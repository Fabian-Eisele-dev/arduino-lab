const int buttonPin = 13;
const int led1Pin = 2;
const int led2Pin = 6;


bool ButtonState = HIGH;
bool led1Active = true;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  if (currentButtonState == LOW && ButtonState == HIGH) {
    led1Active = !led1Active;
  }

  digitalWrite(led1Pin, led1Active ? HIGH : LOW);
  digitalWrite(led2Pin, led1Active ? LOW : HIGH);

  if (digitalRead(buttonPin)== LOW)
  Serial.println("button pressed");

  ButtonState = currentButtonState;
}