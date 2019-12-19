/*
 * Módulo de handlers.
 *
 * Utilidad para registrar los eventos y vincularlos a su propio callback.
 */

#ifndef HANDLER_H
#define HANDLER_H

#include <functional>

/**
 * Para registrar un evento (topic) y su callbaock.
 */
void addHandler(const char *topic, std::function<void(uint8_t *, unsigned int)> handler);

/**
 * Para reaccionar a un mensaje MQTT entrante.
 */
void handle(const char *topic, uint8_t *payload, unsigned int length);

/**
 * Para iterar sobre los eventos registrados.
 */
void eachKey(std::function<void(const char *)> f);

#endif
