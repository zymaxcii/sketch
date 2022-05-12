// pir_tester.ino

/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int led = 13;
int sensor = 2;
int state = LOW;             // by default, no motion detected
int val = 0;                 // sensor value

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}


void loop()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH)
  {
    // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW)
    {
      Serial.println("Motion detected!"); 
      state = HIGH;            // update variable state to HIGH
    }
  } 
  else
  {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH)
      {
        Serial.println("Motion stopped!");
        state = LOW;          // update variable state to LOW
      }
  }
}
