<?php
/**
 * @file
 * opensanmateo_rotator.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_rotator_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
