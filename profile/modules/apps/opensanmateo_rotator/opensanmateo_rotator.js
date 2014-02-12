(function ($) {
  Drupal.behaviors.flexsliderbox = {
    attach: function(context, settings) {
      $('.pane-bundle-rotator-panels-pane .field-collection-container').addClass('flexslider');
      $('.field-name-field-coll-rotator-item > .field-items').addClass('slides');
      $('.field-name-field-rotator-caption').addClass('flex-caption');
      $('.field-name-field-rotator-description').addClass('flex-caption');
      $('.rotator-wrap-link').each(function(index) {
        var link = $(this).attr('href');
        $(this).next('.field-name-field-rotator-caption').wrap('<a href="' + link + '" />');
      });

      advanceSpeedRotator = 5000;
      advanceSpeedCarousel = 5000;
      
      for (var i=0; i < Drupal.settings.OpenSanMateoRotator.length; i++) {
        var fpid = Drupal.settings.OpenSanMateoRotator[i].fpid;
        var type = Drupal.settings.OpenSanMateoRotator[i].type;
        var slideshows;
        // must change the class from carousel to something else. .carousel is used in the foundation css
        if (type == 'carousel') {
          type = 'carousel-rotator';
        }

        $('.pane-fpid-' + fpid + '.pane-bundle-rotator-panels-pane .field-collection-container').addClass(type);
        //$('.pane-fpid-' + fpid + '.pane-bundle-rotator-panels-pane .field-collection-container').attr('advancespeed', Drupal.settings.OpenSanMateoRotator[i].advanceSpeed);
        
        var controlNav = true;
        // Add thumbnail data only if we have a rotator
        if (Drupal.settings.OpenSanMateoRotator[i].type == 'rotator') {
          var controlNav = "thumbnails";
          $('.field-name-field-coll-rotator-item > .field-items > .field-item').each(function(i) {
            var img = $(this).find('img').attr('src');
            $(this).attr('data-thumb', img);
          });
        }

        if (Drupal.settings.OpenSanMateoRotator[i].advance == '1') {
          $('.field-collection-container.rotator, .field-collection-container.carousel-rotator').addClass('flexslider-auto-advance');
        }
        if (type == 'carousel-rotator') {
          advanceSpeedCarousel = Drupal.settings.OpenSanMateoRotator[i].advanceSpeed;
        }
        else if (type == 'rotator') {
          advanceSpeedRotator = Drupal.settings.OpenSanMateoRotator[i].advanceSpeed;
        }
        advanceSpeed = Drupal.settings.OpenSanMateoRotator[i].advanceSpeed;
      }
      
      
      
      $('.field-collection-container.rotator').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        controlNav: "thumbnails",
        pauseOnHover: true,
        slideshow: false,
        slideshowSpeed: advanceSpeedRotator,
        start: function(slider){
          slider.find('.flex-control-thumbs li:eq(0)').addClass('active-item');
        },
        before: function(slider){
          slider.find('.flex-control-thumbs li').removeClass('active-item');
          slider.find('.flex-control-thumbs li:eq(' + slider.animatingTo + ')').addClass('active-item');
        },
      });
      $('.field-collection-container.carousel-rotator').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        controlNav: false,
        pauseOnHover: true,
        slideshow: false,
        slideshowSpeed: advanceSpeedCarousel,
      });

      var $advance = $('.flexslider-auto-advance');
      if ($advance.length) {
        $advance.flexslider('play');
      }
    }
  };
})(jQuery);
