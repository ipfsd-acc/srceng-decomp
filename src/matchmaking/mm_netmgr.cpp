// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_netmgr.cpp
// Functions: 4
// ============================================================

#include "matchmaking\mm_netmgr.h"

//------------------------------------------------------------------------------
// Address: 0x10003E50
// Name: public: void CUtlBuffer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Clear(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_Error = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this);
}

//------------------------------------------------------------------------------
// Address: 0x10003E90
// Name: public: class KeyValues __near * CConnectionlessLanMgr::UnpackPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CConnectionlessLanMgr::UnpackPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  KeyValues *v2; // ebx
  int m_iValue; // ecx
  bf_read *p_m_pChain; // esi
  unsigned int m_wsValue; // eax
  int v7; // ecx
  int v8; // edi
  const unsigned int *v9; // ecx
  const unsigned int *m_pPeer; // edx
  const unsigned int *v11; // edx
  unsigned int v12; // edi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebp
  int v17; // ecx
  INetSupport *m_pINetSupport; // ebp
  unsigned int v19; // eax
  int v20; // ecx
  int v21; // edi
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  const unsigned int *v24; // edx
  unsigned int v25; // edi
  int v26; // eax
  const unsigned int *v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // ebx
  int v30; // ecx
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // ebp
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  const unsigned int *v36; // edx
  unsigned int v37; // ebp
  int v38; // eax
  const unsigned int *v39; // ecx
  unsigned int v40; // edx
  unsigned int v41; // edi
  CUtlBuffer *p_m_buffer; // edi
  KeyValues *v43; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v46; // ecx
  int v47; // ebp
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v50; // edx
  unsigned int v51; // ebp
  int v52; // eax
  const unsigned int *v53; // ecx
  unsigned int v54; // edx
  unsigned int v55; // ebx
  KeyValues *pMsg; // [esp+10h] [ebp+4h]

  v2 = nullptr;
  if ( packet == nullptr || packet[1].m_pChain == nullptr || packet->m_pSub == nullptr )
    return nullptr;
  m_iValue = packet[1].m_iValue;
  p_m_pChain = (bf_read *)&packet->m_pChain;
  if ( m_iValue >= 32 )
  {
    m_wsValue = (unsigned int)packet[1].m_wsValue;
    v7 = m_iValue - 32;
    packet[1].m_iValue = v7;
    if ( v7 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v8 = m_wsValue;
    }
    else
    {
      v9 = *(const unsigned int **)&packet[1].m_iDataType;
      m_pPeer = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v9 == m_pPeer )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v9 + 1;
        v8 = m_wsValue;
      }
      else
      {
        if ( v9 <= m_pPeer )
        {
          packet[1].m_wsValue = (wchar_t *)*v9;
          *(_DWORD *)&packet[1].m_iDataType = v9 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v8 = m_wsValue;
      }
    }
    goto LABEL_22;
  }
  v11 = (const unsigned int *)packet[1].m_pPeer;
  v12 = (unsigned int)packet[1].m_wsValue;
  v13 = 32 - m_iValue;
  v14 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v14 == v11 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
LABEL_19:
    *(_DWORD *)&packet[1].m_iDataType = v14 + 1;
    goto LABEL_20;
  }
  if ( v14 <= v11 )
  {
    packet[1].m_wsValue = (wchar_t *)*v14;
    goto LABEL_19;
  }
  LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  packet[1].m_wsValue = nullptr;
LABEL_20:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) == 0 )
  {
    v15 = (unsigned int)packet[1].m_wsValue;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v13;
    v8 = v16 | v12;
    packet[1].m_wsValue = (wchar_t *)(v15 >> v13);
LABEL_22:
    if ( v8 != 0 )
      return nullptr;
  }
  v17 = packet[1].m_iValue;
  m_pINetSupport = g_pMatchExtensions->m_exts.m_pINetSupport;
  if ( v17 < 32 )
  {
    v24 = (const unsigned int *)packet[1].m_pPeer;
    v25 = (unsigned int)packet[1].m_wsValue;
    v26 = 32 - v17;
    v27 = *(const unsigned int **)&packet[1].m_iDataType;
    if ( v27 == v24 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
    }
    else
    {
      if ( v27 > v24 )
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
        goto LABEL_38;
      }
      packet[1].m_wsValue = (wchar_t *)*v27;
    }
    *(_DWORD *)&packet[1].m_iDataType = v27 + 1;
LABEL_38:
    if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
    {
      v21 = 0;
    }
    else
    {
      v28 = (unsigned int)packet[1].m_wsValue;
      v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << packet[1].m_iValue;
      packet[1].m_iValue = 32 - v26;
      v21 = v29 | v25;
      v2 = nullptr;
      packet[1].m_wsValue = (wchar_t *)(v28 >> v26);
    }
    goto LABEL_41;
  }
  v19 = (unsigned int)packet[1].m_wsValue;
  v20 = v17 - 32;
  packet[1].m_iValue = v20;
  if ( v20 != 0 )
  {
    packet[1].m_wsValue = nullptr;
    v21 = v19;
  }
  else
  {
    v22 = *(const unsigned int **)&packet[1].m_iDataType;
    v23 = (const unsigned int *)packet[1].m_pPeer;
    packet[1].m_iValue = 32;
    if ( v22 == v23 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      *(_DWORD *)&packet[1].m_iDataType = v22 + 1;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        packet[1].m_wsValue = (wchar_t *)*v22;
        *(_DWORD *)&packet[1].m_iDataType = v22 + 1;
      }
      else
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
      }
      v21 = v19;
    }
  }
