(function ($) {
  Drupal.behaviors.webform_deter = {
    log_clear : function() {
      if (Drupal.settings.webform_deter.debug) {
        $('#' + Drupal.settings.webform_deter.debug).html('');
      }
    },
    log : function(msg) {
      if (Drupal.settings.webform_deter.debug) {
        $('#' + Drupal.settings.webform_deter.debug).append(msg + '<br />');
        if (console && console.log) {
          console.log(msg);
        }
      }
    },
    attach: function(context) {
      $('form[class*="webform"]', context).submit(function() {
        Drupal.behaviors.webform_deter.log_clear();
        var allowSubmission = true;
        $('input[type="text"], textarea', this).each(function() {
          var i, p;
          for (i in Drupal.settings.webform_deter.patterns) {
            p = new RegExp(Drupal.settings.webform_deter.patterns[i], 'i');
            Drupal.behaviors.webform_deter.log('Checking: ' + $(this).attr('id') + ' against ' + i + ': ' + p);
            if ($(this).val().match(p)) {
              Drupal.behaviors.webform_deter.log($(this).attr('id') + ' matched');
              allowSubmission = false;
              if (!Drupal.settings.webform_deter.debug) {
                return false;
              }
            }
          }
        });

        ret = (allowSubmission) ? allowSubmission : confirm(Drupal.settings.webform_deter.message);
        if (!Drupal.settings.webform_deter.debug) {
          return ret;
        }
        else {
          Drupal.behaviors.webform_deter.log('Processing complete');
          return false;
        }
      });
    }
  };
})(jQuery)
