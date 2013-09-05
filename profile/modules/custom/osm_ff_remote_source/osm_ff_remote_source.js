
(function ($) {

Drupal.behaviors.osm_ff_remote_source = {
  attach: function (context, settings) {

    $('.filefield-source-osmremotefile td').click(function() {
      val = $(this).find('.views-field-url').text().trim();
      $(this).parents('.field-prefix').next().val(val);
    });
  }
};

})(jQuery);
