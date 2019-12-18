#include "arduino/arduino.h"
#include "wifi/wifi.h"
#include "mqtt/mqtt.h"

void setup()
{
    setUpArduino();
    setUpWifi();
    setUpMQTTClient();
}

void loop()
{
    reconnectMQTTClientIfRequired();
    //int sensorLuz = analogRead(A0);

    //if (sensorLuz < 250)
    //{
    //  digitalWrite(D0, HIGH);
    //}
    //else
    //{
    //  digitalWrite(D0, LOW);
    //}
    delay(1000);
}
