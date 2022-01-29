#ifndef HABITANTE_H_INCLUDED
#define HABITANTE_H_INCLUDED

#include "EnteAbstracto.h"

class Habitante: public EnteAbstracto
{

public:
    Habitante(const char n[],const char t[]): EnteAbstracto(n, t) {}; // los constructores no se heredan pero podemos invocar al del padre
    void actividadesPorHora(const int tiempo) const {};
};

#endif // HABITANTE_H_INCLUDED
