<?php
/**
  * This template overrides the default panelizer template
  * The goal here is to COMPLETELY wipe out the H2 title on these panelizer pages.
  * The original code is commented out at the bottom for future reference
  * This method kills ANY settings for title in panelizer settings.
  * It might be better later to revert this template, and configure default settings
  * in panelizer to set everything to hide title
  
  <!-- Original panelizer template -->
  <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
      <<?php print $title_element;?> <?php print $title_attributes; ?>>
        <?php if (!empty($entity_url)): ?>
          <a href="<?php print $entity_url; ?>"><?php print $title; ?></a>
        <?php else: ?>
          <?php print $title; ?>
        <?php endif; ?>
      </<?php print $title_element;?>>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $content; ?>
  </div>  
  
  */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $content; ?>
</div>

