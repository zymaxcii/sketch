// 7seg4d_lm35.ino
// https://nandgeek.com/blog/how-to-use-4-digit-7-segment-display-with-arduino/
// 7seg4d: I2C or non I2C version?

/**
 * Author      : Julioceaseless
 * Date        : September 2019
 * Description : Display temperature from LM35 temperature sensor 
 *               and display it on a 4-Digit Seven Segment Display
 * Website     : https://nandgeek.com
**/
 
// Pin 2-8 is connected to the 7 segments of the display
#define ADCPIN 0

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

// common pins
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

// decimal pin
int Dot = 13;

double Temperature = 0;
int temp = 0;
int placeValuesofTemp[4];

int tempRefresh = 1000;      // refresh temperature every 1 second
int sevSegRefresh = 5;

unsigned long time_now = 0;


void setup()
{
  analogReference(INTERNAL); 
                
  // initialize the digital pins as outputs
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(Dot, OUTPUT); 
  Serial.begin(9600);
}


void loop()
{
  // read temperature every second
  if (millis() > time_now + tempRefresh )
  {
    time_now = millis();

    // read from temperature sensor
    Temperature = analogRead(ADCPIN);
    Temperature = Temperature*1100/(1024*10);
    temp = Temperature*100;
  
    // put temp digits by their place value
    placeValuesofTemp[3] = ((temp)/1)%10;
    placeValuesofTemp[2] = ((temp)/10)%10;
    placeValuesofTemp[1] = ((temp)/100)%10;
    placeValuesofTemp[0] = ((temp)/1000)%10;
  } // end millis() if statement

  // seven segment 0 - 0 digits
  int number [10][7] =
  {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 0, 0, 0, 1, 1, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}, // 9
        
  };

  int commonPin [5][4]=
  {
    {0, 1, 1, 1},    // enable digit 1
    {1, 0, 1, 1},    // enable digit 2
    {1, 1, 0, 1},    // enable digit 3
    {1, 1, 1, 0},    // enable digit 4
    {0, 0, 0, 0},    // enable all
  };
    
  for (int n = 0; n<4; n++)
  {
    for (int x = 0; x < 4; x++ )
    {
      digitalWrite(x+9, commonPin[n][x]);
      (n==1)?digitalWrite(Dot, 1):digitalWrite(Dot, 0);      // display decimal after second digit
    }
          
    // display 4 digits
    for (int j = 0; j < 7; j++)
    {
      //loop seven segments
      digitalWrite(j+2,number[placeValuesofTemp[n]][j] );  
    }
           
    delay(sevSegRefresh);                                    // seven segment refresh rate
  }
}
