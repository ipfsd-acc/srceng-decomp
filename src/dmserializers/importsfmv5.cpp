// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv5.cpp
// Functions: 2
// ============================================================

#include "dmserializers\importsfmv5.h"

//------------------------------------------------------------------------------
// Address: 0x00455A90
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x00455C10
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0046B490
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x0046B4B0
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004A80E0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004A8100
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104B7E50
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x104B7E70
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportSFMV5::DoFixup@<al>(CImportSFMV5 *this@<ecx>, const char *a2@<edi>, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, a2, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0048E240
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x0048E260
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00511E30
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x00511E50
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportSFMV5::DoFixup@<al>(CImportSFMV5 *this@<ecx>, const char *a2@<edi>, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, a2, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D2440
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004D2460
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00457560
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004576E0
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004591C0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004591E0
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDmxSerializationDictionary::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00463EF0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x00464060
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, KeyValues *pSourceRoot)
{
  int i; // edi
  CDmElement *v3; // esi
  const char *v4; // eax
  void *m_nAllocationCount; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+8h] [ebp-28h] BYREF
  int v8; // [esp+2Ch] [ebp-4h]

  fixlist.m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements.m_nAllocationCount, 0, 12);
  fixlist.m_NumElements = -1;
  fixlist.m_FirstFree = 0;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = (UtlRBTreeNode_t<CDmElement *,int> *)-1;
  v8 = 0;
  CImportSFMV7::BuildList(
    (CImportSFMV9 *)this,
    pElement: pSourceRoot,
    list: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements,
              i) )
  {
    v3 = *(CDmElement **)(fixlist.m_Elements.m_nAllocationCount + 20 * i + 16);
    if ( v3 != nullptr )
    {
      v4 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: v3->m_Type);
      if ( _stricmp(a1: 0, a2: i, dst: v4, src: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: v3, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements);
  m_nAllocationCount = (void *)fixlist.m_Elements.m_nAllocationCount;
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Root >= 0 )
  {
    if ( fixlist.m_Elements.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)fixlist.m_Elements.m_nAllocationCount);
      m_nAllocationCount = nullptr;
      fixlist.m_Elements.m_nAllocationCount = 0;
    }
    fixlist.m_Elements.m_nGrowSize = 0;
  }
  fixlist.m_pElements = (UtlRBTreeNode_t<CDmElement *,int> *)-1;
  if ( fixlist.m_Root >= 0 && m_nAllocationCount != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  return 1;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x004574F0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x00457510
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0045C5E0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x0045C600
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B25C0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004B2740
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0045D030
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x0045D050
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004CBB50
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004CBB70
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004678D0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x004678F0
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0055F2C0
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x0055F2E0
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1008A130
// Name: void InstallSFMV5Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV5Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV5);
}

//------------------------------------------------------------------------------
// Address: 0x1008A150
// Name: private: virtual bool CImportSFMV5::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV5::DoFixup(CImportSFMV5 *this, CDmElement *pSourceRoot)
{
  int i; // edi
  CDmElement *m_Data; // esi
  const char *m_pAsString; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_Root = -1;
  fixlist.m_NumElements = 0;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    m_Data = fixlist.m_Elements.m_pMemory[i].m_Data;
    if ( m_Data != nullptr )
    {
      m_pAsString = m_Data->m_Type.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0 )
        CDmElement::SetType(this: m_Data, pType: "DmeProjectedLight");
    }
  }
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this: &fixlist);
  m_pMemory = fixlist.m_Elements.m_pMemory;
  fixlist.m_FirstFree = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 )
  {
    if ( fixlist.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fixlist.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      fixlist.m_Elements.m_pMemory = nullptr;
    }
    fixlist.m_Elements.m_nAllocationCount = 0;
  }
  fixlist.m_LastAlloc.index = -1;
  if ( fixlist.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace vtex_dll
