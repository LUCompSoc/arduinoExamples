//These are all the pins of the LED
#define A  2  // 7-seg pin: 7
#define B  3  // 7-seg pin: 6
#define C  4  // 7-seg pin: 4
#define D  5  // 7-seg pin: 2
#define E  6  // 7-seg pin: 1
#define F  7  // 7-seg pin: 9
#define G  8  // 7-seg pin: 10
#define DP 9  // 7-seg pin: 5

//These are the different digit configurations
#define DIGIT_ZERO  true,  true,  true,  true,  true,  false, true
#define DIGIT_ONE   false, true,  true,  false, false, false, false
#define DIGIT_TWO   true,  true,  false, true,  true,  true,  false
#define DIGIT_THREE true,  true,  true,  true,  false, true,  false
#define DIGIT_FOUR  false, true,  true,  false, false, true,  true
#define DIGIT_FIVE  true,  false, true,  true,  false, true,  true
#define DIGIT_SIX   true,  false, true,  true,  true,  true,  true
#define DIGIT_SEVEN true,  true,  true,  false, false, false, false
#define DIGIT_EIGHT true,  true,  true,  true,  true,  true,  true
#define DIGIT_NINE  true,  true,  true,  false, false, true,  true
#define DIGIT_CLEAR  false,  false,  false,  false, false, false, false
#define DIGIT_FIZZ false,  false,  false,  true, false, false, false
#define DIGIT_BUZZ false,  false,  true,  false, false, false, false
#define DIGIT_FIZZBUZZ false,  false,  true,  false, false, false, false


int ledPin = 13;
unsigned long previousMillis = 0;
int digit = 0;

int digitPins[] = {A, B, C, D, E, F, G};

//writes all the digits
void writeDigitPins(bool stateA, bool stateB, bool stateC, bool stateD, bool stateE, bool stateF, bool stateG, bool stateDP) {
  digitalWrite(A, stateA ? LOW : HIGH);
  digitalWrite(B, stateB ? LOW : HIGH);
  digitalWrite(C, stateC ? LOW : HIGH);
  digitalWrite(D, stateD ? LOW : HIGH);
  digitalWrite(E, stateE ? LOW : HIGH);
  digitalWrite(F,    ? LOW : HIGH);
  digitalWrite(G, stateG ? LOW : HIGH);
  digitalWrite(DP, stateDP ? LOW : HIGH);
}


void writeDigit(int digit, bool dp) {
  if (digit < 0 || digit > 12) return;

  bool digitStates[7];
  switch (digit) {
    case 0:
      writeDigitPins(DIGIT_ZERO, dp);
      break;
    case 1:
      writeDigitPins(DIGIT_ONE, dp);
      break;
    case 2:
      writeDigitPins(DIGIT_TWO, dp);
      break;
    case 3:
      writeDigitPins(DIGIT_THREE, dp);
      break;
    case 4:
      writeDigitPins(DIGIT_FOUR, dp);
      break;
    case 5:
      writeDigitPins(DIGIT_FIVE, dp);
      break;
    case 6:
      writeDigitPins(DIGIT_SIX, dp);
      break;
    case 7:
      writeDigitPins(DIGIT_SEVEN, dp);
      break;
    case 8:
      writeDigitPins(DIGIT_EIGHT, dp);
      break;
    case 9:
      writeDigitPins(DIGIT_NINE, dp);
      break;
    case 10:
      writeDigitPins(DIGIT_CLEAR, dp);
      break;
    case 11:
      writeDigitPins(DIGIT_FIZZ, dp);
      break;
    case 12:
      writeDigitPins(DIGIT_BUZZ, dp);
      break;
    case 13:
      writeDigitPins(DIGIT_FIZZBUZZ, dp);
      break;
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  writeDigit(digit, false);
}


void loop() {
  // put your main code here, to run repeatedly:

  //This is how you write the digit 1:
  writeDigit(1,true);
  //use delay(int ms) to make the arduino wait
  delay(1000);
  //Try your hand at recreating the fizzbuz algorithm!
}
