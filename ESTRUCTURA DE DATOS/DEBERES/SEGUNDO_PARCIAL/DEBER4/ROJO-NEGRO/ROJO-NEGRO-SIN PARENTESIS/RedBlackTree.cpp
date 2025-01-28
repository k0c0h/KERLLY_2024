#include "RedBlackTree.h"
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

template <typename T>
RedBlackTree<T>::RedBlackTree() : root(nullptr) {}

template <typename T>
RedBlackTree<T>::~RedBlackTree() { deleteTree(root); }

template <typename T>
void RedBlackTree<T>::rotateLeft(Node<T> *&node)
{
    Node<T> *child = node->right;
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

template <typename T>
void RedBlackTree<T>::rotateRight(Node<T> *&node)
{
    Node<T> *child = node->left;
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

template <typename T>
void RedBlackTree<T>::fixInsert(Node<T> *&node)
{
    Node<T> *parent = nullptr;
    Node<T> *grandparent = nullptr;
    while (node != root && node->color == RED && node->parent->color == RED)
    {
        parent = node->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node<T> *uncle = grandparent->right;
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
            Node<T> *uncle = grandparent->left;
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

template <typename T>
void RedBlackTree<T>::insert(T key)
{
    Node<T> *node = new Node<T>(key);
    Node<T> *parent = nullptr;
    Node<T> *current = root;

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

template <typename T>
void RedBlackTree<T>::showTree() {
    if (!root) {
        cout << "Arbol vacio.\n";
        return;
    }

    queue<Node<T>*> nodes;
    nodes.push(root);
    int height = calculateHeight(root); // Calculamos la altura del árbol
    int maxWidth = (1 << height) - 1;   // Máximo número de nodos en el nivel más bajo

    for (int level = 0; level <= height; ++level) {
        int spaces = (1 << (height - level)) - 1; // Espacios iniciales para el nivel
        int between = (1 << (height - level + 1)) - 1; // Espacios entre nodos en el nivel

        cout << string(spaces, ' '); // Espacios iniciales

        int nodesInLevel = 1 << level; // Número de nodos en este nivel
        for (int i = 0; i < nodesInLevel; ++i) {
            if (!nodes.empty()) {
                Node<T>* node = nodes.front();
                nodes.pop();

                if (node) {
                    if (node->color == RED)
                        cout << "\033[31m" << node->data << "\033[0m";
                    else
                        cout << node->data;

                    nodes.push(node->left);
                    nodes.push(node->right);
                } else {
                    cout << " ";
                    nodes.push(nullptr);
                    nodes.push(nullptr);
                }
            } else {
                cout << " ";
            }
            cout << string(between, ' '); // Espacios entre nodos
        }
        cout << endl;

        // Si todos los nodos en el nivel son nulos, terminamos
        bool allNull = true;
        queue<Node<T>*> tempQueue = nodes;
        while (!tempQueue.empty()) {
            if (tempQueue.front() != nullptr) {
                allNull = false;
                break;
            }
            tempQueue.pop();
        }

        if (allNull)
            break;
    }
}

template <typename T>
int RedBlackTree<T>::calculateHeight(Node<T>* node) {
    if (!node) return 0;
    return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
}

template <typename T>
Node<T> *RedBlackTree<T>::searchNode(Node<T> *node, T key)
{
    if (!node || node->data == key)
        return node;
    if (key < node->data)
        return searchNode(node->left, key);
    return searchNode(node->right, key);
}

template <typename T>
void RedBlackTree<T>::remove(Node<T> *&node, T key)
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
            Node<T> *temp = node->left ? node->left : node->right;
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
            Node<T> *temp = maximum(node->left); 
            node->data = temp->data;             
            remove(node->left, temp->data);      
        }
    }
}

template <typename T>
Node<T> *RedBlackTree<T>::maximum(Node<T> *node)
{
    while (node->right != nullptr)
        node = node->right;
    return node;
}

template <typename T>
Node<T> *RedBlackTree<T>::minimum(Node<T> *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T>
void RedBlackTree<T>::showTree(Node<T> *node, int space)
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

template <typename T>
void RedBlackTree<T>::preOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void RedBlackTree<T>::inOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

template <typename T>
void RedBlackTree<T>::postOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

template <typename T>
void RedBlackTree<T>::deleteTree(Node<T> *node)
{
    if (node == nullptr)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template <typename T>
void RedBlackTree<T>::showTraversals()
{
    cout << "Preorden: ";
    preOrder(root);
    cout << "\nInorden: ";
    inOrder(root);
    cout << "\nPostorden: ";
    postOrder(root);
    cout << "\n";
}

// Mostrar el árbol con el nodo encontrado resaltado en azul
template <typename T>
void RedBlackTree<T>::searchAndShow(T key)
{
    Node<T> *node = searchNode(root, key);
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
template <typename T>
void RedBlackTree<T>::showTreeHighlighted(Node<T> *highlightNode, int space)
{
    showTree();
    cout << "\033[34m" << highlightNode->data << "\033[0m" << " (resaltado en azul)" << endl;
}

template <typename T>
void RedBlackTree<T>::remove(T key)
{
    remove(root, key);
}