﻿#if _WIN32
#include "ProductList.h"
#else
#include "ProductList_Linux.h"
#endif

#include <fstream>

using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;

void dispAllProducts(SnackList*, DrinkList*, IceList*, OtherList*);
void procSale(SnackList*, DrinkList*, IceList*, OtherList*);    
void procStock(SnackList*, DrinkList*, IceList*, OtherList*);
int* dispSearch(SnackList*, DrinkList*, IceList*, OtherList*, bool);
void procModify(SnackList*, DrinkList*, IceList*, OtherList*);
void procRemove(SnackList*, DrinkList*, IceList*, OtherList*);
void endPOS(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others, char* firstArg);
void dispRecord();

bool dispMenu(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	static bool sync = 0;

	cls();

	con.csSize(42, 18);

	if (sync) {

		con.boxOpen();
		con.boxLine("Invalid Menu Selection.");
		con.boxClose();

	}

	sync = false;

	con.boxOpen();
	con.boxLineCenter("[MENU]");
	con.boxLine();
	con.boxLine("0: Show all products");
	con.boxLine("1: Selling");
	con.boxLine("2: Receiving");
	con.boxLine("3: Product Search");
	con.boxLine("4: Modify Product Information");
	con.boxLine("5: Remove Product Information");
	con.boxLine("6: Show selling records");
	con.boxLine("7 : EXIT");
	con.boxClose();

	int input;

	cout << " Select Menu : ";

	cin >> input;

	switch (input) {

	case 0:
		dispAllProducts(Snacks, Drinks, Ices, Others);
		break;
	case 1:
		procSale(Snacks, Drinks, Ices, Others);
		break;
	case 2:
		procStock(Snacks, Drinks, Ices, Others);
		break;
	case 3:
		dispSearch(Snacks, Drinks, Ices, Others, false);
		break;
	case 4:
		procModify(Snacks, Drinks, Ices, Others);
		break;
	case 5:
		procRemove(Snacks, Drinks, Ices, Others);
		break;
	case 6:
		dispRecord();
		break;
	case 7:
		return false;
		break;
	default:
		sync = true;
		break;
	}
	
	return true;

};

void dispAllProducts(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	cls();

	con.csSize(140, 45);

	Snacks->dispAllProducts();

	if (Snacks->getAmounts() > 15) {

		con.boxOpen();
		con.boxLine(to_string(Snacks->getAmounts() + Drinks->getAmounts() + Ices->getAmounts() + Others->getAmounts()) + " product(s) found.");
		con.boxClose();

		con.csPause();

		cls();

	}

	Drinks->dispAllProducts();

	if (Drinks->getAmounts() > 15) {

		con.boxOpen();
		con.boxLine(to_string(Snacks->getAmounts() + Drinks->getAmounts() + Ices->getAmounts() + Others->getAmounts()) + " product(s) found.");
		con.boxClose();

		con.csPause();

		cls();

	}

	Ices->dispAllProducts();

	if (Ices->getAmounts() > 15) {

		con.boxOpen();
		con.boxLine(to_string(Snacks->getAmounts() + Drinks->getAmounts() + Ices->getAmounts() + Others->getAmounts()) + " product(s) found.");
		con.boxClose();

		con.csPause();

		cls();

	}

	Others->dispAllProducts();

	con.boxOpen();
	con.boxLine(to_string(Snacks->getAmounts() + Drinks->getAmounts() + Ices->getAmounts() + Others->getAmounts()) + " product(s) found.");
	con.boxClose();

	con.csPause();

}

void endPOS(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	endPOS(Snacks, Drinks, Ices, Others, "product.txt");

}

