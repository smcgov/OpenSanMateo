<?php

function smc_base_process_page(&$variables) {
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  if (!module_exists('opensanmateo_frontend')) {
    $link = l('OpenSanMateo Frontend', 'admin/structure/features');
    drupal_set_message('In order for the San Mateo County base theme to operate properly, please enable the <strong>' . $link . '</strong> feature module.', 'warning');
  }
  
  //krumo($variables);
}

/**
 * Implements hook_preprocess_flexslider().
 */
function smc_base_preprocess_flexslider(&$variables) {
  if (!empty($variables['items'])) {
    foreach ($variables['items'] as $index => &$item) {
      if (!empty($item['item']['image_field_caption'])) {
        $item['caption'] = check_markup($item['item']['image_field_caption']['value'], $item['item']['image_field_caption']['format']);
      }
    }
  }
}

function smc_base_preprocess_node(&$variables) {
  
}

function smc_base_preprocess_block(&$variables) {
  $block = $variables['block'];

  // removes the "generic" block class to blocks as it is used elsewhere for a specific style
  // the class will be applied more specifically later
  if ($variables['classes_array'][0] == "block") {
    unset($variables['classes_array'][0]);
  }

  if (!isset($block->bid)) {
    return;
  }

  switch ($block->bid) {
    case 'menu_block-sanmateo-primary-menu':

      $variables['classes_array'][] = 'primary';
      $variables['classes_array'][] = 'main-nav';

    break;

    case 'distributed_blocks-d_b|opensanmateo_layout_banner':
      //dsm($block);
      //dsm($variables);
    break;

    case 'distributed_blocks-d_b|menu-platform-menu':
      //dsm($variables);
    break;
  }

}
function smc_base_block_view_alter(&$data, $block) {

  // there seems to be an odd case where an empty block id comes up.
  if (!isset($block->bid)) {
    return;
  }

  // Check we get the right menu block (side bar)
  if ($block->bid == 'menu_block-sanmateo-primary-menu') {

    // create a "home" link as the first link in the main menu.
    $keys = array_keys($data['content']['#content']);
    if (isset($data['content']['#content'][$keys[0]])) {
      $data['content']['#content'][$keys[0]]['#prefix'] = '<li class="home">' . l('', '<front>') . '</li>';
    }

    // use a custom function to render the submenus
    $links = $data['content']['#content'];
    foreach ($links as $key => $link) {
      if (isset($links[$key]['#below']) && (count($links[$key]['#below']) >= 1)) {
        $data['content']['#content'][$key]['#below']['#theme_wrappers'][0][0] = 'menu_tree__menu_block__sanmateo_primary_menu_submenu';
      }
    }
  }
}


function smc_base_menu_link__menu_block__sanmateo_primary_menu($variables) {
  $element = $variables['element'];
  //dsm($element);
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function smc_base_menu_tree__menu_block__sanmateo_primary_menu($variables) {
  return '<ul class="flexnav group">' . $variables['tree'] . '</ul>';
}

function smc_base_menu_tree__menu_block__sanmateo_primary_menu_submenu($variables) {
  return '<ul class="">' . $variables['tree'] . '</ul>';
}

function smc_base_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  
  if ($view->name == 'opensanmateo_search') {
    //dsm($vars);  
  }
  
}
function smc_base_preprocess_views_view_fields(&$vars) { 
  $view = $vars['view'];
  
  if ($view->name == 'opensanmateo_search') {
    
    $vars['fields']['title']->wrapper_prefix = '<header class="group clearfix">' . $vars['fields']['type']->wrapper_prefix;
    $vars['fields']['type']->wrapper_suffix = $vars['fields']['type']->wrapper_suffix . '</header>';
  }
}
function smc_base_views_pre_render(&$view) {
  //krumo($view);
  if ($view->name == 'opensanmateo_search') {
    //dsm($view);  
  }
}