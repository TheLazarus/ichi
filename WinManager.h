#pragma once

#include <windows.h>

typedef LRESULT(WINAPI *WinProc)(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP);

class WinManager
{
public:
	WinManager(HINSTANCE hInstance);

	void SL_RegisterClass(PCWSTR pClassName, WinProc winProc);
	HWND SL_CreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const;

private:
	HINSTANCE hInstance{};
	HWND hWnd{};
	PCWSTR pClassName{};
};
