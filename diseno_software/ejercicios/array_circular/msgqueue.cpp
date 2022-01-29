#include <iostream>
#include "msgqueue.h"
using namespace std;


Msgqueue::Msgqueue(int max_elements): insert_index(0), extract_index(0)//asi se suelen inicializar los atributos
{
    if(max_elements + 1 >  QUEUE_BUFFER_SIZE)
        max_num_elements = QUEUE_BUFFER_SIZE;
    else
        max_num_elements = max_elements + 1;
}

bool Msgqueue::is_queue_empty( void ) const
{
    return insert_index == extract_index;
}

bool Msgqueue::is_queue_full( void ) const
{
    return ((insert_index + 1) % max_num_elements) == extract_index;
}

bool Msgqueue::insert_element( const char new_element[], const int bytes )
{

    bool inserted = false;

    if(!is_queue_full())
    {
        buffer[insert_index].data = new char[bytes];
        buffer[insert_index].num_bytes = bytes;
        for(int i = 0; i < bytes; i++)
            buffer[insert_index].data[i] = new_element[i];

        insert_index++;
        //otra forma de hacer el if de abajo: insert_index %= max_num_elements;
        if(insert_index == max_num_elements)
            insert_index = 0;

        inserted = true;
    }

    return inserted;
}

int  Msgqueue::extract_element( char element[] )
{
    int extracted_size = 0;

    if(!is_queue_empty())
    {
        extracted_size = buffer[extract_index].num_bytes;
        for(int i = 0; i < extracted_size; i++)
            element[i] = buffer[extract_index].data[i];

        delete [] buffer[extract_index].data;//como es un array hay que indicarselo al delete

        extract_index++;
        //otra forma de hacer el if de abajo: insert_index %= max_num_elements;
        if(extract_index == max_num_elements)
            extract_index = 0;
    }

    return extracted_size;
}

int  Msgqueue::get_number_of_elements( void ) const
{
    int num_elements = insert_index - extract_index;

    if (insert_index < extract_index)
        num_elements += max_num_elements;

    return num_elements;
}

Msgqueue::~Msgqueue( void )//destructor
{
    int  elements = get_number_of_elements();

    for(int i = 0; i < elements ; i++)
    {
        delete [] buffer[extract_index].data;
        extract_index++;

         if(extract_index == max_num_elements)
            extract_index = 0;
    }
}
