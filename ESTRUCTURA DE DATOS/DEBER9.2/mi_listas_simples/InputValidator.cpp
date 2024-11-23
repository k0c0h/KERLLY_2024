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
#include <conio.h>
#include <cctype>
#include <stdexcept>

using namespace std;

int InputValidator::ingresarEntero(const string& mensaje) {
    return ingresar<int>(mensaje, [](const string& str) { return stoi(str); });
}

float InputValidator::ingresarFlotante(const string& mensaje) {
    return ingresar<float>(mensaje, [](const string& str) { return stof(str); });
}

char InputValidator::ingresarLetra(const string& mensaje) {
    cout << mensaje;
    char c;
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

string InputValidator::ingresarString(const string& mensaje) {
    cout << mensaje;
    string resultado;
    char c;
    while ((c = getch()) != 13) { 
        if (isalpha(c)) {
            cout << c;
            resultado += c;
        } else if (c == 8 && !resultado.empty()) {
            cout << "\b \b";
            resultado.pop_back();
        }
    }
    return resultado;
}

double InputValidator::ingresarDouble(const string& mensaje) {
    return ingresar<double>(mensaje, [](const string& str) { return stod(str); });
}

template <typename T>
T InputValidator::ingresar(const string& mensaje, function<T(const string&)> convert) {
    cout << mensaje;
    string cad;
    char c;
    bool puntoDecimal = false;
    while ((c = getch()) != 13) { 
        if (isdigit(c)) {
            cout << c;
            cad += c;
        } else if (c == 8 && !cad.empty()) {
            cout << "\b \b";
            cad.pop_back();
        } else if (c == '.' && !puntoDecimal) {
            cout << c;
            cad += c;
            puntoDecimal = true;
        }
    }
    try {
        return convert(cad);
    } catch (const invalid_argument& e) {
        cout << "\nEntrada no valida. Intente nuevamente.\n";
        return ingresar<T>(mensaje, convert);
    } catch (const out_of_range& e) {
        cout << "\nNumero fuera de rango. Intente nuevamente.\n";
        return ingresar<T>(mensaje, convert);
    }
}
