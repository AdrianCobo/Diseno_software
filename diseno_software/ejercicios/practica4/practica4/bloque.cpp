#include <iostream>
#include "bloque.h"
using namespace std;


Bloque::Bloque()
{
    ocupado = false;
    for(int i = 0; i < TAMANO_ID_BLOQUE; i++)
        valor_id[i] = 'X';
}

void Bloque::ocupar_bloque(const char nuevo_valor_id[])
{

    for(int i = 0; i < TAMANO_ID_BLOQUE; i++)
        {valor_id[i]=nuevo_valor_id[i];}

    ocupado=true;
}

void Bloque::desocupar_bloque(void)
{
    for(int i = 0; i < TAMANO_ID_BLOQUE; i++)
        {valor_id[i]='X';}
    ocupado=false;
}

void Bloque::obtener_valor(char valor[]) const
{
     for(int i = 0; i < TAMANO_ID_BLOQUE; i++)
        {valor[i] = valor_id[i];}
}

