/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Circulares                                   *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          25/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "ListasCirculares.h"

using namespace std;

inline ListaCircular::ListaCircular() {
    primero = NULL;
    ultimo = NULL;
}

inline void ListaCircular::Insertar(int dato) {
    Nodo* nuevo = new Nodo(dato);
    if (primero == NULL) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

inline void ListaCircular::Buscar(int dato) {
    Nodo* actual = new Nodo(dato);
    actual = primero;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                cout << "\nEl elemento " << dato << " ha sido encontrado en la lista" << endl;
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "\nEl elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "\nLa lista se encuentra vacia" << endl;
    }
}

inline void ListaCircular::Eliminar(int dato) {
    Nodo* actual = new Nodo(dato);
    actual = primero;
    Nodo* anterior = new Nodo(dato);
    anterior = NULL;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                if (actual == primero) {
                    primero = primero->getSiguiente();
                }
                else if (actual == ultimo) {
                    anterior->setSiguiente(primero);
                }
                else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                cout << "\nEl elemento " << dato << " ha sido eliminado de la lista" << endl;
                encontrado = true;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "\nEl elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "\nLa lista se encuentra vacia" << endl;
    }
}

inline void ListaCircular::Mostrar() {
    Nodo* actual = new Nodo(0);
    actual = primero;
    if (primero != NULL) {
        do {
            cout << actual->getDato() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        cout << "\nLa lista se encuentra vacia" << endl;
    }
}
