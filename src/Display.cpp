// #include <Arduino.h>
// #include <LiquidCrystal.h>

// #define btn_A  2 // encoder pin A
// #define btn_B 11  // encoder pin B
// #define btn 12     // push button on the encoder

// //ENCODER
// unsigned long _lastIncReadTime = micros(); 
// unsigned long _lastDecReadTime = micros(); 
// int _pauseLength = 25000;
// int _fastIncrement = 10;

// volatile int counter = 0;


// //DISPLAY
// unsigned long lastButtonPressTime = 0;
// unsigned long debounceDelay = 50;
// boolean rotating = false;
// boolean A_set = false;
// boolean B_set = false;
// int korak=1;
// boolean displ1_called = false;
// boolean displ2_called = false;


// //LCD
// const int rs = 7, en = 6, d4 = 18, d5 = 19, d6 = 4, d7 = 5;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



// void displ1 (){
//         lcd.print("Belt meter");
//         displ1_called = true;
//         displ2_called = false;  

// }


// void displ2 (){   
//         lcd.setCursor(0,0);
//         lcd.print("Izmeri dolzino");
//         lcd.setCursor(0,1);
//         lcd.print("Izberi sam");
//         displ2_called = true;
//         displ1_called = false;  

// }

// void read_encoder() {
//   // Encoder interrupt routine for both pins. Updates counter
//   // if they are valid and have rotated a full indent
 
//   static uint8_t old_AB = 3;  // Lookup table index
//   static int8_t encval = 0;   // Encoder value  
//   static const int8_t enc_states[]  = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0}; // Lookup table

//   old_AB <<=2;  // Remember previous state

//   if (digitalRead(btn_A)) old_AB |= 0x02; // Add current state of pin A
//   if (digitalRead(btn_B)) old_AB |= 0x01; // Add current state of pin B
  
//   encval += enc_states[( old_AB & 0x0f )];

//   // Update counter if encoder has rotated a full indent, that is at least 4 steps
//   if( encval > 3 ) {        // Four steps forward
//     int changevalue = 1;
//     if((micros() - _lastIncReadTime) < _pauseLength) {
//       changevalue = _fastIncrement * changevalue; 
//     }
//     _lastIncReadTime = micros();
//     counter = counter + changevalue;              // Update counter
//     encval = 0;
//   }
//   else if( encval < -3 ) {        // Four steps backward
//     int changevalue = -1;
//     if((micros() - _lastDecReadTime) < _pauseLength) {
//       changevalue = _fastIncrement * changevalue; 
//     }
//     _lastDecReadTime = micros();
//     counter = counter + changevalue;              // Update counter
//     encval = 0;
//   }
// } 

// void setup() {
//     Serial.begin(9600);
//     attachInterrupt(digitalPinToInterrupt(btn_A), read_encoder, CHANGE);
//     lcd.begin(16, 2);
//     pinMode(btn, INPUT_PULLUP); 
// }

// void loop() {
//     switch (korak){
//         case 1:
//             if (!displ1_called) {
//             displ1();
//             }
//             if (digitalRead(btn) == LOW && millis() - lastButtonPressTime > debounceDelay) {
//                 lastButtonPressTime = millis();
//                  if (digitalRead(btn) == LOW){
//                      korak = korak + 1;
//                  }
//             }
//             break;
//         case 2:
//         if (!displ2_called) {
//             displ2();
//         }
//         Serial.println(counter);
//             break;

//     }
// }
