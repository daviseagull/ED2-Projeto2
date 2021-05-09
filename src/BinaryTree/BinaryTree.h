#ifndef BinaryTree_H
#define BinaryTree_H

#include "BinaryNode.h"

class BinaryTree {
private:
    BinaryNode *raiz;
    int comparacoes = 0;

public:
    BinaryTree();

    void aumentaComparacoes();
    void imprimeArvore(BinaryNode* no);
    void inserir(string chave);
    void inserirAux(BinaryNode *no, string chave);

    BinaryNode* getRaiz();
    int getComparacoes();

};

#endif