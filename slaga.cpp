#include "slaga.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
	WinManager winManager(hInstance);

	PCWSTR WIN_CLASS = L"SL_MAIN", WIN_TITLE = L"SLAGA";
	int xPos = 0.5, yPos = 0.5, nWidth = 400, nHeight = 400;

	winManager.SL_RegisterClass(WIN_CLASS);
	winManager.SL_CreateWindow(WIN_CLASS, xPos, yPos, nWidth, nHeight);


	return 0;

}