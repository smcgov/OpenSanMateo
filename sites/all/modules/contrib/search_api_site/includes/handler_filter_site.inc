<?php

define('SEARCH_API_SITE_THIS_SITE_ONLY', 1);
define('SEARCH_API_SITE_ALL_SITES', 2);
/**
 * @file
 *   Contains the SearchApiSiteViewsHandler class.
 */

class SearchApiSiteViewsHandler extends  views_handler_filter_boolean_operator {
  /**
   * Provide a form for setting the filter value.
   */
  public function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    //TODO make there on option for a checkbox.  At the moment i can not get it working because if the expose filter is defaulted to True, that it will always show as check even if you uncheck it.
    #$form['value']['#type'] = 'checkbox';


    $form['value']['#options'] = array(
      SEARCH_API_SITE_THIS_SITE_ONLY => t('This site only'),
      SEARCH_API_SITE_ALL_SITES => t('All sites')
    );
  }

  /**
   * Add this filter to the query.
   */
  public function query() {
    if ($this->value == SEARCH_API_SITE_THIS_SITE_ONLY) {
      $this->value = search_api_site_hash();
      $this->query->condition($this->real_field, $this->value, $this->operator, $this->options['group']);
    }
  }

}
