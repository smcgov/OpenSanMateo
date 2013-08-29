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
  
  switch ($block->bid) {
    case 'menu_block-sanmateo-primary-menu':
      
      $variables['classes_array'][] = 'primary';
      $variables['classes_array'][] = 'main-nav';
      
      //krumo($variables);
      
      
    break;
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