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
	- [SOLVED] Hardness�� ���ؾ� �Ѵ�.
	- [SOLVED] ���ӿ��� Blocker���� �� ���� ���� �� �־�� �Ѵ�.
	- [SOLVED] ���ӿ��� Blocker���� �� ������ ������ �� �־�� �Ѵ�.
	- [SOLVED] ���ӿ��� ĳ������ ���� ������ �� �־�� �Ѵ�.
	- [SOLVED] Dequeue ��ų �� �־�� �Ѵ�.
	- [SOLVED] A ����� B�� C�� Ȯ���ų �� �־�� �Ѵ�.
	- [SOLVED] ��� Blocker�鿡 ���ؼ�, Pixel�� �ڽ��� ������ �ùٸ��� ��ϵǾ�� �Ѵ�.
	- [SOLVED] ������ ������, ����� ������ ����� �Ѵ�.
	- [SOLVED] Pixel ��Ͽ� ���ؼ� �ٽ��� �� Pixel�� ������ �ʿ䰡 �ִ�.
	- [SOLVED] ��� Position ������ Pixel �߽����� �ٲپ�� �Ѵ�.
	- [SOLVED] ��� Size ������ Pixel �߽����� �ٲپ�� �Ѵ�.
	- [SOLVED] ���̻� Queue�� �ƴϹǷ�, List��� �̸����� �ٲپ�� �Ѵ�.
	- [SOLVED] prePos�� ���� X, Y�� ������. ��, ������ ������ Pixel�� ����.
	- [SOLVED] ���� ���� �ı����� �ʵ��� �ؾ� �Ѵ�.
	- [SOLVED] ���� ���̰� 3 �̻��� Blocker�鿡 ���ؼ�, ���� ���ʿ��� ������ �� ���� ���� ���ϵ��� �ؾ� �Ѵ�.

	- ��� new�� ���ؼ� delete�� �����־�� �Ѵ�. (Destructor)
	- ���� �ʺ� �ٲ� �۵��ؾ� �Ѵ�.
	- WCD �Լ��� �ϼ����Ѿ� �Ѵ�.
	- Game Class�� ������ �Ѵ�.
	- �ּ��� �����ϰ�, ���� ���ڸ� �����ؾ� �Ѵ�.
	- ������ �ϰ� ���ƿ��� ��, "- �޴� ���� -" �̶�� ������ ǥ�õǾ�� �Ѵ�.

	TOPIC LIST

	- &�� *�� ���, �׸��� typeid �Լ�
	- Console������ ����/�ݰ� ���ڿ� ��ǥ

*/
