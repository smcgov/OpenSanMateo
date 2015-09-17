<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */
 
/**
 * Tell Drupal to also look for template files in the modules folder
 *
 * implements hook_theme_registry_alter
 *
 * @param $theme_registry
 */
function opensanmateo_sitecrawler_theme_registry_alter(&$theme_registry) {
  $path  = drupal_get_path('module', 'opensanmateo_sitecrawler') . '/assets/templates';
  $reg = drupal_find_theme_templates($theme_registry, '.tpl.php', $path);
  foreach ($reg as &$r) {
    $r['type'] = 'module';
  }
  
  $theme_registry += $reg;
}


/**
 * Implements hook_menu().
 */
function opensanmateo_sitecrawler_menu() {
  $items = array();
  
  $items['admin/config/system/opensanmateo_sitecrawler'] = array(
    'title' => 'Open SanMateo Site Crawler',
    'description' => 'Configure sites to crawl for content.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_form'),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/config/system/opensanmateo_sitecrawler/%'] = array(
    'title' => 'Open SanMateo Site Crawler',
    'description' => 'Configure sites to crawl for content.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_form', 4),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/config/system/opensanmateo_sitecrawler/delete/%'] = array(
    'title' => 'Open SanMateo Delete Site Crawler',
    'description' => 'Delete existing crawler.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_delete_form', 5),
    'access callback' => 'opensanmateo_user_one',
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/config/system/opensanmateo_sitecrawler/run/%'] = array(
    'title' => 'Open SanMateo Delete Site Crawler',
    'description' => 'Delete existing crawler.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_run_form', 5),
    'access callback' => 'opensanmateo_user_one',
    'type' => MENU_NORMAL_ITEM,
  );
   
  return $items;
}

/**
 * Access callback that grants only user 1 access.
 */
function opensanmateo_user_one() {
  global $user;
  return ((int) $user->uid === 1) ? TRUE : FALSE;
}

/**
 * Admin for callback().
 */
