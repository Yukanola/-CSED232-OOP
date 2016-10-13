POS: mainFlow_Linux.o Functions_Linux.o Flows_Linux.o ProductFunc_Linux.o ProductListFunc_Linux.o
	@echo "POS Building..."
	g++ -w -o POS mainFlow_Linux.o Functions_Linux.o Flows_Linux.o ProductFunc_Linux.o ProductListFunc_Linux.o
	rm *.o

mainFlow_Linux.o: mainFlow.cpp Functions.cpp Flows.cpp libKano_Linux.h Products_Linux.h ProductList_Linux.h
	tail --bytes=+4 mainFlow.cpp > mainFlow_Linux.cpp
	if [ -a mainFlow_Linux.o ] ; \
	then \
		rm mainFlow_Linux.o ; \
	fi ;
	g++ -w -c mainFlow_Linux.cpp

Functions_Linux.o: Functions.cpp Flows.cpp Products_Linux.h libKano_Linux.h ProductList_Linux.h
	tail --bytes=+4 Functions.cpp > Functions_Linux.cpp
	if [ -a Functions_Linux.o ] ; \
	then \
		rm Functions_Linux.o ; \
	fi ;
	g++ -w -c Functions_Linux.cpp

Flows_Linux.o: Functions.cpp Flows.cpp Products_Linux.h libKano_Linux.h ProductList_Linux.h
	tail --bytes=+4 Flows.cpp > Flows_Linux.cpp
	if [ -a Flows_Linux.o ] ; \
	then \
		rm Flows_Linux.o ; \
	fi ;
	g++ -w -c Flows_Linux.cpp
	
ProductFunc_Linux.o: Products_Linux.h libKano_Linux.h
	tail --bytes=+4 ProductFunc.cpp > ProductFunc_Linux.cpp
	if [ -a ProductFunc_Linux.o ] ; \
	then \
		rm ProductFunc_Linux.o ; \
	fi ;
	g++ -w -c ProductFunc_Linux.cpp
	
ProductListFunc_Linux.o: Products_Linux.h libKano_Linux.h ProductList_Linux.h
	tail --bytes=+4 ProductListFunc.cpp > ProductListFunc_Linux.cpp
	if [ -a ProductListFunc_Linux.o ] ; \
	then \
		rm ProductListFunc_Linux.o ; \
	fi ;
	g++ -w -c ProductListFunc_Linux.cpp
	
Products_Linux.h: Products.h
	tail --bytes=+4 Products.h  > Products_Linux.h
	
ProductList_Linux.h: Products.h ProductList.h
	tail --bytes=+4 ProductList.h > ProductList_Linux.h
	
libKano_Linux.h: libKano.h
	tail --bytes=+4 libKano.h > libKano_Linux.h
	