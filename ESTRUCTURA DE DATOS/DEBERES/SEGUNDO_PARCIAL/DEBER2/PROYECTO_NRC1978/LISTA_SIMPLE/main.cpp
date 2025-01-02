#include <iostream>
#include "Menu.h"

int main()
{
    ListaPropietarios listaPropietarios;
    listaPropietarios.cargarArchivo("propietarios.txt");
    ListaSimple<Coche> listaCochesHistorial;
    listaCochesHistorial.CargarArchivo("autos_historial.txt");

    ListaSimple<Coche> listaCoches;
    listaCoches.CargarArchivo("autos.txt");

    menu(listaCoches, listaCochesHistorial, listaPropietarios);

    return 0;
}