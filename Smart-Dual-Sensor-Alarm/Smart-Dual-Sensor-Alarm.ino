// Smart Dual Sensor Alarm
// TMP36 + PIR + LED + Buzzer
// Arduino Uno R3

int tmpPin = A0;
int pirPin = 2;
int ledPin = 8;
int buzzerPin = 9;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  // Read temperature from TMP36
  int tmpValue = analogRead(tmpPin);
  float voltage = tmpValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  // Read motion from PIR
  int motion = digitalRead(pirPin);

  // Display readings
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.print(" °C | Motion: ");
  Serial.println(motion);

  // Alarm condition
  if (motion == HIGH && temperatureC > 25) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}
