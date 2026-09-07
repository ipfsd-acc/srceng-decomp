// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/toolmenubutton.cpp
// Functions: 20
// ============================================================

#include "tools\toolutils\toolmenubutton.h"

//------------------------------------------------------------------------------
// Address: 0x102BDA10
// Name: public: static char const __near * CToolMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolMenuButton::GetPanelClassName()
{
  return "CToolMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x102BDA20
// Name: public: virtual void CToolMenuButton::AddSeparator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::AddSeparator(CToolMenuButton *this)
{
  this->m_pMenu->AddSeparator(this: this->m_pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x102BDA30
// Name: public: virtual class vgui::MenuItem __near * CToolMenuButton::GetMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall CToolMenuButton::GetMenuItem(CToolMenuButton *this, int itemID)
{
  return vgui::Menu::GetMenuItem(this: this->m_pMenu, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x102BDA40
// Name: public: virtual void CToolMenuButton::AddSeparatorAfterItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::AddSeparatorAfterItem(CToolMenuButton *this, const char *itemName)
{
  int v3; // eax

  v3 = this->FindMenuItem(this, a2: itemName);
  if ( v3 != -1 )
    this->m_pMenu->AddSeparatorAfterItem(this: this->m_pMenu, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102BDA80
// Name: public: virtual void CToolMenuButton::MoveMenuItem(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::MoveMenuItem(CToolMenuButton *this, int itemID, int moveBeforeThisItemID)
{
  this->m_pMenu->MoveMenuItem(this: this->m_pMenu, a2: itemID, a3: moveBeforeThisItemID);
}

//------------------------------------------------------------------------------
// Address: 0x102BDAA0
// Name: public: virtual void CToolMenuButton::SetCurrentKeyBindingLabel(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::SetCurrentKeyBindingLabel(
        CToolMenuButton *this,
        const char *itemName,
        const char *binding)
{
  int v4; // eax

  v4 = this->FindMenuItem(this, a2: itemName);
  if ( v4 != -1 )
    vgui::Menu::SetCurrentKeyBinding(this: this->m_pMenu, itemID: v4, hotkey: binding);
}

//------------------------------------------------------------------------------
// Address: 0x102BDAD0
// Name: public: class vgui::Menu __near * CToolMenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall CToolMenuButton::GetMenu(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x102BE570
// Name: public: virtual void CToolMenuButton::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::SetItemEnabled(CToolMenuButton *this, unsigned __int16 itemID, BOOL state)
{
  this->m_pMenu->SetItemEnabled(
    this: this->m_pMenu,
    a2: this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[itemID].m_Data.elem.m_ItemID,
    a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BE5B0
// Name: protected: void CToolMenuButton::UpdateMenuItemKeyBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::UpdateMenuItemKeyBindings(CToolMenuButton *this)
{
  int v2; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  char *v4; // eax
  wchar_t *v5; // eax
  char ansi[512]; // [esp+4h] [ebp-418h] BYREF
  wchar_t sz[256]; // [esp+204h] [ebp-218h] BYREF
  int c; // [esp+404h] [ebp-18h]
  CUtlVector<vgui::BoundKey_t *,CUtlMemory<vgui::BoundKey_t *,int> > list; // [esp+408h] [ebp-14h] BYREF

  if ( this->m_pActionTarget != nullptr )
  {
    v2 = 0;
    c = this->m_Items.m_Elements.m_Tree.m_NumElements;
    if ( c != 0 )
    {
      do
      {
        m_pMemory = this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( m_pMemory[(unsigned __int16)v2].m_Data.elem.m_KeyBinding.m_Id != 0xFFFF )
        {
          v4 = CUtlSymbol::String(this: &m_pMemory[(unsigned __int16)v2].m_Data.elem.m_KeyBinding);
          memset(&list, 0, sizeof(list));
          vgui::Panel::LookupBoundKeys(
            this: this->m_pActionTarget,
            bindingName: v4,
            (CUtlMemory<vgui::TreeNode *,int> *)&list);
          if ( list.m_Size > 0 )
          {
            v5 = vgui::Panel::KeyCodeModifiersToDisplayString(
                   code: (ButtonCode_t)(*list.m_Memory.m_pMemory)->keycode,
                   modifiers: (*list.m_Memory.m_pMemory)->modifiers);
            wcsncpy(dest: sz, source: v5, count: 0x100u);
            sz[255] = 0;
            g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: sz, a3: ansi, a4: 512);
            vgui::Menu::SetCurrentKeyBinding(
              this: this->m_pMenu,
              itemID: this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v2].m_Data.elem.m_ItemID,
              hotkey: ansi);
          }
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
        }
        ++v2;
      }
      while ( v2 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BE6C0
// Name: public: virtual void CToolMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::OnShowMenu(CToolMenuButton *this, vgui::Menu *menu)
{
  vgui::Panel *v3; // eax
  vgui::Slider *v4; // eax
  int RangeWindow; // eax

  v3 = this->GetParent(this);
  v4 = (vgui::Slider *)__RTDynamicCast(
                         inptr: v3,
                         VfDelta: 0,
                         SrcType: &vgui::Panel `RTTI Type Descriptor',
                         TargetType: &CToolMenuBar `RTTI Type Descriptor',
                         isReference: 0);
  if ( v4 != nullptr )
  {
    RangeWindow = vgui::ScrollBarSlider::GetRangeWindow(this: v4);
    if ( RangeWindow != 0 )
      (*(void (__thiscall **)(int, vgui::Menu *))(*(_DWORD *)RangeWindow + 964))(a1: RangeWindow, a2: menu);
  }
  CToolMenuButton::UpdateMenuItemKeyBindings(this);
  vgui::Menu::ForceCalculateWidth(this: this->m_pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x102BE7A0
// Name: public: void CToolMenuButton::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::Reset(CToolMenuButton *this)
{
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::RemoveAll(this: &this->m_Items);
  vgui::Menu::DeleteAllItems(this: this->m_pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x102BE7C0
// Name: public: virtual int CToolMenuButton::FindMenuItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolMenuButton::FindMenuItem(CToolMenuButton *this, const char *itemName)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( itemName != nullptr )
  {
    search.key = itemName;
    search.elem = (CToolMenuButton::MenuItem_t)-65536;
    v3 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Items.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v3 = -1;
  }
  if ( v3 == 0xFFFF )
    return -1;
  else
    return this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.m_ItemID;
}

//------------------------------------------------------------------------------
// Address: 0x102BE8A0
// Name: public: CToolMenuButton::CToolMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CToolMenuButton *__thiscall CToolMenuButton::CToolMenuButton(
        CToolMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *actionTarget)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  vgui::Menu *v10; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CToolMenuButton_vtbl *)&CToolMenuButton::`vftable';
  if ( `CToolMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CToolMenuButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
    v6->pfnClassName = CToolMenuButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `CToolMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
    v7->pfnClassName = CToolMenuButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `CToolMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
    v8->pfnClassName = CToolMenuButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  this->m_pActionTarget = actionTarget;
  this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Items.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Items.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Items.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v10 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v10 != nullptr )
    this->m_pMenu = vgui::Menu::Menu(this: v10, parent: this, panelName: "Menu");
  else
    this->m_pMenu = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BE9F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolMenuButton::GetMessageMap(CToolMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolMenuButton::GetMessageMap'::`2'::s_pMap;
  `CToolMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
  `CToolMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BEA20
// Name: public: virtual struct PanelAnimationMap __near * CToolMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolMenuButton::GetAnimMap(CToolMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x102BEA30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolMenuButton::GetKBMap(CToolMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolMenuButton::GetKBMap'::`2'::s_pMap;
  `CToolMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
  `CToolMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BEB20
// Name: public: virtual int CToolMenuButton::AddMenuItem(char const __near *,char const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolMenuButton::AddMenuItem(
        CToolMenuButton *this,
        const char *itemName,
        const char *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData,
        char *kbcommandname)
{
  int v8; // edi

  v8 = this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: itemText, a3: message, a4: target, a5: userData);
  HIWORD(target) = -1;
  LOWORD(target) = v8;
  if ( kbcommandname != nullptr )
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&userData + 1, pStr: kbcommandname);
    HIWORD(target) = HIWORD(userData);
  }
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::Insert(
    this: &this->m_Items,
    pName: itemName,
    element: (const CToolMenuButton::MenuItem_t *)&target);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x102BEB90
// Name: public: virtual int CToolMenuButton::AddCheckableMenuItem(char const __near *,char const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolMenuButton::AddCheckableMenuItem(
        CToolMenuButton *this,
        const char *itemName,
        const char *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData,
        char *kbcommandname)
{
  int v8; // edi

  v8 = this->m_pMenu->AddCheckableMenuItem(this: this->m_pMenu, a2: itemText, a3: message, a4: target, a5: userData);
  HIWORD(target) = -1;
  LOWORD(target) = v8;
  if ( kbcommandname != nullptr )
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&userData + 1, pStr: kbcommandname);
    HIWORD(target) = HIWORD(userData);
  }
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::Insert(
    this: &this->m_Items,
    pName: itemName,
    element: (const CToolMenuButton::MenuItem_t *)&target);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x102BEC00
// Name: public: virtual int CToolMenuButton::AddMenuItem(char const __near *,wchar_t const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolMenuButton::AddMenuItem(
        CToolMenuButton *this,
        const char *itemName,
        const wchar_t *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData,
        char *kbcommandname)
{
  int v8; // edi

  v8 = this->m_pMenu->AddMenuItem(
         this: this->m_pMenu,
         a2: itemName,
         a3: itemText,
         a4: message,
         a5: target,
         a6: userData);
  HIWORD(target) = -1;
  LOWORD(target) = v8;
  if ( kbcommandname != nullptr )
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&userData + 1, pStr: kbcommandname);
    HIWORD(target) = HIWORD(userData);
  }
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::Insert(
    this: &this->m_Items,
    pName: itemName,
    element: (const CToolMenuButton::MenuItem_t *)&target);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x102BEC70
// Name: public: virtual int CToolMenuButton::AddCheckableMenuItem(char const __near *,wchar_t const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolMenuButton::AddCheckableMenuItem(
        CToolMenuButton *this,
        const char *itemName,
        const wchar_t *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData,
        char *kbcommandname)
{
  int v8; // edi

  v8 = this->m_pMenu->AddCheckableMenuItem(
         this: this->m_pMenu,
         a2: itemName,
         a3: itemText,
         a4: message,
         a5: target,
         a6: userData);
  HIWORD(target) = -1;
  LOWORD(target) = v8;
  if ( kbcommandname != nullptr )
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&userData + 1, pStr: kbcommandname);
    HIWORD(target) = HIWORD(userData);
  }
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::Insert(
    this: &this->m_Items,
    pName: itemName,
    element: (const CToolMenuButton::MenuItem_t *)&target);
  return v8;
}
