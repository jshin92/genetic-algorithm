#include "Chromosome.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Chromosome::Chromosome() {
    m_bits = "";
    m_fitness = 0.0;
}

Chromosome::Chromosome(string bits, double fitness) {
    m_bits = bits;
    m_fitness = fitness;
}

void Chromosome::setToRandom() {
    for (int i = 0; i < CHROMOSOME_LEN; i++) {
        int x = rand() % 2;
        m_bits += to_string(x);
    }
}

void Chromosome::printBits() {
    cout << m_bits << endl;
}

