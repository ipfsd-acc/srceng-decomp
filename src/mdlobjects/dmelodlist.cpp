// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmelodlist.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmelodlist.h"

//------------------------------------------------------------------------------
// Address: 0x0049CDC0
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetRootLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetRootLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+0h] [ebp-Ch]
  int nMinIndex; // [esp+4h] [ebp-8h]
  float flMinMetric; // [esp+8h] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  nMinIndex = -1;
  flMinMetric = 3.4028235e38;
  if ( nCount <= 0 )
    return nullptr;
  do
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( flMinMetric > *(float *)(v4 + 112) )
    {
      nMinIndex = v2;
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
      v6 = v5;
      if ( v5 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeLOD::m_classType.u) == 0 )
      {
        v6 = 0;
      }
      flMinMetric = *(float *)(v6 + 112);
      if ( flMinMetric == 0.0 )
        break;
    }
    ++v2;
  }
  while ( v2 < nCount );
  if ( nMinIndex >= 0
    && (v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[nMinIndex]),
        v8 = v7,
        v7 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v8;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CEE0
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetShadowLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetShadowLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( *(_BYTE *)(v4 + 128) != 0 )
      break;
    if ( ++v2 >= nCount )
      return nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
  v7 = v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049CFF0
// Name: public: virtual bool CDmeLODList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLODList::IsA(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049D020
// Name: public: virtual int CDmeLODList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLODList::GetInheritanceDepth(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049D070
// Name: protected: virtual void CDmeLODList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLODList::PerformConstruction(CDmeLODList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_LODs.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "lodList",
                                type: AT_FIRST_ARRAY_TYPE,
                                pMemory: &this->m_LODs);
  CDmAttribute::SetElementTypeSymbol(this: this->m_LODs.m_pAttribute, typeSymbol: CDmeLOD::m_classType);
  this->m_EyeballList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "eyeballList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_EyeballList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EyeballList.m_pAttribute, typeSymbol: CDmeEyeball::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005988E0
// Name: _dynamic_initializer_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLODList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLODList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E000
// Name: _dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLODList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598910
// Name: _dynamic_initializer_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLODList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLODList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598920
// Name: _dynamic_initializer_for__g_CDmeLODList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLODList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLODList_Helper,
           classname: "DmeLODList",
           pFactory: &g_CDmeLODList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E010
// Name: _dynamic_atexit_destructor_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLODList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLODList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E2300
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetRootLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetRootLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+0h] [ebp-Ch]
  int nMinIndex; // [esp+4h] [ebp-8h]
  float flMinMetric; // [esp+8h] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  nMinIndex = -1;
  flMinMetric = 3.4028235e38;
  if ( nCount <= 0 )
    return nullptr;
  do
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( flMinMetric > *(float *)(v4 + 112) )
    {
      nMinIndex = v2;
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
      v6 = v5;
      if ( v5 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeLOD::m_classType.u) == 0 )
      {
        v6 = 0;
      }
      flMinMetric = *(float *)(v6 + 112);
      if ( flMinMetric == 0.0 )
        break;
    }
    ++v2;
  }
  while ( v2 < nCount );
  if ( nMinIndex >= 0
    && (v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[nMinIndex]),
        v8 = v7,
        v7 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v8;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E2420
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetShadowLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetShadowLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( *(_BYTE *)(v4 + 128) != 0 )
      break;
    if ( ++v2 >= nCount )
      return nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
  v7 = v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E2530
// Name: public: virtual bool CDmeLODList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLODList::IsA(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2560
// Name: public: virtual int CDmeLODList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLODList::GetInheritanceDepth(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E25B0
// Name: protected: virtual void CDmeLODList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLODList::PerformConstruction(CDmeLODList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_LODs.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "lodList",
                                type: AT_FIRST_ARRAY_TYPE,
                                pMemory: &this->m_LODs);
  CDmAttribute::SetElementTypeSymbol(this: this->m_LODs.m_pAttribute, typeSymbol: CDmeLOD::m_classType);
  this->m_EyeballList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "eyeballList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_EyeballList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EyeballList.m_pAttribute, typeSymbol: CDmeEyeball::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ED3A0
// Name: _dynamic_initializer_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLODList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLODList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3270
// Name: _dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLODList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED3D0
// Name: _dynamic_initializer_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLODList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLODList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED3E0
// Name: _dynamic_initializer_for__g_CDmeLODList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLODList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLODList_Helper,
           classname: "DmeLODList",
           pFactory: &g_CDmeLODList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3280
