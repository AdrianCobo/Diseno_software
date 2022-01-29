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

class Lista
{
    // Array de punteros a registros:
    tRegistro* registros[TAMANO];
    int contador;

public:

    // tanto lista como registro deben alojarse en memoria dinamica

//////////////   FUNCIONES   ///////////////////////////////////

// constructor que resetea el contador de elementos y reserva memoria
    Lista(): contador(0) {};

// destructor que libera la memoria dinamica usada en la lista
    ~Lista();

// muestra todos los elementos de la lista
    void mostrar();

// intenta insertar un elemento al final de la lista
// devuelve true si el elemento ha sido insertado, false si no
    bool insertar(tRegistro* registro);

// busca un elemento en la lista, por código
// devuelve la posicion del elemento, -1 si no lo encuentra
    int buscar(int codigo);

// intenta eliminar un elemento de la lista, por codigo
// devuelve true si el elemento ha sido eliminado, false si no
    bool eliminar(int codigo);
};

#endif // LISTA3_H_INCLUDED
