/*
 * RS485 暂时没有定义，保留D12为RS485
*/

#include <util/atomic.h> // For the ATOMIC_BLOCK macro
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define RS485_DI 12 
//#define RS485_TX 11 
//#define RS485_RX 12 
//#define RS485_OE 8 

#define E_UP_VAL    -300  // 不同的电机，设置的数值是不同的,更换电机需要更换数值；该数值表示Encoder旋转的圈数，判断motor的当前位置，-表示反方向
#define E_DOWN_VAL   300  // 不同的电机，设置的数值是不同的,更换电机需要更换数值；该数值表示Encoder旋转的圈数，判断motor的当前位置，-表示反方向
#define E_LEFT_VAL  -5400 // 不同的电机，设置的数值是不同的,更换电机需要更换数值；该数值表示Encoder旋转的圈数，判断motor的当前位置，-表示反方向
#define E_RIGHT_VAL  5400 // 不同的电机，设置的数值是不同的,更换电机需要更换数值；该数值表示Encoder旋转的圈数，判断motor的当前位置，-表示反方向

#define ROUND_TIME 10     // 查找0点巡航时间
#define MAX_SPEED 55      //  左右方向motor最大速度 （0 to 255），0停止，255是最大值
#define MAX_SPEED_UD 35   //上方向motor最大速度 （0 to 255），0停止，255是最大值
#define MAX_SPEED_DOWN 80 //下方向motor最大速度 （0 to 255），0停止，255是最大值

#define UP_MAX_ANGLE 65      // 上方向最大角度65度，最大设置70
#define DOWN_MAX_ANGLE 55    // 上方向最大角度55度，最大设置70
#define LEFT_MAX_ANGLE 80    // 左方向最大角度80度，最大设置90
#define RIGHT_MAX_ANGLE 80   // 右方向最大角度80度，最大设置90



#define ENCA_UD 43 //编码器上下方向A mega2560的pin位
#define ENCB_UD 3  //编码器上下方向B mega2560的pin位 只能使用支持Interrupt——pin：2,3,18,19,20,21   20and21已经用于I2C口 for LCD2004 
#define ENCA_LR 41 //编码器左右方向A mega2560的pin位
#define ENCB_LR 18 //编码器左右方向B mega2560的pin位 只能使用支持Interrupt——pin：2,3,18,19,20,21   20and21已经用于I2C口 for LCD2004

#define BUTTON_UP 50 //MEGA_PIN
#define BUTTON_DW 51 //MEGA_PIN
#define BUTTON_LE 48 //MEGA_PIN
#define BUTTON_RT 49 //MEGA_PIN

#define LIMIT_UP 2 //MEGA_PIN
#define LIMIT_ZERO_UD 45 //MEGA_PIN
#define LIMIT_DW 4 //MEGA_PIN

#define LIMIT_LE 7 //MEGA_PIN
#define LIMIT_ZERO_LR 44 //MEGA_PIN
#define LIMIT_RT 8 //MEGA_PIN

/*PAN switch Normally open*/
#define RUN  0 
#define STOP 1

/*PAN switch Normally close*/
//#define RUN  1 
//#define STOP 0

#define PWM1_UD  9
#define PWM2_LR  10

int speed_ud=10,speed_lr=10;

long lasttime_speed_ud,lasttime_speed_lr;

bool button_up_state;
bool button_dw_state;
bool button_le_state;
bool button_rt_state;
bool limit_zero_ud_state;
bool limit_zero_lr_state;

bool button_up_state_last;
bool button_dw_state_last;
bool button_le_state_last;
bool button_rt_state_last;
bool limit_zero_ud_state_last;
bool limit_zero_lr_state_last;

long posi_ud = 0; 
long posi_lr = 0; 
long pos_ud = 0; 
long pos_lr = 0;
long pos_ud1 = 0; 
long pos_lr1 = 0;
long pos_ud_zero = 0; 
long pos_lr_zero = 0;

