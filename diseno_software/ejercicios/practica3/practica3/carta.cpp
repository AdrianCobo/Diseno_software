#include <iostream>
#include <string>
using namespace std;

#include "baraja.h"
#include "carta.h"

void mostrar_carta(tCarta &carta)
{
    std::string mostrar_valor = std::to_string(carta.valor);
    std::string mostrar_palo = std::to_string(carta.palo);

    if(carta.valor == 1)
        mostrar_valor = "As";

    else if(carta.valor == 11)
        mostrar_valor = "J";

    else if(carta.valor == 12)
        mostrar_valor = "Q";

    else if(carta.valor == 13)
        mostrar_valor = "K";

    if(carta.palo == 0)
        mostrar_palo = "Picas";

    else if(carta.palo == 1)
        mostrar_palo = "Rombos";

    else if(carta.palo == 2)
        mostrar_palo = "Treboles";

    else if(carta.palo == 3)
        mostrar_palo = "Corazones";

    imprimir_carta(mostrar_valor,mostrar_palo);
}

void imprimir_carta(string valor, string palo)
{
    cout << valor;
    cout << " de ";
    cout << palo << endl;
}
