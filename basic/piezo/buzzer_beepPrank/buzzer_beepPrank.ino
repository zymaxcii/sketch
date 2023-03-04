// buzzer_beepPrank.ino
// status: compile , upload 

/*
 * Arduino Beep Prank
 * 
 * learnelectronics
 * 19 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */


long myTime = 0;     // -2,147,483,648 to 2,147,483,647


void setup()
{
  randomSeed(analogRead(0));  // floating between 0 & 1023
  pinMode(7, OUTPUT);         // beeper
}


void loop()
{
  myTime = random(60000, 21600000);     // random delay of 1 min to 6 hours
  delay(myTime);

  digitalWrite(7, HIGH);                // activate beeper
  delay(50);
  digitalWrite(7,LOW);                  // deactivate beeper
}
