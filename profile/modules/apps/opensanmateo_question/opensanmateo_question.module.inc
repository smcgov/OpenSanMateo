<?php
/**
 * @file
 * We have our custom module code here to prevent any chance of Features
 * overwriting it in the main .module file
 */

/**
 * Implements hook_entity_info_alter
 *
 * Defines a new bundle type for the question pane
 */
function opensanmateo_question_entity_info_alter(&$entity_info) {
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane'] = $entity_info['fieldable_panels_pane']['bundles']['fieldable_panels_pane'];
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['label'] = 'Question Pane';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['path'] = 'admin/structure/fieldable-panels-panes/manage/%question_panels_panes_type';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['real path'] = 'admin/structure/fieldable-panels-panes/manage/question-panels-pane';
}

/**
 * Implements hook_entity_view_alter
 *
 * This allows us to take the raw field collection entity data and reformat
 * into what we need for the jQuery plugin + CSS to display properly
 */
function opensanmateo_question_entity_view_alter(&$build, $type) {
  //dpm(func_get_args()); return;
  if ('fieldable_panels_pane' == $type && 'question_panels_pane' == $build['#bundle']) {
    $options = array();
    // Iterate through multiple items stored in the field
    foreach ($build['field_question_links']['#items'] as $index => $item) {
      // Locate the item using field_collection's indexing mechanism
      $value = $item['value'];
      $link = $build['field_question_links'][$index]['entity']['field_collection_item'][$value];

      // Set the link text, no check since it's a required field AND #markup should contain sanitized data
      $link_text = $link['field_question_links_text'][0]['#markup'];

      // Check to see if a discrete URL is provided, and use it
      if (!empty($link['field_question_links_url'][0]['#element']['url'])) {
        // Use Drupal url() function to ensure we have a properly-formed URL (note the absolute for posible external URLs)
        $url = url($link['field_question_links_url'][0]['#element']['url'], array('absolute' => TRUE));
      }

      // Otherwise, check for a node reference and use it
      elseif (!empty($link['field_question_links_node_ref'][0]['#href'])) {
        // User Drupal url() to convert internal "node/123" type URL to fully-qualified URL using alias
        $url = url($link['field_question_links_node_ref'][0]['#href']);
      }

      // Fall-through
      else {
        $url = NULL;
      }

      // If we have a URL, add it to the options array to be used in a standard Drupal core select element
      if ($url) {
        $options[$url] = $link_text;
      }
    }

    $build['field_question_links'] = array(
      '#theme' => 'select',
      '#options' => $options,
    );
  }
}
