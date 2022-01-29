#include <iostream>
#include <ctime>
#include <cstdlib>
#include "intermediate_functions.h"
#include "mmind_basic.h"

using namespace std;

int obtener_dificultad(void)
{
    int dificultad = 0;

    do
    {
        cout <<"--------------------------------------------------------------------------------" << endl;
        cout <<"Por favor, selecciona el nivel de juego introduciendo un numero del 1 al 3                   " << endl;
        cout <<"1. Nivel básico: numero secreto con 3 digitos desde el 1 al 4 con 6 intentos para adivinarlo" << endl;
        cout <<"2. Nivel básico: numero secreto con 4 digitos desde el 1 al 6 con 8 intentos para adivinarlo" << endl;
        cout <<"3. Nivel básico: numero secreto con 5 digitos desde el 1 al 8 con 10 intentos para adivinarlo"<< endl;
        cout <<"--------------------------------------------------------------------------------" << endl;
        cout <<"" << endl;
        cin >> dificultad;
    }
    while(dificultad < 1 || dificultad > 3);

    return dificultad;
}

int obtener_num_elem(const int dificultad_seleccionada)
{
    int num_elem = 0;
    if(dificultad_seleccionada == 1)
    {
        num_elem = 3;
    }else if(dificultad_seleccionada == 2)
    {
        num_elem = 4;
    }else
    {
        num_elem = 5;
    }
    return num_elem;
}

int obtener_num_intentos(int dificultad_seleccionada)
{
    int num_intentos = 0;
    if(dificultad_seleccionada == 1)
    {
        num_intentos = 6;
    }else if(dificultad_seleccionada == 2)
    {
        num_intentos = 8;
    }else
    {
        num_intentos = 10;
    }
    return num_intentos;
}

bool obtener_repeticiones(void)
{
    bool se_esperan_digitos_repetidos = false;
    int seleccion = 0;

    do
    {
        cout <<"--------------------------------------------------------------------------------" << endl;
        cout <<"¿Quieres digitos repetidos en el número secreto?" << endl;
        cout <<"Por favor, introduce 1 si quieres digitos repetidos o 2 si no los quieres" << endl;
        cout <<"--------------------------------------------------------------------------------" << endl;
        cout <<"" << endl;
        cin >> seleccion;
    }
    while(seleccion < 1 || seleccion > 2);
    if(seleccion == 1)
    {
        se_esperan_digitos_repetidos = true;
    }
    return se_esperan_digitos_repetidos;
}

void generar_numero_aleatorio(int dificultad_seleccionada,unsigned int array_secreta[],bool se_esperan_digitos_repetidos
                                ,const int num_elem)
{
    int num_mas_alto = 0;
    bool verificar_digitos_repetidos = false;

    if(dificultad_seleccionada == 1)
    {
        num_mas_alto = 4;
        rellenarArrayAleatoriamente(num_elem,num_mas_alto,array_secreta);

    }else if(dificultad_seleccionada == 2)
    {
        num_mas_alto = 6;
        rellenarArrayAleatoriamente(num_elem,num_mas_alto,array_secreta);
    }else
    {
        num_mas_alto = 8;
        rellenarArrayAleatoriamente(num_elem,num_mas_alto,array_secreta);
    }

    verificar_digitos_repetidos = comprobarDigitosRepetidos(array_secreta,num_elem);

    if(verificar_digitos_repetidos != se_esperan_digitos_repetidos)
    {
        generar_numero_aleatorio(dificultad_seleccionada,array_secreta,se_esperan_digitos_repetidos,num_elem);
    }
    return;
}

void rellenarArrayAleatoriamente(const int num_elem,const int num_mas_alto,unsigned int array_secreta[])
{
    int digito = 0;
    for (int i = 0;i < num_elem;i++)
        {
            digito = 1 + random() % (num_mas_alto);
            array_secreta[i] = digito;
        }
}

bool jugar(const int dificultad_seleccionada,const unsigned int numSecreto[],const int num_elem,int num_intentos)
{
    bool num_acertado = false;
    unsigned int intentoDigitos[5];

    while(num_intentos > 0 && num_acertado == false)
    {
        int intento;
        int numero_aciertos = 0;
        int numero_semiaciertos = 0;
        cout <<"Introduce el numero que crees que es" << endl;
        cout <<"" << endl;
        cin >> intento;

        rellenarIntento(intento,intentoDigitos,num_elem);
        numero_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
        if(numero_aciertos == num_elem)
            num_acertado = true;

        cout <<"Aciertos:" << numero_aciertos << endl;
        numero_semiaciertos = calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
        cout <<"Semiaciertos:" << numero_semiaciertos << endl;
        cout <<"" << endl;
        num_intentos--;
    }
    return num_acertado;
}

void pantalla_final(bool victoria)
{
    if(victoria == true)
    {
        cout <<"----------------------------------------"<< endl;
        cout <<"¡¡¡¡¡¡¡¡GANASTESSSSS!!!!!"<< endl;
        cout <<"----------------------------------------"<< endl;

    }else
    {
        cout <<"----------------------------------------"<< endl;
        cout <<"NO TE QUEDAN MAS INTENTOS, HAS PERDIDO =("<< endl;
        cout <<"----------------------------------------"<< endl;
    }
}

void copiar_array(unsigned int array_copiada[], const unsigned int array_original[],const int num_elem)
{
    for(int k = 0; k < num_elem; k++)
    {
        array_copiada[k] = array_original[k];
    }
}

void quitar_aciertos(unsigned int intento_manipulable[],unsigned int num_secreto_manipulable[],const int num_elem)
{
    for(int i = 0; i < num_elem;i++)
    {
        if(num_secreto_manipulable[i]==intento_manipulable[i])
        {
            num_secreto_manipulable[i] = 0;
            intento_manipulable[i]=9;
        }
    }
}
