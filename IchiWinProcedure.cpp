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
    case WM_PAINT:
    {
        LPCWSTR msg = L"Hi Windows";
        PAINTSTRUCT ps{};
        HDC hdc = BeginPaint(hWnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        SetTextColor(hdc, RGB(255, 0, 0));

        RECT drawArea{0, 0, 100, 100};

        DrawText(hdc, msg, 10, &drawArea, DT_CENTER);

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_QUIT:
        PostQuitMessage(-1);
        return -1;

    default:
        return DefWindowProc(hWnd, uMsg, wP, lP);
    }
    return 0;
}
