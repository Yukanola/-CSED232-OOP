#include "Core.kano.h"
#include "WCD.kano.h"
#include "Parameter.h"
#include "Classes.h"

using namespace Setting;
using _Kano::con;
using std::cout;
using std::endl;

void dispSplash() {

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << "      //   ) ) //   ) ) //   ) ) // | |         "
		<< endl << "     //   / / //   / / //___/ / //__| |         "
		<< endl << "    //   / / //   / / / ____ / / ___  |         "
		<< endl << "   //   / / //   / / //       //    | |         "
		<< endl << "  ((___/ / ((___/ / //       //     | |         "
		<< endl << "                                                "
		<< endl << "        //   ) )  //    / / // | |     //   ) ) "
		<< endl << "       //        //___ / / //__| |    //___/ /  "
		<< endl << "      //        / ___   / / ___  |   / ___ (    "
		<< endl << "     //        //    / / //    | |  //   | |    "
		<< endl << "    ((____/ / //    / / //     | | //    | |    " << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << "                                  " + Setting::verSign + "    " << endl << endl
		<< endl << "                                                ";

	deb("Splash has been displayed.");

	con.csDelay(1.3);

}

void dispMenu(int cursor) {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl;
	con.printSpaceCenter("- 메뉴 선택 -");
	cout << endl << endl << endl;

	if (cursor == 1)
		Setting::setSelection(true);
	con.printSpaceCenter("1. 게임 시작");
	cout << endl << endl;
	if (cursor == 1)
		Setting::setSelection(false);

	if (cursor == 2)
		Setting::setSelection(true);
	con.printSpaceCenter("2. 게임 설명");
	cout << endl << endl;
	if (cursor == 2)
		Setting::setSelection(false);

	if (cursor == 3)
		Setting::setSelection(true);
	con.printSpaceCenter("3. 게임 종료");
	cout << endl << endl << endl << endl << endl << endl;
	if (cursor == 3)
		Setting::setSelection(false);

	con.printSpaceCenter("┌──────────┐");
	cout << endl;
	con.printSpaceCenter("│ 메뉴를 선택하세요. │");
	cout << endl;
	con.printSpaceCenter("│                    │");
	con.printSpaceCenter("│ 선택하려면 [ENTER] │");
	cout << endl;
	con.printSpaceCenter("└──────────┘");

}

void dispColorSelection(int cursor) {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl;
	con.printSpaceCenter("- 자동차 색상 선택 -");
	cout << endl << endl << endl;

	Setting::setColor(12);
	cout << "     ■  ";
	Setting::setColor(5);
	cout << "  ■  ";
	Setting::setColor(14);
	cout << "  ■  ";
	Setting::setColor(10);
	cout << "  ■  ";
	Setting::setColor(2);
	cout << "  ■  ";
	Setting::setColor(9);
	cout << "  ■  ";
	Setting::setColor(11);
	cout << "  ■     ";
	Setting::setColor(7);
	cout << endl << endl;

	if (cursor == 1)
		con.printSpaceCenter("↑                                    ");
	if (cursor == 2)
		con.printSpaceCenter("      ↑                              ");
	if (cursor == 3)
		con.printSpaceCenter("            ↑                        ");
	if (cursor == 4)
		con.printSpaceCenter("                  ↑                  ");
	if (cursor == 5)
		con.printSpaceCenter("                        ↑            ");
	if (cursor == 6)
		con.printSpaceCenter("                              ↑      ");
	if (cursor == 7)
		con.printSpaceCenter("                                    ↑");

	cout << endl << endl << endl << endl;
	con.printSpaceCenter("┌──────────┐");
	cout << endl;
	con.printSpaceCenter("│ 색상을 선택하세요. │");
	cout << endl;
	con.printSpaceCenter("│                    │");
	con.printSpaceCenter("│ 선택하려면 [ENTER] │");
	cout << endl;
	con.printSpaceCenter("└──────────┘");

}

