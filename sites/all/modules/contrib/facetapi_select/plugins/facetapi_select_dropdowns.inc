<?php

/**
 * Widget that renders facets as dropdowns.
 */
class FacetapiSelectDropdowns extends FacetapiWidgetLinks {

  /**
   * Overrides FacetapiWidget::__construct().
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->jsSettings['autoSubmit'] = $this->settings->settings['auto-submit'];
  }

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into a select form
   *
   * @see FacetapiWidgetLinks::buildSelectOptions()
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    $vars = $this->buildSelectOptions($element);
    $vars['attributes'] = $this->build['#attributes'];
    // Give peeps a chance to identify the facet.
    $vars['widget'] = $this;
    $vars['facet'] = $this->facet;

    // @TODO: This whole affair currently assumes that only a single value is
    // allowed for the filter, and thus we'll be using a standard drop-down.
    // It would be nice that if multiple values were allowed we switched to a
    // multi-value select.
    // $facet_array = $this->facet->getFacet();
    // if ($this->facet->getAdapter()->getUrlProcessor()->limitActiveItems($facet_array)) {
    //   // Switch to multiselect
    // }

    $element = drupal_get_form('facetapi_select_select_form', $vars);
  }

  /**
   * Transforms the render array for use in a form
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   */
  public function buildSelectOptions($build) {
    $settings = $this->settings->settings;

    // Builds rows.
    $items = array();
    // Initially we presume no filter is active, so it's the current page
    $remove_filter_link = request_uri();

    foreach ($build as $value => $item) {
      // This is a little hacky (putting the url as the value of our select
      // list), but it means our form submission handler can do a simple
      // drupal_goto and our javascript can just do a window.location, rather
      // than submitting the form and getting redirected. Should be quicker.
      //
      // If we ever expand this module to include multi-selects, we'll need to
      // instead rely on the form submit handler to calculate the correct url to
      // redirect to.
      $url = url($item['#path'], array('query' => $item['#query']));
      // If this filter value is not active
      if (!$item['#active']) {
        $items[$url] = format_plural($item['#count'], $settings['option-text-single'], $settings['option-text-multiple'], array('!label' => $item['#markup']));
      }
      // Otherwise the link provided is the one to 'remove' the filter value
      else {
        $remove_filter_link = $url;
        $items[request_uri()] = $item['#markup'];
        $active = $url;
      }
    }

    $items = array(
      $remove_filter_link => $settings['no-selection'],
    ) + $items;

    return array('options' => $items, 'settings' => $settings);

  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  function settingsForm(&$form, &$form_state) {
    $form['widget']['widget_settings']['links'][$this->id]['no-selection'] = array(
      '#type' => 'textfield',
      '#title' => t('No Selection'),
      '#default_value' => $this->settings->settings['no-selection'],
      '#description' => t('The text used for no selection in the select.'),
      '#size' => 20,
    );
    $form['widget']['widget_settings']['links'][$this->id]['auto-submit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Auto submit'),
      '#description' => t('Hide the forms submit button and submit automatically'),
      '#default_value' => $this->settings->settings['auto-submit'],
    );
    $form['widget']['widget_settings']['links'][$this->id]['option-text-single'] = array(
      '#type' => 'textfield',
      '#title' => t('Option text (singular)'),
      '#description' => t('This text will be used to construct the option labels in the select box. You may use the following tokens: !label'),
      '#default_value' => $this->settings->settings['option-text-single'],
    );
    $form['widget']['widget_settings']['links'][$this->id]['option-text-multiple'] = array(
      '#type' => 'textfield',
      '#title' => t('Option text (multiple'),
      '#description' => t('This text will be used to construct the option labels in the select box. You may use the following tokens: !label, @count'),
      '#default_value' => $this->settings->settings['option-text-multiple'],
    );
  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  function getDefaultSettings() {
    return array(
      'no-selection' => t('Any'),
      'auto-submit' => 1,
      'option-text-single' => '!label (1 result)',
      'option-text-multiple' => '!label (@count results)',
    );
  }
}

