#include <iostream>

using namespace std;

int main()
{
    const int filas = 5;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < filas;j++)
        {
            if(j < i)
                cout << " ";
            else
                cout << "*";
        }

        cout << endl;
    }

    return 0;
}
