POS: mainFlow.o Functions.o Flows.o
	g++ -o POS  mainFlow.o Functions.o Flows.o

mainFlow.o: mainFlow.cpp Functions.cpp Flows.cpp libKano.h Products.h
	g++ -c mainFlow.cpp

Functions.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -c Functions.cpp

Flows.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -c Flows.cpp