void dispHardnessSet(int cursor) {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl;
	con.printSpaceCenter("- 난이도 선택 -");
	cout << endl << endl << endl;

	if (cursor == 1)
		Setting::setSelection(true);
	con.printSpaceCenter("1. 아주 쉬움");
	cout << endl << endl;
	if (cursor == 1)
		Setting::setSelection(false);

	if (cursor == 2)
		Setting::setSelection(true);
	con.printSpaceCenter("2. 쉬움");
	cout << endl << endl;
	if (cursor == 2)
		Setting::setSelection(false);

	if (cursor == 3)
		Setting::setSelection(true);
	con.printSpaceCenter("3. 보통");
	cout << endl << endl;
	if (cursor == 3)
		Setting::setSelection(false);

	if (cursor == 4)
		Setting::setSelection(true);
	con.printSpaceCenter("4. 어려움");
	cout << endl << endl;
	if (cursor == 4)
		Setting::setSelection(false);

	if (cursor == 5)
		Setting::setSelection(true);
	con.printSpaceCenter("5. 아주 어려움");
	cout << endl << endl << endl << endl << endl << endl;
	if (cursor == 5)
		Setting::setSelection(false);

	con.printSpaceCenter("┌──────────┐");
	cout << endl;
	con.printSpaceCenter("│ 메뉴를 선택하세요. │");
	cout << endl;
	con.printSpaceCenter("│                    │");
	con.printSpaceCenter("│ 선택하려면 [ENTER] │");
	cout << endl;
	con.printSpaceCenter("└──────────┘");

}

void dispInstruction() {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl;
	con.printSpaceCenter("- 게임 설명 -");
	cout << endl << endl;
	con.boxOpen();
	con.boxLineCenter("[스토리]");
	con.boxLine();
	con.boxLine();
	con.boxLine(" 오랜만에 동료 교수들과 피크닉을 나간 윤은영");
	con.boxLine("교수. 하지만 화장실 간다던 송황준 교수가 갑");
	con.boxLine("자기 사라지고, 한참을 찾아헤메던 윤은영 교수");
	con.boxLine("는 송황준 교수가 창의IT융합공학과의 이진수");
	con.boxLine("교수에게 납치당했다는 사실을 알게된다.");
	con.boxLine();
	con.boxLineCenter(" \"흥, 이진수 따위! 가발을 씌워주겠어!♥\" ");
	con.boxLine();
	con.boxLine(" 그렇게 윤은영 교수는 송황준 교수를 찾아 떠");
	con.boxLine("나게 된다. 하지만 그런 그녀를 막아선 것들은");
	con.boxLine("다름 아닌 이진수 교수의 부하인 정성준 교수와");
	con.boxLine("한수희 교수, 김재준 교수, 한욱신 교수 그리고");
	con.boxLine("그들의 연구원들이었다.");
	con.boxLine(" 윤은영 교수가 알아본 흑막은 이랬다. 이진수 ");
	con.boxLine("교수와 부하들은 코드 네임 DELLA, 즉 김은희");
	con.boxLine("조교를 첩자로 컴퓨터 공학과의 인재들을 빼가");
	con.boxLine("고 있었던 것이다.");
	con.boxLine();
	con.boxLineCenter("\"김은희..! 가만두지 않겠어..!!♥♥\"");
	con.boxLine();
	con.boxLine(" 모든 사실을 알고 화가 머리 끝까지 치밀어 오");
	con.boxLine("른 그녀는 그렇게 김은희 조교와 이진수 교수");
	con.boxLine("패거리들을 잡으러 떠난다.");
	con.boxLine();
	con.boxLine(" 자, 우리 같이 윤은영 교수의 차를 조작하여");
	con.boxLine("움직이는 이진수 교수 부하들의 차를 피해 송황");
	con.boxLine("준 교수를 구하러 가 보자!");
	con.boxClose();

	cout << endl;

	con.boxOpen();
	con.boxLineCenter("[조작법]");
	con.boxLine();
	con.boxLineCenter(" ←/↑/→/↓ : 윤은영 교수 차 이동");
	con.boxClose();

	cout << " [ALERT] ";

	con.csPause();

}

