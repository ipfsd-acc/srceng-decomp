// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/soundproperties.cpp
// Functions: 9
// ============================================================

#include "utils\scenemanager\soundproperties.h"

//------------------------------------------------------------------------------
// Address: 0x00410950
// Name: PopulateScriptList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateScriptList(HWND wnd@<eax>, const char *curscript)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  int c; // [esp+4h] [ebp-4h]

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1005);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( curscript != nullptr )
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)curscript);
    v4 = 0;
    c = g_pSoundEmitterSystem->GetNumSoundScripts(this: g_pSoundEmitterSystem);
    if ( c > 0 )
    {
      do
      {
        v5 = g_pSoundEmitterSystem->GetSoundScriptName(this: g_pSoundEmitterSystem, a2: v4);
        SendMessageA(hWnd: v3, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v5);
        if ( curscript == nullptr && v4 == 0 )
        {
          v6 = g_pSoundEmitterSystem->GetSoundScriptName(this: g_pSoundEmitterSystem, a2: 0);
          SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v6);
        }
        ++v4;
      }
      while ( v4 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004109F0
// Name: WaveLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WaveLessFunc(const char **name1, const char **name2)
{
  return _V_stricmp(s1: *name1, s2: *name2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410A10
// Name: SoundProperties_OnOK
// Source: json
//------------------------------------------------------------------------------
void __usercall SoundProperties_OnOK(HWND hwndDlg@<eax>)
{
  ISoundEmitterSystemBase_vtbl *v2; // ebx
  int v3; // eax
  int v4; // eax
  HWND DlgItem; // eax
  LRESULT v6; // eax
  HWND v7; // eax
  signed int v8; // edi
  HWND v9; // eax
  CSoundEntry *v10; // esi
  ISoundEmitterSystemBase_vtbl *v11; // edi
  int v12; // eax
  ISoundEmitterSystemBase_vtbl *v13; // edi
  int v14; // eax
  ISoundEmitterSystemBase_vtbl *v15; // edi
  int v16; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  char wavename[256]; // [esp+Ch] [ebp-3B8h] BYREF
  char outsoundname[256]; // [esp+10Ch] [ebp-2B8h] BYREF
  char outscriptfile[256]; // [esp+20Ch] [ebp-1B8h] BYREF
  char sz[128]; // [esp+30Ch] [ebp-B8h] BYREF
  CSoundParametersInternal outparams; // [esp+38Ch] [ebp-38h] BYREF
  int c; // [esp+3B4h] [ebp-10h]
  CUtlSymbol sym; // [esp+3B8h] [ebp-Ch] BYREF
  CSoundEntry *item; // [esp+3BCh] [ebp-8h]
  SoundFile source; // [esp+3C0h] [ebp-4h] BYREF

  CSoundParametersInternal::CSoundParametersInternal(this: &outparams);
  item = *g_Params_1.items.m_Memory.m_pMemory;
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1004, lpString: outsoundname, cchMax: 256);
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1005, lpString: outscriptfile, cchMax: 256);
  if ( !g_Params_1.addsound )
  {
    v2 = g_pSoundEmitterSystem->__vftable;
    v3 = item->GetName(this: item);
    v4 = v2->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v3);
    g_pSoundEmitterSystem->GetSourceFileForSound(this: g_pSoundEmitterSystem, a2: v4);
  }
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1007, lpString: sz, cchMax: 128);
  CSoundParametersInternal::ChannelFromString(this: &outparams, sz);
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1008, lpString: sz, cchMax: 128);
  CSoundParametersInternal::VolumeFromString(this: &outparams, sz);
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1009, lpString: sz, cchMax: 128);
  CSoundParametersInternal::SoundLevelFromString(this: &outparams, sz);
  GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1010, lpString: sz, cchMax: 128);
  CSoundParametersInternal::PitchFromString(this: &outparams, sz);
  DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1017);
  v6 = SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0);
  *((_BYTE *)&outparams + 28) ^= ((v6 == 1) ^ *((_BYTE *)&outparams + 28)) & 1;
  v7 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
  v8 = 0;
  c = SendMessageA(hWnd: v7, Msg: 0x18Bu, wParam: 0, lParam: 0);
  if ( c > 0 )
  {
    do
    {
      v9 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
      SendMessageA(hWnd: v9, Msg: 0x189u, wParam: v8, lParam: (LPARAM)wavename);
      g_pSoundEmitterSystem->AddWaveName(this: g_pSoundEmitterSystem, result: &sym, a3: wavename);
      source.symbol = sym;
      *(_WORD *)&source.gender = 256;
      CSoundParametersInternal::AddToTail(
        this: &outparams,
        pDest: &outparams.m_pSoundNames,
        pDestCount: &outparams.m_nSoundNames,
        &source);
      ++v8;
    }
    while ( v8 < c );
  }
  if ( g_Params_1.addsound )
  {
    g_pSoundEmitterSystem->AddSound(this: g_pSoundEmitterSystem, a2: outsoundname, a3: outscriptfile, a4: &outparams);
    v10 = item;
  }
  else
  {
    v10 = item;
    v11 = g_pSoundEmitterSystem->__vftable;
    v12 = ((int (__thiscall *)(CSoundEntry *, char *))item->GetName)(a1: item, a2: outscriptfile);
    ((void (__thiscall *)(ISoundEmitterSystemBase *, int))v11->MoveSound)(a1: g_pSoundEmitterSystem, a2: v12);
    CSoundEntry::SetScriptFile(this: v10, scriptfile: outscriptfile);
    v13 = g_pSoundEmitterSystem->__vftable;
    v14 = ((int (__thiscall *)(CSoundEntry *, CSoundParametersInternal *))v10->GetName)(a1: v10, a2: &outparams);
    ((void (__thiscall *)(ISoundEmitterSystemBase *, int))v13->UpdateSoundParameters)(
      a1: g_pSoundEmitterSystem,
      a2: v14);
    v15 = g_pSoundEmitterSystem->__vftable;
    v16 = ((int (__thiscall *)(CSoundEntry *, char *))v10->GetName)(a1: v10, a2: outsoundname);
    ((void (__thiscall *)(ISoundEmitterSystemBase *, int))v15->RenameSound)(a1: g_pSoundEmitterSystem, a2: v16);
  }
  CSoundEntry::SetName(this: v10, name: outsoundname);
  WorkspaceManager = GetWorkspaceManager();
  CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  CSoundParametersInternal::~CSoundParametersInternal(this: &outparams);
}

