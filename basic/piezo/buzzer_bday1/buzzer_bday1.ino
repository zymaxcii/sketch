// buzzer_bday1.ino
// status: compile ok, upload ok
// https://www.mrelectrouino.com/2019/06/buzzer-tutorial-using-arduino-play.html
// cannot figure out the tunes because of fixed 1 sec duration between notes
// buzzer_bday2.ino is better


int buzzer = 3;


void setup() 
{
  pinMode(buzzer, OUTPUT);
}


void loop() 
{  
  // creating more notes by changing frequency AND duration
  
  // an array having different frequencies
  int notes[10]= {234, 324, 432, 543, 232, 267, 876, 368, 123, 980}; 
  
  for (int i = 0; i< 10; i++)
  {
    tone(buzzer, notes[i]);
    delay(300);           // original 1000
  }
    noTone(buzzer);       // stops tone
    delay(1000);
}
