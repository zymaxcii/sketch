// 8ledsr_lightup1.ino
// light up 1 led
// uses basic control in functions
// https://microcontrollerslab.com/74hc595-shift-register-interfacing-arduino/

// 74HC595 pins DS, ST_CP, SH_CP: 14, 12, 11 (data, storage, shift register)
// pin headers bottom to top:
// 11 SH_CP D8
// 12 ST_CP D7
// 14 DS    D6
int clockpin = 8;
int latchpin = 7;
int datapin  = 6;     // bottom pin

int delayTime = 100;

void clock_signal(void)
{
  digitalWrite(clockpin, HIGH);
  delayMicroseconds(500);
  digitalWrite(clockpin, LOW);
  delayMicroseconds(500);
}


void latch_enable(void)
{
  digitalWrite(latchpin, HIGH);
  delayMicroseconds(500);
  digitalWrite(latchpin, LOW);
}
  
  
void send_data(unsigned int data_out)
{
  int i;
  unsigned hold;
  
  for (i=0 ; i<8 ; i++)
  {
    if ((data_out >> i) & (0x01))
      digitalWrite(datapin,HIGH); 
    else
      digitalWrite(datapin,LOW); 
        
    clock_signal();
  }
  latch_enable(); // Data finally submitted
}


void setup() 
{
  pinMode(latchpin , OUTPUT);
  pinMode(datapin ,  OUTPUT);
  pinMode(clockpin , OUTPUT);
  digitalWrite(latchpin, LOW); 
  digitalWrite(clockpin, LOW); 
  digitalWrite(datapin,  LOW);
  Serial.begin(9600);
}


void loop() 
{
  send_data(0b00000000);
  delay(delayTime);
  send_data(0b10000000);
  delay(delayTime);
  send_data(0b01000000);
  delay(delayTime);
  send_data(0b00100000);
  delay(delayTime);
  send_data(0b00010000);
  delay(delayTime);
  send_data(0b00001000);
  delay(delayTime);
  send_data(0b00000100);
  delay(delayTime);
  send_data(0b00000010);
  delay(delayTime);
  send_data(0b00000001);
  delay(delayTime);
}
