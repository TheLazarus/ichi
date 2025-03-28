#include "headers/Neco.h"

LRESULT WINAPI WinProcedure(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		if (MessageBox(hWnd, L"Wanna really quit SLAGA?", L"SLAGA", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hWnd);
		}
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wP, lP);
	}
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
	NecoWinManager winManager(hInstance);

	PCWSTR WIN_CLASS = L"SL_MAIN", WIN_TITLE = L"SLAGA";
	int xPos = 0.5, yPos = 0.5, nWidth = 400, nHeight = 400;

	winManager.NecoRegisterClass(WIN_CLASS, WinProcedure);
	HWND hWnd = winManager.NecoCreateWindow(WIN_TITLE, xPos, yPos, nWidth, nHeight);
	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	while (GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}