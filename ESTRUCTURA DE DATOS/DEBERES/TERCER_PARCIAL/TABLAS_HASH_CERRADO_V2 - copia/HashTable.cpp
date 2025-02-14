#include "HashTable.h"
#include <bitset>
#include <algorithm>
#include <iostream> // Para imprimir en consola
#include <iomanip>  // Para formato de salida
#include <thread>   // Para sleep_for
#include <chrono>   // Para milisegundos

template <typename T>
HashTable<T>::HashTable(int size) : size(size), window(sf::VideoMode(800, 600), "Hash Table Visualization")
{
    table.resize(size);
    foundIndex = -1; // Inicializa como -1 (no encontrado)
}

template <typename T>
int HashTable<T>::hashFunction(int key)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return 0; // Cierra la ventana y detiene la ejecución de la función
        }
    }
    return key % size;
}

// Genera un número primo menor que n
int getPrime(int n) {
    while (n > 1) {
        bool isPrime = true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return n;
        n--;
    }
    return 2; // Si todo falla, devuelve 2
}

template <typename T>
int HashTable<T>::hashFunction2(const T& key) {
    int keyValue = 0;
    if constexpr (std::is_same<T, std::string>::value) {
        keyValue = hashString(key);  // Usar hashFunction en lugar de hashString
    } else {
        keyValue = key;  // Para enteros, se usa directamente
    }
    return 7 - (keyValue % 7);  // Fórmula de segundo hash
}

template <typename T>
int HashTable<T>::hashFunction(const std::string &key)
{
    int index = hashString(key) % size; // Convertimos la cadena en número y aplicamos módulo

    // Permitir que la ventana siga respondiendo mientras se realizan las operaciones
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return 0; // Cierra la ventana y detiene la ejecución de la función
        }
    }

    return index;
}

template <typename T>
std::string HashTable<T>::sumaBinaria(const std::string &a, const std::string &b)
{
    std::string resultado = "";
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (j >= 0) ? b[j] - '0' : 0;

        int suma = bitA + bitB + carry;
        resultado += (suma % 2) + '0';
        carry = suma / 2;

        i--;
        j--;
    }

    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}

template <typename T>
int HashTable<T>::hashString(const std::string &clave)
{
    unsigned int hash = 0;
    std::string claveInvertida = clave;
    std::reverse(claveInvertida.begin(), claveInvertida.end());

    std::cout << "\n---- Calculando Hash para \"" << clave << "\" ----\n";
    std::cout << "Cadena invertida: " << claveInvertida << "\n\n";

    for (size_t index = 0; index < claveInvertida.length(); ++index)
    {
        // Permite que la ventana siga respondiendo mientras se realizan las operaciones
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        char c = claveInvertida[index];
        unsigned int valor = static_cast<unsigned int>(c);

        std::string binHash = std::bitset<32>(hash).to_string();
        std::string binValor = std::bitset<32>(valor).to_string();
        std::string binSuma = sumaBinaria(binHash, binValor);

        std::cout << "\nIteracion " << index + 1 << ":\n";
        std::cout << "  Letra: '" << c << "' (ASCII: " << valor << ")\n";
        std::cout << "  binHash:   " << binHash << "\n";
        std::cout << "  binValor:  " << binValor << "\n";
        std::cout << "  binSuma:   " << binSuma << " (suma binaria)\n";

        if (index < claveInvertida.length() - 1)
        {
            std::string primeros4 = binSuma.substr(0, 4);
            for (int i = 11; i <= 14; i++)
            {
                binSuma[i] = (binSuma[i] == primeros4[i - 11]) ? '0' : '1';
            }
            binSuma = binSuma.substr(4) + "0000";
            std::cout << "  binModificado: " << binSuma << " (ajuste de bits)\n";
        }

        if (binSuma.length() == 32)
        {
            hash = std::bitset<32>(binSuma).to_ulong();
        }
        else
        {
            std::cerr << "\nError: binSuma no tiene 32 bits." << std::endl;
            return 0;
        }

        std::cout << " \n Nuevo hash: " << hash << " (" << std::bitset<32>(hash) << " en binario)\n";
        std::cout << "--------------------------------------------\n";

        // **Pausa para ver la operación**
        std::cout << "Presiona ENTER para continuar...\n";
        std::cin.get();
    }

    int hashFinal = hash % size;
    std::cout << "Hash final: " << hash << " % " << size << " = " << hashFinal << "\n";
    std::cout << "---- Celda asignada: " << hashFinal << " ----\n\n";

    return hashFinal;
}

