// pulsein.ino
// https://nerdytechy.com/arduino-pulsein-guide/

int pin = 7; //output port number
unsigned long duration; //signal timeout

void setup()
{
  pinMode(pin, INPUT);
}


void loop()
{
  duration = pulseIn(pin, HIGH);
}

