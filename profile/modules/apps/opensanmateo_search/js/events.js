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
        $(this).parent().find('.node-teaser').show();
        return false;
      });
  
      $('.view-opensanmateo-search .event-hide-more-info').bind( "click", function() {
        event.stopPropagation();
        $(this).parent().hide();
        $(this).parent().parent().find('.node-teaser').hide();
        $(this).parent().parent().children('.read-more-wrapper').show();
        return false;
      });

      $(".view-opensanmateo-search .views-row").click(function(){
        $(this).addClass('views-row-selected');
        $(this).find('.event-more-info').show();
        $(this).find('.node-teaser').show();
	$(this).find('.aggregated-node-thumbnail').addClass('aggregated-node-thumbnail-selected');
      });

      $(".view-opensanmateo-search .views-row .event-hide-more-info a").click(function(){
        $(this).parent().parent().parent().parent().removeClass('views-row-selected');
        $(this).parent().parent().hide();
        $(this).parent().parent().parent().find('.node-teaser').hide();
        $(this).parent().parent().parent().find('.aggregated-node-thumbnail').removeClass('aggregated-node-thumbnail-selected');

      });
    }
  };
})(jQuery);
