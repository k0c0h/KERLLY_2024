#include "ListasDoble.h"    
#include "Nodo.h"         
#include "Validaciones.h"   
#include "Menu.h"           
#include <iostream>
#include "GeneradorCorreos.h" 
#include "Persona.h"          

using namespace std;

int main() {
    ListaDoble *lista_enteros = new ListaDoble();
    ListaDoble *lista_flotantes = new ListaDoble();
    ListaDoble *lista_dobles = new ListaDoble();
    ListaDoble *lista_strings = new ListaDoble();
    ListaDoble *lista_letras = new ListaDoble();

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

    while (true) {
        vector<string> opciones = {
            "  Ingresar datos y generar correo   ",
            "    Mostrar datos ingresados        ",
            "       Correos Generados            ",
            "            Salir                   "
        };
        opcion = menu.mostrarMenu("=========== Lista Doble ===========", opciones);
        system("cls");

        switch (opcion + 1) {
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
                return 0;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get(); 
    }

    delete generador; 
    return 0;
}
//g++ ListasDoble.cpp Menu.cpp Persona.cpp Nodo.cpp main.cpp -o main.exe