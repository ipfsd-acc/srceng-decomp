// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/netpacketpool.cpp
// Functions: 2
// ============================================================

#include "gcsdk\netpacketpool.h"

//------------------------------------------------------------------------------
// Address: 0x100541E0
// Name: _dynamic_initializer_for__GCSDK::CNetPacketPool::sm_MemPoolNetPacket__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GCSDK::CNetPacketPool::sm_MemPoolNetPacket__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &GCSDK::CNetPacketPool::sm_MemPoolNetPacket,
    blockSize: 0x14u,
    numElements: 10,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__GCSDK::CNetPacketPool::sm_MemPoolNetPacket__);
}

//------------------------------------------------------------------------------
// Address: 0x100550F0
// Name: _dynamic_atexit_destructor_for__GCSDK::CNetPacketPool::sm_MemPoolNetPacket__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__GCSDK::CNetPacketPool::sm_MemPoolNetPacket__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &GCSDK::CNetPacketPool::sm_MemPoolNetPacket);
}
