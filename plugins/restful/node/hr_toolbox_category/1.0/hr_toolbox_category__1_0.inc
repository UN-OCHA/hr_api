<?php

$plugin = array(
  'label' => t('Toolbox categories'),
  'resource' => 'toolbox_categories',
  'name' => 'hr_toolbox_category__1_0',
  'entity_type' => 'node',
  'bundle' => 'hr_toolbox_category',
  'description' => t('Export the toolbox categories.'),
  'class' => 'RestfulEntityNodeToolboxCategories',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'allow_origin' => '*',
);
