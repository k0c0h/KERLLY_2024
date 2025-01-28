#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

template <typename T>
class Node
{
public:
    T data;
    Color color;
    Node *parent;
    Node *left;
    Node *right;

    Node(T value)
        : data(value), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
