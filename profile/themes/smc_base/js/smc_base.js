/**
 * @todo
 */
Drupal.smc = Drupal.smc || {};

(function($) {
  Drupal.smc.toolbarFix = function() {
    // this function needs to compensate for admin users (or anyone w/access to toolbar) 
    // and rearrange the positioning of the top nav bar accordingly.
    // assuming that the user is anonymous, it already just "works" with the CSS
    
    if ($('body').hasClass('toolbar')) {
      // default toolbar height = 30px;
      var toolbarHeight = $('#toolbar .toolbar-menu').outerHeight();
      // default toolbar drawered height (when open) = 35px;
      var toolbarDrawerHeight = 0;
      
      if (!$('#toolbar .toolbar-drawer').hasClass('collapsed')) {
        toolbarDrawerHeight = $('#toolbar .toolbar-drawer').outerHeight();
      }
      
      var navPosition = toolbarHeight + toolbarDrawerHeight;
      
      // move the top nav bar
      //$('#zone-nav-wrapper').css('top', navPosition);
      
      // reapply padding to body because toolbar module doesn't do this... LOL
      // the padding on the #section-header doesn't need adjusted
      $('body').css('padding-top', navPosition);
    }
  }

  Drupal.behaviors.smcToolbarFix = {
    attach: function (context) {
      
      Drupal.smc.toolbarFix();
      
      $(window).resize(function(){
        Drupal.smc.toolbarFix();
      });
    }
  };
  
  /**
   * @todo
   */
  Drupal.behaviors.smcShowHide = {
    attach: function (context) {
      $(document).ready(function(){
        $('.show_hide').showHide({			 
          speed: 500,  // speed you want the toggle to happen	
          easing: '',  // the animation effect you want. Remove this line if you dont want an effect and if you haven't included jQuery UI
          changeText: 0, // if you dont want the button text to change, set this to 0
          showText: 'View',// the button text to show when a div is closed
          hideText: 'Close' // the button text to show when a div is open
        }); 	
		});
    }
  };
  
  Drupal.behaviors.smcFlexnav = {
    attach: function (context) {
      $(document).ready(function(){
        $(".flexnav").flexNav();
      });
    }
  };
})(jQuery);