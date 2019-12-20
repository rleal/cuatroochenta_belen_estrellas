/*
 * Implementación del estado global del Belen.
 */

#include "state.h"
#include "system/logger.h"

static Logger l = Logger("State");
static int helloWorld = 0;

/**
 * Método de ejemplo declarado en el header.
 */
int incrementAndGetHelloWorld()
{
    l << "Hello world incremented";
    return ++helloWorld;
}