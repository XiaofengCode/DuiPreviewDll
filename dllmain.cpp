// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "StdAfx.h"
HMODULE g_hInstance = NULL;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		g_hInstance = hModule;
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		g_hInstance = NULL;
		break;
	}
	return TRUE;
}

