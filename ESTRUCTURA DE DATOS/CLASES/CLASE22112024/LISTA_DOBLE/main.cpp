/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "ListasDoble.h"
#include <stdlib.h>
#include "Validaciones.h"
using namespace std;

int main(){
    ListaDoble *lista = new ListaDoble();
    Validaciones<int> ingresar_Entero;
    int opcion, dato;

    do
    {
        system("cls");
        cout << "======= Listas Dobles =============" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        cout << "===================================" << endl;
        opcion = ingresar_Entero.ingresar("Ingrese una opcion: ", "entero");

        system("cls");
        switch (opcion)
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
        }
        system("pause");
    } while (opcion != 5);
    
    delete lista;

    return 0;
}
//g++ ListasDoble.cpp Nodo.cpp main.cpp -o main.exe