// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_sounds.cpp
// Functions: 24
// ============================================================

#include "utils\xbox\vxconsole\show_sounds.h"

//------------------------------------------------------------------------------
// Address: 0x0041C2A0
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
// Address: 0x0041C350
// Name: void ShowSounds_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showSoundsSortColumn", defValue: 0, value: &g_showSounds_sortColumn);
  Sys_GetRegistryInteger(keyName: "showSoundsSortDescending", defValue: 0, value: &g_showSounds_sortDescending);
  Sys_GetRegistryString(keyName: "showSoundsWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
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
// Address: 0x0041C400
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
    g_showSounds_pSounds = nullptr;
    g_showSounds_numSounds = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C490
// Name: void ShowSounds_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Export()
{
  int v0; // ebx
  _iobuf *v1; // esi
  label_t *v2; // edi
  int v3; // ebx
  int v4; // edi
  char logFilename[260]; // [esp+4h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+108h] [ebp-58h] BYREF

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_showSounds_hWnd;
  ofn.lpstrFile = logFilename;
  logFilename[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "Excel CSV";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = "c:\\";
  ofn.Flags = 2048;
  if ( GetOpenFileNameA(a1: &ofn) )
  {
    Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 0x104u, bForce: false);
    v1 = fopen(file: logFilename, mode: "wt+");
    if ( v1 != nullptr )
    {
      v2 = g_showSounds_Labels;
      do
      {
        fprintf(str: v1, format: "\"%s\"", v2->name);
        if ( v0 != 10 )
          fprintf(str: v1, format: ",");
        v2 = (label_t *)((char *)v2 + 44);
        ++v0;
      }
      while ( (int)v2 < (int)&vec2_invalid_17 );
      fprintf(str: v1, format: "\n");
      v3 = 0;
      if ( g_showSounds_numSounds > 0 )
      {
        v4 = 0;
        do
        {
          fprintf(str: v1, format: "\"%s\"", g_showSounds_pSounds[v4].pName);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].pPrefix);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].pFormat);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].rateBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].bitsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].channelsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].dataSizeBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].streamedBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].loopedBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].qualityBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showSounds_pSounds[v4].lengthBuff);
          fprintf(str: v1, format: "\n");
          ++v3;
          ++v4;
        }
        while ( v3 < g_showSounds_numSounds );
      }
      fclose(stream: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C6C0
// Name: void ShowSounds_Play(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Play()
{
  LRESULT v0; // esi
  char command[256]; // [esp+0h] [ebp-13Ch] BYREF
  tagLVITEMA lvitem; // [esp+100h] [ebp-3Ch] BYREF

  if ( g_connectedToApp )
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
// Address: 0x0041C750
// Name: void ShowSounds_StopAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_StopAllSounds()
{
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: "stopsound");
}

//------------------------------------------------------------------------------
// Address: 0x0041C770
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
// Address: 0x0041C8E0
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
    v3 = byte_4663AC;
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
// Address: 0x0041C9E0
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
// Address: 0x0041CBD0
// Name: void ShowSounds_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Refresh()
{
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: "vx_soundlist");
}

