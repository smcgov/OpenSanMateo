(function($) {
  Drupal.behaviors.google_translator_init = {
    set_cookie : function(name, value, days) {
      var expiration_date = new Date();
      expiration_date.setDate(expiration_date.getDate() + days);
      var value = escape(value) + ((days == null) ? "; expires=0" : "; expires=" + expiration_date.toUTCString());
      document.cookie = name + "=" + value;
    },
    get_cookie : function(name) {
      //check for google translations cookies
      var i, x, y, cookies = document.cookie.split(";");
      var out = "";
      for( i = 0; i < cookies.length; i++) {
        x = cookies[i].substr(0, cookies[i].indexOf("="));
        y = cookies[i].substr(cookies[i].indexOf("=") + 1);
        x = x.replace(/^\s+|\s+$/g, "");
        if(x == name) {
          return unescape(y);
        }
      }
    },
    attach : function(context, settings) {
      $(document).ready(function(event) {
        //builds the jQuery selector for the configured link
        var menu_link_selector = $('a.' + settings.google_translator.jquery_selector);
        if (typeof (Drupal.behaviors.google_translator_init.get_cookie('googtrans')) != 'undefined' ) {
          menu_link_selector.hide().after(settings.google_translator.gt_script);
          $('#google_translator_element').show();
        }

        $('#google_translator_element').hide();

        menu_link_selector.click(function(event) {
          if (settings.google_translator.disclaimer.trim().length>0) {
            if($('#__dimScreen').length === 0) {
              var accept = '<a href="#" class="accept-terms">' + settings.google_translator.accept_text + '</a>';
              var cancel = '<a href="#" class="do-not-accept-terms">' + settings.google_translator.donot_accept_text + '</a>';
              var message = '<div class="message">' + settings.google_translator.disclaimer + '<div>' + accept + ' ' + cancel + '</div></div>';
              $('<div id="__dimScreen"><div class="overlay-wrapper"></div></div>').css({
                height : '100%',
                left : '0px',
                position : 'fixed',
                top : '0px',
                width : '100%',
                zIndex : '700'
              }).appendTo(document.body);

              $(document.body).css("background-color", '#ccc');

              // Attach message text.
              $('#__dimScreen .overlay-wrapper').after(message);

              // Accepted terms.
              $('#__dimScreen .message a.accept-terms').click(function(event) {
                $('#__dimScreen').hide();
                $('#google_translator_element').show();
                menu_link_selector.hide().after(settings.google_translator.gt_script);
              });

              // Attach esc key to cancel action terms action.
              $(document).keyup(function(e) {
                if (e.keyCode == 27) {
                  $('#__dimScreen').hide();
                }
              });
              // Cancel, did not accepted terms.
              $('#__dimScreen .message a.do-not-accept-terms').click(function(event) {
                $('#__dimScreen').hide();
              });

              $('#__dimScreen .overlay-wrapper').css({
                background : '#000',
                height : '100%',
                left : '0px',
                opacity : '0',
                position : 'absolute',
                top : '0px',
                width : '100%',
                zIndex : '760'
              }).fadeTo(100, 0.75, function(event) { });
            }
          } // Disclaimer already exists
          else {
            menu_link_selector.after(settings.google_translator.gt_script);
            menu_link_selector.hide();
          }
        });
      });
    }
  };
})(jQuery);
