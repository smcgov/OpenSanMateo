
-- SUMMARY --

jReject:
Often times, either through lack of manpower or will, we'll create a web page 
that looks great in modern browsers but falls apart in old ones. Rather than 
fielding comments like "Your page is broken!!", wouldn't it be nice to let your 
visitors know that their browser is out of date?

jReject is a jQuery plugin that determines the browser type and version a 
visitor is using, and conditionally presents the user with a modal message 
prompting them to upgrade their browser.

The jReject jQuery plugin was created by Steven Bower (http://turnwheel.com), 
and based on the "IE6 Upgrade Warning" script by mihai.ile@gmail.com. It is 
released under a dual MIT/GPL license. The jReject for Drupal 7 module was 
created by Domenic Santangelo (entendu) http://drupal.org/user/173461.

jReject for Drupal 7:
jReject for Drupal 7 is a module that lets you plug-and-play jReject with a 
minimum amount of effort. It includes a comprehensive set of administrative 
screens that enables you to tweak jReject's many options without touching a 
single line of code.

For a full description of the module, visit the project page:
  http://drupal.org/project/jreject

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/jreject


-- REQUIREMENTS --

Libraries module 2.x


-- INSTALLATION --

* First, install the jReject for Drupal 7 module in Drupal. The module comes 
with a sensible set of default settings.

* Get the jReject plugin from http://github.com/TurnWheel/jReject. Install it
in your Libraries directory in a directory called `jreject`. Example:
/sites/all/libraries/jreject/(all the jreject files and dirs here)

If you have drush, you can attempt to auto-install the jReject library by using
the `jrdl` command. Example: drush -l mysite.com jrdl

This module will automatically check to see if you've done this step correctly. 
Simply visit any of this module's configuration pages and look for a warning.


-- CONFIGURATION --

* Customize the module's behavior by visiting /admin/config/system/jreject. At 
minimum, you must check the "Enable jReject" box.


-- CUSTOMIZATION --

To be written


-- TROUBLESHOOTING --

To be written

-- FAQ --

To be written


-- CONTACT --

Current maintainers:
* Domenic Santangelo (entendu) - http://drupal.org/user/173461


This project has been sponsored by:
* Development of jReject for Drupal 7 sponsored by X.com.

-- CREDITS --
* jReject by Steven Bower
  https://github.com/TurnWheel/jReject
  http://jreject.turnwheel.com/