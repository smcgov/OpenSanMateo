/**
 * Contains Javascript specific to the opensanmateo_question app
 */

(function ($) {
  /**
   * Use Drupal behaviors instead of the standard jQuery $(document).ready() construct.
   * https://drupal.org/node/304258
   */
  Drupal.behaviors.opensanmateo_question = {
    attach: function(context, settings) {
      // SMC-815 - updating methods so multiple questions can live together in harmony
      $('.nl-field-toggle').click(function() {
        // make sure all others are hidden
        $('.nl-overlay, .nl-field ul').hide();
        // add a class
        $(this).parent('.nl-field').addClass('nl-field-open');
        // show the overlay
        $(this).parent('.nl-field').next('.nl-overlay').show();
        // show the list
        $(this).next('ul').show();
      });
      $('.nl-overlay').click(function() {
        // hide any overlays and lists
        $('div .nl-dd').removeClass('nl-field-open');
        $('.nl-overlay, .nl-field ul').hide();
      });
    }
  };
})(jQuery);