function opensanmateo_sitecrawler_admin_item_form($form, $form_state, $id = FALSE) {
  $record = opensanmateo_sitecrawler_get_crawler($id);
  $new = ('add' == $id) || !$record;
  
  $form['opensanmateo_sitecrawler_id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  
  $form['opensanmateo_sitecrawler_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Administrative Name'),
    '#maxlength' => 32,
    '#description' => t('Internal name of this crawler.'),
    '#default_value' => (!$new ? $record['name'] : ''),
    '#required' => TRUE,
  );
  
  $form['opensanmateo_sitecrawler_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#maxlength' => 255,
    '#description' => t('Internal description of this crawler.'),
    '#default_value' => (!$new ? $record['description'] : ''),
  );
  
  $form['opensanmateo_sitecrawler_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#description' => t('Indicates if this crawl should run on cron or not.'),
    '#default_value' => (!$new ? $record['enabled'] : TRUE),
  );
  
  $form['opensanmateo_sitecrawler_url'] = array(
    '#type' => 'textfield',
    '#title' => t('External URL'),
    '#maxlength' => 255,
    '#description' => t('Provide URL of external site in the form of www.domain.com'),
    '#default_value' => (!$new ? $record['url'] : 'www.?'),
    '#required' => TRUE,
  );
  
  $form['opensanmateo_sitecrawler_options'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Options'),
    '#description' => t('Select which options to enable for this site crawl. Enabling "aggressive search" causes URLs to be evaluated anywhere on the page (i.e. not just in anchor tags). Enabling "deleted missing content" will cause any nodes which were created on a previous pull for this Crawler to be deleted if they are not re-pulled (i.e. no crawlable link found for them) on a subsequent pull.'),
    '#options' => array(
      'nofollow' => t('Obey NoFollow Tags'),
      'robots' => t('Obey robots.txt'),
      'aggressive' => t('Enable Aggressive Search'),
      'cookies' => t('Enable Cookie Handling'),
      'redirects' => t('Follow Redirects'),
      'redirectsfollow' => t('Follow Redirects From Redirects'),
      'deletemissing' => t('Delete Missing Content'),
    ),
    '#default_value' => (!$new ? $record['options'] : array('nofollow','robots','cookies','redirects','deletemissing',)),
  );
  
  $form['opensanmateo_sitecrawler_body_xpaths'] = array(
    '#type' => 'textarea',
    '#title' => t('Body XPaths'),
    '#default_value' => (!$new ? $record['body_xpaths'] : '/html/body'),
    '#description' => t(
      '<p>Enter !xpaths to try to locate the body content with. For each page, each of these xpaths will be tried until a match is found, and the content at that xpath will be used. If no matches are found, then the content of the &lt;body&gt; tag will be used.</p><p>Examples:<ul><li>//div[@id="layout"]</li><li>/html/body</li></ul></p>',
      array(
        '!xpaths' => l(
          'xpaths',
          'http://www.w3schools.com/XPath/',
          array('attributes' => array('target'=>'_blank'))
        )
      )
    ),
  );
  
  $form['opensanmateo_sitecrawler_size_limit'] = array(
    '#type' => 'select',
    '#title' => t('Page Size Limit'),
    '#options' => array(
      '0' => t('0 (no limit)'),
      '1MB' => t('1 MB'),
      '2MB' => t('2 MB'),
      '5MB' => t('5 MB'),
      '10MB' => t('10 MB'),
      '20MB' => t('20 MB'),
      '50MB' => t('50 MB'),
      '100MB' => t('100 MB'),
      '200MB' => t('200 MB'),
      '500MB' => t('500 MB'),
      '1GB' => t('1 GB'),
      '2GB' => t('2 GB'),
      '5GB' => t('5 GB'),
    ),
    '#default_value' => (!$new ? $record['size_limit'] : '2MB'),
    '#description' => t('Sets the content-size-limit for content the crawler should receive from documents. If the crawler is receiving the content of a page and the size-limit is reached, the crawler stops receiving content from that page and evaluates/stores what it has.'),
  );
  
  $form['opensanmateo_sitecrawler_traffic_limit'] = array(
    '#type' => 'select',
    '#title' => t('Traffic Size Limit'),
    '#options' => array(
      '0' => t('0 (no limit)'),
      '1MB' => t('1 MB'),
      '2MB' => t('2 MB'),
      '5MB' => t('5 MB'),
      '10MB' => t('10 MB'),
      '20MB' => t('20 MB'),
      '50MB' => t('50 MB'),
      '100MB' => t('100 MB'),
      '200MB' => t('200 MB'),
      '500MB' => t('500 MB'),
      '1GB' => t('1 GB'),
      '2GB' => t('2 GB'),
      '5GB' => t('5 GB'),
    ),
    '#default_value' => (!$new ? $record['traffic_limit'] : '500MB'),
    '#description' => t('Sets a limit to the number of bytes the crawler should receive alltogether during crawling-process. If the limit is reached, the crawler stops the crawling-process for that cron run.'),
  );
  
  $form['opensanmateo_sitecrawler_page_limit'] = array(
    '#type' => 'select',
    '#title' => t('Page Limit'),
    '#options' => array(
      '0' => t('0 (no limit)'),
      '5' => t('5 per cron'),
      '10' => t('10 per cron'),
      '20' => t('20 per cron'),
      '50' => t('50 per cron'),
      '100' => t('100 per cron'),
      '200' => t('200 per cron'),
      '500' => t('500 per cron'),
      '1000' => t('1000 per cron'),
    ),
    '#default_value' => (!$new ? $record['page_limit'] : '20'),
    '#description' => t('Sets a limit to the number of pages/files the crawler should follow each cron run. If the limit is reached, the crawler stops the crawling-process. Only set to 0 (no limit) for fairly small sites.'),
  );
  
  $form['opensanmateo_sitecrawler_request_delay'] = array(
    '#type' => 'select',
    '#title' => t('Request Delay'),
    '#options' => array(
      '0' => t('0 (no delay)'),
      '.25' => t('.25 second'),
      '.5' => t('.5 second'),
      '.75' => t('.75 second'),
      '1' => t('1 second'),
      '1.5' => t('1.5 seconds'),
      '2' => t('2 seconds'),
      '3' => t('3 seconds'),
      '4' => t('4 seconds'),
      '5' => t('5 seconds'),
    ),
    '#default_value' => (!$new ? $record['request_delay'] : '0'),
    '#description' => t('Sets a delay (in seconds) for every HTTP-requests the crawler executes. The crawler will wait for the given time after every request it executes.'),
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save Changes'));
  if (!$new) {
    $form['actions']['delete'] = array('#type' => 'submit', '#value' => t('Delete'));
  }
  $form['actions']['cancel'] = array('#markup' => l(t('Cancel'), 'admin/config/system/opensanmateo_sitecrawler'),);
  
  // Per-path visibility.
  $form['opensanmateo_sitecrawler_path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Path Rules'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'visibility',
  );

  $form['opensanmateo_sitecrawler_path']['opensanmateo_sitecrawler_path_type_rules'] = array(
    '#type' => 'textarea',
    '#title' => t('Content Type Rules'),
    '#default_value' => (!$new ? $record['path_type_rules'] : '#text/html#'),
    '#description' => t('<p>Adds a rule to the list of rules that decides which pages or files - regarding their content-type - should be received. After receiving the HTTP-header of a followed URL, the crawler check\'s - based on the given rules - whether the content of that URL should be received. If no rule matches with the content-type of the document, the content won\'t be received. By default, if no rule was added to the list, the crawler receives all content.</p><p>Examples:<ul><li>#text/html#</li><li>#text/css#</li></ul></p>'),
  );
  $form['opensanmateo_sitecrawler_path']['opensanmateo_sitecrawler_path_filter_rules'] = array(
    '#type' => 'textarea',
    '#title' => t('Filter Rules'),
    '#default_value' => (!$new ? $record['path_filter_rules'] : '#[.](jpg|jpeg|gif|png|css|js|ico|xml)([?].*)?$# i'),
    '#description' => t('<p>Adds a rule to the list of rules that decide which URLs found on a page should be ignored by the crawler. If the crawler finds a URL and this URL matches with one of the given regular-expressions, the crawler will ignore this URL and won\'t follow it.</p><p>Examples:<ul><li>#(jpg|jpeg|gif|png|bmp)$# i</li><li>#(css|js)$# i</li></ul></p>'),
  );
  $form['opensanmateo_sitecrawler_path']['opensanmateo_sitecrawler_path_follow_rules'] = array(
    '#type' => 'textarea',
    '#title' => t('Follow Rules'),
    '#default_value' => (!$new ? $record['path_follow_rules'] : ''),
    '#description' => t('<p>Adds a rule to the list of rules that decide which URLs found on a page should be followd explicitly. If the crawler finds an URL and this URL doesn\'t match with any of the given regular-expressions, the crawler will ignore this URL and won\'t follow it.</p><p>Examples:<ul><li>#(htm|html)$# i</li><li>#(php|php3|php4|php5)$# i</li></ul></p>'),
  );
    
  return $form;
}

/**
 * Submit callback for the opensanmateo_sitecrawler_admin_item_form form.
 *
 * @ingroup opensanmateo_sitecrawler
 */
function opensanmateo_sitecrawler_admin_item_form_submit($form, &$form_state) {
  switch($form_state['input']['op']) {
    case t('Save Changes'):
      $record = array();
      foreach(array(
        'name',
        'description',
        'enabled',
        'url',
        'body_xpaths',
        'size_limit',
        'traffic_limit',
        'page_limit',
        'request_delay',
        'path_type_rules',
        'path_filter_rules',
        'path_follow_rules',
      ) as $field_name) {
        $record[$field_name] = $form_state['values']['opensanmateo_sitecrawler_' . $field_name];
      }
      $record['options'] = serialize($form_state['values']['opensanmateo_sitecrawler_options']);
      
      $primary_keys = 'id';
      if ('add' == $form_state['values']['opensanmateo_sitecrawler_id']) {
        $primary_keys = NULL;
      } else {
        $record['id'] = $form_state['values']['opensanmateo_sitecrawler_id'];
      }
      break;
    case t('Delete'):
      drupal_goto('admin/config/system/opensanmateo_sitecrawler/delete/' . $form_state['values']['opensanmateo_sitecrawler_id']);
      return;
  }
// drupal_set_message('<pre>$record ' . print_r($record,1) . '</pre>');
  
  drupal_write_record('opensanmateo_sitecrawler_sites', $record, $primary_keys);
}

/**
 * Admin for callback().
 */
function opensanmateo_sitecrawler_admin_item_delete_form($form, $form_state, $id = FALSE) {
  $record = opensanmateo_sitecrawler_get_crawler($id);
  
  if (!$record) {
    drupal_goto('admin/config/system/opensanmateo_sitecrawler');
    return;
  }
  
  $form['opensanmateo_sitecrawler_id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  
  return confirm_form(
    $form,
    t(
      'Are you sure you want to delete the %name crawler?',
      array(
        '%name' => $record['name'],
      )
    ),
    'admin/config/system/opensanmateo_sitecrawler/' . $id
  );
}

/**
 * Submit callback for the opensanmateo_sitecrawler_admin_item_delete_form form.
 *
 * @ingroup opensanmateo_sitecrawler
 */
function opensanmateo_sitecrawler_admin_item_delete_form_submit($form, &$form_state) {
  if($form_state['values']['confirm']) {
    db_delete('opensanmateo_sitecrawler_sites')
      ->condition('id', $form_state['values']['opensanmateo_sitecrawler_id'])
      ->execute();
  }
}

/**
 * Admin for callback().
 */
function opensanmateo_sitecrawler_admin_item_run_form($form, $form_state, $id = FALSE) {
  $record = opensanmateo_sitecrawler_get_crawler($id);
// drupal_set_message('<pre>' . print_r($record, 1) . '</pre>');
  
  if (!$record) {
    drupal_goto('admin/config/system/opensanmateo_sitecrawler');
    return;
  }
  
  $form['opensanmateo_sitecrawler_id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  
  return confirm_form(
    $form,
    t(
      'Are you sure you want to run the %name crawler?',
      array(
        '%name' => $record['name'],
      )
    ),
    'admin/config/system/opensanmateo_sitecrawler'
  );
  
}


/**
 * Submit callback for the opensanmateo_sitecrawler_admin_item_run_form form.
 *
 * @ingroup opensanmateo_sitecrawler
 */
function opensanmateo_sitecrawler_admin_item_run_form_submit($form, &$form_state) {
  opensanmateo_sitecrawler_run_crawler($form_state['values']['opensanmateo_sitecrawler_id']);
}

/**
 * Submit callback for the opensanmateo_sitecrawler_admin_item_run_form form.
 *
 */
function opensanmateo_sitecrawler_run_crawler($crawler_id) {
  if (!($record = opensanmateo_sitecrawler_get_crawler($crawler_id))) {
    drupal_set_message(
      t(
        'Could not load crawlier ID !ID, so could not run crawler!',
        array('!ID' => $crawler_id)
      ),
      'error'
    );
    return;
  }
// drupal_set_message('<pre>' . print_r(opensanmateo_sitecrawler_get_crawler($crawler_id), 1) . '</pre>');
  
  // It may take a while to crawl a site ...
  set_time_limit(10000);

  $crawler = new SiteCrawler($record['id'], preg_split('/$\R?^/m', $record['body_xpaths']));
  $crawler->setUrlCacheType(PHPCrawlerUrlCacheTypes::URLCACHE_D7);
  $crawler->setDatabaseConnectionObject(
    'opensanmateo_sitecrawler_url_cache',
    'opensanmateo_sitecrawler_cookie_cache'
  );

  $crawler->setURL($record['url']);
  $crawler->obeyNoFollowTags(!!$record['options']['nofollow']);
  $crawler->obeyRobotsTxt(!!$record['options']['robots']);
  $crawler->enableAggressiveLinkSearch(!!$record['options']['aggressive']);
  $crawler->enableCookieHandling(!!$record['options']['cookies']);
  $crawler->setFollowRedirects(!!$record['options']['redirects']);
  $crawler->setFollowRedirectsTillContent(!!$record['options']['redirectsfollow']);

  foreach(preg_split('/$\R?^/m', $record['path_type_rules']) as $rule) {
    if (!empty($rule)) {
      $crawler->addContentTypeReceiveRule($rule);
    }
  }
  foreach(preg_split('/$\R?^/m', $record['path_filter_rules']) as $rule) {
    if (
      !empty($rule)
      && (
        // check if this is a valid regex
        FALSE !== @preg_match($rule, 'xxx')
        // and if it's not a valid regex, try to convert it to one
        || FALSE !== @preg_match($rule = '#' . $rule . '# i', 'xxx')
      )
    ) {
      $crawler->addURLFilterRule($rule);
    }
  }
  foreach(preg_split('/$\R?^/m', $record['path_follow_rules']) as $rule) {
    if (!empty($rule)) {
      $crawler->addURLFollowRule($rule);
    }
  }


  // convert strings to size in bytes
  foreach(array('size_limit', 'traffic_limit') as $varname) {
    preg_match('/([0-9])(.+)/', $record[$varname], $matches);
    $$varname = $matches[1] * 1024 * 1024 * ('GB' == $matches[2] ? 1024 : 1);
  }
  
  // Set the various limits
  $crawler->setContentSizeLimit($size_limit);
  $crawler->setTrafficLimit($traffic_limit);
  $crawler->setPageLimit($record['page_limit']);
  $crawler->setRequestDelay($record['request_delay']);

  $crawler->enableResumption();
  
  $crawler_id_variable = 'opensanmateo_sitecrawler_crawler_id_' . $record['id'];

  if (FALSE != ($crawler_ID = variable_get($crawler_id_variable, FALSE))) {
    try {
      $crawler->resume($crawler_ID);
    } catch (Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
      variable_set($crawler_id_variable, FALSE);
    }
  }
  else {
    variable_set($crawler_id_variable, $crawler->getCrawlerId());
  }

  try {
    $crawler->go();
//     $crawler->goMultiProcessed(5);
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    return;
  }
  
  $report = $crawler->getProcessReport();
  drupal_set_message(
    t('Sitecrawler @name Batch Run Summary: ', array('@name' => $record['name']))
    . theme('item_list', array('items' => array(
      t('Links followed: !val', array('!val' => $report->links_followed)),
      t('Documents received: !val', array('!val' => $report->files_received)),
      t('Bytes received: !val bytes', array('!val' => $report->bytes_received)),
      t('Process runtime: !val sec', array('!val' => $report->process_runtime)),
      t('Nodes created: !val', array('!val' => $crawler->nodes_created)),
      t('Nodes updated: !val', array('!val' => $crawler->nodes_updated)),
    )))
  );
  
  
  if (
    !$crawler->getPreviousAbortStatus()
    || $crawler->getPreviousAbortStatus() == ABORTREASON_PASSEDTHROUGH) {
    variable_set($crawler_id_variable, FALSE);
    if (!!$record['options']['deletemissing']) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'sitecrawler_page')
        ->fieldCondition('field_sitecrawler_id', 'value', $record['id'], '=')
        ->fieldCondition('field_sitecrawler_instance_id', 'value', $crawler->getCrawlerId(), '<>')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.
      $result = $query->execute();
      if (isset($result['node'])) {
        $old_pages = array_keys($result['node']);
        entity_delete_multiple('node', $old_pages);
      }
    }
  }
}


/**
 * Implements hook_cron().
 *
 */
function opensanmateo_sitecrawler_cron() {
  $result = db_query('SELECT id FROM {opensanmateo_sitecrawler_sites} WHERE enabled = 1 ORDER BY weight ASC');
  foreach ($result as $item) {
    opensanmateo_sitecrawler_run_crawler($item->id);
  }
}


/**
 * Implements hook_theme().
 *
 * We need run our forms through custom theme functions in order to build the
 * table structure which is required by tabledrag.js.  Before we can use our
 * custom theme functions, we need to implement hook_theme in order to register
 * them with Drupal.
 *
 * We are defining our theme hooks with the same name as the form generation
 * function so that Drupal automatically calls our theming function when the
 * form is displayed.
 */
function opensanmateo_sitecrawler_theme() {
  return array(
    'opensanmateo_sitecrawler_admin_form' => array(
      'render element' => 'form',
    ),
  );
}


/**
 * Build the opensanmateo_sitecrawler_admin_form form.
 *
 * @return array
 *   A form array set for theming by theme_opensanmateo_sitecrawler_admin_form()
 *
 * @ingroup opensanmateo_sitecrawler
 */
function opensanmateo_sitecrawler_admin_form($form, $form_state) {
  $form['crawlers'] = array();

  $result = db_query('SELECT * FROM {opensanmateo_sitecrawler_sites} ORDER BY weight ASC');

  foreach ($result as $item) {

    $form['crawlers'][$item->id] = array(

      'name' => array(
        '#markup' => check_plain($item->name),
      ),
      'url' => array(
        '#markup' => check_plain($item->url),
      ),
      'enabled' => array(
        '#markup' => check_plain($item->enabled ? 'TRUE' : 'FALSE'),
      ),

      // The 'weight' field will be manipulated as users move the items around in
      // the table using the tabledrag activity.
      'weight' => array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $item->weight,
        '#delta' => 10,
        '#title_display' => 'invisible',
      ),
    );
  }
  
  if (0 == count($form['crawlers'])) {
    drupal_set_message(t('There are no crawlers defined yet.'));
    drupal_goto(
      'admin/config/system/opensanmateo_sitecrawler/add',
      array(
        'query' => array(
          'destination' => 'admin/config/system/opensanmateo_sitecrawler'
        )
      )
    );
    return;
  }
  
  // Identify that the elements in 'crawlers' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['crawlers']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save Changes'));
// drupal_set_message('<pre>$form ' . print_r($form,1) . '</pre>');
  return $form;
}

