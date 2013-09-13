<?php

/**
 * @file
 * SearchApiAlterAddMultiAggregation class definition file.
 */

/**
 * Search API data alteration callback that adds an URL field for all items.
 */
class SearchApiAlterAddMultiAggregation extends SearchApiAbstractAlterCallback {

  /**
   * Implements SearchApiAlterCallbackInterface::configurationForm().
   */
  public function configurationForm() {
    $form['#attached']['css'][] = drupal_get_path('module', 'search_api') . '/search_api.admin.css';

    $fields = $this->index->getFields(FALSE);
    $field_options = array();
    foreach ($fields as $name => $field) {
      $field_options[$name] = $field['name'];
    }
    $additional = empty($this->options['fields']) ? array() : $this->options['fields'];

    $form['#id'] = 'edit-callbacks-search-api-alter-add-multi-aggregation-settings';
    $description = '<p>This data alteration lets you define additional fields that will be added to this index. ' .
      'Each of these new fields will be an aggregation of one or more existing fields.</p>' .
      '<p>To add a new aggregated field, click the "Add new field" button and then fill out the form.</p>' .
      '<p>To remove a previously defined field, click the "Remove field" button.</p>' .
      '<p>You can also change the names or contained fields of existing aggregated fields.</p>';
    $form['description'] = array(
      '#markup' => t($description),
    );
    $form['fields']['#prefix'] = '<div id="search-api-alter-add-multi-aggregation-field-settings">';
    $form['fields']['#suffix'] = '</div>';
    if (isset($this->changes)) {
      $form['fields']['#prefix'] .= '<div class="messages warning">All changes in the form will not be saved until the <em>Save configuration</em> button at the form bottom is clicked.</div>';
    }
    foreach ($additional as $name => $field) {
      $form['fields'][$name] = array(
        '#type' => 'fieldset',
        '#title' => $field['name'] ? $field['name'] : t('New field'),
        '#collapsible' => TRUE,
        '#collapsed' => (boolean) $field['name'],
      );
      $form['fields'][$name]['name'] = array(
        '#type' => 'textfield',
        '#title' => t('New field name'),
        '#default_value' => $field['name'],
        '#required' => TRUE,
      );
      $form['fields'][$name]['fields'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Contained fields'),
        '#options' => $field_options,
        '#default_value' => drupal_map_assoc($field['fields']),
        '#attributes' => array('class' => array('search-api-alter-add-aggregation-fields')),
        '#required' => TRUE,
      );
      $form['fields'][$name]['actions'] = array(
        '#type' => 'actions',
        'remove' => array(
          '#type' => 'submit',
          '#value' => t('Remove field'),
          '#submit' => array('searchapimultiaggregate_add_multi_aggregation_field_submit'),
          '#limit_validation_errors' => array(),
          '#name' => 'search_api_add_multi_aggregation_remove_' . $name,
          '#ajax' => array(
            'callback' => 'searchapimultiaggregate_add_multi_aggregation_field_ajax',
            'wrapper' => 'search-api-alter-add-multi-aggregation-field-settings',
          ),
        ),
      );
    }
    $form['actions']['#type'] = 'actions';
    $form['actions']['add_field'] = array(
      '#type' => 'submit',
      '#value' => t('Add new field'),
      '#submit' => array('searchapimultiaggregate_add_multi_aggregation_field_submit'),
      '#limit_validation_errors' => array(),
      '#name' => 'search_api_add_multi_aggregation_add',
      '#ajax' => array(
        'callback' => 'searchapimultiaggregate_add_multi_aggregation_field_ajax',
        'wrapper' => 'search-api-alter-add-multi-aggregation-field-settings',
      ),
    );
    return $form;
  }

