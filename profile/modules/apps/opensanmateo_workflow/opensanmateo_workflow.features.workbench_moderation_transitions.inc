<?php
/**
 * @file
 * opensanmateo_workflow.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function opensanmateo_workflow_workbench_moderation_export_transitions() {
  $items = array(
    'archived:draft' => array(
      'from_name' => 'archived',
      'to_name' => 'draft',
    ),
    'archived:published' => array(
      'from_name' => 'archived',
      'to_name' => 'published',
    ),
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
    ),
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
    ),
    'published:archived' => array(
      'from_name' => 'published',
      'to_name' => 'archived',
    ),
  );
  return $items;
}
