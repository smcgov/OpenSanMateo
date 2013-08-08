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
  $view->name = 'opensanmateo_calendar';
  $view->description = 'Used to display events.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_san_mateo_content_index';
  $view->human_name = 'OpenSanMateo Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'search_api_index_san_mateo_content_index';
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
  /* Field: Indexed Node: Aggregated Teaser */
  $handler->display->display_options['fields']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['fields']['search_api_aggregation_1']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['fields']['search_api_aggregation_1']['label'] = '';
  $handler->display->display_options['fields']['search_api_aggregation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_aggregation_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Indexed Node: Site Hash */
  $handler->display->display_options['filters']['search_api_site_hash']['id'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_site_hash']['field'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['value'] = '1';

  /* Display: Calendar pane */
  $handler = $view->new_display('panel_pane', 'Calendar pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['opensanmateo_calendar'] = $view;

  return $export;
}
