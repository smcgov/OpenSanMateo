
(function ($) {

Drupal.behaviors.osm_ff_remote_source = {
  attach: function (context, settings) {

    $('.osm-ff-move').each(function() {
      id = $(this).attr('for');
      $("#" + id).replaceWith($(this));
    });
    $('.filefield-source-osmremotefile td').click(function() {
      val = $(this).find('.views-field-url').text().trim();
      $(this).parents('.field-prefix').next().val(val);
    });
  }
};

})(jQuery);
