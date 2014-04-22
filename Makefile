main:
	g++ -std=c++11 Chromosome.cpp GeneticAlgo.cpp main.cpp -o ga

clean:
	rm ga

run:
	./ga

go:
	make clean && make && make run
