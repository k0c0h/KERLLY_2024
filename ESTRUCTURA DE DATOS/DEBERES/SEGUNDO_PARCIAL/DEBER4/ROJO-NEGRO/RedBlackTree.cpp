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
void RedBlackTree<T>::fixInsert(Node<T> *&node) {
    Node<T> *parent = nullptr;
    Node<T> *grandparent = nullptr;

    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node<T> *uncle = grandparent->right;

            if (uncle && uncle->color == RED) {
                // Caso 1: El tío es rojo
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    // Caso 2: El nodo es un hijo derecho
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Caso 3: El nodo es un hijo izquierdo
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Node<T> *uncle = grandparent->left;

            if (uncle && uncle->color == RED) {
                // Caso 1: El tío es rojo
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    // Caso 2: El nodo es un hijo izquierdo
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Caso 3: El nodo es un hijo derecho
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::insert(T key) {
    Node<T> *node = new Node<T>(key);
    Node<T> *parent = nullptr;
    Node<T> *current = root;

    while (current) {
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

    node->color = RED;
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
                        cout << "\033[31m(" << node->data << ")\033[0m";
                    else
                        cout << "(" << node->data << ")";

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
void RedBlackTree<T>::fixDelete(Node<T> *&node) {
    while (node != root && node && node->color == BLACK) { 
        if (node == node->parent->left) {
            Node<T> *sibling = node->parent->right;
            if (sibling && sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }
            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (!sibling->right || sibling->right->color == BLACK) {
                    if (sibling->left) sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                if (sibling->right) sibling->right->color = BLACK;
                rotateLeft(node->parent);
                node = root;
            }
        } else {
            Node<T> *sibling = node->parent->left;
            if (sibling && sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateRight(node->parent);
                sibling = node->parent->left;
            }
            if ((!sibling->right || sibling->right->color == BLACK) &&
                (!sibling->left || sibling->left->color == BLACK)) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (!sibling->left || sibling->left->color == BLACK) {
                    if (sibling->right) sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                if (sibling->left) sibling->left->color = BLACK;
                rotateRight(node->parent);
                node = root;
            }
        }
    }
    if (node) node->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::remove(Node<T>*& node, T key) {
    if (!node)
        return;

    Node<T>* x;
    Node<T>* xParent;
    Node<T>* y = node;
    bool yOriginalColor = y->color;

    if (!node->left) {
        x = node->right;
        xParent = node->parent;
        transplant(node, node->right);
    } else if (!node->right) {
        x = node->left;
        xParent = node->parent;
        transplant(node, node->left);
    } else {
        y = minimum(node->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == node) {
            if (x)
                x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = node->right;
            if (y->right)
                y->right->parent = y;
        }
        transplant(node, y);
        y->left = node->left;
        if (y->left)
            y->left->parent = y;
        y->color = node->color;
    }

    delete node;

    if (yOriginalColor == BLACK)
        fixRemove(x, xParent);
}

template <typename T>
void RedBlackTree<T>::transplant(Node<T> *u, Node<T> *v) {
    if (!u->parent) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v) {
        v->parent = u->parent;
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
void RedBlackTree<T>::remove(T key) {
    Node<T> *nodeToDelete = searchNode(root, key);

    if (!nodeToDelete)
        return;

    Node<T> *y = nodeToDelete;  // Nodo que será eliminado o reemplazado
    Node<T> *x = nullptr;
    Node<T> *xParent = nullptr;
    bool yOriginalColor = y->color;

    // Elegir el sucesor en preorden si tiene hijos izquierdos
    if (nodeToDelete->left) {
        y = maximum(nodeToDelete->left); // Máximo del subárbol izquierdo (preorden)
        yOriginalColor = y->color;
        x = y->left; // El predecesor no tendrá hijos derechos
        if (y->parent == nodeToDelete) {
            xParent = y;
        } else {
            transplant(y, y->left);
            y->left = nodeToDelete->left;
            y->left->parent = y;
        }
        transplant(nodeToDelete, y);
        y->right = nodeToDelete->right;
        if (y->right)
            y->right->parent = y;
        y->color = nodeToDelete->color;
    } else if (nodeToDelete->right) {
        y = minimum(nodeToDelete->right); // Sucesor inorden si no tiene hijos izquierdos
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == nodeToDelete) {
            xParent = y;
        } else {
            transplant(y, y->right);
            y->right = nodeToDelete->right;
            y->right->parent = y;
        }
        transplant(nodeToDelete, y);
        y->left = nodeToDelete->left;
        if (y->left)
            y->left->parent = y;
        y->color = nodeToDelete->color;
    } else {
        x = nullptr;
        xParent = nodeToDelete->parent;
        transplant(nodeToDelete, nullptr);
    }

    delete nodeToDelete;

    if (yOriginalColor == BLACK)
        fixRemove(x, xParent);
}

template <typename T>
void RedBlackTree<T>::fixRemove(Node<T> *node, Node<T> *parent) {
    while (node != root && (!node || node->color == BLACK)) {
        if (node == parent->left) {
            Node<T> *sibling = parent->right;
            if (sibling && sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(parent);
                sibling = parent->right;
            }
            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = parent->parent;
            } else {
                if (!sibling->right || sibling->right->color == BLACK) {
                    if (sibling->left)
                        sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right)
                    sibling->right->color = BLACK;
                rotateLeft(parent);
                node = root;
            }
        } else {
            Node<T> *sibling = parent->left;
            if (sibling && sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(parent);
                sibling = parent->left;
            }
            if ((!sibling->right || sibling->right->color == BLACK) &&
                (!sibling->left || sibling->left->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = parent->parent;
            } else {
                if (!sibling->left || sibling->left->color == BLACK) {
                    if (sibling->right)
                        sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left)
                    sibling->left->color = BLACK;
                rotateRight(parent);
                node = root;
            }
        }
    }
    if (node)
        node->color = BLACK;
}


