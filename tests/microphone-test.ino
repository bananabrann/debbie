// Library for Arduino LCD library:
#include <LiquidCrystal.h>
#define PIN_GATE_IN 8
#define IRQ_GATE_IN  0
#define PIN_LED_OUT 13
#define PIN_ANALOG_IN A0

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void soundISR()
{
    int pin_val;

    pin_val = digitalRead(PIN_GATE_IN);
    digitalWrite(PIN_LED_OUT, pin_val)
}
void setup() {

  Serial.being(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(IRQ_GATE_IN,soundISR, CHANGE);

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Debbie ON");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}