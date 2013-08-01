<?php
function embeddable_embed_plugin() {
  $plugins['embed'] = array(
    'title' => 'Embed Embeddable',
    'settings' => array(),
    'icon title' => 'Embed me',
  );
  $embeds = embeddable_embeds();

  //we want to run through all of the embeds
  //and make plugins for them
  //we are going to use the same js as embed
  //and we will look in the embed path for the icon
  //
  foreach($embeds as $id => $embed) {
    $plugins[$id] = isset($embed['wysiwyg plugin']) ? $embed['wysiwyg plugin'] : array();
    $plugins[$id]  = $plugins[$id] + array(
      'title'=> 'Embed ' .$embed['name'],
      'settings' => array('embed_type' => $id),
      'icon title' => 'Embed '. $embed['name'],
      'icon path' => $embed['path'],
      'icon file' => "$id.png",
      'js path' => drupal_get_path('module', 'embeddable') . '/wysiwyg_plugins/embed',
      'js file' => 'embed.js',
      'css path' => drupal_get_path('module', 'embeddable') . '/wysiwyg_plugins/embed',
      'css file' => 'embed.css',

    );
  }
  
  return $plugins;
}
