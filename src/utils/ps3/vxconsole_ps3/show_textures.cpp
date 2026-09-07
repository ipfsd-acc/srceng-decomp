// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/show_textures.cpp
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F700
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
// Address: 0x0040F7D0
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
  Sys_GetRegistryString(keyName: "showTexturesWindowRect", value: buff, defValue: &str, valueLen: 256);
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
// Address: 0x0040F8B0
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
// Address: 0x0040F950
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
    Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 260, bForce: false);
    v1 = fopen(file: logFilename, mode: "wt+");
    if ( v1 != nullptr )
    {
      v2 = g_showTextures_Labels;
      do
      {
        fprintf(str: v1, format: "\"%s\"", v2->name);
        if ( v0 != 11 )
          fprintf(str: v1, format: ",");
        v2 = (label_t *)((char *)v2 + 44);
        ++v0;
      }
      while ( (int)v2 < (int)&vec2_invalid_16 );
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
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].sizeBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].pGroupName);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].pFormatName);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].widthBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].heightBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].depthBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].numLevelsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].bindsBuff);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_pTextures[v4].refCountBuff);
          v5 = "PWL";
          if ( g_showTextures_pTextures[v4].pwl == 0 )
            v5 = &str;
          fprintf(str: v1, format: ",\"%s\"", v5);
          fprintf(str: v1, format: ",\"%s\"", g_showTextures_loadStrings[g_showTextures_pTextures[v4].loadState]);
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
// Address: 0x0040FBC0
// Name: void ShowTextures_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Summary()
{
  int v0; // edx
  int *p_size; // eax
  int v2; // ecx
  char buff[1024]; // [esp+Ch] [ebp-400h] BYREF

  v0 = 0;
  if ( g_showTextures_numTextures > 0 )
  {
    p_size = &g_showTextures_pTextures->size;
    v2 = g_showTextures_numTextures;
    do
    {
      if ( p_size[37] == 0 )
        v0 += *p_size;
      p_size += 43;
      --v2;
    }
    while ( v2 != 0 );
  }
  sprintf(
    string: buff,
    format: "Entries:\t\t\t%d\nSystem D3D Memory:\t%.2f MB\n",
    g_showTextures_numTextures,
    (float)((float)v0 * 0.00000095367432));
  MessageBoxA(hWnd: g_showTextures_hWnd, lpText: buff, lpCaption: "Texture Summary", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040FC50
// Name: void ShowTextures_DrawTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_DrawTexture()
{
  LRESULT v0; // esi
  int lParam; // esi
  char command[256]; // [esp+0h] [ebp-13Ch] BYREF
  tagLVITEMA lvitem; // [esp+100h] [ebp-3Ch] BYREF

  if ( g_connectionState == kCONNECTEDAPP )
  {
    v0 = SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1042u, wParam: 0, lParam: 0);
    if ( v0 != -1 )
    {
      memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
      lvitem.mask = 4;
      lvitem.iItem = v0;
      SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      lParam = lvitem.lParam;
      if ( _V_stricmp(s1: g_showTextures_drawTextureName, s2: *(const char **)(lvitem.lParam + 4)) != 0 )
      {
        sprintf(string: command, format: "mat_drawTexture %s", *(const char **)(lParam + 4));
        V_strncpy(pDest: g_showTextures_drawTextureName, pSrc: *(const char **)(lParam + 4), maxLen: 260);
      }
      else
      {
        sprintf(string: command, format: "mat_drawTexture \"\"");
        g_showTextures_drawTextureName[0] = 0;
      }
      ProcessCommand(strCmdIn: command);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FD40
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
// Address: 0x0040FDF0
// Name: int ShowTextures_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowTextures_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  const char *v4; // ecx
  const char *v5; // [esp-4h] [ebp-4h]

  result = 0;
  switch ( g_showTextures_sortColumn )
  {
    case 0:
      if ( g_showTextures_fullPath == 0 )
      {
        v4 = *(const char **)(lParam1 + 8);
        v5 = *(const char **)(lParam2 + 8);
        goto LABEL_16;
      }
      result = _V_stricmp(s1: *(const char **)(lParam1 + 4), s2: *(const char **)(lParam2 + 4));
      break;
    case 1:
      result = *(_DWORD *)(lParam1 + 20) - *(_DWORD *)(lParam2 + 20);
      break;
    case 2:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 12), s2: *(const char **)(lParam2 + 12));
      break;
    case 3:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 16), s2: *(const char **)(lParam2 + 16));
      break;
    case 4:
      result = *(_DWORD *)(lParam1 + 40) - *(_DWORD *)(lParam2 + 40);
      break;
    case 5:
      result = *(_DWORD *)(lParam1 + 60) - *(_DWORD *)(lParam2 + 60);
      break;
    case 6:
      result = *(_DWORD *)(lParam1 + 80) - *(_DWORD *)(lParam2 + 80);
      break;
    case 7:
      result = *(_DWORD *)(lParam1 + 100) - *(_DWORD *)(lParam2 + 100);
      break;
    case 8:
      result = *(_DWORD *)(lParam1 + 120) - *(_DWORD *)(lParam2 + 120);
      break;
    case 9:
      result = *(_DWORD *)(lParam1 + 140) - *(_DWORD *)(lParam2 + 140);
      break;
    case 10:
      result = *(_DWORD *)(lParam1 + 160) - *(_DWORD *)(lParam2 + 160);
      break;
    case 11:
      v5 = g_showTextures_loadStrings[*(_DWORD *)(lParam2 + 164)];
      v4 = g_showTextures_loadStrings[*(_DWORD *)(lParam1 + 164)];
LABEL_16:
      result = _V_stricmp(s1: v4, s2: v5);
      break;
    default:
      break;
  }
  if ( g_showTextures_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF50
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
    v3 = byte_444D6C;
    for ( j = 12; j != 0; --j )
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
// Address: 0x00410050
// Name: void ShowTextures_AddViewItem(struct texture_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_AddViewItem(texture_t *pTexture)
{
  LRESULT v2; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showTextures_hWnd != nullptr )
  {
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
// Address: 0x00410160
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
  if ( g_connectionState == kCONNECTEDAPP )
    ProcessCommand(strCmdIn: command);
}

//------------------------------------------------------------------------------
// Address: 0x004101E0
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
// Address: 0x00410230
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
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam > 0x9CC7u )
    {
      if ( (unsigned __int16)wParam > 0x9CCBu )
      {
        if ( (unsigned __int16)wParam == 50567 )
        {
          ShowTextures_DrawTexture();
          return 0;
        }
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
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
      *(_DWORD *)(lParam + 32) = v6[3];
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6[4];
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = v6 + 11;
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
      v7 = v6[40] == 0;
      v8 = "PWL";
      if ( v7 )
        v8 = &str;
      *(_DWORD *)(lParam + 32) = v8;
      result = 0;
      break;
    case 0xB:
      *(_DWORD *)(lParam + 32) = g_showTextures_loadStrings[v6[41]];
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004104F0
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
// Address: 0x00410590
// Name: void ShowTextures_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowTextures_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  char *v2; // edx
  int v3; // esi
  int v4; // edi
  char *v5; // eax
  char v6; // cl
  char v7; // [esp+3h] [ebp-13Dh] BYREF
  char strCmdIn[256]; // [esp+4h] [ebp-13Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+104h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+130h] [ebp-10h] BYREF

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
                            lpWindowName: &str,
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
                                    lpWindowName: &str,
                                    dwStyle: 0x50000001u,
                                    X: 0,
                                    Y: 0,
                                    nWidth: clientRect.right - clientRect.left,
                                    nHeight: clientRect.bottom - clientRect.top,
                                    hWndParent: g_showTextures_hWnd,
                                    hMenu: (HMENU)0x64,
                                    hInstance: g_hInstance,
                                    lpParam: nullptr);
    for ( i = 0; i < 132; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = *(char **)((char *)&g_showTextures_Labels[0].name + i * 4);
      lvc.cx = dword_444D64[i];
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.pszText = v2;
      SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showTextures_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v3 = 0;
    if ( g_showTextures_numTextures > 0 )
    {
      v4 = 0;
      do
      {
        ShowTextures_AddViewItem(pTexture: &g_showTextures_pTextures[v4]);
        ++v3;
        ++v4;
      }
      while ( v3 < g_showTextures_numTextures );
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
      v5 = &v7;
      do
        v6 = *++v5;
      while ( v6 != 0 );
      strcpy(v5, " all");
    }
    if ( g_connectionState == kCONNECTEDAPP )
      ProcessCommand(strCmdIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004107E0
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
  const char *v8; // ecx
  const char *v9; // edx
  const char *v10; // ecx
  const char *v11; // edx
  const char *v12; // ecx
  const char *v13; // edx
  const char *v14; // edx
  bool v15; // zf
  char *v16; // eax
  char *v17; // edx
  char v18; // cl
  char *v19; // eax
  char v20; // cl
  int v21; // eax
  int v22; // edi
  char v24; // [esp+3h] [ebp-22Dh] BYREF
  char tempName[260]; // [esp+4h] [ebp-22Ch] BYREF
  char shortName[260]; // [esp+108h] [ebp-128h] BYREF
  int i; // [esp+20Ch] [ebp-24h]
  int retVal; // [esp+210h] [ebp-20h]
  unsigned __int64 retAddr; // [esp+214h] [ebp-1Ch] BYREF
  unsigned __int64 textureList; // [esp+21Ch] [ebp-14h] BYREF
  int xboxRetVal; // [esp+224h] [ebp-Ch] BYREF
  const char *pFormatName; // [esp+228h] [ebp-8h]
  int numTextures; // [esp+22Ch] [ebp-4h] BYREF

  ShowTextures_Clear();
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &numTextures);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%lx", &textureList);
  v3 = GetToken(ppTokenStream: &commandPtr);
  if ( *v3 == 0 )
    return -1;
  sscanf(string: v3, format: "%lx", &retAddr);
  v4 = (unsigned __int8 *)operator new(nSize: 444 * numTextures);
  v5 = 0;
  retVal = (int)v4;
  memset(dst: v4, value: 0, count: 444 * numTextures);
  g_showTextures_numTextures = numTextures;
  g_showTextures_pTextures = (texture_t *)operator new(nSize: 172 * numTextures);
  memset(dst: (unsigned __int8 *)g_showTextures_pTextures, value: 0, count: 172 * numTextures);
  CPS3TargetConnection::DmGetMemory(
    this: &g_PS3CurrentTargetConn,
    pAddressOnConsoleToReadFrom: textureList,
    nBytesToRead: 444 * numTextures,
    pLocalDestinationBuffer: v4);
  v6 = numTextures;
  i = 0;
  if ( numTextures > 0 )
  {
    v7 = v4 + 320;
    do
    {
      pFormatName = *((const char **)v7 + 16);
      *((_DWORD *)v7 + 16) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = *((const char **)v7 + 17);
      v8 = *((const char **)v7 + 18);
      *((_DWORD *)v7 + 17) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v8;
      v9 = *((const char **)v7 + 19);
      *((_DWORD *)v7 + 18) = _byteswap_ulong((unsigned int)v8);
      pFormatName = v9;
      *((_DWORD *)v7 + 19) = _byteswap_ulong((unsigned int)v9);
      pFormatName = *((const char **)v7 + 20);
      v10 = *((const char **)v7 + 21);
      *((_DWORD *)v7 + 20) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v10;
      v11 = *((const char **)v7 + 22);
      *((_DWORD *)v7 + 21) = _byteswap_ulong((unsigned int)v10);
      pFormatName = v11;
      *((_DWORD *)v7 + 22) = _byteswap_ulong((unsigned int)v11);
      pFormatName = *((const char **)v7 + 23);
      v12 = *((const char **)v7 + 24);
      *((_DWORD *)v7 + 23) = _byteswap_ulong((unsigned int)pFormatName);
      pFormatName = v12;
      v13 = *((const char **)v7 + 25);
      *((_DWORD *)v7 + 24) = _byteswap_ulong((unsigned int)v12);
      pFormatName = v13;
      *((_DWORD *)v7 + 25) = _byteswap_ulong((unsigned int)v13);
      pFormatName = (const char *)(*((_DWORD *)v7 + 27) >> 31);
      v14 = *((const char **)v7 + 28);
      *((_DWORD *)v7 + 27) = (_byteswap_ulong((unsigned int)pFormatName) << 31) | *((_DWORD *)v7 + 27) & 0x7FFFFFFF;
      pFormatName = v14;
      *((_DWORD *)v7 + 28) = _byteswap_ulong((unsigned int)v14);
      pFormatName = *((const char **)v7 + 29);
      *((_DWORD *)v7 + 29) = _byteswap_ulong((unsigned int)pFormatName);
      g_showTextures_pTextures[v5].pLongName = MemAlloc_StrDup(pString: (const char *)v7 - 320);
      Sys_StripPath(inpath: g_showTextures_pTextures[v5].pLongName, outpath: shortName, outPathLen: 260);
      g_showTextures_pTextures[v5].pShortName = MemAlloc_StrDup(pString: shortName);
      g_showTextures_pTextures[v5].pGroupName = MemAlloc_StrDup(pString: (const char *)v7 - 64);
      pFormatName = (const char *)v7;
      v15 = V_strncasecmp(s1: (const char *)v7, s2: "D3DFMT_", n: 7) == 0;
      v16 = (char *)(v7 + 7);
      if ( !v15 )
        v16 = (char *)v7;
      if ( *((_DWORD *)v7 + 23) != 0 )
      {
        v17 = (char *)(tempName - v16);
        do
        {
          v18 = *v16;
          v16[(_DWORD)v17] = *v16;
          ++v16;
        }
        while ( v18 != 0 );
        v19 = &v24;
        do
          v20 = *++v19;
        while ( v20 != 0 );
        strcpy(v19, " (SRGB)");
        v16 = tempName;
      }
      g_showTextures_pTextures[v5].pFormatName = MemAlloc_StrDup(pString: v16);
      g_showTextures_pTextures[v5].size = *((_DWORD *)v7 + 16);
      g_showTextures_pTextures[v5].width = *((_DWORD *)v7 + 17);
      g_showTextures_pTextures[v5].height = *((_DWORD *)v7 + 18);
      g_showTextures_pTextures[v5].depth = *((_DWORD *)v7 + 19);
      g_showTextures_pTextures[v5].numLevels = *((_DWORD *)v7 + 20);
      g_showTextures_pTextures[v5].binds = *((_DWORD *)v7 + 21);
      g_showTextures_pTextures[v5].refCount = *((_DWORD *)v7 + 22);
      g_showTextures_pTextures[v5].edram = *((_DWORD *)v7 + 24);
      g_showTextures_pTextures[v5].pwl = *((_DWORD *)v7 + 29);
      if ( *((_DWORD *)v7 + 24) != 0
        || V_stristr(pStr: g_showTextures_pTextures[v5].pGroupName, pSearch: "RenderTarget") != nullptr )
      {
        v21 = 0;
      }
      else if ( *((_DWORD *)v7 + 25) != 0 )
      {
        v21 = 1;
      }
      else if ( *((int *)v7 + 27) >= 0 )
      {
        v21 = *((_DWORD *)v7 + 28) != 0 ? 5 : 2;
      }
      else
      {
        v21 = 4;
      }
      g_showTextures_pTextures[v5].loadState = v21;
      ShowTextures_AddViewItem(pTexture: &g_showTextures_pTextures[v5]);
      v6 = numTextures;
      v7 += 444;
      ++v5;
      ++i;
    }
    while ( i < numTextures );
    v4 = (unsigned __int8 *)retVal;
  }
  v22 = v6;
  retVal = v6;
  xboxRetVal = _byteswap_ulong(v6);
  CPS3TargetConnection::DmSetMemory(
    this: &g_PS3CurrentTargetConn,
    pAddressOnConsoleToWriteTo: retAddr,
    nBytesToWrite: 4,
    pLocalSourceBuffer: &xboxRetVal);
  DebugCommand(pStrFormat: "0x%8.8x = TextureList( 0x%8.8x, 0x%8.8x )\n", v22, numTextures, (_DWORD)textureList);
  free(pMem: v4);
  ShowTextures_SortItems();
  return 0;
}
