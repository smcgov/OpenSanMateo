Search API Multi Aggregate module for Drupal 7


Description
-----------
This module provides a data alteration callback very similar to
'Aggregate Fields', but instead of reducing fields values into a single value,
it keeps fields values "as is" so they are indexed into multi-valued indexes.


Required modules
----------------
- Search API


Why you need it
---------------
This module is useful when you want to aggregate fields and index the new field as string (for faceting for example).
Example

You have 2 fields:

- Primary authors which contains the following values
  - "Primary 1"
  - "Primary 2"
- Secondary authors which contains the following values
  - "Secondary 1"
  - "Secondary 2"

and you want them both to be used in one single Facet block.
You have to create a new field that will contains values of both these fields.
You can use the 'Aggregate Fields' that comes with Search API module for that. But there is a small inconvenient:

- If you index the new field as "Fulltext", your facets will looks like
  - "Primary"
  - "Secondary"
  - "1"
  - "2"
- If you index the new field as "String", you will get only one facet:
  - "Primary 1 Primary 2 Secondary 1 Secondary 2"

Using Search API Multi Aggregate will allow you to have the facets you want:

- "Primary 1"
- "Primary 2"
- "Secondary 1"
- "Secondary 2"


How to use
----------
1. Install and enable the module
2. Go to your Search API Index configuration, under Workflow tab
3. You should see a new type of data alteration: "Aggregated fields (multi-valued)". Enable it
4. Under "callback settings", click on "Add new field" and configure it (fill its name and choose the fields to aggregate)
5. You should now see a new field in the fields list. Check it and choose "String" type
6. Re-index
