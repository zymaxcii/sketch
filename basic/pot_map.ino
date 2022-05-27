// pot_map.ino
// https://arduino.stackexchange.com/questions/26357/change-max-and-min-read-value-of-potentiometer


int pMin = 14;  //the lowest value that comes out of the potentiometer
int pMax = 948; //the highest value that comes out of the potentiometer.

int x = 0;  //we will use this value to store the readings of the potentiometer

void setup()
{
  Serial.begin(9600); //Serial monitor can be used to check the values
}


void loop()
{
  x = analogRead(A0); //connect the potentiometer to the A0 pin of the Arduino
  Serial.print(x);  //prints the original reading
  x = map(x, pMin, pMax, 0, 100) //take the value of x, compared it to the scale of the potentiometer pMin to pMax, and translate that value to the scale of 0 to 100
  Serial.print("\t"); //a tab to make the reading more easy
  Serial.println(x);  //post mapped value, println is a linebreak as well
  delay(100); //so we don't post to much in the serial and you can read data better.
}
