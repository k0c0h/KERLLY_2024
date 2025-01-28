#include "RedBlackTree.cpp"
#include <conio.h>  // Para _getch()
#include <iostream>

void menu()
{
    RedBlackTree<int> tree;
    int element;
    int option = 1;  // Comenzamos en la opción 1
    const int maxOption = 6;
    char key;

    while (true)
    {
        system("cls");
        std::cout << "Seleccione una opcion:\n";

        // Mostrar las opciones y resaltar la seleccionada
        for (int i = 1; i <= maxOption; i++)
        {
            if (i == option)
                std::cout << "> ";  // Marca la opción seleccionada
            else
                std::cout << "  ";

            // Imprimir las opciones del menú
            if (i == 1) std::cout << "1. Insertar elemento\n";
            else if (i == 2) std::cout << "2. Eliminar elemento\n";
            else if (i == 3) std::cout << "3. Buscar elemento\n";
            else if (i == 4) std::cout << "4. Mostrar arbol\n";
            else if (i == 5) std::cout << "5. Mostrar recorridos\n";
            else std::cout << "6. Salir\n";
        }

        key = _getch();  // Captura tecla

        // Manejo de teclas
        if (key == 72)  // Flecha arriba
        {
            option--;
            if (option < 1) option = maxOption;
        }
        else if (key == 80)  // Flecha abajo
        {
            option++;
            if (option > maxOption) option = 1;
        }
        else if (key == 13)  // Enter
        {
            system("cls");
            switch (option)
            {
            case 1:
            {
                char option;
                do
                {
                    system("cls");
                    std::cout << "Arbol actual:\n";
                    tree.showTree();
                    std::cout << "\nIngrese un numero para agregar al arbol: ";
                    std::cin >> element;
                    tree.insert(element);
                    std::cout << "\nDesea agregar otro numero? (s/n): ";
                    std::cin >> option;
                } while (option == 's' || option == 'S');
                system("cls");
                std::cout << "Arbol actual:\n";
                tree.showTree();
                break;
            }
            case 2:
                std::cout << "Ingrese un elemento a eliminar: ";
                std::cin >> element;
                tree.remove(element);
                break;
            case 3:
                std::cout << "Ingrese un elemento a buscar: ";
                std::cin >> element;
                tree.searchAndShow(element);
                break;
            case 4:
                std::cout << "Arbol Rojo-Negro:\n";
                tree.showTree();
                break;
            case 5:
                tree.showTraversals();
                break;
            case 6:
                return;
            default:
                std::cout << "Opcion invalida.\n";
            }
            system("pause");
        }
    }
}

int main()
{
    menu();
    return 0;
}
