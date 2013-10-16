<?php

/**
 * @file
 *  A panels content type plugin to display a GovDelivery signup link
 */


// Give a plugin definition to ctools. We won't specify render or settings
// callbacks here, as we're use the standard naming pattern.
$plugin = array(
  'title' => t('GovDelivery Signup Link'),
  'description' => t('Display a GovDelivery signup link.'),
  'category' => t('Widgets'),
);

/**
 * Render function for the "GovDelivery Signup Link"
 */
function opensanmateo_govdelivery_govdelivery_signup_content_type_render($subtype, $conf, $panel_args) {
  $pane = new stdClass();
  $pane->content = opensanmateo_govdelivery_get_signup_link();
  return $pane;
}