LABEL_41:
  if ( v21 != m_pINetSupport->GetEngineBuildNumber(this: m_pINetSupport) )
    return nullptr;
  v30 = packet[1].m_iValue;
  if ( v30 >= 32 )
  {
    v31 = (unsigned int)packet[1].m_wsValue;
    v32 = v30 - 32;
    packet[1].m_iValue = v32;
    if ( v32 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v33 = v31;
    }
    else
    {
      v34 = *(const unsigned int **)&packet[1].m_iDataType;
      v35 = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v34 == v35 )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v34 + 1;
        v33 = v31;
      }
      else
      {
        if ( v34 <= v35 )
        {
          packet[1].m_wsValue = (wchar_t *)*v34;
          *(_DWORD *)&packet[1].m_iDataType = v34 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v33 = v31;
      }
    }
    goto LABEL_60;
  }
  v36 = (const unsigned int *)packet[1].m_pPeer;
  v37 = (unsigned int)packet[1].m_wsValue;
  v38 = 32 - v30;
  v39 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v39 == v36 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  }
  else
  {
    if ( v39 > v36 )
    {
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
      packet[1].m_wsValue = nullptr;
      goto LABEL_57;
    }
    packet[1].m_wsValue = (wchar_t *)*v39;
  }
  *(_DWORD *)&packet[1].m_iDataType = v39 + 1;
LABEL_57:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
  {
    v33 = 0;
  }
  else
  {
    v40 = (unsigned int)packet[1].m_wsValue;
    v41 = (v40 & CBitBuffer::s_nMaskTable[v38]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v38;
    v33 = v41 | v37;
    packet[1].m_wsValue = (wchar_t *)(v40 >> v38);
  }
LABEL_60:
  p_m_buffer = &this->m_buffer;
  CUtlBuffer::Clear(this: &this->m_buffer);
  CUtlBuffer::EnsureCapacity(this: &this->m_buffer, num: v33);
  CBitRead::ReadBytes(this: p_m_pChain, pOut: this->m_buffer.m_Memory.m_pMemory, nBytes: v33);
  CUtlBuffer::SeekPut(this: &this->m_buffer, type: SEEK_HEAD, offset: v33);
  CUtlBuffer::ActivateByteSwapping(this: &this->m_buffer, bActivate: true);
  v43 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v43 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v43, setName: str);
    pMsg = v2;
  }
  else
  {
    pMsg = nullptr;
  }
  if ( KeyValues::ReadAsBinary(this: v2, buffer: p_m_buffer) )
  {
    m_nBitsAvail = p_m_pChain->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = p_m_pChain->m_nInBufWord;
      v46 = m_nBitsAvail - 32;
      p_m_pChain->m_nBitsAvail = v46;
      if ( v46 != 0 )
      {
        p_m_pChain->m_nInBufWord = 0;
        v47 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = p_m_pChain->m_pDataIn;
        m_pBufferEnd = p_m_pChain->m_pBufferEnd;
        p_m_pChain->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          p_m_pChain->m_nInBufWord = 0;
          p_m_pChain->m_nBitsAvail = 1;
          p_m_pChain->m_pDataIn = m_pDataIn + 1;
          v47 = m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            p_m_pChain->m_nInBufWord = *m_pDataIn;
            p_m_pChain->m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            p_m_pChain->m_nInBufWord = 0;
            p_m_pChain->m_bOverflow = true;
          }
          v47 = m_nInBufWord;
        }
      }
      goto LABEL_81;
    }
    v50 = p_m_pChain->m_pBufferEnd;
    v51 = p_m_pChain->m_nInBufWord;
    v52 = 32 - m_nBitsAvail;
    v53 = p_m_pChain->m_pDataIn;
    if ( v53 == v50 )
    {
      p_m_pChain->m_nBitsAvail = 1;
      p_m_pChain->m_nInBufWord = 0;
      p_m_pChain->m_bOverflow = true;
    }
    else
    {
      if ( v53 > v50 )
      {
        p_m_pChain->m_bOverflow = true;
        p_m_pChain->m_nInBufWord = 0;
LABEL_79:
        if ( p_m_pChain->m_bOverflow )
          return v2;
        v54 = p_m_pChain->m_nInBufWord;
        v55 = (v54 & CBitBuffer::s_nMaskTable[v52]) << p_m_pChain->m_nBitsAvail;
        p_m_pChain->m_nBitsAvail = 32 - v52;
        v47 = v55 | v51;
        v2 = pMsg;
        p_m_pChain->m_nInBufWord = v54 >> v52;
LABEL_81:
        if ( v47 != 0 )
        {
          CUtlBuffer::Clear(this: p_m_buffer);
          CUtlBuffer::EnsureCapacity(this: p_m_buffer, num: v47);
          CBitRead::ReadBytes(this: p_m_pChain, pOut: p_m_buffer->m_Memory.m_pMemory, nBytes: v47);
          CUtlBuffer::SeekPut(this: p_m_buffer, type: SEEK_HEAD, offset: v47);
          KeyValues::SetPtr(this: v2, keyName: "Binary/ptr", value: p_m_buffer->m_Memory.m_pMemory);
        }
        return v2;
      }
      p_m_pChain->m_nInBufWord = *v53;
    }
    p_m_pChain->m_pDataIn = v53 + 1;
    goto LABEL_79;
  }
  KeyValues::deleteThis(this: v2);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100042E0
