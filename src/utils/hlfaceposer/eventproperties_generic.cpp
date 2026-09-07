// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_generic.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\eventproperties_generic.h"

//------------------------------------------------------------------------------
// Address: 0x004414F0
// Name: public: virtual void CEventPropertiesGenericDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGenericDialog::SetTitle(CEventPropertiesGenericDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(
    this,
    params: &g_Params_11,
    eventname: "Generic",
    desc: "Generic AI Event (text)");
}

//------------------------------------------------------------------------------
// Address: 0x00441510
// Name: public: virtual void CEventPropertiesGenericDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGenericDialog::InitDialog(CEventPropertiesGenericDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_11, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_11);
  this->InitControlData(this, a2: &g_Params_11);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_11);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00441580
// Name: private: void CEventPropertiesGenericDialog::PopulateAIGeneric(struct HWND__ __near *,class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGenericDialog::PopulateAIGeneric(
        CEventPropertiesGenericDialog *this,
        HWND__ *control,
        CEventParams *params)
{
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_BLINK");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_HOLSTER");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_UNHOLSTER");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_AIM");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_RANDOMLOOK");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_RANDOMFACEFLEX");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_RANDOMHEADFLEX");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_IGNORECOLLISION");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"AI_DISABLEAI");
  SendMessageA(hWnd: control, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
}

//------------------------------------------------------------------------------
// Address: 0x00441630
// Name: public: virtual int CEventPropertiesGenericDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesGenericDialog::HandleMessage(
        CEventPropertiesGenericDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesGenericDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  LRESULT v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND DlgItem; // eax
  HWND__ *v20; // [esp-14h] [ebp-260h]
  unsigned int v21; // [esp-10h] [ebp-25Ch]
  unsigned int v22; // [esp-Ch] [ebp-258h]
  HWND v23; // [esp-8h] [ebp-254h]
  char buf1[256]; // [esp+Ch] [ebp-240h] BYREF
  char v25[256]; // [esp+10Ch] [ebp-140h] BYREF
  tagRECT rcOut; // [esp+20Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+22Ch] [ebp-20h] BYREF

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
             a2: &g_Params_11,
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
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_11.m_pEvent);
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
          v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
          g_Params_11.m_bResumeCondition = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          break;
        case 0x401u:
          g_Params_11.m_bUsesTag = false;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_11);
          return 1;
        case 0x402u:
          g_Params_11.m_bUsesTag = true;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_11);
          return 1;
        default:
          break;
      }
      return 1;
    }
    if ( (unsigned __int16)wParam == 1017 )
    {
      v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v15 = SendMessageA(hWnd: v14, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_11.m_bHasEndTime = v15 == 1;
      if ( v15 == 1 )
      {
        v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v17, nCmdShow: 9);
      }
      else
      {
        v16 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v16, nCmdShow: 0);
      }
      return 1;
    }
    else if ( (unsigned __int16)wParam > 0x3EFu )
    {
      if ( (unsigned __int16)wParam != 1010 || lParam == nullptr )
        return 1;
      if ( g_Params_11.m_nType == 4 )
      {
        v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
        SendMessageA(hWnd: v13, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)v25);
        V_snprintf(pDest: g_Params_11.m_szParameters2, maxLen: 256, pFormat: "%s", v25);
      }
      else
      {
        SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_11.m_szParameters2);
      }
      return 1;
    }
    else
    {
      if ( (unsigned __int16)wParam == 1007 )
      {
        if ( lParam != nullptr )
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_11.m_szParameters);
          return 1;
        }
        return 1;
      }
      if ( (unsigned __int16)wParam != 1 )
      {
        if ( (unsigned __int16)wParam == 2 )
        {
          EndDialog(hDlg: v6, nResult: 0);
          return 1;
        }
        return 1;
      }
      v12 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
      if ( v12 != nullptr )
        SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_11.m_szParameters);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_11.m_szName, cchMax: 256);
      if ( g_Params_11.m_szName[0] == 0 )
      {
        V_snprintf(pDest: g_Params_11.m_szName, maxLen: 256, pFormat: "%s", g_Params_11.m_szParameters);
        if ( g_Params_11.m_szParameters2[0] != 0 )
        {
          V_snprintf(pDest: buf1, maxLen: 512, pFormat: " to %s", g_Params_11.m_szParameters2);
          V_strncat(pDest: g_Params_11.m_szName, pSrc: buf1, destBufferSize: 0x100u, max_chars_to_copy: -1);
        }
      }
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
      g_Params_11.m_flStartTime = atof(nptr: szTime);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
      g_Params_11.m_flEndTime = atof(nptr: szTime);
      CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_11);
      EndDialog(hDlg: v6, nResult: 1);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441A40
// Name: public: virtual void CEventPropertiesGenericDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGenericDialog::InitControlData(CEventPropertiesGenericDialog *this, HWND__ *params)
{
  HWND DlgItem; // eax
  HWND__ *choices2; // [esp+Ch] [ebp-4h]
  HWND__ *choices1; // [esp+18h] [ebp+8h]

  CBaseEventPropertiesDialog::InitControlData(this, (CEventParams *)params);
  choices1 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: choices1, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices1, Msg: 0xCu, wParam: 0, lParam: (LPARAM)(params + 100));
  choices2 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
  SendMessageA(hWnd: choices2, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices2, Msg: 0xCu, wParam: 0, lParam: (LPARAM)(params + 164));
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1011);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0x100u, lParam: (LPARAM)(params + 100));
  CEventPropertiesGenericDialog::PopulateAIGeneric(this, control: choices1, (CEventParams *)params);
  CBaseEventPropertiesDialog::PopulateNamedActorList(this, wnd: choices2, (CEventParams *)params);
}

//------------------------------------------------------------------------------
// Address: 0x00441B00
// Name: EventPropertiesGenericDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesGenericDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesGenericDialog::HandleMessage(
           this: &g_EventPropertiesGenericDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00441B10
// Name: int EventProperties_Generic(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Generic(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_11 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x86,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesGenericDialogProc,
             dwInitParam: 0);
  *params = g_Params_11;
  return result;
}
