#include "ArbolRN.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <SFML/Graphics.hpp>
using namespace sf;

using namespace std;

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define WHITE "\033[1;37m"

// Constructor: inicializa el árbol con un nodo nulo
ArbolRN::ArbolRN()
{
    nulo = new NodoRN("", "", "", "");
    nulo->color = false; // El nodo nulo siempre es negro
    raiz = nulo;
}

// Rotación a la izquierda
void ArbolRN::rotarIzquierda(NodoRN *x)
{
    NodoRN *y = x->derecho;
    x->derecho = y->izquierdo;

    if (y->izquierdo != nulo)
    {
        y->izquierdo->padre = x;
    }

    y->padre = x->padre;
    if (x->padre == nullptr)
    {
        raiz = y;
    }
    else if (x == x->padre->izquierdo)
    {
        x->padre->izquierdo = y;
    }
    else
    {
        x->padre->derecho = y;
    }

    y->izquierdo = x;
    x->padre = y;
}

// Rotación a la derecha
void ArbolRN::rotarDerecha(NodoRN *y)
{
    NodoRN *x = y->izquierdo;
    y->izquierdo = x->derecho;

    if (x->derecho != nulo)
    {
        x->derecho->padre = y;
    }

    x->padre = y->padre;
    if (y->padre == nullptr)
    {
        raiz = x;
    }
    else if (y == y->padre->derecho)
    {
        y->padre->derecho = x;
    }
    else
    {
        y->padre->izquierdo = x;
    }

    x->derecho = y;
    y->padre = x;
}

// Inserción en el Árbol Rojo-Negro
void ArbolRN::insertar(const string &placa, const string &espacioId, const string &fechaHoraIngreso, const string &fechaHoraSalida)
{
    NodoRN *nuevo = new NodoRN(placa, espacioId, fechaHoraIngreso, fechaHoraSalida);
    nuevo->izquierdo = nulo;
    nuevo->derecho = nulo;

    NodoRN *y = nullptr;
    NodoRN *x = raiz;

    while (x != nulo)
    {
        y = x;
        if (nuevo->placa < x->placa)
        {
            x = x->izquierdo;
        }
        else
        {
            x = x->derecho;
        }
    }

    nuevo->padre = y;
    if (y == nullptr)
    {
        raiz = nuevo;
    }
    else if (nuevo->placa < y->placa)
    {
        y->izquierdo = nuevo;
    }
    else
    {
        y->derecho = nuevo;
    }

    nuevo->color = true; // El nuevo nodo siempre es rojo
    balancearInsercion(nuevo);
}

// Balanceo después de la inserción
void ArbolRN::balancearInsercion(NodoRN *nodo)
{
    NodoRN *tio;

    while (nodo->padre && nodo->padre->color == true)
    {
        if (nodo->padre == nodo->padre->padre->izquierdo)
        {
            tio = nodo->padre->padre->derecho;

            if (tio->color == true)
            { // Caso 1: El tío es rojo
                nodo->padre->color = false;
                tio->color = false;
                nodo->padre->padre->color = true;
                nodo = nodo->padre->padre;
            }
            else
            { // Caso 2 o 3: El tío es negro
                if (nodo == nodo->padre->derecho)
                { // Caso 2: Triángulo
                    nodo = nodo->padre;
                    rotarIzquierda(nodo);
                }

                nodo->padre->color = false; // Caso 3: Línea
                nodo->padre->padre->color = true;
                rotarDerecha(nodo->padre->padre);
            }
        }
        else
        {
            // Simétrico al caso anterior
            tio = nodo->padre->padre->izquierdo;

            if (tio->color == true)
            {
                nodo->padre->color = false;
                tio->color = false;
                nodo->padre->padre->color = true;
                nodo = nodo->padre->padre;
            }
            else
            {
                if (nodo == nodo->padre->izquierdo)
                {
                    nodo = nodo->padre;
                    rotarDerecha(nodo);
                }

                nodo->padre->color = false;
                nodo->padre->padre->color = true;
                rotarIzquierda(nodo->padre->padre);
            }
        }
    }

    raiz->color = false; // La raíz siempre es negra
}

// Buscar un nodo en el árbol
NodoRN *ArbolRN::buscar(const string &placa) const
{
    return buscarNodo(raiz, placa);
}

NodoRN *ArbolRN::buscarNodo(NodoRN *nodo, const string &placa) const
{
    if (nodo == nulo || nodo->placa == placa)
    {
        return nodo;
    }

    if (placa < nodo->placa)
    {
        return buscarNodo(nodo->izquierdo, placa);
    }
    else
    {
        return buscarNodo(nodo->derecho, placa);
    }
}

// Recorrido inOrden
vector<NodoRN *> ArbolRN::obtenerInOrden() const
{
    vector<NodoRN *> nodos;
    recorridoInOrden(raiz, nodos);
    return nodos;
}

