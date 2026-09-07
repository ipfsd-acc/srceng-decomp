// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_firetrigger.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\eventproperties_firetrigger.h"

//------------------------------------------------------------------------------
// Address: 0x00440C30
// Name: public: virtual void CEventPropertiesFireTriggerDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFireTriggerDialog::SetTitle(CEventPropertiesFireTriggerDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_9, eventname: "FireTrigger", desc: "Scene Trigger");
}

//------------------------------------------------------------------------------
// Address: 0x00440C50
// Name: private: void CEventPropertiesFireTriggerDialog::PopulateTriggerList(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFireTriggerDialog::PopulateTriggerList(
        CEventPropertiesFireTriggerDialog *this,
        HWND__ *wnd)
{
  int v2; // esi
  char szName[256]; // [esp+Ch] [ebp-100h] BYREF

  v2 = 0;
  do
  {
    sprintf(string: szName, format: "%d", ++v2);
    SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)szName);
  }
  while ( v2 < 16 );
}

//------------------------------------------------------------------------------
// Address: 0x00440CA0
// Name: public: virtual void CEventPropertiesFireTriggerDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFireTriggerDialog::InitControlData(
        CEventPropertiesFireTriggerDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // edi

  CBaseEventPropertiesDialog::InitControlData(this, params);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
  CEventPropertiesFireTriggerDialog::PopulateTriggerList(this, wnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00440D00
// Name: public: virtual void CEventPropertiesFireTriggerDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFireTriggerDialog::InitDialog(CEventPropertiesFireTriggerDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_9, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_9);
  this->InitControlData(this, a2: &g_Params_9);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_9);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00440D70
// Name: public: virtual int CEventPropertiesFireTriggerDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesFireTriggerDialog::HandleMessage(
        CEventPropertiesFireTriggerDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesFireTriggerDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  LRESULT v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND DlgItem; // eax
  HWND__ *v19; // [esp-14h] [ebp-60h]
  unsigned int v20; // [esp-10h] [ebp-5Ch]
  unsigned int v21; // [esp-Ch] [ebp-58h]
  HWND v22; // [esp-8h] [ebp-54h]
  tagRECT rcOut; // [esp+Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+2Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v22 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v21 = wParam;
  v20 = uMsg;
  v19 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_9,
             a3: v19,
             a4: v20,
             a5: v21,
             a6: (int)v22,
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
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_9.m_pEvent);
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
      switch ( (unsigned __int16)wParam )
      {
        case 0x3FAu:
          v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
          g_Params_9.m_bResumeCondition = SendMessageA(hWnd: v17, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          break;
        case 0x401u:
          g_Params_9.m_bUsesTag = false;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_9);
          return 1;
        case 0x402u:
          g_Params_9.m_bUsesTag = true;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_9);
          return 1;
        default:
          break;
      }
      return 1;
    }
    switch ( (unsigned __int16)wParam )
    {
      case 0x3F9u:
        v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
        v14 = SendMessageA(hWnd: v13, Msg: 0xF0u, wParam: 0, lParam: 0);
        g_Params_9.m_bHasEndTime = v14 == 1;
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
          SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_9.m_szParameters);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_9.m_szName, cchMax: 256);
        if ( g_Params_9.m_szName[0] == 0 )
          V_snprintf(pDest: g_Params_9.m_szName, maxLen: 256, pFormat: "Firetrigger %s", g_Params_9.m_szParameters);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
        g_Params_9.m_flStartTime = atof(nptr: szTime);
        GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
        g_Params_9.m_flEndTime = atof(nptr: szTime);
        CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_9);
        EndDialog(hDlg: v6, nResult: 1);
        return 1;
      case 2u:
        EndDialog(hDlg: v6, nResult: 0);
        return 1;
      default:
        if ( (unsigned __int16)wParam == 1007 && lParam != nullptr )
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_9.m_szParameters);
          return 1;
        }
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004410A0
// Name: EventPropertiesFireTriggerDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesFireTriggerDialogProc(
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  return CEventPropertiesFireTriggerDialog::HandleMessage(
           this: &g_EventPropertiesFireTriggerDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x004410B0
// Name: int EventProperties_FireTrigger(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_FireTrigger(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_9 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x80,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesFireTriggerDialogProc,
             dwInitParam: 0);
  *params = g_Params_9;
  return result;
}
