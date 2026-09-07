// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service_ui/vwatchdlg.cpp
// Functions: 14
// ============================================================

#include "utils\vmpi\vmpi_service_ui\vwatchdlg.h"

//------------------------------------------------------------------------------
// Address: 0x00403790
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::~CUtlVector<char,class CUtlMemory<char,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(
        CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: public: class CUtlVector<char,class CUtlMemory<char,int>> __near & CUtlVector<char,class CUtlMemory<char,int>>::operator=(class CUtlVector<char,class CUtlMemory<char,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<char,CUtlMemory<char,int> > *__thiscall CUtlVector<char,CUtlMemory<char,int>>::operator=(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const CUtlVector<char,CUtlMemory<char,int> > *other)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount);
    this->m_Size += m_Size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - m_Size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && m_Size > 0 )
      _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403F00
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        const unsigned __int8 *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00404BB0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404CA0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::AddToTail(char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::AddToTail(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        char *src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  int v6; // eax
  char *v7; // esi

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00404FE0
// Name: void WriteToStatsWindow(struct HWND__ __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void WriteToStatsWindow(HWND__ *hwndDlg, const char *pFormat, ...)
{
  HWND DlgItem; // esi
  char msg[2048]; // [esp+4h] [ebp-800h] BYREF
  va_list params; // [esp+814h] [ebp+10h] BYREF

  va_start(params, pFormat);
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1004);
  if ( DlgItem != nullptr )
  {
    V_vsnprintf(pDest: msg, maxLen: 2048, pFormat, params);
    FormatAndSendToEditControl(hWnd: DlgItem, pText: msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405030
// Name: void UpdateStats(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateStats(HWND__ *hwndDlg)
{
  HWND DlgItem; // eax
  const CVWatchStats *Stats; // eax
  const CVWatchStats *v3; // esi

  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1004);
  if ( DlgItem != nullptr )
    ClearEditControl(hWnd: DlgItem);
  Stats = CVWatchClient::GetStats(this: &g_VWatchClient);
  v3 = Stats;
  if ( Stats != nullptr )
  {
    if ( Stats->m_bHasRunOutOfMemory )
      WriteToStatsWindow(
        hwndDlg,
        pFormat: "** Service ran out of memory **\nIt will not do any more scanning until restarted.\n\n");
    WriteToStatsWindow(
      hwndDlg,
      pFormat: "Memory used : %.2fM\n",
      (double)v3->m_nMemoryBytesUsed * 0.00000095367431640625);
    WriteToStatsWindow(
      hwndDlg,
      pFormat: "Memory limit : %.2fM\n",
      (double)v3->m_nMemoryBytesLimit * 0.00000095367431640625);
    WriteToStatsWindow(hwndDlg, pFormat: "\n");
    WriteToStatsWindow(
      hwndDlg,
      pFormat: "Watched file memory : %.2fM\n",
      (double)v3->m_nWatchedFileBytes * 0.00000095367431640625);
    WriteToStatsWindow(
      hwndDlg,
      pFormat: "Watched dir memory : %.2fM\n",
      (double)v3->m_nWatchedDirBytes * 0.00000095367431640625);
    WriteToStatsWindow(
      hwndDlg,
      pFormat: "Watched dir long name memory: %.2fM\n",
      (double)v3->m_nWatchedDirLongNameBytes * 0.00000095367431640625);
    WriteToStatsWindow(hwndDlg, pFormat: "\n");
    WriteToStatsWindow(hwndDlg, pFormat: "# files iterated : %lu\n", v3->m_nFilesIterated);
    WriteToStatsWindow(hwndDlg, pFormat: "# file entries : %lu\n", v3->m_nFileEntriesCreated);
    WriteToStatsWindow(hwndDlg, pFormat: "# directory entries : %lu\n", v3->m_nDirectoryEntriesCreated);
    WriteToStatsWindow(hwndDlg, pFormat: "\n");
    WriteToStatsWindow(hwndDlg, pFormat: "# accesses from CVWatchClient : %lu\n", v3->m_nDirectoryEntriesCreated);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405230
// Name: void CenterDialogOnScreen(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CenterDialogOnScreen(HWND__ *hWnd)
{
  HWND DesktopWindow; // eax
  tagRECT rcDesktop; // [esp+8h] [ebp-20h] BYREF
  tagRECT rcDialog; // [esp+18h] [ebp-10h] BYREF

  DesktopWindow = GetDesktopWindow();
  GetWindowRect(hWnd: DesktopWindow, lpRect: &rcDesktop);
  GetWindowRect(hWnd, lpRect: &rcDialog);
  SetWindowPos(
    hWnd,
    hWndInsertAfter: nullptr,
    X: (rcDesktop.right + rcDialog.left - rcDialog.right - rcDesktop.left) / 2,
    Y: (rcDesktop.bottom + rcDialog.top - rcDialog.bottom - rcDesktop.top) / 2,
    cx: 0,
    cy: 0,
    uFlags: 5u);
}

//------------------------------------------------------------------------------
// Address: 0x00405290
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405300
// Name: void UpdateDirectoriesList(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateDirectoriesList(HWND__ *hwndDlg)
{
  HWND v1; // edi
  HWND DlgItem; // eax
  HWND v3; // ebx
  int v4; // esi
  int v5; // edi
  const char *v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirs; // [esp+Ch] [ebp-14h] BYREF

  v1 = hwndDlg;
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1002);
  v3 = DlgItem;
  v4 = 0;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x184u, wParam: 0, lParam: 0);
    memset(&dirs, 0, sizeof(dirs));
    if ( CVWatchClient::GetWatchedDirectories(this: &g_VWatchClient, &dirs) )
    {
      if ( dirs.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          v6 = CUtlString::Get(this: &dirs.m_Memory.m_pMemory[v5]);
          SendMessageA(hWnd: v3, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v6);
          ++v4;
          ++v5;
        }
        while ( v4 < dirs.m_Size );
        v1 = hwndDlg;
      }
      v4 = 1;
    }
    else
    {
      SendMessageA(hWnd: v3, Msg: 0x180u, wParam: 0, lParam: (LPARAM)"(Can't connect to vwatch service)");
    }
    EnableWindow(hWnd: v3, bEnable: v4);
    v7 = GetDlgItem(hDlg: v1, nIDDlgItem: 1003);
    EnableWindow(hWnd: v7, bEnable: v4);
    v8 = GetDlgItem(hDlg: v1, nIDDlgItem: 1005);
    EnableWindow(hWnd: v8, bEnable: v4);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirs);
    m_pMemory = dirs.m_Memory.m_pMemory;
    if ( dirs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        dirs.m_Memory.m_pMemory = nullptr;
      }
      dirs.m_Memory.m_nAllocationCount = 0;
    }
    dirs.m_pElements = m_pMemory;
    if ( dirs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405420
// Name: void OnAddDirectory(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnAddDirectory(HWND__ *hwndDlg)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  StartWatchingDirStatus_t started; // eax
  CUtlString v5; // [esp-20h] [ebp-74h] BYREF
  CUtlString v6; // [esp-10h] [ebp-64h] BYREF
  CSimpleStringDlg dlg; // [esp+Ch] [ebp-48h] BYREF
  CUtlString sMsg; // [esp+34h] [ebp-20h] BYREF
  CUtlString sDir; // [esp+44h] [ebp-10h] BYREF

  while ( 1 )
  {
    CSimpleStringDlg::CSimpleStringDlg(this: &dlg);
    CUtlString::CUtlString(this: &v6, pString: str);
    CUtlString::CUtlString(this: &v5, pString: "Enter the directory path");
    if ( CSimpleStringDlg::Show(this: &dlg, hParent: hwndDlg, sTitle: v5, sInitialValue: v6) == 2 )
      break;
    CUtlString::CUtlString(this: &sDir, string: &dlg.m_sValue);
    v1 = CUtlString::Get(this: &sDir);
    if ( access(path: v1, amode: 0) == 0 )
    {
      v3 = CUtlString::Get(this: &sDir);
      started = CVWatchClient::StartWatchingDir(this: &g_VWatchClient, pDirName: v3);
      if ( started != STARTWATCHINGDIR_STARTED )
      {
        v6.m_Storage.m_nActualLength = 0;
        v6.m_Storage.m_Memory.m_nGrowSize = (int)"Warning";
        if ( started == STARTWATCHINGDIR_ALREADYWATCHING )
          v6.m_Storage.m_Memory.m_nAllocationCount = (int)"Already watching that directory.";
        else
          v6.m_Storage.m_Memory.m_nAllocationCount = (int)"Error adding the directory.";
        MessageBoxA(
          hWnd: hwndDlg,
          lpText: (LPCSTR)v6.m_Storage.m_Memory.m_nAllocationCount,
          lpCaption: (LPCSTR)v6.m_Storage.m_Memory.m_nGrowSize,
          uType: v6.m_Storage.m_nActualLength);
      }
      else
      {
        UpdateDirectoriesList(hwndDlg);
      }
      sDir.m_Storage.m_nActualLength = 0;
      if ( sDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( sDir.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sDir.m_Storage.m_Memory.m_pMemory);
          sDir.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        sDir.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      break;
    }
    CUtlString::operator+(this: &sDir, result: &sMsg, pOther: " does not exist.");
    v6.m_Storage.m_nActualLength = 0;
    v6.m_Storage.m_Memory.m_nGrowSize = (int)"Warning";
    v2 = CUtlString::Get(this: &sMsg);
    MessageBoxA(
      hWnd: hwndDlg,
      lpText: v2,
      lpCaption: (LPCSTR)v6.m_Storage.m_Memory.m_nGrowSize,
      uType: v6.m_Storage.m_nActualLength);
    sMsg.m_Storage.m_nActualLength = 0;
    if ( sMsg.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( sMsg.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sMsg.m_Storage.m_Memory.m_pMemory);
        sMsg.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sMsg.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    sDir.m_Storage.m_nActualLength = 0;
    if ( sDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( sDir.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sDir.m_Storage.m_Memory.m_pMemory);
        sDir.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sDir.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    dlg.m_sValue.m_Storage.m_nActualLength = 0;
    if ( dlg.m_sValue.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dlg.m_sValue.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dlg.m_sValue.m_Storage.m_Memory.m_pMemory);
        dlg.m_sValue.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      dlg.m_sValue.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    dlg.m_sTitle.m_Storage.m_nActualLength = 0;
    if ( dlg.m_sTitle.m_Storage.m_Memory.m_nGrowSize >= 0 && dlg.m_sTitle.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dlg.m_sTitle.m_Storage.m_Memory.m_pMemory);
  }
  CSimpleStringDlg::~CSimpleStringDlg(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x004055C0
// Name: void OnRemoveDirectory(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnRemoveDirectory(HWND__ *hwndDlg)
{
  HWND DlgItem; // eax
  HWND v2; // esi
  WPARAM v3; // eax
  char str[2048]; // [esp+8h] [ebp-800h] BYREF

  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1002);
  v2 = DlgItem;
  if ( DlgItem != nullptr )
  {
    v3 = SendMessageA(hWnd: DlgItem, Msg: 0x188u, wParam: 0, lParam: 0);
    if ( v3 != -1 && SendMessageA(hWnd: v2, Msg: 0x189u, wParam: v3, lParam: (LPARAM)str) != -1 )
    {
      if ( !CVWatchClient::StopWatchingDir(this: &g_VWatchClient, pDirName: str) )
        MessageBoxA(
          hWnd: hwndDlg,
          lpText: "Error attempting to remove the specified directory.",
          lpCaption: "Error",
          uType: 0);
      UpdateDirectoriesList(hwndDlg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405650
// Name: void OnRestart(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnRestart(HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1004);
  if ( DlgItem != nullptr )
    ClearEditControl(hWnd: DlgItem);
  if ( CVWatchClient::SendRestartSignal(this: &g_VWatchClient) )
  {
    _ThreadSleep(a1: 500);
    UpdateStats(hwndDlg);
    UpdateDirectoriesList(hwndDlg);
  }
  else
  {
    MessageBoxA(hWnd: hwndDlg, lpText: "Error sending the restart signal.", lpCaption: "Error", uType: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056C0
// Name: int VWatchDlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall VWatchDlgProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, int lParam)
{
  switch ( uMsg )
  {
    case 0x110u:
      CenterDialogOnScreen(hWnd: hwndDlg);
      if ( CVWatchClient::Connect(this: &g_VWatchClient, nTimeout: 0x12Cu) )
      {
        UpdateStats(hwndDlg);
        SetTimer(hWnd: hwndDlg, nIDEvent: 0, uElapse: 0x1F4u, lpTimerFunc: nullptr);
        UpdateDirectoriesList(hwndDlg);
        return 0;
      }
      WriteToStatsWindow(hwndDlg, pFormat: "Unable to connect to vwatch.");
      break;
    case 0x111u:
      if ( wParam > 0x3EB )
      {
        switch ( wParam )
        {
          case 0x3EDu:
            OnRemoveDirectory(hwndDlg);
            return 0;
          case 0x3EEu:
            UpdateDirectoriesList(hwndDlg);
            return 0;
          case 0x3EFu:
            OnRestart(hwndDlg);
            return 0;
          default:
            break;
        }
      }
      else
      {
        if ( wParam == 1003 )
        {
          OnAddDirectory(hwndDlg);
          return 0;
        }
        if ( wParam != 0 && wParam <= 2 )
        {
          EndDialog(hDlg: hwndDlg, nResult: 0);
          return 0;
        }
      }
      break;
    case 0x113u:
      UpdateStats(hwndDlg);
      return 0;
    default:
      break;
  }
  return 0;
}
