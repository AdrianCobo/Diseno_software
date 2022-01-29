#include <iostream>
#include <ctime>
#include <cstdlib>

#include "habitacion.h"
#include "tipos.h"
#include "posicion.h"
#include "coordenadas.h"
using namespace std;


Habitacion::Habitacion(Posicion& esquina_inf_dcha)
{
    if(esquina_inf_dcha.get_x() > 20)
    {
        esquina_inf_dcha.set_x(20);
        cout << "valor maximo para las filas = 20"<<endl;
    }
    if(esquina_inf_dcha.get_y() > 60)
    {
        esquina_inf_dcha.set_y(60);
        cout << "valor maximo para las filas = 60"<<endl;
    }
    esquina_infd=esquina_inf_dcha;
    for(int i = 0; i < esquina_infd.get_x(); i++)
    {
        for(int j = 0 ; j < esquina_infd.get_y(); j++)
        {
            if(i == 0 || i == esquina_infd.get_x() - 1 || j == 0 || j == esquina_infd.get_y() - 1)
                matriz[i][j] = '*';
            else
                matriz[i][j] = ' ';
        }
    }
}


void Habitacion::colocar_puerta_aleatoria(Posicion& pos)
{
    //seleccionamos la pared de forma aleatoria y luego en que parte de la pared tambien
    int pared = random() % (4);
    int fila = 0;
    int columna = 0;
    obtener_localizacion_pared(pared,fila,columna);
    pos.set_x(fila);
    pos.set_y(columna);
    matriz[fila][columna] = 'P';
}

void Habitacion::obtener_localizacion_pared(int pared,int& fila, int& columna)
{
    if (pared == 0)
    {
        fila = 0;
        columna = 1 + random() % (esquina_infd.get_y()-2);
    }
    else if (pared == 1)
    {
        fila = 1 + random() % (esquina_infd.get_x()-2);
        columna = esquina_infd.get_y() - 1;
    }
    else if (pared == 2)
    {
        fila = esquina_infd.get_x()-1;
        columna = 1 + random() % (esquina_infd.get_y()-2);
    }
    else
    {
        fila = random() % (esquina_infd.get_x()-1);
        columna = 0;
    }
}

void Habitacion::obtener_coordenadas_aleatorias_para_robot(Coordenadas& coord) const
{
    int orientacion_valor = 0 + random() % (4);

    if(orientacion_valor == 0)
        coord.set_orientacion(NORTE);
    else if(orientacion_valor == 1)
        coord.set_orientacion(SUR);
    else if(orientacion_valor == 0)
        coord.set_orientacion(ESTE);
    else
        coord.set_orientacion(OESTE);
    int fila = 1 + random() % (esquina_infd.get_x()-2);
    int columna = 1 + random() % (esquina_infd.get_y()-2);
    coord.set_x(fila);
    coord.set_y(columna);
}

void Habitacion::colocar_pibot(Coordenadas& coord)
{
    if(coord.get_orientacion() == 0)
        matriz[coord.get_x()][coord.get_y()]='^';
    else if(coord.get_orientacion() == 1)
        matriz[coord.get_x()][coord.get_y()]='v';
    else if(coord.get_orientacion() == 2)
        matriz[coord.get_x()][coord.get_y()]='>';
    else
        matriz[coord.get_x()][coord.get_y()]='<';
}

void Habitacion::colocar_tello(Coordenadas& coord, bool volando)
{
    if(volando)
         matriz[coord.get_x()][coord.get_y()]='X';
    else
         matriz[coord.get_x()][coord.get_y()]='x';
}

void Habitacion::dibujar(void) const
{
    for(int i = 0; i < esquina_infd.get_x(); i++)
    {
        for(int j = 0 ; j < esquina_infd.get_y(); j++)
        {
            cout << matriz[i][j];
        }
        cout<<endl;
    }
}
