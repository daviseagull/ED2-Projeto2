#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include "../List/element.h"
#include <list>
#include <iostream>

using namespace std;

class AVLTree
{
private:
    AVLNode *root;
    int comparisons = 0;
    list<Element*> topTrendings;

    int height(AVLNode*);
    int qtNodes(AVLNode*);
    AVLNode* insert(AVLNode* node, string value);
    void inOrder(AVLNode *node);
    AVLNode* rotateLL(AVLNode*);
    AVLNode* rotateRR(AVLNode*);
    AVLNode* rotateLR(AVLNode*);
    AVLNode* rotateRL(AVLNode*);
    int maximo(int, int);

public:
    AVLTree();
    virtual ~AVLTree();
    AVLNode* getRoot();
    bool isEmpty();
    int height();
    int qtNodes();
    void insert (string value);
    void inOrder();
    void setComparisons(int comparisons);
    int getComparisons();
    void addComparisons();
    void printTopTrendings();
    void generateTopTrendings(AVLNode* node);

};

#endif // AVLTREE_H
