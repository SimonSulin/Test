#include <Arduino.h>
#include <AccelStepper.h>
#include <LiquidCrystal.h>


#define CCW_PIN 9 //dir 
#define CW_PIN 8  //step
#define ENC_A 2   //encoder motor a
#define ENC_B 11   //encoder motor b 
#define btn_A 3  //encoder gumb a
#define btn_B 10  //encoder gumb b
#define btn 12

int stevilo=0;
boolean pb;

//BUTTON ENC
volatile int b_encoderPos;
unsigned int b_lastReportedPos = 1;

//ENCODER
volatile long m_encoderPos = 0;
unsigned int m_lastReportedPos = 1;


//LCD
const int rs = 7, en = 6, d4 = 18, d5 = 19, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


volatile bool ac_st=false;
unsigned long buttonPressStartTime = 0;
bool holdButton = false;

//STEPPER 
AccelStepper stepper(1, CW_PIN, CCW_PIN);
int x;





void m_doEncoder() {
  if (digitalRead(ENC_B)){
      m_encoderPos++;

   }
    else  {
      m_encoderPos--;
   }
}

void b_doEncoder() {
   if (stepper.isRunning()){
   if (digitalRead(btn_A)){
      b_encoderPos++;

   }
    else  {

      b_encoderPos--;
  }
}
}


void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(600.0);
  stepper.setAcceleration(600.0);
  lcd.begin(16, 2);
  lcd.print("lasko je zakon!!");

  pinMode(btn,INPUT_PULLUP);
  pinMode(ENC_A, INPUT_PULLUP); 
  pinMode(ENC_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), m_doEncoder, RISING );  
  attachInterrupt(digitalPinToInterrupt(3), b_doEncoder, CHANGE );  
  

}

void loop() {
if (m_lastReportedPos != m_encoderPos) {
Serial.println(m_encoderPos);
m_lastReportedPos = m_encoderPos;     
lcd.clear();
lcd.setCursor(0,0);
lcd.print(m_encoderPos); 
lcd.setCursor(0,1);
lcd.print(b_encoderPos);
}
 
if (b_lastReportedPos != b_encoderPos) {
Serial.println(b_encoderPos);
b_lastReportedPos = b_encoderPos;     
lcd.clear();
lcd.setCursor(0,0);
lcd.print(m_encoderPos); 
lcd.setCursor(0,1);
lcd.print(b_encoderPos);
}

if (digitalRead(btn) == LOW){
  x=x+500;
  stepper.moveTo(x);
   while (stepper.isRunning()) {
    stepper.run();
  }

  //stepper.moveTo(0);
//  while (stepper.isRunning()) {
//     stepper.run();
//   }

  Serial.println("ja");
} 
 
} 
