// La secuencia de encendido es rojo, naranja y verde
// • Los tiempos de estado HIGH debe ser 3 s, 1 s, 1,5 s, respectivamente.
// • Los tiempos de espera deben ser de 100 ms
// • La secuencia debe reproducirse de forma infinita.

const int redLED = 13;
const int orangeLED = 12;
const int greenLED = 11;

void setup() {
  // Declaracion pines
  pinMode(redLED,OUTPUT);
  pinMode(orangeLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  // ROJO
  digitalWrite(redLED,HIGH);
  delay(3000);
  digitalWrite(redLED, LOW);
  // DELAY
  delay(100);
  // NARANJA
  digitalWrite(orangeLED, HIGH);
  delay(1000);
  digitalWrite(orangeLED, LOW);
  // DELAY
  delay(100);
  // VERDE
  digitalWrite(greenLED, HIGH);
  delay(1500);
  digitalWrite(greenLED, LOW);
  // DELAY
  delay(100);
}