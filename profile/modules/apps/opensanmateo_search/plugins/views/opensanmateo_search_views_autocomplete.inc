<?php

/**
 * Views filter handler class for handling fulltext fields.
 */
class OpenSanMateoSearchViewsAutocomplete extends SearchApiViewsHandlerFilterOptions {

  /**
   * Provide a list of options for the operator form.
   */
  public function operator_options() {
    $options = array(
      '=' => t('Is one of'),
      'all of' => t('Is all of'),
      '<>' => t('Is none of'),
    );
    // "Is all of" doesn't make sense for single-valued fields.
    if (empty($this->definition['multi-valued'])) {
      unset($options['all of']);
    }
    return $options;
  }

  public function value_form(&$form, &$form_state) {
    $min_size = isset($this->definition['options']) ? min(4, count($this->definition['options'])) : 4;
    $form['value'] = array(
      '#type' => 'textfield',
      '#value_callback' => 'opensanmateo_form_type_textfield_value',
      '#title' => empty($form_state['exposed']) ? t('Value') : '',
      '#multiple' => TRUE,
      '#size' => $min_size,
      '#default_value' => isset($this->value) ? $this->value : array(),
    );
    // Hide the value box if operator is 'empty' or 'not empty'.
    // Radios share the same selector so we have to add some dummy selector.
    $form['value']['#states']['visible'] = array(
      ':input[name="options[operator]"],dummy-empty' => array('!value' => 'empty'),
      ':input[name="options[operator]"],dummy-not-empty' => array('!value' => 'not empty'),
    );
  }

}
