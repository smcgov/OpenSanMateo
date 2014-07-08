<?php
$plugin = array(
  'embed callback' => 'embed_entity'
);
function embed_entity($info) {
  
  $render = _block_get_renderable_array(_block_render_blocks(array($block)));
  return drupal_render($render);
}

