// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sys_mainwind.cpp
// Functions: 38
// ============================================================

#include "engine\sys_mainwind.h"

//------------------------------------------------------------------------------
// Address: 0x1007A930
// Name: public: virtual bool CGame::IsActiveApp(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGame::IsActiveApp(CDemoActionManager *this)
{
  return this->m_bDirty;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB50
// Name: public: virtual void __near * __near * CGame::GetMainWindowAddress(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CGame::GetMainWindowAddress(CStaticProp *this)
{
  return &this->ICollideable;
}

//------------------------------------------------------------------------------
// Address: 0x101EC5E0
// Name: struct InputContextHandle_t__ __near * GetGameInputContext(void)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__cdecl GetGameInputContext()
{
  return g_Game.m_hInputContext;
}

//------------------------------------------------------------------------------
// Address: 0x101EC5F0
// Name: public: void CGame::HandleMsg_WindowMove(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_WindowMove(CGame *this, const InputEvent_t *event)
{
  game->SetWindowXY(this: game, a2: event->m_nData, a3: event->m_nData2);
  videomode->UpdateWindowPosition(this: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x101EC620
// Name: public: void CGame::HandleMsg_Close(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_Close(CGame *this, const InputEvent_t *event)
{
  if ( eng->GetState(this: eng) == DLL_ACTIVE )
    eng->SetQuitting(this: eng, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101EC650
// Name: public: virtual void CGame::DispatchAllStoredGameMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DispatchAllStoredGameMessages(CGame *this)
{
  int v2; // edi
  const InputEvent_t *v3; // eax
  const InputEvent_t *v4; // esi
  IEngineVGuiInternal *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // [esp+8h] [ebp-4h]

  v2 = g_pInputSystem->GetEventCount(this: g_pInputSystem);
  v3 = g_pInputSystem->GetEventData(this: g_pInputSystem);
  if ( v2 > 0 )
  {
    v10 = v2;
    v4 = v3;
    do
    {
      switch ( v4->m_nType )
      {
        case 0:
        case 1:
        case 2:
        case 0xCA:
        case 0xCB:
          Key_Event(event: v4);
          break;
        case 3:
          if ( (g_pScaleformUI == nullptr || !g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: v4))
            && (g_pMatSystemSurface == nullptr
             || !g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: v4))
            && g_ClientDLL != nullptr )
          {
            g_ClientDLL->HandleGameUIEvent(this: g_ClientDLL, a2: v4);
          }
          break;
        case 0xD5:
          if ( v4->m_nData == 1 )
          {
            v5 = EngineVGui();
            if ( !v5->IsGameUIVisible(this: v5) && sv.m_State >= ss_active && CBaseServer::IsSinglePlayerGame(this: &sv) )
            {
              TraceType = CTraceFilter::GetTraceType(this: v6);
              Cbuf_AddText(eTarget: TraceType, pText: "gameui_activate", nTickDelay: 0);
            }
          }
          break;
        default:
          if ( (g_pMatSystemSurface == nullptr
             || !g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: v4))
            && (g_pScaleformUI == nullptr || !g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: v4)) )
          {
            v8 = 0;
            v9 = 0;
            while ( g_GameMessageHandlers[v9].m_nEventType != v4->m_nType )
            {
              ++v9;
              ++v8;
              if ( v9 >= 4 )
                goto LABEL_25;
            }
            ((void (__thiscall *)(char *, const InputEvent_t *))dword_10422B40[6 * v8])(
              a1: (char *)this + dword_10422B44[6 * v8],
              a2: v4);
          }
          break;
      }
LABEL_25:
      ++v4;
      --v10;
    }
    while ( v10 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC8C0
// Name: void VCR_EnterPausedState(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VCR_EnterPausedState()
{
  HMODULE LibraryA; // eax
  SHORT (__stdcall *GetAsyncKeyState)(int); // eax
  HANDLE CurrentProcess; // eax

  g_bVCRSingleStep = false;
  if ( (_S1_20 & 1) != 0 )
  {
    LibraryA = hInst;
  }
  else
  {
    _S1_20 |= 1u;
    LibraryA = LoadLibraryA(lpLibFileName: "user32.dll");
    hInst = LibraryA;
  }
  if ( LibraryA != nullptr )
  {
    if ( (_S1_20 & 2) != 0 )
    {
      GetAsyncKeyState = pfn;
    }
    else
    {
      _S1_20 |= 2u;
      GetAsyncKeyState = (SHORT (__stdcall *)(int))GetProcAddress(hModule: LibraryA, lpProcName: "GetAsyncKeyState");
      pfn = GetAsyncKeyState;
    }
    if ( GetAsyncKeyState != nullptr && GetAsyncKeyState(vKey: 82) >= 0 )
    {
      do
      {
        if ( pfn(a1: 81) < 0 )
        {
          CurrentProcess = GetCurrentProcess();
          TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
        }
        if ( pfn(a1: 83) >= 0 )
        {
          g_bWaitingForStepKeyUp = false;
        }
        else if ( !g_bWaitingForStepKeyUp )
        {
          g_bVCRSingleStep = true;
          g_bWaitingForStepKeyUp = true;
          return;
        }
        Sleep(dwMilliseconds: 2u);
      }
      while ( pfn(a1: 82) >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC9B0
// Name: CallDefaultWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall CallDefaultWindowProc(HWND__ *hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x101EC9C0
// Name: DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs
// Source: json
//------------------------------------------------------------------------------
int DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs()
{
  int result; // eax
  SOCKET v1; // eax
  SOCKET v2; // esi
  struct hostent *v3; // edi
  WSAData wsaData; // [esp+0h] [ebp-2A4h] BYREF
  char pszHostName[256]; // [esp+190h] [ebp-114h] BYREF
  sockaddr_in myIpAddress; // [esp+290h] [ebp-14h] BYREF
  char Options[1]; // [esp+2A3h] [ebp-1h] BYREF

  result = WSAStartup(wVersionRequested: 0x101u, lpWSAData: &wsaData);
  if ( result == 0 )
  {
    v1 = socket(af: 2, type: 2, protocol: 0);
    v2 = v1;
    if ( v1 != -1 )
    {
      Options[0] = 1;
      setsockopt(s: v1, level: 0xFFFF, optname: 32, optval: Options, optlen: 1);
      gethostname(name: pszHostName, namelen: 256);
      v3 = gethostbyname(name: pszHostName);
      if ( v3 != nullptr )
      {
        memset(&myIpAddress.sin_port, 0, 14);
        myIpAddress.sin_family = 2;
        myIpAddress.sin_port = htons(hostshort: 0x6987u);
        myIpAddress.sin_addr.S_un.S_addr = **(_DWORD **)v3->h_addr_list;
        if ( bind(s: v2, name: (const struct sockaddr *)&myIpAddress, namelen: 16) != -1 )
          sendto(s: v2, buf: pszHostName, len: 1, flags: 0, to: (const struct sockaddr *)&myIpAddress, tolen: 16);
      }
      closesocket(s: v2);
    }
    return WSACleanup();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ECAC0
// Name: private: void CGame::DetachFromWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DetachFromWindow(CGame *this)
{
  if ( this->m_hWindow != nullptr && this->m_ChainedWindowProc != nullptr )
  {
    if ( g_pMatSystemSurface != nullptr )
      g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
    if ( g_pInputSystem != nullptr )
    {
      g_pInputSystem->EnableInput(this: g_pInputSystem, a2: false);
      g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
    }
    SetWindowLongW(hWnd: this->m_hWindow, nIndex: -4, dwNewLong: (LONG)this->m_ChainedWindowProc);
  }
  else
  {
    this->m_ChainedWindowProc = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECB20
// Name: public: virtual void CGame::PlayStartupVideos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::PlayStartupVideos(CGame *this)
{
  int v2; // eax
  bool v3; // bl
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  bool bRecap; // [esp+7h] [ebp-1h]

  if ( (unsigned __int8)_Plat_IsInBenchmarkMode() == 0 )
  {
    if ( !videomode->IsWindowedMode(this: videomode) )
      _ThreadSleep(a1: 1000);
    v2 = _CommandLine();
    v3 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-endgamevid", a3: 0) != 0;
    v4 = _CommandLine();
    bRecap = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-recapvid", a3: 0) != 0;
    if ( g_pFullFileSystem->FileExists(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: "media/HealthWarning.txt",
           a3: nullptr)
      || v3
      || bRecap
      || (v5 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-dev", a3: 0) == 0)
      && (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-novid", a3: 0) == 0)
      && (v7 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "-allowdebug", a3: 0) == 0)
      && (v8 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-console", a3: 0) == 0)
      && (v9 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-toconsole", a3: 0) == 0) )
    {
      v10 = "media/startupvids.txt";
      if ( v3 )
      {
        v11 = _CommandLine();
        (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 16))(a1: v11, a2: "+map");
        v12 = _CommandLine();
        (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 16))(a1: v12, a2: "+load");
        this->PlayVideoListAndWait(this, a2: "media/EndGameVids.txt", a3: false);
      }
      else
      {
        if ( bRecap )
          v10 = "media/RecapVids.txt";
        this->PlayVideoListAndWait(this, a2: v10, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECC90
// Name: public: void CSubtitlePanel::StartCaptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::StartCaptions(CSubtitlePanel *this)
{
  CStatTime *v2; // ecx

  _Plat_FloatTime((CStatTime *)this);
  this->m_Captions.m_CaptionStartTime = _Plat_FloatTime(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101ECCB0
// Name: bool ShouldUseCaptioning(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldUseCaptioning()
{
  CSteam3Client *v0; // eax
  const char *v1; // eax
  int v2; // esi
  char language[64]; // [esp+0h] [ebp-40h] BYREF

  V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  if ( Steam3Client()->m_pSteamApps != nullptr )
  {
    v0 = Steam3Client();
    v1 = v0->m_pSteamApps->GetCurrentGameLanguage(this: v0->m_pSteamApps);
    V_strncpy(pDest: language, pSrc: v1, maxLen: 64);
  }
  v2 = 0;
  while ( _V_stricmp(s1: language, s2: lpszDubbedLanguages[v2]) != 0 )
  {
    if ( (unsigned int)++v2 >= 5 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101ECD30
// Name: public: virtual bool CGame::Init(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::Init(CGame *this, HINSTANCE__ *pvInstance)
{
  InputContextHandle_t__ *v4; // eax
  _OSVERSIONINFOA vinfo; // [esp+4h] [ebp-94h] BYREF

  this->m_bExternallySuppliedWindow = false;
  vinfo.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(lpVersionInformation: &vinfo) || vinfo.dwPlatformId == 0 )
    return 0;
  this->m_hInstance = pvInstance;
  v4 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  this->m_hInputContext = v4;
  g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: v4, a3: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ECDA0
// Name: public: virtual bool CGame::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::Shutdown(CGame *this)
{
  if ( this->m_hInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    this->m_hInputContext = nullptr;
  }
  this->m_hInstance = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ECDD0
// Name: public: virtual void CGame::GetDesktopInfo(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::GetDesktopInfo(CGame *this, int *width, int *height, int *refreshrate)
{
  int m_iDesktopWidth; // eax
  HDC DC; // esi

  m_iDesktopWidth = this->m_iDesktopWidth;
  if ( m_iDesktopWidth != 0 )
  {
    *width = m_iDesktopWidth;
    *height = this->m_iDesktopHeight;
    *refreshrate = this->m_iDesktopRefreshRate;
  }
  else
  {
    DC = GetDC(hWnd: nullptr);
    *width = GetDeviceCaps(hdc: DC, index: 8);
    *height = GetDeviceCaps(hdc: DC, index: 10);
    *refreshrate = GetDeviceCaps(hdc: DC, index: 116);
    ReleaseDC(hWnd: nullptr, hDC: DC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECE40
// Name: public: void CGame::SetMainWindow(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetMainWindow(CGame *this, HWND__ *window)
{
  HWND__ *m_hWindow; // ebx
  HDC DC; // edi

  this->m_hWindow = window;
  avi->SetMainWindow(this: avi, a2: window);
  if ( this->m_iDesktopWidth == 0 || this->m_iDesktopHeight == 0 )
  {
    m_hWindow = this->m_hWindow;
    DC = GetDC(hWnd: m_hWindow);
    this->m_iDesktopWidth = GetDeviceCaps(hdc: DC, index: 8);
    this->m_iDesktopHeight = GetDeviceCaps(hdc: DC, index: 10);
    this->m_iDesktopRefreshRate = GetDeviceCaps(hdc: DC, index: 116);
    ReleaseDC(hWnd: m_hWindow, hDC: DC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECEB0
// Name: public: virtual void CGame::SetWindowXY(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetWindowXY(
        CUtlBuffer *this,
        bool (__thiscall *getFunc)(CUtlBuffer *this, int),
        bool (__thiscall *putFunc)(CUtlBuffer *this, int))
{
  this->m_GetOverflowFunc = getFunc;
  this->m_PutOverflowFunc = putFunc;
}

//------------------------------------------------------------------------------
// Address: 0x101ECED0
// Name: public: virtual void CGame::SetWindowSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetWindowSize(CGame *this, int w, int h)
{
  this->m_width = w;
  this->m_height = h;
}

//------------------------------------------------------------------------------
// Address: 0x101ECEF0
// Name: public: virtual void CGame::GetWindowRect(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::GetWindowRect(CGame *this, int *x, int *y, int *w, int *h)
{
  if ( x != nullptr )
    *x = this->m_x;
  if ( y != nullptr )
    *y = this->m_y;
  if ( w != nullptr )
    *w = this->m_width;
  if ( h != nullptr )
    *h = this->m_height;
}

//------------------------------------------------------------------------------
// Address: 0x101ECF30
// Name: public: virtual void CGame::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::OnScreenSizeChanged(CGame *this, int nOldWidth, int nOldHeight)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->OnScreenSizeChanged(this: g_ClientDLL, a2: nOldWidth, a3: nOldHeight);
}

//------------------------------------------------------------------------------
// Address: 0x101ECF50
// Name: private: void CGame::AppActivate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::AppActivate(CGame *this, bool fActive)
{
  bool v3; // bl
  IVideoMode_vtbl *v4; // eax
  void (*RestoreVideo)(void); // edx

  v3 = true;
  if ( !g_bTextMode )
    v3 = fActive;
  if ( this->IsActiveApp(this) != v3 )
  {
    this->m_bCanPostActivateEvents = false;
    if ( videomode != nullptr )
    {
      v4 = videomode->__vftable;
      if ( v3 )
        RestoreVideo = (void (*)(void))v4->RestoreVideo;
      else
        RestoreVideo = (void (*)(void))v4->ReleaseVideo;
      RestoreVideo();
    }
    if ( host_initialized )
    {
      ClearIOStates();
      if ( v3 )
      {
        UpdateMaterialSystemConfig();
        this->m_bActiveApp = v3;
        this->m_bCanPostActivateEvents = true;
        return;
      }
      if ( g_ClientDLL != nullptr )
        g_ClientDLL->IN_DeactivateMouse(this: g_ClientDLL);
    }
    this->m_bActiveApp = v3;
    this->m_bCanPostActivateEvents = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECFD0
// Name: public: void CGame::HandleMsg_ActivateApp(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_ActivateApp(CGame *this, const InputEvent_t *event)
{
  CGame::AppActivate(this, fActive: event->m_nData != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101ECFF0
// Name: public: int CGame::WindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGame::WindowProc(CGame *this, HWND__ *hWnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  int (__thiscall *GetQuitting)(IEngine *); // edx
  int result; // eax
  vgui::CTreeViewListControl *v8; // ecx
  int v9; // eax
  DWORD WindowLongA; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t v13; // eax
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t v15; // eax
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t v17; // eax
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v19; // ecx
  ECommandTarget_t v20; // eax
  vgui::CTreeViewListControl *v21; // [esp-10h] [ebp-8Ch]
  tagPAINTSTRUCT ps; // [esp+4h] [ebp-78h] BYREF
  InputEvent_t event; // [esp+44h] [ebp-38h] BYREF
  tagRECT rcClient; // [esp+58h] [ebp-24h] BYREF
  tagRECT rcWindow; // [esp+68h] [ebp-14h] BYREF
  int lRet; // [esp+78h] [ebp-4h]

  GetQuitting = eng->GetQuitting;
  lRet = 0;
  if ( GetQuitting(this: eng) != 0 )
    return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  memset((void *)&event, 0, sizeof(event));
  event.m_nTick = g_pInputSystem->GetPollTick(this: g_pInputSystem);
  if ( uMsg <= 0xF )
  {
    if ( uMsg == 15 )
    {
      BeginPaint(hWnd, lpPaint: &ps);
      GetClientRect(hWnd, lpRect: &rcClient);
      EndPaint(hWnd, lpPaint: &ps);
      return lRet;
    }
    else
    {
      switch ( uMsg )
      {
        case 1u:
          SetForegroundWindow(hWnd);
          result = lRet;
          break;
        case 3u:
          event.m_nType = 2000;
          event.m_nData = (__int16)lParam;
          event.m_nData2 = SHIWORD(lParam);
          goto LABEL_8;
        case 5u:
          if ( wParam == 1 )
          {
            GetWindowRect(hWnd, lpRect: &rcWindow);
            v9 = rcWindow.top + this->m_rcLastRestoredClientRect.bottom;
            rcWindow.right = rcWindow.left + this->m_rcLastRestoredClientRect.right;
            rcWindow.bottom = v9;
            WindowLongA = GetWindowLongA(hWnd, nIndex: -16);
            AdjustWindowRect(lpRect: &rcWindow, dwStyle: WindowLongA, bMenu: false);
            MoveWindow(
              hWnd,
              X: rcWindow.left,
              Y: rcWindow.top,
              nWidth: rcWindow.right - rcWindow.left,
              nHeight: rcWindow.bottom - rcWindow.top,
              bRepaint: false);
          }
          else
          {
            GetClientRect(hWnd, lpRect: &this->m_rcLastRestoredClientRect);
          }
          result = lRet;
          break;
        case 7u:
          if ( g_pHammer == nullptr )
            return lRet;
          g_pHammer->NoteEngineGotFocus(this: g_pHammer);
          result = lRet;
          break;
        default:
          return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
      }
    }
    return result;
  }
  if ( uMsg > 0x112 )
  {
    switch ( uMsg )
    {
      case 0x218u:
        if ( wParam == 0 )
        {
          _Msg(a1: "OS requested hibernation, ignoring request.\n");
          return 1112363332;
        }
        break;
      case 0x282u:
        if ( wParam == 14 && !videomode->IsWindowedMode(this: videomode) )
          return 0;
        break;
      case 0x47Cu:
        TraceType = CTraceFilter::GetTraceType(this: v8);
        Cbuf_Clear(eTarget: TraceType);
        v20 = CTraceFilter::GetTraceType(this: v19);
        Cbuf_AddText(eTarget: v20, pText: "quit_gameconsole\n", nTickDelay: 0);
        return lRet;
      default:
        break;
    }
    return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  }
  if ( uMsg == 274 )
  {
    if ( wParam != 61808 && wParam != 61696 && wParam != 61760 )
    {
      if ( wParam != 61536 )
      {
LABEL_32:
        S_BlockSound();
        S_ClearBuffer();
        lRet = CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: 0x112u, wParam, lParam);
        S_UnblockSound();
        return lRet;
      }
      if ( (unsigned __int16)GetKeyState(nVirtKey: 164) >> 8 == 0
        && (unsigned __int16)GetKeyState(nVirtKey: 165) >> 8 == 0 )
      {
        v15 = CTraceFilter::GetTraceType(this: v14);
        Cbuf_Clear(eTarget: v15);
        v17 = CTraceFilter::GetTraceType(this: v16);
        Cbuf_AddText(eTarget: v17, pText: "quit\n", nTickDelay: 0);
        goto LABEL_32;
      }
    }
    return 0;
  }
  switch ( uMsg )
  {
    case 0x1Cu:
      if ( !this->m_bCanPostActivateEvents )
        return lRet;
      event.m_nType = 2001;
      event.m_nData = wParam == 1;
LABEL_8:
      g_pInputSystem->PostUserEvent(this: g_pInputSystem, a2: &event);
      result = lRet;
      break;
    case 0x4Au:
      v21 = *(vgui::CTreeViewListControl **)(lParam + 8);
      v11 = CTraceFilter::GetTraceType(this: v21);
      Cbuf_AddText(eTarget: v11, pText: (const char *)v21, nTickDelay: 0);
      v13 = CTraceFilter::GetTraceType(this: v12);
      Cbuf_AddText(eTarget: v13, pText: "\n", nTickDelay: 0);
      lRet = 1;
      result = 1;
      break;
    case 0x7Eu:
      if ( this->m_iDesktopHeight != 0 && this->m_iDesktopWidth != 0 )
        return lRet;
      this->m_iDesktopHeight = HIWORD(lParam);
      result = lRet;
      this->m_iDesktopWidth = (unsigned __int16)lParam;
      break;
    case 0x106u:
      return lRet;
    default:
      return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED4D0
// Name: HLEngineWindowProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall HLEngineWindowProc(HWND__ *hWnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  return CGame::WindowProc(this: &g_Game, hWnd, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x101ED4E0
// Name: public: virtual void CGame::DestroyGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DestroyGameWindow(CGame *this)
{
  if ( this->m_bExternallySuppliedWindow )
  {
    this->m_hWindow = nullptr;
    this->m_bExternallySuppliedWindow = false;
  }
  else
  {
    CGame::DetachFromWindow(this);
    if ( this->m_hWindow != nullptr )
    {
      DestroyWindow(hWnd: this->m_hWindow);
      this->m_hWindow = nullptr;
    }
    UnregisterClassW(lpClassName: L"Valve001", hInstance: this->m_hInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED530
// Name: public: virtual void CGame::SetGameWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetGameWindow(CGame *this, HWND__ *hWnd)
{
  this->m_bExternallySuppliedWindow = true;
  CGame::SetMainWindow(this, window: hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x101ED540
// Name: private: void CGame::AttachToWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::AttachToWindow(CGame *this)
{
  HWND__ *m_hWindow; // eax

  m_hWindow = this->m_hWindow;
  if ( m_hWindow != nullptr )
  {
    this->m_ChainedWindowProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))GetWindowLongW(
                                                                                                hWnd: m_hWindow,
                                                                                                nIndex: -4);
    SetWindowLongW(hWnd: this->m_hWindow, nIndex: -4, dwNewLong: (LONG)HLEngineWindowProc);
    if ( g_pInputSystem != nullptr )
    {
      g_pInputSystem->AttachToWindow(this: g_pInputSystem, a2: this->m_hWindow);
      g_pInputSystem->EnableInput(this: g_pInputSystem, a2: true);
      g_pInputSystem->EnableMessagePump(this: g_pInputSystem, a2: false);
    }
    if ( g_pMatSystemSurface != nullptr )
    {
      g_pMatSystemSurface->SetAppDrivesInput(this: g_pMatSystemSurface, a2: true);
      g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED5D0
// Name: public: virtual bool CGame::InputAttachToGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::InputAttachToGameWindow(CGame *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  int v5; // eax

  if ( this->m_bExternallySuppliedWindow )
  {
    CGame::AttachToWindow(this);
    v2 = g_pVGuiSurface;
    v3 = g_pVGuiSurface->__vftable;
    v4 = videomode->GetModeHeight(this: videomode);
    v5 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v4);
    ((void (__thiscall *)(vgui::ISurface *, int))v3->OnScreenSizeChanged)(a1: v2, a2: v5);
    CGame::AppActivate(this, fActive: true);
    g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED630
// Name: public: virtual void CGame::InputDetachFromGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::InputDetachFromGameWindow(CGame *this)
{
  if ( this->m_bExternallySuppliedWindow && this->m_ChainedWindowProc != nullptr )
  {
    g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: false);
    CGame::AppActivate(this, fActive: false);
    CGame::DetachFromWindow(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED670
// Name: bool UserRequestingMovieSkip(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl UserRequestingMovieSkip()
{
  return g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_ESCAPE)
      || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_SPACE)
      || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_ENTER);
}

//------------------------------------------------------------------------------
// Address: 0x101ED6C0
// Name: public: virtual bool CGame::CreateGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::CreateGameWindow(CGame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  const char *String; // eax
  HICON__ *ImageA; // eax
  HMODULE ModuleHandleA; // eax
  const char *v8; // eax
  int v9; // esi
  int v10; // eax
  DWORD v11; // esi
  int SystemMetrics; // ebx
  int v13; // eax
  DWORD v14; // ecx
  CGame *v15; // edi
  HWND Window; // eax
  wchar_t uc[512]; // [esp+Ch] [ebp-630h] BYREF
  char localPath[260]; // [esp+40Ch] [ebp-230h] BYREF
  char windowName[256]; // [esp+510h] [ebp-12Ch] BYREF
  tagWNDCLASSW wc; // [esp+610h] [ebp-2Ch] BYREF
  CGame *v22; // [esp+638h] [ebp-4h]

  v22 = this;
  windowName[0] = 0;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ModInfo");
  else
    v3 = nullptr;
  if ( g_pFileSystem != nullptr )
    v4 = &g_pFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v3, keyName: "game", defaultValue: defaultValue);
    V_strncpy(pDest: windowName, pSrc: String, maxLen: 256);
  }
  if ( windowName[0] == 0 )
    V_strncpy(pDest: windowName, pSrc: "HALF-LIFE 2", maxLen: 256);
  wc.hInstance = this->m_hInstance;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  memset(&wc.hIcon, 0, 16);
  wc.style = 40;
  wc.lpfnWndProc = CallDefaultWindowProc;
  wc.lpszClassName = L"Valve001";
  if ( g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: "resource/game.ico", a3: localPath, a4: 260) != nullptr )
  {
    g_pFileSystem->GetLocalCopy(this: g_pFileSystem, a2: localPath);
    ImageA = (HICON__ *)LoadImageA(hInst: nullptr, name: localPath, type: 1u, cx: 0, cy: 0, fuLoad: 0x50u);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    ImageA = LoadIconA(hInstance: ModuleHandleA, lpIconName: (LPCSTR)0x65);
  }
  wc.hIcon = ImageA;
  v8 = KeyValues::GetString(this: v3, keyName: "type", defaultValue: defaultValue);
  if ( v8 != nullptr && V_stristr(pStr: v8, pSearch: "multiplayer") != nullptr )
    DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs();
  MultiByteToWideChar(
    CodePage: 0xFDE9u,
    dwFlags: 0,
    lpMultiByteStr: windowName,
    cbMultiByte: -1,
    lpWideCharStr: uc,
    cchWideChar: 512);
  KeyValues::deleteThis(this: v3);
  UnregisterClassW(lpClassName: L"Valve001", hInstance: this->m_hInstance);
  RegisterClassW(lpWndClass: &wc);
  v9 = -2080374784;
  if ( videomode->IsWindowedMode(this: videomode) )
  {
    v10 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-noborder") == 0
      && !videomode->NoWindowBorder(this: videomode) )
    {
      v9 = -2067070976;
    }
  }
  v11 = v9 & 0xFFFEFFFF;
  SystemMetrics = GetSystemMetrics(nIndex: 0);
  v13 = GetSystemMetrics(nIndex: 1);
  v14 = 0;
  if ( g_bTextMode )
  {
    v11 &= ~0x10000000u;
    v14 = 128;
  }
  v15 = v22;
  Window = CreateWindowExW(
             dwExStyle: v14,
             lpClassName: L"Valve001",
             lpWindowName: uc,
             dwStyle: v11,
             X: 0,
             Y: 0,
             nWidth: SystemMetrics,
             nHeight: v13,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: v22->m_hInstance,
             lpParam: nullptr);
  LOWORD(v22) = (unsigned __int16)v22 & 0xFCC0;
  LOWORD(v22) = (unsigned __int16)v22 | 0x23F;
  if ( Window != nullptr )
  {
    CGame::SetMainWindow(this: v15, window: Window);
    CGame::AttachToWindow(this: v15);
    return 1;
  }
  else
  {
    _Error(a1: "Fatal Error:  Unable to create game window!");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED960
// Name: public: virtual void CGame::PlayVideoListAndWait(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::PlayVideoListAndWait(CGame *this, const char *szVideoFileList, BOOL bNeedHealthWarning)
{
  char moviePath[260]; // [esp+4h] [ebp-234h] BYREF
  characterset_t breakSet; // [esp+108h] [ebp-130h] BYREF
  CUtlBuffer vidBuffer; // [esp+208h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &vidBuffer, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szVideoFileList,
         a3: "GAME",
         a4: &vidBuffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    ShowCursor(bShow: false);
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: defaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &vidBuffer,
              pBreaks: &breakSet,
              pTokenBuf: moviePath,
              nMaxLen: 260,
              bParseComments: true) > 0 )
      this->PlayVideoAndWait(this, a2: moviePath, a3: bNeedHealthWarning);
    ShowCursor(bShow: true);
  }
  if ( vidBuffer.m_Memory.m_nGrowSize >= 0 && vidBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vidBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EDA30
// Name: public: CSubtitlePanel::CSubtitlePanel(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSubtitlePanel *__thiscall CSubtitlePanel::CSubtitlePanel(
        CSubtitlePanel *this,
        int parent,
        const char *pMovieName,
        int nPlaybackHeight)
{
  bool v5; // zf
  unsigned int v6; // eax
  vgui::IScheme *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  unsigned int m_hFont; // ecx
  int v11; // edi
  float v12; // xmm1_4
  char captionFilename[96]; // [esp+Ch] [ebp-64h] BYREF
  int height; // [esp+6Ch] [ebp-4h] BYREF

  vgui::Panel::Panel(this, (vgui::Panel *)parent, panelName: "SubtitlePanel");
  this->__vftable = (CSubtitlePanel_vtbl *)&CSubtitlePanel::`vftable';
  this->m_Captions.m_bCaptions = false;
  CUtlBuffer::CUtlBuffer(this: &this->m_Captions.m_CaptionBuf, growSize: 0, initSize: 0, nFlags: 0);
  v5 = this->m_Captions.m_CaptionBuf.m_Put == 0;
  this->m_Captions.m_CaptionStartTime = 0.0;
  *(_WORD *)&this->m_Captions.m_bShowingCaption = 256;
  this->m_Captions.m_CurCaptionString[0] = 0;
  this->m_Captions.m_CurCaptionStartTime = 0.0;
  this->m_Captions.m_CurCaptionEndTime = 0.0;
  this->m_Captions.m_CurCaptionColor = -1;
  if ( !v5 )
    CUtlBuffer::SeekGet(this: &this->m_Captions.m_CaptionBuf, type: SEEK_HEAD, offset: 0);
  v6 = g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/SourceScheme.res",
         a3: "Tracker");
  v7 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v6);
  if ( v7 != nullptr )
    this->m_hFont = v7->GetFont(this: v7, a2: "CloseCaption_IntroMovie", a3: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "SubtitleLabel", wszText: &wszText);
  else
    v9 = nullptr;
  m_hFont = this->m_hFont;
  this->m_pSubtitleLabel = v9;
  v9->SetFont(this: v9, a2: m_hFont);
  v11 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &parent, a3: &height);
  v12 = (float)parent;
  parent = (int)(float)((float)parent * 0.89999998);
  vgui::Panel::SetPos(
    this: this->m_pSubtitleLabel,
    x: (int)(float)(v12 * 0.050000001),
    y: (int)(float)((float)((float)((float)nPlaybackHeight * 0.85000002) - (float)v11)
               - (float)((nPlaybackHeight - height) / 2)));
  vgui::Panel::SetTall(this: this->m_pSubtitleLabel, tall: 2 * v11);
  vgui::Panel::SetWide(this: this->m_pSubtitleLabel, wide: parent);
  this->m_pSubtitleLabel->SetContentAlignment(this: this->m_pSubtitleLabel, a2: a_center);
  vgui::Label::SetCenterWrap(this: this->m_pSubtitleLabel, bWrap: true);
  V_StripExtension(in: pMovieName, out: captionFilename, outSize: 96);
  V_strncat(pDest: captionFilename, pSrc: "_captions.txt", destBufferSize: 0x60u, max_chars_to_copy: -1);
  this->m_Captions.m_bCaptions = false;
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: captionFilename,
         a3: "GAME",
         a4: &this->m_Captions.m_CaptionBuf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/l4d360ui_%language%.txt", a3: "GAME", a4: true);
    this->m_Captions.m_bCaptions = true;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EDC80
// Name: public: bool CCaptionSequencer::GetNextCaption(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCaptionSequencer::GetNextCaption(CCaptionSequencer *this)
{
  char *m_CurCaptionString; // edi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char buff[256]; // [esp+8h] [ebp-100h] BYREF

  m_CurCaptionString = this->m_CurCaptionString;
  if ( this == (CCaptionSequencer *)-60 || this->m_CaptionBuf.m_Error != 0 )
  {
    *m_CurCaptionString = 0;
    return 0;
  }
  else
  {
    CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: this->m_CurCaptionString, nMaxChars: 256);
    v3 = V_stristr(pStr: m_CurCaptionString, pSearch: "\r");
    if ( v3 != nullptr )
      *v3 = 0;
    CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v4 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v4 != nullptr )
        *v4 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    sscanf(string: buff, format: "%x", &this->m_CurCaptionColor);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v5 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v5 != nullptr )
        *v5 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionStartTime = atof(nptr: buff);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v6 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v6 != nullptr )
        *v6 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionEndTime = atof(nptr: buff);
    this->m_bCaptionStale = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDE00
// Name: public: char const __near * CCaptionSequencer::GetCurrentCaption(int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCaptionSequencer::GetCurrentCaption(CCaptionSequencer *this, int *pColorOut)
{
  char *result; // eax
  float elapsed; // [esp+4h] [ebp-4h]

  if ( !this->m_bCaptions || this->m_CaptionStartTime == 0.0 )
    return nullptr;
  elapsed = _Plat_FloatTime() - this->m_CaptionStartTime;
  if ( this->m_bShowingCaption )
    goto LABEL_18;
  if ( this->m_bCaptionStale )
    CCaptionSequencer::GetNextCaption(this);
  if ( this->m_bShowingCaption )
  {
LABEL_18:
    if ( elapsed > this->m_CurCaptionEndTime )
      *(_WORD *)&this->m_bShowingCaption = 256;
  }
  else if ( elapsed > this->m_CurCaptionStartTime )
  {
    this->m_bShowingCaption = true;
  }
  if ( !this->m_bShowingCaption )
    return nullptr;
  result = this->m_CurCaptionString;
  if ( this->m_CurCaptionString[0] == 0 )
    return nullptr;
  if ( pColorOut != nullptr )
    *pColorOut = this->m_CurCaptionColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EDEA0
// Name: public: virtual void CSubtitlePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::Paint(CSubtitlePanel *this)
{
  char *CurrentCaption; // eax
  int v3; // eax
  vgui::Label *m_pSubtitleLabel; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  int nColor; // [esp+4h] [ebp-4h] BYREF

  nColor = -1;
  CurrentCaption = CCaptionSequencer::GetCurrentCaption(this: &this->m_Captions, pColorOut: &nColor);
  this->m_pSubtitleLabel->SetText(this: this->m_pSubtitleLabel, a2: CurrentCaption);
  v3 = nColor;
  LOBYTE(nColor) = HIBYTE(nColor);
  BYTE2(nColor) = BYTE1(v3);
  m_pSubtitleLabel = this->m_pSubtitleLabel;
  BYTE1(nColor) = BYTE2(v3);
  SetFgColor = m_pSubtitleLabel->SetFgColor;
  HIBYTE(nColor) = v3;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pSubtitleLabel, a2: nColor);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101EDF70
// Name: public: virtual void CGame::PlayVideoAndWait(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CGame::PlayVideoAndWait(
        CGame *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *filename,
        bool bNeedHealthWarning)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  IBik *v8; // ebx
  int v9; // eax
  IMaterial *v10; // eax
  IMaterial_vtbl *v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  void (__thiscall *GetFrameSize)(IBik *, unsigned __int16, int *, int *); // edx
  const AspectRatioInfo_t *v16; // eax
  int m_width; // ecx
  int m_height; // edx
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ecx
  int v22; // edx
  float v23; // xmm1_4
  IInputSystem_vtbl *v24; // edx
  CSubtitlePanel *v25; // ebx
  CSubtitlePanel *v26; // eax
  unsigned int v27; // eax
  bool v28; // al
  int v29; // edi
  vgui::ISurface_vtbl *v30; // edi
  int v31; // eax
  char pDest[172]; // [esp+28h] [ebp-150h] BYREF
  _BYTE localPath_88[76]; // [esp+12Ch] [ebp-4Ch] OVERLAPPED BYREF
  void (__thiscall **localPath_172)(CSubtitlePanel *, unsigned int); // [esp+180h] [ebp+8h]
  bool localPath_175; // [esp+183h] [ebp+Bh]

  if ( filename == nullptr
    || *filename == 0
    || g_pBIK == nullptr
    || V_stristr(pStr: filename, pSearch: "RATINGBOARD") != nullptr )
  {
    return;
  }
  BinkSetSoundSystem(a1: BinkOpenDirectSound, a2: 0);
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  *(_DWORD *)&localPath_88[52] = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v8 = g_pBIK;
  *(_DWORD *)&localPath_88[48] = g_pBIK;
  if ( g_pBIK == nullptr )
    goto LABEL_26;
  V_strncpy(pDest, pSrc: filename, maxLen: 260);
  v9 = v8->CreateMaterial(this: v8, a2: "VideoMaterial", a3: pDest, a4: "GAME", a5: 0);
  *(_DWORD *)&localPath_88[64] = v9;
  if ( (_WORD)v9 == 0xFFFF )
    goto LABEL_26;
  ((void (__thiscall *)(IBik *, _DWORD, _BYTE *, _BYTE *, int, int))v8->GetTexCoordRange)(
    a1: v8,
    a2: (unsigned __int16)v9,
    a3: &localPath_88[40],
    a4: &localPath_88[24],
    a5: a2,
    a6: a3);
  v10 = v8->GetMaterial(this: v8, a2: *(_DWORD *)&localPath_88[64]);
  v11 = v10->__vftable;
  *(_DWORD *)&localPath_88[56] = v10;
  v12 = v11->GetMappingHeight(this: v10);
  v13 = **(_DWORD **)&localPath_88[56];
  *(_DWORD *)&localPath_88[32] = v12;
  v14 = (*(int (__thiscall **)(_DWORD))(v13 + 16))(a1: *(_DWORD *)&localPath_88[56]);
  GetFrameSize = v8->GetFrameSize;
  *(_DWORD *)&localPath_88[16] = v14;
  GetFrameSize(this: v8, a2: *(_DWORD *)&localPath_88[64], a3: (int *)&localPath_88[12], a4: (int *)&localPath_88[44]);
  v16 = materials->GetAspectRatioInfo(this: materials);
  m_width = this->m_width;
  m_height = this->m_height;
  v19 = (float)((float)m_width / (float)m_height) * v16->m_flFrameBuffertoPhysicalScalar;
  v20 = (float)*(int *)&localPath_88[12] / (float)*(int *)&localPath_88[44];
  if ( v20 > v19 )
  {
    *(_DWORD *)&localPath_88[68] = (int)(float)((float)((float)m_width / v16->m_flPhysicalToFrameBufferScalar) / v20);
LABEL_14:
    *(_DWORD *)&localPath_88[60] = m_width;
    goto LABEL_15;
  }
  if ( v19 <= v20 )
  {
    *(_DWORD *)&localPath_88[68] = this->m_height;
    goto LABEL_14;
  }
  v21 = this->m_height;
  *(_DWORD *)&localPath_88[60] = (int)(float)((float)((float)m_height * v20) * v16->m_flPhysicalToFrameBufferScalar);
  *(_DWORD *)&localPath_88[68] = v21;
LABEL_15:
  (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)&localPath_88[56] + 116))(
    a1: *(_DWORD *)&localPath_88[56],
    a2: 32,
    a3: 0);
  v7->Viewport(this: v7, a2: 0, a3: 0, a4: this->m_width, a5: this->m_height);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD))v7->DepthRange)(a1: v7, a2: 0.0, a3: 1.0);
  v7->ClearColor3ub(this: v7, a2: 0, a3: 0, a4: 0);
  *(_DWORD *)localPath_88 = 1065353216;
  *(_DWORD *)&localPath_88[4] = 1065353216;
  *(_DWORD *)&localPath_88[8] = 1065353216;
  v7->SetToneMappingScaleLinear(this: v7, a2: (const Vector *)localPath_88);
  v22 = this->m_height - *(_DWORD *)&localPath_88[68];
  *(_DWORD *)&localPath_88[28] = (int)(float)((float)(this->m_width - *(_DWORD *)&localPath_88[60]) * 0.5);
  v23 = (float)v22 * 0.5;
  v24 = g_pInputSystem->__vftable;
  *(_DWORD *)&localPath_88[36] = (int)v23;
  v24->EnableMessagePump(this: g_pInputSystem, a2: true);
  v25 = nullptr;
  localPath_88[75] = ShouldUseCaptioning();
  if ( localPath_88[75] != 0 )
  {
    v26 = (CSubtitlePanel *)MemAlloc_Alloc(nSize: 0x29Cu);
    if ( v26 != nullptr )
      v25 = CSubtitlePanel::CSubtitlePanel(
              this: v26,
              parent: nullptr,
              pMovieName: filename,
              nPlaybackHeight: *(int *)&localPath_88[68]);
    else
      v25 = nullptr;
    localPath_172 = (void (__thiscall **)(CSubtitlePanel *, unsigned int))&v25->SetParent;
    v27 = g_pMatSystemSurface->GetEmbeddedPanel(this: g_pMatSystemSurface);
    (*localPath_172)(a1: v25, a2: v27);
    v25->SetPaintBackgroundEnabled(this: v25, a2: false);
    v25->SetPaintEnabled(this: v25, a2: true);
    vgui::Panel::SetBounds(this: v25, x: 0, y: 0, wide: this->m_width, tall: this->m_height);
    g_pVGui->RunFrame(this: g_pVGui);
    CSubtitlePanel::StartCaptions(this: v25);
  }
  localPath_175 = !UserRequestingMovieSkip();
  while ( 1 )
  {
    g_pInputSystem->PollInputState(this: g_pInputSystem);
    game->DispatchAllStoredGameMessages(this: game);
    v28 = UserRequestingMovieSkip();
    if ( localPath_175 )
      break;
    localPath_175 = !v28;
LABEL_29:
    v29 = *(_DWORD *)&localPath_88[48];
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)&localPath_88[48] + 40))(
           a1: *(_DWORD *)&localPath_88[48],
           a2: *(_DWORD *)&localPath_88[64]) == 0 )
      goto LABEL_24;
    v7->AntiAliasingHint(this: v7, a2: 7);
    v7->ClearBuffers(this: v7, a2: true, a3: true, a4: true);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))v7->DrawScreenSpaceRectangle)(
      a1: v7,
      a2: *(_DWORD *)&localPath_88[56],
      a3: *(_DWORD *)&localPath_88[28],
      a4: *(_DWORD *)&localPath_88[36],
      a5: *(_DWORD *)&localPath_88[60],
      a6: *(_DWORD *)&localPath_88[68],
      a7: (float)*(int *)&localPath_88[16] * 0.0,
      a8: (float)*(int *)&localPath_88[32] * 0.0,
      a9: (float)((float)*(int *)&localPath_88[16] * *(float *)&localPath_88[40]) - 1.0,
      a10: (float)((float)*(int *)&localPath_88[32] * *(float *)&localPath_88[24]) - 1.0,
      a11: *(_DWORD *)&localPath_88[16],
      a12: *(_DWORD *)&localPath_88[32],
      a13: 0,
      a14: 1,
      a15: 1);
    if ( localPath_88[75] != 0 )
    {
      v30 = g_pVGuiSurface->__vftable;
      *(_DWORD *)&localPath_88[20] = g_pVGuiSurface;
      v31 = v25->GetVPanel(this: v25);
      v30->PaintTraverse(this: *(vgui::ISurface **)&localPath_88[20], a2: v31);
    }
    g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
  }
  if ( !v28 )
    goto LABEL_29;
  v29 = *(_DWORD *)&localPath_88[48];
LABEL_24:
  g_pInputSystem->EnableMessagePump(this: g_pInputSystem, a2: false);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v29 + 36))(a1: v29, a2: *(_DWORD *)&localPath_88[64]);
  if ( v25 != nullptr )
    ((void (__thiscall *)(CSubtitlePanel *, int))v25->dtr_Panel)(a1: v25, a2: 1);
LABEL_26:
  CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&localPath_88[52]);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1007A610
// Name: public: virtual bool CGame::IsActiveApp(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGame::IsActiveApp(CDemoActionManager *this)
{
  return this->m_bDirty;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDC0
// Name: public: virtual void __near * __near * CGame::GetMainWindowAddress(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CGame::GetMainWindowAddress(CStaticProp *this)
{
  return &this->ICollideable;
}

//------------------------------------------------------------------------------
// Address: 0x101EC890
// Name: struct InputContextHandle_t__ __near * GetGameInputContext(void)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__cdecl GetGameInputContext()
{
  return g_Game.m_hInputContext;
}

//------------------------------------------------------------------------------
// Address: 0x101EC8A0
// Name: public: void CGame::HandleMsg_WindowMove(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_WindowMove(CGame *this, const InputEvent_t *event)
{
  game->SetWindowXY(this: game, a2: event->m_nData, a3: event->m_nData2);
  videomode->UpdateWindowPosition(this: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x101EC8D0
// Name: public: void CGame::HandleMsg_Close(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_Close(CGame *this, const InputEvent_t *event)
{
  if ( eng->GetState(this: eng) == DLL_ACTIVE )
    eng->SetQuitting(this: eng, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101EC900
// Name: public: virtual void CGame::DispatchAllStoredGameMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DispatchAllStoredGameMessages(CGame *this)
{
  int v2; // edi
  const InputEvent_t *v3; // eax
  const InputEvent_t *v4; // esi
  IEngineVGuiInternal *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // [esp+8h] [ebp-4h]

  v2 = g_pInputSystem->GetEventCount(this: g_pInputSystem);
  v3 = g_pInputSystem->GetEventData(this: g_pInputSystem);
  if ( v2 > 0 )
  {
    v10 = v2;
    v4 = v3;
    do
    {
      switch ( v4->m_nType )
      {
        case 0:
        case 1:
        case 2:
        case 0xCA:
        case 0xCB:
          Key_Event(event: v4);
          break;
        case 3:
          if ( (g_pScaleformUI == nullptr || !g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: v4))
            && (g_pMatSystemSurface == nullptr
             || !g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: v4))
            && g_ClientDLL != nullptr )
          {
            g_ClientDLL->HandleGameUIEvent(this: g_ClientDLL, a2: v4);
          }
          break;
        case 0xD5:
          if ( v4->m_nData == 1 )
          {
            v5 = EngineVGui();
            if ( !v5->IsGameUIVisible(this: v5) && sv.m_State >= ss_active && CBaseServer::IsSinglePlayerGame(this: &sv) )
            {
              TraceType = CTraceFilter::GetTraceType(this: v6);
              Cbuf_AddText(eTarget: TraceType, pText: "gameui_activate", nTickDelay: 0);
            }
          }
          break;
        default:
          if ( (g_pMatSystemSurface == nullptr
             || !g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: v4))
            && (g_pScaleformUI == nullptr || !g_pScaleformUI->HandleInputEvent(this: g_pScaleformUI, a2: v4)) )
          {
            v8 = 0;
            v9 = 0;
            while ( g_GameMessageHandlers[v9].m_nEventType != v4->m_nType )
            {
              ++v9;
              ++v8;
              if ( v9 >= 4 )
                goto LABEL_25;
            }
            ((void (__thiscall *)(char *, const InputEvent_t *))dword_10422B40[6 * v8])(
              a1: (char *)this + dword_10422B44[6 * v8],
              a2: v4);
          }
          break;
      }
LABEL_25:
      ++v4;
      --v10;
    }
    while ( v10 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECB70
// Name: void VCR_EnterPausedState(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VCR_EnterPausedState()
{
  HMODULE LibraryA; // eax
  SHORT (__stdcall *GetAsyncKeyState)(int); // eax
  HANDLE CurrentProcess; // eax

  g_bVCRSingleStep = false;
  if ( (_S1_20 & 1) != 0 )
  {
    LibraryA = hInst;
  }
  else
  {
    _S1_20 |= 1u;
    LibraryA = LoadLibraryA(lpLibFileName: "user32.dll");
    hInst = LibraryA;
  }
  if ( LibraryA != nullptr )
  {
    if ( (_S1_20 & 2) != 0 )
    {
      GetAsyncKeyState = pfn;
    }
    else
    {
      _S1_20 |= 2u;
      GetAsyncKeyState = (SHORT (__stdcall *)(int))GetProcAddress(hModule: LibraryA, lpProcName: "GetAsyncKeyState");
      pfn = GetAsyncKeyState;
    }
    if ( GetAsyncKeyState != nullptr && GetAsyncKeyState(vKey: 82) >= 0 )
    {
      do
      {
        if ( pfn(a1: 81) < 0 )
        {
          CurrentProcess = GetCurrentProcess();
          TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
        }
        if ( pfn(a1: 83) >= 0 )
        {
          g_bWaitingForStepKeyUp = false;
        }
        else if ( !g_bWaitingForStepKeyUp )
        {
          g_bVCRSingleStep = true;
          g_bWaitingForStepKeyUp = true;
          return;
        }
        Sleep(dwMilliseconds: 2u);
      }
      while ( pfn(a1: 82) >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECC60
// Name: CallDefaultWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall CallDefaultWindowProc(HWND__ *hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x101ECC70
// Name: DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs
// Source: json
//------------------------------------------------------------------------------
int DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs()
{
  int result; // eax
  SOCKET v1; // eax
  SOCKET v2; // esi
  struct hostent *v3; // edi
  WSAData wsaData; // [esp+0h] [ebp-2A4h] BYREF
  char pszHostName[256]; // [esp+190h] [ebp-114h] BYREF
  sockaddr_in myIpAddress; // [esp+290h] [ebp-14h] BYREF
  char Options[1]; // [esp+2A3h] [ebp-1h] BYREF

  result = WSAStartup(wVersionRequested: 0x101u, lpWSAData: &wsaData);
  if ( result == 0 )
  {
    v1 = socket(af: 2, type: 2, protocol: 0);
    v2 = v1;
    if ( v1 != -1 )
    {
      Options[0] = 1;
      setsockopt(s: v1, level: 0xFFFF, optname: 32, optval: Options, optlen: 1);
      gethostname(name: pszHostName, namelen: 256);
      v3 = gethostbyname(name: pszHostName);
      if ( v3 != nullptr )
      {
        memset(&myIpAddress.sin_port, 0, 14);
        myIpAddress.sin_family = 2;
        myIpAddress.sin_port = htons(hostshort: 0x6987u);
        myIpAddress.sin_addr.S_un.S_addr = **(_DWORD **)v3->h_addr_list;
        if ( bind(s: v2, name: (const struct sockaddr *)&myIpAddress, namelen: 16) != -1 )
          sendto(s: v2, buf: pszHostName, len: 1, flags: 0, to: (const struct sockaddr *)&myIpAddress, tolen: 16);
      }
      closesocket(s: v2);
    }
    return WSACleanup();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ECD70
// Name: private: void CGame::DetachFromWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DetachFromWindow(CGame *this)
{
  if ( this->m_hWindow != nullptr && this->m_ChainedWindowProc != nullptr )
  {
    if ( g_pMatSystemSurface != nullptr )
      g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
    if ( g_pInputSystem != nullptr )
    {
      g_pInputSystem->EnableInput(this: g_pInputSystem, a2: false);
      g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
    }
    SetWindowLongW(hWnd: this->m_hWindow, nIndex: -4, dwNewLong: (LONG)this->m_ChainedWindowProc);
  }
  else
  {
    this->m_ChainedWindowProc = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECF40
// Name: public: void CSubtitlePanel::StartCaptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::StartCaptions(CSubtitlePanel *this)
{
  int v2; // ecx

  _Plat_FloatTime(a1: this);
  this->m_Captions.m_CaptionStartTime = _Plat_FloatTime(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101ECF60
// Name: bool ShouldUseCaptioning(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldUseCaptioning()
{
  CSteam3Client *v0; // eax
  const char *v1; // eax
  int v2; // esi
  char language[64]; // [esp+0h] [ebp-40h] BYREF

  V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  if ( Steam3Client()->m_pSteamApps != nullptr )
  {
    v0 = Steam3Client();
    v1 = v0->m_pSteamApps->GetCurrentGameLanguage(this: v0->m_pSteamApps);
    V_strncpy(pDest: language, pSrc: v1, maxLen: 64);
  }
  v2 = 0;
  while ( _V_stricmp(s1: language, s2: lpszDubbedLanguages[v2]) != 0 )
  {
    if ( (unsigned int)++v2 >= 5 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101ECFE0
// Name: public: virtual bool CGame::Init(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::Init(CGame *this, HINSTANCE__ *pvInstance)
{
  InputContextHandle_t__ *v4; // eax
  _OSVERSIONINFOA vinfo; // [esp+4h] [ebp-94h] BYREF

  this->m_bExternallySuppliedWindow = false;
  vinfo.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(lpVersionInformation: &vinfo) || vinfo.dwPlatformId == 0 )
    return 0;
  this->m_hInstance = pvInstance;
  v4 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  this->m_hInputContext = v4;
  g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: v4, a3: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED050
// Name: public: virtual bool CGame::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::Shutdown(CGame *this)
{
  if ( this->m_hInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    this->m_hInputContext = nullptr;
  }
  this->m_hInstance = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED080
// Name: public: virtual void CGame::GetDesktopInfo(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::GetDesktopInfo(CGame *this, int *width, int *height, int *refreshrate)
{
  int m_iDesktopWidth; // eax
  HDC DC; // esi

  m_iDesktopWidth = this->m_iDesktopWidth;
  if ( m_iDesktopWidth != 0 )
  {
    *width = m_iDesktopWidth;
    *height = this->m_iDesktopHeight;
    *refreshrate = this->m_iDesktopRefreshRate;
  }
  else
  {
    DC = GetDC(hWnd: nullptr);
    *width = GetDeviceCaps(hdc: DC, index: 8);
    *height = GetDeviceCaps(hdc: DC, index: 10);
    *refreshrate = GetDeviceCaps(hdc: DC, index: 116);
    ReleaseDC(hWnd: nullptr, hDC: DC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED0F0
// Name: public: void CGame::SetMainWindow(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetMainWindow(CGame *this, HWND__ *window)
{
  HWND__ *m_hWindow; // ebx
  HDC DC; // edi

  this->m_hWindow = window;
  avi->SetMainWindow(this: avi, a2: window);
  if ( this->m_iDesktopWidth == 0 || this->m_iDesktopHeight == 0 )
  {
    m_hWindow = this->m_hWindow;
    DC = GetDC(hWnd: m_hWindow);
    this->m_iDesktopWidth = GetDeviceCaps(hdc: DC, index: 8);
    this->m_iDesktopHeight = GetDeviceCaps(hdc: DC, index: 10);
    this->m_iDesktopRefreshRate = GetDeviceCaps(hdc: DC, index: 116);
    ReleaseDC(hWnd: m_hWindow, hDC: DC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED160
// Name: public: virtual void CGame::SetWindowSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetWindowSize(CGame *this, int w, int h)
{
  this->m_width = w;
  this->m_height = h;
}

//------------------------------------------------------------------------------
// Address: 0x101ED180
// Name: public: virtual void CGame::GetWindowRect(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::GetWindowRect(CGame *this, int *x, int *y, int *w, int *h)
{
  if ( x != nullptr )
    *x = this->m_x;
  if ( y != nullptr )
    *y = this->m_y;
  if ( w != nullptr )
    *w = this->m_width;
  if ( h != nullptr )
    *h = this->m_height;
}

//------------------------------------------------------------------------------
// Address: 0x101ED1C0
// Name: public: virtual void CGame::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::OnScreenSizeChanged(CGame *this, int nOldWidth, int nOldHeight)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->OnScreenSizeChanged(this: g_ClientDLL, a2: nOldWidth, a3: nOldHeight);
}

//------------------------------------------------------------------------------
// Address: 0x101ED1E0
// Name: private: void CGame::AppActivate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::AppActivate(CGame *this, bool fActive)
{
  bool v3; // bl
  IVideoMode_vtbl *v4; // eax
  void (*RestoreVideo)(void); // edx

  v3 = true;
  if ( !g_bTextMode )
    v3 = fActive;
  if ( this->IsActiveApp(this) != v3 )
  {
    this->m_bCanPostActivateEvents = false;
    if ( videomode != nullptr )
    {
      v4 = videomode->__vftable;
      if ( v3 )
        RestoreVideo = (void (*)(void))v4->RestoreVideo;
      else
        RestoreVideo = (void (*)(void))v4->ReleaseVideo;
      RestoreVideo();
    }
    if ( host_initialized )
    {
      ClearIOStates();
      if ( v3 )
      {
        UpdateMaterialSystemConfig();
        this->m_bActiveApp = v3;
        this->m_bCanPostActivateEvents = true;
        return;
      }
      if ( g_ClientDLL != nullptr )
        g_ClientDLL->IN_DeactivateMouse(this: g_ClientDLL);
    }
    this->m_bActiveApp = v3;
    this->m_bCanPostActivateEvents = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED260
// Name: public: void CGame::HandleMsg_ActivateApp(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::HandleMsg_ActivateApp(CGame *this, const InputEvent_t *event)
{
  CGame::AppActivate(this, fActive: event->m_nData != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101ED280
// Name: public: int CGame::WindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGame::WindowProc(CGame *this, HWND__ *hWnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  int (__thiscall *GetQuitting)(IEngine *); // edx
  int result; // eax
  vgui::CTreeViewListControl *v8; // ecx
  int v9; // eax
  DWORD WindowLongA; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t v13; // eax
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t v15; // eax
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t v17; // eax
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v19; // ecx
  ECommandTarget_t v20; // eax
  vgui::CTreeViewListControl *v21; // [esp-10h] [ebp-8Ch]
  tagPAINTSTRUCT ps; // [esp+4h] [ebp-78h] BYREF
  InputEvent_t event; // [esp+44h] [ebp-38h] BYREF
  tagRECT rcClient; // [esp+58h] [ebp-24h] BYREF
  tagRECT rcWindow; // [esp+68h] [ebp-14h] BYREF
  int lRet; // [esp+78h] [ebp-4h]

  GetQuitting = eng->GetQuitting;
  lRet = 0;
  if ( GetQuitting(this: eng) != 0 )
    return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  memset((void *)&event, 0, sizeof(event));
  event.m_nTick = g_pInputSystem->GetPollTick(this: g_pInputSystem);
  if ( uMsg <= 0xF )
  {
    if ( uMsg == 15 )
    {
      BeginPaint(hWnd, lpPaint: &ps);
      GetClientRect(hWnd, lpRect: &rcClient);
      EndPaint(hWnd, lpPaint: &ps);
      return lRet;
    }
    else
    {
      switch ( uMsg )
      {
        case 1u:
          SetForegroundWindow(hWnd);
          result = lRet;
          break;
        case 3u:
          event.m_nType = 2000;
          event.m_nData = (__int16)lParam;
          event.m_nData2 = SHIWORD(lParam);
          goto LABEL_8;
        case 5u:
          if ( wParam == 1 )
          {
            GetWindowRect(hWnd, lpRect: &rcWindow);
            v9 = rcWindow.top + this->m_rcLastRestoredClientRect.bottom;
            rcWindow.right = rcWindow.left + this->m_rcLastRestoredClientRect.right;
            rcWindow.bottom = v9;
            WindowLongA = GetWindowLongA(hWnd, nIndex: -16);
            AdjustWindowRect(lpRect: &rcWindow, dwStyle: WindowLongA, bMenu: false);
            MoveWindow(
              hWnd,
              X: rcWindow.left,
              Y: rcWindow.top,
              nWidth: rcWindow.right - rcWindow.left,
              nHeight: rcWindow.bottom - rcWindow.top,
              bRepaint: false);
          }
          else
          {
            GetClientRect(hWnd, lpRect: &this->m_rcLastRestoredClientRect);
          }
          result = lRet;
          break;
        case 7u:
          if ( g_pHammer == nullptr )
            return lRet;
          g_pHammer->NoteEngineGotFocus(this: g_pHammer);
          result = lRet;
          break;
        default:
          return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
      }
    }
    return result;
  }
  if ( uMsg > 0x112 )
  {
    switch ( uMsg )
    {
      case 0x218u:
        if ( wParam == 0 )
        {
          _Msg(a1: "OS requested hibernation, ignoring request.\n");
          return 1112363332;
        }
        break;
      case 0x282u:
        if ( wParam == 14 && !videomode->IsWindowedMode(this: videomode) )
          return 0;
        break;
      case 0x47Cu:
        TraceType = CTraceFilter::GetTraceType(this: v8);
        Cbuf_Clear(eTarget: TraceType);
        v20 = CTraceFilter::GetTraceType(this: v19);
        Cbuf_AddText(eTarget: v20, pText: "quit_gameconsole\n", nTickDelay: 0);
        return lRet;
      default:
        break;
    }
    return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  }
  if ( uMsg == 274 )
  {
    if ( wParam != 61808 && wParam != 61696 && wParam != 61760 )
    {
      if ( wParam != 61536 )
      {
LABEL_32:
        S_BlockSound();
        S_ClearBuffer();
        lRet = CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: 0x112u, wParam, lParam);
        S_UnblockSound();
        return lRet;
      }
      if ( (unsigned __int16)GetKeyState(nVirtKey: 164) >> 8 == 0
        && (unsigned __int16)GetKeyState(nVirtKey: 165) >> 8 == 0 )
      {
        v15 = CTraceFilter::GetTraceType(this: v14);
        Cbuf_Clear(eTarget: v15);
        v17 = CTraceFilter::GetTraceType(this: v16);
        Cbuf_AddText(eTarget: v17, pText: "quit\n", nTickDelay: 0);
        goto LABEL_32;
      }
    }
    return 0;
  }
  switch ( uMsg )
  {
    case 0x1Cu:
      if ( !this->m_bCanPostActivateEvents )
        return lRet;
      event.m_nType = 2001;
      event.m_nData = wParam == 1;
LABEL_8:
      g_pInputSystem->PostUserEvent(this: g_pInputSystem, a2: &event);
      result = lRet;
      break;
    case 0x4Au:
      v21 = *(vgui::CTreeViewListControl **)(lParam + 8);
      v11 = CTraceFilter::GetTraceType(this: v21);
      Cbuf_AddText(eTarget: v11, pText: (const char *)v21, nTickDelay: 0);
      v13 = CTraceFilter::GetTraceType(this: v12);
      Cbuf_AddText(eTarget: v13, pText: "\n", nTickDelay: 0);
      lRet = 1;
      result = 1;
      break;
    case 0x7Eu:
      if ( this->m_iDesktopHeight != 0 && this->m_iDesktopWidth != 0 )
        return lRet;
      this->m_iDesktopHeight = HIWORD(lParam);
      result = lRet;
      this->m_iDesktopWidth = (unsigned __int16)lParam;
      break;
    case 0x106u:
      return lRet;
    default:
      return CallWindowProcA(lpPrevWndFunc: this->m_ChainedWindowProc, hWnd, Msg: uMsg, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED760
// Name: HLEngineWindowProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall HLEngineWindowProc(HWND__ *hWnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  return CGame::WindowProc(this: &g_Game, hWnd, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x101ED770
// Name: public: virtual void CGame::DestroyGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::DestroyGameWindow(CGame *this)
{
  if ( this->m_bExternallySuppliedWindow )
  {
    this->m_hWindow = nullptr;
    this->m_bExternallySuppliedWindow = false;
  }
  else
  {
    CGame::DetachFromWindow(this);
    if ( this->m_hWindow != nullptr )
    {
      DestroyWindow(hWnd: this->m_hWindow);
      this->m_hWindow = nullptr;
    }
    UnregisterClassW(lpClassName: L"Valve001", hInstance: this->m_hInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED7C0
// Name: public: virtual void CGame::SetGameWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetGameWindow(CGame *this, HWND__ *hWnd)
{
  this->m_bExternallySuppliedWindow = true;
  CGame::SetMainWindow(this, window: hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x101ED7D0
// Name: private: void CGame::AttachToWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::AttachToWindow(CGame *this)
{
  HWND__ *m_hWindow; // eax

  m_hWindow = this->m_hWindow;
  if ( m_hWindow != nullptr )
  {
    this->m_ChainedWindowProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))GetWindowLongW(
                                                                                                hWnd: m_hWindow,
                                                                                                nIndex: -4);
    SetWindowLongW(hWnd: this->m_hWindow, nIndex: -4, dwNewLong: (LONG)HLEngineWindowProc);
    if ( g_pInputSystem != nullptr )
    {
      g_pInputSystem->AttachToWindow(this: g_pInputSystem, a2: this->m_hWindow);
      g_pInputSystem->EnableInput(this: g_pInputSystem, a2: true);
      g_pInputSystem->EnableMessagePump(this: g_pInputSystem, a2: false);
    }
    if ( g_pMatSystemSurface != nullptr )
    {
      g_pMatSystemSurface->SetAppDrivesInput(this: g_pMatSystemSurface, a2: true);
      g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED860
// Name: public: virtual bool CGame::InputAttachToGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::InputAttachToGameWindow(CGame *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  int v5; // eax

  if ( this->m_bExternallySuppliedWindow )
  {
    CGame::AttachToWindow(this);
    v2 = g_pVGuiSurface;
    v3 = g_pVGuiSurface->__vftable;
    v4 = videomode->GetModeHeight(this: videomode);
    v5 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v4);
    ((void (__thiscall *)(vgui::ISurface *, int))v3->OnScreenSizeChanged)(a1: v2, a2: v5);
    CGame::AppActivate(this, fActive: true);
    g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED8C0
// Name: public: virtual void CGame::InputDetachFromGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::InputDetachFromGameWindow(CGame *this)
{
  if ( this->m_bExternallySuppliedWindow && this->m_ChainedWindowProc != nullptr )
  {
    g_pInputStackSystem->SetMouseCapture(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: false);
    CGame::AppActivate(this, fActive: false);
    CGame::DetachFromWindow(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ED900
// Name: bool UserRequestingMovieSkip(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl UserRequestingMovieSkip()
{
  return g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_ESCAPE)
      || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_SPACE)
      || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_ENTER);
}

//------------------------------------------------------------------------------
// Address: 0x101ED980
// Name: public: virtual bool CGame::CreateGameWindow(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGame::CreateGameWindow(CGame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  const char *String; // eax
  HICON__ *ImageA; // eax
  HMODULE ModuleHandleA; // eax
  const char *v8; // eax
  int v9; // esi
  int v10; // eax
  DWORD v11; // esi
  int SystemMetrics; // ebx
  int v13; // eax
  DWORD v14; // ecx
  CGame *v15; // edi
  HWND Window; // eax
  wchar_t uc[512]; // [esp+Ch] [ebp-630h] BYREF
  char localPath[260]; // [esp+40Ch] [ebp-230h] BYREF
  char windowName[256]; // [esp+510h] [ebp-12Ch] BYREF
  tagWNDCLASSW wc; // [esp+610h] [ebp-2Ch] BYREF
  CGame *v22; // [esp+638h] [ebp-4h]

  v22 = this;
  windowName[0] = 0;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ModInfo");
  else
    v3 = nullptr;
  if ( g_pFileSystem != nullptr )
    v4 = &g_pFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v3, keyName: "game", defaultValue: defaultValue);
    V_strncpy(pDest: windowName, pSrc: String, maxLen: 256);
  }
  if ( windowName[0] == 0 )
    V_strncpy(pDest: windowName, pSrc: "HALF-LIFE 2", maxLen: 256);
  wc.hInstance = this->m_hInstance;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  memset(&wc.hIcon, 0, 16);
  wc.style = 40;
  wc.lpfnWndProc = CallDefaultWindowProc;
  wc.lpszClassName = L"Valve001";
  if ( g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: "resource/game.ico", a3: localPath, a4: 260) != nullptr )
  {
    g_pFileSystem->GetLocalCopy(this: g_pFileSystem, a2: localPath);
    ImageA = (HICON__ *)LoadImageA(hInst: nullptr, name: localPath, type: 1u, cx: 0, cy: 0, fuLoad: 0x50u);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    ImageA = LoadIconA(hInstance: ModuleHandleA, lpIconName: (LPCSTR)0x65);
  }
  wc.hIcon = ImageA;
  v8 = KeyValues::GetString(this: v3, keyName: "type", defaultValue: defaultValue);
  if ( v8 != nullptr && V_stristr(pStr: v8, pSearch: "multiplayer") != nullptr )
    DoSomeSocketStuffInOrderToGetZoneAlarmToNoticeUs();
  MultiByteToWideChar(
    CodePage: 0xFDE9u,
    dwFlags: 0,
    lpMultiByteStr: windowName,
    cbMultiByte: -1,
    lpWideCharStr: uc,
    cchWideChar: 512);
  KeyValues::deleteThis(this: v3);
  UnregisterClassW(lpClassName: L"Valve001", hInstance: this->m_hInstance);
  RegisterClassW(lpWndClass: &wc);
  v9 = -2080374784;
  if ( videomode->IsWindowedMode(this: videomode) )
  {
    v10 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-noborder") == 0
      && !videomode->NoWindowBorder(this: videomode) )
    {
      v9 = -2067070976;
    }
  }
  v11 = v9 & 0xFFFEFFFF;
  SystemMetrics = GetSystemMetrics(nIndex: 0);
  v13 = GetSystemMetrics(nIndex: 1);
  v14 = 0;
  if ( g_bTextMode )
  {
    v11 &= ~0x10000000u;
    v14 = 128;
  }
  v15 = v22;
  Window = CreateWindowExW(
             dwExStyle: v14,
             lpClassName: L"Valve001",
             lpWindowName: uc,
             dwStyle: v11,
             X: 0,
             Y: 0,
             nWidth: SystemMetrics,
             nHeight: v13,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: v22->m_hInstance,
             lpParam: nullptr);
  LOWORD(v22) = (unsigned __int16)v22 & 0xFCC0;
  LOWORD(v22) = (unsigned __int16)v22 | 0x23F;
  if ( Window != nullptr )
  {
    CGame::SetMainWindow(this: v15, window: Window);
    CGame::AttachToWindow(this: v15);
    return 1;
  }
  else
  {
    _Error(a1: "Fatal Error:  Unable to create game window!");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDC20
// Name: public: virtual void CGame::PlayVideoListAndWait(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::PlayVideoListAndWait(CGame *this, const char *szVideoFileList, BOOL bNeedHealthWarning)
{
  char moviePath[260]; // [esp+4h] [ebp-234h] BYREF
  characterset_t breakSet; // [esp+108h] [ebp-130h] BYREF
  CUtlBuffer vidBuffer; // [esp+208h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &vidBuffer, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szVideoFileList,
         a3: "GAME",
         a4: &vidBuffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    ShowCursor(bShow: false);
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: defaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &vidBuffer,
              pBreaks: &breakSet,
              pTokenBuf: moviePath,
              nMaxLen: 260,
              bParseComments: true) > 0 )
      this->PlayVideoAndWait(this, a2: moviePath, a3: bNeedHealthWarning);
    ShowCursor(bShow: true);
  }
  if ( vidBuffer.m_Memory.m_nGrowSize >= 0 && vidBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vidBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EDCF0
// Name: public: CSubtitlePanel::CSubtitlePanel(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSubtitlePanel *__thiscall CSubtitlePanel::CSubtitlePanel(
        CSubtitlePanel *this,
        int parent,
        const char *pMovieName,
        int nPlaybackHeight)
{
  bool v5; // zf
  unsigned int v6; // eax
  vgui::IScheme *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  unsigned int m_hFont; // ecx
  int v11; // edi
  float v12; // xmm1_4
  char captionFilename[96]; // [esp+Ch] [ebp-64h] BYREF
  int height; // [esp+6Ch] [ebp-4h] BYREF

  vgui::Panel::Panel(this, (vgui::Panel *)parent, panelName: "SubtitlePanel");
  this->__vftable = (CSubtitlePanel_vtbl *)&CSubtitlePanel::`vftable';
  this->m_Captions.m_bCaptions = false;
  CUtlBuffer::CUtlBuffer(this: &this->m_Captions.m_CaptionBuf, growSize: 0, initSize: 0, nFlags: 0);
  v5 = this->m_Captions.m_CaptionBuf.m_Put == 0;
  this->m_Captions.m_CaptionStartTime = 0.0;
  *(_WORD *)&this->m_Captions.m_bShowingCaption = 256;
  this->m_Captions.m_CurCaptionString[0] = 0;
  this->m_Captions.m_CurCaptionStartTime = 0.0;
  this->m_Captions.m_CurCaptionEndTime = 0.0;
  this->m_Captions.m_CurCaptionColor = -1;
  if ( !v5 )
    CUtlBuffer::SeekGet(this: &this->m_Captions.m_CaptionBuf, type: SEEK_HEAD, offset: 0);
  v6 = g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/SourceScheme.res",
         a3: "Tracker");
  v7 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v6);
  if ( v7 != nullptr )
    this->m_hFont = v7->GetFont(this: v7, a2: "CloseCaption_IntroMovie", a3: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "SubtitleLabel", wszText: &wszText);
  else
    v9 = nullptr;
  m_hFont = this->m_hFont;
  this->m_pSubtitleLabel = v9;
  v9->SetFont(this: v9, a2: m_hFont);
  v11 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &parent, a3: &height);
  v12 = (float)parent;
  parent = (int)(float)((float)parent * 0.89999998);
  vgui::Panel::SetPos(
    this: this->m_pSubtitleLabel,
    x: (int)(float)(v12 * 0.050000001),
    y: (int)(float)((float)((float)((float)nPlaybackHeight * 0.85000002) - (float)v11)
               - (float)((nPlaybackHeight - height) / 2)));
  vgui::Panel::SetTall(this: this->m_pSubtitleLabel, tall: 2 * v11);
  vgui::Panel::SetWide(this: this->m_pSubtitleLabel, wide: parent);
  this->m_pSubtitleLabel->SetContentAlignment(this: this->m_pSubtitleLabel, a2: a_center);
  vgui::Label::SetCenterWrap(this: this->m_pSubtitleLabel, bWrap: true);
  V_StripExtension(in: pMovieName, out: captionFilename, outSize: 96);
  V_strncat(pDest: captionFilename, pSrc: "_captions.txt", destBufferSize: 0x60u, max_chars_to_copy: -1);
  this->m_Captions.m_bCaptions = false;
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: captionFilename,
         a3: "GAME",
         a4: &this->m_Captions.m_CaptionBuf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/l4d360ui_%language%.txt", a3: "GAME", a4: true);
    this->m_Captions.m_bCaptions = true;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EDF40
// Name: public: bool CCaptionSequencer::GetNextCaption(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCaptionSequencer::GetNextCaption(CCaptionSequencer *this)
{
  char *m_CurCaptionString; // edi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char buff[256]; // [esp+8h] [ebp-100h] BYREF

  m_CurCaptionString = this->m_CurCaptionString;
  if ( this == (CCaptionSequencer *)-60 || this->m_CaptionBuf.m_Error != 0 )
  {
    *m_CurCaptionString = 0;
    return 0;
  }
  else
  {
    CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: this->m_CurCaptionString, nMaxChars: 256);
    v3 = V_stristr(pStr: m_CurCaptionString, pSearch: "\r");
    if ( v3 != nullptr )
      *v3 = 0;
    CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v4 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v4 != nullptr )
        *v4 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    sscanf(string: buff, format: "%x", &this->m_CurCaptionColor);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v5 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v5 != nullptr )
        *v5 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionStartTime = atof(nptr: buff);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v6 = V_stristr(pStr: buff, pSearch: "\r");
      if ( v6 != nullptr )
        *v6 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionEndTime = atof(nptr: buff);
    this->m_bCaptionStale = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE0C0
// Name: public: char const __near * CCaptionSequencer::GetCurrentCaption(int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCaptionSequencer::GetCurrentCaption(CCaptionSequencer *this, int *pColorOut)
{
  char *result; // eax
  float elapsed; // [esp+4h] [ebp-4h]

  if ( !this->m_bCaptions || this->m_CaptionStartTime == 0.0 )
    return nullptr;
  elapsed = _Plat_FloatTime(a1: this) - this->m_CaptionStartTime;
  if ( this->m_bShowingCaption )
    goto LABEL_18;
  if ( this->m_bCaptionStale )
    CCaptionSequencer::GetNextCaption(this);
  if ( this->m_bShowingCaption )
  {
LABEL_18:
    if ( elapsed > this->m_CurCaptionEndTime )
      *(_WORD *)&this->m_bShowingCaption = 256;
  }
  else if ( elapsed > this->m_CurCaptionStartTime )
  {
    this->m_bShowingCaption = true;
  }
  if ( !this->m_bShowingCaption )
    return nullptr;
  result = this->m_CurCaptionString;
  if ( this->m_CurCaptionString[0] == 0 )
    return nullptr;
  if ( pColorOut != nullptr )
    *pColorOut = this->m_CurCaptionColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EE160
// Name: public: virtual void CSubtitlePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::Paint(CSubtitlePanel *this)
{
  char *CurrentCaption; // eax
  int v3; // eax
  vgui::Label *m_pSubtitleLabel; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  int nColor; // [esp+4h] [ebp-4h] BYREF

  nColor = -1;
  CurrentCaption = CCaptionSequencer::GetCurrentCaption(this: &this->m_Captions, pColorOut: &nColor);
  this->m_pSubtitleLabel->SetText(this: this->m_pSubtitleLabel, a2: CurrentCaption);
  v3 = nColor;
  LOBYTE(nColor) = HIBYTE(nColor);
  BYTE2(nColor) = BYTE1(v3);
  m_pSubtitleLabel = this->m_pSubtitleLabel;
  BYTE1(nColor) = BYTE2(v3);
  SetFgColor = m_pSubtitleLabel->SetFgColor;
  HIBYTE(nColor) = v3;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pSubtitleLabel, a2: nColor);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101EE230
// Name: public: virtual void CGame::PlayVideoAndWait(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGame::PlayVideoAndWait(
        CGame *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *filename,
        bool bNeedHealthWarning)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  IBik *v8; // ebx
  int v9; // eax
  IMaterial *v10; // eax
  IMaterial v11; // edx
  int v12; // eax
  IMaterial_vtbl *v13; // edx
  int v14; // eax
  void (__thiscall *GetFrameSize)(IBik *, unsigned __int16, int *, int *); // edx
  const AspectRatioInfo_t *v16; // eax
  int m_width; // ecx
  int m_height; // edx
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ecx
  int v22; // edx
  float v23; // xmm1_4
  IInputSystem_vtbl *v24; // edx
  CSubtitlePanel *v25; // ebx
  CSubtitlePanel *v26; // eax
  unsigned int v27; // eax
  bool v28; // al
  IBik *v29; // edi
  vgui::ISurface_vtbl *v30; // edi
  int v31; // eax
  char localPath[260]; // [esp+B0h] [ebp-150h] BYREF
  _DWORD v35[3]; // [esp+1B4h] [ebp-4Ch] BYREF
  int nWidth; // [esp+1C0h] [ebp-40h] BYREF
  int nTexWidth; // [esp+1C4h] [ebp-3Ch]
  vgui::ISurface *v38; // [esp+1C8h] [ebp-38h]
  float flV1; // [esp+1CCh] [ebp-34h] BYREF
  int xpos; // [esp+1D0h] [ebp-30h]
  int nTexHeight; // [esp+1D4h] [ebp-2Ch]
  int ypos; // [esp+1D8h] [ebp-28h]
  float flU1; // [esp+1DCh] [ebp-24h] BYREF
  int nHeight; // [esp+1E0h] [ebp-20h] BYREF
  IBik *pVideoPlayer; // [esp+1E4h] [ebp-1Ch]
  CMatRenderContextPtr pRenderContext; // [esp+1E8h] [ebp-18h] BYREF
  IMaterial *pMaterial; // [esp+1ECh] [ebp-14h]
  int nPlaybackWidth; // [esp+1F0h] [ebp-10h]
  int VideoHandle; // [esp+1F4h] [ebp-Ch]
  int nPlaybackHeight; // [esp+1F8h] [ebp-8h]
  bool bUseCaptioning; // [esp+1FFh] [ebp-1h]
  void (__thiscall **bKeyDebounced)(CSubtitlePanel *, unsigned int); // [esp+208h] [ebp+8h]
  bool bKeyDebounced_3; // [esp+20Bh] [ebp+Bh]

  if ( filename == nullptr
    || *filename == 0
    || g_pBIK == nullptr
    || V_stristr(pStr: filename, pSearch: "RATINGBOARD") != nullptr )
  {
    return;
  }
  BinkSetSoundSystem(a1: BinkOpenDirectSound, a2: 0);
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  pRenderContext.m_pObject = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v8 = g_pBIK;
  pVideoPlayer = g_pBIK;
  if ( g_pBIK == nullptr )
    goto LABEL_26;
  V_strncpy(pDest: localPath, pSrc: filename, maxLen: 260);
  v9 = v8->CreateMaterial(this: v8, a2: "VideoMaterial", a3: localPath, a4: "GAME", a5: 0);
  VideoHandle = v9;
  if ( (_WORD)v9 == 0xFFFF )
    goto LABEL_26;
  ((void (__thiscall *)(IBik *, _DWORD, float *, float *, int, int))v8->GetTexCoordRange)(
    a1: v8,
    a2: (unsigned __int16)v9,
    a3: &flU1,
    a4: &flV1,
    a5: a2,
    a6: a3);
  v10 = v8->GetMaterial(this: v8, a2: VideoHandle);
  v11.__vftable = v10->__vftable;
  pMaterial = v10;
  v12 = v11.GetMappingHeight(this: v10);
  v13 = pMaterial->__vftable;
  nTexHeight = v12;
  v14 = v13->GetMappingWidth(this: pMaterial);
  GetFrameSize = v8->GetFrameSize;
  nTexWidth = v14;
  GetFrameSize(this: v8, a2: VideoHandle, a3: &nWidth, a4: &nHeight);
  v16 = materials->GetAspectRatioInfo(this: materials);
  m_width = this->m_width;
  m_height = this->m_height;
  v19 = (float)((float)m_width / (float)m_height) * v16->m_flFrameBuffertoPhysicalScalar;
  v20 = (float)nWidth / (float)nHeight;
  if ( v20 > v19 )
  {
    nPlaybackHeight = (int)(float)((float)((float)m_width / v16->m_flPhysicalToFrameBufferScalar) / v20);
LABEL_14:
    nPlaybackWidth = m_width;
    goto LABEL_15;
  }
  if ( v19 <= v20 )
  {
    nPlaybackHeight = this->m_height;
    goto LABEL_14;
  }
  v21 = this->m_height;
  nPlaybackWidth = (int)(float)((float)((float)m_height * v20) * v16->m_flPhysicalToFrameBufferScalar);
  nPlaybackHeight = v21;
LABEL_15:
  pMaterial->SetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_VERTEXALPHA, a3: false);
  v7->Viewport(this: v7, a2: 0, a3: 0, a4: this->m_width, a5: this->m_height);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD))v7->DepthRange)(a1: v7, a2: 0.0, a3: 1.0);
  v7->ClearColor3ub(this: v7, a2: 0, a3: 0, a4: 0);
  v35[0] = 1065353216;
  v35[1] = 1065353216;
  v35[2] = 1065353216;
  v7->SetToneMappingScaleLinear(this: v7, a2: (const Vector *)v35);
  v22 = this->m_height - nPlaybackHeight;
  xpos = (int)(float)((float)(this->m_width - nPlaybackWidth) * 0.5);
  v23 = (float)v22 * 0.5;
  v24 = g_pInputSystem->__vftable;
  ypos = (int)v23;
  v24->EnableMessagePump(this: g_pInputSystem, a2: true);
  v25 = nullptr;
  bUseCaptioning = ShouldUseCaptioning();
  if ( bUseCaptioning )
  {
    v26 = (CSubtitlePanel *)MemAlloc_Alloc(nSize: 0x29Cu);
    if ( v26 != nullptr )
      v25 = CSubtitlePanel::CSubtitlePanel(this: v26, parent: 0, pMovieName: filename, nPlaybackHeight);
    else
      v25 = nullptr;
    bKeyDebounced = (void (__thiscall **)(CSubtitlePanel *, unsigned int))&v25->SetParent;
    v27 = g_pMatSystemSurface->GetEmbeddedPanel(this: g_pMatSystemSurface);
    (*bKeyDebounced)(a1: v25, a2: v27);
    v25->SetPaintBackgroundEnabled(this: v25, a2: false);
    v25->SetPaintEnabled(this: v25, a2: true);
    vgui::Panel::SetBounds(this: v25, x: 0, y: 0, wide: this->m_width, tall: this->m_height);
    g_pVGui->RunFrame(this: g_pVGui);
    CSubtitlePanel::StartCaptions(this: v25);
  }
  bKeyDebounced_3 = !UserRequestingMovieSkip();
  while ( 1 )
  {
    g_pInputSystem->PollInputState(this: g_pInputSystem);
    game->DispatchAllStoredGameMessages(this: game);
    v28 = UserRequestingMovieSkip();
    if ( bKeyDebounced_3 )
      break;
    bKeyDebounced_3 = !v28;
LABEL_29:
    v29 = pVideoPlayer;
    if ( !pVideoPlayer->Update(this: pVideoPlayer, a2: VideoHandle) )
      goto LABEL_24;
    v7->AntiAliasingHint(this: v7, a2: 7);
    v7->ClearBuffers(this: v7, a2: true, a3: true, a4: true);
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, int, int))v7->DrawScreenSpaceRectangle)(
      a1: v7,
      a2: pMaterial,
      a3: xpos,
      a4: ypos,
      a5: nPlaybackWidth,
      a6: nPlaybackHeight,
      a7: (float)nTexWidth * 0.0,
      a8: (float)nTexHeight * 0.0,
      a9: (float)((float)nTexWidth * flU1) - 1.0,
      a10: (float)((float)nTexHeight * flV1) - 1.0,
      a11: nTexWidth,
      a12: nTexHeight,
      a13: 0,
      a14: 1,
      a15: 1);
    if ( bUseCaptioning )
    {
      v30 = g_pVGuiSurface->__vftable;
      v38 = g_pVGuiSurface;
      v31 = v25->GetVPanel(this: v25);
      v30->PaintTraverse(this: v38, a2: v31);
    }
    g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
  }
  if ( !v28 )
    goto LABEL_29;
  v29 = pVideoPlayer;
LABEL_24:
  g_pInputSystem->EnableMessagePump(this: g_pInputSystem, a2: false);
  v29->DestroyMaterial(this: v29, a2: VideoHandle);
  if ( v25 != nullptr )
    ((void (__thiscall *)(CSubtitlePanel *, int))v25->dtr_Panel)(a1: v25, a2: 1);
LABEL_26:
  CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x1026CE50
// Name: public: virtual void CGame::SetWindowXY(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGame::SetWindowXY(
        CUtlBuffer *this,
        bool (__thiscall *getFunc)(CUtlBuffer *this, int),
        bool (__thiscall *putFunc)(CUtlBuffer *this, int))
{
  this->m_GetOverflowFunc = getFunc;
  this->m_PutOverflowFunc = putFunc;
}

} // namespace engine_xlsp
