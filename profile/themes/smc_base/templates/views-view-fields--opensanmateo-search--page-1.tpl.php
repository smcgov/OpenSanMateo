<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

$classes = ($view->row_index == 0) ? 'first-row views-row' : 'views-row';
$title = $fields['title']->content;
$location = isset($fields['search_api_multi_aggregation_6']) ? $fields['search_api_multi_aggregation_6']->content : '';
$date = $fields['dateinfo']->content;
$time_of_day = format_date($fields['search_api_multi_aggregation_9']->content, 'custom', 'g:ia');
// All Day Event start time is likely not 12am... ditch it.
if (strpos($date, 'All Day Event')) {
  $time_of_day = '';
}
$description = isset($fields['search_api_multi_aggregation_1']) ? $fields['search_api_multi_aggregation_1']->content : '';
$department = isset($fields['search_api_aggregation_3']) ? $fields['search_api_aggregation_3']->content : '';
$image = isset($fields['search_api_multi_aggregation_2']) ? $fields['search_api_multi_aggregation_2']->content : '';
$readmore = $fields['readmore']->content;
?>
<div class="<?php print $classes; ?>">
  <div class="left-col">
    <?php print $time_of_day; ?>
  </div>
  <div class="right-col">
    <?php print $image; ?>
    <header class="group clearfix">
      <?php print $title; ?>
    </header>

    <div class="description"><?php print $description; ?></div>
    <div class="department">
      <h5 class="label">Dept:</h5>
      <?php print $department; ?>
    </div>
    <span class="location"><?php print $location; ?></span>
    <?php print $date; ?>
    <?php print $readmore; ?>
  </div>
</div>
