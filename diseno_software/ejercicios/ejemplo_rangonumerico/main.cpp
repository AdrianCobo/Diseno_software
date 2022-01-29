#include <iostream>

using namespace std;

int main()
{
    int number;
    do
    {
        cout << "Enter a number between 2 to 174 that is multiple of 3: ";
        cin >> number;
    } while(((number % 3 != 0) || (number < 2) || (number > 174 )));
    cout << "ok" << endl;
    return 0;
}
