POS: mainFlow.o Functions.o Flows.o
	g++ -w -o POS  mainFlow.o Functions.o Flows.o

mainFlow.o: mainFlow.cpp Functions.cpp Flows.cpp libKano.h Products.h
	g++ -w -c mainFlow.cpp

Functions.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -w -c Functions.cpp

Flows.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -w -c Flows.cpp
