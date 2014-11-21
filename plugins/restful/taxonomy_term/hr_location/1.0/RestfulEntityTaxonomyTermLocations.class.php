<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermLocations.
 */

class RestfulEntityTaxonomyTermLocations extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['pcode'] = array(
      'property' => 'field_pcode',
    );

    $public_fiels['geolocation'] = array(
      'property' => 'field_geofield',
    );

    return $public_fields;
  }

}
