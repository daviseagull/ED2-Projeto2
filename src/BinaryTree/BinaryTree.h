#ifndef BinaryTree_H
#define BinaryTree_H

#include "BinaryNode.h"
#include "../List/element.h"
#include <iostream>
#include <list>

using namespace std;

class BinaryTree {
private:
    BinaryNode *root;
    int comparisons = 0;
    list<Element*> topTrendings;

public:
    BinaryTree();
    void addComparisons();
    void print(BinaryNode* node);
    void insert(string key);
    void insertAux(BinaryNode *node, string key);
    void printTopTrendings();
    void generateTopTrendings(BinaryNode*node);
    BinaryNode* getRoot();
    int getComparisons();
};

#endif