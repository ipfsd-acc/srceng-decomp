// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/steam_datacenterjobs.cpp
// Functions: 6
// ============================================================

#include "matchmaking\steam_datacenterjobs.h"

//------------------------------------------------------------------------------
// Address: 0x10028450
// Name: public: CGCClientJobUpdateStats::CGCClientJobUpdateStats(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CGCClientJobUpdateStats *__thiscall CGCClientJobUpdateStats::CGCClientJobUpdateStats(
        CGCClientJobUpdateStats *this,
        KeyValues *pKVStats)
{
  GCSDK::CGCClient *v3; // edi
  KeyValues *Copy; // eax

  v3 = GGCClient();
  GCSDK::CJob::CJob(this, jobMgr: &v3->m_JobMgr);
  this->m_pGCClient = v3;
  this->m_cHeartbeatsBeforeTimeout = 2;
  this->__vftable = (CGCClientJobUpdateStats_vtbl *)&CGCClientJobUpdateStats::`vftable';
  this->m_pKVCmd = nullptr;
  Copy = KeyValues::MakeCopy(this: pKVStats);
  this->m_pKVCmd = Copy;
  KeyValues::SetName(this: Copy, setName: "stat_agg");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100284B0
// Name: public: CGCClientJobDataRequest::CGCClientJobDataRequest(void)
// Source: json
//------------------------------------------------------------------------------
CGCClientJobDataRequest *__thiscall CGCClientJobDataRequest::CGCClientJobDataRequest(CGCClientJobDataRequest *this)
{
  GCSDK::CGCClient *v2; // edi

  v2 = GGCClient();
  GCSDK::CJob::CJob(this, jobMgr: &v2->m_JobMgr);
  this->m_pGCClient = v2;
  this->m_pKVRequest = nullptr;
  this->m_pKVResults = nullptr;
  *(_WORD *)&this->m_bComplete = 0;
  this->m_cHeartbeatsBeforeTimeout = 2;
  this->__vftable = (CGCClientJobDataRequest_vtbl *)&CGCClientJobDataRequest::`vftable';
  this->m_bWaitForRead = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028590
// Name: public: GCSDK::CGCMsg<struct MsgGCGenericKV_t>::CGCMsg<struct MsgGCGenericKV_t>(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCMsg<MsgGCGenericKV_t> *__thiscall GCSDK::CGCMsg<MsgGCGenericKV_t>::CGCMsg<MsgGCGenericKV_t>(
        GCSDK::CGCMsg<MsgGCGenericKV_t> *this,
        unsigned int eMsg,
        unsigned int cubReserve)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *m_pubPkt; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned int m_cubPkt; // [esp-4h] [ebp-Ch]

  this->__vftable = (GCSDK::CGCMsg<MsgGCGenericKV_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  this->m_cubMsgHdr = 30;
  this->m_cubStruct = 1;
  this->m_cubPkt = 31;
  v4 = (unsigned __int8 *)CThreadSafeMultiMemoryPool::Alloc(this: &GCSDK::g_MemPoolMsg, cubAllocSize: cubReserve + 31);
  m_cubPkt = this->m_cubPkt;
  v5 = &v4[this->m_cubMsgHdr];
  this->m_pubPkt = v4;
  this->m_pubBody = v5;
  memset(dst: v4, value: 0, count: m_cubPkt);
  m_pubPkt = this->m_pubPkt;
  this->m_bAlloced = true;
  this->m_pubVarRead = nullptr;
  this->__vftable = (GCSDK::CGCMsg<MsgGCGenericKV_t>_vtbl *)&GCSDK::CGCMsg<MsgGCGenericKV_t>::`vftable';
  *(_DWORD *)m_pubPkt = eMsg;
  *((_WORD *)this->m_pubPkt + 6) = 1;
  v7 = this->m_pubPkt;
  *(_DWORD *)(v7 + 22) = -1;
  *(_DWORD *)(v7 + 26) = -1;
  v8 = this->m_pubPkt;
  *(_DWORD *)(v8 + 14) = -1;
  *(_DWORD *)(v8 + 18) = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028620
// Name: protected: bool GCSDK::CGCClientJob::BYldSendMessageAndGetReply(class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near &,unsigned int,class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClientJob::BYldSendMessageAndGetReply(
        GCSDK::CGCClientJob *this,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *msgOut,
        unsigned int nTimeoutSec,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsgIn,
        unsigned int eMsg)
{
  unsigned __int8 *m_pubPkt; // eax
  int m_JobID; // edx
  GCSDK::CNetPacket *v9; // esi
  unsigned __int8 *m_pubData; // ecx
  unsigned int m_cubMsgHdr; // edx
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // edx
  GCSDK::CNetPacket *pNetPacket; // [esp+4h] [ebp-4h] BYREF

  m_pubPkt = msgOut->m_pubPkt;
  m_JobID = this->m_JobID;
  pNetPacket = nullptr;
  *(_DWORD *)(m_pubPkt + 22) = m_JobID;
  *(_DWORD *)(m_pubPkt + 26) = HIDWORD(this->m_JobID);
  if ( !GCSDK::CGCClient::BSendMessage(this: this->m_pGCClient, msg: msgOut) )
    return false;
  this->m_cHeartbeatsBeforeTimeout = 1000000LL * nTimeoutSec / 10000000 + 1;
  if ( GCSDK::CJob::BYieldingWaitForMsg(this, ppNetPacket: &pNetPacket) == 0 )
    return false;
  v9 = pNetPacket;
  m_pubData = pNetPacket->m_pubData;
  m_cubMsgHdr = pMsgIn->m_cubMsgHdr;
  pMsgIn->m_pubPkt = pNetPacket->m_pubData;
  pMsgIn->m_pubBody = &m_pubData[m_cubMsgHdr];
  pMsgIn->m_cubPkt = v9->m_cubData;
  v12 = &pMsgIn->m_pubPkt[pMsgIn->m_cubStruct];
  pMsgIn->m_bAlloced = false;
  v13 = &v12[m_cubMsgHdr];
  v14 = pMsgIn->m_pubPkt;
  pMsgIn->m_pubVarRead = v13;
  return *(_DWORD *)v14 == eMsg;
}

//------------------------------------------------------------------------------
// Address: 0x100286D0
// Name: public: virtual bool CGCClientJobDataRequest::BYieldingRunGCJob(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGCClientJobDataRequest::BYieldingRunGCJob(CGCClientJobDataRequest *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  unsigned int m_Put; // esi
  unsigned __int8 *m_pMemory; // ebx
  bool Reply; // al
  unsigned int m_cubMsgHdr; // edx
  unsigned __int8 *m_pubPkt; // ebx
  bool v9; // al
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  bool v13; // zf
  int v14; // esi
  int v15; // ecx
  CUtlBuffer bufIn; // [esp+Ch] [ebp-A0h] BYREF
  CUtlBuffer bufOut; // [esp+3Ch] [ebp-70h] BYREF
  GCSDK::CGCMsg<MsgGCGenericKV_t> msgOut; // [esp+6Ch] [ebp-40h] BYREF
  GCSDK::CGCMsg<MsgGCGenericKVResponse_t> msgIn; // [esp+8Ch] [ebp-20h] BYREF

  GCSDK::CGCMsg<MsgGCGenericKV_t>::CGCMsg<MsgGCGenericKV_t>(this: &msgOut, eMsg: 0x3E9u, cubReserve: 0x40u);
  msgIn.m_cubMsgHdr = 30;
  msgIn.m_cubStruct = 1;
  msgIn.m_pubPkt = nullptr;
  msgIn.m_pubBody = (unsigned __int8 *)30;
  msgIn.m_cubPkt = 0;
  msgIn.m_bAlloced = false;
  msgIn.m_pubVarRead = (unsigned __int8 *)31;
  msgIn.__vftable = (GCSDK::CGCMsg<MsgGCGenericKVResponse_t>_vtbl *)&GCSDK::CGCMsg<MsgGCGenericKVResponse_t>::`vftable';
  CUtlBuffer::CUtlBuffer(this: &bufOut, growSize: 0, initSize: 0, nFlags: 0);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "datarequest");
  else
    v3 = nullptr;
  this->m_pKVRequest = v3;
  KeyValues::WriteAsBinary(this: v3, buffer: &bufOut);
  m_Put = bufOut.m_Put;
  m_pMemory = bufOut.m_Memory.m_pMemory;
  if ( bufOut.m_Put != 0 )
  {
    msgOut.m_pubPkt = (unsigned __int8 *)CThreadSafeMultiMemoryPool::ReAlloc(
                                           this: &GCSDK::g_MemPoolMsg,
                                           pvMem: (_DWORD *)msgOut.m_pubPkt,
                                           cubAlloc: (char *)(bufOut.m_Put + msgOut.m_cubPkt));
    msgOut.m_pubBody = &msgOut.m_pubPkt[msgOut.m_cubMsgHdr];
    memcpy(dst: &msgOut.m_pubPkt[msgOut.m_cubPkt], src: m_pMemory, count: m_Put);
    msgOut.m_cubPkt += m_Put;
  }
  Reply = GCSDK::CGCClientJob::BYldSendMessageAndGetReply(
            this,
            &msgOut,
            nTimeoutSec: 0x1Eu,
            pMsgIn: &msgIn,
            eMsg: 0x3EAu);
  m_cubMsgHdr = msgIn.m_cubMsgHdr;
  m_pubPkt = msgIn.m_pubPkt;
  v9 = Reply && msgIn.m_pubPkt[msgIn.m_cubMsgHdr] != 0;
  this->m_bSuccess = v9;
  if ( v9 )
  {
    v10 = msgIn.m_cubPkt < m_cubMsgHdr + msgIn.m_cubStruct ? 0 : msgIn.m_cubPkt - m_cubMsgHdr - msgIn.m_cubStruct;
    CUtlBuffer::CUtlBuffer(this: &bufIn, pBuffer: &m_pubPkt[m_cubMsgHdr + msgIn.m_cubStruct], nSize: v10, nFlags: 8u);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v12 = v11 != nullptr ? KeyValues::KeyValues(this: v11, setName: "results") : nullptr;
    this->m_pKVResults = v12;
    this->m_bSuccess &= KeyValues::ReadAsBinary(this: v12, buffer: (int)&bufIn);
    if ( bufIn.m_Memory.m_nGrowSize >= 0 && bufIn.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufIn.m_Memory.m_pMemory);
  }
  v13 = !this->m_bWaitForRead;
  this->m_bComplete = true;
  v14 = 5;
  if ( !v13 )
  {
    do
    {
      v15 = v14--;
      if ( v15 <= 0 )
        break;
      GCSDK::CJob::BYieldingWaitOneFrame(this);
    }
    while ( this->m_bWaitForRead );
  }
  if ( bufOut.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufOut.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufOut.m_Memory.m_pMemory);
      bufOut.m_Memory.m_pMemory = nullptr;
    }
    bufOut.m_Memory.m_nAllocationCount = 0;
  }
  if ( msgIn.m_bAlloced && m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: m_pubPkt);
  msgOut.__vftable = (GCSDK::CGCMsg<MsgGCGenericKV_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msgOut.m_bAlloced && msgOut.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: (_DWORD *)msgOut.m_pubPkt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100288F0
// Name: public: virtual bool CGCClientJobUpdateStats::BYieldingRunGCJob(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGCClientJobUpdateStats::BYieldingRunGCJob(CGCClientJobUpdateStats *this)
{
  unsigned int m_Put; // esi
  unsigned __int8 *m_pMemory; // edi
  CUtlBuffer bufDest; // [esp+Ch] [ebp-50h] BYREF
  GCSDK::CGCMsg<MsgGCGenericKV_t> msg; // [esp+3Ch] [ebp-20h] BYREF

  GCSDK::CGCMsg<MsgGCGenericKV_t>::CGCMsg<MsgGCGenericKV_t>(this: &msg, eMsg: 0x3E9u, cubReserve: 0x40u);
  CUtlBuffer::CUtlBuffer(this: &bufDest, growSize: 0, initSize: 0, nFlags: 0);
  KeyValues::WriteAsBinary(this: this->m_pKVCmd, buffer: &bufDest);
  m_Put = bufDest.m_Put;
  m_pMemory = bufDest.m_Memory.m_pMemory;
  if ( bufDest.m_Put != 0 )
  {
    msg.m_pubPkt = (unsigned __int8 *)CThreadSafeMultiMemoryPool::ReAlloc(
                                        this: &GCSDK::g_MemPoolMsg,
                                        pvMem: (_DWORD *)msg.m_pubPkt,
                                        cubAlloc: (char *)(bufDest.m_Put + msg.m_cubPkt));
    msg.m_pubBody = &msg.m_pubPkt[msg.m_cubMsgHdr];
    memcpy(dst: &msg.m_pubPkt[msg.m_cubPkt], src: m_pMemory, count: m_Put);
    msg.m_cubPkt += m_Put;
  }
  GCSDK::CGCClient::BSendMessage(this: this->m_pGCClient, &msg);
  if ( bufDest.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufDest.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufDest.m_Memory.m_pMemory);
      bufDest.m_Memory.m_pMemory = nullptr;
    }
    bufDest.m_Memory.m_nAllocationCount = 0;
  }
  msg.__vftable = (GCSDK::CGCMsg<MsgGCGenericKV_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msg.m_bAlloced && msg.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: (_DWORD *)msg.m_pubPkt);
  return 1;
}
