// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_textures.cpp
// Functions: 36
// ============================================================

#include "utils\xbox\vxconsole\show_textures.h"

//------------------------------------------------------------------------------
// Address: 0x0041E040
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0041E070
// Name: void ShowTextures_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showTexturesFullPath", value: g_showTextures_fullPath);
  Sys_SetRegistryInteger(keyName: "showTexturesCurrentFrame", value: g_showTextures_currentFrame);
  Sys_SetRegistryInteger(keyName: "showTexturesSortColumn", value: g_showTextures_sortColumn);
  Sys_SetRegistryInteger(keyName: "showTexturesSortDescending", value: g_showTextures_sortDescending);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showTextures_hWnd, lpwndpl: &wp);
  g_showTextures_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showTexturesWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x0041E140
// Name: void ShowTextures_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showTexturesFullPath", defValue: 1, value: &g_showTextures_fullPath);
  Sys_GetRegistryInteger(keyName: "showTexturesCurrentFrame", defValue: 0, value: &g_showTextures_currentFrame);
  Sys_GetRegistryInteger(keyName: "showTexturesSortColumn", defValue: 0, value: &g_showTextures_sortColumn);
  Sys_GetRegistryInteger(keyName: "showTexturesSortDescending", defValue: 0, value: &g_showTextures_sortDescending);
  Sys_GetRegistryString(keyName: "showTexturesWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showTextures_windowRect,
         &g_showTextures_windowRect.top,
         &g_showTextures_windowRect.right,
         &g_showTextures_windowRect.bottom) != 4
    || g_showTextures_windowRect.left < 0
    || g_showTextures_windowRect.top < 0
    || g_showTextures_windowRect.right < 0
    || g_showTextures_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showTextures_windowRect.left = 0;
    *(_QWORD *)&g_showTextures_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E220
