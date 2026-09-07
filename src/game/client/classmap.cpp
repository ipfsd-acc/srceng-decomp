// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/classmap.cpp
// Functions: 5
// ============================================================

#include "game\client\classmap.h"

//------------------------------------------------------------------------------
// Address: 0x100A1E20
// Name: public: virtual class C_BaseEntity __near * CClassMap::CreateEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CClassMap::CreateEntity(CClassMap *this, const char *mapname)
{
  int m_NumElements; // ecx
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  classentry_t *p_elem; // esi
  int c; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_ClassDict.m_Elements.m_Tree.m_NumElements;
  v4 = 0;
  c = m_NumElements;
  if ( m_NumElements == 0 )
    return nullptr;
  while ( 1 )
  {
    m_pMemory = this->m_ClassDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    p_elem = &m_pMemory[(unsigned __int16)v4].m_Data.elem;
    if ( &m_pMemory[(unsigned __int16)v4] != (UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *)-12 )
      break;
LABEL_6:
    if ( ++v4 >= m_NumElements )
      return nullptr;
  }
  if ( _V_stricmp(s1: m_pMemory[(unsigned __int16)v4].m_Data.elem.mapname, s2: mapname) != 0
    || p_elem->factory == nullptr )
  {
    m_NumElements = c;
    goto LABEL_6;
  }
  return p_elem->factory();
}

//------------------------------------------------------------------------------
// Address: 0x100A1E90
// Name: public: virtual int CClassMap::GetClassSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClassMap::GetClassSize(CClassMap *this, const char *classname)
{
  int m_NumElements; // ecx
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int p_elem; // esi
  int c; // [esp+Ch] [ebp-4h]

  m_NumElements = this->m_ClassDict.m_Elements.m_Tree.m_NumElements;
  v4 = 0;
  c = m_NumElements;
  if ( m_NumElements == 0 )
    return -1;
  while ( 1 )
  {
    m_pMemory = this->m_ClassDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    p_elem = (int)&m_pMemory[(unsigned __int16)v4].m_Data.elem;
    if ( &m_pMemory[(unsigned __int16)v4] != (UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *)-12 )
      break;
LABEL_5:
    if ( ++v4 >= m_NumElements )
      return -1;
  }
  if ( _V_strcmp(s1: m_pMemory[(unsigned __int16)v4].m_Data.elem.mapname, s2: classname) != 0 )
  {
    m_NumElements = c;
    goto LABEL_5;
  }
  return *(_DWORD *)(p_elem + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100A2380
// Name: public: virtual char const __near * CClassMap::Lookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CClassMap::Lookup(CClassMap *this, const char *classname)
{
  unsigned __int16 v3; // ax
  CUtlMap<char const *,classentry_t,unsigned short>::Node_t search; // [esp+4h] [ebp-34h] BYREF

  if ( (_S6_25 & 1) == 0 )
  {
    _S6_25 |= 1u;
    lookup.mapname[0] = 0;
    lookup.factory = nullptr;
    lookup.size = -1;
  }
  if ( classname == nullptr )
    return nullptr;
  search.elem.mapname[0] = 0;
  search.elem.factory = nullptr;
  search.key = classname;
  search.elem.size = -1;
  v3 = CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ClassDict.m_Elements.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  lookup = this->m_ClassDict.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  return lookup.mapname;
}

//------------------------------------------------------------------------------
// Address: 0x100A25B0
// Name: public: virtual void CClassMap::Add(char const __near *,char const __near *,int,class C_BaseEntity __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClassMap::Add(
        CClassMap *this,
        char *mapname,
        const char *classname,
        int size,
        C_BaseEntity *(__cdecl *factory)())
{
  const char *v6; // eax
  unsigned __int16 v7; // ax
  CUtlMap<char const *,classentry_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-64h] BYREF
  classentry_t element; // [esp+40h] [ebp-30h] BYREF

  v6 = this->Lookup(this, a2: classname);
  if ( v6 != nullptr )
  {
    if ( V_strcasecmp(s1: mapname, s2: v6) == 0 )
      return;
    if ( classname != nullptr )
    {
      search.elem.mapname[0] = 0;
      search.elem.factory = nullptr;
      search.elem.size = -1;
      search.key = classname;
      v7 = CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_ClassDict.m_Elements.m_Tree,
             &search);
    }
    else
    {
      v7 = -1;
    }
    CUtlDict<classentry_t,unsigned short>::RemoveAt(this: &this->m_ClassDict, elem: v7);
  }
  element.mapname[0] = 0;
  element.factory = nullptr;
  element.size = -1;
  V_strncpy(pDest: element.mapname, pSrc: mapname, maxLen: 40);
  element.factory = factory;
  element.size = size;
  CUtlDict<classentry_t,unsigned short>::Insert(this: &this->m_ClassDict, pName: classname, &element);
}

//------------------------------------------------------------------------------
// Address: 0x100A2660
// Name: class IClassMap __near & GetClassMap(void)
// Source: json
//------------------------------------------------------------------------------
CClassMap *__cdecl GetClassMap()
{
  if ( (_S5_89 & 1) == 0 )
  {
    _S5_89 |= 1u;
    g_Classmap.__vftable = (CClassMap_vtbl *)&CClassMap::`vftable';
    g_Classmap.m_ClassDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    g_Classmap.m_ClassDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    g_Classmap.m_ClassDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    *(_DWORD *)&g_Classmap.m_ClassDict.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&g_Classmap.m_ClassDict.m_Elements.m_Tree.m_FirstFree = -1;
    g_Classmap.m_ClassDict.m_Elements.m_Tree.m_pElements = nullptr;
    g_Classmap.m_ClassDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    atexit(func: GetClassMap_::_2_::_dynamic_atexit_destructor_for__g_Classmap__);
  }
  return &g_Classmap;
}
