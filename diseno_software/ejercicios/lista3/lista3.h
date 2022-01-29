#ifndef LISTA3_H_INCLUDED
#define LISTA3_H_INCLUDED


//////////////   CONSTANTES    ///////////////////////////////////
const int TAMANO = 1000;
const int LONG_NOMBRE = 100;

//////////////   ESTRUCTURAS   ///////////////////////////////////
typedef struct
{
    int codigo;
    char nombre[LONG_NOMBRE];
    double valor;
} tRegistro;

typedef struct
{
    // Array de punteros a registros:
    tRegistro* registros[TAMANO];
    int contador;
} tLista;


// tanto lista como registro deben alojarse en memoria dinamica

//////////////   FUNCIONES   ///////////////////////////////////

// resetea el contador de elementos y reserva memoria
void inicializar(tLista* lista);

// muestra todos los elementos de la lista
void mostrar(const tLista* lista);

// intenta insertar un elemento al final de la lista
// devuelve true si el elemento ha sido insertado, false si no
bool insertar(tLista* lista, tRegistro* registro);

// busca un elemento en la lista, por código
// devuelve la posicion del elemento, -1 si no lo encuentra
int buscar(const tLista* lista, int codigo);

// intenta eliminar un elemento de la lista, por codigo
// devuelve true si el elemento ha sido eliminado, false si no
bool eliminar(tLista* lista, int codigo);

// libera la memoria dinamica usada en la lista
void destruir(const tLista* lista);

#endif // LISTA3_H_INCLUDED
