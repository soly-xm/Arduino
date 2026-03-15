#define IN1 11
#define IN2 10
#define IN3 6
#define IN4 5

char command;

void setup() {
  Serial.begin(9600);   // HC-05 default baud rate
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();  // Make sure car is stopped at start
}

void loop() {

  if (Serial.available()) {
    command = Serial.read();

    if (command == 'F') {
      forward();
    }
    else if (command == 'B') {
      backward();
    }
    else if (command == 'L') {
      left();
    }
    else if (command == 'R') {
      right();
    }
    else if (command == 'S') {
      stopCar();
    }
  }
}

void forward() {
  // Left side stays the same
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right side flipped
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward() {
  // Left side stays the same
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Right side flipped
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
