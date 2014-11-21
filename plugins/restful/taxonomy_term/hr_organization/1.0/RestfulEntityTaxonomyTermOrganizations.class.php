<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermOrganizations.
 */

class RestfulEntityTaxonomyTermOrganizations extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
      'sub_property' => 'value',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    return $public_fields;
  }

}
