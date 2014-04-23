#include "Chromosome.h"
#include "GeneticAlgo.h"
#include <iostream>
#include <cmath>

#define TARGET 20
#define GENE_LEN 4
#define CROSSOVER_RATE 70 // percentage (e.g. * 100)
#define MUTATION_RATE 1 // percentage

using namespace std;

Chromosome::Chromosome() {
    m_bits = "";
    m_fitness = 0.0;
}

void Chromosome::setGeneticAlgo(GeneticAlgo* ga) {
    m_ga = ga;
}

void Chromosome::getRandomBits() {
    for (int i = 0; i < CHROMOSOME_LEN; i++) {
        int x = rand() % 2;
        m_bits += to_string(x);
    }
}

void Chromosome::printBits() {
    cout << m_bits << endl;
}

bool isNumber(string curElem) {
    return curElem == "0" || curElem == "1" ||
           curElem == "2" || curElem == "3" ||
           curElem == "4" || curElem == "5" || 
           curElem == "6" || curElem == "7" ||
           curElem == "8" || curElem == "9";
}

bool isOp(string curElem) {
    return curElem == "+" || curElem == "-" ||
           curElem == "*" || curElem == "/";
}

void Chromosome::calcFitness() {
    bool expectingNumber = true;
    int index = 0;
    int accum = 0;
    string prevOp = "+";
    while (index < CHROMOSOME_LEN) {
        string curString = m_bits.substr(index, GENE_LEN);
        string curElem = m_ga->mapping[curString];
        if (curElem == "") {
            index += GENE_LEN;
            continue;
        }
        else if (expectingNumber) {
            if (isNumber(curElem)) {
                int curNum = stoi(curElem);
                if (prevOp == "+") accum += curNum;
                else if (prevOp == "-") accum -= curNum;
                else if (prevOp == "*") accum *= curNum;
                else if (prevOp == "/") {
                    // disallow division by zero
                    if (curNum == 0) {
                        cout << "skipping division by zero" << endl;
                        index += GENE_LEN;
                        continue;
                    }
                    accum /= curNum;
                }
                else cerr << "UNEXPECTED OP" << endl;
                expectingNumber = false;
            }
        } else if (!expectingNumber) {
            if (isOp(curElem)) {
                prevOp = curElem;  
                expectingNumber = true;
            }
        }
    
        index += GENE_LEN;
    }

    // exit if we perfectly hit the target 
    if (accum - TARGET == 0) {
        m_fitness = 9999;
        m_ga->done = true;
    }
    m_fitness = 1.0 / abs(accum - TARGET);
    cout << "fitness: " << m_fitness << endl;
    
}

char inverted(char c) {
    return c == '0' ? '1' : '0';
}

void Chromosome::mutate() {
    for (int i = 0; i < CHROMOSOME_LEN; i++) {
        int x = rand() % 100 + 1;
        if (x <= MUTATION_RATE) {
            cout << "mutated a gene" << endl;
            m_bits[i] = inverted(m_bits[i]);
        }
            
    }
}

double Chromosome::getFitness() {
    return m_fitness;
}












