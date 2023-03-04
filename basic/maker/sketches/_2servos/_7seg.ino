
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
int wait = 1;

void numOne(){
  digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
  digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
}

void numTwo(){
   digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
   digitalWrite(e,HIGH);
  delay(wait);
  digitalWrite(e,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
}
 void numThree(){
   digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
 }

void numFour(){
  digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
  digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
  digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
  digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
}

void numFive(){
  digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
}

void numSix(){
  digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
   digitalWrite(e,HIGH);
  delay(wait);
  digitalWrite(e,LOW);
  delay(wait);
}

void numSeven(){
   digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
  digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
  digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
}


void numEight(){
   digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
   digitalWrite(e,HIGH);
  delay(wait);
  digitalWrite(e,LOW);
  delay(wait);
  digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
}

void numNine(){
   digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
   digitalWrite(g,HIGH);
  delay(wait);
  digitalWrite(g,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
     digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
}

void numZero(){
   digitalWrite(a,HIGH);
  delay(wait);
  digitalWrite(a,LOW);
  delay(wait);
   digitalWrite(f,HIGH);
  delay(wait);
  digitalWrite(f,LOW);
  delay(wait);
   digitalWrite(c,HIGH);
  delay(wait);
  digitalWrite(c,LOW);
  delay(wait);
   digitalWrite(d,HIGH);
  delay(wait);
  digitalWrite(d,LOW);
  delay(wait);
   digitalWrite(e,HIGH);
  delay(wait);
  digitalWrite(e,LOW);
  delay(wait);
  digitalWrite(b,HIGH);
  delay(wait);
  digitalWrite(b,LOW);
  delay(wait);
}

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=0;i<200;i++){
  numZero();
}
for(int i=0;i<200;i++){
  numOne();
}
for(int i=0;i<200;i++){
  numTwo();
}
for(int i=0;i<200;i++){
  numThree();
}
for(int i=0;i<200;i++){
  numFour();
}
for(int i=0;i<200;i++){
  numFive();
}
for(int i=0;i<200;i++){
  numSix();
}
for(int i=0;i<200;i++){
  numSeven();
}
for(int i=0;i<200;i++){
  numEight();
}
for(int i=0;i<200;i++){
  numNine();
}
}
