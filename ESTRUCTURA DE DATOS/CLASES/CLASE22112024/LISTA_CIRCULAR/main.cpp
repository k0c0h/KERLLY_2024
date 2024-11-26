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
#include <stdlib.h>
using namespace std;

bool esEntero(string);

int main() {
    ListaCircular* lista = new ListaCircular();
    Validaciones<int> ingresar_Entero;
    int opcion, dato;


    do {
        system("cls");
        cout << "========== Listas Circulares ==========" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        cout << "======================================="<<endl;
        opcion = ingresar_Entero.ingresar("Ingrese una opcion: ", "entero");

        system("cls");
        switch (opcion) {
        case 1:
            dato = ingresar_Entero.ingresar("Ingrese el dato a insertar: ","entero");
            lista->Insertar(dato);
            break;
        case 2:
            dato = ingresar_Entero.ingresar("Ingrese el dato a buscar: ", "entero");
            lista->Buscar(dato);
            break;
        case 3:
            dato = ingresar_Entero.ingresar("Ingresar el dato a eliminar: ", "entero");
            lista->Eliminar(dato);
            break;
        case 4:
            lista->Mostrar();
            break;
        case 5:
            cout <<"\nSaliendo del programa.\n";
            return 0;
        }
        cout<<"\nPresione Enter para continuar...";
        cin.get();

    } while (opcion != 5);
    delete lista;
    return 0;
}

//g++ ListasCirculares.cpp Nodo.cpp main.cpp -o main.exe