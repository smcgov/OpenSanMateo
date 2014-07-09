<?php

/**
 * Expose entity field as a context condition.
 */
class context_condition_entity_field extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = array();
    $defaults = $this->fetch_from_context($context, 'values');

    $entity_types = array();
    foreach (entity_get_info() as $entity_type_name => $entity_type) {
      $entity_types[$entity_type_name] = $entity_type['label'];
    }

    $fields_name = array_keys(field_info_fields());
    $fields_name = array_combine($fields_name, $fields_name);

    $form['entity_type'] = array(
      '#title' => t('Entity type'),
      '#type' => 'checkboxes',
      '#options' => $entity_types,
      '#description' => t('Select entity type to check'),
      '#default_value' => isset($defaults['entity_type']) ? unserialize($defaults['entity_type']) : array(),
    );

    $form['field_name'] = array(
      '#title' => t('Field name'),
      '#type' => 'select',
      '#options' => $fields_name,
      '#description' => t('Select entity field to check'),
      '#default_value' => isset($defaults['field_name']) ? $defaults['field_name'] : TRUE,
    );

    $form['field_value'] = array(
      '#title' => t('Field value'),
      '#type' => 'textfield',
      '#description' => t('Write the entity field value to compare'),
      '#default_value' => isset($defaults['field_value']) ? $defaults['field_value'] : TRUE,
    );

    return $form;
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    return array(
      'entity_type' => serialize($values['entity_type']),
      'field_name'  => $values['field_name'],
      'field_value' => $values['field_value'],
    );
  }

  /**
   * Execute.
   */
  function execute($entity_type, $entity) {
    if ($this->condition_used()) {
      foreach ($this->get_contexts() as $context) {
        $settings = $this->fetch_from_context($context, 'values');

        if (in_array($entity_type, array_filter(unserialize($settings['entity_type'])))) {
          $items = field_get_items($entity_type, $entity, $settings['field_name']);

          if (isset($items[0]) && $settings['field_value'] == $items[0]['value']) {
            $this->condition_met($context);
          }
        }
      }
    }
  }
}
