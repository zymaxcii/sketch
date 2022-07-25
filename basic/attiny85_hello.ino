// attiny85_hello.ino
// https://www.nu42.com/2021/02/attiny85-chirper-red-keys-liyafy-hc35.html


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
// VCC <-> SRCLR (10)
// VCC <-> OE (13)
// VCC <-> VCC (16)

// PB0 (5) <-> RCLK (12)
// ST_CP / latch / Storage register clock pin in tutorial
static const int rclk_out = 0;

// PB1 (6) <-> SRCLK (11)
// SH_CP / Shift register clock pin in tutorial
static const int srclk_out = 1;

// PB2 (7) <-> SER (14)
// DS / Serial data input in tutorial
static const int ser_out = 2;

void setup() {
  delay(250); // let things settle
  pinMode(rclk_out, OUTPUT);
  pinMode(srclk_out, OUTPUT);
  pinMode(ser_out, OUTPUT);
  delay(250);
  digitalWrite(ser_out, 255); // lights off to start
}

void led_out(int b) {
  digitalWrite(rclk_out, LOW); // so LEDs don't change while the bits are being transmitted
  shiftOut(ser_out, srclk_out, LSBFIRST, b); // send the data
  digitalWrite(rclk_out, HIGH); // make the new eight bits available
}

void one_at_a_time() {
  // Light up each LED once
  // Should take about a second
  for (int i = 0; i < 8; ++i) {
    led_out(~(1 << i));
    delay(125);
  }
}

void all_combos() {
  // Count from 0 to 255 in a fraction under a minute
  for (int i = 0; i < 256; ++i) {
    led_out(~i);
    delay(234);
  }
  led_out(255);
}

void blink_all() {
  // Rapid blinking for five seconds
  for (int i = 0; i < 50; ++i) {
    led_out(0);
    delay(50);
    led_out(255);
    delay(50);
  }
  led_out(255);
}

void loop() {
  delay(1000); // wait a little before the show
  one_at_a_time();
  delay(1000);
  all_combos();
  delay(1000);
  blink_all();
}
