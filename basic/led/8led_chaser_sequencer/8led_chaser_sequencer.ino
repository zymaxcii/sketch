// 8led_chaser_sequencer.ino
// https://www.engineersgarage.com/articles-arduino-led-chaser-sequencer-13-light-patterns/


// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
// #define led0 6
// #define led1 7
// #define led2 8
// #define led3 9
// #define led4 10
// #define led5 11
// #define led6 12
// #define led7 13

// with nano and the 8 led module
#define led0 5
#define led1 6
#define led2 7
#define led3 8
#define led4 9
#define led5 10
#define led6 11
#define led7 12



int delayTime1 = 300;
int delayTime2 = 200;
int delayTime3 = 100;


void setup() 
{
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}


void loop()
{
  //Pattern 01
  digitalWrite(led0, LOW); delay(delayTime1);
  digitalWrite(led1, LOW); delay(delayTime1);
  digitalWrite(led2, LOW); delay(delayTime1);
  digitalWrite(led3, LOW); delay(delayTime1);
  digitalWrite(led5, LOW); delay(delayTime1);
  digitalWrite(led6, LOW); delay(delayTime1);
  digitalWrite(led7, LOW); delay(delayTime1);
  
  digitalWrite(led0, HIGH); delay(delayTime2);
  digitalWrite(led1, HIGH); delay(delayTime2);
  digitalWrite(led2, HIGH); delay(delayTime2);
  digitalWrite(led3, HIGH); delay(delayTime2);
  digitalWrite(led5, HIGH); delay(delayTime2);
  digitalWrite(led6, HIGH); delay(delayTime2);
  digitalWrite(led7, HIGH); delay(delayTime2);

  //Pattern 02
  digitalWrite(led7, LOW); delay(delayTime1);
  digitalWrite(led6, LOW); delay(delayTime1);
  digitalWrite(led5, LOW); delay(delayTime1);
  digitalWrite(led3, LOW); delay(delayTime1);
  digitalWrite(led2, LOW); delay(delayTime1);
  digitalWrite(led1, LOW); delay(delayTime1);
  digitalWrite(led0, LOW); delay(delayTime1);
  
  digitalWrite(led7, HIGH); delay(delayTime2);
  digitalWrite(led6, HIGH); delay(delayTime2);
  digitalWrite(led5, HIGH); delay(delayTime2);
  digitalWrite(led3, HIGH); delay(delayTime2);
  digitalWrite(led2, HIGH); delay(delayTime2);
  digitalWrite(led1, HIGH); delay(delayTime2);
  digitalWrite(led0, HIGH); delay(delayTime2);

  //Pattern 03
  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep1  

  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep2  

  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep3  

  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep4  

  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep5  

  digitalWrite(led7, LOW);  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW);  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);  delay(delayTime1);  

  digitalWrite(led7, HIGH); digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); delay(delayTime1); //Rep6  

  digitalWrite(led7, LOW); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW); 
  delay(delayTime1);  

  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); 
  delay(delayTime1); //Rep7  

  digitalWrite(led7, LOW); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW); 
  delay(delayTime1);  

  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW); 
  digitalWrite(led0, HIGH); 
  delay(delayTime1); //Rep8  

  digitalWrite(led6, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led1, HIGH); 
  delay(delayTime2);  

  //Pattern 04
  digitalWrite(led0, LOW); 
  delay(delayTime1);
  digitalWrite(led1, LOW); 
  delay(delayTime1);
  digitalWrite(led2, LOW); 
  delay(delayTime1);
  digitalWrite(led3, LOW); 
  delay(delayTime1);
  digitalWrite(led5, LOW); 
  delay(delayTime1);
  digitalWrite(led6, LOW); 
  delay(delayTime1);
  digitalWrite(led7, LOW); 
  delay(delayTime1);
    
  digitalWrite(led7, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  delay(delayTime2);  

  //Pattern 05
  digitalWrite(led7, LOW); 
  delay(delayTime1);
  digitalWrite(led6, LOW); 
  delay(delayTime1);
  digitalWrite(led5, LOW); 
  delay(delayTime1);
  digitalWrite(led3, LOW); 
  delay(delayTime1);
  digitalWrite(led2, LOW); 
  delay(delayTime1);
  digitalWrite(led1, LOW); 
  delay(delayTime1);
  digitalWrite(led0, LOW); 
  delay(delayTime1);
    
  digitalWrite(led0, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  delay(delayTime2);  

  //Pattern 06
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 1  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 2  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 3  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 4  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 5  

  //Pattern 07
  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
    
  digitalWrite(led0, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  delay(delayTime2);  

  //Pattern 08
  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led0, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  delay(delayTime2);  

  //Pattern 09
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep1    

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep2   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep3   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep4   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep5   

  //Pattern 10
  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, LOW); 
  delay(delayTime3);
    
  digitalWrite(led7, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  delay(delayTime2);  

  //Pattern 11
  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime3);
  digitalWrite(led1, HIGH);
  digitalWrite(led0, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime3);  

  digitalWrite(led7, LOW); 
  delay(delayTime3);  

  digitalWrite(led0, HIGH); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  delay(delayTime2);  

  //Pattern 06 Repeat
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 1  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 2  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 3  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 4  

  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3);  
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3);   
  digitalWrite(led3, LOW); 
  delay(delayTime3);     

  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3);  
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3);   
  digitalWrite(led3, HIGH); 
  delay(delayTime3); //Rep 5  

  //Pattern 12
  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);  

  digitalWrite(led0, LOW); 
  delay(delayTime2);
    
  digitalWrite(led7, HIGH); 
  delay(delayTime2);  

  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  digitalWrite(led5, HIGH); 
  digitalWrite(led6, LOW);
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW);
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, LOW);
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW);
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, LOW);
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  digitalWrite(led1, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW);
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, LOW);
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  digitalWrite(led0, HIGH); 
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, LOW);
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, LOW);
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led7, LOW);
  delay(delayTime2);
  digitalWrite(led7, HIGH);
  delay(delayTime2);  

  //Pattern 13
  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime2);
  digitalWrite(led1, HIGH);
  digitalWrite(led0, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime2);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);  

  digitalWrite(led7, LOW); 
  delay(delayTime2);
    
  digitalWrite(led0, HIGH); 
  delay(delayTime2);  

  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW);
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW);
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW);
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW);
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  digitalWrite(led7, HIGH); 
  digitalWrite(led6, LOW); 
  delay(delayTime2);
  digitalWrite(led6, HIGH); 
  digitalWrite(led5, LOW); 
  delay(delayTime2);
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, LOW);
  delay(delayTime2);
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, LOW);
  delay(delayTime2);
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, LOW);
  delay(delayTime2);
  digitalWrite(led1, HIGH); 
  digitalWrite(led0, LOW);
  delay(delayTime2);
  digitalWrite(led0, HIGH);
  delay(delayTime2);  

  //Pattern 09 Repeat
  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep1    

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep2   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep3   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep4   

  digitalWrite(led3, LOW); 
  delay(delayTime3);
  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW);
  delay(delayTime3); 
  digitalWrite(led1, LOW); 
  digitalWrite(led6, LOW);
  delay(delayTime3); 
  digitalWrite(led0, LOW); 
  digitalWrite(led7, LOW);
  delay(delayTime3); 
   
  digitalWrite(led3, HIGH); 
  delay(delayTime3);
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH);
  delay(delayTime3); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH);
  delay(delayTime3); 
  digitalWrite(led0, HIGH); 
  digitalWrite(led7, HIGH);
  delay(delayTime3); //Rep5 
}
