// 8led_trafficLight.ino
// too many blocking delay()

#define redLight 5
#define yellowLight 6
#define greenLight 7


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
