(function ($) {

  Drupal.behaviors.openSanmateoLocation = {
    attach: function (context, settings) {
      button = $('<a href="#" class="osm_loc_update">Update Address</a>');
      $('.field-name-field-location', context).after(button);
      $('.osm_loc_update').click(function(evt) {
        evt.preventDefault();
        value = $(this).prev().find("input").val();
        b = $(this);
        $.get(
          "/opensanmateo_location/ajax/" + value,
          function(data) {
            console.log(data);
            b.next().find(".street-block input:first").val(data.street);
            b.next().find("input.locality").val(data.city);
            b.next().find("select.state").val(data.state);
            b.next().find("input.postal-code").val(data.zip);
        });
      });
    }
  };

})(jQuery);
