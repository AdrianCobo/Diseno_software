#include <iostream>


int main()
{

    const int LIMITE = 20;
    unsigned long long factorial, resultado;
    factorial = 1;

    for (int i = 1; i <= LIMITE; i++)
    {

        factorial = factorial*i;
        resultado = factorial*4;
    }

    return 0;

}
