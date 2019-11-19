#include <LiquidCrystal.h>            // LCD library classes.

// Initialize pins on LCD to the microprocessor
// Example: D7 on the LCD is going to pin 2 on thee board.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Assign microphone output information as variables
int microphoneGate = 6;
int microphoneLED = 13;
int microphoneEnvelope = A0;

void setup() {
    Serial.begin(9600);

    lcd.begin(16, 2);                     // Intializes LCD screen (columns, rows)
    lcd.print("listening...");

    pinMode(microphoneGate, INPUT);       // Sets pin 6 to be primary input. E.g., where it's listening
    pinMode(microphoneLED, OUTPUT);       // Assigns that when receiving INPUT, send it to microphoneLED
}

void loop() {
    int statusSensor = digitalRead(microphoneGate);           // Read the gate from the microphone and assign it to this variable
    int receivingValue = analogRead(microphoneEnvelope);      // Read the analog output from the microphone's envelope and assign it to this variable
    int receivingValueInDb = convertToDb(receivingValue);     // Calculate microphone's voltage reading to Decibel
    int lastReceivedReading;

    if (statusSensor == 1) {                                   // If microphone's gate detects input (sound)
        digitalWrite(microphoneLED, HIGH);                    // Sends Voltage to microphoneLED

        lcd.clear(); 

        lcd.setCursor(0, 0);                                  // ... Set cursor to row 1, column 1. NOTE: This must be set
        lcd.print(receivingValueInDb);                        // ... Print the calculated Decibels
        lcd.print(" Db, (");
        lcd.print(receivingValue);
        lcd.print("V)");                                      // Text formatting for easy display

        lcd.setCursor(0, 1);

        if (receivingValueInDb < 20) {
            lcd.print("A watch's tick");
        } else if (receivingValueInDb >= 20 && receivingValueInDb < 30) {
            lcd.print("Whisper");
        } else if (receivingValueInDb >= 30 && receivingValueInDb < 40) {
            lcd.print("Turning a page"); 
        } else if (receivingValueInDb >= 40 && receivingValueInDb < 46) {
            lcd.print("Light rain");
        } else if (receivingValueInDb >= 46 && receivingValueInDb < 50) {
            lcd.print("Moderate rain");
        } else if (receivingValueInDb >= 50 && receivingValueInDb < 55) {
            lcd.print("Quiet office");
        } else if (receivingValueInDb >= 55 && receivingValueInDb < 60) {
            lcd.print("Air conditioner");
        } else if (receivingValueInDb >= 60 && receivingValueInDb < 65) {
            lcd.print("Normal conversation");
        } else if (receivingValueInDb >= 65 && receivingValueInDb < 70) {
            lcd.print("Running dryer");
        } else if (receivingValueInDb >= 70 && receivingValueInDb < 80) {
            lcd.print("Tiolet flushing");
        } else if (receivingValueInDb >= 80 && receivingValueInDb < 95) {
            lcd.print("Construction site");
        } else if (receivingValueInDb >= 95 && receivingValueInDb < 110) {
            lcd.print("Nightclub");
        } else {
            lcd.print("Wow, that's loud!");
        }

        delay(1100); // Because the microprocessor is very, very fast, we need to tell it to hold up so that humans can read the reading
    }
    else {                                            // Otherwise, if microphone's gate does not detect input/sound...
        digitalWrite(microphoneLED, LOW);
        lcd.print("Speak louder!");
        delay(0200);
        lcd.clear();
    }
}

int convertToDb(int num) {
    // NOTE: Because Decibels are a logarithmic, this function is not entirely accurate

    int newNum = (20 * (log10(num)));
    return newNum;
}
