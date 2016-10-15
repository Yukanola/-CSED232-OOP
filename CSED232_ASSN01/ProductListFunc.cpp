#if _WIN32
#include "ProductList.h"
#else
#include "ProductList_Linux.h"
#endif

void SnackList::Add(Snack* NewProd) {

	deb("Starts to add a snack.");

	if (this->Amounts != 0) {

		deb("Snack is not alone.");

		this->Tail->setNext(NewProd);

		NewProd->setBefore(this->Tail);

	}
	else
		this->Head = NewProd;

	this->Tail = NewProd;

	this->Amounts += 1;

};

void SnackList::Delete(Snack* TargetProd) {

	if (this->Amounts == 1) {

		deb("Amount is 1.");

		this->Head = NULL;
		this->Tail = NULL;

	}
	else if (TargetProd == this->Tail) {

		deb("This is Tail.");

		TargetProd->getBefore()->setNext(NULL);
		this->Tail = TargetProd->getBefore();

	}
	else if (TargetProd == this->Head) {

		deb("This is Head.");

		this->Head = TargetProd->getNext();
		TargetProd->getNext()->setBefore(NULL);

	}
	else {

		deb("This is middle of List.");

		TargetProd->getNext()->setBefore(TargetProd->getBefore());
		TargetProd->getBefore()->setNext(TargetProd->getNext());

	}

	this->Amounts -= 1;

	delete TargetProd;

};

void SnackList::dispAllProducts() {

	if(isWin)
		con.setCS(140, 35);

	if (this->Amounts) {

		con.boxOpen();
		con.boxLineCenter("[SNACK]");
		con.boxLine();

		if (isWin) {

			printf((isMGW) ? "|" : "│");
			con.printSpace("Prod. ID", 12);
			con.printSpace("Name", 32);
			con.printSpace("Stocks", 16); //60
			con.printSpace("Prime Cost", 15);
			con.printSpace("Margin(%%)", 21);
			con.printSpace("Sail Cost", 15); //110
			con.printSpace("Manufacturer", 25);
			printf((isMGW) ? "|\n" : "│\n");
			con.boxLine();

		}
		else if (isLinux) {

			con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

		}

		for (Snack* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(Queue->getID()), 12);
				con.printSpace(Queue->getName(), 32);
				con.printSpace(to_string(Queue->getStock()), 16); //60
				con.printSpace(to_string(Queue->getPrimeCost()), 15);
				con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
				con.printSpace(to_string(Queue->getSailCost()), 15); //110
				con.printSpace(Queue->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", " << Queue->getManufacturer().c_str() << endl;

			}

		};

		con.boxClose();

	}

};

