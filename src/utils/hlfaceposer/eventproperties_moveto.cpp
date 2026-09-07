// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_moveto.cpp
// Functions: 8
// ============================================================

#include "utils\hlfaceposer\eventproperties_moveto.h"

//------------------------------------------------------------------------------
// Address: 0x00442EE0
// Name: public: virtual void CEventPropertiesMoveToDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesMoveToDialog::SetTitle(CEventPropertiesMoveToDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_15, eventname: "MoveTo", desc: "Move To Actor");
}

//------------------------------------------------------------------------------
// Address: 0x00442F00
// Name: public: virtual void CEventPropertiesMoveToDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesMoveToDialog::InitDialog(CEventPropertiesMoveToDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_15, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_15);
  this->InitControlData(this, a2: &g_Params_15);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_15);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00442F70
// Name: private: void CEventPropertiesMoveToDialog::PopulateMovementStyle(struct HWND__ __near *,class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesMoveToDialog::PopulateMovementStyle(
        CEventPropertiesMoveToDialog *this,
        HWND__ *control,
        CEventParams *params)
{
  int v3; // eax
  char v4; // cl
  int v5; // eax
  char v6; // cl
  char movement_style[256]; // [esp+108h] [ebp-100h] BYREF

  movement_style[0] = 0;
  ParseFromMemory(buffer: params->m_szParameters2, size: strlen(params->m_szParameters2));
  if ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    v3 = 0;
    do
    {
      v4 = token[v3];
      movement_style[v3++] = v4;
    }
    while ( v4 != 0 );
    if ( TokenAvailable() != 0 )
    {
      GetToken(crossline: 0);
      v5 = 0;
      do
        v6 = token[v5++];
      while ( v6 != 0 );
    }
  }
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Walk");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Run");
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"CrouchWalk");
  SendMessageA(hWnd: control, Msg: 0xCu, wParam: 0, lParam: (LPARAM)movement_style);
}

//------------------------------------------------------------------------------
// Address: 0x00443040
// Name: private: void CEventPropertiesMoveToDialog::SetDistanceToTargetText(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesMoveToDialog::SetDistanceToTargetText(
        CEventPropertiesMoveToDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // esi
  char *v3; // eax

  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1076);
  v3 = va(fmt: "%i", (int)params->m_flDistanceToTarget);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v3);
}

