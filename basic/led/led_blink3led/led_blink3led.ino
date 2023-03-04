// led_blink3led.ino
// can also use one RGB led
// status: compile , upload 


// https://tronixstuff.com/

/*
  blinky LED test
*/


int red   = 2;
int green = 3;
int blue  = 4;
int d = 300;


void setup()
{
  pinMode(red,   OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue,  OUTPUT);
}


void loop()
{
  digitalWrite(red, HIGH);
  delay(d);
  digitalWrite(red, LOW);
  delay(d);
  
  digitalWrite(green, HIGH);
  delay(d);
  digitalWrite(green, LOW);
  delay(d);
  
  digitalWrite(blue, HIGH);
  delay(d);
  digitalWrite(blue, LOW);
  delay(d);
}
