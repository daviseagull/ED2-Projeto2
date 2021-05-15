#include <iostream>
#include <algorithm>

#include "BinaryNode.h"
#include "BinaryTree.h"
#include "../List/element.h"

using namespace std;

BinaryTree::BinaryTree() {
    root = NULL;
}

void BinaryTree::print(BinaryNode* node){
    if(node != NULL){
        print(node->getLeft());
        cout << "     " << node->getKey() << ": " << node->getQuantity() << endl;
        print(node->getRight());
    }
}

void BinaryTree::insert(string key) {
    if(root == NULL)
        root = new BinaryNode(key);
    else
        insertAux(root, key);
}

void BinaryTree::insertAux(BinaryNode *node, string key) {
    this->addComparisons();
    if (key == node->getKey())
        node->sumOneToQuantity();

    if(key < node->getKey()) {
        if(node->getLeft() == NULL) {
            BinaryNode *novo_no = new BinaryNode(key);
            node->setLeft(novo_no);
        } else
            insertAux(node->getLeft(), key);
    }

    else if(key > node->getKey()) {
        if(node->getRight() == NULL){
            BinaryNode *novo_no = new BinaryNode(key);
            node->setRight(novo_no);
        } else
            insertAux(node->getRight(), key);
    }
}

void BinaryTree::generateTopTrendings(BinaryNode * node) {
    if(node != NULL){
        generateTopTrendings(node->getLeft());
        Element * e = new Element(node->getKey(), node->getQuantity());
        topTrendings.push_back(e);
        generateTopTrendings(node->getRight());
    }
}

void BinaryTree::printTopTrendings(){
    topTrendings.sort([](Element * lhs, Element* rhs){return lhs->getRepetitions() > rhs->getRepetitions();});
    for(auto& el: topTrendings){
        el->printElement();
    }
}

int BinaryTree::getComparisons() {
    return this->comparisons;
}

void BinaryTree::addComparisons() {
    comparisons += 1;
}

BinaryNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::printBT(string prefix, BinaryNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->getKey() << std::endl;

        printBT( prefix + (isLeft ? "│   " : "    "), node->getLeft(), true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->getRight(), false);
    }
}

void BinaryTree::printBT(BinaryNode *node) {
    printBT("", node, false);
}
