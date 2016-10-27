#include "libKano.cp.h"
#include "Parameter.h"
#include "Classes.h"

using namespace Setting;
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
		<< endl << "                                       Alpha    " << endl << endl
		<< endl << "                                                ";

	deb("Splash has been displayed.");

	con.csDelay(1.3);

}

void dispMenu(int cursor) {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl;
	con.printSpaceCenter("- �޴� ���� -");
	cout << endl << endl << endl;

	if (cursor == 1)
		Setting::setSelection(true);
	con.printSpaceCenter("1. ���� ����");
	cout << endl << endl;
	if (cursor == 1)
		Setting::setSelection(false);

	if (cursor == 2)
		Setting::setSelection(true);
	con.printSpaceCenter("2. ���� ����");
	cout << endl << endl;
	if (cursor == 2)
		Setting::setSelection(false);

	if (cursor == 3)
		Setting::setSelection(true);
	con.printSpaceCenter("3. ���� ����");
	cout << endl << endl << endl << endl << endl << endl;
	if (cursor == 3)
		Setting::setSelection(false);

	con.printSpaceCenter("������������������������");
	cout << endl;
	con.printSpaceCenter("�� �޴��� �����ϼ���. ��");
	cout << endl;
	con.printSpaceCenter("��                    ��");
	con.printSpaceCenter("�� �����Ϸ��� [ENTER] ��");
	cout << endl;
	con.printSpaceCenter("������������������������");

}

void dispHardnessSet(int cursor) {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);

	cout << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl;
	con.printSpaceCenter("- ���̵� ���� -");
	cout << endl << endl << endl;

	if (cursor == 1)
		Setting::setSelection(true);
	con.printSpaceCenter("1. ���� ����");
	cout << endl << endl;
	if (cursor == 1)
		Setting::setSelection(false);

	if (cursor == 2)
		Setting::setSelection(true);
	con.printSpaceCenter("2. ����");
	cout << endl << endl;
	if (cursor == 2)
		Setting::setSelection(false);

	if (cursor == 3)
		Setting::setSelection(true);
	con.printSpaceCenter("3. ����");
	cout << endl << endl;
	if (cursor == 3)
		Setting::setSelection(false);

	if (cursor == 4)
		Setting::setSelection(true);
	con.printSpaceCenter("4. �����");
	cout << endl << endl;
	if (cursor == 4)
		Setting::setSelection(false);

	if (cursor == 5)
		Setting::setSelection(true);
	con.printSpaceCenter("5. ���� �����");
	cout << endl << endl << endl << endl << endl << endl;
	if (cursor == 5)
		Setting::setSelection(false);

	con.printSpaceCenter("������������������������");
	cout << endl;
	con.printSpaceCenter("�� �޴��� �����ϼ���. ��");
	cout << endl;
	con.printSpaceCenter("��                    ��");
	con.printSpaceCenter("�� �����Ϸ��� [ENTER] ��");
	cout << endl;
	con.printSpaceCenter("������������������������");

}

