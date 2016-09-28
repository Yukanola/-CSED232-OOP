// ©Kanola 2016. Compatible for Windows and Unix-based OS.

#pragma once
#pragma region Inclusions
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#pragma endregion

using namespace std;

#pragma region Before-Processor-Block

#define setc(a, b) printf("\x1b[" a "m" b "\x1b[0m");
#define varn(a) printf(#a);
#define bar_l "├---------------------------------------------------------\n"

#ifdef _WIN32
#define isWin true

#ifdef _MSC_FULL_VER
#pragma warning(disable:4996)
#pragma warning(disable:4820)
#endif

#pragma region COLORS
#define BLACK "0"
#define BLUE "1"
#define GREEN "2"
#define TURQUOISE "3"
#define RED "4"
#define PURPLE "5"
#define YELLOW "6"
#define LIGHTGRAY "7"
#define GRAY "8"
#define LIGHTBLUE "9"
#define LIGHTGREEN "A"
#define LIGHTTURQUOISE "B"
#define LIGHTRED "C"
#define LIGHTPURPLE "D"
#define LIGHTYELLOW "E"
#define WHITE "F"
#pragma endregion

#define cls() std::system("cls");
#define color(a, b) std::system("color " a b);
#define csize(a, b) std::system("mode con: cols=" a " lines=" b);

#else
#define isWin false

#pragma region COLORS
#define BLACK "black"
#define BLUE "blue"
#define GREEN "green"
#define TURQUOISE "cyan"
#define RED "red"
#define PURPLE "magenta"
#define YELLOW "yellow"
#define WHITE "white"
#pragma endregion

#define cls() std::system("clear");
#define color(a, b) std::system("setterm --term linux --background "a" --foreground "b);

#endif

#pragma endregion

//Comprehensive Error Data: _KanoE
namespace _KanoE {

	class err {

	public:
		char* desc;
		unsigned long code;

	};

	err MEMORYLACK, MEMFREEFAIL, DATACOPYFAIL, UNKNOWNARG;

	void setERROR() {

		//* 0xE1XXX; MEMORY ERROR

		MEMORYLACK.desc = "Failed to allocate memory.";
		MEMORYLACK.code = 0xE1000;

		MEMFREEFAIL.desc = "Failed to free memory.";
		MEMFREEFAIL.code = 0xE1001;

		DATACOPYFAIL.desc = "Failed to copy data.";
		DATACOPYFAIL.code = 0xE1010;

		//* 0xE2XXX; DATA ERROR

		UNKNOWNARG.desc = "Input argument is not expected.";
		UNKNOWNARG.code = 0xE2010;

	};

}
using namespace _KanoE;

//Comprehensive Base: _KanoB
namespace _KanoB {

	//* DEFAULT VARIABLE Definition

	bool isDev = false;
	static void** pub = (void**)calloc(1, sizeof(void*));

	//* Function Origin Declaration

	void end();

	//* DEFAULT FUNCTION Definition



	//* Classes

	class _con {

	public:

		int* conSize(int cols, int lines) {

			static int retVal[2];

			if (isWin) {

				char *col, *line;

				//sprintf(col, "%d", cols);
				//sprintf(line, "%d", lines);

				//std::system(strcat(strcat(strcat("mode con: cols=", col), " lines="), line));

				retVal[0] = cols;
				retVal[1] = lines;

			}
			else {

				retVal[0] = std::system("echo $COLUMNS");
				retVal[1] = std::system("echo $LINES");

			}

			return retVal;

		};

		void printWithSpace(char* saying, int cols) {

			printf("%s", saying);

			int sayingLength = strlen(saying);

			for (int i = 0, times = cols - sayingLength; i < times; i++)
				printf(" ");

		};

		void boxLinePrint(char* saying, int cols) {

			printf("│");

			this->printWithSpace(saying, cols - 1);

			printf("│\n");


		};

		void openBox(int cols) {

			printf("┌");

			for (int i = 0; i < (cols - 1) / 2; i++)
				printf("─");

			printf("┐\n");

		};

		void closeBox(int cols) {

			printf("└");

			for (int i = 0; i < (cols - 1) / 2; i++)
				printf("─");

			printf("┘\n");

		};

	};
	_con *con = new _KanoB::_con;

	class _err {

	public:

		void E(char* func, char* file, int line, _KanoE::err error) {

			cls();
			color(TURQUOISE, WHITE);

			int* cons = _KanoB::con->conSize(60, 24);
			csize("60", "24"); //for temp
							   //CSIZE는 윈도우용 함수이다. 이 문제를 해결하자. WITH CONSIZE.
			_KanoB::con->openBox(cons[0] = (cons[0] % 2) ? cons[0] - 4 : cons[0] - 3);

			char* bsPos = (strrchr(file, '\\')) + 1;

			_KanoB::con->boxLinePrint("[ERROR] Program is going to be terminated.", cons[0]);
			_KanoB::con->boxLinePrint("", cons[0]);
			_KanoB::con->boxLinePrint("Refer to error information below.", cons[0]);
			_KanoB::con->boxLinePrint("", cons[0]);
			printf("│Code       : 0x%x", error.code);
			_KanoB::con->printWithSpace("", cons[0] - 21);
			printf("│\n│File       : ");
			_KanoB::con->printWithSpace(bsPos, cons[0] - 14);
			printf("│\n│Line       : %.5d", line);
			_KanoB::con->printWithSpace("", cons[0] - 19);
			printf("│\n│Function   : ");
			_KanoB::con->printWithSpace(func, cons[0] - 14);
			printf("│\n");
			_KanoB::con->boxLinePrint("", cons[0]);
			printf("│Description: ");
			_KanoB::con->printWithSpace((error.desc == NULL) ? "Description for this case isn't found." : error.desc, cons[0] - 14);
			printf("│\n");
			_KanoB::con->boxLinePrint("", cons[0]);

			_KanoB::con->closeBox(cons[0]);

			_KanoB::end();

			exit((int)error.code);

		};

	};
	_err *err = new _KanoB::_err;
#define loge(b) _KanoB::err->E(__FUNCTION__, __FILE__, __LINE__, b); //For early-access to loge.

