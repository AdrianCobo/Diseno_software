#ifndef PIBOT_H_INCLUDED
#define PIBOT_H_INCLUDED

#include "robot.h"

class Pibot: public Robot
{

public:
    Pibot(const Coordenadas coord_robot): Robot(coord_robot) {};
    bool detectar_objeto(Posicion& pos_objeto);
    int leer_ultrasonidos(Posicion& pos_esquina);
    void avanzar(void);
    void girar_derecha(void);
    int obtener_distancia_avance(void) const{return 1;};
};

#endif // PIBOT_H_INCLUDED
