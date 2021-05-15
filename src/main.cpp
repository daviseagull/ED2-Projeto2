#include <iostream>
#include <fstream>
#include "BinaryTree/BinaryTree.h"
#include "AvlTree/AVLTree.h"
#include <time.h>

bool fileReaded = true;

bool verifyOption(int option, int finalValue) {
    for (int i = 0; i <= finalValue; i++) {
        if (option == i)
            return true;
    }
    return false;
}

int fileMenu() {

    int option;
    int finalValue = 3;
    bool verified = false;

    while (!verified) {
        cout << "\n\n";
        cout << "  ___________________________________________________  \n";
        cout << " |                                                   | \n";
        cout << " |                   Projeto - 2                     | \n";
        cout << " |            Davi Gomes Seagull - 31746357          | \n";
        cout << " |    Pedro Henrique Rodrigues Correa - 41908406     | \n";
        cout << " |                                                   | \n";
        cout << " |___________________________________________________| \n";
        cout << " |             Menu - Escolha do Arquivo             | \n";
        cout << " |                                                   | \n";
        cout << " |                1 - Arquivo Texto 1                | \n";
        cout << " |                2 - Arquivo Texto 2                | \n";
        cout << " |                3 - Arquivo Texto 3                | \n";
        cout << " |                     0 - sair                      | \n";
        cout << " |                                                   | \n";
        cout << " |___________________________________________________| \n";

        cout << "\nDigite a opcao desejada: ";
        cin >> option;

        bool verified = verifyOption(option, finalValue);
        if (!verified)
            cout << "Digite um valor valido";
        else
            return option;
    }
}

void resultMenu(AVLTree *avlTree, BinaryTree *binaryTree, double tempoExecucaoAVL, double tempoExecucaoBinary) {
    cout << "Arvore Binaria de Busca: \n";
    cout << binaryTree->getComparacoes() << " Comparacoes\n";
    cout << "Tempo de execucao: " << tempoExecucaoBinary << endl;
    cout << "Frequencia das palavras em ordem alfabetica: \n";
    binaryTree->imprimeArvore(binaryTree->getRaiz());
    cout << "\nTrending Topics: \n";
    binaryTree->gerarTopTrendings(binaryTree->getRaiz());
    binaryTree->imprimirTopTrendings();

    cout << "\n\nArvore AVL: \n";
    cout << avlTree->getQtd() << " Comparacoes\n";
    cout << "Tempo de execucao: " << tempoExecucaoAVL << endl;
    cout << "Frequencia das palavras em ordem alfabetica: \n";
    avlTree->inOrder();
    cout << "\nTrending Topics: \n";
    avlTree->gerarTopTrendings(avlTree->getRoot());
    avlTree->imprimirTopTrendings();
}

void readFile(int fileOption, BinaryTree *binaryTree) {
    string line;

    if (fileOption == 1) {
        ifstream myfile("../data/Arquivo1.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                binaryTree->inserir(line);
            }
            myfile.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }

    } else if (fileOption == 2) {
        ifstream myfile("../data/Arquivo2.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                binaryTree->inserir(line);
            }
            myfile.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }
    } else {
        ifstream myfile("../data/Arquivo3.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                binaryTree->inserir(line);
            }
            myfile.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }
    }
}

void readFile(int fileOption, AVLTree *avlTree) {
    string line;

    if (fileOption == 1) {
        ifstream file("../data/Arquivo1.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                avlTree->inserir(line);
            }
            file.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }
    }
    if (fileOption == 2) {
        ifstream file("../data/Arquivo2.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                avlTree->inserir(line);
            }
            file.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }
    }
    if (fileOption == 3) {
        ifstream file("../data/Arquivo3.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                avlTree->inserir(line);
            }
            file.close();
        } else {
            cout << "Unable to open file\n";
            fileReaded = false;
        }
    }
}

double saveFile(AVLTree *Tree, int fileOption) {
    clock_t tempoInicialAVL;
    clock_t tempoFinalAVL;

    tempoInicialAVL = clock();
    readFile(fileOption, Tree);
    tempoFinalAVL = clock();

    return (tempoFinalAVL - tempoInicialAVL) / (double) CLOCKS_PER_SEC;
}

double saveFile(BinaryTree *Tree, int fileOption) {
    clock_t tempoInicialAVL;
    clock_t tempoFinalAVL;

    tempoInicialAVL = clock();
    readFile(fileOption, Tree);
    tempoFinalAVL = clock();

    return (tempoFinalAVL - tempoInicialAVL) / (double) CLOCKS_PER_SEC;
}

int main() {
    bool menu = true;

    while (menu) {
        int fileOption = fileMenu();
        if (fileOption == 0) {
            menu = false;
            break;
        }
        AVLTree *avlTree = new AVLTree();
        BinaryTree *binaryTree = new BinaryTree();
        double tempoExecucaoBinary, tempoExecucaoAVL;

        tempoExecucaoAVL = saveFile(avlTree, fileOption);
        tempoExecucaoBinary = saveFile(binaryTree, fileOption);

        if (fileReaded)
            resultMenu(avlTree, binaryTree, tempoExecucaoAVL, tempoExecucaoBinary);

        fileReaded = true;
        free(avlTree);
        free(binaryTree);
    }
    return 0;
}
