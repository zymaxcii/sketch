// onLed.ino
// Don't know what it does


const int buton=3;
volatile int sayac = 0;
volatile unsigned long sure=300;
const int INTbuton = 1; //interrupt1-INT1 Uno i�in Buton Pin3


void setup()
{
  // put your setup code here, to run once:
  pinMode(buton,INPUT);
  for (int i=4;i<14;i++)
  {
    pinMode(i,OUTPUT);
  }
  attachInterrupt(INTbuton, sureDegistir, RISING);
}


void sureDegistir()
{
  if (sayac < 5) {
    sayac = sayac + 1;
  }
  else {
    sayac = 1;
  }
  if (sayac == 1) {
    sure = 300;
  }
  if (sayac == 2) {
    sure = 700;
  }
  if (sayac == 3) {
    sure = 1000;
  }
  if (sayac == 4) {
    sure = 1500;
  }
  if (sayac == 5) {
    sure = 2000;
  }
}
unsigned long t0=0; //ba?lang?� zaman?
unsigned long t1;
unsigned long t2;
unsigned long t3;
unsigned long t4;
unsigned long t5;
unsigned long t6;
unsigned long t7;
unsigned long t8;
unsigned long t9;
unsigned long t10;
unsigned long t11;
unsigned long t12;
unsigned long t13;
unsigned long t14;
unsigned long t15;
unsigned long t16;
unsigned long t17;
unsigned long t18;
unsigned long t19;
unsigned long t20;
void loop() {
  unsigned long sureAralik;

do{
  t1=millis();
  sureAralik=t1-t0;
  }
while(sureAralik<sure);
digitalWrite(4,1);

do{
  t2=millis();
  sureAralik=t2-t1;
  }
while(sureAralik<sure);
digitalWrite(5,1);

do{
  t3=millis();
  sureAralik=t3-t2;
  }
while(sureAralik<sure);
digitalWrite(6,1);

do{
  t4=millis();
  sureAralik=t4-t3;
  }
while(sureAralik<sure);
digitalWrite(7,1);


do{
  t5=millis();
  sureAralik=t5-t4;
  }
while(sureAralik<sure);
digitalWrite(8,1);

do{
  t6=millis();
  sureAralik=t6-t5;
  }
while(sureAralik<sure);
digitalWrite(9,1);

do{
  t7=millis();
  sureAralik=t7-t6;
  }
while(sureAralik<sure);
digitalWrite(10,1);

do{
  t8=millis();
  sureAralik=t8-t7;
  }
while(sureAralik<sure);
digitalWrite(11,1);

do{
  t9=millis();
  sureAralik=t9-t8;
  }
while(sureAralik<sure);
digitalWrite(12,1);

do{
  t10=millis();
  sureAralik=t10-t9;
  }
while(sureAralik<sure);
digitalWrite(13,1);

do{
  t11=millis();
  sureAralik=t11-t10;
  }
while(sureAralik<sure);
digitalWrite(4,0);

do{
  t12=millis();
  sureAralik=t12-t11;
  }
while(sureAralik<sure);
digitalWrite(5,0);

do{
  t13=millis();
  sureAralik=t13-t12;
  }
while(sureAralik<sure);
digitalWrite(6,0);

do{
  t14=millis();
  sureAralik=t14-t13;
  }
while(sureAralik<sure);
digitalWrite(7,0);


do{
  t15=millis();
  sureAralik=t15-t14;
  }
while(sureAralik<sure);
digitalWrite(8,0);

do{
  t16=millis();
  sureAralik=t16-t15;
  }
while(sureAralik<sure);
digitalWrite(9,0);

do{
  t17=millis();
  sureAralik=t17-t16;
  }
while(sureAralik<sure);
digitalWrite(10,0);

do{
  t18=millis();
  sureAralik=t18-t17;
  }
while(sureAralik<sure);
digitalWrite(11,0);

do{
  t19=millis();
  sureAralik=t19-t18;
  }
while(sureAralik<sure);
digitalWrite(12,0);

do{
  t20=millis();
  sureAralik=t20-t19;
  }
while(sureAralik<sure);
digitalWrite(13,0);

}
