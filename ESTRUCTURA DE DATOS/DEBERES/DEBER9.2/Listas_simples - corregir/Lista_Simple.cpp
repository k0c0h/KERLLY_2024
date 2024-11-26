/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Lista_Simple.h"

using namespace std;


template <typename T>
Lista_Simple<T>::Lista_Simple()
{
    cabeza = NULL;
}

template <typename T>
void Lista_Simple<T>::Insertar_cabeza(T _dato)
{
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        nuevo->setSiguiente(cabeza); 
        cabeza = nuevo;  
    }
}

template <typename T>
void Lista_Simple<T>::Insertar_cola(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo<T>* temp = cabeza;
        while (temp->getSiguiente()) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
    }
}


template<typename T> 
 void Lista_Simple<T>::Buscar(T _dato) {
    Nodo<T>* aux = cabeza;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

template <typename T>
void Lista_Simple<T>::Eliminar_cabeza() {
    if (!cabeza) {
        cout << "La lista está vacía.\n";
        return;
    }
    Nodo<T>* temp = cabeza;
    cabeza = cabeza->getSiguiente();
    delete temp;
    cout << "Elemento eliminado del inicio.\n";
}

template <typename T>
void Lista_Simple<T>::Eliminar_cola() {
    if (!cabeza) {
        cout << "La lista está vacía.\n";
        return;
    }
    if (cabeza->getSiguiente() == nullptr) { 
        delete cabeza;
        cabeza = nullptr;
    } else {
        Nodo<T>* temp = cabeza;
        while (temp->getSiguiente() && temp->getSiguiente()->getSiguiente()) {
            temp = temp->getSiguiente();
        }
        delete temp->getSiguiente();
        temp->setSiguiente(nullptr);
    }
    cout << "Elemento eliminado del final.\n";
}

template<typename T> 
 void Lista_Simple<T>::Mostrar() {
    Nodo<T>* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}
