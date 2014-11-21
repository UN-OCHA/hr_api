<?php
/**
 * @file
 * hr_api.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_api_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'restful_enable_users_resource';
  $strongarm->value = '0';
  $export['restful_enable_users_resource'] = $strongarm;

  return $export;
}
