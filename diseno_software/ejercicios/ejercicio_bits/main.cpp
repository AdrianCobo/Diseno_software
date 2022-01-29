#include <iostream>

using namespace std;

int main()
{
    unsigned short a,b,c,d;
    a = 0x5555;
    b = 0xAAAA;
    c = 0x00FF;

    d = (a << 8) | (((~b) ^ c) << 4);

    cout << hex;
    cout << d << endl;
    return 0;
}
