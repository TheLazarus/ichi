#include "headers/NecoWinManager.h"

NecoWinManager::NecoWinManager(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}

void NecoWinManager::NecoRegisterClass(PCWSTR pClassName, WinProc winProc)
{

	try
	{
		WNDCLASSEXW wc{};

		wc.cbSize = sizeof(WNDCLASSEXW);
		wc.lpfnWndProc = winProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = nullptr;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.lpszClassName = pClassName;

		this->pClassName = pClassName;

		if (RegisterClassEx(&wc) == 0)
		{
			throw L"Failed to register Window Class";
		}
	}
	catch (PCWSTR ex)
	{
		MessageBox(nullptr, ex, L"Error", MB_ICONEXCLAMATION | MB_OK);
		exit(-1);
	}
}

HWND NecoWinManager::NecoCreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const
{

	HWND hWnd = CreateWindowW(pClassName, pWinName, WS_SYSMENU, xPos, yPos, nWidth, nHeight, nullptr, nullptr, hInstance, nullptr);

	if (hWnd == nullptr)
	{
		MessageBox(nullptr, L"Window Creation Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hWnd;
}
