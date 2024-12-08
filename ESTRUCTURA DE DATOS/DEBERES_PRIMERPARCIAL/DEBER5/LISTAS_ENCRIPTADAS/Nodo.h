/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef NODO_H
#define NODO_H

template <typename T>
class ListaDoble;

template <typename T>
class ListaCircular;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    Nodo(const T& dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}

    friend class ListaDoble<T>;
    friend class ListaCircular<T>;
};

#endif 
