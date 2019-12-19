/*
 * Módulo principal.
 *
 * Coordina el resto de módulos del proyecto:
 ** - Arduino. Para la lógica de la placa.
 ** - Logger. Para la centralización de logs.
 ** - WiFi. Para la conexión de red.
 ** - MQTT. Para la conexión del cliente MQTT.
 ** - Handler. Utilidad para el registro de eventos.
 */

#include "arduino/arduino.h"
#include "logger/logger.h"
#include "wifi/wifi.h"
#include "mqtt/mqtt.h"

/**
 * Configuración inicial.
 * 
 * Ahora mismo el programa no continúa hasta que se
 * ha resuelto la conexión de red. Cambiarlo 
 * si el sistema puede empezar a realizar acciones sin conexión.
 */
void setup()
{
    setUpArduino();
    setUpWifi();
    setUpMQTTClient();
}

/**
 * Bucle principal.
 */
void loop()
{
    MQTTClientLoop();
    arduinoLoop();
    flushLog();
    delay(1000);
}
