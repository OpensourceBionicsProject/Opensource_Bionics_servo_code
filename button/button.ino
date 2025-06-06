#include <Servo.h>

Servo servos[13];

const int servoPin = 8;
const int buttonPin = 2;

bool direction = true;           // true = forward, false = reverse
bool lastButtonState = false;

void setup() {
  servos[8].attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);  // Button connected between pin 2 and GND
}

void loop() {
  bool buttonState = !digitalRead(buttonPin);  // Active low button

  // Detect rising edge (button press)
  if (buttonState && !lastButtonState) {
    spinServo(direction);         // Spin in current direction
    direction = !direction;       // Toggle direction for next press
  }

  lastButtonState = buttonState;
}

void spinServo(bool forward) {
  int speed = forward ? 180 : 0;  // 180 = full forward, 0 = full reverse

  servos[8].write(speed);

  // Estimate time for 3 full turns — adjust as needed for your servo
  delay(3000);  // Example: 3 seconds total spin time

  servos[8].write(90);  // Stop the servo
}
