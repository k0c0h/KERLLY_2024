/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "GeneradorCorreos.h"
#include "Validaciones.h"
#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    GeneradorCorreos<string>* generador = new GeneradorCorreos<string>();
    Validaciones<int> ingresar_entero;
    Menu menu;
    int opcion;

    while(true){
        vector<string> opciones = {
            "Ingresar datos y generar correo",
            "Mostrar correos generados",
            "Eliminar letra de nombres y apellidos",
            "Mostrar lista despues de eliminar letra",
            "Salir"
        };

        opcion = menu.mostrarMenu("======== Menu de opciones ===============", opciones);
        system("cls");
        switch (opcion + 1)
        {
        case 1:
            generador->ingresarDatos();
            break;
        case 2:
            generador->mostrarCorreos();
            break;
        case 3:
            generador->eliminarLetra();
            break;
        case 4:
            generador->mostrarListaAuxiliar();
            break;
        case 5:
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
// g++ main.cpp GeneradorCorreos.cpp ListaSimple.cpp Menu.cpp -o main.exe
