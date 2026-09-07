// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_materials.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004180C0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418110
// Name: void ShowMaterials_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showMaterialsCurrentFrame", value: g_showMaterials_currentFrame);
  Sys_SetRegistryInteger(keyName: "showMaterialsSortColumn", value: g_showMaterials_sortColumn);
  Sys_SetRegistryInteger(keyName: "showMaterialsSortDescending", value: g_showMaterials_sortDescending);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showMaterials_hWnd, lpwndpl: &wp);
  g_showMaterials_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showMaterialsWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x004181D0
// Name: void ShowMaterials_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showMaterialsCurrentFrame", defValue: 0, value: &g_showMaterials_currentFrame);
  Sys_GetRegistryInteger(keyName: "showMaterialsSortColumn", defValue: 0, value: &g_showMaterials_sortColumn);
  Sys_GetRegistryInteger(keyName: "showMaterialsSortDescending", defValue: 0, value: &g_showMaterials_sortDescending);
  Sys_GetRegistryString(keyName: "showMaterialsWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showMaterials_windowRect,
         &g_showMaterials_windowRect.top,
         &g_showMaterials_windowRect.right,
         &g_showMaterials_windowRect.bottom) != 4
    || g_showMaterials_windowRect.left < 0
    || g_showMaterials_windowRect.top < 0
    || g_showMaterials_windowRect.right < 0
    || g_showMaterials_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showMaterials_windowRect.left = 0;
    *(_QWORD *)&g_showMaterials_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418290
