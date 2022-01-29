#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;
#include "tipos.h"
#include "posicion.h"
#include "coordenadas.h"
#include "habitacion.h"
#include "robot.h"
#include "pibot.h"
#include "tello.h"
#include "simulacion.h"

void simulacion_completa()
{
    int fila, columna,robot_numero;
    solicitar_datos(fila, columna,robot_numero);
    preparar_habitacio(fila,columna,robot_numero);
}

void solicitar_datos(int& ancho, int& largo, int& robot_numero)
{
    cout << "Introduce el ancho de la habitacion de 0 a 20 (o se autoasignará a 20): ";
    cin >> ancho;
    cout << "Introduce el largo de la habitacion de 0 a 60 (o se autoasignará a 60): ";
    cin >>largo;
    cout << "Introduce el 1 para un pibot o 2 para usar un tello en la simulacion(o se autoasignará un pibot): ";
    cin >>robot_numero;
    if(robot_numero < 1||robot_numero>2)
        robot_numero = 1;
}

void preparar_habitacio(int ancho, int largo, int robot)
{
    // Creamos habitacion de dimensiones ancho x largo
    Posicion esquina_inferior_derecha_habitacion(ancho, largo);
    Habitacion habitacion(esquina_inferior_derecha_habitacion);

    // Colocamos puerta
    Posicion posicion_puerta;
    habitacion.colocar_puerta_aleatoria(posicion_puerta);

    // Creamos robot con coordenadas iniciales
    Coordenadas coord_robot;
    habitacion.obtener_coordenadas_aleatorias_para_robot(coord_robot);
    if(robot == 1)
    {
        Pibot robot(coord_robot);
        // Colocamos robot en habitacion
        habitacion.colocar_pibot(coord_robot);
        simular_movimiento(robot,posicion_puerta,esquina_inferior_derecha_habitacion,coord_robot,habitacion);
    }
    else
    {
        Tello robot_tello(coord_robot);
        habitacion.colocar_tello(coord_robot,robot_tello.get_volando());
        simular_movimiento(robot_tello,posicion_puerta,esquina_inferior_derecha_habitacion,coord_robot,habitacion);
    }
}

void simular_movimiento(Pibot robot, Posicion& posicion_puerta, Posicion esquina_inferior_derecha_habitacion,
                                                    Coordenadas coord_robot, Habitacion habitacion)
{
    bool puerta_detectada = false;
    int lectura_us = 0;
    while (!puerta_detectada)
    {
        puerta_detectada = robot.detectar_objeto(posicion_puerta);
        if (!puerta_detectada)
        {
            lectura_us = robot.leer_ultrasonidos(esquina_inferior_derecha_habitacion);
             if (lectura_us > robot.obtener_distancia_avance() )
                robot.avanzar();
            else
                robot.girar_derecha();

            robot.get_coordenadas(coord_robot);
            habitacion.colocar_pibot(coord_robot);
            habitacion.dibujar();
        }
        usleep(1000000);
        system("clear");
    }
}

void simular_movimiento(Tello robot, Posicion& posicion_puerta, Posicion esquina_inferior_derecha_habitacion,
                                                    Coordenadas coord_robot, Habitacion habitacion)
{
    bool puerta_detectada = false;
    int lectura_us = 0;
    while (!puerta_detectada)
    {
        puerta_detectada = robot.detectar_objeto(posicion_puerta);
        if (!puerta_detectada)
        {
            lectura_us = robot.leer_ultrasonidos(esquina_inferior_derecha_habitacion);
             if (lectura_us > robot.obtener_distancia_avance() )
                robot.avanzar();
            else
                robot.girar_derecha();

            robot.get_coordenadas(coord_robot);
            habitacion.colocar_tello(coord_robot,robot.get_volando());
            habitacion.dibujar();
        }
        usleep(1000000);
        system("clear");
    }
}
