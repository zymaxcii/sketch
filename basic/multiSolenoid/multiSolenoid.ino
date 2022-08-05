// multiSolenoid.ino
// https://github.com/JeremySCook/MultiSolenoid/blob/master/MultiSolenoid.ino
// https://www.arrow.com/en/research-and-events/articles/arduino-solenoid-project-control-solenoid-with-arduino-board


/*
Based on Arduino Blink Sketch
Modified to control 3 items in sequence (solenoids in this case)
By Jeremy S. Cook 4/12/2019
*/

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); //also builtin LED - will blink when triggered
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH); //first servo on
  delay(500);
  digitalWrite(13, LOW); //first servo off
  delay(50);
  digitalWrite(12, HIGH); //second servo on
  delay(500);
  digitalWrite(12, LOW); //second servo off
  delay(50);
  digitalWrite(11, HIGH); //third servo on
  delay(500);
  digitalWrite(11, LOW); //third servo off (all are off)
  delay(500);
}
