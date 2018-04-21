
// set pin numbers:
const int sPin = 2;     // pin digital de entrada

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(sPin, INPUT);
}

void loop() {
}

bool presencia()
{
  return digitalRead(sPin);
}

