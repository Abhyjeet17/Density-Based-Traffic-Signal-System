// Arduino code for Density-Based Traffic Control System

// IR Sensors (Analog Pins A0-A3)
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3

// Traffic Lights - LEDs
#define R1 8
#define Y1 9
#define G1 10

#define R2 11
#define Y2 12
#define G2 13

#define R3 5
#define Y3 4
#define G3 3

#define R4 2
#define Y4 A4
#define G4 A5

void setup() {
  // Set LED pins as OUTPUT
  int ledPins[] = {R1, Y1, G1, R2, Y2, G2, R3, Y3, G3, R4, Y4, G4};
  for (int i = 0; i < 12; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Set IR sensor pins as INPUT
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
}

void loop() {
  bool s1 = digitalRead(SENSOR1);
  bool s2 = digitalRead(SENSOR2);
  bool s3 = digitalRead(SENSOR3);
  bool s4 = digitalRead(SENSOR4);

  if (s1) {
    setLights(G1, Y2, R3, R4);
  }
  else if (s2) {
    setLights(R1, G2, Y3, R4);
  }
  else if (s3) {
    setLights(R1, R2, G3, Y4);
  }
  else if (s4) {
    setLights(Y1, R2, R3, G4);
  }
  else {
    // Default Cycle
    setLights(G1, Y2, R3, R4);
    delay(7000);

    clearAll();
    setLights(R1, G2, Y3, R4);
    delay(7000);

    clearAll();
    setLights(R1, R2, G3, Y4);
    delay(7000);

    clearAll();
    setLights(Y1, R2, R3, G4);
    delay(7000);

    clearAll();
  }

  clearAll();  // Clear before next check
}

void setLights(int l1, int l2, int l3, int l4) {
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, HIGH);
}

void clearAll() {
  int ledPins[] = {R1, Y1, G1, R2, Y2, G2, R3, Y3, G3, R4, Y4, G4};
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
