#include <iostream>
#include <ctime>
#include <cstdlib>

#include "baraja.h"
#include "carta.h"
#include "mano.h"
#include "juego.h"

using namespace std;

int main()
{

    srand(time(NULL));
    jugar();
    return 0;
}
