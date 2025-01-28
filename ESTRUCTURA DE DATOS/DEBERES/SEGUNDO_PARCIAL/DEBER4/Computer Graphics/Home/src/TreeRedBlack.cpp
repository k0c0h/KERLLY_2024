#include <iostream>
#include <queue>
#include <iomanip>
#include <windows.h> // Para colores en la consola
using namespace std;

// Enumeración para colores de nodos en Árbol Rojo-Negro
enum Color
{
    RED,
    BLACK
};

// Clase para el Árbol Rojo-Negro
template <typename T>
class RedBlackTree
{
private:
    struct Node
    {
        T data;
        Color color;
        Node *parent;
        Node *left;
        Node *right;

        Node(T value)
            : data(value), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
    };

    Node *root;

    // Rotación izquierda
    void rotateLeft(Node *&node)
    {
        Node *child = node->right;
        node->right = child->left;
        if (child->left)
            child->left->parent = node;
        child->parent = node->parent;
        if (!node->parent)
            root = child;
        else if (node == node->parent->left)
            node->parent->left = child;
        else
            node->parent->right = child;
        child->left = node;
        node->parent = child;
    }

    // Rotación derecha
    void rotateRight(Node *&node)
    {
        Node *child = node->left;
        node->left = child->right;
        if (child->right)
            child->right->parent = node;
        child->parent = node->parent;
        if (!node->parent)
            root = child;
        else if (node == node->parent->left)
            node->parent->left = child;
        else
            node->parent->right = child;
        child->right = node;
        node->parent = child;
    }

