#include "ArbolRN.h"
#include <iostream>
#include <queue>  // Para recorrido por niveles
#include <iomanip>  // Para formato de impresión
#include <cmath>
#include <vector>

// Definición de colores para la consola
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define WHITE   "\033[37m"

using namespace std;

// Constructor: inicializa el árbol con un nodo nulo
ArbolRN::ArbolRN() {
    nulo = new NodoRN("", "", "", "");
    nulo->color = false; // El nodo nulo siempre es negro
    raiz = nulo;
}

// Rotación a la izquierda
void ArbolRN::rotarIzquierda(NodoRN* x) {
    NodoRN* y = x->derecho;
    x->derecho = y->izquierdo;

    if (y->izquierdo != nulo) {
        y->izquierdo->padre = x;
    }

    y->padre = x->padre;
    if (x->padre == nullptr) {
        raiz = y;
    } else if (x == x->padre->izquierdo) {
        x->padre->izquierdo = y;
    } else {
        x->padre->derecho = y;
    }

    y->izquierdo = x;
    x->padre = y;
}

// Rotación a la derecha
void ArbolRN::rotarDerecha(NodoRN* y) {
    NodoRN* x = y->izquierdo;
    y->izquierdo = x->derecho;

    if (x->derecho != nulo) {
        x->derecho->padre = y;
    }

    x->padre = y->padre;
    if (y->padre == nullptr) {
        raiz = x;
    } else if (y == y->padre->derecho) {
        y->padre->derecho = x;
    } else {
        y->padre->izquierdo = x;
    }

    x->derecho = y;
    y->padre = x;
}

// Inserción en el Árbol Rojo-Negro
void ArbolRN::insertar(const string& placa, const string& espacioId, const string& fechaHoraIngreso, const string& fechaHoraSalida) {
    NodoRN* nuevo = new NodoRN(placa, espacioId, fechaHoraIngreso, fechaHoraSalida);
    nuevo->izquierdo = nulo;
    nuevo->derecho = nulo;

    NodoRN* y = nullptr;
    NodoRN* x = raiz;

    while (x != nulo) {
        y = x;
        if (nuevo->placa < x->placa) {
            x = x->izquierdo;
        } else {
            x = x->derecho;
        }
    }

    nuevo->padre = y;
    if (y == nullptr) {
        raiz = nuevo;
    } else if (nuevo->placa < y->placa) {
        y->izquierdo = nuevo;
    } else {
        y->derecho = nuevo;
    }

    nuevo->color = true; // El nuevo nodo siempre es rojo
    balancearInsercion(nuevo);
}

// Balanceo después de la inserción
void ArbolRN::balancearInsercion(NodoRN* nodo) {
    NodoRN* tio;

    while (nodo->padre && nodo->padre->color == true) {
        if (nodo->padre == nodo->padre->padre->izquierdo) {
            tio = nodo->padre->padre->derecho;

            if (tio->color == true) { // Caso 1: El tío es rojo
                nodo->padre->color = false;
                tio->color = false;
                nodo->padre->padre->color = true;
                nodo = nodo->padre->padre;
            } else { // Caso 2 o 3: El tío es negro
                if (nodo == nodo->padre->derecho) { // Caso 2: Triángulo
                    nodo = nodo->padre;
                    rotarIzquierda(nodo);
                }

                nodo->padre->color = false; // Caso 3: Línea
                nodo->padre->padre->color = true;
                rotarDerecha(nodo->padre->padre);
            }
        } else {
            // Simétrico al caso anterior
            tio = nodo->padre->padre->izquierdo;

            if (tio->color == true) {
                nodo->padre->color = false;
                tio->color = false;
                nodo->padre->padre->color = true;
                nodo = nodo->padre->padre;
            } else {
                if (nodo == nodo->padre->izquierdo) {
                    nodo = nodo->padre;
                    rotarDerecha(nodo);
                }

                nodo->padre->color = false;
                nodo->padre->padre->color = true;
                rotarIzquierda(nodo->padre->padre);
            }
        }
    }

    raiz->color = false; // La raíz siempre es negra
}

