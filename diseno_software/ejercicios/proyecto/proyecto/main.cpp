#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

#include "tipos.h"
#include "posicion.h"
#include "coordenadas.h"
#include "habitacion.h"
#include "robot.h"
#include "pibot.h"
#include "tello.h"
#include "simulacion.h"
using namespace std;

int main()
{
    srand(time(NULL));
    simulacion_completa();
    return 0;
}
