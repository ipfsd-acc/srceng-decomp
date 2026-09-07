// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_lookat.cpp
// Functions: 8
// ============================================================

#include "utils\hlfaceposer\eventproperties_lookat.h"

//------------------------------------------------------------------------------
// Address: 0x00442700
// Name: public: virtual void CEventPropertiesLookAtDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesLookAtDialog::SetTitle(CEventPropertiesLookAtDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_14, eventname: "LookAt", desc: "Look At Actor");
}

//------------------------------------------------------------------------------
// Address: 0x00442720
// Name: public: virtual void CEventPropertiesLookAtDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesLookAtDialog::InitDialog(CEventPropertiesLookAtDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_14, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_14);
  this->InitControlData(this, a2: &g_Params_14);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_14);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00442790
// Name: private: void CEventPropertiesLookAtDialog::SetPitchYawText(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesLookAtDialog::SetPitchYawText(CEventPropertiesLookAtDialog *this, CEventParams *params)
{
  HWND DlgItem; // ebx
  char *v4; // eax
  HWND v5; // esi
  char *v6; // eax

  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1050);
  v4 = va(fmt: "%i", params->pitch);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
  v5 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1051);
  v6 = va(fmt: "%i", params->yaw);
  SendMessageA(hWnd: v5, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v6);
}

//------------------------------------------------------------------------------
// Address: 0x00442810
// Name: public: virtual int CEventPropertiesLookAtDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesLookAtDialog::HandleMessage(
        CEventPropertiesLookAtDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesLookAtDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND DlgItem; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // ebx
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // esi
  bool v20; // al
  HWND v21; // eax
  HWND v22; // eax
  LRESULT v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND__ *v30; // [esp-14h] [ebp-60h]
  unsigned int v31; // [esp-10h] [ebp-5Ch]
  unsigned int v32; // [esp-Ch] [ebp-58h]
  HWND v33; // [esp-8h] [ebp-54h]
  tagRECT rcOut; // [esp+Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+2Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v33 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v32 = wParam;
  v31 = uMsg;
  v30 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_14,
             a3: v30,
             a4: v31,
             a5: v32,
             a6: (int)v33,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) != 0 )
    return result;
  if ( v5 <= 0x110 )
  {
    if ( v5 != 272 )
    {
      if ( v5 == 15 )
      {
        v10 = BeginPaint(hWnd: v6, lpPaint: (LPPAINTSTRUCT)&rcOut);
        DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: DlgItem, e: g_Params_14.m_pEvent);
        EndPaint(hWnd: v6, lpPaint: (const PAINTSTRUCT *)&rcOut);
      }
      return 0;
    }
    this->InitDialog(this, a2: v6);
    return 0;
  }
  v12 = v5 - 273;
  if ( v12 == 0 )
  {
    if ( (unsigned __int16)wParam > 0x3FAu )
    {
      if ( (unsigned __int16)wParam == 1025 )
      {
        g_Params_14.m_bUsesTag = false;
      }
      else
      {
        if ( (unsigned __int16)wParam != 1026 )
        {
          if ( (unsigned __int16)wParam == 1052 )
          {
            v27 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1052);
            if ( SendMessageA(hWnd: v27, Msg: 0xF0u, wParam: 0, lParam: 0) != 1 )
            {
              g_Params_14.yaw = 0;
              g_Params_14.pitch = 0;
              CEventPropertiesLookAtDialog::SetPitchYawText(this, params: &g_Params_14);
              v28 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1048);
              SendMessageA(hWnd: v28, Msg: 0x405u, wParam: 1u, lParam: g_Params_14.pitch);
              v29 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1049);
              SendMessageA(hWnd: v29, Msg: 0x405u, wParam: 1u, lParam: g_Params_14.yaw);
              return 1;
            }
          }
          return 1;
        }
        g_Params_14.m_bUsesTag = true;
      }
      CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_14);
    }
    else
    {
      if ( (unsigned __int16)wParam == 1018 )
      {
        v26 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
        g_Params_14.m_bResumeCondition = SendMessageA(hWnd: v26, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
        return 1;
      }
      if ( (unsigned __int16)wParam > 0x3EFu )
      {
        if ( (unsigned __int16)wParam == 1017 )
        {
          v22 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
          v23 = SendMessageA(hWnd: v22, Msg: 0xF0u, wParam: 0, lParam: 0);
          g_Params_14.m_bHasEndTime = v23 == 1;
          if ( v23 == 1 )
          {
            v25 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
            ShowWindow(hWnd: v25, nCmdShow: 9);
          }
          else
          {
            v24 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
            ShowWindow(hWnd: v24, nCmdShow: 0);
          }
          return 1;
        }
      }
      else
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x3EFu:
            if ( lParam != nullptr )
            {
              SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_14.m_szParameters);
              return 1;
            }
            break;
          case 1u:
            v21 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
            if ( v21 != nullptr )
              SendMessageA(hWnd: v21, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_14.m_szParameters);
            GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_14.m_szName, cchMax: 256);
            if ( g_Params_14.m_szName[0] == 0 )
              V_snprintf(pDest: g_Params_14.m_szName, maxLen: 256, pFormat: "Look at %s", g_Params_14.m_szParameters);
            GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
            g_Params_14.m_flStartTime = atof(nptr: szTime);
            GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
            g_Params_14.m_flEndTime = atof(nptr: szTime);
            CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_14);
            EndDialog(hDlg: v6, nResult: 1);
            return 1;
          case 2u:
            EndDialog(hDlg: v6, nResult: 0);
            return 1;
          default:
            break;
        }
      }
    }
    return 1;
  }
  v13 = v12 - 3;
  if ( v13 != 0 )
  {
    if ( v13 != 1 )
      return 0;
    v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
    CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: v14, rcOut: (tagRECT *)&szTime[16]);
    InvalidateRect(hWnd: v6, lpRect: (const RECT *)&szTime[16], bErase: true);
    UpdateWindow(hWnd: v6);
    return 0;
  }
  else
  {
    v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1049);
    v16 = lParam;
    if ( lParam != v15 && v16 != GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1048) )
      return 0;
    v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1049);
    g_Params_14.yaw = (int)(float)SendMessageA(hWnd: v17, Msg: 0x400u, wParam: 0, lParam: 0);
    v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1048);
    g_Params_14.pitch = (int)(float)SendMessageA(hWnd: v18, Msg: 0x400u, wParam: 0, lParam: 0);
    CEventPropertiesLookAtDialog::SetPitchYawText(this, params: &g_Params_14);
    v19 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1052);
    v20 = g_Params_14.pitch != 0 || g_Params_14.yaw != 0;
    g_Params_14.usepitchyaw = v20;
    SendMessageA(hWnd: v19, Msg: 0xF1u, wParam: v20, lParam: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442CA0
// Name: private: void CEventPropertiesLookAtDialog::SetupLookAtControls(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesLookAtDialog::SetupLookAtControls(CEventPropertiesLookAtDialog *this, HWND__ *params)
{
  HWND DlgItem; // eax
  HWND v5; // ebx
  HWND__ *control; // [esp+14h] [ebp+8h]

  CEventPropertiesLookAtDialog::SetPitchYawText(this, (CEventParams *)params);
  *((_BYTE *)params + 1720) = *((_DWORD *)params + 428) != 0 || *((_DWORD *)params + 429) != 0;
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1052);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: *((_BYTE *)params + 1720) != 0, lParam: 0);
  control = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1048);
  SendMessageA(hWnd: control, Msg: 0x406u, wParam: 0, lParam: (LPARAM)&g_flexedverts[3503].z);
  SendMessageA(hWnd: control, Msg: 0x405u, wParam: 1u, lParam: *((_DWORD *)params + 428));
  v5 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1049);
  SendMessageA(hWnd: v5, Msg: 0x406u, wParam: 0, lParam: (LPARAM)&g_flexedverts[3503].z);
  SendMessageA(hWnd: v5, Msg: 0x405u, wParam: 1u, lParam: *((_DWORD *)params + 429));
}

