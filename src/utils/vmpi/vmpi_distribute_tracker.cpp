// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_distribute_tracker.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1002EAA0
// Name: CheckFlashTimers
// Source: json
//------------------------------------------------------------------------------
void CheckFlashTimers()
{
  int v0; // edi
  CWUStatus *m_pMemory; // esi
  int v2; // edx
  int m_iState; // eax
  double flCurTime; // [esp+4h] [ebp-8h]

  flCurTime = _Plat_FloatTime();
  EnterCriticalSection(lpCriticalSection: &g_CS);
  v0 = 0;
  if ( g_WUStatus.m_Size > 0 )
  {
    m_pMemory = g_WUStatus.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      m_iState = m_pMemory[v2].m_iState;
      if ( (m_iState == 2 || m_iState == 4 || m_iState == 6) && flCurTime > m_pMemory[v2].m_flTransitionTime )
      {
        m_pMemory[v2].m_iState = m_iState - 1;
        ++g_nChanges;
        m_pMemory = g_WUStatus.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < g_WUStatus.m_Size );
  }
  LeaveCriticalSection(lpCriticalSection: &g_CS);
}

//------------------------------------------------------------------------------
// Address: 0x1002EB30
// Name: Graphical_WorkUnitSentToWorker
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitSentToWorker(int iWorkUnit@<eax>)
{
  CWUStatus *v2; // esi
  int m_iState; // eax

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    m_iState = v2->m_iState;
    if ( m_iState != 3 && m_iState != 4 && m_iState != 5 && m_iState != 6 )
    {
      v2->m_iState = 2;
      v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EBA0
// Name: Graphical_WorkUnitStarted
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitStarted(int iWorkUnit@<eax>)
{
  int v2; // eax
  int m_iState; // ecx
  CWUStatus *v4; // esi

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = iWorkUnit;
    m_iState = g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState;
    if ( m_iState != 3 && m_iState != 4 )
    {
      g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 6;
      v4 = &g_WUStatus.m_Memory.m_pMemory[v2];
      v4->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC10
// Name: bool VMPITracker_WriteDebugFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPITracker_WriteDebugFile(_iobuf *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // ebx
  int m_Size; // ecx
  int v4; // edx
  CWorkUnit *m_pMemory; // eax
  int v6; // edi
  int v7; // esi
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  char *MachineName; // [esp-4h] [ebp-28h]
  char *v14; // [esp-4h] [ebp-28h]
  char *v15; // [esp-4h] [ebp-28h]
  double v16; // [esp+0h] [ebp-24h]
  double v17; // [esp+0h] [ebp-24h]
  double v18; // [esp+0h] [ebp-24h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int iEvent; // [esp+20h] [ebp-4h]

  v1 = fopen(file: pFilename, mode: "wt");
  v2 = v1;
  if ( v1 == nullptr )
    return 0;
  fprintf(str: v1, format: "# work units: %d\n", g_WorkUnits.m_Size);
  m_Size = g_WorkUnits.m_Size;
  v4 = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_iWorkerCompleted == -1 )
        ++v4;
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  fprintf(str: v2, format: "# active work units: %d\n", v4);
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "--- Events ---");
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "\n");
  v6 = 0;
  i = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    v7 = 0;
    v22 = 0;
    do
    {
      v8 = (int *)((char *)&g_WorkUnits.m_Memory.m_pMemory->m_iWorkerCompleted + v7);
      if ( *v8 == -1 )
      {
        fprintf(str: v2, format: "  work unit %d\n", v6);
        fprintf(str: v2, format: "\n");
        v9 = v8[4];
        if ( v9 != 0 )
        {
          iEvent = 0;
          if ( v9 > 0 )
          {
            v10 = 0;
            do
            {
              v11 = *(_DWORD *)(v8[1] + v10);
              if ( v11 == 1 )
              {
                v19 = v10 + v8[1];
                v16 = _Plat_FloatTime() - *(double *)(v19 + 8);
                MachineName = VMPI_GetMachineName(iProc: *(_DWORD *)(v19 + 4));
                fprintf(str: v2, format: "   started (by worker %s) %.1f seconds ago\n", MachineName, v16);
              }
              else if ( v11 != 0 )
              {
                if ( v11 == 2 )
                {
                  v21 = v10 + v8[1];
                  v18 = _Plat_FloatTime() - *(double *)(v21 + 8);
                  v15 = VMPI_GetMachineName(iProc: *(_DWORD *)(v21 + 4));
                  fprintf(str: v2, format: " completed (by worker %s) %.1f seconds ago\n", v15, v18);
                }
              }
              else
              {
                v20 = v10 + v8[1];
                v17 = _Plat_FloatTime() - *(double *)(v20 + 8);
                v14 = VMPI_GetMachineName(iProc: *(_DWORD *)(v20 + 4));
                fprintf(str: v2, format: "      sent (to worker %s) %.1f seconds ago\n", v14, v17);
              }
              v10 += 16;
              ++iEvent;
            }
            while ( iEvent < v8[4] );
            v6 = i;
          }
        }
        else
        {
          fprintf(str: v2, format: "    *no events*\n");
        }
        fprintf(str: v2, format: "\n");
      }
      ++v6;
      v7 = v22 + 24;
      i = v6;
      v22 += 24;
    }
    while ( v6 < g_WorkUnits.m_Size );
  }
  fclose(stream: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EE20
// Name: void VMPITracker_HandleDebugKeypresses(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_HandleDebugKeypresses()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  int i; // esi
  char v3; // al
  char *v4; // [esp-4h] [ebp-208h]
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_bTrackWorkUnitEvents && kbhit() != 0 )
  {
    v0 = getch();
    v1 = toupper(c: v0);
    if ( iState == 0 )
    {
      if ( v1 == 68 )
      {
        iState = 1;
        _Warning(
          a1: "\n"
          "\n"
          "----------------------\n"
          "1. Write debug file (ascending filenames).\n"
          "2. Write debug file (c:\\vmpi_tracker_0.txt).\n"
          "3. Invite debug workers (password: 'debugworker').\n"
          "\n"
          "0. Exit menu.\n"
          "----------------------\n"
          "\n");
      }
      return;
    }
    if ( iState != 1 )
      return;
    switch ( v1 )
    {
      case '1':
        iState = 0;
        for ( i = 1; i < 128; ++i )
        {
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "c:\\vmpi_tracker_%d.txt", i);
          if ( access(path: filename, amode: 0) != 0 )
            break;
        }
        if ( i == 128 )
        {
          _Warning(a1: "** Please delete c:\\vmpi_tracker_*.txt and try again.\n");
          return;
        }
        if ( VMPITracker_WriteDebugFile(pFilename: (_iobuf *)filename) != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", filename);
          return;
        }
        v4 = filename;
        goto LABEL_16;
      case '2':
        iState = 0;
        v3 = VMPITracker_WriteDebugFile(pFilename: (_iobuf *)"c:\\vmpi_tracker_0.txt");
        v4 = "c:\\vmpi_tracker_0.txt";
        if ( v3 != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", "c:\\vmpi_tracker_0.txt");
          return;
        }
LABEL_16:
        _Warning(a1: "Failed to write %s successfully.\n", v4);
        return;
      case '3':
        iState = 0;
        _Warning(a1: "\nInviting debug workers with password 'debugworker'...\nGo ahead and connect them.\n");
        VMPI_InviteDebugWorkers();
        break;
      case '0':
        iState = 0;
        _Warning(a1: "\n\nExited menu.\n\n");
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F060
// Name: void VMPITracker_WorkUnitSentToWorker(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitSentToWorker(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 0;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitSentToWorker(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x1002F0B0
// Name: void VMPITracker_WorkUnitStarted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitStarted(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 1;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitStarted(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x1002F100
// Name: void VMPITracker_WorkUnitCompleted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitCompleted(int iWorkUnit, int iWorker)
{
  CWUStatus *v2; // esi
  CWorkUnitEvent event; // [esp+8h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 2;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
    g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_iWorkerCompleted = iWorker;
  }
  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState = 4;
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
    ++g_nChanges;
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F260
// Name: TrackerWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall TrackerWindowProc(HWND__ *hwnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  unsigned int v4; // edi
  unsigned int i; // esi
  int m_Size; // esi
  HDC v7; // ebx
  int *p_bottom; // esi
  int v9; // edi
  signed int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // eax
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-78h] BYREF
  HBRUSH__ *hStateColors[7]; // [esp+4Ch] [ebp-38h]
  CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > wuStatus; // [esp+68h] [ebp-1Ch] BYREF
  void *hOldObj; // [esp+7Ch] [ebp-8h]
  int width; // [esp+80h] [ebp-4h]

  if ( uMsg == 5 )
  {
    v9 = (unsigned __int16)lParam;
    v10 = HIWORD(lParam);
    width = (unsigned __int16)lParam;
    g_LastSizeX = (unsigned __int16)lParam;
    g_LastSizeY = HIWORD(lParam);
    v11 = 20;
    while ( 1 )
    {
      hOldObj = (void *)(v10 / v11);
      if ( v9 / v11 * (v10 / v11) >= g_WUStatus.m_Size )
        break;
      if ( --v11 <= 1 )
        break;
      v9 = width;
    }
    if ( v11 <= minTestSize )
      v11 = minTestSize;
    v12 = 0;
    v13 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v14 = 0;
      hOldObj = (void *)g_WUStatus.m_Size;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.left = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.top = v13;
        v12 += v11;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.right = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.bottom = v13 + v11;
        if ( v12 + v11 > width )
        {
          v13 += v11;
          v12 = 0;
        }
        ++v14;
        hOldObj = (char *)hOldObj - 1;
      }
      while ( hOldObj != nullptr );
    }
  }
  else if ( uMsg == 15 )
  {
    v4 = 0;
    for ( i = 0; i < 7; ++i )
      hStateColors[i] = CreateSolidBrush(color: g_StateColors[i]);
    memset(&wuStatus, 0, 12);
    wuStatus.m_pElements = nullptr;
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_nLastDrawnChanges = g_nChanges;
    wuStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &wuStatus,
      elem: 0,
      num: g_WUStatus.m_Size);
    m_Size = wuStatus.m_Size;
    memcpy(
      dst: (unsigned __int8 *)wuStatus.m_Memory.m_pMemory,
      src: (unsigned __int8 *)g_WUStatus.m_Memory.m_pMemory,
      count: 24 * wuStatus.m_Size);
    LeaveCriticalSection(lpCriticalSection: &g_CS);
    v7 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
    do
    {
      hOldObj = SelectObject(hdc: v7, h: hStateColors[v4]);
      if ( m_Size > 0 )
      {
        p_bottom = &wuStatus.m_Memory.m_pMemory->m_Rect.bottom;
        width = wuStatus.m_Size;
        do
        {
          if ( p_bottom[1] == v4 )
            Rectangle(hdc: v7, left: *(p_bottom - 3), top: *(p_bottom - 2), right: *(p_bottom - 1), bottom: *p_bottom);
          p_bottom += 6;
          --width;
        }
        while ( width != 0 );
        m_Size = wuStatus.m_Size;
      }
      SelectObject(hdc: v7, h: hOldObj);
      DeleteObject(ho: hStateColors[v4++]);
    }
    while ( v4 < 7 );
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    if ( wuStatus.m_Memory.m_nGrowSize >= 0 && wuStatus.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wuStatus.m_Memory.m_pMemory);
  }
  return DefWindowProcA(hWnd: hwnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x1002F470
// Name: ThreadProc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall ThreadProc(void *lpParameter)
{
  HINSTANCE CurrentProcess; // eax
  tagWNDCLASSEXA WndClsEx; // [esp+8h] [ebp-4Ch] BYREF
  tagMSG msg; // [esp+38h] [ebp-1Ch] BYREF

  WndClsEx.cbSize = 48;
  WndClsEx.style = 3;
  WndClsEx.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))TrackerWindowProc;
  WndClsEx.cbClsExtra = 0;
  WndClsEx.cbWndExtra = 0;
  WndClsEx.hIcon = nullptr;
  WndClsEx.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  WndClsEx.hbrBackground = (HBRUSH__ *)GetStockObject(i: 0);
  WndClsEx.lpszMenuName = nullptr;
  WndClsEx.lpszClassName = "VMPI_Tracker";
  WndClsEx.hInstance = (HINSTANCE__ *)GetCurrentProcess();
  WndClsEx.hIconSm = nullptr;
  RegisterClassExA(a1: &WndClsEx);
  CurrentProcess = (HINSTANCE)GetCurrentProcess();
  g_hWnd = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "VMPI_Tracker",
             lpWindowName: "VMPI Tracker",
             dwStyle: 0xCF0000u,
             X: 0,
             Y: 0,
             nWidth: g_LastSizeX,
             nHeight: g_LastSizeY,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: CurrentProcess,
             lpParam: nullptr);
  ShowWindow(hWnd: g_hWnd, nCmdShow: 5);
  SetEvent(hEvent: g_hCreateEvent);
  while ( WaitForSingleObject(hHandle: g_hDestroyWindowEvent, dwMilliseconds: 0xC8u) != 0 )
  {
    while ( PeekMessageA(lpMsg: &msg, hWnd: g_hWnd, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    CheckFlashTimers();
    if ( g_nChanges != g_nLastDrawnChanges )
      InvalidateRect(hWnd: g_hWnd, lpRect: nullptr, bErase: false);
  }
  SetEvent(hEvent: g_hDestroyWindowCompletedEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F5E0
// Name: Graphical_Start
// Source: json
//------------------------------------------------------------------------------
DWORD Graphical_Start()
{
  DWORD result; // eax
  int v1; // eax
  int v2; // ecx

  result = VMPI_IsParamUsed(eParam: mpi_Graphics);
  g_bUseGraphics = result;
  if ( (_BYTE)result != 0 )
  {
    if ( g_hCreateEvent == nullptr )
    {
      g_hCreateEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
      g_hDestroyWindowEvent = CreateEventA(
                                lpEventAttributes: nullptr,
                                bManualReset: false,
                                bInitialState: false,
                                lpName: nullptr);
      g_hDestroyWindowCompletedEvent = CreateEventA(
                                         lpEventAttributes: nullptr,
                                         bManualReset: false,
                                         bInitialState: false,
                                         lpName: nullptr);
      InitializeCriticalSection(lpCriticalSection: &g_CS);
    }
    ResetEvent(hEvent: g_hCreateEvent);
    ResetEvent(hEvent: g_hDestroyWindowCompletedEvent);
    g_WUStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &g_WUStatus,
      elem: 0,
      num: g_WorkUnits.m_Size);
    v1 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v2 = 0;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 0;
        ++v1;
        ++v2;
      }
      while ( v1 < g_WUStatus.m_Size );
    }
    CreateThread(
      lpThreadAttributes: nullptr,
      dwStackSize: 0,
      lpStartAddress: ThreadProc,
      lpParameter: nullptr,
      dwCreationFlags: 0,
      lpThreadId: nullptr);
    return WaitForSingleObject(hHandle: g_hCreateEvent, dwMilliseconds: 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F760
// Name: void VMPITracker_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_End()
{
  CWorkUnit *m_pMemory; // eax

  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bUseGraphics )
  {
    SetEvent(hEvent: g_hDestroyWindowEvent);
    WaitForSingleObject(hHandle: g_hDestroyWindowCompletedEvent, dwMilliseconds: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F830
// Name: void VMPITracker_Start(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_Start(int nWorkUnits)
{
  bool IsParamUsed; // al
  CWorkUnit *m_pMemory; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_TrackEvents)
    || (IsParamUsed = VMPI_IsParamUsed(eParam: mpi_Graphics), g_bTrackWorkUnitEvents = false, IsParamUsed) )
  {
    g_bTrackWorkUnitEvents = true;
  }
  g_flJobStartTime = _Plat_FloatTime();
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bTrackWorkUnitEvents )
  {
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
      this: &g_WorkUnits,
      elem: g_WorkUnits.m_Size,
      num: nWorkUnits);
  }
  Graphical_Start();
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10016210
// Name: CheckFlashTimers
// Source: json
//------------------------------------------------------------------------------
void CheckFlashTimers()
{
  int v0; // edi
  CWUStatus *m_pMemory; // esi
  int v2; // edx
  int m_iState; // eax
  double flCurTime; // [esp+4h] [ebp-8h]

  flCurTime = _Plat_FloatTime();
  EnterCriticalSection(lpCriticalSection: &g_CS);
  v0 = 0;
  if ( g_WUStatus.m_Size > 0 )
  {
    m_pMemory = g_WUStatus.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      m_iState = m_pMemory[v2].m_iState;
      if ( (m_iState == 2 || m_iState == 4 || m_iState == 6) && flCurTime > m_pMemory[v2].m_flTransitionTime )
      {
        m_pMemory[v2].m_iState = m_iState - 1;
        ++g_nChanges;
        m_pMemory = g_WUStatus.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < g_WUStatus.m_Size );
  }
  LeaveCriticalSection(lpCriticalSection: &g_CS);
}

//------------------------------------------------------------------------------
// Address: 0x100162A0
// Name: Graphical_WorkUnitSentToWorker
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitSentToWorker(int iWorkUnit@<eax>)
{
  CWUStatus *v2; // esi
  int m_iState; // eax

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    m_iState = v2->m_iState;
    if ( m_iState != 3 && m_iState != 4 && m_iState != 5 && m_iState != 6 )
    {
      v2->m_iState = 2;
      v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016310
// Name: Graphical_WorkUnitStarted
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitStarted(int iWorkUnit@<eax>)
{
  int v2; // eax
  int m_iState; // ecx
  CWUStatus *v4; // esi

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = iWorkUnit;
    m_iState = g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState;
    if ( m_iState != 3 && m_iState != 4 )
    {
      g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 6;
      v4 = &g_WUStatus.m_Memory.m_pMemory[v2];
      v4->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016380
// Name: bool VMPITracker_WriteDebugFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPITracker_WriteDebugFile(const char *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // ebx
  int m_Size; // ecx
  int v4; // edx
  CWorkUnit *m_pMemory; // eax
  int v6; // edi
  int v7; // esi
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  char *MachineName; // [esp-4h] [ebp-28h]
  char *v14; // [esp-4h] [ebp-28h]
  char *v15; // [esp-4h] [ebp-28h]
  double v16; // [esp+0h] [ebp-24h]
  double v17; // [esp+0h] [ebp-24h]
  double v18; // [esp+0h] [ebp-24h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int iEvent; // [esp+20h] [ebp-4h]

  v1 = fopen(file: pFilename, mode: "wt");
  v2 = v1;
  if ( v1 == nullptr )
    return 0;
  fprintf(str: v1, format: "# work units: %d\n", g_WorkUnits.m_Size);
  m_Size = g_WorkUnits.m_Size;
  v4 = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_iWorkerCompleted == -1 )
        ++v4;
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  fprintf(str: v2, format: "# active work units: %d\n", v4);
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "--- Events ---");
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "\n");
  v6 = 0;
  i = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    v7 = 0;
    v22 = 0;
    do
    {
      v8 = (int *)((char *)&g_WorkUnits.m_Memory.m_pMemory->m_iWorkerCompleted + v7);
      if ( *v8 == -1 )
      {
        fprintf(str: v2, format: "  work unit %d\n", v6);
        fprintf(str: v2, format: "\n");
        v9 = v8[4];
        if ( v9 != 0 )
        {
          iEvent = 0;
          if ( v9 > 0 )
          {
            v10 = 0;
            do
            {
              v11 = *(_DWORD *)(v8[1] + v10);
              if ( v11 == 1 )
              {
                v19 = v10 + v8[1];
                v16 = _Plat_FloatTime() - *(double *)(v19 + 8);
                MachineName = VMPI_GetMachineName(iProc: *(_DWORD *)(v19 + 4));
                fprintf(str: v2, format: "   started (by worker %s) %.1f seconds ago\n", MachineName, v16);
              }
              else if ( v11 != 0 )
              {
                if ( v11 == 2 )
                {
                  v21 = v10 + v8[1];
                  v18 = _Plat_FloatTime() - *(double *)(v21 + 8);
                  v15 = VMPI_GetMachineName(iProc: *(_DWORD *)(v21 + 4));
                  fprintf(str: v2, format: " completed (by worker %s) %.1f seconds ago\n", v15, v18);
                }
              }
              else
              {
                v20 = v10 + v8[1];
                v17 = _Plat_FloatTime() - *(double *)(v20 + 8);
                v14 = VMPI_GetMachineName(iProc: *(_DWORD *)(v20 + 4));
                fprintf(str: v2, format: "      sent (to worker %s) %.1f seconds ago\n", v14, v17);
              }
              v10 += 16;
              ++iEvent;
            }
            while ( iEvent < v8[4] );
            v6 = i;
          }
        }
        else
        {
          fprintf(str: v2, format: "    *no events*\n");
        }
        fprintf(str: v2, format: "\n");
      }
      ++v6;
      v7 = v22 + 24;
      i = v6;
      v22 += 24;
    }
    while ( v6 < g_WorkUnits.m_Size );
  }
  fclose(stream: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10016590
// Name: void VMPITracker_HandleDebugKeypresses(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_HandleDebugKeypresses()
{
  int v0; // eax
  int v1; // eax
  int i; // esi
  char v3; // al
  char *v4; // [esp-4h] [ebp-208h]
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_bTrackWorkUnitEvents && kbhit() != 0 )
  {
    v0 = getch();
    v1 = toupper(c: v0);
    if ( iState == 0 )
    {
      if ( v1 == 68 )
      {
        iState = 1;
        _Warning(
          a1: "\n"
          "\n"
          "----------------------\n"
          "1. Write debug file (ascending filenames).\n"
          "2. Write debug file (c:\\vmpi_tracker_0.txt).\n"
          "3. Invite debug workers (password: 'debugworker').\n"
          "\n"
          "0. Exit menu.\n"
          "----------------------\n"
          "\n");
      }
      return;
    }
    if ( iState != 1 )
      return;
    switch ( v1 )
    {
      case '1':
        iState = 0;
        for ( i = 1; i < 128; ++i )
        {
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "c:\\vmpi_tracker_%d.txt", i);
          if ( access(path: filename, amode: 0) != 0 )
            break;
        }
        if ( i == 128 )
        {
          _Warning(a1: "** Please delete c:\\vmpi_tracker_*.txt and try again.\n");
          return;
        }
        if ( VMPITracker_WriteDebugFile(pFilename: filename) != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", filename);
          return;
        }
        v4 = filename;
        goto LABEL_16;
      case '2':
        iState = 0;
        v3 = VMPITracker_WriteDebugFile(pFilename: "c:\\vmpi_tracker_0.txt");
        v4 = "c:\\vmpi_tracker_0.txt";
        if ( v3 != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", "c:\\vmpi_tracker_0.txt");
          return;
        }
LABEL_16:
        _Warning(a1: "Failed to write %s successfully.\n", v4);
        return;
      case '3':
        iState = 0;
        _Warning(a1: "\nInviting debug workers with password 'debugworker'...\nGo ahead and connect them.\n");
        VMPI_InviteDebugWorkers();
        break;
      case '0':
        iState = 0;
        _Warning(a1: "\n\nExited menu.\n\n");
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016850
// Name: void VMPITracker_WorkUnitSentToWorker(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitSentToWorker(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 0;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitSentToWorker(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x100168A0
// Name: void VMPITracker_WorkUnitStarted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitStarted(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 1;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitStarted(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x100168F0
// Name: void VMPITracker_WorkUnitCompleted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitCompleted(int iWorkUnit, int iWorker)
{
  CWUStatus *v2; // esi
  CWorkUnitEvent event; // [esp+8h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 2;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
    g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_iWorkerCompleted = iWorker;
  }
  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState = 4;
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
    ++g_nChanges;
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016A50
// Name: TrackerWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall TrackerWindowProc(HWND__ *hwnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  unsigned int v4; // edi
  unsigned int i; // esi
  int m_Size; // esi
  HDC v7; // ebx
  int *p_bottom; // esi
  int v9; // edi
  signed int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // eax
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-78h] BYREF
  HBRUSH__ *hStateColors[7]; // [esp+4Ch] [ebp-38h]
  CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > wuStatus; // [esp+68h] [ebp-1Ch] BYREF
  void *hOldObj; // [esp+7Ch] [ebp-8h]
  int width; // [esp+80h] [ebp-4h]

  if ( uMsg == 5 )
  {
    v9 = (unsigned __int16)lParam;
    v10 = HIWORD(lParam);
    width = (unsigned __int16)lParam;
    g_LastSizeX = (unsigned __int16)lParam;
    g_LastSizeY = HIWORD(lParam);
    v11 = 20;
    while ( 1 )
    {
      hOldObj = (void *)(v10 / v11);
      if ( v9 / v11 * (v10 / v11) >= g_WUStatus.m_Size )
        break;
      if ( --v11 <= 1 )
        break;
      v9 = width;
    }
    if ( v11 <= minTestSize )
      v11 = minTestSize;
    v12 = 0;
    v13 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v14 = 0;
      hOldObj = (void *)g_WUStatus.m_Size;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.left = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.top = v13;
        v12 += v11;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.right = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.bottom = v13 + v11;
        if ( v12 + v11 > width )
        {
          v13 += v11;
          v12 = 0;
        }
        ++v14;
        hOldObj = (char *)hOldObj - 1;
      }
      while ( hOldObj != nullptr );
    }
  }
  else if ( uMsg == 15 )
  {
    v4 = 0;
    for ( i = 0; i < 7; ++i )
      hStateColors[i] = CreateSolidBrush(color: g_StateColors[i]);
    memset(&wuStatus, 0, 12);
    wuStatus.m_pElements = nullptr;
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_nLastDrawnChanges = g_nChanges;
    wuStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &wuStatus,
      elem: 0,
      num: g_WUStatus.m_Size);
    m_Size = wuStatus.m_Size;
    memcpy(
      dst: (unsigned __int8 *)wuStatus.m_Memory.m_pMemory,
      src: (unsigned __int8 *)g_WUStatus.m_Memory.m_pMemory,
      count: 24 * wuStatus.m_Size);
    LeaveCriticalSection(lpCriticalSection: &g_CS);
    v7 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
    do
    {
      hOldObj = SelectObject(hdc: v7, h: hStateColors[v4]);
      if ( m_Size > 0 )
      {
        p_bottom = &wuStatus.m_Memory.m_pMemory->m_Rect.bottom;
        width = wuStatus.m_Size;
        do
        {
          if ( p_bottom[1] == v4 )
            Rectangle(hdc: v7, left: *(p_bottom - 3), top: *(p_bottom - 2), right: *(p_bottom - 1), bottom: *p_bottom);
          p_bottom += 6;
          --width;
        }
        while ( width != 0 );
        m_Size = wuStatus.m_Size;
      }
      SelectObject(hdc: v7, h: hOldObj);
      DeleteObject(ho: hStateColors[v4++]);
    }
    while ( v4 < 7 );
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    if ( wuStatus.m_Memory.m_nGrowSize >= 0 && wuStatus.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wuStatus.m_Memory.m_pMemory);
  }
  return DefWindowProcA(hWnd: hwnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10016C60
// Name: ThreadProc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall ThreadProc(void *lpParameter)
{
  HINSTANCE CurrentProcess; // eax
  tagWNDCLASSEXA WndClsEx; // [esp+8h] [ebp-4Ch] BYREF
  tagMSG msg; // [esp+38h] [ebp-1Ch] BYREF

  WndClsEx.cbSize = 48;
  WndClsEx.style = 3;
  WndClsEx.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))TrackerWindowProc;
  WndClsEx.cbClsExtra = 0;
  WndClsEx.cbWndExtra = 0;
  WndClsEx.hIcon = nullptr;
  WndClsEx.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  WndClsEx.hbrBackground = (HBRUSH__ *)GetStockObject(i: 0);
  WndClsEx.lpszMenuName = nullptr;
  WndClsEx.lpszClassName = "VMPI_Tracker";
  WndClsEx.hInstance = (HINSTANCE__ *)GetCurrentProcess();
  WndClsEx.hIconSm = nullptr;
  RegisterClassExA(a1: &WndClsEx);
  CurrentProcess = (HINSTANCE)GetCurrentProcess();
  g_hWnd = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "VMPI_Tracker",
             lpWindowName: "VMPI Tracker",
             dwStyle: 0xCF0000u,
             X: 0,
             Y: 0,
             nWidth: g_LastSizeX,
             nHeight: g_LastSizeY,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: CurrentProcess,
             lpParam: nullptr);
  ShowWindow(hWnd: g_hWnd, nCmdShow: 5);
  SetEvent(hEvent: g_hCreateEvent);
  while ( WaitForSingleObject(hHandle: g_hDestroyWindowEvent, dwMilliseconds: 0xC8u) != 0 )
  {
    while ( PeekMessageA(lpMsg: &msg, hWnd: g_hWnd, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    CheckFlashTimers();
    if ( g_nChanges != g_nLastDrawnChanges )
      InvalidateRect(hWnd: g_hWnd, lpRect: nullptr, bErase: false);
  }
  SetEvent(hEvent: g_hDestroyWindowCompletedEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016DD0
// Name: Graphical_Start
// Source: json
//------------------------------------------------------------------------------
DWORD Graphical_Start()
{
  DWORD result; // eax
  int v1; // eax
  int v2; // ecx

  result = VMPI_IsParamUsed(eParam: mpi_Graphics);
  g_bUseGraphics = result;
  if ( (_BYTE)result != 0 )
  {
    if ( g_hCreateEvent == nullptr )
    {
      g_hCreateEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
      g_hDestroyWindowEvent = CreateEventA(
                                lpEventAttributes: nullptr,
                                bManualReset: false,
                                bInitialState: false,
                                lpName: nullptr);
      g_hDestroyWindowCompletedEvent = CreateEventA(
                                         lpEventAttributes: nullptr,
                                         bManualReset: false,
                                         bInitialState: false,
                                         lpName: nullptr);
      InitializeCriticalSection(lpCriticalSection: &g_CS);
    }
    ResetEvent(hEvent: g_hCreateEvent);
    ResetEvent(hEvent: g_hDestroyWindowCompletedEvent);
    g_WUStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &g_WUStatus,
      elem: 0,
      num: g_WorkUnits.m_Size);
    v1 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v2 = 0;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 0;
        ++v1;
        ++v2;
      }
      while ( v1 < g_WUStatus.m_Size );
    }
    CreateThread(
      lpThreadAttributes: nullptr,
      dwStackSize: 0,
      lpStartAddress: ThreadProc,
      lpParameter: nullptr,
      dwCreationFlags: 0,
      lpThreadId: nullptr);
    return WaitForSingleObject(hHandle: g_hCreateEvent, dwMilliseconds: 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016F50
// Name: void VMPITracker_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_End()
{
  CWorkUnit *m_pMemory; // eax

  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bUseGraphics )
  {
    SetEvent(hEvent: g_hDestroyWindowEvent);
    WaitForSingleObject(hHandle: g_hDestroyWindowCompletedEvent, dwMilliseconds: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017020
// Name: void VMPITracker_Start(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_Start(int nWorkUnits)
{
  bool IsParamUsed; // al
  CWorkUnit *m_pMemory; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_TrackEvents)
    || (IsParamUsed = VMPI_IsParamUsed(eParam: mpi_Graphics), g_bTrackWorkUnitEvents = false, IsParamUsed) )
  {
    g_bTrackWorkUnitEvents = true;
  }
  g_flJobStartTime = _Plat_FloatTime();
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bTrackWorkUnitEvents )
  {
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this: &g_WorkUnits);
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
      this: &g_WorkUnits,
      elem: g_WorkUnits.m_Size,
      num: nWorkUnits);
  }
  Graphical_Start();
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10091BD0
// Name: CheckFlashTimers
// Source: json
//------------------------------------------------------------------------------
void CheckFlashTimers()
{
  int v0; // edi
  CWUStatus *m_pMemory; // esi
  int v2; // edx
  int m_iState; // eax
  int v4; // [esp+0h] [ebp-Ch]
  double flCurTime; // [esp+4h] [ebp-8h]

  flCurTime = _Plat_FloatTime(a1: v4);
  EnterCriticalSection(lpCriticalSection: &g_CS);
  v0 = 0;
  if ( g_WUStatus.m_Size > 0 )
  {
    m_pMemory = g_WUStatus.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      m_iState = m_pMemory[v2].m_iState;
      if ( (m_iState == 2 || m_iState == 4 || m_iState == 6) && flCurTime > m_pMemory[v2].m_flTransitionTime )
      {
        m_pMemory[v2].m_iState = m_iState - 1;
        ++g_nChanges;
        m_pMemory = g_WUStatus.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < g_WUStatus.m_Size );
  }
  LeaveCriticalSection(lpCriticalSection: &g_CS);
}

//------------------------------------------------------------------------------
// Address: 0x10091C60
// Name: Graphical_WorkUnitSentToWorker
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitSentToWorker(int iWorkUnit@<eax>)
{
  CWUStatus *v2; // esi
  int m_iState; // eax
  int v4; // [esp+0h] [ebp-4h]

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    m_iState = v2->m_iState;
    if ( m_iState != 3 && m_iState != 4 && m_iState != 5 && m_iState != 6 )
    {
      v2->m_iState = 2;
      v2->m_flTransitionTime = _Plat_FloatTime(a1: v4) + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091CD0
// Name: Graphical_WorkUnitStarted
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitStarted(int iWorkUnit@<eax>)
{
  int v2; // eax
  int m_iState; // ecx
  CWUStatus *v4; // esi
  int v5; // [esp+0h] [ebp-4h]

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = iWorkUnit;
    m_iState = g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState;
    if ( m_iState != 3 && m_iState != 4 )
    {
      g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 6;
      v4 = &g_WUStatus.m_Memory.m_pMemory[v2];
      v4->m_flTransitionTime = _Plat_FloatTime(a1: v5) + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091D40
// Name: bool VMPITracker_WriteDebugFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall VMPITracker_WriteDebugFile@<al>(int a1@<esi>, const char *pFilename)
{
  _iobuf *v2; // eax
  _iobuf *v3; // ebx
  int m_Size; // ecx
  int v5; // edx
  CWorkUnit *m_pMemory; // eax
  int v7; // edi
  int v8; // esi
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edi
  int v12; // eax
  char *MachineName; // [esp-4h] [ebp-28h]
  char *v15; // [esp-4h] [ebp-28h]
  char *v16; // [esp-4h] [ebp-28h]
  double v17; // [esp+0h] [ebp-24h]
  double v18; // [esp+0h] [ebp-24h]
  double v19; // [esp+0h] [ebp-24h]
  int v20; // [esp+8h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+14h] [ebp-10h]
  int v24; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int iEvent; // [esp+20h] [ebp-4h]

  v2 = fopen(file: pFilename, mode: "wt");
  v3 = v2;
  if ( v2 == nullptr )
    return 0;
  fprintf(str: v2, format: "# work units: %d\n", g_WorkUnits.m_Size);
  m_Size = g_WorkUnits.m_Size;
  v5 = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_iWorkerCompleted == -1 )
        ++v5;
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  fprintf(str: v3, format: "# active work units: %d\n", v5);
  fprintf(str: v3, format: "\n");
  fprintf(str: v3, format: "--- Events ---");
  fprintf(str: v3, format: "\n");
  fprintf(str: v3, format: "\n");
  v7 = 0;
  i = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    v20 = a1;
    v8 = 0;
    v24 = 0;
    do
    {
      v9 = (int *)((char *)&g_WorkUnits.m_Memory.m_pMemory->m_iWorkerCompleted + v8);
      if ( *v9 == -1 )
      {
        fprintf(str: v3, format: "  work unit %d\n", v7);
        fprintf(str: v3, format: "\n");
        v10 = v9[4];
        if ( v10 != 0 )
        {
          iEvent = 0;
          if ( v10 > 0 )
          {
            v11 = 0;
            do
            {
              v12 = *(_DWORD *)(v9[1] + v11);
              if ( v12 == 1 )
              {
                v21 = v11 + v9[1];
                v17 = _Plat_FloatTime(a1: v20) - *(double *)(v21 + 8);
                MachineName = VMPI_GetMachineName(iProc: *(_DWORD *)(v21 + 4));
                fprintf(str: v3, format: "   started (by worker %s) %.1f seconds ago\n", MachineName, v17);
              }
              else if ( v12 != 0 )
              {
                if ( v12 == 2 )
                {
                  v23 = v11 + v9[1];
                  v19 = _Plat_FloatTime(a1: v20) - *(double *)(v23 + 8);
                  v16 = VMPI_GetMachineName(iProc: *(_DWORD *)(v23 + 4));
                  fprintf(str: v3, format: " completed (by worker %s) %.1f seconds ago\n", v16, v19);
                }
              }
              else
              {
                v22 = v11 + v9[1];
                v18 = _Plat_FloatTime(a1: v20) - *(double *)(v22 + 8);
                v15 = VMPI_GetMachineName(iProc: *(_DWORD *)(v22 + 4));
                fprintf(str: v3, format: "      sent (to worker %s) %.1f seconds ago\n", v15, v18);
              }
              v11 += 16;
              ++iEvent;
            }
            while ( iEvent < v9[4] );
            v7 = i;
          }
        }
        else
        {
          fprintf(str: v3, format: "    *no events*\n");
        }
        fprintf(str: v3, format: "\n");
      }
      ++v7;
      v8 = v24 + 24;
      i = v7;
      v24 += 24;
    }
    while ( v7 < g_WorkUnits.m_Size );
  }
  fclose(stream: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091F50
// Name: void VMPITracker_HandleDebugKeypresses(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPITracker_HandleDebugKeypresses(int a1@<esi>)
{
  int v1; // eax
  int v2; // eax
  int i; // esi
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_bTrackWorkUnitEvents && kbhit() != 0 )
  {
    v1 = getch();
    v2 = toupper(c: v1);
    if ( iState == 0 )
    {
      if ( v2 == 68 )
      {
        iState = 1;
        _Warning(
          a1: "\n"
          "\n"
          "----------------------\n"
          "1. Write debug file (ascending filenames).\n"
          "2. Write debug file (c:\\vmpi_tracker_0.txt).\n"
          "3. Invite debug workers (password: 'debugworker').\n"
          "\n"
          "0. Exit menu.\n"
          "----------------------\n"
          "\n");
      }
      return;
    }
    if ( iState != 1 )
      return;
    switch ( v2 )
    {
      case '1':
        iState = 0;
        for ( i = 1; i < 128; ++i )
        {
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "c:\\vmpi_tracker_%d.txt", i);
          if ( access(path: filename, amode: 0) != 0 )
            break;
        }
        if ( i == 128 )
        {
          _Warning(a1: "** Please delete c:\\vmpi_tracker_*.txt and try again.\n");
          return;
        }
        if ( VMPITracker_WriteDebugFile(a1, pFilename: filename) != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n");
          return;
        }
        goto LABEL_15;
      case '2':
        iState = 0;
        if ( VMPITracker_WriteDebugFile(a1, pFilename: "c:\\vmpi_tracker_0.txt") != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n");
          return;
        }
LABEL_15:
        _Warning(a1: "Failed to write %s successfully.\n");
        return;
      case '3':
        iState = 0;
        _Warning(a1: "\nInviting debug workers with password 'debugworker'...\nGo ahead and connect them.\n");
        VMPI_InviteDebugWorkers();
        break;
      case '0':
        iState = 0;
        _Warning(a1: "\n\nExited menu.\n\n");
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092280
// Name: void VMPITracker_WorkUnitSentToWorker(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitSentToWorker(int iWorkUnit, int iWorker)
{
  int v2; // [esp+0h] [ebp-14h]
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 0;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime(a1: v2);
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitSentToWorker(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x100922D0
// Name: void VMPITracker_WorkUnitStarted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitStarted(int iWorkUnit, int iWorker)
{
  int v2; // [esp+0h] [ebp-14h]
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 1;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime(a1: v2);
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitStarted(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10092320
// Name: void VMPITracker_WorkUnitCompleted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPITracker_WorkUnitCompleted(int a1@<ebx>, int iWorkUnit, int iWorker)
{
  CWUStatus *v3; // esi
  int v4; // [esp+0h] [ebp-18h]
  CWorkUnitEvent event; // [esp+8h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 2;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime(a1);
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
    g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_iWorkerCompleted = iWorker;
  }
  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState = 4;
    v3 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    v3->m_flTransitionTime = _Plat_FloatTime(a1: v4) + 0.1000000014901161;
    ++g_nChanges;
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092480
// Name: TrackerWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall TrackerWindowProc(HWND__ *hwnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  unsigned int v4; // edi
  unsigned int i; // esi
  int m_Size; // esi
  HDC v7; // ebx
  int *p_bottom; // esi
  int v9; // edi
  signed int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // eax
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-78h] BYREF
  HBRUSH__ *hStateColors[7]; // [esp+4Ch] [ebp-38h]
  CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > wuStatus; // [esp+68h] [ebp-1Ch] BYREF
  void *hOldObj; // [esp+7Ch] [ebp-8h]
  int width; // [esp+80h] [ebp-4h]

  if ( uMsg == 5 )
  {
    v9 = (unsigned __int16)lParam;
    v10 = HIWORD(lParam);
    width = (unsigned __int16)lParam;
    g_LastSizeX = (unsigned __int16)lParam;
    g_LastSizeY = HIWORD(lParam);
    v11 = 20;
    while ( 1 )
    {
      hOldObj = (void *)(v10 / v11);
      if ( v9 / v11 * (v10 / v11) >= g_WUStatus.m_Size )
        break;
      if ( --v11 <= 1 )
        break;
      v9 = width;
    }
    if ( v11 <= minTestSize )
      v11 = minTestSize;
    v12 = 0;
    v13 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v14 = 0;
      hOldObj = (void *)g_WUStatus.m_Size;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.left = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.top = v13;
        v12 += v11;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.right = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.bottom = v13 + v11;
        if ( v12 + v11 > width )
        {
          v13 += v11;
          v12 = 0;
        }
        ++v14;
        hOldObj = (char *)hOldObj - 1;
      }
      while ( hOldObj != nullptr );
    }
  }
  else if ( uMsg == 15 )
  {
    v4 = 0;
    for ( i = 0; i < 7; ++i )
      hStateColors[i] = CreateSolidBrush(color: g_StateColors[i]);
    memset(&wuStatus, 0, 12);
    wuStatus.m_pElements = nullptr;
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_nLastDrawnChanges = g_nChanges;
    wuStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &wuStatus,
      elem: 0,
      num: g_WUStatus.m_Size);
    m_Size = wuStatus.m_Size;
    memcpy(
      dst: (unsigned __int8 *)wuStatus.m_Memory.m_pMemory,
      src: (unsigned __int8 *)g_WUStatus.m_Memory.m_pMemory,
      count: 24 * wuStatus.m_Size);
    LeaveCriticalSection(lpCriticalSection: &g_CS);
    v7 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
    do
    {
      hOldObj = SelectObject(hdc: v7, h: hStateColors[v4]);
      if ( m_Size > 0 )
      {
        p_bottom = &wuStatus.m_Memory.m_pMemory->m_Rect.bottom;
        width = wuStatus.m_Size;
        do
        {
          if ( p_bottom[1] == v4 )
            Rectangle(hdc: v7, left: *(p_bottom - 3), top: *(p_bottom - 2), right: *(p_bottom - 1), bottom: *p_bottom);
          p_bottom += 6;
          --width;
        }
        while ( width != 0 );
        m_Size = wuStatus.m_Size;
      }
      SelectObject(hdc: v7, h: hOldObj);
      DeleteObject(ho: hStateColors[v4++]);
    }
    while ( v4 < 7 );
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    if ( wuStatus.m_Memory.m_nGrowSize >= 0 && wuStatus.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wuStatus.m_Memory.m_pMemory);
  }
  return DefWindowProcA(hWnd: hwnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10092690
// Name: ThreadProc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall ThreadProc(void *lpParameter)
{
  HINSTANCE CurrentProcess; // eax
  tagWNDCLASSEXA WndClsEx; // [esp+8h] [ebp-4Ch] BYREF
  tagMSG msg; // [esp+38h] [ebp-1Ch] BYREF

  WndClsEx.cbSize = 48;
  WndClsEx.style = 3;
  WndClsEx.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))TrackerWindowProc;
  WndClsEx.cbClsExtra = 0;
  WndClsEx.cbWndExtra = 0;
  WndClsEx.hIcon = nullptr;
  WndClsEx.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  WndClsEx.hbrBackground = (HBRUSH__ *)GetStockObject(i: 0);
  WndClsEx.lpszMenuName = nullptr;
  WndClsEx.lpszClassName = "VMPI_Tracker";
  WndClsEx.hInstance = (HINSTANCE__ *)GetCurrentProcess();
  WndClsEx.hIconSm = nullptr;
  RegisterClassExA(a1: &WndClsEx);
  CurrentProcess = (HINSTANCE)GetCurrentProcess();
  g_hWnd = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "VMPI_Tracker",
             lpWindowName: "VMPI Tracker",
             dwStyle: 0xCF0000u,
             X: 0,
             Y: 0,
             nWidth: g_LastSizeX,
             nHeight: g_LastSizeY,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: CurrentProcess,
             lpParam: nullptr);
  ShowWindow(hWnd: g_hWnd, nCmdShow: 5);
  SetEvent(hEvent: g_hCreateEvent);
  while ( WaitForSingleObject(hHandle: g_hDestroyWindowEvent, dwMilliseconds: 0xC8u) != 0 )
  {
    while ( PeekMessageA(lpMsg: &msg, hWnd: g_hWnd, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    CheckFlashTimers();
    if ( g_nChanges != g_nLastDrawnChanges )
      InvalidateRect(hWnd: g_hWnd, lpRect: nullptr, bErase: false);
  }
  SetEvent(hEvent: g_hDestroyWindowCompletedEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092800
// Name: Graphical_Start
// Source: json
//------------------------------------------------------------------------------
DWORD __fastcall Graphical_Start(int a1, int a2)
{
  DWORD result; // eax
  int v3; // eax
  int v4; // ecx

  result = VMPI_IsParamUsed(a1, a2, eParam: mpi_Graphics);
  g_bUseGraphics = result;
  if ( (_BYTE)result != 0 )
  {
    if ( g_hCreateEvent == nullptr )
    {
      g_hCreateEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
      g_hDestroyWindowEvent = CreateEventA(
                                lpEventAttributes: nullptr,
                                bManualReset: false,
                                bInitialState: false,
                                lpName: nullptr);
      g_hDestroyWindowCompletedEvent = CreateEventA(
                                         lpEventAttributes: nullptr,
                                         bManualReset: false,
                                         bInitialState: false,
                                         lpName: nullptr);
      InitializeCriticalSection(lpCriticalSection: &g_CS);
    }
    ResetEvent(hEvent: g_hCreateEvent);
    ResetEvent(hEvent: g_hDestroyWindowCompletedEvent);
    g_WUStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &g_WUStatus,
      elem: 0,
      num: g_WorkUnits.m_Size);
    v3 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v4 = 0;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v4].m_iState = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < g_WUStatus.m_Size );
    }
    CreateThread(
      lpThreadAttributes: nullptr,
      dwStackSize: 0,
      lpStartAddress: ThreadProc,
      lpParameter: nullptr,
      dwCreationFlags: 0,
      lpThreadId: nullptr);
    return WaitForSingleObject(hHandle: g_hCreateEvent, dwMilliseconds: 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092980
// Name: void VMPITracker_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_End()
{
  CWorkUnit *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bUseGraphics )
  {
    SetEvent(hEvent: g_hDestroyWindowEvent);
    WaitForSingleObject(hHandle: g_hDestroyWindowCompletedEvent, dwMilliseconds: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100929F0
// Name: void VMPITracker_Start(int)
// Source: json
//------------------------------------------------------------------------------
void __fastcall VMPITracker_Start(int a1, int a2, int nWorkUnits)
{
  int v3; // edx
  int v4; // ecx
  bool IsParamUsed; // al
  int v6; // edx
  int v7; // ecx
  CWorkUnit *m_pMemory; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  if ( VMPI_IsParamUsed(a1, a2, eParam: mpi_TrackEvents)
    || (IsParamUsed = VMPI_IsParamUsed(a1: v4, a2: v3, eParam: mpi_Graphics), g_bTrackWorkUnitEvents = false,
                                                                              IsParamUsed) )
  {
    g_bTrackWorkUnitEvents = true;
  }
  g_flJobStartTime = _Plat_FloatTime(a1: savedregs);
  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bTrackWorkUnitEvents )
  {
    CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
      this: &g_WorkUnits,
      elem: g_WorkUnits.m_Size,
      num: nWorkUnits);
  }
  Graphical_Start(a1: v7, a2: v6);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10030590
// Name: CheckFlashTimers
// Source: json
//------------------------------------------------------------------------------
void CheckFlashTimers()
{
  int v0; // edi
  CWUStatus *m_pMemory; // esi
  int v2; // edx
  int m_iState; // eax
  double flCurTime; // [esp+4h] [ebp-8h]

  flCurTime = _Plat_FloatTime();
  EnterCriticalSection(lpCriticalSection: &g_CS);
  v0 = 0;
  if ( g_WUStatus.m_Size > 0 )
  {
    m_pMemory = g_WUStatus.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      m_iState = m_pMemory[v2].m_iState;
      if ( (m_iState == 2 || m_iState == 4 || m_iState == 6) && flCurTime > m_pMemory[v2].m_flTransitionTime )
      {
        m_pMemory[v2].m_iState = m_iState - 1;
        ++g_nChanges;
        m_pMemory = g_WUStatus.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < g_WUStatus.m_Size );
  }
  LeaveCriticalSection(lpCriticalSection: &g_CS);
}

//------------------------------------------------------------------------------
// Address: 0x10030620
// Name: Graphical_WorkUnitSentToWorker
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitSentToWorker(int iWorkUnit@<eax>)
{
  CWUStatus *v2; // esi
  int m_iState; // eax

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    m_iState = v2->m_iState;
    if ( m_iState != 3 && m_iState != 4 && m_iState != 5 && m_iState != 6 )
    {
      v2->m_iState = 2;
      v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030690
// Name: Graphical_WorkUnitStarted
// Source: json
//------------------------------------------------------------------------------
void __usercall Graphical_WorkUnitStarted(int iWorkUnit@<eax>)
{
  int v2; // eax
  int m_iState; // ecx
  CWUStatus *v4; // esi

  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    v2 = iWorkUnit;
    m_iState = g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState;
    if ( m_iState != 3 && m_iState != 4 )
    {
      g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 6;
      v4 = &g_WUStatus.m_Memory.m_pMemory[v2];
      v4->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
      ++g_nChanges;
    }
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030700
// Name: bool VMPITracker_WriteDebugFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPITracker_WriteDebugFile(const char *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // ebx
  int m_Size; // ecx
  int v4; // edx
  CWorkUnit *m_pMemory; // eax
  int v6; // edi
  int v7; // esi
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  char *MachineName; // [esp-4h] [ebp-28h]
  char *v14; // [esp-4h] [ebp-28h]
  char *v15; // [esp-4h] [ebp-28h]
  double v16; // [esp+0h] [ebp-24h]
  double v17; // [esp+0h] [ebp-24h]
  double v18; // [esp+0h] [ebp-24h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int iEvent; // [esp+20h] [ebp-4h]

  v1 = fopen(file: pFilename, mode: "wt");
  v2 = v1;
  if ( v1 == nullptr )
    return 0;
  fprintf(str: v1, format: "# work units: %d\n", g_WorkUnits.m_Size);
  m_Size = g_WorkUnits.m_Size;
  v4 = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_iWorkerCompleted == -1 )
        ++v4;
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  fprintf(str: v2, format: "# active work units: %d\n", v4);
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "--- Events ---");
  fprintf(str: v2, format: "\n");
  fprintf(str: v2, format: "\n");
  v6 = 0;
  i = 0;
  if ( g_WorkUnits.m_Size > 0 )
  {
    v7 = 0;
    v22 = 0;
    do
    {
      v8 = (int *)((char *)&g_WorkUnits.m_Memory.m_pMemory->m_iWorkerCompleted + v7);
      if ( *v8 == -1 )
      {
        fprintf(str: v2, format: "  work unit %d\n", v6);
        fprintf(str: v2, format: "\n");
        v9 = v8[4];
        if ( v9 != 0 )
        {
          iEvent = 0;
          if ( v9 > 0 )
          {
            v10 = 0;
            do
            {
              v11 = *(_DWORD *)(v8[1] + v10);
              if ( v11 == 1 )
              {
                v19 = v10 + v8[1];
                v16 = _Plat_FloatTime() - *(double *)(v19 + 8);
                MachineName = VMPI_GetMachineName(iProc: *(_DWORD *)(v19 + 4));
                fprintf(str: v2, format: "   started (by worker %s) %.1f seconds ago\n", MachineName, v16);
              }
              else if ( v11 != 0 )
              {
                if ( v11 == 2 )
                {
                  v21 = v10 + v8[1];
                  v18 = _Plat_FloatTime() - *(double *)(v21 + 8);
                  v15 = VMPI_GetMachineName(iProc: *(_DWORD *)(v21 + 4));
                  fprintf(str: v2, format: " completed (by worker %s) %.1f seconds ago\n", v15, v18);
                }
              }
              else
              {
                v20 = v10 + v8[1];
                v17 = _Plat_FloatTime() - *(double *)(v20 + 8);
                v14 = VMPI_GetMachineName(iProc: *(_DWORD *)(v20 + 4));
                fprintf(str: v2, format: "      sent (to worker %s) %.1f seconds ago\n", v14, v17);
              }
              v10 += 16;
              ++iEvent;
            }
            while ( iEvent < v8[4] );
            v6 = i;
          }
        }
        else
        {
          fprintf(str: v2, format: "    *no events*\n");
        }
        fprintf(str: v2, format: "\n");
      }
      ++v6;
      v7 = v22 + 24;
      i = v6;
      v22 += 24;
    }
    while ( v6 < g_WorkUnits.m_Size );
  }
  fclose(stream: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030910
// Name: void VMPITracker_HandleDebugKeypresses(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_HandleDebugKeypresses()
{
  int v0; // eax
  int v1; // eax
  int i; // esi
  char v3; // al
  char *v4; // [esp-4h] [ebp-208h]
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_bTrackWorkUnitEvents && kbhit() != 0 )
  {
    v0 = getch();
    v1 = toupper(c: v0);
    if ( iState == 0 )
    {
      if ( v1 == 68 )
      {
        iState = 1;
        _Warning(
          a1: "\n"
          "\n"
          "----------------------\n"
          "1. Write debug file (ascending filenames).\n"
          "2. Write debug file (c:\\vmpi_tracker_0.txt).\n"
          "3. Invite debug workers (password: 'debugworker').\n"
          "\n"
          "0. Exit menu.\n"
          "----------------------\n"
          "\n");
      }
      return;
    }
    if ( iState != 1 )
      return;
    switch ( v1 )
    {
      case '1':
        iState = 0;
        for ( i = 1; i < 128; ++i )
        {
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "c:\\vmpi_tracker_%d.txt", i);
          if ( access(path: filename, amode: 0) != 0 )
            break;
        }
        if ( i == 128 )
        {
          _Warning(a1: "** Please delete c:\\vmpi_tracker_*.txt and try again.\n");
          return;
        }
        if ( VMPITracker_WriteDebugFile(pFilename: filename) != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", filename);
          return;
        }
        v4 = filename;
        goto LABEL_16;
      case '2':
        iState = 0;
        v3 = VMPITracker_WriteDebugFile(pFilename: "c:\\vmpi_tracker_0.txt");
        v4 = "c:\\vmpi_tracker_0.txt";
        if ( v3 != 0 )
        {
          _Warning(a1: "Wrote %s successfully.\n", "c:\\vmpi_tracker_0.txt");
          return;
        }
LABEL_16:
        _Warning(a1: "Failed to write %s successfully.\n", v4);
        return;
      case '3':
        iState = 0;
        _Warning(a1: "\nInviting debug workers with password 'debugworker'...\nGo ahead and connect them.\n");
        VMPI_InviteDebugWorkers();
        break;
      case '0':
        iState = 0;
        _Warning(a1: "\n\nExited menu.\n\n");
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030BD0
// Name: void VMPITracker_WorkUnitSentToWorker(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitSentToWorker(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 0;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitSentToWorker(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10030C20
// Name: void VMPITracker_WorkUnitStarted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitStarted(int iWorkUnit, int iWorker)
{
  CWorkUnitEvent event; // [esp+4h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 1;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
  }
  Graphical_WorkUnitStarted(iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10030C70
// Name: void VMPITracker_WorkUnitCompleted(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_WorkUnitCompleted(int iWorkUnit, int iWorker)
{
  CWUStatus *v2; // esi
  CWorkUnitEvent event; // [esp+8h] [ebp-10h] BYREF

  if ( g_bTrackWorkUnitEvents )
  {
    event.m_iEventType = 2;
    event.m_iWorker = iWorker;
    event.m_flTime = _Plat_FloatTime();
    CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
      this: &g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events,
      elem: g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_Events.m_Size,
      src: &event);
    g_WorkUnits.m_Memory.m_pMemory[iWorkUnit].m_iWorkerCompleted = iWorker;
  }
  if ( g_bUseGraphics )
  {
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_WUStatus.m_Memory.m_pMemory[iWorkUnit].m_iState = 4;
    v2 = &g_WUStatus.m_Memory.m_pMemory[iWorkUnit];
    v2->m_flTransitionTime = _Plat_FloatTime() + 0.1000000014901161;
    ++g_nChanges;
    LeaveCriticalSection(lpCriticalSection: &g_CS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030DD0
// Name: TrackerWindowProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall TrackerWindowProc(HWND__ *hwnd, UINT uMsg, WPARAM wParam, unsigned int lParam)
{
  unsigned int v4; // edi
  unsigned int i; // esi
  int m_Size; // esi
  HDC v7; // ebx
  int *p_bottom; // esi
  int v9; // edi
  signed int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // eax
  tagPAINTSTRUCT ps; // [esp+Ch] [ebp-78h] BYREF
  HBRUSH__ *hStateColors[7]; // [esp+4Ch] [ebp-38h]
  CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > wuStatus; // [esp+68h] [ebp-1Ch] BYREF
  void *hOldObj; // [esp+7Ch] [ebp-8h]
  int width; // [esp+80h] [ebp-4h]

  if ( uMsg == 5 )
  {
    v9 = (unsigned __int16)lParam;
    v10 = HIWORD(lParam);
    width = (unsigned __int16)lParam;
    g_LastSizeX = (unsigned __int16)lParam;
    g_LastSizeY = HIWORD(lParam);
    v11 = 20;
    while ( 1 )
    {
      hOldObj = (void *)(v10 / v11);
      if ( v9 / v11 * (v10 / v11) >= g_WUStatus.m_Size )
        break;
      if ( --v11 <= 1 )
        break;
      v9 = width;
    }
    if ( v11 <= minTestSize )
      v11 = minTestSize;
    v12 = 0;
    v13 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v14 = 0;
      hOldObj = (void *)g_WUStatus.m_Size;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.left = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.top = v13;
        v12 += v11;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.right = v12;
        g_WUStatus.m_Memory.m_pMemory[v14].m_Rect.bottom = v13 + v11;
        if ( v12 + v11 > width )
        {
          v13 += v11;
          v12 = 0;
        }
        ++v14;
        hOldObj = (char *)hOldObj - 1;
      }
      while ( hOldObj != nullptr );
    }
  }
  else if ( uMsg == 15 )
  {
    v4 = 0;
    for ( i = 0; i < 7; ++i )
      hStateColors[i] = CreateSolidBrush(color: g_StateColors[i]);
    memset(&wuStatus, 0, 12);
    wuStatus.m_pElements = nullptr;
    EnterCriticalSection(lpCriticalSection: &g_CS);
    g_nLastDrawnChanges = g_nChanges;
    wuStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &wuStatus,
      elem: 0,
      num: g_WUStatus.m_Size);
    m_Size = wuStatus.m_Size;
    memcpy(
      dst: (unsigned __int8 *)wuStatus.m_Memory.m_pMemory,
      src: (unsigned __int8 *)g_WUStatus.m_Memory.m_pMemory,
      count: 24 * wuStatus.m_Size);
    LeaveCriticalSection(lpCriticalSection: &g_CS);
    v7 = BeginPaint(hWnd: hwnd, lpPaint: &ps);
    do
    {
      hOldObj = SelectObject(hdc: v7, h: hStateColors[v4]);
      if ( m_Size > 0 )
      {
        p_bottom = &wuStatus.m_Memory.m_pMemory->m_Rect.bottom;
        width = wuStatus.m_Size;
        do
        {
          if ( p_bottom[1] == v4 )
            Rectangle(hdc: v7, left: *(p_bottom - 3), top: *(p_bottom - 2), right: *(p_bottom - 1), bottom: *p_bottom);
          p_bottom += 6;
          --width;
        }
        while ( width != 0 );
        m_Size = wuStatus.m_Size;
      }
      SelectObject(hdc: v7, h: hOldObj);
      DeleteObject(ho: hStateColors[v4++]);
    }
    while ( v4 < 7 );
    EndPaint(hWnd: hwnd, lpPaint: &ps);
    if ( wuStatus.m_Memory.m_nGrowSize >= 0 && wuStatus.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wuStatus.m_Memory.m_pMemory);
  }
  return DefWindowProcA(hWnd: hwnd, Msg: uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10030FE0
// Name: ThreadProc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall ThreadProc(void *lpParameter)
{
  HINSTANCE CurrentProcess; // eax
  tagWNDCLASSEXA WndClsEx; // [esp+8h] [ebp-4Ch] BYREF
  tagMSG msg; // [esp+38h] [ebp-1Ch] BYREF

  WndClsEx.cbSize = 48;
  WndClsEx.style = 3;
  WndClsEx.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))TrackerWindowProc;
  WndClsEx.cbClsExtra = 0;
  WndClsEx.cbWndExtra = 0;
  WndClsEx.hIcon = nullptr;
  WndClsEx.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  WndClsEx.hbrBackground = (HBRUSH__ *)GetStockObject(i: 0);
  WndClsEx.lpszMenuName = nullptr;
  WndClsEx.lpszClassName = "VMPI_Tracker";
  WndClsEx.hInstance = (HINSTANCE__ *)GetCurrentProcess();
  WndClsEx.hIconSm = nullptr;
  RegisterClassExA(a1: &WndClsEx);
  CurrentProcess = (HINSTANCE)GetCurrentProcess();
  g_hWnd = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "VMPI_Tracker",
             lpWindowName: "VMPI Tracker",
             dwStyle: 0xCF0000u,
             X: 0,
             Y: 0,
             nWidth: g_LastSizeX,
             nHeight: g_LastSizeY,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: CurrentProcess,
             lpParam: nullptr);
  ShowWindow(hWnd: g_hWnd, nCmdShow: 5);
  SetEvent(hEvent: g_hCreateEvent);
  while ( WaitForSingleObject(hHandle: g_hDestroyWindowEvent, dwMilliseconds: 0xC8u) != 0 )
  {
    while ( PeekMessageA(lpMsg: &msg, hWnd: g_hWnd, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    CheckFlashTimers();
    if ( g_nChanges != g_nLastDrawnChanges )
      InvalidateRect(hWnd: g_hWnd, lpRect: nullptr, bErase: false);
  }
  SetEvent(hEvent: g_hDestroyWindowCompletedEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031150
// Name: Graphical_Start
// Source: json
//------------------------------------------------------------------------------
DWORD Graphical_Start()
{
  DWORD result; // eax
  int v1; // eax
  int v2; // ecx

  result = VMPI_IsParamUsed(eParam: mpi_Graphics);
  g_bUseGraphics = result;
  if ( (_BYTE)result != 0 )
  {
    if ( g_hCreateEvent == nullptr )
    {
      g_hCreateEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
      g_hDestroyWindowEvent = CreateEventA(
                                lpEventAttributes: nullptr,
                                bManualReset: false,
                                bInitialState: false,
                                lpName: nullptr);
      g_hDestroyWindowCompletedEvent = CreateEventA(
                                         lpEventAttributes: nullptr,
                                         bManualReset: false,
                                         bInitialState: false,
                                         lpName: nullptr);
      InitializeCriticalSection(lpCriticalSection: &g_CS);
    }
    ResetEvent(hEvent: g_hCreateEvent);
    ResetEvent(hEvent: g_hDestroyWindowCompletedEvent);
    g_WUStatus.m_Size = 0;
    CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
      this: &g_WUStatus,
      elem: 0,
      num: g_WorkUnits.m_Size);
    v1 = 0;
    if ( g_WUStatus.m_Size > 0 )
    {
      v2 = 0;
      do
      {
        g_WUStatus.m_Memory.m_pMemory[v2].m_iState = 0;
        ++v1;
        ++v2;
      }
      while ( v1 < g_WUStatus.m_Size );
    }
    CreateThread(
      lpThreadAttributes: nullptr,
      dwStackSize: 0,
      lpStartAddress: ThreadProc,
      lpParameter: nullptr,
      dwCreationFlags: 0,
      lpThreadId: nullptr);
    return WaitForSingleObject(hHandle: g_hCreateEvent, dwMilliseconds: 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100312D0
// Name: void VMPITracker_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_End()
{
  CWorkUnit *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bUseGraphics )
  {
    SetEvent(hEvent: g_hDestroyWindowEvent);
    WaitForSingleObject(hHandle: g_hDestroyWindowCompletedEvent, dwMilliseconds: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100313A0
// Name: void VMPITracker_Start(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPITracker_Start(int nWorkUnits)
{
  bool IsParamUsed; // al
  CWorkUnit *m_pMemory; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_TrackEvents)
    || (IsParamUsed = VMPI_IsParamUsed(eParam: mpi_Graphics), g_bTrackWorkUnitEvents = false, IsParamUsed) )
  {
    g_bTrackWorkUnitEvents = true;
  }
  g_flJobStartTime = _Plat_FloatTime();
  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
  m_pMemory = g_WorkUnits.m_Memory.m_pMemory;
  if ( g_WorkUnits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkUnits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkUnits.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorkUnits.m_Memory.m_pMemory = nullptr;
    }
    g_WorkUnits.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkUnits.m_pElements = m_pMemory;
  if ( g_bTrackWorkUnitEvents )
  {
    CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this: &g_WorkUnits);
    CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
      this: &g_WorkUnits,
      elem: g_WorkUnits.m_Size,
      num: nWorkUnits);
  }
  Graphical_Start();
}

} // namespace vvis_dll
