<?php
/**
 * @file
 * opensanmateo_layout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_layout_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}
