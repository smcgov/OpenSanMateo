api = 2
core = 7.x
projects[drupal][type] = core
projects[drupal][version] = 7.22
projects[drupal][patch][] = http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch
projects[drupal][patch][] = http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch
projects[drupal][patch][] = http://drupal.org/files/1355984-timeout_on_install_with_drush_si-make.patch
projects[drupal][patch][] = http://drupal.org/files/1369024-theme-inc-add-messages-id-make-D7.patch
projects[drupal][patch][] = http://drupal.org/files/1369584-form-error-link-from-message-to-element-make-D7.patch
projects[drupal][patch][] = http://drupal.org/files/1356276-make-D7-17.patch
projects[drupal][patch][] = http://drupal.org/files/issues/autocomplete_popup_position-1218684-11.patch

projects[openpublic][type] = profile
projects[openpublic][download][type] = git
projects[openpublic][download][url] = http://git.drupal.org/project/openpublic.git
projects[openpublic][download][revision] = appify_services
projects[openpublic][patch][] = http://georgia.gov/sites/default/files/PATCHES/sprint-11-opic-1.0-beta-16-boxes-homepage-ajax-fix.patch
projects[openpublic][patch][] = http://georgia.gov/sites/default/files/PATCHES/sprint-ziphius-opic-boxes-cancel-validation-fix-1758970-01.patch
; update colorbox
;projects[openpublic][patch][] = http://drupalcode.org/project/openpublic.git/patch/975da73ccf25546ec3704ddee5a31b30dc486434

projects[redirect][type] = module
projects[redirect][subdir] = contrib
projects[redirect][version] = 1.0-beta4
projects[redirect][patch][] = http://drupal.org/files/redirect_entity_type_disable-1263884-11.patch

projects[metatag][type] = module
projects[metatag][subdir] = contrib
projects[metatag][version] = 1.0-beta4
projects[metatag][patch][] = http://drupal.org/files/metatag-n1871020-9_1.patch

projects[backup_migrate][type] = module
projects[backup_migrate][subdir] = contrib
projects[backup_migrate][version] = 2.2

projects[devel][type] = module
projects[devel][subdir] = contrib
projects[devel][version] = 1.2

projects[entity_boxes][type] = module
projects[entity_boxes][subdir] = contrib
projects[entity_boxes][download][type] = git
projects[entity_boxes][download][url] = http://git.drupal.org/project/entity_boxes.git
projects[entity_boxes][download][revision] = c7c670b3cc6c37f61176ad0c20adbcfc3f4b02a8

projects[field_collection][type] = module
projects[field_collection][subdir] = contrib
projects[field_collection][version] = 1.0-beta3
projects[field_collection][patch][] = http://drupal.org/files/issue_1329856_1.patch
projects[field_collection][patch][] = http://drupal.org/files/hide_empty_field_collection-1276258-10.patch

projects[views_bulk_operations][type] = module
projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][version] = 3.0-rc1

projects[filefield_sources][type] = module
projects[filefield_sources][subdir] = contrib
projects[filefield_sources][version] = 1.7

projects[libraries][type] = module
projects[libraries][subdir] = contrib
projects[libraries][version] = 1.0
projects[libraries][patch][] = http://drupal.org/files/libraries-profile_inheritance-1783598-2.patch

projects[addressfield][type] = module
projects[addressfield][subdir] = contrib
projects[addressfield][version] = 1.0-beta2
projects[addressfield][patch][] = http://drupal.org/files/1263316%281%29.patch

projects[workbench][type] = module
projects[workbench][subdir] = contrib
projects[workbench][version] = 1.2

projects[workbench_moderation][type] = module
projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][download][type] = git
projects[workbench_moderation][download][url] = http://git.drupal.org/project/workbench_moderation.git
projects[workbench_moderation][download][revision] = 7.x-1.3
projects[workbench_moderation][patch][] = http://drupal.org/files/workbench_moderation-unpublish-api-1781852-03.patch

projects[revision_scheduler][type] = module
projects[revision_scheduler][subdir] = contrib
projects[revision_scheduler][version] = 1.x-dev
projects[revision_scheduler][download][type] = git
projects[revision_scheduler][download][url] = http://git.drupal.org/project/revision_scheduler.git
projects[revision_scheduler][download][revision] = ab04410b66e0dbdc95f8a9025431b523bf7b4480
projects[revision_scheduler][patch][] = http://drupal.org/files/revision_scheduler-in-node-edit-form-1342824-22.patch
projects[revision_scheduler][patch][] = http://drupal.org/files/revision_scheduler-wbm-unpublish-1364718-01.patch

projects[video_embed_field][type] = module
projects[video_embed_field][subdir] = contrib
projects[video_embed_field][version] = 2.0-beta4

