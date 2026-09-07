// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/cclookup.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00422940
// Name: PopulateCloseCaptionTokenList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateCloseCaptionTokenList(HWND wnd@<eax>, int a2@<ebx>, CCloseCaptionLookupParams *params)
{
  HWND DlgItem; // esi
  int v4; // ebx
  wchar_t label[256]; // [esp+8h] [ebp-284h] BYREF
  tagLVITEMA _macro_lvi; // [esp+208h] [ebp-84h] BYREF
  tagLVITEMW lvItem; // [esp+244h] [ebp-48h] BYREF
  char *s2; // [esp+280h] [ebp-Ch]
  int saveSelected; // [esp+284h] [ebp-8h]
  const char *name; // [esp+288h] [ebp-4h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1066);
  if ( DlgItem != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem.stateMask, value: 0, count: 0x2Cu);
    lvItem.cColumns = 0;
    lvItem.iIndent = 0;
    lvItem.stateMask = 46;
    lvItem.iImage = (int)"CloseCaption Token";
    lvItem.lParam = 256;
    lvItem.cchTextMax = 200;
    SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 0, lParam: (LPARAM)&lvItem.stateMask);
    memset(dst: (unsigned __int8 *)&lvItem.stateMask, value: 0, count: 0x2Cu);
    lvItem.stateMask = 46;
    lvItem.cColumns = 1;
    lvItem.iImage = (int)"Text";
    lvItem.lParam = 256;
    lvItem.iIndent = 1;
    lvItem.cchTextMax = 800;
    SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 1u, lParam: (LPARAM)&lvItem.stateMask);
    SendMessageA(hWnd: DlgItem, Msg: 0x1009u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: DlgItem, Msg: 0x30u, wParam: g_UnicodeFont, lParam: 1);
    v4 = g_pLocalize->GetFirstStringIndex(this: g_pLocalize);
    saveSelected = -1;
    if ( v4 != -1 )
    {
      s2 = params->m_szCCToken;
      do
      {
        name = (const char *)((int (__thiscall *)(ILocalize *, int, int))g_pLocalize->GetNameByIndex)(
                               a1: g_pLocalize,
                               a2: v4,
                               a3: a2);
        memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
        lvItem.iItem = SendMessageA(hWnd: DlgItem, Msg: 0x1004u, wParam: 0, lParam: 0);
        lvItem.mask = 5;
        lvItem.lParam = v4;
        g_pLocalize->ConvertANSIToUnicode(this: g_pLocalize, a2: name, a3: label, a4: 512);
        lvItem.pszText = label;
        lvItem.cchTextMax = 256;
        SendMessageA(hWnd: DlgItem, Msg: 0x104Du, wParam: 0, lParam: (LPARAM)&lvItem);
        lvItem.mask = 1;
        lvItem.iSubItem = 1;
        lvItem.pszText = g_pLocalize->GetValueByIndex(this: g_pLocalize, a2: v4);
        lvItem.cchTextMax = 1024;
        SendMessageA(hWnd: DlgItem, Msg: 0x104Cu, wParam: 0, lParam: (LPARAM)&lvItem);
        if ( _V_stricmp(s1: name, s2) == 0 )
        {
          _macro_lvi.stateMask = 61440;
          _macro_lvi.state = 2;
          SendMessageA(hWnd: DlgItem, Msg: 0x102Bu, wParam: lvItem.iItem, lParam: (LPARAM)&_macro_lvi);
          saveSelected = lvItem.iItem;
        }
        a2 = v4;
        v4 = ((int (__thiscall *)(ILocalize *))g_pLocalize->GetNextStringIndex)(a1: g_pLocalize);
      }
      while ( v4 != -1 );
      if ( saveSelected != -1 )
        SendMessageA(hWnd: DlgItem, Msg: 0x1013u, wParam: saveSelected, lParam: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422B50
// Name: CloseCaptionLookupDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall CloseCaptionLookupDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, int lParam)
{
  HWND v5; // eax
  HWND v6; // edi
  LONG WindowLongA; // eax
  HWND v8; // eax
  int v9; // eax
  HWND DlgItem; // eax
  int v11; // esi
  HWND v12; // edi
  const char *v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  tagLVITEMA lvi; // [esp+Ch] [ebp-3Ch] BYREF

  switch ( uMsg )
  {
    case 0x4Eu:
      if ( wParam == 1066 )
      {
        v9 = *(_DWORD *)(lParam + 8);
        if ( v9 == -101 )
        {
          DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1066);
          v11 = *(_DWORD *)(lParam + 12);
          v12 = DlgItem;
          if ( v11 >= 0 )
          {
            memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
            lvi.iItem = v11;
            lvi.mask = 4;
            if ( SendMessageA(hWnd: v12, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvi) != 0 )
            {
              v13 = g_pLocalize->GetNameByIndex(this: g_pLocalize, a2: lvi.lParam);
              if ( v13 != nullptr )
              {
                V_strncpy(pDest: g_Params_1.m_szCCToken, pSrc: v13, maxLen: 1024);
                v14 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1065);
                SendMessageA(hWnd: v14, Msg: 0xCu, wParam: 0x400u, lParam: (LPARAM)g_Params_1.m_szCCToken);
              }
            }
          }
          return 0;
        }
        if ( v9 == -3 )
        {
          v15 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1065);
          SendMessageA(hWnd: v15, Msg: 0xDu, wParam: 0x400u, lParam: (LPARAM)g_Params_1.m_szCCToken);
          EndDialog(hDlg: hwndDlg, nResult: 1);
          return 0;
        }
      }
      return 1;
    case 0x110u:
      CBaseDialogParams::PositionSelf(this: &g_Params_1, self: hwndDlg);
      v6 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1066);
      WindowLongA = GetWindowLongA(hWnd: v6, nIndex: -20);
      SetWindowLongA(hWnd: v6, nIndex: -20, dwNewLong: WindowLongA | 0x20);
      PopulateCloseCaptionTokenList(wnd: hwndDlg, a2: (int)GetDlgItem, params: &g_Params_1);
      SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_1.m_szDialogTitle);
      SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1065, lpString: g_Params_1.m_szCCToken);
      v8 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1066);
      SetFocus(hWnd: v8);
      break;
    case 0x111u:
      if ( (unsigned __int16)wParam == 1 )
      {
        v5 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1065);
        SendMessageA(hWnd: v5, Msg: 0xDu, wParam: 0x400u, lParam: (LPARAM)g_Params_1.m_szCCToken);
        EndDialog(hDlg: hwndDlg, nResult: 1);
      }
      else if ( (unsigned __int16)wParam == 2 )
      {
        EndDialog(hDlg: hwndDlg, nResult: 0);
        return 1;
      }
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422D40
// Name: int CloseCaptionLookup(struct CCloseCaptionLookupParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl CloseCaptionLookup(CCloseCaptionLookupParams *params)
{
  HMODULE ModuleHandleA; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]
  INT_PTR retval; // [esp+14h] [ebp+8h]

  g_Params_1 = *params;
  g_UnicodeFont = (WPARAM)CreateFontA(
                            cHeight: -10,
                            cWidth: 0,
                            cEscapement: 0,
                            cOrientation: 0,
                            cWeight: 400,
                            bItalic: 0,
                            bUnderline: 0,
                            bStrikeOut: 0,
                            iCharSet: 0,
                            iOutPrecision: 4u,
                            iClipPrecision: 0,
                            iQuality: 4u,
                            iPitchAndFamily: 0,
                            pszFaceName: "Tahoma");
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  retval = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x78,
             hWndParent: Handle,
             lpDialogFunc: CloseCaptionLookupDialogProc,
             dwInitParam: 0);
  DeleteObject(ho: (HGDIOBJ)g_UnicodeFont);
  *params = g_Params_1;
  g_UnicodeFont = 0;
  return retval;
}
