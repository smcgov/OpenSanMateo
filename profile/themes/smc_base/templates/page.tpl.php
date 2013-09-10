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
    <div id="dept-switch" class="clearfix">
    	<a class="close show_hide icon-close" href="" rel="#dept-switch"></a>
    	<h2>Departments</h2>
    	<ul class="group">
  			<li><a href="">Agriculture Weights and Measures</a></li>
  			<li><a href="">Assessor, County Clerk-Recorder &amp;&nbsp;Chief Elections Officer</a></li>
  			<li><a href="">Board of Supervisors</a></li>
  			<li><a href="">Child Support Services</a></li>
  			<li><a href="">Controller</a></li>
  			<li><a href="">Coroner</a></li>
  			<li><a href="">County Counsel</a></li>
  			<li><a href="">County Managers Office/Clerk of the Board</a></li>
  			<li><a href="">Courts</a></li>
  			<li><a href="">District Attorney</a></li>
  			<li><a href="">Fire Protection Services</a></li>
  			<li><a href="">Health System</a></li>
  			<li><a href="">Housing (Department of Housing)</a></li>
  			<li><a href="">Human Resources Department</a></li>
  			<li><a href="">Human Services Agency</a></li>
  			<li><a href="">Information Services Department</a></li>
  			<li><a href="">Parks Department</a></li>
  			<li><a href="">Planning and Building</a></li>
  			<li><a href="">Probation</a></li>
  			<li><a href="">Public Works</a></li>
  			<li><a href="">SamCERA (Retirement)</a></li>
  			<li><a href="">San Mateo County Library</a></li>
  			<li><a href="">Sheriff's Office</a></li>
  			<li><a href="">Tax Collector / Treasurer / Revenue Services</a></li>
  		</ul>
    </div>
    
    
    
    
    
    
    
    
    
    
  <header id="header" class="group clearfix">
      <div class="inner">
    		<a class="dept-link show_hide icon-eye" rel="#dept-switch" href="">View All Departments</a>		
    		
    		<div class="lockup group clearfix">
    			<?php if ($site_name || $site_slogan): ?>
      			
      			<?php if ($site_name): ?>            
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><h2 id="site-name" class="county-name"><?php print $site_name; ?></h2></a>
              
            <?php endif; ?>
  
            <?php if ($site_slogan): ?>
              <a href="<?php print $front_page; ?>" title="<?php print $site_slogan; ?>"><h2 id="site-slogan" class="dept-name"><?php print $site_slogan; ?></h2></a>
            <?php endif; ?>
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

    <div id="content" class="column"><div class="section">
      
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
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

    </div></div> <!-- /.section, /#content -->
  </div> <!-- /#main-wrapper -->

  <div id="footer-wrapper"><div class="section">

    <?php if ($page['footer']): ?>
      <footer id="footer" class="clearfix group">
        <?php print render($page['footer']); ?>
      </footer> <!-- /#footer -->
    <?php endif; ?>

  </div></div> <!-- /.section, /#footer-wrapper -->

</div> <!-- /#wrapper -->
