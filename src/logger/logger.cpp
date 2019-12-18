#include "logger.h"

static stringstream str;

/**
 * Implementación del `flushLog`declarado en el header. 
 * Actualmente lo envía por la salida de Arduino.
 */
void flushLog()
{
    Serial.print(str.str().c_str());
    str.str(string());
}

/**
 * Sobrecarga del operador de streams 
 * con el logger a la derecha
 * para incluir el asunto del logger.
 */
ostream &operator<<(ostream &os, const Logger &l)
{
    os << "\n"
       << l.subject << ": ";
    return os;
}

/**
 * Sobrecargas del operador de streams
 * con el logger a la izquierda
 * para permitir encadenar mensajes de
 * distinto tipo. Añadir los que se necesiten
 * para soportar otros tipos.
 */
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
