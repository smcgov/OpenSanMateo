<?php if (isset($settings['text_address'])): ?>
  <div><?php print $settings['text_address']; ?></div>
<?php endif; ?>
<?php if (isset($settings['directions'])): ?>
  <div><?php print $settings['directions']; ?></div>
<?php endif; ?>
<?php if (isset($settings['link'])): ?>
  <a title="<?php print t('Go to Google map of this location'); ?>" <?php print $settings['target']; ?> href="<?php print $settings['link']; ?>">
<?php endif; ?>
<?php print theme_image(array('path' => $settings['staticmap_url'], 'attributes' => array('class' => 'static_google_map'))); ?>
<?php if (isset($settings['link'])): ?>
  </a>
<?php endif; ?>