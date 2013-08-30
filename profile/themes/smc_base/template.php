<?php


function smc_base_css_alter(&$css) {
  //krumo($css);
}

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
}

function smc_base_preprocess_block(&$variables) {
  $block = $variables['block'];
  
  // removes the "generic" block class to blocks as it is used elsewhere for a specific style
  // the class will be applied more specifically later
  if ($variables['classes_array'][0] == "block") {
    unset($variables['classes_array'][0]);
  }
  //krumo($block->bid);
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
  
  
  // Check we get the right menu block (side bar)
  if ($block->bid == 'menu_block-sanmateo-primary-menu') {
    //dsm($data);
    
    // create a "home" link as the first link in the main menu.
    $keys = array_keys($data['content']['#content']);
    $data['content']['#content'][$keys[0]]['#prefix'] = '<li class="home">' . l('', '<front>') . '</li>';
    
    $links = $data['content']['#content'];
    foreach ($links as $key => $link) {
      if (isset($links[$key]['#below']) && (count($links[$key]['#below']) >= 1)) {
        //dsm('submenu detected.');
        //dsm($links[$key]);
        $data['content']['#content'][$key]['#below']['#theme_wrappers'][0][0] = 'menu_tree__menu_block__sanmateo_primary_menu_submenu';
      }
    }
  }
}
function smc_base_process_menu_tree(&$variables) {
  //dsm($variables);
  //$variables['tree'] = $variables['tree']['#children'];
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
  // <li class="home">'. l('', '<front>') .'</li>
  return '<ul class="flexnav group">' . $variables['tree'] . '</ul>';
}

function smc_base_menu_tree__menu_block__sanmateo_primary_menu_submenu($variables) {
  // <li class="home">'. l('', '<front>') .'</li>
  return '<ul class="">' . $variables['tree'] . '</ul>';
}