void endPOS(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others, char* firstArg) {

	con.csSize(80, 24);

	ofstream Products(firstArg, std::ios::trunc);

	deb("POS Shut down process started.");

	Products << "-SNACK-" << endl;

	for (Snack* aSnack = Snacks->getHead(); aSnack != NULL; aSnack = aSnack->getNext())
		Products << aSnack->getID() << " " + aSnack->getName()+ " " << aSnack->getStock() << " " << aSnack->getPrimeCost() << " " << aSnack->getMargin() << " " << aSnack->getSailCost() << " " << aSnack->getManufacturer() << endl;

	for (; Snacks->getAmounts() != 0;)
		Snacks->Delete(Snacks->getHead());

	deb("Snacks Deleted.");

	Products << "-DRINK-" << endl;

	for (Drink* aSnack = Drinks->getHead(); aSnack != NULL; aSnack = aSnack->getNext())
		Products << aSnack->getID() << " " + aSnack->getName() + " " << aSnack->getStock() << " " << aSnack->getPrimeCost() << " " << aSnack->getMargin() << " " << aSnack->getSailCost() << " " << aSnack->getManufacturer() << endl;

	for (; Drinks->getAmounts() != 0;)
		Drinks->Delete(Drinks->getHead());

	deb("Drinks Deleted.");

	Products << "-ICE-" << endl;

	for (Ice* aSnack = Ices->getHead(); aSnack != NULL; aSnack = aSnack->getNext())
		Products << aSnack->getID() << " " + aSnack->getName() + " " << aSnack->getStock() << " " << aSnack->getPrimeCost() << " " << aSnack->getMargin() << " " << aSnack->getSailCost() << " " << aSnack->getManufacturer() << endl;

	for (; Ices->getAmounts() != 0;)
		Ices->Delete(Ices->getHead());

	deb("Ices Deleted.");

	Products << "-OTHER-" << endl;

	for (Other* aSnack = Others->getHead(); aSnack != NULL; aSnack = aSnack->getNext())
		Products << aSnack->getID() << " " + aSnack->getName() + " " << aSnack->getStock() << " " << aSnack->getPrimeCost() << " " << aSnack->getMargin() << " " << aSnack->getSailCost() << " " << aSnack->getManufacturer() << endl;

	for (; Others->getAmounts() != 0;)
		Others->Delete(Others->getHead());

	deb("Others Deleted.");

	delete Snacks, Drinks, Ices, Others;

	if (_Kano::isDev)
		con.csPause();

	con.csSize(20, 3);

	color(BLACK, CYAN);

	cout << endl;

	con.printSpaceCenter("Thank You.");
	
	cout << endl;

	con.csDelay(2);

	color(DEFAULTBACK, DEFAULTFONT);

	cls();

}

Other* makeProd(int id, string name, int stock, int pCost, float margin, int sCost, string man) {

	return new Other(id, name, stock, pCost, margin, sCost, man);

}

