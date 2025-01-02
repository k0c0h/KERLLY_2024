#pragma once
#include "Nodo.h"
#include <string>
using namespace std;

template <typename T>
class ListaDoble {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;

public:
    ListaDoble();

    Nodo<T>* getPrimero() {
        return primero;
    }

    void insertar(T dato, const std::string& nombreArchivo);
    void buscarPorPlaca(string placa);
    void BusquedaAvanzada(string criterio, string valorInicio, string valorFin);
    void eliminarPorPlaca(string placa);
    void mostrar(Nodo<T>* aux);
    void CargarArchivo(string nombreArchivo);
    void GuardarArchivo(string nombreArchivo);
    void salirDelParqueadero(const std::string& placa);

    static std::string cifrarTexto(const std::string& texto);
    static std::string descifrarTexto(const std::string& texto);
};

#include "Lista.cpp"
