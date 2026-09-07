// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vsoundedit/vsoundedit.cpp
// Functions: 100
// ============================================================

#include "utils\vsoundedit\vsoundedit.h"

//------------------------------------------------------------------------------
// Address: 0x00402160
// Name: public: void ATL::CSimpleStringT<char,0>::Append(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Append(ATL::CSimpleStringT<char,0> *this, char *pszSrc, int nLength)
{
  signed int v4; // edi
  unsigned int v5; // ebx
  int v6; // edi
  char *m_pszData; // eax
  unsigned __int8 *v8; // ecx
  unsigned int nOldLength; // [esp+8h] [ebp-8h]
  unsigned int nOffset; // [esp+Ch] [ebp-4h]

  v4 = *((_DWORD *)this->m_pszData - 3);
  nOffset = pszSrc - this->m_pszData;
  nOldLength = v4;
  if ( nLength < 0 )
    goto LABEL_2;
  if ( pszSrc != nullptr )
    v5 = strnlen(str: pszSrc, maxsize: nLength);
  else
    v5 = 0;
  if ( (int)(0x7FFFFFFF - v5) < v4 )
    ATL::AtlThrowImpl(hr: -2147024809);
  v6 = v5 + v4;
  if ( v6 < 0 )
    ATL::AtlThrowImpl(hr: -2147024809);
  if ( ((*((_DWORD *)this->m_pszData - 2) - v6) | (1 - *((_DWORD *)this->m_pszData - 1))) < 0 )
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this, nLength: v6);
  m_pszData = this->m_pszData;
  v8 = (unsigned __int8 *)(nOffset > nOldLength ? pszSrc : &m_pszData[nOffset]);
  memcpy_s(dst: (unsigned __int8 *)&m_pszData[nOldLength], sizeInBytes: v5, src: v8, count: v5);
  if ( v6 > *((_DWORD *)this->m_pszData - 2) )
LABEL_2:
    ATL::AtlThrowImpl(hr: -2147024809);
  *((_DWORD *)this->m_pszData - 3) = v6;
  this->m_pszData[v6] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406550
// Name: public: virtual int CWinApp::SupportsRestartManager(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsRestartManager(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406560
// Name: public: virtual int CWinApp::SupportsApplicationRecovery(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsApplicationRecovery(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00406570
// Name: public: virtual int CWinApp::SupportsAutosaveAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00406580
// Name: public: virtual int CWinApp::SupportsAutosaveAtInterval(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtInterval(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00406590
// Name: public: virtual int CWinApp::ReopenPreviousFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ReopenPreviousFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004065A0
// Name: public: virtual int CWinApp::RestoreAutosavedFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::RestoreAutosavedFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x004065B0
// Name: public: virtual unsigned long CWinApp::GetApplicationRestartFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetApplicationRestartFlags(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004065C0
// Name: public: virtual unsigned long CWinApp::GetApplicationRecoveryPingInterval(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::GetApplicationRecoveryPingInterval(CWinApp *this)
{
  return 5000;
}

//------------------------------------------------------------------------------
// Address: 0x004065D0
// Name: protected: virtual struct AFX_MSGMAP const __near * CVSoundEditApp::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CVSoundEditApp::GetMessageMap(CVSoundEditApp *this)
{
  return (const AFX_MSGMAP *)&off_535860;
}

