<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
dpm($title, 'title');
dpm($rows, 'rows');
?>
<?php if (!empty($title)): ?>
  <div class='group-by-day clearfix'>
    <?php print $title; ?>
  </div>
<?php endif; ?>

<?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
