#include "vecino.h"

Vecino::Vecino(const char n[], const char t[]): Habitante(n,t)
{
    hora_llegada = 18 + rand() % 4;
}

void Vecino::actividadesPorHora(const int tiempo) const
{
   if( (tiempo >= 7) && (tiempo <= 23) )
   {
        if(tiempo == hora_llegada)
            imprime_accion("ha llegado a casa");
   }
}
