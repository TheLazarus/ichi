#ifndef ICHI_PROC_MANAGER
#define ICHI_PROC_MANAGER

#include "IchiWin.h"
#include <psapi.h>
#include <stdlib.h>

class IchiProcManager
{
private:
    DWORD procs[1024]{}, procDataInBytes{}, noOfProcIdn{};
    HWND hWnd;

    void PrintProcName(DWORD pid);

public:
    IchiProcManager(HWND hWnd);
    void SetProcIdentifiers();
    void PrintProcs();
};

#endif