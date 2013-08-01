<?php
$plugin = array(
  'embed callback' => 'embed_block'
);
function embed_block($info) {
  $block = (object) $info;
  $render = _block_get_renderable_array(_block_render_blocks(array($block)));
  return drupal_render($render);
}

function block_wysiwyg_form(&$form, &$form_state) {
 $options = array();
 foreach(module_implements("block_info") as $module) {
   foreach(module_invoke($module, "block_info") as $key => $data) {
   $options[$module]["$module::$key"] = $data['info'];
   }
 }
 $form['block'] = array(
   '#type' => 'select',
   '#title' => t('Block'),
   '#options' => $options,
 );
}
function block_wysiwyg_submit(&$form, &$form_state) {
  list($module, $delta) = explode("::", $form_state['values']['block']);
  return array("module"=> $module, "delta" => $delta);
}
function block_wysiwyg_title($data) {
  $info = module_invoke($data['module'], "block_info");
  return "BLOCK: {$info[$data['delta']]['info']}";
}
