#ifndef MANO_H_INCLUDED
#define MANO_H_INCLUDED
using namespace std;
#include <string>
#include "baraja.h"
#include "poker_structs.h"


void repartirMano(tMano *mano, tBaraja &baraja); //sacar las cartas necesarias de la baraja para rellenar una mano
void ordenarMano(tMano *mano); //ordenar la mano de menor a mayor por valores de las cartas
int calcularPuntosMano(tMano *mano); //calcula la puntuación de la mano según el enunciado (de 1 a 10
                      //puntos). Aquí se puede llamar a funciones auxiliares (comprobarPoker(),
                      //comprobarTrio(), comprobarEscalera(), etc.)
int obtener_puntos(const int mayor_mayor,const int menor_mayor,const bool mismo_color,const bool escalera);
void mostrarMano(tMano *mano); //mostrar todas las cartas de la mano, incluyendo puntuación
tCarta sacar_carta_baraja(tBaraja &baraja);
string obtener_nombre_puntuaje(tMano *mano);
bool revisar_color(tMano *mano);
bool revisar_escalera(int array_comprobador[]);//revisa si los valores de 5 posiciones consecutivas del array
//son iguales o si el primer valor del array y los 4 ultimos son iguales

#endif // MANO_H_INCLUDED
