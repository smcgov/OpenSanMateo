/**
 *  Javascript to calendar events effects
 */

(function ($) {
  Drupal.behaviors.opensearch_events = {
    attach: function (context, settings) {
      // Clicking a row gives it a class.
      $(".view-opensanmateo-search .views-row").click(function(e){
        $(this).toggleClass('views-row-selected');
      });
    }
  };
})(jQuery);
