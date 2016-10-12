#if _WIN32
#include "Products.h"
#else
#include "Products_Linux.h"
#endif

bool dispMenu(SnackList*, DrinkList*, IceList*, OtherList*);
bool initProd(SnackList*, DrinkList*, IceList*, OtherList*);
bool initProd(SnackList*, DrinkList*, IceList*, OtherList*, char*);
void endPOS(SnackList*, DrinkList*, IceList*, OtherList*, char*);
void endPOS(SnackList*, DrinkList*, IceList*, OtherList*);
void initAnn();

int main(int argc, char** argv) {
 
	Kano::init(false);

	con.csSize(42, 18);

	if(isWin)
		color(DEFAULTFONT, DEFAULTBACK);

	cout << endl << endl << "    `7MM\"\"\"Mq.   .g8\"\"8q.    .M\"\"\"bgd" << endl << "      MM   `MM..dP'    `YM. ,MI    \"Y" << endl << "      MM   ,M9 dM'      `MM `MMb." << endl << "      MMmmdM9  MM        MM   `YMMNq." << endl << "      MM       MM.      ,MP .     `MM" << endl << "      MM       `Mb.    ,dP' Mb     dM" << endl << "    .JMML.       `\"bmmd\"'   P\"Ybmmd\"" << endl << endl << endl << endl << endl << endl << "    Copyright 20160087. Version 1.0.11" << endl << endl << endl;

	con.csDelay(1.8);
	
	if(isWin)
		color(DEFAULTBACK, DEFAULTFONT);

	initAnn();

	deb("Create Lists.");

	SnackList* Snacks = new SnackList();
	DrinkList* Drinks = new DrinkList();
	IceList* Ices = new IceList();
	OtherList* Others = new OtherList();

	deb("Input Products to List.");

	if (argc > 1)
		initProd(Snacks, Drinks, Ices, Others, argv[1]);
	else
		initProd(Snacks, Drinks, Ices, Others);

	deb("Displaying Menu.");

	for (;dispMenu(Snacks, Drinks, Ices, Others););

	deb("Delete Lists.");

	if (argc > 1)
		endPOS(Snacks, Drinks, Ices, Others, argv[1]);
	else
		endPOS(Snacks, Drinks, Ices, Others);

	deb("Kano Script Ended.");

	return Kano::end(0x00000);

}
