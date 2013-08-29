(function ($) {
  Drupal.behaviors.flexsliderbox = {
    attach: function(context, settings) {
      $('.field-collection-container').addClass('flexslider');
      $('.field-name-field-coll-rotator-item > .field-items').addClass('slides');
      $('.field-name-field-rotator-caption').addClass('flex-caption');
      $('.field-name-field-rotator-description').addClass('flex-caption');
      var controlNav = true;
      
      // Add thumbnail data only if we have a rotator
      if (Drupal.settings.OpenSanMateoRotator.type == 'rotator') {
        var controlNav = "thumbnails"; 
        $('.field-name-field-coll-rotator-item > .field-items > .field-item').each(function(i) { 
          var img = $(this).find('img').attr('src');
          $(this).attr('data-thumb', img);
        });
      }
      
      $('.field-collection-container').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        controlNav: controlNav,
        pauseOnHover: true,
        slideshow: false,
        slideshowSpeed: 4000,
      });
    }
  };
})(jQuery);