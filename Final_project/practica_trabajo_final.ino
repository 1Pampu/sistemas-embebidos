// Define LEDs Pins
const int plantaBaja = 13;
const int plantaAlta = 12;
const int patio = 11;
const int alarma = 8;
const int motorCochera = 10;
const int motorPorton = 9;
const int motorRiego = 7;

void setup() {
  // Serial SETUP
  Serial.begin(9600);

  // LEDs SETUP
  pinMode(plantaBaja, OUTPUT);
  pinMode(plantaAlta, OUTPUT);
  pinMode(patio, OUTPUT);
  pinMode(alarma, OUTPUT);

  // RELAYs SETUP
  pinMode(motorCochera, OUTPUT);
  pinMode(motorPorton, OUTPUT);
  pinMode(motorRiego, OUTPUT);

  // Visual
  Serial.println("Bienvenido");
  delay(200);
  Serial.println("Inicializando el sistema");
  delay(200);
  Serial.println("Espere...");
  delay(200);
  Serial.println("Sistema activo");
}

void loop() {
  // Check if serial contains data
  if (Serial.available()){
    // Read Data
    char status = Serial.read();

    // Switch Case
    switch(status){

      // Planta Baja
      case 'a': case 'A':
        digitalWrite(plantaBaja, HIGH);
        Serial.println("Iluminacion de la planta baja encendida");
        break;
      case 'b': case 'B':
        digitalWrite(plantaBaja, LOW);
        Serial.println("Iluminacion de la planta baja apagada");
        break;

      // Planta Alta
      case 'c': case 'C':
        digitalWrite(plantaAlta, HIGH);
        Serial.println("Iluminacion de la planta alta encendida");
        break;
      case 'd': case 'D':
        digitalWrite(plantaAlta, LOW);
        Serial.println("Iluminacion de la planta alta apagada");
        break;

      // Patio
      case 'e': case 'E':
        digitalWrite(patio, HIGH);
        Serial.println("Iluminacion del patio encendida");
        break;
      case 'f': case 'F':
        digitalWrite(patio, LOW);
        Serial.println("Iluminacion del patio apagada");
        break;

      // Alarma
      case '1':
        digitalWrite(alarma, HIGH);
        Serial.println("Alarma encendida");
        break;
      case '0':
        digitalWrite(alarma, LOW);
        Serial.println("Alarma apagada");
        break;

      // Motor Cochera
      case '2':
        Serial.println("Aperturando cochera...");
        digitalWrite(motorCochera, HIGH);
        delay(2000);
        digitalWrite(motorCochera, LOW);
        Serial.println("Cochera aperturada");
        break;
      case '3':
        Serial.println("Cerrando cochera...");
        digitalWrite(motorCochera, HIGH);
        delay(2000);
        digitalWrite(motorCochera, LOW);
        Serial.println("Cochera cerrada");
        break;

      // Motor Porton
      case '4':
        Serial.println("Aperturando porton...");
        digitalWrite(motorPorton, HIGH);
        delay(2000);
        digitalWrite(motorPorton, LOW);
        Serial.println("Porton aperturado");
        break;
      case '5':
        Serial.println("Cerrando porton...");
        digitalWrite(motorPorton, HIGH);
        delay(2000);
        digitalWrite(motorPorton, LOW);
        Serial.println("Porton cerrado");
        break;

      // Motor Riego
      case '6':
        Serial.println("Encendiendo sistema de riego...");
        digitalWrite(motorRiego, HIGH);
        Serial.println("Sistema de riego encendido");
        break;
      case '7':
        Serial.println("Apagando sistema de Riego...");
        digitalWrite(motorRiego, LOW);
        Serial.println("Sistema de riego apagado");
        break;
    }}}