template <typename T>
void HashTable<T>::insert(T key, int method)
{
    int index = hashFunction(key);  // Calcular el índice con la función de hash
    int i = 0;  // Contador de probing
    bool inserted = false;  // Flag para verificar si se insertó

    while (!inserted)
    {
        // Evitar el bucle infinito si la tabla está llena
        if (i >= size) { 
            std::cerr << "Tabla llena, no se pudo insertar " << key << "\n";
            return;
        }

        int probeIndex;
        
        if (method == 1)  // Linear Probing
        {
            probeIndex = (index + i) % size;  // Mover linealmente
        }
        else if (method == 2)  // Quadratic Probing
        {
            probeIndex = (index + i * i) % size;  // Fórmula cuadrática
        }
        else  // Double Hashing
        {
            int secondHash = hashFunction2(key);  // Segunda función hash
            probeIndex = (index + (i * secondHash)) % size;  // Usamos la segunda función de hash
        }

        if (!table[probeIndex].has_value())  
        {
            table[probeIndex] = key;  // Inserta el valor
            inserted = true;  // Marcamos como insertado
        }
        else 
        {
            // Si la celda está ocupada con el mismo valor
            if (table[probeIndex].value() == key)  
            {
                i++;  
            }
            else  
            {
                i++;  
            }
        }
    }

    drawTable();  // Redibuja la tabla después de la inserción
}

template <typename T>
bool HashTable<T>::search(T key)
{
    int index = hashFunction(key);
    int i = 0;
    sf::Clock clock;  // Inicializamos el reloj para la animación

    while (table[(index + i) % size].has_value())
    {
        if (table[(index + i) % size] == key)
        {
            foundIndex = (index + i) % size;
            foundKey = key;

            // Animación sin bloquear el bucle
            while (clock.getElapsedTime().asSeconds() < 1.0f)
            {
                sf::Event event;
                while (window.pollEvent(event)) // Procesar eventos
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        return false; // Esto solo es válido si search() devuelve `bool`
                    }
                }

                drawTable();  // Redibujar la tabla con la celda resaltada
                sf::sleep(sf::milliseconds(100));  // Hacer una pequeña pausa para la animación
            }

            resetHighlight();  // Resetear el color de la celda después de la animación
            return true;
        }

        i++;  // Continuar buscando en el siguiente índice
    }

    resetHighlight();  // Si no encontramos el valor, resetear el color de la celda
    return false;
}

template <typename T>
void HashTable<T>::resetHighlight()
{
    foundIndex = -1;
    foundKey = T();
}

template <typename T>
void HashTable<T>::remove(T key, int method)
{
    int index = hashFunction(key);
    int i = 0;

    // Recorremos las celdas para encontrar el elemento
    while (table[(index + i) % size].has_value())
    {
        // Si encontramos el valor, lo eliminamos
        if (table[(index + i) % size].value() == key)
        {
            table[(index + i) % size] = std::nullopt;  // Elimina el valor
            std::cout << "\nElemento eliminado " << key << std::endl;
            drawTable();  // Dibuja la tabla después de eliminar
            return;  // Salimos de la función después de eliminar
        }
        i++;  // Incrementamos para buscar en la siguiente celda
    }

    // Si llegamos aquí, significa que no encontramos el elemento
    std::cout << "\nEl elemento no se encuentra en la tabla." << std::endl;
}

