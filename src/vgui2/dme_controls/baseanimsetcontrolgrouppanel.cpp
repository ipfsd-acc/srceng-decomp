// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseanimsetcontrolgrouppanel.cpp
// Functions: 103
// ============================================================

#include "vgui2\dme_controls\baseanimsetcontrolgrouppanel.h"

//------------------------------------------------------------------------------
// Address: 0x00491B70
// Name: public: static char const __near * CBaseAnimSetControlGroupPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetControlGroupPanel::GetPanelClassName()
{
  return "CBaseAnimSetControlGroupPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00491B80
// Name: public: static char const __near * CAnimGroupStateIconSet::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::GetPanelClassName()
{
  return "CAnimGroupStateIconSet";
}

//------------------------------------------------------------------------------
// Address: 0x00491B90
// Name: public: static char const __near * CAnimGroupStateIconSet::IconButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::IconButton::GetPanelClassName()
{
  return "IconButton";
}

//------------------------------------------------------------------------------
// Address: 0x00491BA0
// Name: public: virtual void CAnimGroupStateIconSet::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::PerformLayout(CAnimGroupStateIconSet *this)
{
  int Tall; // eax
  CAnimGroupStateIconSet::IconButton *m_pLockButton; // ecx

  Tall = vgui::Panel::GetTall(this);
  m_pLockButton = this->m_pLockButton;
  if ( m_pLockButton != nullptr )
    vgui::Panel::SetBounds(this: m_pLockButton, x: 1, y: 1, wide: Tall - 1, tall: Tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x00491BC0
// Name: public: void CAnimGroupStateIconSet::IconButtonRightClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButtonRightClick(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  bool bPosition; // [esp+13h] [ebp-1h]

  m_StateType = this->m_StateType;
  v3 = 1;
  if ( m_StateType == 1 || (bPosition = false, m_StateType == 2) )
    bPosition = true;
  if ( m_StateType != 1 && m_StateType != 3 )
    v3 = 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OpenLockContextMenu");
  else
    v5 = nullptr;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
  KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
  KeyValues::SetInt(this: v5, keyName: "position", value: bPosition);
  KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
  ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00491C80
// Name: private: virtual void CAnimGroupStateIconSet::OnLockDagButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnLockDagButton(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  bool bPosition; // [esp+13h] [ebp-1h]

  if ( this->m_pDag != nullptr )
  {
    m_StateType = this->m_StateType;
    v3 = 1;
    if ( m_StateType == 1 || (bPosition = false, m_StateType == 2) )
      bPosition = true;
    if ( m_StateType != 1 && m_StateType != 3 )
      v3 = 0;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ToggleDagLock");
    else
      v5 = nullptr;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
    KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
    KeyValues::SetInt(this: v5, keyName: "position", value: bPosition);
    KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
    ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491D50
// Name: public: static char const __near * CAnimGroupTree::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupTree::GetPanelClassName()
{
  return "CAnimGroupTree";
}

//------------------------------------------------------------------------------
// Address: 0x00491D60
// Name: public: enum TransformComponent_t CAnimGroupTree::GetItemComponentFlags(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::GetItemComponentFlags(CAnimGroupTree *this, int nTreeIndex)
{
  KeyValues *v2; // eax

  v2 = this->GetItemData(this, a2: nTreeIndex);
  return KeyValues::GetInt(this: v2, keyName: "componentFlags", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00491D90
// Name: public: virtual void CAnimGroupTree::GenerateContextMenu(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateContextMenu(CAnimGroupTree *this, int itemIndex, int x, int y)
{
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  CAnimGroupTree_vtbl *v7; // edi
  int v8; // eax

  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "TreeViewOpenContextMenu", firstKey: "itemID", firstValue: itemIndex);
  else
    v6 = nullptr;
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v6, a3: 0);
  ((void (__thiscall *)(CAnimGroupTree *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00491DF0
// Name: private: virtual void CAnimGroupTree::OnContextMenuSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnContextMenuSelection(CAnimGroupTree *this, int itemIndex)
{
  CAnimGroupTree_vtbl *v3; // edi
  char v4; // al

  v3 = this->__vftable;
  v4 = ((int (__thiscall *)(CAnimGroupTree *, int, int, int))this->IsItemSelected)(
         a1: this,
         a2: itemIndex,
         a3: 1,
         a4: 1);
  ((void (__thiscall *)(CAnimGroupTree *, int, bool))v3->AddSelectedItem)(a1: this, a2: itemIndex, a3: v4 == 0);
}

//------------------------------------------------------------------------------
// Address: 0x00491E30
// Name: private: virtual void CAnimGroupTree::OnClearWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnClearWorkCameraParent(CAnimGroupTree *this)
{
  CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00491E50
// Name: public: virtual void CAnimGroupTree::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::PaintBackground(CAnimGroupTree *this)
{
  int Tall; // edi

  vgui::Panel::PaintBackground(this);
  if ( this->m_bStateInterface )
  {
    Tall = vgui::Panel::GetTall(this);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_StateColumnColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: this->m_nStateColumnWidth, a5: Tall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491EA0
// Name: public: virtual void CAnimGroupTree::RemoveItem(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveItem(
        CAnimGroupTree *this,
        int itemIndex,
        bool bPromoteChildren,
        bool bRecursivelyRemove)
{
  KeyValues *v5; // eax
  void *Ptr; // eax

  v5 = this->GetItemData(this, a2: abs32(itemIndex));
  if ( v5 != nullptr )
  {
    Ptr = KeyValues::GetPtr(this: v5, keyName: "stateIconSet", defaultValue: nullptr);
    if ( Ptr != nullptr )
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
  }
  vgui::TreeView::RemoveItem(this, itemIndex, bPromoteChildren, bFullDelete: bRecursivelyRemove);
}

//------------------------------------------------------------------------------
// Address: 0x00491F00
// Name: public: virtual void CAnimGroupTree::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveAll(CAnimGroupTree *this)
{
  int i; // edi
  KeyValues *v3; // eax
  void *Ptr; // eax

  for ( i = this->FirstItem(this); i != this->InvalidItemID(this); i = this->NextItem(this, a2: i) )
  {
    v3 = this->GetItemData(this, a2: i);
    if ( v3 != nullptr )
    {
      Ptr = KeyValues::GetPtr(this: v3, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
    }
  }
  vgui::TreeView::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x00491F80
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: true);
}

//------------------------------------------------------------------------------
// Address: 0x00491F90
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: false);
}

//------------------------------------------------------------------------------
// Address: 0x00491FA0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::ClearSelection(this: this->m_pController);
}

//------------------------------------------------------------------------------
// Address: 0x004920B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetControlGroupPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetControlGroupPanel::GetMessageMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004920E0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetControlGroupPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetControlGroupPanel::GetAnimMap(CBaseAnimSetControlGroupPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004920F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetControlGroupPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetControlGroupPanel::GetKBMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492120
// Name: public: CAnimGroupStateIconSet::IconButton::IconButton(class CAnimGroupStateIconSet __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet::IconButton *__thiscall CAnimGroupStateIconSet::IconButton::IconButton(
        CAnimGroupStateIconSet::IconButton *this,
        CAnimGroupStateIconSet *pIconSet,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Button::Button(
    this,
    parent: pIconSet,
    panelName: pName,
    text: defaultValue,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CAnimGroupStateIconSet::IconButton_vtbl *)&CAnimGroupStateIconSet::IconButton::`vftable';
  if ( `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "IconButton");
    v4->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "IconButton");
    v5->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
    v6->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->m_pIconSet = pIconSet;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004921F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::IconButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::IconButton::GetMessageMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492220
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::IconButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::IconButton::GetAnimMap(CAnimGroupStateIconSet::IconButton *this)
{
  return FindOrAddPanelAnimationMap(className: "IconButton");
}

//------------------------------------------------------------------------------
// Address: 0x00492230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::IconButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::IconButton::GetKBMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492260
// Name: public: virtual void CAnimGroupStateIconSet::IconButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButton::OnMousePressed(
        CAnimGroupStateIconSet::IconButton *this,
        ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    CAnimGroupStateIconSet::IconButtonRightClick(this: this->m_pIconSet);
  else
    vgui::Button::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00492290
// Name: public: virtual void CAnimGroupStateIconSet::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::ApplySchemeSettings(CAnimGroupStateIconSet *this, vgui::IScheme *pScheme)
{
  CAnimGroupStateIconSet::IconButton_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color buttonColor; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, _DWORD))pScheme->GetColor)(
    a1: pScheme,
    a2: &buttonColor,
    a3: "Frame.BgColor",
    a4: 0);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: buttonColor);
  if ( this->m_pLockButton != nullptr )
  {
    v3 = this->m_pLockButton->__vftable;
    v4 = pScheme->GetBorder(this: pScheme, a2: "DepressedBorder");
    v3->SetDefaultBorder(this: this->m_pLockButton, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492310
// Name: private: static class CDmeDag const __near * CAnimGroupStateIconSet::GetDagFromDragElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
const CDmeDag *__cdecl CAnimGroupStateIconSet::GetDagFromDragElement(CDmeTransformControl *pElement)
{
  if ( pElement == nullptr )
    return nullptr;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return CDmeTransformControl::GetDag(this: pElement);
  }
  return ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
           a1: pElement,
           a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id)
       ? (const CDmeDag *)pElement
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492370
// Name: public: virtual void CAnimGroupTree::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::ApplySchemeSettings(CAnimGroupTree *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  CAnimGroupTree_vtbl *v6; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v8; // al
  int v9; // eax

  v2 = pScheme;
  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  pScheme = (vgui::IScheme *)-8355712;
  v5 = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "AnimSet.RootColor",
                   a4: -8355712);
  pScheme = nullptr;
  this->m_RootColor = v5;
  this->m_StateColumnColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, _DWORD))v2->GetColor)(
                                         a1: v2,
                                         a2: &pScheme,
                                         a3: "Frame.BgColor",
                                         a4: 0);
  v6 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v8 = IsProportional(this);
  v9 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
         a1: v2,
         a2: "DefaultBold",
         a3: v8);
  v6->SetFont(this, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x00492400
// Name: private: virtual void CAnimGroupTree::OnResetTransformPivot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnResetTransformPivot(CAnimGroupTree *this, int viewCenter)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  vgui::Panel *v5; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ResetTransformPivot", firstKey: "viewCenter", firstValue: viewCenter);
  else
    v4 = nullptr;
  v5 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: v5,
    a3: v4,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00492460
// Name: private: virtual void CAnimGroupTree::OnSetOverrideParent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnSetOverrideParent(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004924C0
// Name: private: virtual void CAnimGroupTree::OnOpenLockContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnOpenLockContextMenu(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00492550
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ApplySchemeSettings(CBaseAnimSetControlGroupPanel *this, int pScheme)
{
  int v2; // esi
  int (__thiscall *v4)(int, int *, const char *, int); // eax
  Color v5; // ecx
  int (__thiscall *v6)(int, int *, const char *, int); // edx
  vgui::Panel *v7; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
  pScheme = -2139062144;
  v5 = *(Color *)v4(a1: v2, a2: &pScheme, a3: "AnimSet.FullSelectionColor", a4: -2139062144);
  pScheme = 1077969024;
  this->m_FullSelectionColor = v5;
  this->m_PartialSelectionColor = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20))(
                                              a1: v2,
                                              a2: &pScheme,
                                              a3: "AnimSet.PartialSelectionColor",
                                              a4: 1077969024);
  v6 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
  pScheme = -16737793;
  this->m_ContextMenuHighlightColor = *(Color *)v6(
                                                  a1: v2,
                                                  a2: &pScheme,
                                                  a3: "AnimSet.ContextMenuSelectionColor",
                                                  a4: -16737793);
  v7 = vgui::PHandle::Get(this: &this->m_hGroups);
  v7->ApplySchemeSettings(this: v7, a2: (vgui::IScheme *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x004925F0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(
        CBaseAnimSetControlGroupPanel *this,
        int itemID)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax

  if ( itemID >= 0 )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v3->__vftable[1].GetAnimMap)(
      a1: v3,
      a2: itemID,
      a3: &this->m_ContextMenuHighlightColor);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = ((int (__thiscall *)(vgui::Panel *, int))v4->__vftable[1].IsWithinTraverse)(a1: v4, a2: itemID);
  v6 = vgui::PHandle::Get(this: &this->m_hEditor);
  ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].OnTick)(a1: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004926F0
// Name: public: void CAnimGroupStateIconSet::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::UpdateState(CAnimGroupStateIconSet *this)
{
  vgui::Tooltip *Tooltip; // ebx
  CDmeDag *m_pDag; // ecx
  CDmeDag *OverrideParent; // eax
  CDmeDag *v5; // edi
  CDmeDag *Parent; // eax
  int m_StateType; // ecx
  bool v8; // bl
  int v9; // edx
  int v10; // eax
  vgui::IImage *Image; // eax
  vgui::Tooltip *v12; // esi
  const wchar_t *v13; // eax
  const char *m_pAsString; // edi
  char tipText[64]; // [esp+4h] [ebp-6Ch] BYREF
  char itemText[32]; // [esp+44h] [ebp-2Ch] BYREF
  vgui::Tooltip *pTooltip; // [esp+64h] [ebp-Ch]
  int nPartialLockedIcon; // [esp+68h] [ebp-8h]
  bool bRot; // [esp+6Eh] [ebp-2h] BYREF
  bool bPos; // [esp+6Fh] [ebp-1h] BYREF

  if ( this->m_pDag == nullptr )
    return;
  this->m_pLockButton->ClearImages(this: this->m_pLockButton);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  m_pDag = this->m_pDag;
  pTooltip = Tooltip;
  bPos = false;
  bRot = false;
  OverrideParent = CDmeDag::GetOverrideParent(
                     this: m_pDag,
                     bPosition: (CDmeDag *)&bPos,
                     bRotation: &bRot,
                     bIgnoreEnable: 1);
  v5 = OverrideParent;
  if ( OverrideParent == nullptr )
  {
    vgui::Tooltip::SetTooltipDelay(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: Tooltip, text: "#LockButtonTip");
    return;
  }
  Parent = CDmeDag::GetParent(this: OverrideParent);
  m_StateType = this->m_StateType;
  v8 = Parent == nullptr;
  v9 = 2 * (Parent == nullptr) + 2;
  nPartialLockedIcon = 2 * (Parent == nullptr) + 3;
  v10 = 0;
  if ( m_StateType == 1 )
  {
    if ( !bPos || !bRot )
    {
      v10 = this->m_pImageIndexMap[nPartialLockedIcon];
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( m_StateType == 2 && bPos || m_StateType == 3 && bRot )
LABEL_11:
    v10 = this->m_pImageIndexMap[v9];
LABEL_12:
  Image = vgui::ImageList::GetImage(this: this->m_ImageList, imageIndex: v10);
  this->m_pLockButton->AddImage(this: this->m_pLockButton, a2: Image, a3: 0);
  v12 = pTooltip;
  if ( pTooltip != nullptr )
  {
    if ( v8 )
    {
      vgui::Tooltip::SetText(this: pTooltip, text: "#LockedToWorld");
    }
    else
    {
      v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#LockedTo");
      if ( v13 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v13, a3: itemText, a4: 32);
        m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: tipText, maxLen: 64, pFormat: "%s %s", itemText, m_pAsString);
        vgui::Tooltip::SetText(this: v12, text: tipText);
      }
    }
    vgui::Tooltip::SetTooltipDelay(this: v12, tooltipDelay: 750);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492880
// Name: public: virtual CAnimGroupTree::~CAnimGroupTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::~CAnimGroupTree(CAnimGroupTree *this)
{
  vgui::Panel *v2; // eax

  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x004928E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupTree::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupTree::GetMessageMap(CAnimGroupTree *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupTree::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupTree::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492910
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupTree::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupTree::GetAnimMap(CAnimGroupTree *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
}

//------------------------------------------------------------------------------
// Address: 0x00492920
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupTree::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupTree::GetKBMap(CAnimGroupTree *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupTree::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetKBMap'::`2'::s_pMap;
  `CAnimGroupTree::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492950
// Name: private: static bool CAnimGroupTree::CanAddDragIntoGroup(class CDmeControlGroup const __near *,class CDmElement const __near *,class CDmElement const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAnimGroupTree::CanAddDragIntoGroup(
        CDmeControlGroup *pTargetGroup,
        const CDmElement *pTargetElement,
        const CDmeControlGroup *pDragElement,
        bool bInsertBefore)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *v5; // esi
  char v6; // al
  CDmeControlGroup *Parent; // eax
  CDmeAnimationSet *pTargetGroupAnimSet; // [esp+Ch] [ebp-8h]
  char v10; // [esp+13h] [ebp-1h]

  if ( (_S1_3 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_3 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symControls, a3: "controls");
  }
  if ( pTargetGroup == nullptr || pDragElement == nullptr || pTargetElement == nullptr || pDragElement == pTargetGroup )
    return false;
  pTargetGroupAnimSet = CDmeControlGroup::FindAnimationSet(this: pTargetGroup, bSearchAncestors: true);
  v5 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: pDragElement);
  v6 = ((int (__thiscall *)(_DWORD, _DWORD))pTargetElement->IsA)(
         a1: (CDmElement *)pTargetElement,
         a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id);
  v10 = v6;
  if ( v5 == nullptr )
  {
    if ( !bInsertBefore || v6 == 0 )
      return FindReferringElement<CDmeAnimationSet>(
               pElement: pDragElement,
               symAttrName: symControls,
               bMustBeInSameFile: true,
               depth: TD_ALL) == pTargetGroupAnimSet;
    return false;
  }
  if ( CDmeControlGroup::IsAncestorOfGroup(this: v5, pGroup: pTargetGroup) || bInsertBefore && v10 == 0 )
    return false;
  Parent = CDmeControlGroup::FindParent(this: v5);
  if ( Parent != nullptr )
    return CDmeControlGroup::FindAnimationSet(this: Parent, bSearchAncestors: true) == pTargetGroupAnimSet;
  else
    return pTargetGroupAnimSet == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492A60
// Name: public: virtual void CAnimGroupTree::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAnimGroupTree::PerformLayout(CAnimGroupTree *this@<ecx>, int a2@<esi>)
{
  int i; // ebx
  KeyValues *v4; // eax
  CAnimGroupStateIconSet *Ptr; // esi
  int nPosX; // [esp+8h] [ebp-10h] BYREF
  int nWidth; // [esp+Ch] [ebp-Ch] BYREF
  int nPosY; // [esp+10h] [ebp-8h] BYREF
  int nHeight; // [esp+14h] [ebp-4h] BYREF

  vgui::TreeView::PerformLayout(this);
  for ( i = this->FirstItem(this);
        i != this->InvalidItemID(this);
        i = ((int (__thiscall *)(CAnimGroupTree *))this->NextItem)(a1: this) )
  {
    v4 = (KeyValues *)((int (__thiscall *)(CAnimGroupTree *, int, int))this->GetItemData)(a1: this, a2: i, a3: a2);
    if ( v4 != nullptr )
    {
      Ptr = (CAnimGroupStateIconSet *)KeyValues::GetPtr(this: v4, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
      {
        if ( vgui::TreeView::GetItemBounds(this, itemIndex: i, x: &nPosX, y: &nPosY, w: &nWidth, h: &nHeight) != 0 )
        {
          CAnimGroupStateIconSet::UpdateState(this: Ptr);
          vgui::Panel::SetBounds(this: Ptr, x: 0, y: nPosY, wide: nHeight, tall: nHeight);
          ((void (__stdcall *)(int))Ptr->SetVisible)(a1: 1);
        }
        else
        {
          ((void (__stdcall *)(_DWORD))Ptr->SetVisible)(a1: 0);
        }
      }
    }
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492B30
// Name: public: virtual bool CAnimGroupStateIconSet::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupStateIconSet::IsDroppable(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeTransformControl *v6; // esi
  const CDmeDag *DagFromDragElement; // eax
  CDmeDag *v8; // esi

  if ( msglist->m_Size != 1 )
    return false;
  Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v6 = (CDmeTransformControl *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
    v6 = nullptr;
  DagFromDragElement = CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v6);
  v8 = (CDmeDag *)DagFromDragElement;
  return DagFromDragElement != nullptr
      && CDmeDag::IsAncestorOfDag(this: this->m_pDag, pDag: DagFromDragElement) == 0
      && this->m_pDag != v8;
}

//------------------------------------------------------------------------------
// Address: 0x00492BC0
// Name: public: virtual void CAnimGroupStateIconSet::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnPanelDropped(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmeTransformControl *v5; // esi
  CExpressionCalculator *DagFromDragElement; // edi
  int m_StateType; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  int BufferType; // eax
  int v11; // eax
  CAnimGroupStateIconSet_vtbl *v12; // edi
  int v13; // eax
  bool bRotation; // [esp+1Bh] [ebp-1h]
  char bPosition_3; // [esp+27h] [ebp+Bh]

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v5 = (CDmeTransformControl *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    DagFromDragElement = (CExpressionCalculator *)CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v5);
    if ( DagFromDragElement != nullptr )
    {
      m_StateType = this->m_StateType;
      if ( m_StateType == 1 || (bPosition_3 = 0, m_StateType == 2) )
        bPosition_3 = 1;
      if ( m_StateType == 1 || (bRotation = false, m_StateType == 3) )
        bRotation = true;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetOverrideParent");
      else
        v9 = nullptr;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
      KeyValues::SetInt(this: v9, keyName: "targetDag", value: BufferType);
      v11 = CCodecBuffer_Block::GetBufferType(this: DagFromDragElement);
      KeyValues::SetInt(this: v9, keyName: "parentDag", value: v11);
      KeyValues::SetInt(this: v9, keyName: "position", value: bPosition_3 != 0);
      KeyValues::SetInt(this: v9, keyName: "rotation", value: bRotation);
      v12 = this->__vftable;
      v13 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(
              a1: this,
              a2: v9,
              a3: 0);
      ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v12->PostMessage)(a1: this, a2: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492D30
// Name: public: class CDmElement __near * CAnimGroupTree::GetTreeItemData(int,enum AnimTreeItemType_t __near *,class CDmeAnimationSet __near * __near *,class CDmeControlGroup __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAnimGroupTree::GetTreeItemData(
        CAnimGroupTree *this,
        int nTreeIndex,
        AnimTreeItemType_t *pItemType,
        CDmeAnimationSet **ppParentAnimationSet,
        CDmeControlGroup **ppControlGroup)
{
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CDmeAnimationSet *v9; // esi
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  DmElementHandle_t v13; // eax
  CDmElement *v14; // eax
  CDmElement *v15; // esi

  v5 = this->GetItemData(this, a2: nTreeIndex);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  if ( pItemType != nullptr )
    *pItemType = KeyValues::GetInt(this: v5, keyName: "itemType", defaultValue: 0);
  if ( ppParentAnimationSet != nullptr )
  {
    Int = KeyValues::GetInt(this: v6, keyName: "animset", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = (CDmeAnimationSet *)v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeAnimationSet::m_classType) )
      v9 = nullptr;
    *ppParentAnimationSet = v9;
  }
  if ( ppControlGroup != nullptr )
  {
    v10 = KeyValues::GetInt(this: v6, keyName: "controlgroup", defaultValue: -1);
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
    v12 = (CDmeControlGroup *)v11;
    if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
      v12 = nullptr;
    *ppControlGroup = v12;
  }
  v13 = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13);
  v15 = v14;
  if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmElement::m_classType) )
    return v15;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492E40
// Name: public: class CDmeControlGroup __near * CAnimGroupTree::GetControlGroupForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAnimGroupTree::GetControlGroupForTreeItem(CAnimGroupTree *this, int nItemIndex)
{
  KeyValues *v2; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmeAnimationSet *v5; // esi

  v2 = this->GetItemData(this, a2: nItemIndex);
  if ( v2 == nullptr )
    return nullptr;
  Int = KeyValues::GetInt(this: v2, keyName: "handle", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = (CDmeAnimationSet *)v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
    v5 = nullptr;
  if ( v5 == nullptr )
    return nullptr;
  if ( v5->IsA(this: v5, a2: CDmeAnimationSet::m_classType) )
    return (CDmeAnimationSet *)CDmeAnimationSet::GetRootControlGroup(this: v5);
  if ( v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492EF0
// Name: public: class CDmeDag __near * CAnimGroupTree::GetDagForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAnimGroupTree::GetDagForTreeItem(CAnimGroupTree *this, AnimTreeItemType_t nTreeItemIndex)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeTransformControl *v6; // esi
  CDmeTransform *Transform; // eax

  v2 = this->GetItemData(this, a2: nTreeItemIndex);
  v3 = v2;
  if ( v2 != nullptr
    && (KeyValues::GetInt(this: v2, keyName: "itemType", defaultValue: 0),
        Int = KeyValues::GetInt(this: v3, keyName: "handle", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = (CDmeTransformControl *)v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmElement::m_classType)
    && v6->IsA(this: v6, a2: CDmeTransformControl::m_classType)
    && (Transform = CDmeTransformControl::GetTransform(this: v6)) != nullptr )
  {
    return CDmeTransform::GetDag(this: Transform);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492FA0
// Name: public: virtual bool CAnimGroupTree::IsItemDroppable(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::IsItemDroppable(
        CAnimGroupTree *this,
        const CDmeControlGroup *nItemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CDmeAnimationSet *ControlGroupForTreeItem; // eax
  int m_Size; // ebx
  int v7; // edi
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  const CDmeControlGroup *v11; // esi
  CDmElement *pTargetElement; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *pTargetControlGroup; // [esp+10h] [ebp-8h]
  CDmeControlGroup *pParentControlGroup; // [esp+14h] [ebp-4h] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+20h] [ebp+8h]

  if ( msglist->m_Size == 0 )
    return 0;
  pParentControlGroup = nullptr;
  pTargetElement = CAnimGroupTree::GetTreeItemData(
                     this,
                     nTreeIndex: (int)nItemIndex,
                     pItemType: nullptr,
                     ppParentAnimationSet: nullptr,
                     ppControlGroup: &pParentControlGroup);
  if ( pTargetElement == nullptr )
    return 0;
  ControlGroupForTreeItem = CAnimGroupTree::GetControlGroupForTreeItem(this, (int)nItemIndex);
  pTargetControlGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
  pNewParentGroup = bInsertBefore ? pParentControlGroup : (CDmeControlGroup *)ControlGroupForTreeItem;
  m_Size = msglist->m_Size;
  v7 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = msglist->m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
    {
      if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr && pTargetControlGroup != nullptr )
        break;
      Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v11 = (const CDmeControlGroup *)v10;
      if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
        v11 = nullptr;
      if ( CAnimGroupTree::CanAddDragIntoGroup(
             pTargetGroup: pNewParentGroup,
             pTargetElement,
             pDragElement: v11,
             bInsertBefore) )
      {
        break;
      }
    }
    if ( ++v7 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004930A0
// Name: public: virtual void CAnimGroupTree::OnItemDropped(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnItemDropped(
        CAnimGroupTree *this,
        int nItemIndex,
        BOOL bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // esi
  CDmeAnimationSet *ControlGroupForTreeItem; // eax
  int v7; // eax
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int nMsgCount; // [esp+Ch] [ebp-20h]
  int iMsg; // [esp+10h] [ebp-1Ch]
  CDmeAnimationSet *pTargetAnimSet; // [esp+14h] [ebp-18h] BYREF
  CDmElement *pTargetElement; // [esp+18h] [ebp-14h]
  CDmeControlGroup *pTargetControlGroup; // [esp+1Ch] [ebp-10h]
  Color clr; // [esp+20h] [ebp-Ch] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+24h] [ebp-8h]
  Color defaultColor; // [esp+28h] [ebp-4h] BYREF

  v4 = msglist;
  if ( this->IsItemDroppable(this, a2: nItemIndex, a3: bInsertBefore, a4: msglist) )
  {
    clr = 0;
    pTargetAnimSet = nullptr;
    pTargetElement = CAnimGroupTree::GetTreeItemData(
                       this,
                       nTreeIndex: nItemIndex,
                       pItemType: nullptr,
                       ppParentAnimationSet: &pTargetAnimSet,
                       ppControlGroup: (CDmeControlGroup **)&clr);
    if ( pTargetElement != nullptr )
    {
      ControlGroupForTreeItem = CAnimGroupTree::GetControlGroupForTreeItem(this, nItemIndex);
      pTargetControlGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
      if ( bInsertBefore )
        pNewParentGroup = (CDmeControlGroup *)clr;
      else
        pNewParentGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
      g_pDataModel->StartUndo(this: g_pDataModel, a2: "Drop onto control group", a3: "Drop onto control group", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Drop onto control group", a3: 0, a4: 256);
      v7 = 0;
      nMsgCount = msglist->m_Size;
      iMsg = 0;
      if ( nMsgCount > 0 )
      {
        while ( 1 )
        {
          v8 = v4->m_Memory.m_pMemory[v7];
          if ( v8 != nullptr )
          {
            if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr )
            {
              defaultColor = 0;
              KeyValues::GetColor(this: v8, result: &clr, keyName: "color", &defaultColor);
              this->SetItemFgColor(this, a2: nItemIndex, a3: &clr);
              this->SetItemSelectionTextColor(this, a2: nItemIndex, a3: &clr);
              CDmeControlGroup::SetGroupColor(this: pTargetControlGroup, groupColor: &clr, bRecursive: false);
            }
            Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
            v11 = (CDmeControlGroup *)v10;
            if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
              v11 = nullptr;
            if ( CAnimGroupTree::CanAddDragIntoGroup(
                   pTargetGroup: pNewParentGroup,
                   pTargetElement,
                   pDragElement: v11,
                   bInsertBefore) )
            {
              if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
                CDmeControlGroup::AddChild(
                  this: pNewParentGroup,
                  pGroup: v11,
                  pInsertBeforeGroup: bInsertBefore ? pTargetControlGroup : nullptr);
              else
                CDmeControlGroup::AddControl(
                  this: pNewParentGroup,
                  pControl: v11,
                  pInsertBeforeControl: bInsertBefore ? pTargetElement : nullptr);
              if ( pTargetAnimSet != nullptr )
              {
                RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pTargetAnimSet);
                if ( RootControlGroup != nullptr )
                  CDmeControlGroup::DestroyEmptyChildren(this: RootControlGroup);
              }
            }
          }
          v7 = iMsg + 1;
          iMsg = v7;
          if ( v7 >= nMsgCount )
            break;
          v4 = msglist;
        }
      }
      g_pDataModel->FinishUndo(this: g_pDataModel);
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004932C0
// Name: public: virtual void CAnimGroupTree::GenerateDragDataForItem(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateDragDataForItem(CAnimGroupTree *this, int nItemIndex, KeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // edi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  int BufferType; // eax

  v3 = this->GetItemData(this, a2: nItemIndex);
  v4 = v3;
  if ( v3 != nullptr )
  {
    Int = KeyValues::GetInt(this: v3, keyName: "itemType", defaultValue: 0);
    v6 = KeyValues::GetInt(this: v4, keyName: "handle", defaultValue: -1);
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
    v8 = (CExpressionCalculator *)v7;
    if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) && Int != 3 )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493350
// Name: public: virtual void CAnimGroupTree::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnMousePressed(CAnimGroupTree *this, const char *code)
{
  int ItemUnderMouse; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CAnimGroupTree_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeTransformControl *v11; // edi
  CDmeDag *Dag; // eax
  int height; // [esp+24h] [ebp-18h] BYREF
  int width; // [esp+28h] [ebp-14h] BYREF
  int xPos; // [esp+2Ch] [ebp-10h] BYREF
  int yPos; // [esp+30h] [ebp-Ch] BYREF
  int my; // [esp+34h] [ebp-8h] BYREF
  int mx; // [esp+38h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
  vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
  ItemUnderMouse = vgui::TreeView::FindItemUnderMouse(this, mx, my);
  if ( this->IsItemIDValid(this, a2: ItemUnderMouse) )
  {
    vgui::TreeView::GetItemBounds(this, itemIndex: ItemUnderMouse, x: &xPos, y: &yPos, w: &width, h: &height);
    if ( mx < xPos || my < yPos || mx > width + xPos || my > height + yPos )
      ItemUnderMouse = -1;
  }
  if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    if ( code == (const char *)108 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(
               this: v4,
               setName: "TreeViewOpenContextMenu",
               firstKey: "itemID",
               firstValue: ItemUnderMouse);
      else
        v5 = nullptr;
      v6 = this->__vftable;
      v7 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
      ((void (__thiscall *)(CAnimGroupTree *, int))v6->PostMessage)(a1: this, a2: v7);
      return;
    }
LABEL_22:
    vgui::TreeView::OnMousePressed(this, code);
    return;
  }
  if ( !this->IsItemIDValid(this, a2: ItemUnderMouse) || mx >= this->m_nStateColumnWidth + 20 )
    goto LABEL_22;
  v8 = this->GetItemData(this, a2: ItemUnderMouse);
  if ( v8 != nullptr )
  {
    Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1);
    v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v11 = (CDmeTransformControl *)v10;
    if ( v10 != nullptr
      && v10->IsA(this: v10, a2: CDmElement::m_classType)
      && v11->IsA(this: v11, a2: CDmeTransformControl::m_classType) )
    {
      Dag = CDmeTransformControl::GetDag(this: v11);
      CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: Dag);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493530
// Name: public: virtual void CAnimGroupTree::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnTick(CAnimGroupTree *this)
{
  int v2; // ebx
  AnimTreeItemType_t v3; // edi
  vgui::Button_vtbl *v4; // edi
  vgui::IImage *Image; // eax
  int x; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int y; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = -1;
  y = (int)CBaseAnimationSetControl::GetWorkCameraParent(this: this->m_pGroupPanel->m_pController);
  if ( y != 0 )
  {
    v3 = this->FirstItem(this);
    if ( v3 != this->InvalidItemID(this) )
    {
      while ( CAnimGroupTree::GetDagForTreeItem(this, nTreeItemIndex: v3) != (CDmeDag *)y )
      {
        v3 = this->NextItem(this, a2: v3);
        if ( v3 == this->InvalidItemID(this) )
          goto LABEL_7;
      }
      v2 = v3;
    }
  }
LABEL_7:
  this->m_pWorkCameraParentButton->SetVisible(this: this->m_pWorkCameraParentButton, a2: v2 != -1);
  if ( v2 != -1 )
  {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    vgui::TreeView::GetItemBounds(this, itemIndex: v2, &x, &y, &w, &h);
    vgui::Panel::SetBounds(
      this: this->m_pWorkCameraParentButton,
      x: this->m_nStateColumnWidth + 1,
      y: y + 1,
      wide: h - 2,
      tall: h - 2);
    this->m_pWorkCameraParentButton->ClearImages(this: this->m_pWorkCameraParentButton);
    v4 = this->m_pWorkCameraParentButton->__vftable;
    Image = vgui::ImageList::GetImage(this: &this->m_Images, imageIndex: this->m_StateIconIndices[0]);
    v4->AddImage(this: this->m_pWorkCameraParentButton, a2: Image, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493660
// Name: private: bool CAnimGroupTree::VisibleControlsBelow_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::VisibleControlsBelow_R(CAnimGroupTree *this, CDmeControlGroup *pGroup)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int nNumChildren; // [esp+18h] [ebp+8h]

  if ( CBaseAnimationSetControl::IsControlGroupVisible(this: this->m_pGroupPanel->m_pController, pGroup) )
  {
    if ( pGroup->m_Controls.m_Storage.m_Size > 0 )
      return 1;
    v4 = 0;
    nNumChildren = pGroup->m_Children.m_Storage.m_Size;
    if ( nNumChildren > 0 )
    {
      while ( 1 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr
          && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType)
          && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v6) )
        {
          break;
        }
        if ( ++v4 >= nNumChildren )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004936F0
// Name: public: int CAnimGroupTree::FindChildItemForElement(int,class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindChildItemForElement(
        CAnimGroupTree *this,
        int nParentIndex,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v9; // eax
  const CDmElement *v10; // edi
  int v11; // eax
  int nChildren; // [esp+Ch] [ebp-Ch]
  int iChild; // [esp+10h] [ebp-8h]
  int nChildIndex; // [esp+14h] [ebp-4h]

  v5 = 0;
  nChildren = this->GetNumChildren(this, a2: nParentIndex);
  iChild = 0;
  if ( nChildren <= 0 )
    return -1;
  while ( 1 )
  {
    nChildIndex = this->GetChild(this, a2: nParentIndex, a3: v5);
    v6 = this->GetItemData(this, a2: nChildIndex);
    v7 = v6;
    if ( v6 != nullptr )
      break;
LABEL_12:
    iChild = ++v5;
    if ( v5 >= nChildren )
      return -1;
  }
  Int = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v10 = v9;
  if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmElement::m_classType) )
    v10 = nullptr;
  if ( v10 == pElement )
  {
    if ( nComponentFlags == TRANSFORM_COMPONENT_NONE )
      return nChildIndex;
    v11 = KeyValues::GetInt(this: v7, keyName: "componentFlags", defaultValue: 0);
    if ( v11 == nComponentFlags )
      return nChildIndex;
    if ( (nComponentFlags & v11) == nComponentFlags )
    {
      this->GenerateChildrenOfNode(this, a2: nChildIndex);
      if ( CAnimGroupTree::FindChildItemForElement(this, nParentIndex: nChildIndex, pElement, nComponentFlags) >= 0 )
        return nChildIndex;
    }
  }
  v5 = iChild;
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x00493800
// Name: public: int CAnimGroupTree::FindItemForElement(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindItemForElement(
        CAnimGroupTree *this,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  const CDmElement *v9; // esi
  int highest; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v4 = 0;
  highest = this->GetHighestItemID(this);
  i = 0;
  if ( highest <= 0 )
    return -1;
  while ( 1 )
  {
    if ( this->IsItemIDValid(this, a2: v4) )
    {
      v5 = this->GetItemData(this, a2: v4);
      v6 = v5;
      if ( v5 == nullptr )
        goto LABEL_11;
      Int = KeyValues::GetInt(this: v5, keyName: "handle", defaultValue: -1);
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      if ( v9 == pElement
        && (KeyValues::GetInt(this: v6, keyName: "componentFlags", defaultValue: 0) == nComponentFlags
         || nComponentFlags == TRANSFORM_COMPONENT_NONE) )
      {
        return i;
      }
      v4 = i;
    }
LABEL_11:
    i = ++v4;
    if ( v4 >= highest )
      return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004938D0
// Name: public: int CAnimGroupTree::BuildTreeToAnimationSet(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToAnimationSet(CAnimGroupTree *this, CDmeAnimationSet *pAnimationSet)
{
  int result; // eax
  int v4; // edi

  if ( pAnimationSet == nullptr )
    return -1;
  result = CAnimGroupTree::FindItemForElement(this, pElement: pAnimationSet, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( result < 0 )
  {
    v4 = this->GetRootItemIndex(this);
    this->GenerateChildrenOfNode(this, a2: v4);
    return CAnimGroupTree::FindChildItemForElement(
             this,
             nParentIndex: v4,
             pElement: pAnimationSet,
             nComponentFlags: TRANSFORM_COMPONENT_NONE);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00493930
// Name: public: int CAnimGroupTree::BuildTreeToGroup(class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToGroup(
        CAnimGroupTree *this,
        CDmeControlGroup *pGroup,
        CDmeAnimationSet *pAnimationSet)
{
  CDmeControlGroup *Parent; // eax
  int v7; // edi
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pGroup == nullptr || pAnimationSet == nullptr )
    return -1;
  nItemIndex = CAnimGroupTree::FindItemForElement(this, pElement: pGroup, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( nItemIndex < 0 )
  {
    if ( CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet) == pGroup )
      return CAnimGroupTree::BuildTreeToAnimationSet(this, pAnimationSet);
    Parent = CDmeControlGroup::FindParent(this: pGroup);
    v7 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: Parent, pAnimationSet);
    if ( v7 >= 0 )
    {
      this->GenerateChildrenOfNode(this, a2: v7);
      return CAnimGroupTree::FindChildItemForElement(
               this,
               nParentIndex: v7,
               pElement: pGroup,
               nComponentFlags: TRANSFORM_COMPONENT_NONE);
    }
  }
  return nItemIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004939C0
// Name: public: void CAnimGroupTree::BuildTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::BuildTreeToControl(
        CAnimGroupTree *this,
        const CDmElement *pControl,
        TransformComponent_t nComponentFlags)
{
  CDmeAnimationSet *Referring; // ebx
  int ItemForElement; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  int v8; // ebx
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pControl != nullptr )
  {
    Referring = FindReferringElement<CDmeAnimationSet>(
                  pElement: pControl,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring != nullptr )
    {
      ItemForElement = CAnimGroupTree::FindItemForElement(this, pElement: pControl, nComponentFlags);
      nItemIndex = ItemForElement;
      if ( ItemForElement >= 0 )
      {
LABEL_8:
        this->MakeItemVisible(this, a2: ItemForElement);
        return;
      }
      GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
      v8 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: GroupContainingControl, pAnimationSet: Referring);
      if ( v8 >= 0 )
      {
        this->GenerateChildrenOfNode(this, a2: v8);
        nItemIndex = CAnimGroupTree::FindChildItemForElement(
                       this,
                       nParentIndex: v8,
                       pElement: pControl,
                       nComponentFlags);
      }
      if ( nItemIndex >= 0 )
      {
        ItemForElement = nItemIndex;
        goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493A50
// Name: protected: void CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(int,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex,
        ESelectionMode selectionMode)
{
  vgui::Panel *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CDmeAnimationSet *v10; // eax
  CDmeControlGroup *v11; // eax
  CAnimGroupTree *v12; // eax
  TransformComponent_t ItemComponentFlags; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-4h]

  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v4->__vftable[1].IsWithinTraverse)(a1: v4, a2: itemIndex);
  v6 = v5;
  if ( v5 != nullptr )
  {
    itemType = KeyValues::GetInt(this: v5, keyName: "itemType", defaultValue: 0);
    Int = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
    {
      switch ( itemType )
      {
        case ANIMTREE_ITEM_ANIMSET:
          v10 = CastElement<CDmeAnimationSet>(pElement: v9);
          if ( v10 != nullptr )
            CBaseAnimationSetControl::SelectAnimationSet(this: this->m_pController, pAnimSet: v10, selectionMode);
          break;
        case ANIMTREE_ITEM_GROUP:
          v11 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: v9);
          if ( v11 != nullptr )
            CBaseAnimationSetControl::SelectControlGroup(this: this->m_pController, pGroup: v11, selectionMode);
          break;
        case ANIMTREE_ITEM_CONTROL:
          CBaseAnimationSetControl::SelectControl(
            this: this->m_pController,
            pControl: v9,
            selectionMode,
            nComponentFlags: TRANSFORM_COMPONENT_ALL,
            bExpandTree: false);
          break;
        case ANIMTREE_ITEM_COMPONENT:
          v12 = (CAnimGroupTree *)vgui::PHandle::Get(this: &this->m_hGroups);
          ItemComponentFlags = CAnimGroupTree::GetItemComponentFlags(this: v12, nTreeIndex: itemIndex);
          CBaseAnimationSetControl::SelectControl(
            this: this->m_pController,
            pControl: v9,
            selectionMode,
            nComponentFlags: ItemComponentFlags,
            bExpandTree: false);
          break;
        default:
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493B80
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ExpandTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandTreeToControl(
        CBaseAnimSetControlGroupPanel *this,
        const CDmElement *pSelection,
        TransformComponent_t nComponentFlags)
{
  CAnimGroupTree *v3; // eax

  v3 = (CAnimGroupTree *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_LastNavDirection);
  CAnimGroupTree::BuildTreeToControl(this: v3, pControl: pSelection, nComponentFlags);
}

//------------------------------------------------------------------------------
// Address: 0x00493BA0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex,
        int replaceSelection)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(
    this,
    itemIndex,
    selectionMode: (ESelectionMode)(replaceSelection == 0));
}

//------------------------------------------------------------------------------
// Address: 0x00493BC0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(this, itemIndex, selectionMode: SELECTION_REMOVE);
}

//------------------------------------------------------------------------------
// Address: 0x00493BE0
// Name: protected: void CBaseAnimSetControlGroupPanel::ExpandItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandItems(
        CBaseAnimSetControlGroupPanel *this,
        const CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes)
{
  int v2; // ebx
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  CDmElement *m_pElement; // edi
  CAnimGroupTree *v5; // eax
  int ItemForElement; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  int v11; // ebx
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v16; // eax
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  vgui::Panel *v20; // eax
  int nExpandedNodes; // [esp+Ch] [ebp-1Ch]
  int nChildren; // [esp+10h] [ebp-18h]
  TransformComponent_t expandedComponents; // [esp+14h] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+18h] [ebp-10h]
  int nItemIndex; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int v27; // [esp+24h] [ebp-4h]

  v2 = 0;
  nExpandedNodes = expandedNodes->m_Size;
  i = 0;
  if ( nExpandedNodes > 0 )
  {
    p_m_hGroups = &this->m_hGroups;
    do
    {
      m_pElement = expandedNodes->m_Memory.m_pMemory[v2].m_pElement;
      v5 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
      ItemForElement = CAnimGroupTree::FindItemForElement(
                         this: v5,
                         pElement: m_pElement,
                         nComponentFlags: TRANSFORM_COMPONENT_NONE);
      nItemIndex = ItemForElement;
      v7 = vgui::PHandle::Get(this: p_m_hGroups);
      if ( ItemForElement != ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].InstallMouseHandler)(a1: v7) )
      {
        v8 = vgui::PHandle::Get(this: p_m_hGroups);
        ((void (__thiscall *)(vgui::Panel *, int, int))v8->__vftable[1].dtr_Panel)(a1: v8, a2: ItemForElement, a3: 1);
        expandedComponents = expandedNodes->m_Memory.m_pMemory[v2].m_ComponentFlags;
        if ( expandedComponents != TRANSFORM_COMPONENT_NONE )
        {
          v9 = vgui::PHandle::Get(this: p_m_hGroups);
          nChildren = ((int (__thiscall *)(vgui::Panel *, int))v9->__vftable[1].PerformApplySchemeSettings)(
                        a1: v9,
                        a2: ItemForElement);
          v27 = 0;
          if ( nChildren > 0 )
          {
            while ( 1 )
            {
              v10 = vgui::PHandle::Get(this: p_m_hGroups);
              v11 = ((int (__thiscall *)(vgui::Panel *, int, int))v10->__vftable[1].PaintTraverse)(
                      a1: v10,
                      a2: ItemForElement,
                      a3: v27);
              v12 = vgui::PHandle::Get(this: p_m_hGroups);
              v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(
                                   a1: v12,
                                   a2: v11);
              v14 = v13;
              if ( v13 != nullptr )
              {
                childItemType = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
                Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
                v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
                if ( v16 != nullptr )
                  v16->IsA(this: v16, a2: CDmElement::m_classType);
              }
              v17 = vgui::PHandle::Get(this: p_m_hGroups);
              v18 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v17->__vftable[1].IsWithinTraverse)(
                                   a1: v17,
                                   a2: v11);
              v19 = KeyValues::GetInt(this: v18, keyName: "componentFlags", defaultValue: 0);
              if ( childItemType == ANIMTREE_ITEM_COMPONENT && (v19 & expandedComponents) != 0 )
              {
                v20 = vgui::PHandle::Get(this: p_m_hGroups);
                ((void (__thiscall *)(vgui::Panel *, int, int))v20->__vftable[1].dtr_Panel)(a1: v20, a2: v11, a3: 1);
              }
              if ( ++v27 >= nChildren )
                break;
              ItemForElement = nItemIndex;
            }
            v2 = i;
          }
        }
      }
      i = ++v2;
    }
    while ( v2 < nExpandedNodes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493D80
// Name: protected: enum SelectionState_t CBaseAnimSetControlGroupPanel::UpdateSelection_R(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection_R(
        CBaseAnimSetControlGroupPanel *this,
        Color nParentIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  vgui::Panel *v3; // eax
  int v4; // eax
  int v5; // ebx
  AnimTreeItemType_t v7; // edi
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // eax
  SelectionState_t updated; // eax
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v16; // eax
  CDmElement *v17; // edi
  CDmeAnimationSet *v18; // eax
  int SelectionState; // eax
  CDmeControlGroup *v20; // eax
  CAnimGroupTree *v21; // eax
  TransformComponent_t ItemComponentFlags; // eax
  vgui::Panel *v23; // eax
  KeyValues *v24; // eax
  int v25; // edi
  Color *p_m_PartialSelectionColor; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  vgui::Panel *v31; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-8h]
  AnimTreeItemType_t itemTypea; // [esp+Ch] [ebp-8h]

  p_m_hGroups = &this->m_hGroups;
  v3 = vgui::PHandle::Get(this: &this->m_hGroups);
  v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].InstallMouseHandler)(a1: v3);
  v5 = (int)nParentIndex;
  if ( nParentIndex == v4 )
    return 0;
  v7 = ANIMTREE_ITEM_ANIMSET;
  nParentIndex = 0;
  v8 = vgui::PHandle::Get(this: p_m_hGroups);
  itemType = ((int (__thiscall *)(vgui::Panel *, int))v8->__vftable[1].PerformApplySchemeSettings)(a1: v8, a2: v5);
  if ( itemType <= ANIMTREE_ITEM_ANIMSET )
  {
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(a1: v12, a2: v5);
    v14 = v13;
    if ( v13 == nullptr )
      return 0;
    itemTypea = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
    Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
    v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v17 = v16;
    if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmElement::m_classType) )
      return 0;
    switch ( itemTypea )
    {
      case ANIMTREE_ITEM_ANIMSET:
        v18 = CastElement<CDmeAnimationSet>(pElement: v17);
        if ( v18 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v18);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_GROUP:
        v20 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: v17);
        if ( v20 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pControlGroup: v20);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_CONTROL:
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: TRANSFORM_COMPONENT_ALL);
        goto LABEL_16;
      case ANIMTREE_ITEM_COMPONENT:
        v21 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
        ItemComponentFlags = CAnimGroupTree::GetItemComponentFlags(this: v21, nTreeIndex: v5);
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: ItemComponentFlags);
LABEL_16:
        nParentIndex = (Color)SelectionState;
        break;
      default:
        break;
    }
  }
  else
  {
    do
    {
      v9 = vgui::PHandle::Get(this: p_m_hGroups);
      v10 = ((int (__thiscall *)(vgui::Panel *, int, AnimTreeItemType_t))v9->__vftable[1].PaintTraverse)(
              a1: v9,
              a2: v5,
              a3: v7);
      updated = CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v10);
      nParentIndex = (Color)(updated | *(_DWORD *)&nParentIndex);
      ++v7;
    }
    while ( v7 < itemType );
  }
  v23 = vgui::PHandle::Get(this: p_m_hGroups);
  v24 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v23->__vftable[1].IsWithinTraverse)(a1: v23, a2: v5);
  v25 = (int)nParentIndex;
  if ( v24 != nullptr )
    KeyValues::SetInt(this: v24, keyName: "selection", value: *(_DWORD *)&nParentIndex);
  if ( v25 == 3 )
  {
    p_m_PartialSelectionColor = &this->m_PartialSelectionColor;
    goto LABEL_23;
  }
  if ( v25 == 2 )
  {
    p_m_PartialSelectionColor = &this->m_FullSelectionColor;
LABEL_23:
    nParentIndex = *p_m_PartialSelectionColor;
    v27 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v27->__vftable[1].GetMessageMap)(
      a1: v27,
      a2: v5,
      a3: &nParentIndex);
    v28 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v28->__vftable[1].GetAnimMap)(a1: v28, a2: v5, a3: &nParentIndex);
    v29 = vgui::PHandle::Get(this: p_m_hGroups);
    v29->SetSilentMode(this: v29, a2: true);
    v30 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD, _DWORD, _DWORD))v30->__vftable[1].RequestFocusPrev)(
      a1: v30,
      a2: v5,
      a3: 0,
      a4: 0,
      a5: 0);
    v31 = vgui::PHandle::Get(this: p_m_hGroups);
    v31->SetSilentMode(this: v31, a2: false);
  }
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x00493FD0
// Name: public: virtual bool CAnimGroupTree::CanCurrentlyEditLabel(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupTree::CanCurrentlyEditLabel(CAnimGroupTree *this, int nItemIndex)
{
  bool result; // al
  int v5; // edi
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int *m_pMemory; // edx
  int v8; // eax
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-18h] BYREF
  int nSelectedItems; // [esp+1Ch] [ebp-4h]
  int nParentIndex; // [esp+28h] [ebp+8h]

  result = this->IsItemSelected(this, a2: nItemIndex);
  if ( result )
  {
    v5 = 0;
    nParentIndex = this->GetItemParent(this, a2: nItemIndex);
    GetSelectedItems = this->GetSelectedItems;
    memset(&selectedItems, 0, sizeof(selectedItems));
    GetSelectedItems(this, a2: &selectedItems);
    m_pMemory = selectedItems.m_Memory.m_pMemory;
    nSelectedItems = selectedItems.m_Size;
    if ( selectedItems.m_Size > 0 )
    {
      do
      {
        v8 = m_pMemory[v5];
        if ( nItemIndex != v8 )
        {
          if ( this->GetItemParent(this, a2: v8) == nParentIndex )
          {
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selectedItems);
            return false;
          }
          m_pMemory = selectedItems.m_Memory.m_pMemory;
        }
        ++v5;
      }
      while ( v5 < nSelectedItems );
    }
    selectedItems.m_Size = 0;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        selectedItems.m_Memory.m_pMemory = nullptr;
      }
      selectedItems.m_Memory.m_nAllocationCount = 0;
    }
    selectedItems.m_pElements = m_pMemory;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004940C0
// Name: public: void CBaseAnimSetControlGroupPanel::UpdateSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection(CBaseAnimSetControlGroupPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  Color v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hGroups) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hGroups);
    v2->SetSilentMode(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v3->__vftable[1].RequestFocus)(a1: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4->SetSilentMode(this: v4, a2: false);
    v5 = vgui::PHandle::Get(this: &this->m_hGroups);
    v6 = (Color)((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].Think)(a1: v5);
    CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494190
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x200000002LL;
    LODWORD(v4.m[2][3]) = 2;
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "TreeViewItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][2]) = "itemIndex";
    LODWORD(v4.m[3][0]) = "replaceSelection";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494230
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemIndex";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004942D0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewStartRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494360
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewFinishRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004943F0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewItemSelectionCleared";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494480
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewOpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494520
// Name: public: static void CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded )
  {
    `CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LockDagButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004945B0
// Name: public: CAnimGroupStateIconSet::CAnimGroupStateIconSet(class vgui::Panel __near *,char const __near *,enum StateIconSetType_t,class CDmeDag __near *,class vgui::ImageList __near &,int const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet *__thiscall CAnimGroupStateIconSet::CAnimGroupStateIconSet(
        CAnimGroupStateIconSet *this,
        vgui::Panel *pParent,
        const char *pchName,
        StateIconSetType_t itemType,
        CDmeDag *pDag,
        vgui::ImageList *imageList,
        const int *pImageIndexMap)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAnimGroupStateIconSet::IconButton *v11; // eax
  CAnimGroupStateIconSet::IconButton *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::Tooltip *Tooltip; // eax
  vgui::Tooltip *v16; // edi
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "AnimGroupStateIconSet");
  this->__vftable = (CAnimGroupStateIconSet_vtbl *)&CAnimGroupStateIconSet::`vftable';
  if ( `CAnimGroupStateIconSet::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v8->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
    v9->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
    v10->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(a1: (int)&savedregs);
  this->m_ImageList = imageList;
  this->m_pImageIndexMap = pImageIndexMap;
  this->m_StateType = itemType;
  this->m_pDag = pDag;
  this->m_pLockButton = nullptr;
  v11 = (CAnimGroupStateIconSet::IconButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v11 != nullptr )
    v12 = CAnimGroupStateIconSet::IconButton::IconButton(this: v11, pIconSet: this, pName: "LockButton");
  else
    v12 = nullptr;
  this->m_pLockButton = v12;
  v12->SetVisible(this: v12, a2: true);
  this->m_pLockButton->AddActionSignalTarget_2(this: this->m_pLockButton, a2: this);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "LockDagButton");
  else
    v14 = nullptr;
  this->m_pLockButton->SetCommand(this: this->m_pLockButton, a2: v14);
  this->m_pLockButton->SetKeyBoardInputEnabled(this: this->m_pLockButton, a2: false);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  v16 = Tooltip;
  if ( Tooltip != nullptr )
  {
    vgui::Tooltip::SetTooltipDelay(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: v16, text: "#LockButtonTip");
    vgui::Tooltip::SetTooltipFormatToSingleLine(this: v16);
  }
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00494770
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::GetMessageMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004947A0
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::GetAnimMap(CAnimGroupStateIconSet *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
}

//------------------------------------------------------------------------------
// Address: 0x004947B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::GetKBMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004947E0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{1084,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ClearWorkCameraParent";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494870
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1088,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnResetTransformPivot";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "viewCenter";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494910
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1092,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ToggleDagLock";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004949A0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1096,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetOverrideParent";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494A30
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1100,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenLockContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494AC0
// Name: public: CAnimGroupTree::CAnimGroupTree(class vgui::Panel __near *,char const __near *,class CBaseAnimSetControlGroupPanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupTree *__thiscall CAnimGroupTree::CAnimGroupTree(
        CAnimGroupTree *this,
        vgui::Panel *parent,
        const char *panelName,
        CBaseAnimSetControlGroupPanel *groupPanel,
        bool bStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  vgui::IImage *v13; // eax
  vgui::IImage *v14; // eax
  vgui::IImage *v15; // eax
  vgui::IImage *v16; // eax
  vgui::IImage *v17; // eax
  vgui::IImage *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TreeView::TreeView(this, parent, panelName);
  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( `CAnimGroupTree::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v6->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
    v7->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
    v8->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  }
  CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pGroupPanel = groupPanel;
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_RootColor = (Color)-8355712;
  this->m_StateColumnColor = 0;
  this->m_nStateColumnWidth = 0;
  this->m_bStateInterface = bStateInterface;
  if ( bStateInterface )
  {
    this->m_nStateColumnWidth = 20;
    vgui::TreeView::SetTreeIndent(this, nIndentAmount: 18);
  }
  vgui::TreeView::SetShowRootNode(this, bRootVisible: false);
  vgui::TreeView::SetDragEnabledItems(this, state: true);
  vgui::TreeView::SetAllowLabelEditing(this, state: true);
  vgui::TreeView::SetEnableInsertDropLocation(this, bEnable: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "workCameraParent",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pWorkCameraParentButton = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pWorkCameraParentButton->AddActionSignalTarget_2(this: this->m_pWorkCameraParentButton, a2: this);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "ClearWorkCameraParent");
  else
    v12 = nullptr;
  this->m_pWorkCameraParentButton->SetCommand(this: this->m_pWorkCameraParentButton, a2: v12);
  this->m_pWorkCameraParentButton->SetKeyBoardInputEnabled(this: this->m_pWorkCameraParentButton, a2: false);
  v13 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_referenceframe_active", a3: 0);
  this->m_StateIconIndices[0] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v13);
  v14 = g_pVGuiSchemeManager->GetImage(
          this: g_pVGuiSchemeManager,
          a2: "tools/ifm/icon_referenceframe_active_hidden",
          a3: 0);
  this->m_StateIconIndices[1] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v14);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked", a3: 0);
  this->m_StateIconIndices[2] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v15);
  v16 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_grey", a3: 0);
  this->m_StateIconIndices[3] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v16);
  v17 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world", a3: 0);
  this->m_StateIconIndices[4] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v17);
  v18 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world_grey", a3: 0);
  this->m_StateIconIndices[5] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v18);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00494DA0
// Name: private: int CAnimGroupTree::AddItemToTree(enum AnimTreeItemType_t,char const __near *,int,class Color const __near &,class CDmElement __near *,class CDmeAnimationSet __near *,class CDmeControlGroup __near *,bool,enum SelectionState_t,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddItemToTree(
        CAnimGroupTree *this,
        AnimTreeItemType_t itemType,
        const char *label,
        int parentIndex,
        const Color *fg,
        CExpressionCalculator *pElement,
        CExpressionCalculator *pAnimSet,
        CExpressionCalculator *pControlGroup,
        Color bExpandable,
        SelectionState_t selection,
        TransformComponent_t nComponentFlags)
{
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  CDmeTransform *Transform; // eax
  StateIconSetType_t v16; // ebx
  CAnimGroupStateIconSet *v17; // eax
  CAnimGroupStateIconSet *v18; // eax
  int v19; // ebx
  void (__thiscall *SetItemSelectionBgColor)(vgui::TreeView *, int, const Color *); // edx
  DmElementHandle_t hElement; // [esp+24h] [ebp+18h]
  DmElementHandle_t hAnimSet; // [esp+28h] [ebp+1Ch]
  DmElementHandle_t hControlGroup; // [esp+2Ch] [ebp+20h]

  if ( pElement != nullptr )
    hElement = CCodecBuffer_Block::GetBufferType(this: pElement);
  else
    hElement = DMELEMENT_HANDLE_INVALID;
  if ( pAnimSet != nullptr )
    hAnimSet = CCodecBuffer_Block::GetBufferType(this: pAnimSet);
  else
    hAnimSet = DMELEMENT_HANDLE_INVALID;
  if ( pControlGroup != nullptr )
    hControlGroup = CCodecBuffer_Block::GetBufferType(this: pControlGroup);
  else
    hControlGroup = DMELEMENT_HANDLE_INVALID;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "item", firstKey: "text", firstValue: label);
  else
    v14 = nullptr;
  KeyValues::SetInt(this: v14, keyName: "droppable", value: 1);
  KeyValues::SetInt(this: v14, keyName: "itemType", value: itemType);
  KeyValues::SetInt(this: v14, keyName: "handle", value: hElement);
  KeyValues::SetInt(this: v14, keyName: "animset", value: hAnimSet);
  KeyValues::SetInt(this: v14, keyName: "controlgroup", value: hControlGroup);
  KeyValues::SetInt(this: v14, keyName: "selection", value: selection);
  KeyValues::SetInt(this: v14, keyName: "componentFlags", value: nComponentFlags);
  KeyValues::SetInt(this: v14, keyName: "Expand", value: bExpandable._color[0] != 0);
  if ( pElement != nullptr
    && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))pElement->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: pElement,
         a2: CDmeTransformControl::m_classType.u) != 0
    && (Transform = CDmeTransformControl::GetTransform(this: (CDmeTransformControl *)pElement)) != nullptr )
  {
    bExpandable = (Color)CDmeTransform::GetDag(this: Transform);
  }
  else
  {
    bExpandable = 0;
  }
  if ( this->m_bStateInterface )
  {
    v16 = STATE_ICON_SET_INVALID;
    if ( itemType == ANIMTREE_ITEM_COMPONENT )
    {
      if ( nComponentFlags == TRANSFORM_COMPONENT_POSITION )
      {
        v16 = STATE_ICON_SET_CONTROL_POSITION;
      }
      else if ( nComponentFlags == TRANSFORM_COMPONENT_ROTATION )
      {
        v16 = STATE_ICON_SET_CONTROL_ROTATION;
      }
    }
    else
    {
      v16 = itemType == ANIMTREE_ITEM_CONTROL;
    }
    if ( bExpandable != 0 && v16 != STATE_ICON_SET_INVALID )
    {
      v17 = (CAnimGroupStateIconSet *)MemAlloc_Alloc(nSize: 0x164u);
      if ( v17 != nullptr )
        v18 = CAnimGroupStateIconSet::CAnimGroupStateIconSet(
                this: v17,
                pParent: this,
                pchName: label,
                itemType: v16,
                pDag: *(CDmeDag **)&bExpandable,
                imageList: &this->m_Images,
                pImageIndexMap: this->m_StateIconIndices);
      else
        v18 = nullptr;
      KeyValues::SetPtr(this: v14, keyName: "stateIconSet", value: v18);
    }
  }
  v19 = this->AddItem(this, a2: v14, a3: parentIndex);
  this->SetItemFgColor(this, a2: v19, a3: fg);
  this->SetItemSelectionTextColor(this, a2: v19, a3: fg);
  this->SetSilentMode(this, a2: true);
  if ( selection == SEL_ALL )
  {
    bExpandable = (Color)-2139062144;
  }
  else
  {
    if ( selection != SEL_SOME )
    {
      SetItemSelectionBgColor = this->SetItemSelectionBgColor;
      bExpandable = (Color)0x80000000;
      SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
      this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
      this->RemoveSelectedItem(this, a2: v19);
      goto LABEL_37;
    }
    bExpandable = (Color)1077969024;
  }
  this->SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
  this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
  this->AddSelectedItem(this, a2: v19, a3: false, a4: false, a5: true);
LABEL_37:
  if ( (unsigned int)itemType <= ANIMTREE_ITEM_GROUP )
    this->SetLabelEditingAllowed(this, a2: v19, a3: true);
  this->SetSilentMode(this, a2: false);
  this->ExpandItem(this, a2: v19, a3: false);
  KeyValues::deleteThis(this: v14);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x00495070
// Name: public: virtual void CAnimGroupTree::GetSelectedItemsForDrag(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GetSelectedItemsForDrag(
        CAnimGroupTree *this,
        AnimTreeItemType_t nPrimaryDragItem,
        CUtlVector<int,CUtlMemory<int,int> > *list)
{
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int i; // esi
  int v6; // [esp-14h] [ebp-3Ch]
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-20h] BYREF
  int nNumSelected; // [esp+1Ch] [ebp-Ch]
  CDmeControlGroup *pParentGroup; // [esp+20h] [ebp-8h] BYREF
  CDmeControlGroup *pPrimaryParentGroup; // [esp+24h] [ebp-4h] BYREF

  GetSelectedItems = this->GetSelectedItems;
  memset(&selectedItems, 0, sizeof(selectedItems));
  GetSelectedItems(this, a2: &selectedItems);
  nNumSelected = selectedItems.m_Size;
  if ( selectedItems.m_Size > 0 )
  {
    pPrimaryParentGroup = nullptr;
    CAnimGroupTree::GetTreeItemData(
      this,
      nTreeIndex: nPrimaryDragItem,
      pItemType: &nPrimaryDragItem,
      ppParentAnimationSet: nullptr,
      ppControlGroup: &pPrimaryParentGroup);
    if ( nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
    {
      for ( i = 0; i < nNumSelected; ++i )
      {
        v6 = selectedItems.m_Memory.m_pMemory[i];
        pParentGroup = nullptr;
        CAnimGroupTree::GetTreeItemData(
          this,
          nTreeIndex: v6,
          pItemType: &nPrimaryDragItem,
          ppParentAnimationSet: nullptr,
          ppControlGroup: &pParentGroup);
        if ( pPrimaryParentGroup == pParentGroup && nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
          CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
            this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)list,
            elem: list->m_Size,
            src: (vgui::PageTab **)&selectedItems.m_Memory.m_pMemory[i]);
      }
    }
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selectedItems);
}

//------------------------------------------------------------------------------
// Address: 0x00495140
// Name: public: CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetControlGroupPanel *__thiscall CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
        CBaseAnimSetControlGroupPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor,
        bool bControlStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CBaseAnimationSetControl *Controller; // eax
  CAnimGroupTree *v10; // eax
  CAnimGroupTree *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::TreeView *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetControlGroupPanel_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v6->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
    v7->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
    v8->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hEditor.m_iPanelID = -1;
  this->m_hGroups.m_iPanelID = -1;
  this->m_pController = nullptr;
  this->m_FullSelectionColor = 0;
  this->m_PartialSelectionColor = 0;
  this->m_ContextMenuHighlightColor = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditor, pPanel: editor);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  v10 = (CAnimGroupTree *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = CAnimGroupTree::CAnimGroupTree(
            this: v10,
            parent: this,
            panelName: "AnimSetGroups",
            groupPanel: this,
            bStateInterface: bControlStateInterface);
  else
    v11 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v11);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hGroups, pPanel: v11);
  v12 = vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::Panel::SetAutoResize(
    this: v12,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v13 = (vgui::TreeView *)vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::TreeView::SetAllowMultipleSelections(this: v13, state: true);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "root");
  else
    v15 = nullptr;
  v16 = vgui::PHandle::Get(this: &this->m_hGroups);
  ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v16->__vftable[1].GetVPanel)(a1: v16, a2: v15, a3: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00495330
// Name: public: virtual void CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimSetControlGroupPanel::UpdateSelection(this: (CBaseAnimSetControlGroupPanel *)((char *)this - 380));
}

//------------------------------------------------------------------------------
// Address: 0x00495340
// Name: protected: void CBaseAnimSetControlGroupPanel::CollectExpandedItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::CollectExpandedItems(
        CBaseAnimSetControlGroupPanel *this,
        CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes,
        int nItemIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ebx
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  int v15; // edi
  vgui::Panel *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // esi
  DmElementHandle_t v19; // eax
  CDmElement *v20; // eax
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  int nChildren; // [esp+Ch] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+14h] [ebp-Ch]
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *pExpansionInfo; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  p_m_hGroups = &this->m_hGroups;
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = nItemIndex;
  if ( nItemIndex != ((int (__thiscall *)(vgui::Panel *))v4->__vftable[1].InstallMouseHandler)(a1: v4) )
  {
    v6 = vgui::PHandle::Get(this: p_m_hGroups);
    v7 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(
                        a1: v6,
                        a2: nItemIndex);
    v8 = v7;
    if ( v7 == nullptr
      || (KeyValues::GetInt(this: v7, keyName: "itemType", defaultValue: 0),
          Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1),
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
          v11 = v10,
          v10 == nullptr)
      || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
    {
      v11 = nullptr;
    }
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].SetVisible)(a1: v12, a2: nItemIndex) != 0 )
    {
      pExpansionInfo = nullptr;
      if ( v11 != nullptr )
      {
        pExpansionInfo = &expandedNodes->m_Memory.m_pMemory[CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>>::AddToTail(this: expandedNodes)];
        pExpansionInfo->m_pElement = v11;
        pExpansionInfo->m_ComponentFlags = TRANSFORM_COMPONENT_NONE;
      }
      v13 = vgui::PHandle::Get(this: p_m_hGroups);
      nChildren = ((int (__thiscall *)(vgui::Panel *, int))v13->__vftable[1].PerformApplySchemeSettings)(
                    a1: v13,
                    a2: nItemIndex);
      i = 0;
      if ( nChildren > 0 )
      {
        while ( 1 )
        {
          v14 = vgui::PHandle::Get(this: p_m_hGroups);
          v15 = ((int (__thiscall *)(vgui::Panel *, int, int))v14->__vftable[1].PaintTraverse)(a1: v14, a2: v5, a3: i);
          v16 = vgui::PHandle::Get(this: p_m_hGroups);
          v17 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].IsWithinTraverse)(
                               a1: v16,
                               a2: v15);
          v18 = v17;
          if ( v17 != nullptr )
          {
            childItemType = KeyValues::GetInt(this: v17, keyName: "itemType", defaultValue: 0);
            v19 = KeyValues::GetInt(this: v18, keyName: "handle", defaultValue: -1);
            v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v19);
            if ( v20 != nullptr )
              v20->IsA(this: v20, a2: CDmElement::m_classType);
          }
          if ( childItemType == ANIMTREE_ITEM_COMPONENT )
          {
            v21 = vgui::PHandle::Get(this: p_m_hGroups);
            if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v21->__vftable[1].SetVisible)(a1: v21, a2: v15) != 0
              && pExpansionInfo != nullptr )
            {
              v22 = vgui::PHandle::Get(this: p_m_hGroups);
              v23 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v22->__vftable[1].IsWithinTraverse)(
                                   a1: v22,
                                   a2: v15);
              pExpansionInfo->m_ComponentFlags |= KeyValues::GetInt(
                                                    this: v23,
                                                    keyName: "componentFlags",
                                                    defaultValue: 0);
            }
          }
          else
          {
            CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, expandedNodes, nItemIndex: v15);
          }
          if ( ++i >= nChildren )
            break;
          v5 = nItemIndex;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495530
// Name: public: int CAnimGroupTree::AddAnimationSetToTree(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddAnimationSetToTree(CAnimGroupTree *this, CDmeAnimationSet *pAnimSet)
{
  CDmeAnimationSet *v2; // edi
  CDmeControlGroup *RootControlGroup; // ebx
  bool v6; // zf
  char v7; // al
  const char *m_pAsString; // eax
  int parentIndex; // [esp+Ch] [ebp-8h]
  SelectionState_t selection; // [esp+10h] [ebp-4h]

  v2 = pAnimSet;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  if ( !CBaseAnimationSetControl::IsControlGroupVisible(
          this: this->m_pGroupPanel->m_pController,
          pGroup: RootControlGroup) )
    return -1;
  parentIndex = this->GetRootItemIndex(this);
  selection = CBaseAnimationSetControl::GetSelectionState(this: this->m_pGroupPanel->m_pController, pAnimSet: v2);
  pAnimSet = (CDmeAnimationSet *)this->m_RootColor;
  if ( !CDmeControlGroup::IsSelectable(this: RootControlGroup)
    || (v6 = !CDmeControlGroup::IsVisible(this: RootControlGroup), v7 = -1, v6) )
  {
    v7 = 64;
  }
  HIBYTE(pAnimSet) = v7;
  m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_ANIMSET,
           label: m_pAsString,
           parentIndex,
           fg: (const Color *)&pAnimSet,
           pElement: (CExpressionCalculator *)v2,
           pAnimSet: (CExpressionCalculator *)v2,
           pControlGroup: nullptr,
           bExpandable: (Color)1,
           selection,
           nComponentFlags: TRANSFORM_COMPONENT_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x004955F0
// Name: public: int CAnimGroupTree::AddControlGroupToTree(int,class CDmeControlGroup __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddControlGroupToTree(
        CAnimGroupTree *this,
        int parentIndex,
        CDmeControlGroup *pControlGroup,
        CExpressionCalculator *pParentGroup,
        CExpressionCalculator *pAnimSet)
{
  CDmeControlGroup *v5; // esi
  int SelectionState; // eax
  SelectionState_t v8; // ebx
  bool v9; // zf
  char v10; // al
  const char *m_pAsString; // eax

  v5 = pControlGroup;
  SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pGroupPanel->m_pController, pControlGroup);
  pControlGroup = (CDmeControlGroup *)v5->m_GroupColor.m_Storage;
  v8 = SelectionState;
  if ( !CDmeControlGroup::IsSelectable(this: v5) || (v9 = !CDmeControlGroup::IsVisible(this: v5), v10 = -1, v9) )
    v10 = 64;
  HIBYTE(pControlGroup) = v10;
  m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_GROUP,
           label: m_pAsString,
           parentIndex,
           fg: (const Color *)&pControlGroup,
           pElement: (CExpressionCalculator *)v5,
           pAnimSet,
           pControlGroup: pParentGroup,
           bExpandable: (Color)1,
           selection: v8,
           nComponentFlags: TRANSFORM_COMPONENT_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x00495670
// Name: public: int CAnimGroupTree::AddControlToTree(int,class CDmElement __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddControlToTree(
        CAnimGroupTree *this,
        int parentIndex,
        CExpressionCalculator *pControl,
        CDmeControlGroup *pControlGroup,
        CExpressionCalculator *pAnimSet)
{
  CExpressionCalculator *v5; // edi
  unsigned __int8 v6; // al
  CDmeControlGroup *v7; // ebx
  TransformComponent_t v8; // esi
  bool v9; // zf
  char v10; // al
  const char *m_nAllocationCount; // eax
  Color bTransformControl; // [esp+10h] [ebp-8h]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v5 = pControl;
  selection = CBaseAnimationSetControl::GetSelectionState(
                this: this->m_pGroupPanel->m_pController,
                (CDmElement *)pControl,
                componentFlags: TRANSFORM_COMPONENT_ALL);
  v6 = (*((int (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v5,
         a2: CDmeTransformControl::m_classType.u);
  v7 = pControlGroup;
  pControl = (CExpressionCalculator *)pControlGroup->m_ControlColor.m_Storage;
  bTransformControl._color[0] = v6;
  v8 = v6 != 0 ? TRANSFORM_COMPONENT_ALL : TRANSFORM_COMPONENT_NONE;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v9 = !CDmeControlGroup::IsVisible(this: v7), v10 = -1, v9) )
  {
    v10 = 64;
  }
  HIBYTE(pControl) = v10;
  m_nAllocationCount = (const char *)v5->m_varNames.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount == (const char *)-1 )
    m_nAllocationCount = defaultValue;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_CONTROL,
           label: m_nAllocationCount,
           parentIndex,
           fg: (const Color *)&pControl,
           pElement: v5,
           pAnimSet,
           pControlGroup: (CExpressionCalculator *)v7,
           bExpandable: bTransformControl,
           selection,
           nComponentFlags: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00495720
// Name: public: void CAnimGroupTree::AddTransformComponentsToTree(int,class CDmeTransformControl __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddTransformComponentsToTree(
        CAnimGroupTree *this,
        int nParentIndex,
        CDmeTransformControl *pControl,
        CDmeControlGroup *pControlGroup,
        CExpressionCalculator *pAnimSet,
        SelectionState_t nParentComponentFlags)
{
  char SelectionComponentFlags; // si
  CUtlSymbolLarge::<unnamed_type_u> v9; // eax
  bool v10; // zf
  unsigned __int8 v11; // al
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> *v15; // eax
  CFmtStrN<256> *v16; // eax
  SelectionState_t v17; // esi
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> *v19; // eax
  CFmtStrN<256> *v20; // eax
  int v21; // esi
  CExpressionCalculator *v22; // [esp-14h] [ebp-134h]
  CExpressionCalculator *v23; // [esp-10h] [ebp-130h]
  Color v24; // [esp-Ch] [ebp-12Ch]
  SelectionState_t v25; // [esp-8h] [ebp-128h]
  TransformComponent_t v26; // [esp-4h] [ebp-124h]
  CFmtStrN<256> v27; // [esp+Ch] [ebp-114h] BYREF
  SelectionState_t rotSelection; // [esp+118h] [ebp-8h]
  Color color; // [esp+11Ch] [ebp-4h] BYREF
  const char *pControla; // [esp+12Ch] [ebp+Ch]
  SelectionState_t pControlGroupa; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupb; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupc; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupd; // [esp+130h] [ebp+10h]
  SelectionState_t posSelection; // [esp+138h] [ebp+18h]

  SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                              this: this->m_pGroupPanel->m_pController,
                              pControl);
  v9.m_Id = (int)pControl->m_Name.m_Storage.u;
  pControla = defaultValue;
  if ( v9.m_Id != -1 )
    pControla = (const char *)v9.m_Id;
  color = pControlGroup->m_ControlColor.m_Storage;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v10 = !CDmeControlGroup::IsVisible(this: pControlGroup), v11 = -1, v10) )
  {
    v11 = 64;
  }
  color._color[3] = v11;
  if ( nParentComponentFlags == 63 )
  {
    if ( (SelectionComponentFlags & 7) == 7 )
      posSelection = SEL_ALL;
    else
      posSelection = 2 * ((SelectionComponentFlags & 7) != 0) + 1;
    v12 = SelectionComponentFlags & 0x38;
    if ( v12 == 56 )
      rotSelection = SEL_ALL;
    else
      rotSelection = 2 * (v12 > 0) + 1;
    v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v13->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      (CExpressionCalculator *)pControlGroup,
      bExpandable: (Color)1,
      selection: posSelection,
      nComponentFlags: TRANSFORM_COMPONENT_POSITION);
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION;
    v25 = rotSelection;
    v24 = (Color)1;
    v23 = (CExpressionCalculator *)pControlGroup;
    v22 = pAnimSet;
LABEL_36:
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v14->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet: v22,
      pControlGroup: v23,
      bExpandable: v24,
      selection: v25,
      nComponentFlags: v26);
    return;
  }
  if ( nParentComponentFlags != (SEL_SOME|0x4) )
  {
    if ( nParentComponentFlags != 56 )
      return;
    if ( (SelectionComponentFlags & 8) != 0 )
      pControlGroupc = SEL_ALL;
    else
      pControlGroupc = 2 * ((SelectionComponentFlags & 8) != 0) + 1;
    v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.x", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v19->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupc,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_X);
    if ( (SelectionComponentFlags & 0x10) != 0 )
      pControlGroupd = SEL_ALL;
    else
      pControlGroupd = 2 * ((SelectionComponentFlags & 0x10) != 0) + 1;
    v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.y", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v20->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupd,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_Y);
    if ( (SelectionComponentFlags & 0x20) != 0 )
      v21 = 2;
    else
      v21 = 1;
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.z", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION_Z;
    v25 = v21;
    v24 = 0;
    v23 = nullptr;
    v22 = pAnimSet;
    goto LABEL_36;
  }
  if ( (SelectionComponentFlags & 1) != 0 )
    pControlGroupa = SEL_ALL;
  else
    pControlGroupa = 2 * ((SelectionComponentFlags & 1) != 0) + 1;
  v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.x", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v15->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupa,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_X);
  if ( (SelectionComponentFlags & 2) != 0 )
    pControlGroupb = SEL_ALL;
  else
    pControlGroupb = 2 * ((SelectionComponentFlags & 2) != 0) + 1;
  v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.y", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v16->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupb,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Y);
  if ( (SelectionComponentFlags & 4) != 0 )
    v17 = SEL_ALL;
  else
    v17 = SEL_NONE;
  v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.z", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v18->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: v17,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Z);
}

//------------------------------------------------------------------------------
// Address: 0x00495A60
// Name: private: void CAnimGroupTree::AddDmeControlGroup(int,class CDmeAnimationSet __near *,class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddDmeControlGroup(
        CAnimGroupTree *this,
        int nParentItemIndex,
        CExpressionCalculator *pAnimationSet,
        CExpressionCalculator *pGroup)
{
  int v5; // ebx
  CDmElement *v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  CDmElement *v9; // eax
  CExpressionCalculator *v10; // esi
  int nControls; // [esp+20h] [ebp+10h]
  int nControlsa; // [esp+20h] [ebp+10h]

  v5 = 0;
  nControls = (int)pGroup[1].m_expr.m_Storage.m_Memory.m_pMemory;
  if ( nControls > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(pGroup->m_stack.m_Size + 4 * v5));
      v7 = (CDmeControlGroup *)v6;
      if ( v6 != nullptr
        && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType)
        && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v7) != 0 )
      {
        CAnimGroupTree::AddControlGroupToTree(
          this,
          parentIndex: nParentItemIndex,
          pControlGroup: v7,
          pParentGroup: pGroup,
          pAnimSet: pAnimationSet);
      }
      ++v5;
    }
    while ( v5 < nControls );
  }
  v8 = 0;
  nControlsa = pGroup[1].m_varNames.m_Size;
  if ( nControlsa > 0 )
  {
    do
    {
      v9 = g_pDataModel->GetElement(
             this: g_pDataModel,
             a2: *((_DWORD *)&pGroup[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v8));
      v10 = (CExpressionCalculator *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmElement::m_classType) )
        CAnimGroupTree::AddControlToTree(
          this,
          parentIndex: nParentItemIndex,
          pControl: v10,
          pControlGroup: (CDmeControlGroup *)pGroup,
          pAnimSet: pAnimationSet);
      ++v8;
    }
    while ( v8 < nControlsa );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495B40
// Name: public: virtual void CAnimGroupTree::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateChildrenOfNode(CAnimGroupTree *this, int itemIndex)
{
  CDmeAnimationSet *i; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  CDmElement *ElementKey; // eax
  CDmeAnimationSet *v7; // ebx
  bool v8; // al
  CDmElement *v9; // eax
  CDmeControlGroup *v10; // ebx
  SelectionState_t v11; // edi
  CExpressionCalculator *RootControlGroup; // eax
  CExpressionCalculator *v13; // eax
  CDmeTransformControl *v14; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-10h] BYREF
  int Int; // [esp+10h] [ebp-Ch]
  CDmElement *pElement; // [esp+14h] [ebp-8h]
  CDmeAnimationSet *pAnimationSet; // [esp+18h] [ebp-4h]

  if ( this->GetNumChildren(this, a2: itemIndex) <= 0 )
  {
    if ( itemIndex == this->GetRootItemIndex(this) )
    {
      itemType = (AnimTreeItemType_t)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pGroupPanel->m_pController);
      Int = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType) )
      {
        CAnimGroupTree::AddAnimationSetToTree(this, pAnimSet: i);
      }
    }
    else
    {
      v4 = this->GetItemData(this, a2: itemIndex);
      v5 = v4;
      if ( v4 != nullptr )
      {
        Int = KeyValues::GetInt(this: v4, keyName: "itemType", defaultValue: 0);
        pElement = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "handle");
        ElementKey = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "animset");
        v7 = (CDmeAnimationSet *)ElementKey;
        if ( ElementKey == nullptr
          || (v8 = ElementKey->IsA(this: ElementKey, a2: CDmeAnimationSet::m_classType), pAnimationSet = v7, !v8) )
        {
          pAnimationSet = nullptr;
        }
        v9 = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "controlgroup");
        v10 = (CDmeControlGroup *)v9;
        if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeControlGroup::m_classType) )
          v10 = nullptr;
        v11 = KeyValues::GetInt(this: v5, keyName: "componentFlags", defaultValue: 0);
        switch ( Int )
        {
          case 0:
            RootControlGroup = (CExpressionCalculator *)CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet);
            CAnimGroupTree::AddDmeControlGroup(
              this,
              nParentItemIndex: itemIndex,
              (CExpressionCalculator *)pAnimationSet,
              pGroup: RootControlGroup);
            break;
          case 1:
            v13 = (CExpressionCalculator *)CastElement<CDmeControlGroup>(pElement);
            CAnimGroupTree::AddDmeControlGroup(
              this,
              nParentItemIndex: itemIndex,
              (CExpressionCalculator *)pAnimationSet,
              pGroup: v13);
            break;
          case 2:
          case 3:
            v14 = CastElement<CDmeTransformControl>(pElement);
            if ( v14 != nullptr )
              CAnimGroupTree::AddTransformComponentsToTree(
                this,
                nParentIndex: itemIndex,
                pControl: v14,
                pControlGroup: v10,
                pAnimSet: (CExpressionCalculator *)pAnimationSet,
                nParentComponentFlags: v11);
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495D00
// Name: public: void CBaseAnimSetControlGroupPanel::RebuildTree(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::RebuildTree(CBaseAnimSetControlGroupPanel *this, bool bRestoreExpansion)
{
  vgui::Panel *v3; // eax
  int v4; // eax
  KeyValues *v5; // ebx
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *v6; // ecx
  vgui::Panel *v7; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // ebx
  vgui::Panel *v15; // eax
  vgui::Panel_vtbl *v16; // esi
  int v17; // eax
  vgui::Panel *v18; // eax
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  vgui::Panel *v23; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  CDmeAnimationSet *i; // eax
  CAnimGroupTree *v26; // eax
  vgui::Panel *v27; // eax
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ecx
  vgui::Panel *v29; // edi
  vgui::Panel *v30; // ebx
  vgui::Panel_vtbl *v31; // esi
  int v32; // eax
  CDmeAnimationSet *v33; // [esp-4h] [ebp-2Ch]
  CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > expandedNodes; // [esp+Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-8h] BYREF
  vgui::Panel *bRestoreExpansiona; // [esp+30h] [ebp+8h]

  if ( bRestoreExpansion )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].Repaint)(a1: v3);
    v5 = nullptr;
    v6 = nullptr;
    expandedNodes.m_Memory.m_pMemory = nullptr;
    expandedNodes.m_Memory.m_nAllocationCount = v4;
    expandedNodes.m_Memory.m_nGrowSize = 0;
    if ( v4 != 0 )
    {
      v6 = (CBaseAnimSetControlGroupPanel::ElementExpansion_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v4);
      expandedNodes.m_Memory.m_pMemory = v6;
    }
    expandedNodes.m_pElements = v6;
    expandedNodes.m_Size = 0;
    v7 = vgui::PHandle::Get(this: &this->m_hGroups);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].Think)(a1: v7);
    CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, &expandedNodes, nItemIndex: v8);
    v9 = vgui::PHandle::Get(this: &this->m_hGroups);
    v9->SetSilentMode(this: v9, a2: true);
    v10 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v10->__vftable[1].GetClipRect)(a1: v10);
    v11 = vgui::PHandle::Get(this: &this->m_hGroups);
    v11->SetSilentMode(this: v11, a2: false);
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v5 = KeyValues::KeyValues(this: v12, setName: "root");
    v13 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v13->__vftable[1].GetVPanel)(a1: v13, a2: v5, a3: -1);
    v14 = vgui::PHandle::Get(this: &this->m_hGroups);
    v15 = vgui::PHandle::Get(this: &this->m_hGroups);
    v16 = v15->__vftable;
    bRestoreExpansiona = v15;
    v17 = ((int (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].Think)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v16[1].dtr_Panel)(a1: bRestoreExpansiona, a2: v17);
    CBaseAnimSetControlGroupPanel::ExpandItems(this, &expandedNodes);
    CBaseAnimSetControlGroupPanel::UpdateSelection(this);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&expandedNodes);
  }
  else
  {
    v18 = vgui::PHandle::Get(this: &this->m_hGroups);
    v18->SetSilentMode(this: v18, a2: true);
    v19 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v19->__vftable[1].GetClipRect)(a1: v19);
    v20 = vgui::PHandle::Get(this: &this->m_hGroups);
    v20->SetSilentMode(this: v20, a2: false);
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "root");
    else
      v22 = nullptr;
    v23 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v23->__vftable[1].GetVPanel)(a1: v23, a2: v22, a3: -1);
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    if ( AnimationSetClip != nullptr )
    {
      traversal.m_pFilmClip = AnimationSetClip;
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        v33 = i;
        v26 = (CAnimGroupTree *)vgui::PHandle::Get(this: &this->m_hGroups);
        CAnimGroupTree::AddAnimationSetToTree(this: v26, pAnimSet: v33);
      }
      v27 = vgui::PHandle::Get(this: &this->m_hGroups);
      p_m_hGroups = &this->m_hGroups;
      v29 = v27;
      v30 = vgui::PHandle::Get(this: p_m_hGroups);
      v31 = v30->__vftable;
      v32 = ((int (__thiscall *)(vgui::Panel *, int))v29->__vftable[1].Think)(a1: v29, a2: 1);
      ((void (__thiscall *)(vgui::Panel *, int))v31[1].dtr_Panel)(a1: v30, a2: v32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495F50
// Name: public: virtual void CAnimGroupTree::OnLabelChanged(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnLabelChanged(
        CAnimGroupTree *this,
        CDmeControlGroup *nItemIndex,
        const char *pOldString,
        const char *pNewString)
{
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  CExpressionCalculator *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeControlGroup *RootControlGroup; // eax
  const char *v12; // esi
  CDmeControlGroup *v13; // edi
  int v14; // eax
  KeyValues *v15; // eax
  int BufferType; // eax
  vgui::Panel *v17; // eax
  CFmtStrN<256> newName; // [esp+30h] [ebp-124h] BYREF
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > childList; // [esp+13Ch] [ebp-18h] BYREF
  CAnimGroupTree *v20; // [esp+150h] [ebp-4h]
  CDmeControlGroup *pControlGroup; // [esp+15Ch] [ebp+8h]

  StartUndo = g_pDataModel->StartUndo;
  v6 = nullptr;
  v20 = this;
  StartUndo(this: g_pDataModel, a2: "Change group label", a3: "Change group label", a4: 0);
  v7 = this->GetItemData(this, a2: nItemIndex);
  if ( v7 == nullptr )
  {
    v8 = nullptr;
LABEL_8:
    pControlGroup = nullptr;
    goto LABEL_9;
  }
  Int = KeyValues::GetInt(this: v7, keyName: "handle", defaultValue: -1);
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v8 = (CExpressionCalculator *)v10;
  if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
    v8 = nullptr;
  if ( v8 == nullptr )
    goto LABEL_8;
  pControlGroup = (CDmeControlGroup *)v8;
  if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeControlGroup::m_classType.u) == 0 )
    goto LABEL_8;
LABEL_9:
  if ( v8 == nullptr
    || (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeAnimationSet::m_classType.u) == 0 )
  {
    v8 = nullptr;
  }
  if ( pControlGroup != nullptr )
  {
    RootControlGroup = CDmeControlGroup::FindRootControlGroup(this: pControlGroup);
    v12 = pNewString;
    v13 = RootControlGroup;
    if ( RootControlGroup != nullptr
      && CDmeControlGroup::FindChildByName(
           this: RootControlGroup,
           pchName: pNewString,
           recursive: true,
           pParentGroup: nullptr) != nullptr )
    {
      memset(&childList, 0, sizeof(childList));
      CDmeControlGroup::GetAllChildren(this: v13, childGroupList: &childList);
      v14 = GenerateUniqueNameIndex(prefix: v12, array: &childList, startindex: 0);
      CFmtStrN<256>::CFmtStrN<256>(this: &newName, pszFormat: "%s%d", v12, v14);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pNewString, a3: newName.m_szBuf);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: pControlGroup->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
      CBaseAnimSetControlGroupPanel::RebuildTree(this: v20->m_pGroupPanel, bRestoreExpansion: true);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&childList);
    }
    else
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pNewString, a3: v12);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: pControlGroup->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
    }
  }
  else if ( v8 != nullptr )
  {
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v6 = KeyValues::KeyValues(this: v15, setName: "SetAnimationSetName", firstKey: "text", firstValue: pNewString);
    BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
    KeyValues::SetInt(this: v6, keyName: "animset", value: BufferType);
    v17 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
    ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: v17,
      a3: v6,
      a4: 0);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x00496170
// Name: public: void CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(
        CBaseAnimSetControlGroupPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel::RebuildTree(this, bRestoreExpansion: false);
}

//------------------------------------------------------------------------------
// Address: 0x00608910
// Name: public: virtual class vgui::ListPanelItem __near * vgui::ListPanel::GetItemData(int)
// Source: json
//------------------------------------------------------------------------------
vgui::FastSortListPanelItem *__thiscall vgui::ListPanel::GetItemData(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00608BC0
// Name: public: virtual class vgui::IImage __near * vgui::ListPanel::GetCellImage(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ListPanel::GetCellImage(vgui::ListPanel *this, int itemID, int col)
{
  KeyValues *v4; // edi
  vgui::Button *m_pHeader; // ecx
  const char *v6; // eax
  int Int; // edi

  v4 = this->GetItem(this, a2: itemID);
  if ( v4 != nullptr
    && col >= 0
    && col < this->m_CurrentColumns.m_Size
    && (m_pHeader = this->m_ColumnsData.m_Memory.m_pMemory[this->m_CurrentColumns.m_Memory.m_pMemory[col]].m_Element.m_pHeader,
        (v6 = m_pHeader->GetName(this: m_pHeader)) != nullptr)
    && *v6 != 0
    && this->m_pImageList != nullptr
    && (Int = KeyValues::GetInt(this: v4, keyName: v6, defaultValue: 0),
        vgui::ImageList::IsValidIndex(this: this->m_pImageList, imageIndex: Int))
    && Int > 0 )
  {
    return vgui::ImageList::GetImage(this: this->m_pImageList, imageIndex: Int);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0060AD20
// Name: protected: virtual class vgui::Panel __near * vgui::ListPanel::GetCellRenderer(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::ListPanel::GetCellRenderer(vgui::ListPanel *this, int itemID, int col)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v4; // edi
  vgui::ListPanel_vtbl *v5; // edx
  vgui::ISchemeManager_vtbl *v6; // ebx
  int v7; // eax
  vgui::IScheme *v8; // eax
  vgui::Label *m_pLabel; // ecx
  vgui::Label::Alignment m_nContentAlignment; // edx
  KeyValues *v11; // eax
  vgui::TextImage *m_pTextImage; // ecx
  KeyValues *v13; // ebx
  void (__thiscall *SetText)(vgui::TextImage *, const wchar_t *, bool); // eax
  int v15; // eax
  int m_Size; // ecx
  int v17; // eax
  int *m_pMemory; // edx
  vgui::TextImage *v19; // eax
  vgui::TextImage_vtbl *v20; // edi
  int v21; // eax
  unsigned int (__thiscall *GetFocus)(vgui::IInput *); // eax
  unsigned int v23; // edi
  bool (__thiscall *HasFocus)(vgui::Panel *); // eax
  vgui::IPanel *v25; // ebx
  vgui::IPanel_vtbl *v26; // edi
  unsigned int v27; // eax
  bool v28; // al
  vgui::Label_vtbl *v29; // edi
  Color *v30; // eax
  vgui::TextImage *v31; // eax
  vgui::TextImage_vtbl *v32; // edi
  Color *Color; // eax
  int v34; // eax
  vgui::TextImage *v35; // ecx
  int Int; // eax
  vgui::TextImage *v37; // ecx
  vgui::FastSortListPanelItem *m_Element; // eax
  vgui::ImageList *m_pImageList; // ecx
  vgui::IImage *m_pIcon; // edi
  int m_nImageIndex; // edi
  int v43; // ecx
  int v44; // eax
  int *v45; // edx
  vgui::IImage *v46; // eax
  unsigned int v47; // edi
  bool (__thiscall *v48)(vgui::Panel *); // eax
  vgui::IPanel *v49; // ebx
  vgui::IPanel_vtbl *v50; // edi
  unsigned int v51; // eax
  vgui::Label_vtbl *v52; // edi
  Color *v53; // eax
  wchar_t tempText[256]; // [esp+Ch] [ebp-218h] BYREF
  int tall; // [esp+20Ch] [ebp-18h] BYREF
  int cw; // [esp+210h] [ebp-14h] BYREF
  KeyValues *item; // [esp+214h] [ebp-10h]
  unsigned int focus; // [esp+218h] [ebp-Ch] BYREF
  bool selected; // [esp+21Fh] [ebp-5h]
  vgui::IScheme *pScheme; // [esp+220h] [ebp-4h] BYREF

  v4 = &this->m_ColumnsData.m_Memory.m_pMemory[this->m_CurrentColumns.m_Memory.m_pMemory[col]];
  v5 = this->__vftable;
  v6 = g_pVGuiSchemeManager->__vftable;
  item = (KeyValues *)g_pVGuiSchemeManager;
  v7 = v5->GetScheme(this);
  v8 = v6->GetIScheme(this: (vgui::ISchemeManager *)item, a2: v7);
  m_pLabel = this->m_pLabel;
  m_nContentAlignment = v4->m_Element.m_nContentAlignment;
  pScheme = v8;
  m_pLabel->SetContentAlignment(this: m_pLabel, a2: m_nContentAlignment);
  if ( v4->m_Element.m_bTypeIsText )
  {
    this->GetCellText(this, a2: itemID, a3: col, a4: tempText, a5: 256);
    v11 = this->GetItem(this, a2: itemID);
    m_pTextImage = this->m_pTextImage;
    v13 = v11;
    SetText = m_pTextImage->SetText;
    item = v13;
    SetText(this: m_pTextImage, a2: tempText, a3: false);
    this->m_pTextImage->GetContentSize(this: this->m_pTextImage, a2: &cw, a3: &tall);
    v15 = vgui::Panel::GetWide(this: v4->m_Element.m_pHeader) - 5;
    if ( cw < v15 )
      v15 = cw;
    this->m_pTextImage->SetSize(this: this->m_pTextImage, a2: v15, a3: tall);
    this->m_pLabel->SetTextImageIndex(this: this->m_pLabel, a2: 0);
    this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: this->m_pTextImage, a4: 3);
    m_Size = this->m_SelectedItems.m_Size;
    v17 = 0;
    selected = false;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_SelectedItems.m_Memory.m_pMemory;
    while ( *m_pMemory != itemID )
    {
      ++v17;
      ++m_pMemory;
      if ( v17 >= m_Size )
        goto LABEL_8;
    }
    if ( v17 < 0 || (*((_BYTE *)this + 508) & 8) != 0 && col != this->m_iSelectedColumn )
    {
LABEL_8:
      if ( KeyValues::IsEmpty(this: v13, keyName: "cellcolor") )
      {
        Int = KeyValues::GetInt(this: v13, keyName: "disabled", defaultValue: 0);
        v37 = this->m_pTextImage;
        if ( Int != 0 )
          ((void (__stdcall *)(_DWORD))v37->SetColor)(a1: *(_DWORD *)&this->m_DisabledColor);
        else
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v37->SetColor)(a1: v37, a2: *(_DWORD *)&this->m_LabelFgColor);
      }
      else
      {
        v19 = this->m_pTextImage;
        pScheme = nullptr;
        v20 = v19->__vftable;
        v21 = (int)*KeyValues::GetColor(
                      this: v13,
                      result: (Color *)&focus,
                      keyName: "cellcolor",
                      defaultColor: (const Color *)&pScheme);
        ((void (__stdcall *)(int))v20->SetColor)(a1: v21);
      }
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
    }
    else
    {
      GetFocus = g_pVGuiInput->GetFocus;
      selected = true;
      v23 = GetFocus(this: g_pVGuiInput);
      HasFocus = this->HasFocus;
      focus = v23;
      if ( HasFocus(this)
        || v23 != 0
        && (v25 = g_pVGuiPanel,
            v26 = g_pVGuiPanel->__vftable,
            v27 = this->GetVParent(this),
            v28 = v26->HasParent(this: v25, a2: focus, a3: v27),
            v13 = item,
            v28) )
      {
        v29 = this->m_pLabel->__vftable;
        v30 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedBgColor", a4: pScheme);
      }
      else
      {
        v29 = this->m_pLabel->__vftable;
        v30 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedOutOfFocusBgColor", a4: pScheme);
      }
      ((void (__thiscall *)(vgui::Label *, _DWORD))v29->SetBgColor)(a1: this->m_pLabel, a2: *v30);
      if ( KeyValues::IsEmpty(this: v13, keyName: "cellcolor") )
      {
        v34 = KeyValues::GetInt(this: v13, keyName: "disabled", defaultValue: 0);
        v35 = this->m_pTextImage;
        if ( v34 != 0 )
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v35->SetColor)(
            a1: v35,
            a2: *(_DWORD *)&this->m_DisabledSelectionFgColor);
        else
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v35->SetColor)(
            a1: v35,
            a2: *(_DWORD *)&this->m_SelectionFgColor);
        this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
      }
      else
      {
        v31 = this->m_pTextImage;
        pScheme = nullptr;
        v32 = v31->__vftable;
        Color = KeyValues::GetColor(
                  this: v13,
                  result: (Color *)&focus,
                  keyName: "cellcolor",
                  defaultColor: (const Color *)&pScheme);
        v32->SetColor(this: this->m_pTextImage, a2: *Color);
        this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
      }
    }
    m_Element = this->m_DataItems.m_Memory.m_pMemory[itemID].m_Element;
    if ( col == 0 && m_Element->m_bImage )
    {
      m_pImageList = this->m_pImageList;
      if ( m_pImageList != nullptr )
      {
        m_pIcon = m_Element->m_pIcon;
        if ( m_pIcon != nullptr
          || (!selected
            ? (m_nImageIndex = m_Element->m_nImageIndex)
            : (m_nImageIndex = m_Element->m_nImageIndexSelected),
              vgui::ImageList::IsValidIndex(this: m_pImageList, imageIndex: m_nImageIndex)
           && (m_pIcon = vgui::ImageList::GetImage(this: this->m_pImageList, imageIndex: m_nImageIndex)) != nullptr) )
        {
          this->m_pLabel->SetTextImageIndex(this: this->m_pLabel, a2: 1);
          this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: m_pIcon, a4: 0);
          this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 1, a3: this->m_pTextImage, a4: 3);
          return this->m_pLabel;
        }
      }
    }
  }
  else
  {
    v43 = this->m_SelectedItems.m_Size;
    v44 = 0;
    if ( v43 <= 0 )
      goto LABEL_42;
    v45 = this->m_SelectedItems.m_Memory.m_pMemory;
    while ( *v45 != itemID )
    {
      ++v44;
      ++v45;
      if ( v44 >= v43 )
        goto LABEL_42;
    }
    if ( v44 < 0 || (*((_BYTE *)this + 508) & 8) != 0 && col != this->m_iSelectedColumn )
    {
LABEL_42:
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
    }
    else
    {
      v47 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
      v48 = this->HasFocus;
      focus = v47;
      if ( v48(this)
        || v47 != 0
        && (v49 = g_pVGuiPanel,
            v50 = g_pVGuiPanel->__vftable,
            v51 = this->GetVParent(this),
            v50->HasParent(this: v49, a2: focus, a3: v51)) )
      {
        v52 = this->m_pLabel->__vftable;
        v53 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedBgColor", a4: pScheme);
      }
      else
      {
        v52 = this->m_pLabel->__vftable;
        v53 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedOutOfFocusBgColor", a4: pScheme);
      }
      ((void (__thiscall *)(vgui::Label *, _DWORD))v52->SetBgColor)(a1: this->m_pLabel, a2: *v53);
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
    }
    v46 = this->GetCellImage(this, a2: itemID, a3: col);
    this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: v46, a4: 0);
  }
  return this->m_pLabel;
}

//------------------------------------------------------------------------------
// Address: 0x0060E3E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ListPanel::GetMessageMap(vgui::ListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ListPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ListPanel");
  `vgui::ListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060E410
// Name: public: virtual struct PanelAnimationMap __near * vgui::ListPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ListPanel::GetAnimMap(vgui::ListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0060E420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ListPanel::GetKBMap(vgui::ListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ListPanel::GetKBMap'::`2'::s_pMap;
  `vgui::ListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ListPanel");
  `vgui::ListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491FB0
// Name: class CDmeControlGroup const __near * CastElement<class CDmeControlGroup>(class CDmElement const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CDmeControlGroup *__cdecl CastElement<CDmeControlGroup>(const CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: (CDmElement *)pElement,
         a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id) )
  {
    return (const CDmeControlGroup *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492660
// Name: class CDmeAnimationSet __near * FindReferringElement<class CDmeAnimationSet>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl FindReferringElement<CDmeAnimationSet>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeAnimationSet *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10370C07
// Name: public: void CDockContext::UpdateState(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockContext::UpdateState(CDockContext *this, int *pFlag, int bNewValue)
{
  unsigned int m_dwDockStyle; // eax
  BOOL v5; // eax
  bool v6; // zf
  unsigned int CanDock; // eax

  if ( *pFlag != bNewValue )
  {
    *pFlag = bNewValue;
    m_dwDockStyle = this->m_dwDockStyle;
    v5 = (m_dwDockStyle & 0xA000) != 0 && (m_dwDockStyle & 0x5000) != 0 && this->m_bFlip != 0;
    v6 = this->m_bForceFrame == 0;
    this->m_bFlip = v5;
    if ( v6 )
      CanDock = CDockContext::CanDock(this);
    else
      CanDock = 0;
    this->m_dwOverDockStyle = CanDock;
    CDockContext::DrawFocusRect(this, bRemoveRect: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049DF40
// Name: public: static char const __near * CBaseAnimSetControlGroupPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetControlGroupPanel::GetPanelClassName()
{
  return "CBaseAnimSetControlGroupPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1049DF50
// Name: public: static char const __near * CAnimGroupStateIconSet::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::GetPanelClassName()
{
  return "CAnimGroupStateIconSet";
}

//------------------------------------------------------------------------------
// Address: 0x1049DF60
// Name: public: static char const __near * CAnimGroupStateIconSet::IconButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::IconButton::GetPanelClassName()
{
  return "IconButton";
}

//------------------------------------------------------------------------------
// Address: 0x1049DF70
// Name: public: virtual void CAnimGroupStateIconSet::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::PerformLayout(CAnimGroupStateIconSet *this)
{
  int Tall; // eax
  CAnimGroupStateIconSet::IconButton *m_pLockButton; // ecx

  Tall = vgui::Panel::GetTall(this);
  m_pLockButton = this->m_pLockButton;
  if ( m_pLockButton != nullptr )
    vgui::Panel::SetBounds(this: m_pLockButton, x: 1, y: 1, wide: Tall - 1, tall: Tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1049DF90
// Name: public: void CAnimGroupStateIconSet::IconButtonRightClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButtonRightClick(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  char v9; // [esp+13h] [ebp-1h]

  m_StateType = this->m_StateType;
  v3 = 1;
  if ( m_StateType == 1 || (v9 = 0, m_StateType == 2) )
    v9 = 1;
  if ( m_StateType != 1 && m_StateType != 3 )
    v3 = 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OpenLockContextMenu");
  else
    v5 = nullptr;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
  KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
  KeyValues::SetInt(this: v5, keyName: "position", value: v9 != 0);
  KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
  ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1049E050
// Name: private: virtual void CAnimGroupStateIconSet::OnLockDagButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnLockDagButton(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  char v9; // [esp+13h] [ebp-1h]

  if ( this->m_pDag != nullptr )
  {
    m_StateType = this->m_StateType;
    v3 = 1;
    if ( m_StateType == 1 || (v9 = 0, m_StateType == 2) )
      v9 = 1;
    if ( m_StateType != 1 && m_StateType != 3 )
      v3 = 0;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ToggleDagLock");
    else
      v5 = nullptr;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
    KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
    KeyValues::SetInt(this: v5, keyName: "position", value: v9 != 0);
    KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
    ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049E120
// Name: public: static char const __near * CAnimGroupTree::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupTree::GetPanelClassName()
{
  return "CAnimGroupTree";
}

//------------------------------------------------------------------------------
// Address: 0x1049E130
// Name: public: enum TransformComponent_t CAnimGroupTree::GetItemComponentFlags(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::GetItemComponentFlags(CAnimGroupTree *this, int nTreeIndex)
{
  KeyValues *v2; // eax

  v2 = this->GetItemData(this, a2: nTreeIndex);
  return KeyValues::GetInt(this: v2, keyName: "componentFlags", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1049E160
// Name: public: virtual void CAnimGroupTree::GenerateContextMenu(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateContextMenu(CAnimGroupTree *this, int itemIndex, int x, int y)
{
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  CAnimGroupTree_vtbl *v7; // edi
  int v8; // eax

  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "TreeViewOpenContextMenu", firstKey: "itemID", firstValue: itemIndex);
  else
    v6 = nullptr;
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v6, a3: 0);
  ((void (__thiscall *)(CAnimGroupTree *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1049E1C0
// Name: private: virtual void CAnimGroupTree::OnContextMenuSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnContextMenuSelection(CAnimGroupTree *this, int itemIndex)
{
  CAnimGroupTree_vtbl *v3; // edi
  char v4; // al

  v3 = this->__vftable;
  v4 = ((int (__thiscall *)(CAnimGroupTree *, int, int, int))this->IsItemSelected)(
         a1: this,
         a2: itemIndex,
         a3: 1,
         a4: 1);
  ((void (__thiscall *)(CAnimGroupTree *, int, bool))v3->AddSelectedItem)(a1: this, a2: itemIndex, a3: v4 == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1049E200
// Name: private: virtual void CAnimGroupTree::OnClearWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnClearWorkCameraParent(CAnimGroupTree *this)
{
  CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1049E220
// Name: public: virtual void CAnimGroupTree::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::PaintBackground(CAnimGroupTree *this)
{
  int Tall; // edi

  vgui::Panel::PaintBackground(this);
  if ( this->m_bStateInterface )
  {
    Tall = vgui::Panel::GetTall(this);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_StateColumnColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: this->m_nStateColumnWidth, a5: Tall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049E270
// Name: public: virtual void CAnimGroupTree::RemoveItem(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveItem(
        CAnimGroupTree *this,
        int itemIndex,
        bool bPromoteChildren,
        bool bRecursivelyRemove)
{
  KeyValues *v5; // eax
  void *Ptr; // eax

  v5 = this->GetItemData(this, a2: abs32(itemIndex));
  if ( v5 != nullptr )
  {
    Ptr = KeyValues::GetPtr(this: v5, keyName: "stateIconSet", defaultValue: nullptr);
    if ( Ptr != nullptr )
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
  }
  vgui::TreeView::RemoveItem(this, itemIndex, bPromoteChildren, bFullDelete: bRecursivelyRemove);
}

//------------------------------------------------------------------------------
// Address: 0x1049E2D0
// Name: public: virtual void CAnimGroupTree::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveAll(CAnimGroupTree *this)
{
  int i; // edi
  KeyValues *v3; // eax
  void *Ptr; // eax

  for ( i = this->FirstItem(this); i != this->InvalidItemID(this); i = this->NextItem(this, a2: i) )
  {
    v3 = this->GetItemData(this, a2: i);
    if ( v3 != nullptr )
    {
      Ptr = KeyValues::GetPtr(this: v3, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
    }
  }
  vgui::TreeView::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1049E350
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: true);
}

//------------------------------------------------------------------------------
// Address: 0x1049E360
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049E370
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::ClearSelection(this: this->m_pController);
}

//------------------------------------------------------------------------------
// Address: 0x1049E470
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetControlGroupPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetControlGroupPanel::GetMessageMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049E4A0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetControlGroupPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetControlGroupPanel::GetAnimMap(CBaseAnimSetControlGroupPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1049E4B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetControlGroupPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetControlGroupPanel::GetKBMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049E4E0
// Name: public: CAnimGroupStateIconSet::IconButton::IconButton(class CAnimGroupStateIconSet __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet::IconButton *__thiscall CAnimGroupStateIconSet::IconButton::IconButton(
        CAnimGroupStateIconSet::IconButton *this,
        CAnimGroupStateIconSet *pIconSet,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Button::Button(
    this,
    parent: pIconSet,
    panelName: pName,
    text: &var,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CAnimGroupStateIconSet::IconButton_vtbl *)&CAnimGroupStateIconSet::IconButton::`vftable';
  if ( `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "IconButton");
    v4->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "IconButton");
    v5->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
    v6->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->m_pIconSet = pIconSet;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049E5B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::IconButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::IconButton::GetMessageMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049E5E0
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::IconButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::IconButton::GetAnimMap(CAnimGroupStateIconSet::IconButton *this)
{
  return FindOrAddPanelAnimationMap(className: "IconButton");
}

//------------------------------------------------------------------------------
// Address: 0x1049E5F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::IconButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::IconButton::GetKBMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049E620
// Name: public: virtual void CAnimGroupStateIconSet::IconButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButton::OnMousePressed(
        CAnimGroupStateIconSet::IconButton *this,
        ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    CAnimGroupStateIconSet::IconButtonRightClick(this: this->m_pIconSet);
  else
    vgui::Button::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1049E650
// Name: public: virtual void CAnimGroupStateIconSet::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::ApplySchemeSettings(CAnimGroupStateIconSet *this, vgui::IScheme *pScheme)
{
  CAnimGroupStateIconSet::IconButton_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color buttonColor; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, _DWORD))pScheme->GetColor)(
    a1: pScheme,
    a2: &buttonColor,
    a3: "Frame.BgColor",
    a4: 0);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: buttonColor);
  if ( this->m_pLockButton != nullptr )
  {
    v3 = this->m_pLockButton->__vftable;
    v4 = pScheme->GetBorder(this: pScheme, a2: "DepressedBorder");
    v3->SetDefaultBorder(this: this->m_pLockButton, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049E6D0
// Name: private: static class CDmeDag const __near * CAnimGroupStateIconSet::GetDagFromDragElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
const CDmeDag *__cdecl CAnimGroupStateIconSet::GetDagFromDragElement(CDmeTransformControl *pElement)
{
  if ( pElement == nullptr )
    return nullptr;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return CDmeTransformControl::GetDag(this: pElement);
  }
  return ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
           a1: pElement,
           a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id)
       ? (const CDmeDag *)pElement
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1049E730
// Name: public: virtual void CAnimGroupTree::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::ApplySchemeSettings(CAnimGroupTree *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  CAnimGroupTree_vtbl *v6; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v8; // al
  int v9; // eax

  v2 = pScheme;
  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  pScheme = (vgui::IScheme *)-8355712;
  v5 = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "AnimSet.RootColor",
                   a4: -8355712);
  pScheme = nullptr;
  this->m_RootColor = v5;
  this->m_StateColumnColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, _DWORD))v2->GetColor)(
                                         a1: v2,
                                         a2: &pScheme,
                                         a3: "Frame.BgColor",
                                         a4: 0);
  v6 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v8 = IsProportional(this);
  v9 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
         a1: v2,
         a2: "DefaultBold",
         a3: v8);
  v6->SetFont(this, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1049E7C0
// Name: private: virtual void CAnimGroupTree::OnResetTransformPivot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnResetTransformPivot(CAnimGroupTree *this, int viewCenter)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  vgui::Panel *v5; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ResetTransformPivot", firstKey: "viewCenter", firstValue: viewCenter);
  else
    v4 = nullptr;
  v5 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: v5,
    a3: v4,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1049E820
// Name: private: virtual void CAnimGroupTree::OnSetOverrideParent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnSetOverrideParent(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049E880
// Name: private: virtual void CAnimGroupTree::OnOpenLockContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnOpenLockContextMenu(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1049E910
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ApplySchemeSettings(CBaseAnimSetControlGroupPanel *this, int pScheme)
{
  vgui::IScheme *v2; // esi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  Color *(__thiscall *v6)(vgui::IScheme *, Color *, const char *, Color); // edx
  vgui::Panel *v7; // eax

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  pScheme = -2139062144;
  v5 = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "AnimSet.FullSelectionColor",
                   a4: -2139062144);
  pScheme = 1077969024;
  this->m_FullSelectionColor = v5;
  this->m_PartialSelectionColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                              a1: v2,
                                              a2: &pScheme,
                                              a3: "AnimSet.PartialSelectionColor",
                                              a4: 1077969024);
  v6 = v2->GetColor;
  pScheme = -16737793;
  this->m_ContextMenuHighlightColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v6)(
                                                  a1: v2,
                                                  a2: &pScheme,
                                                  a3: "AnimSet.ContextMenuSelectionColor",
                                                  a4: -16737793);
  v7 = vgui::PHandle::Get(this: &this->m_hGroups);
  v7->ApplySchemeSettings(this: v7, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1049E9B0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(
        CBaseAnimSetControlGroupPanel *this,
        int itemID)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax

  if ( itemID >= 0 )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v3->__vftable[1].GetAnimMap)(
      a1: v3,
      a2: itemID,
      a3: &this->m_ContextMenuHighlightColor);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = ((int (__thiscall *)(vgui::Panel *, int))v4->__vftable[1].IsWithinTraverse)(a1: v4, a2: itemID);
  v6 = vgui::PHandle::Get(this: &this->m_hEditor);
  ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].OnTick)(a1: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1049EAB0
// Name: public: void CAnimGroupStateIconSet::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::UpdateState(CAnimGroupStateIconSet *this)
{
  vgui::Tooltip *Tooltip; // ebx
  CDmeDag *m_pDag; // ecx
  CDmeDag *OverrideParent; // eax
  CDmeDag *v5; // edi
  CDmeDag *Parent; // eax
  int m_StateType; // ecx
  bool v8; // bl
  int v9; // edx
  int v10; // eax
  vgui::IImage *Image; // eax
  vgui::Tooltip *v12; // esi
  const wchar_t *v13; // eax
  const char *m_pAsString; // edi
  char tipText[64]; // [esp+4h] [ebp-6Ch] BYREF
  char itemText[32]; // [esp+44h] [ebp-2Ch] BYREF
  vgui::Tooltip *pTooltip; // [esp+64h] [ebp-Ch]
  int nPartialLockedIcon; // [esp+68h] [ebp-8h]
  bool bRot; // [esp+6Eh] [ebp-2h] BYREF
  bool bPos; // [esp+6Fh] [ebp-1h] BYREF

  if ( this->m_pDag == nullptr )
    return;
  this->m_pLockButton->ClearImages(this: this->m_pLockButton);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  m_pDag = this->m_pDag;
  pTooltip = Tooltip;
  bPos = false;
  bRot = false;
  OverrideParent = (CDmeDag *)CDmeDag::GetOverrideParent(
                                this: m_pDag,
                                bPosition: &bPos,
                                bRotation: &bRot,
                                bIgnoreEnable: true);
  v5 = OverrideParent;
  if ( OverrideParent == nullptr )
  {
    CDmElement::ChangeHandle(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: Tooltip, text: "#LockButtonTip");
    return;
  }
  Parent = CDmeDag::GetParent(this: OverrideParent);
  m_StateType = this->m_StateType;
  v8 = Parent == nullptr;
  v9 = 2 * (Parent == nullptr) + 2;
  nPartialLockedIcon = 2 * (Parent == nullptr) + 3;
  v10 = 0;
  if ( m_StateType == 1 )
  {
    if ( !bPos || !bRot )
    {
      v10 = this->m_pImageIndexMap[nPartialLockedIcon];
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( m_StateType == 2 && bPos || m_StateType == 3 && bRot )
LABEL_11:
    v10 = this->m_pImageIndexMap[v9];
LABEL_12:
  Image = vgui::ImageList::GetImage(this: this->m_ImageList, imageIndex: v10);
  this->m_pLockButton->AddImage(this: this->m_pLockButton, a2: Image, a3: 0);
  v12 = pTooltip;
  if ( pTooltip != nullptr )
  {
    if ( v8 )
    {
      vgui::Tooltip::SetText(this: pTooltip, text: "#LockedToWorld");
    }
    else
    {
      v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#LockedTo");
      if ( v13 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v13, a3: itemText, a4: 32);
        m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        V_snprintf(pDest: tipText, maxLen: 0x40u, pFormat: "%s %s", itemText, m_pAsString);
        vgui::Tooltip::SetText(this: v12, text: tipText);
      }
    }
    CDmElement::ChangeHandle(this: v12, tooltipDelay: 750);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049EC40
// Name: public: virtual CAnimGroupTree::~CAnimGroupTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::~CAnimGroupTree(CAnimGroupTree *this)
{
  vgui::Panel *v2; // eax

  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x1049ECA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupTree::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupTree::GetMessageMap(CAnimGroupTree *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupTree::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupTree::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049ECD0
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupTree::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupTree::GetAnimMap(CAnimGroupTree *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
}

//------------------------------------------------------------------------------
// Address: 0x1049ECE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupTree::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupTree::GetKBMap(CAnimGroupTree *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupTree::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetKBMap'::`2'::s_pMap;
  `CAnimGroupTree::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049ED10
// Name: private: static bool CAnimGroupTree::CanAddDragIntoGroup(class CDmeControlGroup const __near *,class CDmElement const __near *,class CDmElement const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAnimGroupTree::CanAddDragIntoGroup(
        CDmeControlGroup *pTargetGroup,
        const CDmElement *pTargetElement,
        const CDmeControlGroup *pDragElement,
        bool bInsertBefore)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *v5; // esi
  char v6; // al
  CDmeControlGroup *Parent; // eax
  CDmeAnimationSet *pTargetGroupAnimSet; // [esp+Ch] [ebp-8h]
  char v10; // [esp+13h] [ebp-1h]

  if ( (_S1_50 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_50 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symControls, a3: "controls");
  }
  if ( pTargetGroup == nullptr || pDragElement == nullptr || pTargetElement == nullptr || pDragElement == pTargetGroup )
    return false;
  pTargetGroupAnimSet = CDmeControlGroup::FindAnimationSet(this: pTargetGroup, bSearchAncestors: true);
  v5 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: pDragElement);
  v6 = ((int (__thiscall *)(_DWORD, _DWORD))pTargetElement->IsA)(
         a1: (CDmElement *)pTargetElement,
         a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id);
  v10 = v6;
  if ( v5 == nullptr )
  {
    if ( !bInsertBefore || v6 == 0 )
      return FindReferringElement<CDmeAnimationSet>(
               pElement: pDragElement,
               symAttrName: symControls,
               bMustBeInSameFile: true,
               depth: TD_ALL) == pTargetGroupAnimSet;
    return false;
  }
  if ( CDmeControlGroup::IsAncestorOfGroup(this: v5, pGroup: pTargetGroup) || bInsertBefore && v10 == 0 )
    return false;
  Parent = CDmeControlGroup::FindParent(this: v5);
  if ( Parent != nullptr )
    return CDmeControlGroup::FindAnimationSet(this: Parent, bSearchAncestors: true) == pTargetGroupAnimSet;
  else
    return pTargetGroupAnimSet == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1049EE20
// Name: public: virtual void CAnimGroupTree::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAnimGroupTree::PerformLayout(CAnimGroupTree *this@<ecx>, int a2@<esi>)
{
  int i; // ebx
  KeyValues *v4; // eax
  CAnimGroupStateIconSet *Ptr; // esi
  int nPosX; // [esp+8h] [ebp-10h] BYREF
  int nWidth; // [esp+Ch] [ebp-Ch] BYREF
  int nPosY; // [esp+10h] [ebp-8h] BYREF
  int nHeight; // [esp+14h] [ebp-4h] BYREF

  vgui::TreeView::PerformLayout(this);
  for ( i = this->FirstItem(this);
        i != this->InvalidItemID(this);
        i = ((int (__thiscall *)(CAnimGroupTree *))this->NextItem)(a1: this) )
  {
    v4 = (KeyValues *)((int (__thiscall *)(CAnimGroupTree *, int, int))this->GetItemData)(a1: this, a2: i, a3: a2);
    if ( v4 != nullptr )
    {
      Ptr = (CAnimGroupStateIconSet *)KeyValues::GetPtr(this: v4, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
      {
        if ( vgui::TreeView::GetItemBounds(this, itemIndex: i, x: &nPosX, y: &nPosY, w: &nWidth, h: &nHeight) != 0 )
        {
          CAnimGroupStateIconSet::UpdateState(this: Ptr);
          vgui::Panel::SetBounds(this: Ptr, x: 0, y: nPosY, wide: nHeight, tall: nHeight);
          ((void (__stdcall *)(int))Ptr->SetVisible)(a1: 1);
        }
        else
        {
          ((void (__stdcall *)(_DWORD))Ptr->SetVisible)(a1: 0);
        }
      }
    }
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049EEF0
// Name: public: virtual bool CAnimGroupStateIconSet::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupStateIconSet::IsDroppable(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeTransformControl *v6; // esi
  const CDmeDag *DagFromDragElement; // eax
  CDmeDag *v8; // esi

  if ( msglist->m_Size != 1 )
    return false;
  Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v6 = (CDmeTransformControl *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
    v6 = nullptr;
  DagFromDragElement = CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v6);
  v8 = (CDmeDag *)DagFromDragElement;
  return DagFromDragElement != nullptr
      && !CDmeDag::IsAncestorOfDag(this: this->m_pDag, pDag: DagFromDragElement)
      && this->m_pDag != v8;
}

//------------------------------------------------------------------------------
// Address: 0x1049EF80
// Name: public: virtual void CAnimGroupStateIconSet::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnPanelDropped(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmeTransformControl *v5; // esi
  CExpressionCalculator *DagFromDragElement; // edi
  int m_StateType; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  int BufferType; // eax
  int v11; // eax
  CAnimGroupStateIconSet_vtbl *v12; // edi
  int v13; // eax
  char v14; // [esp+13h] [ebp-1h]
  bool bRotation; // [esp+1Fh] [ebp+Bh]

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v5 = (CDmeTransformControl *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    DagFromDragElement = (CExpressionCalculator *)CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v5);
    if ( DagFromDragElement != nullptr )
    {
      m_StateType = this->m_StateType;
      if ( m_StateType == 1 || (bRotation = false, m_StateType == 2) )
        bRotation = true;
      if ( m_StateType == 1 || (v14 = 0, m_StateType == 3) )
        v14 = 1;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetOverrideParent");
      else
        v9 = nullptr;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
      KeyValues::SetInt(this: v9, keyName: "targetDag", value: BufferType);
      v11 = CCodecBuffer_Block::GetBufferType(this: DagFromDragElement);
      KeyValues::SetInt(this: v9, keyName: "parentDag", value: v11);
      KeyValues::SetInt(this: v9, keyName: "position", value: bRotation);
      KeyValues::SetInt(this: v9, keyName: "rotation", value: v14 != 0);
      v12 = this->__vftable;
      v13 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(
              a1: this,
              a2: v9,
              a3: 0);
      ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v12->PostMessage)(a1: this, a2: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049F0F0
// Name: public: class CDmElement __near * CAnimGroupTree::GetTreeItemData(int,enum AnimTreeItemType_t __near *,class CDmeAnimationSet __near * __near *,class CDmeControlGroup __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAnimGroupTree::GetTreeItemData(
        CAnimGroupTree *this,
        int nTreeIndex,
        AnimTreeItemType_t *pItemType,
        CDmeAnimationSet **ppParentAnimationSet,
        CDmeControlGroup **ppControlGroup)
{
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CDmeAnimationSet *v9; // esi
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  DmElementHandle_t v13; // eax
  CDmElement *v14; // eax
  CDmElement *v15; // esi

  v5 = this->GetItemData(this, a2: nTreeIndex);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  if ( pItemType != nullptr )
    *pItemType = KeyValues::GetInt(this: v5, keyName: "itemType", defaultValue: 0);
  if ( ppParentAnimationSet != nullptr )
  {
    Int = KeyValues::GetInt(this: v6, keyName: "animset", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = (CDmeAnimationSet *)v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeAnimationSet::m_classType) )
      v9 = nullptr;
    *ppParentAnimationSet = v9;
  }
  if ( ppControlGroup != nullptr )
  {
    v10 = KeyValues::GetInt(this: v6, keyName: "controlgroup", defaultValue: -1);
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
    v12 = (CDmeControlGroup *)v11;
    if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
      v12 = nullptr;
    *ppControlGroup = v12;
  }
  v13 = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13);
  v15 = v14;
  if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmElement::m_classType) )
    return v15;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1049F200
// Name: public: class CDmeControlGroup __near * CAnimGroupTree::GetControlGroupForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAnimGroupTree::GetControlGroupForTreeItem(CAnimGroupTree *this, int nItemIndex)
{
  KeyValues *v2; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v4; // eax
  CDmeAnimationSet *v5; // esi

  v2 = this->GetItemData(this, a2: nItemIndex);
  if ( v2 == nullptr )
    return nullptr;
  Int = KeyValues::GetInt(this: v2, keyName: "handle", defaultValue: -1);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v5 = (CDmeAnimationSet *)v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
    v5 = nullptr;
  if ( v5 == nullptr )
    return nullptr;
  if ( v5->IsA(this: v5, a2: CDmeAnimationSet::m_classType) )
    return (CDmeAnimationSet *)CDmeAnimationSet::GetRootControlGroup(this: v5);
  if ( v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1049F2B0
// Name: public: class CDmeDag __near * CAnimGroupTree::GetDagForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAnimGroupTree::GetDagForTreeItem(CAnimGroupTree *this, AnimTreeItemType_t nTreeItemIndex)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v5; // eax
  CDmeTransformControl *v6; // esi
  DmElementHandle_t *Transform; // eax

  v2 = this->GetItemData(this, a2: nTreeItemIndex);
  v3 = v2;
  if ( v2 != nullptr
    && (KeyValues::GetInt(this: v2, keyName: "itemType", defaultValue: 0),
        Int = KeyValues::GetInt(this: v3, keyName: "handle", defaultValue: -1),
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
        v6 = (CDmeTransformControl *)v5,
        v5 != nullptr)
    && v5->IsA(this: v5, a2: CDmElement::m_classType)
    && v6->IsA(this: v6, a2: CDmeTransformControl::m_classType)
    && (Transform = CDmeTransformControl::GetTransform(this: v6)) != nullptr )
  {
    return CDmeTransform::GetDag(this: (CDmeTransform *)Transform);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049F350
// Name: public: virtual bool CAnimGroupTree::IsItemDroppable(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::IsItemDroppable(
        CAnimGroupTree *this,
        const CDmeControlGroup *nItemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CDmeControlGroup *ControlGroupForTreeItem; // eax
  int m_Size; // ebx
  int v7; // edi
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  const CDmeControlGroup *v11; // esi
  CDmElement *pTargetElement; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *pTargetControlGroup; // [esp+10h] [ebp-8h]
  CDmeControlGroup *pParentControlGroup; // [esp+14h] [ebp-4h] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+20h] [ebp+8h]

  if ( msglist->m_Size == 0 )
    return 0;
  pParentControlGroup = nullptr;
  pTargetElement = CAnimGroupTree::GetTreeItemData(
                     this,
                     nTreeIndex: (int)nItemIndex,
                     pItemType: nullptr,
                     ppParentAnimationSet: nullptr,
                     ppControlGroup: &pParentControlGroup);
  if ( pTargetElement == nullptr )
    return 0;
  ControlGroupForTreeItem = (CDmeControlGroup *)CAnimGroupTree::GetControlGroupForTreeItem(this, (int)nItemIndex);
  pTargetControlGroup = ControlGroupForTreeItem;
  pNewParentGroup = bInsertBefore ? pParentControlGroup : ControlGroupForTreeItem;
  m_Size = msglist->m_Size;
  v7 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = msglist->m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
    {
      if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr && pTargetControlGroup != nullptr )
        break;
      Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v11 = (const CDmeControlGroup *)v10;
      if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
        v11 = nullptr;
      if ( CAnimGroupTree::CanAddDragIntoGroup(
             pTargetGroup: pNewParentGroup,
             pTargetElement,
             pDragElement: v11,
             bInsertBefore) )
      {
        break;
      }
    }
    if ( ++v7 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1049F450
// Name: public: virtual void CAnimGroupTree::OnItemDropped(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnItemDropped(
        CAnimGroupTree *this,
        int nItemIndex,
        BOOL bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // esi
  CDmeControlGroup *ControlGroupForTreeItem; // eax
  int v7; // eax
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int nMsgCount; // [esp+Ch] [ebp-20h]
  int iMsg; // [esp+10h] [ebp-1Ch]
  CDmeAnimationSet *pTargetAnimSet; // [esp+14h] [ebp-18h] BYREF
  CDmElement *pTargetElement; // [esp+18h] [ebp-14h]
  CDmeControlGroup *pTargetControlGroup; // [esp+1Ch] [ebp-10h]
  Color clr; // [esp+20h] [ebp-Ch] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+24h] [ebp-8h]
  Color defaultColor; // [esp+28h] [ebp-4h] BYREF

  v4 = msglist;
  if ( this->IsItemDroppable(this, a2: nItemIndex, a3: bInsertBefore, a4: msglist) )
  {
    clr = 0;
    pTargetAnimSet = nullptr;
    pTargetElement = CAnimGroupTree::GetTreeItemData(
                       this,
                       nTreeIndex: nItemIndex,
                       pItemType: nullptr,
                       ppParentAnimationSet: &pTargetAnimSet,
                       ppControlGroup: (CDmeControlGroup **)&clr);
    if ( pTargetElement != nullptr )
    {
      ControlGroupForTreeItem = (CDmeControlGroup *)CAnimGroupTree::GetControlGroupForTreeItem(this, nItemIndex);
      pTargetControlGroup = ControlGroupForTreeItem;
      if ( bInsertBefore )
        pNewParentGroup = (CDmeControlGroup *)clr;
      else
        pNewParentGroup = ControlGroupForTreeItem;
      g_pDataModel->StartUndo(this: g_pDataModel, a2: "Drop onto control group", a3: "Drop onto control group", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Drop onto control group", a3: 0, a4: 256);
      v7 = 0;
      nMsgCount = msglist->m_Size;
      iMsg = 0;
      if ( nMsgCount > 0 )
      {
        while ( 1 )
        {
          v8 = v4->m_Memory.m_pMemory[v7];
          if ( v8 != nullptr )
          {
            if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr )
            {
              defaultColor = 0;
              KeyValues::GetColor(this: v8, result: &clr, keyName: "color", &defaultColor);
              this->SetItemFgColor(this, a2: nItemIndex, a3: &clr);
              this->SetItemSelectionTextColor(this, a2: nItemIndex, a3: &clr);
              CDmeControlGroup::SetGroupColor(this: pTargetControlGroup, groupColor: &clr, bRecursive: false);
            }
            Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
            v11 = (CDmeControlGroup *)v10;
            if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
              v11 = nullptr;
            if ( CAnimGroupTree::CanAddDragIntoGroup(
                   pTargetGroup: pNewParentGroup,
                   pTargetElement,
                   pDragElement: v11,
                   bInsertBefore) )
            {
              if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
                CDmeControlGroup::AddChild(
                  this: pNewParentGroup,
                  pGroup: v11,
                  pInsertBeforeGroup: bInsertBefore ? pTargetControlGroup : nullptr);
              else
                CDmeControlGroup::AddControl(
                  this: pNewParentGroup,
                  pControl: v11,
                  pInsertBeforeControl: bInsertBefore ? pTargetElement : nullptr);
              if ( pTargetAnimSet != nullptr )
              {
                RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pTargetAnimSet);
                if ( RootControlGroup != nullptr )
                  CDmeControlGroup::DestroyEmptyChildren(this: RootControlGroup);
              }
            }
          }
          v7 = iMsg + 1;
          iMsg = v7;
          if ( v7 >= nMsgCount )
            break;
          v4 = msglist;
        }
      }
      g_pDataModel->FinishUndo(this: g_pDataModel);
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049F670
// Name: public: virtual void CAnimGroupTree::GenerateDragDataForItem(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateDragDataForItem(CAnimGroupTree *this, int nItemIndex, KeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // edi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  int BufferType; // eax

  v3 = this->GetItemData(this, a2: nItemIndex);
  v4 = v3;
  if ( v3 != nullptr )
  {
    Int = KeyValues::GetInt(this: v3, keyName: "itemType", defaultValue: 0);
    v6 = KeyValues::GetInt(this: v4, keyName: "handle", defaultValue: -1);
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
    v8 = (CExpressionCalculator *)v7;
    if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) && Int != 3 )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049F700
// Name: public: virtual void CAnimGroupTree::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnMousePressed(CAnimGroupTree *this, ButtonCode_t code)
{
  int ItemUnderMouse; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CAnimGroupTree_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // eax
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeTransformControl *v11; // edi
  CDmeDag *Dag; // eax
  int h; // [esp+10h] [ebp-18h] BYREF
  int w; // [esp+14h] [ebp-14h] BYREF
  int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int y; // [esp+20h] [ebp-8h] BYREF
  int x; // [esp+24h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  ItemUnderMouse = vgui::TreeView::FindItemUnderMouse(this, mx: x, my: y);
  if ( this->IsItemIDValid(this, a2: ItemUnderMouse) )
  {
    vgui::TreeView::GetItemBounds(this, itemIndex: ItemUnderMouse, x: &v15, y: &v16, &w, &h);
    if ( x < v15 || y < v16 || x > w + v15 || y > h + v16 )
      ItemUnderMouse = -1;
  }
  if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    if ( code == MOUSE_RIGHT )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(
               this: v4,
               setName: "TreeViewOpenContextMenu",
               firstKey: "itemID",
               firstValue: ItemUnderMouse);
      else
        v5 = nullptr;
      v6 = this->__vftable;
      v7 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
      ((void (__thiscall *)(CAnimGroupTree *, int))v6->PostMessage)(a1: this, a2: v7);
      return;
    }
LABEL_22:
    vgui::TreeView::OnMousePressed(this, code);
    return;
  }
  if ( !this->IsItemIDValid(this, a2: ItemUnderMouse) || x >= this->m_nStateColumnWidth + 20 )
    goto LABEL_22;
  v8 = this->GetItemData(this, a2: ItemUnderMouse);
  if ( v8 != nullptr )
  {
    Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1);
    v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v11 = (CDmeTransformControl *)v10;
    if ( v10 != nullptr
      && v10->IsA(this: v10, a2: CDmElement::m_classType)
      && v11->IsA(this: v11, a2: CDmeTransformControl::m_classType) )
    {
      Dag = CDmeTransformControl::GetDag(this: v11);
      CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: Dag);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049F8E0
// Name: public: virtual void CAnimGroupTree::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnTick(CAnimGroupTree *this)
{
  int v2; // ebx
  AnimTreeItemType_t v3; // edi
  vgui::Button_vtbl *v4; // edi
  vgui::IImage *Image; // eax
  int x; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int y; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v2 = -1;
  y = (int)CBaseAnimationSetControl::GetWorkCameraParent(this: this->m_pGroupPanel->m_pController);
  if ( y != 0 )
  {
    v3 = this->FirstItem(this);
    if ( v3 != this->InvalidItemID(this) )
    {
      while ( CAnimGroupTree::GetDagForTreeItem(this, nTreeItemIndex: v3) != (CDmeDag *)y )
      {
        v3 = this->NextItem(this, a2: v3);
        if ( v3 == this->InvalidItemID(this) )
          goto LABEL_7;
      }
      v2 = v3;
    }
  }
LABEL_7:
  this->m_pWorkCameraParentButton->SetVisible(this: this->m_pWorkCameraParentButton, a2: v2 != -1);
  if ( v2 != -1 )
  {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    vgui::TreeView::GetItemBounds(this, itemIndex: v2, &x, &y, &w, &h);
    vgui::Panel::SetBounds(
      this: this->m_pWorkCameraParentButton,
      x: this->m_nStateColumnWidth + 1,
      y: y + 1,
      wide: h - 2,
      tall: h - 2);
    this->m_pWorkCameraParentButton->ClearImages(this: this->m_pWorkCameraParentButton);
    v4 = this->m_pWorkCameraParentButton->__vftable;
    Image = vgui::ImageList::GetImage(this: &this->m_Images, imageIndex: this->m_StateIconIndices[0]);
    v4->AddImage(this: this->m_pWorkCameraParentButton, a2: Image, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049FA10
// Name: private: bool CAnimGroupTree::VisibleControlsBelow_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::VisibleControlsBelow_R(CAnimGroupTree *this, CDmeControlGroup *pGroup)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int nNumChildren; // [esp+18h] [ebp+8h]

  if ( CBaseAnimationSetControl::IsControlGroupVisible(this: this->m_pGroupPanel->m_pController, pGroup) )
  {
    if ( pGroup->m_Controls.m_Storage.m_Size > 0 )
      return 1;
    v4 = 0;
    nNumChildren = pGroup->m_Children.m_Storage.m_Size;
    if ( nNumChildren > 0 )
    {
      while ( 1 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr
          && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType)
          && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v6) )
        {
          break;
        }
        if ( ++v4 >= nNumChildren )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1049FAA0
// Name: public: int CAnimGroupTree::FindChildItemForElement(int,class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindChildItemForElement(
        CAnimGroupTree *this,
        int nParentIndex,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  DmElementHandle_t Int; // eax
  CDmElement *v9; // eax
  const CDmElement *v10; // edi
  int v11; // eax
  int nChildren; // [esp+Ch] [ebp-Ch]
  int iChild; // [esp+10h] [ebp-8h]
  int nChildIndex; // [esp+14h] [ebp-4h]

  v5 = 0;
  nChildren = this->GetNumChildren(this, a2: nParentIndex);
  iChild = 0;
  if ( nChildren <= 0 )
    return -1;
  while ( 1 )
  {
    nChildIndex = this->GetChild(this, a2: nParentIndex, a3: v5);
    v6 = this->GetItemData(this, a2: nChildIndex);
    v7 = v6;
    if ( v6 != nullptr )
      break;
LABEL_12:
    iChild = ++v5;
    if ( v5 >= nChildren )
      return -1;
  }
  Int = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v10 = v9;
  if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmElement::m_classType) )
    v10 = nullptr;
  if ( v10 == pElement )
  {
    if ( nComponentFlags == TRANSFORM_COMPONENT_NONE )
      return nChildIndex;
    v11 = KeyValues::GetInt(this: v7, keyName: "componentFlags", defaultValue: 0);
    if ( v11 == nComponentFlags )
      return nChildIndex;
    if ( (nComponentFlags & v11) == nComponentFlags )
    {
      this->GenerateChildrenOfNode(this, a2: nChildIndex);
      if ( CAnimGroupTree::FindChildItemForElement(this, nParentIndex: nChildIndex, pElement, nComponentFlags) >= 0 )
        return nChildIndex;
    }
  }
  v5 = iChild;
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x1049FBB0
// Name: public: int CAnimGroupTree::FindItemForElement(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindItemForElement(
        CAnimGroupTree *this,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  const CDmElement *v9; // esi
  int highest; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v4 = 0;
  highest = this->GetHighestItemID(this);
  i = 0;
  if ( highest <= 0 )
    return -1;
  while ( 1 )
  {
    if ( this->IsItemIDValid(this, a2: v4) )
    {
      v5 = this->GetItemData(this, a2: v4);
      v6 = v5;
      if ( v5 == nullptr )
        goto LABEL_11;
      Int = KeyValues::GetInt(this: v5, keyName: "handle", defaultValue: -1);
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      if ( v9 == pElement
        && (KeyValues::GetInt(this: v6, keyName: "componentFlags", defaultValue: 0) == nComponentFlags
         || nComponentFlags == TRANSFORM_COMPONENT_NONE) )
      {
        return i;
      }
      v4 = i;
    }
LABEL_11:
    i = ++v4;
    if ( v4 >= highest )
      return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049FC80
// Name: public: int CAnimGroupTree::BuildTreeToAnimationSet(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToAnimationSet(CAnimGroupTree *this, CDmeAnimationSet *pAnimationSet)
{
  int result; // eax
  int v4; // edi

  if ( pAnimationSet == nullptr )
    return -1;
  result = CAnimGroupTree::FindItemForElement(this, pElement: pAnimationSet, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( result < 0 )
  {
    v4 = this->GetRootItemIndex(this);
    this->GenerateChildrenOfNode(this, a2: v4);
    return CAnimGroupTree::FindChildItemForElement(
             this,
             nParentIndex: v4,
             pElement: pAnimationSet,
             nComponentFlags: TRANSFORM_COMPONENT_NONE);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049FCE0
// Name: public: int CAnimGroupTree::BuildTreeToGroup(class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToGroup(
        CAnimGroupTree *this,
        CDmeControlGroup *pGroup,
        CDmeAnimationSet *pAnimationSet)
{
  CDmeControlGroup *Parent; // eax
  int v7; // edi
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pGroup == nullptr || pAnimationSet == nullptr )
    return -1;
  nItemIndex = CAnimGroupTree::FindItemForElement(this, pElement: pGroup, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( nItemIndex < 0 )
  {
    if ( CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet) == pGroup )
      return CAnimGroupTree::BuildTreeToAnimationSet(this, pAnimationSet);
    Parent = CDmeControlGroup::FindParent(this: pGroup);
    v7 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: Parent, pAnimationSet);
    if ( v7 >= 0 )
    {
      this->GenerateChildrenOfNode(this, a2: v7);
      return CAnimGroupTree::FindChildItemForElement(
               this,
               nParentIndex: v7,
               pElement: pGroup,
               nComponentFlags: TRANSFORM_COMPONENT_NONE);
    }
  }
  return nItemIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1049FD70
// Name: public: void CAnimGroupTree::BuildTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::BuildTreeToControl(
        CAnimGroupTree *this,
        const CDmElement *pControl,
        TransformComponent_t nComponentFlags)
{
  CDmeAnimationSet *Referring; // ebx
  int ItemForElement; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  int v8; // ebx
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pControl != nullptr )
  {
    Referring = FindReferringElement<CDmeAnimationSet>(
                  pElement: pControl,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring != nullptr )
    {
      ItemForElement = CAnimGroupTree::FindItemForElement(this, pElement: pControl, nComponentFlags);
      nItemIndex = ItemForElement;
      if ( ItemForElement >= 0 )
      {
LABEL_8:
        this->MakeItemVisible(this, a2: ItemForElement);
        return;
      }
      GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
      v8 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: GroupContainingControl, pAnimationSet: Referring);
      if ( v8 >= 0 )
      {
        this->GenerateChildrenOfNode(this, a2: v8);
        nItemIndex = CAnimGroupTree::FindChildItemForElement(
                       this,
                       nParentIndex: v8,
                       pElement: pControl,
                       nComponentFlags);
      }
      if ( nItemIndex >= 0 )
      {
        ItemForElement = nItemIndex;
        goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049FE00
// Name: protected: void CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(int,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex,
        ESelectionMode selectionMode)
{
  vgui::Panel *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CDmeAnimationSet *v10; // eax
  CDmeControlGroup *v11; // eax
  CAnimGroupTree *v12; // eax
  TransformComponent_t ItemComponentFlags; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-4h]

  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v4->__vftable[1].IsWithinTraverse)(a1: v4, a2: itemIndex);
  v6 = v5;
  if ( v5 != nullptr )
  {
    itemType = KeyValues::GetInt(this: v5, keyName: "itemType", defaultValue: 0);
    Int = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v9 = v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
    {
      switch ( itemType )
      {
        case ANIMTREE_ITEM_ANIMSET:
          v10 = CastElement<CDmeAnimationSet>(pElement: v9);
          if ( v10 != nullptr )
            CBaseAnimationSetControl::SelectAnimationSet(this: this->m_pController, pAnimSet: v10, selectionMode);
          break;
        case ANIMTREE_ITEM_GROUP:
          v11 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: v9);
          if ( v11 != nullptr )
            CBaseAnimationSetControl::SelectControlGroup(this: this->m_pController, pGroup: v11, selectionMode);
          break;
        case ANIMTREE_ITEM_CONTROL:
          CBaseAnimationSetControl::SelectControl(
            this: this->m_pController,
            pControl: v9,
            selectionMode,
            nComponentFlags: TRANSFORM_COMPONENT_ALL,
            bExpandTree: false);
          break;
        case ANIMTREE_ITEM_COMPONENT:
          v12 = (CAnimGroupTree *)vgui::PHandle::Get(this: &this->m_hGroups);
          ItemComponentFlags = CAnimGroupTree::GetItemComponentFlags(this: v12, nTreeIndex: itemIndex);
          CBaseAnimationSetControl::SelectControl(
            this: this->m_pController,
            pControl: v9,
            selectionMode,
            nComponentFlags: ItemComponentFlags,
            bExpandTree: false);
          break;
        default:
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049FF30
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ExpandTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandTreeToControl(
        CBaseAnimSetControlGroupPanel *this,
        const CDmElement *pSelection,
        TransformComponent_t nComponentFlags)
{
  CAnimGroupTree *v3; // eax

  v3 = (CAnimGroupTree *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_LastNavDirection);
  CAnimGroupTree::BuildTreeToControl(this: v3, pControl: pSelection, nComponentFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1049FF50
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex,
        int replaceSelection)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(
    this,
    itemIndex,
    selectionMode: (ESelectionMode)(replaceSelection == 0));
}

//------------------------------------------------------------------------------
// Address: 0x1049FF70
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(this, itemIndex, selectionMode: SELECTION_REMOVE);
}

//------------------------------------------------------------------------------
// Address: 0x1049FF90
// Name: protected: void CBaseAnimSetControlGroupPanel::ExpandItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandItems(
        CBaseAnimSetControlGroupPanel *this,
        const CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes)
{
  int v2; // ebx
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  CDmElement *m_pElement; // edi
  CAnimGroupTree *v5; // eax
  int ItemForElement; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  int v11; // ebx
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v16; // eax
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  vgui::Panel *v20; // eax
  int nExpandedNodes; // [esp+Ch] [ebp-1Ch]
  int nChildren; // [esp+10h] [ebp-18h]
  TransformComponent_t expandedComponents; // [esp+14h] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+18h] [ebp-10h]
  int nItemIndex; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int v27; // [esp+24h] [ebp-4h]

  v2 = 0;
  nExpandedNodes = expandedNodes->m_Size;
  i = 0;
  if ( nExpandedNodes > 0 )
  {
    p_m_hGroups = &this->m_hGroups;
    do
    {
      m_pElement = expandedNodes->m_Memory.m_pMemory[v2].m_pElement;
      v5 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
      ItemForElement = CAnimGroupTree::FindItemForElement(
                         this: v5,
                         pElement: m_pElement,
                         nComponentFlags: TRANSFORM_COMPONENT_NONE);
      nItemIndex = ItemForElement;
      v7 = vgui::PHandle::Get(this: p_m_hGroups);
      if ( ItemForElement != ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].InstallMouseHandler)(a1: v7) )
      {
        v8 = vgui::PHandle::Get(this: p_m_hGroups);
        ((void (__thiscall *)(vgui::Panel *, int, int))v8->__vftable[1].dtr_Panel)(a1: v8, a2: ItemForElement, a3: 1);
        expandedComponents = expandedNodes->m_Memory.m_pMemory[v2].m_ComponentFlags;
        if ( expandedComponents != TRANSFORM_COMPONENT_NONE )
        {
          v9 = vgui::PHandle::Get(this: p_m_hGroups);
          nChildren = ((int (__thiscall *)(vgui::Panel *, int))v9->__vftable[1].PerformApplySchemeSettings)(
                        a1: v9,
                        a2: ItemForElement);
          v27 = 0;
          if ( nChildren > 0 )
          {
            while ( 1 )
            {
              v10 = vgui::PHandle::Get(this: p_m_hGroups);
              v11 = ((int (__thiscall *)(vgui::Panel *, int, int))v10->__vftable[1].PaintTraverse)(
                      a1: v10,
                      a2: ItemForElement,
                      a3: v27);
              v12 = vgui::PHandle::Get(this: p_m_hGroups);
              v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(
                                   a1: v12,
                                   a2: v11);
              v14 = v13;
              if ( v13 != nullptr )
              {
                childItemType = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
                Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
                v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
                if ( v16 != nullptr )
                  v16->IsA(this: v16, a2: CDmElement::m_classType);
              }
              v17 = vgui::PHandle::Get(this: p_m_hGroups);
              v18 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v17->__vftable[1].IsWithinTraverse)(
                                   a1: v17,
                                   a2: v11);
              v19 = KeyValues::GetInt(this: v18, keyName: "componentFlags", defaultValue: 0);
              if ( childItemType == ANIMTREE_ITEM_COMPONENT && (v19 & expandedComponents) != 0 )
              {
                v20 = vgui::PHandle::Get(this: p_m_hGroups);
                ((void (__thiscall *)(vgui::Panel *, int, int))v20->__vftable[1].dtr_Panel)(a1: v20, a2: v11, a3: 1);
              }
              if ( ++v27 >= nChildren )
                break;
              ItemForElement = nItemIndex;
            }
            v2 = i;
          }
        }
      }
      i = ++v2;
    }
    while ( v2 < nExpandedNodes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0130
// Name: protected: enum SelectionState_t CBaseAnimSetControlGroupPanel::UpdateSelection_R(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection_R(CBaseAnimSetControlGroupPanel *this, int nParentIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  vgui::Panel *v3; // eax
  int v4; // eax
  int v5; // ebx
  AnimTreeItemType_t v7; // edi
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // eax
  SelectionState_t updated; // eax
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v16; // eax
  CDmElement *v17; // edi
  CDmeAnimationSet *v18; // eax
  SelectionState_t SelectionState; // eax
  CDmeControlGroup *v20; // eax
  CAnimGroupTree *v21; // eax
  TransformComponent_t ItemComponentFlags; // eax
  vgui::Panel *v23; // eax
  KeyValues *v24; // eax
  int v25; // edi
  Color *p_m_PartialSelectionColor; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  vgui::Panel *v31; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-8h]
  AnimTreeItemType_t itemTypea; // [esp+Ch] [ebp-8h]

  p_m_hGroups = &this->m_hGroups;
  v3 = vgui::PHandle::Get(this: &this->m_hGroups);
  v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].InstallMouseHandler)(a1: v3);
  v5 = nParentIndex;
  if ( nParentIndex == v4 )
    return 0;
  v7 = ANIMTREE_ITEM_ANIMSET;
  nParentIndex = 0;
  v8 = vgui::PHandle::Get(this: p_m_hGroups);
  itemType = ((int (__thiscall *)(vgui::Panel *, int))v8->__vftable[1].PerformApplySchemeSettings)(a1: v8, a2: v5);
  if ( itemType <= ANIMTREE_ITEM_ANIMSET )
  {
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(a1: v12, a2: v5);
    v14 = v13;
    if ( v13 == nullptr )
      return 0;
    itemTypea = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
    Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
    v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
    v17 = v16;
    if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmElement::m_classType) )
      return 0;
    switch ( itemTypea )
    {
      case ANIMTREE_ITEM_ANIMSET:
        v18 = CastElement<CDmeAnimationSet>(pElement: v17);
        if ( v18 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v18);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_GROUP:
        v20 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: v17);
        if ( v20 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pControlGroup: v20);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_CONTROL:
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: TRANSFORM_COMPONENT_ALL);
        goto LABEL_16;
      case ANIMTREE_ITEM_COMPONENT:
        v21 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
        ItemComponentFlags = CAnimGroupTree::GetItemComponentFlags(this: v21, nTreeIndex: v5);
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: ItemComponentFlags);
LABEL_16:
        nParentIndex = SelectionState;
        break;
      default:
        break;
    }
  }
  else
  {
    do
    {
      v9 = vgui::PHandle::Get(this: p_m_hGroups);
      v10 = ((int (__thiscall *)(vgui::Panel *, int, AnimTreeItemType_t))v9->__vftable[1].PaintTraverse)(
              a1: v9,
              a2: v5,
              a3: v7);
      updated = CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v10);
      nParentIndex |= updated;
      ++v7;
    }
    while ( v7 < itemType );
  }
  v23 = vgui::PHandle::Get(this: p_m_hGroups);
  v24 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v23->__vftable[1].IsWithinTraverse)(a1: v23, a2: v5);
  v25 = nParentIndex;
  if ( v24 != nullptr )
    KeyValues::SetInt(this: v24, keyName: "selection", value: nParentIndex);
  if ( v25 == 3 )
  {
    p_m_PartialSelectionColor = &this->m_PartialSelectionColor;
    goto LABEL_23;
  }
  if ( v25 == 2 )
  {
    p_m_PartialSelectionColor = &this->m_FullSelectionColor;
LABEL_23:
    nParentIndex = (int)*p_m_PartialSelectionColor;
    v27 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, int *))v27->__vftable[1].GetMessageMap)(
      a1: v27,
      a2: v5,
      a3: &nParentIndex);
    v28 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, int *))v28->__vftable[1].GetAnimMap)(a1: v28, a2: v5, a3: &nParentIndex);
    v29 = vgui::PHandle::Get(this: p_m_hGroups);
    v29->SetSilentMode(this: v29, a2: true);
    v30 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD, _DWORD, _DWORD))v30->__vftable[1].RequestFocusPrev)(
      a1: v30,
      a2: v5,
      a3: 0,
      a4: 0,
      a5: 0);
    v31 = vgui::PHandle::Get(this: p_m_hGroups);
    v31->SetSilentMode(this: v31, a2: false);
  }
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x104A0380
// Name: public: virtual bool CAnimGroupTree::CanCurrentlyEditLabel(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupTree::CanCurrentlyEditLabel(CAnimGroupTree *this, int nItemIndex)
{
  bool result; // al
  int v5; // edi
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int *m_pMemory; // edx
  int v8; // eax
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-18h] BYREF
  int nSelectedItems; // [esp+1Ch] [ebp-4h]
  int nParentIndex; // [esp+28h] [ebp+8h]

  result = this->IsItemSelected(this, a2: nItemIndex);
  if ( result )
  {
    v5 = 0;
    nParentIndex = this->GetItemParent(this, a2: nItemIndex);
    GetSelectedItems = this->GetSelectedItems;
    memset(&selectedItems, 0, sizeof(selectedItems));
    GetSelectedItems(this, a2: &selectedItems);
    m_pMemory = selectedItems.m_Memory.m_pMemory;
    nSelectedItems = selectedItems.m_Size;
    if ( selectedItems.m_Size > 0 )
    {
      do
      {
        v8 = m_pMemory[v5];
        if ( nItemIndex != v8 )
        {
          if ( this->GetItemParent(this, a2: v8) == nParentIndex )
          {
            CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&selectedItems);
            return false;
          }
          m_pMemory = selectedItems.m_Memory.m_pMemory;
        }
        ++v5;
      }
      while ( v5 < nSelectedItems );
    }
    selectedItems.m_Size = 0;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        selectedItems.m_Memory.m_pMemory = nullptr;
      }
      selectedItems.m_Memory.m_nAllocationCount = 0;
    }
    selectedItems.m_pElements = m_pMemory;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A0470
// Name: public: void CBaseAnimSetControlGroupPanel::UpdateSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection(CBaseAnimSetControlGroupPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  int v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hGroups) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hGroups);
    v2->SetSilentMode(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v3->__vftable[1].RequestFocus)(a1: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4->SetSilentMode(this: v4, a2: false);
    v5 = vgui::PHandle::Get(this: &this->m_hGroups);
    v6 = ((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].Think)(a1: v5);
    CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0540
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x200000002LL;
    LODWORD(v4.m[2][3]) = 2;
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "TreeViewItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][2]) = "itemIndex";
    LODWORD(v4.m[3][0]) = "replaceSelection";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A05E0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemIndex";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0680
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewStartRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0710
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewFinishRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A07A0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewItemSelectionCleared";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0830
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewOpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A08D0
// Name: public: static void CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded )
  {
    `CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LockDagButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0960
// Name: public: CAnimGroupStateIconSet::CAnimGroupStateIconSet(class vgui::Panel __near *,char const __near *,enum StateIconSetType_t,class CDmeDag __near *,class vgui::ImageList __near &,int const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet *__thiscall CAnimGroupStateIconSet::CAnimGroupStateIconSet(
        CAnimGroupStateIconSet *this,
        vgui::Panel *pParent,
        const char *pchName,
        int itemType,
        CDmeDag *pDag,
        vgui::ImageList *imageList,
        vgui::Panel *pImageIndexMap)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAnimGroupStateIconSet::IconButton *v11; // eax
  CAnimGroupStateIconSet::IconButton *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::Tooltip *Tooltip; // eax
  vgui::Tooltip *v16; // edi
  int _C; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "AnimGroupStateIconSet");
  this->__vftable = (CAnimGroupStateIconSet_vtbl *)&CAnimGroupStateIconSet::`vftable';
  if ( `CAnimGroupStateIconSet::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v8->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
    v9->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
    v10->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(a1: (int)&_C);
  this->m_ImageList = imageList;
  this->m_pImageIndexMap = (const int *const)pImageIndexMap;
  this->m_StateType = itemType;
  this->m_pDag = pDag;
  this->m_pLockButton = nullptr;
  v11 = (CAnimGroupStateIconSet::IconButton *)operator new(nSize: 0x1FCu);
  if ( v11 != nullptr )
    v12 = CAnimGroupStateIconSet::IconButton::IconButton(this: v11, pIconSet: this, pName: "LockButton");
  else
    v12 = nullptr;
  this->m_pLockButton = v12;
  v12->SetVisible(this: v12, a2: true);
  this->m_pLockButton->AddActionSignalTarget_2(this: this->m_pLockButton, a2: this);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "LockDagButton");
  else
    v14 = nullptr;
  this->m_pLockButton->SetCommand(this: this->m_pLockButton, a2: v14);
  this->m_pLockButton->SetKeyBoardInputEnabled(this: this->m_pLockButton, a2: false);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  v16 = Tooltip;
  if ( Tooltip != nullptr )
  {
    CDmElement::ChangeHandle(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: v16, text: "#LockButtonTip");
    vgui::Tooltip::SetTooltipFormatToSingleLine(this: v16);
  }
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A0B20
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::GetMessageMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A0B50
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::GetAnimMap(CAnimGroupStateIconSet *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
}

//------------------------------------------------------------------------------
// Address: 0x104A0B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::GetKBMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A0B90
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{1084,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ClearWorkCameraParent";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0C20
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1088,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnResetTransformPivot";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "viewCenter";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0CC0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1092,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ToggleDagLock";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0D50
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1096,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetOverrideParent";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0DE0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1100,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenLockContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A0E70
// Name: public: CAnimGroupTree::CAnimGroupTree(class vgui::Panel __near *,char const __near *,class CBaseAnimSetControlGroupPanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupTree *__thiscall CAnimGroupTree::CAnimGroupTree(
        CAnimGroupTree *this,
        vgui::Panel *parent,
        const char *panelName,
        CBaseAnimSetControlGroupPanel *groupPanel,
        bool bStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  vgui::IImage *v13; // eax
  vgui::IImage *v14; // eax
  vgui::IImage *v15; // eax
  vgui::IImage *v16; // eax
  vgui::IImage *v17; // eax
  vgui::IImage *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TreeView::TreeView(this, parent, panelName);
  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( `CAnimGroupTree::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v6->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
    v7->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
    v8->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  }
  CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pGroupPanel = groupPanel;
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_RootColor = (Color)-8355712;
  this->m_StateColumnColor = 0;
  this->m_nStateColumnWidth = 0;
  this->m_bStateInterface = bStateInterface;
  if ( bStateInterface )
  {
    this->m_nStateColumnWidth = 20;
    vgui::TreeView::SetTreeIndent(this, nIndentAmount: 18);
  }
  vgui::TreeView::SetShowRootNode(this, bRootVisible: false);
  vgui::TreeView::SetDragEnabledItems(this, state: true);
  vgui::TreeView::SetAllowLabelEditing(this, state: true);
  vgui::TreeView::SetEnableInsertDropLocation(this, bEnable: true);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "workCameraParent",
            text: &var,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pWorkCameraParentButton = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pWorkCameraParentButton->AddActionSignalTarget_2(this: this->m_pWorkCameraParentButton, a2: this);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "ClearWorkCameraParent");
  else
    v12 = nullptr;
  this->m_pWorkCameraParentButton->SetCommand(this: this->m_pWorkCameraParentButton, a2: v12);
  this->m_pWorkCameraParentButton->SetKeyBoardInputEnabled(this: this->m_pWorkCameraParentButton, a2: false);
  v13 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_referenceframe_active", a3: 0);
  this->m_StateIconIndices[0] = vgui::ImageList::AddImage(this: &this->m_Images, image: v13);
  v14 = g_pVGuiSchemeManager->GetImage(
          this: g_pVGuiSchemeManager,
          a2: "tools/ifm/icon_referenceframe_active_hidden",
          a3: 0);
  this->m_StateIconIndices[1] = vgui::ImageList::AddImage(this: &this->m_Images, image: v14);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked", a3: 0);
  this->m_StateIconIndices[2] = vgui::ImageList::AddImage(this: &this->m_Images, image: v15);
  v16 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_grey", a3: 0);
  this->m_StateIconIndices[3] = vgui::ImageList::AddImage(this: &this->m_Images, image: v16);
  v17 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world", a3: 0);
  this->m_StateIconIndices[4] = vgui::ImageList::AddImage(this: &this->m_Images, image: v17);
  v18 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world_grey", a3: 0);
  this->m_StateIconIndices[5] = vgui::ImageList::AddImage(this: &this->m_Images, image: v18);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A1150
// Name: private: int CAnimGroupTree::AddItemToTree(enum AnimTreeItemType_t,char const __near *,int,class Color const __near &,class CDmElement __near *,class CDmeAnimationSet __near *,class CDmeControlGroup __near *,bool,enum SelectionState_t,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddItemToTree(
        CAnimGroupTree *this,
        AnimTreeItemType_t itemType,
        char *label,
        int parentIndex,
        const Color *fg,
        CExpressionCalculator *pElement,
        CExpressionCalculator *pAnimSet,
        CExpressionCalculator *pControlGroup,
        Color bExpandable,
        SelectionState_t selection,
        TransformComponent_t nComponentFlags)
{
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  DmElementHandle_t *Transform; // eax
  int v16; // ebx
  CAnimGroupStateIconSet *v17; // eax
  CAnimGroupStateIconSet *v18; // eax
  int v19; // ebx
  void (__thiscall *SetItemSelectionBgColor)(vgui::TreeView *, int, const Color *); // edx
  DmElementHandle_t hElement; // [esp+24h] [ebp+18h]
  DmElementHandle_t hAnimSet; // [esp+28h] [ebp+1Ch]
  DmElementHandle_t hControlGroup; // [esp+2Ch] [ebp+20h]

  if ( pElement != nullptr )
    hElement = CCodecBuffer_Block::GetBufferType(this: pElement);
  else
    hElement = DMELEMENT_HANDLE_INVALID;
  if ( pAnimSet != nullptr )
    hAnimSet = CCodecBuffer_Block::GetBufferType(this: pAnimSet);
  else
    hAnimSet = DMELEMENT_HANDLE_INVALID;
  if ( pControlGroup != nullptr )
    hControlGroup = CCodecBuffer_Block::GetBufferType(this: pControlGroup);
  else
    hControlGroup = DMELEMENT_HANDLE_INVALID;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "item", firstKey: "text", firstValue: label);
  else
    v14 = nullptr;
  KeyValues::SetInt(this: v14, keyName: "droppable", value: 1);
  KeyValues::SetInt(this: v14, keyName: "itemType", value: itemType);
  KeyValues::SetInt(this: v14, keyName: "handle", value: hElement);
  KeyValues::SetInt(this: v14, keyName: "animset", value: hAnimSet);
  KeyValues::SetInt(this: v14, keyName: "controlgroup", value: hControlGroup);
  KeyValues::SetInt(this: v14, keyName: "selection", value: selection);
  KeyValues::SetInt(this: v14, keyName: "componentFlags", value: nComponentFlags);
  KeyValues::SetInt(this: v14, keyName: "Expand", value: bExpandable._color[0] != 0);
  if ( pElement != nullptr
    && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))pElement->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: pElement,
         a2: CDmeTransformControl::m_classType.u) != 0
    && (Transform = CDmeTransformControl::GetTransform(this: (CDmeTransformControl *)pElement)) != nullptr )
  {
    bExpandable = (Color)CDmeTransform::GetDag(this: (CDmeTransform *)Transform);
  }
  else
  {
    bExpandable = 0;
  }
  if ( this->m_bStateInterface )
  {
    v16 = 0;
    if ( itemType == ANIMTREE_ITEM_COMPONENT )
    {
      if ( nComponentFlags == TRANSFORM_COMPONENT_POSITION )
      {
        v16 = 2;
      }
      else if ( nComponentFlags == TRANSFORM_COMPONENT_ROTATION )
      {
        v16 = 3;
      }
    }
    else
    {
      v16 = itemType == ANIMTREE_ITEM_CONTROL;
    }
    if ( bExpandable != 0 && v16 != 0 )
    {
      v17 = (CAnimGroupStateIconSet *)operator new(nSize: 0x164u);
      if ( v17 != nullptr )
        v18 = CAnimGroupStateIconSet::CAnimGroupStateIconSet(
                this: v17,
                pParent: this,
                pchName: label,
                itemType: v16,
                pDag: *(CDmeDag **)&bExpandable,
                imageList: &this->m_Images,
                pImageIndexMap: (vgui::Panel *)this->m_StateIconIndices);
      else
        v18 = nullptr;
      KeyValues::SetPtr(this: v14, keyName: "stateIconSet", value: v18);
    }
  }
  v19 = this->AddItem(this, a2: v14, a3: parentIndex);
  this->SetItemFgColor(this, a2: v19, a3: fg);
  this->SetItemSelectionTextColor(this, a2: v19, a3: fg);
  this->SetSilentMode(this, a2: true);
  if ( selection == SELECT_MORPH )
  {
    bExpandable = (Color)-2139062144;
  }
  else
  {
    if ( selection != SELECT_MULTI_PARTIAL )
    {
      SetItemSelectionBgColor = this->SetItemSelectionBgColor;
      bExpandable = (Color)0x80000000;
      SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
      this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
      this->RemoveSelectedItem(this, a2: v19);
      goto LABEL_37;
    }
    bExpandable = (Color)1077969024;
  }
  this->SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
  this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
  this->AddSelectedItem(this, a2: v19, a3: false, a4: false, a5: true);
LABEL_37:
  if ( (unsigned int)itemType <= ANIMTREE_ITEM_GROUP )
    this->SetLabelEditingAllowed(this, a2: v19, a3: true);
  this->SetSilentMode(this, a2: false);
  this->ExpandItem(this, a2: v19, a3: false);
  KeyValues::deleteThis(this: v14);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x104A1420
// Name: public: virtual void CAnimGroupTree::GetSelectedItemsForDrag(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GetSelectedItemsForDrag(
        CAnimGroupTree *this,
        AnimTreeItemType_t nPrimaryDragItem,
        CUtlVector<int,CUtlMemory<int,int> > *list)
{
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int i; // esi
  int v6; // [esp-14h] [ebp-3Ch]
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-20h] BYREF
  int nNumSelected; // [esp+1Ch] [ebp-Ch]
  CDmeControlGroup *pParentGroup; // [esp+20h] [ebp-8h] BYREF
  CDmeControlGroup *pPrimaryParentGroup; // [esp+24h] [ebp-4h] BYREF

  GetSelectedItems = this->GetSelectedItems;
  memset(&selectedItems, 0, sizeof(selectedItems));
  GetSelectedItems(this, a2: &selectedItems);
  nNumSelected = selectedItems.m_Size;
  if ( selectedItems.m_Size > 0 )
  {
    pPrimaryParentGroup = nullptr;
    CAnimGroupTree::GetTreeItemData(
      this,
      nTreeIndex: nPrimaryDragItem,
      pItemType: &nPrimaryDragItem,
      ppParentAnimationSet: nullptr,
      ppControlGroup: &pPrimaryParentGroup);
    if ( nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
    {
      for ( i = 0; i < nNumSelected; ++i )
      {
        v6 = selectedItems.m_Memory.m_pMemory[i];
        pParentGroup = nullptr;
        CAnimGroupTree::GetTreeItemData(
          this,
          nTreeIndex: v6,
          pItemType: &nPrimaryDragItem,
          ppParentAnimationSet: nullptr,
          ppControlGroup: &pParentGroup);
        if ( pPrimaryParentGroup == pParentGroup && nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
          CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
            this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)list,
            elem: list->m_Size,
            src: (vgui::PageTab *const *)&selectedItems.m_Memory.m_pMemory[i]);
      }
    }
  }
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&selectedItems);
}

//------------------------------------------------------------------------------
// Address: 0x104A14F0
// Name: public: CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetControlGroupPanel *__thiscall CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
        CBaseAnimSetControlGroupPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor,
        bool bControlStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CBaseAnimationSetControl *Controller; // eax
  CAnimGroupTree *v10; // eax
  CDragDropHelperPanel *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::TreeView *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetControlGroupPanel_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v6->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
    v7->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
    v8->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hEditor.m_iPanelID = -1;
  this->m_hGroups.m_iPanelID = -1;
  this->m_pController = nullptr;
  this->m_FullSelectionColor = 0;
  this->m_PartialSelectionColor = 0;
  this->m_ContextMenuHighlightColor = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hEditor,
    pPanel: (CDragDropHelperPanel *)editor);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  v10 = (CAnimGroupTree *)operator new(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = (CDragDropHelperPanel *)CAnimGroupTree::CAnimGroupTree(
                                    this: v10,
                                    parent: this,
                                    panelName: "AnimSetGroups",
                                    groupPanel: this,
                                    bStateInterface: bControlStateInterface);
  else
    v11 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v11);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hGroups,
    pPanel: v11);
  v12 = vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::Panel::SetAutoResize(
    this: v12,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v13 = (vgui::TreeView *)vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::TreeView::SetAllowMultipleSelections(this: v13, state: true);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "root");
  else
    v15 = nullptr;
  v16 = vgui::PHandle::Get(this: &this->m_hGroups);
  ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v16->__vftable[1].GetVPanel)(a1: v16, a2: v15, a3: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A16E0
// Name: public: virtual void CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimSetControlGroupPanel::UpdateSelection(this: (CBaseAnimSetControlGroupPanel *)((char *)this - 380));
}

//------------------------------------------------------------------------------
// Address: 0x104A16F0
// Name: protected: void CBaseAnimSetControlGroupPanel::CollectExpandedItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::CollectExpandedItems(
        CBaseAnimSetControlGroupPanel *this,
        CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes,
        int nItemIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ebx
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  int v15; // edi
  vgui::Panel *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // esi
  DmElementHandle_t v19; // eax
  CDmElement *v20; // eax
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  int nChildren; // [esp+Ch] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+14h] [ebp-Ch]
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *pExpansionInfo; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  p_m_hGroups = &this->m_hGroups;
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = nItemIndex;
  if ( nItemIndex != ((int (__thiscall *)(vgui::Panel *))v4->__vftable[1].InstallMouseHandler)(a1: v4) )
  {
    v6 = vgui::PHandle::Get(this: p_m_hGroups);
    v7 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(
                        a1: v6,
                        a2: nItemIndex);
    v8 = v7;
    if ( v7 == nullptr
      || (KeyValues::GetInt(this: v7, keyName: "itemType", defaultValue: 0),
          Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1),
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int),
          v11 = v10,
          v10 == nullptr)
      || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
    {
      v11 = nullptr;
    }
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].SetVisible)(a1: v12, a2: nItemIndex) != 0 )
    {
      pExpansionInfo = nullptr;
      if ( v11 != nullptr )
      {
        pExpansionInfo = &expandedNodes->m_Memory.m_pMemory[CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>>::AddToTail(this: expandedNodes)];
        pExpansionInfo->m_pElement = v11;
        pExpansionInfo->m_ComponentFlags = TRANSFORM_COMPONENT_NONE;
      }
      v13 = vgui::PHandle::Get(this: p_m_hGroups);
      nChildren = ((int (__thiscall *)(vgui::Panel *, int))v13->__vftable[1].PerformApplySchemeSettings)(
                    a1: v13,
                    a2: nItemIndex);
      i = 0;
      if ( nChildren > 0 )
      {
        while ( 1 )
        {
          v14 = vgui::PHandle::Get(this: p_m_hGroups);
          v15 = ((int (__thiscall *)(vgui::Panel *, int, int))v14->__vftable[1].PaintTraverse)(a1: v14, a2: v5, a3: i);
          v16 = vgui::PHandle::Get(this: p_m_hGroups);
          v17 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].IsWithinTraverse)(
                               a1: v16,
                               a2: v15);
          v18 = v17;
          if ( v17 != nullptr )
          {
            childItemType = KeyValues::GetInt(this: v17, keyName: "itemType", defaultValue: 0);
            v19 = KeyValues::GetInt(this: v18, keyName: "handle", defaultValue: -1);
            v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v19);
            if ( v20 != nullptr )
              v20->IsA(this: v20, a2: CDmElement::m_classType);
          }
          if ( childItemType == ANIMTREE_ITEM_COMPONENT )
          {
            v21 = vgui::PHandle::Get(this: p_m_hGroups);
            if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v21->__vftable[1].SetVisible)(a1: v21, a2: v15) != 0
              && pExpansionInfo != nullptr )
            {
              v22 = vgui::PHandle::Get(this: p_m_hGroups);
              v23 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v22->__vftable[1].IsWithinTraverse)(
                                   a1: v22,
                                   a2: v15);
              pExpansionInfo->m_ComponentFlags |= KeyValues::GetInt(
                                                    this: v23,
                                                    keyName: "componentFlags",
                                                    defaultValue: 0);
            }
          }
          else
          {
            CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, expandedNodes, nItemIndex: v15);
          }
          if ( ++i >= nChildren )
            break;
          v5 = nItemIndex;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A18E0
// Name: public: int CAnimGroupTree::AddAnimationSetToTree(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddAnimationSetToTree(CAnimGroupTree *this, CDmeAnimationSet *pAnimSet)
{
  CDmeAnimationSet *v2; // edi
  CDmeControlGroup *RootControlGroup; // ebx
  bool v6; // zf
  char v7; // al
  char *m_Id; // eax
  int parentIndex; // [esp+Ch] [ebp-8h]
  SelectionState_t selection; // [esp+10h] [ebp-4h]

  v2 = pAnimSet;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  if ( !CBaseAnimationSetControl::IsControlGroupVisible(
          this: this->m_pGroupPanel->m_pController,
          pGroup: RootControlGroup) )
    return -1;
  parentIndex = this->GetRootItemIndex(this);
  selection = CBaseAnimationSetControl::GetSelectionState(this: this->m_pGroupPanel->m_pController, pAnimSet: v2);
  pAnimSet = (CDmeAnimationSet *)this->m_RootColor;
  if ( !CDmeControlGroup::IsSelectable(this: RootControlGroup)
    || (v6 = !CDmeControlGroup::IsVisible(this: RootControlGroup), v7 = -1, v6) )
  {
    v7 = 64;
  }
  HIBYTE(pAnimSet) = v7;
  m_Id = (char *)v2->m_Name.m_Storage.u.CDmElement::m_Id;
  if ( m_Id == (char *)-1 )
    m_Id = (char *)&var;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_ANIMSET,
           label: m_Id,
           parentIndex,
           fg: (const Color *)&pAnimSet,
           pElement: (CExpressionCalculator *)v2,
           pAnimSet: (CExpressionCalculator *)v2,
           pControlGroup: nullptr,
           bExpandable: (Color)1,
           selection,
           nComponentFlags: TRANSFORM_COMPONENT_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x104A19A0
// Name: public: int CAnimGroupTree::AddControlGroupToTree(int,class CDmeControlGroup __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddControlGroupToTree(
        CAnimGroupTree *this,
        int parentIndex,
        CDmeControlGroup *pControlGroup,
        CDmeControlGroup *pParentGroup,
        CDmeAnimationSet *pAnimSet)
{
  CDmeControlGroup *v5; // esi
  SelectionState_t SelectionState; // eax
  SelectionState_t v8; // ebx
  bool v9; // zf
  char v10; // al
  char *m_Id; // eax

  v5 = pControlGroup;
  SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pGroupPanel->m_pController, pControlGroup);
  pControlGroup = (CDmeControlGroup *)v5->m_GroupColor.m_Storage;
  v8 = SelectionState;
  if ( !CDmeControlGroup::IsSelectable(this: v5) || (v9 = !CDmeControlGroup::IsVisible(this: v5), v10 = -1, v9) )
    v10 = 64;
  HIBYTE(pControlGroup) = v10;
  m_Id = (char *)v5->m_Name.m_Storage.u.CDmElement::m_Id;
  if ( m_Id == (char *)-1 )
    m_Id = (char *)&var;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_GROUP,
           label: m_Id,
           parentIndex,
           fg: (const Color *)&pControlGroup,
           pElement: (CExpressionCalculator *)v5,
           (CExpressionCalculator *)pAnimSet,
           pControlGroup: (CExpressionCalculator *)pParentGroup,
           bExpandable: (Color)1,
           selection: v8,
           nComponentFlags: TRANSFORM_COMPONENT_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x104A1A20
// Name: public: int CAnimGroupTree::AddControlToTree(int,class CDmElement __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddControlToTree(
        CAnimGroupTree *this,
        int parentIndex,
        CExpressionCalculator *pControl,
        CDmeControlGroup *pControlGroup,
        CDmeAnimationSet *pAnimSet)
{
  CExpressionCalculator *v5; // edi
  unsigned __int8 v6; // al
  CDmeControlGroup *v7; // ebx
  TransformComponent_t v8; // esi
  bool v9; // zf
  char v10; // al
  char *m_nAllocationCount; // eax
  Color bTransformControl; // [esp+10h] [ebp-8h]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v5 = pControl;
  selection = CBaseAnimationSetControl::GetSelectionState(
                this: this->m_pGroupPanel->m_pController,
                (CDmElement *)pControl,
                componentFlags: TRANSFORM_COMPONENT_ALL);
  v6 = (*((int (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v5,
         a2: CDmeTransformControl::m_classType.u);
  v7 = pControlGroup;
  pControl = (CExpressionCalculator *)pControlGroup->m_ControlColor.m_Storage;
  bTransformControl._color[0] = v6;
  v8 = v6 != 0 ? TRANSFORM_COMPONENT_ALL : TRANSFORM_COMPONENT_NONE;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v9 = !CDmeControlGroup::IsVisible(this: v7), v10 = -1, v9) )
  {
    v10 = 64;
  }
  HIBYTE(pControl) = v10;
  m_nAllocationCount = (char *)v5->m_varNames.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount == (char *)-1 )
    m_nAllocationCount = (char *)&var;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_CONTROL,
           label: m_nAllocationCount,
           parentIndex,
           fg: (const Color *)&pControl,
           pElement: v5,
           (CExpressionCalculator *)pAnimSet,
           pControlGroup: (CExpressionCalculator *)v7,
           bExpandable: bTransformControl,
           selection,
           nComponentFlags: v8);
}

//------------------------------------------------------------------------------
// Address: 0x104A1AD0
// Name: public: void CAnimGroupTree::AddTransformComponentsToTree(int,class CDmeTransformControl __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddTransformComponentsToTree(
        CAnimGroupTree *this,
        int nParentIndex,
        CDmeTransformControl *pControl,
        CDmeControlGroup *pControlGroup,
        CDmeAnimationSet *pAnimSet,
        SelectionState_t nParentComponentFlags)
{
  char SelectionComponentFlags; // si
  CUtlSymbolLarge::<unnamed_type_u> v9; // eax
  bool v10; // zf
  unsigned __int8 v11; // al
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> *v15; // eax
  CFmtStrN<256> *v16; // eax
  SelectionState_t v17; // esi
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> *v19; // eax
  CFmtStrN<256> *v20; // eax
  int v21; // esi
  CExpressionCalculator *v22; // [esp-14h] [ebp-134h]
  CExpressionCalculator *v23; // [esp-10h] [ebp-130h]
  Color v24; // [esp-Ch] [ebp-12Ch]
  SelectionState_t v25; // [esp-8h] [ebp-128h]
  TransformComponent_t v26; // [esp-4h] [ebp-124h]
  CFmtStrN<256> v27; // [esp+Ch] [ebp-114h] BYREF
  SelectionState_t rotSelection; // [esp+118h] [ebp-8h]
  Color color; // [esp+11Ch] [ebp-4h] BYREF
  const char *pControla; // [esp+12Ch] [ebp+Ch]
  SelectionState_t pControlGroupa; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupb; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupc; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupd; // [esp+130h] [ebp+10h]
  SelectionState_t posSelection; // [esp+138h] [ebp+18h]

  SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                              this: this->m_pGroupPanel->m_pController,
                              pControl);
  v9.m_Id = (int)pControl->m_Name.m_Storage.u;
  pControla = &var;
  if ( v9.m_Id != -1 )
    pControla = (const char *)v9.m_Id;
  color = pControlGroup->m_ControlColor.m_Storage;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v10 = !CDmeControlGroup::IsVisible(this: pControlGroup), v11 = -1, v10) )
  {
    v11 = 64;
  }
  color._color[3] = v11;
  if ( nParentComponentFlags == 63 )
  {
    if ( (SelectionComponentFlags & 7) == 7 )
      posSelection = SELECT_MORPH;
    else
      posSelection = 2 * ((SelectionComponentFlags & 7) != 0) + 1;
    v12 = SelectionComponentFlags & 0x38;
    if ( v12 == 56 )
      rotSelection = SELECT_MORPH;
    else
      rotSelection = 2 * (v12 > 0) + 1;
    v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v13->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      (CExpressionCalculator *)pAnimSet,
      (CExpressionCalculator *)pControlGroup,
      bExpandable: (Color)1,
      selection: posSelection,
      nComponentFlags: TRANSFORM_COMPONENT_POSITION);
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION;
    v25 = rotSelection;
    v24 = (Color)1;
    v23 = (CExpressionCalculator *)pControlGroup;
    v22 = (CExpressionCalculator *)pAnimSet;
LABEL_36:
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v14->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet: v22,
      pControlGroup: v23,
      bExpandable: v24,
      selection: v25,
      nComponentFlags: v26);
    return;
  }
  if ( nParentComponentFlags != (SELECT_MODIFY|SELECT_MULTI_PARTIAL) )
  {
    if ( nParentComponentFlags != 56 )
      return;
    if ( (SelectionComponentFlags & 8) != 0 )
      pControlGroupc = SELECT_MORPH;
    else
      pControlGroupc = 2 * ((SelectionComponentFlags & 8) != 0) + 1;
    v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.x", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v19->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      (CExpressionCalculator *)pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupc,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_X);
    if ( (SelectionComponentFlags & 0x10) != 0 )
      pControlGroupd = SELECT_MORPH;
    else
      pControlGroupd = 2 * ((SelectionComponentFlags & 0x10) != 0) + 1;
    v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.y", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v20->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      (CExpressionCalculator *)pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupd,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_Y);
    if ( (SelectionComponentFlags & 0x20) != 0 )
      v21 = 2;
    else
      v21 = 1;
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.z", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION_Z;
    v25 = v21;
    v24 = 0;
    v23 = nullptr;
    v22 = (CExpressionCalculator *)pAnimSet;
    goto LABEL_36;
  }
  if ( (SelectionComponentFlags & 1) != 0 )
    pControlGroupa = SELECT_MORPH;
  else
    pControlGroupa = 2 * ((SelectionComponentFlags & 1) != 0) + 1;
  v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.x", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v15->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    (CExpressionCalculator *)pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupa,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_X);
  if ( (SelectionComponentFlags & 2) != 0 )
    pControlGroupb = SELECT_MORPH;
  else
    pControlGroupb = 2 * ((SelectionComponentFlags & 2) != 0) + 1;
  v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.y", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v16->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    (CExpressionCalculator *)pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupb,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Y);
  if ( (SelectionComponentFlags & 4) != 0 )
    v17 = SELECT_MORPH;
  else
    v17 = SELECT_NORMAL;
  v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.z", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v18->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    (CExpressionCalculator *)pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: v17,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Z);
}

//------------------------------------------------------------------------------
// Address: 0x104A1E10
// Name: private: void CAnimGroupTree::AddDmeControlGroup(int,class CDmeAnimationSet __near *,class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddDmeControlGroup(
        CAnimGroupTree *this,
        int nParentItemIndex,
        CDmeAnimationSet *pAnimationSet,
        CDmeControlGroup *pGroup)
{
  int v5; // ebx
  CDmElement *v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  CDmElement *v9; // eax
  CExpressionCalculator *v10; // esi
  int nControls; // [esp+20h] [ebp+10h]
  int nControlsa; // [esp+20h] [ebp+10h]

  v5 = 0;
  nControls = pGroup->m_Children.m_Storage.m_Size;
  if ( nControls > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = (CDmeControlGroup *)v6;
      if ( v6 != nullptr
        && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType)
        && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v7) != 0 )
      {
        CAnimGroupTree::AddControlGroupToTree(
          this,
          parentIndex: nParentItemIndex,
          pControlGroup: v7,
          pParentGroup: pGroup,
          pAnimSet: pAnimationSet);
      }
      ++v5;
    }
    while ( v5 < nControls );
  }
  v8 = 0;
  nControlsa = pGroup->m_Controls.m_Storage.m_Size;
  if ( nControlsa > 0 )
  {
    do
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Controls.m_Storage.m_Memory.m_pMemory[v8]);
      v10 = (CExpressionCalculator *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmElement::m_classType) )
        CAnimGroupTree::AddControlToTree(
          this,
          parentIndex: nParentItemIndex,
          pControl: v10,
          pControlGroup: pGroup,
          pAnimSet: pAnimationSet);
      ++v8;
    }
    while ( v8 < nControlsa );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A1EF0
// Name: public: virtual void CAnimGroupTree::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateChildrenOfNode(CAnimGroupTree *this, int itemIndex)
{
  CDmeAnimationSet *i; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  CDmElement *ElementKey; // eax
  CDmeAnimationSet *v7; // ebx
  bool v8; // al
  CDmElement *v9; // eax
  CDmeControlGroup *v10; // ebx
  SelectionState_t v11; // edi
  CDmeControlGroup *RootControlGroup; // eax
  CDmeControlGroup *v13; // eax
  CDmeTransformControl *v14; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-10h] BYREF
  int Int; // [esp+10h] [ebp-Ch]
  CDmElement *pElement; // [esp+14h] [ebp-8h]
  CDmeAnimationSet *pAnimationSet; // [esp+18h] [ebp-4h]

  if ( this->GetNumChildren(this, a2: itemIndex) <= 0 )
  {
    if ( itemIndex == this->GetRootItemIndex(this) )
    {
      itemType = (AnimTreeItemType_t)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pGroupPanel->m_pController);
      Int = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType) )
      {
        CAnimGroupTree::AddAnimationSetToTree(this, pAnimSet: i);
      }
    }
    else
    {
      v4 = this->GetItemData(this, a2: itemIndex);
      v5 = v4;
      if ( v4 != nullptr )
      {
        Int = KeyValues::GetInt(this: v4, keyName: "itemType", defaultValue: 0);
        pElement = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "handle");
        ElementKey = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "animset");
        v7 = (CDmeAnimationSet *)ElementKey;
        if ( ElementKey == nullptr
          || (v8 = ElementKey->IsA(this: ElementKey, a2: CDmeAnimationSet::m_classType), pAnimationSet = v7, !v8) )
        {
          pAnimationSet = nullptr;
        }
        v9 = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "controlgroup");
        v10 = (CDmeControlGroup *)v9;
        if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeControlGroup::m_classType) )
          v10 = nullptr;
        v11 = KeyValues::GetInt(this: v5, keyName: "componentFlags", defaultValue: 0);
        switch ( Int )
        {
          case 0:
            RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet);
            CAnimGroupTree::AddDmeControlGroup(
              this,
              nParentItemIndex: itemIndex,
              pAnimationSet,
              pGroup: RootControlGroup);
            break;
          case 1:
            v13 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement);
            CAnimGroupTree::AddDmeControlGroup(this, nParentItemIndex: itemIndex, pAnimationSet, pGroup: v13);
            break;
          case 2:
          case 3:
            v14 = CastElement<CDmeTransformControl>(pElement);
            if ( v14 != nullptr )
              CAnimGroupTree::AddTransformComponentsToTree(
                this,
                nParentIndex: itemIndex,
                pControl: v14,
                pControlGroup: v10,
                pAnimSet: pAnimationSet,
                nParentComponentFlags: v11);
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A20B0
// Name: public: void CBaseAnimSetControlGroupPanel::RebuildTree(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::RebuildTree(CBaseAnimSetControlGroupPanel *this, bool bRestoreExpansion)
{
  vgui::Panel *v3; // eax
  int v4; // eax
  KeyValues *v5; // ebx
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *v6; // ecx
  vgui::Panel *v7; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // ebx
  vgui::Panel *v15; // eax
  vgui::Panel_vtbl *v16; // esi
  int v17; // eax
  vgui::Panel *v18; // eax
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  vgui::Panel *v23; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  CDmeAnimationSet *i; // eax
  CAnimGroupTree *v26; // eax
  vgui::Panel *v27; // eax
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ecx
  vgui::Panel *v29; // edi
  vgui::Panel *v30; // ebx
  vgui::Panel_vtbl *v31; // esi
  int v32; // eax
  CDmeAnimationSet *v33; // [esp-4h] [ebp-2Ch]
  CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > expandedNodes; // [esp+Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-8h] BYREF
  vgui::Panel *bRestoreExpansiona; // [esp+30h] [ebp+8h]

  if ( bRestoreExpansion )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].Repaint)(a1: v3);
    v5 = nullptr;
    v6 = nullptr;
    expandedNodes.m_Memory.m_pMemory = nullptr;
    expandedNodes.m_Memory.m_nAllocationCount = v4;
    expandedNodes.m_Memory.m_nGrowSize = 0;
    if ( v4 != 0 )
    {
      v6 = (CBaseAnimSetControlGroupPanel::ElementExpansion_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v4);
      expandedNodes.m_Memory.m_pMemory = v6;
    }
    expandedNodes.m_pElements = v6;
    expandedNodes.m_Size = 0;
    v7 = vgui::PHandle::Get(this: &this->m_hGroups);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].Think)(a1: v7);
    CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, &expandedNodes, nItemIndex: v8);
    v9 = vgui::PHandle::Get(this: &this->m_hGroups);
    v9->SetSilentMode(this: v9, a2: true);
    v10 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v10->__vftable[1].GetClipRect)(a1: v10);
    v11 = vgui::PHandle::Get(this: &this->m_hGroups);
    v11->SetSilentMode(this: v11, a2: false);
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v5 = KeyValues::KeyValues(this: v12, setName: "root");
    v13 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v13->__vftable[1].GetVPanel)(a1: v13, a2: v5, a3: -1);
    v14 = vgui::PHandle::Get(this: &this->m_hGroups);
    v15 = vgui::PHandle::Get(this: &this->m_hGroups);
    v16 = v15->__vftable;
    bRestoreExpansiona = v15;
    v17 = ((int (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].Think)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v16[1].dtr_Panel)(a1: bRestoreExpansiona, a2: v17);
    CBaseAnimSetControlGroupPanel::ExpandItems(this, &expandedNodes);
    CBaseAnimSetControlGroupPanel::UpdateSelection(this);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&expandedNodes);
  }
  else
  {
    v18 = vgui::PHandle::Get(this: &this->m_hGroups);
    v18->SetSilentMode(this: v18, a2: true);
    v19 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v19->__vftable[1].GetClipRect)(a1: v19);
    v20 = vgui::PHandle::Get(this: &this->m_hGroups);
    v20->SetSilentMode(this: v20, a2: false);
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "root");
    else
      v22 = nullptr;
    v23 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v23->__vftable[1].GetVPanel)(a1: v23, a2: v22, a3: -1);
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    if ( AnimationSetClip != nullptr )
    {
      traversal.m_pFilmClip = AnimationSetClip;
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        v33 = i;
        v26 = (CAnimGroupTree *)vgui::PHandle::Get(this: &this->m_hGroups);
        CAnimGroupTree::AddAnimationSetToTree(this: v26, pAnimSet: v33);
      }
      v27 = vgui::PHandle::Get(this: &this->m_hGroups);
      p_m_hGroups = &this->m_hGroups;
      v29 = v27;
      v30 = vgui::PHandle::Get(this: p_m_hGroups);
      v31 = v30->__vftable;
      v32 = ((int (__thiscall *)(vgui::Panel *, int))v29->__vftable[1].Think)(a1: v29, a2: 1);
      ((void (__thiscall *)(vgui::Panel *, int))v31[1].dtr_Panel)(a1: v30, a2: v32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A2300
// Name: public: virtual void CAnimGroupTree::OnLabelChanged(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnLabelChanged(
        CAnimGroupTree *this,
        int nItemIndex,
        const char *pOldString,
        char *pNewString)
{
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  CExpressionCalculator *v8; // esi
  DmElementHandle_t Int; // eax
  CDmElement *v10; // eax
  CDmeControlGroup *RootControlGroup; // eax
  const char *v12; // esi
  CDmeControlGroup *v13; // edi
  int UniqueNameIndex; // eax
  KeyValues *v15; // eax
  int BufferType; // eax
  vgui::Panel *v17; // eax
  CFmtStrN<256> v18; // [esp+10h] [ebp-124h] BYREF
  CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > v19; // [esp+11Ch] [ebp-18h] BYREF
  CAnimGroupTree *v20; // [esp+130h] [ebp-4h]
  CDmeControlGroup *v21; // [esp+13Ch] [ebp+8h]

  StartUndo = g_pDataModel->StartUndo;
  v6 = nullptr;
  v20 = this;
  StartUndo(this: g_pDataModel, a2: "Change group label", a3: "Change group label", a4: 0);
  v7 = this->GetItemData(this, a2: nItemIndex);
  if ( v7 == nullptr )
  {
    v8 = nullptr;
LABEL_8:
    v21 = nullptr;
    goto LABEL_9;
  }
  Int = KeyValues::GetInt(this: v7, keyName: "handle", defaultValue: -1);
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
  v8 = (CExpressionCalculator *)v10;
  if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType) )
    v8 = nullptr;
  if ( v8 == nullptr )
    goto LABEL_8;
  v21 = (CDmeControlGroup *)v8;
  if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeControlGroup::m_classType.u) == 0 )
    goto LABEL_8;
LABEL_9:
  if ( v8 == nullptr
    || (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeAnimationSet::m_classType.u) == 0 )
  {
    v8 = nullptr;
  }
  if ( v21 != nullptr )
  {
    RootControlGroup = CDmeControlGroup::FindRootControlGroup(this: v21);
    v12 = pNewString;
    v13 = RootControlGroup;
    if ( RootControlGroup != nullptr
      && CDmeControlGroup::FindChildByName(
           this: RootControlGroup,
           pchName: pNewString,
           recursive: true,
           pParentGroup: nullptr) != nullptr )
    {
      memset(&v19, 0, sizeof(v19));
      CDmeControlGroup::GetAllChildren(
        this: v13,
        childGroupList: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&v19);
      UniqueNameIndex = GenerateUniqueNameIndex(
                          prefix: v12,
                          array: (const CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&v19,
                          startindex: 0);
      CFmtStrN<256>::CFmtStrN<256>(this: &v18, pszFormat: "%s%d", v12, UniqueNameIndex);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pNewString, a3: v18.m_szBuf);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: v21->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
      CBaseAnimSetControlGroupPanel::RebuildTree(this: v20->m_pGroupPanel, bRestoreExpansion: true);
      CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: &v19);
    }
    else
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pNewString, a3: v12);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: v21->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
    }
  }
  else if ( v8 != nullptr )
  {
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v6 = KeyValues::KeyValues(this: v15, setName: "SetAnimationSetName", firstKey: "text", firstValue: pNewString);
    BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
    KeyValues::SetInt(this: v6, keyName: "animset", value: BufferType);
    v17 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
    ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: v17,
      a3: v6,
      a4: 0);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x104A2520
// Name: public: void CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(
        CBaseAnimSetControlGroupPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel::RebuildTree(this, bRestoreExpansion: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049E380
// Name: class CDmeControlGroup const __near * CastElement<class CDmeControlGroup>(class CDmElement const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CDmeControlGroup *__cdecl CastElement<CDmeControlGroup>(const CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: (CDmElement *)pElement,
         a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id) )
  {
    return (const CDmeControlGroup *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049EA20
// Name: class CDmeAnimationSet __near * FindReferringElement<class CDmeAnimationSet>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl FindReferringElement<CDmeAnimationSet>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeAnimationSet *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048FEC0
// Name: public: static char const __near * CBaseAnimSetControlGroupPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetControlGroupPanel::GetPanelClassName()
{
  return "CBaseAnimSetControlGroupPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048FED0
// Name: public: static char const __near * CAnimGroupStateIconSet::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::GetPanelClassName()
{
  return "CAnimGroupStateIconSet";
}

//------------------------------------------------------------------------------
// Address: 0x0048FEE0
// Name: public: static char const __near * CAnimGroupStateIconSet::IconButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupStateIconSet::IconButton::GetPanelClassName()
{
  return "IconButton";
}

//------------------------------------------------------------------------------
// Address: 0x0048FEF0
// Name: public: virtual void CAnimGroupStateIconSet::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::PerformLayout(CAnimGroupStateIconSet *this)
{
  int Tall; // eax
  CAnimGroupStateIconSet::IconButton *m_pLockButton; // ecx

  Tall = vgui::Panel::GetTall(this);
  m_pLockButton = this->m_pLockButton;
  if ( m_pLockButton != nullptr )
    vgui::Panel::SetBounds(this: m_pLockButton, x: 1, y: 1, wide: Tall - 1, tall: Tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x0048FF10
// Name: public: void CAnimGroupStateIconSet::IconButtonRightClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButtonRightClick(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  bool bPosition; // [esp+13h] [ebp-1h]

  m_StateType = this->m_StateType;
  v3 = 1;
  if ( m_StateType == 1 || (bPosition = false, m_StateType == 2) )
    bPosition = true;
  if ( m_StateType != 1 && m_StateType != 3 )
    v3 = 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OpenLockContextMenu");
  else
    v5 = nullptr;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
  KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
  KeyValues::SetInt(this: v5, keyName: "position", value: bPosition);
  KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
  ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x0048FFD0
// Name: private: virtual void CAnimGroupStateIconSet::OnLockDagButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnLockDagButton(CAnimGroupStateIconSet *this)
{
  int m_StateType; // eax
  char v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int BufferType; // eax
  CAnimGroupStateIconSet_vtbl *v7; // ebx
  int v8; // eax
  bool bPosition; // [esp+13h] [ebp-1h]

  if ( this->m_pDag != nullptr )
  {
    m_StateType = this->m_StateType;
    v3 = 1;
    if ( m_StateType == 1 || (bPosition = false, m_StateType == 2) )
      bPosition = true;
    if ( m_StateType != 1 && m_StateType != 3 )
      v3 = 0;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ToggleDagLock");
    else
      v5 = nullptr;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
    KeyValues::SetInt(this: v5, keyName: "targetDag", value: BufferType);
    KeyValues::SetInt(this: v5, keyName: "position", value: bPosition);
    KeyValues::SetInt(this: v5, keyName: "rotation", value: v3 != 0);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
    ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v7->PostMessage)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004900A0
// Name: public: static char const __near * CAnimGroupTree::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAnimGroupTree::GetPanelClassName()
{
  return "CAnimGroupTree";
}

//------------------------------------------------------------------------------
// Address: 0x004900B0
// Name: public: enum TransformComponent_t CAnimGroupTree::GetItemComponentFlags(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::GetItemComponentFlags(CAnimGroupTree *this, int nTreeIndex)
{
  KeyValues *v2; // eax

  v2 = this->GetItemData(this, a2: nTreeIndex);
  return KeyValues::GetInt(this: v2, keyName: "componentFlags", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004900E0
// Name: public: virtual void CAnimGroupTree::GenerateContextMenu(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateContextMenu(CAnimGroupTree *this, int itemIndex, int x, int y)
{
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  CAnimGroupTree_vtbl *v7; // edi
  int v8; // eax

  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "TreeViewOpenContextMenu", firstKey: "itemID", firstValue: itemIndex);
  else
    v6 = nullptr;
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v6, a3: 0);
  ((void (__thiscall *)(CAnimGroupTree *, int))v7->PostMessage)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00490140
// Name: private: virtual void CAnimGroupTree::OnContextMenuSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnContextMenuSelection(CAnimGroupTree *this, int itemIndex)
{
  CAnimGroupTree_vtbl *v3; // edi
  char v4; // al

  v3 = this->__vftable;
  v4 = ((int (__thiscall *)(CAnimGroupTree *, int, int, int))this->IsItemSelected)(
         a1: this,
         a2: itemIndex,
         a3: 1,
         a4: 1);
  ((void (__thiscall *)(CAnimGroupTree *, int, bool))v3->AddSelectedItem)(a1: this, a2: itemIndex, a3: v4 == 0);
}

//------------------------------------------------------------------------------
// Address: 0x00490180
// Name: private: virtual void CAnimGroupTree::OnClearWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnClearWorkCameraParent(CAnimGroupTree *this)
{
  CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004901A0
// Name: public: virtual void CAnimGroupTree::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::PaintBackground(CAnimGroupTree *this)
{
  int Tall; // edi

  vgui::Panel::PaintBackground(this);
  if ( this->m_bStateInterface )
  {
    Tall = vgui::Panel::GetTall(this);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_StateColumnColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: this->m_nStateColumnWidth, a5: Tall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004901F0
// Name: public: virtual void CAnimGroupTree::RemoveItem(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveItem(
        CAnimGroupTree *this,
        int itemIndex,
        bool bPromoteChildren,
        bool bRecursivelyRemove)
{
  KeyValues *v5; // eax
  void *Ptr; // eax

  v5 = this->GetItemData(this, a2: abs32(itemIndex));
  if ( v5 != nullptr )
  {
    Ptr = KeyValues::GetPtr(this: v5, keyName: "stateIconSet", defaultValue: nullptr);
    if ( Ptr != nullptr )
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
  }
  vgui::TreeView::RemoveItem(this, itemIndex, bPromoteChildren, bFullDelete: bRecursivelyRemove);
}

//------------------------------------------------------------------------------
// Address: 0x00490250
// Name: public: virtual void CAnimGroupTree::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::RemoveAll(CAnimGroupTree *this)
{
  int i; // edi
  KeyValues *v3; // eax
  void *Ptr; // eax

  for ( i = this->FirstItem(this); i != this->InvalidItemID(this); i = this->NextItem(this, a2: i) )
  {
    v3 = this->GetItemData(this, a2: i);
    if ( v3 != nullptr )
    {
      Ptr = KeyValues::GetPtr(this: v3, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)Ptr + 128))(a1: Ptr, a2: 1);
    }
  }
  vgui::TreeView::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x004902D0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewStartRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: true);
}

//------------------------------------------------------------------------------
// Address: 0x004902E0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewFinishRangeSelection(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::SetRangeSelectionState(this: this->m_pController, bInRangeSelection: false);
}

//------------------------------------------------------------------------------
// Address: 0x004902F0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelectionCleared(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimationSetControl::ClearSelection(this: this->m_pController);
}

//------------------------------------------------------------------------------
// Address: 0x004903D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetControlGroupPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetControlGroupPanel::GetMessageMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490400
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetControlGroupPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetControlGroupPanel::GetAnimMap(CBaseAnimSetControlGroupPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00490410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetControlGroupPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetControlGroupPanel::GetKBMap(CBaseAnimSetControlGroupPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
  `CBaseAnimSetControlGroupPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490440
// Name: public: CAnimGroupStateIconSet::IconButton::IconButton(class CAnimGroupStateIconSet __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet::IconButton *__thiscall CAnimGroupStateIconSet::IconButton::IconButton(
        CAnimGroupStateIconSet::IconButton *this,
        CAnimGroupStateIconSet *pIconSet,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Button::Button(
    this,
    parent: pIconSet,
    panelName: pName,
    text: defaultValue,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CAnimGroupStateIconSet::IconButton_vtbl *)&CAnimGroupStateIconSet::IconButton::`vftable';
  if ( `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "IconButton");
    v4->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "IconButton");
    v5->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::IconButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
    v6->pfnClassName = CAnimGroupStateIconSet::IconButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->m_pIconSet = pIconSet;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00490510
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::IconButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::IconButton::GetMessageMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490540
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::IconButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::IconButton::GetAnimMap(CAnimGroupStateIconSet::IconButton *this)
{
  return FindOrAddPanelAnimationMap(className: "IconButton");
}

//------------------------------------------------------------------------------
// Address: 0x00490550
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::IconButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::IconButton::GetKBMap(
        CAnimGroupStateIconSet::IconButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "IconButton");
  `CAnimGroupStateIconSet::IconButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490580
// Name: public: virtual void CAnimGroupStateIconSet::IconButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::IconButton::OnMousePressed(
        CAnimGroupStateIconSet::IconButton *this,
        ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    CAnimGroupStateIconSet::IconButtonRightClick(this: this->m_pIconSet);
  else
    vgui::Button::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004905B0
// Name: public: virtual void CAnimGroupStateIconSet::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::ApplySchemeSettings(CAnimGroupStateIconSet *this, vgui::IScheme *pScheme)
{
  CAnimGroupStateIconSet::IconButton_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  Color buttonColor; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, _DWORD))pScheme->GetColor)(
    a1: pScheme,
    a2: &buttonColor,
    a3: "Frame.BgColor",
    a4: 0);
  ((void (__thiscall *)(_DWORD, _DWORD))this->SetBgColor)(a1: this, a2: buttonColor);
  if ( this->m_pLockButton != nullptr )
  {
    v3 = this->m_pLockButton->__vftable;
    v4 = pScheme->GetBorder(this: pScheme, a2: "DepressedBorder");
    v3->SetDefaultBorder(this: this->m_pLockButton, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490630
// Name: private: static class CDmeDag const __near * CAnimGroupStateIconSet::GetDagFromDragElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
const CDmeDag *__cdecl CAnimGroupStateIconSet::GetDagFromDragElement(CDmeTransformControl *pElement)
{
  if ( pElement == nullptr )
    return nullptr;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return CDmeTransformControl::GetDag(this: pElement);
  }
  return ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
           a1: pElement,
           a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id)
       ? (const CDmeDag *)pElement
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00490690
// Name: public: virtual void CAnimGroupTree::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::ApplySchemeSettings(CAnimGroupTree *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  CAnimGroupTree_vtbl *v6; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v8; // al
  int v9; // eax

  v2 = pScheme;
  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  GetColor = v2->GetColor;
  pScheme = (vgui::IScheme *)-8355712;
  v5 = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "AnimSet.RootColor",
                   a4: -8355712);
  pScheme = nullptr;
  this->m_RootColor = v5;
  this->m_StateColumnColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, _DWORD))v2->GetColor)(
                                         a1: v2,
                                         a2: &pScheme,
                                         a3: "Frame.BgColor",
                                         a4: 0);
  v6 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v8 = IsProportional(this);
  v9 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
         a1: v2,
         a2: "DefaultBold",
         a3: v8);
  v6->SetFont(this, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x00490720
// Name: private: virtual void CAnimGroupTree::OnResetTransformPivot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnResetTransformPivot(CAnimGroupTree *this, int viewCenter)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  vgui::Panel *v5; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ResetTransformPivot", firstKey: "viewCenter", firstValue: viewCenter);
  else
    v4 = nullptr;
  v5 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: v5,
    a3: v4,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00490780
// Name: private: virtual void CAnimGroupTree::OnSetOverrideParent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnSetOverrideParent(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004907E0
// Name: private: virtual void CAnimGroupTree::OnOpenLockContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnOpenLockContextMenu(CAnimGroupTree *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  CAnimGroupTree_vtbl *v4; // ebx
  vgui::Panel *v5; // edi
  KeyValues *Copy; // eax

  v3 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
  v4 = this->__vftable;
  v5 = v3;
  Copy = KeyValues::MakeCopy(this: pParams);
  ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))v4->PostMessage)(
    a1: this,
    a2: v5,
    a3: Copy,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00490870
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ApplySchemeSettings(CBaseAnimSetControlGroupPanel *this, int pScheme)
{
  int v2; // esi
  int (__thiscall *v4)(int, int *, const char *, int); // eax
  Color v5; // ecx
  int (__thiscall *v6)(int, int *, const char *, int); // edx
  vgui::Panel *v7; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
  pScheme = -2139062144;
  v5 = *(Color *)v4(a1: v2, a2: &pScheme, a3: "AnimSet.FullSelectionColor", a4: -2139062144);
  pScheme = 1077969024;
  this->m_FullSelectionColor = v5;
  this->m_PartialSelectionColor = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20))(
                                              a1: v2,
                                              a2: &pScheme,
                                              a3: "AnimSet.PartialSelectionColor",
                                              a4: 1077969024);
  v6 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
  pScheme = -16737793;
  this->m_ContextMenuHighlightColor = *(Color *)v6(
                                                  a1: v2,
                                                  a2: &pScheme,
                                                  a3: "AnimSet.ContextMenuSelectionColor",
                                                  a4: -16737793);
  v7 = vgui::PHandle::Get(this: &this->m_hGroups);
  v7->ApplySchemeSettings(this: v7, a2: (vgui::IScheme *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x00490910
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewOpenContextMenu(
        CBaseAnimSetControlGroupPanel *this,
        int itemID)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax

  if ( itemID >= 0 )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v3->__vftable[1].GetAnimMap)(
      a1: v3,
      a2: itemID,
      a3: &this->m_ContextMenuHighlightColor);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = ((int (__thiscall *)(vgui::Panel *, int))v4->__vftable[1].IsWithinTraverse)(a1: v4, a2: itemID);
  v6 = vgui::PHandle::Get(this: &this->m_hEditor);
  ((void (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].OnTick)(a1: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00490A10
// Name: public: void CAnimGroupStateIconSet::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::UpdateState(CAnimGroupStateIconSet *this)
{
  vgui::Tooltip *Tooltip; // ebx
  CDmeDag *m_pDag; // ecx
  CDmeDag *OverrideParent; // eax
  CDmeDag *v5; // edi
  CDmeDag *Parent; // eax
  int m_StateType; // ecx
  bool v8; // bl
  int v9; // edx
  int v10; // eax
  vgui::IImage *Image; // eax
  vgui::Tooltip *v12; // esi
  const wchar_t *v13; // eax
  const char *m_pAsString; // edi
  char tipText[64]; // [esp+4h] [ebp-6Ch] BYREF
  char itemText[32]; // [esp+44h] [ebp-2Ch] BYREF
  vgui::Tooltip *pTooltip; // [esp+64h] [ebp-Ch]
  int nPartialLockedIcon; // [esp+68h] [ebp-8h]
  bool bRot; // [esp+6Eh] [ebp-2h] BYREF
  bool bPos; // [esp+6Fh] [ebp-1h] BYREF

  if ( this->m_pDag == nullptr )
    return;
  this->m_pLockButton->ClearImages(this: this->m_pLockButton);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  m_pDag = this->m_pDag;
  pTooltip = Tooltip;
  bPos = false;
  bRot = false;
  OverrideParent = (CDmeDag *)CDmeDag::GetOverrideParent(
                                this: m_pDag,
                                bPosition: &bPos,
                                bRotation: &bRot,
                                bIgnoreEnable: true);
  v5 = OverrideParent;
  if ( OverrideParent == nullptr )
  {
    vgui::Tooltip::SetTooltipDelay(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: Tooltip, text: "#LockButtonTip");
    return;
  }
  Parent = CDmeDag::GetParent(this: OverrideParent);
  m_StateType = this->m_StateType;
  v8 = Parent == nullptr;
  v9 = 2 * (Parent == nullptr) + 2;
  nPartialLockedIcon = 2 * (Parent == nullptr) + 3;
  v10 = 0;
  if ( m_StateType == 1 )
  {
    if ( !bPos || !bRot )
    {
      v10 = this->m_pImageIndexMap[nPartialLockedIcon];
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( m_StateType == 2 && bPos || m_StateType == 3 && bRot )
LABEL_11:
    v10 = this->m_pImageIndexMap[v9];
LABEL_12:
  Image = vgui::ImageList::GetImage(this: this->m_ImageList, imageIndex: v10);
  this->m_pLockButton->AddImage(this: this->m_pLockButton, a2: Image, a3: 0);
  v12 = pTooltip;
  if ( pTooltip != nullptr )
  {
    if ( v8 )
    {
      vgui::Tooltip::SetText(this: pTooltip, text: "#LockedToWorld");
    }
    else
    {
      v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#LockedTo");
      if ( v13 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v13, a3: itemText, a4: 32);
        m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: tipText, maxLen: 64, pFormat: "%s %s", itemText, m_pAsString);
        vgui::Tooltip::SetText(this: v12, text: tipText);
      }
    }
    vgui::Tooltip::SetTooltipDelay(this: v12, tooltipDelay: 750);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490BA0
// Name: public: virtual CAnimGroupTree::~CAnimGroupTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::~CAnimGroupTree(CAnimGroupTree *this)
{
  vgui::Panel *v2; // eax

  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::ImageList::~ImageList(this: &this->m_Images);
  vgui::TreeView::~TreeView(this);
}

//------------------------------------------------------------------------------
// Address: 0x00490C00
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupTree::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupTree::GetMessageMap(CAnimGroupTree *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupTree::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupTree::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490C30
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupTree::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupTree::GetAnimMap(CAnimGroupTree *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
}

//------------------------------------------------------------------------------
// Address: 0x00490C40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupTree::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupTree::GetKBMap(CAnimGroupTree *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupTree::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupTree::GetKBMap'::`2'::s_pMap;
  `CAnimGroupTree::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
  `CAnimGroupTree::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490C70
// Name: private: static bool CAnimGroupTree::CanAddDragIntoGroup(class CDmeControlGroup const __near *,class CDmElement const __near *,class CDmElement const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAnimGroupTree::CanAddDragIntoGroup(
        CDmeControlGroup *pTargetGroup,
        const CDmElement *pTargetElement,
        const CDmeControlGroup *pDragElement,
        bool bInsertBefore)
{
  void (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *v5; // esi
  char v6; // al
  CDmeControlGroup *Parent; // eax
  CDmeAnimationSet *pTargetGroupAnimSet; // [esp+Ch] [ebp-8h]
  char v10; // [esp+13h] [ebp-1h]

  if ( (_S1_4 & 1) == 0 )
  {
    v4 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_4 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v4)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symControls,
      a3: "controls");
  }
  if ( pTargetGroup == nullptr || pDragElement == nullptr || pTargetElement == nullptr || pDragElement == pTargetGroup )
    return false;
  pTargetGroupAnimSet = CDmeControlGroup::FindAnimationSet(this: pTargetGroup, bSearchAncestors: true);
  v5 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: pDragElement);
  v6 = ((int (__thiscall *)(_DWORD, _DWORD))pTargetElement->IsA)(
         a1: (CDmElement *)pTargetElement,
         a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id);
  v10 = v6;
  if ( v5 == nullptr )
  {
    if ( !bInsertBefore || v6 == 0 )
      return FindReferringElement<CDmeAnimationSet>(
               pElement: pDragElement,
               symAttrName: symControls,
               bMustBeInSameFile: true,
               depth: TD_ALL) == pTargetGroupAnimSet;
    return false;
  }
  if ( CDmeControlGroup::IsAncestorOfGroup(this: v5, pGroup: pTargetGroup) || bInsertBefore && v10 == 0 )
    return false;
  Parent = CDmeControlGroup::FindParent(this: v5);
  if ( Parent != nullptr )
    return CDmeControlGroup::FindAnimationSet(this: Parent, bSearchAncestors: true) == pTargetGroupAnimSet;
  else
    return pTargetGroupAnimSet == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00490D80
// Name: public: virtual void CAnimGroupTree::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAnimGroupTree::PerformLayout(CAnimGroupTree *this@<ecx>, int a2@<esi>)
{
  int i; // ebx
  KeyValues *v4; // eax
  CAnimGroupStateIconSet *Ptr; // esi
  int nPosX; // [esp+8h] [ebp-10h] BYREF
  int nWidth; // [esp+Ch] [ebp-Ch] BYREF
  int nPosY; // [esp+10h] [ebp-8h] BYREF
  int nHeight; // [esp+14h] [ebp-4h] BYREF

  vgui::TreeView::PerformLayout(this);
  for ( i = this->FirstItem(this);
        i != this->InvalidItemID(this);
        i = ((int (__thiscall *)(CAnimGroupTree *))this->NextItem)(a1: this) )
  {
    v4 = (KeyValues *)((int (__thiscall *)(CAnimGroupTree *, int, int))this->GetItemData)(a1: this, a2: i, a3: a2);
    if ( v4 != nullptr )
    {
      Ptr = (CAnimGroupStateIconSet *)KeyValues::GetPtr(this: v4, keyName: "stateIconSet", defaultValue: nullptr);
      if ( Ptr != nullptr )
      {
        if ( vgui::TreeView::GetItemBounds(this, itemIndex: i, x: &nPosX, y: &nPosY, w: &nWidth, h: &nHeight) != 0 )
        {
          CAnimGroupStateIconSet::UpdateState(this: Ptr);
          vgui::Panel::SetBounds(this: Ptr, x: 0, y: nPosY, wide: nHeight, tall: nHeight);
          ((void (__stdcall *)(int))Ptr->SetVisible)(a1: 1);
        }
        else
        {
          ((void (__stdcall *)(_DWORD))Ptr->SetVisible)(a1: 0);
        }
      }
    }
    a2 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490E50
// Name: public: virtual bool CAnimGroupStateIconSet::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupStateIconSet::IsDroppable(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  int Int; // eax
  int v5; // eax
  CDmeTransformControl *v6; // esi
  const CDmeDag *DagFromDragElement; // eax
  CDmeDag *v8; // esi

  if ( msglist->m_Size != 1 )
    return false;
  Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v6 = (CDmeTransformControl *)v5;
  if ( v5 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v6 = nullptr;
  }
  DagFromDragElement = CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v6);
  v8 = (CDmeDag *)DagFromDragElement;
  return DagFromDragElement != nullptr
      && !CDmeDag::IsAncestorOfDag(this: this->m_pDag, pDag: DagFromDragElement)
      && this->m_pDag != v8;
}

//------------------------------------------------------------------------------
// Address: 0x00490EE0
// Name: public: virtual void CAnimGroupStateIconSet::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupStateIconSet::OnPanelDropped(
        CAnimGroupStateIconSet *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  int Int; // eax
  int v4; // eax
  CDmeTransformControl *v5; // esi
  CExpressionCalculator *DagFromDragElement; // edi
  int m_StateType; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  int BufferType; // eax
  int v11; // eax
  CAnimGroupStateIconSet_vtbl *v12; // edi
  int v13; // eax
  bool bRotation; // [esp+1Bh] [ebp-1h]
  char bPosition_3; // [esp+27h] [ebp+Bh]

  if ( msglist->m_Size == 1 )
  {
    Int = KeyValues::GetInt(this: *msglist->m_Memory.m_pMemory, keyName: "dmeelement", defaultValue: -1);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v5 = (CDmeTransformControl *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    DagFromDragElement = (CExpressionCalculator *)CAnimGroupStateIconSet::GetDagFromDragElement(pElement: v5);
    if ( DagFromDragElement != nullptr )
    {
      m_StateType = this->m_StateType;
      if ( m_StateType == 1 || (bPosition_3 = 0, m_StateType == 2) )
        bPosition_3 = 1;
      if ( m_StateType == 1 || (bRotation = false, m_StateType == 3) )
        bRotation = true;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetOverrideParent");
      else
        v9 = nullptr;
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)this->m_pDag);
      KeyValues::SetInt(this: v9, keyName: "targetDag", value: BufferType);
      v11 = CCodecBuffer_Block::GetBufferType(this: DagFromDragElement);
      KeyValues::SetInt(this: v9, keyName: "parentDag", value: v11);
      KeyValues::SetInt(this: v9, keyName: "position", value: bPosition_3 != 0);
      KeyValues::SetInt(this: v9, keyName: "rotation", value: bRotation);
      v12 = this->__vftable;
      v13 = ((int (__thiscall *)(CAnimGroupStateIconSet *, KeyValues *, _DWORD))this->GetParent)(
              a1: this,
              a2: v9,
              a3: 0);
      ((void (__thiscall *)(CAnimGroupStateIconSet *, int))v12->PostMessage)(a1: this, a2: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491050
// Name: public: class CDmElement __near * CAnimGroupTree::GetTreeItemData(int,enum AnimTreeItemType_t __near *,class CDmeAnimationSet __near * __near *,class CDmeControlGroup __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAnimGroupTree::GetTreeItemData(
        CAnimGroupTree *this,
        int nTreeIndex,
        AnimTreeItemType_t *pItemType,
        CDmeAnimationSet **ppParentAnimationSet,
        CDmeControlGroup **ppControlGroup)
{
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  int Int; // eax
  int v8; // eax
  CDmeAnimationSet *v9; // esi
  int v10; // eax
  int v11; // eax
  CDmeControlGroup *v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // esi

  v5 = this->GetItemData(this, a2: nTreeIndex);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  if ( pItemType != nullptr )
    *pItemType = KeyValues::GetInt(this: v5, keyName: "itemType", defaultValue: 0);
  if ( ppParentAnimationSet != nullptr )
  {
    Int = KeyValues::GetInt(this: v6, keyName: "animset", defaultValue: -1);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: Int);
    v9 = (CDmeAnimationSet *)v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeAnimationSet::m_classType.u) == 0 )
    {
      v9 = nullptr;
    }
    *ppParentAnimationSet = v9;
  }
  if ( ppControlGroup != nullptr )
  {
    v10 = KeyValues::GetInt(this: v6, keyName: "controlgroup", defaultValue: -1);
    v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: v10);
    v12 = (CDmeControlGroup *)v11;
    if ( v11 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
           a1: v11,
           a2: CDmeControlGroup::m_classType.u) == 0 )
    {
      v12 = nullptr;
    }
    *ppControlGroup = v12;
  }
  v13 = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v13);
  v15 = v14;
  if ( v14 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
         a1: v14,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v15;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491160
// Name: public: class CDmeControlGroup __near * CAnimGroupTree::GetControlGroupForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CAnimGroupTree::GetControlGroupForTreeItem(CAnimGroupTree *this, int nItemIndex)
{
  KeyValues *v2; // eax
  int Int; // eax
  int v4; // eax
  CDmeAnimationSet *v5; // esi

  v2 = this->GetItemData(this, a2: nItemIndex);
  if ( v2 == nullptr )
    return nullptr;
  Int = KeyValues::GetInt(this: v2, keyName: "handle", defaultValue: -1);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v5 = (CDmeAnimationSet *)v4;
  if ( v4 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v5 = nullptr;
  }
  if ( v5 == nullptr )
    return nullptr;
  if ( v5->IsA(this: v5, a2: CDmeAnimationSet::m_classType) )
    return (CDmeAnimationSet *)CDmeAnimationSet::GetRootControlGroup(this: v5);
  if ( v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00491210
// Name: public: class CDmeDag __near * CAnimGroupTree::GetDagForTreeItem(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAnimGroupTree::GetDagForTreeItem(CAnimGroupTree *this, AnimTreeItemType_t nTreeItemIndex)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  int Int; // eax
  int v5; // eax
  CDmeTransformControl *v6; // esi
  CDmeTransform *Transform; // eax

  v2 = this->GetItemData(this, a2: nTreeItemIndex);
  v3 = v2;
  if ( v2 != nullptr
    && (KeyValues::GetInt(this: v2, keyName: "itemType", defaultValue: 0),
        Int = KeyValues::GetInt(this: v3, keyName: "handle", defaultValue: -1),
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: Int),
        v6 = (CDmeTransformControl *)v5,
        v5 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmElement::m_classType.u) != 0
    && v6->IsA(this: v6, a2: CDmeTransformControl::m_classType)
    && (Transform = CDmeTransformControl::GetTransform(this: v6)) != nullptr )
  {
    return CDmeTransform::GetDag(this: Transform);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004912B0
// Name: public: virtual bool CAnimGroupTree::IsItemDroppable(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::IsItemDroppable(
        CAnimGroupTree *this,
        const CDmeControlGroup *nItemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CDmeAnimationSet *ControlGroupForTreeItem; // eax
  int m_Size; // ebx
  int v7; // edi
  KeyValues *v8; // esi
  int Int; // eax
  int v10; // eax
  const CDmeControlGroup *v11; // esi
  CDmElement *pTargetElement; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *pTargetControlGroup; // [esp+10h] [ebp-8h]
  CDmeControlGroup *pParentControlGroup; // [esp+14h] [ebp-4h] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+20h] [ebp+8h]

  if ( msglist->m_Size == 0 )
    return 0;
  pParentControlGroup = nullptr;
  pTargetElement = CAnimGroupTree::GetTreeItemData(
                     this,
                     nTreeIndex: (int)nItemIndex,
                     pItemType: nullptr,
                     ppParentAnimationSet: nullptr,
                     ppControlGroup: &pParentControlGroup);
  if ( pTargetElement == nullptr )
    return 0;
  ControlGroupForTreeItem = CAnimGroupTree::GetControlGroupForTreeItem(this, (int)nItemIndex);
  pTargetControlGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
  pNewParentGroup = bInsertBefore ? pParentControlGroup : (CDmeControlGroup *)ControlGroupForTreeItem;
  m_Size = msglist->m_Size;
  v7 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = msglist->m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
    {
      if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr && pTargetControlGroup != nullptr )
        break;
      Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
      v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: Int);
      v11 = (const CDmeControlGroup *)v10;
      if ( v10 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
             a1: v10,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v11 = nullptr;
      }
      if ( CAnimGroupTree::CanAddDragIntoGroup(
             pTargetGroup: pNewParentGroup,
             pTargetElement,
             pDragElement: v11,
             bInsertBefore) )
      {
        break;
      }
    }
    if ( ++v7 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004913B0
// Name: public: virtual void CAnimGroupTree::OnItemDropped(int,bool,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnItemDropped(
        CAnimGroupTree *this,
        int nItemIndex,
        BOOL bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // esi
  CDmeAnimationSet *ControlGroupForTreeItem; // eax
  int v7; // eax
  KeyValues *v8; // esi
  int Int; // eax
  int v10; // eax
  CDmeControlGroup *v11; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int nMsgCount; // [esp+Ch] [ebp-20h]
  int iMsg; // [esp+10h] [ebp-1Ch]
  CDmeAnimationSet *pTargetAnimSet; // [esp+14h] [ebp-18h] BYREF
  CDmElement *pTargetElement; // [esp+18h] [ebp-14h]
  CDmeControlGroup *pTargetControlGroup; // [esp+1Ch] [ebp-10h]
  Color clr; // [esp+20h] [ebp-Ch] BYREF
  CDmeControlGroup *pNewParentGroup; // [esp+24h] [ebp-8h]
  Color defaultColor; // [esp+28h] [ebp-4h] BYREF

  v4 = msglist;
  if ( this->IsItemDroppable(this, a2: nItemIndex, a3: bInsertBefore, a4: msglist) )
  {
    clr = 0;
    pTargetAnimSet = nullptr;
    pTargetElement = CAnimGroupTree::GetTreeItemData(
                       this,
                       nTreeIndex: nItemIndex,
                       pItemType: nullptr,
                       ppParentAnimationSet: &pTargetAnimSet,
                       ppControlGroup: (CDmeControlGroup **)&clr);
    if ( pTargetElement != nullptr )
    {
      ControlGroupForTreeItem = CAnimGroupTree::GetControlGroupForTreeItem(this, nItemIndex);
      pTargetControlGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
      if ( bInsertBefore )
        pNewParentGroup = (CDmeControlGroup *)clr;
      else
        pNewParentGroup = (CDmeControlGroup *)ControlGroupForTreeItem;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Drop onto control group",
        a3: "Drop onto control group",
        a4: 0);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 460))(
        a1: g_pDataModel.u,
        a2: "Drop onto control group",
        a3: 0,
        a4: 256);
      v7 = 0;
      nMsgCount = msglist->m_Size;
      iMsg = 0;
      if ( nMsgCount > 0 )
      {
        while ( 1 )
        {
          v8 = v4->m_Memory.m_pMemory[v7];
          if ( v8 != nullptr )
          {
            if ( KeyValues::FindKey(this: v8, keyName: "color", bCreate: false) != nullptr )
            {
              defaultColor = 0;
              KeyValues::GetColor(this: v8, result: &clr, keyName: "color", &defaultColor);
              this->SetItemFgColor(this, a2: nItemIndex, a3: &clr);
              this->SetItemSelectionTextColor(this, a2: nItemIndex, a3: &clr);
              CDmeControlGroup::SetGroupColor(this: pTargetControlGroup, groupColor: &clr, bRecursive: false);
            }
            Int = KeyValues::GetInt(this: v8, keyName: "dmeelement", defaultValue: -1);
            v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: Int);
            v11 = (CDmeControlGroup *)v10;
            if ( v10 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                   a1: v10,
                   a2: CDmElement::m_classType.u) == 0 )
            {
              v11 = nullptr;
            }
            if ( CAnimGroupTree::CanAddDragIntoGroup(
                   pTargetGroup: pNewParentGroup,
                   pTargetElement,
                   pDragElement: v11,
                   bInsertBefore) )
            {
              if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
                CDmeControlGroup::AddChild(
                  this: pNewParentGroup,
                  pGroup: v11,
                  pInsertBeforeGroup: bInsertBefore ? pTargetControlGroup : nullptr);
              else
                CDmeControlGroup::AddControl(
                  this: pNewParentGroup,
                  pControl: v11,
                  pInsertBeforeControl: bInsertBefore ? pTargetElement : nullptr);
              if ( pTargetAnimSet != nullptr )
              {
                RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pTargetAnimSet);
                if ( RootControlGroup != nullptr )
                  CDmeControlGroup::DestroyEmptyChildren(this: RootControlGroup);
              }
            }
          }
          v7 = iMsg + 1;
          iMsg = v7;
          if ( v7 >= nMsgCount )
            break;
          v4 = msglist;
        }
      }
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004915D0
// Name: public: virtual void CAnimGroupTree::GenerateDragDataForItem(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateDragDataForItem(CAnimGroupTree *this, int nItemIndex, KeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // edi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // esi
  int BufferType; // eax

  v3 = this->GetItemData(this, a2: nItemIndex);
  v4 = v3;
  if ( v3 != nullptr )
  {
    Int = KeyValues::GetInt(this: v3, keyName: "itemType", defaultValue: 0);
    v6 = KeyValues::GetInt(this: v4, keyName: "handle", defaultValue: -1);
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v6);
    v8 = (CExpressionCalculator *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmElement::m_classType.u) != 0
      && Int != 3 )
    {
      BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491660
// Name: public: virtual void CAnimGroupTree::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnMousePressed(CAnimGroupTree *this, const char *code)
{
  int ItemUnderMouse; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CAnimGroupTree_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // eax
  int Int; // eax
  int v10; // eax
  CDmeTransformControl *v11; // edi
  CDmeDag *Dag; // eax
  int height; // [esp+24h] [ebp-18h] BYREF
  int width; // [esp+28h] [ebp-14h] BYREF
  int xPos; // [esp+2Ch] [ebp-10h] BYREF
  int yPos; // [esp+30h] [ebp-Ch] BYREF
  int my; // [esp+34h] [ebp-8h] BYREF
  int mx; // [esp+38h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
  vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
  ItemUnderMouse = vgui::TreeView::FindItemUnderMouse(this, mx, my);
  if ( this->IsItemIDValid(this, a2: ItemUnderMouse) )
  {
    vgui::TreeView::GetItemBounds(this, itemIndex: ItemUnderMouse, x: &xPos, y: &yPos, w: &width, h: &height);
    if ( mx < xPos || my < yPos || mx > width + xPos || my > height + yPos )
      ItemUnderMouse = -1;
  }
  if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    if ( code == (const char *)108 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(
               this: v4,
               setName: "TreeViewOpenContextMenu",
               firstKey: "itemID",
               firstValue: ItemUnderMouse);
      else
        v5 = nullptr;
      v6 = this->__vftable;
      v7 = ((int (__thiscall *)(CAnimGroupTree *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v5, a3: 0);
      ((void (__thiscall *)(CAnimGroupTree *, int))v6->PostMessage)(a1: this, a2: v7);
      return;
    }
LABEL_22:
    vgui::TreeView::OnMousePressed(this, code);
    return;
  }
  if ( !this->IsItemIDValid(this, a2: ItemUnderMouse) || mx >= this->m_nStateColumnWidth + 20 )
    goto LABEL_22;
  v8 = this->GetItemData(this, a2: ItemUnderMouse);
  if ( v8 != nullptr )
  {
    Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1);
    v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: Int);
    v11 = (CDmeTransformControl *)v10;
    if ( v10 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
           a1: v10,
           a2: CDmElement::m_classType.u) != 0
      && v11->IsA(this: v11, a2: CDmeTransformControl::m_classType) )
    {
      Dag = CDmeTransformControl::GetDag(this: v11);
      CBaseAnimationSetControl::SetWorkCameraParent(this: this->m_pGroupPanel->m_pController, pParent: Dag);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491840
// Name: public: virtual void CAnimGroupTree::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnTick(CAnimGroupTree *this)
{
  int v2; // ebx
  AnimTreeItemType_t v3; // edi
  vgui::Button_vtbl *v4; // edi
  vgui::IImage *Image; // eax
  int x; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int y; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = -1;
  y = (int)CBaseAnimationSetControl::GetWorkCameraParent(this: this->m_pGroupPanel->m_pController);
  if ( y != 0 )
  {
    v3 = this->FirstItem(this);
    if ( v3 != this->InvalidItemID(this) )
    {
      while ( CAnimGroupTree::GetDagForTreeItem(this, nTreeItemIndex: v3) != (CDmeDag *)y )
      {
        v3 = this->NextItem(this, a2: v3);
        if ( v3 == this->InvalidItemID(this) )
          goto LABEL_7;
      }
      v2 = v3;
    }
  }
LABEL_7:
  this->m_pWorkCameraParentButton->SetVisible(this: this->m_pWorkCameraParentButton, a2: v2 != -1);
  if ( v2 != -1 )
  {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    vgui::TreeView::GetItemBounds(this, itemIndex: v2, &x, &y, &w, &h);
    vgui::Panel::SetBounds(
      this: this->m_pWorkCameraParentButton,
      x: this->m_nStateColumnWidth + 1,
      y: y + 1,
      wide: h - 2,
      tall: h - 2);
    this->m_pWorkCameraParentButton->ClearImages(this: this->m_pWorkCameraParentButton);
    v4 = this->m_pWorkCameraParentButton->__vftable;
    Image = vgui::ImageList::GetImage(this: &this->m_Images, imageIndex: this->m_StateIconIndices[0]);
    v4->AddImage(this: this->m_pWorkCameraParentButton, a2: Image, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491970
// Name: private: bool CAnimGroupTree::VisibleControlsBelow_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimGroupTree::VisibleControlsBelow_R(CAnimGroupTree *this, CDmeControlGroup *pGroup)
{
  int v4; // edi
  int v5; // eax
  CDmeControlGroup *v6; // esi
  int nNumChildren; // [esp+18h] [ebp+8h]

  if ( CBaseAnimationSetControl::IsControlGroupVisible(this: this->m_pGroupPanel->m_pController, pGroup) )
  {
    if ( pGroup->m_Controls.m_Storage.m_Size > 0 )
      return 1;
    v4 = 0;
    nNumChildren = pGroup->m_Children.m_Storage.m_Size;
    if ( nNumChildren > 0 )
    {
      while ( 1 )
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeControlGroup::m_classType.u) != 0
          && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v6) )
        {
          break;
        }
        if ( ++v4 >= nNumChildren )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00491A00
// Name: public: int CAnimGroupTree::FindChildItemForElement(int,class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindChildItemForElement(
        CAnimGroupTree *this,
        int nParentIndex,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  int Int; // eax
  int v9; // eax
  const CDmElement *v10; // edi
  int v11; // eax
  int nChildren; // [esp+Ch] [ebp-Ch]
  int iChild; // [esp+10h] [ebp-8h]
  int nChildIndex; // [esp+14h] [ebp-4h]

  v5 = 0;
  nChildren = this->GetNumChildren(this, a2: nParentIndex);
  iChild = 0;
  if ( nChildren <= 0 )
    return -1;
  while ( 1 )
  {
    nChildIndex = this->GetChild(this, a2: nParentIndex, a3: v5);
    v6 = this->GetItemData(this, a2: nChildIndex);
    v7 = v6;
    if ( v6 != nullptr )
      break;
LABEL_12:
    iChild = ++v5;
    if ( v5 >= nChildren )
      return -1;
  }
  Int = KeyValues::GetInt(this: v6, keyName: "handle", defaultValue: -1);
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v10 = (const CDmElement *)v9;
  if ( v9 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
         a1: v9,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v10 = nullptr;
  }
  if ( v10 == pElement )
  {
    if ( nComponentFlags == TRANSFORM_COMPONENT_NONE )
      return nChildIndex;
    v11 = KeyValues::GetInt(this: v7, keyName: "componentFlags", defaultValue: 0);
    if ( v11 == nComponentFlags )
      return nChildIndex;
    if ( (nComponentFlags & v11) == nComponentFlags )
    {
      this->GenerateChildrenOfNode(this, a2: nChildIndex);
      if ( CAnimGroupTree::FindChildItemForElement(this, nParentIndex: nChildIndex, pElement, nComponentFlags) >= 0 )
        return nChildIndex;
    }
  }
  v5 = iChild;
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x00491B10
// Name: public: int CAnimGroupTree::FindItemForElement(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::FindItemForElement(
        CAnimGroupTree *this,
        const CDmElement *pElement,
        TransformComponent_t nComponentFlags)
{
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  int Int; // eax
  int v8; // eax
  const CDmElement *v9; // esi
  int highest; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v4 = 0;
  highest = this->GetHighestItemID(this);
  i = 0;
  if ( highest <= 0 )
    return -1;
  while ( 1 )
  {
    if ( this->IsItemIDValid(this, a2: v4) )
    {
      v5 = this->GetItemData(this, a2: v4);
      v6 = v5;
      if ( v5 == nullptr )
        goto LABEL_11;
      Int = KeyValues::GetInt(this: v5, keyName: "handle", defaultValue: -1);
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v9 = (const CDmElement *)v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v9 = nullptr;
      }
      if ( v9 == pElement
        && (KeyValues::GetInt(this: v6, keyName: "componentFlags", defaultValue: 0) == nComponentFlags
         || nComponentFlags == TRANSFORM_COMPONENT_NONE) )
      {
        return i;
      }
      v4 = i;
    }
LABEL_11:
    i = ++v4;
    if ( v4 >= highest )
      return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491BE0
// Name: public: int CAnimGroupTree::BuildTreeToAnimationSet(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToAnimationSet(CAnimGroupTree *this, CDmeAnimationSet *pAnimationSet)
{
  int result; // eax
  int v4; // edi

  if ( pAnimationSet == nullptr )
    return -1;
  result = CAnimGroupTree::FindItemForElement(this, pElement: pAnimationSet, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( result < 0 )
  {
    v4 = this->GetRootItemIndex(this);
    this->GenerateChildrenOfNode(this, a2: v4);
    return CAnimGroupTree::FindChildItemForElement(
             this,
             nParentIndex: v4,
             pElement: pAnimationSet,
             nComponentFlags: TRANSFORM_COMPONENT_NONE);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491C40
// Name: public: int CAnimGroupTree::BuildTreeToGroup(class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::BuildTreeToGroup(
        CAnimGroupTree *this,
        CDmeControlGroup *pGroup,
        CDmeAnimationSet *pAnimationSet)
{
  CDmeControlGroup *Parent; // eax
  int v7; // edi
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pGroup == nullptr || pAnimationSet == nullptr )
    return -1;
  nItemIndex = CAnimGroupTree::FindItemForElement(this, pElement: pGroup, nComponentFlags: TRANSFORM_COMPONENT_NONE);
  if ( nItemIndex < 0 )
  {
    if ( CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet) == pGroup )
      return CAnimGroupTree::BuildTreeToAnimationSet(this, pAnimationSet);
    Parent = CDmeControlGroup::FindParent(this: pGroup);
    v7 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: Parent, pAnimationSet);
    if ( v7 >= 0 )
    {
      this->GenerateChildrenOfNode(this, a2: v7);
      return CAnimGroupTree::FindChildItemForElement(
               this,
               nParentIndex: v7,
               pElement: pGroup,
               nComponentFlags: TRANSFORM_COMPONENT_NONE);
    }
  }
  return nItemIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00491CD0
// Name: public: void CAnimGroupTree::BuildTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::BuildTreeToControl(
        CAnimGroupTree *this,
        const CDmElement *pControl,
        TransformComponent_t nComponentFlags)
{
  CDmeAnimationSet *Referring; // ebx
  int ItemForElement; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  int v8; // ebx
  int nItemIndex; // [esp+14h] [ebp+8h]

  if ( pControl != nullptr )
  {
    Referring = FindReferringElement<CDmeAnimationSet>(
                  pElement: pControl,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring != nullptr )
    {
      ItemForElement = CAnimGroupTree::FindItemForElement(this, pElement: pControl, nComponentFlags);
      nItemIndex = ItemForElement;
      if ( ItemForElement >= 0 )
      {
LABEL_8:
        this->MakeItemVisible(this, a2: ItemForElement);
        return;
      }
      GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
      v8 = CAnimGroupTree::BuildTreeToGroup(this, pGroup: GroupContainingControl, pAnimationSet: Referring);
      if ( v8 >= 0 )
      {
        this->GenerateChildrenOfNode(this, a2: v8);
        nItemIndex = CAnimGroupTree::FindChildItemForElement(
                       this,
                       nParentIndex: v8,
                       pElement: pControl,
                       nComponentFlags);
      }
      if ( nItemIndex >= 0 )
      {
        ItemForElement = nItemIndex;
        goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491E90
// Name: public: virtual void CBaseAnimSetControlGroupPanel::ExpandTreeToControl(class CDmElement const __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandTreeToControl(
        CBaseAnimSetControlGroupPanel *this,
        const CDmElement *pSelection,
        TransformComponent_t nComponentFlags)
{
  CAnimGroupTree *v3; // eax

  v3 = (CAnimGroupTree *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_LastNavDirection);
  CAnimGroupTree::BuildTreeToControl(this: v3, pControl: pSelection, nComponentFlags);
}

//------------------------------------------------------------------------------
// Address: 0x00491EB0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemSelected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex,
        int replaceSelection)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(
    this,
    itemIndex,
    selectionMode: (ESelectionMode)(replaceSelection == 0));
}

//------------------------------------------------------------------------------
// Address: 0x00491ED0
// Name: protected: virtual void CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnTreeViewItemDeselected(
        CBaseAnimSetControlGroupPanel *this,
        int itemIndex)
{
  CBaseAnimSetControlGroupPanel::SelectAnimTreeItem(this, itemIndex, selectionMode: SELECTION_REMOVE);
}

//------------------------------------------------------------------------------
// Address: 0x00491EF0
// Name: protected: void CBaseAnimSetControlGroupPanel::ExpandItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ExpandItems(
        CBaseAnimSetControlGroupPanel *this,
        const CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes)
{
  int v2; // ebx
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  CDmElement *m_pElement; // edi
  CAnimGroupTree *v5; // eax
  int ItemForElement; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  int v11; // ebx
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  int Int; // eax
  int v16; // eax
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  vgui::Panel *v20; // eax
  int nExpandedNodes; // [esp+Ch] [ebp-1Ch]
  int nChildren; // [esp+10h] [ebp-18h]
  TransformComponent_t expandedComponents; // [esp+14h] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+18h] [ebp-10h]
  int nItemIndex; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int v27; // [esp+24h] [ebp-4h]

  v2 = 0;
  nExpandedNodes = expandedNodes->m_Size;
  i = 0;
  if ( nExpandedNodes > 0 )
  {
    p_m_hGroups = &this->m_hGroups;
    do
    {
      m_pElement = expandedNodes->m_Memory.m_pMemory[v2].m_pElement;
      v5 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
      ItemForElement = CAnimGroupTree::FindItemForElement(
                         this: v5,
                         pElement: m_pElement,
                         nComponentFlags: TRANSFORM_COMPONENT_NONE);
      nItemIndex = ItemForElement;
      v7 = vgui::PHandle::Get(this: p_m_hGroups);
      if ( ItemForElement != ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].InstallMouseHandler)(a1: v7) )
      {
        v8 = vgui::PHandle::Get(this: p_m_hGroups);
        ((void (__thiscall *)(vgui::Panel *, int, int))v8->__vftable[1].dtr_Panel)(a1: v8, a2: ItemForElement, a3: 1);
        expandedComponents = expandedNodes->m_Memory.m_pMemory[v2].m_ComponentFlags;
        if ( expandedComponents != TRANSFORM_COMPONENT_NONE )
        {
          v9 = vgui::PHandle::Get(this: p_m_hGroups);
          nChildren = ((int (__thiscall *)(vgui::Panel *, int))v9->__vftable[1].PerformApplySchemeSettings)(
                        a1: v9,
                        a2: ItemForElement);
          v27 = 0;
          if ( nChildren > 0 )
          {
            while ( 1 )
            {
              v10 = vgui::PHandle::Get(this: p_m_hGroups);
              v11 = ((int (__thiscall *)(vgui::Panel *, int, int))v10->__vftable[1].PaintTraverse)(
                      a1: v10,
                      a2: ItemForElement,
                      a3: v27);
              v12 = vgui::PHandle::Get(this: p_m_hGroups);
              v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(
                                   a1: v12,
                                   a2: v11);
              v14 = v13;
              if ( v13 != nullptr )
              {
                childItemType = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
                Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
                v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                        a1: g_pDataModel.u,
                        a2: Int);
                if ( v16 != 0 )
                  (*(void (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
                    a1: v16,
                    a2: CDmElement::m_classType.u);
              }
              v17 = vgui::PHandle::Get(this: p_m_hGroups);
              v18 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v17->__vftable[1].IsWithinTraverse)(
                                   a1: v17,
                                   a2: v11);
              v19 = KeyValues::GetInt(this: v18, keyName: "componentFlags", defaultValue: 0);
              if ( childItemType == ANIMTREE_ITEM_COMPONENT && (v19 & expandedComponents) != 0 )
              {
                v20 = vgui::PHandle::Get(this: p_m_hGroups);
                ((void (__thiscall *)(vgui::Panel *, int, int))v20->__vftable[1].dtr_Panel)(a1: v20, a2: v11, a3: 1);
              }
              if ( ++v27 >= nChildren )
                break;
              ItemForElement = nItemIndex;
            }
            v2 = i;
          }
        }
      }
      i = ++v2;
    }
    while ( v2 < nExpandedNodes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492090
// Name: protected: enum SelectionState_t CBaseAnimSetControlGroupPanel::UpdateSelection_R(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection_R(
        CBaseAnimSetControlGroupPanel *this,
        Color nParentIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // esi
  vgui::Panel *v3; // eax
  int v4; // eax
  int v5; // ebx
  AnimTreeItemType_t v7; // edi
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // eax
  SelectionState_t updated; // eax
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  int Int; // eax
  int v16; // eax
  CDmElement *v17; // edi
  CDmeAnimationSet *v18; // eax
  int SelectionState; // eax
  CDmeControlGroup *v20; // eax
  CAnimGroupTree *v21; // eax
  TransformComponent_t ItemComponentFlags; // eax
  vgui::Panel *v23; // eax
  KeyValues *v24; // eax
  int v25; // edi
  Color *p_m_PartialSelectionColor; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  vgui::Panel *v31; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-8h]
  AnimTreeItemType_t itemTypea; // [esp+Ch] [ebp-8h]

  p_m_hGroups = &this->m_hGroups;
  v3 = vgui::PHandle::Get(this: &this->m_hGroups);
  v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].InstallMouseHandler)(a1: v3);
  v5 = (int)nParentIndex;
  if ( nParentIndex == v4 )
    return 0;
  v7 = ANIMTREE_ITEM_ANIMSET;
  nParentIndex = 0;
  v8 = vgui::PHandle::Get(this: p_m_hGroups);
  itemType = ((int (__thiscall *)(vgui::Panel *, int))v8->__vftable[1].PerformApplySchemeSettings)(a1: v8, a2: v5);
  if ( itemType <= ANIMTREE_ITEM_ANIMSET )
  {
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    v13 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].IsWithinTraverse)(a1: v12, a2: v5);
    v14 = v13;
    if ( v13 == nullptr )
      return 0;
    itemTypea = KeyValues::GetInt(this: v13, keyName: "itemType", defaultValue: 0);
    Int = KeyValues::GetInt(this: v14, keyName: "handle", defaultValue: -1);
    v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: Int);
    v17 = (CDmElement *)v16;
    if ( v16 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
           a1: v16,
           a2: CDmElement::m_classType.u) == 0 )
    {
      return 0;
    }
    switch ( itemTypea )
    {
      case ANIMTREE_ITEM_ANIMSET:
        v18 = CastElement<CDmeAnimationSet>(pElement: v17);
        if ( v18 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v18);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_GROUP:
        v20 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement: v17);
        if ( v20 != nullptr )
        {
          SelectionState = CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pControlGroup: v20);
          goto LABEL_16;
        }
        break;
      case ANIMTREE_ITEM_CONTROL:
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: TRANSFORM_COMPONENT_ALL);
        goto LABEL_16;
      case ANIMTREE_ITEM_COMPONENT:
        v21 = (CAnimGroupTree *)vgui::PHandle::Get(this: p_m_hGroups);
        ItemComponentFlags = CAnimGroupTree::GetItemComponentFlags(this: v21, nTreeIndex: v5);
        SelectionState = CBaseAnimationSetControl::GetSelectionState(
                           this: this->m_pController,
                           pControl: v17,
                           componentFlags: ItemComponentFlags);
