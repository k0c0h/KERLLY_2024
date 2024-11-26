/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
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
#include "Persona.h"  
#include <algorithm>

using namespace std;

template <typename T>
class GeneradorCorreos
{
private:
    unordered_set<string> palabrasIgnoradas = {"de", "del", "la", "las", "los"};
    unordered_map<string, int> contadorCorreos;
    vector<string> correos;
    vector<Persona> personas;  // Almacenamos las personas

    char obtenerInicial(const string &palabra);
    string procesarApellido(const string &apellidoCompuesto);
    string generarCorreo(const string &primerNombre, const string &segundoNombre, const string &apellido);

public:
    void ingresarDatos();
    void mostrarPersonas() const;  // Método corregido
    void mostrarCorreos() const;
};

template <typename T>
char GeneradorCorreos<T>::obtenerInicial(const string &palabra)
{
    string palabraMinuscula = palabra;
    transform(palabraMinuscula.begin(), palabraMinuscula.end(), palabraMinuscula.begin(), ::tolower);

    if (palabrasIgnoradas.find(palabraMinuscula) == palabrasIgnoradas.end())
    {
        return tolower(palabra[0]);
    }
    return '\0';
}

template <typename T>
string GeneradorCorreos<T>::procesarApellido(const string &apellidoCompuesto)
{
    stringstream ss(apellidoCompuesto);
    string palabra, apellidoProcesado;

    while (ss >> palabra)
    {
        string palabraMinuscula = palabra;
        transform(palabraMinuscula.begin(), palabraMinuscula.end(), palabraMinuscula.begin(), ::tolower);

        if (palabrasIgnoradas.find(palabraMinuscula) == palabrasIgnoradas.end())
        {
            apellidoProcesado = palabra;
        }
    }

    if (!apellidoProcesado.empty())
    {
        apellidoProcesado[0] = tolower(apellidoProcesado[0]);
    }

    return apellidoProcesado;
}

template <typename T>
string GeneradorCorreos<T>::generarCorreo(const string &primerNombre, const string &segundoNombre, const string &apellido)
{
    string correoBase;
    stringstream ssPrimerNombre(primerNombre), ssSegundoNombre(segundoNombre);
    string palabra;

    while (ssPrimerNombre >> palabra)
    {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0')
        {
            correoBase += inicial;
            break;
        }
    }

    while (ssSegundoNombre >> palabra)
    {
        char inicial = obtenerInicial(palabra);
        if (inicial != '\0')
        {
            correoBase += inicial;
            break;
        }
    }
    correoBase += procesarApellido(apellido);

    string correoFinal = correoBase;
    if (contadorCorreos[correoBase] > 0)
    {
        correoFinal += to_string(contadorCorreos[correoBase]);
    }
    contadorCorreos[correoBase]++;
    correoFinal += "@espe.edu.ec";

    return correoFinal;
}

template <typename T>
void GeneradorCorreos<T>::ingresarDatos()
{
    Validaciones<string> valString;
    Validaciones<int> valInt;

    string primerNombre = valString.ingresar("\nIngrese el primer nombre: ", "string");
    string segundoNombre = valString.ingresar("\nIngrese el segundo nombre (puede ser compuesto o vacio): ", "string");
    string apellidoCompuesto = valString.ingresar("\nIngrese el primer apellido: ", "string");

    int cedula;
    do {
        cedula = valInt.ingresar("\nIngrese su numero de cedula: ", "entero");
        if (!valInt.validarCedula(cedula)) {
            cout << "\nCedula invalida. Por favor, ingrese una cedula valida de 10 digitos y cuyo primer digito este entre 1 y 24.\n";
        }
    } while (!valInt.validarCedula(cedula));  

    string direccion = valString.ingresar("\nIngrese su direccion: ", "string");

    int celular; 
    do {
        celular = valInt.ingresar("\nIngrese su numero de celular: ", "entero"); 
        if (!valInt.validarTelefono(celular)) {
            cout << "\nNumero de celular invalido. Debe ser un numero de 10 digitos.\n";
        }
    } while (!valInt.validarTelefono(celular)); 

    string nombreCompleto = primerNombre + " " + segundoNombre;
    personas.emplace_back(nombreCompleto, apellidoCompuesto, cedula, direccion, celular);  

    string correo = generarCorreo(primerNombre, segundoNombre, apellidoCompuesto);
    correos.push_back(correo);

    cout << "\nCorreo generado: " << correo << endl;
}

template <typename T>
void GeneradorCorreos<T>::mostrarPersonas() const
{
    if (personas.empty())
    {
        cout << "\nNo hay datos personales registrados.\n";
        return;
    }
    cout << "\nDatos personales registrados:\n";
    for (const auto &persona : personas)
    {
        persona.mostrarDatos();  
    }
}

template <typename T>
void GeneradorCorreos<T>::mostrarCorreos() const
{
    cout << "\nCorreos generados:\n";
    for (const auto &correo : correos)
    {
        cout << correo << endl;
    }
}
#endif