// Name: public: virtual bool CConnectionlessLanMgr::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConnectionlessLanMgr::ProcessConnectionlessPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  KeyValues *v2; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *v6; // eax

  v2 = CConnectionlessLanMgr::UnpackPacket(this, packet);
  if ( v2 == nullptr )
    return 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnNetLanConnectionlessPacket");
  else
    v5 = nullptr;
  v6 = netadr_s::ToString(this: (netadr_s *)packet, baseOnly: false);
  KeyValues::SetString(this: v5, keyName: "from", value: v6);
  KeyValues::AddSubKey(this: v5, pSubkey: v2);
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004350
// Name: public: void CConnectionlessLanMgr::SendPacket(class KeyValues __near *,char const __near *,enum INetSupport::NetworkSocket_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConnectionlessLanMgr::SendPacket(
        CConnectionlessLanMgr *this,
        KeyValues *pMsg,
        const char *szAddress,
        INetSupport::NetworkSocket_t eSock)
{
  int v4; // eax
  KeyValues *Key; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  const void *Ptr; // edi
  int Int; // eax
  int v10; // esi
  unsigned __int16 v11; // [esp-4h] [ebp-510h]
  netadr_s inetAddr; // [esp+4h] [ebp-508h] BYREF
  bf_write msg; // [esp+10h] [ebp-4FCh] BYREF
  CUtlBuffer data; // [esp+28h] [ebp-4E4h] BYREF
  char buf[1200]; // [esp+58h] [ebp-4B4h] BYREF

  bf_write::bf_write(this: (bf_write *)&msg.m_nDataBytes, pData: &buf[4], nBytes: 1200, nBits: -1);
  bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: -1);
  bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: 0);
  v4 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: v4);
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&data.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: (CUtlBuffer *)&data.m_Memory.m_nAllocationCount, bActivate: true);
  KeyValues::WriteAsBinary(this: pMsg, buffer: (CUtlBuffer *)&data.m_Memory.m_nAllocationCount);
  bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: data.m_nOffset);
  bf_write::WriteBytes(
    this: (bf_write *)&msg.m_nDataBytes,
    pBuf: (const void *)data.m_Memory.m_nAllocationCount,
    nBytes: data.m_nOffset);
  Key = KeyValues::FindKey(this: pMsg, keyName: "Binary/ptr", bCreate: false);
  v6 = KeyValues::FindKey(this: pMsg, keyName: "Binary/size", bCreate: false);
  v7 = v6;
  if ( Key != nullptr
    && v6 != nullptr
    && (Ptr = KeyValues::GetPtr(this: Key, keyName: nullptr, defaultValue: nullptr),
        Int = KeyValues::GetInt(this: v7, keyName: nullptr, defaultValue: 0),
        v10 = Int,
        Ptr != nullptr)
    && Int != 0 )
  {
    bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: Int);
    if ( !bf_write::WriteBytes(this: (bf_write *)&msg.m_nDataBytes, pBuf: Ptr, nBytes: v10) )
    {
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&data.m_Memory.m_nAllocationCount);
      return;
    }
  }
  else
  {
    bf_write::WriteLong(this: (bf_write *)&msg.m_nDataBytes, val: 0);
  }
  netadr_s::SetIP(this: (netadr_s *)inetAddr.ip, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)inetAddr.ip, newport: 0);
  netadr_s::SetType(this: (netadr_s *)inetAddr.ip, newtype: NA_IP);
  if ( szAddress != nullptr )
  {
    if ( *szAddress == 42 && szAddress[1] == 58 )
    {
      netadr_s::SetType(this: (netadr_s *)inetAddr.ip, newtype: NA_BROADCAST);
      v11 = atoi(nptr: szAddress + 2);
      netadr_s::SetPort(this: (netadr_s *)inetAddr.ip, newport: v11);
    }
    else
    {
      netadr_s::SetFromString(this: (netadr_s *)inetAddr.ip, pch: szAddress, bUseDNS: false);
    }
  }
  else
  {
    netadr_s::SetType(this: (netadr_s *)inetAddr.ip, newtype: NA_BROADCAST);
    netadr_s::SetPort(this: (netadr_s *)inetAddr.ip, newport: 0);
  }
  if ( netadr_s::GetType(this: (netadr_s *)inetAddr.ip) != NA_BROADCAST
    || net_allow_multicast.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pMatchExtensions->m_exts.m_pINetSupport->SendPacket(
      this: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: nullptr,
      a3: eSock,
      a4: (const netadr_s *)inetAddr.ip,
      a5: (const void *)msg.m_nDataBytes,
      a6: (*(_DWORD *)&msg.m_bOverflow + 7) >> 3,
      a7: nullptr,
      a8: false);
  }
  if ( data.m_Get >= 0 && data.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)data.m_Memory.m_nAllocationCount);
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1000D520
// Name: public: void CUtlBuffer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Clear(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_Error = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this, nPut: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D570
// Name: public: class KeyValues __near * CConnectionlessLanMgr::UnpackPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CConnectionlessLanMgr::UnpackPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  int m_iValue; // ecx
  unsigned int m_wsValue; // eax
  int v6; // ecx
  int v7; // ebx
  const unsigned int *v8; // ecx
  const unsigned int *m_pPeer; // edx
  const unsigned int *v10; // edx
  unsigned int v11; // ebx
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  int v16; // ecx
  INetSupport *m_pINetSupport; // edi
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  const unsigned int *v23; // edx
  unsigned int v24; // ebx
  int v25; // eax
  const unsigned int *v26; // ecx
  unsigned int v27; // edx
  unsigned int v28; // edi
  int v29; // ecx
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // ebx
  const unsigned int *v33; // ecx
  const unsigned int *v34; // edx
  const unsigned int *v35; // edx
  unsigned int v36; // ebx
  int v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // edi
  CUtlBuffer *p_m_buffer; // edi
  KeyValues *v42; // eax
  int v43; // ecx
  unsigned int v44; // eax
  int v45; // ecx
  int v46; // ebx
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  const unsigned int *v49; // edx
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // ebx
  unsigned int v54; // [esp+8h] [ebp-8h]
  KeyValues *pMsg; // [esp+18h] [ebp+8h]
  KeyValues *pMsga; // [esp+18h] [ebp+8h]

  if ( packet == nullptr || packet[1].m_pChain == nullptr || packet->m_pSub == nullptr )
    return nullptr;
  m_iValue = packet[1].m_iValue;
  if ( m_iValue >= 32 )
  {
    m_wsValue = (unsigned int)packet[1].m_wsValue;
    v6 = m_iValue - 32;
    packet[1].m_iValue = v6;
    if ( v6 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v7 = m_wsValue;
    }
    else
    {
      v8 = *(const unsigned int **)&packet[1].m_iDataType;
      m_pPeer = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v8 == m_pPeer )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v8 + 1;
        v7 = m_wsValue;
      }
      else
      {
        if ( v8 <= m_pPeer )
        {
          packet[1].m_wsValue = (wchar_t *)*v8;
          *(_DWORD *)&packet[1].m_iDataType = v8 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v7 = m_wsValue;
      }
    }
    goto LABEL_22;
  }
  v10 = (const unsigned int *)packet[1].m_pPeer;
  v11 = (unsigned int)packet[1].m_wsValue;
  v12 = 32 - m_iValue;
  v13 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v13 == v10 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
