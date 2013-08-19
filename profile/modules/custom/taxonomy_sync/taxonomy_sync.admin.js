(function ($) {

Drupal.behaviors.taxonomy_sync = {
  attach: function(context, settings) {
    // Add logic to enable/disable field when master is toggled
    var $master_check = $('#edit-gta-terms-sync-master', context);
    $master_check.change(function(e) {
      if ($(this).attr('checked')) {
        $('.form-item-gta-terms-sync-master-url', context).slideUp();
      }
      else {
        $('.form-item-gta-terms-sync-master-url', context).slideDown();
      }
    });

    // Fire the change event to set the field visibility
    $master_check.change();
  }
};

}) (jQuery);