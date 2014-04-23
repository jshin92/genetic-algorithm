#include "GeneticAlgo.h"
#include "Chromosome.h"
#include <iostream>
#include <string>

#define GIVE_UP_THRESHOLD 400
#define POP_SIZE 1

#include <array>

using namespace std;

void GeneticAlgo::run() {
    cout << "Running..." << endl;

    array<Chromosome, POP_SIZE> c_arr;
    //Chromosome c_arr[POP_SIZE];
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

            if (c.getFitness() == 9999) {
                cout << "Solution found in " << generationCount << 
                " generations." << endl;
                c.printBits();
                done = true;
                break;
            }
        }

        if (done) break;

        array<Chromosome, POP_SIZE> nextGen;
        int newGenCount = 0;

        // keep going until we made POP_SIZE more children
        while (newGenCount < POP_SIZE) {
            // choose two parents to crossover
            /// child1 <- rouletteSelect
            /// child2 <- rouletteSelect

            /// crossover(child1, child2)
            /// mutate(child1)
            /// mutate(child2)

            /// nextGen[newGenCount++] = Chromosome(child1);
            /// nextGen[newGenCount++] = Chromosome(child2);
        }

        // the next generation becomes the new current generation in the next iteration
        c_arr = nextGen; 

        generationCount++;

        if (generationCount > GIVE_UP_THRESHOLD) {
            cout << "No solutions, taking too many iterations..." << endl;
            done = true;
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


