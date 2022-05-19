// 7seg4d_alanCounter.ino
// http://alanh0research.blogspot.com/2015/08/arduino-4-digit-7-segment-display.html

// segment | Arduino board PIN number   
 #define segG 12  
 #define segF 11  
 #define segA 6  
 #define segB 7  
 #define segE 10  
 #define segD 9  
 #define segC 8  
 #define DP 13  
 #define GND1 2  
 #define GND2 3  
 #define GND3 4  
 #define GND4 5  
 int timer=0;   
 int i=0;  
 // functions to display digits  
 void digit0 () {  
  digitalWrite(segA, LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, LOW);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, HIGH);  
 };  
 void digit1 () {  
  digitalWrite(segA, HIGH);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, HIGH);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, HIGH);  
  digitalWrite(segG, HIGH);  
 };  
 void digit2 () {  
  digitalWrite(segA,LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, HIGH);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, LOW);  
  digitalWrite(segF, HIGH);  
  digitalWrite(segG, LOW);  
 };  
 void digit3 () {  
  digitalWrite(segA,LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, HIGH);  
  digitalWrite(segG, LOW);  
 };  
 void digit4 () {  
  digitalWrite(segA,HIGH);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, HIGH);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, LOW);  
 };  
 void digit5 () {  
  digitalWrite(segA,LOW);  
  digitalWrite(segB, HIGH);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, LOW);  
 };  
 void digit6 () {  
  digitalWrite(segA,LOW);  
  digitalWrite(segB, HIGH);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, LOW);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, LOW);  
 };  
 void digit7 () {  
  digitalWrite(segA,LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, HIGH);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, HIGH);  
  digitalWrite(segG, HIGH);  
 };  
 void digit8 () {  
  digitalWrite(segA, LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, LOW);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, LOW);  
 };  
 void digit9 () {  
  digitalWrite(segA, LOW);  
  digitalWrite(segB, LOW);  
  digitalWrite(segC, LOW);  
  digitalWrite(segD, LOW);  
  digitalWrite(segE, HIGH);  
  digitalWrite(segF, LOW);  
  digitalWrite(segG, LOW);  
 };  
 //function to display digit from inputed int  
 void showdigit (int digit)  
 {  
  switch (digit) {  
  case 0:  
   digit0 ();  
   break;  
  case 1:  
   digit1 ();  
   break;  
  case 2:  
   digit2 ();  
   break;  
  case 3:  
   digit3 ();  
   break;  
  case 4:  
   digit4 ();  
   break;  
  case 5:  
   digit5 ();  
   break;  
  case 6:  
   digit6 ();  
   break;  
  case 7:  
   digit7 ();  
   break;  
  case 8:  
   digit8 ();  
   break;  
  case 9:  
   digit9 ();  
   break;  
  default:  
   break;  
  };   
 };  
 // showing 4 digits  
 void showdigits (int number)  
 {  
  // e.g. we have "1234"  
  showdigit(number/1000); // segments are set to display "1"  
  digitalWrite(GND1, HIGH); // first digit on,  
  digitalWrite(GND2, LOW); // other off  
  digitalWrite(GND3, LOW);  
  digitalWrite(GND4, LOW);  
  delay (1);  
  number = number%1000; // remainder of 1234/1000 is 234  
  digitalWrite(GND1, LOW); // first digit is off  
  showdigit(number/100); //// segments are set to display "2"  
  digitalWrite(GND2, HIGH); // second digit is on  
  delay (1); // and so on....  
  number =number%100;    
  digitalWrite(GND2, LOW);  
  showdigit(number/10);  
  digitalWrite(GND3, HIGH);  
  delay (1);  
  number =number%10;   
  digitalWrite(GND3, LOW);  
  showdigit(number);   
  digitalWrite(GND4, HIGH);  
  delay (1);  
 };   
 void setup()  
 {  
  pinMode(segA, OUTPUT);  
  pinMode(segB, OUTPUT);  
  pinMode(segC, OUTPUT);  
  pinMode(segD, OUTPUT);  
  pinMode(segE, OUTPUT);  
  pinMode(segF, OUTPUT);  
  pinMode(segG, OUTPUT);  
  pinMode(DP, OUTPUT);  
  pinMode(GND1, OUTPUT);  
  pinMode(GND2, OUTPUT);  
  pinMode(GND3, OUTPUT);  
  pinMode(GND4, OUTPUT);  
 };  
 void loop ()  
 {   
  timer++;  
  showdigits (i);  
  if (timer==10) {  
   timer=0;  
   i++;  
   if (i>10000) {  
    i=0;  
   };  
  };   
 };
 
