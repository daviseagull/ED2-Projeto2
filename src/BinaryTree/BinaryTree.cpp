#include <iostream>
#include <algorithm>

#include "BinaryNode.h"
#include "BinaryTree.h"
#include "../List/elemento.h"

using namespace std;

BinaryTree::BinaryTree() {
    raiz = NULL;
}

void BinaryTree::imprimeArvore(BinaryNode* no){
    if(no != NULL){
        imprimeArvore(no->getEsq());
        cout << no->getChave() << ": " << no->getRepeticoes() << endl;
        imprimeArvore(no->getDir());
    }
}

void BinaryTree::inserir(string chave) {
    if(raiz == NULL)
        raiz = new BinaryNode(chave);
    else
        inserirAux(raiz, chave);
}

void BinaryTree::inserirAux(BinaryNode *no, string chave) {
    this->aumentaComparacoes();
    if (chave == no->getChave())
        no->aumentaRepeticoes();

    if(chave < no->getChave()) {
        if(no->getEsq() == NULL) {
            BinaryNode *novo_no = new BinaryNode(chave);
            no->setEsq(novo_no);
        } else
            inserirAux(no->getEsq(), chave);
    }

    else if(chave > no->getChave()) {
        if(no->getDir() == NULL){
            BinaryNode *novo_no = new BinaryNode(chave);
            no->setDir(novo_no);
        } else
            inserirAux(no->getDir(), chave);
    }
}

void BinaryTree::gerarTopTrendings(BinaryNode * no) {
    if(no != NULL){
        gerarTopTrendings(no->getEsq());
        Elemento * e = new Elemento(no->getChave(), no->getRepeticoes());
        topTrendings.push_back(e);
        gerarTopTrendings(no->getDir());
    }
}

void BinaryTree::imprimirTopTrendings(){
    topTrendings.sort([](Elemento * lhs, Elemento* rhs){return lhs->getValor() > rhs->getValor();});
    for(auto& el: topTrendings){
        el->print_element();
    }
}

int BinaryTree::getComparacoes() {
    return this->comparacoes;
}

void BinaryTree::aumentaComparacoes() {
    comparacoes += 1;
}

BinaryNode* BinaryTree::getRaiz() {
    return raiz;
}
