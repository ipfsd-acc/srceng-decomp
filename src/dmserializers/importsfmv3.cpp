// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv3.cpp
// Functions: 6
// ============================================================

#include "dmserializers\importsfmv3.h"

//------------------------------------------------------------------------------
// Address: 0x00455EB0
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x00455ED0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_22 )
      return nullptr;
  }
  return off_4A97C0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x00455F20
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_4A97BC;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_22.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00455F60
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = &defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00456070
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004561E0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0046B750
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x0046B770
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_27 )
      return nullptr;
  }
  return off_5F5E80[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x0046B7C0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5F5E7C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_27.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B800
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = var;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x0046B910
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BBE0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004A83A0
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004A83C0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_72 )
      return nullptr;
  }
  return off_745A28[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004A8410
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_745A24;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_72.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8450
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x004A8560
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A86D0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B8110
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x104B8130
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_446 )
      return nullptr;
  }
  return off_107793B8[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x104B8180
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_107793B4;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_446.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104B81C0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = &var;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x104B82D0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B8440
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0048E500
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x0048E520
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_45 )
      return nullptr;
  }
  return off_5E61A0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x0048E570
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5E619C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_45.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0048E5B0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = WindowName;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x0048E6C0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  int v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
                 a1: g_pDataModel.u,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: 0);
          v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                               a1: g_pDataModel.u,
                               a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E830
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00512260
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x00512280
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_50 )
      return nullptr;
  }
  return off_665A88[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x005122D0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_665A84;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_50.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00512310
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = pDefaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00512420
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00512590
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004D2700
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004D2720
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_49 )
      return nullptr;
  }
  return off_64CF10[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004D2770
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_64CF0C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_49.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D27B0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = pDeltaStateName;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x004D28C0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  int v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
                 a1: g_pDataModel.u,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: 0);
          v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                               a1: g_pDataModel.u,
                               a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2B90
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00457980
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004579A0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_23 )
      return nullptr;
  }
  return off_524860[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004579F0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_52485C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_23.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00457A30
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00457B40
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457CB0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00459480
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004594A0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_25 )
      return nullptr;
  }
  return off_5AD9D0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004594F0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5AD9CC;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_25.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459530
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = str;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00459640
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004597B0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00464330
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x00464350
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  unsigned int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _stricmp(a1: (unsigned int)pLogType, a2: v1, dst: pLogType, src: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_42 )
      return nullptr;
  }
  return off_484188[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004643A0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall IsLogLayerType@<al>(unsigned int a1@<ebx>, const char *pLogLayerType)
{
  const char **v2; // esi

  v2 = (const char **)off_484184;
  while ( _stricmp(a1, a2: (unsigned int)pLogLayerType, dst: pLogLayerType, src: *v2) != 0 )
  {
    v2 += 3;
    if ( (int)v2 >= (int)&vec2_invalid_42.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004643E0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  const char *v5; // ebx
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *v11; // eax
  const char *v12; // eax
  void *pValue; // [esp+18h] [ebp+10h]

  v5 = pToAttrName;
  if ( pToAttrName == nullptr )
    v5 = pFromAttrName;
  if ( pToElement != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    v7 = toType;
    v8 = Attribute->m_nFlags & 0x1F;
    pValue = Attribute->m_pData;
    if ( toType == AT_UNKNOWN )
      v7 = Attribute->m_nFlags & 0x1F;
    v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: v5);
    if ( v9 != nullptr )
      v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
    else
      v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: v5, type: v7);
    if ( v10 == nullptr )
    {
      _Warning(a1: "*** Problem in converter encountered!\n");
      v11 = CUtlString::operator char const *(this: &pToElement->m_Name.m_Storage);
      _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", v5, v11);
      CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
      return;
    }
    if ( v8 != v7 )
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      v12 = CUtlString::operator char const *(this: &pFromElement->m_Name.m_Storage);
      _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
      CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
      return;
    }
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
  }
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x004644F0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV3::FixupElement(CImportSFMV3 *this@<ecx>, unsigned int a2@<ebx>, CDmElement *pElement)
{
  const char *v3; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v5; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v7; // eax

  if ( pElement != nullptr )
  {
    v3 = g_pDataModel->GetString(this: g_pDataModel, a2: pElement->m_Type);
    if ( IsLogLayerType(a1: a2, pLogLayerType: v3) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: v3);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v5 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v7 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v5,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v5,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v5,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v5,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v5,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v5,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v5,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v5,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v5,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v5,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464670
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, KeyValues *pSourceRoot)
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
    CImportSFMV3::FixupElement(
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
// Address: 0x00457910
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x00457930
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_23 )
      return nullptr;
  }
  return off_4AF860[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004579C0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = &defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00457AD0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457C40
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045C8A0
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x0045C8C0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_26 )
      return nullptr;
  }
  return off_5BEAA0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x0045C910
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5BEA9C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_26.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C950
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = &pParentName;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x0045CA60
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CBD0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B29E0
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004B2A00
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_76 )
      return nullptr;
  }
  return off_788488[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004B2A50
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_788484;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_76.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2A90
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x004B2BA0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  int v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
                 a1: g_pDataModel.u,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: 0);
          v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                               a1: g_pDataModel.u,
                               a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2D10
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045D450
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x0045D470
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_26 )
      return nullptr;
  }
  return off_5C0B00[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x0045D4C0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5C0AFC;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_26.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D500
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    v7 = toType;
    v8 = Attribute->m_nFlags & 0x1F;
    pValue = Attribute->m_pData;
    if ( toType == AT_UNKNOWN )
      v7 = Attribute->m_nFlags & 0x1F;
    v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
    if ( v9 != nullptr )
      v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
    else
      v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
    if ( v10 == nullptr )
    {
      _Warning(a1: "*** Problem in converter encountered!\n");
      _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n");
      CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
      return;
    }
    if ( v8 != v7 )
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n");
      CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
      return;
    }
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
  }
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x0045D610
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D780
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004CBE10
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x004CBE30
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_49 )
      return nullptr;
  }
  return off_643F08[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x004CBE80
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_643F04;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_49.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CBEC0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = pDeltaStateName;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x004CBFD0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  int v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
                 a1: g_pDataModel.u,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: 0);
          v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                               a1: g_pDataModel.u,
                               a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC140
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00467B90
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x00467BB0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_27 )
      return nullptr;
  }
  return off_5BDD18[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x00467C00
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_5BDD14;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_27.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467C40
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = Ptr;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x00467D50
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467EC0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0055F580
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x0055F5A0
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_75 )
      return nullptr;
  }
  return off_7788A0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x0055F5F0
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_77889C;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_75.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F630
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = var;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x0055F740
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && *CDmAttribute::GetValue<bool>(this: Attribute) )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F8B0
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x1008A3F0
// Name: void InstallSFMV3Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV3Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV3);
}

