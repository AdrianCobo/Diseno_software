#ifndef VECINO_H_INCLUDED
#define VECINO_H_INCLUDED

#include "Habitante.h"

class Vecino: public Habitante
{

public:
    Vecino(const char n[],const char t[]);
    void actividadesPorHora(const int tiempo) const;
protected:
    int hora_salida;
    int hora_llegada;
    int hora_cena;
};

#endif // VECINO_H_INCLUDED
