hw2: tjj0013_hw2.o HeartSurgeon.o SurgerySchedule.o Doctor.o
	g++ -o hw2 tjj0013_hw2.o HeartSurgeon.o SurgerySchedule.o Doctor.o

tjj0013_hw2.o: tjj0013_hw2.cpp HeartSurgeon.h
	g++ -c tjj0013_hw2.cpp

HeartSurgeon.o: HeartSurgeon.cpp HeartSurgeon.h
	g++ -c HeartSurgeon.cpp

SurgerySchedule.o: SurgerySchedule.cpp SurgerySchedule.h
	g++ -c SurgerySchedule.cpp

Doctor.o: Doctor.cpp Doctor.h
	g++ -c Doctor.cpp

clean:
	rm *.o hw2
