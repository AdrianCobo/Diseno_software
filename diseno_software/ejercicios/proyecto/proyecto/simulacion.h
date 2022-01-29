#ifndef SIMULACION_H_INCLUDED
#define SIMULACION_H_INCLUDED

#include "pibot.h"
#include "tello.h"
void simulacion_completa();
void solicitar_datos(int& ancho, int& largo, int& robot);
void preparar_habitacio(int ancho, int largo, int robot);

void simular_movimiento(Pibot robot, Posicion& posicion_puerta, Posicion esquina_inferior_derecha_habitacion,
                                                                Coordenadas coord_robot,Habitacion habitacion);

void simular_movimiento(Tello robot, Posicion& posicion_puerta, Posicion esquina_inferior_derecha_habitacion,
                                                                    Coordenadas coord_robot,Habitacion habitacion);


#endif // SIMULACION_H_INCLUDED
