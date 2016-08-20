// Global variables
int buttonPins[] = {2, 3, 4, 5};
int frequencies[] = {256, 288, 324, 342};
int buzzPin = 8;

// Setup
void setup() {
  // Init pins
  pinMode(buttonPins[0], INPUT);
  pinMode(buttonPins[1], INPUT);
  pinMode(buttonPins[2], INPUT);
  pinMode(buttonPins[3], INPUT);
  pinMode(buzzPin, OUTPUT);
}

// Loop
void loop() {
  for (int i=0; i<4; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      tone(buzzPin, frequencies[i]);
      delay(500);
      noTone(buzzPin);
      break;
    }
  }
}
