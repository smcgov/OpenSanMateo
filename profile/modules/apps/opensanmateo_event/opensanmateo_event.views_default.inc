<?php
/**
 * @file
 * opensanmateo_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function opensanmateo_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Upcoming Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['fields']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_event_type']['element_label_colon'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_location_address']['id'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address']['field'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['label'] = '';
  $handler->display->display_options['fields']['field_location_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_address']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
    'hide_empty' => 0,
  );
  $handler->display->display_options['fields']['field_location_address']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_thumbnail_image']['id'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['table'] = 'field_data_field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['field'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail_image']['settings'] = array(
    'image_style' => 'opensanmateo_resp_images_small',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View Event';
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date - end date (field_event_date:value2) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_event_date_value2']['default_date'] = 'now';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'upcoming_events_pane');
  $export['upcoming_events'] = $view;

  return $export;
}
