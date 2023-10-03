#define latchPin 8
#define clockPin 12
#define dataPin 11
#define animDelay 250

byte b = 1;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (b == 0) {
    b = 1;
  }
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, b);
  digitalWrite(latchPin, HIGH);

  if (b != 0) {
    Serial.println(b);
    b = b << 1;
    delay(animDelay);
  }
}
