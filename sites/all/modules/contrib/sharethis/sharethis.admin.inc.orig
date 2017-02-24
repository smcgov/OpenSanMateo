<?php

/**
 * @file
 * Functionality for Share This administration.
 */

/**
 * This is the main configuration form for the admin page.
 */
function sharethis_configuration_form($form, &$form_state) {
  // First, setup variables we will need.
  // Get the path variables setup.
  $my_path = drupal_get_path('module', 'sharethis');
  // Load the css and js for our module's configuration.
  drupal_add_css($my_path . '/ShareThisForm.css');
  // This is ShareThis's common library.
  // It has a serviceList of all the objects that are currently supported.
  drupal_add_js('https://ws.sharethis.com/share5x/js/stcommon.js', 'external');
  drupal_add_js($my_path . '/ShareThisForm.js');
  drupal_add_js($my_path . '/stlib_picker.js');
  drupal_add_css($my_path . '/stlib_picker.css');
  $current_options_array = sharethis_get_options_array();
  global $base_url;
  // Create the variables related to button choice.
  $button_choice = check_plain($current_options_array['buttons']);
  // Create the variables related to services chosen.
  $service_string = $current_options_array['services'];
  $service_string_markup = "";
  $enabled_services = array();
  foreach (explode(",", $service_string) as $string) {
    $key = explode(":", drupal_substr($string, 0, -1));
    $key = $key[1];
    $service_string_markup .= "\"" . $key . "\",";
    // Store enabled services for custom overrides.
    $service = explode(":", drupal_substr($string, 0, -1));
    $enabled_services[$service[1]] = str_replace('"', '', $service[0]);
  }
  $service_string_markup = drupal_substr($service_string_markup, 0, -1);

  // Create the variables for publisher keys.
  $publisher = $current_options_array['publisherID'];
  // Create the variables for teasers.
  $form = array();
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
  );
  $form['options']['sharethis_button_option'] = array(
    '#required' => TRUE,
    '#type' => 'radios',
    '#options' => array(
      'stbc_large' => t('Large Chicklets'),
      'stbc_' => t('Small Chicklets'),
      'stbc_button' => t('Classic Buttons'),
      'stbc_vcount' => t('Vertical Counters'),
      'stbc_hcount' => t('Horizontal Counters'),
      'stbc_custom' => t('Custom Buttons via CSS'),
    ),
    '#default_value' => $button_choice,
    '#title' => t("Choose a button style:"),
    '#prefix' => '<div class="st_widgetContain"><div class="st_spriteCover"><img id="stb_sprite" class="st_buttonSelectSprite ' . $button_choice . '" src="' . $base_url . '/' . $my_path . '/img/preview_sprite.png"></img></div><div class="st_widgetPic"><img class="st_buttonSelectImage" src="' . $base_url . '/' . $my_path . '/img/preview_bg.png"></img></div>',
    '#suffix' => '</div>',
  );
  $form['options']['sharethis_service_option'] = array(
    '#description' => t("<b>Add</b> a service by selecting it on the right and clicking the <i>left arrow</i>.  <b>Remove</b> it by clicking the <i>right arrow</i>.<br /><b>Change the order</b> of services under \'Selected Services\' by using the <i>up</i> and <i>down</i> arrows."),
    '#required' => TRUE,
    '#type' => 'textfield',
    '#prefix' => '<div>',
    '#suffix' => '</div><div id="myPicker"></div><script type="text/javascript">stlib_picker.setupPicker(jQuery("#myPicker"), [' . $service_string_markup . '], drupal_st.serviceCallback);</script>',
    '#title' => t("Choose Your Services."),
    '#default_value' => t("@service_string", array('@service_string' => $service_string)),
    '#maxlength' => 1024,
  );
  $form['options']['sharethis_option_extras'] = array(
    '#title' => t('Extra services'),
    '#description' => t('Select additional services which will be available. These are not officially supported by ShareThis, but are available.'),
    '#type' => 'checkboxes',
    '#options' => array(
      'Google Plus One:plusone' => t('Google Plus One'),
      'Facebook Like:fblike' => t('Facebook Like'),
      'Facebook Recommend:fbrec' => t('Facebook Recommend'),
      'Facebook Send:fbsend' => t('Facebook Send'),
    ),
    '#default_value' => $current_options_array['option_extras'],
  );

  $form['options']['sharethis_option_extras_fbsub'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'Facebook Subscribe:fbsub' => t('Facebook Subscribe'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_fbsub', array()),
  );
  $form['options']['sharethis_option_extras_fbsub_field'] = array(
    '#title' => t("Insert Facebook Subscribe Username"),
    '#description' => t("Note: This must be a valid profile name"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_fbsub_field', ''),
  );
  $form['options']['sharethis_option_extras_pinterestfollow'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'Pinterest Follow:pinterestfollow' => t('Pinterest Follow'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_pinterestfollow', array()),
  );
  $form['options']['sharethis_option_extras_pinterestfollow_field'] = array(
    '#title' => t("Insert Pinterest Follow Username"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_pinterestfollow_field', ''),
  );
  $form['options']['sharethis_option_extras_twitterfollow'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'Twitter Follow:twitterfollow' => t('Twitter Follow'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_twitterfollow', array()),
  );
  $form['options']['sharethis_option_extras_twitterfollow_field'] = array(
    '#title' => t("Insert Twitter Follow Username"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_twitterfollow_field', ''),
  );
  $form['options']['sharethis_option_extras_youtube'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'YouTube Follow:youtube' => t('YouTube Follow'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_youtube', array()),
  );
  $form['options']['sharethis_option_extras_youtube_field'] = array(
    '#title' => t("Insert YouTube Username"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_youtube_field', ''),
  );
  $form['options']['sharethis_option_extras_foursquarefollow'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'Foursquare Follow:foursquarefollow' => t('Foursquare Follow'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_foursquarefollow', array()),
  );
  $form['options']['sharethis_option_extras_foursquarefollow_field'] = array(
    '#title' => t("Insert Foursquare Follow Username"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_foursquarefollow_field', ''),
  );
  $form['options']['sharethis_option_extras_foursquarefollow_field2'] = array(
    '#title' => t("Insert Foursquare Follow Id"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_option_extras_foursquarefollow_field2', ''),
  );
  $form['options']['sharethis_option_extras_foursquaresave'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'Foursquare Save:foursquaresave' => t('Foursquare Save'),
    ),
    '#default_value' => variable_get('sharethis_option_extras_foursquaresave', array()),
  );
  $form['options']['sharethis_callesi'] = array(
    '#type' => 'hidden',
    '#default_value' => $current_options_array['sharethis_callesi'],
  );

  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['context'] = array(
    '#type' => 'fieldset',
    '#title' => t('Context'),
    '#group' => 'additional_settings',
    '#description' => t('Configure where the ShareThis widget should appear.'),
  );

  $form['context']['sharethis_location'] = array(
    '#title' => t('Location'),
    '#type' => 'radios',
    '#options' => array(
      'content' => t('Node content'),
      'block' => t('Block'),
      'links' => t('Links area'),
    ),
    '#default_value' => variable_get('sharethis_location', 'content'),
  );

  // Add an information section for each location type, each dependent on the
  // currently selected location.
  foreach (array('links', 'content', 'block') as $location_type) {
    $form['context'][$location_type]['#type'] = 'container';
    $form['context'][$location_type]['#states']['visible'][':input[name="sharethis_location"]'] = array('value' => $location_type);
  }

  // Add help text for the 'content' location.
  $form['context']['content']['help'] = array(
    '#markup' => t('When using the Content location, you must place the ShareThis links in the <a href="@url">Manage Display</a> section of each content type.', array('@url' => url('admin/structure/types'))),
    '#weight' => 10,
    '#prefix' => '<em>',
    '#suffix' => '</em>',
  );
  // Add help text for the 'block' location.
  $form['context']['block']['#children'] = t('You must choose which region to display the <em>ShareThis block</em> in from the <a href="@blocksadmin">Blocks administration</a>.', array('@blocksadmin' => url('admin/structure/block')));

  // Add checkboxes for each view mode of each bundle.
  $entity_info = entity_get_info('node');
  $modes = array();
  foreach ($entity_info['view modes'] as $mode => $mode_info) {
    $modes[$mode] = $mode_info['label'];
  }
  // Get a list of content types and view modes.
  $view_modes_selected = $current_options_array['view_modes'];
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $form['context']['links']['sharethis_' . $bundle . '_options'] = array(
      '#title' => t('%label View Modes', array('%label' => $bundle_info['label'])),
      '#description' => t('Select which view modes the ShareThis widget should appear on for %label nodes.', array('%label' => $bundle_info['label'])),
      '#type' => 'checkboxes',
      '#options' => $modes,
      '#default_value' => $view_modes_selected[$bundle],
    );
  }

  // Allow the user to choose which content types will have ShareThis added
  // when using the 'Content' location.
  $content_types = array();
  $enabled_content_types = $current_options_array['sharethis_node_types'];
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $content_types[$bundle] = t("@label", array('@label' => $bundle_info['label']));
  }
  $form['context']['content']['sharethis_node_types'] = array(
    '#title' => t('Node Types'),
    '#description' => t('Select which node types the ShareThis widget should appear on.'),
    '#type' => 'checkboxes',
    '#options' => $content_types,
    '#default_value' => $enabled_content_types,
  );
  $form['context']['sharethis_comments'] = array(
    '#title' => t('Comments'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('sharethis_comments', FALSE),
    '#description' => t('Display ShareThis on comments.'),
    '#access' => module_exists('comment'),
  );
  $form['context']['sharethis_weight'] = array(
    '#title' => t('Weight'),
    '#description' => t('The weight of the widget determines the location on the page where it will appear.'),
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(-100, -50, -25, -10, 0, 10, 25, 50, 100,
    )),
    '#default_value' => variable_get('sharethis_weight', 10),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#group' => 'additional_settings',
    '#description' => t('The advanced settings can usually be ignored if you have no need for them.'),
  );
  $form['advanced']['sharethis_publisherID'] = array(
    '#title' => t("Insert a publisher key (optional)."),
    '#description' => t("When you install the module, we create a random publisher key.  You can register the key with ShareThis by contacting customer support.  Otherwise, you can go to <a href='http://www.sharethis.com/account'>ShareThis</a> and create an account.<br />Your official publisher key can be found under 'My Account'.<br />It allows you to get detailed analytics about sharing done on your site."),
    '#type' => 'textfield',
    '#default_value' => $publisher,
  );
  $form['advanced']['sharethis_late_load'] = array(
    '#title' => t('Late Load'),
    '#description' => t("You can change the order in which ShareThis widget loads on the user's browser. By default the ShareThis widget loader loads as soon as the browser encounters the JavaScript tag; typically in the tag of your page. ShareThis assets are generally loaded from a CDN closest to the user. However, if you wish to change the default setting so that the widget loads after your web-page has completed loading then you simply tick this option."),
    '#type' => 'checkbox',
    '#default_value' => variable_get('sharethis_late_load', FALSE),
  );
  $form['advanced']['sharethis_twitter_prefix'] = array(
    '#title' => t("Twitter Prefix"),
    '#description' => t("Optionally prepend a Twitter handle, or text, so that you get pinged when someone shares an article. Example: <em> @YourNameHere</em>"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_twitter_prefix', ''),
  );
  $form['advanced']['sharethis_twitter_suffix'] = array(
    '#title' => t("Twitter Suffix"),
    '#description' => t("Optionally append a Twitter handle, or text, so that you get pinged when someone shares an article. Example: <em>via @YourNameHere</em>"),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_twitter_suffix', ''),
  );
  $form['advanced']['sharethis_twitter_handle'] = array(
    '#title' => t('Twitter Handle'),
    '#description' => t('Twitter handle to use when sharing.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_twitter_handle', ''),
  );
  $form['advanced']['sharethis_twitter_recommends'] = array(
    '#title' => t('Twitter recommends'),
    '#description' => t('Specify a twitter handle to be recommended to the user.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sharethis_twitter_recommends', ''),
  );
  $form['advanced']['sharethis_option_onhover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display ShareThis widget on hover'),
    '#description' => t('If disabled, the ShareThis widget will be displayed on click instead of hover.'),
    '#default_value' => variable_get('sharethis_option_onhover', TRUE),
  );
  $form['advanced']['sharethis_option_neworzero'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display count "0" instead of "New"'),
    '#description' => t('Display a zero (0) instead of "New" in the count for content not yet shared.'),
    '#default_value' => variable_get('sharethis_option_neworzero', FALSE),
  );
  $form['advanced']['sharethis_option_shorten'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display short URL'),
    '#description' => t('Display either the full or the shortened URL.'),
    '#default_value' => variable_get('sharethis_option_shorten', TRUE),
  );
  $form['advanced']['sharethis_option_servicepopup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use popup'),
    '#description' => t('Display the share window in a popup instread of a new tab.'),
    '#default_value' => variable_get('sharethis_option_servicepopup', FALSE),
  );
  $form['advanced']['sharethis_fastshare'] = array(
    '#title' => t('Fast Share'),
    '#description' => t('Whether or not to use the <a href="@fastshare">Fast Share</a> feature.', array(
      '@fastshare' => 'http://sharethis.com/publishers/fast-share',
    )),
    '#type' => 'checkbox',
    '#default_value' => variable_get('sharethis_fastshare', TRUE),
  );
  $form['advanced']['sharethis_cns'] = array(
    '#title' => t('<b>CopyNShare </b><sup>(<a href="http://support.sharethis.com/customer/portal/articles/517332-share-widget-faqs#copynshare" target="_blank">?</a>)</sup>'),
    '#type' => 'checkboxes',
    '#prefix' => '<div id="st_cns_settings">',
    '#suffix' => '</div><div class="st_cns_container">
    <p>CopyNShare is the new ShareThis widget feature that enables you to track the shares that occur when a user copies and pastes your website\'s <u>URL</u> or <u>Content</u>. <br/>
      <u>Site URL</u> - ShareThis adds a special #hashtag at the end of your address bar URL to keep track of where your content is being shared on the web.<br/>
      <u>Site Content</u> - It enables the pasting of "See more: YourURL#SThashtag" after user copies-and-pastes text. When a user copies text within your site, a "See more: yourURL.com#SThashtag" will appear after the pasted text. <br/>
      Please refer the <a href="http://support.sharethis.com/customer/portal/articles/517332-share-widget-faqs#copynshare" target="_blank">CopyNShare FAQ</a> for more details.</p>
    </div>',
    '#options' => array(
      'donotcopy' => t("Measure copy & shares of your site\'s Content"),
      'hashaddress' => t("Measure copy & shares of your site\'s URLs"),
    ),
    '#default_value' => $current_options_array['sharethis_cns'],
  );
  $form['overrides'] = array(
    '#type' => 'fieldset',
    '#title' => t('Markup overrides'),
    '#group' => 'additional_settings',
    '#description' => t('Override span button markup to include SVGs or other markup.'),
  );
  foreach ($enabled_services as $key => $service) {
    $current_value = variable_get('sharethis_override_' . $key, '');
    // Add each enabled service to include markup.
    $form['overrides']['override_' . $key] = array(
      '#title' => $service,
      '#type' => 'textfield',
      '#default_value' => $current_value,
    );
  }

  $form['#submit'][] = 'sharethis_configuration_form_submit';
  return system_settings_form($form);
}

/**
 * Form validation handler for sharethis_configuration_form().
 */
function sharethis_configuration_form_validate($form, &$form_state) {
  // Additional filters for the service option input.
  // Sanitize the publisher ID option.
  // Since it's a text field, remove anything that resembles code.
  $form_state['values']['sharethis_service_option'] = filter_xss($form_state['values']['sharethis_service_option'], array());

  // Additional filters for the option extras input.
  $form_state['values']['sharethis_option_extras'] = (isset($form_state['values']['sharethis_option_extras'])) ? $form_state['values']['sharethis_option_extras'] : array();

  // Sanitize the publisher ID option.
  // Since it's a text field, remove anything that resembles code.
  $form_state['values']['sharethis_publisherID'] = filter_xss($form_state['values']['sharethis_publisherID'], array());

  if ($form_state['values']['sharethis_callesi'] == 1) {
    unset($form_state['values']['sharethis_cns']);
  }
  unset($form_state['values']['sharethis_callesi']);

  // Ensure default value for twitter prefix.
  $form_state['values']['sharethis_twitter_prefix'] = (isset($form_state['values']['sharethis_twitter_prefix'])) ? $form_state['values']['sharethis_twitter_prefix'] : '';

  // Ensure default value for twitter suffix.
  $form_state['values']['sharethis_twitter_suffix'] = (isset($form_state['values']['sharethis_twitter_suffix'])) ? $form_state['values']['sharethis_twitter_suffix'] : '';

  // Ensure default value for twitter handle.
  $form_state['values']['sharethis_twitter_handle'] = (isset($form_state['values']['sharethis_twitter_handle'])) ? $form_state['values']['sharethis_twitter_handle'] : '';

  // Ensure default value for twitter recommends.
  $form_state['values']['sharethis_twitter_recommends'] = (isset($form_state['values']['sharethis_twitter_recommends'])) ? $form_state['values']['sharethis_twitter_recommends'] : '';
}
