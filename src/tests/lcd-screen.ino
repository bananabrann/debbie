// Library for Arduino LCD library:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initializes the lcd screen. lcd.begin(col, row)
  lcd.begin(16, 2);
  lcd.print("loading...");
}

void loop() {
//  lcd.display();
  
  lcd.clear();
  lcd.print("Testing, 1, 2, 3...");
  delay(1000);
  lcd.clear();
  lcd.print("Ready!");
  delay(1000);
}