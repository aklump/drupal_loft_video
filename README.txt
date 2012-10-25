/* $Id$ */

SUMMARY: This module is an api and must be used by another module or theme to be
effective.


REQUIREMENTS:


INSTALLATION:
- Download and unzip this module into your modules directory.
- Goto Administer > Site Building > Modules and enable this module.
- Go to http://flowplayer.org/download/ and download into
  /sites/all/libraries/flowplayer/

- Consider downloading the flowplayer.ipad plugin from:
  http://flowplayer.org/plugins/javascript/ipad.html.
- Download and rename to:
  /sites/all/libraries/flowplayer_ipad/flowplayer.ipad.js


CONFIGURATION:
- You can install the getid3 module and it will work with this module and
  provide duration information
- If you want duration information avabilable in your node tpl then you should
  enable filefield_meta and http://drupal.org/project/getid3 modules


SUPPORTED PLAYER TYPES:
- flowplayer: standard flowplayer; last tested on version 3.2.8
- flowplayer_ipad: includes the flowplayer ipad plugin found here:
  http://flowplayer.org/plugins/javascript/ipad.html


VIDEO ENCODING
- (excerpt from http://flowplayer.org/plugins/javascript/ipad.html)
- As iOS does not support Flash, videos in Flash format - FLV, F4V etc. - cannot
  be played on iDevices.
- Videos deployed on iDevices must be encoded in the MPEG4 Part 10 format using
  the h.264 video codec. Within the MPEG4 specs make sure that your videos meet
  the constraints of the devices of your target audience. Older and small
  (iPhone, iPod) iDevices allow only lower h.264 profiles and levels because
  higher levels and profiles are expensive to decode. To achieve maximum
  backwards compatibility with early iPhones and iPods you must use the
  Constrained Baseline Profile (CBP) at maximum Level 3.0, and the video's
  dimensions must not exceed 640x480 pixels. Moreover, you should not permit
  more than 2 reference frames to avoid the risk of square artifacts during
  playback.


USAGE:
- You may either use theme('loft_video_player') if you just want to theme a path
  to a video file; or you may use hook_loft_video() to provide information about
  nodes and fields that contain video files.
- If you utilize the latter, your embed code will be available in node.tpl.php
  as a variable called {$fieldname}_embed.


EXAMPLE USAGE:
- Add a filefield to a node type OR create a video node type (@see
  sample_code/video_type.cck.php)
- Register that field from within a custom module using hook_loft_video()
- You will have access to ta variable called {$fieldname}_embed to be used in
  your node tpl for placement of the video.
- You can also include it in the #content var; @see loft_video.api.php


VIEWS:
- A view is provided which lists all videos so you can easily test them on iOs
  devices. View is located here: /admin/content/loft-video/list and is limited
  to permissions: administer content
--------------------------------------------------------
CONTACT:
In the Loft Studios
Aaron Klump - Web Developer
PO Box 29294 Bellingham, WA 98228-1294
aim: theloft101
skype: intheloftstudios

http://www.InTheLoftStudios.com
