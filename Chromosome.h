#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <string>

class GeneticAlgo;
class Chromosome {
    private:
        std::string m_bits;
        double m_fitness;
        GeneticAlgo* m_ga;

    public:
        Chromosome();
        Chromosome(std::string bits, double fitness);
        void setToRandom();
        void printBits();
        void setGA(GeneticAlgo* ga);
        void calcFitness();
        void mutate();
};


#endif
