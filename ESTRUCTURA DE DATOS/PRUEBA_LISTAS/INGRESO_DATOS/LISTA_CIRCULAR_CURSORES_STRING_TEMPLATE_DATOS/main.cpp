/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                  Lista circular                                          *
 * Autor:                      Kerlly Chiriboga                                        *
 * Fecha de creacion:          24/11/2024                                              *
 * Fecha de modificacion:      24/11/2024                                              *
 * Materia:                    Estructura de datos                                     *
 * NRC :                       1978                                                    *
 ***************************************************************************************/

#include "ListasCirculares.cpp"
#include "Nodo.cpp"
#include "Validaciones.h"
#include "Menu.h"
#include <iostream>
#include "GeneradorCorreos.h"
#include "Persona.h"

using namespace std;

int main()
{
    ListaCircular<int> *lista_enteros = new ListaCircular<int>();
    ListaCircular<float> *lista_flotantes = new ListaCircular<float>();
    ListaCircular<double> *lista_dobles = new ListaCircular<double>();
    ListaCircular<std::string> *lista_strings = new ListaCircular<std::string>();
    ListaCircular<char> *lista_letras = new ListaCircular<char>();

    int opcion, dato_entero, sub_opcion;
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
        opcion = menu.mostrarMenu("=========== Lista Circular ===========", opciones);
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
//g++ ListasCirculares.cpp main.cpp Nodo.cpp Menu.cpp Persona.cpp -o main.exe