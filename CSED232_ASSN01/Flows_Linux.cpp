#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

#include <fstream>
#include <ctime>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::time;
using std::localtime;
using std::tm;
using std::time_t;
using std::ios;

Other* makeProd(int, string, int, int, float, int, string);
int* dispSearch(SnackList*, DrinkList*, IceList*, OtherList*, bool);
bool initProd(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others, char* firstArg);

bool initProd(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	return initProd(Snacks, Drinks, Ices, Others, "product.txt");

}

bool initProd(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others, char* firstArg) {

	deb("Read product.txt File.");

	ifstream Products(firstArg);

	char Temp[1024] = "";

	int sort = 1;

	if (!Products)
		return false;

	for (; !Products.eof(); Products.getline(Temp, 1024)) {

		deb(Temp);

		if (Temp[0] == '-') {

			deb("New product type found.");

			if (strstr(Temp, "-SNACK-") != NULL)
				sort = 1;
			else if (strstr(Temp, "-DRINK-") != NULL)
				sort = 2;
			else if (strstr(Temp, "-ICE-") != NULL)
				sort = 3;
			else
				sort = 4;

		}
		else if (Temp[0] != NULL && Temp[0] != 32) {

			if (sort == 1) {

				deb("A snack found.");

				int i = 1;
				char *readings[7], *addr;

				addr = strtok(Temp, " ");

				readings[0] = addr;

				while (i < 7) {

					addr = strtok(NULL, " ");

					readings[i++] = addr;

				}

				deb("All properties of a snack found.");

				string name(readings[1]), man(readings[6]);

				deb("char* converted to string.");

				Snack* aSnack = new Snack(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

				deb("A Snack object created.");

				Snacks->Add(aSnack);

				deb("Information of a snack now inputted.");

			}
			else if (sort == 2) {

				deb("A drink found.");

				int i = 1;
				char *readings[7], *addr;

				addr = strtok(Temp, " ");

				readings[0] = addr;

				while (i < 7) {

					addr = strtok(NULL, " ");

					readings[i++] = addr;

				}

				deb("All properties of a drink found.");

				string name(readings[1]), man(readings[6]);

				deb("char* converted to string.");

				Drink* aDrink = new Drink(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

				deb("A Drink object created.");

				Drinks->Add(aDrink);

				deb("Information of a drink now inputted.");

			}
			else if (sort == 3) {

				deb("An ice found.");

				int i = 1;
				char *readings[7], *addr;

				addr = strtok(Temp, " ");

				readings[0] = addr;

				while (i < 7) {

					addr = strtok(NULL, " ");

					readings[i++] = addr;

				}

				deb("All properties of an ice found.");

				string name(readings[1]), man(readings[6]);

				deb("char* converted to string.");

				Ice* anIce = new Ice(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

				deb("An Ice object created.");

				Ices->Add(anIce);

				deb("Information of an ice now inputted.");

			}
			else {

				deb("An Unknown Product found.");

				int i = 1;
				char *readings[7], *addr;

				addr = strtok(Temp, " ");

				readings[0] = addr;

				while (i < 7) {

					addr = strtok(NULL, " ");

					readings[i++] = addr;

				}

				deb("All properties of a product found.");

				string name(readings[1]), man(readings[6]);

				deb("char* converted to string.");

				Other* aProd = new Other(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);
 
				deb("An Other object created.");

				Others->Add(aProd);

				deb("Information of an unknown product now inputted.");

			}

		}

	}

	if (Temp[0] != 0 && Temp[0] != '-' && Temp[0] != 32) {

		if (sort == 1) {

			deb("A snack found.");

			int i = 1;
			char *readings[7], *addr;

			addr = strtok(Temp, " ");

			readings[0] = addr;

			while (i < 7) {

				addr = strtok(NULL, " ");

				readings[i++] = addr;

			}

			deb("All properties of a snack found.");

			string name(readings[1]), man(readings[6]);

			deb("char* converted to string.");

			Snack* aSnack = new Snack(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

			deb("A Snack object created.");

			Snacks->Add(aSnack);

			deb("Information of a snack now inputted.");

		}
		else if (sort == 2) {

			deb("A drink found.");

			int i = 1;
			char *readings[7], *addr;

			addr = strtok(Temp, " ");

			readings[0] = addr;

			while (i < 7) {

				addr = strtok(NULL, " ");

				readings[i++] = addr;

			}

			deb("All properties of a drink found.");

			string name(readings[1]), man(readings[6]);

			deb("char* converted to string.");

			Drink* aDrink = new Drink(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

			deb("A Drink object created.");

			Drinks->Add(aDrink);

			deb("Information of a drink now inputted.");

		}
		else if (sort == 3) {

			deb("An ice found.");

			int i = 1;
			char *readings[7], *addr;

			addr = strtok(Temp, " ");

			readings[0] = addr;

			while (i < 7) {

				addr = strtok(NULL, " ");

				readings[i++] = addr;

			}

			deb("All properties of an ice found.");

			string name(readings[1]), man(readings[6]);

			deb("char* converted to string.");

			Ice* anIce = new Ice(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

			deb("An Ice object created.");

			Ices->Add(anIce);

			deb("Information of an ice now inputted.");

		}
		else {

			deb("An Unknown Product found.");

			int i = 1;
			char *readings[7], *addr;

			addr = strtok(Temp, " ");

			readings[0] = addr;

			while (i < 7) {

				addr = strtok(NULL, " ");

				readings[i++] = addr;

			}

			deb("All properties of a product found.");

			string name(readings[1]), man(readings[6]);

			deb("char* converted to string.");

			Other* aProd = new Other(atoi(readings[0]), name, atoi(readings[2]), atoi(readings[3]), atof(readings[4]), atoi(readings[5]), man);

			deb("An Other object created.");

			Others->Add(aProd);

			deb("Information of an unknown product now inputted.");

		}

	}

	Products.close();

	return true;
}

void procSale(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	deb("Sailing Process Started.");

	cls();

	con.csSize(140, 25);

	int Temp, sort = 0;

	Snack* aSnack;
	Drink* aDrink;
	Ice* anIce;
	Other *aProd, *targetProd;
	time_t nowTime = time(NULL);
	struct tm* nowATime = localtime(&nowTime);
	ofstream Records("sell_info.txt", std::ios::app);

	con.boxOpen();
	con.boxLineCenter("[SELL]");
	con.boxLine();
	con.boxLine("Enter the Product ID.");
	con.boxClose();
	cout << " Prod. ID: ";
	cin >> Temp;

	if (Temp <= 0) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("ID cannot be lower than 1.");
		con.boxClose();

		con.csPause();

		return;

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

	cls();

	con.boxOpen();
	con.boxLineCenter("[Prod. Information]");
	con.boxLine();

	if (!sort) {

		con.boxLine("Invalid product (Your product does not exist).");
		con.boxClose();

	}
	else {

		con.boxLine("");
		if(isWin) {
				
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
		
		if (isWin) {
			
			con.boxLine();
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
			
		con.boxClose();

		printf(" How much do you want to sell: ");

		cin >> Temp;

		switch (sort) {

		case 2:
			if (aSnack->getStock() < Temp || Temp < 0) {

				sort += 100;
				break;

			}
			if (aSnack->getStock() == Temp)
				Snacks->Delete(aSnack);
			else
				aSnack->setStock(aSnack->getStock() - Temp);
			break;
		case 3:
			if (aDrink->getStock() < Temp || Temp < 0) {

				sort += 100;
				break;

			}
			if (aDrink->getStock() == Temp)
				Drinks->Delete(aDrink);
			else
				aDrink->setStock(aDrink->getStock() - Temp);
			break;
		case 4:
			if (anIce->getStock() < Temp || Temp < 0) {

				sort += 100;
				break;

			}
			if (anIce->getStock() == Temp)
				Ices->Delete(anIce);
			else
				anIce->setStock(anIce->getStock() - Temp);
			break;
		case 5:
			if (aProd->getStock() < Temp || Temp < 0) {

				sort += 100;
				break;

			}
			if (aProd->getStock() == Temp)
				Others->Delete(aProd);
			else
				aProd->setStock(aProd->getStock() - Temp);
			break;

		}

		con.boxOpen();

		if (sort >= 100)
			con.boxLine("Invalid Input.");
		else
		{

			con.boxLine("Successfully processed.");

			Records << nowATime->tm_year + 1900 << "." << nowATime->tm_mon + 1 << "." << nowATime->tm_mday << " " << nowATime->tm_hour << ":" << nowATime->tm_min << ":" << nowATime->tm_sec << " " << targetProd->getName() + "(ID=" << targetProd->getID() << ", Price=" << targetProd->getSailCost() << ") " << Temp << " = SUM " << Temp * targetProd->getSailCost() << endl;

		}

		if ((sort % 100) != 5)
			delete targetProd;

		con.boxClose();
		Records.close();

	}

	con.csPause();

}

void procStock(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	cls();

	int id, sCost, stock, pCost, sort;
	float margin;
	string name, man;

	Snack* aSnack;
	Drink* aDrink;
	Ice* anIce;
	Other *aProd;

	con.csSize(80, 28);

	con.boxOpen();
	con.boxLineCenter("[Receiving]");
	con.boxLine();
	con.boxLine("Enter the informations.");
	con.boxClose();
	cout << " = Prod. ID : ";
	cin >> id;

	if (id <= 0) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("ID cannot be lower than 1.");
		con.boxClose();

		con.csPause();

		return;

	}

	if (((aSnack = Snacks->getProdByID(id)) && aSnack->getID() == id) || ((aDrink = Drinks->getProdByID(id)) && aDrink->getID() == id) || ((anIce = Ices->getProdByID(id)) && anIce->getID() == id) || ((aProd = Others->getProdByID(id)) && aProd->getID() == id)) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine("Entered ID already exists.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Name : ";
	cin >> name;

	if (((aSnack = Snacks->getProdByName(name)) && aSnack->getName() == name) || ((aDrink = Drinks->getProdByName(name)) && aDrink->getName() == name) || ((anIce = Ices->getProdByName(name)) && anIce->getName() == name) || ((aProd = Others->getProdByName(name)) && aProd->getName() == name)) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine("Entered name already exists.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Stocks : ";
	cin >> stock;

	if (stock <= 0) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("Stock cannot be lower than 1.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Prime Cost : ";
	cin >> pCost;

	if (pCost <= 0) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("Prime Cost cannot be lower than 1.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Margin ( < 1 ) : ";
	cin >> margin;

	if (margin <= 0 || margin >= 1) {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("Margin cannot be lower than 0 or 0 or upper than 1.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Manufacturer : ";
	cin >> man;

	con.boxOpen();
	con.boxLine("Select product category.");
	con.boxLine();
	con.boxLineCenter("1. Snack    2. Drink    3. Ice    4. Other");
	con.boxClose();
	cout << " Category Number: ";
	cin >> sort;

	if (sort == 1) {

		Snack* newSnack = new Snack(id, name, stock, pCost, margin, (int)((float)pCost * ((float)1 + margin)), man);

		Snacks->Add(newSnack);

	}
	else if (sort == 2) {

		Drink* newDrink = new Drink(id, name, stock, pCost, margin, (int)((float)pCost * ((float)1 + margin)), man);

		Drinks->Add(newDrink);

	}
	else if (sort == 3) {

		Ice* newIce = new Ice(id, name, stock, pCost, margin, (int)((float)pCost * ((float)1 + margin)), man);

		Ices->Add(newIce);

	}
	else if (sort == 4) {

		Other* newProd = new Other(id, name, stock, pCost, margin, (int)((float)pCost * ((float)1 + margin)), man);

		Others->Add(newProd);

	}
	else {

		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine("Invalid Input.");
		con.boxClose();
		con.csPause();

		return;

	}

	con.boxOpen();
	con.boxLine("Receiving Processed.");
	con.boxClose();

	con.csPause();

}

void procModify(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	con.csSize(140, 30);
	con.boxOpen();
	con.boxLineCenter("You can modify a product after searching it.");
	con.boxClose();

	Snack* aSnack, *sSnack;
	Drink* aDrink, *sDrink;
	Ice* anIce, *sIce;
	Other* aProd, *sProd;

	int* targetProdInfo;

	targetProdInfo = dispSearch(Snacks, Drinks, Ices, Others, true);

	if (targetProdInfo[1] == -1)
		return;
	else if (targetProdInfo[1] == 2)
		aSnack = Snacks->getProdByID(targetProdInfo[0]);
	else if (targetProdInfo[1] == 3)
		aDrink = Drinks->getProdByID(targetProdInfo[0]);
	else if (targetProdInfo[1] == 4)
		anIce = Ices->getProdByID(targetProdInfo[0]);
	else if (targetProdInfo[1] == 5)
		aProd = Others->getProdByID(targetProdInfo[0]);
	else
		eLog(_Kano::UNKNOWNARG);

	int Temp;
	string TempStr;
	float TempFloat;

	con.boxOpen();
	con.boxLine("Select what do you want to modify.");
	con.boxLine();
	con.boxLine("1. Prod.ID    2. Name    3. Stocks    4. Prime Cost    5. Margin    6. Manufacturer");
	con.boxClose();
	cout << " Selection: ";
	cin >> Temp;

	switch (Temp) {

	default:
		con.boxOpen();
		con.boxLineCenter("[ERROR]");
		con.boxLine();
		con.boxLine("Invalid Input.");
		con.boxClose();
		con.csPause();
		return;
		break;

	case 1:
		cout << " = Prod.ID : ";
		cin >> Temp;

		if (Temp <= 0) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine();
			con.boxLine("ID cannot be lower than 1.");
			con.boxClose();

			con.csPause();

			return;

		}

		if (((sSnack = Snacks->getProdByID(Temp)) && sSnack->getID() == Temp) || ((sDrink = Drinks->getProdByID(Temp)) && sDrink->getID() == Temp) || ((sIce = Ices->getProdByID(Temp)) && sIce->getID() == Temp) || ((sProd = Others->getProdByID(Temp)) && sProd->getID() == Temp)) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine("Entered ID already exists.");
			con.boxClose();

			con.csPause();

			return;

		}
		
		if (targetProdInfo[1] == 2)
			aSnack->setID(Temp);
		else if (targetProdInfo[1] == 3)
			aDrink->setID(Temp);
		else if (targetProdInfo[1] == 4)
			anIce->setID(Temp);
		else if (targetProdInfo[1] == 5)
			aProd->setID(Temp);
		break;

	case 2:
		cout << " = Name : ";
		cin >> TempStr;

		if (((sSnack = Snacks->getProdByName(TempStr)) && sSnack->getName() == TempStr) || ((sDrink = Drinks->getProdByName(TempStr)) && sDrink->getName() == TempStr) || ((sIce = Ices->getProdByName(TempStr)) && sIce->getName() == TempStr) || ((sProd = Others->getProdByName(TempStr)) && sProd->getName() == TempStr)) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine("Entered name already exists.");
			con.boxClose();

			con.csPause();

			return;

		}

		if (targetProdInfo[1] == 2)
			aSnack->setName(TempStr);
		else if (targetProdInfo[1] == 3)
			aDrink->setName(TempStr);
		else if (targetProdInfo[1] == 4)
			anIce->setName(TempStr);
		else if (targetProdInfo[1] == 5)
			aProd->setName(TempStr);
		break;

	case 3:
		cout << " = Stocks : ";
		cin >> Temp;

		if (Temp <= 0) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine();
			con.boxLine("Stocks cannot be lower than 1.");
			con.boxClose();

			con.csPause();

			return;

		}

		if (targetProdInfo[1] == 2)
			aSnack->setStock(Temp);
		else if (targetProdInfo[1] == 3)
			aDrink->setStock(Temp);
		else if (targetProdInfo[1] == 4)
			anIce->setStock(Temp);
		else if (targetProdInfo[1] == 5)
			aProd->setStock(Temp);
		break;

	case 4:
		cout << " = Prime Cost : ";
		cin >> Temp;

		if (Temp <= 0) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine();
			con.boxLine("Prime Cost cannot be lower than 1.");
			con.boxClose();

			con.csPause();

			return;

		}

		if (targetProdInfo[1] == 2)
			aSnack->setPrimeCost(Temp);
		else if (targetProdInfo[1] == 3)
			aDrink->setPrimeCost(Temp);
		else if (targetProdInfo[1] == 4)
			anIce->setPrimeCost(Temp);
		else if (targetProdInfo[1] == 5)
			aProd->setPrimeCost(Temp);
		break;

	case 5:
		cout << " = Margin ( < 1 ) : ";
		cin >> TempFloat;

		if (TempFloat <= 0 || TempFloat >= 1) {

			con.boxOpen();
			con.boxLineCenter("[ERROR]");
			con.boxLine();
			con.boxLine("Margin cannot be lower than 0 or 0 or upper than 1.");
			con.boxClose();

			con.csPause();

			return;

		}

		if (targetProdInfo[1] == 2)
			aSnack->setMargin(TempFloat);
		else if (targetProdInfo[1] == 3)
			aDrink->setMargin(TempFloat);
		else if (targetProdInfo[1] == 4)
			anIce->setMargin(TempFloat);
		else if (targetProdInfo[1] == 5)
			aProd->setMargin(TempFloat);
		break;

	case 6:
		cout << " = Manufacturer : ";
		cin >> TempStr;
		if (targetProdInfo[1] == 2)
			aSnack->setManufacturer(TempStr);
		else if (targetProdInfo[1] == 3)
			aDrink->setManufacturer(TempStr);
		else if (targetProdInfo[1] == 4)
			anIce->setManufacturer(TempStr);
		else if (targetProdInfo[1] == 5)
			aProd->setManufacturer(TempStr);
		break;

	}

	targetProdInfo[0] = -1;
	targetProdInfo[1] = -1;

	con.boxOpen();
	con.boxLine("Successfully modified product information.");
	con.boxClose();

	con.csPause();

}

void procRemove(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	con.csSize(140, 30);
	con.boxOpen();
	con.boxLineCenter("You can remove a product after searching it.");
	con.boxClose();

	int* targetProdInfo;

	targetProdInfo = dispSearch(Snacks, Drinks, Ices, Others, true);

	//cout << "[TEST] [" << targetProdInfo[0] << "][" << targetProdInfo[1] << "]\n";
	//con.csPause();

	if (targetProdInfo[1] == -1)
		return;
	else if (targetProdInfo[1] == 2)
		Snacks->Delete(Snacks->getProdByID(targetProdInfo[0]));
	else if (targetProdInfo[1] == 3)
		Drinks->Delete(Drinks->getProdByID(targetProdInfo[0]));
	else if (targetProdInfo[1] == 4)
		Ices->Delete(Ices->getProdByID(targetProdInfo[0]));
	else if (targetProdInfo[1] == 5)
		Others->Delete(Others->getProdByID(targetProdInfo[0]));
	else
		eLog(_Kano::UNKNOWNARG);

	targetProdInfo[0] = -1;
	targetProdInfo[1] = -1;

	con.boxOpen();
	con.boxLineCenter("A product successfully removed.");
	con.boxClose();

	con.csPause();

}