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
        digitalWrite(microphoneLED, HIGH);

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print(receivingValueInDb);
        lcd.print(" Db, (");
        lcd.print(receivingValue);
        lcd.print("V)");

        lcd.setCursor(0, 1);

        if (receivingValueInDb < 20)
        {
            lcd.print("A watch's tick");
        }
        else if (receivingValueInDb >= 20 && receivingValueInDb < 30)
        {
            lcd.print("Whisper");
        }
        else if (receivingValueInDb >= 30 && receivingValueInDb < 40)
        {
            lcd.print("Turning a page");
        }
        else if (receivingValueInDb >= 40 && receivingValueInDb < 46)
        {
            lcd.print("Light rain");
        }
        else if (receivingValueInDb >= 46 && receivingValueInDb < 50)
        {
            lcd.print("Moderate rain");
        }
        else if (receivingValueInDb >= 50 && receivingValueInDb < 55)
        {
            lcd.print("Quiet office");
        }
        else if (receivingValueInDb >= 55 && receivingValueInDb < 60)
        {
            lcd.print("Air conditioner");
        }
        else if (receivingValueInDb >= 60 && receivingValueInDb < 65)
        {
            lcd.print("Normal conversation");
        }
        else if (receivingValueInDb >= 65 && receivingValueInDb < 70)
        {
            lcd.print("Running dryer");
        }
        else if (receivingValueInDb >= 70 && receivingValueInDb < 80)
        {
            lcd.print("Tiolet flushing");
        }
        else if (receivingValueInDb >= 80 && receivingValueInDb < 95)
        {
            lcd.print("Construction site");
        }
        else if (receivingValueInDb >= 95 && receivingValueInDb < 110)
        {
            lcd.print("Nightclub");
        }
        else
        {
            lcd.print("Wow, that's loud!");
        }

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
