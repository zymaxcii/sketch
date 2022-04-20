// 8led_pwm.ino
// https://forum.arduino.cc/t/pwm-for-8-leds-with-arduino-nano/340325/8
// PWM for 8 LEDs with Arduino Nano

// all leds must be connected with common anode
// so my "normal" 8led with common cathode won't work
const int cathode[8] = {5,6,7,8,9,10,11,12};
const int anode = 3;    // pwm pin


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
    
    for (int k=0; k<5; k++)
    {
      for (int j=0; j<256; j++)
      {
        analogWrite(anode, j);
        delay(10);
      }
      
      for (int j=255; j>=0; j--)
      {
        analogWrite(anode, j);
        delay(10);
      }
    }
    digitalWrite(cathode[i], HIGH);
  }
}
