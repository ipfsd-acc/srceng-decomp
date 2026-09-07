// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcesystem/resourcetypemanagerbase.cpp
// Functions: 11
// ============================================================

#include "resourcesystem\resourcetypemanagerbase.h"

//------------------------------------------------------------------------------
// Address: 0x100085E0
// Name: protected: virtual CResourceTypeManagerBase::~CResourceTypeManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::~CResourceTypeManagerBase(CResourceTypeManagerBase *this)
{
  this->__vftable = (CResourceTypeManagerBase_vtbl *)&CResourceTypeManagerBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100085F0
// Name: public: virtual int CResourceTypeManagerBase::GetResourceType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceTypeManagerBase::GetResourceType(CResourceEnumValueIntrospection *this)
{
  return this->m_nEnumValue;
}

//------------------------------------------------------------------------------
// Address: 0x10008600
// Name: public: void CResourceTypeManagerBase::SetFactory(class IResourceTypeManagerFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::SetFactory(
        CResourceTypeManagerBase *this,
        IResourceTypeManagerFactory *pFactory)
{
  this->m_pFactory = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10008610
// Name: public: void CResourceTypeManagerBase::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::Release(CResourceTypeManagerBase *this)
{
  this->m_pFactory->Destroy(this: this->m_pFactory, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10008620
// Name: public: virtual void CResourceTypeManagerBase::Init(int,class IResourceTypeConstructor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::Init(
        CResourceTypeManagerBase *this,
        int nType,
        IResourceTypeConstructor *pConstructor)
{
  this->m_nResourceType = nType;
  this->m_pConstructor = pConstructor;
  if ( pConstructor != nullptr )
    this->m_nMemoryLimit = pConstructor->GetDefaultMemoryLimit(this: pConstructor);
  else
    this->m_nMemoryLimit = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008650
// Name: public: virtual void CResourceTypeManagerBase::SetMemoryLimit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::SetMemoryLimit(CResourceTypeManagerBase *this, int nMemoryLimit)
{
  this->m_nMemoryLimit = nMemoryLimit;
}

//------------------------------------------------------------------------------
// Address: 0x10008660
// Name: protected: virtual void CResourceIntrospectionTraversal::PostVisitField(void const __near *,class CResourceFieldIntrospection const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionTraversal::PostVisitField(
        CResourceIntrospectionTraversal *this,
        const void *pFieldInstance,
        const CResourceFieldIntrospection *pFieldIntro,
        int nTypeChainIndex)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10008670
// Name: protected: virtual bool CResourceIntrospectionTraversal::VisitStruct(void const __near *,class CResourceStructIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceIntrospectionTraversal::VisitStruct(
        CResourceIntrospectionTraversal *this,
        const void *pEnum,
        const CResourceEnumIntrospection *pEnumIntro)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008680
// Name: protected: void CResourceTypeManagerBase::FixupResourceReferences(void __near *,void const __near *,int,class CResourceIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerBase::FixupResourceReferences(
        CResourceTypeManagerBase *this,
        void *pResourceData,
        const void *pDct,
        int nResourceType,
        const CResourceIntrospection *pIntroDct)
{
  int v5; // edi
  const CResourceStructIntrospection *StructIntrospectionForResourceType; // eax
  const CResourceStructIntrospection *v7; // esi
  CResourceReferenceFixupTraversal fixupTraversal; // [esp+8h] [ebp-18h] BYREF
  char v9; // [esp+1Ch] [ebp-4h]

  if ( pIntroDct != nullptr )
  {
    if ( CResourceIntrospection::GetVersion(this: pIntroDct) != 2 )
    {
      _Warning(
        a1: "Out-of-date introspection data for resource type %d. Make sure you have up-to-date VTD's?\n",
        nResourceType);
      return;
    }
    v5 = nResourceType;
    StructIntrospectionForResourceType = CResourceIntrospection::FindStructIntrospectionForResourceType(
                                           this: pIntroDct,
                                           nType: nResourceType);
  }
  else
  {
    v5 = nResourceType;
    StructIntrospectionForResourceType = g_pResourceSystemImp->FindStructIntrospectionForResourceType(
                                           this: g_pResourceSystemImp,
                                           a2: nResourceType);
  }
  v7 = StructIntrospectionForResourceType;
  if ( StructIntrospectionForResourceType != nullptr )
  {
    CResourceIntrospectionTraversal::CResourceIntrospectionTraversal(
      this: (CResourceIntrospectionTraversal *)&fixupTraversal.m_bTraverseDiskLayout,
      pResIntro: pIntroDct);
    *(_DWORD *)&fixupTraversal.m_bWarnOnNotFound = pDct;
    *(_DWORD *)&fixupTraversal.m_bTraverseDiskLayout = &CResourceReferenceFixupTraversal::`vftable';
    v9 = 1;
    CResourceIntrospectionTraversal::TraverseStruct(
      this: (CResourceIntrospectionTraversal *)&fixupTraversal.m_bTraverseDiskLayout,
      pStruct: pResourceData,
      pStructIntro: v7);
  }
  else
  {
    _Warning(
      a1: "Could not find introspection information for resource type %d. Make sure you have up-to-date VTD's?\n",
      v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008730
// Name: public: CResourceTypeManagerBase::CResourceTypeManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerBase *__thiscall CResourceTypeManagerBase::CResourceTypeManagerBase(CResourceTypeManagerBase *this)
{
  this->__vftable = (CResourceTypeManagerBase_vtbl *)&CResourceTypeManagerBase::`vftable';
  this->m_nResourceType = -1;
  this->m_pFactory = nullptr;
  this->m_nMemoryUsed = 0;
  this->m_nMemoryLimit = 0x8000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008770
// Name: public: virtual bool CResourceReferenceFixupTraversal::VisitField(void const __near *,class CResourceFieldIntrospection const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceReferenceFixupTraversal::VisitField(
        CResourceReferenceFixupTraversal *this,
        int *pFieldInstance,
        CResourceFieldIntrospection *pFieldIntro,
        int nTypeChainIndex)
{
  CResourceSystem_vtbl *v5; // edi
  unsigned int RootTypeData; // eax
  int v7; // eax
  int v8; // eax
  int m_nOffset; // ebx
  unsigned int v11; // eax

  if ( CResourceFieldIntrospection::ReadTypeChain(this: pFieldIntro, nChainIndex: nTypeChainIndex) != RESOURCE_FIELD_TYPE_RESOURCE_REFERENCE )
    return 1;
  v5 = g_pResourceSystemImp->__vftable;
  RootTypeData = CResourceFieldIntrospection::GetRootTypeData(this: pFieldIntro);
  v7 = (int)v5->GetResourceManager(this: g_pResourceSystemImp, a2: RootTypeData);
  v8 = (*(int (__thiscall **)(int, int, const void *))(*(_DWORD *)v7 + 72))(
         a1: v7,
         a2: *pFieldInstance,
         a3: this->m_pDct);
  *pFieldInstance = v8;
  if ( v8 != 0 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 12), 1u);
    return 0;
  }
  else
  {
    if ( this->m_bWarnOnNotFound )
    {
      m_nOffset = pFieldIntro->m_pFieldName.m_nOffset;
      v11 = CResourceFieldIntrospection::GetRootTypeData(this: pFieldIntro);
      _Warning(
        a1: "Failed to fixup resource reference for field '%s' (Resource Type = %d, ID = %d)\n",
        (const char *)pFieldIntro + m_nOffset,
        v11,
        0);
    }
    return 0;
  }
}
