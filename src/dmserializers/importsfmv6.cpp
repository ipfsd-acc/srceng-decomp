// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv6.cpp
// Functions: 4
// ============================================================

#include "dmserializers\importsfmv6.h"

//------------------------------------------------------------------------------
// Address: 0x004557C0
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004557E0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455920
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004559C0
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0046B1C0
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x0046B1E0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046B320
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B3C0
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004A7E10
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004A7E30
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7F70
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A8010
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x104B7B80
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x104B7BA0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104B7CE0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B7D80
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0048DF70
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x0048DF90
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E0D0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E170
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00511B60
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x00511B80
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00511CC0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511D60
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004D2170
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004D2190
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D22D0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2370
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00457290
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004572B0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004573F0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457490
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00458EF0
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x00458F10
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459050
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004590F0
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00463B80
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x00463BA0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  double v3; // st5
  double v4; // st4
  double v5; // rt0
  double v6; // st4
  double v7; // st3
  double v8; // st2
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st6
  Vector right; // [esp+0h] [ebp-1Ch] BYREF
  Vector up; // [esp+Ch] [ebp-10h] BYREF
  float v16; // [esp+18h] [ebp-4h]

  up.y = 0.0;
  up.z = 0.0;
  v16 = 1.0;
  v3 = dir->z * 0.0;
  v4 = dir->y - v3;
  right.y = v4;
  v5 = v4;
  v6 = v3 - dir->x;
  right.z = v6;
  v7 = dir->x * 0.0;
  v8 = v7 - dir->y * 0.0;
  up.x = v8;
  if ( v8 * v8 + v6 * v6 + v5 * v5 < 0.0000010000001 )
  {
    up.y = 1.0;
    up.z = 0.0;
    v16 = 0.0;
    v9 = dir->z - v7;
    v10 = v7 - dir->y;
    right.y = dir->y * 0.0 - 0.0 * dir->z;
    right.z = v9;
    up.x = v10;
  }
  pfVectorNormalize(a1: (Vector *)&right.y);
  v11 = right.y * dir->y - right.z * dir->x;
  v12 = up.x * dir->x - right.y * dir->z;
  up.y = right.z * dir->z - up.x * dir->y;
  up.z = v12;
  v16 = v11;
  BasisToQuaternion(vecForward: dir, vecRight: (Vector *)&right.y, vecUp: (Vector *)&up.y, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463D70
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportSFMV6::FixupElement(CImportSFMV6 *this@<ecx>, unsigned int a2@<ebx>, CDmElement *pElement)
{
  const char *v4; // eax
  CDmaVar<Vector> *v5; // eax
  Vector vDir; // [esp+4h] [ebp-20h] BYREF
  Quaternion q; // [esp+10h] [ebp-14h] BYREF

  if ( pElement != nullptr )
  {
    v4 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElement->m_Type);
    if ( _stricmp(a1: a2, a2: (unsigned int)this, dst: v4, src: "DmeProjectedLight") == 0 )
    {
      v5 = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction");
      vDir.y = v5->m_Storage.x;
      vDir.z = v5->m_Storage.y;
      q.x = v5->m_Storage.z;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: (Quaternion *)&q.y, dir: (Vector *)&vDir.y);
      CDmElement::SetValue<Quaternion>(this: pElement, pAttributeName: "orientation", value: (Quaternion *)&q.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463E00
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, KeyValues *pSourceRoot)
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
    CImportSFMV6::FixupElement(
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
// Address: 0x00457220
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x00457240
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457380
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457420
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045C310
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x0045C330
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C470
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C510
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004B22F0
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004B2310
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B2450
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B24F0
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0045CD60
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x0045CD80
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CEC0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CF60
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x004CB880
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x004CB8A0
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CB9E0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBA80
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x00467600
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x00467620
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467760
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467800
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x0055EFF0
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x0055F010
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055F150
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F1F0
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
// Address: 0x10089E60
// Name: void InstallSFMV6Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV6Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportSFMV6);
}

//------------------------------------------------------------------------------
// Address: 0x10089E80
// Name: private: class Quaternion CImportSFMV6::DirectionToOrientation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall CImportSFMV6::DirectionToOrientation(CImportSFMV6 *this, Quaternion *result, const Vector *dir)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float z; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  Vector up; // [esp+8h] [ebp-18h] BYREF
  Vector right; // [esp+14h] [ebp-Ch] BYREF

  y = dir->y;
  x = dir->x;
  v5 = dir->z * 0.0;
  v6 = y - v5;
  v7 = v5 - dir->x;
  right.x = v6;
  v8 = x * 0.0;
  right.y = v7;
  right.z = v8 - (float)(y * 0.0);
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(right.z * right.z)) < 0.0000010000001 )
  {
    z = dir->z;
    v10 = z - v8;
    v11 = v8 - dir->y;
    v12 = (float)(dir->y * 0.0) - (float)(z * 0.0);
    up.x = 1.0;
    up.y = 0.0;
    up.z = 0.0;
    right.x = v12;
    right.y = v10;
    right.z = v11;
  }
  VectorNormalize(vec: &right);
  v13 = (float)(dir->x * right.z) - (float)(dir->z * right.x);
  v14 = (float)(dir->y * right.x) - (float)(dir->x * right.y);
  up.x = (float)(dir->z * right.y) - (float)(dir->y * right.z);
  up.y = v13;
  up.z = v14;
  BasisToQuaternion(vecForward: dir, vecRight: &right, vecUp: &up, q: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10089FC0
// Name: private: void CImportSFMV6::FixupElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV6::FixupElement(CImportSFMV6 *this, CDmElement *pElement)
{
  const char *m_pAsString; // eax
  CDmAttribute *Attribute; // eax
  Quaternion q; // [esp+8h] [ebp-1Ch] BYREF
  Vector vDir; // [esp+18h] [ebp-Ch] BYREF

  if ( pElement != nullptr )
  {
    m_pAsString = pElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: "DmeProjectedLight") == 0 )
    {
      vDir = CDmElement::GetValue<Vector>(this: pElement, pAttributeName: "direction")->m_Storage;
      CDmElement::RemoveAttribute(this: pElement, pAttributeName: "direction");
      CImportSFMV6::DirectionToOrientation(this, result: &q, dir: &vDir);
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "orientation");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
      {
        CDmAttribute::SetValue<Quaternion>(this: Attribute, value: &q);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A060
// Name: private: virtual bool CImportSFMV6::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV6::DoFixup(CImportSFMV6 *this, CDmElement *pSourceRoot)
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
    CImportSFMV6::FixupElement(this, pElement: fixlist.m_Elements.m_pMemory[i].m_Data);
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
