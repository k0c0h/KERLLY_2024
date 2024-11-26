#include "Lista.h"
#include "Ingresar.h"
#include "Buscar.h"
#include "Imprimir.h"
#include "Eliminar.h"
#include "InputValidator.h" 
#include <iostream>
#include <limits> 

int main() {
    Lista<int> lista;
    Ingresar<int> ingresar;
    Buscar<int> buscar;
    Imprimir<int> imprimir;
    Eliminar<int> eliminar;
    InputValidator validator;

    int opcion = 0;
    int valor;
    bool desdeFrente;
    bool entradaValida;

    while (true) {
        std::cout << "======== Menu de opciones: ======\n";
        std::cout << "1. Insertar un elemento\n";
        std::cout << "2. Eliminar un elemento\n";
        std::cout << "3. Buscar un elemento\n";
        std::cout << "4. Imprimir la lista\n";
        std::cout << "5. Salir\n";
        std::cout << "==================================\n";
        std::cout << "Seleccione una opcion (1-5): ";
        
        opcion = validator.ingresarEntero(""); 

        switch (opcion) {
            case 1: 
                std::cout << "\nIngrese el valor a ingresar: ";
                valor = validator.ingresarEntero(""); 
                ingresar.realizarOperacion(lista, valor);
                break;
            
            case 2: 
                entradaValida = false;
                while (!entradaValida) {
                    std::cout << "\nDesea eliminar desde el frente (1) o desde atras (0)? ";
                    desdeFrente = validator.ingresarEntero("");
        
                    if (desdeFrente != 0 && desdeFrente != 1) {
                        std::cout << "\nEntrada no válida. Por favor ingrese 1 para frente o 0 para atras.\n";
                    } else {
                        entradaValida = true;
                        eliminar.realizarOperacion(lista, desdeFrente);  
                    }
                }
                break;


            case 3:
                std::cout << "\nIngrese el valor a buscar: ";
                valor = validator.ingresarEntero(""); 
                buscar.realizarOperacion(lista, valor);
                break;

            case 4:
                std::cout << "\nLista actual: ";
                imprimir.realizarOperacion(lista);
                break;

            case 5: 
                std::cout << "\nSaliendo del programa...\n";
                return 0;

            default:
                std::cout << "\nOpcion no valida. Intente de nuevo.\n";
                break;
        }

        std::cout << "\n";
    }

    return 0;
}
//g++ -o lista main.cpp Buscar.cpp Eliminar.cpp Imprimir.cpp InputValidator.cpp
