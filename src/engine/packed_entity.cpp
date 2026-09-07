// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/packed_entity.cpp
// Functions: 7
// ============================================================

#include "engine\packed_entity.h"

//------------------------------------------------------------------------------
// Address: 0x101C8380
// Name: public: bool PackedEntity::AllocAndCopyPadded(void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PackedEntity::AllocAndCopyPadded(PackedEntity *this, const void *pData, unsigned int size)
{
  void *m_pData; // eax
  void *v5; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pData);
    this->m_pData = nullptr;
  }
  v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * ((size + 3) >> 2));
  this->m_pData = v5;
  if ( v5 == nullptr )
    return 0;
  _V_memcpy(dest: v5, src: pData, count: size);
  this->m_nBits = 32 * ((size + 3) >> 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8400
// Name: public: int PackedEntity::GetPropsChangedAfterTick(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PackedEntity::GetPropsChangedAfterTick(PackedEntity *this, int iTick, int *iOutProps, int nMaxOutProps)
{
  if ( this->m_pChangeFrameList != nullptr )
    return this->m_pChangeFrameList->GetPropsChangedAfterTick(
             this: this->m_pChangeFrameList,
             a2: iTick,
             a3: iOutProps,
             a4: nMaxOutProps);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8420
// Name: public: void PackedEntity::SetServerAndClientClass(class ServerClass __near *,class ClientClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::SetServerAndClientClass(
        PackedEntity *this,
        ServerClass *pServerClass,
        ClientClass *pClientClass)
{
  this->m_pServerClass = pServerClass;
  this->m_pClientClass = pClientClass;
  if ( pServerClass != nullptr )
    *((_DWORD *)this + 12) = (*((unsigned __int8 *)pServerClass->m_pTable + 16) << 29)
                           ^ (*((_DWORD *)this + 12)
                            ^ (*((unsigned __int8 *)pServerClass->m_pTable + 16) << 29))
                           & 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101C8460
// Name: public: bool PackedEntity::CompareRecipients(class CUtlMemory<class CSendProxyRecipients,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PackedEntity::CompareRecipients(
        PackedEntity *this,
        const CUtlMemory<CSendProxyRecipients,int> *recipients)
{
  int m_Size; // eax
  CSendProxyRecipients *m_pMemory; // ecx
  CSendProxyRecipients *v5; // esi
  unsigned int v6; // edx

  m_Size = this->m_Recipients.m_Size;
  if ( recipients->m_nAllocationCount != m_Size )
    return false;
  m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
  v5 = recipients->m_pMemory;
  v6 = 8 * m_Size;
  if ( (unsigned int)(8 * m_Size) < 4 )
  {
LABEL_6:
    if ( v6 == 0 )
      return true;
  }
  else
  {
    while ( v5->m_Bits.m_Ints[0] == m_pMemory->m_Bits.m_Ints[0] )
    {
      v6 -= 4;
      m_pMemory = (CSendProxyRecipients *)((char *)m_pMemory + 4);
      v5 = (CSendProxyRecipients *)((char *)v5 + 4);
      if ( v6 < 4 )
        goto LABEL_6;
    }
  }
  return LOBYTE(v5->m_Bits.m_Ints[0]) == LOBYTE(m_pMemory->m_Bits.m_Ints[0])
      && (v6 <= 1
       || BYTE1(v5->m_Bits.m_Ints[0]) == BYTE1(m_pMemory->m_Bits.m_Ints[0])
       && (v6 <= 2 || BYTE2(v5->m_Bits.m_Ints[0]) == BYTE2(m_pMemory->m_Bits.m_Ints[0]) && v6 <= 3));
}

//------------------------------------------------------------------------------
// Address: 0x101C8500
// Name: public: PackedEntity::PackedEntity(void)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall PackedEntity::PackedEntity(PackedEntity *this)
{
  this->m_ReferenceCount.m_value = 0;
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_Size = 0;
  this->m_Recipients.m_pElements = nullptr;
  this->m_pData = nullptr;
  this->m_pChangeFrameList = nullptr;
  *((_DWORD *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C8520
// Name: public: PackedEntity::~PackedEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::~PackedEntity(PackedEntity *this)
{
  void *m_pData; // eax
  IChangeFrameList *m_pChangeFrameList; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pData);
    this->m_pData = nullptr;
  }
  m_pChangeFrameList = this->m_pChangeFrameList;
  if ( m_pChangeFrameList != nullptr )
  {
    m_pChangeFrameList->Release(this: m_pChangeFrameList);
    this->m_pChangeFrameList = nullptr;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Recipients);
}

//------------------------------------------------------------------------------
// Address: 0x101C85F0
// Name: public: void PackedEntity::SetRecipients(class CUtlMemory<class CSendProxyRecipients,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::SetRecipients(PackedEntity *this, const CUtlMemory<CSendProxyRecipients,int> *recipients)
{
  int m_nAllocationCount; // esi
  CSendProxyRecipients *m_pMemory; // edi
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int> > *p_m_Recipients; // ebx
  int v5; // edx
  CSendProxyRecipients *v6; // eax
  unsigned int v7; // ecx
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int> > *recipientsa; // [esp+14h] [ebp+8h]

  m_nAllocationCount = recipients->m_nAllocationCount;
  m_pMemory = recipients->m_pMemory;
  p_m_Recipients = &this->m_Recipients;
  recipientsa = &this->m_Recipients;
  this->m_Recipients.m_Size = 0;
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int>>::InsertMultipleBefore(
    this: &this->m_Recipients,
    elem: 0,
    num: m_nAllocationCount);
  v5 = 0;
  if ( m_nAllocationCount > 0 )
  {
    while ( 1 )
    {
      v6 = &p_m_Recipients->m_Memory.m_pMemory[v5];
      v6->m_Bits.m_Ints[0] = m_pMemory[v5].m_Bits.m_Ints[0];
      v7 = m_pMemory[v5++].m_Bits.m_Ints[1];
      v6->m_Bits.m_Ints[1] = v7;
      if ( v5 >= m_nAllocationCount )
        break;
      p_m_Recipients = recipientsa;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101C87E0
// Name: public: bool PackedEntity::AllocAndCopyPadded(void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PackedEntity::AllocAndCopyPadded(PackedEntity *this, const void *pData, unsigned int size)
{
  void *m_pData; // eax
  void *v5; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pData);
    this->m_pData = nullptr;
  }
  v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * ((size + 3) >> 2));
  this->m_pData = v5;
  if ( v5 == nullptr )
    return 0;
  _V_memcpy(dest: v5, src: pData, count: size);
  this->m_nBits = 32 * ((size + 3) >> 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8860
// Name: public: int PackedEntity::GetPropsChangedAfterTick(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PackedEntity::GetPropsChangedAfterTick(PackedEntity *this, int iTick, int *iOutProps, int nMaxOutProps)
{
  if ( this->m_pChangeFrameList != nullptr )
    return this->m_pChangeFrameList->GetPropsChangedAfterTick(
             this: this->m_pChangeFrameList,
             a2: iTick,
             a3: iOutProps,
             a4: nMaxOutProps);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8880
// Name: public: void PackedEntity::SetServerAndClientClass(class ServerClass __near *,class ClientClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::SetServerAndClientClass(
        PackedEntity *this,
        ServerClass *pServerClass,
        ClientClass *pClientClass)
{
  this->m_pServerClass = pServerClass;
  this->m_pClientClass = pClientClass;
  if ( pServerClass != nullptr )
    *((_DWORD *)this + 12) = (*((unsigned __int8 *)pServerClass->m_pTable + 16) << 29)
                           ^ (*((_DWORD *)this + 12)
                            ^ (*((unsigned __int8 *)pServerClass->m_pTable + 16) << 29))
                           & 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101C88C0
// Name: public: bool PackedEntity::CompareRecipients(class CUtlMemory<class CSendProxyRecipients,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PackedEntity::CompareRecipients(
        PackedEntity *this,
        const CUtlMemory<CSendProxyRecipients,int> *recipients)
{
  int m_Size; // eax
  CSendProxyRecipients *m_pMemory; // ecx
  CSendProxyRecipients *v5; // esi
  unsigned int v6; // edx

  m_Size = this->m_Recipients.m_Size;
  if ( recipients->m_nAllocationCount != m_Size )
    return false;
  m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
  v5 = recipients->m_pMemory;
  v6 = 8 * m_Size;
  if ( (unsigned int)(8 * m_Size) < 4 )
  {
LABEL_6:
    if ( v6 == 0 )
      return true;
  }
  else
  {
    while ( v5->m_Bits.m_Ints[0] == m_pMemory->m_Bits.m_Ints[0] )
    {
      v6 -= 4;
      m_pMemory = (CSendProxyRecipients *)((char *)m_pMemory + 4);
      v5 = (CSendProxyRecipients *)((char *)v5 + 4);
      if ( v6 < 4 )
        goto LABEL_6;
    }
  }
  return LOBYTE(v5->m_Bits.m_Ints[0]) == LOBYTE(m_pMemory->m_Bits.m_Ints[0])
      && (v6 <= 1
       || BYTE1(v5->m_Bits.m_Ints[0]) == BYTE1(m_pMemory->m_Bits.m_Ints[0])
       && (v6 <= 2 || BYTE2(v5->m_Bits.m_Ints[0]) == BYTE2(m_pMemory->m_Bits.m_Ints[0]) && v6 <= 3));
}

//------------------------------------------------------------------------------
// Address: 0x101C8960
// Name: public: PackedEntity::PackedEntity(void)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall PackedEntity::PackedEntity(PackedEntity *this)
{
  this->m_ReferenceCount.m_value = 0;
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_Size = 0;
  this->m_Recipients.m_pElements = nullptr;
  this->m_pData = nullptr;
  this->m_pChangeFrameList = nullptr;
  *((_DWORD *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C8980
// Name: public: PackedEntity::~PackedEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::~PackedEntity(PackedEntity *this)
{
  void *m_pData; // eax
  IChangeFrameList *m_pChangeFrameList; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pData);
    this->m_pData = nullptr;
  }
  m_pChangeFrameList = this->m_pChangeFrameList;
  if ( m_pChangeFrameList != nullptr )
  {
    m_pChangeFrameList->Release(this: m_pChangeFrameList);
    this->m_pChangeFrameList = nullptr;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Recipients);
}

//------------------------------------------------------------------------------
// Address: 0x101C8A50
// Name: public: void PackedEntity::SetRecipients(class CUtlMemory<class CSendProxyRecipients,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PackedEntity::SetRecipients(PackedEntity *this, const CUtlMemory<CSendProxyRecipients,int> *recipients)
{
  int m_nAllocationCount; // esi
  CSendProxyRecipients *m_pMemory; // edi
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int> > *p_m_Recipients; // ebx
  int v5; // edx
  CSendProxyRecipients *v6; // eax
  unsigned int v7; // ecx
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int> > *recipientsa; // [esp+14h] [ebp+8h]

  m_nAllocationCount = recipients->m_nAllocationCount;
  m_pMemory = recipients->m_pMemory;
  p_m_Recipients = &this->m_Recipients;
  recipientsa = &this->m_Recipients;
  this->m_Recipients.m_Size = 0;
  CUtlVector<CSendProxyRecipients,CUtlMemory<CSendProxyRecipients,int>>::InsertMultipleBefore(
    this: &this->m_Recipients,
    elem: 0,
    num: m_nAllocationCount);
  v5 = 0;
  if ( m_nAllocationCount > 0 )
  {
    while ( 1 )
    {
      v6 = &p_m_Recipients->m_Memory.m_pMemory[v5];
      v6->m_Bits.m_Ints[0] = m_pMemory[v5].m_Bits.m_Ints[0];
      v7 = m_pMemory[v5++].m_Bits.m_Ints[1];
      v6->m_Bits.m_Ints[1] = v7;
      if ( v5 >= m_nAllocationCount )
        break;
      p_m_Recipients = recipientsa;
    }
  }
}

} // namespace engine_xlsp
