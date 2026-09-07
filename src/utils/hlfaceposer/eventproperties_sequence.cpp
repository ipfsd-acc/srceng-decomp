// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_sequence.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\eventproperties_sequence.h"

//------------------------------------------------------------------------------
// Address: 0x00443C40
// Name: public: virtual void CEventPropertiesSequenceDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSequenceDialog::SetTitle(CEventPropertiesSequenceDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_17, eventname: "Sequence", desc: "Sequence");
}

//------------------------------------------------------------------------------
// Address: 0x00443C60
// Name: private: void CEventPropertiesSequenceDialog::PopulateSequenceList(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSequenceDialog::PopulateSequenceList(CEventPropertiesSequenceDialog *this, HWND__ *wnd)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v7; // eax
  const studiohdr_t *v8; // ecx
  int v9; // eax
  mstudioseqdesc_t *v10; // eax

  v2 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v2->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v2->m_MDLHandle);
      CStudioHdr::Init(this: v2->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = v2->m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      for ( i = 0; ; ++i )
      {
        v7 = m_pStudioHdr->m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
           : m_pStudioHdr->m_pStudioHdr->numlocalseq;
        if ( i >= v7 )
          break;
        if ( m_pStudioHdr->m_pVModel != nullptr )
        {
          v10 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
        }
        else
        {
          v8 = m_pStudioHdr->m_pStudioHdr;
          v9 = i;
          if ( i < 0 || i >= v8->numlocalseq )
            v9 = 0;
          v10 = (mstudioseqdesc_t *)((char *)v8 + 212 * v9 + v8->localseqindex);
        }
        SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v10 + v10->szlabelindex);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443D30
// Name: public: virtual void CEventPropertiesSequenceDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSequenceDialog::InitControlData(
        CEventPropertiesSequenceDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // edi
  HWND v4; // eax

  CBaseEventPropertiesDialog::InitControlData(this, params);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
  v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1091);
  SendMessageA(hWnd: v4, Msg: 0xF1u, wParam: g_Params_17.m_bPlayOverScript, lParam: 0);
  CEventPropertiesSequenceDialog::PopulateSequenceList(this, wnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00443DB0
// Name: public: virtual void CEventPropertiesSequenceDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSequenceDialog::InitDialog(CEventPropertiesSequenceDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_17, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_17);
  this->InitControlData(this, a2: &g_Params_17);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_17);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00443E40
// Name: public: virtual int CEventPropertiesSequenceDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesSequenceDialog::HandleMessage(
        CEventPropertiesSequenceDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesSequenceDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
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
             a2: &g_Params_17,
             a3: v20,
             a4: v21,
             a5: v22,
             a6: (int)v23,
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
      CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_17.m_pEvent);
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
  if ( (unsigned __int16)wParam > 0x3FAu )
  {
    switch ( (unsigned __int16)wParam )
    {
      case 0x401u:
        g_Params_17.m_bUsesTag = false;
        break;
      case 0x402u:
        g_Params_17.m_bUsesTag = true;
        break;
      case 0x443u:
        v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1091);
        g_Params_17.m_bPlayOverScript = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
        return 1;
      default:
        return 1;
    }
    CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_17);
    return 1;
  }
  if ( (unsigned __int16)wParam == 1018 )
  {
    v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
    g_Params_17.m_bResumeCondition = SendMessageA(hWnd: v17, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
    return 1;
  }
  if ( (unsigned __int16)wParam > 0x3EFu )
  {
    if ( (unsigned __int16)wParam == 1017 )
    {
      v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v14 = SendMessageA(hWnd: v13, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_17.m_bHasEndTime = v14 == 1;
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
    }
    return 1;
  }
  if ( (unsigned __int16)wParam == 1007 )
  {
    if ( lParam != nullptr )
    {
      SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_17.m_szParameters);
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
    SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_17.m_szParameters);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_17.m_szName, cchMax: 256);
  if ( g_Params_17.m_szName[0] == 0 )
    V_strncpy(pDest: g_Params_17.m_szName, pSrc: g_Params_17.m_szParameters, maxLen: 256);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
  g_Params_17.m_flStartTime = atof(nptr: szTime);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
  g_Params_17.m_flEndTime = atof(nptr: szTime);
  CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_17);
  EndDialog(hDlg: v6, nResult: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004441A0
// Name: EventPropertiesSequenceDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesSequenceDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesSequenceDialog::HandleMessage(
           this: &g_EventPropertiesSequenceDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x004441B0
// Name: int EventProperties_Sequence(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Sequence(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_17 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7E,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesSequenceDialogProc,
             dwInitParam: 0);
  *params = g_Params_17;
  return result;
}
