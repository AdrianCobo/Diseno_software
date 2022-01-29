#include "tello.h"

bool Tello::detectar_objeto(Posicion& pos_objeto)//para que este método tuviese menos de 20 líneas podría haber juntado
{                                                //los ifs como en la clase pibot.cpp, pero no lo he hecho por que creo
    bool objeto_detectado = false;               //que perjudicaría la legibilidad del código.
    if(coord.get_orientacion()== NORTE)
    {
        if(coord.get_x()==pos_objeto.get_x() && (coord.get_y()==pos_objeto.get_y()+2||coord.get_y()==pos_objeto.get_y()+1))
            objeto_detectado = true;
    }
    else if(coord.get_orientacion()== SUR)
    {
        if(coord.get_x()==pos_objeto.get_x() && (coord.get_y()==pos_objeto.get_y()-2||coord.get_y()==pos_objeto.get_y()-1))
            objeto_detectado = true;
    }
    else if(coord.get_orientacion()== ESTE)
    {
        if((coord.get_x()==pos_objeto.get_x()+2 ||coord.get_x()==pos_objeto.get_x()+1)&& coord.get_y()==pos_objeto.get_y())
            objeto_detectado = true;
    }
    else
    {
        if((coord.get_x()==pos_objeto.get_x()-2||coord.get_x()==pos_objeto.get_x()-1) && coord.get_y()==pos_objeto.get_y())
            objeto_detectado = true;
    }
    return objeto_detectado;
}

int Tello::leer_ultrasonidos(Posicion& pos_esquina)
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

void Tello::avanzar(void)
{
    volando = true;

    if(coord.get_orientacion()== NORTE)
        coord.set_x(coord.get_x()-distancia_avance);

    else if(coord.get_orientacion()== SUR)
        coord.set_x(coord.get_x()+distancia_avance);

    else if(coord.get_orientacion()== ESTE)
        coord.set_y(coord.get_y()+distancia_avance);

    else
        coord.set_y(coord.get_y()-distancia_avance);

    bateria_optima--;
    if(bateria_optima < 0)
        distancia_avance = 1;
}

void Tello::girar_derecha(void)
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
