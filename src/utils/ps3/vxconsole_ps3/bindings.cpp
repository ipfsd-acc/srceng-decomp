// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/bindings.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004012C0
// Name: void Bindings_ModifyEntry(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_ModifyEntry(int i, const char *pMenuName, const char *pCommandString)
{
  _BYTE *v3; // eax
  _BYTE *v4; // eax

  v3 = (_BYTE *)dword_444018[4 * i];
  if ( v3 != nullptr && *v3 != 0 )
    Sys_Free(ptr: (void *)dword_444018[4 * i]);
  dword_444018[4 * i] = (int)Sys_CopyString(str: pMenuName);
  v4 = (_BYTE *)dword_44401C[4 * i];
  if ( v4 != nullptr && *v4 != 0 )
    Sys_Free(ptr: (void *)dword_44401C[4 * i]);
  dword_44401C[4 * i] = (int)Sys_CopyString(str: pCommandString);
}

//------------------------------------------------------------------------------
// Address: 0x00401330
// Name: int Bindings_GetSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
WPARAM __cdecl Bindings_GetSelectedItem()
{
  WPARAM v0; // esi

  v0 = 0;
  while ( SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x102Cu, wParam: v0, lParam: 2) != 2 )
  {
    if ( (int)++v0 >= 12 )
      return -1;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00401370
// Name: bool Bindings_TranslateKey(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Bindings_TranslateKey(int vkKeyCode)
{
  int v1; // edx
  int *v2; // eax

  v1 = 0;
  v2 = dword_44401C;
  while ( *v2 == 0 || *(_BYTE *)*v2 == 0 || vkKeyCode != *(v2 - 3) )
  {
    v2 += 4;
    ++v1;
    if ( (int)v2 >= (int)&off_4440DC )
      return 0;
  }
  ProcessCommand(strCmdIn: (const char *)dword_44401C[4 * v1]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004013C0
// Name: bool Bindings_MenuSelection(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Bindings_MenuSelection(int wID)
{
  if ( (unsigned int)(wID - 50002) > 0xB )
    return 0;
  else
    return Bindings_TranslateKey(vkKeyCode: g_bindings[wID - 50002].keyCode);
}

//------------------------------------------------------------------------------
// Address: 0x004013F0
// Name: void Bindings_UpdateMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_UpdateMenu()
{
  HMENU PopupMenu; // eax
  int v1; // edi
  HMENU__ *v2; // ebx
  int *v3; // esi
  HMENU__ *v4; // esi
  const char *v5; // [esp-10h] [ebp-8Ch]
  int v6; // [esp-Ch] [ebp-88h]
  char menuBuff[64]; // [esp+4h] [ebp-78h] BYREF
  tagMENUITEMINFOA menuItemInfo; // [esp+44h] [ebp-38h] BYREF
  HMENU__ *hMenu; // [esp+74h] [ebp-8h]
  int numAdded; // [esp+78h] [ebp-4h]

  hMenu = GetMenu(hWnd: g_hDlgMain);
  if ( hMenu != nullptr )
  {
    memset(dst: (unsigned __int8 *)&menuItemInfo, value: 0, count: sizeof(menuItemInfo));
    menuItemInfo.cbSize = 48;
    numAdded = 0;
    PopupMenu = CreatePopupMenu();
    menuItemInfo.fType = 0;
    v1 = 11;
    v2 = PopupMenu;
    menuItemInfo.fMask = 322;
    v3 = (int *)&unk_4440CC;
    do
    {
      if ( *v3 != 0 && *(_BYTE *)*v3 != 0 )
      {
        v6 = *(v3 - 3) - 111;
        v5 = (const char *)*(v3 - 1);
        menuItemInfo.wID = v1 + 50002;
        sprintf(string: menuBuff, format: "%s\tF%d", v5, v6);
        menuItemInfo.dwTypeData = menuBuff;
        InsertMenuItemA(hmenu: v2, item: 0, fByPosition: true, lpmi: &menuItemInfo);
        ++numAdded;
      }
      v3 -= 4;
      --v1;
    }
    while ( (int)v3 >= (int)dword_44401C );
    if ( numAdded != 0 )
    {
      menuItemInfo.fMask = 256;
      menuItemInfo.fType = 2048;
      InsertMenuItemA(hmenu: v2, item: 0, fByPosition: true, lpmi: &menuItemInfo);
    }
    menuItemInfo.fMask = 322;
    menuItemInfo.fType = 0;
    menuItemInfo.wID = 50001;
    menuItemInfo.dwTypeData = "Edit...";
    InsertMenuItemA(hmenu: v2, item: 0, fByPosition: true, lpmi: &menuItemInfo);
    v4 = hMenu;
    menuItemInfo.fMask = 4;
    GetMenuItemInfoA(hmenu: hMenu, item: 0xC350u, fByPosition: false, lpmii: &menuItemInfo);
    if ( menuItemInfo.hSubMenu != nullptr )
      DestroyMenu(hMenu: menuItemInfo.hSubMenu);
    else
      AppendMenuA(hMenu: v4, uFlags: 0, uIDNewItem: 0xC350u, lpNewItem: "Bindings");
    menuItemInfo.fMask = 4;
    menuItemInfo.hSubMenu = v2;
    SetMenuItemInfoA(hmenu: v4, item: 0xC350u, fByPositon: false, lpmii: &menuItemInfo);
    DrawMenuBar(hWnd: g_hDlgMain);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401560
// Name: int BindingsModifyDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall BindingsModifyDlg_Proc(HWND__ *hWnd, unsigned int message, INT_PTR wParam, int lParam)
{
  if ( message == 272 )
  {
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1052, lpString: g_bindingsModify_keyCode);
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1050, lpString: g_bindingsModify_menuName);
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1051, lpString: g_bindingsModify_command);
    return 1;
  }
  else
  {
    if ( message != 273 )
      return 0;
    if ( (unsigned __int16)wParam != 2 )
    {
      if ( (unsigned __int16)wParam == 1019 )
      {
        GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1050, lpString: g_bindingsModify_menuName, cchMax: 256);
        GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1051, lpString: g_bindingsModify_command, cchMax: 256);
      }
      else if ( (unsigned __int16)wParam != 1020 )
      {
        return 0;
      }
    }
    EndDialog(hDlg: hWnd, nResult: wParam);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401610
// Name: void BindingsModifyDlg_Open(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BindingsModifyDlg_Open(int selection)
{
  int v1; // eax
  char *v2; // edx
  char v3; // cl
  int v4; // eax
  char *v5; // edx
  char v6; // cl

  sprintf(string: g_bindingsModify_keyCode, format: "F%d", selection + 1);
  v1 = dword_444018[4 * selection];
  v2 = &g_bindingsModify_menuName[-v1];
  do
  {
    v3 = *(_BYTE *)v1;
    v2[v1] = *(_BYTE *)v1;
    ++v1;
  }
  while ( v3 != 0 );
  v4 = dword_44401C[4 * selection];
  v5 = &g_bindingsModify_command[-v4];
  do
  {
    v6 = *(_BYTE *)v4;
    v5[v4] = *(_BYTE *)v4;
    ++v4;
  }
  while ( v6 != 0 );
  if ( (unsigned __int16)DialogBoxParamA(
                           hInstance: g_hInstance,
                           lpTemplateName: (LPCSTR)0x7B,
                           hWndParent: g_hDlgMain,
                           lpDialogFunc: (DLGPROC)BindingsModifyDlg_Proc,
                           dwInitParam: 0) == 1019 )
  {
    Bindings_ModifyEntry(i: selection, pMenuName: g_bindingsModify_menuName, pCommandString: g_bindingsModify_command);
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1015u, wParam: 0, lParam: 11);
    UpdateWindow(hWnd: g_bindings_hWndListView);
    Bindings_UpdateMenu();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016D0
// Name: void Bindings_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_LoadConfig()
{
  int v0; // edi
  void **v1; // esi
  const char *Token; // eax
  char *v3; // eax
  char *v4; // edx
  char v5; // cl
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  _BYTE *v9; // eax
  char buff[256]; // [esp+Ch] [ebp-424h] BYREF
  char valueBuff[256]; // [esp+10Ch] [ebp-324h] BYREF
  char commandString[256]; // [esp+20Ch] [ebp-224h] BYREF
  char menuName[256]; // [esp+30Ch] [ebp-124h] BYREF
  char keyBuff[32]; // [esp+40Ch] [ebp-24h] BYREF
  char *ptr; // [esp+42Ch] [ebp-4h] BYREF

  v0 = 0;
  v1 = (void **)dword_44401C;
  do
  {
    menuName[0] = 0;
    commandString[0] = 0;
    sprintf(string: keyBuff, format: "bind%d", v0);
    Sys_GetRegistryString(keyName: keyBuff, value: valueBuff, defValue: &str, valueLen: 256);
    ptr = valueBuff;
    Token = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *Token != 0 )
      atoi(nptr: Token);
    v3 = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *v3 != 0 )
    {
      v4 = (char *)(menuName - v3);
      do
      {
        v5 = *v3;
        v3[(_DWORD)v4] = *v3;
        ++v3;
      }
      while ( v5 != 0 );
    }
    v6 = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *v6 != 0 )
    {
      v7 = (char *)(commandString - v6);
      do
      {
        v8 = *v6;
        v6[(_DWORD)v7] = *v6;
        ++v6;
      }
      while ( v8 != 0 );
    }
    v9 = *(v1 - 1);
    if ( v9 != nullptr && *v9 != 0 )
      Sys_Free(ptr: *(v1 - 1));
    *(v1 - 1) = Sys_CopyString(str: menuName);
    if ( *v1 != nullptr && *(_BYTE *)*v1 != 0 )
      Sys_Free(ptr: *v1);
    *v1 = Sys_CopyString(str: commandString);
    v1 += 4;
    ++v0;
  }
  while ( (int)v1 < (int)&off_4440DC );
  Sys_GetRegistryString(keyName: "bindingsWindowRect", value: buff, defValue: &str, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_bindings_windowRect,
         &g_bindings_windowRect.top,
         &g_bindings_windowRect.right,
         &g_bindings_windowRect.bottom) != 4 )
  {
    *(_QWORD *)&g_bindings_windowRect.left = 0;
    *(_QWORD *)&g_bindings_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401850
// Name: void Bindings_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_SaveConfig()
{
  int v0; // edi
  const char **v1; // esi
  const char *v2; // eax
  const char *v3; // ecx
  char buff[256]; // [esp+8h] [ebp-24Ch] BYREF
  char valueBuff[256]; // [esp+108h] [ebp-14Ch] BYREF
  char keyBuff[32]; // [esp+208h] [ebp-4Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+228h] [ebp-2Ch] BYREF

  if ( g_bindings_hWnd != nullptr )
  {
    memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
    wp.length = 44;
    GetWindowPlacement(hWnd: g_bindings_hWnd, lpwndpl: &wp);
    g_bindings_windowRect = wp.rcNormalPosition;
    sprintf(
      string: buff,
      format: "%d %d %d %d",
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.top,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.bottom);
    Sys_SetRegistryString(keyName: "bindingsWindowRect", value: buff);
  }
  v0 = 0;
  v1 = (const char **)dword_44401C;
  do
  {
    sprintf(string: keyBuff, format: "bind%d", v0);
    v2 = *(v1 - 1);
    if ( v2 == nullptr )
      v2 = &str;
    v3 = *v1;
    if ( *v1 == nullptr )
      v3 = &str;
    if ( _snprintf(string: valueBuff, count: 0x100u, format: "%d \"%s\" \"%s\"", *(v1 - 3), v2, v3) == -1 )
      valueBuff[0] = 0;
    Sys_SetRegistryString(keyName: keyBuff, value: valueBuff);
    v1 += 4;
    ++v0;
  }
  while ( (int)v1 < (int)&off_4440DC );
}

//------------------------------------------------------------------------------
// Address: 0x00401960
// Name: long Bindings_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall Bindings_WndProc(HWND__ *hwnd, UINT message, WPARAM wParam, unsigned int lParam)
{
  int right; // ecx
  int bottom; // eax
  signed int v7; // eax
  signed int SelectedItem; // eax
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // ecx
  int v12; // eax
  tagRECT Rect; // [esp+Ch] [ebp-10h] BYREF

  if ( message > 5 )
  {
    if ( message == 78 )
    {
      v9 = *(_DWORD *)(lParam + 8);
      if ( v9 != -150 )
      {
        if ( v9 == -3 )
        {
          BindingsModifyDlg_Open(selection: *(_DWORD *)(lParam + 12));
          return DefWindowProcA(hWnd: hwnd, Msg: 0x4Eu, wParam, lParam);
        }
        return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
      }
      v10 = *(_DWORD *)(lParam + 20);
      v11 = *(_DWORD **)(lParam + 44);
      if ( v10 == 0 )
      {
        *(_DWORD *)(lParam + 32) = v11[1];
        return 0;
      }
      v12 = v10 - 1;
      if ( v12 == 0 )
      {
        *(_DWORD *)(lParam + 32) = v11[2];
        return 0;
      }
      if ( v12 == 1 )
      {
        *(_DWORD *)(lParam + 32) = v11[3];
        return 0;
      }
    }
    else if ( message == 273 )
    {
      if ( (unsigned __int16)wParam == 40192 )
      {
        SelectedItem = Bindings_GetSelectedItem();
        if ( SelectedItem >= 0 )
        {
          BindingsModifyDlg_Open(selection: SelectedItem);
          return 0;
        }
        return 0;
      }
      if ( (unsigned __int16)wParam == 40193 )
      {
        v7 = Bindings_GetSelectedItem();
        if ( v7 >= 0 )
        {
          Bindings_ModifyEntry(i: v7, pMenuName: &str, pCommandString: &str);
          SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1015u, wParam: 0, lParam: 11);
          UpdateWindow(hWnd: g_bindings_hWndListView);
          Bindings_UpdateMenu();
          return 0;
        }
        return 0;
      }
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
  }
  if ( message != 5 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        Bindings_SaveConfig();
        Bindings_UpdateMenu();
        g_bindings_hWnd = nullptr;
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, wParam, lParam);
    }
    return 0;
  }
  right = (unsigned __int16)lParam;
  bottom = HIWORD(lParam);
  if ( (_WORD)lParam == 0 || bottom == 0 )
  {
    GetClientRect(hWnd: hwnd, lpRect: &Rect);
    right = Rect.right;
    bottom = Rect.bottom;
  }
  SetWindowPos(hWnd: g_bindings_hWndListView, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: right, cy: bottom, uFlags: 4u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: void Bindings_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_Open()
{
  unsigned int i; // esi
  char *name; // edx
  bind_t *v2; // esi
  tagLVITEMA lvi; // [esp+4h] [ebp-8Ch] BYREF
  LPARAM lParam[4]; // [esp+40h] [ebp-50h] BYREF
  tagLVCOLUMNA lvc; // [esp+50h] [ebp-40h] BYREF
  tagRECT clientRect; // [esp+7Ch] [ebp-14h] BYREF
  int itemCount; // [esp+8Ch] [ebp-4h]

  if ( g_bindings_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_bindings_hWnd) )
      ShowWindow(hWnd: g_bindings_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_bindings_hWnd);
  }
  else
  {
    g_bindings_hWnd = CreateWindowExA(
                        dwExStyle: 0x200u,
                        lpClassName: "BINDINGSCLASS",
                        lpWindowName: "Edit Bindings",
                        dwStyle: 0x80CF0000,
                        X: 0,
                        Y: 0,
                        nWidth: 600,
                        nHeight: 300,
                        hWndParent: g_hDlgMain,
                        hMenu: nullptr,
                        hInstance: g_hInstance,
                        lpParam: nullptr);
    GetClientRect(hWnd: g_bindings_hWnd, lpRect: &clientRect);
    g_bindings_hWndListView = CreateWindowExA(
                                dwExStyle: 0,
                                lpClassName: "SysListView32",
                                lpWindowName: &str,
                                dwStyle: 0x5000800Du,
                                X: 0,
                                Y: 0,
                                nWidth: clientRect.right - clientRect.left,
                                nHeight: clientRect.bottom - clientRect.top,
                                hWndParent: g_bindings_hWnd,
                                hMenu: (HMENU)0x64,
                                hInstance: g_hInstance,
                                lpParam: nullptr);
    itemCount = 0;
    for ( i = 0; i < 9; i += 3 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      name = (char *)g_bindings_labels[i / 3].name;
      lvc.cx = dword_4440D4[i];
      lvc.pszText = name;
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x101Bu, wParam: itemCount++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v2 = g_bindings;
    do
    {
      itemCount = SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
      memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
      lvi.mask = 13;
      lvi.iItem = itemCount;
      memset(&lvi.iSubItem, 0, 12);
      lvi.pszText = (char *)-1;
      lvi.lParam = (int)v2;
      SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
      ++v2;
    }
    while ( (int)v2 < (int)g_bindings_labels );
    lvc.mask = 2;
    lParam[3] = 2;
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x102Bu, wParam: 0, (LPARAM)lParam);
    SetFocus(hWnd: g_bindings_hWndListView);
    if ( g_bindings_windowRect.right != 0 && g_bindings_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_bindings_hWnd,
        X: g_bindings_windowRect.left,
        Y: g_bindings_windowRect.top,
        nWidth: g_bindings_windowRect.right - g_bindings_windowRect.left,
        nHeight: g_bindings_windowRect.bottom - g_bindings_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_bindings_hWnd, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D70
// Name: bool Bindings_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall Bindings_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = Bindings_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)122;
  wndclass.hCursor = (HICON__ *)"BINDINGSCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  Bindings_LoadConfig();
  Bindings_UpdateMenu();
  return 1;
}
