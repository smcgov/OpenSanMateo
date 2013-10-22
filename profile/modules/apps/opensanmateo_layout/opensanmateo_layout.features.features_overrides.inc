<?php
/**
 * @file
 * opensanmateo_layout.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_layout_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.node:blog_entry:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:blog_entry:default.display|content|new-8"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:blog_entry:default.display|panels|center|0"] = 'new-8';
  $overrides["panelizer_defaults.node:blog_entry:default.display|title_pane"] = 'new-8';
  $overrides["panelizer_defaults.node:document:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:document:default.display|content|new-9"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:document:default.display|panels|center|0"] = 'new-9';
  $overrides["panelizer_defaults.node:document:default.display|title_pane"] = 'new-9';
  $overrides["panelizer_defaults.node:event:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:event:default.display|content|new-5"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:event:default.display|panels|center|0"] = 'new-5';
  $overrides["panelizer_defaults.node:event:default.display|title_pane"] = 'new-5';
  $overrides["panelizer_defaults.node:location:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:location:default.display|content|new-6"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:location:default.display|panels|center|0"] = 'new-6';
  $overrides["panelizer_defaults.node:location:default.display|title_pane"] = 'new-6';
  $overrides["panelizer_defaults.node:media:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:media:default.display|content|new-7"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:media:default.display|panels|center|0"] = 'new-7';
  $overrides["panelizer_defaults.node:media:default.display|title_pane"] = 'new-7';
  $overrides["panelizer_defaults.node:profile:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:profile:default.display|content|new-10"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:profile:default.display|panels|center|0"] = 'new-10';
  $overrides["panelizer_defaults.node:profile:default.display|title_pane"] = 'new-10';
  $overrides["panelizer_defaults.node:services:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:services:default.display|content|new-2"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:services:default.display|panels|center|0"] = 'new-2';
  $overrides["panelizer_defaults.node:services:default.display|title_pane"] = 'new-2';
  $overrides["panelizer_defaults.node:site_page:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:site_page:default.display|content|new-3"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:site_page:default.display|panels|center|0"] = 'new-3';
  $overrides["panelizer_defaults.node:site_page:default.display|title_pane"] = 'new-3';
  $overrides["panelizer_defaults.node:webform:default.display|content|new-1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.node:webform:default.display|content|new-4"] = (object) array(
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
    );
  $overrides["panelizer_defaults.node:webform:default.display|panels|center|0"] = 'new-4';
  $overrides["panelizer_defaults.node:webform:default.display|title_pane"] = 'new-4';

 return $overrides;
}
