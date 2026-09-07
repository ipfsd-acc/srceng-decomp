// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_face.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\eventproperties_face.h"

//------------------------------------------------------------------------------
// Address: 0x00440740
// Name: public: virtual void CEventPropertiesFaceDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFaceDialog::SetTitle(CEventPropertiesFaceDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_8, eventname: "Face", desc: "Face Actor");
}

//------------------------------------------------------------------------------
// Address: 0x00440760
// Name: public: virtual void CEventPropertiesFaceDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFaceDialog::InitControlData(CEventPropertiesFaceDialog *this, CEventParams *params)
{
  HWND DlgItem; // ebx
  HWND v4; // eax

  CBaseEventPropertiesDialog::InitControlData(this, params);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
  CBaseEventPropertiesDialog::PopulateNamedActorList(this, wnd: DlgItem, params);
  v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1019);
  SendMessageA(hWnd: v4, Msg: 0xF1u, wParam: params->m_bLockBodyFacing, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004407E0
// Name: public: virtual void CEventPropertiesFaceDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFaceDialog::InitDialog(CEventPropertiesFaceDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_8, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_8);
  this->InitControlData(this, a2: &g_Params_8);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_8);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00440850
// Name: public: virtual int CEventPropertiesFaceDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesFaceDialog::HandleMessage(
        CEventPropertiesFaceDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesFaceDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  LRESULT v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND DlgItem; // eax
  HWND__ *v20; // [esp-14h] [ebp-60h]
  unsigned int v21; // [esp-10h] [ebp-5Ch]
  unsigned int v22; // [esp-Ch] [ebp-58h]
  HWND v23; // [esp-8h] [ebp-54h]
  tagRECT rcOut; // [esp+Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+2Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v23 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v22 = wParam;
  v21 = uMsg;
  v20 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_8,
             a3: v20,
             a4: v21,
             a5: v22,
             a6: (int)v23,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) == 0 )
  {
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
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_8.m_pEvent);
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
      switch ( (__int16)wParam )
      {
        case 1018:
          v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
          g_Params_8.m_bResumeCondition = SendMessageA(hWnd: v17, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          return 1;
        case 1019:
          v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1019);
          g_Params_8.m_bLockBodyFacing = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          return 1;
        case 1025:
          g_Params_8.m_bUsesTag = false;
          goto LABEL_30;
        case 1026:
          g_Params_8.m_bUsesTag = true;
LABEL_30:
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_8);
          break;
        default:
          return 1;
      }
      return 1;
    }
    switch ( (unsigned __int16)wParam )
    {
      case 0x3F9u:
        v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
        v14 = SendMessageA(hWnd: v13, Msg: 0xF0u, wParam: 0, lParam: 0);
        g_Params_8.m_bHasEndTime = v14 == 1;
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
          SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_8.m_szParameters);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_8.m_szName, cchMax: 256);
        if ( g_Params_8.m_szName[0] == 0 )
          V_snprintf(pDest: g_Params_8.m_szName, maxLen: 256, pFormat: "Face %s", g_Params_8.m_szParameters);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
        g_Params_8.m_flStartTime = atof(nptr: szTime);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
        g_Params_8.m_flEndTime = atof(nptr: szTime);
        CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_8);
        EndDialog(hDlg: v6, nResult: 1);
        return 1;
      case 2u:
        EndDialog(hDlg: v6, nResult: 0);
        return 1;
      default:
        if ( (unsigned __int16)wParam == 1007 && lParam != nullptr )
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_8.m_szParameters);
          return 1;
        }
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00440BD0
// Name: EventPropertiesFaceDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesFaceDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesFaceDialog::HandleMessage(this: &g_EventPropertiesFaceDialog, hwndDlg, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00440BE0
// Name: int EventProperties_Face(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Face(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_8 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7F,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesFaceDialogProc,
             dwInitParam: 0);
  *params = g_Params_8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004411B0
// Name: public: virtual void CEventPropertiesFaceDialog::ShowControlsForEventType(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFaceDialog::ShowControlsForEventType(
        CEventPropertiesCameraDialog *this,
        CEventParams *params)
{
  CBaseEventPropertiesDialog::ShowControlsForEventType(this, params);
}
