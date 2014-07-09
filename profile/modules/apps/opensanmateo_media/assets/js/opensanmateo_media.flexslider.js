(function($) {
  $('.flexslider').bind('start', function(event, slider) {
    $.each(slider.slides, function(i, slide) {
      if (i != slider.currentSlide) {
        $(slide).css({'display': 'none'});
      }
    });
  });
  $('.flexslider').bind('before', function(event, slider) {
    $.each(slider.slides, function(i, slide) {
      if (i == slider.animatingTo) {
        $(slide).css({'display': 'block'});
      } else {
        $(slide).css({'display': 'none'});
      }
    });
  });
}(jQuery));