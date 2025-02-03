/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto Primer Parcial                             *
 * Autor:                          Kerlly Chiriboga,Heidy Mera                         *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          06/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "Menu.h"
#include "Validaciones.h"
#include <iostream>
#include "HistorialEstacionamiento.h"
#include "Ordenamientos.h"
#include <conio.h>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include "BusquedaBinaria.h"
#include "ArbolRN.h"

using namespace std;
// Constructor: Inicializa el menú con las opciones disponibles
Menu::Menu(Parqueadero *p, HistorialEstacionamiento *h, AutosPermitidos *a)
    : parqueadero(p), historial(h), autosPermitidos(a), seleccionActual(0)
{
    opciones = {
        "Mostrar estado del parqueadero",
        "Estacionar un auto",
        "Retirar un auto",
        "Registrar auto permitido",
        "Eliminar auto permitido",
        "Mostrar autos permitidos",
        "Imprimir arbol",
        "Mostrar Recorridos",
        "Opciones de Busqueda",
        "Ordenar autos permitidos",
        "Mostrar propietarios",
        "Mostrar historial de estacionamientos",
        "Salir"};
}

// Mostrar el menú principal
void Menu::mostrarMenu()
{
    system("cls");
    cout << "Sistema de Gestion de Parqueadero\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < opciones.size(); i++)
    {
        if (i == seleccionActual)
        {
            cout << " > " << opciones[i] << " <\n"; // Opción seleccionada
        }
        else
        {
            cout << "   " << opciones[i] << "\n"; // Opción no seleccionada
        }
    }
}

// Ejecutar la opción seleccionada
void Menu::ejecutarOpcion()
{
    system("cls");
    switch (seleccionActual)
    {
    case 0:
        parqueadero->mostrarEstado();
        break;
    case 1:
    {
        string placa, espacioId;
        Validaciones<string> validador;

        // Ingresar y validar la placa
        placa = validador.ingresarPlaca("Ingresa la placa del auto a estacionar (sin guiones): ");
        cout << endl;

        // Verificar si el auto está permitido
        if (!autosPermitidos->buscarAuto(placa))
        {
            cout << "El auto no esta permitido. Registrelo primero.\n";
            break;
        }

        // Mostrar estado actual del parqueadero
        parqueadero->mostrarEstado();

        // Estacionamiento automático
        espacioId = ""; // Forzar asignación aleatoria

        // Intentar estacionar el auto
        if (parqueadero->estacionarAuto(placa, espacioId))
        {
            historial->registrarEntrada(placa, espacioId); // Registrar la entrada con el espacio asignado
        }
        break;
    }
    case 2:
    { // Retirar auto
        string placa;
        Validaciones<string> validador;

        placa = validador.ingresarPlaca("Ingrese la placa del auto a retirar (sin guiones): ");

        // `retirarAuto` ya registra la salida en el historial
        parqueadero->retirarAuto(placa);

        break;
    }
    case 3:
    {
        string placa, marca, color, nombre, cedula, correo;
        Validaciones<string> validador;
        placa = validador.ingresarPlaca("Ingrese la placa del auto(sin guiones): ");
        cout << endl;
        marca = validador.ingresar("Ingrese la marca del auto: ", "string");
        cout << endl;
        color = validador.ingresar("Ingrese el color: ", "string");
        cout << endl;
        nombre = validador.ingresar("Ingrese el nombre del propietario: ", "string");
        cout << endl;
        cedula = validador.ingresarCedula("Ingrese la cedula del propietario: ");
        cout << endl;
        correo = validador.ingresarCorreo("Ingrese el correo del propietario: ");
        cout << endl;
        Auto autoObj(placa, marca, color);
        Propietario propietario(nombre, cedula, correo);
        autosPermitidos->agregarAuto(autoObj, propietario);
        break;
    }
    case 4:
    {
        string placa;
        Validaciones<string> validador;
        placa = validador.ingresarPlaca("Ingrese la placa del auto a eliminar(sin guiones): ");
        cout << endl;
        autosPermitidos->eliminarAuto(placa);
        if (parqueadero->retirarAuto(placa))
        {
            historial->registrarSalida(placa);
        }
        break;
    }
    case 5:
        autosPermitidos->mostrarAutos();
        break;
    case 6:
    {
        historial->imprimirArbol();
        break;
    }
    case 7:
    {
        historial->mostrarRecorridos();
        break;
    }
    case 8:
        submenuBusquedas();
        break;
    case 9: // Agregar caso para ordenar los autos permitidos
        mostrarMenuOrdenamiento(autosPermitidos->getRegistros());
        break;
    case 10:
        autosPermitidos->mostrarPropietarios();
        break;
    case 11:
        mostrarSubmenuHistorial();
        break;
    case 12:
        cout << "Saliendo del programa...\n";
        exit(0);
    default:
        cout << "Opcion no valida.\n";
        break;
    }
    system("pause");
}

