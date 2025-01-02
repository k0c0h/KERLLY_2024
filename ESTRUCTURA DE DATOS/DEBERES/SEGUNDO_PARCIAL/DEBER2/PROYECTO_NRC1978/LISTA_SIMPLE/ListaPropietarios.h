#pragma once
#include <iostream>
#include "Propietario.h"
#include "Nodo.h"

using namespace std;

class ListaPropietarios
{
private:
    Nodo<Propietario>* primero;
    Nodo<Propietario>* ultimo;

public:
    ListaPropietarios();
    ~ListaPropietarios();

    void agregarPropietario(const Propietario &propietario);
    Propietario* buscarPropietarioPorCedula(const string &cedula);
    void mostrarPropietarios() const;
    bool estaVacia() const;
    void cargarArchivo(const string &archivo); 
    void guardarArchivo(const string &archivo) const;
};