projects[better_exposed_filters][type] = module
projects[better_exposed_filters][subdir] = contrib
projects[better_exposed_filters][version] = 3.0-beta3
projects[better_exposed_filters][patch][] = http://drupal.org/files/bef-pager-reset-1924822-01.patch

projects[calendar][type] = module
projects[calendar][subdir] = contrib
projects[calendar][version] = 3.0
projects[calendar][patch][] = http://drupal.org/files/calendar-granularity-1445228-12.patch

projects[flexslider][type] = module
projects[flexslider][subdir] = contrib
projects[flexslider][version] = 1.x-dev
projects[flexslider][download][type] = git
projects[flexslider][download][url] = http://git.drupal.org/project/flexslider.git
projects[flexslider][download][revision] = 78daf7a3e465f4c3fdfaee2e7574ab5eec45109b

projects[embeddable][type] = module
projects[embeddable][subdir] = contrib
projects[embeddable][download][type] = git
projects[embeddable][download][url] = http://git.drupal.org/project/embeddable.git
projects[embeddable][download][revision] = b52592fc5236c3c6e4fd7262cd9c7a50a28c1ad7
projects[embeddable][patch][] = http://drupal.org/files/custom_attributes_html5_compatible-1585998-1.patch

projects[addressfield_staticmap][type] = module
projects[addressfield_staticmap][subdir] = contrib
projects[addressfield_staticmap][download][type] = git
projects[addressfield_staticmap][download][url] = http://git.drupal.org/project/addressfield_staticmap.git
projects[addressfield_staticmap][download][revision] = a7b499487d90fe34bad089a9ac9843fff34d468a

projects[context_entity_field][type] = module
projects[context_entity_field][subdir] = contrib
projects[context_entity_field][version] = 1.0

projects[nodequeue][type] = module
projects[nodequeue][subdir] = contrib
projects[nodequeue][version] = 2.0-beta1

projects[imce_tools][type] = module
projects[imce_tools][subdir] = contrib
projects[imce_tools][version] = 1.0

projects[imce_mkdir][type] = module
projects[imce_mkdir][subdir] = contrib
projects[imce_mkdir][version] = 1.0

projects[password_policy2][type] = module
projects[password_policy2][subdir] = contrib
projects[password_policy2][download][type] = git
projects[password_policy2][download][url] = http://git.drupal.org/sandbox/e2thex/1380342.git
projects[password_policy2][download][revision] = 8e154c84b842778cca3cf7bd8ff6a0dbbeabdb9b

projects[lock_session][type] = module
projects[lock_session][subdir] = contrib
projects[lock_session][download][type] = git
projects[lock_session][download][url] = http://git.drupal.org/project/lock_session.git
projects[lock_session][download][revision] = cc94f8c634b1d6f9a3f551c8e8b082f549b56370
projects[lock_session][patch][] = http://drupal.org/files/lock-session-dateinterval-php-5.3-1514060-5.patch

libraries[flexslider][download][type] = git
libraries[flexslider][download][url] = https://github.com/woothemes/FlexSlider.git
libraries[flexslider][download][revision] = 6f95db1174ea3b7df2badca2b1e3e4c1c22aa3f0

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz

projects[menu_block][type] = module
projects[menu_block][subdir] = contrib
projects[menu_block][version] = 2.3

projects[special_menu_items][type] = module
projects[special_menu_items][download][type] = git
projects[special_menu_items][subdir] = contrib
projects[special_menu_items][download][url] = https://github.com/phase2/special-menu-items.git
projects[special_menu_items][download][branch] = master

projects[nice_menus][type] = module
projects[nice_menus][subdir] = contrib
projects[nice_menus][version] = 2.1

projects[textformatter][type] = module
projects[textformatter][subdir] = contrib
projects[textformatter][download][type] = git
projects[textformatter][download][url] = http://git.drupal.org/project/textformatter.git
projects[textformatter][download][revision] = 1559b04ff4c6fb2c6c2ef832bc364a9861c4f3d6
projects[textformatter][patch][] = http://drupal.org/files/textformatter-node_reference-1515278-1.patch
projects[textformatter][patch][] = http://drupal.org/files/textformatter-textformatter_separator_custom_tag.patch

projects[site_map][type] = module
projects[site_map][subdir] = contrib
projects[site_map][version] = 1.0
projects[site_map][patch][] = http://drupal.org/files/site_map-alter_hooks-1588988-01.patch

projects[acquia_connector][type] = module
projects[acquia_connector][subdir] = contrib
projects[acquia_connector][version] = 2.2

projects[memcache][type] = module
projects[memcache][subdir] = contrib
projects[memcache][version] = 1.0

