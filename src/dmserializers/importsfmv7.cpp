// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv7.cpp
// Functions: 4
// ============================================================

#include "dmserializers\importsfmv7.h"

//------------------------------------------------------------------------------
// Address: 0x004554E0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00455500
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CDmElement::GetHandle(this: v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004556F0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x00455AB0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0046AEE0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x0046AF00
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B0F0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x0046BA80
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004A76B0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7B30
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x004A7B50
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7D40
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B78A0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x104B78C0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B7AB0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x104B9880
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV7::BuildList(
        CImportSFMV9 *this@<ecx>,
        const char *a2@<edi>,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v4; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v16; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v16 = this;
  if ( pElement != nullptr )
  {
    v4 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v4,
        a2,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v6 = Attribute->m_nFlags & 0x1F;
          if ( v6 == 1 )
          {
            v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
            v9 = v8;
            if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
              v9 = nullptr;
            CImportSFMV7::BuildList(this: v16, pElement: v9, list: v4);
          }
          else if ( v6 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v12 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
                v14 = v13;
                if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                  v14 = nullptr;
                CImportSFMV7::BuildList(this: v16, pElement: v14, list);
                if ( ++v12 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v4 = list;
        }
      }
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0048DC90
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x0048DCB0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = (CDmElement *)v10;
          if ( v10 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CDmElement::GetHandle(this: v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DEA0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x0048FC70
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  int v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  int v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: v6->m_Storage.m_Handle);
            v8 = (CDmElement *)v7;
            if ( v7 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) == 0 )
            {
              v8 = nullptr;
            }
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = (CDmElement *)v12;
                if ( v12 == 0
                  || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                       a1: v12,
                       a2: CDmElement::m_classType.u) == 0 )
                {
                  v13 = nullptr;
                }
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00511880
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x005118A0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CVTFTexture::MipCount(this: (CVTFTexture *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511A90
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x00512030
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV7::BuildList(
        CImportSFMV9 *this@<ecx>,
        const char *a2@<edi>,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v4; // ebx
  CDmAttribute *v5; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v16; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v16 = this;
  if ( pElement != nullptr )
  {
    v4 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v4,
        a2,
        insert: &pElement);
      v5 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
      pAttribute = v5;
      if ( v5 != nullptr )
      {
        while ( 1 )
        {
          v6 = v5->m_nFlags & 0x1F;
          if ( v6 == 1 )
          {
            v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v5);
            v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
            v9 = v8;
            if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
              v9 = nullptr;
            CImportSFMV7::BuildList(this: v16, pElement: v9, list: v4);
          }
          else if ( v6 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (v5->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = v5;
              m_pData = (DmElementArray_t *)v5->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v12 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
                v14 = v13;
                if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                  v14 = nullptr;
                CImportSFMV7::BuildList(this: v16, pElement: v14, list);
                if ( ++v12 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            v5 = pAttribute;
          }
          pAttribute = v5->m_pNext;
          if ( pAttribute == nullptr )
            break;
          v5 = pAttribute;
          v4 = list;
        }
      }
    }
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D1E90
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x004D1EB0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = (CDmElement *)v10;
          if ( v10 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D20A0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x004D2A30
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  int v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  int v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: v6->m_Storage.m_Handle);
            v8 = (CDmElement *)v7;
            if ( v7 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) == 0 )
            {
              v8 = nullptr;
            }
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = (CDmElement *)v12;
                if ( v12 == 0
                  || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                       a1: v12,
                       a2: CDmElement::m_classType.u) == 0 )
                {
                  v13 = nullptr;
                }
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00456FB0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00456FD0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CCodecBuffer_Block::GetBufferType(this: v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004571C0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x00457580
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00458AB0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00458AD0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458CC0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458E20
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00463810
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00463890
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  const char *v3; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi
  CDmElement *v6; // edi
  CDmAttribute *v7; // esi
  int m_Size; // ebx
  int i; // edi
  CDmElement *v10; // esi
  DmElementHandle_t src; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+10h] [ebp-18h] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+18h] [ebp-10h] BYREF
  CDmrElementArray<CDmElement> presets; // [esp+20h] [ebp-8h] BYREF

  v2 = pElement;
  if ( pElement != nullptr )
  {
    v3 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElement->m_Type);
    if ( _stricmp(a1: 0, a2: (unsigned int)pElement, dst: v3, src: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&presetGroupArray);
        v5 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v5 != nullptr
           || (v5 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v5, typeSymbol: CDmElement::m_classType.m_Id),
               v5 != nullptr))
          && (v5->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v5;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v5->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v6 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v6, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&presets);
        if ( v6 != nullptr
          && ((v7 = CDmElement::FindAttribute(this: v6, pAttributeName: "presets")) != nullptr
           || (v7 = CDmElement::CreateAttribute(this: v6, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v7, typeSymbol: CDmElement::m_classType.m_Id),
               v7 != nullptr))
          && (v7->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v7;
          presets.m_pStorage = (DmElementArray_t *)v7->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v6);
        m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType.m_Id) )
          {
            CDmElement::SetType(this: v10, pType: "DmePreset");
            src = CDmElement::GetHandle(this: v10);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463A90
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: *(CDmElement **)(fixlist.m_Elements.m_nAllocationCount + 20 * i + 16));
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

