(function($) {

Drupal.behaviors.embed = {
  attach: function(context) {
    // We are grabing the embed for and sticking it into a dialog
    // so we can use it later
    //
    // TODO: currently we loading the form on page load and 
    // moving it into the dialog I would love for this to all
    // be ajax and pull the first form using ajax.
    id = 'embeddable-embed-form'
    form = $("#" + id);
    
    if (form.size() > 0) {
      form.show();
    }
    if(!form.hasClass('dialog')) {
      form.dialog({
        autoOpen: false,
        height: 400,
        width: 500,
        modal: true,
        dialogClass: 'node_embed_dialog'
      });
      form.addClass('dialog');
      $(form).dialog('close');
    }
    
    if(Drupal.settings.embeddable_embeds){
      // we need to define the same plugin for each of our embed types
      $.each(Drupal.settings.embeddable_embeds, function(key, value) {
        Drupal.wysiwyg.plugins[value] = Drupal.wysiwyg.plugins.embed;
      });
    }
  }
};

Drupal.wysiwyg.plugins.embed = {
  isNode: function(node) {
    return $(node).is('div.drupal-embed');
  },
  // This is run when a button is pressed
  // We are going to grab the form (which should already be
  // on the page)
  invoke: function(data,settings,instanceId) {
    id = 'embeddable-embed-form'
    form = $("#" + id);
    if(settings.embed_type) {
      form.find("[name='plugin']").val(settings.embed_type);
      form.find("[name='plugin']").trigger('change');
      form.addClass("has-plugin");
    }
    else {
    
    }
    // when insert build the correct html from 
    // the data provided 
    // insert it into the wysiwyg
    // and close the dialog
    //
    // This is getting called by a 
    // drupal ajax command from php
    // see block_enable_ajax in embeddable.module
    plugin = this;
    //remove anyother binding that might exist
    form.unbind("insert");
    form.bind("insert", function(event, data) {
      wrapper = $("<p></p>");
      insert = plugin._marker(data);
      wrapper.append(insert);
      Drupal.wysiwyg.instances[instanceId].insert(wrapper.html());
      $(".drupal-embed").click(function(e) {
        $(forma).dialog('open');
      });
      $(this).dialog('close');

    });
    $(form).dialog('open');
    /*
    this was my attempt at pulling the form ajax   
      element = $("#" + id);
    $.ajax({ 
      url :"/embeddable/embed-form",
      'success': function(data) {
        $(element).replaceWith(data);        
        Drupal.attacheBehaviors(element);
        element_settings =  {
          'url':"embeddable/embed-form",
          'element' : element
         };
        Drupal.ajax[id] = new Drupal.ajax(id, element, {'url':"embeddable/embed-form"});
     }
    });
    */
  },
  // This runs each time the wysiwyg editing is turn on
  // we are adding the place holder inside of the div so that 
  // we can see what it is
  attach: function(content, settings, instanceId) {
    //content = content.replace(/<!--break-->/g, this._getPlaceholder(settings));
    var $content = $('<div>' + content + '</div>');
    plugin = this;
    $.each($('.drupal-embed', $content), function (i, elem) {
      //first fill in a genearl placeholder
      $(elem).html(plugin._placeholder(elem));
      //then go get a better one
      //we have to do this not async becuase we need
      //to get the values back so we can return them
      //at the end of this function (note we are returning 
      //a string at the end(
      $.ajax({
        async:false,
        type: "POST",
        url:  Drupal.settings.basePath + 'embeddable/title',
        data: $(elem).getAttributes(),
        success: function(msg) {
          $(elem).html(plugin._placeholder(elem, msg));
        }
      });
      //TODO: this does not work
      //need to find a way to attach events to the
      //embed content so that people can edit it and 
      //so they do not edit it
      $(elem).click(function(e) {
      });
    });
    return $content.html();
  },
  // This runs on submit as well as when the editor is disabled
  // we are removing all of the html from inside of our div
  detach: function(content, settings, instanceId) {
    var $content = $('<div>' + content + '</div>');
    $.each($('.drupal-embed', $content), function (i, elem) {
      $(elem).html("");
    });
    return $content.html();
  },
  // This returns the marker that should be insert 
  _marker: function(data) {
    insert = $("<div class='drupal-embed'></div>");
    $.each(data, function(key, value) {
      if(key == 'preview') {
        insert.html(value);
      }
      insert.attr(key, value);
    });
    return insert;
  },
  // This returns what should be shown in the wysiwyg
  // @TODO: this should get a preview or atleast the title of the content
  _placeholder: function(elem, title) {
    title = typeof(title) != 'undefined' ? title : "EMBEDED CONTENT";
    return "<div class = 'drupal-embed-icon'></div>"+title+"<div>&nbsp;</div>";
  }
}

$.fn.getAttributes = function() {
  var attributes = {}; 

  if(!this.length)
    return this;

  $.each(this[0].attributes, function(index, attr) {
    attributes[attr.name] = attr.value;
  }); 

  return attributes;
}


})(jQuery);
