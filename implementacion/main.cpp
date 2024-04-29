#include "./treap/treap.hh"
#include <iostream>
#include <chrono> // Para medir el tiempo
#include <vector>
#include <cmath> // Para la función sqrt

// Definición de códigos de colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"

int main() {
    // Medir el tiempo total
    auto startTotal = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point endTotal;

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
    std::vector<double> tiemposInsercion; // Contenedor para almacenar tiempos de inserción

    auto startInsertOrdered = std::chrono::steady_clock::now();
    for (int i = 1; i <= 10; ++i) {
        auto startInsert = std::chrono::steady_clock::now(); // Medir tiempo de cada inserción
        treap2.insertar(i * 10);
        auto endInsert = std::chrono::steady_clock::now();
        tiemposInsercion.push_back(std::chrono::duration_cast<std::chrono::duration<double>>(endInsert - startInsert).count()); // Almacenar el tiempo de inserción
    }
    auto endInsertOrdered = std::chrono::steady_clock::now();
    std::cout << RED << "Tiempo de insercion de numeros ordenados: " << std::chrono::duration_cast<std::chrono::duration<double>>(endInsertOrdered - startInsertOrdered).count() << " s" << RESET << std::endl;

    std::cout << GREEN << "El recorrido inorder del segundo Treap es:" << RESET << std::endl;
    treap2.imprimir();

    endTotal = std::chrono::steady_clock::now(); // Definir el tiempo total al final del bloque de código principal

    // Calcular la media de los tiempos de inserción
    double media = 0.0;
    for (auto tiempo : tiemposInsercion) {
        media += tiempo;
    }
    media /= tiemposInsercion.size();

    // Calcular la desviación estándar de los tiempos de inserción
    double desviacionEstandar = 0.0;
    for (auto tiempo : tiemposInsercion) {
        desviacionEstandar += pow(tiempo - media, 2);
    }
    desviacionEstandar = sqrt(desviacionEstandar / tiemposInsercion.size());

    std::cout << MAGENTA << "--------------------------------------------" << RESET << std::endl;
    std::cout << RED << "Tiempo total: " << std::chrono::duration_cast<std::chrono::duration<double>>(endTotal - startTotal).count() << " s" << RESET << std::endl;

    // Imprimir la media y la desviación estándar
    std::cout << GREEN << "Media de los tiempos de insercion: " << media << " s" << RESET << std::endl;
    std::cout << MAGENTA << "Desviacion estandar de los tiempos de insercion: " << desviacionEstandar << " s" << RESET << std::endl;

    return 0;
}
