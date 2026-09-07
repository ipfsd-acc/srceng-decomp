// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/keybindinghelpdialog.cpp
// Functions: 12
// ============================================================

#include "vgui2\vgui_controls\keybindinghelpdialog.h"

//------------------------------------------------------------------------------
// Address: 0x1031F5F0
// Name: BindingLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BindingLessFunc(KeyValues **lhs, KeyValues **rhs)
{
  KeyValues *v2; // esi
  char *v3; // eax
  char *String; // [esp-4h] [ebp-8h]

  v2 = *lhs;
  String = KeyValues::GetString(this: *rhs, keyName: "Action", defaultValue: &var);
  v3 = KeyValues::GetString(this: v2, keyName: "Action", defaultValue: &var);
  return _V_stricmp(s1: v3, s2: String) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10322210
// Name: public: static char const __near * vgui::CKeyBindingHelpDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CKeyBindingHelpDialog::GetPanelClassName()
{
  return "CKeyBindingHelpDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10322220
// Name: private: bool vgui::CKeyBindingHelpDialog::IsHelpKeyStillBeingHeld(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall vgui::CKeyBindingHelpDialog::IsHelpKeyStillBeingHeld@<al>(
        vgui::CKeyBindingHelpDialog *this@<ecx>,
        int a2@<ebx>)
{
  bool result; // al
  bool v4; // bl
  bool v5; // cl
  int v6; // eax
  bool ctrl; // [esp+7h] [ebp-1h]

  result = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: this->m_KeyCode);
  if ( result )
  {
    v4 = ((unsigned __int8 (__thiscall *)(vgui::IInput *, int, int))g_pVGuiInput->IsKeyDown)(
           a1: g_pVGuiInput,
           a2: 79,
           a3: a2) != 0
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (ctrl = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      ctrl = true;
    }
    v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT);
    v6 = v4;
    if ( ctrl )
      v6 |= 2u;
    if ( v5 )
      v6 |= 4u;
    return v6 == this->m_Modifiers;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10322300
// Name: public: virtual void vgui::CKeyBindingHelpDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBindingHelpDialog::OnKeyCodeTyped(vgui::CKeyBindingHelpDialog *this, ButtonCode_t code)
{
  vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10322310
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CKeyBindingHelpDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CKeyBindingHelpDialog::GetMessageMap(vgui::CKeyBindingHelpDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CKeyBindingHelpDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBindingHelpDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::CKeyBindingHelpDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKeyBindingHelpDialog");
  `vgui::CKeyBindingHelpDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10322340
// Name: public: virtual struct PanelAnimationMap __near * vgui::CKeyBindingHelpDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CKeyBindingHelpDialog::GetAnimMap(vgui::CKeyBindingHelpDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CKeyBindingHelpDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10322350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CKeyBindingHelpDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CKeyBindingHelpDialog::GetKBMap(vgui::CKeyBindingHelpDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CKeyBindingHelpDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBindingHelpDialog::GetKBMap'::`2'::s_pMap;
  `vgui::CKeyBindingHelpDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBindingHelpDialog");
  `vgui::CKeyBindingHelpDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103223D0
// Name: private: virtual void vgui::CKeyBindingHelpDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CKeyBindingHelpDialog::OnTick(vgui::CKeyBindingHelpDialog *this@<ecx>, int a2@<ebx>)
{
  bool IsHelpKeyStillBeingHeld; // bl
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  IsHelpKeyStillBeingHeld = vgui::CKeyBindingHelpDialog::IsHelpKeyStillBeingHeld(this, a2);
  if ( g_pVGuiSystem->GetCurrentTime(this: g_pVGuiSystem) - this->m_flShowTime <= 1.0 )
  {
    if ( !IsHelpKeyStillBeingHeld )
    {
      v4 = g_pVGui;
      v5 = g_pVGui->__vftable;
      v6 = this->GetVPanel(this);
      v5->RemoveTickSignal(this: v4, a2: v6);
      this->m_bPermanent = true;
    }
  }
  else if ( !IsHelpKeyStillBeingHeld )
  {
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322440
// Name: public: void vgui::CKeyBindingHelpDialog::HelpKeyPressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBindingHelpDialog::HelpKeyPressed(vgui::CKeyBindingHelpDialog *this)
{
  if ( vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor) == nullptr && this->m_bPermanent )
    this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x10322470
// Name: public: virtual void vgui::CKeyBindingHelpDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBindingHelpDialog::OnCommand(vgui::CKeyBindingHelpDialog *this, const char *cmd)
{
  vgui::Panel *v3; // eax
  vgui::CKeyBoardEditorDialog *v4; // ebx
  CDragDropHelperPanel *v5; // eax
  vgui::CKeyBoardEditorDialog *v6; // eax
  vgui::Panel *v7; // eax
  vgui::IVGui *v8; // edi
  vgui::IVGui_vtbl *v9; // ebx
  int v10; // eax

  if ( _V_stricmp(s1: cmd, s2: "OK") != 0
    && _V_stricmp(s1: cmd, s2: "cancel") != 0
    && _V_stricmp(s1: cmd, s2: "Close") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "edit") != 0 )
    {
      vgui::Frame::OnCommand(this, command: cmd);
    }
    else
    {
      if ( vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor) != nullptr )
      {
        v3 = vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor);
        if ( v3 != nullptr )
          ((void (__thiscall *)(vgui::Panel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
      }
      v4 = (vgui::CKeyBoardEditorDialog *)operator new(nSize: 0x228u);
      if ( v4 != nullptr )
      {
        v5 = (CDragDropHelperPanel *)vgui::PHandle::Get(this: &this->m_hPanel);
        v6 = vgui::CKeyBoardEditorDialog::CKeyBoardEditorDialog(
               this: v4,
               parent: this,
               panelToEdit: v5,
               handle: this->m_Handle);
      }
      else
      {
        v6 = nullptr;
      }
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hKeyBindingsEditor,
        pPanel: (CDragDropHelperPanel *)v6);
      v7 = vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor);
      v7->__vftable[1].IsEnabled(this: v7);
      v8 = g_pVGui;
      v9 = g_pVGui->__vftable;
      v10 = this->GetVPanel(this);
      v9->RemoveTickSignal(this: v8, a2: v10);
      this->m_bPermanent = true;
    }
  }
  else
  {
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103225A0
// Name: private: void vgui::CKeyBindingHelpDialog::PopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBindingHelpDialog::PopulateList(vgui::CKeyBindingHelpDialog *this)
{
  vgui::ListPanel *m_pList; // ecx
  void (__thiscall *DeleteAllItems)(vgui::ListPanel *); // edx
  int v4; // esi
  vgui::Panel *v5; // edi
  vgui::PanelKeyBindingMap *j; // edi
  int k; // eax
  int m_Size; // eax
  int v9; // esi
  ListInfo_t *m_pMemory; // ecx
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *m_pPanel; // edx
  int v15; // eax
  vgui::BoundKey_t *v16; // esi
  KeyValues *v17; // eax
  const wchar_t *v18; // eax
  wchar_t *v19; // eax
  vgui::PanelKeyBindingMap *v20; // eax
  char *m_nAllocationCount; // edi
  const wchar_t *v22; // eax
  int v23; // eax
  UtlRBTreeNode_t<KeyValues *,int> *v24; // ecx
  int v25; // edx
  int v26; // esi
  int v27; // edx
  int v28; // eax
  const char **v29; // esi
  vgui::BoundKey_t **v30; // eax
  bool v31; // sf
  IMemAlloc *v32; // ecx
  KeyValues *v33; // eax
  const wchar_t *v34; // eax
  char *v35; // edi
  const wchar_t *v36; // eax
  int v37; // eax
  UtlRBTreeNode_t<KeyValues *,int> *v38; // ecx
  int v39; // edx
  int v40; // esi
  int v41; // edx
  int ii; // esi
  KeyValues *m_Data; // edi
  char loc[128]; // [esp+Ch] [ebp-1F4h] BYREF
  char ansi[256]; // [esp+8Ch] [ebp-174h] BYREF
  vgui::CKeyBindingHelpDialog *v46; // [esp+18Ch] [ebp-74h]
  vgui::Panel *v47; // [esp+190h] [ebp-70h]
  CUtlRBTree<KeyValues *,int,bool (__cdecl*)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int> > sorted; // [esp+194h] [ebp-6Ch] BYREF
  int i; // [esp+1B8h] [ebp-48h]
  vgui::PanelKeyBindingMap *m; // [esp+1BCh] [ebp-44h]
  CUtlVector<ListInfo_t,CUtlMemory<ListInfo_t,int> > maps; // [esp+1C0h] [ebp-40h] BYREF
  CUtlVector<vgui::BoundKey_t *,CUtlMemory<vgui::BoundKey_t *,int> > list; // [esp+1D4h] [ebp-2Ch] BYREF
  int parent; // [esp+1E8h] [ebp-18h] BYREF
  int n; // [esp+1ECh] [ebp-14h] BYREF
  unsigned int v55; // [esp+1F0h] [ebp-10h]
  KeyValues *item; // [esp+1F4h] [ebp-Ch] BYREF
  vgui::Panel *pPanel; // [esp+1F8h] [ebp-8h] BYREF
  bool leftchild; // [esp+1FFh] [ebp-1h] BYREF

  m_pList = this->m_pList;
  DeleteAllItems = m_pList->DeleteAllItems;
  v46 = this;
  DeleteAllItems(this: m_pList);
  v4 = 0;
  memset(&maps, 0, sizeof(maps));
  v5 = vgui::PHandle::Get(this: &this->m_hPanel);
  pPanel = v5;
  if ( vgui::Panel::IsKeyBindingChainToParentAllowed(this: v5) )
  {
    while ( 1 )
    {
      for ( j = v5->GetKBMap(this: v5); j != nullptr; j = j->baseMap )
      {
        for ( k = 0; k < v4; ++k )
        {
          if ( maps.m_Memory.m_pMemory[k].m_pMap == j )
            break;
        }
        if ( k == v4 )
        {
          m_Size = maps.m_Size;
          v9 = maps.m_Size;
          if ( maps.m_Size + 1 > maps.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CacheOptimizedKDNode,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&maps,
              num: maps.m_Size - maps.m_Memory.m_nAllocationCount + 1);
            m_Size = maps.m_Size;
          }
          m_pMemory = maps.m_Memory.m_pMemory;
          maps.m_Size = m_Size + 1;
          v11 = m_Size - v9;
          maps.m_pElements = maps.m_Memory.m_pMemory;
          if ( v11 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&maps.m_Memory.m_pMemory[v9 + 1],
              src: (unsigned __int8 *)&maps.m_Memory.m_pMemory[v9],
              count: 8 * v11);
            m_pMemory = maps.m_Memory.m_pMemory;
          }
          v12 = pPanel;
          m_pMemory[v9].m_pMap = j;
          m_pMemory[v9].m_pPanel = v12;
          v4 = maps.m_Size;
        }
      }
      v13 = pPanel->GetParent(this: pPanel);
      pPanel = v13;
      if ( v13 == nullptr || !vgui::Panel::IsKeyBindingChainToParentAllowed(this: v13) )
        break;
      v5 = pPanel;
    }
  }
  sorted.m_LessFunc = (bool (__cdecl *)(KeyValues *const *, KeyValues *const *))BindingLessFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  sorted.m_Root = -1;
  sorted.m_NumElements = 0;
  sorted.m_FirstFree = -1;
  sorted.m_LastAlloc.index = -1;
  sorted.m_pElements = nullptr;
  i = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      m_pPanel = maps.m_Memory.m_pMemory[i].m_pPanel;
      v15 = maps.m_Memory.m_pMemory[i].m_pMap->boundkeys.m_Size;
      m = maps.m_Memory.m_pMemory[i].m_pMap;
      v47 = m_pPanel;
      if ( v15 > 0 )
      {
        v55 = 0;
        for ( n = v15; n != 0; --n )
        {
          v16 = &m->boundkeys.m_Memory.m_pMemory[v55 / 0x10];
          v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v17 != nullptr )
            item = KeyValues::KeyValues(this: v17, setName: "Item");
          else
            item = nullptr;
          V_snprintf(pDest: loc, maxLen: 0x80u, pFormat: "#%s", v16->bindingname);
          ansi[0] = 0;
          v18 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: loc);
          if ( v18 != nullptr )
            g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v18, a3: ansi, a4: 256);
          else
            V_strncpy(pDest: ansi, pSrc: loc, maxLen: 256);
          KeyValues::SetString(this: item, keyName: "Action", value: ansi);
          v19 = vgui::Panel::KeyCodeModifiersToDisplayString(
                  code: (ButtonCode_t)v16->keycode,
                  modifiers: v16->modifiers);
          KeyValues::SetWString(this: item, keyName: "Binding", value: v19);
          v20 = vgui::Panel::LookupBinding(this: v47, bindingName: v16->bindingname);
          if ( v20 != nullptr )
          {
            m_nAllocationCount = (char *)v20->defaultkeys.m_Memory.m_nAllocationCount;
            if ( m_nAllocationCount != nullptr )
            {
              ansi[0] = 0;
              v22 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: m_nAllocationCount);
              if ( v22 != nullptr )
                g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v22, a3: ansi, a4: 256);
              else
                V_strncpy(pDest: ansi, pSrc: m_nAllocationCount, maxLen: 256);
              KeyValues::SetString(this: item, keyName: "Description", value: ansi);
            }
          }
          KeyValues::SetPtr(this: item, keyName: "Item", value: v16);
          parent = -1;
          leftchild = false;
          CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FindInsertionPosition(
            this: &sorted,
            insert: &item,
            &parent,
            &leftchild);
          v23 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(
                  this: &sorted,
                  a2: (const char *)0xFFFFFFFF);
          v24 = sorted.m_Elements.m_pMemory;
          v25 = parent;
          v26 = v23;
          sorted.m_Elements.m_pMemory[v26].m_Parent = parent;
          v24[v26].m_Right = -1;
          v24[v26].m_Left = -1;
          v24[v26].m_Tag = 0;
          if ( v25 == -1 )
          {
            sorted.m_Root = v23;
          }
          else
          {
            v27 = v25;
            if ( leftchild )
              v24[v27].m_Left = v23;
            else
              v24[v27].m_Right = v23;
          }
          CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::InsertRebalance(
            this: &sorted,
            elem: v23);
          ++sorted.m_NumElements;
          if ( &sorted.m_Elements.m_pMemory[v26] != (UtlRBTreeNode_t<KeyValues *,int> *)-16 )
            sorted.m_Elements.m_pMemory[v26].m_Data = item;
          v55 += 16;
        }
      }
      v28 = m->entries.m_Size;
      if ( v28 > 0 )
        break;
