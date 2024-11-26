/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "GeneradorCorreos.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

int main()
{
    GeneradorCorreos<string>* generador = new GeneradorCorreos<string>();
    Validaciones<int> ingresar_entero;
    int opcion;

    do
    {
        system("cls");
        cout << "\n======== Menu de opciones:=============\n";
        cout << "1. Ingresar datos y generar correo\n";
        cout << "2. Mostrar correos generados\n";
        cout << "3. Salir\n";
        cout << "=======================================\n";
        opcion = ingresar_entero.ingresar("Ingrese una de las opciones: \n", "entero");

        system("cls");
        switch (opcion)
        {
        case 1:
            generador->ingresarDatos();
            break;
        case 2:
            generador->mostrarCorreos();
            break;
        case 3:
            cout << "\nSaliendo del programa.\n";
            break;
        default:
            cout << "\nOpcion no valida.\n";
            break;
        }

        if (opcion != 3)
        {
            cout << "Presione Enter para continuar...";
            cin.get();
        }
    } while (opcion != 3);
    delete generador;

    return 0;
}
// g++ main.cpp GeneradorCorreos.cpp ListaSimple.cpp -o main.exe
