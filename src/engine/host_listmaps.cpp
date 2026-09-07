// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host_listmaps.cpp
// Functions: 12
// ============================================================

#include "engine\host_listmaps.h"

//------------------------------------------------------------------------------
// Address: 0x1018E6E0
// Name: MapList_ListMaps
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapList_ListMaps(
        const char *pszSubString,
        bool listobsolete,
        bool verbose,
        int maxcount,
        int maxitemlength,
        char (*maplist)[64])
{
  int v6; // ebx
  int v7; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int> *m_pMemory; // edi
  int m_nValid; // edi
  char pDest[32]; // [esp+4h] [ebp-30h] BYREF
  int substringlength; // [esp+24h] [ebp-10h]
  int showOutdated; // [esp+28h] [ebp-Ch]
  char *v14; // [esp+2Ch] [ebp-8h]
  int count; // [esp+30h] [ebp-4h]
  const char *mapname; // [esp+40h] [ebp+Ch]

  v6 = 0;
  substringlength = 0;
  if ( pszSubString != nullptr && *pszSubString != 0 )
    substringlength = strlen(pszSubString);
  if ( verbose )
    ConMsg(a1: "-------------\n");
  count = 0;
  showOutdated = listobsolete;
  while ( v6 < maxcount )
  {
    v7 = 0;
    if ( g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements > 0 )
    {
      v14 = &(*maplist)[64 * v6];
      while ( 1 )
      {
        if ( v6 >= maxcount )
          goto LABEL_44;
        if ( v7 < 0
          || v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          || v7 > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
        {
          break;
        }
        if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1066C608 = -1;
          dword_1066C60C = -1;
          dword_1066C610 = 1;
        }
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Left == v7 )
          goto LABEL_25;
        mapname = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.key;
LABEL_18:
        if ( v7 < 0
          || v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          || v7 > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
        {
          goto LABEL_27;
        }
        if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1066C608 = -1;
          dword_1066C60C = -1;
          dword_1066C610 = 1;
        }
        if ( m_pMemory[v7].m_Left == v7 )
LABEL_27:
          m_nValid = 0;
        else
          m_nValid = m_pMemory[v7].m_Data.elem.m_nValid;
        if ( substringlength == 0 || V_stristr(pStr: mapname + 5, pSearch: pszSubString) != nullptr )
        {
          if ( verbose )
          {
            pDest[0] = 0;
            if ( m_nValid != 0 )
            {
              if ( m_nValid == 1 )
                V_strncpy(pDest, pSrc: "PENDING:  ", maxLen: 32);
            }
            else
            {
              V_strncpy(pDest, pSrc: "OUTDATED:  ", maxLen: 32);
            }
            if ( (m_nValid != 0) != (showOutdated != 0) )
              ConMsg(a1: "%s %s %s\n", pDest, "(fs)", mapname + 5);
          }
          if ( m_nValid != 0 )
          {
            if ( maxitemlength != 0 )
              V_strncpy(pDest: v14, pSrc: mapname + 5, maxLen: maxitemlength);
            ++count;
            v14 += 64;
          }
          v6 = count;
        }
        if ( ++v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements )
          goto LABEL_44;
      }
      m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
LABEL_25:
      mapname = "Invalid!!!";
      goto LABEL_18;
    }
LABEL_44:
    if ( --showOutdated < 0 )
      return v6;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1018EA50
// Name: private: void CMapListManager::BuildList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapListManager::BuildList(CMapListManager *this)
{
  const char *i; // esi
  int v3; // eax
  float v4; // xmm0_4
  char mapwild[96]; // [esp+Ch] [ebp-D4h] BYREF
  char sz[96]; // [esp+6Ch] [ebp-74h] BYREF
  CUtlMap<char const *,CMapListItem,int>::Node_t search; // [esp+CCh] [ebp-14h] BYREF
  CMapListItem item; // [esp+D8h] [ebp-8h] BYREF

  CUtlDict<CMapListItem,int>::RemoveAll(this: &this->m_Items);
  this->m_bDirty = false;
  V_snprintf(pDest: mapwild, maxLen: 96, pFormat: "maps/*.%sbsp", defaultValue);
  for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(basename: nullptr, namelength: 0) )
  {
    if ( V_stristr(pStr: i, pSearch: ".360.bsp") == nullptr )
    {
      V_snprintf(pDest: sz, maxLen: 96, pFormat: "maps/%s", i);
      v3 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: sz, a3: nullptr);
      search.key = sz;
      item.m_lFileTimestamp = v3;
      item.m_nValid = 1;
      search.elem.m_nValid = 1;
      search.elem.m_lFileTimestamp = 0;
      if ( CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Find(
             this: &this->m_Items.m_Elements.m_Tree,
             &search) == -1 )
        CUtlDict<CMapListItem,int>::Insert(this: &this->m_Items, pName: sz, element: &item);
    }
  }
  Sys_FindClose();
  v4 = realtime;
  this->m_bDirty = true;
  this->m_flLastRefreshTime = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1018EB50
