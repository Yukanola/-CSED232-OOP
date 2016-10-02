#include "Products.h"
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

bool initProd(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	deb("Read product.txt File.");

	ifstream Products("product.txt");

	char Temp[1024] = "";

	int sort = 1;

	for (; !Products.eof(); Products.getline(Temp, 1024)) {

		deb(Temp);

		if (Temp[0] == '-') {

			deb("New product type found.");

			if (!strcmp(Temp, "-SNACK-"))
				sort = 1;
			else if (!strcmp(Temp, "-DRINK-"))
				sort = 2;
			else if (!strcmp(Temp, "-ICE-"))
				sort = 3;
			else
				sort = 4;

		}
		else if (Temp[0] != NULL) {

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

	if (Temp[0] != 0 && Temp[0] != '-') {

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
	con.boxLineCenter("[판매]");
	con.boxLine();
	con.boxLine("제품 ID를 입력하세요.");
	con.boxClose();
	cout << " 제품 ID: ";
	cin >> Temp;

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
	con.boxLineCenter("[제품 정보]");
	con.boxLine();

	if (!sort) {

		con.boxLine("존재하지 않는 상품입니다.");
		con.boxClose();

	}
	else {

		con.boxLine("");
		printf("│");
		con.printSpace("Prod. ID", 12);
		con.printSpace("Name", 32);
		con.printSpace("Stocks", 16);
		con.printSpace("Prime Cost", 15);
		con.printSpace("Margin(%%)", 21);
		con.printSpace("Sail Cost", 15);
		con.printSpace("Manufacturer", 26);
		printf("│\n│");
		con.printSpace(to_string(targetProd->getID()), 12);
		con.printSpace(targetProd->getName(), 32);
		con.printSpace(to_string(targetProd->getStock()), 16);
		con.printSpace(to_string(targetProd->getPrimeCost()), 15);
		con.printSpace(to_string((int)(targetProd->getMargin() * 100)), 20);
		con.printSpace(to_string(targetProd->getSailCost()), 15);
		con.printSpace(targetProd->getManufacturer(), 26);
		printf("│\n");
		con.boxClose();

		printf(" 판매 수량을 입력하세요: ");

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
			con.boxLine("잘못된 입력입니다.");
		else
		{

			con.boxLine("정상 처리되었습니다.");

			Records << nowATime->tm_year + 1900 << "." << nowATime->tm_mon + 1 << "." << nowATime->tm_mday << " " << nowATime->tm_hour << ":" << nowATime->tm_min << ":" << nowATime->tm_sec << " " << targetProd->getName() + "(ID=" << targetProd->getID() << ", Price=" << targetProd->getSailCost() << ") " << Temp << "개 = 총액 " << Temp * targetProd->getSailCost() << endl;

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
	con.boxLineCenter("[입고]");
	con.boxLine();
	con.boxLine("정보를 입력하세요.");
	con.boxClose();
	cout << " = Prod. ID : ";
	cin >> id;

	if (((aSnack = Snacks->getProdByID(id)) && aSnack->getID() == id) || ((aDrink = Drinks->getProdByID(id)) && aDrink->getID() == id) || ((anIce = Ices->getProdByID(id)) && anIce->getID() == id) || ((aProd = Others->getProdByID(id)) && aProd->getID() == id)) {

		con.boxOpen();
		con.boxLineCenter("[오류]");
		con.boxLine("입력한 ID가 이미 존재합니다.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Name : ";
	cin >> name;

	if (((aSnack = Snacks->getProdByName(name)) && aSnack->getName() == name) || ((aDrink = Drinks->getProdByName(name)) && aDrink->getName() == name) || ((anIce = Ices->getProdByName(name)) && anIce->getName() == name) || ((aProd = Others->getProdByName(name)) && aProd->getName() == name)) {

		con.boxOpen();
		con.boxLineCenter("[오류]");
		con.boxLine("입력한 이름이 이미 존재합니다.");
		con.boxClose();

		con.csPause();

		return;

	}

	cout << endl << " = Stocks : ";
	cin >> stock;
	cout << endl << " = Prime Cost : ";
	cin >> pCost;
	cout << endl << " = Margin ( < 1 ) : ";
	cin >> margin;
	cout << endl << " = Manufacturer : ";
	cin >> man;
	con.boxOpen();
	con.boxLine("상품 카테고리를 선택하세요.");
	con.boxLine();
	con.boxLineCenter("1. Snack    2. Drink    3. Ice    4. Other");
	con.boxClose();
	cout << " 카테고리 번호: ";
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
		con.boxLineCenter("[오류]");
		con.boxLine("잘못된 값을 입력하셨습니다.");
		con.boxClose();

	}

	con.boxOpen();
	con.boxLine("입고처리 되었습니다.");
	con.boxClose();

	con.csPause();

}

void procModify(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	con.csSize(140, 30);
	con.boxOpen();
	con.boxLineCenter("상품 검색 후 수정하실 수 있습니다.");
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
	con.boxLine("수정할 항목을 선택하세요.");
	con.boxLine();
	con.boxLine("1. Prod.ID    2. Name    3. Stocks    4. Prime Cost    5. Margin    6. Manufacturer");
	con.boxClose();
	cout << " 선택: ";
	cin >> Temp;

	switch (Temp) {

	case 1:
		cout << " = Prod.ID : ";
		cin >> Temp;
		if (((sSnack = Snacks->getProdByID(Temp)) && sSnack->getID() == Temp) || ((sDrink = Drinks->getProdByID(Temp)) && sDrink->getID() == Temp) || ((sIce = Ices->getProdByID(Temp)) && sIce->getID() == Temp) || ((sProd = Others->getProdByID(Temp)) && sProd->getID() == Temp)) {

			con.boxOpen();
			con.boxLineCenter("[오류]");
			con.boxLine("입력한 ID가 이미 존재합니다.");
			con.boxClose();

			con.csPause();

			return;

		}
		deb("통과");
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
			con.boxLineCenter("[오류]");
			con.boxLine("입력한 이름이 이미 존재합니다.");
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
		cout << " = Margin : ";
		cin >> TempFloat;
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
		cout << " = Prod.ID : ";
		cin >> Temp;
		if (targetProdInfo[1] == 2)
			aSnack->setID(Temp);
		else if (targetProdInfo[1] == 3)
			aDrink->setID(Temp);
		else if (targetProdInfo[1] == 4)
			anIce->setID(Temp);
		else if (targetProdInfo[1] == 5)
			aProd->setID(Temp);
		break;

	}

	con.boxOpen();
	con.boxLine("성공적으로 상품 정보를 수정하였습니다.");
	con.boxClose();

	con.csPause();

}

void procRemove(SnackList* Snacks, DrinkList* Drinks, IceList* Ices, OtherList* Others) {

	con.csSize(140, 30);
	con.boxOpen();
	con.boxLineCenter("상품 검색 후 삭제하실 수 있습니다.");
	con.boxClose();

	int* targetProdInfo;

	targetProdInfo = dispSearch(Snacks, Drinks, Ices, Others, true);

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

	con.boxOpen();
	con.boxLineCenter("상품이 삭제되었습니다.");
	con.boxClose();

	con.csPause();

}