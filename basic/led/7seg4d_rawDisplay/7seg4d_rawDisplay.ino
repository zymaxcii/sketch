// 7seg4d_rawDisplay.ino
// 7seg_4x8_bit_numbers.ino
// This sketch is not working
// display number entered from serial monitor

// Boards to run the sketch:
// my 7 segment 4-digit led board

// 3641AS:
// 
// pin # Name to Uno Pin
// =====================
// 1  E  D6
// 2  D  D5
// 3  DP D9
// 4  C  D4
// 5  G  D8
// 6  D4 D13
// 7  B  D3
// 8  D3 D12
// 9  D2 D11
//10  F  D7  
//11  A  D2
//12  D1 D10

// bottom CCW pins 1-6, then 7-12
// pins 1-12: E,D,DP,C,G,D4, B,D3,D2,F,A,D1
// segments A,B,C,D,E,F,G,DP to pins D2,D3,D4,D5,D6,D7,D8,D9
// common cathode 3641AS pins D1,D2,D3,D4: D10,D11,D12,D13

int aPin = 2;  //         A
int bPin = 3;  //      ________
int cPin = 4;  //     |        |
int dPin = 5;  //   F |        |  B
int ePin = 6;  //     |    G   |
int fPin = 7;  //     |________|
int gPin = 8;  //     |        |
int GND1 = 10; //     |        |
int GND2 = 11; //   E |        |   C
int GND3 = 12; //     |________|
int GND4 = 13; //        
int num;       //         D
int dig1;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;
int DTime = 10;    // original 4


void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);  
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  Serial.begin(9600);
}


//void loop()
//{
//
//  clearLEDs(); three();
//}

 void loop()
{
//  digitalWrite( GND1, LOW);
//  digitalWrite( GND2, LOW);
//  digitalWrite( GND3, LOW);
//  digitalWrite( GND4, LOW);
 
 if (Serial.available() > 0) 
 {
  num = Serial.parseInt();
  Serial.println(num);
  dig1 = num / 1000;
  num = num - (dig1 * 1000);
  dig2 = num / 100;
  num = num - (dig2 * 100);
  dig3 = num / 10;
  dig4 = num - (dig3 *10);

  Serial.print(dig4);
  Serial.print(dig3);
  Serial.print(dig2);
  Serial.println(dig1);

 } 
  
  
  digitalWrite( GND4, LOW);    //digit 4
  pickNumber(dig4);
  delay(DTime);
  digitalWrite( GND4, HIGH);
  
  digitalWrite( GND3, LOW);    //digit 3
  pickNumber(dig3);
  delay(DTime);
  digitalWrite( GND3, HIGH);
  
  digitalWrite( GND2, LOW);   //digit 2
  pickNumber(dig2);
  delay(DTime);
  digitalWrite( GND2, HIGH);
  
  digitalWrite( GND1, LOW);   //digit 1
  pickNumber(dig1);
  delay(DTime);
  digitalWrite( GND1, HIGH);
 
}
  
void pickNumber(int x)
{
   switch(x)
   {
     case 1: one();   break;
     case 2: two();   break;
     case 3: three(); break;
     case 4: four();  break;
     case 5: five();  break;
     case 6: six();   break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine();  break;
     default: zero(); break;
   } 
}

void clearLEDs()
{   
  digitalWrite(  2, LOW); // A
  digitalWrite(  3, LOW); // B
  digitalWrite(  4, LOW); // C
  digitalWrite(  5, LOW); // D
  digitalWrite(  6, LOW); // E
  digitalWrite(  7, LOW); // F
  digitalWrite(  8, LOW); // G 
}

void one()
{
  digitalWrite( aPin, LOW); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, LOW); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, LOW); 
  digitalWrite( gPin, LOW); 
}

void two()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, HIGH); 
  digitalWrite( fPin, LOW); 
  digitalWrite( gPin, HIGH); 
}

void three()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, LOW); 
  digitalWrite( gPin, HIGH); 
}

void four()
{
  digitalWrite( aPin, LOW); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, LOW); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, HIGH); 
}

void five()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, HIGH); 
}

void six()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, HIGH); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, HIGH); 
}

void seven()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, LOW); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, LOW); 
  digitalWrite( gPin, LOW); 
}

void eight()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, HIGH); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, HIGH); 
}

void nine()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, LOW); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, HIGH); 
}

void zero()
{
  digitalWrite( aPin, HIGH); 
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH); 
  digitalWrite( dPin, HIGH); 
  digitalWrite( ePin, HIGH); 
  digitalWrite( fPin, HIGH); 
  digitalWrite( gPin, LOW); 
}
