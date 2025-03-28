#include "slaga.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
	WinManager winManager(hInstance);

	PCWSTR WIN_CLASS = L"SL_MAIN", WIN_TITLE = L"SLAGA";
	int xPos = 0.5, yPos = 0.5, nWidth = 400, nHeight = 400;

	winManager.SL_RegisterClass(WIN_CLASS);
	HWND hWnd = winManager.SL_CreateWindow(WIN_TITLE, xPos, yPos, nWidth, nHeight);


	LPMSG msg;
	while(GetMessage(msg, hWnd, 0, 0) > 0) {

		
	}
	return 0;

}