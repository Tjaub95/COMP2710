lab2: tjj0013_2.o Menu.o Friends.o Messages.o
	g++ -o lab2 tjj0013_2.o Menu.o Friends.o Messages.o

tjj00113_2.o: tjj0013_2.cpp Menu.h
	g++ -c tjj0013_2.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

Friends.o: Friends.cpp Friends.h
	g++ -c Friends.cpp

Messages.o: Messages.cpp Messages.h
	g++ -c Messages.cpp

clean:
	rm *.o lab2
