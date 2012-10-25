/* $Id$ */

SUMMARY: This module is an api and must be used by another module or theme to be
effective.


REQUIREMENTS:


INSTALLATION:
- Download and unzip this module into your modules directory.
- Goto Administer > Site Building > Modules and enable this module.


CONFIGURATION:
- 


USAGE:
- You may either use theme('loft_video_player') if you just want to theme a path
  to a video file; or you may use hook_loft_video() to provide information about
  nodes and fields that contain video files.
- If you utilize the latter, your embed code will be available in node.tpl.php
  as a variable called {$fieldname}_embed.

--------------------------------------------------------
CONTACT:
In the Loft Studios
Aaron Klump - Web Developer
PO Box 29294 Bellingham, WA 98228-1294
aim: theloft101
skype: intheloftstudios

http://www.InTheLoftStudios.com