//------------------------------------------------------------------------------
// Address: 0x0041CBF0
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
// Address: 0x0041CC40
// Name: void ShowSounds_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSounds_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  int v2; // ecx
  char *v3; // edx
  int v4; // esi
  int v5; // edi
  tagLVCOLUMNA lvc; // [esp+0h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+2Ch] [ebp-10h] BYREF

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
                                  lpWindowName: &defValue,
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
      v2 = dword_4663A4[i];
      v3 = *(char **)((char *)&g_showSounds_Labels[0].name + i * 4);
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.cx = v2;
      lvc.mask = 15;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showSounds_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v4 = 0;
    if ( g_showSounds_numSounds > 0 )
    {
      v5 = 0;
      do
      {
        ShowSounds_AddViewItem(pSound: &g_showSounds_pSounds[v5]);
        ++v4;
        ++v5;
      }
      while ( v4 < g_showSounds_numSounds );
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
    if ( g_connectedToApp )
      ProcessCommand(strCmdIn: "vx_soundlist");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CE50
// Name: int rc_SoundList(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_SoundList(char *commandPtr)
{
  char *Token; // eax
  char *v2; // eax
  char *v3; // eax
  xrSound_t *v4; // ebx
  int v5; // edi
  int v6; // eax
  int *p_rate; // esi
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  const char *v13; // ebx
  char *v14; // eax
  unsigned int v15; // ebx
  int rate; // eax
  float v17; // xmm0_4
  int v18; // esi
  char prefixString[256]; // [esp+4h] [ebp-120h] BYREF
  xrSound_t *pLocalList; // [esp+104h] [ebp-20h]
  int i; // [esp+108h] [ebp-1Ch]
  int retVal; // [esp+10Ch] [ebp-18h]
  int v24; // [esp+110h] [ebp-14h]
  int retAddr; // [esp+114h] [ebp-10h] BYREF
  int xboxRetVal; // [esp+118h] [ebp-Ch] BYREF
  int soundList; // [esp+11Ch] [ebp-8h] BYREF
  int numSounds; // [esp+120h] [ebp-4h] BYREF

  ShowSounds_Clear();
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &numSounds);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%x", &soundList);
  v3 = GetToken(ppTokenStream: &commandPtr);
  if ( *v3 == 0 )
    return -1;
  sscanf(string: v3, format: "%x", &retAddr);
  v4 = (xrSound_t *)operator new(nSize: 352 * numSounds);
  v5 = 0;
  pLocalList = v4;
  memset(dst: (unsigned __int8 *)v4, value: 0, count: 352 * numSounds);
  g_showSounds_numSounds = numSounds;
  g_showSounds_pSounds = (sound_t *)operator new(nSize: 180 * numSounds);
  memset(dst: (unsigned __int8 *)g_showSounds_pSounds, value: 0, count: 180 * numSounds);
  DmGetMemory(a1: soundList, a2: 352 * numSounds, a3: v4, a4: 0);
  v6 = numSounds;
  i = 0;
  if ( numSounds > 0 )
  {
    p_rate = &v4->rate;
    retVal = -320 - (_DWORD)v4;
    do
    {
      v24 = *p_rate;
      v8 = p_rate[1];
      *p_rate = _byteswap_ulong(v24);
      v24 = v8;
      p_rate[1] = _byteswap_ulong(v8);
      v24 = p_rate[2];
      v9 = p_rate[3];
      p_rate[2] = _byteswap_ulong(v24);
      v24 = v9;
      v10 = p_rate[4];
      p_rate[3] = _byteswap_ulong(v9);
      v24 = v10;
      p_rate[4] = _byteswap_ulong(v10);
      v24 = p_rate[5];
      v11 = p_rate[6];
      p_rate[5] = _byteswap_ulong(v24);
      v24 = v11;
      v12 = p_rate[7];
      p_rate[6] = _byteswap_ulong(v11);
      v24 = v12;
      v13 = (const char *)(p_rate - 80);
      for ( p_rate[7] = _byteswap_ulong(v12); *v13 != 0; ++v13 )
      {
        if ( isalnum(c: *v13) != 0 )
          break;
        if ( *v13 == 95 )
          break;
      }
      v14 = MemAlloc_StrDup(pString: v13);
      v15 = &v13[-retVal] - (const char *)p_rate - (_DWORD)pLocalList;
      g_showSounds_pSounds[v5].pName = v14;
      memcpy(dst: (unsigned __int8 *)prefixString, src: (unsigned __int8 *)p_rate - 320, count: v15);
      prefixString[v15] = 0;
      g_showSounds_pSounds[v5].pPrefix = MemAlloc_StrDup(pString: prefixString);
      g_showSounds_pSounds[v5].pFormat = MemAlloc_StrDup(pString: (const char *)p_rate - 64);
      g_showSounds_pSounds[v5].rate = *p_rate;
      g_showSounds_pSounds[v5].bits = p_rate[1];
      g_showSounds_pSounds[v5].channels = p_rate[2];
      g_showSounds_pSounds[v5].dataSize = p_rate[4];
      g_showSounds_pSounds[v5].numSamples = p_rate[5];
      g_showSounds_pSounds[v5].streamed = p_rate[6];
      g_showSounds_pSounds[v5].looped = p_rate[3];
      g_showSounds_pSounds[v5].quality = p_rate[7];
      rate = g_showSounds_pSounds[v5].rate;
      if ( rate <= 0 )
        v17 = 0.0;
      else
        v17 = (float)g_showSounds_pSounds[v5].numSamples / (float)rate;
      g_showSounds_pSounds[v5].length = v17;
      ShowSounds_AddViewItem(pSound: &g_showSounds_pSounds[v5]);
      v6 = numSounds;
      p_rate += 88;
      ++v5;
      ++i;
    }
    while ( i < numSounds );
    v4 = pLocalList;
  }
  v18 = v6;
  retVal = v6;
  xboxRetVal = _byteswap_ulong(v6);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = SoundList( 0x%8.8x, 0x%8.8x )\n", v18, numSounds, soundList);
  free(pMem: v4);
  ShowSounds_SortItems();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D190
// Name: public: void CUtlMemory<struct CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
        CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCountedStringPoolBase<unsigned short>::hash_item_t *)_g_pMemAlloc->Realloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: m_pMemory,
                                                                                 a3: v7);
    else
      this->m_pMemory = (CCountedStringPoolBase<unsigned short>::hash_item_t *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D230
// Name: public: void CUtlMemory<struct CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
        CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCountedStringPoolBase<unsigned int>::hash_item_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CCountedStringPoolBase<unsigned int>::hash_item_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D2D0
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D360
// Name: public: void CUtlMemory<unsigned int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned int,int>::Grow(CUtlMemory<unsigned int,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned int *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D540
// Name: public: CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned short> *__thiscall CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
        CCountedStringPoolBase<unsigned short> *this,
        StringPoolCase_t caseSensitivity)
{
  int i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int v7; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned short>_vtbl *)&CCountedStringPoolBase<unsigned short>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
      this: &this->m_Elements.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  m_pMemory = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041D620
