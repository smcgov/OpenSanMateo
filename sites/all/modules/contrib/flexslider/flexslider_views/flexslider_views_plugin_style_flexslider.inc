<?php
/**
 * @file
 * flexslider style plugin for the Views module.
 */

/**
  * Implements a style type plugin for the Views module.
  */
class flexslider_views_plugin_style_flexslider extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options += array(
      'optionset' => array('default' => 'default'),
      'caption_field' => array('' => t('None')),
      'text_field' => array('' => t('None')),
    );

    return $options;
  }

  /**
   * Show a form to edit the style options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['flexslider'] = array(
      '#type' => 'fieldset',
      '#title' => t('FlexSlider'),
    );

    $optionsets = array();
    foreach (flexslider_optionset_load_all() as $name => $optionset) {
      $optionsets[$name] = check_plain($optionset->title);
    }
    $form['flexslider']['optionset'] = array(
      '#title' => t('Option set'),
      '#type' => 'select',
      '#options' => $optionsets,
      '#default_value' => $this->options['optionset'],
    );

    $link_options = array('' => t('None'));
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $link_options[$field] = $handler->ui_name();
    }

    /*
    $form['flexslider']['caption_field'] = array(
      '#type' => 'select',
      '#title' => t('Caption Field'),
      '#multiple' => FALSE,
      '#description' => t('Select a field to be used as a caption. This is typically the name of the image and can be used to link to the source content.'),
      '#options' => $link_options,
      '#default_value' => $this->options['caption_field'],
    );

    $form['flexslider']['text_field'] = array(
      '#type' => 'select',
      '#title' => t('Description Field'),
      '#multiple' => FALSE,
      '#description' => t('Select a field to be used as a description of the image or extra information for the viewer.'),
      '#options' => $link_options,
      '#default_value' => $this->options['text_field'],
    );
    */
  }

  /**
   * Performs some cleanup tasks on the options array before saving it.
   */
  function options_submit(&$form, &$form_state) {
    $options =& $form_state['values']['style_options'];

    // Pull the fieldset values one level up
    $options = $options['flexslider'];
    unset($options['flexslider']);
  }

  /**
   * Searches for the image field to use.
   */
  function find_image_field() {
    foreach ($this->view->display_handler->get_handlers('field') as $id => $handler) {
      if (($handler instanceof views_handler_field_field) && ($handler->field_info['type'] == 'image')) {
        return $id;
        break;
      }
    }
    return FALSE;
  }

  /**
   * Render the display in this style.
   */
  function render() {
    $image_field = $this->find_image_field();
    if ($image_field === FALSE) {
      drupal_set_message(t('Style @style requires an image field to be added.', array('@style' => $this->definition['title'])), 'error');
      return;
    }

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    // Render each group separately and concatenate.
    $output = '';
    foreach ($sets as $title => $rows) {
      $output .= theme($this->theme_functions(),
        array(
          'view' => $this->view,
          'options' => $this->options,
          'img_field_name' => $image_field,
          'rows' => $rows,
          'title' => $title)
        );
    }
    return $output;
  }
}
