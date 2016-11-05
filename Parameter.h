#pragma once
#include "Core.kano.h"
#include "WCD.kano.h"

namespace Keys {

	static const int KEY_UP = 72;
	static const int KEY_DOWN = 80;
	static const int KEY_LEFT = 75;
	static const int KEY_RIGHT = 77;
	static const int KEY_ENTER = 13;
	static const int KEY_ESC = 27;

}

namespace Setting {

	using std::begin;
	using std::end;

	static bool wannaESC = false;

	static string verSign = "  Beta 1.2"; // This must be with 10 characters.

	static unsigned int blockers = 0;

	static const int scrSize[2] = { /*Columns*/48, /*Rows*/43 }; // The number of cols must be 48 or 49.

	static bool ableCursor(bool Opinion) {

		HANDLE Handler;
		CONSOLE_CURSOR_INFO ConsoleCursor;
		Handler = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursor.bVisible = (int)Opinion;
		ConsoleCursor.dwSize = 1;
		return SetConsoleCursorInfo(Handler, &ConsoleCursor);

	};

	static bool setColor(int color) {

		return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)color);

	};

	static bool setSelection(bool Switch) {

		return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (Switch) ? 0xF0 : 0x0F);

	};

	static int hardness = 1;

	static class Env {

	public:

		const int roadX, roadY, blockAX, blockBX, blockCX, blockAY, blockBY, blockCY, EX, EY, T1, T2, code;

		Env(int ex, int ey, int t1, int t2, int c) : roadX(17), roadY(39), blockAX(3), blockAY(2), blockBX(2), blockBY(2), blockCX(2), blockCY(3), EX(ex), EY(ey), T1(t1), T2(t2), code(c) {};

	} /*Player Initial Width, Player Initial Height, Ticker 1, Ticker 2*/
		VEASY(2, 2, 500, 4500, 1),
		EASY(2, 2, 400, 1600, 2),
		NORMAL(2, 2, 300, 1500, 3),
		HARD(3, 3, 200, 1000, 4),
		VHARD(3, 3, 100, 300, 5);

	static int HighestScore = 0;

	static Env* E;

};
