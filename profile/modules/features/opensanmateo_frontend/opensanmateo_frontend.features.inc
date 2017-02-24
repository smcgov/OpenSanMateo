<?php
/**
 * @file
 * opensanmateo_frontend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_frontend_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_wysiwyg_default_profiles_alter().
 */
function opensanmateo_frontend_wysiwyg_default_profiles_alter(&$data) {
  if (isset($data['full_html'])) {
    $data['full_html']['settings']['block_formats'] = 'p,h2,h3,h4,h5,h6,div'; /* WAS: 'p,address,pre,h2,h3,h4,h5,h6,div' */
    $data['full_html']['settings']['css_path'] = '%bprofiles/sanmateo/themes/smc_base/css/elements/editor.css'; /* WAS: '' */
    $data['full_html']['settings']['css_setting'] = 'self'; /* WAS: 'theme' */
  }
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function opensanmateo_frontend_themekey_features_rule_chain() {
  if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
  $rules = array(
    0 => array(
      'rule' => array(
        'property' => 'drupal:path',
        'operator' => '=',
        'value' => 'imce',
        'theme' => 'seven',
        'enabled' => 1,
        'wildcards' => array(),
        'module' => 'opensanmateo_frontend',
      ),
      'string' => '"drupal:path = imce >>> seven"',
      'childs' => array(),
    ),
  );

  return $rules;
}
