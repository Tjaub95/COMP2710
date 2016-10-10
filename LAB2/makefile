lab2: tjj0013_2.o Menu.o Friends.o Messages.o Hashtags.o Pages.o
	g++ -o lab2 tjj0013_2.o Menu.o Friends.o Messages.o Hashtags.o Pages.o

tjj00113_2.o: tjj0013_2.cpp Menu.h
	g++ -c tjj0013_2.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

Friends.o: Friends.cpp Friends.h
	g++ -c Friends.cpp

Messages.o: Messages.cpp Messages.h
	g++ -c Messages.cpp

Hashtags.o: Hashtags.cpp Hashtags.h
	g++ -c Hashtags.cpp

Pages.o: Pages.cpp Pages.h
	g++ -c Pages.cpp

clean:
	rm *.o lab2
