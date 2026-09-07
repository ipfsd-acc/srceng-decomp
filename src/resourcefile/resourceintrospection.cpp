// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcefile/resourceintrospection.cpp
// Functions: 43
// ============================================================

#include "resourcefile\resourceintrospection.h"

//------------------------------------------------------------------------------
// Address: 0x1000FB90
// Name: unsigned int ComputeStructureNameHash(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeStructureNameHash(char *pStructName)
{
  unsigned int v1; // eax

  v1 = _V_strlen(str: pStructName);
  return MurmurHash2(key: pStructName, len: v1, seed: 0xBAADFEED);
}

//------------------------------------------------------------------------------
// Address: 0x1000FBB0
// Name: public: unsigned int CResourceIntrospection::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceIntrospection::GetVersion(CResourceIntrospection *this)
{
  return this->m_nVersion;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBC0
// Name: public: int CResourceIntrospection::GetStructCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceIntrospection::GetStructCount(CResourceIntrospection *this)
{
  return this->m_StructIntrospection.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBD0
// Name: public: int CResourceIntrospection::GetTypedefCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceIntrospection::GetTypedefCount(CResourceIntrospection *this)
{
  return this->m_TypedefIntrospection.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBE0
// Name: public: int CResourceStructIntrospection::GetFieldCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceStructIntrospection::GetFieldCount(CResourceStructIntrospection *this)
{
  return this->m_FieldIntrospection.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBF0
// Name: public: bool CResourceStructIntrospection::HasVTable(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceStructIntrospection::HasVTable(CResourceStructIntrospection *this)
{
  return this->m_nStructFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC00
// Name: public: int CResourceIntrospection::GetEnumCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceIntrospection::GetEnumCount(CResourceEnumIntrospection *this)
{
  return this->m_EnumValueIntrospection.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC10
// Name: public: CResourceIntrospectionTraversal::CResourceIntrospectionTraversal(class CResourceIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
CResourceIntrospectionTraversal *__thiscall CResourceIntrospectionTraversal::CResourceIntrospectionTraversal(
        CResourceIntrospectionTraversal *this,
        const CResourceIntrospection *pResIntro)
{
  this->__vftable = (CResourceIntrospectionTraversal_vtbl *)&CResourceIntrospectionTraversal::`vftable';
  this->m_bTraverseDiskLayout = false;
  this->m_pResIntro = pResIntro;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC30
// Name: protected: virtual bool CResourceIntrospectionTraversal::VisitField(void const __near *,class CResourceFieldIntrospection const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceIntrospectionTraversal::VisitField(
        CResourceIntrospectionTraversal *this,
        const void *pFieldInstance,
        const CResourceFieldIntrospection *pFieldIntro,
        int nTypeChainIndex)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC40
// Name: public: static struct ResourceFieldProperties_t const __near * ResourceFieldProperties_t::GetFieldProperties(enum ResourceFieldType_t)
// Source: json
//------------------------------------------------------------------------------
const ResourceFieldProperties_t *__cdecl ResourceFieldProperties_t::GetFieldProperties(ResourceFieldType_t nFieldType)
{
  return &s_pFieldTypes[nFieldType];
}

//------------------------------------------------------------------------------
// Address: 0x1000FC50
// Name: public: virtual int CSchemaClassBinding<class CResourceEnumIntrospection>::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemaClassBinding<CResourceEnumIntrospection>::GetSize(
        CSchemaClassBinding<CResourceEnumIntrospection> *this)
{
  return 20;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC60
// Name: public: virtual int CSchemaClassBinding<class CResourceTypedefIntrospection>::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemaClassBinding<CResourceTypedefIntrospection>::GetSize(
        CSchemaClassBinding<CResourceTypedefIntrospection> *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC70
// Name: public: static class CResourceIntrospection const __near * CResourceIntrospection::FindInFile(struct ResourceFileHeader_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const CResourceIntrospection *__cdecl CResourceIntrospection::FindInFile(const ResourceFileHeader_t *pHeader)
{
  return (const CResourceIntrospection *)Resource_GetBlock(pHeader, id: 0x49534552u);
}

//------------------------------------------------------------------------------
// Address: 0x1000FC90
// Name: public: enum ResourceFieldType_t CResourceFieldIntrospection::ReadTypeChain(int)const
// Source: json
//------------------------------------------------------------------------------
ResourceFieldType_t __thiscall CResourceFieldIntrospection::ReadTypeChain(
        CResourceFieldIntrospection *this,
        int nChainIndex)
{
  if ( nChainIndex != 0 )
    return *(_DWORD *)((char *)&this->m_nFieldType + 4 * nChainIndex + this->m_nTypeChain);
  else
    return this->m_nFieldType;
}

//------------------------------------------------------------------------------
// Address: 0x1000FCB0
// Name: public: unsigned int CResourceFieldIntrospection::GetRootTypeData(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceFieldIntrospection::GetRootTypeData(CResourceFieldIntrospection *this)
{
  __int16 m_nTypeChainCount; // ax

  m_nTypeChainCount = this->m_nTypeChainCount;
  if ( m_nTypeChainCount == 1 )
    return this->m_nTypeChain;
  else
    return *(_DWORD *)((char *)&this->m_nFieldType + 4 * m_nTypeChainCount + this->m_nTypeChain);
}

//------------------------------------------------------------------------------
// Address: 0x1000FCD0
// Name: public: enum ResourceFieldType_t CResourceFieldIntrospection::GetRootType(void)const
// Source: json
//------------------------------------------------------------------------------
ResourceFieldType_t __thiscall CResourceFieldIntrospection::GetRootType(CResourceFieldIntrospection *this)
{
  __int16 m_nTypeChainCount; // ax

  m_nTypeChainCount = this->m_nTypeChainCount;
  if ( m_nTypeChainCount == 1 )
    return this->m_nFieldType;
  else
    return *(_DWORD *)((char *)&this->m_nOnDiskOffset + 4 * m_nTypeChainCount + this->m_nTypeChain);
}

//------------------------------------------------------------------------------
// Address: 0x1000FCF0
// Name: public: char const __near * CResourceEnumValueIntrospection::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CResourceEnumValueIntrospection::GetName(CResourceEnumValueIntrospection *this)
{
  return (char *)this + this->m_pEnumValueName.m_nOffset;
}

//------------------------------------------------------------------------------
// Address: 0x1000FD00
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospection::GetStructIntrospection(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospection::GetStructIntrospection(
        CResourceIntrospection *this,
        int nIndex)
{
  return (const CResourceStructIntrospection *)((char *)&this->m_StructIntrospection
                                              + 52 * nIndex
                                              + this->m_StructIntrospection.m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD20
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospection::FindStructIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospection::FindStructIntrospection(
        CResourceIntrospection *this,
        unsigned int id)
{
  signed int m_nCount; // esi
  int v3; // eax
  int m_nOffset; // edi
  CResourceArray<CResourceStructIntrospection> *p_m_StructIntrospection; // edx
  int i; // ecx

  m_nCount = this->m_StructIntrospection.m_nCount;
  v3 = 0;
  if ( m_nCount <= 0 )
    return nullptr;
  m_nOffset = this->m_StructIntrospection.m_nOffset;
  p_m_StructIntrospection = &this->m_StructIntrospection;
  for ( i = 0; *(int *)((char *)&p_m_StructIntrospection->m_nOffset + i + m_nOffset) != id; i += 52 )
  {
    if ( ++v3 >= m_nCount )
      return nullptr;
  }
  return (const CResourceStructIntrospection *)((char *)p_m_StructIntrospection + 52 * v3 + m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD70
// Name: public: class CResourceEnumIntrospection const __near * CResourceIntrospection::GetEnumIntrospection(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceIntrospection::GetEnumIntrospection(
        CResourceIntrospection *this,
        int nIndex)
{
  return (const CResourceEnumIntrospection *)((char *)&this->m_EnumIntrospection
                                            + 20 * nIndex
                                            + this->m_EnumIntrospection.m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD90
// Name: public: class CResourceEnumIntrospection const __near * CResourceIntrospection::FindEnumIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceIntrospection::FindEnumIntrospection(
        CResourceIntrospection *this,
        unsigned int id)
{
  signed int m_nCount; // esi
  int v3; // edx
  int m_nOffset; // edi
  CResourceArray<CResourceEnumIntrospection> *p_m_EnumIntrospection; // ecx
  int i; // eax

  m_nCount = this->m_EnumIntrospection.m_nCount;
  v3 = 0;
  if ( m_nCount <= 0 )
    return nullptr;
  m_nOffset = this->m_EnumIntrospection.m_nOffset;
  p_m_EnumIntrospection = &this->m_EnumIntrospection;
  for ( i = 0; *(int *)((char *)&p_m_EnumIntrospection->m_nOffset + i + m_nOffset) != id; i += 20 )
  {
    if ( ++v3 >= m_nCount )
      return nullptr;
  }
  return (const CResourceEnumIntrospection *)((char *)p_m_EnumIntrospection + 20 * v3 + m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FDE0
// Name: public: class CResourceTypedefIntrospection const __near * CResourceIntrospection::GetTypedefIntrospection(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceTypedefIntrospection *__thiscall CResourceIntrospection::GetTypedefIntrospection(
        CResourceIntrospection *this,
        int nIndex)
{
  return (const CResourceTypedefIntrospection *)((char *)&this->m_TypedefIntrospection
                                               + 12 * nIndex
                                               + this->m_TypedefIntrospection.m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE00
// Name: public: enum IntrospectionCompatibilityType_t CResourceIntrospection::CalculateCompatibility(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceIntrospection::CalculateCompatibility(CResourceIntrospection *this)
{
  signed int v1; // ebp
  CResourceArray<CResourceStructIntrospection> *p_m_StructIntrospection; // ebx
  int v3; // edi
  int v4; // esi
  unsigned int v5; // edx
  char *v6; // esi
  const CResourceStructIntrospection *v7; // eax
  int v8; // ebp
  CResourceArray<CResourceEnumIntrospection> *p_m_EnumIntrospection; // ebx
  int i; // edi
  int v11; // esi
  CResourceIntrospection *nCompatibilityType; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v1 = 0;
  nCompatibilityType = this;
  v14 = 1;
  if ( (int)this->m_StructIntrospection.m_nCount <= 0 )
  {
LABEL_11:
    v8 = 0;
    if ( (int)this->m_EnumIntrospection.m_nCount <= 0 )
      return v14;
    p_m_EnumIntrospection = &this->m_EnumIntrospection;
    for ( i = 0; ; i += 20 )
    {
      v11 = i + p_m_EnumIntrospection->m_nOffset;
      if ( *(int *)((char *)&p_m_EnumIntrospection[1].m_nOffset + v11) != g_pResourceSystem->FindEnumIntrospection_2(
                                                                            this: g_pResourceSystem,
                                                                            a2: *(int *)((char *)&p_m_EnumIntrospection->m_nOffset
                                                                                   + v11))->m_nCrc )
        break;
      if ( ++v8 >= (signed int)nCompatibilityType->m_EnumIntrospection.m_nCount )
        return v14;
    }
  }
  else
  {
    p_m_StructIntrospection = &this->m_StructIntrospection;
    v3 = 0;
    while ( 1 )
    {
      v4 = v3 + p_m_StructIntrospection->m_nOffset;
      v5 = *(int *)((char *)&p_m_StructIntrospection->m_nOffset + v4);
      v6 = (char *)p_m_StructIntrospection + v4;
      v7 = g_pResourceSystem->FindStructIntrospection_2(this: g_pResourceSystem, a2: v5);
      if ( v7 == nullptr )
        break;
      if ( *((_DWORD *)v6 + 2) != v7->m_nCrc )
        return 3;
      if ( v7->m_nDiskSize != v7->m_nMemorySize )
      {
        if ( _V_strcmp(s1: &v6[*((_DWORD *)v6 + 1) + 4], s2: "MaterialDrawDescriptor_t") != 0 )
        {
          if ( v14 == 1 )
            v14 = 2;
        }
        else
        {
          _Warning(a1: "****** HARDCODED CHECK FOR MaterialDrawDescriptor_t - REPLACE WITH METADATA LOOKUP WHEN AVAILABLE ******\n");
        }
      }
      this = nCompatibilityType;
      ++v1;
      v3 += 52;
      if ( v1 >= (signed int)nCompatibilityType->m_StructIntrospection.m_nCount )
        goto LABEL_11;
    }
    _Warning(
      a1: "Resource introspection block contained a struct '%s' which doesn't exist anymore.\n",
      &v6[*((_DWORD *)v6 + 1) + 4]);
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF10
// Name: public: class CResourceFieldIntrospection const __near * CResourceStructIntrospection::GetField(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceFieldIntrospection *__thiscall CResourceStructIntrospection::GetField(
        CResourceStructIntrospection *this,
        int nIndex)
{
  return (const CResourceFieldIntrospection *)((char *)&this->m_FieldIntrospection
                                             + 20 * nIndex
                                             + this->m_FieldIntrospection.m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1000FF30
// Name: public: int CResourceFieldIntrospection::GetElementMemorySize(int,class CResourceIntrospection const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceFieldIntrospection::GetElementMemorySize(
        CResourceFieldIntrospection *this,
        int nTypeChainIndex,
        const CResourceIntrospection *pIntroDct)
{
  ResourceFieldType_t m_nFieldType; // edx
  __int16 m_nTypeChainCount; // dx
  __int16 v7; // cx
  unsigned int m_nTypeChain; // eax

  if ( nTypeChainIndex != 0 )
    m_nFieldType = *(_DWORD *)((char *)&this->m_nFieldType + 4 * nTypeChainIndex + this->m_nTypeChain);
  else
    m_nFieldType = this->m_nFieldType;
  if ( m_nFieldType != RESOURCE_FIELD_TYPE_STRUCT )
    return g_pResourceSystem->GetFieldSize(this: g_pResourceSystem, a2: m_nFieldType);
  if ( pIntroDct != nullptr )
  {
    m_nTypeChainCount = this->m_nTypeChainCount;
    if ( m_nTypeChainCount == 1 )
      return CResourceIntrospection::FindStructIntrospection(this: pIntroDct, id: this->m_nTypeChain)->m_nMemorySize;
    else
      return CResourceIntrospection::FindStructIntrospection(
               this: pIntroDct,
               id: *(_DWORD *)((char *)&this->m_nFieldType + 4 * m_nTypeChainCount + this->m_nTypeChain))->m_nMemorySize;
  }
  else
  {
    v7 = this->m_nTypeChainCount;
    if ( v7 == 1 )
      m_nTypeChain = this->m_nTypeChain;
    else
      m_nTypeChain = *(_DWORD *)((char *)&this->m_nFieldType + 4 * v7 + this->m_nTypeChain);
    return g_pResourceSystem->FindStructIntrospection_2(this: g_pResourceSystem, a2: m_nTypeChain)->m_nMemorySize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FFE0
// Name: public: int CResourceFieldIntrospection::GetElementDiskSize(int,class CResourceIntrospection const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceFieldIntrospection::GetElementDiskSize(
        CResourceFieldIntrospection *this,
        int nTypeChainIndex,
        const CResourceIntrospection *pIntroDct)
{
  ResourceFieldType_t m_nFieldType; // edx
  __int16 m_nTypeChainCount; // dx
  __int16 v7; // cx
  unsigned int m_nTypeChain; // eax

  if ( nTypeChainIndex != 0 )
    m_nFieldType = *(_DWORD *)((char *)&this->m_nFieldType + 4 * nTypeChainIndex + this->m_nTypeChain);
  else
    m_nFieldType = this->m_nFieldType;
  if ( m_nFieldType != RESOURCE_FIELD_TYPE_STRUCT )
    return g_pResourceSystem->GetFieldSize(this: g_pResourceSystem, a2: m_nFieldType);
  if ( pIntroDct != nullptr )
  {
    m_nTypeChainCount = this->m_nTypeChainCount;
    if ( m_nTypeChainCount == 1 )
      return CResourceIntrospection::FindStructIntrospection(this: pIntroDct, id: this->m_nTypeChain)->m_nDiskSize;
    else
      return CResourceIntrospection::FindStructIntrospection(
               this: pIntroDct,
               id: *(_DWORD *)((char *)&this->m_nFieldType + 4 * m_nTypeChainCount + this->m_nTypeChain))->m_nDiskSize;
  }
  else
  {
    v7 = this->m_nTypeChainCount;
    if ( v7 == 1 )
      m_nTypeChain = this->m_nTypeChain;
    else
      m_nTypeChain = *(_DWORD *)((char *)&this->m_nFieldType + 4 * v7 + this->m_nTypeChain);
    return g_pResourceSystem->FindStructIntrospection_2(this: g_pResourceSystem, a2: m_nTypeChain)->m_nDiskSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010090
// Name: public: int CResourceFieldIntrospection::GetElementAlignment(int,class CResourceIntrospection const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceFieldIntrospection::GetElementAlignment(
        CResourceFieldIntrospection *this,
        int nTypeChainIndex,
        const CResourceIntrospection *pIntroDct)
{
  ResourceFieldType_t m_nFieldType; // edx
  __int16 m_nTypeChainCount; // dx
  __int16 v7; // cx
  unsigned int m_nTypeChain; // eax

  if ( nTypeChainIndex != 0 )
    m_nFieldType = *(_DWORD *)((char *)&this->m_nFieldType + 4 * nTypeChainIndex + this->m_nTypeChain);
  else
    m_nFieldType = this->m_nFieldType;
  if ( m_nFieldType != RESOURCE_FIELD_TYPE_STRUCT )
    return g_pResourceSystem->GetFieldAlignment(this: g_pResourceSystem, a2: m_nFieldType);
  if ( pIntroDct != nullptr )
  {
    m_nTypeChainCount = this->m_nTypeChainCount;
    if ( m_nTypeChainCount == 1 )
      return CResourceIntrospection::FindStructIntrospection(this: pIntroDct, id: this->m_nTypeChain)->m_nAlignment;
    else
      return CResourceIntrospection::FindStructIntrospection(
               this: pIntroDct,
               id: *(_DWORD *)((char *)&this->m_nFieldType + 4 * m_nTypeChainCount + this->m_nTypeChain))->m_nAlignment;
  }
  else
  {
    v7 = this->m_nTypeChainCount;
    if ( v7 == 1 )
      m_nTypeChain = this->m_nTypeChain;
    else
      m_nTypeChain = *(_DWORD *)((char *)&this->m_nFieldType + 4 * v7 + this->m_nTypeChain);
    return g_pResourceSystem->FindStructIntrospection_2(this: g_pResourceSystem, a2: m_nTypeChain)->m_nAlignment;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010140
// Name: public: class CResourceEnumValueIntrospection const __near * CResourceEnumIntrospection::GetEnumValue(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumValueIntrospection *__thiscall CResourceEnumIntrospection::GetEnumValue(
        CResourceEnumIntrospection *this,
        int nIndex)
{
  return (const CResourceEnumValueIntrospection *)((char *)&this->m_EnumValueIntrospection
                                                 + 8 * nIndex
                                                 + this->m_EnumValueIntrospection.m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10010160
// Name: public: char const __near * CResourceEnumIntrospection::FindEnumString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CResourceEnumIntrospection::FindEnumString(CResourceEnumIntrospection *this, int nValue)
{
  signed int m_nCount; // edx
  int v3; // eax
  int m_nOffset; // esi
  CResourceArray<CResourceEnumValueIntrospection> *p_m_EnumValueIntrospection; // ecx

  m_nCount = this->m_EnumValueIntrospection.m_nCount;
  v3 = 0;
  if ( m_nCount <= 0 )
    return nullptr;
  m_nOffset = this->m_EnumValueIntrospection.m_nOffset;
  p_m_EnumValueIntrospection = &this->m_EnumValueIntrospection;
  while ( *(unsigned int *)((char *)&p_m_EnumValueIntrospection[v3].m_nCount + m_nOffset) != nValue )
  {
    if ( ++v3 >= m_nCount )
      return nullptr;
  }
  return (char *)&p_m_EnumValueIntrospection[v3]
       + m_nOffset
       + *(int *)((char *)&p_m_EnumValueIntrospection[v3].m_nOffset + m_nOffset);
}

//------------------------------------------------------------------------------
// Address: 0x100101A0
// Name: public: virtual void CResourceIntrospectionTraversal::TraverseStruct(void const __near *,class CResourceStructIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionTraversal::TraverseStruct(
        CResourceIntrospectionTraversal *this,
        char *pStruct,
        const CResourceStructIntrospection *pStructIntro)
{
  signed int m_nCount; // ebx
  CResourceArray<CResourceFieldIntrospection> *p_m_FieldIntrospection; // ecx
  int v6; // edi
  const CResourceFieldIntrospection *v7; // eax
  __int16 v8; // cx
  CResourceArray<CResourceFieldIntrospection> *pStructIntroa; // [esp+10h] [ebp+8h]

  if ( this->VisitStruct(this, a2: pStruct, a3: pStructIntro) )
  {
    m_nCount = pStructIntro->m_FieldIntrospection.m_nCount;
    if ( m_nCount > 0 )
    {
      p_m_FieldIntrospection = &pStructIntro->m_FieldIntrospection;
      pStructIntroa = &pStructIntro->m_FieldIntrospection;
      v6 = 0;
      while ( 1 )
      {
        v7 = (const CResourceFieldIntrospection *)((char *)p_m_FieldIntrospection
                                                 + v6
                                                 + p_m_FieldIntrospection->m_nOffset);
        v8 = this->m_bTraverseDiskLayout ? v7->m_nOnDiskOffset : v7->m_nInMemoryOffset;
        this->TraverseField(this, a2: &pStruct[v8], a3: v7, a4: (ResourceFieldType_t)v7->m_nFieldType, a5: 0);
        v6 += 20;
        if ( --m_nCount == 0 )
          break;
        p_m_FieldIntrospection = pStructIntroa;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010220
// Name: protected: virtual void CResourceIntrospectionTraversal::TraverseRootField(void const __near *,class CResourceFieldIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionTraversal::TraverseRootField(
        CResourceIntrospectionTraversal *this,
        const void *pField,
        const CResourceFieldIntrospection *pFieldIntro)
{
  __int16 m_nTypeChainCount; // ax
  int m_nFieldType; // ecx
  unsigned int m_nTypeChain; // esi
  CResourceIntrospection *v7; // ecx
  const CResourceEnumIntrospection *EnumIntrospection; // eax
  CResourceIntrospection *m_pResIntro; // ecx
  const CResourceStructIntrospection *StructIntrospection; // eax

  if ( this->VisitRootField(this, a2: pField, a3: pFieldIntro) && pField != nullptr )
  {
    m_nTypeChainCount = pFieldIntro->m_nTypeChainCount;
    if ( m_nTypeChainCount == 1 )
      m_nFieldType = pFieldIntro->m_nFieldType;
    else
      m_nFieldType = *(_DWORD *)((char *)&pFieldIntro->m_nOnDiskOffset
                               + 4 * m_nTypeChainCount
                               + pFieldIntro->m_nTypeChain);
    if ( m_nTypeChainCount == 1 )
      m_nTypeChain = pFieldIntro->m_nTypeChain;
    else
      m_nTypeChain = *(_DWORD *)((char *)&pFieldIntro->m_nFieldType + 4 * m_nTypeChainCount + pFieldIntro->m_nTypeChain);
    if ( m_nFieldType == 3 )
    {
      m_pResIntro = this->m_pResIntro;
      if ( m_pResIntro != nullptr )
        StructIntrospection = CResourceIntrospection::FindStructIntrospection(this: m_pResIntro, id: m_nTypeChain);
      else
        StructIntrospection = g_pResourceSystem->FindStructIntrospection_2(this: g_pResourceSystem, a2: m_nTypeChain);
      this->TraverseStruct(this, a2: pField, a3: StructIntrospection);
    }
    else if ( m_nFieldType == 4 )
    {
      v7 = this->m_pResIntro;
      if ( v7 != nullptr )
        EnumIntrospection = CResourceIntrospection::FindEnumIntrospection(this: v7, id: m_nTypeChain);
      else
        EnumIntrospection = g_pResourceSystem->FindEnumIntrospection_2(this: g_pResourceSystem, a2: m_nTypeChain);
      this->VisitEnum(this, a2: pField, a3: EnumIntrospection);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010300
// Name: protected: virtual void CResourceIntrospectionTraversal::TraverseField(void const __near *,class CResourceFieldIntrospection const __near *,enum ResourceFieldType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionTraversal::TraverseField(
        CResourceIntrospectionTraversal *this,
        const void **pField,
        CResourceFieldIntrospection *pFieldIntro,
        ResourceFieldType_t fieldType,
        int nTypeChainIndex)
{
  const void **v5; // ebx
  int v6; // ebp
  int ElementDiskSize; // eax
  int m_nCount; // eax
  int v11; // ebp
  int ElementMemorySize; // eax
  char *v13; // ecx
  char *v14; // ebx
  bool v15; // zf
  int nStride; // [esp+1Ch] [ebp-14h]
  int v17; // [esp+20h] [ebp-10h]
  char *i; // [esp+24h] [ebp-Ch]
  const void **v19; // [esp+28h] [ebp-8h]
  int v20; // [esp+2Ch] [ebp-4h]
  ResourceFieldType_t subFieldType; // [esp+38h] [ebp+8h]
  int nTypeChainIndexa; // [esp+40h] [ebp+10h]

  v5 = pField;
  v6 = nTypeChainIndex;
  if ( this->VisitField(this, a2: pField, a3: pFieldIntro, a4: nTypeChainIndex) )
  {
    if ( this->m_bTraverseDiskLayout )
      ElementDiskSize = CResourceFieldIntrospection::GetElementDiskSize(
                          this: pFieldIntro,
                          nTypeChainIndex,
                          pIntroDct: this->m_pResIntro);
    else
      ElementDiskSize = CResourceFieldIntrospection::GetElementMemorySize(
                          this: pFieldIntro,
                          nTypeChainIndex,
                          pIntroDct: this->m_pResIntro);
    nStride = ElementDiskSize;
    m_nCount = 1;
    if ( nTypeChainIndex == 0 )
    {
      m_nCount = pFieldIntro->m_nCount;
      if ( (__int16)m_nCount <= 0 )
        m_nCount = 1;
    }
    if ( nTypeChainIndex == pFieldIntro->m_nTypeChainCount - 1 )
    {
      for ( nTypeChainIndexa = m_nCount; nTypeChainIndexa != 0; --nTypeChainIndexa )
      {
        this->TraverseRootField(this, a2: v5, a3: pFieldIntro);
        v5 = (const void **)((char *)v5 + nStride);
      }
    }
    else
    {
      if ( nTypeChainIndex != 0 )
        subFieldType = *(_DWORD *)((char *)&pFieldIntro->m_nFieldType + 4 * nTypeChainIndex + pFieldIntro->m_nTypeChain);
      else
        subFieldType = pFieldIntro->m_nFieldType;
      v19 = pField;
      v20 = m_nCount;
      do
      {
        switch ( fieldType )
        {
          case RESOURCE_FIELD_TYPE_RESOURCE_POINTER:
            this->TraverseField(this, a2: (char *)*v5 + (_DWORD)v5, a3: pFieldIntro, a4: subFieldType, a5: v6 + 1);
            break;
          case RESOURCE_FIELD_TYPE_RESOURCE_ARRAY:
            v11 = v6 + 1;
            if ( this->m_bTraverseDiskLayout )
              ElementMemorySize = CResourceFieldIntrospection::GetElementDiskSize(
                                    this: pFieldIntro,
                                    nTypeChainIndex: v11,
                                    pIntroDct: this->m_pResIntro);
            else
              ElementMemorySize = CResourceFieldIntrospection::GetElementMemorySize(
                                    this: pFieldIntro,
                                    nTypeChainIndex: v11,
                                    pIntroDct: this->m_pResIntro);
            v13 = (char *)v5[1];
            v17 = ElementMemorySize;
            if ( v13 != nullptr )
            {
              v14 = (char *)*v5 + (_DWORD)v5;
              for ( i = v13; i != nullptr; --i )
              {
                this->TraverseField(this, a2: v14, a3: pFieldIntro, a4: subFieldType, a5: v11);
                v14 += v17;
              }
              v5 = v19;
            }
            v6 = nTypeChainIndex;
            break;
          case RESOURCE_FIELD_TYPE_C_POINTER:
            this->TraverseField(this, a2: *v5, a3: pFieldIntro, a4: subFieldType, a5: v6 + 1);
            break;
          default:
            break;
        }
        v5 = (const void **)((char *)v5 + nStride);
        v15 = v20-- == 1;
        v19 = v5;
      }
      while ( !v15 );
    }
    this->PostVisitField(this, a2: pField, a3: pFieldIntro, a4: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104B0
// Name: public: virtual void CSchemaClassBinding<class CResourceEnumIntrospection>::ConstructInPlace(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemaClassBinding<CResourceEnumIntrospection>::ConstructInPlace(
        CSchemaClassBinding<CResourceEnumIntrospection> *this,
        _DWORD *pMemory)
{
  if ( pMemory != nullptr )
  {
    pMemory[3] = 0;
    pMemory[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104D0
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospection::FindStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospection::FindStructIntrospectionForResourceType(
        CResourceIntrospection *this,
        int nType)
{
  const CResourceStructIntrospection *v3; // eax

  v3 = g_pResourceSystem->FindStructIntrospectionForResourceType(this: g_pResourceSystem, a2: nType);
  if ( v3 != nullptr )
    return CResourceIntrospection::FindStructIntrospection(this, id: v3->m_nId);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010500
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospection::FindPermanentStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospection::FindPermanentStructIntrospectionForResourceType(
        CResourceIntrospection *this,
        int nType)
{
  const CResourceStructIntrospection *v3; // eax

  v3 = g_pResourceSystem->FindPermanentStructIntrospectionForResourceType(this: g_pResourceSystem, a2: nType);
  if ( v3 != nullptr )
    return CResourceIntrospection::FindStructIntrospection(this, id: v3->m_nId);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA40
// Name: _dynamic_initializer_for__CResourceFieldIntrospection::s_CResourceFieldIntrospectionSchemaBinding__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
CSchemaClassBindingBase *dynamic_initializer_for__CResourceFieldIntrospection::s_CResourceFieldIntrospectionSchemaBinding__()
{
  CSchemaClassBindingBase *result; // eax

  result = CSchemaClassBindingBase::sm_pClassBindingList;
  CResourceFieldIntrospection::s_CResourceFieldIntrospectionSchemaBinding.m_pNextBinding = CSchemaClassBindingBase::sm_pClassBindingList;
  CSchemaClassBindingBase::sm_pClassBindingList = &CResourceFieldIntrospection::s_CResourceFieldIntrospectionSchemaBinding;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA60
// Name: _dynamic_initializer_for__CResourceEnumIntrospection::s_CResourceEnumIntrospectionSchemaBinding__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
CSchemaClassBindingBase *dynamic_initializer_for__CResourceEnumIntrospection::s_CResourceEnumIntrospectionSchemaBinding__()
{
  CSchemaClassBindingBase *result; // eax

  result = CSchemaClassBindingBase::sm_pClassBindingList;
  CResourceEnumIntrospection::s_CResourceEnumIntrospectionSchemaBinding.m_pNextBinding = CSchemaClassBindingBase::sm_pClassBindingList;
  CSchemaClassBindingBase::sm_pClassBindingList = &CResourceEnumIntrospection::s_CResourceEnumIntrospectionSchemaBinding;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA80
// Name: _dynamic_initializer_for__CResourceTypedefIntrospection::s_CResourceTypedefIntrospectionSchemaBinding__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSchemaClassBindingBase *dynamic_initializer_for__CResourceTypedefIntrospection::s_CResourceTypedefIntrospectionSchemaBinding__()
{
  CSchemaClassBindingBase *result; // eax

  result = CSchemaClassBindingBase::sm_pClassBindingList;
  CResourceTypedefIntrospection::s_CResourceTypedefIntrospectionSchemaBinding.m_pNextBinding = CSchemaClassBindingBase::sm_pClassBindingList;
  CSchemaClassBindingBase::sm_pClassBindingList = &CResourceTypedefIntrospection::s_CResourceTypedefIntrospectionSchemaBinding;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DAA0
// Name: _dynamic_atexit_destructor_for__s_ResourceSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ResourceSystem__()
{
  CResourceSystem::~CResourceSystem(this: &s_ResourceSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1001DAB0
// Name: _dynamic_atexit_destructor_for__s_FileAtomicFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_FileAtomicFactory__()
{
  s_FileAtomicFactory.__vftable = (CResourceTypeManagerFactory<CResourceTypeManagerFileAtomic>_vtbl *)&CResourceTypeManagerFactoryBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1001DAC0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB00
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1001DB50
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}