SnackList* SnackList::getProdsByManufacturer(SnackList* Box, string man) {

	Snack* TargetSnack = this->Head;

	for (int i = 0; i < this->Amounts; i++) {
		if (NULL != strstr(TargetSnack->getManufacturer().c_str(), man.c_str())) {

			Snack* copySnack = new Snack(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

			Box->Add(copySnack);

		}

		TargetSnack = TargetSnack->getNext();

	};

	return Box;

};

void DrinkList::Add(Drink* NewProd) {

	if (this->Amounts != 0) {

		this->Tail->setNext(NewProd);

		NewProd->setBefore(this->Tail);

	}
	else
		this->Head = NewProd;

	this->Tail = NewProd;

	this->Amounts += 1;

};

void DrinkList::Delete(Drink* TargetProd) {

	if (this->Amounts == 1) {

		deb("Amount is 1.");

		this->Head = NULL;
		this->Tail = NULL;

	}
	else if (TargetProd == this->Tail) {

		deb("This is Tail.");

		TargetProd->getBefore()->setNext(NULL);
		this->Tail = TargetProd->getBefore();

	}
	else if (TargetProd == this->Head) {

		deb("This is Head.");

		this->Head = TargetProd->getNext();
		TargetProd->getNext()->setBefore(NULL);

	}
	else {

		deb("This is middle of List.");

		TargetProd->getNext()->setBefore(TargetProd->getBefore());
		TargetProd->getBefore()->setNext(TargetProd->getNext());

	}

	this->Amounts -= 1;

	delete TargetProd;

};

void DrinkList::dispAllProducts() {

	if(isWin)
		con.setCS(140, 35);

	if (this->Amounts) {

		con.boxOpen();
		con.boxLineCenter("[DRINK]");
		con.boxLine();

		if (isWin) {

			printf((isMGW) ? "|" : "│");
			con.printSpace("Prod. ID", 12);
			con.printSpace("Name", 32);
			con.printSpace("Stocks", 16); //60
			con.printSpace("Prime Cost", 15);
			con.printSpace("Margin(%%)", 21);
			con.printSpace("Sail Cost", 15); //110
			con.printSpace("Manufacturer", 25);
			printf((isMGW) ? "|\n" : "│\n");
			con.boxLine();

		}
		else if (isLinux) {

			con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

		}

		for (Drink* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(Queue->getID()), 12);
				con.printSpace(Queue->getName(), 32);
				con.printSpace(to_string(Queue->getStock()), 16); //60
				con.printSpace(to_string(Queue->getPrimeCost()), 15);
				con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
				con.printSpace(to_string(Queue->getSailCost()), 15); //110
				con.printSpace(Queue->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", " << Queue->getManufacturer().c_str() << endl;

			}

		};

		con.boxClose();

	}

};

DrinkList* DrinkList::getProdsByManufacturer(DrinkList* Box, string man) {

	Drink* TargetSnack = this->Head;

	for (int i = 0; i < this->Amounts; i++) {
		if (NULL != strstr(TargetSnack->getManufacturer().c_str(), man.c_str())) {

			Drink* copySnack = new Drink(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

			Box->Add(copySnack);

		}

		TargetSnack = TargetSnack->getNext();

	}

	return Box;

};

void IceList::Add(Ice* NewProd) {

	if (this->Amounts != 0) {

		this->Tail->setNext(NewProd);

		NewProd->setBefore(this->Tail);

	}
	else
		this->Head = NewProd;

	this->Tail = NewProd;

	this->Amounts += 1;

};

void IceList::Delete(Ice* TargetProd) {

	if (this->Amounts == 1) {

		deb("Amount is 1.");

		this->Head = NULL;
		this->Tail = NULL;

	}
	else if (TargetProd == this->Tail) {

		deb("This is Tail.");

		TargetProd->getBefore()->setNext(NULL);
		this->Tail = TargetProd->getBefore();

	}
	else if (TargetProd == this->Head) {

		deb("This is Head.");

		this->Head = TargetProd->getNext();
		TargetProd->getNext()->setBefore(NULL);

	}
	else {

		deb("This is middle of List.");

		TargetProd->getNext()->setBefore(TargetProd->getBefore());
		TargetProd->getBefore()->setNext(TargetProd->getNext());

	}

	this->Amounts -= 1;

	delete TargetProd;

};

void IceList::dispAllProducts() {

	if(isWin)
		con.setCS(140, 35);

	if (this->Amounts) {

		con.boxOpen();
		con.boxLineCenter("[ICE]");
		con.boxLine();

		if (isWin) {

			printf((isMGW) ? "|" : "│");
			con.printSpace("Prod. ID", 12);
			con.printSpace("Name", 32);
			con.printSpace("Stocks", 16); //60
			con.printSpace("Prime Cost", 15);
			con.printSpace("Margin(%%)", 21);
			con.printSpace("Sail Cost", 15); //110
			con.printSpace("Manufacturer", 25);
			printf((isMGW) ? "|\n" : "│\n");
			con.boxLine();

		}
		else if (isLinux) {

			con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

		}

		for (Ice* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(Queue->getID()), 12);
				con.printSpace(Queue->getName(), 32);
				con.printSpace(to_string(Queue->getStock()), 16); //60
				con.printSpace(to_string(Queue->getPrimeCost()), 15);
				con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
				con.printSpace(to_string(Queue->getSailCost()), 15); //110
				con.printSpace(Queue->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", " << Queue->getManufacturer().c_str() << endl;

			}

		};

		con.boxClose();

	}

};

