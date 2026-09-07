// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/objectproperties.cpp
// Functions: 545
// ============================================================

#include "hammer\objectproperties.h"

//------------------------------------------------------------------------------
// Address: 0x100D55A0
// Name: public: virtual struct CRuntimeClass __near * CObjectProperties::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CObjectProperties::GetRuntimeClass(CObjectProperties *this)
{
  return &CObjectProperties::classCObjectProperties;
}

//------------------------------------------------------------------------------
// Address: 0x100D55B0
// Name: public: virtual struct CRuntimeClass __near * editCMapClass::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall editCMapClass::GetRuntimeClass(editCMapClass *this)
{
  return &editCMapClass::classeditCMapClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D55C0
// Name: public: virtual struct CRuntimeClass __near * editCEditGameClass::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall editCEditGameClass::GetRuntimeClass(editCEditGameClass *this)
{
  return &editCEditGameClass::classeditCEditGameClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D5680
// Name: public: void CObjectProperties::CreatePages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::CreatePages(CObjectProperties *this)
{
  COP_Entity *v2; // eax
  COP_Entity *v3; // eax
  CUtlReferenceVector<CMapClass> *p_m_DstObjects; // edi
  COP_Flags *v5; // eax
  COP_Flags *v6; // eax
  COP_Groups *v7; // eax
  COP_Groups *v8; // eax
  COP_Output *v9; // eax
  COP_Output *v10; // eax
  COP_Input *v11; // eax
  COP_Input *v12; // eax
  COP_Model *v13; // eax
  COP_Model *v14; // eax
  CPropertyPage *v15; // eax
  CPropertyPage *v16; // eax

  v2 = (COP_Entity *)operator new(nSize: 0xD44u);
  if ( v2 != nullptr )
    v3 = COP_Entity::COP_Entity(this: v2);
  else
    v3 = nullptr;
  this->m_pEntity = v3;
  p_m_DstObjects = &this->m_DstObjects;
  v3->m_pObjectList = &this->m_DstObjects;
  v5 = (COP_Flags *)operator new(nSize: 0x174u);
  if ( v5 != nullptr )
    v6 = COP_Flags::COP_Flags(this: v5);
  else
    v6 = nullptr;
  this->m_pFlags = v6;
  v6->m_pObjectList = p_m_DstObjects;
  COP_Entity::SetFlagsPage(this: this->m_pEntity, pFlagsPage: this->m_pFlags);
  COP_Flags::SetEntityPage(this: this->m_pFlags, pPage: this->m_pEntity);
  v7 = (COP_Groups *)operator new(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = COP_Groups::COP_Groups(this: v7);
  else
    v8 = nullptr;
  this->m_pGroups = v8;
  v8->m_pObjectList = p_m_DstObjects;
  v9 = (COP_Output *)operator new(nSize: 0x828u);
  if ( v9 != nullptr )
    v10 = COP_Output::COP_Output(this: v9);
  else
    v10 = nullptr;
  this->m_pOutput = v10;
  v10->m_pObjectList = p_m_DstObjects;
  v11 = (COP_Input *)operator new(nSize: 0x180u);
  if ( v11 != nullptr )
    v12 = COP_Input::COP_Input(this: v11);
  else
    v12 = nullptr;
  this->m_pInput = v12;
  v12->m_pObjectList = p_m_DstObjects;
  v13 = (COP_Model *)operator new(nSize: 0x1F0u);
  if ( v13 != nullptr )
    v14 = COP_Model::COP_Model(this: v13);
  else
    v14 = nullptr;
  this->m_pModel = v14;
  v14->m_pObjectList = p_m_DstObjects;
  v15 = (CPropertyPage *)operator new(nSize: 0xA8u);
  if ( v15 != nullptr )
    v16 = CPropertyPage::CPropertyPage(this: v15, nIDTemplate: 0x9Fu, nIDCaption: 0, dwSize: 0x38u);
  else
    v16 = nullptr;
  this->m_ppPages = nullptr;
  this->m_nPages = 0;
  this->m_pLastActivePage = nullptr;
  this->m_pDummy = v16;
}

//------------------------------------------------------------------------------
// Address: 0x100D5870
// Name: public: void __near * CObjectProperties::GetEditObject(struct CRuntimeClass __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CObjectProperties::GetEditObject(CObjectProperties *this, CRuntimeClass *pType)
{
  if ( pType == &editCMapClass::classeditCMapClass )
    return &e_CMapClass.CMapClass;
  else
    return pType != &editCEditGameClass::classeditCEditGameClass
         ? nullptr
         : (CMapClass *)&e_CEditGameClass.CEditGameClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D58A0
// Name: protected: void CObjectProperties::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnSize(CObjectProperties *this, unsigned int nType, unsigned int cx, int cy)
{
  CAnchorMgr::OnSize(this: &this->m_AnchorMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100D58B0
// Name: protected: void CObjectProperties::OnInputs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnInputs(CObjectProperties *this)
{
  CPropertySheet::SetActivePage(this, pPage: this->m_pInput);
}

//------------------------------------------------------------------------------
// Address: 0x100D58C0
// Name: protected: void CObjectProperties::OnOutputs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnOutputs(CObjectProperties *this)
{
  CPropertySheet::SetActivePage(this, pPage: this->m_pOutput);
}

//------------------------------------------------------------------------------
// Address: 0x100D58D0
// Name: protected: int CObjectProperties::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectProperties::OnCreate(CObjectProperties *this, tagCREATESTRUCTA *lpCreateStruct)
{
  lpCreateStruct->dwExStyle |= 0x80u;
  return (CWnd::Default(this) != -1) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D58F0
// Name: public: class CPropertyPage __near * CPropertySheet::GetPage(int)const
// Source: json
//------------------------------------------------------------------------------
CPropertyPage *__thiscall CPropertySheet::GetPage(CPropertySheet *this, int nPage)
{
  CPropertyPage *result; // eax

  if ( nPage < 0
    || nPage >= this->m_pages.m_nSize
    || (result = (CPropertyPage *)this->m_pages.m_pData[nPage]) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5920
// Name: public: class CTabCtrl __near * CPropertySheet::GetTabControl(void)const
// Source: json
//------------------------------------------------------------------------------
CTabCtrl *__thiscall CPropertySheet::GetTabControl(CPropertySheet *this)
{
  HWND__ *v1; // eax

  v1 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x474u, wParam: 0, lParam: 0);
  return (CTabCtrl *)CWnd::FromHandle(hWnd: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100D5950
// Name: public: void CObjectProperties::SetOutputButtonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::SetOutputButtonState(CObjectProperties *this, int nState)
{
  if ( nState == 1 )
  {
    SendMessageA(hWnd: this->m_pOutputButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)this->m_hIconOutputGood);
    CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 5);
    InvalidateRect(hWnd: this->m_pOutputButton->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_pOutputButton->m_hWnd);
  }
  else
  {
    if ( nState == 2 )
    {
      SendMessageA(hWnd: this->m_pOutputButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)this->m_hIconOutputBad);
      CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 5);
    }
    else
    {
      CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 0);
    }
    InvalidateRect(hWnd: this->m_pOutputButton->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_pOutputButton->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5A50
// Name: protected: void CObjectProperties::CreateButtons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::CreateButtons(CObjectProperties *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // edi
  __int16 WindowLongA; // ax
  CWnd *v5; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  AFX_MODULE_STATE *v9; // eax
  CButton *v10; // ebx
  CWnd *v11; // eax
  CButton *v12; // edi
  CButton *v13; // ecx
  CWnd *v14; // eax
  CButton *v15; // edi
  CButton *v16; // ecx
  CWnd *v17; // eax
  CButton *v18; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-44h]
  int v20; // [esp+Ch] [ebp-30h] BYREF
  int v21; // [esp+10h] [ebp-2Ch]
  int v22; // [esp+14h] [ebp-28h]
  int v23; // [esp+18h] [ebp-24h]
  CRect rect; // [esp+1Ch] [ebp-20h] BYREF
  void *pData; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+38h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1);
  CWnd::EnableWindow(this: DlgItem, bEnable: 1);
  v3 = CWnd::GetDlgItem(this, nID: 12321);
  WindowLongA = GetWindowLongA(hWnd: v3->m_hWnd, nIndex: -16);
  SendMessageA(hWnd: v3->m_hWnd, Msg: 0xF4u, wParam: WindowLongA & 0xFFFE | 1, lParam: 1);
  CWnd::EnableWindow(this: v3, bEnable: 1);
  CWnd::ShowWindow(this: v3, nCmdShow: 8);
  v5 = CWnd::GetDlgItem(this, nID: 2);
  CWnd::EnableWindow(this: v5, bEnable: 1);
  CWnd::ShowWindow(this: v5, nCmdShow: 8);
  AfxGetModuleState();
  ModuleState = AfxGetModuleState();
  this->m_hIconOutputGood = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x13A);
  v7 = AfxGetModuleState();
  this->m_hIconOutputBad = LoadIconW(hInstance: v7->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x139);
  v8 = AfxGetModuleState();
  this->m_hIconInputGood = LoadIconW(hInstance: v8->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x138);
  v9 = AfxGetModuleState();
  this->m_hIconInputBad = LoadIconW(hInstance: v9->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x137);
  v10 = nullptr;
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  rect.bottom += 32;
  CWnd::MoveWindow(
    this,
    x: rect.left,
    y: rect.top,
    nWidth: rect.right - rect.left,
    nHeight: rect.bottom - rect.top,
    bRepaint: false);
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  v11 = (CWnd *)operator new(nSize: 0x74u);
  v12 = (CButton *)v11;
  pData = v11;
  v26 = 0;
  if ( v11 != nullptr )
  {
    CWnd::CWnd(this: v11);
    v12->__vftable = (CButton_vtbl *)&CButton::`vftable';
    LOBYTE(v26) = 0;
    v13 = v12;
  }
  else
  {
    v13 = nullptr;
  }
  v26 = -1;
  v21 = rect.bottom - 34;
  v23 = rect.bottom - 2;
  this->m_pInputButton = v13;
  v20 = 6;
  v22 = 38;
  v13->Create_2(this: v13, a2: "My button", a3: 1342210112u, a4: (const tagRECT *)&v20, a5: this, a6: 312u);
  v14 = (CWnd *)operator new(nSize: 0x74u);
  v15 = (CButton *)v14;
  pData = v14;
  v26 = 2;
  if ( v14 != nullptr )
  {
    CWnd::CWnd(this: v14);
    v15->__vftable = (CButton_vtbl *)&CButton::`vftable';
    LOBYTE(v26) = 2;
    v16 = v15;
  }
  else
  {
    v16 = nullptr;
  }
  v26 = -1;
  v23 = rect.bottom - 2;
  v21 = rect.bottom - 34;
  this->m_pOutputButton = v16;
  v20 = 40;
  v22 = 72;
  v16->Create_2(this: v16, a2: "My button", a3: 1342210112u, a4: (const tagRECT *)&v20, a5: this, a6: 314u);
  v17 = (CWnd *)operator new(nSize: 0x74u);
  v18 = (CButton *)v17;
  pData = v17;
  v26 = 4;
  if ( v17 != nullptr )
  {
    CWnd::CWnd(this: v17);
    v18->__vftable = (CButton_vtbl *)&CButton::`vftable';
    LOBYTE(v26) = 4;
    v10 = v18;
  }
  v26 = -1;
  v23 = rect.bottom - 4;
  v21 = rect.bottom - 28;
  this->m_pInstanceButton = v10;
  v20 = 6;
  v22 = 140;
  v10->Create_2(this: v10, a2: "Edit Instance", a3: 1342177280u, a4: (const tagRECT *)&v20, a5: this, a6: 339u);
}

//------------------------------------------------------------------------------
// Address: 0x100D5D20
// Name: protected: void CObjectProperties::UpdateAnchors(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::UpdateAnchors(CObjectProperties *this, CWnd *pPage)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v4; // esi
  HWND__ *v5; // eax
  HWND__ *v6; // eax
  CWnd *v7; // eax
  HWND__ *v8; // eax
  CAnchorDef anchorDefs[8]; // [esp+4h] [ebp-160h] BYREF

  if ( this != nullptr )
  {
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr )
    {
      v4 = nullptr;
      v5 = (HWND__ *)SendMessageA(hWnd: m_hWnd, Msg: 0x474u, wParam: 0, lParam: 0);
      if ( CWnd::FromHandle(hWnd: v5) != nullptr )
      {
        v6 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x474u, wParam: 0, lParam: 0);
        v7 = CWnd::FromHandle(hWnd: v6);
        if ( v7 != nullptr )
          v4 = v7->m_hWnd;
      }
      CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[1], dlgItemID: 12321, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[2], dlgItemID: 2, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[3], dlgItemID: 312, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[4], dlgItemID: 314, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[5], dlgItemID: 339, eSimpleAnchor: k_eSimpleAnchorBottomRight);
      CAnchorDef::CAnchorDef(this: &anchorDefs[6], hWnd: v4, eSimpleAnchor: k_eSimpleAnchorAllSides);
      if ( pPage != nullptr )
        v8 = pPage->m_hWnd;
      else
        v8 = nullptr;
      CAnchorDef::CAnchorDef(this: &anchorDefs[7], hWnd: v8, eSimpleAnchor: k_eSimpleAnchorAllSides);
      CAnchorMgr::Init(this: &this->m_AnchorMgr, hParentWnd: this->m_hWnd, pAnchors: anchorDefs, nAnchors: 8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5E30
// Name: protected: void CObjectProperties::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnShowWindow(CObjectProperties *this, int bShow, unsigned int nStatus)
{
  int v3; // esi
  CObjectPage *v5; // ecx

  v3 = 0;
  CPropertySheet::SetActivePage(this, nPage: 0);
  this->m_pLastActivePage = nullptr;
  CWnd::Default(this);
  if ( this->m_nPages > 0 )
  {
    do
    {
      v5 = this->m_ppPages[v3];
      v5->OnShowPropertySheet(this: v5, a2: bShow, a3: nStatus);
      ++v3;
    }
    while ( v3 < this->m_nPages );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5E90
// Name: public: virtual int CObjectProperties::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectProperties::OnInitDialog(CObjectProperties *this)
{
  int inited; // edi

  inited = CPropertySheet::OnInitDialog(this);
  CWnd::SetWindowTextA(this, lpszString: "Object Properties");
  CObjectProperties::CreateButtons(this);
  CObjectProperties::UpdateAnchors(this, pPage: nullptr);
  return inited;
}

//------------------------------------------------------------------------------
// Address: 0x100D5F20
// Name: protected: void CObjectProperties::UpdateOutputButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::UpdateOutputButton(CObjectProperties *this)
{
  COP_Output *m_pOutput; // ecx
  int v3; // ebx
  CMapEntity *m_pObject; // edi
  int v5; // eax
  bool bIgnoreHiddenTargets; // [esp+7h] [ebp-5h]
  bool bHaveConnection; // [esp+Bh] [ebp-1h]

  if ( this->m_pOutputButton != nullptr )
  {
    m_pOutput = this->m_pOutput;
    bHaveConnection = false;
    bIgnoreHiddenTargets = false;
    if ( m_pOutput != nullptr )
      bIgnoreHiddenTargets = !COP_Output::ShouldShowHiddenTargets(this: m_pOutput);
    v3 = 0;
    if ( this->m_DstObjects.m_Size <= 0 )
    {
LABEL_14:
      CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 0);
      InvalidateRect(hWnd: this->m_pOutputButton->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_pOutputButton->m_hWnd);
    }
    else
    {
      do
      {
        m_pObject = (CMapEntity *)this->m_DstObjects.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_DstObjects.m_Memory
                                                                                                 + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr && m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0 )
        {
          v5 = CEntityConnection::ValidateOutputConnections(
                 pEntity: m_pObject,
                 bVisibilityCheck: true,
                 bIgnoreHiddenTargets,
                 CheckAllDocuments: true);
          if ( v5 == 2 )
          {
            SendMessageA(
              hWnd: this->m_pOutputButton->m_hWnd,
              Msg: 0xF7u,
              wParam: 1u,
              lParam: (LPARAM)this->m_hIconOutputBad);
            CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 5);
            InvalidateRect(hWnd: this->m_pOutputButton->m_hWnd, lpRect: nullptr, bErase: true);
            UpdateWindow(hWnd: this->m_pOutputButton->m_hWnd);
            return;
          }
          if ( v5 == 1 )
            bHaveConnection = true;
        }
        ++v3;
      }
      while ( v3 < this->m_DstObjects.m_Size );
      if ( !bHaveConnection )
        goto LABEL_14;
      SendMessageA(hWnd: this->m_pOutputButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)this->m_hIconOutputGood);
      CWnd::ShowWindow(this: this->m_pOutputButton, nCmdShow: 5);
      InvalidateRect(hWnd: this->m_pOutputButton->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_pOutputButton->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D60C0
// Name: protected: void CObjectProperties::UpdateInputButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::UpdateInputButton(CObjectProperties *this)
{
  int v2; // ebx
  CMapEntity *m_pObject; // edi
  int v4; // eax
  bool bHaveConnection; // [esp+7h] [ebp-1h]

  if ( this->m_pInputButton != nullptr )
  {
    v2 = 0;
    bHaveConnection = false;
    if ( this->m_DstObjects.m_Size <= 0 )
    {
LABEL_12:
      CWnd::ShowWindow(this: this->m_pInputButton, nCmdShow: 0);
      InvalidateRect(hWnd: this->m_pInputButton->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_pInputButton->m_hWnd);
    }
    else
    {
      do
      {
        m_pObject = (CMapEntity *)this->m_DstObjects.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_DstObjects.m_Memory
                                                                                                 + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr && m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0 )
        {
          v4 = CEntityConnection::ValidateInputConnections(pEntity: m_pObject, bVisibilityCheck: false);
          if ( v4 == 2 )
          {
            SendMessageA(
              hWnd: this->m_pInputButton->m_hWnd,
              Msg: 0xF7u,
              wParam: 1u,
              lParam: (LPARAM)this->m_hIconInputBad);
            CWnd::ShowWindow(this: this->m_pInputButton, nCmdShow: 5);
            InvalidateRect(hWnd: this->m_pInputButton->m_hWnd, lpRect: nullptr, bErase: true);
            UpdateWindow(hWnd: this->m_pInputButton->m_hWnd);
            return;
          }
          if ( v4 == 1 )
            bHaveConnection = true;
        }
        ++v2;
      }
      while ( v2 < this->m_DstObjects.m_Size );
      if ( !bHaveConnection )
        goto LABEL_12;
      SendMessageA(hWnd: this->m_pInputButton->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)this->m_hIconInputGood);
      CWnd::ShowWindow(this: this->m_pInputButton, nCmdShow: 5);
      InvalidateRect(hWnd: this->m_pInputButton->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_pInputButton->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6240
// Name: protected: enum LayoutType_t CObjectProperties::GetLayout(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectProperties::GetLayout(CObjectProperties *this)
{
  int m_Size; // eax
  int v3; // esi
  int v4; // edx
  CMapEntity *m_pObject; // edi
  char *v6; // eax
  int v7; // esi
  const char *ThisType; // [esp+8h] [ebp-10h]
  const char *PrevType; // [esp+Ch] [ebp-Ch]
  int pos; // [esp+10h] [ebp-8h]
  bool bFirst; // [esp+17h] [ebp-1h]

  m_Size = this->m_DstObjects.m_Size;
  v3 = 1;
  if ( m_Size != 0 && CMapDoc::m_pMapDoc != nullptr )
  {
    v4 = 0;
    bFirst = true;
    PrevType = CMapEntity::__Type;
    pos = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        m_pObject = (CMapEntity *)this->m_DstObjects.m_Memory.m_pMemory[v4 >> (*((int *)&this->m_DstObjects.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)].m_pObject;
        v6 = (char *)m_pObject->GetType(this: m_pObject);
        ThisType = v6;
        if ( bFirst )
        {
          bFirst = false;
          if ( v6 == CMapEntity::__Type )
          {
            if ( this->m_DstObjects.m_Size == 1 )
            {
              v7 = -(CMapEntity::GetChildOfType<CMapStudioModel>(this: m_pObject, ignoredArg: nullptr) != nullptr);
              v6 = (char *)ThisType;
              v3 = (v7 & 3) + 4;
            }
            else
            {
              v3 = 5;
            }
          }
          else if ( v6 == CMapSolid::__Type || v6 == CMapGroup::__Type )
          {
            v3 = (this->m_DstObjects.m_Size != 1) + 2;
          }
          else if ( v6 == CMapWorld::__Type )
          {
            v3 = 6;
          }
        }
        else if ( v6 != PrevType )
        {
          v3 = 8;
        }
        PrevType = v6;
        if ( ++pos >= this->m_DstObjects.m_Size )
          break;
        v4 = pos;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100D6360
// Name: public: int CObjectProperties::SetupPages(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectProperties::SetupPages(CObjectProperties *this)
{
  CObjectPage *ActivePage; // eax
  LayoutType_t Layout; // eax
  bool v4; // bl
  int v5; // eax
  CObjectPage **m_ppPages; // ecx
  bool v8; // zf
  int v9; // edi
  HWND ActiveWindow; // eax
  COP_Input *m_pInput; // ecx
  COP_Output *m_pOutput; // eax
  COP_Model *m_pModel; // eax
  COP_Flags *m_pFlags; // edx
  COP_Groups *m_pGroups; // ecx
  unsigned int i; // edi
  CObjectPage *m_pPage; // ebx
  bool v18; // al
  int v19; // eax
  unsigned int j; // edi
  unsigned int k; // edi
  int PageCount; // eax
  int m; // eax
  CObjectPage *v24; // ecx
  CObjectPage *v25; // edx
  int v26; // eax
  CObjectPage **v27; // ecx
  HWND v28; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-48h]
  CObjectProperties::SetupPages::__l21::<unnamed_type_pages> pages[6]; // [esp+8h] [ebp-38h]
  CWnd *pActiveWnd; // [esp+38h] [ebp-8h]
  bool bDisabledraw; // [esp+3Ch] [ebp-4h]
  bool bFlags; // [esp+3Dh] [ebp-3h]
  bool bModel; // [esp+3Eh] [ebp-2h]
  bool bGroups; // [esp+3Fh] [ebp-1h]

  if ( (unsigned int)eLastLayoutType >= ltSolid )
  {
    ActivePage = (CObjectPage *)CPropertySheet::GetActivePage(this);
    if ( ActivePage != nullptr )
      this->m_pLastActivePage = ActivePage;
  }
  Layout = CObjectProperties::GetLayout(this);
  v4 = false;
  bModel = false;
  bFlags = false;
  bGroups = false;
  switch ( Layout )
  {
    case ltSolid:
    case ltSolidMulti:
    case ltMulti:
      bGroups = true;
      break;
    case ltEntity:
    case ltEntityMulti:
    case ltModelEntity:
      v4 = true;
      bFlags = true;
      bGroups = true;
      bModel = Layout == ltModelEntity;
      break;
    case ltWorld:
      v4 = true;
      break;
    default:
      break;
  }
  if ( Layout == eLastLayoutType )
  {
    v5 = 0;
    if ( this->m_nPages <= 0 )
    {
LABEL_13:
      CPropertySheet::SetActivePage(this, nPage: 0);
      return 0;
    }
    else
    {
      m_ppPages = this->m_ppPages;
      while ( *m_ppPages != this->m_pLastActivePage )
      {
        ++v5;
        ++m_ppPages;
        if ( v5 >= this->m_nPages )
          goto LABEL_13;
      }
      CPropertySheet::SetActivePage(this, pPage: this->m_pLastActivePage);
      return 0;
    }
  }
  if ( Layout != ltNone && Layout != eLastValidLayoutType )
  {
    if ( Layout == ltEntity )
    {
      v8 = eLastValidLayoutType == ltModelEntity;
    }
    else
    {
      if ( Layout != ltModelEntity )
      {
LABEL_22:
        this->m_pLastActivePage = nullptr;
        eLastValidLayoutType = Layout;
        goto LABEL_23;
      }
      v8 = eLastValidLayoutType == ltEntity;
    }
    if ( !v8 )
      goto LABEL_22;
  }
LABEL_23:
  eLastLayoutType = Layout;
  CObjectPage::s_bRESTRUCTURING = 1;
  v9 = bModel + bFlags + bGroups + v4;
  ActiveWindow = GetActiveWindow();
  pActiveWnd = CWnd::FromHandle(hWnd: ActiveWindow);
  m_hWnd = this->m_hWnd;
  bDisabledraw = false;
  if ( IsWindow(hWnd: m_hWnd) && IsWindowVisible(hWnd: this->m_hWnd) )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    bDisabledraw = true;
  }
  if ( this->m_bDummy )
  {
    if ( v9 != 0 )
    {
      CPropertySheet::RemovePage(this, pPage: this->m_pDummy);
      this->m_bDummy = false;
    }
  }
  else if ( v9 == 0 )
  {
    CPropertySheet::AddPage(this, pPage: this->m_pDummy);
    this->m_bDummy = true;
  }
  m_pInput = this->m_pInput;
  m_pOutput = this->m_pOutput;
  pages[0].m_pPage = this->m_pEntity;
  pages[1].m_pPage = m_pOutput;
  m_pModel = this->m_pModel;
  pages[2].m_pPage = m_pInput;
  pages[3].m_bWantVisible = bModel;
  m_pFlags = this->m_pFlags;
  pages[3].m_pPage = m_pModel;
  pages[4].m_bWantVisible = bFlags;
  m_pGroups = this->m_pGroups;
  pages[0].m_bIsVisible = false;
  pages[0].m_bWantVisible = v4;
  pages[1].m_bIsVisible = false;
  pages[1].m_bWantVisible = v4;
  pages[2].m_bIsVisible = false;
  pages[2].m_bWantVisible = v4;
  pages[3].m_bIsVisible = false;
  pages[4].m_bIsVisible = false;
  pages[4].m_pPage = m_pFlags;
  pages[5].m_bIsVisible = false;
  pages[5].m_bWantVisible = bGroups;
  pages[5].m_pPage = m_pGroups;
  for ( i = 0; i < 6; ++i )
  {
    m_pPage = pages[i].m_pPage;
    v18 = CPropertySheet::GetPageIndex(this, pPage: m_pPage) != -1;
    pages[i].m_bIsVisible = v18;
    if ( v18 && !pages[i].m_bWantVisible )
    {
      CPropertySheet::RemovePage(this, pPage: m_pPage);
      pages[i].m_bIsVisible = false;
    }
  }
  v19 = 0;
  while ( pages[v19].m_bIsVisible || !pages[v19].m_bWantVisible )
  {
    if ( (unsigned int)++v19 >= 6 )
      goto LABEL_46;
  }
  for ( j = v19 + 1; j < 6; ++j )
  {
    if ( pages[j].m_bIsVisible )
    {
      CPropertySheet::RemovePage(this, pPage: pages[j].m_pPage);
      pages[j].m_bIsVisible = false;
    }
  }
LABEL_46:
  for ( k = 0; k < 6; ++k )
  {
    if ( !pages[k].m_bIsVisible && pages[k].m_bWantVisible )
      CPropertySheet::AddPage(this, pPage: pages[k].m_pPage);
  }
  if ( !this->m_bDummy )
  {
    operator delete(p: this->m_ppPages);
    PageCount = CPropertySheet::GetPageCount(this);
    this->m_nPages = PageCount;
    this->m_ppPages = (CObjectPage **)operator new[](nSize: 4 * PageCount);
    for ( m = 0; m < this->m_nPages; v25->m_bHasUpdatedData = false )
    {
      if ( m < 0 || m >= this->m_pages.m_nSize || (v24 = (CObjectPage *)this->m_pages.m_pData[m]) == nullptr )
        AfxThrowInvalidArgException();
      this->m_ppPages[m] = v24;
      this->m_ppPages[m]->m_bFirstTimeActive = true;
      v25 = this->m_ppPages[m++];
    }
  }
  v26 = 0;
  CObjectPage::s_bRESTRUCTURING = 0;
  if ( this->m_nPages <= 0 )
  {
LABEL_61:
    CPropertySheet::SetActivePage(this, nPage: 0);
  }
  else
  {
    v27 = this->m_ppPages;
    while ( *v27 != this->m_pLastActivePage )
    {
      ++v26;
      ++v27;
      if ( v26 >= this->m_nPages )
        goto LABEL_61;
    }
    CPropertySheet::SetActivePage(this, pPage: this->m_pLastActivePage);
  }
  if ( bDisabledraw )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: false);
  }
  CObjectProperties::UpdateOutputButton(this);
  CObjectProperties::UpdateInputButton(this);
  if ( pActiveWnd != nullptr )
  {
    v28 = SetActiveWindow(hWnd: pActiveWnd->m_hWnd);
    CWnd::FromHandle(hWnd: v28);
  }
  bFirstTime_0 = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D6760
// Name: public: void CObjectProperties::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::SaveData(CObjectProperties *this, SaveData_Reason_t reason)
{
  CMapDoc *v3; // ebx
  CHistory *History; // eax
  CMapClass *m_pObject; // edi
  CHistory *v6; // eax
  CHistory *v7; // eax
  int v8; // edi
  CObjectPage *v9; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-14h] [ebp-1Ch]
  CMapDoc *pDoc; // [esp+4h] [ebp-4h]

  if ( IsWindowVisible(hWnd: this->m_hWnd) && !this->m_bDataDirty )
  {
    v3 = CMapDoc::m_pMapDoc;
    pDoc = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr && this->m_DstObjects.m_Size != 0 && !this->m_bDummy )
    {
      List = CSelection::GetList(this: CMapDoc::m_pMapDoc->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Change Properties", bFromOpposite: 0);
      if ( this->m_DstObjects.m_Size == 1
        && (m_pObject = CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Element(
                          this: &this->m_DstObjects,
                          i: 0)->m_pObject,
            IsWorldObject(pObject: m_pObject)) )
      {
        v6 = GetHistory();
        CHistory::KeepNoChildren(this: v6, pObject: m_pObject);
      }
      else
      {
        v7 = GetHistory();
        CHistory::Keep(this: v7, pList: &this->m_DstObjects);
      }
      v8 = 0;
      if ( this->m_nPages > 0 )
      {
        do
        {
          if ( IsWindow(hWnd: this->m_ppPages[v8]->m_hWnd) )
          {
            v9 = this->m_ppPages[v8];
            if ( v9->m_bHasUpdatedData )
              ((void (__stdcall *)(SaveData_Reason_t))v9->SaveData)(a1: reason);
          }
          ++v8;
        }
        while ( v8 < this->m_nPages );
        v3 = pDoc;
      }
      v3->SetModifiedFlag(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6890
// Name: public: void CObjectProperties::LoadDataForPages(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::LoadDataForPages(CObjectProperties *this, int iPage)
{
  int m_Size; // eax
  int v4; // edx
  CMapClass *m_pObject; // ebx
  CObjectPage *v6; // ecx
  CRuntimeClass *v7; // eax
  CObjectPage *v8; // ecx
  int v9; // edi
  CObjectPage *v10; // ecx
  CObjectPage *v11; // eax
  CRuntimeClass *m_pEditObjectRuntimeClass; // eax
  CMapClass *v13; // eax
  CObjectPage *v14; // ecx
  CWnd *DlgItem; // eax
  CObjectPage *v16; // ecx
  int i; // edi
  CObjectPage *v18; // ecx
  CMapClass *pobj; // [esp+4h] [ebp-10h]
  bool bMultiEdit; // [esp+8h] [ebp-Ch]
  int pos; // [esp+Ch] [ebp-8h]
  int nMode; // [esp+10h] [ebp-4h]

  if ( this->m_bDummy )
    return;
  m_Size = this->m_DstObjects.m_Size;
  v4 = 0;
  bMultiEdit = m_Size > 1;
  this->m_bCanEdit = true;
  nMode = 0;
  pos = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = this->m_DstObjects.m_Memory.m_pMemory[v4 >> (*((int *)&this->m_DstObjects.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)].m_pObject;
      pobj = m_pObject;
      if ( !m_pObject->IsEditable(this: m_pObject) )
        this->m_bCanEdit = false;
      if ( iPage == -1 )
      {
        v9 = 0;
        if ( this->m_nPages <= 0 )
          goto LABEL_26;
        while ( 2 )
        {
          v10 = this->m_ppPages[v9];
          v10->SetMultiEdit(this: v10, a2: bMultiEdit);
          v11 = this->m_ppPages[v9];
          if ( !v11->m_bFirstTimeActive )
          {
            m_pEditObjectRuntimeClass = v11->m_pEditObjectRuntimeClass;
            if ( m_pEditObjectRuntimeClass == &editCMapClass::classeditCMapClass )
            {
              v13 = m_pObject;
LABEL_23:
              if ( v13 != nullptr )
              {
                v14 = this->m_ppPages[v9];
                v14->UpdateData(this: v14, a2: nMode, a3: v13, a4: this->m_bCanEdit);
                m_pObject = pobj;
                this->m_ppPages[v9]->m_bHasUpdatedData = true;
              }
            }
            else if ( m_pEditObjectRuntimeClass == &editCEditGameClass::classeditCEditGameClass
                   && (m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0
                    || m_pObject->IsMapClass(this: m_pObject, a2: CMapWorld::__Type) != 0) )
            {
              v13 = m_pObject + 1;
              goto LABEL_23;
            }
          }
          if ( ++v9 >= this->m_nPages )
            goto LABEL_26;
          continue;
        }
      }
      v6 = this->m_ppPages[iPage];
      v6->SetMultiEdit(this: v6, a2: bMultiEdit);
      v7 = this->m_ppPages[iPage]->m_pEditObjectRuntimeClass;
      if ( v7 != &editCMapClass::classeditCMapClass )
      {
        if ( v7 != &editCEditGameClass::classeditCEditGameClass
          || m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) == 0
          && m_pObject->IsMapClass(this: m_pObject, a2: CMapWorld::__Type) == 0 )
        {
          goto LABEL_26;
        }
        ++m_pObject;
      }
      if ( m_pObject != nullptr )
      {
        v8 = this->m_ppPages[iPage];
        v8->UpdateData(this: v8, a2: nMode, a3: m_pObject, a4: this->m_bCanEdit);
        this->m_ppPages[iPage]->m_bHasUpdatedData = true;
      }
LABEL_26:
      nMode = 1;
      if ( ++pos >= this->m_DstObjects.m_Size )
        break;
      v4 = pos;
    }
  }
  DlgItem = CWnd::GetDlgItem(this, nID: 12321);
  CWnd::EnableWindow(this: DlgItem, bEnable: this->m_bCanEdit);
  if ( iPage == -1 )
  {
    for ( i = 0; i < this->m_nPages; ++i )
    {
      v18 = this->m_ppPages[i];
      if ( !v18->m_bFirstTimeActive )
        v18->UpdateData(this: v18, a2: 2, a3: nullptr, a4: this->m_bCanEdit);
    }
  }
  else
  {
    v16 = this->m_ppPages[iPage];
    v16->UpdateData(this: v16, a2: 2, a3: nullptr, a4: this->m_bCanEdit);
  }
  CObjectProperties::UpdateOutputButton(this);
  CObjectProperties::UpdateInputButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D6BF0
// Name: protected: void CObjectProperties::AddObjectExpandGroups(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::AddObjectExpandGroups(CObjectProperties *this, CMapClass *pObject)
{
  bool (__thiscall *IsGroup)(CMapClass *); // edx
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CUtlReference<CMapClass> *v7; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  CObjectProperties *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  IsGroup = pObject->IsGroup;
  v9 = this;
  if ( IsGroup(this: pObject) )
  {
    for ( i = 0; i < pObject->m_Children.m_Size; ++i )
    {
      m_pObject = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&pObject->m_Children.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        src.m_pObject = pObject->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pObject->m_Children.m_Memory
                                                                                       + 2) >> 27)][i & ((32 * *((_DWORD *)&pObject->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        src.m_pNext = m_pObject->m_References.m_pHead;
        m_pHead = m_pObject->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
      }
      v10 = 0;
      CObjectProperties::AddObjectExpandGroups(this: v9, pObject: src.m_pObject);
      v10 = -1;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
    }
  }
  else
  {
    v7 = pObject->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = pObject;
    src.m_pNext = v7;
    if ( v7 != nullptr )
      v7->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObject->m_References.m_pHead = &src;
    v10 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: &this->m_DstObjects,
      elem: this->m_DstObjects.m_Size,
      &src);
    v10 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6DA0
// Name: protected: void CObjectProperties::ReloadData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::ReloadData(CObjectProperties *this)
{
  const CUtlReferenceVector<CMapClass> *m_pOrgObjects; // eax
  int v3; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  int m_Size; // eax
  CMapClass *v7; // edi
  const char *v8; // eax
  CManifestMap **v9; // ebx
  CMapEntity *v10; // eax
  CMapEntity *v11; // edi
  CMapInstance *ChildOf; // eax
  char szTitle[260]; // [esp+Ch] [ebp-124h] BYREF
  CManifest *pManifest; // [esp+110h] [ebp-20h]
  CMapDoc *pDoc; // [esp+114h] [ebp-1Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+118h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v17; // [esp+11Ch] [ebp-14h]
  CMapClass *pObject; // [esp+120h] [ebp-10h]
  int v19; // [esp+12Ch] [ebp-4h]

  pDoc = CMapDoc::m_pMapDoc;
  CWnd::EnableWindow(this, bEnable: 0);
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_DstObjects);
  m_pOrgObjects = this->m_pOrgObjects;
  if ( m_pOrgObjects != nullptr )
  {
    v3 = 0;
    if ( m_pOrgObjects->m_Size > 0 )
    {
      do
      {
        m_pObject = this->m_pOrgObjects->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_pOrgObjects->m_Memory
                                                                                     + 2) >> 27)][v3
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_pOrgObjects->m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          pObject = this->m_pOrgObjects->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_pOrgObjects->m_Memory
                                                                                     + 2) >> 27)][v3
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_pOrgObjects->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v5 = m_pObject->m_References.m_pHead;
          if ( v5 != nullptr )
            v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v17 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v19 = 0;
        CObjectProperties::AddObjectExpandGroups(this, pObject);
        v19 = -1;
        if ( pObject != nullptr )
        {
          if ( v17 != nullptr )
          {
            v17->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v17;
          }
          else if ( (CUtlReference<CMapClass> **)pObject->m_References.m_pHead == &m_pHead )
          {
            pObject->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v17 = nullptr;
          m_pHead = nullptr;
          pObject = nullptr;
        }
        ++v3;
      }
      while ( v3 < this->m_pOrgObjects->m_Size );
    }
  }
  CWnd::ShowWindow(this: this->m_pInstanceButton, nCmdShow: 0);
  m_Size = this->m_DstObjects.m_Size;
  if ( m_Size != 1 )
  {
    if ( m_Size <= 1 )
      CWnd::SetWindowTextA(this, lpszString: "Object Properties");
    else
      CWnd::SetWindowTextA(this, lpszString: "Object Properties: multiple objects");
LABEL_36:
    CObjectProperties::SetupPages(this);
    CObjectProperties::LoadDataForPages(this, iPage: -1);
    CWnd::EnableWindow(this, bEnable: 1);
    this->m_bDataDirty = false;
    return;
  }
  v7 = (*this->m_DstObjects.m_Memory.m_pMemory)->m_pObject;
  CMapClass::CopyFrom(this: &e_CMapClass.CMapClass, pFrom: (CVisGroup *)v7, bUpdateDependencies: false);
  if ( v7->IsMapClass(this: v7, a2: CMapEntity::__Type) != 0 || v7->IsMapClass(this: v7, a2: CMapWorld::__Type) != 0 )
    CEditGameClass::CopyFrom(this: &e_CEditGameClass.CEditGameClass, pFrom: (CEditGameClass *)&v7[1]);
  v8 = v7->GetDescription(this: v7);
  sprintf(string: szTitle, format: "Object Properties: %s", v8);
  CWnd::SetWindowTextA(this, lpszString: szTitle);
  v9 = (CManifestMap **)__RTDynamicCast(
                          inptr: v7,
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CManifestInstance `RTTI Type Descriptor',
                          isReference: 0);
  if ( v9 == nullptr || (pManifest = CMapDoc::m_pManifest, CMapDoc::m_pManifest == nullptr) )
  {
    v10 = (CMapEntity *)__RTDynamicCast(
                          inptr: v7,
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CMapEntity `RTTI Type Descriptor',
                          isReference: 0);
    v11 = v10;
    if ( v10 != nullptr )
    {
      if ( _V_stricmp(s1: v10->m_szClass, s2: "func_instance") != 0 )
      {
        if ( _V_stricmp(s1: v11->m_szClass, s2: "func_instance_parms") == 0 && pDoc != nullptr )
          CMapDoc::PopulateInstanceParms(this: pDoc, pEntity: v11);
      }
      else
      {
        CMapDoc::PopulateInstance(this: pDoc, pEntity: v11);
        ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: v11, ignoredArg: nullptr);
        if ( ChildOf != nullptr && ChildOf->m_pInstancedMap != nullptr )
          CWnd::ShowWindow(this: this->m_pInstanceButton, nCmdShow: 5);
      }
    }
    goto LABEL_36;
  }
  CWnd::ShowWindow(this, nCmdShow: 0);
  if ( pDoc != nullptr )
    CMapDoc::UpdateAllViews(this: pDoc, nFlags: 2072, ub: nullptr);
  CManifest::SetPrimaryMap(this: pManifest, a2: (int)v7, pManifestMap: v9[97]);
}

//------------------------------------------------------------------------------
// Address: 0x100D70A0
// Name: protected: void CObjectProperties::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnPaint(CObjectProperties *this)
{
  CPaintDC dc; // [esp+4h] [ebp-60h] BYREF
  int v3; // [esp+60h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v3 = 0;
  if ( this->m_bDataDirty )
    CObjectProperties::ReloadData(this);
  v3 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100D7100
// Name: protected: void CObjectProperties::ApplyChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::ApplyChanges(CObjectProperties *this, bool bCalledOnClose)
{
  CMapDoc *v3; // ebx
  int v4; // edi
  CObjectPage *v5; // ecx
  int i; // edi
  CMapClass *m_pObject; // ecx
  char bLocked; // [esp+7h] [ebp-1h]

  if ( this->m_bCanEdit )
  {
    v3 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v4 = 0;
      bLocked = CMapDoc::VisGroups_LockUpdates(this: CMapDoc::m_pMapDoc, bLock: true);
      if ( this->m_nPages <= 0 )
      {
LABEL_6:
        CObjectProperties::SaveData(this, reason: (SaveData_Reason_t)!bCalledOnClose);
        CObjectProperties::ReloadData(this);
        for ( i = 0; i < this->m_DstObjects.m_Size; ++i )
        {
          m_pObject = this->m_DstObjects.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_DstObjects.m_Memory
                                                                                    + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
            m_pObject->OnApply(this: m_pObject);
        }
        if ( bLocked != 0 )
          CMapDoc::VisGroups_LockUpdates(this: v3, bLock: false);
      }
      else
      {
        while ( 1 )
        {
          v5 = this->m_ppPages[v4];
          if ( v5->OnApply(this: v5) == 0 )
            break;
          if ( ++v4 >= this->m_nPages )
            goto LABEL_6;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D71E0
// Name: protected: void CObjectProperties::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnApply(CObjectProperties *this)
{
  CObjectProperties::ApplyChanges(this, bCalledOnClose: false);
}

//------------------------------------------------------------------------------
// Address: 0x100D71F0
// Name: protected: void CObjectProperties::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnCancel(CObjectProperties *this)
{
  CWnd::ShowWindow(this, nCmdShow: 0);
  CObjectProperties::ReloadData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7210
// Name: public: void CObjectProperties::MarkDataDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::MarkDataDirty(CObjectProperties *this)
{
  int i; // esi
  CObjectPage *v3; // ecx
  CObjectPage *v4; // ecx
  int j; // edi
  CUtlReference<CMapClass> *v6; // eax
  CMapClass *m_pObject; // ecx
  CUtlReference<CMapClass> *m_pPrev; // edx
  CUtlReference<CMapClass> *m_pNext; // edx

  if ( !this->m_bDataDirty )
  {
    for ( i = 0; i < this->m_nPages; ++i )
    {
      v3 = this->m_ppPages[i];
      if ( v3->m_hWnd != nullptr )
      {
        v3->RememberState(this: v3);
        v4 = this->m_ppPages[i];
        v4->MarkDataDirty(this: v4);
      }
    }
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: false);
    for ( j = 0; j < this->m_DstObjects.m_Size; ++j )
    {
      v6 = &this->m_DstObjects.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&this->m_DstObjects.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->m_DstObjects.m_Memory + 2)) >> 5)];
      m_pObject = v6->m_pObject;
      if ( m_pObject != nullptr )
      {
        m_pPrev = v6->m_pPrev;
        if ( m_pPrev != nullptr )
        {
          m_pPrev->m_pNext = v6->m_pNext;
          if ( v6->m_pNext != nullptr )
            v6->m_pNext->m_pPrev = v6->m_pPrev;
        }
        else if ( m_pObject->m_References.m_pHead == v6 )
        {
          m_pNext = v6->m_pNext;
          m_pObject->m_References.m_pHead = v6->m_pNext;
          if ( m_pNext != nullptr )
            m_pNext->m_pPrev = nullptr;
        }
        v6->m_pPrev = nullptr;
        v6->m_pNext = nullptr;
        v6->m_pObject = nullptr;
      }
    }
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &this->m_DstObjects);
    this->m_bDataDirty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7310
// Name: public: virtual CObjectProperties::~CObjectProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::~CObjectProperties(CObjectProperties *this)
{
  CPropertyPage *m_pDummy; // ecx
  COP_Entity *m_pEntity; // ecx
  COP_Flags *m_pFlags; // ecx
  COP_Groups *m_pGroups; // ecx
  COP_Output *m_pOutput; // ecx
  COP_Input *m_pInput; // ecx
  COP_Model *m_pModel; // ecx
  CButton *m_pInputButton; // ecx
  CButton *m_pOutputButton; // ecx
  CButton *m_pInstanceButton; // ecx

  this->__vftable = (CObjectProperties_vtbl *)&CObjectProperties::`vftable';
  m_pDummy = this->m_pDummy;
  if ( m_pDummy != nullptr )
    ((void (__thiscall *)(CPropertyPage *, int))m_pDummy->dtr_CObject)(a1: m_pDummy, a2: 1);
  m_pEntity = this->m_pEntity;
  if ( m_pEntity != nullptr )
    ((void (__thiscall *)(COP_Entity *, int))m_pEntity->dtr_CObject)(a1: m_pEntity, a2: 1);
  m_pFlags = this->m_pFlags;
  if ( m_pFlags != nullptr )
    ((void (__thiscall *)(COP_Flags *, int))m_pFlags->dtr_CObject)(a1: m_pFlags, a2: 1);
  m_pGroups = this->m_pGroups;
  if ( m_pGroups != nullptr )
    ((void (__thiscall *)(COP_Groups *, int))m_pGroups->dtr_CObject)(a1: m_pGroups, a2: 1);
  m_pOutput = this->m_pOutput;
  if ( m_pOutput != nullptr )
    ((void (__thiscall *)(COP_Output *, int))m_pOutput->dtr_CObject)(a1: m_pOutput, a2: 1);
  m_pInput = this->m_pInput;
  if ( m_pInput != nullptr )
    ((void (__thiscall *)(COP_Input *, int))m_pInput->dtr_CObject)(a1: m_pInput, a2: 1);
  m_pModel = this->m_pModel;
  if ( m_pModel != nullptr )
    ((void (__thiscall *)(COP_Model *, int))m_pModel->dtr_CObject)(a1: m_pModel, a2: 1);
  m_pInputButton = this->m_pInputButton;
  if ( m_pInputButton != nullptr )
    ((void (__thiscall *)(CButton *, int))m_pInputButton->dtr_CObject)(a1: m_pInputButton, a2: 1);
  m_pOutputButton = this->m_pOutputButton;
  if ( m_pOutputButton != nullptr )
    ((void (__thiscall *)(CButton *, int))m_pOutputButton->dtr_CObject)(a1: m_pOutputButton, a2: 1);
  m_pInstanceButton = this->m_pInstanceButton;
  if ( m_pInstanceButton != nullptr )
    ((void (__thiscall *)(CButton *, int))m_pInstanceButton->dtr_CObject)(a1: m_pInstanceButton, a2: 1);
  operator delete(p: this->m_ppPages);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_DstObjects);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_AnchorMgr);
  CPropertySheet::~CPropertySheet(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7450
// Name: public: void CObjectProperties::SetPageToOutput(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::SetPageToOutput(CObjectProperties *this, CEntityConnection *pConnection)
{
  if ( this->m_bDataDirty )
    CObjectProperties::ReloadData(this);
  CPropertySheet::SetActivePage(this, pPage: this->m_pOutput);
  COP_Output::SetSelectedConnection(this: this->m_pOutput, pConnection);
}

//------------------------------------------------------------------------------
// Address: 0x100D7490
// Name: public: void CObjectProperties::SetPageToInput(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::SetPageToInput(CObjectProperties *this, CEntityConnection *pConnection)
{
  if ( this->m_bDataDirty )
    CObjectProperties::ReloadData(this);
  CPropertySheet::SetActivePage(this, pPage: this->m_pInput);
  COP_Input::SetSelectedConnection(this: this->m_pInput, pConnection);
}

//------------------------------------------------------------------------------
// Address: 0x100D74D0
// Name: protected: void CObjectProperties::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnClose(CObjectProperties *this)
{
  CObjectProperties::ApplyChanges(this, bCalledOnClose: true);
  CWnd::ShowWindow(this, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D74F0
// Name: protected: void CObjectProperties::OnEditInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::OnEditInstance(CObjectProperties *this)
{
  CMapClass *v2; // ebx
  CMapClass *i; // eax
  CMapInstance *v4; // esi
  EnumChildrenPos_t pos; // [esp+4h] [ebp-84h] BYREF

  if ( this->m_DstObjects.m_Size == 1 )
  {
    v2 = (CMapClass *)__RTDynamicCast(
                        inptr: (*this->m_DstObjects.m_Memory.m_pMemory)->m_pObject,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapEntity `RTTI Type Descriptor',
                        isReference: 0);
    if ( v2 != nullptr )
    {
      for ( i = CMapClass::GetFirstDescendent(this: v2, (CMapClass *)&pos);
            i != nullptr;
            i = CMapClass::GetNextDescendent(this: v2, (CMapClass *)&pos) )
      {
        v4 = (CMapInstance *)__RTDynamicCast(
                               inptr: i,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapInstance `RTTI Type Descriptor',
                               isReference: 0);
        if ( v4 != nullptr )
        {
          CObjectProperties::ApplyChanges(this, bCalledOnClose: true);
          CWnd::ShowWindow(this, nCmdShow: 0);
          CMapInstance::SwitchTo(this: v4);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D75B0
// Name: public: void CObjectProperties::SetObjectList(class CUtlReferenceVector<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectProperties::SetObjectList(
        CObjectProperties *this,
        const CUtlReferenceVector<CMapClass> *pObjectList)
{
  this->m_pOrgObjects = pObjectList;
  CObjectProperties::MarkDataDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D75D0
// Name: protected: static struct AFX_MSGMAP const __near * CObjectProperties::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CObjectProperties::GetThisMessageMap()
{
  if ( (_S1_15 & 1) == 0 )
  {
    _S1_15 |= 1u;
    messageEntries_46[8].nID = 12321;
    messageEntries_46[8].nLastID = 12321;
    messageEntries_46[9].nID = 2;
    messageEntries_46[9].nLastID = 2;
    messageEntries_46[2].nSig = 19;
    messageEntries_46[3].nSig = 19;
    messageEntries_46[6].nMessage = 1;
    messageEntries_46[7].nID = 1;
    messageEntries_46[7].nLastID = 1;
    messageEntries_46[10].nID = 312;
    messageEntries_46[10].nLastID = 312;
    messageEntries_46[7].nMessage = 273;
    messageEntries_46[8].nMessage = 273;
    messageEntries_46[9].nMessage = 273;
    messageEntries_46[10].nMessage = 273;
    messageEntries_46[11].nMessage = 273;
    messageEntries_46[12].nMessage = 273;
    messageEntries_46[0].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHelpInfo;
    messageEntries_46[1].nMessage = 6;
    messageEntries_46[1].nCode = 0;
    messageEntries_46[1].nID = 0;
    messageEntries_46[1].nLastID = 0;
    messageEntries_46[1].nSig = 41;
    messageEntries_46[1].pfn = (void (__thiscall *)(CCmdTarget *))CMyComboBox::OnChar;
    messageEntries_46[2].nMessage = 16;
    messageEntries_46[2].nCode = 0;
    messageEntries_46[2].nID = 0;
    messageEntries_46[2].nLastID = 0;
    messageEntries_46[2].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnClose;
    messageEntries_46[3].nMessage = 15;
    messageEntries_46[3].nCode = 0;
    messageEntries_46[3].nID = 0;
    messageEntries_46[3].nLastID = 0;
    messageEntries_46[3].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnPaint;
    messageEntries_46[4].nMessage = 5;
    messageEntries_46[4].nCode = 0;
    messageEntries_46[4].nID = 0;
    messageEntries_46[4].nLastID = 0;
    messageEntries_46[4].nSig = 25;
    messageEntries_46[4].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnSize;
    messageEntries_46[5].nMessage = 24;
    messageEntries_46[5].nCode = 0;
    messageEntries_46[5].nID = 0;
    messageEntries_46[5].nLastID = 0;
    messageEntries_46[5].nSig = 21;
    messageEntries_46[5].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnShowWindow;
    messageEntries_46[6].nCode = 0;
    messageEntries_46[6].nID = 0;
    messageEntries_46[6].nLastID = 0;
    messageEntries_46[6].nSig = 13;
    messageEntries_46[6].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnCreate;
    messageEntries_46[7].nCode = 0;
    messageEntries_46[7].nSig = 57;
    messageEntries_46[7].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnApply;
    messageEntries_46[8].nCode = 0;
    messageEntries_46[8].nSig = 57;
    messageEntries_46[8].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnApply;
    messageEntries_46[9].nCode = 0;
    messageEntries_46[9].nSig = 57;
    messageEntries_46[9].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnCancel;
    messageEntries_46[10].nCode = 0;
    messageEntries_46[10].nSig = 57;
    messageEntries_46[10].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnInputs;
    messageEntries_46[11].nCode = 0;
    messageEntries_46[11].nID = 314;
    messageEntries_46[11].nLastID = 314;
    messageEntries_46[11].nSig = 57;
    messageEntries_46[11].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnOutputs;
    messageEntries_46[12].nCode = 0;
    messageEntries_46[12].nID = 339;
    messageEntries_46[12].nLastID = 339;
    messageEntries_46[12].nSig = 57;
    messageEntries_46[12].pfn = (void (__thiscall *)(CCmdTarget *))CObjectProperties::OnEditInstance;
    messageEntries_46[13].nMessage = 0;
    messageEntries_46[13].nCode = 0;
    messageEntries_46[13].nID = 0;
    messageEntries_46[13].nLastID = 0;
    messageEntries_46[13].nSig = 0;
    messageEntries_46[13].pfn = nullptr;
  }
  return &messageMap_6;
}

//------------------------------------------------------------------------------
// Address: 0x100D7860
// Name: public: CObjectProperties::CObjectProperties(void)
// Source: json
//------------------------------------------------------------------------------
CObjectProperties *__thiscall CObjectProperties::CObjectProperties(CObjectProperties *this)
{
  CPropertySheet::CPropertySheet(this);
  this->__vftable = (CObjectProperties_vtbl *)&CObjectProperties::`vftable';
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  this->m_DstObjects.m_Memory.m_pMemory = nullptr;
  this->m_DstObjects.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_DstObjects.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_DstObjects.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_DstObjects.m_Size = 0;
  this->m_DstObjects.m_pElements = nullptr;
  this->m_bDummy = false;
  this->m_pDummy = nullptr;
  this->m_pInputButton = nullptr;
  this->m_pOutputButton = nullptr;
  this->m_pInstanceButton = nullptr;
  this->m_pOrgObjects = nullptr;
  *(_WORD *)&this->m_bDataDirty = 0;
  CObjectProperties::CreatePages(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7950
// Name: protected: virtual struct AFX_MSGMAP const __near * CObjectProperties::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall CObjectProperties::GetMessageMap(CObjectProperties *this)
{
  return CObjectProperties::GetThisMessageMap();
}

//------------------------------------------------------------------------------
// Address: 0x102B1AD0
// Name: public: virtual char const __near * CMapClass::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapClass::GetDescription(CEmptyConVar *this)
{
  return &var;
}

//------------------------------------------------------------------------------
// Address: 0x10339943
// Name: public: static int CWnd::ModifyStyle(struct HWND__ __near *,unsigned long,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWnd::ModifyStyle(HWND__ *hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
{
  return _AfxModifyStyle(hWnd, nStyleOffset: -16, dwRemove, dwAdd, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1033995F
// Name: public: static int CWnd::ModifyStyleEx(struct HWND__ __near *,unsigned long,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWnd::ModifyStyleEx(HWND__ *hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
{
  return _AfxModifyStyle(hWnd, nStyleOffset: -20, dwRemove, dwAdd, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1033997B
// Name: public: virtual class CMenu __near * CWnd::GetMenu(void)const
// Source: json
//------------------------------------------------------------------------------
CMenu *__thiscall CWnd::GetMenu(CWnd *this)
{
  HMENU Menu; // eax

  Menu = GetMenu(hWnd: this->m_hWnd);
  return CMenu::FromHandle(hMenu: Menu);
}

//------------------------------------------------------------------------------
// Address: 0x1033998B
// Name: public: virtual void CWnd::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnFinalRelease(CWnd *this)
{
  CWnd_vtbl *v1; // eax

  v1 = this->__vftable;
  if ( this->m_hWnd != nullptr )
    ((void (*)(void))v1->DestroyWindow)();
  else
    ((void (*)(void))v1->PostNcDestroy)();
}

//------------------------------------------------------------------------------
// Address: 0x1033999C
// Name: protected: virtual long CWnd::DefWindowProcA(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CWnd::DefWindowProcA(CWnd *this, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
  int (__stdcall *m_pfnSuper)(HWND__ *, unsigned int, unsigned int, int); // eax

  m_pfnSuper = this->m_pfnSuper;
  if ( m_pfnSuper != nullptr )
    return CallWindowProcA(lpPrevWndFunc: m_pfnSuper, hWnd: this->m_hWnd, Msg: nMsg, wParam, lParam);
  m_pfnSuper = *this->GetSuperWndProcAddr(this);
  if ( m_pfnSuper != nullptr )
    return CallWindowProcA(lpPrevWndFunc: m_pfnSuper, hWnd: this->m_hWnd, Msg: nMsg, wParam, lParam);
  else
    return DefWindowProcA(hWnd: this->m_hWnd, Msg: nMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103399E5
// Name: protected: virtual long (*__near * CWnd::GetSuperWndProcAddr(void))(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int (__stdcall **__thiscall CWnd::GetSuperWndProcAddr(CWnd *this))(HWND__ *, unsigned int, unsigned int, int)
{
  return &this->m_pfnSuper;
}

//------------------------------------------------------------------------------
// Address: 0x103399E9
// Name: public: virtual int CWnd::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::PreTranslateMessage(CWnd *this, tagMSG *pMsg)
{
  void (__stdcall *m_pfnFilterToolTipMessage)(tagMSG *, CWnd *); // eax

  m_pfnFilterToolTipMessage = AfxGetModuleState()->m_pfnFilterToolTipMessage;
  if ( m_pfnFilterToolTipMessage != nullptr )
    m_pfnFilterToolTipMessage(a1: pMsg, a2: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10339A0A
// Name: public: virtual int CWnd::OnToolHitTest(class CPoint,struct tagTOOLINFOA __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnToolHitTest(CWnd *this, CPoint point, tagTOOLINFOA *pTI)
{
  HWND__ *v4; // eax
  HWND v5; // edi
  HWND__ *m_hWnd; // eax
  int nHit; // [esp+8h] [ebp-4h]

  v4 = _AfxTopChildWindowFromPoint(hWnd: this->m_hWnd, pt: point.tagPOINT);
  v5 = v4;
  if ( v4 == nullptr )
    return -1;
  nHit = GetDlgCtrlID(hWnd: v4);
  if ( pTI != nullptr && pTI->cbSize >= 0x2C )
  {
    m_hWnd = this->m_hWnd;
    pTI->uFlags |= 1u;
    pTI->lpszText = (char *)-1;
    pTI->hwnd = m_hWnd;
    pTI->uId = (unsigned int)v5;
    if ( (SendMessageA(hWnd: v5, Msg: 0x87u, wParam: 0, lParam: 0) & 0x2000) == 0 )
      pTI->uFlags |= 0x80000002;
  }
  return nHit;
}

//------------------------------------------------------------------------------
// Address: 0x10339A7D
// Name: public: int CWnd::GetWindowPlacement(struct tagWINDOWPLACEMENT __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::GetWindowPlacement(CWnd *this, tagWINDOWPLACEMENT *lpwndpl)
{
  lpwndpl->length = 44;
  return GetWindowPlacement(hWnd: this->m_hWnd, lpwndpl);
}

//------------------------------------------------------------------------------
// Address: 0x10339A99
// Name: public: int CWnd::SetWindowPlacement(struct tagWINDOWPLACEMENT const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::SetWindowPlacement(CWnd *this, const tagWINDOWPLACEMENT *lpwndpl)
{
  lpwndpl->length = 44;
  return SetWindowPlacement(hWnd: this->m_hWnd, lpwndpl);
}

//------------------------------------------------------------------------------
// Address: 0x10339B01
// Name: protected: virtual long CWnd::WindowProc(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::WindowProc(CWnd *this, unsigned int message, unsigned int wParam, int lParam)
{
  int lResult; // [esp+4h] [ebp-4h] BYREF

  lResult = 0;
  if ( this->OnWndMsg(this, a2: message, a3: wParam, a4: lParam, a5: &lResult) == 0 )
    return this->DefWindowProcA(this, a2: message, a3: wParam, a4: lParam);
  return lResult;
}

//------------------------------------------------------------------------------
// Address: 0x10339B78
// Name: public: int CWnd::SetScrollInfo(int,struct tagSCROLLINFO __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SetScrollInfo(CWnd *this, int nBar, tagSCROLLINFO *lpScrollInfo, BOOL bRedraw)
{
  HWND__ *m_hWnd; // esi
  int v5; // edi
  CScrollBar *v6; // eax

  m_hWnd = this->m_hWnd;
  v5 = nBar;
  if ( nBar != 2 )
  {
    v6 = this->GetScrollBarCtrl(this, a2: nBar);
    if ( v6 != nullptr )
    {
      m_hWnd = v6->m_hWnd;
      v5 = 2;
    }
  }
  lpScrollInfo->cbSize = 28;
  SetScrollInfo(hwnd: m_hWnd, nBar: v5, lpsi: lpScrollInfo, redraw: bRedraw);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10339BB8
// Name: public: int CWnd::GetScrollInfo(int,struct tagSCROLLINFO __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::GetScrollInfo(CWnd *this, int nBar, tagSCROLLINFO *lpScrollInfo, unsigned int nMask)
{
  HWND__ *m_hWnd; // esi
  int v5; // edi
  CScrollBar *v6; // eax

  m_hWnd = this->m_hWnd;
  v5 = nBar;
  if ( nBar != 2 )
  {
    v6 = this->GetScrollBarCtrl(this, a2: nBar);
    if ( v6 != nullptr )
    {
      m_hWnd = v6->m_hWnd;
      v5 = 2;
    }
  }
  lpScrollInfo->cbSize = 28;
  lpScrollInfo->fMask = nMask;
  return GetScrollInfo(hwnd: m_hWnd, nBar: v5, lpsi: lpScrollInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10339CAC
// Name: public: virtual void CWnd::CalcWindowRect(struct tagRECT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::CalcWindowRect(CWnd *this, tagRECT *lpClientRect, unsigned int nAdjustType)
{
  unsigned int v4; // eax
  DWORD Style; // eax
  DWORD v6; // [esp-4h] [ebp-8h]

  v4 = CWnd::GetExStyle(this);
  if ( nAdjustType == 0 )
    v4 &= ~0x200u;
  v6 = v4;
  Style = CWnd::GetStyle(this);
  AdjustWindowRectEx(lpRect: lpClientRect, dwStyle: Style, bMenu: false, dwExStyle: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10339CDD
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * CWnd::GetInterfaceMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall CWnd::GetInterfaceMap(CWnd *this)
{
  return &CWnd::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x1033A2F3
// Name: public: virtual long CWnd::EnsureStdObj(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::EnsureStdObj(CWnd *this)
{
  HRESULT result; // eax

  if ( this->m_pStdObject != nullptr )
    return 0;
  result = CreateStdAccessibleObject(
             hwnd: this->m_hWnd,
             idObject: -4,
             riid: &_GUID_618736e0_3c3d_11cf_810c_00aa00389b71,
             ppvObject: (void **)&this->m_pStdObject);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033A312
// Name: public: virtual long CWnd::get_accParent(struct IDispatch __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accParent(CWnd *this, IDispatch **ppdispParent)
{
  return this->m_pStdObject->get_accParent(this: this->m_pStdObject, a2: ppdispParent);
}

//------------------------------------------------------------------------------
// Address: 0x1033A327
// Name: public: virtual long CWnd::get_accChildCount(long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accChildCount(CWnd *this, int *pcountChildren)
{
  return this->m_pStdObject->get_accChildCount(this: this->m_pStdObject, a2: pcountChildren);
}

//------------------------------------------------------------------------------
// Address: 0x1033A33C
// Name: public: virtual long CWnd::get_accChild(struct tagVARIANT,struct IDispatch __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accChild(CWnd *this, tagVARIANT varChild, IDispatch **ppdispChild)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, IDispatch **))this->m_pStdObject->get_accChild)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: ppdispChild);
}

//------------------------------------------------------------------------------
// Address: 0x1033A361
// Name: public: virtual long CWnd::get_accName(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accName(CWnd *this, tagVARIANT varChild, wchar_t **pszName)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accName)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszName);
}

//------------------------------------------------------------------------------
// Address: 0x1033A386
// Name: public: virtual long CWnd::get_accValue(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accValue(CWnd *this, tagVARIANT varChild, wchar_t **pszValue)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accValue)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1033A3AB
// Name: public: virtual long CWnd::get_accDescription(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accDescription(CWnd *this, tagVARIANT varChild, wchar_t **pszDescription)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accDescription)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszDescription);
}

//------------------------------------------------------------------------------
// Address: 0x1033A3D0
// Name: public: virtual long CWnd::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accRole(CWnd *this, tagVARIANT varChild, tagVARIANT *pvarRole)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))this->m_pStdObject->get_accRole)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pvarRole);
}

//------------------------------------------------------------------------------
// Address: 0x1033A3F5
// Name: public: virtual long CWnd::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accState(CWnd *this, tagVARIANT varChild, tagVARIANT *pvarState)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))this->m_pStdObject->get_accState)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pvarState);
}

//------------------------------------------------------------------------------
// Address: 0x1033A41A
// Name: public: virtual long CWnd::get_accHelp(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accHelp(CWnd *this, tagVARIANT varChild, wchar_t **pszHelp)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accHelp)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszHelp);
}

//------------------------------------------------------------------------------
// Address: 0x1033A43F
// Name: public: virtual long CWnd::get_accHelpTopic(wchar_t __near * __near *,struct tagVARIANT,long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accHelpTopic(CWnd *this, wchar_t **pszHelpFile, tagVARIANT varChild, int *pidTopic)
{
  return ((HRESULT (__stdcall *)(IAccessible *, wchar_t **, _DWORD, unsigned int, unsigned int, unsigned int, int *))this->m_pStdObject->get_accHelpTopic)(
           a1: this->m_pStdObject,
           a2: pszHelpFile,
           a3: *(_DWORD *)&varChild.vt,
           a4: varChild.decVal.Hi32,
           a5: varChild.decVal.Lo32,
           a6: varChild.decVal.Mid32,
           a7: pidTopic);
}

//------------------------------------------------------------------------------
// Address: 0x1033A467
// Name: public: virtual long CWnd::get_accKeyboardShortcut(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accKeyboardShortcut(CWnd *this, tagVARIANT varChild, wchar_t **pszKeyboardShortcut)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accKeyboardShortcut)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszKeyboardShortcut);
}

//------------------------------------------------------------------------------
// Address: 0x1033A48C
// Name: public: virtual long CWnd::get_accFocus(struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accFocus(CWnd *this, tagVARIANT *pvarChild)
{
  return this->m_pStdObject->get_accFocus(this: this->m_pStdObject, a2: pvarChild);
}

//------------------------------------------------------------------------------
// Address: 0x1033A4A1
// Name: public: virtual long CWnd::get_accSelection(struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accSelection(CWnd *this, tagVARIANT *pvarChildren)
{
  return this->m_pStdObject->get_accSelection(this: this->m_pStdObject, a2: pvarChildren);
}

//------------------------------------------------------------------------------
// Address: 0x1033A4B6
// Name: public: virtual long CWnd::get_accDefaultAction(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::get_accDefaultAction(CWnd *this, tagVARIANT varChild, wchar_t **pszDefaultAction)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))this->m_pStdObject->get_accDefaultAction)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: pszDefaultAction);
}

//------------------------------------------------------------------------------
// Address: 0x1033A4DB
// Name: public: virtual long CWnd::accSelect(long,struct tagVARIANT)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::accSelect(CWnd *this, int flagsSelect, tagVARIANT varChild)
{
  return ((HRESULT (__stdcall *)(IAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int))this->m_pStdObject->accSelect)(
           a1: this->m_pStdObject,
           a2: flagsSelect,
           a3: *(_DWORD *)&varChild.vt,
           a4: varChild.decVal.Hi32,
           a5: varChild.decVal.Lo32,
           a6: varChild.decVal.Mid32);
}

//------------------------------------------------------------------------------
// Address: 0x1033A500
// Name: public: virtual long CWnd::accLocation(long __near *,long __near *,long __near *,long __near *,struct tagVARIANT)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::accLocation(
        CWnd *this,
        int *pxLeft,
        int *pyTop,
        int *pcxWidth,
        int *pcyHeight,
        tagVARIANT varChild)
{
  return ((HRESULT (__stdcall *)(IAccessible *, int *, int *, int *, int *, _DWORD, unsigned int, unsigned int, unsigned int))this->m_pStdObject->accLocation)(
           a1: this->m_pStdObject,
           a2: pxLeft,
           a3: pyTop,
           a4: pcxWidth,
           a5: pcyHeight,
           a6: *(_DWORD *)&varChild.vt,
           a7: varChild.decVal.Hi32,
           a8: varChild.decVal.Lo32,
           a9: varChild.decVal.Mid32);
}

//------------------------------------------------------------------------------
// Address: 0x1033A52E
// Name: public: virtual long CWnd::accNavigate(long,struct tagVARIANT,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::accNavigate(CWnd *this, int navDir, tagVARIANT varStart, tagVARIANT *pvarEndUpAt)
{
  return ((HRESULT (__stdcall *)(IAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))this->m_pStdObject->accNavigate)(
           a1: this->m_pStdObject,
           a2: navDir,
           a3: *(_DWORD *)&varStart.vt,
           a4: varStart.decVal.Hi32,
           a5: varStart.decVal.Lo32,
           a6: varStart.decVal.Mid32,
           a7: pvarEndUpAt);
}

//------------------------------------------------------------------------------
// Address: 0x1033A556
// Name: public: virtual long CWnd::accHitTest(long,long,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::accHitTest(CWnd *this, int xLeft, int yTop, tagVARIANT *pvarChild)
{
  return this->m_pStdObject->accHitTest(this: this->m_pStdObject, a2: xLeft, a3: yTop, a4: pvarChild);
}

//------------------------------------------------------------------------------
// Address: 0x1033A571
// Name: public: virtual long CWnd::accDoDefaultAction(struct tagVARIANT)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::accDoDefaultAction(CWnd *this, tagVARIANT varChild)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int))this->m_pStdObject->accDoDefaultAction)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32);
}

//------------------------------------------------------------------------------
// Address: 0x1033A593
// Name: public: virtual long CWnd::put_accValue(struct tagVARIANT,wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::put_accValue(CWnd *this, tagVARIANT varChild, wchar_t *szValue)
{
  return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t *))this->m_pStdObject->put_accName)(
           a1: this->m_pStdObject,
           a2: *(_DWORD *)&varChild.vt,
           a3: varChild.decVal.Hi32,
           a4: varChild.decVal.Lo32,
           a5: varChild.decVal.Mid32,
           a6: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x1033A5B8
// Name: public: virtual long CWnd::SetProxy(struct IAccessibleProxy __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::SetProxy(CWnd *this, IAccessibleProxy *pProxy)
{
  this->m_pProxy = pProxy;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033A5C9
// Name: public: static int CWnd::GrayCtlColor(struct HDC__ __near *,struct HWND__ __near *,unsigned int,struct HBRUSH__ __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWnd::GrayCtlColor(HDC__ *hDC, HWND__ *hWnd, unsigned int nCtlColor, HBRUSH__ *hbrGray, COLORREF clrText)
{
  COLORREF SysColor; // eax
  tagLOGBRUSH logbrush; // [esp+8h] [ebp-10h] BYREF

  if ( hDC == nullptr
    || hbrGray == nullptr
    || nCtlColor < 2
    || nCtlColor == 5
    || nCtlColor == 2 && !_AfxIsComboBoxControl(hWnd, nStyle: 2u) )
  {
    return 0;
  }
  GetObjectA(h: hbrGray, c: 12, pv: &logbrush);
  SetBkColor(hdc: hDC, color: logbrush.lbColor);
  SysColor = clrText;
  if ( clrText == -1 )
    SysColor = GetSysColor(nIndex: 8);
  SetTextColor(hdc: hDC, color: SysColor);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033A655
// Name: public: int CWnd::PreTranslateInput(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::PreTranslateInput(CWnd *this, tagMSG *lpMsg)
{
  unsigned int message; // eax

  message = lpMsg->message;
  if ( (message < 0x100 || message > 0x109) && (message < 0x200 || message > 0x209) )
    return 0;
  else
    return CWnd::IsDialogMessageA(this, lpMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1033A68A
// Name: public: virtual int CWnd::ContinueModal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWnd::ContinueModal(CWnd *this)
{
  return this->m_nFlags & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x1033A6B0
// Name: protected: virtual int CWnd::CreateControlContainer(class COleControlContainer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::CreateControlContainer(CWnd *this, COleControlContainer **ppContainer)
{
  if ( ppContainer == nullptr )
    AfxThrowInvalidArgException();
  *ppContainer = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033A6CB
// Name: protected: virtual int CWnd::CreateControlSite(class COleControlContainer __near *,class COleControlSite __near * __near *,unsigned int,struct _GUID const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::CreateControlSite(
        CWnd *this,
        COleControlContainer *__formal,
        COleControlSite **ppSite,
        unsigned int a4,
        const _GUID *a5)
{
  if ( ppSite == nullptr )
    AfxThrowInvalidArgException();
  *ppSite = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033A6E6
// Name: public: class COleControlContainer __near * CWnd::GetControlContainer(void)
// Source: json
//------------------------------------------------------------------------------
COleControlContainer *__thiscall CWnd::GetControlContainer(CWnd *this)
{
  return this->m_pCtrlCont;
}

//------------------------------------------------------------------------------
// Address: 0x1033A6EA
// Name: public: virtual struct CRuntimeClass __near * CWnd::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWnd::GetRuntimeClass(CWnd *this)
{
  return &CWnd::classCWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1033AAE4
// Name: public: CWnd::CWnd(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::CWnd(CWnd *this)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (CWnd_vtbl *)&CWnd::`vftable';
  this->m_xAccessible.__vftable = (CWnd::XAccessible_vtbl *)&CWnd::XAccessible::`vftable';
  this->m_xAccessibleServer.__vftable = (CWnd::XAccessibleServer_vtbl *)&CWnd::XAccessibleServer::`vftable';
  this->m_hWnd = nullptr;
  this->m_bEnableActiveAccessibility = false;
  this->m_bIsTouchWindowRegistered = 0;
  this->m_pProxy = nullptr;
  this->m_pStdObject = nullptr;
  this->m_hWndOwner = nullptr;
  this->m_nFlags = 0;
  this->m_pfnSuper = nullptr;
  this->m_nModalResult = 0;
  this->m_pDropTarget = nullptr;
  this->m_pCtrlCont = nullptr;
  this->m_pCtrlSite = nullptr;
  this->m_pMFCCtrlContainer = nullptr;
  this->m_ulGestureArg = 0;
  this->m_bGestureInited = 0;
  this->m_pCurrentGestureInfo = nullptr;
  this->m_ptGestureFrom.x = -1;
  this->m_ptGestureFrom.y = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1033AB46
// Name: private: CWnd::CWnd(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::CWnd(CWnd *this, HWND__ *hWnd)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (CWnd_vtbl *)&CWnd::`vftable';
  this->m_xAccessible.__vftable = (CWnd::XAccessible_vtbl *)&CWnd::XAccessible::`vftable';
  this->m_xAccessibleServer.__vftable = (CWnd::XAccessibleServer_vtbl *)&CWnd::XAccessibleServer::`vftable';
  this->m_hWnd = hWnd;
  this->m_bEnableActiveAccessibility = false;
  this->m_bIsTouchWindowRegistered = 0;
  this->m_pProxy = nullptr;
  this->m_hWndOwner = nullptr;
  this->m_nFlags = 0;
  this->m_pfnSuper = nullptr;
  this->m_nModalResult = 0;
  this->m_pDropTarget = nullptr;
  this->m_pCtrlCont = nullptr;
  this->m_pCtrlSite = nullptr;
  this->m_pMFCCtrlContainer = nullptr;
  this->m_ulGestureArg = 0;
  this->m_bGestureInited = 0;
  this->m_pCurrentGestureInfo = nullptr;
  this->m_ptGestureFrom.x = -1;
  this->m_ptGestureFrom.y = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1033ABD4
// Name: public: virtual int CWnd::SetMenu(class CMenu __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::SetMenu(CWnd *this, HMENU__ *pMenu)
{
  HMENU__ *v2; // eax

  v2 = pMenu;
  if ( pMenu != nullptr )
    v2 = *((HMENU__ **)pMenu + 1);
  return SetMenu(hWnd: this->m_hWnd, hMenu: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1033ABF1
// Name: public: virtual int CWnd::CreateEx(unsigned long,char const __near *,char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::CreateEx(
        CWnd *this,
        unsigned int dwExStyle,
        const char *lpszClassName,
        const char *lpszWindowName,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        HMENU__ *nID,
        void *lpParam)
{
  HWND__ *m_hWnd; // edi

  if ( pParentWnd != nullptr )
    m_hWnd = pParentWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  return this->CreateEx_2(
           this,
           a2: dwExStyle,
           a3: lpszClassName,
           a4: lpszWindowName,
           a5: dwStyle,
           a6: rect->left,
           a7: rect->top,
           a8: rect->right - rect->left,
           a9: rect->bottom - rect->top,
           a10: m_hWnd,
           a11: nID,
           a12: lpParam);
}

//------------------------------------------------------------------------------
// Address: 0x1033AC3C
// Name: public: virtual int CWnd::Create(char const __near *,char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::Create(
        CWnd *this,
        const char *lpszClassName,
        const char *lpszWindowName,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        HMENU__ *nID,
        CCreateContext *pContext)
{
  HWND__ *m_hWnd; // edi

  if ( pParentWnd != nullptr )
    m_hWnd = pParentWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  return this->CreateEx_2(
           this,
           a2: 0,
           a3: lpszClassName,
           a4: lpszWindowName,
           a5: dwStyle | 0x40000000,
           a6: rect->left,
           a7: rect->top,
           a8: rect->right - rect->left,
           a9: rect->bottom - rect->top,
           a10: m_hWnd,
           a11: nID,
           a12: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x1033AC8C
// Name: public: static void CWnd::CancelToolTips(int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CWnd::CancelToolTips(int bKeys)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // esi
  CToolTipCtrl *m_pToolTip; // eax
  HWND m_hWnd; // eax
  CControlBar *m_pLastStatus; // esi

  ModuleThreadState = AfxGetModuleThreadState();
  m_pToolTip = ModuleThreadState->m_pToolTip;
  if ( m_pToolTip != nullptr )
  {
    m_hWnd = m_pToolTip->m_hWnd;
    if ( m_hWnd != nullptr )
      SendMessageA(hWnd: m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
  }
  m_pLastStatus = ModuleThreadState->m_pLastStatus;
  if ( bKeys != 0 && m_pLastStatus != nullptr && GetKeyState(nVirtKey: 1) >= 0 )
    m_pLastStatus->SetStatusText(this: m_pLastStatus, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1033ADAE
// Name: public: int CWnd::RegisterTouchWindow(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::RegisterTouchWindow(CWnd *this, int bRegister, unsigned int ulFlags)
{
  int result; // eax

  this->m_bIsTouchWindowRegistered = 0;
  if ( (_S1_35 & 1) == 0 )
  {
    _S1_35 |= 1u;
    hUserDll = AfxCtxLoadLibraryA(lpLibFileName: "user32.dll");
  }
  if ( hUserDll == nullptr )
    AfxThrowInvalidArgException();
  if ( (_S1_35 & 2) == 0 )
  {
    _S1_35 |= 2u;
    pfRegister = (int (__stdcall *)(HWND__ *, unsigned int))GetProcAddress(
                                                              hModule: hUserDll,
                                                              lpProcName: "RegisterTouchWindow");
  }
  if ( (_S1_35 & 4) == 0 )
  {
    _S1_35 |= 4u;
    pfUnregister = (int (__stdcall *)(HWND__ *))GetProcAddress(hModule: hUserDll, lpProcName: "UnregisterTouchWindow");
  }
  if ( pfRegister == nullptr || pfUnregister == nullptr )
    return 0;
  if ( bRegister == 0 )
    return pfUnregister(a1: this->m_hWnd);
  result = pfRegister(a1: this->m_hWnd, a2: ulFlags);
  this->m_bIsTouchWindowRegistered = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033AE73
// Name: protected: long CWnd::OnTabletQuerySystemGestureStatus(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnTabletQuerySystemGestureStatus(CWnd *this, unsigned int __formal, int lParam)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-14h]
  CPoint ptTouch; // [esp+4h] [ebp-8h] BYREF

  ptTouch.y = SHIWORD(lParam);
  m_hWnd = this->m_hWnd;
  ptTouch.x = (__int16)lParam;
  ScreenToClient(hWnd: m_hWnd, lpPoint: &ptTouch);
  return ((int (__thiscall *)(CWnd *, int, int))this->GetGestureStatus)(a1: this, a2: ptTouch.x, a3: ptTouch.y);
}

//------------------------------------------------------------------------------
// Address: 0x1033AEAF
// Name: protected: virtual int CWnd::OnTouchInputs(unsigned int,struct tagTOUCHINPUT __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnTouchInputs(CWnd *this, unsigned int nInputsCount, tagTOUCHINPUT *pInputs)
{
  unsigned int v3; // ebx
  CPoint ptCurr; // [esp+Ch] [ebp-8h] BYREF

  v3 = 0;
  if ( nInputsCount == 0 )
    return 1;
  while ( 1 )
  {
    ptCurr.x = pInputs->x / 100;
    ptCurr.y = pInputs->y / 100;
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCurr);
    if ( ((int (__thiscall *)(CWnd *, int, int, unsigned int, unsigned int, tagTOUCHINPUT *))this->OnTouchInput)(
           a1: this,
           a2: ptCurr.x,
           a3: ptCurr.y,
           a4: v3,
           a5: nInputsCount,
           a6: pInputs) == 0 )
      break;
    ++v3;
    ++pInputs;
    if ( v3 >= nInputsCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033AF4B
// Name: public: virtual void CWnd::WinHelpInternal(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::WinHelpInternal(CWnd *this, unsigned int dwData, unsigned int nCmd)
{
  unsigned int v4; // eax

  if ( AfxGetModuleState()->m_pCurrentWinApp->m_eHelpType == afxHTMLHelp )
  {
    v4 = nCmd;
    switch ( nCmd )
    {
      case 1u:
        v4 = 15;
        break;
      case 3u:
        v4 = 1;
        break;
      case 0xBu:
        v4 = 0;
        break;
      default:
        break;
    }
    this->HtmlHelpA(this, a2: dwData, a3: v4);
  }
  else
  {
    this->WinHelpA(this, a2: dwData, a3: nCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033AFA1
// Name: public: int CWnd::MessageBoxA(char const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::MessageBoxA(CWnd *this, const char *lpszText, const char *lpszCaption, UINT nType)
{
  const char *m_lpszCurrentAppName; // eax
  HWND__ *m_hWnd; // ecx

  m_lpszCurrentAppName = lpszCaption;
  if ( lpszCaption == nullptr )
    m_lpszCurrentAppName = AfxGetModuleState()->m_lpszCurrentAppName;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  return AfxCtxMessageBoxA(hWnd: m_hWnd, lpText: lpszText, lpCaption: m_lpszCurrentAppName, uType: nType);
}

//------------------------------------------------------------------------------
// Address: 0x1033AFD8
// Name: public: int CWnd::SetScrollPos(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SetScrollPos(CWnd *this, int nBar, int nPos, BOOL bRedraw)
{
  CScrollBar *v5; // eax

  v5 = this->GetScrollBarCtrl(this, a2: nBar);
  if ( v5 != nullptr )
    return SetScrollPos(hWnd: v5->m_hWnd, nBar: 2, nPos, bRedraw);
  else
    return SetScrollPos(hWnd: this->m_hWnd, nBar, nPos, bRedraw);
}

//------------------------------------------------------------------------------
// Address: 0x1033B00A
// Name: public: int CWnd::GetScrollPos(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::GetScrollPos(CWnd *this, int nBar)
{
  CScrollBar *v3; // eax

  v3 = this->GetScrollBarCtrl(this, a2: nBar);
  if ( v3 != nullptr )
    return GetScrollPos(hWnd: v3->m_hWnd, nBar: 2);
  else
    return GetScrollPos(hWnd: this->m_hWnd, nBar);
}

//------------------------------------------------------------------------------
// Address: 0x1033B036
// Name: public: void CWnd::SetScrollRange(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::SetScrollRange(CWnd *this, int nBar, int nMinPos, int nMaxPos, BOOL bRedraw)
{
  CScrollBar *v6; // eax

  v6 = this->GetScrollBarCtrl(this, a2: nBar);
  if ( v6 != nullptr )
    SetScrollRange(hWnd: v6->m_hWnd, nBar: 2, nMinPos, nMaxPos, bRedraw);
  else
    SetScrollRange(hWnd: this->m_hWnd, nBar, nMinPos, nMaxPos, bRedraw);
}

//------------------------------------------------------------------------------
// Address: 0x1033B06B
// Name: public: void CWnd::GetScrollRange(int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::GetScrollRange(CWnd *this, int nBar, int *lpMinPos, int *lpMaxPos)
{
  CScrollBar *v5; // eax

  v5 = this->GetScrollBarCtrl(this, a2: nBar);
  if ( v5 != nullptr )
    GetScrollRange(hWnd: v5->m_hWnd, nBar: 2, lpMinPos, lpMaxPos);
  else
    GetScrollRange(hWnd: this->m_hWnd, nBar, lpMinPos, lpMaxPos);
}

//------------------------------------------------------------------------------
// Address: 0x1033B09D
// Name: public: void CWnd::EnableScrollBarCtrl(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::EnableScrollBarCtrl(CWnd *this, int nBar, int bEnable)
{
  int v3; // edi
  CScrollBar *v5; // eax

  v3 = nBar;
  if ( nBar == 3 )
  {
    CWnd::EnableScrollBarCtrl(this, nBar: 0, bEnable);
    v3 = 1;
  }
  v5 = this->GetScrollBarCtrl(this, a2: v3);
  if ( v5 != nullptr )
    CWnd::EnableWindow(this: v5, bEnable);
  else
    ShowScrollBar(hWnd: this->m_hWnd, wBar: v3, bShow: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1033B0E3
// Name: public: int CWnd::GetScrollLimit(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::GetScrollLimit(CWnd *this, int nBar)
{
  int nMin; // [esp+4h] [ebp-28h] BYREF
  int nMax; // [esp+8h] [ebp-24h] BYREF
  tagSCROLLINFO info; // [esp+Ch] [ebp-20h] BYREF

  CWnd::GetScrollRange(this, nBar, lpMinPos: &nMin, lpMaxPos: &nMax);
  if ( CWnd::GetScrollInfo(this, nBar, lpScrollInfo: &info, nMask: 2u) )
    nMax -= info.nPage != 1 ? info.nPage - 1 : 0;
  return nMax;
}

//------------------------------------------------------------------------------
// Address: 0x1033B140
// Name: public: void CWnd::ScrollWindow(int,int,struct tagRECT const __near *,struct tagRECT const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::ScrollWindow(
        CWnd *this,
        int xAmount,
        int yAmount,
        const tagRECT *lpRect,
        const tagRECT *lpClipRect)
{
  HWND i; // eax
  HWND v7; // ebx
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  if ( IsWindowVisible(hWnd: this->m_hWnd) || lpRect != nullptr || lpClipRect != nullptr )
  {
    ScrollWindow(hWnd: this->m_hWnd, XAmount: xAmount, YAmount: yAmount, lpRect, lpClipRect);
  }
  else
  {
    for ( i = GetWindow(hWnd: this->m_hWnd, uCmd: 5u); ; i = GetWindow(hWnd: v7, uCmd: 2u) )
    {
      v7 = i;
      if ( i == nullptr )
        break;
      memset(&rect, 0, sizeof(rect));
      GetWindowRect(hWnd: i, lpRect: &rect);
      CWnd::ScreenToClient(this, lpRect: &rect);
      SetWindowPos(
        hWnd: v7,
        hWndInsertAfter: nullptr,
        X: xAmount + rect.left,
        Y: yAmount + rect.top,
        cx: 0,
        cy: 0,
        uFlags: 0x15u);
    }
  }
  if ( this->m_pCtrlCont != nullptr && lpRect == nullptr )
    this->m_pCtrlCont->ScrollChildren(this: this->m_pCtrlCont, a2: xAmount, a3: yAmount);
}

//------------------------------------------------------------------------------
// Address: 0x1033B20A
// Name: protected: long CWnd::OnActivateTopLevel(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnActivateTopLevel(CWnd *this, __int16 wParam, int __formal)
{
  tagTOOLINFOA *m_pLastInfo; // eax

  if ( wParam == 0 )
  {
    m_pLastInfo = AfxGetModuleThreadState()->m_pLastInfo;
    if ( m_pLastInfo != nullptr && (m_pLastInfo->uFlags & 0x40000000) == 0 )
      CWnd::CancelToolTips(bKeys: 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033B578
// Name: public: int CWnd::UpdateData(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::UpdateData(CWnd *this, int bSaveAndValidate)
{
  _AFX_THREAD_STATE *ThreadState; // eax
  CWnd_vtbl *v4; // eax
  CDataExchange v6; // [esp+14h] [ebp-2Ch] BYREF
  _AFX_THREAD_STATE *pThreadState; // [esp+28h] [ebp-18h]
  HWND__ *hWndOldLockout; // [esp+2Ch] [ebp-14h]
  int v9; // [esp+3Ch] [ebp-4h]

  v6.m_bSaveAndValidate = bSaveAndValidate;
  v6.m_pDlgWnd = this;
  v6.m_idLastControl = 0;
  ThreadState = AfxGetThreadState();
  hWndOldLockout = ThreadState->m_hLockoutNotifyWindow;
  ThreadState->m_hLockoutNotifyWindow = this->m_hWnd;
  pThreadState = ThreadState;
  v4 = this->__vftable;
  v9 = 0;
  v4->DoDataExchange(this, a2: &v6);
  pThreadState->m_hLockoutNotifyWindow = hWndOldLockout;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033B606
// Name: public: void CWnd::CenterWindow(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::CenterWindow(CWnd *this, CWnd *pAlternateOwner)
{
  unsigned int Style; // eax
  HWND v4; // esi
  HWND__ *m_hWnd; // ebx
  HWND Parent; // eax
  LRESULT v7; // eax
  LONG WindowLongA; // eax
  CWnd *MainWnd; // eax
  HMONITOR v10; // eax
  HMONITOR v11; // eax
  HWND v12; // edi
  int left; // ecx
  int top; // esi
  HWND__ *v15; // [esp-8h] [ebp-78h]
  unsigned int dwStyle; // [esp+10h] [ebp-60h]
  tagMONITORINFO mi; // [esp+14h] [ebp-5Ch] BYREF
  CRect rcDlg; // [esp+3Ch] [ebp-34h] BYREF
  CRect rcCenter; // [esp+4Ch] [ebp-24h] BYREF
  CRect rcArea; // [esp+5Ch] [ebp-14h] BYREF

  Style = CWnd::GetStyle(this);
  v4 = nullptr;
  dwStyle = Style;
  if ( pAlternateOwner != nullptr )
  {
    m_hWnd = pAlternateOwner->m_hWnd;
  }
  else
  {
    if ( (Style & 0x40000000) != 0 )
      Parent = GetParent(hWnd: this->m_hWnd);
    else
      Parent = GetWindow(hWnd: this->m_hWnd, uCmd: 4u);
    m_hWnd = Parent;
    if ( Parent != nullptr )
    {
      v7 = SendMessageA(hWnd: Parent, Msg: 0x36Bu, wParam: 0, lParam: 0);
      if ( v7 != 0 )
        m_hWnd = (HWND__ *)v7;
    }
  }
  v15 = this->m_hWnd;
  memset(&rcDlg, 0, sizeof(rcDlg));
  GetWindowRect(hWnd: v15, lpRect: &rcDlg);
  memset(&rcArea, 0, sizeof(rcArea));
  memset(&rcCenter, 0, sizeof(rcCenter));
  if ( (dwStyle & 0x40000000) != 0 )
  {
    v12 = GetParent(hWnd: this->m_hWnd);
    GetClientRect(hWnd: v12, lpRect: &rcArea);
    GetClientRect(hWnd: m_hWnd, lpRect: &rcCenter);
    MapWindowPoints(hWndFrom: m_hWnd, hWndTo: v12, lpPoints: (LPPOINT)&rcCenter, cPoints: 2u);
  }
  else
  {
    if ( m_hWnd != nullptr )
    {
      WindowLongA = GetWindowLongA(hWnd: m_hWnd, nIndex: -16);
      if ( (WindowLongA & 0x10000000) == 0 || (WindowLongA & 0x20000000) != 0 )
        m_hWnd = nullptr;
    }
    mi.cbSize = 40;
    if ( m_hWnd != nullptr )
    {
      GetWindowRect(hWnd: m_hWnd, lpRect: &rcCenter);
      v11 = MonitorFromWindow(hwnd: m_hWnd, dwFlags: 2u);
      GetMonitorInfoA(hMonitor: v11, lpmi: &mi);
      CopyRect(lprcDst: &rcArea, lprcSrc: &mi.rcWork);
    }
    else
    {
      MainWnd = AfxGetMainWnd();
      if ( MainWnd != nullptr )
        v4 = MainWnd->m_hWnd;
      v10 = MonitorFromWindow(hwnd: v4, dwFlags: 1u);
      GetMonitorInfoA(hMonitor: v10, lpmi: &mi);
      CopyRect(lprcDst: &rcCenter, lprcSrc: &mi.rcWork);
      CopyRect(lprcDst: &rcArea, lprcSrc: &mi.rcWork);
    }
  }
  left = (rcCenter.right + rcCenter.left) / 2 - (rcDlg.right - rcDlg.left) / 2;
  top = (rcCenter.bottom + rcCenter.top) / 2 - (rcDlg.bottom - rcDlg.top) / 2;
  if ( left + rcDlg.right - rcDlg.left > rcArea.right )
    left = rcArea.right + rcDlg.left - rcDlg.right;
  if ( left < rcArea.left )
    left = rcArea.left;
  if ( top + rcDlg.bottom - rcDlg.top > rcArea.bottom )
    top = rcArea.bottom + rcDlg.top - rcDlg.bottom;
  if ( top < rcArea.top )
    top = rcArea.top;
  CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: left, y: top, cx: -1, cy: -1, nFlags: 0x15u);
}

//------------------------------------------------------------------------------
// Address: 0x1033B7FE
// Name: public: int CWnd::RunModalLoop(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::RunModalLoop(CWnd *this, char dwFlags)
{
  HWND Parent; // eax
  LRESULT v4; // eax
  unsigned int message; // eax
  HWND__ *hWndParent; // [esp+Ch] [ebp-14h]
  tagMSG *pMsg; // [esp+10h] [ebp-10h]
  int bIdle; // [esp+14h] [ebp-Ch]
  LPARAM lIdleCount; // [esp+18h] [ebp-8h]
  int bShowIdle; // [esp+1Ch] [ebp-4h]

  bIdle = 1;
  lIdleCount = 0;
  if ( (dwFlags & 4) == 0 || (bShowIdle = 1, (CWnd::GetStyle(this) & 0x10000000) != 0) )
    bShowIdle = 0;
  Parent = GetParent(hWnd: this->m_hWnd);
  this->m_nFlags |= 0x18u;
  hWndParent = Parent;
  pMsg = AfxGetCurrentMessage();
LABEL_15:
  while ( bIdle != 0 && !PeekMessageA(lpMsg: pMsg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
  {
    if ( bShowIdle != 0 )
    {
      CWnd::ShowWindow(this, nCmdShow: 1);
      UpdateWindow(hWnd: this->m_hWnd);
      bShowIdle = 0;
    }
    if ( (dwFlags & 1) == 0 && hWndParent != nullptr && lIdleCount == 0 )
      SendMessageA(hWnd: hWndParent, Msg: 0x121u, wParam: 0, lParam: (LPARAM)this->m_hWnd);
    if ( (dwFlags & 2) == 0 )
    {
      v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: lIdleCount++);
      if ( v4 != 0 )
        continue;
    }
    bIdle = 0;
  }
  while ( 1 )
  {
    if ( AfxPumpMessage() == 0 )
    {
      AfxPostQuitMessage(nExitCode: 0);
      return -1;
    }
    if ( bShowIdle != 0 )
    {
      message = pMsg->message;
      if ( message == 280 || message == 260 )
      {
        CWnd::ShowWindow(this, nCmdShow: 1);
        UpdateWindow(hWnd: this->m_hWnd);
        bShowIdle = 0;
      }
    }
    if ( this->ContinueModal(this) == 0 )
      break;
    if ( AfxIsIdleMessage(pMsg) != 0 )
    {
      bIdle = 1;
      lIdleCount = 0;
    }
    if ( !PeekMessageA(lpMsg: pMsg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
      goto LABEL_15;
  }
  this->m_nFlags &= 0xFFFFFFE7;
  return this->m_nModalResult;
}

//------------------------------------------------------------------------------
// Address: 0x1033B942
// Name: public: virtual void CWnd::EndModalLoop(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::EndModalLoop(CWnd *this, int nResult)
{
  unsigned int m_nFlags; // eax

  this->m_nModalResult = nResult;
  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x10) != 0 )
  {
    this->m_nFlags = m_nFlags & 0xFFFFFFEF;
    PostMessageA(hWnd: this->m_hWnd, Msg: 0, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033B96C
// Name: public: virtual void CWnd::OnDrawIconicThumbnailOrLivePreview(class CDC __near &,class CRect,class CSize,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnDrawIconicThumbnailOrLivePreview(
        CWnd *this,
        HDC__ *dc,
        CRect __formal,
        CSize a4,
        int a5,
        int *a6)
{
  HDC__ *v6; // eax

  v6 = dc;
  if ( dc != nullptr )
    v6 = *((HDC__ **)dc + 1);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x317u, wParam: (WPARAM)v6, lParam: 30);
}

//------------------------------------------------------------------------------
// Address: 0x1033B990
// Name: public: static class CObject __near * CWnd::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall CWnd::CreateObject()
{
  CWnd *v0; // ecx
  CWnd *result; // eax

  v0 = (CWnd *)operator new(nSize: 0x74u);
  result = nullptr;
  if ( v0 != nullptr )
    return CWnd::CWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033BB58
// Name: protected: static struct tagMSG const __near * CWnd::GetCurrentMessage(void)
// Source: json
//------------------------------------------------------------------------------
CNoTrackObject *__stdcall CWnd::GetCurrentMessage()
{
  CNoTrackObject *Data; // esi
  DWORD MessagePos; // eax

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  Data[26].__vftable = (CNoTrackObject_vtbl *)GetMessageTime();
  MessagePos = GetMessagePos();
  Data[28].__vftable = (CNoTrackObject_vtbl *)SHIWORD(MessagePos);
  Data[27].__vftable = (CNoTrackObject_vtbl *)(__int16)MessagePos;
  return Data + 22;
}

//------------------------------------------------------------------------------
// Address: 0x1033BB96
// Name: protected: long CWnd::Default(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::Default(CWnd *this)
{
  CNoTrackObject *Data; // eax

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  return this->DefWindowProcA(
           this,
           a2: (unsigned int)Data[23].__vftable,
           a3: (unsigned int)Data[24].__vftable,
           a4: (int)Data[25].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x1033BC3C
// Name: public: static class CWnd __near * CWnd::FromHandle(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall CWnd::FromHandle(HWND__ *hWnd)
{
  CHandleMap *v1; // esi
  CWnd *v2; // edi

  v1 = afxMapHWND(bCreate: 1);
  v2 = (CWnd *)CHandleMap::FromHandle(this: v1, h: hWnd);
  CWnd::AttachControlSite(this: v2, pMap: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033BC68
// Name: public: static class CWnd __near * CWnd::FromHandlePermanent(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall CWnd::FromHandlePermanent(CDocument *hWnd)
{
  CHandleMap *v1; // ecx
  CWnd *result; // eax

  v1 = afxMapHWND(bCreate: 0);
  result = nullptr;
  if ( v1 != nullptr )
    return (CWnd *)CMapPtrToPtr::GetValueAt(this: &v1->m_permanentMap, key: hWnd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033BC89
// Name: public: int CWnd::Attach(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::Attach(CWnd *this, HWND__ *hWndNew)
{
  CHandleMap *v4; // edi

  if ( hWndNew == nullptr )
    return 0;
  v4 = afxMapHWND(bCreate: 1);
  this->m_hWnd = hWndNew;
  *CMapPtrToPtr::operator[](this: &v4->m_permanentMap, key: (CDocument *)hWndNew) = this;
  CWnd::AttachControlSite(this, pMap: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033BCC7
// Name: public: struct HWND__ __near * CWnd::Detach(void)
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall CWnd::Detach(CWnd *this)
{
  HWND__ *m_hWnd; // edi
  CHandleMap *v3; // eax

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    v3 = afxMapHWND(bCreate: 0);
    if ( v3 != nullptr )
      CMapPtrToPtr::RemoveKey(this: &v3->m_permanentMap, key: (CDocument *)this->m_hWnd);
    this->m_hWnd = nullptr;
  }
  this->m_pCtrlSite = nullptr;
  return m_hWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1033BD44
// Name: protected: void CWnd::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnDestroy(CWnd *this)
{
  COleControlContainer *m_pCtrlCont; // ecx
  IAccessibleProxy *m_pProxy; // eax
  IAccessible *m_pStdObject; // eax

  m_pCtrlCont = this->m_pCtrlCont;
  if ( m_pCtrlCont != nullptr )
    ((void (__thiscall *)(COleControlContainer *, int))m_pCtrlCont->dtr_CObject)(a1: m_pCtrlCont, a2: 1);
  m_pProxy = this->m_pProxy;
  this->m_pCtrlCont = nullptr;
  if ( m_pProxy != nullptr )
    m_pProxy->SetServer(this: m_pProxy, a2: nullptr, a3: nullptr);
  m_pStdObject = this->m_pStdObject;
  if ( m_pStdObject != nullptr )
    m_pStdObject->Release(this: this->m_pStdObject);
  if ( this->m_bIsTouchWindowRegistered != 0 )
    CWnd::RegisterTouchWindow(this, bRegister: 0, ulFlags: 0);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033BD90
// Name: protected: void CWnd::OnNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnNcDestroy(CWnd *this)
{
  CWinThread *Thread; // eax
  CWinApp *v3; // edi
  COleDropTarget *m_pDropTarget; // ecx
  COleControlContainer *m_pCtrlCont; // ecx
  CToolTipCtrl *m_pToolTip; // edi
  LONG WindowLongA; // ebx
  LONG v8; // eax
  HWND m_hWnd; // [esp-10h] [ebp-50h]
  tagTOOLINFOA ti; // [esp+Ch] [ebp-34h] BYREF

  Thread = AfxGetThread();
  v3 = (CWinApp *)Thread;
  if ( Thread != nullptr )
  {
    if ( Thread->m_pMainWnd == this )
    {
      if ( AfxGetModuleState()->m_bDLL == 0 && (v3 != AfxGetModuleState()->m_pCurrentWinApp || AfxOleCanExitApp()) )
        AfxPostQuitMessage(nExitCode: 0);
      v3->m_pMainWnd = nullptr;
    }
    if ( v3->m_pActiveWnd == this )
      v3->m_pActiveWnd = nullptr;
  }
  m_pDropTarget = this->m_pDropTarget;
  if ( m_pDropTarget != nullptr )
  {
    m_pDropTarget->Revoke(this: m_pDropTarget);
    this->m_pDropTarget = nullptr;
  }
  m_pCtrlCont = this->m_pCtrlCont;
  if ( m_pCtrlCont != nullptr )
    ((void (__thiscall *)(COleControlContainer *, int))m_pCtrlCont->dtr_CObject)(a1: m_pCtrlCont, a2: 1);
  this->m_pCtrlCont = nullptr;
  if ( (this->m_nFlags & 1) != 0 )
  {
    m_pToolTip = AfxGetModuleThreadState()->m_pToolTip;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    {
      memset(dst: (unsigned __int8 *)&ti, value: 0, count: sizeof(ti));
      ti.hwnd = this->m_hWnd;
      ti.uId = (unsigned int)ti.hwnd;
      m_hWnd = m_pToolTip->m_hWnd;
      ti.cbSize = 44;
      ti.uFlags = 1;
      SendMessageA(hWnd: m_hWnd, Msg: 0x405u, wParam: 0, lParam: (LPARAM)&ti);
    }
  }
  WindowLongA = GetWindowLongA(hWnd: this->m_hWnd, nIndex: -4);
  CWnd::Default(this);
  if ( GetWindowLongA(hWnd: this->m_hWnd, nIndex: -4) == WindowLongA )
  {
    v8 = (LONG)*this->GetSuperWndProcAddr(this);
    if ( v8 != 0 )
      SetWindowLongA(hWnd: this->m_hWnd, nIndex: -4, dwNewLong: v8);
  }
  CWnd::Detach(this);
  this->PostNcDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033BEB7
// Name: public: virtual int CWnd::DestroyWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::DestroyWindow(CWnd *this)
{
  int v2; // edi
  CHandleMap *v4; // eax

  v2 = 0;
  if ( this->m_hWnd != nullptr )
  {
    v4 = afxMapHWND(bCreate: 0);
    if ( v4 == nullptr )
      AfxThrowInvalidArgException();
    CMapPtrToPtr::GetValueAt(this: &v4->m_permanentMap, key: (CDocument *)this->m_hWnd);
  }
  else if ( this->m_pCtrlSite == nullptr )
  {
    return 0;
  }
  if ( this->m_hWnd != nullptr || this->m_pCtrlSite != nullptr )
  {
    if ( this->m_pCtrlSite != nullptr )
      return this->m_pCtrlSite->DestroyControl(this: this->m_pCtrlSite);
    else
      return DestroyWindow(hWnd: this->m_hWnd);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033BF16
// Name: protected: long CWnd::OnNTCtlColor(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnNTCtlColor(CWnd *this, HDC__ *wParam, HWND__ *lParam)
{
  CNoTrackObject *Data; // eax
  AFX_CTLCOLOR ctl; // [esp+4h] [ebp-Ch] BYREF

  ctl.hDC = wParam;
  ctl.hWnd = lParam;
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  ctl.nCtlType = (unsigned int)&Data[23].__vftable[-77].dtr_CNoTrackObject + 2;
  return this->WindowProc(this, a2: 25u, a3: 0, a4: (int)&ctl);
}

//------------------------------------------------------------------------------
// Address: 0x1033BF69
// Name: protected: long CWnd::OnTouchMessage(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnTouchMessage(CWnd *this, unsigned __int16 wParam, void *lParam)
{
  CWnd *v3; // ebx
  tagTOUCHINPUT *v4; // eax
  tagTOUCHINPUT *v5; // esi
  int TouchInputInfo; // eax
  int v7; // edi

  v3 = this;
  if ( wParam == 0 )
    return CWnd::Default(this);
  if ( (_S3_10 & 1) == 0 )
  {
    _S3_10 |= 1u;
    hUserDll_0 = AfxCtxLoadLibraryA(lpLibFileName: "user32.dll");
  }
  if ( hUserDll_0 == nullptr )
    AfxThrowInvalidArgException();
  if ( (_S3_10 & 2) == 0 )
  {
    _S3_10 |= 2u;
    pfGetTouchInputInfo = (int (__stdcall *)(void *, unsigned int, tagTOUCHINPUT *, int))GetProcAddress(
                                                                                           hModule: hUserDll_0,
                                                                                           lpProcName: "GetTouchInputInfo");
  }
  if ( (_S3_10 & 4) == 0 )
  {
    _S3_10 |= 4u;
    pfCloseTouchInputHandle = (int (__stdcall *)(void *))GetProcAddress(
                                                           hModule: hUserDll_0,
                                                           lpProcName: "CloseTouchInputHandle");
  }
  if ( pfGetTouchInputInfo == nullptr )
    goto LABEL_16;
  if ( pfCloseTouchInputHandle == nullptr )
    goto LABEL_16;
  v4 = (tagTOUCHINPUT *)operator new(nSize: 40 * wParam);
  v5 = v4;
  if ( v4 == nullptr )
    goto LABEL_16;
  TouchInputInfo = pfGetTouchInputInfo(a1: lParam, a2: wParam, a3: v4, a4: 40);
  this = v3;
  if ( TouchInputInfo != 0 )
  {
    v7 = v3->OnTouchInputs(this: v3, a2: wParam, a3: v5);
    operator delete(p: v5);
    pfCloseTouchInputHandle(a1: lParam);
    if ( v7 != 0 )
      return 0;
LABEL_16:
    this = v3;
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C073
// Name: protected: long CWnd::OnGesture(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnGesture(CWnd *this, unsigned int __formal, HGESTUREINFO__ *lParam)
{
  HWND__ *m_hWnd; // edx
  tagGESTUREINFO *m_pCurrentGestureInfo; // eax
  int y; // ecx
  tagGESTUREINFO *v7; // eax
  BOOL v8; // edi
  int v9; // eax
  unsigned __int64 v10; // st7
  tagGESTUREINFO *v11; // eax
  tagPOINT Point; // [esp+28h] [ebp-14h] BYREF
  int v14; // [esp+38h] [ebp-4h]

  if ( (_S6_5 & 1) == 0 )
  {
    _S6_5 |= 1u;
    v14 = -1;
    hUserDll_1 = AfxCtxLoadLibraryA(lpLibFileName: "user32.dll");
  }
  if ( hUserDll_1 == nullptr )
    AfxThrowInvalidArgException();
  if ( (_S6_5 & 2) == 0 )
  {
    _S6_5 |= 2u;
    pfGetGestureInfo = (int (__stdcall *)(HGESTUREINFO__ *, tagGESTUREINFO *))GetProcAddress(
                                                                                hModule: hUserDll_1,
                                                                                lpProcName: "GetGestureInfo");
  }
  if ( (_S6_5 & 4) == 0 )
  {
    _S6_5 |= 4u;
    pfCloseGestureInfoHandle = (int (__stdcall *)(HGESTUREINFO__ *))GetProcAddress(
                                                                      hModule: hUserDll_1,
                                                                      lpProcName: "CloseGestureInfoHandle");
  }
  if ( pfGetGestureInfo == nullptr || pfCloseGestureInfoHandle == nullptr )
    return CWnd::Default(this);
  if ( this->m_pCurrentGestureInfo == nullptr )
    this->m_pCurrentGestureInfo = (tagGESTUREINFO *)operator new(nSize: 0x30u);
  memset(dst: (unsigned __int8 *)this->m_pCurrentGestureInfo, value: 0, count: sizeof(tagGESTUREINFO));
  this->m_pCurrentGestureInfo->cbSize = 48;
  if ( pfGetGestureInfo(a1: lParam, a2: this->m_pCurrentGestureInfo) == 0
    || (m_hWnd = this->m_hWnd, (m_pCurrentGestureInfo = this->m_pCurrentGestureInfo)->hwndTarget != m_hWnd) )
  {
    memset(dst: (unsigned __int8 *)this->m_pCurrentGestureInfo, value: 0, count: sizeof(tagGESTUREINFO));
    return CWnd::Default(this);
  }
  y = m_pCurrentGestureInfo->ptsLocation.y;
  Point.x = m_pCurrentGestureInfo->ptsLocation.x;
  Point.y = y;
  ScreenToClient(hWnd: m_hWnd, lpPoint: &Point);
  v7 = this->m_pCurrentGestureInfo;
  v8 = true;
  switch ( v7->dwID )
  {
    case 1u:
      this->m_ptGestureFrom = (CPoint)Point;
      LODWORD(this->m_ulGestureArg) = v7->ullArguments;
      HIDWORD(this->m_ulGestureArg) = HIDWORD(v7->ullArguments);
      return CWnd::Default(this);
    case 2u:
      this->m_ptGestureFrom.x = -1;
      this->m_ptGestureFrom.y = -1;
      LODWORD(this->m_ulGestureArg) = 0;
      HIDWORD(this->m_ulGestureArg) = 0;
      memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(tagGESTUREINFO));
      return CWnd::Default(this);
    case 3u:
      v9 = ((int (__thiscall *)(CWnd *, int, int, int))this->OnGestureZoom)(
             a1: this,
             a2: Point.x,
             a3: Point.y,
             a4: LODWORD(v7->ullArguments) - LODWORD(this->m_ulGestureArg));
      break;
    case 4u:
      v9 = ((int (__thiscall *)(CWnd *, int, int, int, int))this->OnGesturePan)(
             a1: this,
             a2: this->m_ptGestureFrom.x,
             a3: this->m_ptGestureFrom.y,
             a4: Point.x,
             a5: Point.y);
      break;
    case 5u:
      *(double *)&v10 = (double)v7->ullArguments / 65535.0 * 4.0 * 3.14159265 - 6.2831853;
      v9 = ((int (__thiscall *)(CWnd *, int, int, _DWORD, _DWORD))this->OnGestureRotate)(
             a1: this,
             a2: Point.x,
             a3: Point.y,
             a4: v10,
             a5: HIDWORD(v10));
      break;
    case 6u:
      v9 = ((int (__thiscall *)(CWnd *, int, int))this->OnGestureTwoFingerTap)(a1: this, a2: Point.x, a3: Point.y);
      break;
    case 7u:
      v9 = ((int (__thiscall *)(CWnd *, int, int, _DWORD))this->OnGesturePressAndTap)(
             a1: this,
             a2: Point.x,
             a3: Point.y,
             a4: v7->ullArguments);
      break;
    default:
      goto LABEL_29;
  }
  v8 = v9 == 0;
  if ( v9 != 0 )
    pfCloseGestureInfoHandle(a1: lParam);
LABEL_29:
  this->m_ptGestureFrom = (CPoint)Point;
  v11 = this->m_pCurrentGestureInfo;
  LODWORD(this->m_ulGestureArg) = v11->ullArguments;
  HIDWORD(this->m_ulGestureArg) = HIDWORD(v11->ullArguments);
  if ( !v8 )
    return 0;
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C2E3
// Name: public: class CWnd __near * CWnd::GetParentOwner(void)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetParentOwner(CWnd *this)
{
  HWND__ *m_hWnd; // ebx
  LONG i; // eax
  HWND Parent; // eax

  if ( this == nullptr )
    return nullptr;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd == nullptr )
    return nullptr;
  for ( i = GetWindowLongA(hWnd: m_hWnd, nIndex: -16); (i & 0x40000000) != 0; i = GetWindowLongA(
                                                                                    hWnd: Parent,
                                                                                    nIndex: -16) )
  {
    Parent = GetParent(hWnd: m_hWnd);
    if ( Parent == nullptr )
      break;
    m_hWnd = Parent;
  }
  return CWnd::FromHandle(hWnd: m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1033C329
// Name: public: static class CWnd __near * CWnd::GetSafeOwner(class CWnd __near *,struct HWND__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall CWnd::GetSafeOwner(CWnd *pParent, HWND__ **pWndTop)
{
  HWND__ *m_hWnd; // eax
  HWND__ *SafeOwner; // eax

  m_hWnd = (HWND__ *)pParent;
  if ( pParent != nullptr )
    m_hWnd = pParent->m_hWnd;
  SafeOwner = CWnd::GetSafeOwner_(hParent: m_hWnd, pWndTop);
  return CWnd::FromHandle(hWnd: SafeOwner);
}

//------------------------------------------------------------------------------
// Address: 0x1033C34B
// Name: public: static class CWnd __near * CWnd::GetDescendantWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall CWnd::GetDescendantWindow(HWND__ *hWnd, int nID, int bOnlyPerm)
{
  HWND DlgItem; // eax
  CDocument *v4; // esi
  CWnd *result; // eax
  HWND v6; // esi

  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: nID);
  v4 = (CDocument *)DlgItem;
  if ( DlgItem == nullptr )
    goto LABEL_7;
  if ( GetTopWindow(hWnd: DlgItem) == nullptr
    || (result = CWnd::GetDescendantWindow(hWnd: (HWND__ *)v4, nID, bOnlyPerm)) == nullptr )
  {
    if ( bOnlyPerm == 0 )
      return CWnd::FromHandle(hWnd: (HWND__ *)v4);
    result = CWnd::FromHandlePermanent(hWnd: v4);
    if ( result == nullptr )
    {
LABEL_7:
      for ( result = (CWnd *)GetTopWindow(hWnd); ; result = (CWnd *)GetWindow(hWnd: v6, uCmd: 2u) )
      {
        v6 = (HWND)result;
        if ( result == nullptr )
          break;
        result = CWnd::GetDescendantWindow(hWnd: (HWND__ *)result, nID, bOnlyPerm);
        if ( result != nullptr )
          break;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033C3C4
// Name: public: void CWnd::RepositionBars(unsigned int,unsigned int,unsigned int,unsigned int,struct tagRECT __near *,struct tagRECT const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::RepositionBars(
        CWnd *this,
        unsigned int nIDFirst,
        unsigned int nIDLast,
        unsigned int nIDLeftOver,
        unsigned int nFlags,
        tagRECT *lpRectParam,
        const tagRECT *lpRectClient,
        int bStretch)
{
  HWND i; // esi
  unsigned int DlgCtrlID; // edi
  CWnd *v10; // eax
  int cy; // eax
  CWnd *v12; // eax
  unsigned int v14; // [esp+10h] [ebp-2Ch]
  HWND__ *hWndLeftOver; // [esp+14h] [ebp-28h]
  AFX_SIZEPARENTPARAMS layout; // [esp+18h] [ebp-24h] BYREF

  hWndLeftOver = nullptr;
  layout.bStretch = bStretch;
  layout.sizeTotal.cy = 0;
  layout.sizeTotal.cx = 0;
  if ( lpRectClient != nullptr )
    layout.rect = *lpRectClient;
  else
    GetClientRect(hWnd: this->m_hWnd, lpRect: &layout.rect);
  v14 = nFlags & 0xFFFF7FFF;
  if ( (nFlags & 0xFFFF7FFF) == 1 )
    layout.hDWP = nullptr;
  else
    layout.hDWP = BeginDeferWindowPos(nNumWindows: 8);
  for ( i = GetTopWindow(hWnd: this->m_hWnd); i != nullptr; i = GetWindow(hWnd: i, uCmd: 2u) )
  {
    DlgCtrlID = GetDlgCtrlID(hWnd: i);
    v10 = CWnd::FromHandlePermanent(hWnd: (CDocument *)i);
    if ( DlgCtrlID == nIDLeftOver )
    {
      hWndLeftOver = i;
    }
    else if ( DlgCtrlID >= nIDFirst && DlgCtrlID <= nIDLast && v10 != nullptr )
    {
      SendMessageA(hWnd: i, Msg: 0x361u, wParam: 0, lParam: (LPARAM)&layout);
    }
  }
  if ( v14 == 1 )
  {
    if ( bStretch != 0 )
    {
      CopyRect(lprcDst: lpRectParam, lprcSrc: &layout.rect);
    }
    else
    {
      lpRectParam->right = layout.sizeTotal.cx;
      cy = layout.sizeTotal.cy;
      lpRectParam->top = 0;
      lpRectParam->left = 0;
      lpRectParam->bottom = cy;
    }
  }
  else
  {
    if ( nIDLeftOver != 0 && hWndLeftOver != nullptr )
    {
      v12 = CWnd::FromHandle(hWnd: hWndLeftOver);
      if ( v14 == 2 )
      {
        layout.rect.left += lpRectParam->left;
        layout.rect.top += lpRectParam->top;
        layout.rect.right -= lpRectParam->right;
        layout.rect.bottom -= lpRectParam->bottom;
      }
      if ( (nFlags & 0x8000) == 0 )
      {
        v12->CalcWindowRect(this: v12, a2: &layout.rect, a3: 0);
        AfxRepositionWindow(lpLayout: &layout, hWnd: hWndLeftOver, lpRect: &layout.rect);
      }
    }
    if ( layout.hDWP != nullptr )
      EndDeferWindowPos(hWinPosInfo: layout.hDWP);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033C52A
// Name: public: static int CWnd::WalkPreTranslateTree(struct HWND__ __near *,struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWnd::WalkPreTranslateTree(HWND__ *hWndStop, tagMSG *pMsg)
{
  HWND__ *i; // esi
  CWnd *v3; // eax

  for ( i = pMsg->hwnd; ; i = GetParent(hWnd: i) )
  {
    if ( i == nullptr )
      return 0;
    v3 = CWnd::FromHandlePermanent(hWnd: (CDocument *)i);
    if ( v3 != nullptr && v3->PreTranslateMessage(this: v3, a2: pMsg) != 0 )
      break;
    if ( i == hWndStop )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033C570
// Name: public: int CWnd::SendChildNotifyLastMsg(long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SendChildNotifyLastMsg(CWnd *this, int *pResult)
{
  CNoTrackObject *Data; // eax

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  return this->OnChildNotify(
           this,
           a2: (unsigned int)Data[23].__vftable,
           a3: (unsigned int)Data[24].__vftable,
           a4: (int)Data[25].__vftable,
           a5: pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1033C5AB
// Name: protected: void CWnd::OnSetFocus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnSetFocus(CWnd *this, CWnd *__formal)
{
  if ( this->m_pCtrlCont == nullptr || this->m_pCtrlCont->HandleSetFocus(this: this->m_pCtrlCont) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C5D0
// Name: protected: int CWnd::OnHelpInfo(struct tagHELPINFO __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::OnHelpInfo(CWnd *this, tagHELPINFO *__formal)
{
  CWnd *MainWnd; // edi

  if ( (CWnd::GetStyle(this) & 0x40000000) != 0 )
    return CWnd::Default(this) != 0;
  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr
    || GetKeyState(nVirtKey: 16) < 0
    || GetKeyState(nVirtKey: 17) < 0
    || GetKeyState(nVirtKey: 18) < 0 )
  {
    return CWnd::Default(this) != 0;
  }
  SendMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033C63C
// Name: protected: long CWnd::OnGetObject(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnGetObject(CWnd *this, unsigned int wParam, int lParam)
{
  CWnd *v3; // esi
  CWnd_vtbl *v5; // eax
  int lRet; // [esp+4h] [ebp-4h] BYREF

  v3 = this;
  if ( !this->m_bEnableActiveAccessibility )
    return CWnd::Default(this);
  v5 = this->__vftable;
  lRet = 0;
  if ( v5->CreateAccessibleProxy(this, a2: wParam, a3: lParam, a4: &lRet) < 0 )
  {
    this = v3;
    return CWnd::Default(this);
  }
  return lRet;
}

//------------------------------------------------------------------------------
// Address: 0x1033C67A
// Name: protected: void CWnd::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnHScroll(CWnd *this, unsigned int __formal, unsigned int a3, CScrollBar *pScrollBar)
{
  if ( pScrollBar == nullptr || CWnd::SendChildNotifyLastMsg(this: pScrollBar, pResult: nullptr) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C6A0
// Name: protected: void CWnd::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnPaint(CWnd *this)
{
  COleControlContainer *m_pCtrlCont; // ecx
  COleControlContainer_vtbl *v3; // eax
  CPaintDC v4; // [esp+10h] [ebp-64h] BYREF
  int v5; // [esp+70h] [ebp-4h]

  if ( this->m_pCtrlCont != nullptr )
  {
    CPaintDC::CPaintDC(this: &v4, pWnd: this);
    m_pCtrlCont = this->m_pCtrlCont;
    v3 = m_pCtrlCont->__vftable;
    v5 = 0;
    v3->OnPaint(this: m_pCtrlCont, a2: &v4);
    v5 = -1;
    CPaintDC::~CPaintDC(this: &v4);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C6E9
// Name: protected: void CWnd::OnEnterIdle(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnEnterIdle(CWnd *this, unsigned int __formal, CWnd *a3)
{
  tagMSG msg; // [esp+Ch] [ebp-1Ch] BYREF

  while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0x121u, wMsgFilterMax: 0x121u, wRemoveMsg: 1u) )
    DispatchMessageA(lpMsg: &msg);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C72B
// Name: protected: struct HBRUSH__ __near * CWnd::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::OnCtlColor(CWnd *this, CDC *__formal, CWnd *pWnd, unsigned int a4)
{
  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: (int *)&pWnd) != 0 )
    return pWnd;
  else
    return (CWnd *)CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033C7B7
// Name: public: struct HWND__ __near * CWnd::UnsubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall CWnd::UnsubclassWindow(CWnd *this)
{
  LONG *v2; // edi

  v2 = (LONG *)this->GetSuperWndProcAddr(this);
  SetWindowLongA(hWnd: this->m_hWnd, nIndex: -4, dwNewLong: *v2);
  *v2 = 0;
  return CWnd::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CA05
// Name: public: virtual CWnd::~CWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::~CWnd(CWnd *this)
{
  COleControlContainer *m_pCtrlCont; // ecx
  COleControlSite *m_pCtrlSite; // eax
  CMFCControlContainer *m_pMFCCtrlContainer; // ecx

  this->__vftable = (CWnd_vtbl *)&CWnd::`vftable';
  if ( this->m_hWnd != nullptr
    && this != &CWnd::wndTop
    && this != &CWnd::wndBottom
    && this != &CWnd::wndTopMost
    && this != &CWnd::wndNoTopMost )
  {
    CWnd::DestroyWindow(this);
  }
  m_pCtrlCont = this->m_pCtrlCont;
  if ( m_pCtrlCont != nullptr )
    ((void (__thiscall *)(COleControlContainer *, int))m_pCtrlCont->dtr_CObject)(a1: m_pCtrlCont, a2: 1);
  m_pCtrlSite = this->m_pCtrlSite;
  if ( m_pCtrlSite != nullptr && m_pCtrlSite->m_pWndCtrl == this )
    m_pCtrlSite->m_pWndCtrl = nullptr;
  m_pMFCCtrlContainer = this->m_pMFCCtrlContainer;
  if ( m_pMFCCtrlContainer != nullptr )
    ((void (__thiscall *)(CMFCControlContainer *, int))m_pMFCCtrlContainer->dtr_CObject)(a1: m_pMFCCtrlContainer, a2: 1);
  if ( this->m_pCurrentGestureInfo != nullptr )
    operator delete(p: this->m_pCurrentGestureInfo);
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CA96
// Name: protected: int CWnd::OnVKeyToItem(unsigned int,class CListBox __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CListBox *__thiscall CWnd::OnVKeyToItem(CWnd *this, unsigned int __formal, CListBox *pWnd, unsigned int a4)
{
  if ( pWnd != nullptr && CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: (int *)&pWnd) != 0 )
    return pWnd;
  else
    return (CListBox *)CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CAC3
// Name: protected: void CWnd::OnMeasureItem(int,struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnMeasureItem(CWnd *this, int __formal, tagMEASUREITEMSTRUCT *lpMeasureItemStruct)
{
  CNoTrackObject *Data; // eax
  CMenu *v5; // eax
  CMenu *PopupMenuFromID; // eax
  CWnd *DescendantWindow; // eax

  if ( lpMeasureItemStruct->CtlType == 1 )
  {
    Data = CThreadLocalObject::GetData(
             this: &_afxThreadState,
             pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
    if ( Data == nullptr
      || (Data[29].__vftable != (CNoTrackObject_vtbl *)this->m_hWnd
        ? (v5 = this->GetMenu(this))
        : (v5 = CMenu::FromHandle(hMenu: (HMENU__ *)Data[30].__vftable)),
          v5 == nullptr) )
    {
      AfxThrowInvalidArgException();
    }
    PopupMenuFromID = _AfxFindPopupMenuFromID(pMenu: v5, nID: (HMENU__ *)lpMeasureItemStruct->itemID);
    if ( PopupMenuFromID != nullptr )
      PopupMenuFromID->MeasureItem(this: PopupMenuFromID, a2: lpMeasureItemStruct);
    goto LABEL_12;
  }
  DescendantWindow = CWnd::GetDescendantWindow(hWnd: this->m_hWnd, nID: lpMeasureItemStruct->CtlID, bOnlyPerm: 1);
  if ( DescendantWindow == nullptr || CWnd::SendChildNotifyLastMsg(this: DescendantWindow, pResult: nullptr) == 0 )
LABEL_12:
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CB4C
// Name: public: class CFrameWnd __near * CWnd::GetParentFrame(void)const
// Source: json
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CWnd::GetParentFrame(CWnd *this)
{
  HWND__ *m_hWnd; // eax
  CFrameWnd *result; // eax
  HWND i; // eax
  CFrameWnd *v4; // esi

  if ( this == nullptr )
    return nullptr;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd == nullptr )
    return nullptr;
  for ( i = GetParent(hWnd: m_hWnd); ; i = GetParent(hWnd: v4->m_hWnd) )
  {
    result = (CFrameWnd *)CWnd::FromHandle(hWnd: i);
    v4 = result;
    if ( result == nullptr )
      break;
    if ( result->IsFrameWnd(this: result) != 0 )
      return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033CB8B
// Name: public: class CFrameWnd __near * CWnd::GetTopLevelFrame(void)const
// Source: json
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CWnd::GetTopLevelFrame(CWnd *this)
{
  CFrameWnd *ParentFrame; // esi
  CWnd *i; // ecx
  CFrameWnd *v4; // eax

  ParentFrame = (CFrameWnd *)this;
  if ( this == nullptr || this->m_hWnd == nullptr )
    return nullptr;
  if ( this->IsFrameWnd(this) == 0 )
    ParentFrame = CWnd::GetParentFrame(this: ParentFrame);
  if ( ParentFrame != nullptr )
  {
    for ( i = ParentFrame; ; i = v4 )
    {
      v4 = CWnd::GetParentFrame(this: i);
      if ( v4 == nullptr )
        break;
      ParentFrame = v4;
    }
  }
  return ParentFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1033CBCC
// Name: public: static void CWnd::SendMessageToDescendants(struct HWND__ __near *,unsigned int,unsigned int,long,int,int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CWnd::SendMessageToDescendants(
        HWND__ *hWnd,
        CNoTrackObject_vtbl *message,
        CNoTrackObject_vtbl *wParam,
        CNoTrackObject_vtbl *lParam,
        int bDeep,
        int bOnlyPerm)
{
  HWND i; // eax
  CWnd *v7; // eax
  HWND__ *v8; // esi

  for ( i = GetTopWindow(hWnd); ; i = GetWindow(hWnd: v8, uCmd: 2u) )
  {
    v8 = i;
    if ( i == nullptr )
      break;
    if ( bOnlyPerm != 0 )
    {
      v7 = CWnd::FromHandlePermanent(hWnd: (CDocument *)i);
      if ( v7 != nullptr )
        AfxCallWndProc(pWnd: v7, hWnd: (CNoTrackObject_vtbl *)v7->m_hWnd, nMsg: message, wParam, lParam);
    }
    else
    {
      SendMessageA(hWnd: i, Msg: (UINT)message, (WPARAM)wParam, (LPARAM)lParam);
    }
    if ( bDeep != 0 && GetTopWindow(hWnd: v8) != nullptr )
      CWnd::SendMessageToDescendants(
        hWnd: v8,
        (unsigned int)message,
        (unsigned int)wParam,
        (int)lParam,
        bDeep,
        bOnlyPerm);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033CC4B
// Name: protected: static int CWnd::ReflectLastMsg(struct HWND__ __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWnd::ReflectLastMsg(HWND__ *hWndChild, int *pResult)
{
  CHandleMap *v2; // eax
  CMapPtrToPtr *p_m_permanentMap; // esi
  CWnd *ValueAt; // eax
  CDocument *Parent; // eax
  _DWORD *v7; // eax
  int v8; // eax
  COleControlSite *v9; // esi
  int v10; // eax
  BOOL v11; // esi
  CWnd wndTemp; // [esp+10h] [ebp-80h] BYREF
  int v13; // [esp+8Ch] [ebp-4h]

  v2 = afxMapHWND(bCreate: 0);
  if ( v2 == nullptr )
    return 0;
  p_m_permanentMap = &v2->m_permanentMap;
  ValueAt = (CWnd *)CMapPtrToPtr::GetValueAt(this: &v2->m_permanentMap, key: (CDocument *)hWndChild);
  if ( ValueAt != nullptr )
    return CWnd::SendChildNotifyLastMsg(this: ValueAt, pResult);
  Parent = (CDocument *)GetParent(hWnd: hWndChild);
  v7 = CMapPtrToPtr::GetValueAt(this: p_m_permanentMap, key: Parent);
  if ( v7 == nullptr )
    return 0;
  v8 = v7[26];
  if ( v8 == 0 )
    return 0;
  v9 = (COleControlSite *)CMapPtrToPtr::GetValueAt(this: (CMapPtrToPtr *)(v8 + 36), key: (CDocument *)hWndChild);
  if ( v9 == nullptr )
    return 0;
  CWnd::CWnd(this: &wndTemp, hWnd: hWndChild);
  v13 = 0;
  wndTemp.m_pCtrlSite = v9;
  v10 = CWnd::SendChildNotifyLastMsg(this: &wndTemp, pResult);
  wndTemp.m_hWnd = nullptr;
  v13 = -1;
  v11 = v10 != 0;
  CWnd::~CWnd(this: &wndTemp);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1033CCEB
// Name: protected: void CWnd::OnParentNotify(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnParentNotify(CWnd *this, __int16 message, HWND__ *lParam)
{
  if ( message != 1 && message != 2 || CWnd::ReflectLastMsg(hWndChild: lParam, pResult: nullptr) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CD1B
// Name: protected: long CWnd::OnDragList(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnDragList(CWnd *this, unsigned int __formal, int lParam)
{
  if ( CWnd::ReflectLastMsg(hWndChild: *(HWND__ **)(lParam + 4), pResult: &lParam) != 0 )
    return lParam;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033CD47
// Name: public: void CWnd::UpdateDialogControls(class CCmdTarget __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::UpdateDialogControls(CWnd *this, CCmdTarget *pTarget, int bDisableIfNoHndler)
{
  HWND__ *i; // eax
  CWnd *v5; // eax
  int v6; // ebx
  unsigned int v7; // eax
  CDocument *v8; // esi
  HWND__ *m_hWnd; // [esp-4h] [ebp-C0h]
  CWnd wndTemp; // [esp+10h] [ebp-ACh] BYREF
  CCmdUI state; // [esp+84h] [ebp-38h] BYREF
  CCmdTarget *v12; // [esp+ACh] [ebp-10h]
  int v13; // [esp+B8h] [ebp-4h]

  v12 = this;
  CCmdUI::CCmdUI(this: &state);
  CWnd::CWnd(this: &wndTemp);
  m_hWnd = this->m_hWnd;
  v13 = 0;
  for ( i = GetTopWindow(hWnd: m_hWnd); ; i = GetWindow(hWnd: (HWND)v8, uCmd: 2u) )
  {
    v8 = (CDocument *)i;
    if ( i == nullptr )
      break;
    wndTemp.m_hWnd = i;
    state.m_nID = GetDlgCtrlID(hWnd: i);
    state.m_pOther = &wndTemp;
    v5 = CWnd::FromHandlePermanent(hWnd: v8);
    if ( (v5 == nullptr
       || CCmdTarget::OnCmdMsg(
            this: v5,
            nID: 0,
            nCode: 0xBD11FFFF,
            pExtra: (const _GUID *)&state,
            pHandlerInfo: nullptr) == 0)
      && CCmdTarget::OnCmdMsg(
           this: v12,
           nID: state.m_nID,
           nCode: 0xFFFFFFFF,
           pExtra: (const _GUID *)&state,
           pHandlerInfo: nullptr) == 0 )
    {
      v6 = bDisableIfNoHndler;
      if ( bDisableIfNoHndler != 0
        && ((SendMessageA(hWnd: wndTemp.m_hWnd, Msg: 0x87u, wParam: 0, lParam: 0) & 0x2000) == 0
         || (v7 = CWnd::GetStyle(this: &wndTemp) & 0xF) == 3
         || v7 == 6
         || v7 == 7
         || v7 == 9) )
      {
        v6 = 0;
      }
      CCmdUI::DoUpdate(this: &state, pTarget, bDisableIfNoHndler: v6);
    }
  }
  v13 = -1;
  wndTemp.m_hWnd = nullptr;
  CWnd::~CWnd(this: &wndTemp);
}

//------------------------------------------------------------------------------
// Address: 0x1033CE51
// Name: public: int CWnd::SubclassWindow(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SubclassWindow(CWnd *this, HWND__ *hWnd)
{
  int result; // eax
  int (__stdcall **v4)(HWND__ *, unsigned int, unsigned int, int); // esi
  LONG v5; // eax

  result = CWnd::Attach(this, hWndNew: hWnd);
  if ( result != 0 )
  {
    this->PreSubclassWindow(this);
    v4 = this->GetSuperWndProcAddr(this);
    v5 = SetWindowLongA(hWnd, nIndex: -4, dwNewLong: (LONG)AfxWndProc);
    if ( *v4 == nullptr )
      *v4 = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))v5;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033CE97
// Name: public: int CWnd::SubclassDlgItem(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SubclassDlgItem(CWnd *this, unsigned int nID, CWnd *pParent)
{
  HWND DlgItem; // eax
  COleControlSite *v6; // eax
  COleControlSite *v7; // edi

  DlgItem = GetDlgItem(hDlg: pParent->m_hWnd, nIDDlgItem: nID);
  if ( DlgItem != nullptr )
    return CWnd::SubclassWindow(this, hWnd: DlgItem);
  if ( pParent->m_pCtrlCont == nullptr )
    return 0;
  v6 = pParent->m_pCtrlCont->FindItem(this: pParent->m_pCtrlCont, a2: nID);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  CWnd::SubclassWindow(this, hWnd: v6->m_hWnd);
  if ( pParent->m_hWnd != GetParent(hWnd: v7->m_hWnd) )
    CWnd::AttachControlSite(this, pWndParent: pParent, nIDC: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033D47F
// Name: public: class CWnd __near * CWnd::GetOwner(void)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetOwner(CWnd *this)
{
  HWND__ *m_hWndOwner; // eax

  m_hWndOwner = this->m_hWndOwner;
  if ( m_hWndOwner == nullptr )
    m_hWndOwner = GetParent(hWnd: this->m_hWnd);
  return CWnd::FromHandle(hWnd: m_hWndOwner);
}

//------------------------------------------------------------------------------
// Address: 0x1033D4B7
// Name: public: void CWnd::GetWindowTextA(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::GetWindowTextA(
        CWnd *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString)
{
  int WindowTextLengthA; // eax
  CHAR *BufferSetLength; // eax
  int v5; // [esp-4h] [ebp-8h]

  if ( this->m_pCtrlSite != nullptr )
  {
    this->m_pCtrlSite->GetWindowTextA(this: this->m_pCtrlSite, a2: rString);
  }
  else
  {
    WindowTextLengthA = GetWindowTextLengthA(hWnd: this->m_hWnd);
    v5 = WindowTextLengthA + 1;
    BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: WindowTextLengthA);
    GetWindowTextA(hWnd: this->m_hWnd, lpString: BufferSetLength, nMaxCount: v5);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033D501
// Name: protected: void CWnd::OnDrawItem(int,struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnDrawItem(CWnd *this, int __formal, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  CMenu *v4; // eax

  if ( lpDrawItemStruct->CtlType == 1
    && (v4 = CMenu::FromHandlePermanent(hMenu: (HMENU__ *)lpDrawItemStruct->hwndItem)) != nullptr )
  {
    v4->DrawItem(this: v4, a2: lpDrawItemStruct);
  }
  else if ( CWnd::ReflectLastMsg(hWndChild: lpDrawItemStruct->hwndItem, pResult: nullptr) == 0 )
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033D543
// Name: protected: int CWnd::OnCompareItem(int,struct tagCOMPAREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
tagCOMPAREITEMSTRUCT *__thiscall CWnd::OnCompareItem(
        CWnd *this,
        int __formal,
        tagCOMPAREITEMSTRUCT *lpCompareItemStruct)
{
  if ( CWnd::ReflectLastMsg(hWndChild: lpCompareItemStruct->hwndItem, pResult: (int *)&lpCompareItemStruct) != 0 )
    return lpCompareItemStruct;
  else
    return (tagCOMPAREITEMSTRUCT *)CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033D56F
// Name: protected: void CWnd::OnDeleteItem(int,struct tagDELETEITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnDeleteItem(CWnd *this, int __formal, tagDELETEITEMSTRUCT *lpDeleteItemStruct)
{
  if ( CWnd::ReflectLastMsg(hWndChild: lpDeleteItemStruct->hwndItem, pResult: nullptr) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033D614
// Name: protected: virtual int CWnd::OnCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnCommand(CWnd *this, unsigned int wParam, HWND__ *lParam)
{
  unsigned int v3; // edi
  CWnd_vtbl *v6; // eax
  CNoTrackObject *Data; // eax
  CTestCmdUI state; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned int nCode; // [esp+40h] [ebp+8h]

  v3 = (unsigned __int16)wParam;
  nCode = HIWORD(wParam);
  if ( lParam != nullptr )
  {
    Data = CThreadLocalObject::GetData(
             this: &_afxThreadState,
             pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
    if ( Data == nullptr )
      AfxThrowInvalidArgException();
    if ( Data[55].__vftable == (CNoTrackObject_vtbl *)this->m_hWnd
      || CWnd::ReflectLastMsg(hWndChild: lParam, pResult: nullptr) != 0 )
    {
      return 1;
    }
    if ( v3 == 0 )
      return 0;
  }
  else
  {
    if ( v3 == 0 )
      return 0;
    CTestCmdUI::CTestCmdUI(this: &state);
    v6 = this->__vftable;
    state.m_nID = v3;
    v6->OnCmdMsg(this, a2: v3, a3: -1, a4: &state, a5: nullptr);
    if ( state.m_bEnabled == 0 )
      return 1;
    nCode = 0;
  }
  return this->OnCmdMsg(this, a2: v3, a3: nCode, a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1033D6AD
// Name: protected: virtual int CWnd::OnNotify(unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnNotify(CWnd *this, unsigned int __formal, tagNMHDR *lParam, int *pResult)
{
  HWND__ *hwndFrom; // ebx
  CNoTrackObject *Data; // eax
  CWnd_vtbl *v9; // eax
  AFX_NOTIFY notify; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int nID; // [esp+14h] [ebp-4h]
  int nCode; // [esp+24h] [ebp+Ch]

  hwndFrom = lParam->hwndFrom;
  nID = GetDlgCtrlID(hWnd: lParam->hwndFrom);
  nCode = lParam->code;
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( Data[55].__vftable == (CNoTrackObject_vtbl *)this->m_hWnd
    || CWnd::ReflectLastMsg(hWndChild: hwndFrom, pResult) != 0 )
  {
    return 1;
  }
  notify.pResult = pResult;
  v9 = this->__vftable;
  notify.pNMHDR = lParam;
  return v9->OnCmdMsg(this, a2: nID, a3: (unsigned __int16)nCode | 0x4E0000, a4: &notify, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1033D779
// Name: public: class CWnd __near * CWnd::GetTopLevelParent(void)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetTopLevelParent(CWnd *this)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v3; // esi

  if ( this == nullptr )
    return nullptr;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd == nullptr )
    return nullptr;
  do
  {
    v3 = m_hWnd;
    m_hWnd = AfxGetParentOwner(hWnd: m_hWnd);
  }
  while ( m_hWnd != nullptr );
  return CWnd::FromHandle(hWnd: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1033D7A1
// Name: public: int CWnd::HandleFloatingSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::HandleFloatingSysCommand(CWnd *this, WPARAM nID, LPARAM lParam)
{
  CWnd *TopLevelParent; // esi
  HWND__ *m_hWnd; // ebx
  HWND v6; // eax
  HWND__ *hWndFocus; // [esp+8h] [ebp-4h]

  TopLevelParent = CWnd::GetTopLevelParent(this);
  if ( (nID & 0xFFF0) == 0xF040 || (nID & 0xFFF0) == 0xF050 )
  {
    if ( (_WORD)lParam == 117 && TopLevelParent != nullptr )
    {
      CWnd::SetFocus(this: TopLevelParent);
      return 1;
    }
  }
  else if ( (nID & 0xFFF0) == 0xF060 || (nID & 0xFFF0) == 0xF100 )
  {
    if ( ((nID & 0xFFF0) == 0xF060 || lParam != 0) && TopLevelParent != nullptr )
    {
      m_hWnd = this->m_hWnd;
      hWndFocus = GetFocus();
      v6 = SetActiveWindow(hWnd: TopLevelParent->m_hWnd);
      CWnd::FromHandle(hWnd: v6);
      SendMessageA(hWnd: TopLevelParent->m_hWnd, Msg: 0x112u, wParam: nID, lParam);
      if ( IsWindow(hWnd: m_hWnd) )
        SetActiveWindow(hWnd: m_hWnd);
      if ( IsWindow(hWnd: hWndFocus) )
        SetFocus(hWnd: hWndFocus);
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033D861
// Name: protected: void CWnd::OnSysColorChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnSysColorChange(CWnd *this)
{
  CWinApp *m_pCurrentWinApp; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr && m_pCurrentWinApp->m_pMainWnd == this )
    AUX_DATA::UpdateSysColors(this: &afxData);
  if ( (CWnd::GetStyle(this) & 0x40000000) == 0 )
    CWnd::SendMessageToDescendants(
      hWnd: this->m_hWnd,
      message: (CNoTrackObject_vtbl *)0x15,
      wParam: nullptr,
      lParam: nullptr,
      bDeep: 1,
      bOnlyPerm: 1);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033D8A9
// Name: protected: void CWnd::OnDevModeChange(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnDevModeChange(CWnd *this, char *lpDeviceName)
{
  CWinApp *m_pCurrentWinApp; // eax
  CNoTrackObject *CurrentMessage; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr && m_pCurrentWinApp->m_pMainWnd == this )
    CWinApp::DevModeChange(this: m_pCurrentWinApp, lpDeviceName);
  if ( (CWnd::GetStyle(this) & 0x40000000) == 0 )
  {
    CurrentMessage = CWnd::GetCurrentMessage();
    CWnd::SendMessageToDescendants(
      hWnd: this->m_hWnd,
      message: CurrentMessage[1].__vftable,
      wParam: CurrentMessage[2].__vftable,
      lParam: CurrentMessage[3].__vftable,
      bDeep: 1,
      bOnlyPerm: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033D8F9
// Name: protected: long CWnd::OnDisplayChange(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnDisplayChange(CWnd *this, unsigned int __formal, unsigned int __formala)
{
  CNoTrackObject *CurrentMessage; // eax

  if ( AfxGetMainWnd() == this )
    AUX_DATA::UpdateSysMetrics(this: &afxData);
  if ( (CWnd::GetStyle(this) & 0x40000000) == 0 )
  {
    CurrentMessage = CWnd::GetCurrentMessage();
    CWnd::SendMessageToDescendants(
      hWnd: this->m_hWnd,
      message: CurrentMessage[1].__vftable,
      wParam: CurrentMessage[2].__vftable,
      lParam: CurrentMessage[3].__vftable,
      bDeep: 1,
      bOnlyPerm: 1);
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033E05E
// Name: public: virtual int CWnd::CreateEx(unsigned long,char const __near *,char const __near *,unsigned long,int,int,int,int,struct HWND__ __near *,struct HMENU__ __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::CreateEx(
        CWnd *this,
        unsigned int dwExStyle,
        const char *lpszClassName,
        const char *lpszWindowName,
        unsigned int dwStyle,
        int x,
        int y,
        int nWidth,
        int nHeight,
        HWND__ *hWndParent,
        HMENU__ *nIDorHMenu,
        void *lpParam)
{
  HWND__ *Window; // edi
  tagCREATESTRUCTA v15; // [esp+8h] [ebp-30h] BYREF

  if ( lpszWindowName != nullptr && !AfxIsValidString(psz: lpszWindowName, nLength: -1) )
    AfxThrowInvalidArgException();
  v15.dwExStyle = dwExStyle;
  v15.lpszClass = lpszClassName;
  v15.style = dwStyle;
  v15.x = x;
  v15.y = y;
  v15.cx = nWidth;
  v15.cy = nHeight;
  v15.hwndParent = hWndParent;
  v15.lpszName = lpszWindowName;
  v15.hMenu = nIDorHMenu;
  v15.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  v15.lpCreateParams = lpParam;
  if ( this->PreCreateWindow(this, a2: &v15) != 0 )
  {
    AfxHookWindowCreate(pWnd: this);
    Window = AfxCtxCreateWindowExA(
               dwExStyle: v15.dwExStyle,
               lpClassName: v15.lpszClass,
               lpWindowName: v15.lpszName,
               dwStyle: v15.style,
               X: v15.x,
               Y: v15.y,
               nWidth: v15.cx,
               nHeight: v15.cy,
               hWndParent: v15.hwndParent,
               hMenu: v15.hMenu,
               hInstance: v15.hInstance,
               lpParam: v15.lpCreateParams);
    if ( AfxUnhookWindowCreate() == 0 )
      this->PostNcDestroy(this);
    return Window != nullptr;
  }
  else
  {
    this->PostNcDestroy(this);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033E13D
// Name: public: void CWnd::PrepareForHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::PrepareForHelp(CWnd *this)
{
  CWnd *TopLevelParent; // eax
  CWnd *v3; // ebx
  HWND Capture; // eax

  if ( this->IsFrameWnd(this) != 0 )
    ((void (__thiscall *)(CWnd *))this->__vftable[1].GetConnectionHook)(a1: this);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  CWnd::SendMessageToDescendants(
    hWnd: this->m_hWnd,
    message: (CNoTrackObject_vtbl *)0x1F,
    wParam: nullptr,
    lParam: nullptr,
    bDeep: 1,
    bOnlyPerm: 1);
  TopLevelParent = CWnd::GetTopLevelParent(this);
  v3 = TopLevelParent;
  if ( TopLevelParent == nullptr )
    AfxThrowInvalidArgException();
  SendMessageA(hWnd: TopLevelParent->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  CWnd::SendMessageToDescendants(
    hWnd: v3->m_hWnd,
    message: (CNoTrackObject_vtbl *)0x1F,
    wParam: nullptr,
    lParam: nullptr,
    bDeep: 1,
    bOnlyPerm: 1);
  Capture = GetCapture();
  if ( Capture != nullptr )
    SendMessageA(hWnd: Capture, Msg: 0x1Fu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1033E1BB
// Name: protected: virtual int CWnd::OnWndMsg(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnWndMsg(CWnd *this, unsigned int message, WPARAM wParam, unsigned int lParam, int *pResult)
{
  int v6; // eax
  CWnd *v8; // eax
  COleControlContainer *m_pCtrlCont; // eax
  AFX_MSG_CACHE *v10; // ebx
  const AFX_MSGMAP_ENTRY *v11; // ebx
  AFX_MSG_CACHE *v12; // eax
  int v13; // ebx
  const AFX_MSGMAP_ENTRY *MessageEntry; // eax
  void (__thiscall *pfn)(CCmdTarget *); // ebx
  unsigned int nSig; // eax
  const AFX_MSGMAP_ENTRY *i; // eax
  CWnd *v19; // eax
  int v20; // eax
  CWnd *v21; // eax
  CWnd *v22; // eax
  HDC__ *v23; // eax
  CDocument *v24; // eax
  int v25; // esi
  CWnd *p_wndTemp; // eax
  COleControlContainer *v27; // eax
  COleControlSite *ValueAt; // eax
  int v29; // eax
  int v30; // eax
  CWnd *v31; // eax
  CWnd *v32; // eax
  int v33; // eax
  CWnd *v34; // eax
  CWnd *v35; // eax
  CWnd *v36; // eax
  CWnd *v37; // eax
  int v38; // edx
  int v39; // ecx
  CWnd *v40; // eax
  CWnd *v41; // [esp-8h] [ebp-B4h]
  unsigned int v42; // [esp-4h] [ebp-B0h]
  CDC *v43; // [esp-4h] [ebp-B0h]
  unsigned int v44; // [esp-4h] [ebp-B0h]
  int v45; // [esp-4h] [ebp-B0h]
  CMenu *v46; // [esp-4h] [ebp-B0h]
  unsigned int v47; // [esp-4h] [ebp-B0h]
  unsigned int v48; // [esp-4h] [ebp-B0h]
  unsigned int v49; // [esp-4h] [ebp-B0h]
  CWnd *v50; // [esp-4h] [ebp-B0h]
  CMenu *v51; // [esp-4h] [ebp-B0h]
  CWnd wndTemp; // [esp+10h] [ebp-9Ch] BYREF
  CDC dcTemp; // [esp+84h] [ebp-28h] BYREF
  AFX_MSG_CACHE *pMsgCache; // [esp+94h] [ebp-18h]
  CInternalGlobalLock winMsgLock; // [esp+98h] [ebp-14h] BYREF
  int lResult[3]; // [esp+9Ch] [ebp-10h] BYREF
  int v57; // [esp+A8h] [ebp-4h]
  int nScrollCode; // [esp+B4h] [ebp+8h]
  int nPos; // [esp+B8h] [ebp+Ch]
  const AFX_MSGMAP *lpEntry; // [esp+BCh] [ebp+10h]
  const AFX_MSGMAP_ENTRY *lpEntrya; // [esp+BCh] [ebp+10h]

  lResult[0] = 0;
  winMsgLock.m_nLockType = 0x7FFFFFFF;
  v57 = 0;
  if ( message != 273 )
  {
    if ( message != 78 )
    {
      if ( message == 6 )
      {
        v8 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
        _AfxHandleActivate(pWnd: this, nState: wParam, pWndOther: v8);
      }
      if ( message == 32 && _AfxHandleSetCursor(pWnd: this, nHitTest: (__int16)lParam, nMsg: HIWORD(lParam)) != 0 )
        goto LABEL_3;
      m_pCtrlCont = this->m_pCtrlCont;
      if ( m_pCtrlCont != nullptr
        && m_pCtrlCont->m_nWindowlessControls > 0
        && (message >= 0x200 && message <= 0x209 || message >= 0x100 && message <= 0x10F || message - 641 <= 0x10)
        && this->m_pCtrlCont->HandleWindowlessMessage(
             this: this->m_pCtrlCont,
             a2: message,
             a3: wParam,
             a4: lParam,
             a5: lResult) != 0 )
      {
        goto LReturnTrue;
      }
      lpEntry = this->GetMessageMap(this);
      CInternalGlobalLock::Lock(this: &winMsgLock, nLockType: 7);
      v10 = &_afxMsgCache[((unsigned __int16)message ^ (unsigned __int16)lpEntry) & 0x1FF];
      pMsgCache = v10;
      if ( message == v10->nMsg && lpEntry == v10->pMessageMap )
      {
        v11 = v10->lpEntry;
        lpEntrya = _afxMsgCache[((unsigned __int16)message ^ (unsigned __int16)lpEntry) & 0x1FF].lpEntry;
        CInternalGlobalLock::Unlock(this: &winMsgLock);
        if ( v11 == nullptr )
          goto LABEL_39;
        if ( message < 0xC000 )
        {
LDispatch:
          pfn = lpEntrya->pfn;
          nSig = lpEntrya->nSig;
          switch ( nSig )
          {
            case 1u:
              v43 = CDC::FromHandle(hDC: (HDC__ *)wParam);
              v20 = ((int (__thiscall *)(CWnd *, CDC *))pfn)(a1: this, a2: v43);
              goto LABEL_111;
            case 2u:
            case 3u:
            case 4u:
            case 0x1Bu:
            case 0x1Cu:
              v20 = ((int (__thiscall *)(CWnd *, WPARAM))pfn)(a1: this, a2: wParam);
              goto LABEL_111;
            case 5u:
            case 0xCu:
              v22 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              v20 = ((int (__thiscall *)(CWnd *, CWnd *, _DWORD, unsigned int))pfn)(
                      a1: this,
                      a2: v22,
                      a3: (unsigned __int16)lParam,
                      a4: HIWORD(lParam));
              goto LABEL_111;
            case 6u:
            case 0x47u:
              v42 = lParam;
              v19 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              goto LABEL_41;
            case 7u:
            case 0xDu:
            case 0x4Au:
              v20 = ((int (__thiscall *)(CWnd *, unsigned int))pfn)(a1: this, a2: lParam);
              goto LABEL_111;
            case 8u:
              CDC::CDC(this: &dcTemp);
              v23 = *(HDC__ **)(lParam + 4);
              LOBYTE(v57) = 1;
              dcTemp.m_hDC = v23;
              CWnd::CWnd(this: &wndTemp);
              v24 = *(CDocument **)lParam;
              v25 = *(_DWORD *)(lParam + 8);
              LOBYTE(v57) = 2;
              wndTemp.m_hWnd = (HWND__ *)v24;
              p_wndTemp = CWnd::FromHandlePermanent(hWnd: v24);
              if ( p_wndTemp == nullptr )
              {
                v27 = this->m_pCtrlCont;
                if ( v27 != nullptr )
                {
                  ValueAt = (COleControlSite *)CMapPtrToPtr::GetValueAt(
                                                 this: &v27->m_siteMap,
                                                 key: (CDocument *)wndTemp.m_hWnd);
                  if ( ValueAt != nullptr )
                    wndTemp.m_pCtrlSite = ValueAt;
                }
                p_wndTemp = &wndTemp;
              }
              v29 = ((int (__thiscall *)(CWnd *, CDC *, CWnd *, int))pfn)(a1: this, a2: &dcTemp, a3: p_wndTemp, a4: v25);
              dcTemp.m_hDC = nullptr;
              wndTemp.m_hWnd = nullptr;
              lResult[0] = v29;
              LOBYTE(v57) = 1;
              CWnd::~CWnd(this: &wndTemp);
              goto LABEL_57;
            case 9u:
              CDC::CDC(this: &dcTemp);
              v45 = *(_DWORD *)(lParam + 8);
              dcTemp.m_hDC = *(HDC__ **)(lParam + 4);
              LOBYTE(v57) = 3;
              v30 = ((int (__thiscall *)(CWnd *, CDC *, int))pfn)(a1: this, a2: &dcTemp, a3: v45);
              dcTemp.m_hDC = nullptr;
              lResult[0] = v30;
LABEL_57:
              LOBYTE(v57) = 0;
              CDC::~CDC(this: &dcTemp);
              goto LReturnTrue;
            case 0xAu:
              v46 = (CMenu *)HIWORD(wParam);
              v31 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
              goto LABEL_60;
            case 0xBu:
              v42 = HIWORD(wParam);
              v19 = (CWnd *)(unsigned __int16)wParam;
              goto LABEL_41;
            case 0xEu:
            case 0x2Fu:
            case 0x4Fu:
              goto $LN58_9;
            case 0xFu:
              v46 = CMenu::FromHandle(hMenu: (HMENU__ *)lParam);
              v31 = (CWnd *)HIWORD(wParam);
LABEL_60:
              v20 = ((int (__thiscall *)(CWnd *, _DWORD, CWnd *, CMenu *))pfn)(
                      a1: this,
                      a2: (unsigned __int16)wParam,
                      a3: v31,
                      a4: v46);
              goto LABEL_111;
            case 0x10u:
            case 0x12u:
            case 0x15u:
            case 0x1Eu:
            case 0x2Du:
            case 0x32u:
            case 0x4Cu:
            case 0x53u:
            case 0x54u:
              v44 = lParam;
              goto LABEL_106;
            case 0x11u:
            case 0x14u:
              ((void (__thiscall *)(CWnd *, WPARAM))pfn)(a1: this, a2: wParam);
              goto LReturnTrue;
            case 0x13u:
              pfn(this);
              goto LReturnTrue;
            case 0x16u:
              v47 = HIWORD(wParam);
              v32 = (CWnd *)(unsigned __int16)wParam;
              goto LABEL_67;
            case 0x17u:
              v47 = SHIWORD(lParam);
              v32 = (CWnd *)(__int16)lParam;
              goto LABEL_67;
            case 0x18u:
            case 0x19u:
              v48 = HIWORD(lParam);
              v33 = (unsigned __int16)lParam;
              goto LABEL_70;
            case 0x1Au:
              v21 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
              goto LABEL_47;
            case 0x1Du:
            case 0x28u:
            case 0x31u:
              v20 = ((int (__thiscall *)(CWnd *))pfn)(a1: this);
              goto LABEL_111;
            case 0x1Fu:
              v49 = (unsigned int)CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              v41 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
              v34 = (CWnd *)(this->m_hWnd == (HWND__ *)lParam);
              goto LABEL_72;
            case 0x20u:
              v35 = (CWnd *)CDC::FromHandle(hDC: (HDC__ *)wParam);
              goto LABEL_74;
            case 0x21u:
              v35 = (CWnd *)CMenu::FromHandle(hMenu: (HMENU__ *)wParam);
              goto LABEL_74;
            case 0x22u:
              v49 = SHIWORD(lParam);
              v41 = (CWnd *)(__int16)lParam;
              v34 = (CWnd *)CMenu::FromHandle(hMenu: (HMENU__ *)wParam);
              goto LABEL_72;
            case 0x23u:
              v35 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              goto LABEL_74;
            case 0x24u:
              v35 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
LABEL_74:
              ((void (__thiscall *)(CWnd *, CWnd *))pfn)(a1: this, a2: v35);
              goto LReturnTrue;
            case 0x25u:
              v49 = HIWORD(lParam);
              v36 = (CWnd *)(unsigned __int16)lParam;
              goto LABEL_81;
            case 0x26u:
              v36 = (CWnd *)(__int16)lParam;
              v49 = SHIWORD(lParam);
LABEL_81:
              v41 = v36;
              v34 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              goto LABEL_72;
            case 0x27u:
              v47 = lParam;
              v32 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              goto LABEL_67;
            case 0x29u:
              v49 = HIWORD(wParam);
              v37 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
              goto LABEL_85;
            case 0x2Au:
            case 0x2Bu:
              v38 = (__int16)wParam;
              v39 = SHIWORD(wParam);
              nScrollCode = (__int16)wParam;
              nPos = SHIWORD(wParam);
              if ( nSig == 42 )
              {
                v50 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
                ((void (__thiscall *)(CWnd *, int, int, CWnd *))pfn)(a1: this, a2: nScrollCode, a3: nPos, a4: v50);
              }
              else
              {
                ((void (__thiscall *)(CWnd *, int, int))pfn)(a1: this, a2: v38, a3: v39);
              }
              goto LReturnTrue;
            case 0x2Cu:
            case 0x33u:
              ((void (__thiscall *)(CWnd *, unsigned int))pfn)(a1: this, a2: lParam);
              goto LReturnTrue;
            case 0x2Eu:
            case 0x36u:
            case 0x52u:
              ((void (__thiscall *)(CWnd *, WPARAM, unsigned int))pfn)(a1: this, a2: wParam, a3: lParam);
              goto LABEL_3;
            case 0x30u:
            case 0x46u:
              v19 = (CWnd *)(__int16)lParam;
              v42 = SHIWORD(lParam);
LABEL_41:
              v20 = ((int (__thiscall *)(CWnd *, CWnd *, unsigned int))pfn)(a1: this, a2: v19, a3: v42);
              goto LABEL_111;
            case 0x34u:
              v49 = lParam;
              v37 = (CWnd *)HIWORD(wParam);
LABEL_85:
              v41 = v37;
              v34 = (CWnd *)(unsigned __int16)wParam;
LABEL_72:
              ((void (__thiscall *)(CWnd *, CWnd *, CWnd *, unsigned int))pfn)(a1: this, a2: v34, a3: v41, a4: v49);
              goto LReturnTrue;
            case 0x35u:
              v33 = (__int16)lParam;
              v48 = SHIWORD(lParam);
LABEL_70:
              ((void (__thiscall *)(CWnd *, WPARAM, int, unsigned int))pfn)(a1: this, a2: wParam, a3: v33, a4: v48);
              goto LReturnTrue;
            case 0x37u:
              v6 = ((int (__thiscall *)(CWnd *, _DWORD, WPARAM, _DWORD, _DWORD))pfn)(
                     a1: this,
                     a2: (unsigned __int16)wParam,
                     a3: HIWORD(wParam),
                     a4: (__int16)lParam,
                     a5: SHIWORD(lParam));
              lResult[0] = v6;
              goto LABEL_7;
            case 0x38u:
              ((void (__thiscall *)(CWnd *, _DWORD, WPARAM, _DWORD, _DWORD))pfn)(
                a1: this,
                a2: (unsigned __int16)wParam,
                a3: HIWORD(wParam),
                a4: (__int16)lParam,
                a5: SHIWORD(lParam));
              goto LReturnTrue;
            case 0x45u:
              lResult[0] = ((int (__thiscall *)(CWnd *))pfn)(a1: this);
              if ( lResult[0] != 0 )
                goto LABEL_39;
              goto LReturnTrue;
            case 0x48u:
              v21 = (CWnd *)CMenu::FromHandle(hMenu: (HMENU__ *)lParam);
LABEL_47:
              v44 = (unsigned int)v21;
LABEL_106:
              ((void (__thiscall *)(CWnd *, WPARAM, unsigned int))pfn)(a1: this, a2: wParam, a3: v44);
              goto LReturnTrue;
            case 0x49u:
              v51 = CMenu::FromHandle(hMenu: (HMENU__ *)lParam);
              goto LABEL_110;
            case 0x4Bu:
              v47 = lParam;
              v32 = (CWnd *)CMenu::FromHandle(hMenu: (HMENU__ *)wParam);
              goto LABEL_67;
            case 0x4Du:
              v40 = CWnd::FromHandle(hWnd: (HWND__ *)wParam);
              ((void (__thiscall *)(CWnd *, CWnd *, unsigned int, int, _DWORD))pfn)(
                a1: this,
                a2: v40,
                a3: HIWORD(lParam) & 0xFFF,
                a4: HIWORD(lParam) & 0xF000,
                a5: (unsigned __int16)lParam);
              goto LABEL_3;
            case 0x4Eu:
              v32 = (CWnd *)(unsigned __int8)wParam;
              v47 = lParam;
LABEL_67:
              ((void (__thiscall *)(CWnd *, CWnd *, unsigned int))pfn)(a1: this, a2: v32, a3: v47);
              break;
            case 0x50u:
              ((void (__thiscall *)(CWnd *, _DWORD, WPARAM, _DWORD, _DWORD))pfn)(
                a1: this,
                a2: (unsigned __int16)wParam,
                a3: HIWORD(wParam),
                a4: (__int16)lParam,
                a5: SHIWORD(lParam));
              goto LABEL_3;
            case 0x51u:
              ((void (__thiscall *)(CWnd *, WPARAM, WPARAM, _DWORD, _DWORD))pfn)(
                a1: this,
                a2: wParam,
                a3: HIWORD(wParam),
                a4: (__int16)lParam,
                a5: SHIWORD(lParam));
              goto LABEL_3;
            default:
              goto LReturnTrue;
          }
          goto LReturnTrue;
        }
      }
      else
      {
        v12 = pMsgCache;
        v13 = (int)lpEntry;
        pMsgCache->nMsg = message;
        v12->pMessageMap = lpEntry;
        while ( 1 )
        {
          if ( *(_DWORD *)v13 == 0 )
          {
            pMsgCache->lpEntry = nullptr;
            CInternalGlobalLock::Unlock(this: &winMsgLock);
            goto LABEL_39;
          }
          if ( message >= 0xC000 )
            break;
          MessageEntry = AfxFindMessageEntry(
                           lpEntry: *(const AFX_MSGMAP_ENTRY **)(v13 + 4),
                           nMsg: message,
                           nCode: 0,
                           nID: 0);
          lpEntrya = MessageEntry;
          if ( MessageEntry != nullptr )
          {
            pMsgCache->lpEntry = MessageEntry;
            CInternalGlobalLock::Unlock(this: &winMsgLock);
            goto LDispatch;
          }
LABEL_36:
          v13 = (*(int (**)(void))v13)();
          lpEntry = (const AFX_MSGMAP *)v13;
        }
        for ( i = AfxFindMessageEntry(lpEntry: lpEntry->lpEntries, nMsg: 0xC000u, nCode: 0, nID: 0);
              ;
              i = AfxFindMessageEntry(lpEntry: i + 1, nMsg: 0xC000u, nCode: 0, nID: 0) )
        {
          v11 = i;
          if ( i == nullptr )
          {
            v13 = (int)lpEntry;
            goto LABEL_36;
          }
          if ( *(_DWORD *)i->nSig == message )
            break;
        }
        pMsgCache->lpEntry = i;
        CInternalGlobalLock::Unlock(this: &winMsgLock);
      }
      pfn = v11->pfn;
$LN58_9:
      v51 = (CMenu *)lParam;
LABEL_110:
      v20 = ((int (__thiscall *)(CWnd *, WPARAM, CMenu *))pfn)(a1: this, a2: wParam, a3: v51);
LABEL_111:
      lResult[0] = v20;
      goto LReturnTrue;
    }
    if ( *(_DWORD *)lParam != 0 )
    {
      v6 = this->OnNotify(this, a2: wParam, a3: lParam, a4: lResult);
LABEL_7:
      if ( v6 != 0 )
        goto LReturnTrue;
    }
LABEL_39:
    v57 = -1;
    CInternalGlobalLock::Unlock(this: &winMsgLock);
    return 0;
  }
  if ( this->OnCommand(this, a2: wParam, a3: lParam) == 0 )
    goto LABEL_39;
LABEL_3:
  lResult[0] = 1;
LReturnTrue:
  if ( pResult != nullptr )
    *pResult = lResult[0];
  v57 = -1;
  CInternalGlobalLock::Unlock(this: &winMsgLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033E8DB
// Name: public: int CWnd::IsTopParentActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::IsTopParentActive(CWnd *this)
{
  CWnd *TopLevelParent; // esi
  HWND ForegroundWindow; // eax
  CWnd *v3; // edi
  HWND LastActivePopup; // eax

  TopLevelParent = CWnd::GetTopLevelParent(this);
  if ( TopLevelParent == nullptr )
    AfxThrowInvalidArgException();
  ForegroundWindow = GetForegroundWindow();
  v3 = CWnd::FromHandle(hWnd: ForegroundWindow);
  LastActivePopup = GetLastActivePopup(hWnd: TopLevelParent->m_hWnd);
  return v3 == CWnd::FromHandle(hWnd: LastActivePopup);
}

//------------------------------------------------------------------------------
// Address: 0x1033E918
// Name: public: void CWnd::ActivateTopParent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::ActivateTopParent(CWnd *this)
{
  HWND ForegroundWindow; // eax
  CWnd *v3; // eax
  HWND m_hWnd; // eax
  CWnd *TopLevelParent; // eax

  ForegroundWindow = GetForegroundWindow();
  v3 = CWnd::FromHandle(hWnd: ForegroundWindow);
  if ( v3 == nullptr || (m_hWnd = v3->m_hWnd) != this->m_hWnd && !IsChild(hWndParent: m_hWnd, hWnd: this->m_hWnd) )
  {
    TopLevelParent = CWnd::GetTopLevelParent(this);
    if ( TopLevelParent == nullptr )
      AfxThrowInvalidArgException();
    SetForegroundWindow(hWnd: TopLevelParent->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033E95E
// Name: protected: int CWnd::ReflectChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::ReflectChildNotify(
        CWnd *this,
        unsigned int uMsg,
        unsigned int wParam,
        tagNMHDR *lParam,
        int *pResult)
{
  unsigned int code; // edx
  int result; // eax
  int v7; // [esp+4h] [ebp-Ch] BYREF
  AFX_NOTIFY notify; // [esp+8h] [ebp-8h] BYREF

  if ( uMsg > 0x111 )
  {
    if ( uMsg < 0x114 || uMsg > 0x115 && uMsg != 528 )
      goto LABEL_15;
    return CWnd::OnWndMsg(this, message: uMsg + 48128, wParam, (unsigned int)lParam, pResult);
  }
  if ( uMsg != 273 )
  {
    if ( uMsg < 0x2B )
      goto LABEL_15;
    if ( uMsg > 0x2F && uMsg != 57 )
    {
      if ( uMsg == 78 )
      {
        code = lParam->code;
        notify.pResult = pResult;
        notify.pNMHDR = lParam;
        return CCmdTarget::OnCmdMsg(
                 this,
                 nID: 0,
                 nCode: (unsigned __int16)code | 0xBC4E0000,
                 pExtra: (const _GUID *)&notify,
                 pHandlerInfo: nullptr);
      }
LABEL_15:
      if ( uMsg - 306 > 6 )
        return 0;
      notify.pNMHDR = (tagNMHDR *)(uMsg - 306);
      notify.pResult = (int *)wParam;
      result = CWnd::OnWndMsg(this, message: 0xBC19u, wParam: 0, lParam: (unsigned int)&v7, pResult);
      if ( *pResult == 0 )
        return 0;
      return result;
    }
    return CWnd::OnWndMsg(this, message: uMsg + 48128, wParam, (unsigned int)lParam, pResult);
  }
  if ( CCmdTarget::OnCmdMsg(this, nID: 0, nCode: HIWORD(wParam) | 0xBD110000, pExtra: nullptr, pHandlerInfo: nullptr) == 0 )
    return 0;
  result = 1;
  if ( pResult != nullptr )
    *pResult = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033EA45
// Name: protected: void CWnd::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnSettingChange(CWnd *this, unsigned int uFlags, const char *lpszSection)
{
  _afxGotScrollLines = 0;
  if ( this->m_pCtrlCont != nullptr )
    this->m_pCtrlCont->BroadcastAmbientPropertyChange(this: this->m_pCtrlCont, a2: -705);
  CWnd::OnDisplayChange(this, __formal: 0, __formala: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1033EAE3
// Name: public: virtual void CWnd::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::WinHelpA(CWnd *this, ULONG_PTR dwData, UINT nCmd)
{
  CWinApp *m_pCurrentWinApp; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  CWnd *TopLevelParent; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  ModuleState = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
  CWnd::PrepareForHelp(this);
  TopLevelParent = CWnd::GetTopLevelParent(this);
  if ( TopLevelParent == nullptr )
    AfxThrowInvalidArgException();
  if ( !WinHelpA(
          hWndMain: TopLevelParent->m_hWnd,
          lpszHelp: m_pCurrentWinApp->m_pszHelpFilePath,
          uCommand: nCmd,
          dwData) )
    AfxMessageBox(nIDPrompt: 0xF107u, nType: 0, nIDHelp: 0xFFFFFFFF);
  CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&dwData + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1033EB58
// Name: public: virtual void CWnd::HtmlHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::HtmlHelpA(CWnd *this, unsigned int dwData, unsigned int nCmd)
{
  CWinApp *m_pCurrentWinApp; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  CWnd *TopLevelParent; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  ModuleState = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
  CWnd::PrepareForHelp(this);
  TopLevelParent = CWnd::GetTopLevelParent(this);
  if ( TopLevelParent == nullptr )
    AfxThrowInvalidArgException();
  if ( AfxHtmlHelp(hWnd: TopLevelParent->m_hWnd, szHelpFilePath: m_pCurrentWinApp->m_pszHelpFilePath, nCmd, dwData) == nullptr )
    AfxMessageBox(nIDPrompt: 0xF107u, nType: 0, nIDHelp: 0xFFFFFFFF);
  CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&dwData + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1033EBCC
// Name: protected: virtual int CWnd::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CWnd::OnChildNotify(
        CWnd *this,
        unsigned int uMsg,
        unsigned int wParam,
        tagNMHDR *lParam,
        int *pResult)
{
  LRESULT result; // eax

  if ( this->m_pCtrlSite == nullptr )
    return CWnd::ReflectChildNotify(this, uMsg, wParam, lParam, pResult);
  result = SendMessageA(hWnd: this->m_hWnd, Msg: uMsg + 0x2000, wParam, (LPARAM)lParam);
  if ( uMsg - 306 > 6 || result != 0 )
  {
    if ( pResult != nullptr )
      *pResult = result;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033EC19
// Name: public: virtual long CWnd::CreateAccessibleProxy(unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWnd::CreateAccessibleProxy(CWnd *this, WPARAM wParam, IAccessibleProxy *lParam, int *pResult)
{
  int v5; // edi
  CMFCComObject<ATL::CAccessibleProxy>_vtbl *v6; // ecx
  IAccessibleProxy *v7; // eax
  LONG_PTR v8; // eax
  LONG_PTR v9; // eax
  CMFCComObject<ATL::CAccessibleProxy> *p; // [esp+10h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v5 = -2147467259;
  if ( lParam == (IAccessibleProxy *)-4 )
  {
    v5 = this->EnsureStdObj(this);
    if ( v5 >= 0 )
    {
      if ( this->m_pProxy != nullptr )
      {
        v9 = LresultFromObject(riid: &_GUID_618736e0_3c3d_11cf_810c_00aa00389b71, wParam, punk: this->m_pProxy);
        *pResult = v9;
        return 0;
      }
      else
      {
        v5 = CMFCComObject<ATL::CAccessibleProxy>::CreateInstance(pp: &p);
        if ( v5 >= 0 )
        {
          lParam = nullptr;
          v6 = p->ATL::CAccessibleProxy::ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::IAccessible::IDispatch::IUnknown::__vftable;
          v12 = 0;
          if ( v6->QueryInterface(this: p, a2: &_GUID_7a7d9dcf_b7a1_4019_9031_258268846980, a3: (void **)&lParam) >= 0 )
          {
            v7 = lParam;
            this->m_pProxy = lParam;
            v7->SetServer(
              this: v7,
              a2: (IAccessible *)&this->m_xAccessible,
              a3: (IAccessibleServer *)&this->m_xAccessibleServer);
            v8 = LresultFromObject(riid: &_GUID_618736e0_3c3d_11cf_810c_00aa00389b71, wParam, punk: this->m_pProxy);
            *pResult = v8;
          }
          v12 = -1;
          v5 = 0;
          if ( lParam != nullptr )
            lParam->Release(this: lParam);
        }
      }
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033ECD8
// Name: public: int CWnd::GetDlgItemTextA(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::GetDlgItemTextA(
        CWnd *this,
        int nID,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString)
{
  HWND v4; // eax
  HWND v5; // esi
  int WindowTextLengthA; // eax
  CHAR *BufferSetLength; // eax
  CWnd *DlgItem; // eax
  int v10; // [esp-4h] [ebp-Ch]

  ATL::CSimpleStringT<char,0>::SetString(this: rString, pszSrc: &var);
  if ( this->m_pCtrlCont != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID);
    if ( DlgItem != nullptr )
      CWnd::GetWindowTextA(this: DlgItem, rString);
  }
  else
  {
    v4 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: nID);
    v5 = v4;
    if ( v4 != nullptr )
    {
      WindowTextLengthA = GetWindowTextLengthA(hWnd: v4);
      v10 = WindowTextLengthA + 1;
      BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: WindowTextLengthA);
      GetWindowTextA(hWnd: v5, lpString: BufferSetLength, nMaxCount: v10);
      ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
    }
  }
  return *((_DWORD *)rString->m_pszData - 3);
}

//------------------------------------------------------------------------------
// Address: 0x1033ED4C
// Name: protected: static struct AFX_MSGMAP const __near * CWnd::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CWnd::GetThisMessageMap(CWnd *this)
{
  return &messageMap_12;
}

//------------------------------------------------------------------------------
// Address: 0x1033EEE3
// Name: public: int CWnd::ExecuteDlgInit(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::ExecuteDlgInit(CWnd *this, unsigned int lpResource)
{
  CMFCControlContainer *v3; // eax
  CMFCControlContainer *v4; // eax
  char *v5; // esi
  CMFCControlContainer *v6; // edi
  unsigned __int16 v7; // ax
  char *v8; // esi
  CMFCControlContainer *m_pMFCCtrlContainer; // ecx
  tagCOMBOBOXEXITEMA item; // [esp+10h] [ebp-3Ch] BYREF
  CMFCControlContainer *nIDC; // [esp+34h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+38h] [ebp-14h] BYREF
  int bSuccess; // [esp+3Ch] [ebp-10h]
  int v15; // [esp+48h] [ebp-4h]
  WPARAM dwLen; // [esp+54h] [ebp+8h]

  if ( this->m_pMFCCtrlContainer == nullptr )
  {
    v3 = (CMFCControlContainer *)operator new(nSize: 0x38u);
    nIDC = v3;
    v15 = 0;
    if ( v3 != nullptr )
      v4 = CMFCControlContainer::CMFCControlContainer(this: v3, pWnd: this);
    else
      v4 = nullptr;
    v15 = -1;
    this->m_pMFCCtrlContainer = v4;
    CMFCControlContainer::SubclassDlgControls(this: v4);
  }
  v5 = (char *)lpResource;
  bSuccess = 1;
  if ( lpResource == 0 )
  {
LABEL_28:
    CWnd::SendMessageToDescendants(
      hWnd: this->m_hWnd,
      message: (CNoTrackObject_vtbl *)0x364,
      wParam: nullptr,
      lParam: nullptr,
      bDeep: 0,
      bOnlyPerm: 0);
    return bSuccess;
  }
  while ( *(_WORD *)v5 != 0 )
  {
    v6 = (CMFCControlContainer *)*(unsigned __int16 *)v5;
    v7 = *((_WORD *)v5 + 1);
    dwLen = *((_DWORD *)v5 + 1);
    v8 = v5 + 8;
    nIDC = v6;
    switch ( v7 )
    {
      case 0x1234u:
        memset(&item.iItem, 0, 0x20u);
        item.iItem = -1;
        item.mask = 1;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strText,
          pszSrc: v8);
        item.pszText = strText.m_pszData;
        if ( SendDlgItemMessageA(
               hDlg: this->m_hWnd,
               nIDDlgItem: (unsigned __int16)nIDC,
               Msg: 0x401u,
               wParam: 0,
               lParam: (LPARAM)&item) == -1 )
          bSuccess = 0;
        ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
        goto LABEL_26;
      case 0x401u:
        v7 = 384;
LABEL_24:
        if ( SendDlgItemMessageA(
               hDlg: this->m_hWnd,
               nIDDlgItem: (unsigned __int16)v6,
               Msg: v7,
               wParam: 0,
               lParam: (LPARAM)v8) == -1 )
          bSuccess = 0;
        goto LABEL_26;
      case 0x403u:
        v7 = 323;
        break;
      default:
        break;
    }
    if ( v7 == 892 )
    {
      if ( SendDlgItemMessageA(
             hDlg: this->m_hWnd,
             nIDDlgItem: (unsigned __int16)v6,
             Msg: 0x37Cu,
             wParam: dwLen,
             lParam: (LPARAM)v8) == -1 )
        bSuccess = 0;
      m_pMFCCtrlContainer = this->m_pMFCCtrlContainer;
      if ( m_pMFCCtrlContainer != nullptr )
        CMFCControlContainer::SetControlData(
          this: m_pMFCCtrlContainer,
          nIDC: (unsigned __int16)v6,
          dwSize: dwLen,
          pbData: (unsigned __int8 *)v8);
      goto LABEL_26;
    }
    if ( v7 == 384 || v7 == 323 )
      goto LABEL_24;
LABEL_26:
    v5 = &v8[dwLen];
    if ( bSuccess == 0 )
      break;
  }
  if ( bSuccess != 0 )
    goto LABEL_28;
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x1033F3A3
// Name: public: virtual int CWnd::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::PreCreateWindow(CWnd *this, tagCREATESTRUCTA *cs)
{
  if ( cs->lpszClass == nullptr )
  {
    AfxEndDeferRegisterClass(fToRegister: 1);
    cs->lpszClass = "AfxWnd100s";
  }
  if ( cs->hMenu == nullptr && (cs->style & 0x40000000) != 0 )
    cs->hMenu = (HMENU__ *)this;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033F3DE
// Name: public: int CWnd::ExecuteDlgInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HGLOBAL __thiscall CWnd::ExecuteDlgInit(CWnd *this, const char *lpszResourceName)
{
  HGLOBAL v2; // ebx
  LPVOID v3; // edi
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HGLOBAL result; // eax
  int v7; // esi

  v2 = nullptr;
  v3 = nullptr;
  if ( lpszResourceName != nullptr )
  {
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
    ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszResourceName, lpType: (LPCSTR)0xF0);
    if ( ResourceA != nullptr )
    {
      result = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
      v2 = result;
      if ( result == nullptr )
        return result;
      v3 = LockResource(hResData: result);
    }
  }
  v7 = CWnd::ExecuteDlgInit(this, lpResource: (unsigned int)v3);
  if ( v3 != nullptr && v2 != nullptr )
    FreeResource(hResData: v2);
  return (HGLOBAL)v7;
}

//------------------------------------------------------------------------------
// Address: 0x1033F448
// Name: public: virtual int CWnd::OnAmbientProperty(class COleControlSite __near *,long,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::OnAmbientProperty(CWnd *this, COleControlSite *pSite, int dispid, tagVARIANT *pvar)
{
  return this->m_pCtrlCont->GetAmbientProp(this: this->m_pCtrlCont, a2: pSite, a3: dispid, a4: pvar);
}

//------------------------------------------------------------------------------
// Address: 0x1033F456
// Name: public: struct IUnknown __near * CWnd::GetControlUnknown(void)
// Source: json
//------------------------------------------------------------------------------
IUnknown_vtbl *__thiscall CWnd::GetControlUnknown(CWnd *this)
{
  IUnknown_vtbl *result; // eax

  result = (IUnknown_vtbl *)this->m_pCtrlSite;
  if ( result != nullptr )
    return (IUnknown_vtbl *)result[6].Release;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033F462
// Name: public: int CWnd::PaintWindowlessControls(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::PaintWindowlessControls(CWnd *this, CDC *pDC)
{
  if ( this->m_pCtrlCont != nullptr )
    return this->m_pCtrlCont->OnPaint(this: this->m_pCtrlCont, a2: pDC);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033F47F
// Name: public: class COleControlSite __near * CWnd::GetOleControlSite(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
COleControlSite *__thiscall CWnd::GetOleControlSite(CWnd *this, unsigned int idControl)
{
  if ( this->m_pCtrlCont != nullptr )
    return this->m_pCtrlCont->FindItem(this: this->m_pCtrlCont, a2: idControl);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1033F499
// Name: public: void CWnd::CheckDlgButton(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::CheckDlgButton(CWnd *this, int nIDButton, unsigned int nCheck)
{
  if ( this->m_pCtrlCont != nullptr )
    this->m_pCtrlCont->CheckDlgButton(this: this->m_pCtrlCont, a2: nIDButton, a3: nCheck);
  else
    CheckDlgButton(hDlg: this->m_hWnd, nIDButton, uCheck: nCheck);
}

//------------------------------------------------------------------------------
// Address: 0x1033F4C0
// Name: public: class CWnd __near * CWnd::GetDlgItem(int)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetDlgItem(CWnd *this, int nID)
{
  HWND DlgItem; // eax

  if ( this->m_pCtrlCont != nullptr )
    return this->m_pCtrlCont->GetDlgItem(this: this->m_pCtrlCont, a2: nID);
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: nID);
  return CWnd::FromHandle(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x1033F4EA
// Name: public: void CWnd::GetDlgItem(int,struct HWND__ __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::GetDlgItem(CWnd *this, int nID, HWND__ **phWnd)
{
  if ( this->m_pCtrlCont != nullptr )
    this->m_pCtrlCont->GetDlgItem(this: this->m_pCtrlCont, a2: nID, a3: phWnd);
  else
    *phWnd = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: nID);
}

//------------------------------------------------------------------------------
// Address: 0x1033F513
// Name: public: unsigned int CWnd::GetDlgItemInt(int,int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
UINT __thiscall CWnd::GetDlgItemInt(CWnd *this, int nID, int *lpTrans, int bSigned)
{
  if ( this->m_pCtrlCont != nullptr )
    return this->m_pCtrlCont->GetDlgItemInt(this: this->m_pCtrlCont, a2: nID, a3: lpTrans, a4: bSigned);
  else
    return GetDlgItemInt(hDlg: this->m_hWnd, nIDDlgItem: nID, lpTranslated: lpTrans, bSigned);
}

//------------------------------------------------------------------------------
// Address: 0x1033F53D
// Name: public: void CWnd::SetDlgItemInt(int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::SetDlgItemInt(CWnd *this, int nID, unsigned int nValue, int bSigned)
{
  if ( this->m_pCtrlCont != nullptr )
    this->m_pCtrlCont->SetDlgItemInt(this: this->m_pCtrlCont, a2: nID, a3: nValue, a4: bSigned);
  else
    SetDlgItemInt(hDlg: this->m_hWnd, nIDDlgItem: nID, uValue: nValue, bSigned);
}

//------------------------------------------------------------------------------
// Address: 0x1033F56A
// Name: public: void CWnd::SetDlgItemTextA(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::SetDlgItemTextA(CWnd *this, int nID, const char *lpszString)
{
  if ( this->m_pCtrlCont != nullptr )
    this->m_pCtrlCont->SetDlgItemTextA(this: this->m_pCtrlCont, a2: nID, a3: lpszString);
  else
    SetDlgItemTextA(hDlg: this->m_hWnd, nIDDlgItem: nID, lpString: lpszString);
}

//------------------------------------------------------------------------------
// Address: 0x1033F594
// Name: public: int CWnd::IsDialogMessageA(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::IsDialogMessageA(CWnd *this, tagMSG *lpMsg)
{
  AFX_MODULE_STATE *ModuleState; // eax

  if ( (this->m_nFlags & 0x100) == 0 )
    return IsDialogMessageA(hDlg: this->m_hWnd, lpMsg);
  ModuleState = AfxGetModuleState();
  return ModuleState->m_pOccManager->IsDialogMessageA(this: ModuleState->m_pOccManager, a2: this, a3: lpMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1033F5CB
// Name: public: unsigned long CWnd::GetStyle(void)const
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall CWnd::GetStyle(CWnd *this)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->GetStyle(this: this->m_pCtrlSite);
  else
    return GetWindowLongA(hWnd: this->m_hWnd, nIndex: -16);
}

//------------------------------------------------------------------------------
// Address: 0x1033F5E5
// Name: public: unsigned long CWnd::GetExStyle(void)const
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall CWnd::GetExStyle(CWnd *this)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->GetExStyle(this: this->m_pCtrlSite);
  else
    return GetWindowLongA(hWnd: this->m_hWnd, nIndex: -20);
}

//------------------------------------------------------------------------------
// Address: 0x1033F5FF
// Name: public: int CWnd::ModifyStyle(unsigned long,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::ModifyStyle(CWnd *this, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->ModifyStyle(this: this->m_pCtrlSite, a2: dwRemove, a3: dwAdd, a4: nFlags);
  else
    return CWnd::ModifyStyle(hWnd: this->m_hWnd, dwRemove, dwAdd, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1033F62B
// Name: public: int CWnd::ModifyStyleEx(unsigned long,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::ModifyStyleEx(CWnd *this, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->ModifyStyleEx(this: this->m_pCtrlSite, a2: dwRemove, a3: dwAdd, a4: nFlags);
  else
    return CWnd::ModifyStyleEx(hWnd: this->m_hWnd, dwRemove, dwAdd, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1033F657
// Name: public: void CWnd::SetWindowTextA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::SetWindowTextA(CWnd *this, const char *lpszString)
{
  if ( this == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  if ( !IsWindow(hWnd: this->m_hWnd) )
  {
    if ( this->m_pCtrlSite == nullptr )
      goto LABEL_2;
    goto LABEL_5;
  }
  if ( this->m_pCtrlSite != nullptr )
  {
LABEL_5:
    this->m_pCtrlSite->SetWindowTextA(this: this->m_pCtrlSite, a2: lpszString);
    return;
  }
  SetWindowTextA(hWnd: this->m_hWnd, lpString: lpszString);
}

//------------------------------------------------------------------------------
// Address: 0x1033F69E
// Name: public: int CWnd::GetDlgCtrlID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::GetDlgCtrlID(CWnd *this)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->GetDlgCtrlID(this: this->m_pCtrlSite);
  else
    return GetDlgCtrlID(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1033F6B9
// Name: public: int CWnd::SetDlgCtrlID(int)
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall CWnd::SetDlgCtrlID(CWnd *this, int nID)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->SetDlgCtrlID(this: this->m_pCtrlSite, a2: nID);
  else
    return SetWindowLongA(hWnd: this->m_hWnd, nIndex: -12, dwNewLong: nID);
}

//------------------------------------------------------------------------------
// Address: 0x1033F722
// Name: public: int CWnd::ShowWindow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::ShowWindow(CWnd *this, int nCmdShow)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->ShowWindow(this: this->m_pCtrlSite, a2: nCmdShow);
  else
    return ShowWindow(hWnd: this->m_hWnd, nCmdShow);
}

//------------------------------------------------------------------------------
// Address: 0x1033F749
// Name: public: int CWnd::IsWindowEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::IsWindowEnabled(CWnd *this)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->IsWindowEnabled(this: this->m_pCtrlSite);
  else
    return IsWindowEnabled(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1033F764
// Name: public: int CWnd::EnableWindow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::EnableWindow(CWnd *this, int bEnable)
{
  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->EnableWindow(this: this->m_pCtrlSite, a2: bEnable);
  else
    return EnableWindow(hWnd: this->m_hWnd, bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1033F78B
// Name: public: void CWnd::AttachControlSite(class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::AttachControlSite(CWnd *this, CWnd *pWndParent, unsigned int nIDC)
{
  if ( this->m_pCtrlSite == nullptr && pWndParent->m_pCtrlCont != nullptr )
    pWndParent->m_pCtrlCont->AttachControlSite(this: pWndParent->m_pCtrlCont, a2: this, a3: nIDC);
}

//------------------------------------------------------------------------------
// Address: 0x1033F7D2
// Name: public: int CWnd::SetWindowPos(class CWnd const __near *,int,int,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::SetWindowPos(CWnd *this, CWnd *pWndInsertAfter, int x, int y, int cx, int cy, unsigned int nFlags)
{
  HWND__ *m_hWnd; // eax

  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->SetWindowPos(
             this: this->m_pCtrlSite,
             a2: pWndInsertAfter,
             a3: x,
             a4: y,
             a5: cx,
             a6: cy,
             a7: nFlags);
  m_hWnd = (HWND__ *)pWndInsertAfter;
  if ( pWndInsertAfter != nullptr )
    m_hWnd = pWndInsertAfter->m_hWnd;
  return SetWindowPos(hWnd: this->m_hWnd, hWndInsertAfter: m_hWnd, X: x, Y: y, cx, cy, uFlags: nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1033F810
// Name: public: class CWnd __near * CWnd::SetFocus(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::SetFocus(CWnd *this)
{
  HWND Parent; // eax
  HWND v3; // eax
  CWnd *v4; // eax
  HWND v5; // eax
  CWnd *v6; // eax
  HWND v7; // eax

  if ( this->m_pCtrlSite != nullptr )
    return this->m_pCtrlSite->SetFocus(this: this->m_pCtrlSite);
  Parent = GetParent(hWnd: this->m_hWnd);
  if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
  {
    v3 = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: v3);
    if ( CWnd::GetControlContainer(this: v4) != nullptr )
    {
      v5 = GetParent(hWnd: this->m_hWnd);
      v6 = CWnd::FromHandle(hWnd: v5);
      CWnd::GetControlContainer(this: v6)->m_pSiteFocus = nullptr;
    }
  }
  v7 = SetFocus(hWnd: this->m_hWnd);
  return CWnd::FromHandle(hWnd: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1033F87B
// Name: protected: void CWnd::AttachControlSite(class CHandleMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::AttachControlSite(CWnd *this, CHandleMap *pMap)
{
  CDocument *Parent; // eax
  _DWORD **ValueAt; // eax

  if ( this != nullptr && this->m_pCtrlSite == nullptr )
  {
    Parent = (CDocument *)GetParent(hWnd: this->m_hWnd);
    ValueAt = (_DWORD **)CMapPtrToPtr::GetValueAt(this: &pMap->m_permanentMap, key: Parent);
    if ( ValueAt != nullptr && ValueAt[26] != nullptr )
      (*(void (__thiscall **)(_DWORD *, CWnd *, _DWORD))(*ValueAt[26] + 156))(a1: ValueAt[26], a2: this, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033F8BF
// Name: public: int CWnd::GetWindowTextA(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::GetWindowTextA(CWnd *this, char *lpszString, int nMaxCount)
{
  CAfxStringMgr *StringManager; // eax
  COleControlSite *m_pCtrlSite; // ecx
  COleControlSite_vtbl *v7; // eax
  int v8; // eax
  int v9; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  if ( this->m_pCtrlSite == nullptr )
    return GetWindowTextA(hWnd: this->m_hWnd, lpString: lpszString, nMaxCount);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
  m_pCtrlSite = this->m_pCtrlSite;
  v7 = m_pCtrlSite->__vftable;
  v11 = 0;
  v7->GetWindowTextA(this: m_pCtrlSite, a2: &str);
  v8 = _mbsnbcpy_s(
         _Arg1: (unsigned __int8 *)lpszString,
         _Arg2: nMaxCount,
         _Arg3: (const unsigned __int8 *)str.m_pszData,
         _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v8);
  v9 = lstrlenA(lpString: lpszString);
  ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10340002
// Name: protected: int CWnd::OnEraseBkgnd(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CWnd::OnEraseBkgnd(CToolBar *this, CDC *__formal)
{
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10343E47
// Name: public: void CWnd::ScreenToClient(struct tagRECT __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::ScreenToClient(CWnd *this, tagPOINT *lpRect)
{
  int *p_x; // edi
  int x; // eax

  ScreenToClient(hWnd: this->m_hWnd, lpPoint: lpRect);
  p_x = &lpRect[1].x;
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: lpRect + 1);
  if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
  {
    x = lpRect->x;
    lpRect->x = *p_x;
    *p_x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10343E88
// Name: public: void CWnd::ClientToScreen(struct tagRECT __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::ClientToScreen(CWnd *this, tagPOINT *lpRect)
{
  int *p_x; // edi
  int x; // eax

  ClientToScreen(hWnd: this->m_hWnd, lpPoint: lpRect);
  p_x = &lpRect[1].x;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: lpRect + 1);
  if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
  {
    x = lpRect->x;
    lpRect->x = *p_x;
    *p_x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348B5B
// Name: public: class CWnd __near * CWnd::GetNextDlgTabItem(class CWnd __near *,int)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetNextDlgTabItem(CWnd *this, CWnd *pWndCtl, BOOL bPrevious)
{
  HWND__ *m_hWnd; // eax
  HWND NextDlgTabItem; // eax

  m_hWnd = (HWND__ *)pWndCtl;
  if ( pWndCtl != nullptr )
    m_hWnd = pWndCtl->m_hWnd;
  NextDlgTabItem = GetNextDlgTabItem(hDlg: this->m_hWnd, hCtl: m_hWnd, bPrevious);
  return CWnd::FromHandle(hWnd: NextDlgTabItem);
}

//------------------------------------------------------------------------------
// Address: 0x10349063
// Name: protected: int CWnd::CreateDlgIndirect(struct DLGTEMPLATE const __near *,class CWnd __near *,struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::CreateDlgIndirect(
        CWnd *this,
        const DLGTEMPLATE *lpDialogTemplate,
        CWnd *pParentWnd,
        HINSTANCE hInst)
{
  COccManager *m_pOccManager; // edi
  const DLGTEMPLATE *v7; // edi
  CAfxStringMgr *StringManager; // eax
  HWND__ *m_hWnd; // eax
  HWND DialogIndirectParamA; // edi
  _AFX_OCC_DIALOG_INFO occDialogInfo; // [esp+10h] [ebp-48h] BYREF
  CDialogTemplate dlgTemp; // [esp+20h] [ebp-38h] BYREF
  COccManager *pOccManager; // [esp+30h] [ebp-28h]
  CWnd *v14; // [esp+38h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFace; // [esp+3Ch] [ebp-1Ch] BYREF
  int wSize; // [esp+40h] [ebp-18h] BYREF
  void *hTemplate; // [esp+44h] [ebp-14h]
  int v18; // [esp+54h] [ebp-4h]

  v14 = this;
  if ( hInst == nullptr )
    hInst = AfxGetModuleState()->m_hCurrentResourceHandle;
  m_pOccManager = AfxGetModuleState()->m_pOccManager;
  pOccManager = m_pOccManager;
  hTemplate = nullptr;
  v18 = 0;
  AfxEndDeferRegisterClass(fToRegister: 16);
  AfxEndDeferRegisterClass(fToRegister: 245760);
  AfxRegisterMFCCtrlClasses();
  if ( m_pOccManager != nullptr )
  {
    if ( this->SetOccDialogInfo(this, a2: &occDialogInfo) == 0 )
      return false;
    v7 = m_pOccManager->PreCreateDialog(this: m_pOccManager, a2: &occDialogInfo, a3: lpDialogTemplate);
  }
  else
  {
    v7 = lpDialogTemplate;
  }
  if ( v7 == nullptr )
    return false;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFace, pStringMgr: StringManager);
  LOBYTE(v18) = 1;
  wSize = 0;
  if ( CDialogTemplate::GetFont(pTemplate: v7, &strFace, nFontSize: (unsigned __int16 *)&wSize) == 0 )
  {
    CDialogTemplate::CDialogTemplate(this: &dlgTemp, pTemplate: v7);
    LOBYTE(v18) = 2;
    CDialogTemplate::SetSystemFont(this: &dlgTemp, wSize);
    hTemplate = CDialogTemplate::Detach(this: &dlgTemp);
    LOBYTE(v18) = 1;
    CDialogTemplate::~CDialogTemplate(this: &dlgTemp);
    if ( hTemplate != nullptr )
      v7 = (const DLGTEMPLATE *)GlobalLock(hMem: hTemplate);
  }
  this->m_nModalResult = -1;
  this->m_nFlags |= 0x10u;
  AfxHookWindowCreate(pWnd: this);
  if ( pParentWnd != nullptr )
    m_hWnd = pParentWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  DialogIndirectParamA = CreateDialogIndirectParamA(
                           hInstance: hInst,
                           lpTemplate: v7,
                           hWndParent: m_hWnd,
                           lpDialogFunc: (DLGPROC)AfxDlgProc,
                           dwInitParam: 0);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFace.m_pszData - 1);
  v18 = -1;
  if ( pOccManager != nullptr && DialogIndirectParamA != nullptr )
  {
    ((void (__stdcall *)(_AFX_OCC_DIALOG_INFO *))pOccManager->PostCreateDialog)(a1: &occDialogInfo);
    this->SetOccDialogInfo(this, a2: nullptr);
  }
  if ( AfxUnhookWindowCreate() == 0 )
    this->PostNcDestroy(this);
  if ( DialogIndirectParamA != nullptr && (this->m_nFlags & 0x10) == 0 )
  {
    DestroyWindow(hWnd: DialogIndirectParamA);
    DialogIndirectParamA = nullptr;
  }
  if ( hTemplate != nullptr )
  {
    GlobalUnlock(hMem: hTemplate);
    GlobalFree(hMem: hTemplate);
  }
  return DialogIndirectParamA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10349421
// Name: protected: int CWnd::CreateDlg(char const __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWnd::CreateDlg(CWnd *this, const char *lpszTemplateName, CWnd *pParentWnd)
{
  const DLGTEMPLATE *v3; // ebx
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HGLOBAL Resource; // eax
  void *v7; // edi
  BOOL DlgIndirect; // esi

  v3 = nullptr;
  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszTemplateName, lpType: (LPCSTR)5);
  Resource = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  v7 = Resource;
  if ( Resource != nullptr )
    v3 = (const DLGTEMPLATE *)LockResource(hResData: Resource);
  DlgIndirect = CWnd::CreateDlgIndirect(this, lpDialogTemplate: v3, pParentWnd, hInst: m_hCurrentResourceHandle);
  FreeResource(hResData: v7);
  return DlgIndirect;
}

//------------------------------------------------------------------------------
// Address: 0x10349B8E
// Name: public: static struct HWND__ __near * CWnd::GetSafeOwner_(struct HWND__ __near *,struct HWND__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HWND __stdcall CWnd::GetSafeOwner_(HWND__ *hParent, HWND__ **pWndTop)
{
  HWND i; // esi
  CFrameWnd *RoutingFrame; // eax
  HWND v4; // edi
  HWND j; // eax

  i = hParent;
  if ( hParent != nullptr )
    goto LABEL_6;
  RoutingFrame = CCmdTarget::GetRoutingFrame_();
  if ( RoutingFrame != nullptr || (RoutingFrame = (CFrameWnd *)AfxGetMainWnd()) != nullptr )
  {
    for ( i = RoutingFrame->m_hWnd; i != nullptr; i = GetParent(hWnd: i) )
    {
LABEL_6:
      if ( (GetWindowLongA(hWnd: i, nIndex: -16) & 0x40000000) == 0 )
        break;
    }
  }
  else
  {
    i = nullptr;
  }
  v4 = i;
  for ( j = i; j != nullptr; j = GetParent(hWnd: j) )
    v4 = j;
  if ( hParent == nullptr && i != nullptr )
    i = GetLastActivePopup(hWnd: i);
  if ( pWndTop != nullptr )
  {
    if ( v4 != nullptr && IsWindowEnabled(hWnd: v4) && v4 != i )
    {
      *pWndTop = v4;
      EnableWindow(hWnd: v4, bEnable: false);
    }
    else
    {
      *pWndTop = nullptr;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1035060D
// Name: protected: void CPropertySheet::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::OnClose(CPropertySheet *this)
{
  bool v1; // zf

  v1 = this->m_bModeless == 0;
  this->m_nModalResult = 2;
  if ( v1 )
    CWnd::Default(this);
  else
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x471u, wParam: 5u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10350635
// Name: protected: int CPropertySheet::OnNcCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnNcCreate(CPropertySheet *this, tagCREATESTRUCTA *__formal)
{
  CWnd::ModifyStyleEx(this, dwRemove: 0x400u, dwAdd: 0, nFlags: 0);
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10350653
// Name: protected: long CPropertySheet::HandleInitDialog(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::HandleInitDialog(CPropertySheet *this, unsigned int __formal, unsigned int __formala)
{
  return this->OnInitDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035065E
// Name: public: virtual int CPropertySheet::OnCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnCommand(CPropertySheet *this, unsigned int wParam, HWND__ *lParam)
{
  unsigned int v4; // eax

  if ( CWnd::OnCommand(this, wParam, lParam) != 0 )
    return 1;
  if ( lParam != nullptr
    && HIWORD(wParam) == 0
    && (SendMessageA(hWnd: lParam, Msg: 0x87u, wParam: 0, lParam: 0) & 0x2010) != 0 )
  {
    v4 = GetWindowLongA(hWnd: lParam, nIndex: -16) & 0xF;
    if ( v4 < 2 || v4 == 8 || v4 == 11 )
      this->m_nModalResult = (unsigned __int16)wParam;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103506D2
// Name: protected: struct HBRUSH__ __near * CPropertySheet::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CPropertySheet::OnCtlColor(CPropertySheet *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  int lResult; // [esp+4h] [ebp-4h] BYREF

  if ( pWnd == nullptr )
    AfxThrowInvalidArgException();
  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: &lResult) != 0 )
    return (CWnd *)lResult;
  else
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
}

//------------------------------------------------------------------------------
// Address: 0x10350716
// Name: public: virtual struct CRuntimeClass __near * CPropertySheet::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPropertySheet::GetRuntimeClass(CPropertySheet *this)
{
  return &CPropertySheet::classCPropertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x10350989
// Name: protected: long CPropertySheet::OnSetDefID(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnSetDefID(CPropertySheet *this, int wParam, int lParam)
{
  HWND DlgItem; // eax
  HWND Focus; // eax
  HWND__ *hWnd; // [esp+Ch] [ebp-4h]
  HWND i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]

  if ( (this->m_psh.dwFlags & 0x1000020) == 0 )
    return CWnd::Default(this);
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: wParam);
  i = DlgItem;
  if ( DlgItem != nullptr && (GetWindowLongA(hWnd: DlgItem, nIndex: -16) & 0x10000000) != 0 && IsWindowEnabled(hWnd: i) )
    return CWnd::Default(this);
  ia = 0;
  while ( 1 )
  {
    hWnd = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: _afxPropSheetIDs[ia]);
    if ( (GetWindowLongA(hWnd, nIndex: -16) & 0x10000000) != 0 && IsWindowEnabled(hWnd) )
      break;
    if ( (unsigned int)++ia >= 4 )
      return CWnd::Default(this);
  }
  Focus = GetFocus();
  if ( !IsWindowEnabled(hWnd: Focus) )
    SetFocus(hWnd);
  return this->DefWindowProcA(this, a2: 1025u, a3: _afxPropSheetIDs[ia], a4: lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10350A4F
// Name: public: void CPropertySheet::CommonConstruct(class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::CommonConstruct(CPropertySheet *this, CWnd *pParentWnd, unsigned int iSelectPage)
{
  _PROPSHEETHEADERA_V2 *p_m_psh; // edi
  char *m_pszData; // eax

  p_m_psh = &this->m_psh;
  memset(dst: (unsigned __int8 *)&this->m_psh, value: 0, count: sizeof(this->m_psh));
  m_pszData = this->m_strCaption.m_pszData;
  this->m_bModeless = 0;
  this->m_psh.pszCaption = m_pszData;
  p_m_psh->dwSize = 52;
  this->m_psh.dwFlags = 8;
  this->m_psh.nStartPage = iSelectPage;
  this->m_bStacked = 1;
  if ( AfxHelpEnabled() != 0 )
    this->m_psh.dwFlags |= 0x200u;
  this->m_pParentWnd = pParentWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10350ABA
// Name: public: virtual int CPropertySheet::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::PreTranslateMessage(CPropertySheet *this, tagMSG *pMsg)
{
  HANDLE PropA; // ebx
  _DWORD *v5; // eax
  HANDLE v6; // eax
  unsigned int wParam; // eax

  if ( CWnd::PreTranslateMessage(this, pMsg) != 0 )
    return 1;
  PropA = GetPropA(hWnd: this->m_hWnd, lpString: PROP_CLOSEPENDING_NAME);
  v5 = GlobalLock(hMem: PropA);
  if ( v5 != nullptr )
  {
    if ( *v5 == 1 && SendMessageA(hWnd: this->m_hWnd, Msg: 0x476u, wParam: 0, lParam: 0) == 0 )
    {
      GlobalUnlock(hMem: PropA);
      v6 = RemovePropA(hWnd: this->m_hWnd, lpString: PROP_CLOSEPENDING_NAME);
      if ( v6 != nullptr )
        GlobalFree(hMem: v6);
      this->DestroyWindow(this);
      return 1;
    }
    GlobalUnlock(hMem: PropA);
  }
  if ( pMsg->message == 256 && GetAsyncKeyState(vKey: 17) < 0 )
  {
    wParam = pMsg->wParam;
    if ( (wParam == 9 || wParam == 33 || wParam == 34)
      && SendMessageA(hWnd: this->m_hWnd, Msg: 0x475u, wParam: 0, lParam: (LPARAM)pMsg) != 0 )
    {
      return 1;
    }
  }
  return CWnd::PreTranslateInput(this, lpMsg: pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10350B92
// Name: public: virtual int CPropertySheet::ContinueModal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPropertySheet::ContinueModal(CPropertySheet *this)
{
  unsigned int result; // eax

  result = CWnd::ContinueModal(this);
  if ( result != 0 )
    return SendMessageA(hWnd: this->m_hWnd, Msg: 0x476u, wParam: 0, lParam: 0) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10350BBC
// Name: public: int CPropertySheet::GetPageCount(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CPropertySheet::GetPageCount(CPropertySheet *this)
{
  CTabCtrl *TabControl; // eax

  if ( this->m_hWnd == nullptr )
    return this->m_pages.m_nSize;
  TabControl = CPropertySheet::GetTabControl(this);
  if ( TabControl == nullptr )
    AfxThrowInvalidArgException();
  return SendMessageA(hWnd: TabControl->m_hWnd, Msg: 0x1304u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10350BEA
// Name: public: int CPropertySheet::GetActiveIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CPropertySheet::GetActiveIndex(CPropertySheet *this)
{
  CTabCtrl *TabControl; // eax

  if ( this->m_hWnd == nullptr )
    return this->m_psh.nStartPage;
  TabControl = CPropertySheet::GetTabControl(this);
  if ( TabControl == nullptr )
    AfxThrowInvalidArgException();
  return SendMessageA(hWnd: TabControl->m_hWnd, Msg: 0x130Bu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10350C18
// Name: public: int CPropertySheet::SetActivePage(int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CPropertySheet::SetActivePage(CPropertySheet *this, WPARAM nPage)
{
  HWND__ *m_hWnd; // eax

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    return SendMessageA(hWnd: m_hWnd, Msg: 0x465u, wParam: nPage, lParam: 0);
  this->m_psh.nStartPage = nPage;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10350C47
// Name: public: int CPropertySheet::GetPageIndex(class CPropertyPage __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::GetPageIndex(CPropertySheet *this, CPropertyPage *pPage)
{
  int v3; // esi

  v3 = 0;
  if ( CPropertySheet::GetPageCount(this) <= 0 )
    return -1;
  while ( CPropertySheet::GetPage(this, nPage: v3) != pPage )
  {
    if ( ++v3 >= CPropertySheet::GetPageCount(this) )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10350C81
// Name: public: int CPropertySheet::SetActivePage(class CPropertyPage __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CPropertySheet::SetActivePage(CPropertySheet *this, CPropertyPage *pPage)
{
  WPARAM PageIndex; // eax

  if ( pPage == nullptr )
    AfxThrowInvalidArgException();
  PageIndex = CPropertySheet::GetPageIndex(this, pPage);
  return CPropertySheet::SetActivePage(this, nPage: PageIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10350CA9
// Name: public: void CPropertySheet::RemovePage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::RemovePage(CPropertySheet *this, int nPage)
{
  HWND__ *m_hWnd; // eax

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    SendMessageA(hWnd: m_hWnd, Msg: 0x466u, wParam: nPage, lParam: 0);
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
    this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_pages,
    nIndex: nPage,
    nCount: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10350CDE
// Name: protected: void CPropertySheet::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::OnSysCommand(CPropertySheet *this, __int16 nID, int __formal)
{
  this->m_nModalResult = 2;
  if ( (nID & 0xFFF0) == 0xF060 && this->m_bModeless != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  else
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10350D1B
// Name: public: virtual int CPropertySheet::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnInitDialog(CPropertySheet *this)
{
  HWND DlgItem; // eax
  HWND v3; // eax
  HWND v4; // eax
  HWND v5; // eax
  HWND v6; // ebx
  HWND__ *m_hWnd; // [esp-Ch] [ebp-44h]
  HWND__ *v9; // [esp-Ch] [ebp-44h]
  HWND__ *v10; // [esp-Ch] [ebp-44h]
  HWND__ *hWnd; // [esp+8h] [ebp-30h]
  HWND__ *hWnda; // [esp+8h] [ebp-30h]
  int cyDiff; // [esp+Ch] [ebp-2Ch]
  int cyDiffa; // [esp+Ch] [ebp-2Ch]
  unsigned int i; // [esp+10h] [ebp-28h]
  unsigned int j; // [esp+10h] [ebp-28h]
  CRect rectWnd; // [esp+14h] [ebp-24h] BYREF
  CRect rectButton; // [esp+24h] [ebp-14h] BYREF

  if ( this->m_bStacked == 0 )
  {
    DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 12320);
    if ( DlgItem != nullptr )
      CWnd::ModifyStyle(hWnd: DlgItem, dwRemove: 0x200u, dwAdd: 0, nFlags: 0);
  }
  if ( (this->m_psh.dwFlags & 0x1000020) == 0 )
  {
    hWnd = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 12320);
    memset(&rectButton, 0, sizeof(rectButton));
    GetWindowRect(hWnd, lpRect: &rectButton);
    CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectButton);
    m_hWnd = this->m_hWnd;
    memset(&rectWnd, 0, 12);
    rectWnd.bottom = 32;
    MapDialogRect(hDlg: m_hWnd, lpRect: &rectWnd);
    if ( rectWnd.bottom < rectButton.bottom )
    {
      cyDiff = rectButton.bottom - rectButton.top - rectWnd.bottom;
      SetWindowPos(
        hWnd,
        hWndInsertAfter: nullptr,
        X: 0,
        Y: 0,
        cx: rectButton.right - rectButton.left,
        cy: rectWnd.bottom,
        uFlags: 0x16u);
      for ( i = 0; i < 4; ++i )
      {
        v3 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: _afxPropSheetButtons[i]);
        hWnda = v3;
        if ( v3 != nullptr )
        {
          GetWindowRect(hWnd: v3, lpRect: &rectButton);
          CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectButton);
          SetWindowPos(
            hWnd: hWnda,
            hWndInsertAfter: nullptr,
            X: rectButton.left,
            Y: rectButton.top - cyDiff,
            cx: 0,
            cy: 0,
            uFlags: 0x15u);
        }
      }
      GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectButton);
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: 0,
        y: 0,
        cx: rectButton.right - rectButton.left,
        cy: rectButton.bottom - rectButton.top - cyDiff,
        nFlags: 0x16u);
    }
  }
  cyDiffa = CWnd::Default(this);
  if ( this->m_bModeless != 0 && (this->m_psh.dwFlags & 0x1000020) == 0 )
  {
    v9 = this->m_hWnd;
    memset(&rectWnd, 0, sizeof(rectWnd));
    GetWindowRect(hWnd: v9, lpRect: &rectWnd);
    v10 = this->m_hWnd;
    memset(&rectButton, 0, sizeof(rectButton));
    v4 = GetDlgItem(hDlg: v10, nIDDlgItem: 1);
    if ( v4 != nullptr )
    {
      GetWindowRect(hWnd: v4, lpRect: &rectButton);
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: 0,
        y: 0,
        cx: rectWnd.right - rectWnd.left,
        cy: rectButton.top - rectWnd.top,
        nFlags: 0x16u);
    }
    for ( j = 0; j < 4; ++j )
    {
      v5 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: _afxPropSheetButtons[j]);
      v6 = v5;
      if ( v5 != nullptr )
      {
        ShowWindow(hWnd: v5, nCmdShow: 0);
        EnableWindow(hWnd: v6, bEnable: false);
      }
    }
  }
  if ( (CWnd::GetStyle(this) & 0x40000000) == 0 )
    CWnd::CenterWindow(this, pAlternateOwner: nullptr);
  return cyDiffa;
}

//------------------------------------------------------------------------------
// Address: 0x103511B6
// Name: public: class CPropertyPage __near * CPropertySheet::GetActivePage(void)const
// Source: json
//------------------------------------------------------------------------------
CPropertyPage *__thiscall CPropertySheet::GetActivePage(CPropertySheet *this)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v3; // eax
  LRESULT ActiveIndex; // eax

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    v3 = (HWND__ *)SendMessageA(hWnd: m_hWnd, Msg: 0x476u, wParam: 0, lParam: 0);
    return (CPropertyPage *)CWnd::FromHandle(hWnd: v3);
  }
  else
  {
    ActiveIndex = CPropertySheet::GetActiveIndex(this);
    return CPropertySheet::GetPage(this, nPage: ActiveIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103511E9
// Name: public: virtual int CPropertySheet::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::DoModal(CPropertySheet *this)
{
  CWinApp *m_pCurrentWinApp; // eax
  CWnd *m_pParentWnd; // eax
  HWND__ *m_hWnd; // eax
  HWND__ *SafeOwner; // eax
  HWND v6; // edi
  HWND Capture; // eax
  unsigned int dwFlags; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int m_nModalResult; // ebx
  AFX_MODULE_STATE *v11; // eax
  int v12; // eax
  int v13; // ebx
  char v14; // bl
  CWinApp *pApp; // [esp+8h] [ebp-Ch]
  HWND__ *hWndTop; // [esp+Ch] [ebp-8h] BYREF
  int bEnableParent; // [esp+10h] [ebp-4h]

  AfxEndDeferRegisterClass(fToRegister: 16);
  AfxEndDeferRegisterClass(fToRegister: 245760);
  this->BuildPropPageArray(this);
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  pApp = m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    CWinApp::EnableModeless(this: m_pCurrentWinApp, bEnable: 0);
  m_pParentWnd = this->m_pParentWnd;
  if ( m_pParentWnd != nullptr )
    m_hWnd = m_pParentWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  SafeOwner = CWnd::GetSafeOwner_(hParent: m_hWnd, pWndTop: &hWndTop);
  v6 = SafeOwner;
  this->m_psh.hwndParent = SafeOwner;
  bEnableParent = 0;
  if ( SafeOwner != nullptr && IsWindowEnabled(hWnd: SafeOwner) )
  {
    EnableWindow(hWnd: v6, bEnable: false);
    bEnableParent = 1;
  }
  Capture = GetCapture();
  if ( Capture != nullptr )
    SendMessageA(hWnd: Capture, Msg: 0x1Fu, wParam: 0, lParam: 0);
  this->m_nModalResult = 0;
  if ( (this->m_psh.dwFlags & 0x4000) == 0 )
    this->m_nFlags |= 0x10u;
  AfxHookWindowCreate(pWnd: this);
  dwFlags = this->m_psh.dwFlags;
  if ( (dwFlags & 0x4000) != 0 )
  {
    ModuleState = AfxGetModuleState();
    m_nModalResult = CComCtlWrapper::_PropertySheetA(
                       this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
                       unnamed1: &this->m_psh);
    AfxUnhookWindowCreate();
    this->m_hWnd = nullptr;
  }
  else
  {
    this->m_psh.dwFlags = dwFlags | 0x400;
    v11 = AfxGetModuleState();
    v12 = CComCtlWrapper::_PropertySheetA(
            this: *(CComCtlWrapper **)v11->m_pDllIsolationWrappers,
            unnamed1: &this->m_psh);
    this->m_psh.dwFlags &= ~0x400u;
    v13 = v12;
    AfxUnhookWindowCreate();
    if ( v13 == 0 || v13 == -1 )
      this->m_nFlags &= ~0x10u;
    m_nModalResult = this->m_nModalResult;
    if ( this->ContinueModal(this) != 0 )
    {
      v14 = 4;
      if ( (CWnd::GetStyle(this) & 0x100) != 0 )
        v14 = 5;
      m_nModalResult = CWnd::RunModalLoop(this, dwFlags: v14);
    }
    if ( this->m_hWnd != nullptr )
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x97u);
  }
  if ( bEnableParent != 0 )
    EnableWindow(hWnd: v6, bEnable: true);
  if ( v6 != nullptr && GetActiveWindow() == this->m_hWnd )
    SetActiveWindow(hWnd: v6);
  if ( (this->m_psh.dwFlags & 0x4000) == 0 )
    this->DestroyWindow(this);
  if ( pApp != nullptr )
    CWinApp::EnableModeless(this: pApp, bEnable: 1);
  if ( hWndTop != nullptr )
    EnableWindow(hWnd: hWndTop, bEnable: true);
  return m_nModalResult;
}

//------------------------------------------------------------------------------
// Address: 0x10351397
// Name: public: virtual int CPropertySheet::Create(class CWnd __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPropertySheet::Create(CPropertySheet *this, CWnd *pParentWnd, HWND__ *dwStyle, unsigned int dwExStyle)
{
  _AFX_THREAD_STATE *ThreadState; // eax
  HWND__ *m_hWnd; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HGLOBAL v8; // edi
  _DWORD *v9; // eax
  HWND__ *hWnd; // [esp+18h] [ebp+Ch]

  if ( (~(this->m_psh.dwFlags >> 14) & 1) == 0 )
    AfxThrowInvalidArgException();
  ThreadState = AfxGetThreadState();
  if ( dwStyle == (HWND__ *)-1 )
  {
    ThreadState->m_dwPropStyle = -1866456892;
    if ( (this->m_psh.dwFlags & 0x1000020) == 0 )
      ThreadState->m_dwPropStyle = -1865932604;
  }
  else
  {
    ThreadState->m_dwPropStyle = (unsigned int)dwStyle;
  }
  ThreadState->m_dwPropExStyle = dwExStyle;
  AfxEndDeferRegisterClass(fToRegister: 16);
  AfxEndDeferRegisterClass(fToRegister: 245760);
  this->BuildPropPageArray(this);
  m_hWnd = (HWND__ *)pParentWnd;
  this->m_psh.dwFlags |= 0x500u;
  this->m_bModeless = 1;
  this->m_psh.pfnCallback = AfxPropSheetCallback;
  if ( pParentWnd != nullptr )
    m_hWnd = pParentWnd->m_hWnd;
  this->m_psh.hwndParent = m_hWnd;
  AfxHookWindowCreate(pWnd: this);
  ModuleState = AfxGetModuleState();
  hWnd = (HWND__ *)CComCtlWrapper::_PropertySheetA(
                     this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
                     unnamed1: &this->m_psh);
  if ( AfxUnhookWindowCreate() == 0 )
    this->PostNcDestroy(this);
  v8 = GlobalAlloc(uFlags: 0x40u, dwBytes: 4u);
  v9 = GlobalLock(hMem: v8);
  if ( v9 == nullptr )
    goto LABEL_14;
  *v9 = 1;
  GlobalUnlock(hMem: v8);
  if ( !SetPropA(hWnd: this->m_hWnd, lpString: PROP_CLOSEPENDING_NAME, hData: v8) )
  {
    GlobalFree(hMem: v8);
LABEL_14:
    this->DestroyWindow(this);
    return false;
  }
  return hWnd != nullptr && hWnd != (HWND__ *)-1;
}

//------------------------------------------------------------------------------
// Address: 0x103514AD
// Name: public: void CPropertySheet::RemovePage(class CPropertyPage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::RemovePage(CPropertySheet *this, CPropertyPage *pPage)
{
  int PageIndex; // eax

  if ( pPage == nullptr )
    AfxThrowInvalidArgException();
  PageIndex = CPropertySheet::GetPageIndex(this, pPage);
  CPropertySheet::RemovePage(this, nPage: PageIndex);
}

//------------------------------------------------------------------------------
// Address: 0x103514D5
// Name: protected: long CPropertySheet::OnKickIdle(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CPropertySheet::OnKickIdle(CPropertySheet *this, WPARAM wp, LPARAM lp)
{
  CPropertyPage *ActivePage; // eax

  ActivePage = CPropertySheet::GetActivePage(this);
  if ( ActivePage != nullptr )
    return SendMessageA(hWnd: ActivePage->m_hWnd, Msg: 0x36Au, wParam: wp, lParam: lp);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103514FF
// Name: protected: long CPropertySheet::OnCommandHelp(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPropertySheet::OnCommandHelp(
        CPropertySheet *this,
        CNoTrackObject_vtbl *wParam,
        CNoTrackObject_vtbl *lParam)
{
  CPropertyPage *ActivePage; // eax

  ActivePage = CPropertySheet::GetActivePage(this);
  return AfxCallWndProc(
           pWnd: ActivePage,
           hWnd: (CNoTrackObject_vtbl *)ActivePage->m_hWnd,
           nMsg: (CNoTrackObject_vtbl *)0x365,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10351726
// Name: protected: virtual struct AFX_MSGMAP const __near * CPropertySheet::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPropertySheet::GetMessageMap(CPropertySheet *this)
{
  return &messageMap_20;
}

//------------------------------------------------------------------------------
// Address: 0x1035172C
// Name: public: CPropertySheet::CPropertySheet(void)
// Source: json
//------------------------------------------------------------------------------
CPropertySheet *__thiscall CPropertySheet::CPropertySheet(CPropertySheet *this)
{
  CAfxStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CPropertySheet_vtbl *)&CPropertySheet::`vftable';
  CPtrArray::CPtrArray(this: &this->m_pages);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  CPropertySheet::CommonConstruct(this, pParentWnd: nullptr, iSelectPage: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351783
// Name: public: virtual CPropertySheet::~CPropertySheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::~CPropertySheet(CPropertySheet *this)
{
  this->__vftable = (CPropertySheet_vtbl *)&CPropertySheet::`vftable';
  free(pMem: this->m_psh.phpage);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCaption.m_pszData - 1);
  CPtrArray::~CPtrArray(this: &this->m_pages);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103517D4
// Name: public: virtual void CPropertySheet::BuildPropPageArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::BuildPropPageArray(CPropertySheet *this)
{
  int v2; // esi
  unsigned int v3; // ebx
  _PROPSHEETPAGEA *v4; // eax
  _PROPSHEETPAGEA *v5; // esi
  unsigned int v6; // eax
  bool v7; // cc
  CPropertyPage *Page; // eax
  CPropertyPage *v9; // ebx
  char *m_pszData; // eax
  char *v11; // eax
  int bWizard; // [esp+Ch] [ebp-10h]
  unsigned __int8 *ppspOrigByte; // [esp+10h] [ebp-Ch]
  unsigned __int8 *pPropSheetPagesArrEnd; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  free(pMem: this->m_psh.phpage);
  v2 = 0;
  v3 = 0;
  for ( this->m_psh.ppsp = nullptr; v2 < this->m_pages.m_nSize; ++v2 )
    v3 += CPropertySheet::GetPage(this, nPage: v2)->m_pPSP->dwSize;
  v4 = (_PROPSHEETPAGEA *)MemAlloc_Alloc(nSize: v3);
  v5 = v4;
  ppspOrigByte = (unsigned __int8 *)v4;
  if ( v4 == nullptr )
    goto LABEL_4;
  pPropSheetPagesArrEnd = (unsigned __int8 *)v4 + v3;
  if ( (_PROPSHEETPAGEA *)((char *)v4 + v3) < v4 )
    AfxThrowInvalidArgException();
  i = 0;
  v6 = this->m_psh.dwFlags & 0x1000020;
  v7 = this->m_pages.m_nSize <= 0;
  this->m_psh.ppsp = v5;
  bWizard = v6;
  if ( !v7 )
  {
    while ( 1 )
    {
      Page = CPropertySheet::GetPage(this, nPage: i);
      v9 = Page;
      if ( v5 < (_PROPSHEETPAGEA *)ppspOrigByte || v5 > (_PROPSHEETPAGEA *)pPropSheetPagesArrEnd )
        break;
      ATL::Checked::memcpy_s(
        _S1: (void *)v5,
        _S1max: pPropSheetPagesArrEnd - (unsigned __int8 *)v5,
        _S2: Page->m_pPSP,
        _N: Page->m_pPSP->dwSize);
      m_pszData = v9->m_strHeaderTitle.m_pszData;
      if ( *((_DWORD *)m_pszData - 3) != 0 )
      {
        v5->dwFlags |= 0x1000u;
        v5->pszHeaderTitle = m_pszData;
      }
      v11 = v9->m_strHeaderSubTitle.m_pszData;
      if ( *((_DWORD *)v11 - 3) != 0 )
      {
        v5->dwFlags |= 0x2000u;
        v5->pszHeaderSubTitle = v11;
      }
      CPropertyPage::PreProcessPageTemplate(this: v9, psp: v5, bWizard);
      v5 = (_PROPSHEETPAGEA *)((char *)v5 + v5->dwSize);
      if ( ++i >= this->m_pages.m_nSize )
        goto LABEL_15;
    }
LABEL_4:
    AfxThrowMemoryException();
  }
LABEL_15:
  this->m_psh.nPages = this->m_pages.m_nSize;
}

//------------------------------------------------------------------------------
// Address: 0x103518DF
// Name: public: void CPropertySheet::AddPage(class CPropertyPage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::AddPage(CPropertySheet *this, CPropertyPage *pPage)
{
  unsigned int v3; // ecx
  const _PROPSHEETPAGEA *ppsp; // ebx
  signed int dwSize; // eax
  signed int v6; // edx
  signed int v7; // eax
  signed int v8; // ebx
  const _PROPSHEETPAGEA *v9; // edi
  const _PROPSHEETPAGEA *v10; // edi
  char *m_pszData; // eax
  char *v12; // ebx
  AFX_MODULE_STATE *ModuleState; // eax
  struct _PSP *PropertySheetPageA; // eax
  struct _PSP *v15; // edi
  AFX_MODULE_STATE *v16; // eax
  int nBytes; // [esp+4h] [ebp-4h]

  if ( pPage == nullptr )
    AfxThrowInvalidArgException();
  CUIntArray::SetAtGrow(this: &this->m_pages, nIndex: this->m_pages.m_nSize, newElement: pPage);
  if ( this->m_hWnd != nullptr )
  {
    v3 = 0;
    ppsp = this->m_psh.ppsp;
    nBytes = 0;
    if ( this->m_psh.nPages != 0 )
    {
      while ( 1 )
      {
        dwSize = ppsp->dwSize;
        v6 = ppsp->dwSize + nBytes;
        if ( v6 < nBytes || v6 < dwSize )
          break;
        ppsp = (const _PROPSHEETPAGEA *)((char *)ppsp + dwSize);
        ++v3;
        nBytes = v6;
        if ( v3 >= this->m_psh.nPages )
          goto LABEL_8;
      }
LABEL_18:
      AfxThrowMemoryException();
    }
LABEL_8:
    v7 = pPage->m_pPSP->dwSize;
    v8 = v7 + nBytes;
    if ( v7 + nBytes < nBytes )
      goto LABEL_18;
    if ( v8 < v7 )
      goto LABEL_18;
    v9 = (const _PROPSHEETPAGEA *)_realloc_crt(ptr: this->m_psh.phpage, size: v7 + nBytes);
    if ( v9 == nullptr )
      goto LABEL_18;
    this->m_psh.ppsp = v9;
    v10 = (const _PROPSHEETPAGEA *)((char *)v9 + nBytes);
    ATL::Checked::memcpy_s(_S1: (void *)v10, _S1max: v8 - nBytes, _S2: pPage->m_pPSP, _N: pPage->m_pPSP->dwSize);
    CPropertyPage::PreProcessPageTemplate(this: pPage, psp: v10, bWizard: (this->m_psh.dwFlags & 0x1000020) != 0);
    m_pszData = pPage->m_strHeaderTitle.m_pszData;
    if ( *((_DWORD *)m_pszData - 3) != 0 )
    {
      v10->dwFlags |= 0x1000u;
      v10->pszHeaderTitle = m_pszData;
    }
    v12 = pPage->m_strHeaderSubTitle.m_pszData;
    if ( *((_DWORD *)v12 - 3) != 0 )
    {
      v10->dwFlags |= 0x2000u;
      v10->pszHeaderSubTitle = v12;
    }
    ModuleState = AfxGetModuleState();
    PropertySheetPageA = CComCtlWrapper::_CreatePropertySheetPageA(
                           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
                           constPropSheetPagePointer: v10);
    v15 = PropertySheetPageA;
    if ( PropertySheetPageA == nullptr )
      goto LABEL_18;
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x467u, wParam: 0, lParam: (LPARAM)PropertySheetPageA) == 0 )
    {
      v16 = AfxGetModuleState();
      CComCtlWrapper::_DestroyPropertySheetPage(this: *(CComCtlWrapper **)v16->m_pDllIsolationWrappers, unnamed1: v15);
      goto LABEL_18;
    }
    ++this->m_psh.nPages;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10351C42
// Name: public: CPropertySheet::CPropertySheet(char const __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CPropertySheet *__thiscall CPropertySheet::CPropertySheet(
        CPropertySheet *this,
        const char *pszCaption,
        CWnd *pParentWnd,
        unsigned int iSelectPage)
{
  CAfxStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CPropertySheet_vtbl *)&CPropertySheet::`vftable';
  CPtrArray::CPtrArray(this: &this->m_pages);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  if ( !AfxIsValidString(psz: pszCaption, nLength: -1) )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCaption, pszSrc: pszCaption);
  CPropertySheet::CommonConstruct(this, pParentWnd, iSelectPage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351CBE
// Name: public: void CPropertySheet::SetTitle(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropertySheet::SetTitle(CPropertySheet *this, const char *lpszText, WPARAM nStyle)
{
  HWND__ *m_hWnd; // eax

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    SendMessageA(hWnd: m_hWnd, Msg: 0x46Fu, wParam: nStyle, lParam: (LPARAM)lpszText);
  }
  else
  {
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCaption, pszSrc: lpszText);
    this->m_psh.pszCaption = this->m_strCaption.m_pszData;
    this->m_psh.dwFlags = nStyle | this->m_psh.dwFlags & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103587C1
// Name: public: void CWnd::OnHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnHelp(CWnd *this)
{
  HWND i; // eax
  HWND j; // eax
  CWnd *TopLevelParent; // eax
  HWND k; // eax
  HWND__ *hWnd; // [esp+10h] [ebp-4h]
  HWND__ *hWnda; // [esp+10h] [ebp-4h]
  HWND__ *hWndb; // [esp+10h] [ebp-4h]

  for ( i = GetCapture(); ; i = AfxGetParentOwner(hWnd) )
  {
    hWnd = i;
    if ( i == nullptr )
      break;
    if ( SendMessageA(hWnd: i, Msg: 0x365u, wParam: 0, lParam: 0) != 0 )
      return;
  }
  for ( j = GetFocus(); ; j = AfxGetParentOwner(hWnd: hWnda) )
  {
    hWnda = j;
    if ( j == nullptr )
      break;
    if ( SendMessageA(hWnd: j, Msg: 0x365u, wParam: 0, lParam: 0) != 0 )
      return;
  }
  TopLevelParent = CWnd::GetTopLevelParent(this);
  if ( TopLevelParent == nullptr )
    AfxThrowInvalidArgException();
  for ( k = GetLastActivePopup(hWnd: TopLevelParent->m_hWnd); ; k = AfxGetParentOwner(hWnd: hWndb) )
  {
    hWndb = k;
    if ( k == nullptr )
      break;
    if ( SendMessageA(hWnd: k, Msg: 0x365u, wParam: 0, lParam: 0) != 0 )
      return;
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE147u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103588A3
// Name: public: void CWnd::OnHelpFinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::OnHelpFinder(CWnd *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->WinHelpInternal(this: ModuleState->m_pCurrentWinApp, a2: 0, a3: 11u);
}

//------------------------------------------------------------------------------
// Address: 0x1035A93F
// Name: protected: void CWnd::OnCancelMode(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWnd::OnCancelMode(CMFCColorPickerCtrl *this)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10371F91
// Name: public: void CWnd::FilterToolTipMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::FilterToolTipMessage(CWnd *this, tagMSG *pMsg)
{
  tagMSG *v2; // esi
  unsigned int message; // ebx
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // eax
  _DWORD *v5; // edi
  CWnd *i; // eax
  CToolTipCtrl *v7; // ebx
  CToolTipCtrl *v8; // eax
  CToolTipCtrl_vtbl *v9; // eax
  CWnd_vtbl *v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  unsigned __int8 *v13; // eax
  CWnd *j; // eax
  BOOL v15; // eax
  HWND__ *hwnd; // [esp-4h] [ebp-A4h]
  HWND Parent; // [esp-4h] [ebp-A4h]
  HWND v18; // [esp-4h] [ebp-A4h]
  tagPOINT Point; // [esp+10h] [ebp-90h] BYREF
  tagPOINT v20; // [esp+18h] [ebp-88h] BYREF
  AFX_MODULE_THREAD_STATE *v21; // [esp+20h] [ebp-80h]
  tagMSG *v22; // [esp+24h] [ebp-7Ch]
  CWnd *ParentOwner; // [esp+28h] [ebp-78h]
  CWnd *v24; // [esp+2Ch] [ebp-74h]
  unsigned __int8 v25[48]; // [esp+30h] [ebp-70h] BYREF
  unsigned __int8 dst[60]; // [esp+60h] [ebp-40h] BYREF
  int v27; // [esp+9Ch] [ebp-4h]

  v2 = pMsg;
  message = pMsg->message;
  v24 = this;
  v22 = pMsg;
  if ( (message == 512 || message == 160 || message == 514 || message == 517 || message == 520)
    && GetKeyState(nVirtKey: 1) >= 0
    && GetKeyState(nVirtKey: 2) >= 0
    && GetKeyState(nVirtKey: 4) >= 0 )
  {
    ModuleThreadState = AfxGetModuleThreadState();
    hwnd = pMsg->hwnd;
    v5 = &ModuleThreadState->__vftable;
    v21 = ModuleThreadState;
    for ( i = CWnd::FromHandle(hWnd: hwnd); i != nullptr && (i->m_nFlags & 0x401) == 0; i = CWnd::FromHandle(hWnd: Parent) )
      Parent = GetParent(hWnd: i->m_hWnd);
    if ( i == v24 )
    {
      v7 = (CToolTipCtrl *)v5[15];
      ParentOwner = CWnd::GetParentOwner(this: v24);
      if ( v7 == nullptr )
        goto LABEL_20;
      if ( CWnd::GetOwner(this: v7) != ParentOwner )
      {
        v7->DestroyWindow(this: v7);
        ((void (__thiscall *)(CToolTipCtrl *, int))v7->dtr_CObject)(a1: v7, a2: 1);
        v7 = nullptr;
        v5[15] = 0;
      }
      if ( v7 == nullptr )
      {
LABEL_20:
        v8 = (CToolTipCtrl *)operator new(nSize: 0x90u);
        v20.y = (int)v8;
        v7 = nullptr;
        v27 = 0;
        if ( v8 != nullptr )
          v7 = CToolTipCtrl::CToolTipCtrl(this: v8);
        v9 = v7->__vftable;
        v27 = -1;
        if ( v9->Create_2(this: v7, a2: ParentOwner, a3: 1u) == 0 )
        {
          ((void (__thiscall *)(CToolTipCtrl *, int))v7->dtr_CObject)(a1: v7, a2: 1);
          return;
        }
        SendMessageA(hWnd: v7->m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
        v2 = v22;
        v5[15] = v7;
      }
      memset(dst, value: 0, count: 0x30u);
      Point = v2->pt;
      ScreenToClient(hWnd: v24->m_hWnd, lpPoint: &Point);
      memset(dst: v25, value: 0, count: sizeof(v25));
      v10 = v24->__vftable;
      *(_DWORD *)v25 = 44;
      v11 = ((int (__thiscall *)(CWnd *, int, int, unsigned __int8 *))v10->OnToolHitTest)(
              a1: v24,
              a2: Point.x,
              a3: Point.y,
              a4: v25);
      v20.y = v11;
      ParentOwner = v11 != -1 ? v24 : nullptr;
      if ( v5[17] == v11 && v5[16] == (v11 != -1 ? (unsigned int)v24 : 0) )
      {
        if ( (v24->m_nFlags & 0x400) != 0 )
        {
          GetCursorPos(lpPoint: &v20);
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0x412u, wParam: 0, lParam: LOWORD(v20.x) | (LOWORD(v20.y) << 16));
        }
        else if ( v11 != -1 )
        {
          _AfxRelayToolTipMessage(pToolTip: v7, pMsg: v2);
        }
      }
      else
      {
        if ( v11 == -1 )
        {
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
        }
        else
        {
          qmemcpy(dst, v25, 48);
          *(_DWORD *)&dst[4] = *(_DWORD *)&v25[4] & 0x3FFFFFFF;
          if ( (v24->m_nFlags & 0x400) != 0 )
            *(_DWORD *)&dst[4] = *(_DWORD *)&v25[4] & 0x3FFFFFDF | 0x20;
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0x404u, wParam: 0, lParam: (LPARAM)dst);
          if ( (*(_DWORD *)&v25[4] & 0x40000000) != 0 || CWnd::IsTopParentActive(this: v24) )
          {
            SendMessageA(hWnd: v7->m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
            if ( (v24->m_nFlags & 0x400) != 0 )
              SendMessageA(hWnd: v7->m_hWnd, Msg: 0x411u, wParam: 1u, lParam: (LPARAM)dst);
            SetWindowPos(hWnd: v7->m_hWnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x213u);
          }
          v5 = &v21->__vftable;
          v2 = v22;
        }
        _AfxRelayToolTipMessage(pToolTip: v7, pMsg: v2);
        v12 = (_DWORD *)v5[18];
        if ( v12 != nullptr && *v12 >= 0x2Cu )
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0x405u, wParam: 0, lParam: v5[18]);
        v5[16] = ParentOwner;
        v5[17] = v20.y;
        if ( v5[18] == 0 )
        {
          v13 = (unsigned __int8 *)operator new(nSize: 0x30u);
          v5[18] = v13;
          memset(dst: v13, value: 0, count: 0x30u);
        }
        qmemcpy((void *)v5[18], v25, 48);
      }
      if ( *(_DWORD *)&v25[36] != -1 && *(_DWORD *)&v25[32] == 0 )
        free(pMem: *(void **)&v25[36]);
    }
    else if ( i == nullptr )
    {
      v5[16] = 0;
      v5[17] = -1;
    }
  }
  else if ( (v24->m_nFlags & 0x401) != 0 )
  {
    for ( j = CWnd::FromHandle(hWnd: pMsg->hwnd); j != nullptr; j = CWnd::FromHandle(hWnd: v18) )
    {
      if ( j == v24 )
        goto LABEL_57;
      if ( (j->m_nFlags & 0x401) != 0 )
        break;
      v18 = GetParent(hWnd: j->m_hWnd);
    }
    if ( j != v24 )
      return;
LABEL_57:
    v15 = message >= 0x100 && message <= 0x109 || message - 260 <= 3;
    if ( (v24->m_nFlags & 0x400) == 0
      && (v15
       || message == 513
       || message == 515
       || message == 516
       || message == 518
       || message == 519
       || message == 521
       || message == 161
       || message == 163
       || message == 164
       || message == 166
       || message == 167
       || message == 169) )
    {
      CWnd::CancelToolTips(bKeys: v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103723C5
// Name: public: static void CWnd::_FilterToolTipMessage(struct tagMSG __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CWnd::_FilterToolTipMessage(tagMSG *pMsg, CWnd *pWnd)
{
  CWnd::FilterToolTipMessage(this: pWnd, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1037249B
// Name: public: int CWnd::_EnableToolTips(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::_EnableToolTips(CWnd *this, int bEnable, unsigned int nFlag)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // eax
  CToolTipCtrl *m_pToolTip; // edi
  HWND m_hWnd; // [esp-10h] [ebp-50h]
  tagTOOLINFOA ti; // [esp+Ch] [ebp-34h] BYREF

  ModuleThreadState = AfxGetModuleThreadState();
  m_pToolTip = ModuleThreadState->m_pToolTip;
  if ( bEnable != 0 )
  {
    if ( (nFlag & this->m_nFlags) == 0 )
    {
      AfxGetModuleState()->m_pfnFilterToolTipMessage = CWnd::_FilterToolTipMessage;
      this->m_nFlags |= nFlag;
    }
  }
  else if ( (nFlag & this->m_nFlags) != 0 )
  {
    if ( ModuleThreadState->m_pLastHit == this )
      CWnd::CancelToolTips(bKeys: 1);
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    {
      memset(dst: (unsigned __int8 *)&ti, value: 0, count: sizeof(ti));
      ti.hwnd = this->m_hWnd;
      ti.uId = (unsigned int)ti.hwnd;
      m_hWnd = m_pToolTip->m_hWnd;
      ti.cbSize = 44;
      ti.uFlags = 1;
      SendMessageA(hWnd: m_hWnd, Msg: 0x405u, wParam: 0, lParam: (LPARAM)&ti);
    }
    this->m_nFlags &= ~nFlag;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037254B
// Name: public: int CWnd::EnableToolTips(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWnd::EnableToolTips(CWnd *this, int bEnable)
{
  return CWnd::_EnableToolTips(this, bEnable, nFlag: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10376000
// Name: public: void CWnd::MapWindowPoints(class CWnd __near *,struct tagRECT __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::MapWindowPoints(CWnd *this, CWnd *pwndTo, tagPOINT *lpRect)
{
  HWND__ *m_hWnd; // eax

  m_hWnd = (HWND__ *)pwndTo;
  if ( pwndTo != nullptr )
    m_hWnd = pwndTo->m_hWnd;
  MapWindowPoints(hWndFrom: this->m_hWnd, hWndTo: m_hWnd, lpPoints: lpRect, cPoints: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x103A58E1
// Name: public: class CWnd __near * CWnd::GetNextDlgGroupItem(class CWnd __near *,int)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::GetNextDlgGroupItem(CWnd *this, CWnd *pWndCtl, BOOL bPrevious)
{
  HWND__ *m_hWnd; // eax
  HWND NextDlgGroupItem; // eax

  m_hWnd = (HWND__ *)pWndCtl;
  if ( pWndCtl != nullptr )
    m_hWnd = pWndCtl->m_hWnd;
  NextDlgGroupItem = GetNextDlgGroupItem(hDlg: this->m_hWnd, hCtl: m_hWnd, bPrevious);
  return CWnd::FromHandle(hWnd: NextDlgGroupItem);
}

//------------------------------------------------------------------------------
// Address: 0x105C4912
// Name: _dynamic_initializer_for__CWnd::m_nMsgDragList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__CWnd::m_nMsgDragList__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "commctrl_DragListMsg");
  CWnd::m_nMsgDragList = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C4923
// Name: _dynamic_initializer_for__CWnd::wndTop__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWnd::wndTop__()
{
  CWnd::CWnd(this: &CWnd::wndTop, hWnd: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__CWnd::wndTop__);
}

//------------------------------------------------------------------------------
// Address: 0x105C493B
// Name: _dynamic_initializer_for__CWnd::wndBottom__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWnd::wndBottom__()
{
  CWnd::CWnd(this: &CWnd::wndBottom, hWnd: (HWND__ *)1);
  return atexit(func: dynamic_atexit_destructor_for__CWnd::wndBottom__);
}

//------------------------------------------------------------------------------
// Address: 0x105C4953
// Name: _dynamic_initializer_for__CWnd::wndTopMost__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWnd::wndTopMost__()
{
  CWnd::CWnd(this: &CWnd::wndTopMost, hWnd: (HWND__ *)0xFFFFFFFF);
  return atexit(func: dynamic_atexit_destructor_for__CWnd::wndTopMost__);
}

//------------------------------------------------------------------------------
// Address: 0x105C496B
// Name: _dynamic_initializer_for__CWnd::wndNoTopMost__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWnd::wndNoTopMost__()
{
  CWnd::CWnd(this: &CWnd::wndNoTopMost, hWnd: (HWND__ *)0xFFFFFFFE);
  return atexit(func: dynamic_atexit_destructor_for__CWnd::wndNoTopMost__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC135
// Name: _dynamic_atexit_destructor_for__CWnd::wndTop__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWnd::wndTop__()
{
  CWnd::~CWnd(this: &CWnd::wndTop);
}

//------------------------------------------------------------------------------
// Address: 0x105CC13F
// Name: _dynamic_atexit_destructor_for__CWnd::wndBottom__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWnd::wndBottom__()
{
  CWnd::~CWnd(this: &CWnd::wndBottom);
}

//------------------------------------------------------------------------------
// Address: 0x105CC149
// Name: _dynamic_atexit_destructor_for__CWnd::wndTopMost__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWnd::wndTopMost__()
{
  CWnd::~CWnd(this: &CWnd::wndTopMost);
}

//------------------------------------------------------------------------------
// Address: 0x105CC153
// Name: _dynamic_atexit_destructor_for__CWnd::wndNoTopMost__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWnd::wndNoTopMost__()
{
  CWnd::~CWnd(this: &CWnd::wndNoTopMost);
}

//------------------------------------------------------------------------------
// Address: 0x10339AB5
// Name: public: virtual int CMFCVisualManager::OnEraseMDIClientArea(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::OnEraseMDIClientArea(CMFCVisualManager *this, CDC *__formal, CRect __formala)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10339ABA
// Name: public: virtual int CView::OnDrop(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::OnDrop(
        CMFCRibbonBaseElement *this,
        int bAccelerator,
        int nNotifyCode,
        int wParam,
        unsigned int lParam)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10339ABF
// Name: struct AFX_MSGMAP_ENTRY const __near * AfxFindMessageEntry(struct AFX_MSGMAP_ENTRY const __near *,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP_ENTRY *__stdcall AfxFindMessageEntry(
        const AFX_MSGMAP_ENTRY *lpEntry,
        unsigned int nMsg,
        unsigned int nCode,
        unsigned int nID)
{
  while ( lpEntry->nSig != 0 )
  {
    if ( nMsg == lpEntry->nMessage && nCode == lpEntry->nCode && nID >= lpEntry->nID && nID <= lpEntry->nLastID )
      return lpEntry;
    ++lpEntry;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10339B47
// Name: public: CTestCmdUI::CTestCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTestCmdUI *__thiscall CTestCmdUI::CTestCmdUI(CTestCmdUI *this)
{
  CCmdUI::CCmdUI(this);
  this->__vftable = (CTestCmdUI_vtbl *)&CTestCmdUI::`vftable';
  this->m_bEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10339BF8
// Name: void AfxRepositionWindow(struct AFX_SIZEPARENTPARAMS __near *,struct HWND__ __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxRepositionWindow(AFX_SIZEPARENTPARAMS *lpLayout, HWND__ *hWnd, const tagRECT *lpRect)
{
  int left; // [esp-14h] [ebp-3Ch]
  int top; // [esp-10h] [ebp-38h]
  int v5; // [esp-Ch] [ebp-34h]
  int v6; // [esp-8h] [ebp-30h]
  HWND__ *hWndParent; // [esp+Ch] [ebp-1Ch]
  CRect rectOld; // [esp+14h] [ebp-14h] BYREF

  hWndParent = GetParent(hWnd);
  if ( lpLayout == nullptr || lpLayout->hDWP != nullptr )
  {
    memset(&rectOld, 0, sizeof(rectOld));
    GetWindowRect(hWnd, lpRect: &rectOld);
    ScreenToClient(hWnd: hWndParent, lpPoint: (LPPOINT)&rectOld);
    ScreenToClient(hWnd: hWndParent, lpPoint: (LPPOINT)&rectOld.right);
    if ( !EqualRect(lprc1: &rectOld, lprc2: lpRect) )
    {
      v6 = lpRect->bottom - lpRect->top;
      v5 = lpRect->right - lpRect->left;
      top = lpRect->top;
      left = lpRect->left;
      if ( lpLayout != nullptr )
        lpLayout->hDWP = DeferWindowPos(
                           hWinPosInfo: lpLayout->hDWP,
                           hWnd,
                           hWndInsertAfter: nullptr,
                           x: left,
                           y: top,
                           cx: v5,
                           cy: v6,
                           uFlags: 0x14u);
      else
        SetWindowPos(hWnd, hWndInsertAfter: nullptr, X: left, Y: top, cx: v5, cy: v6, uFlags: 0x14u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10339CE3
// Name: public: virtual long CWnd::XAccessible::GetIDsOfNames(struct _GUID const __near &,wchar_t __near * __near *,unsigned int,unsigned long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::GetIDsOfNames(
        CWnd::XAccessible *this,
        const _GUID *refiid,
        wchar_t **rgszNames,
        unsigned int cNames,
        unsigned int lcid,
        int *rgDispId)
{
  return ATL::AtlIAccessibleGetIDsOfNamesHelper(__formal: refiid, rgszNames, cNames, a4: lcid, (char *)rgDispId);
}

//------------------------------------------------------------------------------
// Address: 0x10339D00
// Name: public: virtual long CWnd::XAccessible::GetTypeInfoCount(unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::GetTypeInfoCount(CWnd::XAccessible *this, unsigned int *pctinfo)
{
  if ( pctinfo == nullptr )
    return -2147467261;
  *pctinfo = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10339D1F
// Name: public: virtual long CWnd::XAccessible::GetTypeInfo(unsigned int,unsigned long,struct ITypeInfo __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::GetTypeInfo(
        CWnd::XAccessible *this,
        CWnd::XAccessible *__formal,
        unsigned int __formala,
        ITypeInfo **a4)
{
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x10339D27
// Name: public: virtual long CWnd::XAccessible::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accState(CWnd::XAccessible *this, tagVARIANT varChild, tagVARIANT *pvarState)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))(v3 + 180))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pvarState);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033A691
// Name: public: int CFrameWnd::IsTracking(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameWnd::IsTracking(CFrameWnd *this)
{
  unsigned int m_nIDTracking; // eax

  m_nIDTracking = this->m_nIDTracking;
  return m_nIDTracking != 0 && m_nIDTracking != 57346 && m_nIDTracking != 57345;
}

//------------------------------------------------------------------------------
// Address: 0x1033ABAE
// Name: void _AfxPreInitDialog(class CWnd __near *,struct tagRECT __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxPreInitDialog(CWnd *pWnd, tagRECT *lpRectOld, unsigned int *pdwStyleOld)
{
  GetWindowRect(hWnd: pWnd->m_hWnd, lpRect: lpRectOld);
  *pdwStyleOld = CWnd::GetStyle(this: pWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1033AF16
// Name: public: virtual _AFX_HTMLHELP_STATE::~_AFX_HTMLHELP_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _AFX_HTMLHELP_STATE::~_AFX_HTMLHELP_STATE(_AFX_HTMLHELP_STATE *this)
{
  HINSTANCE__ *m_hInstHtmlHelp; // ecx

  this->__vftable = (_AFX_HTMLHELP_STATE_vtbl *)&_AFX_HTMLHELP_STATE::`vftable';
  m_hInstHtmlHelp = this->m_hInstHtmlHelp;
  if ( m_hInstHtmlHelp != nullptr )
    FreeLibrary(hLibModule: m_hInstHtmlHelp);
}

//------------------------------------------------------------------------------
// Address: 0x1033B238
// Name: public: virtual unsigned long CWnd::XAccessible::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CWnd::XAccessible::AddRef(CWnd::XAccessible *this)
{
  LONG v1; // eax
  LONG v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v5 = 0;
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 12));
  v5 = -1;
  v2 = v1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033B276
// Name: public: virtual unsigned long CWnd::XAccessible::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CWnd::XAccessible::Release(CWnd::XAccessible *this)
{
  LONG v1; // eax
  LONG v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v5 = 0;
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 12));
  v5 = -1;
  v2 = v1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033B2B4
// Name: public: virtual long CWnd::XAccessible::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::QueryInterface(CWnd::XAccessible *this, const _GUID *iid, void **ppvObj)
{
  int Interface; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v7 = 0;
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 12), iid, ppvObj);
  v7 = -1;
  v4 = Interface;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033B2F8
// Name: public: virtual long CWnd::XAccessible::Invoke(long,struct _GUID const __near &,unsigned long,unsigned short,struct tagDISPPARAMS __near *,struct tagVARIANT __near *,struct tagEXCEPINFO __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::Invoke(
        CWnd::XAccessible *this,
        int dispIdMember,
        const _GUID *refiid,
        unsigned int lcid,
        int wFlags,
        tagDISPPARAMS *pDispParams,
        tagVARIANT *pVarResult,
        tagEXCEPINFO *pExcepInfo,
        unsigned int *puArgErr)
{
  HRESULT v9; // eax
  HRESULT v10; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v13 = 0;
  v9 = ATL::AtlIAccessibleInvokeHelper(
         pAccessible: (IAccessible *)this,
         dispIdMember,
         __formal: refiid,
         a4: lcid,
         wFlags,
         pDispParams,
         pVarResult,
         a8: pExcepInfo,
         puArgErr);
  v13 = -1;
  v10 = v9;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1033B34C
// Name: public: virtual long CWnd::XAccessible::get_accParent(struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accParent(CWnd::XAccessible *this, IDispatch **ppdispParent)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v2 = *((_DWORD *)this - 12);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessible *, IDispatch **))(v2 + 152))(a1: this - 12, a2: ppdispParent);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033B391
// Name: public: virtual long CWnd::XAccessible::get_accChildCount(long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accChildCount(CWnd::XAccessible *this, int *pcountChildren)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v2 = *((_DWORD *)this - 12);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessible *, int *))(v2 + 156))(a1: this - 12, a2: pcountChildren);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033B3D6
// Name: public: virtual long CWnd::XAccessible::get_accChild(struct tagVARIANT,struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accChild(
        CWnd::XAccessible *this,
        tagVARIANT varChild,
        IDispatch **ppdispChild)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, IDispatch **))(v3 + 160))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: ppdispChild);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033B427
// Name: public: virtual long CWnd::XAccessible::get_accName(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accName(CWnd::XAccessible *this, tagVARIANT varChild, wchar_t **pszName)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 164))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszName);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033B478
// Name: public: virtual long CWnd::XAccessible::get_accValue(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accValue(CWnd::XAccessible *this, tagVARIANT varChild, wchar_t **pszValue)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 168))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszValue);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033B4C9
// Name: public: virtual long CWnd::XAccessible::get_accDescription(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accDescription(
        CWnd::XAccessible *this,
        tagVARIANT varChild,
        wchar_t **pszDescription)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 172))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszDescription);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033B51A
// Name: public: virtual long CWnd::XAccessible::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accRole(CWnd::XAccessible *this, tagVARIANT varChild, tagVARIANT *pvarRole)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))(v3 + 176))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pvarRole);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033B56B
// Name: public: ATL::CComPtr<struct IOleInPlaceUIWindow>::~CComPtr<struct IOleInPlaceUIWindow>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CComPtr<IOleInPlaceUIWindow>::~CComPtr<IOleInPlaceUIWindow>(
        ATL::CComQIPtr<ITaskbarList4,&_GUID_c43dc798_95d1_4bea_9030_bb99e2983a1a> *this)
{
  if ( this->p != nullptr )
    this->p->Release(this: this->p);
}

//------------------------------------------------------------------------------
// Address: 0x1033B9BD
// Name: public: static void ConstructDestruct<class CWnd>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CWnd>::Construct(CWnd *pObject)
{
  if ( pObject != nullptr )
    CWnd::CWnd(this: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1033BBC8
// Name: class CHandleMap __near * afxMapHWND(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHandleMap *__stdcall afxMapHWND(int bCreate)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // esi
  int (__cdecl *v2)(unsigned int); // ebx
  CHandleMap *v3; // ecx
  CHandleMap *v4; // eax

  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pmapHWND == nullptr && bCreate != 0 )
  {
    v2 = AfxSetNewHandler(pfnNewHandler: (int (__cdecl *)(unsigned int))AfxCriticalNewHandler);
    v3 = (CHandleMap *)operator new(nSize: 0x60u);
    if ( v3 != nullptr )
      v4 = CHandleMap::CHandleMap(
             this: v3,
             pClass: &CWnd::classCWnd,
             pfnConstructObject: (void (__stdcall *)(CObject *))ConstructDestruct<CWnd>::Construct,
             pfnDestructObject: ConstructDestruct<CGdiObject>::Destruct,
             nOffset: 0x20u,
             nHandles: 1);
    else
      v4 = nullptr;
    ModuleThreadState->m_pmapHWND = v4;
    AfxSetNewHandler(pfnNewHandler: v2);
  }
  return ModuleThreadState->m_pmapHWND;
}

//------------------------------------------------------------------------------
// Address: 0x1033BCF7
// Name: int AfxUnhookWindowCreate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxUnhookWindowCreate()
{
  CNoTrackObject *Data; // esi

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( AfxGetModuleState()->m_bDLL != 0 && Data[10].__vftable != nullptr )
  {
    UnhookWindowsHookEx(hhk: (HHOOK)Data[10].__vftable);
    Data[10].__vftable = nullptr;
  }
  if ( Data[5].__vftable == nullptr )
    return 1;
  Data[5].__vftable = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033C754
// Name: long _AfxInitCommonControls(struct tagINITCOMMONCONTROLSEX __near *,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxInitCommonControls(tagINITCOMMONCONTROLSEX *lpInitCtrls, int fToRegister)
{
  int v2; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax
  AFX_MODULE_STATE *v5; // eax
  CComCtlWrapper::InitCommonControlsEx_Type v7; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  ModuleState = AfxGetModuleState();
  if ( CComCtlWrapper::GetProcAddress_InitCommonControlsEx(
         this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
         result: &v7)->p != nullptr )
  {
    v4 = AfxGetModuleState();
    if ( CComCtlWrapper::_InitCommonControlsEx(
           this: *(CComCtlWrapper **)v4->m_pDllIsolationWrappers,
           unnamed1: lpInitCtrls) != 0 )
      return fToRegister;
  }
  else if ( (fToRegister & 0x3FC0) == fToRegister )
  {
    v5 = AfxGetModuleState();
    CComCtlWrapper::_InitCommonControls(this: *(CComCtlWrapper **)v5->m_pDllIsolationWrappers);
    return 16320;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033CF05
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accParent(struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accParent(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        IDispatch **ppdispParent)
{
  if ( this->m_pAccessible == nullptr )
    return -2147417848;
  if ( ppdispParent != nullptr )
    return this->m_pAccessible->get_accParent(this: this->m_pAccessible, a2: ppdispParent);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033CF37
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accChildCount(long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accChildCount(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int *pcountChildren)
{
  if ( this->m_pAccessible == nullptr )
    return -2147417848;
  if ( pcountChildren != nullptr )
    return this->m_pAccessible->get_accChildCount(this: this->m_pAccessible, a2: pcountChildren);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033CF69
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accChild(struct tagVARIANT,struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accChild(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        IDispatch **ppdispChild)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( ppdispChild != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, IDispatch **))m_pAccessible->get_accChild)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: ppdispChild);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033CFA9
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accName(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accName(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszName)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszName != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accName)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszName);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033CFE9
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accValue(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accValue(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszValue)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszValue != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accValue)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszValue);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D029
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accDescription(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accDescription(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszDescription)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszDescription != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accDescription)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszDescription);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D069
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accRole(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        tagVARIANT *pvarRole)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarRole != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))m_pAccessible->get_accRole)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pvarRole);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D0A9
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accState(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        tagVARIANT *pvarState)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarState != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))m_pAccessible->get_accState)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pvarState);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D0E9
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accHelp(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accHelp(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszHelp)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszHelp != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accHelp)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszHelp);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D129
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accHelpTopic(wchar_t __near * __near *,struct tagVARIANT,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accHelpTopic(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        wchar_t **pszHelpFile,
        tagVARIANT varChild,
        int *pidTopic)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszHelpFile != nullptr && pidTopic != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, wchar_t **, _DWORD, unsigned int, unsigned int, unsigned int, int *))m_pAccessible->get_accHelpTopic)(
             a1: m_pAccessible,
             a2: pszHelpFile,
             a3: *(_DWORD *)&varChild.vt,
             a4: varChild.decVal.Hi32,
             a5: varChild.decVal.Lo32,
             a6: varChild.decVal.Mid32,
             a7: pidTopic);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D172
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accKeyboardShortcut(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accKeyboardShortcut(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszKeyboardShortcut)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszKeyboardShortcut != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accKeyboardShortcut)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszKeyboardShortcut);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D1B2
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accFocus(struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accFocus(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT *pvarChild)
{
  if ( this->m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarChild != nullptr )
    return this->m_pAccessible->get_accFocus(this: this->m_pAccessible, a2: pvarChild);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D1E4
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accSelection(struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accSelection(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT *pvarChildren)
{
  if ( this->m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarChildren != nullptr )
    return this->m_pAccessible->get_accSelection(this: this->m_pAccessible, a2: pvarChildren);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D216
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::get_accDefaultAction(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::get_accDefaultAction(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild,
        wchar_t **pszDefaultAction)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pszDefaultAction != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))m_pAccessible->get_accDefaultAction)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32,
             a6: pszDefaultAction);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D256
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::accSelect(long,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::accSelect(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int flagsSelect,
        tagVARIANT varChild)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int))m_pAccessible->accSelect)(
             a1: m_pAccessible,
             a2: flagsSelect,
             a3: *(_DWORD *)&varChild.vt,
             a4: varChild.decVal.Hi32,
             a5: varChild.decVal.Lo32,
             a6: varChild.decVal.Mid32);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D289
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::accLocation(long __near *,long __near *,long __near *,long __near *,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::accLocation(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int *pxLeft,
        int *pyTop,
        int *pcxWidth,
        int *pcyHeight,
        tagVARIANT varChild)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pxLeft != nullptr && pyTop != nullptr && pcxWidth != nullptr && pcyHeight != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, int *, int *, int *, int *, _DWORD, unsigned int, unsigned int, unsigned int))m_pAccessible->accLocation)(
             a1: m_pAccessible,
             a2: pxLeft,
             a3: pyTop,
             a4: pcxWidth,
             a5: pcyHeight,
             a6: *(_DWORD *)&varChild.vt,
             a7: varChild.decVal.Hi32,
             a8: varChild.decVal.Lo32,
             a9: varChild.decVal.Mid32);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D2E2
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::accNavigate(long,struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::accNavigate(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int navDir,
        tagVARIANT varStart,
        tagVARIANT *pvarEndUpAt)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarEndUpAt != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))m_pAccessible->accNavigate)(
             a1: m_pAccessible,
             a2: navDir,
             a3: *(_DWORD *)&varStart.vt,
             a4: varStart.decVal.Hi32,
             a5: varStart.decVal.Lo32,
             a6: varStart.decVal.Mid32,
             a7: pvarEndUpAt);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D325
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::accHitTest(long,long,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::accHitTest(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int xLeft,
        int yTop,
        tagVARIANT *pvarChild)
{
  if ( this->m_pAccessible == nullptr )
    return -2147417848;
  if ( pvarChild != nullptr )
    return this->m_pAccessible->accHitTest(this: this->m_pAccessible, a2: xLeft, a3: yTop, a4: pvarChild);
  return -2147467261;
}

//------------------------------------------------------------------------------
// Address: 0x1033D35D
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::accDoDefaultAction(struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::accDoDefaultAction(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT varChild)
{
  IAccessible *m_pAccessible; // eax

  m_pAccessible = this->m_pAccessible;
  if ( m_pAccessible != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int))m_pAccessible->accDoDefaultAction)(
             a1: m_pAccessible,
             a2: *(_DWORD *)&varChild.vt,
             a3: varChild.decVal.Hi32,
             a4: varChild.decVal.Lo32,
             a5: varChild.decVal.Mid32);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D38D
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::put_accValue(struct tagVARIANT,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::put_accValue(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        tagVARIANT __formal,
        wchar_t *a3)
{
  return this->m_pAccessible != nullptr ? -2147467263 : -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D3AA
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::SetServer(struct IAccessible __near *,struct IAccessibleServer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::SetServer(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        IAccessible *pAccessible,
        IAccessible *pServer)
{
  this->IAccessibleProxy::IUnknown::__vftable = (IAccessibleProxy_vtbl *)pAccessible;
  this->m_pAccessible = pServer;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033D3C4
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::Invoke(long,struct _GUID const __near &,unsigned long,unsigned short,struct tagDISPPARAMS __near *,struct tagVARIANT __near *,struct tagEXCEPINFO __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::Invoke(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        int dispIdMember,
        const _GUID *riid,
        unsigned int lcid,
        int wFlags,
        tagDISPPARAMS *pDispParams,
        tagVARIANT *pVarResult,
        tagEXCEPINFO *pExcepInfo,
        unsigned int *puArgErr)
{
  if ( this->m_pAccessible != nullptr )
    return this->m_pAccessible->Invoke(
             this: this->m_pAccessible,
             a2: dispIdMember,
             a3: riid,
             a4: lcid,
             a5: wFlags,
             a6: pDispParams,
             a7: pVarResult,
             a8: pExcepInfo,
             a9: puArgErr);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D3FE
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::GetIDsOfNames(struct _GUID const __near &,wchar_t __near * __near *,unsigned int,unsigned long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::GetIDsOfNames(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        const _GUID *riid,
        wchar_t **rgszNames,
        unsigned int cNames,
        unsigned int lcid,
        int *rgDispId)
{
  if ( this->m_pAccessible != nullptr )
    return this->m_pAccessible->GetIDsOfNames(
             this: this->m_pAccessible,
             a2: riid,
             a3: rgszNames,
             a4: cNames,
             a5: lcid,
             a6: rgDispId);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D42F
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::GetTypeInfoCount(unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::GetTypeInfoCount(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        unsigned int *pctinfo)
{
  if ( this->m_pAccessible != nullptr )
    return this->m_pAccessible->GetTypeInfoCount(this: this->m_pAccessible, a2: pctinfo);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D454
// Name: public: virtual long ATL::IAccessibleProxyImpl<class ATL::CAccessibleProxy>::GetTypeInfo(unsigned int,unsigned long,struct ITypeInfo __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::GetTypeInfo(
        ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy> *this,
        unsigned int iTInfo,
        unsigned int lcid,
        ITypeInfo **ppTInfo)
{
  if ( this->m_pAccessible != nullptr )
    return this->m_pAccessible->GetTypeInfo(this: this->m_pAccessible, a2: iTInfo, a3: lcid, a4: ppTInfo);
  else
    return -2147417848;
}

//------------------------------------------------------------------------------
// Address: 0x1033D594
// Name: struct HWND__ __near * AfxHtmlHelp(struct HWND__ __near *,char const __near *,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__stdcall AfxHtmlHelp(HWND__ *hWnd, const char *szHelpFilePath, unsigned int nCmd, unsigned int dwData)
{
  CNoTrackObject *Data; // eax
  CNoTrackObject *v5; // esi
  HMODULE LibraryW; // eax
  HWND (__stdcall *HtmlHelpA)(HWND, LPCSTR, UINT, DWORD_PTR); // eax

  AfxLockGlobals(nLockType: 12);
  Data = CProcessLocalObject::GetData(
           this: &_afxHtmlHelpState,
           pfnCreateObject: CProcessLocal<_AFX_HTMLHELP_STATE>::CreateObject);
  v5 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( Data[2].__vftable == nullptr )
  {
    LibraryW = AfxCtxLoadLibraryW(lpLibFileName: L"hhctrl.ocx");
    v5[1].__vftable = (CNoTrackObject_vtbl *)LibraryW;
    if ( LibraryW == nullptr )
      return nullptr;
    HtmlHelpA = (HWND (__stdcall *)(HWND, LPCSTR, UINT, DWORD_PTR))GetProcAddress(
                                                                     hModule: LibraryW,
                                                                     lpProcName: "HtmlHelpA");
    v5[2].__vftable = (CNoTrackObject_vtbl *)HtmlHelpA;
    if ( HtmlHelpA == nullptr )
    {
      FreeLibrary(hLibModule: (HMODULE)v5[1].__vftable);
      v5[1].__vftable = nullptr;
      return nullptr;
    }
  }
  AfxUnlockGlobals(nLockType: 12);
  return ((HWND__ *(__stdcall *)(HWND__ *, const char *, unsigned int, unsigned int))v5[2].__vftable)(
           a1: hWnd,
           a2: szHelpFilePath,
           a3: nCmd,
           a4: dwData);
}

//------------------------------------------------------------------------------
// Address: 0x1033D72F
// Name: struct HWND__ __near * AfxGetParentOwner(struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__stdcall AfxGetParentOwner(HWND__ *hWnd)
{
  CWnd *v1; // eax
  HWND__ *result; // eax

  v1 = CWnd::FromHandlePermanent((CDocument *)hWnd);
  if ( v1 != nullptr )
  {
    result = (HWND__ *)CWnd::GetOwner(this: v1);
    if ( result != nullptr )
      return *((HWND__ **)result + 8);
  }
  else if ( (GetWindowLongA(hWnd, nIndex: -16) & 0x40000000) != 0 )
  {
    return GetParent(hWnd);
  }
  else
  {
    return GetWindow(hWnd, uCmd: 4u);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033D944
// Name: public: CMFCComObject<class ATL::CAccessibleProxy>::CMFCComObject<class ATL::CAccessibleProxy>(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCComObject<ATL::CAccessibleProxy> *__thiscall CMFCComObject<ATL::CAccessibleProxy>::CMFCComObject<ATL::CAccessibleProxy>(
        CMFCComObject<ATL::CAccessibleProxy> *this,
        void *__formal)
{
  this->m_dwRef = 0;
  this->m_pAccessible = nullptr;
  this->m_pAccessibleServer = nullptr;
  this->ATL::CAccessibleProxy::ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::IAccessible::IDispatch::IUnknown::__vftable = (CMFCComObject<ATL::CAccessibleProxy>_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable'{for `IAccessible'};
  this->ATL::CAccessibleProxy::ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::IAccessibleProxy::IUnknown::__vftable = (IAccessibleProxy_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable'{for `IAccessibleProxy'};
  this->ATL::CAccessibleProxy::IOleWindow::IUnknown::__vftable = (IOleWindow_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable';
  AfxOleLockApp();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1033D971
// Name: _InlineIsEqualGUID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl InlineIsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  return rguid1->Data1 == rguid2->Data1
      && *(_DWORD *)&rguid1->Data2 == *(_DWORD *)&rguid2->Data2
      && *(_DWORD *)rguid1->Data4 == *(_DWORD *)rguid2->Data4
      && *(_DWORD *)&rguid1->Data4[4] == *(_DWORD *)&rguid2->Data4[4];
}

//------------------------------------------------------------------------------
// Address: 0x1033D9A3
// Name: public: virtual long ATL::CAccessibleProxy::ContextSensitiveHelp(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::CAccessibleProxy::ContextSensitiveHelp(
        ATL::CAccessibleProxy *this,
        ATL::CAccessibleProxy *__formal)
{
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x1033D9AB
// Name: public: long ATL::CAccessibleProxy::FinalRelease(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CAccessibleProxy::FinalRelease(ATL::CAccessibleProxy *this)
{
  if ( this->m_pAccessibleServer != nullptr )
    return this->m_pAccessibleServer->SetProxy(this: this->m_pAccessibleServer, a2: nullptr);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033EA71
// Name: public: static long CMFCComObject<class ATL::CAccessibleProxy>::CreateInstance(class CMFCComObject<class ATL::CAccessibleProxy> __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CMFCComObject<ATL::CAccessibleProxy>::CreateInstance(CMFCComObject<ATL::CAccessibleProxy> **pp)
{
  CMFCComObject<ATL::CAccessibleProxy> *v2; // eax
  CMFCComObject<ATL::CAccessibleProxy> *v3; // eax
  HRESULT hRes; // [esp+1Ch] [ebp-14h]

  if ( pp == nullptr )
    return -2147467261;
  *pp = nullptr;
  hRes = -2147024882;
  v2 = (CMFCComObject<ATL::CAccessibleProxy> *)operator new(nSize: 0x18u);
  if ( v2 != nullptr )
    v3 = CMFCComObject<ATL::CAccessibleProxy>::CMFCComObject<ATL::CAccessibleProxy>(this: v2, __formal: nullptr);
  else
    v3 = nullptr;
  if ( v3 != nullptr )
    hRes = 0;
  *pp = v3;
  return hRes;
}

//------------------------------------------------------------------------------
// Address: 0x1033ED52
// Name: int AfxRegisterClass(struct tagWNDCLASSA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxRegisterClass(tagWNDCLASSA *lpWndClass)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strUnregisterList; // esi
  tagWNDCLASSA wndcls; // [esp+14h] [ebp-38h] BYREF
  int v4; // [esp+48h] [ebp-4h]

  if ( AfxCtxGetClassInfoA(
         hInstance: lpWndClass->hInstance,
         lpClassName: lpWndClass->lpszClassName,
         lpWndClass: &wndcls) == 0 )
  {
    if ( AfxCtxRegisterClassA(lpWndClass) == 0 )
      return 0;
    if ( AfxGetModuleState()->m_bDLL != 0 )
    {
      AfxLockGlobals(nLockType: 1);
      v4 = 0;
      p_m_strUnregisterList = &AfxGetModuleState()->m_strUnregisterList;
      ATL::CSimpleStringT<char,0>::Append(this: p_m_strUnregisterList, pszSrc: (char *)lpWndClass->lpszClassName);
      ATL::CSimpleStringT<char,0>::AppendChar(this: p_m_strUnregisterList, ch: 10);
      v4 = -1;
      AfxUnlockGlobals(nLockType: 1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033EDE0
// Name: char const __near * AfxRegisterWndClass(unsigned int,struct HICON__ __near *,struct HBRUSH__ __near *,struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__stdcall AfxRegisterWndClass(
        unsigned int nClassStyle,
        HICON__ *hCursor,
        HBRUSH__ *hbrBackground,
        HICON__ *hIcon)
{
  char *m_szTempClassName; // esi
  HINSTANCE__ *m_hCurrentInstanceHandle; // ebx
  int *v6; // eax
  tagWNDCLASSA wndcls; // [esp+Ch] [ebp-2Ch] BYREF
  int _saveErrno; // [esp+34h] [ebp-4h]

  m_szTempClassName = AfxGetThreadState()->m_szTempClassName;
  m_hCurrentInstanceHandle = AfxGetModuleState()->m_hCurrentInstanceHandle;
  if ( hCursor != nullptr || hbrBackground != nullptr || hIcon != nullptr )
  {
    _saveErrno = *_errno();
    *_errno() = 0;
    _snprintf_s(
      string: m_szTempClassName,
      sizeInBytes: 0x60u,
      count: 0x5Fu,
      format: "Afx:%p:%x:%p:%p:%p",
      m_hCurrentInstanceHandle,
      nClassStyle,
      hCursor,
      hbrBackground,
      hIcon);
  }
  else
  {
    _saveErrno = *_errno();
    *_errno() = 0;
    _snprintf_s(
      string: m_szTempClassName,
      sizeInBytes: 0x60u,
      count: 0x5Fu,
      format: "Afx:%p:%x",
      m_hCurrentInstanceHandle,
      nClassStyle);
  }
  if ( *_errno() != 0 )
  {
    v6 = _errno();
    ATL::AtlCrtErrorCheck(nError: *v6);
  }
  else
  {
    *_errno() = _saveErrno;
  }
  if ( AfxCtxGetClassInfoA(hInstance: m_hCurrentInstanceHandle, lpClassName: m_szTempClassName, lpWndClass: &wndcls) == 0 )
  {
    wndcls.style = nClassStyle;
    wndcls.lpfnWndProc = DefWindowProcA;
    wndcls.hIcon = hIcon;
    wndcls.hCursor = hCursor;
    wndcls.hbrBackground = hbrBackground;
    wndcls.cbWndExtra = 0;
    wndcls.cbClsExtra = 0;
    wndcls.hInstance = m_hCurrentInstanceHandle;
    wndcls.lpszMenuName = nullptr;
    wndcls.lpszClassName = m_szTempClassName;
    if ( AfxRegisterClass(lpWndClass: &wndcls) == 0 )
      AfxThrowResourceException();
  }
  return m_szTempClassName;
}

//------------------------------------------------------------------------------
// Address: 0x1033F06F
// Name: int _AfxRegisterWithIcon(struct tagWNDCLASSA __near *,char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxRegisterWithIcon(tagWNDCLASSA *pWndCls, const char *lpszClassName, unsigned __int16 nIDIcon)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HICON__ *IconW; // eax

  pWndCls->lpszClassName = lpszClassName;
  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)nIDIcon);
  pWndCls->hIcon = IconW;
  if ( IconW == nullptr )
    pWndCls->hIcon = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F00);
  return AfxRegisterClass(lpWndClass: pWndCls);
}

//------------------------------------------------------------------------------
// Address: 0x1033F0B3
// Name: int AfxEndDeferRegisterClass(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxEndDeferRegisterClass(int fToRegister)
{
  int v2; // esi
  AFX_MODULE_STATE *v3; // ecx
  tagWNDCLASSA wndcls; // [esp+0h] [ebp-34h] BYREF
  tagINITCOMMONCONTROLSEX init; // [esp+28h] [ebp-Ch] BYREF
  AFX_MODULE_STATE *pModuleState; // [esp+30h] [ebp-4h]
  unsigned int fToRegistera; // [esp+3Ch] [ebp+8h]

  pModuleState = AfxGetModuleState();
  fToRegistera = ~pModuleState->m_fRegisteredClasses & fToRegister;
  if ( fToRegistera == 0 )
    return true;
  v2 = 0;
  memset(dst: (unsigned __int8 *)&wndcls, value: 0, count: sizeof(wndcls));
  wndcls.lpfnWndProc = DefWindowProcA;
  wndcls.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  wndcls.hCursor = afxData.hcurArrow;
  init.dwSize = 8;
  if ( (fToRegistera & 1) != 0 )
  {
    wndcls.style = 11;
    wndcls.lpszClassName = "AfxWnd100s";
    v2 = AfxRegisterClass(lpWndClass: &wndcls) != 0;
  }
  if ( (fToRegistera & 0x20) != 0 )
  {
    wndcls.style |= 0x8Bu;
    wndcls.lpszClassName = "AfxOleControl100s";
    if ( AfxRegisterClass(lpWndClass: &wndcls) != 0 )
      v2 |= 0x20u;
  }
  if ( (fToRegistera & 2) != 0 )
  {
    wndcls.style = 0;
    wndcls.lpszClassName = "AfxControlBar100s";
    wndcls.hbrBackground = (HBRUSH__ *)16;
    if ( AfxRegisterClass(lpWndClass: &wndcls) != 0 )
      v2 |= 2u;
  }
  if ( (fToRegistera & 4) != 0 )
  {
    wndcls.style = 8;
    wndcls.hbrBackground = nullptr;
    if ( _AfxRegisterWithIcon(pWndCls: &wndcls, lpszClassName: "AfxMDIFrame100s", nIDIcon: 0x7A01u) != 0 )
      v2 |= 4u;
  }
  if ( (fToRegistera & 8) != 0 )
  {
    wndcls.style = 11;
    wndcls.hbrBackground = (HBRUSH__ *)6;
    if ( _AfxRegisterWithIcon(pWndCls: &wndcls, lpszClassName: "AfxFrameOrView100s", nIDIcon: 0x7A02u) != 0 )
      v2 |= 8u;
  }
  if ( (fToRegistera & 0x10) != 0 )
  {
    init.dwICC = 255;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 16320);
    fToRegistera &= 0xFFFFC03F;
  }
  if ( (fToRegistera & 0x40) != 0 )
  {
    init.dwICC = 16;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 64);
  }
  if ( (fToRegistera & 0x80u) != 0 )
  {
    init.dwICC = 2;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 128);
  }
  if ( (fToRegistera & 0x100) != 0 )
  {
    init.dwICC = 8;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 256);
  }
  if ( (fToRegistera & 0x200) != 0 )
  {
    init.dwICC = 32;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 512);
  }
  if ( (fToRegistera & 0x400) != 0 )
  {
    init.dwICC = 1;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 1024);
  }
  if ( (fToRegistera & 0x800) != 0 )
  {
    init.dwICC = 64;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 2048);
  }
  if ( (fToRegistera & 0x1000) != 0 )
  {
    init.dwICC = 4;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 4096);
  }
  if ( (fToRegistera & 0x2000) != 0 )
  {
    init.dwICC = 128;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x2000);
  }
  if ( (fToRegistera & 0x4000) != 0 )
  {
    init.dwICC = 2048;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x4000);
  }
  if ( (fToRegistera & 0x8000) != 0 )
  {
    init.dwICC = 1024;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x8000);
  }
  if ( (fToRegistera & 0x10000) != 0 )
  {
    init.dwICC = 512;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x10000);
  }
  if ( (fToRegistera & 0x20000) != 0 )
  {
    init.dwICC = 256;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x20000);
  }
  if ( (fToRegistera & 0x40000) != 0 )
  {
    init.dwICC = 0x8000;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x40000);
  }
  if ( (fToRegistera & 0x80000) != 0 )
  {
    init.dwICC = 4096;
    v2 |= _AfxInitCommonControls(lpInitCtrls: &init, fToRegister: 0x80000);
  }
  v3 = pModuleState;
  pModuleState->m_fRegisteredClasses |= v2;
  if ( (v3->m_fRegisteredClasses & 0x3FC0) == 0x3FC0 )
  {
    v3->m_fRegisteredClasses |= 0x10u;
    v2 |= 0x10u;
  }
  return fToRegistera == (fToRegistera & v2);
}

//------------------------------------------------------------------------------
// Address: 0x1033F93E
// Name: public: virtual struct HACCEL__ __near * CFrameWnd::GetDefaultAccelerator(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HACCEL__ *__thiscall CFrameWnd::GetDefaultAccelerator(CFrameWnd *this)
{
  HACCEL__ *m_hAccelTable; // esi
  CDocument *v2; // eax
  int v3; // eax

  m_hAccelTable = this->m_hAccelTable;
  v2 = this->GetActiveDocument(this);
  if ( v2 != nullptr )
  {
    v3 = (int)v2->GetDefaultAccelerator(this: v2);
    if ( v3 != 0 )
      return (HACCEL__ *)v3;
  }
  return m_hAccelTable;
}

//------------------------------------------------------------------------------
// Address: 0x1033F965
// Name: public: virtual int CFrameWnd::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameWnd::PreTranslateMessage(CFrameWnd *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  BOOL result; // eax
  COleFrameHook *m_pNotifyHook; // ecx
  unsigned int v9; // eax
  HACCEL v10; // eax

  if ( pMsg == nullptr )
    AfxThrowInvalidArgException();
  message = pMsg->message;
  if ( message == 513 || message == 161 )
    AfxCancelModes(hWndRcvr: pMsg->hwnd);
  if ( (this->m_dwMenuBarVisibility & 4) != 0 && pMsg->message == 261 && pMsg->wParam == 121 )
    this->SetMenuBarState(this, a2: 1u);
  if ( (this->m_dwMenuBarVisibility & 2) != 0 )
  {
    v4 = pMsg->message;
    if ( v4 == 261 && pMsg->wParam == 18 )
    {
      this->SetMenuBarState(this, a2: (this->m_dwMenuBarState == 1) + 1);
    }
    else if ( v4 == 262 && this->m_dwMenuBarState == 2 )
    {
      this->SetMenuBarState(this, a2: 1u);
      this->m_bTempShowMenu = 1;
    }
  }
  if ( (this->m_dwMenuBarVisibility & 1) == 0
    && ((v5 = pMsg->message) == 256 && pMsg->wParam == 27
     || v5 == 513
     || v5 == 516
     || (v5 == 161 || v5 == 164) && pMsg->wParam != 5) )
  {
    this->SetMenuBarState(this, a2: 2u);
  }
  v6 = pMsg->message;
  if ( v6 == 161 || v6 == 164 )
  {
    this->m_bMouseHitMenu = pMsg->wParam == 5;
  }
  else if ( v6 == 162 || v6 == 165 || v6 == 514 || v6 == 517 )
  {
    this->m_bMouseHitMenu = 0;
  }
  result = true;
  if ( CWnd::PreTranslateMessage(this, pMsg) == 0 )
  {
    m_pNotifyHook = this->m_pNotifyHook;
    if ( m_pNotifyHook == nullptr || m_pNotifyHook->OnPreTranslateMessage(this: m_pNotifyHook, a2: pMsg) == 0 )
    {
      v9 = pMsg->message;
      if ( v9 < 0x100 )
        return false;
      if ( v9 > 0x109 )
        return false;
      v10 = this->GetDefaultAccelerator(this);
      if ( v10 == nullptr || TranslateAcceleratorA(hWnd: this->m_hWnd, hAccTable: v10, lpMsg: pMsg) == 0 )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033FAF3
// Name: protected: long CFrameWnd::OnHelpHitTest(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CFrameWnd::OnHelpHitTest(CFrameWnd *this, unsigned int __formal, unsigned int __formala)
{
  unsigned int m_nIDHelp; // eax

  m_nIDHelp = this->m_nIDHelp;
  if ( m_nIDHelp != 0 )
    return m_nIDHelp + 0x20000;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033FB09
// Name: int AfxIsDescendant(struct HWND__ __near *,struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__stdcall AfxIsDescendant(HWND__ *hWndParent, HWND__ *hWndChild)
{
  HWND__ *result; // eax

  result = hWndChild;
  while ( hWndParent != result )
  {
    result = AfxGetParentOwner(hWnd: result);
    if ( result == nullptr )
      return result;
  }
  return (HWND__ *)1;
}

//------------------------------------------------------------------------------
// Address: 0x1034000A
// Name: public: void CPushRoutingFrame::Pop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPushRoutingFrame::Pop(CPushRoutingFrame *this)
{
  _AFX_THREAD_STATE *pThreadState; // eax

  pThreadState = this->pThreadState;
  if ( pThreadState == nullptr )
    AfxThrowInvalidArgException();
  pThreadState->m_pRoutingFrame = this->pOldRoutingFrame;
  this->pThreadState->m_pPushRoutingFrame = this->pOldPushRoutingFrame;
  this->pThreadState = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1034002F
// Name: public: class CImageList __near * CToolBarCtrl::GetImageList(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CImageList *__thiscall CToolBarCtrl::GetImageList(CToolBarCtrl *this)
{
  struct _IMAGELIST *v1; // eax

  v1 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x431u, wParam: 0, lParam: 0);
  return CImageList::FromHandle(h: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10340048
// Name: public: int CFrameWnd::LoadAccelTable(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameWnd::LoadAccelTable(CFrameWnd *this, const char *lpszResourceName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HACCEL__ *AcceleratorsA; // eax

  ModuleState = AfxGetModuleState();
  AcceleratorsA = LoadAcceleratorsA(hInstance: ModuleState->m_hCurrentResourceHandle, lpTableName: lpszResourceName);
  this->m_hAccelTable = AcceleratorsA;
  return AcceleratorsA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10340076
// Name: protected: void CFrameWnd::OnPaletteChanged(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnPaletteChanged(CFrameWnd *this, CWnd *pFocusWnd)
{
  CWnd::Default(this);
  if ( this->m_pNotifyHook != nullptr )
    this->m_pNotifyHook->OnPaletteChanged(this: this->m_pNotifyHook, a2: pFocusWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1034009D
// Name: protected: int CFrameWnd::OnQueryNewPalette(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnQueryNewPalette(CFrameWnd *this)
{
  if ( this->m_pNotifyHook != nullptr && this->m_pNotifyHook->OnQueryNewPalette(this: this->m_pNotifyHook) != 0 )
    return 1;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103400C7
// Name: public: virtual void CFrameWnd::ExitHelpMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::ExitHelpMode(CFrameWnd *this)
{
  CFrameWnd *TopLevelFrame; // eax
  tagMSG msg; // [esp+4h] [ebp-1Ch] BYREF

  if ( this->m_bHelpMode != 0 )
  {
    if ( !PeekMessageA(lpMsg: &msg, hWnd: this->m_hWnd, wMsgFilterMin: 0x367u, wMsgFilterMax: 0x367u, wRemoveMsg: 3u) )
      PostMessageA(hWnd: this->m_hWnd, Msg: 0x367u, wParam: 0, lParam: 0);
    if ( GetCapture() == this->m_hWnd )
      ReleaseCapture();
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
    if ( TopLevelFrame == nullptr )
      AfxThrowInvalidArgException();
    this->m_bHelpMode = 0;
    TopLevelFrame->m_bHelpMode = 0;
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10351D0E
// Name: public: void CObList::RemoveAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CObList::RemoveAll(CObList *this)
{
  CPlex *m_pBlocks; // ecx

  m_pBlocks = this->m_pBlocks;
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  CPlex::FreeDataChain(this: m_pBlocks);
  this->m_pBlocks = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10351D30
// Name: protected: void CObList::FreeNode(struct CObList::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CObList::FreeNode(CObList *this, CObList::CNode *pNode)
{
  bool v2; // zf

  if ( pNode == nullptr )
    AfxThrowInvalidArgException();
  pNode->pNext = this->m_pNodeFree;
  v2 = this->m_nCount-- == 1;
  this->m_pNodeFree = pNode;
  if ( v2 )
    CObList::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035886F
// Name: protected: void CFrameWnd::OnHelp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnHelp(CFrameWnd *this)
{
  unsigned int *p_m_dwPromptContext; // esi
  unsigned int m_dwPromptContext; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  p_m_dwPromptContext = &this->m_dwPromptContext;
  m_dwPromptContext = this->m_dwPromptContext;
  if ( m_dwPromptContext != 0 )
  {
    if ( m_dwPromptContext != 258311 )
    {
      ModuleState = AfxGetModuleState();
      ModuleState->m_pCurrentWinApp->WinHelpInternal(
        this: ModuleState->m_pCurrentWinApp,
        a2: *p_m_dwPromptContext,
        a3: 1u);
    }
  }
  else
  {
    CWnd::OnHelp(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103588BA
// Name: public: int CFrameWnd::CanEnterHelpMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CFrameWnd::CanEnterHelpMode(CFrameWnd *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HICON__ *result; // eax
  AFX_CMDHANDLERINFO info; // [esp+4h] [ebp-8h] BYREF

  if ( afxData.hcurHelp != nullptr )
    return (HICON__ *)this->OnCmdMsg(this, a2: 57669u, a3: 0, a4: nullptr, a5: &info);
  afxData.hcurHelp = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F8B);
  if ( afxData.hcurHelp != nullptr )
    return (HICON__ *)this->OnCmdMsg(this, a2: 57669u, a3: 0, a4: nullptr, a5: &info);
  ModuleState = AfxGetModuleState();
  result = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x7901);
  afxData.hcurHelp = result;
  if ( result != nullptr )
    return (HICON__ *)this->OnCmdMsg(this, a2: 57669u, a3: 0, a4: nullptr, a5: &info);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10358917
// Name: protected: struct HWND__ __near * CFrameWnd::SetHelpCapture(struct tagPOINT,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__thiscall CFrameWnd::SetHelpCapture(CFrameWnd *this, tagPOINT point, int *pbDescendant)
{
  DWORD WindowThreadProcessId; // edi
  HWND v5; // eax
  CWnd *v6; // eax
  HWND__ *m_hWnd; // esi
  HWND ActiveWindow; // eax
  CWnd *v9; // eax
  CWnd *TopLevelParent; // ebx
  CWnd *pTopHit; // [esp+4h] [ebp-14h]
  int bDescendant; // [esp+8h] [ebp-10h]
  DWORD hCurTask; // [esp+Ch] [ebp-Ch]
  HWND__ *hWndCapture; // [esp+10h] [ebp-8h]

  WindowThreadProcessId = 0;
  if ( this->m_bHelpMode == 0 )
    return nullptr;
  hWndCapture = GetCapture();
  v5 = WindowFromPoint(Point: point);
  v6 = CWnd::FromHandle(hWnd: v5);
  if ( v6 != nullptr )
    m_hWnd = v6->m_hWnd;
  else
    m_hWnd = nullptr;
  pTopHit = CWnd::GetTopLevelParent(this: v6);
  ActiveWindow = GetActiveWindow();
  v9 = CWnd::FromHandle(hWnd: ActiveWindow);
  TopLevelParent = CWnd::GetTopLevelParent(this: v9);
  bDescendant = 0;
  hCurTask = GetCurrentThreadId();
  if ( m_hWnd != nullptr )
    WindowThreadProcessId = GetWindowThreadProcessId(hWnd: m_hWnd, lpdwProcessId: nullptr);
  if ( TopLevelParent == nullptr || m_hWnd == GetDesktopWindow() )
  {
    if ( hWndCapture == this->m_hWnd )
      ReleaseCapture();
    SetCursor(hCursor: afxData.hcurArrow);
    goto LABEL_25;
  }
  if ( m_hWnd != nullptr )
  {
    if ( hCurTask != WindowThreadProcessId )
    {
LABEL_19:
      m_hWnd = nullptr;
LABEL_20:
      if ( hWndCapture == this->m_hWnd )
        ReleaseCapture();
      goto LABEL_25;
    }
    if ( AfxIsDescendant(hWndParent: this->m_hWnd, hWndChild: m_hWnd) != nullptr )
    {
      bDescendant = 1;
      if ( TopLevelParent == pTopHit )
      {
        if ( hWndCapture != this->m_hWnd )
          SetCapture(hWnd: this->m_hWnd);
        SetCursor(hCursor: afxData.hcurHelp);
      }
      else
      {
        m_hWnd = nullptr;
      }
LABEL_25:
      if ( pbDescendant != nullptr )
        *pbDescendant = bDescendant;
      return m_hWnd;
    }
  }
  if ( hCurTask == WindowThreadProcessId )
    goto LABEL_20;
  goto LABEL_19;
}

//------------------------------------------------------------------------------
// Address: 0x10358A32
// Name: protected: int CFrameWnd::ProcessHelpMsg(struct tagMSG __near &,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::ProcessHelpMsg(CFrameWnd *this, tagMSG *msg, unsigned int *pContext)
{
  tagMSG *v3; // esi
  UINT message; // eax
  HWND__ *v5; // ebx
  LRESULT v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  tagMSG msgCaptured; // [esp+Ch] [ebp-28h] BYREF
  CPoint point; // [esp+28h] [ebp-Ch] BYREF
  CFrameWnd *v12; // [esp+30h] [ebp-4h]

  v3 = msg;
  message = msg->message;
  v12 = this;
  if ( message != 871 && (message != 256 || msg->wParam != 27) )
  {
    point.x = 0;
    point.y = 0;
    if ( (message < 0x200 || message > 0x209) && (message < 0xA0 || message > 0xA9) )
    {
      if ( message == 274 || message >= 0x100 && message <= 0x109 )
      {
        if ( GetCapture() != nullptr )
        {
          ReleaseCapture();
          while ( PeekMessageA(
                    lpMsg: &msgCaptured,
                    hWnd: nullptr,
                    wMsgFilterMin: 0x200u,
                    wMsgFilterMax: 0x209u,
                    wRemoveMsg: 3u) )
            ;
        }
        if ( !PeekMessageA(
                lpMsg: v3,
                hWnd: nullptr,
                wMsgFilterMin: v3->message,
                wMsgFilterMax: v3->message,
                wRemoveMsg: 0) )
          goto LABEL_36;
        GetMessageA(lpMsg: v3, hWnd: nullptr, wMsgFilterMin: v3->message, wMsgFilterMax: v3->message);
        if ( v12->PreTranslateMessage(this: v12, a2: v3) != 0 )
          goto LABEL_36;
        TranslateMessage(lpMsg: v3);
        v9 = v3->message;
        if ( v9 != 274 && (v9 < 0x104 || v9 > 0x107) )
          goto LABEL_36;
        goto LABEL_35;
      }
      if ( !PeekMessageA(lpMsg: msg, hWnd: nullptr, wMsgFilterMin: message, wMsgFilterMax: message, wRemoveMsg: 1u) )
        return 1;
    }
    else
    {
      v5 = CFrameWnd::SetHelpCapture(this: v12, point: msg->pt, pbDescendant: (int *)&msg);
      if ( v5 == nullptr )
        return 1;
      if ( msg != nullptr )
      {
        if ( v3->message != 513 )
        {
          PeekMessageA(lpMsg: v3, hWnd: nullptr, wMsgFilterMin: v3->message, wMsgFilterMax: v3->message, wRemoveMsg: 1u);
          return 1;
        }
        v7 = SendMessageA(hWnd: v5, Msg: 0x84u, wParam: 0, lParam: LOWORD(v3->pt.x) | (LOWORD(v3->pt.y) << 16));
        if ( v7 != 5 && v7 != 3 )
        {
          if ( v7 == 1 )
            v8 = _AfxMapClientArea(hWnd: v5, point: v3->pt);
          else
            v8 = _AfxMapNonClientArea(iHit: v7);
          *pContext = v8;
          PeekMessageA(lpMsg: v3, hWnd: nullptr, wMsgFilterMin: v3->message, wMsgFilterMax: v3->message, wRemoveMsg: 1u);
          return 0;
        }
        ReleaseCapture();
        GetMessageA(lpMsg: v3, hWnd: nullptr, wMsgFilterMin: 0xA1u, wMsgFilterMax: 0xA1u);
LABEL_35:
        DispatchMessageA(lpMsg: v3);
LABEL_36:
        GetCursorPos(lpPoint: &point);
        CFrameWnd::SetHelpCapture(this: v12, point: point.tagPOINT, pbDescendant: nullptr);
        return 1;
      }
      PeekMessageA(lpMsg: v3, hWnd: nullptr, wMsgFilterMin: v3->message, wMsgFilterMax: v3->message, wRemoveMsg: 1u);
    }
    DispatchMessageA(lpMsg: v3);
    return 1;
  }
  PeekMessageA(lpMsg: msg, hWnd: nullptr, wMsgFilterMin: message, wMsgFilterMax: message, wRemoveMsg: 1u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10358C32
// Name: public: void CFrameWnd::OnContextHelp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnContextHelp(CFrameWnd *this)
{
  unsigned int v2; // eax
  COleFrameHook *v3; // ecx
  CWinApp *m_pCurrentWinApp; // edi
  int v5; // eax
  HWND v6; // eax
  COleFrameHook *m_pNotifyHook; // ecx
  tagMSG msg; // [esp+8h] [ebp-34h] BYREF
  tagPOINT point; // [esp+24h] [ebp-18h] BYREF
  CWinApp *pApp; // [esp+2Ch] [ebp-10h]
  unsigned int nMsgSave; // [esp+30h] [ebp-Ch]
  unsigned int dwContext; // [esp+34h] [ebp-8h] BYREF
  int lIdleCount; // [esp+38h] [ebp-4h]

  if ( this->m_bHelpMode != 1
    && CFrameWnd::CanEnterHelpMode(this) != nullptr
    && !PeekMessageA(lpMsg: &msg, hWnd: this->m_hWnd, wMsgFilterMin: 0x367u, wMsgFilterMax: 0x367u, wRemoveMsg: 3u) )
  {
    nMsgSave = this->m_bHelpMode;
    v2 = nMsgSave;
    this->m_bHelpMode = 1;
    if ( v2 == 2 || (v3 = this->m_pNotifyHook) == nullptr || v3->OnContextHelp(this: v3, a2: 1) != 0 )
    {
      if ( nMsgSave != 0 )
      {
        nMsgSave = SendMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam: 0xE002u, lParam: 0);
        if ( nMsgSave == 0 )
          nMsgSave = 57345;
        dwContext = 0;
        GetCursorPos(lpPoint: &point);
        CFrameWnd::SetHelpCapture(this, point, pbDescendant: nullptr);
        lIdleCount = 0;
        m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
        pApp = m_pCurrentWinApp;
        while ( this->m_bHelpMode != 0 )
        {
          if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
          {
            if ( CFrameWnd::ProcessHelpMsg(this, &msg, pContext: &dwContext) == 0 )
              break;
          }
          else
          {
            v5 = m_pCurrentWinApp->OnIdle(this: m_pCurrentWinApp, a2: lIdleCount++);
            if ( v5 == 0 )
            {
              lIdleCount = 0;
              WaitMessage();
            }
          }
        }
        this->m_bHelpMode = 0;
        ReleaseCapture();
        v6 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v6);
        ReleaseCapture();
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam: nMsgSave, lParam: 0);
        m_pNotifyHook = this->m_pNotifyHook;
        if ( m_pNotifyHook != nullptr )
          m_pNotifyHook->OnContextHelp(this: m_pNotifyHook, a2: 0);
        if ( dwContext != 0 )
        {
          if ( dwContext == -1 )
            SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE147u, lParam: 0);
          else
            pApp->WinHelpInternal(this: pApp, a2: dwContext, a3: 1u);
        }
        PostMessageA(hWnd: this->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
      }
      else
      {
        PostMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE145u, lParam: 0);
        this->m_bHelpMode = 2;
      }
    }
    else
    {
      this->m_pNotifyHook->OnContextHelp(this: this->m_pNotifyHook, a2: 0);
      this->m_bHelpMode = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358DFC
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * CFileDialog::GetInterfaceMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall CFileDialog::GetInterfaceMap(CFileDialog *this)
{
  return &CFileDialog::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x10358E02
// Name: public: virtual struct CRuntimeClass __near * CFileDialog::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFileDialog::GetRuntimeClass(CFileDialog *this)
{
  return &CFileDialog::classCFileDialog;
}

//------------------------------------------------------------------------------
// Address: 0x10358E08
// Name: public: struct IFileSaveDialog __near * CFileDialog::GetIFileSaveDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IFileSaveDialog *__thiscall CFileDialog::GetIFileSaveDialog(CFileDialog *this)
{
  IFileSaveDialog *pIFileSaveDialog; // [esp+0h] [ebp-4h] BYREF

  pIFileSaveDialog = nullptr;
  if ( this->m_bVistaStyle == 1 )
    (**(void (__stdcall ***)(void *, GUID *, IFileSaveDialog **))this->m_pIFileDialog)(
      a1: this->m_pIFileDialog,
      a2: &_GUID_84bccd23_5fde_4cdb_aea4_af64b83d78ab,
      a3: &pIFileSaveDialog);
  return pIFileSaveDialog;
}

//------------------------------------------------------------------------------
// Address: 0x10358E34
// Name: public: virtual unsigned long CFileDialog::XFileDialogEvents::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CFileDialog::XFileDialogEvents::AddRef(CFileDialog::XFileDialogEvents *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 127));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10358E69
// Name: public: virtual unsigned long CFileDialog::XFileDialogEvents::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CFileDialog::XFileDialogEvents::Release(CFileDialog::XFileDialogEvents *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 127));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10358E9E
// Name: public: virtual long CFileDialog::XFileDialogEvents::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::QueryInterface(
        CFileDialog::XFileDialogEvents *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 127), iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x10358ED9
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnFileOk(struct IFileDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CFileDialog::XFileDialogEvents::OnFileOk(CFileDialog::XFileDialogEvents *this, IFileDialog *__formal)
{
  BOOL v3; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  (*(void (__thiscall **)(CFileDialog::XFileDialogEvents *))(*((_DWORD *)this - 127) + 392))(a1: this - 127);
  v3 = (*(int (__thiscall **)(CFileDialog::XFileDialogEvents *))(*((_DWORD *)this - 127) + 400))(a1: this - 127) != 0;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10358F2B
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnFolderChange(struct IFileDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnFolderChange(
        CFileDialog::XFileDialogEvents *this,
        IFileDialog *__formal)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  (*(void (__thiscall **)(CFileDialog::XFileDialogEvents *))(*((_DWORD *)this - 127) + 416))(a1: this - 127);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10358F65
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnFolderChanging(struct IFileDialog __near *,struct IShellItem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnFolderChanging(
        CFileDialog::XFileDialogEvents *this,
        IFileDialog *__formal,
        IShellItem *a3)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10358F8B
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnHelp(struct IFileDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnHelp(CFileDialog::XFileDialogEvents *this, IFileDialog *__formal)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10358FB1
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnSelectionChange(struct IFileDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnSelectionChange(
        CFileDialog::XFileDialogEvents *this,
        IFileDialog *__formal)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  (*(void (__thiscall **)(CFileDialog::XFileDialogEvents *))(*((_DWORD *)this - 127) + 412))(a1: this - 127);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10358FEB
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnTypeChange(struct IFileDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnTypeChange(
        CFileDialog::XFileDialogEvents *this,
        IFileDialog *__formal)
{
  CFileDialog::XFileDialogEvents *v2; // esi
  CFileDialog::XFileDialogEvents_vtbl *v3; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  v2 = this;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  v3 = v2[-86].__vftable;
  this = nullptr;
  (*((void (__stdcall **)(CFileDialog::XFileDialogEvents_vtbl *, CFileDialog::XFileDialogEvents **))v3->QueryInterface
   + 6))(
    a1: v3,
    a2: &this);
  v2[-90].OnSelectionChange = (HRESULT (__stdcall *)(IFileDialogEvents *, IFileDialog *))this;
  ((void (__thiscall *)(CFileDialog::XFileDialogEvents *))v2[-127].__vftable[9].OnSelectionChange)(a1: &v2[-127]);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10359045
// Name: public: virtual long CFileDialog::XFileDialogEvents::OnOverwrite(struct IFileDialog __near *,struct IShellItem __near *,enum tagFDE_OVERWRITE_RESPONSE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogEvents::OnOverwrite(
        CFileDialog::XFileDialogEvents *this,
        IFileDialog *__formal,
        IShellItem *a3,
        tagFDE_OVERWRITE_RESPONSE *a4)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 120));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035906B
// Name: public: virtual unsigned long CFileDialog::XFileDialogControlEvents::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CFileDialog::XFileDialogControlEvents::AddRef(CFileDialog::XFileDialogControlEvents *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)this - 16);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x103590A0
// Name: public: virtual unsigned long CFileDialog::XFileDialogControlEvents::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CFileDialog::XFileDialogControlEvents::Release(CFileDialog::XFileDialogControlEvents *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)this - 16);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x103590D5
// Name: public: virtual long CFileDialog::XFileDialogControlEvents::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogControlEvents::QueryInterface(
        CFileDialog::XFileDialogControlEvents *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  if ( ppvObj == nullptr )
    AfxThrowInvalidArgException();
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)this - 16, iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x1035911B
// Name: public: virtual long CFileDialog::XFileDialogControlEvents::OnItemSelected(struct IFileDialogCustomize __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogControlEvents::OnItemSelected(
        CFileDialog::XFileDialogControlEvents *this,
        IFileDialogCustomize *__formal,
        unsigned int dwIDCtl,
        unsigned int dwIDItem)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  (*(void (__thiscall **)(CFileDialog::XFileDialogControlEvents *, unsigned int, unsigned int))(*((_DWORD *)this - 128)
                                                                                              + 424))(
    a1: this - 128,
    a2: dwIDCtl,
    a3: dwIDItem);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035915B
// Name: public: virtual long CFileDialog::XFileDialogControlEvents::OnButtonClicked(struct IFileDialogCustomize __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogControlEvents::OnButtonClicked(
        CFileDialog::XFileDialogControlEvents *this,
        IFileDialogCustomize *__formal,
        unsigned int dwIDCtl)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  (*(void (__thiscall **)(CFileDialog::XFileDialogControlEvents *, unsigned int))(*((_DWORD *)this - 128) + 428))(
    a1: this - 128,
    a2: dwIDCtl);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10359198
// Name: public: virtual long CFileDialog::XFileDialogControlEvents::OnCheckButtonToggled(struct IFileDialogCustomize __near *,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogControlEvents::OnCheckButtonToggled(
        CFileDialog::XFileDialogControlEvents *this,
        IFileDialogCustomize *__formal,
        unsigned int dwIDCtl,
        int bChecked)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  (*(void (__thiscall **)(CFileDialog::XFileDialogControlEvents *, unsigned int, int))(*((_DWORD *)this - 128) + 432))(
    a1: this - 128,
    a2: dwIDCtl,
    a3: bChecked);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103591D8
// Name: public: virtual long CFileDialog::XFileDialogControlEvents::OnControlActivating(struct IFileDialogCustomize __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CFileDialog::XFileDialogControlEvents::OnControlActivating(
        CFileDialog::XFileDialogControlEvents *this,
        IFileDialogCustomize *__formal,
        unsigned int dwIDCtl)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 121));
  (*(void (__thiscall **)(CFileDialog::XFileDialogControlEvents *, unsigned int))(*((_DWORD *)this - 128) + 436))(
    a1: this - 128,
    a2: dwIDCtl);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10359215
// Name: protected: virtual void CFileDialog::OnInitDone(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFileDialog::OnInitDone(CFileDialog *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  CWnd::CenterWindow(this: v2, pAlternateOwner: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1035922E
// Name: protected: virtual int CFileDialog::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFileDialog::OnNotify(CFileDialog *this, unsigned int wParam, int lParam, int *pResult)
{
  int v5; // eax
  int v7; // eax

  if ( CWnd::OnNotify(this, __formal: wParam, (tagNMHDR *)lParam, pResult) != 0 )
    return 1;
  v5 = *(_DWORD *)(lParam + 8);
  switch ( v5 )
  {
    case -607:
      this->OnTypeChange(this);
      return 1;
    case -606:
      v7 = this->OnFileNameOK(this);
      goto LABEL_14;
    case -605:
      if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0) == 0 )
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x365u, wParam: 0, lParam: 0);
      return 1;
    case -604:
      v7 = this->OnShareViolation(this, a2: *(const char **)(lParam + 16));
LABEL_14:
      *pResult = v7;
      return 1;
    case -603:
      this->OnFolderChange(this);
      break;
    case -602:
      this->OnFileNameChange(this);
      break;
    case -601:
      this->OnInitDone(this);
      break;
    default:
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103723D9
// Name: public: void CToolTipCtrl::GetText(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,class CWnd __near *,unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::GetText(
        CToolTipCtrl *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str,
        CWnd *pWnd,
        unsigned int nIDTool)
{
  int v5; // eax
  tagTOOLINFOA ti; // [esp+10h] [ebp-3Ch] BYREF
  char _OverrunDetector[5]; // [esp+40h] [ebp-Ch] BYREF

  CToolTipCtrl::FillInToolInfo(this, &ti, pWnd, nIDTool);
  *(_DWORD *)_OverrunDetector = *(_DWORD *)"M";
  _OverrunDetector[4] = aFc[2];
  ti.lpszText = ATL::CSimpleStringT<char,0>::PrepareWrite(this: str, nLength: 1029);
  memset(dst: (unsigned __int8 *)ti.lpszText, value: 0, count: 0x400u);
  v5 = memcpy_s(dst: ti.lpszText + 1024, sizeInBytes: 5u, src: _OverrunDetector, count: 5u);
  AfxCrtErrorCheck(error: v5);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x40Bu, wParam: 0, lParam: (LPARAM)&ti);
  if ( memcmp(lhs: _OverrunDetector, rhs: ti.lpszText + 1024, siz: 5u) != 0 )
    AfxThrowMemoryException();
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: str, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1037255E
// Name: public: void COleServerDoc::RequestPositionChange(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleServerDoc::RequestPositionChange(COleServerDoc *this, const tagRECT *lpPosRect)
{
  IUnknown *Interface; // eax
  IUnknown *v3; // esi

  Interface = _AfxQueryInterface(lpUnknown: this->m_lpClientSite, iid: &IID_IOleInPlaceSite);
  v3 = Interface;
  if ( Interface != nullptr )
  {
    ((void (__stdcall *)(IUnknown *, const tagRECT *))Interface->__vftable[4].Release)(a1: Interface, a2: lpPosRect);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037258E
// Name: public: COleDataObject::~COleDataObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COleDataObject::~COleDataObject(COleDataObject *this)
{
  COleDataObject::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10372593
// Name: public: COleCntrFrameWnd::COleCntrFrameWnd(class COleIPFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleCntrFrameWnd *__thiscall COleCntrFrameWnd::COleCntrFrameWnd(COleCntrFrameWnd *this, COleIPFrameWnd *pInPlaceFrame)
{
  CFrameWnd::CFrameWnd(this);
  this->__vftable = (COleCntrFrameWnd_vtbl *)&COleCntrFrameWnd::`vftable';
  this->m_pInPlaceFrame = pInPlaceFrame;
  CFrameWnd::RemoveFrameWnd(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103725CD
// Name: public: virtual void COleCntrFrameWnd::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWnd::RecalcLayout(COleCntrFrameWnd *this, int __formal)
{
  COleIPFrameWnd *m_pInPlaceFrame; // ecx
  int v4; // edi
  CWinThread *Thread; // eax
  COleIPFrameWnd *v6; // ecx
  COleIPFrameWnd *v7; // eax

  if ( this->m_bInRecalcLayout == 0 )
  {
    m_pInPlaceFrame = this->m_pInPlaceFrame;
    this->m_nIdleFlags &= 0xFFFFFFF3;
    this->m_bInRecalcLayout = 1;
    v4 = (int)m_pInPlaceFrame->GetActiveDocument(this: m_pInPlaceFrame);
    Thread = AfxGetThread();
    if ( Thread == nullptr )
      AfxThrowInvalidArgException();
    if ( v4 != 0 )
    {
      v6 = this->m_pInPlaceFrame;
      if ( Thread->m_pActiveWnd == v6 )
      {
        if ( this == v6->m_pMainFrame )
          (*(void (__thiscall **)(int, _DWORD, IOleInPlaceFrame *, int))(*(_DWORD *)v4 + 396))(
            a1: v4,
            a2: 0,
            a3: v6->m_lpFrame,
            a4: 1);
        v7 = this->m_pInPlaceFrame;
        if ( this == v7->m_pDocFrame )
          (*(void (__thiscall **)(int, _DWORD, IOleInPlaceUIWindow *, _DWORD))(*(_DWORD *)v4 + 396))(
            a1: v4,
            a2: 0,
            a3: v7->m_lpDocFrame,
            a4: 0);
      }
    }
    this->m_bInRecalcLayout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10372668
// Name: public: virtual COleIPFrameWnd::~COleIPFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::~COleIPFrameWnd(COleIPFrameWnd *this)
{
  COleCntrFrameWnd *m_pMainFrame; // ecx
  COleCntrFrameWnd *m_pDocFrame; // ecx

  this->__vftable = (COleIPFrameWnd_vtbl *)&COleIPFrameWnd::`vftable';
  m_pMainFrame = this->m_pMainFrame;
  if ( m_pMainFrame != nullptr )
    ((void (__thiscall *)(COleCntrFrameWnd *, int))m_pMainFrame->dtr_CObject)(a1: m_pMainFrame, a2: 1);
  m_pDocFrame = this->m_pDocFrame;
  if ( m_pDocFrame != nullptr )
    ((void (__thiscall *)(COleCntrFrameWnd *, int))m_pDocFrame->dtr_CObject)(a1: m_pDocFrame, a2: 1);
  if ( this->m_hSharedMenu != nullptr )
    DestroyMenu(hMenu: this->m_hSharedMenu);
  _AfxRelease(lplpUnknown: &this->m_lpFrame);
  _AfxRelease(lplpUnknown: &this->m_lpDocFrame);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103726DF
// Name: protected: int COleIPFrameWnd::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::OnCreate(COleIPFrameWnd *this, tagCREATESTRUCTA *lpCreateStruct)
{
  tagMSG msg; // [esp+4h] [ebp-1Ch] BYREF

  if ( CFrameWnd::OnCreate(this, lpcs: lpCreateStruct) < 0 )
    return -1;
  CWnd::ModifyStyleEx(this, dwRemove: 0x200u, dwAdd: 0, nFlags: 0);
  PeekMessageA(lpMsg: &msg, hWnd: this->m_hWnd, wMsgFilterMin: 0x362u, wMsgFilterMax: 0x362u, wRemoveMsg: 3u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10372728
// Name: protected: void COleIPFrameWnd::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::OnDestroy(COleIPFrameWnd *this)
{
  CDocument *v2; // eax
  CDocument *v3; // edi
  COleCntrFrameWnd *m_pMainFrame; // ecx
  COleCntrFrameWnd *m_pDocFrame; // ecx

  v2 = this->GetActiveDocument(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CDocument::DisconnectViews(this: v2);
    v3->OnCloseDocument(this: v3);
  }
  m_pMainFrame = this->m_pMainFrame;
  if ( m_pMainFrame != nullptr )
    CFrameWnd::DestroyDockBars(this: m_pMainFrame);
  m_pDocFrame = this->m_pDocFrame;
  if ( m_pDocFrame != nullptr )
    CFrameWnd::DestroyDockBars(this: m_pDocFrame);
  CFrameWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10372774
// Name: public: virtual int COleIPFrameWnd::OnCreateControlBars(class CFrameWnd __near *,class CFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::OnCreateControlBars(COleIPFrameWnd *this, CFrameWnd *pWndFrame, CFrameWnd *pWndDoc)
{
  return this->OnCreateControlBars(this, a2: pWndFrame, a3: pWndDoc);
}

//------------------------------------------------------------------------------
// Address: 0x10372782
// Name: protected: long COleIPFrameWnd::OnRecalcParent(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::OnRecalcParent(COleIPFrameWnd *this, unsigned int __formal, int *lParam)
{
  CRect *p_m_rectPos; // esi
  int *p_top; // esi

  p_m_rectPos = &this->m_rectPos;
  ((void (__stdcall *)(CRect *, CRect *))this->RepositionFrame)(a1: &this->m_rectPos, a2: &this->m_rectClip);
  if ( lParam != nullptr )
  {
    *lParam = p_m_rectPos->left;
    p_top = &p_m_rectPos->top;
    lParam[1] = *p_top++;
    lParam[2] = *p_top;
    lParam[3] = p_top[1];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103727B3
// Name: public: virtual int COleIPFrameWnd::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall COleIPFrameWnd::PreTranslateMessage(COleIPFrameWnd *this, tagMSG *pMsg)
{
  BOOL result; // eax
  unsigned int message; // eax
  HACCEL v5; // esi
  int v6; // eax
  IOleInPlaceFrame *m_lpFrame; // [esp-10h] [ebp-2Ch]
  tagOIFI frameInfo; // [esp+8h] [ebp-14h] BYREF

  if ( CFrameWnd::PreTranslateMessage(this, pMsg) )
    return 1;
  message = pMsg->message;
  result = false;
  if ( message >= 0x100 && message <= 0x109 )
  {
    v5 = this->GetDefaultAccelerator(this);
    if ( v5 != nullptr )
    {
      v6 = CopyAcceleratorTableA(hAccelSrc: v5, lpAccelDst: nullptr, cAccelEntries: 0);
      if ( IsAccelerator(hAccel: v5, cAccelEntries: v6, lpMsg: pMsg, lpwCmd: nullptr) )
        return true;
    }
    m_lpFrame = this->m_lpFrame;
    frameInfo = this->m_frameInfo;
    if ( OleTranslateAccelerator(lpFrame: m_lpFrame, lpFrameInfo: &frameInfo, lpmsg: pMsg) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037283F
// Name: protected: int COleIPFrameWnd::OnBarCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::OnBarCheck(COleIPFrameWnd *this, unsigned int nID)
{
  CFrameWnd *v3; // ecx
  COleCntrFrameWnd *m_pMainFrame; // ecx
  COleCntrFrameWnd *m_pDocFrame; // ecx

  if ( CFrameWnd::GetControlBar(this, nID) != nullptr )
  {
    v3 = this;
    return CFrameWnd::OnBarCheck(this: v3, nID);
  }
  m_pMainFrame = this->m_pMainFrame;
  if ( m_pMainFrame != nullptr && CFrameWnd::GetControlBar(this: m_pMainFrame, nID) != nullptr )
  {
    v3 = this->m_pMainFrame;
    return CFrameWnd::OnBarCheck(this: v3, nID);
  }
  m_pDocFrame = this->m_pDocFrame;
  if ( m_pDocFrame != nullptr && CFrameWnd::GetControlBar(this: m_pDocFrame, nID) != nullptr )
  {
    v3 = this->m_pDocFrame;
    return CFrameWnd::OnBarCheck(this: v3, nID);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037289F
// Name: protected: virtual int COleIPFrameWnd::BuildSharedMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU__ *__thiscall COleIPFrameWnd::BuildSharedMenu(COleIPFrameWnd *this)
{
  HMENU__ *result; // eax
  HMENU__ *v3; // eax
  HOLEMENU MenuDescriptor; // eax
  HMENU__ *m_hSharedMenu; // [esp-Ch] [ebp-14h]
  HMENU__ *hMenu; // [esp+4h] [ebp-4h]

  hMenu = this->GetInPlaceMenu(this);
  result = CreateMenu();
  this->m_hSharedMenu = result;
  if ( result != nullptr )
  {
    memset(dst: (unsigned __int8 *)&this->m_menuWidths, value: 0, count: sizeof(this->m_menuWidths));
    if ( this->m_lpFrame->InsertMenus(this: this->m_lpFrame, a2: this->m_hSharedMenu, a3: &this->m_menuWidths) != 0 )
    {
      DestroyMenu(hMenu: this->m_hSharedMenu);
      this->m_hSharedMenu = nullptr;
      return nullptr;
    }
    else if ( hMenu != nullptr )
    {
      v3 = AfxMergeMenus(
             hMenuShared: this->m_hSharedMenu,
             hMenuSource: hMenu,
             lpMenuWidths: (UINT *)&this->m_menuWidths,
             iWidthIndex: 1,
             bMergeHelpMenus: this->m_menuWidths.width[5] != 0);
      m_hSharedMenu = this->m_hSharedMenu;
      this->m_hMenuHelpPopup = v3;
      MenuDescriptor = OleCreateMenuDescriptor(hmenuCombined: m_hSharedMenu, lpMenuWidths: &this->m_menuWidths);
      this->m_hOleMenu = MenuDescriptor;
      return (HMENU__ *)(MenuDescriptor != nullptr);
    }
    else
    {
      return (HMENU__ *)1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10372956
// Name: protected: virtual void COleIPFrameWnd::DestroySharedMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::DestroySharedMenu(COleDocIPFrameWnd *this)
{
  HMENU__ *v2; // eax
  void *m_hOleMenu; // eax

  if ( this->m_hSharedMenu != nullptr )
  {
    v2 = this->GetInPlaceMenu(this);
    if ( v2 != nullptr )
    {
      AfxUnmergeMenus(hMenuShared: this->m_hSharedMenu, hMenuSource: v2, hHelpMenuPopup: this->m_hMenuHelpPopup);
      this->m_lpFrame->RemoveMenus(this: this->m_lpFrame, a2: this->m_hSharedMenu);
      DestroyMenu(hMenu: this->m_hSharedMenu);
      m_hOleMenu = this->m_hOleMenu;
      this->m_hSharedMenu = nullptr;
      if ( m_hOleMenu != nullptr )
      {
        OleDestroyMenuDescriptor(holemenu: m_hOleMenu);
        this->m_hOleMenu = nullptr;
      }
      this->m_hMenuHelpPopup = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103729CA
// Name: public: virtual struct CRuntimeClass __near * COleIPFrameWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COleIPFrameWnd::GetRuntimeClass(COleIPFrameWnd *this)
{
  return &COleIPFrameWnd::classCOleIPFrameWnd;
}

//------------------------------------------------------------------------------
// Address: 0x103729D8
// Name: public: void COleCntrFrameWnd::OnIdleUpdateCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWnd::OnIdleUpdateCmdUI(COleCntrFrameWnd *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void *data; // eax

  if ( (this->m_nIdleFlags & 8) != 0 )
    this->RecalcLayout(this, a2: this->m_nIdleFlags & 4);
  m_pNodeHead = this->m_listControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    AfxCallWndProc(
      pWnd: (CWnd *)data,
      hWnd: *((CNoTrackObject_vtbl **)data + 8),
      nMsg: (CNoTrackObject_vtbl *)0x363,
      wParam: (CNoTrackObject_vtbl *)1,
      lParam: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10372A24
// Name: public: virtual int COleCntrFrameWnd::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWnd::OnCmdMsg(
        COleCntrFrameWnd *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  COleIPFrameWnd *m_pInPlaceFrame; // ecx
  COleIPFrameWnd_vtbl *v7; // eax
  int v8; // esi
  CPushRoutingFrame push; // [esp+10h] [ebp-18h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  CPushRoutingFrame::CPushRoutingFrame(this: &push, pNewRoutingFrame: this);
  m_pInPlaceFrame = this->m_pInPlaceFrame;
  v7 = m_pInPlaceFrame->__vftable;
  v11 = 0;
  v8 = v7->OnCmdMsg(this: m_pInPlaceFrame, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo);
  CPushRoutingFrame::~CPushRoutingFrame(this: &push);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10372A6A
// Name: public: COleIPFrameWnd::COleIPFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleIPFrameWnd *__thiscall COleIPFrameWnd::COleIPFrameWnd(COleIPFrameWnd *this)
{
  CFrameWnd::CFrameWnd(this);
  this->__vftable = (COleIPFrameWnd_vtbl *)&COleIPFrameWnd::`vftable';
  this->m_rectPos.left = 0;
  this->m_rectPos.top = 0;
  this->m_rectPos.right = 0;
  this->m_rectPos.bottom = 0;
  this->m_rectClip.left = 0;
  this->m_rectClip.top = 0;
  this->m_rectClip.right = 0;
  this->m_rectClip.bottom = 0;
  memset(dst: (unsigned __int8 *)&this->m_frameInfo, value: 0, count: sizeof(this->m_frameInfo));
  this->m_frameInfo.cb = 20;
  this->m_bUIActive = 0;
  this->m_lpFrame = nullptr;
  this->m_lpDocFrame = nullptr;
  this->m_hOleMenu = nullptr;
  SetRectEmpty(lprc: &this->m_rectPos);
  SetRectEmpty(lprc: &this->m_rectClip);
  this->m_bInsideRecalc = 0;
  this->m_hSharedMenu = nullptr;
  this->m_pMainFrame = nullptr;
  this->m_pDocFrame = nullptr;
  this->m_bPreviewMode = 0;
  this->m_hMenuHelpPopup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10372B38
// Name: protected: void COleIPFrameWnd::OnIdleUpdateCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::OnIdleUpdateCmdUI(COleIPFrameWnd *this)
{
  COleCntrFrameWnd *m_pMainFrame; // ecx
  COleCntrFrameWnd *m_pDocFrame; // ecx

  m_pMainFrame = this->m_pMainFrame;
  if ( m_pMainFrame != nullptr )
    COleCntrFrameWnd::OnIdleUpdateCmdUI(this: m_pMainFrame);
  m_pDocFrame = this->m_pDocFrame;
  if ( m_pDocFrame != nullptr )
    COleCntrFrameWnd::OnIdleUpdateCmdUI(this: m_pDocFrame);
}

//------------------------------------------------------------------------------
// Address: 0x10372B5D
// Name: protected: void COleIPFrameWnd::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::OnWindowPosChanging(COleIPFrameWnd *this, tagWINDOWPOS *lpWndPos)
{
  DWORD CurrentThreadId; // eax
  tagMSG msg; // [esp+8h] [ebp-1Ch] BYREF

  if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0x36Au, wMsgFilterMax: 0x36Au, wRemoveMsg: 0) )
  {
    CurrentThreadId = GetCurrentThreadId();
    PostThreadMessageA(idThread: CurrentThreadId, Msg: 0x36Au, wParam: 0, lParam: 0);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10372B9F
// Name: public: virtual int COleIPFrameWnd::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::LoadFrame(
        COleIPFrameWnd *this,
        HMENU__ *nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  int result; // eax
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  this->m_nIDHelp = (unsigned int)nIDResource;
  memset(&rect, 0, sizeof(rect));
  result = CWnd::Create(
             this,
             lpszClassName: nullptr,
             lpszWindowName: nullptr,
             dwStyle: dwDefaultStyle,
             &rect,
             pParentWnd,
             nID: nIDResource,
             pContext);
  if ( result != 0 )
  {
    CFrameWnd::LoadAccelTable(this, lpszResourceName: (const char *)(unsigned __int16)nIDResource);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10372C07
// Name: protected: long COleIPFrameWnd::OnResizeChild(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWnd::OnResizeChild(COleIPFrameWnd *this, unsigned int __formal, const RECT *lParam)
{
  HWND Parent; // eax
  CWnd *v5; // esi
  CWnd *DlgItem; // eax
  CRect rectCur; // [esp+8h] [ebp-24h] BYREF
  CRect rectNew; // [esp+18h] [ebp-14h] BYREF

  if ( this->GetActiveDocument(this) != nullptr )
  {
    memset(&rectNew, 0, sizeof(rectNew));
    CopyRect(lprcDst: &rectNew, lprcSrc: lParam);
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rectNew);
    CWnd::ScreenToClient(this: v5, lpRect: (tagPOINT *)&rectNew);
    DlgItem = CWnd::GetDlgItem(this, nID: 59648);
    rectCur = this->m_rectPos;
    DlgItem->CalcWindowRect(this: DlgItem, a2: &rectCur, a3: 1u);
    rectNew.left += this->m_rectPos.left - rectCur.left;
    rectNew.top += this->m_rectPos.top - rectCur.top;
    rectNew.right += this->m_rectPos.right - rectCur.right;
    rectNew.bottom += this->m_rectPos.bottom - rectCur.bottom;
    this->OnRequestPositionChange(this, a2: &rectNew);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10372CE8
// Name: public: virtual void COleIPFrameWnd::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::RecalcLayout(COleIPFrameWnd *this, int __formal)
{
  HWND Parent; // eax
  CDocument *v4; // eax
  CWnd *DlgItem; // eax
  CWnd *pParentWnd; // [esp+Ch] [ebp-4Ch]
  BOOL nAdjustType; // [esp+10h] [ebp-48h]
  CRect rectVis; // [esp+14h] [ebp-44h] BYREF
  CRect rectLeft; // [esp+24h] [ebp-34h] BYREF
  CRect rectBig; // [esp+34h] [ebp-24h] BYREF
  CRect rect; // [esp+44h] [ebp-14h] BYREF

  Parent = GetParent(hWnd: this->m_hWnd);
  pParentWnd = CWnd::FromHandle(hWnd: Parent);
  nAdjustType = false;
  v4 = this->GetActiveDocument(this);
  if ( v4 != nullptr )
    nAdjustType = v4[1].m_lstChunks.m_nCount != 0;
  rectBig.right = 0x3FFFFFFF;
  rectBig.bottom = 0x3FFFFFFF;
  rectBig.left = 0;
  rectBig.top = 0;
  memset(&rectLeft, 0, sizeof(rectLeft));
  CWnd::RepositionBars(
    this,
    nIDFirst: 0,
    nIDLast: 0xFFFFu,
    nIDLeftOver: 0xE900u,
    nFlags: 1u,
    lpRectParam: &rectLeft,
    lpRectClient: &rectBig,
    bStretch: 1);
  rect = this->m_rectPos;
  rect.left -= rectLeft.left;
  rect.top -= rectLeft.top;
  rect.right += 0x3FFFFFFF - rectLeft.right;
  rect.bottom += 0x3FFFFFFF - rectLeft.bottom;
  DlgItem = CWnd::GetDlgItem(this, nID: 59648);
  if ( DlgItem != nullptr )
  {
    rectBig = this->m_rectPos;
    DlgItem->CalcWindowRect(this: DlgItem, a2: &rectBig, a3: 1u);
    rect.left += rectBig.left - this->m_rectPos.left;
    rect.top += rectBig.top - this->m_rectPos.top;
    rect.right += rectBig.right - this->m_rectPos.right;
    rect.bottom += rectBig.bottom - this->m_rectPos.bottom;
  }
  this->CalcWindowRect(this, a2: &rect, a3: nAdjustType);
  memset(&rectVis, 0, sizeof(rectVis));
  IntersectRect(lprcDst: &rectVis, lprcSrc1: &rect, lprcSrc2: &this->m_rectClip);
  AfxRepositionWindow(lpLayout: nullptr, hWnd: this->m_hWnd, lpRect: &rectVis);
  CWnd::ClientToScreen(this: pParentWnd, lpRect: (tagPOINT *)&rect);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rect);
  CWnd::RepositionBars(
    this,
    nIDFirst: 0,
    nIDLast: 0xFFFFu,
    nIDLeftOver: 0xE900u,
    nFlags: 0,
    lpRectParam: nullptr,
    lpRectClient: &rect,
    bStretch: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10372E76
// Name: public: virtual void COleIPFrameWnd::RepositionFrame(struct tagRECT const __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::RepositionFrame(
        COleIPFrameWnd *this,
        const tagRECT *lpPosRect,
        const tagRECT *lpClipRect)
{
  if ( this->m_bInsideRecalc == 0 )
  {
    this->m_bInsideRecalc = 1;
    CopyRect(lprcDst: &this->m_rectPos, lprcSrc: lpPosRect);
    CopyRect(lprcDst: &this->m_rectClip, lprcSrc: lpClipRect);
    this->RecalcLayout(this, a2: 1);
    this->m_bInsideRecalc = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10372EC9
// Name: protected: void COleIPFrameWnd::OnUpdateControlBarMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWnd::OnUpdateControlBarMenu(COleIPFrameWnd *this, CCmdUI *pCmdUI)
{
  CFrameWnd *v3; // ecx
  COleCntrFrameWnd *m_pMainFrame; // ecx
  COleCntrFrameWnd *m_pDocFrame; // ecx

  if ( CFrameWnd::GetControlBar(this, nID: pCmdUI->m_nID) != nullptr )
  {
    v3 = this;
LABEL_9:
    CFrameWnd::OnUpdateControlBarMenu(this: v3, pCmdUI);
    return;
  }
  m_pMainFrame = this->m_pMainFrame;
  if ( m_pMainFrame != nullptr && CFrameWnd::GetControlBar(this: m_pMainFrame, nID: pCmdUI->m_nID) != nullptr )
  {
    v3 = this->m_pMainFrame;
    goto LABEL_9;
  }
  m_pDocFrame = this->m_pDocFrame;
  if ( m_pDocFrame != nullptr && CFrameWnd::GetControlBar(this: m_pDocFrame, nID: pCmdUI->m_nID) != nullptr )
  {
    v3 = this->m_pDocFrame;
    goto LABEL_9;
  }
  pCmdUI->m_bContinueRouting = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10372F34
// Name: protected: virtual struct HMENU__ __near * COleIPFrameWnd::GetInPlaceMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU__ *__thiscall COleIPFrameWnd::GetInPlaceMenu(COleIPFrameWnd *this)
{
  return this->GetActiveDocument(this)->m_pDocTemplate->m_hMenuInPlaceServer;
}

//------------------------------------------------------------------------------
// Address: 0x10372F43
// Name: public: static class CObject __near * COleIPFrameWnd::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleIPFrameWnd *__stdcall COleIPFrameWnd::CreateObject()
{
  COleIPFrameWnd *v0; // ecx
  COleIPFrameWnd *result; // eax

  v0 = (COleIPFrameWnd *)operator new(nSize: 0x188u);
  result = nullptr;
  if ( v0 != nullptr )
    return COleIPFrameWnd::COleIPFrameWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10372F73
// Name: protected: static struct AFX_MSGMAP const __near * COleIPFrameWnd::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COleIPFrameWnd::GetThisMessageMap(COleIPFrameWnd *this)
{
  return &messageMap_29;
}

//------------------------------------------------------------------------------
// Address: 0x10372F7B
// Name: public: virtual COleCntrFrameWnd::~COleCntrFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall COleCntrFrameWnd::~COleCntrFrameWnd(COleCntrFrameWnd *this)
{
  this->__vftable = (COleCntrFrameWnd_vtbl *)&COleCntrFrameWnd::`vftable';
  CFrameWnd::AddFrameWnd(this);
  CWnd::Detach(this);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10373090
// Name: public: virtual long COleIPFrameWnd::OnSetMessageString(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall COleIPFrameWnd::OnSetMessageString(
        COleIPFrameWnd *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > wParam,
        const char *lParam)
{
  unsigned int m_pszData; // edi
  CAfxStringMgr *StringManager; // eax
  const char *v6; // eax
  ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t> > > *v7; // eax
  unsigned int result; // eax

  m_pszData = (unsigned int)wParam.m_pszData;
  if ( this->m_lpFrame != nullptr )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &wParam, pStringMgr: StringManager);
    v6 = lParam;
    if ( lParam == nullptr )
    {
      if ( m_pszData == 0
        || (this->GetMessageString(this, a2: m_pszData, a3: &wParam), v6 = wParam.m_pszData, wParam.m_pszData == nullptr) )
      {
        v6 = &var;
      }
    }
    v7 = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
           this: (ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t> > > *)&lParam,
           pszSrc: v6);
    this->m_lpFrame->SetStatusText(this: this->m_lpFrame, a2: v7->m_pszData);
    ATL::CStringData::Release(this: (ATL::CStringData *)lParam - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)wParam.m_pszData - 1);
  }
  result = this->m_nIDLastMessage;
  this->m_nIDLastMessage = m_pszData;
  this->m_nIDTracking = m_pszData;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037312D
// Name: long _AfxMultMultDivDiv(int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxMultMultDivDiv(int factor, int num1, int num2, int den1, int den2)
{
  __int64 v5; // rdi
  __int64 v6; // rax
  __int64 v7; // kr08_8
  int v8; // ebx
  __int64 i; // rax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 numerator; // [esp+Ch] [ebp-8h]
  int nBitsInFactor; // [esp+20h] [ebp+Ch]

  v5 = den2 * (__int64)den1;
  v6 = (int)((unsigned __int64)(num2 * (__int64)num1) >> 32);
  numerator = num2 * (__int64)num1;
  v7 = __PAIR64__(HIDWORD(v6) ^ (unsigned int)v6, HIDWORD(v6) ^ (unsigned int)(num2 * num1))
     - __PAIR64__(HIDWORD(v6), HIDWORD(v6));
  v8 = 0;
  while ( v7 != 0 )
  {
    ++v8;
    v7 >>= 1;
  }
  nBitsInFactor = 0;
  for ( i = (int)abs32(factor); i != 0; i >>= 1 )
    ++nBitsInFactor;
  v10 = nBitsInFactor + v8;
  if ( v5 < 0 )
  {
    v5 = -v5;
    numerator = -numerator;
  }
  while ( v10 > 31 )
  {
    v11 = (unsigned __int64)numerator >> 1;
    v12 = v10 - 1;
    v13 = SHIDWORD(numerator) >> 1;
    v5 >>= 1;
    numerator >>= 1;
    if ( v12 <= 31 )
      break;
    numerator = __SPAIR64__(v13, v11) >> 1;
    v5 >>= 1;
    v14 = v12 - 1;
    v10 = v12 - 2;
    if ( v14 <= 31 )
      break;
    factor >>= 1;
    v5 >>= 1;
  }
  v15 = factor * numerator;
  if ( v5 != 0 )
  {
    return (v15 + v5 / 2) / v5;
  }
  else if ( v15 >= 0 )
  {
    LODWORD(v16) = 0x7FFFFFFF;
  }
  else
  {
    LODWORD(v16) = 0x80000000;
  }
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10373250
// Name: public: virtual void CPreviewDC::ReleaseOutputDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::ReleaseOutputDC(CPreviewDC *this)
{
  RestoreDC(hdc: this->m_hDC, nSavedDC: this->m_nSaveDCIndex);
  CDC::ReleaseOutputDC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10373269
// Name: public: virtual CPreviewDC::~CPreviewDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::~CPreviewDC(CPreviewDC *this)
{
  this->__vftable = (CPreviewDC_vtbl *)&CPreviewDC::`vftable';
  AfxDeleteObject(pObject: (void **)&this->m_hFont);
  CDC::~CDC(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037329E
// Name: public: virtual int CPreviewDC::SaveDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::SaveDC(CPreviewDC *this)
{
  HGDIOBJ StockObject; // eax
  int v3; // eax
  HDC__ *m_hDC; // [esp-Ch] [ebp-18h]
  HFONT__ *m_hFont; // [esp-8h] [ebp-14h]
  int nAttribIndex; // [esp+8h] [ebp-4h]

  nAttribIndex = SaveDC(hdc: this->m_hAttribDC);
  if ( this->m_hDC != nullptr )
  {
    StockObject = GetStockObject(i: 13);
    SelectObject(hdc: this->m_hDC, h: StockObject);
    v3 = SaveDC(hdc: this->m_hDC);
    m_hFont = this->m_hFont;
    m_hDC = this->m_hDC;
    this->m_nSaveDCDelta = v3 - nAttribIndex;
    SelectObject(hdc: m_hDC, h: m_hFont);
  }
  else
  {
    this->m_nSaveDCDelta = 0x7FFF;
  }
  return nAttribIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10376022
// Name: public: void CList<struct HWND__ __near *,struct HWND__ __near * __near &>::RemoveAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<HWND__ *,HWND__ * &>::RemoveAll(CList<HWND__ *,HWND__ * &> *this)
{
  CList<HWND__ *,HWND__ * &>::CNode *i; // eax
  CPlex *m_pBlocks; // ecx

  for ( i = this->m_pNodeHead; i != nullptr; i = i->pNext )
    ;
  m_pBlocks = this->m_pBlocks;
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  CPlex::FreeDataChain(this: m_pBlocks);
  this->m_pBlocks = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1037604F
// Name: protected: struct CList<struct tagPOINT,struct tagPOINT>::CNode __near * CList<struct tagPOINT,struct tagPOINT>::NewNode(struct CList<struct tagPOINT,struct tagPOINT>::CNode __near *,struct CList<struct tagPOINT,struct tagPOINT>::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<tagPOINT,tagPOINT>::CNode *__thiscall CList<tagPOINT,tagPOINT>::NewNode(
        CList<tagPOINT,tagPOINT> *this,
        CList<tagPOINT,tagPOINT>::CNode *pPrev,
        CList<tagPOINT,tagPOINT>::CNode *pNext)
{
  CPlex *v4; // eax
  int v5; // ecx
  CList<tagPOINT,tagPOINT>::CNode *i; // eax
  CList<tagPOINT,tagPOINT>::CNode *result; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v4 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: 0x10u);
    v5 = this->m_nBlockSize - 1;
    for ( i = (CList<tagPOINT,tagPOINT>::CNode *)&v4[4 * this->m_nBlockSize - 3]; v5 >= 0; --v5 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i--;
    }
  }
  result = this->m_pNodeFree;
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  this->m_pNodeFree = result->pNext;
  result->pPrev = pPrev;
  result->pNext = pNext;
  ++this->m_nCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103760AB
// Name: void SerializeElements<struct tagPOINT>(class CArchive __near &,struct tagPOINT __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SerializeElements<tagPOINT>(CArchive *ar, tagPOINT *pElements, tagPOINT *nCount)
{
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // edi
  tagPOINT *pData; // [esp+10h] [ebp+10h]

  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  v4 = (unsigned int)nCount;
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    if ( nCount != nullptr )
    {
      do
      {
        v6 = 0xFFFFFFF;
        if ( v4 < 0xFFFFFFF )
          v6 = v4;
        CArchive::EnsureRead(this: ar, lpBuf: pData, nCount: 8 * v6);
        pData += v6;
        v4 -= v6;
      }
      while ( v4 != 0 );
    }
  }
  else if ( nCount != nullptr )
  {
    do
    {
      v5 = 0xFFFFFFF;
      if ( v4 < 0xFFFFFFF )
        v5 = v4;
      CArchive::Write(this: ar, lpBuf: pData, nMax: 8 * v5);
      pData += v5;
      v4 -= v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037612F
// Name: public: static void CMFCVisualManager::RedrawAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall CMFCVisualManager::RedrawAll()
{
  CWnd *MainWnd; // eax
  CList<CFrameWnd *,CFrameWnd *>::CNode *m_pNodeHead; // esi
  CWnd *v2; // edi
  CFrameWnd *data; // edi
  CObList::CNode *v4; // esi
  CObject *v5; // eax
  CObject *v6; // edi
  CObject *v7; // [esp-4h] [ebp-14h]
  CWnd *pMainWnd; // [esp+Ch] [ebp-4h]

  MainWnd = AfxGetMainWnd();
  m_pNodeHead = CFrameImpl::m_lstFrames.m_pNodeHead;
  v2 = MainWnd;
  pMainWnd = MainWnd;
  if ( CFrameImpl::m_lstFrames.m_pNodeHead != nullptr )
  {
    do
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( CWnd::FromHandlePermanent(hWnd: (CDocument *)data->m_hWnd) != nullptr )
        RedrawWindow(hWnd: data->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
    }
    while ( m_pNodeHead != nullptr );
    v2 = pMainWnd;
  }
  if ( v2 != nullptr && v2->m_hWnd != nullptr && CWnd::FromHandlePermanent(hWnd: (CDocument *)v2->m_hWnd) != nullptr )
    RedrawWindow(hWnd: v2->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
  v4 = afxAllToolBars.m_pNodeHead;
  while ( v4 != nullptr )
  {
    v7 = v4->data;
    v4 = v4->pNext;
    v5 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v7);
    v6 = v5;
    if ( v5 != nullptr && CWnd::FromHandlePermanent(hWnd: (CDocument *)v5[8].__vftable) != nullptr )
      RedrawWindow(hWnd: (HWND)v6[8].__vftable, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
  }
  CPaneFrameWnd::RedrawAll();
}

//------------------------------------------------------------------------------
// Address: 0x103761EE
// Name: public: static void CMFCVisualManager::AdjustFrames(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall CMFCVisualManager::AdjustFrames()
{
  CList<CFrameWnd *,CFrameWnd *>::CNode *m_pNodeHead; // esi
  CFrameWnd *data; // edi

  m_pNodeHead = CFrameImpl::m_lstFrames.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( CWnd::FromHandlePermanent(hWnd: (CDocument *)data->m_hWnd) != nullptr )
      SendMessageA(hWnd: data->m_hWnd, Msg: AFX_WM_CHANGEVISUALMANAGER, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10376227
// Name: public: virtual void CMFCVisualManager::OnFillBarBackground(class CDC __near *,class CBasePane __near *,class CRect,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillBarBackground(
        CMFCVisualManager *this,
        CDC *pDC,
        CBasePane *pBar,
        CRect rectClient,
        CRect rectClip,
        int __formal)
{
  HWND Parent; // eax
  CWnd *v8; // eax
  COLORREF bottom; // ebx
  CBrush *p_brBtnFace; // esi
  bool v11; // zf
  CRect *p_rectClient; // eax

  if ( AfxDynamicDownCast(pClass: &CReBar::classCReBar, pObject: pBar) != nullptr
    || (Parent = GetParent(hWnd: pBar->m_hWnd),
        v8 = CWnd::FromHandle(hWnd: Parent),
        AfxDynamicDownCast(pClass: &CReBar::classCReBar, pObject: v8) != nullptr) )
  {
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CBasePane *, int, int, int, int))this->FillReBarPane)(
      a1: this,
      a2: pDC,
      a3: pBar,
      a4: rectClient.left,
      a5: rectClient.top,
      a6: rectClient.right,
      a7: rectClient.bottom);
  }
  else if ( CObject::IsKindOf(this: pBar, pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane) != 0 )
  {
    ((void (__thiscall *)(CBasePane *, CDC *, int, int, int, int))pBar->__vftable[1].CanFloat)(
      a1: pBar,
      a2: pDC,
      a3: rectClient.left,
      a4: rectClient.top,
      a5: rectClient.right,
      a6: rectClient.bottom);
  }
  else if ( CObject::IsKindOf(this: pBar, pClass: &CMFCCaptionBar::classCMFCCaptionBar) != 0 )
  {
    if ( pBar[2].m_pDockBarRow != nullptr )
    {
      FillRect(hDC: pDC->m_hDC, lprc: &rectClip, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
    }
    else
    {
      bottom = pBar[2].m_rectBar.bottom;
      if ( bottom == -1 )
        bottom = afxGlobalData.clrBarShadow;
      CDC::FillSolidRect(this: pDC, lpRect: &rectClip, clr: bottom);
    }
  }
  else if ( CObject::IsKindOf(this: pBar, pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar) != 0
         && pBar[13].m_pOuterUnknown != nullptr )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectClip, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
  }
  else
  {
    p_brBtnFace = &afxGlobalData.brBtnFace;
    if ( pBar->m_bIsDlgControl == 0 )
      p_brBtnFace = &afxGlobalData.brBarFace;
    v11 = !IsRectEmpty(lprc: &rectClip);
    p_rectClient = &rectClient;
    if ( v11 )
      p_rectClient = &rectClip;
    CDC::FillRect(this: pDC, lpRect: p_rectClient, pBrush: p_brBtnFace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10376365
// Name: public: virtual void CMFCVisualManager::OnDrawPaneBorder(class CDC __near *,class CBasePane __near *,class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCVisualManager::OnDrawPaneBorder(
        CMFCVisualManager *this@<ecx>,
        int a2@<edi>,
        CDC *pDC,
        CBasePane *pBar,
        CRect *rect)
{
  COLORREF BkColor; // eax
  int m_bIsDlgControl; // esi
  unsigned int clrBtnHilite; // eax
  unsigned int clrBtnShadow; // eax
  unsigned int clrBckOld; // [esp+4h] [ebp-14h]
  int v12; // [esp+8h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-Ch]
  unsigned int clrHilite; // [esp+10h] [ebp-8h]
  __int16 dwStyle; // [esp+14h] [ebp-4h]
  unsigned int dwStylea; // [esp+14h] [ebp-4h]
  unsigned int clrShadow; // [esp+20h] [ebp+8h]
  CRect *recta; // [esp+28h] [ebp+10h]

  if ( pBar->IsFloating(this: pBar) == 0 )
  {
    dwStyle = pBar->GetPaneStyle(this: pBar);
    if ( (dwStyle & 0xF00) != 0 )
    {
      BkColor = GetBkColor(hdc: pDC->m_hAttribDC);
      m_bIsDlgControl = pBar->m_bIsDlgControl;
      clrBckOld = BkColor;
      clrBtnHilite = afxGlobalData.clrBtnHilite;
      if ( m_bIsDlgControl == 0 )
        clrBtnHilite = afxGlobalData.clrBarHilite;
      clrHilite = clrBtnHilite;
      clrBtnShadow = afxGlobalData.clrBtnShadow;
      if ( m_bIsDlgControl == 0 )
        clrBtnShadow = afxGlobalData.clrBarShadow;
      clrShadow = clrBtnShadow;
      v13 = dwStyle & 0x100;
      if ( (dwStyle & 0x100) != 0 )
        CDC::FillSolidRect(this: pDC, x: 0, y: 0, cx: 1, cy: rect->bottom - rect->top - 1, clr: clrHilite);
      recta = (CRect *)(dwStyle & 0x200);
      if ( (dwStyle & 0x200) != 0 )
        CDC::FillSolidRect(this: pDC, x: 0, y: 0, cx: rect->right - rect->left - 1, cy: 1, clr: clrHilite);
      v12 = dwStyle & 0x400;
      if ( (dwStyle & 0x400) != 0 )
        CDC::FillSolidRect(this: pDC, x: rect->right, y: 0, cx: -1, cy: rect->bottom - rect->top, clr: clrShadow);
      dwStylea = dwStyle & 0x800;
      if ( dwStylea != 0 )
        CDC::FillSolidRect(this: pDC, x: 0, y: rect->bottom, cx: rect->right - rect->left - 1, cy: -1, clr: clrShadow);
      if ( ((int (__thiscall *)(CBasePane *, int))pBar->CanFloat)(a1: pBar, a2) == 0 )
      {
        CDC::FillSolidRect(this: pDC, x: 0, y: 0, cx: rect->right - rect->left, cy: 1, clr: clrShadow);
        CDC::FillSolidRect(this: pDC, x: 0, y: 1, cx: rect->right - rect->left, cy: 1, clr: clrHilite);
      }
      if ( v13 != 0 )
        ++rect->left;
      if ( recta != nullptr )
        ++rect->top;
      if ( v12 != 0 )
        --rect->right;
      if ( dwStylea != 0 )
        --rect->bottom;
      pDC->SetBkColor(this: pDC, a2: clrBckOld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103764CE
// Name: public: virtual void CMFCVisualManager::OnHighlightMenuItem(class CDC __near *,class CMFCToolBarMenuButton __near *,class CRect,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnHighlightMenuItem(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarMenuButton *__formal,
        CRect rect,
        unsigned int *a5)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x103764ED
// Name: public: virtual unsigned long CMFCVisualManager::OnDrawMenuLabel(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnDrawMenuLabel(CMFCVisualManager *this, CDC *pDC, CRect rect)
{
  CRect rectSeparator; // [esp+Ch] [ebp-14h] BYREF

  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  rectSeparator.left = rect.left;
  rectSeparator.right = rect.right;
  rectSeparator.bottom = rect.bottom;
  rectSeparator.top = rect.bottom - 2;
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectSeparator,
    clrTopLeft: afxGlobalData.clrBtnShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
  return afxGlobalData.clrBtnText;
}

//------------------------------------------------------------------------------
// Address: 0x10376558
// Name: public: virtual void CMFCVisualManager::OnFillTab(class CDC __near *,class CRect,class CBrush __near *,int,int,class CMFCBaseTabCtrl const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillTab(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectFill,
        CBrush *pbrFill,
        int iTab,
        int bIsActive,
        CMFCBaseTabCtrl *pTabWnd)
{
  CMFCBaseTabCtrl *v7; // esi
  HBRUSH v8; // edi

  v7 = pTabWnd;
  v8 = (HBRUSH)pbrFill;
  if ( bIsActive != 0
    && afxGlobalData.m_bIsWhiteHighContrast == 0
    && afxGlobalData.m_bIsBlackHighContrast == 0
    && (pTabWnd->IsOneNoteStyle(this: pTabWnd) != 0
     || v7->IsVS2005Style(this: v7) != 0
     || v7->IsLeftRightRounded(this: v7) != 0)
    && v7->GetTabBkColor(this: v7, a2: iTab) == -1 )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectFill, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
  }
  else
  {
    if ( v8 != nullptr )
      v8 = *((HBRUSH *)v8 + 1);
    FillRect(hDC: pDC->m_hDC, lprc: &rectFill, hbr: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103765E0
// Name: public: virtual void CMFCVisualManager::OnDrawTabCloseButton(class CDC __near *,class CRect,class CMFCBaseTabCtrl const __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTabCloseButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        const CMFCBaseTabCtrl *__formal,
        int bIsHighlighted,
        int bIsPressed,
        int a7)
{
  CSize sizeImageDest; // [esp+8h] [ebp-8h] BYREF

  if ( bIsHighlighted != 0 )
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdClose, rectImage: &rect, state: ImageBlack, &sizeImageDest);
  if ( bIsHighlighted != 0 )
  {
    if ( bIsPressed != 0 )
      CDC::Draw3dRect(
        this: pDC,
        lpRect: &rect,
        clrTopLeft: afxGlobalData.clrBarDkShadow,
        clrBottomRight: afxGlobalData.clrBarHilite);
    else
      CDC::Draw3dRect(
        this: pDC,
        lpRect: &rect,
        clrTopLeft: afxGlobalData.clrBarHilite,
        clrBottomRight: afxGlobalData.clrBarDkShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10376652
// Name: public: virtual void CMFCVisualManager::OnEraseTabsButton(class CDC __near *,class CRect,class CMFCButton __near *,class CMFCBaseTabCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnEraseTabsButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCButton *__formal,
        CMFCBaseTabCtrl *a5)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x10376671
// Name: public: virtual void CMFCVisualManager::OnDrawTabResizeBar(class CDC __near *,class CMFCBaseTabCtrl __near *,int,class CRect,class CBrush __near *,class CPen __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTabResizeBar(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCBaseTabCtrl *__formal,
        int bIsVert,
        CRect rect,
        CBrush *pbrFace,
        CFont *pPen)
{
  HBRUSH m_hObject; // eax
  CFont *v8; // edi
  CFont *v9; // edi
  CPoint result; // [esp+8h] [ebp-8h] BYREF

  m_hObject = (HBRUSH)pbrFace;
  v8 = pPen;
  if ( pbrFace != nullptr )
    m_hObject = (HBRUSH)pbrFace->m_hObject;
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: m_hObject);
  v9 = CDC::SelectObject(this: pDC, pFont: v8);
  CDC::MoveTo(this: pDC, &result, x: rect.left, y: rect.top);
  if ( bIsVert != 0 )
    CDC::LineTo(this: pDC, x: rect.left, y: rect.bottom);
  else
    CDC::LineTo(this: pDC, x: rect.right, y: rect.top);
  CDC::SelectObject(this: pDC, pFont: v9);
}

//------------------------------------------------------------------------------
// Address: 0x103766DC
// Name: public: virtual unsigned long CMFCVisualManager::OnFillCommandsListBackground(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnFillCommandsListBackground(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bIsSelected)
{
  if ( bIsSelected != 0 )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
    --rect.right;
    PatBlt(hdc: pDC->m_hDC, x: rect.left, y: rect.top + 1, w: 1, h: --rect.bottom - rect.top, rop: 0x5A0049u);
    PatBlt(hdc: pDC->m_hDC, x: rect.left, y: rect.top, w: rect.right - rect.left, h: 1, rop: 0x5A0049u);
    PatBlt(hdc: pDC->m_hDC, x: rect.right, y: rect.top, w: 1, h: rect.bottom - rect.top, rop: 0x5A0049u);
    PatBlt(hdc: pDC->m_hDC, x: rect.left + 1, y: rect.bottom, w: rect.right - rect.left, h: 1, rop: 0x5A0049u);
    return afxGlobalData.clrTextHilite;
  }
  else
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
    return afxGlobalData.clrBarText;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037679D
// Name: public: virtual void CMFCVisualManager::OnDrawTearOffCaption(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTearOffCaption(CMFCVisualManager *this, CDC *pDC, CRect rect, int bIsActive)
{
  COLORREF clrActiveCaption; // eax

  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  InflateRect(lprc: &rect, dx: -2, dy: -1);
  clrActiveCaption = afxGlobalData.clrActiveCaption;
  if ( bIsActive == 0 )
    clrActiveCaption = afxGlobalData.clrInactiveCaption;
  CDC::FillSolidRect(this: pDC, lpRect: &rect, clr: clrActiveCaption);
}

//------------------------------------------------------------------------------
// Address: 0x103767E8
// Name: public: virtual void CMFCVisualManager::OnDrawMenuScrollButton(class CDC __near *,class CRect,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuScrollButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bIsScrollDown,
        int bIsHighlited,
        int __formal,
        int a7)
{
  CSize sizeImageDest; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectFill; // [esp+14h] [ebp-14h] BYREF

  rectFill.left = rect.left;
  rectFill.right = rect.right;
  rectFill.bottom = rect.bottom;
  rectFill.top = rect.top - 2;
  FillRect(hDC: pDC->m_hDC, lprc: &rectFill, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(
    pDC,
    id: bIsScrollDown != 0 ? IdArrowDown : IdArrowUp,
    rectImage: &rect,
    state: ImageBlack,
    &sizeImageDest);
  if ( bIsHighlited != 0 )
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10376878
// Name: public: virtual void CMFCVisualManager::OnDrawMenuSystemButton(class CDC __near *,class CRect,unsigned int,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuSystemButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        unsigned int uiSystemCommand,
        unsigned int nStyle,
        int __formal)
{
  UINT v6; // edx

  v6 = 0;
  switch ( uiSystemCommand )
  {
    case 0xF020u:
      v6 = 1;
      break;
    case 0xF060u:
      break;
    case 0xF120u:
      v6 = 3;
      break;
    default:
      return;
  }
  if ( (nStyle & 0x20000) != 0 )
    v6 |= 0x200u;
  if ( (nStyle & 0x40000) != 0 )
    v6 |= 0x100u;
  DrawFrameControl(a1: pDC->m_hDC, a2: &rect, a3: 1u, a4: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103768D2
// Name: public: virtual void CMFCVisualManager::OnDrawComboDropButton(class CDC __near *,class CRect,int,int,int,class CMFCToolBarComboBoxButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawComboDropButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bDisabled,
        int bIsDropped,
        int bIsHighlighted,
        CMFCToolBarComboBoxButton *__formal)
{
  COLORREF TextColor; // ebx
  CSize sizeImageDest; // [esp+10h] [ebp-1Ch] BYREF
  CDrawingManager dm; // [esp+18h] [ebp-14h] BYREF
  int v10; // [esp+28h] [ebp-4h]

  TextColor = GetTextColor(hdc: pDC->m_hAttribDC);
  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v10 = 0;
    CDrawingManager::DrawRect(
      this: &dm,
      (int)&rect,
      clrFill: afxGlobalData.clrBarFace,
      clrLine: afxGlobalData.clrBarHilite);
    if ( bIsDropped != 0 )
    {
      OffsetRect(lprc: &rect, dx: 1, dy: 1);
    }
    else if ( bIsHighlighted == 0 )
    {
LABEL_6:
      v10 = -1;
      CDrawingManager::~CDrawingManager(this: &dm);
      goto LABEL_11;
    }
    CDrawingManager::DrawRect(this: &dm, (int)&rect, clrFill: 0xFFFFFFFF, clrLine: afxGlobalData.clrBarShadow);
    goto LABEL_6;
  }
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarHilite);
  if ( bIsDropped != 0 )
  {
    OffsetRect(lprc: &rect, dx: 1, dy: 1);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
  else if ( bIsHighlighted != 0 )
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarShadow);
  }
LABEL_11:
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(
    pDC,
    id: IdArrowDown,
    rectImage: &rect,
    state: (CMenuImages::IMAGE_STATE)(bDisabled != 0),
    &sizeImageDest);
  pDC->SetTextColor(this: pDC, a2: TextColor);
}

//------------------------------------------------------------------------------
// Address: 0x103769E6
// Name: public: virtual void CMFCVisualManager::OnFillOutlookPageButton(class CDC __near *,class CRect const __near &,int,int,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillOutlookPageButton(
        CMFCVisualManager *this,
        CDC *pDC,
        const CRect *rect,
        int __formal,
        int a5,
        unsigned int *clrText)
{
  FillRect(hDC: pDC->m_hDC, lprc: rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  *clrText = afxGlobalData.clrBarText;
}

//------------------------------------------------------------------------------
// Address: 0x10376A0F
// Name: public: virtual void CMFCVisualManager::OnDrawCaptionBarInfoArea(class CDC __near *,class CMFCCaptionBar __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawCaptionBarInfoArea(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCCaptionBar *__formal,
        CRect rect)
{
  HDC__ *m_hDC; // edi
  HBRUSH SysColorBrush; // eax

  if ( pDC != nullptr )
    m_hDC = pDC->m_hDC;
  else
    m_hDC = nullptr;
  SysColorBrush = GetSysColorBrush(nIndex: 24);
  FillRect(hDC: m_hDC, lprc: &rect, hbr: SysColorBrush);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarHilite);
  InflateRect(lprc: &rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10376A7A
// Name: public: virtual unsigned long CMFCVisualManager::OnFillCaptionBarButton(class CDC __near *,class CMFCCaptionBar __near *,class CRect,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnFillCaptionBarButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCCaptionBar *pBar,
        CRect rect,
        int bIsPressed,
        int bIsHighlighted,
        int bIsDisabled,
        int bHasDropDownArrow,
        int bIsSysButton)
{
  unsigned int result; // eax

  if ( pBar->m_bIsMessageBarMode == 0 )
    return -1;
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  result = afxGlobalData.clrGrayedText;
  if ( bIsDisabled == 0 )
    return afxGlobalData.clrBarText;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10376ABA
// Name: public: virtual void CMFCVisualManager::OnFillHeaderCtrlBackground(class CMFCHeaderCtrl __near *,class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillHeaderCtrlBackground(
        CMFCVisualManager *this,
        CMFCHeaderCtrl *pCtrl,
        CDC *pDC,
        CRect rect)
{
  CBrush *p_brBtnFace; // eax

  p_brBtnFace = &afxGlobalData.brBtnFace;
  if ( pCtrl->m_bIsDlgControl == 0 )
    p_brBtnFace = &afxGlobalData.brBarFace;
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)p_brBtnFace->m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x10376AEC
// Name: public: virtual void CMFCVisualManager::OnDrawEditBorder(class CDC __near *,class CRect,int,int,class CMFCToolBarEditBoxButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawEditBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int __formal,
        int bIsHighlighted,
        CMFCToolBarEditBoxButton *a6)
{
  if ( bIsHighlighted != 0 )
    DrawEdge(hdc: pDC->m_hDC, qrc: &rect, edge: 0xAu, grfFlags: 0xFu);
}

//------------------------------------------------------------------------------
// Address: 0x10376B0F
// Name: public: virtual void CMFCVisualManager::OnFillTasksPaneBackground(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillTasksPaneBackground(CMFCVisualManager *this, CDC *pDC, CRect rectWorkArea)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rectWorkArea, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x10376B2E
// Name: public: virtual void CMFCVisualManager::OnDrawTasksGroupIcon(class CDC __near *,class CMFCTasksPaneTaskGroup __near *,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTasksGroupIcon(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCTasksPaneTaskGroup *pGroup,
        int nIconHOffset,
        int __formal,
        int a6,
        int a7)
{
  int m_nGroupCaptionVertOffset; // eax
  int v9; // edi
  HDC__ *m_hDC; // edx
  int rectImage; // [esp+4h] [ebp-14h]
  int rectImage_4; // [esp+8h] [ebp-10h]
  int rectImage_12; // [esp+10h] [ebp-8h]
  HICON__ *hIcon; // [esp+14h] [ebp-4h]
  int y; // [esp+24h] [ebp+Ch]

  hIcon = pGroup->m_hIcon;
  if ( hIcon != nullptr )
  {
    m_nGroupCaptionVertOffset = pGroup->m_pPage->m_pTaskPane->m_nGroupCaptionVertOffset;
    rectImage = pGroup->m_rect.left;
    rectImage_12 = pGroup->m_rect.bottom;
    if ( m_nGroupCaptionVertOffset == -1 )
      m_nGroupCaptionVertOffset = this->m_nGroupCaptionVertOffset;
    rectImage_4 = m_nGroupCaptionVertOffset + pGroup->m_rect.top;
    if ( nIconHOffset / 2 >= 0 )
      v9 = nIconHOffset / 2;
    else
      v9 = 0;
    if ( (rectImage_12 - pGroup->m_sizeIcon.cy - rectImage_4) / 2 >= 0 )
      y = (rectImage_12 - pGroup->m_sizeIcon.cy - rectImage_4) / 2;
    else
      y = 0;
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    DrawIconEx(
      hdc: m_hDC,
      xLeft: rectImage + v9,
      yTop: rectImage_12 - pGroup->m_sizeIcon.cy - y,
      hIcon,
      cxWidth: pGroup->m_sizeIcon.cx,
      cyWidth: pGroup->m_sizeIcon.cy,
      istepIfAniCur: 0,
      hbrFlickerFreeDraw: nullptr,
      diFlags: 3u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10376BE9
// Name: public: virtual void CMFCVisualManager::OnDrawScrollButtons(class CDC __near *,class CRect const __near &,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawScrollButtons(
        CMFCVisualManager *this,
        CDC *pDC,
        const CRect *rect,
        const int nBorderSize,
        CMenuImages::IMAGES_IDS iImage,
        int bHilited)
{
  CSize sizeImageDest; // [esp+10h] [ebp-34h] BYREF
  CSize result; // [esp+18h] [ebp-2Ch] BYREF
  tagRECT *lpRect; // [esp+20h] [ebp-24h]
  RECT rc; // [esp+24h] [ebp-20h] BYREF
  int v10; // [esp+40h] [ebp-4h]

  lpRect = &rect->tagRECT;
  CMenuImages::Size(&result);
  rc = rect->tagRECT;
  rc.top -= nBorderSize;
  FillRect(hDC: pDC->m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  if ( bHilited != 0 )
  {
    CDrawingManager::CDrawingManager(this: (CDrawingManager *)&result, m_dc: pDC);
    v10 = 0;
    CDrawingManager::HighlightRect(
      this: (CDrawingManager *)&result,
      rect: (CRect)*lpRect,
      nPercentage: -1,
      clrTransparent: -1,
      nTolerance: 0,
      clrBlend: 0xFFFFFFFF);
    CDC::Draw3dRect(
      this: pDC,
      lpRect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
    v10 = -1;
    CDrawingManager::~CDrawingManager(this: (CDrawingManager *)&result);
  }
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: iImage, rectImage: (const CRect *)lpRect, state: ImageBlack, &sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x10376C98
// Name: public: virtual void CMFCVisualManager::OnDrawSpinButtons(class CDC __near *,class CRect,int,int,class CMFCSpinButtonCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawSpinButtons(
        CMFCVisualManager *this,
        CDC *pDC,
        tagRECT rectSpin,
        char nState,
        CDC *bOrientation,
        CMFCSpinButtonCtrl *__formal)
{
  int v6; // edx
  int *p_right; // eax
  int v8; // esi
  CRect *p_rect; // edi
  CMenuImages::IMAGES_IDS *v10; // ebx
  CSize sizeImageDest; // [esp+10h] [ebp-60h] BYREF
  CDrawingManager v12; // [esp+18h] [ebp-58h] BYREF
  CDrawingManager v13; // [esp+20h] [ebp-50h] BYREF
  CDC *pDCa; // [esp+28h] [ebp-48h]
  int v15; // [esp+2Ch] [ebp-44h]
  CRect rect; // [esp+30h] [ebp-40h] BYREF
  tagRECT v17; // [esp+40h] [ebp-30h]
  _DWORD v18[7]; // [esp+50h] [ebp-20h] BYREF
  int v19; // [esp+6Ch] [ebp-4h]

  v13.m_dc = bOrientation;
  pDCa = pDC;
  InflateRect(lprc: &rectSpin, dx: -1, dy: -1);
  v6 = 1;
  p_right = &rect.right;
  do
  {
    *(p_right - 2) = 0;
    *(p_right - 1) = 0;
    *p_right = 0;
    p_right[1] = 0;
    p_right += 4;
    --v6;
  }
  while ( v6 >= 0 );
  v17 = rectSpin;
  rect = (CRect)rectSpin;
  if ( v13.m_dc != nullptr )
  {
    rect.right = rectSpin.right - (rectSpin.right - rectSpin.left) / 2;
    v17.left = rect.right + 1;
  }
  else
  {
    rect.bottom = rectSpin.bottom - (rectSpin.bottom - rectSpin.top) / 2;
    v17.top = rect.bottom + 1;
  }
  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &v12, m_dc: pDC);
    v19 = 0;
    CDrawingManager::DrawRect(
      this: &v12,
      rect: (int)&rectSpin,
      clrFill: afxGlobalData.clrBarFace,
      clrLine: afxGlobalData.clrBarHilite);
    v19 = -1;
    CDrawingManager::~CDrawingManager(this: &v12);
  }
  else
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectSpin, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectSpin,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
  v8 = (nState & 3) - 1;
  v18[1] = 0;
  v15 = 0;
  v18[0] = 7;
  v18[2] = 9;
  v18[3] = 1;
  v12.m_dc = (CDC *)((nState & 0x10) != 0);
  p_rect = &rect;
  v10 = (CMenuImages::IMAGES_IDS *)&v18[2 * (v13.m_dc != nullptr)];
  do
  {
    if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
    {
      CDrawingManager::CDrawingManager(this: &v13, m_dc: pDCa);
      v19 = 1;
      if ( v8 == v15 )
        CDrawingManager::DrawRect(
          this: &v13,
          rect: (int)p_rect,
          clrFill: 0xFFFFFFFF,
          clrLine: afxGlobalData.clrBarShadow);
      else
        CDrawingManager::DrawRect(
          this: &v13,
          rect: (int)p_rect,
          clrFill: 0xFFFFFFFF,
          clrLine: afxGlobalData.clrBarHilite);
      v19 = -1;
      CDrawingManager::~CDrawingManager(this: &v13);
    }
    else if ( v8 == v15 )
    {
      CDC::Draw3dRect(
        this: pDCa,
        lpRect: p_rect,
        clrTopLeft: afxGlobalData.clrBarShadow,
        clrBottomRight: afxGlobalData.clrBarHilite);
    }
    else
    {
      CDC::Draw3dRect(
        this: pDCa,
        lpRect: p_rect,
        clrTopLeft: afxGlobalData.clrBarHilite,
        clrBottomRight: afxGlobalData.clrBarShadow);
    }
    sizeImageDest.cx = 0;
    sizeImageDest.cy = 0;
    CMenuImages::Draw(pDC: pDCa, id: *v10, rectImage: p_rect, state: (CMenuImages::IMAGE_STATE)v12.m_dc, &sizeImageDest);
    ++v15;
    ++v10;
    ++p_rect;
  }
  while ( v15 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x10376E63
// Name: public: virtual void CMFCVisualManager::OnDrawControlBorder(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawControlBorder(CMFCVisualManager *this, CWnd *pWndCtrl)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-4Ch]
  CWindowDC v3; // [esp+10h] [ebp-34h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-20h] BYREF
  int v5; // [esp+40h] [ebp-4h]

  CWindowDC::CWindowDC(this: &v3, pWnd: pWndCtrl);
  m_hWnd = pWndCtrl->m_hWnd;
  v5 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
  Rect.bottom -= Rect.top;
  Rect.right -= Rect.left;
  Rect.top = 0;
  Rect.left = 0;
  if ( CWnd::GetStyle(this: pWndCtrl) >= 0 )
    CDC::Draw3dRect(
      this: &v3,
      lpRect: &Rect,
      clrTopLeft: afxGlobalData.clrBarDkShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  else
    CDC::Draw3dRect(
      this: &v3,
      lpRect: &Rect,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarShadow);
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: &v3,
    lpRect: &Rect,
    clrTopLeft: afxGlobalData.clrWindow,
    clrBottomRight: afxGlobalData.clrWindow);
  v5 = -1;
  CWindowDC::~CWindowDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x10376F0C
// Name: public: virtual void CMFCVisualManager::OnEraseTabsArea(class CDC __near *,class CRect,class CMFCBaseTabCtrl const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnEraseTabsArea(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCAutoHideButton *__formal)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x10376F2B
// Name: public: virtual void CMFCVisualManager::OnDrawAutoHideButtonBorder(class CDC __near *,class CRect,class CRect,class CMFCAutoHideButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawAutoHideButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectBounds,
        CRect rectBorderSize,
        CMFCAutoHideButton *__formal)
{
  COLORREF clrBarShadow; // edi
  COLORREF TextColor; // ebx

  clrBarShadow = afxGlobalData.clrBarShadow;
  TextColor = GetTextColor(hdc: pDC->m_hAttribDC);
  if ( rectBorderSize.left > 0 )
    CDC::FillSolidRect(
      this: pDC,
      x: rectBounds.left,
      y: rectBounds.top,
      cx: rectBounds.left + rectBorderSize.left,
      cy: rectBounds.bottom,
      clr: clrBarShadow);
  if ( rectBorderSize.top > 0 )
    CDC::FillSolidRect(
      this: pDC,
      x: rectBounds.left,
      y: rectBounds.top,
      cx: rectBounds.right,
      cy: rectBounds.top + rectBorderSize.top,
      clr: clrBarShadow);
  if ( rectBorderSize.right > 0 )
    CDC::FillSolidRect(
      this: pDC,
      x: rectBounds.right - rectBorderSize.right,
      y: rectBounds.top,
      cx: rectBounds.right,
      cy: rectBounds.bottom,
      clr: clrBarShadow);
  if ( rectBorderSize.bottom > 0 )
    CDC::FillSolidRect(
      this: pDC,
      x: rectBounds.left,
      y: rectBounds.bottom - rectBorderSize.bottom,
      cx: rectBounds.right,
      cy: rectBounds.bottom,
      clr: clrBarShadow);
  pDC->SetTextColor(this: pDC, a2: TextColor);
}

//------------------------------------------------------------------------------
// Address: 0x10376FC6
// Name: public: virtual void CMFCVisualManager::OnDrawOutlookBarSplitter(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawOutlookBarSplitter(CMFCVisualManager *this, CDC *pDC, CRect rectSplitter)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rectSplitter, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectSplitter,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10376FFE
// Name: public: virtual int CMFCVisualManager::OnDrawBrowseButton(class CDC __near *,class CRect,class CMFCEditBrowseCtrl __near *,enum CMFCVisualManager::AFX_BUTTON_STATE,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::OnDrawBrowseButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCEditBrowseCtrl *__formal,
        CMFCVisualManager::AFX_BUTTON_STATE state,
        unsigned int *a6)
{
  CRect rectFrame; // [esp+Ch] [ebp-14h] BYREF

  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  rectFrame.left = rect.left;
  rectFrame.right = rect.right + 1;
  rectFrame.bottom = rect.bottom + 1;
  rectFrame.top = rect.top - 1;
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectFrame,
    clrTopLeft: afxGlobalData.clrBtnDkShadow,
    clrBottomRight: afxGlobalData.clrBtnDkShadow);
  InflateRect(lprc: &rectFrame, dx: -1, dy: -1);
  DrawEdge(hdc: pDC->m_hDC, qrc: &rectFrame, edge: 4 * (state == ButtonsIsPressed) + 4, grfFlags: 0xFu);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10377094
// Name: public: virtual void CMFCVisualManager::OnFillPopupWindowBackground(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillPopupWindowBackground(CMFCVisualManager *this, CDC *pDC, CRect rect)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x103770B3
// Name: public: virtual void CMFCVisualManager::OnErasePopupWindowButton(class CDC __near *,class CRect,class CMFCDesktopAlertWndButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnErasePopupWindowButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCDesktopAlertWndButton *pButton)
{
  CMFCDesktopAlertWndButton *v4; // esi
  HWND Parent; // eax
  CWnd *v7; // eax
  HWND v8; // eax
  CWnd *v9; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-28h]
  CRect rectParent; // [esp+10h] [ebp-14h] BYREF

  v4 = pButton;
  if ( pButton->m_bIsCaptionButton != 0 )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  }
  else
  {
    m_hWnd = pButton->m_hWnd;
    memset(&rectParent, 0, sizeof(rectParent));
    Parent = GetParent(hWnd: m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    GetClientRect(hWnd: v7->m_hWnd, lpRect: &rectParent);
    v8 = GetParent(hWnd: v4->m_hWnd);
    v9 = CWnd::FromHandle(hWnd: v8);
    MapWindowPoints(hWndFrom: v9->m_hWnd, hWndTo: v4->m_hWnd, lpPoints: (LPPOINT)&rectParent, cPoints: 2u);
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int))this->OnFillPopupWindowBackground)(
      a1: this,
      a2: pDC,
      a3: rectParent.left,
      a4: rectParent.top,
      a5: rectParent.right,
      a6: rectParent.bottom);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10377164
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonCategoryScroll(class CDC __near *,class CRibbonCategoryScroll __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonCategoryScroll(
        CMFCVisualManager *this,
        CDC *pDC,
        CRibbonCategoryScroll *pScroll)
{
  int m_bIsLeft; // eax
  HDC__ *m_hDC; // [esp-Ch] [ebp-50h]
  CSize sizeImageDest; // [esp+10h] [ebp-34h] BYREF
  CDrawingManager v6; // [esp+18h] [ebp-2Ch] BYREF
  CDC *m_dc; // [esp+20h] [ebp-24h]
  RECT rc; // [esp+24h] [ebp-20h] BYREF
  int v9; // [esp+40h] [ebp-4h]

  rc.left = pScroll->m_rect.left;
  rc.top = pScroll->m_rect.top;
  rc.right = pScroll->m_rect.right;
  m_hDC = pDC->m_hDC;
  rc.bottom = pScroll->m_rect.bottom;
  --rc.bottom;
  m_dc = pDC;
  FillRect(hDC: m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  if ( pScroll->IsHighlighted(this: pScroll) != 0 )
  {
    CDrawingManager::CDrawingManager(this: &v6, m_dc);
    v9 = 0;
    CDrawingManager::HighlightRect(
      this: &v6,
      rect: (CRect)rc,
      nPercentage: -1,
      clrTransparent: -1,
      nTolerance: 0,
      clrBlend: 0xFFFFFFFF);
    v9 = -1;
    CDrawingManager::~CDrawingManager(this: &v6);
  }
  m_bIsLeft = pScroll->m_bIsLeft;
  if ( afxGlobalData.m_bIsRTL != 0 )
    m_bIsLeft = m_bIsLeft == 0;
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(
    pDC: m_dc,
    id: (CMenuImages::IMAGES_IDS)(m_bIsLeft != 0 ? IdArrowLeftLarge : IdArrowRightLarge),
    rectImage: (const CRect *)&rc,
    state: ImageBlack,
    &sizeImageDest);
  CDC::Draw3dRect(
    this: m_dc,
    lpRect: &rc,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10377231
// Name: public: virtual unsigned long CMFCVisualManager::OnDrawRibbonPanel(class CDC __near *,class CMFCRibbonPanel __near *,class CRect,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnDrawRibbonPanel(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonPanel *pPanel,
        CRect rectPanel,
        CRect __formal)
{
  CDrawingManager dm; // [esp+10h] [ebp-18h] BYREF
  unsigned int clrText; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  clrText = afxGlobalData.clrBarText;
  if ( CMFCRibbonPanel::IsCollapsed(this: pPanel) != 0
    && pPanel->m_btnDefault.IsFocused(this: &pPanel->m_btnDefault) != 0 )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectPanel, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
    clrText = afxGlobalData.clrTextHilite;
  }
  else if ( pPanel->m_bIsHighlighted != 0 )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v8 = 0;
    CDrawingManager::HighlightRect(
      this: &dm,
      rect: rectPanel,
      nPercentage: -1,
      clrTransparent: -1,
      nTolerance: 0,
      clrBlend: 0xFFFFFFFF);
    v8 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectPanel,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarHilite);
  OffsetRect(lprc: &rectPanel, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectPanel,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
  return clrText;
}

//------------------------------------------------------------------------------
// Address: 0x103772FB
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonDefaultPaneButtonIndicator(class CDC __near *,class CMFCRibbonButton __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonDefaultPaneButtonIndicator(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *__formal,
        CRect rect,
        int a5,
        int a6)
{
  CSize sizeImageDest; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectWhite; // [esp+14h] [ebp-14h] BYREF

  rect.left = rect.right + rect.top - rect.bottom;
  InflateRect(lprc: &rect, dx: -1, dy: -1);
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
  rectWhite = rect;
  OffsetRect(lprc: &rectWhite, dx: 0, dy: 1);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdArrowDown, rectImage: &rectWhite, state: ImageWhite, &sizeImageDest);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdArrowDown, rectImage: &rect, state: ImageBlack, &sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x103773A9
// Name: public: virtual unsigned long CMFCVisualManager::OnFillRibbonButton(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnFillRibbonButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  CDrawingManager *v3; // ecx
  HDC__ *m_hDC; // [esp-Ch] [ebp-70h]
  CDrawingManager v6; // [esp+10h] [ebp-54h] BYREF
  unsigned int clrLine; // [esp+18h] [ebp-4Ch]
  CDrawingManager v8; // [esp+1Ch] [ebp-48h] BYREF
  CRect m_rect; // [esp+24h] [ebp-40h] BYREF
  RECT rc; // [esp+34h] [ebp-30h] BYREF
  CRect rect; // [esp+44h] [ebp-20h] BYREF
  int v12; // [esp+60h] [ebp-4h]

  v8.m_dc = pDC;
  if ( CObject::IsKindOf(this: pButton, pClass: &CMFCRibbonEdit::classCMFCRibbonEdit) != 0 )
  {
    rc = (RECT)pButton->m_rectCommand;
    rect = pButton->m_rect;
    clrLine = afxGlobalData.clrBarShadow;
    rect.left = rc.left;
    if ( CMFCToolBarImages::m_bIsDrawOnGlass == 0 )
    {
      if ( pButton->IsDroppedDown(this: pButton) != 0 || pButton->IsHighlighted(this: pButton) != 0 )
      {
        FillRect(hDC: v8.m_dc->m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
      }
      else
      {
        CDrawingManager::CDrawingManager(this: &v6, m_dc: v8.m_dc);
        v12 = 1;
        CDrawingManager::HighlightRect(
          this: &v6,
          rect: (CRect)rc,
          nPercentage: -1,
          clrTransparent: -1,
          nTolerance: 0,
          clrBlend: 0xFFFFFFFF);
        v12 = -1;
        CDrawingManager::~CDrawingManager(this: &v6);
      }
      CDC::Draw3dRect(this: v8.m_dc, lpRect: &rect, clrTopLeft: clrLine, clrBottomRight: clrLine);
      return -1;
    }
    CDrawingManager::CDrawingManager(this: &v8, m_dc: v8.m_dc);
    v12 = 0;
    CDrawingManager::DrawRect(this: &v8, (int)&rect, clrFill: afxGlobalData.clrWindow, clrLine);
    v3 = &v8;
LABEL_17:
    v12 = -1;
    CDrawingManager::~CDrawingManager(this: v3);
    return -1;
  }
  if ( CMFCRibbonBaseElement::IsMenuMode(this: pButton) == 0 || pButton->IsGalleryIcon(this: pButton) != 0 )
  {
    if ( pButton->IsChecked(this: pButton) == 0 || pButton->IsHighlighted(this: pButton) != 0 )
      return -1;
    if ( CMFCToolBarImages::m_bIsDrawOnGlass == 0 )
    {
      m_rect = pButton->m_rect;
      CMFCToolBarImages::FillDitheredRect(pDC: v8.m_dc, rect: &m_rect);
      return -1;
    }
    CDrawingManager::CDrawingManager(this: &v6, m_dc: pDC);
    rect.left = pButton->m_rect.left;
    rect.top = pButton->m_rect.top;
    rect.right = pButton->m_rect.right;
    v12 = 2;
    rect.bottom = pButton->m_rect.bottom;
    CDrawingManager::DrawRect(this: &v6, (int)&rect, clrFill: afxGlobalData.clrWindow, clrLine: 0xFFFFFFFF);
    v3 = &v6;
    goto LABEL_17;
  }
  if ( pButton->IsHighlighted(this: pButton) != 0 )
  {
    rect.left = pButton->m_rect.left;
    rect.top = pButton->m_rect.top;
    m_hDC = v8.m_dc->m_hDC;
    rect.right = pButton->m_rect.right;
    rect.bottom = pButton->m_rect.bottom;
    FillRect(hDC: m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
    return afxGlobalData.clrTextHilite;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10377573
// Name: public: virtual void CMFCVisualManager::OnFillRibbonEdit(class CDC __near *,class CMFCRibbonRichEditCtrl __near *,class CRect,int,int,int,unsigned long __near &,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillRibbonEdit(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonRichEditCtrl *__formal,
        CRect rect,
        int bIsHighlighted,
        int a6,
        int bIsDisabled,
        unsigned int *a8,
        unsigned int *a9,
        unsigned int *a10)
{
  CDrawingManager *p_dm; // ecx
  CDrawingManager dm; // [esp+10h] [ebp-1Ch] BYREF
  CDrawingManager v12; // [esp+18h] [ebp-14h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  if ( bIsHighlighted == 0 || bIsDisabled != 0 )
  {
    CDrawingManager::CDrawingManager(this: &v12, m_dc: pDC);
    v13 = 1;
    if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
    {
      CDrawingManager::DrawRect(this: &v12, (int)&rect, clrFill: afxGlobalData.clrBarFace, clrLine: 0xFFFFFFFF);
    }
    else
    {
      FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
      CDrawingManager::HighlightRect(
        this: &v12,
        rect,
        nPercentage: -1,
        clrTransparent: -1,
        nTolerance: 0,
        clrBlend: 0xFFFFFFFF);
    }
    p_dm = &v12;
  }
  else
  {
    if ( CMFCToolBarImages::m_bIsDrawOnGlass == 0 )
    {
      FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
      return;
    }
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v13 = 0;
    CDrawingManager::DrawRect(this: &dm, (int)&rect, clrFill: afxGlobalData.clrWindow, clrLine: 0xFFFFFFFF);
    p_dm = &dm;
  }
  v13 = -1;
  CDrawingManager::~CDrawingManager(this: p_dm);
}

//------------------------------------------------------------------------------
// Address: 0x1037763D
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonMenuCheckFrame(class CDC __near *,class CMFCRibbonButton __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonMenuCheckFrame(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *__formal,
        CRect rect)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBtnShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
}

//------------------------------------------------------------------------------
// Address: 0x10377675
// Name: public: virtual void CMFCVisualManager::OnFillRibbonMenuFrame(class CDC __near *,class CMFCRibbonMainPanel __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillRibbonMenuFrame(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonMainPanel *__formal,
        CRect rect)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x10377694
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonRecentFilesFrame(class CDC __near *,class CMFCRibbonMainPanel __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonRecentFilesFrame(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonMainPanel *__formal,
        CRect rect)
{
  CRect rectSeparator; // [esp+Ch] [ebp-14h] BYREF

  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  rectSeparator.left = rect.left;
  rectSeparator.top = rect.top;
  rectSeparator.bottom = rect.bottom;
  rectSeparator.right = rect.left + 2;
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectSeparator,
    clrTopLeft: afxGlobalData.clrBtnShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
}

//------------------------------------------------------------------------------
// Address: 0x103776FA
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonProgressBar(class CDC __near *,class CMFCRibbonProgressBar __near *,class CRect,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonProgressBar(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonProgressBar *__formal,
        CRect rectProgress,
        CRect rectChunk,
        int a6)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v7 = 0;
    if ( !IsRectEmpty(lprc: &rectChunk) )
      CDrawingManager::DrawRect(this: &dm, rect: (int)&rectChunk, clrFill: afxGlobalData.clrHilite, clrLine: 0xFFFFFFFF);
    CDrawingManager::DrawRect(
      this: &dm,
      rect: (int)&rectProgress,
      clrFill: 0xFFFFFFFF,
      clrLine: afxGlobalData.clrBarShadow);
    v7 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
  else
  {
    if ( !IsRectEmpty(lprc: &rectChunk) )
      FillRect(hDC: pDC->m_hDC, lprc: &rectChunk, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectProgress,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103777A3
// Name: public: virtual void CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup(class CDC __near *,class CMFCRibbonPanelMenuBar __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonPanelMenuBar *__formal,
        CRect rect)
{
  FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x103777C2
// Name: public: virtual unsigned long CMFCVisualManager::OnDrawPropertySheetListItem(class CDC __near *,class CMFCPropertySheet __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnDrawPropertySheetListItem(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCPropertySheet *__formal,
        CRect rect,
        int bIsHighlihted,
        int bIsSelected)
{
  unsigned int clrTextHilite; // edi

  clrTextHilite = -1;
  if ( bIsSelected != 0 )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)afxGlobalData.brHilite.m_hObject);
    clrTextHilite = afxGlobalData.clrTextHilite;
  }
  if ( bIsHighlihted != 0 )
    DrawFocusRect(hDC: pDC->m_hDC, lprc: &rect);
  return clrTextHilite;
}

//------------------------------------------------------------------------------
// Address: 0x10377809
// Name: public: virtual CMFCBaseVisualManager::~CMFCBaseVisualManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseVisualManager::~CMFCBaseVisualManager(CMFCBaseVisualManager *this)
{
  bool v2; // zf

  v2 = this->m_hinstUXDLL == nullptr;
  this->__vftable = (CMFCBaseVisualManager_vtbl *)&CMFCBaseVisualManager::`vftable';
  if ( !v2 )
  {
    CMFCBaseVisualManager::CleanUpThemes(this);
    FreeLibrary(hLibModule: this->m_hinstUXDLL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037782A
// Name: protected: void CMFCBaseVisualManager::UpdateSystemColors(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseVisualManager::UpdateSystemColors(CMFCBaseVisualManager *this)
{
  HWND__ *MainWnd; // eax
  HWND__ *v3; // eax
  HWND__ *v4; // eax
  HWND__ *v5; // eax
  HWND__ *v6; // eax
  HWND__ *v7; // eax
  HWND__ *v8; // eax
  HWND__ *v9; // eax
  HWND__ *v10; // eax
  HWND__ *v11; // eax
  HWND__ *v12; // eax
  HWND__ *v13; // eax
  HWND__ *v14; // eax
  HWND__ *v15; // eax
  HWND__ *v16; // eax
  HWND__ *v17; // eax
  HWND__ *v18; // eax
  HWND__ *v19; // eax

  if ( this->m_hinstUXDLL != nullptr )
  {
    CMFCBaseVisualManager::CleanUpThemes(this);
    if ( this->m_pfOpenThemeData != nullptr
      && this->m_pfCloseThemeData != nullptr
      && this->m_pfDrawThemeBackground != nullptr )
    {
      MainWnd = (HWND__ *)AfxGetMainWnd();
      if ( MainWnd != nullptr )
        MainWnd = *((HWND__ **)MainWnd + 8);
      this->m_hThemeWindow = this->m_pfOpenThemeData(a1: MainWnd, a2: L"WINDOW");
      v3 = (HWND__ *)AfxGetMainWnd();
      if ( v3 != nullptr )
        v3 = *((HWND__ **)v3 + 8);
      this->m_hThemeToolBar = this->m_pfOpenThemeData(a1: v3, a2: L"TOOLBAR");
      v4 = (HWND__ *)AfxGetMainWnd();
      if ( v4 != nullptr )
        v4 = *((HWND__ **)v4 + 8);
      this->m_hThemeButton = this->m_pfOpenThemeData(a1: v4, a2: L"BUTTON");
      v5 = (HWND__ *)AfxGetMainWnd();
      if ( v5 != nullptr )
        v5 = *((HWND__ **)v5 + 8);
      this->m_hThemeStatusBar = this->m_pfOpenThemeData(a1: v5, a2: L"STATUS");
      v6 = (HWND__ *)AfxGetMainWnd();
      if ( v6 != nullptr )
        v6 = *((HWND__ **)v6 + 8);
      this->m_hThemeRebar = this->m_pfOpenThemeData(a1: v6, a2: L"REBAR");
      v7 = (HWND__ *)AfxGetMainWnd();
      if ( v7 != nullptr )
        v7 = *((HWND__ **)v7 + 8);
      this->m_hThemeComboBox = this->m_pfOpenThemeData(a1: v7, a2: L"COMBOBOX");
      v8 = (HWND__ *)AfxGetMainWnd();
      if ( v8 != nullptr )
        v8 = *((HWND__ **)v8 + 8);
      this->m_hThemeProgress = this->m_pfOpenThemeData(a1: v8, a2: L"PROGRESS");
      v9 = (HWND__ *)AfxGetMainWnd();
      if ( v9 != nullptr )
        v9 = *((HWND__ **)v9 + 8);
      this->m_hThemeHeader = this->m_pfOpenThemeData(a1: v9, a2: L"HEADER");
      v10 = (HWND__ *)AfxGetMainWnd();
      if ( v10 != nullptr )
        v10 = *((HWND__ **)v10 + 8);
      this->m_hThemeScrollBar = this->m_pfOpenThemeData(a1: v10, a2: L"SCROLLBAR");
      v11 = (HWND__ *)AfxGetMainWnd();
      if ( v11 != nullptr )
        v11 = *((HWND__ **)v11 + 8);
      this->m_hThemeExplorerBar = this->m_pfOpenThemeData(a1: v11, a2: L"EXPLORERBAR");
      v12 = (HWND__ *)AfxGetMainWnd();
      if ( v12 != nullptr )
        v12 = *((HWND__ **)v12 + 8);
      this->m_hThemeTree = this->m_pfOpenThemeData(a1: v12, a2: L"TREEVIEW");
      v13 = (HWND__ *)AfxGetMainWnd();
      if ( v13 != nullptr )
        v13 = *((HWND__ **)v13 + 8);
      this->m_hThemeStartPanel = this->m_pfOpenThemeData(a1: v13, a2: L"STARTPANEL");
      v14 = (HWND__ *)AfxGetMainWnd();
      if ( v14 != nullptr )
        v14 = *((HWND__ **)v14 + 8);
      this->m_hThemeTaskBand = this->m_pfOpenThemeData(a1: v14, a2: L"TASKBAND");
      v15 = (HWND__ *)AfxGetMainWnd();
      if ( v15 != nullptr )
        v15 = *((HWND__ **)v15 + 8);
      this->m_hThemeTaskBar = this->m_pfOpenThemeData(a1: v15, a2: L"TASKBAR");
      v16 = (HWND__ *)AfxGetMainWnd();
      if ( v16 != nullptr )
        v16 = *((HWND__ **)v16 + 8);
      this->m_hThemeSpin = this->m_pfOpenThemeData(a1: v16, a2: L"SPIN");
      v17 = (HWND__ *)AfxGetMainWnd();
      if ( v17 != nullptr )
        v17 = *((HWND__ **)v17 + 8);
      this->m_hThemeTab = this->m_pfOpenThemeData(a1: v17, a2: L"TAB");
      v18 = (HWND__ *)AfxGetMainWnd();
      if ( v18 != nullptr )
        v18 = *((HWND__ **)v18 + 8);
      this->m_hThemeTrack = this->m_pfOpenThemeData(a1: v18, a2: L"TRACKBAR");
      v19 = (HWND__ *)AfxGetMainWnd();
      if ( v19 != nullptr )
        v19 = *((HWND__ **)v19 + 8);
      this->m_hThemeMenu = this->m_pfOpenThemeData(a1: v19, a2: L"MENU");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10377A0E
// Name: public: virtual int CMFCBaseVisualManager::DrawPushButton(class CDC __near *,class CRect,class CMFCButton __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseVisualManager::DrawPushButton(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCButton *pButton,
        unsigned int __formal)
{
  CMFCButton *v5; // ebx
  HWND Focus; // eax
  HRESULT (__stdcall *m_pfDrawThemeBackground)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *); // ecx
  HDC__ *m_hDC; // edx
  int nState; // [esp+14h] [ebp-4h]

  v5 = pButton;
  if ( this->m_hThemeButton == nullptr )
    return 0;
  nState = 1;
  if ( CWnd::IsWindowEnabled(this: pButton) != 0 )
  {
    if ( CMFCButton::IsPressed(this: v5) != 0 || SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
    {
      nState = 3;
    }
    else if ( v5->m_bHighlighted != 0 )
    {
      nState = 2;
    }
    else
    {
      Focus = GetFocus();
      if ( CWnd::FromHandle(hWnd: Focus) == v5 )
        nState = 5;
    }
  }
  else
  {
    nState = 4;
  }
  ((void (__thiscall *)(CMFCButton *, CDC *, int, int, int, int))v5->OnDrawParentBackground)(
    a1: v5,
    a2: pDC,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom);
  m_pfDrawThemeBackground = this->m_pfDrawThemeBackground;
  if ( m_pfDrawThemeBackground != nullptr )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    m_pfDrawThemeBackground(a1: this->m_hThemeButton, a2: m_hDC, a3: 1, a4: nState, a5: &rect, a6: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10377AEA
// Name: public: virtual int CMFCBaseVisualManager::DrawComboDropButton(class CDC __near *,class CRect,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseVisualManager::DrawComboDropButton(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bDisabled,
        int bIsDropped,
        int bIsHighlighted)
{
  void *m_hThemeComboBox; // esi
  int v8; // edx
  HRESULT (__stdcall *m_pfDrawThemeBackground)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *); // eax
  HDC__ *m_hDC; // ecx
  int v11; // [esp-4h] [ebp-Ch]

  m_hThemeComboBox = this->m_hThemeComboBox;
  if ( m_hThemeComboBox == nullptr )
    return 0;
  if ( bDisabled != 0 )
  {
    v11 = 4;
  }
  else
  {
    if ( bIsDropped == 0 )
    {
      v8 = (bIsHighlighted != 0) + 1;
      goto LABEL_9;
    }
    v11 = 3;
  }
  v8 = v11;
LABEL_9:
  m_pfDrawThemeBackground = this->m_pfDrawThemeBackground;
  if ( m_pfDrawThemeBackground != nullptr )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    m_pfDrawThemeBackground(a1: m_hThemeComboBox, a2: m_hDC, a3: 1, a4: v8, a5: &rect, a6: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10377B46
// Name: public: virtual void CMFCBaseVisualManager::FillReBarPane(class CDC __near *,class CBasePane __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseVisualManager::FillReBarPane(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CBasePane *pBar,
        CRect rectClient)
{
  CMFCBaseVisualManager *v4; // ebx
  CFrameWnd *v5; // eax
  HWND Parent; // eax
  CFrameWnd *TopLevelFrame; // ebx
  HWND m_hWnd; // eax
  HRESULT (__stdcall *m_pfDrawThemeBackground)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *); // ecx
  HDC__ *m_hDC; // eax
  CWnd *pWndParent; // [esp+14h] [ebp-28h]
  CRect rectMain; // [esp+18h] [ebp-24h] BYREF
  CRect rectParent; // [esp+28h] [ebp-14h] BYREF

  v4 = this;
  if ( this->m_pfDrawThemeBackground != nullptr && this->m_hThemeRebar != nullptr )
  {
    v5 = AFXGetParentFrame(pWnd: pBar);
    pWndParent = v5;
    if ( v5 == nullptr || v5->m_hWnd == nullptr )
    {
      Parent = GetParent(hWnd: pBar->m_hWnd);
      v5 = (CFrameWnd *)CWnd::FromHandle(hWnd: Parent);
      pWndParent = v5;
    }
    memset(&rectParent, 0, sizeof(rectParent));
    GetWindowRect(hWnd: v5->m_hWnd, lpRect: &rectParent);
    CWnd::ScreenToClient(this: pBar, lpRect: (tagPOINT *)&rectParent);
    if ( rectClient.right <= rectParent.right )
      rectClient.right = rectParent.right;
    if ( rectClient.bottom <= rectParent.bottom )
      rectClient.bottom = rectParent.bottom;
    if ( pBar->IsFloating(this: pBar) == 0 && pBar->GetParentMiniFrame(this: pBar, a2: 0) == nullptr )
    {
      rectClient.left = rectParent.left;
      rectClient.top = rectParent.top;
      if ( CObject::IsKindOf(this: pBar, pClass: &CDockSite::classCDockSite) == 0 )
      {
        TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
        if ( g_pTopLevelFrame != nullptr || (TopLevelFrame = CWnd::GetTopLevelFrame(this: pWndParent)) != nullptr )
        {
          m_hWnd = TopLevelFrame->m_hWnd;
          if ( m_hWnd != nullptr )
          {
            memset(&rectMain, 0, sizeof(rectMain));
            GetClientRect(hWnd: m_hWnd, lpRect: &rectMain);
            MapWindowPoints(
              hWndFrom: TopLevelFrame->m_hWnd,
              hWndTo: pBar->m_hWnd,
              lpPoints: (LPPOINT)&rectMain,
              cPoints: 2u);
            rectClient.top = rectMain.top;
          }
        }
        v4 = this;
      }
    }
    m_pfDrawThemeBackground = v4->m_pfDrawThemeBackground;
    if ( m_pfDrawThemeBackground != nullptr )
    {
      if ( pDC != nullptr )
        m_hDC = pDC->m_hDC;
      else
        m_hDC = nullptr;
      m_pfDrawThemeBackground(a1: v4->m_hThemeRebar, a2: m_hDC, a3: 0, a4: 0, a5: &rectClient, a6: nullptr);
    }
  }
  else
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectClient, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10377CAF
// Name: public: virtual int CMFCBaseVisualManager::DrawCheckBox(class CDC __near *,class CRect,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseVisualManager::DrawCheckBox(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bHighlighted,
        int nState,
        int bEnabled,
        int bPressed)
{
  void *m_hThemeButton; // ebx
  int v9; // eax
  int v10; // edx
  HRESULT (__stdcall *m_pfDrawThemeBackground)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *); // ecx
  HDC__ *m_hDC; // eax
  int v13; // [esp-8h] [ebp-10h]

  m_hThemeButton = this->m_hThemeButton;
  if ( m_hThemeButton == nullptr )
    return 0;
  v9 = nState;
  if ( nState < 0 )
    v9 = 0;
  if ( v9 > 2 )
    v9 = 2;
  if ( v9 == 1 )
    v10 = 5;
  else
    v10 = 8 * (v9 == 2) + 1;
  if ( bEnabled != 0 )
  {
    if ( bPressed != 0 )
    {
      if ( v9 == 1 )
      {
        v13 = 7;
        goto LABEL_21;
      }
      v10 = 8 * (v9 == 2) + 3;
    }
    else if ( bHighlighted != 0 )
    {
      if ( v9 != 1 )
      {
        v10 = 8 * (v9 == 2) + 2;
        goto LABEL_23;
      }
      v13 = 6;
      goto LABEL_21;
    }
  }
  else
  {
    if ( v9 == 1 )
    {
      v13 = 8;
LABEL_21:
      v10 = v13;
      goto LABEL_23;
    }
    v10 = 8 * (v9 == 2) + 4;
  }
LABEL_23:
  m_pfDrawThemeBackground = this->m_pfDrawThemeBackground;
  if ( m_pfDrawThemeBackground != nullptr )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    m_pfDrawThemeBackground(a1: m_hThemeButton, a2: m_hDC, a3: 3, a4: v10, a5: &rect, a6: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10377D77
// Name: public: virtual int CMFCBaseVisualManager::DrawRadioButton(class CDC __near *,class CRect,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseVisualManager::DrawRadioButton(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bHighlighted,
        int bChecked,
        int bEnabled,
        int bPressed)
{
  void *m_hThemeButton; // ebx
  int v9; // edx
  HRESULT (__stdcall *m_pfDrawThemeBackground)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *); // eax
  HDC__ *m_hDC; // ecx

  m_hThemeButton = this->m_hThemeButton;
  if ( m_hThemeButton == nullptr )
    return 0;
  v9 = 4 * (bChecked != 0) + 1;
  if ( bEnabled != 0 )
  {
    if ( bPressed != 0 )
    {
      v9 = 4 * (bChecked != 0) + 3;
    }
    else if ( bHighlighted != 0 )
    {
      v9 = 4 * (bChecked != 0) + 2;
    }
  }
  else
  {
    v9 = 4 * (bChecked != 0) + 4;
  }
  m_pfDrawThemeBackground = this->m_pfDrawThemeBackground;
  if ( m_pfDrawThemeBackground != nullptr )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    m_pfDrawThemeBackground(a1: m_hThemeButton, a2: m_hDC, a3: 2, a4: v9, a5: &rect, a6: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10377E07
// Name: public: struct __POSITION __near * CList<struct tagPOINT,struct tagPOINT>::AddHead(struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<tagPOINT,tagPOINT>::CNode *__thiscall CList<tagPOINT,tagPOINT>::AddHead(
        CList<tagPOINT,tagPOINT> *this,
        tagPOINT newElement)
{
  CList<tagPOINT,tagPOINT>::CNode *result; // eax
  CList<tagPOINT,tagPOINT>::CNode *m_pNodeHead; // ecx

  result = CList<tagPOINT,tagPOINT>::NewNode(this, pPrev: nullptr, pNext: this->m_pNodeHead);
  result->data = newElement;
  m_pNodeHead = this->m_pNodeHead;
  if ( m_pNodeHead != nullptr )
    m_pNodeHead->pPrev = result;
  else
    this->m_pNodeTail = result;
  this->m_pNodeHead = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10377E3C
// Name: public: struct __POSITION __near * CList<struct tagPOINT,struct tagPOINT>::AddTail(struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<tagPOINT,tagPOINT>::CNode *__thiscall CList<tagPOINT,tagPOINT>::AddTail(
        CList<tagPOINT,tagPOINT> *this,
        tagPOINT newElement)
{
  CList<tagPOINT,tagPOINT>::CNode *result; // eax
  CList<tagPOINT,tagPOINT>::CNode *m_pNodeTail; // ecx

  result = CList<tagPOINT,tagPOINT>::NewNode(this, pPrev: this->m_pNodeTail, pNext: nullptr);
  result->data = newElement;
  m_pNodeTail = this->m_pNodeTail;
  if ( m_pNodeTail != nullptr )
    m_pNodeTail->pNext = result;
  else
    this->m_pNodeHead = result;
  this->m_pNodeTail = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10377E70
// Name: public: struct __POSITION __near * CList<struct tagPOINT,struct tagPOINT>::InsertBefore(struct __POSITION __near *,struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<tagPOINT,tagPOINT>::CNode *__thiscall CList<tagPOINT,tagPOINT>::InsertBefore(
        CList<tagPOINT,tagPOINT> *this,
        __POSITION *position,
        tagPOINT newElement)
{
  CList<tagPOINT,tagPOINT>::CNode *result; // eax
  CList<tagPOINT,tagPOINT>::CNode **v5; // ecx

  if ( position == nullptr )
    return CList<tagPOINT,tagPOINT>::AddHead(this, newElement);
  result = CList<tagPOINT,tagPOINT>::NewNode(
             this,
             pPrev: *(CList<tagPOINT,tagPOINT>::CNode **)&position[4],
             pNext: (CList<tagPOINT,tagPOINT>::CNode *)position);
  result->data = newElement;
  v5 = *(CList<tagPOINT,tagPOINT>::CNode ***)&position[4];
  if ( v5 != nullptr )
    *v5 = result;
  else
    this->m_pNodeHead = result;
  *(_DWORD *)&position[4] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10377EB9
// Name: public: struct __POSITION __near * CList<struct tagPOINT,struct tagPOINT>::InsertAfter(struct __POSITION __near *,struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<tagPOINT,tagPOINT>::CNode *__thiscall CList<tagPOINT,tagPOINT>::InsertAfter(
        CList<tagPOINT,tagPOINT> *this,
        __POSITION *position,
        tagPOINT newElement)
{
  CList<tagPOINT,tagPOINT>::CNode *result; // eax

  if ( position == nullptr )
    return CList<tagPOINT,tagPOINT>::AddTail(this, newElement);
  result = CList<tagPOINT,tagPOINT>::NewNode(
             this,
             pPrev: (CList<tagPOINT,tagPOINT>::CNode *)position,
             pNext: *(CList<tagPOINT,tagPOINT>::CNode **)position);
  result->data = newElement;
  if ( *(_DWORD *)position != 0 )
    *(_DWORD *)(*(_DWORD *)position + 4) = result;
  else
    this->m_pNodeTail = result;
  *(_DWORD *)position = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10377F00
// Name: public: virtual CList<struct tagPOINT,struct tagPOINT>::~CList<struct tagPOINT,struct tagPOINT>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<tagPOINT,tagPOINT>::~CList<tagPOINT,tagPOINT>(CList<tagPOINT,tagPOINT> *this)
{
  this->__vftable = (CList<tagPOINT,tagPOINT>_vtbl *)&CList<tagPOINT,tagPOINT>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103A5907
// Name: public: CMFCButton::CMFCButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCButton *__thiscall CMFCButton::CMFCButton(CMFCButton *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCButton_vtbl *)&CMFCButton::`vftable';
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_sizePushOffset.cx = 0;
  this->m_sizePushOffset.cy = 0;
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_Image);
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_ImageHot);
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_ImageDisabled);
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_ImageChecked);
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_ImageCheckedHot);
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_ImageCheckedDisabled);
  this->m_sizeImage.cx = 0;
  this->m_nAlignStyle = ALIGN_RIGHT;
  this->m_sizePushOffset.cy = 2;
  this->m_bPushed = 0;
  this->m_bClickiedInside = 0;
  this->m_bHighlighted = 0;
  this->m_bCaptured = 0;
  this->m_nFlatStyle = BUTTONSTYLE_3D;
  this->m_sizeImage.cy = 0;
  this->m_nStdImageId = -1;
  this->m_nStdImageDisabledId = -1;
  this->m_StdImageState = ImageBlack;
  this->m_bFullTextTooltip = 0;
  this->m_bRightImage = 0;
  this->m_bTopImage = 0;
  this->m_hCursor = nullptr;
  this->m_sizePushOffset.cx = 2;
  this->m_bHover = 0;
  this->m_clrRegular = -1;
  this->m_clrHover = -1;
  this->m_clrFace = -1;
  this->m_bDrawFocus = 1;
  this->m_bTransparent = 0;
  this->m_hFont = nullptr;
  this->m_bDelayFullTextTooltipSet = 0;
  this->m_bGrayDisabled = 1;
  this->m_bChecked = 0;
  this->m_bCheckButton = 0;
  this->m_bRadioButton = 0;
  this->m_bAutoCheck = 0;
  this->m_bHighlightChecked = 1;
  this->m_nAutoRepeatTimeDelay = 0;
  this->m_bResponseOnButtonDown = 0;
  this->m_bDontUseWinXPTheme = 0;
  this->m_bWasDblClk = 0;
  this->m_pToolTip = nullptr;
  this->m_bEnableActiveAccessibility = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A5A7C
// Name: public: virtual CMFCButton::~CMFCButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::~CMFCButton(CMFCButton *this)
{
  this->__vftable = (CMFCButton_vtbl *)&CMFCButton::`vftable';
  CMFCButton::CleanUp(this);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_ImageCheckedDisabled);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_ImageCheckedHot);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_ImageChecked);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_ImageDisabled);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_ImageHot);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_Image);
  CButton::~CButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A5B0A
// Name: protected: void CMFCButton::InitStyle(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::InitStyle(CMFCButton *this, __int16 dwStyle)
{
  int v2; // edx

  switch ( dwStyle & 0xF )
  {
    case 2:
      goto LABEL_8;
    case 3:
      this->m_bAutoCheck = 1;
LABEL_8:
      this->m_bCheckButton = 1;
      break;
    case 4:
LABEL_6:
      this->m_bRadioButton = 1;
      break;
    case 9:
      this->m_bAutoCheck = 1;
      goto LABEL_6;
    default:
      break;
  }
  if ( this->m_bCheckButton != 0 || this->m_bRadioButton != 0 )
  {
    v2 = dwStyle & 0x300;
    switch ( v2 )
    {
      case 256:
        this->m_nAlignStyle = ALIGN_INVALID;
        break;
      case 512:
        this->m_nAlignStyle = ALIGN_LEFT;
        break;
      case 768:
        this->m_nAlignStyle = ALIGN_RIGHT;
        break;
      default:
        break;
    }
  }
  if ( CMFCButton::m_bWinXPThemeWasChecked == 0 )
  {
    if ( CMFCButton::m_bWinXPTheme == 0 )
      CMFCButton::m_bWinXPTheme = AfxGetModuleState()->m_hCurrentResourceHandle != nullptr;
    CMFCButton::m_bWinXPThemeWasChecked = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A5BB2
// Name: protected: virtual void CMFCButton::OnFillBackground(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnFillBackground(CMFCButton *this, CWnd *pDC, const CRect *rectClient)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  if ( this->m_bTransparent != 0 )
  {
    AFX_GLOBAL_DATA::DrawParentBackground(this: &afxGlobalData, pWnd: this, pDC, rectClip: nullptr);
  }
  else if ( this->m_clrFace == -1 )
  {
    FillRect(hDC: (HDC)pDC->m_dwRef, lprc: rectClient, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  }
  else
  {
    CDC::FillSolidRect(this: (CDC *)pDC, lpRect: rectClient, clr: this->m_clrFace);
  }
  if ( this->m_bChecked != 0 && this->m_bHighlightChecked != 0 && (this->m_bPushed == 0 || this->m_bHighlighted == 0) )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: (CDC *)pDC);
    v5 = 0;
    CDrawingManager::HighlightRect(
      this: &dm,
      rect: *rectClient,
      nPercentage: -1,
      clrTransparent: -1,
      nTolerance: 0,
      clrBlend: 0xFFFFFFFF);
    v5 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A5C66
// Name: protected: void CMFCButton::SetImageInternal(struct HICON__ __near *,int,struct HICON__ __near *,int,struct HICON__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetImageInternal(
        CMFCButton *this,
        HICON hIconCold,
        int bAutoDestroy,
        HICON hIconHot,
        int bChecked,
        HICON hIconDisabled,
        int bAlphaBlend)
{
  int v8; // ebx
  HICON v9; // eax
  CMFCToolBarImages *p_m_ImageCheckedHot; // eax
  HDC CompatibleDC; // eax
  HANDLE v12; // eax
  HGDIOBJ v13; // eax
  int cx; // ecx
  void *v15; // ebx
  CMFCToolBarImages *v16; // edx
  char pv[4]; // [esp+10h] [ebp-7Ch] BYREF
  CSize v18; // [esp+14h] [ebp-78h]
  _ICONINFO piconinfo; // [esp+28h] [ebp-64h] BYREF
  CDC v20; // [esp+3Ch] [ebp-50h] BYREF
  HGDIOBJ ho; // [esp+4Ch] [ebp-40h]
  int v22; // [esp+50h] [ebp-3Ch]
  HICON v23; // [esp+54h] [ebp-38h]
  int v24; // [esp+58h] [ebp-34h]
  HICON v25; // [esp+5Ch] [ebp-30h]
  CMFCToolBarImages *v26; // [esp+60h] [ebp-2Ch]
  HICON v27; // [esp+64h] [ebp-28h]
  HICON hIcon; // [esp+68h] [ebp-24h]
  RECT rc; // [esp+6Ch] [ebp-20h] BYREF
  int v30; // [esp+88h] [ebp-4h]

  v25 = hIconHot;
  v23 = hIconCold;
  v27 = hIconDisabled;
  CMFCButton::ClearImages(this, bChecked);
  if ( hIconCold != nullptr )
  {
    v8 = 0;
    v22 = 0;
    v24 = (v27 != nullptr) + 2;
    if ( (v27 != nullptr) != -2 )
    {
      do
      {
        if ( v8 != 0 )
        {
          v9 = v25;
          if ( v8 != 1 )
            v9 = v27;
        }
        else
        {
          v9 = v23;
        }
        hIcon = v9;
        if ( bChecked != 0 )
        {
          if ( v8 != 0 )
          {
            p_m_ImageCheckedHot = &this->m_ImageCheckedHot;
            if ( v8 != 1 )
              p_m_ImageCheckedHot = &this->m_ImageCheckedDisabled;
          }
          else
          {
            p_m_ImageCheckedHot = &this->m_ImageChecked;
          }
        }
        else if ( v8 != 0 )
        {
          p_m_ImageCheckedHot = &this->m_ImageHot;
          if ( v8 != 1 )
            p_m_ImageCheckedHot = &this->m_ImageDisabled;
        }
        else
        {
          p_m_ImageCheckedHot = &this->m_Image;
        }
        v26 = p_m_ImageCheckedHot;
        if ( hIcon != nullptr )
        {
          GetIconInfo(hIcon, &piconinfo);
          GetObjectA(h: piconinfo.hbmColor, c: 24, pv);
          this->m_sizeImage = v18;
          if ( v8 == 0 )
          {
            CDC::CDC(this: &v20);
            v30 = 0;
            CompatibleDC = CreateCompatibleDC(hdc: nullptr);
            CDC::Attach(this: &v20, hDC: CompatibleDC);
            v12 = CopyImage(h: piconinfo.hbmColor, type: 0, cx: 0, cy: 0, flags: 0x2000u);
            ho = v12;
            if ( v12 != nullptr )
            {
              v13 = SelectObject(hdc: v20.m_hDC, h: v12);
              cx = this->m_sizeImage.cx;
              v15 = v13;
              rc.bottom = this->m_sizeImage.cy;
              rc.left = 0;
              rc.top = 0;
              rc.right = cx;
              FillRect(hDC: v20.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
              DrawIconEx(
                hdc: v20.m_hDC,
                xLeft: 0,
                yTop: 0,
                hIcon,
                cxWidth: this->m_sizeImage.cx,
                cyWidth: this->m_sizeImage.cy,
                istepIfAniCur: 0,
                hbrFlickerFreeDraw: nullptr,
                diFlags: 3u);
              if ( v15 != nullptr )
                SelectObject(hdc: v20.m_hDC, h: v15);
              DeleteObject(ho);
              v8 = v22;
            }
            v30 = -1;
            CDC::~CDC(this: &v20);
          }
          DeleteObject(ho: piconinfo.hbmColor);
          DeleteObject(ho: piconinfo.hbmMask);
          v16 = v26;
          v26->m_sizeImage = v18;
          if ( bAlphaBlend == 0 )
          {
            CMFCToolBarImages::SetTransparentColor(this: v16, clrTransparent: afxGlobalData.clrBtnFace);
            v16 = v26;
          }
          CMFCToolBarImages::AddIcon(this: v16, hIcon, bAlphaBlend);
        }
        v22 = ++v8;
      }
      while ( v8 < v24 );
    }
    if ( bAutoDestroy != 0 )
    {
      DestroyIcon(hIcon: v23);
      if ( v25 != nullptr )
        DestroyIcon(hIcon: v25);
      if ( v27 != nullptr )
        DestroyIcon(hIcon: v27);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A5E77
// Name: protected: void CMFCButton::SetImageInternal(struct HBITMAP__ __near *,int,struct HBITMAP__ __near *,int,int,struct HBITMAP__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetImageInternal(
        CMFCButton *this,
        HBITMAP__ *hBitmapCold,
        int bAutoDestroy,
        HBITMAP__ *hBitmapHot,
        int bMap3dColors,
        int bChecked,
        HBITMAP__ *hBitmapDisabled)
{
  CMFCButton *v7; // esi
  int v8; // edi
  int v9; // eax
  HBITMAP__ *v10; // ecx
  CMFCToolBarImages *p_m_ImageCheckedHot; // eax
  bool v12; // zf
  CMFCToolBarImages *v13; // esi
  CBasePane *v14; // ecx
  int v15; // ebx
  CMFCButton *v16; // eax
  unsigned int clrBtnFace; // eax
  tagBITMAP bmp; // [esp+8h] [ebp-28h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  CMFCButton *v20; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  HBITMAP__ *hBitmap; // [esp+2Ch] [ebp-4h]

  v7 = this;
  v20 = this;
  CMFCButton::ClearImages(this, bChecked);
  v8 = 0;
  if ( hBitmapCold != nullptr )
  {
    nCount = (hBitmapDisabled != nullptr) + 2;
    v9 = 0;
    i = 0;
    if ( (hBitmapDisabled != nullptr) != -2 )
    {
      while ( 1 )
      {
        if ( v9 != 0 )
        {
          v10 = hBitmapHot;
          if ( v9 != 1 )
            v10 = hBitmapDisabled;
        }
        else
        {
          v10 = hBitmapCold;
        }
        hBitmap = v10;
        if ( bChecked != 0 )
        {
          if ( v9 != 0 )
          {
            v12 = v9 == 1;
            p_m_ImageCheckedHot = &v7->m_ImageCheckedHot;
            if ( !v12 )
              p_m_ImageCheckedHot = &v7->m_ImageCheckedDisabled;
          }
          else
          {
            p_m_ImageCheckedHot = &v7->m_ImageChecked;
          }
        }
        else if ( v9 != 0 )
        {
          v12 = v9 == 1;
          p_m_ImageCheckedHot = &v7->m_ImageHot;
          if ( !v12 )
            p_m_ImageCheckedHot = &v7->m_ImageDisabled;
        }
        else
        {
          p_m_ImageCheckedHot = &v7->m_Image;
        }
        v13 = p_m_ImageCheckedHot;
        if ( hBitmap == nullptr )
          break;
        GetObjectA(h: hBitmap, c: 24, pv: &bmp);
        if ( bMap3dColors != 0 || bmp.bmBitsPixel > 8u && bmp.bmBitsPixel < 0x20u )
        {
          v15 = 1;
          if ( bMap3dColors != 0 )
            goto LABEL_27;
        }
        else
        {
          v15 = 0;
        }
        if ( bmp.bmBitsPixel == 32 && CFrameWnd::IsFrameWnd(this: v14) != 0 )
          v8 = 1;
LABEL_27:
        if ( i == 0 )
        {
          v16 = v20;
          v20->m_sizeImage.cx = bmp.bmWidth;
          v16->m_sizeImage.cy = bmp.bmHeight;
        }
        if ( v8 != 0 )
          CMFCToolBarImages::PreMultiplyAlpha(hbmp: hBitmap, bAutoCheckPremlt: 1);
        v13->m_sizeImage.cx = bmp.bmWidth;
        v13->m_sizeImage.cy = bmp.bmHeight;
        if ( v15 != 0 )
        {
          clrBtnFace = 12632256;
        }
        else if ( v8 != 0 )
        {
          clrBtnFace = -1;
        }
        else
        {
          clrBtnFace = afxGlobalData.clrBtnFace;
        }
        CMFCToolBarImages::SetTransparentColor(this: v13, clrTransparent: clrBtnFace);
        CMFCToolBarImages::AddImage(this: v13, hbmp: hBitmap, bSetBitPerPixel: 1);
        ++i;
        v8 = 0;
        if ( i >= nCount )
          break;
        v7 = v20;
        v9 = i;
      }
    }
    if ( bAutoDestroy != 0 )
    {
      if ( hBitmapHot != nullptr )
        DeleteObject(ho: hBitmapHot);
      DeleteObject(ho: hBitmapCold);
      if ( hBitmapDisabled != nullptr )
        DeleteObject(ho: hBitmapDisabled);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A6000
// Name: ButtonLoadBitmap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBITMAP__ *__stdcall ButtonLoadBitmap(unsigned int uiBmpResId)
{
  HBITMAP__ *result; // eax
  HANDLE ImageA; // eax
  HINSTANCE__ *m_hCurrentResourceHandle; // eax
  HANDLE v4; // esi
  CPngImage pngImage; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  result = nullptr;
  if ( uiBmpResId != 0 )
  {
    LOBYTE(result) = (unsigned __int16)uiBmpResId != 0;
    if ( result == nullptr )
      AfxThrowInvalidArgException();
    CPngImage::CPngImage(this: &pngImage);
    v6 = 0;
    if ( CPngImage::Load(
           this: &pngImage,
           lpszResourceName: (const char *)(unsigned __int16)uiBmpResId,
           hinstRes: nullptr) != 0 )
    {
      ImageA = CGdiObject::Detach(this: &pngImage);
    }
    else
    {
      m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
      if ( m_hCurrentResourceHandle == nullptr )
      {
        v6 = -1;
        CPngImage::~CPngImage(this: &pngImage);
        return nullptr;
      }
      ImageA = LoadImageA(
                 hInst: m_hCurrentResourceHandle,
                 name: (LPCSTR)(unsigned __int16)uiBmpResId,
                 type: 0,
                 cx: 0,
                 cy: 0,
                 fuLoad: 0x3000u);
    }
    v6 = -1;
    v4 = ImageA;
    CPngImage::~CPngImage(this: &pngImage);
    return (HBITMAP__ *)v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A608E
// Name: protected: void CMFCButton::SetImageInternal(unsigned int,unsigned int,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetImageInternal(
        CMFCButton *this,
        unsigned int uiBmpResId,
        unsigned int uiBmpHotResId,
        int bChecked,
        unsigned int uiBmpDsblResID)
{
  HBITMAP__ *Bitmap; // edi
  HBITMAP__ *v7; // ebx
  HBITMAP__ *v8; // eax

  CMFCButton::ClearImages(this, bChecked);
  if ( uiBmpResId != 0 )
  {
    Bitmap = ButtonLoadBitmap(uiBmpResId);
    v7 = ButtonLoadBitmap(uiBmpResId: uiBmpHotResId);
    v8 = ButtonLoadBitmap(uiBmpResId: uiBmpDsblResID);
    CMFCButton::SetImageInternal(
      this,
      hBitmapCold: Bitmap,
      bAutoDestroy: 1,
      hBitmapHot: v7,
      bMap3dColors: 0,
      bChecked,
      hBitmapDisabled: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A60DA
// Name: protected: void CMFCButton::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnCancelMode(CMFCButton *this)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-18h]

  CWnd::Default(this);
  if ( this->m_bCaptured != 0 )
  {
    ReleaseCapture();
    m_hWnd = this->m_hWnd;
    this->m_bCaptured = 0;
    this->m_bPushed = 0;
    this->m_bClickiedInside = 0;
    this->m_bHighlighted = 0;
    this->m_bHover = 0;
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  if ( this->m_nAutoRepeatTimeDelay >= 0 )
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x103A6140
// Name: protected: void CMFCButton::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnMouseMove(CMFCButton *this, char nFlags, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-30h]
  int bRedraw; // [esp+10h] [ebp-18h]
  CRect rectClient; // [esp+14h] [ebp-14h] BYREF

  this->m_bHover = 0;
  if ( (nFlags & 1) == 0
    && this->m_nFlatStyle == BUTTONSTYLE_3D
    && (CMFCButton::m_bWinXPTheme == 0 || this->m_bDontUseWinXPTheme != 0) )
  {
    goto LABEL_26;
  }
  m_hWnd = this->m_hWnd;
  bRedraw = 0;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  if ( PtInRect(lprc: &rectClient, pt: point.tagPOINT) )
  {
    this->m_bHover = 1;
    if ( this->m_bHighlighted == 0 )
    {
      this->m_bHighlighted = 1;
      bRedraw = 1;
    }
    if ( (nFlags & 1) != 0 && this->m_bPushed == 0 && this->m_bClickiedInside != 0 )
    {
      this->m_bPushed = 1;
      bRedraw = 1;
    }
    if ( this->m_bCaptured != 0 )
      goto LABEL_24;
    v4 = SetCapture(hWnd: this->m_hWnd);
    CWnd::FromHandle(hWnd: v4);
    this->m_bCaptured = 1;
    goto LABEL_23;
  }
  if ( (nFlags & 1) != 0 )
  {
    if ( this->m_bPushed != 0 )
    {
      this->m_bPushed = 0;
LABEL_19:
      bRedraw = 1;
    }
  }
  else if ( this->m_bHighlighted != 0 )
  {
    this->m_bHighlighted = 0;
    goto LABEL_19;
  }
  if ( this->m_bCaptured != 0 && (nFlags & 1) == 0 )
  {
    ReleaseCapture();
    this->m_bCaptured = 0;
LABEL_23:
    bRedraw = 1;
  }
LABEL_24:
  if ( bRedraw != 0 )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
LABEL_26:
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A6280
// Name: protected: void CMFCButton::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnLButtonDown(CMFCButton *this, unsigned int nFlags, CPoint point)
{
  HWND Parent; // eax
  CWnd *v5; // edi
  HWND__ *m_hWnd; // ebx
  unsigned __int16 DlgCtrlID; // ax
  bool v8; // zf
  HWND v9; // eax
  signed int m_nAutoRepeatTimeDelay; // eax

  if ( this->m_bResponseOnButtonDown != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    if ( v5 != nullptr )
    {
      m_hWnd = this->m_hWnd;
      DlgCtrlID = CWnd::GetDlgCtrlID(this);
      SendMessageA(hWnd: v5->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
    }
  }
  else
  {
    v8 = this->m_bCaptured == 0;
    this->m_bPushed = 1;
    this->m_bClickiedInside = 1;
    this->m_bHighlighted = 1;
    if ( v8 )
    {
      v9 = SetCapture(hWnd: this->m_hWnd);
      CWnd::FromHandle(hWnd: v9);
      this->m_bCaptured = 1;
    }
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
    m_nAutoRepeatTimeDelay = this->m_nAutoRepeatTimeDelay;
    if ( m_nAutoRepeatTimeDelay > 0 )
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: m_nAutoRepeatTimeDelay, lpTimerFunc: nullptr);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A6330
// Name: public: void CMFCButton::SetTooltip(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetTooltip(CMFCButton *this, char *lpszToolTipText)
{
  CToolTipCtrl *v3; // edi
  CToolTipCtrl **p_m_pToolTip; // esi
  CToolTipCtrl *m_pToolTip; // ecx
  CToolTipCtrl *v6; // esi

  if ( this == nullptr || this->m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  if ( lpszToolTipText != nullptr )
  {
    p_m_pToolTip = &this->m_pToolTip;
    m_pToolTip = this->m_pToolTip;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    {
      CToolTipCtrl::UpdateTipText(this: m_pToolTip, lpszText: lpszToolTipText, pWnd: this, nIDTool: 0);
    }
    else if ( CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 0x40u) != 0 )
    {
      CToolTipCtrl::AddTool(this: *p_m_pToolTip, pWnd: this, lpszText: lpszToolTipText, lpRectTool: nullptr, nIDTool: 0);
    }
    v6 = *p_m_pToolTip;
    if ( v6 != nullptr && v6->m_hWnd != nullptr )
      SendMessageA(hWnd: v6->m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
  }
  else
  {
    v3 = this->m_pToolTip;
    if ( v3 != nullptr && v3->m_hWnd != nullptr )
      SendMessageA(hWnd: v3->m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C4983
// Name: _dynamic_initializer_for___afxThreadState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___afxThreadState__()
{
  return atexit(func: dynamic_atexit_destructor_for___afxThreadState__);
}

//------------------------------------------------------------------------------
// Address: 0x105C498F
// Name: _dynamic_initializer_for___afxBaseModuleState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___afxBaseModuleState__()
{
  return atexit(func: dynamic_atexit_destructor_for___afxBaseModuleState__);
}

//------------------------------------------------------------------------------
// Address: 0x105C499B
// Name: _dynamic_initializer_for___simpleResourceException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___simpleResourceException__()
{
  CException::CException(this: &_simpleResourceException, bAutoDelete: 0);
  _simpleResourceException.m_bInitialized = 0;
  _simpleResourceException.m_bLoaded = 0;
  _simpleResourceException.__vftable = (CResourceException_vtbl *)&CResourceException::`vftable';
  _simpleResourceException.m_nResourceID = 61474;
  return atexit(func: dynamic_atexit_destructor_for___simpleResourceException__);
}

//------------------------------------------------------------------------------
// Address: 0x105C49D5
// Name: _dynamic_initializer_for___simpleUserException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___simpleUserException__()
{
  CException::CException(this: &_simpleUserException, bAutoDelete: 0);
  _simpleUserException.m_bInitialized = 0;
  _simpleUserException.m_bLoaded = 0;
  _simpleUserException.__vftable = (CUserException_vtbl *)&CUserException::`vftable';
  _simpleUserException.m_nResourceID = 61476;
  return atexit(func: dynamic_atexit_destructor_for___simpleUserException__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC15D
// Name: _dynamic_atexit_destructor_for___afxThreadState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxThreadState__()
{
  CThreadLocalObject::~CThreadLocalObject(this: &_afxThreadState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC167
// Name: _dynamic_atexit_destructor_for___afxBaseModuleState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxBaseModuleState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxBaseModuleState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC171
// Name: _dynamic_atexit_destructor_for___simpleResourceException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___simpleResourceException__()
{
  _simpleResourceException.__vftable = (CResourceException_vtbl *)&CSimpleException::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC17C
// Name: _dynamic_atexit_destructor_for___simpleUserException__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___simpleUserException__()
{
  _simpleUserException.__vftable = (CUserException_vtbl *)&CSimpleException::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC187
// Name: _dynamic_atexit_destructor_for___afxWinState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxWinState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxWinState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC191
// Name: _dynamic_atexit_destructor_for___afxRichEditState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxRichEditState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxRichEditState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC19B
// Name: _dynamic_atexit_destructor_for___afxClrState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxClrState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxClrState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1A5
// Name: _dynamic_atexit_destructor_for___afxChecklistState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxChecklistState__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxChecklistState);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1AF
// Name: _dynamic_atexit_destructor_for__afxData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__afxData__()
{
  AUX_DATA::~AUX_DATA(this: &afxData);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1B9
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1C7
// Name: _dynamic_atexit_destructor_for__strOfficeFontName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strOfficeFontName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strOfficeFontName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1D5
// Name: _dynamic_atexit_destructor_for__strOffice2007FontName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strOffice2007FontName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strOffice2007FontName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1E3
// Name: _dynamic_atexit_destructor_for__strDefaultFontName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strDefaultFontName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strDefaultFontName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1F1
// Name: _dynamic_atexit_destructor_for__strVertFontName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strVertFontName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strVertFontName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC1FF
// Name: _dynamic_atexit_destructor_for__strMarlettFontName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strMarlettFontName__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strMarlettFontName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC20D
// Name: _dynamic_atexit_destructor_for__afxGlobalData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__afxGlobalData__()
{
  AFX_GLOBAL_DATA::~AFX_GLOBAL_DATA(this: &afxGlobalData);
}

//------------------------------------------------------------------------------
// Address: 0x105CC217
// Name: _dynamic_atexit_destructor_for___afxPropPageFontInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxPropPageFontInfo__()
{
  CProcessLocalObject::~CProcessLocalObject(this: &_afxPropPageFontInfo);
}

//------------------------------------------------------------------------------
// Address: 0x105CC221
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___0()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC22F
// Name: _dynamic_atexit_destructor_for__CFrameImpl::m_lstFrames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CFrameImpl::m_lstFrames__()
{
  CFrameImpl::m_lstFrames.__vftable = (CList<CFrameWnd *,CFrameWnd *>_vtbl *)&CList<CFrameWnd *,CFrameWnd *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CFrameImpl::m_lstFrames);
}

//------------------------------------------------------------------------------
// Address: 0x105CC243
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___1()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_1.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC251
// Name: _dynamic_atexit_destructor_for__strTearOffBarsRegEntry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strTearOffBarsRegEntry__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTearOffBarsRegEntry.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC25F
// Name: _dynamic_atexit_destructor_for__CDockingManager::m_SDParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDockingManager::m_SDParams__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x105CC260
// Name: _dynamic_atexit_destructor_for__strDockingManagerProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strDockingManagerProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strDockingManagerProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC26E
// Name: _dynamic_atexit_destructor_for__strMDIClientAreaProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strMDIClientAreaProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strMDIClientAreaProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC27C
// Name: _dynamic_atexit_destructor_for__afxGlobalUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__afxGlobalUtils__()
{
  afxGlobalUtils.__vftable = (CGlobalUtils_vtbl *)&CGlobalUtils::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC287
// Name: _dynamic_atexit_destructor_for__CPaneFrameWnd::m_mapFloatingBars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPaneFrameWnd::m_mapFloatingBars__()
{
  CPaneFrameWnd::m_mapFloatingBars.__vftable = (CMap<unsigned int,unsigned int,HWND__ *,HWND__ *>_vtbl *)&CMap<unsigned int,unsigned int,HWND__ *,HWND__ *>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CPaneFrameWnd::m_mapFloatingBars);
}

//------------------------------------------------------------------------------
// Address: 0x105CC29B
// Name: _dynamic_atexit_destructor_for__CPaneFrameWnd::m_lstFrames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPaneFrameWnd::m_lstFrames__()
{
  CPaneFrameWnd::m_lstFrames.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CPaneFrameWnd::m_lstFrames);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2AF
// Name: _CPaneFrameWnd::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CPaneFrameWnd::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2BD
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatChar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatChar__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatChar.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2CB
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatShort__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatShort__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatShort.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2D9
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatLong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatLong__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatLong.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2E7
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatUShort__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatUShort__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatUShort.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC2F5
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatULong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatULong__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatULong.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC303
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatFloat__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatFloat.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC311
// Name: _dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatDouble__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCPropertyGridProperty::m_strFormatDouble__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCPropertyGridProperty::m_strFormatDouble.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC31F
// Name: _CMFCPropertyGridCtrl::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCPropertyGridCtrl::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC32D
// Name: _dynamic_atexit_destructor_for__afxAllToolBars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__afxAllToolBars__()
{
  CObList::~CObList(this: &afxAllToolBars);
}

//------------------------------------------------------------------------------
// Address: 0x105CC337
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_DropSource__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_DropSource__()
{
  CMFCToolBarDropSource::~CMFCToolBarDropSource(this: &CMFCToolBar::m_DropSource);
}

//------------------------------------------------------------------------------
// Address: 0x105CC341
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_Images__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_Images__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_Images);
}

//------------------------------------------------------------------------------
// Address: 0x105CC34B
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_ColdImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_ColdImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_ColdImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC355
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_MenuImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_MenuImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_MenuImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC35F
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_DisabledImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_DisabledImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_DisabledImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC369
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_DisabledMenuImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_DisabledMenuImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_DisabledMenuImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC373
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_LargeImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_LargeImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_LargeImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC37D
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_LargeColdImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_LargeColdImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_LargeColdImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC387
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_LargeDisabledImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_LargeDisabledImages__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCToolBar::m_LargeDisabledImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC391
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_UsageCount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_UsageCount__()
{
  CMFCCmdUsageCount::~CMFCCmdUsageCount(this: &CMFCToolBar::m_UsageCount);
}

//------------------------------------------------------------------------------
// Address: 0x105CC39B
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_DefaultImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_DefaultImages__()
{
  CMFCToolBar::m_DefaultImages.__vftable = (CMap<unsigned int,unsigned int,int,int>_vtbl *)&CMap<unsigned int,unsigned int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCToolBar::m_DefaultImages);
}

//------------------------------------------------------------------------------
// Address: 0x105CC3AF
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_lstUnpermittedCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_lstUnpermittedCommands__()
{
  CMFCToolBar::m_lstUnpermittedCommands.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CMFCToolBar::m_lstUnpermittedCommands);
}

//------------------------------------------------------------------------------
// Address: 0x105CC3C3
// Name: _dynamic_atexit_destructor_for__CMFCToolBar::m_lstBasicCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBar::m_lstBasicCommands__()
{
  CMFCToolBar::m_lstBasicCommands.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CMFCToolBar::m_lstBasicCommands);
}

//------------------------------------------------------------------------------
// Address: 0x105CC3D7
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___2()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_2.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC3E5
// Name: _dynamic_atexit_destructor_for__strToolbarProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strToolbarProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strToolbarProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC3F3
// Name: _CMFCToolBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCToolBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_1.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC401
// Name: _dynamic_atexit_destructor_for__CMFCVisualManagerOffice2007::m_strStylePrefix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCVisualManagerOffice2007::m_strStylePrefix__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCVisualManagerOffice2007::m_strStylePrefix.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC40F
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___3()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_3.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC41D
// Name: _dynamic_atexit_destructor_for__strKbProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strKbProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strKbProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC42B
// Name: _dynamic_atexit_destructor_for__CKeyboardManager::m_strDelimiter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CKeyboardManager::m_strDelimiter__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CKeyboardManager::m_strDelimiter.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC439
// Name: _dynamic_atexit_destructor_for__strToolbarProfile___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strToolbarProfile___0()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strToolbarProfile_0.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC447
// Name: _dynamic_atexit_destructor_for__STATIC_CREATOR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__STATIC_CREATOR__()
{
  CCommandManager::~CCommandManager(this: &STATIC_CREATOR.s_TheCmdMgr);
}

//------------------------------------------------------------------------------
// Address: 0x105CC451
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesBlack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesBlack__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesBlack);
}

//------------------------------------------------------------------------------
// Address: 0x105CC45B
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesDkGray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesDkGray__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesDkGray);
}

//------------------------------------------------------------------------------
// Address: 0x105CC465
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesGray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesGray__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesGray);
}

//------------------------------------------------------------------------------
// Address: 0x105CC46F
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesLtGray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesLtGray__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesLtGray);
}

//------------------------------------------------------------------------------
// Address: 0x105CC479
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesWhite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesWhite__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesWhite);
}

//------------------------------------------------------------------------------
// Address: 0x105CC483
// Name: _dynamic_atexit_destructor_for__CMenuImages::m_ImagesBlack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMenuImages::m_ImagesBlack2__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMenuImages::m_ImagesBlack2);
}

//------------------------------------------------------------------------------
// Address: 0x105CC48D
// Name: _dynamic_atexit_destructor_for__afxMenuHash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__afxMenuHash__()
{
  CMenuHash::~CMenuHash(this: &afxMenuHash);
}

//------------------------------------------------------------------------------
// Address: 0x105CC497
// Name: _dynamic_atexit_destructor_for__toolbarTerm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl dynamic_atexit_destructor_for__toolbarTerm__()
{
  CMFCToolBarImages::CleanUp();
}

//------------------------------------------------------------------------------
// Address: 0x105CC49C
// Name: _dynamic_atexit_destructor_for__CMFCToolBarImages::m_CriticalSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBarImages::m_CriticalSection__()
{
  CCriticalSection::~CCriticalSection(this: &CMFCToolBarImages::m_CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4A6
// Name: _dynamic_atexit_destructor_for__CMFCToolBarImages::m_strPngResType__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCToolBarImages::m_strPngResType__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)CMFCToolBarImages::m_strPngResType.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4B4
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___4()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_4.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4C2
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___5()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_5.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4D0
// Name: _dynamic_atexit_destructor_for__strDummyAmpSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strDummyAmpSeq__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strDummyAmpSeq.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4DE
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___6()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_6.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4EC
// Name: _dynamic_atexit_destructor_for__strControlBarProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__strControlBarProfile__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strControlBarProfile.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC4FA
// Name: _CMFCCaptionBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CMFCCaptionBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText_2.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC508
// Name: _dynamic_atexit_destructor_for__CMFCOutlookBarPane::m_Images__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMFCOutlookBarPane::m_Images__()
{
  CMFCToolBarImages::~CMFCToolBarImages(this: &CMFCOutlookBarPane::m_Images);
}

//------------------------------------------------------------------------------
// Address: 0x105CC512
// Name: _dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___afxDefaultAcceleratorDelimiter___7()
{
  ATL::CStringData::Release(this: (ATL::CStringData *)afxDefaultAcceleratorDelimiter_7.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x105CC520
// Name: _dynamic_atexit_destructor_for__CTabbedPane::m_arTabsAutoColors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTabbedPane::m_arTabsAutoColors__()
{
  CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(this: &CTabbedPane::m_arTabsAutoColors);
}

//------------------------------------------------------------------------------
// Address: 0x105CC52A
// Name: _dynamic_atexit_destructor_for__CTabbedPane::m_lstTabbedControlBars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTabbedPane::m_lstTabbedControlBars__()
{
  CTabbedPane::m_lstTabbedControlBars.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&CTabbedPane::m_lstTabbedControlBars);
}
