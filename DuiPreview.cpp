// DuiPreview.cpp : 定义 DLL 应用程序的导出函数。
//

#include "StdAfx.h"
#include "../DuilibPreview/MainWnd.h"


#define DP_EXPORT EXTERN_C _declspec(dllexport)
extern HMODULE g_hInstance;

CMainWnd* g_pDlg = NULL;

DP_EXPORT HWND Preview(LPCWSTR lpwszSkinFile, HWND hParent)
{
// 	CPaintManagerUI::SetInstance(g_hInstance);
// 	CPaintManagerUI::SetResourcePath(szDir);
	//DBGMSG(_T("xxx"));
	if (g_pDlg)
	{
		g_pDlg->Close();
		delete g_pDlg;
		g_pDlg = NULL;
	}
	
	CDuiString strDir(lpwszSkinFile);

	int nPos = strDir.ReverseFind('\\');
	if (nPos >= 0)
	{
		strDir.Delete(nPos, strDir.GetLength() - nPos);
	}
	SetCurrentDirectory(strDir);

	CPaintManagerUI::SetInstance(g_hInstance);
	CPaintManagerUI::SetResourcePath(strDir);
	g_pDlg = new CMainWnd(lpwszSkinFile);
	//g_pDlg->SetSkinFile(lpwszSkinFile);
	g_pDlg->Create(hParent, NULL, UI_WNDSTYLE_CHILD, 0);
	if (!g_pDlg->IsLoadSkinSuccess())
	{
		return NULL;
	}
	g_pDlg->ShowWindow(true, false);
	return g_pDlg->GetHWND();
}