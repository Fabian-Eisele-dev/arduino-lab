const int BUTTON1 = 9;
const int BUTTON2 = 10;
const int BUTTON3 = 11;
const int BUTTON4 = 12;

const int RED = 2;
const int GREEN = 3;
const int BLUE = 4;

bool lastState[4] = {true, true, true, true};


void setup() {
pinMode(BUTTON1, INPUT_PULLUP);
pinMode(BUTTON2, INPUT_PULLUP);
pinMode(BUTTON3, INPUT_PULLUP);
pinMode(BUTTON4, INPUT_PULLUP);

pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
Serial.begin(9600);
}

void loop() {

bool current1 = digitalRead(BUTTON1);
bool current2 = digitalRead(BUTTON2);
bool current3 = digitalRead(BUTTON3);
bool current4 = digitalRead(BUTTON4);

if (current1 == LOW && lastState[0] == true){
  Serial.println("BLUE");
  analogWrite(RED, 0);
  analogWrite(GREEN, 120);
  analogWrite(BLUE, 105);
  delay(200);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

if (current2 == LOW && lastState[1] == true){
  Serial.println("GREEN");
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 0);
  delay(200);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

if (current3 == LOW && lastState[2] == true){
  Serial.println("YELLOW");
  analogWrite(RED, 200);
  analogWrite(GREEN, 100);
  analogWrite(BLUE, 0);
  delay(200);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

if (current4 == LOW && lastState[3] == true){
  Serial.println("RED");
  analogWrite(RED, 255);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(200);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}


lastState[0] = current1;
lastState[1] = current2;
lastState[2] = current3;
lastState[3] = current4;

delay(20);
}
