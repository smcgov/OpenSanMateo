<?php
// $Id$
/**
* @defgroup node Node Templates
* All of the node templates
*/
/**
 * @file node.tpl.php
 * Default node template.
 * @ingroup node
 */
 
 
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <div class="node-inner node-content">

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <?php if ($display_submitted && !empty($posted_by)): ?>
    <div class="submitted">
      <?php print $posted_by; ?>
    </div>
  <?php endif; ?>
  
  <?php if (!empty($unpublished)): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <div class="content clearfix">
    <?php hide($content['comments']); ?>
    <?php hide($content['links']); ?>
    <?php print render($content); ?>
    <?php print render($content['comments']); ?>
  </div>

  <?php print render($content['links']); ?>
  </div>
</div> <!-- /node-inner, /node -->
