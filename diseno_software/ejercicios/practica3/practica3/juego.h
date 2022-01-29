#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

using namespace std;
#include <string>
#include "baraja.h"
#include "carta.h"
#include "mano.h"
#include "juego.h"

void anadirMano(tJuego &juego,tBaraja &baraja);// añade una mano al juego
void encontrarManoGanadora(tJuego &juego);// encuentra la mano (o las manos en caso de empate) con la puntuación máxima
void mostrarManoGanadora();// muestra la mano (o las manos en caso de empate) con la puntuación máxima
void calcular_puntos_manosenjuego(tJuego &juego,int array_puntuaje[]);
int revisar_empate(tJuego &juego,const int puntuacion_mayor,const int array_puntuaje[]);
int obtener_numero_jugadores();
bool seguir_jugando();
void jugar();
void imprimir_ganadores(tJuego juego,const int puntuacion_mayor,const int array_puntuaje[]);
void eliminar_manos_juego(tJuego &juego);
#endif // JUEGO_H_INCLUDED