void dispEndSplash() {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	Setting::setColor(12); // 12 means bright red, 13 means pink, 15 means bright white, 7 means white, 8 means gray.

	con.printSpaceCenter("                       /                        ");
	con.printSpaceCenter("                       y`                       ");
	con.printSpaceCenter("                      `y/                       ");
	con.printSpaceCenter("                      `yy.                      ");
	con.printSpaceCenter("        `              sys`                     ");
	con.printSpaceCenter("        .-             +yys.                    ");
	con.printSpaceCenter("         -/.           :yyyy/`                  ");
	con.printSpaceCenter("          :+/-         `yyyyyy/`                ");
	con.printSpaceCenter("           /+++:.       +yyyyyyy+.              ");
	con.printSpaceCenter("            /++++/:.    .yyyyyyyyyo-            ");
	con.printSpaceCenter("             /+++++++/:.`+yyyyyyyyyyo.          ");
	con.printSpaceCenter("              :++++++++oooyyyyyyyyyyyy/         ");
	con.printSpaceCenter("               -++++oooooosyyyyyyyyyyyyo`       ");
	con.printSpaceCenter("                `/ooooooooooyyyyyyyyyyyyo       ");
	con.printSpaceCenter("                  ./oooooooooyyyyyyyyyyyy-      ");
	con.printSpaceCenter("                    `-/ooooooosyyyyyyyyyo`      ");
	con.printSpaceCenter("                        .-://+++++syyso:        ");
	con.printSpaceCenter("                                                ");

	Setting::setColor(15);

	con.printSpaceRight("Game by KANOLA. Ltd.     ");

	Setting::setColor(8);

	con.printSpaceRight("(20160087)     ");

	Setting::setColor(7);

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << " [ALERT] ";

}

void dispInGameTimeCount() {

	static const COORD Point1 = { 20, 18 }, Point2 = { 20, 19 }, Point3 = { 20, 20 }, Point4 = { 20, 21 }, Point5 = { 20, 22 };

	for (int i = 3; i > 0; i--) {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point1);

		switch (i) {

		case 3:
		case 2:
			cout << "■■■■";
			break;

		case 1:
			cout << "    ■  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point2);

		switch (i) {

		case 3:
		case 2:
			cout << "      ■";
			break;

		case 1:
			cout << "  ■■  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point3);

		switch (i) {

		case 3:
		case 2:
			cout << "■■■■";
			break;

		case 1:
			cout << "    ■  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point4);

		switch (i) {

		case 2:
			cout << "■      ";
			break;

		case 3:
			cout << "      ■";
			break;

		case 1:
			cout << "    ■  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point5);

		switch (i) {

		case 3:
		case 2:
			cout << "■■■■";
			break;

		case 1:
			cout << "  ■■■";
			break;

		}

		Sleep(1000);

	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point1);
	cout << "          ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point2);
	cout << "          ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point3);
	cout << "          ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point4);
	cout << "          ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point5);
	cout << "          ";

}

void dispInGameBackground(Env* E) {

	int* ConsoleSize = con.setCS(Setting::scrSize[0], Setting::scrSize[1]);
	int padding = (((Setting::scrSize[0]) - (E->roadX * 2) - 4) / 2); // I subtracted 4 because of two walls.

	con.boxOpen();
	con.boxLine("현재 점수 :           최고 점수 :          ");
	con.boxClose();

	for (int i = 0; i < E->roadY; i++) {

		for (int j = 0; j < padding - 2; j++)
			cout << " ";

		printf("%2d", i);

		Setting::setColor(15);
		cout << "□";
		Setting::setColor(7);
		for (int j = 0; j < E->roadX; j++)
			//printf("%2d", j);
			cout << "  ";
		Setting::setColor(15);
		cout << "□";
		Setting::setColor(7);

		cout << endl;

	}
	
	for (int j = 0; j < padding + 2; j++)
		cout << " ";

	for (int j = 0; j++ < E->roadX; printf("%2d", j - 1));

}

void dispInGameScorePanel(int now, int highest) {

	static const COORD posNOW = { 14, 1 }, posHIGHEST = { 36, 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNOW);

	cout << now << " 점";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posHIGHEST);

	cout << highest << " 점";

}

void dispInGameEY(int* pos, Env* E, int c) {

	int padding = (((Setting::scrSize[0]) - (E->roadX * 2)) / 2);
	static COORD preXY = { pos[0] * 2 + padding, pos[1] + 3 };
	COORD XY = { pos[0] * 2 + padding, pos[1] + 3 };

	int preY = preXY.Y;

	for (int i = 0; i++ < E->EX; preXY.X += 2) {

		for (int j = 0; j++ < E->EY; preXY.Y += 1) {

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), preXY);
			cout << "  ";

		}

		preXY.Y = preY;

	}

	preXY.X = pos[0] * 2 + padding, preXY.Y = pos[1] + 3;

	for (int i = 0; i++ < E->EY; XY.X += 2) {

		for (int j = 0; j++ < E->EY; XY.Y += 1) {
			
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
			Setting::setColor(c);
			cout << "■";
			Setting::setColor(7);

		}

		XY.Y = pos[1] + 3;

	}

}

