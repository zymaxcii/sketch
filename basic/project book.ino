// arduino projects book
// chapter 2
// spaceship interface

int switchState = 0;

void setup()
{
  pinMode(3,OUTPUT);  // led: HIGH on
  pinMode(4,OUTPUT);  // led
  pinMode(5,OUTPUT);  // led
  pinMode(2,INPUT);   // switch: LOW not presses
}


void loop()
{
  switchState = digitalRead(2);

  if (switchState == LOW)
  {
    // the button is not pressed
    digitalWrite(3, HIGH);    // green LED
    digitalWrite(4, LOW);     // red LED
    digitalWrite(5, LOW);     // red LED
  }
  else
  {
    // if the switchState is LOW:
    // turn the green LED on
    // turn the red LEDs off
    // if the switchState is HIGH:
    // turn the green LED off
    // turn the red LEDs on
    // the button is pressed
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);               // wait for a quarter second
  }
} // go back to the beginning of the loop




// chapter 3
// love-o-meter

const int sensorPin = A0;           // temperature sensor
const float baselineTemp = 20.0;


void setup()
{
  Serial.begin(9600);               // open a serial port
  
  for (int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}


void loop()
{
  int sensorVal = analogRead(sensorPin);
  
  Serial.print(“Sensor Value: “);
  Serial.print(sensorVal);

  // convert ADC reading to voltage 
  float voltage = (sensorVal/1024.0) * 5.0;
  
  Serial.print(“, Volts: “);
  Serial.print(voltage);
  Serial.print(“, degrees C: “);
  
  // convert voltage to temperature in degrees arduino.cc/kitdatasheets
  float temperature = (voltage - .5) * 100;
  
  Serial.println(temperature);
  
  if(temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else
  {
    if (temperature >= baselineTemp+2 && temperature < baselineTemp+4)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }
    else
    {
      if(temperature >= baselineTemp+4 && temperature < baselineTemp+6)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      }
      else
      {
        if (temperature >= baselineTemp+6)
        {
          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
        }
      }    
    }  
 
    delay(1);
  }
}




// chapter 4
// color mixing lamp

const int  greenLEDPin = 9;
const int  redLEDPin = 11;
const int blueLEDPin = 10;

const int   redSensorPin = A0;
const int greenSensorPin = A1;
const int  blueSensorPin = A2;

int   redValue = 0;
int greenValue = 0;
int  blueValue = 0;

int   redSensorValue = 0;
int greenSensorValue = 0;
int  blueSensorValue = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin,   OUTPUT);
  pinMode(blueLEDPin,  OUTPUT);
}


void loop()
{
  redSensorValue = analogRead(redSensorPin);
  delay(5);

  greenSensorValue = analogRead(greenSensorPin);
  delay(5);

  blueSensorValue = analogRead(blueSensorPin);

  Serial.print(“Raw Sensor Values \t Red: “);
  Serial.print(redSensorValue);
  Serial.print(“\t Green: “);
  Serial.print(greenSensorValue);
  Serial.print(“\t Blue: “);
  Serial.println(blueSensorValue);

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print(“Mapped Sensor Values \t Red: “);
  Serial.print(redValue);
  Serial.print(“\t Green: “);
  Serial.print(greenValue);
  Serial.print(“\t Blue: “);
  Serial.println(blueValue);

  analogWrite(redLEDPin,   redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin,  blueValue);
}




// chapter 5
// mood cue

#include <Servo.h>

Servo myServo;

int const potPin = A0;

int potVal;
int angle;


void setup()
{
  myServo.attach(9);
  
  Serial.begin(9600);
}


void loop()
{
  potVal = analogRead(potPin);

  Serial.print(“potVal: “);
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print(“, angle: “);
  Serial.println(angle);

  myServo.write(angle);
  
  delay(15);
}




// chapyter 6
// theramin

int sensorValue;

int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;


void setup()
{
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000)
  {
    sensorValue = analogRead(A0);

    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  
  digitalWrite(ledPin, LOW);
}


void loop() 
{
  sensorValue = analogRead(A0);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  
  tone(8,pitch,20);
  
  delay(10);
}



// chapter 7
// keyboard instrument

int buttons[6];      // set up an array with 6 integers

int buttons[0] = 2;  // give first element of array value 2

int notes[] = {262, 294, 330, 349};


void setup() 
{
  Serial.begin(9600);
}


void loop() 
{
  int keyVal = analogRead(A0);

  Serial.println(keyVal);

  if (keyVal == 1023)
  {
    tone(8, notes[0]);
  }

  else
  {
    if (keyVal >= 990 && keyVal <= 1010)
    {
      tone(8, notes[1]);
    }
    else
    {
      if (keyVal >= 505 && keyVal <= 515)
      {
        tone(8, notes[2]);
      }
      else
      {
        if(keyVal >= 5 && keyVal <= 10)
        {
          tone(8, notes[3]);
        }
        else
        {
          noTone(8);
        }
      }
    }
  }
}




