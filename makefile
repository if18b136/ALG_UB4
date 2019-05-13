tsp: main.o
	g++ -o tsp main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o tsp