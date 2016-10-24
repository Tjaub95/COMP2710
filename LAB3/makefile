lab3: tjj0013_3.o Menu.o Node.o
	g++ -o lab3 tjj0013_3.o Menu.o Node.o

tjj00113_3.o: tjj0013_3.cpp Menu.h
	g++ -c tjj0013_3.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *.o lab3