LABEL_16:
        nParentIndex = (Color)SelectionState;
        break;
      default:
        break;
    }
  }
  else
  {
    do
    {
      v9 = vgui::PHandle::Get(this: p_m_hGroups);
      v10 = ((int (__thiscall *)(vgui::Panel *, int, AnimTreeItemType_t))v9->__vftable[1].PaintTraverse)(
              a1: v9,
              a2: v5,
              a3: v7);
      updated = CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v10);
      nParentIndex = (Color)(updated | *(_DWORD *)&nParentIndex);
      ++v7;
    }
    while ( v7 < itemType );
  }
  v23 = vgui::PHandle::Get(this: p_m_hGroups);
  v24 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v23->__vftable[1].IsWithinTraverse)(a1: v23, a2: v5);
  v25 = (int)nParentIndex;
  if ( v24 != nullptr )
    KeyValues::SetInt(this: v24, keyName: "selection", value: *(_DWORD *)&nParentIndex);
  if ( v25 == 3 )
  {
    p_m_PartialSelectionColor = &this->m_PartialSelectionColor;
    goto LABEL_23;
  }
  if ( v25 == 2 )
  {
    p_m_PartialSelectionColor = &this->m_FullSelectionColor;
LABEL_23:
    nParentIndex = *p_m_PartialSelectionColor;
    v27 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v27->__vftable[1].GetMessageMap)(
      a1: v27,
      a2: v5,
      a3: &nParentIndex);
    v28 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, Color *))v28->__vftable[1].GetAnimMap)(a1: v28, a2: v5, a3: &nParentIndex);
    v29 = vgui::PHandle::Get(this: p_m_hGroups);
    v29->SetSilentMode(this: v29, a2: true);
    v30 = vgui::PHandle::Get(this: p_m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD, _DWORD, _DWORD))v30->__vftable[1].RequestFocusPrev)(
      a1: v30,
      a2: v5,
      a3: 0,
      a4: 0,
      a5: 0);
    v31 = vgui::PHandle::Get(this: p_m_hGroups);
    v31->SetSilentMode(this: v31, a2: false);
  }
  return v25;
}

