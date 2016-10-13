#if _WIN32
#include "libKano.h"
#else
#include "libKano_Linux.h"
#endif

//using std::ostringstream;

class Snack {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Snack* Next;
	Snack* Before;

public:

	Snack(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Snack* aSnack) { this->Next = aSnack; };
	void setBefore(Snack* aSnack) { this->Before = aSnack; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Snack* getNext() { return this->Next; };
	Snack* getBefore() { return this->Before; };


};

class Drink {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Drink* Next;
	Drink* Before;

public:

	Drink(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Drink* aDrink) { this->Next = aDrink; };
	void setBefore(Drink* aDrink) { this->Before = aDrink; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Drink* getNext() { return this->Next; };
	Drink* getBefore() { return this->Before; };

};

class Ice {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Ice* Next;
	Ice* Before;

public:

	Ice(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Ice* anIce) { this->Next = anIce; };
	void setBefore(Ice* anIce) { this->Before = anIce; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Ice* getNext() { return this->Next; };
	Ice* getBefore() { return this->Before; };

};

class Other {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Other* Next;
	Other* Before;

public:

	Other(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Other* aProd) { this->Next = aProd; };
	void setBefore(Other* aProd) { this->Before = aProd; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Other* getNext() { return this->Next; };
	Other* getBefore() { return this->Before; };

};
