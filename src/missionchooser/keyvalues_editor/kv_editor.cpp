// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_editor.cpp
// Functions: 20
// ============================================================

#include "missionchooser\keyvalues_editor\kv_editor.h"

//------------------------------------------------------------------------------
// Address: 0x1000CFE0
// Name: public: static char const __near * CKV_Editor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Editor::GetPanelClassName()
{
  return "CKV_Editor";
}

//------------------------------------------------------------------------------
// Address: 0x1000CFF0
// Name: public: virtual void CKV_Editor::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::PerformLayout(CKV_Editor *this)
{
  int Wide; // eax
  int Tall; // [esp-4h] [ebp-8h]

  vgui::EditablePanel::PerformLayout(this);
  Tall = vgui::Panel::GetTall(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pScrollingWindow, x: 0, y: 0, wide: Wide, tall: Tall);
}

//------------------------------------------------------------------------------
// Address: 0x1000D020
// Name: protected: class KeyValues __near * CKV_Editor::FindParentForKey(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindParentForKey(CKV_Editor *this, KeyValues *pRoot, KeyValues *pSearchChild)
{
  KeyValues *FirstSubKey; // eax
  KeyValues *NextKey; // esi
  KeyValues *result; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pRoot);
  if ( FirstSubKey != nullptr )
  {
    while ( FirstSubKey != pSearchChild )
    {
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_4;
    }
    return pRoot;
  }
  else
  {
LABEL_4:
    NextKey = KeyValues::GetFirstSubKey(this: pRoot);
    if ( NextKey != nullptr )
    {
      while ( 1 )
      {
        result = CKV_Editor::FindParentForKey(this, pRoot: NextKey, pSearchChild);
        if ( result != nullptr )
          break;
        NextKey = KeyValues::GetNextKey(this: NextKey);
        if ( NextKey == nullptr )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D090
// Name: public: virtual void CKV_Editor::SetFileSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileSpec(CKV_Editor *this, const char *szFilename, const char *szPathID)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "FileSpec");
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v6,
         resourceName: szFilename,
         pathID: szPathID,
         pfnEvaluateSymbolProc: nullptr) )
  {
    this->SetFileSpec(this, a2: v5);
  }
  else
  {
    _Warning(a1: "Failed to load file spec %s\n", szFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D110
// Name: public: void CKV_Editor::SetFileFilter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileFilter(CKV_Editor *this, const char *szFilter, const char *szFilterName)
{
  V_snprintf(pDest: this->m_szFileFilter, maxLen: 32, pFormat: szFilter);
  V_snprintf(pDest: this->m_szFileFilterName, maxLen: 32, pFormat: szFilterName);
}

//------------------------------------------------------------------------------
// Address: 0x1000D150
// Name: public: void CKV_Editor::SetFileDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileDirectory(CKV_Editor *this, const char *szDirName)
{
  V_snprintf(pDest: this->m_szFileDirectory, maxLen: 260, pFormat: szDirName);
}

//------------------------------------------------------------------------------
// Address: 0x1000D170
// Name: public: virtual void CKV_Editor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::ApplySchemeSettings(CKV_Editor *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CKV_Fit_Children_Panel *, int))this->m_pContainer->SetBgColor)(
    a1: this->m_pContainer,
    a2: -16777216);
}

//------------------------------------------------------------------------------
// Address: 0x1000D1A0
// Name: protected: class KeyValues __near * CKV_Editor::FindParentForKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindParentForKey(CKV_Editor *this, KeyValues *pSearchChild)
{
  KeyValues *m_pKeys; // edi
  KeyValues *FirstSubKey; // eax
  KeyValues *i; // esi
  KeyValues *result; // eax

  m_pKeys = this->m_pKeys;
  if ( m_pKeys != nullptr )
  {
    while ( m_pKeys != pSearchChild )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: m_pKeys);
      if ( FirstSubKey != nullptr )
      {
        while ( FirstSubKey != pSearchChild )
        {
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
            goto LABEL_6;
        }
        return m_pKeys;
      }
LABEL_6:
      for ( i = KeyValues::GetFirstSubKey(this: m_pKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        result = CKV_Editor::FindParentForKey(this, pRoot: i, pSearchChild);
        if ( result != nullptr )
          return result;
      }
      m_pKeys = KeyValues::GetNextKey(this: m_pKeys);
      if ( m_pKeys == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000D220
// Name: protected: void CKV_Editor::DeleteAllPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::DeleteAllPanels(CKV_Editor *this)
{
  int i; // edi
  CKV_Editor_Base_Panel *v3; // ecx
  CKV_Editor_Base_Panel *v4; // ecx
  CKV_Editor_Base_Panel *v5; // ecx
  vgui::Panel *v6; // eax
  CKV_Fit_Children_Panel *v7; // eax
  bool v8; // sf
  CKV_Editor_Base_Panel **m_pMemory; // ecx

  for ( i = 0; i < this->m_Panels.m_Size; ++i )
  {
    v3 = this->m_Panels.m_Memory.m_pMemory[i];
    v3->SetVisible(this: v3, a2: false);
    v4 = this->m_Panels.m_Memory.m_pMemory[i];
    v4->MarkForDeletion(this: v4);
    v5 = this->m_Panels.m_Memory.m_pMemory[i];
    v6 = v5->GetParent(this: v5);
    v7 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                     inptr: v6,
                                     VfDelta: 0,
                                     SrcType: &vgui::Panel `RTTI Type Descriptor',
                                     TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                     isReference: 0);
    if ( v7 != nullptr )
      CKV_Fit_Children_Panel::RemoveAutoPositionPanel(this: v7, pPanel: this->m_Panels.m_Memory.m_pMemory[i]);
  }
  v8 = this->m_Panels.m_Memory.m_nGrowSize < 0;
  this->m_Panels.m_Size = 0;
  if ( v8 )
  {
    this->m_Panels.m_pElements = this->m_Panels.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Panels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Panels.m_Memory.m_pMemory);
      this->m_Panels.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Panels.m_Memory.m_pMemory;
    this->m_Panels.m_Memory.m_nAllocationCount = 0;
    this->m_Panels.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D300
// Name: public: CKV_Editor::CKV_Editor(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor *__thiscall CKV_Editor::CKV_Editor(CKV_Editor *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CScrollingWindow *v7; // eax
  CScrollingWindow *v8; // eax
  CKV_Fit_Children_Panel *v9; // eax
  CKV_Fit_Children_Panel *v10; // eax
  CScrollingWindow *m_pScrollingWindow; // ecx

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CKV_Editor_vtbl *)&CKV_Editor::`vftable';
  if ( `CKV_Editor::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor");
    v4->pfnClassName = CKV_Editor::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Editor::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Editor");
    v5->pfnClassName = CKV_Editor::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor");
    v6->pfnClassName = CKV_Editor::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_Panels.m_Memory.m_pMemory = nullptr;
  this->m_Panels.m_Memory.m_nAllocationCount = 0;
  this->m_Panels.m_Memory.m_nGrowSize = 0;
  this->m_Panels.m_Size = 0;
  this->m_Panels.m_pElements = nullptr;
  this->m_pKeys = nullptr;
  this->m_pFileSpec = nullptr;
  *(_WORD *)&this->m_bRequireFileSpec = 257;
  v7 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v7 != nullptr )
    v8 = CScrollingWindow::CScrollingWindow(this: v7, parent: this, name: "ScrollingWindow");
  else
    v8 = nullptr;
  this->m_pScrollingWindow = v8;
  v9 = (CKV_Fit_Children_Panel *)operator new(nSize: 0x1CCu);
  if ( v9 != nullptr )
    v10 = CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(this: v9, parent: this, name: "Container");
  else
    v10 = nullptr;
  m_pScrollingWindow = this->m_pScrollingWindow;
  this->m_pContainer = v10;
  CScrollingWindow::SetChildPanel(this: m_pScrollingWindow, pPanel: v10);
  this->m_pScrollingWindow->InvalidateLayout(this: this->m_pScrollingWindow, a2: true, a3: false);
  this->m_szFileDirectory[0] = 0;
  this->m_szFileFilter[0] = 0;
  this->m_szFileFilterName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D480
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Editor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Editor::GetMessageMap(CKV_Editor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Editor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor::GetMessageMap'::`2'::s_pMap;
  `CKV_Editor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor");
  `CKV_Editor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4B0
// Name: public: virtual struct PanelAnimationMap __near * CKV_Editor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Editor::GetAnimMap(CKV_Editor *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Editor");
}

//------------------------------------------------------------------------------
// Address: 0x1000D4C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Editor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Editor::GetKBMap(CKV_Editor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Editor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor::GetKBMap'::`2'::s_pMap;
  `CKV_Editor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor");
  `CKV_Editor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4F0
// Name: protected: class CKV_Editor_Base_Panel __near * CKV_Editor::CreatePanel(char const __near *,class CKV_Editor_Base_Panel __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor_Base_Panel *__thiscall CKV_Editor::CreatePanel(
        CKV_Editor *this,
        const char *szClassName,
        CKV_Editor_Base_Panel *pParent,
        KeyValues *pFileSpecNode,
        KeyValues *pKey)
{
  vgui::Panel *v6; // eax
  CKV_Editor_Base_Panel *v7; // esi
  const char *Name; // eax
  KeyValues *ParentForKey; // eax
  CKV_Fit_Children_Panel *v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  int v14; // eax
  CKV_Editor_Base_Panel **v15; // ebx
  CKV_Editor_Base_Panel *result; // eax

  v6 = this->CreateControlByName(this, a2: szClassName);
  v7 = (CKV_Editor_Base_Panel *)__RTDynamicCast(
                                  inptr: v6,
                                  VfDelta: 0,
                                  SrcType: &vgui::Panel `RTTI Type Descriptor',
                                  TargetType: &CKV_Editor_Base_Panel `RTTI Type Descriptor',
                                  isReference: 0);
  if ( v7 != nullptr )
  {
    v7->SetParent_2(this: v7, a2: pParent);
    v7->m_bAllowDeletion = this->m_bAllowDeletion;
    CKV_Editor_Base_Panel::SetFileSpecNode(this: v7, pKey: pFileSpecNode);
    v7->m_pEditor = this;
    Name = KeyValues::GetName(this: pKey);
    vgui::Panel::SetName(this: v7, panelName: Name);
    CKV_Editor_Base_Panel::SetKey(this: v7, pKey);
    ParentForKey = CKV_Editor::FindParentForKey(this, pSearchChild: pKey);
    CKV_Editor_Base_Panel::SetKeyParent(this: v7, pKey: ParentForKey);
    v7->m_flSortOrder = KeyValues::GetFloat(this: pFileSpecNode, keyName: "SortOrder", defaultValue: 0.0);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v10 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                      inptr: pParent,
                                      VfDelta: 0,
                                      SrcType: &CKV_Editor_Base_Panel `RTTI Type Descriptor',
                                      TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                      isReference: 0);
    if ( v10 != nullptr )
      CKV_Fit_Children_Panel::AddAutoPositionPanel(this: v10, pPanel: v7);
    m_Size = this->m_Panels.m_Size;
    m_nAllocationCount = this->m_Panels.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Panels,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Panels.m_Size;
    m_pMemory = this->m_Panels.m_Memory.m_pMemory;
    v14 = this->m_Panels.m_Size - m_Size - 1;
    this->m_Panels.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
    v15 = &this->m_Panels.m_Memory.m_pMemory[m_Size];
    result = v7;
    if ( v15 != nullptr )
      *v15 = v7;
  }
  else
  {
    _Warning(a1: "Failed to create panel %s\n", szClassName);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D660
// Name: protected: class KeyValues __near * CKV_Editor::FindFileSpecNodeForKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindFileSpecNodeForKey(CKV_Editor *this, KeyValues *pKey)
{
  KeyValues *result; // eax
  KeyValues *ParentForKey; // esi
  KeyValues **m_pMemory; // edi
  int m_Size; // ebx
  KeyValues *m_pFileSpec; // esi
  const char *String; // edi
  const char *Name; // eax
  const char *v9; // eax
  const char *v10; // eax
  KeyValues *NextKey; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > chain; // [esp+0h] [ebp-18h] BYREF
  CKV_Editor *v13; // [esp+14h] [ebp-4h]
  int iCurrentDepth; // [esp+20h] [ebp+8h]

  result = nullptr;
  v13 = this;
  if ( this->m_pFileSpec != nullptr )
  {
    ParentForKey = pKey;
    m_pMemory = nullptr;
    m_Size = 0;
    memset(&chain, 0, sizeof(chain));
    if ( pKey != nullptr )
    {
      while ( 1 )
      {
        if ( m_Size + 1 > (int)result )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&chain,
            num: m_Size - (_DWORD)result + 1);
          m_Size = chain.m_Size;
          m_pMemory = chain.m_Memory.m_pMemory;
        }
        chain.m_Size = ++m_Size;
        chain.m_pElements = m_pMemory;
        if ( m_Size - 1 > 0 )
          _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * (m_Size - 1));
        if ( m_pMemory != nullptr )
          *m_pMemory = ParentForKey;
        ParentForKey = CKV_Editor::FindParentForKey(this: v13, pSearchChild: ParentForKey);
        if ( ParentForKey == nullptr )
          break;
        result = (KeyValues *)chain.m_Memory.m_nAllocationCount;
      }
    }
    m_pFileSpec = v13->m_pFileSpec;
    iCurrentDepth = 0;
    if ( m_pFileSpec == nullptr )
    {
LABEL_22:
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&chain);
      return nullptr;
    }
    while ( 1 )
    {
      String = "_unnamed_node";
      Name = KeyValues::GetName(this: m_pFileSpec);
      if ( _V_stricmp(s1: Name, s2: "_Node") == 0
        || (v9 = KeyValues::GetName(this: m_pFileSpec), _V_stricmp(s1: v9, s2: "_Leaf") == 0) )
      {
        String = KeyValues::GetString(this: m_pFileSpec, keyName: "Name", defaultValue: "_unnamed_node");
      }
      v10 = KeyValues::GetName(this: chain.m_Memory.m_pMemory[iCurrentDepth]);
      if ( _V_stricmp(s1: String, s2: v10) != 0 && _V_stricmp(s1: String, s2: "*") != 0 )
      {
        NextKey = KeyValues::GetNextKey(this: m_pFileSpec);
      }
      else
      {
        if ( ++iCurrentDepth >= m_Size )
        {
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&chain);
          return m_pFileSpec;
        }
        NextKey = KeyValues::GetFirstSubKey(this: m_pFileSpec);
      }
      m_pFileSpec = NextKey;
      if ( NextKey == nullptr )
        goto LABEL_22;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7D0
// Name: public: virtual void CKV_Editor::AddToKey(class KeyValues __near *,class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::AddToKey(
        CKV_Editor *this,
        KeyValues *pFileSpecNode,
        KeyValues *pKey,
        const char *szNewKeyName)
{
  CKV_Editor *v4; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  bool v7; // bl
  const char *v8; // eax
  int v9; // eax
  const char *String; // eax
  bool v11; // zf
  const char *v12; // eax
  bool v13; // bl
  KeyValues *v14; // edi
  const char *v15; // eax
  KeyValues *v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  KeyValues *v19; // edi
  const char *v20; // eax
  KeyValues *v21; // edi
  const char *v22; // eax
  KeyValues *FileSpecNodeForKey; // eax
  bool bLeaf_3; // [esp+17h] [ebp+Bh]

  v4 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pFileSpecNode);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      v7 = _V_stricmp(s1: Name, s2: "_Node") == 0;
      v8 = KeyValues::GetName(this: FirstSubKey);
      v9 = _V_stricmp(s1: v8, s2: "_Leaf");
      bLeaf_3 = v9 == 0;
      if ( v9 == 0 || v7 )
      {
        if ( szNewKeyName != nullptr )
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
          v11 = _V_stricmp(s1: String, s2: szNewKeyName) == 0;
        }
        else
        {
          v11 = KeyValues::GetInt(this: FirstSubKey, keyName: "Autocreate", defaultValue: 0) == 1;
        }
        if ( v11 )
        {
          if ( bLeaf_3 )
          {
            v12 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
            v13 = KeyValues::FindKey(this: pKey, keyName: v12, bCreate: false) != nullptr;
            if ( KeyValues::GetInt(this: FirstSubKey, keyName: "Unique", defaultValue: 0) != 1 || !v13 )
            {
              v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v14 != nullptr )
              {
                v15 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
                v16 = KeyValues::KeyValues(this: v14, setName: v15);
              }
              else
              {
                v16 = nullptr;
              }
              v17 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
              _Msg(a1: "Added leaf %s\n", v17);
              v18 = KeyValues::GetString(this: FirstSubKey, keyName: "DefaultValue", defaultValue: szDescription);
              KeyValues::SetStringValue(this: v16, strValue: v18);
              KeyValues::AddSubKey(this: pKey, pSubkey: v16);
            }
          }
          else
          {
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
            {
              v20 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
              v21 = KeyValues::KeyValues(this: v19, setName: v20);
            }
            else
            {
              v21 = nullptr;
            }
            v22 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: szDescription);
            _Msg(a1: "Added node %s\n", v22);
            KeyValues::AddSubKey(this: pKey, pSubkey: v21);
            FileSpecNodeForKey = CKV_Editor::FindFileSpecNodeForKey(this, pKey: v21);
            if ( FileSpecNodeForKey != nullptr )
              this->AddToKey(this, a2: FileSpecNodeForKey, a3: v21, a4: nullptr);
          }
        }
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    v4 = this;
  }
  v4->OnKeyAdded(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1000DA10
// Name: protected: void CKV_Editor::UpdatePanels(class KeyValues __near *,class CKV_Editor_Base_Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::UpdatePanels(
        CKV_Editor *this,
        KeyValues *pKV,
        CKV_Editor_Base_Panel *pParentPanel,
        bool bIncludeSiblings)
{
  KeyValues *NextKey; // edi
  CKV_Editor *v5; // ebx
  int m_Size; // edx
  int v7; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  CKV_Editor_Base_Panel *Panel; // esi
  KeyValues *FileSpecNodeForKey; // eax
  const char *String; // ebx
  const char *v12; // eax
  vgui::Panel *v13; // eax
  CKV_Fit_Children_Panel *v14; // eax
  KeyValues *ParentForKey; // eax
  KeyValues *FirstSubKey; // eax
  const char *Name; // eax
  const char *v18; // [esp-4h] [ebp-14h]
  KeyValues *pFileSpecNode; // [esp+18h] [ebp+8h]

  NextKey = pKV;
  v5 = this;
  if ( pKV == nullptr )
    goto LABEL_28;
  while ( 1 )
  {
    m_Size = v5->m_Panels.m_Size;
    v7 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      Panel = nullptr;
    }
    else
    {
      m_pMemory = v5->m_Panels.m_Memory.m_pMemory;
      while ( (*m_pMemory)->m_pKey != NextKey )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_6;
      }
      Panel = v5->m_Panels.m_Memory.m_pMemory[v7];
    }
    FileSpecNodeForKey = CKV_Editor::FindFileSpecNodeForKey(this: v5, pKey: NextKey);
    pFileSpecNode = FileSpecNodeForKey;
    if ( FileSpecNodeForKey != nullptr )
    {
      String = KeyValues::GetString(this: FileSpecNodeForKey, keyName: "Panel", defaultValue: "CKV_Node_Panel");
    }
    else
    {
      if ( v5->m_bRequireFileSpec )
      {
        v18 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: szDescription);
        Name = KeyValues::GetName(this: NextKey);
        _Warning(a1: "Key %s:%s has no FileSpecNode!\n", Name, v18);
        return;
      }
      if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
        String = "CKV_Node_Panel";
      else
        String = "CKV_Leaf_Panel";
    }
    if ( Panel == nullptr )
      goto LABEL_15;
    v12 = Panel->GetClassName(this: Panel);
    if ( _V_stricmp(s1: v12, s2: String) != 0 )
    {
      Panel->SetVisible(this: Panel, a2: false);
      Panel->MarkForDeletion(this: Panel);
      v13 = Panel->GetParent(this: Panel);
      v14 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                        inptr: v13,
                                        VfDelta: 0,
                                        SrcType: &vgui::Panel `RTTI Type Descriptor',
                                        TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                        isReference: 0);
      if ( v14 != nullptr )
        CKV_Fit_Children_Panel::RemoveAutoPositionPanel(this: v14, pPanel: Panel);
LABEL_15:
      Panel = CKV_Editor::CreatePanel(this, szClassName: String, pParent: pParentPanel, pFileSpecNode, pKey: NextKey);
      goto LABEL_21;
    }
    CKV_Editor_Base_Panel::SetKey(this: Panel, pKey: NextKey);
    ParentForKey = CKV_Editor::FindParentForKey(this, pSearchChild: NextKey);
    CKV_Editor_Base_Panel::SetKeyParent(this: Panel, pKey: ParentForKey);
LABEL_21:
    if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: NextKey);
      CKV_Editor::UpdatePanels(this, pKV: FirstSubKey, pParentPanel: Panel, bIncludeSiblings: true);
    }
    if ( !bIncludeSiblings )
      break;
    v5 = this;
    NextKey = KeyValues::GetNextKey(this: NextKey);
    if ( NextKey == nullptr )
      goto LABEL_28;
  }
  v5 = this;
LABEL_28:
  v5->m_pContainer->InvalidateLayout(this: v5->m_pContainer, a2: true, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000DBE0
// Name: public: virtual void CKV_Editor::SetFileSpec(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileSpec(CKV_Editor *this, KeyValues *pKeys)
{
  this->m_pFileSpec = pKeys;
  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC20
// Name: public: virtual void CKV_Editor::SetKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetKeys(CKV_Editor *this, KeyValues *pKeys)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->m_pKeys = pKeys;
  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DCA0
// Name: public: virtual void CKV_Editor::OnKeyDeleted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::OnKeyDeleted(CKV_Editor *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00406ED0
// Name: public: static char const __near * CKV_Editor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Editor::GetPanelClassName()
{
  return "CKV_Editor";
}

//------------------------------------------------------------------------------
// Address: 0x00406EE0
// Name: public: virtual void CKV_Editor::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::PerformLayout(CKV_Editor *this)
{
  int Wide; // eax
  int Tall; // [esp-4h] [ebp-8h]

  vgui::EditablePanel::PerformLayout(this);
  Tall = vgui::Panel::GetTall(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pScrollingWindow, x: 0, y: 0, wide: Wide, tall: Tall);
}

//------------------------------------------------------------------------------
// Address: 0x00406F10
// Name: protected: class KeyValues __near * CKV_Editor::FindParentForKey(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindParentForKey(CKV_Editor *this, KeyValues *pRoot, KeyValues *pSearchChild)
{
  KeyValues *FirstSubKey; // eax
  KeyValues *NextKey; // esi
  KeyValues *result; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pRoot);
  if ( FirstSubKey != nullptr )
  {
    while ( FirstSubKey != pSearchChild )
    {
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_4;
    }
    return pRoot;
  }
  else
  {
LABEL_4:
    NextKey = KeyValues::GetFirstSubKey(this: pRoot);
    if ( NextKey != nullptr )
    {
      while ( 1 )
      {
        result = CKV_Editor::FindParentForKey(this, pRoot: NextKey, pSearchChild);
        if ( result != nullptr )
          break;
        NextKey = KeyValues::GetNextKey(this: NextKey);
        if ( NextKey == nullptr )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406F80
// Name: public: virtual void CKV_Editor::SetFileSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileSpec(CKV_Editor *this, const char *szFilename, const char *szPathID)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "FileSpec");
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v6,
         resourceName: szFilename,
         pathID: szPathID,
         pfnEvaluateSymbolProc: nullptr) )
  {
    this->SetFileSpec(this, a2: v5);
  }
  else
  {
    _Warning(a1: "Failed to load file spec %s\n", szFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407000
// Name: public: virtual void CKV_Editor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::ApplySchemeSettings(CKV_Editor *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CKV_Fit_Children_Panel *, int))this->m_pContainer->SetBgColor)(
    a1: this->m_pContainer,
    a2: -16777216);
}

//------------------------------------------------------------------------------
// Address: 0x00407030
// Name: protected: class KeyValues __near * CKV_Editor::FindParentForKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindParentForKey(CKV_Editor *this, KeyValues *pSearchChild)
{
  KeyValues *m_pKeys; // edi
  KeyValues *FirstSubKey; // eax
  KeyValues *i; // esi
  KeyValues *result; // eax

  m_pKeys = this->m_pKeys;
  if ( m_pKeys != nullptr )
  {
    while ( m_pKeys != pSearchChild )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: m_pKeys);
      if ( FirstSubKey != nullptr )
      {
        while ( FirstSubKey != pSearchChild )
        {
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
            goto LABEL_6;
        }
        return m_pKeys;
      }
LABEL_6:
      for ( i = KeyValues::GetFirstSubKey(this: m_pKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        result = CKV_Editor::FindParentForKey(this, pRoot: i, pSearchChild);
        if ( result != nullptr )
          return result;
      }
      m_pKeys = KeyValues::GetNextKey(this: m_pKeys);
      if ( m_pKeys == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004070B0
// Name: protected: void CKV_Editor::DeleteAllPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::DeleteAllPanels(CKV_Editor *this)
{
  int i; // edi
  CKV_Editor_Base_Panel *v3; // ecx
  CKV_Editor_Base_Panel *v4; // ecx
  CKV_Editor_Base_Panel *v5; // ecx
  vgui::Panel *v6; // eax
  CKV_Fit_Children_Panel *v7; // eax
  bool v8; // sf
  CKV_Editor_Base_Panel **m_pMemory; // ecx

  for ( i = 0; i < this->m_Panels.m_Size; ++i )
  {
    v3 = this->m_Panels.m_Memory.m_pMemory[i];
    v3->SetVisible(this: v3, a2: false);
    v4 = this->m_Panels.m_Memory.m_pMemory[i];
    v4->MarkForDeletion(this: v4);
    v5 = this->m_Panels.m_Memory.m_pMemory[i];
    v6 = v5->GetParent(this: v5);
    v7 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                     inptr: v6,
                                     VfDelta: 0,
                                     SrcType: &vgui::Panel `RTTI Type Descriptor',
                                     TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                     isReference: 0);
    if ( v7 != nullptr )
      CKV_Fit_Children_Panel::RemoveAutoPositionPanel(this: v7, pPanel: this->m_Panels.m_Memory.m_pMemory[i]);
  }
  v8 = this->m_Panels.m_Memory.m_nGrowSize < 0;
  this->m_Panels.m_Size = 0;
  if ( v8 )
  {
    this->m_Panels.m_pElements = this->m_Panels.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Panels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Panels.m_Memory.m_pMemory);
      this->m_Panels.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Panels.m_Memory.m_pMemory;
    this->m_Panels.m_Memory.m_nAllocationCount = 0;
    this->m_Panels.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407190
// Name: public: CKV_Editor::CKV_Editor(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor *__thiscall CKV_Editor::CKV_Editor(CKV_Editor *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CScrollingWindow *v7; // eax
  CScrollingWindow *v8; // eax
  CKV_Fit_Children_Panel *v9; // eax
  CKV_Fit_Children_Panel *v10; // eax
  CScrollingWindow *m_pScrollingWindow; // ecx

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CKV_Editor_vtbl *)&CKV_Editor::`vftable';
  if ( `CKV_Editor::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor");
    v4->pfnClassName = CKV_Editor::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Editor::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Editor");
    v5->pfnClassName = CKV_Editor::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor");
    v6->pfnClassName = CKV_Editor::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_Panels.m_Memory.m_pMemory = nullptr;
  this->m_Panels.m_Memory.m_nAllocationCount = 0;
  this->m_Panels.m_Memory.m_nGrowSize = 0;
  this->m_Panels.m_Size = 0;
  this->m_Panels.m_pElements = nullptr;
  this->m_pKeys = nullptr;
  this->m_pFileSpec = nullptr;
  *(_WORD *)&this->m_bRequireFileSpec = 257;
  v7 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v7 != nullptr )
    v8 = CScrollingWindow::CScrollingWindow(this: v7, parent: this, name: "ScrollingWindow");
  else
    v8 = nullptr;
  this->m_pScrollingWindow = v8;
  v9 = (CKV_Fit_Children_Panel *)operator new(nSize: 0x1CCu);
  if ( v9 != nullptr )
    v10 = CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(this: v9, parent: this, name: "Container");
  else
    v10 = nullptr;
  m_pScrollingWindow = this->m_pScrollingWindow;
  this->m_pContainer = v10;
  CScrollingWindow::SetChildPanel(this: m_pScrollingWindow, pPanel: v10);
  this->m_pScrollingWindow->InvalidateLayout(this: this->m_pScrollingWindow, a2: true, a3: false);
  this->m_szFileDirectory[0] = 0;
  this->m_szFileFilter[0] = 0;
  this->m_szFileFilterName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407310
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Editor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Editor::GetMessageMap(CKV_Editor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Editor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor::GetMessageMap'::`2'::s_pMap;
  `CKV_Editor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor");
  `CKV_Editor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407340
// Name: public: virtual struct PanelAnimationMap __near * CKV_Editor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Editor::GetAnimMap(CKV_Editor *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Editor");
}

//------------------------------------------------------------------------------
// Address: 0x00407350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Editor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Editor::GetKBMap(CKV_Editor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Editor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor::GetKBMap'::`2'::s_pMap;
  `CKV_Editor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor");
  `CKV_Editor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407380
// Name: protected: class CKV_Editor_Base_Panel __near * CKV_Editor::CreatePanel(char const __near *,class CKV_Editor_Base_Panel __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor_Base_Panel *__thiscall CKV_Editor::CreatePanel(
        CKV_Editor *this,
        const char *szClassName,
        CKV_Editor_Base_Panel *pParent,
        KeyValues *pFileSpecNode,
        KeyValues *pKey)
{
  vgui::Panel *v6; // eax
  CKV_Editor_Base_Panel *v7; // esi
  const char *Name; // eax
  KeyValues *ParentForKey; // eax
  CKV_Fit_Children_Panel *v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  int v14; // eax
  CKV_Editor_Base_Panel **v15; // ebx
  CKV_Editor_Base_Panel *result; // eax

  v6 = this->CreateControlByName(this, a2: szClassName);
  v7 = (CKV_Editor_Base_Panel *)__RTDynamicCast(
                                  inptr: v6,
                                  VfDelta: 0,
                                  SrcType: &vgui::Panel `RTTI Type Descriptor',
                                  TargetType: &CKV_Editor_Base_Panel `RTTI Type Descriptor',
                                  isReference: 0);
  if ( v7 != nullptr )
  {
    v7->SetParent_2(this: v7, a2: pParent);
    v7->m_bAllowDeletion = this->m_bAllowDeletion;
    CKV_Editor_Base_Panel::SetFileSpecNode(this: v7, pKey: pFileSpecNode);
    v7->m_pEditor = this;
    Name = KeyValues::GetName(this: pKey);
    vgui::Panel::SetName(this: v7, panelName: Name);
    CKV_Editor_Base_Panel::SetKey(this: v7, pKey);
    ParentForKey = CKV_Editor::FindParentForKey(this, pSearchChild: pKey);
    CKV_Editor_Base_Panel::SetKeyParent(this: v7, pKey: ParentForKey);
    v7->m_flSortOrder = KeyValues::GetFloat(this: pFileSpecNode, keyName: "SortOrder", defaultValue: 0.0);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v10 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                      inptr: pParent,
                                      VfDelta: 0,
                                      SrcType: &CKV_Editor_Base_Panel `RTTI Type Descriptor',
                                      TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                      isReference: 0);
    if ( v10 != nullptr )
      CKV_Fit_Children_Panel::AddAutoPositionPanel(this: v10, pPanel: v7);
    m_Size = this->m_Panels.m_Size;
    m_nAllocationCount = this->m_Panels.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Panels,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Panels.m_Size;
    m_pMemory = this->m_Panels.m_Memory.m_pMemory;
    v14 = this->m_Panels.m_Size - m_Size - 1;
    this->m_Panels.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
    v15 = &this->m_Panels.m_Memory.m_pMemory[m_Size];
    result = v7;
    if ( v15 != nullptr )
      *v15 = v7;
  }
  else
  {
    _Warning(a1: "Failed to create panel %s\n", szClassName);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004074F0
// Name: protected: class KeyValues __near * CKV_Editor::FindFileSpecNodeForKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CKV_Editor::FindFileSpecNodeForKey(CKV_Editor *this, KeyValues *pKey)
{
  KeyValues *result; // eax
  KeyValues *ParentForKey; // esi
  KeyValues **m_pMemory; // edi
  int m_Size; // ebx
  KeyValues *m_pFileSpec; // esi
  const char *String; // edi
  const char *Name; // eax
  const char *v9; // eax
  const char *v10; // eax
  KeyValues *NextKey; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > chain; // [esp+0h] [ebp-18h] BYREF
  CKV_Editor *v13; // [esp+14h] [ebp-4h]
  int iCurrentDepth; // [esp+20h] [ebp+8h]

  result = nullptr;
  v13 = this;
  if ( this->m_pFileSpec != nullptr )
  {
    ParentForKey = pKey;
    m_pMemory = nullptr;
    m_Size = 0;
    memset(&chain, 0, sizeof(chain));
    if ( pKey != nullptr )
    {
      while ( 1 )
      {
        if ( m_Size + 1 > (int)result )
        {
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&chain,
            num: m_Size - (_DWORD)result + 1);
          m_Size = chain.m_Size;
          m_pMemory = chain.m_Memory.m_pMemory;
        }
        chain.m_Size = ++m_Size;
        chain.m_pElements = m_pMemory;
        if ( m_Size - 1 > 0 )
          _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * (m_Size - 1));
        if ( m_pMemory != nullptr )
          *m_pMemory = ParentForKey;
        ParentForKey = CKV_Editor::FindParentForKey(this: v13, pSearchChild: ParentForKey);
        if ( ParentForKey == nullptr )
          break;
        result = (KeyValues *)chain.m_Memory.m_nAllocationCount;
      }
    }
    m_pFileSpec = v13->m_pFileSpec;
    iCurrentDepth = 0;
    if ( m_pFileSpec == nullptr )
    {
LABEL_22:
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&chain);
      return nullptr;
    }
    while ( 1 )
    {
      String = "_unnamed_node";
      Name = KeyValues::GetName(this: m_pFileSpec);
      if ( _V_stricmp(s1: Name, s2: "_Node") == 0
        || (v9 = KeyValues::GetName(this: m_pFileSpec), _V_stricmp(s1: v9, s2: "_Leaf") == 0) )
      {
        String = KeyValues::GetString(this: m_pFileSpec, keyName: "Name", defaultValue: "_unnamed_node");
      }
      v10 = KeyValues::GetName(this: chain.m_Memory.m_pMemory[iCurrentDepth]);
      if ( _V_stricmp(s1: String, s2: v10) != 0 && _V_stricmp(s1: String, s2: "*") != 0 )
      {
        NextKey = KeyValues::GetNextKey(this: m_pFileSpec);
      }
      else
      {
        if ( ++iCurrentDepth >= m_Size )
        {
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&chain);
          return m_pFileSpec;
        }
        NextKey = KeyValues::GetFirstSubKey(this: m_pFileSpec);
      }
      m_pFileSpec = NextKey;
      if ( NextKey == nullptr )
        goto LABEL_22;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407660
// Name: public: virtual void CKV_Editor::AddToKey(class KeyValues __near *,class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::AddToKey(
        CKV_Editor *this,
        KeyValues *pFileSpecNode,
        KeyValues *pKey,
        const char *szNewKeyName)
{
  CKV_Editor *v4; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  bool v7; // bl
  const char *v8; // eax
  int v9; // eax
  const char *String; // eax
  bool v11; // zf
  const char *v12; // eax
  bool v13; // bl
  KeyValues *v14; // edi
  const char *v15; // eax
  KeyValues *v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  KeyValues *v19; // edi
  const char *v20; // eax
  KeyValues *v21; // edi
  const char *v22; // eax
  KeyValues *FileSpecNodeForKey; // eax
  bool bLeaf_3; // [esp+17h] [ebp+Bh]

  v4 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pFileSpecNode);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      v7 = _V_stricmp(s1: Name, s2: "_Node") == 0;
      v8 = KeyValues::GetName(this: FirstSubKey);
      v9 = _V_stricmp(s1: v8, s2: "_Leaf");
      bLeaf_3 = v9 == 0;
      if ( v9 == 0 || v7 )
      {
        if ( szNewKeyName != nullptr )
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
          v11 = _V_stricmp(s1: String, s2: szNewKeyName) == 0;
        }
        else
        {
          v11 = KeyValues::GetInt(this: FirstSubKey, keyName: "Autocreate", defaultValue: 0) == 1;
        }
        if ( v11 )
        {
          if ( bLeaf_3 )
          {
            v12 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
            v13 = KeyValues::FindKey(this: pKey, keyName: v12, bCreate: false) != nullptr;
            if ( KeyValues::GetInt(this: FirstSubKey, keyName: "Unique", defaultValue: 0) != 1 || !v13 )
            {
              v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v14 != nullptr )
              {
                v15 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
                v16 = KeyValues::KeyValues(this: v14, setName: v15);
              }
              else
              {
                v16 = nullptr;
              }
              v17 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
              _Msg(a1: "Added leaf %s\n", v17);
              v18 = KeyValues::GetString(this: FirstSubKey, keyName: "DefaultValue", defaultValue: &defaultValue);
              KeyValues::SetStringValue(this: v16, strValue: v18);
              KeyValues::AddSubKey(this: pKey, pSubkey: v16);
            }
          }
          else
          {
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
            {
              v20 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
              v21 = KeyValues::KeyValues(this: v19, setName: v20);
            }
            else
            {
              v21 = nullptr;
            }
            v22 = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: &defaultValue);
            _Msg(a1: "Added node %s\n", v22);
            KeyValues::AddSubKey(this: pKey, pSubkey: v21);
            FileSpecNodeForKey = CKV_Editor::FindFileSpecNodeForKey(this, pKey: v21);
            if ( FileSpecNodeForKey != nullptr )
              this->AddToKey(this, a2: FileSpecNodeForKey, a3: v21, a4: nullptr);
          }
        }
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    v4 = this;
  }
  v4->OnKeyAdded(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004078A0
// Name: protected: void CKV_Editor::UpdatePanels(class KeyValues __near *,class CKV_Editor_Base_Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::UpdatePanels(
        CKV_Editor *this,
        KeyValues *pKV,
        CKV_Editor_Base_Panel *pParentPanel,
        bool bIncludeSiblings)
{
  KeyValues *NextKey; // edi
  CKV_Editor *v5; // ebx
  int m_Size; // edx
  int v7; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  CKV_Editor_Base_Panel *Panel; // esi
  KeyValues *FileSpecNodeForKey; // eax
  const char *String; // ebx
  const char *v12; // eax
  vgui::Panel *v13; // eax
  CKV_Fit_Children_Panel *v14; // eax
  KeyValues *ParentForKey; // eax
  KeyValues *FirstSubKey; // eax
  const char *Name; // eax
  const char *v18; // [esp-4h] [ebp-14h]
  KeyValues *pFileSpecNode; // [esp+18h] [ebp+8h]

  NextKey = pKV;
  v5 = this;
  if ( pKV == nullptr )
    goto LABEL_28;
  while ( 1 )
  {
    m_Size = v5->m_Panels.m_Size;
    v7 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      Panel = nullptr;
    }
    else
    {
      m_pMemory = v5->m_Panels.m_Memory.m_pMemory;
      while ( (*m_pMemory)->m_pKey != NextKey )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_6;
      }
      Panel = v5->m_Panels.m_Memory.m_pMemory[v7];
    }
    FileSpecNodeForKey = CKV_Editor::FindFileSpecNodeForKey(this: v5, pKey: NextKey);
    pFileSpecNode = FileSpecNodeForKey;
    if ( FileSpecNodeForKey != nullptr )
    {
      String = KeyValues::GetString(this: FileSpecNodeForKey, keyName: "Panel", defaultValue: "CKV_Node_Panel");
    }
    else
    {
      if ( v5->m_bRequireFileSpec )
      {
        v18 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: &defaultValue);
        Name = KeyValues::GetName(this: NextKey);
        _Warning(a1: "Key %s:%s has no FileSpecNode!\n", Name, v18);
        return;
      }
      if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
        String = "CKV_Node_Panel";
      else
        String = "CKV_Leaf_Panel";
    }
    if ( Panel == nullptr )
      goto LABEL_15;
    v12 = Panel->GetClassName(this: Panel);
    if ( _V_stricmp(s1: v12, s2: String) != 0 )
    {
      Panel->SetVisible(this: Panel, a2: false);
      Panel->MarkForDeletion(this: Panel);
      v13 = Panel->GetParent(this: Panel);
      v14 = (CKV_Fit_Children_Panel *)__RTDynamicCast(
                                        inptr: v13,
                                        VfDelta: 0,
                                        SrcType: &vgui::Panel `RTTI Type Descriptor',
                                        TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
                                        isReference: 0);
      if ( v14 != nullptr )
        CKV_Fit_Children_Panel::RemoveAutoPositionPanel(this: v14, pPanel: Panel);
LABEL_15:
      Panel = CKV_Editor::CreatePanel(this, szClassName: String, pParent: pParentPanel, pFileSpecNode, pKey: NextKey);
      goto LABEL_21;
    }
    CKV_Editor_Base_Panel::SetKey(this: Panel, pKey: NextKey);
    ParentForKey = CKV_Editor::FindParentForKey(this, pSearchChild: NextKey);
    CKV_Editor_Base_Panel::SetKeyParent(this: Panel, pKey: ParentForKey);
LABEL_21:
    if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: NextKey);
      CKV_Editor::UpdatePanels(this, pKV: FirstSubKey, pParentPanel: Panel, bIncludeSiblings: true);
    }
    if ( !bIncludeSiblings )
      break;
    v5 = this;
    NextKey = KeyValues::GetNextKey(this: NextKey);
    if ( NextKey == nullptr )
      goto LABEL_28;
  }
  v5 = this;
LABEL_28:
  v5->m_pContainer->InvalidateLayout(this: v5->m_pContainer, a2: true, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00407A70
// Name: public: virtual void CKV_Editor::SetFileSpec(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetFileSpec(CKV_Editor *this, KeyValues *pKeys)
{
  this->m_pFileSpec = pKeys;
  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
}

//------------------------------------------------------------------------------
// Address: 0x00407AB0
// Name: public: virtual void CKV_Editor::SetKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::SetKeys(CKV_Editor *this, KeyValues *pKeys)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->m_pKeys = pKeys;
  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407B30
// Name: public: virtual void CKV_Editor::OnKeyDeleted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor::OnKeyDeleted(CKV_Editor *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  CKV_Editor::DeleteAllPanels(this);
  CKV_Editor::UpdatePanels(
    this,
    pKV: this->m_pKeys,
    pParentPanel: this->m_pContainer,
    bIncludeSiblings: this->m_bShowSiblings);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

} // namespace vgui_editor
