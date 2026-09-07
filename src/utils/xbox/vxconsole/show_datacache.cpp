// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_datacache.cpp
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004169D0
// Name: char __near * ShowDataCache_FormatSize(int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ShowDataCache_FormatSize(int size, char *pBuff, bool bUnits)
{
  char *v3; // esi

  if ( g_showDataCache_showBytes != 0 )
  {
    if ( g_showDataCache_showBytes == 1 )
    {
      v3 = pBuff;
      sprintf(string: pBuff, format: "%.2f", (float)((float)size * 0.0009765625));
      if ( !bUnits )
        return v3;
      strcat(pBuff, " K");
      return pBuff;
    }
    else
    {
      if ( g_showDataCache_showBytes == 2 )
      {
        v3 = pBuff;
        sprintf(string: pBuff, format: "%.2f", (float)((float)size * 0.00000095367432));
        if ( bUnits )
          strcat(pBuff, " MB");
        return v3;
      }
      return pBuff;
    }
  }
  else
  {
    sprintf(string: pBuff, format: "%d", size);
    return pBuff;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416AB0
// Name: void ShowDataCache_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showDataCacheSortColumn", value: g_showDataCache_sortColumn);
  Sys_SetRegistryInteger(keyName: "showDataCacheSortDescending", value: g_showDataCache_sortDescending);
  Sys_SetRegistryInteger(keyName: "showDataCacheShowBytes", value: g_showDataCache_showBytes);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showDataCache_hWnd, lpwndpl: &wp);
  g_showDataCache_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showDataCacheWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x00416B70
// Name: void ShowDataCache_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showDataCacheSortColumn", defValue: 0, value: &g_showDataCache_sortColumn);
  Sys_GetRegistryInteger(keyName: "showDataCacheSortDescending", defValue: 0, value: &g_showDataCache_sortDescending);
  Sys_GetRegistryInteger(keyName: "showDataCacheShowBytes", defValue: 1, value: &g_showDataCache_showBytes);
  Sys_GetRegistryString(keyName: "showDataCacheWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showDataCache_windowRect,
         &g_showDataCache_windowRect.top,
         &g_showDataCache_windowRect.right,
         &g_showDataCache_windowRect.bottom) != 4
    || g_showDataCache_windowRect.left < 0
    || g_showDataCache_windowRect.top < 0
    || g_showDataCache_windowRect.right < 0
    || g_showDataCache_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showDataCache_windowRect.left = 0;
    *(_QWORD *)&g_showDataCache_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416C30
// Name: int ShowDataCache_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowDataCache_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  const char *v4; // esi
  const char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  int v8; // edi
  int v9; // ecx
  bool v10; // zf
  const char *v11; // esi
  const char *v12; // eax

  result = 0;
  switch ( g_showDataCache_sortColumn )
  {
    case 0:
      goto $LN13_2;
    case 1:
      v6 = CUtlString::operator char const *(this: (CUtlString *)(lParam2 + 20));
      v7 = CUtlString::operator char const *(this: (CUtlString *)(lParam1 + 20));
      result = _V_stricmp(s1: v7, s2: v6);
      if ( result == 0 )
      {
$LN13_2:
        v4 = CUtlString::operator char const *(this: (CUtlString *)(lParam2 + 4));
        v5 = CUtlString::operator char const *(this: (CUtlString *)(lParam1 + 4));
        result = _V_stricmp(s1: v5, s2: v4);
      }
      break;
    case 2:
      v8 = lParam1;
      v9 = lParam2;
      result = *(_DWORD *)(lParam1 + 56) - *(_DWORD *)(lParam2 + 56);
      v10 = *(_DWORD *)(lParam1 + 56) == *(_DWORD *)(lParam2 + 56);
      goto LABEL_6;
    case 3:
      v8 = lParam1;
      v9 = lParam2;
      result = *(_DWORD *)(lParam1 + 76) - *(_DWORD *)(lParam2 + 76);
      v10 = *(_DWORD *)(lParam1 + 76) == *(_DWORD *)(lParam2 + 76);
      goto LABEL_6;
    case 4:
      v8 = lParam1;
      v9 = lParam2;
      result = *(_DWORD *)(lParam1 + 36) - *(_DWORD *)(lParam2 + 36);
      v10 = *(_DWORD *)(lParam1 + 36) == *(_DWORD *)(lParam2 + 36);
LABEL_6:
      if ( v10 )
      {
        v11 = CUtlString::operator char const *(this: (CUtlString *)(v9 + 4));
        v12 = CUtlString::operator char const *(this: (CUtlString *)(v8 + 4));
        result = _V_stricmp(s1: v12, s2: v11);
      }
      break;
    case 5:
      result = *(_DWORD *)(lParam1 + 96) - *(_DWORD *)(lParam2 + 96);
      break;
    case 6:
      result = *(_DWORD *)(lParam1 + 116) - *(_DWORD *)(lParam2 + 116);
      break;
    case 7:
      result = *(_DWORD *)(lParam1 + 136) - *(_DWORD *)(lParam2 + 136);
      break;
    default:
      break;
  }
  if ( g_showDataCache_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416D70
// Name: void ShowDataCache_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showDataCache_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowDataCache_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = string;
    for ( j = 8; j != 0; --j )
    {
      if ( v2 == g_showDataCache_sortColumn )
        v4 = 2 * (g_showDataCache_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416E70
// Name: void ShowDataCache_AddViewItem(struct CacheEntry_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_AddViewItem(CacheEntry_t *pEntry)
{
  LRESULT v1; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showDataCache_hWnd != nullptr )
  {
    ShowDataCache_FormatSize(size: pEntry->size, pBuff: pEntry->sizeBuff, bUnits: true);
    sprintf(string: pEntry->lockCountBuff, format: "%d", pEntry->lockCount);
    if ( pEntry->lockCount != 0 )
      sprintf(string: pEntry->lruOrderBuff, format: "%s", "Locked");
    else
      sprintf(string: pEntry->lruOrderBuff, format: "%d", pEntry->lruOrder);
    sprintf(string: pEntry->clientIdBuff, format: "0x%8.8x", pEntry->clientId);
    sprintf(string: pEntry->itemDataBuff, format: "0x%8.8x", pEntry->itemData);
    sprintf(string: pEntry->handleBuff, format: "0x%8.8x", pEntry->handle);
    v1 = SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    lvi.mask = 13;
    lvi.iItem = v1;
    memset(&lvi.iSubItem, 0, 12);
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pEntry;
    pEntry->listIndex = SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416F80
// Name: void ShowDataCache_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_Refresh()
{
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: "vx_datacache_list");
}

//------------------------------------------------------------------------------
// Address: 0x00416FA0
// Name: void ShowDataCache_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_SizeWindow(HWND__ *hwnd, int cx, int cy)
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
    hWnd: g_showDataCache_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00417130
// Name: void ShowDataCache_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_Export()
{
  int v0; // edi
  _iobuf *v1; // eax
  _iobuf *v2; // esi
  int i; // ebx
  const char *v4; // eax
  const char *v5; // eax
  int size; // ecx
  char logFilename[260]; // [esp+14h] [ebp-19Ch] BYREF
  char buff[64]; // [esp+118h] [ebp-98h] BYREF
  tagOFNA ofn; // [esp+158h] [ebp-58h] BYREF

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_showDataCache_hWnd;
  ofn.lpstrFile = logFilename;
  logFilename[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "Excel CSV";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = g_localPath;
  ofn.Flags = 2048;
  if ( GetOpenFileNameA(a1: &ofn) )
  {
    Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 0x104u, bForce: false);
    v1 = fopen(file: logFilename, mode: "wt+");
    v2 = v1;
    if ( v1 != nullptr )
    {
      fprintf(str: v1, format: "Name");
      fprintf(str: v2, format: ",Section");
      fprintf(str: v2, format: ",Size");
      fprintf(str: v2, format: ",Lock Count");
      fprintf(str: v2, format: ",LRU Order");
      fprintf(str: v2, format: ",Client ID");
      fprintf(str: v2, format: ",Item Data");
      fprintf(str: v2, format: ",Handle");
      fprintf(str: v2, format: "\n");
      for ( i = 0; i < g_showDataCache_Contents.m_Size; ++v0 )
      {
        v4 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v0].name);
        fprintf(str: v2, format: "\"%s\"", v4);
        v5 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v0].section);
        fprintf(str: v2, format: ",\"%s\"", v5);
        size = g_showDataCache_Contents.m_Memory.m_pMemory[v0].size;
        if ( g_showDataCache_showBytes != 0 )
        {
          if ( g_showDataCache_showBytes == 1 )
          {
            sprintf(string: buff, format: "%.2f", (float)((float)size * 0.0009765625));
          }
          else if ( g_showDataCache_showBytes == 2 )
          {
            sprintf(string: buff, format: "%.2f", (float)((float)size * 0.00000095367432));
          }
        }
        else
        {
          sprintf(string: buff, format: "%d", size);
        }
        fprintf(str: v2, format: ",%s", buff);
        fprintf(str: v2, format: ",%d", g_showDataCache_Contents.m_Memory.m_pMemory[v0].lockCount);
        fprintf(str: v2, format: ",%d", g_showDataCache_Contents.m_Memory.m_pMemory[v0].lruOrder);
        fprintf(str: v2, format: ",0x%8.8x", g_showDataCache_Contents.m_Memory.m_pMemory[v0].clientId);
        fprintf(str: v2, format: ",0x%8.8x", g_showDataCache_Contents.m_Memory.m_pMemory[v0].itemData);
        fprintf(str: v2, format: ",0x%8.8x", g_showDataCache_Contents.m_Memory.m_pMemory[v0].handle);
        fprintf(str: v2, format: "\n");
        ++i;
      }
      fclose(stream: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004173E0
// Name: void ShowDataCache_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_Summary()
{
  int v0; // edi
  int v1; // ebx
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  int size; // ecx
  int v6; // eax
  int v7; // esi
  char *v8; // edi
  char *v9; // [esp+4h] [ebp-299Ch]
  char pDest[8320]; // [esp+14h] [ebp-298Ch] BYREF
  char string[2304]; // [esp+2094h] [ebp-90Ch] BYREF
  int v12; // [esp+2994h] [ebp-Ch]
  int v13; // [esp+2998h] [ebp-8h]
  char *s2; // [esp+299Ch] [ebp-4h]

  v0 = 0;
  v1 = 0;
  v13 = 0;
  if ( g_showDataCache_Contents.m_Size > 0 )
  {
    do
    {
      v2 = 0;
      if ( v1 <= 0 )
      {
LABEL_6:
        v2 = v1++;
        v4 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v0].section);
        V_strncpy(pDest: &pDest[260 * v2], pSrc: v4, maxLen: 260);
        *(_DWORD *)&string[4 * v2 + 2176] = 0;
        *(_DWORD *)&string[4 * v2 + 2048] = 0;
      }
      else
      {
        s2 = pDest;
        while ( 1 )
        {
          v9 = s2;
          v3 = CUtlString::operator char const *(this: &g_showDataCache_Contents.m_Memory.m_pMemory[v0].section);
          if ( _V_stricmp(s1: v3, s2: v9) == 0 )
            break;
          s2 += 260;
          if ( ++v2 >= v1 )
            goto LABEL_6;
        }
      }
      size = g_showDataCache_Contents.m_Memory.m_pMemory[v0].size;
      ++*(_DWORD *)&string[4 * v2 + 2176];
      v6 = v13;
      *(_DWORD *)&string[4 * v2 + 2048] += size;
      ++v0;
      v13 = v6 + 1;
    }
    while ( v6 + 1 < g_showDataCache_Contents.m_Size );
  }
  v7 = 0;
  v13 = 0;
  v12 = 0;
  v8 = string;
  if ( v1 > 0 )
  {
    s2 = pDest;
    do
    {
      sprintf(
        string: v8,
        format: "%s:\t %d Resources, %.2f MB\n",
        s2,
        *(_DWORD *)&string[4 * v7 + 2176],
        (float)((float)*(int *)&string[4 * v7 + 2048] * 0.00000095367432));
      s2 += 260;
      v8 += strlen(v8);
      v13 += *(_DWORD *)&string[4 * v7 + 2176];
      v12 += *(_DWORD *)&string[4 * v7++ + 2048];
    }
    while ( v7 < v1 );
  }
  sprintf(string: v8, format: "\nTotal:\t\t %d Resources, %.2f MB\n", v13, (float)((float)v12 * 0.00000095367432));
  MessageBoxA(hWnd: g_showDataCache_hWnd, lpText: string, lpCaption: "DataCache Summary", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417590
// Name: void ShowDataCache_FormatItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_FormatItems()
{
  int v0; // ebx
  char *sizeBuff; // esi
  int size; // eax
  int i; // [esp+14h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < g_showDataCache_Contents.m_Size; ++i )
  {
    sizeBuff = g_showDataCache_Contents.m_Memory.m_pMemory[v0].sizeBuff;
    size = g_showDataCache_Contents.m_Memory.m_pMemory[v0].size;
    if ( g_showDataCache_showBytes != 0 )
    {
      if ( g_showDataCache_showBytes == 1 )
      {
        sprintf(
          string: g_showDataCache_Contents.m_Memory.m_pMemory[v0].sizeBuff,
          format: "%.2f",
          (float)((float)size * 0.0009765625));
        strcat(sizeBuff, " K");
      }
      else if ( g_showDataCache_showBytes == 2 )
      {
        sprintf(
          string: g_showDataCache_Contents.m_Memory.m_pMemory[v0].sizeBuff,
          format: "%.2f",
          (float)((float)size * 0.00000095367432));
        strcat(sizeBuff, " MB");
      }
    }
    else
    {
      sprintf(string: g_showDataCache_Contents.m_Memory.m_pMemory[v0].sizeBuff, format: "%d", size);
    }
    ++v0;
  }
  ShowDataCache_SortItems();
}

//------------------------------------------------------------------------------
// Address: 0x004176A0
// Name: long ShowDataCache_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowDataCache_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  int v6; // eax

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC55Fu, uCheck: g_showDataCache_showBytes != 0 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC562u, uCheck: g_showDataCache_showBytes != 1 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC563u, uCheck: g_showDataCache_showBytes != 2 ? 0 : 8);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam <= 0xC55Fu )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0xC55Fu:
          g_showDataCache_showBytes = 0;
          ShowDataCache_FormatItems();
          return 0;
        case 0x9CC7u:
          ShowDataCache_Summary();
          return 0;
        case 0x9CC8u:
          ShowDataCache_Refresh();
          return 0;
        case 0x9CC9u:
          ShowDataCache_Export();
          return 0;
        default:
          break;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam == 50530 )
    {
      g_showDataCache_showBytes = 1;
      ShowDataCache_FormatItems();
      return 0;
    }
    if ( (unsigned __int16)wParam == 50531 )
    {
      g_showDataCache_showBytes = 2;
      ShowDataCache_FormatItems();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        ShowDataCache_SaveConfig();
        g_showDataCache_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowDataCache_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
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
      if ( g_showDataCache_sortColumn == *(_DWORD *)(lParam + 16) )
        g_showDataCache_sortDescending ^= 1u;
      else
        g_showDataCache_sortColumn = *(_DWORD *)(lParam + 16);
      ShowDataCache_SortItems();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  v6 = *(_DWORD *)(lParam + 44);
  switch ( *(_DWORD *)(lParam + 20) )
  {
    case 0:
      *(_DWORD *)(lParam + 32) = CUtlString::operator char const *(this: (CUtlString *)(v6 + 4));
      result = 0;
      break;
    case 1:
      *(_DWORD *)(lParam + 32) = CUtlString::operator char const *(this: (CUtlString *)(v6 + 20));
      result = 0;
      break;
    case 2:
      *(_DWORD *)(lParam + 32) = v6 + 60;
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6 + 80;
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = v6 + 40;
      result = 0;
      break;
    case 5:
      *(_DWORD *)(lParam + 32) = v6 + 100;
      result = 0;
      break;
    case 6:
      *(_DWORD *)(lParam + 32) = v6 + 120;
      result = 0;
      break;
    case 7:
      *(_DWORD *)(lParam + 32) = v6 + 140;
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417910
// Name: bool ShowDataCache_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowDataCache_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowDataCache_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)135;
  wndclass.hCursor = (HICON__ *)"SHOWDATACACHECLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowDataCache_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004179B0
// Name: void ShowDataCache_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  char *v2; // edx
  int v3; // esi
  int v4; // edi
  tagLVCOLUMNA lvc; // [esp+4h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+30h] [ebp-10h] BYREF

  if ( g_showDataCache_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showDataCache_hWnd) )
      ShowWindow(hWnd: g_showDataCache_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showDataCache_hWnd);
  }
  else
  {
    g_showDataCache_hWnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SHOWDATACACHECLASS",
                             lpWindowName: "DataCache",
                             dwStyle: 0x80CF0000,
                             X: 0,
                             Y: 0,
                             nWidth: 700,
                             nHeight: 400,
                             hWndParent: g_hDlgMain,
                             hMenu: nullptr,
                             hInstance: g_hInstance,
                             lpParam: nullptr);
    GetClientRect(hWnd: g_showDataCache_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showDataCache_hWndListView = CreateWindowExA(
                                     dwExStyle: 0,
                                     lpClassName: "SysListView32",
                                     lpWindowName: &defValue,
                                     dwStyle: 0x5000000Du,
                                     X: 0,
                                     Y: 0,
                                     nWidth: clientRect.right - clientRect.left,
                                     nHeight: clientRect.bottom - clientRect.top,
                                     hWndParent: g_showDataCache_hWnd,
                                     hMenu: (HMENU)0x64,
                                     hInstance: g_hInstance,
                                     lpParam: nullptr);
    for ( i = 0; i < 88; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = *(char **)((char *)&g_showDataCache_Labels[0].name + i * 4);
      lvc.cx = dword_465974[i];
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.pszText = v2;
      SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v3 = 0;
    if ( g_showDataCache_Contents.m_Size > 0 )
    {
      v4 = 0;
      do
      {
        ShowDataCache_AddViewItem(pEntry: &g_showDataCache_Contents.m_Memory.m_pMemory[v4]);
        ++v3;
        ++v4;
      }
      while ( v3 < g_showDataCache_Contents.m_Size );
    }
    ShowDataCache_SortItems();
    if ( g_showDataCache_windowRect.right != 0 && g_showDataCache_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_showDataCache_hWnd,
        X: g_showDataCache_windowRect.left,
        Y: g_showDataCache_windowRect.top,
        nWidth: g_showDataCache_windowRect.right - g_showDataCache_windowRect.left,
        nHeight: g_showDataCache_windowRect.bottom - g_showDataCache_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_showDataCache_hWnd, nCmdShow: 1);
    if ( g_connectedToApp )
      ProcessCommand(strCmdIn: "vx_datacache_list");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417DC0
// Name: void ShowDataCache_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowDataCache_Clear()
{
  CacheEntry_t *m_pMemory; // eax

  if ( g_showDataCache_hWnd != nullptr )
    SendMessageA(hWnd: g_showDataCache_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showDataCache_Contents.m_Size != 0 )
  {
    CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::RemoveAll(this: &g_showDataCache_Contents);
    m_pMemory = g_showDataCache_Contents.m_Memory.m_pMemory;
    if ( g_showDataCache_Contents.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_showDataCache_Contents.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_showDataCache_Contents.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_showDataCache_Contents.m_Memory.m_pMemory = nullptr;
      }
      g_showDataCache_Contents.m_Memory.m_nAllocationCount = 0;
    }
    g_showDataCache_Contents.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E30
// Name: int rc_DataCacheList(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_DataCacheList(char *pCommand)
{
  int v1; // esi
  xrDataCacheItem_t *v2; // ebx
  int v3; // edi
  const char *Token; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // edi
  xrDataCacheItem_t *m_pMemory; // edi
  int v9; // eax
  int *p_size; // edi
  int v11; // ecx
  int v12; // edi
  CUtlVector<xrDataCacheItem_t,CUtlMemory<xrDataCacheItem_t,int> > localList; // [esp+Ch] [ebp-2Ch] BYREF
  int retVal; // [esp+20h] [ebp-18h]
  int lruOrder; // [esp+24h] [ebp-14h]
  int retAddr; // [esp+28h] [ebp-10h] BYREF
  int xboxRetVal; // [esp+2Ch] [ebp-Ch] BYREF
  int cacheList; // [esp+30h] [ebp-8h] BYREF
  int numEntries; // [esp+34h] [ebp-4h] BYREF

  v1 = 0;
  v2 = nullptr;
  v3 = -1;
  memset(&localList, 0, sizeof(localList));
  ShowDataCache_Clear();
  Token = GetToken(ppTokenStream: &pCommand);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%x", &numEntries);
    v5 = GetToken(ppTokenStream: &pCommand);
    if ( *v5 != 0 )
    {
      sscanf(string: v5, format: "%x", &cacheList);
      v6 = GetToken(ppTokenStream: &pCommand);
      if ( *v6 != 0 )
      {
        sscanf(string: v6, format: "%x", &retAddr);
        v7 = numEntries;
        CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::RemoveAll(this: &g_showDataCache_Contents);
        CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::InsertMultipleBefore(
          this: &g_showDataCache_Contents,
          elem: g_showDataCache_Contents.m_Size,
          num: v7);
        localList.m_Size = 0;
        CUtlVector<xrDataCacheItem_t,CUtlMemory<xrDataCacheItem_t,int>>::InsertMultipleBefore(
          this: &localList,
          elem: 0,
          num: numEntries);
        m_pMemory = localList.m_Memory.m_pMemory;
        DmGetMemory(a1: cacheList, a2: 340 * numEntries, a3: localList.m_Memory.m_pMemory, a4: 0);
        v9 = numEntries;
        lruOrder = 1;
        if ( numEntries > 0 )
        {
          p_size = &m_pMemory->size;
          do
          {
            CUtlString::operator=(
              this: &g_showDataCache_Contents.m_Memory.m_pMemory[v1].name,
              src: (const char *)p_size - 320);
            CUtlString::operator=(
              this: &g_showDataCache_Contents.m_Memory.m_pMemory[v1].section,
              src: (const char *)p_size - 64);
            retVal = *p_size;
            g_showDataCache_Contents.m_Memory.m_pMemory[v1].size = _byteswap_ulong(retVal);
            retVal = p_size[1];
            g_showDataCache_Contents.m_Memory.m_pMemory[v1].lockCount = _byteswap_ulong(retVal);
            retVal = p_size[3];
            g_showDataCache_Contents.m_Memory.m_pMemory[v1].itemData = _byteswap_ulong(retVal);
            retVal = p_size[2];
            g_showDataCache_Contents.m_Memory.m_pMemory[v1].clientId = _byteswap_ulong(retVal);
            retVal = p_size[4];
            g_showDataCache_Contents.m_Memory.m_pMemory[v1].handle = _byteswap_ulong(retVal);
            if ( g_showDataCache_Contents.m_Memory.m_pMemory[v1].lockCount != 0 )
            {
              g_showDataCache_Contents.m_Memory.m_pMemory[v1].lruOrder = 0;
            }
            else
            {
              v11 = lruOrder;
              g_showDataCache_Contents.m_Memory.m_pMemory[v1].lruOrder = lruOrder;
              lruOrder = v11 + 1;
            }
            ShowDataCache_AddViewItem(pEntry: &g_showDataCache_Contents.m_Memory.m_pMemory[v1]);
            v9 = numEntries;
            v2 = (xrDataCacheItem_t *)((char *)v2 + 1);
            p_size += 85;
            ++v1;
          }
          while ( (int)v2 < numEntries );
        }
        v12 = v9;
        retVal = v9;
        xboxRetVal = _byteswap_ulong(v9);
        DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
        DebugCommand(pStrFormat: "0x%8.8x = DataCacheList( 0x%8.8x, 0x%8.8x )\n", v12, numEntries, cacheList);
        ShowDataCache_SortItems();
        v2 = localList.m_Memory.m_pMemory;
        v3 = 0;
      }
    }
  }
  if ( localList.m_Memory.m_nGrowSize >= 0 && v2 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
  return v3;
}
