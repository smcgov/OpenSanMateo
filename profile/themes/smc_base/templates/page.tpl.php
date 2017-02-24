<?php

/**
 * @file
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
 */
 
?>
<div id="wrapper" class="wrapper page-wrapper group">
  <?php if ($page['highlighted']): ?>
    <?php print render($page['highlighted']); ?>
  <?php endif; ?>

  <header id="header" class="group clearfix">
      <div class="inner clearfix">
    		<a class="dept-link show_hide icon-eye" rel="#dept-switch" href="">View All Departments</a>		
    		
    		<div class="lockup group clearfix">
    		  <div class="site-seal"><a href="<?php print $smclink; ?>" title="<?php print t('County of San Mateo'); ?>"><img src="<?php print $header_logo; ?>" alt="<?php print t('County of San Mateo'); ?>" /></a></div>
    		  
    			<?php if ($site_name): ?>
      			<a href="<?php print $smclink; ?>" title="<?php print t('County of San Mateo'); ?>"><h2 class="county-name">County of San Mateo</h2></a>
            <a href="<?php print $front_page; ?>" title="<?php print $site_name; ?>" rel="home"><h2 id="site-name" class="dept-name"><?php print $site_name; ?></h2></a>
    			<?php endif; ?>
    		</div>

    <?php print render($page['header']); ?>
    <?php if ($messages): ?>
      <div id="messages" class="clearfix"><div class="section clearfix">
        <?php print $messages; ?>
      </div></div> <!-- /.section, /#messages -->
    <?php endif; ?>
    </div><!-- / inner -->
  </header> <!-- /.section, /#header -->

  

  <div id="main-wrapper" class="body clearfix">

    <?php if ($breadcrumb): ?>
      <div id="breadcrumb"><?php print $breadcrumb; ?></div>
    <?php endif; ?>

    <div id="content" class="clearfix">
      <div class="section">
      
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title && !$is_front): ?>
          <h1 class="title" id="page-title">
            <?php print $title; ?>
          </h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($tabs): ?>
          <div class="tabs clearfix">
            <?php print render($tabs); ?>
          </div>
        <?php endif; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>

      </div>
    </div> 
  </div>
  <?php if ($page['footer']): ?>
  <div id="footer-wrapper">  
    <footer id="footer" class="clearfix group">    
      <div class="limiter clearfix">
        <div class="seal clearfix">
          <img class="mobile-only" src="<?php print $footer_logo; ?>" />
          <img class="not-mobile" src="<?php print $footer_logo_small; ?>" />
          <?php print render($page['footer']); ?>
        </div>
      </div>
    </footer>
  </div>
  <?php endif; ?>

</div> <!-- /#wrapper -->
