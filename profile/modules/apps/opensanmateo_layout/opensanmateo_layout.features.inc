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
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function opensanmateo_layout_panelizer_defaults_override_alter(&$data) {
  if (isset($data['node:blog_entry:default'])) {
    $data['node:blog_entry:default']->display->content['new-8'] = (object) array(
          'pid' => 'new-8',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:blog_entry:default']->display->panels['center']['0'] = 'new-8'; /* WAS: 'new-1' */
    $data['node:blog_entry:default']->display->title_pane = 'new-8'; /* WAS: 'new-1' */
    unset($data['node:blog_entry:default']->display->content['new-1']);
  }
  if (isset($data['node:document:default'])) {
    $data['node:document:default']->display->content['new-9'] = (object) array(
          'pid' => 'new-9',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:document:default']->display->panels['center']['0'] = 'new-9'; /* WAS: 'new-1' */
    $data['node:document:default']->display->title_pane = 'new-9'; /* WAS: 'new-1' */
    unset($data['node:document:default']->display->content['new-1']);
  }
  if (isset($data['node:event:default'])) {
    $data['node:event:default']->display->content['new-5'] = (object) array(
          'pid' => 'new-5',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:event:default']->display->panels['center']['0'] = 'new-5'; /* WAS: 'new-1' */
    $data['node:event:default']->display->title_pane = 'new-5'; /* WAS: 'new-1' */
    unset($data['node:event:default']->display->content['new-1']);
  }
  if (isset($data['node:location:default'])) {
    $data['node:location:default']->display->content['new-6'] = (object) array(
          'pid' => 'new-6',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:location:default']->display->panels['center']['0'] = 'new-6'; /* WAS: 'new-1' */
    $data['node:location:default']->display->title_pane = 'new-6'; /* WAS: 'new-1' */
    unset($data['node:location:default']->display->content['new-1']);
  }
  if (isset($data['node:media:default'])) {
    $data['node:media:default']->display->content['new-7'] = (object) array(
          'pid' => 'new-7',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:media:default']->display->panels['center']['0'] = 'new-7'; /* WAS: 'new-1' */
    $data['node:media:default']->display->title_pane = 'new-7'; /* WAS: 'new-1' */
    unset($data['node:media:default']->display->content['new-1']);
  }
  if (isset($data['node:profile:default'])) {
    $data['node:profile:default']->display->content['new-10'] = (object) array(
          'pid' => 'new-10',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:profile:default']->display->panels['center']['0'] = 'new-10'; /* WAS: 'new-1' */
    $data['node:profile:default']->display->title_pane = 'new-10'; /* WAS: 'new-1' */
    unset($data['node:profile:default']->display->content['new-1']);
  }
  if (isset($data['node:services:default'])) {
    $data['node:services:default']->display->content['new-2'] = (object) array(
          'pid' => 'new-2',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:services:default']->display->panels['center']['0'] = 'new-2'; /* WAS: 'new-1' */
    $data['node:services:default']->display->title_pane = 'new-2'; /* WAS: 'new-1' */
    unset($data['node:services:default']->display->content['new-1']);
  }
  if (isset($data['node:site_page:default'])) {
    $data['node:site_page:default']->display->content['new-3'] = (object) array(
          'pid' => 'new-3',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:site_page:default']->display->panels['center']['0'] = 'new-3'; /* WAS: 'new-1' */
    $data['node:site_page:default']->display->title_pane = 'new-3'; /* WAS: 'new-1' */
    unset($data['node:site_page:default']->display->content['new-1']);
  }
  if (isset($data['node:webform:default'])) {
    $data['node:webform:default']->display->content['new-4'] = (object) array(
          'pid' => 'new-4',
          'panel' => 'center',
          'type' => 'entity_view',
          'subtype' => 'node',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'view_mode' => 'full',
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['node:webform:default']->display->panels['center']['0'] = 'new-4'; /* WAS: 'new-1' */
    $data['node:webform:default']->display->title_pane = 'new-4'; /* WAS: 'new-1' */
    unset($data['node:webform:default']->display->content['new-1']);
  }
}
