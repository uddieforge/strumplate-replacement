#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap = Adafruit_MPR121();

const int numPads = 12;
const int touchThreshold = 6; // en dessous de cette valeur => considéré touché

// pad 0 -> D2, pad 1 -> D3, ..., pad 11 -> D13
const int gatePins[numPads] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numPads; i++) {
    pinMode(gatePins[i], OUTPUT);
    digitalWrite(gatePins[i], LOW);
  }

  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 non détecté, vérifie le câblage !");
    while (1);
  }

  Serial.println("MPR121 détecté !");
}

void loop() {
  for (int pad = 0; pad < numPads; pad++) {
    uint16_t filtered = cap.filteredData(pad);
    bool isTouched = filtered < touchThreshold;

    digitalWrite(gatePins[pad], isTouched ? HIGH : LOW);
  }

  delay(20);
}
