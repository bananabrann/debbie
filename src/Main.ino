#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int microphoneGate = 6;
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
    //    interrupts();

    int statusSensor = digitalRead(microphoneGate);
    int receivingValue = analogRead(microphoneEnvelope);
    int lastReceivedReading;
    int receivingValueInDb = convertToDb(receivingValue);

    if (statusSensor == 1)
    {
        lcd.clear();
        digitalWrite(microphoneLED, HIGH);

        lcd.print(receivingValueInDb);
        lcd.print(" Db, (");
        lcd.print(receivingValue);
        lcd.print("V)");

        delay(1000);
    }
    else
    {
        digitalWrite(microphoneLED, LOW);

        lcd.print("Speak louder!");

        // There needs to be some sort of very short delay. Do not remove this.
        delay(0200);
        lcd.clear();
    }
}

int convertToDb(int num)
{
    int newNum = (20 * (log10(num)));
    return newNum;
}
