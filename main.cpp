#include <iostream>
#include "GeneticAlgo.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    GeneticAlgo g;
    g.run();
}
