/*
 * Módulo principal.
 *
 * Coordina el resto de módulos del proyecto:
 ** - Belen. Para la lógica del Belen.
 ** - System/Logger. Para la centralización de logs.
 ** - System/WiFi. Para la conexión de red.
 ** - System/MQTT. Para la conexión del cliente MQTT.
 ** - System/Handler. Utilidad para el registro de eventos.
 */

#include "belen/belen.h"
#include "system/logger/logger.h"
#include "system/wifi/wifi.h"
#include "system/mqtt/mqtt.h"

/**
 * Configuración inicial.
 * 
 * Ahora mismo el programa no continúa hasta que se
 * ha resuelto la conexión de red. Cambiarlo 
 * si el sistema puede empezar a realizar acciones sin conexión.
 */
void setup()
{
    setUpBelen();
    setUpWifi();
    setUpMQTTClient();
}

/**
 * Bucle principal.
 */
void loop()
{
    MQTTClientLoop();
    belenLoop();
    flushLog();
    delay(1000);
}
