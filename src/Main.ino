#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// int soundSensor = 6;
int microphoneGate = 6;
// int soundLED = 13;
int microphoneLED = 13;

int microphoneEnvelope = A0;

void setup()
{
    Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.print("listening...");

    pinMode(microphoneGate, INPUT);
    pinMode(microphoneLED, OUTPUT);
}

void loop()
{
    interrupts();

    int statusSensor = digitalRead(microphoneGate);
    int receivingValue = analogRead(microphoneEnvelope);
    int lastReceivedReading;

    if (statusSensor == 1)
    {
        lcd.clear();
        digitalWrite(microphoneLED, HIGH);

        Serial.println(receivingValue);

        lcd.print("Reading is ");
        lcd.print(receivingValue);

        delay(1000);
        //        lcd.clear();
    }
    else
    {
        digitalWrite(microphoneLED, LOW);

        lcd.print("No reading...");

        // There needs to be some sort of very short delay. Do not remove this.
        delay(0100);
    }
}