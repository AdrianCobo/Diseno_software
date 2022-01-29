#include <iostream>

using namespace std;

#include "baraja.h"
#include "carta.h"
#include "mano.h"
#include "juego.h"

void anadirMano(tJuego &juego, tBaraja &baraja)
{
    tMano* mano = new tMano;
    repartirMano(mano,baraja);
    juego.mano[juego.numero++] = mano;

}

void encontrarManoGanadora(tJuego &juego)
{
    int array_puntuaje[juego.numero] = {0};
    int puntuacion_mayor = 0;

    calcular_puntos_manosenjuego(juego,array_puntuaje);
    for(int j= 0; j < juego.numero; j++)
    {
        if(array_puntuaje[j] > puntuacion_mayor)
        {
            puntuacion_mayor = array_puntuaje[j];
        }
    }
    imprimir_ganadores(juego,puntuacion_mayor,array_puntuaje);

}

void calcular_puntos_manosenjuego(tJuego &juego,int array_puntuaje[])
{
    for(int i = 0; i < juego.numero; i++)
    {
        array_puntuaje[i] = calcularPuntosMano(juego.mano[i]);
        cout << "Jugador " << i+1 << ":    Puntuacion: " << array_puntuaje[i] <<" - "
                                    << obtener_nombre_puntuaje(juego.mano[i]) <<endl;
        mostrarMano(juego.mano[i]);
        cout << endl;
    }
}

void imprimir_ganadores(tJuego juego,const int puntuacion_mayor,const int array_puntuaje[])
{
    int empates = revisar_empate(juego,puntuacion_mayor,array_puntuaje);
    int flag = 0;
    string jugadores_empatados = "";
    string jugada_empatada = "";
    for (int i = 0; i <juego.numero; i++)
    {
        if(puntuacion_mayor == array_puntuaje[i] && empates == 0)
            cout << "RESULTADO: Jugador " << i+1 << ": GANADOR con: " << obtener_nombre_puntuaje(juego.mano[i]) << endl;

        else if(puntuacion_mayor == array_puntuaje[i] && flag <= empates)
        {

            if(flag < empates)
            {
                jugadores_empatados = jugadores_empatados + "Jugador " + std::to_string(i+1) + ", ";
                flag++;
            }else
            {
                jugadores_empatados = jugadores_empatados + "Jugador " + std::to_string(i+1);
                jugada_empatada = obtener_nombre_puntuaje(juego.mano[i]);
            }
        }
    }
    if(empates != 0)
        cout << "RESULTADO: "<< jugadores_empatados << ": EMPATE con: " << jugada_empatada << endl;
}

int revisar_empate(tJuego &juego,const int puntuacion_mayor,const int array_puntuaje[])
{
    int empate = -1;

    for(int j= 0; j < juego.numero; j++)
    {
        if(array_puntuaje[j] == puntuacion_mayor)
            empate++;
    }
    return empate;
}

int obtener_numero_jugadores()
{
    int numero_jugadores = 0;
    while(numero_jugadores < 2 || numero_jugadores > 4)
    {    cout <<"Elige numero de jugadores (de 2 a 4): "<< endl;
         cin >> numero_jugadores;

         if(numero_jugadores < 2 || numero_jugadores > 4)
            cout <<"La opcion elegida no es valida"<< endl;
    }

    return numero_jugadores;
}

bool seguir_jugando()
{
    int seguir_jugando = -1;

    while(seguir_jugando < 0 || seguir_jugando > 1)
    {    cout <<"Pulsa 1 para jugar(0 para salir)"<< endl;
         cin >> seguir_jugando;
    }
    return seguir_jugando;
}

void jugar()
{
    int numero_jugadores = obtener_numero_jugadores();

    while(seguir_jugando())
    {
        tBaraja baraja;

        inicializar(baraja);

        tJuego juego;
        juego.numero = 0;
        for (int i = 0; i < numero_jugadores; i++)
            anadirMano(juego,baraja);

        encontrarManoGanadora(juego);
        eliminar_manos_juego(juego);
    }
}

void eliminar_manos_juego(tJuego &juego)
{
    for(int i = 0; i < juego.numero; i++)
        delete juego.mano[i];

    juego.numero= 0;
}
