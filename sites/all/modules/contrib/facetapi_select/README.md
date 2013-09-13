FacetAPI select
===============

This module provides a facetapi widget to display a facet as a single-valued
select box. It defaults to hiding the form submit button and submitting
automatically but this can be turned off and degrades without javascript.

It was originally a patch to [Jody Lynn's sandbox of the same
name](http://drupal.org/sandbox/lynn/1311040) but it turned into more of a
rewrite so a seperate repo was helpful. The behaviour is different as
described in [#1412442].

I also just noticed a new module [FacetAPI
multiselect](http://drupal.org/project/facetapi_multiselect) that also falls
in this realm.

Usage
=====

This module relies on a patch to the FacetAPI module ([#1393928]) which
enables sane behaviour for a single-valued checkbox.

After applying that patch, select this widget for your given facet. In the
global settings on the "Configure facet display" page set your operator to
"OR" and check the box labelled "Limit to one active item".
