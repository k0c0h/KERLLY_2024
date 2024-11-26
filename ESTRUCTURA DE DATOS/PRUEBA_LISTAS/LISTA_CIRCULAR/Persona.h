#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string nombreCompleto;
    string apellido;
    int cedula;
    string direccion;
    int celular;

public:
    Persona(const string& nombreCompleto, const string& apellido, int cedula, const string& direccion, int celular);

    string getNombreCompleto() const;
    string getApellido() const;
    int getCedula() const;
    string getDireccion() const;
    int getCelular() const;

    void mostrarDatos() const;
};

#endif 
