#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

Snack::Snack(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

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

Drink::Drink(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

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

Ice::Ice(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

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

Other::Other(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

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
