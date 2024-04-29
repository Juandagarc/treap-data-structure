#include "./treap/treap.hh"
#include <iostream>
#include <chrono> // Para medir el tiempo

// Definición de códigos de colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"

int main() {
    // Medir el tiempo total
    auto startTotal = std::chrono::steady_clock::now();

    Treap treap1;
    treap1.insertar(20);
    treap1.insertar(30);
    treap1.insertar(25);
    treap1.insertar(5);
    treap1.insertar(10);

    std::cout << GREEN << "El recorrido inorder del Treap es:" << RESET << std::endl;
    treap1.imprimir();

    // Medir el tiempo de búsqueda
    auto startSearch = std::chrono::steady_clock::now();
    int llaveBuscar = 25;
    bool encontrado = treap1.encontrar(llaveBuscar);
    auto endSearch = std::chrono::steady_clock::now();
    std::cout << RED << "Tiempo de busqueda: " << std::chrono::duration_cast<std::chrono::duration<double>>(endSearch - startSearch).count() << " s" << RESET << std::endl;

    if (encontrado) {
        std::cout << GREEN << "La llave " << llaveBuscar << " esta presente en el Treap." << RESET << std::endl;
    } else {
        std::cout << RED << "La llave " << llaveBuscar << " no esta presente en el Treap." << RESET << std::endl;
    }

    // Medir el tiempo de eliminación
    auto startDelete = std::chrono::steady_clock::now();
    int llaveEliminar = 30;
    treap1.eliminar(llaveEliminar);
    auto endDelete = std::chrono::steady_clock::now();
    std::cout << GREEN << "El recorrido inorder del Treap despues de eliminar " << llaveEliminar << " es:" << RESET << std::endl;
    treap1.imprimir();
    std::cout << RED << "Tiempo de eliminacion: " << std::chrono::duration_cast<std::chrono::duration<double>>(endDelete - startDelete).count() << " s" << RESET << std::endl;

    std::cout << MAGENTA << "--------------------------------------------" << RESET << std::endl;

    // Crear otro Treap con números ordenados
    Treap treap2;
    auto startInsertOrdered = std::chrono::steady_clock::now();
    for (int i = 1; i <= 10; ++i) {
        treap2.insertar(i * 10);
    }
    auto endInsertOrdered = std::chrono::steady_clock::now();
    std::cout << RED << "Tiempo de insercion de numeros ordenados: " << std::chrono::duration_cast<std::chrono::duration<double>>(endInsertOrdered - startInsertOrdered).count() << " s" << RESET << std::endl;

    std::cout << GREEN << "El recorrido inorder del segundo Treap es:" << RESET << std::endl;
    treap2.imprimir();

    auto endTotal = std::chrono::steady_clock::now();
    std::cout << MAGENTA << "--------------------------------------------" << RESET << std::endl;
    std::cout << RED << "Tiempo total: " << std::chrono::duration_cast<std::chrono::duration<double>>(endTotal - startTotal).count() << " s" << RESET << std::endl;

    return 0;
}
