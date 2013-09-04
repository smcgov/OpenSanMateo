<?php
/**
 * @file
 * opensanmateo_contentreview.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_contentreview_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-site_page-field_next_review'
  $field_instances['node-site_page-field_next_review'] = array(
    'bundle' => 'site_page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_next_review',
    'label' => 'Next Review',
    'required' => FALSE,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-site_page-field_review_interval'
  $field_instances['node-site_page-field_review_interval'] = array(
    'bundle' => 'site_page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_review_interval',
    'label' => 'Review Interval',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'timeperiod',
      'settings' => array(
        'units' => array(
          1 => array(
            'max' => 0,
            'step size' => 1,
          ),
          60 => array(
            'max' => 0,
            'step size' => 5,
          ),
          3600 => array(
            'max' => 23,
            'step size' => 1,
          ),
          86400 => array(
            'max' => 365,
            'step size' => 1,
          ),
        ),
      ),
      'type' => 'timeperiod_select',
      'weight' => 35,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Next Review');
  t('Review Interval');

  return $field_instances;
}

