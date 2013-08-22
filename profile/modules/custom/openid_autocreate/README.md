This module intercepts the registartion process when one use an openid.  If some one is coming from a domain that is accept they will have a user crate for them automaticly.

Setting the variable openid_autocreate_regex_NAMEOFROLE to an array of regex that will be run on any openid.  If the regex match then the user will be given that role
