#include <iostream>
#include "planta.h"
#include "identificador.h"
#include "bloque.h"
using namespace std;


Planta::Planta()
{
    bloques_libres = 0;
    filas = 0;
    columnas = 0;
}

Planta::Planta(const int num_filas, const int num_columnas): bloques_libres(0)
{
    filas = num_filas;
    columnas = num_columnas;
    bloques_libres=filas*columnas-bloques_libres;
}

int Planta::num_bloques_libres(void) const
{
    return bloques_libres;
}

bool Planta::estacionar_vehiculo( tVehiculo vehiculo )
{
    Identificador identificador;
    bool hueco_encontrado;
    bool estacionado = false;
    char valor[4];
    int valor_bloques = 4;
    int fila = 0;
    int columna = 0;
    if(vehiculo == MOTOCICLETA)
        valor_bloques =  1;
    else if(vehiculo == TURISMO)
        valor_bloques = 2;
    else if(vehiculo == FURGONETA)
        valor_bloques = 3;

    hueco_encontrado = obtener_hueco(valor_bloques,fila,columna);

    if(hueco_encontrado)
    {
        identificador.preparar_valor(vehiculo);
        identificador.generar_valor(valor);
        for(int i = 0; i < valor_bloques; i++)
            bloques[fila][columna+i].ocupar_bloque(valor);

        bloques_libres = bloques_libres-valor_bloques;
        estacionado = true;
    }
    return estacionado;
}

bool Planta::retirar_vehiculo( const char valor_id[] )
{
    bool vehiculo_retirado = false;
    int coincidencias_id = 0;
    const int TAMANO_ID_BLOQUE = 4;
    char cadena_a_comparar[TAMANO_ID_BLOQUE];
    int valor_bloques = TAMANO_ID_BLOQUE;
    if(valor_id[0] == 'M')
        valor_bloques =  1;
    else if(valor_id[0] == 'T')
        valor_bloques = 2;
    else if(valor_id[0] == 'F')
        valor_bloques = 3;

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            bloques[i][j].obtener_valor(cadena_a_comparar);
            for(int k = 0; k < TAMANO_ID_BLOQUE; k++)
                if(cadena_a_comparar[k] == valor_id[k])
                    coincidencias_id++;

            if(coincidencias_id == 4)
            {
                bloques[i][j].desocupar_bloque();
                vehiculo_retirado = true;
            }
            coincidencias_id = 0;
        }
    }
    if(vehiculo_retirado)
        bloques_libres = bloques_libres + valor_bloques;
    return vehiculo_retirado;
}

bool Planta::obtener_hueco(int num_bloques, int& fila, int& columna)
{
    bool encontrado_hueco = false;
    int filas = get_filas();
    int columnas = get_columnas();
    if(num_bloques <= num_bloques_libres())
    {
        for(int i = filas-1; 0 <= i; i--)
        {
            for(int j = 0; j < columnas; j++)
            {
                if(encontrado_hueco == false && bloques[i][j].esta_ocupado() == false && encontrado_hueco == false)
                {
                    if(columnas-j >= num_bloques)
                    {
                        fila = i;
                        columna = j;
                        encontrado_hueco = true;
                    }
                }
            }
        }
    }

    return encontrado_hueco;
}

void Planta::visualizar_estado( void ) const
{
    char valor[4];
    const int TAMANO_ID_BLOQUE = 4;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            bloques[i][j].obtener_valor(valor);
            for(int k = 0; k < TAMANO_ID_BLOQUE; k++)
                cout << valor[k];
            cout << " ";
        }
        cout << endl;
    }
}
