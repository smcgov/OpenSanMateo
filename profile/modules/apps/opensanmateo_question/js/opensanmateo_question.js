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
      $('.nl-field-toggle, .nl-overlay').click(function() {
        $('div .nl-dd').toggleClass('nl-field-open');
        $('.nl-overlay, .nl-field ul').toggle();
      });
    }
  };
})(jQuery);
