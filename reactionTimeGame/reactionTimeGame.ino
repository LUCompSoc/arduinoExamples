#include "TM1637Display.h"

#define DISPLAY_PIN_CLK 2
#define DISPLAY_PIN_DIO 3
#define PLAYER_PIN_A 4
#define PLAYER_PIN_B 5
#define LED_PIN 13

#define DELAY_MIN_MS 5000
#define DELAY_MAX_MS 10000

// Player class representing a player with their own button
// Should really be in its own file
class Player {
  private:
    int buttonPin;
    int lastButtonState;
  
  public:
    Player(int buttonPin) {
      // Set attributes
      this->buttonPin = buttonPin;

      // Configure button pin as input
      pinMode(buttonPin, INPUT);
    }

    int justPressed() {
      // Read state of button pin
      int buttonState = digitalRead(buttonPin);

      // Check whether the button was pressed since last call of this function
      int justPressed = buttonState == 1 && buttonState != this->lastButtonState;
      
      // Set last button state and return justPressed
      this->lastButtonState = buttonState;
      return justPressed;
    }
};

// Global variables
TM1637Display display(DISPLAY_PIN_CLK, DISPLAY_PIN_DIO);
Player plrA(PLAYER_PIN_A);
Player plrB(PLAYER_PIN_B);

int nextTriggerTime = -1;
int awaitingUserInput = 0;

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

  // Configure LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Set a new random trigger time for the LED
  newRandomTriggerTime();
}

void loop() {
  // Check for user input
  if (awaitingUserInput) {
    // Player A has won
    if (plrA.justPressed()) {
      awaitingUserInput = false;
      digitalWrite(LED_PIN, 0);
    }
  }

  // We have passed the next trigger time so trigger the LED
  else if (millis() >= nextTriggerTime) {
    awaitingUserInput = 1;
    digitalWrite(LED_PIN, 1);
  }

  // Delay between iterations
  delay(10);
}
