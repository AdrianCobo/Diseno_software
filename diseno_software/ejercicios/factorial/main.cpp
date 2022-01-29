#include <iostream>

using namespace std;

int main()
{
    const int valor_multiplicador_del_factorial = 4;
    unsigned long long factorial_acumulado = 1;
    unsigned long long resultado_multiplicado;

    for(int i = 1; i <= 20; i++)
    {
        factorial_acumulado = factorial_acumulado*i;
        resultado_multiplicado = factorial_acumulado*valor_multiplicador_del_factorial;
    }

    return 0;
}
