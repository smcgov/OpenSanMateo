XRDS Simple Module for Drupal
=============================

XRDS Simple can be used to provide an XRDS document in Drupal.
It originally implemented the XRDS Simple specification,
which used to be found at:  http://xrds-simple.net/core/1.0/.

That site is gone now, along with the specification.

An XRDS Document in Drupal is used in the OpenID discovery process,
both for operating an OpenID 2.0 provider, and eleveted security
OpenID logins such as the ICAM OpenID Profile.

This module has no user interface.  You either need it as
a dependency of another module (like openid_provider or openid_icam)
or you have to use the API function, hook_xrds().  

See xrds_simple.api.php for an example of using the API.

XRDS Simple is a relatively small module, so if you are more 
curious about how it works, inspect the code in xrds_simple.module.
 