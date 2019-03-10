// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);
//   digitalWrite(LED_BUILTIN, HIGH);
//   pinMode(7, OUTPUT);
//   bool setupInProgress = true;
//   while
// }

// void loop() {
// //  for (int i = 0; i < 5; i += 1) {
// //    digitalWrite(LED_BUILTIN, HIGH);
// //    delay(500);
// //    digitalWrite(LED_BUILTIN, LOW);
// //    delay(500);
// //    printf("For loop");
// //  }
//   digitalWrite(7, HIGH);
//   delay(750);
//   digitalWrite(7, LOW);
//   delay(750);
// }


// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hey bolz");
}

void loop() {
  // Turn off the display:
//  lcd.noDisplay();
//  delay(500);
//  // Turn on the display:
//  lcd.display();
//  delay(500);
}