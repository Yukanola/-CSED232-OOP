#include "Core.kano.h"
#include "Parameter.h"
#include "Classes.h"
#include <conio.h>
#include <tchar.h>

using std::cin;
using namespace Keys;
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
void dispInGameLane(_L&, Env&);
bool procInGame(Env&, _L&, _M&, _Pixel&, int&);
void dispColorSelection(int);
void dispInGameGAMEOVER(Env&, _M&, int, int);

bool procMenu() { //메뉴 부분 흐름을 담당하는 함수입니다.

	deb("Menu process started.");

	static int menuCode = 1;
	int lastKey = 0;
	dispMenu(menuCode);

	Setting::wannaESC = false;

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_W || lastKey == KEY_WW || lastKey == KEY_S || lastKey == KEY_SS || lastKey == KEY_UP || lastKey == KEY_DOWN || lastKey == KEY_ENTER)););

	if (lastKey != KEY_ENTER) {

		if ((lastKey == KEY_DOWN || lastKey == KEY_S || lastKey == KEY_SS) && menuCode != 3)
			menuCode++;

		if ((lastKey == KEY_UP || lastKey == KEY_W || lastKey == KEY_WW) && menuCode != 1)
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

int procSetEYColor(int& color) { //캐릭터의 색을 정하는 흐름을 담당하는 함수입니다.

	deb("Color selection process started.");

	int lastKey = 0;
	static const int colorSet[7] = { 12, 5, 14, 10, 2, 9, 11 };
	static int colorNumber = 1;
	dispColorSelection(colorNumber);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_A || lastKey == KEY_AA || lastKey == KEY_D || lastKey == KEY_DD || lastKey == KEY_LEFT || lastKey == KEY_RIGHT || lastKey == KEY_ENTER || lastKey == KEY_ESC)););

	if (lastKey != KEY_ENTER) {

		if ((lastKey == KEY_RIGHT || lastKey == KEY_D || lastKey == KEY_DD) && colorNumber != 7)
			colorNumber++;

		if ((lastKey == KEY_LEFT || lastKey == KEY_A || lastKey == KEY_AA) && colorNumber != 1)
			colorNumber--;

		if (lastKey == KEY_ESC)
			return (Setting::wannaESC = true);

		return 0;

	}

	return (color = colorSet[colorNumber - 1]);

}

