// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv9.cpp
// Functions: 3
// ============================================================

#include "dmserializers\importsfmv9.h"

//------------------------------------------------------------------------------
// Address: 0x00453F40
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00454700
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004551C0
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00469A60
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00469A80
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x0046A100
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ABC0
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004A7310
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x004A7340
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7810
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B71F0
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x104B7210
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B7580
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0048C790
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x0048CEB0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D970
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00510390
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00510AA0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511560
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004D0A60
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x004D10B0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1B70
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00455AB0
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x004561D0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456C90
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00457630
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00457650
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00457CD0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458790
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00462300
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00462890
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV9::FixupElement(CImportSFMV9 *this@<ecx>, unsigned int a2@<ebx>, CDmElement *pElement)
{
  const char *v3; // esi
  CDmAttribute *Attribute; // eax
  double v5; // st7
  double v6; // st6
  CDmaVar<Vector4D> *v7; // edx
  int v8; // ecx
  double v9; // rt0
  double v10; // rt1
  double v11; // st6
  double v12; // st7
  double v13; // st5
  double v14; // rt2
  double v15; // st6
  double v16; // st7
  double v17; // st5
  double v18; // rtt
  double v19; // st5
  double v20; // rt1
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  Color color; // [esp+2h] [ebp-Ch]
  Color value; // [esp+6h] [ebp-8h] BYREF
  int v25; // [esp+Ah] [ebp-4h]

  if ( pElement != nullptr )
  {
    v3 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElement->m_Type);
    if ( _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmeLight") == 0
      || _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmeDirectionalLight") == 0
      || _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmeProjectedLight") == 0
      || _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmePointLight") == 0
      || _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmeSpotLight") == 0
      || _stricmp(a1: a2, a2: (unsigned int)pElement, dst: v3, src: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        value = 0;
        v5 = 255.0;
        v6 = 0.0;
        v7 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        v8 = 0;
        while ( 1 )
        {
          v10 = v6;
          v11 = v5;
          v12 = v10;
          if ( v11 >= *(&v7->m_Storage.x + v8) )
          {
            v14 = v11;
            v15 = v12;
            v16 = v14;
            v17 = v15 <= *(&v7->m_Storage.x + v8) ? *(&v7->m_Storage.x + v8) : v15;
            v18 = v17;
            v19 = v16;
            v12 = v15;
            v20 = v19;
            v13 = v18;
            v11 = v20;
          }
          else
          {
            v13 = v11;
          }
          ++v8;
          v25 = (int)v13;
          color._color[v8 + 3] = (int)v13;
          if ( v8 >= 4 )
            break;
          v9 = v11;
          v6 = v12;
          v5 = v9;
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "color");
        v21 = CDmElement::FindAttribute(this: pElement, pAttributeName: "color");
        if ( v21 != nullptr )
        {
          CDmAttribute::SetValue<Color>(this: (v21->m_nFlags & 0x1F) != 8 ? nullptr : v21, &value);
        }
        else
        {
          v22 = CDmElement::CreateAttribute(this: pElement, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v22, &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463450
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
    this,
    pElement: pSourceRoot,
    list: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: (CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *)&fixlist.m_Elements,
              i) )
  {
    CImportSFMV9::FixupElement(
      this,
      a2: 0,
      pElement: *(CDmElement **)(fixlist.m_Elements.m_nAllocationCount + 20 * i + 16));
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
// Address: 0x00455A10
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00456160
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456C20
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045A9E0
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x0045B0F0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BD10
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B1960
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x004B1980
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1CF0
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045B650
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x0045BCA0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C760
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004C9F40
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x004CA660
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB120
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00465E90
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x00465EC0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00466540
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  const Vector4D *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467000
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0055D730
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x0055D750
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x0055DDD0
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055E890
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x10088530
// Name: void InstallSFMV9Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV9Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV9);
}

//------------------------------------------------------------------------------
// Address: 0x10088C40
// Name: private: void CImportSFMV9::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV9::FixupElement(CImportSFMV9 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector4D> *v5; // eax
  int i; // ecx
  float v7; // xmm0_4
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeDirectionalLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmePointLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeSpotLight") == 0
      || _V_stricmp(s1: m_pAsString, s2: "DmeAmbientLight") == 0 )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xB )
      {
        pElement = nullptr;
        v5 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
        for ( i = 0; i < 4; ++i )
        {
          v7 = *(&v5->m_Storage.x + i);
          if ( v7 >= 0.0 )
          {
            if ( v7 > 255.0 )
              v7 = 255.0;
          }
          else
          {
            v7 = 0.0;
          }
          *((_BYTE *)&pElement + i) = (int)v7;
        }
        CDmElement::RemoveAttribute(this: v2, pAttributeName: "color");
        v8 = CDmElement::FindAttribute(this: v2, pAttributeName: "color");
        if ( v8 != nullptr )
        {
          CDmAttribute::SetValue<Color>(
            this: (v8->m_nFlags & 0x1F) != 8 ? nullptr : v8,
            value: (const Color *)&pElement);
        }
        else
        {
          v9 = CDmElement::CreateAttribute(this: v2, pAttributeName: "color", type: AT_COLOR);
          CDmAttribute::SetValue<Color>(this: v9, value: (const Color *)&pElement);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089700
// Name: private: virtual bool CImportSFMV9::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV9::DoFixup(CImportSFMV9 *this, CDmElement *pSourceRoot)
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
  CImportSFMV7::BuildList(this, pElement: pSourceRoot, list: &fixlist);
  for ( i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(this: &fixlist);
        i != -1;
        i = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
              this: &fixlist,
              i) )
  {
    CImportSFMV9::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
