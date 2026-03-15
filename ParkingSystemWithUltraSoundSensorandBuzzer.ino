const int trigPin = 9;
const int echoPin = 10;
const int ledPinG = 7;
const int ledPinY = 6;
const int ledPinR = 5;
const int ledPinB =4;

float duration; // variable to store pulse duration
float distanceCM; // variable to store distance in CM
float distanceIN; // variable to store distance in IN

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinY, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  tone(ledPinB, 1000);   // 1000 Hz sound
}

void loop() {
  // start with a clean signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // send trigger signal
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // return pulse duration in microseconds
  // if set to HIGH, pulseIn() waits for the pin to go from LOW to HIGH
  // stops timing when pin goes back LOW
  duration = pulseIn(echoPin, HIGH);
  // convert m/s to in/microsec
  // 343 m/s = .034 cm/microseconds
  distanceCM = (duration * 0.034) / 2;
  // convert to inches, 1in = 2.54cm
  distanceIN = distanceCM / 2.54;
  // print distance to Serial Monitor

//seting up an if statement
if (distanceCM < 15) {  
  // VERY CLOSE → constant tone
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinY, LOW);
  digitalWrite(ledPinR, HIGH);

  tone(ledPinB, 1000);   // continuous sound
}

else if (distanceCM < 30) {  
  // MEDIUM → medium speed beep
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinY, HIGH);
  digitalWrite(ledPinR, LOW);

  tone(ledPinB, 1000);
  delay(200);
  noTone(ledPinB);
  delay(200);
}

else if (distanceCM < 50) {  
  // FAR BUT DETECTED → slow beep
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinY, HIGH);
  digitalWrite(ledPinR, LOW);

  tone(ledPinB, 1000);
  delay(500);
  noTone(ledPinB);
  delay(500);
}

else {  
  // VERY FAR → silent
  digitalWrite(ledPinG, HIGH);
  digitalWrite(ledPinY, LOW);
  digitalWrite(ledPinR, LOW);

  noTone(ledPinB);
}


  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm | ");
  Serial.print(distanceIN);
  Serial.println(" in");
  delay(1000);
}
