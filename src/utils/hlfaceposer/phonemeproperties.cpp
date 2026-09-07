// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/phonemeproperties.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00476D60
// Name: PhonemeBtnProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall PhonemeBtnProc(HWND__ *hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  HWND Parent; // eax
  HWND DlgItem; // esi
  LONG WindowLongA; // eax

  if ( uMsg != 512 )
    return CallWindowProcA(lpPrevWndFunc: lpfnOldButtonProc, hWnd: hwnd, Msg: uMsg, wParam, lParam);
  Parent = GetParent(hWnd: hwnd);
  if ( Parent != nullptr )
  {
    DlgItem = GetDlgItem(hDlg: Parent, nIDDlgItem: 1030);
    if ( DlgItem != nullptr )
    {
      WindowLongA = GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA != 0 )
        SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: WindowLongA + 36);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00476DE0
// Name: ClickedPhoneme
// Source: json
//------------------------------------------------------------------------------
void __usercall ClickedPhoneme(HWND hwndDlg@<eax>, int phoneme@<ecx>)
{
  HWND DlgItem; // eax
  HWND v4; // ebx
  const char *WindowLongA; // eax

  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1028);
  v4 = DlgItem;
  if ( DlgItem != nullptr )
  {
    if ( g_Params_24.m_bMultiplePhoneme )
      SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_24.m_szName);
    else
      g_Params_24.m_szName[0] = 0;
    if ( phoneme < g_nPhonemeCount && phoneme >= 0 )
    {
      WindowLongA = (const char *)GetWindowLongA(hWnd: g_rgButtons[phoneme], nIndex: -21);
      if ( WindowLongA != nullptr )
      {
        if ( strlen(g_Params_24.m_szName) != 0 )
          strcat(g_Params_24.m_szName, " ");
        strcat(g_Params_24.m_szName, WindowLongA);
        if ( g_Params_24.m_bMultiplePhoneme )
        {
          SetFocus(hWnd: v4);
          SendMessageA(hWnd: v4, Msg: 0xCu, wParam: 0, lParam: (LPARAM)g_Params_24.m_szName);
          SendMessageA(hWnd: v4, Msg: 0xB1u, wParam: 0, lParam: -65536);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476EE0
// Name: CreateAndLayoutControls
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAndLayoutControls(CPhonemeParams *params@<eax>, HWND__ *hwndDlg)
{
  CExpClass *v3; // eax
  int NumExpressions; // eax
  int v5; // edi
  int m_nTop; // ecx
  int m_nLeft; // edx
  HWND v8; // ebx
  void (__stdcall *v9)(HWND, int, int, int, int, BOOL); // esi
  int SystemMetrics; // eax
  HWND DlgItem; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  int v16; // esi
  int v17; // edi
  CExpression *Expression; // ebx
  const char *v19; // eax
  HWND Window; // esi
  HGDIOBJ StockObject; // eax
  int v22; // [esp-18h] [ebp-28h]
  HMODULE ModuleHandleA; // [esp-10h] [ebp-20h]
  CExpClass *v24; // [esp+4h] [ebp-Ch]
  int Y; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  g_nPhonemeCount = 0;
  FacePoser_EnsurePhonemesLoaded();
  v3 = expressions->FindClass(this: expressions, a2: "phonemes", a3: 1);
  v24 = v3;
  if ( v3 != nullptr )
  {
    NumExpressions = CExpClass::GetNumExpressions(this: v3);
    g_nPhonemeCount = NumExpressions;
    if ( NumExpressions != 0 )
    {
      g_rgButtons = (HWND__ **)operator new(nSize: 4 * NumExpressions);
      v5 = 23 * (g_nPhonemeCount / 7) + 148;
      if ( params->m_bPositionDialog )
      {
        m_nTop = params->m_nTop;
        m_nLeft = params->m_nLeft;
        v8 = hwndDlg;
        v9 = (void (__stdcall *)(HWND, int, int, int, int, BOOL))MoveWindow;
        MoveWindow(hWnd: hwndDlg, X: m_nLeft, Y: m_nTop - v5 - 5, nWidth: 440, nHeight: v5, bRepaint: true);
      }
      else
      {
        v22 = (GetSystemMetrics(nIndex: 17) - v5) / 2;
        SystemMetrics = GetSystemMetrics(nIndex: 16);
        v9 = (void (__stdcall *)(HWND, int, int, int, int, BOOL))MoveWindow;
        MoveWindow(hWnd: hwndDlg, X: (SystemMetrics - 440) / 2, Y: v22, nWidth: 440, nHeight: v5, bRepaint: true);
        v8 = hwndDlg;
      }
      DlgItem = GetDlgItem(hDlg: v8, nIDDlgItem: 1);
      if ( DlgItem != nullptr )
        v9(hWnd: DlgItem, X: 220, Y: v5 - 58, nWidth: 100, nHeight: 20, bRepaint: true);
      v12 = GetDlgItem(hDlg: v8, nIDDlgItem: 2);
      if ( v12 != nullptr )
        v9(hWnd: v12, X: 330, Y: v5 - 58, nWidth: 100, nHeight: 20, bRepaint: true);
      v13 = GetDlgItem(hDlg: v8, nIDDlgItem: 1029);
      if ( v13 != nullptr )
        v9(hWnd: v13, X: 10, Y: v5 - 55, nWidth: 50, nHeight: 20, bRepaint: true);
      v14 = GetDlgItem(hDlg: v8, nIDDlgItem: 1028);
      if ( v14 != nullptr )
        v9(hWnd: v14, X: 60, Y: v5 - 58, nWidth: 100, nHeight: 20, bRepaint: true);
      v15 = GetDlgItem(hDlg: v8, nIDDlgItem: 1030);
      if ( v15 != nullptr )
        v9(hWnd: v15, X: 10, Y: v5 - 85, nWidth: 410, nHeight: 20, bRepaint: true);
      v16 = 0;
      v17 = 0;
      i = 0;
      if ( g_nPhonemeCount > 0 )
      {
        Y = 40;
        do
        {
          Expression = CExpClass::GetExpression(this: v24, num: v16);
          if ( Expression != nullptr )
          {
            ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
            v19 = va(fmt: "%s", Expression->name);
            Window = CreateWindowExA(
                       dwExStyle: 0,
                       lpClassName: "BUTTON",
                       lpWindowName: v19,
                       dwStyle: 0x50000100u,
                       X: 60 * v17 + 10,
                       Y,
                       nWidth: 50,
                       nHeight: 18,
                       hWndParent: hwndDlg,
                       hMenu: (HMENU)(v16 + 2000),
                       hInstance: ModuleHandleA,
                       lpParam: nullptr);
            SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)Expression);
            lpfnOldButtonProc = (WNDPROC)SetWindowLongA(hWnd: Window, nIndex: -4, dwNewLong: (LONG)PhonemeBtnProc);
            StockObject = GetStockObject(i: 12);
            SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
            ++v17;
            g_rgButtons[i] = Window;
            v16 = i;
            if ( v17 >= 7 )
            {
              Y += 23;
              v17 = 0;
            }
          }
          i = ++v16;
        }
        while ( v16 < g_nPhonemeCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477150
// Name: DestroyControls
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyControls()
{
  HWND__ **v0; // ecx
  int i; // esi

  v0 = g_rgButtons;
  for ( i = 0; i < g_nPhonemeCount; ++i )
  {
    if ( v0[i] != nullptr )
    {
      DestroyWindow(hWnd: v0[i]);
      v0 = g_rgButtons;
      g_rgButtons[i] = nullptr;
    }
  }
  free(pMem: v0);
  g_nPhonemeCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004771A0
// Name: ValidatePhonemeString
// Source: json
//------------------------------------------------------------------------------
char __usercall ValidatePhonemeString@<al>(const char *input@<eax>, bool allowmultiple, char *output)
{
  CExpClass *v4; // edi
  const char *v5; // ebx
  char v6; // al
  char *i; // ecx
  int v8; // esi
  CExpression *Expression; // eax
  char phoneme[128]; // [esp+8h] [ebp-88h] BYREF
  CExpClass *v12; // [esp+88h] [ebp-8h]
  int count; // [esp+8Ch] [ebp-4h]

  FacePoser_EnsurePhonemesLoaded();
  v4 = expressions->FindClass(this: expressions, a2: "phonemes", a3: 1);
  v12 = v4;
  if ( v4 == nullptr || input == nullptr || *input == 0 )
    return 0;
  count = 1;
  *output = 0;
  v5 = input;
  do
  {
    v6 = *v5;
    for ( i = phoneme; *v5 > 32; ++i )
    {
      ++v5;
      *i = v6;
      v6 = *v5;
    }
    v8 = 0;
    *i = 0;
    if ( g_nPhonemeCount > 0 )
    {
      while ( 1 )
      {
        Expression = CExpClass::GetExpression(this: v4, num: v8);
        if ( Expression != nullptr && _V_stricmp(s1: Expression->name, s2: phoneme) == 0 )
          break;
        if ( ++v8 >= g_nPhonemeCount )
          goto LABEL_15;
      }
      if ( count != 1 )
        strcat(output, " ");
      strcat(output, phoneme);
      v4 = v12;
    }
LABEL_15:
    if ( *v5 == 0 )
      break;
    ++count;
    ++v5;
  }
  while ( allowmultiple );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004772C0
// Name: PhonemePropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall PhonemePropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned __int16 wParam, int lParam)
{
  HWND v5; // esi
  HWND DlgItem; // eax
  HWND v7; // edi
  const char *v8; // eax
  HWND v9; // eax
  HWND v10; // esi
  char szPhoneme[256]; // [esp+4h] [ebp-100h] BYREF

  if ( uMsg != 272 )
  {
    if ( uMsg != 273 )
      return 0;
    if ( wParam < 0x7D0u || wParam >= g_nPhonemeCount + 2000 )
    {
      if ( wParam != 1028 )
      {
        if ( wParam != 1 )
        {
          if ( wParam == 2 )
          {
            DestroyControls();
            EndDialog(hDlg: hwndDlg, nResult: 0);
            return 1;
          }
          return 1;
        }
        v5 = hwndDlg;
        DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1028);
        if ( DlgItem != nullptr )
        {
          SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)szPhoneme);
          ValidatePhonemeString(
            input: szPhoneme,
            allowmultiple: g_Params_24.m_bMultiplePhoneme,
            output: g_Params_24.m_szName);
        }
        goto LABEL_14;
      }
    }
    else
    {
      v5 = hwndDlg;
      ClickedPhoneme(hwndDlg, phoneme: wParam - 2000);
      if ( !g_Params_24.m_bMultiplePhoneme )
      {
LABEL_14:
        DestroyControls();
        EndDialog(hDlg: v5, nResult: 1);
      }
    }
    return 1;
  }
  CBaseDialogParams::PositionSelf(this: &g_Params_24, self: hwndDlg);
  SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_24.m_szDialogTitle);
  CreateAndLayoutControls(params: &g_Params_24, hwndDlg);
  v7 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1024);
  if ( v7 != nullptr )
  {
    if ( g_Params_24.m_bMultiplePhoneme )
      v8 = "Click or enter one or more phonemes from list below";
    else
      v8 = va(fmt: "Phoneme/Viseme:  %s", g_Params_24.m_szName);
    SendMessageA(hWnd: v7, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v8);
  }
  v9 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1028);
  v10 = v9;
  if ( v9 == nullptr )
    return 1;
  SetFocus(hWnd: v9);
  SendMessageA(hWnd: v10, Msg: 0xCu, wParam: 0, lParam: (LPARAM)g_Params_24.m_szName);
  SendMessageA(hWnd: v10, Msg: 0xB1u, wParam: 0, lParam: -65536);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00477460
// Name: int PhonemeProperties(struct CPhonemeParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl PhonemeProperties(CPhonemeParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_24 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x6B,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)PhonemePropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_24;
  return result;
}
