// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service_ui/vmpi_service_ui.cpp
// Functions: 11
// ============================================================

#include "utils\vmpi\vmpi_service_ui\vmpi_service_ui.h"

//------------------------------------------------------------------------------
// Address: 0x004044E0
// Name: char __near * GetLastErrorString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLastErrorString()
{
  DWORD LastError; // eax
  void *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  strncpy(dest: (unsigned __int8 *)err, source: (unsigned __int8 *)lpMsgBuf, count: 0x800u);
  LocalFree(hMem: lpMsgBuf);
  err[2047] = 0;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x00404540
// Name: void LoadStateFromRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadStateFromRegistry()
{
  unsigned int val; // [esp+0h] [ebp-10h] BYREF
  unsigned int size; // [esp+4h] [ebp-Ch] BYREF
  unsigned int type; // [esp+8h] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+Ch] [ebp-4h] BYREF

  hKey = nullptr;
  RegCreateKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Valve\\VMPI", phkResult: &hKey);
  if ( hKey != nullptr )
  {
    val = 0;
    type = 4;
    size = 4;
    if ( RegQueryValueExA(
           hKey,
           lpValueName: "HighlightIconWhenBusy",
           lpReserved: nullptr,
           lpType: &type,
           lpData: (LPBYTE)&val,
           lpcbData: &size) == 0
      && type == 4
      && size == 4 )
    {
      g_bHighlightIconWhenBusy = val != 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004045C0
// Name: void SaveStateToRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveStateToRegistry()
{
  unsigned int val; // [esp+0h] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+4h] [ebp-4h] BYREF

  hKey = nullptr;
  RegCreateKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Valve\\VMPI", phkResult: &hKey);
  if ( hKey != nullptr )
  {
    val = g_bHighlightIconWhenBusy;
    RegSetValueExA(
      hKey,
      lpValueName: "HighlightIconWhenBusy",
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&val,
      cbData: 4u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404610
// Name: void UpdateAppIcon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateAppIcon()
{
  if ( g_iCurState == 0 )
    goto LABEL_2;
  if ( g_iCurState == 1 )
  {
    if ( !g_bHighlightIconWhenBusy )
    {
LABEL_2:
      CShellIconMgr::ChangeIcon(this: &g_ShellIconMgr, iIconResourceID: 105);
      return;
    }
    CShellIconMgr::ChangeIcon(this: &g_ShellIconMgr, iIconResourceID: 102);
  }
  else
  {
    CShellIconMgr::ChangeIcon(this: &g_ShellIconMgr, iIconResourceID: 101);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404660
// Name: public: virtual void CVMPIServiceUILoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceUILoggingListener::Log(
        CVMPIServiceUILoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  _BYTE *v3; // eax
  char timeString[512]; // [esp+0h] [ebp-224h] BYREF
  tm newtime; // [esp+200h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: this, a2: &newtime);
  _Plat_GetTimeString(a1: &newtime, a2: timeString, a3: 512);
  strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
  if ( v3 != nullptr )
    *v3 = 0;
  if ( g_pConsoleWnd != nullptr )
    g_pConsoleWnd->PrintToConsole(this: g_pConsoleWnd, a2: timeString);
  OutputDebugStringA(lpOutputString: timeString);
  if ( g_pConsoleWnd != nullptr )
    g_pConsoleWnd->PrintToConsole(this: g_pConsoleWnd, a2: " - ");
  OutputDebugStringA(lpOutputString: " - ");
  if ( g_pConsoleWnd != nullptr )
    g_pConsoleWnd->PrintToConsole(this: g_pConsoleWnd, a2: pMessage);
  OutputDebugStringA(lpOutputString: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00404710
// Name: void UpdatePopupMenuState(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePopupMenuState()
{
  bool v0; // bl
  bool v1; // al
  bool v2; // al

  v0 = (unsigned int)g_iCurState < 2;
  EnableMenuItem(hMenu: g_hPopupMenu, uIDEnableItem: 0x9C41u, uEnable: (unsigned int)g_iCurState < 2);
  EnableMenuItem(hMenu: g_hPopupMenu, uIDEnableItem: 0x9C43u, uEnable: !v0);
  v1 = g_pConsoleWnd->IsVisible(this: g_pConsoleWnd);
  EnableMenuItem(hMenu: g_hPopupMenu, uIDEnableItem: 0x9C45u, uEnable: v1);
  v2 = g_pConsoleWnd->IsVisible(this: g_pConsoleWnd);
  EnableMenuItem(hMenu: g_hPopupMenu, uIDEnableItem: 0x9C46u, uEnable: !v2);
  CheckMenuItem(hMenu: g_hPopupMenu, uIDCheckItem: 0x8006u, uCheck: g_bScreensaverMode ? 8 : 0);
  CheckMenuItem(hMenu: g_hPopupMenu, uIDCheckItem: 0x8005u, uCheck: g_bHighlightIconWhenBusy ? 8 : 0);
}

//------------------------------------------------------------------------------
// Address: 0x004047E0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  HMENU MenuA; // eax
  tagMSG msg; // [esp+0h] [ebp-1Ch] BYREF

  g_hInstance = hInstance;
  VMPI_WriteToLogFile(pMsg: "vmpi_service_ui startup.\n");
  if ( CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "vmpi_service_ui_mutex") != nullptr
    && GetLastError() == 183 )
  {
    return 1;
  }
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &g_VMPIServiceUILoggingListener);
  if ( g_pConsoleWnd == nullptr )
    g_pConsoleWnd = CreateConsoleWnd(
                      hInstance: g_hInstance,
                      dialogResourceID: 0x81u,
                      editControlID: 1000,
                      bVisible: false);
  LoadStateFromRegistry();
  MenuA = LoadMenuA(hInstance: g_hInstance, lpMenuName: (LPCSTR)0x67);
  g_hMenu = MenuA;
  if ( MenuA != nullptr )
  {
    g_hPopupMenu = GetSubMenu(hMenu: MenuA, nPos: 0);
    UpdatePopupMenuState();
    _Msg(a1: "Waiting for jobs...\n");
    if ( CShellIconMgr::Init(
           this: &g_ShellIconMgr,
           pHelper: &g_ShellIconMgrHelper,
           pToolTip: g_pIconTooltip,
           iCallbackMessage: 32868,
           iIconResourceID: 105) != 0 )
    {
      CServiceConnMgr::InitClient(this: &g_ConnMgr);
      while ( 1 )
      {
        msg.message = 0;
        if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
          break;
LABEL_13:
        if ( msg.message == 18 )
          goto LABEL_17;
        CServiceConnMgr::Update(this: &g_ConnMgr);
        if ( !CServiceConnMgr::IsConnected(this: &g_ConnMgr) )
          CShellIconMgr::ChangeIcon(this: &g_ShellIconMgr, iIconResourceID: 132);
        Sleep(dwMilliseconds: 0x1Eu);
      }
      while ( msg.message != 18 )
      {
        TranslateMessage(lpMsg: &msg);
        DispatchMessageA(lpMsg: &msg);
        if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
          goto LABEL_13;
      }
LABEL_17:
      CServiceConnMgr::Term(this: &g_ConnMgr);
      CShellIconMgr::Term(this: &g_ShellIconMgr);
    }
    _LoggingSystem_PopLoggingState(a1: 0);
    return 0;
  }
  else
  {
    _Warning(a1: "LoadMenu failed.\n");
    _LoggingSystem_PopLoggingState(a1: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049C0
// Name: public: virtual void CUIConnMgr::HandlePacket(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUIConnMgr::HandlePacket(CUIConnMgr *this, const char *pData, int len)
{
  int v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  int v7; // edi
  int v8; // eax
  const char *v9; // eax
  const char *LastErrorString; // eax
  char str[4096]; // [esp+4h] [ebp-1158h] BYREF
  char pDest[260]; // [esp+1004h] [ebp-158h] BYREF
  _STARTUPINFOA dst; // [esp+1108h] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+114Ch] [ebp-10h] BYREF

  if ( *pData == 1 )
  {
    v3 = pData[1];
    if ( pData[1] != 0 )
    {
      switch ( v3 )
      {
        case 1:
          g_iCurState = *(_DWORD *)(pData + 2);
          VMPI_WriteToLogFile(pMsg: "New UI state: %d.\n", g_iCurState);
          UpdateAppIcon();
          g_bScreensaverMode = pData[6] != 0;
          if ( g_pPassword != nullptr )
            free(pMem: g_pPassword);
          g_pPassword = (char *)operator new(nSize: strlen(pData + 7) + 1);
          v4 = pData + 7;
          v5 = g_pPassword;
          do
          {
            v6 = *v4;
            *v5++ = *v4++;
          }
          while ( v6 != 0 );
          UpdatePopupMenuState();
          break;
        case 2:
          VMPI_WriteToLogFile(pMsg: "Got a VMPI_SERVICE_TO_UI_PATCHING packet.\n");
          v7 = pData[2];
          V_strncpy(pDest, pSrc: pData + 3, maxLen: 260);
          v8 = _V_strlen(str: pDest);
          V_strncpy(pDest: str, pSrc: &pData[v8 + 4], maxLen: 4096);
          _V_strlen(str);
          memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
          dst.cb = 68;
          memset(&ProcessInformation, 0, sizeof(ProcessInformation));
          if ( CreateProcessA(
                 lpApplicationName: nullptr,
                 lpCommandLine: str,
                 lpProcessAttributes: nullptr,
                 lpThreadAttributes: nullptr,
                 bInheritHandles: false,
                 dwCreationFlags: 0x8000000u,
                 lpEnvironment: nullptr,
                 lpCurrentDirectory: pDest,
                 lpStartupInfo: &dst,
                 lpProcessInformation: &ProcessInformation) )
          {
            v9 = "yes";
            if ( v7 == 0 )
              v9 = "no";
            VMPI_WriteToLogFile(pMsg: "CreateProcess succeeded:\n%s\nExit after: %s\n", str, v9);
            CloseHandle(hObject: ProcessInformation.hProcess);
            CloseHandle(hObject: ProcessInformation.hThread);
            if ( v7 != 0 )
              PostQuitMessage(nExitCode: 0);
          }
          else
          {
            LastErrorString = GetLastErrorString();
            VMPI_WriteToLogFile(pMsg: "CreateProcess failed: %s", LastErrorString);
          }
          break;
        case 3:
          PostQuitMessage(nExitCode: 0);
          break;
        default:
          break;
      }
    }
    else
    {
      _Msg(a1: pData + 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BA0
// Name: public: virtual struct HINSTANCE__ __near * CShellIconMgrHelper::GetHInstance(void)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE __thiscall CShellIconMgrHelper::GetHInstance(CShellIconMgrHelper *this)
{
  return g_hInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: public: CSimpleStringDlg::~CSimpleStringDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleStringDlg::~CSimpleStringDlg(CSimpleStringDlg *this)
{
  this->m_sValue.m_Storage.m_nActualLength = 0;
  if ( this->m_sValue.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sValue.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sValue.m_Storage.m_Memory.m_pMemory);
      this->m_sValue.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sValue.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_sTitle.m_Storage.m_nActualLength = 0;
  if ( this->m_sTitle.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sTitle.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sTitle.m_Storage.m_Memory.m_pMemory);
      this->m_sTitle.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sTitle.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D00
// Name: public: virtual int CShellIconMgrHelper::WindowProc(void __near *,int,long,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShellIconMgrHelper::WindowProc(
        CShellIconMgrHelper *this,
        HWND pWnd,
        UINT uMsg,
        int wParam,
        LPARAM lParam)
{
  UINT v5; // esi
  WPARAM v6; // edi
  int result; // eax
  const char *v8; // eax
  const char *v9; // esi
  DWORD TickCount; // edi
  CUtlString v11; // [esp-20h] [ebp-70h] BYREF
  CUtlString v12; // [esp-10h] [ebp-60h] BYREF
  CSimpleStringDlg dlg; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > data; // [esp+34h] [ebp-1Ch] BYREF
  tagPOINT cursorPos; // [esp+48h] [ebp-8h] BYREF

  v5 = uMsg;
  v6 = wParam;
  if ( uMsg != 273 )
  {
    if ( uMsg == 32868 && (lParam == 516 || lParam == 513) )
    {
      GetCursorPos(lpPoint: &cursorPos);
      UpdatePopupMenuState();
      SetForegroundWindow(hWnd: pWnd);
      TrackPopupMenu(
        hMenu: g_hPopupMenu,
        uFlags: 0x28u,
        x: cursorPos.x,
        y: cursorPos.y,
        nReserved: 0,
        hWnd: pWnd,
        prcRect: nullptr);
      return 0;
    }
    return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
  }
  if ( wParam <= 40001 )
  {
    if ( wParam != 40001 )
    {
      if ( wParam > 32771 )
      {
        if ( wParam != 32773 )
        {
          if ( wParam != 32774 )
          {
            if ( wParam == 32776 )
              DialogBoxParamA(
                hInstance: g_hInstance,
                lpTemplateName: (LPCSTR)0x85,
                hWndParent: nullptr,
                lpDialogFunc: VWatchDlgProc,
                dwInitParam: 0);
            return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
          }
          v12.m_Storage.m_nActualLength = 2;
          g_bScreensaverMode = !g_bScreensaverMode;
          LOBYTE(uMsg) = 7;
          BYTE1(uMsg) = g_bScreensaverMode;
          v12.m_Storage.m_Memory.m_nGrowSize = (int)&uMsg;
          goto LABEL_24;
        }
        g_bHighlightIconWhenBusy = !g_bHighlightIconWhenBusy;
        SaveStateToRegistry();
        UpdateAppIcon();
        UpdatePopupMenuState();
      }
      else
      {
        if ( wParam == 32771 )
        {
          CSimpleStringDlg::CSimpleStringDlg(this: &dlg);
          v8 = g_pPassword;
          if ( g_pPassword == nullptr )
            v8 = str;
          CUtlString::CUtlString(this: &v12, pString: v8);
          CUtlString::CUtlString(this: &v11, pString: "Set Password (-mpi_pw)");
          if ( CSimpleStringDlg::Show(this: &dlg, hParent: nullptr, sTitle: v11, sInitialValue: v12) == 1 )
          {
            v9 = CUtlString::Get(this: &dlg.m_sValue);
            memset(&data, 0, sizeof(data));
            HIBYTE(wParam) = 4;
            CUtlVector<char,CUtlMemory<char,int>>::AddToTail(this: &data, src: (char *)&wParam + 3);
            CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
              this: &data,
              elem: data.m_Size,
              num: strlen(v9) + 1,
              pToInsert: v9);
            CServiceConnMgr::SendPacket(this: &g_ConnMgr, id: -1, pData: data.m_Memory.m_pMemory, len: data.m_Size);
            CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &data);
            v5 = uMsg;
          }
          CSimpleStringDlg::~CSimpleStringDlg(this: &dlg);
          return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
        }
        if ( wParam == 133 )
        {
          v12.m_Storage.m_nActualLength = 1;
          HIBYTE(uMsg) = 78;
          v12.m_Storage.m_Memory.m_nGrowSize = (int)&uMsg + 3;
LABEL_24:
          CServiceConnMgr::SendPacket(
            this: &g_ConnMgr,
            id: -1,
            pData: (const void *)v12.m_Storage.m_Memory.m_nGrowSize,
            len: v12.m_Storage.m_nActualLength);
        }
      }
      return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
    }
    v12.m_Storage.m_nActualLength = 1;
    HIBYTE(uMsg) = 3;
    v12.m_Storage.m_Memory.m_nGrowSize = (int)&uMsg + 3;
    goto LABEL_24;
  }
  switch ( wParam )
  {
    case 40003:
      v12.m_Storage.m_nActualLength = 1;
      HIBYTE(uMsg) = 2;
      v12.m_Storage.m_Memory.m_nGrowSize = (int)&uMsg + 3;
      goto LABEL_24;
    case 40004:
      HIBYTE(uMsg) = 5;
      CServiceConnMgr::SendPacket(this: &g_ConnMgr, id: -1, pData: (char *)&uMsg + 3, len: 1);
      CShellIconMgr::Term(this: &g_ShellIconMgr);
      TickCount = GetTickCount();
      while ( GetTickCount() - TickCount < 0x7D0 )
      {
        CServiceConnMgr::Update(this: &g_ConnMgr);
        if ( !CServiceConnMgr::IsConnected(this: &g_ConnMgr) )
          break;
        Sleep(dwMilliseconds: 0xAu);
      }
      PostQuitMessage(nExitCode: 0);
      result = 1;
      break;
    case 40005:
      g_pConsoleWnd->SetVisible(this: g_pConsoleWnd, a2: true);
      UpdatePopupMenuState();
      return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
    case 40006:
      g_pConsoleWnd->SetVisible(this: g_pConsoleWnd, a2: false);
      UpdatePopupMenuState();
      return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
    default:
      return DefWindowProcA(hWnd: pWnd, Msg: v5, wParam: v6, lParam);
  }
  return result;
}
