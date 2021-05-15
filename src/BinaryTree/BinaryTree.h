#ifndef BinaryTree_H
#define BinaryTree_H

#include "BinaryNode.h"
#include "../List/elemento.h"
#include <iostream>
#include <list>

using namespace std;

class BinaryTree {
private:
    BinaryNode *raiz;
    int comparacoes = 0;
    list<Elemento*> topTrendings;

public:
    BinaryTree();

    void aumentaComparacoes();
    void imprimeArvore(BinaryNode* no);
    void inserir(string chave);
    void inserirAux(BinaryNode *no, string chave);
    void imprimirTopTrendings();
    void gerarTopTrendings(BinaryNode*no);


    BinaryNode* getRaiz();
    int getComparacoes();

};

#endif