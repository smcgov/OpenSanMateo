<?php
/**
 * @file
 * opensanmateo_layout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_layout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_page_manager_handlers';
  $strongarm->value = array(
    'node_view_panelizer' => TRUE,
  );
  $export['default_page_manager_handlers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_entry_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:25:"panelizer_node:blog_entry";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:blog_entry_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:document_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:23:"panelizer_node:document";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:document_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:20:"panelizer_node:event";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:event_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:location_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:23:"panelizer_node:location";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:location_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:media_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:20:"panelizer_node:media";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:media_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:press_release_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:28:"panelizer_node:press_release";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:press_release_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:profile_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:22:"panelizer_node:profile";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:profile_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:services_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:23:"panelizer_node:services";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:services_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:site_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:24:"panelizer_node:site_page";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:site_page_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:webform_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:22:"panelizer_node:webform";s:23:"allowed_layout_settings";a:13:{s:8:"flexible";b:0;s:10:"two_column";b:1;s:12:"three_column";b:1;s:14:"two_column_alt";b:1;s:10:"one_column";b:1;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:webform_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = 'access-denied';
  $export['site_403'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_404';
  $strongarm->value = 'not-found';
  $export['site_404'] = $strongarm;

  return $export;
}
