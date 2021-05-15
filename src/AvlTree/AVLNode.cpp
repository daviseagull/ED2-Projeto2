#include "AVLNode.h"
#include <iostream>

AVLNode::AVLNode() {
    left = NULL;
    right = NULL;
    height = 0;
    quantity = 1;
}

AVLNode::AVLNode(string value) {
    left = NULL;
    right = NULL;
    data = value;
    quantity = 1;
    height = 0;
}

AVLNode::~AVLNode() {
    free(left);
    free(right);
}

void AVLNode::setData(string data) {
    this->data = data;
}

string AVLNode::getData() {
    return data;
}

void AVLNode::setLeft(AVLNode *node) {
    this->left = node;
}

AVLNode *AVLNode::getLeft() {
    return left;
}

void AVLNode::setRight(AVLNode *node) {
    this->right = node;
}

AVLNode *AVLNode::getRight() {
    return right;
}

void AVLNode::setHeight(int height) {
    this->height = height;
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
