#ifndef POKER_STRUCTS_H_INCLUDED
#define POKER_STRUCTS_H_INCLUDED


const int PALOS = 4;
const int VALORES = 13;
const int CARTASBARAJA = PALOS * VALORES;
const int CARTASMANO = 5;
const int MAXJUGADORES = 4;

typedef struct
{
	int	palo;  // 1..PALOS
	int	valor; // 1..VALORES
} tCarta;

typedef struct
{
	tCarta carta[CARTASBARAJA];
	int numero;  //  0..CARTASBARAJA
} tBaraja;

typedef struct
{
	tCarta carta[CARTASMANO];
	int numero; // 0..CARTASMANO
	int puntos; // 1..10
} tMano;

typedef struct
{
	tMano* mano[MAXJUGADORES]; // array de punteros
	int numero; // 2..MAXJUGADORES
} tJuego;



#endif // POKER_STRUCTS_H_INCLUDED
