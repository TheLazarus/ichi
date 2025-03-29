#include "IchiProcManager.h"

IchiProcManager::IchiProcManager(HWND hWnd)
{
    this->hWnd = hWnd;
}

void IchiProcManager::SetProcIdentifiers()
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

void IchiProcManager::PrintProcName(DWORD pid)
{

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);

    if (hProcess != nullptr)
    {
        HINSTANCE procModule{};
        DWORD moduleSizeInBytes{};

        wchar_t procModuleName[1000]{};

        if (EnumProcessModulesEx(hProcess, &procModule, sizeof(procModule), &moduleSizeInBytes, LIST_MODULES_ALL))
        {
            GetModuleBaseName(hProcess, procModule, procModuleName, sizeof(procModuleName) / sizeof(wchar_t));
        }

        MessageBox(hWnd, procModuleName, L"Ichi", MB_OKCANCEL);
        CloseHandle(hProcess);
    }
}

void IchiProcManager::PrintProcs()
{
    if (!noOfProcIdn)
        return;

    for (int i = 0; i < noOfProcIdn; i++)
    {
        DWORD pid = procs[i];
        if (pid != 0)
        {

            PrintProcName(pid);
        }
    }
}
