<?php
/**
 * @file
 * We have our custom module code here to prevent any chance of Features overwriting it in the main .module file
 */

/**
 * Implements hook_entity_info_alter()
 * 
 * Defines a new bundle type for the question pane
 */
function opensanmateo_question_entity_info_alter(&$entity_info) {
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane'] = $entity_info['fieldable_panels_pane']['bundles']['fieldable_panels_pane'];
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['label'] = 'Question Pane';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['path'] = 'admin/structure/fieldable-panels-panes/manage/%question_panels_panes_type';
  $entity_info['fieldable_panels_pane']['bundles']['question_panels_pane']['admin']['real path'] = 'admin/structure/fieldable-panels-panes/manage/question-panels-pane';
}
