export PATH := bin:$(PATH)

tsp: main.o enumeration.o nearestNeighbour.o
	g++ -o tsp main.o enumeration.o nearestNeighbour.o

main.o: main.cpp enumeration.cpp nearestNeighbour.cpp
	g++ -c main.cpp enumeration.cpp nearestNeighbour.cpp

clean:
	rm -f *.o tsp