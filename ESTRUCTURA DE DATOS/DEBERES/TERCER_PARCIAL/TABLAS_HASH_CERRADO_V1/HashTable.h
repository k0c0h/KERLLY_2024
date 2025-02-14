// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <list>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <bitset>

template <typename T>
class HashTable {
private:
    std::vector<std::optional<T>> table;
    int size;
    std::string a,b;
    int hashFunction(int key);
    int hashFunction2(const T &key);
    //int hashFunction2(const T &key);
    int hashFunction(const std::string& key);
    int hashString(const std::string &clave);
    sf::RenderWindow window;
    void drawCell(int index, int cellWidth, int cellHeight, sf::Font &font);
    int foundIndex; 
    T foundKey; 
public:
    HashTable(int size);
    void insert(T key, int method);
    bool search(T key);
    void remove(T key, int method);
    std::string sumaBinaria(const std::string &a, const std::string &b);
    void display();
    void resetHighlight();
    void run();
    void drawTable();
};

#endif