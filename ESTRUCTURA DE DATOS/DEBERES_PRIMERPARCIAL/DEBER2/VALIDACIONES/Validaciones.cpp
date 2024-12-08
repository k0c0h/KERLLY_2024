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
#include <cstdlib>
#include <conio.h>
#include <cctype>

using namespace std;

// Función para ingresar enteros
int Validaciones::ingresar(const char *msj) {
    char cad[10];
    char c;
    int i = 0;
    int valor = 0;
    cout << msj;
    while ((c = getch()) != 13) {  // 13 es la tecla Enter
        if (isdigit(c)) {
            cout << c;
            cad[i++] = c;
        } else if (c == 8 && i > 0) {  // Tecla Backspace
            cout << "\b \b";
            i--;
        }
    }
    cad[i] = '\0';
    valor = atoi(cad);
    return valor;
}

// Función para ingresar letras
char Validaciones::ingresarLetra(const char *msj) {
    char c;
    cout << msj;
    while (true) {
        c = getch();
        if (isalpha(c)) {
            cout << c;
            return c;
        } else if (c == 8) {
            cout << "\b \b";
        }
    }
}

// Función para ingresar valores flotantes
float Validaciones::ingresarFloat(const char *msj) {
    char cad[20];
    char c;
    int i = 0;
    bool punto = false;
    cout << msj;
    while ((c = getch()) != 13) {
        if (isdigit(c)) {
            cout << c;
            cad[i++] = c;
        } else if (c == '.' && !punto) {
            cout << c;
            cad[i++] = c;
            punto = true;
        } else if (c == 8 && i > 0) {  // Backspace
            cout << "\b \b";
            i--;
        }
    }
    cad[i] = '\0';
    return atof(cad);
}

// Función para ingresar strings
string Validaciones::ingresarString(const char *msj) {
    char c;
    string resultado;
    cout << msj;
    while ((c = getch()) != 13) {
        if (isalpha(c) || c == ' ') {
            cout << c;
            resultado += c;
        } else if (c == 8 && !resultado.empty()) {  // Backspace
            cout << "\b \b";
            resultado.pop_back();
        }
    }
    return resultado;
}

// Función para ingresar valores double
double Validaciones::ingresarDouble(const char *msj) {
    char cad[20];
    char c;
    int i = 0;
    bool punto = false;
    cout << msj;
    while ((c = getch()) != 13) {
        if (isdigit(c)) {
            cout << c;
            cad[i++] = c;
        } else if (c == '.' && !punto) {
            cout << c;
            cad[i++] = c;
            punto = true;
        } else if (c == 8 && i > 0) {  // Backspace
            cout << "\b \b";
            i--;
        }
    }
    cad[i] = '\0';
    return atof(cad);
}
