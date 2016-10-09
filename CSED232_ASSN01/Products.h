#include "libKano.h"

using std::endl;
//using std::ostringstream;

class Snack {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Snack* Next = NULL;
	Snack* Before = NULL;

public:

	Snack(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

		this->ID = id;
		this->Name = name;
		this->Stock = amount;
		this->Margin = margin;
		this->PrimeCost = primeCost;
		this->Manufacturer = manufacturer;
		this->SailCost = sailCost;

	};

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

class SnackList {

	Snack* Head = NULL;
	Snack* Tail = NULL;
	int Amounts = 0;

public:

	void Add(Snack* NewProd) {

		if (this->Amounts != 0) {

			this->Tail->setNext(NewProd);

			NewProd->setBefore(this->Tail);

		}
		else
			this->Head = NewProd;

		this->Tail = NewProd;

		this->Amounts += 1;

	};

	void Delete(Snack* TargetProd) {

		if (this->Amounts == 1) {

			this->Head = NULL;
			this->Tail = NULL;

		}
		else if (TargetProd == this->Tail) {

			TargetProd->getBefore()->setNext(NULL);
			this->Tail = NULL;

		}
		else if (TargetProd == this->Head) {

			this->Head = TargetProd->getNext();
			TargetProd->getNext()->setBefore(NULL);

		}
		else {

			TargetProd->getNext()->setBefore(TargetProd->getBefore());
			TargetProd->getBefore()->setNext(TargetProd->getNext());

		}

		this->Amounts -= 1;

		delete TargetProd;

	};

	void dispAllProducts() {

		if (this->Amounts) {

			con.boxOpen();
			con.boxLineCenter("[SNACK]");
			con.boxLine();

			if(isWin) {
				
				printf("│");
				con.printSpace("Prod. ID", 12);
				con.printSpace("Name", 32);
				con.printSpace("Stocks", 16); //60
				con.printSpace("Prime Cost", 15);
				con.printSpace("Margin(%%)", 21);
				con.printSpace("Sail Cost", 15); //110
				con.printSpace("Manufacturer", 26);
				printf("│\n");
				con.boxLine();
				
			}
			else if (isLinux) {
				
				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");
				
			}

			for (Snack* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

				if(isWin) {
					
					printf("│");
					con.printSpace(to_string(Queue->getID()), 12);
					con.printSpace(Queue->getName(), 32);
					con.printSpace(to_string(Queue->getStock()), 16); //60
					con.printSpace(to_string(Queue->getPrimeCost()), 15);
					con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
					con.printSpace(to_string(Queue->getSailCost()), 15); //110
					con.printSpace(Queue->getManufacturer(), 26);
					printf("│\n");
					
				}
				else if (isLinux) {
					
					con.boxLine(to_string(Queue->getID()) + ", " + Queue->getName() + ", " + to_string(Queue->getStock()) + ", " + to_string(Queue->getPrimeCost()) + ", " + to_string((int)(Queue->getMargin() * 100)) + ", " + to_string(Queue->getSailCost()) + ", " + Queue->getManufacturer());
					
				}

			};

			con.boxClose();

		}

	};

