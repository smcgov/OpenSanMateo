api = 2
core = 7.x
projects[drupal][type] = core
projects[drupal][version] = 7.28
projects[drupal][patch][] = http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch
;projects[drupal][patch][] = http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch
projects[drupal][patch][] = http://drupal.org/files/1355984-timeout_on_install_with_drush_si-make.patch
projects[drupal][patch][] = http://drupal.org/files/1369024-theme-inc-add-messages-id-make-D7.patch
projects[drupal][patch][] = http://drupal.org/files/1369584-form-error-link-from-message-to-element-make-D7.patch
projects[drupal][patch][] = http://drupal.org/files/1356276-make-D7-17.patch
projects[drupal][patch][] = http://drupal.org/files/issues/autocomplete_popup_position-1218684-11.patch

projects[openpublic][type] = profile
projects[openpublic][download][type] = git
projects[openpublic][download][url] = http://git.drupal.org/project/openpublic.git
projects[openpublic][download][revision] = appify_services

projects[redirect][type] = module
projects[redirect][subdir] = contrib
projects[redirect][version] = 1.0-beta4
projects[redirect][patch][] = http://drupal.org/files/redirect_entity_type_disable-1263884-11.patch

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
projects[libraries][version] = 2.1
projects[libraries][patch][] = http://drupal.org/files/libraries-profile_inheritance-1783598-4.patch

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

projects[workbench_access][type] = module
projects[workbench_access][subdir] = contrib
projects[workbench_access][version] = 1.2

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
projects[video_embed_field][version] = 2.0-beta5

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
projects[flexslider][download][type] = git
projects[flexslider][download][url] = http://git.drupal.org/project/flexslider.git
projects[flexslider][download][revision] = 068df89
projects[flexslider][patch][] = https://drupal.org/files/issues/flexslider_include_object_in_callback-1580902-39.patch
projects[flexslider][patch][] = https://drupal.org/files/issues/flexslider-2123947-thumbnail-image-style-11.patch

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
projects[addressfield_staticmap][download][revision] = f9f1d97b025ddc0f02af3b39a88da662fcf5d15d

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

libraries[flexslider][download][type] = git
libraries[flexslider][download][url] = https://github.com/woothemes/FlexSlider.git
libraries[flexslider][download][revision] = ce5441b214a46322424a32c92d77baaadeed9688

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
projects[acquia_connector][version] = 2.14

projects[memcache][type] = module
projects[memcache][subdir] = contrib
projects[memcache][version] = 1.0

projects[purge][type] = module
projects[purge][subdir] = contrib
projects[purge][version] = 1.6

projects[acquia_purge][type] = module
projects[acquia_purge][subdir] = contrib
projects[acquia_purge][version] = 1.0-beta2

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

projects[search_api][type] = module
projects[search_api][subdir] = contrib
projects[search_api][version] = 1.7
projects[search_api][patch][] = http://drupal.org/files/search_api-url-arg-multivalue-2040111-01.patch

projects[search_api_site][type] = module
projects[search_api_site][subdir] = contrib
projects[search_api_site][download][type] = git
projects[search_api_site][download][branch] = 7.x-1.x
projects[search_api_site][download][url] = http://git.drupal.org/sandbox/e2thex/2033065.git

projects[features_template][type] = module
projects[features_template][subdir] = contrib
projects[features_template][download][type] = git
projects[features_template][download][url] = http://git.drupal.org/project/features_template.git
projects[features_template][download][revision] =   6ed792a0ad0555f24516a804a8dfe05ea275910c

projects[quick_search][type] = module
projects[quick_search][subdir] = contrib
projects[quick_search][download][type] = git
projects[quick_search][download][branch] = 7.x-1.x
projects[quick_search][download][url] = http://git.drupal.org/sandbox/jec006/1524412.git

projects[search_api_solr][type] = module
projects[search_api_solr][type] = module
projects[search_api_solr][subdir] = contrib
projects[search_api_solr][version] = 1.0
projects[search_api_solr][patch][] =  http://drupal.org/files/1776534.patch

projects[search_api_acquia][type] = module
projects[search_api_acquia][subdir] = contrib
projects[search_api_acquia][download][type] = git
projects[search_api_acquia][download][url] = http://git.drupal.org/project/search_api_acquia.git
projects[search_api_acquia][download][revision] = 1967e867e0df80a476e218a120d30327034766d9
projects[search_api_acquia][patch][1977510] = http://drupal.org/files/1977510-14--remove_SolrPhpClient.patch
projects[search_api_acquia][patch][2087141] = http://drupal.org/files/search_api_acquia-acquia_search_host_precedence-2087141-1.patch

