#include "Products.h"

bool dispMenu(SnackList*, DrinkList*, IceList*, OtherList*);
bool initProd(SnackList*, DrinkList*, IceList*, OtherList*);
void endPOS(SnackList*, DrinkList*, IceList*, OtherList*);

int main() {

	Kano::init(true);

	con.csSize(42, 18);

	color(DEFAULTFONT, DEFAULTBACK);

	cout << endl << endl << "    `7MM\"\"\"Mq.   .g8\"\"8q.    .M\"\"\"bgd" << endl << "      MM   `MM..dP'    `YM. ,MI    \"Y" << endl << "      MM   ,M9 dM'      `MM `MMb." << endl << "      MMmmdM9  MM        MM   `YMMNq." << endl << "      MM       MM.      ,MP .     `MM" << endl << "      MM       `Mb.    ,dP' Mb     dM" << endl << "    .JMML.       `\"bmmd\"'   P\"Ybmmd\"" << endl << endl << endl << endl << endl << endl << "           Copyright 20160087." << endl << endl << endl;

	con.csDelay(2);
	
	color(DEFAULTBACK, DEFAULTFONT);

	deb("Create Lists.");

	SnackList* Snacks = new SnackList;
	DrinkList* Drinks = new DrinkList;
	IceList* Ices = new IceList;
	OtherList* Others = new OtherList;

	deb("Input Products to List.");

	initProd(Snacks, Drinks, Ices, Others);

	deb("Displaying Menu.");

	for (;dispMenu(Snacks, Drinks, Ices, Others););

	deb("Delete Lists.");

	endPOS(Snacks, Drinks, Ices, Others);

	deb("Kano Script Ended.");

	return Kano::end(0x00000);

}
