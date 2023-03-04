
int x=0;
int y=0;
int button=0;
#define xAxis A0
#define yAxis A1
#define theButton 7




void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(theButton,INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:

x = analogRead(xAxis);
y = analogRead(yAxis);
button = digitalRead(theButton);

/*
Serial.print("X position ");
Serial.print(x);
Serial.print("\T");

Serial.print("Y position ");
Serial.print(y);
Serial.print("\T");

Serial.print("Button ");

Serial.print(button);
Serial.println();
*/



if(x<470){
  Serial.println("UP");
}
  else if(x>500){
    Serial.println("DOWN");
  }
else {
  Serial.println("X Center");
}

if(y<480){
  Serial.println("RIGHT");
}
  else if(y>510){
    Serial.println("LEFT");
  }
else {
  Serial.println("Y Center");
}
Serial.println(button);
delay(500);

}


