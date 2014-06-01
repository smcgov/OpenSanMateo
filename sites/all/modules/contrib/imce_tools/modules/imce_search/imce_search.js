imce.hooks.load.push(function() {
  imce.opAdd({
    name : 'search',
    title : 'Search',
    content : jQuery('#imce-search-form')
  });
  jQuery('#imce-search-form').submit(function() {
    jQuery('#imce-search-results div').html('Searching ' + ((imce.conf.dir == '.') ? 'all ' : imce.conf.dir + ' and sub') +'directories for ' + jQuery('#edit-imce-search-term').val());
    jQuery('#imce-search-results div').addClass('loading');
    var case_insensitive = 0;
    jQuery('#edit-imce-search-case:checked').each(function() { case_insensitive = 1; });
    jQuery.ajax({
      url: Drupal.settings.basePath + 'imce_search_callback/' + case_insensitive + '/' + encodeURI(imce.conf.dir + '/' + jQuery('#edit-imce-search-term').val()),
      type: 'GET',
      success: function(serverdata, status, xmlhttp) {
        data = eval('(' + serverdata + ')');
        var filelist = jQuery.map(data.files, function(fullpath, index) {
          var li = document.createElement('li');
          /*jQuery(li).click(function () { 
            file = fullpath.substr(fullpath.lastIndexOf('/') + 1);
            dir = fullpath.substr(0, fullpath.lastIndexOf('/'));
            imce.dirActivate(dir);
            imce.highlight(file);
          });*/
          if (index > 10) {
            jQuery(li).addClass('toggle');
          }
          jQuery(li).html(fullpath);
          return li;
        });
        jQuery('#imce-search-results ul').hide();
        jQuery('#imce-search-results ul').empty().append(filelist);
        jQuery('#imce-search-results ul li[class="toggle"]').hide();
        jQuery('#imce-search-results ul').show();
        jQuery('#imce-search-results div').html(data.search + '. ' + data.files.length + ' results found. ');
        if (data.files.length > 10) {
          var toggle =  document.createElement('a');
          jQuery(toggle).append('Show all');
          jQuery(toggle).toggle(function () {
              jQuery(this).html('Short list');
              jQuery('#imce-search-results ul li[class*="toggle"]').show();
            },
            function () {
              jQuery(this).html('Show all');
              jQuery('#imce-search-results ul li[class*="toggle"]').hide();
            }
          );
          jQuery('#imce-search-results div').append(toggle);
        }
        jQuery('#imce-search-results div').removeClass('loading');
      }
    });
    return false;
  });
});
