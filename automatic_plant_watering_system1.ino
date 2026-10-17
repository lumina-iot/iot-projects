const int sensorPin = A0;
const int relayPin = 4;
const int ledPin = 8;

int moistureValue;
int threshold = 500;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(relayPin, HIGH);   // Relay OFF (active LOW)
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(sensorPin);

  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(relayPin, LOW);   // Pump ON
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(relayPin, HIGH);  // Pump OFF
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}