<?php
/**
 * @file
 * opensanmateo_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function opensanmateo_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'opensanmateo_lookup';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_san_mateo_content_index';
  $view->human_name = 'OpenSanMateo Lookup';
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
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;

  /* Display: Locations */
  $handler = $view->new_display('block', 'Locations', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );

  /* Display: Events */
  $handler = $view->new_display('block', 'Events', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );

  /* Display: All Content Types */
  $handler = $view->new_display('block', 'All Content Types', 'block_3');
  $handler->display->display_options['display_description'] = 'Returns all indexed content for a lookup view.';
  $export['opensanmateo_lookup'] = $view;

  $view = new view();
  $view->name = 'opensanmateo_media_browser';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_san_mateo_file_index';
  $view->human_name = 'OpenSanMateo Media Browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OpenSanMateo Media Browser';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed File: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_san_mateo_file_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Preview */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Preview';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[url]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Indexed File: File name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_san_mateo_file_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Indexed File: Subject */
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['id'] = 'search_api_multi_aggregation_2';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['table'] = 'search_api_index_san_mateo_file_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['field'] = 'search_api_multi_aggregation_2';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['link_to_entity'] = 0;
  /* Field: Indexed File: Description */
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['id'] = 'search_api_multi_aggregation_1';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['table'] = 'search_api_index_san_mateo_file_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['field'] = 'search_api_multi_aggregation_1';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_san_mateo_file_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'opensanmateo-media-browser';
  $export['opensanmateo_media_browser'] = $view;

  $view = new view();
  $view->name = 'opensanmateo_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_san_mateo_content_index';
  $view->human_name = 'OpenSanMateo Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'universal-teaser clearfix [type_1]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['element_wrapper_class'] = 'node-url';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'node-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_type'] = 'p';
  $handler->display->display_options['fields']['type']['element_class'] = 'meta node-type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Node: Aggregated Thumbnail */
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['id'] = 'search_api_multi_aggregation_2';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['field'] = 'search_api_multi_aggregation_2';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['element_class'] = 'node-thumbnail';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_2']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Teaser */
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['id'] = 'search_api_multi_aggregation_1';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['field'] = 'search_api_multi_aggregation_1';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['element_wrapper_class'] = 'node-teaser clearfix';
  $handler->display->display_options['fields']['search_api_multi_aggregation_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Start Date */
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['id'] = 'search_api_multi_aggregation_9';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['field'] = 'search_api_multi_aggregation_9';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['element_class'] = 'node-start-date';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_9']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated End Date */
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['id'] = 'search_api_multi_aggregation_10';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['field'] = 'search_api_multi_aggregation_10';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['element_class'] = 'node-end-date';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_10']['link_to_entity'] = 0;
  /* Field: Indexed Node: City */
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['id'] = 'search_api_multi_aggregation_7';
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['field'] = 'search_api_multi_aggregation_7';
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['element_wrapper_class'] = 'node-location-city';
  $handler->display->display_options['fields']['search_api_multi_aggregation_7']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated State */
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['id'] = 'search_api_multi_aggregation_4';
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['field'] = 'search_api_multi_aggregation_4';
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['element_wrapper_class'] = 'node-location-state';
  $handler->display->display_options['fields']['search_api_multi_aggregation_4']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Postal */
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['id'] = 'search_api_multi_aggregation_5';
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['field'] = 'search_api_multi_aggregation_5';
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['element_wrapper_class'] = 'node-location-zip';
  $handler->display->display_options['fields']['search_api_multi_aggregation_5']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Premise */
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['id'] = 'search_api_multi_aggregation_17';
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['field'] = 'search_api_multi_aggregation_17';
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_17']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Thoroughfare */
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['id'] = 'search_api_multi_aggregation_6';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['field'] = 'search_api_multi_aggregation_6';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['alter']['text'] = '<h5><span class="icon-location"> </span>Location</h5>
  <ul class="adr">
  <li>[search_api_multi_aggregation_6]</li>
  <li>[search_api_multi_aggregation_17]</li>
  <li>[search_api_multi_aggregation_7], [search_api_multi_aggregation_4]
   [search_api_multi_aggregation_5]</li>
  </ul>';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['element_wrapper_class'] = 'node-location clearfix';
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_6']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Thumbnail Title */
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['id'] = 'search_api_multi_aggregation_15';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['field'] = 'search_api_multi_aggregation_15';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_15']['link_to_entity'] = 0;
  /* Field: Indexed Node: Aggregated Thumbnail ALt */
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['id'] = 'search_api_multi_aggregation_16';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['field'] = 'search_api_multi_aggregation_16';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['label'] = '';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['element_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['search_api_multi_aggregation_16']['link_to_entity'] = 0;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type_1']['format_name'] = 0;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_release_date']['id'] = 'field_release_date';
  $handler->display->display_options['sorts']['field_release_date']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['sorts']['field_release_date']['field'] = 'field_release_date';
  $handler->display->display_options['sorts']['field_release_date']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_release_date']['expose']['label'] = 'Release Date';
  /* Filter criterion: Indexed Node: Site Hash */
  $handler->display->display_options['filters']['search_api_site_hash']['id'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_site_hash']['field'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['value'] = '2';
  $handler->display->display_options['filters']['search_api_site_hash']['group'] = 1;
  $handler->display->display_options['filters']['search_api_site_hash']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['label'] = 'True';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator'] = 'search_api_site_hash_op';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['identifier'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: List w/search */
  $handler = $view->new_display('panel_pane', 'List w/search', 'panel_pane_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Site Hash */
  $handler->display->display_options['filters']['search_api_site_hash']['id'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_site_hash']['field'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['value'] = '2';
  $handler->display->display_options['filters']['search_api_site_hash']['group'] = 1;
  $handler->display->display_options['filters']['search_api_site_hash']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['label'] = 'True';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator'] = 'search_api_site_hash_op';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['identifier'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: List by Type */
  $handler = $view->new_display('panel_pane', 'List by Type', 'panel_pane_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Site Hash */
  $handler->display->display_options['filters']['search_api_site_hash']['id'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_site_hash']['field'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['value'] = '2';
  $handler->display->display_options['filters']['search_api_site_hash']['group'] = 1;
  $handler->display->display_options['filters']['search_api_site_hash']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['label'] = 'Site';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator'] = 'search_api_site_hash_op';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['identifier'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array();
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  $handler->display->display_options['pane_category']['name'] = 'Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'search_api_site_hash' => 'configureable',
      'type' => '',
    ),
    'sorts' => array(
      'field_release_date' => '',
    ),
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Site item id */
  $handler->display->display_options['arguments']['search_api_site_id']['id'] = 'search_api_site_id';
  $handler->display->display_options['arguments']['search_api_site_id']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['arguments']['search_api_site_id']['field'] = 'search_api_site_id';
  $handler->display->display_options['arguments']['search_api_site_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_site_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_site_id']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['search_api_site_id']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Calendar pane */
  $handler = $view->new_display('panel_pane', 'Calendar pane', 'calendar_pane');
  $handler->display->display_options['display_description'] = 'Used to display events.';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Site Hash */
  $handler->display->display_options['filters']['search_api_site_hash']['id'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['search_api_site_hash']['field'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['value'] = '2';
  $handler->display->display_options['filters']['search_api_site_hash']['group'] = 1;
  $handler->display->display_options['filters']['search_api_site_hash']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['label'] = 'True';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['operator'] = 'search_api_site_hash_op';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['identifier'] = 'search_api_site_hash';
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_site_hash']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Start date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator_id'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['identifier'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_value']['widget_type'] = 'date_popup';
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_event_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value2']['expose']['operator_id'] = 'field_event_date_value2_op';
  $handler->display->display_options['filters']['field_event_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_event_date_value2']['expose']['operator'] = 'field_event_date_value2_op';
  $handler->display->display_options['filters']['field_event_date_value2']['expose']['identifier'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_value2']['widget_type'] = 'date_popup';
  /* Filter criterion: Date: Start date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value_1']['id'] = 'field_event_date_value_1';
  $handler->display->display_options['filters']['field_event_date_value_1']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['filters']['field_event_date_value_1']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value_1']['value'] = 'now';
  $handler->display->display_options['pane_category']['name'] = 'Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'search_api_site_hash' => 'exposed',
      'field_event_date_value' => 'exposed',
      'field_event_date_value2' => 'exposed',
      'field_event_date_value_1' => '',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Taxonomy Page:Subject */
  $handler = $view->new_display('block', 'Taxonomy Page:Subject', 'block_3');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Subject: Name (indexed) */
  $handler->display->display_options['arguments']['field_subject_name']['id'] = 'field_subject_name';
  $handler->display->display_options['arguments']['field_subject_name']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['arguments']['field_subject_name']['field'] = 'field_subject_name';
  $handler->display->display_options['arguments']['field_subject_name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_subject_name']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_subject_name']['default_argument_options']['code'] = '$term = taxonomy_term_load($view->args[0]);
      return $term->name;';
  $handler->display->display_options['arguments']['field_subject_name']['summary']['format'] = 'default_summary';

  /* Display: Taxonomy Page:Sub Type */
  $handler = $view->new_display('block', 'Taxonomy Page:Sub Type', 'block_4');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Sub Type: Name (indexed) */
  $handler->display->display_options['arguments']['field_sub_type_name']['id'] = 'field_sub_type_name';
  $handler->display->display_options['arguments']['field_sub_type_name']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['arguments']['field_sub_type_name']['field'] = 'field_sub_type_name';
  $handler->display->display_options['arguments']['field_sub_type_name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_sub_type_name']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_sub_type_name']['default_argument_options']['code'] = '$term = taxonomy_term_load($view->args[0]);
      return $term->name;';
  $handler->display->display_options['arguments']['field_sub_type_name']['summary']['format'] = 'default_summary';

  /* Display: Lookup Title Only Block */
  $handler = $view->new_display('block', 'Lookup Title Only Block', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Site item id */
  $handler->display->display_options['arguments']['search_api_site_id']['id'] = 'search_api_site_id';
  $handler->display->display_options['arguments']['search_api_site_id']['table'] = 'search_api_index_san_mateo_content_index';
  $handler->display->display_options['arguments']['search_api_site_id']['field'] = 'search_api_site_id';
  $handler->display->display_options['arguments']['search_api_site_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_site_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_site_id']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['search_api_site_id']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $export['opensanmateo_search'] = $view;

  return $export;
}
