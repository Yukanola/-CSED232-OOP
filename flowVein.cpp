#include "libKano.cp.h"
#include <conio.h>
#include "Parameter.h"
#include "Classes.h"

using std::cin;
using namespace Key;
using namespace Setting;

void dispMenu(int);
void dispHardnessSet(int);
void procGame();
void dispInstruction();
int procSetHardness();
void dispInGameBackground(Env*);
void dispInGameTimeCount();
void dispInGameScorePanel(int, int);
void dispInGameEY(int*, Env*);
void dispInGameLane(_Q&, Env&);
bool procInGame(Env&, _Q&, _M&, int&);

bool procMenu() {

	deb("Menu process started.");

	static int menuCode = 1;
	int lastKey = 0;
	dispMenu(menuCode);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_UP || lastKey == KEY_DOWN || lastKey == ENTER)););

	if (lastKey != ENTER) {

		if (lastKey == KEY_DOWN && menuCode != 3)
			menuCode++;

		if (lastKey == KEY_UP && menuCode != 1)
			menuCode--;

		return true;

	}

	cin.clear();

	switch (menuCode) {

	case 1:
		deb("First menu selected.");
		procGame();
		break;

	case 2:
		deb("Second menu selected.");
		dispInstruction();
		break;

	case 3:
		deb("Third menu selected.");
		return false;
		break;

	};

	return true;

}

void procGame() {

	using std::endl;

	Env* Hardness;
	_Q Q;
	bool isDied = false;

	int score = 0;

	for (; !procSetHardness(););

	cls();

	switch (Setting::hardness) {

	case 1:
		Hardness = &VE;
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	}

	_M M((Hardness->roadX) - (Hardness->EX), 37 - (Setting::hardness * 5));

	dispInGameBackground(Hardness);
	dispInGameScorePanel(score, Setting::HighestScore);
	dispInGameEY(M.getPos(), Hardness);
	dispInGameTimeCount();

	for (;!isDied;) {

		for (clock_t mTime = clock(); (clock() - mTime < Hardness->T2) && !(isDied = !procInGame(*Hardness, Q++, M, score)); Q.insert());

	}

}

bool procInGameCheckAccident() {

	return false;

};

void procScoreUp(int score) {

	if (Setting::HighestScore < score)
		Setting::HighestScore = score;

};

bool procInGame(Env& E, _Q& Q, _M& M, int& score) {

	char keyGet;
	
	dispInGameLane(Q, E);

	for (clock_t mTime = clock(); clock() - mTime < E.T1;) {

		if (_kbhit()) {

			keyGet = getch();

			switch (keyGet) {
					
			case KEY_LEFT:
				if (M.getPosX() > 1)
					M.setPosX(M.getPosX() - 2);
				dispInGameEY(M.getPos(), &E);
				break;

			case KEY_RIGHT:
				if (M.getPosX() < (E.roadX * 2 - 5))
					M.setPosX(M.getPosX() + 2);
				dispInGameEY(M.getPos(), &E);
				break;

			}

			if (procInGameCheckAccident())
				return false;
			else
				procScoreUp(++score);

		}

	};

	return true;

};

int procSetHardness() {

	deb("Hardness selection process started.");

	int lastKey = 0;
	dispHardnessSet(Setting::hardness);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_UP || lastKey == KEY_DOWN || lastKey == ENTER)););

	if (lastKey != ENTER) {

		if (lastKey == KEY_DOWN && hardness != 5)
			Setting::hardness++;

		if (lastKey == KEY_UP && hardness != 1)
			Setting::hardness--;

		return 0;

	}

	return Setting::hardness;

}
