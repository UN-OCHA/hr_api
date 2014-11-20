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
  $strongarm->name = 'services_entity_max_pagesize';
  $strongarm->value = '100';
  $export['services_entity_max_pagesize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'services_entity_resource_class';
  $strongarm->value = 'HRApiServicesEntityResourceController';
  $export['services_entity_resource_class'] = $strongarm;

  return $export;
}
