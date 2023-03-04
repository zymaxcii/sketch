// love_o_meter.ino
// Arduino project book
// chapter 3
// love-o-meter.ino

// bug in check_temperature()
// connect tmp36 temperature sensor to A0
// connect 3 red leds to pins 2,3,4 with 330ohms resistors to +5v
// sense temerature to determine how much you are in love
// love level: from 1 to 3 leds being lit up

int sensorVal;
int sensorPin = A0;
const float baselineTemp = 20.0;    // default to 20
void check_temperature();


void setup()
{
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);   // turn off led
  }
}


void loop()
{
  sensorVal = analogRead(sensorPin);
  
  // copy code from pdf encounters error in double quote: retype
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // convert ADC reading to voltage
  // for TMP36
  // float voltage = (sensorVal/1024.0) * 5.0;
  // float temperature = (voltage - .5) * 100;

  // for LM35
  float voltage = (sensorVal/1024.0)*5000;
  float temperature = voltage/10;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  check_temperature(temperature);
  delay(500);
}


void check_temperature(float temperature)
{
  // here is the love logic
  // why this logic causes sensorVal to be wrong on second loop onwards?
  if (temperature < baselineTemp)
  {
    digitalWrite(2, LOW);     // all 3 leds off: no love at all
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else
  {
    if (temperature >= baselineTemp+2 && temperature < baselineTemp+4)
    {
      digitalWrite(2, HIGH);  // 22 to 24 degree: 1 led lit
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }
    else
    {
      if (temperature >= baselineTemp+4 && temperature < baselineTemp+6)
      {
        digitalWrite(2, HIGH);  // 24 to 26: 2 leds lit
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      }
      else
      {
        if (temperature >= baselineTemp+6)
        {
          digitalWrite(2, HIGH);  // above 26 degree: all 3 leds lit
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
        }
      }    
    }  
  }
}
