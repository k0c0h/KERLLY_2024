/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Dobles                                       *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "Nodo.h"

template<typename T>
Nodo<T>::Nodo(T _dato) {
    dato = _dato;
    siguiente = nullptr;
    anterior = nullptr;
}

template<typename T>
void Nodo<T>::setDato(T _dato) {
    dato = _dato;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T>* _siguiente) {
    siguiente = _siguiente;
}

template<typename T>
void Nodo<T>::setAnterior(Nodo<T>* _anterior) {
    anterior = _anterior;
}

template<typename T>
T Nodo<T>::getDato() {
    return dato;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::getAnterior() {
    return anterior;
}
