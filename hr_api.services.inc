<?php
/**
 * @file
 * hr_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function hr_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'hr_api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1';
  $endpoint->authentication = array();
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'entity_taxonomy_term_hr_organization' => array(
      'alias' => 'organizations',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'entity_taxonomy_term_hr_theme' => array(
      'alias' => 'themes',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'entity_taxonomy_term_hr_location' => array(
      'alias' => 'locations',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['hr_api'] = $endpoint;

  return $export;
}