LABEL_19:
    *(_DWORD *)&packet[1].m_iDataType = v13 + 1;
    goto LABEL_20;
  }
  if ( v13 <= v10 )
  {
    packet[1].m_wsValue = (wchar_t *)*v13;
    goto LABEL_19;
  }
  LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  packet[1].m_wsValue = nullptr;
LABEL_20:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) == 0 )
  {
    v14 = (unsigned int)packet[1].m_wsValue;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v12;
    v7 = v15 | v11;
    packet[1].m_wsValue = (wchar_t *)(v14 >> v12);
LABEL_22:
    if ( v7 != 0 )
      return nullptr;
  }
  v16 = packet[1].m_iValue;
  m_pINetSupport = g_pMatchExtensions->m_exts.m_pINetSupport;
  pMsg = (KeyValues *)m_pINetSupport;
  if ( v16 < 32 )
  {
    v23 = (const unsigned int *)packet[1].m_pPeer;
    v24 = (unsigned int)packet[1].m_wsValue;
    v25 = 32 - v16;
    v26 = *(const unsigned int **)&packet[1].m_iDataType;
    if ( v26 == v23 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
    }
    else
    {
      if ( v26 > v23 )
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
        goto LABEL_38;
      }
      packet[1].m_wsValue = (wchar_t *)*v26;
    }
    *(_DWORD *)&packet[1].m_iDataType = v26 + 1;
LABEL_38:
    if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
    {
      v20 = 0;
    }
    else
    {
      v27 = (unsigned int)packet[1].m_wsValue;
      v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << packet[1].m_iValue;
      packet[1].m_iValue = 32 - v25;
      v20 = v28 | v24;
      m_pINetSupport = (INetSupport *)pMsg;
      packet[1].m_wsValue = (wchar_t *)(v27 >> v25);
    }
    goto LABEL_41;
  }
  v18 = (unsigned int)packet[1].m_wsValue;
  v19 = v16 - 32;
  packet[1].m_iValue = v19;
  if ( v19 != 0 )
  {
    packet[1].m_wsValue = nullptr;
    v20 = v18;
  }
  else
  {
    v21 = *(const unsigned int **)&packet[1].m_iDataType;
    v22 = (const unsigned int *)packet[1].m_pPeer;
    packet[1].m_iValue = 32;
    if ( v21 == v22 )
    {
      packet[1].m_wsValue = nullptr;
      packet[1].m_iValue = 1;
      *(_DWORD *)&packet[1].m_iDataType = v21 + 1;
      v20 = v18;
    }
    else
    {
      if ( v21 <= v22 )
      {
        packet[1].m_wsValue = (wchar_t *)*v21;
        *(_DWORD *)&packet[1].m_iDataType = v21 + 1;
      }
      else
      {
        packet[1].m_wsValue = nullptr;
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
      }
      v20 = v18;
    }
  }
LABEL_41:
  if ( v20 != m_pINetSupport->GetEngineBuildNumber(this: m_pINetSupport) )
    return nullptr;
  v29 = packet[1].m_iValue;
  if ( v29 >= 32 )
  {
    v30 = (unsigned int)packet[1].m_wsValue;
    v31 = v29 - 32;
    packet[1].m_iValue = v31;
    if ( v31 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v32 = v30;
    }
    else
    {
      v33 = *(const unsigned int **)&packet[1].m_iDataType;
      v34 = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v33 == v34 )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v33 + 1;
        v32 = v30;
      }
      else
      {
        if ( v33 <= v34 )
        {
          packet[1].m_wsValue = (wchar_t *)*v33;
          *(_DWORD *)&packet[1].m_iDataType = v33 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v32 = v30;
      }
    }
    goto LABEL_60;
  }
  v35 = (const unsigned int *)packet[1].m_pPeer;
  v36 = (unsigned int)packet[1].m_wsValue;
  v37 = 32 - v29;
  v38 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v38 == v35 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  }
  else
  {
    if ( v38 > v35 )
    {
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
      packet[1].m_wsValue = nullptr;
      goto LABEL_57;
    }
    packet[1].m_wsValue = (wchar_t *)*v38;
  }
  *(_DWORD *)&packet[1].m_iDataType = v38 + 1;
LABEL_57:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
  {
    v32 = 0;
  }
  else
  {
    v39 = (unsigned int)packet[1].m_wsValue;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v37;
    v32 = v40 | v36;
    packet[1].m_wsValue = (wchar_t *)(v39 >> v37);
  }
