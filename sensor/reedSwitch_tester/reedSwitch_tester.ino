// reedSwitch_tester.ino
// magnetic reed switch

/*
 Created by Rui Santos
 All the resources for this project:
 http://randomnerdtutorials.com/
*/


int ledOpen  = 4;      // red
int ledClose = 6;      // green
int switchReed = 2;


void setup()
{
  pinMode(ledOpen,  OUTPUT);
  pinMode(ledClose, OUTPUT);
  pinMode(switchReed, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{
  if (digitalRead(switchReed)==LOW)
  {
    digitalWrite(ledOpen, LOW);
    digitalWrite(ledClose, HIGH);
    Serial.println("Your Door is Closed");
  }
  else
  {
    digitalWrite(ledOpen, HIGH);
    digitalWrite(ledClose, LOW);
    Serial.println("Your Door is Open");
  }
  // original 1
  delay(100);
}
