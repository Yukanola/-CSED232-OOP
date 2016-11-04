#include "Core.kano.h"
#include "WCD.kano.h"
#include "Parameter.h"
#include "Classes.h"
#include <conio.h>

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
void dispInGameEY(int*, Env*, int);
void dispInGameLane(_Q&, Env&);
bool procInGame(Env&, _Q&, _M&, _Pixel&, int&);
void dispColorSelection(int);
void dispInGameGAMEOVER(Env&, _M&, int, int);

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

int procSetEYColor(int& color) {

	deb("Color selection process started.");

	int lastKey = 0;
	static const int colorSet[7] = { 12, 5, 14, 10, 2, 9, 11 };
	static int colorNumber = 1;
	dispColorSelection(colorNumber);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_LEFT || lastKey == KEY_RIGHT || lastKey == ENTER)););

	if (lastKey != ENTER) {

		if (lastKey == KEY_RIGHT && colorNumber != 7)
			colorNumber++;

		if (lastKey == KEY_LEFT && colorNumber != 1)
			colorNumber--;

		return 0;

	}

	return (color = colorSet[colorNumber - 1]);

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
		Hardness = Setting::E = &VEASY;
		break;

	case 2:
		Hardness = Setting::E = &EASY;
		break;

	case 3:
		Hardness = Setting::E = &NORMAL;
		break;

	case 4:
		Hardness = Setting::E = &HARD;
		break;

	case 5:
		Hardness = Setting::E = &VHARD;
		break;

	}

	int color = 0;

	for (; !procSetEYColor(color););

	_M M((Hardness->roadX) - (Hardness->EX) + 2 * (Hardness->roadX % 2), 37 - (Setting::hardness * 5), color);
	_Pixel Pixel(2 * Hardness->roadX + 1, Hardness->roadY + 1);

	Setting::P = &Pixel;

	Q.randomInsert(Pixel);
	dispInGameBackground(Hardness);
	dispInGameScorePanel(score, Setting::HighestScore);
	dispInGameEY(M.getPos(), Hardness, M.getColor());
	dispInGameTimeCount();

	for (; !isDied; Q.randomInsert(Pixel))
		for (clock_t mTime = clock(); (clock() - mTime < Hardness->T2) && !(isDied = !procInGame(*Hardness, Q, M, Pixel, score)); Q.behave(*Hardness, Pixel));

	dispInGameLane(Q, *Hardness);
	dispInGameEY(M.getPos(), Hardness, M.getColor());
	dispInGameGAMEOVER(*Hardness, M, score, Setting::HighestScore);

};

bool procInGameCheckAccident(_Pixel& P, _M& M) {

	for (int i = 0; ++i - 1 < Setting::E->EX;)
		for (int j = 0; ++j - 1 < Setting::E->EY;)
			if (P.getPixel(i * 2 + M.getPosX() + 4, j + M.getPosY() - 3).detect()) {

				cout << "[" << i * 2 + M.getPosX() + 4 << "," << j + M.getPosY() + + 2 << "]";

				return true;

			}
			/*else {

				COORD temp = { i * 2 + M.getPosX() + 4, j + M.getPosY() + 2 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
				cout << "OO";

			}*/

	return false;

};

int procCheckHighscore(int score) {

	if (Setting::HighestScore < score)
		Setting::HighestScore = score;

	dispInGameScorePanel(score, Setting::HighestScore);

	return score;

};

int procCheckScore(_Q& Q, _M& M, int& score) { 

	CarA* A = Q.getAFront();
	CarB* B = Q.getBFront();
	CarC* C = Q.getCFront();

	for (int i = 0; i++ < Q.getCount()[0]; A = A->getNext())
		if (A->getPosY() >= M.getPosY() + Setting::E->EY - 2 && !A->isCounted()) {
			
			A->count();
			score++;

		}

	for (int i = 0; i++ < Q.getCount()[1]; B = B->getNext())
		if (B->getPosY() >= M.getPosY() + Setting::E->EY - 2 && !B->isCounted()) {

			B->count();
			score++;

		}

	for (int i = 0; i++ < Q.getCount()[2]; C = C->getNext())
		if (C->getPosY() >= M.getPosY() + Setting::E->EY - 2 && !C->isCounted()) {

			C->count();
			score++;

		}

	return procCheckHighscore(score);

}

bool procInGame(Env& E, _Q& Q, _M& M, _Pixel& P, int& score) {

	char keyGet;

	if (procInGameCheckAccident(P, M))
		return false;
	else
		procCheckScore(Q, M, score);

	dispInGameLane(Q, E);
	dispInGameEY(M.getPos(), &E, M.getColor());

	for (clock_t mTime = clock(); clock() - mTime < E.T1;) {

		if (_kbhit()) {

			keyGet = getch();

			switch (keyGet) {

			case KEY_LEFT:
				if (M.getPosX() > 1)
					M.setPosX(M.getPosX() - 2);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_RIGHT:
				if (M.getPosX() < (E.roadX * 2 - 3))
					M.setPosX(M.getPosX() + 2);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_UP:
				if (M.getPosY() > 0)
					M.setPosY(M.getPosY() - 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_DOWN:
				if (M.getPosY() < E.roadY - 2)
					M.setPosY(M.getPosY() + 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			}

			if (procInGameCheckAccident(P, M))
				return false;
			else
				procCheckScore(Q, M, score);

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