// Name: public: void CMapListManager::RefreshList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapListManager::RefreshList(CMapListManager *this)
{
  float m_flLastRefreshTime; // xmm0_4
  const char *i; // edi
  int v4; // eax
  IBaseFileSystem *v5; // ecx
  CMapListItem *p_elem; // edi
  int v7; // eax
  char mapwild[96]; // [esp+4h] [ebp-D4h] BYREF
  char sz[96]; // [esp+64h] [ebp-74h] BYREF
  CUtlMap<char const *,CMapListItem,int>::Node_t search; // [esp+C4h] [ebp-14h] BYREF
  CMapListItem item; // [esp+D0h] [ebp-8h] BYREF

  m_flLastRefreshTime = this->m_flLastRefreshTime;
  if ( m_flLastRefreshTime == -1.0 )
  {
    CMapListManager::BuildList(this);
    return;
  }
  if ( (float)(m_flLastRefreshTime + 60.0) <= realtime )
  {
    _ConDMsg(a1: "Refreshing map list...\n");
    V_strncpy(pDest: mapwild, pSrc: "maps/*.bsp", maxLen: 96);
    for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
          i != nullptr;
          i = Sys_FindNext(basename: nullptr, namelength: 0) )
    {
      if ( V_stristr(pStr: i, pSearch: ".360.bsp") == nullptr )
      {
        V_snprintf(pDest: sz, maxLen: 96, pFormat: "maps/%s", i);
        search.elem.m_nValid = 1;
        search.elem.m_lFileTimestamp = 0;
        search.key = sz;
        v4 = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Find(
               this: &this->m_Items.m_Elements.m_Tree,
               &search);
        v5 = &g_pFileSystem->IBaseFileSystem;
        if ( v4 == -1 )
        {
          item.m_lFileTimestamp = v5->GetFileTime(this: v5, a2: sz, a3: nullptr);
          item.m_nValid = 1;
          CUtlDict<CMapListItem,int>::Insert(this: &this->m_Items, pName: sz, element: &item);
LABEL_10:
          this->m_bDirty = true;
          continue;
        }
        p_elem = &this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
        v7 = v5->GetFileTime(this: v5, a2: sz, a3: nullptr);
        if ( p_elem->m_lFileTimestamp != v7 )
        {
          p_elem->m_lFileTimestamp = v7;
          p_elem->m_nValid = 1;
          goto LABEL_10;
        }
      }
    }
    Sys_FindClose();
    this->m_flLastRefreshTime = realtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ECA0
// Name: MapList_CountMaps
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapList_CountMaps(const char *pszSubString, bool listobsolete, int *maxitemlength)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int> *m_pMemory; // edx
  int i; // esi
  const char *key; // ebx
  int m_nValid; // edi
  const char *v7; // eax
  signed int v8; // ecx
  unsigned int v9; // eax
  int substringlength; // [esp+0h] [ebp-8h]
  int count; // [esp+4h] [ebp-4h]
  int showOutdated; // [esp+14h] [ebp+Ch]

  CMapListManager::RefreshList(this: &g_MapListMgr);
  *maxitemlength = 0;
  substringlength = 0;
  if ( pszSubString != nullptr && *pszSubString != 0 )
    substringlength = strlen(pszSubString);
  count = 0;
  showOutdated = listobsolete;
  m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
  do
  {
    for ( i = 0; i < g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements; ++i )
    {
      if ( i < 0
        || i >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || i > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_19;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1066C608 = -1;
        dword_1066C60C = -1;
        dword_1066C610 = 1;
      }
      if ( m_pMemory[i].m_Left == i )
LABEL_19:
        key = "Invalid!!!";
      else
        key = m_pMemory[i].m_Data.key;
      if ( i < 0
        || i >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || i > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_21;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1066C608 = -1;
        dword_1066C60C = -1;
        dword_1066C610 = 1;
      }
      if ( m_pMemory[i].m_Left == i )
LABEL_21:
        m_nValid = 0;
      else
        m_nValid = m_pMemory[i].m_Data.elem.m_nValid;
      if ( substringlength != 0 )
      {
        v7 = V_stristr(pStr: key + 5, pSearch: pszSubString);
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( v7 == nullptr )
          continue;
      }
      if ( m_nValid != 0 )
      {
        v8 = strlen(key + 5) + 1;
        v9 = *maxitemlength;
        if ( *maxitemlength <= v8 )
          v9 = strlen(key + 5) + 1;
        ++count;
        *maxitemlength = v9;
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
      }
    }
    --showOutdated;
  }
  while ( showOutdated >= 0 );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1018EEA0
// Name: int _Host_Map_f_CompletionFunc(char const __near *,char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl _Host_Map_f_CompletionFunc(const char *cmdname, const char *partial, char (*commands)[64])
{
  const char *v3; // esi
  int result; // eax
  int v5; // edi
  int v6; // edi
  char *v7; // esi
  int v8; // ecx
  bool v9; // zf
  char old[64]; // [esp+8h] [ebp-44h] BYREF
  int longest; // [esp+48h] [ebp-4h] BYREF
  int count; // [esp+58h] [ebp+Ch]

  v3 = partial;
  if ( _V_strstr(s1: partial, search: cmdname) != nullptr )
    v3 = &partial[strlen(cmdname)];
  longest = 0;
  if ( MapList_CountMaps(pszSubString: v3, listobsolete: false, maxitemlength: &longest) >= 64 )
  {
    count = 64;
    v5 = 64;
  }
  else
  {
    result = MapList_CountMaps(pszSubString: v3, listobsolete: false, maxitemlength: &longest);
    v5 = result;
    count = result;
    if ( result <= 0 )
      return result;
  }
  MapList_ListMaps(
    pszSubString: v3,
    listobsolete: false,
    verbose: false,
    maxcount: 64,
    maxitemlength: longest,
    maplist: commands);
  if ( v5 <= 0 )
    return v5;
  v6 = 0;
  v7 = (char *)commands;
  longest = count;
  do
  {
    V_strncpy(pDest: old, pSrc: v7, maxLen: 64);
    V_snprintf(pDest: v7, maxLen: 64, pFormat: "%s%s", cmdname, old);
    v8 = v6 + strlen(v7);
    v6 += 64;
    v7 += 64;
    v9 = longest-- == 1;
    (*commands)[v8 - 4] = 0;
  }
  while ( !v9 );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1018EFB0
// Name: Host_SSMap_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_SSMap_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "ss_map ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018EFD0
// Name: Host_Map_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Map_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018EFF0
// Name: Host_Background_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Background_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map_background ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F010
// Name: Host_Map_Commentary_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Map_Commentary_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map_commentary ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F030
// Name: Host_Changelevel_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Changelevel_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "changelevel ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F050
// Name: Host_Changelevel2_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Changelevel2_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "changelevel2 ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F070
// Name: Host_Maps_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Maps_f(const CCommand *args)
{
  const char *v1; // esi
  int v2; // eax

  v1 = nullptr;
  if ( args->m_nArgc != 2 )
  {
    if ( args->m_nArgc != 3 )
    {
      ConMsg(a1: "Usage:  maps <substring>\nmaps * for full listing\n");
      return;
    }
    goto LABEL_8;
  }
  v1 = args->m_ppArgv[1];
  if ( v1 != nullptr && *v1 != 0 )
  {
    if ( *v1 == 42 )
      v1 = nullptr;
LABEL_8:
    args = nullptr;
    v2 = MapList_CountMaps(pszSubString: v1, listobsolete: true, maxitemlength: (int *)&args);
    if ( v2 > 0 )
      MapList_ListMaps(
        pszSubString: v1,
        listobsolete: true,
        verbose: true,
        maxcount: v2,
        maxitemlength: 0,
        maplist: nullptr);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1018EAE0
// Name: MapList_ListMaps
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapList_ListMaps(
        const char *pszSubString,
        bool listobsolete,
        bool verbose,
        int maxcount,
        int maxitemlength,
        char (*maplist)[64])
{
  int v6; // ebx
  int v7; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int> *m_pMemory; // edi
  int m_nValid; // edi
  char pDest[32]; // [esp+4h] [ebp-30h] BYREF
  int substringlength; // [esp+24h] [ebp-10h]
  int showOutdated; // [esp+28h] [ebp-Ch]
  char *v14; // [esp+2Ch] [ebp-8h]
  int count; // [esp+30h] [ebp-4h]
  const char *mapname; // [esp+40h] [ebp+Ch]

  v6 = 0;
  substringlength = 0;
  if ( pszSubString != nullptr && *pszSubString != 0 )
    substringlength = strlen(pszSubString);
  if ( verbose )
    ConMsg(a1: "-------------\n");
  count = 0;
  showOutdated = listobsolete;
  while ( v6 < maxcount )
  {
    v7 = 0;
    if ( g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements > 0 )
    {
      v14 = &(*maplist)[64 * v6];
      while ( 1 )
      {
        if ( v6 >= maxcount )
          goto LABEL_44;
        if ( v7 < 0
          || v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          || v7 > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
        {
          break;
        }
        if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1066C608 = -1;
          dword_1066C60C = -1;
          dword_1066C610 = 1;
        }
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Left == v7 )
          goto LABEL_25;
        mapname = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.key;
LABEL_18:
        if ( v7 < 0
          || v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          || v7 > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
        {
          goto LABEL_27;
        }
        if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1066C608 = -1;
          dword_1066C60C = -1;
          dword_1066C610 = 1;
        }
        if ( m_pMemory[v7].m_Left == v7 )
LABEL_27:
          m_nValid = 0;
        else
          m_nValid = m_pMemory[v7].m_Data.elem.m_nValid;
        if ( substringlength == 0 || V_stristr(pStr: mapname + 5, pSearch: pszSubString) != nullptr )
        {
          if ( verbose )
          {
            pDest[0] = 0;
            if ( m_nValid != 0 )
            {
              if ( m_nValid == 1 )
                V_strncpy(pDest, pSrc: "PENDING:  ", maxLen: 32);
            }
            else
            {
              V_strncpy(pDest, pSrc: "OUTDATED:  ", maxLen: 32);
            }
            if ( (m_nValid != 0) != (showOutdated != 0) )
              ConMsg(a1: "%s %s %s\n", pDest, "(fs)", mapname + 5);
          }
          if ( m_nValid != 0 )
          {
            if ( maxitemlength != 0 )
              V_strncpy(pDest: v14, pSrc: mapname + 5, maxLen: maxitemlength);
            ++count;
            v14 += 64;
          }
          v6 = count;
        }
        if ( ++v7 >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements )
          goto LABEL_44;
      }
      m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
LABEL_25:
      mapname = "Invalid!!!";
      goto LABEL_18;
    }
LABEL_44:
    if ( --showOutdated < 0 )
      return v6;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1018EE50
// Name: private: void CMapListManager::BuildList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapListManager::BuildList(CMapListManager *this)
{
  const char *i; // esi
  int v3; // eax
  float v4; // xmm0_4
  char mapwild[96]; // [esp+Ch] [ebp-D4h] BYREF
  char sz[96]; // [esp+6Ch] [ebp-74h] BYREF
  CUtlMap<char const *,CMapListItem,int>::Node_t search; // [esp+CCh] [ebp-14h] BYREF
  CMapListItem item; // [esp+D8h] [ebp-8h] BYREF

  CUtlDict<CMapListItem,int>::RemoveAll(this: &this->m_Items);
  this->m_bDirty = false;
  V_snprintf(pDest: mapwild, maxLen: 96, pFormat: "maps/*.%sbsp", defaultValue);
  for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(basename: nullptr, namelength: 0) )
  {
    if ( V_stristr(pStr: i, pSearch: ".360.bsp") == nullptr )
    {
      V_snprintf(pDest: sz, maxLen: 96, pFormat: "maps/%s", i);
      v3 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: sz, a3: nullptr);
      search.key = sz;
      item.m_lFileTimestamp = v3;
      item.m_nValid = 1;
      search.elem.m_nValid = 1;
      search.elem.m_lFileTimestamp = 0;
      if ( CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Find(
             this: &this->m_Items.m_Elements.m_Tree,
             &search) == -1 )
        CUtlDict<CMapListItem,int>::Insert(this: &this->m_Items, pName: sz, element: &item);
    }
  }
  Sys_FindClose();
  v4 = realtime;
  this->m_bDirty = true;
  this->m_flLastRefreshTime = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1018EF50
// Name: public: void CMapListManager::RefreshList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapListManager::RefreshList(CMapListManager *this)
{
  float m_flLastRefreshTime; // xmm0_4
  const char *i; // edi
  int v4; // eax
  IBaseFileSystem *v5; // ecx
  CMapListItem *p_elem; // edi
  int v7; // eax
  char mapwild[96]; // [esp+4h] [ebp-D4h] BYREF
  char sz[96]; // [esp+64h] [ebp-74h] BYREF
  CUtlMap<char const *,CMapListItem,int>::Node_t search; // [esp+C4h] [ebp-14h] BYREF
  CMapListItem item; // [esp+D0h] [ebp-8h] BYREF

  m_flLastRefreshTime = this->m_flLastRefreshTime;
  if ( m_flLastRefreshTime == -1.0 )
  {
    CMapListManager::BuildList(this);
    return;
  }
  if ( (float)(m_flLastRefreshTime + 60.0) <= realtime )
  {
    _ConDMsg(a1: "Refreshing map list...\n");
    V_strncpy(pDest: mapwild, pSrc: "maps/*.bsp", maxLen: 96);
    for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
          i != nullptr;
          i = Sys_FindNext(basename: nullptr, namelength: 0) )
    {
      if ( V_stristr(pStr: i, pSearch: ".360.bsp") == nullptr )
      {
        V_snprintf(pDest: sz, maxLen: 96, pFormat: "maps/%s", i);
        search.elem.m_nValid = 1;
        search.elem.m_lFileTimestamp = 0;
        search.key = sz;
        v4 = CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Find(
               this: &this->m_Items.m_Elements.m_Tree,
               &search);
        v5 = &g_pFileSystem->IBaseFileSystem;
        if ( v4 == -1 )
        {
          item.m_lFileTimestamp = v5->GetFileTime(this: v5, a2: sz, a3: nullptr);
          item.m_nValid = 1;
          CUtlDict<CMapListItem,int>::Insert(this: &this->m_Items, pName: sz, element: &item);
LABEL_10:
          this->m_bDirty = true;
          continue;
        }
        p_elem = &this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
        v7 = v5->GetFileTime(this: v5, a2: sz, a3: nullptr);
        if ( p_elem->m_lFileTimestamp != v7 )
        {
          p_elem->m_lFileTimestamp = v7;
          p_elem->m_nValid = 1;
          goto LABEL_10;
        }
      }
    }
    Sys_FindClose();
    this->m_flLastRefreshTime = realtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F0A0
// Name: MapList_CountMaps
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapList_CountMaps(const char *pszSubString, bool listobsolete, int *maxitemlength)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int> *m_pMemory; // edx
  int i; // esi
  const char *key; // ebx
  int m_nValid; // edi
  const char *v7; // eax
  signed int v8; // ecx
  unsigned int v9; // eax
  int substringlength; // [esp+0h] [ebp-8h]
  int count; // [esp+4h] [ebp-4h]
  int showOutdated; // [esp+14h] [ebp+Ch]

  CMapListManager::RefreshList(this: &g_MapListMgr);
  *maxitemlength = 0;
  substringlength = 0;
  if ( pszSubString != nullptr && *pszSubString != 0 )
    substringlength = strlen(pszSubString);
  count = 0;
  showOutdated = listobsolete;
  m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
  do
  {
    for ( i = 0; i < g_MapListMgr.m_Items.m_Elements.m_Tree.m_NumElements; ++i )
    {
      if ( i < 0
        || i >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || i > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_19;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1066C608 = -1;
        dword_1066C60C = -1;
        dword_1066C610 = 1;
      }
      if ( m_pMemory[i].m_Left == i )
LABEL_19:
        key = "Invalid!!!";
      else
        key = m_pMemory[i].m_Data.key;
      if ( i < 0
        || i >= g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || i > g_MapListMgr.m_Items.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_21;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1066C608 = -1;
        dword_1066C60C = -1;
        dword_1066C610 = 1;
      }
      if ( m_pMemory[i].m_Left == i )
LABEL_21:
        m_nValid = 0;
      else
        m_nValid = m_pMemory[i].m_Data.elem.m_nValid;
      if ( substringlength != 0 )
      {
        v7 = V_stristr(pStr: key + 5, pSearch: pszSubString);
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( v7 == nullptr )
          continue;
      }
      if ( m_nValid != 0 )
      {
        v8 = strlen(key + 5) + 1;
        v9 = *maxitemlength;
        if ( *maxitemlength <= v8 )
          v9 = strlen(key + 5) + 1;
        ++count;
        *maxitemlength = v9;
        m_pMemory = g_MapListMgr.m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
      }
    }
    --showOutdated;
  }
  while ( showOutdated >= 0 );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1018F2A0
// Name: int _Host_Map_f_CompletionFunc(char const __near *,char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl _Host_Map_f_CompletionFunc(const char *cmdname, const char *partial, char (*commands)[64])
{
  const char *v3; // esi
  int result; // eax
  int v5; // edi
  int v6; // edi
  char *v7; // esi
  int v8; // ecx
  bool v9; // zf
  char old[64]; // [esp+8h] [ebp-44h] BYREF
  int longest; // [esp+48h] [ebp-4h] BYREF
  int count; // [esp+58h] [ebp+Ch]

  v3 = partial;
  if ( _V_strstr(s1: partial, search: cmdname) != nullptr )
    v3 = &partial[strlen(cmdname)];
  longest = 0;
  if ( MapList_CountMaps(pszSubString: v3, listobsolete: false, maxitemlength: &longest) >= 64 )
  {
    count = 64;
    v5 = 64;
  }
  else
  {
    result = MapList_CountMaps(pszSubString: v3, listobsolete: false, maxitemlength: &longest);
    v5 = result;
    count = result;
    if ( result <= 0 )
      return result;
  }
  MapList_ListMaps(
    pszSubString: v3,
    listobsolete: false,
    verbose: false,
    maxcount: 64,
    maxitemlength: longest,
    maplist: commands);
  if ( v5 <= 0 )
    return v5;
  v6 = 0;
  v7 = (char *)commands;
  longest = count;
  do
  {
    V_strncpy(pDest: old, pSrc: v7, maxLen: 64);
    V_snprintf(pDest: v7, maxLen: 64, pFormat: "%s%s", cmdname, old);
    v8 = v6 + strlen(v7);
    v6 += 64;
    v7 += 64;
    v9 = longest-- == 1;
    (*commands)[v8 - 4] = 0;
  }
  while ( !v9 );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1018F3B0
// Name: Host_SSMap_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_SSMap_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "ss_map ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F3D0
// Name: Host_Map_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Map_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F3F0
// Name: Host_Background_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Background_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map_background ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F410
// Name: Host_Map_Commentary_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Map_Commentary_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "map_commentary ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F430
// Name: Host_Changelevel_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Changelevel_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "changelevel ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F450
// Name: Host_Changelevel2_f_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_Changelevel2_f_CompletionFunc(const char *partial, char (*commands)[64])
{
  return _Host_Map_f_CompletionFunc(cmdname: "changelevel2 ", partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1018F470
// Name: Host_Maps_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Maps_f(const CCommand *args)
{
  const char *v1; // esi
  int v2; // eax

  v1 = nullptr;
  if ( args->m_nArgc != 2 )
  {
    if ( args->m_nArgc != 3 )
    {
      ConMsg(a1: "Usage:  maps <substring>\nmaps * for full listing\n");
      return;
    }
    goto LABEL_8;
  }
  v1 = args->m_ppArgv[1];
  if ( v1 != nullptr && *v1 != 0 )
  {
    if ( *v1 == 42 )
      v1 = nullptr;
LABEL_8:
    args = nullptr;
    v2 = MapList_CountMaps(pszSubString: v1, listobsolete: true, maxitemlength: (int *)&args);
    if ( v2 > 0 )
      MapList_ListMaps(
        pszSubString: v1,
        listobsolete: true,
        verbose: true,
        maxcount: v2,
        maxitemlength: 0,
        maplist: nullptr);
  }
}

} // namespace engine_xlsp