int* dispSearch(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others, bool Mode) {

	if (!Mode) {

		cls();
		con.csSize(140, 30);

	}
	else
		con.setCS(140, 30);

	int Temp = 0, sort = 0;
	static int retVal[2] = {-1, -1}; // {id, type}

	string TempStr;

	Snack* aSnack;
	Drink* aDrink;
	Ice* anIce;
	Other *aProd, *targetProd;
	SnackList* sSnacks = new SnackList();
	DrinkList* sDrinks = new DrinkList();
	IceList* sIces = new IceList();
	OtherList *sOthers = new OtherList();

	con.boxOpen();
	con.boxLineCenter("[Product Search]");
	con.boxLine();
	con.boxLine("Select the way of searching.");
	con.boxClose();
	con.boxOpen();
	con.boxLineCenter((Mode) ? "1. Prod. ID    2. Name" : "1. Prod. ID    2. Name    3. Manufacturer");
	con.boxClose();
	
	cout << " Way of searching: ";
	cin >> Temp;

	cout << endl;

	if (Temp == 1) {

		cout << " ID: ";
		cin >> Temp;

		if (Temp <= 0) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine();
			con.boxLine("ID cannot be lower than 1.");
			con.boxClose();

			con.csPause();

			delete sSnacks, sDrinks, sIces, sOthers;

			return retVal;

		}

		if ((aSnack = Snacks->getProdByID(Temp)) && aSnack->getID() == Temp) {

			deb("It\'s a Snack!");

			targetProd = makeProd(aSnack->getID(), aSnack->getName(), aSnack->getStock(), aSnack->getPrimeCost(), aSnack->getMargin(), aSnack->getSailCost(), aSnack->getManufacturer());

			sort = 2;

		}
		else if ((aDrink = Drinks->getProdByID(Temp)) && aDrink->getID() == Temp) {

			deb("It\'s a Drink!");

			targetProd = makeProd(aDrink->getID(), aDrink->getName(), aDrink->getStock(), aDrink->getPrimeCost(), aDrink->getMargin(), aDrink->getSailCost(), aDrink->getManufacturer());

			sort = 3;

		}
		else if ((anIce = Ices->getProdByID(Temp)) && anIce->getID() == Temp) {

			deb("It\'s an Ice!");

			targetProd = makeProd(anIce->getID(), anIce->getName(), anIce->getStock(), anIce->getPrimeCost(), anIce->getMargin(), anIce->getSailCost(), anIce->getManufacturer());

			sort = 4;

		}
		else if ((aProd = Others->getProdByID(Temp)) && aProd->getID() == Temp) {

			deb("It\'s a Product!");

			sort = 5;

			targetProd = aProd;

		}

		if (Mode)
			cls();

		con.boxOpen();
		con.boxLineCenter("[Search Result]");
		con.boxLine();
		
		if (sort) {

			con.boxLine("1 product found.");
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

			}
			else if (isLinux) {

				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

			}

			con.boxLine();

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(targetProd->getID()), 12);
				con.printSpace(targetProd->getName(), 32);
				con.printSpace(to_string(targetProd->getStock()), 16);
				con.printSpace(to_string(targetProd->getPrimeCost()), 15);
				con.printSpace(to_string((int)(targetProd->getMargin() * 100)), 20);
				con.printSpace(to_string(targetProd->getSailCost()), 15);
				con.printSpace(targetProd->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(targetProd->getID()).c_str() << ", " << targetProd->getName().c_str() << ", " << to_string(targetProd->getStock()).c_str() << ", " << to_string(targetProd->getPrimeCost()).c_str() << ", " << to_string((int)(targetProd->getMargin() * 100)).c_str() << ", " << to_string(targetProd->getSailCost()).c_str() << ", "<< targetProd->getManufacturer().c_str() << endl;

			}

			retVal[0] = targetProd->getID();
			retVal[1] = sort;

			if (sort != 5)
				delete targetProd;

		}
		else
			con.boxLine("Couldn\'t find any product(s).");	

		con.boxClose();

	}
	else if (Temp == 2) {

		cout << " Name: ";
		cin >> TempStr;

		if ((aSnack = Snacks->getProdByName(TempStr)) && aSnack->getName() == TempStr) {

			deb("It\'s a Snack!");

			targetProd = makeProd(aSnack->getID(), aSnack->getName(), aSnack->getStock(), aSnack->getPrimeCost(), aSnack->getMargin(), aSnack->getSailCost(), aSnack->getManufacturer());

			sort = 2;

		}
		else if ((aDrink = Drinks->getProdByName(TempStr)) && aDrink->getName() == TempStr) {

			deb("It\'s a Drink!");

			targetProd = makeProd(aDrink->getID(), aDrink->getName(), aDrink->getStock(), aDrink->getPrimeCost(), aDrink->getMargin(), aDrink->getSailCost(), aDrink->getManufacturer());

			sort = 3;

		}
		else if ((anIce = Ices->getProdByName(TempStr)) && anIce->getName() == TempStr) {

			deb("It\'s an Ice!");

			targetProd = makeProd(anIce->getID(), anIce->getName(), anIce->getStock(), anIce->getPrimeCost(), anIce->getMargin(), anIce->getSailCost(), anIce->getManufacturer());

			sort = 4;

		}
		else if ((aProd = Others->getProdByName(TempStr)) && aProd->getName() == TempStr) {

			deb("It\'s a Product!");

			sort = 5;

			targetProd = aProd;

		}

		if (Mode)
			cls();

		con.boxOpen();
		con.boxLineCenter("[Search Result]");
		con.boxLine();

		if (sort) {

			con.boxLine("1 product found.");
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

			}
			else if (isLinux) {

				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

			}

			con.boxLine();

			if (isWin) {

				printf((isMGW) ? "|" : "│");
				con.printSpace(to_string(targetProd->getID()), 12);
				con.printSpace(targetProd->getName(), 32);
				con.printSpace(to_string(targetProd->getStock()), 16);
				con.printSpace(to_string(targetProd->getPrimeCost()), 15);
				con.printSpace(to_string((int)(targetProd->getMargin() * 100)), 20);
				con.printSpace(to_string(targetProd->getSailCost()), 15);
				con.printSpace(targetProd->getManufacturer(), 26);
				printf((isMGW) ? "|\n" : "│\n");

			}
			else if (isLinux) {

				cout << "│" << to_string(targetProd->getID()).c_str() << ", " << targetProd->getName().c_str() << ", " << to_string(targetProd->getStock()).c_str() << ", " << to_string(targetProd->getPrimeCost()).c_str() << ", " << to_string((int)(targetProd->getMargin() * 100)).c_str() << ", " << to_string(targetProd->getSailCost()).c_str() << ", "<< targetProd->getManufacturer().c_str() << endl;

			}

			retVal[0] = targetProd->getID();
			retVal[1] = sort;

			if (sort != 5)
				delete targetProd;

		}
		else
			con.boxLine("Couldn\'t find any product(s).");

		con.boxClose();

	}
	else if (Temp == 3 && !Mode) {

		cout << " Manufacturer: ";
		cin >> TempStr;

		sSnacks = Snacks->getProdsByManufacturer(sSnacks, TempStr);
		sDrinks = Drinks->getProdsByManufacturer(sDrinks, TempStr);
		sIces = Ices->getProdsByManufacturer(sIces, TempStr);
		sOthers = Others->getProdsByManufacturer(sOthers, TempStr);

		con.boxOpen();
		con.boxLineCenter("[Search Result]");
		con.boxLine();

		if (sSnacks->getAmounts() + sDrinks->getAmounts() + sIces->getAmounts() + sOthers->getAmounts()) {

			con.boxLine(to_string(sSnacks->getAmounts() + sDrinks->getAmounts() + sIces->getAmounts() + sOthers->getAmounts()) + " product(s) found.");
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

			}
			else if (isLinux) {

				con.boxLine("Prod. ID,   Name,   Stocks,   Prime Cost,   Margin(%%),   Sail Cost,   Manufacturer");

			}

			con.boxLine();

			for (Snack* Queue = sSnacks->getHead(); Queue != NULL; Queue = Queue->getNext()) {

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

					cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", "<< Queue->getManufacturer().c_str() << endl;

				}

			}

			for (Drink* Queue = sDrinks->getHead(); Queue != NULL; Queue = Queue->getNext()) {

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

					cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", "<< Queue->getManufacturer().c_str() << endl;

				}

			}

			for (Ice* Queue = sIces->getHead(); Queue != NULL; Queue = Queue->getNext()) {

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

					cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", "<< Queue->getManufacturer().c_str() << endl;

				}

			}

			for (Other* Queue = sOthers->getHead(); Queue != NULL; Queue = Queue->getNext()) {

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

					cout << "│" << to_string(Queue->getID()).c_str() << ", " << Queue->getName().c_str() << ", " << to_string(Queue->getStock()).c_str() << ", " << to_string(Queue->getPrimeCost()).c_str() << ", " << to_string((int)(Queue->getMargin() * 100)).c_str() << ", " << to_string(Queue->getSailCost()).c_str() << ", "<< Queue->getManufacturer().c_str() << endl;

				}

			}

		}
		else
			con.boxLine("Couldn\'t find any product(s).");

		con.boxClose();

	}
	else {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("Invalid Input.");
		con.boxClose();

	}

	if(sSnacks->getAmounts())
		for (; sSnacks->getHead() != NULL; sSnacks->Delete(sSnacks->getHead()));
	if(sDrinks->getAmounts())
		for (; sDrinks->getHead() != NULL; sDrinks->Delete(sDrinks->getHead()));
	if(sIces->getAmounts())
		for (; sIces->getHead() != NULL; sIces->Delete(sIces->getHead()));
	if(sOthers->getAmounts())
		for (; sOthers->getHead() != NULL; sOthers->Delete(sOthers->getHead()));

	delete sSnacks, sDrinks, sIces, sOthers;

	if (!Mode || !Temp || retVal[0] == -1)
		con.csPause();

	return retVal;

}

