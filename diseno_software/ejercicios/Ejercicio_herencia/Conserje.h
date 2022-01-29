#ifndef CONSERGE_H_INCLUDED
#define CONSERGE_H_INCLUDED
#include "Habitante.h"

class Conserje: public Habitante
{
public:
    Conserje(const char n[],const char t[]): Habitante(n, t) {};// los constructores no se heredan pero podemos invocar al del padre
    void actividadesPorHora(const int tiempo) const;

};

#endif // CONSERGE_H_INCLUDED
