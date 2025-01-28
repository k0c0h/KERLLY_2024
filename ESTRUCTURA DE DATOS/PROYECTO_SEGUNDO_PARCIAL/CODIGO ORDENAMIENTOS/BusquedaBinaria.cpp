#include <iostream>
#include <list>
#include <string>
#include <functional>

class BusquedaBinaria {
public:
    // Función de búsqueda binaria para encontrar el primer auto con el prefijo dado
    static std::list<Auto>::iterator buscarPrimerAutoConPrefijo(
        std::list<Auto>& autos, const std::string& prefijo) {

        auto inicio = autos.begin();
        auto fin = autos.end();

        while (inicio != fin) {
            auto medio = std::next(inicio, std::distance(inicio, fin) / 2);

            // Si el auto en el medio tiene un prefijo que coincide
            if (medio->getPlaca().find(prefijo) == 0) {
                fin = medio;  // Encontramos un auto con el prefijo, sigamos buscando en la izquierda
            } else if (medio->getPlaca() < prefijo) {
                inicio = std::next(medio);
            } else {
                fin = medio;
            }
        }

        return inicio;  // Si no lo encuentra, retorna fin
    }

    // Función de búsqueda binaria para encontrar el último auto con el prefijo dado
    static std::list<Auto>::iterator buscarUltimoAutoConPrefijo(
        std::list<Auto>& autos, const std::string& prefijo) {

        auto inicio = autos.begin();
        auto fin = autos.end();

        while (inicio != fin) {
            auto medio = std::next(inicio, std::distance(inicio, fin) / 2);

            // Si el auto en el medio tiene un prefijo que coincide
            if (medio->getPlaca().find(prefijo) == 0) {
                inicio = std::next(medio);  // Encontramos un auto con el prefijo, sigamos buscando en la derecha
            } else if (medio->getPlaca() < prefijo) {
                inicio = std::next(medio);
            } else {
                fin = medio;
            }
        }

        return inicio;  // Si no lo encuentra, retorna fin
    }

    // Función para mostrar todos los autos con el prefijo dado
    static void mostrarAutos(const std::list<Auto>& autos, const std::string& prefijo) {
        auto inicio = buscarPrimerAutoConPrefijo(autos, prefijo);
        auto fin = buscarUltimoAutoConPrefijo(autos, prefijo);

        if (inicio == autos.end() || fin == autos.end()) {
            std::cout << "No se encontraron autos con el prefijo " << prefijo << std::endl;
        } else {
            for (auto it = inicio; it != fin; ++it) {
                if (it->getPlaca().find(prefijo) == 0) {
                    std::cout << "Auto con placa: " << it->getPlaca() << std::endl;
                }
            }
        }
    }
};