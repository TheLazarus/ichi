#include "WinManager.h"

WinManager::WinManager(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}

void WinManager::SL_RegisterClass(PCWSTR pClassName)
{

	try
	{
		WNDCLASSEXW wc{};

		

		wc.cbSize = sizeof(WNDCLASSEXW);
		wc.lpfnWndProc = DefWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = nullptr;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.lpszClassName = pClassName;

		OutputDebugString(pClassName);

		this->pClassName = pClassName;

		if (RegisterClassExW(&wc) == 0)
		{
			throw std::runtime_error("Failed to register Window Class");
		}
	}
	catch (const std::exception &ex)
	{
		MessageBoxA(nullptr, ex.what(), "Error", MB_ICONEXCLAMATION | MB_OK);
		exit(-1);
	}
}

HWND WinManager::SL_CreateWindow(PCWSTR pWinName, int xPos, int yPos, int nWidth, int nHeight) const
{

	HWND hWnd = CreateWindowW(pClassName, pWinName, 0, xPos, yPos, nWidth, nHeight, nullptr, nullptr, hInstance, nullptr);

	if (hWnd == nullptr)
	{
		MessageBoxW(nullptr, L"Window Creation Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hWnd;
}