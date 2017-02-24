<?php 
/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 *
 * This template file is used to render the pervious and next month arrows, as
 * well as the selected start-date month above the mini-calendar attachment.
 */
$parameters = drupal_get_query_parameters();
$start_day = isset($parameters['start_date']['date']) ? $parameters['start_date']['date'] : date('Y-m-d');
$current_date = new DateTime($start_day);
$month = date_format($current_date, 'F');

$last_month = new DateTime($start_day);
$last_month->modify('first day of last month');
$last_month = date_format($last_month, 'Y-m-d');
$last_month_params = drupal_get_query_parameters();
$last_month_params['start_date'] = array('date' => $last_month);
unset($last_month_params['to_date']);
// If on page 3 of February, clicking to go to March should not take you
// to page 3 of March.
if (isset($last_month_params['page'])) {
  unset($last_month_params['page']);
}
$last_month_link = '/events/list?' . drupal_http_build_query($last_month_params);

$next_month = new DateTime($start_day);
$next_month->modify('first day of next month');
$next_month = date_format($next_month, 'Y-m-d');
$next_month_params = drupal_get_query_parameters();
$next_month_params['start_date'] = array('date' => $next_month);
unset($next_month_params['to_date']);
// If on page 3 of February, clicking to go to March should not take you
// to page 3 of March.
if (isset($next_month_params['page'])) {
  unset($next_month_params['page']);
}
$next_month_link = '/events/list?' . drupal_http_build_query($next_month_params);

?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <div class="group-by-day">
        <div class="date"><?php print $month; ?></div>
      </div>
      <div class="controls right-arrow"><a href='<?php print $next_month_link; ?>'>next</a></div>
      <div class="controls left-arrow"><a href='<?php print $last_month_link; ?>'>back</a></div>
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
