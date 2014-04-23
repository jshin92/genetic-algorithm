#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#define CHROMOSOME_LEN 40
#include <string>

class GeneticAlgo;
class Chromosome {
    private:
        std::string m_bits;
        double m_fitness;
        GeneticAlgo* m_ga;

    public:
        Chromosome();
        void getRandomBits();
        void printBits();
        void setGeneticAlgo(GeneticAlgo* ga);
        void calcFitness();
        void mutate();
        double getFitness();
};


#endif