template <typename T>
void HashTable<T>::display()
{
    for (int i = 0; i < size; i++)
    {
        if (!table[i].has_value())
            std::cout << "[ ] ";
        else
            std::cout << "[" << table[i].value() << "] ";
    }
    std::cout << std::endl;
    drawTable();
}

template <typename T>
void HashTable<T>::drawTable()
{
    window.clear(sf::Color::White); // Limpia la ventana
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    int cellWidth = 60, cellHeight = 40;
    for (int i = 0; i < size; i++)
    {
        drawCell(i, cellWidth, cellHeight, font);
    }

    window.display(); // Actualiza la pantalla
}

template <typename T>
void HashTable<T>::drawCell(int index, int cellWidth, int cellHeight, sf::Font &font)
{
    // Definir cuántas filas habrá
    int numRows = 3;  // Número de filas
    int numColumns = (size + numRows - 1) / numRows;  // Número de columnas por fila

    // Calcular la fila y columna para la celda actual
    int row = index / numColumns;  // Fila
    int col = index % numColumns;  // Columna

    // Dibuja la celda de la tabla
    sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));
    cell.setPosition(50 + col * (cellWidth + 10), 50 + row * (cellHeight + 30));  // Espaciado entre celdas
    cell.setOutlineThickness(2);
    cell.setOutlineColor(sf::Color::Black);

    // Si es la celda que contiene el valor encontrado, resaltar en azul
    if (index == foundIndex)  // `foundIndex` debe ser la variable global que indica la celda encontrada
    {
        cell.setFillColor(sf::Color::Blue);  // Resaltado en azul
    }
    else
    {
        cell.setFillColor(sf::Color::White);  // Color normal para otras celdas
    }

    window.draw(cell);

    // Dibuja el valor dentro de la celda
    if (table[index].has_value())
    {
        // Dibuja el valor dentro de la celda (en la misma celda del índice)
        sf::Text valueText;
        valueText.setFont(font);

        // Comprobamos el tipo de T y convertimos adecuadamente
        if constexpr (std::is_same<T, std::string>::value)
        {
            valueText.setString(table[index].value()); // Si T es string, no necesitamos conversión
        }
        else
        {
            // Convertimos el valor a string si T es un tipo numérico
            valueText.setString(std::to_string(table[index].value()));
        }

        valueText.setCharacterSize(20);
        valueText.setFillColor(sf::Color::Black);
        // Centra el texto dentro de la celda
        valueText.setPosition(50 + col * (cellWidth + 10) + (cellWidth - valueText.getLocalBounds().width) / 2, 
                              50 + row * (cellHeight + 30) + (cellHeight - valueText.getLocalBounds().height) / 2);
        window.draw(valueText);
    }

    // Dibuja el índice debajo de la celda
    sf::Text indexText;
    indexText.setFont(font);
    indexText.setString(std::to_string(index)); // Convertir el índice a string
    indexText.setCharacterSize(15); // Ajusta el tamaño de la fuente para el índice
    indexText.setFillColor(sf::Color::Black);
    // Coloca el índice debajo de la celda con un ajuste de espacio para que no se solapen con otras celdas
    indexText.setPosition(50 + col * (cellWidth + 10) + (cellWidth - indexText.getLocalBounds().width) / 2, 
                          50 + row * (cellHeight + 30) + cellHeight + 5); // Añadir espacio debajo de la celda
    window.draw(indexText);
}

template <typename T>
void HashTable<T>::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return; // CORRECCIÓN: No devolver nada porque es `void`
            }
        }

        drawTable();
        sf::sleep(sf::milliseconds(16)); // ≈ 60 FPS, evita uso excesivo de CPU
    }
}

// Explicit instantiation
template class HashTable<int>;
template class HashTable<std::string>;
