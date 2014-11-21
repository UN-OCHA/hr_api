<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermGlobalClusters.
 */

class RestfulEntityTaxonomyTermGlobalClusters extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['icon'] = array(
      'property' => 'field_image',
    );

    return $public_fields;
  }

}
