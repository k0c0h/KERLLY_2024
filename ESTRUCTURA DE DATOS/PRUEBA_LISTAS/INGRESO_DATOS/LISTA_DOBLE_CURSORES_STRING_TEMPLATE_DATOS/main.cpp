/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Lista doble                                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              24/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/

#include "ListasDoble.cpp"
#include "Nodo.cpp"
#include "Validaciones.h"
#include "Menu.h"
#include <iostream>
#include "GeneradorCorreos.h"
#include "Persona.h"

using namespace std;

int main()
{
    ListaDoble<int> *lista_enteros = new ListaDoble<int>();
    ListaDoble<float> *lista_flotantes = new ListaDoble<float>();
    ListaDoble<double> *lista_dobles = new ListaDoble<double>();
    ListaDoble<std::string> *lista_strings = new ListaDoble<std::string>();
    ListaDoble<char> *lista_letras = new ListaDoble<char>();

    int opcion, dato_entero, dato, sub_opcion;
    float dato_flotante;
    double dato_doble;
    std::string dato_string;
    char dato_char;
    Menu menu;

    Validaciones<int> ingresar_entero;
    Validaciones<float> ingresar_flotante;
    Validaciones<double> ingresar_doble;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;

    GeneradorCorreos<string> *generador = new GeneradorCorreos<string>();

    while (true)
    {
        vector<string> opciones = {
            "  Ingresar datos y generar correo   ",
            "    Mostrar datos ingresados        ",
            "       Correos Generados            ",
            "            Salir                   "
        };
        opcion = menu.mostrarMenu("=========== Lista Doble ===========", opciones);
        system("cls");
        switch (opcion + 1)
        {
        case 1:
            generador->ingresarDatos();
            break;
        case 2:
            generador->mostrarPersonas();
            break;
        case 3:
            generador->mostrarCorreos();
            break;
        case 4:
            cout << "\nSaliendo del programa.\n";
            delete lista_enteros;
            delete lista_flotantes;
            delete lista_dobles;
            delete lista_strings;
            delete lista_letras;
            delete generador;
            return 0;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get();
    }
    return 0;
}
//g++ ListasDoble.cpp main.cpp Menu.cpp Nodo.cpp Persona.cpp -o main.exe