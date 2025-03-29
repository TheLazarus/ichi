#ifndef ICHI_WIN_MANAGER
#define ICHI_WIN_MANAGER

#include "IchiWin.h"
#include <stdlib.h>

typedef LRESULT(WINAPI *WinProc)(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP);

class IchiWinManager
{

private:
	HINSTANCE hInstance{};
	HWND hWnd{};
	PCWSTR pClassName{};

public:
	IchiWinManager(HINSTANCE hInstance);

	void RegClass(PCWSTR pClassName, WinProc winProc);
	HWND CreateWin(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const;
};

#endif
