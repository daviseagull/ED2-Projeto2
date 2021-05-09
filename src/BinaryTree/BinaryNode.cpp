#include <iostream>

#include "BinaryNode.h"

using namespace std;

BinaryNode::BinaryNode(string value){
    this->chave = value;
    this->repeticoes = 1;
    esq = NULL;
    dir = NULL;
}

BinaryNode::~BinaryNode(){
    free(esq);
    free(dir);
}

int BinaryNode::getRepeticoes(){
    return repeticoes;
}

void BinaryNode::setRepeticoes(int value){
    repeticoes = value;
}

string BinaryNode::getChave(){
    return chave;
}

BinaryNode* BinaryNode::getEsq(){
    return esq;
}

BinaryNode* BinaryNode::getDir(){
    return dir;
}

void BinaryNode::setEsq(BinaryNode *no){
    esq = no;
}

void BinaryNode::setDir(BinaryNode *no){
    dir = no;
}

void BinaryNode::aumentaRepeticoes(){
    repeticoes++;
}


