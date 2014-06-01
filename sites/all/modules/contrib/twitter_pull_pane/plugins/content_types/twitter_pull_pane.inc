<?php
/**
 * Define Plugin
 */
$plugin = array(
  'title' => t('Twitter pull pane'),
  'description' => t('Provides a pane that displays data like: a user timeline or twitter search results by hashtag or a search term.'),
  'single' => TRUE,
  'content_types' => array('twitter_pull_pane_content_type'),
  'render callback' => 'twitter_pull_pane_content_type_render',
  'defaults' => array(),
  'edit form' => 'twitter_pull_pane_content_type_edit_form',
  'admin title' => 'twitter_pull_pane_content_type_admin_title',
  'admin info' => 'twitter_pull_pane_content_type_admin_info',
  'category' => t('Widgets'),
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the pane.
 */
function twitter_pull_pane_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = check_plain("Twitter");
  $search = !empty($context) ? ctools_context_keyword_substitute($conf['search'], array(), $context) : $conf['search'];    
  
  $tweets = twitter_pull_retrieve($search, $conf['items']);
  $content = theme('twitter_pull_listing', array('tweets' => $tweets, 'twitkey' => $search, 'title' => ''));
  $block->content = $content;
  
  if (is_array($tweets)) {
    return $block;
  }
  
}

/**
 * Edit form callback for the content type.
 */
function twitter_pull_pane_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['search'] = array(
    '#type' => 'textfield',
    '#title' => t('Specify twitter search term'),
    '#size' => 50,
    '#description' => t('Enter twitter search term. For example #twitter. You may use keyword substitutions.'),
    '#default_value' => !empty($conf['search']) ? $conf['search'] : '',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );
  $form['items'] = array(
    '#type' => 'textfield',
    '#title' => t('Specify number of items to pull'),
    '#size' => 50,
    '#description' => t('How many tweets do you want this pane to display?'),
    '#default_value' => !empty($conf['items']) ? $conf['items'] : '5',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );
  return $form;
}

/**
 * Form submit callback for the content type.
 */
function twitter_pull_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('search', 'items') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
* Returns the administrative title for the pane.
*/
function twitter_pull_pane_content_type_admin_title($subtype, $conf) {
  if (!empty($conf['search'])) {
    return t('Twitter pull pane: Search string @search', array('@search' => $conf['search']));
  }
}

/**
* Returns the administrative info for the pane.
*/
function twitter_pull_pane_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('View information');

  $cont = '<ul><li>Search: '. $conf['search'] .'</li>';
  $cont .= '<li>Limit: '. $conf['items'] .'</li></ul>';

  $block->content = $cont;
  return $block;
}
