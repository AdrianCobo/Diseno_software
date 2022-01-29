
int main()
{

    const int LIMITE = 20;
    int factorial, resultado;

    for (int i = 0; i <= LIMITE; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }
        resultado = factorial << 2;//desplazamos 2 bits a la derecha para multiplicar por 4
    }

    return 0;

}
