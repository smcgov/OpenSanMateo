(function ($) {
  Drupal.behaviors.flexsliderbox = {
    attach: function(context, settings) {
      $('.pane-bundle-rotator-panels-pane .field-collection-container').addClass('flexslider');
      $('.field-name-field-coll-rotator-item > .field-items').addClass('slides');
      $('.field-name-field-rotator-caption').addClass('flex-caption');
      $('.field-name-field-rotator-description').addClass('flex-caption');
      
      for (var i=0; i < Drupal.settings.OpenSanMateoRotator.length; i++) {        
        $('.pane-bundle-rotator-panels-pane .field-collection-container').eq(i).addClass(Drupal.settings.OpenSanMateoRotator[i].type);
        
        var controlNav = true;
        // Add thumbnail data only if we have a rotator
        if (Drupal.settings.OpenSanMateoRotator[i].type == 'rotator') {
          var controlNav = "thumbnails"; 
          $('.field-name-field-coll-rotator-item > .field-items > .field-item').each(function(i) { 
            var img = $(this).find('img').attr('src');
            $(this).attr('data-thumb', img);
          });
        }
      }
      
      $('.field-collection-container.rotator').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        controlNav: "thumbnails",
        pauseOnHover: true,
        slideshow: false,
        slideshowSpeed: 4000,
      });
      $('.field-collection-container.carousel').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        controlNav: false,
        pauseOnHover: true,
        slideshow: false,
        slideshowSpeed: 4000,
      });
    }
  };
})(jQuery);