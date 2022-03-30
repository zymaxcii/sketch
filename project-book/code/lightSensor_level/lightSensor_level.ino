// lightSensor_level.ino

// This program's logic is wrong I think
// dark means readins get higher, more resistance

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-light-sensor
 */

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void loop()
{
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  Serial.print("Analog reading: ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10)
  {
    Serial.println(" - Dark");
  }
  else
    if (analogValue < 200)
    {
      Serial.println(" - Dim");
    }
    else
      if (analogValue < 500)
      {
        Serial.println(" - Light");
      }
      else
        if (analogValue < 800)
        {
          Serial.println(" - Bright");
        }
        else
        {
          Serial.println(" - Very bright");
        }

  delay(500);
}
