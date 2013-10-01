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

    case 'distributed_blocks-d_b--opensanmateo_layout_banner':
      //dsm($block);
      //dsm($variables);
    break;

    case 'distributed_blocks-d_b--menu-platform-menu':
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
    // Gets rid of warnings if there are no menu items
    if (empty($data['content'])) {
      return;
    }
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
    //krumo($vars);
  }  
}

function smc_base_preprocess_panels_pane(&$vars) {  
  if (isset($vars['content']['#bundle']) && $vars['content']['#bundle'] == 'promo_panels_pane') {
    if (isset($vars['content']['field_promo_style'])) {
      // assign a class we can use to style
      $vars['classes_array'][] = 'promo-pane-' . $vars['content']['field_promo_style']['#items'][0]['value'];
      // now remove the field
      unset($vars['content']['field_promo_style']);
    }
  }
}
function smc_base_preprocess_views_view_fields(&$vars) { 
  $view = $vars['view'];
  
  if ($view->name == 'opensanmateo_search') {
    
    //krumo($vars['fields']);
    // Legend for (wonky) field names
    // There is a chance the variable names may need changed later, hence this fancy legend
    // Module developers should be drawn and quartered 
    // for this type of naming convention    
    
    // TEASER
    // search_api_multi_aggregation_1   - thumbnail url
    
    // THUMBNAIL RELATED
    // search_api_multi_aggregation_2   - thumbnail url
    // search_api_multi_aggregation_15  - thumbnail title
    // search_api_multi_aggregation_16  - thumbnail alt
    
    // DATE RELATED
    // Preferend Date Format: ""
    // search_api_multi_aggregation_9   - start date
    // search_api_multi_aggregation_10  - end date
    
    // LOCATION RELATED
    // search_api_multi_aggregation_6   - street
    // search_api_multi_aggregation_17  - street 2
    // search_api_multi_aggregation_7   - city
    // search_api_multi_aggregation_4   - state
    // search_api_multi_aggregation_5   - zip
    
    // build the real thumbnail from the data parts (2, 15, 16)
    //dsm($vars['fields']['search_api_multi_aggregation_9']);
    if (isset($vars['fields']['search_api_multi_aggregation_2']->content) && strlen($vars['fields']['search_api_multi_aggregation_2']->content) >= 1) {
      $img = theme('image', array(
        'path' => $vars['fields']['search_api_multi_aggregation_2']->content,
        'title' => $vars['fields']['search_api_multi_aggregation_15']->content,
        'alt' => $vars['fields']['search_api_multi_aggregation_16']->content,
        'attributes' => array(
          'class' => array(
            'node-thumbnail-img',
          ),
        ),
      ));
      
      // apply the image
      $vars['fields']['search_api_multi_aggregation_2']->content = '<div class="node-thumbnail">' . $img . '</div>';  
      
      
      // now let's wrap the thumbnail and teaser into a single wrapper 
      $vars['fields']['search_api_multi_aggregation_1']->content = $vars['fields']['search_api_multi_aggregation_2']->content . $vars['fields']['search_api_multi_aggregation_1']->content;
      // since we've combined the two fields, unset the "original" thumbnail
      unset($vars['fields']['search_api_multi_aggregation_2']);  
    }
    else {
      // then remove it completely
      unset($vars['fields']['search_api_multi_aggregation_2']);  
    }
    
    // unset the alt and title fields completely from displaying
    unset($vars['fields']['search_api_multi_aggregation_15']);
    unset($vars['fields']['search_api_multi_aggregation_16']);
    
    
    
    
    
    
    // Adjust the header (title and type) 
    // It should be safe here to use prefix on one and suffix on the other because if
    // one is missing (type or title), there are really big problems with the node anyway
    $vars['fields']['title']->wrapper_prefix = '<header class="group clearfix">' . $vars['fields']['type']->wrapper_prefix;
    $vars['fields']['type']->wrapper_suffix = $vars['fields']['type']->wrapper_suffix . '</header>';
    
    // start date
    if (isset($vars['fields']['search_api_multi_aggregation_9']->content) && strlen($vars['fields']['search_api_multi_aggregation_9']->content) >= 1) {
      $startdate = '<div class="node-start-date">' . smc_base_gimme_date($vars['fields']['search_api_multi_aggregation_9']->content) . '</div>';
      $vars['fields']['search_api_multi_aggregation_9']->content = $startdate;
    }
    else {
      // remove it then
      unset($vars['fields']['search_api_multi_aggregation_9']);  
    }
    // end date
    if (isset($vars['fields']['search_api_multi_aggregation_10']->content) && strlen($vars['fields']['search_api_multi_aggregation_10']->content) >= 1) {
      $enddate = '<div class="node-end-date">' . smc_base_gimme_date($vars['fields']['search_api_multi_aggregation_10']->content) . '</div>';
      $vars['fields']['search_api_multi_aggregation_10']->content = $enddate;
    }
    else {
      // remove it then
      unset($vars['fields']['search_api_multi_aggregation_10']);
    }
    
    // we need to ensure that in the panels pane these items are removed
    // as the views rewrite groups them all into one field (street)
    unset($vars['fields']['search_api_multi_aggregation_4']); // state
    unset($vars['fields']['search_api_multi_aggregation_5']); // zip
    unset($vars['fields']['search_api_multi_aggregation_7']); // city
    unset($vars['fields']['search_api_multi_aggregation_17']); // street2
    
    unset($vars['fields']['more_link']); // morelink
    //krumo($vars['fields']);
    
  } // end opensanmateo_search
}

