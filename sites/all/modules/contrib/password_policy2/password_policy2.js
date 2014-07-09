(function ($) {
/**
 * Overriding the standard password strength check
 */
Drupal.behaviors.passwordOverride = {
  attach: function (context, settings) {
    // set a default for our pw_status
    pw_status = {
      strength: 0,
      message: '',
      indicatorText: '',
    }

    //we take over the keyup function on password and instead make a call to 
    //the server to evaluate the password.
    //when we get the status back we update it.  Then we call focus to all 
    //the normal drupal password update
    $('input.password-field', context).once('passworda', function () {
      passwordInput = $(this);
      passwordCheck = function (e) {
        e.stopImmediatePropagation();
        $.getJSON(
          "/password_policy2/check?password=" + encodeURIComponent(passwordInput.val()),
          function(data) {
            pw_status = data;
            passwordInput.trigger("focus");
          }
        );
      };
      passwordInput.keyup(passwordCheck);
    });
    //we are overriding the normal evaluatePasseordStrength and instead 
    //are just returning the current status
    Drupal.evaluatePasswordStrength = function (password, translate) {
      return pw_status;
    };
  },
};
})(jQuery);