void dispInstruction() {

	cls();

	con.setCS(Setting::scrSize[0], Setting::scrSize[1]);
	
	cout << endl;
	con.printSpaceCenter("- ���� ���� -");
	cout << endl << endl;
	con.boxOpen();
	con.boxLineCenter("[���丮]");
	con.boxLine();
	con.boxLine();
	con.boxLine(" �������� ���� ������� ��ũ���� ���� ������");
	con.boxLine("����. ������ ȭ��� ���ٴ� ��Ȳ�� ������ ��");
	con.boxLine("�ڱ� �������, ������ ã����޴� ������ ����");
	con.boxLine("�� ��Ȳ�� ������ â��IT���հ��а��� ������");
	con.boxLine("�������� ��ġ���ߴٴ� ����� �˰Եȴ�.");
	con.boxLine();
	con.boxLineCenter(" \"��, ������ ����! ������ �����ְھ�!��\" ");
	con.boxLine();
	con.boxLine(" �׷��� ������ ������ ��Ȳ�� ������ ã�� ��");
	con.boxLine("���� �ȴ�. ������ �׷� �׳ฦ ���Ƽ� �͵���");
	con.boxLine("�ٸ� �ƴ� ������ ������ ������ ������ ������");
	con.boxLine("�Ѽ��� ����, ������ ����, �ѿ�� ���� �׸���");
	con.boxLine("�׵��� ���������̾���.");
	con.boxLine(" ������ ������ �˾ƺ� �渷�� �̷���. ������ ");
	con.boxLine("������ ���ϵ��� �ڵ� ���� DELLA, �� ������");
	con.boxLine("������ ø�ڷ� ��ǻ�� ���а��� ������� ����");
	con.boxLine("�� �־��� ���̴�.");
	con.boxLine();
	con.boxLineCenter("\"������..! �������� �ʰھ�..!!����\"");
	con.boxLine();
	con.boxLine(" ��� ����� �˰� ȭ�� �Ӹ� ������ ġ�о� ��");
	con.boxLine("�� �׳�� �׷��� ������ ������ ������ �аŸ�");
	con.boxLine("�� ������ ������.");
	con.boxLine();
	con.boxLine(" ��, �츮 ���� ������ ������ ���� �����Ͽ�");
	con.boxLine("�����̴� ������ ���� ���ϵ��� ���� ���� ��Ȳ");
	con.boxLine("�� ������ ���Ϸ� �� ����!");
	con.boxClose();

	cout << endl;

	con.boxOpen();
	con.boxLineCenter("[���۹�]");
	con.boxLine();
	con.boxLineCenter(" ��/�� : ������ ���� �� �̵�");
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
			cout << "�����";
			break;

		case 1:
			cout << "    ��  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point2);

		switch (i) {

		case 3:
		case 2:
			cout << "      ��";
			break;

		case 1:
			cout << "  ���  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point3);

		switch (i) {

		case 3:
		case 2:
			cout << "�����";
			break;

		case 1:
			cout << "    ��  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point4);

		switch (i) {

		case 2:
			cout << "��      ";
			break;

		case 3:
			cout << "      ��";
			break;

		case 1:
			cout << "    ��  ";
			break;

		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point5);

		switch (i) {

		case 3:
		case 2:
			cout << "�����";
			break;

		case 1:
			cout << "  ����";
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

	int* ConsoleSize = con.csSize(Setting::scrSize[0], Setting::scrSize[1]);
	int padding = (((ConsoleSize[0]) - (E->roadX)) / 4) - 1;

	con.boxOpen();
	con.boxLine("���� ���� :           �ְ� ���� :          ");
	con.boxClose();

	for (int i = 0; i < E->roadY; i++) {

		for (int j = 0; j < padding-2; j++)
			cout << " ";

		printf("%2d", i);

		Setting::setColor(15);
		cout << "��";
		Setting::setColor(7);
		for (int j = 0; j < E->roadX; j++)
			printf("%2d", j);//cout << "  ";
		Setting::setColor(15);
		cout << "��";
		Setting::setColor(7);

		cout << endl;

	}

}

void dispInGameScorePanel(int now, int highest) {

	COORD posNOW = { 14, 1 }, posHIGHEST = { 36, 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNOW);

	cout << now << " ��";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posHIGHEST);

	cout << highest << " ��";

}

void dispInGameEY(int* pos, Env* E) {

	int* ConsoleSize = con.setCS(Setting::scrSize[0], Setting::scrSize[1]);
	int padding = (((ConsoleSize[0]) - (E->roadX)) / 4) + 1;
	static COORD preXY = { pos[0] + padding, pos[1] + 3 };
	COORD XY = { pos[0] + padding, pos[1] + 3 };

	int preY = preXY.Y;

	for (int i = 0; i++ < E->EX; preXY.X += 2) {

		for (int j = 0; j++ < E->EY; preXY.Y += 1) {

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), preXY);
			cout << "  ";

		}

		preXY.Y = preY;

	}

	preXY.X = pos[0] + padding, preXY.Y = pos[1] + 3;

	for (int i = 0; i++ < E->EY; XY.X += 2) {

		for (int j = 0; j++ < E->EY; XY.Y += 1) {

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
			Setting::setColor(14);
			cout << "��";
			Setting::setColor(7);

		}

		XY.Y = pos[1] + 3;

	}
		

	

}

void dispInGameLane(_Q& Q) {

	//Show Left Lane

	//Show Center Lane

	//Show Right Lane

}
