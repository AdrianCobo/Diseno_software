#include "vecino_tranquilo.h"

Vecino_Tranquilo::Vecino_Tranquilo(const char n[], const char t[]): Vecino(n,t)
{
    horadesayuno = 7 + rand() % 4;
};

void Vecino_Tranquilo::actividadesPorHora(const int tiempo) const
{
   if((tiempo >= 7) && (tiempo <= 23))
   {
        if(tiempo == horadesayuno)
            imprime_accion("esta desayunando");
   }
   Vecino::actividadesPorHora(tiempo);
}
