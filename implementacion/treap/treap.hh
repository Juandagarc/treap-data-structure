// Treap.hh
#ifndef TREAP_HH
#define TREAP_HH

#include <cstdlib>

struct Nodo {
    int llave;
    int prioridad;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int _llave); // Constructor que inicializa un nodo.
};

class Treap {
private:
    Nodo* raiz;

    // Funciones privadas para rotar los nodos y mantener las propiedades del Treap.
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);

    // Funciones privadas recursivas para insertar, eliminar y encontrar un nodo.
    Nodo* insertar(Nodo* t, int llave);
    Nodo* eliminar(Nodo* t, int llave);
    Nodo* encontrar(Nodo* t, int llave);

    // Función auxiliar para realizar el recorrido inorder.
    void inorder(Nodo* t);

    // Función auxiliar para encontrar el nodo con el valor mínimo en el subárbol.
    Nodo* minimo(Nodo* t);

public:
    Treap(); // Constructor que inicializa el Treap.
    ~Treap(); // Destructor para limpiar la memoria.

    void insertar(int llave); // Inserta un nuevo llave en el Treap.
    void eliminar(int llave); // Elimina un llave del Treap.
    bool encontrar(int llave); // Busca un llave en el Treap.
    void imprimir(); // Imprime el Treap en orden.
};

#endif // TREAP_HH
