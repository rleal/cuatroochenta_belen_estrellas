#ifndef HANDLER_H
#define HANDLER_H

#include <functional>

void addHandler(const char *topic, std::function<void(uint8_t *, unsigned int)> handler);

void handle(const char *topic, uint8_t *payload, unsigned int length);

void eachKey(std::function<void(const char *)> f);

#endif
