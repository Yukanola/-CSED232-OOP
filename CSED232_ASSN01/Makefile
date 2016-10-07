POS: mainFlow.o Functions.o Flows.o
	g++ -std=c++11 -w -o POS  mainFlow.o Functions.o Flows.o

mainFlow.o: mainFlow.cpp Functions.cpp Flows.cpp libKano.h Products.h
	g++ -std=c++11 -w -c mainFlow.cpp

Functions.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -std=c++11 -w -c Functions.cpp

Flows.o: Functions.cpp Flows.cpp Products.h libKano.h
	g++ -std=c++11 -w -c Flows.cpp
