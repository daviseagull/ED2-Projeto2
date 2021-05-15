#include "element.h"

Element::Element(string palavra, int repeticoes) {
    this->setWord(palavra);
    this->setRepetitions(repeticoes);
}

int Element::getRepetitions(){
    return repetitions;
}

void Element::setRepetitions(int v){
    repetitions = v;
}

void Element::printElement() const {
    cout << word << ": " << repetitions << endl;
}

void Element::setWord(string word) {
    this->word = word;
}


