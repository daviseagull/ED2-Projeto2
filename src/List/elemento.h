#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

using namespace std;

class Elemento {

private:
    int valor; // valor do elemento
    string palavra;

public:
    Elemento(string palavra, int repeticoes);
    int getValor();
    string getPalavra();
    void setPalavra(string palavra);
    void setValor(int v);
    void print_element() const;
    bool operator < (const Elemento& other) const { return valor > other.valor;}

    Elemento(string basicString);
};

#endif
