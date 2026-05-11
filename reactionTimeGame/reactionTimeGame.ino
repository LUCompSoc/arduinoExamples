#include "TM1637Display.h"

#define DISPLAY_PIN_CLK 2
#define DISPLAY_PIN_DIO 3
#define PLAYER_PIN_A 7
#define LED_PIN 6

#define DELAY_MIN_MS 5000
#define DELAY_MAX_MS 10000

// Global variables
TM1637Display display(DISPLAY_PIN_CLK, DISPLAY_PIN_DIO);
int nextTriggerTime = 0;


void newRandomTriggerTime() {
  nextTriggerTime = millis() + random(DELAY_MIN_MS, DELAY_MAX_MS);
  Serial.print("Will trigger in: ");
  Serial.print(nextTriggerTime - millis());
  Serial.println("ms");
}

void setup() {
  // Configure serial
  Serial.begin(9600);
  // Configure display
  display.clear();
  display.setBrightness(7);
  randomSeed(analogRead(0));
  // Configure LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(PLAYER_PIN_A, INPUT);
  // Set a new random trigger time for the LED
  newRandomTriggerTime();
}

void loop() {
  //If the current time is greater than or equal to the next trigger time - replace question mark!
  if (?){
    //Turn on the LED - fill in the line!
    ?
    //If the button is pressed - replace the question mark!
    if (?){
      //Work out how many ms have passed - replace the question mark!
      int speed = ?;
      display.showNumberDecEx((speed<9999?speed:0000), 0b00000000, true);
      delay(1000);
      while (digitalRead(PLAYER_PIN_A)==LOW){
        delay(10);
      }
      //Turn off the LED, clear the display, and generate a new trigger time - fill in next 3 lines!
      ?
      ?
      ?
    }
  }
  delay(1);
}
