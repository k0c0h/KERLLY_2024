/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Dobles                                       *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "ListasDoble.h"
#include <stdlib.h>
#include "Validaciones.h"
#include "Menu.h"
using namespace std;

int main()
{
    ListaDoble *lista = new ListaDoble();
    Validaciones<int> ingresar_Entero;
    Menu menu;
    int opcion, dato;

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
            dato = ingresar_Entero.ingresar("Ingrese el dato a insertar: ", "entero");
            lista->Insertar(dato);
            break;
        case 2:
            dato = ingresar_Entero.ingresar("Ingrese el dato a buscar: ", "entero");
            lista->Buscar(dato);
            break;
        case 3:
            dato = ingresar_Entero.ingresar("Ingrese el dato a eliminar: ", "entero");
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