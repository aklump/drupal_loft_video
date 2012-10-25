<?php
// $Id$

/**
 * @file
 * API documentation for loft_video module. *
 */

/**
 * Implementation of hook_loft_video
 
 * @return array
 *   An associate array with keys who are the node_types that contain video files
 *   Each key is an array of fieldnames, within that node type, that contain video files
 *   Each filename is an array with attributes: width, height
 */
function hook_loft_video() {
  return array(
    'video' => array(
      'field_video_file' => array(
        'width' => '746', //width in pixels
        'height' => '420', //width in pixels
        'type' => 'flowplayer',
      ),
    ),
  );
}