//------------------------------------------------------------------------------
// Address: 0x00406610
// Name: public: void ATL::CSimpleStringT<char,0>::Append(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Append(ATL::CSimpleStringT<char,0> *this, char *pszSrc)
{
  if ( pszSrc != nullptr )
    ATL::CSimpleStringT<char,0>::Append(this, pszSrc, nLength: strlen(pszSrc));
  else
    ATL::CSimpleStringT<char,0>::Append(this, pszSrc: nullptr, nLength: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00406650
// Name: public: virtual int CVSoundEditApp::InitInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVSoundEditApp::InitInstance(CVSoundEditApp *this)
{
  char *m_lpCmdLine; // edx
  int v3; // eax
  char *v4; // eax
  CVSoundEditDlg v6; // [esp+4h] [ebp-11C4h] BYREF
  INITCOMMONCONTROLSEX picce; // [esp+11BCh] [ebp-Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCommandLine; // [esp+11C4h] [ebp-4h] BYREF

  picce.dwSize = 8;
  picce.dwICC = 255;
  InitCommonControlsEx(&picce);
  CWinApp::InitInstance(this);
  CWinApp::SetRegistryKey(this, lpszRegistryKey: "Local AppWizard-Generated Applications");
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strCommandLine,
    pszSrc: "vsoundedit.exe ");
  m_lpCmdLine = this->m_lpCmdLine;
  if ( m_lpCmdLine != nullptr )
    v3 = strlen(this->m_lpCmdLine);
  else
    v3 = 0;
  ATL::CSimpleStringT<char,0>::Append(this: &strCommandLine, pszSrc: m_lpCmdLine, nLength: v3);
  CVSoundEditDlg::CVSoundEditDlg(this: &v6, &strCommandLine, pParent: nullptr);
  this->m_pMainWnd = &v6;
  CDialog::DoModal(this: &v6);
  CVSoundEditDlg::~CVSoundEditDlg(this: &v6);
  v4 = strCommandLine.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strCommandLine.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422343
// Name: protected: static struct AFX_MSGMAP const __near * CWinApp::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CWinApp::GetThisMessageMap(CWinApp *this)
{
  return &messageMap_4;
}

//------------------------------------------------------------------------------
// Address: 0x00422349
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
// Address: 0x0042240E
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
// Address: 0x0042244E
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
// Address: 0x00422480
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
// Address: 0x004224BC
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
// Address: 0x00422547
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
// Address: 0x004225B3
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
// Address: 0x0042262F
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
// Address: 0x004226B2
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
// Address: 0x0042272F
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
// Address: 0x004227CF
// Name: public: virtual struct CRuntimeClass __near * CWinApp::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWinApp::GetRuntimeClass(CWinApp *this)
{
  return &CWinApp::classCWinApp;
}

//------------------------------------------------------------------------------
// Address: 0x00422ABB
// Name: public: virtual int CWinApp::LoadSysPolicies(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CWinApp::LoadSysPolicies(CWinApp *this)
{
  return CWinApp::_LoadSysPolicies(this);
}

//------------------------------------------------------------------------------
// Address: 0x00422AC0
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
// Address: 0x00422B34
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
// Address: 0x00422B57
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
// Address: 0x00422B98
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
// Address: 0x00422BDC
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
// Address: 0x00422C4A
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
// Address: 0x00422DAE
// Name: public: CWinApp::CWinApp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWinApp *__thiscall CWinApp::CWinApp(CWinApp *this, const char *lpszAppName)
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
// Address: 0x00422EA8
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
  free(pMem: (void *)this->m_pszAppName);
  free(pMem: (void *)this->m_pszRegistryKey);
  free(pMem: (void *)this->m_pszExeName);
  free(pMem: (void *)this->m_pszHelpFilePath);
  free(pMem: (void *)this->m_pszProfileName);
  this->m_hThread = nullptr;
  CWinThread::~CWinThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x004230B7
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
      pszSrc: &szGroupName);
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
// Address: 0x00423146
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
    memset((void *)&pguid, 0, sizeof(pguid));
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
// Address: 0x0042335C
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
// Address: 0x00423AD6
// Name: protected: void CWinApp::SetRegistryKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SetRegistryKey(CWinApp *this, const char *lpszRegistryKey)
{
  const char *v3; // eax
  char *m_pszProfileName; // [esp-Ch] [ebp-10h]

  free(pMem: (void *)this->m_pszRegistryKey);
  v3 = _strdup(string: lpszRegistryKey);
  m_pszProfileName = (char *)this->m_pszProfileName;
  this->m_pszRegistryKey = v3;
  free(pMem: m_pszProfileName);
  this->m_pszProfileName = _strdup(string: this->m_pszAppName);
}

//------------------------------------------------------------------------------
// Address: 0x00423B0C
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
// Address: 0x00423BFB
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
// Address: 0x00423CB6
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
// Address: 0x00423D10
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
// Address: 0x00423D7D
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
// Address: 0x00423E08
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
// Address: 0x00423EA1
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
// Address: 0x00423F4D
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
// Address: 0x0042423E
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
// Address: 0x0042424F
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
// Address: 0x00424488
// Name: public: virtual int CWinApp::Unregister(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::Unregister(CWinApp *this)
{
  CDocTemplate *NextDocTemplate; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // eax
  const char *m_pszProfileName; // [esp-10h] [ebp-150h]
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
    m_pszProfileName = this->m_pszProfileName;
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
// Address: 0x00424600
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
// Address: 0x0042467F
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
// Address: 0x00424691
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
// Address: 0x004246C1
// Name: public: virtual class CDocument __near * CWinApp::OpenDocumentFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *lpszFileName)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->OpenDocumentFile_2(this: this->m_pDocManager, a2: lpszFileName);
}

//------------------------------------------------------------------------------
// Address: 0x004246DA
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
// Address: 0x004246F3
// Name: public: void CWinApp::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::CloseAllDocuments(CWinApp *this, int bEndSession)
{
  if ( this->m_pDocManager != nullptr )
    this->m_pDocManager->CloseAllDocuments(this: this->m_pDocManager, a2: bEndSession);
}

//------------------------------------------------------------------------------
// Address: 0x0042470B
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
// Address: 0x00424741
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
// Address: 0x0042477B
// Name: protected: void CWinApp::OnAppExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnAppExit(CWinApp *this)
{
  SendMessageA(hWnd: this->m_pMainWnd->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042478E
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
// Address: 0x004247C2
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
// Address: 0x0042484A
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
// Address: 0x00424925
// Name: public: void CWinApp::EnableModeless(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::EnableModeless(CWinApp *this, int bEnable)
{
  CWinApp::DoEnableModeless(bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x00424937
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
// Address: 0x00424ACB
// Name: public: virtual int CWinApp::DoMessageBox(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::DoMessageBox(CWinApp *this, const char *lpszPrompt, UINT nType, unsigned int nIDPrompt)
{
  return CWinApp::ShowAppMessageBox(pApp: this, lpszPrompt, nType, nIDPrompt);
}

//------------------------------------------------------------------------------
// Address: 0x004423EA
// Name: public: void CWinApp::SetCurrentHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SetCurrentHandles(CWinApp *this)
{
  AFX_MODULE_STATE *ModuleState; // ebx
  DWORD ModuleFileNameA; // eax
  const char *v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax
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
       : _strdup(string: this->m_pszExeName);
    this->m_pszAppName = v5;
    if ( v5 == nullptr )
      goto LABEL_10;
  }
  if ( this->m_pszAppID == nullptr )
  {
    this->m_pszAppID = AfxLoadString(nID: 0xE006u, lpszBuf: szAppID, nMaxBuf: 0x100u) != 0
                     ? _strdup(string: szAppID)
                     : &szGroupName;
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
// Address: 0x004EDEA5
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
// Address: 0x004EE0E1
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
// Address: 0x00422525
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
// Address: 0x004227D5
// Name: public: static class CNoTrackObject __near * CThreadLocal<class AFX_MODULE_THREAD_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_THREAD_STATE *__stdcall CThreadLocal<AFX_MODULE_THREAD_STATE>::CreateObject()
{
  AFX_MODULE_THREAD_STATE *v0; // ecx
  AFX_MODULE_THREAD_STATE *result; // eax

  v0 = (AFX_MODULE_THREAD_STATE *)CNoTrackObject::operator new(nSize: 0x54u);
  result = nullptr;
  if ( v0 != nullptr )
    return AFX_MODULE_THREAD_STATE::AFX_MODULE_THREAD_STATE(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422801
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
// Address: 0x0042281F
// Name: _AfxLoadLangDLL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __fastcall AfxLoadLangDLL(const char *pszFormat, const char *pszPath, LCID lcid)
{
  int v5; // eax
  int v6; // edi
  unsigned int v7; // ebx
  int *v8; // eax
  char szLangCode[4]; // [esp+8h] [ebp-11Ch] BYREF
  char szLangDLL[276]; // [esp+Ch] [ebp-118h] BYREF

  if ( lcid == 2048 )
  {
    v5 = strcpy_s(_Dst: szLangCode, _SizeInBytes: 4u, _Src: "LOC");
    AfxCrtErrorCheck(error: v5);
  }
  else if ( GetLocaleInfoA(Locale: lcid, LCType: 3u, lpLCData: szLangCode, cchData: 4) == 0 )
  {
    return nullptr;
  }
  v6 = *_errno();
  *_errno() = 0;
  v7 = _snprintf_s(string: szLangDLL, sizeInBytes: 0x112u, count: 0x111u, format: pszFormat, pszPath, szLangCode);
  if ( *_errno() != 0 )
  {
    v8 = _errno();
    ATL::AtlCrtErrorCheck(nError: *v8);
  }
  else
  {
    *_errno() = v6;
  }
  if ( v7 <= 0x111 )
    return LoadLibraryA(lpLibFileName: szLangDLL);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004228F1
// Name: struct HINSTANCE__ __near * AfxLoadLangResourceDLL(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __stdcall AfxLoadLangResourceDLL(char *pszFormat, const char *pszPath)
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
  LCID v14; // [esp-4h] [ebp-25Ch]
  LCID v15; // [esp-4h] [ebp-25Ch]
  unsigned int nLanguages; // [esp+10h] [ebp-248h] BYREF
  char *v17; // [esp+14h] [ebp-244h]
  unsigned int cchLanguagesBuffer; // [esp+18h] [ebp-240h] BYREF
  unsigned int alcidSearch[25]; // [esp+1Ch] [ebp-23Ch]
  char rgchFullModulePath[262]; // [esp+80h] [ebp-1D8h] BYREF
  wchar_t wszLanguages[102]; // [esp+188h] [ebp-D0h] BYREF

  v17 = pszFormat;
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
  alcidSearch[v2 + 4] = 2048;
  v11 = v2 + 5;
  *(_WORD *)&rgchFullModulePath[260] = 0;
  if ( GetModuleFileNameA(hModule: (HMODULE)0x400000, lpFilename: rgchFullModulePath, nSize: 0x105u) == 0 )
    return nullptr;
  v12 = 0;
  if ( v11 <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = AfxLoadLangDLL(pszFormat: v17, pszPath, lcid: alcidSearch[v12]);
    if ( result != nullptr )
      break;
    if ( ++v12 >= v11 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422C20
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
// Address: 0x00422CFE
// Name: public: class AFX_MODULE_THREAD_STATE __near * CThreadLocal<class AFX_MODULE_THREAD_STATE>::GetData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_THREAD_STATE *__thiscall CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(
        CThreadLocal<AFX_MODULE_THREAD_STATE> *this)
{
  AFX_MODULE_THREAD_STATE *result; // eax

  result = (AFX_MODULE_THREAD_STATE *)CThreadLocalObject::GetData(
                                        this,
                                        pfnCreateObject: (CNoTrackObject *(__stdcall *)())CThreadLocal<AFX_MODULE_THREAD_STATE>::CreateObject);
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422D12
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
// Address: 0x00422D7A
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
// Address: 0x004233A2
// Name: class CWinThread __near * AfxGetThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWinThread *__stdcall AfxGetThread()
{
  return AfxGetModuleThreadState()->m_pCurrentWinThread;
}

//------------------------------------------------------------------------------
// Address: 0x004233AB
// Name: struct tagMSG __near * AfxGetCurrentMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tagMSG *__stdcall AfxGetCurrentMessage()
{
  return &AfxGetThreadState()->m_msgCur;
}

//------------------------------------------------------------------------------
// Address: 0x004233B4
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
// Address: 0x004233DE
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
// Address: 0x004233FB
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
// Address: 0x00423434
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
// Address: 0x0042347C
// Name: public: virtual void CWinThread::Delete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWinThread::Delete(CWinThread *this)
{
  if ( this->m_bAutoDelete != 0 )
    ((void (__thiscall *)(CWinThread *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042348A
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
// Address: 0x0042351E
// Name: public: virtual int CWinThread::ExitInstance(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CWinThread::ExitInstance(CWinThread *this)
{
  return AfxGetThreadState()->m_msgCur.wParam;
}

//------------------------------------------------------------------------------
// Address: 0x00423527
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
// Address: 0x004235A5
// Name: public: virtual long CWinThread::ProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::ProcessWndProcException(CWinThread *this, CException *e, const tagMSG *pMsg)
{
  return AfxInternalProcessWndProcException(__formal: e, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x004235B0
// Name: int IsEnterKey(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl IsEnterKey(tagMSG *lpMsg)
{
  return lpMsg->message == 256 && lpMsg->wParam == 13;
}

//------------------------------------------------------------------------------
// Address: 0x00423B20
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
// Address: 0x00423B79
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
// Address: 0x00423BDE
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
// Address: 0x00423F48
// Name: public: ATL::CRegKey::~CRegKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall ATL::CRegKey::~CRegKey(ATL::CRegKey *this)
{
  ATL::CRegKey::Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x00424268
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
// Address: 0x004242BC
// Name: long AfxDelRegTreeHelper(struct HKEY__ __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxDelRegTreeHelper(
        HKEY__ *hParentKey,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strKeyName,
        ATL::CAtlTransactionManager *pTM)
{
  char *m_pszData; // edi
  ATL::CStringData *v4; // eax
  LSTATUS v5; // eax
  LSTATUS v6; // esi
  LSTATUS v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str2; // [esp+18h] [ebp-130h] BYREF
  HKEY__ *phkResult; // [esp+1Ch] [ebp-12Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11; // [esp+20h] [ebp-128h] BYREF
  HKEY__ *hKey; // [esp+24h] [ebp-124h]
  bool v13; // [esp+2Bh] [ebp-11Dh]
  CHAR Name[280]; // [esp+2Ch] [ebp-11Ch] BYREF
  int v15; // [esp+144h] [ebp-4h]

  hKey = hParentKey;
  m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strKeyName->m_pszData - 1)[1];
  str2.m_pszData = m_pszData;
  v15 = 0;
  if ( hParentKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v4 = (ATL::CStringData *)ATL::operator+(result: &v11, psz1: "Software\\Classes\\", &str2);
    LOBYTE(v15) = 1;
    ATL::CSimpleStringT<char,0>::operator=(this: &str2, strSrc: v4);
    LOBYTE(v15) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
    m_pszData = str2.m_pszData;
    hKey = (HKEY__ *)-2147483647;
  }
  if ( pTM != nullptr )
    v5 = ATL::CAtlTransactionManager::RegOpenKeyExA(
           this: pTM,
           hKey,
           lpSubKey: m_pszData,
           ulOptions: 0,
           samDesired: 0x2001Fu,
           &phkResult);
  else
    v5 = RegOpenKeyExA(hKey, lpSubKey: m_pszData, ulOptions: 0, samDesired: 0x2001Fu, &phkResult);
  v6 = v5;
  if ( v5 == 0 )
  {
    while ( 1 )
    {
      v6 = RegEnumKeyA(hKey: phkResult, dwIndex: 0, lpName: Name, cchName: 0x104u);
      if ( v6 != 0 )
        break;
      LOBYTE(v15) = 2;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v11,
        pszSrc: Name);
      LOBYTE(v15) = 3;
      v6 = AfxDelRegTreeHelper(hParentKey: phkResult, strKeyName: &v11, pTM);
      v13 = v6 != 0;
      ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
      if ( v13 )
      {
        LOBYTE(v15) = 0;
        break;
      }
      v15 = 0;
    }
    if ( v6 == 259 || v6 == 1010 )
    {
      if ( pTM != nullptr )
        v7 = ATL::CAtlTransactionManager::RegDeleteKeyA(this: pTM, hKey, lpSubKey: m_pszData);
      else
        v7 = RegDeleteKeyA(hKey, lpSubKey: m_pszData);
      v6 = v7;
    }
    RegCloseKey(hKey: phkResult);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0042483E
// Name: protected: static class CFrameWnd __near * CCmdTarget::GetRoutingFrame_(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__stdcall CCmdTarget::GetRoutingFrame_()
{
  return AfxGetThreadState()->m_pRoutingFrame;
}

//------------------------------------------------------------------------------
// Address: 0x00424A98
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
// Address: 0x00424AE6
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
// Address: 0x00424B48
// Name: public: void CException::Delete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CException::Delete(CException *this)
{
  if ( this->m_bAutoDelete > 0 )
    ((void (__thiscall *)(CException *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00424B56
// Name: public: virtual int CException::GetErrorMessage(char __near *,unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CException::GetErrorMessage(
        CException *this,
        char *lpszError,
        unsigned int nMaxError,
        unsigned int *pnHelpContext)
{
  return this->GetErrorMessage(this, a2: lpszError, a3: nMaxError, a4: pnHelpContext);
}

//------------------------------------------------------------------------------
// Address: 0x004425B7
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
// Address: 0x0044261E
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
