#include <iostream>

using namespace std;

#include "baraja.h"
#include "carta.h"

void inicializar(tBaraja &baraja)
{
    baraja.numero = 0;

    tCarta carta;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 14; j++)
        {
            carta.valor = j;
            carta.palo = i;
            if(insertar(baraja,carta) == false)
                cout << "elemento no insertado" << endl;
        }
    }
}

void mostrar(const tBaraja &baraja)
{
    if(baraja.numero == 0)
        cout << "baraja vacia" << endl;
    else{
        for (int i = 0; i < baraja.numero; i++)
        {
            tCarta carta = baraja.carta[i];
            mostrar_carta(carta);
        }
    }
    cout << endl;
}

int buscar(const tBaraja &baraja, int valor,int palo)
{
    int posicion = -1;
    int indice = 0;
    while( (posicion == -1) && (indice < baraja.numero) )
    {
        if(baraja.carta[indice].palo == palo && baraja.carta[indice].valor == valor)
            posicion = indice;
        indice++;
    }
    return posicion;
}

bool insertar(tBaraja &baraja, tCarta &carta)
{
    bool insertado = false;

    if (baraja.numero < CARTASBARAJA )
    {
        baraja.carta[baraja.numero++] = carta;
        insertado = true;
    }

    return insertado;
}

bool eliminar(tBaraja &baraja, int valor, int palo)
{
   bool eliminado = false;
   int posicion;

   posicion = buscar(baraja, valor,palo);

    if (posicion != -1)
   {
       for(int i = posicion; i < baraja.numero;i++)
           baraja.carta[i] = baraja.carta[i + 1];

        eliminado = true;
        baraja.numero--;
   }

    return eliminado;
}
