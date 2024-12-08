/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                     Validaciones                         *
 * Autor:                         Kerlly Chiriboga                     *
 * Fecha de creacion:              10/10/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Validaciones.h"
#include <iostream>

using namespace std;

int main() {
    Validaciones validador;

    int imprimirNumeros = validador.ingresar("Ingrese un valor entero: ");
    cout << endl << "Valor entero ingresado: " << imprimirNumeros << endl;

    char imprimirLetras = validador.ingresarLetra("Ingrese una letra: ");
    cout << endl << "Letra ingresada: " << imprimirLetras << endl;

    float imprimirFloats = validador.ingresarFloat("Ingrese un valor flotante: ");
    cout << endl << "Valor flotante ingresado: " << imprimirFloats << endl;

    string imprimirString = validador.ingresarString("Ingrese un string: ");
    cout << endl << "String ingresado: " << imprimirString << endl;

    double imprimirDouble = validador.ingresarDouble("Ingrese un valor double: ");
    cout << endl << "Valor double ingresado: " << imprimirDouble << endl;

    return 0;
}
