<?php
/**
 * @file
 * opensanmateo_location.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function opensanmateo_location_taxonomy_default_vocabularies() {
  return array(
    'location_type' => array(
      'name' => 'Location Type',
      'machine_name' => 'location_type',
      'description' => 'Used for categorizing the location.',
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
