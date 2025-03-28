#pragma once

#include<windows.h>
#include<stdexcept>

class WinManager
{
public:

	WinManager(HINSTANCE hInstance);

	void SL_RegisterClass(PCWSTR pClassName);
	HWND SL_CreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const;


private:
	HINSTANCE hInstance{};
	HWND hWnd{};
	PCWSTR pClassName{};
};

