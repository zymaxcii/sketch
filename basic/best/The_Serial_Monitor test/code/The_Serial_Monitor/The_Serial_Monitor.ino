void setup() {
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
}

void loop() {
   // print out the value
  Serial.print("hi-");
 Serial.println("hello,world");
delay(300);//delay 300ms
}