projects[purge][type] = module
projects[purge][subdir] = contrib
projects[purge][version] = 1.5-rc1
projects[purge][patch][] = http://drupal.org/files/purge-proxy_url_base-1551232-5.patch

projects[expire][type] = module
projects[expire][subdir] = contrib
projects[expire][version] = 1.0-alpha3
projects[expire][patch][] = http://drupal.org/files/base_url_in_expires-1471926-9.patch
projects[expire][patch][] = http://drupal.org/files/wrong-variable-name-1452140-2.patch
projects[expire][patch][] = http://drupal.org/files/expire-removemenuhack-1451336-1-D7.patch

projects[rules][type] = module
projects[rules][subdir] = contrib
projects[rules][version] = 2.3

projects[maxlength][type] = module
projects[maxlength][subdir] = contrib
projects[maxlength][version] = 3.0-beta1

projects[globalredirect][type] = module
projects[globalredirect][subdir] = contrib
projects[globalredirect][version] = 1.4

projects[custom_pagers][type] = module
projects[custom_pagers][subdir] = contrib
projects[custom_pagers][download][type] = git
projects[custom_pagers][download][url] = http://git.drupal.org/project/custom_pagers.git
projects[custom_pagers][download][revision] = dcc774741f5152a8c6a10d21a70399d77794cfa2
projects[custom_pagers][patch][] = http://drupal.org/files/custom_pagers-api_update-1288368-59.patch
projects[custom_pagers][patch][] = http://drupal.org/files/custom_pagers-api_update-1288368-60.patch
projects[custom_pagers][patch][] = http://drupal.org/files/custom_pagers-token-help.patch

projects[context_http_headers][type] = module
projects[context_http_headers][subdir] = contrib
projects[context_http_headers][download][type] = git
projects[context_http_headers][download][url] = http://git.drupal.org/project/context_http_headers.git
projects[context_http_headers][download][revision] = cb07de891efbbc2c5aaffe0d6f3648822a9a4dfd

projects[fieldcollection_sort][type] = module
projects[fieldcollection_sort][subdir] = contrib
projects[fieldcollection_sort][download][type] = git
projects[fieldcollection_sort][download][url] = http://git.drupal.org/sandbox/jec006/1648162.git
projects[fieldcollection_sort][download][revision] = 790ee4320ceec8d53d36f838bcf457b9e76c5b76
projects[fieldcollection_sort][patch][] = http://drupal.org/files/fieldcollection_sort-link-noderef-support-1896280-02.patch

projects[publish_date][type] = module
projects[publish_date][subdir] = contrib
projects[publish_date][version] = 1.1

projects[node_reference_set_trail_formatter][type] = module
projects[node_reference_set_trail_formatter][subdir] = contrib
projects[node_reference_set_trail_formatter][version] = 1.0-alpha1
projects[node_reference_set_trail_formatter][patch][] = http://drupal.org/files/node_reference_set_trail_formatter-breadcrumbs-1707278-01.patch

projects[pathauto_persist][type] = module
projects[pathauto_persist][subdir] = contrib
projects[pathauto_persist][version] = 1.2

projects[print][type] = module
projects[print][subdir] = contrib
projects[print][version] = 1.1

projects[role_delegation][type] = module
projects[role_delegation][subdir] = contrib
projects[role_delegation][version] = 1.1
projects[role_delegation][patch][] = http://drupal.org/files/1156414-prevent-editing-of-certain-users.patch

projects[navigation404][type] = module
projects[navigation404][subdir] = contrib
projects[navigation404][version] = 1.0

projects[webform_deter][type] = module
projects[webform_deter][subdir] = contrib
projects[webform_deter][download][type] = git
projects[webform_deter][download][url] = https://github.com/phase2/webform-deter.git
projects[webform_deter][download][revision] = 2eb309e653734c06e8ff76c3dc49994306374d15

projects[content_access][type] = module
projects[content_access][subdir] = contrib
projects[content_access][version] = 1.2-beta1
projects[content_access][patch][] = http://drupal.org/files/add_view_own_unpublished_content_setting-1225520-5.patch


projects[search_api][subdir] = contrib
projects[search_api_site][type] = module
projects[search_api_site][subdir] = contrib
projects[search_api_site][download][type] = git
projects[search_api_site][download][url] = http://git.drupal.org/sandbox/e2thex/2033065.git 
projects[search_api_solr][subdir] = contrib
projects[search_api_solr][patch][] =  http://drupal.org/files/1776534.patch
projects[facetapi][subdir] = facetapi

libraries[colorbox][download][type] = get
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.4.16.zip


projects[search_api][subdir] = contrib
projects[facetapi][subdir] = contrib
projects[search_api_solr][subdir] = contrib
