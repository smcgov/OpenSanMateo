<?php

/**
 * @file
 * Contains SearchApiAcquiaSearchConnection.
 */

/**
 * Establishes a connection to the Acquia Search service.
 */
class SearchApiAcquiaSearchConnection extends SearchApiSolrConnection {

  /**
   * The derived key used to HMAC hash the search request.
   *
   * @var string
   */
  protected $derivedKey;

  /**
   * Overrides SearchApiSolrConnection::__construct().
   *
   * Also accepts the 'derived_key' setting in $options to set the derived key
   * used to HMAC hash the search request.
   *
   * @see SearchApiAcquiaSearchHttpTransport
   */
  public function __construct(array $options) {
    parent::__construct($options);

    if (isset($options['derived_key'])) {
      $this->derivedKey = $options['derived_key'];
    }
  }

  /**
   * Creates an authenticator based on a data string and HMAC-SHA1.
   *
   * @see acquia_search_authenticator()
   */
  function authenticator($string, $nonce, $derived_key = NULL) {
    if (empty($derived_key)) {
      $derived_key = $this->getDerivedKey();
    }
    if (empty($derived_key)) {
      // Expired or invalid subscription - don't continue.
      return '';
    }
    else {
      $time = time();
      $hash = hash_hmac('sha1', $time . $nonce . $string, $derived_key);
      return 'acquia_solr_time=' . $time . '; acquia_solr_nonce=' . $nonce . '; acquia_solr_hmac=' . $hash . ';';
    }
  }

  /**
   * Sets the derived key used to HMAC hash the search request.
   *
   * @param string $derived_key
   *   The derived key.
   */
  public function setDerivedKey($derived_key) {
    $this->derivedKey = $derived_key;
  }

  /**
   * Derive a key for the solr hmac using the information shared with
   * acquia.com.
   *
   * @see _acquia_search_derived_key()
   */
  public function getDerivedKey() {
    if (!isset($this->derivedKey)) {
      $key = acquia_agent_settings('acquia_key');
      $subscription = acquia_agent_settings('acquia_subscription_data');
      $identifier = acquia_agent_settings('acquia_identifier');
      // We use a salt from acquia.com in key derivation since this is a shared
      // value that we could change on the AN side if needed to force any
      // or all clients to use a new derived key.  We also use a string
      // ('solr') specific to the service, since we want each service using a
      // derived key to have a separate one.
      if (empty($subscription['active']) || empty($key) || empty($identifier)) {
        // Expired or invalid subscription - don't continue.
        $this->derivedKey = '';
      }
      else {
        $salt = isset($subscription['derived_key_salt']) ? $subscription['derived_key_salt'] : '';
        $derivation_string = $identifier . 'solr' . $salt;
        $this->derivedKey =  hash_hmac('sha1', str_pad($derivation_string, 80, $derivation_string), $key);
      }
    }
    return $this->derivedKey;
  }

  /**
   * Modify a solr base url and construct a hmac authenticator cookie.
   *
   * @param $url
   *  The solr url beng requested - passed by reference and may be altered.
   * @param $string
   *  A string - the data to be authenticated, or empty to just use the path
   *  and query from the url to build the authenticator.
   * @param $derived_key
   *  Optional string to supply the derived key.
   *
   * @return
   *  An array containing the string to be added as the content of the
   *  Cookie header to the request and the nonce.
   *
   * @see acquia_search_auth_cookie
   */
  function authCookie(&$url, $string = '', $derived_key = NULL) {
    $uri = parse_url($url);

    // Add a scheme - should always be https if available.
    if (in_array('ssl', stream_get_transports(), TRUE) && !defined('ACQUIA_DEVELOPMENT_NOSSL')) {
      $scheme = 'https://';
      $port = '';
    }
    else {
      $scheme = 'http://';
      $port = (isset($uri['port']) && $uri['port'] != 80) ? ':'. $uri['port'] : '';
    }
    $path = isset($uri['path']) ? $uri['path'] : '/';
    $query = isset($uri['query']) ? '?'. $uri['query'] : '';
    $url = $scheme . $uri['host'] . $port . $path . $query;

    // 32 character nonce.
    $nonce = base64_encode(drupal_random_bytes(24));

    if ($string) {
      $auth_header = $this->authenticator($string, $nonce, $derived_key);
    }
    else {
      $auth_header = $this->authenticator($path . $query, $nonce, $derived_key);
    }
    return array($auth_header, $nonce);
  }

