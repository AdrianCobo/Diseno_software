#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "baraja.h"
#include "poker_structs.h"
#include "mano.h"
#include "carta.h"

void repartirMano(tMano *mano, tBaraja &baraja)
{
    tCarta carta;
    for(int i = 0; i < 5; i++)
    {
        carta = sacar_carta_baraja(baraja);
        mano->carta[i] = carta;
    }
    ordenarMano(mano);
}

tCarta sacar_carta_baraja(tBaraja &baraja)
{
    int resulado_busqueda = -1;
    int valor = 0;
    int palo = 0;
    while(resulado_busqueda == -1)
    {
        valor = 1 + random() % (13);
        palo = 1 + random() % (4);
        resulado_busqueda = buscar(baraja,valor,palo);
    }
    eliminar(baraja,valor,palo);
    tCarta carta;
    carta.valor = valor;
    carta.palo = palo;
    return carta;
}

void ordenarMano(tMano *mano)
{
    for(short i=1; i<CARTASMANO; i++)
        for(short j=0; j<CARTASMANO-i; j++)
            if(mano->carta[j].valor > mano->carta[j+1].valor)
            {
                tCarta swap = mano->carta[j];
                mano->carta[j] = mano->carta[j+1];
                mano->carta[j+1] = swap;
            }
}

void mostrarMano(tMano *mano)
{
    tCarta carta;

    for(int i = 0; i < 5; i++)
    {
        carta = mano->carta[i];
        mostrar_carta(carta);
    }
}

bool revisar_color(tMano *mano)
{
    bool mismo_color = true;
    int color_a_comparar = mano->carta[0].palo;
    for(int i = 0; i < CARTASMANO; i++)
    {
        if(color_a_comparar != mano->carta[i].palo)
            mismo_color=false;
    }
    return mismo_color;
}

bool revisar_escalera(int array_comprobador[])
{
    int valores_en_escalera = 1;
    bool escalera = false;
    for(int i = 0; i < VALORES-1; i++)
    {
        if(array_comprobador[i]==array_comprobador[i+1]&&array_comprobador[i]!=0)
            valores_en_escalera++;
    }
    if(valores_en_escalera == 5)
        escalera=true;
    valores_en_escalera = 1;
    for(int i = 9; i < VALORES-1; i++)
    {
        if(array_comprobador[i]==array_comprobador[i+1]&&array_comprobador[i]!=0)
            valores_en_escalera++;
    }
    if(valores_en_escalera==4&&array_comprobador[0]==array_comprobador[9])
        escalera=true;
    return escalera;
}

int calcularPuntosMano(tMano *mano)
{
    int mayor_mayor = 0;
    int menor_mayor = 0;
    int array_comprobador[VALORES] = {0};
    int puntuacion = 0;
    bool mismo_color = true;

    for (int i = 0; i < CARTASMANO; i++)
    {
        array_comprobador[mano->carta[i].valor-1]+=1;
    }

    mismo_color = revisar_color(mano);
    bool escalera=revisar_escalera(array_comprobador);
    for (int j = 0; j < VALORES; j++)
    {
        if(mayor_mayor < array_comprobador[j])
        {
            mayor_mayor = array_comprobador[j];
            array_comprobador[j] = 0;
        }
        if(menor_mayor < array_comprobador[j])
            menor_mayor = array_comprobador[j];
    }
    puntuacion = obtener_puntos(mayor_mayor,menor_mayor,mismo_color,escalera);
    return puntuacion;
}

int obtener_puntos(const int mayor_mayor,const int menor_mayor,const bool mismo_color,const bool escalera)
{
    int puntuacion = 0;
    if(mayor_mayor == 4)//poker
    {
        puntuacion = 8;
    }else if(mayor_mayor == 3 && menor_mayor ==2)//full
    {
        puntuacion = 7;
    }else if(mismo_color)//color
    {
        puntuacion = 6;
    }else if(escalera)//escalera
    {
        puntuacion = 5;
    }else if(mayor_mayor == 3)//trio
    {
        puntuacion = 4;
    }else if(mayor_mayor == 2 && menor_mayor == 2)//doble pareja
    {
        puntuacion = 3;
    }else if(mayor_mayor == 2)//pareja
    {
        puntuacion = 2;
    }else//carta alta
        puntuacion = 1;

    return puntuacion;
}

string obtener_nombre_puntuaje(tMano *mano)
{
    string nombre_puntuacion = "";
    int puntuacion = calcularPuntosMano(mano);

    if(puntuacion == 8)
        nombre_puntuacion = "poker";

    else if(puntuacion == 7)
        nombre_puntuacion = "full";

    else if(puntuacion == 6)
        nombre_puntuacion = "color";

    else if(puntuacion == 5)
        nombre_puntuacion = "escalera";

    else if(puntuacion == 4)
        nombre_puntuacion = "trio";

    else if(puntuacion == 3)
        nombre_puntuacion = "doble pareja";

    else if(puntuacion == 2)
       nombre_puntuacion = "pareja";

    else
        nombre_puntuacion = "carta alta";

    return nombre_puntuacion;
}
