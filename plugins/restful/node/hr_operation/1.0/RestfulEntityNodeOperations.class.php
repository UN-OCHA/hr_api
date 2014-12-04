<?php

/**
 * @file
 * Contains \RestfulEntityNodeOperations.
 */

class RestfulEntityNodeOperations extends \RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBase::getQueryForList().
   *
   * Avoid access check which is causing an issue
   * IMPORTANT: MUST BE FIXED BEFORE GOING IN PRODUCTION
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    $query->addMetaData('account', user_load(1));
    return $query;
  }


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

    $public_fields['status'] = array(
      'property' => 'field_operation_status',
    );

    $public_fields['country'] = array(
      'property' => 'field_country',
      'resource' => array(
        'hr_location' => 'locations',
      ),
    );

    $public_fields['launch_date'] = array(
      'property' => 'field_launch_date',
    );

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

}
