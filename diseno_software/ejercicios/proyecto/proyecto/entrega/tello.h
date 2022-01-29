#ifndef TELLO_H_INCLUDED
#define TELLO_H_INCLUDED

#include "robot.h"

class Tello: public Robot
{
public:
    Tello(const Coordenadas coord_robot): Robot(coord_robot) {volando = false; distancia_avance = 2;bateria_optima = 25;};
    bool detectar_objeto(Posicion& pos_objeto);
    int leer_ultrasonidos(Posicion& pos_esquina);
    void avanzar(void);
    void girar_derecha(void);
    int obtener_distancia_avance(void) const{return distancia_avance;};
    bool get_volando(void) const{return volando;};
protected:
    bool volando;
    int bateria_optima;
};

#endif // TELLO_H_INCLUDED
