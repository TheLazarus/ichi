#include "WinManager.h"

WinManager::WinManager(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}

void WinManager::SL_RegisterClass(PCWSTR pClassName, WinProc winProc)
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

HWND WinManager::SL_CreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const
{

	HWND hWnd = CreateWindowW(pClassName, pWinName, WS_SYSMENU, xPos, yPos, nWidth, nHeight, nullptr, nullptr, hInstance, nullptr);

	if (hWnd == nullptr)
	{
		MessageBox(nullptr, L"Window Creation Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hWnd;
}