void dispRecord() {

	ifstream Records("sell_info.txt");

	con.csSize(100, 45);

	int count = 0;
	char Temp[1024];

	con.boxOpen();
	con.boxLineCenter("[RECORD]");
	con.boxClose();
	con.boxOpen();
	
	if (!Records) {
		
		con.boxLine("No Records.");
		con.boxClose();
		con.csPause();
		
		return;
		
	}

	for (Records.getline(Temp, 1024); !Records.eof(); Records.getline(Temp, 1024)) {

		con.boxLine(Temp);

		if ((count++) % 25 == 24) {

			con.boxLine();
			con.boxLine("Press any key to keep going.");
			con.boxClose();
			con.csPause();

			cls();

			con.boxOpen();
			con.boxLineCenter("[RECORD]");
			con.boxClose();
			con.boxOpen();

		}

	}

	con.boxClose();

	con.csPause();

}

void initAnn() {

	con.csSize(80, 24);

	con.boxOpen();
	con.boxLineCenter("<Information>");
	con.boxClose();
	con.boxOpen();
	con.boxLine("Creator: Jio Gim");
	con.boxLine("Version: 1.0.11");
	con.boxClose();

	if (isWin) {

		con.boxOpen();
		con.boxLine("Please use ANSI text.");
		con.boxClose();

	}
	else if (isLinux) {

		color(BLACK, RED);
		con.boxOpen();
		con.boxLine("Please use UTF-8 without BOM text.");
		con.boxClose();
		color(BLACK, YELLOW);
		con.boxOpen();
		con.boxLine("POS is most compatible with Windows.");
		con.boxLine("In Linux, Something can be displayed as wrong way.");
		con.boxLine("If you use English, this problem will not be happened.");
		con.boxClose();
		color(BLACK, DEFAULTFONT);
		con.boxOpen();
		con.boxLine("Suggested screen size is 99*28.");
		con.boxLine("In other size, some design could be wrongly displayed.");
		con.boxClose();

	}

	cout << " This program is developed as an assignment of CSED232 in POSTECH." << endl << endl;

	con.csPause();

}
