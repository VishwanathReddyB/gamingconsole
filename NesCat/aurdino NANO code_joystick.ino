// Define pins for the joystick and output LEDs
const int VRxPin = A0; // Analog pin for X-axis
const int VRyPin = A1; // Analog pin for Y-axis
const int SWPin = 12;  // Analog pin for the switch
const int D3Pin = 3;   // Digital pin for X-axis < 400
const int D4Pin = 4;   // Digital pin for X-axis > 500
const int D5Pin = 5;   // Digital pin for Y-axis < 400
const int D6Pin = 6;   // Digital pin for Y-axis > 500
const int D7Pin = 7;   // Digital pin for switch press

const int DEAD_ZONE_LOW = 450; // Lower boundary of dead zone
const int DEAD_ZONE_HIGH = 550; // Upper boundary of dead zone

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set the output pins as outputs
  pinMode(D3Pin, OUTPUT);
  pinMode(D4Pin, OUTPUT);
  pinMode(D5Pin, OUTPUT);
  pinMode(D6Pin, OUTPUT);
  pinMode(D7Pin, OUTPUT);

  // Set the switch pin as input with pull-up resistor
  pinMode(SWPin, INPUT_PULLUP);
}

void loop() {
  // Read the values from the joystick
  int xValue = analogRead(VRxPin); // Read X-axis value
  int yValue = analogRead(VRyPin); // Read Y-axis value
  int buttonState = digitalRead(SWPin); // Read button state

  // Determine which pins should be high and print corresponding direction
  if (xValue < DEAD_ZONE_LOW) {
    digitalWrite(D3Pin, HIGH);
    Serial.println("left");
  } else {
    digitalWrite(D3Pin, LOW);
  }

  if (xValue > DEAD_ZONE_HIGH) {
    digitalWrite(D4Pin, HIGH);
    Serial.println("right");
  } else {
    digitalWrite(D4Pin, LOW);
  }

  if (yValue < DEAD_ZONE_LOW) {
    digitalWrite(D5Pin, HIGH);
    Serial.println("up");
  } else {
    digitalWrite(D5Pin, LOW);
  }

  if (yValue > DEAD_ZONE_HIGH) {
    digitalWrite(D6Pin, HIGH);
    Serial.println("down");
  } else {
    digitalWrite(D6Pin, LOW);
  }

  // Check the switch state and set D7 high if pressed
  if (buttonState == LOW) {
    digitalWrite(D7Pin, HIGH);
    Serial.println("select");
  } else {
    digitalWrite(D7Pin, LOW);
  }

  // Delay for a short while before the next loop
  delay(100);
}
