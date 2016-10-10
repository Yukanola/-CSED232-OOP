POS: mainFlow_Linux.o Functions_Linux.o Flows_Linux.o
	@echo "POS Building..."
	g++ -w -o POS mainFlow_Linux.o Functions_Linux.o Flows_Linux.o

mainFlow_Linux.o: mainFlow.cpp Functions.cpp Flows.cpp libKano_Linux.h Products_Linux.h
	tail --bytes=+4 mainFlow.cpp > mainFlow_Linux.cpp
	g++ -w -c mainFlow_Linux.cpp

Functions_Linux.o: Functions.cpp Flows.cpp Products_Linux.h libKano_Linux.h
	tail --bytes=+4 Functions.cpp > Functions_Linux.cpp
	g++ -w -c Functions_Linux.cpp

Flows_Linux.o: Functions.cpp Flows.cpp Products_Linux.h libKano_Linux.h
	tail --bytes=+4 Flows.cpp > Flows_Linux.cpp
	g++ -w -c Flows_Linux.cpp
	
Products_Linux.h: Products.h
	tail --bytes=+4 Products.h  > Products_Linux.h
	
libKano_Linux.h: libKano.h
	tail --bytes=+4 libKano.h > libKano_Linux.h
	
	