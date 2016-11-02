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

	- [SOLVED] 게임에서 캐릭터는 양 벽에 닿을 수 있어야 한다.
	- [SOLVED] Operator Overloading을 사용할 수 없다.
	- Game Class를 만들어야 한다.
	- Hardness를 정해야 한다.
	- 게임에서 Blocker들은 양 벽에 닿을 수 있어야 한다.
	- 게임에서 Blocker들은 양 벽에서 생성될 수 있어야 한다.
	- 게임에서 캐릭터의 색을 설정할 수 있어야 한다.
	- WCD 함수를 완성시켜야 한다.
	- Dequeue 시킬 수 있어야 한다.
	- A 대상을 B와 C로 확장시킬 수 있어야 한다.

	TOPIC LIST

	- &과 *의 사용, 그리고 typeid 함수

*/
