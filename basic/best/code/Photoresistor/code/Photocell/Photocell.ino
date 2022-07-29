int light=0;//Define the analog interface 0 connect the photosensitive resistance
int led=11;//Define digital interface 11 output PWM adjust LED brightness
int val=0;//Defined variable val
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);//Define digital interface 11 for output
}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(light);//Read the sensor's analog values and assign to val
analogWrite(led,val);// Turn on the LED and set the brightness (the maximum value of the PWM output is 255)
delay(10);//Delay 0.01 seconds
}
