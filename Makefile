main:
	g++ -std=c++11 Chromosome.cpp GeneticAlgo.cpp main.cpp -o main

clean:
	rm main

run:
	./main
