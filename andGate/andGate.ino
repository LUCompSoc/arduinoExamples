#define BUTTON_A 8
#define BUTTON_B 7
#define LED 6
int buttonAState=0, buttonBState =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
}

void loop() {
  //reads both pins, storing either HIGH or LOW in a variable
  buttonAState = digitalRead(BUTTON_A);
  buttonBState = digitalRead(BUTTON_B);
  //if both buttons are high, our AND gate is true!
  if (buttonAState == HIGH && buttonBState == HIGH){
    //So we turn on the LED by writing HIGH to that pin
    digitalWrite(LED, HIGH);
  }
  else{
    //otherwise we turn it off!
    digitalWrite(LED, LOW);
  }
}

