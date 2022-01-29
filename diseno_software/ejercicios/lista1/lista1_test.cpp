#include <iostream>

using namespace std;

#include "lista1.h"
#include "lista1_test.h"

void lista1_test1(void)
{
    tLista lista;

    inicializar(lista);
    mostrar(lista);

    for(int i = 0; i < 10; i++)
    {
        tRegistro registro;
        registro.codigo = 123000 + i;
        registro.nombre[0] = 'A' + i;
        registro.nombre[1] = 0;
        registro.valor = 456.0 + i;
        if(insertar(lista,registro) == false)
            cout << "elemento no insertado" << endl;
    }
    mostrar(lista);

    cout << buscar(lista,123006) << endl;
    cout << buscar(lista,123011) << endl;

    cout << eliminar(lista,123006) << endl;
    mostrar(lista);

}
