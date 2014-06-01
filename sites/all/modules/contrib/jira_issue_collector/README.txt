This project integrates the JIRA Issue Collector with your Drupal site.
https://marketplace.atlassian.com/583856

"The JIRA Issue Collector plugin makes collecting feedback and bugs from your
users and customers easier than ever.
If you develop web-applications or web sites, the JIRA Issue Collector is the
best way to turn your customers' and users' feedback and problems directly into
JIRA issues, all without requiring a JIRA login.
Instead of having to navigate to JIRA to raise bugs users will be able to raise
issues directly from within your web-application, in a feedback form that you
design!
Users will see a button (or "trigger") for feedback, and can click the button to
raise feedback or bugs on a form embedded in your web application."

The code is heavily inspired by the SnapEngage module.

# Installation and configuration

To use JIRA Issue Collector you need a working JIRA 5.x installation and access
to project administration. JIRA Issue Collector supports both OnDemand and
Download versions for JIRA.

To start collecting issues for a JIRA project from your Drupal site complete the
following steps:

- Download and install this module.
- Go to the project administration page for the JIRA project and add a new issue
  collector
- Enter your configuration and submit the issue collector.
- Find the "Embedding this Issue Collector" section and copy the code. Both
  "Embed directly..." and "Embed in an existing JavaScript resource..." should
  work.
- Go to the JIRA Isse Collector configuration page on your Drupal site
  (admin/config/system/jira_issue_collector) and paste the code in the "Embed
  code" section.
- Adjust the remaining configuration options as needed and save the
  configuration.
