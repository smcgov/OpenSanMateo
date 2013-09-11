<?php
/**
 * @file
 * opensanmateo_security.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_security_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "password_policy2" && $api == "default_password_policy") {
    return array("version" => "1");
  }
}
