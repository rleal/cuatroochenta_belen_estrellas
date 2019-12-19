#include "helloWorldEvent.h"
#include "system/logger.h"
#include "belen/state.h"

static Logger l = Logger("Hello world");

/**
 * Método declarado en el header.
 */
const char *helloWorldEvent()
{
    return "HELLO_WORLD";
}

/**
 * Método declarado en el header.
 */
void onHelloWorld(uint8_t *payload, unsigned int length)
{
    l << "Hello world with data " << (char *)payload;
    l << "Hello world happend " << incrementAndGetHelloWorld() << " times";
}