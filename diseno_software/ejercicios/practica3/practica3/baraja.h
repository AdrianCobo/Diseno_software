#ifndef BARAJA_H_INCLUDED
#define BARAJA_H_INCLUDED

#include "poker_structs.h"

// resetea el contador de elementos y reserva memoria
void inicializar(tBaraja &baraja);

// muestra todos los elementos de la lista
void mostrar(const tBaraja &baraja);

// busca un elemento en la lista, por código
// devuelve la posicion del elemento, -1 si no lo encuentra
int buscar(const tBaraja &baraja, int valor, int palo);

// intenta insertar un elemento al final de la lista
// devuelve true si el elemento ha sido insertado, false si no
bool insertar(tBaraja &baraja, tCarta &carta);

// intenta eliminar un elemento de la lista, por codigo
// devuelve true si el elemento ha sido eliminado, false si no
bool eliminar(tBaraja &baraja, int valor, int palo);

// libera la memoria dinamica usada en la lista
void destruir(tBaraja &baraja);

#endif // BARAJA_H_INCLUDED
