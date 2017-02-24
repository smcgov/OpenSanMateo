<?php
/**
 * @file
 * opensanmateo_publishcontent.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_publishcontent_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
