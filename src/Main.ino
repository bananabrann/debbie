#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int soundSensor = 6;
int soundLED = 13;
int analogPinZero = A0;

void setup()
{
    Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.print("listening...");

    pinMode(soundSensor, INPUT);
    pinMode(soundLED, OUTPUT);
}

void loop()
{
    int statusSensor = digitalRead(soundSensor);
    int receivingValue = analogRead(analogPinZero);
    int lastReceivedReading;

    if (statusSensor == 1)
    {
        lcd.display();
        lcd.clear();
        digitalWrite(soundLED, HIGH);

        Serial.println(receivingValue);

        lcd.print("Reading is ");
        lcd.print(receivingValue);

        delay(600);
        lcd.clear();
    }
    else
    {
        digitalWrite(soundLED, LOW);

        lcd.print("Last reading: ");
        lcd.print(receivingValue);

        // Without this delay, the light will turn on and remain on.
        delay(0050);
    }
}