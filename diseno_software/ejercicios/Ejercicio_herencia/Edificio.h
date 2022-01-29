#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED

#include "Habitante.h"

const int MAX_HABITANTES = 100;

class Edificio
{
    Habitante* habitantes[MAX_HABITANTES];
    int num_habitantes;
public:
    Edificio(Habitante* h[], int num_hab);
    void simularUnDia(void);
};

#endif // EDIFICIO_H_INCLUDED
