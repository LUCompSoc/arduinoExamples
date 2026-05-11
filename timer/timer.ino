#include "TM1637Display.h"

// Pins used for data & clock of display
#define DISPLAY_PIN_CLK 2
#define DISPLAY_PIN_DIO 3

// Display object for interacting with the display
TM1637Display display(DISPLAY_PIN_CLK, DISPLAY_PIN_DIO);

// Timer global variables
int timerStart = 0;
int lastDisplayNum = 0;

//! Reset the timer
void timerReset() {
  timerStart = 0;
}

//! Get time elapsed since timer start in milli-seconds.
//! @return Time in milli-seconds since timer start.
unsigned long timerDelta() {
  return millis() - timerStart;
}

//! Generates a 4-digit number representing the minutes & seconds since the timer started.
//! @param timerDelta Time since timer started in milli seconds.
//! @return The 4-digit integer to give to the display object.
int createDisplayNumber(unsigned long timerDelta) {
  int deltaSecs = timerDelta / 1000;

  int secs = deltaSecs % 60;
  int mins = deltaSecs / 60;

  return mins * 60 + secs;
}

// Arduino start-up function
void setup() {
  // Clear display & set brightness to max
  display.clear();
  display.setBrightness(7);

  // Reset timer
  timerReset();
}

// Arduino loop function
void loop() {
  // Generate display number from time elapsed
  unsigned long timeElapsed = timerDelta();
  int displayNum = createDisplayNumber(timeElapsed);
  
  // If display number has changed, update the display
  if (displayNum != lastDisplayNum) {
    lastDisplayNum = displayNum;
    display.showNumberDecEx(displayNum, 0b01000000, true);
  }

  // Wait before checking time elapsed again
  delay(100);
}