  /**
   * Implements SearchApiAlterCallbackInterface::configurationFormValidate().
   */
  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    unset($values['actions']);
    if (empty($values['fields'])) {
      return;
    }
    foreach ($values['fields'] as $name => $field) {
      $fields = $values['fields'][$name]['fields'] = array_values(array_filter($field['fields']));
      unset($values['fields'][$name]['actions']);
      if ($field['name'] && !$fields) {
        form_error($form['fields'][$name]['fields'], t('You have to select at least one field to aggregate. If you want to remove an aggregated field, please delete its name.'));
      }
    }
  }

  /**
   * Implements SearchApiAlterCallbackInterface::configurationFormSubmit().
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    if (empty($values['fields'])) {
      return array();
    }
    $index_fields = $this->index->getFields(FALSE);
    foreach ($values['fields'] as $name => $field) {
      if (!$field['name']) {
        unset($values['fields'][$name]);
      }
      else {
        $values['fields'][$name]['description'] = $this->fieldDescription($field, $index_fields);
      }
    }
    $this->options = $values;
    return $values;
  }

  /**
   * Implements SearchApiAlterCallbackInterface::alterItems().
   */
  public function alterItems(array &$items) {
    if (!$items) {
      return;
    }
    if (isset($this->options['fields'])) {
      foreach ($items as $item) {
        $wrapper = $this->index->entityWrapper($item);
        foreach ($this->options['fields'] as $name => $field) {
          if ($field['name']) {
            $required_fields = array();
            foreach ($field['fields'] as $f) {
              if (!isset($required_fields[$f])) {
                $required_fields[$f]['type'] = 'list<text>';
              }
            }
            $fields = search_api_extract_fields($wrapper, $required_fields);
            $values = array();
            foreach ($fields as $f) {
              if (isset($f['value'])) {
                $values[] = $f['value'];
              }
            }
            $values = $this->flattenArray($values);

            $item->{$name} = $values;
          }
        }
      }
    }
  }

  /**
   * Helper method for flattening a multi-dimensional array.
   */
  protected function flattenArray(array $data) {
    $ret = array();
    foreach ($data as $item) {
      if (!isset($item)) {
        continue;
      }
      if (is_scalar($item)) {
        $ret[] = $item;
      }
      else {
        $ret = array_merge($ret, $this->flattenArray($item));
      }
    }
    return $ret;
  }

  /**
   * Implements SearchApiAlterCallbackInterface::propertyInfo().
   */
  public function propertyInfo() {
    $ret = array();
    if (isset($this->options['fields'])) {
      foreach ($this->options['fields'] as $name => $field) {
        $ret[$name] = array(
          'label' => $field['name'],
          'description' => empty($field['description']) ? '' : $field['description'],
          'type' => 'list<text>',
        );
      }
    }
    return $ret;
  }

  /**
   * Helper method for creating a field description.
   */
  protected function fieldDescription(array $field, array $index_fields) {
    $fields = array();
    foreach ($field['fields'] as $f) {
      $fields[] = isset($index_fields[$f]) ? $index_fields[$f]['name'] : $f;
    }
    return t('A text aggregation of the following fields: @fields.', array(
      '@fields' => implode(', ', $fields),
    ));
  }

  /**
   * Submit helper callback for buttons in the callback's configuration form.
   */
  public function formButtonSubmit(array $form, array &$form_state) {
    $button_name = $form_state['triggering_element']['#name'];
    if ($button_name == 'search_api_add_multi_aggregation_add') {
      for ($i = 1; isset($this->options['fields']['search_api_multi_aggregation_' . $i]); ++$i) {
      }
      $this->options['fields']['search_api_multi_aggregation_' . $i] = array(
        'name' => '',
        'type' => 'fulltext',
        'fields' => array(),
      );
    }
    else {
      $field = substr($button_name, 40);
      unset($this->options['fields'][$field]);
    }
    $form_state['rebuild'] = TRUE;
    $this->changes = TRUE;
  }

}

/**
 * Submit function for buttons in the callback's configuration form.
 */
function searchapimultiaggregate_add_multi_aggregation_field_submit(array $form, array &$form_state) {
  $form_state['callbacks']['search_api_alter_add_multi_aggregation']->formButtonSubmit($form, $form_state);
}

/**
 * AJAX submit function for buttons in the callback's configuration form.
 */
function searchapimultiaggregate_add_multi_aggregation_field_ajax(array $form, array &$form_state) {
  return $form['callbacks']['settings']['search_api_alter_add_multi_aggregation']['fields'];
}