void dispInGameLane(_L& L, Env& E) {

	int temp = (((Setting::scrSize[0]) - (E.roadX * 2) + 2) / 2); // Because of the left wall, I subtracted 2.
	COORD posStd = { temp, 3 };

	CarA* A = L.getAFront();
	CarB* B = L.getBFront();
	CarC* C = L.getCFront();

	//Show CarA

	if (L.getCount()[0])
		for (int k = 0; k++ < L.getCount()[0]; A = A->getNext()) {

			for (int i = 0; i < A->getOCarW(); i++)
				for (int j = 0; j < A->getOCarH(); j++) {

					COORD prePos = A->getPrePos();
					prePos.X += (2 * i) + posStd.X;
					prePos.Y += (1 * j) + posStd.Y;
					
					if (prePos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), prePos);
						cout << "  ";

					}

				}

			for (int i = 0; i < A->getCarW(); i++)
				for (int j = 0; j < A->getCarH(); j++) {

					COORD pos = { A->getRealPosX() + posStd.X + (i * 2), A->getPosY() + posStd.Y + (j * 1) };

					if (pos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
						cout << "■";

					}

				}

			A->setPrePos(A->getRealPosX(), A->getPosY());

		}

	//Show CarB

	if (L.getCount()[1])
		for (int k = 0; k++ < L.getCount()[1]; B = B->getNext()) {

			for (int i = 0; i < B->getOCarW(); i++)
				for (int j = 0; j < B->getOCarH(); j++) {

					COORD prePos = B->getPrePos();
					prePos.X += (2 * i) + posStd.X;
					prePos.Y += (1 * j) + posStd.Y;

					if (prePos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), prePos);
						cout << "  ";

					}

				}

			for (int i = 0; i < B->getCarW(); i++)
				for (int j = 0; j < B->getCarH(); j++) {

					COORD pos = { B->getRealPosX() + posStd.X + (i * 2), B->getPosY() + posStd.Y + (j * 1) };

					if (pos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
						cout << "■";

					}

				}

			B->setPrePos(B->getRealPosX(), B->getPosY());

		}

	//Show CarC

	if (L.getCount()[2])
		for (int k = 0; k++ < L.getCount()[2]; C = C->getNext()) {

			for (int i = 0; i < C->getOCarW();i++)
				for (int j = 0; j < C->getOCarH();j++) {

					COORD prePos = C->getPrePos();
					prePos.X += (2 * i) + posStd.X;
					prePos.Y += (1 * j) + posStd.Y;

					if (prePos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), prePos);
						cout << "  ";

					}

				}

			for (int i = 0; i < C->getCarW(); i++)
				for (int j = 0; j < C->getCarH(); j++) {

					COORD pos = { C->getRealPosX() + posStd.X + (i * 2), C->getPosY() + posStd.Y + (j * 1) };

					if (pos.Y > 2) {

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
						cout << "■";

					}

				}

			C->setPrePos(C->getRealPosX(), C->getPosY());

		}

}

void dispInGameOopsBox(int color, bool isLeft) {

	static const COORD LeftBoxTopPoint = { 8, 38 };
	static const COORD LeftBoxMidPoint = { LeftBoxTopPoint.X, LeftBoxTopPoint.Y + 1 };
	static const COORD LeftBoxBottomPoint = { LeftBoxTopPoint.X, LeftBoxTopPoint.Y + 2 };
	static const COORD RightBoxTopPoint = { 28, LeftBoxTopPoint.Y };
	static const COORD RightBoxMidPoint = { RightBoxTopPoint.X, RightBoxTopPoint.Y + 1 };
	static const COORD RightBoxBottomPoint = { RightBoxTopPoint.X, RightBoxTopPoint.Y + 2 };

	Setting::setColor(color);

	if (isLeft) {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LeftBoxTopPoint);
		cout << "┌────┐";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LeftBoxMidPoint);
		cout << "│ Oops!! │";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LeftBoxBottomPoint);
		cout << "└────┘";

	}
	else {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), RightBoxTopPoint);
		cout << "┌────┐";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), RightBoxMidPoint);
		cout << "│ Oops!! │";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), RightBoxBottomPoint);
		cout << "└────┘";

	}

	Setting::setColor(7);

}

