<?php
dpm($items);
dpm($title);
?>
<div class="hls hls-light group">
        <span class="icon-info"></span><h4 class="reverse mti_font_element"><?php print $title?></h4>
        <form id="nl-form" class="nl-form">

          <div class="nl-field nl-dd"><a class="nl-field-toggle">choose topic... ▾</a>
          <ul style="display: none;">
            <li><?php print t('Choose a topic...'); ?></li>
            <?php foreach ($items as $link => $text) : ?>
              <li><?php print l($text, $link); ?></li>
            <?php endforeach; ?>
          </ul>
          </div>
         ?
          <div class="nl-overlay" style="display: none;"></div>
        </form>
</div>
