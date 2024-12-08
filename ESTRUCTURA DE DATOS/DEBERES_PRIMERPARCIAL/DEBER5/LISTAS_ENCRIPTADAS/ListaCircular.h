/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Lista.h"
#include <iostream>
#include <functional>
#include "Nodo.h"
using namespace std;

template <typename T>
class ListaCircular : public Lista<T> {
private:
    Nodo<T>* cabeza;

public:
    ListaCircular() : cabeza(nullptr) {}

    ~ListaCircular() {
        if (!cabeza) return; 
        Nodo<T>* actual = cabeza;
        do {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        } while (actual != cabeza);
        cabeza = nullptr;
    }

    void insertar(const T& dato) override {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (!cabeza) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
            nuevo->siguiente = cabeza;
        }
    }

    void mostrar() const override {
        if (!cabeza) {
            cout << "Lista Circular esta vacia" << endl;
            return;
        }
        Nodo<T>* actual = cabeza;
        do {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        cout << endl;
    }

    void encriptar(function<T(const T&)> func) override {
        if (!cabeza) return; 
        Nodo<T>* actual = cabeza;
        do {
            actual->dato = func(actual->dato);
            actual = actual->siguiente;
        } while (actual != cabeza);
    }
};

#endif 
