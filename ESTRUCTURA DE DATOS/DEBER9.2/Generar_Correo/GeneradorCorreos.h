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
#include <algorithm>


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
    string palabraMinuscula = palabra;
    transform(palabraMinuscula.begin(), palabraMinuscula.end(), palabraMinuscula.begin(), ::tolower);

    if (palabrasIgnoradas.find(palabraMinuscula) == palabrasIgnoradas.end()) {
        return tolower(palabra[0]);
    }
    return '\0';
}
template <typename T>
string GeneradorCorreos<T>::procesarApellido(const string& apellidoCompuesto) {
    stringstream ss(apellidoCompuesto);
    string palabra, apellidoProcesado;

    while (ss >> palabra) {
        string palabraMinuscula = palabra;
        transform(palabraMinuscula.begin(), palabraMinuscula.end(), palabraMinuscula.begin(), ::tolower);

        if (palabrasIgnoradas.find(palabraMinuscula) == palabrasIgnoradas.end()) {
            apellidoProcesado = palabra; // Última palabra válida encontrada
        }
    }

    if (!apellidoProcesado.empty()) {
        apellidoProcesado[0] = tolower(apellidoProcesado[0]); // Primera letra en minúscula
    }

    return apellidoProcesado;
}

template <typename T>
string GeneradorCorreos<T>::generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido) {
    string correoBase;
    stringstream ssPrimerNombre(primerNombre), ssSegundoNombre(segundoNombre);
    string palabra;

    // Obtener inicial del primer nombre
    while (ssPrimerNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break; // Usar solo la primera inicial válida
        }
    }

    // Obtener inicial del segundo nombre
    while (ssSegundoNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break; // Usar solo la primera inicial válida
        }
    }

    // Procesar el apellido compuesto
    correoBase += procesarApellido(apellido);

    // Generar el correo final con índice si es necesario
    string correoFinal = correoBase;
    if (contadorCorreos[correoBase] > 0) {
        correoFinal += to_string(contadorCorreos[correoBase]);
    }
    contadorCorreos[correoBase]++;
    correoFinal += "@espe.edu.ec";

    return correoFinal;
}


/*template <typename T>
string GeneradorCorreos<T>::generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido) {
    string correoBase;
    stringstream ssPrimerNombre(primerNombre), ssSegundoNombre(segundoNombre);
    string palabra;

    // Obtener inicial del primer nombre
    while (ssPrimerNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break; 
        }
    }

    // Obtener inicial del segundo nombre
    while (ssSegundoNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break;
        }
    }

    // Procesar el apellido
    correoBase += procesarApellido(apellido);

    // Generar el correo final con índice
    string correoFinal = correoBase;
    if (contadorCorreos[correoBase] > 0) {
        correoFinal += to_string(contadorCorreos[correoBase]); // Agrega índice si ya existe
    }
    contadorCorreos[correoBase]++; // Incrementa el contador del correo base
    correoFinal += "@espe.edu.ec";

    return correoFinal;
}*/


template <typename T>
void GeneradorCorreos<T>::ingresarDatos() {
    Validaciones<string> valString;

    string primerNombre = valString.ingresar("\nIngrese el primer nombre (puede ser compuesto): ", "string");
    string segundoNombre = valString.ingresar("\nIngrese el segundo nombre (puede ser compuesto o vacio): ", "string");
    string apellidoCompuesto = valString.ingresar("\nIngrese el primer apellido: ", "string");
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
