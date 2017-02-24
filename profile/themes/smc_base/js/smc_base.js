/**
 * @todo
 */
Drupal.smc = Drupal.smc || {};

(function($) {
  
  Drupal.smc.toolbarFix = function() {
    // this function needs to compensate for admin users (or anyone w/access to toolbar) 
    // and rearrange the positioning of the top nav bar accordingly.
    // assuming that the user is anonymous, it already just "works" with the CSS
    $(document).ready(function(){    
      if ($('body').hasClass('toolbar')) {
        // default toolbar height = 30px;
        var toolbarHeight = $('#toolbar').height();
        //var alertHeight = $('#block-distributed-blocks-d-b-opensanmateo-layout-banner').height();
        // reapply padding to body because toolbar module doesn't do this... LOL
        // the padding on the #section-header doesn't need adjusted
        $('body').css('padding-top', toolbarHeight);

        $('body.toolbar .flexnav.show').css('padding-top', toolbarHeight + 120);
      }
    });
  }

  Drupal.behaviors.smcToolbarFix = {
    attach: function (context) {
      $(document).ready(function(){  
        Drupal.smc.toolbarFix();
      });
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
      
      $('.show_hide').click(function() {
        $('#dept-switch').slideToggle(500);
        return false;
      });
      
      /*
$('.show_hide').showHide({			 
        speed: 500,  // speed you want the toggle to happen	
        easing: '',  // the animation effect you want. Remove this line if you dont want an effect and if you haven't included jQuery UI
        changeText: 0, // if you dont want the button text to change, set this to 0
        showText: 'View',// the button text to show when a div is closed
        hideText: 'Close' // the button text to show when a div is open
      });
*/
    }
  };
  
  Drupal.behaviors.smcFlexnav = {
    attach: function (context) {
      
      $(".flexnav").flexNav();
      $('html:not(.lte8) #block-opensanmateo-search-header-search').fadeOut('fast');
      $('html:not(.lte8) .menu-button .touch-button').on('click touchstart', function(e){
        Drupal.smc.toolbarFix();
        e.stopPropagation();
        e.preventDefault();
        $('#block-opensanmateo-search-header-search').fadeToggle('fast');
        //$('#responsive-navigation').slideToggle();
        //$('#responsive-navigation').slideToggle();
        //alert('whoa!!');
      });
    }
  };
  
  Drupal.behaviors.smcHeaderSearch = {
    attach: function (context) {
      
     $('.block-opensanmateo-search a.search-button').click(function(){
       $(this).parent('.block-opensanmateo-search').find('form').submit();
     });
    }
  };
  Drupal.behaviors.smcNavToggle = {
    attach: function (context) {
      
     $('html:not(.lte8) #navigation-toggle a').click(function(){
       $('#responsive-navigation').slideToggle();
       //return false;
     });
     
     if ($('html:not(.lte8) #responsive-navigation').children().size() == 0) {
       $('.panel-col-nav').css('display', 'none');
       $('#navigation-toggle a').css('display', 'none');
     }
    }
  };
  Drupal.behaviors.smcOneColResize = {
    attach: function (context) {
     $('#block-system-main .sm-one-column').parents('#main-wrapper').addClass('one-column-display');
    }
  };
  Drupal.behaviors.smcTranslateFixes = {
    attach: function (context) {
     $('a.google-translator-switch').click(function(){
       return false;
     });
    }
  };
  Drupal.behaviors.smcMetaPadding = {
    attach: function (context) {
      var metaWidth;
      $('.universal-teaser .node-type').each(function(){
        metaWidth = $(this).outerWidth();
        $(this).parent('header').css('padding-right', metaWidth + 10);
      });
     
      $(window).resize(function(){
        metaWidth = $(this).outerWidth();
        $(this).parent('header').css('padding-right', metaWidth + 10);
      });
    }
  };
  Drupal.behaviors.smcStickyHeader = {
    attach: function (context) {

      var stuck = false;
      var move = function () {
        var st = $(window).scrollTop();
        var ot = $(".lockup").offset().top + 84;
        var s = $(".region-header");
        if (stuck == false && st > ot && ($(window).width() <= 767)) {
          stuck = true;
          s.css({
            position: "fixed",
            top: "0px"
          });
          $(".lockup").css({
            "margin-bottom" : $(".region-header").height()
          })
        }
        if (stuck == true && st <= ot) {
          stuck = false;
          s.css({
            position: "relative",
            top: ""
          });
          $(".lockup").css({
            "margin-bottom" : 0
          })
        }
      };
      $(window).scroll(move);
      move();
    }
  }
})(jQuery);