int mark_ud = 0;
int mark_lr = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(); //启动lcd2004
  lcd.backlight();//打开lcd2004背光
  lcd.setCursor(0, 0);//设置lcd2004输入起始位置为 0行第0位 
  lcd.print("hello, world!");//显示测试字符 helloword
    
  pinMode(BUTTON_UP,INPUT_PULLUP);//拉高按钮输入引脚
  pinMode(BUTTON_DW,INPUT_PULLUP);//拉高按钮输入引脚
  pinMode(BUTTON_LE,INPUT_PULLUP);//拉高按钮输入引脚
  pinMode(BUTTON_RT,INPUT_PULLUP);//拉高按钮输入引脚
  
  pinMode(ENCA_UD,INPUT_PULLUP);//拉高编码器输入引脚
  pinMode(ENCB_UD,INPUT_PULLUP);//拉高编码器输入引脚
  pinMode(ENCA_LR,INPUT_PULLUP);//拉高编码器输入引脚
  pinMode(ENCB_LR,INPUT_PULLUP);//拉高编码器输入引脚

  pinMode(LIMIT_ZERO_UD,INPUT);
  pinMode(LIMIT_ZERO_LR,INPUT);
   
  pinMode(LIMIT_UP,OUTPUT);
  pinMode(LIMIT_DW,OUTPUT);
  pinMode(LIMIT_LE,OUTPUT);
  pinMode(LIMIT_RT,OUTPUT);
  
  digitalWrite(LIMIT_UP,LOW);
  digitalWrite(LIMIT_DW,LOW);
  digitalWrite(LIMIT_LE,LOW);
  digitalWrite(LIMIT_RT,LOW);
  
//  goto_LR_00();//启用时，开机自动寻找左右方向0点，寻找时间由 ROUND_TIME 定义
//  goto_UD_00();//启用时，开机自动寻找上下方向0点，寻找时间由 ROUND_TIME 定义，默认不自动寻找
//  goto_00();   //开机同时寻找上下左右方向00点

  attachInterrupt(digitalPinToInterrupt(ENCB_UD),readEncoder_UD,RISING);//中断读取编码器
  attachInterrupt(digitalPinToInterrupt(ENCB_LR),readEncoder_LR,RISING);//中断读取编码器
}

void loop() {
 read_limitsw();//读取limitswitch
 read_button(); //读取button
 readENCODER(); //读取Encoder
 run_motor();   //驱动motor                        
 lcd_display(); //lcd2004屏显
}

void goto_LR_00(){
 long  lasttime_00lr = millis();
    while(1){
    read_limitsw();
    lcd.setCursor(0,1);
    lcd.print("Looking for L<0>R");
    lcd.setCursor(0,2);
    lcd.print("please waiting");
    lcd.setCursor(0,3);
    lcd.print("about 10s");
    if(limit_zero_lr_state == 1 - RUN){
      Serial.println("y = 0");
      lcd.clear();
      break;
      }
    
    if(limit_zero_lr_state == 1-STOP){
      if(millis()-lasttime_00lr < ROUND_TIME *1000){
        run_le_motor();
      }
      else if(millis()-lasttime_00lr < ROUND_TIME *2000){
        run_rt_motor();
        }
      else{
        run_lr_stop_motor();
        }   
      }
     else{
        run_lr_stop_motor();
      }
    }
  }

void goto_UD_00(){
 long  lasttime_00ud = millis();
    while(1){
    read_limitsw();
    lcd.setCursor(0,1);
    lcd.print("Looking for D<0>U");
    lcd.setCursor(0,2);
    lcd.print("please waiting");
    lcd.setCursor(0,3);
    lcd.print("about 10s");
    
    if(limit_zero_ud_state == 1 - RUN){
      Serial.println("y = 0");
      lcd.clear();
      break;
      }
    if(limit_zero_ud_state == 1-STOP){//Y != 0
      if(millis()-lasttime_00ud < ROUND_TIME *1000){
        run_up_motor();
      }
      else if(millis()-lasttime_00ud <  ROUND_TIME *2000){
        run_dw_motor();
        }
      else{
        run_ud_stop_motor();
        }   
      }
     else{
        run_ud_stop_motor();
      }
    }
  }  
void goto_00(){
 long  lasttime_00ud = millis();
 long  lasttime_00lr = millis();
    while(1){
    read_limitsw();
    lcd.setCursor(0,1);
    lcd.print("Looking for (0,0)");
    lcd.setCursor(0,2);
    lcd.print("please waiting");
    
    if(limit_zero_ud_state == 1 - RUN && limit_zero_lr_state == 1 - RUN){
      Serial.println("x = 0 and y = 0");
      lcd.clear();
      break;
      }
    if(limit_zero_ud_state == 1-STOP){//Y != 0
      if(millis()-lasttime_00ud < ROUND_TIME *1000){
        run_up_motor();
      }
      else if(millis()-lasttime_00ud <  ROUND_TIME *2000){
        run_dw_motor();
        }
      else{
        run_ud_stop_motor();
        }   
      }
     else{
        run_ud_stop_motor();
      }

    if(limit_zero_lr_state == 1-STOP){//x != 0
      if(millis()-lasttime_00lr < ROUND_TIME *1000){
        run_le_motor();
      }
      else if(millis()-lasttime_00lr < ROUND_TIME *2000){
        run_rt_motor();
        }
      else{
        run_lr_stop_motor();
        }   
      }
     else{
        run_lr_stop_motor();
      }
    }
  }