//------------------------------------------------------------------------------
// Address: 0x004922E0
// Name: public: virtual bool CAnimGroupTree::CanCurrentlyEditLabel(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimGroupTree::CanCurrentlyEditLabel(CAnimGroupTree *this, int nItemIndex)
{
  bool result; // al
  int v5; // edi
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int *m_pMemory; // edx
  int v8; // eax
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-18h] BYREF
  int nSelectedItems; // [esp+1Ch] [ebp-4h]
  int nParentIndex; // [esp+28h] [ebp+8h]

  result = this->IsItemSelected(this, a2: nItemIndex);
  if ( result )
  {
    v5 = 0;
    nParentIndex = this->GetItemParent(this, a2: nItemIndex);
    GetSelectedItems = this->GetSelectedItems;
    memset(&selectedItems, 0, sizeof(selectedItems));
    GetSelectedItems(this, a2: &selectedItems);
    m_pMemory = selectedItems.m_Memory.m_pMemory;
    nSelectedItems = selectedItems.m_Size;
    if ( selectedItems.m_Size > 0 )
    {
      do
      {
        v8 = m_pMemory[v5];
        if ( nItemIndex != v8 )
        {
          if ( this->GetItemParent(this, a2: v8) == nParentIndex )
          {
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selectedItems);
            return false;
          }
          m_pMemory = selectedItems.m_Memory.m_pMemory;
        }
        ++v5;
      }
      while ( v5 < nSelectedItems );
    }
    selectedItems.m_Size = 0;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        selectedItems.m_Memory.m_pMemory = nullptr;
      }
      selectedItems.m_Memory.m_nAllocationCount = 0;
    }
    selectedItems.m_pElements = m_pMemory;
    if ( selectedItems.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004923D0
// Name: public: void CBaseAnimSetControlGroupPanel::UpdateSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::UpdateSelection(CBaseAnimSetControlGroupPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  Color v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hGroups) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hGroups);
    v2->SetSilentMode(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v3->__vftable[1].RequestFocus)(a1: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4->SetSilentMode(this: v4, a2: false);
    v5 = vgui::PHandle::Get(this: &this->m_hGroups);
    v6 = (Color)((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].Think)(a1: v5);
    CBaseAnimSetControlGroupPanel::UpdateSelection_R(this, nParentIndex: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004924A0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x200000002LL;
    LODWORD(v4.m[2][3]) = 2;
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "TreeViewItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][2]) = "itemIndex";
    LODWORD(v4.m[3][0]) = "replaceSelection";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492540
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewItemDeselected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemIndex";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004925E0
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewStartRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492670
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewFinishRangeSelection";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492700
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TreeViewItemSelectionCleared";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492790
// Name: public: static void CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TreeViewOpenContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492830
// Name: public: static void CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded )
  {
    `CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LockDagButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004928C0
// Name: public: CAnimGroupStateIconSet::CAnimGroupStateIconSet(class vgui::Panel __near *,char const __near *,enum StateIconSetType_t,class CDmeDag __near *,class vgui::ImageList __near &,int const __near *)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupStateIconSet *__thiscall CAnimGroupStateIconSet::CAnimGroupStateIconSet(
        CAnimGroupStateIconSet *this,
        vgui::Panel *pParent,
        const char *pchName,
        StateIconSetType_t itemType,
        CDmeDag *pDag,
        vgui::ImageList *imageList,
        const int *pImageIndexMap)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  CAnimGroupStateIconSet::IconButton *v11; // eax
  CAnimGroupStateIconSet::IconButton *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::Tooltip *Tooltip; // eax
  vgui::Tooltip *v16; // edi
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "AnimGroupStateIconSet");
  this->__vftable = (CAnimGroupStateIconSet_vtbl *)&CAnimGroupStateIconSet::`vftable';
  if ( `CAnimGroupStateIconSet::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
    v8->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
    v9->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupStateIconSet::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
    v10->pfnClassName = CAnimGroupStateIconSet::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  CAnimGroupStateIconSet::PanelMessageFunc_OnLockDagButton::InitVar(a1: (int)&savedregs);
  this->m_ImageList = imageList;
  this->m_pImageIndexMap = pImageIndexMap;
  this->m_StateType = itemType;
  this->m_pDag = pDag;
  this->m_pLockButton = nullptr;
  v11 = (CAnimGroupStateIconSet::IconButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v11 != nullptr )
    v12 = CAnimGroupStateIconSet::IconButton::IconButton(this: v11, pIconSet: this, pName: "LockButton");
  else
    v12 = nullptr;
  this->m_pLockButton = v12;
  v12->SetVisible(this: v12, a2: true);
  this->m_pLockButton->AddActionSignalTarget_2(this: this->m_pLockButton, a2: this);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "LockDagButton");
  else
    v14 = nullptr;
  this->m_pLockButton->SetCommand(this: this->m_pLockButton, a2: v14);
  this->m_pLockButton->SetKeyBoardInputEnabled(this: this->m_pLockButton, a2: false);
  Tooltip = vgui::Panel::GetTooltip(this: this->m_pLockButton);
  v16 = Tooltip;
  if ( Tooltip != nullptr )
  {
    vgui::Tooltip::SetTooltipDelay(this: Tooltip, tooltipDelay: 1500);
    vgui::Tooltip::SetText(this: v16, text: "#LockButtonTip");
    vgui::Tooltip::SetTooltipFormatToSingleLine(this: v16);
  }
  vgui::Panel::SetDropEnabled(this, enabled: true, flHoverContextTime: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00492A80
// Name: public: virtual struct vgui::PanelMessageMap __near * CAnimGroupStateIconSet::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAnimGroupStateIconSet::GetMessageMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492AB0
// Name: public: virtual struct PanelAnimationMap __near * CAnimGroupStateIconSet::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAnimGroupStateIconSet::GetAnimMap(CAnimGroupStateIconSet *this)
{
  return FindOrAddPanelAnimationMap(className: "CAnimGroupStateIconSet");
}

//------------------------------------------------------------------------------
// Address: 0x00492AC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAnimGroupStateIconSet::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAnimGroupStateIconSet::GetKBMap(CAnimGroupStateIconSet *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap;
  `CAnimGroupStateIconSet::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupStateIconSet");
  `CAnimGroupStateIconSet::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492B20
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{1084,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ClearWorkCameraParent";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492BB0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1088,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnResetTransformPivot";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "viewCenter";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492C50
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1092,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ToggleDagLock";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492CE0
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1096,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetOverrideParent";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492D70
// Name: public: static void CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded )
  {
    `CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1100,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenLockContextMenu";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492E00
// Name: public: CAnimGroupTree::CAnimGroupTree(class vgui::Panel __near *,char const __near *,class CBaseAnimSetControlGroupPanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CAnimGroupTree *__thiscall CAnimGroupTree::CAnimGroupTree(
        CAnimGroupTree *this,
        vgui::Panel *parent,
        const char *panelName,
        CBaseAnimSetControlGroupPanel *groupPanel,
        bool bStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  vgui::IImage *v13; // eax
  vgui::IImage *v14; // eax
  vgui::IImage *v15; // eax
  vgui::IImage *v16; // eax
  vgui::IImage *v17; // eax
  vgui::IImage *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TreeView::TreeView(this, parent, panelName);
  this->__vftable = (CAnimGroupTree_vtbl *)&CAnimGroupTree::`vftable';
  if ( `CAnimGroupTree::ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CAnimGroupTree");
    v6->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CAnimGroupTree");
    v7->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TreeView");
  }
  if ( `CAnimGroupTree::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAnimGroupTree::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CAnimGroupTree");
    v8->pfnClassName = CAnimGroupTree::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  }
  CAnimGroupTree::PanelMessageFunc_OnClearWorkCameraParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnResetTransformPivot::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnToggleDagLock::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnSetOverrideParent::InitVar(a1: (int)&savedregs);
  CAnimGroupTree::PanelMessageFunc_OnOpenLockContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pGroupPanel = groupPanel;
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  this->m_RootColor = (Color)-8355712;
  this->m_StateColumnColor = 0;
  this->m_nStateColumnWidth = 0;
  this->m_bStateInterface = bStateInterface;
  if ( bStateInterface )
  {
    this->m_nStateColumnWidth = 20;
    vgui::TreeView::SetTreeIndent(this, nIndentAmount: 18);
  }
  vgui::TreeView::SetShowRootNode(this, bRootVisible: false);
  vgui::TreeView::SetDragEnabledItems(this, state: true);
  vgui::TreeView::SetAllowLabelEditing(this, state: true);
  vgui::TreeView::SetEnableInsertDropLocation(this, bEnable: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "workCameraParent",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pWorkCameraParentButton = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pWorkCameraParentButton->AddActionSignalTarget_2(this: this->m_pWorkCameraParentButton, a2: this);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "ClearWorkCameraParent");
  else
    v12 = nullptr;
  this->m_pWorkCameraParentButton->SetCommand(this: this->m_pWorkCameraParentButton, a2: v12);
  this->m_pWorkCameraParentButton->SetKeyBoardInputEnabled(this: this->m_pWorkCameraParentButton, a2: false);
  v13 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_referenceframe_active", a3: 0);
  this->m_StateIconIndices[0] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v13);
  v14 = g_pVGuiSchemeManager->GetImage(
          this: g_pVGuiSchemeManager,
          a2: "tools/ifm/icon_referenceframe_active_hidden",
          a3: 0);
  this->m_StateIconIndices[1] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v14);
  v15 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked", a3: 0);
  this->m_StateIconIndices[2] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v15);
  v16 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_grey", a3: 0);
  this->m_StateIconIndices[3] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v16);
  v17 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world", a3: 0);
  this->m_StateIconIndices[4] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v17);
  v18 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_dag_locked_world_grey", a3: 0);
  this->m_StateIconIndices[5] = vgui::Dar<unsigned long>::AddElement(
                                  this: (vgui::Dar<unsigned long> *)&this->m_Images,
                                  elem: (unsigned int)v18);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004930E0
// Name: private: int CAnimGroupTree::AddItemToTree(enum AnimTreeItemType_t,char const __near *,int,class Color const __near &,class CDmElement __near *,class CDmeAnimationSet __near *,class CDmeControlGroup __near *,bool,enum SelectionState_t,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddItemToTree(
        CAnimGroupTree *this,
        AnimTreeItemType_t itemType,
        const char *label,
        int parentIndex,
        const Color *fg,
        CExpressionCalculator *pElement,
        CExpressionCalculator *pAnimSet,
        CExpressionCalculator *pControlGroup,
        Color bExpandable,
        SelectionState_t selection,
        TransformComponent_t nComponentFlags)
{
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  CDmeTransform *Transform; // eax
  StateIconSetType_t v16; // ebx
  CAnimGroupStateIconSet *v17; // eax
  CAnimGroupStateIconSet *v18; // eax
  int v19; // ebx
  void (__thiscall *SetItemSelectionBgColor)(vgui::TreeView *, int, const Color *); // edx
  DmElementHandle_t hElement; // [esp+24h] [ebp+18h]
  DmElementHandle_t hAnimSet; // [esp+28h] [ebp+1Ch]
  DmElementHandle_t hControlGroup; // [esp+2Ch] [ebp+20h]

  if ( pElement != nullptr )
    hElement = CCodecBuffer_Block::GetBufferType(this: pElement);
  else
    hElement = DMELEMENT_HANDLE_INVALID;
  if ( pAnimSet != nullptr )
    hAnimSet = CCodecBuffer_Block::GetBufferType(this: pAnimSet);
  else
    hAnimSet = DMELEMENT_HANDLE_INVALID;
  if ( pControlGroup != nullptr )
    hControlGroup = CCodecBuffer_Block::GetBufferType(this: pControlGroup);
  else
    hControlGroup = DMELEMENT_HANDLE_INVALID;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "item", firstKey: "text", firstValue: label);
  else
    v14 = nullptr;
  KeyValues::SetInt(this: v14, keyName: "droppable", value: 1);
  KeyValues::SetInt(this: v14, keyName: "itemType", value: itemType);
  KeyValues::SetInt(this: v14, keyName: "handle", value: hElement);
  KeyValues::SetInt(this: v14, keyName: "animset", value: hAnimSet);
  KeyValues::SetInt(this: v14, keyName: "controlgroup", value: hControlGroup);
  KeyValues::SetInt(this: v14, keyName: "selection", value: selection);
  KeyValues::SetInt(this: v14, keyName: "componentFlags", value: nComponentFlags);
  KeyValues::SetInt(this: v14, keyName: "Expand", value: bExpandable._color[0] != 0);
  if ( pElement != nullptr
    && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))pElement->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: pElement,
         a2: CDmeTransformControl::m_classType.u) != 0
    && (Transform = CDmeTransformControl::GetTransform(this: (CDmeTransformControl *)pElement)) != nullptr )
  {
    bExpandable = (Color)CDmeTransform::GetDag(this: Transform);
  }
  else
  {
    bExpandable = 0;
  }
  if ( this->m_bStateInterface )
  {
    v16 = STATE_ICON_SET_INVALID;
    if ( itemType == ANIMTREE_ITEM_COMPONENT )
    {
      if ( nComponentFlags == TRANSFORM_COMPONENT_POSITION )
      {
        v16 = STATE_ICON_SET_CONTROL_POSITION;
      }
      else if ( nComponentFlags == TRANSFORM_COMPONENT_ROTATION )
      {
        v16 = STATE_ICON_SET_CONTROL_ROTATION;
      }
    }
    else
    {
      v16 = itemType == ANIMTREE_ITEM_CONTROL;
    }
    if ( bExpandable != 0 && v16 != STATE_ICON_SET_INVALID )
    {
      v17 = (CAnimGroupStateIconSet *)MemAlloc_Alloc(nSize: 0x164u);
      if ( v17 != nullptr )
        v18 = CAnimGroupStateIconSet::CAnimGroupStateIconSet(
                this: v17,
                pParent: this,
                pchName: label,
                itemType: v16,
                pDag: *(CDmeDag **)&bExpandable,
                imageList: &this->m_Images,
                pImageIndexMap: this->m_StateIconIndices);
      else
        v18 = nullptr;
      KeyValues::SetPtr(this: v14, keyName: "stateIconSet", value: v18);
    }
  }
  v19 = this->AddItem(this, a2: v14, a3: parentIndex);
  this->SetItemFgColor(this, a2: v19, a3: fg);
  this->SetItemSelectionTextColor(this, a2: v19, a3: fg);
  this->SetSilentMode(this, a2: true);
  if ( selection == SEL_ALL )
  {
    bExpandable = (Color)-2139062144;
  }
  else
  {
    if ( selection != SEL_SOME )
    {
      SetItemSelectionBgColor = this->SetItemSelectionBgColor;
      bExpandable = (Color)0x80000000;
      SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
      this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
      this->RemoveSelectedItem(this, a2: v19);
      goto LABEL_37;
    }
    bExpandable = (Color)1077969024;
  }
  this->SetItemSelectionBgColor(this, a2: v19, a3: &bExpandable);
  this->SetItemSelectionUnfocusedBgColor(this, a2: v19, a3: &bExpandable);
  this->AddSelectedItem(this, a2: v19, a3: false, a4: false, a5: true);
LABEL_37:
  if ( (unsigned int)itemType <= ANIMTREE_ITEM_GROUP )
    this->SetLabelEditingAllowed(this, a2: v19, a3: true);
  this->SetSilentMode(this, a2: false);
  this->ExpandItem(this, a2: v19, a3: false);
  KeyValues::deleteThis(this: v14);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x004933B0
// Name: public: virtual void CAnimGroupTree::GetSelectedItemsForDrag(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GetSelectedItemsForDrag(
        CAnimGroupTree *this,
        AnimTreeItemType_t nPrimaryDragItem,
        CUtlVector<int,CUtlMemory<int,int> > *list)
{
  void (__thiscall *GetSelectedItems)(vgui::TreeView *, CUtlVector<int,CUtlMemory<int,int> > *); // edx
  int i; // esi
  int v6; // [esp-14h] [ebp-3Ch]
  CUtlVector<int,CUtlMemory<int,int> > selectedItems; // [esp+8h] [ebp-20h] BYREF
  int nNumSelected; // [esp+1Ch] [ebp-Ch]
  CDmeControlGroup *pParentGroup; // [esp+20h] [ebp-8h] BYREF
  CDmeControlGroup *pPrimaryParentGroup; // [esp+24h] [ebp-4h] BYREF

  GetSelectedItems = this->GetSelectedItems;
  memset(&selectedItems, 0, sizeof(selectedItems));
  GetSelectedItems(this, a2: &selectedItems);
  nNumSelected = selectedItems.m_Size;
  if ( selectedItems.m_Size > 0 )
  {
    pPrimaryParentGroup = nullptr;
    CAnimGroupTree::GetTreeItemData(
      this,
      nTreeIndex: nPrimaryDragItem,
      pItemType: &nPrimaryDragItem,
      ppParentAnimationSet: nullptr,
      ppControlGroup: &pPrimaryParentGroup);
    if ( nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
    {
      for ( i = 0; i < nNumSelected; ++i )
      {
        v6 = selectedItems.m_Memory.m_pMemory[i];
        pParentGroup = nullptr;
        CAnimGroupTree::GetTreeItemData(
          this,
          nTreeIndex: v6,
          pItemType: &nPrimaryDragItem,
          ppParentAnimationSet: nullptr,
          ppControlGroup: &pParentGroup);
        if ( pPrimaryParentGroup == pParentGroup && nPrimaryDragItem != ANIMTREE_ITEM_COMPONENT )
          CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
            this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)list,
            elem: list->m_Size,
            src: (vgui::PageTab **)&selectedItems.m_Memory.m_pMemory[i]);
      }
    }
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selectedItems);
}

//------------------------------------------------------------------------------
// Address: 0x00493480
// Name: public: CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetControlGroupPanel *__thiscall CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
        CBaseAnimSetControlGroupPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor,
        bool bControlStateInterface)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CBaseAnimationSetControl *Controller; // eax
  CAnimGroupTree *v10; // eax
  CAnimGroupTree *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::TreeView *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetControlGroupPanel_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetControlGroupPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetControlGroupPanel");
    v6->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetControlGroupPanel");
    v7->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetControlGroupPanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetControlGroupPanel");
    v8->pfnClassName = CBaseAnimSetControlGroupPanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemDeselected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewStartRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewFinishRangeSelection::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewItemSelectionCleared::InitVar(a1: (int)&savedregs);
  CBaseAnimSetControlGroupPanel::PanelMessageFunc_OnTreeViewOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hEditor.m_iPanelID = -1;
  this->m_hGroups.m_iPanelID = -1;
  this->m_pController = nullptr;
  this->m_FullSelectionColor = 0;
  this->m_PartialSelectionColor = 0;
  this->m_ContextMenuHighlightColor = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditor, pPanel: editor);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  v10 = (CAnimGroupTree *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = CAnimGroupTree::CAnimGroupTree(
            this: v10,
            parent: this,
            panelName: "AnimSetGroups",
            groupPanel: this,
            bStateInterface: bControlStateInterface);
  else
    v11 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v11);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hGroups, pPanel: v11);
  v12 = vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::Panel::SetAutoResize(
    this: v12,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v13 = (vgui::TreeView *)vgui::PHandle::Get(this: &this->m_hGroups);
  vgui::TreeView::SetAllowMultipleSelections(this: v13, state: true);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "root");
  else
    v15 = nullptr;
  v16 = vgui::PHandle::Get(this: &this->m_hGroups);
  ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v16->__vftable[1].GetVPanel)(a1: v16, a2: v15, a3: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00493670
// Name: public: virtual void CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::OnControlSelectionChanged(CBaseAnimSetControlGroupPanel *this)
{
  CBaseAnimSetControlGroupPanel::UpdateSelection(this: (CBaseAnimSetControlGroupPanel *)((char *)this - 380));
}

//------------------------------------------------------------------------------
// Address: 0x00493680
// Name: protected: void CBaseAnimSetControlGroupPanel::CollectExpandedItems(class CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::CollectExpandedItems(
        CBaseAnimSetControlGroupPanel *this,
        CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *expandedNodes,
        int nItemIndex)
{
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ebx
  vgui::Panel *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  int Int; // eax
  int v10; // eax
  CDmElement *v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  int v15; // edi
  vgui::Panel *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // esi
  int v19; // eax
  int v20; // eax
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  KeyValues *v23; // eax
  int nChildren; // [esp+Ch] [ebp-14h]
  AnimTreeItemType_t childItemType; // [esp+14h] [ebp-Ch]
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *pExpansionInfo; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  p_m_hGroups = &this->m_hGroups;
  v4 = vgui::PHandle::Get(this: &this->m_hGroups);
  v5 = nItemIndex;
  if ( nItemIndex != ((int (__thiscall *)(vgui::Panel *))v4->__vftable[1].InstallMouseHandler)(a1: v4) )
  {
    v6 = vgui::PHandle::Get(this: p_m_hGroups);
    v7 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v6->__vftable[1].IsWithinTraverse)(
                        a1: v6,
                        a2: nItemIndex);
    v8 = v7;
    if ( v7 == nullptr
      || (KeyValues::GetInt(this: v7, keyName: "itemType", defaultValue: 0),
          Int = KeyValues::GetInt(this: v8, keyName: "handle", defaultValue: -1),
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: Int),
          v11 = (CDmElement *)v10,
          v10 == 0)
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
           a1: v10,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v11 = nullptr;
    }
    v12 = vgui::PHandle::Get(this: p_m_hGroups);
    if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v12->__vftable[1].SetVisible)(a1: v12, a2: nItemIndex) != 0 )
    {
      pExpansionInfo = nullptr;
      if ( v11 != nullptr )
      {
        pExpansionInfo = &expandedNodes->m_Memory.m_pMemory[CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>>::AddToTail(this: expandedNodes)];
        pExpansionInfo->m_pElement = v11;
        pExpansionInfo->m_ComponentFlags = TRANSFORM_COMPONENT_NONE;
      }
      v13 = vgui::PHandle::Get(this: p_m_hGroups);
      nChildren = ((int (__thiscall *)(vgui::Panel *, int))v13->__vftable[1].PerformApplySchemeSettings)(
                    a1: v13,
                    a2: nItemIndex);
      i = 0;
      if ( nChildren > 0 )
      {
        while ( 1 )
        {
          v14 = vgui::PHandle::Get(this: p_m_hGroups);
          v15 = ((int (__thiscall *)(vgui::Panel *, int, int))v14->__vftable[1].PaintTraverse)(a1: v14, a2: v5, a3: i);
          v16 = vgui::PHandle::Get(this: p_m_hGroups);
          v17 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].IsWithinTraverse)(
                               a1: v16,
                               a2: v15);
          v18 = v17;
          if ( v17 != nullptr )
          {
            childItemType = KeyValues::GetInt(this: v17, keyName: "itemType", defaultValue: 0);
            v19 = KeyValues::GetInt(this: v18, keyName: "handle", defaultValue: -1);
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: v19);
            if ( v20 != 0 )
              (*(void (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v20 + 16))(
                a1: v20,
                a2: CDmElement::m_classType.u);
          }
          if ( childItemType == ANIMTREE_ITEM_COMPONENT )
          {
            v21 = vgui::PHandle::Get(this: p_m_hGroups);
            if ( ((unsigned __int8 (__thiscall *)(vgui::Panel *, int))v21->__vftable[1].SetVisible)(a1: v21, a2: v15) != 0
              && pExpansionInfo != nullptr )
            {
              v22 = vgui::PHandle::Get(this: p_m_hGroups);
              v23 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v22->__vftable[1].IsWithinTraverse)(
                                   a1: v22,
                                   a2: v15);
              pExpansionInfo->m_ComponentFlags |= KeyValues::GetInt(
                                                    this: v23,
                                                    keyName: "componentFlags",
                                                    defaultValue: 0);
            }
          }
          else
          {
            CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, expandedNodes, nItemIndex: v15);
          }
          if ( ++i >= nChildren )
            break;
          v5 = nItemIndex;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493870
// Name: public: int CAnimGroupTree::AddAnimationSetToTree(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddAnimationSetToTree(CAnimGroupTree *this, CDmeAnimationSet *pAnimSet)
{
  CDmeAnimationSet *v2; // edi
  CDmeControlGroup *RootControlGroup; // ebx
  bool v6; // zf
  char v7; // al
  const char *m_pAsString; // eax
  int parentIndex; // [esp+Ch] [ebp-8h]
  SelectionState_t selection; // [esp+10h] [ebp-4h]

  v2 = pAnimSet;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  if ( !CBaseAnimationSetControl::IsControlGroupVisible(
          this: this->m_pGroupPanel->m_pController,
          pGroup: RootControlGroup) )
    return -1;
  parentIndex = this->GetRootItemIndex(this);
  selection = CBaseAnimationSetControl::GetSelectionState(this: this->m_pGroupPanel->m_pController, pAnimSet: v2);
  pAnimSet = (CDmeAnimationSet *)this->m_RootColor;
  if ( !CDmeControlGroup::IsSelectable(this: RootControlGroup)
    || (v6 = !CDmeControlGroup::IsVisible(this: RootControlGroup), v7 = -1, v6) )
  {
    v7 = 64;
  }
  HIBYTE(pAnimSet) = v7;
  m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_ANIMSET,
           label: m_pAsString,
           parentIndex,
           fg: (const Color *)&pAnimSet,
           pElement: (CExpressionCalculator *)v2,
           pAnimSet: (CExpressionCalculator *)v2,
           pControlGroup: nullptr,
           bExpandable: (Color)1,
           selection,
           nComponentFlags: TRANSFORM_COMPONENT_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x004939B0
// Name: public: int CAnimGroupTree::AddControlToTree(int,class CDmElement __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAnimGroupTree::AddControlToTree(
        CAnimGroupTree *this,
        int parentIndex,
        CExpressionCalculator *pControl,
        CDmeControlGroup *pControlGroup,
        CExpressionCalculator *pAnimSet)
{
  CExpressionCalculator *v5; // edi
  unsigned __int8 v6; // al
  CDmeControlGroup *v7; // ebx
  TransformComponent_t v8; // esi
  bool v9; // zf
  char v10; // al
  const char *m_nAllocationCount; // eax
  Color bTransformControl; // [esp+10h] [ebp-8h]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v5 = pControl;
  selection = CBaseAnimationSetControl::GetSelectionState(
                this: this->m_pGroupPanel->m_pController,
                (CDmElement *)pControl,
                componentFlags: TRANSFORM_COMPONENT_ALL);
  v6 = (*((int (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v5,
         a2: CDmeTransformControl::m_classType.u);
  v7 = pControlGroup;
  pControl = (CExpressionCalculator *)pControlGroup->m_ControlColor.m_Storage;
  bTransformControl._color[0] = v6;
  v8 = v6 != 0 ? TRANSFORM_COMPONENT_ALL : TRANSFORM_COMPONENT_NONE;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v9 = !CDmeControlGroup::IsVisible(this: v7), v10 = -1, v9) )
  {
    v10 = 64;
  }
  HIBYTE(pControl) = v10;
  m_nAllocationCount = (const char *)v5->m_varNames.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount == (const char *)-1 )
    m_nAllocationCount = defaultValue;
  return CAnimGroupTree::AddItemToTree(
           this,
           itemType: ANIMTREE_ITEM_CONTROL,
           label: m_nAllocationCount,
           parentIndex,
           fg: (const Color *)&pControl,
           pElement: v5,
           pAnimSet,
           pControlGroup: (CExpressionCalculator *)v7,
           bExpandable: bTransformControl,
           selection,
           nComponentFlags: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00493A60
// Name: public: void CAnimGroupTree::AddTransformComponentsToTree(int,class CDmeTransformControl __near *,class CDmeControlGroup __near *,class CDmeAnimationSet __near *,enum TransformComponent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddTransformComponentsToTree(
        CAnimGroupTree *this,
        int nParentIndex,
        CDmeTransformControl *pControl,
        CDmeControlGroup *pControlGroup,
        CExpressionCalculator *pAnimSet,
        SelectionState_t nParentComponentFlags)
{
  char SelectionComponentFlags; // si
  CUtlSymbolLarge::<unnamed_type_u> v9; // eax
  bool v10; // zf
  unsigned __int8 v11; // al
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> *v15; // eax
  CFmtStrN<256> *v16; // eax
  SelectionState_t v17; // esi
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> *v19; // eax
  CFmtStrN<256> *v20; // eax
  int v21; // esi
  CExpressionCalculator *v22; // [esp-14h] [ebp-134h]
  CExpressionCalculator *v23; // [esp-10h] [ebp-130h]
  Color v24; // [esp-Ch] [ebp-12Ch]
  SelectionState_t v25; // [esp-8h] [ebp-128h]
  TransformComponent_t v26; // [esp-4h] [ebp-124h]
  CFmtStrN<256> v27; // [esp+Ch] [ebp-114h] BYREF
  SelectionState_t rotSelection; // [esp+118h] [ebp-8h]
  Color color; // [esp+11Ch] [ebp-4h] BYREF
  const char *pControla; // [esp+12Ch] [ebp+Ch]
  SelectionState_t pControlGroupa; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupb; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupc; // [esp+130h] [ebp+10h]
  SelectionState_t pControlGroupd; // [esp+130h] [ebp+10h]
  SelectionState_t posSelection; // [esp+138h] [ebp+18h]

  SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                              this: this->m_pGroupPanel->m_pController,
                              pControl);
  v9.m_Id = (int)pControl->m_Name.m_Storage.u;
  pControla = defaultValue;
  if ( v9.m_Id != -1 )
    pControla = (const char *)v9.m_Id;
  color = pControlGroup->m_ControlColor.m_Storage;
  if ( !CDmeControlGroup::IsSelectable(this: pControlGroup)
    || (v10 = !CDmeControlGroup::IsVisible(this: pControlGroup), v11 = -1, v10) )
  {
    v11 = 64;
  }
  color._color[3] = v11;
  if ( nParentComponentFlags == 63 )
  {
    if ( (SelectionComponentFlags & 7) == 7 )
      posSelection = SEL_ALL;
    else
      posSelection = 2 * ((SelectionComponentFlags & 7) != 0) + 1;
    v12 = SelectionComponentFlags & 0x38;
    if ( v12 == 56 )
      rotSelection = SEL_ALL;
    else
      rotSelection = 2 * (v12 > 0) + 1;
    v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v13->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      (CExpressionCalculator *)pControlGroup,
      bExpandable: (Color)1,
      selection: posSelection,
      nComponentFlags: TRANSFORM_COMPONENT_POSITION);
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION;
    v25 = rotSelection;
    v24 = (Color)1;
    v23 = (CExpressionCalculator *)pControlGroup;
    v22 = pAnimSet;
LABEL_36:
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v14->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet: v22,
      pControlGroup: v23,
      bExpandable: v24,
      selection: v25,
      nComponentFlags: v26);
    return;
  }
  if ( nParentComponentFlags != (SEL_SOME|0x4) )
  {
    if ( nParentComponentFlags != 56 )
      return;
    if ( (SelectionComponentFlags & 8) != 0 )
      pControlGroupc = SEL_ALL;
    else
      pControlGroupc = 2 * ((SelectionComponentFlags & 8) != 0) + 1;
    v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.x", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v19->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupc,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_X);
    if ( (SelectionComponentFlags & 0x10) != 0 )
      pControlGroupd = SEL_ALL;
    else
      pControlGroupd = 2 * ((SelectionComponentFlags & 0x10) != 0) + 1;
    v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.y", pControla);
    CAnimGroupTree::AddItemToTree(
      this,
      itemType: ANIMTREE_ITEM_COMPONENT,
      label: v20->m_szBuf,
      parentIndex: nParentIndex,
      fg: &color,
      pElement: (CExpressionCalculator *)pControl,
      pAnimSet,
      pControlGroup: nullptr,
      bExpandable: 0,
      selection: pControlGroupd,
      nComponentFlags: TRANSFORM_COMPONENT_ROTATION_Y);
    if ( (SelectionComponentFlags & 0x20) != 0 )
      v21 = 2;
    else
      v21 = 1;
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - rot.z", pControla);
    v26 = TRANSFORM_COMPONENT_ROTATION_Z;
    v25 = v21;
    v24 = 0;
    v23 = nullptr;
    v22 = pAnimSet;
    goto LABEL_36;
  }
  if ( (SelectionComponentFlags & 1) != 0 )
    pControlGroupa = SEL_ALL;
  else
    pControlGroupa = 2 * ((SelectionComponentFlags & 1) != 0) + 1;
  v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.x", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v15->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupa,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_X);
  if ( (SelectionComponentFlags & 2) != 0 )
    pControlGroupb = SEL_ALL;
  else
    pControlGroupb = 2 * ((SelectionComponentFlags & 2) != 0) + 1;
  v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.y", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v16->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: pControlGroupb,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Y);
  if ( (SelectionComponentFlags & 4) != 0 )
    v17 = SEL_ALL;
  else
    v17 = SEL_NONE;
  v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "%s - pos.z", pControla);
  CAnimGroupTree::AddItemToTree(
    this,
    itemType: ANIMTREE_ITEM_COMPONENT,
    label: v18->m_szBuf,
    parentIndex: nParentIndex,
    fg: &color,
    pElement: (CExpressionCalculator *)pControl,
    pAnimSet,
    pControlGroup: nullptr,
    bExpandable: 0,
    selection: v17,
    nComponentFlags: TRANSFORM_COMPONENT_POSITION_Z);
}

//------------------------------------------------------------------------------
// Address: 0x00493DA0
// Name: private: void CAnimGroupTree::AddDmeControlGroup(int,class CDmeAnimationSet __near *,class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::AddDmeControlGroup(
        CAnimGroupTree *this,
        int nParentItemIndex,
        CDmeAnimationSet *pAnimationSet,
        CDmeControlGroup *pGroup)
{
  int v5; // ebx
  int v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  int v9; // eax
  CExpressionCalculator *v10; // esi
  int nControls; // [esp+20h] [ebp+10h]
  int nControlsa; // [esp+20h] [ebp+10h]

  v5 = 0;
  nControls = pGroup->m_Children.m_Storage.m_Size;
  if ( nControls > 0 )
  {
    do
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = (CDmeControlGroup *)v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeControlGroup::m_classType.u) != 0
        && CAnimGroupTree::VisibleControlsBelow_R(this, pGroup: v7) != 0 )
      {
        CAnimGroupTree::AddControlGroupToTree(
          this,
          parentIndex: nParentItemIndex,
          pControlGroup: v7,
          pParentGroup: pGroup,
          pAnimSet: pAnimationSet);
      }
      ++v5;
    }
    while ( v5 < nControls );
  }
  v8 = 0;
  nControlsa = pGroup->m_Controls.m_Storage.m_Size;
  if ( nControlsa > 0 )
  {
    do
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pGroup->m_Controls.m_Storage.m_Memory.m_pMemory[v8]);
      v10 = (CExpressionCalculator *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmElement::m_classType.u) != 0 )
      {
        CAnimGroupTree::AddControlToTree(
          this,
          parentIndex: nParentItemIndex,
          pControl: v10,
          pControlGroup: pGroup,
          pAnimSet: (CExpressionCalculator *)pAnimationSet);
      }
      ++v8;
    }
    while ( v8 < nControlsa );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493E80
// Name: public: virtual void CAnimGroupTree::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::GenerateChildrenOfNode(CAnimGroupTree *this, int itemIndex)
{
  CDmeAnimationSet *i; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  CDmElement *ElementKey; // eax
  CDmeAnimationSet *v7; // ebx
  bool v8; // al
  CDmElement *v9; // eax
  CDmeControlGroup *v10; // ebx
  SelectionState_t v11; // edi
  CDmeControlGroup *RootControlGroup; // eax
  CDmeControlGroup *v13; // eax
  CDmeTransformControl *v14; // eax
  AnimTreeItemType_t itemType; // [esp+Ch] [ebp-10h] BYREF
  int Int; // [esp+10h] [ebp-Ch]
  CDmElement *pElement; // [esp+14h] [ebp-8h]
  CDmeAnimationSet *pAnimationSet; // [esp+18h] [ebp-4h]

  if ( this->GetNumChildren(this, a2: itemIndex) <= 0 )
  {
    if ( itemIndex == this->GetRootItemIndex(this) )
    {
      itemType = (AnimTreeItemType_t)CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pGroupPanel->m_pController);
      Int = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: (CAnimSetGroupAnimSetTraversal *)&itemType) )
      {
        CAnimGroupTree::AddAnimationSetToTree(this, pAnimSet: i);
      }
    }
    else
    {
      v4 = this->GetItemData(this, a2: itemIndex);
      v5 = v4;
      if ( v4 != nullptr )
      {
        Int = KeyValues::GetInt(this: v4, keyName: "itemType", defaultValue: 0);
        pElement = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "handle");
        ElementKey = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "animset");
        v7 = (CDmeAnimationSet *)ElementKey;
        if ( ElementKey == nullptr
          || (v8 = ElementKey->IsA(this: ElementKey, a2: CDmeAnimationSet::m_classType), pAnimationSet = v7, !v8) )
        {
          pAnimationSet = nullptr;
        }
        v9 = GetElementKeyValue<CDmElement>(pKeyValues: v5, pName: "controlgroup");
        v10 = (CDmeControlGroup *)v9;
        if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeControlGroup::m_classType) )
          v10 = nullptr;
        v11 = KeyValues::GetInt(this: v5, keyName: "componentFlags", defaultValue: 0);
        switch ( Int )
        {
          case 0:
            RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimationSet);
            CAnimGroupTree::AddDmeControlGroup(
              this,
              nParentItemIndex: itemIndex,
              pAnimationSet,
              pGroup: RootControlGroup);
            break;
          case 1:
            v13 = (CDmeControlGroup *)CastElement<CDmeControlGroup>(pElement);
            CAnimGroupTree::AddDmeControlGroup(this, nParentItemIndex: itemIndex, pAnimationSet, pGroup: v13);
            break;
          case 2:
          case 3:
            v14 = CastElement<CDmeTransformControl>(pElement);
            if ( v14 != nullptr )
              CAnimGroupTree::AddTransformComponentsToTree(
                this,
                nParentIndex: itemIndex,
                pControl: v14,
                pControlGroup: v10,
                pAnimSet: (CExpressionCalculator *)pAnimationSet,
                nParentComponentFlags: v11);
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494040
// Name: public: void CBaseAnimSetControlGroupPanel::RebuildTree(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::RebuildTree(CBaseAnimSetControlGroupPanel *this, bool bRestoreExpansion)
{
  vgui::Panel *v3; // eax
  int v4; // eax
  KeyValues *v5; // ebx
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *v6; // ecx
  vgui::Panel *v7; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // ebx
  vgui::Panel *v15; // eax
  vgui::Panel_vtbl *v16; // esi
  int v17; // eax
  vgui::Panel *v18; // eax
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  vgui::Panel *v23; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  CDmeAnimationSet *i; // eax
  CAnimGroupTree *v26; // eax
  vgui::Panel *v27; // eax
  vgui::DHANDLE<CAnimGroupTree> *p_m_hGroups; // ecx
  vgui::Panel *v29; // edi
  vgui::Panel *v30; // ebx
  vgui::Panel_vtbl *v31; // esi
  int v32; // eax
  CDmeAnimationSet *v33; // [esp-4h] [ebp-2Ch]
  CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > expandedNodes; // [esp+Ch] [ebp-1Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-8h] BYREF
  vgui::Panel *bRestoreExpansiona; // [esp+30h] [ebp+8h]

  if ( bRestoreExpansion )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hGroups);
    v4 = ((int (__thiscall *)(vgui::Panel *))v3->__vftable[1].Repaint)(a1: v3);
    v5 = nullptr;
    v6 = nullptr;
    expandedNodes.m_Memory.m_pMemory = nullptr;
    expandedNodes.m_Memory.m_nAllocationCount = v4;
    expandedNodes.m_Memory.m_nGrowSize = 0;
    if ( v4 != 0 )
    {
      v6 = (CBaseAnimSetControlGroupPanel::ElementExpansion_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v4);
      expandedNodes.m_Memory.m_pMemory = v6;
    }
    expandedNodes.m_pElements = v6;
    expandedNodes.m_Size = 0;
    v7 = vgui::PHandle::Get(this: &this->m_hGroups);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].Think)(a1: v7);
    CBaseAnimSetControlGroupPanel::CollectExpandedItems(this, &expandedNodes, nItemIndex: v8);
    v9 = vgui::PHandle::Get(this: &this->m_hGroups);
    v9->SetSilentMode(this: v9, a2: true);
    v10 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v10->__vftable[1].GetClipRect)(a1: v10);
    v11 = vgui::PHandle::Get(this: &this->m_hGroups);
    v11->SetSilentMode(this: v11, a2: false);
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v5 = KeyValues::KeyValues(this: v12, setName: "root");
    v13 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v13->__vftable[1].GetVPanel)(a1: v13, a2: v5, a3: -1);
    v14 = vgui::PHandle::Get(this: &this->m_hGroups);
    v15 = vgui::PHandle::Get(this: &this->m_hGroups);
    v16 = v15->__vftable;
    bRestoreExpansiona = v15;
    v17 = ((int (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].Think)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v16[1].dtr_Panel)(a1: bRestoreExpansiona, a2: v17);
    CBaseAnimSetControlGroupPanel::ExpandItems(this, &expandedNodes);
    CBaseAnimSetControlGroupPanel::UpdateSelection(this);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&expandedNodes);
  }
  else
  {
    v18 = vgui::PHandle::Get(this: &this->m_hGroups);
    v18->SetSilentMode(this: v18, a2: true);
    v19 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *))v19->__vftable[1].GetClipRect)(a1: v19);
    v20 = vgui::PHandle::Get(this: &this->m_hGroups);
    v20->SetSilentMode(this: v20, a2: false);
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "root");
    else
      v22 = nullptr;
    v23 = vgui::PHandle::Get(this: &this->m_hGroups);
    ((void (__thiscall *)(vgui::Panel *, KeyValues *, int))v23->__vftable[1].GetVPanel)(a1: v23, a2: v22, a3: -1);
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    if ( AnimationSetClip != nullptr )
    {
      traversal.m_pFilmClip = AnimationSetClip;
      traversal.m_nIndex = 0;
      for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
            i != nullptr;
            i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
      {
        v33 = i;
        v26 = (CAnimGroupTree *)vgui::PHandle::Get(this: &this->m_hGroups);
        CAnimGroupTree::AddAnimationSetToTree(this: v26, pAnimSet: v33);
      }
      v27 = vgui::PHandle::Get(this: &this->m_hGroups);
      p_m_hGroups = &this->m_hGroups;
      v29 = v27;
      v30 = vgui::PHandle::Get(this: p_m_hGroups);
      v31 = v30->__vftable;
      v32 = ((int (__thiscall *)(vgui::Panel *, int))v29->__vftable[1].Think)(a1: v29, a2: 1);
      ((void (__thiscall *)(vgui::Panel *, int))v31[1].dtr_Panel)(a1: v30, a2: v32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494290
// Name: public: virtual void CAnimGroupTree::OnLabelChanged(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimGroupTree::OnLabelChanged(
        CAnimGroupTree *this,
        CDmeControlGroup *nItemIndex,
        const char *pOldString,
        const char *pNewString)
{
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // edx
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  CExpressionCalculator *v8; // esi
  int Int; // eax
  int v10; // eax
  CDmeControlGroup *RootControlGroup; // eax
  const char *v12; // esi
  CDmeControlGroup *v13; // edi
  int v14; // eax
  KeyValues *v15; // eax
  int BufferType; // eax
  vgui::Panel *v17; // eax
  CFmtStrN<256> newName; // [esp+30h] [ebp-124h] BYREF
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > childList; // [esp+13Ch] [ebp-18h] BYREF
  CAnimGroupTree *v20; // [esp+150h] [ebp-4h]
  CDmeControlGroup *pControlGroup; // [esp+15Ch] [ebp+8h]

  v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
  v6 = nullptr;
  v20 = this;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v5)(
    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
    a2: "Change group label",
    a3: "Change group label",
    a4: 0);
  v7 = this->GetItemData(this, a2: nItemIndex);
  if ( v7 == nullptr )
  {
    v8 = nullptr;
LABEL_8:
    pControlGroup = nullptr;
    goto LABEL_9;
  }
  Int = KeyValues::GetInt(this: v7, keyName: "handle", defaultValue: -1);
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: Int);
  v8 = (CExpressionCalculator *)v10;
  if ( v10 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
         a1: v10,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v8 = nullptr;
  }
  if ( v8 == nullptr )
    goto LABEL_8;
  pControlGroup = (CDmeControlGroup *)v8;
  if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeControlGroup::m_classType.u) == 0 )
    goto LABEL_8;
LABEL_9:
  if ( v8 == nullptr
    || (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
        + 4))(
         a1: v8,
         a2: CDmeAnimationSet::m_classType.u) == 0 )
  {
    v8 = nullptr;
  }
  if ( pControlGroup != nullptr )
  {
    RootControlGroup = CDmeControlGroup::FindRootControlGroup(this: pControlGroup);
    v12 = pNewString;
    v13 = RootControlGroup;
    if ( RootControlGroup != nullptr
      && CDmeControlGroup::FindChildByName(
           this: RootControlGroup,
           pchName: pNewString,
           recursive: true,
           pParentGroup: nullptr) != nullptr )
    {
      memset(&childList, 0, sizeof(childList));
      CDmeControlGroup::GetAllChildren(this: v13, childGroupList: &childList);
      v14 = GenerateUniqueNameIndex(prefix: v12, array: &childList, startindex: 0);
      CFmtStrN<256>::CFmtStrN<256>(this: &newName, pszFormat: "%s%d", v12, v14);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200))(
        a1: g_pDataModel.u,
        a2: &pNewString,
        a3: newName.m_szBuf);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: pControlGroup->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
      CBaseAnimSetControlGroupPanel::RebuildTree(this: v20->m_pGroupPanel, bRestoreExpansion: true);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&childList);
    }
    else
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
        a1: g_pDataModel.u,
        a2: &pNewString,
        a3: v12);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: pControlGroup->m_Name.m_pAttribute,
        value: (const CUtlSymbolLarge *)&pNewString);
    }
  }
  else if ( v8 != nullptr )
  {
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v6 = KeyValues::KeyValues(this: v15, setName: "SetAnimationSetName", firstKey: "text", firstValue: pNewString);
    BufferType = CCodecBuffer_Block::GetBufferType(this: v8);
    KeyValues::SetInt(this: v6, keyName: "animset", value: BufferType);
    v17 = vgui::PHandle::Get(this: &this->m_pGroupPanel->m_hEditor);
    ((void (__thiscall *)(CAnimGroupTree *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: v17,
      a3: v6,
      a4: 0);
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
}

//------------------------------------------------------------------------------
// Address: 0x004944B0
// Name: public: void CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(
        CBaseAnimSetControlGroupPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel::RebuildTree(this, bRestoreExpansion: false);
}

//------------------------------------------------------------------------------
// Address: 0x00640030
// Name: public: virtual class vgui::ListPanelItem __near * vgui::ListPanel::GetItemData(int)
// Source: json
//------------------------------------------------------------------------------
vgui::FastSortListPanelItem *__thiscall vgui::ListPanel::GetItemData(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006402E0
// Name: public: virtual class vgui::IImage __near * vgui::ListPanel::GetCellImage(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::ListPanel::GetCellImage(vgui::ListPanel *this, int itemID, int col)
{
  KeyValues *v4; // edi
  vgui::Button *m_pHeader; // ecx
  const char *v6; // eax
  int Int; // edi

  v4 = this->GetItem(this, a2: itemID);
  if ( v4 != nullptr
    && col >= 0
    && col < this->m_CurrentColumns.m_Size
    && (m_pHeader = this->m_ColumnsData.m_Memory.m_pMemory[this->m_CurrentColumns.m_Memory.m_pMemory[col]].m_Element.m_pHeader,
        (v6 = m_pHeader->GetName(this: m_pHeader)) != nullptr)
    && *v6 != 0
    && this->m_pImageList != nullptr
    && (Int = KeyValues::GetInt(this: v4, keyName: v6, defaultValue: 0),
        vgui::ImageList::IsValidIndex(this: this->m_pImageList, imageIndex: Int))
    && Int > 0 )
  {
    return vgui::ImageList::GetImage(this: this->m_pImageList, imageIndex: Int);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00642440
// Name: protected: virtual class vgui::Panel __near * vgui::ListPanel::GetCellRenderer(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::ListPanel::GetCellRenderer(vgui::ListPanel *this, int itemID, int col)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v4; // edi
  vgui::ListPanel_vtbl *v5; // edx
  vgui::ISchemeManager_vtbl *v6; // ebx
  int v7; // eax
  vgui::IScheme *v8; // eax
  vgui::Label *m_pLabel; // ecx
  vgui::Label::Alignment m_nContentAlignment; // edx
  KeyValues *v11; // eax
  vgui::TextImage *m_pTextImage; // ecx
  KeyValues *v13; // ebx
  void (__thiscall *SetText)(vgui::TextImage *, const wchar_t *, bool); // eax
  int v15; // eax
  int m_Size; // ecx
  int v17; // eax
  int *m_pMemory; // edx
  vgui::TextImage *v19; // eax
  vgui::TextImage_vtbl *v20; // edi
  int v21; // eax
  unsigned int (__thiscall *GetFocus)(vgui::IInput *); // eax
  unsigned int v23; // edi
  bool (__thiscall *HasFocus)(vgui::Panel *); // eax
  vgui::IPanel *v25; // ebx
  vgui::IPanel_vtbl *v26; // edi
  unsigned int v27; // eax
  bool v28; // al
  vgui::Label_vtbl *v29; // edi
  Color *v30; // eax
  vgui::TextImage *v31; // eax
  vgui::TextImage_vtbl *v32; // edi
  Color *Color; // eax
  int v34; // eax
  vgui::TextImage *v35; // ecx
  int Int; // eax
  vgui::TextImage *v37; // ecx
  vgui::FastSortListPanelItem *m_Element; // eax
  vgui::ImageList *m_pImageList; // ecx
  vgui::IImage *m_pIcon; // edi
  int m_nImageIndex; // edi
  int v43; // ecx
  int v44; // eax
  int *v45; // edx
  vgui::IImage *v46; // eax
  unsigned int v47; // edi
  bool (__thiscall *v48)(vgui::Panel *); // eax
  vgui::IPanel *v49; // ebx
  vgui::IPanel_vtbl *v50; // edi
  unsigned int v51; // eax
  vgui::Label_vtbl *v52; // edi
  Color *v53; // eax
  wchar_t tempText[256]; // [esp+Ch] [ebp-218h] BYREF
  int tall; // [esp+20Ch] [ebp-18h] BYREF
  int cw; // [esp+210h] [ebp-14h] BYREF
  KeyValues *item; // [esp+214h] [ebp-10h]
  unsigned int focus; // [esp+218h] [ebp-Ch] BYREF
  bool selected; // [esp+21Fh] [ebp-5h]
  vgui::IScheme *pScheme; // [esp+220h] [ebp-4h] BYREF

  v4 = &this->m_ColumnsData.m_Memory.m_pMemory[this->m_CurrentColumns.m_Memory.m_pMemory[col]];
  v5 = this->__vftable;
  v6 = g_pVGuiSchemeManager->__vftable;
  item = (KeyValues *)g_pVGuiSchemeManager;
  v7 = v5->GetScheme(this);
  v8 = v6->GetIScheme(this: (vgui::ISchemeManager *)item, a2: v7);
  m_pLabel = this->m_pLabel;
  m_nContentAlignment = v4->m_Element.m_nContentAlignment;
  pScheme = v8;
  m_pLabel->SetContentAlignment(this: m_pLabel, a2: m_nContentAlignment);
  if ( v4->m_Element.m_bTypeIsText )
  {
    this->GetCellText(this, a2: itemID, a3: col, a4: tempText, a5: 256);
    v11 = this->GetItem(this, a2: itemID);
    m_pTextImage = this->m_pTextImage;
    v13 = v11;
    SetText = m_pTextImage->SetText;
    item = v13;
    SetText(this: m_pTextImage, a2: tempText, a3: false);
    this->m_pTextImage->GetContentSize(this: this->m_pTextImage, a2: &cw, a3: &tall);
    v15 = vgui::Panel::GetWide(this: v4->m_Element.m_pHeader) - 5;
    if ( cw < v15 )
      v15 = cw;
    this->m_pTextImage->SetSize(this: this->m_pTextImage, a2: v15, a3: tall);
    this->m_pLabel->SetTextImageIndex(this: this->m_pLabel, a2: 0);
    this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: this->m_pTextImage, a4: 3);
    m_Size = this->m_SelectedItems.m_Size;
    v17 = 0;
    selected = false;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_SelectedItems.m_Memory.m_pMemory;
    while ( *m_pMemory != itemID )
    {
      ++v17;
      ++m_pMemory;
      if ( v17 >= m_Size )
        goto LABEL_8;
    }
    if ( v17 < 0 || (*((_BYTE *)this + 508) & 8) != 0 && col != this->m_iSelectedColumn )
    {
LABEL_8:
      if ( KeyValues::IsEmpty(this: v13, keyName: "cellcolor") )
      {
        Int = KeyValues::GetInt(this: v13, keyName: "disabled", defaultValue: 0);
        v37 = this->m_pTextImage;
        if ( Int != 0 )
          ((void (__stdcall *)(_DWORD))v37->SetColor)(a1: *(_DWORD *)&this->m_DisabledColor);
        else
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v37->SetColor)(a1: v37, a2: *(_DWORD *)&this->m_LabelFgColor);
      }
      else
      {
        v19 = this->m_pTextImage;
        pScheme = nullptr;
        v20 = v19->__vftable;
        v21 = (int)*KeyValues::GetColor(
                      this: v13,
                      result: (Color *)&focus,
                      keyName: "cellcolor",
                      defaultColor: (const Color *)&pScheme);
        ((void (__stdcall *)(int))v20->SetColor)(a1: v21);
      }
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
    }
    else
    {
      GetFocus = g_pVGuiInput->GetFocus;
      selected = true;
      v23 = GetFocus(this: g_pVGuiInput);
      HasFocus = this->HasFocus;
      focus = v23;
      if ( HasFocus(this)
        || v23 != 0
        && (v25 = g_pVGuiPanel,
            v26 = g_pVGuiPanel->__vftable,
            v27 = this->GetVParent(this),
            v28 = v26->HasParent(this: v25, a2: focus, a3: v27),
            v13 = item,
            v28) )
      {
        v29 = this->m_pLabel->__vftable;
        v30 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedBgColor", a4: pScheme);
      }
      else
      {
        v29 = this->m_pLabel->__vftable;
        v30 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedOutOfFocusBgColor", a4: pScheme);
      }
      ((void (__thiscall *)(vgui::Label *, _DWORD))v29->SetBgColor)(a1: this->m_pLabel, a2: *v30);
      if ( KeyValues::IsEmpty(this: v13, keyName: "cellcolor") )
      {
        v34 = KeyValues::GetInt(this: v13, keyName: "disabled", defaultValue: 0);
        v35 = this->m_pTextImage;
        if ( v34 != 0 )
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v35->SetColor)(
            a1: v35,
            a2: *(_DWORD *)&this->m_DisabledSelectionFgColor);
        else
          ((void (__thiscall *)(vgui::TextImage *, _DWORD))v35->SetColor)(
            a1: v35,
            a2: *(_DWORD *)&this->m_SelectionFgColor);
        this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
      }
      else
      {
        v31 = this->m_pTextImage;
        pScheme = nullptr;
        v32 = v31->__vftable;
        Color = KeyValues::GetColor(
                  this: v13,
                  result: (Color *)&focus,
                  keyName: "cellcolor",
                  defaultColor: (const Color *)&pScheme);
        v32->SetColor(this: this->m_pTextImage, a2: *Color);
        this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
      }
    }
    m_Element = this->m_DataItems.m_Memory.m_pMemory[itemID].m_Element;
    if ( col == 0 && m_Element->m_bImage )
    {
      m_pImageList = this->m_pImageList;
      if ( m_pImageList != nullptr )
      {
        m_pIcon = m_Element->m_pIcon;
        if ( m_pIcon != nullptr
          || (!selected
            ? (m_nImageIndex = m_Element->m_nImageIndex)
            : (m_nImageIndex = m_Element->m_nImageIndexSelected),
              vgui::ImageList::IsValidIndex(this: m_pImageList, imageIndex: m_nImageIndex)
           && (m_pIcon = vgui::ImageList::GetImage(this: this->m_pImageList, imageIndex: m_nImageIndex)) != nullptr) )
        {
          this->m_pLabel->SetTextImageIndex(this: this->m_pLabel, a2: 1);
          this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: m_pIcon, a4: 0);
          this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 1, a3: this->m_pTextImage, a4: 3);
          return this->m_pLabel;
        }
      }
    }
  }
  else
  {
    v43 = this->m_SelectedItems.m_Size;
    v44 = 0;
    if ( v43 <= 0 )
      goto LABEL_42;
    v45 = this->m_SelectedItems.m_Memory.m_pMemory;
    while ( *v45 != itemID )
    {
      ++v44;
      ++v45;
      if ( v44 >= v43 )
        goto LABEL_42;
    }
    if ( v44 < 0 || (*((_BYTE *)this + 508) & 8) != 0 && col != this->m_iSelectedColumn )
    {
LABEL_42:
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
    }
    else
    {
      v47 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
      v48 = this->HasFocus;
      focus = v47;
      if ( v48(this)
        || v47 != 0
        && (v49 = g_pVGuiPanel,
            v50 = g_pVGuiPanel->__vftable,
            v51 = this->GetVParent(this),
            v50->HasParent(this: v49, a2: focus, a3: v51)) )
      {
        v52 = this->m_pLabel->__vftable;
        v53 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedBgColor", a4: pScheme);
      }
      else
      {
        v52 = this->m_pLabel->__vftable;
        v53 = this->GetSchemeColor_2(this, result: &focus, a3: "ListPanel.SelectedOutOfFocusBgColor", a4: pScheme);
      }
      ((void (__thiscall *)(vgui::Label *, _DWORD))v52->SetBgColor)(a1: this->m_pLabel, a2: *v53);
      this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: true);
    }
    v46 = this->GetCellImage(this, a2: itemID, a3: col);
    this->m_pLabel->SetImageAtIndex(this: this->m_pLabel, a2: 0, a3: v46, a4: 0);
  }
  return this->m_pLabel;
}

//------------------------------------------------------------------------------
// Address: 0x00645B00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ListPanel::GetMessageMap(vgui::ListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ListPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ListPanel");
  `vgui::ListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00645B30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ListPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ListPanel::GetAnimMap(vgui::ListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "ListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00645B40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ListPanel::GetKBMap(vgui::ListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ListPanel::GetKBMap'::`2'::s_pMap;
  `vgui::ListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ListPanel");
  `vgui::ListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490980
// Name: class CDmeAnimationSet __near * FindReferringElement<class CDmeAnimationSet>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl FindReferringElement<CDmeAnimationSet>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeAnimationSet *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeAnimationSet>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

} // namespace sceneviewer
