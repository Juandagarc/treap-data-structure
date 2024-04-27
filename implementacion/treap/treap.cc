// Treap.cc
#include "Treap.hh"
#include <iostream>
#include <ctime>

using std::swap;

// Implementación de la estructura Nodo.
Nodo::Nodo(int _llave) : llave(_llave), prioridad(rand()), izquierdo(nullptr), derecho(nullptr) {}

// Implementación del constructor y destructor de Treap.
Treap::Treap() : raiz(nullptr) {
    srand(static_cast<unsigned>(time(nullptr))); // Inicializa la semilla para la prioridad aleatoria.
}

// Función auxiliar para eliminar subárbol.
void eliminarSubarbol(Nodo* t) {
    if (t) {
        eliminarSubarbol(t->izquierdo);
        eliminarSubarbol(t->derecho);
        delete t;
    }
}

Treap::~Treap() {
    eliminarSubarbol(raiz); // Elimina todos los nodos y limpia la memoria.
}

// Implementaciones de las funciones privadas de rotación.
Nodo* Treap::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    y->izquierdo = x->derecho;
    x->derecho = y;
    return x;
}

Nodo* Treap::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    x->derecho = y->izquierdo;
    y->izquierdo = x;
    return y;
}

// Implementación de la función de inserción.
Nodo* Treap::insertar(Nodo* t, int llave) {
    if (!t) return new Nodo(llave);

    if (llave < t->llave) {
        t->izquierdo = insertar(t->izquierdo, llave);
        if (t->izquierdo && t->izquierdo->prioridad > t->prioridad)
            t = rotarDerecha(t);
    } else if (llave > t->llave) {
        t->derecho = insertar(t->derecho, llave);
        if (t->derecho && t->derecho->prioridad > t->prioridad)
            t = rotarIzquierda(t);
    }
    // Si llave es igual, no se inserta porque ya existe.
    return t;
}

// Implementación de la función auxiliar inorder.
void Treap::inorder(Nodo* t) {
    if (!t) return;
    inorder(t->izquierdo);
    std::cout << t->llave << "(" << t->prioridad << ") ";
    inorder(t->derecho);
}

// Implementaciones de las funciones públicas.
void Treap::insertar(int llave) {
    raiz = insertar(raiz, llave);
}

void Treap::imprimir() {
    inorder(raiz);
    std::cout << std::endl;
}

//prueba
int main() {
    Treap treap;
    treap.insertar(20);
    treap.insertar(30);
    treap.insertar(25);
    treap.insertar(5);
    treap.insertar(10);

    std::cout << "El recorrido inorder del Treap es:" << std::endl;
    treap.imprimir();

    return 0;
}
