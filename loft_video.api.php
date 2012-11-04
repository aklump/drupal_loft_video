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
 *   Properties of each array are:
 *   - #auto_content: set to True and the field will be rendered as a video,
     overriding the current display handler
 *   Each key is an array of fieldnames, within that node type, that contain video files
 *   Each filename is an array with attributes: width, height
 */
function hook_loft_video() {
  return array(
    'video' => array(
      '#auto_content' => TRUE,
      'field_video_file' => array(
        'width' => '746', //width in pixels
        'height' => '420', //width in pixels
        'type' => 'flowplayer',
      ),
    ),
  );
}
