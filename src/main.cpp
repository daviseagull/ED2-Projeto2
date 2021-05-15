#include <iostream>
#include <fstream>
#include "BinaryTree/BinaryTree.h"
#include "AvlTree/AVLTree.h"
#include <time.h>

bool fileReaded = false;

//Metodo utilizado para verificar se a opcao escolhida pelo usuario eh valida
bool verifyOption(int option, int finalValue) {
    for (int i = 0; i <= finalValue; i++) {
        if (option == i)
            return true;
    }
    return false;
}

//Menu para escolha do arquivo que sera base para a analise
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
            cout << "Digite um repetitions valido";
        else
            return option;
    }
}

//Metodo que imprime todos os resultados da analise
void resultMenu(AVLTree *avlTree, BinaryTree *binaryTree, double executionTimeAVL, double executionTimeBinary) {
    cout << "Arvore Binaria de Busca: \n" << binaryTree->getComparisons() << " Comparacoes\n";

    cout << "Tempo de execucao: " << executionTimeBinary << endl;

    cout << "Frequencia das palavras em ordem alfabetica: \n";
    binaryTree->print(binaryTree->getRoot());

    cout << "\nTrending Topics: \n";
    binaryTree->generateTopTrendings(binaryTree->getRoot());
    binaryTree->printTopTrendings();

    cout << "\n\nArvore AVL: \n" << avlTree->getComparisons() << " Comparacoes\n";

    cout << "Tempo de execucao: " << executionTimeAVL << endl;

    cout << "Frequencia das palavras em ordem alfabetica: \n";
    avlTree->inOrder();

    cout << "\nTrending Topics: \n";
    avlTree->generateTopTrendings(avlTree->getRoot());
    avlTree->printTopTrendings();
}

//Metodo para leitura das palavras e insercao na arvore binaria
void readFile(int fileOption, BinaryTree *binaryTree) {
    string line;
    string fileName;

    //sequencia de if para definir o nome do arquivo que sera utilizado
    if (fileOption == 1)
        fileName = "Arquivo1";
    else if (fileOption == 2)
        fileName = "Arquivo2";
    else
        fileName = "Arquivo3";

    //inicio da leitura do arquivo selecionado
    ifstream myfile("../data/" + fileName + ".txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            binaryTree->insert(line); //insercao na arvore binaria
        }
        myfile.close();
        fileReaded = true;
    } else {
        cout << "Unable to open file\n";
    }
}

//Metodo para leitura das palavras e insercao na arvore AVL
void readFile(int fileOption, AVLTree *avlTree) {
    string line;
    string fileName;

    //sequencia de if para definir o nome do arquivo que sera utilizado
    if (fileOption == 1)
        fileName = "Arquivo1";
    else if (fileOption == 2)
        fileName = "Arquivo2";
    else
        fileName = "Arquivo3";

    ifstream file("../data/" + fileName + ".txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            avlTree->insert(line); //insercao na arvore AVL
        }
        file.close();
        fileReaded = true;
    } else {
        cout << "Unable to open file\n";
    }
}

//metodo utilizado para cronometrar o tempo gasto para insert na arvore binaria
double saveFile(BinaryTree *Tree, int fileOption) {
    clock_t initialTimeBinary;
    clock_t finalTimeBinary;

    initialTimeBinary = clock();
    readFile(fileOption, Tree);
    finalTimeBinary = clock();

    return (finalTimeBinary - initialTimeBinary) /
           (double) CLOCKS_PER_SEC; //return o tempo gasto para insert na arvore
}

//metodo utilizado para cronometrar o tempo gasto para insert na arvore AVL
double saveFile(AVLTree *Tree, int fileOption) {
    clock_t initialTimeAVL;
    clock_t finalTimeAVL;

    initialTimeAVL = clock();
    readFile(fileOption, Tree);
    finalTimeAVL = clock();

    return (finalTimeAVL - initialTimeAVL) / (double) CLOCKS_PER_SEC; //return o tempo gasto para insert na arvore
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
        double executionTimeBinary, executionTimeAVL;

        executionTimeAVL = saveFile(avlTree, fileOption);
        executionTimeBinary = saveFile(binaryTree, fileOption);

        if (fileReaded)
            resultMenu(avlTree, binaryTree, executionTimeAVL, executionTimeBinary);

        fileReaded = false;
        free(avlTree);
        free(binaryTree);
    }
    return 0;
}
