// The ignition sequence is red, orange, and green.
// • The HIGH state times should be 3 s, 1 s, 1.5 s, respectively.
// • The waiting times should be 100 ms.
// • The sequence should be played infinitely.

// Define Pins
const int redLED = 13;
const int orangeLED = 12;
const int greenLED = 11;

void setup() {
  // LEDs SETUP
  pinMode(redLED,OUTPUT);
  pinMode(orangeLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  // RED
  digitalWrite(redLED,HIGH);
  delay(3000);
  digitalWrite(redLED, LOW);
  // DELAY
  delay(100);
  // ORANGE
  digitalWrite(orangeLED, HIGH);
  delay(1000);
  digitalWrite(orangeLED, LOW);
  // DELAY
  delay(100);
  // GREEN
  digitalWrite(greenLED, HIGH);
  delay(1500);
  digitalWrite(greenLED, LOW);
  // DELAY
  delay(100);
}