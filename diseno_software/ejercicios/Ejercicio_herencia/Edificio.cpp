#include "Edificio.h"

#include <iostream>
using namespace std;

Edificio::Edificio(Habitante* h[], int num_hab)
{
    num_habitantes = num_hab;
    for(int i = 0; i < num_habitantes; i++)
    {
        habitantes[i] = h[i];
    }
}

void Edificio::simularUnDia(void)
{

    for(int hora = 0; hora < 24; hora++)
    {
        cout << "---------- " << hora << " h ---------------------" << endl;
        for(int i = 0; i<num_habitantes; i++)
            habitantes[i]->actividadesPorHora(hora);
    }
}
