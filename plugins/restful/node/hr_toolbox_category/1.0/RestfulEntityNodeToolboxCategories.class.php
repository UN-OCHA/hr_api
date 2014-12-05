<?php

/**
 * @file
 * Contains \RestfulEntityNodeToolboxCategories.
 */

class RestfulEntityNodeToolboxCategories extends \RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['cat_type'] = array(
      'property' => 'field_toolbox_cat_type',
    );

    return $public_fields;
  }

}