projects[search_api_solr_overrides][type] = module
projects[search_api_solr_overrides][subdir] = contrib
projects[search_api_solr_overrides][version] = 1.0-rc1

projects[searchapimultiaggregate][type] = module
projects[searchapimultiaggregate][subdir] = contrib
projects[searchapimultiaggregate][version] = 1.1

projects[panelizer][type] = module
projects[panelizer][subdir] = contrib
projects[panelizer][version] = 3.1

projects[facetapi][type] = module
projects[facetapi][subdir] = contrib
projects[facetapi][version] = 1.3
projects[facetapi][patch][1393928] = http://drupal.org/files/limit-active-items-1393928-48.patch

projects[facetapi_select][type] = module
projects[facetapi_select][subdir] = contrib
projects[facetapi_select][download][type] = git
projects[facetapi_select][download][branch] = 7.x-1.x
projects[facetapi_select][download][url] = http://git.drupal.org/sandbox/stevetweeddale/1776754.git

projects[oauth][type] = module
projects[oauth][subdir] = contrib
projects[oauth][version] = 3.1

projects[fieldable_panels_panes][type] = module
projects[fieldable_panels_panes][subdir] = contrib
projects[fieldable_panels_panes][version] = 1.4

projects[twitter][type] = module
projects[twitter][subdir] = contrib
projects[twitter][version] = 5.8

projects[twitter_pull][type] = module
projects[twitter_pull][subdir] = contrib
projects[twitter_pull][download][type] = git
projects[twitter_pull][download][url] = http://git.drupal.org/project/twitter_pull.git
projects[twitter_pull][download][revision] = 46b6f89568aa50654295ad8e192673744afa4d35

projects[twitter_pull_pane][type] = module
projects[twitter_pull_pane][subdir] = contrib
projects[twitter_pull_pane][download][type] = git
projects[twitter_pull_pane][download][branch] = master
projects[twitter_pull_pane][download][url] = http://git.drupal.org/sandbox/pontusnilsson/1371892.git

projects[sharethis][type] = module
projects[sharethis][subdir] = contrib
projects[sharethis][version] = 2.5

projects[addtocal][type] = module
projects[addtocal][subdir] = contrib
projects[addtocal][version] = 1.0-beta3

projects[image_field_caption][type] = module
projects[image_field_caption][subdir] = contrib
projects[image_field_caption][version] = 2.0

projects[publishcontent][type] = module
projects[publishcontent][subdir] = contrib
projects[publishcontent][version] = 1.2

projects[picture][type] = module
projects[picture][subdir] = contrib
projects[picture][download][type] = git
projects[picture][download][url] = http://git.drupal.org/project/picture.git
projects[picture][download][revision] = 3d9fe6c4b5fc5e48fcee225853cd32b6e5f61242

projects[workbench][type] = module
projects[workbench][subdir] = contrib
projects[workbench][version] = 1.2

projects[workbench_moderation][type] = module
projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][download][type] = git
projects[workbench_moderation][download][url] = http://git.drupal.org/project/workbench_moderation.git
projects[workbench_moderation][download][revision] = a90378de5b1aea2b095ff5613eea44f55947f514

projects[breakpoints][type] = module
projects[breakpoints][subdir] = contrib
projects[breakpoints][version] = 1.1

projects[distributed_blocks][type] = module
projects[distributed_blocks][subdir] = contrib
projects[distributed_blocks][download][type] = git
projects[distributed_blocks][download][url] = http://git.drupal.org/project/distributed_blocks.git
projects[distributed_blocks][download][revision] = 501219b163acda942c06d3c0017655fba7695b3c
projects[distributed_blocks][patch][2105889] = http://drupal.org/files/issues/distributed_blocks-undefined-offset-2105889-01.patch

libraries[colorbox][download][type] = get
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.4.16.zip

projects[field_views][type] = module
projects[field_views][subdir] = contrib
projects[field_views][version] = 1.0-alpha1

projects[taxonomy_view_mode][type] = module
projects[taxonomy_view_mode][subdir] = contrib
projects[taxonomy_view_mode][version] = 1.0-alpha1

projects[xrds_simple][type] = module
projects[xrds_simple][subdir] = contrib
projects[xrds_simple][version] = 1.1

projects[openid_provider][type] = module
projects[openid_provider][subdir] = contrib
projects[openid_provider][version] = 1.0

