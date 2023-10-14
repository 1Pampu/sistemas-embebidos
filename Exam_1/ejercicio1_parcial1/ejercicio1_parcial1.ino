// Import Library
#include <DHT.h>
#include <LiquidCrystal.h>

// Define DHT11 Sensor
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define LCD
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);

// Define LEDs Pins
const int greenLED = 11;
const int redLED = 12;

// Define Function to Delete the View on the Terminal
void clearSerialMonitor() {
  for (int i = 0; i < 50; i++) {
    Serial.println(" ");
  }
}

void setup() {
  // Serial SETUP
  Serial.begin(9600);

  // LEDs SETUP
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // DHT11 SETUP
  dht.begin();

  // LCD SETUP
  lcd.begin(16,2);

  // Show First Screen
  lcd.setCursor(2,0);
  lcd.print("TriARG Ltda.");
  lcd.setCursor(2,1);
  lcd.print("Bahia Blanca");

  // Wait 0.5seg and Clear LCD
  delay(500);
  lcd.clear();

  // Show Second Screen
  lcd.setCursor(1,0);
  lcd.print("Automatizacion");
  lcd.setCursor(2,1);
  lcd.print("Temp / Humd");
}

void loop() {
  // Wait 0.5seg and Clear LCD and Terminal
  delay(500);
  lcd.clear();
  clearSerialMonitor();

  // Collect Data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Display Temperature and Humidity
  String hString = "Humedad: " + String(humidity, 2) + "%";
  String tString = "Temp.: " + String(temperature, 2) + "*C";
  lcd.setCursor(0,0);
  lcd.print(hString);
  lcd.setCursor(0,1);
  lcd.print(tString);

  // Display Temperature and Humidity Difference
  float hDiff = humidity - 40;
  String hdString = "La diferencia de humedad es: " + String(hDiff, 2);
  float tDiff = temperature - 25;
  String tdString = "La diferencia de temperatura es: " + String(tDiff, 2);
  Serial.println(hdString);
  Serial.println(tdString);

  // Temperature Automation
  if (temperature >= 25){
    digitalWrite(greenLED, HIGH);
  }
  else {
    digitalWrite(greenLED, LOW);
  } 

  // Humidity Automation
  if (humidity <= 40){
    digitalWrite(redLED, HIGH);
  }  
  else {
    digitalWrite(redLED, LOW);
  }
}
