// trafficLight_4Way.ino
// This sketch looks more promising - mty

#define OFF 99
#define RED 11
#define YELLOW 10
#define GREEN 9

#define NORTH 8
#define SOUTH 7
#define EAST 6
#define WEST 5

unsigned long phaseStart;
byte cycleCounter;


void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(NORTH, OUTPUT);
  pinMode(SOUTH, OUTPUT);
  pinMode(EAST, OUTPUT);
  pinMode(WEST, OUTPUT);
  StartupSequence();
}


void loop()
{
  while (cycleCounter++ < 2)
  {
    phaseStart = millis();
    while (millis()-phaseStart < 4000)
    {
      Show(NORTH, GREEN);
      Show(SOUTH, GREEN);
      Show(EAST, RED);
      Show(WEST, RED);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, YELLOW);
      Show(SOUTH, YELLOW);
      Show(EAST, RED);
      Show(WEST, RED);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, RED);
      Show(WEST, RED);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < 4000)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, GREEN);
      Show(WEST, GREEN);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, YELLOW);
      Show(WEST, YELLOW);
    }
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, RED);
      Show(WEST, RED);
    }
  }
  
  while (cycleCounter++ < 12)
  {
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, OFF);
      Show(WEST, OFF);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, OFF);
      Show(SOUTH, OFF);
      Show(EAST, YELLOW);
      Show(WEST, YELLOW);
    }
  }
  
  phaseStart = millis();
  while (millis()-phaseStart < 1000)
  {
    Show(NORTH, RED);
    Show(SOUTH, RED);
    Show(EAST, RED);
    Show(WEST, RED);
  }
  
  while (cycleCounter++ < 17)
  {
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, GREEN);
      Show(SOUTH, GREEN);
      Show(EAST, RED);
      Show(WEST, OFF);
    }
    phaseStart = millis();
    while (millis()-phaseStart < 1000)
    {
      Show(NORTH, GREEN);
      Show(SOUTH, GREEN);
      Show(EAST, RED);
      Show(WEST, RED);
    }
  }
  cycleCounter = 0;
}


void StartupSequence()
{
  int stepTime = 200;
  for (byte i=0; i<2; i++)
  {
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(NORTH, RED);
      Show(NORTH, YELLOW);
      Show(NORTH, GREEN);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(EAST, RED);
      Show(EAST, YELLOW);
      Show(EAST, GREEN);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(SOUTH, RED);
      Show(SOUTH, YELLOW);
      Show(SOUTH, GREEN);
    }
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(WEST, RED);
      Show(WEST, YELLOW);
      Show(WEST, GREEN);
    }
  }
  
  for (byte i=0; i<2; i++)
  {
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(NORTH, RED);
      Show(SOUTH, RED);
      Show(EAST, RED);
      Show(WEST, RED);
    }
    
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(NORTH, YELLOW);
      Show(SOUTH, YELLOW);
      Show(EAST, YELLOW);
      Show(WEST, YELLOW);
    }
    phaseStart = millis();
    while (millis()-phaseStart < stepTime)
    {
      Show(NORTH, GREEN);
      Show(SOUTH, GREEN);
      Show(EAST, GREEN);
      Show(WEST, GREEN);
    }
  }
}


void Show(byte road, byte color)
{
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  
  digitalWrite(NORTH, NORTH != road);
  digitalWrite(SOUTH, SOUTH != road);
  digitalWrite(EAST, EAST != road);
  digitalWrite(WEST, WEST != road);
  
  switch(color)
  {
    case RED: digitalWrite(RED, RED == color); break;
    case YELLOW: digitalWrite(YELLOW, YELLOW == color); break;
    case GREEN: digitalWrite(GREEN, GREEN == color);
  }
  delayMicroseconds(500);
}