/**
 * Submit callback for the opensanmateo_sitecrawler_admin_form form.
 *
 * Updates the 'weight' column for each element in our table, taking into
 * account that item's new order after the drag and drop actions have been
 * performed.
 *
 * @ingroup opensanmateo_sitecrawler
 */
function opensanmateo_sitecrawler_admin_form_submit($form, &$form_state) {
  // Because the form elements were keyed with the item ids from the database,
  // this can simply iterate through the submitted values.
  foreach ($form_state['values']['crawlers'] as $id => $item) {
    db_query(
      "UPDATE {opensanmateo_sitecrawler_sites} SET weight = :weight WHERE id = :id",
      array(':weight' => $item['weight'], ':id' => $id)
    );
  }
}

/**
 * Theme callback for the opensanmateo_sitecrawler_admin_form form.
 *
 * The theme callback will format the $form data structure into a table and
 * add our tabledrag functionality.  (Note that drupal_add_tabledrag should be
 * called from the theme layer, and not from a form declaration.  This helps
 * keep template files clean and readable, and prevents tabledrag.js from
 * being added twice accidently.
 *
 * @return array
 *   The rendered tabledrag form
 *
 * @ingroup opensanmateo_sitecrawler
 */
function theme_opensanmateo_sitecrawler_admin_form($variables) {
  $form = $variables['form'];
  
  $output = 
    '<div>'
    . l(
      'Add Another Crawl',
      'admin/config/system/opensanmateo_sitecrawler/add',
      array(
        'query' => array(
          'destination' => 'admin/config/system/opensanmateo_sitecrawler'
        )
      )
    )
    . '</div>';

  $rows = array();

  foreach (element_children($form['crawlers']) as $id) {

    // Before adding the 'weight' column to the row, give the
    // element a custom class so that it can be identified in the
    // drupal_add_tabledrag call.
    $form['crawlers'][$id]['weight']['#attributes']['class'] = array('crawler-item-weight');

    $links = array();
    $links[] = l(
      'edit',
      'admin/config/system/opensanmateo_sitecrawler/' . $id,
        array(
          'query' => array(
            'destination' => 'admin/config/system/opensanmateo_sitecrawler'
          )
        )
      );
      // Only give user one access to run and delete
      if (opensanmateo_user_one()) {
        $links[] = l(
          'delete',
          'admin/config/system/opensanmateo_sitecrawler/delete/' . $id,
          array(
            'query' => array(
              'destination' => 'admin/config/system/opensanmateo_sitecrawler'
            )
          )
        );

        $links[] = l(
          'run',
          'admin/config/system/opensanmateo_sitecrawler/run/' . $id,
          array(
            'query' => array(
              'destination' => 'admin/config/system/opensanmateo_sitecrawler'
            )
          )
        );
      }
    // Add each element of the $form data to the $rows array using drupal_render()
    // to generate the final html markup for each.
    $rows[] = array(
      'data' => array(
        drupal_render($form['crawlers'][$id]['name']),
        drupal_render($form['crawlers'][$id]['url']),
        drupal_render($form['crawlers'][$id]['enabled']),
        implode(' ', $links),
        drupal_render($form['crawlers'][$id]['weight']),
      ),
      // To support the tabledrag behaviour, assign each <tr> of the
      // table a class attribute of 'draggable'.
      'class' => array('draggable'),
    );
  }

  $header = array(t('Name'), t('URL'), t('Enabled'), '', t('Weight'));

  // Pass the drupal_add_tabledrag() function an id which willbe used to identify 
  // the <table> element containing our tabledrag form. Note that an element's 
  // 'id' should be unique on a page.
  $table_id = 'opensanmateo-sitecrawler-table';

  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  // Render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);

  // Call the drupal_add_tabledrag() function in order to add thetabledrag.js 
  // goodness to the page.
  //
  // For a basic sortable table, pass in:
  // - the $table_id of our <table> element,
  // - the $action to be performed on our form items ('order'),
  // - a string describing where $action should be applied ('siblings'),
  // - and the class of the element containing our 'weight' element.
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'crawler-item-weight');

  return $output;
}

