items of note 

THe following line is place in the field_base file 
   'referenceable_types' => array_map(function($i) {return $i->type;}, node_type_get_types()),

as a replace ment for the referencable_types like so that all types can be referenced.
