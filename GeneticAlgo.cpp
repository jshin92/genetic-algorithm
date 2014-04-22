#include "GeneticAlgo.h"
#include "Chromosome.h"
#include <iostream>

#define POP_SIZE 3

using namespace std;

GeneticAlgo::GeneticAlgo() { }

void GeneticAlgo::run() {
    cout << "Running..." << endl;

    bool done = false;
    Chromosome c_arr[POP_SIZE];

    for (Chromosome c : c_arr) {
        c.setToRandom();
        c.printBits();
    }
}
