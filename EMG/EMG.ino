#include <Servo.h>

const int emgPin = A0;
const int loMinusPin = 10;
const int loPlusPin = 11;
const int servoPin = 9;

const int openAngle = 0;       // Servo at rest (e.g., hand open)
const int closeAngle = 90;     // Servo position for contraction (e.g., hand closed)
const int highThreshold = 550; // Adjust based on actual signal when muscle is flexed
const int lowThreshold = 450;  // Adjust based on resting EMG noise

Servo armServo;
bool isClosed = false;

void setup() {
  Serial.begin(9600);
  pinMode(loMinusPin, INPUT);
  pinMode(loPlusPin, INPUT);
  armServo.attach(servoPin);
  armServo.write(openAngle); // Start in open position
}

void loop() {
  // Check if electrodes are properly attached
  if (digitalRead(loMinusPin) == HIGH || digitalRead(loPlusPin) == HIGH) {
    Serial.println("! No contact with muscle");
    return;  // Skip signal reading if no contact
  }

  int emgValue = analogRead(emgPin);
  Serial.println(emgValue);  // For debugging

  // If muscle flexes and arm is open
  if (emgValue > highThreshold && !isClosed) {
    armServo.write(closeAngle);
    isClosed = true;
  }

  // If muscle relaxes and arm is closed
  if (emgValue < lowThreshold && isClosed) {
    armServo.write(openAngle);
    isClosed = false;
  }

  delay(10); // Small delay to reduce flickering
}
