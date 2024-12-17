/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Validacion de datos                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include <string>
#include <functional>
#include <cctype>

using namespace std;

class InputValidator {
public:
    static int ingresarEntero(const string& mensaje) {
        return ingresar<int>(mensaje, [](const string& str) { return stoi(str); });
    }

    static float ingresarFlotante(const string& mensaje) {
        return ingresar<float>(mensaje, [](const string& str) { return stof(str); });
    }

    static char ingresarLetra(const string& mensaje) {
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

    static string ingresarString(const string& mensaje) {
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

    static double ingresarDouble(const string& mensaje) {
        return ingresar<double>(mensaje, [](const string& str) { return stod(str); });
    }

private:
    template <typename T>
    static T ingresar(const string& mensaje, function<T(const string&)> convert) {
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
        return convert(cad);
    }
};



// Función principal
int main() {
    int entero = InputValidator::ingresarEntero("Ingrese un valor entero: ");
    cout << endl;

    float flotante = InputValidator::ingresarFlotante("Ingrese un valor flotante: ");
    cout << endl;

    char letra = InputValidator::ingresarLetra("Ingrese una letra: ");
    cout << endl << "Letra ingresada: " << letra << endl;

    string cadena = InputValidator::ingresarString("Ingrese una cadena de texto: ");
    cout << endl << "Cadena ingresada: " << cadena << endl;

    double numeroDouble = InputValidator::ingresarDouble("Ingrese un valor double: ");
    cout << endl << "Valor double ingresado: " << numeroDouble << endl;

    return 0;
}
