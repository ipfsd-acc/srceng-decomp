// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/bindings.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: void Bindings_ModifyEntry(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_ModifyEntry(int i, const char *pMenuName, const char *pCommandString)
{
  char *v3; // eax
  char *v4; // eax

  v3 = g_bindings[i].pMenuName;
  if ( v3 != nullptr && *v3 != 0 )
    Sys_Free(ptr: g_bindings[i].pMenuName);
  g_bindings[i].pMenuName = Sys_CopyString(str: pMenuName);
  v4 = g_bindings[i].pCommandString;
  if ( v4 != nullptr && *v4 != 0 )
    Sys_Free(ptr: g_bindings[i].pCommandString);
  g_bindings[i].pCommandString = Sys_CopyString(str: pCommandString);
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: int Bindings_GetSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
WPARAM __cdecl Bindings_GetSelectedItem()
{
  WPARAM v0; // esi

  v0 = 0;
  while ( SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x102Cu, wParam: v0, lParam: 2) != 2 )
  {
    if ( (int)++v0 >= 50 )
      return -1;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: bool Bindings_TranslateKey(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Bindings_TranslateKey(int vkKeyCode)
{
  int v1; // edx
  bind_t *v2; // eax
  char *pCommandString; // ecx

  v1 = 0;
  v2 = g_bindings;
  while ( 1 )
  {
    pCommandString = v2->pCommandString;
    if ( pCommandString != nullptr && *pCommandString != 0 && v2->keyCode != 0 && vkKeyCode == v2->keyCode )
      break;
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)g_bindings_labels )
      return 0;
  }
  ProcessCommand(strCmdIn: g_bindings[v1].pCommandString);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004013A0
// Name: bool Bindings_MenuSelection(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Bindings_MenuSelection(int wID)
{
  if ( (unsigned int)(wID - 50002) > 0x31 )
    return 0;
  ProcessCommand(strCmdIn: g_bindings[wID - 50002].pCommandString);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004013D0
// Name: void Bindings_UpdateMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_UpdateMenu()
{
  HMENU PopupMenu; // eax
  int v1; // edi
  HMENU__ *v2; // ebx
  char **p_pCommandString; // esi
  int v4; // eax
  HMENU__ *v5; // esi
  const char *v6; // [esp-10h] [ebp-ACh]
  char menuBuff[64]; // [esp+4h] [ebp-98h] BYREF
  char keyBuff[32]; // [esp+44h] [ebp-58h] BYREF
  tagMENUITEMINFOA menuItemInfo; // [esp+64h] [ebp-38h] BYREF
  HMENU__ *hMenu; // [esp+94h] [ebp-8h]
  int numAdded; // [esp+98h] [ebp-4h]

  hMenu = GetMenu(hWnd: g_hDlgMain);
  if ( hMenu != nullptr )
  {
    memset(dst: (unsigned __int8 *)&menuItemInfo, value: 0, count: sizeof(menuItemInfo));
    menuItemInfo.cbSize = 48;
    numAdded = 0;
    PopupMenu = CreatePopupMenu();
    menuItemInfo.fType = 0;
    v1 = 49;
    v2 = PopupMenu;
    menuItemInfo.fMask = 322;
    p_pCommandString = &g_bindings[49].pCommandString;
    do
    {
      if ( *p_pCommandString != nullptr && **p_pCommandString != 0 )
      {
        v6 = *(p_pCommandString - 1);
        menuItemInfo.wID = v1 + 50002;
        V_strncpy(pDest: menuBuff, pSrc: v6, maxLen: 64);
        v4 = (int)*(p_pCommandString - 3);
        if ( v4 != 0 )
        {
          sprintf(string: keyBuff, format: "\tF%d", v4 - 111);
          V_strncat(pDest: menuBuff, pSrc: keyBuff, destBufferSize: 0x40u, max_chars_to_copy: -1);
        }
        menuItemInfo.dwTypeData = menuBuff;
        InsertMenuItemA(hmenu: v2, item: 0, fByPosition: true, lpmi: &menuItemInfo);
        ++numAdded;
      }
      p_pCommandString -= 4;
      --v1;
    }
    while ( (int)p_pCommandString >= (int)&g_bindings[0].pCommandString );
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
    v5 = hMenu;
    menuItemInfo.fMask = 4;
    GetMenuItemInfoA(hmenu: hMenu, item: 0xC350u, fByPosition: false, lpmii: &menuItemInfo);
    if ( menuItemInfo.hSubMenu != nullptr )
      DestroyMenu(hMenu: menuItemInfo.hSubMenu);
    else
      AppendMenuA(hMenu: v5, uFlags: 0, uIDNewItem: 0xC350u, lpNewItem: "Bindings");
    menuItemInfo.fMask = 4;
    menuItemInfo.hSubMenu = v2;
    SetMenuItemInfoA(hmenu: v5, item: 0xC350u, fByPositon: false, lpmii: &menuItemInfo);
    DrawMenuBar(hWnd: g_hDlgMain);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401570
// Name: int BindingsModifyDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall BindingsModifyDlg_Proc(HWND__ *hWnd, unsigned int message, INT_PTR wParam, int lParam)
{
  HWND DlgItem; // eax

  if ( message == 272 )
  {
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1052, lpString: g_bindingsModify_keyCode);
    if ( g_bindingsModify_keyCode[0] == 0 )
    {
      DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1101);
      EnableWindow(hWnd: DlgItem, bEnable: false);
    }
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
        GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1050, lpString: g_bindingsModify_menuName, cchMax: 512);
        GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1051, lpString: g_bindingsModify_command, cchMax: 512);
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
// Address: 0x00401640
// Name: void BindingsModifyDlg_Open(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BindingsModifyDlg_Open(int selection)
{
  if ( selection >= 0 )
  {
    if ( selection + 1 > 12 )
      g_bindingsModify_keyCode[0] = 0;
    else
      sprintf(string: g_bindingsModify_keyCode, format: "F%d", selection + 1);
    V_strncpy(pDest: g_bindingsModify_menuName, pSrc: g_bindings[selection].pMenuName, maxLen: 512);
    V_strncpy(pDest: g_bindingsModify_command, pSrc: g_bindings[selection].pCommandString, maxLen: 512);
    if ( (unsigned __int16)DialogBoxParamA(
                             hInstance: g_hInstance,
                             lpTemplateName: (LPCSTR)0x7B,
                             hWndParent: g_hDlgMain,
                             lpDialogFunc: (DLGPROC)BindingsModifyDlg_Proc,
                             dwInitParam: 0) == 1019 )
    {
      if ( g_bindingsModify_menuName[0] == 0 )
        V_strncpy(pDest: g_bindingsModify_menuName, pSrc: g_bindingsModify_command, maxLen: 512);
      Bindings_ModifyEntry(i: selection, pMenuName: g_bindingsModify_menuName, pCommandString: g_bindingsModify_command);
      SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1015u, wParam: 0, lParam: 49);
      UpdateWindow(hWnd: g_bindings_hWndListView);
      Bindings_UpdateMenu();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: void Bindings_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_LoadConfig()
{
  int v0; // edi
  void **p_pCommandString; // esi
  const char *Token; // eax
  const char *v3; // eax
  const char *v4; // eax
  _BYTE *v5; // eax
  char buff[512]; // [esp+Ch] [ebp-824h] BYREF
  char valueBuff[512]; // [esp+20Ch] [ebp-624h] BYREF
  char commandString[512]; // [esp+40Ch] [ebp-424h] BYREF
  char menuName[512]; // [esp+60Ch] [ebp-224h] BYREF
  char keyBuff[32]; // [esp+80Ch] [ebp-24h] BYREF
  char *ptr; // [esp+82Ch] [ebp-4h] BYREF

  v0 = 0;
  p_pCommandString = (void **)&g_bindings[0].pCommandString;
  do
  {
    menuName[0] = 0;
    commandString[0] = 0;
    sprintf(string: keyBuff, format: "bind%d", v0);
    Sys_GetRegistryString(keyName: keyBuff, value: valueBuff, defValue: &defValue, valueLen: 512);
    ptr = valueBuff;
    Token = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *Token != 0 )
      atoi(nptr: Token);
    v3 = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *v3 != 0 )
      V_strncpy(pDest: menuName, pSrc: v3, maxLen: 512);
    v4 = Sys_GetToken(dataptr: &ptr, allowLineBreaks: 0, numlines: nullptr);
    if ( *v4 != 0 )
      V_strncpy(pDest: commandString, pSrc: v4, maxLen: 512);
    v5 = *(p_pCommandString - 1);
    if ( v5 != nullptr && *v5 != 0 )
      Sys_Free(ptr: *(p_pCommandString - 1));
    *(p_pCommandString - 1) = Sys_CopyString(str: menuName);
    if ( *p_pCommandString != nullptr && *(_BYTE *)*p_pCommandString != 0 )
      Sys_Free(ptr: *p_pCommandString);
    *p_pCommandString = Sys_CopyString(str: commandString);
    p_pCommandString += 4;
    ++v0;
  }
  while ( (int)p_pCommandString < (int)&off_46533C );
  Sys_GetRegistryString(keyName: "bindingsWindowRect", value: buff, defValue: &defValue, valueLen: 512);
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
// Address: 0x004018B0
// Name: void Bindings_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Bindings_SaveConfig()
{
  int v0; // edi
  char **p_pCommandString; // esi
  const char *v2; // eax
  const char *v3; // ecx
  char valueBuff[1536]; // [esp+8h] [ebp-84Ch] BYREF
  char buff[512]; // [esp+608h] [ebp-24Ch] BYREF
  char keyBuff[32]; // [esp+808h] [ebp-4Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+828h] [ebp-2Ch] BYREF

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
  p_pCommandString = &g_bindings[0].pCommandString;
  do
  {
    sprintf(string: keyBuff, format: "bind%d", v0);
    v2 = *(p_pCommandString - 1);
    if ( v2 == nullptr )
      v2 = &defValue;
    v3 = *p_pCommandString;
    if ( *p_pCommandString == nullptr )
      v3 = &defValue;
    if ( _snprintf(string: valueBuff, count: 0x600u, format: "%d \"%s\" \"%s\"", *(p_pCommandString - 3), v2, v3) == -1 )
      valueBuff[0] = 0;
    Sys_SetRegistryString(keyName: keyBuff, value: valueBuff);
    p_pCommandString += 4;
    ++v0;
  }
  while ( (int)p_pCommandString < (int)&off_46533C );
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
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
  const char *v13; // ecx
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
        v13 = (const char *)v11[1];
        if ( v13 == nullptr )
          v13 = &defValue;
        *(_DWORD *)(lParam + 32) = v13;
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
          Bindings_ModifyEntry(i: v7, pMenuName: &defValue, pCommandString: &defValue);
          SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1015u, wParam: 0, lParam: 49);
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
// Address: 0x00401B80
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
                                lpWindowName: &defValue,
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
      lvc.cx = dword_465334[i];
      lvc.pszText = name;
      lvc.mask = 15;
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x101Bu, wParam: itemCount++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_bindings_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
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
// Address: 0x00401DE0
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
