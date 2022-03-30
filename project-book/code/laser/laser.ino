// laser.ino

/*
 * Laser Sensor module for Arduino
 * Turns ON a buzzer or you can control a motor or servo or any other action
 * Watch the video https://youtu.be/h_y1y6eUvIY
 *  Written by Ahmad Shamshiri for Robojax.com
 * on Feb 02, 2018 at 18:24 in Ajax, Ontario, Canada
 * This code has been download from Robojax.com
*/


#define DETECT 2 // pin 2 for sensor
#define ACTION 8 // pin 8 for action to do someting


void setup()
{
  Serial.begin(9600);
  Serial.println("Robojax.com Laser Module Test");
  pinMode(DETECT, INPUT);      // define detect input pin
  pinMode(ACTION, OUTPUT);     // define ACTION output pin
}


void loop()
{
  // Laser Sensor code for Robojax.com
  int detected = digitalRead(DETECT);     // read Laser sensor
 
  if ( detected == HIGH)
  {
    digitalWrite(ACTION,HIGH);            // set the buzzer ON
    Serial.println("Detected!");
  }
  else
  {
    digitalWrite(ACTION,LOW);             // Set the buzzer OFF
    Serial.println("No laser");
  }
  delay(200);
}

