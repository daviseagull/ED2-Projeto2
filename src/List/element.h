#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

using namespace std;

class Element {

private:
    int repetitions;
    string word;

public:
    Element(string palavra, int repetitions);
    int getRepetitions();
    void setWord(string word);
    void setRepetitions(int v);
    void printElement() const;
    bool operator < (const Element& other) const { return repetitions > other.repetitions;}
};

#endif
