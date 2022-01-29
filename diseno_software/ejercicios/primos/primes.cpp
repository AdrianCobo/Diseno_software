#include <math.h>
#include "searches.h"


int store_primes(int array_primes[], const int first, const int last)
{
    int num_primes = 0;

    for(int i = 0; i <= last; i++)
    {
        if( is_prime(i) )
        {
            array_primes[num_primes++] = i;
        }
    }

    return num_primes;
}

bool is_prime(int number)
{
    bool prime = true;
    int divisor = 3;

    if( (number % 2 == 0) && number != 2)
        prime = false;

    while(prime && (divisor <= sqrt(number)))
    {
        if(number % divisor == 0)
            prime = false;
        divisor += 2;
    }
    return prime;

}

int number_of_primes(const int first, const int last)
{
    int num_primes = 0;

    for(int i = 0; i <= last; i++)
    {
        if( is_prime(i) )
        {
            num_primes++;
        }
    }

    return num_primes;
}
