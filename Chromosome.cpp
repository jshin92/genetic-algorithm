#include "Chromosome.h"
#include "GeneticAlgo.h"
#include <iostream>
#include <stdlib.h>

#define CHROMOSOME_LEN 40
#define GENE_LEN 4
using namespace std;

Chromosome::Chromosome() {
    m_bits = "";
    m_fitness = 0.0;
}

Chromosome::Chromosome(string bits, double fitness) {
    m_bits = bits;
    m_fitness = fitness;
}

void Chromosome::setGA(GeneticAlgo* ga) {
    m_ga = ga;
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

void Chromosome::calcFitness() {
    bool expectingNumber = true;
    int index = 0;
    while (index < CHROMOSOME_LEN) {
        string curString = m_bits.substr(index, GENE_LEN);
        string curElem = m_ga->mapping[curString];
        cout << "CUR_ELEM: " << curElem << endl;
        index += GENE_LEN;
    }
}













