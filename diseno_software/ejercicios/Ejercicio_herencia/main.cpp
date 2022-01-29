#include <iostream>
using namespace std;

#include "Edificio.h"
#include "Conserje.h"
#include "Habitante.h"
#include "vecino_tranquilo.h"

int main()
{
    Conserje hab1("Freddy", "Conserje");
    Vecino_Tranquilo hab2("Eloy", "vecinotranquilo");
    Vecino_Tranquilo hab3("Frank", "vecinotranquilo");

    Habitante* habitantes[MAX_HABITANTES];
    int num_habitantes = 0;
    habitantes[num_habitantes++] = &hab1; // Es una array de punteros, así que pasamos el puntero al ¿objeto?
    habitantes[num_habitantes++] = &hab2;
    habitantes[num_habitantes++] = &hab3;

    Edificio edificio1(habitantes, num_habitantes);
    edificio1.simularUnDia();

    return 0;
}
