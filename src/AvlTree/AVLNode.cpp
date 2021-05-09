#include "AVLNode.h"
#include <iostream>

AVLNode::AVLNode() {
    left = NULL;
    right = NULL;
    height = 0;
    quantity = 1;
}

AVLNode::AVLNode(string valor) {
    left = NULL;
    right = NULL;
    data = valor;
    quantity = 1;
    height = 0;
}

AVLNode::~AVLNode() {
    //dtor
}

void AVLNode::setData(string d) {
    data = d;
}

string AVLNode::getData() {
    return data;
}

void AVLNode::setLeft(AVLNode *n) {
    left = n;
}

AVLNode* AVLNode::getLeft() {
    return left;
}

void AVLNode::setRight(AVLNode *n) {
    right = n;
}
AVLNode* AVLNode::getRight() {
    return right;
}

void AVLNode::setHeight(int h) {
    height = h;
}

int AVLNode::getHeight() {
    return height;
}

void AVLNode::addQuantity() {
    quantity += 1;
}

int AVLNode::getQuantity() {
    return quantity;
}
