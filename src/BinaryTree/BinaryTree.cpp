#include <iostream>

#include "BinaryNode.h"
#include "BinaryTree.h"

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

bool BinaryTree::buscarValor(BinaryNode *raiz, string valor){

    if (valor == raiz->getChave())
        return true;

    else if(valor < raiz->getChave()){

        if (raiz->getEsq() == NULL)
            return false;

        else
            buscarValor(raiz->getEsq(), valor);

    } else if(valor > raiz->getChave()){

        if (raiz->getDir() == NULL)
            return false;

        else
            buscarValor(raiz->getDir(), valor);
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
