<?php
/**
 * @file
 * opensanmateo_govdelivery.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function opensanmateo_govdelivery_taxonomy_default_vocabularies() {
  return array(
    'govdelivery_topics' => array(
      'name' => 'GovDelivery Topics',
      'machine_name' => 'govdelivery_topics',
      'description' => '',
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
