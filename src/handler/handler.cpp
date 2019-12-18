#include "handler.h"
#include "logger/logger.h"
#include <map>
#include <string>

static Logger l = Logger("Handler");
static std::map<std::string, std::function<void(uint8_t *, unsigned int)>> handlers;

/**
 * Método declarado en el header.
 */
void addHandler(const char *topic, std::function<void(uint8_t *, unsigned int)> handler)
{
    l << "Subscribed for " << topic;
    handlers[std::string(topic)] = handler;
}

/**
 * Método declarado en el header.
 */
void handle(const char *topic, uint8_t *payload, unsigned int length)
{
    if (handlers.count(topic))
    {
        handlers[std::string(topic)](payload, length);
    }
    else
    {
        l << "No handler binded for " << topic;
    }
}

/**
 * Método declarado en el header.
 */
void eachKey(std::function<void(const char *)> f)
{
    for (const auto &myPair : handlers)
    {
        f(myPair.first.c_str());
    }
}
