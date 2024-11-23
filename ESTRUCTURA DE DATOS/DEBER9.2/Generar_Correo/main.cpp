#include "GeneradorCorreos.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;

int main()
{
    GeneradorCorreos<string> generador;
    Validaciones<int> ingresar_entero;
    int opcion;

    do
    {
        cout << "\nMenu de opciones:\n";
        cout << "1. Ingresar datos y generar correo\n";
        cout << "2. Mostrar correos generados\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        opcion = ingresar_entero.ingresar("Opcion: ", "entero");

        switch (opcion)
        {
        case 1:
            generador.ingresarDatos();
            break;
        case 2:
            generador.mostrarCorreos();
            break;
        case 3:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}
// g++ main.cpp GeneradorCorreos.cpp ListaSimple.cpp  -o programa
