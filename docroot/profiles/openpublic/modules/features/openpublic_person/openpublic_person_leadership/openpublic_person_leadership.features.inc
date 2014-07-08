<?php
/**
 * @file
 * openpublic_person_leadership.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function openpublic_person_leadership_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
