#include <iostream>

using namespace std;

#include "lista1.h"

void inicializar(tLista& lista)
{
    lista.contador = 0;
}

void mostrar(const tLista& lista)
{
    if(lista.contador == 0)
        cout << "lista vacia" << endl;

    for (int i = 0; i < lista.contador; i++)
    {
        cout << lista.registros[i].codigo << " || ";
        cout << lista.registros[i].nombre << " || ";
        cout << lista.registros[i].valor << " || ";
        cout << endl;
    }
    cout << endl;
}

bool insertar(tLista& lista, tRegistro& registro)
{
    bool insertado = false;

    if (lista.contador < TAMANO )
    {
        lista.registros[lista.contador++] = registro;
        insertado = true;
    }

    return insertado;
}

int buscar(const tLista& lista, int codigo)
{
    int posicion = -1;
    int indice = 0;
    while( (posicion == -1) && (indice < lista.contador) )
    {
        if(lista.registros[indice].codigo == codigo)
            posicion = indice;
        indice++;

    }
    return posicion;
}

bool eliminar(tLista& lista, int codigo)
{
    bool eliminado = false;
    int posicion;

    posicion = buscar(lista, codigo);

    if (posicion != -1)
    {
        for(int i = posicion; i < lista.contador;i++)
            lista.registros[i] = lista.registros[i + 1];

        eliminado = true;
        lista.contador--;
    }

    return eliminado;
}


























