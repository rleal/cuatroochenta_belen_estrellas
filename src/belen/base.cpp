#include "base.h"
#include "system/handler.h"
#include "system/logger.h"
#include "event/helloWorldEvent.h"
#include "loop/helloWorldLoop.h"

static Logger l = Logger("BELEN");

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
    addHandler(helloWorldEvent(), onHelloWorld);

    l << "Belen ready";
}

/**
 * Método declarado en el header.
 */
void belenLoop()
{
    helloWorldLoop();
}
