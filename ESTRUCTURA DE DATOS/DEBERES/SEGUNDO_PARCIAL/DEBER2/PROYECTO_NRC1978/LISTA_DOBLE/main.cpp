#include <iostream>
#include "Menu.h"

int main()
{
    ListaPropietarios listaPropietarios;
    listaPropietarios.cargarArchivo("propietarios.txt");
    ListaDoble<Coche> listaCochesHistorial;
    listaCochesHistorial.CargarArchivo("autos_historial.txt");

    ListaDoble<Coche> listaCoches;
    listaCoches.CargarArchivo("autos.txt");

    menu(listaCoches, listaCochesHistorial, listaPropietarios);

    return 0;
}