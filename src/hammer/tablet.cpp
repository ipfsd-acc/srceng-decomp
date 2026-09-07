// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/tablet.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100B32A0
// Name: bool WinTab_Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WinTab_Init()
{
  UINT v0; // edi

  v0 = (unsigned __int16)SetErrorMode(uMode: 0x8001u);
  bWinTabAvailable = WTInfoA(a1: 0, a2: 0, a3: 0) != 0;
  SetErrorMode(uMode: v0);
  m_flLastPressure = 1.0;
  return bWinTabAvailable;
}

//------------------------------------------------------------------------------
// Address: 0x100B32F0
// Name: void WinTab_Open(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WinTab_Open(HWND__ *hWnd)
{
  if ( bWinTabAvailable )
  {
    memset(dst: (unsigned __int8 *)&LogContext, value: 0, count: sizeof(LogContext));
    WTInfoA(a1: 3, a2: 0, a3: &LogContext);
    LogContext.lcPktData = 1472;
    LogContext.lcPktMode = 0;
    LogContext.lcOptions = 5;
    hGlobalContext = (HCTX__ *)WTOpenA(a1: hWnd, a2: &LogContext, a3: 1);
    bWinTabOpened = true;
    WTInfoA(a1: LogContext.lcDevice + 100, a2: 15, a3: &NormalAxis);
    WTQueueSizeSet(a1: hGlobalContext, a2: 1000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3390
// Name: float WinTab_GetPressure(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl WinTab_GetPressure()
{
  if ( bLMBDown )
    return m_flLastPressure;
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B33B0
// Name: bool WinTab_Opened(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WinTab_Opened()
{
  return bWinTabOpened;
}

//------------------------------------------------------------------------------
// Address: 0x100B33C0
// Name: void WinTab_Packet(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WinTab_Packet(unsigned int wSerial, int hContext)
{
  AFX_MODULE_STATE *ModuleState; // eax
  _BYTE v3[12]; // [esp+0h] [ebp-3E88h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-3E7Ch]
  tagPOINT Point; // [esp+3E80h] [ebp-8h] BYREF

  if ( WTPacketsGet(a1: hContext, a2: 1000, a3: v3) != 0 )
  {
    m_flLastPressure = (double)v4 / (double)NormalAxis.axMax;
    if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::GetActiveMapView(this: CMapDoc::m_pMapDoc) != nullptr )
    {
      GetCursorPos(lpPoint: &Point);
      ModuleState = AfxGetModuleState();
      ScreenToClient(hWnd: ModuleState->m_pCurrentWinApp->m_pMainWnd->m_hWnd, lpPoint: &Point);
      if ( m_flLastPressure >= 0.050000001 && !bLMBDown )
        bLMBDown = true;
      if ( m_flLastPressure < 0.02 && bLMBDown )
        bLMBDown = false;
    }
  }
}