// Name: public: void CCountedStringPoolBase<unsigned short>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned short>::FreeAll(CCountedStringPoolBase<unsigned short> *this)
{
  int i; // eax
  int v3; // edi
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *v6; // ecx
  int v7; // eax

  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v3 = 0;
  for ( this->m_FreeListStart = 0; v3 < this->m_Elements.m_Size; ++v3 )
  {
    m_pMemory = this->m_Elements.m_Memory.m_pMemory;
    if ( m_pMemory[v3].pString != nullptr )
    {
      free(pMem: m_pMemory[v3].pString);
      this->m_Elements.m_Memory.m_pMemory[v3].pString = nullptr;
      this->m_Elements.m_Memory.m_pMemory[v3].nReferenceCount = 0;
      this->m_Elements.m_Memory.m_pMemory[v3].nNextElement = 0;
    }
  }
  this->m_Elements.m_Size = 0;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount < 1 )
    CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
      this: &this->m_Elements.m_Memory,
      num: 1 - m_nAllocationCount);
  ++this->m_Elements.m_Size;
  v6 = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - 1;
  this->m_Elements.m_pElements = v6;
  if ( v7 > 0 )
    _V_memmove(dest: &v6[1], src: v6, count: 8 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D6E0
// Name: public: CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
        CCountedStringPoolBase<unsigned int> *this,
        StringPoolCase_t caseSensitivity)
{
  int i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  int v7; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)&CCountedStringPoolBase<unsigned int>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
      this: &this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: &this->m_Elements.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  m_pMemory = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041D7C0
// Name: public: void CCountedStringPoolBase<unsigned int>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned int>::FreeAll(CCountedStringPoolBase<unsigned int> *this)
{
  int v2; // edi
  int i; // eax
  int v4; // ebx
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *v8; // ecx
  int v9; // eax

  v2 = 0;
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v4 = 0;
  for ( this->m_FreeListStart = 0; v4 < this->m_Elements.m_Size; ++v2 )
  {
    m_pMemory = this->m_Elements.m_Memory.m_pMemory;
    if ( m_pMemory[v2].pString != nullptr )
    {
      free(pMem: m_pMemory[v2].pString);
      this->m_Elements.m_Memory.m_pMemory[v2].pString = nullptr;
      this->m_Elements.m_Memory.m_pMemory[v2].nReferenceCount = 0;
      this->m_Elements.m_Memory.m_pMemory[v2].nNextElement = 0;
    }
    ++v4;
  }
  this->m_Elements.m_Size = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: &this->m_Elements.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  v8 = this->m_Elements.m_Memory.m_pMemory;
  v9 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = v8;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 12 * v9);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D910
