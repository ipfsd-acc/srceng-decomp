// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_subscene.cpp
// Functions: 6
// ============================================================

#include "utils\hlfaceposer\eventproperties_subscene.h"

//------------------------------------------------------------------------------
// Address: 0x00445280
// Name: public: virtual void CEventPropertiesSubSceneDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSubSceneDialog::SetTitle(CEventPropertiesSubSceneDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_19, eventname: "SubScene", desc: "Sub-scene");
}

//------------------------------------------------------------------------------
// Address: 0x004452A0
// Name: public: virtual void CEventPropertiesSubSceneDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSubSceneDialog::InitControlData(
        CEventPropertiesSubSceneDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // edi
  HWND v4; // eax
  CEventParams *paramsa; // [esp+14h] [ebp+8h]

  CBaseEventPropertiesDialog::InitControlData(this, params);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  paramsa = (CEventParams *)params->m_szParameters;
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)paramsa);
  v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1011);
  SendMessageA(hWnd: v4, Msg: 0xCu, wParam: 0x100u, lParam: (LPARAM)paramsa);
}

//------------------------------------------------------------------------------
// Address: 0x00445310
// Name: public: virtual void CEventPropertiesSubSceneDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSubSceneDialog::InitDialog(CEventPropertiesSubSceneDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_19, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_19);
  this->InitControlData(this, a2: &g_Params_19);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_19);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00445380
// Name: public: virtual int CEventPropertiesSubSceneDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesSubSceneDialog::HandleMessage(
        CEventPropertiesSubSceneDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  HWND__ *v5; // ebx
  unsigned int v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesSubSceneDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // edi
  HWND v11; // eax
  HWND v12; // eax
  LRESULT v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND DlgItem; // eax
  HWND__ *v18; // [esp-14h] [ebp-260h]
  unsigned int v19; // [esp-10h] [ebp-25Ch]
  unsigned int v20; // [esp-Ch] [ebp-258h]
  HWND v21; // [esp-8h] [ebp-254h]
  char filename[512]; // [esp+Ch] [ebp-240h] BYREF
  tagRECT rcOut; // [esp+20Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+22Ch] [ebp-20h] BYREF

  v5 = hwndDlg;
  v6 = uMsg;
  v21 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v20 = wParam;
  v19 = uMsg;
  v18 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_19,
             a3: v18,
             a4: v19,
             a5: v20,
             a6: (int)v21,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) == 0 )
  {
    if ( v6 > 0x111 )
    {
      if ( v6 == 277 )
      {
        DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: DlgItem, rcOut: (tagRECT *)&szTime[16]);
        InvalidateRect(hWnd: v5, lpRect: (const RECT *)&szTime[16], bErase: true);
        UpdateWindow(hWnd: v5);
      }
      return 0;
    }
    if ( v6 != 273 )
    {
      if ( v6 == 15 )
      {
        v10 = BeginPaint(hWnd: v5, lpPaint: (LPPAINTSTRUCT)&rcOut);
        v11 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_19.m_pEvent);
        EndPaint(hWnd: v5, lpPaint: (const PAINTSTRUCT *)&rcOut);
        return 0;
      }
      if ( v6 == 272 )
      {
        this->InitDialog(this, a2: v5);
        return 0;
      }
      return 0;
    }
    if ( (unsigned __int16)wParam > 0x3F9u )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0x3FAu:
          v16 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
          g_Params_19.m_bResumeCondition = SendMessageA(hWnd: v16, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
          break;
        case 0x401u:
          g_Params_19.m_bUsesTag = false;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_19);
          return 1;
        case 0x402u:
          g_Params_19.m_bUsesTag = true;
          CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_19);
          return 1;
        default:
          break;
      }
      return 1;
    }
    if ( (unsigned __int16)wParam == 1017 )
    {
      v12 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v13 = SendMessageA(hWnd: v12, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_19.m_bHasEndTime = v13 == 1;
      if ( v13 == 1 )
      {
        v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v15, nCmdShow: 9);
      }
      else
      {
        v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v14, nCmdShow: 0);
      }
      return 1;
    }
    else
    {
      if ( (unsigned __int16)wParam > 0x3EFu )
      {
        if ( (unsigned __int16)wParam == 1009
          && FacePoser_ShowOpenFileNameDialog(relative: filename, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
        {
          SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1011, lpString: filename);
          return 1;
        }
        return 1;
      }
      if ( (unsigned __int16)wParam == 1007 )
      {
        if ( lParam != nullptr )
        {
          SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_19.m_szParameters);
          return 1;
        }
        return 1;
      }
      if ( (unsigned __int16)wParam != 1 )
      {
        if ( (unsigned __int16)wParam == 2 )
        {
          EndDialog(hDlg: v5, nResult: 0);
          return 1;
        }
        return 1;
      }
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1011, lpString: filename, cchMax: 512);
      V_strncpy(pDest: g_Params_19.m_szParameters, pSrc: filename, maxLen: 256);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_19.m_szName, cchMax: 256);
      if ( g_Params_19.m_szName[0] == 0 )
        V_strncpy(pDest: g_Params_19.m_szName, pSrc: g_Params_19.m_szParameters, maxLen: 256);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
      g_Params_19.m_flStartTime = atof(nptr: szTime);
      GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
      g_Params_19.m_flEndTime = atof(nptr: szTime);
      CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_19);
      EndDialog(hDlg: v5, nResult: 1);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445710
// Name: EventPropertiesSubSceneDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesSubSceneDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesSubSceneDialog::HandleMessage(
           this: &g_EventPropertiesSubSceneDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00445720
// Name: int EventProperties_SubScene(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_SubScene(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_19 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x82,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesSubSceneDialogProc,
             dwInitParam: 0);
  *params = g_Params_19;
  return result;
}
