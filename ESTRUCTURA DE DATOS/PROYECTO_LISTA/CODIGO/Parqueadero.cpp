#include "Parqueadero.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream> // Asegúrate de incluir esta cabecera
#include <limits>
#include "RegistroHistorial.h"
#include <random>
#include <iomanip> // Para formato
#include <list>

using namespace std;

// Constructor
Parqueadero::Parqueadero(int totalEspacios, const std::string &rutaPropietarios, const std::string &rutaAutosPermitidos)
{
    for (int i = 1; i <= totalEspacios; ++i)
    {
        espacios.emplace_back(std::make_unique<EspacioParqueadero>(i));
    }

    cargarPropietarios(rutaPropietarios);
    cargarAutosPermitidos(rutaAutosPermitidos);
    std::cout << "Los espacios 1 a 4 están reservados para personas con discapacidad.\n";
}

void Parqueadero::mostrarEstadoCircular() const
{
    const std::string verde = "\033[32m"; // Vacío
    const std::string rojo = "\033[31m";  // Ocupado
    const std::string azul = "\033[34m";  // Reservado para discapacitados
    const std::string reset = "\033[0m";  // Restaurar color

    int totalEspacios = espacios.size();
    int espaciosPorFila = 10; // Máximo de espacios en la fila superior o inferior
    int espaciosLaterales = (totalEspacios - 2 * espaciosPorFila) / 2;

    auto it = espacios.begin();

    // Fila superior
    std::cout << " ";
    for (int i = 0; i < espaciosPorFila; ++i, ++it)
    {
        if (i < 4) // Primeros cuatro reservados para discapacitados
        {
            std::cout << azul;
        }
        else if ((*it)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << "+---+ ";
    }
    std::cout << reset << "\n ";

    // IDs de la fila superior
    it = espacios.begin();
    for (int i = 0; i < espaciosPorFila; ++i, ++it)
    {
        if (i < 4)
        {
            std::cout << azul;
        }
        else if ((*it)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << "| " << std::setw(2) << (*it)->getId() << "| ";
    }
    std::cout << reset << "\n ";

    for (int i = 0; i < espaciosPorFila; ++i)
    {
        std::cout << "+---+ ";
    }
    std::cout << reset << "\n";

    // Laterales
    auto itIzq = it; // Iterador para los laterales izquierdos
    auto itDer = it;
    std::advance(itDer, espaciosLaterales); // Avanza al lado derecho

    for (int i = 0; i < espaciosLaterales; ++i)
    {
        // Lado izquierdo
        if ((*itIzq)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << "| " << std::setw(2) << (*itIzq)->getId() << "| ";
        ++itIzq;

        std::cout << "                                     "; // Espaciado central

        // Lado derecho
        if ((*itDer)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << "| " << std::setw(2) << (*itDer)->getId() << "|\n";
        ++itDer;
    }

    // Fila inferior
    for (int i = 0; i < espaciosPorFila; ++i)
    {
        if ((*it)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << " +---+";
        ++it;
    }
    std::cout << reset << "\n ";

    it = espacios.end();
    std::advance(it, -espaciosPorFila); // Avanza a la fila inferior

    for (int i = 0; i < espaciosPorFila; ++i)
    {
        if ((*it)->estaOcupado())
        {
            std::cout << rojo;
        }
        else
        {
            std::cout << verde;
        }
        std::cout << "| " << std::setw(2) << (*it)->getId() << "| ";
        ++it;
    }
    std::cout << reset << "\n ";

    for (int i = 0; i < espaciosPorFila; ++i)
    {
        std::cout << "+---+ ";
    }
    std::cout << reset << "\n";
}

// Método para estacionar un auto
void Parqueadero::estacionarAuto(Auto *autoEstacionado, Propietario *propietario, const std::string &tarjeta, int espacioID)
{
    // Buscar el auto en la lista de autos permitidos
    auto itAuto = std::find_if(autosPermitidos.begin(), autosPermitidos.end(),
                               [&autoEstacionado](const Auto &a)
                               { return a.getPlaca() == autoEstacionado->getPlaca(); });

    if (itAuto == autosPermitidos.end())
    {
        std::cerr << "\nEl auto no esta permitido para estacionarse.\n";
        return;
    }

    // Verificar si el auto tiene estado "Dentro del parqueadero"
    std::string estadoActual = itAuto->getEstado();
    estadoActual.erase(remove_if(estadoActual.begin(), estadoActual.end(), [](unsigned char c)
                                 { return std::isspace(c); }),
                       estadoActual.end());

    if (estadoActual != "Dentrodelparqueadero")
    {
        std::cerr << "\nEl auto no tiene acceso para estacionarse. Primero debe ingresar al parqueadero.\n";
        return;
    }

    // Convertir espacioID en iterador
    auto espacioIt = std::next(espacios.begin(), espacioID - 1);
    if (espacioIt == espacios.end())
    {
        std::cerr << "Espacio invalido.\n";
        return;
    }

    auto &espacio = *espacioIt;

    // Verificar si el espacio está ocupado
    if (espacio->estaOcupado())
    {
        std::cerr << "El espacio " << espacioID << " ya esta ocupado.\n";
        return;
    }

    // Verificar si la tarjeta es válida
    auto tarjetaIt = tarjetasParqueo.find(autoEstacionado->getPlaca());
    if (tarjetaIt == tarjetasParqueo.end() || tarjetaIt->second != tarjeta)
    {
        std::cerr << "Numero de tarjeta invalido para el auto con placa " << autoEstacionado->getPlaca() << ".\n";
        return;
    }

    // Estacionar el auto
    espacio->ocuparEspacio(autoEstacionado, propietario);
    actualizarEstadoAuto(autoEstacionado->getPlaca(), "Estacionado");
    std::cout << "Auto estacionado en espacio " << espacioID << ".\n";
}

// Método para retirar un auto
void Parqueadero::retirarAuto(const std::string &placa)
{
    auto it = std::find_if(autosPermitidos.begin(), autosPermitidos.end(),
                           [&placa](const Auto &a)
                           { return a.getPlaca() == placa; });

    if (it == autosPermitidos.end())
    {
        std::cerr << "\nNo se encontró un auto con la placa " << placa << " en el parqueadero.\n";
        return;
    }

    // Iterar sobre la lista de espacios
    for (auto &espacio : espacios)
    {
        if (espacio->estaOcupado() && espacio->getAuto()->getPlaca() == placa)
        {
            espacio->liberarEspacio();
            actualizarEstadoAuto(placa, "No se encuentra en el parqueadero");
            std::cout << "\nAuto con placa " << placa << " retirado del parqueadero.\n";
            return;
        }
    }

    std::cerr << "\nEl auto con placa " << placa << " no está estacionado.\n";
}

// Mostrar el estado de los espacios del parqueadero
void Parqueadero::mostrarEstado() const
{
    for (const auto &espacio : espacios)
    {
        cout << espacio->obtenerEstado() << '\n';
    }
}

std::string Parqueadero::generarTarjetaParqueo()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999);
    return std::to_string(dis(gen));
}

// Registrar un auto permitido
void Parqueadero::registrarAutoPermitido(const Auto &autoPermitido)
{
    auto it = std::find_if(autosPermitidos.begin(), autosPermitidos.end(),
                           [&autoPermitido](const Auto &a)
                           { return a.getPlaca() == autoPermitido.getPlaca(); });

    if (it == autosPermitidos.end())
    {
        autosPermitidos.push_back(autoPermitido);
        std::string tarjeta = generarTarjetaParqueo();
        tarjetasParqueo[autoPermitido.getPlaca()] = tarjeta;
        std::cout << "\nAuto con placa " << autoPermitido.getPlaca()
                  << " registrado con tarjeta: " << tarjeta << "\n";
    }
    else
    {
        std::cerr << "\nEl auto con placa " << autoPermitido.getPlaca() << " ya esta registrado.\n";
    }
}

// Eliminar un auto permitido
void Parqueadero::eliminarAutoPermitido(const std::string &placa)
{
    auto it = std::find_if(autosPermitidos.begin(), autosPermitidos.end(),
                           [&placa](const Auto &a)
                           { return a.getPlaca() == placa; });

    if (it != autosPermitidos.end())
    {
        autosPermitidos.erase(it);
        cout << "\nAuto con placa " << placa << " eliminado correctamente.\n";
    }
    else
    {
        cerr << "\nEl auto con placa " << placa << " no esta en la lista de permitidos.\n";
    }
}

// Guardar lista de autos permitidos en archivo
void Parqueadero::guardarAutosPermitidos(const std::string &rutaArchivo)
{
    std::ofstream archivo(rutaArchivo);
    if (!archivo)
    {
        std::cerr << "\nNo se pudo abrir el archivo para escritura.\n";
        return;
    }

    for (const auto &autoPermitido : autosPermitidos)
    {
        archivo << "  - " << autoPermitido.getPlaca() << " "
                << autoPermitido.getMarca() << " "
                << autoPermitido.getColor() << " "
                << tarjetasParqueo[autoPermitido.getPlaca()] << " "
                << autoPermitido.getEstado() << '\n';
    }
    archivo.close();
}

// Guardar información de propietarios en archivo
void Parqueadero::guardarPropietarios(const std::string &rutaArchivo)
{
    std::ofstream archivo(rutaArchivo);
    if (!archivo)
    {
        std::cerr << "\nNo se pudo abrir el archivo para guardar propietarios: " << rutaArchivo << std::endl;
        return;
    }

    for (const auto &propietario : propietarios)
    {
        archivo << propietario.getNombreCompleto() << ","
                << propietario.getCedula() << ","
                << propietario.getCorreo() << ","
                << (propietario.getEsDiscapacitado() ? "1" : "0") << '\n';

        for (const auto &autoAsociado : propietario.getAutos())
        {
            archivo << "  " << autoAsociado.getPlaca() << " "
                    << autoAsociado.getMarca() << " "
                    << autoAsociado.getColor() << " "
                    << tarjetasParqueo[autoAsociado.getPlaca()] << '\n';
        }
    }
    archivo.close();
}

void Parqueadero::eliminarPropietario(const std::string &cedula)
{
    // Buscar al propietario en la lista
    auto it = std::find_if(propietarios.begin(), propietarios.end(),
                           [&cedula](const Propietario &p)
                           { return p.getCedula() == cedula; });

    if (it != propietarios.end())
    {
        // Obtener los autos asociados al propietario
        const auto &autosAsociados = it->getAutos();

        // Eliminar los autos asociados del archivo y la lista de autos permitidos
        for (const auto &autoAsociado : autosAsociados)
        {
            auto itAuto = std::find_if(autosPermitidos.begin(), autosPermitidos.end(),
                                       [&autoAsociado](const Auto &a)
                                       { return a.getPlaca() == autoAsociado.getPlaca(); });

            if (itAuto != autosPermitidos.end())
            {
                autosPermitidos.erase(itAuto);
            }
        }

        // Eliminar el propietario de la lista
        propietarios.erase(it);
        cout << "\nPropietario con cedula " << cedula << " eliminado correctamente.\n";

        // Guardar los cambios en los archivos
        guardarPropietarios("propietarios.txt");
        guardarAutosPermitidos("autos.txt");
    }
    else
    {
        cerr << "\nNo se encontro un propietario con la cedula " << cedula << ".\n";
    }
}

// Cargar lista de autos permitidos desde archivo
void Parqueadero::cargarAutosPermitidos(const std::string &rutaArchivo)
{
    std::ifstream archivo(rutaArchivo);
    if (!archivo)
    {
        std::cerr << "\nNo se pudo abrir el archivo de autos permitidos.\n";
        return;
    }

    std::string linea;
    while (getline(archivo, linea))
    {
        // Ignorar líneas en blanco
        if (linea.empty())
            continue;

        // Eliminar espacios iniciales
        linea.erase(0, linea.find_first_not_of(' '));

        // Verificar si la línea comienza con un guion
        if (!linea.empty() && linea[0] == '-')
        {
            // Eliminar el guion y los espacios que lo rodean
            linea = linea.substr(1);                      // Eliminar el guion
            linea.erase(0, linea.find_first_not_of(' ')); // Eliminar espacio después del guion

            // Procesar el contenido de la línea
            std::istringstream stream(linea);
            std::string placa, marca, tarjeta, estado;

            stream >> placa >> marca >> tarjeta; // Leer placa, marca y tarjeta
            getline(stream, estado);             // Leer el resto como estado

            // Quitar espacios iniciales y finales del estado
            estado.erase(0, estado.find_first_not_of(' '));
            estado.erase(estado.find_last_not_of(' ') + 1);

            // Si no hay un estado definido, asignar el predeterminado
            if (estado.empty())
            {
                estado = "No se encuentra en el parqueadero";
            }

            // Almacenar los datos en las estructuras correspondientes
            autosPermitidos.emplace_back(placa, marca, tarjeta, estado);
            tarjetasParqueo[placa] = tarjeta;
        }
    }

    archivo.close();
}

// Cargar información de propietarios desde archivo
void Parqueadero::cargarPropietarios(const std::string &rutaArchivo)
{
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        std::cerr << "\nNo se pudo abrir el archivo de propietarios: " << rutaArchivo << std::endl;
        return;
    }

    propietarios.clear();
    std::string linea;

    while (getline(archivo, linea))
    {
        // Verificar si la línea no está vacía
        if (linea.empty())
            continue;

        std::istringstream streamPropietario(linea);
        std::string nombreCompleto, cedula, correo;
        bool esDiscapacitado;

        // Leer los datos del propietario
        getline(streamPropietario, nombreCompleto, ',');
        getline(streamPropietario, cedula, ',');
        getline(streamPropietario, correo, ',');
        streamPropietario >> esDiscapacitado;

        Propietario propietario(nombreCompleto, cedula, correo, esDiscapacitado);

        // Leer los autos asociados
        while (getline(archivo, linea))
        {
            // Si la línea comienza con un espacio, es un auto asociado
            if (!linea.empty() && linea[0] == ' ')
            {
                // Eliminar el espacio inicial (si tiene dos espacios) y el guion
                std::string autoInfo = linea.substr(2); // Elimina los dos primeros caracteres (espacio y guion)
                std::istringstream streamAuto(autoInfo);

                std::string placa, marca, color, tarjeta, estado;

                // Leer la línea completa del auto
                streamAuto >> placa >> marca >> color >> tarjeta >> estado;

                // Crear el auto
                Auto autoAsociado(placa, marca, color, estado);

                // Asociar la tarjeta con la placa
                tarjetasParqueo[placa] = tarjeta;

                // Agregar el auto al propietario
                propietario.agregarAuto(autoAsociado);
            }
            else
            {
                // Si encontramos una línea sin espacio, significa que hemos llegado al siguiente propietario
                archivo.seekg(-static_cast<int>(linea.size()) - 1, std::ios::cur);
                break;
            }
        }

        // Agregar el propietario a la lista
        propietarios.push_back(propietario);
    }

    archivo.close();
    std::cout << "\nPropietarios cargados correctamente desde " << rutaArchivo << ".\n";
}

void Parqueadero::guardarTarjetas(const std::string &rutaArchivo)
{
    std::ofstream archivo(rutaArchivo);
    for (const auto &par : tarjetasParqueo)
    {
        archivo << par.first << " " << par.second << "\n";
    }
}

void Parqueadero::cargarTarjetas(const std::string &rutaArchivo)
{
    std::ifstream archivo(rutaArchivo);
    std::string placa, tarjeta;
    while (archivo >> placa >> tarjeta)
    {
        tarjetasParqueo[placa] = tarjeta;
    }
}

void Parqueadero::actualizarEstadoAuto(const std::string &placa, const std::string &estado)
{
    for (auto &autoPermitido : autosPermitidos)
    {
        if (autoPermitido.getPlaca() == placa)
        {
            autoPermitido.setEstado(estado);
            guardarAutosPermitidos("autos.txt"); // Guardar automáticamente al archivo
            guardarPropietarios("propietarios.txt");
            std::cout << "\nEstado del auto con placa " << placa << " actualizado a: " << estado << ".\n";
            return;
        }
    }
    std::cerr << "\nNo se pudo actualizar el estado. Auto con placa " << placa << " no encontrado.\n";
}

const std::vector<Auto> &Parqueadero::getAutosPermitidos() const
{
    return autosPermitidos;
}

const std::vector<Propietario> &Parqueadero::getPropietarios() const
{
    return propietarios;
}

void Parqueadero::agregarPropietario(const Propietario &nuevoPropietario)
{
    propietarios.push_back(nuevoPropietario);
}

std::unordered_map<std::string, std::string> &Parqueadero::getTarjetasParqueo()
{
    return tarjetasParqueo; // Asumiendo que tienes tarjetasParqueo como un atributo miembro
}

// g++ main.cpp EspacioParqueadero.cpp Parqueadero.cpp Propietario.cpp Auto.cpp Menu.cpp RegistroHistorial.cpp -o main.exe