// Buscar un nodo en el árbol
NodoRN* ArbolRN::buscar(const string& placa) const {
    return buscarNodo(raiz, placa);
}

NodoRN* ArbolRN::buscarNodo(NodoRN* nodo, const string& placa) const {
    if (nodo == nulo || nodo->placa == placa) {
        return nodo;
    }

    if (placa < nodo->placa) {
        return buscarNodo(nodo->izquierdo, placa);
    } else {
        return buscarNodo(nodo->derecho, placa);
    }
}

// Recorrido inOrden
vector<NodoRN*> ArbolRN::obtenerInOrden() const {
    vector<NodoRN*> nodos;
    recorridoInOrden(raiz, nodos);
    return nodos;
}

void ArbolRN::recorridoInOrden(NodoRN* nodo, vector<NodoRN*>& nodos) const {
    if (nodo != nulo) {
        recorridoInOrden(nodo->izquierdo, nodos);
        nodos.push_back(nodo);
        recorridoInOrden(nodo->derecho, nodos);
    }
}

// Destructor
ArbolRN::~ArbolRN() {
    eliminarNodo(raiz);
    delete nulo;
}

void ArbolRN::eliminarNodo(NodoRN* nodo) {
    if (nodo != nulo) {
        eliminarNodo(nodo->izquierdo);
        eliminarNodo(nodo->derecho);
        delete nodo;
    }
}

void ArbolRN::imprimirArbol() const {
    if (raiz == nulo) {
        cout << "El árbol está vacío.\n";
        return;
    }

    //cout << "Árbol Rojo-Negro (In-Orden):\n";
    //imprimirInOrden(raiz);
    //cout << endl;
}

// Función auxiliar para imprimir en orden
void ArbolRN::imprimirInOrden(NodoRN* nodo) const {
    if (nodo != nulo) {
        imprimirInOrden(nodo->izquierdo);
        cout << "Placa: " << nodo->placa << " | Espacio: " << nodo->espacioId
             << " | Ingreso: " << nodo->fechaHoraIngreso
             << " | Color: " << (nodo->color ? "Rojo" : "Negro") << endl;
        imprimirInOrden(nodo->derecho);
    }
}

void ArbolRN::mostrarArbol(NodoRN *nodo, int espacio) const {
    if (nodo == nulo) return;

    // Incrementar el espacio para separar niveles
    espacio += 10;

    // Imprimir el subárbol derecho primero (para que la raíz quede centrada)
    mostrarArbol(nodo->derecho, espacio);

    // Imprimir nodo con espaciado adecuado
    cout << endl;
    for (int i = 10; i < espacio; i++) cout << " ";
    cout << (nodo->color ? "\033[31m" : "\033[37m") << nodo->espacioId << "\033[0m" << endl;

    // Imprimir el subárbol izquierdo
    mostrarArbol(nodo->izquierdo, espacio);
    cout << "Árbol Rojo-Negro (In-Orden):\n";
    imprimirInOrden(raiz);
    cout << endl;
}

void ArbolRN::mostrarArbol() const {
    if (raiz == nulo) {
        cout << "Árbol vacío.\n";
        return;
    }

    cout << "Árbol Rojo-Negro (In-Orden):\n";
    imprimirInOrden(raiz);
    cout << endl;
    
    queue<pair<NodoRN*, int>> q; // Cola para recorrer por niveles
    q.push({raiz, 0});
    int nivelActual = 0;
    bool hayMasNodos = true;

    while (hayMasNodos) {
        hayMasNodos = false;
        int nodosNivel = q.size();

        for (int i = 0; i < nodosNivel; i++) {
            auto [nodo, nivel] = q.front();
            q.pop();

            // Cambio de nivel
            if (nivel != nivelActual) {
                cout << "\n\n";
                nivelActual = nivel;
            }

            // Espaciado proporcional al nivel
            cout << setw(10 / (nivel + 1)) << "";

            // Dibujar nodo
            if (nodo) {
                hayMasNodos = true; // Hay nodos en este nivel
                cout << (nodo->color ? "\033[31m" : "\033[37m") << nodo->espacioId << "\033[0m";
                q.push({nodo->izquierdo, nivel + 1});
                q.push({nodo->derecho, nivel + 1});
            } else {
                cout << " ";
                q.push({nullptr, nivel + 1});
                q.push({nullptr, nivel + 1});
            }
        }
    }
    cout << "\n";
}


