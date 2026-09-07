// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/filtercontrol.cpp
// Functions: 240
// ============================================================

#include "hammer\filtercontrol.h"

//------------------------------------------------------------------------------
// Address: 0x1005B4E0
// Name: protected: virtual void CFilterControl::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnSize(CManifestFilter *this, unsigned int nType, int cx, int cy)
{
  CHammerBar::OnSize(this, nType, cx, cy);
}

//------------------------------------------------------------------------------
// Address: 0x100CED30
// Name: public: virtual class CSize CFilterControl::CalcDynamicLayout(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CSize *__thiscall CFilterControl::CalcDynamicLayout(
        CFilterControl *this,
        CSize *result,
        int nLength,
        unsigned int dwMode)
{
  CHammerBar::CalcDynamicLayout(this, result, nLength, dwMode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CED50
// Name: public: void CFilterControl::SelectCordon(struct Cordon_t __near *,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::SelectCordon(CFilterControl *this, Cordon_t *pSelectCordon, BoundBox *pSelectBox)
{
  GDclass *p_m_cCordonBox; // edi
  int v4; // ebx
  CClassOutput *Output; // esi

  p_m_cCordonBox = (GDclass *)&this->m_cCordonBox;
  v4 = 0;
  if ( CTreeList::GetItemCount(this: &this->m_cCordonBox) > 0 )
  {
    while ( 1 )
    {
      Output = GDclass::GetOutput(this: p_m_cCordonBox, nIndex: v4);
      if ( (Cordon_t *)Output->__vftable == pSelectCordon && *(BoundBox **)Output->m_szName == pSelectBox )
        break;
      if ( ++v4 >= CTreeList::GetItemCount(this: (CTreeList *)p_m_cCordonBox) )
        return;
    }
    CTreeList::EnsureVisible(this: (CTreeList *)p_m_cCordonBox, pItem: Output);
    CTreeList::SelectItem(this: (CTreeList *)p_m_cCordonBox, pItem: Output);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CEDC0
// Name: protected: void CFilterControl::UpdateControl(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateControl(CFilterControl *this, CCmdUI *pCmdUI)
{
  CCmdUI_vtbl *v2; // edi
  CMapWorld *ActiveWorld; // eax

  v2 = pCmdUI->__vftable;
  ActiveWorld = GetActiveWorld();
  v2->Enable(this: pCmdUI, a2: ActiveWorld != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CEDF0
// Name: protected: void CFilterControl::UpdateControlGroups(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateControlGroups(CFilterControl *this, CCmdUI *pCmdUI)
{
  if ( GetActiveWorld() == nullptr || CVisGroup::IsShowAllActive() )
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  else
    pCmdUI->Enable(this: pCmdUI, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100CEE30
// Name: public: virtual void CFilterControl::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnUpdateCmdUI(CFilterControl *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100CEE50
// Name: protected: void CFilterControl::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnNew(CFilterControl *this)
{
  if ( this->m_mode == FILTER_DIALOG_CORDONS && CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::OnNewCordon(this: CMapDoc::m_pMapDoc);
}

//------------------------------------------------------------------------------
// Address: 0x100CEE70
// Name: public: void CFilterControl::UpdateGroupListChecks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateGroupListChecks(CFilterControl *this)
{
  GDclass *p_m_cGroupBox; // edi
  int v2; // ebx
  CTreeList *Output; // esi
  int nCount; // [esp+8h] [ebp-4h]

  p_m_cGroupBox = (GDclass *)&this->m_cGroupBox;
  v2 = 0;
  nCount = CTreeList::GetItemCount(this: &this->m_cGroupBox);
  if ( nCount > 0 )
  {
    do
    {
      Output = (CTreeList *)GDclass::GetOutput(this: p_m_cGroupBox, nIndex: v2);
      if ( CTreeList::GetItemCount(this: Output) != 0 )
      {
        if ( CTreeList::GetItemCount(this: Output) == 1 )
          CTreeList::SetCheck(this: (CTreeList *)p_m_cGroupBox, pItem: Output, nCheckState: 1);
        else
          CTreeList::SetCheck(this: (CTreeList *)p_m_cGroupBox, pItem: Output, nCheckState: -1);
      }
      else
      {
        CTreeList::SetCheck(this: (CTreeList *)p_m_cGroupBox, pItem: Output, nCheckState: 0);
      }
      ++v2;
    }
    while ( v2 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CEED0
// Name: public: void CFilterControl::UpdateCordonListChecks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateCordonListChecks(CFilterControl *this)
{
  GDclass *p_m_cCordonBox; // edi
  int ItemCount; // ebx
  int i; // esi
  CClassOutput *Output; // eax

  p_m_cCordonBox = (GDclass *)&this->m_cCordonBox;
  ItemCount = CTreeList::GetItemCount(this: &this->m_cCordonBox);
  for ( i = 0; i < ItemCount; ++i )
  {
    Output = GDclass::GetOutput(this: p_m_cCordonBox, nIndex: i);
    if ( *(_DWORD *)Output->m_szName == 0 )
      CTreeList::SetCheck(
        this: (CTreeList *)p_m_cCordonBox,
        pItem: Output,
        nCheckState: LOBYTE(Output->__vftable[4].dtr_CClassInputOutputBase) != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CEF20
// Name: protected: void CWnd::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWnd::OnShowWindow(CWnd *this, int __formal, unsigned int __formala)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEF50
// Name: public: void CFilterControl::UpdateGroupList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateGroupList(CFilterControl *this)
{
  CMapDoc *v1; // ebx
  CGroupList *p_m_cGroupBox; // ecx
  CVisGroup *RootVisGroup; // eax
  CVisGroup *pVisGroup; // [esp+8h] [ebp-10h]
  int nCount; // [esp+Ch] [ebp-Ch]
  CMapDoc *pDoc; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v1 = CMapDoc::m_pMapDoc;
  pDoc = CMapDoc::m_pMapDoc;
  p_m_cGroupBox = &this->m_cGroupBox;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CTreeList::SaveTreeListExpandStates(this: p_m_cGroupBox);
    pVisGroup = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupBox);
    SendMessageA(hWnd: this->m_cGroupBox.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    CTreeList::DeleteAllItems(this: &this->m_cGroupBox);
    nCount = CMapDoc::VisGroups_GetRootCount(this: v1);
    i = 0;
    if ( nCount > 0 )
    {
      while ( 1 )
      {
        RootVisGroup = CMapDoc::VisGroups_GetRootVisGroup(this: v1, nIndex: i);
        if ( (strcmp(RootVisGroup->m_szName, "Auto") == 0) == (this->m_mode == FILTER_DIALOG_AUTO_VISGROUPS) )
          CGroupList::AddVisGroup(this: &this->m_cGroupBox, pVisGroup: RootVisGroup);
        if ( ++i >= nCount )
          break;
        v1 = pDoc;
      }
    }
    CFilterControl::UpdateGroupListChecks(this);
    if ( pVisGroup != nullptr )
    {
      CTreeList::EnsureVisible(this: &this->m_cGroupBox, pItem: pVisGroup);
      CTreeList::SelectItem(this: &this->m_cGroupBox, pItem: pVisGroup);
    }
    CTreeList::RestoreTreeListExpandStates(this: &this->m_cGroupBox);
    SendMessageA(hWnd: this->m_cGroupBox.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_cGroupBox.m_hWnd, lpRect: nullptr, bErase: true);
  }
  else
  {
    CTreeList::DeleteAllItems(this: p_m_cGroupBox);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF090
// Name: protected: void CFilterControl::OnShowAllGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnShowAllGroups(CFilterControl *this)
{
  CWnd *DlgItem; // eax
  LRESULT v3; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1470);
  if ( DlgItem != nullptr )
  {
    v3 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
    CVisGroup::ShowAllVisGroups(bShow: v3 == 1);
    CMapDoc::UpdateVisibilityAll(this: CMapDoc::m_pMapDoc);
    CFilterControl::UpdateGroupListChecks(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF0E0
// Name: protected: void CFilterControl::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnWindowPosChanged(CFilterControl *this, tagWINDOWPOS *pPos)
{
  if ( this->m_bInitialized && (pPos->flags & 0x40) != 0 )
    CFilterControl::UpdateGroupList(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF110
// Name: protected: void CFilterControl::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnShowWindow(CFilterControl *this, int bShow, unsigned int nStatus)
{
  if ( bShow != 0 )
    CFilterControl::UpdateGroupList(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF130
// Name: protected: void CFilterControl::OnActivate(unsigned int,class CWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnActivate(CFilterControl *this, unsigned int nState, CWnd *pWnd, int bMinimized)
{
  if ( nState == 1 )
    CFilterControl::UpdateGroupList(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF150
// Name: protected: long CFilterControl::OnListToggleState(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnListToggleState(CFilterControl *this, CTreeList *wParam, int lParam)
{
  CMapDoc *v3; // edi
  int ItemCount; // eax

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc == nullptr )
    return 0;
  if ( this->m_mode != FILTER_DIALOG_CORDONS )
  {
    if ( wParam != nullptr )
    {
      ItemCount = CTreeList::GetItemCount(this: wParam);
      CMapDoc::VisGroups_ShowVisGroup(this: v3, pGroup: (CVisGroup *)wParam, bShow: ItemCount == 0);
    }
    CFilterControl::UpdateGroupListChecks(this);
    return 0;
  }
  if ( wParam == nullptr )
    return 0;
  if ( wParam->m_dwRef == 0 )
    LOBYTE(wParam->OnFinalRelease) = LOBYTE(wParam->OnFinalRelease) == 0;
  CMapDoc::UpdateVisibilityAll(this: v3);
  CFilterControl::UpdateCordonListChecks(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CF1D0
// Name: public: void CFilterControl::UpdateCordonList(struct Cordon_t __near *,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::UpdateCordonList(CFilterControl *this, Cordon_t *pSelectCordon, BoundBox *pSelectBox)
{
  CFilterControl *v3; // edi
  int i; // esi
  CClassOutput *Output; // eax
  Cordon_t *v6; // esi
  CordonListItem_t *v7; // ebx
  CordonListItem_t *v8; // edi
  int v9; // ebx
  CClassOutput *v10; // eax
  int nSelectedItem; // [esp+4h] [ebp-20h]
  int m_Size; // [esp+8h] [ebp-1Ch]
  int j; // [esp+10h] [ebp-14h]
  CMapDoc *pDoc; // [esp+14h] [ebp-10h]
  CordonListItem_t *pSelectItem; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]
  Cordon_t *pSelectCordona; // [esp+2Ch] [ebp+8h]

  v3 = this;
  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    SendMessageA(hWnd: this->m_cCordonBox.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    nSelectedItem = -1;
    if ( pSelectCordon == nullptr )
      nSelectedItem = CTreeList::GetSelectedIndex(this: &v3->m_cCordonBox);
    for ( i = 0; i < CTreeList::GetItemCount(this: &v3->m_cCordonBox); ++i )
    {
      Output = GDclass::GetOutput(this: (GDclass *)&v3->m_cCordonBox, nIndex: i);
      operator delete(p: Output);
    }
    CTreeList::DeleteAllItems(this: &v3->m_cCordonBox);
    pSelectItem = nullptr;
    if ( pDoc->m_Cordons.m_Size > 0 )
    {
      v17 = 0;
      m_Size = pDoc->m_Cordons.m_Size;
      do
      {
        v6 = &pDoc->m_Cordons.m_Memory.m_pMemory[v17];
        v7 = (CordonListItem_t *)operator new(nSize: 8u);
        v7->m_pCordon = v6;
        v7->m_pBox = nullptr;
        CCordonList::AddCordon(this: &v3->m_cCordonBox, pCordon: v7, pParent: nullptr);
        if ( pSelectCordon != nullptr && pSelectCordon == v6 && pSelectBox == nullptr )
          pSelectItem = v7;
        j = 0;
        if ( v6->m_Boxes.m_Size > 0 )
        {
          v18 = 0;
          do
          {
            v8 = (CordonListItem_t *)operator new(nSize: 8u);
            v8->m_pCordon = v6;
            v8->m_pBox = &v6->m_Boxes.m_Memory.m_pMemory[v18];
            CCordonList::AddCordon(this: &this->m_cCordonBox, pCordon: v8, pParent: v7);
            if ( pSelectCordon != nullptr && pSelectCordon == v6 && pSelectBox != nullptr && pSelectBox == v8->m_pBox )
              pSelectItem = v8;
            ++v18;
            ++j;
          }
          while ( j < v6->m_Boxes.m_Size );
          v3 = this;
        }
        ++v17;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    v9 = 0;
    pSelectCordona = (Cordon_t *)CTreeList::GetItemCount(this: &v3->m_cCordonBox);
    if ( (int)pSelectCordona > 0 )
    {
      do
      {
        v10 = GDclass::GetOutput(this: (GDclass *)&v3->m_cCordonBox, nIndex: v9);
        if ( *(_DWORD *)v10->m_szName == 0 )
          CTreeList::SetCheck(
            this: &v3->m_cCordonBox,
            pItem: v10,
            nCheckState: LOBYTE(v10->__vftable[4].dtr_CClassInputOutputBase) != 0);
        ++v9;
      }
      while ( v9 < (int)pSelectCordona );
    }
    if ( nSelectedItem == -1 )
    {
      if ( pSelectItem != nullptr )
      {
        CTreeList::EnsureVisible(this: &v3->m_cCordonBox, pItem: pSelectItem);
        CTreeList::SelectItem(this: &v3->m_cCordonBox, pItem: pSelectItem);
      }
    }
    else
    {
      CTreeList::EnsureVisible(this: &v3->m_cCordonBox, nItem: nSelectedItem);
      CTreeList::SelectNearestItem(this: &v3->m_cCordonBox, nItem: nSelectedItem);
    }
    CTreeList::ExpandAll(this: &v3->m_cCordonBox);
    SendMessageA(hWnd: v3->m_cCordonBox.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: v3->m_cCordonBox.m_hWnd, lpRect: nullptr, bErase: true);
  }
  else
  {
    CTreeList::DeleteAllItems(this: &this->m_cCordonBox);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF410
// Name: protected: int CFilterControl::OnMoveUpDown(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnMoveUpDown(CFilterControl *this, unsigned int uCmd)
{
  Cordon_t **SelectedItem; // eax
  void *v4; // esi
  CTreeList *p_m_cCordonBox; // ecx
  CVisGroup *v6; // eax
  CMapDoc *pDoc; // [esp+4h] [ebp-4h]

  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    if ( this->m_mode == FILTER_DIALOG_CORDONS )
    {
      SelectedItem = (Cordon_t **)CTreeList::GetSelectedItem(this: &this->m_cCordonBox);
      v4 = SelectedItem;
      if ( SelectedItem != nullptr )
      {
        if ( uCmd == 1012 )
          CMapDoc::Cordon_MoveUp(this: pDoc, cordon: *SelectedItem);
        else
          CMapDoc::Cordon_MoveDown(this: pDoc, cordon: *SelectedItem);
        CFilterControl::UpdateCordonList(this, pSelectCordon: nullptr, pSelectBox: nullptr);
        CTreeList::EnsureVisible(this: &this->m_cCordonBox, pItem: v4);
        p_m_cCordonBox = &this->m_cCordonBox;
LABEL_13:
        CTreeList::SelectItem(this: p_m_cCordonBox, pItem: v4);
        pDoc->SetModifiedFlag(this: pDoc, a2: 1);
      }
    }
    else
    {
      v6 = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupBox);
      v4 = v6;
      if ( v6 != nullptr )
      {
        if ( uCmd == 1012 )
          CMapDoc::VisGroups_MoveUp(this: pDoc, pGroup: v6);
        else
          CMapDoc::VisGroups_MoveDown(this: pDoc, pGroup: v6);
        CFilterControl::UpdateGroupList(this);
        CTreeList::EnsureVisible(this: &this->m_cGroupBox, pItem: v4);
        p_m_cCordonBox = &this->m_cGroupBox;
        goto LABEL_13;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF4F0
// Name: protected: void CFilterControl::OnEditGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnEditGroups(CFilterControl *this)
{
  CEditGroups dlg; // [esp+4h] [ebp-250h] BYREF
  CColorBox *p_m_cColorBox; // [esp+244h] [ebp-10h]
  int v4; // [esp+250h] [ebp-4h]

  if ( this->m_mode != FILTER_DIALOG_CORDONS )
  {
    CEditGroups::CEditGroups(this: &dlg, pParent: nullptr);
    v4 = 0;
    CDialog::DoModal(this: &dlg);
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
    CFilterControl::UpdateGroupList(this);
    v4 = 3;
    p_m_cColorBox = &dlg.m_cColorBox;
    CStatic::~CStatic(this: &dlg.m_cColorBox);
    LOBYTE(v4) = 2;
    CGroupList::~CGroupList(this: &dlg.m_cGroupList);
    LOBYTE(v4) = 1;
    CEdit::~CEdit(this: &dlg.m_cName);
    v4 = -1;
    CDialog::~CDialog(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF5B0
// Name: protected: void CFilterControl::OnMarkMembers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnMarkMembers(CFilterControl *this)
{
  CMapDoc *v1; // ebx
  bool v2; // zf
  CMapWorld *m_pWorld; // edi
  CVisGroup *SelectedItem; // esi
  CMapClass *j; // edi
  CVisGroup **m_pMemory; // eax
  CMapClass_vtbl *v7; // esi
  CMapClass *ParentWnd; // eax
  CMapClass *v9; // eax
  CVisGroup *v10; // esi
  CMapClass *FirstDescendent; // edi
  CMapClass_vtbl *v12; // esi
  CMapClass *v13; // eax
  CMapClass *v14; // eax
  EnumChildrenPos_t pos; // [esp+4h] [ebp-94h] BYREF
  int i; // [esp+88h] [ebp-10h]
  CMapWorld *pWorld; // [esp+8Ch] [ebp-Ch]
  int v18; // [esp+90h] [ebp-8h]
  CVisGroup *pVisGroup; // [esp+94h] [ebp-4h]

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v2 = this->m_mode == FILTER_DIALOG_CORDONS;
    m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
    pWorld = m_pWorld;
    if ( v2 )
    {
      SelectedItem = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cCordonBox);
      pVisGroup = SelectedItem;
      if ( SelectedItem != nullptr )
      {
        CSelection::SetMode(this: v1->m_pSelection, eNewSelectMode: selectObjects);
        CMapDoc::SelectObject(this: v1, pObj: nullptr, cmd: 1040);
        for ( j = CMapClass::GetFirstDescendent(this: m_pWorld, (CMapClass *)&pos);
              j != nullptr;
              j = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos) )
        {
          m_pMemory = SelectedItem->m_Children.m_Memory.m_pMemory;
          i = 0;
          if ( (int)m_pMemory[8] > 0 )
          {
            v18 = 0;
            do
            {
              if ( (*((_BYTE *)j + 180) & 2) != 0
                && j->IsIntersectingCordon(
                     this: j,
                     a2: (const Vector *)((char *)&m_pMemory[5]->m_Children.m_Memory.m_nAllocationCount + v18),
                     a3: (const Vector *)((char *)&m_pMemory[5]->m_Children.m_pElements + v18)) )
              {
                v7 = j->__vftable;
                ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)v1->m_pSelection);
                v9 = v7->PrepareSelection(this: j, a2: (SelectMode_t)ParentWnd);
                if ( v9 != nullptr )
                  CMapDoc::SelectObject(this: v1, pObj: v9, cmd: 2);
              }
              SelectedItem = pVisGroup;
              m_pMemory = pVisGroup->m_Children.m_Memory.m_pMemory;
              v18 += 28;
              ++i;
            }
            while ( i < (int)m_pMemory[8] );
          }
        }
      }
    }
    else
    {
      v10 = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupBox);
      pVisGroup = v10;
      if ( v10 != nullptr )
      {
        CSelection::SetMode(this: v1->m_pSelection, eNewSelectMode: selectObjects);
        CMapDoc::SelectObject(this: v1, pObj: nullptr, cmd: 1040);
        FirstDescendent = CMapClass::GetFirstDescendent(this: m_pWorld, (CMapClass *)&pos);
        if ( FirstDescendent != nullptr )
        {
          while ( 1 )
          {
            if ( (*((_BYTE *)FirstDescendent + 180) & 2) != 0
              && CMapClass::IsInVisGroup(this: FirstDescendent, pVisGroup: v10) != 0 )
            {
              v12 = FirstDescendent->__vftable;
              v13 = CVGuiWnd::GetParentWnd(this: (CMapClass *)v1->m_pSelection);
              v14 = v12->PrepareSelection(this: FirstDescendent, a2: (SelectMode_t)v13);
              if ( v14 != nullptr )
                CMapDoc::SelectObject(this: v1, pObj: v14, cmd: 2);
            }
            FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
            if ( FirstDescendent == nullptr )
              break;
            v10 = pVisGroup;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF770
// Name: protected: long CFilterControl::OnListSelChange(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnListSelChange(CFilterControl *this, unsigned int wParam, int lParam)
{
  CMapDoc *v3; // esi
  void *SelectedItem; // eax
  BoundBox *v5; // ecx

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr && wParam == 1104 && this->m_mode == FILTER_DIALOG_CORDONS )
  {
    SelectedItem = CTreeList::GetSelectedItem(this: &this->m_cCordonBox);
    v5 = *((BoundBox **)SelectedItem + 1);
    if ( v5 != nullptr
      || *(int *)(*(_DWORD *)SelectedItem + 32) > 0 && (v5 = *(BoundBox **)(*(_DWORD *)SelectedItem + 20)) != nullptr )
    {
      CMapDoc::Cordon_SelectCordonForEditing(this: v3, cordon: *(Cordon_t **)SelectedItem, box: v5, nFlags: 2);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CF7D0
// Name: protected: void CFilterControl::ChangeMode(enum FilterDialogMode_t,enum FilterDialogMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::ChangeMode(
        CFilterControl *this,
        FilterDialogMode_t oldMode,
        FilterDialogMode_t newMode)
{
  CCordonList *p_m_cCordonBox; // ecx
  CWnd *DlgItem; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  CWnd *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax
  CWnd *v11; // eax
  CWnd *v12; // eax

  this->m_mode = newMode;
  p_m_cCordonBox = &this->m_cCordonBox;
  if ( newMode == FILTER_DIALOG_CORDONS )
  {
    CWnd::ShowWindow(this: p_m_cCordonBox, nCmdShow: 5);
    DlgItem = CWnd::GetDlgItem(this, nID: 1093);
    CWnd::ShowWindow(this: DlgItem, nCmdShow: 5);
    v6 = CWnd::GetDlgItem(this, nID: 1305);
    CWnd::ShowWindow(this: v6, nCmdShow: 5);
    CWnd::ShowWindow(this: &this->m_cGroupBox, nCmdShow: 0);
    v7 = CWnd::GetDlgItem(this, nID: 1091);
    CWnd::ShowWindow(this: v7, nCmdShow: 0);
    v8 = CWnd::GetDlgItem(this, nID: 1470);
    CWnd::ShowWindow(this: v8, nCmdShow: 0);
    CFilterControl::UpdateCordonList(this, pSelectCordon: nullptr, pSelectBox: nullptr);
  }
  else
  {
    CWnd::ShowWindow(this: p_m_cCordonBox, nCmdShow: 0);
    v9 = CWnd::GetDlgItem(this, nID: 1093);
    CWnd::ShowWindow(this: v9, nCmdShow: 0);
    v10 = CWnd::GetDlgItem(this, nID: 1305);
    CWnd::ShowWindow(this: v10, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_cGroupBox, nCmdShow: 5);
    v11 = CWnd::GetDlgItem(this, nID: 1091);
    CWnd::ShowWindow(this: v11, nCmdShow: 5);
    v12 = CWnd::GetDlgItem(this, nID: 1470);
    CWnd::ShowWindow(this: v12, nCmdShow: 5);
    CFilterControl::UpdateGroupList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF8E0
// Name: public: int CFilterControl::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::Create(CFilterControl *this, CWnd *pParentWnd)
{
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // ebx
  CWnd *DlgItem; // eax
  AFX_MODULE_STATE *v7; // eax
  HICON v8; // edi
  CWnd *v9; // eax

  result = CHammerBar::Create(
             this,
             pParentWnd,
             nIDTemplate: 0x8Cu,
             nStyle: 0x4104u,
             nID: 0xE807u,
             pszName: "Filter Control");
  if ( result != 0 )
  {
    CWnd::SubclassDlgItem(this: &this->m_cGroupBox, nID: 0x449u, pParent: this);
    CTreeList::EnableChecks(this: &this->m_cGroupBox);
    CWnd::SubclassDlgItem(this: &this->m_cCordonBox, nID: 0x450u, pParent: this);
    CTreeList::EnableChecks(this: &this->m_cCordonBox);
    CWnd::SubclassDlgItem(this: &this->m_cTabControl, nID: 0x66Du, pParent: this);
    CTabCtrl::InsertItem(this: &this->m_cTabControl, nMask: 1u, nItem: 0, lpszItem: "User", nImage: 0, lParam: 0);
    CTabCtrl::InsertItem(this: &this->m_cTabControl, nMask: 1u, nItem: 1u, lpszItem: "Auto", nImage: 0, lParam: 0);
    CTabCtrl::InsertItem(this: &this->m_cTabControl, nMask: 1u, nItem: 2u, lpszItem: "Cordon", nImage: 0, lParam: 0);
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x140);
    DlgItem = CWnd::GetDlgItem(this, nID: 1012);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)IconW);
    v7 = AfxGetModuleState();
    v8 = LoadIconW(hInstance: v7->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x141);
    v9 = CWnd::GetDlgItem(this, nID: 1011);
    SendMessageA(hWnd: v9->m_hWnd, Msg: 0xF7u, wParam: 1u, lParam: (LPARAM)v8);
    CHammerBar::AddControl(this, nIDTemplate: 1097, dwPlacementFlag: 4u);
    CHammerBar::AddControl(this, nIDTemplate: 1104, dwPlacementFlag: 4u);
    CHammerBar::AddControl(this, nIDTemplate: 1012, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1011, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1470, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1091, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1093, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1305, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1323, dwPlacementFlag: 2u);
    CHammerBar::AddControl(this, nIDTemplate: 1645, dwPlacementFlag: 4u);
    CFilterControl::UpdateGroupList(this);
    this->m_bInitialized = true;
    CFilterControl::ChangeMode(this, oldMode: FILTER_DIALOG_NONE, newMode: FILTER_DIALOG_USER_VISGROUPS);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CFAC0
// Name: protected: void CFilterControl::DeleteCordonListItem(struct CordonListItem_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::DeleteCordonListItem(CFilterControl *this, CordonListItem_t *pDelete, bool bConfirm)
{
  CMapDoc *v3; // edi
  bool v4; // bl
  const char *v5; // eax
  char *v6; // [esp-Ch] [ebp-30h]
  char *v7; // [esp-Ch] [ebp-30h]
  CUtlString str; // [esp+4h] [ebp-20h] BYREF
  CFilterControl *v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+20h] [ebp-4h]

  v3 = CMapDoc::m_pMapDoc;
  v9 = this;
  if ( CMapDoc::m_pMapDoc == nullptr )
    return;
  v4 = pDelete->m_pBox == nullptr || pDelete->m_pCordon->m_Boxes.m_Size <= 1;
  CUtlString::CUtlString(this: &str);
  v10 = 0;
  if ( v4 )
  {
    v6 = CUtlString::Get(this: &pDelete->m_pCordon->m_szName);
    CUtlString::Format(this: &str, pFormat: "Delete cordon '%s'?", v6);
  }
  else
  {
    if ( !bConfirm )
    {
LABEL_14:
      CMapDoc::Cordon_RemoveBox(this: v3, cordon: pDelete->m_pCordon, box: pDelete->m_pBox);
      goto LABEL_15;
    }
    v7 = CUtlString::Get(this: &pDelete->m_pCordon->m_szName);
    CUtlString::Format(this: &str, pFormat: "Delete box from cordon '%s'?", v7);
  }
  v5 = CUtlString::operator char const *(this: &str);
  if ( AfxMessageBox(lpszText: v5, nType: 0x24u, nIDHelp: 0) == 7 )
  {
    v10 = 2;
    goto LABEL_16;
  }
  if ( !v4 )
    goto LABEL_14;
  CMapDoc::Cordon_RemoveCordon(this: v3, cordon: pDelete->m_pCordon);
LABEL_15:
  CFilterControl::UpdateCordonList(this: v9, pSelectCordon: nullptr, pSelectBox: nullptr);
  v10 = 4;
LABEL_16:
  str.m_Storage.m_nActualLength = 0;
  v10 = -1;
  if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
    free(pMem: str.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100CFBE0
// Name: protected: long CFilterControl::OnListKeyDown(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnListKeyDown(CFilterControl *this, unsigned int wParam, int lParam)
{
  CordonListItem_t *SelectedItem; // eax

  if ( this->m_mode == FILTER_DIALOG_CORDONS && wParam == 46 && CMapDoc::m_pMapDoc != nullptr )
  {
    SelectedItem = (CordonListItem_t *)CTreeList::GetSelectedItem(this: &this->m_cCordonBox);
    if ( SelectedItem != nullptr )
    {
      CFilterControl::DeleteCordonListItem(this, pDelete: SelectedItem, bConfirm: false);
      CWnd::SetFocus(this: &this->m_cCordonBox);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CFC30
// Name: protected: void CFilterControl::OnSelChangeTab(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnSelChangeTab(CFilterControl *this, tagNMHDR *header, tagNMHDR *result)
{
  FilterDialogMode_t m_mode; // edi
  LRESULT v5; // eax

  m_mode = this->m_mode;
  v5 = SendMessageA(hWnd: this->m_cTabControl.m_hWnd, Msg: 0x130Bu, wParam: 0, lParam: 0);
  if ( v5 != 0 )
    CFilterControl::ChangeMode(this, oldMode: m_mode, newMode: (FilterDialogMode_t)((v5 != 1) + 1));
  else
    CFilterControl::ChangeMode(this, oldMode: m_mode, newMode: FILTER_DIALOG_USER_VISGROUPS);
}

//------------------------------------------------------------------------------
// Address: 0x100CFC80
// Name: protected: void CFilterControl::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnDelete(CFilterControl *this)
{
  CordonListItem_t *SelectedItem; // eax

  if ( this->m_mode == FILTER_DIALOG_CORDONS && CMapDoc::m_pMapDoc != nullptr )
  {
    SelectedItem = (CordonListItem_t *)CTreeList::GetSelectedItem(this: &this->m_cCordonBox);
    if ( SelectedItem != nullptr )
      CFilterControl::DeleteCordonListItem(this, pDelete: SelectedItem, bConfirm: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFCB0
// Name: protected: void CFilterControl::OnCordonListDragDrop(struct CordonListItem_t __near *,struct CordonListItem_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnCordonListDragDrop(
        CFilterControl *this,
        CordonListItem_t *pDrag,
        CordonListItem_t *pDrop)
{
  CMapDoc *v3; // ebx
  CordonListItem_t *v4; // esi
  CordonListItem_t *v5; // edi
  char *v6; // [esp-10h] [ebp-24h]
  char *v7; // [esp-10h] [ebp-24h]
  char *v8; // [esp-Ch] [ebp-20h]
  char *v9; // [esp-Ch] [ebp-20h]

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v4 = pDrag;
    if ( pDrag != nullptr )
    {
      v5 = pDrop;
      if ( pDrag != pDrop )
      {
        if ( pDrop != nullptr )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDrag);
          if ( v4->m_pBox != nullptr && v4->m_pCordon->m_Boxes.m_Size > 1 )
          {
            v8 = CUtlString::Get(this: &v5->m_pCordon->m_szName);
            v6 = CUtlString::Get(this: &v4->m_pCordon->m_szName);
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDrag,
              pszFormat: "Merge box from cordon '%s' into cordon '%s'?",
              v6,
              v8);
          }
          else
          {
            v9 = CUtlString::Get(this: &v5->m_pCordon->m_szName);
            v7 = CUtlString::Get(this: &v4->m_pCordon->m_szName);
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDrag,
              pszFormat: "Merge cordon '%s' into cordon '%s'?",
              v7,
              v9);
          }
          if ( AfxMessageBox(lpszText: (const char *)pDrag, nType: 0x24u, nIDHelp: 0) != 7 )
          {
            CMapDoc::Cordon_CombineCordons(
              this: v3,
              pSourceCordon: v4->m_pCordon,
              pSourceBox: v4->m_pBox,
              pDestCordon: v5->m_pCordon);
            CFilterControl::UpdateCordonList(this, pSelectCordon: nullptr, pSelectBox: nullptr);
          }
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDrag);
        }
        else
        {
          CFilterControl::DeleteCordonListItem(this, pDelete: pDrag, bConfirm: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFDC0
// Name: protected: void CFilterControl::OnVisGroupListDragDrop(class CVisGroup __near *,class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::OnVisGroupListDragDrop(
        CFilterControl *this,
        CVisGroup *pDragGroup,
        CVisGroup *pDropGroup)
{
  CMapDoc *v3; // ebx
  CVisGroup *v4; // esi
  CVisGroup *v5; // edi
  char *v6; // eax
  bool v7; // cc
  CAfxStringMgr *StringManager; // eax
  CVisGroup *v9; // esi
  CVisGroup *v10; // edi

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v4 = pDropGroup;
    if ( pDropGroup != nullptr )
    {
      v5 = pDragGroup;
      if ( CVisGroup::FindDescendent(this: pDragGroup, pGroup: pDropGroup) )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDropGroup);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDropGroup,
          pszFormat: "Cannot combine the groups because '%s' is a sub-group of '%s'.",
          v4->m_szName,
          v5->m_szName);
        AfxMessageBox(lpszText: (const char *)pDropGroup, nType: 0, nIDHelp: 0);
        CFilterControl::UpdateGroupList(this);
        v6 = &pDropGroup[-1].m_szName[127];
        v7 = _InterlockedDecrement((volatile signed __int32 *)&pDropGroup[-1].m_eVisible) <= 0;
        goto LABEL_12;
      }
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDragGroup);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDragGroup,
        pszFormat: "Combine group '%s' into group '%s'?",
        v5->m_szName,
        v4->m_szName);
      if ( AfxMessageBox(lpszText: (const char *)pDragGroup, nType: 0x24u, nIDHelp: 0) == 7 )
      {
        CFilterControl::UpdateGroupList(this);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDragGroup);
        return;
      }
      CMapDoc::VisGroups_CombineGroups(this: v3, pFrom: v5, pTo: v4);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDragGroup);
    }
    else
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      pDropGroup = (CVisGroup *)&StringManager->GetNilString(this: StringManager)[1];
      v9 = pDragGroup;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDropGroup,
        pszFormat: "Delete group '%s'?",
        pDragGroup->m_szName);
      v10 = pDropGroup;
      if ( AfxMessageBox(lpszText: (const char *)pDropGroup, nType: 0x24u, nIDHelp: 0) == 7 )
      {
        CFilterControl::UpdateGroupList(this);
        v6 = &v10[-1].m_szName[127];
        v7 = _InterlockedDecrement((volatile signed __int32 *)&v10[-1].m_eVisible) <= 0;
LABEL_12:
        if ( v7 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
        return;
      }
      CMapDoc::VisGroups_CheckMemberVisibility(this: v3, pGroup: v9);
      CMapDoc::VisGroups_RemoveGroup(this: v3, pGroup: (CMapWorld *)v9);
      if ( _InterlockedDecrement((volatile signed __int32 *)&v10[-1].m_eVisible) <= 0 )
        (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)&v10[-1].m_szName[127] + 4))(
          a1: *(_DWORD *)&v10[-1].m_szName[127],
          a2: &v10[-1].m_szName[127]);
    }
    CFilterControl::UpdateGroupList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFFD0
// Name: protected: long CFilterControl::OnListLeftDragDrop(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnListLeftDragDrop(
        CFilterControl *this,
        CordonListItem_t *wParam,
        CordonListItem_t *lParam)
{
  FilterDialogMode_t m_mode; // eax

  m_mode = this->m_mode;
  if ( m_mode == FILTER_DIALOG_CORDONS )
  {
    CFilterControl::OnCordonListDragDrop(this, pDrag: wParam, pDrop: lParam);
    return 0;
  }
  else
  {
    if ( m_mode == FILTER_DIALOG_AUTO_VISGROUPS )
      CFilterControl::UpdateGroupList(this);
    else
      CFilterControl::OnVisGroupListDragDrop(this, pDragGroup: (CVisGroup *)wParam, pDropGroup: (CVisGroup *)lParam);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0020
// Name: protected: long CFilterControl::OnListRightDragDrop(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilterControl::OnListRightDragDrop(CFilterControl *this, CVisGroup *wParam, char *lParam)
{
  FilterDialogMode_t m_mode; // eax
  CMapDoc *v5; // ebx
  CVisGroup *v6; // esi

  m_mode = this->m_mode;
  if ( m_mode != FILTER_DIALOG_CORDONS )
  {
    if ( m_mode == FILTER_DIALOG_AUTO_VISGROUPS )
    {
      CFilterControl::UpdateGroupList(this);
      return 0;
    }
    v5 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v6 = (CVisGroup *)lParam;
      if ( CVisGroup::FindDescendent(this: wParam, pGroup: (CVisGroup *)lParam) )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lParam);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lParam,
          pszFormat: "Cannot move the group because '%s' is a sub-group of '%s'.",
          v6->m_szName,
          wParam->m_szName);
        AfxMessageBox(lpszText: lParam, nType: 0, nIDHelp: 0);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lParam);
      }
      else
      {
        CMapDoc::VisGroups_SetParent(this: v5, pVisGroup: wParam, pNewParent: v6);
        CFilterControl::UpdateGroupList(this);
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D0100
// Name: protected: virtual struct AFX_MSGMAP const __near * CFilterControl::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFilterControl::GetMessageMap(CFilterControl *this)
{
  return (const AFX_MSGMAP *)&off_105EC060;
}

//------------------------------------------------------------------------------
// Address: 0x1034FB70
// Name: public: virtual void CStatusBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusBar::OnUpdateCmdUI(CStatusBar *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  unsigned int m_nCount; // ecx
  unsigned int v5; // eax
  CStatusCmdUI state; // [esp+4h] [ebp-28h] BYREF

  CCmdUI::CCmdUI(this: &state);
  m_nCount = this->m_nCount;
  v5 = 0;
  state.__vftable = (CStatusCmdUI_vtbl *)&CStatusCmdUI::`vftable';
  state.m_pOther = this;
  state.m_nIndexMax = m_nCount;
  for ( state.m_nIndex = 0; v5 < state.m_nIndexMax; state.m_nIndex = v5 )
  {
    state.m_nID = *((_DWORD *)this->m_pData + 5 * v5);
    if ( CCmdTarget::OnCmdMsg(this, nID: state.m_nID, nCode: -1, pExtra: &state, pHandlerInfo: nullptr) == 0 )
      CCmdUI::DoUpdate(this: &state, pTarget, bDisableIfNoHndler: 0);
    v5 = state.m_nIndex + 1;
  }
  CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler);
}

//------------------------------------------------------------------------------
// Address: 0x103548CC
// Name: public: virtual void CToolBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolBar::OnUpdateCmdUI(CToolBar *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  CToolBar_vtbl *v4; // eax
  CToolCmdUI state; // [esp+Ch] [ebp-40h] BYREF
  _TBBUTTON button; // [esp+34h] [ebp-18h] BYREF

  CCmdUI::CCmdUI(this: &state);
  v4 = this->__vftable;
  state.__vftable = (CToolCmdUI_vtbl *)&CToolCmdUI::`vftable';
  state.m_pOther = this;
  state.m_nIndexMax = v4->DefWindowProcA(this, a2: 1048u, a3: 0, a4: 0);
  for ( state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax; ++state.m_nIndex )
  {
    CToolBar::_GetButton(this, nIndex: state.m_nIndex, pButton: &button);
    state.m_nID = button.idCommand;
    if ( (button.fsStyle & 1) == 0
      && CCmdTarget::OnCmdMsg(this, nID: 0, nCode: -1122893825, pExtra: &state, pHandlerInfo: nullptr) == 0
      && CCmdTarget::OnCmdMsg(this, nID: state.m_nID, nCode: -1, pExtra: &state, pHandlerInfo: nullptr) == 0 )
    {
      CCmdUI::DoUpdate(this: &state, pTarget, bDisableIfNoHndler);
    }
  }
  CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler);
}

//------------------------------------------------------------------------------
// Address: 0x103AC604
// Name: public: virtual void CMFCToolBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnUpdateCmdUI(CMFCToolBar *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  unsigned int m_nCount; // eax
  CMFCToolBarButton *Button; // eax
  unsigned int m_nID; // edx
  unsigned int v7; // eax
  BOOL v8; // eax
  CMFCToolBarCmdUI state; // [esp+4h] [ebp-28h] BYREF

  CCmdUI::CCmdUI(this: &state);
  m_nCount = this->m_Buttons.m_nCount;
  state.m_nIndex = 0;
  state.__vftable = (CMFCToolBarCmdUI_vtbl *)&CMFCToolBarCmdUI::`vftable';
  state.m_pOther = this;
  state.m_nIndexMax = m_nCount;
  if ( m_nCount != 0 )
  {
    while ( 1 )
    {
      Button = CMFCToolBar::GetButton(this, nIndex: state.m_nIndex);
      if ( Button == nullptr )
        break;
      if ( afxUserToolsManager != nullptr )
      {
        m_nID = Button->m_nID;
        if ( m_nID >= afxUserToolsManager->m_uiCmdFirst && m_nID <= afxUserToolsManager->m_uiCmdLast )
          bDisableIfNoHndler = 0;
      }
      state.m_nID = Button->m_nID;
      if ( (Button->m_nStyle & 1) == 0 )
      {
        v7 = Button->m_nID;
        if ( v7 != 0 && v7 - 61440 > 0x1EF && v7 < 0xFF00 )
          CCmdUI::DoUpdate(this: &state, pTarget, bDisableIfNoHndler);
      }
      if ( ++state.m_nIndex >= state.m_nIndexMax )
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    v8 = bDisableIfNoHndler != 0 && this->m_bDisableControlsIfNoHandler != 0;
    CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8ECE
// Name: protected: virtual void CMFCRibbonBaseElement::OnUpdateCmdUI(class CMFCRibbonCmdUI __near *,class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::OnUpdateCmdUI(
        CMFCRibbonBaseElement *this,
        CMFCRibbonCmdUI *pCmdUI,
        CFrameWnd *pTarget,
        int bDisableIfNoHndler)
{
  unsigned int m_nID; // eax

  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  m_nID = this->m_nID;
  if ( m_nID != 0 && m_nID - 61440 > 0x1EF && m_nID < 0xFF00 )
  {
    pCmdUI->m_pUpdated = this;
    pCmdUI->m_nID = this->m_nID;
    CCmdUI::DoUpdate(this: pCmdUI, pTarget, bDisableIfNoHndler);
    pCmdUI->m_pUpdated = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D33AF
// Name: protected: virtual void CMFCRibbonPanel::OnUpdateCmdUI(class CMFCRibbonCmdUI __near *,class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::OnUpdateCmdUI(
        CMFCRibbonPanel *this,
        CMFCRibbonCmdUI *pCmdUI,
        CFrameWnd *pTarget,
        int bDisableIfNoHndler)
{
  int i; // esi
  CMFCRibbonBaseElement *v6; // ecx

  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v6 = this->m_arElements.m_pData[i];
    v6->OnUpdateCmdUI(this: v6, a2: pCmdUI, a3: pTarget, a4: bDisableIfNoHndler);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DEEF7
// Name: public: virtual void CMFCRibbonCategory::OnUpdateCmdUI(class CMFCRibbonCmdUI __near *,class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnUpdateCmdUI(
        CMFCRibbonCategory *this,
        CMFCRibbonCmdUI *pCmdUI,
        CFrameWnd *pTarget,
        int bDisableIfNoHndler)
{
  int i; // esi
  CMFCRibbonPanel *v6; // ecx

  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v6 = this->m_arPanels.m_pData[i];
    v6->OnUpdateCmdUI(this: v6, a2: pCmdUI, a3: pTarget, a4: bDisableIfNoHndler);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E532F
// Name: public: virtual void CMFCDropDownToolBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolBar::OnUpdateCmdUI(
        CMFCDropDownToolBar *this,
        CFrameWnd *__formal,
        int bDisableIfNoHndler)
{
  CFrameWnd *v4; // eax

  v4 = (CFrameWnd *)this->GetCommandTarget(this);
  CMFCToolBar::OnUpdateCmdUI(this, pTarget: v4, bDisableIfNoHndler);
}

//------------------------------------------------------------------------------
// Address: 0x103E954A
// Name: public: virtual void CDockablePane::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnUpdateCmdUI(CDockablePane *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  HWND Focus; // eax
  CWnd *v5; // eax
  int m_bActive; // ebx
  CWnd *v7; // edi
  int v8; // eax

  CWnd::UpdateDialogControls(this: &this->CPane, pTarget, bDisableIfNoHndler);
  Focus = GetFocus();
  v5 = CWnd::FromHandle(hWnd: Focus);
  m_bActive = this->m_bActive;
  v7 = v5;
  v8 = v5 != nullptr
    && v5->m_hWnd != nullptr
    && (IsChild(hWndParent: this->m_hWnd, hWnd: v5->m_hWnd) || v7->m_hWnd == this->m_hWnd);
  this->m_bActive = v8;
  if ( v8 != m_bActive )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10408D59
// Name: protected: virtual void CMFCColorBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnUpdateCmdUI(CMFCColorBar *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  unsigned int m_nCommandID; // eax
  int m_bEnabled; // ebx
  CFrameWnd *v6; // edi
  CFrameWnd_vtbl *v7; // edx
  CFrameWnd_vtbl *v8; // edx
  CObList::CNode *m_pNodeHead; // edi
  CObject *v10; // eax
  unsigned int v11; // [esp-14h] [ebp-50h]
  unsigned int v12; // [esp-14h] [ebp-50h]
  CObject *data; // [esp-8h] [ebp-44h]
  CMFCColorBarCmdUI state; // [esp+8h] [ebp-34h] BYREF
  AFX_CMDHANDLERINFO info; // [esp+34h] [ebp-8h] BYREF

  m_nCommandID = this->m_nCommandID;
  m_bEnabled = 0;
  if ( m_nCommandID == 0 || m_nCommandID == -1 )
  {
    CMFCToolBar::OnUpdateCmdUI(this, pTarget, bDisableIfNoHndler);
  }
  else
  {
    CMFCColorBarCmdUI::CMFCColorBarCmdUI(this: &state);
    v6 = pTarget;
    v7 = pTarget->__vftable;
    v11 = this->m_nCommandID;
    state.m_pOther = this;
    state.m_nIndexMax = 1;
    state.m_nID = v11;
    if ( v7->OnCmdMsg(this: pTarget, a2: v11, a3: -1, a4: &state, a5: nullptr) != 0 )
    {
      m_bEnabled = state.m_bEnabled;
    }
    else if ( bDisableIfNoHndler != 0 && state.m_bEnableChanged == 0 )
    {
      v8 = pTarget->__vftable;
      v12 = this->m_nCommandID;
      info.pTarget = nullptr;
      m_bEnabled = v8->OnCmdMsg(this: pTarget, a2: v12, a3: 0, a4: &state, a5: &info);
    }
    if ( m_bEnabled != this->m_bIsEnabled )
    {
      m_pNodeHead = this->m_Buttons.m_pNodeHead;
      this->m_bIsEnabled = m_bEnabled;
      while ( m_pNodeHead != nullptr )
      {
        data = m_pNodeHead->data;
        m_pNodeHead = m_pNodeHead->pNext;
        v10 = AfxDynamicDownCast(pClass: &CMFCToolBarColorButton::classCMFCToolBarColorButton, pObject: data);
        if ( v10 != nullptr )
        {
          v10[9].__vftable = (CObject_vtbl *)((int)v10[9].__vftable & ~0x40000u);
          if ( m_bEnabled == 0 )
            v10[9].__vftable = (CObject_vtbl *)((int)v10[9].__vftable | 0x40000);
        }
      }
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
      v6 = pTarget;
    }
    CMFCToolBar::OnUpdateCmdUI(this, pTarget: v6, bDisableIfNoHndler);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10416711
// Name: public: virtual void CMFCRibbonPanelMenuBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnUpdateCmdUI(
        CMFCRibbonPanelMenuBar *this,
        CFrameWnd *pTarget,
        int bDisableIfNoHndler)
{
  CMFCRibbonCategory *m_pCategory; // ecx
  CMFCRibbonPanel *m_pPanel; // ecx
  CMFCRibbonCategory *v6; // eax
  CMFCRibbonCmdUI state; // [esp+8h] [ebp-2Ch] BYREF

  CMFCRibbonCmdUI::CMFCRibbonCmdUI(this: &state);
  m_pCategory = this->m_pCategory;
  state.m_pOther = this;
  if ( m_pCategory != nullptr )
    m_pCategory->OnUpdateCmdUI(this: m_pCategory, a2: &state, a3: pTarget, a4: bDisableIfNoHndler);
  else
    this->m_pPanel->OnUpdateCmdUI(this: this->m_pPanel, a2: &state, a3: pTarget, a4: bDisableIfNoHndler);
  CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler);
  if ( bDisableIfNoHndler != 0 && this->m_bSetKeyTips != 0 )
  {
    m_pPanel = this->m_pPanel;
    if ( m_pPanel != nullptr )
    {
      if ( CMFCRibbonPanel::GetDroppedDown(this: m_pPanel) == nullptr )
        CMFCRibbonBar::SetKeyboardNavigationLevel(this: this->m_pRibbonBar, pLevel: this->m_pPanel, bSetFocus: 0);
    }
    else
    {
      v6 = this->m_pCategory;
      if ( v6 != nullptr )
        CMFCRibbonBar::SetKeyboardNavigationLevel(this: this->m_pRibbonBar, pLevel: v6, bSetFocus: 0);
    }
    this->m_bSetKeyTips = 0;
    CMFCPopupMenu::UpdateAllShadows(lprectScreen: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041A3DF
// Name: public: virtual void CMFCOutlookBarToolBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMFCOutlookBarToolBar::OnUpdateCmdUI(
        CMFCOutlookBarToolBar *this@<ecx>,
        int a2@<esi>,
        CFrameWnd *__formal,
        int a4)
{
  int i; // ebx
  unsigned int ButtonStyle; // eax
  unsigned int v7; // esi
  int v8; // eax
  int iTab; // [esp+8h] [ebp-4h] BYREF

  for ( i = 0; i < this->m_Buttons.m_nCount; ++i )
  {
    ButtonStyle = CMFCToolBar::GetButtonStyle(this, nIndex: i);
    iTab = -1;
    v7 = ButtonStyle & 0xFFEEFFFF;
    if ( CMap<int,int,unsigned int,unsigned int>::Lookup(this: &this->m_TabButtons, key: i, rValue: &iTab) != 0 )
    {
      v8 = ((int (__thiscall *)(CMFCOutlookBarTabCtrl *, int))this->m_pParentBar->GetActiveTab)(
             a1: this->m_pParentBar,
             a2);
      if ( v8 == iTab )
        v7 |= 0x10000u;
      a2 = v7 | 2;
      ((void (__thiscall *)(CMFCOutlookBarToolBar *, int))this->SetButtonStyle)(a1: this, a2: i);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104302F5
// Name: public: virtual void CMFCTasksPane::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnUpdateCmdUI(CMFCTasksPane *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  CObList::CNode *m_pNodeHead; // edi
  unsigned int m_nCount; // eax
  CUserToolsManager *v6; // ecx
  CObject *data; // eax
  CObject_vtbl *v8; // esi
  CObject_vtbl *v9; // eax
  void (__thiscall *Serialize)(CObject *, CArchive *); // eax
  unsigned int v11; // edx
  unsigned int v12; // eax
  CMFCTasksPaneToolBarCmdUI state; // [esp+8h] [ebp-28h] BYREF

  CCmdUI::CCmdUI(this: &state);
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  m_nCount = this->m_lstTaskGroups.m_nCount;
  state.m_nIndex = 0;
  state.__vftable = (CMFCTasksPaneToolBarCmdUI_vtbl *)&CMFCTasksPaneToolBarCmdUI::`vftable';
  state.m_pOther = this;
  state.m_nIndexMax = m_nCount;
  if ( m_pNodeHead != nullptr )
  {
    v6 = afxUserToolsManager;
    do
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v8 = data[4].__vftable;
      while ( v8 != nullptr )
      {
        v9 = v8;
        v8 = (CObject_vtbl *)v8->GetRuntimeClass;
        Serialize = v9->Serialize;
        if ( v6 != nullptr )
        {
          v11 = *((_DWORD *)Serialize + 9);
          if ( v11 >= v6->m_uiCmdFirst && v11 <= v6->m_uiCmdLast )
            bDisableIfNoHndler = 0;
        }
        state.m_nID = *((_DWORD *)Serialize + 9);
        if ( *((_DWORD *)Serialize + 9) != 0 )
        {
          v12 = *((_DWORD *)Serialize + 9);
          if ( v12 - 61440 > 0x1EF && v12 < 0xFF00 )
          {
            CCmdUI::DoUpdate(this: &state, pTarget, bDisableIfNoHndler);
            v6 = afxUserToolsManager;
          }
        }
      }
      ++state.m_nIndex;
    }
    while ( m_pNodeHead != nullptr );
  }
  CDockablePane::OnUpdateCmdUI(this, pTarget, bDisableIfNoHndler);
}

//------------------------------------------------------------------------------
// Address: 0x1035498D
// Name: unsigned long _AfxGetComCtlVersion(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxGetComCtlVersion()
{
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HMODULE ModuleHandleA; // eax
  FARPROC DllGetVersion; // ebx
  int v4; // esi
  AFX_DLLVERSIONINFO dvi; // [esp+0h] [ebp-18h] BYREF

  result = _afxComCtlVersion;
  if ( _afxComCtlVersion == -1 )
  {
    ModuleState = AfxGetModuleState();
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this: *ModuleState->m_pDllIsolationWrappers);
    DllGetVersion = GetProcAddress(hModule: ModuleHandleA, lpProcName: "DllGetVersion");
    v4 = 0x40000;
    if ( DllGetVersion != nullptr )
    {
      memset(dst: (unsigned __int8 *)&dvi, value: 0, count: sizeof(dvi));
      dvi.cbSize = 20;
      if ( ((int (__stdcall *)(AFX_DLLVERSIONINFO *))DllGetVersion)(a1: &dvi) >= 0 )
        v4 = LOWORD(dvi.dwMinorVersion) | (LOWORD(dvi.dwMajorVersion) << 16);
    }
    _afxComCtlVersion = v4;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10354A15
// Name: public: virtual int CToolBar::CreateEx(class CWnd __near *,unsigned long,unsigned long,class CRect,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::CreateEx(
        CToolBar *this,
        CWnd *pParentWnd,
        unsigned int dwCtrlStyle,
        unsigned int dwStyle,
        CRect rcBorders,
        unsigned int nID)
{
  int result; // eax
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  CControlBar::SetBorders(
    this,
    cxLeft: rcBorders.left,
    cyTop: rcBorders.top,
    cxRight: rcBorders.right,
    cyBottom: rcBorders.bottom);
  this->m_dwStyle = dwStyle & 0x40FFFF;
  if ( nID == 59392 )
    this->m_dwStyle = dwStyle & 0x40FFF7 | 8;
  AfxEndDeferRegisterClass(fToRegister: 4096);
  _AfxGetComCtlVersion();
  _AfxGetDropDownWidth();
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  result = CWnd::Create(
             this,
             lpszClassName: "ToolbarWindow32",
             lpszWindowName: nullptr,
             dwStyle: dwCtrlStyle | dwStyle & 0xFFBF004E | 0x4E,
             &rect,
             pParentWnd,
             nID,
             pContext: nullptr);
  if ( result != 0 )
  {
    CToolBar::SetSizes(this, sizeButton: this->m_sizeButton.tagSIZE, sizeImage: this->m_sizeImage.tagSIZE);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10354AED
// Name: public: int CToolBar::LoadToolBar(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::LoadToolBar(CToolBar *this, const char *lpszResourceName)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HGLOBAL Resource; // eax
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // esi
  unsigned int *v8; // edi
  int v9; // eax
  unsigned __int16 *v10; // ecx
  int BitmapA; // ebx
  tagSIZE v12; // [esp-18h] [ebp-24h]
  tagSIZE v13; // [esp-10h] [ebp-1Ch]
  void *hGlobal; // [esp+4h] [ebp-8h]

  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszResourceName, lpType: (LPCSTR)0xF1);
  if ( ResourceA == nullptr )
    return 0;
  Resource = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  hGlobal = Resource;
  if ( Resource == nullptr )
    return 0;
  v6 = (unsigned __int16 *)LockResource(hResData: Resource);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  v8 = (unsigned int *)operator new(nSize: 4 * v6[3]);
  v9 = 0;
  if ( v7[3] != 0 )
  {
    v10 = v7 + 4;
    do
      v8[v9++] = *v10++;
    while ( v9 < v7[3] );
  }
  BitmapA = CToolBar::SetButtons(this, lpIDArray: v8, nIDCount: v7[3]);
  operator delete(p: v8);
  if ( BitmapA != 0 )
  {
    v13.cy = v7[2];
    v13.cx = v7[1];
    v12.cy = v13.cy + 7;
    v12.cx = v13.cx + 7;
    CToolBar::SetSizes(this, sizeButton: v12, sizeImage: v13);
    BitmapA = CToolBar::LoadBitmapA(this, lpszResourceName);
  }
  FreeResource(hResData: hGlobal);
  return BitmapA;
}

//------------------------------------------------------------------------------
// Address: 0x10354BC6
// Name: protected: class CSize CToolBar::CalcLayout(unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CToolBar::CalcLayout(CToolBar *this, CSize *result, char dwMode, int nLength)
{
  CSize *v4; // esi
  int v6; // eax
  _TBBUTTON *v7; // eax
  int v8; // esi
  _TBBUTTON *v9; // edi
  unsigned int m_dwStyle; // eax
  int v11; // ecx
  _TBBUTTON *v12; // ecx
  int *p_idCommand; // eax
  _AFX_CONTROLPOS *v14; // eax
  int v15; // edx
  int *p_right; // ecx
  int *v17; // ecx
  int v18; // eax
  _DWORD *p_left; // edi
  int *v20; // edi
  unsigned int v21; // eax
  CWnd *DlgItem; // eax
  int v23; // esi
  int v24; // edi
  unsigned int cx; // eax
  int cy; // eax
  unsigned int m_nMRUWidth; // [esp-8h] [ebp-5Ch]
  HWND m_hWnd; // [esp-8h] [ebp-5Ch]
  CWnd *pWnd; // [esp+Ch] [ebp-48h]
  CWnd *pWnda; // [esp+Ch] [ebp-48h]
  _AFX_CONTROLPOS *pControl; // [esp+14h] [ebp-40h]
  int *v33; // [esp+18h] [ebp-3Ch]
  int j; // [esp+18h] [ebp-3Ch]
  _TBBUTTON *pButton; // [esp+1Ch] [ebp-38h]
  _TBBUTTON *pButtona; // [esp+1Ch] [ebp-38h]
  _TBBUTTON *nCount; // [esp+20h] [ebp-34h]
  _TBBUTTON *pData; // [esp+24h] [ebp-30h]
  int nControlCount; // [esp+28h] [ebp-2Ch]
  int i; // [esp+2Ch] [ebp-28h]
  signed int ia; // [esp+2Ch] [ebp-28h]
  CRect *ib; // [esp+2Ch] [ebp-28h]
  tagRECT rc; // [esp+30h] [ebp-24h] BYREF
  CRect rect; // [esp+40h] [ebp-14h] BYREF

  v4 = result;
  result->cx = 0;
  result->cy = 0;
  pData = nullptr;
  v6 = this->DefWindowProcA(this, a2: 1048u, a3: 0, a4: 0);
  nCount = (_TBBUTTON *)v6;
  if ( v6 != 0 )
  {
    v7 = (_TBBUTTON *)operator new(nSize: 20 * v6);
    v8 = 0;
    pData = v7;
    if ( (int)nCount <= 0 )
    {
      v4 = result;
      goto LABEL_59;
    }
    v9 = v7;
    do
      CToolBar::_GetButton(this, nIndex: v8++, pButton: v9++);
    while ( v8 < (int)nCount );
    v4 = result;
  }
  if ( (int)nCount <= 0 )
    goto LABEL_59;
  m_dwStyle = this->m_dwStyle;
  if ( (m_dwStyle & 2) == 0 )
  {
    if ( (m_dwStyle & 4) != 0 )
    {
      if ( (dwMode & 4) != 0 )
        goto LABEL_10;
      if ( (dwMode & 8) != 0 )
      {
        m_nMRUWidth = 0x7FFF;
        goto LABEL_22;
      }
      if ( (dwMode & 0x10) != 0 )
      {
        m_nMRUWidth = 0;
        goto LABEL_22;
      }
      if ( nLength != -1 )
      {
        memset(&rc, 0, sizeof(rc));
        SetRectEmpty(lprc: &rc);
        this->CalcInsideRect(this, a2: (CRect *)&rc, a3: dwMode & 2);
        if ( (dwMode & 0x20) != 0 )
          v11 = rc.bottom - rc.top;
        else
          v11 = rc.right - rc.left;
        CToolBar::SizeToolBar(this, pData, nCount, nLength: nLength + v11, bVert: dwMode & 0x20);
        goto LABEL_23;
      }
      if ( (m_dwStyle & 1) != 0 )
      {
LABEL_10:
        m_nMRUWidth = this->m_nMRUWidth;
LABEL_22:
        CToolBar::SizeToolBar(this, pData, nCount, nLength: m_nMRUWidth, bVert: 0);
        goto LABEL_23;
      }
    }
    m_nMRUWidth = (dwMode & 2) != 0 ? 0x7FFF : 0;
    goto LABEL_22;
  }
LABEL_23:
  *v4 = *CToolBar::CalcSize(this, result: (CSize *)&rc.right, pData, nCount);
  if ( (dwMode & 0x40) != 0 )
  {
    v12 = nCount;
    pControl = nullptr;
    nControlCount = 0;
    rc.bottom = this->m_bDelayedButtonLayout;
    this->m_bDelayedButtonLayout = 0;
    p_idCommand = &pData->idCommand;
    v33 = &pData->idCommand;
    do
    {
      if ( (*((_BYTE *)p_idCommand + 5) & 1) != 0 && *p_idCommand != 0 )
        ++nControlCount;
      p_idCommand += 5;
      v12 = (_TBBUTTON *)((char *)v12 - 1);
    }
    while ( v12 != nullptr );
    if ( nControlCount > 0 )
    {
      LOBYTE(v12) = (24 * (unsigned __int64)(unsigned int)nControlCount) >> 32 != 0;
      v14 = (_AFX_CONTROLPOS *)operator new(nSize: (24 * nControlCount) | -(int)v12);
      if ( v14 != nullptr )
      {
        v15 = nControlCount - 1;
        p_right = &v14->rectOldPos.right;
        do
        {
          *(p_right - 2) = 0;
          *(p_right - 1) = 0;
          *p_right = 0;
          p_right[1] = 0;
          p_right += 6;
          --v15;
        }
        while ( v15 >= 0 );
        pControl = v14;
      }
      else
      {
        pControl = nullptr;
      }
      v17 = &pData->idCommand;
      pWnd = (CWnd *)nControlCount;
      v18 = 0;
      p_left = &pControl->rectOldPos.left;
      nControlCount = 0;
      i = 0;
      pButton = (_TBBUTTON *)&pControl->rectOldPos;
      do
      {
        if ( nControlCount >= (int)pWnd )
          break;
        if ( (*((_BYTE *)v17 + 5) & 1) != 0 && *v17 != 0 )
        {
          *(p_left - 2) = v18;
          *(p_left - 1) = *v17;
          memset(&rect, 0, sizeof(rect));
          this->GetItemRect(this, a2: v18, a3: &rect);
          CWnd::ClientToScreen(this, lpRect: &rect);
          ++nControlCount;
          pButton = (_TBBUTTON *)((char *)pButton + 24);
          v18 = i;
          v17 = v33;
          *p_left = rect.left;
          v20 = p_left + 1;
          *v20++ = rect.top;
          *v20 = rect.right;
          v20[1] = rect.bottom;
          p_left = &pButton->iBitmap;
        }
        ++v18;
        v17 += 5;
        i = v18;
        v33 = v17;
      }
      while ( v18 < (int)nCount );
      v4 = result;
    }
    v21 = this->m_dwStyle;
    if ( (v21 & 1) != 0 && (v21 & 4) != 0 )
      this->m_nMRUWidth = v4->cx;
    ia = 0;
    pButtona = pData;
    do
      CToolBar::_SetButton(this, a2: (int)this, nIndex: ia++, pButton: pButtona++);
    while ( ia < (int)nCount );
    if ( nControlCount > 0 )
    {
      ib = &pControl->rectOldPos;
      for ( j = nControlCount; j != 0; --j )
      {
        DlgItem = CWnd::GetDlgItem(this, nID: ib[-1].bottom);
        pWnda = DlgItem;
        if ( DlgItem != nullptr )
        {
          m_hWnd = DlgItem->m_hWnd;
          memset(&rect, 0, sizeof(rect));
          GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
          v23 = rect.left - ib->left;
          v24 = rect.top - ib->top;
          this->GetItemRect(this, a2: ib[-1].right, a3: &rect);
          CWnd::SetWindowPos(
            this: pWnda,
            pWndInsertAfter: nullptr,
            x: rect.left + v23,
            y: rect.top + v24,
            cx: 0,
            cy: 0,
            nFlags: 0x15u);
          v4 = result;
        }
        ib = (CRect *)((char *)ib + 24);
      }
      operator delete(p: pControl);
    }
    this->m_bDelayedButtonLayout = rc.bottom;
  }
  operator delete(p: (void *)pData);
LABEL_59:
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  this->CalcInsideRect(this, a2: &rect, a3: dwMode & 2);
  v4->cy += rect.top - rect.bottom;
  v4->cx += rect.left - rect.right;
  CControlBar::CalcFixedLayout((CBasePane *)this, result: (CSize *)&rc.right, bStretch: dwMode & 1, bHorz: dwMode & 2);
  cx = v4->cx;
  if ( v4->cx <= rc.right )
    cx = rc.right;
  v4->cx = cx;
  cy = v4->cy;
  if ( cy <= rc.bottom )
    cy = rc.bottom;
  v4->cy = cy;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10354F9D
// Name: public: virtual class CSize CToolBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CToolBar::CalcFixedLayout(CToolBar *this, CSize *result, int bStretch, int bHorz)
{
  CToolBar::CalcLayout(this, result, dwMode: (bHorz != 0 ? 2 : 0) | (bStretch != 0), nLength: -1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10354FC8
// Name: public: virtual class CSize CToolBar::CalcDynamicLayout(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CToolBar::CalcDynamicLayout(CToolBar *this, CSize *result, int nLength, char dwMode)
{
  if ( nLength == -1 && (dwMode & 0x44) == 0 && ((dwMode & 8) != 0 || (dwMode & 0x10) != 0) )
    this->CalcFixedLayout(this, result, a3: dwMode & 1, a4: dwMode & 8);
  else
    CToolBar::CalcLayout(this, result, dwMode, nLength);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035500C
// Name: protected: long CToolBar::OnSetButtonSize(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::OnSetButtonSize(CToolBar *this, unsigned int __formal, int lParam)
{
  return CToolBar::OnSetSizeHelper(this, size: &this->m_sizeButton, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10355024
// Name: protected: long CToolBar::OnSetBitmapSize(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::OnSetBitmapSize(CToolBar *this, unsigned int __formal, int lParam)
{
  return CToolBar::OnSetSizeHelper(this, size: &this->m_sizeImage, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x1035503C
// Name: protected: virtual struct AFX_MSGMAP const __near * CToolBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CToolBar::GetMessageMap(CToolBar *this)
{
  return (const AFX_MSGMAP *)&off_106778C4;
}

//------------------------------------------------------------------------------
// Address: 0x10355042
// Name: public: virtual long CToolBar::get_accName(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CToolBar::get_accName(CToolBar *this, tagVARIANT varChild, wchar_t **pszName)
{
  CAfxStringMgr *StringManager; // eax
  ATL::CStringData *v5; // ecx
  CAfxStringMgr *v7; // eax
  CAfxStringMgr *v8; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // esi
  unsigned int nStyle; // [esp+10h] [ebp-20h] BYREF
  int nImage; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int nID; // [esp+18h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > szFullText; // [esp+1Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTipText; // [esp+20h] [ebp-10h] BYREF
  int v16; // [esp+2Ch] [ebp-4h]

  if ( varChild.decVal.Lo32 == 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &szFullText, pStringMgr: StringManager);
    v16 = 0;
    CWnd::GetWindowTextA(this, rString: &szFullText);
    *pszName = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::AllocSysString(this: &szFullText);
    v5 = (ATL::CStringData *)(szFullText.m_pszData - 16);
LABEL_3:
    ATL::CStringData::Release(this: v5);
    return 0;
  }
  v7 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &szFullText, pStringMgr: v7);
  v16 = 1;
  v8 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTipText, pStringMgr: v8);
  LOBYTE(v16) = 2;
  CToolBar::GetButtonInfo(this, nIndex: varChild.decVal.Lo32 - 1, &nID, &nStyle, iImage: &nImage);
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nID);
  if ( StringResourceHandle != nullptr
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &szFullText,
         hInstance: StringResourceHandle,
         nID) != 0 )
  {
    m_pszData = szFullText.m_pszData;
    AfxExtractSubString(rString: &strTipText, lpszFullString: szFullText.m_pszData, iSubString: 1, chSep: 10);
    *pszName = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::AllocSysString(this: &strTipText);
    ATL::CStringData::Release(this: (ATL::CStringData *)strTipText.m_pszData - 1);
    v5 = (ATL::CStringData *)(m_pszData - 16);
    goto LABEL_3;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strTipText.m_pszData - 1);
  v16 = -1;
  ATL::CStringData::Release(this: (ATL::CStringData *)szFullText.m_pszData - 1);
  return CWnd::get_accName(this, varChild, pszName);
}

//------------------------------------------------------------------------------
// Address: 0x10355154
// Name: public: class CMiniDockFrameWnd __near * CFrameWnd::CreateFloatingFrame(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMiniDockFrameWnd *__thiscall CFrameWnd::CreateFloatingFrame(CFrameWnd *this, unsigned int dwStyle)
{
  CObject *Object; // eax
  CObject *v4; // esi

  Object = CRuntimeClass::CreateObject(this: this->m_pFloatingFrameClass);
  v4 = Object;
  if ( Object == nullptr )
    AfxThrowMemoryException();
  if ( ((int (__thiscall *)(CObject *, CFrameWnd *, unsigned int))Object->__vftable[37].dtr_CObject)(
         a1: Object,
         a2: this,
         a3: dwStyle) == 0 )
    AfxThrowResourceException();
  return (CMiniDockFrameWnd *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10355192
// Name: public: void CFrameWnd::DockControlBar(class CControlBar __near *,class CDockBar __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::DockControlBar(
        CFrameWnd *this,
        CControlBar *pBar,
        CDockBar *pDockBar,
        const tagRECT *lpRect)
{
  CDockBar *ControlBar; // eax
  int v5; // edx

  if ( pBar == nullptr )
    goto LABEL_2;
  ControlBar = pDockBar;
  if ( pDockBar == nullptr )
  {
    v5 = 0;
    while ( (dword_10677A54[2 * v5] & 0xF000) != (pBar->m_dwStyle & 0xF000) )
    {
      if ( ++v5 >= 4 )
        goto LABEL_2;
    }
    ControlBar = (CDockBar *)CFrameWnd::GetControlBar(this, nID: CFrameWnd::dwDockBarMap[v5][0]);
    if ( ControlBar == nullptr )
LABEL_2:
      AfxThrowInvalidArgException();
  }
  CDockBar::DockControlBar(this: ControlBar, pBar, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x103551F3
// Name: public: void CFrameWnd::ReDockControlBar(class CControlBar __near *,class CDockBar __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::ReDockControlBar(
        CFrameWnd *this,
        CControlBar *pBar,
        CDockBar *pDockBar,
        const tagRECT *lpRect)
{
  HWND *v4; // ebx
  CDockBar *v5; // ecx
  const unsigned int *v6; // esi
  CDockBar *ControlBar; // edi
  CControlBar *DlgCtrlID; // eax

  v4 = nullptr;
  if ( pBar == nullptr )
    goto LABEL_2;
  v5 = pDockBar;
  if ( pDockBar == nullptr )
  {
    v6 = CFrameWnd::dwDockBarMap[0];
    do
    {
      ControlBar = (CDockBar *)CFrameWnd::GetControlBar(this, nID: *v6);
      if ( ControlBar != nullptr )
      {
        DlgCtrlID = (CControlBar *)GetDlgCtrlID(hWnd: pBar->m_hWnd);
        if ( CDockBar::FindBar(this: ControlBar, pBar: DlgCtrlID, nPosExclude: -1) > 0 )
        {
          v5 = ControlBar;
          goto LABEL_11;
        }
      }
      if ( ((pBar->m_dwStyle ^ v6[1]) & 0xF000) == 0 )
        v4 = CFrameWnd::GetControlBar(this, nID: *v6);
      v6 += 2;
    }
    while ( (int)v6 < (int)"CMiniDockFrameWnd" );
    v5 = (CDockBar *)v4;
    if ( v4 == nullptr )
LABEL_2:
      AfxThrowInvalidArgException();
  }
LABEL_11:
  CDockBar::ReDockControlBar(this: v5, pBar, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x10355287
// Name: public: void CFrameWnd::EnableDocking(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::EnableDocking(CFrameWnd *this, unsigned int dwDockStyle)
{
  int *v3; // esi
  CDockBar *v4; // ecx
  CDockBar *v5; // eax

  this->m_pFloatingFrameClass = &CMiniDockFrameWnd::classCMiniDockFrameWnd;
  v3 = dword_10677A54;
  do
  {
    if ( (*v3 & dwDockStyle & 0xF000) != 0 && CFrameWnd::GetControlBar(this, nID: *(v3 - 1)) == nullptr )
    {
      v4 = (CDockBar *)operator new(nSize: 0xE4u);
      if ( v4 != nullptr )
        v5 = CDockBar::CDockBar(this: v4, bFloating: 0);
      else
        v5 = nullptr;
      if ( v5->Create(this: v5, a2: this, a3: *v3 | 0x56000000, a4: *(v3 - 1)) == 0 )
        AfxThrowResourceException();
    }
    v3 += 2;
  }
  while ( (int)v3 < (int)"iDockFrameWnd" );
}

//------------------------------------------------------------------------------
// Address: 0x10355318
// Name: public: void CFrameWnd::DockControlBar(class CControlBar __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::DockControlBar(
        CFrameWnd *this,
        CControlBar *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockBar *ControlBar; // eax

  ControlBar = nullptr;
  if ( nDockBarID != 0 )
    ControlBar = (CDockBar *)CFrameWnd::GetControlBar(this, nID: nDockBarID);
  CFrameWnd::DockControlBar(this, pBar, pDockBar: ControlBar, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x10355342
// Name: public: void CFrameWnd::FloatControlBar(class CControlBar __near *,class CPoint,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::FloatControlBar(CFrameWnd *this, CControlBar *pBar, CPoint point, unsigned int dwStyle)
{
  CDockBar *m_pDockBar; // esi
  HWND Parent; // eax
  CWnd *v6; // eax
  CWnd *v7; // esi
  CMiniDockFrameWnd *FloatingFrame; // eax
  CDockBar *DlgItem; // eax

  if ( pBar == nullptr )
    goto LABEL_2;
  if ( pBar->m_pDockSite != nullptr )
  {
    m_pDockBar = pBar->m_pDockBar;
    if ( m_pDockBar != nullptr
      && m_pDockBar->m_bFloating != 0
      && CDockBar::GetDockedCount(this: pBar->m_pDockBar) == 1
      && (dwStyle & m_pDockBar->m_dwStyle & 0xF000) != 0 )
    {
      Parent = GetParent(hWnd: m_pDockBar->m_hWnd);
      v6 = CWnd::FromHandle(hWnd: Parent);
      v7 = v6;
      if ( v6 == nullptr )
        goto LABEL_2;
      CWnd::SetWindowPos(this: v6, pWndInsertAfter: nullptr, x: point.x, y: point.y, cx: 0, cy: 0, nFlags: 0x15u);
      v7->__vftable[1].IsInvokeAllowed(this: v7, a2: 1);
      goto LABEL_19;
    }
  }
  if ( (pBar->m_dwStyle & 4) != 0 )
  {
    dwStyle |= 4u;
    if ( (dwStyle & 0x5000) != 0 )
      dwStyle = dwStyle & 0xFFFF0FFF | 0x2000;
  }
  FloatingFrame = CFrameWnd::CreateFloatingFrame(this, dwStyle);
  v7 = FloatingFrame;
  if ( FloatingFrame == nullptr )
    goto LABEL_2;
  CWnd::SetWindowPos(this: FloatingFrame, pWndInsertAfter: nullptr, x: point.x, y: point.y, cx: 0, cy: 0, nFlags: 0x15u);
  if ( v7->m_hWndOwner == nullptr )
    v7->m_hWndOwner = pBar->m_hWnd;
  DlgItem = (CDockBar *)CWnd::GetDlgItem(this: v7, nID: 59423);
  if ( DlgItem == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  CDockBar::DockControlBar(this: DlgItem, pBar, lpRect: nullptr);
  v7->__vftable[1].IsInvokeAllowed(this: v7, a2: 1);
  if ( (GetWindowLongA(hWnd: pBar->m_hWnd, nIndex: -16) & 0x10000000) != 0 )
  {
    CWnd::ShowWindow(this: v7, nCmdShow: 8);
LABEL_19:
    UpdateWindow(hWnd: v7->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10355476
// Name: public: unsigned long CFrameWnd::CanDock(class CRect,unsigned long,class CDockBar __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CFrameWnd::CanDock(CFrameWnd *this, CRect rect, unsigned int dwDockStyle, CDockBar **ppDockBar)
{
  CDockBar **v4; // ebx
  CPtrList::CNode *m_pNodeHead; // edi
  CDockBar *data; // esi
  unsigned int v7; // eax
  HWND m_hWnd; // [esp-8h] [ebp-28h]
  CRect rectBar; // [esp+Ch] [ebp-14h] BYREF

  dwDockStyle &= 0xF040u;
  v4 = ppDockBar;
  if ( ppDockBar != nullptr )
    *ppDockBar = nullptr;
  m_pNodeHead = this->m_listControlBars.m_pNodeHead;
  if ( m_pNodeHead == nullptr )
    return 0;
  while ( 1 )
  {
    data = (CDockBar *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data->IsDockBar(this: data) != 0 && IsWindowVisible(hWnd: data->m_hWnd) )
    {
      v7 = dwDockStyle & data->m_dwStyle;
      if ( (v7 & 0xF000) != 0 && (data->m_bFloating == 0 || (v7 & 0x40) != 0) )
      {
        m_hWnd = data->m_hWnd;
        memset(&rectBar, 0, sizeof(rectBar));
        GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
        if ( rectBar.right == rectBar.left )
          ++rectBar.right;
        if ( rectBar.bottom == rectBar.top )
          ++rectBar.bottom;
        if ( IntersectRect(lprcDst: &rectBar, lprcSrc1: &rectBar, lprcSrc2: &rect) )
          break;
      }
    }
    if ( m_pNodeHead == nullptr )
      return 0;
  }
  if ( v4 != nullptr )
    *v4 = data;
  return dwDockStyle & data->m_dwStyle;
}

//------------------------------------------------------------------------------
// Address: 0x10355569
// Name: protected: void CDockBar::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::OnPaint(CDockBar *this)
{
  CDockBar_vtbl *v2; // eax
  CPaintDC v3; // [esp+10h] [ebp-64h] BYREF
  int v4; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v2 = this->__vftable;
  v4 = 0;
  if ( v2->IsVisible(this) != 0 && this->GetDockedVisibleCount(this) != 0 )
    this->DoPaint(this, a2: &v3);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x103555C0
// Name: protected: void CDockBar::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::OnWindowPosChanging(CDockBar *this, tagWINDOWPOS *lpWndPos)
{
  unsigned int *p_m_dwStyle; // esi
  unsigned int m_dwStyle; // edi

  p_m_dwStyle = &this->m_dwStyle;
  m_dwStyle = this->m_dwStyle;
  this->m_dwStyle = m_dwStyle & 0xFFFFF0FF;
  CControlBar::OnWindowPosChanging(this, lpWndPos);
  *p_m_dwStyle = m_dwStyle;
}

//------------------------------------------------------------------------------
// Address: 0x103555E8
// Name: public: void CControlBar::EnableDocking(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::EnableDocking(CControlBar *this, unsigned int dwDockStyle)
{
  bool v3; // zf
  CDockContext *v4; // ecx
  CDockContext *v5; // eax

  v3 = this->m_pDockContext == nullptr;
  this->m_dwDockStyle = dwDockStyle;
  if ( v3 )
  {
    v4 = (CDockContext *)operator new(nSize: 0xB0u);
    if ( v4 != nullptr )
      v5 = CDockContext::CDockContext(this: v4, pBar: this);
    else
      v5 = nullptr;
    this->m_pDockContext = v5;
  }
  if ( this->m_hWndOwner == nullptr )
    this->m_hWndOwner = GetParent(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1035564A
// Name: public: virtual void CMiniDockFrameWnd::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMiniDockFrameWnd::RecalcLayout(CMiniDockFrameWnd *this, int bNotify)
{
  char szTitle[260]; // [esp+4h] [ebp-108h] BYREF

  if ( this->m_bInRecalcLayout == 0 )
  {
    CFrameWnd::RecalcLayout(this, bNotify);
    CWnd::GetWindowTextA(this: &this->m_wndDockBar, lpszString: szTitle, nMaxCount: 260);
    AfxSetWindowText(hWndCtrl: this->m_hWnd, lpszNew: szTitle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103556A8
// Name: public: virtual struct CRuntimeClass __near * CDockBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDockBar::GetRuntimeClass(CDockBar *this)
{
  return &CDockBar::classCDockBar;
}

//------------------------------------------------------------------------------
// Address: 0x103556AE
// Name: public: virtual struct CRuntimeClass __near * CMiniDockFrameWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMiniDockFrameWnd::GetRuntimeClass(CMiniDockFrameWnd *this)
{
  return &CMiniDockFrameWnd::classCMiniDockFrameWnd;
}

//------------------------------------------------------------------------------
// Address: 0x103556B4
// Name: public: CDockBar::CDockBar(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockBar *__thiscall CDockBar::CDockBar(CDockBar *this, int bFloating)
{
  CControlBar::CControlBar(this);
  this->__vftable = (CDockBar_vtbl *)&CDockBar::`vftable';
  CPtrArray::CPtrArray(this: &this->m_arrBars);
  this->m_rectLayout.left = 0;
  this->m_rectLayout.top = 0;
  this->m_rectLayout.right = 0;
  this->m_rectLayout.bottom = 0;
  this->m_bFloating = bFloating;
  this->m_bAutoDelete = 1;
  CUIntArray::SetAtGrow(this: &this->m_arrBars, nIndex: this->m_arrBars.m_nSize, newElement: nullptr);
  this->m_bLayoutQuery = 0;
  SetRectEmpty(lprc: &this->m_rectLayout);
  this->m_cyTopBorder = 0;
  this->m_cyBottomBorder = 0;
  this->m_cxRightBorder = 0;
  this->m_cxLeftBorder = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10355740
// Name: public: virtual int CDockBar::Create(class CWnd __near *,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::Create(CDockBar *this, CWnd *pParentWnd, unsigned int dwStyle, unsigned int nID)
{
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  if ( pParentWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_dwStyle = dwStyle & 0x40FFFF;
  AfxEndDeferRegisterClass(fToRegister: 2);
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  return CWnd::Create(
           this,
           lpszClassName: "AfxControlBar100s",
           lpszWindowName: nullptr,
           dwStyle,
           &rect,
           pParentWnd,
           nID,
           pContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103557BA
// Name: protected: long CDockBar::OnSizeParent(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::OnSizeParent(CDockBar *this, unsigned int wParam, int lParam)
{
  int result; // eax
  CRect *p_m_rectLayout; // [esp+1Ch] [ebp-8h]
  int bLayoutQuery; // [esp+20h] [ebp-4h]
  CRect rectLayout; // 0:^14.16

  bLayoutQuery = this->m_bLayoutQuery;
  rectLayout = this->m_rectLayout;
  p_m_rectLayout = &this->m_rectLayout;
  this->m_bLayoutQuery = *(_DWORD *)lParam == 0;
  CopyRect(lprcDst: &this->m_rectLayout, lprcSrc: (const RECT *)(lParam + 4));
  result = CControlBar::OnSizeParent(this, __formal: wParam, lParam);
  *p_m_rectLayout = rectLayout;
  this->m_bLayoutQuery = bLayoutQuery;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10355822
// Name: protected: void CDockBar::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::OnNcCalcSize(CDockBar *this, int __formal, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  this->CalcInsideRect(this, a2: &rect, a3: this->m_dwStyle & 0xA000);
  lpncsp->rgrc[0].left += rect.left;
  lpncsp->rgrc[0].top += rect.top;
  lpncsp->rgrc[0].right += rect.right;
  lpncsp->rgrc[0].bottom += rect.bottom;
}

//------------------------------------------------------------------------------
// Address: 0x10355895
// Name: protected: int CDockBar::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::OnEraseBkgnd(CDockBar *this, CDC *pDC)
{
  void *m_hReBarTheme; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  if ( pDC == nullptr )
    AfxThrowInvalidArgException();
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  m_hReBarTheme = this->m_hReBarTheme;
  if ( m_hReBarTheme == nullptr )
    return CWnd::Default(this);
  if ( CThemeHelper::IsThemeBackgroundPartiallyTransparent(hTheme: m_hReBarTheme, nPartId: 6, nStateId: 0) != 0 )
    CThemeHelper::DrawThemeParentBackground(hwnd: this->m_hWnd, hdc: pDC->m_hDC, prc: &rect);
  if ( CThemeHelper::DrawThemeBackground(
         hTheme: this->m_hReBarTheme,
         hdc: pDC->m_hDC,
         nPartId: 6,
         nStateId: 0,
         pRect: &rect,
         pClipRect: nullptr) >= 0 )
    return 1;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10355939
// Name: public: int CDockBar::FindBar(class CControlBar __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::FindBar(CDockBar *this, CControlBar *pBar, int nPosExclude)
{
  int m_nSize; // edx
  int result; // eax

  m_nSize = this->m_arrBars.m_nSize;
  result = 0;
  if ( m_nSize <= 0 )
    return -1;
  while ( 1 )
  {
    if ( result != nPosExclude )
    {
      if ( result < 0 || result >= m_nSize )
        AfxThrowInvalidArgException();
      if ( this->m_arrBars.m_pData[result] == pBar )
        break;
    }
    if ( ++result >= m_nSize )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10355979
// Name: protected: class CControlBar __near * CDockBar::GetDockedControlBar(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CControlBar *__thiscall CDockBar::GetDockedControlBar(CDockBar *this, int nPos)
{
  void *v2; // ecx

  if ( nPos < 0 || nPos >= this->m_arrBars.m_nSize )
    AfxThrowInvalidArgException();
  v2 = this->m_arrBars.m_pData[nPos];
  return (unsigned int)v2 > 0xFFFF ? (CControlBar *)v2 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103559AB
// Name: protected: int CDockBar::Insert(class CControlBar __near *,class CRect,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::Insert(CDockBar *this, CControlBar *pBarIns, CRect rect, CPoint ptMid)
{
  unsigned int v5; // ebx
  CControlBar *DockedControlBar; // edi
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  bool v10; // sf
  bool v11; // of
  int y; // eax
  int v13; // edi
  int nTotalWidth; // [esp+10h] [ebp-24h]
  int nWidth; // [esp+14h] [ebp-20h]
  int nPosInsAfter; // [esp+18h] [ebp-1Ch]
  int nPos; // [esp+1Ch] [ebp-18h]
  CRect rectBar; // [esp+20h] [ebp-14h] BYREF

  if ( this == nullptr || pBarIns == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  v5 = this->m_dwStyle & 0xA000;
  nPosInsAfter = 0;
  nWidth = 0;
  nTotalWidth = 0;
  nPos = 0;
  if ( this->m_arrBars.m_nSize <= 0 )
  {
LABEL_29:
    v13 = nPosInsAfter + 1;
    CPtrArray::InsertAt(this: &this->m_arrBars, nIndex: nPosInsAfter + 1, newElement: nullptr, nCount: 1);
    goto LABEL_30;
  }
  while ( 1 )
  {
    DockedControlBar = CDockBar::GetDockedControlBar(this, nPos);
    if ( DockedControlBar != nullptr )
    {
      if ( DockedControlBar->IsVisible(this: DockedControlBar) == 0 )
        goto LABEL_28;
      memset(&rectBar, 0, sizeof(rectBar));
      GetWindowRect(hWnd: DockedControlBar->m_hWnd, lpRect: &rectBar);
      CWnd::ScreenToClient(this, lpRect: &rectBar);
      if ( v5 != 0 )
        v7 = rectBar.bottom - rectBar.top;
      else
        v7 = rectBar.right - rectBar.left - 1;
      if ( nWidth <= v7 )
      {
        if ( v5 != 0 )
          nWidth = rectBar.bottom - rectBar.top;
        else
          nWidth = rectBar.right - rectBar.left - 1;
      }
      v8 = 0;
      if ( v5 != 0 )
      {
        v11 = __OFSUB__(rect.left, rectBar.left);
        v9 = rect.left == rectBar.left;
        v10 = rect.left - rectBar.left < 0;
      }
      else
      {
        v11 = __OFSUB__(rect.top, rectBar.top);
        v9 = rect.top == rectBar.top;
        v10 = rect.top - rectBar.top < 0;
      }
      LOBYTE(v8) = !(v10 ^ v11 | v9);
      if ( v8 == 0 )
        goto LABEL_28;
      goto LABEL_27;
    }
    if ( nPos < 0 || nPos >= this->m_arrBars.m_nSize )
      goto LABEL_2;
    if ( this->m_arrBars.m_pData[nPos] == nullptr )
      break;
LABEL_28:
    if ( ++nPos >= this->m_arrBars.m_nSize )
      goto LABEL_29;
  }
  if ( nWidth != 0 )
    nTotalWidth += nWidth - afxData.cyBorder2;
  y = ptMid.y;
  nWidth = 0;
  if ( v5 == 0 )
    y = ptMid.x;
  if ( y >= nTotalWidth )
  {
LABEL_27:
    nPosInsAfter = nPos;
    goto LABEL_28;
  }
  if ( nPos == 0 )
    CPtrArray::InsertAt(this: &this->m_arrBars, nIndex: nPosInsAfter + 1, newElement: nullptr, nCount: 1);
  v13 = nPosInsAfter + 1;
LABEL_30:
  CPtrArray::InsertAt(this: &this->m_arrBars, nIndex: v13, newElement: pBarIns, nCount: 1);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10355B48
// Name: public: int CMiniDockFrameWnd::OnMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMiniDockFrameWnd::OnMouseActivate(
        CMiniDockFrameWnd *this,
        CWnd *pDesktopWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  if ( nHitTest - 10 > 7 )
    return CWnd::Default(this);
  else
    return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10355B66
// Name: public: void CMiniDockFrameWnd::OnNcLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMiniDockFrameWnd::OnNcLButtonDown(CMiniDockFrameWnd *this, unsigned int nHitTest, CPoint point)
{
  int v4; // edi
  CControlBar *i; // eax
  int v6; // edi
  CControlBar *j; // eax

  if ( nHitTest == 2 )
  {
    CWnd::ActivateTopParent(this);
    if ( (this->m_wndDockBar.m_dwStyle & 0x40) == 0 )
    {
      v4 = 1;
      for ( i = nullptr; i == nullptr; i = CDockBar::GetDockedControlBar(this: &this->m_wndDockBar, nPos: v4++) )
      {
        if ( v4 >= this->m_wndDockBar.m_arrBars.m_nSize )
          break;
      }
      if ( i != nullptr && i->m_pDockContext != nullptr )
      {
        ((void (__thiscall *)(CDockContext *, int, int))i->m_pDockContext->StartDrag)(
          a1: i->m_pDockContext,
          a2: point.x,
          a3: point.y);
        return;
      }
LABEL_7:
      AfxThrowInvalidArgException();
    }
    goto LABEL_17;
  }
  if ( nHitTest - 10 > 7 )
  {
LABEL_17:
    CWnd::Default(this);
    return;
  }
  CWnd::ActivateTopParent(this);
  v6 = 1;
  for ( j = nullptr; j == nullptr; j = CDockBar::GetDockedControlBar(this: &this->m_wndDockBar, nPos: v6++) )
  {
    if ( v6 >= this->m_wndDockBar.m_arrBars.m_nSize )
      break;
  }
  if ( j == nullptr || j->m_pDockContext == nullptr )
    goto LABEL_7;
  ((void (__thiscall *)(CDockContext *, unsigned int, int, int))j->m_pDockContext->StartResize)(
    a1: j->m_pDockContext,
    a2: nHitTest,
    a3: point.x,
    a4: point.y);
}

//------------------------------------------------------------------------------
// Address: 0x10355C2A
// Name: public: void CMiniDockFrameWnd::OnNcLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMiniDockFrameWnd::OnNcLButtonDblClk(CMiniDockFrameWnd *this, unsigned int nHitTest, CPoint point)
{
  int v4; // edi
  CControlBar *i; // eax

  if ( nHitTest != 2 || (CWnd::ActivateTopParent(this), (this->m_wndDockBar.m_dwStyle & 0x40) != 0) )
  {
    CWnd::Default(this);
  }
  else
  {
    v4 = 1;
    for ( i = nullptr; i == nullptr; i = CDockBar::GetDockedControlBar(this: &this->m_wndDockBar, nPos: v4++) )
    {
      if ( v4 >= this->m_wndDockBar.m_arrBars.m_nSize )
        break;
    }
    if ( i == nullptr || i->m_pDockContext == nullptr )
      AfxThrowInvalidArgException();
    i->m_pDockContext->ToggleDocking(this: i->m_pDockContext);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10355C93
// Name: public: virtual CDockBar::~CDockBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::~CDockBar(CDockBar *this)
{
  int i; // edi
  CControlBar *DockedControlBar; // eax

  this->__vftable = (CDockBar_vtbl *)&CDockBar::`vftable';
  for ( i = 0; i < this->m_arrBars.m_nSize; ++i )
  {
    DockedControlBar = CDockBar::GetDockedControlBar(this, nPos: i);
    if ( DockedControlBar != nullptr && DockedControlBar->m_pDockBar == this )
      DockedControlBar->m_pDockBar = nullptr;
  }
  CPtrArray::~CPtrArray(this: &this->m_arrBars);
  CControlBar::~CControlBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x10355CFF
// Name: public: int CDockBar::GetDockedCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::GetDockedCount(CDockBar *this)
{
  int v2; // edi
  int i; // ebx

  v2 = 0;
  for ( i = 0; v2 < this->m_arrBars.m_nSize; ++v2 )
  {
    if ( CDockBar::GetDockedControlBar(this, nPos: v2) != nullptr )
      ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10355D2E
// Name: public: virtual int CDockBar::GetDockedVisibleCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::GetDockedVisibleCount(CDockBar *this)
{
  int v2; // edi
  int i; // ebx
  CControlBar *DockedControlBar; // eax

  v2 = 0;
  for ( i = 0; v2 < this->m_arrBars.m_nSize; ++v2 )
  {
    DockedControlBar = CDockBar::GetDockedControlBar(this, nPos: v2);
    if ( DockedControlBar != nullptr && DockedControlBar->IsVisible(this: DockedControlBar) != 0 )
      ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10355D6B
// Name: public: void CDockBar::RemovePlaceHolder(class CControlBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::RemovePlaceHolder(CDockBar *this, CControlBar *pBar)
{
  CControlBar *DlgCtrlID; // eax
  int Bar; // eax
  int v5; // edi
  int v6; // eax
  int m_nSize; // edx
  void **m_pData; // ecx

  DlgCtrlID = pBar;
  if ( (unsigned int)pBar > 0xFFFF )
    DlgCtrlID = (CControlBar *)GetDlgCtrlID(hWnd: pBar->m_hWnd);
  Bar = CDockBar::FindBar(this, pBar: DlgCtrlID, nPosExclude: -1);
  v5 = Bar;
  if ( Bar > 0 )
  {
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
      this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
      nIndex: Bar,
      nCount: 1);
    v6 = v5 - 1;
    if ( v5 - 1 < 0 )
      goto LABEL_11;
    m_nSize = this->m_arrBars.m_nSize;
    if ( v6 >= m_nSize )
      goto LABEL_11;
    m_pData = this->m_arrBars.m_pData;
    if ( m_pData[v6] != nullptr )
      return;
    if ( v5 >= m_nSize )
LABEL_11:
      AfxThrowInvalidArgException();
    if ( m_pData[v5] == nullptr )
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
        nIndex: v5,
        nCount: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10355DE6
// Name: public: int CDockBar::RemoveControlBar(class CControlBar __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockBar::RemoveControlBar(CDockBar *this, CControlBar *pBar, int nPosExclude, int nAddPlaceHolder)
{
  int Bar; // eax
  int v6; // esi
  void **v7; // ebx
  int v8; // eax
  int m_nSize; // edx
  void **m_pData; // ecx
  int v11; // eax
  int v12; // edx
  void **v13; // ecx
  CFrameWnd *DockingFrame; // esi

  if ( this == nullptr )
    goto LABEL_2;
  if ( pBar == nullptr )
    goto LABEL_2;
  Bar = CDockBar::FindBar(this, pBar, nPosExclude);
  v6 = Bar;
  if ( Bar <= 0 )
    goto LABEL_2;
  if ( nAddPlaceHolder == 1 )
  {
    if ( Bar < this->m_arrBars.m_nSize )
    {
      v7 = &this->m_arrBars.m_pData[Bar];
      *v7 = (void *)GetDlgCtrlID(hWnd: pBar->m_hWnd);
      if ( v6 < this->m_arrBars.m_nSize )
      {
        if ( CDockBar::FindBar(this, pBar: (CControlBar *)this->m_arrBars.m_pData[v6], nPosExclude: v6) <= 0 )
          goto LABEL_23;
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
          this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
          nIndex: v6,
          nCount: 1);
        v8 = v6 - 1;
        if ( v6 - 1 >= 0 )
        {
          m_nSize = this->m_arrBars.m_nSize;
          if ( v8 < m_nSize )
          {
            m_pData = this->m_arrBars.m_pData;
            if ( m_pData[v8] != nullptr )
              goto LABEL_23;
            if ( v6 < m_nSize )
            {
              if ( m_pData[v6] == nullptr )
                CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
                  this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
                  nIndex: v6,
                  nCount: 1);
              goto LABEL_23;
            }
          }
        }
      }
    }
LABEL_2:
    AfxThrowInvalidArgException();
  }
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
    this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
    nIndex: Bar,
    nCount: 1);
  v11 = v6 - 1;
  if ( v6 - 1 < 0 )
    goto LABEL_2;
  v12 = this->m_arrBars.m_nSize;
  if ( v11 >= v12 )
    goto LABEL_2;
  v13 = this->m_arrBars.m_pData;
  if ( v13[v11] == nullptr )
  {
    if ( v6 >= v12 )
      goto LABEL_2;
    if ( v13[v6] == nullptr )
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrBars,
        nIndex: v6,
        nCount: 1);
  }
  if ( nAddPlaceHolder != -1 )
    CDockBar::RemovePlaceHolder(this, pBar);
LABEL_23:
  if ( pBar->m_pDockContext == nullptr )
    return 0;
  DockingFrame = CControlBar::GetDockingFrame(this);
  if ( this->m_bFloating == 0 || this->GetDockedVisibleCount(this) != 0 )
  {
    DockingFrame->m_nIdleFlags |= 0xCu;
    return 0;
  }
  if ( CDockBar::GetDockedCount(this) != 0 )
  {
    CWnd::ShowWindow(this: DockingFrame, nCmdShow: 0);
    return 0;
  }
  DockingFrame->DestroyWindow(this: DockingFrame);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10355F69
// Name: public: virtual class CSize CDockBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDockBar::CalcFixedLayout(CDockBar *this, CSize *result, int bStretch, int bHorz)
{
  CDockBar_vtbl *v5; // eax
  int v6; // eax
  int v7; // ecx
  CFrameWnd *ParentFrame; // eax
  CDockBar *v9; // edi
  int v10; // esi
  int cx; // ebx
  CDockBar *v12; // edi
  unsigned int m_dwStyle; // eax
  unsigned int v14; // eax
  int v15; // eax
  CRect *p_m_rectMRUDockPos; // edi
  int v17; // eax
  CRect *v18; // edi
  CSize *v19; // ecx
  int cy; // eax
  int v21; // eax
  int v22; // eax
  CSize *v23; // esi
  int v24; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-9Ch]
  int pt_4; // [esp+10h] [ebp-84h]
  CSize sizeBar; // [esp+14h] [ebp-80h] BYREF
  CSize sizeMax; // [esp+1Ch] [ebp-78h]
  CSize *v30; // [esp+24h] [ebp-70h]
  unsigned int v31; // [esp+28h] [ebp-6Ch]
  int bWrapped; // [esp+2Ch] [ebp-68h]
  int nWidth; // [esp+30h] [ebp-64h]
  CDockBar *v34; // [esp+34h] [ebp-60h]
  int nPos; // [esp+38h] [ebp-5Ch]
  CControlBar *pBar; // [esp+3Ch] [ebp-58h]
  AFX_SIZEPARENTPARAMS layout; // [esp+40h] [ebp-54h] BYREF
  CRect rect; // [esp+60h] [ebp-34h] BYREF
  CRect rectBar; // [esp+70h] [ebp-24h] BYREF
  tagRECT rc; // [esp+80h] [ebp-14h] BYREF

  v34 = this;
  v30 = result;
  if ( this == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  CControlBar::CalcFixedLayout((CBasePane *)this, result, bStretch, bHorz);
  if ( IsRectEmpty(lprc: &this->m_rectLayout) )
  {
    memset(&rectBar, 0, sizeof(rectBar));
    ParentFrame = CWnd::GetParentFrame(this);
    if ( ParentFrame == nullptr )
      goto LABEL_2;
    GetClientRect(hWnd: ParentFrame->m_hWnd, lpRect: &rectBar);
    v6 = rectBar.right - rectBar.left;
    v7 = rectBar.bottom - rectBar.top;
  }
  else
  {
    v5 = this->__vftable;
    rectBar = this->m_rectLayout;
    v5->CalcInsideRect(this, a2: &rectBar, a3: bHorz);
    v6 = rectBar.right - rectBar.left;
    v7 = rectBar.bottom - rectBar.top;
  }
  sizeMax.cy = v7;
  sizeMax.cx = v6;
  if ( this->m_bLayoutQuery != 0 )
    layout.hDWP = nullptr;
  else
    layout.hDWP = BeginDeferWindowPos(nNumWindows: this->m_arrBars.m_nSize);
  v9 = v34;
  v10 = -afxData.cyBorder2;
  cx = -afxData.cxBorder2;
  pt_4 = -afxData.cyBorder2;
  nWidth = 0;
  bWrapped = 0;
  nPos = 0;
  if ( v34->m_arrBars.m_nSize > 0 )
  {
    v31 = -4;
    while ( 1 )
    {
      pBar = CDockBar::GetDockedControlBar(this: v34, nPos);
      if ( nPos < 0 )
        goto LABEL_2;
      v12 = v34;
      if ( nPos >= v34->m_arrBars.m_nSize )
        goto LABEL_2;
      if ( pBar != nullptr )
      {
        if ( pBar->IsVisible(this: pBar) != 0 )
        {
          m_dwStyle = pBar->m_dwStyle;
          if ( (m_dwStyle & 4) != 0 && (m_dwStyle & 1) != 0 )
            v14 = 6;
          else
            v14 = (pBar->m_dwStyle & 0xA000) != 0 ? 10 : 16;
          pBar->CalcDynamicLayout(this: pBar, result: &sizeBar, a3: -1, a4: v14);
          rc.right = cx + sizeBar.cx;
          rc.bottom = v10 + sizeBar.cy;
          memset(&rectBar, 0, sizeof(rectBar));
          m_hWnd = pBar->m_hWnd;
          rc.left = cx;
          rc.top = v10;
          GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
          CWnd::ScreenToClient(this: v12, lpRect: &rectBar);
          if ( bHorz != 0 )
          {
            if ( rectBar.left > rc.left && v12->m_bFloating == 0 )
              OffsetRect(lprc: &rc, dx: rectBar.left - rc.left, dy: 0);
            if ( rc.right > sizeMax.cx && v12->m_bFloating == 0 )
            {
              v15 = sizeMax.cx - (rc.right - afxData.cxBorder2 - rc.left);
              if ( v15 <= cx )
                v15 = cx;
              OffsetRect(lprc: &rc, dx: v15 - rc.left, dy: 0);
            }
            if ( bWrapped != 0 )
            {
              bWrapped = 0;
              OffsetRect(lprc: &rc, dx: -(rc.left + afxData.cxBorder2), dy: 0);
            }
            else if ( rc.left >= sizeMax.cx - afxData.cxBorder2 && nPos > 0 )
            {
              if ( nPos - 1 >= v12->m_arrBars.m_nSize )
                goto LABEL_2;
              if ( v12->m_arrBars.m_pData[v31 / 4] != nullptr )
                goto LABEL_42;
            }
            if ( !EqualRect(lprc1: &rc, lprc2: &rectBar) )
            {
              if ( v12->m_bLayoutQuery == 0 && (pBar->m_dwStyle & 1) == 0 )
              {
                p_m_rectMRUDockPos = &pBar->m_pDockContext->m_rectMRUDockPos;
                p_m_rectMRUDockPos->left = rc.left;
                p_m_rectMRUDockPos = (CRect *)((char *)p_m_rectMRUDockPos + 4);
                p_m_rectMRUDockPos->left = rc.top;
                p_m_rectMRUDockPos = (CRect *)((char *)p_m_rectMRUDockPos + 4);
                p_m_rectMRUDockPos->left = rc.right;
                p_m_rectMRUDockPos->top = rc.bottom;
                v10 = pt_4;
              }
              AfxRepositionWindow(lpLayout: &layout, hWnd: pBar->m_hWnd, lpRect: &rc);
            }
            cx = rc.left + sizeBar.cx - afxData.cxBorder2;
            if ( nWidth <= sizeBar.cy )
              nWidth = sizeBar.cy;
LABEL_65:
            pBar->RecalcDelayShow(this: pBar, a2: &layout);
            goto LABEL_80;
          }
          if ( rectBar.top > rc.top && v12->m_bFloating == 0 )
            OffsetRect(lprc: &rc, dx: 0, dy: rectBar.top - rc.top);
          if ( rc.bottom > sizeMax.cy && v12->m_bFloating == 0 )
          {
            v17 = sizeMax.cy - (rc.bottom - rc.top - afxData.cyBorder2);
            if ( v17 <= v10 )
              v17 = v10;
            OffsetRect(lprc: &rc, dx: 0, dy: v17 - rc.top);
          }
          if ( bWrapped != 0 )
          {
            bWrapped = 0;
            OffsetRect(lprc: &rc, dx: 0, dy: -(afxData.cyBorder2 + rc.top));
          }
          else if ( rc.top >= sizeMax.cy - afxData.cyBorder2 && nPos > 0 )
          {
            if ( nPos - 1 >= v12->m_arrBars.m_nSize )
              goto LABEL_2;
            if ( v12->m_arrBars.m_pData[v31 / 4] != nullptr )
            {
LABEL_42:
              CPtrArray::InsertAt(this: &v12->m_arrBars, nIndex: nPos, newElement: nullptr, nCount: 1);
              bWrapped = 1;
LABEL_67:
              if ( nWidth != 0 )
              {
                v19 = v30;
                if ( bHorz != 0 )
                {
                  v10 += nWidth - afxData.cyBorder2;
                  pt_4 = v10;
                  if ( v30->cx > cx )
                    cx = v30->cx;
                  cy = v30->cy;
                  v30->cx = cx;
                  if ( cy <= v10 )
                    cy = v10;
                  v19->cy = cy;
                  cx = -afxData.cxBorder2;
                }
                else
                {
                  cx += nWidth - afxData.cxBorder2;
                  v21 = v30->cx;
                  if ( v30->cx <= cx )
                    v21 = cx;
                  v30->cx = v21;
                  v22 = v19->cy;
                  if ( v22 <= v10 )
                    v22 = v10;
                  v19->cy = v22;
                  v10 = -afxData.cyBorder2;
                  pt_4 = -afxData.cyBorder2;
                }
                nWidth = 0;
              }
              goto LABEL_80;
            }
          }
          if ( !EqualRect(lprc1: &rc, lprc2: &rectBar) )
          {
            if ( v12->m_bLayoutQuery == 0 && (pBar->m_dwStyle & 1) == 0 )
            {
              v18 = &pBar->m_pDockContext->m_rectMRUDockPos;
              v18->left = rc.left;
              v18 = (CRect *)((char *)v18 + 4);
              v18->left = rc.top;
              v18 = (CRect *)((char *)v18 + 4);
              v18->left = rc.right;
              v18->top = rc.bottom;
            }
            AfxRepositionWindow(lpLayout: &layout, hWnd: pBar->m_hWnd, lpRect: &rc);
          }
          v10 = sizeBar.cy + rc.top - afxData.cyBorder2;
          pt_4 = v10;
          if ( nWidth > sizeBar.cx )
            goto LABEL_65;
          nWidth = sizeBar.cx;
        }
        if ( bWrapped == 0 )
          goto LABEL_65;
      }
      else if ( v34->m_arrBars.m_pData[v31 / 4 + 1] == nullptr )
      {
        goto LABEL_67;
      }
LABEL_80:
      ++nPos;
      v31 += 4;
      if ( nPos >= v34->m_arrBars.m_nSize )
      {
        v9 = v34;
        break;
      }
    }
  }
  v23 = v30;
  if ( v9->m_bLayoutQuery == 0 && layout.hDWP != nullptr )
    EndDeferWindowPos(hWinPosInfo: layout.hDWP);
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  v9->CalcInsideRect(this: v9, a2: &rect, a3: bHorz);
  if ( (bStretch == 0 || bHorz == 0) && v23->cx != 0 )
    v23->cx = rect.left + v23->cx - rect.right;
  if ( bStretch == 0 || bHorz != 0 )
  {
    v24 = v23->cy;
    if ( v24 != 0 )
      v23->cy = rect.top + v24 - rect.bottom;
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x103564EF
// Name: public: void CDockBar::ShowAll(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::ShowAll(CDockBar *this, int bShow)
{
  int i; // ebx
  CControlBar *DockedControlBar; // eax
  CControlBar *v5; // edi
  CFrameWnd *DockingFrame; // eax

  for ( i = 0; i < this->m_arrBars.m_nSize; ++i )
  {
    DockedControlBar = CDockBar::GetDockedControlBar(this, nPos: i);
    v5 = DockedControlBar;
    if ( DockedControlBar != nullptr )
    {
      DockingFrame = CControlBar::GetDockingFrame(this: DockedControlBar);
      CFrameWnd::ShowControlBar(this: DockingFrame, pBar: v5, bShow, bDelay: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10356535
// Name: public: CMiniDockFrameWnd::CMiniDockFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMiniDockFrameWnd *__thiscall CMiniDockFrameWnd::CMiniDockFrameWnd(CMiniDockFrameWnd *this)
{
  CMiniFrameWnd::CMiniFrameWnd(this);
  this->__vftable = (CMiniDockFrameWnd_vtbl *)&CMiniDockFrameWnd::`vftable';
  CDockBar::CDockBar(this: &this->m_wndDockBar, bFloating: 1);
  this->m_wndDockBar.m_bAutoDelete = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10356571
// Name: public: virtual CMiniDockFrameWnd::~CMiniDockFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMiniDockFrameWnd::~CMiniDockFrameWnd(CMiniDockFrameWnd *this)
{
  CDockBar::~CDockBar(this: &this->m_wndDockBar);
  CMiniFrameWnd::~CMiniFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103565A2
// Name: public: void CMiniDockFrameWnd::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMiniDockFrameWnd::OnClose(CMiniDockFrameWnd *this)
{
  CDockBar::ShowAll(this: &this->m_wndDockBar, bShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103565B0
// Name: public: static class CObject __near * CMiniDockFrameWnd::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMiniDockFrameWnd *__stdcall CMiniDockFrameWnd::CreateObject()
{
  CMiniDockFrameWnd *v0; // ecx
  CMiniDockFrameWnd *result; // eax

  v0 = (CMiniDockFrameWnd *)operator new(nSize: 0x204u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMiniDockFrameWnd::CMiniDockFrameWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103565E0
// Name: protected: virtual struct AFX_MSGMAP const __near * CDockBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDockBar::GetMessageMap(CDockBar *this)
{
  return (const AFX_MSGMAP *)&off_10677C74;
}

//------------------------------------------------------------------------------
// Address: 0x10356607
// Name: public: void CDockBar::DockControlBar(class CControlBar __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::DockControlBar(CDockBar *this, CControlBar *pBar, const tagRECT *lpRect)
{
  CControlBar *v3; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  HWND Parent; // eax
  CDockBar *m_pDockBar; // ecx
  BOOL v9; // eax
  CFrameWnd *DockingFrame; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-14Ch]
  CPoint v12; // [esp-8h] [ebp-14Ch]
  int nPos; // [esp+Ch] [ebp-138h]
  int bShow; // [esp+10h] [ebp-134h]
  CRect rectBar; // [esp+1Ch] [ebp-128h] BYREF
  CRect rect; // [esp+2Ch] [ebp-118h] BYREF
  char szTitle[260]; // [esp+3Ch] [ebp-108h] BYREF

  v3 = pBar;
  if ( this == nullptr || pBar == nullptr )
    AfxThrowInvalidArgException();
  m_hWnd = pBar->m_hWnd;
  memset(&rectBar, 0, sizeof(rectBar));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
  if ( pBar->m_pDockBar != this || lpRect != nullptr && !EqualRect(lprc1: &rectBar, lprc2: lpRect) )
  {
    if ( this->m_bFloating != 0 && (pBar->m_dwDockStyle & 0x40) != 0 )
      this->m_dwStyle |= 0x40u;
    this->m_dwStyle &= 0xFFFFFFF9;
    v5 = this->m_dwStyle | pBar->m_dwStyle & 6;
    this->m_dwStyle = v5;
    if ( (v5 & 0x40) == 0 )
    {
      CWnd::GetWindowTextA(this: pBar, lpszString: szTitle, nMaxCount: 260);
      AfxSetWindowText(hWndCtrl: this->m_hWnd, lpszNew: szTitle);
    }
    if ( this->m_bFloating != 0 )
      v6 = pBar->m_dwStyle ^ (this->m_dwStyle ^ pBar->m_dwStyle) & 0xF000 | 0xF01;
    else
      v6 = (pBar->m_dwStyle ^ (this->m_dwStyle ^ pBar->m_dwStyle) & 0xF000) & 0xFFFFF0FE | 0xF00;
    CControlBar::SetBarStyle(this: pBar, dwStyle: v6);
    bShow = 0;
    if ( pBar->m_pDockBar != this && IsWindowVisible(hWnd: pBar->m_hWnd) )
    {
      CWnd::SetWindowPos(this: pBar, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x97u);
      bShow = 1;
    }
    nPos = -1;
    if ( lpRect != nullptr )
    {
      CopyRect(lprcDst: &rect, lprcSrc: lpRect);
      CWnd::ScreenToClient(this, lpRect: &rect);
      v12.y = rect.top + (rect.bottom - rect.top) / 2;
      v12.x = rect.left + (rect.right - rect.left) / 2;
      nPos = CDockBar::Insert(this, pBarIns: pBar, rect, ptMid: v12);
      CWnd::SetWindowPos(
        this: pBar,
        pWndInsertAfter: nullptr,
        x: rect.left,
        y: rect.top,
        cx: rect.right - rect.left,
        cy: rect.bottom - rect.top,
        nFlags: 0x114u);
      v3 = pBar;
    }
    else
    {
      CUIntArray::SetAtGrow(this: &this->m_arrBars, nIndex: this->m_arrBars.m_nSize, newElement: pBar);
      CUIntArray::SetAtGrow(this: &this->m_arrBars, nIndex: this->m_arrBars.m_nSize, newElement: nullptr);
      CWnd::SetWindowPos(
        this: pBar,
        pWndInsertAfter: nullptr,
        x: -afxData.cxBorder2,
        y: -afxData.cyBorder2,
        cx: 0,
        cy: 0,
        nFlags: 0x115u);
    }
    Parent = GetParent(hWnd: v3->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) != this )
      CWnd::SetParent(this: v3, pWndNewParent: this);
    m_pDockBar = v3->m_pDockBar;
    if ( m_pDockBar == this )
    {
      CDockBar::RemoveControlBar(this: m_pDockBar, pBar: v3, nPosExclude: nPos, nAddPlaceHolder: 0);
    }
    else if ( m_pDockBar != nullptr )
    {
      v9 = this->m_bFloating != 0 && m_pDockBar->m_bFloating == 0;
      CDockBar::RemoveControlBar(this: m_pDockBar, pBar: v3, nPosExclude: -1, nAddPlaceHolder: v9);
    }
    v3->m_pDockBar = this;
    if ( bShow != 0 )
      CWnd::SetWindowPos(this: v3, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x57u);
    CDockBar::RemovePlaceHolder(this, pBar: v3);
    DockingFrame = CControlBar::GetDockingFrame(this);
    DockingFrame->m_nIdleFlags |= 0xCu;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10356902
// Name: public: void CDockBar::ReDockControlBar(class CControlBar __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::ReDockControlBar(CDockBar *this, CControlBar *pBar, const tagRECT *lpRect)
{
  CControlBar *v3; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  CControlBar *DlgCtrlID; // eax
  int Bar; // eax
  int v9; // edi
  HWND Parent; // eax
  CDockBar *m_pDockBar; // ecx
  CFrameWnd *DockingFrame; // eax
  CPoint v13; // [esp-8h] [ebp-144h]
  CRect rectBar; // [esp+14h] [ebp-128h] BYREF
  CRect rect; // [esp+24h] [ebp-118h] BYREF
  char szTitle[260]; // [esp+34h] [ebp-108h] BYREF

  v3 = pBar;
  if ( this == nullptr || pBar == nullptr )
    goto LABEL_2;
  memset(&rectBar, 0, sizeof(rectBar));
  GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &rectBar);
  if ( pBar->m_pDockBar == this && (lpRect == nullptr || EqualRect(lprc1: &rectBar, lprc2: lpRect)) )
    return;
  if ( this->m_bFloating != 0 && (pBar->m_dwDockStyle & 0x40) != 0 )
    this->m_dwStyle |= 0x40u;
  this->m_dwStyle &= 0xFFFFFFF9;
  v5 = this->m_dwStyle | pBar->m_dwStyle & 6;
  this->m_dwStyle = v5;
  if ( (v5 & 0x40) == 0 )
  {
    CWnd::GetWindowTextA(this: pBar, lpszString: szTitle, nMaxCount: 260);
    AfxSetWindowText(hWndCtrl: this->m_hWnd, lpszNew: szTitle);
  }
  if ( this->m_bFloating != 0 )
    v6 = pBar->m_dwStyle ^ (this->m_dwStyle ^ pBar->m_dwStyle) & 0xF000 | 0xF01;
  else
    v6 = (pBar->m_dwStyle ^ (this->m_dwStyle ^ pBar->m_dwStyle) & 0xF000) & 0xFFFFF0FE | 0xF00;
  CControlBar::SetBarStyle(this: pBar, dwStyle: v6);
  DlgCtrlID = (CControlBar *)GetDlgCtrlID(hWnd: pBar->m_hWnd);
  Bar = CDockBar::FindBar(this, pBar: DlgCtrlID, nPosExclude: -1);
  v9 = Bar;
  if ( Bar > 0 )
  {
    if ( Bar < this->m_arrBars.m_nSize )
    {
      this->m_arrBars.m_pData[Bar] = pBar;
      goto LABEL_18;
    }
LABEL_2:
    AfxThrowInvalidArgException();
  }
LABEL_18:
  if ( lpRect != nullptr )
  {
    CopyRect(lprcDst: &rect, lprcSrc: lpRect);
    CWnd::ScreenToClient(this, lpRect: &rect);
    if ( v9 < 1 )
    {
      v13.y = rect.top + (rect.bottom - rect.top) / 2;
      v13.x = rect.left + (rect.right - rect.left) / 2;
      CDockBar::Insert(this, pBarIns: pBar, rect, ptMid: v13);
      v3 = pBar;
    }
    CWnd::SetWindowPos(
      this: v3,
      pWndInsertAfter: nullptr,
      x: rect.left,
      y: rect.top,
      cx: rect.right - rect.left,
      cy: rect.bottom - rect.top,
      nFlags: 0x114u);
  }
  else
  {
    if ( Bar < 1 )
    {
      CUIntArray::SetAtGrow(this: &this->m_arrBars, nIndex: this->m_arrBars.m_nSize, newElement: pBar);
      CUIntArray::SetAtGrow(this: &this->m_arrBars, nIndex: this->m_arrBars.m_nSize, newElement: nullptr);
    }
    CWnd::SetWindowPos(
      this: pBar,
      pWndInsertAfter: nullptr,
      x: -afxData.cxBorder2,
      y: -afxData.cyBorder2,
      cx: 0,
      cy: 0,
      nFlags: 0x115u);
  }
  Parent = GetParent(hWnd: v3->m_hWnd);
  if ( CWnd::FromHandle(hWnd: Parent) != this )
    CWnd::SetParent(this: v3, pWndNewParent: this);
  m_pDockBar = v3->m_pDockBar;
  if ( m_pDockBar != nullptr )
    CDockBar::RemoveControlBar(this: m_pDockBar, pBar: v3, nPosExclude: -1, nAddPlaceHolder: 0);
  v3->m_pDockBar = this;
  DockingFrame = CControlBar::GetDockingFrame(this);
  DockingFrame->m_nIdleFlags |= 0xCu;
}

//------------------------------------------------------------------------------
// Address: 0x10356BC1
// Name: protected: virtual struct AFX_MSGMAP const __near * CMiniDockFrameWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMiniDockFrameWnd::GetMessageMap(CMiniDockFrameWnd *this)
{
  return (const AFX_MSGMAP *)&off_10677EF0;
}

//------------------------------------------------------------------------------
// Address: 0x10356BC7
// Name: public: virtual int CMiniDockFrameWnd::Create(class CWnd __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMiniDockFrameWnd::Create(CMiniDockFrameWnd *this, CWnd *pParent, const char *dwBarStyle)
{
  CMiniDockFrameWnd *v3; // edi
  __int16 v4; // bx
  unsigned int v5; // eax
  int result; // eax
  int v7; // esi
  HMENU SystemMenu; // eax
  CMenu *v9; // eax
  CMenu *v10; // ebx
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax

  v3 = this;
  v4 = (__int16)dwBarStyle;
  this->m_bInRecalcLayout = 1;
  v5 = -2134361344;
  if ( (v4 & 4) != 0 )
    v5 = -2134363392;
  result = CMiniFrameWnd::CreateEx(
             this,
             dwExStyle: 0,
             lpClassName: nullptr,
             lpszWindowName: &var,
             dwStyle: v5,
             rect: &CFrameWnd::rectDefault,
             pParentWnd: pParent,
             nID: 0);
  if ( result != 0 )
  {
    v7 = v4 & 0x40 | ((v4 & 0x5000) != 0 ? 4096 : 0x2000);
    SystemMenu = GetSystemMenu(hWnd: v3->m_hWnd, bRevert: false);
    v9 = CMenu::FromHandle(hMenu: SystemMenu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      DeleteMenu(hMenu: v9->m_hMenu, uPosition: 0xF000u, uFlags: 0);
      DeleteMenu(hMenu: v10->m_hMenu, uPosition: 0xF020u, uFlags: 0);
      DeleteMenu(hMenu: v10->m_hMenu, uPosition: 0xF030u, uFlags: 0);
      DeleteMenu(hMenu: v10->m_hMenu, uPosition: 0xF120u, uFlags: 0);
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        this: (ATL::CSimpleStringT<char,0> *)&dwBarStyle,
        pStringMgr: StringManager);
      StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF011u);
      if ( StringResourceHandle != nullptr
        && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&dwBarStyle,
             hInstance: StringResourceHandle,
             nID: 0xF011u) != 0 )
      {
        DeleteMenu(hMenu: v10->m_hMenu, uPosition: 0xF060u, uFlags: 0);
        AppendMenuA(hMenu: v10->m_hMenu, uFlags: 0, uIDNewItem: 0xF060u, lpNewItem: dwBarStyle);
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)dwBarStyle - 1);
      v3 = this;
    }
    result = v3->m_wndDockBar.Create(this: &v3->m_wndDockBar, a2: pParent, a3: v7 | 0x50000000, a4: 59423u);
    if ( result != 0 )
    {
      CWnd::SetParent(this: &v3->m_wndDockBar, pWndNewParent: v3);
      result = 1;
    }
    v3->m_bInRecalcLayout = 0;
  }
  else
  {
    v3->m_bInRecalcLayout = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10356D31
// Name: protected: CControlBar::CControlBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CControlBar *__thiscall CControlBar::CControlBar(CControlBar *this)
{
  CWnd::CWnd(this);
  this->m_cxRightBorder = 6;
  this->m_cxLeftBorder = 6;
  this->m_nCount = 0;
  this->m_pData = nullptr;
  this->m_bAutoDelete = 0;
  this->m_hWndOwner = nullptr;
  this->m_hReBarTheme = nullptr;
  this->m_nStateFlags = 0;
  this->m_pDockSite = nullptr;
  this->m_pDockBar = nullptr;
  this->m_pDockContext = nullptr;
  this->m_dwStyle = 0;
  this->m_dwDockStyle = 0;
  this->m_pInPlaceOwner = nullptr;
  this->m_cxDefaultGap = 2;
  this->m_cyBottomBorder = 1;
  this->m_cyTopBorder = 1;
  this->m_nMRUWidth = 0x7FFF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10356DAF
// Name: public: void CControlBar::SetInPlaceOwner(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::SetInPlaceOwner(CMFCColorPickerCtrl *this, CMFCColorPickerCtrl::COLORTYPE colorType)
{
  this->m_COLORTYPE = colorType;
}

//------------------------------------------------------------------------------
// Address: 0x10356DBE
// Name: public: void CControlBar::SetBorders(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::SetBorders(CControlBar *this, int cxLeft, int cyTop, int cxRight, int cyBottom)
{
  this->m_cxLeftBorder = cxLeft;
  this->m_cyTopBorder = cyTop;
  this->m_cxRightBorder = cxRight;
  this->m_cyBottomBorder = cyBottom;
}

//------------------------------------------------------------------------------
// Address: 0x103AC6C2
// Name: protected: virtual void CMFCToolBar::OnDragLeave(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnDragLeave(CMFCToolBar *this)
{
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_bDisableCustomize == 0 )
  {
    this->m_iDragIndex = -1;
    rect = this->m_rectDrag;
    InflateRect(lprc: &rect, dx: 2, dy: 2);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
    SetRectEmpty(lprc: &this->m_rectDrag);
    this->m_iDragIndex = -1;
    CMFCToolBar::m_DropSource.m_bDeleteOnDrop = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC747
// Name: protected: virtual unsigned long CMFCToolBar::OnDragOver(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCToolBar::OnDragOver(
        CMFCToolBar *this,
        COleDataObject *pDataObject,
        char dwKeyState,
        CPoint point)
{
  CMFCToolBarButton *v5; // eax
  CMFCToolBarButton *v6; // esi
  int v7; // edi
  bool v8; // zf
  int m_iSelected; // ecx
  CMFCToolBar_vtbl *v10; // edx
  int v11; // edi
  int m_iHighlighted; // edi
  int v13; // eax
  unsigned int result; // eax
  int iIndex; // [esp+Ch] [ebp-1Ch]
  int bCopy; // [esp+10h] [ebp-18h]
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  if ( this->m_bLocked != 0 )
    return 0;
  if ( this->m_bDisableCustomize != 0 )
    return 0;
  v5 = CMFCToolBarButton::CreateFromOleData(pDataObject);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  v7 = v5->CanBeDropped(this: v5, a2: this);
  ((void (__thiscall *)(CMFCToolBarButton *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  if ( v7 == 0 )
    return 0;
  v8 = this->m_pDragButton == nullptr;
  bCopy = dwKeyState & 8;
  this->m_bIsDragCopy = bCopy;
  if ( v8 )
  {
    m_iSelected = this->m_iSelected;
    this->m_iSelected = -1;
    if ( m_iSelected != -1 )
    {
      CMFCToolBar::InvalidateButton(this, nIndex: m_iSelected);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
  v10 = this->__vftable;
  rect = this->m_rectDrag;
  v11 = ((int (__thiscall *)(CMFCToolBar *, int, int, CRect *))v10->FindDropIndex)(
          a1: this,
          a2: point.x,
          a3: point.y,
          a4: &this->m_rectDrag);
  iIndex = v11;
  if ( !EqualRect(lprc1: &rect, lprc2: &this->m_rectDrag) )
  {
    this->m_iDragIndex = v11;
    InflateRect(lprc: &rect, dx: 2, dy: 2);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
    rect = this->m_rectDrag;
    InflateRect(lprc: &rect, dx: 2, dy: 2);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectDrag, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  m_iHighlighted = this->m_iHighlighted;
  v13 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y);
  this->m_iHighlighted = v13;
  if ( m_iHighlighted != v13 )
    this->OnChangeHot(this, a2: v13);
  result = 0;
  if ( iIndex != -1 )
  {
    LOBYTE(result) = bCopy == 0;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AC8BD
// Name: protected: virtual int CMFCToolBar::OnDrop(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CMFCToolBar::OnDrop@<eax>(
        CMFCToolBar *this@<ecx>,
        int a2@<ebx>,
        COleDataObject *pDataObject,
        unsigned int dropEffect,
        CPoint point)
{
  int result; // eax
  CMFCToolBar_vtbl *v7; // eax
  CMFCToolBarButton *m_pDragButton; // edi
  int v9; // eax
  _DWORD *v10; // ebx
  int v11; // ebx
  int v12; // esi
  HWND Parent; // eax
  CWnd *v14; // eax
  HWND v15; // eax
  CWnd *v16; // eax
  HWND v17; // eax
  CWnd *v18; // eax
  CObject *v19; // eax
  HWND v20; // eax
  CWnd *v21; // eax
  CObject *v22; // eax
  int iDragIndex; // [esp+4h] [ebp-4h]
  CMFCToolBarButton *pButton; // [esp+10h] [ebp+8h]

  if ( this->m_bDisableCustomize != 0 )
    return 0;
  iDragIndex = this->m_iDragIndex;
  if ( iDragIndex < 0 )
    return 0;
  v7 = this->__vftable;
  m_pDragButton = this->m_pDragButton;
  this->m_pDragButton = nullptr;
  ((void (*)(void))v7->OnDragLeave)();
  v9 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y);
  if ( v9 >= 0 && m_pDragButton == CMFCToolBar::GetButton(this, nIndex: v9) )
    return 0;
  result = (int)this->CreateDroppedButton(this, a2: pDataObject);
  v10 = (_DWORD *)result;
  pButton = (CMFCToolBarButton *)result;
  if ( result != 0 )
  {
    if ( (*(int (__thiscall **)(int, CMFCToolBar *, int))(*(_DWORD *)result + 120))(a1: result, a2: this, a3: a2) == 0 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*v10 + 4))(a1: v10, a2: 1);
      return 1;
    }
    v10[7] = 0;
    if ( m_pDragButton != nullptr && dropEffect != 1 )
    {
      v11 = CMFCToolBar::ButtonToIndex(this, pButton: m_pDragButton);
      if ( iDragIndex == v11 || iDragIndex == v11 + 1 )
      {
        ((void (__thiscall *)(CMFCToolBar *, CMFCToolBarButton *, CPoint *))this->AddRemoveSeparator)(
          a1: this,
          a2: m_pDragButton,
          a3: &this->m_ptStartDrag);
        v10 = &pButton->__vftable;
        v12 = 1;
        goto LABEL_18;
      }
      this->RemoveButton(this, a2: v11);
      v10 = &pButton->__vftable;
    }
    if ( ((int (__thiscall *)(CMFCToolBar *, _DWORD *))this->InsertButton)(a1: this, a2: v10) != -1 )
    {
      this->AdjustLayout(this);
      Parent = GetParent(hWnd: this->m_hWnd);
      v14 = CWnd::FromHandle(hWnd: Parent);
      if ( CObject::IsKindOf(this: v14, pClass: &CMFCTabCtrl::classCMFCTabCtrl) != 0 )
      {
        v15 = GetParent(hWnd: this->m_hWnd);
        v16 = CWnd::FromHandle(hWnd: v15);
        v17 = GetParent(hWnd: v16->m_hWnd);
        v18 = CWnd::FromHandle(hWnd: v17);
        v19 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v18);
        if ( v19 != nullptr )
          ((void (__thiscall *)(CObject *))v19->__vftable[43].Serialize)(a1: v19);
      }
      if ( CMFCToolBar::m_bAltCustomizeMode != 0 )
        (*(void (__thiscall **)(_DWORD *))(*v10 + 128))(a1: v10);
      this->m_iSelected = -1;
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      v20 = GetParent(hWnd: this->m_hWnd);
      v21 = CWnd::FromHandle(hWnd: v20);
      v22 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v21);
      if ( v22 != nullptr )
        RedrawWindow(hWnd: (HWND)v22[8].__vftable, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      return 1;
    }
    v12 = 0;
LABEL_18:
    (*(void (__thiscall **)(_DWORD *, int))(*v10 + 4))(a1: v10, a2: 1);
    return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103ACAA0
// Name: public: static int CMFCToolBar::SetCustomizeMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBar::SetCustomizeMode(int bSet)
{
  CObList::CNode *m_pNodeHead; // edi
  BOOL v3; // ebx
  HWND__ **data; // esi
  CObList::CNode *v5; // esi
  CObject *v6; // edi
  CObList::CNode *v7; // edi
  int v8; // ebx
  CObList::CNode *v9; // eax
  HWND *v10; // esi
  CObject *v11; // eax
  CObject *v12; // eax
  int iOrigCount; // [esp+0h] [ebp-4h]

  if ( CMFCToolBar::m_bCustomizeMode == bSet )
    return 0;
LABEL_3:
  while ( 1 )
  {
    m_pNodeHead = afxAllToolBars.m_pNodeHead;
    v3 = false;
    iOrigCount = afxAllToolBars.m_nCount;
    if ( afxAllToolBars.m_pNodeHead == nullptr )
      break;
    while ( !v3 )
    {
      if ( m_pNodeHead == nullptr
        || (data = (HWND__ **)m_pNodeHead->data, m_pNodeHead = m_pNodeHead->pNext, data == nullptr) )
      {
LABEL_12:
        AfxThrowInvalidArgException();
      }
      if ( CWnd::FromHandlePermanent(hWnd: data[8]) != nullptr )
      {
        (*((void (__thiscall **)(HWND__ **, int))*data + 256))(a1: data, a2: bSet);
        v3 = afxAllToolBars.m_nCount != iOrigCount;
      }
      if ( m_pNodeHead == nullptr )
      {
        if ( v3 )
          goto LABEL_3;
        goto LABEL_11;
      }
    }
  }
LABEL_11:
  v5 = afxAllToolBars.m_pNodeHead;
  CMFCToolBar::m_bCustomizeMode = bSet;
  while ( v5 != nullptr )
  {
    v6 = v5->data;
    v5 = v5->pNext;
    if ( v6 == nullptr )
      goto LABEL_12;
    if ( CWnd::FromHandlePermanent(hWnd: (HWND__ *)v6[8].__vftable) != nullptr && v6[705].__vftable == nullptr )
      v6->__vftable[43].dtr_CObject(this: v6);
  }
  v7 = afxAllToolBars.m_pNodeHead;
  v8 = 0;
  while ( v7 != nullptr )
  {
    v9 = v7;
    v10 = (HWND *)v7->data;
    v7 = v7->pNext;
    if ( v10 == nullptr )
      goto LABEL_12;
    if ( (CWnd::GetStyle(this: (CWnd *)v9->data) & 0x10000000) != 0 )
    {
      v11 = (CObject *)(*((int (__thiscall **)(HWND *))*v10 + 102))(a1: v10);
      v12 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v11);
      if ( v12 != nullptr && v8 == 0 )
      {
        v8 = 1;
        ((void (__thiscall *)(CObject *, int))v12->__vftable[31].GetRuntimeClass)(a1: v12, a2: 1);
      }
      if ( CWnd::FromHandlePermanent(hWnd: v10[8]) != nullptr )
        RedrawWindow(hWnd: v10[8], lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
    }
  }
  if ( bSet == 0 )
    CMFCToolBar::m_pSelToolbar = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ACBDF
// Name: protected: virtual int CMFCToolBar::FindDropIndex(class CPoint,class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::FindDropIndex(CMFCToolBar *this, CPoint p, CRect *rectDrag)
{
  CMFCToolBar *v3; // esi
  BOOL v4; // ecx
  int m_nCount; // eax
  CObList::CNode *v6; // eax
  CObject *v7; // ecx
  int v8; // eax
  CObList::CNode *v9; // ecx
  int v10; // eax
  CObject *v11; // edx
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // ecx
  int v14; // eax
  int v15; // eax
  int left; // eax
  int right; // ecx
  int v18; // eax
  int top; // eax
  int bottom; // ecx
  int v21; // eax
  HWND m_hWnd; // [esp-8h] [ebp-54h]
  int bHorz; // [esp+Ch] [ebp-40h]
  int point_4; // [esp+14h] [ebp-38h]
  CRect rect; // [esp+18h] [ebp-34h]
  CRect recta; // [esp+18h] [ebp-34h]
  int rect_4; // [esp+1Ch] [ebp-30h]
  int rect_8; // [esp+20h] [ebp-2Ch]
  int rect_12; // [esp+24h] [ebp-28h]
  int iCursorRow; // [esp+28h] [ebp-24h]
  int iCursorRowa; // [esp+28h] [ebp-24h]
  int iButton; // [esp+30h] [ebp-1Ch]
  int iButtona; // [esp+30h] [ebp-1Ch]
  int iButtonb; // [esp+30h] [ebp-1Ch]
  int iDragButton; // [esp+34h] [ebp-18h]
  CRect rectClient; // [esp+38h] [ebp-14h] BYREF

  iDragButton = -1;
  v3 = this;
  SetRectEmpty(lprc: rectDrag);
  v4 = (v3->GetCurrentAlignment(this: v3) & 0xA000) != 0;
  bHorz = v4;
  point_4 = p.y;
  if ( p.y < 0 )
    point_4 = 0;
  m_nCount = v3->m_Buttons.m_nCount;
  if ( m_nCount == 0 || m_nCount == 1 && v3->m_pCustomizeBtn != nullptr )
  {
    GetClientRect(hWnd: v3->m_hWnd, lpRect: rectDrag);
    iDragButton = 0;
LABEL_54:
    if ( iDragButton >= 0 )
    {
      m_hWnd = v3->m_hWnd;
      memset(&rectClient, 0, sizeof(rectClient));
      GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
      if ( v3->m_pCustomizeBtn != nullptr )
      {
        v14 = v3->m_Buttons.m_nCount;
        if ( iDragButton == v14 )
        {
          v15 = v14 - 1;
          iDragButton = 0;
          if ( v15 >= 0 )
            iDragButton = v15;
        }
      }
      if ( bHorz != 0 )
      {
        left = rectDrag->left - 3;
        if ( rectClient.left > left )
          left = rectClient.left;
        right = rectClient.right;
        rectDrag->left = left;
        v18 = left + 6;
        rectDrag->right = v18;
        if ( v18 > right )
        {
          rectDrag->right = right;
          rectDrag->left = right - 6;
        }
      }
      else
      {
        top = rectDrag->top - 3;
        if ( rectClient.top > top )
          top = rectClient.top;
        bottom = rectClient.bottom;
        rectDrag->top = top;
        v21 = top + 6;
        rectDrag->bottom = v21;
        if ( v21 > bottom )
        {
          rectDrag->bottom = bottom;
          rectDrag->top = bottom - 6;
        }
      }
    }
    goto LABEL_68;
  }
  if ( !v4 )
  {
    m_pNodeHead = v3->m_Buttons.m_pNodeHead;
    iButtonb = 0;
    if ( m_pNodeHead == nullptr )
      goto LABEL_68;
    while ( 1 )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data == nullptr )
LABEL_17:
        AfxThrowInvalidArgException();
      recta = *(CRect *)&data[21].__vftable;
      if ( point_4 < recta.top )
      {
        *rectDrag = recta;
        iDragButton = iButtonb;
        rectDrag->bottom = rectDrag->top;
        goto LABEL_49;
      }
      if ( point_4 <= recta.bottom )
        break;
      ++iButtonb;
      if ( m_pNodeHead == nullptr )
      {
        v3 = this;
        goto LABEL_68;
      }
    }
    *rectDrag = recta;
    v3 = this;
    if ( point_4 - recta.top <= recta.bottom - point_4 )
    {
      iDragButton = iButtonb;
      rectDrag->bottom = rectDrag->top;
    }
    else
    {
      iDragButton = iButtonb + 1;
      rectDrag->top = rectDrag->bottom;
    }
    goto LABEL_54;
  }
  iCursorRow = v3->GetRowHeight(this: v3);
  iButton = 0;
  memset(&rectClient, 0, sizeof(rectClient));
  SetRectEmpty(lprc: &rectClient);
  v6 = v3->m_Buttons.m_pNodeHead;
  while ( v6 != nullptr )
  {
    v7 = v6->data;
    v6 = v6->pNext;
    if ( v7 == nullptr )
      goto LABEL_17;
    if ( v7[16].__vftable == nullptr && v7[20].__vftable != nullptr )
    {
      rect_4 = (int)v7[22].__vftable;
      rect_8 = (int)v7[23].__vftable;
      rect_12 = (int)v7[24].__vftable;
      if ( iButton > 0 && rect_4 > rectClient.bottom )
      {
        v3 = this;
        iCursorRow = rect_4 - rectClient.bottom;
        break;
      }
      rectClient.left = (int)v7[21].__vftable;
      rectClient.top = rect_4;
      rectClient.right = rect_8;
      rectClient.bottom = rect_12;
      v3 = this;
    }
    ++iButton;
  }
  v8 = v3->GetRowHeight(this: v3);
  iButtona = 0;
  v9 = v3->m_Buttons.m_pNodeHead;
  iCursorRowa = point_4 / (iCursorRow + v8);
  v10 = 0;
  while ( v9 != nullptr )
  {
    v11 = v9->data;
    v9 = v9->pNext;
    if ( v11 == nullptr )
      goto LABEL_17;
    if ( v11[16].__vftable == nullptr && v11[20].__vftable != nullptr )
    {
      rect = *(CRect *)&v11[21].__vftable;
      if ( v10 > 0 && rect.top >= rectClient.bottom )
        ++iButtona;
      if ( iButtona > iCursorRowa )
      {
        *rectDrag = rectClient;
        rectDrag->left = rectDrag->right;
        iDragButton = v10 - 1;
        goto LABEL_37;
      }
      if ( iButtona == iCursorRowa )
      {
        if ( p.x < rect.left )
        {
          *rectDrag = rect;
          goto LABEL_36;
        }
        if ( p.x <= rect.right )
        {
          *rectDrag = rect;
          if ( p.x - rect.left > rect.right - p.x )
          {
            iDragButton = v10 + 1;
            rectDrag->left = rectDrag->right;
LABEL_37:
            v3 = this;
            if ( iDragButton != -1 )
              goto LABEL_54;
            break;
          }
LABEL_36:
          rectDrag->right = rectDrag->left;
          iDragButton = v10;
          goto LABEL_37;
        }
      }
      rectClient.left = (int)v11[21].__vftable;
      rectClient.top = rect.top;
      rectClient.right = rect.right;
      rectClient.bottom = rect.bottom;
      v3 = this;
    }
    ++v10;
  }
  if ( iButtona == iCursorRowa )
  {
    *rectDrag = rectClient;
    rectDrag->left = rectDrag->right;
    iDragButton = v10;
LABEL_49:
    v3 = this;
    goto LABEL_54;
  }
LABEL_68:
  if ( v3->m_pCustomizeBtn != nullptr && iDragButton == v3->m_Buttons.m_nCount )
  {
    iDragButton = -1;
    SetRectEmpty(lprc: rectDrag);
  }
  return iDragButton;
}

//------------------------------------------------------------------------------
// Address: 0x103ACF50
// Name: protected: void CMFCToolBar::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnContextMenu(CMFCToolBar *this, CWnd *pWnd, tagPOINT point)
{
  HMENU__ *v4; // eax
  int m_iSelected; // ecx
  CMFCToolBar *v6; // ecx
  int v7; // edx
  CMFCToolBarButton *Button; // eax
  HMENU SubMenu; // eax
  CMenu *v10; // ebx
  int v11; // eax
  CMFCToolBarButton *v12; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-4Ch]
  HMENU__ *m_hMenu; // [esp-4h] [ebp-48h]
  tagPOINT Point; // [esp+10h] [ebp-34h] BYREF
  CMFCToolBarButton *v16; // [esp+18h] [ebp-2Ch]
  CMenu v17; // [esp+1Ch] [ebp-28h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-20h] BYREF
  int v19; // [esp+40h] [ebp-4h]

  if ( this->m_bLocked != 0 && CMFCToolBar::m_bCustomizeMode != 0 )
  {
    MessageBeep(uType: 0xFFFFFFFF);
  }
  else if ( this->IsDragMode(this) == 0 && this->m_bStretchButton == 0 )
  {
    this->OnChangeHot(this, a2: -1);
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
    {
      CWnd::SetFocus(this);
      Point = point;
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point);
      v4 = (HMENU__ *)((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: Point.x, a3: Point.y);
      m_iSelected = this->m_iSelected;
      v17.m_hMenu = v4;
      this->m_iSelected = (int)v4;
      if ( m_iSelected != -1 )
        CMFCToolBar::InvalidateButton(this, nIndex: m_iSelected);
      if ( this->m_iSelected != -1 )
        CMFCToolBar::InvalidateButton(this, nIndex: this->m_iSelected);
      v6 = CMFCToolBar::m_pSelToolbar;
      if ( CMFCToolBar::m_pSelToolbar != this )
      {
        CMFCToolBar::m_pSelToolbar = this;
        if ( v6 != nullptr )
        {
          v7 = v6->m_iSelected;
          v6->m_iSelected = -1;
          CMFCToolBar::InvalidateButton(this: v6, nIndex: v7);
        }
      }
      UpdateWindow(hWnd: this->m_hWnd);
      if ( (int)v17.m_hMenu >= 0 )
      {
        Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
        v16 = Button;
        if ( Button != nullptr )
        {
          if ( Button->IsEditable(this: Button) != 0 )
          {
            if ( v16->CanBeStored(this: v16) != 0 )
            {
              if ( point == -1 )
              {
                m_hWnd = this->m_hWnd;
                memset(&Rect, 0, sizeof(Rect));
                GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
                CWnd::ClientToScreen(this, lpRect: &Rect);
                point.x = Rect.left + 5;
                point.y = Rect.top + 5;
              }
              v17.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
              v17.m_hMenu = nullptr;
              v19 = 0;
              CMenu::LoadMenuA(this: &v17, nIDResource: 0x3EE6u);
              SubMenu = GetSubMenu(hMenu: v17.m_hMenu, nPos: 0);
              v10 = CMenu::FromHandle(hMenu: SubMenu);
              if ( v10 == nullptr )
                AfxThrowInvalidArgException();
              if ( v16->m_bLocked != 0 )
                EnableMenuItem(hMenu: v10->m_hMenu, uIDEnableItem: 0x420Eu, uEnable: 1u);
              if ( this->EnableContextMenuItems(this, a2: v16, a3: v10) != 0 )
              {
                v11 = this->m_iSelected - 1;
                if ( v11 >= 0 )
                {
                  v12 = CMFCToolBar::GetButton(this, nIndex: v11);
                  if ( v12 != nullptr && v12->m_bVisible == 0 )
                    EnableMenuItem(hMenu: v10->m_hMenu, uIDEnableItem: 0x4215u, uEnable: 1u);
                }
                CMenu::TrackPopupMenu(this: v10, nFlags: 2u, x: point.x, y: point.y, pWnd: this, lpRect: nullptr);
              }
              v19 = -1;
              v17.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
              CMenu::DestroyMenu(this: &v17);
            }
          }
          else
          {
            m_hMenu = v17.m_hMenu;
            this->m_iSelected = -1;
            CMFCToolBar::InvalidateButton(this, nIndex: (int)m_hMenu);
            UpdateWindow(hWnd: this->m_hWnd);
          }
        }
      }
    }
    else
    {
      CPane::OnContextMenu(this, __formal: pWnd, (CPoint)point);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD1AB
// Name: protected: struct HBRUSH__ __near * CMFCToolBar::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CMFCToolBar::OnCtlColor(CMFCToolBar *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  HBRUSH__ *result; // eax
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v8; // eax
  CObject *data; // edi
  HWND__ *m_hWnd; // eax
  HBRUSH__ *hbr; // [esp+18h] [ebp+Ch]

  result = CWnd::OnCtlColor(this, __formal: pDC, pWnd, __formal: nCtlColor);
  hbr = result;
  if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bLocked == 0 )
  {
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      v8 = m_pNodeHead;
      m_pNodeHead = m_pNodeHead->pNext;
      data = v8->data;
      if ( pWnd != nullptr )
        m_hWnd = pWnd->m_hWnd;
      else
        m_hWnd = nullptr;
      if ( ((int (__thiscall *)(CObject *, HWND__ *))data->__vftable[13].dtr_CObject)(a1: data, a2: m_hWnd) != 0 )
      {
        result = (HBRUSH__ *)((int (__thiscall *)(CObject *, CDC *, unsigned int))data->__vftable[6].GetRuntimeClass)(
                               a1: data,
                               a2: pDC,
                               a3: nCtlColor);
        if ( result != nullptr )
          return result;
        return hbr;
      }
    }
    return hbr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F1B
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::HitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::HitTest(CMFCRibbonBaseElement *this, CPoint __formal)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F20
// Name: public: class CMFCRibbonBar __near * CMFCRibbonBaseElement::GetTopLevelRibbonBar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBar *__thiscall CMFCRibbonBaseElement::GetTopLevelRibbonBar(CMFCRibbonBaseElement *this)
{
  CMFCRibbonBar *result; // eax
  CMFCRibbonCategory *m_pParent; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenu; // ecx

  result = this->m_pRibbonBar;
  if ( result == nullptr )
  {
    m_pParent = this->m_pParent;
    if ( m_pParent == nullptr || (result = m_pParent->m_pParentRibbonBar) == nullptr )
    {
      m_pParentMenu = this->m_pParentMenu;
      if ( m_pParentMenu != nullptr )
        return CMFCRibbonPanelMenuBar::GetTopLevelRibbonBar(this: m_pParentMenu);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F47
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::Find(class CMFCRibbonBaseElement const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::Find(
        CMFCRibbonBaseElement *this,
        const CMFCRibbonBaseElement *pElement)
{
  return this == pElement ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F5D
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::FindByID(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::FindByID(CMFCRibbonBaseElement *this, unsigned int uiCmdID)
{
  return uiCmdID == this->m_nID ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F74
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::FindByData(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::FindByData(CMFCRibbonBaseElement *this, unsigned int dwData)
{
  return dwData == this->m_dwData ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8F8B
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::FindByOriginal(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::FindByOriginal(
        CMFCRibbonBaseElement *this,
        CMFCRibbonBaseElement *pOriginal)
{
  return pOriginal == this->m_pOriginal ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FA2
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::GetPressed(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::GetPressed(CMFCRibbonBaseElement *this)
{
  return this->IsPressed(this) != 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FB4
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::GetDroppedDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::GetDroppedDown(CMFCRibbonBaseElement *this)
{
  return this->IsDroppedDown(this) != 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FC6
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::GetHighlighted(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::GetHighlighted(CMFCRibbonBaseElement *this)
{
  return this->IsHighlighted(this) != 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FD8
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::GetFocused(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::GetFocused(CMFCRibbonBaseElement *this)
{
  return this->IsFocused(this) != 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FEA
// Name: public: virtual void CMFCRibbonBaseElement::SetParentCategory(class CMFCRibbonCategory __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetParentCategory(CMFCRibbonBaseElement *this, CMFCRibbonCategory *pParent)
{
  this->m_pParent = pParent;
}

//------------------------------------------------------------------------------
// Address: 0x103C8FF9
// Name: public: virtual void CMFCRibbonBaseElement::SetParentMenu(class CMFCRibbonPanelMenuBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetParentMenu(CMFCRibbonBaseElement *this, CMFCRibbonPanelMenuBar *pMenuBar)
{
  this->m_pParentMenu = pMenuBar;
}

//------------------------------------------------------------------------------
// Address: 0x103C9008
// Name: public: virtual void CMFCRibbonBaseElement::SetOriginal(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetOriginal(CMFCRibbonBaseElement *this, CMFCRibbonBaseElement *pOriginal)
{
  CMFCRibbonBaseElement *v2; // eax

  v2 = pOriginal;
  if ( pOriginal != nullptr )
  {
    while ( v2->m_pOriginal != nullptr )
      v2 = v2->m_pOriginal;
  }
  this->m_pOriginal = v2;
}

//------------------------------------------------------------------------------
// Address: 0x103D33FD
// Name: protected: virtual int CMFCRibbonPanel::NotifyControlCommand(int,int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanel::NotifyControlCommand(
        CMFCRibbonPanel *this,
        int bAccelerator,
        int nNotifyCode,
        unsigned int wParam,
        int lParam)
{
  int v6; // edi
  CMFCRibbonBaseElement *v7; // ecx

  v6 = 0;
  if ( this->m_arElements.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v6 < 0 || v6 >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v7 = this->m_arElements.m_pData[v6];
    if ( v7->NotifyControlCommand(this: v7, a2: bAccelerator, a3: nNotifyCode, a4: wParam, a5: lParam) != 0 )
      break;
    if ( ++v6 >= this->m_arElements.m_nSize )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D3459
// Name: protected: virtual void CMFCRibbonPanel::OnAfterChangeRect(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::OnAfterChangeRect(CMFCRibbonPanel *this, CDC *pDC)
{
  int v2; // eax
  BOOL v4; // eax
  CMFCRibbonBaseElement *v5; // eax
  BOOL v6; // eax
  CMFCRibbonBaseElement *pElem; // [esp+Ch] [ebp-20h]
  int i; // [esp+14h] [ebp-18h]
  RECT rc; // [esp+18h] [ebp-14h] BYREF

  v2 = 0;
  i = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( 1 )
    {
      if ( v2 < 0 || v2 >= this->m_arElements.m_nSize )
        AfxThrowInvalidArgException();
      v5 = this->m_arElements.m_pData[v2];
      rc = (RECT)v5->m_rect;
      pElem = v5;
      v6 = IsRectEmpty(lprc: &rc);
      pElem->OnShow(this: pElem, a2: !v6);
      pElem->OnAfterChangeRect(this: pElem, a2: pDC);
      if ( ++i >= this->m_arElements.m_nSize )
        break;
      v2 = i;
    }
  }
  rc = (RECT)this->m_btnDefault.m_rect;
  v4 = IsRectEmpty(lprc: &rc);
  this->m_btnDefault.OnShow(this: &this->m_btnDefault, a2: !v4);
  this->m_btnDefault.OnAfterChangeRect(this: &this->m_btnDefault, a2: pDC);
}

//------------------------------------------------------------------------------
// Address: 0x103D3544
// Name: protected: virtual void CMFCRibbonPanel::OnShow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::OnShow(CMFCRibbonPanel *this, int bShow)
{
  int v2; // eax
  CMFCRibbonBaseElement *v4; // ecx
  BOOL v5; // eax
  BOOL v6; // eax
  CMFCRibbonBaseElement *pElem; // [esp+4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-18h]
  RECT rc; // [esp+Ch] [ebp-14h] BYREF

  v2 = 0;
  for ( i = 0; v2 < this->m_arElements.m_nSize; i = v2 )
  {
    if ( v2 < 0 || v2 >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[v2];
    pElem = v4;
    v6 = false;
    if ( bShow != 0 )
    {
      rc = (RECT)v4->m_rect;
      v5 = IsRectEmpty(lprc: &rc);
      v4 = pElem;
      if ( !v5 )
        v6 = true;
    }
    v4->OnShow(this: v4, a2: v6);
    v2 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D35D5
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::FindByID(unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonPanel::FindByID(CMFCRibbonPanel *this, unsigned int uiCmdID)
{
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx
  CMFCRibbonDefaultPanelButton *result; // eax

  v3 = 0;
  if ( this->m_arElements.m_nSize <= 0 )
  {
LABEL_6:
    if ( this->m_btnDefault.m_nID == uiCmdID )
      return &this->m_btnDefault;
    else
      return nullptr;
  }
  else
  {
    while ( 1 )
    {
      if ( v3 < 0 || v3 >= this->m_arElements.m_nSize )
        AfxThrowInvalidArgException();
      v4 = this->m_arElements.m_pData[v3];
      result = (CMFCRibbonDefaultPanelButton *)v4->FindByID(this: v4, a2: uiCmdID);
      if ( result != nullptr )
        break;
      if ( ++v3 >= this->m_arElements.m_nSize )
        goto LABEL_6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D3635
// Name: public: int CMFCRibbonPanel::HasElement(class CMFCRibbonBaseElement const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanel::HasElement(CMFCRibbonPanel *this, const CMFCRibbonBaseElement *pElem)
{
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx

  v3 = 0;
  if ( this->m_arElements.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[v3];
    if ( v4->Find(this: v4, a2: pElem) != nullptr )
      break;
    if ( ++v3 >= this->m_arElements.m_nSize )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D3688
// Name: public: void CMFCRibbonPanel::GetElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::GetElements(
        CMFCRibbonPanel *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[i];
    v4->GetElements(this: v4, a2: arElements);
  }
  if ( this->IsMainPanel(this) == 0 )
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
      nIndex: arElements->m_nSize,
      newElement: (CMFCRibbonKeyTip *)&this->m_btnDefault);
}

//------------------------------------------------------------------------------
// Address: 0x103D36EF
// Name: public: void CMFCRibbonPanel::GetElementsByID(unsigned int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::GetElementsByID(
        CMFCRibbonPanel *this,
        unsigned int uiCmdID,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int i; // edi
  CMFCRibbonBaseElement *v5; // ecx

  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v5 = this->m_arElements.m_pData[i];
    v5->GetElementsByID(this: v5, a2: uiCmdID, a3: arElements);
  }
  this->m_btnDefault.GetElementsByID(this: &this->m_btnDefault, a2: uiCmdID, a3: arElements);
}

//------------------------------------------------------------------------------
// Address: 0x103D3745
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetPressed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanel::GetPressed(CMFCRibbonPanel *this)
{
  int v2; // edi
  CMFCRibbonBaseElement *v3; // ecx
  CMFCRibbonBaseElement *result; // eax

  v2 = 0;
  if ( this->m_arElements.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arElements.m_pData[v2];
    result = v3->GetPressed(this: v3);
    if ( result != nullptr )
      break;
    if ( ++v2 >= this->m_arElements.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D378A
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetDroppedDown(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanel::GetDroppedDown(CMFCRibbonPanel *this)
{
  CMFCRibbonBaseElement *result; // eax
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx

  if ( IsRectEmpty(lprc: &this->m_btnDefault.m_rect)
    || (result = this->m_btnDefault.GetDroppedDown(this: &this->m_btnDefault)) == nullptr )
  {
    v3 = 0;
    if ( this->m_arElements.m_nSize <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        if ( v3 < 0 || v3 >= this->m_arElements.m_nSize )
          AfxThrowInvalidArgException();
        v4 = this->m_arElements.m_pData[v3];
        result = v4->GetDroppedDown(this: v4);
        if ( result != nullptr )
          break;
        if ( ++v3 >= this->m_arElements.m_nSize )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D37F2
// Name: protected: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetFirstTabStop(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanel::GetFirstTabStop(CMFCRibbonPanel *this)
{
  int v2; // ebx
  CMFCRibbonBaseElement *v3; // edi
  CMFCRibbonBaseElement *result; // eax
  int v5; // edi
  CMFCRibbonBaseElement *v6; // ebx
  int v7; // edi
  CMFCRibbonBaseElement *v8; // ecx
  int bIsLabel; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_pPaletteButton != nullptr )
  {
    if ( this->m_arElements.m_nSize > 0 )
    {
      while ( v2 >= 0 && v2 < this->m_arElements.m_nSize )
      {
        v3 = this->m_arElements.m_pData[v2];
        bIsLabel = CObject::IsKindOf(this: v3, pClass: &CMFCRibbonLabel::classCMFCRibbonLabel);
        if ( CObject::IsKindOf(this: v3, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) == 0
          && bIsLabel == 0
          && v3->m_bIsOnPaletteTop != 0 )
        {
          result = v3->GetFirstTabStop(this: v3);
          if ( result != nullptr )
            return result;
        }
        if ( ++v2 >= this->m_arElements.m_nSize )
          goto LABEL_10;
      }
LABEL_23:
      AfxThrowInvalidArgException();
    }
LABEL_10:
    v5 = 0;
    if ( this->m_arElements.m_nSize > 0 )
    {
      while ( v5 >= 0 && v5 < this->m_arElements.m_nSize )
      {
        v6 = this->m_arElements.m_pData[v5];
        if ( CObject::IsKindOf(this: v6, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) != 0 )
        {
          result = v6->GetFirstTabStop(this: v6);
          if ( result != nullptr )
            return result;
        }
        if ( ++v5 >= this->m_arElements.m_nSize )
          goto LABEL_16;
      }
      goto LABEL_23;
    }
  }
LABEL_16:
  v7 = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( v7 >= 0 && v7 < this->m_arElements.m_nSize )
    {
      v8 = this->m_arElements.m_pData[v7];
      result = v8->GetFirstTabStop(this: v8);
      if ( result != nullptr )
        return result;
      if ( ++v7 >= this->m_arElements.m_nSize )
        return nullptr;
    }
    goto LABEL_23;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D38FE
// Name: protected: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetLastTabStop(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanel::GetLastTabStop(CMFCRibbonPanel *this)
{
  int m_nSize; // edi
  CMFCRibbonBaseElement *v3; // ebx
  CMFCRibbonBaseElement *result; // eax
  int v5; // edi
  CMFCRibbonBaseElement *v6; // ebx
  int v7; // edi
  CMFCRibbonBaseElement *v8; // ecx
  int bIsLabel; // [esp+Ch] [ebp-4h]

  if ( this->m_pPaletteButton != nullptr )
  {
    m_nSize = this->m_arElements.m_nSize;
    while ( --m_nSize >= 0 )
    {
      if ( m_nSize >= this->m_arElements.m_nSize )
LABEL_10:
        AfxThrowInvalidArgException();
      v3 = this->m_arElements.m_pData[m_nSize];
      bIsLabel = CObject::IsKindOf(this: v3, pClass: &CMFCRibbonLabel::classCMFCRibbonLabel);
      if ( CObject::IsKindOf(this: v3, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) == 0
        && bIsLabel == 0
        && v3->m_bIsOnPaletteTop == 0 )
      {
        result = v3->GetFirstTabStop(this: v3);
        if ( result != nullptr )
          return result;
      }
    }
    v5 = this->m_arElements.m_nSize;
    while ( --v5 >= 0 )
    {
      if ( v5 >= this->m_arElements.m_nSize )
        goto LABEL_10;
      v6 = this->m_arElements.m_pData[v5];
      if ( CObject::IsKindOf(this: v6, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) != 0 )
      {
        result = v6->GetFirstTabStop(this: v6);
        if ( result != nullptr )
          return result;
      }
    }
  }
  v7 = this->m_arElements.m_nSize;
  while ( --v7 >= 0 )
  {
    if ( v7 >= this->m_arElements.m_nSize )
      goto LABEL_10;
    v8 = this->m_arElements.m_pData[v7];
    result = v8->GetLastTabStop(this: v8);
    if ( result != nullptr )
      return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D39E6
// Name: protected: void CMFCRibbonPanel::CleanUpSizes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::CleanUpSizes(CMFCRibbonPanel *this)
{
  int i; // edi
  CMFCRibbonBaseElement *v3; // ecx

  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arWidths,
    nNewSize: 0,
    nGrowBy: -1);
  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arElements.m_pData[i];
    v3->CleanUpSizes(this: v3);
  }
  this->m_btnDefault.CleanUpSizes(this: &this->m_btnDefault);
}

//------------------------------------------------------------------------------
// Address: 0x103D3A41
// Name: protected: void CMFCRibbonPanel::ScrollPalette(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::ScrollPalette(CMFCRibbonPanel *this, int nScrollOffset, int bIsDelta)
{
  int v3; // ebx
  int v5; // eax
  int v6; // eax
  CMFCRibbonBaseElement *v7; // edi
  int IsKindOf; // eax
  int nDelta; // [esp+8h] [ebp-4h]
  int bIsLabel; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( bIsDelta != 0 )
    v5 = nScrollOffset;
  else
    v5 = this->m_nScrollOffset - nScrollOffset;
  nDelta = v5;
  if ( v5 != 0 )
  {
    v6 = bIsDelta != 0 ? this->m_nScrollOffset - v5 : nScrollOffset;
    this->m_nScrollOffset = v6;
    if ( this->m_arElements.m_nSize > 0 )
    {
      do
      {
        if ( v3 < 0 || v3 >= this->m_arElements.m_nSize )
          AfxThrowInvalidArgException();
        v7 = this->m_arElements.m_pData[v3];
        bIsLabel = CObject::IsKindOf(this: v7, pClass: &CMFCRibbonLabel::classCMFCRibbonLabel);
        IsKindOf = CObject::IsKindOf(this: v7, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon);
        if ( bIsLabel != 0 || IsKindOf != 0 )
          OffsetRect(lprc: &v7->m_rect, dx: 0, dy: nDelta);
        ++v3;
      }
      while ( v3 < this->m_arElements.m_nSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D3ADF
// Name: protected: class CSize CMFCRibbonPanel::GetPaltteMinSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonPanel::GetPaltteMinSize(CMFCRibbonPanel *this, CSize *result)
{
  CMFCRibbonGallery *m_pPaletteButton; // ecx
  int v4; // ebx
  int IsKindOf; // eax
  CMFCRibbonGallery *v7; // ecx
  CMFCRibbonBar *TopLevelRibbonBar; // edi
  CFont *Font; // eax
  int SystemMetrics; // eax
  CMFCRibbonGallery *v11; // ecx
  int *v12; // eax
  CMFCRibbonGallery *v13; // ecx
  int v14; // eax
  bool v15; // cc
  CMFCRibbonBaseElement *v16; // edi
  int v17; // eax
  int v18; // eax
  CMFCVisualManager *Instance; // eax
  int v20; // edi
  CSize *MenuImageSize; // eax
  int v22; // eax
  int v23; // eax
  CClientDC dc; // [esp+10h] [ebp-54h] BYREF
  CSize v25; // [esp+24h] [ebp-40h] BYREF
  CSize sizeElem; // [esp+2Ch] [ebp-38h] BYREF
  int cyIcon; // [esp+34h] [ebp-30h]
  int cxScroll; // [esp+38h] [ebp-2Ch]
  CFont *pOldFont; // [esp+3Ch] [ebp-28h]
  int bNoSideBar; // [esp+40h] [ebp-24h]
  int cxIcon; // [esp+44h] [ebp-20h]
  int cyLabel; // [esp+48h] [ebp-1Ch]
  int cyBottom; // [esp+4Ch] [ebp-18h]
  int cxLabel; // [esp+50h] [ebp-14h]
  int cxBottom; // [esp+54h] [ebp-10h]
  int v36; // [esp+60h] [ebp-4h]

  m_pPaletteButton = this->m_pPaletteButton;
  v4 = 0;
  if ( m_pPaletteButton == nullptr )
  {
    result->cx = -1;
    result->cy = -1;
    return result;
  }
  IsKindOf = CObject::IsKindOf(this: m_pPaletteButton, pClass: &CMFCRibbonUndoButton::classCMFCRibbonUndoButton);
  v7 = this->m_pPaletteButton;
  bNoSideBar = IsKindOf;
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this: v7);
  CClientDC::CClientDC(this: &dc, pWnd: TopLevelRibbonBar);
  v36 = 0;
  Font = CWnd::GetFont(this: TopLevelRibbonBar);
  pOldFont = CDC::SelectObject(this: &dc, pFont: Font);
  if ( pOldFont == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  SystemMetrics = GetSystemMetrics(nIndex: 2);
  v11 = this->m_pPaletteButton;
  cxScroll = SystemMetrics;
  v12 = (int *)v11->GetIconSize(this: v11, result: &sizeElem);
  v13 = this->m_pPaletteButton;
  cxIcon = *v12;
  v14 = (int)v13->GetIconSize(this: v13, result: &sizeElem);
  v15 = this->m_arElements.m_nSize <= 0;
  cyIcon = *(_DWORD *)(v14 + 4);
  cxLabel = 0;
  cyLabel = 0;
  cxBottom = 0;
  cyBottom = 0;
  if ( !v15 )
  {
    while ( v4 >= 0 && v4 < this->m_arElements.m_nSize )
    {
      v16 = this->m_arElements.m_pData[v4];
      v16->SetInitialMode(this: v16, a2: 0);
      v16->OnCalcTextSize(this: v16, a2: &dc);
      v16->GetSize(this: v16, result: &sizeElem, a3: &dc);
      if ( CObject::IsKindOf(this: v16, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) == 0 )
      {
        if ( CObject::IsKindOf(this: v16, pClass: &CMFCRibbonLabel::classCMFCRibbonLabel) != 0 )
        {
          if ( cxLabel <= sizeElem.cx )
            cxLabel = sizeElem.cx;
          v17 = this->m_pPaletteButton->GetGroupOffset(this: this->m_pPaletteButton);
          if ( cyLabel <= sizeElem.cy + v17 )
          {
            v18 = this->m_pPaletteButton->GetGroupOffset(this: this->m_pPaletteButton);
            cyLabel = sizeElem.cy + v18;
          }
        }
        else
        {
          if ( bNoSideBar == 0 )
          {
            Instance = CMFCVisualManager::GetInstance();
            v20 = 2 * Instance->GetMenuImageMargin(this: Instance) + 12;
            MenuImageSize = CMFCToolBar::GetMenuImageSize(result: &v25);
            sizeElem.cx += v20 + MenuImageSize->cx;
          }
          if ( cxBottom <= sizeElem.cx )
            cxBottom = sizeElem.cx;
          cyBottom += sizeElem.cy;
        }
      }
      if ( ++v4 >= this->m_arElements.m_nSize )
        goto LABEL_20;
    }
    goto LABEL_4;
  }
LABEL_20:
  CDC::SelectObject(this: &dc, pFont: pOldFont);
  v22 = cxLabel;
  if ( cxIcon > cxLabel )
    v22 = cxIcon;
  v23 = cxScroll + v22;
  if ( v23 <= cxBottom )
    v23 = cxBottom;
  v36 = -1;
  result->cx = v23;
  result->cy = cyIcon + cyLabel + cyBottom;
  CClientDC::~CClientDC(this: &dc);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D3CCB
// Name: protected: virtual void CMFCRibbonPanel::OnRTLChanged(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::OnRTLChanged(CMFCRibbonPanel *this, int bIsRTL)
{
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[i];
    v4->OnRTLChanged(this: v4, a2: bIsRTL);
  }
  this->m_btnDefault.OnRTLChanged(this: &this->m_btnDefault, a2: bIsRTL);
}

//------------------------------------------------------------------------------
// Address: 0x103D3D1E
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetFocused(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonPanel::GetFocused(CMFCRibbonPanel *this)
{
  CMFCRibbonDefaultPanelButton *result; // eax
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx

  if ( !IsRectEmpty(lprc: &this->m_btnDefault.m_rect) && this->m_btnDefault.IsFocused(this: &this->m_btnDefault) != 0 )
    return &this->m_btnDefault;
  v3 = 0;
  if ( this->m_arElements.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[v3];
    result = (CMFCRibbonDefaultPanelButton *)v4->GetFocused(this: v4);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_arElements.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D3D8F
// Name: public: void CMFCRibbonPanel::GetVisibleElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::GetVisibleElements(
        CMFCRibbonPanel *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  for ( i = 0; i < this->m_arElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arElements.m_pData[i];
    v4->GetVisibleElements(this: v4, a2: arElements);
  }
  this->m_btnDefault.GetVisibleElements(this: &this->m_btnDefault, a2: arElements);
}

//------------------------------------------------------------------------------
// Address: 0x103D3DE2
// Name: public: void CMFCRibbonPanel::SetFocused(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::SetFocused(CMFCRibbonPanel *this, CMFCRibbonDefaultPanelButton *pNewFocus)
{
  CMFCRibbonDefaultPanelButton *Focused; // eax
  CMFCRibbonBaseElement *v4; // esi
  CMFCRibbonDefaultPanelButton_vtbl *v5; // eax
  CMFCRibbonBaseElement_vtbl *v6; // edx
  CMFCRibbonBaseElement_vtbl *v7; // eax

  Focused = CMFCRibbonPanel::GetFocused(this);
  v4 = Focused;
  if ( pNewFocus != Focused )
  {
    if ( Focused != nullptr )
    {
      v5 = Focused->__vftable;
      v4->m_bIsFocused = 0;
      v5->OnSetFocus(this: v4, a2: 0);
      if ( v4->m_bIsHighlighted != 0 )
      {
        v6 = v4->__vftable;
        v4->m_bIsHighlighted = 0;
        v6->OnHighlight(this: v4, a2: 0);
        if ( this->m_pHighlighted == v4 )
          this->m_pHighlighted = nullptr;
      }
      v4->Redraw(this: v4);
    }
    if ( pNewFocus != nullptr )
    {
      v7 = (CMFCRibbonBaseElement_vtbl *)pNewFocus->__vftable;
      pNewFocus->m_bIsHighlighted = 1;
      pNewFocus->m_bIsFocused = 1;
      v7->OnSetFocus(this: pNewFocus, a2: 1);
      pNewFocus->OnHighlight(this: pNewFocus, a2: 1);
      pNewFocus->Redraw(this: pNewFocus);
      this->m_pHighlighted = pNewFocus;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D3E76
// Name: public: void CMFCRibbonPanel::MakeGalleryItemVisible(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanel::MakeGalleryItemVisible(CMFCRibbonPanel *this, CMFCRibbonBaseElement *pItem)
{
  int v3; // eax
  CWnd *ParentWnd; // eax
  CScrollBar *m_pScrollBar; // eax
  int rectItem_4; // [esp+Ch] [ebp-20h]
  int rectItem_12; // [esp+14h] [ebp-18h]
  CRect rectPalette; // [esp+18h] [ebp-14h] BYREF

  if ( CObject::IsKindOf(this: pItem, pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon) != 0 )
  {
    rectItem_4 = pItem->m_rect.top;
    rectItem_12 = pItem->m_rect.bottom;
    CMFCRibbonPanel::GetGalleryRect(this, result: &rectPalette);
    if ( rectItem_4 >= rectPalette.top )
    {
      if ( rectItem_12 <= rectPalette.bottom )
        return;
      v3 = rectPalette.bottom - rectItem_12;
    }
    else
    {
      v3 = rectPalette.top - rectItem_4;
    }
    if ( v3 != 0 )
    {
      CMFCRibbonPanel::ScrollPalette(this, nScrollOffset: v3, bIsDelta: 1);
      if ( CMFCRibbonPanel::GetParentWnd(this) != nullptr )
      {
        ParentWnd = CMFCRibbonPanel::GetParentWnd(this);
        RedrawWindow(hWnd: ParentWnd->m_hWnd, lprcUpdate: &rectPalette, hrgnUpdate: nullptr, flags: 0x105u);
      }
      m_pScrollBar = this->m_pScrollBar;
      if ( m_pScrollBar != nullptr && m_pScrollBar->m_hWnd != nullptr )
        SetScrollPos(hWnd: m_pScrollBar->m_hWnd, nBar: 2, nPos: this->m_nScrollOffset, bRedraw: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DEF42
// Name: public: virtual int CMFCRibbonCategory::NotifyControlCommand(int,int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::NotifyControlCommand(
        CMFCRibbonCategory *this,
        int bAccelerator,
        int nNotifyCode,
        unsigned int wParam,
        int lParam)
{
  int v6; // edi
  CMFCRibbonPanel *v7; // ecx

  v6 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v6 < 0 || v6 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v7 = this->m_arPanels.m_pData[v6];
    if ( v7->NotifyControlCommand(this: v7, a2: bAccelerator, a3: nNotifyCode, a4: wParam, a5: lParam) != 0 )
      break;
    if ( ++v6 >= this->m_arPanels.m_nSize )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DEF9B
// Name: protected: void CMFCRibbonCategory::ShowElements(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::ShowElements(CMFCRibbonCategory *this, int bShow)
{
  int v3; // edi
  CMFCRibbonPanel *v4; // ecx
  CFrameWnd *ParentFrame; // eax

  v3 = 0;
  for ( this->m_pParentRibbonBar->m_dwHideFlags = bShow == 0; v3 < this->m_arPanels.m_nSize; ++v3 )
  {
    if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arPanels.m_pData[v3];
    v4->OnShow(this: v4, a2: bShow);
  }
  ParentFrame = CWnd::GetParentFrame(this: this->m_pParentRibbonBar);
  ParentFrame->RecalcLayout(this: ParentFrame, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103DF00B
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::FindByID(unsigned int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonCategory::FindByID(
        CMFCRibbonCategory *this,
        unsigned int uiCmdID,
        int bVisibleOnly)
{
  int v4; // ecx
  int m_nSize; // edx
  CMFCRibbonDefaultPanelButton *result; // eax
  int v7; // edi

  v4 = 0;
  if ( bVisibleOnly == 0 )
  {
    m_nSize = this->m_arElements.m_nSize;
    if ( m_nSize > 0 )
    {
      while ( v4 >= 0 && v4 < m_nSize )
      {
        result = (CMFCRibbonDefaultPanelButton *)this->m_arElements.m_pData[v4];
        if ( result->m_nID == uiCmdID )
          return result;
        if ( ++v4 >= m_nSize )
          goto LABEL_7;
      }
LABEL_14:
      AfxThrowInvalidArgException();
    }
  }
LABEL_7:
  v7 = 0;
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( v7 >= 0 && v7 < this->m_arPanels.m_nSize )
    {
      result = CMFCRibbonPanel::FindByID(this: this->m_arPanels.m_pData[v7], uiCmdID);
      if ( result != nullptr )
        return result;
      if ( ++v7 >= this->m_arPanels.m_nSize )
        return nullptr;
    }
    goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103DF085
// Name: public: void CMFCRibbonCategory::GetElementsByID(unsigned int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::GetElementsByID(
        CMFCRibbonCategory *this,
        unsigned int uiCmdID,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons)
{
  int v4; // edi
  int v5; // edi

  v4 = 0;
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arPanels.m_nSize )
    {
      CMFCRibbonPanel::GetElementsByID(this: this->m_arPanels.m_pData[v4++], uiCmdID, arElements: arButtons);
      if ( v4 >= this->m_arPanels.m_nSize )
        goto LABEL_5;
    }
LABEL_12:
    AfxThrowInvalidArgException();
  }
LABEL_5:
  v5 = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( v5 >= 0 && v5 < this->m_arElements.m_nSize )
    {
      if ( this->m_arElements.m_pData[v5]->m_nID == uiCmdID )
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arButtons,
          nIndex: arButtons->m_nSize,
          newElement: (CMFCRibbonKeyTip *)this->m_arElements.m_pData[v5]);
      if ( ++v5 >= this->m_arElements.m_nSize )
        return;
    }
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF109
// Name: public: class CMFCRibbonPanel __near * CMFCRibbonCategory::FindPanelWithElem(class CMFCRibbonBaseElement const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanel *__thiscall CMFCRibbonCategory::FindPanelWithElem(
        CMFCRibbonCategory *this,
        const CMFCRibbonBaseElement *pElement)
{
  int v3; // edi
  CMFCRibbonPanel *v4; // ebx

  v3 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arPanels.m_pData[v3];
    if ( CMFCRibbonPanel::HasElement(this: v4, pElem: pElement) != 0 )
      break;
    if ( ++v3 >= this->m_arPanels.m_nSize )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103DF15C
// Name: public: void CMFCRibbonCategory::GetElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::GetElements(
        CMFCRibbonCategory *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int v3; // edi
  int v4; // edi

  v3 = 0;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
    nNewSize: 0,
    nGrowBy: -1);
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( v3 >= 0 && v3 < this->m_arPanels.m_nSize )
    {
      CMFCRibbonPanel::GetElements(this: this->m_arPanels.m_pData[v3++], arElements);
      if ( v3 >= this->m_arPanels.m_nSize )
        goto LABEL_5;
    }
LABEL_10:
    AfxThrowInvalidArgException();
  }
LABEL_5:
  v4 = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arElements.m_nSize )
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
        nIndex: arElements->m_nSize,
        newElement: (CMFCRibbonKeyTip *)this->m_arElements.m_pData[v4++]);
      if ( v4 >= this->m_arElements.m_nSize )
        return;
    }
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF1E0
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::GetDroppedDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonCategory::GetDroppedDown(CMFCRibbonCategory *this)
{
  int v2; // edi
  CMFCRibbonBaseElement *result; // eax

  v2 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    result = CMFCRibbonPanel::GetDroppedDown(this: this->m_arPanels.m_pData[v2]);
    if ( result != nullptr )
      break;
    if ( ++v2 >= this->m_arPanels.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DF222
// Name: public: virtual void CMFCRibbonCategory::OnRTLChanged(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnRTLChanged(CMFCRibbonCategory *this, int bIsRTL)
{
  int v3; // edi
  CMFCRibbonPanel *v4; // ecx
  int v5; // edi
  CMFCRibbonBaseElement *v6; // ecx

  v3 = 0;
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( v3 >= 0 && v3 < this->m_arPanels.m_nSize )
    {
      v4 = this->m_arPanels.m_pData[v3];
      v4->OnRTLChanged(this: v4, a2: bIsRTL);
      if ( ++v3 >= this->m_arPanels.m_nSize )
        goto LABEL_5;
    }
LABEL_10:
    AfxThrowInvalidArgException();
  }
LABEL_5:
  v5 = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( v5 >= 0 && v5 < this->m_arElements.m_nSize )
    {
      v6 = this->m_arElements.m_pData[v5];
      v6->OnRTLChanged(this: v6, a2: bIsRTL);
      if ( ++v5 >= this->m_arElements.m_nSize )
        goto LABEL_9;
    }
    goto LABEL_10;
  }
LABEL_9:
  this->m_nLastCategoryWidth = -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DF29E
// Name: protected: int CMFCRibbonCategory::SetPanelsLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::SetPanelsLayout(CMFCRibbonCategory *this, int nWidth)
{
  int v2; // ebx
  CMFCRibbonPanel *v3; // edx
  int m_nSize; // edi
  int m_nCurrWidthIndex; // esi
  int nTotalWidth; // [esp+Ch] [ebp-4h]

  nTotalWidth = 0;
  v2 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return 1;
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_arPanels.m_nSize )
      goto LABEL_13;
    v3 = this->m_arPanels.m_pData[v2];
    m_nSize = v3->m_arWidths.m_nSize;
    m_nCurrWidthIndex = v3->m_nCurrWidthIndex;
    v3->m_bForceCollpapse = 0;
    if ( m_nCurrWidthIndex == m_nSize - 1 && m_nSize > 1 )
      v3->m_bForceCollpapse = 1;
    if ( m_nCurrWidthIndex < 0 || m_nCurrWidthIndex >= m_nSize )
LABEL_13:
      AfxThrowInvalidArgException();
    nTotalWidth += v3->m_arWidths.m_pData[m_nCurrWidthIndex] + 2 * v3->m_nXMargin + 2;
    if ( nTotalWidth > nWidth )
      return 0;
    if ( ++v2 >= this->m_arPanels.m_nSize )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF32B
// Name: protected: void CMFCRibbonCategory::ResetPanelsLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::ResetPanelsLayout(CMFCRibbonCategory *this)
{
  int i; // eax
  CMFCRibbonPanel *v2; // edx

  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v2 = this->m_arPanels.m_pData[i];
    v2->m_nCurrWidthIndex = 0;
    v2->m_bTruncateCaption = 0;
  }
  this->m_nScrollOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DF368
// Name: protected: void CMFCRibbonCategory::EnsureVisible(class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::EnsureVisible(CMFCRibbonCategory *this, CMFCRibbonButton *pButton)
{
  CRect *p_m_rect; // esi
  int v4; // esi
  CMFCRibbonPanel *v5; // eax
  const RECT *v6; // esi
  int rectClient; // [esp+8h] [ebp-34h]
  int rectClient_8; // [esp+10h] [ebp-2Ch]
  int nPanelIndex; // [esp+18h] [ebp-24h]
  int nLastVisiblePanel; // [esp+1Ch] [ebp-20h]
  int nFirstVisiblePanel; // [esp+20h] [ebp-1Ch]
  CMFCRibbonPanel *pParentPanel; // [esp+24h] [ebp-18h]
  CRect rectButton; // [esp+28h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    rectClient = p_m_rect->left + 4;
    rectClient_8 = p_m_rect->right - 4;
    rectButton = pButton->m_rect;
    if ( IsRectEmpty(lprc: &rectButton) )
    {
      v4 = 0;
      pParentPanel = pButton->GetParentPanel(this: pButton);
      if ( pParentPanel != nullptr )
      {
        nPanelIndex = -1;
        nFirstVisiblePanel = -1;
        nLastVisiblePanel = -1;
        if ( this->m_arPanels.m_nSize > 0 )
        {
          do
          {
            if ( v4 < 0 || v4 >= this->m_arPanels.m_nSize )
              AfxThrowInvalidArgException();
            v5 = this->m_arPanels.m_pData[v4];
            if ( v5 == pParentPanel )
              nPanelIndex = v4;
            if ( !IsRectEmpty(lprc: &v5->m_rect) )
            {
              if ( nFirstVisiblePanel < 0 )
                nFirstVisiblePanel = v4;
              nLastVisiblePanel = v4;
            }
            ++v4;
          }
          while ( v4 < this->m_arPanels.m_nSize );
          if ( nPanelIndex != -1 && nFirstVisiblePanel != -1 && nLastVisiblePanel != -1 )
          {
            if ( nPanelIndex >= nFirstVisiblePanel )
            {
              if ( nPanelIndex > nLastVisiblePanel && this->OnScrollHorz(this, a2: 0, a3: 0) != 0 )
              {
                while ( (IsRectEmpty(lprc: &pParentPanel->m_rect) || pParentPanel->m_rect.right > rectClient_8)
                     && this->OnScrollHorz(this, a2: 0, a3: 0) != 0 )
                  ;
              }
            }
            else if ( this->OnScrollHorz(this, a2: 1, a3: 0) != 0 )
            {
              v6 = &pParentPanel->m_rect;
              while ( (IsRectEmpty(lprc: v6) || v6->left < rectClient) && this->OnScrollHorz(this, a2: 1, a3: 0) != 0 )
                ;
            }
          }
        }
      }
    }
    else if ( rectButton.left >= this->m_rect.left - 2 )
    {
      if ( rectButton.right > this->m_rect.right + 2 )
        this->OnScrollHorz(this, a2: 0, a3: rectButton.right - rectClient_8);
    }
    else
    {
      this->OnScrollHorz(this, a2: 1, a3: rectClient - rectButton.left);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF522
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::GetFirstVisibleElement(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonCategory::GetFirstVisibleElement(CMFCRibbonCategory *this)
{
  CMFCRibbonPanel *v3; // esi

  if ( this->m_arPanels.m_nSize == 0 )
    return nullptr;
  if ( this->m_nScrollOffset > 0 )
    this->OnScrollHorz(this, a2: 1, a3: this->m_nScrollOffset);
  if ( this->m_arPanels.m_nSize <= 0 )
    AfxThrowInvalidArgException();
  v3 = *this->m_arPanels.m_pData;
  if ( CMFCRibbonPanel::IsCollapsed(this: v3) != 0 )
    return &v3->m_btnDefault;
  else
    return (CMFCRibbonDefaultPanelButton *)CMFCRibbonPanel::GetElement(this: v3, nIndex: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103DF57B
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::GetLastVisibleElement(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonCategory::GetLastVisibleElement(CMFCRibbonCategory *this)
{
  CMFCRibbonDefaultPanelButton *result; // eax
  int v3; // eax
  CMFCRibbonPanel *v4; // esi
  int Count; // eax
  RECT rc; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_arPanels.m_nSize == 0 )
    return nullptr;
  while ( 1 )
  {
    rc = (RECT)this->m_ScrollRight.m_rect;
    if ( IsRectEmpty(lprc: &rc) )
      break;
    this->OnScrollHorz(this, a2: 0, a3: 0);
  }
  v3 = this->m_arPanels.m_nSize - 1;
  if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
    AfxThrowInvalidArgException();
  v4 = this->m_arPanels.m_pData[v3];
  if ( CMFCRibbonPanel::IsCollapsed(this: v4) != 0 )
    return &v4->m_btnDefault;
  result = (CMFCRibbonDefaultPanelButton *)CMFCRibbonPanel::GetCount(this: v4);
  if ( result != nullptr )
  {
    Count = CMFCRibbonPanel::GetCount(this: v4);
    return (CMFCRibbonDefaultPanelButton *)CMFCRibbonPanel::GetElement(this: v4, nIndex: Count - 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DF624
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::GetFocused(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonCategory::GetFocused(CMFCRibbonCategory *this)
{
  int v2; // edi
  CMFCRibbonDefaultPanelButton *result; // eax

  v2 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    result = CMFCRibbonPanel::GetFocused(this: this->m_arPanels.m_pData[v2]);
    if ( result != nullptr )
      break;
    if ( ++v2 >= this->m_arPanels.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DF666
// Name: public: void CMFCRibbonCategory::GetVisibleElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::GetVisibleElements(
        CMFCRibbonCategory *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons)
{
  int i; // edi

  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    CMFCRibbonPanel::GetVisibleElements(this: this->m_arPanels.m_pData[i], arElements: arButtons);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF6AB
// Name: public: virtual int CMFCRibbonCategory::OnKey(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::OnKey(CMFCRibbonCategory *this, unsigned int nChar)
{
  CMFCRibbonDefaultPanelButton *Focused; // eax
  int v5; // eax
  CMFCRibbonBaseElement *v6; // ebx
  CRect *p_m_rect; // esi
  BOOL v8; // eax
  BOOL v9; // ebx
  CMFCRibbonDefaultPanelButton *FirstVisibleElement; // eax
  _DWORD *v11; // edi
  CMFCRibbonBaseElement *v12; // esi
  CMFCRibbonBar *m_pParentRibbonBar; // ecx
  CMFCRibbonBaseElement_vtbl *v14; // eax
  int v15; // eax
  BOOL v16; // [esp-8h] [ebp-80h]
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arButtons; // [esp+14h] [ebp-64h] BYREF
  CMFCRibbonBaseElement *pFocused; // [esp+28h] [ebp-50h]
  CMFCRibbonBaseElement *NextFocusedElement; // [esp+2Ch] [ebp-4Ch]
  int nScroll; // [esp+30h] [ebp-48h] BYREF
  CMFCRibbonCategory *v21; // [esp+34h] [ebp-44h]
  RECT v22; // [esp+38h] [ebp-40h] BYREF
  RECT rc; // [esp+48h] [ebp-30h] BYREF
  RECT m_rect; // [esp+58h] [ebp-20h] BYREF
  int v25; // [esp+74h] [ebp-4h]

  v21 = this;
  NextFocusedElement = nullptr;
  if ( nChar != 9 )
  {
    if ( nChar == 13 || nChar == 32 )
    {
      Focused = CMFCRibbonCategory::GetFocused(this);
      if ( Focused == nullptr )
        return 0;
      Focused->OnKey(this: Focused, a2: 0);
      return 1;
    }
    if ( nChar <= 0x24 || nChar > 0x28 )
      return 0;
  }
  arButtons.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  memset(&arButtons.m_pData, 0, 16);
  v25 = 0;
  CMFCRibbonCategory::GetVisibleElements(this, &arButtons);
  if ( arButtons.m_nSize == 0 )
  {
    v25 = -1;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arButtons);
    return 0;
  }
  pFocused = CMFCRibbonCategory::GetFocused(this);
  if ( pFocused != nullptr )
  {
    nScroll = 0;
    p_m_rect = &this->m_ScrollLeft.m_rect;
    v22.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    v22.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    v22.right = p_m_rect->left;
    v22.bottom = p_m_rect->top;
    v8 = IsRectEmpty(lprc: &v22);
    m_rect = (RECT)v21->m_ScrollRight.m_rect;
    v9 = !v8;
    v16 = !IsRectEmpty(lprc: &m_rect);
    NextFocusedElement = CMFCRibbonBar::FindNextFocusedElement(
                           nChar,
                           arElems: &arButtons,
                           rectElems: v21->m_rect,
                           pFocused,
                           bIsScrollLeftAvailable: v9,
                           bIsScrollRightAvailable: v16,
                           &nScroll);
    switch ( nScroll )
    {
      case 0:
        goto LABEL_31;
      case -2:
        FirstVisibleElement = CMFCRibbonCategory::GetFirstVisibleElement(this: v21);
        break;
      case -1:
      case 1:
        v21->OnScrollHorz(this: v21, a2: nScroll < 0, a3: 0);
        goto LABEL_31;
      case 2:
        FirstVisibleElement = CMFCRibbonCategory::GetLastVisibleElement(this: v21);
        break;
      default:
        goto LABEL_31;
    }
    NextFocusedElement = FirstVisibleElement;
  }
  else
  {
    v5 = 0;
    nScroll = 0;
    if ( arButtons.m_nSize > 0 )
    {
      while ( 1 )
      {
        if ( v5 < 0 || v5 >= arButtons.m_nSize )
          AfxThrowInvalidArgException();
        v6 = arButtons.m_pData[v5];
        if ( v6->IsTabStop(this: v6) != 0 )
        {
          rc = (RECT)v6->m_rect;
          if ( !IsRectEmpty(lprc: &rc) )
            break;
        }
        v5 = nScroll + 1;
        nScroll = v5;
        if ( v5 >= arButtons.m_nSize )
          goto LABEL_31;
      }
      NextFocusedElement = v6;
    }
  }
LABEL_31:
  v25 = -1;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arButtons);
  v11 = &NextFocusedElement->__vftable;
  v12 = pFocused;
  if ( NextFocusedElement == pFocused )
    return 1;
  if ( NextFocusedElement == nullptr )
    return 0;
  m_pParentRibbonBar = v21->m_pParentRibbonBar;
  if ( m_pParentRibbonBar != nullptr )
    CMFCRibbonBar::DeactivateKeyboardFocus(this: m_pParentRibbonBar, bSetFocus: 0);
  if ( v12 != nullptr )
  {
    v14 = v12->__vftable;
    v12->m_bIsFocused = 0;
    v12->m_bIsHighlighted = 0;
    v14->OnSetFocus(this: v12, a2: 0);
    v12->Redraw(this: v12);
  }
  v15 = *v11;
  v11[28] = 1;
  (*(void (__thiscall **)(_DWORD *, int))(v15 + 388))(a1: v11, a2: 1);
  (*(void (__thiscall **)(_DWORD *))(*v11 + 280))(a1: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DF8CA
// Name: public: virtual void CMFCRibbonTab::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonTab::OnDraw(CMFCRibbonTab *this, CDC *pDC)
{
  CRect *p_m_rect; // esi
  CMFCVisualManager *Instance; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  int *p_top; // esi
  CDC_vtbl *v8; // edx
  int v9; // eax
  unsigned int clrTextOld; // [esp+10h] [ebp-28h]
  unsigned int clrTextOlda; // [esp+10h] [ebp-28h]
  CRect rectTabText; // [esp+14h] [ebp-24h] BYREF
  CRect rectTab; // [esp+24h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    clrTextOld = this->m_pParent->m_bIsActive != 0 || this->GetDroppedDown(this) != nullptr;
    Instance = CMFCVisualManager::GetInstance();
    v5 = Instance->OnDrawRibbonCategoryTab(this: Instance, a2: pDC, a3: this, a4: clrTextOld);
    v6 = pDC->SetTextColor(this: pDC, a2: v5);
    rectTab.left = p_m_rect->left;
    p_top = &p_m_rect->top;
    rectTab.top = *p_top++;
    rectTab.right = *p_top;
    rectTab.bottom = p_top[1];
    v8 = pDC->__vftable;
    rectTabText = this->m_rect;
    clrTextOlda = v6;
    v8->DrawTextA(
      this: pDC,
      a2: this->m_pParent->m_strName.m_pszData,
      a3: *((_DWORD *)this->m_pParent->m_strName.m_pszData - 3),
      a4: &rectTabText,
      a5: 1060u);
    v9 = (rectTab.right - rectTab.left - (rectTabText.right - rectTabText.left)) / 2;
    if ( v9 < 4 )
      v9 = 4;
    InflateRect(lprc: &rectTab, dx: -v9, dy: 0);
    rectTab.top += 3;
    pDC->DrawTextA(
      this: pDC,
      a2: this->m_pParent->m_strName.m_pszData,
      a3: *((_DWORD *)this->m_pParent->m_strName.m_pszData - 3),
      a4: &rectTab,
      a5: 36u);
    pDC->SetTextColor(this: pDC, a2: clrTextOlda);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DF9CC
// Name: public: virtual class CRect CMFCRibbonTab::GetKeyTipRect(class CDC __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCRibbonTab::GetKeyTipRect(CMFCRibbonTab *this, CRect *result, CDC *pDC, int __formal)
{
  CMFCRibbonCategory *m_pParent; // eax
  CDC_vtbl *v6; // edx
  int v7; // eax
  CSize sizeKeyTip; // [esp+14h] [ebp-2Ch] BYREF
  CRect rectTabText; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectTab; // [esp+2Ch] [ebp-14h] BYREF

  this->GetKeyTipSize(this, result: &sizeKeyTip, a3: pDC);
  if ( (sizeKeyTip.cx != 0 || sizeKeyTip.cy != 0) && !IsRectEmpty(lprc: &this->m_rect) )
  {
    rectTab.left = this->m_rect.left;
    rectTab.top = this->m_rect.top;
    rectTab.right = this->m_rect.right;
    m_pParent = this->m_pParent;
    rectTab.bottom = this->m_rect.bottom;
    v6 = pDC->__vftable;
    rectTabText = this->m_rect;
    v6->DrawTextA(
      this: pDC,
      a2: m_pParent->m_strName.m_pszData,
      a3: *((_DWORD *)m_pParent->m_strName.m_pszData - 3),
      a4: &rectTabText,
      a5: 1060u);
    v7 = (rectTab.right - rectTab.left - (rectTabText.right - rectTabText.left)) / 2;
    if ( v7 < 4 )
      v7 = 4;
    InflateRect(lprc: &rectTab, dx: -v7, dy: 0);
    rectTab.left = (rectTab.right + rectTab.left) / 2 - sizeKeyTip.cx / 2;
    rectTab.right = sizeKeyTip.cx + rectTab.left;
    rectTab.top = rectTabText.bottom - 2;
    rectTab.bottom = rectTabText.bottom - 2 + sizeKeyTip.cy;
    *result = rectTab;
    return result;
  }
  else
  {
    result->left = 0;
    result->top = 0;
    result->right = 0;
    result->bottom = 0;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DFAD4
// Name: public: virtual void CMFCRibbonTab::OnLButtonDblClk(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonTab::OnLButtonDblClk(CMFCRibbonTab *this, CPoint __formal)
{
  CMFCRibbonCategory *m_pParent; // eax
  int v4; // edi
  CMFCRibbonCategory *v5; // ecx
  CMFCRibbonBar *m_pParentRibbonBar; // edi
  CFrameWnd *ParentFrame; // eax

  m_pParent = this->m_pParent;
  if ( m_pParent->m_bIsActive != 0
    && (m_pParent->m_ActiveTime == -1 || (v4 = clock() - this->m_pParent->m_ActiveTime) >= (int)GetDoubleClickTime()) )
  {
    v5 = this->m_pParent;
    m_pParentRibbonBar = v5->m_pParentRibbonBar;
    if ( (m_pParentRibbonBar->m_dwHideFlags & 1) != 0 )
    {
      if ( this->IsDroppedDown(this) != 0 )
        this->ClosePopupMenu(this);
      CMFCRibbonCategory::ShowElements(this: this->m_pParent, bShow: 1);
    }
    else
    {
      CMFCRibbonCategory::ShowElements(this: v5, bShow: 0);
    }
    ParentFrame = CWnd::GetParentFrame(this: m_pParentRibbonBar);
    ParentFrame->RecalcLayout(this: ParentFrame, a2: 1);
    RedrawWindow(hWnd: m_pParentRibbonBar->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DFB65
// Name: public: virtual CMFCRibbonCategory::~CMFCRibbonCategory(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::~CMFCRibbonCategory(CMFCRibbonCategory *this)
{
  int v2; // edi
  CMFCRibbonPanel *v3; // eax
  int v4; // edi
  CMFCRibbonBaseElement *v5; // eax

  this->__vftable = (CMFCRibbonCategory_vtbl *)&CMFCRibbonCategory::`vftable';
  v2 = 0;
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( v2 >= 0 && v2 < this->m_arPanels.m_nSize )
    {
      v3 = this->m_arPanels.m_pData[v2];
      if ( v3 != nullptr )
        ((void (__thiscall *)(CMFCRibbonPanel *, int))v3->dtr_CObject)(a1: v3, a2: 1);
      if ( ++v2 >= this->m_arPanels.m_nSize )
        goto LABEL_7;
    }
LABEL_14:
    AfxThrowInvalidArgException();
  }
LABEL_7:
  v4 = 0;
  if ( this->m_arElements.m_nSize > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arElements.m_nSize )
    {
      v5 = this->m_arElements.m_pData[v4];
      if ( v5 != nullptr )
        ((void (__thiscall *)(CMFCRibbonBaseElement *, int))v5->dtr_CObject)(a1: v5, a2: 1);
      if ( ++v4 >= this->m_arElements.m_nSize )
        goto LABEL_13;
    }
    goto LABEL_14;
  }
LABEL_13:
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &this->m_arElements);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_LargeImages);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_SmallImages);
  CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>::~CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>(this: &this->m_arPanels);
  CArray<int,int>::~CArray<int,int>(this: &this->m_arCollapseOrder);
  CMFCRibbonButton::~CMFCRibbonButton(this: &this->m_ScrollRight);
  CMFCRibbonButton::~CMFCRibbonButton(this: &this->m_ScrollLeft);
  CMFCRibbonBaseElement::~CMFCRibbonBaseElement(this: &this->m_Tab);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103DFC8F
// Name: public: int CMFCRibbonCategory::GetMaxHeight(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::GetMaxHeight(CMFCRibbonCategory *this, CDC *pDC)
{
  int v2; // ebx
  CMFCRibbonPanel *v4; // edi
  CSize *TextExtent; // eax
  CSize v7; // [esp+8h] [ebp-Ch] BYREF
  int nMaxHeight; // [esp+10h] [ebp-4h]

  v2 = 0;
  for ( nMaxHeight = 0; v2 < this->m_arPanels.m_nSize; ++v2 )
  {
    if ( v2 < 0 || v2 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arPanels.m_pData[v2];
    if ( nMaxHeight <= v4->GetHeight(this: v4, a2: pDC) )
      nMaxHeight = v4->GetHeight(this: v4, a2: pDC);
  }
  TextExtent = CDC::GetTextExtent(this: pDC, result: &v7, str: &this->m_strName);
  return TextExtent->cy + nMaxHeight + 7;
}

//------------------------------------------------------------------------------
// Address: 0x103DFD0A
// Name: protected: void CMFCRibbonCategory::RecalcPanelWidths(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::RecalcPanelWidths(CMFCRibbonCategory *this, CDC *pDC)
{
  int i; // ebx
  CMFCRibbonPanel *v4; // edi
  int nHeight; // [esp+8h] [ebp-4h]

  nHeight = -1;
  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arPanels.m_pData[i];
    if ( v4->m_arWidths.m_nSize == 0 )
    {
      if ( nHeight == -1 )
        nHeight = CMFCRibbonCategory::GetMaxHeight(this, pDC);
      v4->RecalcWidths(this: v4, a2: pDC, a3: nHeight);
      this->m_nLastCategoryWidth = -1;
    }
  }
  this->m_nMinWidth = -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DFD82
// Name: public: virtual void CMFCRibbonCategory::OnMouseMove(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnMouseMove(CMFCRibbonCategory *this, CPoint point)
{
  CMFCRibbonPanel *PanelFromPoint; // eax

  ((void (__thiscall *)(CRibbonCategoryScroll *, int, int))this->m_ScrollLeft.OnMouseMove)(
    a1: &this->m_ScrollLeft,
    a2: point.x,
    a3: point.y);
  ((void (__thiscall *)(CRibbonCategoryScroll *, int, int))this->m_ScrollRight.OnMouseMove)(
    a1: &this->m_ScrollRight,
    a2: point.x,
    a3: point.y);
  if ( this->m_ScrollLeft.IsHighlighted(this: &this->m_ScrollLeft) == 0
    && this->m_ScrollRight.IsHighlighted(this: &this->m_ScrollRight) == 0 )
  {
    PanelFromPoint = CMFCRibbonCategory::GetPanelFromPoint(this, point);
    CMFCRibbonCategory::HighlightPanel(this, pHLPanel: PanelFromPoint, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DFE04
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonCategory::HitTest(class CPoint,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonCategory::HitTest(
        CMFCRibbonCategory *this,
        CPoint point,
        int bCheckPanelCaption)
{
  CMFCRibbonBaseElement *result; // eax
  CMFCRibbonPanel *PanelFromPoint; // eax

  result = CMFCRibbonCategory::HitTestScrollButtons(this, point);
  if ( result == nullptr )
  {
    PanelFromPoint = CMFCRibbonCategory::GetPanelFromPoint(this, point);
    if ( PanelFromPoint != nullptr )
      return ((CMFCRibbonBaseElement *(__thiscall *)(CMFCRibbonPanel *, int, int, int))PanelFromPoint->HitTest)(
               a1: PanelFromPoint,
               a2: point.x,
               a3: point.y,
               a4: bCheckPanelCaption);
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DFE45
// Name: public: int CMFCRibbonCategory::HitTestEx(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::HitTestEx(CMFCRibbonCategory *this, CPoint point)
{
  CMFCRibbonPanel *PanelFromPoint; // eax

  PanelFromPoint = CMFCRibbonCategory::GetPanelFromPoint(this, point);
  if ( PanelFromPoint != nullptr )
    return ((int (__thiscall *)(CMFCRibbonPanel *, int, int))PanelFromPoint->HitTestEx)(
             a1: PanelFromPoint,
             a2: point.x,
             a3: point.y);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DFE6F
// Name: protected: void CMFCRibbonCategory::SetActive(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::SetActive(CMFCRibbonCategory *this, int bIsActive)
{
  int v3; // edi
  CMFCRibbonPanel *v4; // ecx
  int v5; // eax

  if ( this->m_bIsActive != bIsActive )
  {
    if ( (this->m_pParentRibbonBar->m_dwHideFlags & 1) != 0 )
    {
      this->m_bIsActive = bIsActive;
    }
    else
    {
      CMFCRibbonCategory::ShowElements(this, bShow: 1);
      v3 = 0;
      for ( this->m_bIsActive = bIsActive; v3 < this->m_arPanels.m_nSize; ++v3 )
      {
        if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
          AfxThrowInvalidArgException();
        v4 = this->m_arPanels.m_pData[v3];
        v4->OnShow(this: v4, a2: bIsActive);
      }
      if ( bIsActive != 0 )
        v5 = clock();
      else
        v5 = -1;
      this->m_ActiveTime = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DFF0E
// Name: public: virtual void CMFCRibbonCategory::RecalcLayout(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::RecalcLayout(CMFCRibbonCategory *this, CDC *pDC)
{
  CRect *p_m_rect; // esi
  int v4; // edi
  CMFCRibbonPanel *v5; // esi
  int v6; // eax
  int *p_top; // esi
  int top; // eax
  int v9; // ecx
  CMFCRibbonPanel *v10; // eax
  int v11; // edx
  int v12; // esi
  int m_nSize; // edx
  int *m_pData; // ecx
  int v15; // eax
  CMFCRibbonPanel *v16; // eax
  int v17; // ecx
  int m_nCurrWidthIndex; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // edi
  CMFCRibbonPanel *v22; // ecx
  CMFCRibbonPanel *v23; // eax
  CMFCRibbonBar *m_pParentRibbonBar; // eax
  int bHideAll; // [esp+10h] [ebp-1Ch]
  int bHideAlla; // [esp+10h] [ebp-1Ch]
  int bRedrawScroll; // [esp+14h] [ebp-18h]
  int bRedrawScrolla; // [esp+14h] [ebp-18h]
  CRect rectClient; // [esp+18h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    if ( this->m_pParentMenuBar != nullptr )
      CMFCRibbonCategory::CleanUpSizes(this);
    CMFCRibbonCategory::RecalcPanelWidths(this, pDC);
    if ( this->m_arPanels.m_nSize != 0 )
    {
      bRedrawScroll = 0;
      bHideAll = (this->m_pParentRibbonBar->m_dwHideFlags & 3) != 0;
      if ( this->m_nMinWidth < 0 )
        this->m_nMinWidth = CMFCRibbonCategory::GetMinWidth(this, pDC);
      if ( bHideAll != 0 && this->m_pParentMenuBar == nullptr )
      {
        v4 = 0;
        if ( this->m_arPanels.m_nSize > 0 )
        {
          while ( v4 >= 0 && v4 < this->m_arPanels.m_nSize )
          {
            v5 = this->m_arPanels.m_pData[v4];
            memset(&rectClient, 0, sizeof(rectClient));
            v5->Reposition(this: v5, a2: pDC, a3: &rectClient);
            v5->OnShow(this: v5, a2: 0);
            if ( ++v4 >= this->m_arPanels.m_nSize )
              goto LABEL_13;
          }
          goto LABEL_14;
        }
LABEL_13:
        this->m_nLastCategoryWidth = -1;
        this->m_nMinWidth = -1;
        goto LABEL_52;
      }
      v6 = p_m_rect->right - p_m_rect->left;
      if ( this->m_nLastCategoryWidth == v6 && this->m_nLastCategoryOffsetY == this->m_rect.top )
      {
LABEL_52:
        CMFCRibbonCategory::UpdateScrollButtons(this);
        if ( bRedrawScroll != 0 )
        {
          m_pParentRibbonBar = this->m_pParentRibbonBar;
          if ( m_pParentRibbonBar != nullptr && m_pParentRibbonBar->m_hWnd != nullptr )
          {
            rectClient = this->m_ScrollLeft.m_rect;
            if ( !IsRectEmpty(lprc: &rectClient)
              || (rectClient = this->m_ScrollRight.m_rect, !IsRectEmpty(lprc: &rectClient)) )
            {
              RedrawWindow(
                hWnd: this->m_pParentRibbonBar->m_hWnd,
                lprcUpdate: &this->m_rect,
                hrgnUpdate: nullptr,
                flags: 0x105u);
            }
          }
        }
        return;
      }
      rectClient.left = p_m_rect->left;
      p_top = &p_m_rect->top;
      rectClient.top = *p_top++;
      rectClient.right = *p_top;
      this->m_nLastCategoryWidth = v6;
      top = this->m_rect.top;
      rectClient.bottom = p_top[1];
      rectClient.left += 4;
      rectClient.right -= 4;
      this->m_nLastCategoryOffsetY = top;
      CMFCRibbonCategory::ResetPanelsLayout(this);
      bHideAlla = rectClient.right - rectClient.left;
      if ( rectClient.right - rectClient.left <= this->m_nMinWidth )
      {
        v9 = 0;
        if ( this->m_arPanels.m_nSize > 0 )
        {
          while ( v9 >= 0 && v9 < this->m_arPanels.m_nSize )
          {
            v10 = this->m_arPanels.m_pData[v9];
            v11 = v10->m_arWidths.m_nSize - 1;
            ++v9;
            v10->m_bForceCollpapse = 1;
            v10->m_nCurrWidthIndex = v11;
            if ( v9 >= this->m_arPanels.m_nSize )
              goto LABEL_51;
          }
LABEL_14:
          AfxThrowInvalidArgException();
        }
LABEL_51:
        this->ReposPanels(this, a2: pDC);
        bRedrawScroll = 1;
        goto LABEL_52;
      }
      if ( this->m_arCollapseOrder.m_nSize <= 0 )
        goto LABEL_50;
      v12 = 0;
      bRedrawScrolla = 1;
      while ( 1 )
      {
        if ( CMFCRibbonCategory::SetPanelsLayout(this, nWidth: bHideAlla) != 0 )
          goto LABEL_51;
        m_nSize = this->m_arCollapseOrder.m_nSize;
        if ( v12 == m_nSize )
          goto LABEL_40;
        if ( v12 < 0 || v12 >= m_nSize )
          goto LABEL_14;
        m_pData = this->m_arCollapseOrder.m_pData;
        v15 = m_pData[v12];
        if ( v15 < 0 || v15 >= this->m_arPanels.m_nSize )
        {
LABEL_40:
          CMFCRibbonCategory::ResetPanelsLayout(this);
LABEL_50:
          while ( CMFCRibbonCategory::SetPanelsLayout(this, nWidth: bHideAlla) == 0 )
          {
            v19 = 0;
            v20 = -1;
            v21 = 1;
            if ( this->m_arPanels.m_nSize <= 0 )
              break;
            do
            {
              if ( v19 < 0 || v19 >= this->m_arPanels.m_nSize )
                goto LABEL_14;
              v22 = this->m_arPanels.m_pData[v19];
              if ( v22->m_arWidths.m_nSize - v22->m_nCurrWidthIndex - 1 >= v21 )
              {
                v20 = v19;
                v21 = v22->m_arWidths.m_nSize - v22->m_nCurrWidthIndex - 1;
              }
              ++v19;
            }
            while ( v19 < this->m_arPanels.m_nSize );
            if ( v20 < 0 )
              break;
            if ( v20 >= this->m_arPanels.m_nSize )
              goto LABEL_14;
            v23 = this->m_arPanels.m_pData[v20];
            ++v23->m_nCurrWidthIndex;
          }
          goto LABEL_51;
        }
        v16 = this->m_arPanels.m_pData[v15];
        if ( v12 < m_nSize - 1 )
        {
          if ( bRedrawScrolla < 0 || bRedrawScrolla >= this->m_arCollapseOrder.m_nSize )
            goto LABEL_14;
          if ( m_pData[v12 + 1] == -1 )
            break;
        }
        m_nCurrWidthIndex = v16->m_nCurrWidthIndex;
        if ( m_nCurrWidthIndex < v16->m_arWidths.m_nSize - 1 )
        {
          v17 = m_nCurrWidthIndex + 1;
          goto LABEL_38;
        }
LABEL_39:
        ++v12;
        ++bRedrawScrolla;
        if ( v12 > this->m_arCollapseOrder.m_nSize )
          goto LABEL_40;
      }
      v17 = v16->m_arWidths.m_nSize - 1;
      ++v12;
      ++bRedrawScrolla;
      v16->m_bForceCollpapse = 1;
LABEL_38:
      v16->m_nCurrWidthIndex = v17;
      goto LABEL_39;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E0260
// Name: public: virtual void CMFCRibbonCategory::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnDraw(CMFCRibbonCategory *this, CDC *pDC)
{
  CRect *p_m_rect; // esi
  CMFCVisualManager *Instance; // eax
  HRGN v5; // eax
  int i; // esi
  CMFCRibbonPanel *v7; // ecx
  CGdiObject v8; // [esp+10h] [ebp-30h] BYREF
  int v9; // [esp+18h] [ebp-28h]
  CDC *v10; // [esp+1Ch] [ebp-24h]
  RECT rc; // [esp+20h] [ebp-20h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  p_m_rect = &this->m_rect;
  v10 = pDC;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    Instance = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonCategory *, int, int, int, int))Instance->OnDrawRibbonCategory)(
      a1: Instance,
      a2: v10,
      a3: this,
      a4: p_m_rect->left,
      a5: p_m_rect->top,
      a6: p_m_rect->right,
      a7: p_m_rect->bottom);
    v9 = 0;
    v8.m_hObject = nullptr;
    v8.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    rc.left = this->m_ScrollLeft.m_rect.left;
    rc.top = this->m_ScrollLeft.m_rect.top;
    rc.right = this->m_ScrollLeft.m_rect.right;
    v12 = 0;
    rc.bottom = this->m_ScrollLeft.m_rect.bottom;
    if ( !IsRectEmpty(lprc: &rc) || (rc = (RECT)this->m_ScrollRight.m_rect, !IsRectEmpty(lprc: &rc)) )
    {
      rc = (RECT)this->m_rect;
      rc.left += 2;
      rc.top += 3;
      rc.right -= 2;
      rc.bottom -= 4;
      v5 = CreateRectRgnIndirect(lprect: &rc);
      CGdiObject::Attach(this: &v8, hObject: v5);
      CDC::SelectClipRgn(this: v10, pRgn: (CRgn *)&v8);
      v9 = 1;
    }
    for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
    {
      if ( i < 0 || i >= this->m_arPanels.m_nSize )
        AfxThrowInvalidArgException();
      v7 = this->m_arPanels.m_pData[i];
      v7->DoPaint(this: v7, a2: v10);
    }
    if ( v9 != 0 )
      CDC::SelectClipRgn(this: v10, pRgn: nullptr);
    this->m_ScrollLeft.OnDraw(this: &this->m_ScrollLeft, a2: v10);
    this->m_ScrollRight.OnDraw(this: &this->m_ScrollRight, a2: v10);
    v12 = -1;
    v8.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E03AF
// Name: public: virtual void CMFCRibbonCategory::CopyFrom(class CMFCRibbonCategory __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::CopyFrom(CMFCRibbonCategory *this, CMFCRibbonCategory *src)
{
  int v3; // eax
  CRibbonCategoryScroll_vtbl *v4; // eax
  CMFCRibbonPanel *v5; // edi
  CRuntimeClass *v6; // eax
  CMFCRibbonPanel *pPanel; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strName, strSrc: (ATL::CStringData *)&src->m_strName);
  this->m_bIsActive = src->m_bIsActive;
  this->m_bIsVisible = src->m_bIsVisible;
  v3 = 0;
  i = 0;
  if ( src->m_arPanels.m_nSize > 0 )
  {
    while ( 1 )
    {
      if ( v3 < 0 || v3 >= src->m_arPanels.m_nSize )
        AfxThrowInvalidArgException();
      v5 = src->m_arPanels.m_pData[v3];
      v6 = (CRuntimeClass *)v5->GetRuntimeClass(this: v5);
      pPanel = (CMFCRibbonPanel *)CRuntimeClass::CreateObject(this: v6);
      pPanel->CopyFrom(this: pPanel, a2: v5);
      v5 = (CMFCRibbonPanel *)((char *)v5 + 184);
      pPanel->m_btnDefault.CopyFrom(this: &pPanel->m_btnDefault, a2: (const CMFCRibbonBaseElement *)v5);
      pPanel->m_btnDefault.SetOriginal(this: &pPanel->m_btnDefault, a2: (CMFCRibbonBaseElement *)v5);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arPanels,
        nIndex: this->m_arPanels.m_nSize,
        newElement: (CMFCRibbonKeyTip *)pPanel);
      if ( ++i >= src->m_arPanels.m_nSize )
        break;
      v3 = i;
    }
  }
  this->m_pParentRibbonBar = src->m_pParentRibbonBar;
  this->m_rect = src->m_rect;
  this->m_Tab.CopyFrom(this: &this->m_Tab, a2: &src->m_Tab);
  this->m_dwData = src->m_dwData;
  this->m_uiContextID = src->m_uiContextID;
  this->m_pParentMenuBar = src->m_pParentMenuBar;
  CMFCToolBarImages::CopyTo(this: &src->m_SmallImages, dest: &this->m_SmallImages);
  CMFCToolBarImages::CopyTo(this: &src->m_LargeImages, dest: &this->m_LargeImages);
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arCollapseOrder,
    nNewSize: 0,
    nGrowBy: -1);
  CArray<int,int>::Copy(this: &this->m_arCollapseOrder, src: &src->m_arCollapseOrder);
  this->m_ScrollLeft.CopyFrom(this: &this->m_ScrollLeft, a2: &src->m_ScrollLeft);
  v4 = this->m_ScrollRight.__vftable;
  this->m_ScrollLeft.m_pParent = this;
  ((void (__stdcall *)(CRibbonCategoryScroll *))v4->CopyFrom)(a1: &src->m_ScrollRight);
  this->m_ScrollRight.m_pParent = this;
  this->m_uiSmallImagesResID = src->m_uiSmallImagesResID;
  this->m_uiLargeImagesResID = src->m_uiLargeImagesResID;
}

//------------------------------------------------------------------------------
// Address: 0x103E0545
// Name: public: virtual int CMFCRibbonTab::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonTab::SetACCData(CMFCRibbonTab *this, CWnd *pParent, CAccessibilityData *data)
{
  CAccessibilityData *v4; // esi
  unsigned int v5; // ebx
  int result; // eax
  int v7; // eax
  ATL::CSimpleStringT<char,0> *p_m_strAccDefAction; // ecx
  ATL::CStringData *v9; // eax

  v4 = data;
  v5 = this->m_pParent->m_pParentRibbonBar->m_dwHideFlags & 1;
  result = CMFCRibbonBaseElement::SetACCData(this, pParent, data);
  if ( result != 0 )
  {
    v4->m_bAccState = 3145728;
    if ( v5 != 0 )
    {
      v4->m_bAccState = 1076887552;
      v7 = this->IsDroppedDown(this);
      p_m_strAccDefAction = &v4->m_strAccDefAction;
      if ( v7 != 0 )
      {
        v4->m_bAccState |= 0xAu;
        ATL::CSimpleStringT<char,0>::SetString(this: p_m_strAccDefAction, pszSrc: "Close");
      }
      else
      {
        ATL::CSimpleStringT<char,0>::SetString(this: p_m_strAccDefAction, pszSrc: "Open");
      }
    }
    else
    {
      if ( this->m_pParent->m_bIsActive != 0 )
        v4->m_bAccState = 3145730;
      ATL::CSimpleStringT<char,0>::SetString(this: &v4->m_strAccDefAction, pszSrc: "Switch");
    }
    ATL::CSimpleStringT<char,0>::operator=(
      this: &v4->m_strAccName,
      strSrc: (ATL::CStringData *)&this->m_pParent->m_strName);
    v4->m_nAccRole = 37;
    v9 = (ATL::CStringData *)ATL::operator+(
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&data,
                               psz1: "Alt, ",
                               str2: &this->m_strKeys);
    ATL::CSimpleStringT<char,0>::operator=(this: &v4->m_strAccKeys, strSrc: v9);
    ATL::CStringData::Release(this: (ATL::CStringData *)&data[-1].m_rectAccLocation.right);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E0615
// Name: public: void CMFCRibbonCategory::SetName(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::SetName(CMFCRibbonCategory *this, const char *lpszName)
{
  const char *v3; // eax
  int v4; // edi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  int v7; // ecx
  char *v8; // eax
  const char *v9; // esi

  v3 = lpszName;
  v4 = 0;
  if ( lpszName == nullptr )
    v3 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strName, pszSrc: v3);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&lpszName,
    pStringMgr: StringManager);
  m_pszData = this->m_strName.m_pszData;
  v7 = *((_DWORD *)m_pszData - 3);
  if ( v7 > 0 )
  {
    do
    {
      if ( v4 < 0 || v4 > v7 )
        ATL::AtlThrowImpl(hr: -2147024809);
      if ( m_pszData[v4] == 38 )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Delete(
          this: &this->m_strName,
          iIndex: v4,
          nCount: 1);
        v8 = this->m_strName.m_pszData;
        if ( v4 < *((_DWORD *)v8 - 3) )
          ATL::CSimpleStringT<char,0>::AppendChar(this: (ATL::CSimpleStringT<char,0> *)&lpszName, ch: v8[v4]);
      }
      m_pszData = this->m_strName.m_pszData;
      v7 = *((_DWORD *)m_pszData - 3);
      ++v4;
    }
    while ( v4 < v7 );
  }
  v9 = lpszName;
  this->m_Tab.SetKeys(this: &this->m_Tab, a2: lpszName, a3: nullptr);
  ATL::CStringData::Release(this: (ATL::CStringData *)v9 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103E534F
// Name: public: virtual struct CRuntimeClass __near * CMFCDropDownFrame::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCDropDownFrame::GetRuntimeClass(CMFCDropDownFrame *this)
{
  return &CMFCDropDownFrame::classCMFCDropDownFrame;
}

//------------------------------------------------------------------------------
// Address: 0x103E95BE
// Name: public: virtual int CDockablePane::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::PreTranslateMessage(CDockablePane *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  CToolTipCtrl *m_pToolTip; // eax
  CBaseTabbedPane *ParentTabbedPane; // esi
  int v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  CDockingManager *DockingManager; // eax
  CSmartDockingManager *m_pSDManager; // eax
  HWND v12; // eax
  CWnd *v13; // eax
  HWND Capture; // eax

  message = pMsg->message;
  if ( message > 0x104 )
  {
    if ( message < 0x200 || message > 0x202 && (message <= 0x203 || message > 0x205 && message - 519 > 1) )
      goto LABEL_19;
LABEL_16:
    m_pToolTip = this->m_pToolTip;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
      SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x407u, wParam: 0, lParam: (LPARAM)pMsg);
    goto LABEL_19;
  }
  if ( message == 260
    || message >= 0xA1
    && (message <= 0xA2 || message > 0xA3 && (message <= 0xA5 || message > 0xA6 && (message <= 0xA8 || message == 256))) )
  {
    goto LABEL_16;
  }
LABEL_19:
  if ( pMsg->message == 256 )
  {
    if ( (this->GetDockingMode((CBasePane *)this) & 2) != 0 && this->m_bPrepareToFloat && pMsg->wParam == 27 )
    {
      PostMessageA(hWnd: this->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
      return 1;
    }
    if ( pMsg->message == 256 && this->IsTabbed((CBasePane *)this) != 0 && pMsg->wParam == 27 )
    {
      ParentTabbedPane = CBasePane::GetParentTabbedPane(this: &this->CPane);
      v7 = (int)ParentTabbedPane->GetParentMiniFrame(this: ParentTabbedPane, a2: 0);
      if ( ParentTabbedPane->m_bPrepareToFloat || v7 != 0 && *(_BYTE *)(v7 + 153) != 0 )
      {
        if ( v7 != 0 )
        {
          PostMessageA(hWnd: *(HWND *)(v7 + 32), Msg: 0x1Fu, wParam: 0, lParam: 0);
          return 1;
        }
LABEL_42:
        PostMessageA(hWnd: ParentTabbedPane->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
        return 1;
      }
    }
  }
  if ( pMsg->message == 256 && pMsg->wParam == 27 && (this->GetDockingMode((CBasePane *)this) & 0x80u) != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v9 = CWnd::FromHandle(hWnd: Parent);
    DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v9);
    if ( DockingManager != nullptr )
    {
      m_pSDManager = DockingManager->m_pSDManager;
      if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
      {
        v12 = GetParent(hWnd: this->m_hWnd);
        v13 = CWnd::FromHandle(hWnd: v12);
        ParentTabbedPane = (CBaseTabbedPane *)AfxDynamicDownCast(
                                                pClass: &CPaneFrameWnd::classCPaneFrameWnd,
                                                pObject: v13);
        if ( ParentTabbedPane != nullptr )
        {
          Capture = GetCapture();
          if ( CWnd::FromHandle(hWnd: Capture) == ParentTabbedPane )
            goto LABEL_42;
        }
      }
    }
  }
  return CBasePane::PreTranslateMessage(this: &this->CPane, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103E9792
// Name: public: void CDockablePane::SetDefaultPaneDivider(struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::SetDefaultPaneDivider(CDockablePane *this, HWND__ *hSliderWnd)
{
  CPaneDivider *DefaultPaneDivider; // eax

  if ( this->m_hDefaultSlider != hSliderWnd )
  {
    DefaultPaneDivider = CDockablePane::GetDefaultPaneDivider(this);
    if ( DefaultPaneDivider != nullptr )
      DefaultPaneDivider->RemovePane(this: DefaultPaneDivider, a2: this);
  }
  this->m_hDefaultSlider = hSliderWnd;
}

//------------------------------------------------------------------------------
// Address: 0x103E97C6
// Name: public: virtual enum AFX_CS_STATUS CDockablePane::GetDockingStatus(class CPoint,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::GetDockingStatus(CDockablePane *this, CPoint pt, int nSensitivity)
{
  char v4; // bl
  CWnd *v5; // eax
  CDockingManager *DockingManager; // eax
  CSmartDockingManager *SmartDockingManager; // eax
  int v8; // ebx
  CDockablePane_vtbl *v9; // eax
  int v10; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-4Ch]
  CSmartDockingStandaloneGuide::SDMarkerPlace nHilitedSideNo; // [esp+Ch] [ebp-38h]
  CRect rectTabAreaBottom; // [esp+10h] [ebp-34h] BYREF
  CRect rectTabAreaTop; // [esp+20h] [ebp-24h] BYREF
  CRect rectBar; // [esp+30h] [ebp-14h] BYREF

  v4 = this->GetDockingMode((CBasePane *)this);
  v5 = this->GetDockSiteFrameWnd(this);
  DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v5);
  nHilitedSideNo = sdNONE;
  if ( v4 < 0 && DockingManager != nullptr )
  {
    SmartDockingManager = CDockingManager::GetSmartDockingManager(this: DockingManager);
    if ( SmartDockingManager != nullptr && SmartDockingManager->m_bCreated != 0 && SmartDockingManager->m_bStarted != 0 )
      nHilitedSideNo = SmartDockingManager->m_nHiliteSideNo;
  }
  v8 = ((int (__thiscall *)(CDockablePane *, int, int, int))this->HitTest)(a1: this, a2: pt.x, a3: pt.y, a4: 1);
  v9 = this->__vftable;
  memset(&rectTabAreaTop, 0, sizeof(rectTabAreaTop));
  memset(&rectTabAreaBottom, 0, sizeof(rectTabAreaBottom));
  v9->GetTabArea(this, a2: &rectTabAreaTop, a3: &rectTabAreaBottom);
  if ( v8 == 2
    || PtInRect(lprc: &rectTabAreaTop, pt: pt.tagPOINT)
    || PtInRect(lprc: &rectTabAreaBottom, pt: pt.tagPOINT)
    || nHilitedSideNo == sdCMIDDLE )
  {
    return 3;
  }
  m_hWnd = this->m_hWnd;
  memset(&rectBar, 0, sizeof(rectBar));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
  v10 = this->GetCaptionHeight((CBasePane *)this);
  rectBar.top += v10;
  rectBar.top += rectTabAreaTop.bottom - rectTabAreaTop.top;
  rectBar.bottom += rectTabAreaBottom.top - rectTabAreaBottom.bottom;
  if ( nSensitivity != -1 )
  {
    InflateRect(lprc: &rectBar, dx: -nSensitivity, dy: -nSensitivity);
    if ( !PtInRect(lprc: &rectBar, pt: pt.tagPOINT) )
      return 2;
    return 0;
  }
  if ( !PtInRect(lprc: &rectBar, pt: pt.tagPOINT) )
    return 0;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x103E9929
// Name: protected: void CDockablePane::RemoveCaptionButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::RemoveCaptionButtons(CDockablePane *this)
{
  int i; // edi
  CObject *v3; // ecx

  for ( i = 0; i < this->m_arrButtons.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arrButtons.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arrButtons.m_pData[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CObject *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  CUIntArray::SetSize(this: (CPtrArray *)&this->m_arrButtons, nNewSize: 0, nGrowBy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103E997A
// Name: protected: void CDockablePane::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnSetFocus(CDockablePane *this, CWnd *pOldWnd)
{
  CPaneFrameWnd *v3; // eax
  CObject *v4; // eax

  CWnd::OnSetFocus(this: &this->CPane, __formal: pOldWnd);
  v3 = this->GetParentMiniFrame(this, a2: 0);
  v4 = AfxDynamicDownCast(pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd, pObject: v3);
  if ( v4 != nullptr )
    v4[116].__vftable = (CObject_vtbl *)this->m_hWnd;
}

//------------------------------------------------------------------------------
// Address: 0x103E99B5
// Name: public: virtual int CDockablePane::CanAutoHide(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::CanAutoHide(CDockablePane *this)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  CWnd *v5; // esi
  HWND v6; // eax
  CPaneDivider *DefaultPaneDivider; // edi
  CDockingManager *DockingManager; // eax
  unsigned int m_dwEnabledSlideBars; // esi

  if ( (this->m_dwControlBarStyle & 2) == 0 )
    return 0;
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  if ( CObject::IsKindOf(this: v4, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
  {
    v6 = GetParent(hWnd: v5->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: v6);
  }
  if ( v5 != nullptr
    && (DefaultPaneDivider = CDockablePane::GetDefaultPaneDivider(this),
        (DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v5)) != nullptr)
    && DefaultPaneDivider != nullptr
    && (m_dwEnabledSlideBars = DockingManager->m_dwEnabledSlideBars,
        (DefaultPaneDivider->GetCurrentAlignment(this: DefaultPaneDivider) & m_dwEnabledSlideBars) != 0) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E9A3C
// Name: protected: long CDockablePane::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::OnUpdateToolTips(CDockablePane *this, char wp, int __formal)
{
  CToolTipCtrl **p_m_pToolTip; // esi
  signed int i; // edi
  CRect rectDummy; // [esp+4h] [ebp-14h] BYREF

  if ( (wp & 0x10) != 0 )
  {
    p_m_pToolTip = &this->m_pToolTip;
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: &this->CPane, nType: 0x10u);
    for ( i = 0;
          i < 3;
          CToolTipCtrl::AddTool(
            this: *p_m_pToolTip,
            pWnd: &this->CPane,
            lpszText: (const char *)0xFFFFFFFF,
            lpRectTool: &rectDummy,
            nIDTool: i) )
    {
      memset(&rectDummy, 0, sizeof(rectDummy));
      SetRectEmpty(lprc: &rectDummy);
      ++i;
    }
    CDockablePane::UpdateTooltips(this);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E9AB1
// Name: public: static class CObject __near * CDockablePane::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__stdcall CDockablePane::CreateObject()
{
  CDockablePane *v0; // ecx
  CDockablePane *result; // eax

  v0 = (CDockablePane *)operator new(nSize: 0x350u);
  result = nullptr;
  if ( v0 != nullptr )
    return CDockablePane::CDockablePane(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E9AE1
// Name: public: void CDockablePane::RemoveFromDefaultPaneDividier(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::RemoveFromDefaultPaneDividier(CDockablePane *this)
{
  if ( this->m_hDefaultSlider != nullptr )
    CDockablePane::SetDefaultPaneDivider(this, hSliderWnd: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103E9AF2
// Name: protected: void CDockablePane::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnLButtonDown(CDockablePane *this, WPARAM nFlags, CPoint point)
{
  CMFCCaptionButton *ButtonByHit; // edi
  HWND Window; // eax
  CWnd *v6; // eax
  int v7; // ebx
  HWND v8; // eax
  CWnd *pWndFirstChild; // [esp+8h] [ebp-4h]

  if ( this->m_nHot != 0 )
  {
    ButtonByHit = CDockablePane::FindButtonByHit(this, nHit: this->m_nHot);
    if ( ButtonByHit != nullptr )
    {
      CWnd::SetFocus(this: &this->CPane);
      this->m_nHit = this->m_nHot;
      ButtonByHit->m_bPushed = 1;
      CDockablePane::RedrawButton(this, pButton: ButtonByHit);
      return;
    }
  }
  else
  {
    Window = GetWindow(hWnd: this->m_hWnd, uCmd: 5u);
    v6 = CWnd::FromHandle(hWnd: Window);
    v7 = 0;
    if ( v6 != nullptr )
    {
      do
      {
        pWndFirstChild = v6;
        v8 = GetWindow(hWnd: v6->m_hWnd, uCmd: 2u);
        v6 = CWnd::FromHandle(hWnd: v8);
        ++v7;
      }
      while ( v6 != nullptr );
      if ( v7 == 1 )
        CWnd::SetFocus(this: pWndFirstChild);
    }
  }
  if ( this->IsAutoHideMode((CBasePane *)this) == 0 && this->IsTabbed((CBasePane *)this) == 0 )
  {
    if ( this->CanFloat((CBasePane *)this) != 0 )
      this->m_bPrepareToFloat = true;
    CPane::OnLButtonDown(this: &this->CPane, nFlags, point);
  }
  CWnd::SetFocus(this: &this->CPane);
}

//------------------------------------------------------------------------------
// Address: 0x103E9BC5
// Name: protected: void CDockablePane::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnLButtonUp(CDockablePane *this, WPARAM nFlags, CPoint point)
{
  CWnd *v4; // eax
  unsigned int m_nHit; // edi
  CFrameWnd *TopLevelFrame; // edi
  CObject *v7; // eax
  int v8; // eax
  CObject *v9; // eax
  CObject *v10; // eax
  CObList::CNode *m_pNodeHead; // eax
  HWND v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  CDockSite *v16; // eax
  CAutoHideDockSite *v17; // eax
  CObject *v18; // eax
  int v19; // edi
  CDockablePane_vtbl *v20; // edi
  int v21; // eax
  CMFCCaptionButton *ButtonByHit; // eax
  const CMFCCaptionButton *v23; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  CObject *data; // [esp-4h] [ebp-70h]
  CObList lstBars; // [esp+10h] [ebp-5Ch] BYREF
  CPaneDivider *DefaultPaneDivider; // [esp+2Ch] [ebp-40h]
  int left; // [esp+30h] [ebp-3Ch]
  unsigned int m_nHot; // [esp+34h] [ebp-38h]
  HWND hWnd; // [esp+38h] [ebp-34h]
  tagRECT rc; // [esp+3Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+4Ch] [ebp-20h] BYREF
  int v33; // [esp+68h] [ebp-4h]

  if ( this->m_bPrepareToFloat )
    this->m_bPrepareToFloat = false;
  if ( this->m_nHit != 0 )
  {
    v4 = this->GetDockSiteFrameWnd(this);
    hWnd = (HWND)CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v4);
    if ( hWnd == nullptr && afxGlobalUtils.m_bDialogApp == 0 )
      goto LABEL_6;
    m_nHit = this->m_nHit;
    m_nHot = this->m_nHot;
    this->StopCaptionButtonsTracking(this);
    DefaultPaneDivider = CDockablePane::GetDefaultPaneDivider(this);
    if ( m_nHot != m_nHit )
      goto LABEL_12;
    switch ( m_nHit )
    {
      case 8u:
        if ( CDockingManager::m_bDockBarMenu != 0 )
        {
          ButtonByHit = CDockablePane::FindButtonByHit(this, nHit: 8u);
          v23 = ButtonByHit;
          if ( ButtonByHit != nullptr )
          {
            ButtonByHit->GetRect(this: ButtonByHit, result: (CRect *)&rc);
            m_hWnd = this->m_hWnd;
            memset(&Rect, 0, sizeof(Rect));
            GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
            CWnd::ScreenToClient(this: &this->CPane, lpRect: &Rect);
            OffsetRect(lprc: &rc, dx: Rect.left, dy: Rect.top);
            CWnd::ClientToScreen(this: &this->CPane, lpRect: &rc);
            v23->m_bDroppedDown = 1;
            left = rc.left;
            m_nHot = rc.bottom + 1;
            if ( (CWnd::GetExStyle(this: &this->CPane) & 0x400000) != 0 )
              left += rc.right - rc.left;
            hWnd = this->m_hWnd;
            ((void (__thiscall *)(CDockablePane *, int, unsigned int))this->OnShowControlBarMenu)(
              a1: this,
              a2: left,
              a3: m_nHot);
            if ( IsWindow(hWnd) )
            {
              v23->m_bDroppedDown = 0;
              CDockablePane::RedrawButton(this, pButton: v23);
            }
          }
        }
        break;
      case 9u:
        if ( GetAsyncKeyState(vKey: 17) != 0 && this->IsAutohideAllEnabled(this) != 0 )
        {
          SendMessageA(hWnd: this->m_pDockSite->CPane::CBasePane::m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
          if ( this->m_bPinState != 0 )
          {
            v16 = this->m_pAutoHideBar->GetParentDockSite(this: this->m_pAutoHideBar);
            v17 = (CAutoHideDockSite *)AfxDynamicDownCast(
                                         pClass: &CAutoHideDockSite::classCAutoHideDockSite,
                                         pObject: v16);
            if ( v17 != nullptr )
              CAutoHideDockSite::UnSetAutoHideMode(this: v17, pAutohideToolbar: nullptr);
          }
          else
          {
            CObList::CObList(this: &lstBars, nBlockSize: 10);
            v33 = 0;
            CPaneDivider::GetPanes(this: DefaultPaneDivider, &lstBars);
            m_pNodeHead = lstBars.m_pNodeHead;
            if ( lstBars.m_pNodeHead != nullptr )
            {
              while ( m_pNodeHead != nullptr )
              {
                data = m_pNodeHead->data;
                m_nHot = (unsigned int)m_pNodeHead->pNext;
                v12 = (HWND)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: data);
                v13 = *(_DWORD *)v12;
                hWnd = v12;
                if ( (*(int (__thiscall **)(HWND))(v13 + 832))(a1: v12) != 0 )
                {
                  v14 = *(_DWORD *)v12;
                  v15 = ((int (__thiscall *)(CPaneDivider *, _DWORD, _DWORD))DefaultPaneDivider->GetCurrentAlignment)(
                          a1: DefaultPaneDivider,
                          a2: 0,
                          a3: 0);
                  (*(void (__thiscall **)(HWND, int, int))(v14 + 872))(a1: hWnd, a2: 1, a3: v15);
                }
                if ( m_nHot == 0 )
                  goto LABEL_34;
                m_pNodeHead = (CObList::CNode *)m_nHot;
              }
LABEL_6:
              AfxThrowInvalidArgException();
            }
LABEL_34:
            v33 = -1;
            CObList::~CObList(this: &lstBars);
          }
          SendMessageA(hWnd: this->m_pDockSite->CPane::CBasePane::m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
          v18 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: this->m_pDockSite);
          if ( v18 != nullptr )
            ((void (__thiscall *)(CObject *, int))v18->__vftable[31].GetRuntimeClass)(a1: v18, a2: 1);
          RedrawWindow(
            hWnd: this->m_pDockSite->CPane::CBasePane::m_hWnd,
            lprcUpdate: nullptr,
            hrgnUpdate: nullptr,
            flags: 0x181u);
        }
        else if ( hWnd != nullptr && DefaultPaneDivider != nullptr )
        {
          v19 = *((_DWORD *)hWnd + 71);
          if ( (DefaultPaneDivider->GetCurrentAlignment(this: DefaultPaneDivider) & v19) != 0 )
          {
            v20 = this->__vftable;
            v21 = ((int (__thiscall *)(CPaneDivider *, _DWORD, int))DefaultPaneDivider->GetCurrentAlignment)(
                    a1: DefaultPaneDivider,
                    a2: 0,
                    a3: 1);
            ((void (__thiscall *)(CDockablePane *, bool, int))v20->SetAutoHideMode)(
              a1: this,
              a2: this->m_bPinState == 0,
              a3: v21);
          }
        }
        break;
      case 0x13u:
        TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
        if ( g_pTopLevelFrame != nullptr || (TopLevelFrame = CWnd::GetTopLevelFrame(this: &this->CPane)) != nullptr )
        {
          v7 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
          if ( v7 != nullptr )
          {
            v8 = ((int (__thiscall *)(CObject *, CDockablePane *))v7->__vftable[44].GetRuntimeClass)(a1: v7, a2: this);
          }
          else
          {
            v9 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: TopLevelFrame);
            if ( v9 != nullptr )
            {
              v8 = ((int (__thiscall *)(CObject *, CDockablePane *))v9->__vftable[41].dtr_CObject)(a1: v9, a2: this);
            }
            else
            {
              v10 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: TopLevelFrame);
              if ( v10 == nullptr )
              {
                v10 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject: TopLevelFrame);
                if ( v10 == nullptr )
                  goto LABEL_23;
              }
              v8 = ((int (__thiscall *)(CObject *, CDockablePane *))v10->__vftable[43].dtr_CObject)(a1: v10, a2: this);
            }
          }
          if ( v8 == 0 )
            goto LABEL_12;
        }
LABEL_23:
        this->OnPressCloseButton((CPane *)this);
        goto LABEL_12;
      default:
        this->OnPressButtons(this, a2: m_nHit);
LABEL_12:
        CWnd::Default(this: &this->CPane);
        return;
    }
  }
  else
  {
    CPane::OnLButtonUp(this: &this->CPane, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E9F6F
// Name: public: virtual void CDockablePane::UnSetAutoHideMode(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::UnSetAutoHideMode(CDockablePane *this, CDockablePane *pFirstBarInGroup)
{
  UINT_PTR m_nAutoHideConditionTimerID; // eax
  CMFCAutoHideBar *m_pAutoHideBar; // ecx
  int m_bActiveInGroup; // edi
  CDockablePane_vtbl *v6; // eax

  m_nAutoHideConditionTimerID = this->m_nAutoHideConditionTimerID;
  this->m_bPinState = 0;
  if ( m_nAutoHideConditionTimerID != 0 )
    KillTimer(hWnd: this->m_hWnd, uIDEvent: m_nAutoHideConditionTimerID);
  if ( this->m_nSlideTimer != 0 )
    KillTimer(hWnd: this->m_hWnd, uIDEvent: this->m_nSlideTimer);
  m_pAutoHideBar = this->m_pAutoHideBar;
  m_bActiveInGroup = m_pAutoHideBar->m_bActiveInGroup;
  CMFCAutoHideBar::RemoveAutoHideWindow(this: m_pAutoHideBar, pAutoHideWnd: this);
  CDockablePane::RemoveFromDefaultPaneDividier(this);
  v6 = this->__vftable;
  if ( pFirstBarInGroup != nullptr )
  {
    v6->AttachToTabWnd(this, a2: pFirstBarInGroup, a3: DM_SHOW, a4: m_bActiveInGroup, a5: nullptr);
  }
  else if ( v6->DockPane(this: &this->CPane, a2: &this->CPane, a3: nullptr, a4: DM_DBL_CLICK) == 0 )
  {
    return;
  }
  this->ShowPane((CBasePane *)this, a2: 1, a3: 0, a4: m_bActiveInGroup);
  this->AdjustDockingLayout((CBasePane *)this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103EA006
// Name: protected: virtual void CDockablePane::OnSlide(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnSlide(CDockablePane *this, int bSlideDirection)
{
  CWnd *v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  CWnd *v6; // eax
  CWnd *v7; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-40h]
  HWND__ *m_hDefaultSlider; // [esp-8h] [ebp-40h]
  CPoint pt; // [esp+Ch] [ebp-2Ch] BYREF
  CRect rectSlider; // [esp+14h] [ebp-24h] BYREF
  CRect rect; // [esp+24h] [ebp-14h] BYREF

  if ( this->IsAutoHideMode((CBasePane *)this) != 0 || IsWindow(hWnd: this->m_hDefaultSlider) )
  {
    v3 = this->GetDockSiteFrameWnd(this);
    v4 = CWnd::GetExStyle(this: v3);
    m_hWnd = this->m_hWnd;
    v5 = v4 & 0x400000;
    ++this->m_nSlideStep;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
    v6 = this->GetDockSiteFrameWnd(this);
    CWnd::ScreenToClient(this: v6, lpRect: &rect);
    m_hDefaultSlider = this->m_hDefaultSlider;
    memset(&rectSlider, 0, sizeof(rectSlider));
    GetWindowRect(hWnd: m_hDefaultSlider, lpRect: &rectSlider);
    v7 = this->GetDockSiteFrameWnd(this);
    CWnd::ScreenToClient(this: v7, lpRect: &rectSlider);
    if ( this->m_ahSlideMode == 1 )
    {
      CDockablePane::OffsetRectForSliding(this, &rect, bSlideDirection, bIsRTL: v5);
      CDockablePane::OffsetRectForSliding(this, rect: &rectSlider, bSlideDirection, bIsRTL: v5);
      if ( bSlideDirection != 0 )
      {
        CDockablePane::CalcCorrectOffset(this, result: &pt, rect, bIsRTL: v5);
        OffsetRect(lprc: &rect, dx: pt.x, dy: pt.y);
        OffsetRect(lprc: &rectSlider, dx: pt.x, dy: pt.y);
      }
    }
    else
    {
      CDockablePane::CalcRectForSliding(this, &rect, &rectSlider, bSlideDirection);
    }
    this->SetWindowPos(
      (CBasePane *)this,
      a2: nullptr,
      a3: rect.left,
      a4: rect.top,
      a5: rect.right - rect.left,
      a6: rect.bottom - rect.top,
      a7: 20u,
      a8: nullptr);
    SetWindowPos(
      hWnd: this->m_hDefaultSlider,
      hWndInsertAfter: nullptr,
      X: rectSlider.left,
      Y: rectSlider.top,
      cx: rectSlider.right - rectSlider.left,
      cy: rectSlider.bottom - rectSlider.top,
      uFlags: 0x14u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EA189
// Name: protected: void CDockablePane::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnLButtonDblClk(CDockablePane *this, unsigned int nFlags, CPoint point)
{
  CMFCCaptionButton *Button; // eax
  CDockablePane *v5; // ecx
  int v6; // eax
  CDockablePane_vtbl *v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  CObject *v10; // eax
  HWND v11; // eax
  CWnd *v12; // eax
  CPaneFrameWnd *v13; // eax
  CObject *v14; // ebx
  CWnd *v15; // eax
  CWnd *v16; // edi
  HWND__ *m_hWnd; // ebx
  CPoint ptScreen; // [esp+Ch] [ebp-Ch] BYREF
  CDockablePane *pBarToDock; // [esp+14h] [ebp-4h]
  int bCanFocus; // [esp+20h] [ebp+8h]

  ptScreen = point;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &ptScreen);
  Button = CDockablePane::FindButton(this, point: ptScreen);
  v5 = this;
  if ( Button != nullptr || (v6 = this->IsAutoHideMode((CBasePane *)this), v5 = this, v6 != 0) )
  {
    CWnd::Default(this: &v5->CPane);
  }
  else
  {
    v7 = this->__vftable;
    pBarToDock = this;
    if ( v7->IsTabbed(this: &this->CPane) != 0 )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      v9 = CWnd::FromHandle(hWnd: Parent);
      v10 = AfxDynamicDownCast(pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl, pObject: v9);
      if ( v10 != nullptr )
      {
        v11 = GetParent(hWnd: (HWND)v10[8].__vftable);
        v12 = CWnd::FromHandle(hWnd: v11);
        pBarToDock = (CDockablePane *)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: v12);
      }
    }
    v13 = this->GetParentMiniFrame(this, a2: 0);
    v14 = AfxDynamicDownCast(pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd, pObject: v13);
    if ( v14 != nullptr )
    {
      this->OnProcessDblClk((CPane *)this);
      ((void (__thiscall *)(CObject *, CDockablePane *))v14->__vftable[49].dtr_CObject)(a1: v14, a2: pBarToDock);
    }
    else if ( IsWindow(hWnd: this->m_hDefaultSlider) )
    {
      v15 = CWnd::FromHandlePermanent(hWnd: this->m_recentDockInfo.m_hRecentMiniFrame);
      v16 = (CWnd *)AfxDynamicDownCast(pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd, pObject: v15);
      if ( v16 != nullptr
        && (CRecentDockSiteInfo::GetRecentPaneContainer(this: &this->m_recentDockInfo, bForSlider: 0) != nullptr
         || CRecentDockSiteInfo::GetRecentTabContainer(this: &this->m_recentDockInfo, bForSlider: 0) != nullptr) )
      {
        this->OnBeforeFloat((CPane *)this, a2: &this->m_recentDockInfo.m_rectRecentFloatingRect, a3: DM_DBL_CLICK);
        this->OnProcessDblClk((CPane *)this);
        this->UndockPane((CBasePane *)this, a2: 0);
        m_hWnd = this->m_hWnd;
        bCanFocus = this->CanFocus((CBasePane *)this);
        v16->__vftable[1].SetProxy(this: v16, a2: (IAccessibleProxy *)pBarToDock);
        if ( IsWindow(hWnd: m_hWnd) )
          this->OnAfterFloat((CPane *)this);
        if ( bCanFocus != 0 )
          CWnd::SetFocus(this: v16);
      }
      else
      {
        CPane::OnLButtonDblClk(this: &this->CPane, nFlags, point);
      }
    }
    else
    {
      this->OnProcessDblClk((CPane *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EA347
// Name: public: virtual class CDockablePane __near * CDockablePane::AttachToTabWnd(class CDockablePane __near *,enum AFX_DOCK_METHOD,int,class CDockablePane __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseTabbedPane *__thiscall CDockablePane::AttachToTabWnd(
        CDockablePane *this,
        CDockablePane *pTabControlBarAttachTo,
        AFX_DOCK_METHOD dockMethod,
        int bSetActive,
        CDockablePane **ppTabbedControlBar)
{
  BOOL v6; // ebx
  HWND Parent; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  CWnd *v11; // eax
  CBaseTabbedPane *result; // eax
  CBaseTabbedPane_vtbl *v13; // ebx
  unsigned int v14; // eax
  CBaseTabbedPane_vtbl *v15; // ebx
  unsigned int v16; // eax
  int v17; // ebx
  CWnd *pOldParent; // [esp+Ch] [ebp-24h]
  CWnd *pTabParent; // [esp+14h] [ebp-1Ch]
  CBaseTabbedPane *pTabbedBarAttachTo; // [esp+18h] [ebp-18h] BYREF
  CRect rectWndTab; // [esp+1Ch] [ebp-14h] BYREF

  if ( ppTabbedControlBar != nullptr )
    *ppTabbedControlBar = nullptr;
  if ( pTabControlBarAttachTo->CanBeAttached(this: (CBasePane *)pTabControlBarAttachTo) == 0
    || this->CanBeAttached((CBasePane *)this) == 0 )
  {
    return nullptr;
  }
  pTabbedBarAttachTo = (CBaseTabbedPane *)AfxDynamicDownCast(
                                            pClass: &CBaseTabbedPane::classCBaseTabbedPane,
                                            pObject: &pTabControlBarAttachTo->CPane);
  v6 = pTabControlBarAttachTo->GetParentMiniFrame(this: pTabControlBarAttachTo, a2: 0) != nullptr;
  Parent = GetParent(hWnd: this->m_hWnd);
  pOldParent = CWnd::FromHandle(hWnd: Parent);
  memset(&rectWndTab, 0, sizeof(rectWndTab));
  SetRectEmpty(lprc: &rectWndTab);
  if ( pTabbedBarAttachTo == nullptr )
  {
    v8 = GetParent(hWnd: pTabControlBarAttachTo->m_hWnd);
    pTabParent = CWnd::FromHandle(hWnd: v8);
    if ( AfxDynamicDownCast(pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl, pObject: pTabParent) != nullptr )
    {
      v9 = GetParent(hWnd: pTabParent->m_hWnd);
      pTabParent = CWnd::FromHandle(hWnd: v9);
    }
    pTabbedBarAttachTo = (CBaseTabbedPane *)AfxDynamicDownCast(
                                              pClass: &CBaseTabbedPane::classCBaseTabbedPane,
                                              pObject: pTabParent);
    if ( pTabbedBarAttachTo == nullptr )
    {
      pTabControlBarAttachTo->StoreRecentDockSiteInfo(this: (CPane *)pTabControlBarAttachTo);
      GetWindowRect(hWnd: pTabControlBarAttachTo->m_hWnd, lpRect: &rectWndTab);
      v10 = GetParent(hWnd: pTabControlBarAttachTo->m_hWnd);
      v11 = CWnd::FromHandle(hWnd: v10);
      CWnd::ScreenToClient(this: v11, lpRect: &rectWndTab);
      pTabbedBarAttachTo = pTabControlBarAttachTo->CreateTabbedPane(this: pTabControlBarAttachTo);
      CBasePane::InsertPane(
        this: &pTabControlBarAttachTo->CPane,
        pControlBar: pTabbedBarAttachTo,
        pTarget: &pTabControlBarAttachTo->CPane,
        bAfter: 1);
      if ( CDockablePane::ReplacePane(
             this: pTabControlBarAttachTo,
             pBarToReplaceWith: pTabbedBarAttachTo,
             __formal: dockMethod,
             bRegisterWithFrame: 0) == 0 )
      {
        if ( !v6 )
          CBasePane::RemovePaneFromDockManager(
            this: &this->CPane,
            pBar: pTabbedBarAttachTo,
            bDestroy: 1,
            bAdjustLayout: 0,
            bAutoHide: 0,
            pBarReplacement: nullptr);
        if ( pTabbedBarAttachTo != nullptr )
          ((void (__thiscall *)(CBaseTabbedPane *, int))pTabbedBarAttachTo->dtr_CObject)(a1: pTabbedBarAttachTo, a2: 1);
        return nullptr;
      }
      v13 = pTabbedBarAttachTo->__vftable;
      v14 = pTabControlBarAttachTo->GetEnabledAlignment(this: (CBasePane *)pTabControlBarAttachTo);
      v13->EnableDocking(this: pTabbedBarAttachTo, a2: v14);
      v15 = pTabbedBarAttachTo->__vftable;
      v16 = pTabControlBarAttachTo->GetCurrentAlignment(this: (CBasePane *)pTabControlBarAttachTo);
      v15->SetPaneAlignment(this: pTabbedBarAttachTo, a2: v16);
      pTabControlBarAttachTo->UndockPane(this: (CBasePane *)pTabControlBarAttachTo, a2: 1);
      pTabbedBarAttachTo->AddTab(
        this: pTabbedBarAttachTo,
        a2: (CWnd *)pTabControlBarAttachTo,
        a3: 1,
        a4: bSetActive,
        a5: 1);
      pTabControlBarAttachTo->EnableGripper(this: (CBasePane *)pTabControlBarAttachTo, a2: 0);
    }
  }
  if ( ppTabbedControlBar != nullptr )
    *ppTabbedControlBar = pTabbedBarAttachTo;
  this->EnableGripper((CBasePane *)this, a2: 0);
  this->OnBeforeDock((CPane *)this, a2: &pTabbedBarAttachTo, a3: nullptr, a4: dockMethod);
  this->OnBeforeChangeParent((CBasePane *)this, a2: pTabbedBarAttachTo, a3: 1);
  this->RemoveFromMiniframe((CPane *)this, a2: pTabbedBarAttachTo, a3: dockMethod);
  v17 = pTabbedBarAttachTo->AddTab(this: pTabbedBarAttachTo, a2: (CWnd *)this, a3: 1, a4: bSetActive, a5: 1);
  if ( v17 != 0 )
  {
    this->OnAfterChangeParent((CBasePane *)this, a2: pOldParent);
    this->OnAfterDock((CPane *)this, a2: pTabbedBarAttachTo, a3: nullptr, a4: dockMethod);
  }
  if ( !IsRectEmpty(lprc: &rectWndTab) )
  {
    pTabbedBarAttachTo->SetWindowPos(
      this: pTabbedBarAttachTo,
      a2: nullptr,
      a3: rectWndTab.left,
      a4: rectWndTab.top,
      a5: rectWndTab.right - rectWndTab.left,
      a6: rectWndTab.bottom - rectWndTab.top,
      a7: 20u,
      a8: nullptr);
    if ( v17 != 0 )
      this->AdjustDockingLayout((CBasePane *)this, a2: nullptr);
  }
  pTabbedBarAttachTo->RecalcLayout(this: pTabbedBarAttachTo);
  result = (CBaseTabbedPane *)this;
  if ( v17 == 0 )
    return pTabbedBarAttachTo;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EA608
// Name: protected: virtual int CDockablePane::Dock(class CBasePane __near *,struct tagRECT const __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::Dock(
        CDockablePane *this,
        CDockablePane *pTargetBar,
        CRect *lpRect,
        AFX_DOCK_METHOD dockMethod)
{
  CFrameWnd *v5; // eax
  CDockablePane *v6; // edi
  AFX_DOCK_METHOD v8; // eax
  CDockablePane_vtbl *v9; // edi
  CFrameWnd *v10; // eax
  CPaneDivider *RecentDefaultPaneDivider; // eax
  CPaneDivider *v12; // edi
  IUnknown *m_pOuterUnknown; // eax
  CDockablePane *v14; // eax
  BOOL v15; // edi
  CDockablePane *v16; // eax
  CRect *p_m_rectDockedRect; // eax
  AFX_DOCK_METHOD v18; // [esp-4h] [ebp-24h]
  CPoint ptMouse; // [esp+Ch] [ebp-14h] BYREF
  CPoint ptMouseCur; // [esp+14h] [ebp-Ch] BYREF
  unsigned int dwAlignment; // [esp+1Ch] [ebp-4h] BYREF

  v5 = AFXGetParentFrame(pWnd: this);
  AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v5);
  v6 = pTargetBar;
  if ( pTargetBar != nullptr && pTargetBar->CanAcceptPane(this: (CBasePane *)pTargetBar, a2: this) == 0 && v6 != this )
    return 0;
  v8 = dockMethod;
  if ( dockMethod == DM_RECT && lpRect == nullptr )
    return 0;
  this->m_bPrepareToFloat = false;
  if ( v8 == DM_DBL_CLICK || v8 == DM_SHOW )
  {
    pTargetBar = (CDockablePane *)CRecentDockSiteInfo::GetRecentTabContainer(
                                    this: &this->m_recentDockInfo,
                                    bForSlider: 1);
    CWnd::ShowWindow(this: &this->CPane, nCmdShow: 0);
    v18 = dockMethod;
    v9 = this->__vftable;
    v10 = AFXGetParentFrame(pWnd: this);
    v9->RemoveFromMiniframe(this: &this->CPane, a2: v10, a3: v18);
    this->SetPaneAlignment((CBasePane *)this, a2: this->m_recentDockInfo.m_dwRecentAlignmentToFrame);
    RecentDefaultPaneDivider = CRecentDockSiteInfo::GetRecentDefaultPaneDivider(this: &this->m_recentDockInfo);
    v12 = RecentDefaultPaneDivider;
    if ( RecentDefaultPaneDivider != nullptr )
      CDockablePane::SetDefaultPaneDivider(this, hSliderWnd: RecentDefaultPaneDivider->m_hWnd);
    if ( pTargetBar != nullptr
      && (CRecentDockSiteInfo::IsRecentLeftPane(this: &this->m_recentDockInfo, bForSlider: 1) == 0
        ? (m_pOuterUnknown = pTargetBar->m_pOuterUnknown)
        : (m_pOuterUnknown = (IUnknown *)pTargetBar->m_dwRef),
          m_pOuterUnknown != nullptr) )
    {
      v14 = this->AttachToTabWnd(this, a2: m_pOuterUnknown, a3: 2, a4: 1, a5: 0);
      v15 = v14 != nullptr;
      if ( v14 != nullptr )
        this->ShowPane((CBasePane *)this, a2: 1, a3: 0, a4: 1);
    }
    else
    {
      if ( v12 == nullptr )
      {
        CWnd::ShowWindow(this: &this->CPane, nCmdShow: 5);
        p_m_rectDockedRect = lpRect;
        if ( lpRect == nullptr )
          p_m_rectDockedRect = &this->m_recentDockInfo.m_recentSliderInfo.m_rectDockedRect;
        return this->DockToFrameWindow(
                 (CBasePane *)this,
                 a2: this->m_recentDockInfo.m_dwRecentAlignmentToFrame,
                 a3: p_m_rectDockedRect,
                 a4: 1u,
                 a5: nullptr,
                 a6: -1,
                 a7: 0);
      }
      this->EnableGripper((CBasePane *)this, a2: 1);
      this->AdjustPaneToPaneContainer(this, a2: v12);
      CBasePane::InsertPane(this: &this->CPane, pControlBar: &this->CPane, pTarget: v12, bAfter: 0);
      CWnd::ShowWindow(this: &this->CPane, nCmdShow: 5);
      v16 = v12->AddRecentPane(this: v12, a2: this);
      if ( v16 != this )
      {
        if ( v16 != nullptr )
          v16->AdjustDockingLayout(this: &v16->CPane, a2: nullptr);
        return 0;
      }
      v15 = true;
    }
    this->AdjustDockingLayout((CBasePane *)this, a2: nullptr);
    return v15;
  }
  ptMouse.x = 0;
  ptMouse.y = 0;
  if ( v8 == DM_MOUSE || v8 == DM_STANDARD )
  {
    GetCursorPos(lpPoint: &ptMouse);
    v8 = dockMethod;
  }
  dwAlignment = 0;
  if ( pTargetBar == nullptr )
  {
    pTargetBar = nullptr;
    if ( v8 == DM_MOUSE || v8 == DM_STANDARD )
    {
      ptMouseCur = 0;
      GetCursorPos(lpPoint: &ptMouseCur);
      if ( CBasePane::IsPointNearDockSite(
             this: &this->CPane,
             point: ptMouseCur,
             dwBarAlignment: &dwAlignment,
             bOuterEdge: (int *)&pTargetBar) != 0 )
        return this->DockToFrameWindow(
                 (CBasePane *)this,
                 a2: dwAlignment,
                 a3: nullptr,
                 a4: 1u,
                 a5: nullptr,
                 a6: -1,
                 a7: (int)pTargetBar);
    }
    return 0;
  }
  if ( v8 == DM_MOUSE || v8 == DM_STANDARD )
  {
    if ( CGlobalUtils::CheckAlignment(
           this: &afxGlobalUtils,
           point: ptMouse,
           pBar: &pTargetBar->CPane,
           nSensitivity: CDockingManager::m_nDockSensitivity,
           pDockManager: nullptr,
           bOuterEdge: 0,
           &dwAlignment,
           dwEnabledDockBars: 0xF000u,
           lpRectBounds: nullptr) == 0 )
      return 0;
    return this->DockToWindow(this, a2: pTargetBar, a3: dwAlignment, a4: nullptr);
  }
  else
  {
    if ( lpRect == nullptr )
      return 0;
    return this->DockToWindow(this, a2: pTargetBar, a3: 0, a4: lpRect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EA889
// Name: public: virtual int CDockablePane::DockPaneContainer(class CPaneContainerManager __near &,unsigned long,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::DockPaneContainer(
        CDockablePane *this,
        CPaneContainerManager *barContainerManager,
        unsigned int dwAlignment,
        AFX_DOCK_METHOD __formal)
{
  CObList::CNode *m_pNodeHead; // ebx
  CDockablePane *v6; // esi
  CDockablePane_vtbl *v7; // esi
  unsigned int v8; // eax
  CPaneDivider *DefaultPaneDivider; // eax
  int v10; // eax
  int v11; // esi
  CObject *data; // [esp-4h] [ebp-40h]
  CObList lstControlBars; // [esp+10h] [ebp-2Ch] BYREF
  CDockablePane *pBar; // [esp+2Ch] [ebp-10h]
  int v16; // [esp+38h] [ebp-4h]

  if ( this->m_hDefaultSlider != nullptr && IsWindow(hWnd: this->m_hDefaultSlider) )
  {
    CObList::CObList(this: &lstControlBars, nBlockSize: 10);
    v16 = 0;
    CPaneContainerManager::AddPanesToList(
      this: barContainerManager,
      plstControlBars: &lstControlBars,
      plstSliders: nullptr);
    m_pNodeHead = lstControlBars.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v6 = (CDockablePane *)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: data);
      pBar = v6;
      CBasePane::InsertPane(this: &this->CPane, pControlBar: &v6->CPane, pTarget: &this->CPane, bAfter: 1);
      CDockablePane::SetDefaultPaneDivider(this: v6, hSliderWnd: this->m_hDefaultSlider);
      v7 = v6->__vftable;
      v8 = this->GetCurrentAlignment((CBasePane *)this);
      v7->SetPaneAlignment(this: &pBar->CPane, a2: v8);
    }
    DefaultPaneDivider = CDockablePane::GetDefaultPaneDivider(this);
    if ( DefaultPaneDivider != nullptr )
    {
      v10 = DefaultPaneDivider->AddPaneContainer(
              this: DefaultPaneDivider,
              a2: this,
              a3: barContainerManager,
              a4: dwAlignment);
      v16 = -1;
      v11 = v10;
      CObList::~CObList(this: &lstControlBars);
      return v11;
    }
    v16 = -1;
    CObList::~CObList(this: &lstControlBars);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103EA96C
// Name: public: virtual void CDockablePane::UndockPane(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::UndockPane(CDockablePane *this, int bDelay)
{
  CPaneFrameWnd *v3; // eax
  CObject *v4; // eax

  v3 = this->GetParentMiniFrame(this, a2: 0);
  v4 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: v3);
  if ( v4 != nullptr )
  {
    ((void (__thiscall *)(CObject *, CDockablePane *, _DWORD, _DWORD))v4->__vftable[31].dtr_CObject)(
      a1: v4,
      a2: this,
      a3: 0,
      a4: 0);
  }
  else
  {
    CDockablePane::RemoveFromDefaultPaneDividier(this);
    CBasePane::RemovePaneFromDockManager(
      this: &this->CPane,
      pBar: &this->CPane,
      bDestroy: 0,
      bAdjustLayout: bDelay == 0,
      bAutoHide: 0,
      pBarReplacement: nullptr);
    if ( bDelay == 0 && this->IsFloating((CBasePane *)this) == 0 )
      this->AdjustDockingLayout((CBasePane *)this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EA9DF
// Name: protected: void CDockablePane::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnDestroy(CDockablePane *this)
{
  bool v2; // zf
  CDockablePane_vtbl *v3; // eax
  CWnd *v4; // eax
  CDockingManager *DockingManager; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  CObject *v8; // eax

  CDockablePane::RemoveCaptionButtons(this);
  v2 = this->GetParentMiniFrame(this, a2: 0) == nullptr;
  v3 = this->__vftable;
  if ( v2 )
    v3->UndockPane(this: &this->CPane, a2: 1);
  else
    v3->RemoveFromMiniframe(this: &this->CPane, a2: nullptr, a3: DM_UNKNOWN);
  if ( this->IsMDITabbed((CBasePane *)this) != 0 )
  {
    v4 = this->GetDockSiteFrameWnd(this);
    DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v4);
    CDockingManager::RemoveHiddenMDITabbedBar(this: DockingManager, pBar: this);
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    v8 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v7);
    if ( v8 != nullptr )
      PostMessageA(hWnd: (HWND)v8[8].__vftable, Msg: 0x10u, wParam: 0, lParam: 0);
  }
  CTooltipManager::DeleteToolTip(pToolTip: &this->m_pToolTip);
  CPane::OnDestroy(this: &this->CPane);
}

//------------------------------------------------------------------------------
// Address: 0x103EAA7E
// Name: protected: virtual void CDockablePane::OnTrackCaptionButtons(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnTrackCaptionButtons(CDockablePane *this, CPoint point)
{
  unsigned int m_nHot; // ebx
  CMFCCaptionButton *Button; // eax
  const CMFCCaptionButton *v5; // edi
  unsigned int Hit; // eax
  unsigned int m_nHit; // ecx
  CMFCCaptionButton *ButtonByHit; // eax
  HWND v9; // eax

  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
  {
    m_nHot = this->m_nHot;
    Button = CDockablePane::FindButton(this, point);
    v5 = Button;
    if ( Button != nullptr )
    {
      Hit = CMFCCaptionButton::GetHit(this: Button);
      m_nHit = this->m_nHit;
      this->m_nHot = Hit;
      if ( m_nHit == 0 || m_nHit == Hit )
        v5->m_bFocused = 1;
    }
    else
    {
      this->m_nHot = 0;
    }
    if ( this->m_nHot != m_nHot )
    {
      CDockablePane::RedrawButton(this, pButton: v5);
      ButtonByHit = CDockablePane::FindButtonByHit(this, nHit: m_nHot);
      if ( ButtonByHit != nullptr )
      {
        ButtonByHit->m_bFocused = 0;
        CDockablePane::RedrawButton(this, pButton: ButtonByHit);
      }
    }
    if ( this->m_nHit == 0 )
    {
      if ( m_nHot != 0 )
      {
        if ( this->m_nHot == 0 )
        {
          ReleaseCapture();
          this->m_bCaptionButtonsCaptured = 0;
        }
      }
      else if ( this->m_nHot != 0 )
      {
        v9 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v9);
        this->m_bCaptionButtonsCaptured = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EAB4C
// Name: protected: virtual void CDockablePane::StopCaptionButtonsTracking(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::StopCaptionButtonsTracking(CDockablePane *this)
{
  CMFCCaptionButton *ButtonByHit; // eax
  CMFCCaptionButton *v3; // eax
  CMFCCaptionButton *pBtn; // [esp+Ch] [ebp-4h]
  CMFCCaptionButton *pBtna; // [esp+Ch] [ebp-4h]

  if ( this->m_nHit != 0 )
  {
    ButtonByHit = CDockablePane::FindButtonByHit(this, nHit: this->m_nHit);
    this->m_nHit = 0;
    pBtn = ButtonByHit;
    ReleaseCapture();
    if ( pBtn != nullptr )
    {
      pBtn->m_bPushed = 0;
      CDockablePane::RedrawButton(this, pButton: pBtn);
    }
  }
  if ( this->m_nHot != 0 )
  {
    v3 = CDockablePane::FindButtonByHit(this, nHit: this->m_nHot);
    this->m_nHot = 0;
    pBtna = v3;
    ReleaseCapture();
    if ( pBtna != nullptr )
    {
      pBtna->m_bFocused = 0;
      CDockablePane::RedrawButton(this, pButton: pBtna);
    }
  }
  this->m_bCaptionButtonsCaptured = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10408E64
// Name: protected: int CMFCColorBar::OnQueryNewPalette(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::OnQueryNewPalette(CMFCColorBar *this)
{
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10408E87
// Name: protected: void CMFCColorBar::OnPaletteChanged(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnPaletteChanged(CMFCColorBar *this, CWnd *pFocusWnd)
{
  HWND__ *m_hWnd; // ecx
  HWND__ *v4; // eax

  CWnd::Default(this);
  if ( pFocusWnd != nullptr )
    m_hWnd = pFocusWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( this != nullptr )
    v4 = this->m_hWnd;
  else
    v4 = nullptr;
  if ( m_hWnd != v4 )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408ECC
// Name: public: virtual int CMFCColorBar::CreateControl(class CWnd __near *,class CRect const __near &,unsigned int,int,class CPalette __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::CreateControl(
        CMFCColorBar *this,
        CWnd *pParentWnd,
        const CRect *rect,
        unsigned int nID,
        int nColumns,
        CPalette *pPalette)
{
  int v7; // eax
  int v8; // ecx
  int result; // eax
  CMFCColorBar_vtbl *v10; // edi
  unsigned int v11; // eax
  CMFCColorBar_vtbl *v12; // eax
  HWND__ *m_hWnd; // eax
  CRect rectWnd; // [esp+1Ch] [ebp-14h] BYREF

  CMFCToolBar::EnableLargeIcons(this, bEnable: 0);
  if ( nColumns <= 0 )
  {
    v7 = pPalette != nullptr ? CPalette::GetEntryCount(this: pPalette) : 20;
    nColumns = v7;
    if ( v7 <= 0 )
      goto LABEL_13;
    v8 = rect->right - 2 * this->m_nHorzMargin - rect->left;
    while ( v8 / nColumns == 0 || v8 / nColumns * (v7 / nColumns) <= rect->bottom - 2 * this->m_nVertMargin - rect->top )
    {
      if ( --nColumns <= 0 )
        goto LABEL_12;
    }
    ++nColumns;
LABEL_12:
    if ( nColumns <= 0 )
LABEL_13:
      nColumns = -1;
  }
  result = this->Create(this, a2: pParentWnd, a3: 1342185472u, a4: nID, a5: pPalette, a6: nColumns, a7: 0, a8: 0);
  if ( result != 0 )
  {
    v10 = this->__vftable;
    v11 = this->GetPaneStyle(this);
    v10->SetPaneStyle(this, a2: v11 & 0xFFBFF0FF);
    v12 = this->__vftable;
    rectWnd = *rect;
    v12->MoveWindow(this, a2: &rectWnd, a3: 1, a4: nullptr);
    CMFCColorBar::ContextToSize(this, bSquareButtons: 1, bCenterButtons: 1);
    this->SetWindowPos(this, a2: &CWnd::wndTop, a3: -1, a4: -1, a5: -1, a6: -1, a7: 19u, a8: nullptr);
    if ( pParentWnd != nullptr )
      m_hWnd = pParentWnd->m_hWnd;
    else
      m_hWnd = nullptr;
    this->m_hWndOwner = m_hWnd;
    this->m_nCommandID = nID;
    this->m_bRouteCommandsViaFrame = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409018
// Name: public: void CMFCColorBar::SetColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::SetColor(CMFCColorBar *this, CObject_vtbl *color)
{
  CObList::CNode *m_pNodeHead; // eax
  __POSITION *pNext; // ecx
  CObject *data; // eax
  CObject *v6; // eax
  CObject *v7; // edi
  const RECT *v8; // edi
  HWND__ *m_hWnd; // [esp-14h] [ebp-28h]
  HWND__ *v10; // [esp-14h] [ebp-28h]
  int bWasOtherColor; // [esp+4h] [ebp-10h]
  __POSITION *pos; // [esp+8h] [ebp-Ch]
  int bIsOtherColor; // [esp+Ch] [ebp-8h]
  int iButton; // [esp+10h] [ebp-4h]

  if ( (CObject_vtbl *)this->m_ColorSelected != color )
  {
    this->m_ColorSelected = (unsigned int)color;
    if ( this->m_hWnd != nullptr )
    {
      if ( this->m_ColorAutomatic == -1 || (bIsOtherColor = 0, color != (CObject_vtbl *)-1) )
        bIsOtherColor = 1;
      m_pNodeHead = this->m_Buttons.m_pNodeHead;
      this->m_iHighlighted = -1;
      bWasOtherColor = 0;
      iButton = 0;
      if ( m_pNodeHead != nullptr )
      {
        while ( 1 )
        {
          pNext = (__POSITION *)m_pNodeHead->pNext;
          data = m_pNodeHead->data;
          pos = pNext;
          if ( ((int)data[9].__vftable & 1) == 0 )
          {
            v6 = AfxDynamicDownCast(pClass: &CMFCToolBarColorButton::classCMFCToolBarColorButton, pObject: data);
            v7 = v6;
            if ( v6 != nullptr && v6[31].__vftable == nullptr && v6[32].__vftable == nullptr )
            {
              if ( v6[29].__vftable != nullptr )
              {
                v6[29].__vftable = nullptr;
                InvalidateRect(hWnd: this->m_hWnd, lpRect: (const RECT *)&v6[21], bErase: true);
              }
              if ( v7[30].__vftable != nullptr && color == (CObject_vtbl *)-1 )
              {
                v7[29].__vftable = (CObject_vtbl *)1;
                m_hWnd = this->m_hWnd;
                this->m_iHighlighted = iButton;
                InvalidateRect(hWnd: m_hWnd, lpRect: (const RECT *)&v7[21], bErase: true);
              }
              else if ( v7[28].__vftable == color )
              {
                v7[29].__vftable = (CObject_vtbl *)1;
                v10 = this->m_hWnd;
                this->m_iHighlighted = iButton;
                InvalidateRect(hWnd: v10, lpRect: (const RECT *)&v7[21], bErase: true);
                bIsOtherColor = 0;
              }
              if ( v7[34].__vftable != nullptr )
              {
                v7[28].__vftable = (CObject_vtbl *)this->m_ColorSelected;
                v7[29].__vftable = (CObject_vtbl *)1;
                v8 = (const RECT *)&v7[21];
                InvalidateRect(hWnd: this->m_hWnd, lpRect: v8, bErase: true);
                bWasOtherColor = !IsRectEmpty(lprc: v8);
              }
            }
          }
          ++iButton;
          if ( pos == nullptr )
            break;
          m_pNodeHead = (CObList::CNode *)pos;
        }
      }
      if ( bWasOtherColor != bIsOtherColor )
      {
        this->AdjustLocations(this);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      }
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10409192
// Name: protected: virtual int CMFCColorBar::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::PreTranslateMessage(CMFCColorBar *this, tagMSG *pMsg)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  POINT v7; // [esp-8h] [ebp-28h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_pParentBtn == nullptr && this->m_pWndPropList == nullptr && this->m_pParentRibbonBtn == nullptr
    || this->m_bInCommand != 0 )
  {
    return CMFCToolBar::PreTranslateMessage(this, pMsg);
  }
  switch ( pMsg->message )
  {
    case 0x7Bu:
      goto LABEL_15;
    case 0x100u:
      if ( pMsg->wParam != 27 )
        return CMFCToolBar::PreTranslateMessage(this, pMsg);
LABEL_15:
      Parent = GetParent(hWnd: this->m_hWnd);
      goto LABEL_13;
    case 0x104u:
      goto LABEL_15;
    case 0x201u:
    case 0x204u:
    case 0x207u:
      m_hWnd = this->m_hWnd;
      memset(&rect, 0, sizeof(rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &rect);
      v7.y = SHIWORD(pMsg->lParam);
      v7.x = SLOWORD(pMsg->lParam);
      if ( !PtInRect(lprc: &rect, pt: v7) )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
LABEL_13:
        v4 = CWnd::FromHandle(hWnd: Parent);
        SendMessageA(hWnd: v4->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
        return 1;
      }
      break;
    default:
      break;
  }
  return CMFCToolBar::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10409271
// Name: protected: static int CMFCColorBar::InitColors(class CPalette __near *,class CArray<unsigned long,unsigned long> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCColorBar::InitColors(CPalette *pPalette, CArray<unsigned long,unsigned long> *arColors)
{
  CPalette *v2; // ebx
  HGDIOBJ StockObject; // eax
  signed int i; // esi
  tagPALETTEENTRY palEntry; // [esp+Ch] [ebp-4h] BYREF
  int nColorsCount; // [esp+18h] [ebp+8h]

  v2 = pPalette;
  if ( pPalette != nullptr )
    nColorsCount = CPalette::GetEntryCount(this: pPalette);
  else
    nColorsCount = 20;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arColors,
    nNewSize: nColorsCount,
    nGrowBy: -1);
  if ( v2 == nullptr )
  {
    StockObject = GetStockObject(i: 15);
    v2 = (CPalette *)CGdiObject::FromHandle(h: StockObject);
  }
  for ( i = 0; i < nColorsCount; ++i )
  {
    GetPaletteEntries(hpal: (HPALETTE)v2->m_hObject, iStart: i, cEntries: 1u, pPalEntries: &palEntry);
    if ( i < 0 || i >= arColors->m_nSize )
      AfxThrowInvalidArgException();
    arColors->m_pData[i] = palEntry.peRed | (*(unsigned __int16 *)&palEntry.peGreen << 8);
  }
  return nColorsCount;
}

//------------------------------------------------------------------------------
// Address: 0x10409309
// Name: protected: virtual void CMFCColorBar::ShowCommandMessageString(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::ShowCommandMessageString(CMFCColorBar *this, unsigned int __formal)
{
  WPARAM m_nCommandID; // esi
  CWnd *Owner; // eax

  m_nCommandID = 57345;
  if ( this->m_nCommandID != -1 )
    m_nCommandID = this->m_nCommandID;
  Owner = CWnd::GetOwner(this);
  SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: m_nCommandID, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10409336
// Name: protected: virtual int CMFCColorBar::OpenColorDialog(unsigned long,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::OpenColorDialog(CMFCColorBar *this, unsigned int colorDefault, unsigned int *colorRes)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // eax
  CObject *v7; // eax
  CColorDialog v9; // [esp+10h] [ebp-A28h] BYREF
  int v10; // [esp+C8h] [ebp-970h]
  CMFCColorDialog v11; // [esp+CCh] [ebp-96Ch] BYREF
  int v12; // [esp+A34h] [ebp-4h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  v6 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v5);
  if ( v6 != nullptr )
  {
    v7 = AfxDynamicDownCast(
           pClass: &CMFCColorMenuButton::classCMFCColorMenuButton,
           pObject: (CObject *)v6[82].__vftable);
    if ( v7 != nullptr )
      return ((int (__thiscall *)(CObject *, unsigned int, unsigned int *))v7->__vftable[21].GetRuntimeClass)(
               a1: v7,
               a2: colorDefault,
               a3: colorRes);
  }
  v10 = 0;
  if ( this->m_bStdColorDlg != 0 )
  {
    CColorDialog::CColorDialog(this: &v9, clrInit: colorDefault, dwFlags: 0x102u, pParentWnd: nullptr);
    v12 = 0;
    if ( CColorDialog::DoModal(this: &v9) == 1 )
    {
      *colorRes = v9.m_cc.rgbResult;
      v10 = 1;
    }
    v12 = -1;
    v9.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
    CDialog::~CDialog(this: &v9);
  }
  else
  {
    CMFCColorDialog::CMFCColorDialog(this: &v11, clrInit: colorDefault, __formal: 0, pParentWnd: nullptr, hPal: nullptr);
    v12 = 1;
    if ( CDialog::DoModal(this: &v11) == 1 )
    {
      *colorRes = v11.m_NewColor;
      v10 = 1;
    }
    v12 = -1;
    CMFCColorDialog::~CMFCColorDialog(this: &v11);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10409445
// Name: protected: virtual int CMFCColorBar::OnKey(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::OnKey(CMFCColorBar *this, unsigned int nChar)
{
  __POSITION *Index; // eax
  const CMFCToolBarButton *v4; // edi
  CWnd *Owner; // eax

  if ( this->m_iHighlighted >= 0
    && (Index = CStringList::FindIndex(
                  this: (CList<unsigned long,unsigned long> *)&this->m_Buttons,
                  nIndex: this->m_iHighlighted)) != nullptr )
  {
    v4 = *(const CMFCToolBarButton **)&Index[8];
  }
  else
  {
    v4 = nullptr;
  }
  if ( nChar != 13 || v4 == nullptr )
    return CMFCPopupMenuBar::OnKey(this, nChar);
  Owner = CWnd::GetOwner(this);
  SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
  this->OnSendCommand(this, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104167B1
// Name: protected: virtual void CMFCRibbonPanelMenuBar::OnDrawMenuBorder(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnDrawMenuBorder(CMFCRibbonPanelMenuBar *this, CDC *pDC)
{
  if ( this->m_pCategory != nullptr )
    this->m_pCategory->OnDrawMenuBorder(this: this->m_pCategory, a2: pDC, a3: this);
  else
    this->m_pPanel->OnDrawMenuBorder(this: this->m_pPanel, a2: pDC, a3: this);
}

//------------------------------------------------------------------------------
// Address: 0x104167E3
// Name: protected: void CMFCRibbonPanelMenuBar::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnDestroy(CMFCRibbonPanelMenuBar *this)
{
  if ( this->m_pToolTip != nullptr )
    CTooltipManager::DeleteToolTip(pToolTip: &this->m_pToolTip);
  CMFCPopupMenuBar::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10416801
// Name: public: class CMFCRibbonBar __near * CMFCRibbonPanelMenuBar::GetTopLevelRibbonBar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBar *__thiscall CMFCRibbonPanelMenuBar::GetTopLevelRibbonBar(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonBar *result; // eax

  result = this->m_pRibbonBar;
  if ( result == nullptr )
    return this->m_pPanelOrigin->m_pParent->m_pParentRibbonBar;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041681E
// Name: public: class CMFCRibbonButton __near * CMFCRibbonPanelMenuBar::GetDroppedDown(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonButton *__thiscall CMFCRibbonPanelMenuBar::GetDroppedDown(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonCategory *m_pCategory; // ecx
  CMFCRibbonBaseElement *DroppedDown; // eax

  m_pCategory = this->m_pCategory;
  if ( m_pCategory != nullptr )
    DroppedDown = CMFCRibbonCategory::GetDroppedDown(this: m_pCategory);
  else
    DroppedDown = CMFCRibbonPanel::GetDroppedDown(this: this->m_pPanel);
  return (CMFCRibbonButton *)AfxDynamicDownCast(pClass: &CMFCRibbonButton::classCMFCRibbonButton, pObject: DroppedDown);
}

//------------------------------------------------------------------------------
// Address: 0x1041684A
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanelMenuBar::HitTest(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanelMenuBar::HitTest(CMFCRibbonPanelMenuBar *this, CPoint point)
{
  CMFCRibbonCategory *m_pCategory; // ecx

  m_pCategory = this->m_pCategory;
  if ( m_pCategory != nullptr )
    return CMFCRibbonCategory::HitTest(this: m_pCategory, point, bCheckPanelCaption: 1);
  else
    return ((CMFCRibbonBaseElement *(__thiscall *)(CMFCRibbonPanel *, int, int, _DWORD))this->m_pPanel->HitTest)(
             a1: this->m_pPanel,
             a2: point.x,
             a3: point.y,
             a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416881
// Name: public: int CMFCRibbonPanelMenuBar::HitTestEx(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::HitTestEx(CMFCRibbonPanelMenuBar *this, CPoint point)
{
  CMFCRibbonCategory *m_pCategory; // ecx

  m_pCategory = this->m_pCategory;
  if ( m_pCategory != nullptr )
    return CMFCRibbonCategory::HitTestEx(this: m_pCategory, point);
  else
    return ((int (__thiscall *)(CMFCRibbonPanel *, int, int))this->m_pPanel->HitTestEx)(
             a1: this->m_pPanel,
             a2: point.x,
             a3: point.y);
}

//------------------------------------------------------------------------------
// Address: 0x104168AE
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanelMenuBar::GetFocused(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonPanelMenuBar::GetFocused(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonCategory *m_pCategory; // ecx

  m_pCategory = this->m_pCategory;
  if ( m_pCategory != nullptr )
    return CMFCRibbonCategory::GetFocused(this: m_pCategory);
  else
    return CMFCRibbonPanel::GetFocused(this: this->m_pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x104168CA
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonPanelMenu::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonPanelMenu::GetRuntimeClass(CMFCRibbonPanelMenu *this)
{
  return &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu;
}

//------------------------------------------------------------------------------
// Address: 0x104168D0
// Name: public: class CMFCRibbonPanelMenuBar __near * CMFCRibbonPanelMenu::GetParentRibbonMenuBar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanelMenu::GetParentRibbonMenuBar(CMFCRibbonPanelMenu *this)
{
  CMFCRibbonPanelMenuBar *result; // eax
  CObject *v2; // eax

  result = (CMFCRibbonPanelMenuBar *)CMFCPopupMenu::GetParentPopupMenu(this: &this->CMFCPopupMenu);
  if ( result != nullptr )
  {
    v2 = (CObject *)result->GetControlBarStyle(this: result);
    return (CMFCRibbonPanelMenuBar *)AfxDynamicDownCast(
                                       pClass: &CMFCRibbonPanelMenuBar::classCMFCRibbonPanelMenuBar,
                                       pObject: v2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104168F2
// Name: protected: void CMFCRibbonPanelMenu::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenu::OnKeyDown(
        CMFCRibbonPanelMenu *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  if ( this->m_wndRibbonBar.OnKey(this: &this->m_wndRibbonBar, a2: nChar) == 0 )
    CMFCPopupMenu::OnKeyDown(this: &this->CMFCPopupMenu, nChar, nRepCnt, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10416924
// Name: public: virtual int CMFCRibbonPanelMenu::IsAlwaysClose(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanelMenu::IsAlwaysClose(CMFCRibbonPanelMenu *this)
{
  BOOL result; // eax

  if ( this->m_bForceClose != 0 )
    return true;
  result = CMFCRibbonPanelMenuBar::IsMainPanel(this: &this->m_wndRibbonBar);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416941
// Name: protected: virtual void CMFCRibbonPanelMenu::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenu::DoPaint(CMFCRibbonPanelMenu *this, CDC *pDC)
{
  CMFCPopupMenu::DoPaint(this: &this->CMFCPopupMenu, pPaintDC: pDC);
  this->m_wndRibbonBar.OnDrawMenuBorder(this: &this->m_wndRibbonBar, a2: pDC);
}

//------------------------------------------------------------------------------
// Address: 0x10416961
// Name: protected: virtual int CMFCRibbonPanelMenu::GetBorderSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenu::GetBorderSize(CMFCRibbonPanelMenu *this)
{
  CMFCVisualManager *Instance; // eax

  if ( this->m_wndRibbonBar.m_bIsMenuMode != 0 )
    return CMFCPopupMenu::GetBorderSize(this: &this->CMFCPopupMenu);
  Instance = CMFCVisualManager::GetInstance();
  return Instance->GetRibbonPopupBorderSize(this: Instance, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10416987
// Name: public: virtual int CMFCRibbonPanelMenu::IsScrollUpAvailable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanelMenu::IsScrollUpAvailable(CMFCRibbonPanelMenu *this)
{
  return this->m_wndRibbonBar.m_iOffset > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10416993
// Name: public: virtual int CMFCRibbonPanelMenu::IsScrollDnAvailable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanelMenu::IsScrollDnAvailable(CMFCRibbonPanelMenu *this)
{
  CMFCRibbonPanel *m_pPanel; // eax

  m_pPanel = this->m_wndRibbonBar.m_pPanel;
  return m_pPanel == nullptr || m_pPanel->m_bScrollDnAvailable != 0;
}

//------------------------------------------------------------------------------
// Address: 0x104169AA
// Name: protected: void CMFCRibbonPanelMenu::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenu::OnDestroy(CMFCRibbonPanelMenu *this)
{
  CFrameWnd *v2; // ecx
  CFrameWnd *TopLevelFrame; // eax

  if ( this->m_bEscClose != 0 && this->m_wndRibbonBar.m_pCategory != nullptr )
  {
    v2 = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame != nullptr )
    {
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    }
    else
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this: &this->m_wndRibbonBar);
      v2 = (CFrameWnd *)g_pTopLevelFrame;
    }
    if ( TopLevelFrame != nullptr )
    {
      if ( v2 == nullptr )
        v2 = CWnd::GetTopLevelFrame(this: &this->m_wndRibbonBar);
      CWnd::SetFocus(this: v2);
    }
  }
  CMFCPopupMenu::OnDestroy(this: &this->CMFCPopupMenu);
}

//------------------------------------------------------------------------------
// Address: 0x10416A02
// Name: protected: CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonPanel *v2; // ecx
  CMFCRibbonPanel *v3; // eax

  CMFCPopupMenuBar::CMFCPopupMenuBar(this);
  this->__vftable = (CMFCRibbonPanelMenuBar_vtbl *)&CMFCRibbonPanelMenuBar::`vftable';
  this->m_sizePrefered.cx = 0;
  this->m_sizePrefered.cy = 0;
  this->m_sizeCategory.cx = 0;
  this->m_sizeCategory.cy = 0;
  this->m_rectAutoCommand.left = 0;
  this->m_rectAutoCommand.top = 0;
  this->m_rectAutoCommand.right = 0;
  this->m_rectAutoCommand.bottom = 0;
  this->m_ptStartMenu.x = 0;
  this->m_ptStartMenu.y = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  v2 = (CMFCRibbonPanel *)operator new(nSize: 0x268u);
  if ( v2 != nullptr )
    v3 = CMFCRibbonPanel::CMFCRibbonPanel(this: v2, lpszName: nullptr, hIcon: nullptr);
  else
    v3 = nullptr;
  this->m_pPanel = v3;
  CMFCRibbonPanelMenuBar::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10416AB0
// Name: public: virtual int CMFCRibbonPanelMenuBar::IsRibbonPanelInRegularMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanelMenuBar::IsRibbonPanelInRegularMode(CMFCRibbonPanelMenuBar *this)
{
  return this->m_bIsMenuMode == 0 && !CMFCRibbonPanelMenuBar::IsMainPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10416AC7
// Name: public: virtual CMFCRibbonPanelMenuBar::~CMFCRibbonPanelMenuBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::~CMFCRibbonPanelMenuBar(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonPanel *m_pPanel; // eax
  CMFCRibbonBar *m_pRibbonBar; // ecx
  CMFCRibbonPanel *v4; // ecx
  CMFCRibbonCategory *m_pCategory; // eax
  CMFCRibbonBar *v6; // ecx
  CMFCRibbonCategory *v7; // ecx
  CMFCRibbonBar *v8; // ecx
  CMFCRibbonCategory **p_m_pActiveCategory; // esi
  CMFCRibbonCategory *v10; // eax
  HWND v11; // esi
  tagRECT rc; // [esp+24h] [ebp-20h] BYREF
  int v13; // [esp+40h] [ebp-4h]

  this->__vftable = (CMFCRibbonPanelMenuBar_vtbl *)&CMFCRibbonPanelMenuBar::`vftable';
  m_pPanel = this->m_pPanel;
  v13 = 1;
  if ( m_pPanel != nullptr )
  {
    m_pRibbonBar = this->m_pRibbonBar;
    if ( m_pRibbonBar != nullptr && m_pRibbonBar->m_pKeyboardNavLevelCurrent == m_pPanel )
      CMFCRibbonBar::DeactivateKeyboardFocus(this: m_pRibbonBar, bSetFocus: 0);
    v4 = this->m_pPanel;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CMFCRibbonPanel *, int))v4->dtr_CObject)(a1: v4, a2: 1);
  }
  m_pCategory = this->m_pCategory;
  if ( m_pCategory != nullptr )
  {
    v6 = this->m_pRibbonBar;
    if ( v6 != nullptr && v6->m_pKeyboardNavLevelCurrent == m_pCategory )
      CMFCRibbonBar::DeactivateKeyboardFocus(this: v6, bSetFocus: 0);
    v7 = this->m_pCategory;
    if ( v7 != nullptr )
      ((void (__thiscall *)(CMFCRibbonCategory *, int))v7->dtr_CObject)(a1: v7, a2: 1);
    v8 = this->m_pRibbonBar;
    if ( v8 != nullptr )
    {
      p_m_pActiveCategory = &v8->m_pActiveCategory;
      if ( v8->m_pActiveCategory != nullptr && !CMFCRibbonBar::IsQuickAccessToolbarOnTop(this: v8) )
      {
        v10 = *p_m_pActiveCategory;
        v10->m_Tab.m_bIsDroppedDown = 0;
        v10->m_Tab.m_bIsHighlighted = 0;
        rc = (tagRECT)v10->m_Tab.m_rect;
        rc.bottom = this->m_pRibbonBar->m_QAToolbar.m_rect.bottom;
        InflateRect(lprc: &rc, dx: 1, dy: 1);
        RedrawWindow(hWnd: this->m_pRibbonBar->m_hWnd, lprcUpdate: &rc, hrgnUpdate: nullptr, flags: 0x105u);
      }
    }
  }
  if ( this->m_bHasKeyTips != 0 )
  {
    v11 = CMFCPopupMenu::m_pActivePopupMenu;
    if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr
      && CWnd::FromHandlePermanent(hWnd: *((HWND__ **)CMFCPopupMenu::m_pActivePopupMenu + 8)) != nullptr
      && IsWindowVisible(hWnd: *((HWND *)v11 + 8)) )
    {
      CMFCPopupMenu::UpdateAllShadows(lprectScreen: nullptr);
    }
  }
  LOBYTE(v13) = 0;
  CScrollBar::~CScrollBar(this: &this->m_wndScrollBarVert);
  v13 = -1;
  CMFCPopupMenuBar::~CMFCPopupMenuBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x10416C17
// Name: public: virtual void CMFCRibbonPanelMenuBar::AdjustLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::AdjustLocations(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonBar *m_pRibbonBar; // ecx
  CFont *Font; // eax
  CMFCRibbonCategory *m_pCategory; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-50h]
  CClientDC v7; // [esp+10h] [ebp-38h] BYREF
  CFont *pFont; // [esp+24h] [ebp-24h]
  tagRECT Rect; // [esp+28h] [ebp-20h] BYREF
  int v10; // [esp+44h] [ebp-4h]

  if ( this->m_bInUpdateShadow == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    CClientDC::CClientDC(this: &v7, pWnd: this);
    m_pRibbonBar = this->m_pRibbonBar;
    v10 = 0;
    Font = CWnd::GetFont(this: m_pRibbonBar);
    pFont = CDC::SelectObject(this: &v7, pFont: Font);
    if ( pFont == nullptr )
      AfxThrowInvalidArgException();
    m_pCategory = this->m_pCategory;
    if ( m_pCategory != nullptr )
    {
      m_pCategory->m_rect = (CRect)Rect;
      this->m_pCategory->RecalcLayout(this: this->m_pCategory, a2: &v7);
    }
    else if ( this->m_pPanel != nullptr )
    {
      this->m_pPanel->m_bSizeIsLocked = this->m_bResizeTracking;
      this->m_pPanel->m_nScrollOffset = this->m_iOffset;
      this->m_pPanel->Reposition(this: this->m_pPanel, a2: &v7, a3: (const CRect *)&Rect);
      this->m_pPanel->OnAfterChangeRect(this: this->m_pPanel, a2: &v7);
      TopLevelRibbonBar = CMFCRibbonPanelMenuBar::GetTopLevelRibbonBar(this);
      if ( TopLevelRibbonBar != nullptr && TopLevelRibbonBar->m_pKeyboardNavLevelCurrent == this->m_pPanel )
        CMFCRibbonBar::ShowKeyTips(this: TopLevelRibbonBar, bRepos: 1);
      this->m_pPanel->m_bSizeIsLocked = 0;
    }
    CDC::SelectObject(this: &v7, pFont);
    v10 = -1;
    CClientDC::~CClientDC(this: &v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10416D36
// Name: protected: void CMFCRibbonPanelMenuBar::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnMouseMove(CMFCRibbonPanelMenuBar *this, unsigned int nFlags, CPoint point)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  int v5; // eax
  CMFCRibbonPanel *v6; // ecx
  CMFCRibbonCategory *m_pCategory; // ecx
  CMFCRibbonBaseElement *Pressed; // eax
  CMFCRibbonCategory *v9; // ecx
  CMFCRibbonPanel *v10; // ecx
  int m_bIsHighlighted; // edi
  tagTRACKMOUSEEVENT ptme; // [esp+Ch] [ebp-10h] BYREF

  CMFCPopupMenuBar::OnMouseMove(this, nFlags, point);
  m_pPanel = this->m_pPanel;
  if ( m_pPanel != nullptr && afxGlobalData.m_bEnableAccessibility != 0 )
  {
    v5 = ((int (__thiscall *)(CMFCRibbonPanel *, int, int))m_pPanel->HitTestEx)(a1: m_pPanel, a2: point.x, a3: point.y);
    if ( v5 != -1 && v5 != this->m_iAccHotItem )
    {
      this->m_iAccHotItem = v5;
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 0x14u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
    }
  }
  v6 = this->m_pPanel;
  if ( v6 == nullptr || v6->m_bMenuMode != 0 || CMFCRibbonPanel::GetDroppedDown(this: v6) == nullptr )
  {
    m_pCategory = this->m_pCategory;
    if ( m_pCategory == nullptr || CMFCRibbonCategory::GetDroppedDown(this: m_pCategory) == nullptr )
    {
      if ( CPoint::operator!=(this: &this->m_ptStartMenu, point: (tagPOINT)-1LL) != 0 )
      {
        ptme.hwndTrack = nullptr;
        ptme.dwHoverTime = 0;
        GetCursorPos(lpPoint: (LPPOINT)&ptme.hwndTrack);
        if ( abs(lnumber: (int)ptme.hwndTrack - this->m_ptStartMenu.x) < 10
          && abs(lnumber: ptme.dwHoverTime - this->m_ptStartMenu.y) < 10 )
        {
          return;
        }
        this->m_ptStartMenu.x = -1;
        this->m_ptStartMenu.y = -1;
      }
      if ( point == -1 )
      {
        this->m_bTracked = 0;
      }
      else if ( this->m_bTracked == 0 )
      {
        ptme.hwndTrack = this->m_hWnd;
        this->m_bTracked = 1;
        ptme.cbSize = 16;
        ptme.dwFlags = 2;
        ptme.dwHoverTime = -1;
        AFXTrackMouse(&ptme);
        if ( this->m_pCategory == nullptr )
        {
          Pressed = CMFCRibbonPanel::GetPressed(this: this->m_pPanel);
          if ( Pressed != nullptr && (nFlags & 1) == 0 )
            Pressed->m_bIsPressed = 0;
        }
      }
      v9 = this->m_pCategory;
      if ( v9 != nullptr )
      {
        ((void (__thiscall *)(CMFCRibbonCategory *, int, int))v9->OnMouseMove)(a1: v9, a2: point.x, a3: point.y);
      }
      else
      {
        v10 = this->m_pPanel;
        if ( v10 != nullptr )
        {
          m_bIsHighlighted = v10->m_bIsHighlighted;
          ((void (__thiscall *)(CMFCRibbonPanel *, int, int, int))v10->Highlight)(
            a1: v10,
            a2: 1,
            a3: point.x,
            a4: point.y);
          if ( m_bIsHighlighted == 0 )
            RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041A454
// Name: protected: void CMFCOutlookBarTabCtrl::DrawTabButton(class CDC __near &,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::DrawTabButton(
        CMFCOutlookBarTabCtrl *this,
        CDC *dc,
        int iButtonIdx,
        int bDrawPressedButton)
{
  int *v5; // eax
  HICON__ *v6; // esi
  BOOL v7; // edi
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager *v9; // eax
  HICON__ *v10; // eax
  int v11; // ecx
  tagPOINT v12; // rdi
  int v13; // edx
  CImageList *v14; // eax
  CDC_vtbl *v15; // esi
  int v16; // edi
  unsigned int m_nPageButtonTextAlign; // eax
  const char *dtr_CObject; // eax
  int v19; // edx
  CMFCVisualManager *v20; // eax
  CPoint v21; // [esp-1Ch] [ebp-18Ch]
  CSize v22; // [esp-14h] [ebp-184h]
  int v23; // [esp+10h] [ebp-160h] BYREF
  int v24; // [esp+14h] [ebp-15Ch]
  unsigned int clrBarText; // [esp+18h] [ebp-158h] BYREF
  tagRECT *v26; // [esp+1Ch] [ebp-154h]
  CDC_vtbl *v27; // [esp+20h] [ebp-150h]
  HICON__ *hIcon; // [esp+24h] [ebp-14Ch]
  int nImage; // [esp+28h] [ebp-148h]
  CDC *pDC; // [esp+2Ch] [ebp-144h]
  CBasePane v31; // [esp+30h] [ebp-140h] BYREF
  tagRECT v32; // [esp+130h] [ebp-40h] BYREF
  __int64 v33; // [esp+140h] [ebp-30h] BYREF
  int right; // [esp+148h] [ebp-28h]
  int bottom; // [esp+14Ch] [ebp-24h]
  RECT rc; // [esp+150h] [ebp-20h] BYREF
  int v37; // [esp+16Ch] [ebp-4h]

  pDC = dc;
  hIcon = (HICON__ *)iButtonIdx;
  if ( iButtonIdx < 0 || iButtonIdx >= this->m_arTabs.m_nSize )
    AfxThrowInvalidArgException();
  v5 = (int *)this->m_arTabs.m_pData[iButtonIdx];
  v26 = (tagRECT *)(v5 + 4);
  rc.left = v5[4];
  rc.top = v5[5];
  rc.right = v5[6];
  v27 = (CDC_vtbl *)v5;
  rc.bottom = v5[7];
  if ( !IsRectEmpty(lprc: &rc) )
  {
    v6 = hIcon;
    nImage = hIcon == (HICON__ *)this->m_iHighlighted;
    v7 = hIcon == (HICON__ *)this->m_iPressed && bDrawPressedButton != 0;
    hIcon = (HICON__ *)(hIcon == (HICON__ *)this->m_iActiveTab);
    if ( CMFCOutlookBarTabCtrl::IsMode2003(this) != 0 && hIcon != nullptr )
      v7 = true;
    clrBarText = afxGlobalData.clrBarText;
    Instance = CMFCVisualManager::GetInstance();
    Instance->OnFillOutlookPageButton(
      this: Instance,
      a2: pDC,
      a3: (const CRect *)&rc,
      a4: nImage,
      a5: v7,
      a6: &clrBarText);
    v9 = CMFCVisualManager::GetInstance();
    v9->OnDrawOutlookPageButtonBorder(this: v9, a2: pDC, a3: (CRect *)&rc, a4: nImage, a5: v7);
    this->GetImageSize(this, result: (CSize *)&v23);
    nImage = this->GetTabIcon(this, a2: (int)v6);
    v10 = this->GetTabHicon(this, a2: v6);
    hIcon = v10;
    if ( nImage != -1 || v10 != nullptr )
    {
      v11 = v23;
    }
    else
    {
      v11 = 0;
      v23 = 0;
    }
    if ( v11 + CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN <= rc.right - rc.left )
    {
      v32 = rc;
      v12.y = rc.top + (rc.bottom - rc.top - v24) / 2;
      v12.x = rc.left + 4;
      v13 = rc.left + 4 + v11;
      if ( hIcon != nullptr )
      {
        v22.cy = v24;
        v22.cx = v13 - v12.x;
        v21.y = rc.top + (rc.bottom - rc.top - v24) / 2;
        v21.x = rc.left + 4;
        CDC::DrawState(this: pDC, pt: v21, size: v22, hIcon, nFlags: 0, hBrush: nullptr);
      }
      else
      {
        v14 = (CImageList *)((int (__fastcall *)(CMFCOutlookBarTabCtrl *, int))this->GetImageList)(a1: this, a2: v13);
        if ( v14 != nullptr && nImage != -1 )
          CImageList::Draw(this: v14, (HDC__ *)pDC, nImage, pt: v12, nStyle: 1u);
      }
    }
    pDC->SetTextColor(this: pDC, a2: clrBarText);
    v33 = *(_QWORD *)&v26->left;
    right = v26->right;
    bottom = v26->bottom;
    v15 = v27;
    if ( v27->ScaleViewportExt != nullptr && CMFCOutlookBarTabCtrl::IsMode2003(this) == 0 )
      right -= 11;
    LODWORD(v33) = v33 + v23 + 8;
    v16 = 32804;
    if ( CMFCOutlookBarTabCtrl::IsMode2003(this) == 0 )
    {
      m_nPageButtonTextAlign = this->m_nPageButtonTextAlign;
      if ( m_nPageButtonTextAlign != 0 )
      {
        v16 = 32805;
        if ( m_nPageButtonTextAlign == 2 )
          v16 = 32806;
      }
    }
    dtr_CObject = (const char *)v15->dtr_CObject;
    v19 = *((_DWORD *)dtr_CObject - 3);
    v27 = pDC->__vftable;
    v27->DrawTextA(this: pDC, a2: dtr_CObject, a3: v19, a4: (tagRECT *)&v33, a5: v16);
    if ( v15->ScaleViewportExt != nullptr && CMFCOutlookBarTabCtrl::IsMode2003(this) == 0 )
    {
      v32 = *v26;
      v32.left = right;
      InflateRect(lprc: &v32, dx: -4, dy: -2);
      CBasePane::CBasePane(this: &v31);
      v37 = 0;
      v20 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, CBasePane *))v20->OnDrawBarGripper)(
        a1: v20,
        a2: pDC,
        a3: v32.left,
        a4: v32.top,
        a5: v32.right,
        a6: v32.bottom,
        a7: 1,
        a8: &v31);
      v37 = -1;
      CBasePane::~CBasePane(this: &v31);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041A769
// Name: protected: virtual int COutlookOptionsDlg::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COutlookOptionsDlg::OnInitDialog(COutlookOptionsDlg *this)
{
  CWnd *MainWnd; // eax
  LPARAM i; // ebx
  CAfxStringMgr *StringManager; // eax
  CMFCOutlookBarTabCtrl *m_parentBar; // ecx
  CMFCOutlookBarTabCtrl_vtbl *v6; // eax
  int v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  LRESULT nIndex; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  CDialog::OnInitDialog(this);
  if ( AfxGetMainWnd() != nullptr )
  {
    MainWnd = AfxGetMainWnd();
    if ( (CWnd::GetExStyle(this: MainWnd) & 0x400000) != 0 )
      CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: 0x400000u, nFlags: 0);
  }
  for ( i = 0; i < this->m_parentBar->m_iTabsNum; ++i )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
    m_parentBar = this->m_parentBar;
    v6 = m_parentBar->__vftable;
    v13 = 0;
    v6->GetTabLabel(this: m_parentBar, a2: i, a3: &str);
    nIndex = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)str.m_pszData);
    SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x19Au, wParam: nIndex, lParam: i);
    v7 = this->m_parentBar->IsTabVisible(this: this->m_parentBar, a2: i);
    CCheckListBox::SetCheck(this: &this->m_wndList, nIndex, nCheck: v7);
    v13 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
  }
  SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
  COutlookOptionsDlg::OnSelchange(this);
  Parent = GetParent(hWnd: this->m_parentBar->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: Parent);
  if ( AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v9) == nullptr )
  {
    CWnd::EnableWindow(this: &this->m_wndReset, bEnable: 0);
    CWnd::ShowWindow(this: &this->m_wndReset, nCmdShow: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041A8A8
// Name: protected: void COutlookOptionsDlg::OnReset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnReset(COutlookOptionsDlg *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  char *v4; // ecx
  int v5; // ebx
  int v6; // edi
  const CArray<int,int> *DefaultTabsOrder; // eax
  CMFCRibbonKeyTip *v8; // eax
  CAfxStringMgr *StringManager; // eax
  CMFCOutlookBarTabCtrl *m_parentBar; // ecx
  CMFCOutlookBarTabCtrl_vtbl *v11; // eax
  CArray<int,int> arTabsOrder; // [esp+10h] [ebp-2Ch] BYREF
  int nIndex; // [esp+24h] [ebp-18h]
  int iTabNum; // [esp+28h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+2Ch] [ebp-10h] BYREF
  int v16; // [esp+38h] [ebp-4h]

  Parent = GetParent(hWnd: this->m_parentBar->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (char *)AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v3);
  v5 = 0;
  str.m_pszData = v4;
  if ( v4 != nullptr )
  {
    arTabsOrder.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
    memset(&arTabsOrder.m_pData, 0, 16);
    v16 = 0;
    v6 = 0;
    if ( CBaseTabbedPane::GetDefaultTabsOrder(this: (CBaseTabbedPane *)v4)->m_nSize > 0 )
    {
      while ( 1 )
      {
        DefaultTabsOrder = CBaseTabbedPane::GetDefaultTabsOrder(this: (CBaseTabbedPane *)str.m_pszData);
        if ( v6 < 0 || v6 >= DefaultTabsOrder->m_nSize )
          break;
        v8 = (CMFCRibbonKeyTip *)this->m_parentBar->GetTabByID(
                                   this: this->m_parentBar,
                                   a2: DefaultTabsOrder->m_pData[v6]);
        if ( (int)v8 < 0 )
          goto LABEL_12;
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&arTabsOrder,
          nIndex: arTabsOrder.m_nSize,
          newElement: v8);
        if ( ++v6 >= CBaseTabbedPane::GetDefaultTabsOrder(this: (CBaseTabbedPane *)str.m_pszData)->m_nSize )
          goto LABEL_7;
      }
LABEL_14:
      AfxThrowInvalidArgException();
    }
LABEL_7:
    SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
    if ( arTabsOrder.m_nSize > 0 )
    {
      while ( v5 >= 0 && v5 < arTabsOrder.m_nSize )
      {
        iTabNum = arTabsOrder.m_pData[v5];
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
        m_parentBar = this->m_parentBar;
        v11 = m_parentBar->__vftable;
        LOBYTE(v16) = 1;
        v11->GetTabLabel(this: m_parentBar, a2: iTabNum, a3: &str);
        nIndex = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)str.m_pszData);
        SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x19Au, wParam: nIndex, lParam: iTabNum);
        CCheckListBox::SetCheck(this: &this->m_wndList, nIndex, nCheck: 1);
        LOBYTE(v16) = 0;
        ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
        if ( ++v5 >= arTabsOrder.m_nSize )
          goto LABEL_11;
      }
      goto LABEL_14;
    }
LABEL_11:
    SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
    COutlookOptionsDlg::OnSelchange(this);
LABEL_12:
    v16 = -1;
    CArray<int,int>::~CArray<int,int>(this: &arTabsOrder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041AA3A
// Name: protected: void COutlookOptionsDlg::MoveItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::MoveItem(COutlookOptionsDlg *this, int bMoveUp)
{
  LRESULT v3; // ebx
  CAfxStringMgr *StringManager; // eax
  WPARAM v5; // eax
  LRESULT v6; // ebx
  int bCheck; // [esp+10h] [ebp-18h]
  LPARAM dwData; // [esp+14h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+18h] [ebp-10h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  v3 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
  v10 = 0;
  CListBox::GetText(this: &this->m_wndList, nIndex: v3, rString: &str);
  dwData = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x199u, wParam: v3, lParam: 0);
  bCheck = CCheckListBox::GetCheck(this: &this->m_wndList, nIndex: v3);
  SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
  v5 = v3 - 1;
  if ( bMoveUp == 0 )
    v5 = v3 + 1;
  v6 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x181u, wParam: v5, lParam: (LPARAM)str.m_pszData);
  SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x19Au, wParam: v6, lParam: dwData);
  CCheckListBox::SetCheck(this: &this->m_wndList, nIndex: v6, nCheck: bCheck);
  SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x186u, wParam: v6, lParam: 0);
  COutlookOptionsDlg::OnSelchange(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB1E
// Name: public: virtual int CMFCOutlookBarTabCtrl::SetActiveTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::SetActiveTab(CMFCOutlookBarTabCtrl *this, int iTab)
{
  int m_iActiveTab; // eax
  int m_iHighlighted; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  CWnd *v8; // eax
  CMFCOutlookBarTabCtrl_vtbl *v9; // eax
  CWnd *v10; // edi
  int v11; // eax
  int m_nSize; // ecx
  bool v13; // zf
  int v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  int v17; // eax
  int v18; // eax
  int *v19; // esi
  int *v20; // esi
  int v21; // edi
  int v22; // eax
  int bottom; // eax
  tagRECT *v24; // eax
  CWnd *v25; // edi
  int v26; // edi
  CWnd *v27; // edi
  CAfxStringMgr *StringManager; // eax
  CMFCOutlookBarTabCtrl_vtbl *v29; // eax
  CWnd_vtbl *v30; // eax
  HWND v31; // eax
  CFont *v32; // eax
  const CWnd *v33; // eax
  CView *v34; // edi
  CFrameWnd *v35; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-A8h]
  HWND__ *v37; // [esp-8h] [ebp-A8h]
  int v38; // [esp-8h] [ebp-A8h]
  CClientDC v39; // [esp+10h] [ebp-90h] BYREF
  BOOL v40; // [esp+24h] [ebp-7Ch]
  int v41; // [esp+28h] [ebp-78h]
  int bIsUp; // [esp+2Ch] [ebp-74h]
  int bIsDown; // [esp+30h] [ebp-70h]
  int v44; // [esp+34h] [ebp-6Ch]
  CWnd *v45; // [esp+38h] [ebp-68h]
  int v46; // [esp+3Ch] [ebp-64h]
  CFont *pFont; // [esp+40h] [ebp-60h]
  int v48; // [esp+44h] [ebp-5Ch]
  CWnd *v49; // [esp+48h] [ebp-58h]
  CWnd *v50; // [esp+4Ch] [ebp-54h]
  int dy; // [esp+50h] [ebp-50h]
  int v52; // [esp+54h] [ebp-4Ch]
  ATL::CSimpleStringT<char,0> v53; // [esp+58h] [ebp-48h] BYREF
  BOOL v54; // [esp+5Ch] [ebp-44h]
  tagRECT Rect; // [esp+60h] [ebp-40h] BYREF
  RECT rc; // [esp+70h] [ebp-30h] BYREF
  tagRECT v57; // [esp+80h] [ebp-20h] BYREF
  int v58; // [esp+9Ch] [ebp-4h]

  if ( iTab >= 0 && iTab < this->m_iTabsNum && iTab < this->m_arTabs.m_nSize )
  {
    m_iActiveTab = this->m_iActiveTab;
    v40 = m_iActiveTab == -1;
    if ( m_iActiveTab == iTab )
      return 1;
    v53.m_pszData = (char *)CMFCOutlookBarTabCtrl::IsMode2003(this);
    m_iHighlighted = this->m_iHighlighted;
    if ( m_iHighlighted != this->m_iPressed
      || m_iHighlighted == -1
      || CMFCOutlookBarTabCtrl::m_bEnableAnimation == 0
      || (v54 = true, v53.m_pszData != nullptr) )
    {
      v54 = false;
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    v8 = (CWnd *)AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v7);
    v45 = v8;
    if ( v8 != nullptr && ((int (__thiscall *)(CWnd *, int))v8->__vftable[2].OnGestureRotate)(a1: v8, a2: iTab) == 0 )
      v54 = false;
    if ( afxGlobalData.bIsRemoteSession != 0 )
      v54 = false;
    v52 = this->m_iActiveTab;
    v49 = this->GetActiveWnd(this);
    v9 = this->__vftable;
    this->m_iActiveTab = iTab;
    v10 = v9->GetActiveWnd(this);
    v50 = v10;
    if ( v10 != nullptr )
    {
      if ( v54 )
      {
        v11 = this->m_iActiveTab;
        if ( v11 < 0 )
          goto LABEL_37;
        m_nSize = this->m_arTabs.m_nSize;
        if ( v11 >= m_nSize || v52 < 0 || v52 >= m_nSize )
          goto LABEL_37;
        m_hWnd = this->m_hWnd;
        memset(&Rect, 0, sizeof(Rect));
        v54 = v11 < v52;
        GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
        v37 = v49->m_hWnd;
        memset(&v57, 0, sizeof(v57));
        GetWindowRect(hWnd: v37, lpRect: &v57);
        CWnd::ScreenToClient(this, lpRect: &v57);
        dy = v54 ? 30 : -30;
        v44 = abs(lnumber: (v57.bottom - v57.top) / dy);
        if ( this->m_bScrollButtons == 0 || (v13 = v53.m_pszData == nullptr, v53.m_pszData = (char *)1, !v13) )
          v53.m_pszData = nullptr;
        bIsUp = CWnd::IsWindowEnabled(this: &this->m_btnUp);
        bIsDown = CWnd::IsWindowEnabled(this: &this->m_btnDown);
        if ( v53.m_pszData != nullptr )
        {
          CWnd::ShowWindow(this: &this->m_btnUp, nCmdShow: 0);
          CWnd::ShowWindow(this: &this->m_btnDown, nCmdShow: 0);
          v14 = 0;
          if ( this->m_iTabsNum > 0 )
          {
            while ( v14 >= 0 && v14 < this->m_arTabs.m_nSize )
            {
              v15 = this->m_iActiveTab;
              if ( v14 == v15 || v14 == v15 + 1 )
              {
                v16 = this->m_arTabs.m_pData[v14];
                v16[6] += this->m_nTabsHeight;
              }
              if ( ++v14 >= this->m_iTabsNum )
                goto LABEL_33;
            }
LABEL_37:
            AfxThrowInvalidArgException();
          }
        }
LABEL_33:
        v17 = this->m_iActiveTab;
        memset(&rc, 0, sizeof(rc));
        if ( v54 )
        {
          v18 = v17 + 1;
          if ( v18 < 0 || v18 >= this->m_arTabs.m_nSize )
            goto LABEL_37;
          v19 = (int *)((char *)this->m_arTabs.m_pData[v18] + 16);
          rc.left = *v19++;
          rc.top = *v19;
          rc.right = v19[1];
          rc.bottom = dy + rc.top;
        }
        else
        {
          if ( v17 < 0 || v17 >= this->m_arTabs.m_nSize )
            goto LABEL_37;
          v20 = (int *)((char *)this->m_arTabs.m_pData[v17] + 16);
          rc.left = *v20++;
          rc.top = *v20++;
          rc.right = *v20;
          rc.bottom = v20[1];
          rc.top = dy + rc.bottom;
        }
        CWnd::ModifyStyle(this, dwRemove: 0x2000000u, dwAdd: 0, nFlags: 8u);
        CClientDC::CClientDC(this: &v39, pWnd: this);
        v58 = 0;
        pFont = CDC::SelectObject(this: &v39, pFont: &afxGlobalData.fontRegular);
        CDC::SetBkMode(this: &v39, nBkMode: 1);
        if ( v54 )
        {
          v21 = this->m_iActiveTab + 1;
          v48 = v21;
        }
        else
        {
          v48 = v52 + 1;
          v21 = v52 + 1;
        }
        v22 = v52;
        if ( !v54 )
          v22 = this->m_iActiveTab;
        v52 = v22;
        v41 = CDockingManager::m_bDisableRecalcLayout;
        CDockingManager::m_bDisableRecalcLayout = 1;
        v46 = 0;
        if ( v44 > 0 )
        {
          while ( 1 )
          {
            if ( v54 )
            {
              v57.top += dy;
              bottom = v57.bottom;
            }
            else
            {
              bottom = dy + v57.bottom;
              v57.bottom += dy;
            }
            CWnd::SetWindowPos(
              this: v49,
              pWndInsertAfter: nullptr,
              x: v57.left,
              y: v57.top,
              cx: v57.right - v57.left,
              cy: bottom - v57.top,
              nFlags: 0x14u);
            if ( v48 <= v52 )
              break;
LABEL_57:
            FillRect(hDC: v39.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
            OffsetRect(lprc: &rc, dx: 0, dy);
            Sleep(dwMilliseconds: 0xAu);
            if ( ++v46 >= v44 )
              goto LABEL_58;
            v21 = v48;
          }
          while ( v21 >= 0 )
          {
            if ( v21 >= this->m_arTabs.m_nSize )
              break;
            v24 = (tagRECT *)this->m_arTabs.m_pData[v21];
            if ( v24 == nullptr )
              break;
            OffsetRect(lprc: v24 + 1, dx: 0, dy);
            CMFCOutlookBarTabCtrl::DrawTabButton(this, dc: &v39, iButtonIdx: v21++, bDrawPressedButton: 0);
            if ( v21 > v52 )
              goto LABEL_57;
          }
          goto LABEL_37;
        }
LABEL_58:
        if ( v53.m_pszData != nullptr )
          CMFCOutlookBarTabCtrl::EnableScrollButtons(this, bEnable: 1, bIsUp, bIsDown);
        CDockingManager::m_bDisableRecalcLayout = v41;
        CDC::SelectObject(this: &v39, pFont);
        CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x2000000u, nFlags: 8u);
        CWnd::ShowWindow(this: v49, nCmdShow: 0);
        this->RecalcLayout(this);
        if ( v45 != nullptr )
          ((void (__thiscall *)(CWnd *, int))v45->__vftable[2].OnGestureTwoFingerTap)(a1: v45, a2: iTab);
        v25 = v50;
        CWnd::SetWindowPos(this: v50, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x5Fu);
        BringWindowToTop(hWnd: v25->m_hWnd);
        RedrawWindow(hWnd: v25->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
        v58 = -1;
        CClientDC::~CClientDC(this: &v39);
      }
      else
      {
        if ( v49 != nullptr )
          CWnd::ShowWindow(this: v49, nCmdShow: 0);
        this->RecalcLayout(this);
        CWnd::ShowWindow(this: v10, nCmdShow: 5);
        BringWindowToTop(hWnd: v10->m_hWnd);
        v26 = CDockingManager::m_bDisableRecalcLayout;
        CDockingManager::m_bDisableRecalcLayout = 1;
        CWnd::SetWindowPos(
          this: v50,
          pWndInsertAfter: nullptr,
          x: -1,
          y: -1,
          cx: this->m_rectWndArea.right - this->m_rectWndArea.left + 1,
          cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
          nFlags: 0x16u);
        CWnd::SetWindowPos(
          this: v50,
          pWndInsertAfter: nullptr,
          x: -1,
          y: -1,
          cx: this->m_rectWndArea.right - this->m_rectWndArea.left,
          cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
          nFlags: 0x16u);
        CDockingManager::m_bDisableRecalcLayout = v26;
      }
      v27 = v45;
      if ( v45 != nullptr && ((int (__thiscall *)(CWnd *))v45->__vftable[2].OnTouchInputs)(a1: v45) != 0 )
      {
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v53, pStringMgr: StringManager);
        v29 = this->__vftable;
        v38 = this->m_iActiveTab;
        v58 = 1;
        v29->GetTabLabel(this, a2: v38, a3: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v53);
        if ( ((int (__thiscall *)(CWnd *))v27->__vftable[2].OnTouchInputs)(a1: v27) != 0 )
          CWnd::SetWindowTextA(this: v27, lpszString: v53.m_pszData);
        v30 = v27->__vftable;
        pFont = (CFont *)v27;
        if ( ((int (__thiscall *)(CWnd *))v30[1].dtr_CObject)(a1: v27) != 0 )
        {
          v32 = pFont;
        }
        else
        {
          v31 = GetParent(hWnd: v27->m_hWnd);
          v32 = (CFont *)CWnd::FromHandle(hWnd: v31);
        }
        if ( v32 != nullptr )
          RedrawWindow(hWnd: (HWND)v32[4].__vftable, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
        v58 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)v53.m_pszData - 1);
      }
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      if ( !v40 )
      {
        v33 = (const CWnd *)AfxDynamicDownCast(pClass: &CView::classCView, pObject: v50);
        v34 = (CView *)v33;
        if ( v33 != nullptr )
        {
          v35 = AFXGetParentFrame(pWnd: v33);
          CFrameWnd::SetActiveView(this: v35, pViewNew: v34, bNotify: 1);
        }
        else
        {
          CWnd::SetFocus(this: v50);
        }
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041B149
// Name: protected: void COutlookOptionsDlg::OnMoveDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnMoveDown(COutlookOptionsDlg *this)
{
  COutlookOptionsDlg::MoveItem(this, bMoveUp: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B151
// Name: protected: void COutlookOptionsDlg::OnMoveUp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnMoveUp(COutlookOptionsDlg *this)
{
  COutlookOptionsDlg::MoveItem(this, bMoveUp: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1041B159
// Name: public: virtual class CMFCPopupMenu __near * COutlookCustomizeButton::CreatePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall COutlookCustomizeButton::CreatePopupMenu(COutlookCustomizeButton *this)
{
  CMFCPopupMenu *PopupMenu; // eax
  CMFCPopupMenu *v3; // edi
  CMFCToolBar *v5; // eax
  int v6; // eax
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int StringA; // eax
  const CMFCToolBarMenuButton *v10; // eax
  HINSTANCE__ *v11; // eax
  int v12; // eax
  const CMFCToolBarMenuButton *v13; // eax
  HINSTANCE__ *v14; // eax
  int v15; // eax
  char *m_pszData; // esi
  const CMFCToolBarMenuButton *v17; // eax
  CObject_vtbl *m_iCustomizeCmdId; // [esp-8h] [ebp-114h]
  ATL::CSimpleStringT<char,0> v19; // [esp+10h] [ebp-FCh] BYREF
  CMFCToolBarMenuButton v20; // [esp+14h] [ebp-F8h] BYREF
  int v21; // [esp+108h] [ebp-4h]

  PopupMenu = CMFCCustomizeButton::CreatePopupMenu(this);
  v3 = PopupMenu;
  if ( PopupMenu == nullptr )
    return nullptr;
  m_iCustomizeCmdId = (CObject_vtbl *)this->m_iCustomizeCmdId;
  v5 = PopupMenu->GetMenuBar(this: PopupMenu);
  v6 = CMFCToolBar::CommandToIndex(this: v5, nIDFind: m_iCustomizeCmdId, iIndexFirst: 0);
  CMFCPopupMenu::RemoveItem(this: v3, iIndex: v6);
  if ( CMFCPopupMenu::GetMenuItemCount(this: v3) > 0 )
    CMFCPopupMenu::InsertSeparator(this: v3, iInsertAt: -1);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v19, pStringMgr: StringManager);
  v21 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x4285u);
  if ( StringResourceHandle != nullptr )
    StringA = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v19,
                hInstance: StringResourceHandle,
                nID: 0x4285u);
  else
    StringA = 0;
  if ( StringA != 0 )
  {
    v10 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
            this: &v20,
            uiID: 0xF200u,
            hMenu: nullptr,
            iImage: -1,
            lpszText: v19.m_pszData,
            bUserButton: 0);
    LOBYTE(v21) = 1;
    CMFCPopupMenu::InsertItem(this: v3, button: v10, iInsertAt: -1);
    LOBYTE(v21) = 0;
    CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v20);
    v11 = AfxFindStringResourceHandle(__formal: 0x4286u);
    v12 = v11 != nullptr
        ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v19,
            hInstance: v11,
            nID: 0x4286u)
        : 0;
    if ( v12 != 0 )
    {
      v13 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
              this: &v20,
              uiID: 0xF201u,
              hMenu: nullptr,
              iImage: -1,
              lpszText: v19.m_pszData,
              bUserButton: 0);
      LOBYTE(v21) = 2;
      CMFCPopupMenu::InsertItem(this: v3, button: v13, iInsertAt: -1);
      LOBYTE(v21) = 0;
      CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v20);
      v14 = AfxFindStringResourceHandle(__formal: 0x4287u);
      v15 = v14 != nullptr
          ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v19,
              hInstance: v14,
              nID: 0x4287u)
          : 0;
      if ( v15 != 0 )
      {
        m_pszData = v19.m_pszData;
        v17 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                this: &v20,
                uiID: 0xF202u,
                hMenu: nullptr,
                iImage: -1,
                lpszText: v19.m_pszData,
                bUserButton: 0);
        LOBYTE(v21) = 3;
        CMFCPopupMenu::InsertItem(this: v3, button: v17, iInsertAt: -1);
        LOBYTE(v21) = 0;
        CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v20);
        ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
        return v3;
      }
    }
  }
  AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x1041B303
// Name: public: virtual int CMFCOutlookBarToolBar::OnUserToolTip(class CMFCToolBarButton __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarToolBar::OnUserToolTip(
        CMFCOutlookBarToolBar *this,
        CMFCToolBarButton *pButton,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strTTText)
{
  ATL::CSimpleStringT<char,0>::operator=(this: strTTText, strSrc: (ATL::CStringData *)&pButton->m_strText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041B31E
// Name: protected: void CMFCOutlookBarTabCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnPaint(CMFCOutlookBarTabCtrl *this)
{
  CDC *p_m_dcMem; // esi
  int m_nBorderSize; // edx
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // eax
  CFont *p_fontRegular; // eax
  CMFCVisualManager *Instance; // eax
  CAfxStringMgr *StringManager; // eax
  CMFCOutlookBarTabCtrl_vtbl *v10; // eax
  CMFCVisualManager *v11; // eax
  int v12; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-10Ch]
  int m_iActiveTab; // [esp-8h] [ebp-10Ch]
  CPoint result; // [esp+10h] [ebp-F4h] BYREF
  CPen v16; // [esp+18h] [ebp-ECh] BYREF
  CFont *v17; // [esp+20h] [ebp-E4h]
  int v18; // [esp+24h] [ebp-E0h]
  int w; // [esp+28h] [ebp-DCh] BYREF
  CFont *pFont; // [esp+2Ch] [ebp-D8h] BYREF
  CDC *m_dc; // [esp+30h] [ebp-D4h]
  CPaintDC v22; // [esp+34h] [ebp-D0h] BYREF
  CMemDC v23; // [esp+88h] [ebp-7Ch] BYREF
  tagRECT m_rectCaption; // [esp+C4h] [ebp-40h] BYREF
  RECT rc; // [esp+D4h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+E4h] [ebp-20h] BYREF
  int v27; // [esp+100h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v22, pWnd: this);
  v27 = 0;
  CMemDC::CMemDC(this: &v23, dc: &v22, pWnd: (HDC__ *)this);
  LOBYTE(v27) = 1;
  if ( v23.m_bMemDC != 0 )
  {
    p_m_dcMem = &v23.m_dcMem;
    m_dc = &v23.m_dcMem;
  }
  else
  {
    m_dc = v23.m_dc;
    p_m_dcMem = v23.m_dc;
  }
  v18 = this->GetVisibleTabsNum(this);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  FillRect(hDC: p_m_dcMem->m_hDC, lprc: &Rect, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
  if ( this->m_nBorderSize > 0 )
  {
    pFont = CDC::SelectObject(this: p_m_dcMem, pFont: (CFont *)&afxGlobalData.brBarFace);
    if ( pFont == nullptr )
      goto LABEL_6;
    PatBlt(
      hdc: p_m_dcMem->m_hDC,
      x: Rect.left,
      y: Rect.top,
      w: this->m_nBorderSize,
      h: Rect.bottom - Rect.top,
      rop: 0xF00021u);
    PatBlt(
      hdc: m_dc->m_hDC,
      x: Rect.left,
      y: Rect.top,
      w: Rect.right - Rect.left,
      h: this->m_nBorderSize,
      rop: 0xF00021u);
    m_nBorderSize = this->m_nBorderSize;
    w = m_nBorderSize + 1;
    PatBlt(
      hdc: m_dc->m_hDC,
      x: Rect.right - m_nBorderSize - 1,
      y: Rect.top,
      w: m_nBorderSize + 1,
      h: Rect.bottom - Rect.top,
      rop: 0xF00021u);
    PatBlt(
      hdc: m_dc->m_hDC,
      x: Rect.left,
      y: Rect.bottom - this->m_nBorderSize,
      w: Rect.right - Rect.left,
      h: this->m_nBorderSize,
      rop: 0xF00021u);
    CDC::SelectObject(this: m_dc, pFont);
    InflateRect(lprc: &Rect, dx: -this->m_nBorderSize, dy: -this->m_nBorderSize);
    p_m_dcMem = m_dc;
  }
  CDC::Draw3dRect(
    this: p_m_dcMem,
    lpRect: &Rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
  CPen::CPen(this: &v16, nPenStyle: 0, nWidth: 1, crColor: afxGlobalData.clrBarShadow);
  LOBYTE(v27) = 2;
  v17 = CDC::SelectObject(this: p_m_dcMem, pFont: (CFont *)&v16);
  if ( v17 == nullptr )
LABEL_6:
    AfxThrowInvalidArgException();
  CDC::MoveTo(this: p_m_dcMem, &result, x: this->m_rectWndArea.left - 1, y: this->m_rectWndArea.bottom);
  CDC::LineTo(this: p_m_dcMem, x: this->m_rectWndArea.right + 1, y: this->m_rectWndArea.bottom);
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  v6 = AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v5);
  if ( v6 == nullptr || (p_fontRegular = (CFont *)v6[228].__vftable) == nullptr )
    p_fontRegular = &afxGlobalData.fontRegular;
  result.y = (int)p_m_dcMem->SelectObject(this: p_m_dcMem, a2: p_fontRegular);
  CDC::SetBkMode(this: p_m_dcMem, nBkMode: 1);
  if ( v18 > 1 || this->IsHideSingleTab(this) == 0 )
  {
    for ( pFont = nullptr; (int)pFont < this->m_iTabsNum; pFont = (CFont *)((char *)pFont + 1) )
      CMFCOutlookBarTabCtrl::DrawTabButton(this, dc: p_m_dcMem, iButtonIdx: (int)pFont, bDrawPressedButton: 1);
  }
  if ( !IsRectEmpty(lprc: &this->m_rectCaption) )
  {
    rc.left = this->m_rectCaption.left;
    rc.top = this->m_rectCaption.top;
    rc.right = this->m_rectCaption.right;
    rc.top -= 5;
    ++rc.right;
    rc.bottom = rc.top + 5;
    FillRect(hDC: m_dc->m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
    w = afxGlobalData.clrBarText;
    Instance = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int *))Instance->OnFillOutlookBarCaption)(
      a1: Instance,
      a2: m_dc,
      a3: this->m_rectCaption.left,
      a4: this->m_rectCaption.top,
      a5: this->m_rectCaption.right,
      a6: this->m_rectCaption.bottom,
      a7: &w);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&pFont,
      pStringMgr: StringManager);
    v10 = this->__vftable;
    m_iActiveTab = this->m_iActiveTab;
    LOBYTE(v27) = 3;
    v10->GetTabLabel(
      this,
      a2: m_iActiveTab,
      a3: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pFont);
    m_rectCaption = (tagRECT)this->m_rectCaption;
    InflateRect(lprc: &m_rectCaption, dx: -CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN, dy: 0);
    p_m_dcMem = m_dc;
    m_dc->SetTextColor(this: m_dc, a2: w);
    p_m_dcMem->DrawTextA(
      this: p_m_dcMem,
      a2: (const char *)pFont,
      a3: (int)pFont[-2].m_hObject,
      a4: &m_rectCaption,
      a5: 32804u);
    LOBYTE(v27) = 2;
    ATL::CStringData::Release(this: (ATL::CStringData *)&pFont[-2]);
  }
  if ( !IsRectEmpty(lprc: &this->m_rectSplitter) )
  {
    v11 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int))v11->OnDrawOutlookBarSplitter)(
      a1: v11,
      a2: m_dc,
      a3: this->m_rectSplitter.left,
      a4: this->m_rectSplitter.top,
      a5: this->m_rectSplitter.right,
      a6: this->m_rectSplitter.bottom);
    p_m_dcMem = m_dc;
  }
  if ( this->m_bScrollButtons != 0
    && CMFCOutlookBarTabCtrl::IsMode2003(this) == 0
    && this->m_iActiveTab == this->m_iTabsNum - 1 )
  {
    v12 = Rect.bottom - this->m_nTabsHeight;
    m_rectCaption.left = Rect.left;
    m_rectCaption.right = Rect.right;
    m_rectCaption.bottom = Rect.bottom;
    m_rectCaption.top = v12;
    FillRect(hDC: m_dc->m_hDC, lprc: &m_rectCaption, hbr: (HBRUSH)afxGlobalData.brBarFace.m_hObject);
    p_m_dcMem = m_dc;
  }
  CDC::SelectObject(this: p_m_dcMem, pFont: v17);
  p_m_dcMem->SelectObject(this: p_m_dcMem, a2: (CFont *)result.y);
  LOBYTE(v27) = 1;
  v16.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &v16);
  LOBYTE(v27) = 0;
  CMemDC::~CMemDC(this: &v23);
  v27 = -1;
  CPaintDC::~CPaintDC(this: &v22);
}

//------------------------------------------------------------------------------
// Address: 0x1041B798
// Name: protected: virtual struct AFX_MSGMAP const __near * COutlookOptionsDlg::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COutlookOptionsDlg::GetMessageMap(COutlookOptionsDlg *this)
{
  return (const AFX_MSGMAP *)&off_1068EFD0;
}

//------------------------------------------------------------------------------
// Address: 0x1041B79E
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCOutlookBarTabCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCOutlookBarTabCtrl::GetMessageMap(CMFCOutlookBarTabCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1068F068;
}

//------------------------------------------------------------------------------
// Address: 0x1041B7A4
// Name: protected: void CMFCOutlookBarTabCtrl::RebuildToolBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::RebuildToolBar(CMFCOutlookBarTabCtrl *this)
{
  int cx; // ebx
  int cy; // eax
  CSize *v4; // eax
  int v5; // eax
  CMFCCustomizeButton *v6; // ecx
  CMFCOutlookBarToolBar_vtbl *v7; // eax
  CMFCCustomizeButton *data; // eax
  int v9; // eax
  void **v10; // eax
  void *v11; // ebx
  CMFCOutlookBarToolBar_vtbl *v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v13; // eax
  char *m_pszData; // ebx
  int v15; // eax
  HICON__ *IconA; // eax
  HICON__ *v17; // ebx
  CImageList *v18; // eax
  CSize v19; // [esp-14h] [ebp-1E0h]
  CMFCCustomizeButton *m_pCustomizeBtn; // [esp-4h] [ebp-1D0h]
  int iImage; // [esp+10h] [ebp-1BCh]
  _BYTE v22[4]; // [esp+14h] [ebp-1B8h] BYREF
  int nImage; // [esp+18h] [ebp-1B4h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCustomizeText; // [esp+1Ch] [ebp-1B0h] BYREF
  CMFCToolBarButton v25; // [esp+20h] [ebp-1ACh] BYREF
  CMFCCustomizeButton v26; // [esp+90h] [ebp-13Ch] BYREF
  int v27; // [esp+1C8h] [ebp-4h]

  if ( CMFCOutlookBarTabCtrl::IsMode2003(this) != 0 )
  {
    this->m_wndToolBar.RemoveAllButtons(this: &this->m_wndToolBar);
    CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_wndToolBar.m_TabButtons);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strCustomizeText,
      pszSrc: &var);
    v27 = 0;
    CMFCToolBar::EnableCustomizeButton(
      this: &this->m_wndToolBar,
      bEnable: 1,
      iCustomizeCmd: 0,
      &strCustomizeText,
      bQuickCustomize: 0);
    v27 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)strCustomizeText.m_pszData - 1);
    if ( this == (CMFCOutlookBarTabCtrl *)-600 || this->m_imagesToolbar.m_hImageList == nullptr )
    {
      v4 = this->GetImageSize(this, result: v22);
      cx = v4->cx;
      cy = v4->cy;
    }
    else
    {
      cx = this->m_sizeToolbarImage.cx;
      cy = this->m_sizeToolbarImage.cy;
    }
    nImage = cy;
    if ( cx == 0 && cy == 0 )
    {
      cx = 16;
      nImage = 16;
    }
    v19.cy = nImage + 14;
    v19.cx = cx + 6;
    CMFCToolBar::SetLockedSizes(
      this: &this->m_wndToolBar,
      sizeButton: v19,
      sizeImage: (CSize)__PAIR64__(nImage, cx),
      bDontScale: 0);
    CMFCToolBarImages::Clear(this: &this->m_wndToolBar.m_ImagesLocked);
    v5 = nImage;
    this->m_wndToolBar.m_ImagesLocked.m_sizeImage.cx = cx;
    this->m_wndToolBar.m_ImagesLocked.m_sizeImage.cy = v5;
    if ( this->m_wndToolBar.m_pCustomizeBtn != nullptr )
    {
      CMFCCustomizeButton::CMFCCustomizeButton(this: &v26);
      v26.__vftable = (CMFCCustomizeButton_vtbl *)&COutlookCustomizeButton::`vftable';
      m_pCustomizeBtn = this->m_wndToolBar.m_pCustomizeBtn;
      v27 = 1;
      CMFCCustomizeButton::CopyFrom(this: &v26, s: m_pCustomizeBtn);
      v26.m_bIsPipeStyle = 0;
      v26.m_bMenuRightAlign = 0;
      v26.m_bShowAtRightSide = 1;
      v26.m_pWndMessage = this;
      CObList::RemoveHead(this: &this->m_wndToolBar.m_Buttons);
      v6 = this->m_wndToolBar.m_pCustomizeBtn;
      if ( v6 != nullptr )
        ((void (__thiscall *)(CMFCCustomizeButton *, int))v6->dtr_CObject)(a1: v6, a2: 1);
      v7 = this->m_wndToolBar.__vftable;
      this->m_wndToolBar.m_pCustomizeBtn = nullptr;
      v7->InsertButton(this: &this->m_wndToolBar, a2: &v26, a3: -1);
      data = (CMFCCustomizeButton *)this->m_wndToolBar.m_Buttons.m_pNodeHead->data;
      v27 = -1;
      this->m_wndToolBar.m_pCustomizeBtn = data;
      CMFCCustomizeButton::~CMFCCustomizeButton(this: &v26);
    }
    v9 = 0;
    iImage = 0;
    for ( strCustomizeText.m_pszData = nullptr; v9 < this->m_iTabsNum; strCustomizeText.m_pszData = (char *)v9 )
    {
      if ( v9 < 0 || v9 >= this->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      v10 = &this->m_arTabs.m_pData[v9];
      v11 = *v10;
      if ( *((_DWORD *)*v10 + 13) == 0 || !IsRectEmpty(lprc: (const RECT *)v11 + 1) )
        goto LABEL_27;
      CMFCToolBarButton::CMFCToolBarButton(
        this: &v25,
        uiID: iImage + 61955,
        iImage,
        lpszText: *((const char **)v11 + 1),
        bUserButton: 0,
        bLocked: 0);
      v12 = this->m_wndToolBar.__vftable;
      v27 = 2;
      v12->InsertButton(this: &this->m_wndToolBar, a2: &v25, a3: -1);
      v13 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)CMap<int,int,int,int>::operator[](
                                                                                this: &this->m_wndToolBar.m_TabButtons,
                                                                                key: iImage);
      m_pszData = strCustomizeText.m_pszData;
      v13->m_pszData = strCustomizeText.m_pszData;
      v15 = this->GetTabIcon(this, a2: (int)m_pszData);
      nImage = v15;
      if ( this == (CMFCOutlookBarTabCtrl *)-600 || this->m_imagesToolbar.m_hImageList == nullptr )
      {
        v17 = this->GetTabHicon(this, a2: m_pszData);
        if ( v17 != nullptr )
          goto LABEL_26;
        v18 = (CImageList *)this->GetImageList(this);
        if ( v18 == nullptr || nImage == -1 )
          goto LABEL_26;
        IconA = CImageList::ExtractIconA(this: v18, nImage);
      }
      else
      {
        IconA = CImageList::ExtractIconA(this: &this->m_imagesToolbar, nImage: v15);
      }
      v17 = IconA;
LABEL_26:
      CMFCToolBarImages::AddIcon(this: &this->m_wndToolBar.m_ImagesLocked, hIcon: v17, bAlphaBlend: 0);
      ++iImage;
      v27 = -1;
      CMFCToolBarButton::~CMFCToolBarButton(this: &v25);
LABEL_27:
      v9 = (int)(strCustomizeText.m_pszData + 1);
    }
    this->m_wndToolBar.AdjustLocations(this: &this->m_wndToolBar);
    RedrawWindow(hWnd: this->m_wndToolBar.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041BAC1
// Name: public: virtual void CMFCOutlookBarTabCtrl::RecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::RecalcLayout(CMFCOutlookBarTabCtrl *this)
{
  int cy; // esi
  CSize *v3; // eax
  long double m_dblRibbonImageScale; // st6
  int v5; // ecx
  CMFCOutlookBarTabCtrl_vtbl *v6; // eax
  int v7; // eax
  int v8; // esi
  int m_nTabsHeight; // ecx
  int m_nVisiblePageButtons; // edx
  int top; // esi
  int v12; // ecx
  int bottom; // ecx
  int v14; // eax
  int v15; // eax
  tagRECT *v16; // eax
  int v17; // ecx
  int m_iActiveTab; // eax
  tagRECT *v19; // eax
  int right; // eax
  CMFCOutlookBarScrollButton *p_m_btnUp; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // esi
  _DWORD *v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  CObject **v30; // eax
  CObject *v31; // edi
  CObject *v32; // eax
  CObject *v33; // eax
  CObject *v34; // eax
  HWND Parent; // eax
  CWnd *v36; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-5Ch]
  int rectScroll_4; // [esp+Ch] [ebp-44h]
  int rectScroll_8; // [esp+10h] [ebp-40h]
  int rectScroll_12; // [esp+14h] [ebp-3Ch]
  char v41[4]; // [esp+18h] [ebp-38h] BYREF
  LPRECT lprc; // [esp+1Ch] [ebp-34h]
  CMFCTabInfo *pTab; // [esp+20h] [ebp-30h]
  tagRECT *v44; // [esp+24h] [ebp-2Ch]
  int y; // [esp+28h] [ebp-28h]
  int nVisibleTabsNum; // [esp+2Ch] [ebp-24h]
  int nToolBarHeight; // [esp+30h] [ebp-20h]
  int bIsMode2003; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  CRect rectClient; // [esp+3Ch] [ebp-14h] BYREF

  if ( this == nullptr || this->m_hWnd == nullptr || this->m_nTabsHeight == 0 )
    return;
  bIsMode2003 = CMFCOutlookBarTabCtrl::IsMode2003(this);
  nToolBarHeight = 0;
  if ( bIsMode2003 != 0 )
  {
    if ( this == (CMFCOutlookBarTabCtrl *)-600 || this->m_imagesToolbar.m_hImageList == nullptr )
    {
      v3 = this->GetImageSize(this, result: v41);
      cy = v3->cy;
      pTab = (CMFCTabInfo *)v3->cx;
    }
    else
    {
      cy = this->m_sizeToolbarImage.cy;
      pTab = (CMFCTabInfo *)this->m_sizeToolbarImage.cx;
    }
    if ( cy == 0 )
      cy = 16;
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
    else
      m_dblRibbonImageScale = 1.0;
    v5 = 12;
    if ( m_dblRibbonImageScale != 1.0 )
      v5 = (int)(m_dblRibbonImageScale * 12.0 + 0.5);
    nToolBarHeight = cy + v5;
  }
  SendMessageA(hWnd: this->m_btnUp.m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_btnDown.m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: -1 - this->m_nBorderSize, dy: -1 - this->m_nBorderSize);
  v6 = this->__vftable;
  this->m_rectWndArea = rectClient;
  v7 = v6->GetVisibleTabsNum(this);
  nVisibleTabsNum = v7;
  if ( bIsMode2003 != 0 )
  {
    v8 = v7;
    if ( this->m_nVisiblePageButtons == -1 )
      this->m_nVisiblePageButtons = v7;
    if ( this->m_nVisiblePageButtons > v7 )
      this->m_nVisiblePageButtons = v7;
    m_nTabsHeight = this->m_nTabsHeight;
    if ( v7 >= (rectClient.bottom - m_nTabsHeight - rectClient.top - nToolBarHeight) / (2 * m_nTabsHeight) )
      v8 = (rectClient.bottom - m_nTabsHeight - rectClient.top - nToolBarHeight) / (2 * m_nTabsHeight);
    m_nVisiblePageButtons = this->m_nVisiblePageButtons;
    this->m_nMaxVisiblePageButtons = v8;
    if ( v8 < m_nVisiblePageButtons )
      m_nVisiblePageButtons = v8;
    this->m_rectCaption = rectClient;
    top = this->m_rectCaption.top;
    v12 = nToolBarHeight + m_nVisiblePageButtons * m_nTabsHeight;
    this->m_rectCaption.bottom = afxGlobalData.m_nTextHeightHorz + top + 2 * CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN;
    this->m_rectCaption.top = top + 3;
    this->m_rectSplitter = rectClient;
    this->m_rectSplitter.bottom -= v12;
    bottom = this->m_rectCaption.bottom;
    v14 = this->m_rectSplitter.bottom - 8;
    this->m_rectSplitter.top = v14;
    this->m_rectWndArea.top = bottom;
    this->m_rectWndArea.bottom = v14;
  }
  else
  {
    SetRectEmpty(lprc: &this->m_rectCaption);
    SetRectEmpty(lprc: &this->m_rectSplitter);
    if ( nVisibleTabsNum <= 1 && this->IsHideSingleTab(this) != 0 )
      goto LABEL_32;
    InflateRect(lprc: &this->m_rectWndArea, dx: 0, dy: -1);
  }
  if ( bIsMode2003 == 0 )
  {
LABEL_32:
    v15 = rectClient.top;
    goto LABEL_33;
  }
  v15 = this->m_rectSplitter.bottom;
LABEL_33:
  y = v15;
  if ( nVisibleTabsNum > 1 || this->IsHideSingleTab(this) == 0 )
  {
    i = 0;
    if ( this->m_iTabsNum > 0 )
    {
      while ( i >= 0 && i < this->m_arTabs.m_nSize )
      {
        v16 = (tagRECT *)this->m_arTabs.m_pData[i];
        v17 = y;
        lprc = v16 + 1;
        v16[1] = rectClient.tagRECT;
        ++v16[1].right;
        v16[1].top = v17;
        v16[1].bottom = v17 + this->m_nTabsHeight;
        v44 = v16;
        if ( v17 >= rectClient.bottom - nToolBarHeight && bIsMode2003 != 0 )
        {
          SetRectEmpty(lprc);
          v16 = v44;
        }
        if ( v16[3].top != 0 )
        {
          if ( this->m_bScrollButtons != 0 && bIsMode2003 == 0 )
          {
            m_iActiveTab = this->m_iActiveTab;
            if ( i == m_iActiveTab || i == m_iActiveTab + 1 )
            {
              v19 = v44;
              rectScroll_4 = lprc->top;
              rectScroll_8 = lprc->right;
              rectScroll_12 = lprc->bottom;
              v44[1].right -= this->m_nTabsHeight;
              right = v19[1].right;
              if ( i == this->m_iActiveTab )
                p_m_btnUp = &this->m_btnUp;
              else
                p_m_btnUp = &this->m_btnDown;
              CWnd::SetWindowPos(
                this: p_m_btnUp,
                pWndInsertAfter: nullptr,
                x: right,
                y: rectScroll_4,
                cx: rectScroll_8 - right,
                cy: rectScroll_12 - rectScroll_4,
                nFlags: 0x14u);
            }
          }
          v22 = i;
          if ( i != this->m_iActiveTab || bIsMode2003 != 0 )
          {
            y += this->m_nTabsHeight;
          }
          else
          {
            v23 = this->m_nTabsHeight;
            this->m_rectWndArea.top = v23 + y;
            v24 = 0;
            while ( ++v22 < this->m_iTabsNum )
            {
              if ( v22 < 0 )
                goto LABEL_83;
              if ( v22 >= this->m_arTabs.m_nSize )
                goto LABEL_83;
              v25 = this->m_arTabs.m_pData[v22];
              if ( v25 == nullptr )
                goto LABEL_83;
              if ( v25[13] != 0 )
                ++v24;
            }
            v26 = v24 * v23;
            y = rectClient.bottom - v26 + 1;
            this->m_rectWndArea.bottom = rectClient.bottom - v26;
          }
        }
        else
        {
          SetRectEmpty(lprc);
        }
        if ( ++i >= this->m_iTabsNum )
          goto LABEL_63;
      }
LABEL_83:
      AfxThrowInvalidArgException();
    }
  }
LABEL_63:
  if ( this->m_bScrollButtons != 0 && bIsMode2003 == 0 && this->m_iActiveTab == nVisibleTabsNum - 1 )
  {
    v27 = this->m_nTabsHeight;
    v28 = rectClient.bottom;
    this->m_rectWndArea.bottom -= v27;
    CWnd::SetWindowPos(
      this: &this->m_btnDown,
      pWndInsertAfter: nullptr,
      x: rectClient.right - v27 + 1,
      y: v28 - v27 + 1,
      cx: v27,
      cy: v27,
      nFlags: 0x15u);
  }
  v29 = 0;
  lprc = nullptr;
  if ( this->m_iTabsNum > 0 )
  {
    while ( v29 >= 0 && v29 < this->m_arTabs.m_nSize )
    {
      v30 = (CObject **)this->m_arTabs.m_pData[v29];
      v31 = nullptr;
      v44 = (tagRECT *)v30;
      if ( v30[13] != nullptr )
      {
        v32 = AfxDynamicDownCast(pClass: &CDockablePaneAdapter::classCDockablePaneAdapter, pObject: v30[8]);
        if ( v32 != nullptr )
        {
          v33 = (CObject *)v32->__vftable[78].GetRuntimeClass(this: v32);
          v34 = AfxDynamicDownCast(pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane, pObject: v33);
          v31 = v34;
          if ( v34 != nullptr )
          {
            v34[1825].__vftable = (CObject_vtbl *)(this->m_rectWndArea.right - this->m_rectWndArea.left);
            v34[741].__vftable = (CObject_vtbl *)(this->m_rectWndArea.bottom - this->m_rectWndArea.top);
            if ( this->m_bDontAdjustLayout != 0 )
              v34[1832].__vftable = (CObject_vtbl *)1;
          }
        }
        CWnd::SetWindowPos(
          this: (CWnd *)v44[2].left,
          pWndInsertAfter: nullptr,
          x: this->m_rectWndArea.left,
          y: this->m_rectWndArea.top,
          cx: this->m_rectWndArea.right - this->m_rectWndArea.left,
          cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
          nFlags: 0x14u);
        if ( v31 != nullptr )
          v31[1832].__vftable = nullptr;
      }
      v29 = (int)&lprc->left + 1;
      lprc = (LPRECT)v29;
      if ( v29 >= this->m_iTabsNum )
        goto LABEL_78;
    }
    goto LABEL_83;
  }
LABEL_78:
  if ( nVisibleTabsNum != 0 || bIsMode2003 != 0 )
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
    if ( bIsMode2003 != 0 )
    {
      CWnd::ShowWindow(this: &this->m_wndToolBar, nCmdShow: 4);
      this->m_wndToolBar.SetWindowPos(
        this: &this->m_wndToolBar,
        a2: nullptr,
        a3: rectClient.left,
        a4: rectClient.bottom - nToolBarHeight,
        a5: rectClient.right - rectClient.left,
        a6: nToolBarHeight,
        a7: 20u,
        a8: nullptr);
      CMFCOutlookBarTabCtrl::RebuildToolBar(this);
      return;
    }
  }
  else
  {
    CWnd::ShowWindow(this, nCmdShow: 0);
  }
  CWnd::ShowWindow(this: &this->m_wndToolBar, nCmdShow: 0);
  RedrawWindow(hWnd: this->m_btnUp.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  RedrawWindow(hWnd: this->m_btnDown.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  Parent = GetParent(hWnd: this->m_hWnd);
  v36 = CWnd::FromHandle(hWnd: Parent);
  RedrawWindow(hWnd: v36->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1041C09C
// Name: protected: void CMFCRibbonQuickAccessToolBar::RebuildKeys(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonQuickAccessToolBar::RebuildKeys(CMFCRibbonQuickAccessToolBar *this)
{
  int v2; // esi
  CMFCRibbonBaseElement *v3; // ebx
  CAfxStringMgr *StringManager; // eax
  int v5; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKeys; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  v2 = 0;
  if ( this->m_arButtons.m_nSize - 1 > 0 )
  {
    v5 = 18;
    do
    {
      if ( v2 < 0 || v2 >= this->m_arButtons.m_nSize )
        AfxThrowInvalidArgException();
      v3 = this->m_arButtons.m_pData[v2];
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strKeys, pStringMgr: StringManager);
      v7 = 0;
      if ( v2 >= 9 )
      {
        if ( v2 >= 18 )
        {
          if ( v2 - 18 < 26 )
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
              this: &strKeys,
              pszFormat: "%c%c",
              (v2 - 18) / 26 + 48,
              (v2 - 18) % 26 + 97);
        }
        else
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strKeys, pszFormat: "0%d", v5);
        }
      }
      else
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strKeys, pszFormat: "%d", v2 + 1);
      }
      v3->SetKeys(this: v3, a2: strKeys.m_pszData, a3: nullptr);
      v7 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
      ++v2;
      --v5;
    }
    while ( v2 < this->m_arButtons.m_nSize - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C17F
// Name: protected: void CMFCRibbonQuickAccessToolBar::Add(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonQuickAccessToolBar::Add(CMFCRibbonQuickAccessToolBar *this, CMFCRibbonBaseElement *pElem)
{
  CRuntimeClass *v3; // eax
  CMFCRibbonBaseElement *Object; // esi

  v3 = (CRuntimeClass *)pElem->GetRuntimeClass(this: pElem);
  Object = (CMFCRibbonBaseElement *)CRuntimeClass::CreateObject(this: v3);
  Object->CopyFrom(this: Object, a2: pElem);
  Object->m_pRibbonBar = this->m_pRibbonBar;
  if ( pElem->m_pOriginal != nullptr )
    Object->SetOriginal(this: Object, a2: pElem->m_pOriginal);
  else
    Object->SetOriginal(this: Object, a2: pElem);
  Object->m_bQuickAccessMode = 1;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::InsertAt(
    this: &this->m_arButtons,
    nIndex: this->m_arButtons.m_nSize - 1,
    newElement: Object,
    nCount: 1);
  CMFCRibbonQuickAccessToolBar::RebuildKeys(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1F2
// Name: protected: int CMFCRibbonGallery::IsButtonLook(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonGallery::IsButtonLook(CMFCRibbonGallery *this)
{
  int result; // eax

  result = 0;
  if ( this->m_bQuickAccessMode != 0
    || this->m_bFloatyMode != 0
    || this->m_bIsButtonMode != 0
    || this->m_bIsCollapsed != 0
    || this->m_pParentGroup != nullptr
    || this->m_nIcons == 0 )
  {
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C21F
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonGalleryIcon::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonGalleryIcon::GetRuntimeClass(CMFCRibbonGalleryIcon *this)
{
  return &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon;
}

//------------------------------------------------------------------------------
// Address: 0x1041C225
// Name: public: CMFCRibbonGalleryIcon::CMFCRibbonGalleryIcon(class CMFCRibbonGallery __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonGalleryIcon *__thiscall CMFCRibbonGalleryIcon::CMFCRibbonGalleryIcon(
        CMFCRibbonGalleryIcon *this,
        CMFCRibbonGallery *pOwner,
        int nIndex)
{
  CMFCRibbonButton::CMFCRibbonButton(this);
  this->m_nIndex = nIndex;
  this->__vftable = (CMFCRibbonGalleryIcon_vtbl *)&CMFCRibbonGalleryIcon::`vftable';
  this->m_pOwner = pOwner;
  if ( pOwner != nullptr )
    this->m_pParent = pOwner->m_pParent;
  this->m_bIsFirstInRow = 0;
  this->m_bIsLastInRow = 0;
  this->m_bIsFirstInColumn = 0;
  this->m_bIsLastInColumn = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041C275
// Name: protected: virtual unsigned int CMFCRibbonGalleryIcon::GetQuickAccessToolBarID(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCRibbonGalleryIcon::GetQuickAccessToolBarID(CMFCRibbonGalleryIcon *this)
{
  CMFCRibbonGallery *m_pOwner; // eax

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
    return m_pOwner->m_nID;
  else
    return this->m_nID;
}

//------------------------------------------------------------------------------
// Address: 0x104303C2
// Name: protected: void CMFCTasksPane::OnUpdateForward(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnUpdateForward(CMFCTasksPane *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: this->m_iActivePage < this->m_arrHistoryStack.m_nSize - 1);
}
