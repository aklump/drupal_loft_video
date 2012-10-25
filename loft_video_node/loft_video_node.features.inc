<?php
/**
 * @file
 * loft_video_node.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loft_video_node_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function loft_video_node_node_info() {
  $items = array(
    'loft_video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Add a video.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
