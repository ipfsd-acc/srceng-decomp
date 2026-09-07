// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_helpers.cpp
// Functions: 7
// ============================================================

#include "engine\vgui_helpers.h"

//------------------------------------------------------------------------------
// Address: 0x1020B890
// Name: void IncrementalUpdateTree(class vgui::TreeView __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IncrementalUpdateTree(vgui::TreeView *pTree, KeyValues *pValues)
{
  bool updated; // al
  vgui::TreeView_vtbl *v3; // edi
  bool v4; // bl
  int v5; // eax

  if ( g_bForceRefresh
    || vgui_drawtree_freeze.m_pParent == nullptr
    || vgui_drawtree_freeze.m_pParent->m_Value.m_nValue == 0 )
  {
    g_bForceRefresh = false;
    updated = IncrementalUpdateTree(
                pTree,
                pValues,
                fn: (bool (__cdecl *)(vgui::TreeView *, int, KeyValues *))UpdateItemState,
                iRoot: -1);
    v3 = pTree->__vftable;
    v4 = updated;
    v5 = ((int (__thiscall *)(vgui::TreeView *, int))pTree->GetRootItemIndex)(a1: pTree, a2: 1);
    ((void (__thiscall *)(vgui::TreeView *, int))v3->ExpandItem)(a1: pTree, a2: v5);
    if ( g_pDrawTreeFrame != nullptr )
      CDrawTreeFrame::RecalculateSelectedHighlight(this: g_pDrawTreeFrame);
    if ( v4 )
      pTree->InvalidateLayout(this: pTree, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C440
// Name: public: CConVarCheckButton::CConVarCheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CConVarCheckButton *__thiscall CConVarCheckButton::CConVarCheckButton(
        CConVarCheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (CConVarCheckButton_vtbl *)&CConVarCheckButton::`vftable';
  this->m_pConVar = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020C470
// Name: public: virtual void CConVarCheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarCheckButton::SetSelected(CConVarCheckButton *this, bool state)
{
  vgui::CheckButton::SetSelected(this, state);
  this->m_pConVar->SetValue_2(this: &this->m_pConVar->IConVar, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1020C4A0
// Name: void IncrementalUpdateTree_R(class vgui::TreeView __near *,int,class KeyValues __near *,bool __near &,bool (*)(class vgui::TreeView __near *,int,class KeyValues __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl IncrementalUpdateTree_R(
        vgui::TreeView *pTree,
        int iCurTreeNode,
        KeyValues *pValues,
        bool *bChanges,
        bool (__cdecl *fn)(vgui::TreeView *, int, KeyValues *))
{
  KeyValues *FirstSubKey; // eax
  KeyValues *v7; // edi
  int v8; // eax
  int v9; // eax
  int iChildItemId; // [esp+Ch] [ebp-8h]
  int iCurChild; // [esp+10h] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+8h]

  iCurChild = 0;
  nChildren = pTree->GetNumChildren(this: pTree, a2: iCurTreeNode);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pValues);
LABEL_2:
  v7 = FirstSubKey;
  while ( iCurChild < nChildren )
  {
    if ( v7 != nullptr )
    {
LABEL_7:
      if ( KeyValues::GetString(this: v7, keyName: "Text", defaultValue: nullptr) != nullptr )
      {
        if ( iCurChild >= nChildren )
        {
          *bChanges = true;
          v8 = ((int (__stdcall *)(KeyValues *, int))pTree->AddItem)(a1: v7, a2: iCurTreeNode);
        }
        else
        {
          v8 = ((int (__stdcall *)(int, int))pTree->GetChild)(a1: iCurTreeNode, a2: iCurChild);
        }
        iChildItemId = v8;
        if ( fn(a1: pTree, a2: v8, a3: v7) )
          *bChanges = true;
        IncrementalUpdateTree_R(pTree, iCurTreeNode: iChildItemId, pValues: v7, bChanges, fn);
        ++iCurChild;
      }
      FirstSubKey = KeyValues::GetNextKey(this: v7);
      goto LABEL_2;
    }
    v9 = pTree->GetChild(this: pTree, a2: iCurTreeNode, a3: iCurChild);
    --nChildren;
    *bChanges = true;
    pTree->RemoveItem(this: pTree, a2: -v9, a3: false, a4: false);
  }
  if ( v7 != nullptr )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x1020C590
// Name: bool IncrementalUpdateTree(class vgui::TreeView __near *,class KeyValues __near *,bool (*)(class vgui::TreeView __near *,int,class KeyValues __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IncrementalUpdateTree(
        vgui::TreeView *pTree,
        KeyValues *pValues,
        bool (__cdecl *fn)(vgui::TreeView *, int, KeyValues *),
        int iRoot)
{
  int v4; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  int (__thiscall *GetNumChildren)(vgui::TreeView *, int); // edx
  KeyValues *FirstSubKey; // eax
  KeyValues *v10; // edi
  vgui::TreeView_vtbl *v12; // edx
  int v13; // eax
  int (__thiscall *AddItem)(vgui::TreeView *, KeyValues *, int); // eax
  void (__thiscall *RemoveItem)(vgui::TreeView *, int, bool, bool); // eax
  int v16; // [esp-Ch] [ebp-20h]
  int iCurTreeNode; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  vgui::TreeView *pTreea; // [esp+1Ch] [ebp+8h]

  v4 = iRoot;
  if ( iRoot == -1 )
  {
    v4 = pTree->GetRootItemIndex(this: pTree);
    if ( v4 == -1 )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: defaultValue);
      else
        v7 = nullptr;
      KeyValues::SetString(this: v7, keyName: "Text", value: defaultValue);
      v4 = pTree->AddItem(this: pTree, a2: v7, a3: -1);
      KeyValues::deleteThis(this: v7);
    }
  }
  GetNumChildren = pTree->GetNumChildren;
  HIBYTE(iRoot) = 0;
  pTreea = nullptr;
  v18 = GetNumChildren(this: pTree, a2: v4);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pValues);
LABEL_8:
  v10 = FirstSubKey;
  while ( (int)pTreea < v18 )
  {
    if ( v10 != nullptr )
    {
LABEL_13:
      if ( KeyValues::GetString(this: v10, keyName: "Text", defaultValue: nullptr) != nullptr )
      {
        v12 = pTree->__vftable;
        if ( (int)pTreea >= v18 )
        {
          AddItem = v12->AddItem;
          HIBYTE(iRoot) = 1;
          v13 = ((int (__stdcall *)(KeyValues *, int))AddItem)(a1: v10, a2: v4);
        }
        else
        {
          v13 = ((int (__stdcall *)(int, vgui::TreeView *))v12->GetChild)(a1: v4, a2: pTreea);
        }
        iCurTreeNode = v13;
        if ( fn(a1: pTree, a2: v13, a3: v10) )
          HIBYTE(iRoot) = 1;
        IncrementalUpdateTree_R(pTree, iCurTreeNode, pValues: v10, bChanges: (bool *)&iRoot + 3, fn);
        pTreea = (vgui::TreeView *)((char *)pTreea + 1);
      }
      FirstSubKey = KeyValues::GetNextKey(this: v10);
      goto LABEL_8;
    }
    --v18;
    v16 = -pTree->GetChild(this: pTree, a2: v4, a3: (int)pTreea);
    RemoveItem = pTree->RemoveItem;
    HIBYTE(iRoot) = 1;
    RemoveItem(this: pTree, a2: v16, a3: false, a4: false);
  }
  if ( v10 != nullptr )
    goto LABEL_13;
  return HIBYTE(iRoot);
}

//------------------------------------------------------------------------------
// Address: 0x1020C6E0
// Name: public: void CConVarCheckButton::SetConVar(class ConVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarCheckButton::SetConVar(CConVarCheckButton *this, ConVar *pVar)
{
  ConVar *m_pParent; // eax
  int m_nValue; // eax

  this->m_pConVar = pVar;
  m_pParent = pVar->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->SetSelected(this, a2: m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C720
// Name: void CopyListPanelToClipboard(class vgui::ListPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyListPanelToClipboard(vgui::ListPanel *pListPanel)
{
  vgui::ListPanel *v1; // ebx
  int (__thiscall *GetNumColumnHeaders)(vgui::ListPanel *); // edx
  int m_Size; // esi
  char *m_pMemory; // edi
  int v5; // ebx
  bool v6; // zf
  char *v7; // edi
  int v8; // ebx
  int v9; // esi
  char *v10; // ebx
  vgui::ListPanel *v11; // ebx
  int v12; // eax
  int v13; // ebx
  char *v14; // edi
  int v15; // ebx
  char *v16; // ebx
  int v17; // eax
  int v18; // ebx
  int v19; // esi
  char *v20; // ebx
  wchar_t tempTextWC[512]; // [esp+Ch] [ebp-620h] BYREF
  char tempText[512]; // [esp+40Ch] [ebp-220h] BYREF
  int nColumns; // [esp+60Ch] [ebp-20h]
  int j; // [esp+610h] [ebp-1Ch]
  CUtlVector<char,CUtlMemory<char,int> > textBuf; // [esp+614h] [ebp-18h] BYREF
  int i; // [esp+628h] [ebp-4h]

  v1 = pListPanel;
  GetNumColumnHeaders = pListPanel->GetNumColumnHeaders;
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&textBuf, 0, sizeof(textBuf));
  nColumns = GetNumColumnHeaders(this: pListPanel);
  for ( i = 0; i < nColumns; ++i )
  {
    if ( i != 0 )
    {
      v5 = m_Size;
      if ( m_Size + 1 > textBuf.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: m_Size - textBuf.m_Memory.m_nAllocationCount + 1);
        m_Size = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      textBuf.m_Size = ++m_Size;
      textBuf.m_pElements = m_pMemory;
      if ( m_Size - v5 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: m_Size - v5 - 1);
      v6 = &m_pMemory[v5] == nullptr;
      v7 = &m_pMemory[v5];
      v1 = pListPanel;
      if ( !v6 )
        *v7 = 9;
    }
    if ( !v1->GetColumnHeaderText(this: v1, a2: i, a3: tempText, a4: 512) )
      _Error(a1: "GetColumHeaderText( %d ) failed", i);
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: &textBuf,
      elem: m_Size,
      num: strlen(tempText),
      pToInsert: tempText);
    m_Size = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v8 = m_Size;
  if ( m_Size + 1 > textBuf.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: m_Size - textBuf.m_Memory.m_nAllocationCount + 1);
    m_Size = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v9 = m_Size + 1;
  textBuf.m_Size = v9;
  textBuf.m_pElements = m_pMemory;
  if ( v9 - v8 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: v9 - v8 - 1);
  v10 = &m_pMemory[v8];
  if ( v10 != nullptr )
    *v10 = 10;
  v11 = pListPanel;
  i = pListPanel->FirstItem(this: pListPanel);
  v12 = v11->InvalidItemID(this: v11);
  if ( i != v12 )
  {
    do
    {
      for ( j = 0; j < nColumns; ++j )
      {
        if ( j != 0 )
        {
          v13 = v9;
          if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
            v9 = textBuf.m_Size;
            m_pMemory = textBuf.m_Memory.m_pMemory;
          }
          textBuf.m_Size = ++v9;
          textBuf.m_pElements = m_pMemory;
          if ( v9 - v13 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: v9 - v13 - 1);
          v6 = &m_pMemory[v13] == nullptr;
          v14 = &m_pMemory[v13];
          v11 = pListPanel;
          if ( !v6 )
            *v14 = 9;
        }
        v11->GetCellText(this: v11, a2: i, a3: j, a4: tempTextWC, a5: 1024);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: tempTextWC, a3: tempText, a4: 512);
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: &textBuf,
          elem: v9,
          num: strlen(tempText),
          pToInsert: tempText);
        v9 = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      v15 = v9;
      if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
        v9 = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      textBuf.m_Size = ++v9;
      textBuf.m_pElements = m_pMemory;
      if ( v9 - v15 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: v9 - v15 - 1);
      v16 = &m_pMemory[v15];
      if ( v16 != nullptr )
        *v16 = 10;
      v11 = pListPanel;
      i = pListPanel->NextItem(this: pListPanel, a2: i);
      v17 = v11->InvalidItemID(this: v11);
    }
    while ( i != v17 );
  }
  v18 = v9;
  if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
    v9 = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v19 = v9 + 1;
  if ( v19 - v18 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v18 + 1], src: &m_pMemory[v18], count: v19 - v18 - 1);
  v20 = &m_pMemory[v18];
  if ( v20 != nullptr )
    *v20 = 0;
  g_pVGuiSystem->SetClipboardText_2(this: g_pVGuiSystem, a2: m_pMemory, a3: v19);
  if ( textBuf.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1020B9A0
// Name: void IncrementalUpdateTree(class vgui::TreeView __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IncrementalUpdateTree(vgui::TreeView *pTree, KeyValues *pValues)
{
  bool updated; // al
  vgui::TreeView_vtbl *v3; // edi
  bool v4; // bl
  int v5; // eax

  if ( g_bForceRefresh
    || vgui_drawtree_freeze.m_pParent == nullptr
    || vgui_drawtree_freeze.m_pParent->m_Value.m_nValue == 0 )
  {
    g_bForceRefresh = false;
    updated = IncrementalUpdateTree(
                pTree,
                pValues,
                fn: (bool (__cdecl *)(vgui::TreeView *, int, KeyValues *))UpdateItemState,
                iRoot: -1);
    v3 = pTree->__vftable;
    v4 = updated;
    v5 = ((int (__thiscall *)(vgui::TreeView *, int))pTree->GetRootItemIndex)(a1: pTree, a2: 1);
    ((void (__thiscall *)(vgui::TreeView *, int))v3->ExpandItem)(a1: pTree, a2: v5);
    if ( g_pDrawTreeFrame != nullptr )
      CDrawTreeFrame::RecalculateSelectedHighlight(this: g_pDrawTreeFrame);
    if ( v4 )
      pTree->InvalidateLayout(this: pTree, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C550
// Name: public: CConVarCheckButton::CConVarCheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CConVarCheckButton *__thiscall CConVarCheckButton::CConVarCheckButton(
        CConVarCheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (CConVarCheckButton_vtbl *)&CConVarCheckButton::`vftable';
  this->m_pConVar = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020C580
// Name: public: virtual void CConVarCheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarCheckButton::SetSelected(CConVarCheckButton *this, bool state)
{
  vgui::CheckButton::SetSelected(this, state);
  this->m_pConVar->SetValue_2(this: &this->m_pConVar->IConVar, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1020C5B0
// Name: void IncrementalUpdateTree_R(class vgui::TreeView __near *,int,class KeyValues __near *,bool __near &,bool (*)(class vgui::TreeView __near *,int,class KeyValues __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl IncrementalUpdateTree_R(
        vgui::TreeView *pTree,
        int iCurTreeNode,
        KeyValues *pValues,
        bool *bChanges,
        bool (__cdecl *fn)(vgui::TreeView *, int, KeyValues *))
{
  KeyValues *FirstSubKey; // eax
  KeyValues *v7; // edi
  int v8; // eax
  int v9; // eax
  int iChildItemId; // [esp+Ch] [ebp-8h]
  int iCurChild; // [esp+10h] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+8h]

  iCurChild = 0;
  nChildren = pTree->GetNumChildren(this: pTree, a2: iCurTreeNode);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pValues);
LABEL_2:
  v7 = FirstSubKey;
  while ( iCurChild < nChildren )
  {
    if ( v7 != nullptr )
    {
LABEL_7:
      if ( KeyValues::GetString(this: v7, keyName: "Text", defaultValue: nullptr) != nullptr )
      {
        if ( iCurChild >= nChildren )
        {
          *bChanges = true;
          v8 = ((int (__stdcall *)(KeyValues *, int))pTree->AddItem)(a1: v7, a2: iCurTreeNode);
        }
        else
        {
          v8 = ((int (__stdcall *)(int, int))pTree->GetChild)(a1: iCurTreeNode, a2: iCurChild);
        }
        iChildItemId = v8;
        if ( fn(a1: pTree, a2: v8, a3: v7) )
          *bChanges = true;
        IncrementalUpdateTree_R(pTree, iCurTreeNode: iChildItemId, pValues: v7, bChanges, fn);
        ++iCurChild;
      }
      FirstSubKey = KeyValues::GetNextKey(this: v7);
      goto LABEL_2;
    }
    v9 = pTree->GetChild(this: pTree, a2: iCurTreeNode, a3: iCurChild);
    --nChildren;
    *bChanges = true;
    pTree->RemoveItem(this: pTree, a2: -v9, a3: false, a4: false);
  }
  if ( v7 != nullptr )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x1020C6A0
// Name: bool IncrementalUpdateTree(class vgui::TreeView __near *,class KeyValues __near *,bool (*)(class vgui::TreeView __near *,int,class KeyValues __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IncrementalUpdateTree(
        vgui::TreeView *pTree,
        KeyValues *pValues,
        bool (__cdecl *fn)(vgui::TreeView *, int, KeyValues *),
        int iRoot)
{
  int v4; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  int (__thiscall *GetNumChildren)(vgui::TreeView *, int); // edx
  KeyValues *FirstSubKey; // eax
  KeyValues *v10; // edi
  vgui::TreeView_vtbl *v12; // edx
  int v13; // eax
  int (__thiscall *AddItem)(vgui::TreeView *, KeyValues *, int); // eax
  void (__thiscall *RemoveItem)(vgui::TreeView *, int, bool, bool); // eax
  int v16; // [esp-Ch] [ebp-20h]
  int iCurTreeNode; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  vgui::TreeView *pTreea; // [esp+1Ch] [ebp+8h]

  v4 = iRoot;
  if ( iRoot == -1 )
  {
    v4 = pTree->GetRootItemIndex(this: pTree);
    if ( v4 == -1 )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: defaultValue);
      else
        v7 = nullptr;
      KeyValues::SetString(this: v7, keyName: "Text", value: defaultValue);
      v4 = pTree->AddItem(this: pTree, a2: v7, a3: -1);
      KeyValues::deleteThis(this: v7);
    }
  }
  GetNumChildren = pTree->GetNumChildren;
  HIBYTE(iRoot) = 0;
  pTreea = nullptr;
  v18 = GetNumChildren(this: pTree, a2: v4);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pValues);
LABEL_8:
  v10 = FirstSubKey;
  while ( (int)pTreea < v18 )
  {
    if ( v10 != nullptr )
    {
LABEL_13:
      if ( KeyValues::GetString(this: v10, keyName: "Text", defaultValue: nullptr) != nullptr )
      {
        v12 = pTree->__vftable;
        if ( (int)pTreea >= v18 )
        {
          AddItem = v12->AddItem;
          HIBYTE(iRoot) = 1;
          v13 = ((int (__stdcall *)(KeyValues *, int))AddItem)(a1: v10, a2: v4);
        }
        else
        {
          v13 = ((int (__stdcall *)(int, vgui::TreeView *))v12->GetChild)(a1: v4, a2: pTreea);
        }
        iCurTreeNode = v13;
        if ( fn(a1: pTree, a2: v13, a3: v10) )
          HIBYTE(iRoot) = 1;
        IncrementalUpdateTree_R(pTree, iCurTreeNode, pValues: v10, bChanges: (bool *)&iRoot + 3, fn);
        pTreea = (vgui::TreeView *)((char *)pTreea + 1);
      }
      FirstSubKey = KeyValues::GetNextKey(this: v10);
      goto LABEL_8;
    }
    --v18;
    v16 = -pTree->GetChild(this: pTree, a2: v4, a3: (int)pTreea);
    RemoveItem = pTree->RemoveItem;
    HIBYTE(iRoot) = 1;
    RemoveItem(this: pTree, a2: v16, a3: false, a4: false);
  }
  if ( v10 != nullptr )
    goto LABEL_13;
  return HIBYTE(iRoot);
}

