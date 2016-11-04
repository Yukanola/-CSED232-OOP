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
	- [SOLVED] Hardness를 정해야 한다.
	- [SOLVED] 게임에서 Blocker들은 양 벽에 닿을 수 있어야 한다.
	- [SOLVED] 게임에서 Blocker들은 양 벽에서 생성될 수 있어야 한다.
	- [SOLVED] 게임에서 캐릭터의 색을 설정할 수 있어야 한다.
	- WCD 함수를 완성시켜야 한다.
	- [SOLVED] Dequeue 시킬 수 있어야 한다.
	- [SOLVED] A 대상을 B와 C로 확장시킬 수 있어야 한다.
	- 가로 길이가 3 이상인 Blocker들에 대해서, 가장 왼쪽에서 생성될 때 벽을 넘지 못하도록 해야 한다.
	- [SOLVED] 모든 Blocker들에 대해서, Pixel에 자신의 영역이 올바르게 등록되어야 한다.
	- 주석을 제거하고, 각종 숫자를 제거해야 한다.
	- [SOLVED] 게임이 끝나고, 가운데에 정보를 띄워야 한다.
	- Pixel 등록에 대해서 다시한 번 Pixel을 통일할 필요가 있다.
	- 모든 new에 대해서 delete를 시켜주어야 한다. (Destructor)
	- 모든 Position 개념을 Pixel 중심으로 바꾸어야 한다.
	- 모든 Size 개념을 Pixel 중심으로 바꾸어야 한다.

	TOPIC LIST

	- &과 *의 사용, 그리고 typeid 함수

*/
