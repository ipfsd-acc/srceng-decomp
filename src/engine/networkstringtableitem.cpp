// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/networkstringtableitem.cpp
// Functions: 8
// ============================================================

#include "engine\networkstringtableitem.h"

//------------------------------------------------------------------------------
// Address: 0x101C7F50
// Name: public: CNetworkStringTableItem::CNetworkStringTableItem(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableItem *__thiscall CNetworkStringTableItem::CNetworkStringTableItem(CNetworkStringTableItem *this)
{
  this->m_pUserData = nullptr;
  this->m_nUserDataLength = 0;
  this->m_nTickChanged = 0;
  this->m_nTickCreated = 0;
  this->m_pChangeList = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C7F70
// Name: public: void const __near * CNetworkStringTableItem::GetUserData(int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CNetworkStringTableItem::GetUserData(CNetworkStringTableItem *this, int *length)
{
  if ( length != nullptr )
    *length = this->m_nUserDataLength;
  return this->m_pUserData;
}

//------------------------------------------------------------------------------
// Address: 0x101C7F90
// Name: public: int CNetworkStringTableItem::RestoreTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTableItem::RestoreTick(CNetworkStringTableItem *this, int tick)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  CNetworkStringTableItem::itemchange_s *m_pMemory; // esi
  int v4; // edx
  CNetworkStringTableItem::itemchange_s *v5; // eax
  int result; // eax

  m_pChangeList = this->m_pChangeList;
  m_pMemory = m_pChangeList->m_Memory.m_pMemory;
  v4 = 1;
  if ( m_pChangeList->m_Size > 1 )
  {
    v5 = m_pMemory + 1;
    do
    {
      if ( v5->tick > tick )
        break;
      m_pMemory = v5;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pChangeList->m_Size );
  }
  if ( m_pMemory->tick <= tick )
  {
    this->m_pUserData = m_pMemory->data;
    this->m_nUserDataLength = m_pMemory->length;
    result = m_pMemory->tick;
    this->m_nTickChanged = m_pMemory->tick;
  }
  else
  {
    this->m_pUserData = nullptr;
    this->m_nUserDataLength = 0;
    this->m_nTickChanged = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C8070
// Name: public: void CNetworkStringTableItem::EnableChangeHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::EnableChangeHistory(CNetworkStringTableItem *this)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v2; // eax

  if ( this->m_pChangeList == nullptr )
  {
    v2 = (CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      v2->m_Memory.m_pMemory = nullptr;
      v2->m_Memory.m_nAllocationCount = 0;
      v2->m_Memory.m_nGrowSize = 0;
      v2->m_Size = 0;
      v2->m_pElements = nullptr;
      this->m_pChangeList = v2;
    }
    else
    {
      this->m_pChangeList = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C80B0
// Name: public: CNetworkStringTableItem::~CNetworkStringTableItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::~CNetworkStringTableItem(CNetworkStringTableItem *this)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  int v3; // ebx
  int v4; // edi
  unsigned __int8 *data; // eax
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v6; // edi

  m_pChangeList = this->m_pChangeList;
  if ( m_pChangeList != nullptr )
  {
    v3 = 0;
    if ( m_pChangeList->m_Size > 0 )
    {
      v4 = 0;
      do
      {
        data = this->m_pChangeList->m_Memory.m_pMemory[v4].data;
        if ( data != nullptr )
          free(pMem: data);
        ++v3;
        ++v4;
      }
      while ( v3 < this->m_pChangeList->m_Size );
    }
    v6 = this->m_pChangeList;
    if ( v6 != nullptr )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pChangeList);
      free(pMem: v6);
    }
    this->m_pUserData = nullptr;
  }
  else if ( this->m_pUserData != nullptr )
  {
    free(pMem: this->m_pUserData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8140
// Name: public: void CNetworkStringTableItem::UpdateChangeList(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::UpdateChangeList(
        CNetworkStringTableItem *this,
        int tick,
        int length,
        const void *userData)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  int m_Size; // esi
  unsigned __int8 *data; // edi
  int v7; // ebx
  int v8; // ecx
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v9; // esi
  CNetworkStringTableItem::itemchange_s item; // [esp+Ch] [ebp-10h] BYREF
  CNetworkStringTableItem *v11; // [esp+18h] [ebp-4h]

  m_pChangeList = this->m_pChangeList;
  m_Size = m_pChangeList->m_Size;
  v11 = this;
  if ( m_Size > 0 )
  {
    data = m_pChangeList->m_Memory.m_pMemory[m_Size - 1].data;
    v7 = m_pChangeList->m_Memory.m_pMemory[m_Size - 1].tick;
    if ( data == nullptr && userData == nullptr
      || m_pChangeList->m_Memory.m_pMemory[m_Size - 1].length == length
      && data != nullptr
      && userData != nullptr
      && _V_memcmp(m1: userData, m2: data, count: length) == 0 )
    {
      return;
    }
    if ( v7 == tick )
    {
      if ( data != nullptr )
        free(pMem: data);
      v8 = m_Size - 1;
      v9 = v11->m_pChangeList;
      if ( v9->m_Size - v8 - 1 > 0 )
        _V_memmove(
          dest: &v9->m_Memory.m_pMemory[v8],
          src: &v9->m_Memory.m_pMemory[v8 + 1],
          count: 12 * (v9->m_Size - v8 - 1));
      --v9->m_Size;
    }
  }
  item.tick = tick;
  if ( userData != nullptr && length != 0 )
  {
    item.length = length;
    item.data = (unsigned __int8 *)MemAlloc_Alloc(nSize: length);
    _V_memcpy(dest: item.data, src: userData, count: length);
  }
  else
  {
    item.data = nullptr;
    item.length = 0;
  }
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v11->m_pChangeList,
    elem: v11->m_pChangeList->m_Size,
    src: (const Vector *)&item);
}

//------------------------------------------------------------------------------
// Address: 0x101C8240
// Name: public: bool CNetworkStringTableItem::SetUserData(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableItem::SetUserData(
        CNetworkStringTableItem *this,
        int tick,
        int length,
        const void *userData)
{
  unsigned __int8 *m_pUserData; // eax
  unsigned __int8 *v7; // eax

  if ( this->m_pChangeList != nullptr )
  {
    CNetworkStringTableItem::UpdateChangeList(this, tick, length, userData);
    return 0;
  }
  m_pUserData = this->m_pUserData;
  if ( userData != nullptr )
  {
    if ( m_pUserData == nullptr )
      goto LABEL_11;
  }
  else if ( m_pUserData == nullptr )
  {
    return 0;
  }
  if ( length == this->m_nUserDataLength && _V_memcmp(m1: m_pUserData, m2: userData, count: length) == 0 )
    return 0;
  if ( this->m_pUserData != nullptr )
    free(pMem: this->m_pUserData);
LABEL_11:
  this->m_nUserDataLength = length;
  if ( length <= 0 )
  {
    this->m_nTickChanged = tick;
    this->m_pUserData = nullptr;
  }
  else
  {
    v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: length);
    this->m_pUserData = v7;
    _V_memcpy(dest: v7, src: userData, count: length);
    this->m_nTickChanged = tick;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C82F0
// Name: __CreateCNetworkStringTableContainerINetworkStringTableContainer_interface_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__cdecl _CreateCNetworkStringTableContainerINetworkStringTableContainer_interface_0()
{
  return &s_NetworkStringTableServer;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101C8390
// Name: public: CNetworkStringTableItem::CNetworkStringTableItem(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableItem *__thiscall CNetworkStringTableItem::CNetworkStringTableItem(CNetworkStringTableItem *this)
{
  this->m_pUserData = nullptr;
  this->m_nUserDataLength = 0;
  this->m_nTickChanged = 0;
  this->m_nTickCreated = 0;
  this->m_pChangeList = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C83B0
// Name: public: void const __near * CNetworkStringTableItem::GetUserData(int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CNetworkStringTableItem::GetUserData(CNetworkStringTableItem *this, int *length)
{
  if ( length != nullptr )
    *length = this->m_nUserDataLength;
  return this->m_pUserData;
}

//------------------------------------------------------------------------------
// Address: 0x101C8470
// Name: public: int CNetworkStringTableItem::RestoreTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTableItem::RestoreTick(CNetworkStringTableItem *this, int tick)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  CNetworkStringTableItem::itemchange_s *m_pMemory; // esi
  int v4; // edx
  CNetworkStringTableItem::itemchange_s *v5; // eax
  int result; // eax

  m_pChangeList = this->m_pChangeList;
  m_pMemory = m_pChangeList->m_Memory.m_pMemory;
  v4 = 1;
  if ( m_pChangeList->m_Size > 1 )
  {
    v5 = m_pMemory + 1;
    do
    {
      if ( v5->tick > tick )
        break;
      m_pMemory = v5;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pChangeList->m_Size );
  }
  if ( m_pMemory->tick <= tick )
  {
    this->m_pUserData = m_pMemory->data;
    this->m_nUserDataLength = m_pMemory->length;
    result = m_pMemory->tick;
    this->m_nTickChanged = m_pMemory->tick;
  }
  else
  {
    this->m_pUserData = nullptr;
    this->m_nUserDataLength = 0;
    this->m_nTickChanged = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C84D0
// Name: public: void CNetworkStringTableItem::EnableChangeHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::EnableChangeHistory(CNetworkStringTableItem *this)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v2; // eax

  if ( this->m_pChangeList == nullptr )
  {
    v2 = (CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      v2->m_Memory.m_pMemory = nullptr;
      v2->m_Memory.m_nAllocationCount = 0;
      v2->m_Memory.m_nGrowSize = 0;
      v2->m_Size = 0;
      v2->m_pElements = nullptr;
      this->m_pChangeList = v2;
    }
    else
    {
      this->m_pChangeList = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8510
// Name: public: CNetworkStringTableItem::~CNetworkStringTableItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::~CNetworkStringTableItem(CNetworkStringTableItem *this)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  int v3; // ebx
  int v4; // edi
  unsigned __int8 *data; // eax
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v6; // edi

  m_pChangeList = this->m_pChangeList;
  if ( m_pChangeList != nullptr )
  {
    v3 = 0;
    if ( m_pChangeList->m_Size > 0 )
    {
      v4 = 0;
      do
      {
        data = this->m_pChangeList->m_Memory.m_pMemory[v4].data;
        if ( data != nullptr )
          free(pMem: data);
        ++v3;
        ++v4;
      }
      while ( v3 < this->m_pChangeList->m_Size );
    }
    v6 = this->m_pChangeList;
    if ( v6 != nullptr )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pChangeList);
      free(pMem: v6);
    }
    this->m_pUserData = nullptr;
  }
  else if ( this->m_pUserData != nullptr )
  {
    free(pMem: this->m_pUserData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C85A0
// Name: public: void CNetworkStringTableItem::UpdateChangeList(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableItem::UpdateChangeList(
        CNetworkStringTableItem *this,
        int tick,
        int length,
        const void *userData)
{
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *m_pChangeList; // eax
  int m_Size; // esi
  unsigned __int8 *data; // edi
  int v7; // ebx
  int v8; // ecx
  CUtlVector<CNetworkStringTableItem::itemchange_s,CUtlMemory<CNetworkStringTableItem::itemchange_s,int> > *v9; // esi
  CNetworkStringTableItem::itemchange_s item; // [esp+Ch] [ebp-10h] BYREF
  CNetworkStringTableItem *v11; // [esp+18h] [ebp-4h]

  m_pChangeList = this->m_pChangeList;
  m_Size = m_pChangeList->m_Size;
  v11 = this;
  if ( m_Size > 0 )
  {
    data = m_pChangeList->m_Memory.m_pMemory[m_Size - 1].data;
    v7 = m_pChangeList->m_Memory.m_pMemory[m_Size - 1].tick;
    if ( data == nullptr && userData == nullptr
      || m_pChangeList->m_Memory.m_pMemory[m_Size - 1].length == length
      && data != nullptr
      && userData != nullptr
      && _V_memcmp(m1: userData, m2: data, count: length) == 0 )
    {
      return;
    }
    if ( v7 == tick )
    {
      if ( data != nullptr )
        free(pMem: data);
      v8 = m_Size - 1;
      v9 = v11->m_pChangeList;
      if ( v9->m_Size - v8 - 1 > 0 )
        _V_memmove(
          dest: &v9->m_Memory.m_pMemory[v8],
          src: &v9->m_Memory.m_pMemory[v8 + 1],
          count: 12 * (v9->m_Size - v8 - 1));
      --v9->m_Size;
    }
  }
  item.tick = tick;
  if ( userData != nullptr && length != 0 )
  {
    item.length = length;
    item.data = (unsigned __int8 *)MemAlloc_Alloc(nSize: length);
    _V_memcpy(dest: item.data, src: userData, count: length);
  }
  else
  {
    item.data = nullptr;
    item.length = 0;
  }
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v11->m_pChangeList,
    elem: v11->m_pChangeList->m_Size,
    src: (const Vector *)&item);
}

//------------------------------------------------------------------------------
// Address: 0x101C86A0
// Name: public: bool CNetworkStringTableItem::SetUserData(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableItem::SetUserData(
        CNetworkStringTableItem *this,
        int tick,
        int length,
        const void *userData)
{
  unsigned __int8 *m_pUserData; // eax
  unsigned __int8 *v7; // eax

  if ( this->m_pChangeList != nullptr )
  {
    CNetworkStringTableItem::UpdateChangeList(this, tick, length, userData);
    return 0;
  }
  m_pUserData = this->m_pUserData;
  if ( userData != nullptr )
  {
    if ( m_pUserData == nullptr )
      goto LABEL_11;
  }
  else if ( m_pUserData == nullptr )
  {
    return 0;
  }
  if ( length == this->m_nUserDataLength && _V_memcmp(m1: m_pUserData, m2: userData, count: length) == 0 )
    return 0;
  if ( this->m_pUserData != nullptr )
    free(pMem: this->m_pUserData);
LABEL_11:
  this->m_nUserDataLength = length;
  if ( length <= 0 )
  {
    this->m_nTickChanged = tick;
    this->m_pUserData = nullptr;
  }
  else
  {
    v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: length);
    this->m_pUserData = v7;
    _V_memcpy(dest: v7, src: userData, count: length);
    this->m_nTickChanged = tick;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8750
// Name: __CreateCNetworkStringTableContainerINetworkStringTableContainer_interface_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__cdecl _CreateCNetworkStringTableContainerINetworkStringTableContainer_interface_0()
{
  return &s_NetworkStringTableServer;
}

} // namespace engine_xlsp
