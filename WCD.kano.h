// Windows Console Debugging Extension 1.0.0161105.0 for Kano Compact Library.
// Copyright Kanola 2016. Compatible for Windows.

#pragma once
#include "Core.kano.h"
#include <Windows.h>

namespace _Kano {

	static int WCD_Counter = 0;
	static COORD WCD_position = { 0, 0 };
	static COORD WCD_window = { 0, 0 };

	const static void WCD_debug(const char* func, char* task) {

		if (_Kano::isDev) {

			

			static string Line[5];

			//cout << "<" << WCD_position.X << "," << WCD_position.Y << ">";

			CONSOLE_SCREEN_BUFFER_INFO CSBI;

			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);

			COORD origin = { CSBI.dwCursorPosition.X, CSBI.dwCursorPosition.Y };

			if (WCD_position.Y < WCD_window.Y - 1) {

				//WCD_position.Y += 1;

				//Line[point]

			}
			else {



			}

			//cout << "(" << WCD_position.X << "," << WCD_position.Y << ")";

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _Kano::WCD_position);

			char* copiedFunc = (char*)calloc(512, sizeof(char));
			copiedFunc = strcpy(copiedFunc, func);

			char* caller[2];
			char* colonPos = strrchr(copiedFunc, ':');

			if (colonPos != NULL) {

				int caller_length;

				caller[0] = (char*)malloc((--(caller_length = strlen(copiedFunc) - strlen(colonPos)) + 2) * sizeof(char));
				strncpy(caller[0], copiedFunc, caller_length);
				caller[0][caller_length] = NULL;
				caller[1] = ++colonPos;

			}
			else {

				caller[0] = "";
				caller[1] = copiedFunc;

			}

			printf("[dev] %s%s%s%s >   %s\n", caller[1], (colonPos != NULL) ? "(" : "", caller[0], (colonPos != NULL) ? ")" : "", task);

			if (colonPos != NULL)
				free(caller[0]);

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), origin);

		}

	};

	const static void WCD_init() {

		_Kano::WCD_debug(__FUNCTION__, ((char*)Kano::version.c_str()));
		_Kano::WCD_debug(__FUNCTION__, "with WCD Extension 1.0");
		_Kano::WCD_debug(__FUNCTION__, "Initiation completed.");

	}

};

namespace Kano {

	inline const static void WCD_init(int x, int y) {

		con.csSize(x, ((_Kano::isDev) ? y + 6 : y));

		_Kano::WCD_position.Y = y + 1;
		_Kano::WCD_window.X = x;
		_Kano::WCD_window.Y = y + 6;

#define deb(a) _Kano::WCD_debug(__FUNCTION__, a);

		_Kano::WCD_init();

	};

};

#define debc() cout << "CheckSign(" << _Kano::WCD_Counter++ << ")";
