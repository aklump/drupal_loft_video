<?php
// $Id$

/**
 * @file
 * Extra page related functions
 *
 * @ingroup loft_video
 * @{
 */

 /**
 * Formats the video player
 *
 * Note that this function can be extended in at least three ways:
 * - theme_loft_video_player_alter() at the module level
 * - hook_theme_registry_alter() at the module level
 * - Theme override at the theme level
 *
 * @param $vars
 * Required keys are:
 * - url: url to the source media
 * - type: currently: "flowplayer", "flowplayer_ipad"
 * Optional keys are:
 * - attributes ()
 * - flashvars; see http://flowplayer.org/documentation/configuration/player.html#embedding
 * - config: see http://flowplayer.org/documentation/configuration/
 *
 * @return string
 *
 * @ingroup themeable
 */
function theme_loft_video_player($vars) {
  $original_vars = $vars;

  // Determine if we are to use the flowplayer ipad plugin or not
  //$vars['type'] = $vars['type'];
  //$flowplayer_ipad = FALSE;
  //if ($vars['type'] == 'flowplayer_ipad') {
  //  $flowplayer_ipad = TRUE;
  //  $vars['type'] = 'flowplayer';
  //}

  // Locate the flowplayer assets and version
  if (!($player_dir = loft_video_player_source($vars['type']))) {
    watchdog('loft_video', 'Unable to locate %type assets', array('%type' => $vars['type'],), WATCHDOG_ERROR);
    return FALSE;
  }
  if (!($version = loft_video_player_version($vars['type']))) {
    watchdog('loft_video', 'Unable to determine the %type version', array('%type' => $version,), WATCHDOG_ERROR);
    return FALSE;
  }

  // Add the necessary css
  drupal_add_css(drupal_get_path('module', 'loft_video') .'/loft_video.css');

  // This sets the class of the wrapper
  if (empty($vars['attributes']['class'])) {
    $vars['attributes']['class'] = '';
  }
  if (!strstr($vars['attributes']['class'], 'loft-video-video')) {
    $vars['attributes']['class'] .= ' loft-video-video';
    $vars['attributes']['class'] = trim($vars['attributes']['class']);
  }

  // Creates a static class if needed
  static $video_index = 1;
  $vars['attributes']['id'] = isset($vars['attributes']['id'])
    ? $vars['attributes']['id']
    : 'loft-video-' . $video_index++;

  $output = '';

  switch ($vars['type']) {
    case 'flowplayer':
    case 'flowplayer_ipad':
      if (empty($vars['attributes']['style'])) {
        $vars['attributes']['style'] = '';
      }
      if (!strstr($vars['attributes']['style'], 'block')) {
        $vars['attributes']['style'] .= ' display: block;';
        $vars['attributes']['style'] = trim($vars['attributes']['style']);
      }

      $attributes = array(
        'id'    => $vars['attributes']['id'],
        'class' => $vars['attributes']['class'] . ' flowplayer',
        'style' => $vars['attributes']['style'],
      );

      if ($vars['type'] == 'flowplayer_ipad') {
        $attributes['class'] .= ' flowplayer-ipad';
      }

      $output .= '<a href="' . $vars['url'] . '" ' . drupal_attributes($attributes) . '></a>' . "\n";

      $flashvars = array(
        'src' => base_path() . $player_dir . "/flowplayer-$version.swf",
      );

      //allow the users to add in some vars
      if (!empty($vars['flashvars'])) {
        $flashvars += (array) $vars['flashvars'];
      }

      // Add this post user in case they want to set it different, we don't want
      // to override
      $flashvars += array(
        'wmode' => 'transparent',
      );

      // Add in optional user config vars
      $config = array();
      if (!empty($vars['config'])) {
        $config += (array) $vars['config'];
      }

      // Add the flowplayer js
      drupal_add_js($player_dir . '/flowplayer-' . $version . '.min.js');
      $js = '';
      $js .= "$('document').ready(function(){\n";
      if ($vars['type'] == 'flowplayer_ipad') {

        // http://flowplayer.org/plugins/javascript/ipad.html
        drupal_add_js('sites/all/libraries/flowplayer_plugins/ipad.js');
        $js .= '  $f("' . $attributes['id'] . '", ' . drupal_to_js($flashvars) . ', ' .   drupal_to_js($config) . ').ipad();' . "\n";
      }
      else {
        $js .= '  $f("' . $attributes['id'] . '", ' . drupal_to_js($flashvars) . ', ' .   drupal_to_js($config) . ');' . "\n";
      }
      $js .= '});' . "\n";
      drupal_add_js($js, 'inline');
      break;
  }

  // Allow modules to easily extend this without having to rewrite the entire
  // theme function, say if they want to provide their own video type/theme with
  // the least amount of code. The alternative to this is to use
  // hook_theme_registry_alter at the module level, or to simply to a theme
  // override at the theme level.  Three ways to override this function
  drupal_alter('loft_video_player', $output, $vars, $original_vars);
  return $output;
}

/**
 * Return the path to a video player's root directory
 *
 * @param string $type
 *   E.g. flowplayer
 *
 * @return string
 *   e.g. 3.2.8
 */
function loft_video_player_source($type) {
  $path = FALSE;

  // Set up where to look
  switch ($type) {
    case 'flowplayer':
    case 'flowplayer_ipad':
      $dirs = array(
        'sites/all/libraries/flowplayer',
        drupal_get_path('module', 'loft_video') . '/flowplayer',
      );
      break;
  }

  // Find the first dir containing the assets
  foreach ($dirs as $dir) {
    if (is_dir($dir)) {
      $path = $dir;
      break;
    }
  }
  drupal_alter('loft_video_player_source', $path, $type);
  return $path;
}
/**
 * Return the version of a video player type
 *
 * @param string $type
 *   E.g. flowplayer
 *
 * @return string
 *   e.g. 3.2.8
 */
function loft_video_player_version($type) {
  $version = FALSE;
  if ($dir = loft_video_player_source($type)) {
    switch ($type) {
      case 'flowplayer':
      case 'flowplayer_ipad':
      default:
        $regex = '([0-9][0-9\.]+)';
        $files = file_scan_directory($dir, $regex, NULL, NULL, FALSE, 'basename');
        preg_match('/' . $regex . '/', key($files), $found);
        $version = trim($found[1], '.');
        break;
    }
  }
  drupal_alter('loft_video_player_version', $version, $type);
  return $version;
}

/** @} */ //end of grouploft_video loft_video
