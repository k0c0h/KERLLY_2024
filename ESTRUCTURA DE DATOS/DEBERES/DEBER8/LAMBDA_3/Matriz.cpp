#include "Matriz.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
Matriz<T>::Matriz(int f, int c) : filas(f), columnas(c) {
    matriz = new T*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new T[columnas];
    }
}

template <typename T>
Matriz<T>::~Matriz() {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

template <typename T>
void Matriz<T>::llenarMatriz() {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 1001; 
        }
    }
}

template <typename T>
void Matriz<T>::mostrarMatriz() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <typename T>
T Matriz<T>::getElemento(int f, int c) const {
    return matriz[f][c];
}

template <typename T>
void Matriz<T>::setElemento(int f, int c, T valor) {
    matriz[f][c] = valor;
}

template <typename T>
T Matriz<T>::sumaRecursivaMatrices(const Matriz<T>& m1, const Matriz<T>& m2, int f, int c) {
    auto sumarMatrices = [](auto& self, const Matriz<T>& m1, const Matriz<T>& m2, int fila, int col) -> T {
        if (fila < 0) return 0;
        if (col < 0) return self(self, m1, m2, fila - 1, m1.columnas - 1); 
        return m1.getElemento(fila, col) + m2.getElemento(fila, col) + self(self, m1, m2, fila, col - 1);  // Sumar y recursión
    };

    return sumarMatrices(sumarMatrices, m1, m2, f, c);
}

template class Matriz<int>;
