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

Nodo::Nodo(int _dato) {
    dato = _dato;
    siguiente = NULL;
    anterior = NULL;
}

void Nodo::setDato(int _dato) {
    dato = _dato;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

void Nodo::setAnterior(Nodo* _anterior) {
    anterior = _anterior;
}

int Nodo::getDato() {
    return dato;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

Nodo* Nodo::getAnterior() {
    return anterior;
}
