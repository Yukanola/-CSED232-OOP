#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

Snack::Snack(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {	// Snack의 생성자로, 기본 값들을 설정하는 기능을 가지고 있다.

	this->ID = id;
	this->Name = name;
	this->Stock = amount;
	this->Margin = margin;
	this->PrimeCost = primeCost;
	this->Manufacturer = manufacturer;
	this->SailCost = sailCost;
	this->Next = NULL;
	this->Before = NULL;

};

Drink::Drink(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {	// Snack 참조.

	this->ID = id;
	this->Name = name;
	this->Stock = amount;
	this->Margin = margin;
	this->PrimeCost = primeCost;
	this->Manufacturer = manufacturer;
	this->SailCost = sailCost;
	this->Next = NULL;
	this->Before = NULL;

};

Ice::Ice(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {	// Snack 참조.

	this->ID = id;
	this->Name = name;
	this->Stock = amount;
	this->Margin = margin;
	this->PrimeCost = primeCost;
	this->Manufacturer = manufacturer;
	this->SailCost = sailCost;
	this->Next = NULL;
	this->Before = NULL;

};

Other::Other(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {	// Snack 참조.

	this->ID = id;
	this->Name = name;
	this->Stock = amount;
	this->Margin = margin;
	this->PrimeCost = primeCost;
	this->Manufacturer = manufacturer;
	this->SailCost = sailCost;
	this->Next = NULL;
	this->Before = NULL;

};
