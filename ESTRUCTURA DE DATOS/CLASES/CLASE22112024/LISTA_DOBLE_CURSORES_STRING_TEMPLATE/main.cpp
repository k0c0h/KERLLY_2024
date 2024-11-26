/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Dobles                                       *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "ListasDoble.cpp"
#include <stdlib.h>
#include "Validaciones.h"
#include "Menu.h"
#include "Nodo.cpp"
using namespace std;

int main()
{
    ListaDoble<std::string>* lista = new ListaDoble<std::string>();
    Validaciones<std::string> ingresar_string;
    Menu menu;
    int opcion;
    std::string dato;

    while(true){
        vector<string> opciones = {
            "      Insertar       ",
            "      Buscar         ",
            "      Eliminar       ",
            "      Mostrar        ",
            "      Salir          "
        };

        opcion = menu.mostrarMenu("======= Listas Dobles =============",opciones);
        system("cls");
        switch (opcion + 1)
        {
        case 1:
            dato = ingresar_string.ingresar("Ingrese el dato a insertar: ", "string");
            lista->Insertar(dato);
            break;
        case 2:
            dato = ingresar_string.ingresar("Ingrese el dato a buscar: ", "string");
            lista->Buscar(dato);
            break;
        case 3:
            dato = ingresar_string.ingresar("Ingrese el dato a eliminar: ", "string");
            lista->Eliminar(dato);
            break;
        case 4:
            lista->Mostrar();
            break;
        case 5:
            cout << "\nSaliendo del programa.\n";
            return 0;
        default:
            cout << "\nOpcion no valida.\n";
            break;
        }
        cout << "\nPresione Enter para continuar...";
        cin.get();

    } 

    delete lista;
    return 0;
}
// g++ ListasDoble.cpp Nodo.cpp main.cpp Menu.cpp -o main.exe