// Mostrar submenú de autos permitidos
void Menu::submenuBusquedas()
{
    vector<string> opcionesAutos = {
        "Buscar auto por placa",
        "Buscar autos permitidos por prefijo de placa",  // Opción nueva
        "Buscar el primer ingreso por fecha especifica", // Opción nueva
        "Buscar autos por rango de fechas",              // Opción nueva
        "Buscar autos en un espacio por rango de fechas",
        "Buscar autos por duracion de estacionamiento en una fecha",
        "Buscar espacio mas y menos ocupado por numero de veces",
        "Buscar espacio mas y menos ocupado por duracion",
        "Regresar al menu principal"};

    int seleccionSubmenu = 0;

    while (true)
    {
        system("cls");
        cout << "   Opciones de Busqueda      \n";
        cout << "-----------------------------\n";

        for (int i = 0; i < opcionesAutos.size(); i++)
        {
            if (i == seleccionSubmenu)
            {
                cout << " > " << opcionesAutos[i] << " <\n";
            }
            else
            {
                cout << "   " << opcionesAutos[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72)
        { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesAutos.size()) % opcionesAutos.size();
        }
        else if (tecla == 80)
        { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesAutos.size();
        }
        else if (tecla == '\r')
        { // Enter
            system("cls");
            if (seleccionSubmenu == 0)
            {
                // Opción: Buscar auto por placa
                string placa;
                Validaciones<string> validador;
                placa = validador.ingresarPlaca("Ingrese la placa del auto(sin guiones): ");
                cout << endl;

                if (autosPermitidos->buscarAuto(placa))
                {
                    autosPermitidos->mostrarAutoPorPlaca(placa); // Mostrar detalles del auto
                }
                else
                {
                    cout << "El auto con placa " << placa << " no esta permitido.\n";
                }
            }
            else if (seleccionSubmenu == 1)
            {
                // Opción: Buscar autos por prefijo de placa
                string prefijo;
                Validaciones<string> validador;
                prefijo = validador.ingresarPrefijo("Ingrese el prefijo de la placa(Ejem: XYZ): ");
                cout << endl;
                // Usar la clase BusquedaBinaria para encontrar los autos con el prefijo
                BusquedaBinaria::mostrarRegistros(autosPermitidos->getRegistros(), prefijo);
            }
            else if (seleccionSubmenu == 2)
            {
                // Opción: Buscar el primer ingreso por fecha específica
                string fecha;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha de busqueda (YYYY-MM-DD): ");
                cout << endl;

                // Llamar al método de HistorialEstacionamiento para mostrar el primer ingreso
                historial->mostrarPrimerIngresoPorFecha(fecha);
            }
            else if (seleccionSubmenu == 3)
            {
                // Opción: Buscar autos por rango de fechas
                string fechaInicio, fechaFin;
                Validaciones<string> validador;
                fechaInicio = validador.ingresarFecha("Ingrese la fecha de inicio (YYYY-MM-DD): ");
                cout << endl;
                fechaFin = validador.ingresarFecha("Ingrese la fecha de fin (YYYY-MM-DD): ");
                cout << endl;

                // Llamar al método de HistorialEstacionamiento para mostrar autos en el rango de fechas
                historial->mostrarAutosPorRangoFechas(fechaInicio, fechaFin);
            }
            else if (seleccionSubmenu == 4)
            {
                string espacioId, fechaInicio, fechaFin;
                Validaciones<string> validador;
                espacioId = validador.ingresarEspacioId("Ingrese el ID del espacio: ");
                cout << endl;
                fechaInicio = validador.ingresarFecha("Ingrese la fecha de inicio (YYYY-MM-DD): ");
                cout << endl;
                fechaFin = validador.ingresarFecha("Ingrese la fecha de fin (YYYY-MM-DD): ");
                cout << endl;
                historial->buscarAutosEnEspacioPorRangoFechas(espacioId, fechaInicio, fechaFin);
            }
            else if (seleccionSubmenu == 5)
            { // Buscar por duración
                string fecha, duracionMin, duracionMax;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha de busqueda (YYYY-MM-DD): ");
                cout << endl;
                duracionMin = validador.ingresarDuracion("Ingrese la duracion minima (HH:MM): ");
                cout << endl;
                duracionMax = validador.ingresarDuracion("Ingrese la duracion maxima en (HH:MM): ");
                cout << endl;
                historial->mostrarAutosPorDuracionEnFecha(fecha, duracionMin, duracionMax);
            }
            else if (seleccionSubmenu == 6) { // Buscar espacio más y menos ocupado
                historial->mostrarEspacioMasMenosOcupado();
            } 
            else if (seleccionSubmenu == 7) { // Buscar espacio con mayor y menor tiempo de uso
                historial->mostrarEspacioMasMenosTiempoOcupado();
            }
            else if (seleccionSubmenu == 8)
            {
                // Opción: Regresar al menú principal
                break;
            }

            system("pause");
        }
    }
}

// Mostrar submenú del historial
void Menu::mostrarSubmenuHistorial()
{
    vector<string> opcionesHistorial = {
        "Mostrar historial por fecha",
        "Mostrar historial por fecha y placa",
        "Mostrar historial por rango de hora",
        "Regresar al menu principal"};
    int seleccionSubmenu = 0;

    while (true)
    {
        system("cls");
        cout << "Opciones de Historial\n";
        cout << "-----------------------\n";

        for (int i = 0; i < opcionesHistorial.size(); i++)
        {
            if (i == seleccionSubmenu)
            {
                cout << " > " << opcionesHistorial[i] << " <\n";
            }
            else
            {
                cout << "   " << opcionesHistorial[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72)
        { // Flecha arriba
            seleccionSubmenu = (seleccionSubmenu - 1 + opcionesHistorial.size()) % opcionesHistorial.size();
        }
        else if (tecla == 80)
        { // Flecha abajo
            seleccionSubmenu = (seleccionSubmenu + 1) % opcionesHistorial.size();
        }
        else if (tecla == '\r')
        { // Enter
            system("cls");
            if (seleccionSubmenu == 0)
            {
                string fecha;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha (YYYY-MM-DD): ");
                cout << endl;
                historial->mostrarHistorialPorFecha(fecha);
                cout << endl;
            }
            else if (seleccionSubmenu == 1)
            {
                string fecha, placa;
                Validaciones<string> validador;
                fecha = validador.ingresarFecha("Ingrese la fecha (YYYY-MM-DD): ");
                cout << endl;
                placa = validador.ingresarPlaca("Ingrese la placa (sin guiones): ");
                cout << endl;
                historial->mostrarHistorialPorFechaYPlaca(fecha, placa);
            }
            else if (seleccionSubmenu == 2)
            {
                string horaInicio, horaFin;
                Validaciones<string> validador;
                horaInicio = validador.ingresarHora("Ingrese la hora de inicio (HH:MM:SS): ");
                cout << endl;
                horaFin = validador.ingresarHora("Ingrese la hora de fin (HH:MM:SS): ");
                cout << endl;
                historial->mostrarHistorialPorRangoHoras(horaInicio, horaFin);
                cout << endl;
            }
            else if (seleccionSubmenu == 3)
            {
                break; // Regresar al menú principal
            }
            system("pause");
        }
    }
}

void Menu::mostrarMenuOrdenamiento(std::list<Registro> &registros) // Modificado
{
    std::vector<std::string> opcionesOrdenamiento = {
        "Shell Sort",
        "Bubble Sort",
        "Quick Sort",
        "Radix Sort",
        "Bucket Sort",
        "Heap Sort",
        "Salir"};
    int seleccionMenu = 0;

    while (true)
    {
        system("cls");
        std::cout << "Opciones de Ordenamiento\n";
        std::cout << "--------------------------\n";

        for (int i = 0; i < opcionesOrdenamiento.size(); i++)
        {
            if (i == seleccionMenu)
            {
                std::cout << " > " << opcionesOrdenamiento[i] << " <\n";
            }
            else
            {
                std::cout << "   " << opcionesOrdenamiento[i] << "\n";
            }
        }

        char tecla = _getch();
        if (tecla == 72)
        { // Flecha arriba
            seleccionMenu = (seleccionMenu - 1 + opcionesOrdenamiento.size()) % opcionesOrdenamiento.size();
        }
        else if (tecla == 80)
        { // Flecha abajo
            seleccionMenu = (seleccionMenu + 1) % opcionesOrdenamiento.size();
        }
        else if (tecla == '\r')
        { // Enter
            system("cls");
            if (seleccionMenu == 0)
            {
                std::cout << "Ejecutando Shell Sort...\n";
                // Usando un comparador (por ejemplo, por placa en orden ascendente)
                Ordenamientos::shellSort(registros, [](const Auto &a, const Auto &b)
                                         { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_ShellSort.txt");
            }
            else if (seleccionMenu == 1)
            {
                std::cout << "Ejecutando Bubble Sort...\n";
                Ordenamientos::bubbleSort(registros, [](const Auto &a, const Auto &b)
                                          { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_BubbleSort.txt");
            }
            else if (seleccionMenu == 2)
            {
                std::cout << "Ejecutando Quick Sort...\n";
                // Usando un comparador (por ejemplo, por placa en orden ascendente)
                Ordenamientos::quickSort(registros, [](const Auto &a, const Auto &b)
                                         { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_QuickSort.txt");
            }
            else if (seleccionMenu == 3)
            {
                std::cout << "Ejecutando Radix Sort...\n";
                Ordenamientos::radixSort(registros, [](const Auto &a, const Auto &b)
                                         { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_RadixSort.txt");
            }
            else if (seleccionMenu == 4)
            {
                std::cout << "Ejecutando Bucket Sort...\n";
                Ordenamientos::bucketSort(registros, [](const Auto &a, const Auto &b)
                                          { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_BucketSort.txt");
            }
            else if (seleccionMenu == 5)
            {
                std::cout << "Ejecutando Heap Sort...\n";
                Ordenamientos::heapSort(registros, [](const Auto &a, const Auto &b)
                                        { return a.placa < b.placa; });
                Ordenamientos::guardarEnArchivo(registros, "autos_ordenados_HeapSort.txt");
            }
            else if (seleccionMenu == 6)
            {
                break; // Salir del menú
            }
            std::cout << "Ordenamiento completado.\n";
            system("pause");
        }
    }
}

// Iniciar el menú interactivo
void Menu::iniciar()
{
    while (true)
    {
        mostrarMenu();
        char tecla = _getch();
        if (tecla == 72)
        { // Flecha arriba
            seleccionActual = (seleccionActual - 1 + opciones.size()) % opciones.size();
        }
        else if (tecla == 80)
        { // Flecha abajo
            seleccionActual = (seleccionActual + 1) % opciones.size();
        }
        else if (tecla == '\r')
        { // Enter
            ejecutarOpcion();
        }
        else if (tecla == 59)
        { // F1 (en ASCII extendido)
            mostrarGuiaRapida();
        }
    }
}

void Menu::mostrarGuiaRapida()
{
    vector<string> paginas = {
        "Guia Rapida - Pagina 1\n"
        "----------------------------\n"
        "- Consultar Estado del Parqueadero\n"
        "  - Usa 'Mostrar estado del parqueadero' para visualizar"
        "   graficamente los espacios ocupados o libres\n\n"
        "- Estacionar un Auto\n"
        "  - Auto debe estar registrado previamente.\n"
        "  - Selecciona un espacio disponible.\n\n"
        "Usa las flechas para pasar a la siguiente pagina, ESC para salir.\n",

        "Guia Rapida - Pagina 2\n"
        "----------------------------\n"
        "- Retirar un Auto\n"
        "  - Ingresa la placa del auto.\n"
        "  - Se liberara el espacio ocupado.\n\n"
        "- Registrar Autos Permitidos\n"
        "  - Agrega autos con placa, marca y datos del Propietario.\n\n"
        "Usa las flechas para pasar a la siguiente pagina o para regresar, ESC para salir.\n",

        "Guia Rapida - Pagina 3 y ultima\n"
        "--------------------------------\n"
        "- Eliminar Autos Permitidos\n"
        "  - Elimina autos que ya no necesitan acceso.\n\n"
        "- Visualizar Historial\n"
        "  - Consulta entradas y salidas por placa o fecha\n"
        "  - Mostrar historiales de acuerdo a varios atributos.\n\n"
        "- Navegacion del Menu\n"
        "  - Usa las flechas para moverte por todas las opciones.\n\n"
        "Usa las flechas para regresar, ESC para salir.\n"};

    int paginaActual = 0;

    while (true)
    {
        system("cls");
        cout << paginas[paginaActual];

        char tecla = _getch();
        if (tecla == 27)
        { // Tecla ESC para salir
            break;
        }
        else if (tecla == 75 && paginaActual > 0)
        { // Flecha izquierda (cÃ³digo ASCII 75)
            paginaActual--;
        }
        else if (tecla == 77 && paginaActual < paginas.size() - 1)
        { // Flecha derecha (cÃ³digo ASCII 77)
            paginaActual++;
        }
    }

    system("cls"); // Limpiar pantalla antes de regresar al menÃº principal
}

void Menu::ordenarAutosPermitidos()
{
    // Llamamos al método de ordenar de la clase AutosPermitidos
    autosPermitidos->ordenarAutos(); // Suponiendo que 'ordenarAutos' está implementado en AutosPermitidos
    cout << "Autos permitidos ordenados correctamente." << endl;
}