//------------------------------------------------------------------------------
// Address: 0x00442D70
// Name: public: virtual void CEventPropertiesLookAtDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesLookAtDialog::InitControlData(CEventPropertiesLookAtDialog *this, HWND__ *params)
{
  const char *v3; // eax
  const char *v4; // eax
  HWND DlgItem; // eax
  HWND v6; // eax
  HWND__ *choices1; // [esp+1Ch] [ebp+8h]

  v3 = va(fmt: "%f", g_Params_14.m_flStartTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: v3);
  v4 = va(fmt: "%f", g_Params_14.m_flEndTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: v4);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: g_Params_14.m_bHasEndTime, lParam: 0);
  v6 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
  SendMessageA(hWnd: v6, Msg: 0xF1u, wParam: g_Params_14.m_bResumeCondition, lParam: 0);
  CBaseEventPropertiesDialog::PopulateTagList(this, (CEventParams *)params);
  choices1 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: choices1, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices1, Msg: 0xCu, wParam: 0, lParam: (LPARAM)(params + 100));
  CEventPropertiesLookAtDialog::SetupLookAtControls(this, params);
  CBaseEventPropertiesDialog::PopulateNamedActorList(this, wnd: choices1, (CEventParams *)params);
}

//------------------------------------------------------------------------------
// Address: 0x00442E80
// Name: EventPropertiesLookAtDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesLookAtDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesLookAtDialog::HandleMessage(
           this: &g_EventPropertiesLookAtDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00442E90
// Name: int EventProperties_LookAt(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_LookAt(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_14 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7A,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesLookAtDialogProc,
             dwInitParam: 0);
  *params = g_Params_14;
  return result;
}
