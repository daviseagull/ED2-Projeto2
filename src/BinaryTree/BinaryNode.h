#ifndef Node_H
#define  Node_H

using namespace std;

class BinaryNode {
private:
    BinaryNode *esq, *dir;
    string chave;
    int repeticoes;

public:
    BinaryNode(string value);

    int getRepeticoes();

    void setRepeticoes(int value);

    string getChave();

    BinaryNode* getEsq();

    BinaryNode* getDir();

    void setEsq(BinaryNode *no);

    void setDir(BinaryNode *no);

    void aumentaRepeticoes();

};

#endif
