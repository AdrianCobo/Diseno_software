#include <iostream>
#include "planta.h"
#include "identificador.h"
#include "bloque.h"
#include "parking.h"
using namespace std;


Parking::Parking(const Planta nuevas_plantas[], int numero_plantas)
{
    for(int i = 0; i < MAX_PLANTAS; i++)
    {
        plantas[i] = nuevas_plantas[i];
    }
    num_plantas = numero_plantas;
}

int Parking::num_bloques_libres(void) const
{
    int bloques_libres_totales = 0 ;
    for (int i = 0; i < num_plantas; i++)
        bloques_libres_totales = plantas[i].num_bloques_libres()+bloques_libres_totales;
    return bloques_libres_totales;
}

bool Parking::estacionar_vehiculo( tVehiculo vehiculo )
{
    int planta_mas_espaciosa = 0;

    for(int i = 1; i < num_plantas; i++)
    {
        if(plantas[i-1].num_bloques_libres() < plantas[i].num_bloques_libres())
            planta_mas_espaciosa = i;
    }
    bool aparcado = plantas[planta_mas_espaciosa].estacionar_vehiculo(vehiculo);
    return aparcado;
}

bool Parking::retirar_vehiculo( const char valor_id[] )
{
    bool vehiculo_retirado = false;

    for (int i = 0; i < num_plantas; i++)
    {
        if(plantas[i].retirar_vehiculo(valor_id))
            vehiculo_retirado = true;
    }

    return vehiculo_retirado;
}

void Parking::visualizar_estado( void )const
{
    for(int i = 0; i < num_plantas; i++)
    {
        cout << "Planta " << i << endl;
        plantas[i].visualizar_estado();
        cout << endl;
    }
}