//------------------------------------------------------------------------------
// Address: 0x00463F10
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        KeyValues *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // edi
  CDmAttribute *i; // ebp
  int v5; // eax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *m_pData; // eax
  int m_nFlags; // ebx
  int v10; // esi
  CDmElement *v11; // edi
  CDmrElementArray<CDmElement> array; // [esp+8h] [ebp-Ch] BYREF
  CDmAttribute *v13; // [esp+10h] [ebp-4h]

  array.m_pStorage = (DmElementArray_t *)this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: (CDmElement *const *)&pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: (CDmElement *const *)&pElement);
      for ( i = (CDmAttribute *)KeyValues::GetFirstSubKey(this: pElement); i != nullptr; i = i->m_pNext )
      {
        v5 = i->m_nFlags & 0x1F;
        if ( v5 == 1 )
        {
          v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: i);
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType.m_Id) )
            v7 = nullptr;
          CImportSFMV7::BuildList(this: (CImportSFMV9 *)array.m_pStorage, pElement: v7, list: v3);
        }
        else if ( v5 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
          if ( (i->m_nFlags & 0x1F) == 0xF )
          {
            v13 = i;
            m_pData = (CDmAttribute *)i->m_pData;
          }
          else
          {
            v13 = nullptr;
            m_pData = nullptr;
          }
          array.m_pAttribute = m_pData;
          m_nFlags = m_pData->m_nFlags;
          v10 = 0;
          if ( m_nFlags > 0 )
          {
            while ( 1 )
            {
              v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v10));
              if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType.m_Id) )
                v11 = nullptr;
              CImportSFMV7::BuildList(this: (CImportSFMV9 *)array.m_pStorage, pElement: v11, list);
              if ( ++v10 >= m_nFlags )
                break;
              m_pData = array.m_pAttribute;
            }
            v3 = list;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463830
