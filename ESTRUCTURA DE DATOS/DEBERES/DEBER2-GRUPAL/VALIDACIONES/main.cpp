/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Validacion de datos                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              08/11/2024                          *
 * Fecha de modificacion:          09/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "InputValidator.h"
#include <iostream>

using namespace std;

int main() {
    int entero = InputValidator::ingresarEntero("Ingrese un valor entero: ");
    cout << endl << "Valor entero ingresado: " << entero << endl;

    float flotante = InputValidator::ingresarFlotante("Ingrese un valor flotante: ");
    cout << endl << "Valor flotante ingresado: " << flotante << endl;

    char letra = InputValidator::ingresarLetra("Ingrese una letra: ");
    cout << endl << "Letra ingresada: " << letra << endl;

    string cadena = InputValidator::ingresarString("Ingrese una cadena de texto: ");
    cout << endl << "Cadena ingresada: " << cadena << endl;

    double numeroDouble = InputValidator::ingresarDouble("Ingrese un valor double: ");
    cout << endl << "Valor double ingresado: " << numeroDouble << endl;

    return 0;
}
