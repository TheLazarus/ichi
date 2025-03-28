#pragma once

#include <windows.h>

typedef LRESULT(WINAPI *WinProc)(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP);

class NecoWinManager
{
public:
	NecoWinManager(HINSTANCE hInstance);

	void NecoRegisterClass(PCWSTR pClassName, WinProc winProc);
	HWND NecoCreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const;

private:
	HINSTANCE hInstance{};
	HWND hWnd{};
	PCWSTR pClassName{};
};
