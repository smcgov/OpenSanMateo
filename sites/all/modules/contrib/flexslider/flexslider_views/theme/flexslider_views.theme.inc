<?php

/**
 * @file
 * Theme functions for FlexSlider Views integration
 *
 * @author Mathew Winstone <mwinstone@coldfrontlabs.ca>
 */

/**
 * Defines theme_views_view_flexslider().
 */
function theme_views_view_flexslider($vars) {
  $items = array();
  $view = $vars['view'];
  $options = $vars['options'];
  $optionset = flexslider_optionset_load($options['optionset']);

  $img_field_name = $vars['img_field_name'];
  $img_field_field_name = 'field_' . $img_field_name;

  $row_plugin = $view->style_plugin->row_plugin;

  foreach ($vars['rows'] as $id => $row) {
    // Render the row into a slide
    $view->row_index = $id;
    $item['slide'] = $row_plugin->render($row);

    // @todo rethink how to add alt/title tags to image fields. It's possible
    // to have multiple image fields per slide, the alt/title tags to include
    // on image fields should be tied to each field, not to the style plugin.
    /*
    if (isset($options['caption_field']) && !empty($options['caption_field'])) {
      $data = $view->style_plugin->rendered_fields[$id][$options['caption_field']];
      if (!empty($data)) {
        $item['title'] = $data;
      }
    }
    if (isset($options['text_field']) && !empty($options['text_field'])) {
      $data = $view->style_plugin->rendered_fields[$id][$options['text_field']];
      if (!empty($data)) {
        $item['alt'] = $data;
      }
    }
    //*/

    // If an image field is set, use it to set a slide thumbnail
    if (isset($row->_field_data[$view->base_field]['entity']->{$img_field_name}) and isset($row->{$img_field_field_name}[0]['raw']['uri'])) {
      $item['thumb'] = image_style_url($optionset->imagestyle_thumbnail, $row->{$img_field_field_name}[0]['raw']['uri']);
    }
    else {
      $item['thumb'] = '';
    }

    $items[] = $item;
  }

  return theme('flexslider', array(
    'items' => $items,
    'settings' => $options,
  ));
}
