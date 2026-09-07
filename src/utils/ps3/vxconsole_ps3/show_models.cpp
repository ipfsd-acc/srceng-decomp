// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/show_models.cpp
// Functions: 15
// ============================================================

#include "utils\ps3\vxconsole_ps3\show_models.h"

//------------------------------------------------------------------------------
// Address: 0x0040D320
// Name: public: char __near * model_t::GetDispInfo(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall model_t::GetDispInfo(model_t *this, int subItem)
{
  char *result; // eax

  switch ( subItem )
  {
    case 0:
      result = this->pName;
      break;
    case 1:
      result = this->sizeBuff;
      break;
    case 2:
      result = this->vertBuff;
      break;
    case 3:
      result = this->sizeBuffLod0;
      break;
    case 4:
      result = this->vertBuffLod0;
      break;
    case 5:
      result = this->lodBuff;
      break;
    case 6:
      result = this->meshBuff;
      break;
    case 7:
      result = this->partBuff;
      break;
    case 8:
      result = this->boneBuff;
      break;
    default:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D3B0
// Name: void ShowModels_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showModelsSortColumn", value: g_showModels_sortColumn);
  Sys_SetRegistryInteger(keyName: "showModelsSortDescending", value: g_showModels_sortDescending);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showModels_hWnd, lpwndpl: &wp);
  g_showModels_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showModelsWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x0040D460
// Name: void ShowModels_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showModelsSortColumn", defValue: 0, value: &g_showModels_sortColumn);
  Sys_GetRegistryInteger(keyName: "showModelsSortDescending", defValue: 0, value: &g_showModels_sortDescending);
  Sys_GetRegistryString(keyName: "showModelsWindowRect", value: buff, defValue: &str, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showModels_windowRect,
         &g_showModels_windowRect.top,
         &g_showModels_windowRect.right,
         &g_showModels_windowRect.bottom) != 4
    || g_showModels_windowRect.left < 0
    || g_showModels_windowRect.top < 0
    || g_showModels_windowRect.right < 0
    || g_showModels_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showModels_windowRect.left = 0;
    *(_QWORD *)&g_showModels_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D510
// Name: void ShowModels_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_Clear()
{
  int v0; // edi
  int v1; // esi

  if ( g_showModels_hWnd != nullptr )
    SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showModels_pModels != nullptr )
  {
    v0 = 0;
    if ( g_showModels_numModels > 0 )
    {
      v1 = 0;
      do
      {
        free(pMem: g_showModels_pModels[v1].pName);
        ++v0;
        ++v1;
      }
      while ( v0 < g_showModels_numModels );
    }
    g_showModels_pModels = nullptr;
    g_showModels_numModels = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D580
// Name: void ShowModels_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_Export()
{
  int v0; // ebx
  _iobuf *v1; // esi
  label_t *v2; // edi
  int v3; // ebx
  model_t *v4; // edi
  char logFilename[260]; // [esp+4h] [ebp-160h] BYREF
  tagOFNA ofn; // [esp+108h] [ebp-5Ch] BYREF
  unsigned int v7; // [esp+160h] [ebp-4h]

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_showModels_hWnd;
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
      v2 = g_showModels_Labels;
      do
      {
        fprintf(str: v1, format: "\"%s\"", v2->name);
        if ( v0 != 8 )
          fprintf(str: v1, format: ",");
        v2 = (label_t *)((char *)v2 + 44);
        ++v0;
      }
      while ( (int)v2 < (int)&vec2_invalid_14 );
      fprintf(str: v1, format: "\n");
      v3 = 0;
      if ( g_showModels_numModels > 0 )
      {
        v7 = 0;
        do
        {
          v4 = &g_showModels_pModels[v7 / 0xA8];
          fprintf(str: v1, format: "\"%s\"", g_showModels_pModels[v7 / 0xA8].pName);
          fprintf(str: v1, format: ",\"%s\"", v4->sizeBuff);
          fprintf(str: v1, format: ",\"%s\"", v4->vertBuff);
          fprintf(str: v1, format: ",\"%s\"", v4->sizeBuffLod0);
          fprintf(str: v1, format: ",\"%s\"", v4->vertBuffLod0);
          fprintf(str: v1, format: ",\"%s\"", v4->lodBuff);
          fprintf(str: v1, format: ",\"%s\"", v4->meshBuff);
          fprintf(str: v1, format: ",\"%s\"", v4->partBuff);
          fprintf(str: v1, format: ",\"%s\"", v4->boneBuff);
          fprintf(str: v1, format: "\n");
          v7 += 168;
          ++v3;
        }
        while ( v3 < g_showModels_numModels );
      }
      fclose(stream: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D750
// Name: void ShowModels_Summary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_Summary()
{
  int v0; // ecx
  int v1; // eax
  int v2; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  int *p_dataSizeLod0; // eax
  unsigned int v7; // ecx
  model_t *v8; // ecx
  int dataSize; // eax
  char buff[1028]; // [esp+1Ch] [ebp-410h] BYREF
  int totalStatic; // [esp+420h] [ebp-Ch]
  int i; // [esp+424h] [ebp-8h]
  int totalStaticLod0; // [esp+428h] [ebp-4h]

  v0 = g_showModels_numModels;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  totalStatic = 0;
  totalStaticLod0 = 0;
  if ( g_showModels_numModels >= 2 )
  {
    p_dataSizeLod0 = &g_showModels_pModels->dataSizeLod0;
    v7 = ((unsigned int)(g_showModels_numModels - 2) >> 1) + 1;
    i = 2 * v7;
    v3 = 0;
    do
    {
      v4 += *(p_dataSizeLod0 - 1);
      v2 += *p_dataSizeLod0;
      v5 += p_dataSizeLod0[41];
      v3 += p_dataSizeLod0[42];
      p_dataSizeLod0 += 84;
      --v7;
    }
    while ( v7 != 0 );
    v1 = i;
    v0 = g_showModels_numModels;
  }
  if ( v1 >= v0 )
  {
    dataSize = totalStatic;
  }
  else
  {
    v8 = &g_showModels_pModels[v1];
    dataSize = v8->dataSize;
    totalStaticLod0 = v8->dataSizeLod0;
    v0 = g_showModels_numModels;
  }
  sprintf(
    string: buff,
    format: "Entries:\t\t\t%d\nStatic Memory:\t\t%.2f MB\n LOD 0 Memory:\t\t%.2f MB\n",
    v0,
    (float)((float)(dataSize + v4 + v5) * 0.00000095367432),
    (float)((float)(totalStaticLod0 + v2 + v3) * 0.00000095367432));
  MessageBoxA(hWnd: g_showModels_hWnd, lpText: buff, lpCaption: "Model Summary", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040D850
// Name: int ShowModels_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowModels_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax

  result = 0;
  switch ( g_showModels_sortColumn )
  {
    case 0:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 4), s2: *(const char **)(lParam2 + 4));
      break;
    case 1:
      result = *(_DWORD *)(lParam1 + 8) - *(_DWORD *)(lParam2 + 8);
      break;
    case 2:
      result = *(_DWORD *)(lParam1 + 48) - *(_DWORD *)(lParam2 + 48);
      break;
    case 3:
      result = *(_DWORD *)(lParam1 + 12) - *(_DWORD *)(lParam2 + 12);
      break;
    case 4:
      result = *(_DWORD *)(lParam1 + 52) - *(_DWORD *)(lParam2 + 52);
      break;
    case 5:
      result = *(_DWORD *)(lParam1 + 88) - *(_DWORD *)(lParam2 + 88);
      break;
    case 6:
      result = *(_DWORD *)(lParam1 + 108) - *(_DWORD *)(lParam2 + 108);
      break;
    case 7:
      result = *(_DWORD *)(lParam1 + 128) - *(_DWORD *)(lParam2 + 128);
      break;
    case 8:
      result = *(_DWORD *)(lParam1 + 148) - *(_DWORD *)(lParam2 + 148);
      break;
    default:
      break;
  }
  if ( g_showModels_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D930
// Name: void ShowModels_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showModels_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowModels_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_4449CC;
    for ( j = 9; j != 0; --j )
    {
      if ( v2 == g_showModels_sortColumn )
        v4 = 2 * (g_showModels_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DA30
// Name: void ShowModels_AddViewItem(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_AddViewItem(model_t *item)
{
  int dataSize; // eax
  LRESULT v2; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showModels_hWnd != nullptr )
  {
    dataSize = item->dataSize;
    if ( dataSize < 0 )
      *(_DWORD *)item->sizeBuff = 4144959;
    else
      sprintf(string: item->sizeBuff, format: "%d", dataSize);
    if ( item->numVertices < 0 )
      *(_DWORD *)item->vertBuff = 4144959;
    else
      sprintf(string: item->vertBuff, format: "%d", item->numVertices);
    if ( item->dataSizeLod0 < 0 )
      *(_DWORD *)item->sizeBuffLod0 = 4144959;
    else
      sprintf(string: item->sizeBuffLod0, format: "%d", item->dataSizeLod0);
    if ( item->numVerticesLod0 < 0 )
      *(_DWORD *)item->vertBuffLod0 = 4144959;
    else
      sprintf(string: item->vertBuffLod0, format: "%d", item->numVerticesLod0);
    if ( item->numLODs < 0 )
      *(_DWORD *)item->lodBuff = 4144959;
    else
      sprintf(string: item->lodBuff, format: "%d", item->numLODs);
    if ( item->numMeshes < 0 )
      *(_DWORD *)item->meshBuff = 4144959;
    else
      sprintf(string: item->meshBuff, format: "%d", item->numMeshes);
    if ( item->numParts < 0 )
      *(_DWORD *)item->partBuff = 4144959;
    else
      sprintf(string: item->partBuff, format: "%d", item->numParts);
    if ( item->numBones < 0 )
      *(_DWORD *)item->boneBuff = 4144959;
    else
      sprintf(string: item->boneBuff, format: "%d", item->numBones);
    v2 = SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    memset(&lvi.iSubItem, 0, 12);
    lvi.mask = 13;
    lvi.iItem = v2;
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)item;
    item->listIndex = SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DBC0
// Name: void ShowModels_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_Refresh()
{
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(command, "vx_model_list");
  if ( g_connectionState == kCONNECTEDAPP )
    ProcessCommand(strCmdIn: command);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC10
// Name: void ShowModels_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_SizeWindow(HWND__ *hwnd, int cx, int cy)
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
  SetWindowPos(hWnd: g_showModels_hWndListView, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: right, cy: bottom, uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC60
// Name: long ShowModels_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
UINT __stdcall ShowModels_WndProc(HWND__ *hwnd, UINT message, WPARAM wParam, unsigned int lParam)
{
  UINT result; // eax
  int v5; // eax

  if ( message > 0x4E )
  {
    if ( message == 273 )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0x9CC7u:
          ShowModels_Summary();
          return 0;
        case 0x9CC8u:
          ShowModels_Refresh();
          return 0;
        case 0x9CC9u:
          ShowModels_Export();
          return 0;
        default:
          break;
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
        ShowModels_SaveConfig();
        g_showModels_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowModels_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 == -150 )
  {
    *(_DWORD *)(lParam + 32) = model_t::GetDispInfo(this: *(model_t **)(lParam + 44), subItem: *(_DWORD *)(lParam + 20));
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  if ( v5 != -108 )
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  if ( g_showModels_sortColumn == *(_DWORD *)(lParam + 16) )
    g_showModels_sortDescending ^= 1u;
  else
    g_showModels_sortColumn = *(_DWORD *)(lParam + 16);
  ShowModels_SortItems();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD90
// Name: bool ShowModels_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowModels_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowModels_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)126;
  wndclass.hCursor = (HICON__ *)"showModelsCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowModels_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DE40
// Name: void ShowModels_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowModels_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  char *v2; // edx
  int v3; // esi
  int v4; // edi
  char strCmdIn[256]; // [esp+4h] [ebp-13Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+104h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+130h] [ebp-10h] BYREF

  if ( g_showModels_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showModels_hWnd) )
      ShowWindow(hWnd: g_showModels_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showModels_hWnd);
  }
  else
  {
    g_showModels_hWnd = CreateWindowExA(
                          dwExStyle: 0x200u,
                          lpClassName: "showModelsCLASS",
                          lpWindowName: "Models",
                          dwStyle: 0x80CF0000,
                          X: 0,
                          Y: 0,
                          nWidth: 700,
                          nHeight: 400,
                          hWndParent: g_hDlgMain,
                          hMenu: nullptr,
                          hInstance: g_hInstance,
                          lpParam: nullptr);
    GetClientRect(hWnd: g_showModels_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showModels_hWndListView = CreateWindowExA(
                                  dwExStyle: 0,
                                  lpClassName: "SysListView32",
                                  lpWindowName: &str,
                                  dwStyle: 0x5000000Du,
                                  X: 0,
                                  Y: 0,
                                  nWidth: clientRect.right - clientRect.left,
                                  nHeight: clientRect.bottom - clientRect.top,
                                  hWndParent: g_showModels_hWnd,
                                  hMenu: (HMENU)0x64,
                                  hInstance: g_hInstance,
                                  lpParam: nullptr);
    for ( i = 0; i < 99; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = *(char **)((char *)&g_showModels_Labels[0].name + i * 4);
      lvc.cx = dword_4449C4[i];
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.pszText = v2;
      SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showModels_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v3 = 0;
    if ( g_showModels_numModels > 0 )
    {
      v4 = 0;
      do
      {
        ShowModels_AddViewItem(item: &g_showModels_pModels[v4]);
        ++v3;
        ++v4;
      }
      while ( v3 < g_showModels_numModels );
    }
    ShowModels_SortItems();
    if ( g_showModels_windowRect.right != 0 && g_showModels_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_showModels_hWnd,
        X: g_showModels_windowRect.left,
        Y: g_showModels_windowRect.top,
        nWidth: g_showModels_windowRect.right - g_showModels_windowRect.left,
        nHeight: g_showModels_windowRect.bottom - g_showModels_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_showModels_hWnd, nCmdShow: 1);
    strcpy(strCmdIn, "vx_model_list");
    if ( g_connectionState == kCONNECTEDAPP )
      ProcessCommand(strCmdIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E2B0
// Name: int rc_ModelList(char __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_ModelList(char *const commandPtr, unsigned int nDataLength)
{
  int m_Size; // esi
  xrModel_t *m_pMemory; // edi
  model_t *v4; // esi
  const char *j; // ebx
  _BYTE *v6; // eax
  const char *v7; // ecx
  int v8; // eax
  char v9; // dl
  unsigned int v10; // eax
  CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > vLocalList; // [esp+8h] [ebp-20h] BYREF
  unsigned int dataSize; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  unsigned int v15; // [esp+24h] [ebp-4h]

  memset(&vLocalList, 0, sizeof(vLocalList));
  ShowModels_Clear();
  rc_Helper_UnpackListOfThings<xrModel_t>(vOutList: &vLocalList, pStringIn: (int)commandPtr, nDataLength);
  m_Size = vLocalList.m_Size;
  g_showModels_numModels = vLocalList.m_Size;
  g_showModels_pModels = (model_t *)operator new(nSize: 168 * vLocalList.m_Size);
  memset(dst: (unsigned __int8 *)g_showModels_pModels, value: 0, count: 168 * m_Size);
  if ( m_Size > 0 )
  {
    v15 = 0;
    m_pMemory = vLocalList.m_Memory.m_pMemory;
    for ( i = m_Size; i != 0; --i )
    {
      v4 = &g_showModels_pModels[v15 / 0xA8];
      for ( j = (const char *)m_pMemory; *j != 0; ++j )
      {
        if ( isalnum(c: *j) != 0 )
          break;
        if ( *j == 95 )
          break;
      }
      v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(j) + 1);
      dataSize = (unsigned int)v6;
      if ( v6 != nullptr )
      {
        v7 = j;
        v8 = v6 - j;
        do
        {
          v9 = *v7;
          v7[v8] = *v7;
          ++v7;
        }
        while ( v9 != 0 );
        v10 = dataSize;
      }
      else
      {
        v10 = 0;
      }
      v4->pName = (char *)v10;
      dataSize = m_pMemory->dataSize;
      v4->dataSize = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numVertices;
      v4->numVertices = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->dataSizeLod0;
      v4->dataSizeLod0 = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numVerticesLod0;
      v4->numVerticesLod0 = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numBones;
      v4->numBones = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numParts;
      v4->numParts = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numLODs;
      v4->numLODs = _byteswap_ulong(dataSize);
      dataSize = m_pMemory->numMeshes;
      v4->numMeshes = _byteswap_ulong(dataSize);
      ShowModels_AddViewItem(item: v4);
      v15 += 168;
      ++m_pMemory;
    }
  }
  ShowModels_SortItems();
  if ( vLocalList.m_Memory.m_nGrowSize >= 0 && vLocalList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vLocalList.m_Memory.m_pMemory);
  return 0;
}
