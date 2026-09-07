// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/netpacket.cpp
// Functions: 4
// ============================================================

#include "gcsdk\netpacket.h"

//------------------------------------------------------------------------------
// Address: 0x10017310
// Name: public: GCSDK::CNetPacket::CNetPacket(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CNetPacket *__thiscall GCSDK::CNetPacket::CNetPacket(GCSDK::CNetPacket *this)
{
  this->m_cRef = 0;
  this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017320
// Name: public: void GCSDK::CNetPacket::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CNetPacket::AddRef(GCSDK::CNetPacket *this)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *m_pubData; // [esp-8h] [ebp-Ch]
  unsigned int m_cubData; // [esp-4h] [ebp-8h]

  if ( ++this->m_cRef > 1 && this->m_pubNetworkBuffer == nullptr )
  {
    v2 = (unsigned __int8 *)CThreadSafeMultiMemoryPool::Alloc(this: &GCSDK::g_MemPoolMsg, cubAllocSize: this->m_cubData);
    m_cubData = this->m_cubData;
    m_pubData = this->m_pubData;
    this->m_pubNetworkBuffer = v2;
    memcpy(dst: v2, src: m_pubData, count: m_cubData);
    this->m_pubData = this->m_pubNetworkBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017360
// Name: public: void GCSDK::CNetPacket::Init(unsigned char __near *,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CNetPacket::Init(
        GCSDK::CNetPacket *this,
        unsigned __int8 *pubData,
        unsigned int cubData,
        unsigned __int8 *pubNetworkBuffer)
{
  bool v5; // cc
  unsigned __int8 *v6; // eax
  unsigned __int8 *m_pubData; // [esp-8h] [ebp-Ch]
  unsigned int m_cubData; // [esp-4h] [ebp-8h]

  v5 = ++this->m_cRef <= 1;
  this->m_pubData = pubData;
  this->m_cubData = cubData;
  this->m_pubNetworkBuffer = pubNetworkBuffer;
  if ( !v5 && pubNetworkBuffer == nullptr )
  {
    v6 = (unsigned __int8 *)CThreadSafeMultiMemoryPool::Alloc(this: &GCSDK::g_MemPoolMsg, cubAllocSize: cubData);
    m_cubData = this->m_cubData;
    m_pubData = this->m_pubData;
    this->m_pubNetworkBuffer = v6;
    memcpy(dst: v6, src: m_pubData, count: m_cubData);
    this->m_pubData = this->m_pubNetworkBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100173B0
// Name: public: void GCSDK::CNetPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CNetPacket::Release(GCSDK::CNetPacket *this)
{
  if ( this->m_cRef-- == 1 )
  {
    if ( this->m_pubNetworkBuffer != nullptr )
      CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: (_DWORD *)this->m_pubNetworkBuffer);
    --GCSDK::g_cNetPacket;
    CUtlMemoryPool::Free(this: &GCSDK::CNetPacketPool::sm_MemPoolNetPacket, memBlock: this);
  }
}
