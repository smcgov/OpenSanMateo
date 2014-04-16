<?php
/**
 * @file
 * opensanmateo_profile_social_media.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function opensanmateo_profile_social_media_defaultconfig_features() {
  return array(
    'opensanmateo_profile_social_media' => array(
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function opensanmateo_profile_social_media_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_social_media-field_social_media_title'.
  $fields['field_collection_item-field_social_media-field_social_media_title'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_social_media_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_social_media',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_social_media_title',
      'label' => 'Title',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 33,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_social_media-field_social_media_type'.
  $fields['field_collection_item-field_social_media-field_social_media_type'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_social_media_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'email' => 'Email',
          'googleplus' => 'Google +',
          'facebook' => 'Facebook',
          'twitter' => 'Twitter',
          'linkedin' => 'LinkedIn',
          'pinterest' => 'Pinterest',
          'tumblr' => 'Tumblr',
          'instagram' => 'Instagram',
          'url' => 'Other (URL)',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'field_social_media',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_social_media_type',
      'label' => 'Type',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 31,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_social_media-field_social_media_value'.
  $fields['field_collection_item-field_social_media-field_social_media_value'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_social_media_value',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_social_media',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_social_media_value',
      'label' => 'ID/Link',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 32,
      ),
    ),
  );

  // Exported field: 'node-profile-field_social_media'.
  $fields['node-profile-field_social_media'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_social_media',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'field_collection',
      'settings' => array(
        'path' => '',
      ),
      'translatable' => 0,
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'profile',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
            'hide_empty' => FALSE,
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 17,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_social_media',
      'label' => 'Social Media',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => 10,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ID/Link');
  t('Social Media');
  t('Title');
  t('Type');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function opensanmateo_profile_social_media_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_social_media';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_social_media'] = $strongarm;

  return $export;
}
