#ifndef NODORN_H
#define NODORN_H

#include <iostream>
#include <string>
using namespace std;

// Definir códigos de color ANSI para terminal
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define WHITE   "\033[1;37m"

class NodoRN {
public:
    string placa;             // Clave principal (para búsqueda)
    string espacioId;         // ID del espacio del parqueadero
    string fechaHoraIngreso;  // Fecha y hora de ingreso
    string fechaHoraSalida;   // Fecha y hora de salida (vacía si aún está estacionado)

    bool color;               // true = rojo, false = negro
    NodoRN* padre;            // Puntero al nodo padre
    NodoRN* izquierdo;        // Puntero al hijo izquierdo
    NodoRN* derecho;          // Puntero al hijo derecho

    // Constructor
    NodoRN(const string& placa, const string& espacioId, 
           const string& fechaHoraIngreso, const string& fechaHoraSalida = "") 
        : placa(placa), espacioId(espacioId), fechaHoraIngreso(fechaHoraIngreso), 
          fechaHoraSalida(fechaHoraSalida), color(true), 
          padre(nullptr), izquierdo(nullptr), derecho(nullptr) {}

    // Imprimir el árbol en formato visual
    void imprimirArbol(int espacio = 0) {
        if (this == nullptr) return;

        espacio += 6;  // Espaciado entre niveles

        // Imprimir el subárbol derecho
        if (derecho) derecho->imprimirArbol(espacio);

        // Imprimir nodo actual con color
        cout << endl;
        for (int i = 6; i < espacio; i++)
            cout << " ";
        cout << (color ? RED : WHITE) << espacioId << RESET << endl;

        // Imprimir el subárbol izquierdo
        if (izquierdo) izquierdo->imprimirArbol(espacio);
    }
};

#endif
