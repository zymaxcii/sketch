// coolant_temperature_gauge.ino
//https://forum.arduino.cc/t/diy-coolant-temperature-gauge-for-motorcycles/435194/18



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

int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1=1000;
float R2= 0;
float buffer= 0;

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

//Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
}

//////////////////  delete after testing
//Serial.println(R2);
//delay(1000);
//////////////////  delete after testing


//at 35 degrees
if ((R2 >= 1802) && (R2 < 9420))
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
if ((R2 >=1459) && (R2 < 1802))
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
if ((R2 >= 1188) && (R2 < 1459))
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
if ((R2 >= 973) && (R2 < 1188))
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
if ((R2 >= 667) && (R2 < 973))
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
if ((R2 >= 467) && (R2 < 667))
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
if ((R2 >= 340) && (R2 < 467))
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
if ((R2 >= 241) && (R2 < 340))
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
if ((R2 >= 177) && (R2 < 241))
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
if (R2 < 177)
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
