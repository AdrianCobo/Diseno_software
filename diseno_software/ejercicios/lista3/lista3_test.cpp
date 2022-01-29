#include <iostream>

using namespace std;

#include "lista3.h"
#include "lista3_test.h"

void lista1_test1(void)
{
    tLista* lista = new tLista;

    inicializar(lista);
    mostrar(lista);

    tRegistro* registro = new tRegistro;
    for(int i = 0; i < 10; i++)
    {
        registro->codigo = 123000 + i;
        registro->nombre[0] = 'A' + i;
        registro->nombre[1] = 0;
        registro->valor = 456.0 + i;
        if(insertar(lista,registro) == false)
            cout << "elemento no insertado" << endl;
    }
    mostrar(lista);

    cout << buscar(lista,123006) << endl;
    cout << buscar(lista,123011) << endl;

    cout << eliminar(lista,123006) << endl;
    mostrar(lista);

    destruir(lista);
    inicializar(lista);

    delete registro;
    delete lista;

}
