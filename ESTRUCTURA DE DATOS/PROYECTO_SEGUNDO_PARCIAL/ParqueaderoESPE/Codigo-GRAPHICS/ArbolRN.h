#ifndef ARBOLRN_H
#define ARBOLRN_H

#include "NodoRN.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp> 

using namespace sf;

using namespace std;

class ArbolRN {
private:
    NodoRN* raiz;             // Raíz del árbol
    NodoRN* nulo;             // Nodo nulo para representar hojas vacías

    // Métodos auxiliares
    void rotarIzquierda(NodoRN* x);
    void rotarDerecha(NodoRN* y);
    void balancearInsercion(NodoRN* nodo);
    void balancearEliminacion(NodoRN* nodo);
    void eliminarNodo(NodoRN* nodo);

    void recorridoInOrden(NodoRN* nodo, vector<NodoRN*>& nodos) const;

    NodoRN* buscarNodo(NodoRN* nodo, const string& placa) const;
    void imprimirInOrden(NodoRN* nodo) const;
    void drawTree(sf::RenderWindow &window, NodoRN *nodo, int x, int y, int offset);
    
public:
    // Constructor
    ArbolRN();

    // Operaciones principales
    void insertar(const string& placa, const string& espacioId, const string& fechaHoraIngreso, const string& fechaHoraSalida = "");
    void eliminar(const string& placa);
    NodoRN* buscar(const string& placa) const;

    // Recorrido
    vector<NodoRN*> obtenerInOrden() const;
    void imprimirArbol() const;
    void imprimirArbolVisual(NodoRN* nodo, int espacio) const;
    void imprimirArbolVertical() const;
    void imprimirArbolGrafico();

    // Destructor
    ~ArbolRN();
};

#endif
