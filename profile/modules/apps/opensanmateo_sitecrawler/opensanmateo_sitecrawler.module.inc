<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */

/**
 * Shows this block on every page except the listed pages.
 */
define('PATH_IMPORT_NOTLISTED', 0);

/**
 * Shows this block on only the listed pages.
 */
define('PATH_IMPORT_LISTED', 1);

/**
 * Shows this block if the associated PHP code returns TRUE.
 */
define('PATH_IMPORT_PHP', 2);

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
  
  $items['admin/config/opensanmateo_sitecrawler'] = array(
    'title' => 'Open SanMateo Site Crawler',
    'description' => 'Configure sites to crawl for content.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_form'),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/config/opensanmateo_sitecrawler/%'] = array(
    'title' => 'Open SanMateo Site Crawler',
    'description' => 'Configure sites to crawl for content.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_form', 3),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_LOCAL_TASK,
  );
  
  $items['admin/config/opensanmateo_sitecrawler/delete/%'] = array(
    'title' => 'Open SanMateo Delete Site Crawler',
    'description' => 'Delete existing crawler.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_delete_form', 4),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_LOCAL_TASK,
  );
  
  $items['admin/config/opensanmateo_sitecrawler/run/%'] = array(
    'title' => 'Open SanMateo Delete Site Crawler',
    'description' => 'Delete existing crawler.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('opensanmateo_sitecrawler_admin_item_run_form', 4),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_LOCAL_TASK,
  );
   
  return $items;
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
  $form['actions']['cancel'] = array('#markup' => l(t('Cancel'), 'admin/config/opensanmateo_sitecrawler'),);
  
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
      drupal_goto('admin/config/opensanmateo_sitecrawler/delete/' . $form_state['values']['opensanmateo_sitecrawler_id']);
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
    drupal_goto('admin/config/opensanmateo_sitecrawler');
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
    'admin/config/opensanmateo_sitecrawler/' . $id
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
    drupal_goto('admin/config/opensanmateo_sitecrawler');
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
    'admin/config/opensanmateo_sitecrawler'
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

  $crawler = new SiteCrawler($record['id']);
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
    if (!empty($rule)) {
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
      'admin/config/opensanmateo_sitecrawler/add',
      array(
        'query' => array(
          'destination' => 'admin/config/opensanmateo_sitecrawler'
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
      'admin/config/opensanmateo_sitecrawler/add',
      array(
        'query' => array(
          'destination' => 'admin/config/opensanmateo_sitecrawler'
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

    // Add each element of the $form data to the $rows array using drupal_render()
    // to generate the final html markup for each.
    $rows[] = array(
      'data' => array(
        drupal_render($form['crawlers'][$id]['name']),
        drupal_render($form['crawlers'][$id]['url']),
        drupal_render($form['crawlers'][$id]['enabled']),
        l(
          'edit',
          'admin/config/opensanmateo_sitecrawler/' . $id,
          array(
            'query' => array(
              'destination' => 'admin/config/opensanmateo_sitecrawler'
            )
          )
        )
        . ' '
        . l(
          'delete',
          'admin/config/opensanmateo_sitecrawler/delete/' . $id,
          array(
            'query' => array(
              'destination' => 'admin/config/opensanmateo_sitecrawler'
            )
          )
        )
        . ' '
        . l(
          'run',
          'admin/config/opensanmateo_sitecrawler/run/' . $id,
          array(
            'query' => array(
              'destination' => 'admin/config/opensanmateo_sitecrawler'
            )
          )
        ),
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

function opensanmateo_sitecrawler_apachesolr_update_index($document, $node, $namespace) {
die('killed by opensanmateo_sitecrawler_apachesolr_update_index');
drupal_set_message('opensanmateo_sitecrawler_apachesolr_update_indexL ' . print_r($node->title,1));
  if ($node->type == 'sitecrawler_page') {
    $document->ss_url = $node->field_sitecrawler_url[$node->language][0]['url'];
  }
}


/**
 * implements hook_search_api_index_items_alter
 *
 * we do not know the index id in the allCallback object so we need to jump in here and add the value for the id
 */
function search_opensanmateo_sitecrawler_search_api_index_items_alter(array &$items, SearchApiIndex $index) {
die('killed by opensanmateo_sitecrawler_apachesolr_update_index');
  foreach ($items as $id => $item) {
drupal_set_message('opensanmateo_sitecrawler_apachesolr_update_indexL ' . print_r($item->title,1));
    $hash = search_api_site_hash();
    $item->search_api_site_id = "{$index->machine_name}-{$id}-{$hash}";
  }
}