//------------------------------------------------------------------------------
// Address: 0x00443080
// Name: public: virtual int CEventPropertiesMoveToDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesMoveToDialog::HandleMessage(
        CEventPropertiesMoveToDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesMoveToDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND DlgItem; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  LRESULT v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND__ *v26; // [esp-14h] [ebp-160h]
  unsigned int v27; // [esp-10h] [ebp-15Ch]
  unsigned int v28; // [esp-Ch] [ebp-158h]
  HWND v29; // [esp-8h] [ebp-154h]
  char buf1[256]; // [esp+Ch] [ebp-140h] BYREF
  tagRECT rcOut; // [esp+10Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+12Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v29 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v28 = wParam;
  v27 = uMsg;
  v26 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_15,
             a3: v26,
             a4: v27,
             a5: v28,
             a6: (int)v29,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) != 0 )
    return result;
  if ( v5 <= 0x110 )
  {
    if ( v5 == 272 )
    {
      this->InitDialog(this, a2: v6);
      return 0;
    }
    if ( v5 == 15 )
    {
      v10 = BeginPaint(hWnd: v6, lpPaint: (LPPAINTSTRUCT)&rcOut);
      DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
      CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: DlgItem, e: g_Params_15.m_pEvent);
      EndPaint(hWnd: v6, lpPaint: (const PAINTSTRUCT *)&rcOut);
    }
    return 0;
  }
  v12 = v5 - 273;
  if ( v12 != 0 )
  {
    v13 = v12 - 3;
    if ( v13 != 0 )
    {
      if ( v13 == 1 )
      {
        v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: v14, rcOut: (tagRECT *)&szTime[16]);
        InvalidateRect(hWnd: v6, lpRect: (const RECT *)&szTime[16], bErase: true);
        UpdateWindow(hWnd: v6);
        return 0;
      }
    }
    else
    {
      v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1075);
      if ( lParam == v15 )
      {
        v16 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1075);
        g_Params_15.m_flDistanceToTarget = (float)SendMessageA(hWnd: v16, Msg: 0x400u, wParam: 0, lParam: 0);
        CEventPropertiesMoveToDialog::SetDistanceToTargetText(this, params: &g_Params_15);
        return 1;
      }
    }
    return 0;
  }
  if ( (unsigned __int16)wParam > 0x3FAu )
  {
    switch ( (__int16)wParam )
    {
      case 1025:
        g_Params_15.m_bUsesTag = false;
        CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_15);
        result = 1;
        break;
      case 1026:
        g_Params_15.m_bUsesTag = true;
        CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_15);
        result = 1;
        break;
      case 1044:
        if ( lParam == nullptr )
          return 1;
        if ( g_Params_15.m_nType == 4 )
        {
          v24 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1044);
          SendMessageA(hWnd: v24, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)buf1);
          V_snprintf(pDest: g_Params_15.m_szParameters3, maxLen: 256, pFormat: "%s", buf1);
        }
        else
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_15.m_szParameters3);
        }
        result = 1;
        break;
      case 1087:
        v25 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1087);
        g_Params_15.m_bForceShortMovement = SendMessageA(hWnd: v25, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
        return 1;
      default:
        return 0;
    }
    return result;
  }
  if ( (unsigned __int16)wParam == 1018 )
  {
    v23 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
    g_Params_15.m_bResumeCondition = SendMessageA(hWnd: v23, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
    return 1;
  }
  if ( (unsigned __int16)wParam <= 0x3EFu )
  {
    if ( (unsigned __int16)wParam != 1007 )
    {
      if ( (unsigned __int16)wParam != 1 )
      {
        if ( (unsigned __int16)wParam == 2 )
        {
          EndDialog(hDlg: v6, nResult: 0);
          return 1;
        }
        return 0;
      }
      v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
      if ( v17 != nullptr )
        SendMessageA(hWnd: v17, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_15.m_szParameters);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_15.m_szName, cchMax: 256);
      if ( g_Params_15.m_szName[0] == 0 )
        V_snprintf(pDest: g_Params_15.m_szName, maxLen: 256, pFormat: "Moveto %s", g_Params_15.m_szParameters);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
      g_Params_15.m_flStartTime = atof(nptr: szTime);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
      g_Params_15.m_flEndTime = atof(nptr: szTime);
      CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_15);
      EndDialog(hDlg: v6, nResult: 1);
      return 1;
    }
    if ( lParam != nullptr )
    {
      SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_15.m_szParameters);
      return 1;
    }
    return 1;
  }
  if ( (unsigned __int16)wParam == 1010 )
  {
    if ( lParam != nullptr )
    {
      if ( g_Params_15.m_nType == 4 )
      {
        v22 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
        SendMessageA(hWnd: v22, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)buf1);
        V_snprintf(pDest: g_Params_15.m_szParameters2, maxLen: 256, pFormat: "%s", buf1);
      }
      else
      {
        SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_15.m_szParameters2);
      }
      return 1;
    }
    return 1;
  }
  if ( (unsigned __int16)wParam != 1017 )
    return 0;
  v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
  v19 = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0);
  g_Params_15.m_bHasEndTime = v19 == 1;
  if ( v19 == 1 )
  {
    v21 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
    ShowWindow(hWnd: v21, nCmdShow: 9);
  }
  else
  {
    v20 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
    ShowWindow(hWnd: v20, nCmdShow: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004435C0
// Name: public: virtual void CEventPropertiesMoveToDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesMoveToDialog::InitControlData(CEventPropertiesMoveToDialog *this, CEventParams *params)
{
  const char *v3; // eax
  const char *v4; // eax
  HWND DlgItem; // eax
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // esi
  char *v10; // eax
  HWND__ *control; // [esp+18h] [ebp-10h]
  HWND__ *choices2; // [esp+1Ch] [ebp-Ch]
  HWND__ *choices1; // [esp+20h] [ebp-8h]
  HWND__ *choices3; // [esp+24h] [ebp-4h]

  v3 = va(fmt: "%f", g_Params_15.m_flStartTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: v3);
  v4 = va(fmt: "%f", g_Params_15.m_flEndTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: v4);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: g_Params_15.m_bHasEndTime, lParam: 0);
  v6 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
  SendMessageA(hWnd: v6, Msg: 0xF1u, wParam: g_Params_15.m_bResumeCondition, lParam: 0);
  CBaseEventPropertiesDialog::PopulateTagList(this, params);
  choices1 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: choices1, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices1, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
  choices2 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
  SendMessageA(hWnd: choices2, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices2, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters2);
  choices3 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1044);
  SendMessageA(hWnd: choices3, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters3);
  control = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1075);
  SendMessageA(hWnd: control, Msg: 0x406u, wParam: 0, lParam: 13107200);
  SendMessageA(hWnd: control, Msg: 0x405u, wParam: 1u, lParam: (int)params->m_flDistanceToTarget);
  v7 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1087);
  SendMessageA(hWnd: v7, Msg: 0xF1u, wParam: g_Params_15.m_bForceShortMovement, lParam: 0);
  CBaseEventPropertiesDialog::PopulateNamedActorList(this, wnd: choices1, params);
  v8 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1013);
  SendMessageA(hWnd: v8, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"Movement Style:");
  CEventPropertiesMoveToDialog::PopulateMovementStyle(this, control: choices2, params);
  if ( strlen(params->m_szParameters3) != 0 )
    SendMessageA(hWnd: choices3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)defaultValue);
  CBaseEventPropertiesDialog::PopulateNamedActorList(this, wnd: choices3, params);
  v9 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1076);
  v10 = va(fmt: "%i", (int)params->m_flDistanceToTarget);
  SendMessageA(hWnd: v9, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v10);
}

//------------------------------------------------------------------------------
// Address: 0x00443810
// Name: EventPropertiesMoveToDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesMoveToDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesMoveToDialog::HandleMessage(
           this: &g_EventPropertiesMoveToDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00443820
// Name: int EventProperties_MoveTo(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_MoveTo(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_15 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7B,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesMoveToDialogProc,
             dwInitParam: 0);
  *params = g_Params_15;
  return result;
}
