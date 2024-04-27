// Treap.hh
#ifndef TREAP_HH
#define TREAP_HH

#include <cstdlib>

// Definición de la estructura Nodo, que representa cada nodo en el Treap.
struct Nodo {
    int llave;
    int prioridad;
    Nodo *izquierdo, *derecho;

    Nodo(int _llave); // Constructor que inicializa un nodo.
};

// Definición de la clase Treap.
class Treap {
private:
    Nodo* raiz; // Raíz del Treap.

    // Funciones privadas para rotar los nodos y mantener las propiedades del Treap.
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);

    // Función recursiva para insertar un nuevo llave en el subárbol con raíz en t.
    Nodo* insertar(Nodo* t, int llave);

    // Función auxiliar para realizar el recorrido inorder.
    void inorder(Nodo* t);

public:
    Treap(); // Constructor que inicializa el Treap.
    ~Treap(); // Destructor para limpiar la memoria.

    void insertar(int llave); // Inserta un nuevo llave en el Treap.
    void imprimir(); // Imprime el Treap en orden.
};

#endif // TREAP_HH
