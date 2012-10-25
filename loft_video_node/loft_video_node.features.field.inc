<?php
/**
 * @file
 * loft_video_node.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function loft_video_node_field_default_fields() {
  $fields = array();

  // Exported field: 'node-loft_video-field_video_file'
  $fields['node-loft_video-field_video_file'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_video_file',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '1',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'loft_video',
      'deleted' => '0',
      'description' => 'Locate the file on your harddrive and upload.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_video_file',
      'label' => 'Video File',
      'required' => 1,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'videos',
        'file_extensions' => 'mov flv',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Locate the file on your harddrive and upload.');
  t('Video File');

  return $fields;
}
