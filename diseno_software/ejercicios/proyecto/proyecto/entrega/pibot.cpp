#include "pibot.h"

bool Pibot::detectar_objeto(Posicion& pos_objeto)
{
    bool objeto_detectado = false;
    if((coord.get_orientacion()== NORTE)&&(coord.get_x()==pos_objeto.get_x() && coord.get_y()==pos_objeto.get_y()+1))
        objeto_detectado = true;

    else if((coord.get_orientacion()== SUR)&&(coord.get_x()==pos_objeto.get_x() && coord.get_y()==pos_objeto.get_y()-1))
        objeto_detectado = true;

    else if((coord.get_orientacion()== ESTE)&&(coord.get_x()==pos_objeto.get_x()+1 && coord.get_y()==pos_objeto.get_y()))
        objeto_detectado = true;

    else if((coord.get_orientacion()== OESTE)&&(coord.get_x()==pos_objeto.get_x()-1 && coord.get_y()==pos_objeto.get_y()))
        objeto_detectado = true;

    return objeto_detectado;
}

int Pibot::leer_ultrasonidos(Posicion& pos_esquina)
{
    int distancia_pared = 0;

    if(coord.get_orientacion()== NORTE)
        distancia_pared=coord.get_x();

    else if(coord.get_orientacion()== SUR)
        distancia_pared=pos_esquina.get_x()-1 - coord.get_x();

    else if(coord.get_orientacion()== ESTE)
        distancia_pared=pos_esquina.get_y()-1 - coord.get_y();

    else
        distancia_pared=coord.get_y();

    return distancia_pared;
}

void Pibot::avanzar(void)
{
    if(coord.get_orientacion()== NORTE)
        coord.set_x(coord.get_x()-1);

    else if(coord.get_orientacion()== SUR)
        coord.set_x(coord.get_x()+1);

    else if(coord.get_orientacion()== ESTE)
        coord.set_y(coord.get_y()+1);

    else
        coord.set_y(coord.get_y()-1);
}
void Pibot::girar_derecha(void)
{
    if(coord.get_orientacion() == NORTE)
        coord.set_orientacion(ESTE);

    else if(coord.get_orientacion()== SUR)
        coord.set_orientacion(OESTE);

    else if(coord.get_orientacion()== ESTE)
        coord.set_orientacion(SUR);

    else
        coord.set_orientacion(NORTE);
}
