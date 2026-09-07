// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_services_watch/vmpi_browser_services.cpp
// Functions: 255
// ============================================================

#include "utils\vmpi\vmpi_services_watch\vmpi_browser_services.h"

//------------------------------------------------------------------------------
// Address: 0x00405D70
// Name: public: virtual int CWinApp::SupportsRestartManager(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsRestartManager(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405D80
// Name: public: virtual int CWinApp::SupportsApplicationRecovery(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsApplicationRecovery(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00405D90
// Name: public: virtual int CWinApp::SupportsAutosaveAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00405DA0
// Name: public: virtual int CWinApp::SupportsAutosaveAtInterval(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtInterval(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00405DB0
// Name: public: virtual int CWinApp::ReopenPreviousFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ReopenPreviousFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00405DC0
// Name: public: virtual int CWinApp::RestoreAutosavedFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::RestoreAutosavedFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x00405DD0
// Name: public: virtual unsigned long CWinApp::GetApplicationRestartFlags(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CWinApp::GetApplicationRestartFlags(CWinApp *this)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405DE0
// Name: public: virtual unsigned long CWinApp::GetApplicationRecoveryPingInterval(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::GetApplicationRecoveryPingInterval(CWinApp *this)
{
  return 5000;
}

//------------------------------------------------------------------------------
// Address: 0x00405DF0
// Name: public: virtual int CVMPIBrowserServicesApp::InitInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIBrowserServicesApp::InitInstance(CVMPIBrowserServicesApp *this)
{
  CServicesDlg dlg; // [esp+4h] [ebp-484h] BYREF
  int v4; // [esp+484h] [ebp-4h]

  AfxEnableControlContainer(pOccManager: nullptr);
  CServicesDlg::CServicesDlg(this: &dlg, pParent: nullptr);
  v4 = 0;
  this->m_pMainWnd = &dlg;
  CDialog::DoModal(this: &dlg);
  v4 = -1;
  CServicesDlg::~CServicesDlg(this: &dlg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405E70
// Name: protected: virtual struct AFX_MSGMAP const __near * CVMPIBrowserServicesApp::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CVMPIBrowserServicesApp::GetMessageMap(CVMPIBrowserServicesApp *this)
{
  return (const AFX_MSGMAP *)&off_52BDBC;
}

//------------------------------------------------------------------------------
// Address: 0x00412BB8
// Name: public: static void CWinApp::DoEnableModeless(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CWinApp::DoEnableModeless(int bEnable)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd != nullptr && MainWnd->IsFrameWnd(this: MainWnd) != 0 && MainWnd[1].m_pProxy != nullptr )
    ((void (__thiscall *)(IAccessibleProxy *, int))MainWnd[1].m_pProxy->__vftable[6].AddRef)(
      a1: MainWnd[1].m_pProxy,
      a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x00412C93
// Name: public: void CWinApp::EnableModeless(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::EnableModeless(CWinApp *this, int bEnable)
{
  CWinApp::DoEnableModeless(bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x00412CA5
// Name: public: static int CWinApp::ShowAppMessageBox(class CWinApp __near *,char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CWinApp::ShowAppMessageBox(CWinApp *pApp, const char *lpszPrompt, UINT nType, unsigned int nIDPrompt)
{
  unsigned int *p_m_dwPromptContext; // esi
  HWND SafeOwner; // eax
  HWND v6; // ebx
  LRESULT v7; // eax
  unsigned int v8; // eax
  const char *m_pszAppName; // ebx
  int v10; // edi
  HWND__ *hWnd; // [esp+10h] [ebp-118h]
  unsigned int dwWndPid; // [esp+14h] [ebp-114h] BYREF
  unsigned int dwOldPromptContext; // [esp+18h] [ebp-110h]
  HWND__ *hWndTop; // [esp+1Ch] [ebp-10Ch] BYREF
  char szAppName[260]; // [esp+20h] [ebp-108h] BYREF

  p_m_dwPromptContext = nullptr;
  CWinApp::DoEnableModeless(bEnable: 0);
  SafeOwner = CWnd::GetSafeOwner_(hParent: nullptr, pWndTop: &hWndTop);
  v6 = SafeOwner;
  hWnd = SafeOwner;
  if ( SafeOwner != hWndTop )
    EnableWindow(hWnd: SafeOwner, bEnable: true);
  dwWndPid = 0;
  GetWindowThreadProcessId(hWnd: v6, lpdwProcessId: &dwWndPid);
  if ( v6 != nullptr
    && dwWndPid == GetCurrentProcessId()
    && (v7 = SendMessageA(hWnd: v6, Msg: 0x376u, wParam: 0, lParam: 0)) != 0 )
  {
    p_m_dwPromptContext = (unsigned int *)v7;
  }
  else if ( pApp != nullptr )
  {
    p_m_dwPromptContext = &pApp->m_dwPromptContext;
  }
  dwOldPromptContext = 0;
  if ( p_m_dwPromptContext != nullptr )
  {
    dwOldPromptContext = *p_m_dwPromptContext;
    if ( nIDPrompt != 0 )
      *p_m_dwPromptContext = nIDPrompt + 196608;
  }
  if ( (nType & 0xF0) == 0 )
  {
    v8 = nType & 0xF;
    if ( v8 <= 1 )
    {
      nType |= 0x30u;
    }
    else if ( v8 - 3 <= 1 )
    {
      nType |= 0x20u;
    }
  }
  szAppName[0] = 0;
  if ( pApp != nullptr )
  {
    m_pszAppName = pApp->m_pszAppName;
  }
  else
  {
    m_pszAppName = szAppName;
    if ( GetModuleFileNameA(hModule: nullptr, lpFilename: szAppName, nSize: 0x104u) == 260 )
      szAppName[259] = 0;
  }
  v10 = AfxCtxMessageBoxA(hWnd, lpText: lpszPrompt, lpCaption: m_pszAppName, uType: nType);
  if ( p_m_dwPromptContext != nullptr )
    *p_m_dwPromptContext = dwOldPromptContext;
  if ( hWndTop != nullptr )
    EnableWindow(hWnd: hWndTop, bEnable: true);
  CWinApp::DoEnableModeless(bEnable: 1);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00412E39
// Name: public: virtual int CWinApp::DoMessageBox(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::DoMessageBox(CWinApp *this, const char *lpszPrompt, UINT nType, unsigned int nIDPrompt)
{
  return CWinApp::ShowAppMessageBox(pApp: this, lpszPrompt, nType, nIDPrompt);
}

//------------------------------------------------------------------------------
// Address: 0x00412ED4
// Name: protected: static struct AFX_MSGMAP const __near * CWinApp::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CWinApp::GetThisMessageMap(CWinApp *this)
{
  return &messageMap_5;
}

//------------------------------------------------------------------------------
// Address: 0x00412EDA
// Name: protected: int CWinApp::_LoadSysPolicies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::_LoadSysPolicies(CWinApp *this)
{
  _AfxSysPolicies *i; // ebx
  _AfxSysPolicyData *j; // esi
  unsigned int dwID; // ecx
  unsigned int dwDataLen; // [esp+8h] [ebp-14h] BYREF
  CWinApp *v6; // [esp+Ch] [ebp-10h]
  unsigned int dwType; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwValue; // [esp+14h] [ebp-8h] BYREF
  HKEY__ *hkPolicy; // [esp+18h] [ebp-4h] BYREF

  this->m_dwPolicies = 0;
  v6 = this;
  hkPolicy = nullptr;
  dwValue = 0;
  dwDataLen = 4;
  dwType = 0;
  for ( i = rgPolicies; i->szPolicyKey != nullptr; ++i )
  {
    if ( RegOpenKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: i->szPolicyKey,
           ulOptions: 0,
           samDesired: 1u,
           phkResult: &hkPolicy) == 0 )
    {
      for ( j = i->pData; j->szPolicyName != nullptr; ++j )
      {
        if ( RegQueryValueExA(
               hKey: hkPolicy,
               lpValueName: j->szPolicyName,
               lpReserved: nullptr,
               lpType: &dwType,
               lpData: (LPBYTE)&dwValue,
               lpcbData: &dwDataLen) == 0
          && dwType == 4 )
        {
          dwID = j->dwID;
          if ( dwValue != 0 )
            v6->m_dwPolicies |= dwID;
          else
            v6->m_dwPolicies &= ~dwID;
        }
        dwValue = 0;
        dwDataLen = 4;
        dwType = 0;
      }
      RegCloseKey(hKey: hkPolicy);
      hkPolicy = nullptr;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412F9F
// Name: public: virtual int CWinApp::InitApplication(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::InitApplication(CWinApp *this)
{
  CDocManager *m_pDocManager; // ecx

  if ( CDocManager::pStaticDocManager != nullptr )
  {
    if ( this->m_pDocManager == nullptr )
      this->m_pDocManager = CDocManager::pStaticDocManager;
    CDocManager::pStaticDocManager = nullptr;
  }
  m_pDocManager = this->m_pDocManager;
  if ( m_pDocManager != nullptr )
    m_pDocManager->AddDocTemplate(this: m_pDocManager, a2: nullptr);
  else
    CDocManager::bStaticInit = 0;
  this->LoadSysPolicies(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412FDF
// Name: public: virtual int CWinApp::RestartInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::RestartInstance(CWinApp *this)
{
  int v1; // edi
  CDataRecoveryHandler *v2; // esi

  v1 = 0;
  v2 = this->GetDataRecoveryHandler(this);
  if ( v2 != nullptr && v2->ReadOpenDocumentList(this: v2) != 0 )
  {
    v1 = v2->ReopenPreviousDocuments(this: v2);
    v2->RestoreAutosavedDocuments(this: v2);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00413011
// Name: protected: void CWinApp::SaveStdProfileSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SaveStdProfileSettings(CWinApp *this)
{
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->WriteList(this: this->m_pRecentFileList);
  if ( this->m_nNumPreviewPages != 0 )
    this->WriteProfileInt(this, a2: "Settings", a3: "PreviewPages", a4: this->m_nNumPreviewPages);
}

//------------------------------------------------------------------------------
// Address: 0x0041304D
// Name: public: virtual int CWinApp::ExitInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ExitInstance(CWinApp *this)
{
  CCommandLineInfo *m_pCmdInfo; // eax
  CCommandLineInfo::<unnamed_type_m_nShellCommand> m_nShellCommand; // eax
  void (*m_lpfnDaoTerm)(void); // eax
  int v5; // esi

  m_pCmdInfo = this->m_pCmdInfo;
  if ( (m_pCmdInfo == nullptr
     || (m_nShellCommand = m_pCmdInfo->m_nShellCommand) != AppUnregister && m_nShellCommand != AppRegister)
    && AfxGetModuleState()->m_bDLL == 0 )
  {
    CWinApp::SaveStdProfileSettings(this);
  }
  m_lpfnDaoTerm = this->m_lpfnDaoTerm;
  if ( m_lpfnDaoTerm != nullptr )
    m_lpfnDaoTerm();
  if ( this->m_hLangResourceDLL != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hLangResourceDLL);
    this->m_hLangResourceDLL = nullptr;
  }
  v5 = 0;
  if ( AfxGetCurrentMessage() != nullptr )
    return AfxGetCurrentMessage()->wParam;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004130D8
// Name: public: virtual long CWinApp::RegisterWithRestartManager(wchar_t const __near *,unsigned long,unsigned long (*)(void __near *),void __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWinApp::RegisterWithRestartManager(
        CWinApp *this,
        const wchar_t *pwzCommandLineArgs,
        DWORD dwRestartFlags,
        unsigned int (__stdcall *pRecoveryCallback)(void *),
        void *lpvParam,
        DWORD dwPingInterval,
        DWORD dwCallbackFlags)
{
  HMODULE ModuleHandleW; // eax
  HMODULE v8; // edi
  HRESULT (__stdcall *RegisterApplicationRestart)(PCWSTR, DWORD); // ebx
  HRESULT (__stdcall *RegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD); // eax
  HRESULT (__stdcall *v11)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD); // esi
  HRESULT result; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v8 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
    AfxThrowInvalidArgException();
  RegisterApplicationRestart = (HRESULT (__stdcall *)(PCWSTR, DWORD))GetProcAddress(
                                                                       hModule: ModuleHandleW,
                                                                       lpProcName: "RegisterApplicationRestart");
  RegisterApplicationRecoveryCallback = (HRESULT (__stdcall *)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD))GetProcAddress(hModule: v8, lpProcName: "RegisterApplicationRecoveryCallback");
  v11 = RegisterApplicationRecoveryCallback;
  if ( RegisterApplicationRestart == nullptr )
    return 0;
  if ( RegisterApplicationRecoveryCallback == nullptr )
    return 0;
  result = RegisterApplicationRestart(pwzCommandline: pwzCommandLineArgs, dwFlags: dwRestartFlags);
  if ( result == 0 )
  {
    if ( pRecoveryCallback == nullptr )
      return 0;
    result = v11(pRecoveyCallback: pRecoveryCallback, pvParameter: lpvParam, dwPingInterval, dwFlags: dwCallbackFlags);
    if ( result == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413144
// Name: public: virtual unsigned long CWinApp::ApplicationRecoveryCallback(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ApplicationRecoveryCallback(CWinApp *this, void *__formal)
{
  HMODULE ModuleHandleW; // eax
  HMODULE v3; // edi
  HRESULT (__stdcall *ApplicationRecoveryInProgress)(PBOOL); // ebx
  void (__stdcall *ApplicationRecoveryFinished)(BOOL); // eax
  void (__stdcall *v6)(BOOL); // edi
  int v7; // esi
  CDataRecoveryHandler *v8; // eax
  int bRecoveryCanceled; // [esp+10h] [ebp-4h] BYREF

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v3 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
    AfxThrowInvalidArgException();
  ApplicationRecoveryInProgress = (HRESULT (__stdcall *)(PBOOL))GetProcAddress(
                                                                  hModule: ModuleHandleW,
                                                                  lpProcName: "ApplicationRecoveryInProgress");
  ApplicationRecoveryFinished = (void (__stdcall *)(BOOL))GetProcAddress(
                                                            hModule: v3,
                                                            lpProcName: "ApplicationRecoveryFinished");
  v6 = ApplicationRecoveryFinished;
  if ( ApplicationRecoveryInProgress != nullptr && ApplicationRecoveryFinished != nullptr )
  {
    bRecoveryCanceled = 0;
    ApplicationRecoveryInProgress(pbCancelled: &bRecoveryCanceled);
    if ( bRecoveryCanceled == 0 )
    {
      v7 = 1;
      v8 = this->GetDataRecoveryHandler(this);
      if ( v8 != nullptr )
        v7 = v8->SaveOpenDocumentList(this: v8);
      v6(bSuccess: v7);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004131C0
// Name: public: virtual long CWinApp::ProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::ProcessWndProcException(CWinApp *this, CException *e, const tagMSG *pMsg)
{
  int v3; // ebx
  int v4; // esi

  v3 = 0;
  if ( e == nullptr || pMsg == nullptr )
    AfxThrowInvalidArgException();
  if ( pMsg->message == 1 || pMsg->message == 15 )
    return CWinThread::ProcessWndProcException(this, e, pMsg);
  v4 = 61704;
  if ( pMsg->message == 273 )
  {
    if ( pMsg->lParam == 0 )
      v4 = 61705;
    v3 = 1;
  }
  if ( CObject::IsKindOf(this: e, pClass: &CMemoryException::classCMemoryException) != 0 )
  {
    ((void (__stdcall *)(int, int))e->ReportError)(a1: 4144, a2: v4);
  }
  else if ( CObject::IsKindOf(this: e, pClass: &CUserException::classCUserException) == 0 )
  {
    ((void (__stdcall *)(int, int))e->ReportError)(a1: 16, a2: v4);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00413243
// Name: public: virtual int CWinApp::OnIdle(long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::OnIdle(CWinApp *this, __POSITION *lCount)
{
  int v2; // ebx
  CDocTemplate *v4; // eax
  CDataRecoveryHandler *v5; // eax

  v2 = (int)lCount;
  if ( (int)lCount > 0 )
  {
    if ( lCount == (__POSITION *)1 )
      CWinThread::OnIdle(this, lCount: 1);
  }
  else
  {
    CWinThread::OnIdle(this, (int)lCount);
    lCount = nullptr;
    if ( this->m_pDocManager != nullptr )
    {
      lCount = this->m_pDocManager->GetFirstDocTemplatePosition(this: this->m_pDocManager);
      while ( lCount != nullptr )
      {
        v4 = this->m_pDocManager->GetNextDocTemplate(this: this->m_pDocManager, a2: &lCount);
        v4->OnIdle(this: v4);
      }
    }
    v5 = this->GetDataRecoveryHandler(this);
    if ( v5 != nullptr )
      v5->SetSaveDocumentInfoOnIdle(this: v5, a2: 0);
  }
  return v2 < 1;
}

//------------------------------------------------------------------------------
// Address: 0x004132C0
// Name: public: void CWinApp::DevModeChange(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::DevModeChange(CWinApp *this, char *lpDeviceName)
{
  void *m_hDevNames; // eax
  const char *v4; // eax
  SIZE_T v5; // eax
  HGLOBAL v6; // eax
  _devicemodeA *v7; // eax
  void *hPrinter; // [esp+8h] [ebp-4h] BYREF

  m_hDevNames = this->m_hDevNames;
  if ( m_hDevNames != nullptr )
  {
    v4 = (const char *)GlobalLock(hMem: m_hDevNames);
    if ( lstrcmpA(lpString1: &v4[*((unsigned __int16 *)v4 + 1)], lpString2: lpDeviceName) == 0
      && OpenPrinterA(pPrinterName: lpDeviceName, phPrinter: &hPrinter, pDefault: nullptr) )
    {
      if ( this->m_hDevMode != nullptr )
        AfxGlobalFree(hGlobal: this->m_hDevMode);
      v5 = DocumentPropertiesA(
             hWnd: nullptr,
             hPrinter,
             pDeviceName: lpDeviceName,
             pDevModeOutput: nullptr,
             pDevModeInput: nullptr,
             fMode: 0);
      v6 = GlobalAlloc(uFlags: 0x42u, dwBytes: v5);
      this->m_hDevMode = v6;
      v7 = (_devicemodeA *)GlobalLock(hMem: v6);
      if ( DocumentPropertiesA(
             hWnd: nullptr,
             hPrinter,
             pDeviceName: lpDeviceName,
             pDevModeOutput: v7,
             pDevModeInput: nullptr,
             fMode: 2u) != 1 )
      {
        AfxGlobalFree(hGlobal: this->m_hDevMode);
        this->m_hDevMode = nullptr;
      }
      ClosePrinter(hPrinter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413360
// Name: public: virtual struct CRuntimeClass __near * CWinApp::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWinApp::GetRuntimeClass(CWinApp *this)
{
  return &CWinApp::classCWinApp;
}

//------------------------------------------------------------------------------
// Address: 0x00413625
// Name: public: virtual int CWinApp::LoadSysPolicies(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CWinApp::LoadSysPolicies(CWinApp *this)
{
  return CWinApp::_LoadSysPolicies(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041362A
// Name: public: virtual struct HINSTANCE__ __near * CWinApp::LoadAppLangResourceDLL(void)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWinApp::LoadAppLangResourceDLL(CWinApp *this)
{
  DWORD ModuleFileNameA; // eax
  char szPath[260]; // [esp+4h] [ebp-114h] BYREF
  char szFormat[12]; // [esp+108h] [ebp-10h] BYREF

  ModuleFileNameA = GetModuleFileNameA(hModule: this->m_hInstance, lpFilename: szPath, nSize: 0x104u);
  if ( ModuleFileNameA == 0 || ModuleFileNameA == 260 )
    return nullptr;
  *PathFindExtensionA(pszPath: szPath) = 0;
  strcpy(szFormat, "%s%s.dll");
  return AfxLoadLangResourceDLL(pszFormat: szFormat, pszPath: szPath);
}

//------------------------------------------------------------------------------
// Address: 0x0041369E
// Name: public: virtual int CWinApp::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::Run(CWinApp *this)
{
  if ( this->m_pMainWnd == nullptr && AfxOleGetUserCtrl() != 0 )
    AfxPostQuitMessage(nExitCode: 0);
  return CWinThread::Run(this);
}

//------------------------------------------------------------------------------
// Address: 0x004136C1
// Name: public: virtual void CWinApp::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::WinHelpA(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->WinHelpA(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x00413702
// Name: public: virtual void CWinApp::HtmlHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::HtmlHelpA(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->HtmlHelpA(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x00413746
// Name: public: virtual void CWinApp::WinHelpInternal(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::WinHelpInternal(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->WinHelpInternal(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x004137B4
// Name: public: virtual class CDataRecoveryHandler __near * CWinApp::GetDataRecoveryHandler(void)
// Source: json
//------------------------------------------------------------------------------
CDataRecoveryHandler *__thiscall CWinApp::GetDataRecoveryHandler(CWinApp *this)
{
  CDataRecoveryHandler *v2; // ecx
  CDataRecoveryHandler *v3; // eax
  CDataRecoveryHandler *m_pDataRecoveryHandler; // ecx

  if ( afxGlobalData.bIsWindowsVista != 0
    && (this->SupportsRestartManager(this) != 0 || this->SupportsApplicationRecovery(this) != 0)
    && bTriedOnce == 0
    && this->m_pDataRecoveryHandler == nullptr )
  {
    v2 = (CDataRecoveryHandler *)operator new(nSize: 0xCCu);
    v3 = v2 != nullptr
       ? CDataRecoveryHandler::CDataRecoveryHandler(
           this: v2,
           dwRestartManagerSupportFlags: this->m_dwRestartManagerSupportFlags,
           nAutosaveInterval: this->m_nAutosaveInterval)
       : nullptr;
    this->m_pDataRecoveryHandler = v3;
    if ( v3->Initialize(this: v3) == 0 )
    {
      m_pDataRecoveryHandler = this->m_pDataRecoveryHandler;
      if ( m_pDataRecoveryHandler != nullptr )
        ((void (__thiscall *)(CDataRecoveryHandler *, int))m_pDataRecoveryHandler->dtr_CObject)(
          a1: m_pDataRecoveryHandler,
          a2: 1);
      this->m_pDataRecoveryHandler = nullptr;
    }
  }
  bTriedOnce = 1;
  return this->m_pDataRecoveryHandler;
}

//------------------------------------------------------------------------------
// Address: 0x00413960
// Name: public: CWinApp::CWinApp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWinApp *__thiscall CWinApp::CWinApp(CWinApp *this, char *lpszAppName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // ebx
  AFX_MODULE_THREAD_STATE *Data; // eax

  CWinThread::CWinThread(this);
  this->__vftable = (CWinApp_vtbl *)&CWinApp::`vftable';
  if ( lpszAppName != nullptr )
    this->m_pszAppName = _strdup(string: lpszAppName);
  else
    this->m_pszAppName = nullptr;
  ModuleState = AfxGetModuleState();
  v4 = ModuleState;
  if ( ModuleState == nullptr
    || (Data = CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread)) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  Data->m_pCurrentWinThread = this;
  this->m_hThread = GetCurrentThread();
  this->m_nThreadID = GetCurrentThreadId();
  v4->m_pCurrentWinApp = this;
  this->m_atomSystemTopic = 0;
  this->m_atomApp = 0;
  this->m_hInstance = nullptr;
  this->m_hLangResourceDLL = nullptr;
  this->m_pszHelpFilePath = nullptr;
  this->m_pszProfileName = nullptr;
  this->m_pszRegistryKey = nullptr;
  this->m_pszExeName = nullptr;
  this->m_pRecentFileList = nullptr;
  this->m_pDocManager = nullptr;
  this->m_lpCmdLine = nullptr;
  this->m_pCmdInfo = nullptr;
  this->m_pDataRecoveryHandler = nullptr;
  this->m_nWaitCursorCount = 0;
  this->m_hcurWaitCursorRestore = nullptr;
  this->m_hDevMode = nullptr;
  this->m_hDevNames = nullptr;
  this->m_nNumPreviewPages = 0;
  this->m_lpfnDaoTerm = nullptr;
  this->m_bHelpMode = 0;
  this->m_eHelpType = afxWinHelp;
  this->m_nSafetyPoolSize = 512;
  this->m_dwRestartManagerSupportFlags = 0;
  this->m_nAutosaveInterval = 300000;
  this->m_bTaskbarInteractionEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413AAB
// Name: public: virtual CWinApp::~CWinApp(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CWinApp::~CWinApp(CWinApp *this)
{
  CDocManager *m_pDocManager; // ecx
  CRecentFileList *m_pRecentFileList; // ecx
  CDataRecoveryHandler *m_pDataRecoveryHandler; // ecx
  CCommandLineInfo *m_pCmdInfo; // ecx
  AFX_MODULE_STATE *ModuleState; // eax

  this->__vftable = (CWinApp_vtbl *)&CWinApp::`vftable';
  m_pDocManager = this->m_pDocManager;
  if ( m_pDocManager != nullptr )
    ((void (__thiscall *)(CDocManager *, int))m_pDocManager->dtr_CObject)(a1: m_pDocManager, a2: 1);
  m_pRecentFileList = this->m_pRecentFileList;
  if ( m_pRecentFileList != nullptr )
    ((void (__thiscall *)(CRecentFileList *, int))m_pRecentFileList->dtr_CRecentFileList)(a1: m_pRecentFileList, a2: 1);
  m_pDataRecoveryHandler = this->m_pDataRecoveryHandler;
  if ( m_pDataRecoveryHandler != nullptr )
    ((void (__thiscall *)(CDataRecoveryHandler *, int))m_pDataRecoveryHandler->dtr_CObject)(
      a1: m_pDataRecoveryHandler,
      a2: 1);
  if ( AfxGetModuleState()->m_bDLL == 0 )
  {
    if ( CDocManager::pStaticList != nullptr )
    {
      ((void (__thiscall *)(CPtrList *, int))CDocManager::pStaticList->dtr_CObject)(a1: CDocManager::pStaticList, a2: 1);
      CDocManager::pStaticList = nullptr;
    }
    if ( CDocManager::pStaticDocManager != nullptr )
    {
      ((void (__thiscall *)(CDocManager *, int))CDocManager::pStaticDocManager->dtr_CObject)(
        a1: CDocManager::pStaticDocManager,
        a2: 1);
      CDocManager::pStaticDocManager = nullptr;
    }
  }
  if ( this->m_hDevMode != nullptr )
    AfxGlobalFree(hGlobal: this->m_hDevMode);
  if ( this->m_hDevNames != nullptr )
    AfxGlobalFree(hGlobal: this->m_hDevNames);
  if ( this->m_atomApp != 0 )
    GlobalDeleteAtom(nAtom: this->m_atomApp);
  if ( this->m_atomSystemTopic != 0 )
    GlobalDeleteAtom(nAtom: this->m_atomSystemTopic);
  m_pCmdInfo = this->m_pCmdInfo;
  if ( m_pCmdInfo != nullptr )
    ((void (__thiscall *)(CCommandLineInfo *, int))m_pCmdInfo->dtr_CObject)(a1: m_pCmdInfo, a2: 1);
  ModuleState = AfxGetModuleState();
  if ( ModuleState->m_lpszCurrentAppName == this->m_pszAppName )
    ModuleState->m_lpszCurrentAppName = nullptr;
  if ( ModuleState->m_pCurrentWinApp == this )
    ModuleState->m_pCurrentWinApp = nullptr;
  free(pBlock: (void *)this->m_pszAppName);
  free(pBlock: (void *)this->m_pszRegistryKey);
  free(pBlock: (void *)this->m_pszExeName);
  free(pBlock: (void *)this->m_pszHelpFilePath);
  free(pBlock: (void *)this->m_pszProfileName);
  this->m_hThread = nullptr;
  CWinThread::~CWinThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x00413CBA
// Name: public: virtual int CWinApp::InitInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::InitInstance(CWinApp *this)
{
  HINSTANCE__ *v2; // ebx
  CWinApp_vtbl *v3; // edi
  int v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  this->InitLibId(this);
  v2 = this->LoadAppLangResourceDLL(this);
  this->m_hLangResourceDLL = v2;
  if ( v2 != nullptr )
  {
    AfxGetModuleState()->m_hCurrentResourceHandle = v2;
    InterlockedExchange(
      Target: (volatile LONG *)&ATL::_AtlBaseModule.m_hInstResource,
      Value: (LONG)this->m_hLangResourceDLL);
  }
  if ( this->SupportsRestartManager(this) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &v6,
      pszSrc: szGroupName);
    v3 = this->__vftable;
    v7 = 0;
    v4 = ((int (__thiscall *)(CWinApp *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v3->SupportsApplicationRecovery)(
           a1: this,
           a2: &v6);
    ((void (__thiscall *)(CWinApp *, int))v3->RegisterWithRestartManager)(a1: this, a2: v4);
    ATL::CStringData::Release(this: (ATL::CStringData *)v6.m_pszData - 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413D49
// Name: public: virtual long CWinApp::RegisterWithRestartManager(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWinApp::RegisterWithRestartManager(
        CWinApp *this,
        int bRegisterRecoveryCallback,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strRestartIdentifierParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  ATL::CStringData *v6; // eax
  CAfxStringMgr *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CDataRecoveryHandler *v11; // eax
  char *m_str; // eax
  CWinApp_vtbl *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  wchar_t *v18; // eax
  CWinApp_vtbl *v19; // esi
  int v20; // eax
  int v21; // esi
  ATL::CStringData *v23; // [esp-4h] [ebp-48h]
  wchar_t *m_pszData; // [esp+0h] [ebp-44h]
  ATL::CComBSTR v25; // [esp+10h] [ebp-34h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+14h] [ebp-30h] BYREF
  ATL::CSimpleStringT<char,0> v27; // [esp+18h] [ebp-2Ch] BYREF
  ATL::CSimpleStringT<char,0> v28; // [esp+1Ch] [ebp-28h] BYREF
  ATL::CSimpleStringT<char,0> v29; // [esp+20h] [ebp-24h] BYREF
  GUID pguid; // [esp+24h] [ebp-20h] BYREF
  int v31; // [esp+40h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v29, pStringMgr: StringManager);
  v31 = 0;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v28, pStringMgr: v5);
  v23 = (ATL::CStringData *)(strRestartIdentifierParam->m_pszData - 16);
  LOBYTE(v31) = 1;
  v6 = ATL::CSimpleStringT<char,0>::CloneData(pData: v23);
  v26.m_pszData = (char *)&v6[1];
  LOBYTE(v31) = 2;
  if ( v6->nDataLength == 0 )
  {
    memset(&pguid, 0, sizeof(pguid));
    CoCreateGuid(&pguid);
    v7 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v27, pStringMgr: v7);
    LOBYTE(v31) = 3;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &v26,
      pszFormat: "%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
      pguid.Data1,
      pguid.Data2,
      pguid.Data3,
      pguid.Data4[0],
      pguid.Data4[1],
      pguid.Data4[2],
      pguid.Data4[3],
      pguid.Data4[4],
      pguid.Data4[5],
      pguid.Data4[6],
      pguid.Data4[7]);
    LOBYTE(v31) = 2;
    ATL::CStringData::Release(this: (ATL::CStringData *)v27.m_pszData - 1);
  }
  ATL::CSimpleStringT<char,0>::SetString(this: &v29, pszSrc: this->m_lpCmdLine);
  strlen(buf: "RestartByRestartManager");
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: "RestartByRestartManager", nLength: v8);
  strlen(buf: ":");
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: ":", nLength: v9);
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: v26.m_pszData, nLength: *((_DWORD *)v26.m_pszData - 3));
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v29,
         pszSub: v28.m_pszData,
         iStart: 0) == -1 )
  {
    strlen(buf: " /");
    ATL::CSimpleStringT<char,0>::Append(this: &v29, pszSrc: " /", nLength: v10);
    ATL::CSimpleStringT<char,0>::Append(this: &v29, pszSrc: v28.m_pszData, nLength: *((_DWORD *)v28.m_pszData - 3));
  }
  v11 = this->GetDataRecoveryHandler(this);
  if ( v11 != nullptr )
    v11->SetRestartIdentifier(this: v11, a2: &v26);
  if ( bRegisterRecoveryCallback != 0 )
  {
    m_str = (char *)ATL::CComBSTR::CComBSTR(this: &v25, pSrc: v29.m_pszData)->m_str;
    v13 = this->__vftable;
    LOBYTE(v31) = 4;
    v27.m_pszData = m_str;
    v14 = ((int (__thiscall *)(CWinApp *, _DWORD))v13->GetApplicationRecoveryPingInterval)(a1: this, a2: 0);
    v15 = ((int (__thiscall *)(CWinApp *, int))this->GetApplicationRecoveryParameter)(a1: this, a2: v14);
    v16 = ((int (__thiscall *)(CWinApp *, unsigned int (__stdcall *)(void *), int))this->GetApplicationRestartFlags)(
            a1: this,
            a2: AfxApplicationRecoveryWrapper,
            a3: v15);
    v17 = ((int (__thiscall *)(CWinApp *, char *, int))v13->RegisterWithRestartManager)(
            a1: this,
            a2: v27.m_pszData,
            a3: v16);
    m_pszData = v25.m_str;
  }
  else
  {
    v18 = ATL::CComBSTR::CComBSTR(this: (ATL::CComBSTR *)&v27, pSrc: v29.m_pszData)->m_str;
    v19 = this->__vftable;
    LOBYTE(v31) = 5;
    v25.m_str = v18;
    v20 = ((int (__thiscall *)(CWinApp *, _DWORD, _DWORD, _DWORD, _DWORD))v19->GetApplicationRestartFlags)(
            a1: this,
            a2: 0,
            a3: 0,
            a4: 0,
            a5: 0);
    v17 = ((int (__thiscall *)(CWinApp *, wchar_t *, int))v19->RegisterWithRestartManager)(
            a1: this,
            a2: v25.m_str,
            a3: v20);
    m_pszData = (wchar_t *)v27.m_pszData;
  }
  v21 = v17;
  SysFreeString(bstrString: m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v28.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v29.m_pszData - 1);
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x00413F5F
// Name: protected: void CWinApp::OnHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnHelp(CWinApp *this)
{
  unsigned int m_dwPromptContext; // eax
  CFrameWnd *MainWnd; // esi

  m_dwPromptContext = this->m_dwPromptContext;
  if ( m_dwPromptContext != 0 )
  {
    if ( m_dwPromptContext != 258311 )
      this->WinHelpInternal(this, a2: m_dwPromptContext, a3: 1u);
  }
  else
  {
    MainWnd = (CFrameWnd *)AfxGetMainWnd();
    if ( MainWnd == nullptr )
      AfxThrowInvalidArgException();
    if ( MainWnd->IsFrameWnd(this: MainWnd) != 0 )
      CFrameWnd::OnHelp(this: MainWnd);
    else
      CWnd::OnHelp(this: MainWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004146D9
// Name: public: virtual int CWinApp::IsTaskbarInteractionEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::IsTaskbarInteractionEnabled(CWinApp *this)
{
  BOOL result; // eax

  result = false;
  if ( afxGlobalData.bIsWindows7 != 0 )
    return this->m_bTaskbarInteractionEnabled != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004147C8
// Name: public: struct HKEY__ __near * CWinApp::GetAppRegistryKey(class ATL::CAtlTransactionManager __near *)
// Source: json
//------------------------------------------------------------------------------
HKEY__ *__thiscall CWinApp::GetAppRegistryKey(CWinApp *this, ATL::CAtlTransactionManager *pTM)
{
  LSTATUS v3; // eax
  int v4; // eax
  const char *m_pszRegistryKey; // [esp-20h] [ebp-3Ch]
  const char *m_pszProfileName; // [esp-20h] [ebp-3Ch]
  HKEY__ *hAppKey; // [esp+Ch] [ebp-10h] BYREF
  unsigned int dw; // [esp+10h] [ebp-Ch] BYREF
  HKEY__ *hCompanyKey; // [esp+14h] [ebp-8h] BYREF
  HKEY__ *hSoftKey; // [esp+18h] [ebp-4h] BYREF

  hAppKey = nullptr;
  hSoftKey = nullptr;
  hCompanyKey = nullptr;
  if ( pTM != nullptr )
    v3 = ATL::CAtlTransactionManager::RegOpenKeyExA(
           this: pTM,
           hKey: (HKEY__ *)0x80000001,
           lpSubKey: "software",
           ulOptions: 0,
           samDesired: 0x2001Fu,
           phkResult: &hSoftKey);
  else
    v3 = RegOpenKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: "software",
           ulOptions: 0,
           samDesired: 0x2001Fu,
           phkResult: &hSoftKey);
  if ( v3 == 0 )
  {
    m_pszRegistryKey = this->m_pszRegistryKey;
    v4 = pTM != nullptr
       ? ATL::CAtlTransactionManager::RegCreateKeyExA(
           this: pTM,
           hKey: hSoftKey,
           lpSubKey: m_pszRegistryKey,
           dwReserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0x2001Fu,
           lpSecurityAttributes: nullptr,
           phkResult: &hCompanyKey,
           lpdwDisposition: &dw)
       : RegCreateKeyExA(
           hKey: hSoftKey,
           lpSubKey: m_pszRegistryKey,
           Reserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0x2001Fu,
           lpSecurityAttributes: nullptr,
           phkResult: &hCompanyKey,
           lpdwDisposition: &dw);
    if ( v4 == 0 )
    {
      m_pszProfileName = this->m_pszProfileName;
      if ( pTM != nullptr )
        ATL::CAtlTransactionManager::RegCreateKeyExA(
          this: pTM,
          hKey: hCompanyKey,
          lpSubKey: m_pszProfileName,
          dwReserved: 0,
          lpClass: nullptr,
          dwOptions: 0,
          samDesired: 0x2001Fu,
          lpSecurityAttributes: nullptr,
          phkResult: &hAppKey,
          lpdwDisposition: &dw);
      else
        RegCreateKeyExA(
          hKey: hCompanyKey,
          lpSubKey: m_pszProfileName,
          Reserved: 0,
          lpClass: nullptr,
          dwOptions: 0,
          samDesired: 0x2001Fu,
          lpSecurityAttributes: nullptr,
          phkResult: &hAppKey,
          lpdwDisposition: &dw);
    }
  }
  if ( hSoftKey != nullptr )
    RegCloseKey(hKey: hSoftKey);
  if ( hCompanyKey != nullptr )
    RegCloseKey(hKey: hCompanyKey);
  return hAppKey;
}

//------------------------------------------------------------------------------
// Address: 0x00414883
// Name: public: struct HKEY__ __near * CWinApp::GetSectionKey(char const __near *,class ATL::CAtlTransactionManager __near *)
// Source: json
//------------------------------------------------------------------------------
HKEY__ *__thiscall CWinApp::GetSectionKey(CWinApp *this, const char *lpszSection, ATL::CAtlTransactionManager *pTM)
{
  HKEY__ *AppRegistryKey; // edi
  unsigned int dw; // [esp+8h] [ebp-8h] BYREF
  HKEY__ *hSectionKey; // [esp+Ch] [ebp-4h] BYREF

  hSectionKey = nullptr;
  AppRegistryKey = CWinApp::GetAppRegistryKey(this, pTM);
  if ( AppRegistryKey == nullptr )
    return nullptr;
  if ( pTM != nullptr )
    ATL::CAtlTransactionManager::RegCreateKeyExA(
      this: pTM,
      hKey: AppRegistryKey,
      lpSubKey: lpszSection,
      dwReserved: 0,
      lpClass: nullptr,
      dwOptions: 0,
      samDesired: 0x2001Fu,
      lpSecurityAttributes: nullptr,
      phkResult: &hSectionKey,
      lpdwDisposition: &dw);
  else
    RegCreateKeyExA(
      hKey: AppRegistryKey,
      lpSubKey: lpszSection,
      Reserved: 0,
      lpClass: nullptr,
      dwOptions: 0,
      samDesired: 0x2001Fu,
      lpSecurityAttributes: nullptr,
      phkResult: &hSectionKey,
      lpdwDisposition: &dw);
  RegCloseKey(hKey: AppRegistryKey);
  return hSectionKey;
}

//------------------------------------------------------------------------------
// Address: 0x004148DD
// Name: public: virtual unsigned int CWinApp::GetProfileIntA(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
UINT __thiscall CWinApp::GetProfileIntA(CWinApp *this, unsigned int lpszSection, const char *lpszEntry, INT nDefault)
{
  HKEY SectionKey; // esi
  LSTATUS v6; // ebx
  unsigned int dwType; // [esp+4h] [ebp-8h] BYREF
  unsigned int dwValue; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_pszRegistryKey == nullptr )
    return GetPrivateProfileIntA(
             lpAppName: (LPCSTR)lpszSection,
             lpKeyName: lpszEntry,
             nDefault,
             lpFileName: this->m_pszProfileName);
  SectionKey = CWinApp::GetSectionKey(this, (const char *)lpszSection, pTM: nullptr);
  if ( SectionKey == nullptr )
    return nDefault;
  lpszSection = 4;
  v6 = RegQueryValueExA(
         hKey: SectionKey,
         lpValueName: lpszEntry,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)&dwValue,
         lpcbData: &lpszSection);
  RegCloseKey(hKey: SectionKey);
  if ( v6 != 0 )
    return nDefault;
  else
    return dwValue;
}

//------------------------------------------------------------------------------
// Address: 0x0041494A
// Name: public: virtual int CWinApp::WriteProfileInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HKEY __thiscall CWinApp::WriteProfileInt(CWinApp *this, const char *lpszSection, const char *lpszEntry, int nValue)
{
  HKEY result; // eax
  HKEY v6; // esi
  LSTATUS v7; // edi
  char szT[16]; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_pszRegistryKey != nullptr )
  {
    result = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v6 = result;
    if ( result != nullptr )
    {
      v7 = RegSetValueExA(
             hKey: result,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 4u,
             lpData: (const BYTE *)&nValue,
             cbData: 4u);
      RegCloseKey(hKey: v6);
      return (HKEY)(v7 == 0);
    }
  }
  else
  {
    sprintf_s(string: szT, sizeInBytes: 0x10u, format: "%d", nValue);
    return (HKEY)WritePrivateProfileStringA(
                   lpAppName: lpszSection,
                   lpKeyName: lpszEntry,
                   lpString: szT,
                   lpFileName: this->m_pszProfileName);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004149D5
// Name: public: virtual int CWinApp::WriteProfileStringA(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::WriteProfileStringA(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        const char *lpszValue)
{
  HKEY AppRegistryKey; // eax
  HKEY v5; // esi
  LSTATUS v7; // eax
  HKEY SectionKey; // eax
  int v9; // eax
  LSTATUS v10; // edi

  if ( this->m_pszRegistryKey == nullptr )
    return WritePrivateProfileStringA(
             lpAppName: lpszSection,
             lpKeyName: lpszEntry,
             lpString: lpszValue,
             lpFileName: this->m_pszProfileName);
  if ( lpszEntry != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v5 = SectionKey;
    if ( lpszValue != nullptr )
    {
      if ( SectionKey == nullptr )
        return false;
      v9 = lstrlenA(lpString: lpszValue);
      v7 = RegSetValueExA(
             hKey: v5,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 1u,
             lpData: (const BYTE *)lpszValue,
             cbData: v9 + 1);
    }
    else
    {
      if ( SectionKey == nullptr )
        return false;
      v7 = RegDeleteValueA(hKey: SectionKey, lpValueName: lpszEntry);
    }
  }
  else
  {
    AppRegistryKey = CWinApp::GetAppRegistryKey(this, pTM: nullptr);
    v5 = AppRegistryKey;
    if ( AppRegistryKey == nullptr )
      return false;
    v7 = RegDeleteKeyA(hKey: AppRegistryKey, lpSubKey: lpszSection);
  }
  v10 = v7;
  RegCloseKey(hKey: v5);
  return v10 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414A6E
// Name: public: virtual int CWinApp::WriteProfileBinary(char const __near *,char const __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::WriteProfileBinary(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        unsigned __int8 *pData,
        DWORD nBytes)
{
  HKEY SectionKey; // eax
  HKEY v7; // esi
  LSTATUS v9; // ebx
  char *v10; // esi
  DWORD i; // eax
  int v12; // edi

  if ( this->m_pszRegistryKey != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v7 = SectionKey;
    if ( SectionKey != nullptr )
    {
      v9 = RegSetValueExA(
             hKey: SectionKey,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 3u,
             lpData: pData,
             cbData: nBytes);
      RegCloseKey(hKey: v7);
      return v9 == 0;
    }
    else
    {
      return false;
    }
  }
  else
  {
    v10 = (char *)operator new(nSize: 2 * nBytes + 1);
    for ( i = 0; i < nBytes; ++i )
    {
      v10[2 * i] = (pData[i] & 0xF) + 65;
      v10[2 * i + 1] = (pData[i] >> 4) + 65;
    }
    v10[2 * i] = 0;
    v12 = this->WriteProfileStringA(this, a2: lpszSection, a3: lpszEntry, a4: v10);
    operator delete(p: v10);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414B1A
// Name: public: virtual int CWinApp::GetProfileBinary(char const __near *,char const __near *,unsigned char __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetProfileBinary(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        unsigned __int8 **ppData,
        unsigned int *pBytes)
{
  void **v5; // edi
  unsigned int *v6; // ebx
  int v7; // esi
  HKEY__ *SectionKey; // eax
  LSTATUS Value; // eax
  const char *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned int *v13; // eax
  void *v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // ebx
  char v18; // bl
  int v19; // eax
  ATL::CRegKey rkSecKey; // [esp+10h] [ebp-1Ch] BYREF
  HKEY__ *hSecKey; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+28h] [ebp-4h]

  v5 = (void **)ppData;
  v6 = pBytes;
  v7 = 0;
  *ppData = nullptr;
  *v6 = 0;
  if ( this->m_pszRegistryKey != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    hSecKey = SectionKey;
    if ( SectionKey == nullptr )
      return 0;
    rkSecKey.m_hKey = SectionKey;
    rkSecKey.m_samWOW64 = 0;
    rkSecKey.m_pTM = nullptr;
    v22 = 0;
    ppData = nullptr;
    lpszSection = nullptr;
    Value = RegQueryValueExA(
              hKey: SectionKey,
              lpValueName: lpszEntry,
              lpReserved: nullptr,
              lpType: (LPDWORD)&ppData,
              lpData: nullptr,
              lpcbData: (LPDWORD)&lpszSection);
    v11 = lpszSection;
    *pBytes = (unsigned int)lpszSection;
    if ( Value != 0
      || (v12 = (unsigned __int8 *)operator new(nSize: (unsigned int)v11),
          *v5 = v12,
          RegQueryValueExA(
            hKey: hSecKey,
            lpValueName: lpszEntry,
            lpReserved: nullptr,
            lpType: (LPDWORD)&ppData,
            lpData: v12,
            lpcbData: (LPDWORD)&lpszSection) != 0) )
    {
      operator delete(p: *v5);
      *v5 = nullptr;
    }
    else
    {
      v7 = 1;
    }
    ATL::CRegKey::Close(this: &rkSecKey);
    return v7;
  }
  else
  {
    this->GetProfileStringA(
      this,
      result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszEntry,
      a3: lpszSection,
      a4: lpszEntry,
      a5: nullptr);
    v13 = *((unsigned int **)lpszEntry - 3);
    v22 = 1;
    if ( v13 == nullptr )
    {
      ATL::CStringData::Release(this: (ATL::CStringData *)lpszEntry - 1);
      return 0;
    }
    pBytes = v13;
    *v6 = (unsigned int)v13 >> 1;
    v14 = operator new(nSize: (unsigned int)v13 >> 1);
    v15 = 0;
    for ( *v5 = v14; v15 < (int)pBytes; *((_BYTE *)*v5 + v19) = v18 - 65 )
    {
      v16 = v15 + 1;
      if ( v15 + 1 < 0 || (v17 = *((_DWORD *)lpszEntry - 3), v16 > v17) || v15 < 0 || v15 > v17 )
        ATL::AtlThrowImpl(hr: -2147024809);
      v18 = lpszEntry[v15] + 16 * (lpszEntry[v16] - 1);
      v19 = v15 / 2;
      v15 += 2;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)lpszEntry - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414E0B
// Name: public: struct __POSITION __near * CWinApp::GetFirstDocTemplatePosition(void)const
// Source: json
//------------------------------------------------------------------------------
__POSITION *__thiscall CWinApp::GetFirstDocTemplatePosition(CWinApp *this)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->GetFirstDocTemplatePosition(this: this->m_pDocManager);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00414E1C
// Name: public: class CDocTemplate __near * CWinApp::GetNextDocTemplate(struct __POSITION __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
CDocTemplate *__thiscall CWinApp::GetNextDocTemplate(CWinApp *this, __POSITION **rPosition)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->GetNextDocTemplate(this: this->m_pDocManager, a2: rPosition);
}

//------------------------------------------------------------------------------
// Address: 0x00415166
// Name: public: virtual int CWinApp::Unregister(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::Unregister(CWinApp *this)
{
  CDocTemplate *NextDocTemplate; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // eax
  char *m_pszProfileName; // [esp-10h] [ebp-150h]
  char *m_pszRegistryKey; // [esp-4h] [ebp-144h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v7; // [esp+10h] [ebp-130h] BYREF
  int cbData; // [esp+14h] [ebp-12Ch] BYREF
  __POSITION *rPosition; // [esp+18h] [ebp-128h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKeyName; // [esp+1Ch] [ebp-124h] BYREF
  HKEY__ *phkResult; // [esp+20h] [ebp-120h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str1; // [esp+24h] [ebp-11Ch] BYREF
  CHAR Name[276]; // [esp+28h] [ebp-118h] BYREF
  int v14; // [esp+13Ch] [ebp-4h]

  phkResult = nullptr;
  cbData = 0;
  rPosition = CWinApp::GetFirstDocTemplatePosition(this);
  while ( rPosition != nullptr )
  {
    NextDocTemplate = CWinApp::GetNextDocTemplate(this, &rPosition);
    if ( NextDocTemplate != nullptr )
      NextDocTemplate->OnCmdMsg(this: NextDocTemplate, a2: 0, a3: -4, a4: nullptr, a5: nullptr);
  }
  if ( this->m_pszRegistryKey != nullptr )
  {
    if ( this->m_pszProfileName == nullptr )
      AfxThrowInvalidArgException();
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str1,
      pszSrc: "Software\\");
    m_pszRegistryKey = (char *)this->m_pszRegistryKey;
    v14 = 0;
    ATL::CSimpleStringT<char,0>::Append(this: &str1, pszSrc: m_pszRegistryKey);
    v3 = ATL::operator+(result: &v7, &str1, psz2: "\\");
    m_pszProfileName = (char *)this->m_pszProfileName;
    LOBYTE(v14) = 1;
    ATL::operator+(result: &strKeyName, str1: v3, psz2: m_pszProfileName);
    LOBYTE(v14) = 3;
    ATL::CStringData::Release(this: (ATL::CStringData *)v7.m_pszData - 1);
    AfxDelRegTreeHelper(hParentKey: (HKEY__ *)0x80000001, &strKeyName, pTM: nullptr);
    if ( RegOpenKeyExA(hKey: HKEY_CURRENT_USER, lpSubKey: str1.m_pszData, ulOptions: 0, samDesired: 8u, &phkResult) == 0 )
    {
      if ( RegEnumKeyA(hKey: phkResult, dwIndex: 0, lpName: Name, cchName: 0x104u) == 259 )
        AfxDelRegTreeHelper(hParentKey: (HKEY__ *)0x80000001, strKeyName: &str1, pTM: nullptr);
      RegCloseKey(hKey: phkResult);
    }
    RegQueryValueA(hKey: HKEY_CURRENT_USER, lpSubKey: strKeyName.m_pszData, lpData: Name, lpcbData: &cbData);
    ATL::CStringData::Release(this: (ATL::CStringData *)strKeyName.m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)str1.m_pszData - 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004152DE
// Name: public: virtual void CWinApp::DoWaitCursor(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::DoWaitCursor(CWinApp *this, int nCode)
{
  HICON__ *v3; // eax
  HICON__ *m_hcurWaitCursorRestore; // [esp-4h] [ebp-Ch]

  if ( (unsigned int)nCode >= 2 && nCode != -1 || afxData.hcurWait == nullptr )
    AfxThrowInvalidArgException();
  AfxLockGlobals(nLockType: 2u);
  this->m_nWaitCursorCount += nCode;
  if ( this->m_nWaitCursorCount <= 0 )
  {
    m_hcurWaitCursorRestore = this->m_hcurWaitCursorRestore;
    this->m_nWaitCursorCount = 0;
    SetCursor(hCursor: m_hcurWaitCursorRestore);
  }
  else
  {
    v3 = SetCursor(hCursor: afxData.hcurWait);
    if ( nCode > 0 && this->m_nWaitCursorCount == 1 )
      this->m_hcurWaitCursorRestore = v3;
  }
  AfxUnlockGlobals(nLockType: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x0041535D
// Name: public: virtual int CWinApp::SaveAllModified(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::SaveAllModified(CWinApp *this)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->SaveAllModified(this: this->m_pDocManager);
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041536F
// Name: public: virtual void CWinApp::AddToRecentFileList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::AddToRecentFileList(CWinApp *this, const char *lpszPathName)
{
  if ( lpszPathName == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->Add(this: this->m_pRecentFileList, a2: lpszPathName, a3: this->m_pszAppID);
}

//------------------------------------------------------------------------------
// Address: 0x0041539F
// Name: public: virtual class CDocument __near * CWinApp::OpenDocumentFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *lpszFileName)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->OpenDocumentFile(this: this->m_pDocManager, a2: lpszFileName);
}

//------------------------------------------------------------------------------
// Address: 0x004153B8
// Name: public: virtual class CDocument __near * CWinApp::OpenDocumentFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *lpszFileName, int bAddToMRU)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->OpenDocumentFile(this: this->m_pDocManager, a2: lpszFileName, a3: bAddToMRU);
}

//------------------------------------------------------------------------------
// Address: 0x004153D1
// Name: public: void CWinApp::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::CloseAllDocuments(CWinApp *this, int bEndSession)
{
  if ( this->m_pDocManager != nullptr )
    this->m_pDocManager->CloseAllDocuments(this: this->m_pDocManager, a2: bEndSession);
}

//------------------------------------------------------------------------------
// Address: 0x004153E9
// Name: protected: void CWinApp::OnUpdateRecentFileMenu(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnUpdateRecentFileMenu(CWinApp *this, CCmdUI *pCmdUI)
{
  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->UpdateMenu(this: this->m_pRecentFileList, a2: pCmdUI);
  else
    ((void (__stdcall *)(_DWORD))pCmdUI->Enable)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041541F
// Name: public: virtual int CWinApp::OnDDECommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::OnDDECommand(CWinApp *this, char *lpszCommand)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->OnDDECommand(this: this->m_pDocManager, a2: lpszCommand);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00415459
// Name: protected: void CWinApp::OnAppExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnAppExit(CWinApp *this)
{
  SendMessageA(hWnd: this->m_pMainWnd->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041546C
// Name: public: void CWinApp::HideApplication(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::HideApplication(CWinApp *this)
{
  CWnd::ShowWindow(this: this->m_pMainWnd, nCmdShow: 0);
  ShowOwnedPopups(hWnd: this->m_pMainWnd->m_hWnd, fShow: false);
  CWnd::SetWindowPos(this: this->m_pMainWnd, pWndInsertAfter: &CWnd::wndBottom, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x13u);
}

//------------------------------------------------------------------------------
// Address: 0x004154A0
// Name: protected: int CWinApp::OnOpenRecentFile(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::OnOpenRecentFile(CWinApp *this, unsigned int nID)
{
  CRecentFileList *m_pRecentFileList; // edx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax

  m_pRecentFileList = this->m_pRecentFileList;
  if ( m_pRecentFileList == nullptr || nID < 0xE110 || nID >= m_pRecentFileList->m_nSize + 57616 )
    AfxThrowInvalidArgException();
  g_bRemoveFromMRU = 1;
  v4 = CRecentFileList::operator[](this: this->m_pRecentFileList, nIndex: nID - 57616);
  if ( this->OpenDocumentFile(this, a2: v4->m_pszData) == nullptr && g_bRemoveFromMRU != 0 )
    this->m_pRecentFileList->Remove(this: this->m_pRecentFileList, a2: nID - 57616);
  g_bRemoveFromMRU = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043BBBF
// Name: public: void CWinApp::SetCurrentHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SetCurrentHandles(CWinApp *this)
{
  AFX_MODULE_STATE *ModuleState; // ebx
  DWORD ModuleFileNameA; // eax
  char *v4; // eax
  const char *v5; // eax
  int v6; // eax
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  LPSTR lpszExt; // [esp+Ch] [ebp-410h]
  char szTitle[256]; // [esp+10h] [ebp-40Ch] BYREF
  char szAppID[256]; // [esp+110h] [ebp-30Ch] BYREF
  char szExeName[260]; // [esp+210h] [ebp-20Ch] BYREF
  char szBuff[260]; // [esp+314h] [ebp-108h] BYREF
  int v15; // [esp+418h] [ebp-4h] BYREF

  ModuleState = AfxGetModuleState();
  ModuleState->m_hCurrentInstanceHandle = this->m_hInstance;
  ModuleState->m_hCurrentResourceHandle = this->m_hInstance;
  ModuleFileNameA = GetModuleFileNameA(hModule: this->m_hInstance, lpFilename: szBuff, nSize: 0x104u);
  if ( ModuleFileNameA == 0 || ModuleFileNameA == 260 )
    AfxThrowUserException();
  lpszExt = PathFindExtensionA(pszPath: szBuff);
  if ( lpszExt == nullptr )
    AfxThrowUserException();
  *lpszExt = 0;
  if ( AfxGetFileName(lpszPathName: szBuff, lpszTitle: szExeName, nMax: 0x104u) != 0 )
    AfxThrowUserException();
  if ( this->m_pszExeName == nullptr )
  {
    v4 = _strdup(string: szExeName);
    this->m_pszExeName = v4;
    if ( v4 == nullptr )
      goto LABEL_10;
  }
  if ( this->m_pszAppName == nullptr )
  {
    v5 = AfxLoadString(nID: 0xE000u, lpszBuf: szTitle, nMaxBuf: 0x100u) != 0
       ? _strdup(string: szTitle)
       : _strdup(string: (char *)this->m_pszExeName);
    this->m_pszAppName = v5;
    if ( v5 == nullptr )
      goto LABEL_10;
  }
  if ( this->m_pszAppID == nullptr )
  {
    this->m_pszAppID = AfxLoadString(nID: 0xE006u, lpszBuf: szAppID, nMaxBuf: 0x100u) != 0
                     ? _strdup(string: szAppID)
                     : szGroupName;
    if ( this->m_pszAppID == nullptr )
      goto LABEL_10;
  }
  ModuleState->m_lpszCurrentAppName = this->m_pszAppName;
  if ( this->m_pszHelpFilePath == nullptr )
  {
    if ( this->m_eHelpType == afxHTMLHelp )
      v6 = strcpy_s(_Dst: lpszExt, _SizeInBytes: (char *)&v15 - lpszExt, _Src: ".CHM");
    else
      v6 = strcpy_s(_Dst: lpszExt, _SizeInBytes: (char *)&v15 - lpszExt, _Src: ".HLP");
    AfxCrtErrorCheck(error: v6);
    v7 = _strdup(string: szBuff);
    this->m_pszHelpFilePath = v7;
    if ( v7 != nullptr )
    {
      *lpszExt = 0;
      goto LABEL_27;
    }
LABEL_10:
    AfxThrowMemoryException();
  }
LABEL_27:
  if ( this->m_pszProfileName == nullptr )
  {
    v8 = strcat_s(_Dst: szExeName, _SizeInBytes: 0x104u, _Src: ".INI");
    AfxCrtErrorCheck(error: v8);
    v9 = _strdup(string: szExeName);
    this->m_pszProfileName = v9;
    if ( v9 == nullptr )
      goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8BED
// Name: protected: void CWinApp::UpdatePrinterSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::UpdatePrinterSelection(CWinApp *this, int bForceDefaults)
{
  unsigned __int16 *v3; // esi
  CPrintDialog *p_pd; // ecx
  tagPDA *v5; // eax
  tagPDA *m_pd; // eax
  const char *v7; // [esp-8h] [ebp-1ECh]
  const char *v8; // [esp-8h] [ebp-1ECh]
  const char *v9; // [esp-8h] [ebp-1ECh]
  char *m_pszData; // [esp-4h] [ebp-1E8h]
  char *v11; // [esp-4h] [ebp-1E8h]
  char *v12; // [esp-4h] [ebp-1E8h]
  CPrintDialog v13; // [esp+10h] [ebp-1D4h] BYREF
  CPrintDialog pd; // [esp+ECh] [ebp-F8h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v15; // [esp+1C8h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+1CCh] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v17; // [esp+1D0h] [ebp-14h] BYREF
  int v18; // [esp+1D4h] [ebp-10h]
  int v19; // [esp+1E0h] [ebp-4h]
  char bForceDefaults_3; // [esp+1EFh] [ebp+Bh]

  v18 = 0;
  if ( bForceDefaults != 0 || this->m_hDevNames == nullptr )
  {
    CPrintDialog::CPrintDialog(this: &v13, bPrintSetupOnly: 1, dwFlags: 0x14000Cu, pParentWnd: nullptr);
    v19 = 3;
    CPrintDialog::GetDefaults(this: &v13);
    if ( this->m_hDevMode != nullptr )
      AfxGlobalFree(hGlobal: this->m_hDevMode);
    if ( this->m_hDevNames != nullptr )
      AfxGlobalFree(hGlobal: this->m_hDevNames);
    m_pd = v13.m_pd;
    this->m_hDevMode = v13.m_pd->hDevMode;
    this->m_hDevNames = m_pd->hDevNames;
    v13.__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
    p_pd = &v13;
    goto LABEL_35;
  }
  v3 = (unsigned __int16 *)GlobalLock(hMem: this->m_hDevNames);
  if ( v3 == nullptr )
    AfxThrowInvalidArgException();
  if ( (v3[3] & 1) != 0 )
  {
    CPrintDialog::CPrintDialog(this: &pd, bPrintSetupOnly: 1, dwFlags: 0x14000Cu, pParentWnd: nullptr);
    v19 = 0;
    if ( CPrintDialog::GetDefaults(this: &pd) != 0 )
    {
      if ( pd.m_pd->hDevNames != nullptr )
      {
        m_pszData = CPrintDialog::GetDriverName(this: &pd, &result)->m_pszData;
        v7 = (char *)v3 + *v3;
        LOBYTE(v19) = 1;
        v18 = 1;
        if ( lstrcmpA(lpString1: v7, lpString2: m_pszData) != 0 )
          goto LABEL_15;
        v11 = CPrintDialog::GetDeviceName(this: &pd, result: &v17)->m_pszData;
        v8 = (char *)v3 + v3[1];
        v19 = 2;
        v18 = 3;
        if ( lstrcmpA(lpString1: v8, lpString2: v11) != 0
          || (v12 = CPrintDialog::GetPortName(this: &pd, result: &v15)->m_pszData,
              v9 = (char *)v3 + v3[2],
              v18 = 7,
              bForceDefaults_3 = 0,
              lstrcmpA(lpString1: v9, lpString2: v12) != 0) )
        {
LABEL_15:
          bForceDefaults_3 = 1;
        }
        if ( (v18 & 4) != 0 )
        {
          v18 &= ~4u;
          ATL::CStringData::Release(this: (ATL::CStringData *)v15.m_pszData - 1);
        }
        if ( (v18 & 2) != 0 )
        {
          v18 &= ~2u;
          ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
        }
        v19 = 0;
        if ( (v18 & 1) != 0 )
          ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
        if ( bForceDefaults_3 != 0 )
        {
          if ( this->m_hDevMode != nullptr )
            AfxGlobalFree(hGlobal: this->m_hDevMode);
          AfxGlobalFree(hGlobal: this->m_hDevNames);
          v5 = pd.m_pd;
          this->m_hDevMode = pd.m_pd->hDevMode;
          this->m_hDevNames = v5->hDevNames;
        }
        else
        {
          if ( pd.m_pd->hDevMode != nullptr )
            AfxGlobalFree(hGlobal: pd.m_pd->hDevMode);
          if ( pd.m_pd->hDevNames != nullptr )
            AfxGlobalFree(hGlobal: pd.m_pd->hDevNames);
        }
      }
      else
      {
        if ( this->m_hDevMode != nullptr )
          AfxGlobalFree(hGlobal: this->m_hDevMode);
        AfxGlobalFree(hGlobal: this->m_hDevNames);
        this->m_hDevMode = nullptr;
        this->m_hDevNames = nullptr;
      }
    }
    pd.__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
    p_pd = &pd;
LABEL_35:
    v19 = -1;
    CDialog::~CDialog(this: p_pd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8E29
// Name: public: int CWinApp::GetPrinterDeviceDefaults(struct tagPDA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetPrinterDeviceDefaults(CWinApp *this, tagPDA *pPrintDlg)
{
  CWinApp::UpdatePrinterSelection(this, bForceDefaults: this->m_hDevNames == nullptr);
  if ( this->m_hDevNames == nullptr )
    return 0;
  if ( pPrintDlg == nullptr )
    AfxThrowInvalidArgException();
  pPrintDlg->hDevNames = this->m_hDevNames;
  pPrintDlg->hDevMode = this->m_hDevMode;
  GlobalUnlock(hMem: this->m_hDevNames);
  GlobalUnlock(hMem: this->m_hDevMode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412E06
// Name: int AfxMessageBox(char const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxMessageBox(const char *lpszText, UINT nType, unsigned int nIDHelp)
{
  CWinApp *m_pCurrentWinApp; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    return m_pCurrentWinApp->DoMessageBox(this: m_pCurrentWinApp, a2: lpszText, a3: nType, a4: nIDHelp);
  else
    return CWinApp::ShowAppMessageBox(pApp: nullptr, lpszPrompt: lpszText, nType, nIDPrompt: nIDHelp);
}

//------------------------------------------------------------------------------
// Address: 0x00412E54
// Name: int AfxMessageBox(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxMessageBox(unsigned int nIDPrompt, UINT nType, unsigned int nIDHelp)
{
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  unsigned int v5; // eax
  char *m_pszData; // esi
  int v7; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > string; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &string, pStringMgr: StringManager);
  v10 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nIDPrompt);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &string,
      hInstance: StringResourceHandle,
      nID: nIDPrompt);
  v5 = nIDHelp;
  if ( nIDHelp == -1 )
    v5 = nIDPrompt;
  m_pszData = string.m_pszData;
  v7 = AfxMessageBox(lpszText: string.m_pszData, nType, nIDHelp: v5);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004130B6
// Name: void AfxPostQuitMessage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxPostQuitMessage(int nExitCode)
{
  CWinThread *Thread; // eax
  void (__stdcall *m_lpfnOleTermOrFreeLib)(int, int); // eax

  Thread = AfxGetThread();
  if ( Thread != nullptr )
  {
    m_lpfnOleTermOrFreeLib = Thread->m_lpfnOleTermOrFreeLib;
    if ( m_lpfnOleTermOrFreeLib != nullptr )
      m_lpfnOleTermOrFreeLib(a1: 1, a2: 1);
  }
  PostQuitMessage(nExitCode);
}

//------------------------------------------------------------------------------
// Address: 0x00413366
// Name: void ATL::Checked::tcscpy_s(char __near *,unsigned int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ATL::Checked::tcscpy_s(char *_Dst, unsigned int _SizeInChars, const char *_Src)
{
  int v3; // eax

  v3 = strcpy_s(_Dst, _SizeInBytes: _SizeInChars, _Src);
  AfxCrtErrorCheck(error: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00413384
// Name: _AfxLoadLangDLL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __cdecl AfxLoadLangDLL(const char *pszPath, LCID lcid)
{
  const char *pszFormat; // ecx
  const char *v3; // esi
  int v4; // eax
  int v5; // edi
  int *v6; // eax
  char szLangCode[4]; // [esp+4h] [ebp-120h] BYREF
  int ret; // [esp+8h] [ebp-11Ch]
  char szLangDLL[276]; // [esp+Ch] [ebp-118h] BYREF

  ret = (int)pszPath;
  v3 = pszFormat;
  if ( lcid == 2048 )
  {
    v4 = strcpy_s(_Dst: szLangCode, _SizeInBytes: 4u, _Src: "LOC");
    AfxCrtErrorCheck(error: v4);
  }
  else if ( GetLocaleInfoA(Locale: lcid, LCType: 3u, lpLCData: szLangCode, cchData: 4) == 0 )
  {
    return nullptr;
  }
  v5 = *_errno();
  *_errno() = 0;
  ret = _snprintf_s(string: szLangDLL, sizeInBytes: 0x112u, count: 0x111u, format: v3, ret, szLangCode);
  if ( *_errno() != 0 )
  {
    v6 = _errno();
    ATL::AtlCrtErrorCheck(nError: *v6);
  }
  else
  {
    *_errno() = v5;
  }
  if ( (unsigned int)ret <= 0x111 )
    return LoadLibraryExA(lpLibFileName: szLangDLL, hFile: nullptr, dwFlags: 0);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00413474
// Name: struct HINSTANCE__ __near * AfxLoadLangResourceDLL(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __stdcall AfxLoadLangResourceDLL(const char *pszFormat, char *pszPath)
{
  int v2; // esi
  HMODULE LibraryA; // eax
  BOOL (__stdcall *GetThreadPreferredUILanguages)(DWORD, PULONG, PZZWSTR, PULONG); // edi
  wchar_t *i; // edi
  int v6; // ebx
  LANGID UserDefaultUILanguage; // ax
  LCID v8; // eax
  LANGID SystemDefaultUILanguage; // ax
  LCID v10; // eax
  int v11; // esi
  int v12; // edi
  HMODULE result; // eax
  LCID v14; // [esp-4h] [ebp-154h]
  LCID v15; // [esp-4h] [ebp-154h]
  unsigned int nLanguages; // [esp+10h] [ebp-140h] BYREF
  char *v17; // [esp+14h] [ebp-13Ch]
  unsigned int cchLanguagesBuffer; // [esp+18h] [ebp-138h] BYREF
  unsigned int alcidSearch[25]; // [esp+1Ch] [ebp-134h]
  wchar_t wszLanguages[102]; // [esp+80h] [ebp-D0h] BYREF

  v17 = pszPath;
  v2 = 0;
  LibraryA = AfxCtxLoadLibraryA(lpLibFileName: "KERNEL32.DLL");
  if ( LibraryA != nullptr )
  {
    GetThreadPreferredUILanguages = (BOOL (__stdcall *)(DWORD, PULONG, PZZWSTR, PULONG))GetProcAddress(
                                                                                          hModule: LibraryA,
                                                                                          lpProcName: "GetThreadPreferredUILanguages");
    if ( GetThreadPreferredUILanguages != nullptr )
    {
      memset(wszLanguages, 0, 202);
      nLanguages = 0;
      cchLanguagesBuffer = 101;
      if ( GetThreadPreferredUILanguages(
             dwFlags: 52,
             pulNumLanguages: &nLanguages,
             pwszLanguagesBuffer: wszLanguages,
             pcchLanguagesBuffer: &cchLanguagesBuffer) )
      {
        for ( i = wszLanguages; *i != 0; i += wcslen(wcs: i) + 1 )
        {
          if ( v2 >= 20 )
            break;
          v6 = wcstoul(nptr: i, endptr: nullptr, ibase: 0x10u);
          if ( v6 != 0 && *_errno() != 34 )
            alcidSearch[v2++] = v6;
        }
      }
    }
  }
  UserDefaultUILanguage = GetUserDefaultUILanguage();
  cchLanguagesBuffer = UserDefaultUILanguage & 0x3FF;
  v8 = ConvertDefaultLocale(Locale: UserDefaultUILanguage);
  v14 = cchLanguagesBuffer;
  alcidSearch[v2] = v8;
  alcidSearch[v2 + 1] = ConvertDefaultLocale(Locale: v14);
  SystemDefaultUILanguage = GetSystemDefaultUILanguage();
  cchLanguagesBuffer = SystemDefaultUILanguage & 0x3FF;
  v10 = ConvertDefaultLocale(Locale: cchLanguagesBuffer | SystemDefaultUILanguage & 0xFC00);
  v15 = cchLanguagesBuffer;
  alcidSearch[v2 + 2] = v10;
  alcidSearch[v2 + 3] = ConvertDefaultLocale(Locale: v15);
  v11 = v2 + 4;
  if ( g_fLoadingResourcesForMFCDLL == 0 )
    alcidSearch[v11++] = 2048;
  v12 = 0;
  if ( v11 <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = AfxLoadLangDLL(pszPath: v17, lcid: alcidSearch[v12]);
    if ( result != nullptr )
      break;
    if ( ++v12 >= v11 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041378A
// Name: unsigned long AfxApplicationRecoveryWrapper(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxApplicationRecoveryWrapper(void *lpvParam)
{
  int v1; // esi
  CWinApp *m_pCurrentWinApp; // eax

  v1 = 0;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    return m_pCurrentWinApp->ApplicationRecoveryCallback(this: m_pCurrentWinApp, a2: lpvParam);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00413868
// Name: wchar_t __near * A2WBSTR(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl A2WBSTR(const char *lp, int nLen)
{
  UINT v2; // eax
  int v3; // edi
  wchar_t *v4; // eax
  wchar_t *str; // [esp+Ch] [ebp-4h]

  if ( lp == nullptr || nLen == 0 )
    return nullptr;
  v2 = MultiByteToWideChar(
         CodePage: 3u,
         dwFlags: 0,
         lpMultiByteStr: lp,
         cbMultiByte: nLen,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v3 = v2;
  if ( nLen == -1 )
    --v2;
  v4 = SysAllocStringLen(strIn: nullptr, ui: v2);
  str = v4;
  if ( v4 != nullptr
    && MultiByteToWideChar(
         CodePage: 3u,
         dwFlags: 0,
         lpMultiByteStr: lp,
         cbMultiByte: nLen,
         lpWideCharStr: v4,
         cchWideChar: v3) != v3 )
  {
    SysFreeString(bstrString: str);
    return nullptr;
  }
  return str;
}

//------------------------------------------------------------------------------
// Address: 0x004138D0
// Name: public: ATL::CComBSTR::CComBSTR(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CComBSTR *__thiscall ATL::CComBSTR::CComBSTR(ATL::CComBSTR *this, const char *pSrc)
{
  wchar_t *v3; // eax

  if ( pSrc != nullptr )
  {
    v3 = A2WBSTR(lp: pSrc, nLen: -1);
    this->m_str = v3;
    if ( v3 == nullptr )
      ATL::AtlThrowImpl(hr: -2147024882);
  }
  else
  {
    this->m_str = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413FA5
// Name: class CWinThread __near * AfxGetThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWinThread *__stdcall AfxGetThread()
{
  return AfxGetModuleThreadState()->m_pCurrentWinThread;
}

//------------------------------------------------------------------------------
// Address: 0x00413FAE
// Name: struct tagMSG __near * AfxGetCurrentMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tagMSG *__stdcall AfxGetCurrentMessage()
{
  return &AfxGetThreadState()->m_msgCur;
}

//------------------------------------------------------------------------------
// Address: 0x00413FB7
// Name: long AfxInternalProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxInternalProcessWndProcException(CException *__formal, const tagMSG *pMsg)
{
  unsigned int message; // eax

  message = pMsg->message;
  if ( message == 1 )
    return -1;
  if ( message == 15 )
    ValidateRect(hWnd: pMsg->hwnd, lpRect: nullptr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413FE1
// Name: long AfxProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxProcessWndProcException(CException *e, const tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->ProcessWndProcException(this: m_pCurrentWinThread, a2: e, a3: pMsg);
  else
    return AfxInternalProcessWndProcException(__formal: e, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x00413FFE
// Name: public: void CWinThread::CommonConstruct(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWinThread::CommonConstruct(CWinThread *this)
{
  _AFX_THREAD_STATE *ThreadState; // eax

  this->m_pMainWnd = nullptr;
  this->m_pActiveWnd = nullptr;
  this->m_hThread = nullptr;
  this->m_nThreadID = 0;
  ThreadState = AfxGetThreadState();
  ThreadState->m_msgCur.message = 0;
  ThreadState->m_nMsgLast = 0;
  GetCursorPos(lpPoint: &ThreadState->m_ptCursorLast);
  this->m_pMessageFilter = nullptr;
  this->m_lpfnOleTermOrFreeLib = nullptr;
  this->m_bAutoDelete = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414037
// Name: public: virtual CWinThread::~CWinThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWinThread::~CWinThread(CWinThread *this)
{
  void *m_hThread; // eax
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // eax

  this->__vftable = (CWinThread_vtbl *)&CWinThread::`vftable';
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr )
    CloseHandle(hObject: m_hThread);
  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pCurrentWinThread == this )
    ModuleThreadState->m_pCurrentWinThread = nullptr;
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041407F
// Name: public: virtual void CWinThread::Delete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWinThread::Delete(CWinThread *this)
{
  if ( this->m_bAutoDelete != 0 )
    ((void (__thiscall *)(CWinThread *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041408D
// Name: public: virtual int CWinThread::Run(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::Run(CWinThread *this)
{
  int v2; // eax
  bool v3; // zf
  CWinThread_vtbl *v4; // eax
  _AFX_THREAD_STATE *pState; // [esp+Ch] [ebp-Ch]
  int lIdleCount; // [esp+10h] [ebp-8h]
  int bIdle; // [esp+14h] [ebp-4h]

  pState = AfxGetThreadState();
  bIdle = 1;
  lIdleCount = 0;
LABEL_2:
  while ( bIdle != 0 )
  {
    if ( PeekMessageA(lpMsg: &pState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
      break;
    v2 = this->OnIdle(this, a2: lIdleCount++);
    if ( v2 == 0 )
      bIdle = 0;
  }
  while ( 1 )
  {
    v3 = this->PumpMessage(this) == 0;
    v4 = this->__vftable;
    if ( v3 )
      return v4->ExitInstance(this);
    if ( v4->IsIdleMessage(this, a2: &pState->m_msgCur) != 0 )
    {
      bIdle = 1;
      lIdleCount = 0;
    }
    if ( !PeekMessageA(lpMsg: &pState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
      goto LABEL_2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414121
// Name: public: virtual int CWinThread::ExitInstance(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CWinThread::ExitInstance(CWinThread *this)
{
  return AfxGetThreadState()->m_msgCur.wParam;
}

//------------------------------------------------------------------------------
// Address: 0x0041412A
// Name: protected: int CWinThread::DispatchThreadMessageEx(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::DispatchThreadMessageEx(CWinThread *this, tagMSG *pMsg)
{
  int v2; // esi
  unsigned int message; // eax
  const AFX_MSGMAP_ENTRY *MessageEntry; // eax
  tagMSG *v5; // ecx
  const AFX_MSGMAP_ENTRY *i; // eax

  v2 = ((int (__fastcall *)(CWinThread *))this->GetMessageMap)(a1: this);
  if ( *(_DWORD *)v2 == 0 )
    return 0;
  while ( 1 )
  {
    message = pMsg->message;
    if ( message >= 0xC000 )
    {
      for ( i = *(const AFX_MSGMAP_ENTRY **)(v2 + 4); ; i = MessageEntry + 1 )
      {
        MessageEntry = AfxFindMessageEntry(lpEntry: i, nMsg: 0xC000u, nCode: 0, nID: 0);
        if ( MessageEntry == nullptr )
          break;
        v5 = pMsg;
        if ( *(_DWORD *)MessageEntry->nSig == pMsg->message )
          goto LDispatch_0;
      }
      goto LABEL_10;
    }
    MessageEntry = AfxFindMessageEntry(lpEntry: *(const AFX_MSGMAP_ENTRY **)(v2 + 4), nMsg: message, nCode: 0, nID: 0);
    if ( MessageEntry != nullptr )
      break;
LABEL_10:
    v2 = (*(int (**)(void))v2)();
    if ( *(_DWORD *)v2 == 0 )
      return 0;
  }
  v5 = pMsg;
LDispatch_0:
  ((void (__thiscall *)(CWinThread *, unsigned int, int))MessageEntry->pfn)(a1: this, a2: v5->wParam, a3: v5->lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004141A8
// Name: public: virtual long CWinThread::ProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::ProcessWndProcException(CWinThread *this, CException *e, const tagMSG *pMsg)
{
  return AfxInternalProcessWndProcException(__formal: e, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x004141B3
// Name: int IsEnterKey(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl IsEnterKey(tagMSG *lpMsg)
{
  return lpMsg->message == 256 && lpMsg->wParam == 13;
}

//------------------------------------------------------------------------------
// Address: 0x004141D3
// Name: public: virtual struct CRuntimeClass __near * CWinThread::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWinThread::GetRuntimeClass(CWinThread *this)
{
  return &CWinThread::classCWinThread;
}

//------------------------------------------------------------------------------
// Address: 0x004141D9
// Name: public: int CPoint::operator==(struct tagPOINT)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPoint::operator==(CSize *this, tagSIZE size)
{
  return *this == size;
}

//------------------------------------------------------------------------------
// Address: 0x004141F8
// Name: int AfxInternalPreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxInternalPreTranslateMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // eax
  HWND__ *MainWnd; // eax
  CWnd *v4; // esi
  CWnd *v5; // eax

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr
    && pMsg->hwnd == nullptr
    && CWinThread::DispatchThreadMessageEx(this: m_pCurrentWinThread, pMsg) != 0 )
  {
    return 1;
  }
  MainWnd = (HWND__ *)AfxGetMainWnd();
  v4 = (CWnd *)MainWnd;
  if ( MainWnd != nullptr )
    MainWnd = *((HWND__ **)MainWnd + 8);
  if ( CWnd::WalkPreTranslateTree(hWndStop: MainWnd, pMsg) != 0 )
    return 1;
  if ( v4 == nullptr )
    return 0;
  v5 = CWnd::FromHandle(hWnd: pMsg->hwnd);
  if ( CWnd::GetTopLevelParent(this: v5) == v4 )
    return 0;
  return v4->PreTranslateMessage(this: v4, a2: pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x0041426B
// Name: int AfxPreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxPreTranslateMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->PreTranslateMessage(this: m_pCurrentWinThread, a2: pMsg);
  else
    return AfxInternalPreTranslateMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x0041428C
// Name: int AfxInternalIsIdleMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl AfxInternalIsIdleMessage(tagMSG *pMsg)
{
  unsigned int message; // eax
  _AFX_THREAD_STATE *ThreadState; // ebx
  int y; // ecx

  message = pMsg->message;
  if ( message != 512 && message != 160 )
    return message != 15 && message != 280;
  ThreadState = AfxGetThreadState();
  if ( CPoint::operator==(this: (CSize *)&ThreadState->m_ptCursorLast, size: (tagSIZE)pMsg->pt)
    && pMsg->message == ThreadState->m_nMsgLast )
  {
    return false;
  }
  else
  {
    y = pMsg->pt.y;
    ThreadState->m_ptCursorLast.x = pMsg->pt.x;
    ThreadState->m_ptCursorLast.y = y;
    ThreadState->m_nMsgLast = pMsg->message;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004142FC
// Name: int AfxIsIdleMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxIsIdleMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->IsIdleMessage(this: m_pCurrentWinThread, a2: pMsg);
  else
    return AfxInternalIsIdleMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x0041433E
// Name: public: CWinThread::CWinThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWinThread *__thiscall CWinThread::CWinThread(CWinThread *this)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (CWinThread_vtbl *)&CWinThread::`vftable';
  this->m_pThreadParams = nullptr;
  this->m_pfnThreadProc = nullptr;
  CWinThread::CommonConstruct(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00414374
// Name: public: virtual int CWinThread::IsIdleMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CWinThread::IsIdleMessage(CWinThread *this, tagMSG *pMsg)
{
  return AfxInternalIsIdleMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x00414386
// Name: public: virtual int CWinThread::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::PreTranslateMessage(CWinThread *this, tagMSG *pMsg)
{
  return AfxInternalPreTranslateMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x00414398
// Name: public: virtual class CWnd __near * CWinThread::GetMainWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CWinThread::GetMainWnd(CWinThread *this)
{
  CWnd *result; // eax
  HWND ActiveWindow; // eax

  result = this->m_pActiveWnd;
  if ( result == nullptr )
  {
    result = this->m_pMainWnd;
    if ( result == nullptr )
    {
      ActiveWindow = GetActiveWindow();
      return CWnd::FromHandle(hWnd: ActiveWindow);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004143B3
// Name: int AfxInternalPumpMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxInternalPumpMessage()
{
  _AFX_THREAD_STATE *ThreadState; // esi
  BOOL result; // eax

  ThreadState = AfxGetThreadState();
  result = GetMessageA(lpMsg: &ThreadState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0);
  if ( result )
  {
    if ( ThreadState->m_msgCur.message != 874 && AfxPreTranslateMessage(pMsg: &ThreadState->m_msgCur) == 0 )
    {
      TranslateMessage(lpMsg: &ThreadState->m_msgCur);
      DispatchMessageA(lpMsg: &ThreadState->m_msgCur);
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004143F9
// Name: int AfxPumpMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxPumpMessage()
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->PumpMessage(this: m_pCurrentWinThread);
  else
    return AfxInternalPumpMessage();
}

//------------------------------------------------------------------------------
// Address: 0x0041440F
// Name: long _AfxMsgFilterHook(int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxMsgFilterHook(int code, WPARAM wParam, LPARAM lParam)
{
  CWinThread *m_pCurrentWinThread; // ecx
  CNoTrackObject *Data; // eax

  if ( AfxGetModuleState()->m_bDLL == 0 && code >= 0 )
  {
    m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
    if ( m_pCurrentWinThread != nullptr )
      return m_pCurrentWinThread->ProcessMessageFilter(this: m_pCurrentWinThread, a2: code, a3: (tagMSG *)lParam);
  }
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: (CNoTrackObject *(__stdcall *)())CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  return CallNextHookEx(hhk: (HHOOK)Data[11].__vftable, nCode: code, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00414473
// Name: public: virtual int CWinThread::ProcessMessageFilter(int,struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::ProcessMessageFilter(CWinThread *this, int code, tagMSG *lpMsg)
{
  CWnd *v4; // eax
  CFrameWnd *TopLevelFrame; // eax
  CFrameWnd *v6; // edi
  CWnd *MainWnd; // edi
  unsigned int message; // eax
  CNoTrackObject *Data; // eax
  CNoTrackObject *v10; // ebx
  tagMSG msg; // [esp+8h] [ebp-20h] BYREF
  CWinThread *v12; // [esp+24h] [ebp-4h]

  v12 = this;
  if ( lpMsg == nullptr )
    return 0;
  if ( code != 0 )
  {
    if ( code != 2 )
      return 0;
    v4 = CWnd::FromHandle(hWnd: lpMsg->hwnd);
    if ( v4 != nullptr )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this: v4);
      v6 = TopLevelFrame;
      if ( TopLevelFrame != nullptr && CFrameWnd::IsTracking(this: TopLevelFrame) && v6->m_bHelpMode != 0 )
      {
        MainWnd = AfxGetMainWnd();
        if ( v12->m_pMainWnd != nullptr && (IsEnterKey(lpMsg) || lpMsg->message == 514) )
        {
          SendMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0);
          return 1;
        }
      }
    }
  }
  AfxGetMainWnd();
  if ( code == 0 && v12->m_pActiveWnd != nullptr )
  {
    message = lpMsg->message;
    if ( message >= 0x100 && message <= 0x109 )
    {
      Data = CThreadLocalObject::GetData(
               this: &_afxThreadState,
               pfnCreateObject: (CNoTrackObject *(__stdcall *)())CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
      v10 = Data;
      if ( Data == nullptr )
        AfxThrowInvalidArgException();
      if ( Data[56].__vftable == nullptr )
      {
        Data[56].__vftable = (CNoTrackObject_vtbl *)1;
        msg = *lpMsg;
        if ( CWnd::IsWindowEnabled(this: v12->m_pActiveWnd) != 0 && v12->PreTranslateMessage(this: v12, a2: &msg) != 0 )
        {
          v10[56].__vftable = nullptr;
          return 1;
        }
        v10[56].__vftable = nullptr;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004145A5
// Name: public: virtual int CWinThread::PumpMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __thiscall CWinThread::PumpMessage(CWinThread *this)
{
  return AfxInternalPumpMessage();
}

//------------------------------------------------------------------------------
// Address: 0x004145AA
// Name: void AfxInitThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxInitThread()
{
  _AFX_THREAD_STATE *ThreadState; // esi
  DWORD CurrentThreadId; // eax

  if ( AfxGetModuleState()->m_bDLL == 0 )
  {
    ThreadState = AfxGetThreadState();
    CurrentThreadId = GetCurrentThreadId();
    ThreadState->m_hHookOldMsgFilter = SetWindowsHookExA(
                                         idHook: -1,
                                         lpfn: _AfxMsgFilterHook,
                                         hmod: nullptr,
                                         dwThreadId: CurrentThreadId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004146ED
// Name: public: long ATL::CAtlTransactionManager::RegOpenKeyExA(struct HKEY__ __near *,char const __near *,unsigned long,unsigned long,struct HKEY__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegOpenKeyExA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey,
        DWORD ulOptions,
        REGSAM samDesired,
        HKEY__ **phkResult)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegOpenKeyTransactedA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegOpenKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "RegOpenKeyTransactedA");
      if ( RegOpenKeyTransactedA != nullptr )
        return RegOpenKeyTransactedA(
                 hKey,
                 lpSubKey,
                 ulOptions,
                 samDesired,
                 phkResult,
                 hTransaction: this->m_hTransaction,
                 pExtendedParemeter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414746
// Name: public: long ATL::CAtlTransactionManager::RegCreateKeyExA(struct HKEY__ __near *,char const __near *,unsigned long,char __near *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES __near * const,struct HKEY__ __near * __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegCreateKeyExA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey,
        DWORD dwReserved,
        char *lpClass,
        DWORD dwOptions,
        REGSAM samDesired,
        _SECURITY_ATTRIBUTES *const lpSecurityAttributes,
        HKEY__ **phkResult,
        unsigned int *lpdwDisposition)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegCreateKeyTransactedA)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegCreateKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "RegCreateKeyTransactedA");
      if ( RegCreateKeyTransactedA != nullptr )
        return RegCreateKeyTransactedA(
                 hKey,
                 lpSubKey,
                 Reserved: dwReserved,
                 lpClass,
                 dwOptions,
                 samDesired,
                 lpSecurityAttributes,
                 phkResult,
                 lpdwDisposition,
                 hTransaction: this->m_hTransaction,
                 pExtendedParemeter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegCreateKeyExA(
             hKey,
             lpSubKey,
             Reserved: dwReserved,
             lpClass,
             dwOptions,
             samDesired,
             lpSecurityAttributes,
             phkResult,
             lpdwDisposition);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004147AB
// Name: public: long ATL::CRegKey::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::Close(ATL::CRegKey *this)
{
  HKEY__ *m_hKey; // ecx
  LSTATUS result; // eax

  m_hKey = this->m_hKey;
  result = 0;
  if ( m_hKey != nullptr )
  {
    result = RegCloseKey(hKey: m_hKey);
    this->m_hKey = nullptr;
  }
  this->m_samWOW64 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414B15
// Name: public: ATL::CRegKey::~CRegKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall ATL::CRegKey::~CRegKey(ATL::CRegKey *this)
{
  ATL::CRegKey::Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x00414E35
// Name: public: long ATL::CAtlTransactionManager::RegDeleteKeyA(struct HKEY__ __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegDeleteKeyA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegDeleteKeyTransactedA)(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegDeleteKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID))GetProcAddress(
                                                                                                     hModule: ModuleHandleA,
                                                                                                     lpProcName: "RegDeleteKeyTransactedA");
      if ( RegDeleteKeyTransactedA != nullptr )
        return RegDeleteKeyTransactedA(
                 hKey,
                 lpSubKey,
                 samDesired: 0,
                 Reserved: 0,
                 hTransaction: this->m_hTransaction,
                 pExtendedParameter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegDeleteKeyA(hKey, lpSubKey);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041551C
// Name: $LN21_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall _LN21_4@<eax>(const DLGTEMPLATE *pTemplate@<eax>)
{
  if ( pTemplate == nullptr )
    AfxThrowInvalidArgException();
  return HIWORD(pTemplate->style) == 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00415536
// Name: struct DLGITEMTEMPLATE __near * _AfxFindFirstDlgItem(struct DLGTEMPLATE const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DLGITEMTEMPLATE *__stdcall _AfxFindFirstDlgItem(const DLGTEMPLATE *pTemplate)
{
  unsigned int style; // ebx
  BOOL v2; // eax
  const DLGTEMPLATE *v3; // ecx
  __int16 v4; // di
  __int16 v5; // dx
  __int16 v6; // dx
  __int16 v7; // ax

  style = pTemplate->style;
  v2 = _LN21_4(pTemplate);
  if ( v2 )
  {
    style = *(_DWORD *)&pTemplate->y;
    v3 = (const DLGTEMPLATE *)((char *)pTemplate + 26);
  }
  else
  {
    v3 = pTemplate + 1;
  }
  if ( LOWORD(v3->style) == 0xFFFF )
  {
    v3 = (const DLGTEMPLATE *)((char *)v3 + 4);
  }
  else
  {
    do
    {
      v4 = v3->style;
      v3 = (const DLGTEMPLATE *)((char *)v3 + 2);
    }
    while ( v4 != 0 );
  }
  if ( LOWORD(v3->style) == 0xFFFF )
  {
    v3 = (const DLGTEMPLATE *)((char *)v3 + 4);
  }
  else
  {
    do
    {
      v5 = v3->style;
      v3 = (const DLGTEMPLATE *)((char *)v3 + 2);
    }
    while ( v5 != 0 );
  }
  do
  {
    v6 = v3->style;
    v3 = (const DLGTEMPLATE *)((char *)v3 + 2);
  }
  while ( v6 != 0 );
  if ( (style & 0x40) != 0 )
  {
    v3 = (const DLGTEMPLATE *)((char *)v3 + 4 * v2 + 2);
    do
    {
      v7 = v3->style;
      v3 = (const DLGTEMPLATE *)((char *)v3 + 2);
    }
    while ( v7 != 0 );
  }
  return (DLGITEMTEMPLATE *)(((unsigned int)&v3->style + 3) & 0xFFFFFFFC);
}

//------------------------------------------------------------------------------
// Address: 0x004155BD
// Name: struct DLGITEMTEMPLATE __near * _AfxFindNextDlgItem(struct DLGITEMTEMPLATE __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DLGITEMTEMPLATE *__stdcall _AfxFindNextDlgItem(DLGITEMTEMPLATE *pItem, int bDialogEx)
{
  DLGITEMTEMPLATE *v2; // eax
  __int16 style; // dx
  __int16 v4; // cx
  unsigned __int16 v5; // cx

  if ( bDialogEx != 0 )
    v2 = (DLGITEMTEMPLATE *)((char *)pItem + 24);
  else
    v2 = pItem + 1;
  if ( LOWORD(v2->style) == 0xFFFF )
  {
    v2 = (DLGITEMTEMPLATE *)((char *)v2 + 4);
  }
  else
  {
    do
    {
      style = v2->style;
      v2 = (DLGITEMTEMPLATE *)((char *)v2 + 2);
    }
    while ( style != 0 );
  }
  if ( LOWORD(v2->style) == 0xFFFF )
  {
    v2 = (DLGITEMTEMPLATE *)((char *)v2 + 4);
  }
  else
  {
    do
    {
      v4 = v2->style;
      v2 = (DLGITEMTEMPLATE *)((char *)v2 + 2);
    }
    while ( v4 != 0 );
  }
  v5 = v2->style;
  if ( LOWORD(v2->style) != 0 && bDialogEx == 0 )
    v5 -= 2;
  return (DLGITEMTEMPLATE *)(((unsigned int)&v2->dwExtendedStyle + v5 + 1) & 0xFFFFFFFC);
}

//------------------------------------------------------------------------------
// Address: 0x00415624
// Name: public: virtual int COccManager::OnEvent(class CCmdTarget __near *,unsigned int,struct AFX_EVENT __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall COccManager::OnEvent(
        COccManager *this,
        CCmdTarget *pCmdTarget,
        unsigned int idCtrl,
        AFX_EVENT *pEvent,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  return CCmdTarget::OnEvent(this: pCmdTarget, idCtrl, pEvent, pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041563E
// Name: public: virtual struct DLGTEMPLATE const __near * COccManager::PreCreateDialog(struct _AFX_OCC_DIALOG_INFO __near *,struct DLGTEMPLATE const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const DLGTEMPLATE *__thiscall COccManager::PreCreateDialog(
        COccManager *this,
        _AFX_OCC_DIALOG_INFO *pDlgInfo,
        const DLGTEMPLATE *pOrigTemplate)
{
  bool v4; // zf
  unsigned __int16 *p_cy; // eax
  const DLGTEMPLATE *result; // eax
  DLGITEMTEMPLATE *FirstDlgItem; // esi
  unsigned __int16 *p_cdit; // eax
  signed int v10; // ebx
  _AFX_OCC_DIALOG_INFO::ItemInfo *v11; // eax
  int v12; // eax
  DLGITEMTEMPLATE *v13; // ecx
  unsigned int style; // esi
  BOOL v15; // ecx
  DLGTEMPLATE *pNewTemplate; // [esp+Ch] [ebp-Ch]
  DLGITEMTEMPLATE *pNextItem; // [esp+10h] [ebp-8h]
  BOOL bDialogEx; // [esp+14h] [ebp-4h]
  int iItem; // [esp+20h] [ebp+8h]

  v4 = !_LN21_4(pTemplate: pOrigTemplate);
  p_cy = (unsigned __int16 *)&pOrigTemplate->cy;
  if ( v4 )
    p_cy = &pOrigTemplate->cdit;
  result = (const DLGTEMPLATE *)calloc(num: 4u, size: *p_cy + 1);
  pDlgInfo->m_ppOleDlgItems = (DLGITEMTEMPLATE **)result;
  if ( result != nullptr )
  {
    pNewTemplate = this->SplitDialogTemplate(this, a2: pOrigTemplate, a3: result);
    pDlgInfo->m_pNewTemplate = pNewTemplate;
    FirstDlgItem = _AfxFindFirstDlgItem(pTemplate: pOrigTemplate);
    bDialogEx = _LN21_4(pTemplate: pOrigTemplate);
    v4 = !_LN21_4(pTemplate: pOrigTemplate);
    p_cdit = (unsigned __int16 *)&pOrigTemplate->cy;
    if ( v4 )
      p_cdit = &pOrigTemplate->cdit;
    v10 = *p_cdit;
    v11 = (_AFX_OCC_DIALOG_INFO::ItemInfo *)operator new(nSize: 8 * v10);
    pDlgInfo->m_pItemInfo = v11;
    memset(dst: (int)v11, value: nullptr, count: 8 * v10);
    iItem = 0;
    for ( pDlgInfo->m_cItems = v10; iItem < v10; pDlgInfo->m_pItemInfo[v12].bAutoRadioButton = v15 )
    {
      pNextItem = _AfxFindNextDlgItem(pItem: FirstDlgItem, bDialogEx);
      v12 = iItem;
      if ( bDialogEx )
      {
        pDlgInfo->m_pItemInfo[v12].nId = *(unsigned int *)((char *)&FirstDlgItem[1].style + 2);
        v13 = (DLGITEMTEMPLATE *)((char *)FirstDlgItem + 24);
        style = *(_DWORD *)&FirstDlgItem->x;
      }
      else
      {
        pDlgInfo->m_pItemInfo[v12].nId = FirstDlgItem->id;
        v13 = FirstDlgItem + 1;
        style = FirstDlgItem->style;
      }
      v15 = LOWORD(v13->style) == 0xFFFF && HIWORD(v13->style) == 128 && (style & 0xF) == 9;
      ++iItem;
      FirstDlgItem = pNextItem;
    }
    result = pNewTemplate;
    if ( pNewTemplate == nullptr )
      return pOrigTemplate;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415765
// Name: public: virtual void COccManager::PostCreateDialog(struct _AFX_OCC_DIALOG_INFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COccManager::PostCreateDialog(COccManager *this, _AFX_OCC_DIALOG_INFO *pDlgInfo)
{
  if ( pDlgInfo->m_pNewTemplate != nullptr )
    GlobalFree(hMem: (HGLOBAL)pDlgInfo->m_pNewTemplate);
  if ( pDlgInfo->m_ppOleDlgItems != nullptr )
    free(pBlock: pDlgInfo->m_ppOleDlgItems);
  operator delete(p: pDlgInfo->m_pItemInfo);
}

//------------------------------------------------------------------------------
// Address: 0x00415797
// Name: public: virtual struct DLGTEMPLATE __near * COccManager::SplitDialogTemplate(struct DLGTEMPLATE const __near *,struct DLGITEMTEMPLATE __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DLGTEMPLATE *__thiscall COccManager::SplitDialogTemplate(
        COccManager *this,
        const DLGTEMPLATE *pTemplate,
        DLGITEMTEMPLATE **ppOleDlgItems)
{
  unsigned int v3; // edi
  bool v4; // zf
  unsigned __int16 *p_cy; // eax
  int v6; // eax
  DLGITEMTEMPLATE *v7; // esi
  int i; // ebx
  DLGITEMTEMPLATE *NextDlgItem; // eax
  DLGITEMTEMPLATE *v10; // ecx
  const DLGTEMPLATE *v12; // eax
  const DLGTEMPLATE *v13; // esi
  const DLGTEMPLATE *v14; // ebx
  _WORD *p_cdit; // eax
  DLGITEMTEMPLATE *v16; // edi
  int v17; // esi
  DLGITEMTEMPLATE *v18; // eax
  _WORD *v19; // eax
  int nItems; // [esp+Ch] [ebp-14h]
  DLGITEMTEMPLATE *pFirstItem; // [esp+10h] [ebp-10h]
  DLGITEMTEMPLATE *pFirstItema; // [esp+10h] [ebp-10h]
  int bHasOleControls; // [esp+14h] [ebp-Ch]
  BOOL bDialogEx; // [esp+18h] [ebp-8h]
  SIZE_T iItem; // [esp+1Ch] [ebp-4h]
  int iItema; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *pNew; // [esp+28h] [ebp+8h]

  pFirstItem = _AfxFindFirstDlgItem(pTemplate);
  v3 = (char *)pFirstItem - (char *)pTemplate;
  iItem = (char *)pFirstItem - (char *)pTemplate;
  bDialogEx = _LN21_4(pTemplate);
  v4 = !_LN21_4(pTemplate);
  p_cy = (unsigned __int16 *)&pTemplate->cy;
  if ( v4 )
    p_cy = &pTemplate->cdit;
  v6 = *p_cy;
  bHasOleControls = 0;
  v7 = pFirstItem;
  nItems = v6;
  if ( v6 == 0 )
    goto LABEL_12;
  for ( i = v6; i != 0; --i )
  {
    NextDlgItem = _AfxFindNextDlgItem(pItem: v7, bDialogEx);
    v10 = (DLGITEMTEMPLATE *)((char *)v7 + 24);
    if ( !bDialogEx )
      v10 = v7 + 1;
    if ( LOWORD(v10->style) == 123 )
      bHasOleControls = 1;
    else
      iItem += (char *)NextDlgItem - (char *)v7;
    v7 = NextDlgItem;
  }
  if ( bHasOleControls != 0 )
  {
    v12 = (const DLGTEMPLATE *)GlobalAlloc(uFlags: 0, dwBytes: iItem);
    v13 = v12;
    if ( v12 == nullptr )
      AfxThrowMemoryException();
    v14 = v12;
    ATL::Checked::memcpy_s(_S1: (void *)v12, _S1max: iItem, _S2: pTemplate, _N: v3);
    pNew = (unsigned __int8 *)v13 + v3;
    v4 = !_LN21_4(pTemplate: v14);
    p_cdit = &v14->cy;
    if ( v4 )
      p_cdit = &v14->cdit;
    v16 = pFirstItem;
    v17 = 0;
    *p_cdit = 0;
    iItema = 0;
    do
    {
      pFirstItema = _AfxFindNextDlgItem(pItem: v16, bDialogEx);
      v18 = (DLGITEMTEMPLATE *)((char *)v16 + 24);
      if ( !bDialogEx )
        v18 = v16 + 1;
      if ( LOWORD(v18->style) == 123 )
      {
        ppOleDlgItems[v17] = v16;
      }
      else
      {
        ATL::Checked::memcpy_s(
          _S1: pNew,
          _S1max: (char *)pFirstItema - (char *)v16,
          _S2: v16,
          _N: (char *)pFirstItema - (char *)v16);
        pNew += (char *)pFirstItema - (char *)v16;
        v4 = !_LN21_4(pTemplate: v14);
        v19 = &v14->cy;
        if ( v4 )
          v19 = &v14->cdit;
        ++*v19;
        ppOleDlgItems[iItema] = nullptr;
        v17 = iItema;
      }
      v16 = pFirstItema;
      iItema = ++v17;
    }
    while ( v17 < nItems );
    ppOleDlgItems[nItems] = (DLGITEMTEMPLATE *)-1;
    return v14;
  }
  else
  {
LABEL_12:
    *ppOleDlgItems = (DLGITEMTEMPLATE *)-1;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004158EB
// Name: public: virtual class COleControlContainer __near * COccManager::CreateContainer(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleControlContainer *__thiscall COccManager::CreateContainer(COccManager *this, CWnd *pWnd)
{
  COleControlContainer *v2; // ecx
  COleControlContainer *result; // eax

  v2 = (COleControlContainer *)operator new(nSize: 0x80u);
  result = nullptr;
  if ( v2 != nullptr )
    return COleControlContainer::COleControlContainer(this: v2, pWnd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415920
// Name: public: virtual int COccManager::CreateDlgControls(class CWnd __near *,char const __near *,struct _AFX_OCC_DIALOG_INFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HGLOBAL __thiscall COccManager::CreateDlgControls(
        COccManager *this,
        CWnd *pWndParent,
        const char *lpszResourceName,
        _AFX_OCC_DIALOG_INFO *pOccDlgInfo)
{
  void *v4; // ebx
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HGLOBAL result; // eax
  HGLOBAL hResource; // [esp+Ch] [ebp-4h]
  int bResult; // [esp+1Ch] [ebp+Ch]

  v4 = nullptr;
  hResource = nullptr;
  if ( lpszResourceName != nullptr )
  {
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
    ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszResourceName, lpType: (LPCSTR)0xF0);
    if ( ResourceA != nullptr )
    {
      result = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
      hResource = result;
      if ( result == nullptr )
        return result;
      v4 = LockResource(hResData: result);
    }
  }
  bResult = 1;
  if ( v4 != nullptr )
  {
    bResult = this->CreateDlgControls(this, a2: pWndParent, a3: v4, a4: pOccDlgInfo);
    if ( hResource != nullptr )
      FreeResource(hResData: hResource);
  }
  if ( pWndParent->m_pCtrlCont != nullptr )
    pWndParent->m_pCtrlCont->FillListSitesOrWnds(this: pWndParent->m_pCtrlCont, a2: pOccDlgInfo);
  return (HGLOBAL)bResult;
}

//------------------------------------------------------------------------------
// Address: 0x004159B2
// Name: public: virtual class COleControlSite __near * COleControlSiteFactory::CreateSite(class COleControlContainer __near *,class CControlCreationInfo const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleControlSite *__thiscall COleControlSiteFactory::CreateSite(
        COleControlSiteFactory *this,
        COleControlContainer *pCtrlCont,
        const CControlCreationInfo *__formal)
{
  COleControlSite *v3; // ecx
  COleControlSite *result; // eax

  v3 = (COleControlSite *)operator new(nSize: 0xECu);
  result = nullptr;
  if ( v3 != nullptr )
    return COleControlSite::COleControlSite(this: v3, pCtrlCont);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004159E7
// Name: public: class COleControlSite __near * CControlSiteFactoryMgr::CreateSite(class COleControlContainer __near *,class CControlCreationInfo const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleControlSite *__thiscall CControlSiteFactoryMgr::CreateSite(
        CControlSiteFactoryMgr *this,
        COleControlContainer *pCtrlCont,
        const CControlCreationInfo *creationInfo)
{
  CList<IControlSiteFactory *,IControlSiteFactory *>::CNode *m_pNodeHead; // esi
  COleControlSite *result; // eax
  IControlSiteFactory *data; // ecx

  m_pNodeHead = this->m_lstFactory.m_pNodeHead;
  result = nullptr;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data != nullptr )
    {
      result = data->CreateSite(this: data, a2: pCtrlCont, a3: creationInfo);
      if ( result != nullptr )
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415A15
// Name: public: CList<class IControlSiteFactory __near *,class IControlSiteFactory __near *>::CList<class IControlSiteFactory __near *,class IControlSiteFactory __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<IControlSiteFactory *,IControlSiteFactory *> *__thiscall CList<IControlSiteFactory *,IControlSiteFactory *>::CList<IControlSiteFactory *,IControlSiteFactory *>(
        CList<IControlSiteFactory *,IControlSiteFactory *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<IControlSiteFactory *,IControlSiteFactory *>_vtbl *)&CList<IControlSiteFactory *,IControlSiteFactory *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415A3D
// Name: public: void CArchive::EnsureRead(void __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CArchive::EnsureRead(CArchive *this, char *lpBuf, unsigned int nCount)
{
  if ( CArchive::Read(this, lpBuf, nMax: nCount) != nCount )
    AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00415A5F
// Name: public: virtual CList<class IControlSiteFactory __near *,class IControlSiteFactory __near *>::~CList<class IControlSiteFactory __near *,class IControlSiteFactory __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<IControlSiteFactory *,IControlSiteFactory *>::~CList<IControlSiteFactory *,IControlSiteFactory *>(
        CList<IControlSiteFactory *,IControlSiteFactory *> *this)
{
  this->__vftable = (CList<IControlSiteFactory *,IControlSiteFactory *>_vtbl *)&CList<IControlSiteFactory *,IControlSiteFactory *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00415A91
// Name: protected: void COccManager::BindControls(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COccManager::BindControls(COccManager *this, CWnd *pWndParent)
{
  COleControlContainer *m_pCtrlCont; // eax
  CPtrList::CNode *m_pNodeHead; // ebx
  void *data; // esi
  int v5; // eax
  CDataBoundProperty *i; // edi
  CWnd *DlgItem; // eax
  CWnd *v8; // edi
  CPtrList::CNode *v9; // esi
  int v10; // ecx

  m_pCtrlCont = pWndParent->m_pCtrlCont;
  if ( m_pCtrlCont != nullptr )
  {
    m_pNodeHead = m_pCtrlCont->m_listSitesOrWnds.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      v5 = *((_DWORD *)data + 1);
      m_pNodeHead = m_pNodeHead->pNext;
      if ( v5 != 0 )
      {
        for ( i = *(CDataBoundProperty **)(v5 + 148); i != nullptr; i = CDataBoundProperty::GetNext(this: i) )
        {
          CDataBoundProperty::SetClientSite(this: i, pClientSite: *((COleControlSite **)data + 1));
          if ( i->m_ctlid != 0 )
          {
            DlgItem = CWnd::GetDlgItem(this: pWndParent, nID: i->m_ctlid);
            CDataBoundProperty::SetDSCSite(this: i, pDSCSite: DlgItem->m_pCtrlSite);
          }
        }
        if ( *(_WORD *)(*((_DWORD *)data + 1) + 152) != 0 )
        {
          v8 = CWnd::GetDlgItem(this: pWndParent, nID: *(unsigned __int16 *)(*((_DWORD *)data + 1) + 152));
          v8->m_pCtrlSite->EnableDSC(this: v8->m_pCtrlSite);
          *(_DWORD *)(*((_DWORD *)data + 1) + 152) = v8->m_pCtrlSite;
          v8->m_pCtrlSite->m_pDataSourceControl->BindProp_2(
            this: v8->m_pCtrlSite->m_pDataSourceControl,
            a2: *((COleControlSite **)data + 1),
            a3: 1);
        }
      }
    }
    v9 = pWndParent->m_pCtrlCont->m_listSitesOrWnds.m_pNodeHead;
    while ( v9 != nullptr )
    {
      v10 = *((_DWORD *)v9->data + 1);
      v9 = v9->pNext;
      if ( v10 != 0 && *(_DWORD *)(v10 + 144) != 0 )
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 144) + 12))(a1: *(_DWORD *)(v10 + 144));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415BB2
// Name: public: virtual CControlSiteFactoryMgr::~CControlSiteFactoryMgr(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlSiteFactoryMgr::~CControlSiteFactoryMgr(CControlSiteFactoryMgr *this)
{
  COleControlSiteFactory *m_pOleControlSiteDefaultFactory; // ecx

  this->__vftable = (CControlSiteFactoryMgr_vtbl *)&CControlSiteFactoryMgr::`vftable';
  m_pOleControlSiteDefaultFactory = this->m_pOleControlSiteDefaultFactory;
  if ( m_pOleControlSiteDefaultFactory != nullptr )
    ((void (__thiscall *)(COleControlSiteFactory *, int))m_pOleControlSiteDefaultFactory->dtr_IControlSiteFactory)(
      a1: m_pOleControlSiteDefaultFactory,
      a2: 1);
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstFactory);
  this->m_lstFactory.__vftable = (CList<IControlSiteFactory *,IControlSiteFactory *>_vtbl *)&CList<IControlSiteFactory *,IControlSiteFactory *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstFactory);
}

//------------------------------------------------------------------------------
// Address: 0x00415BFB
// Name: public: int CControlSiteFactoryMgr::RegisterSiteFactory(class IControlSiteFactory __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlSiteFactoryMgr::RegisterSiteFactory(CControlSiteFactoryMgr *this, IControlSiteFactory *pFactory)
{
  CList<IControlSiteFactory *,IControlSiteFactory *> *p_m_lstFactory; // esi

  if ( pFactory == nullptr )
    AfxThrowInvalidArgException();
  p_m_lstFactory = &this->m_lstFactory;
  if ( CList<unsigned int,unsigned int>::Find(
         this: (CList<HWND__ *,HWND__ *> *)&this->m_lstFactory,
         searchValue: (HWND__ *)pFactory,
         startAfter: nullptr) == nullptr )
    CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::AddHead(
      this: (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *)p_m_lstFactory,
      newElement: (CMFCPropertyGridProperty *)pFactory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00415C30
// Name: public: static class CNoTrackObject __near * CProcessLocal<class COccManager>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNoTrackObject *__stdcall CProcessLocal<COccManager>::CreateObject()
{
  CNoTrackObject *result; // eax

  result = (CNoTrackObject *)CNoTrackObject::operator new(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CNoTrackObject_vtbl *)&COccManager::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415C45
// Name: public: CControlSiteFactoryMgr::CControlSiteFactoryMgr(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CControlSiteFactoryMgr *__thiscall CControlSiteFactoryMgr::CControlSiteFactoryMgr(CControlSiteFactoryMgr *this)
{
  COleControlSiteFactory *v2; // eax

  this->__vftable = (CControlSiteFactoryMgr_vtbl *)&CControlSiteFactoryMgr::`vftable';
  CList<IControlSiteFactory *,IControlSiteFactory *>::CList<IControlSiteFactory *,IControlSiteFactory *>(
    this: &this->m_lstFactory,
    nBlockSize: 10);
  v2 = (COleControlSiteFactory *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    v2->__vftable = (COleControlSiteFactory_vtbl *)&COleControlSiteFactory::`vftable';
  else
    v2 = nullptr;
  this->m_pOleControlSiteDefaultFactory = v2;
  CControlSiteFactoryMgr::RegisterSiteFactory(this, pFactory: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415CD6
// Name: public: static class CNoTrackObject __near * CProcessLocal<class CControlSiteFactoryMgr>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CControlSiteFactoryMgr *__stdcall CProcessLocal<CControlSiteFactoryMgr>::CreateObject()
{
  CControlSiteFactoryMgr *v0; // ecx
  CControlSiteFactoryMgr *result; // eax

  v0 = (CControlSiteFactoryMgr *)CNoTrackObject::operator new(nSize: 0x24u);
  result = nullptr;
  if ( v0 != nullptr )
    return CControlSiteFactoryMgr::CControlSiteFactoryMgr(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415D02
// Name: void AfxEnableControlContainer(class COccManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AfxEnableControlContainer(COccManager *pOccManager)
{
  COccManager *Data; // esi

  Data = pOccManager;
  if ( pOccManager == nullptr )
  {
    Data = (COccManager *)CProcessLocalObject::GetData(
                            this: &_afxOccManager,
                            pfnCreateObject: CProcessLocal<COccManager>::CreateObject);
    if ( Data == nullptr )
      AfxThrowInvalidArgException();
  }
  AfxGetModuleState()->m_pOccManager = Data;
}

//------------------------------------------------------------------------------
// Address: 0x00415D34
// Name: public: virtual class COleControlSite __near * COccManager::CreateSite(class COleControlContainer __near *,class CControlCreationInfo const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleControlSite *__thiscall COccManager::CreateSite(
        COccManager *this,
        COleControlContainer *pCtrlCont,
        const CControlCreationInfo *creationInfo)
{
  COleControlSite *Site; // esi
  CControlSiteFactoryMgr *Data; // eax

  Site = this->CreateSite_2(this, a2: pCtrlCont);
  if ( Site != nullptr )
  {
    if ( CControlCreationInfo::IsManaged(this: creationInfo) )
      return nullptr;
  }
  else
  {
    Data = (CControlSiteFactoryMgr *)CProcessLocalObject::GetData(
                                       this: &_afxControlFactoryMgr,
                                       pfnCreateObject: (CNoTrackObject *(__stdcall *)())CProcessLocal<CControlSiteFactoryMgr>::CreateObject);
    if ( Data == nullptr || (Site = CControlSiteFactoryMgr::CreateSite(this: Data, pCtrlCont, creationInfo)) == nullptr )
      AfxThrowInvalidArgException();
  }
  return Site;
}

//------------------------------------------------------------------------------
// Address: 0x00415D8A
// Name: protected: int COccManager::CreateDlgControl(class CWnd __near *,struct HWND__ __near *,int,struct DLGITEMTEMPLATE __near *,unsigned short,unsigned char __near *,unsigned long,struct HWND__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COccManager::CreateDlgControl(
        COccManager *this,
        CWnd *pWndParent,
        HWND hwAfter,
        int bDialogEx,
        DLGITEMTEMPLATE *pItem,
        unsigned __int16 nMsg,
        unsigned __int8 *lpData,
        unsigned int cb,
        HWND__ **phWnd)
{
  DLGITEMTEMPLATE *v9; // edi
  unsigned __int8 *v10; // esi
  __int16 style; // ax
  unsigned __int16 id; // dx
  __int16 style_high; // ax
  int y; // edx
  int x; // ebx
  int v16; // ecx
  UINT v17; // ebx
  wchar_t *v18; // eax
  CAfxStringMgr *StringManager; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // eax
  const char *v25; // esi
  ATL::IAtlStringMgr_vtbl *v26; // eax
  CDataBoundProperty *v27; // eax
  CDataBoundProperty *v28; // eax
  HRESULT v29; // eax
  int v30; // ebx
  CMemFile *v31; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-CCh]
  CMemFile v34; // [esp+10h] [ebp-B4h] BYREF
  void *p; // [esp+3Ch] [ebp-88h]
  int dispid; // [esp+40h] [ebp-84h]
  int v37; // [esp+44h] [ebp-80h]
  HWND hWndInsertAfter; // [esp+48h] [ebp-7Ch]
  int v39; // [esp+4Ch] [ebp-78h]
  unsigned int v40; // [esp+50h] [ebp-74h]
  HWND__ **v41; // [esp+54h] [ebp-70h]
  int v42; // [esp+58h] [ebp-6Ch]
  CWnd *v43; // [esp+5Ch] [ebp-68h]
  CDataBoundProperty *pLast; // [esp+60h] [ebp-64h]
  wchar_t *bstrLicKey; // [esp+64h] [ebp-60h]
  ATL::CStringData strSrc; // [esp+68h] [ebp-5Ch] BYREF
  unsigned int nBufferSize; // [esp+78h] [ebp-4Ch]
  COleControlSite *ppNewSite; // [esp+7Ch] [ebp-48h] BYREF
  _GUID pclsid; // [esp+80h] [ebp-44h] BYREF
  tagRECT Rect; // [esp+90h] [ebp-34h] BYREF
  _DWORD v51[2]; // [esp+A0h] [ebp-24h] BYREF
  __int16 cx; // [esp+A8h] [ebp-1Ch]
  __int16 cy; // [esp+AAh] [ebp-1Ah]
  unsigned __int16 v54; // [esp+ACh] [ebp-18h]
  __int16 v55; // [esp+AEh] [ebp-16h]
  __int16 v56; // [esp+B0h] [ebp-14h]
  int v57; // [esp+C0h] [ebp-4h]

  v9 = pItem;
  v10 = lpData;
  v43 = pWndParent;
  hWndInsertAfter = hwAfter;
  strSrc.nRefs = nMsg;
  nBufferSize = cb;
  v41 = phWnd;
  strSrc.nDataLength = (int)&pItem[1];
  if ( bDialogEx != 0 )
  {
    style = pItem[1].style;
    v51[0] = *(_DWORD *)&pItem->x;
    v51[1] = pItem->dwExtendedStyle;
    cx = pItem->cx;
    cy = pItem->cy;
    id = pItem->id;
    v55 = style;
    style_high = HIWORD(pItem[1].style);
    v54 = id;
    v56 = style_high;
    v9 = (DLGITEMTEMPLATE *)v51;
    strSrc.nDataLength = (int)&pItem[1].dwExtendedStyle + 2;
  }
  y = v9->y;
  x = v9->x;
  v16 = v9->cx;
  Rect.bottom = y + v9->cy;
  m_hWnd = v43->m_hWnd;
  Rect.left = x;
  Rect.top = y;
  Rect.right = x + v16;
  MapDialogRect(hDlg: m_hWnd, lpRect: &Rect);
  bstrLicKey = nullptr;
  if ( nBufferSize >= 4 )
  {
    v17 = *(_DWORD *)lpData;
    nBufferSize -= 4;
    v10 = lpData + 4;
    if ( v17 != 0 )
    {
      v18 = SysAllocStringLen(strIn: (const OLECHAR *)v10, ui: v17);
      v10 += 2 * v17;
      nBufferSize -= 2 * v17;
      bstrLicKey = v18;
    }
  }
  pLast = nullptr;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&strSrc,
    pStringMgr: StringManager);
  v57 = 0;
  v39 = 0;
  v42 = 0;
  v40 = 0;
  if ( LOWORD(strSrc.nRefs) == 890 || LOWORD(strSrc.nRefs) == 891 )
  {
    v20 = *(_DWORD *)v10;
    v21 = *(_DWORD *)v10 - 12;
    v10 += 12;
    v37 = v20;
    strSrc.nAllocLength = v21;
    if ( v21 != 0 )
    {
      do
      {
        v22 = *(_DWORD *)v10;
        v23 = *((unsigned __int16 *)v10 + 2);
        strSrc.nAllocLength -= 6;
        v10 += 6;
        dispid = v22;
        if ( v22 == -2147418111 )
        {
          v42 = *(_DWORD *)v10;
          v24 = *((_DWORD *)v10 + 1);
          v25 = (const char *)(v10 + 16);
          v40 = v24;
          ATL::CSimpleStringT<char,0>::SetString(this: (ATL::CSimpleStringT<char,0> *)&strSrc, pszSrc: v25);
          v26 = strSrc.pStringMgr[-3].__vftable;
          strSrc.nAllocLength += -17 - (_DWORD)v26;
          v10 = (unsigned __int8 *)&v26->Allocate + (_DWORD)v25 + 1;
          v39 = v23;
        }
        else
        {
          v27 = (CDataBoundProperty *)operator new(nSize: 0x1Cu);
          p = v27;
          LOBYTE(v57) = 1;
          if ( v27 != nullptr )
            v28 = CDataBoundProperty::CDataBoundProperty(this: v27, pLast, dispid, ctlid: v23);
          else
            v28 = nullptr;
          LOBYTE(v57) = 0;
          pLast = v28;
        }
      }
      while ( strSrc.nAllocLength != 0 );
      v20 = v37;
    }
    nBufferSize -= v20;
    strSrc.nRefs += 65532;
  }
  if ( *(_WORD *)strSrc.nDataLength == 123 )
    v29 = CLSIDFromString(lpsz: (LPCOLESTR)strSrc.nDataLength, &pclsid);
  else
    v29 = CLSIDFromProgID(lpszProgID: (LPCOLESTR)strSrc.nDataLength, lpclsid: &pclsid);
  v30 = 0;
  strSrc.nDataLength = v29;
  CMemFile::CMemFile(this: &v34, lpBuffer: v10, nBufferSize, nGrowBytes: 0);
  v31 = (unsigned __int16)(LOWORD(strSrc.nRefs) - 888) != 0 ? &v34 : nullptr;
  LOBYTE(v57) = 2;
  ppNewSite = nullptr;
  if ( strSrc.nDataLength >= 0
    && CWnd::InitControlContainer(this: v43, bCreateFromResource: 1)
    && COleControlContainer::CreateControl(
         this: v43->m_pCtrlCont,
         pWndCtrl: nullptr,
         clsid: &pclsid,
         lpszWindowName: nullptr,
         dwStyle: v9->style,
         rect: &Rect,
         nID: v9->id,
         pPersist: v31,
         bStorage: LOWORD(strSrc.nRefs) == 887,
         bstrLicKey,
         &ppNewSite) )
  {
    COleControlSite::FreezeEvents(this: ppNewSite, bFreeze: 1);
    SetWindowPos(hWnd: ppNewSite->m_hWnd, hWndInsertAfter, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x13u);
    ppNewSite->m_pBindings = pLast;
    ATL::CSimpleStringT<char,0>::operator=(this: &ppNewSite->m_strDataField, &strSrc);
    ppNewSite->m_ctlidRowSource = v39;
    ppNewSite->m_defdispid = v42;
    ppNewSite->m_dwType = v40;
  }
  if ( bstrLicKey != nullptr )
    SysFreeString(bstrString: bstrLicKey);
  if ( ppNewSite != nullptr )
  {
    *v41 = ppNewSite->m_hWnd;
    v30 = 1;
  }
  else
  {
    *v41 = nullptr;
  }
  LOBYTE(v57) = 0;
  CMemFile::~CMemFile(this: &v34);
  ATL::CStringData::Release(this: (ATL::CStringData *)&strSrc.pStringMgr[-4]);
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x00416094
// Name: public: virtual int COccManager::CreateDlgControls(class CWnd __near *,void __near *,struct _AFX_OCC_DIALOG_INFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COccManager::CreateDlgControls(
        COccManager *this,
        CWnd *pWndParent,
        HWND__ *lpResource,
        _AFX_OCC_DIALOG_INFO *pOccDlgInfo)
{
  DLGTEMPLATE *m_pNewTemplate; // eax
  CWnd *v7; // ebx
  HWND__ *v8; // edi
  unsigned __int16 v9; // bx
  unsigned __int8 *v10; // edi
  HWND Window; // eax
  DLGITEMTEMPLATE *v12; // esi
  HWND__ *v13; // ebx
  HWND Parent; // eax
  COleControlContainer *m_pCtrlCont; // ecx
  unsigned int dwLen; // [esp+8h] [ebp-18h]
  BOOL bDialogEx; // [esp+Ch] [ebp-14h]
  HWND__ *hwNew; // [esp+10h] [ebp-10h] BYREF
  DLGITEMTEMPLATE **ppOleDlgItems; // [esp+14h] [ebp-Ch]
  HWND__ *hwParent; // [esp+18h] [ebp-8h]
  int bSuccess; // [esp+1Ch] [ebp-4h]
  HWND__ *hwAfter; // [esp+2Ch] [ebp+Ch]
  int iItem; // [esp+30h] [ebp+10h]

  m_pNewTemplate = pOccDlgInfo->m_pNewTemplate;
  if ( pOccDlgInfo->m_pNewTemplate == nullptr )
    return 1;
  v7 = pWndParent;
  if ( pWndParent != nullptr )
    hwParent = pWndParent->m_hWnd;
  else
    hwParent = nullptr;
  v8 = lpResource;
  bDialogEx = _LN21_4(pTemplate: m_pNewTemplate);
  bSuccess = 1;
  if ( lpResource != nullptr )
  {
    iItem = 0;
    hwAfter = nullptr;
    ppOleDlgItems = pOccDlgInfo->m_ppOleDlgItems;
    do
    {
      if ( *(_WORD *)v8 == 0 )
        break;
      v9 = *((_WORD *)v8 + 1);
      dwLen = *((_DWORD *)v8 + 1);
      v10 = (unsigned __int8 *)(v8 + 2);
      if ( v9 == 886 || v9 == 890 || v9 == 887 || v9 == 891 || v9 == 888 )
      {
        while ( 1 )
        {
          v12 = ppOleDlgItems[iItem++];
          if ( v12 != nullptr )
            break;
          if ( hwAfter != nullptr )
            Window = GetWindow(hWnd: hwAfter, uCmd: 2u);
          else
            Window = GetWindow(hWnd: hwParent, uCmd: 5u);
          hwAfter = Window;
        }
        hwNew = nullptr;
        if ( v12 == (DLGITEMTEMPLATE *)-1
          || COccManager::CreateDlgControl(
               this,
               pWndParent,
               hwAfter,
               bDialogEx,
               pItem: v12,
               nMsg: v9,
               lpData: v10,
               cb: dwLen,
               phWnd: &hwNew) == 0 )
        {
          bSuccess = 0;
        }
        else
        {
          v13 = hwNew;
          if ( hwNew != nullptr )
          {
            if ( bDialogEx )
              SetWindowContextHelpId(a1: hwNew, a2: v12->style);
            Parent = GetParent(hWnd: v13);
            if ( Parent == hwParent )
              hwAfter = v13;
          }
        }
      }
      v8 = (HWND__ *)&v10[dwLen];
    }
    while ( bSuccess != 0 );
    if ( bSuccess == 0 )
      return bSuccess;
    v7 = pWndParent;
  }
  m_pCtrlCont = v7->m_pCtrlCont;
  if ( m_pCtrlCont != nullptr )
    COleControlContainer::FreezeAllEvents(this: m_pCtrlCont, bFreeze: 0);
  COccManager::BindControls(this, pWndParent: v7);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x004161F0
// Name: public: virtual void CMFCAutoHideButton::ShowButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::ShowButton(CMFCAutoHideButton *this, int bShow)
{
  this->m_bVisible = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x004161FF
// Name: public: virtual void CDC::SetOutputDC(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::SetOutputDC(CDC *this, HDC__ *hDC)
{
  this->m_hDC = hDC;
}

//------------------------------------------------------------------------------
// Address: 0x0041620E
// Name: public: virtual void CDC::ReleaseAttribDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::ReleaseAttribDC(CDC *this)
{
  this->m_hAttribDC = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00416213
// Name: public: virtual void CDC::ReleaseOutputDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::ReleaseOutputDC(CDC *this)
{
  this->m_hDC = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00416218
// Name: public: virtual int CDC::SaveDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SaveDC(CDC *this)
{
  int v2; // ebx

  v2 = 0;
  if ( this->m_hAttribDC != nullptr )
    v2 = SaveDC(hdc: this->m_hAttribDC);
  if ( this->m_hDC != this->m_hAttribDC && SaveDC(hdc: this->m_hDC) != 0 )
    return -1;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041624B
// Name: public: virtual int CDC::RestoreDC(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::RestoreDC(CDC *this, int nSavedDC)
{
  HDC__ *m_hDC; // ecx
  BOOL result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = true;
  if ( m_hDC != this->m_hAttribDC )
    result = RestoreDC(hdc: m_hDC, nSavedDC);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return result && RestoreDC(hdc: m_hAttribDC, nSavedDC);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041628D
// Name: public: virtual unsigned long CDC::SetBkColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CDC::SetBkColor(CDC *this, COLORREF crColor)
{
  HDC__ *m_hDC; // ecx
  unsigned int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = -1;
  if ( m_hDC != this->m_hAttribDC )
    result = SetBkColor(hdc: m_hDC, color: crColor);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetBkColor(hdc: m_hAttribDC, color: crColor);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004162C0
// Name: public: int CDC::SetBkMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SetBkMode(CDC *this, int nBkMode)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = SetBkMode(hdc: m_hDC, mode: nBkMode);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetBkMode(hdc: m_hAttribDC, mode: nBkMode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004162F2
// Name: public: int CDC::SetPolyFillMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SetPolyFillMode(CDC *this, int nPolyFillMode)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = SetPolyFillMode(hdc: m_hDC, mode: nPolyFillMode);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetPolyFillMode(hdc: m_hAttribDC, mode: nPolyFillMode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416324
// Name: public: int CDC::SetROP2(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SetROP2(CDC *this, int nDrawMode)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = SetROP2(hdc: m_hDC, rop2: nDrawMode);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetROP2(hdc: m_hAttribDC, rop2: nDrawMode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416356
// Name: public: virtual unsigned long CDC::SetTextColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CDC::SetTextColor(CDC *this, COLORREF crColor)
{
  HDC__ *m_hDC; // ecx
  unsigned int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = -1;
  if ( m_hDC != this->m_hAttribDC )
    result = SetTextColor(hdc: m_hDC, color: crColor);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetTextColor(hdc: m_hAttribDC, color: crColor);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416389
// Name: public: virtual int CDC::SetMapMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SetMapMode(CDC *this, int nMapMode)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = SetMapMode(hdc: m_hDC, iMode: nMapMode);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetMapMode(hdc: m_hAttribDC, iMode: nMapMode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004163BB
// Name: public: virtual int CDC::GetClipBox(struct tagRECT __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::GetClipBox(CDC *this, tagRECT *lpRect)
{
  return GetClipBox(hdc: this->m_hDC, lprect: lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x004163D0
// Name: public: int CDC::ExcludeClipRect(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::ExcludeClipRect(CDC *this, const tagRECT *lpRect)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // edi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = ExcludeClipRect(
               hdc: m_hDC,
               left: lpRect->left,
               top: lpRect->top,
               right: lpRect->right,
               bottom: lpRect->bottom);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return ExcludeClipRect(
             hdc: m_hAttribDC,
             left: lpRect->left,
             top: lpRect->top,
             right: lpRect->right,
             bottom: lpRect->bottom);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416417
// Name: public: int CDC::IntersectClipRect(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::IntersectClipRect(CDC *this, const tagRECT *lpRect)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  HDC__ *m_hAttribDC; // edi

  m_hDC = this->m_hDC;
  result = 0;
  if ( m_hDC != this->m_hAttribDC )
    result = IntersectClipRect(
               hdc: m_hDC,
               left: lpRect->left,
               top: lpRect->top,
               right: lpRect->right,
               bottom: lpRect->bottom);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return IntersectClipRect(
             hdc: m_hAttribDC,
             left: lpRect->left,
             top: lpRect->top,
             right: lpRect->right,
             bottom: lpRect->bottom);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041645E
// Name: public: int CDC::LineTo(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::LineTo(CDC *this, int x, int y)
{
  HDC__ *m_hAttribDC; // eax

  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr && this->m_hDC != m_hAttribDC )
    MoveToEx(hdc: m_hAttribDC, x, y, lppt: nullptr);
  return LineTo(hdc: this->m_hDC, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x00416495
// Name: public: unsigned int CDC::SetTextAlign(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __thiscall CDC::SetTextAlign(CDC *this, UINT nFlags)
{
  HDC__ *m_hDC; // eax
  int v4; // ebx
  HDC__ *m_hAttribDC; // esi

  m_hDC = this->m_hDC;
  v4 = -1;
  if ( m_hDC != this->m_hAttribDC )
    SetTextAlign(hdc: m_hDC, align: nFlags);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    return SetTextAlign(hdc: m_hAttribDC, align: nFlags);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004164CE
// Name: public: unsigned long CDC::GetLayout(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall CDC::GetLayout(CDC *this)
{
  return GetLayout(hdc: this->m_hDC);
}

//------------------------------------------------------------------------------
// Address: 0x004164D8
// Name: public: unsigned long CDC::SetLayout(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall CDC::SetLayout(CDC *this, DWORD dwSetLayout)
{
  return SetLayout(hdc: this->m_hDC, l: dwSetLayout);
}

//------------------------------------------------------------------------------
// Address: 0x004164ED
// Name: public: virtual struct CRuntimeClass __near * CResourceException::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CResourceException::GetRuntimeClass(CResourceException *this)
{
  return &CResourceException::classCResourceException;
}

//------------------------------------------------------------------------------
// Address: 0x004164F3
// Name: public: virtual struct CRuntimeClass __near * CUserException::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CUserException::GetRuntimeClass(CUserException *this)
{
  return &CUserException::classCUserException;
}

//------------------------------------------------------------------------------
// Address: 0x004164F9
// Name: public: virtual struct CRuntimeClass __near * CDC::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDC::GetRuntimeClass(CDC *this)
{
  return &CDC::classCDC;
}

//------------------------------------------------------------------------------
// Address: 0x004164FF
// Name: public: virtual struct CRuntimeClass __near * CClientDC::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CClientDC::GetRuntimeClass(CClientDC *this)
{
  return &CClientDC::classCClientDC;
}

//------------------------------------------------------------------------------
// Address: 0x00416505
// Name: public: virtual struct CRuntimeClass __near * CWindowDC::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWindowDC::GetRuntimeClass(CWindowDC *this)
{
  return &CWindowDC::classCWindowDC;
}

//------------------------------------------------------------------------------
// Address: 0x0041650B
// Name: public: virtual struct CRuntimeClass __near * CPaintDC::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPaintDC::GetRuntimeClass(CPaintDC *this)
{
  return &CPaintDC::classCPaintDC;
}

//------------------------------------------------------------------------------
// Address: 0x00416511
// Name: public: virtual struct CRuntimeClass __near * CGdiObject::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CGdiObject::GetRuntimeClass(CGdiObject *this)
{
  return &CGdiObject::classCGdiObject;
}

//------------------------------------------------------------------------------
// Address: 0x00416517
// Name: public: virtual struct CRuntimeClass __near * CPen::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPen::GetRuntimeClass(CPen *this)
{
  return &CPen::classCPen;
}

//------------------------------------------------------------------------------
// Address: 0x0041651D
// Name: public: virtual struct CRuntimeClass __near * CBrush::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBrush::GetRuntimeClass(CBrush *this)
{
  return &CBrush::classCBrush;
}

//------------------------------------------------------------------------------
// Address: 0x00416523
// Name: public: virtual struct CRuntimeClass __near * CFont::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFont::GetRuntimeClass(CFont *this)
{
  return &CFont::classCFont;
}

//------------------------------------------------------------------------------
// Address: 0x00416529
// Name: public: virtual struct CRuntimeClass __near * CBitmap::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBitmap::GetRuntimeClass(CBitmap *this)
{
  return &CBitmap::classCBitmap;
}

//------------------------------------------------------------------------------
// Address: 0x0041652F
// Name: public: virtual struct CRuntimeClass __near * CPalette::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPalette::GetRuntimeClass(CPalette *this)
{
  return &CPalette::classCPalette;
}

//------------------------------------------------------------------------------
// Address: 0x00416535
// Name: public: virtual struct CRuntimeClass __near * CRgn::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CRgn::GetRuntimeClass(CRgn *this)
{
  return &CRgn::classCRgn;
}

//------------------------------------------------------------------------------
// Address: 0x0041653B
// Name: void AfxThrowResourceException(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowResourceException()
{
  CResourceException *pExceptionObject; // [esp+0h] [ebp-4h] BYREF

  pExceptionObject = &_simpleResourceException;
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI5PAVCResourceException__);
}

//------------------------------------------------------------------------------
// Address: 0x00416557
// Name: void AfxThrowUserException(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowUserException()
{
  CUserException *pExceptionObject; // [esp+0h] [ebp-4h] BYREF

  pExceptionObject = &_simpleUserException;
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI5PAVCUserException__);
}

//------------------------------------------------------------------------------
// Address: 0x00416573
// Name: public: class CSize CDC::GetViewportExt(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::GetViewportExt(CDC *this, CSize *result)
{
  tagSIZE size; // [esp+0h] [ebp-8h] BYREF

  GetViewportExtEx(hdc: this->m_hAttribDC, lpsize: &size);
  *result = (CSize)size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416599
// Name: public: class CSize CDC::GetWindowExt(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::GetWindowExt(CDC *this, CSize *result)
{
  tagSIZE size; // [esp+0h] [ebp-8h] BYREF

  GetWindowExtEx(hdc: this->m_hAttribDC, lpsize: &size);
  *result = (CSize)size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004165BF
// Name: public: void CDC::FillRect(struct tagRECT const __near *,class CBrush __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDC::FillRect(CDC *this, const tagRECT *lpRect, CBrush *pBrush)
{
  HBRUSH m_hObject; // eax

  m_hObject = (HBRUSH)pBrush;
  if ( pBrush != nullptr )
    m_hObject = (HBRUSH)pBrush->m_hObject;
  FillRect(hDC: this->m_hDC, lprc: lpRect, hbr: m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x004165DF
// Name: public: int CDC::BitBlt(int,int,int,int,class CDC __near *,int,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::BitBlt(
        CDC *this,
        int x,
        int y,
        int nWidth,
        int nHeight,
        HDC__ *pSrcDC,
        int xSrc,
        int ySrc,
        DWORD dwRop)
{
  HDC__ *v9; // eax

  v9 = pSrcDC;
  if ( pSrcDC != nullptr )
    v9 = *((HDC__ **)pSrcDC + 1);
  return BitBlt(hdc: this->m_hDC, x, y, cx: nWidth, cy: nHeight, hdcSrc: v9, x1: xSrc, y1: ySrc, rop: dwRop);
}

//------------------------------------------------------------------------------
// Address: 0x00416611
// Name: public: CDC::CDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CDC::CDC(CDC *this)
{
  this->__vftable = (CDC_vtbl *)&CDC::`vftable';
  this->m_hDC = nullptr;
  this->m_hAttribDC = nullptr;
  this->m_bPrinting = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416625
// Name: public: virtual int CDC::PtVisible(int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::PtVisible(CDC *this, int x, int y)
{
  return PtVisible(hdc: this->m_hDC, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041663D
// Name: public: virtual int CDC::RectVisible(struct tagRECT const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::RectVisible(CDC *this, const tagRECT *lpRect)
{
  return RectVisible(hdc: this->m_hDC, lprect: lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x00416652
// Name: public: virtual int CDC::TextOutA(int,int,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::TextOutA(CDC *this, int x, int y, const char *lpszString, int nCount)
{
  return TextOutA(hdc: this->m_hDC, x, y, lpString: lpszString, c: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x00416670
// Name: public: virtual int CDC::ExtTextOutA(int,int,unsigned int,struct tagRECT const __near *,char const __near *,unsigned int,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::ExtTextOutA(
        CDC *this,
        int x,
        int y,
        UINT nOptions,
        const tagRECT *lpRect,
        const char *lpszString,
        UINT nCount,
        int *lpDxWidths)
{
  return ExtTextOutA(
           hdc: this->m_hDC,
           x,
           y,
           options: nOptions,
           lprect: lpRect,
           lpString: lpszString,
           c: nCount,
           lpDx: lpDxWidths);
}

//------------------------------------------------------------------------------
// Address: 0x00416697
// Name: public: virtual class CSize CDC::TabbedTextOutA(int,int,char const __near *,int,int,int __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::TabbedTextOutA(
        CDC *this,
        CSize *result,
        int x,
        int y,
        const char *lpszString,
        int nCount,
        int nTabPositions,
        int *lpnTabStopPositions,
        int nTabOrigin)
{
  LONG v9; // eax

  v9 = TabbedTextOutA(
         hdc: this->m_hDC,
         x,
         y,
         lpString: lpszString,
         chCount: nCount,
         nTabPositions,
         lpnTabStopPositions,
         nTabOrigin);
  result->cy = SHIWORD(v9);
  result->cx = (__int16)v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004166CF
// Name: public: virtual int CDC::DrawTextA(char const __near *,int,struct tagRECT __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::DrawTextA(CDC *this, const char *lpszString, int nCount, tagRECT *lpRect, UINT nFormat)
{
  return DrawTextA(hdc: this->m_hDC, lpchText: lpszString, cchText: nCount, lprc: lpRect, format: nFormat);
}

//------------------------------------------------------------------------------
// Address: 0x004166ED
// Name: public: virtual int CDC::DrawTextExA(char __near *,int,struct tagRECT __near *,unsigned int,struct tagDRAWTEXTPARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::DrawTextExA(
        CDC *this,
        char *lpszString,
        int nCount,
        tagRECT *lpRect,
        UINT nFormat,
        tagDRAWTEXTPARAMS *lpDTParams)
{
  return DrawTextExA(
           hdc: this->m_hDC,
           lpchText: lpszString,
           cchText: nCount,
           lprc: lpRect,
           format: nFormat,
           lpdtp: lpDTParams);
}

//------------------------------------------------------------------------------
// Address: 0x0041670E
// Name: public: virtual int CDC::GrayStringA(class CBrush __near *,int (*)(struct HDC__ __near *,long,int),long,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDC::GrayStringA(
        CDC *this,
        CBrush *pBrush,
        int (__stdcall *lpfnOutput)(HDC__ *, int, int),
        LPARAM lpData,
        int nCount,
        int x,
        int y,
        int nWidth,
        int nHeight)
{
  HBRUSH m_hObject; // eax

  m_hObject = (HBRUSH)pBrush;
  if ( pBrush != nullptr )
    m_hObject = (HBRUSH)pBrush->m_hObject;
  return GrayStringA(
           hDC: this->m_hDC,
           hBrush: m_hObject,
           lpOutputFunc: lpfnOutput,
           lpData,
           nCount,
           X: x,
           Y: y,
           nWidth,
           nHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00416740
// Name: public: virtual int CDC::Escape(int,int,char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::Escape(CDC *this, int nEscape, int nCount, const char *lpszInData, void *lpOutData)
{
  return Escape(hdc: this->m_hDC, iEscape: nEscape, cjIn: nCount, pvIn: lpszInData, pvOut: lpOutData);
}

//------------------------------------------------------------------------------
// Address: 0x0041675E
// Name: public: int CDC::SelectObject(class CRgn __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDC::SelectObject(CDC *this, CRgn *pRgn)
{
  HDC__ *m_hDC; // ecx
  int result; // eax
  void *m_hObject; // eax
  HDC__ *m_hAttribDC; // esi
  void *v7; // eax

  m_hDC = this->m_hDC;
  result = -1;
  if ( m_hDC != this->m_hAttribDC )
  {
    if ( pRgn != nullptr )
      m_hObject = pRgn->m_hObject;
    else
      m_hObject = nullptr;
    result = (int)SelectObject(hdc: m_hDC, h: m_hObject);
  }
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
  {
    if ( pRgn != nullptr )
      v7 = pRgn->m_hObject;
    else
      v7 = nullptr;
    return (int)SelectObject(hdc: m_hAttribDC, h: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004167A8
// Name: public: virtual class CPoint CDC::SetViewportOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CDC::SetViewportOrg(CDC *this, CPoint *result, int x, int y)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->x = 0;
  result->y = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    SetViewportOrgEx(hdc: m_hDC, x, y, lppt: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    SetViewportOrgEx(hdc: m_hAttribDC, x, y, lppt: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004167EE
// Name: public: virtual class CPoint CDC::OffsetViewportOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CDC::OffsetViewportOrg(CDC *this, CPoint *result, int nWidth, int nHeight)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->x = 0;
  result->y = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    OffsetViewportOrgEx(hdc: m_hDC, x: nWidth, y: nHeight, lppt: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    OffsetViewportOrgEx(hdc: m_hAttribDC, x: nWidth, y: nHeight, lppt: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416834
// Name: public: virtual class CSize CDC::SetViewportExt(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::SetViewportExt(CDC *this, CSize *result, int x, int y)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->cx = 0;
  result->cy = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    SetViewportExtEx(hdc: m_hDC, x, y, lpsz: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    SetViewportExtEx(hdc: m_hAttribDC, x, y, lpsz: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041687A
// Name: public: virtual class CSize CDC::ScaleViewportExt(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::ScaleViewportExt(CDC *this, CSize *result, int xNum, int xDenom, int yNum, int yDenom)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // edi

  result->cx = 0;
  result->cy = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    ScaleViewportExtEx(hdc: m_hDC, xn: xNum, dx: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    ScaleViewportExtEx(hdc: m_hAttribDC, xn: xNum, dx: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004168CC
// Name: public: class CPoint CDC::SetWindowOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CDC::SetWindowOrg(CDC *this, CPoint *result, int x, int y)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->x = 0;
  result->y = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    SetWindowOrgEx(hdc: m_hDC, x, y, lppt: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    SetWindowOrgEx(hdc: m_hAttribDC, x, y, lppt: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416912
// Name: public: class CPoint CDC::OffsetWindowOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CDC::OffsetWindowOrg(CDC *this, CPoint *result, int nWidth, int nHeight)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->x = 0;
  result->y = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    OffsetWindowOrgEx(hdc: m_hDC, x: nWidth, y: nHeight, lppt: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    OffsetWindowOrgEx(hdc: m_hAttribDC, x: nWidth, y: nHeight, lppt: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416958
// Name: public: virtual class CSize CDC::SetWindowExt(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::SetWindowExt(CDC *this, CSize *result, int x, int y)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->cx = 0;
  result->cy = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    SetWindowExtEx(hdc: m_hDC, x, y, lpsz: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    SetWindowExtEx(hdc: m_hAttribDC, x, y, lpsz: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041699E
// Name: public: virtual class CSize CDC::ScaleWindowExt(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDC::ScaleWindowExt(CDC *this, CSize *result, int xNum, int xDenom, int yNum, int yDenom)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // edi

  result->cx = 0;
  result->cy = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    ScaleWindowExtEx(hdc: m_hDC, xn: xNum, xd: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    ScaleWindowExtEx(hdc: m_hAttribDC, xn: xNum, xd: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004169F0
// Name: public: int CDC::SelectClipRgn(class CRgn __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRGN __thiscall CDC::SelectClipRgn(CDC *this, CRgn *pRgn)
{
  HDC__ *m_hDC; // ecx
  HRGN result; // eax
  HDC__ *m_hAttribDC; // esi
  HRGN m_hObject; // eax

  m_hDC = this->m_hDC;
  result = nullptr;
  if ( m_hDC != this->m_hAttribDC )
  {
    if ( pRgn != nullptr )
      result = (HRGN)pRgn->m_hObject;
    result = (HRGN)SelectClipRgn(hdc: m_hDC, hrgn: result);
  }
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
  {
    if ( pRgn != nullptr )
      m_hObject = (HRGN)pRgn->m_hObject;
    else
      m_hObject = nullptr;
    return (HRGN)SelectClipRgn(hdc: m_hAttribDC, hrgn: m_hObject);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416A35
// Name: public: class CPoint CDC::MoveTo(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CDC::MoveTo(CDC *this, CPoint *result, int x, int y)
{
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // esi

  result->x = 0;
  result->y = 0;
  m_hDC = this->m_hDC;
  if ( m_hDC != this->m_hAttribDC )
    MoveToEx(hdc: m_hDC, x, y, lppt: result);
  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr )
    MoveToEx(hdc: m_hAttribDC, x, y, lppt: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BD8C
// Name: int AfxWinInit(struct HINSTANCE__ __near *,struct HINSTANCE__ __near *,char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxWinInit(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  UINT v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  CWinApp *m_pCurrentWinApp; // eax

  v4 = SetErrorMode(uMode: 0);
  SetErrorMode(uMode: v4 | 0x8001);
  ModuleState = AfxGetModuleState();
  ModuleState->m_hCurrentInstanceHandle = hInstance;
  ModuleState->m_hCurrentResourceHandle = hInstance;
  AFX_MODULE_STATE::CreateActivationContext(this: ModuleState);
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
  {
    m_pCurrentWinApp->m_lpCmdLine = lpCmdLine;
    m_pCurrentWinApp->m_nCmdShow = nCmdShow;
    m_pCurrentWinApp->m_hInstance = hInstance;
    CWinApp::SetCurrentHandles(this: m_pCurrentWinApp);
  }
  if ( AfxGetModuleState()->m_bDLL == 0 )
    AfxInitThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043BDF3
// Name: public: static int CFileException::OsErrorToException(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CFileException::OsErrorToException(unsigned int lOsErr)
{
  int result; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax

  if ( lOsErr > 0x10B )
  {
    if ( lOsErr != 995 && lOsErr != 996 && lOsErr != 997 )
    {
      if ( lOsErr != 999 )
        return 1;
      return 5;
    }
    return 10;
  }
  if ( lOsErr == 267 )
    return 3;
  if ( lOsErr > 0x3E )
  {
    if ( lOsErr > 0x6B )
    {
      if ( lOsErr > 0x90 )
      {
        if ( lOsErr <= 0xB6 )
        {
          switch ( lOsErr )
          {
            case 0xB6u:
              return 6;
            case 0x91u:
              return 7;
            case 0x9Au:
            case 0xA1u:
              return 3;
            default:
              break;
          }
          if ( lOsErr != 167 )
          {
            if ( lOsErr != 170 )
              return 1;
            return 5;
          }
          return 12;
        }
        if ( lOsErr == 183 )
          return 5;
        if ( lOsErr == 191 || lOsErr == 193 )
          return 6;
        v3 = lOsErr - 206;
        if ( lOsErr == 206 )
          return 3;
LABEL_40:
        if ( v3 != 2 )
          return 1;
        return 3;
      }
      if ( lOsErr == 144 )
        return 3;
      if ( lOsErr > 0x75 )
      {
        if ( lOsErr != 123 && lOsErr != 124 && lOsErr != 125 )
        {
          v2 = lOsErr - 131;
          if ( lOsErr == 131 )
            return 9;
LABEL_19:
          if ( v2 == 1 )
            return 9;
          return 1;
        }
        return 3;
      }
      if ( lOsErr != 117 )
      {
        if ( lOsErr == 108 )
          return 12;
        if ( lOsErr == 111 )
          return 3;
        if ( lOsErr != 112 )
        {
          if ( lOsErr != 113 )
          {
            if ( lOsErr != 114 )
              return 1;
            return 6;
          }
          return 4;
        }
        return 13;
      }
    }
    else
    {
      if ( lOsErr == 107 )
        return 2;
      if ( lOsErr <= 0x47 )
      {
        switch ( lOsErr )
        {
          case 'G':
          case '@':
          case 'A':
            return 5;
          case 'B':
            return 6;
          case 'C':
            return 3;
          default:
            break;
        }
        v3 = lOsErr - 68;
        if ( lOsErr == 68 )
          return 4;
        goto LABEL_40;
      }
      switch ( lOsErr )
      {
        case 'P':
        case 'R':
          return 5;
        case 'U':
          return 3;
        case 'V':
          return 5;
        default:
          break;
      }
      if ( lOsErr != 88 )
        return 1;
    }
    return 10;
  }
  if ( lOsErr == 62 )
    return 8;
  if ( lOsErr > 0x19 )
  {
    if ( lOsErr > 0x27 )
    {
      switch ( lOsErr )
      {
        case '4':
        case '5':
        case '7':
          return 3;
        case '6':
        case ':':
          return 5;
        case '9':
        case ';':
          return 10;
        case '<':
          return 6;
        default:
          return 1;
      }
    }
    if ( lOsErr != 39 )
    {
      if ( lOsErr <= 0x20 )
      {
        if ( lOsErr == 32 )
          return 11;
        if ( lOsErr != 26 )
        {
          if ( lOsErr == 27 )
            return 9;
          v2 = lOsErr - 29;
          if ( lOsErr != 29 )
            goto LABEL_19;
          return 5;
        }
        return 6;
      }
      if ( lOsErr != 33 )
      {
        if ( lOsErr != 34 )
        {
          if ( lOsErr != 36 )
          {
            if ( lOsErr == 38 )
              return 14;
            return 1;
          }
          return 4;
        }
        return 3;
      }
      return 12;
    }
    return 13;
  }
  if ( lOsErr == 25 )
    return 9;
  switch ( lOsErr )
  {
    case 0u:
      result = 0;
      break;
    case 2u:
    case 6u:
    case 0x12u:
      return 2;
    case 3u:
    case 0xFu:
    case 0x11u:
      return 3;
    case 4u:
      return 4;
    case 5u:
    case 0xCu:
    case 0x13u:
      return 5;
    case 0xBu:
      return 6;
    case 0x10u:
      return 7;
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
      return 10;
    case 0x18u:
      return 9;
    default:
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C08B
// Name: public: virtual struct CRuntimeClass __near * CFileException::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFileException::GetRuntimeClass(CFileException *this)
{
  return &CFileException::classCFileException;
}

//------------------------------------------------------------------------------
// Address: 0x0043C091
// Name: public: virtual int CFileException::GetErrorMessage(char __near *,unsigned int,unsigned int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFileException::GetErrorMessage(
        CFileException *this,
        char *lpszError,
        unsigned int nMaxError,
        unsigned __int8 *pnHelpContext)
{
  CAfxStringMgr *StringManager; // eax
  ATL::CStringData *v6; // eax
  char *m_pszData; // esi
  bool v8; // zf
  HINSTANCE__ *StringResourceHandle; // eax
  int v10; // eax
  ATL::CStringData *v12; // [esp-4h] [ebp-24h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFileName; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-4h]

  if ( lpszError == nullptr || nMaxError == 0 )
    return 0;
  if ( pnHelpContext != nullptr )
    *(_DWORD *)pnHelpContext = this->m_cause + 61856;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&pnHelpContext,
    pStringMgr: StringManager);
  v12 = (ATL::CStringData *)(this->m_strFileName.m_pszData - 16);
  v14 = 0;
  v6 = ATL::CSimpleStringT<char,0>::CloneData(pData: v12);
  m_pszData = (char *)&v6[1];
  strFileName.m_pszData = (char *)&v6[1];
  v8 = v6->nDataLength == 0;
  LOBYTE(v14) = 1;
  if ( v8 )
  {
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF006u);
    if ( StringResourceHandle != nullptr )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
        this: &strFileName,
        hInstance: StringResourceHandle,
        nID: 0xF006u);
      m_pszData = strFileName.m_pszData;
    }
  }
  AfxFormatString1(
    rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pnHelpContext,
    nIDS: this->m_cause + 61856,
    lpsz1: m_pszData);
  v10 = _mbsnbcpy_s(_Arg1: (unsigned __int8 *)lpszError, _Arg2: nMaxError, _Arg3: pnHelpContext, _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v10);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)pnHelpContext - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C15E
// Name: void AfxThrowFileException(int,long,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowFileException(int cause, int lOsError, const char *lpszFileName)
{
  CFileException *v3; // ecx
  CFileException *v4; // eax
  CFileException *pExceptionObject; // [esp+14h] [ebp-10h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  v3 = (CFileException *)operator new(nSize: 0x14u);
  v4 = nullptr;
  v6 = 0;
  if ( v3 != nullptr )
    v4 = CFileException::CFileException(this: v3, cause, lOsError, pstrFileName: lpszFileName);
  v6 = -1;
  pExceptionObject = v4;
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI4PAVCFileException__);
}

//------------------------------------------------------------------------------
// Address: 0x0043C1A4
// Name: public: static void CFileException::ThrowOsError(long,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CFileException::ThrowOsError(int lOsError, const char *lpszFileName)
{
  int v2; // eax

  if ( lOsError != 0 )
  {
    v2 = CFileException::OsErrorToException(lOsErr: lOsError);
    AfxThrowFileException(cause: v2, lOsError, lpszFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C1C7
// Name: public: struct __POSITION __near * CStringList::FindIndex(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<unsigned long,unsigned long>::CNode *__thiscall CStringList::FindIndex(
        CList<unsigned long,unsigned long> *this,
        int nIndex)
{
  int v2; // edx
  CList<unsigned long,unsigned long>::CNode *result; // eax

  v2 = nIndex;
  if ( nIndex >= this->m_nCount || nIndex < 0 )
    return nullptr;
  result = this->m_pNodeHead;
  if ( nIndex != 0 )
  {
    do
    {
      --v2;
      result = result->pNext;
    }
    while ( v2 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C1EA
// Name: public: virtual struct CRuntimeClass __near * CStringList::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CStringList::GetRuntimeClass(CStringList *this)
{
  return &CStringList::classCStringList;
}

//------------------------------------------------------------------------------
// Address: 0x0043C1F0
// Name: public: CStringList::CStringList(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList *__thiscall CStringList::CStringList(CStringList *this, int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CStringList_vtbl *)&CStringList::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043C218
// Name: public: static class CObject __near * CStringList::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList *__stdcall CStringList::CreateObject()
{
  CStringList *v0; // eax

  v0 = (CStringList *)operator new(nSize: 0x1Cu);
  if ( v0 != nullptr )
    return CStringList::CStringList(this: v0, nBlockSize: 10);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043C231
// Name: protected: struct CStringList::CNode __near * CStringList::NewNode(struct CStringList::CNode __near *,struct CStringList::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList::CNode *__thiscall CStringList::NewNode(
        CStringList *this,
        CStringList::CNode *pPrev,
        CStringList::CNode *pNext)
{
  CPlex *v4; // eax
  int v5; // ecx
  CStringList::CNode *i; // eax
  CStringList::CNode *m_pNodeFree; // edi
  CAfxStringMgr *StringManager; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v4 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: 0xCu);
    v5 = this->m_nBlockSize - 1;
    for ( i = (CStringList::CNode *)&v4[3 * this->m_nBlockSize - 2]; v5 >= 0; --v5 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i--;
    }
  }
  m_pNodeFree = this->m_pNodeFree;
  this->m_pNodeFree = m_pNodeFree->pNext;
  m_pNodeFree->pPrev = pPrev;
  m_pNodeFree->pNext = pNext;
  ++this->m_nCount;
  if ( m_pNodeFree == (CStringList::CNode *)-8 )
    AfxThrowInvalidArgException();
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &m_pNodeFree->data, pStringMgr: StringManager);
  return m_pNodeFree;
}

//------------------------------------------------------------------------------
// Address: 0x0043C2A2
// Name: public: struct __POSITION __near * CStringList::Find(char const __near *,struct __POSITION __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList::CNode *__thiscall CStringList::Find(CStringList *this, char *searchValue, __POSITION *startAfter)
{
  CStringList::CNode *m_pNodeHead; // esi
  int v4; // eax

  if ( startAfter != nullptr )
    m_pNodeHead = *(CStringList::CNode **)startAfter;
  else
    m_pNodeHead = this->m_pNodeHead;
  while ( 1 )
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &m_pNodeHead->data, psz: searchValue);
    if ( v4 == 0 )
      break;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  return m_pNodeHead;
}

//------------------------------------------------------------------------------
// Address: 0x004E8E7B
// Name: public: virtual struct CRuntimeClass __near * CMFCToolTipCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolTipCtrl::GetRuntimeClass(CMFCToolTipCtrl *this)
{
  return &CMFCToolTipCtrl::classCMFCToolTipCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x004E8E81
// Name: public: virtual class CSize CMFCToolTipCtrl::GetIconSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::GetIconSize(CMFCToolTipCtrl *this, CSize *result)
{
  CMFCRibbonButton *m_pRibbonButton; // ecx
  int v4; // edi
  CMFCRibbonButton *v5; // ecx
  CSize *v6; // eax
  int v7; // edx
  int v8; // ebx
  int *v9; // eax
  CMFCRibbonButton *v10; // ecx
  int v11; // edx
  int *v12; // eax
  CMFCToolBarButton *m_pHotButton; // eax
  CMFCToolBarImages *m_pToolBarImages; // esi
  int m_iUserImage; // eax
  int cx; // ecx
  int cy; // esi
  BOOL v18; // [esp-4h] [ebp-18h]
  CSize v19; // [esp+Ch] [ebp-8h] BYREF

  m_pRibbonButton = this->m_pRibbonButton;
  v4 = 0;
  if ( m_pRibbonButton != nullptr )
  {
    if ( m_pRibbonButton->IsDrawTooltipImage(this: m_pRibbonButton) != 0 )
    {
      v5 = this->m_pRibbonButton;
      if ( v5->m_hIcon != nullptr )
      {
        v18 = v5->m_bIsLargeImage == 0;
        this->m_nRibbonImageType = v18;
        v5->GetImageSize(this: v5, result, a3: (CMFCRibbonBaseElement::RibbonImageType)v18);
        return result;
      }
      v7 = 0;
      v8 = 0;
      if ( v5->m_bIsLargeImage != 0 && v5->m_nLargeImageIndex >= 0 )
      {
        v9 = (int *)v5->GetImageSize(this: v5, result: &v19, a3: RibbonImageLarge);
        v7 = *v9;
        v8 = v9[1];
      }
      if ( v7 != 0 || v8 != 0 )
      {
        this->m_nRibbonImageType = 0;
        result->cx = v7;
        result->cy = v8;
        return result;
      }
      v10 = this->m_pRibbonButton;
      v11 = 0;
      if ( v10->m_nSmallImageIndex >= 0 )
      {
        v12 = (int *)v10->GetImageSize(this: v10, result: &v19, a3: RibbonImageSmall);
        v11 = *v12;
        v4 = v12[1];
      }
      v6 = result;
      this->m_nRibbonImageType = 1;
      result->cx = v11;
      goto LABEL_25;
    }
LABEL_24:
    v6 = result;
    result->cx = 0;
LABEL_25:
    v6->cy = v4;
    return v6;
  }
  m_pHotButton = this->m_pHotButton;
  if ( m_pHotButton == nullptr )
    goto LABEL_24;
  m_pToolBarImages = this->m_pToolBarImages;
  if ( m_pToolBarImages == nullptr || m_pToolBarImages->m_iCount == 0 )
    goto LABEL_24;
  if ( m_pHotButton->m_bUserButton != 0 )
    m_iUserImage = m_pHotButton->m_iUserImage;
  else
    m_iUserImage = m_pHotButton->m_iImage;
  if ( m_iUserImage < 0 )
  {
    cx = 0;
    cy = 0;
  }
  else
  {
    cx = m_pToolBarImages->m_sizeImage.cx;
    cy = m_pToolBarImages->m_sizeImage.cy;
  }
  result->cx = cx;
  result->cy = cy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E8F96
// Name: public: virtual void CMFCToolTipCtrl::OnDrawBorder(class CDC __near *,class CRect,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnDrawBorder(CMFCToolTipCtrl *this, CDC *pDC, CRect rect, unsigned int clrLine)
{
  CPoint result; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_Params.m_bRoundedCorners != 0 )
  {
    CDC::MoveTo(this: pDC, &result, x: rect.left + 2, y: rect.top);
    CDC::LineTo(this: pDC, x: rect.right - 3, y: rect.top);
    CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.top + 2);
    CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.bottom - 3);
    CDC::LineTo(this: pDC, x: rect.right - 3, y: rect.bottom - 1);
    CDC::LineTo(this: pDC, x: rect.left + 2, y: rect.bottom - 1);
    CDC::LineTo(this: pDC, x: rect.left, y: rect.bottom - 3);
    CDC::LineTo(this: pDC, x: rect.left, y: rect.top + 2);
    CDC::LineTo(this: pDC, x: rect.left + 2, y: rect.top);
  }
  else
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: clrLine, clrBottomRight: clrLine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9068
// Name: public: virtual int CMFCToolTipCtrl::OnDrawIcon(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnDrawIcon(CMFCToolTipCtrl *this, CDC *pDC, CRect rectImage)
{
  CMFCRibbonButton *m_pRibbonButton; // eax
  int m_bIsDisabled; // ecx
  CMFCToolBarImages *v7; // ecx
  CMFCToolBarButton *m_pHotButton; // eax
  int m_bText; // ecx
  int v10; // eax
  CMFCToolBarImages *m_pToolBarImages; // [esp-18h] [ebp-44h]
  int m_nRibbonImageType; // [esp-14h] [ebp-40h]
  tagAFXDrawState v13; // [esp+Ch] [ebp-20h] BYREF
  unsigned int nSaveStyle; // [esp+18h] [ebp-14h]
  int bSaveLargeIcons; // [esp+1Ch] [ebp-10h]
  int bSaveImage; // [esp+20h] [ebp-Ch]
  int bSaveText; // [esp+24h] [ebp-8h]
  int bIsDisabled; // [esp+28h] [ebp-4h]

  m_pRibbonButton = this->m_pRibbonButton;
  bIsDisabled = (int)pDC;
  if ( m_pRibbonButton != nullptr )
  {
    m_bIsDisabled = m_pRibbonButton->m_bIsDisabled;
    m_pRibbonButton->m_bIsDisabled = 0;
    m_nRibbonImageType = this->m_nRibbonImageType;
    bIsDisabled = m_bIsDisabled;
    ((void (__thiscall *)(CMFCRibbonButton *, CDC *, int, int, int, int, int))this->m_pRibbonButton->DrawImage)(
      a1: this->m_pRibbonButton,
      a2: pDC,
      a3: m_nRibbonImageType,
      a4: rectImage.left,
      a5: rectImage.top,
      a6: rectImage.right,
      a7: rectImage.bottom);
    this->m_pRibbonButton->m_bIsDisabled = bIsDisabled;
    return 1;
  }
  else if ( this->m_pHotButton != nullptr && (v7 = this->m_pToolBarImages) != nullptr )
  {
    CMFCToolBarImages::PrepareDrawImage(this: v7, ds: &v13, sizeImageDest: 0, bFadeInactive: 0);
    m_pHotButton = this->m_pHotButton;
    nSaveStyle = m_pHotButton->m_nStyle;
    m_bText = m_pHotButton->m_bText;
    bSaveImage = m_pHotButton->m_bImage;
    v10 = CMFCToolBar::m_bLargeIcons;
    CMFCToolBar::m_bLargeIcons = 0;
    bSaveLargeIcons = v10;
    this->m_pHotButton->m_bText = 0;
    this->m_pHotButton->m_bImage = 1;
    this->m_pHotButton->m_nStyle = 0;
    m_pToolBarImages = this->m_pToolBarImages;
    bSaveText = m_bText;
    CMFCToolBarButton::OnDraw(
      this: this->m_pHotButton,
      pDC: (CDC *)bIsDisabled,
      rect: &rectImage,
      pImages: m_pToolBarImages,
      bHorz: 1,
      bCustomizeMode: 0,
      bHighlight: 0,
      bDrawBorder: 1,
      bGrayDisabledButtons: 1);
    this->m_pHotButton->m_nStyle = nSaveStyle;
    this->m_pHotButton->m_bText = bSaveText;
    this->m_pHotButton->m_bImage = bSaveImage;
    CMFCToolBar::m_bLargeIcons = bSaveLargeIcons;
    CMFCToolBarImages::EndDrawImage(this: this->m_pToolBarImages, ds: &v13);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9195
// Name: public: virtual void CMFCToolTipCtrl::OnDrawSeparator(class CDC __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnDrawSeparator(CMFCToolTipCtrl *this, CDC *pDC, int x1, int x2, int y)
{
  CPoint result; // [esp+0h] [ebp-8h] BYREF

  CDC::MoveTo(this: pDC, &result, x: x1, y);
  CDC::LineTo(this: pDC, x: x2, y);
}

//------------------------------------------------------------------------------
// Address: 0x004E91C0
// Name: public: void CMFCToolTipCtrl::SetParams(class CMFCToolTipInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetParams(CMFCToolTipCtrl *this, CMFCToolTipInfo *pParams)
{
  CMFCToolTipInfo paramsDefault; // [esp+4h] [ebp-34h] BYREF

  if ( pParams != nullptr )
  {
    CMFCToolTipInfo::operator=(this: &this->m_Params, src: pParams);
  }
  else
  {
    CMFCToolTipInfo::CMFCToolTipInfo(this: &paramsDefault);
    CMFCToolTipInfo::operator=(this: &this->m_Params, src: &paramsDefault);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E91F2
// Name: public: void CMFCToolTipCtrl::SetLocation(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetLocation(CMFCToolTipCtrl *this, CPoint pt)
{
  this->m_ptLocation = pt;
}

//------------------------------------------------------------------------------
// Address: 0x004E920D
// Name: public: void CMFCToolTipCtrl::SetHotRibbonButton(class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetHotRibbonButton(CMFCToolTipCtrl *this, CMFCRibbonButton *pRibbonButton)
{
  this->m_pRibbonButton = pRibbonButton;
}

//------------------------------------------------------------------------------
// Address: 0x004E921F
// Name: protected: int CMFCToolTipCtrl::GetFixedWidth(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::GetFixedWidth(CMFCToolTipCtrl *this)
{
  long double m_dblRibbonImageScale; // st7

  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  if ( this->m_sizeImage.cx > (int)(m_dblRibbonImageScale * 32.0) )
    return this->m_nFixedWidthWithImage;
  else
    return this->m_nFixedWidthRegular;
}

//------------------------------------------------------------------------------
// Address: 0x004E9258
// Name: protected: int CMFCToolTipCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnCreate(CMFCToolTipCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  CWnd *v4; // eax
  CMFCToolBar *v5; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    v4 = CWnd::FromHandlePermanent(hWnd: lpCreateStruct->hwndParent);
    v5 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v4);
    this->m_pToolBar = v5;
    if ( v5 != nullptr && CObject::IsKindOf(this: v5, pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane) != 0 )
      this->m_pToolBar = nullptr;
    CWnd::ModifyStyle(this, dwRemove: 0x800000u, dwAdd: 0, nFlags: 0);
    if ( this->m_Params.m_bBalloonTooltip != 0 )
      CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x40u, nFlags: 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E92D4
// Name: protected: int CMFCToolTipCtrl::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnEraseBkgnd(CMFCToolTipCtrl *this, CDC *pDC)
{
  unsigned int clrDummy; // [esp+Ch] [ebp-1Ch] BYREF
  CDC *v5; // [esp+10h] [ebp-18h]
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  v5 = pDC;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int *, unsigned int *))this->OnFillBackground)(
    a1: this,
    a2: pDC,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom,
    a7: &clrDummy,
    a8: &clrDummy);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004E933E
// Name: protected: void CMFCToolTipCtrl::GetHotButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::GetHotButton(CMFCToolTipCtrl *this)
{
  int v2; // eax
  CMFCToolBarButton *Button; // eax
  CMFCToolBar *m_pToolBar; // ecx
  CMFCToolBarImages *LockedMenuImages; // eax
  CPoint ptToolBar; // [esp+8h] [ebp-8h] BYREF

  this->m_pHotButton = nullptr;
  this->m_pToolBarImages = nullptr;
  if ( this->m_pRibbonButton == nullptr && this->m_pToolBar != nullptr )
  {
    ptToolBar.x = 0;
    ptToolBar.y = 0;
    GetCursorPos(lpPoint: &ptToolBar);
    ScreenToClient(hWnd: this->m_pToolBar->m_hWnd, lpPoint: &ptToolBar);
    v2 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->m_pToolBar->HitTest)(
           a1: this->m_pToolBar,
           a2: ptToolBar.x,
           a3: ptToolBar.y);
    Button = (CMFCToolBarButton *)CMFCToolBar::GetButton(this: this->m_pToolBar, nIndex: v2);
    this->m_pHotButton = Button;
    if ( Button != nullptr )
    {
      m_pToolBar = this->m_pToolBar;
      if ( m_pToolBar->m_bLocked != 0 )
      {
        LockedMenuImages = CMFCToolBar::GetLockedMenuImages(this: m_pToolBar);
LABEL_8:
        this->m_pToolBarImages = LockedMenuImages;
        return;
      }
      if ( Button->m_bUserButton != 0 )
      {
        LockedMenuImages = CMFCToolBar::m_pUserImages;
        goto LABEL_8;
      }
      this->m_pToolBarImages = &CMFCToolBar::m_MenuImages;
      if ( CMFCToolBar::m_MenuImages.m_iCount <= 0 )
        this->m_pToolBarImages = &CMFCToolBar::m_Images;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9403
// Name: protected: void CMFCToolTipCtrl::OnPop(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnPop(CMFCToolTipCtrl *this, tagNMHDR *__formal, int *pResult)
{
  this->m_pHotButton = nullptr;
  this->m_pToolBarImages = nullptr;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strDescription);
  this->m_ptLocation.x = -1;
  this->m_pRibbonButton = nullptr;
  this->m_nRibbonImageType = 0;
  this->m_ptLocation.y = -1;
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E944D
// Name: public: CMFCToolTipCtrl::CMFCToolTipCtrl(class CMFCToolTipInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipCtrl *__thiscall CMFCToolTipCtrl::CMFCToolTipCtrl(CMFCToolTipCtrl *this, CMFCToolTipInfo *pParams)
{
  CAfxStringMgr *StringManager; // eax

  CToolTipCtrl::CToolTipCtrl(this);
  this->__vftable = (CMFCToolTipCtrl_vtbl *)&CMFCToolTipCtrl::`vftable';
  CMFCToolTipInfo::CMFCToolTipInfo(this: &this->m_Params);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDescription, pStringMgr: StringManager);
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_ptMargin.x = 0;
  this->m_ptMargin.y = 0;
  this->m_ptLocation.x = 0;
  this->m_ptLocation.y = 0;
  CMFCToolTipCtrl::SetParams(this, pParams);
  this->m_sizeImage.cy = 0;
  this->m_ptMargin.y = 0;
  this->m_sizeImage.cx = 0;
  this->m_ptMargin.x = 0;
  this->m_pToolBar = nullptr;
  this->m_pToolBarImages = nullptr;
  this->m_pHotButton = nullptr;
  this->m_pRibbonButton = nullptr;
  this->m_nRibbonImageType = 0;
  this->m_nFixedWidthRegular = 0;
  this->m_nFixedWidthWithImage = 0;
  this->m_ptLocation.x = -1;
  this->m_ptLocation.y = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E950C
// Name: public: virtual CMFCToolTipCtrl::~CMFCToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::~CMFCToolTipCtrl(CMFCToolTipCtrl *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strDescription.m_pszData - 16);
  this->__vftable = (CMFCToolTipCtrl_vtbl *)&CMFCToolTipCtrl::`vftable';
  ATL::CStringData::Release(this: v2);
  CToolTipCtrl::~CToolTipCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E952D
// Name: public: virtual class CSize CMFCToolTipCtrl::OnDrawDescription(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::OnDrawDescription(
        CMFCToolTipCtrl *this,
        CSize *result,
        CDC *pDC,
        CRect rect,
        int bCalcOnly)
{
  int v6; // eax
  int FixedWidth; // eax
  int cx; // ecx
  unsigned int v9; // ecx
  int v10; // ebx
  CFont *pOldFont; // [esp+Ch] [ebp-4h]

  v6 = 0;
  if ( this->m_Params.m_bDrawDescription != 0 )
  {
    pOldFont = pDC->SelectObject(this: pDC, a2: &afxGlobalData.fontTooltip);
    FixedWidth = CMFCToolTipCtrl::GetFixedWidth(this);
    if ( FixedWidth <= 0 || (cx = this->m_sizeImage.cx) > 32 )
    {
      rect.right = rect.left + this->m_Params.m_nMaxDescrWidth;
    }
    else
    {
      rect.right = FixedWidth + rect.left;
      if ( cx > 0 && this->m_Params.m_bDrawIcon != 0 )
        rect.right -= cx + this->m_ptMargin.x;
    }
    v9 = 16;
    if ( bCalcOnly != 0 )
      v9 = 1040;
    v10 = pDC->DrawTextA(
            this: pDC,
            a2: this->m_strDescription.m_pszData,
            a3: *((_DWORD *)this->m_strDescription.m_pszData - 3),
            a4: &rect,
            a5: v9);
    pDC->SelectObject(this: pDC, a2: pOldFont);
    v6 = rect.right - rect.left;
    result->cy = v10;
  }
  else
  {
    result->cy = 0;
  }
  result->cx = v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E95EA
// Name: public: static class CObject __near * CMFCToolTipCtrl::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipCtrl *__stdcall CMFCToolTipCtrl::CreateObject()
{
  CMFCToolTipCtrl *v0; // ecx
  CMFCToolTipCtrl *result; // eax

  v0 = (CMFCToolTipCtrl *)operator new(nSize: 0xFCu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolTipCtrl::CMFCToolTipCtrl(this: v0, pParams: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E963C
// Name: public: virtual class CSize CMFCToolTipCtrl::OnDrawLabel(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::OnDrawLabel(
        CMFCToolTipCtrl *this,
        CSize *result,
        CDC *pDC,
        CRect rect,
        int bCalcOnly)
{
  CAfxStringMgr *StringManager; // eax
  COleDropTarget *m_pDropTarget; // ecx
  CFont *p_fontTooltip; // eax
  unsigned int v8; // edx
  int cy; // eax
  CSize *TextExtent; // eax
  unsigned int v11; // edx
  CFont *pOldFont; // [esp+10h] [ebp-20h]
  CSize v14; // [esp+14h] [ebp-1Ch] BYREF
  CWnd *v15; // [esp+1Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+20h] [ebp-10h] BYREF
  int v17; // [esp+2Ch] [ebp-4h]

  v15 = this;
  result->cx = 0;
  result->cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strText, pStringMgr: StringManager);
  v17 = 0;
  CWnd::GetWindowTextA(this: v15, rString: &strText);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: &strText, pszOld: "\t", pszNew: "    ");
  if ( v15[1].m_xAccessibleServer.__vftable == nullptr
    || (m_pDropTarget = v15[1].m_pDropTarget, v14.cy = 1, m_pDropTarget[-1].m_dwLastTick == 0) )
  {
    v14.cy = 0;
  }
  if ( v15[1].m_ptGestureFrom.x == 0 || (p_fontTooltip = &afxGlobalData.fontBold, v14.cy == 0) )
    p_fontTooltip = &afxGlobalData.fontTooltip;
  pOldFont = pDC->SelectObject(this: pDC, a2: p_fontTooltip);
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &strText, ch: 0xAu, iStart: 0) >= 0 )
  {
    v8 = 2048;
    if ( bCalcOnly != 0 )
      v8 = 3072;
    if ( v15[1].m_pStdObject != nullptr )
      v8 |= 0x800u;
    cy = pDC->DrawTextA(this: pDC, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &rect, a5: v8);
    result->cx = rect.right - rect.left;
    goto LABEL_15;
  }
  if ( bCalcOnly != 0 )
  {
    TextExtent = CDC::GetTextExtent(this: pDC, result: &v14, str: &strText);
    result->cx = TextExtent->cx;
    cy = TextExtent->cy;
LABEL_15:
    result->cy = cy;
    goto LABEL_21;
  }
  v11 = 288;
  if ( v14.cy == 0 )
    v11 = 292;
  if ( v15[1].m_pStdObject != nullptr )
    v11 |= 0x800u;
  result->cy = pDC->DrawTextA(
                 this: pDC,
                 a2: strText.m_pszData,
                 a3: *((_DWORD *)strText.m_pszData - 3),
                 a4: &rect,
                 a5: v11);
  result->cx = rect.right - rect.left;
LABEL_21:
  pDC->SelectObject(this: pDC, a2: pOldFont);
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9790
// Name: protected: void CMFCToolTipCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnPaint(CMFCToolTipCtrl *this)
{
  CDC *p_m_dcMem; // eax
  int y; // eax
  unsigned int m_clrBorder; // eax
  unsigned int m_clrText; // eax
  int v6; // eax
  CDC *v7; // esi
  int v8; // ecx
  HWND__ *v9; // [esp-10h] [ebp-128h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-120h]
  int v11; // [esp+10h] [ebp-108h]
  int v12; // [esp+14h] [ebp-104h]
  int right; // [esp+18h] [ebp-100h]
  int v14; // [esp+1Ch] [ebp-FCh]
  CFont *pFont; // [esp+20h] [ebp-F8h]
  CPen v16; // [esp+24h] [ebp-F4h] BYREF
  int left; // [esp+2Ch] [ebp-ECh]
  int top; // [esp+30h] [ebp-E8h]
  int v19; // [esp+34h] [ebp-E4h] BYREF
  int bottom; // [esp+38h] [ebp-E0h]
  unsigned int v21; // [esp+3Ch] [ebp-DCh] BYREF
  unsigned int crColor; // [esp+40h] [ebp-D8h] BYREF
  CDC *v23; // [esp+44h] [ebp-D4h]
  tagRECT rc; // [esp+48h] [ebp-D0h] BYREF
  CPaintDC v25; // [esp+58h] [ebp-C0h] BYREF
  CMemDC v26; // [esp+ACh] [ebp-6Ch] BYREF
  LPARAM lParam; // [esp+E8h] [ebp-30h] BYREF
  int v28; // [esp+ECh] [ebp-2Ch]
  int v29; // [esp+F0h] [ebp-28h]
  int v30; // [esp+F4h] [ebp-24h]
  tagRECT Rect; // [esp+F8h] [ebp-20h] BYREF
  int v32; // [esp+114h] [ebp-4h]

  if ( this->m_Params.m_bBalloonTooltip != 0 )
  {
    CWnd::OnPaint(this);
  }
  else
  {
    CPaintDC::CPaintDC(this: &v25, pWnd: this);
    v32 = 0;
    CMemDC::CMemDC(this: &v26, dc: &v25, pWnd: (HDC__ *)this);
    LOBYTE(v32) = 1;
    p_m_dcMem = &v26.m_dcMem;
    if ( v26.m_bMemDC == 0 )
      p_m_dcMem = v26.m_dc;
    v23 = p_m_dcMem;
    m_hWnd = this->m_hWnd;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    v9 = this->m_hWnd;
    lParam = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    SendMessageA(hWnd: v9, Msg: 0x41Bu, wParam: 0, (LPARAM)&lParam);
    rc.left = Rect.left;
    rc.top = v28 + Rect.top;
    rc.right = Rect.right - v29;
    rc.bottom = Rect.bottom - v30;
    y = this->m_ptMargin.y;
    rc.left = lParam + Rect.left;
    InflateRect(lprc: &rc, dx: -this->m_ptMargin.x, dy: -y);
    m_clrBorder = this->m_Params.m_clrBorder;
    if ( m_clrBorder == -1 )
      m_clrBorder = GetSysColor(nIndex: 23);
    crColor = m_clrBorder;
    m_clrText = this->m_Params.m_clrText;
    if ( m_clrText == -1 )
      m_clrText = GetSysColor(nIndex: 23);
    v21 = m_clrText;
    ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int *, unsigned int *))this->OnFillBackground)(
      a1: this,
      a2: v23,
      a3: Rect.left,
      a4: Rect.top,
      a5: Rect.right,
      a6: Rect.bottom,
      a7: &v21,
      a8: &crColor);
    CPen::CPen(this: &v16, nPenStyle: 0, nWidth: 1, crColor);
    LOBYTE(v32) = 2;
    pFont = CDC::SelectObject(this: v23, pFont: (CFont *)&v16);
    ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int))this->OnDrawBorder)(
      a1: this,
      a2: v23,
      a3: Rect.left,
      a4: Rect.top,
      a5: Rect.right,
      a6: Rect.bottom,
      a7: crColor);
    if ( CPoint::operator!=(this: &this->m_sizeImage, size: 0) && this->m_Params.m_bDrawIcon != 0 )
    {
      v6 = rc.left + this->m_sizeImage.cx;
      left = rc.left;
      top = rc.top;
      bottom = rc.bottom;
      v19 = v6;
      bottom = rc.top + this->m_sizeImage.cy;
      ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int))this->OnDrawIcon)(
        a1: this,
        a2: v23,
        a3: rc.left,
        a4: rc.top,
        a5: v6,
        a6: bottom);
      rc.left += this->m_sizeImage.cx + this->m_ptMargin.x;
    }
    v7 = v23;
    CDC::SetBkMode(this: v23, nBkMode: 1);
    v7->SetTextColor(this: v7, a2: v21);
    v8 = *(_DWORD *)(((int (__thiscall *)(CMFCToolTipCtrl *, int *, CDC *, int, int, int, int, _DWORD))this->OnDrawLabel)(
                       a1: this,
                       a2: &v19,
                       a3: v23,
                       a4: rc.left,
                       a5: rc.top,
                       a6: rc.right,
                       a7: rc.bottom,
                       a8: 0)
                   + 4);
    if ( *((_DWORD *)this->m_strDescription.m_pszData - 3) != 0 && this->m_Params.m_bDrawDescription != 0 )
    {
      v11 = rc.left;
      right = rc.right;
      v14 = rc.bottom;
      v12 = v8 + rc.top + 3 * this->m_ptMargin.y / 2;
      if ( this->m_Params.m_bDrawSeparator != 0 )
        this->OnDrawSeparator(
          this,
          a2: v23,
          a3: rc.left,
          a4: rc.right,
          a5: v8 + rc.top + 3 * this->m_ptMargin.y / 2 - this->m_ptMargin.y / 2);
      ((void (__thiscall *)(CMFCToolTipCtrl *, int *, CDC *, int, int, int, int, _DWORD))this->OnDrawDescription)(
        a1: this,
        a2: &v19,
        a3: v23,
        a4: v11,
        a5: v12,
        a6: right,
        a7: v14,
        a8: 0);
    }
    CDC::SelectObject(this: v23, pFont);
    LOBYTE(v32) = 1;
    v16.__vftable = (CPen_vtbl *)&CPen::`vftable';
    CGdiObject::~CGdiObject(this: &v16);
    LOBYTE(v32) = 0;
    CMemDC::~CMemDC(this: &v26);
    v32 = -1;
    CPaintDC::~CPaintDC(this: &v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9ADA
// Name: protected: void CMFCToolTipCtrl::OnShow(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnShow(CMFCToolTipCtrl *this, tagNMHDR *__formal, int *pResult)
{
  CMFCVisualManager *Instance; // eax
  CSize *v5; // eax
  int v6; // ecx
  CMFCToolTipCtrl_vtbl *v7; // eax
  int v8; // edi
  int *v9; // eax
  int v10; // ecx
  int v11; // eax
  bool v12; // cc
  int cx; // eax
  int FixedWidth; // eax
  int top; // edi
  HMONITOR v16; // eax
  int SystemMetrics; // eax
  int y; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND v23; // eax
  _DWORD *m_hObject; // ecx
  int right; // eax
  HRGN RoundRectRgn; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-E4h]
  HWND__ *v28; // [esp-8h] [ebp-DCh]
  HWND__ *v29; // [esp-8h] [ebp-DCh]
  CClientDC v30; // [esp+10h] [ebp-C4h] BYREF
  int v31; // [esp+24h] [ebp-B0h] BYREF
  int v32; // [esp+28h] [ebp-ACh]
  tagPOINT Point; // [esp+2Ch] [ebp-A8h] BYREF
  CGdiObject v34; // [esp+34h] [ebp-A0h] BYREF
  int v35; // [esp+3Ch] [ebp-98h] BYREF
  int left; // [esp+40h] [ebp-94h]
  int cy; // [esp+44h] [ebp-90h]
  int v38; // [esp+48h] [ebp-8Ch]
  tagRECT Rect; // [esp+4Ch] [ebp-88h] BYREF
  tagMONITORINFO mi; // [esp+5Ch] [ebp-78h] BYREF
  LPARAM lParam[4]; // [esp+84h] [ebp-50h] BYREF
  tagRECT v42; // [esp+94h] [ebp-40h] BYREF
  tagRECT rcDst; // [esp+A4h] [ebp-30h] BYREF
  tagRECT v44; // [esp+B4h] [ebp-20h] BYREF
  int v45; // [esp+D0h] [ebp-4h]

  *pResult = 0;
  v34.m_hObject = pResult;
  if ( this->m_Params.m_bVislManagerTheme != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    Instance->GetToolTipInfo(this: Instance, a2: &this->m_Params, a3: -1u);
    this->m_Params.m_bVislManagerTheme = 1;
  }
  if ( this->m_Params.m_bBalloonTooltip == 0 )
  {
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    CMFCToolTipCtrl::GetHotButton(this);
    if ( this->m_Params.m_bDrawIcon != 0 )
    {
      v5 = this->GetIconSize(this, result: &v35);
    }
    else
    {
      v35 = 0;
      left = 0;
      v5 = (CSize *)&v35;
    }
    this->m_sizeImage.cx = v5->cx;
    this->m_sizeImage.cy = v5->cy;
    if ( this->m_Params.m_bRoundedCorners != 0 )
    {
      v35 = 6;
      left = 4;
    }
    else
    {
      v35 = 4;
      left = 2;
    }
    v6 = v35;
    this->m_ptMargin.y = left;
    m_hWnd = this->m_hWnd;
    this->m_ptMargin.x = v6;
    memset(lParam, 0, sizeof(lParam));
    SendMessageA(hWnd: m_hWnd, Msg: 0x41Bu, wParam: 0, (LPARAM)lParam);
    v28 = this->m_hWnd;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: v28, lpRect: &Rect);
    CClientDC::CClientDC(this: &v30, pWnd: this);
    v7 = this->__vftable;
    v45 = 0;
    ((void (__thiscall *)(CMFCToolTipCtrl *, int *, CClientDC *, int, int, int, int, int))v7->OnDrawLabel)(
      a1: this,
      a2: &v31,
      a3: &v30,
      a4: Rect.left,
      a5: Rect.top,
      a6: Rect.right,
      a7: Rect.bottom,
      a8: 1);
    v8 = 0;
    v38 = v31;
    cy = v32;
    v35 = 0;
    if ( this->m_Params.m_bDrawDescription != 0 && *((_DWORD *)this->m_strDescription.m_pszData - 3) != 0 )
    {
      v9 = (int *)((int (__thiscall *)(CMFCToolTipCtrl *, int *, CClientDC *, int, int, int, int, int))this->OnDrawDescription)(
                    a1: this,
                    a2: &v42.right,
                    a3: &v30,
                    a4: Rect.left,
                    a5: Rect.top,
                    a6: Rect.right,
                    a7: Rect.bottom,
                    a8: 1);
      v10 = *v9;
      v8 = v9[1];
      cy += v8 + 2 * this->m_ptMargin.y;
      v35 = v10;
      if ( v38 <= v10 )
        v38 = v10;
      v11 = this->m_sizeImage.cy;
      v12 = cy <= v11;
    }
    else
    {
      v11 = this->m_sizeImage.cy;
      v12 = v32 <= v11;
    }
    if ( v12 )
      cy = v11;
    cx = this->m_sizeImage.cx;
    if ( cx > 0 && this->m_Params.m_bDrawIcon != 0 )
      v38 += cx + this->m_ptMargin.x;
    v38 += 2 * this->m_ptMargin.x;
    cy += 2 * this->m_ptMargin.y;
    FixedWidth = CMFCToolTipCtrl::GetFixedWidth(this);
    if ( FixedWidth > 0 && (v35 != 0 || v8 != 0) && v38 <= FixedWidth )
      v38 = FixedWidth;
    v29 = this->m_hWnd;
    memset((void *)&v44, 0, sizeof(v44));
    GetWindowRect(hWnd: v29, lpRect: &v44);
    top = v44.top;
    left = v44.left;
    if ( CPoint::operator!=(this: (CSize *)&this->m_ptLocation, size: (tagSIZE)-1LL) )
    {
      top = this->m_ptLocation.y;
      left = this->m_ptLocation.x;
      *(_DWORD *)v34.m_hObject = 1;
    }
    memset((void *)&rcDst, 0, sizeof(rcDst));
    mi.cbSize = 40;
    v16 = MonitorFromPoint(pt: *(POINT *)&v44.left, dwFlags: 2u);
    if ( GetMonitorInfoA(hMonitor: v16, lpmi: &mi) )
      CopyRect(lprcDst: &rcDst, lprcSrc: &mi.rcWork);
    else
      SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: (PVOID)&rcDst, fWinIni: 0);
    SystemMetrics = GetSystemMetrics(nIndex: 14);
    y = Point.y;
    v19 = cy + Point.y + SystemMetrics;
    v20 = top + cy + 2;
    if ( v19 > v20 )
    {
      v21 = GetSystemMetrics(nIndex: 14);
      y = Point.y;
      v20 = cy + Point.y + v21;
    }
    if ( v20 <= rcDst.bottom )
    {
      m_hObject = v34.m_hObject;
    }
    else
    {
      top = y - cy - 1;
      if ( this->m_pRibbonButton != nullptr
        && CPoint::operator!=(this: (CSize *)&this->m_ptLocation, size: (tagSIZE)-1LL) )
      {
        TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this: this->m_pRibbonButton);
        if ( TopLevelRibbonBar != nullptr )
        {
          v23 = TopLevelRibbonBar->m_hWnd;
          if ( v23 != nullptr )
          {
            memset((void *)&v42, 0, sizeof(v42));
            GetWindowRect(hWnd: v23, lpRect: &v42);
            top = v42.top - cy;
          }
        }
      }
      m_hObject = v34.m_hObject;
      *(_DWORD *)v34.m_hObject = 1;
    }
    right = rcDst.right;
    if ( left + v38 + 2 > rcDst.right )
    {
      if ( *m_hObject == 1 )
        right = Point.x;
      else
        *m_hObject = 1;
      left = right - v38 - 1;
    }
    if ( *m_hObject == 1 )
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: left, y: top, cx: v38, cy, nFlags: 0x14u);
    else
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: v38, cy, nFlags: 0x16u);
    if ( this->m_Params.m_bRoundedCorners != 0 )
    {
      v34.m_hObject = nullptr;
      v34.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      LOBYTE(v45) = 1;
      RoundRectRgn = CreateRoundRectRgn(x1: 0, y1: 0, x2: v38 + 1, y2: cy + 1, w: 4, h: 4);
      CGdiObject::Attach(this: &v34, hObject: RoundRectRgn);
      SetWindowRgn(hWnd: this->m_hWnd, hRgn: (HRGN)v34.m_hObject, bRedraw: false);
      LOBYTE(v45) = 0;
      v34.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      CGdiObject::~CGdiObject(this: &v34);
    }
    v45 = -1;
    CClientDC::~CClientDC(this: &v30);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9FA2
// Name: public: virtual void CMFCToolTipCtrl::OnFillBackground(class CDC __near *,class CRect,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnFillBackground(
        CMFCToolTipCtrl *this,
        CDC *pDC,
        CRect rect,
        unsigned int *__formal,
        unsigned int *a5)
{
  HDC__ *m_hDC; // edi
  HBRUSH SysColorBrush; // eax
  int m_nGradientAngle; // eax
  CDrawingManager dm; // [esp+10h] [ebp-1Ch] BYREF
  CBrush br; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  m_hDC = (HDC__ *)pDC;
  if ( this->m_Params.m_clrFill == -1 )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    SysColorBrush = GetSysColorBrush(nIndex: 24);
    FillRect(hDC: m_hDC, lprc: &rect, hbr: SysColorBrush);
  }
  else if ( this->m_Params.m_clrFillGradient == -1 )
  {
    CBrush::CBrush(this: &br, crColor: this->m_Params.m_clrFill);
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)br.m_hObject);
    br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &br);
  }
  else
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    m_nGradientAngle = this->m_Params.m_nGradientAngle;
    v11 = 0;
    if ( m_nGradientAngle == -1 )
      m_nGradientAngle = 90;
    CDrawingManager::FillGradient2(
      this: &dm,
      rect,
      colorStart: this->m_Params.m_clrFillGradient,
      colorFinish: this->m_Params.m_clrFill,
      nAngle: m_nGradientAngle);
    v11 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA05E
// Name: public: virtual void CMFCToolTipCtrl::SetDescription(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetDescription(
        CMFCToolTipCtrl *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDescription)
{
  CMFCToolTipCtrl::GetHotButton(this);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strDescription, strSrc: (ATL::CStringData *)&strDescription);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
    this: &this->m_strDescription,
    pszOld: "\t",
    pszNew: "    ");
  ATL::CStringData::Release(this: (ATL::CStringData *)strDescription.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x004EA0AC
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolTipCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolTipCtrl::GetMessageMap(CMFCToolTipCtrl *this)
{
  return (const AFX_MSGMAP *)&off_548218;
}

//------------------------------------------------------------------------------
// Address: 0x004EA0B2
// Name: private: static long CThemeHelper::GetThemePartSizeFail(void __near *,struct HDC__ __near *,int,int,struct tagRECT __near *,enum THEMESIZE,struct tagSIZE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::GetThemePartSizeFail()
{
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x004EA0B8
// Name: private: static void __near * CThemeHelper::GetProc(char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FARPROC __cdecl CThemeHelper::GetProc(const char *szProc, void *pfnFail)
{
  FARPROC ProcAddress; // eax

  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    hThemeDll = AfxCtxLoadLibraryW(lpLibFileName: L"UxTheme.dll");
  }
  if ( hThemeDll != nullptr )
  {
    ProcAddress = GetProcAddress(hModule: hThemeDll, lpProcName: szProc);
    if ( ProcAddress != nullptr )
      return ProcAddress;
  }
  return (FARPROC)pfnFail;
}

//------------------------------------------------------------------------------
// Address: 0x004EA10C
// Name: public: static int CThemeHelper::IsAppThemed(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CThemeHelper::IsAppThemed()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    pfnIsAppThemed = CThemeHelper::GetProc(szProc: "IsAppThemed", pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnIsAppThemed();
}

//------------------------------------------------------------------------------
// Address: 0x004EA152
// Name: public: static void __near * CThemeHelper::OpenThemeData(struct HWND__ __near *,wchar_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl CThemeHelper::OpenThemeData(HWND__ *hwnd, const wchar_t *pszClassList)
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    pfnOpenThemeData = (void *(__stdcall *)(HWND__ *, const wchar_t *))CThemeHelper::GetProc(
                                                                         szProc: "OpenThemeData",
                                                                         pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnOpenThemeData(a1: hwnd, a2: pszClassList);
}

//------------------------------------------------------------------------------
// Address: 0x004EA19E
// Name: public: static long CThemeHelper::CloseThemeData(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::CloseThemeData(void *hTheme)
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    pfnCloseThemeData = (HRESULT (__stdcall *)(void *))CThemeHelper::GetProc(
                                                         szProc: "CloseThemeData",
                                                         pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnCloseThemeData(a1: hTheme);
}

//------------------------------------------------------------------------------
// Address: 0x004EA1E7
// Name: public: static long CThemeHelper::DrawThemeBackground(void __near *,struct HDC__ __near *,int,int,struct tagRECT const __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::DrawThemeBackground(
        void *hTheme,
        HDC__ *hdc,
        int nPartId,
        int nStateId,
        const tagRECT *pRect,
        const tagRECT *pClipRect)
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    pfnDrawThemeBackground = (HRESULT (__stdcall *)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *))CThemeHelper::GetProc(szProc: "DrawThemeBackground", pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnDrawThemeBackground(a1: hTheme, a2: hdc, a3: nPartId, a4: nStateId, a5: pRect, a6: pClipRect);
}

//------------------------------------------------------------------------------
// Address: 0x004EA23F
// Name: public: static long CThemeHelper::GetThemePartSize(void __near *,struct HDC__ __near *,int,int,struct tagRECT __near *,enum THEMESIZE,struct tagSIZE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::GetThemePartSize(
        void *hTheme,
        HDC__ *hdc,
        int nPartId,
        int nStateId,
        tagRECT *pRect,
        THEMESIZE eSize,
        tagSIZE *psz)
{
  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    pfnGetThemePartSize = (HRESULT (__stdcall *)(void *, HDC__ *, int, int, tagRECT *, THEMESIZE, tagSIZE *))CThemeHelper::GetProc(szProc: "GetThemePartSize", pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnGetThemePartSize(a1: hTheme, a2: hdc, a3: nPartId, a4: nStateId, a5: pRect, a6: eSize, a7: psz);
}

//------------------------------------------------------------------------------
// Address: 0x004EA29A
// Name: public: static int CThemeHelper::IsThemeBackgroundPartiallyTransparent(void __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CThemeHelper::IsThemeBackgroundPartiallyTransparent(void *hTheme, int nPartId, int nStateId)
{
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    pfnIsThemeBackgroundPartiallyTransparent = (int (__stdcall *)(void *, int, int))CThemeHelper::GetProc(
                                                                                      szProc: "IsThemeBackgroundPartiallyTransparent",
                                                                                      pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnIsThemeBackgroundPartiallyTransparent(a1: hTheme, a2: nPartId, a3: nStateId);
}

//------------------------------------------------------------------------------
// Address: 0x004EA2E9
// Name: public: static long CThemeHelper::DrawThemeParentBackground(struct HWND__ __near *,struct HDC__ __near *,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::DrawThemeParentBackground(HWND__ *hwnd, HDC__ *hdc, tagRECT *prc)
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    pfnDrawThemeParentBackground = (HRESULT (__stdcall *)(HWND__ *, HDC__ *, tagRECT *))CThemeHelper::GetProc(
                                                                                          szProc: "DrawThemeParentBackground",
                                                                                          pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnDrawThemeParentBackground(a1: hwnd, a2: hdc, a3: prc);
}

//------------------------------------------------------------------------------
// Address: 0x004EA338
// Name: unsigned int AfxPropPageCallback(struct HWND__ __near *,unsigned int,struct _PROPSHEETPAGEA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall AfxPropPageCallback(HWND__ *__formal, unsigned int message, _PROPSHEETPAGEA *pPropPage)
{
  if ( message == 1 )
  {
    AfxUnhookWindowCreate();
  }
  else if ( message == 2 )
  {
    AfxHookWindowCreate(pWnd: (CWnd *)pPropPage->lParam);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EA377
// Name: protected: void CPropertyPage::AllocPSP(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::AllocPSP(CPropertyPage *this, unsigned int dwSize)
{
  unsigned int v2; // edi
  _PROPSHEETPAGEA *v4; // eax

  v2 = dwSize;
  if ( dwSize == 0 )
    v2 = 56;
  v4 = (_PROPSHEETPAGEA *)malloc(size: v2);
  this->m_pPSP = v4;
  if ( v4 == nullptr )
    AfxThrowMemoryException();
  memset(dst: (int)v4, value: nullptr, count: v2);
  this->m_pPSP->dwSize = v2;
}

//------------------------------------------------------------------------------
// Address: 0x004EA3BA
// Name: protected: void CPropertyPage::Cleanup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::Cleanup(CPropertyPage *this)
{
  COccManager *m_pOccManager; // eax

  m_pOccManager = AfxGetModuleState()->m_pOccManager;
  if ( m_pOccManager != nullptr && this->m_pOccDialogInfo != nullptr )
  {
    m_pOccManager->PostCreateDialog(this: m_pOccManager, a2: this->m_pOccDialogInfo);
    free(pBlock: this->m_pOccDialogInfo);
    this->m_pOccDialogInfo = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EA3F2
// Name: protected: struct DLGTEMPLATE const __near * CPropertyPage::InitDialogInfo(struct DLGTEMPLATE const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const DLGTEMPLATE *__thiscall CPropertyPage::InitDialogInfo(CPropertyPage *this, const DLGTEMPLATE *pTemplate)
{
  AFX_MODULE_STATE *ModuleState; // eax

  CPropertyPage::Cleanup(this);
  this->m_pOccDialogInfo = (_AFX_OCC_DIALOG_INFO *)malloc(size: 0x10u);
  ModuleState = AfxGetModuleState();
  return ModuleState->m_pOccManager->PreCreateDialog(
           this: ModuleState->m_pOccManager,
           a2: this->m_pOccDialogInfo,
           a3: pTemplate);
}

//------------------------------------------------------------------------------
// Address: 0x004EA42A
// Name: public: virtual int CPropertyPage::OnApply(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnApply(CPropertyPage *this)
{
  this->OnOK(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA436
// Name: public: virtual void CPropertyPage::OnReset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPropertyPage::OnReset(CPropertyPage *this)
{
  this->OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA43E
// Name: public: virtual int CPropertyPage::OnSetActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnSetActive(CPropertyPage *this)
{
  if ( this->m_bFirstSetActive != 0 )
    this->m_bFirstSetActive = 0;
  else
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA45A
// Name: public: virtual int CPropertyPage::OnKillActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPropertyPage::OnKillActive(CPropertyPage *this)
{
  return CWnd::UpdateData(this, bSaveAndValidate: 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EA468
// Name: public: virtual struct HWND__ __near * CPropertyPage::OnWizardFinishEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__thiscall CPropertyPage::OnWizardFinishEx(CPropertyPage *this)
{
  return (HWND__ *)(this->OnWizardFinish(this) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EA476
// Name: protected: virtual int CPropertyPage::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::PreTranslateMessage(CPropertyPage *this, tagMSG *pMsg)
{
  CWnd::PreTranslateMessage(this, pMsg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EA489
// Name: protected: struct HBRUSH__ __near * CPropertyPage::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CPropertyPage::OnCtlColor(CPropertyPage *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  int lResult; // [esp+4h] [ebp-4h] BYREF

  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: &lResult) != 0 )
    return (CWnd *)lResult;
  else
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
}

//------------------------------------------------------------------------------
// Address: 0x004EA4BC
// Name: int AfxPropSheetCallback(struct HWND__ __near *,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxPropSheetCallback(HWND__ *__formal, unsigned int message, unsigned int *lParam)
{
  _AFX_THREAD_STATE *ThreadState; // eax
  unsigned int *v5; // edi
  _AFX_THREAD_STATE *v6; // esi
  unsigned int m_dwPropStyle; // eax
  unsigned int v8; // eax

  if ( message != 2 )
    return 0;
  ThreadState = AfxGetThreadState();
  v5 = lParam;
  v6 = ThreadState;
  if ( *lParam == ThreadState->m_dwPropStyle && lParam[1] == ThreadState->m_dwPropExStyle )
    return 0;
  VirtualProtect(lpAddress: lParam, dwSize: 0x12u, flNewProtect: 4u, lpflOldProtect: &message);
  m_dwPropStyle = v6->m_dwPropStyle;
  if ( (*(_BYTE *)v5 & 0x40) != 0 )
    v8 = m_dwPropStyle | 0x40;
  else
    v8 = m_dwPropStyle & 0xFFFFFFBF;
  *v5 = v8;
  v5[1] = v6->m_dwPropExStyle;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA51B
// Name: protected: void CPropertySheet::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::OnClose(CPropertySheet *this)
{
  bool v1; // zf

  v1 = this->m_bModeless == 0;
  this->m_nModalResult = 2;
  if ( v1 )
    CWnd::Default(this);
  else
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x471u, wParam: 5u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EA543
// Name: protected: int CPropertySheet::OnNcCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnNcCreate(CPropertySheet *this, tagCREATESTRUCTA *__formal)
{
  CWnd::ModifyStyleEx(this, dwRemove: 0x400u, dwAdd: 0, nFlags: 0);
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA561
// Name: protected: long CPropertySheet::HandleInitDialog(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::HandleInitDialog(CPropertySheet *this, unsigned int __formal, unsigned int __formala)
{
  return this->OnInitDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA56C
// Name: public: virtual int CPropertySheet::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnCommand(CPropertySheet *this, unsigned int wParam, HWND__ *lParam)
{
  unsigned int v4; // eax

  if ( CWnd::OnCommand(this, wParam, lParam) != 0 )
    return 1;
  if ( lParam != nullptr
    && HIWORD(wParam) == 0
    && (SendMessageA(hWnd: lParam, Msg: 0x87u, wParam: 0, lParam: 0) & 0x2010) != 0 )
  {
    v4 = GetWindowLongA(hWnd: lParam, nIndex: -16) & 0xF;
    if ( v4 < 2 || v4 == 8 || v4 == 11 )
      this->m_nModalResult = (unsigned __int16)wParam;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EA5E0
// Name: protected: struct HBRUSH__ __near * CPropertySheet::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CPropertySheet::OnCtlColor(CPropertySheet *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  int lResult; // [esp+4h] [ebp-4h] BYREF

  if ( pWnd == nullptr )
    AfxThrowInvalidArgException();
  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: &lResult) != 0 )
    return (CWnd *)lResult;
  else
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
}

//------------------------------------------------------------------------------
// Address: 0x004EA61E
// Name: public: virtual struct CRuntimeClass __near * CPropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPropertyPage::GetRuntimeClass(CPropertyPage *this)
{
  return &CPropertyPage::classCPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x004EA624
// Name: public: virtual struct CRuntimeClass __near * CPropertySheet::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPropertySheet::GetRuntimeClass(CPropertySheet *this)
{
  return &CPropertySheet::classCPropertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x004EA62A
// Name: public: class CPropertyPage __near * CPropertySheet::GetPage(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPropertyPage *__thiscall CPropertySheet::GetPage(CPropertySheet *this, int nPage)
{
  CPropertyPage *result; // eax

  if ( nPage < 0
    || nPage >= this->m_pages.m_nSize
    || (result = (CPropertyPage *)this->m_pages.m_pData[nPage]) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EA654
// Name: public: class CTabCtrl __near * CPropertySheet::GetTabControl(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTabCtrl *__thiscall CPropertySheet::GetTabControl(CPropertySheet *this)
{
  HWND__ *v1; // eax

  v1 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x474u, wParam: 0, lParam: 0);
  return (CTabCtrl *)CWnd::FromHandle(hWnd: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004EA66D
// Name: public: virtual int CPropertyPage::OnWizardFinish(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPropertyPage::OnWizardFinish(CPropertyPage *this)
{
  int v2; // edi
  HWND Parent; // eax
  CWnd *v4; // eax
  CObject *v5; // eax

  v2 = 0;
  if ( CWnd::UpdateData(this, bSaveAndValidate: 1) != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    v5 = AfxDynamicDownCast(pClass: &CPropertySheet::classCPropertySheet, pObject: v4);
    if ( v5 != nullptr && v5[50].__vftable != nullptr && ((int)v5[30].__vftable & 0x1000020) != 0 )
      PostMessageA(hWnd: (HWND)v5[8].__vftable, Msg: 0, wParam: 0, lParam: 0);
    return 1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004EA6C5
// Name: protected: long CPropertyPage::MapWizardResult(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__thiscall CPropertyPage::MapWizardResult(CPropertyPage *this, const char *lToMap)
{
  const char *result; // eax
  int v3; // ebx
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // eax
  CPropertySheet *v7; // esi
  CObject_vtbl *v8; // edi

  result = lToMap;
  if ( lToMap != (const char *)-1 )
  {
    v3 = 0;
    if ( lToMap != nullptr )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      v5 = CWnd::FromHandle(hWnd: Parent);
      v6 = AfxDynamicDownCast(pClass: &CPropertySheet::classCPropertySheet, pObject: v5);
      v7 = (CPropertySheet *)v6;
      if ( v6 != nullptr && (v8 = v6[37].__vftable, (int)v6[44].__vftable > 0) )
      {
        while ( CPropertySheet::GetPage(this: v7, nPage: v3)->m_pPSP->pszTemplate != lToMap )
        {
          v8 = (CObject_vtbl *)((char *)v8 + (unsigned int)v8->GetRuntimeClass);
          if ( ++v3 >= v7->m_pages.m_nSize )
            return lToMap;
        }
        return (const char *)v8[1].GetRuntimeClass;
      }
      else
      {
        return lToMap;
      }
    }
  }
  return result;
}