function smc_base_gimme_date($stamp) {
  // Date formatting and display
  $dateformat1 = "M j";   // Aug 12
  $dateformat2 = "S";     // th
  $dateformat3 = "Y";     // 2013
  $timeformat = "g:i a";  // 8:00 am
  $osdate = strtotime($stamp);
  $sdate1 = format_date($osdate, 'custom', $dateformat1);
  $sdate2 = format_date($osdate, 'custom', $dateformat2);
  $sdate3 = format_date($osdate, 'custom', $dateformat3);
  $stime = format_date($osdate, 'custom', $timeformat);
  return $sdate1 . '<sup>' . $sdate2 . '</sup> ' . $sdate3 . ' at ' . $stime;
}
function smc_base_views_pre_render(&$view) {
  //krumo($view);
  if ($view->name == 'opensanmateo_search') {
    //dsm($view);  
  }
}


/**
 * customize theme_follow_link to allow title text to be hidden
 */
function smc_base_follow_link($variables) {
  $link = $variables['link'];
  $link->options['html'] = true;
  $title = '<span class="follow-link-text">' . $variables['title'] . '</span>';
  $classes = array();
  $classes[] = 'follow-link';
  $classes[] = "follow-link-{$link->name}";
  $classes[] = $link->uid ? 'follow-link-user' : 'follow-link-site';
  $attributes = array(
    'class' => $classes,
    'title' => follow_link_title($link->uid) .' '. $title,
  );
  $link->options['attributes'] = $attributes;
  return l($title, $link->path, $link->options) . "\n";
}

function smc_base_pager($variables) {
  //dsm($variables);
  
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  $i = $pager_first;

  $li_first = theme('pager_first', array('text' => '1', 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => t('Prev'), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => t('Next'), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => $pager_max, 'element' => $element, 'parameters' => $parameters));


  // there's more than one page, so show the pager.
  if ($pager_total[$element] > 1) {
    
    
    
    
    $first_classes = array('pager-first');
    if ($pager_current == 1) {
       $first_classes[] = 'link-inactive';
    }
    $items[] = array(
      'class' => $first_classes,
      'data' => $li_first,
    );

    $prev_classes = array('pager-prev');
    if ($pager_current == 1) {
      $prev_classes[] = 'link-inactive';
    }
    $items[] = array(
      'class' => $prev_classes,
      'data' => $li_previous,
    );
    
    // this renders the 3 of 6 data in the center
    $items[] = array(
      'class' => array('pager-info'),
      'data' => '<span>' . $pager_current . ' of ' . $pager_max . '</span>',
    );

    $next_classes = array('pager-last');
    if ($pager_current == $pager_max) {
      $next_classes[] = 'link-inactive';
    }
    $items[] = array(
      'class' => $next_classes,
      'data' => $li_next,
    );
    
    $last_classes = array('pager-last');
    if ($pager_current == $pager_max) {
      $last_classes[] = 'link-inactive';
    }
    $items[] = array(
      'class' => $last_classes,
      'data' => $li_last,
    );
    
    
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination', 'clearfix')),
      'container_attributes' => array(
        'class' => array('pager-container', 'clearfix'),
      ),
    ));
  }
}

function smc_base_pager_first($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_page_array;
  $output = '';

  // If we are on the first page, we will show the item, but not as a link
  $link = FALSE;
  if ($pager_page_array[$element] > 0) {
    $link = TRUE;
  }
  $output = theme('pager_link', array(
    'text' => $text, 
    'link' => $link,
    'page_new' => pager_load_array(0, $element, $pager_page_array), 
    'element' => $element, 
    'parameters' => $parameters)
  );
  return $output;
}

function smc_base_pager_last($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are on the first page, we will show the item, but not as a link
  $link = FALSE;
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $link = TRUE;
  }
  $output = theme('pager_link', array(
    'text' => $text, 
    'link' => $link,
    'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array), 
    'element' => $element, 
    'parameters' => $parameters)
  );
  return $output;
}

function smc_base_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  $link = FALSE;
  if ($pager_page_array[$element] > 0) {
    $link = TRUE;
  }
  $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);
  
  $output = theme('pager_link', array(
    'text' => $text,
    'link' => $link, 
    'page_new' => $page_new, 
    'element' => $element, 
    'parameters' => $parameters)
  );
  

  return $output;
}
function smc_base_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  $link = FALSE;
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $link = TRUE;
  }

  $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);

  $output = theme('pager_link', array(
    'text' => $text, 
    'link' => $link, 
    'page_new' => $page_new, 
    'element' => $element, 
    'parameters' => $parameters)
  );

  return $output;
}

function smc_base_pager_link($variables) {
  //dsm($variables);
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $link = $variables['link'];
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  
  // if it is a link, make it a link
  if ($link) {
    $attributes['href'] = url($_GET['q'], array('query' => $query));
    return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';  
  }
  // otherwise, let's have a span
  else {
    return '<span' . drupal_attributes($attributes) . '>' . check_plain($text) . '</span>';  
  }
  
}

function smc_base_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $container_attributes = isset($variables['container_attributes']) ? drupal_attributes($variables['container_attributes']) : array('class' => array('item-list'));
  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  //$output = '<div class="item-list pager clearfix">';
  $output = '<div '. $container_attributes . '>';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}