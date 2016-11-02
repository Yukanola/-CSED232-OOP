#include "Core.kano.h"
#include "WCD.kano.h"
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
void dispColorSelection(int);

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

bool procSetEYColor(int& color) {

	deb("Menu process started.");

	static const int colorCode[5] = { 14, 15, 15, 15, 15 };

	static int EYColor = 1;
	int lastKey = 0;
	dispColorSelection(EYColor);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_UP || lastKey == KEY_DOWN || lastKey == ENTER)););

	if (lastKey != ENTER) {

		if (lastKey == KEY_DOWN && EYColor != 5)
			EYColor++;

		if (lastKey == KEY_UP && EYColor != 1)
			EYColor--;

		return true;

	}

	cin.clear();

	return false;

};

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
		Hardness = Setting::E = &VEASY;
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

	int color = 0;

	for (; !procSetEYColor(color););

	_M M((Hardness->roadX) - (Hardness->EX) + 2 * (Hardness->roadX % 2), 37 - (Setting::hardness * 5));
	_Pixel Pixel(2 * Hardness->roadX + 1, Hardness->roadY + 1);

	Q.randomInsert(Pixel);
	dispInGameBackground(Hardness);
	dispInGameScorePanel(score, Setting::HighestScore);
	dispInGameEY(M.getPos(), Hardness);
	dispInGameTimeCount();

	for (; !isDied; Q.randomInsert(Pixel))
		for (clock_t mTime = clock(); (clock() - mTime < Hardness->T2) && !(isDied = !procInGame(*Hardness, Q, M, score)); Q.behave(*Hardness, Pixel));

};

bool procInGameCheckAccident(_Q& Q) {

	//for (int i = 0;;);

	return false;

};

int procCheckHighscore(int score) {

	if (Setting::HighestScore < score)
		Setting::HighestScore = score;

	dispInGameScorePanel(score, Setting::HighestScore);

	return score;

};

int procCheckScore(int& score) { 

	//++score;

	return procCheckHighscore(score);

}

bool procInGame(Env& E, _Q& Q, _M& M, int& score) {

	char keyGet;

	if (procInGameCheckAccident(Q))
		return false;
	else
		procCheckScore(score);

	dispInGameLane(Q, E);
	dispInGameEY(M.getPos(), &E);

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
				if (M.getPosX() < (E.roadX * 2 - 3))
					M.setPosX(M.getPosX() + 2);
				dispInGameEY(M.getPos(), &E);
				break;

			case KEY_UP:
				if (M.getPosY() > 0)
					M.setPosY(M.getPosY() - 1);
				dispInGameEY(M.getPos(), &E);
				break;

			case KEY_DOWN:
				if (M.getPosY() < E.roadY - 2)
					M.setPosY(M.getPosY() + 1);
				dispInGameEY(M.getPos(), &E);
				break;

			}

			if (procInGameCheckAccident(Q))
				return false;
			else
				procCheckScore(score);

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

void procInGameCheckBlkAccident(_Q& Q) {

	CarA* A = Q.getAFront();
	CarB* B = Q.getBFront();
	CarC* C = Q.getCFront();

	//process about As

	for (int i = 0; i++ < Q.getCount()[0];) {

		for (int j = 0; j++ < Q.getCount()[0];) {

			

		}


	}

	//process about Bs

	//process about Cs

}