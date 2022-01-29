#ifndef VECINO_TRANQUILO_H_INCLUDED
#define VECINO_TRANQUILO_H_INCLUDED

#include "vecino.h"

class Vecino_Tranquilo: public Vecino
{
public:
    Vecino_Tranquilo(const char n[],const char t[]); // los constructores no se heredan pero podemos invocar al del padre
    void actividadesPorHora(const int tiempo) const;
protected:
    int horadesayuno;
};

#endif // VECINO_TRANQUILO_H_INCLUDED
