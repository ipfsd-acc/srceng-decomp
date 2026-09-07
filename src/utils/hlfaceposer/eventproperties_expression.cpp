// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_expression.cpp
// Functions: 8
// ============================================================

#include "utils\hlfaceposer\eventproperties_expression.h"

//------------------------------------------------------------------------------
// Address: 0x00440090
// Name: public: virtual void CEventPropertiesExpressionDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesExpressionDialog::SetTitle(CEventPropertiesExpressionDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_7, eventname: "Expression", desc: "Expression");
}

//------------------------------------------------------------------------------
// Address: 0x004400B0
// Name: private: void CEventPropertiesExpressionDialog::PopulateExpressionList(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesExpressionDialog::PopulateExpressionList(
        CEventPropertiesExpressionDialog *this,
        HWND__ *wnd)
{
  int i; // esi
  CExpClass *v3; // eax
  const char *Name; // eax

  for ( i = 0; i < expressions->GetNumClasses(this: expressions); ++i )
  {
    v3 = expressions->GetClass(this: expressions, a2: i);
    if ( v3 != nullptr )
    {
      Name = CExpClass::GetName(this: v3);
      SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Name);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440110
// Name: public: virtual void CEventPropertiesExpressionDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesExpressionDialog::InitDialog(CEventPropertiesExpressionDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_7, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_7);
  this->InitControlData(this, a2: &g_Params_7);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_7);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00440180
// Name: private: void CEventPropertiesExpressionDialog::PopulateExpressionClass(struct HWND__ __near *,class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesExpressionDialog::PopulateExpressionClass(
        CEventPropertiesExpressionDialog *this,
        HWND__ *control,
        CEventParams *params)
{
  int v3; // edi
  CExpClass *v4; // esi
  const char *Name; // eax
  int i; // edi
  CExpression *Expression; // eax

  v3 = 0;
  if ( expressions->GetNumClasses(this: expressions) > 0 )
  {
    while ( 1 )
    {
      v4 = expressions->GetClass(this: expressions, a2: v3);
      if ( v4 != nullptr )
      {
        Name = CExpClass::GetName(this: v4);
        if ( _V_stricmp(s1: Name, s2: params->m_szParameters) == 0 )
          break;
      }
      if ( ++v3 >= expressions->GetNumClasses(this: expressions) )
        return;
    }
    for ( i = 0; i < CExpClass::GetNumExpressions(this: v4); ++i )
    {
      Expression = CExpClass::GetExpression(this: v4, num: i);
      if ( Expression != nullptr )
        SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Expression);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440230
// Name: public: virtual int CEventPropertiesExpressionDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesExpressionDialog::HandleMessage(
        CEventPropertiesExpressionDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesExpressionDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  LRESULT v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND DlgItem; // eax
  HWND__ *v21; // [esp-14h] [ebp-160h]
  unsigned int v22; // [esp-10h] [ebp-15Ch]
  unsigned int v23; // [esp-Ch] [ebp-158h]
  HWND v24; // [esp-8h] [ebp-154h]
  char buf1[256]; // [esp+Ch] [ebp-140h] BYREF
  tagRECT rcOut; // [esp+10Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+12Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v24 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v23 = wParam;
  v22 = uMsg;
  v21 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_7,
             a3: v21,
             a4: v22,
             a5: v23,
             a6: (int)v24,
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
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_7.m_pEvent);
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
          v19 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
          g_Params_7.m_bResumeCondition = SendMessageA(hWnd: v19, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          break;
        case 0x401u:
          g_Params_7.m_bUsesTag = false;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_7);
          return 1;
        case 0x402u:
          g_Params_7.m_bUsesTag = true;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_7);
          return 1;
        default:
          break;
      }
      return 1;
    }
    if ( (unsigned __int16)wParam == 1017 )
    {
      v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v16 = SendMessageA(hWnd: v15, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_7.m_bHasEndTime = v16 == 1;
      if ( v16 == 1 )
      {
        v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v18, nCmdShow: 9);
      }
      else
      {
        v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v17, nCmdShow: 0);
      }
      return 1;
    }
    else if ( (unsigned __int16)wParam > 0x3EFu )
    {
      if ( (unsigned __int16)wParam != 1010 || lParam == nullptr )
        return 1;
      if ( g_Params_7.m_nType == 4 )
      {
        v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
        SendMessageA(hWnd: v14, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)buf1);
        V_snprintf(pDest: g_Params_7.m_szParameters2, maxLen: 256, pFormat: "%s", buf1);
      }
      else
      {
        SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_7.m_szParameters2);
      }
      return 1;
    }
    else
    {
      if ( (unsigned __int16)wParam == 1007 )
      {
        if ( lParam != nullptr )
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_7.m_szParameters);
          v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
          CEventPropertiesExpressionDialog::PopulateExpressionClass(this, control: v13, params: &g_Params_7);
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
        SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_7.m_szParameters);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_7.m_szName, cchMax: 256);
      if ( g_Params_7.m_szName[0] == 0 )
        V_snprintf(
          pDest: g_Params_7.m_szName,
          maxLen: 256,
          pFormat: "%s/%s",
          g_Params_7.m_szParameters,
          g_Params_7.m_szParameters2);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
      g_Params_7.m_flStartTime = atof(nptr: szTime);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
      g_Params_7.m_flEndTime = atof(nptr: szTime);
      CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_7);
      EndDialog(hDlg: v6, nResult: 1);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00440620
// Name: public: virtual void CEventPropertiesExpressionDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesExpressionDialog::InitControlData(
        CEventPropertiesExpressionDialog *this,
        HWND__ *params)
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
  CEventPropertiesExpressionDialog::PopulateExpressionList(this, wnd: choices1);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1013);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)aName_0);
  CEventPropertiesExpressionDialog::PopulateExpressionClass(this, control: choices2, (CEventParams *)params);
}

//------------------------------------------------------------------------------
// Address: 0x004406E0
// Name: EventPropertiesExpressionDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesExpressionDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesExpressionDialog::HandleMessage(
           this: &g_EventPropertiesExpressionDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x004406F0
// Name: int EventProperties_Expression(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Expression(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_7 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x79,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesExpressionDialogProc,
             dwInitParam: 0);
  *params = g_Params_7;
  return result;
}