//------------------------------------------------------------------------------
// Address: 0x1008A410
// Name: char const __near * GetCurveInfoTypeFromLogType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurveInfoTypeFromLogType(const char *pLogType)
{
  int v1; // edi
  LogToCurveInfoTypeMap_t *v2; // esi

  v1 = 0;
  v2 = g_typeMap;
  while ( _V_stricmp(s1: pLogType, s2: v2->pLogType) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&vec2_invalid_33 )
      return nullptr;
  }
  return off_101374E0[3 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x1008A460
// Name: bool IsLogLayerType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLogLayerType(const char *pLogLayerType)
{
  const char **v1; // esi

  v1 = (const char **)off_101374DC;
  while ( _V_stricmp(s1: pLogLayerType, s2: *v1) != 0 )
  {
    v1 += 3;
    if ( (int)v1 >= (int)&vec2_invalid_33.y )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008A4A0
// Name: void MoveAttribute(class CDmElement __near *,char const __near *,class CDmElement __near *,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveAttribute(
        CDmElement *pFromElement,
        const char *pFromAttrName,
        CDmElement *pToElement,
        const char *pToAttrName,
        DmAttributeType_t toType)
{
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v7; // edi
  int v8; // esi
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // ecx
  const char *m_pAsString; // eax
  const char *v12; // eax
  void *pValue; // [esp+10h] [ebp+10h]

  if ( pToAttrName == nullptr )
    pToAttrName = pFromAttrName;
  if ( pToElement == nullptr )
    goto LABEL_18;
  Attribute = CDmElement::FindAttribute(this: pFromElement, pAttributeName: pFromAttrName);
  v7 = toType;
  v8 = Attribute->m_nFlags & 0x1F;
  pValue = Attribute->m_pData;
  if ( toType == AT_UNKNOWN )
    v7 = Attribute->m_nFlags & 0x1F;
  v9 = CDmElement::FindAttribute(this: pToElement, pAttributeName: pToAttrName);
  if ( v9 != nullptr )
    v10 = v7 == (v9->m_nFlags & 0x1F) ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pToElement, pAttributeName: pToAttrName, type: v7);
  if ( v10 == nullptr )
  {
    _Warning(a1: "*** Problem in converter encountered!\n");
    m_pAsString = pToElement->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    _Warning(a1: "*** Unable to find or add attribute \"%s\" to element \"%s\"!\n", pToAttrName, m_pAsString);
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  if ( v8 == v7 )
  {
    CDmAttribute::SetValue(this: v10, valueType: v7, pValue);
LABEL_18:
    CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
    return;
  }
  _Warning(a1: "*** Problem in file encountered!\n");
  v12 = pFromElement->m_Name.m_Storage.u.m_pAsString;
  if ( v12 == (const char *)-1 )
    v12 = defaultValue;
  _Warning(a1: "*** Element \"%s\" has attribute \"%s\" with an unexpected type!\n", v12, pFromAttrName);
  CDmElement::RemoveAttribute(this: pFromElement, pAttributeName: pFromAttrName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5B0
// Name: private: void CImportSFMV3::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV3::FixupElement(CImportSFMV3 *this, CDmElement *pElement)
{
  const char *m_pAsString; // edi
  char *CurveInfoTypeFromLogType; // ebx
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v6; // eax

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( IsLogLayerType(pLogLayerType: m_pAsString) != 0 )
    {
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "ownerlog");
    }
    else
    {
      CurveInfoTypeFromLogType = GetCurveInfoTypeFromLogType(pLogType: m_pAsString);
      if ( CurveInfoTypeFromLogType != nullptr )
      {
        v4 = nullptr;
        Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "usecurvetypes");
        if ( Attribute != nullptr && CDmAttribute::GetValue<bool>(this: Attribute)->m_Storage )
        {
          v6 = g_pDataModel->CreateElement(
                 this: g_pDataModel,
                 a2: "curve info",
                 a3: CurveInfoTypeFromLogType,
                 a4: pElement->m_fileId,
                 a5: nullptr);
          v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        }
        CDmElement::RemoveAttribute(this: pElement, pAttributeName: "usecurvetypes");
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultcurvetype",
          pToElement: v4,
          pToAttrName: "defaultCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "defaultedgezerovalue",
          pToElement: v4,
          pToAttrName: "defaultEdgeZeroValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "useedgeinfo",
          pToElement: v4,
          pToAttrName: "useEdgeInfo",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "rightedgetime",
          pToElement: v4,
          pToAttrName: "rightEdgeTime",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_active",
          pToElement: v4,
          pToAttrName: "leftEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_active",
          pToElement: v4,
          pToAttrName: "rightEdgeActive",
          toType: AT_BOOL);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_curvetype",
          pToElement: v4,
          pToAttrName: "leftEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_curvetype",
          pToElement: v4,
          pToAttrName: "rightEdgeCurveType",
          toType: AT_INT);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "left_edge_value",
          pToElement: v4,
          pToAttrName: "leftEdgeValue",
          toType: AT_UNKNOWN);
        MoveAttribute(
          pFromElement: pElement,
          pFromAttrName: "right_edge_value",
          pToElement: v4,
          pToAttrName: "rightEdgeValue",
          toType: AT_UNKNOWN);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A720
// Name: private: virtual bool CImportSFMV3::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV3::DoFixup(CImportSFMV3 *this, CDmElement *pSourceRoot)
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
    CImportSFMV3::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
