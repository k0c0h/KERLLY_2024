#ifndef GENERADORCORREOS_H
#define GENERADORCORREOS_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cctype> 
#include "Validaciones.h"

using namespace std;

template <typename T>
class GeneradorCorreos {
private:
    unordered_set<string> palabrasIgnoradas = {"de", "del", "la", "las", "los"};
    unordered_map<string, int> contadorCorreos;
    vector<string> correos;

    char obtenerInicial(const string& palabra);
    string procesarApellido(const string& apellidoCompuesto);
    string generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido);

public:
    void ingresarDatos();
    void mostrarCorreos() const;
};


template <typename T>
char GeneradorCorreos<T>::obtenerInicial(const string& palabra) {
    if (palabrasIgnoradas.find(palabra) == palabrasIgnoradas.end()) {
        return tolower(palabra[0]);
    }
    return '\0'; 
}

template <typename T>
string GeneradorCorreos<T>::procesarApellido(const string& apellidoCompuesto) {
    stringstream ss(apellidoCompuesto);
    string palabra, ultimaValida;

    while (ss >> palabra) {
        if (palabrasIgnoradas.find(palabra) == palabrasIgnoradas.end()) {
            ultimaValida = palabra; 
        }
    }

    if (!ultimaValida.empty()) {
        ultimaValida[0] = tolower(ultimaValida[0]);
    }

    return ultimaValida;
}

template <typename T>
string GeneradorCorreos<T>::generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido) {
    string correo;
    stringstream ssPrimerNombre(primerNombre), ssSegundoNombre(segundoNombre);
    string palabra;

    while (ssPrimerNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correo += inicial;
            break; 
        }
    }

    while (ssSegundoNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correo += inicial;
            break;
        }
    }

    correo += procesarApellido(apellido);

    if (contadorCorreos[correo] > 0) {
        correo += to_string(contadorCorreos[correo]);
    }
    contadorCorreos[correo]++;
    correo += "@espe.edu.ec";

    return correo;
}

template <typename T>
void GeneradorCorreos<T>::ingresarDatos() {
    Validaciones<string> valString;

    string primerNombre = valString.ingresar("Ingrese el primer nombre (puede ser compuesto): ", "string");
    string segundoNombre = valString.ingresar("Ingrese el segundo nombre (puede ser compuesto o vacío): ", "string");
    string apellidoCompuesto = valString.ingresar("Ingrese el apellido compuesto: ", "string");
    string correo = generarCorreo(primerNombre, segundoNombre, apellidoCompuesto);
    correos.push_back(correo);

    cout << "\nCorreo generado: " << correo << endl;
}

template <typename T>
void GeneradorCorreos<T>::mostrarCorreos() const {
    cout << "\nCorreos generados:\n";
    for (const auto& correo : correos) {
        cout << correo << endl;
    }
}

#endif
