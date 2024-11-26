/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/

#include "Menu.h"
#include "GeneradorCorreos.h"
#include "Validaciones.h"
#include <iostream>

using namespace std;

int main() {
    GeneradorCorreos<string>* generador = new GeneradorCorreos<string>();
    Menu menu;
    Validaciones<int> ingresar_entero;

    while (true) {
        vector<string> opciones = {
            "Ingresar datos y generar correo",
            "Mostrar correos generados",
            "Salir"
        };

        int opcion = menu.mostrarMenu("======== Menu de opciones: =========", opciones);

        system("cls");
        switch (opcion) {
        case 0:
            generador->ingresarDatos();
            break;
        case 1: 
            generador->mostrarCorreos();
            break;
        case 2:
            cout << "\nSaliendo del programa.\n";
            return 0;
        default:
            cout << "\nOpcion no valida.\n";
            break;
        }

        cout << "Presione Enter para continuar...";
        cin.get();
    }
    delete generador;
    return 0;
}
//g++ main.cpp GeneradorCorreos.cpp ListaSimple.cpp Menu.cpp -o main.exe