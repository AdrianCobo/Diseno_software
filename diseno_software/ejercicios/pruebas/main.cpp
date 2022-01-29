#include <iostream>
using namespace std;
int main(void) {
    int i = 5, j = 13;
    int* punt = &i;
    cout << *punt << endl;
        punt = &j;
    cout << *punt << endl;
    int* otro = &i;
    cout << *otro + *punt << endl;
    j += i;
    int k = *punt;
    cout << k << endl;
    return 0;
}
