#ifndef Node_H
#define  Node_H

using namespace std;

class BinaryNode {
private:
    BinaryNode *left, *right;
    string key;
    int quantity;

public:
    BinaryNode(string value);
    virtual ~BinaryNode();
    int getQuantity();
    string getKey();
    BinaryNode* getLeft();
    BinaryNode* getRight();
    void setLeft(BinaryNode *node);
    void setRight(BinaryNode *node);
    void sumOneToQuantity();
};

#endif
