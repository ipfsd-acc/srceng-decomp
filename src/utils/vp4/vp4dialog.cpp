// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vp4/vp4dialog.cpp
// Functions: 105
// ============================================================

#include "utils\vp4\vp4dialog.h"

//------------------------------------------------------------------------------
// Address: 0x00401A70
// Name: public: static char const __near * CFileTreeView::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFileTreeView::GetPanelClassName()
{
  return "CFileTreeView";
}

//------------------------------------------------------------------------------
// Address: 0x00401A80
// Name: public: static char const __near * CSmallTextListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSmallTextListPanel::GetPanelClassName()
{
  return "CSmallTextListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: int IntSortFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IntSortFunc(_DWORD *elem1, _DWORD *elem2)
{
  if ( *elem1 >= *elem2 )
    return *elem1 > *elem2;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00401AC0
// Name: private: virtual void CVP4Dialog::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::OnTextChanged(CVP4Dialog *this)
{
  KeyValues *ActiveItemUserData; // eax
  IP4_vtbl *v3; // edi
  const char *String; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pClientCombo);
  if ( ActiveItemUserData != nullptr )
  {
    v3 = p4->__vftable;
    String = KeyValues::GetString(this: ActiveItemUserData, keyName: "client", defaultValue: defaultValue);
    v3->SetActiveClient(this: p4, a2: String);
    this->Activate(this);
    this->m_pRevisionList->RemoveAll(this: this->m_pRevisionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: private: virtual void CVP4Dialog::CloakFolder(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::CloakFolder(CVP4Dialog *this, int iItem)
{
  KeyValues *v3; // eax
  IP4_vtbl *v4; // ebx
  const char *String; // eax

  v3 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: iItem);
  if ( v3 != nullptr )
  {
    v4 = p4->__vftable;
    String = KeyValues::GetString(this: v3, keyName: "path", defaultValue: defaultValue);
    v4->RemovePathFromActiveClientspec(this: p4, a2: String);
    this->m_pFileTree->RemoveItem(this: this->m_pFileTree, a2: -iItem, a3: false, a4: false);
    this->m_pFileTree->InvalidateLayout(this: this->m_pFileTree, a2: false, a3: false);
    this->m_pFileTree->Repaint(this: this->m_pFileTree);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BD0
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x00401BF0
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401C00
// Name: public: static char const __near * CVP4Dialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVP4Dialog::GetPanelClassName()
{
  return "CVP4Dialog";
}

//------------------------------------------------------------------------------
// Address: 0x00401C40
// Name: public: CFileTreeView::CFileTreeView(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileTreeView *__thiscall CFileTreeView::CFileTreeView(CFileTreeView *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::TreeView::TreeView(this, parent, panelName: name);
  this->__vftable = (CFileTreeView_vtbl *)&CFileTreeView::`vftable';
  if ( `CFileTreeView::ChainToMap'::`2'::chained == 0 )
  {
    `CFileTreeView::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CFileTreeView");
    v4->pfnClassName = CFileTreeView::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "TreeView");
  }
  if ( `CFileTreeView::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFileTreeView::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CFileTreeView");
    v5->pfnClassName = CFileTreeView::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "TreeView");
  }
  if ( `CFileTreeView::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFileTreeView::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CFileTreeView");
    v6->pfnClassName = CFileTreeView::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TreeView");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401D00
// Name: public: virtual void CFileTreeView::GenerateContextMenu(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFileTreeView::GenerateContextMenu(
        CFileTreeView *this@<ecx>,
        int a2@<edi>,
        int itemIndex,
        int x,
        int y)
{
  KeyValues *v6; // ebx
  vgui::Menu *v7; // eax
  vgui::Menu *v8; // edi
  KeyValues *v9; // eax
  vgui::Menu_vtbl *v10; // ebx
  int v11; // eax
  KeyValues *v12; // eax
  vgui::Menu_vtbl *v13; // ebx
  int v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  KeyValues *v18; // [esp+8h] [ebp-4h]
  int v19; // [esp+8h] [ebp-4h]
  KeyValues *itemIndexa; // [esp+14h] [ebp+8h]
  int itemIndexb; // [esp+14h] [ebp+8h]

  v6 = this->GetItemData(this, a2: itemIndex);
  if ( *KeyValues::GetString(this: v6, keyName: "path", defaultValue: defaultValue) != 0 )
  {
    v7 = (vgui::Menu *)operator new(nSize: 0x420u);
    if ( v7 != nullptr )
      v8 = vgui::Menu::Menu(this: v7, parent: this, panelName: "FileContext");
    else
      v8 = nullptr;
    if ( KeyValues::GetInt(this: v6, keyName: "dir", defaultValue: 0) != 0 )
    {
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        itemIndexa = KeyValues::KeyValues(this: v9, setName: "CloakFolder", firstKey: "item", firstValue: itemIndex);
      else
        itemIndexa = nullptr;
      v10 = v8->__vftable;
      v11 = ((int (__thiscall *)(CFileTreeView *, _DWORD, int))this->GetParent)(a1: this, a2: 0, a3: a2);
      ((void (__thiscall *)(vgui::Menu *, const char *, KeyValues *, int))v10->AddMenuItem)(
        a1: v8,
        a2: "Cloak folder",
        a3: itemIndexa,
        a4: v11);
    }
    else
    {
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v18 = KeyValues::KeyValues(this: v12, setName: "EditFile", firstKey: "item", firstValue: itemIndex);
      else
        v18 = nullptr;
      v13 = v8->__vftable;
      v14 = ((int (__thiscall *)(CFileTreeView *, _DWORD, int))this->GetParent)(a1: this, a2: 0, a3: a2);
      ((void (__thiscall *)(vgui::Menu *, const char *, KeyValues *, int))v13->AddMenuItem)(
        a1: v8,
        a2: "Open for edit",
        a3: v18,
        a4: v14);
      v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v15 != nullptr )
        v16 = KeyValues::KeyValues(this: v15, setName: "DeleteFile", firstKey: "item", firstValue: itemIndex);
      else
        v16 = nullptr;
      itemIndexb = (int)v8->__vftable;
      v19 = ((int (__thiscall *)(CFileTreeView *, _DWORD))this->GetParent)(a1: this, a2: 0);
      (*(void (__thiscall **)(vgui::Menu *, const char *, KeyValues *, int))(itemIndexb + 856))(
        a1: v8,
        a2: "Open for delete",
        a3: v16,
        a4: v19);
    }
    vgui::Panel::SetPos(this: v8, x, y);
    v8->SetVisible(this: v8, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E90
// Name: public: virtual void CFileTreeView::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTreeView::ApplySchemeSettings(CFileTreeView *this, vgui::IScheme *pScheme)
{
  CFileTreeView_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::TreeView::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00401ED0
// Name: public: virtual struct vgui::PanelMessageMap __near * CFileTreeView::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFileTreeView::GetMessageMap(CFileTreeView *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFileTreeView::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileTreeView::GetMessageMap'::`2'::s_pMap;
  `CFileTreeView::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFileTreeView");
  `CFileTreeView::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401F00
// Name: public: virtual struct PanelAnimationMap __near * CFileTreeView::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFileTreeView::GetAnimMap(CFileTreeView *this)
{
  return FindOrAddPanelAnimationMap(className: "CFileTreeView");
}

//------------------------------------------------------------------------------
// Address: 0x00401F10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFileTreeView::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFileTreeView::GetKBMap(CFileTreeView *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFileTreeView::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileTreeView::GetKBMap'::`2'::s_pMap;
  `CFileTreeView::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFileTreeView");
  `CFileTreeView::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401F70
// Name: public: CSmallTextListPanel::CSmallTextListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSmallTextListPanel *__thiscall CSmallTextListPanel::CSmallTextListPanel(
        CSmallTextListPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ListPanel::ListPanel(this, parent, panelName: name);
  this->__vftable = (CSmallTextListPanel_vtbl *)&CSmallTextListPanel::`vftable';
  if ( `CSmallTextListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSmallTextListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSmallTextListPanel");
    v4->pfnClassName = CSmallTextListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ListPanel");
  }
  if ( `CSmallTextListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSmallTextListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSmallTextListPanel");
    v5->pfnClassName = CSmallTextListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ListPanel");
  }
  if ( `CSmallTextListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSmallTextListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSmallTextListPanel");
    v6->pfnClassName = CSmallTextListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ListPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402030
// Name: public: virtual void CSmallTextListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallTextListPanel::ApplySchemeSettings(CSmallTextListPanel *this, vgui::IScheme *pScheme)
{
  CSmallTextListPanel_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::ListPanel::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
  v3->SetFont(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00402070
// Name: public: virtual struct vgui::PanelMessageMap __near * CSmallTextListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSmallTextListPanel::GetMessageMap(CSmallTextListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSmallTextListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSmallTextListPanel::GetMessageMap'::`2'::s_pMap;
  `CSmallTextListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSmallTextListPanel");
  `CSmallTextListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004020A0
// Name: public: virtual struct PanelAnimationMap __near * CSmallTextListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSmallTextListPanel::GetAnimMap(CSmallTextListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSmallTextListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004020B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSmallTextListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSmallTextListPanel::GetKBMap(CSmallTextListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSmallTextListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSmallTextListPanel::GetKBMap'::`2'::s_pMap;
  `CSmallTextListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSmallTextListPanel");
  `CSmallTextListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: public: virtual void CVP4Dialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::OnClose(CVP4Dialog *this)
{
  vgui::Frame::OnClose(this);
  g_pVGui->Stop(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x00402140
// Name: private: void CVP4Dialog::RefreshFileList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::RefreshFileList(CVP4Dialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  P4Client_t *v4; // eax
  __int16 v5; // ecx^2
  const char *v6; // eax
  P4Client_t *v7; // eax
  __int16 v8; // ecx^2
  const char *v9; // eax
  vgui::TreeView *m_pFileTree; // ecx
  vgui::TreeView_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp-4h] [ebp-14h]

  this->m_pFileTree->RemoveAll(this: this->m_pFileTree);
  ((void (__thiscall *)(vgui::TreeView *, int))this->m_pFileTree->SetFgColor)(a1: this->m_pFileTree, a2: -2892072);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "root");
  else
    v3 = nullptr;
  v4 = p4->GetActiveClient(this: p4);
  HIWORD(v14) = v5;
  LOWORD(v14) = v4->m_sLocalRoot.m_Id;
  v6 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v14);
  KeyValues::SetString(this: v3, keyName: "text", value: v6);
  v7 = p4->GetActiveClient(this: p4);
  HIWORD(v15) = v8;
  LOWORD(v15) = v7->m_sLocalRoot.m_Id;
  v9 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v15);
  KeyValues::SetString(this: v3, keyName: "path", value: v9);
  KeyValues::SetInt(this: v3, keyName: "dir", value: 1);
  m_pFileTree = this->m_pFileTree;
  v11 = m_pFileTree->__vftable;
  v12 = ((int (*)(void))m_pFileTree->GetRootItemIndex)();
  v13 = v11->AddItem(this: this->m_pFileTree, a2: v3, a3: v12);
  this->m_pFileTree->ExpandItem(this: this->m_pFileTree, a2: v13, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00402250
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402260
// Name: public: virtual struct vgui::PanelMessageMap __near * CVP4Dialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVP4Dialog::GetMessageMap(CVP4Dialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVP4Dialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVP4Dialog::GetMessageMap'::`2'::s_pMap;
  `CVP4Dialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
  `CVP4Dialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402290
// Name: public: virtual struct PanelAnimationMap __near * CVP4Dialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVP4Dialog::GetAnimMap(CVP4Dialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CVP4Dialog");
}

//------------------------------------------------------------------------------
// Address: 0x004022A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVP4Dialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVP4Dialog::GetKBMap(CVP4Dialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVP4Dialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVP4Dialog::GetKBMap'::`2'::s_pMap;
  `CVP4Dialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVP4Dialog");
  `CVP4Dialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004022D0
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402360
// Name: public: virtual void CFileTreeView::GenerateChildrenOfNode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTreeView::GenerateChildrenOfNode(CFileTreeView *this, int itemIndex)
{
  KeyValues *(__thiscall *GetItemData)(vgui::TreeView *, int); // eax
  int v3; // edi
  KeyValues *v4; // esi
  const char *String; // esi
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *v6; // esi
  __int16 v7; // ecx^2
  KeyValues *v8; // ebx
  const char *v9; // eax
  KeyValues *v10; // ebx
  const char *(__thiscall *v11)(IP4 *, CUtlSymbol); // edx
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  void (__thiscall *SetItemFgColor)(vgui::TreeView *, int, const Color *); // eax
  int v17; // [esp-8h] [ebp-228h]
  int v18; // [esp-4h] [ebp-224h]
  P4File_t *m_pMemory; // [esp-4h] [ebp-224h]
  char *v20; // [esp+0h] [ebp-220h]
  int v21; // [esp+0h] [ebp-220h]
  int v22; // [esp+0h] [ebp-220h]
  char *v23; // [esp+4h] [ebp-21Ch]
  int v24; // [esp+4h] [ebp-21Ch]
  int v25; // [esp+4h] [ebp-21Ch]
  char szLocalPath[260]; // [esp+Ch] [ebp-214h] BYREF
  char szPath[260]; // [esp+110h] [ebp-110h] BYREF
  CFileTreeView *v28; // [esp+214h] [ebp-Ch]
  int i; // [esp+218h] [ebp-8h]
  int v30; // [esp+21Ch] [ebp-4h] BYREF

  GetItemData = this->GetItemData;
  v28 = this;
  v3 = 0;
  v4 = (KeyValues *)((int (__stdcall *)(int))GetItemData)(a1: itemIndex);
  if ( KeyValues::GetInt(this: v4, keyName: "dir", defaultValue: 0) != 0 )
  {
    String = KeyValues::GetString(this: v4, keyName: "path", defaultValue: defaultValue);
    if ( *String != 0 )
    {
      g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
      v6 = p4->GetFileList(this: p4, a2: String);
      for ( i = 0; i < v6->m_Size; ++i )
      {
        if ( !v6->m_Memory.m_pMemory[v3].m_bDeleted )
        {
          v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v8 != nullptr )
          {
            HIWORD(v18) = v7;
            LOWORD(v18) = v6->m_Memory.m_pMemory[v3].m_sName.m_Id;
            v9 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v18);
            v10 = KeyValues::KeyValues(this: v8, setName: "node", firstKey: "text", firstValue: v9);
          }
          else
          {
            v10 = nullptr;
          }
          if ( v6->m_Memory.m_pMemory[v3].m_bDir )
          {
            KeyValues::SetInt(this: v10, keyName: "expand", value: 1);
            KeyValues::SetInt(this: v10, keyName: "dir", value: 1);
            KeyValues::SetInt(this: v10, keyName: "image", value: 1);
          }
          else
          {
            KeyValues::SetInt(this: v10, keyName: "image", value: 3);
          }
          m_pMemory = v6->m_Memory.m_pMemory;
          LOWORD(m_pMemory) = v6->m_Memory.m_pMemory[v3].m_sName.m_Id;
          v11 = p4->String;
          if ( v6->m_Memory.m_pMemory[v3].m_bDir )
          {
            v12 = ((int (__stdcall *)(P4File_t *, char *, char *))v11)(a1: m_pMemory, a2: v20, a3: v23);
            HIWORD(v21) = (unsigned int)&v6->m_Memory.m_pMemory[v3] >> 16;
            LOWORD(v21) = v6->m_Memory.m_pMemory[v3].m_sPath.m_Id;
            v24 = ((int (__thiscall *)(IP4 *, int, int))p4->String)(a1: p4, a2: v21, a3: v12);
            V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s/%s/%%%%1", v24);
          }
          else
          {
            v13 = ((int (__stdcall *)(P4File_t *, char *, char *))v11)(a1: m_pMemory, a2: v20, a3: v23);
            HIWORD(v22) = (unsigned int)&v6->m_Memory.m_pMemory[v3] >> 16;
            LOWORD(v22) = v6->m_Memory.m_pMemory[v3].m_sPath.m_Id;
            v25 = ((int (__thiscall *)(IP4 *, int, int))p4->String)(a1: p4, a2: v22, a3: v13);
            V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s/%s", v25);
          }
          v23 = szPath;
          v20 = szLocalPath;
          ((void (__thiscall *)(IP4 *))p4->GetLocalFilePath)(a1: p4);
          KeyValues::SetString(this: v10, keyName: "path", value: szLocalPath);
          v14 = _V_strrchr(s: szLocalPath, c: 92);
          if ( v14 != nullptr )
            *v14++ = 0;
          KeyValues::SetString(this: v10, keyName: "text", value: v14);
          v15 = v28->AddItem(this: v28, a2: v10, a3: itemIndex);
          if ( v6->m_Memory.m_pMemory[v3].m_iHaveRevision < v6->m_Memory.m_pMemory[v3].m_iHeadRevision )
          {
            v17 = v15;
            SetItemFgColor = v28->SetItemFgColor;
            v30 = -16776961;
            SetItemFgColor(this: v28, a2: v17, a3: (const Color *)&v30);
          }
        }
        ++v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025A0
// Name: private: void CVP4Dialog::RefreshClientList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::RefreshClientList(CVP4Dialog *this)
{
  CVP4Dialog *v1; // edi
  vgui::ComboBox *m_pClientCombo; // ecx
  CUtlVector<P4Client_t,CUtlMemory<P4Client_t,int> > *v3; // esi
  int v4; // ecx
  int m_Size; // eax
  int v6; // edx
  int v7; // ebx
  const char *v8; // eax
  __int16 v9; // ecx^2
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // eax
  int v13; // eax
  bool v14; // cc
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // eax
  int v16; // [esp-4h] [ebp-120h]
  int v17; // [esp-4h] [ebp-120h]
  const char *v18; // [esp-4h] [ebp-120h]
  int v19; // [esp-4h] [ebp-120h]
  int v20; // [esp-4h] [ebp-120h]
  int v21; // [esp+0h] [ebp-11Ch]
  char szText[256]; // [esp+Ch] [ebp-110h] BYREF
  int v23; // [esp+10Ch] [ebp-10h]
  int i; // [esp+110h] [ebp-Ch]
  CVP4Dialog *v25; // [esp+114h] [ebp-8h]
  P4Client_t *activeClient; // [esp+118h] [ebp-4h]

  v1 = this;
  m_pClientCombo = this->m_pClientCombo;
  v25 = v1;
  vgui::ComboBox::RemoveAll(this: m_pClientCombo);
  v3 = p4->GetClientList(this: p4);
  activeClient = p4->GetActiveClient(this: p4);
  m_Size = v3->m_Size;
  v6 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = v6;
      v4 = (int)&v3->m_Memory.m_pMemory[v6];
      v23 = *(unsigned __int16 *)(v4 + 4);
      if ( (_WORD)v23 == activeClient->m_sHost.m_Id )
      {
        HIWORD(v16) = HIWORD(v4);
        LOWORD(v16) = *(_WORD *)(v4 + 6);
        v21 = ((int (__thiscall *)(IP4 *, int, int))p4->String)(a1: p4, a2: v16, a3: v21);
        HIWORD(v17) = (unsigned int)&v3->m_Memory.m_pMemory[v7] >> 16;
        LOWORD(v17) = v3->m_Memory.m_pMemory[v7].m_sName.m_Id;
        v8 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v17);
        V_snprintf(pDest: szText, maxLen: 256, pFormat: "%s    %s", v8, v18);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
        {
          HIWORD(v19) = v9;
          LOWORD(v19) = v3->m_Memory.m_pMemory[v7].m_sName.m_Id;
          v11 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v19);
          v12 = KeyValues::KeyValues(this: v10, setName: "client", firstKey: "client", firstValue: v11);
        }
        else
        {
          v12 = nullptr;
        }
        v25->m_pClientCombo->AddItem_2(this: v25->m_pClientCombo, a2: szText, a3: v12);
        v6 = i;
        v1 = v25;
      }
      i = ++v6;
    }
    while ( v6 < v3->m_Size );
  }
  HIWORD(v20) = HIWORD(v4);
  LOWORD(v20) = activeClient->m_sName.m_Id;
  v13 = ((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v20);
  v1->m_pClientCombo->SetText(this: v1->m_pClientCombo, a2: (const char *)v13);
  v14 = v1->m_pClientCombo->GetItemCount(this: v1->m_pClientCombo) <= 1;
  SetEnabled = v1->m_pClientCombo->SetEnabled;
  if ( v14 )
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  else
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402740
// Name: private: virtual void CVP4Dialog::OnFileSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::OnFileSelected(CVP4Dialog *this)
{
  vgui::ListPanel *m_pRevisionList; // ecx
  void (__thiscall *RemoveAll)(vgui::ListPanel *); // edx
  int v4; // edi
  int v5; // ebx
  KeyValues *v6; // edi
  int Int; // eax
  IP4_vtbl *v8; // esi
  const char *String; // eax
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *v10; // esi
  KeyValues *v11; // eax
  __int16 v12; // ecx^2
  KeyValues *v13; // edi
  const char *v14; // eax
  char *v15; // eax
  char v16; // cl
  int v18; // [esp-4h] [ebp-31Ch]
  char szTime[256]; // [esp+Ch] [ebp-30Ch] BYREF
  char szDate[256]; // [esp+10Ch] [ebp-20Ch] BYREF
  char szShortDescription[256]; // [esp+20Ch] [ebp-10Ch] BYREF
  CVP4Dialog *v22; // [esp+30Ch] [ebp-Ch]
  int i; // [esp+310h] [ebp-8h]
  char *pTerm; // [esp+314h] [ebp-4h]

  m_pRevisionList = this->m_pRevisionList;
  RemoveAll = m_pRevisionList->RemoveAll;
  v22 = this;
  RemoveAll(this: m_pRevisionList);
  if ( this->m_pRevisionsPage->IsVisible(this: this->m_pRevisionsPage) )
  {
    v4 = this->m_pFileTree->GetFirstSelectedItem(this: this->m_pFileTree);
    v5 = 0;
    if ( v4 >= 0 )
    {
      g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 5u);
      this->m_pRevisionList->SetEmptyListText_2(
        this: this->m_pRevisionList,
        a2: "There is no revision history for the selected file.");
      v6 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: v4);
      Int = KeyValues::GetInt(this: v6, keyName: "dir", defaultValue: 0);
      v8 = p4->__vftable;
      LOBYTE(i) = Int != 0;
      String = KeyValues::GetString(this: v6, keyName: "path", defaultValue: defaultValue);
      v10 = v8->GetRevisionList(this: p4, a2: String, a3: i);
      for ( i = 0; i < v10->m_Size; ++i )
      {
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v13 = KeyValues::KeyValues(this: v11, setName: "node");
        else
          v13 = nullptr;
        HIWORD(v18) = v12;
        LOWORD(v18) = v10->m_Memory.m_pMemory[v5].m_sUser.m_Id;
        v14 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v18);
        KeyValues::SetString(this: v13, keyName: "user", value: v14);
        KeyValues::SetInt(this: v13, keyName: "change", value: v10->m_Memory.m_pMemory[v5].m_iChange);
        V_snprintf(
          pDest: szDate,
          maxLen: 256,
          pFormat: "%d/%d/%d",
          v10->m_Memory.m_pMemory[v5].m_nYear,
          v10->m_Memory.m_pMemory[v5].m_nMonth,
          v10->m_Memory.m_pMemory[v5].m_nDay);
        KeyValues::SetString(this: v13, keyName: "date", value: szDate);
        V_snprintf(
          pDest: szTime,
          maxLen: 256,
          pFormat: "%d:%d:%d",
          v10->m_Memory.m_pMemory[v5].m_nHour,
          v10->m_Memory.m_pMemory[v5].m_nMinute,
          v10->m_Memory.m_pMemory[v5].m_nSecond);
        KeyValues::SetString(this: v13, keyName: "time", value: szTime);
        v15 = CUtlString::Get(this: &v10->m_Memory.m_pMemory[v5].m_Description);
        v16 = *v15;
        pTerm = v15;
        if ( v16 != 0 )
        {
          do
          {
            if ( isspace(c: v16) == 0 && iscntrl(c: *pTerm) == 0 )
              break;
            v16 = *++pTerm;
          }
          while ( v16 != 0 );
          v15 = pTerm;
        }
        V_strncpy(pDest: szShortDescription, pSrc: v15, maxLen: 256);
        pTerm = szShortDescription;
        if ( szShortDescription[0] != 0 )
        {
          do
          {
            if ( iscntrl(c: *pTerm) != 0 )
              break;
          }
          while ( *++pTerm != 0 );
        }
        *pTerm = 0;
        KeyValues::SetString(this: v13, keyName: "description", value: szShortDescription);
        v22->m_pRevisionList->AddItem(this: v22->m_pRevisionList, a2: v13, a3: 0, a4: false, a5: false);
        ++v5;
      }
    }
    else
    {
      this->m_pRevisionList->SetEmptyListText_2(
        this: this->m_pRevisionList,
        a2: "No file or directory currently selected.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004029F0
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402A60
// Name: private: void CVP4Dialog::RefreshChangesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::RefreshChangesList(CVP4Dialog *this)
{
  vgui::SectionedListPanel *m_pChangesList; // ecx
  void (__thiscall *RemoveAll)(vgui::SectionedListPanel *); // edx
  signed int v4; // esi
  int *m_pMemory; // ebx
  signed int m_Size; // edi
  int v7; // edx
  int v8; // eax
  signed int v9; // esi
  int *v10; // esi
  __int16 v11; // ecx^2
  int v12; // esi
  int v13; // eax
  __int16 v14; // ecx^2
  int v15; // edi
  int v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  P4File_t *v19; // eax
  int v20; // [esp-Ch] [ebp-154h]
  int v21; // [esp-4h] [ebp-14Ch]
  const char *v22; // [esp-4h] [ebp-14Ch]
  char pDest[4]; // [esp+Ch] [ebp-13Ch] BYREF
  char szChangelistName[256]; // [esp+10h] [ebp-138h] BYREF
  int *v25; // [esp+110h] [ebp-38h]
  CUtlVector<int,CUtlMemory<int,int> > sections; // [esp+114h] [ebp-34h] BYREF
  int i; // [esp+128h] [ebp-20h]
  CVP4Dialog *v28; // [esp+12Ch] [ebp-1Ch]
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > files; // [esp+130h] [ebp-18h] BYREF
  int j; // [esp+144h] [ebp-4h]

  m_pChangesList = this->m_pChangesList;
  RemoveAll = m_pChangesList->RemoveAll;
  v28 = this;
  RemoveAll(this: m_pChangesList);
  this->m_pChangesList->RemoveAllSections(this: this->m_pChangesList);
  v4 = 0;
  memset(&files, 0, sizeof(files));
  p4->GetOpenedFileList_2(this: p4, a2: &files, a3: false);
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&sections, 0, sizeof(sections));
  i = 0;
  if ( files.m_Size > 0 )
  {
    v7 = 0;
    j = 0;
    do
    {
      v8 = 0;
      if ( m_Size <= 0 )
        goto LABEL_9;
      while ( m_pMemory[v8] != *(int *)((char *)&files.m_Memory.m_pMemory->m_iChangelist + v7) )
      {
        if ( ++v8 >= m_Size )
          goto LABEL_9;
      }
      if ( v8 < 0 || v8 >= m_Size )
      {
LABEL_9:
        v25 = (int *)((char *)&files.m_Memory.m_pMemory->m_iChangelist + v7);
        v9 = m_Size;
        if ( m_Size + 1 > sections.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&sections,
            num: m_Size - sections.m_Memory.m_nAllocationCount + 1);
          m_Size = sections.m_Size;
          m_pMemory = sections.m_Memory.m_pMemory;
        }
        sections.m_Size = ++m_Size;
        sections.m_pElements = m_pMemory;
        if ( m_Size - v9 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
        v10 = &m_pMemory[v9];
        if ( v10 != nullptr )
          *v10 = *v25;
        v4 = 0;
      }
      v7 = j + 32;
      ++i;
      j += 32;
    }
    while ( i < files.m_Size );
  }
  qsort(base: m_pMemory, num: m_Size, width: 4u, comp: (int (__cdecl *)(const void *, const void *))IntSortFunc);
  if ( m_Size > 0 )
  {
    do
    {
      v28->m_pChangesList->AddSection_2(this: v28->m_pChangesList, a2: m_pMemory[v4], a3: defaultValue, a4: nullptr);
      if ( m_pMemory[v4] <= 0 )
        V_snprintf(pDest: szChangelistName, maxLen: 256, pFormat: "CHANGE: DEFAULT");
      else
        V_snprintf(pDest: szChangelistName, maxLen: 256, pFormat: "CHANGE: %d", m_pMemory[v4]);
      v28->m_pChangesList->AddColumnToSection_2(
        this: v28->m_pChangesList,
        a2: m_pMemory[v4++],
        a3: "file",
        a4: szChangelistName,
        a5: 4,
        a6: 512,
        a7: 0);
    }
    while ( v4 < m_Size );
  }
  v12 = 0;
  for ( j = 0; j < files.m_Size; ++j )
  {
    HIWORD(v21) = v11;
    LOWORD(v21) = files.m_Memory.m_pMemory[v12].m_sName.m_Id;
    v13 = ((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v21);
    HIWORD(v20) = v14;
    LOWORD(v20) = files.m_Memory.m_pMemory[v12].m_sPath.m_Id;
    v15 = ((int (__thiscall *)(IP4 *, int, int))p4->String)(a1: p4, a2: v20, a3: v13);
    v16 = p4->GetDepotRootLength(this: p4);
    V_snprintf(pDest, maxLen: 260, pFormat: "%s/%s", (const char *)(v15 + v16), v22);
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v17 != nullptr )
      v18 = KeyValues::KeyValues(this: v17, setName: "node", firstKey: "file", firstValue: pDest);
    else
      v18 = nullptr;
    v28->m_pChangesList->AddItem(this: v28->m_pChangesList, a2: files.m_Memory.m_pMemory[v12++].m_iChangelist, a3: v18);
  }
  if ( sections.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  v19 = files.m_Memory.m_pMemory;
  files.m_Size = 0;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      v19 = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = v19;
  if ( files.m_Memory.m_nGrowSize >= 0 && v19 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
}

//------------------------------------------------------------------------------
// Address: 0x00402D60
// Name: private: virtual void CVP4Dialog::OpenFileForEdit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::OpenFileForEdit(CVP4Dialog *this, int iItem)
{
  KeyValues *v3; // eax
  IP4_vtbl *v4; // edi
  const char *String; // eax

  v3 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: iItem);
  if ( v3 != nullptr )
  {
    v4 = p4->__vftable;
    String = KeyValues::GetString(this: v3, keyName: "path", defaultValue: defaultValue);
    v4->OpenFileForEdit(this: p4, a2: String);
    CVP4Dialog::RefreshChangesList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402DC0
// Name: private: virtual void CVP4Dialog::OpenFileForDelete(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::OpenFileForDelete(CVP4Dialog *this, int iItem)
{
  KeyValues *v3; // eax
  IP4_vtbl *v4; // edi
  const char *String; // eax

  v3 = this->m_pFileTree->GetItemData(this: this->m_pFileTree, a2: iItem);
  if ( v3 != nullptr )
  {
    v4 = p4->__vftable;
    String = KeyValues::GetString(this: v3, keyName: "path", defaultValue: defaultValue);
    v4->OpenFileForDelete(this: p4, a2: String);
    CVP4Dialog::RefreshChangesList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402E20
// Name: public: static void CVP4Dialog::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVP4Dialog::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVP4Dialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CVP4Dialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "TreeViewItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402EB0
// Name: public: static void CVP4Dialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVP4Dialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVP4Dialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CVP4Dialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "TextChanged";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F40
// Name: public: static void CVP4Dialog::PanelMessageFunc_CloakFolder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVP4Dialog::PanelMessageFunc_CloakFolder::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVP4Dialog::PanelMessageFunc_CloakFolder::InitVar'::`2'::bAdded )
  {
    `CVP4Dialog::PanelMessageFunc_CloakFolder::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVP4Dialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CloakFolder";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "item";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402FF0
// Name: public: static void CVP4Dialog::PanelMessageFunc_OpenFileForEdit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVP4Dialog::PanelMessageFunc_OpenFileForEdit::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVP4Dialog::PanelMessageFunc_OpenFileForEdit::InitVar'::`2'::bAdded )
  {
    `CVP4Dialog::PanelMessageFunc_OpenFileForEdit::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "EditFile";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "item";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403090
// Name: public: static void CVP4Dialog::PanelMessageFunc_OpenFileForDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVP4Dialog::PanelMessageFunc_OpenFileForDelete::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVP4Dialog::PanelMessageFunc_OpenFileForDelete::InitVar'::`2'::bAdded )
  {
    `CVP4Dialog::PanelMessageFunc_OpenFileForDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DeleteFile";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "item";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403130
// Name: public: CVP4Dialog::CVP4Dialog(void)
// Source: json
//------------------------------------------------------------------------------
CVP4Dialog *__thiscall CVP4Dialog::CVP4Dialog(CVP4Dialog *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  vgui::ComboBox *v5; // eax
  vgui::ComboBox *v6; // eax
  CFileTreeView *v7; // eax
  CFileTreeView *v8; // eax
  vgui::IImage *v9; // eax
  vgui::IImage *v10; // eax
  vgui::IImage *v11; // eax
  vgui::PropertySheet *v12; // eax
  struct vgui::PropertySheetA *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  struct vgui::PropertySheetA *m_pViewsSheet; // ecx
  vgui::SectionedListPanel *v17; // eax
  vgui::SectionedListPanel *v18; // eax
  vgui::PropertyPage *v19; // eax
  vgui::PropertyPage *v20; // eax
  struct vgui::PropertySheetA *v21; // ecx
  CSmallTextListPanel *v22; // eax
  CSmallTextListPanel *v23; // eax
  int x; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: nullptr, panelName: "vp4dialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CVP4Dialog_vtbl *)&CVP4Dialog::`vftable';
  if ( `CVP4Dialog::ChainToMap'::`2'::chained == 0 )
  {
    `CVP4Dialog::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CVP4Dialog");
    v2->pfnClassName = CVP4Dialog::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CVP4Dialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVP4Dialog::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CVP4Dialog");
    v3->pfnClassName = CVP4Dialog::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CVP4Dialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVP4Dialog::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CVP4Dialog");
    v4->pfnClassName = CVP4Dialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CVP4Dialog::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CVP4Dialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CVP4Dialog::PanelMessageFunc_CloakFolder::InitVar(a1: (int)&savedregs);
  CVP4Dialog::PanelMessageFunc_OpenFileForEdit::InitVar(a1: (int)&savedregs);
  CVP4Dialog::PanelMessageFunc_OpenFileForDelete::InitVar(a1: (int)&savedregs);
  vgui::ImageList::ImageList(this: &this->m_Images, deleteImagesWhenDone: false);
  vgui::Panel::SetSize(this, wide: 1024, tall: 768);
  vgui::Frame::SetTitle(this, title: "VP4", surfaceTitle: true);
  v5 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v5 != nullptr )
    v6 = vgui::ComboBox::ComboBox(this: v5, parent: this, panelName: "ClientCombo", numLines: 16, allowEdit: false);
  else
    v6 = nullptr;
  this->m_pClientCombo = v6;
  v7 = (CFileTreeView *)operator new(nSize: 0x1C0u);
  if ( v7 != nullptr )
    v8 = CFileTreeView::CFileTreeView(this: v7, parent: this, name: "FileTree");
  else
    v8 = nullptr;
  this->m_pFileTree = v8;
  v9 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v9);
  v10 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_folder_selected", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v10);
  v11 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "resource/icon_file", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_Images, elem: (unsigned int)v11);
  this->m_pFileTree->SetImageList(this: this->m_pFileTree, a2: &this->m_Images, a3: false);
  v12 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = (struct vgui::PropertySheetA *)vgui::PropertySheet::PropertySheet(
                                           this: v12,
                                           parent: this,
                                           panelName: "ViewsSheet",
                                           draggableTabs: false);
  else
    v13 = nullptr;
  this->m_pViewsSheet = v13;
  v14 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v14 != nullptr )
    v15 = vgui::PropertyPage::PropertyPage(
            this: v14,
            parent: (vgui::Panel *)this->m_pViewsSheet,
            panelName: "ChangesPage");
  else
    v15 = nullptr;
  m_pViewsSheet = this->m_pViewsSheet;
  this->m_pChangesPage = v15;
  (*(void (__thiscall **)(struct vgui::PropertySheetA *, vgui::PropertyPage *, const char *, _DWORD, _DWORD, int))(*(_DWORD *)m_pViewsSheet + 948))(
    a1: m_pViewsSheet,
    a2: v15,
    a3: "Changes",
    a4: 0,
    a5: 0,
    a6: -1);
  v17 = (vgui::SectionedListPanel *)operator new(nSize: 0x1FCu);
  if ( v17 != nullptr )
    v18 = vgui::SectionedListPanel::SectionedListPanel(this: v17, parent: this->m_pChangesPage, name: "ChangesList");
  else
    v18 = nullptr;
  this->m_pChangesList = v18;
  vgui::Panel::GetBounds(this: this->m_pChangesPage, &x, &y, &wide, &tall);
  vgui::Panel::SetAutoResize(
    this: this->m_pChangesList,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 6,
    nPinOffsetY: 6,
    nUnpinnedCornerOffsetX: -12,
    nUnpinnedCornerOffsetY: -12);
  v19 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v19 != nullptr )
    v20 = vgui::PropertyPage::PropertyPage(
            this: v19,
            parent: (vgui::Panel *)this->m_pViewsSheet,
            panelName: "RevisionsPage");
  else
    v20 = nullptr;
  v21 = this->m_pViewsSheet;
  this->m_pRevisionsPage = v20;
  (*(void (__thiscall **)(struct vgui::PropertySheetA *, vgui::PropertyPage *, const char *, _DWORD, _DWORD, int))(*(_DWORD *)v21 + 948))(
    a1: v21,
    a2: v20,
    a3: "History",
    a4: 0,
    a5: 0,
    a6: -1);
  v22 = (CSmallTextListPanel *)operator new(nSize: 0x250u);
  if ( v22 != nullptr )
    v23 = CSmallTextListPanel::CSmallTextListPanel(this: v22, parent: this->m_pRevisionsPage, name: "RevisionList");
  else
    v23 = nullptr;
  this->m_pRevisionList = v23;
  v23->SetEmptyListText_2(this: v23, a2: "No file or directory currently selected.");
  this->m_pRevisionList->AddColumnHeader(this: this->m_pRevisionList, a2: 0, a3: "change", a4: "change", a5: 52, a6: 8);
  this->m_pRevisionList->AddColumnHeader(this: this->m_pRevisionList, a2: 1, a3: "date", a4: "date", a5: 52, a6: 0);
  this->m_pRevisionList->AddColumnHeader(this: this->m_pRevisionList, a2: 2, a3: "time", a4: "time", a5: 52, a6: 8);
  this->m_pRevisionList->AddColumnHeader(this: this->m_pRevisionList, a2: 3, a3: "user", a4: "user", a5: 64, a6: 0);
  this->m_pRevisionList->AddColumnHeader(
    this: this->m_pRevisionList,
    a2: 4,
    a3: "description",
    a4: "description",
    a5: 32,
    a6: 2);
  this->m_pRevisionList->SetAllowUserModificationOfColumns(this: this->m_pRevisionList, a2: true);
  vgui::Panel::GetBounds(this: this->m_pRevisionsPage, &x, &y, &wide, &tall);
  vgui::Panel::SetAutoResize(
    this: this->m_pRevisionList,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 6,
    nPinOffsetY: 6,
    nUnpinnedCornerOffsetX: -12,
    nUnpinnedCornerOffsetY: -12);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "//PLATFORM/resource/vp4dialog.res",
    dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403550
// Name: public: virtual void CVP4Dialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVP4Dialog::Activate(CVP4Dialog *this)
{
  P4Client_t *v2; // eax
  __int16 v3; // ecx^2
  const char *v4; // eax
  int v5; // [esp-4h] [ebp-108h]
  char szTitle[256]; // [esp+4h] [ebp-100h] BYREF

  vgui::Frame::Activate(this);
  v2 = p4->GetActiveClient(this: p4);
  HIWORD(v5) = v3;
  LOWORD(v5) = v2->m_sUser.m_Id;
  v4 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v5);
  V_snprintf(pDest: szTitle, maxLen: 256, pFormat: "VP4 - %s", v4);
  this->SetTitle_2(this, a2: szTitle, a3: true);
  CVP4Dialog::RefreshFileList(this);
  CVP4Dialog::RefreshClientList(this);
  CVP4Dialog::RefreshChangesList(this);
  p4->GetClientList(this: p4);
}

//------------------------------------------------------------------------------
// Address: 0x00403A50
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404180
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004042F0
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004049A0
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040E070
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x0040E400
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E5F0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040E870
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x0040EE40
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0040F110
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x0040F4A0
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x0040F4D0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x0040F960
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x00411250
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x004112C0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00411310
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x00411FF0
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00413140
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413930
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x00413AF0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00413CC0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00413E90
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00414730
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00414790
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415B90
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415BD0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415C10
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415C50
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417110
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417180
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417210
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041B020
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x0041C4F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  CPanelMessageMapDictionary *PanelMessageMapDictionary; // eax
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  PanelMessageMapDictionary = GetPanelMessageMapDictionary();
  result = CPanelMessageMapDictionary::FindOrAddPanelMessageMap(this: PanelMessageMapDictionary, className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C520
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  CPanelKeyBindingMapDictionary *PanelKeyBindingMapDictionary; // eax
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  PanelKeyBindingMapDictionary = vgui::GetPanelKeyBindingMapDictionary();
  result = CPanelKeyBindingMapDictionary::FindOrAddPanelKeyBindingMap(
             this: PanelKeyBindingMapDictionary,
             className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004292C0
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E960
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0043CA20
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x0043D540
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D820
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00445C30
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044B700
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DCB0
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00450970
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x004513F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451420
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x00451430
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453D70
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00455000
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455300
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456E70
// Name: public: int CUtlVector<class vgui::CItemButton __near *,class CUtlMemory<class vgui::CItemButton __near *,int>>::Find(class vgui::CItemButton __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
        CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int> > *this,
        vgui::CItemButton **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::CItemButton **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457BC0
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00458E50
// Name: public: int CUtlVector<struct vgui::SectionedListPanel::column_t,class CUtlMemory<struct vgui::SectionedListPanel::column_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int>>::AddToTail(
        CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::SectionedListPanel::column_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::SectionedListPanel::column_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 172 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00459000
// Name: public: int CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::SectionedListPanel::section_t *m_pMemory; // ecx
  int v6; // eax
  vgui::SectionedListPanel::section_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::SectionedListPanel::section_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Columns.m_Memory.m_pMemory = nullptr;
    v7->m_Columns.m_Memory.m_nAllocationCount = 0;
    v7->m_Columns.m_Memory.m_nGrowSize = 0;
    v7->m_Columns.m_Size = 0;
    v7->m_Columns.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00459330
// Name: public: void CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 36 * v1;
    v5 = 36 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 6) = 0;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( *((_DWORD *)v3 + 3) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 3));
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      v4 = *((void **)v3 + 3);
      *((_DWORD *)v3 + 7) = v4;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      --v1;
      v2 = v5 - 36;
      v5 -= 36;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459500
// Name: public: CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::~CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::~CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this)
{
  bool v2; // sf
  vgui::SectionedListPanel::section_t *m_pMemory; // eax

  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BB70
// Name: public: void CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::Remove(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045BBB0
// Name: public: void CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Remove(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045C070
// Name: public: int CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::InsertBefore(int,struct vgui::PropertySheet::Page_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::InsertBefore(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem,
        const vgui::PropertySheet::Page_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v7; // eax
  vgui::PropertySheet::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::PropertySheet::Page_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045C0E0
// Name: public: int CUtlVector<class vgui::CItemButton __near *,class CUtlMemory<class vgui::CItemButton __near *,int>>::InsertBefore(int,class vgui::CItemButton __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::InsertBefore(
        CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int> > *this,
        int elem,
        vgui::CItemButton **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CItemButton **m_pMemory; // ecx
  int v7; // eax
  vgui::CItemButton **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045E680
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x0045FC50
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00460230
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::PropertySheet::Page_t,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004625E0
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462670
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
