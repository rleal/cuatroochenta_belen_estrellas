#include <Arduino.h>
#include "wifi/wifi.h"
#include "mqtt/mqtt.h"

void setup()
{
  Serial.begin(115200);

  pinMode(A0, INPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);

  setUpWifi();
  setUpMQTTClient();
}

void loop()
{
  reconnectMQTTClientIfRequired();
  int sensorLuz = analogRead(A0);

  if (sensorLuz < 250)
  {
    digitalWrite(D0, HIGH);
  }
  else
  {
    digitalWrite(D0, LOW);
  }
  delay(1000);
}