// Name: class CDmElement __near * CreateElement<class CDmElement>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl CreateElement<CDmElement>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // esi

  v3 = g_pDataModel->CreateElement_2(
         this: g_pDataModel,
         a2: CDmElement::m_classType.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType.m_Id) )
    return v4;
  else
    return nullptr;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00456F40
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00456F60
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CDmElement::GetHandle(this: v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457150
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x004576E0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0045BBB0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C030
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x0045C050
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C240
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B2010
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x004B2030
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = (CDmElement *)v10;
          if ( v10 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2220
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x004B25E0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  int v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  int v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: v6->m_Storage.m_Handle);
            v8 = (CDmElement *)v7;
            if ( v7 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) == 0 )
            {
              v8 = nullptr;
            }
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = (CDmElement *)v12;
                if ( v12 == 0
                  || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                       a1: v12,
                       a2: CDmElement::m_classType.u) == 0 )
                {
                  v13 = nullptr;
                }
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0045CA80
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x0045CAA0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (int)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CC90
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x0045D220
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004CB370
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  int v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  int v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: v6->m_Storage.m_Handle);
            v8 = (CDmElement *)v7;
            if ( v7 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmElement::m_classType.u) == 0 )
            {
              v8 = nullptr;
            }
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = (CDmElement *)v12;
                if ( v12 == 0
                  || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                       a1: v12,
                       a2: CDmElement::m_classType.u) == 0 )
                {
                  v13 = nullptr;
                }
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB5A0
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x004CB5C0
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = (CDmElement *)v10;
          if ( v10 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB7B0
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00467320
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x00467340
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467530
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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

//------------------------------------------------------------------------------
// Address: 0x00469300
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *Attribute; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      Attribute = CDmElement::FirstAttribute(this: pElement);
      pAttribute = Attribute;
      if ( Attribute != nullptr )
      {
        while ( 1 )
        {
          v5 = Attribute->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (Attribute->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = Attribute;
              m_pData = (DmElementArray_t *)Attribute->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            Attribute = pAttribute;
          }
          pAttribute = Attribute->m_pNext;
          if ( pAttribute == nullptr )
            break;
          Attribute = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0055EAE0
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *v4; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      v4 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
      pAttribute = v4;
      if ( v4 != nullptr )
      {
        while ( 1 )
        {
          v5 = v4->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v4);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (v4->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = v4;
              m_pData = (DmElementArray_t *)v4->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            v4 = pAttribute;
          }
          pAttribute = v4->m_pNext;
          if ( pAttribute == nullptr )
            break;
          v4 = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055ED10
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x0055ED30
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055EF20
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x10089A20
// Name: void InstallSFMV7Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV7Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV7);
}

//------------------------------------------------------------------------------
// Address: 0x10089A40
// Name: private: void CImportSFMV7::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::FixupElement(CImportSFMV7 *this, CDmElement *pElement)
{
  CDmElement *v2; // edi
  int m_Size; // ebx
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CDmElement *v7; // edi
  CDmAttribute *v8; // esi
  int i; // edi
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> presets; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> presetGroupArray; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> srcPresets; // [esp+1Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+24h] [ebp-4h] BYREF

  v2 = pElement;
  m_Size = 0;
  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeAnimationSet") == 0 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcPresets);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "presets");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        srcPresets.m_pAttribute = Attribute;
        srcPresets.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupArray);
        v6 = CDmElement::FindAttribute(this: pElement, pAttributeName: "presetGroups");
        if ( (v6 != nullptr
           || (v6 = CDmElement::CreateAttribute(
                      this: pElement,
                      pAttributeName: "presetGroups",
                      type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
               v6 != nullptr))
          && (v6->m_nFlags & 0x1F) == 0xF )
        {
          presetGroupArray.m_pAttribute = v6;
          presetGroupArray.m_pStorage = (DmElementArray_t *)v6->m_pData;
        }
        else
        {
          presetGroupArray.m_pAttribute = nullptr;
          presetGroupArray.m_pStorage = nullptr;
        }
        v7 = CreateElement<CDmElement>(pObjectName: "custom", fileid: pElement->m_fileId, pObjectID: nullptr);
        CDmElement::SetType(this: v7, pType: "DmePresetGroup");
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
        if ( v7 != nullptr
          && ((v8 = CDmElement::FindAttribute(this: v7, pAttributeName: "presets")) != nullptr
           || (v8 = CDmElement::CreateAttribute(this: v7, pAttributeName: "presets", type: AT_FIRST_ARRAY_TYPE),
               CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
               v8 != nullptr))
          && (v8->m_nFlags & 0x1F) == 0xF )
        {
          presets.m_pAttribute = v8;
          presets.m_pStorage = (DmElementArray_t *)v8->m_pData;
        }
        else
        {
          presets.m_pAttribute = nullptr;
          presets.m_pStorage = nullptr;
        }
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &presetGroupArray,
          pValue: (DmElementHandle_t)v7);
        if ( srcPresets.m_pAttribute != nullptr )
          m_Size = srcPresets.m_pStorage->m_Size;
        for ( i = 0; i < m_Size; ++i )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: srcPresets.m_pStorage->m_Memory.m_pMemory[i]);
          v11 = v10;
          if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CDmElement::SetType(this: v11, pType: "DmePreset");
            src = CVTFTexture::MipCount(this: (CVTFTexture *)v11);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &presets,
              &src);
          }
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &srcPresets);
        v2 = pElement;
      }
      else
      {
        srcPresets.m_pAttribute = nullptr;
        srcPresets.m_pStorage = nullptr;
      }
      CDmElement::RemoveAttribute(this: v2, pAttributeName: "presets");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089C30
// Name: private: void CImportSFMV7::BuildList(class CDmElement __near *,class CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV7::BuildList(
        CImportSFMV9 *this,
        CDmElement *pElement,
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *list)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *v3; // ebx
  CDmAttribute *v4; // edi
  __int16 v5; // ax
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v11; // edi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV9 *v15; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v15 = this;
  if ( pElement != nullptr )
  {
    v3 = list;
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
           this: list,
           search: &pElement) == -1 )
    {
      CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        this: v3,
        insert: &pElement);
      v4 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
      pAttribute = v4;
      if ( v4 != nullptr )
      {
        while ( 1 )
        {
          v5 = v4->m_nFlags & 0x1F;
          if ( v5 == 1 )
          {
            v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v4);
            v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
            v8 = v7;
            if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
              v8 = nullptr;
            CImportSFMV7::BuildList(this: v15, pElement: v8, list: v3);
          }
          else if ( v5 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
            if ( (v4->m_nFlags & 0x1F) == 0xF )
            {
              array.m_pAttribute = v4;
              m_pData = (DmElementArray_t *)v4->m_pData;
              array.m_pStorage = m_pData;
              m_Size = m_pData->m_Size;
            }
            else
            {
              m_pData = nullptr;
              array.m_pAttribute = nullptr;
              array.m_pStorage = nullptr;
              m_Size = 0;
            }
            v11 = 0;
            if ( m_Size > 0 )
            {
              while ( 1 )
              {
                v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v11]);
                v13 = v12;
                if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmElement::m_classType) )
                  v13 = nullptr;
                CImportSFMV7::BuildList(this: v15, pElement: v13, list);
                if ( ++v11 >= m_Size )
                  break;
                m_pData = array.m_pStorage;
              }
            }
            v4 = pAttribute;
          }
          pAttribute = v4->m_pNext;
          if ( pAttribute == nullptr )
            break;
          v4 = pAttribute;
          v3 = list;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089D90
// Name: private: virtual bool CImportSFMV7::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV7::DoFixup(CImportSFMV7 *this, CDmElement *pSourceRoot)
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
    CImportSFMV7::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