LABEL_73:
      if ( ++i >= maps.m_Size )
        goto LABEL_74;
    }
    v55 = 0;
    parent = v28;
    while ( 1 )
    {
      v29 = (const char **)((char *)&m->entries.m_Memory.m_pMemory->bindingname + v55);
      memset(&list, 0, sizeof(list));
      vgui::Panel::LookupBoundKeys(this: v47, bindingName: *v29, (CUtlMemory<vgui::TreeNode *,int> *)&list);
      if ( list.m_Size <= 0 )
        break;
      v30 = list.m_Memory.m_pMemory;
      list.m_Size = 0;
      v31 = list.m_Memory.m_nGrowSize < 0;
      if ( list.m_Memory.m_nGrowSize >= 0 )
      {
        if ( list.m_Memory.m_pMemory != nullptr )
        {
          v32 = _g_pMemAlloc;
LABEL_67:
          v32->Free_2(this: v32, a2: v30);
          v30 = nullptr;
          list.m_Memory.m_pMemory = nullptr;
        }
LABEL_68:
        v31 = list.m_Memory.m_nGrowSize < 0;
        list.m_Memory.m_nAllocationCount = 0;
      }
LABEL_69:
      list.m_pElements = v30;
      if ( !v31 && v30 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30);
      v55 += 48;
      if ( --parent == 0 )
        goto LABEL_73;
    }
    v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v33 != nullptr )
      pPanel = (vgui::Panel *)KeyValues::KeyValues(this: v33, setName: "Item");
    else
      pPanel = nullptr;
    V_snprintf(pDest: loc, maxLen: 0x80u, pFormat: "#%s", *v29);
    ansi[0] = 0;
    v34 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: loc);
    if ( v34 != nullptr )
      g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v34, a3: ansi, a4: 256);
    else
      V_strncpy(pDest: ansi, pSrc: loc, maxLen: 256);
    KeyValues::SetString(this: (KeyValues *)pPanel, keyName: "Action", value: ansi);
    KeyValues::SetWString(this: (KeyValues *)pPanel, keyName: "Binding", value: (wchar_t *)&byte_105EEA78);
    v35 = (char *)v29[8];
    if ( v35 != nullptr )
    {
      ansi[0] = 0;
      v36 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v35);
      if ( v36 != nullptr )
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v36, a3: ansi, a4: 256);
      else
        V_strncpy(pDest: ansi, pSrc: v35, maxLen: 256);
      KeyValues::SetString(this: (KeyValues *)pPanel, keyName: "Description", value: ansi);
    }
    KeyValues::SetPtr(this: (KeyValues *)pPanel, keyName: "Unbound", value: v29);
    n = -1;
    leftchild = false;
    CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FindInsertionPosition(
      this: &sorted,
      insert: (KeyValues *const *)&pPanel,
      parent: &n,
      &leftchild);
    v37 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(
            this: &sorted,
            a2: (const char *)0xFFFFFFFF);
    v38 = sorted.m_Elements.m_pMemory;
    v39 = n;
    v40 = v37;
    sorted.m_Elements.m_pMemory[v40].m_Parent = n;
    v38[v40].m_Right = -1;
    v38[v40].m_Left = -1;
    v38[v40].m_Tag = 0;
    if ( v39 == -1 )
    {
      sorted.m_Root = v37;
    }
    else
    {
      v41 = v39;
      if ( leftchild )
        v38[v41].m_Left = v37;
      else
        v38[v41].m_Right = v37;
    }
    CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::InsertRebalance(
      this: &sorted,
      elem: v37);
    ++sorted.m_NumElements;
    if ( &sorted.m_Elements.m_pMemory[v40] != (UtlRBTreeNode_t<KeyValues *,int> *)-16 )
      sorted.m_Elements.m_pMemory[v40].m_Data = (KeyValues *)pPanel;
    v30 = list.m_Memory.m_pMemory;
    list.m_Size = 0;
    v31 = list.m_Memory.m_nGrowSize < 0;
    if ( list.m_Memory.m_nGrowSize < 0 )
      goto LABEL_69;
    if ( list.m_Memory.m_pMemory == nullptr )
      goto LABEL_68;
    v32 = _g_pMemAlloc;
    goto LABEL_67;
  }
