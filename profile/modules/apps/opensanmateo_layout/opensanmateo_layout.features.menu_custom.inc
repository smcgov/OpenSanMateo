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

  // Exported menu: menu-department-menu.
  $menus['menu-department-menu'] = array(
    'menu_name' => 'menu-department-menu',
    'title' => 'Department Menu',
    'description' => 'Shared menu that is used to store department related links.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-platform-menu.
  $menus['menu-platform-menu'] = array(
    'menu_name' => 'menu-platform-menu',
    'title' => 'Platform Menu',
    'description' => 'This is the platform-wide footer menu that will be shared.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Department Menu');
  t('Platform Menu');
  t('Shared menu that is used to store department related links.');
  t('This is the platform-wide footer menu that will be shared.');


  return $menus;
}