void ArbolRN::recorridoInOrden(NodoRN *nodo, vector<NodoRN *> &nodos) const
{
    if (nodo != nulo)
    {
        recorridoInOrden(nodo->izquierdo, nodos);
        nodos.push_back(nodo);
        recorridoInOrden(nodo->derecho, nodos);
    }
}

// Destructor
ArbolRN::~ArbolRN()
{
    eliminarNodo(raiz);
    delete nulo;
}

void ArbolRN::eliminarNodo(NodoRN *nodo)
{
    if (nodo != nulo)
    {
        eliminarNodo(nodo->izquierdo);
        eliminarNodo(nodo->derecho);
        delete nodo;
    }
}

void ArbolRN::imprimirArbol() const
{
    if (raiz == nulo)
    {
        cout << "El árbol está vacío.\n";
        return;
    }

    cout << WHITE << "Árbol Rojo-Negro (Solo Espacios de Estacionamiento):\n"
         << RESET;
    imprimirArbolVisual(raiz, 0);
}

// Función recursiva para imprimir el árbol con formato visual
void ArbolRN::imprimirArbolVisual(NodoRN *nodo, int espacio) const
{
    if (nodo == nulo)
        return;

    espacio += 6; // Ajusta el espaciado entre niveles

    // Imprimir subárbol derecho
    imprimirArbolVisual(nodo->derecho, espacio);

    // Imprimir nodo actual con su color
    cout << endl;
    for (int i = 6; i < espacio; i++)
        cout << " ";
    cout << (nodo->color ? RED : WHITE) << nodo->espacioId << RESET << endl;

    // Imprimir subárbol izquierdo
    imprimirArbolVisual(nodo->izquierdo, espacio);
}

// Función auxiliar para imprimir en orden
void ArbolRN::imprimirInOrden(NodoRN *nodo) const
{
    if (nodo != nulo)
    {
        imprimirInOrden(nodo->izquierdo);
        cout << "Placa: " << nodo->placa << " | Espacio: " << nodo->espacioId
             << " | Ingreso: " << nodo->fechaHoraIngreso
             << " | Color: " << (nodo->color ? "Rojo" : "Negro") << endl;
        imprimirInOrden(nodo->derecho);
    }
}

void ArbolRN::imprimirArbolVertical() const
{
    if (raiz == nulo)
    {
        cout << "El árbol está vacío.\n";
        return;
    }

    queue<NodoRN *> cola;
    cola.push(raiz);

    while (!cola.empty())
    {
        int tamanoNivel = cola.size();

        // Imprimir todos los nodos en el nivel actual
        for (int i = 0; i < tamanoNivel; i++)
        {
            NodoRN *actual = cola.front();
            cola.pop();

            // Mostrar el nodo con color
            cout << (actual->color ? RED : WHITE) << actual->espacioId << RESET << " ";

            // Agregar hijos a la cola si no son nulos
            if (actual->izquierdo != nulo)
                cola.push(actual->izquierdo);
            if (actual->derecho != nulo)
                cola.push(actual->derecho);
        }
        cout << endl; // Nueva línea para cada nivel
    }
}

void ArbolRN::imprimirArbolGrafico() 
{
    if (this->raiz == this->nulo)
    {
        std::cout << "El arbol esta vacio.\n";
        return;
    }

    // Crear ventana SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Árbol Rojo-Negro");

    // Variables para dibujar el árbol
    int baseX = window.getSize().x / 2; // Centro de la ventana
    int baseY = 50;                     // Empezamos desde la parte superior

    // Dibujar el árbol
    drawTree(window, raiz, baseX, baseY, 100);

    // Ciclo de eventos
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}

void ArbolRN::drawTree(sf::RenderWindow &window, NodoRN *nodo, int x, int y, int offset)
{
    if (nodo == this->nulo)
        return;

    // Dibujar el nodo como un círculo
    sf::CircleShape nodeShape(20);
    nodeShape.setFillColor(nodo->color ? sf::Color::Red : sf::Color::Black);
    nodeShape.setPosition(x - 20, y - 20);
    window.draw(nodeShape);

    // Dibujar el texto del nodo (placa)
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "No se pudo cargar la fuente\n";
        return;
    }
    sf::Text nodeText(nodo->placa, font, 15);
    nodeText.setFillColor(sf::Color::White);
    nodeText.setPosition(x - 15, y - 10);
    window.draw(nodeText);

    // Dibujar las líneas hacia los hijos
    if (nodo->izquierdo != this->nulo)
    {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(x - offset, y + 50))};
        window.draw(line, 2, sf::Lines);
        drawTree(window, nodo->izquierdo, x - offset, y + 50, offset / 2);
    }
    if (nodo->derecho != this->nulo)
    {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(x + offset, y + 50))};
        window.draw(line, 2, sf::Lines);
        drawTree(window, nodo->derecho, x + offset, y + 50, offset / 2);
    }
}