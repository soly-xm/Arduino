const int analogPin = A0;   // MQ-2 A0
const int digitalPin = 7;   // MQ-2 D0 (optional)

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  Serial.println("MQ-2 Gas Sensor Test Starting...");
}

void loop() {
  int analogValue = analogRead(analogPin);
  int digitalValue = digitalRead(digitalPin);

  Serial.print("Analog Value: ");
  Serial.print(analogValue);

  Serial.print(" | Digital Value: ");
  Serial.println(digitalValue);

  delay(1000);
  if (analogValue >= 80 ) {
    Serial.print("fire!!");
  }
}
