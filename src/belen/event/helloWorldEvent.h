/*
 * Declaración de un evento de ejemplo.
 */

#ifndef HELLO_WORLD_EVENT_H
#define HELLO_WORLD_EVENT_H

#include <stdint.h>

/**
 * Nombre del evento.
 */
const char *helloWorldEvent();

/**
 * Método para reaccionar al evento.
 */
void onHelloWorld(uint8_t *payload, unsigned int length);

#endif