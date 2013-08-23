<?php
/**
 * @file
 * opensanmateo_layout.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function opensanmateo_layout_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-platform-menu.
  $menus['menu-platform-menu'] = array(
    'menu_name' => 'menu-platform-menu',
    'title' => 'Platform Menu',
    'description' => 'This is the platform-wide footer menu that will be shared.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Platform Menu');
  t('This is the platform-wide footer menu that will be shared.');


  return $menus;
}
