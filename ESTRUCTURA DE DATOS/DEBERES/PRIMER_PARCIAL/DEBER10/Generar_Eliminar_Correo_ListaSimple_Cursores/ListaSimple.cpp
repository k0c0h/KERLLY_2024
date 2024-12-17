/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "ListaSimple.h"

template <typename T>
void ListaSimple<T>::Insertar_cabeza(T _dato) {
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

template <typename T>
void ListaSimple<T>::Mostrar() const {
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        cout << aux->getDato() << endl; 
        aux = aux->getSiguiente();
    }
}

template <typename T>
ListaSimple<T>::~ListaSimple() {
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        Nodo<T>* siguiente = aux->getSiguiente();
        delete aux;
        aux = siguiente;
    }
}