// Name: void ShowSounds_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShowSounds_Summary(int a1@<ebp>)
{
  int v1; // eax
  sound_t *v2; // ecx
  int v3; // esi
  void *m_nGrowSize; // eax
  void *v5; // eax
  void *v6; // eax
  void *m_i32; // eax
  void *v8; // eax
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  char v12[12]; // [esp+18h] [ebp-4FCh] BYREF
  char buff[1024]; // [esp+24h] [ebp-4F0h] BYREF
  CUtlFilenameSymbolTable StreamedSoundSymbolTable; // [esp+424h] [ebp-F0h] BYREF
  CUtlFilenameSymbolTable StaticSoundSymbolTable; // [esp+494h] [ebp-80h] BYREF
  int v16; // [esp+504h] [ebp-10h]
  int i; // [esp+508h] [ebp-Ch]
  int totalStatic; // [esp+50Ch] [ebp-8h]
  int retaddr; // [esp+514h] [ebp+0h]

  i = a1;
  totalStatic = retaddr;
  CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
    this: (CCountedStringPoolBase<unsigned short> *)&buff[1012],
    caseSensitivity: StringPoolCaseInsensitive);
  CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
    this: (CCountedStringPoolBase<unsigned int> *)&StreamedSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements,
    caseSensitivity: StringPoolCaseInsensitive);
  StreamedSoundSymbolTable.m_FileStringPool.m_Elements.m_pElements = nullptr;
  StreamedSoundSymbolTable.m_FileStringPool.m_FreeListStart = 0;
  CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
    this: (CCountedStringPoolBase<unsigned short> *)&StreamedSoundSymbolTable.m_FileStringPool.m_caseSensitivity,
    caseSensitivity: StringPoolCaseInsensitive);
  CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
    this: (CCountedStringPoolBase<unsigned int> *)&StaticSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements,
    caseSensitivity: StringPoolCaseInsensitive);
  v1 = g_showSounds_numSounds;
  StaticSoundSymbolTable.m_FileStringPool.m_Elements.m_pElements = nullptr;
  StaticSoundSymbolTable.m_FileStringPool.m_FreeListStart = 0;
  v16 = 0;
  StaticSoundSymbolTable.m_lock.m_writerId = 0;
  StaticSoundSymbolTable.m_lock.m_lockInfo.m_i32 = 0;
  if ( g_showSounds_numSounds > 0 )
  {
    v2 = g_showSounds_pSounds;
    v3 = 0;
    do
    {
      if ( v2[v3].streamed != 0 )
      {
        if ( CUtlFilenameSymbolTable::FindFileName(
               this: (CUtlFilenameSymbolTable *)&buff[1012],
               pFileName: v2[v3].pName) != nullptr )
          goto LABEL_8;
        CUtlFilenameSymbolTable::FindOrAddFileName(
          this: (CUtlFilenameSymbolTable *)&buff[1012],
          pFileName: g_showSounds_pSounds[v3].pName);
        v2 = g_showSounds_pSounds;
        v16 += g_showSounds_pSounds[v3].dataSize;
      }
      else
      {
        if ( CUtlFilenameSymbolTable::FindFileName(
               this: (CUtlFilenameSymbolTable *)&StreamedSoundSymbolTable.m_FileStringPool.m_caseSensitivity,
               pFileName: v2[v3].pName) != nullptr )
        {
LABEL_8:
          v2 = g_showSounds_pSounds;
          goto LABEL_9;
        }
        CUtlFilenameSymbolTable::FindOrAddFileName(
          this: (CUtlFilenameSymbolTable *)&StreamedSoundSymbolTable.m_FileStringPool.m_caseSensitivity,
          pFileName: g_showSounds_pSounds[v3].pName);
        v2 = g_showSounds_pSounds;
        StaticSoundSymbolTable.m_lock.m_writerId += g_showSounds_pSounds[v3].dataSize;
      }
LABEL_9:
      v1 = g_showSounds_numSounds;
      ++v3;
      ++StaticSoundSymbolTable.m_lock.m_lockInfo.m_i32;
    }
    while ( (int)StaticSoundSymbolTable.m_lock.m_lockInfo.m_i32 < g_showSounds_numSounds );
  }
  sprintf(
    string: v12,
    format: "Entries:\t\t\t%d\nStatic Memory:\t\t%.2f MB\nStreamed Memory:\t\t%.2f MB\n",
    v1,
    (float)((float)(int)StaticSoundSymbolTable.m_lock.m_writerId * 0.00000095367432),
    (float)((float)v16 * 0.00000095367432));
  MessageBoxA(hWnd: g_showSounds_hWnd, lpText: v12, lpCaption: "Sound Summary", uType: 0);
  StaticSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements = (CCountedStringPoolBase<unsigned short>::hash_item_t *)&CCountedStringPoolBase<unsigned int>::`vftable';
  CCountedStringPoolBase<unsigned int>::FreeAll(this: (CCountedStringPoolBase<unsigned int> *)&StaticSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements);
  m_nGrowSize = (void *)StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize;
  StaticSoundSymbolTable.m_FileStringPool.m_Elements.m_Memory.m_pMemory = nullptr;
  if ( (int)StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize);
      m_nGrowSize = nullptr;
      StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Size = 0;
  }
  StaticSoundSymbolTable.m_FileStringPool.m_Elements.m_Memory.m_nAllocationCount = (int)m_nGrowSize;
  if ( (int)StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( m_nGrowSize != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nGrowSize);
      StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Size = 0;
  }
  v5 = *(void **)&StaticSoundSymbolTable.m_PathStringPool.m_FreeListStart;
  StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_pMemory = nullptr;
  if ( (int)StaticSoundSymbolTable.m_FileStringPool.__vftable >= 0 )
  {
    if ( *(_DWORD *)&StaticSoundSymbolTable.m_PathStringPool.m_FreeListStart != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&StaticSoundSymbolTable.m_PathStringPool.m_FreeListStart);
      v5 = nullptr;
      *(_DWORD *)&StaticSoundSymbolTable.m_PathStringPool.m_FreeListStart = 0;
    }
    StaticSoundSymbolTable.m_PathStringPool.m_caseSensitivity = StringPoolCaseInsensitive;
  }
  StaticSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nAllocationCount = (int)v5;
  if ( (int)StaticSoundSymbolTable.m_FileStringPool.__vftable >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      *(_DWORD *)&StaticSoundSymbolTable.m_PathStringPool.m_FreeListStart = 0;
    }
    StaticSoundSymbolTable.m_PathStringPool.m_caseSensitivity = StringPoolCaseInsensitive;
  }
  StreamedSoundSymbolTable.m_FileStringPool.m_caseSensitivity = (StringPoolCase_t)&CCountedStringPoolBase<unsigned short>::`vftable';
  CCountedStringPoolBase<unsigned short>::FreeAll(this: (CCountedStringPoolBase<unsigned short> *)&StreamedSoundSymbolTable.m_FileStringPool.m_caseSensitivity);
  v6 = (void *)StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize;
  StaticSoundSymbolTable.m_PathStringPool.m_Elements.m_Memory.m_pMemory = nullptr;
  if ( (int)StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize);
      v6 = nullptr;
      StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Size = 0;
  }
  StaticSoundSymbolTable.m_PathStringPool.m_Elements.m_Memory.m_nAllocationCount = (int)v6;
  if ( (int)StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Size = 0;
  }
  m_i32 = (void *)StreamedSoundSymbolTable.m_lock.m_lockInfo.m_i32;
  StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_pMemory = nullptr;
  if ( (int)StaticSoundSymbolTable.m_PathStringPool.__vftable >= 0 )
  {
    if ( StreamedSoundSymbolTable.m_lock.m_lockInfo.m_i32 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)StreamedSoundSymbolTable.m_lock.m_lockInfo.m_i32);
      m_i32 = nullptr;
      StreamedSoundSymbolTable.m_lock.m_lockInfo.m_i32 = 0;
    }
    StreamedSoundSymbolTable.m_lock.m_writerId = 0;
  }
  StaticSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nAllocationCount = (int)m_i32;
  if ( (int)StaticSoundSymbolTable.m_PathStringPool.__vftable >= 0 )
  {
    if ( m_i32 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_i32);
      StreamedSoundSymbolTable.m_lock.m_lockInfo.m_i32 = 0;
    }
    StreamedSoundSymbolTable.m_lock.m_writerId = 0;
  }
  StreamedSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements = (CCountedStringPoolBase<unsigned short>::hash_item_t *)&CCountedStringPoolBase<unsigned int>::`vftable';
  CCountedStringPoolBase<unsigned int>::FreeAll(this: (CCountedStringPoolBase<unsigned int> *)&StreamedSoundSymbolTable.m_PathStringPool.m_Elements.m_pElements);
  v8 = (void *)StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize;
  StreamedSoundSymbolTable.m_FileStringPool.m_Elements.m_Memory.m_pMemory = nullptr;
  if ( (int)StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize);
      v8 = nullptr;
      StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Size = 0;
  }
  StreamedSoundSymbolTable.m_FileStringPool.m_Elements.m_Memory.m_nAllocationCount = (int)v8;
  if ( (int)StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Size = 0;
  }
  v9 = *(void **)&StreamedSoundSymbolTable.m_PathStringPool.m_FreeListStart;
  StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_pMemory = nullptr;
  if ( (int)StreamedSoundSymbolTable.m_FileStringPool.__vftable >= 0 )
  {
    if ( *(_DWORD *)&StreamedSoundSymbolTable.m_PathStringPool.m_FreeListStart != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&StreamedSoundSymbolTable.m_PathStringPool.m_FreeListStart);
      v9 = nullptr;
      *(_DWORD *)&StreamedSoundSymbolTable.m_PathStringPool.m_FreeListStart = 0;
    }
    StreamedSoundSymbolTable.m_PathStringPool.m_caseSensitivity = StringPoolCaseInsensitive;
  }
  StreamedSoundSymbolTable.m_FileStringPool.m_HashTable.m_Memory.m_nAllocationCount = (int)v9;
  if ( (int)StreamedSoundSymbolTable.m_FileStringPool.__vftable >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      *(_DWORD *)&StreamedSoundSymbolTable.m_PathStringPool.m_FreeListStart = 0;
    }
    StreamedSoundSymbolTable.m_PathStringPool.m_caseSensitivity = StringPoolCaseInsensitive;
  }
  *(_DWORD *)&buff[1012] = &CCountedStringPoolBase<unsigned short>::`vftable';
  CCountedStringPoolBase<unsigned short>::FreeAll(this: (CCountedStringPoolBase<unsigned short> *)&buff[1012]);
  v10 = (void *)StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize;
  StreamedSoundSymbolTable.m_PathStringPool.m_Elements.m_Memory.m_pMemory = nullptr;
  if ( (int)StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize);
      v10 = nullptr;
      StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Size = 0;
  }
  StreamedSoundSymbolTable.m_PathStringPool.m_Elements.m_Memory.m_nAllocationCount = (int)v10;
  if ( (int)StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_pElements >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nGrowSize = 0;
    }
    StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Size = 0;
  }
  v11 = *(void **)&buff[1016];
  StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_pMemory = nullptr;
  if ( (int)StreamedSoundSymbolTable.m_PathStringPool.__vftable >= 0 )
  {
    if ( *(_DWORD *)&buff[1016] != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&buff[1016]);
      v11 = nullptr;
      *(_DWORD *)&buff[1016] = 0;
    }
    *(_DWORD *)&buff[1020] = 0;
  }
  StreamedSoundSymbolTable.m_PathStringPool.m_HashTable.m_Memory.m_nAllocationCount = (int)v11;
  if ( (int)StreamedSoundSymbolTable.m_PathStringPool.__vftable >= 0 && v11 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x0041DD80
// Name: long ShowSounds_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
UINT __stdcall ShowSounds_WndProc(HWND__ *hwnd, UINT message, WPARAM wParam, unsigned int lParam)
{
  UINT result; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( message > 0x4E )
  {
    if ( message == 273 )
    {
      if ( (unsigned __int16)wParam <= 0x9CC9u )
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x9CC9u:
            ShowSounds_Export();
            return 0;
          case 0x9CC7u:
            ShowSounds_Summary(a1: (int)&savedregs);
            return 0;
          case 0x9CC8u:
            ShowSounds_Refresh();
            return 0;
          default:
            break;
        }
        return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
      }
      if ( (unsigned __int16)wParam == 50513 )
      {
        ShowSounds_Play();
        return 0;
      }
      if ( (unsigned __int16)wParam == 50597 )
      {
        ShowSounds_StopAllSounds();
        return 0;
      }
    }
    else
    {
      result = message - 278;
      if ( message == 278 )
        return result;
    }
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
// Address: 0x0041DFA0
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