//------------------------------------------------------------------------------
// Address: 0x00411A00
// Name: public: CWaveParams::CWaveParams(void)
// Source: json
//------------------------------------------------------------------------------
CWaveParams *__thiscall CWaveParams::CWaveParams(CWaveParams *this)
{
  this->items.m_Memory.m_pMemory = nullptr;
  this->items.m_Memory.m_nAllocationCount = 0;
  this->items.m_Memory.m_nGrowSize = 0;
  this->items.m_Size = 0;
  this->items.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411A30
// Name: SoundProperties_GetSelectedWaveList
// Source: json
//------------------------------------------------------------------------------
void __usercall SoundProperties_GetSelectedWaveList(
        HWND control@<eax>,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list@<esi>)
{
  LRESULT v3; // eax
  signed int i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  int *v7; // ecx
  int v8; // eax
  int *v9; // eax
  int *s; // [esp+4h] [ebp-8h]
  signed int count; // [esp+8h] [ebp-4h]

  if ( control != nullptr )
  {
    v3 = SendMessageA(hWnd: control, Msg: 0x190u, wParam: 0, lParam: 0);
    count = v3;
    if ( v3 != -1 )
    {
      s = (int *)operator new(nSize: 4 * v3);
      SendMessageA(hWnd: control, Msg: 0x191u, wParam: count, lParam: (LPARAM)s);
      for ( i = 0; i < count; ++i )
      {
        m_pMemory = (int)list[1].m_pMemory;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v7 = (int *)list->m_pMemory;
        v8 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
        v9 = (int *)&list->m_pMemory[m_pMemory];
        if ( v9 != nullptr )
          *v9 = s[i];
      }
      free(pMem: s);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411B00
// Name: PopulateWaveList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateWaveList(HWND wnd@<eax>, CSoundParametersInternal *p)
{
  HWND__ *DlgItem; // eax
  CSoundParametersInternal *v3; // ecx
  int m_nSoundNames; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // ebx
  ISoundEmitterSystemBase *v6; // esi
  ISoundEmitterSystemBase_vtbl *v7; // edi
  SoundFile *SoundNames; // eax
  const char *v9; // eax
  const char *v10; // edi
  char *v11; // eax
  int v12; // eax
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // ecx
  int v14; // edx
  int v15; // esi
  int v16; // edx
  int j; // edi
  char *m_Data; // esi
  CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > m_SortedNames; // [esp+4h] [ebp-3Ch] BYREF
  HWND__ *control; // [esp+28h] [ebp-18h]
  int c; // [esp+2Ch] [ebp-14h]
  const char *name; // [esp+30h] [ebp-10h] BYREF
  int parent; // [esp+34h] [ebp-Ch] BYREF
  int i; // [esp+38h] [ebp-8h]
  bool leftchild; // [esp+3Fh] [ebp-1h] BYREF

  DlgItem = GetDlgItem(hDlg: wnd, nIDDlgItem: 1013);
  control = DlgItem;
  if ( DlgItem != nullptr )
  {
    SendMessageA(hWnd: DlgItem, Msg: 0x184u, wParam: 0, lParam: 0);
    v3 = p;
    if ( p != nullptr )
    {
      m_SortedNames.m_Root = -1;
      m_SortedNames.m_FirstFree = -1;
      m_SortedNames.m_LastAlloc.index = -1;
      m_nSoundNames = p->m_nSoundNames;
      v5 = nullptr;
      m_SortedNames.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))WaveLessFunc;
      memset(&m_SortedNames.m_Elements, 0, sizeof(m_SortedNames.m_Elements));
      m_SortedNames.m_NumElements = 0;
      m_SortedNames.m_pElements = nullptr;
      c = m_nSoundNames;
      i = 0;
      if ( m_nSoundNames > 0 )
      {
        while ( 1 )
        {
          v6 = g_pSoundEmitterSystem;
          v7 = g_pSoundEmitterSystem->__vftable;
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v3);
          v9 = v7->GetWaveName(this: v6, a2: (CUtlSymbol *)&SoundNames[i]);
          v10 = v9;
          if ( v9 != nullptr && (v11 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v9) + 1)) != nullptr )
            strcpy(v11, v10);
          else
            v11 = nullptr;
          name = v11;
          parent = -1;
          leftchild = false;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
            this: &m_SortedNames,
            insert: &name,
            &parent,
            &leftchild);
          v12 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                  this: (CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *)&m_SortedNames,
                  a2: (const char *)0xFFFFFFFF);
          m_pMemory = m_SortedNames.m_Elements.m_pMemory;
          v14 = parent;
          v15 = v12;
          m_SortedNames.m_Elements.m_pMemory[v15].m_Parent = parent;
          m_pMemory[v15].m_Right = -1;
          m_pMemory[v15].m_Left = -1;
          m_pMemory[v15].m_Tag = 0;
          if ( v14 == -1 )
          {
            m_SortedNames.m_Root = v12;
          }
          else
          {
            v16 = v14;
            if ( leftchild )
              m_pMemory[v16].m_Left = v12;
            else
              m_pMemory[v16].m_Right = v12;
          }
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
            this: &m_SortedNames,
            elem: v12);
          v5 = m_SortedNames.m_Elements.m_pMemory;
          ++m_SortedNames.m_NumElements;
          if ( &m_SortedNames.m_Elements.m_pMemory[v15] != (UtlRBTreeNode_t<char const *,int> *)-16 )
            m_SortedNames.m_Elements.m_pMemory[v15].m_Data = name;
          if ( ++i >= c )
            break;
          v3 = p;
        }
      }
      for ( j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(this: &m_SortedNames);
            j != -1;
            j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
                  this: &m_SortedNames,
                  i: j) )
      {
        m_Data = (char *)v5[j].m_Data;
        if ( m_Data != nullptr && *m_Data != 0 )
          SendMessageA(hWnd: control, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v5[j].m_Data);
        free(pMem: m_Data);
      }
      CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(this: &m_SortedNames);
      if ( m_SortedNames.m_Elements.m_nGrowSize >= 0 && m_SortedNames.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_SortedNames.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411D00
// Name: PopulateWaveList_Available
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateWaveList_Available(HWND wnd@<eax>)
{
  CWorkspaceManager *WorkspaceManager; // eax
  CWaveBrowser *WaveBrowser; // esi
  UtlRBTreeNode_t<char const *,int> *v3; // edi
  int SoundCount; // eax
  int v5; // ecx
  CWaveFile *Sound; // eax
  int v7; // eax
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // ecx
  int v9; // edx
  int v10; // esi
  int v11; // edx
  int j; // esi
  const char *m_Data; // eax
  CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > m_SortedNames; // [esp+4h] [ebp-40h] BYREF
  int c; // [esp+28h] [ebp-1Ch]
  CWaveBrowser *wb; // [esp+2Ch] [ebp-18h]
  HWND__ *control; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  const char *name; // [esp+38h] [ebp-Ch] BYREF
  int parent; // [esp+3Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+43h] [ebp-1h] BYREF

  control = GetDlgItem(hDlg: wnd, nIDDlgItem: 1016);
  if ( control != nullptr )
  {
    WorkspaceManager = GetWorkspaceManager();
    WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: WorkspaceManager);
    wb = WaveBrowser;
    if ( WaveBrowser != nullptr )
    {
      v3 = nullptr;
      m_SortedNames.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))WaveLessFunc;
      memset(&m_SortedNames.m_Elements, 0, sizeof(m_SortedNames.m_Elements));
      m_SortedNames.m_Root = -1;
      m_SortedNames.m_NumElements = 0;
      m_SortedNames.m_FirstFree = -1;
      m_SortedNames.m_LastAlloc.index = -1;
      m_SortedNames.m_pElements = nullptr;
      SoundCount = CWaveBrowser::GetSoundCount(this: WaveBrowser);
      v5 = 0;
      c = SoundCount;
      i = 0;
      if ( SoundCount > 0 )
      {
        while ( 1 )
        {
          Sound = CWaveBrowser::GetSound(this: WaveBrowser, index: v5);
          if ( Sound != nullptr )
          {
            name = (const char *)Sound->GetName(this: Sound);
            parent = -1;
            leftchild = false;
            CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
              this: &m_SortedNames,
              insert: &name,
              &parent,
              &leftchild);
            v7 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                   this: (CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *)&m_SortedNames,
                   a2: (const char *)v3);
            m_pMemory = m_SortedNames.m_Elements.m_pMemory;
            v9 = parent;
            v10 = v7;
            m_SortedNames.m_Elements.m_pMemory[v10].m_Parent = parent;
            m_pMemory[v10].m_Right = -1;
            m_pMemory[v10].m_Left = -1;
            m_pMemory[v10].m_Tag = 0;
            if ( v9 == -1 )
            {
              m_SortedNames.m_Root = v7;
            }
            else
            {
              v11 = v9;
              if ( leftchild )
                m_pMemory[v11].m_Left = v7;
              else
                m_pMemory[v11].m_Right = v7;
            }
            CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
              this: &m_SortedNames,
              elem: v7);
            v3 = m_SortedNames.m_Elements.m_pMemory;
            ++m_SortedNames.m_NumElements;
            if ( &m_SortedNames.m_Elements.m_pMemory[v10] != (UtlRBTreeNode_t<char const *,int> *)-16 )
              m_SortedNames.m_Elements.m_pMemory[v10].m_Data = name;
          }
          v5 = i + 1;
          i = v5;
          if ( v5 >= c )
            break;
          WaveBrowser = wb;
        }
      }
      SendMessageA(hWnd: control, Msg: 0x184u, wParam: 0, lParam: 0);
      for ( j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(this: &m_SortedNames);
            j != -1;
            j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
                  this: &m_SortedNames,
                  i: j) )
      {
        m_Data = v3[j].m_Data;
        if ( m_Data != nullptr && *m_Data != 0 )
          SendMessageA(hWnd: control, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v3[j].m_Data);
      }
      CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(this: &m_SortedNames);
      if ( m_SortedNames.m_Elements.m_nGrowSize >= 0 && m_SortedNames.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_SortedNames.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411EC0
// Name: SoundPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __userpurge SoundPropertiesDialogProc@<eax>(
        int a1@<edi>,
        HWND hwndDlg,
        const char *uMsg,
        unsigned int wParam,
        int lParam)
{
  HWND v5; // eax
  HWND v6; // esi
  WPARAM v7; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  CWaveBrowser *WaveBrowser; // eax
  CWaveFile *Entry; // eax
  const char *v11; // eax
  HWND v14; // eax
  int v15; // eax
  HWND v16; // eax
  CWorkspaceManager *v17; // eax
  CWaveBrowser *v18; // eax
  CWaveFile *v19; // eax
  CWaveFile *v20; // esi
  CSoundEntry *v21; // edi
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // esi
  WPARAM v25; // eax
  CWorkspaceManager *v26; // eax
  CWaveBrowser *v27; // eax
  CWaveFile *v28; // edi
  int v29; // eax
  int v30; // esi
  CWaveFile **v31; // ecx
  int v32; // eax
  CWaveFile **v33; // eax
  HWND v34; // eax
  int v35; // esi
  HWND v36; // eax
  CWorkspaceManager *v37; // eax
  CWaveBrowser *v38; // eax
  CWaveFile *v39; // eax
  int j; // esi
  HWND v41; // eax
  CSoundParametersInternal *v43; // ebx
  CSoundEntry *v44; // eax
  int m_Size; // eax
  int v46; // edi
  CSoundEntry **m_pMemory; // ecx
  int v48; // eax
  CSoundEntry **v49; // edi
  CSoundEntry *v50; // edi
  HWND DlgItem; // eax
  ISoundEmitterSystemBase_vtbl *v52; // ebx
  int v53; // eax
  int v54; // ebx
  HWND v55; // eax
  const char *SentenceText; // eax
  const char *v57; // eax
  HWND v58; // eax
  WPARAM v59; // [esp-8h] [ebp-928h]
  WPARAM v60; // [esp-8h] [ebp-928h]
  WPARAM v61; // [esp-8h] [ebp-928h]
  WPARAM v62; // [esp-8h] [ebp-928h]
  wchar_t cctext[1024]; // [esp+Ch] [ebp-914h] BYREF
  char v64[96]; // [esp+80Ch] [ebp-114h] BYREF
  CWaveParams wp; // [esp+86Ch] [ebp-B4h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > selected; // [esp+90Ch] [ebp-14h] BYREF
  int i; // [esp+928h] [ebp+8h]
  CSoundEntry *ia; // [esp+928h] [ebp+8h]
  const char *script; // [esp+92Ch] [ebp+Ch]

  if ( uMsg == (const char *)272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_1, self: hwndDlg);
    v43 = nullptr;
    script = nullptr;
    if ( g_Params_1.addsound )
    {
      v44 = (CSoundEntry *)operator new(nSize: 0x21Cu);
      if ( v44 != nullptr )
        ia = CSoundEntry::CSoundEntry(
               this: v44,
               a2: 0,
               a3: a1,
               a4: (int)hwndDlg,
               vcd: nullptr,
               name: (CSoundParametersInternal *)"Unnamed");
      else
        ia = nullptr;
      m_Size = g_Params_1.items.m_Size;
      v46 = g_Params_1.items.m_Size;
      if ( g_Params_1.items.m_Size + 1 > g_Params_1.items.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_Params_1.items,
          num: g_Params_1.items.m_Size - g_Params_1.items.m_Memory.m_nAllocationCount + 1);
        m_Size = g_Params_1.items.m_Size;
      }
      m_pMemory = g_Params_1.items.m_Memory.m_pMemory;
      g_Params_1.items.m_Size = m_Size + 1;
      v48 = m_Size - v46;
      g_Params_1.items.m_pElements = g_Params_1.items.m_Memory.m_pMemory;
      if ( v48 > 0 )
      {
        _V_memmove(
          dest: &g_Params_1.items.m_Memory.m_pMemory[v46 + 1],
          src: &g_Params_1.items.m_Memory.m_pMemory[v46],
          count: 4 * v48);
        m_pMemory = g_Params_1.items.m_Memory.m_pMemory;
      }
      v49 = &m_pMemory[v46];
      if ( v49 != nullptr )
      {
        *v49 = ia;
        m_pMemory = g_Params_1.items.m_Memory.m_pMemory;
      }
      v50 = *m_pMemory;
      DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1017);
      SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: 0, lParam: 0);
      SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1018, lpString: &WindowName);
      SetDlgItemTextW(hDlg: hwndDlg, nIDDlgItem: 1019, lpString: word_44E770);
    }
    else
    {
      v50 = *g_Params_1.items.m_Memory.m_pMemory;
      v52 = g_pSoundEmitterSystem->__vftable;
      v53 = (***(int (__thiscall ****)(CSoundEntry *))g_Params_1.items.m_Memory.m_pMemory)(a1: *g_Params_1.items.m_Memory.m_pMemory);
      v54 = v52->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v53);
      script = g_pSoundEmitterSystem->GetSourceFileForSound(this: g_pSoundEmitterSystem, a2: v54);
      v43 = g_pSoundEmitterSystem->InternalGetParametersForSound(this: g_pSoundEmitterSystem, a2: v54);
      v62 = (*((_BYTE *)v43 + 28) & 1) != 0;
      v55 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1017);
      SendMessageA(hWnd: v55, Msg: 0xF1u, wParam: v62, lParam: 0);
      SentenceText = CSoundEntry::GetSentenceText(this: v50, wavindex: 0);
      SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1018, lpString: SentenceText);
      CSoundEntry::GetCCText(this: v50, out: cctext, maxchars: 0x400u);
      SetDlgItemTextW(hDlg: hwndDlg, nIDDlgItem: 1019, lpString: cctext);
    }
    PopulateChannelList(wnd: hwndDlg, p: v43);
    PopulateVolumeList(wnd: hwndDlg, p: v43);
    PopulateSoundlevelList(wnd: hwndDlg, p: v43);
    PopulatePitchList(wnd: hwndDlg, p: v43);
    PopulateWaveList(wnd: hwndDlg, p: v43);
    v57 = (const char *)v50->GetName(this: v50);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1004, lpString: v57);
    PopulateScriptList(wnd: hwndDlg, curscript: script);
    PopulateWaveList_Available(wnd: hwndDlg);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_1.m_szDialogTitle);
    v58 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1004);
    SetFocus(hWnd: v58);
    return 0;
  }
  if ( uMsg != (const char *)273 )
    return 0;
  if ( (unsigned __int16)wParam <= 0x3F6u )
  {
    if ( (unsigned __int16)wParam != 1014 )
    {
      if ( (unsigned __int16)wParam == 1 )
      {
        SoundProperties_OnOK(hwndDlg);
        EndDialog(hDlg: hwndDlg, nResult: 1);
        return 0;
      }
      if ( (unsigned __int16)wParam == 2 )
      {
        EndDialog(hDlg: hwndDlg, nResult: 0);
        return 0;
      }
      if ( (unsigned __int16)wParam == 1013 && HIWORD(wParam) == 1 )
      {
        v5 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
        v6 = v5;
        if ( v5 != nullptr )
        {
          v7 = SendMessageA(hWnd: v5, Msg: 0x188u, wParam: 0, lParam: 0);
          if ( v7 != -1 )
          {
            SendMessageA(hWnd: v6, Msg: 0x189u, wParam: v7, lParam: (LPARAM)wavname);
            WorkspaceManager = GetWorkspaceManager();
            WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: WorkspaceManager);
            if ( WaveBrowser != nullptr )
            {
              Entry = CWaveBrowser::FindEntry(this: WaveBrowser, wavname: wavname, jump: true);
              if ( Entry != nullptr )
              {
                v11 = CWaveFile::GetSentenceText(this: Entry);
                SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1018, lpString: v11);
                return 0;
              }
            }
          }
        }
      }
      return 0;
    }
    memset(&selected, 0, sizeof(selected));
    v14 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1016);
    SoundProperties_GetSelectedWaveList(
      control: v14,
      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected);
    if ( selected.m_Size >= 1 )
    {
      v15 = 0;
      i = 0;
      do
      {
        v59 = selected.m_Memory.m_pMemory[v15];
        v16 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1016);
        SendMessageA(hWnd: v16, Msg: 0x189u, wParam: v59, lParam: (LPARAM)v64);
        v17 = GetWorkspaceManager();
        v18 = CWorkspaceManager::GetWaveBrowser(this: v17);
        if ( v18 != nullptr )
        {
          v19 = CWaveBrowser::FindEntry(this: v18, wavname: v64, jump: true);
          v20 = v19;
          if ( v19 != nullptr )
          {
            v21 = *g_Params_1.items.m_Memory.m_pMemory;
            if ( CSoundEntry::FindWave(this: *g_Params_1.items.m_Memory.m_pMemory, wave: v19) == -1 )
            {
              CSoundEntry::AddWave(this: v21, wave: v20);
              v22 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
              SendMessageA(hWnd: v22, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v64);
            }
          }
        }
        v15 = i + 1;
        i = v15;
      }
      while ( v15 < selected.m_Size );
    }