LABEL_60:
  p_m_buffer = &this->m_buffer;
  CUtlBuffer::Clear(this: &this->m_buffer);
  CUtlBuffer::EnsureCapacity(this: &this->m_buffer, num: v32);
  CBitRead::ReadBytes(this: (CBitRead *)&packet->m_pChain, pOut: this->m_buffer.m_Memory.m_pMemory, nBytes: v32);
  CUtlBuffer::SeekPut(this: &this->m_buffer, type: SEEK_HEAD, offset: v32);
  CUtlBuffer::ActivateByteSwapping(this: &this->m_buffer, bActivate: true);
  v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v42 != nullptr )
    pMsga = KeyValues::KeyValues(this: v42, setName: defaultValue);
  else
    pMsga = nullptr;
  if ( KeyValues::ReadAsBinary(this: pMsga, buffer: p_m_buffer) )
  {
    v43 = packet[1].m_iValue;
    v44 = (unsigned int)packet[1].m_wsValue;
    if ( v43 >= 32 )
    {
      v45 = v43 - 32;
      packet[1].m_iValue = v45;
      if ( v45 != 0 )
      {
        packet[1].m_wsValue = nullptr;
        v46 = v44;
      }
      else
      {
        v47 = *(const unsigned int **)&packet[1].m_iDataType;
        v48 = (const unsigned int *)packet[1].m_pPeer;
        packet[1].m_iValue = 32;
        if ( v47 == v48 )
        {
          packet[1].m_wsValue = nullptr;
          packet[1].m_iValue = 1;
          *(_DWORD *)&packet[1].m_iDataType = v47 + 1;
          v46 = v44;
        }
        else
        {
          if ( v47 <= v48 )
          {
            packet[1].m_wsValue = (wchar_t *)*v47;
            *(_DWORD *)&packet[1].m_iDataType = v47 + 1;
          }
          else
          {
            packet[1].m_wsValue = nullptr;
            LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          }
          v46 = v44;
        }
      }
      goto LABEL_81;
    }
    v49 = (const unsigned int *)packet[1].m_pPeer;
    v54 = (unsigned int)packet[1].m_wsValue;
    v50 = 32 - v43;
    v51 = *(const unsigned int **)&packet[1].m_iDataType;
    if ( v51 == v49 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
    }
    else
    {
      if ( v51 > v49 )
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
LABEL_79:
        if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
          return pMsga;
        v52 = (unsigned int)packet[1].m_wsValue;
        v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << packet[1].m_iValue;
        packet[1].m_iValue = 32 - v50;
        v46 = v53 | v54;
        packet[1].m_wsValue = (wchar_t *)(v52 >> v50);
LABEL_81:
        if ( v46 != 0 )
        {
          CUtlBuffer::Clear(this: p_m_buffer);
          CUtlBuffer::EnsureCapacity(this: p_m_buffer, num: v46);
          CBitRead::ReadBytes(this: (CBitRead *)&packet->m_pChain, pOut: p_m_buffer->m_Memory.m_pMemory, nBytes: v46);
          CUtlBuffer::SeekPut(this: p_m_buffer, type: SEEK_HEAD, offset: v46);
          KeyValues::SetPtr(this: pMsga, keyName: "binary/ptr", value: p_m_buffer->m_Memory.m_pMemory);
        }
        return pMsga;
      }
      packet[1].m_wsValue = (wchar_t *)*v51;
    }
    *(_DWORD *)&packet[1].m_iDataType = v51 + 1;
    goto LABEL_79;
  }
  KeyValues::deleteThis(this: pMsga);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9E0
