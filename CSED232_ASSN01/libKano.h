// Copyright Kanola 2016. Compatible for Windows and Unix-based OS.

#pragma once
#pragma region Inclusions
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <typeinfo>
#include <ctime>
#pragma endregion

#pragma region Usings
using std::string;
using std::cout;
using std::to_string;
#pragma endregion

#pragma region Before-Block

#ifdef _WIN32
#define isWin true
#define isLinux false

#include <Windows.h>

#ifdef _MSC_FULL_VER
#pragma warning(disable:4996)
#pragma warning(disable:4820)
#endif

#define BLACK "0"
#define BLUE "1"
#define GREEN "2"
#define CYAN "3"
#define RED "4"
#define PURPLE "5"
#define YELLOW "6"
#define WHITE "F"
#define DEFAULTFONT "7"
#define DEFAULTBACK "0"

#define cls() std::system("cls");
#define color(a,b) std::system("color " a b);
#define csize(a,b) std::system("mode " a "," b);

#else
#define isWin false
#define isLinux true

#include <sys/ioctl.h>
#include <unistd.h>

#define BLACK "black"
#define BLUE "blue"
#define GREEN "green"
#define CYAN "cyan"
#define RED "red"
#define PURPLE "magenta"
#define YELLOW "yellow"
#define WHITE "white"
#define DEFAULTFONT "white"
#define DEFAULTBACK "black"

#define cls() std::system("clear");
#define color(a,b) std::system("setterm --term linux --background " a " --foreground " b);
#define csize(a,b);

#endif

namespace _Kano {

	static bool isDev = false;

	const static class __errStruct {

	public:

		__errStruct(unsigned long code, string detail) { this->detail = detail; this->code = code; };

		string detail;
		unsigned long code;

	} MEMORYLACK(0xE1000, "Failed to allocate memory")
		, MEMFREEFAIL(0xE1001, "Failed to free memory")
		, DATACOPYFAIL(0xE1010, "Failed to copy data")
		, UNKNOWNARG(0xE2010, "Input argument isn\'t expected")
		, OVERRANGE(0xE2020, "Input is over it\'s range");

	static class __con {

		int consolSize[2]; // [0] = ROWS / [1] = COLUMNS

	public:

		__con() {

#if isWin

			CONSOLE_SCREEN_BUFFER_INFO csBuffer;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csBuffer);

			this->consolSize[0] = csBuffer.srWindow.Bottom - csBuffer.srWindow.Top + 1;
			this->consolSize[1] = csBuffer.srWindow.Right - csBuffer.srWindow.Left + 1;

#elif isLinux

			struct winsize cS;
			
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &cS);
			