LABEL_23:
    CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
    return 0;
  }
  if ( (unsigned __int16)wParam == 1015 )
  {
    memset(&selected, 0, sizeof(selected));
    v34 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
    SoundProperties_GetSelectedWaveList(
      control: v34,
      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected);
    if ( selected.m_Size >= 1 )
    {
      v35 = 0;
      do
      {
        v60 = selected.m_Memory.m_pMemory[v35];
        v36 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
        SendMessageA(hWnd: v36, Msg: 0x189u, wParam: v60, lParam: (LPARAM)v64);
        v37 = GetWorkspaceManager();
        v38 = CWorkspaceManager::GetWaveBrowser(this: v37);
        if ( v38 != nullptr )
        {
          v39 = CWaveBrowser::FindEntry(this: v38, wavname: v64, jump: true);
          if ( v39 != nullptr )
            CSoundEntry::RemoveWave(this: *g_Params_1.items.m_Memory.m_pMemory, wave: v39);
        }
        ++v35;
      }
      while ( v35 < selected.m_Size );
      for ( j = selected.m_Size - 1; j >= 0; --j )
      {
        v61 = selected.m_Memory.m_pMemory[j];
        v41 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
        SendMessageA(hWnd: v41, Msg: 0x182u, wParam: v61, lParam: 0);
      }
    }
    goto LABEL_23;
  }
  if ( (unsigned __int16)wParam != 1022 )
    return 0;
  v23 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
  v24 = v23;
  if ( v23 == nullptr )
    return 0;
  v25 = SendMessageA(hWnd: v23, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v25 == -1 )
    return 0;
  SendMessageA(hWnd: v24, Msg: 0x189u, wParam: v25, lParam: (LPARAM)wavname);
  v26 = GetWorkspaceManager();
  v27 = CWorkspaceManager::GetWaveBrowser(this: v26);
  if ( v27 == nullptr )
    return 0;
  v28 = CWaveBrowser::FindEntry(this: v27, wavname: wavname, jump: true);
  if ( v28 == nullptr )
    return 0;
  CWaveParams::CWaveParams(this: &wp);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  V_snprintf(pDest: wp.m_szDialogTitle, maxLen: 128, pFormat: "Wave Properties");
  v29 = wp.items.m_Size;
  v30 = wp.items.m_Size;
  if ( wp.items.m_Size + 1 > wp.items.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&wp.items,
      num: wp.items.m_Size - wp.items.m_Memory.m_nAllocationCount + 1);
    v29 = wp.items.m_Size;
  }
  v31 = wp.items.m_Memory.m_pMemory;
  wp.items.m_Size = v29 + 1;
  v32 = v29 - v30;
  wp.items.m_pElements = wp.items.m_Memory.m_pMemory;
  if ( v32 > 0 )
  {
    _V_memmove(dest: &wp.items.m_Memory.m_pMemory[v30 + 1], src: &wp.items.m_Memory.m_pMemory[v30], count: 4 * v32);
    v31 = wp.items.m_Memory.m_pMemory;
  }
  v33 = &v31[v30];
  if ( v33 != nullptr )
    *v33 = v28;
  WaveProperties(params: &wp);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&wp.items);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004124F0
// Name: int SoundProperties(struct CSoundParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl SoundProperties(CSoundParams *params)
{
  int m_Size; // esi
  int i; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  int v5; // esi
  int j; // eax
  HWND Handle; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp-4h] [ebp-14h]
  INT_PTR retval; // [esp+Ch] [ebp-4h]

  qmemcpy(&g_Params_1, params, 0x8Du);
  m_Size = params->items.m_Size;
  g_Params_1.items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(
    this: &g_Params_1.items,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    g_Params_1.items.m_Memory.m_pMemory[i] = params->items.m_Memory.m_pMemory[i];
  WorkspaceManager = GetWorkspaceManager();
  Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  retval = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x75,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)SoundPropertiesDialogProc,
             dwInitParam: 0);
  params->CBaseDialogParams = g_Params_1.CBaseDialogParams;
  params->addsound = g_Params_1.addsound;
  v5 = g_Params_1.items.m_Size;
  v9 = g_Params_1.items.m_Size;
  params->items.m_Size = 0;
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(this: &params->items, elem: 0, num: v9);
  for ( j = 0; j < v5; ++j )
    params->items.m_Memory.m_pMemory[j] = g_Params_1.items.m_Memory.m_pMemory[j];
  return retval;
}