// Name: public: virtual bool CConnectionlessLanMgr::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConnectionlessLanMgr::ProcessConnectionlessPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  KeyValues *v2; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *v6; // eax

  v2 = CConnectionlessLanMgr::UnpackPacket(this, packet);
  if ( v2 == nullptr )
    return 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnNetLanConnectionlessPacket");
  else
    v5 = nullptr;
  v6 = netadr_s::ToString(this: (netadr_s *)packet, baseOnly: false);
  KeyValues::SetString(this: v5, keyName: "from", value: v6);
  KeyValues::AddSubKey(this: v5, pSubkey: v2);
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DA60
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DA90
// Name: public: void CConnectionlessLanMgr::SendPacket(class KeyValues __near *,char const __near *,enum INetSupport::NetworkSocket_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConnectionlessLanMgr::SendPacket(
        CConnectionlessLanMgr *this,
        KeyValues *pMsg,
        const char *szAddress,
        INetSupport::NetworkSocket_t eSock)
{
  int v4; // eax
  KeyValues *Key; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  const void *Ptr; // edi
  int Int; // eax
  int v10; // esi
  unsigned __int16 v11; // [esp-4h] [ebp-510h]
  char buf[1200]; // [esp+8h] [ebp-504h] BYREF
  CUtlBuffer data; // [esp+4B8h] [ebp-54h] BYREF
  bf_write msg; // [esp+4E8h] [ebp-24h] BYREF
  netadr_s inetAddr; // [esp+500h] [ebp-Ch] BYREF

  bf_write::bf_write(this: &msg, pData: buf, nBytes: 1200, nBits: -1);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteLong(this: &msg, val: 0);
  v4 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  bf_write::WriteLong(this: &msg, val: v4);
  CUtlBuffer::CUtlBuffer(this: &data, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &data, bActivate: true);
  KeyValues::WriteAsBinary(this: pMsg, buffer: &data);
  bf_write::WriteLong(this: &msg, val: data.m_nMaxPut);
  bf_write::WriteBytes(this: &msg, pBuf: data.m_Memory.m_pMemory, nBytes: data.m_nMaxPut);
  Key = KeyValues::FindKey(this: pMsg, keyName: "binary/ptr", bCreate: false);
  v6 = KeyValues::FindKey(this: pMsg, keyName: "binary/size", bCreate: false);
  v7 = v6;
  if ( Key != nullptr
    && v6 != nullptr
    && (Ptr = KeyValues::GetPtr(this: Key, keyName: nullptr, defaultValue: nullptr),
        Int = KeyValues::GetInt(this: v7, keyName: nullptr, defaultValue: 0),
        v10 = Int,
        Ptr != nullptr)
    && Int != 0 )
  {
    bf_write::WriteLong(this: &msg, val: Int);
    if ( !bf_write::WriteBytes(this: &msg, pBuf: Ptr, nBytes: v10) )
    {
      CUtlBuffer::~CUtlBuffer(this: &data);
      return;
    }
  }
  else
  {
    bf_write::WriteLong(this: &msg, val: 0);
  }
  netadr_s::SetIP(this: &inetAddr, unIP: 0);
  netadr_s::SetPort(this: &inetAddr, newport: 0);
  netadr_s::SetType(this: &inetAddr, newtype: NA_IP);
  if ( szAddress != nullptr )
  {
    if ( *szAddress == 42 && szAddress[1] == 58 )
    {
      netadr_s::SetType(this: &inetAddr, newtype: NA_BROADCAST);
      v11 = atoi(nptr: szAddress + 2);
      netadr_s::SetPort(this: &inetAddr, newport: v11);
    }
    else
    {
      netadr_s::SetFromString(this: &inetAddr, pch: szAddress, bUseDNS: false);
    }
  }
  else
  {
    netadr_s::SetType(this: &inetAddr, newtype: NA_BROADCAST);
    netadr_s::SetPort(this: &inetAddr, newport: 0);
  }
  if ( netadr_s::GetType(this: &inetAddr) != NA_BROADCAST
    || net_allow_multicast.m_pParent != nullptr && net_allow_multicast.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pMatchExtensions->m_exts.m_pINetSupport->SendPacket(
      this: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: nullptr,
      a3: eSock,
      a4: &inetAddr,
      a5: msg.m_pData,
      a6: (msg.m_iCurBit + 7) >> 3,
      a7: nullptr,
      a8: false);
    if ( data.m_Memory.m_nGrowSize >= 0 && data.m_Memory.m_pMemory != nullptr )
      goto LABEL_22;
  }
  else if ( data.m_Memory.m_nGrowSize >= 0 && data.m_Memory.m_pMemory != nullptr )
  {
LABEL_22:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_Memory.m_pMemory);
  }
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10007CD0
// Name: public: void CUtlBuffer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Clear(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_Error = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this, nPut: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10007D30
// Name: public: class KeyValues __near * CConnectionlessLanMgr::UnpackPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CConnectionlessLanMgr::UnpackPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  int m_iValue; // ecx
  unsigned int m_wsValue; // eax
  int v6; // ecx
  int v7; // ebx
  const unsigned int *v8; // ecx
  const unsigned int *m_pPeer; // edx
  const unsigned int *v10; // edx
  unsigned int v11; // ebx
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  int v16; // ecx
  INetSupport *m_pINetSupport; // edi
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  const unsigned int *v23; // edx
  unsigned int v24; // ebx
  int v25; // eax
  const unsigned int *v26; // ecx
  unsigned int v27; // edx
  unsigned int v28; // edi
  int v29; // ecx
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // ebx
  const unsigned int *v33; // ecx
  const unsigned int *v34; // edx
  const unsigned int *v35; // edx
  unsigned int v36; // ebx
  int v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // edi
  CUtlBuffer *p_m_buffer; // edi
  KeyValues *v42; // eax
  int v43; // ecx
  unsigned int v44; // eax
  int v45; // ecx
  int v46; // ebx
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  const unsigned int *v49; // edx
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // ebx
  unsigned int v54; // [esp+8h] [ebp-8h]
  KeyValues *pMsg; // [esp+18h] [ebp+8h]
  KeyValues *pMsga; // [esp+18h] [ebp+8h]

  if ( packet == nullptr || packet[1].m_pChain == nullptr || packet->m_pSub == nullptr )
    return nullptr;
  m_iValue = packet[1].m_iValue;
  if ( m_iValue >= 32 )
  {
    m_wsValue = (unsigned int)packet[1].m_wsValue;
    v6 = m_iValue - 32;
    packet[1].m_iValue = v6;
    if ( v6 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v7 = m_wsValue;
    }
    else
    {
      v8 = *(const unsigned int **)&packet[1].m_iDataType;
      m_pPeer = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v8 == m_pPeer )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v8 + 1;
        v7 = m_wsValue;
      }
      else
      {
        if ( v8 <= m_pPeer )
        {
          packet[1].m_wsValue = (wchar_t *)*v8;
          *(_DWORD *)&packet[1].m_iDataType = v8 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v7 = m_wsValue;
      }
    }
    goto LABEL_22;
  }
  v10 = (const unsigned int *)packet[1].m_pPeer;
  v11 = (unsigned int)packet[1].m_wsValue;
  v12 = 32 - m_iValue;
  v13 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v13 == v10 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
LABEL_19:
    *(_DWORD *)&packet[1].m_iDataType = v13 + 1;
    goto LABEL_20;
  }
  if ( v13 <= v10 )
  {
    packet[1].m_wsValue = (wchar_t *)*v13;
    goto LABEL_19;
  }
  LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  packet[1].m_wsValue = nullptr;
LABEL_20:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) == 0 )
  {
    v14 = (unsigned int)packet[1].m_wsValue;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v12;
    v7 = v15 | v11;
    packet[1].m_wsValue = (wchar_t *)(v14 >> v12);
LABEL_22:
    if ( v7 != 0 )
      return nullptr;
  }
  v16 = packet[1].m_iValue;
  m_pINetSupport = g_pMatchExtensions->m_exts.m_pINetSupport;
  pMsg = (KeyValues *)m_pINetSupport;
  if ( v16 < 32 )
  {
    v23 = (const unsigned int *)packet[1].m_pPeer;
    v24 = (unsigned int)packet[1].m_wsValue;
    v25 = 32 - v16;
    v26 = *(const unsigned int **)&packet[1].m_iDataType;
    if ( v26 == v23 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
    }
    else
    {
      if ( v26 > v23 )
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
        goto LABEL_38;
      }
      packet[1].m_wsValue = (wchar_t *)*v26;
    }
    *(_DWORD *)&packet[1].m_iDataType = v26 + 1;
