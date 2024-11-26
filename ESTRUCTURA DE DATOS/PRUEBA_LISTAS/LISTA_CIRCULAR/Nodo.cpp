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

using namespace std;

Nodo::Nodo(int dato) {
    this->dato = dato;
    this->siguiente = NULL;
}

void Nodo::setDato(int dato) {
    this->dato = dato;
}

int Nodo::getDato() {
    return this->dato;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo* Nodo::getSiguiente() {
    return this->siguiente;
}