void ArbolRN::recorridoPreorden(NodoRN* nodo) const {
    if (nodo == nulo) return;
    
    // Mostrar el nodo actual
    cout << "(" << (nodo->color ? RED : WHITE) << nodo->espacioId << RESET << ") - ";
    
    // Recorrer primero el subárbol izquierdo
    recorridoPreorden(nodo->izquierdo);
    
    // Luego el subárbol derecho
    recorridoPreorden(nodo->derecho);
}

void ArbolRN::recorridoInorden(NodoRN* nodo) const {
    if (nodo == nulo) return;
    
    // Recorrer primero el subárbol izquierdo
    recorridoInorden(nodo->izquierdo);
    
    // Mostrar el nodo actual
    cout << "(" << (nodo->color ? RED : WHITE) << nodo->espacioId << RESET << ") - ";
    
    // Luego el subárbol derecho
    recorridoInorden(nodo->derecho);
}

void ArbolRN::recorridoPostorden(NodoRN* nodo) const {
    if (nodo == nulo) return;
    
    // Recorrer primero el subárbol izquierdo
    recorridoPostorden(nodo->izquierdo);
    
    // Luego el subárbol derecho
    recorridoPostorden(nodo->derecho);
    
    // Mostrar el nodo actual
    cout << "(" << (nodo->color ? RED : WHITE) << nodo->espacioId << RESET << ") - ";
}

void ArbolRN::mostrarRecorridos() const {
    cout << "\nRecorrido Preorden: ";
    recorridoPreorden(raiz);
    cout << "\n";
    
    cout << "\nRecorrido Inorden: ";
    recorridoInorden(raiz);
    cout << "\n";
    
    cout << "\nRecorrido Postorden: ";
    recorridoPostorden(raiz);
    cout << "\n";
}

NodoRN* ArbolRN::obtenerRaiz() {
    return raiz;
}

//  Método para obtener la altura total del árbol
int ArbolRN::obtenerAltura(NodoRN* nodo) const {
    if (nodo == nullptr || nodo == nulo) {  // Los nodos nulos tienen altura 0
        return 0;
    }
    return max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho)) + 1;
}

//  Método para calcular la altura negra del árbol (nodos negros en el camino más largo)
int ArbolRN::obtenerAlturaNegra(NodoRN* nodo) const {
    if (nodo == nullptr || nodo == nulo) {  // Los nodos nulos tienen altura negra 0
        return 0;
    }
    int alturaIzq = obtenerAlturaNegra(nodo->izquierdo);
    int alturaDer = obtenerAlturaNegra(nodo->derecho);

    // Solo contamos los nodos negros en la altura negra
    if (nodo->color == NEGRO) {
        return max(alturaIzq, alturaDer) + 1;
    } else {
        return max(alturaIzq, alturaDer);
    }
}

int ArbolRN::obtenerProfundidad(NodoRN* nodo) {
    if (nodo == nullptr || nodo == raiz) {
        return 0;  // La raíz tiene profundidad 0
    }
    return 1 + obtenerProfundidad(nodo->padre);  // Sumar 1 en cada nivel hacia arriba
}

NodoRN* ArbolRN::buscarNodoID(NodoRN* nodo, const string& espacioId) const {
    // Si el nodo es nulo, no se encontró el espacioId
    if (nodo == nullptr) {
        return nullptr;
    }

    // Si el nodo actual contiene el espacioId, retorna el nodo
    if (nodo->espacioId == espacioId) {
        return nodo;
    }

    // Si el espacioId es menor que el del nodo actual, busca en el subárbol izquierdo
    if (espacioId < nodo->espacioId) {
        return buscarNodo(nodo->izquierdo, espacioId);
    }

    // Si el espacioId es mayor que el del nodo actual, busca en el subárbol derecho
    return buscarNodo(nodo->derecho, espacioId);
}
