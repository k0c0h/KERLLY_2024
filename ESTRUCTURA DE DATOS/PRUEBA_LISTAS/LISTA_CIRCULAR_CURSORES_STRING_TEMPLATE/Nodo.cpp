/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Circulares                                   *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          25/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Nodo.h"

template<typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    this->siguiente = nullptr;
}

template<typename T>
void Nodo<T>::setDato(T dato) {
    this->dato = dato;
}

template<typename T>
T Nodo<T>::getDato() {
    return this->dato;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return this->siguiente;
}