void run_up_motor(){
 if(millis()-lasttime_speed_ud>1){//speed++
    speed_ud=speed_ud+1;
    lasttime_speed_ud = millis();
    if(speed_ud > MAX_SPEED_UD){speed_ud = MAX_SPEED_UD;} 
 }
  analogWrite(PWM1_UD,speed_ud);
  digitalWrite(LIMIT_UP,HIGH);
  digitalWrite(LIMIT_DW,LOW);
  }
void run_ud_stop_motor(){
  speed_ud = 10;
  analogWrite(PWM1_UD,speed_ud);
  digitalWrite(LIMIT_UP,LOW);
  digitalWrite(LIMIT_DW,LOW);
  }
void run_dw_motor(){
  if(millis()-lasttime_speed_ud>1){
   speed_ud=speed_ud+2;
   lasttime_speed_ud = millis();
   if(speed_ud > MAX_SPEED_DOWN){speed_ud = MAX_SPEED_DOWN;} 
 }
  analogWrite(PWM1_UD,speed_ud);
  digitalWrite(LIMIT_UP,LOW);
  digitalWrite(LIMIT_DW,HIGH);
  }
void run_le_motor(){  
  if(millis()-lasttime_speed_lr>1){
    speed_lr++;
     if(speed_lr>MAX_SPEED){speed_lr = MAX_SPEED;} 
      lasttime_speed_lr = millis();
  }
  analogWrite(PWM2_LR,speed_lr);
  digitalWrite(LIMIT_LE,HIGH);
  digitalWrite(LIMIT_RT,LOW);
  }    
void run_lr_stop_motor(){  
  speed_lr = 10;
  analogWrite(PWM2_LR,speed_lr);
  digitalWrite(LIMIT_LE,LOW);
  digitalWrite(LIMIT_RT,LOW);
  }    
void run_rt_motor(){  
  if(millis()-lasttime_speed_lr>1){
    speed_lr=speed_lr+4;
    if(speed_lr>MAX_SPEED){speed_lr = MAX_SPEED;}
      lasttime_speed_lr = millis();
  }
  analogWrite(PWM2_LR,speed_lr);
  digitalWrite(LIMIT_LE,LOW);
  digitalWrite(LIMIT_RT,HIGH);
  }



  
void run_motor(){ 
   
      if(button_up_state == RUN && button_dw_state == STOP && pos_ud < UP_MAX_ANGLE){//UP 
     Serial.println("go up");
          run_up_motor();
        }
      else if(button_up_state == STOP && button_dw_state == RUN && pos_ud > ((-1) * DOWN_MAX_ANGLE)){ //DOWN
     Serial.println("go down");
          run_dw_motor();
        }
      else{
//      Serial.println("stop updown");     
          run_ud_stop_motor();
        }

      if(button_le_state == RUN && button_rt_state == STOP && pos_lr > (-1) * LEFT_MAX_ANGLE){  //LEFT
          run_le_motor();
          Serial.println("go left");
        }
      else if(button_le_state == STOP && button_rt_state == RUN && pos_lr < RIGHT_MAX_ANGLE ){ //RIGHT
          run_rt_motor();
           Serial.println("go right");
        }
      else{
//         Serial.println("stop leftright");
        run_lr_stop_motor();
        }

}    
void read_limitsw(){
   limit_zero_ud_state_last = limit_zero_ud_state;
   limit_zero_lr_state_last = limit_zero_lr_state;
   limit_zero_ud_state = digitalRead(LIMIT_ZERO_UD);
   limit_zero_lr_state = digitalRead(LIMIT_ZERO_LR);
    if(limit_zero_ud_state == STOP){
      posi_ud=0;
      }

    if(limit_zero_lr_state == STOP){
      posi_lr=0;
      }  
//  if(limit_zero_ud_state == 1 && limit_zero_ud_state_last==0){
//      Serial.print("zero ud = ");
//    Serial.println(limit_zero_ud_state);
//  }
//  if(limit_zero_lr_state == 1 && limit_zero_lr_state_last==0){  
//    
//      Serial.print("zero lr = ");
//    Serial.println(limit_zero_lr_state);
//  }
//    delay(200);
  }  
