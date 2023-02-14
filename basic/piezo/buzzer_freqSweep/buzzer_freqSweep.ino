// buzzer_freqSweep.ino
// status: compile ok, upload ok

// buzzer module use pin D3
// If you're using the other version wire the (+) pin with D3
// Refer to https://surtrtech.com/ for more information

// Increasing sound freqency from 100 to 2 KHz then decreasing frequency from 2KHz to 100Hz

int buzzer = 3;


void setup()
{
  pinMode(buzzer, OUTPUT);
}


void loop()
{
    for (int i=100 ; i<2000 ; i++)
    {
      // loop for to increase the sound frequency
      tone(buzzer, i);
      delay(10);
    }
    
    for (int i=2000 ; i>100 ; i--)
    {
      tone(buzzer, i);
      delay(10);
    } 
}
