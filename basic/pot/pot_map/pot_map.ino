// pot_map.ino
// https://arduino.stackexchange.com/questions/26357/change-max-and-min-read-value-of-potentiometer
// maps pot value to 100%

int pMin = 14;        // lowest value that comes out of pot
int pMax = 948;       // highest value that comes out of pot

int x = 0;            // use this value to store readings of pot


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  x = analogRead(A0);               // connect pot to A0 pin
  Serial.print(x);                  // original reading
  
  x = map(x, pMin, pMax, 0, 100);    // translate value to scale of 0 to 100
  
  Serial.print("\t");
  Serial.println(x);
  delay(100);
}
