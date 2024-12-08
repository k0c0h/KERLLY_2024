/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "Lista.h"
#include <iostream>
#include <functional>
#include "Nodo.h"
using namespace std;

template <typename T>
class ListaDoble : public Lista<T> {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDoble() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void insertar(const T& dato) override {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (cabeza == nullptr) {
            cabeza = cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void mostrar() const override {
        if (cabeza == nullptr) {
            cout << "ListaDoble vacia." << endl;
            return;
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " <-> ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void encriptar(function<T(const T&)> func) override {
        if (cabeza == nullptr) {
            cout << "ListaDoble vacia. Nada que encriptar." << endl;
            return;
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            actual->dato = func(actual->dato);
            actual = actual->siguiente;
        }
    }
};

#endif 