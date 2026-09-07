// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_interrupt.cpp
// Functions: 5
// ============================================================

#include "utils\hlfaceposer\eventproperties_interrupt.h"

//------------------------------------------------------------------------------
// Address: 0x004422E0
// Name: public: virtual void CEventPropertiesInterruptDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesInterruptDialog::SetTitle(CEventPropertiesInterruptDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_13, eventname: "Interrupt", desc: "Interrupt");
}

//------------------------------------------------------------------------------
// Address: 0x00442350
// Name: public: virtual void CEventPropertiesInterruptDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesInterruptDialog::InitDialog(CEventPropertiesInterruptDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_13, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_13);
  this->InitControlData(this, a2: &g_Params_13);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_13);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x004423C0
// Name: public: virtual int CEventPropertiesInterruptDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesInterruptDialog::HandleMessage(
        CEventPropertiesInterruptDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesInterruptDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  LRESULT v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND DlgItem; // eax
  HWND__ *v18; // [esp-14h] [ebp-60h]
  unsigned int v19; // [esp-10h] [ebp-5Ch]
  unsigned int v20; // [esp-Ch] [ebp-58h]
  HWND v21; // [esp-8h] [ebp-54h]
  tagRECT rcOut; // [esp+Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+2Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v21 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v20 = wParam;
  v19 = uMsg;
  v18 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_13,
             a3: v18,
             a4: v19,
             a5: v20,
             a6: (int)v21,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) != 0 )
    return result;
  if ( v5 > 0x111 )
  {
    if ( v5 == 277 )
    {
      DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
      CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: DlgItem, rcOut: (tagRECT *)&szTime[16]);
      InvalidateRect(hWnd: v6, lpRect: (const RECT *)&szTime[16], bErase: true);
      UpdateWindow(hWnd: v6);
    }
    return 0;
  }
  if ( v5 != 273 )
  {
    if ( v5 == 15 )
    {
      v10 = BeginPaint(hWnd: v6, lpPaint: (LPPAINTSTRUCT)&rcOut);
      v11 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
      CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_13.m_pEvent);
      EndPaint(hWnd: v6, lpPaint: (const PAINTSTRUCT *)&rcOut);
      return 0;
    }
    if ( v5 == 272 )
    {
      this->InitDialog(this, a2: v6);
      return 0;
    }
    return 0;
  }
  if ( (unsigned __int16)wParam > 0x3F9u )
  {
    if ( (unsigned __int16)wParam == 1025 )
    {
      g_Params_13.m_bUsesTag = false;
    }
    else
    {
      if ( (unsigned __int16)wParam != 1026 )
        return 1;
      g_Params_13.m_bUsesTag = true;
    }
    CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_13);
    return 1;
  }
  switch ( (unsigned __int16)wParam )
  {
    case 0x3F9u:
      v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v14 = SendMessageA(hWnd: v13, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_13.m_bHasEndTime = v14 == 1;
      if ( v14 == 1 )
      {
        v16 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v16, nCmdShow: 9);
      }
      else
      {
        v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v15, nCmdShow: 0);
      }
      return 1;
    case 1u:
      v12 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
      if ( v12 != nullptr )
        SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_13.m_szParameters);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_13.m_szName, cchMax: 256);
      if ( g_Params_13.m_szName[0] == 0 )
        V_strncpy(pDest: g_Params_13.m_szName, pSrc: "Interrupt", maxLen: 256);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
      g_Params_13.m_flStartTime = atof(nptr: szTime);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
      g_Params_13.m_flEndTime = atof(nptr: szTime);
      CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_13);
      EndDialog(hDlg: v6, nResult: 1);
      return 1;
    case 2u:
      EndDialog(hDlg: v6, nResult: 0);
      return 1;
    default:
      if ( (unsigned __int16)wParam == 1007 && lParam != nullptr )
      {
        SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_13.m_szParameters);
        return 1;
      }
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442690
// Name: EventPropertiesInterruptDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesInterruptDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesInterruptDialog::HandleMessage(
           this: &g_EventPropertiesInterruptDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x004426A0
// Name: int EventProperties_Interrupt(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Interrupt(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_13 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x83,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesInterruptDialogProc,
             dwInitParam: 0);
  *params = g_Params_13;
  return result;
}
