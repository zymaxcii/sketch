// buzzer_bday.ino
// https://www.mrelectrouino.com/2019/06/buzzer-tutorial-using-arduino-play.html


int buzzer = 8;


void setup() 
{
  pinMode(buzzer, OUTPUT);
}


void loop() 
{  
  // creating more notes by changing frequency AND duration
  int notes[10]= {234, 324, 432, 543, 232, 267, 876, 368, 123, 980};       // an array having different frequency

  for (int i = 0; i< 10; i++)
  {
    tone(buzzer, notes[i]);
    delay(1000);
  }
    noTone(buzzer);                                                        // stops tone
    delay(1000);
}