  /**
   * Modify the url and add headers appropriate to authenticate to Acquia Search.
   *
   * @return
   *  The nonce used in the request.
   */
  public function prepareRequest(&$url, &$options, $use_data = TRUE) {
    $id = uniqid();
    if (!stristr($url,'?')) {
      $url .= "?";
    }
    else {
      $url .= "&";
    }
    $url .= 'request_id=' . $id;
    if ($use_data && isset($options['data'])) {
      list($cookie, $nonce) = $this->authCookie($url, $options['data']);
    }
    else {
      list($cookie, $nonce) = $this->authCookie($url);
    }
    if (empty($cookie)) {
      throw new Exception('Invalid authentication string - subscription keys expired or missing.');
    }
    $options['headers']['Cookie'] = $cookie;
    $options['headers'] += array('User-Agent' => 'search_api_acquia/'. variable_get('search_api_acquia_version', '7.x'));
    $options['context'] = acquia_agent_stream_context_create($url, 'acquia_search');
    if (!$options['context']) {
      throw new Exception(t("Could not create stream context"));
    }
    return $nonce;
  }

  /**
   * Validate the hmac for the response body.
   *
   * @return
   *  The response object.
   */
  public function authenticateResponse($response, $nonce, $url) {
    $hmac = $this->extractHmac($response->headers);
    if (!$this->validResponse($hmac, $nonce, $response->data)) {
      throw new Exception('Authentication of search content failed url: '. $url);
    }
    return $response;
  }

  /**
   * Look in the headers and get the hmac_digest out.
   *
   * @see acquia_search_extract_hmac()
   */
  protected function extractHmac($headers) {
    $reg = array();
    if (is_array($headers)) {
      foreach ($headers as $name => $value) {
        if (strtolower($name) == 'pragma' && preg_match("/hmac_digest=([^;]+);/i", $value, $reg)) {
          return trim($reg[1]);
        }
      }
    }
    return '';
  }

  /**
   * Validate the authenticity of returned data using a nonce and HMAC-SHA1.
   *
   * @return boolean
   *  TRUE or FALSE depending on whether the response is valid.
   *
   * @see acquia_search_valid_response()
   */
  protected function validResponse($hmac, $nonce, $string, $derived_key = NULL) {
    if (empty($derived_key)) {
      $derived_key = $this->derivedKey();
    }
    return $hmac == hash_hmac('sha1', $nonce . $string, $derived_key);
  }

  /**
   * Overrides SearchApiSolrHttpTransport::performHttpRequest().
   *
   * Adds the data to the query string required for HMAC authentication,
   * executes the search query.
   */
  protected function makeHttpRequest($url, array $options = array()) {
    if (empty($options['method']) || $options['method'] == 'GET' || $options['method'] == 'HEAD') {
      // Make sure we are not sending a request body.
      $options['data'] = NULL;
    }
    if ($this->http_auth) {
      $options['headers']['Authorization'] = $this->http_auth;
    }
    if ($this->stream_context) {
      $options['context'] = $this->stream_context;
    }

    $this->prepareRequest($url, $options);
    $result = drupal_http_request($url, $options);

    if (!isset($result->code) || $result->code < 0) {
      $result->code = 0;
      $result->status_message = 'Request failed';
      $result->protocol = 'HTTP/1.0';
    }
    // Additional information may be in the error property.
    if (isset($result->error)) {
      $result->status_message .= ': ' . check_plain($result->error);
    }

    if (!isset($result->data)) {
      $result->data = '';
      $result->response = NULL;
    }
    else {
      $response = json_decode($result->data);
      if (is_object($response)) {
        foreach ($response as $key => $value) {
          $result->$key = $value;
        }
      }
    }

    return $result;
  }

}