LABEL_74:
  for ( ii = CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FirstInorder(this: &sorted);
        ii != -1;
        ii = CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::NextInorder(
               this: &sorted,
               i: ii) )
  {
    m_Data = sorted.m_Elements.m_pMemory[ii].m_Data;
    v46->m_pList->AddItem(this: v46->m_pList, a2: m_Data, a3: 0, a4: false, a5: false);
    KeyValues::deleteThis(this: m_Data);
  }
  CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::RemoveAll(this: &sorted);
  CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
  if ( maps.m_Memory.m_nGrowSize >= 0 && maps.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: maps.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10322BD0
// Name: public: vgui::CKeyBindingHelpDialog::CKeyBindingHelpDialog(class vgui::Panel __near *,class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t,enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CKeyBindingHelpDialog *__thiscall vgui::CKeyBindingHelpDialog::CKeyBindingHelpDialog(
        vgui::CKeyBindingHelpDialog *this,
        vgui::Panel *parent,
        CDragDropHelperPanel *panelToView,
        vgui::KeyBindingContextHandle_t handle,
        ButtonCode_t code,
        int modifiers)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  vgui::ListPanel *v10; // eax
  vgui::ListPanel *v11; // eax
  const char *v13; // [esp-8h] [ebp-10h]

  vgui::Frame::Frame(this, parent, panelName: "KeyBindingHelpDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::CKeyBindingHelpDialog_vtbl *)&vgui::CKeyBindingHelpDialog::`vftable';
  if ( `vgui::CKeyBindingHelpDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBindingHelpDialog::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CKeyBindingHelpDialog");
    v7->pfnClassName = vgui::CKeyBindingHelpDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::CKeyBindingHelpDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBindingHelpDialog::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CKeyBindingHelpDialog");
    v8->pfnClassName = vgui::CKeyBindingHelpDialog::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::CKeyBindingHelpDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBindingHelpDialog::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBindingHelpDialog");
    v9->pfnClassName = vgui::CKeyBindingHelpDialog::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  this->m_hPanel.m_iPanelID = -1;
  this->m_Handle = handle;
  this->m_KeyCode = code;
  this->m_Modifiers = modifiers;
  this->m_bPermanent = false;
  this->m_hKeyBindingsEditor.m_iPanelID = -1;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hPanel,
    pPanel: panelToView);
  v10 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v10 != nullptr )
    v11 = vgui::ListPanel::ListPanel(this: v10, parent: this, panelName: "KeyBindings");
  else
    v11 = nullptr;
  this->m_pList = v11;
  vgui::ListPanel::SetIgnoreDoubleClick(this: v11, state: true);
  this->m_pList->AddColumnHeader(this: this->m_pList, a2: 0, a3: "Action", a4: "#KBEditorBindingName", a5: 175, a6: 0);
  this->m_pList->AddColumnHeader(this: this->m_pList, a2: 1, a3: "Binding", a4: "#KBEditorBinding", a5: 175, a6: 0);
  this->m_pList->AddColumnHeader(
    this: this->m_pList,
    a2: 2,
    a3: "Description",
    a4: "#KBEditorDescription",
    a5: 300,
    a6: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/KeyBindingHelpDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  if ( panelToView != nullptr
    && panelToView->GetName(this: panelToView) != nullptr
    && *panelToView->GetName(this: panelToView) != 0 )
  {
    v13 = panelToView->GetName(this: panelToView);
    vgui::Frame::SetTitle(this, title: v13, surfaceTitle: true);
  }
  else
  {
    vgui::Frame::SetTitle(this, title: "#KBHelpDialogTitle", surfaceTitle: true);
  }
  vgui::Frame::SetSmallCaption(this, state: true);
  vgui::Panel::SetMinimumSize(this, wide: 400, tall: 400);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetMaximizeButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::CKeyBindingHelpDialog::PopulateList(this);
  this->m_flShowTime = g_pVGuiSystem->GetCurrentTime(this: g_pVGuiSystem);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  return this;
}
