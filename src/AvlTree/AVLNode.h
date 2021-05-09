#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>

using namespace std;

class AVLNode
{
public:
    AVLNode();
    AVLNode(string);
    virtual ~AVLNode();
    string getData();
    int getHeight();
    void setData(string);
    void setHeight(int);
    AVLNode* getLeft();
    AVLNode* getRight();
    void setRight(AVLNode*);
    void setLeft(AVLNode*);
    void addQuantity();
    void setQuantity();
    int getQuantity();

protected:

private:
    AVLNode* left, *right;
    string data;
    int height;
    int quantity;
};

#endif // AVLNODE_H
