#include <iostream>

using namespace std;

int main()
{
    const int limite_inferior = 1900;
    const int limite_superior = 2021;
    bool es_bisiesto;

    for(int anyo = limite_inferior; anyo < limite_superior;anyo++)
    {
        es_bisiesto=((anyo % 4 == 0) && (anyo % 100 != 0)) || (anyo % 400 == 0);
        if(es_bisiesto)
        cout << anyo << ' ';
    }
    return 0;
}