// Name: void ShowTextures_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Clear()
{
  int v0; // edi
  int v1; // esi

  if ( g_showTextures_hWnd != nullptr )
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showTextures_pTextures != nullptr )
  {
    v0 = 0;
    if ( g_showTextures_numTextures > 0 )
    {
      v1 = 0;
      do
      {
        free(pMem: g_showTextures_pTextures[v1].pLongName);
        free(pMem: g_showTextures_pTextures[v1].pShortName);
        free(pMem: g_showTextures_pTextures[v1].pGroupName);
        free(pMem: g_showTextures_pTextures[v1].pFormatName);
        ++v0;
        ++v1;
      }
      while ( v0 < g_showTextures_numTextures );
    }
    g_showTextures_pTextures = nullptr;
    g_showTextures_numTextures = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E2C0
// Name: void ShowTextures_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Export()
{
  int v0; // ebx
  _iobuf *v1; // esi
  label_t *v2; // edi
  int v3; // ebx
  int v4; // edi
  const char *v5; // eax
  char logFilename[260]; // [esp+4h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+108h] [ebp-58h] BYREF

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_showTextures_hWnd;
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
      v2 = g_showTextures_Labels;
      do
      {
        fprintf(str: v1, format: "\"%s\"", v2->name);
        if ( v0 != 14 )
          fprintf(str: v1, format: ",");
        v2 = (label_t *)((char *)v2 + 44);
        ++v0;
      }
      while ( (int)v2 < (int)&vec2_invalid_18 );
      fprintf(str: v1, format: "\n");
      v3 = 0;
      if ( g_showTextures_numTextures > 0 )
      {
        v4 = 0;
        do
        {
          if ( g_showTextures_fullPath != 0 )
            fprintf(str: v1, format: "\"%s\"", g_showTextures_pTextures[v4].pLongName);
          else
            fprintf(str: v1, format: "\"%s\"", g_showTextures_pTextures[v4].pShortName);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].staticSizeBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].sizeBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].pGroupName);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].pFormatName);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].widthBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].heightBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].depthBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].numLevelsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].bindsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].refCountBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_cacheStrings[g_showTextures_pTextures[v4].cacheState]);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_loadStrings[g_showTextures_pTextures[v4].loadState]);
          v5 = "PWL";
          if ( g_showTextures_pTextures[v4].pwl == 0 )
            v5 = &defValue;
          fprintf(str: v1, format: ",\"%s\"", v5);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_reducedStrings[g_showTextures_pTextures[v4].reducedState]);
          fprintf(str: v1, format: "\n");
          ++v3;
          ++v4;
        }
        while ( v3 < g_showTextures_numTextures );
      }
      fclose(stream: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E590
// Name: void ShowTextures_DrawTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_DrawTexture()
{
  LRESULT v0; // esi
  int lParam; // esi
  char command[256]; // [esp+0h] [ebp-13Ch] BYREF
  tagLVITEMA lvitem; // [esp+100h] [ebp-3Ch] BYREF

  if ( g_connectedToApp )
  {
    if ( g_showTextures_drawTexture != 0 )
    {
      v0 = SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1042u, wParam: 0, lParam: 0);
      if ( v0 != -1 )
      {
        memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
        lvitem.mask = 4;
        lvitem.iItem = v0;
        SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
        lParam = lvitem.lParam;
        if ( _V_stricmp(s1: *(const char **)(lvitem.lParam + 4), s2: g_showTextures_drawTextureName) != 0 )
        {
          V_strncpy(pDest: g_showTextures_drawTextureName, pSrc: *(const char **)(lParam + 4), maxLen: 260);
          sprintf(string: command, format: "mat_drawTexture %s", *(const char **)(lParam + 4));
          ProcessCommand(strCmdIn: command);
        }
      }
    }
    else if ( g_showTextures_drawTextureName[0] != 0 )
    {
      sprintf(string: command, format: "mat_drawTexture \"\"");
      ProcessCommand(strCmdIn: command);
      g_showTextures_drawTextureName[0] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E690
// Name: void ShowTextures_SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_SetTitle()
{
  HWND v0; // edx
  char *v1; // eax
  char v2; // cl
  char *v3; // eax
  char v4; // cl
  char v5; // [esp-1h] [ebp-81h] BYREF
  char titleBuff[128]; // [esp+0h] [ebp-80h] BYREF

  v0 = g_showTextures_hWnd;
  if ( g_showTextures_hWnd != nullptr )
  {
    strcpy(titleBuff, "Textures ");
    if ( g_showTextures_currentFrame != 0 )
    {
      v1 = &v5;
      do
        v2 = *++v1;
      while ( v2 != 0 );
      strcpy(v1, " [FRAME]");
    }
    if ( g_showTextures_fullPath != 0 )
    {
      v3 = &v5;
      do
        v4 = *++v3;
      while ( v4 != 0 );
      strcpy(v3, " [FULL PATH]");
    }
    SetWindowTextA(hWnd: v0, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E740
// Name: int ShowTextures_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowTextures_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  const char *v4; // eax
  int v5; // eax
  int v6; // ecx
  const char *v7; // [esp-4h] [ebp-4h]

  result = 0;
  switch ( g_showTextures_sortColumn )
  {
    case 0:
      if ( g_showTextures_fullPath != 0 )
      {
        v4 = *(const char **)(lParam1 + 4);
        v7 = *(const char **)(lParam2 + 4);
        goto LABEL_25;
      }
      result = _V_stricmp(s1: *(const char **)(lParam1 + 8), s2: *(const char **)(lParam2 + 8));
      goto LABEL_26;
    case 1:
      result = *(_DWORD *)(lParam1 + 20) - *(_DWORD *)(lParam2 + 20);
      goto LABEL_26;
    case 2:
      result = *(_DWORD *)(lParam1 + 40) - *(_DWORD *)(lParam2 + 40);
      goto LABEL_26;
    case 3:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 12), s2: *(const char **)(lParam2 + 12));
      goto LABEL_26;
    case 4:
      v4 = *(const char **)(lParam1 + 16);
      v7 = *(const char **)(lParam2 + 16);
      goto LABEL_25;
    case 5:
      result = *(_DWORD *)(lParam1 + 60) - *(_DWORD *)(lParam2 + 60);
      goto LABEL_26;
    case 6:
      result = *(_DWORD *)(lParam1 + 80) - *(_DWORD *)(lParam2 + 80);
      goto LABEL_26;
    case 7:
      result = *(_DWORD *)(lParam1 + 100) - *(_DWORD *)(lParam2 + 100);
      goto LABEL_26;
    case 8:
      result = *(_DWORD *)(lParam1 + 120) - *(_DWORD *)(lParam2 + 120);
      goto LABEL_26;
    case 9:
      result = *(_DWORD *)(lParam1 + 140) - *(_DWORD *)(lParam2 + 140);
      goto LABEL_26;
    case 10:
      result = *(_DWORD *)(lParam1 + 160) - *(_DWORD *)(lParam2 + 160);
      goto LABEL_26;
    case 11:
      v7 = g_showTextures_cacheStrings[*(_DWORD *)(lParam2 + 196)];
      v4 = g_showTextures_cacheStrings[*(_DWORD *)(lParam1 + 196)];
      goto LABEL_25;
    case 12:
      v5 = *(_DWORD *)(lParam1 + 188);
      v6 = *(_DWORD *)(lParam2 + 188);
      if ( v5 == v6 )
      {
        result = 0;
      }
      else if ( v5 == 4 )
      {
        result = -1;
      }
      else if ( v6 == 4 )
      {
        result = 1;
      }
      else
      {
        v4 = g_showTextures_loadStrings[v5];
        v7 = g_showTextures_loadStrings[v6];
LABEL_25:
        result = _V_stricmp(s1: v4, s2: v7);
      }
LABEL_26:
      if ( g_showTextures_sortDescending != 0 )
        return -result;
      return result;
    case 13:
      result = *(_DWORD *)(lParam1 + 180) - *(_DWORD *)(lParam2 + 180);
      goto LABEL_26;
    case 14:
      result = _V_stricmp(
                 s1: g_showTextures_reducedStrings[*(_DWORD *)(lParam1 + 184)],
                 s2: g_showTextures_reducedStrings[*(_DWORD *)(lParam2 + 184)]);
      goto LABEL_26;
    default:
      goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E930
// Name: void ShowTextures_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showTextures_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowTextures_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_466624;
    for ( j = 15; j != 0; --j )
    {
      if ( v2 == g_showTextures_sortColumn )
        v4 = 2 * (g_showTextures_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EA30
// Name: void ShowTextures_AddViewItem(struct texture_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_AddViewItem(texture_t *pTexture)
{
  LRESULT v2; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showTextures_hWnd != nullptr )
  {
    sprintf(string: pTexture->staticSizeBuff, format: "%d", pTexture->staticSize);
    sprintf(string: pTexture->sizeBuff, format: "%d", pTexture->size);
    sprintf(string: pTexture->widthBuff, format: "%d", pTexture->width);
    sprintf(string: pTexture->heightBuff, format: "%d", pTexture->height);
    sprintf(string: pTexture->depthBuff, format: "%d", pTexture->depth);
    sprintf(string: pTexture->numLevelsBuff, format: "%d", pTexture->numLevels);
    sprintf(string: pTexture->bindsBuff, format: "%d", pTexture->binds);
    sprintf(string: pTexture->refCountBuff, format: "%d", pTexture->refCount);
    v2 = SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    lvi.mask = 13;
    lvi.iItem = v2;
    memset(&lvi.iSubItem, 0, 12);
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pTexture;
    pTexture->listIndex = SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EB50
// Name: void ShowTextures_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Refresh()
{
  char *v0; // eax
  char v1; // cl
  char v2; // [esp-1h] [ebp-101h] BYREF
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(command, "mat_get_textures");
  if ( g_showTextures_currentFrame == 0 )
  {
    v0 = &v2;
    do
      v1 = *++v0;
    while ( v1 != 0 );
    strcpy(v0, " all");
  }
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: command);
}

//------------------------------------------------------------------------------
// Address: 0x0041EBD0
// Name: void ShowTextures_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_SizeWindow(HWND__ *hwnd, int cx, int cy)
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
  SetWindowPos(
    hWnd: g_showTextures_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0041EC20
// Name: void ShowTextures_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  int v2; // ecx
  char *v3; // edx
  int v4; // esi
  int v5; // edi
  char *v6; // eax
  char v7; // cl
  char v8; // [esp-1h] [ebp-13Dh] BYREF
  char strCmdIn[256]; // [esp+0h] [ebp-13Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+100h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+12Ch] [ebp-10h] BYREF

  if ( g_showTextures_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showTextures_hWnd) )
      ShowWindow(hWnd: g_showTextures_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showTextures_hWnd);
  }
  else
  {
    g_showTextures_hWnd = CreateWindowExA(
                            dwExStyle: 0x200u,
                            lpClassName: "SHOWTEXTURESCLASS",
                            lpWindowName: &defValue,
                            dwStyle: 0x80CF0000,
                            X: 0,
                            Y: 0,
                            nWidth: 700,
                            nHeight: 400,
                            hWndParent: g_hDlgMain,
                            hMenu: nullptr,
                            hInstance: g_hInstance,
                            lpParam: nullptr);
    GetClientRect(hWnd: g_showTextures_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showTextures_hWndListView = CreateWindowExA(
                                    dwExStyle: 0,
                                    lpClassName: "SysListView32",
                                    lpWindowName: &defValue,
                                    dwStyle: 0x50000005u,
                                    X: 0,
                                    Y: 0,
                                    nWidth: clientRect.right - clientRect.left,
                                    nHeight: clientRect.bottom - clientRect.top,
                                    hWndParent: g_showTextures_hWnd,
                                    hMenu: (HMENU)0x64,
                                    hInstance: g_hInstance,
                                    lpParam: nullptr);
    for ( i = 0; i < 165; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = dword_46661C[i];
      v3 = *(char **)((char *)&g_showTextures_Labels[0].name + i * 4);
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.cx = v2;
      lvc.mask = 15;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1036u, wParam: 0x71u, lParam: 113);
    v4 = 0;
    if ( g_showTextures_numTextures > 0 )
    {
      v5 = 0;
      do
      {
        ShowTextures_AddViewItem(pTexture: &g_showTextures_pTextures[v5]);
        ++v4;
        ++v5;
      }
      while ( v4 < g_showTextures_numTextures );
    }
    ShowTextures_SortItems();
    ShowTextures_SetTitle();
    if ( g_showTextures_windowRect.right != 0 && g_showTextures_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_showTextures_hWnd,
        X: g_showTextures_windowRect.left,
        Y: g_showTextures_windowRect.top,
        nWidth: g_showTextures_windowRect.right - g_showTextures_windowRect.left,
        nHeight: g_showTextures_windowRect.bottom - g_showTextures_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_showTextures_hWnd, nCmdShow: 1);
    strcpy(strCmdIn, "mat_get_textures");
    if ( g_showTextures_currentFrame == 0 )
    {
      v6 = &v8;
      do
        v7 = *++v6;
      while ( v7 != 0 );
      strcpy(v6, " all");
    }
    if ( g_connectedToApp )
      ProcessCommand(strCmdIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EE90
// Name: int rc_TextureList(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_TextureList(char *commandPtr)
{
  char *Token; // eax
  char *v2; // eax
  char *v3; // eax
  unsigned __int8 *v4; // esi
  int v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // esi
  const char *v8; // edx
  const char *v9; // ecx
  const char *v10; // edx
  const char *v11; // ecx
  const char *v12; // edx
  const char *v13; // ecx
  const char *v14; // edx
  const char *v15; // ecx
  const char *v16; // edx
  int v17; // eax
  bool v18; // zf
  char *v19; // eax
  char *v20; // edx
  char v21; // cl
  char *v22; // eax
  char v23; // cl
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // edi
  char v29; // [esp+3h] [ebp-225h] BYREF
  char tempName[260]; // [esp+4h] [ebp-224h] BYREF
  char shortName[260]; // [esp+108h] [ebp-120h] BYREF
  int i; // [esp+20Ch] [ebp-1Ch]
  int retVal; // [esp+210h] [ebp-18h]
  int retAddr; // [esp+214h] [ebp-14h] BYREF
  int xboxRetVal; // [esp+218h] [ebp-10h] BYREF
  const char *pFormatName; // [esp+21Ch] [ebp-Ch]
  int textureList; // [esp+220h] [ebp-8h] BYREF
  int numTextures; // [esp+224h] [ebp-4h] BYREF

  ShowTextures_Clear();
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &numTextures);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%x", &textureList);
  v3 = GetToken(ppTokenStream: &commandPtr);
  if ( *v3 == 0 )
    return -1;
  sscanf(string: v3, format: "%x", &retAddr);
  v4 = (unsigned __int8 *)operator new(nSize: 444 * numTextures);
  v5 = 0;
  retVal = (int)v4;
  memset(dst: v4, value: 0, count: 444 * numTextures);
  g_showTextures_numTextures = numTextures;
  g_showTextures_pTextures = (texture_t *)operator new(nSize: 200 * numTextures);
  memset(dst: (unsigned __int8 *)g_showTextures_pTextures, value: 0, count: 200 * numTextures);
  DmGetMemory(a1: textureList, a2: 444 * numTextures, a3: v4, a4: 0);
  v6 = numTextures;
  i = 0;
  if ( numTextures > 0 )
  {
    v7 = v4 + 320;
    do
    {
      pFormatName = *((const char **)v7 + 16);
      v8 = *((const char **)v7 + 17);
      *((_DWORD *)v7 + 16) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v8;
      *((_DWORD *)v7 + 17) = _byteswap_ulong((unsigned int)v8);
      pFormatName = *((const char **)v7 + 18);
      v9 = *((const char **)v7 + 19);
      *((_DWORD *)v7 + 18) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v9;
      v10 = *((const char **)v7 + 20);
      *((_DWORD *)v7 + 19) = _byteswap_ulong((unsigned int)v9);
      pFormatName = v10;
      *((_DWORD *)v7 + 20) = _byteswap_ulong((unsigned int)v10);
      pFormatName = *((const char **)v7 + 21);
      v11 = *((const char **)v7 + 22);
      *((_DWORD *)v7 + 21) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v11;
      v12 = *((const char **)v7 + 23);
      *((_DWORD *)v7 + 22) = _byteswap_ulong((unsigned int)v11);
      pFormatName = v12;
      *((_DWORD *)v7 + 23) = _byteswap_ulong((unsigned int)v12);
      pFormatName = *((const char **)v7 + 24);
      v13 = *((const char **)v7 + 25);
      *((_DWORD *)v7 + 24) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v13;
      v14 = *((const char **)v7 + 26);
      *((_DWORD *)v7 + 25) = _byteswap_ulong((unsigned int)v13);
      pFormatName = v14;
      *((_DWORD *)v7 + 26) = _byteswap_ulong((unsigned int)v14);
      pFormatName = *((const char **)v7 + 28);
      v15 = *((const char **)v7 + 29);
      *((_DWORD *)v7 + 28) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v15;
      v16 = *((const char **)v7 + 30);
      *((_DWORD *)v7 + 29) = _byteswap_ulong((unsigned int)v15);
      pFormatName = v16;
      *((_DWORD *)v7 + 30) = _byteswap_ulong((unsigned int)v16);
      pFormatName = (const char *)(*((_DWORD *)v7 + 27) & 0x80000000 | ((2 * *((_DWORD *)v7 + 27)) >> 1));
      v17 = _byteswap_ulong((unsigned int)pFormatName);
      *((_DWORD *)v7 + 27) = (v17 << 31) ^ (v17 >> 1) & 0x7FFFFFFF;
      g_showTextures_pTextures[v5].pLongName = MemAlloc_StrDup(pString: (const char *)v7 - 320);
      Sys_StripPath(inpath: g_showTextures_pTextures[v5].pLongName, outpath: shortName, outPathLen: 0x104u);
      g_showTextures_pTextures[v5].pShortName = MemAlloc_StrDup(pString: shortName);
      g_showTextures_pTextures[v5].pGroupName = MemAlloc_StrDup(pString: (const char *)v7 - 64);
      pFormatName = (const char *)v7;
      v18 = V_strncasecmp(s1: (const char *)v7, s2: "D3DFMT_", n: 7) == 0;
      v19 = (char *)(v7 + 7);
      if ( !v18 )
        v19 = (char *)v7;
      if ( *((_DWORD *)v7 + 23) != 0 )
      {
        v20 = (char *)(tempName - v19);
        do
        {
          v21 = *v19;
          v19[(_DWORD)v20] = *v19;
          ++v19;
        }
        while ( v21 != 0 );
        v22 = &v29;
        do
          v23 = *++v22;
        while ( v23 != 0 );
        strcpy(v22, " (SRGB)");
        v19 = tempName;
      }
      g_showTextures_pTextures[v5].pFormatName = MemAlloc_StrDup(pString: v19);
      g_showTextures_pTextures[v5].staticSize = *((_DWORD *)v7 + 16) - ((2 * *((_DWORD *)v7 + 27)) >> 1);
      g_showTextures_pTextures[v5].size = *((_DWORD *)v7 + 16);
      g_showTextures_pTextures[v5].width = *((_DWORD *)v7 + 17);
      g_showTextures_pTextures[v5].height = *((_DWORD *)v7 + 18);
      g_showTextures_pTextures[v5].depth = *((_DWORD *)v7 + 19);
      g_showTextures_pTextures[v5].numLevels = *((_DWORD *)v7 + 20);
      g_showTextures_pTextures[v5].binds = *((_DWORD *)v7 + 21);
      g_showTextures_pTextures[v5].refCount = *((_DWORD *)v7 + 22);
      g_showTextures_pTextures[v5].edram = *((_DWORD *)v7 + 24);
      g_showTextures_pTextures[v5].pwl = *((_DWORD *)v7 + 29);
      v24 = 0;
      if ( *((int *)v7 + 30) < 3 )
        v24 = *((_DWORD *)v7 + 30);
      g_showTextures_pTextures[v5].reducedState = v24;
      if ( *((_DWORD *)v7 + 24) != 0
        || V_stristr(pStr: g_showTextures_pTextures[v5].pGroupName, pSearch: "RenderTarget") != nullptr )
      {
        v25 = 0;
      }
      else if ( *((_DWORD *)v7 + 25) != 0 )
      {
        v25 = 1;
      }
      else if ( *((int *)v7 + 27) >= 0 )
      {
        v25 = 2 * (*((_DWORD *)v7 + 28) != 0) + 2;
      }
      else
      {
        v25 = 3;
      }
      g_showTextures_pTextures[v5].loadState = v25;
      v26 = 0;
      if ( *((_DWORD *)v7 + 26) < 4u )
        v26 = *((_DWORD *)v7 + 26);
      g_showTextures_pTextures[v5].cacheState = v26;
      ShowTextures_AddViewItem(pTexture: &g_showTextures_pTextures[v5]);
      v6 = numTextures;
      v7 += 444;
      ++v5;
      ++i;
    }
    while ( i < numTextures );
    v4 = (unsigned __int8 *)retVal;
  }
  v27 = v6;
  retVal = v6;
  xboxRetVal = _byteswap_ulong(v6);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = TextureList( 0x%8.8x, 0x%8.8x )\n", v27, numTextures, textureList);
  free(pMem: v4);
  ShowTextures_SortItems();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F300
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( i == -1 )
    return dword_494D2C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041F360
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( i == -1 )
    return dword_494D28;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041F3C0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Parent == -1 )
    return dword_494D28 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041F470
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F560
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<fileList_t,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F620
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041F6D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_494D28 = -1;
      dword_494D2C = -1;
      dword_494D30 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041F880
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041F9F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,int,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041FAE0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_494D28 = -1;
      dword_494D2C = -1;
      dword_494D30 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_494D28 = -1;
      dword_494D2C = -1;
      dword_494D30 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB80
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_494D28 = -1;
    dword_494D2C = -1;
    dword_494D30 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_494D28 = -1;
          dword_494D2C = -1;
          dword_494D30 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FCF0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_494D28 = -1;
            dword_494D2C = -1;
            dword_494D30 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FDB0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_494D28 = -1;
        dword_494D2C = -1;
        dword_494D30 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_494D28 = -1;
          dword_494D2C = -1;
          dword_494D30 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_494D28 = -1;
          dword_494D2C = -1;
          dword_494D30 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_494D28 = -1;
            dword_494D2C = -1;
            dword_494D30 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_494D28 = -1;
            dword_494D2C = -1;
            dword_494D30 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_494D28 = -1;
          dword_494D2C = -1;
          dword_494D30 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_494D28 = -1;
          dword_494D2C = -1;
          dword_494D30 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_494D28 = -1;
            dword_494D2C = -1;
            dword_494D30 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_494D28 = -1;
            dword_494D2C = -1;
            dword_494D30 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00420210
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420280
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key, int insert)
{
  int v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00420300
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x00420360
// Name: void ShowTextures_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Summary()
{
  int v0; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v1; // ebx
  int v2; // esi
  texture_t *v3; // eax
  int v4; // edi
  const char *v5; // esi
  int v6; // eax
  char *v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // eax
  int v12; // esi
  int i; // esi
  CFmtStrN<256> *v14; // eax
  int j; // esi
  char pDest[4096]; // [esp+18h] [ebp-1154h] BYREF
  CFmtStrN<256> v17; // [esp+1018h] [ebp-154h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+1124h] [ebp-48h] BYREF
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+112Ch] [ebp-40h] BYREF
  int v20; // [esp+1134h] [ebp-38h]
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > v21; // [esp+1138h] [ebp-34h] BYREF
  int parent; // [esp+115Ch] [ebp-10h] BYREF
  int v23; // [esp+1160h] [ebp-Ch]
  float v24; // [esp+1164h] [ebp-8h]
  bool leftchild; // [esp+116Bh] [ebp-1h] BYREF

  v0 = g_showTextures_numTextures;
  v1 = nullptr;
  v2 = 0;
  memset(&v21.m_Elements, 0, sizeof(v21.m_Elements));
  v21.m_Root = -1;
  v21.m_NumElements = 0;
  v21.m_FirstFree = -1;
  v21.m_LastAlloc.index = -1;
  v21.m_pElements = nullptr;
  v21.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v20 = 0;
  if ( g_showTextures_numTextures > 0 )
  {
    v3 = g_showTextures_pTextures;
    v4 = 0;
    v23 = 0;
    while ( *(int *)((char *)&v3->edram + v4) != 0 )
    {
LABEL_31:
      v4 += 200;
      ++v20;
      v23 = v4;
      if ( v20 >= v0 )
        goto LABEL_32;
    }
    LODWORD(v24) = *(_DWORD *)&v3->staticSizeBuff[v4 + 16] + v2;
    v5 = *(char **)((char *)&v3->pGroupName + v4);
    if ( _V_stricmp(s1: v5, s2: "World Textures") == 0 )
    {
      if ( V_strnicmp(s1: *(const char **)((char *)&g_showTextures_pTextures->pLongName + v4), s2: "models/", n: 7) == 0 )
      {
        if ( V_stristr(pStr: *(char **)((char *)&g_showTextures_pTextures->pLongName + v4), pSearch: "infected") != nullptr )
        {
          v5 = "Models - Infected";
        }
        else if ( V_stristr(pStr: *(char **)((char *)&g_showTextures_pTextures->pLongName + v4), pSearch: "survivors") != nullptr )
        {
          v5 = "Models - Survivors";
        }
        else if ( V_stristr(pStr: *(char **)((char *)&g_showTextures_pTextures->pLongName + v4), pSearch: "props") != nullptr )
        {
          v5 = "Models - Props";
        }
        else if ( V_stristr(pStr: *(char **)((char *)&g_showTextures_pTextures->pLongName + v4), pSearch: "weapons") != nullptr )
        {
          v5 = "Models - Weapons";
        }
        else
        {
          v5 = "Models - Other";
        }
LABEL_18:
        search.key = v5;
        v6 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
               this: &v21,
               &search);
        if ( v6 != -1 )
        {
LABEL_30:
          v2 = LODWORD(v24);
          v1[v6].m_Data.elem += *(_DWORD *)&g_showTextures_pTextures->staticSizeBuff[v4 + 16];
          v0 = g_showTextures_numTextures;
          v3 = g_showTextures_pTextures;
          goto LABEL_31;
        }
        v7 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v5) + 1);
        if ( v7 != nullptr )
        {
          strcpy(v7, v5);
LABEL_22:
          insert.key = v7;
          insert.elem = 0;
          parent = -1;
          leftchild = false;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
            this: &v21,
            &insert,
            &parent,
            &leftchild);
          v8 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(this: &v21);
          v9 = parent;
          v10 = v8;
          m_pMemory = v21.m_Elements.m_pMemory;
          v12 = v10;
          v21.m_Elements.m_pMemory[v12].m_Parent = parent;
          m_pMemory[v12].m_Right = -1;
          m_pMemory[v12].m_Left = -1;
          m_pMemory[v12].m_Tag = 0;
          if ( v9 == -1 )
          {
            v21.m_Root = v10;
          }
          else if ( leftchild )
          {
            m_pMemory[v9].m_Left = v10;
          }
          else
          {
            m_pMemory[v9].m_Right = v10;
          }
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
            this: &v21,
            elem: v10);
          v1 = v21.m_Elements.m_pMemory;
          ++v21.m_NumElements;
          if ( &v21.m_Elements.m_pMemory[v12] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
            v21.m_Elements.m_pMemory[v12].m_Data = insert;
          v6 = v10;
          v4 = v23;
          goto LABEL_30;
        }
LABEL_21:
        v7 = nullptr;
        goto LABEL_22;
      }
      if ( V_strnicmp(s1: *(const char **)((char *)&g_showTextures_pTextures->pLongName + v4), s2: "particle/", n: 9) == 0 )
      {
        v5 = "Particle Textures";
        goto LABEL_18;
      }
    }
    if ( v5 == nullptr )
      goto LABEL_21;
    goto LABEL_18;
  }
LABEL_32:
  v24 = (float)v2;
  V_snprintf(
    pDest,
    maxLen: 4096,
    pFormat: "Entries:\t\t\t%d\nSystem D3D Memory:\t%.2f MB\n\n",
    v0,
    (float)((float)v2 * 0.00000095367432));
  if ( v2 != 0 && v21.m_NumElements != 0 )
  {
    for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v21);
          i != -1;
          i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                this: &v21,
                i) )
    {
      v14 = CFmtStrN<256>::CFmtStrN<256>(
              this: &v17,
              pszFormat: "%-32s\t%.2f MB\t(%.2f%%)\n",
              v1[i].m_Data.key,
              (float)((float)v1[i].m_Data.elem * 0.00000095367432),
              (float)((float)((float)v1[i].m_Data.elem / v24) * 100.0));
      V_strncat(pDest, pSrc: v14->m_szBuf, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    }
  }
  MessageBoxA(hWnd: g_showTextures_hWnd, lpText: pDest, lpCaption: "Texture Summary", uType: 0);
  for ( j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v21);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &v21,
              i: j) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v1[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v21);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v21);
  if ( v21.m_Elements.m_nGrowSize >= 0 && v21.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00420780
// Name: long ShowTextures_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowTextures_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  _DWORD *v6; // eax
  bool v7; // zf
  const char *v8; // eax

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CC4u, uCheck: g_showTextures_currentFrame != 0 ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CCBu, uCheck: g_showTextures_fullPath != 0 ? 8 : 0);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC587u, uCheck: g_showTextures_drawTexture != 0 ? 8 : 0);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam > 0x9CC7u )
    {
      if ( (unsigned __int16)wParam > 0x9CCBu )
      {
        if ( (unsigned __int16)wParam != 50567 )
          return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
        g_showTextures_drawTexture ^= 1u;
        goto LABEL_54;
      }
      if ( (unsigned __int16)wParam == 40139 )
      {
        g_showTextures_fullPath ^= 1u;
        ShowTextures_SetTitle();
        ShowTextures_SortItems();
        return 0;
      }
      if ( (unsigned __int16)wParam != 40136 )
      {
        if ( (unsigned __int16)wParam == 40137 )
        {
          ShowTextures_Export();
          return 0;
        }
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
      }
    }
    else
    {
      if ( (unsigned __int16)wParam == 40135 )
      {
        ShowTextures_Summary();
        return 0;
      }
      if ( (unsigned __int16)wParam != 40132 )
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
      g_showTextures_currentFrame ^= 1u;
      ShowTextures_SetTitle();
    }
    ShowTextures_Refresh();
    return 0;
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        g_showTextures_drawTexture = 0;
        ShowTextures_DrawTexture();
        ShowTextures_SaveConfig();
        g_showTextures_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowTextures_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 != -150 )
  {
    if ( v5 != -114 )
    {
      if ( v5 == -108 )
      {
        if ( g_showTextures_sortColumn == *(_DWORD *)(lParam + 16) )
          g_showTextures_sortDescending ^= 1u;
        else
          g_showTextures_sortColumn = *(_DWORD *)(lParam + 16);
        ShowTextures_SortItems();
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
LABEL_54:
    ShowTextures_DrawTexture();
    return 0;
  }
  v6 = *(_DWORD **)(lParam + 44);
  switch ( *(_DWORD *)(lParam + 20) )
  {
    case 0:
      if ( g_showTextures_fullPath != 0 )
        *(_DWORD *)(lParam + 32) = v6[1];
      else
        *(_DWORD *)(lParam + 32) = v6[2];
      result = 0;
      break;
    case 1:
      *(_DWORD *)(lParam + 32) = v6 + 6;
      result = 0;
      break;
    case 2:
      *(_DWORD *)(lParam + 32) = v6 + 11;
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6[3];
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = v6[4];
      result = 0;
      break;
    case 5:
      *(_DWORD *)(lParam + 32) = v6 + 16;
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
    case 0xB:
      *(_DWORD *)(lParam + 32) = g_showTextures_cacheStrings[v6[49]];
      result = 0;
      break;
    case 0xC:
      *(_DWORD *)(lParam + 32) = g_showTextures_loadStrings[v6[47]];
      result = 0;
      break;
    case 0xD:
      v7 = v6[45] == 0;
      v8 = "PWL";
      if ( v7 )
        v8 = &defValue;
      *(_DWORD *)(lParam + 32) = v8;
      result = 0;
      break;
    case 0xE:
      *(_DWORD *)(lParam + 32) = g_showTextures_reducedStrings[v6[46]];
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420AB0
// Name: bool ShowTextures_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowTextures_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowTextures_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)118;
  wndclass.hCursor = (HICON__ *)"SHOWTEXTURESCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowTextures_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00439880
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    word_4BFD7A = -1;
    dword_4BFD7C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004398E0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439A20
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}
