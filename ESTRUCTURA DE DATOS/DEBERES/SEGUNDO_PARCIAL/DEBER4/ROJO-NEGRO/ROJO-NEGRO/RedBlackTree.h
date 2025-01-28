#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"
#include <queue>
#include <iomanip>

template <typename T>
class RedBlackTree
{
private:
    Node<T> *root;
    void rotateLeft(Node<T> *&node);
    void rotateRight(Node<T> *&node);
    void fixInsert(Node<T> *&node);
    Node<T> *searchNode(Node<T> *node, T key);
    void remove(Node<T> *&node, T key);
    Node<T> *maximum(Node<T> *node);
    Node<T> *minimum(Node<T> *node);
    void showTree(Node<T> *node, int space);
    void preOrder(Node<T> *node);
    void inOrder(Node<T> *node);
    void postOrder(Node<T> *node);
    void deleteTree(Node<T> *node);

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(T key);
    void remove(T key);
    void searchAndShow(T key);
    void showTree();
    void showTraversals();
    void showTreeHighlighted(Node<T> *highlightNode, int space);
};

#endif // REDBLACKTREE_H
