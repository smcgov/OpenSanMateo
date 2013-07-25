<?php
/**
 * @file
 * opensanmateo_location.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_location_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.opensanmateo_lookup.display|block_1"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:3:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:2:{s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:7:"filters";a:1:{s:4:"type";a:4:{s:2:"id";s:4:"type";s:5:"table";s:40:"search_api_index_san_mateo_content_index";s:5:"field";s:4:"type";s:5:"value";a:1:{s:8:"location";s:8:"location";}}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_1";s:13:"display_title";s:9:"Locations";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.opensanmateo_search.display|block_2"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:4:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:6:"fields";b:0;s:9:"arguments";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:6:"fields";a:2:{s:3:"url";a:8:{s:2:"id";s:3:"url";s:5:"table";s:40:"search_api_index_san_mateo_content_index";s:5:"field";s:3:"url";s:5:"label";s:0:"";s:7:"exclude";b:1;s:19:"element_label_colon";b:0;s:15:"display_as_link";b:0;s:14:"link_to_entity";i:0;}s:5:"title";a:7:{s:2:"id";s:5:"title";s:5:"table";s:40:"search_api_index_san_mateo_content_index";s:5:"field";s:5:"title";s:5:"label";s:0:"";s:5:"alter";a:2:{s:9:"make_link";b:1;s:4:"path";s:5:"[url]";}s:19:"element_label_colon";b:0;s:14:"link_to_entity";i:0;}}s:9:"arguments";a:1:{s:18:"search_api_site_id";a:7:{s:2:"id";s:18:"search_api_site_id";s:5:"table";s:40:"search_api_index_san_mateo_content_index";s:5:"field";s:18:"search_api_site_id";s:21:"default_argument_type";s:5:"fixed";s:7:"summary";a:1:{s:6:"format";s:15:"default_summary";}s:12:"break_phrase";i:1;s:3:"not";i:0;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_2";s:13:"display_title";s:23:"Lookup Title Only Block";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');

 return $overrides;
}
