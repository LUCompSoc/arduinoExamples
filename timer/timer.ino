// Complete the TODO items on lines 28 & 55

#include "TM1637Display.h"

// Pins connected to data & clock pins on display
#define DISPLAY_PIN_CLK 2
#define DISPLAY_PIN_DIO 3

// Display object for interacting with the physical display
TM1637Display display(DISPLAY_PIN_CLK, DISPLAY_PIN_DIO);

// Timer global variables
int timerStart = 0;
int lastDisplayNum = 0;

// Reset the timer
void resetTimer() {
  timerStart = 0;
}

// Returns time elapsed since timer start in milli-seconds.
unsigned long timeElapsed() {
  return millis() - timerStart;
}

// Generates a 4-digit number representing the minutes & seconds since the timer started.
int createDisplayNumber(unsigned long timeMS) {
  // TODO: Write code to generate the number used by the library for setting the content of the display.
  // Format:
  // - A single 4-digit (or less) integer.
  // - Order of digits is same as it is visually on the board.
  // - If a number with less then 4 digits is used, it will be displayed on the right digits of the display.
  // Hint: Use divide & modulo operators to get minutes & seconds :D
}

// Arduino start-up function
void setup() {
  // Clear display & set brightness to max
  display.clear();
  display.setBrightness(7);

  // Reset timer
  resetTimer();
}

// Arduino loop function
void loop() {
  // Generate display number from time elapsed
  int displayNum = createDisplayNumber(timeElapsed());
  
  // If display number has changed, update the display
  if (displayNum != lastDisplayNum) {
    lastDisplayNum = displayNum;
    
    // TODO: Write the number to the display.
    // Use display.showNumberDecEx()
    // Read "TM1637Display.h" in the library zip
  }

  // Wait before checking time elapsed again
  delay(100);
}
