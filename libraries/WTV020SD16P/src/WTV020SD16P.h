/*
 WTV020SD16P.h - Library to control a WTV020-SD-16P module to play voices from an Arduino board.
 Created by Diego J. Arevalo, August 6th, 2012.
 Released into the public domain.
 
  v1.2 - Renamed .cpp & .h to WTV020SD16P
  v1.3 - Added reset again
  v1.4 - Fixed crashes on Arduino Pro Mini
 */

#ifndef WTV020SD16P_h
#define WTV020SD16P_h

class WTV020SD16P
{
public:
  WTV020SD16P(int resetPin, int clockPin,int dataPin,int busyPin);
  
  void playVoice(unsigned int voiceNumber);
  void asyncPlayVoice(unsigned int voiceNumber);
  void stopVoice();
  void pauseVoice();
  void mute();
  void unmute();
  void setVolume(unsigned int volume);
  void reset();

private:
  void sendCommand(unsigned int command);
  void delayMicros(unsigned long delayMicros);
  
  int _resetPin;
  int _clockPin;
  int _dataPin;
  int _busyPin;
  int _busyPinState;
  unsigned int _currentVolume;
  unsigned long _lastMicros;
};

#endif