	Snack* getProdByID(int id) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Snack* getProdByName(string name) { Snack* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	SnackList* getProdsByManufacturer(SnackList* Box, string man) {

		Snack* TargetSnack = this->Head;

		for (int i = 0; i < this->Amounts; i++) {
			if (TargetSnack->getManufacturer() == man) {

				Snack* copySnack = new Snack(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

				Box->Add(copySnack);

			}

			TargetSnack = TargetSnack->getNext();

		};

		return Box;

	};

	Snack* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class Drink {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Drink* Next = NULL;
	Drink* Before = NULL;

public:

	Drink(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

		this->ID = id;
		this->Name = name;
		this->Stock = amount;
		this->Margin = margin;
		this->PrimeCost = primeCost;
		this->Manufacturer = manufacturer;
		this->SailCost = sailCost;

	};

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

class DrinkList {

	Drink* Head = NULL;
	Drink* Tail = NULL;
	int Amounts = 0;

public:

	void Add(Drink* NewProd) {

		if (this->Amounts != 0) {

			this->Tail->setNext(NewProd);

			NewProd->setBefore(this->Tail);

		}
		else
			this->Head = NewProd;

		this->Tail = NewProd;

		this->Amounts += 1;

	};

	void Delete(Drink* TargetProd) {

		if (this->Amounts == 1) {

			this->Head = NULL;
			this->Tail = NULL;

		}
		else if (TargetProd == this->Tail) {

			TargetProd->getBefore()->setNext(NULL);
			this->Tail = NULL;

		}
		else if (TargetProd == this->Head) {

			this->Head = TargetProd->getNext();
			TargetProd->getNext()->setBefore(NULL);

		}
		else {

			TargetProd->getNext()->setBefore(TargetProd->getBefore());
			TargetProd->getBefore()->setNext(TargetProd->getNext());

		}

		this->Amounts -= 1;

		delete TargetProd;

	};

	void dispAllProducts() {

		if (this->Amounts) {

			con.boxOpen();
			con.boxLineCenter("[DRINK]");
			con.boxLine();

			if(isWin) {
				
				printf("│");
				con.printSpace("Prod. ID", 12);
				con.printSpace("Name", 32);
				con.printSpace("Stocks", 16); //60
				con.printSpace("Prime Cost", 15);
				con.printSpace("Margin(%%)", 21);
				con.printSpace("Sail Cost", 15); //110
				con.printSpace("Manufacturer", 26);
				printf("│\n");
				con.boxLine();
				
			}
			else if (isLinux) {
				
				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");
				
			}

			for (Drink* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

				if(isWin) {
					
					printf("│");
					con.printSpace(to_string(Queue->getID()), 12);
					con.printSpace(Queue->getName(), 32);
					con.printSpace(to_string(Queue->getStock()), 16); //60
					con.printSpace(to_string(Queue->getPrimeCost()), 15);
					con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
					con.printSpace(to_string(Queue->getSailCost()), 15); //110
					con.printSpace(Queue->getManufacturer(), 26);
					printf("│\n");
					
				}
				else if (isLinux) {
					
					con.boxLine(to_string(Queue->getID()) + ", " + Queue->getName() + ", " + to_string(Queue->getStock()) + ", " + to_string(Queue->getPrimeCost()) + ", " + to_string((int)(Queue->getMargin() * 100)) + ", " + to_string(Queue->getSailCost()) + ", " + Queue->getManufacturer());
					
				}

			};

			con.boxClose();

		}

	}; 

	Drink* getProdByID(int id) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Drink* getProdByName(string name) { Drink* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	DrinkList* getProdsByManufacturer(DrinkList* Box, string man) {

		Drink* TargetSnack = this->Head;

		for (int i = 0; i < this->Amounts; i++) {
			if (TargetSnack->getManufacturer() == man) {

				Drink* copySnack = new Drink(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

				Box->Add(copySnack);

			}

			TargetSnack = TargetSnack->getNext();

		}

		return Box;

	};

	Drink* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class Ice {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Ice* Next = NULL;
	Ice* Before = NULL;

public:

	Ice(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

		this->ID = id;
		this->Name = name;
		this->Stock = amount;
		this->Margin = margin;
		this->PrimeCost = primeCost;
		this->Manufacturer = manufacturer;
		this->SailCost = sailCost;

	};

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

class IceList {

	Ice* Head = NULL;
	Ice* Tail = NULL;
	int Amounts = 0;

public:

	void Add(Ice* NewProd) {

		if (this->Amounts != 0) {

			this->Tail->setNext(NewProd);

			NewProd->setBefore(this->Tail);

		}
		else
			this->Head = NewProd;

		this->Tail = NewProd;

		this->Amounts += 1;

	};

	void Delete(Ice* TargetProd) {

		if (this->Amounts == 1) {

			this->Head = NULL;
			this->Tail = NULL;

		}
		else if (TargetProd == this->Tail) {

			TargetProd->getBefore()->setNext(NULL);
			this->Tail = NULL;

		}
		else if (TargetProd == this->Head) {

			this->Head = TargetProd->getNext();
			TargetProd->getNext()->setBefore(NULL);

		}
		else {

			TargetProd->getNext()->setBefore(TargetProd->getBefore());
			TargetProd->getBefore()->setNext(TargetProd->getNext());

		}

		this->Amounts -= 1;

		delete TargetProd;

	};

	void dispAllProducts() {

		if (this->Amounts) {

			con.boxOpen();
			con.boxLineCenter("[ICE]");
			con.boxLine();

			if(isWin) {
				
				printf("│");
				con.printSpace("Prod. ID", 12);
				con.printSpace("Name", 32);
				con.printSpace("Stocks", 16); //60
				con.printSpace("Prime Cost", 15);
				con.printSpace("Margin(%%)", 21);
				con.printSpace("Sail Cost", 15); //110
				con.printSpace("Manufacturer", 26);
				printf("│\n");
				con.boxLine();
				
			}
			else if (isLinux) {
				
				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");
				
			}

			for (Ice* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

				if(isWin) {
					
					printf("│");
					con.printSpace(to_string(Queue->getID()), 12);
					con.printSpace(Queue->getName(), 32);
					con.printSpace(to_string(Queue->getStock()), 16); //60
					con.printSpace(to_string(Queue->getPrimeCost()), 15);
					con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
					con.printSpace(to_string(Queue->getSailCost()), 15); //110
					con.printSpace(Queue->getManufacturer(), 26);
					printf("│\n");
					
				}
				else if (isLinux) {
					
					con.boxLine(to_string(Queue->getID()) + ", " + Queue->getName() + ", " + to_string(Queue->getStock()) + ", " + to_string(Queue->getPrimeCost()) + ", " + to_string((int)(Queue->getMargin() * 100)) + ", " + to_string(Queue->getSailCost()) + ", " + Queue->getManufacturer());
					
				}

			};

			con.boxClose();

		}

	};

	Ice* getProdByID(int id) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Ice* getProdByName(string name) { Ice* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	IceList* getProdsByManufacturer(IceList* Box, string man) {

		Ice* TargetSnack = this->Head;

		for (int i = 0; i < this->Amounts; i++) {
			if (TargetSnack->getManufacturer() == man) {

				Ice* copySnack = new Ice(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

				Box->Add(copySnack);

			}

			TargetSnack = TargetSnack->getNext();

		}

		return Box;

	};

	Ice* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};

class Other {

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Other* Next = NULL;
	Other* Before = NULL;

public:

	Other(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer) {

		this->ID = id;
		this->Name = name;
		this->Stock = amount;
		this->Margin = margin;
		this->PrimeCost = primeCost;
		this->Manufacturer = manufacturer;
		this->SailCost = sailCost;

	};

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

class OtherList {

	Other* Head = NULL;
	Other* Tail = NULL;
	int Amounts = 0;

public:

	void Add(Other* NewProd) {

		if (this->Amounts != 0) {

			this->Tail->setNext(NewProd);

			NewProd->setBefore(this->Tail);

		}
		else
			this->Head = NewProd;

		this->Tail = NewProd;

		this->Amounts += 1;

	};

	void Delete(Other* TargetProd) {

		if (this->Amounts == 1) {

			this->Head = NULL;
			this->Tail = NULL;

		}
		else if (TargetProd == this->Tail) {

			TargetProd->getBefore()->setNext(NULL);
			this->Tail = NULL;

		}
		else if (TargetProd == this->Head) {

			this->Head = TargetProd->getNext();
			TargetProd->getNext()->setBefore(NULL);

		}
		else {

			TargetProd->getNext()->setBefore(TargetProd->getBefore());
			TargetProd->getBefore()->setNext(TargetProd->getNext());

		}

		this->Amounts -= 1;

		delete TargetProd;

	};

	void dispAllProducts() {

		if (this->Amounts) {

			con.boxOpen();
			con.boxLineCenter("[OTHER]");
			con.boxLine();

			if(isWin) {
				
				printf("│");
				con.printSpace("Prod. ID", 12);
				con.printSpace("Name", 32);
				con.printSpace("Stocks", 16); //60
				con.printSpace("Prime Cost", 15);
				con.printSpace("Margin(%%)", 21);
				con.printSpace("Sail Cost", 15); //110
				con.printSpace("Manufacturer", 26);
				printf("│\n");
				con.boxLine();
				
			}
			else if (isLinux) {
				
				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");
				
			}
			

			for (Other* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

				if(isWin) {
					
					printf("│");
					con.printSpace(to_string(Queue->getID()), 12);
					con.printSpace(Queue->getName(), 32);
					con.printSpace(to_string(Queue->getStock()), 16); //60
					con.printSpace(to_string(Queue->getPrimeCost()), 15);
					con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
					con.printSpace(to_string(Queue->getSailCost()), 15); //110
					con.printSpace(Queue->getManufacturer(), 26);
					printf("│\n");
					
				}
				else if (isLinux) {
					
					con.boxLine(to_string(Queue->getID()) + ", " + Queue->getName() + ", " + to_string(Queue->getStock()) + ", " + to_string(Queue->getPrimeCost()) + ", " + to_string((int)(Queue->getMargin() * 100)) + ", " + to_string(Queue->getSailCost()) + ", " + Queue->getManufacturer());
					
				}
				
			};

			con.boxClose();

		}

	};

	Other* getProdByID(int id) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getID() != id; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	Other* getProdByName(string name) { Other* TargetSnack = this->Head;  for (; TargetSnack != NULL && TargetSnack->getName() != name; TargetSnack = TargetSnack->getNext()); return TargetSnack; };

	OtherList* getProdsByManufacturer(OtherList* Box, string man) {

		Other* TargetSnack = this->Head;

		for (int i = 0; i < this->Amounts; i++) {
			if (TargetSnack->getManufacturer() == man) {

				Other* copySnack = new Other(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

				Box->Add(copySnack);

			}

			TargetSnack = TargetSnack->getNext();

		}

		return Box;

	};

	Other* getHead() { return this->Head; };

	int getAmounts() { return this->Amounts; };

};