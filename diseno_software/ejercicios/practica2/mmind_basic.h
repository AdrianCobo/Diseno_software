#ifndef MMIND_BASIC_H_INCLUDED
#define MMIND_BASIC_H_INCLUDED


/* Función comprobarDigitosRepetidos():
Devuelve true si 'numero[]' contiene algún dígito repetido, False en caso contrario.
'numero[]' es un array de "num_elem" posiciones,
cada posición del array contiene un dígito del número secreto.
*/
bool comprobarDigitosRepetidos(const unsigned int numero[], const int num_elem);


/* Función rellenarIntento():
Rellena el array de "num_elem" posiciones 'intentoDigitos[]',
de forma que en cada posición del array almacena el dígito correspondiente del número 'intento'.
Por ejemplo, si num_elem=4 e intento=4512, la función debe rellenar el array de la siguiente forma:
intentoDigitos[0] = 4; intentoDigitos[1] = 5; intentoDigitos[2] = 1; intentoDigitos[3] = 2.
*/
void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem);


/* Función calcularAciertos():
Devuelve el número de dígitos acertados existente en el array de "num_elem" posiciones 'intentoDigitos[]'
con respecto al array de "num_elem"  posiciones 'numSecreto[]'.
Un dígito de 'intentoDigitos[]' se considera acertado si coincide el valor y la posición del mismo
con respecto a los de 'numSecreto[]'.
Por ejemplo, si num_elem=4, numSecreto[] = {1,2,3,4} e intentoDigitos[] = {5,0,3,4}, la función debe devolver el valor 2.
*/
unsigned int calcularAciertos(const unsigned int numSecreto[],
                              const unsigned int intentoDigitos[],
                              const int num_elem);


/* Función calcularSemiaciertos():
Devuelve el número de dígitos semi-acertados existente en el array de "num_elem" posiciones 'intentoDigitos[]'
con respecto al array de "num_elem" posiciones 'numSecreto[]'.
Un dígito de 'intentoDigitos[]' se considera semi-acertado si coincide el valor pero no la posición del mismo
con respecto a los de 'numSecreto[]'.
Por ejemplo, si num_elem=4, numSecreto[] = {1,2,3,4} e intentoDigitos[] = {3,1,0,4}, la función debe devolver el valor 2.
*/
unsigned int calcularSemiaciertos(const unsigned int numSecreto[],
                                  const unsigned int intentoDigitos[],
                                  const int num_elem);


#endif // MMIND_BASIC_H_INCLUDED
