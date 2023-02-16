// 8led_larsonScanner.ino
// https://www.instructables.com/8-LED-Larson-Scanner-with-Arduino/
// use DIP led bar has better effect
// press button to start scnning
// pot at A0 determines the scanning rate

// to do: can modify this code to simulate led display of AS-66 alkaline water dispenser

const int buttonPin = 2;
const int ledPin1 = 13;
int buttonState = 0;

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
// int leds[] = {6,7,8,9,10,11,12,13};

// with the 8 led module and mega - no jumper wires no separate GND jumper
int leds[] = {39,41,43,45,47,49,51,53};




#define NUMBER_OF_LEDS (sizeof(leds)/sizeof(int))

boolean larson[][NUMBER_OF_LEDS] =
{
  { HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW},
  { LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW},
  { LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW},
  { LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW},
  { LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW},
  { LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW},
  { LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW},
  { LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH},
  { LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW},
  { LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW},
  { LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW},
  { LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW},
  { LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW},
  { LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW},  
};

#define FRAMES (sizeof(larson)/(sizeof(larson[0])))

int sensorPin = 0;


void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  for (int led=0; led<NUMBER_OF_LEDS; led++)
  {
    pinMode(leds[led], OUTPUT);
  }
}


void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    digitalWrite(ledPin1, HIGH);
  }
  else
  {
    long time = millis();

    for (int frame=0; frame<FRAMES; frame++)
    {
      for (int led=0; led<NUMBER_OF_LEDS; led++)
      {
        digitalWrite(leds[led], larson[frame][led]);
      }

      int sensorValue = map(analogRead(sensorPin), 0, 1023, 0, 1000);
      while (sensorValue >= (millis() - time))
      {
        sensorValue = analogRead(sensorPin);
      }
      time = millis();
    }
  }
}