projects[remote_stream_wrapper][type] = module
projects[remote_stream_wrapper][subdir] = contrib
projects[remote_stream_wrapper][version] = 1.0-beta4
projects[remote_stream_wrapper][patch][1926434] = http://drupal.org/files/broken-image-style-7.20-1926434-0.patch

projects[jquery_update][type] = module
projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.3

projects[variable][type] = module
projects[variable][subdir] = contrib
projects[variable][version] = 1.1

projects[i18n][type] = module
projects[i18n][subdir] = contrib
projects[i18n][version] = 1.7

projects[menu_position][type] = module
projects[menu_position][subdir] = contrib
projects[menu_position][version] = 1.1

projects[openpublic_translation_content][type] = module
projects[openpublic_translation_content][subdir] = apps
projects[openpublic_translation_content][download][type] = get
projects[openpublic_translation_content][download][url] = http://appserver.openpublicapp.com/sites/default/files/fserver/openpublic_translation_content.tar.gz

projects[timeperiod][type] = module
projects[timeperiod][subdir] = contrib
projects[timeperiod][version] = 1.0-beta1

projects[defaultconfig][type] = module
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][version] = 1.0-alpha9

projects[file_entity][type] = module
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][url] = http://git.drupal.org/project/file_entity.git
projects[file_entity][download][revision] = 208ae95

projects[term_ref_autocomplete][type] = module
projects[term_ref_autocomplete][subdir] = contrib
projects[term_ref_autocomplete][download][type] = git
projects[term_ref_autocomplete][download][url] = http://git.drupal.org/project/term_ref_autocomplete.git
projects[term_ref_autocomplete][download][revision] = 42e10e6

projects[google_translator][type] = module
projects[google_translator][subdir] = contrib
projects[google_translator][download][type] = git
projects[google_translator][download][url] = https://bitbucket.org/phase2tech/google_translator.git
projects[google_translator][download][revision] = c3eee44361b1a636fa0ac10799d2b426949bd0e6

projects[plupload][type] = module
projects[plupload][subdir] = contrib
projects[plupload][version] = 1.3

projects[filefield_sources_plupload][type] = module
projects[filefield_sources_plupload][subdir] = contrib
projects[filefield_sources_plupload][download][type] = git
projects[filefield_sources_plupload][download][url] = http://git.drupal.org/project/filefield_sources_plupload.git
projects[filefield_sources_plupload][download][revision] = 8945a60

libraries[plupload][download][type] = get
libraries[plupload][download][url] = https://github.com/downloads/moxiecode/plupload/plupload_1_5_4.zip
libraries[plupload][destination] = libraries

projects[metatag][type] = module
projects[metatag][subdir] = contrib
projects[metatag][version] = 1.0-beta7

projects[jira_issue_collector][type] = module
projects[jira_issue_collector][subdir] = contrib
projects[jira_issue_collector][version] = 1.1

projects[hierarchical_select][type] = module
projects[hierarchical_select][subdir] = contrib
projects[hierarchical_select][download][type] = git
projects[hierarchical_select][download][url] = http://git.drupal.org/project/hierarchical_select.git
projects[hierarchical_select][download][revision] = aac15cd

projects[fontyourface][type] = module
projects[fontyourface][subdir] = contrib
projects[fontyourface][version] = 2.8

projects[apps][type] = module
projects[apps][subdir] = contrib
projects[apps][download][type] = git
projects[apps][download][url] = http://git.drupal.org/project/apps.git
projects[apps][download][revision] = b9d82b7bf5b4ebc7ba53324ce87082a84c3515cc
projects[apps][patch][1899390] = https://drupal.org/files/issues/1899390-remove-update-dep-2.patch

projects[shield][type] = module
projects[shield][subdir] = contrib
projects[shield][download][type] = git
projects[shield][download][url] = http://git.drupal.org/project/shield.git
projects[shield][download][revision] = d0d4d8ba32ac128d15c758fe29dbc022223a1270

projects[XHProf][type] = module
projects[XHProf][subdir] = contrib
projects[XHProf][version] = 1.0-beta3

projects[shs][type] = module
projects[shs][subdir] = contrib
projects[shs][version] = 1.6

projects[jreject][type] = module
projects[jreject][subdir] = contrib
projects[jreject][version] = 2.0-beta1

libraries[jreject][download][type] = git
libraries[jreject][download][url] = https://github.com/TurnWheel/jReject.git
libraries[jreject][download][revision] = 4d5f3651c0dda9b7741189d528567b8054b2fb0a
