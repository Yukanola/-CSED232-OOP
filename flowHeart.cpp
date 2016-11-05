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

	SetConsoleTitle(_T("OOPA CHAR Beta"));

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
	- [SOLVED] Hardness를 정해야 한다.
	- [SOLVED] 게임에서 Blocker들은 양 벽에 닿을 수 있어야 한다.
	- [SOLVED] 게임에서 Blocker들은 양 벽에서 생성될 수 있어야 한다.
	- [SOLVED] 게임에서 캐릭터의 색을 설정할 수 있어야 한다.
	- [SOLVED] Dequeue 시킬 수 있어야 한다.
	- [SOLVED] A 대상을 B와 C로 확장시킬 수 있어야 한다.
	- [SOLVED] 모든 Blocker들에 대해서, Pixel에 자신의 영역이 올바르게 등록되어야 한다.
	- [SOLVED] 게임이 끝나고, 가운데에 정보를 띄워야 한다.
	- [SOLVED] Pixel 등록에 대해서 다시한 번 Pixel을 통일할 필요가 있다.
	- [SOLVED] 모든 Position 개념을 Pixel 중심으로 바꾸어야 한다.
	- [SOLVED] 모든 Size 개념을 Pixel 중심으로 바꾸어야 한다.
	- [SOLVED] 더이상 Queue가 아니므로, List라는 이름으로 바꾸어야 한다.
	- [SOLVED] prePos만 실제 X, Y를 따른다. 단, 원점의 기준은 Pixel과 같다.
	- [SOLVED] 우측 벽이 파괴되지 않도록 해야 한다.
	- [SOLVED] 가로 길이가 3 이상인 Blocker들에 대해서, 가장 왼쪽에서 생성될 때 벽을 넘지 못하도록 해야 한다.
	- [SOLVED] 주석을 제거하고, 각종 숫자를 제거해야 한다.
	- [SOLVED] 게임을 하고 돌아왔을 때, "- 메뉴 선택 -" 이라는 문구가 표시되어야 한다.
	- [SOLVED] 화면의 색을 일정하게 유지해야 한다.
	- [SOLVED] 모든 new에 대해서 delete를 시켜주어야 한다. (Destructor)
	- [SOLVED] 게임 설정 중 ESC를 눌러 메인 메뉴로 나갈 수 있어야 한다.

	- 도로 너비가 바뀌어도 작동해야 한다.
	- WCD 함수를 완성시켜야 한다.
	- Game Class를 만들어야 한다.

	TOPIC LIST

	- &과 *의 사용, 그리고 typeid 함수
	- Console에서의 전각/반각 문자와 좌표

*/
