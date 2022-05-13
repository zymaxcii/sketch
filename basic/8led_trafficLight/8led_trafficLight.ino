// 8led_trafficLight.ino
// too many blocking delay()

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
#define redLight 6
#define yellowLight 7
#define greenLight 8


void setup()
{
  pinMode (redLight, OUTPUT);
  pinMode (yellowLight, OUTPUT);
  pinMode (greenLight, OUTPUT);
}


void loop()
{
  digitalWrite (redLight, 1);
  delay(9000);
  digitalWrite (redLight, 0);        // stopped  

  digitalWrite (yellowLight, 1); 
  delay (3000);                    // yellow light for 3 sec
  digitalWrite (yellowLight, 0);

  digitalWrite (greenLight, 1);
  delay (9000);
  digitalWrite (greenLight, 0);      // greenLight start flashing
  delay (500);
  digitalWrite (greenLight, 1);
  delay (500);    
  digitalWrite (greenLight, 0);
  delay (500);
  digitalWrite (greenLight, 1);
  delay (500);
  digitalWrite (greenLight, 0);
  delay (500);
  digitalWrite (greenLight, 1);
  delay (500);
  digitalWrite (greenLight, 0);
  delay (500);
  digitalWrite (greenLight, 1);
  delay (500);
  digitalWrite (greenLight, 0);
}
