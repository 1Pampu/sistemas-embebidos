// The student, in the development of their programming, should consider the following:
// • The objective of the project is to be able to automate a greenhouse that will automatically monitor
//   the temperature and humidity of the environment.
// • The system will continuously test the temperature and humidity using the DHT11 sensor.
// • If the temperature is equal to or higher than 25 degrees Celsius, an automatic fan motor should
//   turn on. When the temperature drops, the motor will turn off.
// • If the humidity in the environment is lower than or equal to 40%, the automatic irrigation system (water pump)
//   should turn on, and at the same time, the green LED will also turn on. When the humidity rises, the irrigation
//   system will turn off, and simultaneously, the green LED will turn off, and the red LED will turn on.

// Import Library
#include <DHT.h>
#include <LiquidCrystal.h>

// Define DHT11 Sensor
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define LCD
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);

// Define Pins
const int greenLED = 11;
const int redLED = 12;
const int fanRelay = 6;
const int waterpumpRelay = 7;

void setup() {
  // LEDs SETUP
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // RELAYs SETUP
  pinMode(fanRelay, OUTPUT);
  pinMode(waterpumpRelay, OUTPUT);

  // DHT11 SETUP
  dht.begin();

  // LCD SETUP
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Proyecto 2 UPSO");
  lcd.setCursor(0,1);
  lcd.print("Grupo 6");
}

void loop() {
  // Clear LCD
  delay(500);
  lcd.clear();

  // Collect Data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Display Temperature and Humidity
  String tString = "Temp.: " + String(temperature, 2) + "*C";
  String hString = "Hum.: " + String(humidity, 2) + "%";
  lcd.setCursor(0,0);
  lcd.print(tString);
  lcd.setCursor(0,1);
  lcd.print(hString);

  // Fan Automation
  if (temperature >= 25){
    digitalWrite(fanRelay, HIGH);
  }
  else {
    digitalWrite(fanRelay, LOW);
  }

  // Water Pump Automation
  if (humidity <= 40){
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(waterpumpRelay, HIGH);
  }
  else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(waterpumpRelay, LOW);
  }
}
