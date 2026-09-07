// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/show_sounds.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E480
// Name: void ShowSounds_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showSoundsSortColumn", value: g_showSounds_sortColumn);
  Sys_SetRegistryInteger(keyName: "showSoundsSortDescending", value: g_showSounds_sortDescending);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showSounds_hWnd, lpwndpl: &wp);
  g_showSounds_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showSoundsWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x0040E530
// Name: void ShowSounds_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showSoundsSortColumn", defValue: 0, value: &g_showSounds_sortColumn);
  Sys_GetRegistryInteger(keyName: "showSoundsSortDescending", defValue: 0, value: &g_showSounds_sortDescending);
  Sys_GetRegistryString(keyName: "showSoundsWindowRect", value: buff, defValue: &str, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showSounds_windowRect,
         &g_showSounds_windowRect.top,
         &g_showSounds_windowRect.right,
         &g_showSounds_windowRect.bottom) != 4
    || g_showSounds_windowRect.left < 0
    || g_showSounds_windowRect.top < 0
    || g_showSounds_windowRect.right < 0
    || g_showSounds_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showSounds_windowRect.left = 0;
    *(_QWORD *)&g_showSounds_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E5E0
// Name: void ShowSounds_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Clear()
{
  int v0; // edi
  int v1; // esi

  if ( g_showSounds_hWnd != nullptr )
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showSounds_pSounds != nullptr )
  {
    v0 = 0;
    if ( g_showSounds_numSounds > 0 )
    {
      v1 = 0;
      do
      {
        free(pMem: g_showSounds_pSounds[v1].pName);
        free(pMem: g_showSounds_pSounds[v1].pPrefix);
        free(pMem: g_showSounds_pSounds[v1].pFormat);
        ++v0;
        ++v1;
      }
      while ( v0 < g_showSounds_numSounds );
    }
    free(pMem: g_showSounds_pSounds);
    g_showSounds_pSounds = nullptr;
    g_showSounds_numSounds = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E680
// Name: void ShowSounds_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Summary()
{
  int v0; // esi
  int v1; // edx
  int *p_dataSize; // eax
  int v3; // ecx
  char buff[1024]; // [esp+18h] [ebp-400h] BYREF

  v0 = 0;
  v1 = 0;
  if ( g_showSounds_numSounds > 0 )
  {
    p_dataSize = &g_showSounds_pSounds->dataSize;
    v3 = g_showSounds_numSounds;
    do
    {
      if ( p_dataSize[5] != 0 )
        v0 += *p_dataSize;
      else
        v1 += *p_dataSize;
      p_dataSize += 45;
      --v3;
    }
    while ( v3 != 0 );
  }
  sprintf(
    string: buff,
    format: "Entries:\t\t\t%d\nStatic Memory:\t\t%.2f MB\nStreamed Memory:\t\t%.2f MB\n",
    g_showSounds_numSounds,
    (float)((float)v1 * 0.00000095367432),
    (float)((float)v0 * 0.00000095367432));
  MessageBoxA(hWnd: g_showSounds_hWnd, lpText: buff, lpCaption: "Sound Summary", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040E720
// Name: void ShowSounds_Play(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Play()
{
  LRESULT v0; // esi
  char command[256]; // [esp+0h] [ebp-13Ch] BYREF
  tagLVITEMA lvitem; // [esp+100h] [ebp-3Ch] BYREF

  if ( g_connectionState == kCONNECTEDAPP )
  {
    v0 = SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1042u, wParam: 0, lParam: 0);
    if ( v0 != -1 )
    {
      memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
      lvitem.mask = 4;
      lvitem.iItem = v0;
      SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      sprintf(
        string: command,
        format: "play %s%s",
        *(const char **)(lvitem.lParam + 8),
        *(const char **)(lvitem.lParam + 4));
      ProcessCommand(strCmdIn: command);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E7B0
// Name: int ShowSounds_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowSounds_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  result = 0;
  switch ( g_showSounds_sortColumn )
  {
    case 0:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 4), s2: *(const char **)(lParam2 + 4));
      break;
    case 1:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 8), s2: *(const char **)(lParam2 + 8));
      break;
    case 2:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 12), s2: *(const char **)(lParam2 + 12));
      break;
    case 3:
      result = *(_DWORD *)(lParam1 + 16) - *(_DWORD *)(lParam2 + 16);
      break;
    case 4:
      result = *(_DWORD *)(lParam1 + 36) - *(_DWORD *)(lParam2 + 36);
      break;
    case 5:
      result = _V_stricmp(s1: (const char *)(lParam1 + 60), s2: (const char *)(lParam2 + 60));
      break;
    case 6:
      result = *(_DWORD *)(lParam1 + 80) - *(_DWORD *)(lParam2 + 80);
      break;
    case 7:
      result = _V_stricmp(s1: (const char *)(lParam1 + 104), s2: (const char *)(lParam2 + 104));
      break;
    case 8:
      result = _V_stricmp(s1: (const char *)(lParam1 + 124), s2: (const char *)(lParam2 + 124));
      break;
    case 9:
      result = *(_DWORD *)(lParam1 + 140) - *(_DWORD *)(lParam2 + 140);
      break;
    case 10:
      v4 = *(float *)(lParam1 + 160);
      v5 = *(float *)(lParam2 + 160);
      if ( v5 <= v4 )
        result = v4 != v5;
      else
        result = -1;
      break;
    default:
      break;
  }
  if ( g_showSounds_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E920
// Name: void ShowSounds_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showSounds_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowSounds_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_444B64;
    for ( j = 11; j != 0; --j )
    {
      if ( v2 == g_showSounds_sortColumn )
        v4 = 2 * (g_showSounds_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EA20
// Name: void ShowSounds_AddViewItem(struct sound_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_AddViewItem(sound_t *pSound)
{
  int rate; // eax
  int channels; // eax
  char *v3; // eax
  char *v4; // edx
  char v5; // cl
  int streamed; // eax
  bool v7; // zf
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  int looped; // eax
  bool v12; // zf
  char *v13; // eax
  char *v14; // edx
  char v15; // cl
  LRESULT v16; // ebx
  tagLVITEMA lvi; // [esp+14h] [ebp-3Ch] BYREF

  if ( g_showSounds_hWnd != nullptr )
  {
    rate = pSound->rate;
    if ( rate < 0 )
      *(_DWORD *)pSound->rateBuff = 4144959;
    else
      sprintf(string: pSound->rateBuff, format: "%5.2f KHz", (float)((float)rate * 0.001));
    if ( pSound->bits < 0 )
      *(_DWORD *)pSound->bitsBuff = 4144959;
    else
      sprintf(string: pSound->bitsBuff, format: "%d", pSound->bits);
    channels = pSound->channels;
    if ( channels < 1 )
    {
      *(_DWORD *)pSound->channelsBuff = 4144959;
    }
    else
    {
      v7 = channels == 2;
      v3 = "Stereo";
      if ( !v7 )
        v3 = "Mono";
      v4 = (char *)(pSound->channelsBuff - v3);
      do
      {
        v5 = *v3;
        v3[(_DWORD)v4] = *v3;
        ++v3;
      }
      while ( v5 != 0 );
    }
    if ( pSound->dataSize < 0 )
      *(_DWORD *)pSound->dataSizeBuff = 4144959;
    else
      sprintf(string: pSound->dataSizeBuff, format: "%d", pSound->dataSize);
    streamed = pSound->streamed;
    v7 = streamed == 0;
    if ( streamed < 0 )
    {
      *(_DWORD *)pSound->streamedBuff = 4144959;
    }
    else
    {
      v8 = "Stream";
      if ( v7 )
        v8 = "Static";
      v9 = (char *)(pSound->streamedBuff - v8);
      do
      {
        v10 = *v8;
        v8[(_DWORD)v9] = *v8;
        ++v8;
      }
      while ( v10 != 0 );
    }
    looped = pSound->looped;
    v12 = looped == 0;
    if ( looped < 0 )
    {
      *(_DWORD *)pSound->loopedBuff = 4144959;
    }
    else
    {
      v13 = "Looped";
      if ( v12 )
        v13 = "One-Shot";
      v14 = (char *)(pSound->loopedBuff - v13);
      do
      {
        v15 = *v13;
        v13[(_DWORD)v14] = *v13;
        ++v13;
      }
      while ( v15 != 0 );
    }
    if ( pSound->quality < 0 )
      *(_DWORD *)pSound->qualityBuff = 4144959;
    else
      sprintf(string: pSound->qualityBuff, format: "%d", pSound->quality);
    sprintf(
      string: pSound->lengthBuff,
      format: "%2.2d:%2.2d:%3.3d",
      (int)pSound->length / 60,
      (int)pSound->length % 60,
      (int)(float)((float)(pSound->length - (float)(int)pSound->length) * 1000.0) % 1000);
    v16 = SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    memset(&lvi.iSubItem, 0, 12);
    lvi.mask = 13;
    lvi.iItem = v16;
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pSound;
    pSound->listIndex = SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EC10
// Name: void ShowSounds_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Refresh()
{
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(command, "vx_soundlist");
  if ( g_connectionState == kCONNECTEDAPP )
    ProcessCommand(strCmdIn: command);
}

//------------------------------------------------------------------------------
// Address: 0x0040EC60
// Name: void ShowSounds_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_SizeWindow(HWND__ *hwnd, int cx, int cy)
{
  int right; // ecx
  int bottom; // eax
  tagRECT rcClient; // [esp+0h] [ebp-10h] BYREF

  right = cx;
  if ( cx == 0 || (bottom = cy, cy == 0) )
  {
    GetClientRect(hWnd: hwnd, lpRect: &rcClient);
    right = rcClient.right;
    bottom = rcClient.bottom;
  }
  SetWindowPos(hWnd: g_showSounds_hWndListView, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: right, cy: bottom, uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0040ECB0
// Name: long ShowSounds_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
UINT __stdcall ShowSounds_WndProc(HWND__ *hwnd, UINT message, WPARAM wParam, unsigned int lParam)
{
  UINT result; // eax
  int v5; // eax
  _DWORD *v6; // eax

  if ( message > 0x4E )
  {
    if ( message == 273 )
    {
      if ( (unsigned __int16)wParam > 0x9CC9u )
      {
        if ( (unsigned __int16)wParam != 50513 )
          return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
        ShowSounds_Play();
      }
      else if ( (unsigned __int16)wParam != 40137 )
      {
        if ( (unsigned __int16)wParam == 40135 )
        {
          ShowSounds_Summary();
          return 0;
        }
        if ( (unsigned __int16)wParam == 40136 )
        {
          ShowSounds_Refresh();
          return 0;
        }
        return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
      }
      return 0;
    }
    result = message - 278;
    if ( message == 278 )
      return result;
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        ShowSounds_SaveConfig();
        g_showSounds_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowSounds_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 != -150 )
  {
    if ( v5 == -108 )
    {
      if ( g_showSounds_sortColumn == *(_DWORD *)(lParam + 16) )
        g_showSounds_sortDescending ^= 1u;
      else
        g_showSounds_sortColumn = *(_DWORD *)(lParam + 16);
      ShowSounds_SortItems();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  v6 = *(_DWORD **)(lParam + 44);
  switch ( *(_DWORD *)(lParam + 20) )
  {
    case 0:
      *(_DWORD *)(lParam + 32) = v6[1];
      result = 0;
      break;
    case 1:
      *(_DWORD *)(lParam + 32) = v6[2];
      result = 0;
      break;
    case 2:
      *(_DWORD *)(lParam + 32) = v6[3];
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6 + 5;
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = v6 + 10;
      result = 0;
      break;
    case 5:
      *(_DWORD *)(lParam + 32) = v6 + 15;
      result = 0;
      break;
    case 6:
      *(_DWORD *)(lParam + 32) = v6 + 21;
      result = 0;
      break;
    case 7:
      *(_DWORD *)(lParam + 32) = v6 + 26;
      result = 0;
      break;
    case 8:
      *(_DWORD *)(lParam + 32) = v6 + 31;
      result = 0;
      break;
    case 9:
      *(_DWORD *)(lParam + 32) = v6 + 36;
      result = 0;
      break;
    case 0xA:
      *(_DWORD *)(lParam + 32) = v6 + 41;
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040EEB0
// Name: bool ShowSounds_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowSounds_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowSounds_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)125;
  wndclass.hCursor = (HICON__ *)"SHOWSOUNDSCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowSounds_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF60
// Name: void ShowSounds_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  char *v2; // edx
  int v3; // esi
  int v4; // edi
  char strCmdIn[256]; // [esp+4h] [ebp-13Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+104h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+130h] [ebp-10h] BYREF

  if ( g_showSounds_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showSounds_hWnd) )
      ShowWindow(hWnd: g_showSounds_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showSounds_hWnd);
  }
  else
  {
    g_showSounds_hWnd = CreateWindowExA(
                          dwExStyle: 0x200u,
                          lpClassName: "SHOWSOUNDSCLASS",
                          lpWindowName: "Sounds",
                          dwStyle: 0x80CF0000,
                          X: 0,
                          Y: 0,
                          nWidth: 700,
                          nHeight: 400,
                          hWndParent: g_hDlgMain,
                          hMenu: nullptr,
                          hInstance: g_hInstance,
                          lpParam: nullptr);
    GetClientRect(hWnd: g_showSounds_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showSounds_hWndListView = CreateWindowExA(
                                  dwExStyle: 0,
                                  lpClassName: "SysListView32",
                                  lpWindowName: &str,
                                  dwStyle: 0x5000000Du,
                                  X: 0,
                                  Y: 0,
                                  nWidth: clientRect.right - clientRect.left,
                                  nHeight: clientRect.bottom - clientRect.top,
                                  hWndParent: g_showSounds_hWnd,
                                  hMenu: (HMENU)0x64,
                                  hInstance: g_hInstance,
                                  lpParam: nullptr);
    for ( i = 0; i < 121; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = *(char **)((char *)&g_showSounds_Labels[0].name + i * 4);
      lvc.cx = dword_444B5C[i];
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.pszText = v2;
      SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v3 = 0;
    if ( g_showSounds_numSounds > 0 )
    {
      v4 = 0;
      do
      {
        ShowSounds_AddViewItem(pSound: &g_showSounds_pSounds[v4]);
        ++v3;
        ++v4;
      }
      while ( v3 < g_showSounds_numSounds );
    }
    ShowSounds_SortItems();
    if ( g_showSounds_windowRect.right != 0 && g_showSounds_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_showSounds_hWnd,
        X: g_showSounds_windowRect.left,
        Y: g_showSounds_windowRect.top,
        nWidth: g_showSounds_windowRect.right - g_showSounds_windowRect.left,
        nHeight: g_showSounds_windowRect.bottom - g_showSounds_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_showSounds_hWnd, nCmdShow: 1);
    strcpy(strCmdIn, "vx_soundlist");
    if ( g_connectionState == kCONNECTEDAPP )
      ProcessCommand(strCmdIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F3D0
// Name: int rc_SoundList(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall rc_SoundList@<eax>(unsigned int a1@<ebx>, char *commandPtr, unsigned int nDataLength)
{
  int m_Size; // edi
  int v4; // ebx
  char *formatString; // esi
  const char *v6; // edi
  int v7; // eax
  const char *v8; // ecx
  int v9; // edx
  char v10; // al
  char *v11; // eax
  unsigned int v12; // edi
  char *v13; // eax
  char *v14; // eax
  int rate; // eax
  float v16; // xmm0_4
  BOOL v17; // edi
  char prefixString[256]; // [esp+8h] [ebp-120h] BYREF
  unsigned int v21; // [esp+108h] [ebp-20h]
  CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > pLocalList; // [esp+10Ch] [ebp-1Ch] BYREF
  int i; // [esp+120h] [ebp-8h]
  char *v24; // [esp+124h] [ebp-4h]

  memset(&pLocalList, 0, sizeof(pLocalList));
  rc_Helper_UnpackListOfThings<xrSound_t>(vOutList: &pLocalList, pStringIn: (int)commandPtr, nDataLength);
  ShowSounds_Clear();
  m_Size = pLocalList.m_Size;
  g_showSounds_numSounds = pLocalList.m_Size;
  g_showSounds_pSounds = (sound_t *)operator new(nSize: 180 * pLocalList.m_Size);
  memset(dst: (unsigned __int8 *)g_showSounds_pSounds, value: 0, count: 180 * m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    formatString = pLocalList.m_Memory.m_pMemory->formatString;
    v21 = -256 - (unsigned int)pLocalList.m_Memory.m_pMemory;
    for ( i = m_Size; i != 0; --i )
    {
      v24 = *((char **)formatString + 16);
      *((_DWORD *)formatString + 16) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 17);
      *((_DWORD *)formatString + 17) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 18);
      *((_DWORD *)formatString + 18) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 19);
      *((_DWORD *)formatString + 19) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 20);
      *((_DWORD *)formatString + 20) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 21);
      *((_DWORD *)formatString + 21) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 22);
      *((_DWORD *)formatString + 22) = _byteswap_ulong((unsigned int)v24);
      v24 = *((char **)formatString + 23);
      v6 = formatString - 256;
      for ( *((_DWORD *)formatString + 23) = _byteswap_ulong((unsigned int)v24); *v6 != 0; ++v6 )
      {
        if ( isalnum(c: *v6) != 0 )
          break;
        if ( *v6 == 95 )
          break;
      }
      v7 = ((int (__thiscall *)(IMemAlloc *, unsigned int, unsigned int))_g_pMemAlloc->Alloc_2)(
             a1: _g_pMemAlloc,
             a2: strlen(v6) + 1,
             a3: a1);
      v24 = (char *)v7;
      if ( v7 != 0 )
      {
        v8 = v6;
        v9 = v7 - (_DWORD)v6;
        do
        {
          v10 = *v8;
          v8[v9] = *v8;
          ++v8;
        }
        while ( v10 != 0 );
        v11 = v24;
      }
      else
      {
        v11 = nullptr;
      }
      v12 = &v6[-v21] - formatString - (unsigned int)pLocalList.m_Memory.m_pMemory;
      g_showSounds_pSounds[v4].pName = v11;
      memcpy(dst: (unsigned __int8 *)prefixString, src: (unsigned __int8 *)formatString - 256, count: v12);
      prefixString[v12] = 0;
      a1 = strlen(prefixString) + 1;
      v13 = (char *)((int (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc);
      if ( v13 != nullptr )
        strcpy(v13, prefixString);
      else
        v13 = nullptr;
      g_showSounds_pSounds[v4].pPrefix = v13;
      if ( formatString != nullptr
        && (v14 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(formatString) + 1)) != nullptr )
      {
        strcpy(v14, formatString);
      }
      else
      {
        v14 = nullptr;
      }
      g_showSounds_pSounds[v4].pFormat = v14;
      g_showSounds_pSounds[v4].rate = *((_DWORD *)formatString + 16);
      g_showSounds_pSounds[v4].bits = *((_DWORD *)formatString + 17);
      g_showSounds_pSounds[v4].channels = *((_DWORD *)formatString + 18);
      g_showSounds_pSounds[v4].dataSize = *((_DWORD *)formatString + 20);
      g_showSounds_pSounds[v4].numSamples = *((_DWORD *)formatString + 21);
      g_showSounds_pSounds[v4].streamed = *((_DWORD *)formatString + 22);
      g_showSounds_pSounds[v4].looped = *((_DWORD *)formatString + 19);
      g_showSounds_pSounds[v4].quality = *((_DWORD *)formatString + 23);
      rate = g_showSounds_pSounds[v4].rate;
      if ( rate <= 0 )
        v16 = 0.0;
      else
        v16 = (float)g_showSounds_pSounds[v4].numSamples / (float)rate;
      g_showSounds_pSounds[v4].length = v16;
      ShowSounds_AddViewItem(pSound: &g_showSounds_pSounds[v4]);
      formatString += 352;
      ++v4;
    }
    m_Size = pLocalList.m_Size;
  }
  ShowSounds_SortItems();
  v17 = m_Size != 0;
  if ( pLocalList.m_Memory.m_nGrowSize >= 0 && pLocalList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLocalList.m_Memory.m_pMemory);
  return v17;
}
