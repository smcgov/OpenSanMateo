(function ($) {
  Drupal.behaviors.flexsliderbox = { 
    attach: function(context, settings) {
      $('.field-collection-container').flexslider({
        selector: '.field-name-field-coll-rotator-item > .field-items > .field-item',
        //animation: "slide",
        
      });
      
    }
  };
  console.info('urgh');
})(jQuery);