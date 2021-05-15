#include <iostream>
#include <fstream>
#include "BinaryTree/BinaryTree.h"
#include "AvlTree/AVLTree.h"
#include <time.h>
#include <conio.h>

bool fileReaded = true;

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
        cout << " |                     0 - Sair                      | \n";
        cout << " |                                                   | \n";
        cout << " |___________________________________________________| \n";

        cout << "\nDigite a opcao desejada: ";
        cin >> option;

        bool verified = verifyOption(option, finalValue);
        if (!verified)
            cout << "\nDigite uma opcao valida\n";
        else
            return option;
    }
}

//Menu para escolher quais resultados serao exibidos
int optionMenu() {
    int option;
    int finalValue = 5;
    bool verified = false;

    while (!verified) {
        cout << "  ___________________________________________________ \n";
        cout << " |                 Menu - Resultados                 | \n";
        cout << " |                                                   | \n";
        cout << " |           1 - Visualizar Resultados AVL           | \n";
        cout << " |           2 - Visualizar Resultados BST           | \n";
        cout << " |        3 - Visualizar Resultados Resumidos        | \n";
        cout << " |                 4 - Visualizar AVL                | \n";
        cout << " |                 5 - Visualizar BST                | \n";
        cout << " |                    0 - Voltar                     | \n";
        cout << " |                                                   | \n";
        cout << " |___________________________________________________| \n";

        cout << "\nDigite a opcao desejada: ";
        cin >> option;

        bool verified = verifyOption(option, finalValue);
        if (!verified)
            cout << "Digite uma opcao valida";
        else
            return option;
    }
}

//Metodo que imprime os resultados da BST
void resultMenu(BinaryTree *binaryTree, double executionTimeBinary) {
    cout << "\nArvore Binaria de Busca: \n" << binaryTree->getComparisons() << " Comparacoes\n";
    cout << "Tempo de execucao: " << executionTimeBinary << endl;
    cout << "Frequencia das palavras em ordem alfabetica: \n";
    binaryTree->print(binaryTree->getRoot());
    cout << "\nTrending Topics: \n";
    binaryTree->generateTopTrendings(binaryTree->getRoot());
    binaryTree->printTopTrendings();

}

//Metodo que imprime os resultados da AVL
void resultMenu(AVLTree *avlTree, double executionTimeAVL) {
    cout << "\nArvore AVL: \n" << avlTree->getComparisons() << " Comparacoes\n";
    cout << "Tempo de execucao: " << executionTimeAVL << endl;
    cout << "Frequencia das palavras em ordem alfabetica: \n";
    avlTree->inOrder();
    cout << "\nTrending Topics: \n";
    avlTree->generateTopTrendings(avlTree->getRoot());
    avlTree->printTopTrendings();
}

//Metodo para imprimir todos os resultados simplificados (sem a frequencia e topTrendings)
void resultSimplifiedMenu(AVLTree* avlTree, BinaryTree* binaryTree, double executionTimeBinary, double executionTimeAVL){
    cout << "\nArvore AVL: \n" << avlTree->getComparisons() << " Comparacoes\n";
    cout << "Tempo de execucao: " << executionTimeAVL << endl;

    cout << "\nArvore Binaria de Busca: \n" << binaryTree->getComparisons() << " Comparacoes\n";
    cout << "Tempo de execucao: " << executionTimeBinary << endl;
}

//Metodo para imprimir a AVL formatada
void printAVL(AVLTree *avlTree) {
    cout << "Arvore AVL: \n";
    avlTree->printBT(avlTree->getRoot());
}

//Metodo para imprimir a BST formatada
void printBST(BinaryTree *binaryTree) {
    cout << "Arvore Binaria de Busca (BST): \n";
    binaryTree->printBT(binaryTree->getRoot());
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
    } else {
        cout << "Unable to open file\n";
        fileReaded = false;
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
    } else {
        cout << "Unable to open file\n";
        fileReaded = false;
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
        bool subMenu = true;
        int fileOption = fileMenu();
        if (fileOption == 0) {
            menu = false;
            break;
        }

        system("cls");

        AVLTree *avlTree = new AVLTree();
        BinaryTree *binaryTree = new BinaryTree();
        double executionTimeBinary, executionTimeAVL;

        executionTimeAVL = saveFile(avlTree, fileOption);
        executionTimeBinary = saveFile(binaryTree, fileOption);

        if (fileReaded) {
            while (subMenu) {
                system("cls");
                int option = optionMenu();
                if (option == 0) {
                    subMenu = false;
                    break;
                }
                if (option == 1)
                    resultMenu(avlTree, executionTimeAVL);
                else if (option == 2)
                    resultMenu(binaryTree, executionTimeBinary);
                else if(option == 3)
                    resultSimplifiedMenu(avlTree,binaryTree,executionTimeBinary,executionTimeAVL);
                else if (option == 4)
                    printAVL(avlTree);
                else
                    printBST(binaryTree);

                cout << "\nAperte qualquer tecla para voltar ao menu";
                getch();
                system("cls");
            }
        }

        fileReaded = true;
        free(avlTree);
        free(binaryTree);

        cout << "\nAperte qualquer tecla para voltar ao menu";
        getch();
        system("cls");

    }

    return 0;
}
