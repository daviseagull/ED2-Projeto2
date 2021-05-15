#include <stdlib.h>

#include "elemento.h"

int Elemento::getValor(){
    return valor;
}

void Elemento::setValor(int v){
    valor = v;
}

void Elemento::print_element() const {
    cout << palavra << ": " << valor << endl;
}

void Elemento::setPalavra(string palavra) {
    this->palavra = palavra;
}

string Elemento::getPalavra() {
    return this->palavra;
}

Elemento::Elemento(string palavra, int repeticoes) {
    this->setPalavra(palavra);
    this->setValor(repeticoes);

}
