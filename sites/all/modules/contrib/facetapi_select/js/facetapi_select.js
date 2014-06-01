(function ($) {
  Drupal.behaviors.facetapiSelect = {
    attach: function(context, settings) {
      if (settings.facetapi) {
        // We do a cheeky window.location to skip a form submission
        var goToLocation = function() {
          var location = $(this).find('.form-select').val();
          if (location) {
            window.location.href = location;
          }
        };
        for (var index in settings.facetapi.facets) {
          var facet = settings.facetapi.facets[index];
          if (facet.widget === 'facetapi_select_dropdowns' && facet.autoSubmit === 1) {
            // Add a handler for our select boxes
            $('#' + facet.id).change(goToLocation);
          }
        }
      }
    }
  };
})(jQuery);

