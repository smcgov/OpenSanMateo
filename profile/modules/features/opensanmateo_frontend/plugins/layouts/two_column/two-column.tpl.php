<?php
/**
 * @file
 * Template for the 1 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 */
?>
<div id="main" class="panel-display sm-two-column main-body group clearfix">
  
  <div class="panel-panel panel-col-top">
    <div class="inside"><?php print $content['top']; ?></div>
  </div>
  
  <div class="panel-panel panel-col-first sidebar">
    <div id="navigation-toggle"><a href="#" class="icon-subnav">View More</a></div>
    <div id="responsive-navigation" class="inside sidebar-responsive-navigation">
      <?php print $content['nav']; ?>
    </div>
    <div class="inside sidebar-content">
      <?php print $content['left']; ?>
    </div>
  </div>

  <div class="panel-panel panel-col panel-col-middle main-content">
    <div class="inside"><?php print $content['middle']; ?></div>
  </div>
  
  <div class="panel-panel panel-col-bottom section">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>
</div>
