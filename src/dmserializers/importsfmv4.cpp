// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv4.cpp
// Functions: 3
// ============================================================

#include "dmserializers\importsfmv4.h"

//------------------------------------------------------------------------------
// Address: 0x00455D10
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00455D30
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = &defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455DE0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0046B5B0
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x0046B5D0
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = var;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B680
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004A8200
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x004A8220
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A82D0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B7F70
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x104B7F90
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = &var;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B8040
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, a2: (const char *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0048E360
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x0048E380
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = WindowName;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E430
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00511F50
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00511F80
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDefaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00512190
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, a2: (const char *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004D2560
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x004D2580
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDeltaStateName;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2630
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004577E0
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00457800
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004578B0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004592E0
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00459300
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, CDmElement *pElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = *(CDmElement **)CDmAttribute::GetValue<float>(this: Attribute);
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: (float *)&pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004593B0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDmxSerializationDictionary::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00464170
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00464190
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV4::FixupElement(
        CImportSFMV4 *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        float pElement)
{
  CDmElement *v4; // esi
  const char *v5; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v5 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: *(unsigned __int16 *)(LODWORD(pElement) + 44));
    if ( _stricmp(a1: a2, a2: a3, dst: v5, src: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v7 = CDmElement::FindAttribute(this: v4, pAttributeName: "bloomScale");
      if ( v7 != nullptr )
        v8 = (v7->m_nFlags & 0x1F) == 3 ? v7 : nullptr;
      else
        v8 = CDmElement::CreateAttribute(this: v4, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v8, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464240
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, KeyValues *pSourceRoot)
{
  int i; // esi
  void *m_nAllocationCount; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-28h] BYREF
  int v7; // [esp+30h] [ebp-4h]

  fixlist.m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements.m_nAllocationCount, 0, 12);
  fixlist.m_NumElements = -1;
  fixlist.m_FirstFree = 0;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_pElements = (UtlRBTreeNode_t<CDmElement *,int> *)-1;
  v7 = 0;
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
    CImportSFMV4::FixupElement(
      this,
      a2: 0,
      a3: (unsigned int)this,
      pElement: *(float *)(fixlist.m_Elements.m_nAllocationCount + 20 * i + 16));
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
// Address: 0x00457610
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00457630
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, CDmElement *pElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = *(CDmElement **)CDmAttribute::GetValue<float>(this: Attribute);
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: (const float *)&pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457840
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045C700
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x0045C720
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = &pParentName;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C7D0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B2840
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x004B2860
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, CDmElement *pElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = *(CDmElement **)CDmAttribute::GetValue<float>(this: Attribute);
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: (const float *)&pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2910
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045D150
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x0045D170
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, CDmElement *pElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = *(CDmElement **)CDmAttribute::GetValue<float>(this: Attribute);
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: (const float *)&pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D380
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004CBC70
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x004CBC90
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDeltaStateName;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBD40
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004679F0
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x00467A10
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, CDmElement *pElement)
{
  CDmElement *v2; // esi
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = *(CDmElement **)CDmAttribute::GetValue<float>(this: Attribute);
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: (const float *)&pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467AC0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0055F3E0
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x0055F400
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = var;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F4B0
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x1008A250
// Name: void InstallSFMV4Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV4Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV4);
}

//------------------------------------------------------------------------------
// Address: 0x1008A270
// Name: private: void CImportSFMV4::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV4::FixupElement(CImportSFMV4 *this, float pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // edi
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v3 = *(const char **)(LODWORD(pElement) + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeCamera") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "toneMapScale");
      pElement = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "bloomScale");
      if ( v5 != nullptr )
        v6 = (v5->m_nFlags & 0x1F) != 3 ? nullptr : v5;
      else
        v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "bloomScale", type: AT_FLOAT);
      CDmAttribute::SetValue<float>(this: v6, value: &pElement);
      value = 1.0;
      CDmAttribute::SetValue<float>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A320
// Name: private: virtual bool CImportSFMV4::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV4::DoFixup(CImportSFMV4 *this, CDmElement *pSourceRoot)
{
  int i; // esi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // eax
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > fixlist; // [esp+Ch] [ebp-24h] BYREF

  fixlist.m_Root = -1;
  fixlist.m_FirstFree = -1;
  fixlist.m_LastAlloc.index = -1;
  fixlist.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  memset(&fixlist.m_Elements, 0, sizeof(fixlist.m_Elements));
  fixlist.m_NumElements = 0;
  fixlist.m_pElements = nullptr;
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV4::FixupElement(this, pElement: *(float *)&fixlist.m_Elements.m_pMemory[i].m_Data);
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
