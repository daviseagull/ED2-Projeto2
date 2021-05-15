#include <iostream>

#include "BinaryNode.h"

using namespace std;

BinaryNode::BinaryNode(string value){
    this->key = value;
    this->quantity = 1;
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode(){
    free(left);
    free(right);
}

int BinaryNode::getQuantity(){
    return quantity;
}

string BinaryNode::getKey(){
    return key;
}

BinaryNode* BinaryNode::getLeft(){
    return left;
}

BinaryNode* BinaryNode::getRight(){
    return right;
}

void BinaryNode::setLeft(BinaryNode *node){
    left = node;
}

void BinaryNode::setRight(BinaryNode *node){
    right = node;
}

void BinaryNode::sumOneToQuantity(){
    quantity++;
}


