#include <iostream>

using namespace std;

#include "lista3.h"

void Lista::mostrar()
{
    if(contador == 0)
        cout << "lista vacia" << endl;

    for (int i = 0; i < contador; i++)
    {
        cout << registros[i]->codigo << " || ";
        cout << registros[i]->nombre << " || ";
        cout << registros[i]->valor << " || ";
        cout << endl;
    }
    cout << endl;
}

bool Lista::insertar(tRegistro* registro)
{
    bool insertado = false;

    if (contador < TAMANO )
    {
        registros[contador++] = new tRegistro(*registro);
        insertado = true;
    }

    return insertado;
}

int Lista::buscar(int codigo)
{
    int posicion = -1;
    int indice = 0;
    while( (posicion == -1) && (indice < contador) )
    {
        if(registros[indice]->codigo == codigo)
            posicion = indice;
        indice++;

    }
    return posicion;
}

bool Lista::eliminar(int codigo)
{
    bool eliminado = false;
    int posicion;

    posicion = buscar(codigo);

    if (posicion != -1)
    {
        delete registros[posicion];
        for(int i = posicion; i < contador - 1;i++)
           registros[i] = registros[i + 1];

        eliminado = true;
        contador--;
    }

    return eliminado;
}

Lista::~Lista()
{
    for (int i = 0; i < contador; i++)
        delete registros[i];
}
























