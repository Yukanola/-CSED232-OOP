#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

using std::endl;

class SnackList {

	Snack* Head;
	Snack* Tail;
	int Amounts;

public:

	SnackList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Snack* NewProd);

	void Delete(Snack* TargetProd);

	void dispAllProducts();

	Snack* getProdByID(int id) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Snack* getProdByName(string name) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	SnackList* getProdsByManufacturer(SnackList* Box, string man);

	Snack* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class DrinkList {

	Drink* Head;
	Drink* Tail;
	int Amounts;

public:

	DrinkList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Drink* NewProd);

	void Delete(Drink* TargetProd);

	void dispAllProducts();

	Drink* getProdByID(int id) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Drink* getProdByName(string name) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	DrinkList* getProdsByManufacturer(DrinkList* Box, string man);

	Drink* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class IceList {

	Ice* Head;
	Ice* Tail;
	int Amounts;

public:

	IceList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Ice* NewProd);

	void Delete(Ice* TargetProd);

	void dispAllProducts();

	Ice* getProdByID(int id) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Ice* getProdByName(string name) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	IceList* getProdsByManufacturer(IceList* Box, string man);

	Ice* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class OtherList {

	Other* Head;
	Other* Tail;
	int Amounts;

public:

	OtherList() { this->Amounts = 0; this->Head = NULL; this->Tail = NULL; };

	void Add(Other* NewProd);

	void Delete(Other* TargetProd);

	void dispAllProducts();

	Other* getProdByID(int id) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Other* getProdByName(string name) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	OtherList* getProdsByManufacturer(OtherList* Box, string man);

	Other* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};
