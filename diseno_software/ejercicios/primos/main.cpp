#include <iostream>
using namespace std;
#include "primes.h"
#include "searches.h"
#include "time.h"

int main()
{
    const int FIRST_VALUE = 2;
    const int LAST_VALUE = 10000000;
    const int ARRAY_SIZE = 664579;
    static int array_primes[ARRAY_SIZE];

    cout << store_primes(array_primes, FIRST_VALUE, LAST_VALUE) << endl;

    int init_value = 10000000;
    bool descending = true;
    bool binary = false;
    cout << linear_binary_search(array_primes,ARRAY_SIZE,init_value,descending,binary) << endl;
    clock_t time_linear = linear_binary_search_get_time(array_primes,ARRAY_SIZE,init_value,descending,binary);
    cout << time_linear << endl;
    binary = true;
    cout << linear_binary_search(array_primes,ARRAY_SIZE,init_value,descending,binary)<< endl;
    clock_t time_binary = linear_binary_search_get_time(array_primes,ARRAY_SIZE,init_value,descending,binary);
    cout << time_binary << endl;
    cout << "ratio: " << (float)time_linear/time_binary;

    init_value = 9876543;
    descending = false;
    binary = false;
    cout << linear_binary_search(array_primes,ARRAY_SIZE,init_value,descending,binary)<< endl;
    cout << linear_binary_search_get_time(array_primes,ARRAY_SIZE,init_value,descending,binary)<< endl;
    binary = true;
    cout << linear_binary_search(array_primes,ARRAY_SIZE,init_value,descending,binary)<< endl;
    cout << linear_binary_search_get_time(array_primes,ARRAY_SIZE,init_value,descending,binary)<< endl;
    return 0;
}