//------------------------------------------------------------------------------
// Address: 0x1020C820
// Name: public: void CConVarCheckButton::SetConVar(class ConVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarCheckButton::SetConVar(CConVarCheckButton *this, ConVar *pVar)
{
  ConVar *m_pParent; // eax
  int m_nValue; // eax

  this->m_pConVar = pVar;
  m_pParent = pVar->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->SetSelected(this, a2: m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C860
// Name: void CopyListPanelToClipboard(class vgui::ListPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyListPanelToClipboard(vgui::ListPanel *pListPanel)
{
  vgui::ListPanel *v1; // ebx
  int (__thiscall *GetNumColumnHeaders)(vgui::ListPanel *); // edx
  int m_Size; // esi
  char *m_pMemory; // edi
  int v5; // ebx
  bool v6; // zf
  char *v7; // edi
  int v8; // ebx
  int v9; // esi
  char *v10; // ebx
  vgui::ListPanel *v11; // ebx
  int v12; // eax
  int v13; // ebx
  char *v14; // edi
  int v15; // ebx
  char *v16; // ebx
  int v17; // eax
  int v18; // ebx
  int v19; // esi
  char *v20; // ebx
  wchar_t tempTextWC[512]; // [esp+Ch] [ebp-620h] BYREF
  char tempText[512]; // [esp+40Ch] [ebp-220h] BYREF
  int nColumns; // [esp+60Ch] [ebp-20h]
  int j; // [esp+610h] [ebp-1Ch]
  CUtlVector<char,CUtlMemory<char,int> > textBuf; // [esp+614h] [ebp-18h] BYREF
  int i; // [esp+628h] [ebp-4h]

  v1 = pListPanel;
  GetNumColumnHeaders = pListPanel->GetNumColumnHeaders;
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&textBuf, 0, sizeof(textBuf));
  nColumns = GetNumColumnHeaders(this: pListPanel);
  for ( i = 0; i < nColumns; ++i )
  {
    if ( i != 0 )
    {
      v5 = m_Size;
      if ( m_Size + 1 > textBuf.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: m_Size - textBuf.m_Memory.m_nAllocationCount + 1);
        m_Size = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      textBuf.m_Size = ++m_Size;
      textBuf.m_pElements = m_pMemory;
      if ( m_Size - v5 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: m_Size - v5 - 1);
      v6 = &m_pMemory[v5] == nullptr;
      v7 = &m_pMemory[v5];
      v1 = pListPanel;
      if ( !v6 )
        *v7 = 9;
    }
    if ( !v1->GetColumnHeaderText(this: v1, a2: i, a3: tempText, a4: 512) )
      _Error(a1: "GetColumHeaderText( %d ) failed", i);
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: &textBuf,
      elem: m_Size,
      num: strlen(tempText),
      pToInsert: tempText);
    m_Size = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v8 = m_Size;
  if ( m_Size + 1 > textBuf.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: m_Size - textBuf.m_Memory.m_nAllocationCount + 1);
    m_Size = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v9 = m_Size + 1;
  textBuf.m_Size = v9;
  textBuf.m_pElements = m_pMemory;
  if ( v9 - v8 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: v9 - v8 - 1);
  v10 = &m_pMemory[v8];
  if ( v10 != nullptr )
    *v10 = 10;
  v11 = pListPanel;
  i = pListPanel->FirstItem(this: pListPanel);
  v12 = v11->InvalidItemID(this: v11);
  if ( i != v12 )
  {
    do
    {
      for ( j = 0; j < nColumns; ++j )
      {
        if ( j != 0 )
        {
          v13 = v9;
          if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
            v9 = textBuf.m_Size;
            m_pMemory = textBuf.m_Memory.m_pMemory;
          }
          textBuf.m_Size = ++v9;
          textBuf.m_pElements = m_pMemory;
          if ( v9 - v13 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: v9 - v13 - 1);
          v6 = &m_pMemory[v13] == nullptr;
          v14 = &m_pMemory[v13];
          v11 = pListPanel;
          if ( !v6 )
            *v14 = 9;
        }
        v11->GetCellText(this: v11, a2: i, a3: j, a4: tempTextWC, a5: 1024);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: tempTextWC, a3: tempText, a4: 512);
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: &textBuf,
          elem: v9,
          num: strlen(tempText),
          pToInsert: tempText);
        v9 = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      v15 = v9;
      if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
        v9 = textBuf.m_Size;
        m_pMemory = textBuf.m_Memory.m_pMemory;
      }
      textBuf.m_Size = ++v9;
      textBuf.m_pElements = m_pMemory;
      if ( v9 - v15 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: v9 - v15 - 1);
      v16 = &m_pMemory[v15];
      if ( v16 != nullptr )
        *v16 = 10;
      v11 = pListPanel;
      i = pListPanel->NextItem(this: pListPanel, a2: i);
      v17 = v11->InvalidItemID(this: v11);
    }
    while ( i != v17 );
  }
  v18 = v9;
  if ( v9 + 1 > textBuf.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &textBuf.m_Memory, num: v9 - textBuf.m_Memory.m_nAllocationCount + 1);
    v9 = textBuf.m_Size;
    m_pMemory = textBuf.m_Memory.m_pMemory;
  }
  v19 = v9 + 1;
  if ( v19 - v18 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v18 + 1], src: &m_pMemory[v18], count: v19 - v18 - 1);
  v20 = &m_pMemory[v18];
  if ( v20 != nullptr )
    *v20 = 0;
  g_pVGuiSystem->SetClipboardText_2(this: g_pVGuiSystem, a2: m_pMemory, a3: v19);
  if ( textBuf.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10319750
// Name: _dynamic_initializer_for__help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__help_command__()
{
  ConCommand::ConCommand(
    this: &help_command,
    pName: "help",
    callback: help,
    pHelpString: "Find help about a convar/concommand.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__help_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324F80
// Name: _dynamic_atexit_destructor_for__help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__help_command__()
{
  ConCommand::~ConCommand(this: &help_command);
}

//------------------------------------------------------------------------------
// Address: 0x10319780
// Name: _dynamic_initializer_for__differences_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__differences_command__()
{
  ConCommand::ConCommand(
    this: &differences_command,
    pName: "differences",
    callback: differences,
    pHelpString: "Show all convars which are not at their default values.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__differences_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324F90
// Name: _dynamic_atexit_destructor_for__differences_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__differences_command__()
{
  ConCommand::~ConCommand(this: &differences_command);
}

} // namespace engine_xlsp
