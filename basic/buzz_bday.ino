// buzz_bday.ino
// https://www.mrelectrouino.com/2019/06/buzzer-tutorial-using-arduino-play.html

int buzzer = 8;
void setup() 
{
    // put your setup code here, to run once:
    pinMode(buzzer, OUTPUT);//sets the digital pin as OUTPUT
}

void loop() 
{  
// put your main code here, to run repeatedly:
  //creating a more notes by changing frequency AND duration

int notes[10]={234,324,432,543,232,267,876,368,123,980}; //an array having different frequency

for(int i = 0; i< 10; i++)
{
    tone(buzzer, notes[i]);
    delay(1000);
  }
    noTone(buzzer);// stops tone
    delay(1000);
}
