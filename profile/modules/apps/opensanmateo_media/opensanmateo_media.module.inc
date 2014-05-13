<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */

function opensanmateo_media_preprocess_node(&$variables) {
  if (
    !empty($variables['node'])
    && 'media' == $variables['node']->type
  ) {
    drupal_add_js(drupal_get_path('module', 'opensanmateo_media') . '/assets/js/opensanmateo_media.flexslider.js', array('type' => 'file', 'scope' => 'footer'));
  }
}
