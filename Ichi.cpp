#include "Ichi.h"



int WINAPI wWinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] PWSTR lpCmdLine, [[maybe_unused]] int nCmdShow)
{
	IchiWinManager winManager(hInstance);

	PCWSTR WIN_CLASS = L"ICHI_MAIN", WIN_TITLE = L"Ichi";
	int xPos = 0.5, yPos = 0.5, nWidth = 400, nHeight = 400;

	winManager.RegClass(WIN_CLASS, WinProcedure);
	HWND hWnd = winManager.CreateWin(WIN_TITLE, xPos, yPos, nWidth, nHeight);

	IchiProcManager procManager(hWnd);

	ShowWindow(hWnd, SW_SHOW);

	procManager.SetProcIdentifiers();
	procManager.PrintProcs();

	MSG msg;
	while (GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}