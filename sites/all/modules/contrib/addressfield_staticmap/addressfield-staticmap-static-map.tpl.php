<?php if (isset($settings['directions'])): ?>
  <div><?php print $settings['directions']; ?></div>
<?php endif; ?>  
<?php if (isset($settings['link'])): ?>
  <a title="<?php print t('Go to Google map of this location'); ?>" <?php print $settings['target']; ?> href="<?php print $settings['link']; ?>">
<?php endif; ?>
    <img class="static_google_map" src="<?php print $settings['staticmap_url']; ?>">
<?php if (isset($settings['link'])): ?>
  </a>
<?php endif; ?>