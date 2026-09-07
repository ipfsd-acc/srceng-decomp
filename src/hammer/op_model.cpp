// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_model.cpp
// Functions: 14
// ============================================================

#include "hammer\op_model.h"

//------------------------------------------------------------------------------
// Address: 0x100E6660
// Name: public: virtual struct CRuntimeClass __near * COP_Model::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Model::GetRuntimeClass(COP_Model *this)
{
  return &COP_Model::classCOP_Model;
}

//------------------------------------------------------------------------------
// Address: 0x100E6670
// Name: protected: virtual int COP_Model::OnKillActive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Model::OnKillActive(COP_Model *this)
{
  Options.view3d.bAnimateModels = this->m_bOldAnimatedModels;
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 258, ub: nullptr);
  return CPropertyPage::OnKillActive(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E66A0
// Name: protected: virtual void COP_Model::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Model::DoDataExchange(COP_Model *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_ComboSequence);
  DDX_Control(pDX, nIDC: (HWND__ *)0x627, rControl: (HWND__ *)&this->m_ScrollBarFrame);
}

//------------------------------------------------------------------------------
// Address: 0x100E66E0
// Name: protected: class CMapStudioModel __near * COP_Model::GetModelHelper(void)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__thiscall COP_Model::GetModelHelper(COP_Model *this)
{
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // eax
  _DWORD *v2; // eax
  int v3; // ecx
  void *v4; // edx
  CMapEntity *v5; // eax
  int v7; // [esp+4h] [ebp-18h] BYREF
  _DWORD *v8; // [esp+8h] [ebp-14h]
  void *inptr; // [esp+Ch] [ebp-10h]
  int v10; // [esp+18h] [ebp-4h]

  m_pObjectList = this->m_pObjectList;
  if ( m_pObjectList->m_Size == 0 )
    return nullptr;
  v2 = &(*m_pObjectList->m_Memory.m_pMemory)->m_pObject->__vftable;
  if ( v2 != nullptr )
  {
    inptr = v2;
    v7 = v2[8];
    v3 = v2[8];
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 4) = &v7;
    v8 = nullptr;
    v2[8] = &v7;
  }
  v4 = inptr;
  v10 = -1;
  if ( inptr != nullptr )
  {
    if ( v8 != nullptr )
    {
      *v8 = v7;
      if ( v7 != 0 )
        *(_DWORD *)(v7 + 4) = v8;
    }
    else if ( *((int **)inptr + 8) == &v7 )
    {
      *((_DWORD *)inptr + 8) = v7;
      if ( v7 != 0 )
        *(_DWORD *)(v7 + 4) = 0;
    }
    v8 = nullptr;
    v7 = 0;
    inptr = nullptr;
  }
  if ( v4 != nullptr
    && (v5 = (CMapEntity *)__RTDynamicCast(
                             inptr: v4,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CMapEntity `RTTI Type Descriptor',
                             isReference: 0)) != nullptr )
  {
    return CMapEntity::GetChildOfType<CMapStudioModel>(this: v5, ignoredArg: nullptr);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E67E0
// Name: protected: virtual int COP_Model::OnSetActive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Model::OnSetActive(COP_Model *this)
{
  CMapStudioModel *ModelHelper; // eax

  this->m_bOldAnimatedModels = Options.view3d.bAnimateModels;
  Options.view3d.bAnimateModels = 1;
  ModelHelper = COP_Model::GetModelHelper(this);
  if ( ModelHelper != nullptr )
    this->m_nOldSequence = CMapStudioModel::GetSequence(this: ModelHelper);
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 258, ub: nullptr);
  return CObjectPage::OnSetActive(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E6830
// Name: public: virtual bool COP_Model::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Model::SaveData(COP_Model *this, SaveData_Reason_t reason)
{
  CMapStudioModel *ModelHelper; // eax
  CMapStudioModel *v5; // esi

  if ( !IsWindow(hWnd: this->m_hWnd) )
    return 0;
  if ( reason == SAVEDATA_SELECTION_CHANGED || reason == SAVEDATA_CLOSE )
  {
    ModelHelper = COP_Model::GetModelHelper(this);
    v5 = ModelHelper;
    if ( ModelHelper != nullptr )
    {
      CMapStudioModel::SetSequence(this: ModelHelper, nIndex: this->m_nOldSequence);
      CMapStudioModel::SetFrame(this: v5, nFrame: 0);
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 2, ub: nullptr);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E68A0
// Name: protected: void COP_Model::InitScrollRange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Model::InitScrollRange(COP_Model *this)
{
  LPARAM MaxFrame; // edi
  CMapStudioModel *ModelHelper; // eax
  CWnd *DlgItem; // eax
  char string[40]; // [esp+8h] [ebp-28h] BYREF

  MaxFrame = 1000;
  ModelHelper = COP_Model::GetModelHelper(this);
  if ( ModelHelper != nullptr )
    MaxFrame = CMapStudioModel::GetMaxFrame(this: ModelHelper);
  CSliderCtrl::SetRange(this: &this->m_ScrollBarFrame, nMin: 0, nMax: MaxFrame, bRedraw: 0);
  SendMessageA(hWnd: this->m_ScrollBarFrame.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 0);
  sprintf(string, format: "%d", 0);
  DlgItem = CWnd::GetDlgItem(this, nID: 1576);
  CWnd::SetWindowTextA(this: DlgItem, lpszString: string);
}

//------------------------------------------------------------------------------
// Address: 0x100E6920
// Name: protected: void COP_Model::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Model::OnHScroll(COP_Model *this, unsigned int nSBCode, unsigned int nPos, CScrollBar *pScrollBar)
{
  CMapStudioModel *ModelHelper; // eax
  CWnd *DlgItem; // eax
  char string[40]; // [esp+Ch] [ebp-28h] BYREF

  if ( pScrollBar == (CScrollBar *)&this->m_ScrollBarFrame )
  {
    if ( nSBCode == 8 )
      return;
    ModelHelper = COP_Model::GetModelHelper(this);
    if ( ModelHelper != nullptr )
    {
      CMapStudioModel::SetFrame(this: ModelHelper, nFrame: nPos);
      sprintf(string, format: "%d", nPos);
      DlgItem = CWnd::GetDlgItem(this, nID: 1576);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: string);
      Options.view3d.bAnimateModels = 0;
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 258, ub: nullptr);
    }
  }
  CWnd::OnHScroll(this, __formal: nSBCode, a3: nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x100E69C0
// Name: public: virtual void COP_Model::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Model::OnTextChanged(COP_Model *this, const char *pText)
{
  COP_Model *v2; // edi
  CMapStudioModel *ModelHelper; // esi
  int SequenceIndex; // eax

  v2 = (COP_Model *)((char *)this - 184);
  ModelHelper = COP_Model::GetModelHelper(this: (COP_Model *)((char *)this - 184));
  if ( ModelHelper != nullptr )
  {
    SequenceIndex = CMapStudioModel::GetSequenceIndex(this: ModelHelper, pSequenceName: pText);
    if ( SequenceIndex != -1 )
      CMapStudioModel::SetSequence(this: ModelHelper, nIndex: SequenceIndex);
    CMapStudioModel::SetFrame(this: ModelHelper, nFrame: 0);
    COP_Model::InitScrollRange(this: v2);
    Options.view3d.bAnimateModels = 1;
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 258, ub: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6A30
// Name: public: virtual void COP_Model::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Model::UpdateData(COP_Model *this, int Mode, void *pData, int bCanEdit)
{
  void *v4; // edi
  int v6; // esi
  CMapStudioModel *ModelHelper; // eax
  CMapStudioModel *v8; // edi
  void *Sequence; // eax
  int v10; // eax
  bool m_bCanEdit; // [esp-8h] [ebp-334h]
  char txt[512]; // [esp+8h] [ebp-324h] BYREF
  char szName[260]; // [esp+208h] [ebp-124h] BYREF
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+30Ch] [ebp-20h] BYREF
  int v15; // [esp+328h] [ebp-4h]

  v4 = pData;
  CObjectPage::UpdateData(this, Mode, pData, bCanEdit);
  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    v6 = 0;
    if ( v4 != nullptr )
    {
      if ( Mode == 0 )
      {
        CFilteredComboBox::Clear(this: &this->m_ComboSequence);
        ModelHelper = COP_Model::GetModelHelper(this);
        v8 = ModelHelper;
        if ( ModelHelper != nullptr )
        {
          txt[0] = 0;
          Sequence = (void *)CMapStudioModel::GetSequence(this: ModelHelper);
          pData = Sequence;
          if ( Sequence != nullptr )
            CMapStudioModel::GetSequenceName(this: v8, nIndex: (int)Sequence, szName: txt);
          memset(&suggestions, 0, sizeof(suggestions));
          v15 = 1;
          bCanEdit = CMapStudioModel::GetSequenceCount(this: v8);
          if ( bCanEdit > 0 )
          {
            do
            {
              CMapStudioModel::GetSequenceName(this: v8, nIndex: v6, szName);
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&Mode,
                pszSrc: szName);
              LOBYTE(v15) = 2;
              CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
                this: &suggestions,
                elem: suggestions.m_Size,
                src: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&Mode);
              LOBYTE(v15) = 1;
              v10 = Mode - 16;
              if ( _InterlockedDecrement((volatile signed __int32 *)(Mode - 16 + 12)) <= 0 )
                (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 4))(a1: v10);
              ++v6;
            }
            while ( v6 < bCanEdit );
          }
          CFilteredComboBox::SetSuggestions(this: &this->m_ComboSequence, &suggestions, flags: 0);
          SendMessageA(hWnd: this->m_ComboSequence.m_hWnd, Msg: 0x14Eu, wParam: (WPARAM)pData, lParam: 0);
          v15 = -1;
          CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::~CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>(this: &suggestions);
        }
        COP_Model::InitScrollRange(this);
      }
      m_bCanEdit = this->m_bCanEdit;
      LOBYTE(Mode) = !this->m_bCanEdit;
      CFilteredComboBox::EnableWindow(this: &this->m_ComboSequence, bEnable: m_bCanEdit);
      CWnd::EnableWindow(this: &this->m_ScrollBarFrame, bEnable: (_BYTE)Mode == 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6BE0
// Name: protected: virtual int COP_Model::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Model::OnInitDialog(COP_Model *this)
{
  CDialog::OnInitDialog(this);
  COP_Model::InitScrollRange(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E6C00
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Model::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COP_Model::GetMessageMap(COP_Model *this)
{
  return (const AFX_MSGMAP *)&off_105EF45C;
}

//------------------------------------------------------------------------------
// Address: 0x100E6C10
// Name: public: COP_Model::COP_Model(void)
// Source: json
//------------------------------------------------------------------------------
COP_Model *__thiscall COP_Model::COP_Model(COP_Model *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x13Cu, nIDCaption: 0, dwSize: 0x38u);
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Model_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CFilteredComboBox::ICallbacks::`vftable';
  this->CObjectPage::CPropertyPage::CDialog::CWnd::CCmdTarget::CObject::__vftable = (COP_Model_vtbl *)&COP_Model::`vftable'{for `CObjectPage'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&COP_Model::`vftable'{for `CFilteredComboBox::ICallbacks'};
  CFilteredComboBox::CFilteredComboBox(this: &this->m_ComboSequence, pCallbacks: &this->CFilteredComboBox::ICallbacks);
  CWnd::CWnd(this: &this->m_ScrollBarFrame);
  this->m_ScrollBarFrame.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  this->m_pEditObjectRuntimeClass = &editCEditGameClass::classeditCEditGameClass;
  CFilteredComboBox::SetOnlyProvideSuggestions(this: &this->m_ComboSequence, bOnlyProvideSuggestions: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E6D70
// Name: public: static class CObject __near * COP_Model::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Model *__stdcall COP_Model::CreateObject()
{
  COP_Model *v0; // eax

  v0 = (COP_Model *)operator new(nSize: 0x1F0u);
  if ( v0 != nullptr )
    return COP_Model::COP_Model(this: v0);
  else
    return nullptr;
}
