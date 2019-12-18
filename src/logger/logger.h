#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <sstream>
using namespace std;

class Logger
{
public:
    const char *subject;

    Logger(const char *s)
    {
        subject = s;
    }

    Logger(char *s)
    {
        subject = s;
    }

    friend ostream &operator<<(ostream &os, const Logger &l);

    friend ostream &operator<<(const Logger &l, const void *p);
};

#endif
