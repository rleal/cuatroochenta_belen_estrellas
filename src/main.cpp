#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);

}

void loop() {
  Serial.println("Hola mundo");

  digitalWrite(D0, HIGH);
  int value = digitalRead(D1);

  delay(1000);
  // put your main code here, to run repeatedly:
}