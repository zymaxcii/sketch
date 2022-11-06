// https://www.nu42.com/2021/01/attiny85-liyafy-hc-35-8-led-keypad-serial-in-parallel-out-shift-register.html

// Adapted sample code in https://www.arduino.cc/en/Tutorial/Foundations/ShiftOut
// Code sample 1: Hello World https://www.arduino.cc/en/Tutorial/ShftOut11

// ATtiny85    SN74HC595
// ----------------------
// PB0 (5) <-> RCLCK (12)
// PB1 (6) <-> SRCLK (11)
// PB2 (7) <-> SER (14)

// ATtiny85
// --------
// 5V  <-> VCC(8)
// GND <-> GND(4)

// SN74HC595
// ---------
// GND <-> GND (8)
// GND <-> SRCLR (10)
// 

// PB0 (5) <-> RCLK (12) ST_CP / latch / Storage register clock pin in tutorial
int rclk_out = 0;
// PB1 (6) <-> SRCLK (11) SH_CP / Shift register clock pin in tutorial
 int srclk_out = 1;
// PB2 (7) <-> SER (14) DS / Serial data input in tutorial 
int ser_out = 2;

void setup() {
  pinMode(rclk_out, OUTPUT);
  pinMode(srclk_out, OUTPUT);
  pinMode(ser_out, OUTPUT);
}

void led_out(int b) {
  digitalWrite(rclk_out, LOW); // so LEDs don't change while the bits are being transmitted
  shiftOut(ser_out, srclk_out, LSBFIRST, b); // send the data
  digitalWrite(rclk_out, HIGH); // make the new eight bits available
}

void one_at_a_time() {
  for (int i = 0; i < 7; ++i) {
    led_out(1 << i);
    delay(500);
  }  
}

void all_combos() {
  for (int i = 0; i < 256; ++i) {
    led_out(i);
    delay(500);
  }
}

void blink_all() {
  for (int i = 0; i < 100; ++i) {
    led_out(0);
    delay(250);
    led_out(255);
    delay(250);
  }
}

void loop() {
  one_at_a_time();
  delay(1000);
  all_combos();
  delay(1000);
  blink_all();
  delay(1000);
}
