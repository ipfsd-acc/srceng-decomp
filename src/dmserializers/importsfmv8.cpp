// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv8.cpp
// Functions: 3
// ============================================================

#include "dmserializers\importsfmv8.h"

//------------------------------------------------------------------------------
// Address: 0x00455290
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004552B0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = &defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455410
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0046AC90
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x0046ACB0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = var;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AE10
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004A78E0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004A7900
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7A60
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B7650
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x104B7670
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = &var;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B77D0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0048DA40
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x0048DA60
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = WindowName;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = (CDmElement *)v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DBC0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00511630
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x00511650
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDefaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005117B0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList((CImportSFMV9 *)this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004D1C40
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004D1C60
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDeltaStateName;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = (CDmElement *)v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1DC0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00456D60
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x00456D80
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456EE0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00458860
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x00458880
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = str;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004589E0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00463540
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x00463560
// Name: public: class CDmAttribute __near * CDmElement::SetValue<float>(char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<float>(CDmElement *this, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 3 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FLOAT);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<float>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004635C0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV8::FixupElement(
        CImportSFMV8 *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        float pElement)
{
  CDmElement *v4; // esi
  const char *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *m_pData; // eax
  int m_nFlags; // ebx
  int v9; // edi
  CDmElement *v10; // esi
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+0h] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+8h] [ebp-4h]

  v4 = (CDmElement *)LODWORD(pElement);
  if ( pElement != 0.0 )
  {
    v5 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: *(unsigned __int16 *)(LODWORD(pElement) + 44));
    if ( _stricmp(a1: a2, a2: a3, dst: v5, src: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&srcControls.m_pAttribute);
      Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        v14 = Attribute;
        m_pData = (CDmAttribute *)Attribute->m_pData;
        srcControls.m_pAttribute = m_pData;
        m_nFlags = m_pData->m_nFlags;
        v9 = 0;
        if ( m_nFlags > 0 )
        {
          while ( 1 )
          {
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v9));
            if ( v10 != nullptr
              && v10->IsA(this: v10, a2: CDmElement::m_classType.m_Id)
              && !CDmElement::GetValue<bool>(this: v10, pAttributeName: "transform")->m_Storage )
            {
              pElement = 0.5;
              v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "defaultBalance");
              if ( v11 == nullptr || (v11->m_nFlags & 0x1F) != 3 )
                CDmElement::SetValue<float>(this: v10, pAttributeName: "defaultBalance", value: &pElement);
              pElement = 0.5;
              v12 = CDmElement::FindAttribute(this: v10, pAttributeName: "defaultMultilevel");
              if ( v12 == nullptr || (v12->m_nFlags & 0x1F) != 3 )
                CDmElement::SetValue<float>(this: v10, pAttributeName: "defaultMultilevel", value: &pElement);
              CDmElement::RemoveAttribute(this: v10, pAttributeName: "midpoint");
            }
            if ( ++v9 >= m_nFlags )
              break;
            m_pData = srcControls.m_pAttribute;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463720
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(
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
// Address: 0x00456CF0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x00456D10
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = &defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456E70
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045BDE0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x0045BE00
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = &pParentName;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BF60
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B1DC0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004B1DE0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = (CDmElement *)v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1F40
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045C830
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x0045C850
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = &pch;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C9B0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004CB1F0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004CB210
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = pDeltaStateName;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = (CDmElement *)v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB4D0
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004670D0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x004670F0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = Ptr;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(
                  this: v8,
                  pAttributeName: "defaultBalance",
                  value: (const float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467250
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0055E960
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x0055E980
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = var;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = (CDmaVar<bool> *)CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055EC40
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x100897D0
// Name: void InstallSFMV8Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV8Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV8);
}

//------------------------------------------------------------------------------
// Address: 0x100897F0
// Name: private: void CImportSFMV8::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV8::FixupElement(CImportSFMV8 *this, int pElement)
{
  CDmElement *v2; // esi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  DmElementArray_t *m_pData; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmrElementArray<CDmElement> srcControls; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (CDmElement *)pElement;
  if ( pElement != 0 )
  {
    v3 = *(const char **)(pElement + 52);
    if ( v3 == (const char *)-1 )
      v3 = defaultValue;
    if ( _V_stricmp(s1: v3, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcControls);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "controls");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcControls.m_pAttribute = Attribute;
        m_pData = (DmElementArray_t *)Attribute->m_pData;
        srcControls.m_pStorage = m_pData;
        v6 = 0;
        nCount = m_pData->m_Size;
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
            v8 = v7;
            if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
            {
              if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
              }
              v9 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
              if ( v9 != nullptr )
                v10 = CDmAttribute::GetValue<bool>(this: v9);
              else
                v10 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
              if ( !v10->m_Storage )
              {
                pElement = 1056964608;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultBalance", value: (float *)&pElement);
                value = 0.5;
                CDmElement::InitValue<float>(this: v8, pAttributeName: "defaultMultilevel", &value);
                CDmElement::RemoveAttribute(this: v8, pAttributeName: "midpoint");
              }
            }
            if ( ++v6 >= nCount )
              break;
            m_pData = srcControls.m_pStorage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089950
// Name: private: virtual bool CImportSFMV8::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV8::DoFixup(CImportSFMV8 *this, CDmElement *pSourceRoot)
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
    CImportSFMV8::FixupElement(this, pElement: (int)fixlist.m_Elements.m_pMemory[i].m_Data);
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
