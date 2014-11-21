<?php
/**
 * This class is designed to create a very clean API that integrates with
 * the services and entity modules. We want to strip all "drupalisms" out
 * of the API. For example, there should be no [LANGUAGE_NONE][0][value] or
 * field_ in the API.
 *
 * It should be possible to create an API that is easily replicated on another
 * system.
 *
 * Much of this code is borrowed from restws module.
 */
class HRApiServicesEntityResourceController extends ServicesEntityResourceControllerClean {

  /**
   * Returns fields to be excluded depending on entity type and bundle
   */
  protected function get_fields_excluded($entity_type, $bundle) {
    $fields_exclude = array();
    switch($bundle) {
      case 'hr_organization':
        $fields_exclude = array('parents_all', 'parent', 'description_field', 'description', 'weight', 'feed_nid');
        break;
      case 'hr_location':
        $fields_exclude = array('geofield', 'description_field', 'description', 'weight', 'feed_nid');
        break;
      case 'hr_theme':
        $fields_exclude = array('description_field', 'description', 'weight', 'feed_nid');
        break;
    }
    return $fields_exclude;
  }

  /**
   * Return the data structure for an entity stripped of all "drupalisms" such as
   * field_ and complex data arrays.
   *
   * @param type $wrapper
   * @return type
   */
  protected function get_data($wrapper, $fields = '*') {
    $fields_exclude = array();
    if ($wrapper->type() == 'taxonomy_term') {
      $bundle = $wrapper->getBundle();
      $fields_exclude = $this->get_fields_excluded('taxonomy_term', $bundle);
    }
    if ($fields != '*') {
      $fields_array = explode(',', $fields);
    }
    $data = array();
    $filtered = $this->property_access_filter($wrapper);
    foreach ($filtered as $name => $property) {
      // We don't want 'field_' at the beginning of fields. This is a drupalism and shouldn't be in the api.
      $name = preg_replace('/^field_/', '', $name);
      // If fields is set and it isn't one of them, go to the next.
      if ($fields != '*' && !in_array($name, $fields_array) || in_array($name, $fields_exclude)) {
        continue;
      }
      try {
        if ($property instanceof EntityDrupalWrapper) {
          // For referenced entities only return the URI.
          if ($id = $property->getIdentifier()) {
            if ($name == 'organization_type') {
              $org_type = entity_load_single($property->type(), $id);
              $data[$name] = entity_label($property->type(), $org_type);
            }
            else {
              $resource = $property->type();
              if ($resource == 'taxonomy_term' && $bundle = $property->getBundle()) {
                $resource = $resource . '_'.$bundle;
              }
              $data[$name] = $this->get_resource_reference($resource, $id);
            }
          }
        }
        elseif ($property instanceof EntityValueWrapper) {
          $data[$name] = $property->value();
        }
        elseif ($property instanceof EntityListWrapper || $property instanceof EntityStructureWrapper) {
          $data[$name] = $this->get_data($property);
        }
      }
      catch (EntityMetadataWrapperException $e) {
        // A property causes problems - ignore that.
      }
    }
    // If bundle = entity_type, don't send it.
    if (method_exists($wrapper, 'entityInfo')) {
      $entity_info = $wrapper->entityInfo();
      if (isset($entity_info['bundle keys'])) {
        foreach ($entity_info['bundle keys'] as $bundle_key) {
          if (array_key_exists($bundle_key, $data) && $data[$bundle_key] == $wrapper->type()) {
            unset($data[$bundle_key]);
          }
        }
      }
    }
    return $data;
  }

  /**
   * Return a resource reference array.
   *
   * @param type $resource
   * @param type $id
   * @return type
   */
  protected function get_resource_reference($resource, $id) {
    $return = array(
      'uri' => services_resource_uri(array('entity_' . $resource, $id)),
      'id' => $id,
    );
    if (module_exists('uuid') && entity_get_info($resource)) {
      $ids = entity_get_uuid_by_id($resource, array($id));
      if ($id = reset($ids)) {
        $return['uuid'] = $id;
      }
    }
    return $return;
  }


}
   
