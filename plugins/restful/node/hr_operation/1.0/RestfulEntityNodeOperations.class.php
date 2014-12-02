<?php

/**
 * @file
 * Contains \RestfulEntityNodeOperations.
 */

class RestfulEntityNodeOperations extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['type'] = array(
      'property' => 'field_operation_type',
    );

    return $public_fields;
  }

}
