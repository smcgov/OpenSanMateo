
(function ($) {

Drupal.behaviors.osm_ff_remote_source = {
  attach: function (context, settings) {

    $('.filefield-source-osmremotefile .view-row').click(function() {
      val = $(this).find('.views-field-url .field-content').text();
      $(this).parents('.view-opensanmateo-media-browser').next().find('input.form-text').val(val);
    });
  }
};

})(jQuery);
