#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS      24
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);









void setup() {
  // put your setup code here, to run once:

 pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'

}

void xmas1(){
  for(int i=0; i<6; i++){
  pixels.setPixelColor(i, pixels.Color(25,0,0));
  pixels.show();
  delay(50);
}
for(int i=12; i<18; i++){
  pixels.setPixelColor(i, pixels.Color(25,0,0));
  pixels.show();
  delay(50);
}

for(int i=6; i<12; i++){
  pixels.setPixelColor(i, pixels.Color(0,25,0));
  pixels.show();
  delay(50);
}

for(int i=18; i<24; i++){
  pixels.setPixelColor(i, pixels.Color(0,25,0));
  pixels.show();
  delay(50);
}
for(int i=24; i>=0; i--){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
  pixels.show();
  delay(25);
}
}


void halfnhalf(){
  pixels.setPixelColor(0, pixels.Color(50,0,0));
  pixels.setPixelColor(23, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(1, pixels.Color(50,0,0));
  pixels.setPixelColor(22, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(2, pixels.Color(50,0,0));
  pixels.setPixelColor(21, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(3, pixels.Color(50,0,0));
  pixels.setPixelColor(20, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(4, pixels.Color(50,0,0));
  pixels.setPixelColor(19, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(5, pixels.Color(50,0,0));
  pixels.setPixelColor(18, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(6, pixels.Color(50,0,0));
  pixels.setPixelColor(17, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(7, pixels.Color(50,0,0));
  pixels.setPixelColor(16, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(8, pixels.Color(50,0,0));
  pixels.setPixelColor(15, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(9, pixels.Color(50,0,0));
  pixels.setPixelColor(14, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(10, pixels.Color(50,0,0));
  pixels.setPixelColor(13, pixels.Color(0,50,0));
  pixels.show();
  delay(50);

  pixels.setPixelColor(11, pixels.Color(50,0,0));
  pixels.setPixelColor(12, pixels.Color(0,50,0));
  pixels.show();
  delay(2000);

  for(int i=24; i>=0; i--){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
  pixels.show();
  delay(25);

  } 
}









void xmas2(){
  for (int i=0; i<25; i++){
     pixels.setPixelColor(i, pixels.Color(25,0,0));
    pixels.show();
    delay(25);
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
for (int i=0; i<25; i++){
     pixels.setPixelColor(i, pixels.Color(0,25,0));
    pixels.show();
    delay(25);
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
}

void xmasFade(){
  for (int i = 0; i <100; i++){
    pixels.setPixelColor(0, pixels.Color(i,0,0));
    pixels.setPixelColor(1, pixels.Color(i,0,0));
    pixels.setPixelColor(2, pixels.Color(i,0,0));
    pixels.setPixelColor(3, pixels.Color(i,0,0));
    pixels.setPixelColor(4, pixels.Color(i,0,0));
    pixels.setPixelColor(5, pixels.Color(i,0,0));
    pixels.setPixelColor(6, pixels.Color(i,0,0));
    pixels.setPixelColor(7, pixels.Color(i,0,0));
    pixels.setPixelColor(8, pixels.Color(i,0,0));
    pixels.setPixelColor(9, pixels.Color(i,0,0));
    pixels.setPixelColor(10, pixels.Color(i,0,0));
    pixels.setPixelColor(11, pixels.Color(i,0,0));
    pixels.setPixelColor(12, pixels.Color(i,0,0));
    pixels.setPixelColor(13, pixels.Color(i,0,0));
    pixels.setPixelColor(14, pixels.Color(i,0,0));
    pixels.setPixelColor(15, pixels.Color(i,0,0));
    pixels.setPixelColor(16, pixels.Color(i,0,0));
    pixels.setPixelColor(17, pixels.Color(i,0,0));
    pixels.setPixelColor(18, pixels.Color(i,0,0));
    pixels.setPixelColor(19, pixels.Color(i,0,0));
    pixels.setPixelColor(20, pixels.Color(i,0,0));
    pixels.setPixelColor(21, pixels.Color(i,0,0));
    pixels.setPixelColor(22, pixels.Color(i,0,0));
    pixels.setPixelColor(23, pixels.Color(i,0,0));
    pixels.show();
    delay(100);
  }
    delay(500);
    for (int i = 1; i <25; i++){
    pixels.setPixelColor(0, pixels.Color(0,i,0));
    pixels.setPixelColor(1, pixels.Color(0,i,0));
    pixels.setPixelColor(2, pixels.Color(0,i,0));
    pixels.setPixelColor(3, pixels.Color(0,i,0));
    pixels.setPixelColor(4, pixels.Color(0,i,0));
    pixels.setPixelColor(5, pixels.Color(0,i,0));
    pixels.setPixelColor(6, pixels.Color(0,i,0));
    pixels.setPixelColor(7, pixels.Color(0,i,0));
    pixels.setPixelColor(8, pixels.Color(0,i,0));
    pixels.setPixelColor(9, pixels.Color(0,i,0));
    pixels.setPixelColor(10, pixels.Color(0,i,0));
    pixels.setPixelColor(11, pixels.Color(0,i,0));
    pixels.setPixelColor(12, pixels.Color(0,i,0));
    pixels.setPixelColor(13, pixels.Color(0,i,0));
    pixels.setPixelColor(14, pixels.Color(0,i,0));
    pixels.setPixelColor(15, pixels.Color(0,i,0));
    pixels.setPixelColor(16, pixels.Color(0,i,0));
    pixels.setPixelColor(17, pixels.Color(0,i,0));
    pixels.setPixelColor(18, pixels.Color(0,i,0));
    pixels.setPixelColor(19, pixels.Color(0,i,0));
    pixels.setPixelColor(20, pixels.Color(0,i,0));
    pixels.setPixelColor(21, pixels.Color(0,i,0));
    pixels.setPixelColor(22, pixels.Color(0,i,0));
    pixels.setPixelColor(23, pixels.Color(0,i,0));
    pixels.show();
    delay(100);
  }


}

void xmasFill(){
  for(int red=0; red<25; red = red+2){
    pixels.setPixelColor(red, pixels.Color(50,0,0));
    pixels.show();
    delay(100);
  }
  for(int green=1; green<25; green = green+2){
    pixels.setPixelColor(green, pixels.Color(0,50,0));
    pixels.show();
    delay(100);
  }
delay(1000);
  for(int i=24; i>=0; i--){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
  pixels.show();
  delay(25);
}
}









void loop() {

xmas1();
delay(1000);


xmas2();
delay(1000);






xmasFade();
delay(1000);


xmasFill();
delay(1000);


halfnhalf();

delay(1000);







}