// chapter 8
// digital hourglass

const int switchPin = 8;          // tilt switch

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 600000;


void setup()
{
  for (int x = 2; x<8; x++)
  {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}


void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval)
  {
    previousTime = currentTime;

   digitalWrite(led, HIGH);
   led++;

   if (led == 7)
   {
   }
  }
  
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState)
  {
    for (int x = 2; x<8; x++)
    {
      digitalWrite(x, LOW);
    }
  
    led = 2;

    previousTime = currentTime;
  }
  
  prevSwitchState = switchState;
}



// chapter 9
// pinwheel

const int switchPin = 2;
const int motorPin = 9;

int switchState = 0;


void setup() 
{
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}


void loop()
{
  switchState = digitalRead(switchPin);

  if (switchState == HIGH)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }
}



// chapter 10
// zoetrope

const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;

const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;

const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;


void setup()
{
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);

  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}


void loop()
{
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);

  motorSpeed = analogRead(potPin)/4;

  if (onOffSwitchState != previousOnOffSwitchState)
  {
    if (onOffSwitchState == HIGH)
    {
      motorEnabled = !motorEnabled;
    }
  }
  
  if (directionSwitchState != previousDirectionSwitchState)
  {
    if (directionSwitchState == HIGH)
    {
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1)
  {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else
  {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    analogWrite(enablePin, 0);
  }
  
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}




// chapter 11
// crystal ball

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;


void setup()
{
  lcd.begin(16, 2);
  
  pinMode(switchPin, INPUT);
  lcd.print(“Ask the”);

  lcd.setCursor(0, 1);
  lcd.print(“Crystal Ball!”);
}


void loop() 
{
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState)
  {
    if (switchState == LOW)
    {
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print ( “The ball says:” );
      lcd.setCursor(0, 1);

      switch(reply)
      {
        case 0:
          lcd.print(“Yes”);
          break;

        case 1:
          lcd.print(“Most likely”);
          break;

        case 2:
          lcd.print(“Certainly”);
          break;

        case 3:
          lcd.print(“Outlook good”);
          break;

        case 4:
          lcd.print(“Unsure”);
          break;
          
        case 5:
          lcd.print(“Ask again”);
          break;

        case 6:
          lcd.print(“Doubtful”);
          break;

        case 7:
          lcd.print(“No”);
          break;
      } 
    }
  }
  
  prevSwitchState = switchState;
}




// chapter 12
// knock lock

#include <Servo.h>

Servo myServo;

const int piezo = A0;

const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;


void setup()
{
  myServo.attach(9);

  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(switchPin, INPUT);

  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println(“The box is unlocked!”);
}


void loop()
{
  if (locked == false)
  {
    switchVal = digitalRead(switchPin);

    if (switchVal == HIGH)
    {
      locked = true;
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed,HIGH);

      myServo.write(90);
      Serial.println(“The box is locked!”);
      delay (1000);
    }
  }
   
  if (locked == true)
  {
    knockVal = analogRead(piezo);

    if (numberOfKnocks < 3 && knockVal > 0)
    {
      if (checkForKnock(knockVal) == true)
      {

        numberOfKnocks++;
      }
      
      Serial.print(3-numberOfKnocks);
      Serial.println(“ more knocks to go”);
    }
    
    if (numberOfKnocks >= 3)
    {
      locked = false;
      myServo.write(0);
      delay(20);
      
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed,LOW);
      Serial.println(“The box is unlocked!”);
    }
  }
}


boolean checkForKnock(int value)
{
  if (value > quietKnock && value < loudKnock)
  {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    
    digitalWrite(yellowLed, LOW);

    Serial.print(“Valid knock of value “);
    Serial.println(value);
    return true;
  }
  else
  {
    Serial.print(“Bad knock value “);
    Serial.println(value);
    return false;
  }
}



// chapter 13
// touchy feely

#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 1000;
const int ledPin = 12;


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop()
{
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);

  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  delay(10);
}



// chapter 14
// tweak arduino log

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  Serial.write(analogRead(A0)/4);
  delay(1);
}




// processing

import processing.serial.*;

Serial myPort;
PImage logo;

int bgcolor = 0;

void setup()
{
  colorMode(HSB, 255);

  logo = loadImage(“http://arduino.cc/logo.png”);
  size(logo.width, logo.height);

  println ( “Available serial ports:” );
  println(Serial.list());

  myPort = new Serial(this, Serial.list()[0], 9600);
}


void draw()
{
  if (myPort.available() > 0)
  {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}




// chapter 15
// hacking opto

const int optoPin = 2;

void setup()
{
  pinMode(optoPin, OUTPUT);
}


void loop()
{
  digitalWrite(optoPin, HIGH);
  delay(15);

  digitalWrite(optoPin, LOW);
  delay(21000);
}


