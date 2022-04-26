// 8led_pwm.ino
// https://forum.arduino.cc/t/pwm-for-8-leds-with-arduino-nano/340325/8
// PWM for 8 LEDs with Arduino Nano

// all leds must be connected with common anode
// so my "normal" 8led with common cathode won't work
// need to modify my 8led for this code to run:
// 1. disconnect common gnd
// 2. hook it to pin D3 which is pwm
// 3. reverse polarity of all 8 leds - common anode
// 4. test this code it should work
// 5. to revert for normal use, disconnect D3, reconnect to GND
// 6. reverse all led polarity - common cathode

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
const int cathode[8] = {6,7,8,9, 10,11,12,13};      // my std 8 led pins
const int anode = 3;    // pwm pin
int delayTime = 10;


void setup()
{
  pinMode(anode, OUTPUT);
  
  for (int i=0; i<8; i++)
  {
    pinMode(cathode[i], OUTPUT);
    digitalWrite(cathode[i], HIGH);
  }
}


void loop()
{
  for (int i=0; i<8; i++)
  {
    digitalWrite(cathode[i], LOW);
    
    // repeat 2 times each
    for (int k=0; k<2; k++)
    {
      for (int j=0; j<256; j++)
      {
        analogWrite(anode, j);    // fade up
        delay(delayTime);
      }
      
      for (int j=255; j>=0; j--)
      {
        analogWrite(anode, j);    // fade down
        delay(delayTime);
      }
    }
    digitalWrite(cathode[i], HIGH);
  }
}
