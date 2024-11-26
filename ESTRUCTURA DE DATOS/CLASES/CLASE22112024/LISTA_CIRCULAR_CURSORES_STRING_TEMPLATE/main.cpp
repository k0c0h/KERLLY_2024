/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Circulares                                   *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          25/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "ListasCirculares.cpp"
#include "Validaciones.h"
#include "Menu.h"
#include "Nodo.cpp"
#include <stdlib.h>

using namespace std;

int main() {
    ListaCircular<std::string>* lista = new ListaCircular<std::string>();
    Validaciones<std::string> ingresar_string;
    Menu menu;
    int opcion;
    std::string dato;

    while(true){
        vector<string>opciones = {
            "Insertar",
            "Buscar  ",
            "Eliminar",
            "Mostrar ",
            "Salir   "
        };

        opcion = menu.mostrarMenu("========== Listas Circulares ==========",opciones);
        system("cls");
        switch (opcion + 1) {
        case 1:
            dato = ingresar_string.ingresar("Ingrese el dato a insertar: ","string");
            lista->Insertar(dato);
            break;
        case 2:
            dato = ingresar_string.ingresar("Ingrese el dato a buscar: ", "string");
            lista->Buscar(dato);
            break;
        case 3:
            dato = ingresar_string.ingresar("Ingresar el dato a eliminar: ", "string");
            lista->Eliminar(dato);
            break;
        case 4:
            lista->Mostrar();
            break;
        case 5:
            cout <<"\nSaliendo del programa.\n";
            return 0;
        }
        cout <<"\nPresione Enter para continuar...";
        cin.get();

    } 
    delete lista;
    return 0;
}

//g++ ListasCirculares.cpp Nodo.cpp main.cpp Menu.cpp -o main.exe