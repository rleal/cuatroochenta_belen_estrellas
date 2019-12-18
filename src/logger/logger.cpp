#include "logger.h"

static stringstream str;

void flushLog()
{
    Serial.print(str.str().c_str());
    str.str(string());
}

ostream &operator<<(ostream &os, const Logger &l)
{
    os << "\n"
       << l.subject << ": ";
    return os;
}

ostream &operator<<(const Logger &l, const void *p)
{
    str << l << p;
    return str;
}

ostream &operator<<(const Logger &l, const char *p)
{
    str << l << p;
    return str;
}

ostream &operator<<(const Logger &l, char *p)
{
    str << l << p;
    return str;
}

ostream &operator<<(const Logger &l, int p)
{
    str << l << p;
    return str;
}
