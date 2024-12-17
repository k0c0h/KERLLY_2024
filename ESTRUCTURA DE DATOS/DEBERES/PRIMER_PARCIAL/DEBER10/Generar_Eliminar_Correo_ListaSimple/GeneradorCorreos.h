/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/


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
    vector<string> nombresYApellidos;

    char obtenerInicial(const string& palabra);
    string procesarApellido(const string& apellidoCompuesto);
    string generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido);

public:
    void ingresarDatos();
    void mostrarCorreos() const;
    void eliminarLetra();
    void mostrarListaAuxiliar() const;
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
            apellidoProcesado = palabra; 
        }
    }

    if (!apellidoProcesado.empty()) {
        apellidoProcesado[0] = tolower(apellidoProcesado[0]); 
    }

    return apellidoProcesado;
}

template <typename T>
string GeneradorCorreos<T>::generarCorreo(const string& primerNombre, const string& segundoNombre, const string& apellido) {
    string correoBase;
    stringstream ssPrimerNombre(primerNombre), ssSegundoNombre(segundoNombre);
    string palabra;

    while (ssPrimerNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break;
        }
    }

    while (ssSegundoNombre >> palabra) {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0') {
            correoBase += inicial;
            break;
        }
    }
    correoBase += procesarApellido(apellido);

    string correoFinal = correoBase;
    if (contadorCorreos[correoBase] > 0) {
        correoFinal += to_string(contadorCorreos[correoBase]);
    }
    contadorCorreos[correoBase]++;
    correoFinal += "@espe.edu.ec";

    return correoFinal;
}

template <typename T>
void GeneradorCorreos<T>::ingresarDatos() {
    Validaciones<string> valString;

    string primerNombre = valString.ingresar("\nIngrese el primer nombre: ", "string");
    string segundoNombre = valString.ingresar("\nIngrese el segundo nombre (puede ser compuesto o vacio): ", "string");
    string apellidoCompuesto = valString.ingresar("\nIngrese el primer apellido: ", "string");
    
    nombresYApellidos.push_back(primerNombre);
    if (!segundoNombre.empty()) {
        nombresYApellidos.push_back(segundoNombre);
    }
    nombresYApellidos.push_back(apellidoCompuesto);
    
    string correo = generarCorreo(primerNombre, segundoNombre, apellidoCompuesto);
    correos.push_back(correo);

    cout << "\nCorreo generado: " << correo << endl;
}

template <typename T>
void GeneradorCorreos<T>::eliminarLetra() {
    Validaciones<char> ingresarLetra;
    char letraEliminar = ingresarLetra.ingresar("Ingrese la letra que desea eliminar: ", "char");

    letraEliminar = tolower(letraEliminar);

    for (auto& nombreApellido : nombresYApellidos) {
        nombreApellido.erase(remove_if(nombreApellido.begin(), nombreApellido.end(), [letraEliminar](char c) { 
            return tolower(c) == letraEliminar; }),nombreApellido.end());
    }

    cout << "\nLista con la letra eliminada: \n";
    for (const auto& nombre : nombresYApellidos) {
        cout << nombre << endl;
    }
}

template <typename T>
void GeneradorCorreos<T>::mostrarListaAuxiliar() const {
    cout << "\nLista de nombres y apellidos modificada:\n";
    for (const auto& nombre : nombresYApellidos) {
        cout << nombre << endl;
    }
}

template <typename T>
void GeneradorCorreos<T>::mostrarCorreos() const {
    cout << "\nCorreos generados:\n";
    for (const auto& correo : correos) {
        cout << correo << endl;
    }
}



#endif
