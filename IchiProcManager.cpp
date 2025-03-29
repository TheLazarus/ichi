#include "IchiProcManager.h"

IchiProcManager::IchiProcManager(HWND hWnd)
{
    this->hWnd = hWnd;
}

void IchiProcManager::GetProcIdn()
{

    try
    {

        int procRetStatus = EnumProcesses(procs, sizeof(procs), &procDataInBytes);
        if (!procRetStatus)
        {
            throw L"Process Enumeration Failed";
        }

        noOfProcIdn = procDataInBytes / sizeof(DWORD);
    }

    catch (PCWSTR msg)
    {
        MessageBox(hWnd, msg, L"Ichi", MB_OKCANCEL);
        exit(-1);
    }
}

void IchiProcManager::PrintProcNames()
{
    if (!noOfProcIdn)
        return;

    for (int i = 0; i < noOfProcIdn; i++)
    {
        DWORD pid = procs[i];
        if (pid != 0)
        {
        }
    }
}
