<?php
/**
 * @file
 * openpublic_services_demo.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function openpublic_services_demo_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:services
  $menu_links['main-menu:services'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'services',
    'router_path' => 'services',
    'link_title' => 'Services',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Services');


  return $menu_links;
}
