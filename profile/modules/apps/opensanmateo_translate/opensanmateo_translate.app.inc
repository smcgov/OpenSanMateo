<?php

/**
 * Implements hook_app_info().
 */
function opensanmateo_translate_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_translate_app_configure_form',
    'status callback' => 'opensanmateo_translate_status',
  );
}

/**
 * Provide app spectific settings.
 */
function opensanmateo_translate_app_configure_form() {
  // Build default translator settings page.
  $form = google_translator_settings_page();

  // Define allowed sanmateo languages.
  $allowed_langs = array(
    // Filipino.
    'tl' => 1,
    // Russian.
    'ru' => 1,
    // Spanish.
    'es' => 1,
    // Simplified chinese.
    'zh-CN' => 1,
  );

  // Filter the language option list.
  $form['gt_active_languages']['google_translator_active_languages']['#options'] = array_intersect_key($form['gt_active_languages']['google_translator_active_languages']['#options'], $allowed_langs);

  return $form;
}


/**
 * Provide the app status callback.
 */
function opensanmateo_translate_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $status['items']['menu_link'] = array(
    'title' => 'Translation link in footer',
    'action' => '',
    'description' => t("Create a menu link with &lt;google-translate&gt; as the path."),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );

  $query = db_select('menu_links', 'm')
           ->fields('m', array('mlid'))
           ->condition('menu_name', 'menu-footer-utility')
           ->condition('link_path', '<google-translate>')
           ->execute();

  $result = $query->rowCount();

  if (empty($result)) {
    $status['items']['menu_link']['severity'] = REQUIREMENT_WARNING;
    $status['items']['menu_link']['action'][] = l("Add the link", "admin/structure/menu/manage/menu-footer-utility/add",  array('query' => drupal_get_destination()));

  }

  return $status;
}
