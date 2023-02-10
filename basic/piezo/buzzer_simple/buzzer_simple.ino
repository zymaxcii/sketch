// buzzer_simple.ino
// status: compile ok, upload ok

// simple buzzing
// https://surtrtech.com/2018/01/29/how-to-use-a-buzzer-piezo-speaker-with-arduino/

// buzzer module with 3 pins: wire I/O with D3
// other version wire the (+) pin with D3
// Refer to https://surtrtech.com/ for more information
// Emitting 1KHz sound for 1s and then 2KHz sound for 1s


int buzzer = 3;


void setup()
{
  pinMode(buzzer, OUTPUT);
 
}
 

void loop()
{
 tone(buzzer, 1000); // buzzer pin, sound frequency, duration
 delay(1000);
 
 tone(buzzer, 2000);
 delay(1000);
 
 noTone(buzzer);     // stop
 delay(500);
}
