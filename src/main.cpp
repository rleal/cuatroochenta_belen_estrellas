/*
 * Módulo principal.
 * 
 * Para el desarrollo habitual de funcionalidades del belén
 * tan solo hay que definir los loops, eventos y estado necesarios.
 * 
 * Ejemplos:
 ** - Belen/Event/helloWorldEvent: evento de ejemplo.
 ** - Belen/Loop/helloWorldLoop: loop de ejemplo.
 ** - Belen/State/incrementAndGetHelloWorld: ejemplo de estado.
 ** - Belen/base: configuración y uso de los ejemplos anteriores.
 *
 * 
 * Índice de módulos del proyecto:
 * 
 ** - Belen. Para la lógica del belen.
 **** - Belen/Base. Para configurar el belén.
 **** - Belen/State. Para definir y gestionar el estado global del belén.
 **** - Belen/Event. Para definir y gestionar los eventos del belén.
 **** - Belen/Loop. Para definir loops individuales del belén.
 *
 ** - System. Para la lógica del sistema y utilidades.
 **** - System/Logger. Para la centralización de logs.
 **** - System/WiFi. Para la conexión de red.
 **** - System/MQTT. Para la conexión del cliente MQTT.
 **** - System/Handler. Utilidad para el registro de eventos.
 */

#include "belen/base.h"
#include "system/logger.h"
#include "system/wifi.h"
#include "system/mqtt.h"

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
