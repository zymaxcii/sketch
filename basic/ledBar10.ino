// ledBar10.ino
// https://forum.arduino.cc/t/diy-coolant-temperature-gauge-for-motorcycles/435194/14


//declares all the pin connections to the arduino board
const int LED1= 11; 
const int LED2= 10;
const int LED3= 9;
const int LED4= 8;
const int LED5= 7;
const int LED6= 6;
const int LED7= 5;
const int LED8= 4;
const int LED9= 3;
const int LED10= 2;
const int potentiometer= A0;

int value=0;

//declares the LEDs as outputs and the potentiometer as inputs
//also creates a Serial Monitor so that we can see what the actually analog value is
void setup()
{
pinMode(LED1, OUTPUT); 
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode (LED5, OUTPUT);
pinMode (LED6, OUTPUT);
pinMode (LED7, OUTPUT);
pinMode (LED8, OUTPUT);
pinMode (LED9, OUTPUT);
pinMode (LED10, OUTPUT);
pinMode (potentiometer, INPUT);
Serial.begin(9600);
}

void loop()
{
value= analogRead(potentiometer);
Serial.println(value);

//at 35 degrees
if ((value >= 1802) && (value < 9420))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, LOW);
digitalWrite (LED3, LOW);
digitalWrite (LED4, LOW);
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 40 degrees
if ((value >=1459) && (value < 1802))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, LOW);
digitalWrite (LED4, LOW); 
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 45 degrees
if ((value >= 1188) && (value < 1459))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, LOW); 
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 50 degrees
if ((value >= 973) && (value < 1188))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 60 degrees
if ((value >= 667) && (value < 973))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, LOW); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 70 degrees
if ((value >= 467) && (value < 667))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, HIGH); 
digitalWrite (LED7, LOW);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 80 degrees
if ((value >= 340) && (value < 467))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, HIGH); 
digitalWrite (LED7, HIGH);
digitalWrite (LED8, LOW); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 90 degrees
if ((value >= 241) && (value < 340))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, HIGH); 
digitalWrite (LED7, HIGH);
digitalWrite (LED8, HIGH); 
digitalWrite (LED9, LOW);
digitalWrite (LED10, LOW); 
}

//at 100 degrees
if ((value >= 177) && (value < 241))
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, HIGH); 
digitalWrite (LED7, HIGH);
digitalWrite (LED8, HIGH); 
digitalWrite (LED9, HIGH);
digitalWrite (LED10, LOW); 
}

//lights up 9 LEDs
if (value < 177)
{
digitalWrite (LED1, HIGH);
digitalWrite (LED2, HIGH);
digitalWrite (LED3, HIGH);
digitalWrite (LED4, HIGH); 
digitalWrite (LED5, HIGH);
digitalWrite (LED6, HIGH); 
digitalWrite (LED7, HIGH);
digitalWrite (LED8, HIGH); 
digitalWrite (LED9, HIGH);
digitalWrite (LED10,HIGH); 
}
}