    // Corrección tras insertar
    void fixInsert(Node *&node)
    {
        Node *parent = nullptr;
        Node *grandparent = nullptr;
        while (node != root && node->color == RED && node->parent->color == RED)
        {
            parent = node->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left)
            {
                Node *uncle = grandparent->right;
                if (uncle && uncle->color == RED)
                {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->right)
                    {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
            else
            {
                Node *uncle = grandparent->left;
                if (uncle && uncle->color == RED)
                {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->left)
                    {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }

    // Buscar un nodo
    Node *searchNode(Node *node, T key)
    {
        if (!node || node->data == key)
            return node;
        if (key < node->data)
            return searchNode(node->left, key);
        return searchNode(node->right, key);
    }

    // Función de eliminación del nodo
    void remove(Node *&node, T key)
    {
        if (node == nullptr)
            return;

        if (key < node->data)
            remove(node->left, key);
        else if (key > node->data)
            remove(node->right, key);
        else
        {
            // Nodo encontrado
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else
            {
                Node *temp = maximum(node->left); // Busca el predecesor inorden (máximo del subárbol izquierdo)
                node->data = temp->data;          // Reemplaza el valor del nodo actual por el predecesor
                remove(node->left, temp->data);   // Elimina el nodo duplicado en el subárbol izquierdo
            }
        }
    }
    Node *maximum(Node *node)
    {
        while (node->right != nullptr)
            node = node->right;
        return node;
    }

    Node *minimum(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Mostrar el árbol con la raíz en la parte superior y los hijos abajo
    void showTree(Node *node, int space)
    {
        if (node == nullptr)
            return;
        space += 10;
        showTree(node->right, space);
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        if (node->color == RED)
            cout << "\033[31m" << node->data << "\033[0m" << endl; // Rojo
        else if (node->color == BLACK)
            cout << node->data << endl; // Negro
        showTree(node->left, space);
    }

    // Funciones de recorrido
    void preOrder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    RedBlackTree() : root(nullptr) {}
    ~RedBlackTree() { deleteTree(root); }

    void insert(T key)
    {
        Node *node = new Node(key);
        Node *parent = nullptr;
        Node *current = root;

        while (current)
        {
            parent = current;
            current = key < current->data ? current->left : current->right;
        }

        node->parent = parent;

        if (!parent)
            root = node;
        else if (key < parent->data)
            parent->left = node;
        else
            parent->right = node;

        fixInsert(node);
    }

    // Eliminar un nodo
    void remove(T key)
    {
        remove(root, key);
    }

    // Mostrar el árbol con el nodo encontrado resaltado en azul
    void searchAndShow(T key)
    {
        Node *node = searchNode(root, key);
        if (node)
        {
            cout << "Elemento encontrado: " << node->data << endl;
            showTreeHighlighted(node, 0);
        }
        else
        {
            cout << "Elemento no encontrado.\n";
        }
    }

    // Mostrar el árbol resaltando el nodo
    void showTreeHighlighted(Node *highlightNode, int space)
    {
        showTree();
        cout << "\033[34m" << highlightNode->data << "\033[0m" << " (resaltado en azul)" << endl;
    }

    // Mostrar recorridos
    void showTraversals()
    {
        cout << "Preorden: ";
        preOrder(root);
        cout << "\nInorden: ";
        inOrder(root);
        cout << "\nPostorden: ";
        postOrder(root);
        cout << "\n";
    }

    // Mostrar el árbol
    // Mostrar el árbol gráficamente en la consola
    void showTree()
    {
        if (!root)
        {
            cout << "Árbol vacío.\n";
            return;
        }

        queue<pair<Node *, int>> q; // Cola para los nodos y niveles
        q.push({root, 0});
        int currentLevel = 0;
        bool hasMoreNodes = true;

        while (hasMoreNodes)
        {
            hasMoreNodes = false;
            int levelNodeCount = q.size();

            for (int i = 0; i < levelNodeCount; i++)
            {
                auto [node, level] = q.front();
                q.pop();

                // Cambiar de nivel
                if (level != currentLevel)
                {
                    cout << "\n\n";
                    currentLevel = level;
                }

                // Espaciado proporcional al nivel
                cout << setw(10 / (level + 1)) << "";

                // Dibujar nodo
                if (node)
                {
                    hasMoreNodes = true; // Hay al menos un nodo válido en el nivel
                    if (node->color == RED)
                    {
                        cout << "\033[31m" << node->data << "\033[0m"; // Rojo
                    }
                    else
                    {
                        cout << "\033[37m" << node->data << "\033[0m"; // Blanco
                    }
                    q.push({node->left, level + 1});
                    q.push({node->right, level + 1});
                }
                else
                {
                    cout << " ";
                    q.push({nullptr, level + 1}); // Agregar nodos vacíos
                    q.push({nullptr, level + 1});
                }
            }
        }
        cout << "\n";
    }
};

// Menú principal
void menu()
{
    RedBlackTree<int> tree;
    int option = 0, element;

    while (true)
    {
        system("cls");
        cout << "Seleccione una opcion:\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Buscar elemento\n";
        cout << "4. Mostrar arbol\n";
        cout << "5. Mostrar recorridos\n";
        cout << "6. Salir\n";
        cout << "Opción: ";
        cin >> option;

        system("cls");
        switch (option)
        {
        case 1:
        {
            int element;
            char option;
            do
            {
                system("cls");
                cout << "Arbol actual:\n";
                tree.showTree();
                cout << "\nIngrese un numero para agregar al arbol: ";
                cin >> element;

                tree.insert(element);

                cout << "\nDesea agregar otro numero? (s/n): ";
                cin >> option;
            } while (option == 's' || option == 'S');
            system("cls");
            cout << "Arbol actual:\n";
            tree.showTree();
            break;
        }
        case 2:
            cout << "Ingrese un elemento a eliminar: ";
            cin >> element;
            tree.remove(element);
            break;
        case 3:
            cout << "Ingrese un elemento a buscar: ";
            cin >> element;
            tree.searchAndShow(element);
            break;
        case 4:
            cout << "Arbol Rojo-Negro:\n";
            tree.showTree();
            break;
        case 5:
            tree.showTraversals();
            break;
        case 6:
            return;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause");
    }
}

int main()
{
    menu();
    return 0;
}
