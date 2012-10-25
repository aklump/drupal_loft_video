<?php
// $Id$

/**
 * @file
 * API documentation for loft_video module.
 */

/**
 * Implementation of hook_loft_video

 * @return array
 *   An associate array with keys who are the node_types that contain video files
 *   Each key is an array of fieldnames, within that node type, that contain video files
 *   Here are the keys within each fieldname
 *
 *   It is advised to apply height and width using external stylesheets, however
     you may apply height and width here which is rendered in the style
     attribute.
 *
 *   - width: int (optional. Will be applied as a style attribute and will override anything else)
 *   - height: int (optional. Will be applied as a style attribute and will override anything else)
 *   - type: currently only 'flowplayer'
 *   - autoplay: bool; defaults to TRUE
 *   - content_render: should the rendered value of the field be replaced with the
     embed code in hook_preprocess_node in $vars['content']?
     - config: This will be player dependent and allows you send player
       configuration options to the player
       - flowplayer config: //@see http://flowplayer.org/documentation/configuration/
 */
function hook_loft_video() {
  return array(
    'video' => array(
      'field_video_file' => array(
        'type' => 'flowplayer_ipad',
        'autoplay' => FALSE,
        'content_render' => TRUE,
        //'width' => '400', //width in pixels
        //'height' => '300', //width in pixels
        //'config' => array(
        //  'clip' => array(
        //    'autoPlay' => FALSE,
        //  ),
        //),
      ),
    ),
  );
}

/**
 * Implements hook_loft_video_player_source_alter().
 *
 * Allows modules to alter the source directory of a player by type
 *
 * @param string $path
 *   The path as determined by type
 * @param string $type
 *   The type of video player
 *
 * @return NULL
 */
function hook_loft_video_player_source_alter(&$path, $type) {
  if ($type = 'my_custom_player') {
    $path = 'sites/all/libraries/my_custom_player';
  }
}

/**
 * Implements hook_loft_video_player_version_alter().
 *
 * Allows modules to alter the player version by type
 *
 * @param string $version
 *   The version as determined by type
 * @param string $type
 *   The type of video player
 *
 * @return NULL
 */
function hook_loft_video_player_version_alter(&$version, $type) {
  if ($type = 'my_custom_player') {
    $version = '1.0';
  }
}

/**
 * Alter the output of theme_loft_video_player
 *
 * @param string $output
 *   The html markup coming out of the theme function
 * @param array $vars
 *   The $vars array coming out of the function
 * @param array $original_vars
 *   The $vars array going in to the function
 *
 * @return NULL
 */
function hook_loft_video_player_alter(&$output, $vars, $original_vars) {

}

/**
 *
 * Implements hook_loft_video_file_urls_alter().
 *
 * Allow modules to alter the video file urls for a node
 *
 * @param array $video_urls
 * @param object $node
 *
 * @return NULL
 */
function hook_loft_video_file_urls_alter(&$video_urls, $node) {

}
