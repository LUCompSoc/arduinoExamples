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
  // put your main code here, to run repeatedly:
  buttonAState = digitalRead(BUTTON_A);
  buttonBState = digitalRead(BUTTON_B);
  if (buttonAState == HIGH && buttonBState == HIGH){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