// Name: void ShowMaterials_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_Clear()
{
  int v0; // edi
  int v1; // esi

  if ( g_showMaterials_hWnd != nullptr )
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showMaterials_pMaterials != nullptr )
  {
    v0 = 0;
    if ( g_showMaterials_numMaterials > 0 )
    {
      v1 = 0;
      do
      {
        free(pMem: g_showMaterials_pMaterials[v1].pName);
        free(pMem: g_showMaterials_pMaterials[v1].pShaderName);
        ++v0;
        ++v1;
      }
      while ( v0 < g_showMaterials_numMaterials );
    }
    g_showMaterials_pMaterials = nullptr;
    g_showMaterials_numMaterials = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418310
// Name: void ShowMaterials_SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_SetTitle()
{
  HWND v0; // edx
  char *v1; // eax
  char v2; // cl
  char v3; // [esp-1h] [ebp-81h] BYREF
  char titleBuff[128]; // [esp+0h] [ebp-80h] BYREF

  v0 = g_showMaterials_hWnd;
  if ( g_showMaterials_hWnd != nullptr )
  {
    strcpy(titleBuff, "Materials ");
    if ( g_showMaterials_currentFrame != 0 )
    {
      v1 = &v3;
      do
        v2 = *++v1;
      while ( v2 != 0 );
      strcpy(v1, " [FRAME]");
    }
    SetWindowTextA(hWnd: v0, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418390
// Name: int ShowMaterials_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowMaterials_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax

  result = 0;
  if ( g_showMaterials_sortColumn != 0 )
  {
    if ( g_showMaterials_sortColumn == 1 )
    {
      result = _V_stricmp(s1: *(const char **)(lParam1 + 8), s2: *(const char **)(lParam2 + 8));
    }
    else if ( g_showMaterials_sortColumn == 2 )
    {
      result = *(_DWORD *)(lParam1 + 12) - *(_DWORD *)(lParam2 + 12);
    }
  }
  else
  {
    result = _V_stricmp(s1: *(const char **)(lParam1 + 4), s2: *(const char **)(lParam2 + 4));
  }
  if ( g_showMaterials_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004183F0
// Name: void ShowMaterials_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showMaterials_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)ShowMaterials_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_465AE4;
    for ( j = 3; j != 0; --j )
    {
      if ( v2 == g_showMaterials_sortColumn )
        v4 = 2 * (g_showMaterials_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004184F0
// Name: void ShowMaterials_AddViewItem(struct material_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_AddViewItem(material_t *pMaterial)
{
  LRESULT v1; // ebx
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  if ( g_showMaterials_hWnd != nullptr )
  {
    sprintf(string: pMaterial->refCountBuff, format: "%d", pMaterial->refCount);
    v1 = SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    lvi.mask = 13;
    lvi.iItem = v1;
    memset(&lvi.iSubItem, 0, 12);
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pMaterial;
    pMaterial->listIndex = SendMessageA(
                             hWnd: g_showMaterials_hWndListView,
                             Msg: 0x1007u,
                             wParam: 0,
                             lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418580
// Name: void ShowMaterials_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_Refresh()
{
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(command, "mat_material_list");
  if ( g_connectedToApp )
    ProcessCommand(strCmdIn: command);
}

//------------------------------------------------------------------------------
// Address: 0x004185E0
// Name: void ShowMaterials_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_SizeWindow(HWND__ *hwnd, int cx, int cy)
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
    hWnd: g_showMaterials_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00418630
// Name: long ShowMaterials_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowMaterials_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9CC4u, uCheck: g_showMaterials_currentFrame != 0 ? 8 : 0);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    switch ( (unsigned __int16)wParam )
    {
      case 0x9CC4u:
        g_showMaterials_currentFrame ^= 1u;
        ShowMaterials_SetTitle();
        break;
      case 0x9CC8u:
        break;
      case 0x9CC9u:
        return 0;
      default:
        return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    ShowMaterials_Refresh();
    return 0;
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        ShowMaterials_SaveConfig();
        g_showMaterials_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowMaterials_SizeWindow(hwnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 == -150 )
  {
    v6 = *(_DWORD *)(lParam + 20);
    v7 = *(_DWORD *)(lParam + 44);
    if ( v6 == 0 )
    {
      *(_DWORD *)(lParam + 32) = *(_DWORD *)(v7 + 4);
      return 0;
    }
    v8 = v6 - 1;
    if ( v8 == 0 )
    {
      *(_DWORD *)(lParam + 32) = *(_DWORD *)(v7 + 8);
      return 0;
    }
    result = v8 - 1;
    if ( result == 0 )
    {
      *(_DWORD *)(lParam + 32) = v7 + 16;
      return result;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  if ( v5 != -108 )
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  if ( g_showMaterials_sortColumn == *(_DWORD *)(lParam + 16) )
    g_showMaterials_sortDescending ^= 1u;
  else
    g_showMaterials_sortColumn = *(_DWORD *)(lParam + 16);
  ShowMaterials_SortItems();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418790
// Name: bool ShowMaterials_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowMaterials_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowMaterials_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)124;
  wndclass.hCursor = (HICON__ *)"SHOWMATERIALSCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowMaterials_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418830
// Name: void ShowMaterials_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMaterials_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  char *v2; // edx
  int v3; // esi
  int v4; // edi
  HWND v5; // esi
  char *v6; // eax
  char v7; // cl
  char strCmdIn[127]; // [esp+4h] [ebp-13Ch] BYREF
  char v9; // [esp+83h] [ebp-BDh] BYREF
  char String[128]; // [esp+84h] [ebp-BCh] BYREF
  tagLVCOLUMNA lvc; // [esp+104h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+130h] [ebp-10h] BYREF

  if ( g_showMaterials_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showMaterials_hWnd) )
      ShowWindow(hWnd: g_showMaterials_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showMaterials_hWnd);
  }
  else
  {
    g_showMaterials_hWnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SHOWMATERIALSCLASS",
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
    GetClientRect(hWnd: g_showMaterials_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showMaterials_hWndListView = CreateWindowExA(
                                     dwExStyle: 0,
                                     lpClassName: "SysListView32",
                                     lpWindowName: &defValue,
                                     dwStyle: 0x50000001u,
                                     X: 0,
                                     Y: 0,
                                     nWidth: clientRect.right - clientRect.left,
                                     nHeight: clientRect.bottom - clientRect.top,
                                     hWndParent: g_showMaterials_hWnd,
                                     hMenu: (HMENU)0x64,
                                     hInstance: g_hInstance,
                                     lpParam: nullptr);
    for ( i = 0; i < 33; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = *(char **)((char *)&g_showMaterials_Labels[0].name + i * 4);
      lvc.cx = dword_465ADC[i];
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.pszText = v2;
      SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showMaterials_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v3 = 0;
    if ( g_showMaterials_numMaterials > 0 )
    {
      v4 = 0;
      do
      {
        ShowMaterials_AddViewItem(pMaterial: &g_showMaterials_pMaterials[v4]);
        ++v3;
        ++v4;
      }
      while ( v3 < g_showMaterials_numMaterials );
    }
    ShowMaterials_SortItems();
    v5 = g_showMaterials_hWnd;
    if ( g_showMaterials_hWnd != nullptr )
    {
      strcpy(String, "Materials ");
      if ( g_showMaterials_currentFrame != 0 )
      {
        v6 = &v9;
        do
          v7 = *++v6;
        while ( v7 != 0 );
        strcpy(v6, " [FRAME]");
      }
      SetWindowTextA(hWnd: v5, lpString: String);
      v5 = g_showMaterials_hWnd;
    }
    if ( g_showMaterials_windowRect.right != 0 && g_showMaterials_windowRect.bottom != 0 )
    {
      MoveWindow(
        hWnd: v5,
        X: g_showMaterials_windowRect.left,
        Y: g_showMaterials_windowRect.top,
        nWidth: g_showMaterials_windowRect.right - g_showMaterials_windowRect.left,
        nHeight: g_showMaterials_windowRect.bottom - g_showMaterials_windowRect.top,
        bRepaint: false);
      v5 = g_showMaterials_hWnd;
    }
    ShowWindow(hWnd: v5, nCmdShow: 1);
    strcpy(strCmdIn, "mat_material_list");
    if ( g_connectedToApp )
      ProcessCommand(strCmdIn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418AE0
// Name: int rc_MaterialList(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_MaterialList(char *commandPtr)
{
  char *Token; // eax
  char *v2; // eax
  char *v3; // eax
  unsigned __int8 *v4; // esi
  unsigned int v5; // eax
  int v6; // ebx
  int v7; // edi
  unsigned int *v8; // esi
  unsigned int v9; // edi
  int retVal; // [esp+4h] [ebp-18h]
  int retAddr; // [esp+Ch] [ebp-10h] BYREF
  int xboxRetVal; // [esp+10h] [ebp-Ch] BYREF
  int materialList; // [esp+14h] [ebp-8h] BYREF
  int numMaterials; // [esp+18h] [ebp-4h] BYREF

  ShowMaterials_Clear();
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &numMaterials);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%x", &materialList);
  v3 = GetToken(ppTokenStream: &commandPtr);
  if ( *v3 == 0 )
    return -1;
  sscanf(string: v3, format: "%x", &retAddr);
  v4 = (unsigned __int8 *)operator new(nSize: 516 * numMaterials);
  retVal = (int)v4;
  memset(dst: v4, value: 0, count: 516 * numMaterials);
  g_showMaterials_numMaterials = numMaterials;
  g_showMaterials_pMaterials = (material_t *)operator new(nSize: 32 * numMaterials);
  memset(dst: (unsigned __int8 *)g_showMaterials_pMaterials, value: 0, count: 32 * numMaterials);
  DmGetMemory(a1: materialList, a2: 516 * numMaterials, a3: v4, a4: 0);
  v5 = numMaterials;
  v6 = 0;
  if ( numMaterials > 0 )
  {
    v7 = 0;
    v8 = (unsigned int *)(v4 + 512);
    do
    {
      *v8 = _byteswap_ulong(*v8);
      g_showMaterials_pMaterials[v7].pName = MemAlloc_StrDup(pString: (const char *)v8 - 512);
      g_showMaterials_pMaterials[v7].pShaderName = MemAlloc_StrDup(pString: (const char *)v8 - 256);
      g_showMaterials_pMaterials[v7].refCount = *v8;
      ShowMaterials_AddViewItem(pMaterial: &g_showMaterials_pMaterials[v7]);
      v5 = numMaterials;
      ++v6;
      v8 += 129;
      ++v7;
    }
    while ( v6 < numMaterials );
    v4 = (unsigned __int8 *)retVal;
  }
  v9 = v5;
  xboxRetVal = _byteswap_ulong(v5);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = MaterialList( 0x%8.8x, 0x%8.8x )\n", v9, numMaterials, materialList);
  free(pMem: v4);
  ShowMaterials_SortItems();
  return 0;
}
