#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>

template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    Lista() : cabeza(nullptr), cola(nullptr) {}
    ~Lista() {}
    
    void insertarFrente(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
    }

    void insertarAtras(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cola == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    bool buscar(T valor) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void eliminarFrente() {
        if (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void eliminarAtras() {
        if (cabeza == nullptr) return;
        
        if (cabeza == cola) {
            delete cabeza;
            cabeza = cola = nullptr;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != cola) {
                temp = temp->siguiente;
            }
            delete cola;
            cola = temp;
            cola->siguiente = nullptr;
        }
    }

    void imprimir() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void ejecutarOperaciones() {
        // Implementar la ejecución de las operaciones
    }

    void imprimirAtrasRecursivo(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        imprimirAtrasRecursivo(nodo->siguiente);
        std::cout << nodo->dato << " ";
    }
};

#endif
