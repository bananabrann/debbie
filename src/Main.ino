#include <LiquidCrystal.h> // LCD library classes.

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Initializes pins on LCD to the microprocessor's pins. Ex: D7 on the LCD is going to pin 2 on te board.

int microphoneGate = 6;
int microphoneLED = 13;
int microphoneEnvelope = A0;
// Dynamic variables for easy changes in the future.

void setup() // This runs only when the microprocessor first launches.
{
    Serial.begin(9600);

    lcd.begin(16, 2); // Intializes LCD screen. (columns, rows)
    lcd.print("listening...");

    pinMode(microphoneGate, INPUT); // Sets pin 6 to be primary input. E.g., where it's listening.
    pinMode(microphoneLED, OUTPUT); // Assigns that when receiving INPUT, send it to microphoneLED.
}

void loop() // Runs continuously as long as the microprocessor is receiving power and code within the loop does not effect the loop.
{
    int statusSensor = digitalRead(microphoneGate); // Read the gate from the microphone and assign it to this variable.
    int receivingValue = analogRead(microphoneEnvelope); // Read the analog output from the microphone's envelope and assign it to this variable.
    int lastReceivedReading;
    int receivingValueInDb = convertToDb(receivingValue); // The microphone does not calculate Decibels. Instead, it calculates Voltage. This code calls a function that calculates the Voltage into the estimated Decibels and stores it in this variable.

    if (statusSensor == 1) // If the microphone's gate output is TRUE...
    {
        digitalWrite(microphoneLED, HIGH); // ... Send Voltage to microphoneLED.

        lcd.clear(); // ... Clear the LCD.

        lcd.setCursor(0, 0); // ... Set cursor to row 1, column 1.
        lcd.print(receivingValueInDb); // ... Print the Decibels.
        lcd.print(" Db, (");
        lcd.print(receivingValue);
        lcd.print("V)");
        // Text formatting for easy display!

        lcd.setCursor(0, 1);
        // Set cursor to row 1, column 2.

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
        // Checks and displays the estimated Decibels comparison.

        delay(1100); // Because the microprocessor is very, very fast, we need to tell it to hold up so that humans can read the reading. This value is in miliseconds.
    }
    else // Otherwise, if gate is FALSE...
    {
        digitalWrite(microphoneLED, LOW); // Send no Voltage to microphoneLED.

        lcd.print("Speak louder!");

        delay(0200); // Delays the microprocessor. Without this, the screen would "update" very, very quickly and flash. Value is in miliseconds.

        lcd.clear(); // Clear LCD screen.
    }
}

int convertToDb(int num) // This function is outside the microprocessor's loop function, and is called to calculate the Decibels from a given Voltage. Because Decibels are a logarithmic, this function is not entirely accurate.
{
    int newNum = (20 * (log10(num))); // Math for Voltage to Decibels.
    return newNum; // Returns new, calculated number.
}
