#include "Persona.h"
#include <iostream>

using namespace std;

Persona::Persona(const string& nombreCompleto, const string& apellido, int cedula, const string& direccion, int celular)
    : nombreCompleto(nombreCompleto), apellido(apellido), cedula(cedula), direccion(direccion), celular(celular) {}

string Persona::getNombreCompleto() const { return nombreCompleto; }
string Persona::getApellido() const { return apellido; }
int Persona::getCedula() const { return cedula; }
string Persona::getDireccion() const { return direccion; }

void Persona::mostrarDatos() const {
    cout << "Nombre: " << nombreCompleto << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Celular: " << celular << endl;
    cout << "-----------------------------------\n";
}