void dispInGameGAMEOVER(Env& E, _M& M, int now, int highest) {

	using std::cin;

	bool isLeft = ((E.roadX / 2) < M.getPosX());

	cin.get();
	
	for (int i = 0; i++ < 6;) {

		dispInGameOopsBox(12, isLeft);
		con.csDelay(0.1);
		dispInGameOopsBox(14, isLeft);
		con.csDelay(0.2);
		dispInGameOopsBox(15, isLeft);
		con.csDelay(0.1);
		dispInGameOopsBox(14, isLeft);
		con.csDelay(0.2);

	}

	static const COORD FullBoxStartPoint = { 0,3 };
	int* ConsoleSize = con.csSize(Setting::scrSize[0], Setting::scrSize[1]);

	con.boxOpen();
	con.boxLine("이번 점수 :           최고 점수 :          ");
	con.boxClose();

	dispInGameScorePanel(now, highest);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), FullBoxStartPoint);

	Setting::setColor(15);

	con.boxOpen();
	con.boxLine();
	con.boxLineCenter("[게임 결과]");
	con.boxLine();
	con.boxLine();
	con.boxLine();

	Setting::setSelection(true);
	
	if (now && now >= highest) {

		cout
			<< "                                                " << endl
			<< " ##    ## ####### ##      ##                    " << endl
			<< " ###   ## ##      ##  ##  ##                    " << endl
			<< " ####  ## ##      ##  ##  ##                    " << endl
			<< " ## ## ## #####   ##  ##  ##                    " << endl
			<< " ##  #### ##      ##  ##  ##                    " << endl
			<< " ##   ### ##      ##  ##  ##                    " << endl
			<< " ##    ## #######  ########                     " << endl
			<< "                                                " << endl
			<< " ######  ####### ####    ###  ######  #####  ## " << endl
			<< " ##   ## ##      ##  ## ##  # ##   ## ##  ## ## " << endl
			<< " ##   ## ##      ##     ##  # ##   ## ##  ## ## " << endl
			<< " ######  #####   ##     ##  # ######  ##  ##  # " << endl
			<< " ## ##   ##      ##     ##  # ## ##   ##  ##    " << endl
			<< " ##  ##  ##      ##  ## ##  # ##  ##  ##  ## ## " << endl
			<< " ##   ## ####### #####   ###  ##   ## #####  ## " << endl
			<< "                                                " << endl;

		/* Because of font problem, this code cannot be used.
		con.boxLineCenter("╔╗╔╔═╗╦ ╦          ");
		con.boxLineCenter("║║║║╣ ║║║          ");
		con.boxLineCenter("╝╚╝╚═╝╚╩╝          ");
		con.boxLineCenter("╦═╗╔═╗╔═╗╔═╗╦═╗╔╦╗┬");
		con.boxLineCenter("╠╦╝║╣ ║  ║ ║╠╦╝ ║║│");
		con.boxLineCenter("╩╚═╚═╝╚═╝╚═╝╩╚══╩╝o");
		*/

	}
	else {

		con.boxLine();
		con.boxLineCenter(" ######      ###    ##     ## ######## ");
		con.boxLineCenter("##    ##    ## ##   ###   ### ##       ");
		con.boxLineCenter("##         ##   ##  #### #### ##       ");
		con.boxLineCenter("##   #### ##     ## ## ### ## ######   ");
		con.boxLineCenter("##    ##  ######### ##     ## ##       ");
		con.boxLineCenter("##    ##  ##     ## ##     ## ##       ");
		con.boxLineCenter(" ######   ##     ## ##     ## ######## ");
		con.boxLine();
		con.boxLineCenter(" #######  ##     ## ######## ########  ");
		con.boxLineCenter("##     ## ##     ## ##       ##     ## ");
		con.boxLineCenter("##     ## ##     ## ##       ##     ## ");
		con.boxLineCenter("##     ## ##     ## ######   ########  ");
		con.boxLineCenter("##     ##  ##   ##  ##       ##   ##   ");
		con.boxLineCenter("##     ##   ## ##   ##       ##    ##  ");
		con.boxLineCenter(" #######     ###    ######## ##     ## ");
		con.boxLine();

	}

	Setting::setSelection(false);

	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLineCenter((now && now >= highest) ? "오우~~ 대단해요!!!♥♥♥" : "흥, 다시 해요!! 점수가 이따구야...");
	con.boxLine();
	con.boxLineCenter("<ENTER> 키를 눌러 메뉴로 돌아가세요.");
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxLine();
	con.boxClose();

	Setting::setColor(7);

	cout << " [ALERT] <ENTER>키를 누르십시오 . . .";

	Setting::setColor(0);

	cin.get();

}