IceList* IceList::getProdsByManufacturer(IceList* Box, string man) {

	Ice* TargetSnack = this->Head;

	for (int i = 0; i < this->Amounts; i++) {
		if (NULL != strstr(TargetSnack->getManufacturer().c_str(), man.c_str())) {

			Ice* copySnack = new Ice(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

			Box->Add(copySnack);

		}

		TargetSnack = TargetSnack->getNext();

	}

	return Box;

};

void OtherList::Add(Other* NewProd) {

	if (this->Amounts != 0) {

		this->Tail->setNext(NewProd);

		NewProd->setBefore(this->Tail);

	}
	else
		this->Head = NewProd;

	this->Tail = NewProd;

	this->Amounts += 1;

};

void OtherList::Delete(Other* TargetProd) {

	if (this->Amounts == 1) {

		deb("Amount is 1.");

		this->Head = NULL;
		this->Tail = NULL;

	}
	else if (TargetProd == this->Tail) {

		deb("This is Tail.");

		TargetProd->getBefore()->setNext(NULL);
		this->Tail = TargetProd->getBefore();

	}
	else if (TargetProd == this->Head) {

		deb("This is Head.");

		this->Head = TargetProd->getNext();
		TargetProd->getNext()->setBefore(NULL);

	}
	else {

		deb("This is middle of List.");

		TargetProd->getNext()->setBefore(TargetProd->getBefore());
		TargetProd->getBefore()->setNext(TargetProd->getNext());

	}

	this->Amounts -= 1;

	delete TargetProd;

};

void OtherList::dispAllProducts() {

	if(isWin)
		con.setCS(140, 35);

	if (this->Amounts) {

		con.boxOpen();
		con.boxLineCenter("[OTHER]");
		con.boxLine();

		if (isWin) {

			printf((isMGW) ? "|" : "│");
			con.printSpace("Prod. ID", 12);
			con.printSpace("Name", 32);
			con.printSpace("Stocks", 16); //60
			con.printSpace("Prime Cost", 15);
			con.printSpace("Margin(%%)", 21);
			con.printSpace("Sail Cost", 15); //110
			con.printSpace("Manufacturer", 25);
			printf((isMGW) ? "|\n" : "│\n");
			con.boxLine();

		}
		else if (isLinux) {

			con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

		}


		for (Other* Queue = this->Head; Queue != NULL; Queue = Queue->getNext()) {

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(Queue->getID()), 12);
				con.printSpace(Queue->getName(), 32);
				con.printSpace(to_string(Queue->getStock()), 16); //60
				con.printSpace(to_string(Queue->getPrimeCost()), 15);
				con.printSpace(to_string((int)(Queue->getMargin() * 100)), 20);
				con.printSpace(to_string(Queue->getSailCost()), 15); //110
				con.printSpace(Queue->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", " << Queue->getManufacturer().c_str() << endl;

			}

		};

		con.boxClose();

	}

};

OtherList* OtherList::getProdsByManufacturer(OtherList* Box, string man) {

	Other* TargetSnack = this->Head;

	for (int i = 0; i < this->Amounts; i++) {
		if (NULL != strstr(TargetSnack->getManufacturer().c_str(), man.c_str())) {

			Other* copySnack = new Other(TargetSnack->getID(), TargetSnack->getName(), TargetSnack->getStock(), TargetSnack->getPrimeCost(), TargetSnack->getMargin(), TargetSnack->getSailCost(), TargetSnack->getManufacturer());

			Box->Add(copySnack);

		}

		TargetSnack = TargetSnack->getNext();

	}

	return Box;

};
