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

      $(".view-display-id-page_1 .views-row").hover(function(){
	$(this).css("background-color", "#E7EDED");
        }, function(){
        $(this).css("background-color", "white");
      });

      $(".view-opensanmateo-search .views-row").click(function(){
        $(this).css("background-color", "white");
        $(this).find('.event-more-info').show();
        $(this).find('.node-teaser').show();
	$(this).find('.aggregated-node-thumbnail').hide();
      });

      $(".view-opensanmateo-search .views-row .event-hide-more-info a").click(function(){
        $(this).parent().parent().hide();
        $(this).parent().parent().parent().find('.node-teaser').hide();
        $(this).parent().parent().parent().find('.aggregated-node-thumbnail').show();
      });
    }
  };
})(jQuery);
