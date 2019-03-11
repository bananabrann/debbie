#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int soundSensor = 6;
int soundLED = 13;

void setup() {
  lcd.begin(16, 2);
  lcd.print("listening...");
  pinMode (soundSensor, INPUT);
  pinMode (soundLED, OUTPUT);
}

void loop() {
  int statusSensor = digitalRead (soundSensor);
  if (statusSensor == 1)
  {
    digitalWrite(soundLED, HIGH);
  }
    else 
    {
      digitalWrite(soundLED, LOW);
      delay(100);
      // Without this delay, the light will turn on and remain on.
    }
}
  