void read_button(){
   button_up_state_last = button_up_state;
   button_dw_state_last = button_dw_state;
   button_le_state_last = button_le_state;
   button_rt_state_last = button_rt_state;
 
   button_up_state = digitalRead(BUTTON_UP);
   button_dw_state = digitalRead(BUTTON_DW);
   button_le_state = digitalRead(BUTTON_LE);
   button_rt_state = digitalRead(BUTTON_RT);

//Serial.print(button_up_state);
//Serial.print(button_dw_state);
//Serial.print(button_le_state);
//Serial.println(button_rt_state);
//delay(100);
// if(button_up_state == 1-RUN && button_dw_state == 1-RUN){
//  Serial.println("UP DOWN Button   failure!!!");
//  }
// if(button_le_state == 1-RUN && button_rt_state == 1-RUN){
//  Serial.println("LEFT RIGHT Button  failure!!!");
//  } 
 }
void lcd_display(){
 if( button_up_state_last != button_up_state)lcd.clear();
 if( button_dw_state_last != button_dw_state)lcd.clear();
 if( button_le_state_last != button_le_state)lcd.clear();
 if( button_rt_state_last != button_rt_state)lcd.clear();
 if( limit_zero_ud_state_last != limit_zero_ud_state)lcd.clear();
 if( limit_zero_lr_state_last != limit_zero_lr_state)lcd.clear();
      
  
  lcd.setCursor(0,0);
  lcd.print("current position:");
  
  lcd.setCursor(0,1);
  lcd.print("TILT=");

//pos_ud = -10;   //-90~90
//pos_lr = 90;  //-90~90
  
  if(pos_ud > 0){
    lcd.print(" UP    ");
  }else if(pos_ud < 0){
    lcd.print(" DOWN  ");
  }
  else{
    lcd.print("      "); 
   }
  lcd.print(abs(pos_ud));


//  lcd.print(pos_ud);
  lcd.print("      ");

  
  lcd.setCursor(0,2);
  lcd.print("PAN =");
  
  if(pos_lr < 0){
    lcd.print(" LEFT  ");
  }else if(pos_lr > 0){
    lcd.print(" RIGHT ");
  }else{
    lcd.print("      ");
    }
  lcd.print(abs(pos_lr));

//  lcd.print(pos_lr);
  lcd.print("     ");
  
  lcd.setCursor(0,3);
  
//  if(limit_zero_ud_state  == 1-RUN){lcd.print(" TILT = 0");}
//  if(limit_zero_lr_state  == 1-RUN){lcd.print(" PAN = 0");}
}

void readENCODER() {
   pos_ud = 0; 
   pos_lr = 0;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos_ud = posi_ud;
    pos_lr = posi_lr;
    pos_ud1 = posi_ud;
    pos_lr1 = posi_lr;
  }
  
//  pos_ud = map(pos_ud,-300,300,90,-90);// to 0~90 angle   up<------>down
//  pos_lr = map(pos_lr,-5400,5400,90,-90);// to 0~90 angle  right<--->left
  pos_ud = map(pos_ud,E_UP_VAL,E_DOWN_VAL,90,-90);// to 0~90 angle   up<------>down
  pos_lr = map(pos_lr,E_LEFT_VAL,E_RIGHT_VAL,90,-90);// to 0~90 angle  right<--->left
 
  if(pos_lr<(-90)){pos_lr=(-90);}
  if(pos_lr>90){pos_lr=90;}
  if(pos_ud<(-90)){pos_ud=(-90);}
  if(pos_ud>90){pos_ud=90;}
//  Serial.print(pos_ud);
//  Serial.print("  ");
//  Serial.print(pos_lr);
//  Serial.println();
}
void readEncoder_UD(){
  int b = digitalRead(ENCA_UD);
//  Serial.println(b); 
  if(b > 0){
    posi_ud++;
  }
  else{
    posi_ud--;
  }
}

void readEncoder_LR(){
  int b = digitalRead(ENCA_LR);
  if(b > 0){
    posi_lr++;
  }
  else{
    posi_lr--;
  }
}
