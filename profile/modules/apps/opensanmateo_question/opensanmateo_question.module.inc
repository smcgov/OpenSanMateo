<?php
/**
 * @file
 * We have our custom module code here to prevent any chance of Features
 * overwriting it in the main .module file
 */

/**
 * Implements hook_entity_info_alter
 * https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_entity_info_alter/7
 *
 * Defines a new bundle type for the question pane since there is no UI mechanism to do so.
 * Copied from opensanmateo_rotator and modified for this app.
 */
function opensanmateo_question_entity_info_alter(&$entity_info) {
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane'] = $entity_info['fieldable_panels_pane']['bundles']['fieldable_panels_pane'];
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['label'] = 'Question Pane';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['path'] = 'admin/structure/fieldable-panels-panes/manage/%question_panels_panes_type';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['real path'] = 'admin/structure/fieldable-panels-panes/manage/question-panels-pane';
}

/**
 * Implements hook_entity_view_alter
 * https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_entity_view_alter/7
 *
 * This allows us to take the raw field collection entity data and reformat it
 * into what we need for the jQuery plugin + CSS to display properly
 */
function opensanmateo_question_entity_view_alter(&$build, $type) {
  //dpm(func_get_args()); return;
  // Check to see if this entity is one we want to manipulate (refer to opensanmateo_question_entity_info_alter)
  if ('fieldable_panels_pane' == $type && 'question_panels_pane' == $build['#bundle']) {
    $options = array('' => t('choose a topic...'));
    // Iterate through multiple items stored in the field
    foreach ($build['field_question_links']['#items'] as $index => $item) {
      // Locate the item using field_collection's indexing mechanism
      $value = $item['value'];
      $link = $build['field_question_links'][$index]['entity']['field_collection_item'][$value];

      // Set the link text, no check since it's a required field AND #markup should contain sanitized data
      $link_text = $link['field_question_links_text'][0]['#markup'];

      // Check to see if a discrete URL is provided, and use it
      if (!empty($link['field_question_links_url'][0]['#element']['url'])) {
        // Use Drupal url() function to ensure we have a properly-formed URL (note the absolute for possible external URLs)
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

    // Rewrite this element as a SELECT tag using Drupal's theming system; see theme() and theme_select()
    $build['field_question_links'] = array(
      '#theme' => 'select',
      '#options' => $options,
    );

    // Inject JS and CSS into page
    $module_path = drupal_get_path('module', 'opensanmateo_question');
    drupal_add_js("{$module_path}/js/opensanmateo_question.js");
    drupal_add_css("{$module_path}/css/opensanmateo_question.css");
  }
}
