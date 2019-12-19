#include "belen.h"
#include "system/handler/handler.h"
#include "system/logger/logger.h"

static Logger l = Logger("BELEN");

/**
 * Constantes para los eventos a los que se suscribe
 */
const char *HELLO_WORLD_TOPIC = "HELLO_WORLD";

/**
 * Ejemplo de handler para un evento.
 * Los handlers de verdad deberían importarse de su propio módulo.
 */
void onHelloWorld(uint8_t *payload, unsigned int length)
{
    l << "Handle for " << (char *)payload;
}

/**
 * Método declarado en el header.
 */
void setUpBelen()
{
    // Configuración de comunicación
    Serial.begin(115200);

    // Configuración de pins
    pinMode(A0, INPUT);
    pinMode(D0, OUTPUT);
    pinMode(D1, INPUT);

    // Registro de eventos
    addHandler(HELLO_WORLD_TOPIC, onHelloWorld);

    l << "Belen ready";
}

/**
 * Método declarado en el header.
 */
void belenLoop()
{
    // EJEMPLO
    //int sensorLuz = analogRead(A0);

    //if (sensorLuz < 250)
    //{
    //  digitalWrite(D0, HIGH);
    //}
    //else
    //{
    //  digitalWrite(D0, LOW);
    //}

    // if (2 > 3)
    // {
    //     //digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    //     // but actually the LED is on; this is because
    //     // it is active low on the ESP-01)
    // }
    // else
    // {
    //     //digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
    // }
}
