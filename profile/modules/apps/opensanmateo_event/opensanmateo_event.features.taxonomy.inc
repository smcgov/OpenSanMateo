<?php
/**
 * @file
 * opensanmateo_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function opensanmateo_event_taxonomy_default_vocabularies() {
  return array(
    'calendars' => array(
      'name' => 'Calendars',
      'machine_name' => 'calendars',
      'description' => 'Used for organizing events into calendars.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