void procGame() { //게임의 시작부터 끝까지를 담당하는 함수입니다. 긴 주기를 담당합니다.

	using std::endl;

	Env* Hardness;
	_L L;

	bool isDied = false;

	int score = 0;

	for (; !procSetHardness(););

	if (Setting::wannaESC)
		return;

	cls();

	switch (Setting::hardness) {

	case 6:
		Hardness = Setting::E = &HIDDEN;
		SetConsoleTitle(_T("OOPA CHAR HIDDEN MODE!!"));
		break;

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

	if (Setting::wannaESC)
		return;

	_M M(((Hardness->roadX - Hardness->EX) / 2) + (Hardness->roadX % 2), 34 - Hardness->EY, color);
	_Pixel Pixel(Hardness->roadX + 1, Hardness->roadY + 1);

	Setting::P = &Pixel;

	L.randomInsert(Pixel);
	dispInGameBackground(Hardness);
	dispInGameScorePanel(score, Setting::HighestScore);
	dispInGameEY(M.getPos(), Hardness, M.getColor());
	dispInGameTimeCount();

	for (; !isDied; L.randomInsert(Pixel))
		for (clock_t mTime = clock(); (clock() - mTime < Hardness->T2) && !(isDied = !procInGame(*Hardness, L, M, Pixel, score)); L.behave(*Hardness, Pixel));

	dispInGameLane(L, *Hardness);
	dispInGameEY(M.getPos(), Hardness, M.getColor());
	dispInGameGAMEOVER(*Hardness, M, score, Setting::HighestScore);

	L.X();

	if (Setting::hardness == 6) {

		SetConsoleTitle(_T("OOPA CHAR Public Handin"));

		Setting::hardness = 1;

	}
	
};

bool procInGameCheckAccident(_Pixel& P, _M& M) { //게임 진행 중, 사고 여부를 판단하는 함수입니다.

	for (int i = 0; i < Setting::E->EX; i++)
		for (int j = 0; j < Setting::E->EY; j++)
			if (P.getPixel(M.getPosX() + i, j + M.getPosY()).detect())
				return true;

			/* For checking character's real position
			else {

				int pad = (((Setting::scrSize[0]) - (E->roadX * 2)) / 2);
				COORD temp = { (M.getPosX() + i) * 2 + pad, (M.getPosY() + j) + 3 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
				cout << "OO";

			}
			*/

	return false;

};

int procCheckHighscore(int score) { //게임 진행 중, 하이스코어를 확인하고 갱신하는 함수입니다.

	if (Setting::HighestScore < score)
		Setting::HighestScore = score;

	dispInGameScorePanel(score, Setting::HighestScore);

	return score;

};

int procCheckScore(_L& L, _M& M, int& score) { //게임 진행 중, 스코어를 올려주는 역할을 담당하는 함수입니다.

	CarA* A = L.getAFront();
	CarB* B = L.getBFront();
	CarC* C = L.getCFront();

	for (int i = 0; i++ < L.getCount()[0]; A = A->getNext())
		if (A->getPosY() >= M.getPosY() + Setting::E->EY && !A->isCounted()) {
			
			A->count();
			score++;

		}

	for (int i = 0; i++ < L.getCount()[1]; B = B->getNext())
		if (B->getPosY() >= M.getPosY() + Setting::E->EY&& !B->isCounted()) {

			B->count();
			score++;

		}

	for (int i = 0; i++ < L.getCount()[2]; C = C->getNext())
		if (C->getPosY() >= M.getPosY() + Setting::E->EY&& !C->isCounted()) {

			C->count();
			score++;

		}

	return procCheckHighscore(score);

}

bool procInGame(Env& E, _L& L, _M& M, _Pixel& P, int& score) { //짧은 주기를 담당하는 함수입니다.

	char keyGet;

	if (procInGameCheckAccident(P, M))
		return false;
	else
		procCheckScore(L, M, score);

	dispInGameLane(L, E);
	dispInGameEY(M.getPos(), &E, M.getColor());

	for (clock_t mTime = clock(); clock() - mTime < E.T1;) {

		if (_kbhit()) {

			keyGet = getch();

			switch (keyGet) {

			case KEY_A:
			case KEY_AA:
			case KEY_LEFT:
				if (M.getPosX() > 0)
					M.setPosX(M.getPosX() - 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_D:
			case KEY_DD:
			case KEY_RIGHT:
				if (M.getPosX() < E.roadX - E.EX)
					M.setPosX(M.getPosX() + 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_W:
			case KEY_WW:
			case KEY_UP:
				if (M.getPosY() > 0)
					M.setPosY(M.getPosY() - 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			case KEY_S:
			case KEY_SS:
			case KEY_DOWN:
				if (M.getPosY() < E.roadY - E.EY)
					M.setPosY(M.getPosY() + 1);
				dispInGameEY(M.getPos(), &E, M.getColor());
				break;

			}

			if (procInGameCheckAccident(P, M))
				return false;
			else
				procCheckScore(L, M, score);

		}

	};

	return true;

};

int procSetHardness() { //난이도 설정 흐름을 담당하는 함수입니다.

	deb("Hardness selection process started.");

	int lastKey = 0;
	dispHardnessSet(Setting::hardness);

	for (cin.clear(); !(_kbhit() && (lastKey = getch()) && (lastKey == KEY_F1 || lastKey == KEY_UP || lastKey == KEY_DOWN || lastKey == KEY_ENTER || lastKey == KEY_ESC)););

	if (lastKey == KEY_F1)
		Setting::hardness = 6;
	else if (lastKey != KEY_ENTER) {

		if (lastKey == KEY_DOWN && hardness != 5)
			Setting::hardness++;

		if (lastKey == KEY_UP && hardness != 1)
			Setting::hardness--;

		if (lastKey == KEY_ESC)
			return (Setting::wannaESC = true);

		return 0;

	}

	return Setting::hardness;

}
