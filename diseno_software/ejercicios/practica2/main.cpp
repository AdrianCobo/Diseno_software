#include <iostream>
#include <ctime>
#include <cstdlib>
#include "intermediate_functions.h"

using namespace std;

int main()
{
    srand(time(NULL));
    unsigned int array_secreto[5];

    const int dificultad_seleccionada = obtener_dificultad();
    int num_elem = obtener_num_elem(dificultad_seleccionada);
    int num_intentos = obtener_num_intentos(dificultad_seleccionada);
    bool se_esperan_digitos_repetidos = obtener_repeticiones();
    generar_numero_aleatorio(dificultad_seleccionada, array_secreto,se_esperan_digitos_repetidos,num_elem);
    bool victoria = jugar(dificultad_seleccionada,array_secreto,num_elem,num_intentos);
    pantalla_final(victoria);
    return 0;
}
