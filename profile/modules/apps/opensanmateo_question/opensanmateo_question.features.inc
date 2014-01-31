<?php
/**
 * @file
 * opensanmateo_question.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_question_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function opensanmateo_question_views_api() {
  return array("api" => "3.0");
}