LABEL_38:
    if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
    {
      v20 = 0;
    }
    else
    {
      v27 = (unsigned int)packet[1].m_wsValue;
      v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << packet[1].m_iValue;
      packet[1].m_iValue = 32 - v25;
      v20 = v28 | v24;
      m_pINetSupport = (INetSupport *)pMsg;
      packet[1].m_wsValue = (wchar_t *)(v27 >> v25);
    }
    goto LABEL_41;
  }
  v18 = (unsigned int)packet[1].m_wsValue;
  v19 = v16 - 32;
  packet[1].m_iValue = v19;
  if ( v19 != 0 )
  {
    packet[1].m_wsValue = nullptr;
    v20 = v18;
  }
  else
  {
    v21 = *(const unsigned int **)&packet[1].m_iDataType;
    v22 = (const unsigned int *)packet[1].m_pPeer;
    packet[1].m_iValue = 32;
    if ( v21 == v22 )
    {
      packet[1].m_wsValue = nullptr;
      packet[1].m_iValue = 1;
      *(_DWORD *)&packet[1].m_iDataType = v21 + 1;
      v20 = v18;
    }
    else
    {
      if ( v21 <= v22 )
      {
        packet[1].m_wsValue = (wchar_t *)*v21;
        *(_DWORD *)&packet[1].m_iDataType = v21 + 1;
      }
      else
      {
        packet[1].m_wsValue = nullptr;
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
      }
      v20 = v18;
    }
  }
LABEL_41:
  if ( v20 != m_pINetSupport->GetEngineBuildNumber(this: m_pINetSupport) )
    return nullptr;
  v29 = packet[1].m_iValue;
  if ( v29 >= 32 )
  {
    v30 = (unsigned int)packet[1].m_wsValue;
    v31 = v29 - 32;
    packet[1].m_iValue = v31;
    if ( v31 != 0 )
    {
      packet[1].m_wsValue = nullptr;
      v32 = v30;
    }
    else
    {
      v33 = *(const unsigned int **)&packet[1].m_iDataType;
      v34 = (const unsigned int *)packet[1].m_pPeer;
      packet[1].m_iValue = 32;
      if ( v33 == v34 )
      {
        packet[1].m_iValue = 1;
        packet[1].m_wsValue = nullptr;
        *(_DWORD *)&packet[1].m_iDataType = v33 + 1;
        v32 = v30;
      }
      else
      {
        if ( v33 <= v34 )
        {
          packet[1].m_wsValue = (wchar_t *)*v33;
          *(_DWORD *)&packet[1].m_iDataType = v33 + 1;
        }
        else
        {
          LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          packet[1].m_wsValue = nullptr;
        }
        v32 = v30;
      }
    }
    goto LABEL_60;
  }
  v35 = (const unsigned int *)packet[1].m_pPeer;
  v36 = (unsigned int)packet[1].m_wsValue;
  v37 = 32 - v29;
  v38 = *(const unsigned int **)&packet[1].m_iDataType;
  if ( v38 == v35 )
  {
    packet[1].m_iValue = 1;
    packet[1].m_wsValue = nullptr;
    LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
  }
  else
  {
    if ( v38 > v35 )
    {
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
      packet[1].m_wsValue = nullptr;
      goto LABEL_57;
    }
    packet[1].m_wsValue = (wchar_t *)*v38;
  }
  *(_DWORD *)&packet[1].m_iDataType = v38 + 1;
LABEL_57:
  if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
  {
    v32 = 0;
  }
  else
  {
    v39 = (unsigned int)packet[1].m_wsValue;
    v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << packet[1].m_iValue;
    packet[1].m_iValue = 32 - v37;
    v32 = v40 | v36;
    packet[1].m_wsValue = (wchar_t *)(v39 >> v37);
  }
LABEL_60:
  p_m_buffer = &this->m_buffer;
  CUtlBuffer::Clear(this: &this->m_buffer);
  CUtlBuffer::EnsureCapacity(this: &this->m_buffer, num: v32);
  CBitRead::ReadBytes(this: (CBitRead *)&packet->m_pChain, pOut: this->m_buffer.m_Memory.m_pMemory, nBytes: v32);
  CUtlBuffer::SeekPut(this: &this->m_buffer, type: SEEK_HEAD, offset: v32);
  CUtlBuffer::ActivateByteSwapping(this: &this->m_buffer, bActivate: true);
  v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v42 != nullptr )
    pMsga = KeyValues::KeyValues(this: v42, setName: str);
  else
    pMsga = nullptr;
  if ( KeyValues::ReadAsBinary(this: pMsga, buffer: (int)p_m_buffer) )
  {
    v43 = packet[1].m_iValue;
    v44 = (unsigned int)packet[1].m_wsValue;
    if ( v43 >= 32 )
    {
      v45 = v43 - 32;
      packet[1].m_iValue = v45;
      if ( v45 != 0 )
      {
        packet[1].m_wsValue = nullptr;
        v46 = v44;
      }
      else
      {
        v47 = *(const unsigned int **)&packet[1].m_iDataType;
        v48 = (const unsigned int *)packet[1].m_pPeer;
        packet[1].m_iValue = 32;
        if ( v47 == v48 )
        {
          packet[1].m_wsValue = nullptr;
          packet[1].m_iValue = 1;
          *(_DWORD *)&packet[1].m_iDataType = v47 + 1;
          v46 = v44;
        }
        else
        {
          if ( v47 <= v48 )
          {
            packet[1].m_wsValue = (wchar_t *)*v47;
            *(_DWORD *)&packet[1].m_iDataType = v47 + 1;
          }
          else
          {
            packet[1].m_wsValue = nullptr;
            LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
          }
          v46 = v44;
        }
      }
      goto LABEL_81;
    }
    v49 = (const unsigned int *)packet[1].m_pPeer;
    v54 = (unsigned int)packet[1].m_wsValue;
    v50 = 32 - v43;
    v51 = *(const unsigned int **)&packet[1].m_iDataType;
    if ( v51 == v49 )
    {
      packet[1].m_iValue = 1;
      packet[1].m_wsValue = nullptr;
      LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
    }
    else
    {
      if ( v51 > v49 )
      {
        LOBYTE(packet->m_pExpressionGetSymbolProc) = 1;
        packet[1].m_wsValue = nullptr;
LABEL_79:
        if ( LOBYTE(packet->m_pExpressionGetSymbolProc) != 0 )
          return pMsga;
        v52 = (unsigned int)packet[1].m_wsValue;
        v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << packet[1].m_iValue;
        packet[1].m_iValue = 32 - v50;
        v46 = v53 | v54;
        packet[1].m_wsValue = (wchar_t *)(v52 >> v50);
LABEL_81:
        if ( v46 != 0 )
        {
          CUtlBuffer::Clear(this: p_m_buffer);
          CUtlBuffer::EnsureCapacity(this: p_m_buffer, num: v46);
          CBitRead::ReadBytes(this: (CBitRead *)&packet->m_pChain, pOut: p_m_buffer->m_Memory.m_pMemory, nBytes: v46);
          CUtlBuffer::SeekPut(this: p_m_buffer, type: SEEK_HEAD, offset: v46);
          KeyValues::SetPtr(this: pMsga, keyName: "binary/ptr", value: p_m_buffer->m_Memory.m_pMemory);
        }
        return pMsga;
      }
      packet[1].m_wsValue = (wchar_t *)*v51;
    }
    *(_DWORD *)&packet[1].m_iDataType = v51 + 1;
    goto LABEL_79;
  }
  KeyValues::deleteThis(this: pMsga);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100081A0
