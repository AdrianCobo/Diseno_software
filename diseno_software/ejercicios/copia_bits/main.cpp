#include <iostream>

/*
& si los dos bits de la misma posicion son 1, devuelve 1 sino, un 0
| si al menos 1 bit de esa posicion es 1, devuelve un uno, sino un 0
xor si 1 tiene un 1 y el otro un 0 o viceversa, devuelve un uno, si los dos son iguales, devuelve un 0
*/

using namespace std;

int main()
{
    unsigned short input1,input2,output,aux1,aux2,result,mask1,mask2;
    input1 = 0x5555;
    input2 = 0xAAAA;
    aux1 = 0;
    aux2 = 0;
    result = 0;

    mask2 = (1<<4) | (1<<5) | (1<<6) | (1<<7);//0x00F0// se ponen a uno los bits 4,5,6 y 7 de la mascara
    aux2 = input2 & mask2;//ponemos todos los bits a cero del input 2 excepto los de la posicion 4,5,6,7
    aux2 = aux2 << 4;//movemos 4 bits a la izquieda

    mask1 = (1<<8) | (1<<9) | (1<<10) | (1<<11);//se ponen a 1 los bits 8,9,10,11 de la mascara
    aux1 = input1 & ~mask1;//ponemos a cero los bits 8,9,10 y 11

    result = aux1|aux2;//juntamos los dos auxiliares
    return 0;
}
