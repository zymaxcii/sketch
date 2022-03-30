// buzzer_1toneChange.ino

// This code is to use with a buzzer if you're using the module with 3 pins wire the I/O with D8
// If you're using the other version wire the (+) pin with 8 
// Refer to https://surtrtech.com/ for more information
// Emitting 1KHz sound for 1s and then 2KHz sound for 1s

int buzzer = 3;      // can use any digital pin
 
void setup()
{
  pinMode(buzzer, OUTPUT);
 
}


void loop()
{
  tone(buzzer, 1000);
  // tone() is the main function to use with a buzzer
  // it takes 2 or 3 parameteres (buzzer pin, sound frequency, duration)
  
  delay(1000);
  tone(buzzer, 2000);
  // You can also use noTone() to stop the sound it takes 1 parametere which is the buzzer pin
  delay(2000);
}

