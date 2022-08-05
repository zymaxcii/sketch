# WTV020SD16P
Arduino library for the WTV020-SD-16P sound module

**WTV020SD16P.cpp Version 1.3**

Library to control a WTV020-SD-16P module to play voices from an Arduino board.
Created by Diego J. Arevalo, August 6th, 2012.
Modifed by Ryszard Malinowski November 30, 2014.
Modifed by Dan F  March 2015
Modified by Thomas A. Hirsch, October 28, 2019.
  
 Released into the public domain.
 
 **Changes:**
 - V1.0 - Original library written by Diego J. Arevalo
 - V1.1 - Changes by Ryszard Malinowski:
>Add "delayMicros" function execute exact delay from the last call
>Fix clock timing in "setCommand" function
>Add "setVolume" function
>Fix "unmute" function to restore original volume
>Padawan - Removed reset

 - v1.2 - Changes by r0n_dL
>Renamed .cpp & .h to WTV020SD16P
>Published to GitHub

 - v1.3 - Changes by thirsch
>Added method reset() again.

 - v1.4 - Changes by thirsch
>Using `delayMicros()` instead of `delay` to avoid crashes on Arudino Pro Mini. (#1)