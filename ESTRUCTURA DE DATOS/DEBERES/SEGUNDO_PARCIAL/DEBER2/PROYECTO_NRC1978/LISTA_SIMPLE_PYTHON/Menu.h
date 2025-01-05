#pragma once
#include <iostream>
#include <vector>
#include "Lista.h"
#include "ListaPropietarios.h"

using namespace std;

// Función principal del menú
void menu(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial, ListaPropietarios &listaPropietarios);

// Función para menús interactivos
int menuInteractivo(const vector<string> &opciones, const string &titulo = "Menu Interactivo");

// Menú de búsqueda avanzada
void menuBusquedaAvanzada(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial);

// Menú de ordenamiento
void menuOrdenar(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial);
