/**
 *  Javascript to calendar events effects
 */

(function ($) {
  Drupal.behaviors.opensearch_events = {
    attach: function (context, settings) {
      $('.view-opensanmateo-search .read-more-wrapper').bind( "click", function() {
        event.stopPropagation();
        $(this).hide();
        $(this).parent().children('.event-more-info').show();
        return false;
      });
  
      $('.view-opensanmateo-search .event-hide-more-info').bind( "click", function() {
        event.stopPropagation();
        $(this).parent().hide();
        $(this).parent().parent().children('.read-more-wrapper').show();
        return false;
      });
    }
  };
})(jQuery);
