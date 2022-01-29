#include <iostream>

using namespace std;

#include "lista3.h"
#include "lista3_test.h"

void lista1_test1(void)
{
    Lista* lista = new Lista;

    lista->mostrar();

    tRegistro* registro = new tRegistro;
    for(int i = 0; i < 10; i++)
    {
        registro->codigo = 123000 + i;
        registro->nombre[0] = 'A' + i;
        registro->nombre[1] = 0;
        registro->valor = 456.0 + i;
        if(lista->insertar(registro) == false)
            cout << "elemento no insertado" << endl;
    }
    lista->mostrar();

    cout << lista->buscar(123006) << endl;
    cout << lista->buscar(123011) << endl;

    cout << lista->eliminar(123006) << endl;
    lista->mostrar();

    delete registro;
    delete lista;

}
