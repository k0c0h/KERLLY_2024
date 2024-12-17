#include "Lista.h"
#include "Ingresar.h"
#include "Buscar.h"
#include "Imprimir.h"
#include "Eliminar.h"

int main() {
    Lista<int> lista;

    Ingresar<int> ingresar;
    Buscar<int> buscar;
    Imprimir<int> imprimir;
    Eliminar<int> eliminar;

    // Insertar elementos
    ingresar.realizarOperacion(lista, 10);
    ingresar.realizarOperacion(lista, 20);
    ingresar.realizarOperacion(lista, 30);
    ingresar.realizarOperacion(lista, 40);

    // Imprimir después de inserciones
    std::cout << "Lista después de inserciones: ";
    imprimir.realizarOperacion(lista);

    // Buscar elementos
    buscar.realizarOperacion(lista, 20);
    buscar.realizarOperacion(lista, 50);

    // Eliminar elementos
    eliminar.realizarOperacion(lista, true);  // Eliminar desde el frente
    eliminar.realizarOperacion(lista, false); // Eliminar desde atrás

    // Imprimir después de eliminaciones
    std::cout << "Lista después de eliminaciones: ";
    imprimir.realizarOperacion(lista);

    // Ejecutar otras operaciones de lista
    lista.ejecutarOperaciones();

    return 0;
}
