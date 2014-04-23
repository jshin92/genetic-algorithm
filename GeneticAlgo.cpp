#include "GeneticAlgo.h"
#include "Chromosome.h"
#include <iostream>
#include <string>


#define POP_SIZE 1

using namespace std;

void GeneticAlgo::run() {
    cout << "Running..." << endl;

    Chromosome c_arr[POP_SIZE];
    int generationCount = 0;
    // initialize chromosomes with random genes
    for (auto& c : c_arr) {
        c.setGeneticAlgo(this);
        c.getRandomBits();
        c.printBits();
    }
    
    while (!done) {
        done = true;
       
       double totalFitness = 0.0;
        for (auto& c : c_arr) {
            c.calcFitness();            
            totalFitness += c.getFitness();
        }

        

    }
}

GeneticAlgo::GeneticAlgo() {  
    done = false;
    mapping = map<string, string>();
    mapping["0000"] = "0";
    mapping["0001"] = "1";
    mapping["0010"] = "2";
    mapping["0011"] = "3";
    mapping["0100"] = "4";
    mapping["0101"] = "5";
    mapping["0110"] = "6";
    mapping["0111"] = "7";
    mapping["1000"] = "8";
    mapping["1001"] = "9";
    mapping["1010"] = "+";
    mapping["1011"] = "-";
    mapping["1100"] = "*";
    mapping["1101"] = "/";
    // 1110 and 1111 are unused & ignored 
}