	class _deb {

	public:

		void debug(char* func, char* task, int channel) {

			if (_KanoB::isDev) {

				char* caller[2];
				char* colonPos = strrchr(func, ':');

				if (colonPos != NULL) {

					int caller_length;

					caller[0] = (char*)malloc((--(caller_length = strlen(func) - strlen(colonPos)) + 2) * sizeof(char));
					strncpy(caller[0], func, caller_length);
					caller[0][caller_length] = NULL;
					caller[1] = ++colonPos;

				}
				else {

					caller[0] = "";
					caller[1] = func;

				}

				if (channel == 1)
					printf("[dev] %s%s%s%s >   %s\n", caller[1], (colonPos != NULL) ? "(" : "", caller[0], (colonPos != NULL) ? ")" : "", task);

				else if (channel == 0) {

					//LOG COLLECTOR

				}
				else {

					if (colonPos != NULL)
						free(caller[0]);

					loge(_KanoE::UNKNOWNARG);

				}

				if (colonPos != NULL)
					free(caller[0]);

			}

		};

	};
	_deb *deb = new _KanoB::_deb;
#define devl(b) _KanoB::deb->debug(__FUNCTION__, b, 1); //For early-access to devl.
#define dev(b) _KanoB::deb->debug(__FUNCTION__, b, 0); //For early-access to dev.

	class _obj {

	public:

		static bool addo(void* objp) {

			devl("To Add Base Kano Object Started.");

			int puc = (int)(sizeof(_KanoB::pub) / sizeof(void*));

			_KanoB::pub = (void**)realloc(_KanoB::pub, (++puc)*sizeof(void*));

			if (_KanoB::pub == NULL)
				return false;
			else
			{

				devl("New Kano Object appended to pub.");

				_KanoB::pub[--puc] = objp;
				return true;

			}

		};

		static void remo() {

			devl("Starts to remove Kano Objects from pub.");

			int puc = (int)(sizeof(_KanoB::pub) / sizeof(void*));

			for (int i = 0; i < puc; i++) {

				devl("A Kano object is deleted from pub.");

				delete _KanoB::pub[i];

			}

			delete _KanoB::pub;

			devl("Kano pub is completely erased.");

		};

		void __show_pub() {

			printf(bar_l);
			printf("[TEST] Let you see _KanoM::pub.\n");

			int puc = (int)(sizeof(_KanoB::pub) / sizeof(void*));

			printf("\n       There is %d Kano object(s) in pub.\n       See the list below.\n\n", puc);

			for (int i = 0; i < puc; i++) {

				printf("[%d] %s\n", i + 1, typeid(_KanoB::pub[i]).name());

			}

			printf(bar_l);

		};

	};

	/*class _log {

	private:

	char** log = (char**)calloc(1, sizeof(char*));

	public:

	const char* name = typeid(this).name();

	bool recLog(char* logs, char* func) {

	try {

	char* tempMsg;

	if (tempMsg = (char*)malloc(sizeof(logs)))
	throw _KanoB::MEMORYLACK;

	if (strcpy(tempMsg, logs))
	throw _KanoB::DATACOPYFAILURE;

	}
	catch (unsigned long e) {

	//printf("%s", e);

	}



	}

	};*/
	//_log *log = new _KanoB::_log;

	void end() {

		_KanoB::_obj::remo();

		devl("Memory allocation is successfully released.");
		devl("Program successfully terminated.");

		delete _KanoB::err, _KanoB::deb, _KanoB::con;// , _KanoB::log;

	};

}
using namespace _KanoB;

#pragma region Midterm Definition



#pragma endregion

//Kano System: Kano
namespace Kano {

	char* version = "Delicate 0.7 [0160918.3]";

	_KanoB::_obj obj;

	class _set {

	public:

		char* name = "CLASS:_set";

		void devMode(bool mode) { _KanoB::isDev = mode; }; //OK

	};
	_set *set;

	/*class _mem {

	public:

	char* name = "CLASS:_mem";

	bool remember(void* data) {

	//NEXT: 메모리 관리 시스템 만들기..!

	};

	};
	_mem *mem;*/

	void end(const long code) {

		_KanoB::end();

		exit((code == NULL) ? 0x00000 : code);

	};

	void init(bool modeSet) {

		if (modeSet == true)
			_KanoB::isDev = true;

		_KanoE::setERROR();

		devl(version);

		//Add Kano Objects
		obj.addo(Kano::set = new Kano::_set);
		//obj.addo(Kano::mem = new Kano::_mem);

		devl("Initiation completed.");

	};

}
using namespace Kano;

#pragma region After-Definitions



#pragma endregion