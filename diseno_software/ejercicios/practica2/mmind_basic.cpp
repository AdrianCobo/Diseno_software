#include "mmind_basic.h"
#include "intermediate_functions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

bool comprobarDigitosRepetidos(const unsigned int secret_array[], const int num_elem)
{
    bool found = false;
    for(int i = 0; i < num_elem - 1; i++)
    {
        for(int j = i+1; j < num_elem; j++)
        {
            if(secret_array[i] == secret_array[j])
            {
                found = true;
            }
        }
    }
    return found;
}

void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem)
{
    for(int i = 0; i < num_elem; i++)
    {
        intentoDigitos[i] = intento/pow(10,(num_elem-1-i));
        intento=intento-intentoDigitos[i]*pow(10,(num_elem-1-i));

    }
}

unsigned int calcularAciertos(const unsigned int numSecreto[],const unsigned int intentoDigitos[],const int num_elem)
{
    int numero_de_aciertos = 0;

    for(int i = 0; i < num_elem;i++)
    {
        if(numSecreto[i]==intentoDigitos[i])
            numero_de_aciertos++;
    }
    return numero_de_aciertos;
}

unsigned int calcularSemiaciertos(const unsigned int numSecreto[],const unsigned int intentoDigitos[],const int num_elem)
{
    int numero_de_semiaciertos = 0;
    unsigned int intento_manipulable[num_elem];
    unsigned int num_secreto_manipulable[num_elem];

    copiar_array(intento_manipulable,intentoDigitos,num_elem);
    copiar_array(num_secreto_manipulable,numSecreto,num_elem);

    bool repetir_semiaciertos = false;
    quitar_aciertos(intento_manipulable,num_secreto_manipulable,num_elem);

    for(int i = 0; i < num_elem;i++)
    {
        for(int j = 0; j < num_elem;j++)
        {
            if(num_secreto_manipulable[i]==intento_manipulable[j] && i != j && repetir_semiaciertos == false)
            {   numero_de_semiaciertos++;
                intento_manipulable[j] = 10;
                repetir_semiaciertos = true;
            }
        }
        repetir_semiaciertos = false;
    }
    return numero_de_semiaciertos;
}

