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

// Implementación de la función auxiliar para eliminar un nodo con la llave dada.
Nodo* Treap::eliminar(Nodo* t, int llave) {
    if (!t) return t;

    // Si la llave a eliminar es menor que la llave del nodo actual, buscar en el subárbol izquierdo.
    if (llave < t->llave)
        t->izquierdo = eliminar(t->izquierdo, llave);
    // Si la llave a eliminar es mayor que la llave del nodo actual, buscar en el subárbol derecho.
    else if (llave > t->llave)
        t->derecho = eliminar(t->derecho, llave);
    // Si la llave a eliminar es igual a la llave del nodo actual.
    else {
        // Si el nodo tiene solo un hijo o ninguno.
        if (!t->izquierdo) {
            Nodo* temp = t->derecho;
            delete t;
            return temp;
        } else if (!t->derecho) {
            Nodo* temp = t->izquierdo;
            delete t;
            return temp;
        }
        // Si el nodo tiene dos hijos, encontrar el sucesor inorden (nodo más pequeño en el subárbol derecho).
        Nodo* temp = minimo(t->derecho);
        // Copiar los datos del sucesor inorden al nodo actual.
        t->llave = temp->llave;
        // Eliminar el sucesor inorden.
        t->derecho = eliminar(t->derecho, temp->llave);
    }
    return t;
}

// Implementación de la función auxiliar para encontrar el nodo con el valor mínimo en el subárbol.
Nodo* Treap::minimo(Nodo* t) {
    Nodo* current = t;
    // Recorrer el árbol hacia la izquierda para encontrar el nodo con el valor mínimo.
    while (current && current->izquierdo != nullptr)
        current = current->izquierdo;
    return current;
}

// Implementación de la función auxiliar para encontrar el nodo con la llave dada.
Nodo* Treap::encontrar(Nodo* t, int llave) {
    if (!t) return nullptr;
    if (llave < t->llave)
        return encontrar(t->izquierdo, llave);
    else if (llave > t->llave)
        return encontrar(t->derecho, llave);
    else
        return t;
}

// Implementaciones de las funciones públicas.
void Treap::insertar(int llave) {
    raiz = insertar(raiz, llave);
}

void Treap::eliminar(int llave) {
    raiz = eliminar(raiz, llave);
}

bool Treap::encontrar(int llave) {
    return encontrar(raiz, llave) != nullptr;
}

void Treap::imprimir() {
    inorder(raiz);
    std::cout << std::endl;
}
