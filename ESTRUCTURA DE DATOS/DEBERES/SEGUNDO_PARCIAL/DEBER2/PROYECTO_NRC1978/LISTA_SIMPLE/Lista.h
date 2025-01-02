#pragma once
#include "Nodo.h"
#include <string>
using namespace std;

template <typename T>
class ListaSimple {
private:
    Nodo<T>* primero; // Solo necesitamos un puntero al primer nodo

public:
    ListaSimple();

    Nodo<T>* getPrimero() {
        return primero;
    }

    void insertar(T dato, const std::string& nombreArchivo);
    void buscarPorPlaca(string placa);
    void BusquedaAvanzada(const std::string& criterio, const std::string& valorInicio, const std::string& valorFin);
    void eliminarPorPlaca(string placa);
    void mostrar(Nodo<T>* aux);
    void CargarArchivo(string nombreArchivo);
    void GuardarArchivo(string nombreArchivo);
    void salirDelParqueadero(const std::string& placa);

    static std::string cifrarTexto(const std::string& texto);
    static std::string descifrarTexto(const std::string& texto);
};

#include "Lista.cpp"
