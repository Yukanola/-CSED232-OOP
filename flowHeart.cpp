#include "libKano.cp.h"
#include "Parameter.h"
#include <tchar.h>

void dispSplash();
bool procMenu();
bool Setting::ableCursor(bool);
void dispEndSplash();

int main(int argc, char** argv) {

	Kano::init(true);

	deb("Set Console Title.");

	SetConsoleTitle(_T("OOPA CHAR Alpha"));

	deb("Set console size.");

	con.csSize(Setting::scrSize[0], Setting::scrSize[1]);

	deb("Turn off default console cursor.");

	Setting::ableCursor(false);

	deb("Starts loop command.");

	for (dispSplash();procMenu(););

	deb("Loop command exited.");

	dispEndSplash();

	return Kano::end(0x0000);

}
