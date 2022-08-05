// pot_readInput.ino
//

/*
pot.ino
Adafruit Arduino - Lesson 8. Analog Inputs
*/

// Boards to run the sketch:
// my poteniometer board

// 10 kOhms
// Connect potentiometer output to analog input A0
//
// pin # Name to Uno Pin
// =====================
// 1  VCC  VCC
// 2  OUT  A0
// 3  GND GND


// pin A0 not digital D0
int potPin = 0;  // 0 or A0

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  int reading = analogRead(potPin);
  Serial.println(reading);
  delay(500);
}
