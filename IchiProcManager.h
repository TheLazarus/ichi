#ifndef ICHI_PROC_MANAGER
#define ICHI_PROC_MANAGER

#include <windows.h>
#include <psapi.h>

class IchiProcManager
{
public:
    IchiProcManager(HWND hWnd);
    void GetProcIdn();
    void PrintProcNames();

private:
    DWORD procs[1024]{}, procDataInBytes{}, noOfProcIdn{};
    HWND hWnd;
};

#endif