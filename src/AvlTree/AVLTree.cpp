#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() {
    //ctor
    root = NULL;
    setComparisons(0);
}

AVLTree::~AVLTree() {
    free(root);
}

bool AVLTree::isEmpty() {
    return root == NULL;
}

int AVLTree::height() {
    return height(root);
}

int AVLTree::height(AVLNode *no) {
    return no == NULL ? -1 : no->getHeight();
}

int AVLTree::max(int lhs, int rhs) {
    return lhs > rhs ? lhs : rhs;
}

int AVLTree::qtNodes() {
    return qtNodes(root);
}

int AVLTree::qtNodes(AVLNode *no) {
    if (no == NULL)
        return 0;

    int qtleft = qtNodes(no->getLeft());
    int qtright = qtNodes(no->getRight());

    return qtleft + qtright + 1;
}

int AVLTree::getComparisons() {
    return comparisons;
}

AVLNode *AVLTree::getRoot() {
    return root;
}

void AVLTree::setComparisons(int comparisons) {
    this->comparisons = comparisons;
}

void AVLTree::addComparisons() {
    comparisons++;
}

void AVLTree::insert(string value) {
    root = insert(root, value);
}

AVLNode *AVLTree::insert(AVLNode *node, string value) {
    addComparisons();
    if (node == NULL)
        return new AVLNode(value);
    if (value == node->getData()) {
        node->addQuantity();
        return node;
    }
    if (value < node->getData()) {
        node->setLeft(insert(node->getLeft(), value));
        if (height(node->getRight()) - height(node->getLeft()) == -2) {
            if (value < node->getLeft()->getData()) {
                node = rotateLL(node);
            } else {
                node = rotateLR(node);
            }
        }
    } else {
        if (value > node->getData()) {
            node->setRight(insert(node->getRight(), value));
            if (height(node->getRight()) - height(node->getLeft()) == 2) {
                if (value > node->getRight()->getData())
                    node = rotateRR(node);
                else
                    node = rotateRL(node);
            }
        }
    }

    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

    return node;
}

AVLNode *AVLTree::rotateLL(AVLNode *node) {
    AVLNode *leftSubTree = node->getLeft();

    node->setLeft(leftSubTree->getRight());
    leftSubTree->setRight(node);

    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

    leftSubTree->setHeight(max(height(leftSubTree->getLeft()), height(node) + 1));

    return leftSubTree;
}

AVLNode *AVLTree::rotateRR(AVLNode *node) {
    AVLNode *rightSubTree = node->getRight();

    node->setRight(rightSubTree->getLeft());
    rightSubTree->setLeft(node);

    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

    rightSubTree->setHeight(max(height(rightSubTree->getRight()), height(node) + 1));

    return rightSubTree;
}

AVLNode *AVLTree::rotateLR(AVLNode *node) {
    node->setLeft(rotateRR(node->getLeft()));

    return rotateLL(node);
}

AVLNode *AVLTree::rotateRL(AVLNode *node) {
    node->setRight(rotateLL(node->getRight()));

    return rotateRR(node);
}

void AVLTree::inOrder() {
    inOrder(root);
}

void AVLTree::inOrder(AVLNode *node) {
    if (node != NULL) {
        inOrder(node->getLeft());
        cout << "     " << node->getData() << ": " << node->getQuantity() << endl;
        inOrder(node->getRight());
    }
}

void AVLTree::generateTopTrendings(AVLNode *node) {
    if (node != NULL) {
        generateTopTrendings(node->getLeft());
        Element *e = new Element(node->getData(), node->getQuantity());
        topTrendings.push_back(e);
        generateTopTrendings(node->getRight());
    }
}

void AVLTree::printTopTrendings() {
    topTrendings.sort([](Element *lhs, Element *rhs) { return lhs->getRepetitions() > rhs->getRepetitions(); });
    for (auto &el: topTrendings) {
        el->printElement();
    }
}

void AVLTree::printBT(string prefix, AVLNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->getData() << std::endl;

        printBT( prefix + (isLeft ? "│   " : "    "), node->getLeft(), true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->getRight(), false);
    }
}

void AVLTree::printBT(AVLNode *node) {
    printBT("", node, false);
}


