#include "Conserje.h"

void Conserje::actividadesPorHora(const int tiempo) const
{
   if((tiempo >= 6) && (tiempo <= 14))
   {
        if(tiempo % 3 == 0)
            imprime_accion("Limpia la escalera");
        if(tiempo % 6 == 1)
            imprime_accion("hace un arreglo");
   }
}