// Name: public: virtual bool CConnectionlessLanMgr::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConnectionlessLanMgr::ProcessConnectionlessPacket(CConnectionlessLanMgr *this, KeyValues *packet)
{
  KeyValues *v2; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *v6; // eax

  v2 = CConnectionlessLanMgr::UnpackPacket(this, packet);
  if ( v2 == nullptr )
    return 0;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnNetLanConnectionlessPacket");
  else
    v5 = nullptr;
  v6 = netadr_s::ToString(this: (netadr_s *)packet, baseOnly: false);
  KeyValues::SetString(this: v5, keyName: "from", value: v6);
  KeyValues::AddSubKey(this: v5, pSubkey: v2);
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008220
// Name: public: void CConnectionlessLanMgr::SendPacket(class KeyValues __near *,char const __near *,enum INetSupport::NetworkSocket_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConnectionlessLanMgr::SendPacket(
        CConnectionlessLanMgr *this,
        KeyValues *pMsg,
        const char *szAddress,
        INetSupport::NetworkSocket_t eSock)
{
  int v4; // eax
  KeyValues *Key; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  void *Ptr; // edi
  int Int; // eax
  int v10; // esi
  unsigned __int16 v11; // [esp-4h] [ebp-510h]
  char buf[1200]; // [esp+8h] [ebp-504h] BYREF
  CUtlBuffer data; // [esp+4B8h] [ebp-54h] BYREF
  bf_write msg; // [esp+4E8h] [ebp-24h] BYREF
  netadr_s inetAddr; // [esp+500h] [ebp-Ch] BYREF

  bf_write::bf_write(this: &msg, pData: buf, nBytes: 1200, nBits: -1);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteLong(this: &msg, val: 0);
  v4 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  bf_write::WriteLong(this: &msg, val: v4);
  CUtlBuffer::CUtlBuffer(this: &data, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &data, bActivate: true);
  KeyValues::WriteAsBinary(this: pMsg, buffer: &data);
  bf_write::WriteLong(this: &msg, val: data.m_nMaxPut);
  bf_write::WriteBytes(this: &msg, pBuf: data.m_Memory.m_pMemory, nBytes: data.m_nMaxPut);
  Key = KeyValues::FindKey(this: pMsg, keyName: "binary/ptr", bCreate: false);
  v6 = KeyValues::FindKey(this: pMsg, keyName: "binary/size", bCreate: false);
  v7 = v6;
  if ( Key != nullptr
    && v6 != nullptr
    && (Ptr = KeyValues::GetPtr(this: Key, keyName: nullptr, defaultValue: nullptr),
        Int = KeyValues::GetInt(this: v7, keyName: nullptr, defaultValue: 0),
        v10 = Int,
        Ptr != nullptr)
    && Int != 0 )
  {
    bf_write::WriteLong(this: &msg, val: Int);
    if ( !bf_write::WriteBytes(this: &msg, pBuf: Ptr, nBytes: v10) )
    {
      CUtlBuffer::~CUtlBuffer(this: &data);
      return;
    }
  }
  else
  {
    bf_write::WriteLong(this: &msg, val: 0);
  }
  netadr_s::SetIP(this: &inetAddr, unIP: 0);
  netadr_s::SetPort(this: &inetAddr, newport: 0);
  netadr_s::SetType(this: &inetAddr, newtype: NA_IP);
  if ( szAddress != nullptr )
  {
    if ( *szAddress == 42 && szAddress[1] == 58 )
    {
      netadr_s::SetType(this: &inetAddr, newtype: NA_BROADCAST);
      v11 = atoi(nptr: szAddress + 2);
      netadr_s::SetPort(this: &inetAddr, newport: v11);
    }
    else
    {
      netadr_s::SetFromString(this: &inetAddr, pch: szAddress, bUseDNS: false);
    }
  }
  else
  {
    netadr_s::SetType(this: &inetAddr, newtype: NA_BROADCAST);
    netadr_s::SetPort(this: &inetAddr, newport: 0);
  }
  if ( netadr_s::GetType(this: &inetAddr) != NA_BROADCAST
    || net_allow_multicast.m_pParent != nullptr && net_allow_multicast.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pMatchExtensions->m_exts.m_pINetSupport->SendPacket(
      this: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: nullptr,
      a3: eSock,
      a4: &inetAddr,
      a5: msg.m_pData,
      a6: (msg.m_iCurBit + 7) >> 3,
      a7: nullptr,
      a8: false);
    if ( data.m_Memory.m_nGrowSize >= 0 && data.m_Memory.m_pMemory != nullptr )
      goto LABEL_22;
  }
  else if ( data.m_Memory.m_nGrowSize >= 0 && data.m_Memory.m_pMemory != nullptr )
  {
LABEL_22:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_Memory.m_pMemory);
  }
}

} // namespace matchmaking_ds
