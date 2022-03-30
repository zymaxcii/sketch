// test_4ch_relay.ino
// Use a 4-channel relay module to turn on 4 leds
// leds connected to relays' NO terminals
// when it closes it switches on 5V
// the 4 inputs IN1, IN2, IN3, IN4 are active low

int ch=4;                // number of relays
int relay[] = {2,3,4,5}; // pin number of relays

int wait = 2000;         // 2 secs
int i=0;


void setup()
{
  for (int i=0; i<ch; i++)
  {
    pinMode(relay[i], OUTPUT);      // set relay pins as output
    digitalWrite(relay[i], HIGH);   // turn relay off
  }
}


void loop()
{
  for (int i=0; i<ch; i++)
  {
    digitalWrite(relay[i], LOW);    // turn relay ON
    delay(wait);
  }
  
  for (int i=0; i<ch; i++)
  {
    digitalWrite(relay[i], HIGH);   // turn relay OFF
    delay(3000);
  }
}
