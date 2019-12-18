#include "handler.h"
#include "logger/logger.h"
#include <map>
#include <string>

static Logger l = Logger("Handler");
static std::map<std::string, std::function<void(uint8_t *, unsigned int)>> handlers;

void addHandler(const char *topic, std::function<void(uint8_t *, unsigned int)> handler)
{
    l << "Subscribed for " << topic;
    handlers[std::string(topic)] = handler;
}

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

void eachKey(std::function<void(const char *)> f)
{
    for (const auto &myPair : handlers)
    {
        f(myPair.first.c_str());
    }
}
