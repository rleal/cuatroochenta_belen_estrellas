#include "logger.h"

static stringstream str;

ostream &operator<<(ostream &os, const Logger &l)
{
    os << l.subject << ": ";
    return os;
}

ostream &operator<<(const Logger &l, const void *p)
{
    str.str(string());
    str << l << p;
    Serial1.println(str.str().c_str());
    return str;
}
