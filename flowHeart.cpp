#include "Core.kano.h"
#include "WCD.kano.h"
#include "Parameter.h"
#include <tchar.h>

void dispSplash();
bool procMenu();
bool Setting::ableCursor(bool);
void dispEndSplash();

int main(int argc, char** argv) {

	Kano::Core_init(false);
	Kano::WCD_init(Setting::scrSize[0], Setting::scrSize[1]);

	deb("Set Console Title.");

	SetConsoleTitle(_T("OOPA CHAR Alpha"));

	deb("Turn off default console cursor.");

	Setting::ableCursor(false);

	deb("Starts loop command.");

	for (dispSplash(); procMenu(););

	deb("Loop command exited.");

	dispEndSplash();

	return Kano::end(0x0000);

}

/*

	TODO LIST

	- [SOLVED] ���ӿ��� ĳ���ʹ� �� ���� ���� �� �־�� �Ѵ�.
	- [SOLVED] Operator Overloading�� ����� �� ����.
	- Game Class�� ������ �Ѵ�.
	- Hardness�� ���ؾ� �Ѵ�.
	- ���ӿ��� Blocker���� �� ���� ���� �� �־�� �Ѵ�.
	- ���ӿ��� Blocker���� �� ������ ������ �� �־�� �Ѵ�.
	- ���ӿ��� ĳ������ ���� ������ �� �־�� �Ѵ�.
	- WCD �Լ��� �ϼ����Ѿ� �Ѵ�.
	- Dequeue ��ų �� �־�� �Ѵ�.
	- A ����� B�� C�� Ȯ���ų �� �־�� �Ѵ�.

	TOPIC LIST

	- &�� *�� ���, �׸��� typeid �Լ�

*/
