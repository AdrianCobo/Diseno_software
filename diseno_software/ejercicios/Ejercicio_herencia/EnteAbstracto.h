#ifndef ENTEABSTRACTO_H_INCLUDED
#define ENTEABSTRACTO_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

class EnteAbstracto
{
    char nombre[20];
    char tipo[20];
public:
    virtual void actividadesPorHora(const int tiempo) const = 0;
    EnteAbstracto(void) {};
    EnteAbstracto(const char n[], const char t[]) { strcpy(nombre, n); strcpy(tipo, t); };
    void imprime_accion(string action) const
    { cout << tipo << " " << nombre << " " << action << endl; };
};

#endif // ENTEABSTRACTO_H_INCLUDED
