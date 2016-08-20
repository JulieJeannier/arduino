void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Test");

  int buttonPins[] = {2, 3, 4, 5};
  int frequencies[] = {256, 288, 324, 342};
  int buzzPin = 8;

  pinMode(buttonPins[0], INPUT);
  pinMode(buttonPins[1], INPUT);
  pinMode(buttonPins[2], INPUT);
  pinMode(buttonPins[3], INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  int buttonPins[] = {2, 3, 4, 5};
  int frequencies[] = {256, 288, 324, 342};
  int buzzPin = 8;
  
  //noTone(buzzPin);

  //tone(buzzPin, frequencies[0]);

  for (int i=0; i<4; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      Serial.print(buttonPins[i]);
      Serial.println(" : HIGH");
      tone(buzzPin, frequencies[i]);
      delay(500);
      noTone(buzzPin);
      break;
    } else if (digitalRead(buttonPins[i]) == LOW) {
      Serial.print(buttonPins[i]);
      Serial.println(" : LOW");
    }
  }
}
