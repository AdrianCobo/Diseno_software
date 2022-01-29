#ifndef INTERMEDIATE_FUNCTIONS_H_INCLUDED
#define INTERMEDIATE_FUNCTIONS_H_INCLUDED

int obtener_dificultad(void);//obtiene la dificultad deseada por el jugador
int obtener_num_elem(int dificultad_seleccionada);//da el numero de digitos del numero secreto con el que se va a jugar
int obtener_num_intentos(int dificultad_seleccionada);//da el numero de intentos de la partida
bool obtener_repeticiones(void);//indica si se desean digitos repetidos o no

void copiar_array(unsigned int array_copiada[], const unsigned int array_original[],const int num_elem);

//este metodo cambia los digitos que cuentan como acierto de las copias del los arrays intento y numero secreto para
//que no se cuenten como semiaciertos
void quitar_aciertos(unsigned int intento_manipulable[],unsigned int num_secreto_manipulable[],const int num_elem);

//generar_numero_aleatorio sirve para en funcion de la dificultad seleccionada pasar los parametros correspondientes al
//metodo rellenarArrayAleatoriamente como corresponda
void generar_numero_aleatorio(int dificultad_seleccionada,unsigned int secret_array[],bool expected_repeated_numbers,const int num_elem);
void rellenarArrayAleatoriamente(const int num_elem, const int num_mas_alto,unsigned int secret_array[]);
bool jugar(const int dificultad_seleccionada,const unsigned int numSecreto[],const int num_elem,int num_intentos);
void pantalla_final(bool victoria);
#endif // INTERMEDIATE_FUNCTIONS_H_INCLUDED
