#include "Matriz.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Matriz::Matriz(int f, int c) {
    filas = f;
    columnas = c;
    matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
}

Matriz::~Matriz() {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz; 
}

int Matriz::getElemento(int f, int c) const {
    return *(*(matriz + f) + c); 
}

void Matriz::setElemento(int f, int c, int valor) {
    *(*(matriz + f) + c) = valor; 
}

void Matriz::llenarMatriz() {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            setElemento(i, j, rand() % 1001); 
        }
    }
}

void Matriz::mostrarMatriz() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << getElemento(i, j) << "\t";
        }
        cout << endl;
    }
}

int Matriz::sumaRecursivaMatrices(const Matriz& m1, const Matriz& m2, int f, int c) {
    if (f == 0 && c == 0) {
        return m1.getElemento(f, c) + m2.getElemento(f, c);
    } else {
        if (f >= 0) {
            c--;
            if (c >= -1) {
                return m1.getElemento(f, c + 1) + m2.getElemento(f, c + 1) + sumaRecursivaMatrices(m1, m2, f, c);
            } else {
                return sumaRecursivaMatrices(m1, m2, f - 1, c - 1);
            }
        }
    }
    return 0;
}
