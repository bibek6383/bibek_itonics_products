<?php


/**
 * Implements hook_schema().
 */
function bibek_itonics_categories_schema()
{
  $schema = array();

  $schema['bibek_itonics_categories'] = array(
    'description' => 'Table to store product categories.',
    'fields' => array(
      'id' => array(
        'description' => 'Primary Key: Unique category ID.',
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'name' => array(
        'description' => 'Category name.',
        'type' => 'varchar',
        'length' => 150,
        'not null' => TRUE,
      ),
    ),
    'primary key' => array('id'),
  );

  return $schema;
}

/**
 * Implements hook_install().
 */
function bibek_itonics_categories_install()
{
  drupal_install_schema('bibek_itonics_categories');
}

/**
 * Implements hook_uninstall().
 */
function bibek_itonics_categories_uninstall()
{
  drupal_uninstall_schema('bibek_itonics_categories');
}