			this->consolSize[0] = cS.ws_row;
			this->consolSize[1] = cS.ws_col;

#endif

		};

		void setCS(int cols, int lines) {

			this->consolSize[0] = lines;
			this->consolSize[1] = cols;

		};

		void csDelay(float time) {
			
#if isWin

			time = time * 1000;

			clock_t beginningTime = clock();

			while (clock() - beginningTime < (int)time);
			
#elif isLinux
			
			sleep(time);
			
#endif

		};

		void csPause() {

			if (isWin)
				std::system("pause");
			else if (isLinux)
				std::system("read -n1 -rsp \"Press any key to continue..\"");

		}

		int* csSize(int cols, int lines) {

			if (isWin) {

				string command = "mode " + std::to_string(cols) + "," + std::to_string(lines);

				std::system(command.c_str());

				this->consolSize[0] = lines;
				this->consolSize[1] = cols;

			}

			return this->consolSize;

		};

		void printSpace(char* sentence, int cols) {

			std::printf(sentence);

			cols -= (int)strlen(sentence);

			for (int i = 0; i < cols; i++)
				printf(" ");

		};
		void printSpace(char* sentence) { this->printSpace(sentence, this->consolSize[1]); };
		void printSpace(string sentence, int cols) {

			std::cout << sentence;

			cols -= (int)sentence.length();

			for (int i = 0; i < cols; i++)
				printf(" ");

		};
		void printSpace(string sentence) { this->printSpace(sentence, this->consolSize[1]); };
		void printSpace(int cols) { this->printSpace("", cols); };
		void printSpaceLeft(char* sentence, int cols) { this->printSpace(sentence, cols); };
		void printSpaceLeft(char* sentence) { this->printSpace(sentence); };
		void printSpaceLeft(string sentence, int cols) { this->printSpace(sentence, cols); };
		void printSpaceLeft(string sentence) { this->printSpace(sentence); };
		void printSpaceCenter(char* sentence, int cols) {

			cols -= (int)strlen(sentence);

			bool isOdd = cols % 2;

			cols = cols / 2;

			for (int i = (isOdd) ? -1 : 0; i < cols; i++)
				printf(" ");

			std::printf(sentence);

			for (int i = 0; i < cols; i++)
				printf(" ");

		};
		void printSpaceCenter(char* sentence) { this->printSpaceCenter(sentence, this->consolSize[1]); };
		void printSpaceCenter(string sentence, int cols) {

			cols -= (int)sentence.length();

			bool isOdd = cols % 2;

			cols = cols / 2;

			for (int i = (isOdd) ? -1 : 0; i < cols; i++)
				printf(" ");

			std::cout << sentence;

			for (int i = 0; i < cols; i++)
				printf(" ");

		};
		void printSpaceCenter(string sentence) { this->printSpaceCenter(sentence, this->consolSize[1]); };
		void printSpaceRight(char* sentence, int cols) {

			cols -= (int)strlen(sentence);

			for (int i = 0; i < cols; i++)
				printf(" ");

			std::printf(sentence);

		};
		void printSpaceRight(char* sentence) { this->printSpaceRight(sentence, this->consolSize[1]); };
		void printSpaceRight(string sentence, int cols) {

			cols -= (int)sentence.length();

			for (int i = 0; i < cols; i++)
				printf(" ");

			std::cout << sentence;

		};
		void printSpaceRight(string sentence) { this->printSpaceRight(sentence, this->consolSize[1]); };
		void printLine(int trigger) {

			if (trigger >= 0) {

				for (int i = 0; i < trigger / 2; i++)
					printf("─");

			}
			else {

				for (int i = 0, goal = this->consolSize[1] / 2 + trigger / 2; i < goal; i++)
					printf("─");

			}

		};
		void printLine() {

			for (int i = 0; i < this->consolSize[1] / 2; i++)
				printf("─");

		};

		void boxOpen() {

			printf("┌");

			int cols = (this->consolSize[1] - 4) / ((isLinux) ? 1 : 2);

			for (int i = 0; i < cols; i++)
				printf("─");

			printf("┐\n");

		};
		void boxClose() {

			printf("└");

			int cols = (this->consolSize[1] - 4) / ((isLinux) ? 1 : 2);

			for (int i = 0; i < cols; i++)
				printf("─");

			printf("┘\n");

		};
		void boxLine(char* sentence, int cols) {

			printf("│");

			this->printSpace(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLine(char* sentence) { this->boxLine(sentence, this->consolSize[1]); };
		void boxLine(string sentence, int cols) {

			printf("│");

			this->printSpace(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLine(string sentence) { this->boxLine(sentence, this->consolSize[1]); };
		void boxLine(int cols) { this->boxLine("", this->consolSize[1]); };
		void boxLine() { this->boxLine(""); };
		void boxLineLeft(char* sentence, int cols) { this->boxLine(sentence, cols); };
		void boxLineLeft(char*sentence) { this->boxLine(sentence); };
		void boxLineLeft(string sentence, int cols) { this->boxLine(sentence, cols); };
		void boxLineLeft(string sentence) { this->boxLine(sentence); };
		void boxLineCenter(char* sentence, int cols) {

			printf("│");

			this->printSpaceCenter(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLineCenter(char* sentence) { this->boxLineCenter(sentence, this->consolSize[1]); };
		void boxLineCenter(string sentence, int cols) {

			printf("│");

			this->printSpaceCenter(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLineCenter(string sentence) { this->boxLineCenter(sentence, this->consolSize[1]); };
		void boxLineRight(char* sentence, int cols) {

			printf("│");

			this->printSpaceRight(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLineRight(char* sentence) { this->boxLineRight(sentence, this->consolSize[1]); };
		void boxLineRight(string sentence, int cols) {

			printf("│");

			this->printSpaceRight(sentence, cols - 4 - ((this->consolSize[1] % 2) ? 1 : 0) + ((isLinux) ? 1 : 0));

			printf("│\n");

		};
		void boxLineRight(string sentence) { this->boxLineRight(sentence, this->consolSize[1]); };
		void boxCutter() {

			printf("├");

			this->printLine(-4);

			printf("┤\n");

		};

	} con;

	static class __core {

	public:

		void E(const char* func, const char* file, const int line, _Kano::__errStruct error) {

			cls();
			color(CYAN, WHITE);

			int* csSize = _Kano::con.csSize(60, 24);
			const char* bsPos = (strrchr(file, '\\')) + 1;
			int csCols = (csSize[1] / 2) * 2;

			_Kano::con.boxOpen();
			_Kano::con.boxLine("[ERROR] Program is going to be terminated.");
			_Kano::con.boxLine();
			printf("│Code       : 0x%x", error.code);
			_Kano::con.printSpace(csCols - 24);
			printf("│\n│File       : ");
			_Kano::con.printSpace((char*)bsPos, csSize[1] - 17 - ((csSize[1] % 2) ? 1 : 0));
			printf("│\n│Line       : %.5d", line); 
			_Kano::con.printSpace(csSize[1] - 22 - ((csSize[1] % 2) ? 1 : 0));
			printf("│\n│Function   : ");
			_Kano::con.printSpace(func, csSize[1] - 17 - ((csSize[1] % 2) ? 1 : 0));
			printf("│\n");
			_Kano::con.boxLine();
			printf("│Description: ");
			_Kano::con.printSpace((error.detail == "") ? "Description for this case isn't found." : error.detail, csSize[1] - 17 - ((csSize[1] % 2) ? 1 : 0));
			printf("│\n");
			_Kano::con.boxLine();
			_Kano::con.boxClose();

			con.csPause();

			color(DEFAULTBACK, DEFAULTFONT);
			cls();

			exit((int)error.code);

		};

		void debug(const char* func, char* task) {

			if (_Kano::isDev) {

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

			}

		};

	} core;

	// 0xE1XXX = MEMORY ERROR / 0xE2XXXX = DATA ERROR

};

using namespace _Kano;

#define eLog(a) _Kano::core.E(__FUNCTION__, __FILE__, __LINE__, a);
#define deb(a) _Kano::core.debug(__FUNCTION__, a);

namespace Kano {

	const string version = "Delicate 0.9 [0161007.2  Development]";

	const static void init(bool modeSet) {

		_Kano::isDev = modeSet;

		deb((char*)Kano::version.c_str());

		deb("Initiation completed.");

	};

	const static int end(unsigned long exitCode) {

		return (int) exitCode;

	};

};

using namespace Kano;
