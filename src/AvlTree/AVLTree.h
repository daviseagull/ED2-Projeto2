#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include <iostream>

using namespace std;

class AVLTree
{
public:
    AVLTree();
    virtual ~AVLTree();
    AVLNode* getRoot();
    bool isEmpty();
    int height();
    int qtNodes();
    void inserir (string valor);
    void preOrder();
    void posOrder();
    void inOrder();
    void reverseOrder();
    void setQtd(int qtd);
    int getQtd();
    void addOneQtd();

protected:

private:
    AVLNode *root;
    int qtd;

    int height(AVLNode*);
    int qtNodes(AVLNode*);
    AVLNode* inserir(AVLNode*, string);
    void preOrder(AVLNode *no);
    void posOrder(AVLNode *no);
    void inOrder(AVLNode *no);
    AVLNode* rotateLL(AVLNode*);
    AVLNode* rotateRR(AVLNode*);
    AVLNode* rotateLR(AVLNode*);
    AVLNode* rotateRL(AVLNode*);
    void reverseOrder(AVLNode*);
    int maximo(int, int);

};

#endif // AVLTREE_H
