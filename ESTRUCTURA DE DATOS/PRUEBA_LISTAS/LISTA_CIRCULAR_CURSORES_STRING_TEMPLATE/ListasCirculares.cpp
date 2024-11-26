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

template<typename T>
inline ListaCircular<T>::ListaCircular() {
    primero = nullptr;
    ultimo = nullptr;
}

template<typename T>
inline void ListaCircular<T>::Insertar(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (primero == nullptr) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

template<typename T>
inline void ListaCircular<T>::Buscar(T dato) {
    Nodo<T>* actual = primero;
    bool encontrado = false;
    if (primero != nullptr) {
        do {
            if (actual->getDato() == dato) {
                cout << "\nEl elemento " << dato << " ha sido encontrado en la lista" << endl;
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero && !encontrado);
        if (!encontrado) {
            cout << "\nEl elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    } else {
        cout << "\nLa lista se encuentra vacía" << endl;
    }
}

template<typename T>
inline void ListaCircular<T>::Eliminar(T dato) {
    Nodo<T>* actual = primero;
    Nodo<T>* anterior = nullptr;
    bool encontrado = false;
    if (primero != nullptr) {
        do {
            if (actual->getDato() == dato) {
                if (actual == primero) {
                    primero = primero->getSiguiente();
                    ultimo->setSiguiente(primero);
                } else if (actual == ultimo) {
                    anterior->setSiguiente(primero);
                    ultimo = anterior;
                } else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                delete actual;
                cout << "\nEl elemento " << dato << " ha sido eliminado de la lista" << endl;
                encontrado = true;
                break;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        } while (actual != primero);
        if (!encontrado) {
            cout << "\nEl elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    } else {
        cout << "\nLa lista se encuentra vacía" << endl;
    }
}

template<typename T>
inline void ListaCircular<T>::Mostrar() {
    Nodo<T>* actual = primero;
    if (primero != nullptr) {
        do {
            cout << actual->getDato() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
        cout << " (vuelta al inicio)" << endl;
    } else {
        cout << "\nLa lista se encuentra vacía" << endl;
    }
}
