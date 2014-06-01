(function ($) {

Drupal.behaviors.JiraIssueCollector = {
  attach: function(context, settings) {
    // Use ajax() instead of getScript() as this allows cache to be enabled.
    // This is preferable for performance reasons. The JIRA Issue Collector
    // script should not change much.
    jQuery.ajax({
      url: settings.jiraIssueCollector.url,
      type: "get",
      dataType: "script",
      cache: true,
    });
  }
};

})(jQuery);