// Name: _dynamic_atexit_destructor_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLODList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLODList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C960
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetRootLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetRootLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+0h] [ebp-Ch]
  int nMinIndex; // [esp+4h] [ebp-8h]
  float flMinMetric; // [esp+8h] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  nMinIndex = -1;
  flMinMetric = 3.4028235e38;
  if ( nCount <= 0 )
    return nullptr;
  do
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( flMinMetric > *(float *)(v4 + 112) )
    {
      nMinIndex = v2;
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
      v6 = v5;
      if ( v5 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeLOD::m_classType.u) == 0 )
      {
        v6 = 0;
      }
      flMinMetric = *(float *)(v6 + 112);
      if ( flMinMetric == 0.0 )
        break;
    }
    ++v2;
  }
  while ( v2 < nCount );
  if ( nMinIndex >= 0
    && (v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[nMinIndex]),
        v8 = v7,
        v7 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v8;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050CA80
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetShadowLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetShadowLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( *(_BYTE *)(v4 + 128) != 0 )
      break;
    if ( ++v2 >= nCount )
      return nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
  v7 = v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050CB90
// Name: public: virtual bool CDmeLODList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLODList::IsA(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050CBC0
// Name: public: virtual int CDmeLODList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLODList::GetInheritanceDepth(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050CC10
// Name: protected: virtual void CDmeLODList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLODList::PerformConstruction(CDmeLODList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_LODs.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "lodList",
                                type: AT_FIRST_ARRAY_TYPE,
                                pMemory: &this->m_LODs);
  CDmAttribute::SetElementTypeSymbol(this: this->m_LODs.m_pAttribute, typeSymbol: CDmeLOD::m_classType);
  this->m_EyeballList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "eyeballList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_EyeballList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EyeballList.m_pAttribute, typeSymbol: CDmeEyeball::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ACCE0
// Name: _dynamic_initializer_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLODList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLODList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DD0
// Name: _dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLODList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACD10
// Name: _dynamic_initializer_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLODList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLODList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACD20
// Name: _dynamic_initializer_for__g_CDmeLODList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLODList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLODList_Helper,
           classname: "DmeLODList",
           pFactory: &g_CDmeLODList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DE0
// Name: _dynamic_atexit_destructor_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLODList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeLODList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DC3E0
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetRootLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetRootLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+0h] [ebp-Ch]
  int nMinIndex; // [esp+4h] [ebp-8h]
  float flMinMetric; // [esp+8h] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  nMinIndex = -1;
  flMinMetric = 3.4028235e38;
  if ( nCount <= 0 )
    return nullptr;
  do
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( flMinMetric > *(float *)(v4 + 112) )
    {
      nMinIndex = v2;
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
      v6 = v5;
      if ( v5 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeLOD::m_classType.u) == 0 )
      {
        v6 = 0;
      }
      flMinMetric = *(float *)(v6 + 112);
      if ( flMinMetric == 0.0 )
        break;
    }
    ++v2;
  }
  while ( v2 < nCount );
  if ( nMinIndex >= 0
    && (v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[nMinIndex]),
        v8 = v7,
        v7 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v8;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DC500
// Name: public: virtual class CDmeLOD __near * CDmeLODList::GetShadowLOD(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLODList::GetShadowLOD(CDmeLODList *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_LODs.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeLOD::m_classType.u) == 0 )
    {
      v4 = 0;
    }
    if ( *(_BYTE *)(v4 + 128) != 0 )
      break;
    if ( ++v2 >= nCount )
      return nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_LODs.m_Storage.m_Memory.m_pMemory[v2]);
  v7 = v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeLOD::m_classType.u) != 0 )
  {
    return (CDmeLOD *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DC610
// Name: public: virtual bool CDmeLODList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLODList::IsA(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC640
// Name: public: virtual int CDmeLODList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLODList::GetInheritanceDepth(CDmeLODList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLODList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC690
// Name: protected: virtual void CDmeLODList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLODList::PerformConstruction(CDmeLODList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_LODs.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "lodList",
                                type: AT_FIRST_ARRAY_TYPE,
                                pMemory: &this->m_LODs);
  CDmAttribute::SetElementTypeSymbol(this: this->m_LODs.m_pAttribute, typeSymbol: CDmeLOD::m_classType);
  this->m_EyeballList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "eyeballList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_EyeballList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EyeballList.m_pAttribute, typeSymbol: CDmeEyeball::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E63B0
// Name: _dynamic_initializer_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLODList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLODList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC190
// Name: _dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLODList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLODList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E63E0
// Name: _dynamic_initializer_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLODList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLODList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E63F0
// Name: _dynamic_initializer_for__g_CDmeLODList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLODList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLODList_Helper,
           classname: "DmeLODList",
           pFactory: &g_CDmeLODList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1A0
// Name: _dynamic_atexit_destructor_for__g_CDmeLODList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLODList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLODList_Factory.m_CallBackList);
}

} // namespace studiomdl
