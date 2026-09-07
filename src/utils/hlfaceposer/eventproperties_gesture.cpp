// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_gesture.cpp
// Functions: 9
// ============================================================

#include "utils\hlfaceposer\eventproperties_gesture.h"

//------------------------------------------------------------------------------
// Address: 0x00441B70
// Name: public: virtual void CEventPropertiesGestureDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGestureDialog::SetTitle(CEventPropertiesGestureDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_12, eventname: "Gesture", desc: "Gesture");
}

//------------------------------------------------------------------------------
// Address: 0x00441B90
// Name: public: virtual void CEventPropertiesGestureDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGestureDialog::InitDialog(CEventPropertiesGestureDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_12, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_12);
  this->InitControlData(this, a2: &g_Params_12);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_12);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00441C00
// Name: private: bool CEventPropertiesGestureDialog::CheckSequenceType(class StudioModel __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEventPropertiesGestureDialog::CheckSequenceType(
        CEventPropertiesGestureDialog *this,
        StudioModel *model,
        int iSequence,
        char *szType)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char *m_pModelName; // edi
  bool v7; // bl
  const char *KeyValueText; // eax
  KeyValues *Key; // eax
  KeyValues *v10; // eax
  const char *String; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: defaultValue);
  else
    v5 = nullptr;
  m_pModelName = model->m_pModelName;
  v7 = false;
  KeyValueText = StudioModel::GetKeyValueText(this: model, iSequence);
  if ( KeyValues::LoadFromBuffer(
         this: v5,
         resourceName: m_pModelName,
         pBuffer: KeyValueText,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: v5, keyName: "faceposer", bCreate: false);
    if ( Key != nullptr )
    {
      v10 = KeyValues::FindKey(this: Key, keyName: "type", bCreate: false);
      if ( v10 != nullptr )
      {
        String = KeyValues::GetString(this: v10, keyName: nullptr, defaultValue: defaultValue);
        v7 = _V_stricmp(s1: String, s2: szType) == 0;
      }
    }
  }
  KeyValues::deleteThis(this: v5);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00441CB0
// Name: public: virtual void CEventPropertiesGestureDialog::ShowControlsForEventType(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGestureDialog::ShowControlsForEventType(
        CEventPropertiesGestureDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // eax
  HWND v4; // eax

  CBaseEventPropertiesDialog::ShowControlsForEventType(this, params);
  if ( g_Params_12.m_nType == 6 && _V_stricmp(s1: g_Params_12.m_szName, s2: "NULL") == 0 )
  {
    DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
    ShowWindow(hWnd: DlgItem, nCmdShow: 0);
    v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1027);
    ShowWindow(hWnd: v4, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441D20
// Name: public: virtual int CEventPropertiesGestureDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesGestureDialog::HandleMessage(
        CEventPropertiesGestureDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesGestureDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
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
             a2: &g_Params_12,
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
      CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_12.m_pEvent);
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
        g_Params_12.m_bUsesTag = false;
        break;
      case 0x402u:
        g_Params_12.m_bUsesTag = true;
        break;
      case 0x440u:
        v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1088);
        g_Params_12.m_bSyncToFollowingGesture = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
        return 1;
      default:
        return 1;
    }
    CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_12);
    return 1;
  }
  if ( (unsigned __int16)wParam == 1018 )
  {
    v17 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
    g_Params_12.m_bResumeCondition = SendMessageA(hWnd: v17, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
    return 1;
  }
  if ( (unsigned __int16)wParam > 0x3EFu )
  {
    if ( (unsigned __int16)wParam == 1017 )
    {
      v13 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v14 = SendMessageA(hWnd: v13, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_12.m_bHasEndTime = v14 == 1;
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
      SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_12.m_szParameters);
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
    SendMessageA(hWnd: v12, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_12.m_szParameters);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_12.m_szName, cchMax: 256);
  if ( g_Params_12.m_szName[0] == 0 )
    V_strncpy(pDest: g_Params_12.m_szName, pSrc: g_Params_12.m_szParameters, maxLen: 256);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
  g_Params_12.m_flStartTime = atof(nptr: szTime);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
  g_Params_12.m_flEndTime = atof(nptr: szTime);
  CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_12);
  EndDialog(hDlg: v6, nResult: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00442080
// Name: private: void CEventPropertiesGestureDialog::PopulateGestureList(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGestureDialog::PopulateGestureList(CEventPropertiesGestureDialog *this, HWND__ *wnd)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v7; // eax
  StudioModel *v8; // eax
  const studiohdr_t *v9; // ecx
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  int j; // esi
  int v13; // eax
  StudioModel *v14; // eax
  const studiohdr_t *v15; // ecx
  int v16; // eax
  mstudioseqdesc_t *v17; // eax

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
        v8 = models->GetActiveStudioModel(this: models);
        if ( CEventPropertiesGestureDialog::CheckSequenceType(this, model: v8, iSequence: i, szType: "gesture") )
        {
          if ( m_pStudioHdr->m_pVModel != nullptr )
          {
            v11 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
          }
          else
          {
            v9 = m_pStudioHdr->m_pStudioHdr;
            v10 = i;
            if ( i < 0 || i >= v9->numlocalseq )
              v10 = 0;
            v11 = (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex);
          }
          SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v11 + v11->szlabelindex);
        }
      }
      for ( j = 0; ; ++j )
      {
        v13 = m_pStudioHdr->m_pVModel != nullptr
            ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
            : m_pStudioHdr->m_pStudioHdr->numlocalseq;
        if ( j >= v13 )
          break;
        v14 = models->GetActiveStudioModel(this: models);
        if ( CEventPropertiesGestureDialog::CheckSequenceType(this, model: v14, iSequence: j, szType: "posture") )
        {
          if ( m_pStudioHdr->m_pVModel != nullptr )
          {
            v17 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: j);
          }
          else
          {
            v15 = m_pStudioHdr->m_pStudioHdr;
            v16 = j;
            if ( j < 0 || j >= v15->numlocalseq )
              v16 = 0;
            v17 = (mstudioseqdesc_t *)((char *)v15 + 212 * v16 + v15->localseqindex);
          }
          SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v17 + v17->szlabelindex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442200
// Name: public: virtual void CEventPropertiesGestureDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesGestureDialog::InitControlData(
        CEventPropertiesGestureDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // edi
  HWND v4; // eax

  CBaseEventPropertiesDialog::InitControlData(this, params);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1007);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)params->m_szParameters);
  v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1088);
  SendMessageA(hWnd: v4, Msg: 0xF1u, wParam: g_Params_12.m_bSyncToFollowingGesture, lParam: 0);
  CEventPropertiesGestureDialog::PopulateGestureList(this, wnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00442280
// Name: EventPropertiesGestureDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesGestureDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesGestureDialog::HandleMessage(
           this: &g_EventPropertiesGestureDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00442290
// Name: int EventProperties_Gesture(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Gesture(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_12 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7D,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesGestureDialogProc,
             dwInitParam: 0);
  *params = g_Params_12;
  return result;
}