/**
 * Admin for callback().
 */
function opensanmateo_sitecrawler_get_crawler($id) {
  $record = db_query('SELECT * FROM {opensanmateo_sitecrawler_sites} WHERE id = :id', array(':id' => $id))->fetchAssoc();
  if (!!$record) {
    $record['options'] = unserialize($record['options']);
  }
  return $record;
}

/**
 * Implements hook_url_outbound_alter().
 * 
 * OK, this is *NOT* the way I wanted to do this, but it worked after everything 
 * else failed, so here it is. The goal was to get the URL stored in SOLR to be 
 * the external URL of the crawled content rather than the stored Drupal 
 * internal URL. Changing the view URL across the board is undesirable because 
 * that interferes with normal use of the node internal to drupal (e.g. if an 
 * admin wanted to view the node).
 * 
 * The following options were considered and rejected before deciding on this
 * hook:
 * 
 *  * hook_apachesolr_update_index: Provides an array of entity objects being 
 *    passed to SOLR, and is a handy place to add or alter content before it's 
 *    indexed. However, the content URL is not a field that's available to 
 *    overwrite on entity objects.
 * 
 *  * hook_search_api_index_items_alter: Same problem as 
 *    hook_apachesolr_update_index.
 * 
 *  * hook_search_api_alter_callback_info: The thinking here was that we could 
 *    provide a custom callback that would modify URL on the object. However, as
 *    with the update_index and search_api_index_items_alter hooks, the URL is 
 *    not set at this point so cannot be modified. There was some false hope to 
 *    the contrary given the exising SearchApiAlterAddUrl object (ref: 
 *    callback_add_url.inc), which calls getItemUrl() off of the datasource, 
 *    but this is setting the value to an arbitrary field in the solr index and 
 *    is not setting the URL stored in SOLR for this item. Further, the 
 *    getItemUrl() methos is only ever called by the SearchApiAlterAddUrl 
 *    object, and is not used by the underlying system to fetch and store the 
 *    URL.
 * 
 *  * hook_search_api_item_type_info_alter: The existence of getItemUrl() here 
 *    gave some false hope regarding how that method might be being used by the 
 *    underlying syste, but this turned out to be false (see discussion on 
 *    hook_search_api_alter_callback_info above). As before, there doesn't 
 *    appear to be a way to override the existing URL from the context of the 
 *    datasource object (even though this seems to be implied by the existence 
 *    and description of the SearchApiExternalDataSourceController object).
 *
 * So, failing all of that, this implementation of hook_url_outbound_alter is 
 * being used instead. A specific check is being made to determine if this URL 
 * is in the context of a search_api request; an exhaustive check has not been 
 * done to determine if this check actually limits it to just calls from the 
 * search_api, but various test runs seem to indicate that this is the case. As 
 * you can see, when the entity is a sitecrawler_page, then the URL value stored 
 * in field_sitecrawler_url at the time the content was is substituted for the 
 * URL of the content.
 */

function opensanmateo_sitecrawler_url_outbound_alter(&$path, &$options, $original_path) {
  if (
    !empty($options['entity'])
    && isset($options['entity']->search_api_site_id)
    && 'sitecrawler_page' == $options['entity']->type
  ) {
    $path = $options['entity']->field_sitecrawler_url[$options['entity']->language][0]['url'];
    $options['external'] = TRUE;
  }
  
}
