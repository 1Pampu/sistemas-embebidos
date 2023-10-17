// Define LEDs Pins
const int groundFloor = 13;
const int topFloor = 12;
const int backyard = 11;
const int garage = 10;
const int gate = 9;
const int alarm = 8;

void setup() {
  // Serial SETUP
  Serial.begin(9600);

  // LEDs SETUP
  pinMode(groundFloor, OUTPUT);
  pinMode(topFloor, OUTPUT);
  pinMode(backyard, OUTPUT);
  pinMode(alarm, OUTPUT);

  // RELAYs SETUP
  pinMode(garage, OUTPUT);
  pinMode(gate, OUTPUT);
}

void loop() {
  // Check if serial contains data
  if (Serial.available()){
    // Read Data
    char status = Serial.read();

    // GroundFloor
    if (status == 'A' || status == 'a'){
      digitalWrite(groundFloor, HIGH);
    }
    if (status == 'B' || status == 'b'){
      digitalWrite(groundFloor, LOW);
    }
  
    // TopFloor
    if (status == 'C' || status == 'c'){
      digitalWrite(topFloor, HIGH);
    }
    if (status == 'D' || status == 'd'){
      digitalWrite(topFloor, LOW);
    }

    // Backyard
    if (status == 'E' || status == 'e'){
      digitalWrite(backyard, HIGH);
    }
    if (status == 'F' || status == 'f'){
      digitalWrite(backyard, LOW);
    }

    // Alarm
    if (status == '1'){
      digitalWrite(alarm, HIGH);
    }
    if (status == '0'){
      digitalWrite(alarm, LOW);
    }

    // Garage
    if (status == '2'){
      digitalWrite(garage, HIGH);
    }
    if (status == '3'){
      digitalWrite(garage, LOW);
    }

    // Gate
    if (status == '4'){
      digitalWrite(gate, HIGH);
    }
    if (status == '5'){
      digitalWrite(gate, LOW);
    }
  }
}
