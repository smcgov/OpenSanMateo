<?php

/**
 * @file
 * Field handler to display ShareThis links.
 */

/**
 * Field handler for ShareThis.
 */
class SharethisHandlerFieldLink extends views_handler_field_entity {

  /**
   * Render values.
   */
  public function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->renderSharethisLink($entity);
    }
  }

  /**
   * Renders sharethis link.
   */
  public function renderSharethisLink($entity) {
    $path = url('node/' . $entity->nid, array('absolute' => TRUE));

    // @todo
    // The line below requires theming of the sharethis button HTML as described
    // in http://drupal.org/node/1335836 . Once the theming issue is resolved,
    // this line can be uncommented/modified to implement that functionality.
    return theme('sharethis', array(
      'data_options' => sharethis_get_options_array(),
      'm_title' => $entity->title,
      'm_path' => $path,
    ));
  }

}
