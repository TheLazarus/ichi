#include "IchiWinProcedure.h"

LRESULT WINAPI WinProcedure(HWND hWnd, UINT uMsg, WPARAM wP, LPARAM lP)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        if (MessageBox(hWnd, L"Wanna really quit Ichi?", L"Ichi", MB_OKCANCEL) == IDOK)
        {
            DestroyWindow(hWnd);
        }
        break;

    default:
        return DefWindowProc(hWnd, uMsg, wP, lP);
    }
    return 0;
}
