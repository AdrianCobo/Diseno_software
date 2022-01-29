#include "searches.h"

int is_found_linear (const int an_array[], const int size, const int target)
{
    int position_found = -1;
    int i = 0;
    while( (i < size) && (position_found == -1) )
    {
        if (target == an_array[i])
            position_found = i;
        i++;
    }
    return position_found;
}

int is_found_binary (const int an_array[], const int size, const int target)
{
    int position_found = -1, low = 0, high = size - 1, mid;
    while( (low <= high) && (position_found == -1) )
    {
        mid = (low + high) / 2;
        if (target < an_array[mid])
            high = mid - 1;
        else if (target > an_array[mid])
            low = mid + 1;
        else
            position_found = mid;
    }
    return position_found;
}

int linear_binary_search(const int array_primes[],const int size,const int init_value,
                    const bool descending,const bool binary)
{
    int position = -1;
    int current_value = init_value;

    while(position == -1)
    {
        if (binary)
            position = is_found_binary(array_primes, size, current_value);
        else
            position = is_found_linear(array_primes,size,current_value);

        if (position == -1)
        {
            if (descending)
                current_value--;
            else
                current_value++;
        }

    }
    return current_value;
}

clock_t linear_binary_search_get_time(const int array_primes[], const int size,
                        const int init_value, const bool descending,bool binary)

{
    const int NUMBER_OF_EXECUTIONS = 100;
    clock_t time_start, time_end;
    time_start = clock();

    for(int i = 0; i < NUMBER_OF_EXECUTIONS;i++)
        linear_binary_search(array_primes,size,init_value,descending,binary);
    time_end = clock();


    return time_end- time_start;
}




















