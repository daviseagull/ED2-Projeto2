#ifndef BinaryTree_H
#define BinaryTree_H

#include "BinaryNode.h"

class BinaryTree {
private:
    BinaryNode *raiz;
    int comparacoes = 0;

public:
    BinaryTree();

    int getComparacoes();

    void aumentaComparacoes();

    void imprimeArvore(BinaryNode* no);

    void inserir(string chave);

    void inserirAux(BinaryNode *no, string chave);

    bool buscarValor(BinaryNode *raiz, string valor);

    BinaryNode* getRaiz();
};

#endif