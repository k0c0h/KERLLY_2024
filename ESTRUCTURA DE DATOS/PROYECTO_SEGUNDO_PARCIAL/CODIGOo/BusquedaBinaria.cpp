#include <iostream>
#include <list>
#include <string>
#include <functional>
#include "Registro.h"
#include "Auto.h"
#include "BusquedaBinaria.h"

// Función de búsqueda binaria para encontrar el primer registro con el prefijo dado
std::list<Registro>::const_iterator BusquedaBinaria::buscarPrimerRegistroConPrefijo(
    const std::list<Registro>& registros, const std::string& prefijo)
{

    auto inicio = registros.begin();
    auto fin = registros.end();

    while (inicio != fin)
    {
        auto medio = std::next(inicio, std::distance(inicio, fin) / 2);

        // Si el auto en el medio tiene un prefijo que coincide
        if (medio->getAutoPermitido().getPlaca().find(prefijo) == 0)
        {
            fin = medio; // Encontramos un auto con el prefijo, sigamos buscando en la izquierda
        }
        else if (medio->getAutoPermitido().getPlaca() < prefijo)
        {
            inicio = std::next(medio);
        }
        else
        {
            fin = medio;
        }
    }

    return inicio; // Si no lo encuentra, retorna fin
}

// Función de búsqueda binaria para encontrar el último registro con el prefijo dado
std::list<Registro>::const_iterator BusquedaBinaria::buscarUltimoRegistroConPrefijo(
    const std::list<Registro>& registros, const std::string& prefijo)
{

    auto inicio = registros.begin();
    auto fin = registros.end();

    while (inicio != fin)
    {
        auto medio = std::next(inicio, std::distance(inicio, fin) / 2);

        // Si el auto en el medio tiene un prefijo que coincide
        if (medio->getAutoPermitido().getPlaca().find(prefijo) == 0)
        {
            inicio = std::next(medio); // Encontramos un auto con el prefijo, sigamos buscando en la derecha
        }
        else if (medio->getAutoPermitido().getPlaca() < prefijo)
        {
            inicio = std::next(medio);
        }
        else
        {
            fin = medio;
        }
    }

    return inicio; // Si no lo encuentra, retorna fin
}

// Función para mostrar todos los registros con el prefijo dado
void BusquedaBinaria::mostrarRegistros(const std::list<Registro>& registros, const std::string& prefijo)
{
    auto inicio = buscarPrimerRegistroConPrefijo(registros, prefijo);
    auto fin = buscarUltimoRegistroConPrefijo(registros, prefijo);

    if (inicio == registros.end() || fin == registros.end())
    {
        std::cout << "No se encontraron registros con el prefijo " << prefijo << std::endl;
    }
    else
    {
        for (auto it = inicio; it != fin; ++it)
        {
            if (it->getAutoPermitido().getPlaca().find(prefijo) == 0)
            {
                std::cout << "Auto con placa: " << it->getAutoPermitido().getPlaca() << ", Marca: "<< it->getAutoPermitido().getMarca()<< ", Color: "<<it->getAutoPermitido().getColor()<<endl;
            }
        }
    }
}
