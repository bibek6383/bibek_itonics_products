<?php


/**
 * Implements hook_schema().
 */
function bibek_itonics_products_schema()
{
  $schema = [];

  $schema['bibek_itonics_products'] = [
    'description' => 'Table for storing information about products in ITONICS.',
    'fields' => [
      'id' => [
        'description' => 'The primary identifier for a product.',
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ],
      'title' => [
        'description' => 'The title of the product.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ],
      'image' => [
        'description' => 'The image of the product.',
        'type' => 'varchar',
        'length' => 255,
      ],
      'summary' => [
        'description' => 'The summary of the product.',
        'type' => 'text',
      ],
      'description' => [
        'description' => 'The description of the product.',
        'type' => 'text',
      ],
      'type' => [
        'description' => 'The type of the product.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ],
      'owner_email' => [
        'description' => 'The owner\'s email of the product.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ],
      'expiry_date' => [
        'description' => 'The expiry date of the product.',
        'type' => 'date',
        'mysql_type' => 'date',
        'not null' => TRUE,
      ]
    ],
    'primary key' => ['id'],
  ];

  $schema['bibek_itonics_product_categories'] = [
    'description' => 'Table for associating products with categories in ITONICS.',
    'fields' => [
      'product_id' => [
        'description' => 'The ID of the product.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ],
      'category_id' => [
        'description' => 'The ID of the category.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ],
    ],
    'primary key' => ['product_id', 'category_id'],
    'indexes' => [
      'product_id' => ['product_id'],
      'category_id' => ['category_id'],
    ],
    'foreign keys' => [
      'fk_product' => [
        'table' => 'bibek_itonics_products',
        'columns' => ['product_id' => 'id'],
        'on delete' => 'CASCADE',
        'on update' => 'CASCADE',
      ],
      'fk_category' => [
        'table' => 'bibek_itonics_categories',
        'columns' => ['category_id' => 'id'],
        'on delete' => 'CASCADE',
        'on update' => 'CASCADE',
      ],
    ],
  ];
  return $schema;
}

/**
 * Implements hook_install().
 */
function bibek_itonics_products_install() {
  drupal_install_schema('bibek_itonics_products');
}

/**
 * Implements hook_uninstall().
 */
function bibek_itonics_products_uninstall() {
  drupal_uninstall_schema('bibek_itonics_products');
}
