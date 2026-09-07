// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui_src_editor.cpp
// Functions: 7
// ============================================================

#include "utils\vgui_editor\vgui_src_editor.h"

//------------------------------------------------------------------------------
// Address: 0x00406140
// Name: class CVGUI_Src_Editor __near * VGUI_Src_Editor(void)
// Source: json
//------------------------------------------------------------------------------
CVGUI_Src_Editor *__cdecl VGUI_Src_Editor()
{
  return g_pVGUISrcEditor;
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: protected: bool CVGUI_Src_Editor::SaveManagedPanelList(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGUI_Src_Editor::SaveManagedPanelList(CVGUI_Src_Editor *this)
{
  KeyValues *v2; // eax
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char szPanelListFile[260]; // [esp+8h] [ebp-108h] BYREF
  KeyValues *pKeys; // [esp+10Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
    pKeys = KeyValues::KeyValues(this: v2, setName: "pManagedPanelListKeys");
  else
    pKeys = nullptr;
  if ( this->m_ManagedPanels.m_Size > 0 )
  {
    do
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "ManagedPanel");
      else
        v5 = nullptr;
      CManaged_Panel_Data::SaveToKeyValues(this: this->m_ManagedPanels.m_Memory.m_pMemory[v3], pKeys: v5);
      KeyValues::AddSubKey(this: pKeys, pSubkey: v5);
      ++v3;
    }
    while ( v3 < this->m_ManagedPanels.m_Size );
  }
  V_snprintf(
    pDest: szPanelListFile,
    maxLen: 260,
    pFormat: "%s/game/client/%s/vgui/managed_panel_list.txt",
    this->m_pszVSRC,
    this->m_pszVMOD);
  if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: szPanelListFile) )
    _Warning(a1: "Failed to open %s for edit with p4\n", szPanelListFile);
  if ( g_pFullFileSystem != nullptr )
    return KeyValues::SaveToFile(
             this: pKeys,
             filesystem: &g_pFullFileSystem->IBaseFileSystem,
             resourceName: szPanelListFile,
             pathID: nullptr);
  else
    return KeyValues::SaveToFile(this: pKeys, filesystem: nullptr, resourceName: szPanelListFile, pathID: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004062D0
// Name: public: CVGUI_Src_Editor::CVGUI_Src_Editor(void)
// Source: json
//------------------------------------------------------------------------------
CVGUI_Src_Editor *__thiscall CVGUI_Src_Editor::CVGUI_Src_Editor(CVGUI_Src_Editor *this)
{
  this->m_ManagedPanels.m_Memory.m_pMemory = nullptr;
  this->m_ManagedPanels.m_Memory.m_nAllocationCount = 0;
  this->m_ManagedPanels.m_Memory.m_nGrowSize = 0;
  this->m_ManagedPanels.m_Size = 0;
  this->m_ManagedPanels.m_pElements = nullptr;
  g_pVGUISrcEditor = this;
  this->m_szInitError[0] = 0;
  this->m_pszVGAME = nullptr;
  this->m_pszVSRC = nullptr;
  this->m_pszVMOD = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406300
// Name: public: CVGUI_Src_Editor::~CVGUI_Src_Editor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor::~CVGUI_Src_Editor(CVGUI_Src_Editor *this)
{
  g_pVGUISrcEditor = nullptr;
  CUtlVector<CManaged_Panel_Data *,CUtlMemory<CManaged_Panel_Data *,int>>::PurgeAndDeleteElements(this: &this->m_ManagedPanels);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00406320
// Name: protected: bool CVGUI_Src_Editor::LoadManagedPanelList(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVGUI_Src_Editor::LoadManagedPanelList(CVGUI_Src_Editor *this)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *v4; // edi
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  CManaged_Panel_Data *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CManaged_Panel_Data **m_pMemory; // ecx
  int v12; // eax
  CManaged_Panel_Data **v13; // eax
  char szPanelListFile[260]; // [esp+8h] [ebp-10Ch] BYREF
  CManaged_Panel_Data *pManagedPanel; // [esp+10Ch] [ebp-8h]
  KeyValues *pKeys; // [esp+110h] [ebp-4h]

  V_snprintf(
    pDest: szPanelListFile,
    maxLen: 260,
    pFormat: "%s/game/client/%s/vgui/managed_panel_list.txt",
    this->m_pszVSRC,
    this->m_pszVMOD);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    pKeys = KeyValues::KeyValues(this: v2, setName: "pManagedPanelListKeys");
  else
    pKeys = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  v4 = pKeys;
  if ( KeyValues::LoadFromFile(
         this: pKeys,
         filesystem: v3,
         resourceName: szPanelListFile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "ManagedPanel") == 0 )
        {
          v8 = (CManaged_Panel_Data *)operator new(nSize: 0x528u);
          if ( v8 != nullptr )
            pManagedPanel = CManaged_Panel_Data::CManaged_Panel_Data(this: v8);
          else
            pManagedPanel = nullptr;
          CManaged_Panel_Data::LoadFromKeyValues(this: pManagedPanel, pKeys: FirstSubKey);
          m_Size = this->m_ManagedPanels.m_Size;
          m_nAllocationCount = this->m_ManagedPanels.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              (CUtlMemory<vgui::TreeNode *,int> *)this,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_ManagedPanels.m_Size;
          m_pMemory = this->m_ManagedPanels.m_Memory.m_pMemory;
          v12 = this->m_ManagedPanels.m_Size - m_Size - 1;
          this->m_ManagedPanels.m_pElements = this->m_ManagedPanels.m_Memory.m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
          v13 = &this->m_ManagedPanels.m_Memory.m_pMemory[m_Size];
          if ( v13 != nullptr )
            *v13 = pManagedPanel;
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v4 = pKeys;
    }
    KeyValues::deleteThis(this: v4);
    return 1;
  }
  else
  {
    V_snprintf(pDest: this->m_szInitError, maxLen: 256, pFormat: "Error loading %s", szPanelListFile);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064A0
// Name: public: void CVGUI_Src_Editor::CreateNewManagedPanel(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor::CreateNewManagedPanel(
        CVGUI_Src_Editor *this,
        const char *szName,
        const char *szParentClass)
{
  CManaged_Panel_Data *v4; // eax
  CManaged_Panel_Data *v5; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CManaged_Panel_Data **m_pMemory; // ecx
  int v9; // eax
  CManaged_Panel_Data **v10; // eax

  v4 = (CManaged_Panel_Data *)operator new(nSize: 0x528u);
  if ( v4 != nullptr )
    v5 = CManaged_Panel_Data::CManaged_Panel_Data(this: v4);
  else
    v5 = nullptr;
  CManaged_Panel_Data::SetName(this: v5, szName);
  CManaged_Panel_Data::SetParentClass(this: v5, szParentClass);
  if ( CManaged_Panel_Data::CreateInitialFiles(this: v5) != 0 )
  {
    m_nAllocationCount = this->m_ManagedPanels.m_Memory.m_nAllocationCount;
    m_Size = this->m_ManagedPanels.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        (CUtlMemory<vgui::TreeNode *,int> *)this,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ManagedPanels.m_Size;
    m_pMemory = this->m_ManagedPanels.m_Memory.m_pMemory;
    v9 = this->m_ManagedPanels.m_Size - m_Size - 1;
    this->m_ManagedPanels.m_pElements = this->m_ManagedPanels.m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ManagedPanels.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v5;
    CVGUI_Src_Editor::SaveManagedPanelList(this);
  }
  else if ( v5 != nullptr )
  {
    CManaged_Panel_Data::~CManaged_Panel_Data(this: v5);
    free(pMem: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406560
// Name: public: bool CVGUI_Src_Editor::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGUI_Src_Editor::Init(CVGUI_Src_Editor *this)
{
  const char *v2; // eax
  const char *v4; // eax
  const char *v5; // eax

  v2 = getenv(option: "VGAME");
  this->m_pszVGAME = v2;
  if ( v2 == nullptr )
  {
    V_snprintf(pDest: this->m_szInitError, maxLen: 256, pFormat: "VGAME env variable not set.");
    return false;
  }
  v4 = getenv(option: "VSRC");
  this->m_pszVSRC = v4;
  if ( v4 == nullptr )
  {
    V_snprintf(pDest: this->m_szInitError, maxLen: 256, pFormat: "VSRC env variable not set.");
    return false;
  }
  v5 = getenv(option: "VMOD");
  this->m_pszVMOD = v5;
  if ( v5 == nullptr )
  {
    V_snprintf(pDest: this->m_szInitError, maxLen: 256, pFormat: "VMOD env variable not set.");
    return false;
  }
  return CVGUI_Src_Editor::LoadManagedPanelList(this) != 0;
}
