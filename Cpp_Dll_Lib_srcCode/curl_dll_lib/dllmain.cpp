// dllmain.cpp : Defines the entry point for the DLL application.
#include "curl_lib_header.hpp"
#define dllexport __declspec(dllexport)
#define def_cdecl __cdecl

dllexport bool def_cdecl InitCURL(char* hostname) {
    if (InitCurl(hostname)) {
        return true;
    }
    else {
        return false;
    }
}
dllexport bool def_cdecl CheckTor(char* filename_phpfile) {
    if (CheckTORDownloaded(filename_phpfile)) {
        return true;
    }
    else {
        return false;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

