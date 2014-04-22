#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <string>

#define CHROMOSOME_LEN 40

class Chromosome {
    private:
        std::string m_bits;
        double m_fitness;


    public:
        Chromosome();
        Chromosome(std::string bits, double fitness);
        void setToRandom();
        void printBits();

};


#endif
