// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: networksystem/netchan.cpp
// Functions: 109
// ============================================================

#include "networksystem\netchan.h"

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: void bf_write::WriteUBitLong(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteUBitLong(bf_write *this, unsigned int curData, int numbits, bool bCheckRange)
{
  int m_iCurBit; // ecx
  int m_nDataBits; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  m_iCurBit = this->m_iCurBit;
  m_nDataBits = this->m_nDataBits;
  if ( m_iCurBit + numbits <= m_nDataBits )
  {
    v7 = m_iCurBit;
    v8 = m_iCurBit & 0x1F;
    v9 = v7 >> 5;
    *(_DWORD *)&this->m_pData[4 * v9] = (curData << v8)
                                      | *(_DWORD *)&this->m_pData[4 * v9] & g_BitWriteMasks[0][32 * v8 + v8 + numbits];
    if ( 32 - v8 < numbits )
      *(_DWORD *)&this->m_pData[4 * v9 + 4] = (curData >> (32 - v8))
                                            | *(_DWORD *)&this->m_pData[4 * v9 + 4]
                                            & g_BitWriteMasks[0][numbits - (32 - v8)];
    this->m_iCurBit += numbits;
  }
  else
  {
    this->m_iCurBit = m_nDataBits;
    this->m_bOverflow = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: void LogMultiline(bool,char const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl LogMultiline(bool input, const char *label, const char *data, unsigned int len)
{
  bool v4; // zf
  unsigned int i; // esi
  unsigned int v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // esi
  char v9; // al
  int v10; // eax
  char v11; // cl
  _BYTE asc_line_4[84]; // [esp+4h] [ebp-54h] OVERLAPPED BYREF
  const char *direction; // [esp+5Ch] [ebp+4h]

  v4 = !input;
  direction = " << ";
  if ( v4 )
    direction = " >> ";
  for ( i = len; i != 0; len = i )
  {
    memset(asc_line_4, 32, 25);
    memset(dst: &asc_line_4[28], value: 0x20u, count: 0x38u);
    v6 = i;
    if ( i >= 0x18 )
      v6 = 24;
    v7 = 0;
    if ( v6 != 0 )
    {
      do
      {
        v8 = (unsigned __int8)data[v7];
        if ( isprint(c: v8) == 0 || iscntrl(c: v8) != 0 )
          v9 = 46;
        else
          v9 = data[v7];
        asc_line_4[v7] = v9;
        v10 = (v7 >> 2) + 2 * v7;
        v11 = HEX[v8 & 0xF];
        ++v7;
        asc_line_4[v10 + 28] = HEX[v8 >> 4];
        asc_line_4[v10 + 29] = v11;
      }
      while ( v7 < v6 );
      i = len;
    }
    asc_line_4[24] = 0;
    asc_line_4[83] = 0;
    _Msg(a1: "%s %s %s %s \n", label, direction, asc_line_4, &asc_line_4[28]);
    data += v6;
    i -= v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001330
// Name: public: CNetchanParanoidMode::MessageItem_t::MessageItem_t(void)
// Source: json
//------------------------------------------------------------------------------
CNetchanParanoidMode::MessageItem_t *__thiscall CNetchanParanoidMode::MessageItem_t::MessageItem_t(
        CNetchanParanoidMode::MessageItem_t *this)
{
  this->m_pMsg = nullptr;
  this->m_nMessageSize = 0;
  this->m_nType = 0;
  this->m_nGroup = 0;
  this->m_nStartBit = 0;
  this->m_szName[0] = 0;
  this->m_szDesc[0] = 0;
  this->m_nEndBit = -1;
  _V_memset(dest: this->m_Message, fill: 0, count: 128);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: void CNetchanParanoidMode::MessageItem_t::Init(class INetMessage __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::MessageItem_t::Init(
        CNetchanParanoidMode::MessageItem_t *this,
        INetMessage *msg,
        int nStartBit)
{
  const char *v4; // eax

  this->m_pMsg = msg;
  this->m_nMessageSize = msg->GetSize(this: msg);
  this->m_nType = msg->GetType(this: msg);
  this->m_nGroup = msg->GetGroup(this: msg);
  v4 = msg->GetName(this: msg);
  V_strncpy(pDest: this->m_szName, pSrc: v4, maxLen: 32);
  this->m_szDesc[0] = 0;
  this->m_nStartBit = nStartBit;
  this->m_nEndBit = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: void CNetchanParanoidMode::MessageItem_t::InitControlMessage(int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::MessageItem_t::InitControlMessage(
        CNetchanParanoidMode::MessageItem_t *this,
        int nType,
        int nStartBit,
        const char *pchName,
        const char *pchDesc)
{
  this->m_pMsg = nullptr;
  this->m_nMessageSize = 0;
  this->m_nGroup = 0;
  this->m_nType = nType;
  V_strncpy(pDest: this->m_szName, pSrc: pchName, maxLen: 32);
  V_strncpy(pDest: this->m_szDesc, pSrc: pchDesc, maxLen: 128);
  this->m_nStartBit = nStartBit;
  this->m_nEndBit = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: void CNetchanParanoidMode::MessageItem_t::UpdateRaw(class INetMessage __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::MessageItem_t::UpdateRaw(
        CNetchanParanoidMode::MessageItem_t *this,
        INetMessage *msg,
        int nEndBit)
{
  int v4; // eax
  const char *v5; // eax

  if ( msg->GetSize(this: msg) >= 0x80 )
    v4 = 128;
  else
    v4 = msg->GetSize(this: msg);
  _V_memcpy(dest: this->m_Message, src: msg, count: v4);
  this->m_nEndBit = nEndBit;
  v5 = msg->ToString(this: msg);
  V_strncpy(pDest: this->m_szDesc, pSrc: v5, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: void CNetchanParanoidMode::MessageItem_t::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::MessageItem_t::Dump(CNetchanParanoidMode::MessageItem_t *this)
{
  char *m_szName; // [esp-4h] [ebp-10h]

  if ( this->m_pMsg != nullptr && this->m_nEndBit == -1 )
    _Msg(a1: "---> DIDN'T FINISH PARSING %s\n", this->m_szName);
  _Msg(
    a1: "%s: type( %d ) group ( %d ) size ( %d bytes ), startbit %d end bit %d\n",
    this->m_szName,
    this->m_nType,
    this->m_nGroup,
    this->m_nMessageSize,
    this->m_nStartBit,
    this->m_nEndBit);
  _Msg(a1: "   %s\n", this->m_szDesc);
  m_szName = this->m_szName;
  if ( this->m_pMsg != nullptr )
  {
    _Msg(a1: "RAW(%s) start\n", m_szName);
    LogMultiline(input: false, label: this->m_szName, data: (const char *)this->m_pMsg, len: this->m_nMessageSize);
    _Msg(a1: "RAW(%s) end\n", this->m_szName);
  }
  else
  {
    _Msg(a1: " %s Control message\n", m_szName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: virtual bool CNetChan::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsLoopback(CNetChan *this)
{
  return netadr_s::IsLoopback(this: &this->remote_address);
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual bool CNetChan::IsNull(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsNull(CNetChan *this)
{
  return netadr_s::GetType(this: &this->remote_address) == NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: private: void CNetChan::UncompressFragments(struct CNetChan::DataFragments_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UncompressFragments(CNetChan *this, CNetChan::DataFragments_t *data)
{
  CNetChan::DataFragments_t *v2; // esi
  char *v3; // edi
  CNetChan::DataFragments_t *v4; // ecx
  char *buffer; // [esp-4h] [ebp-10h]
  unsigned int bytes; // [esp+0h] [ebp-Ch]

  v2 = data;
  if ( data->isCompressed )
  {
    v3 = (char *)operator new(nSize: 4 * ((data->nUncompressedSize + 3) >> 2));
    bytes = v2->bytes;
    buffer = v2->buffer;
    data = (CNetChan::DataFragments_t *)v2->nUncompressedSize;
    g_pNetworkSystem->BufferToBufferDecompress(
      this: g_pNetworkSystem,
      a2: v3,
      a3: (unsigned int *)&data,
      a4: buffer,
      a5: bytes);
    free(pMem: v2->buffer);
    v4 = data;
    v2->buffer = v3;
    v2->bytes = (unsigned int)v4;
    v2->isCompressed = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: virtual void CNetChan::RequestFile_OLD(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RequestFile_OLD(CNetChan *this, const char *filename, unsigned int transferID)
{
  _Error(a1: "Called RequestFile_OLD");
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: virtual unsigned int CNetChan::GetChallengeNr(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::GetChallengeNr(CNetChan *this)
{
  return this->m_ChallengeNr;
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: virtual void CNetChan::GetSequenceData(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::GetSequenceData(
        CNetChan *this,
        int *nOutSequenceNr,
        int *nInSequenceNr,
        int *nOutSequenceNrAck)
{
  *nOutSequenceNr = this->m_nOutSequenceNr;
  *nInSequenceNr = this->m_nInSequenceNr;
  *nOutSequenceNrAck = this->m_nOutSequenceNrAck;
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: public: virtual void CNetChan::SetSequenceData(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetSequenceData(CNetChan *this, int nOutSequenceNr, int nInSequenceNr, int nOutSequenceNrAck)
{
  this->m_nOutSequenceNr = nOutSequenceNr;
  this->m_nInSequenceNr = nInSequenceNr;
  this->m_nOutSequenceNrAck = nOutSequenceNrAck;
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: public: virtual void CNetChan::SetDemoRecorder(class IDemoRecorderBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDemoRecorder(CNetChan *this, IDemoRecorderBase *recorder)
{
  this->m_DemoRecorder = recorder;
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: virtual void CNetChan::SetTimeout(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetTimeout(CNetChan *this, float seconds, bool bForceExact)
{
  float v3; // xmm1_4

  this->m_Timeout = seconds;
  if ( !bForceExact )
  {
    v3 = 3600.0;
    if ( seconds > 3600.0 )
      goto LABEL_6;
    if ( seconds <= 0.0 )
    {
      this->m_Timeout = -1.0;
      return;
    }
    v3 = 4.0;
    if ( seconds < 4.0 )
LABEL_6:
      this->m_Timeout = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: virtual void CNetChan::SetFileTransmissionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetFileTransmissionMode(CNetChan *this, bool bBackgroundMode)
{
  this->m_bFileBackgroundTranmission = bBackgroundMode;
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: virtual void CNetChan::SetCompressionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetCompressionMode(CNetChan *this, bool bUseCompression)
{
  this->m_bUseCompression = bUseCompression;
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: public: virtual void CNetChan::SetDataRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDataRate(CNetChan *this, float rate)
{
  float v2; // xmm0_4

  v2 = rate;
  if ( rate > 30000.0 )
  {
    v2 = 30000.0;
LABEL_3:
    this->m_Rate = (int)v2;
    return;
  }
  if ( rate >= 1000.0 )
    goto LABEL_3;
  this->m_Rate = (int)1000.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001730
// Name: public: virtual char const __near * CNetChan::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNetChan::GetName(CNetChan *this)
{
  return this->m_Name;
}

//------------------------------------------------------------------------------
// Address: 0x10001740
// Name: public: virtual char const __near * CNetChan::GetAddress(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetChan::GetAddress(CNetChan *this)
{
  return netadr_s::ToString(this: &this->remote_address, baseOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10001750
// Name: public: virtual int CNetChan::GetDropNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDropNumber(CNetChan *this)
{
  return this->m_PacketDrop;
}

//------------------------------------------------------------------------------
// Address: 0x10001760
// Name: private: void CNetChan::FlowNewPacket(int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::FlowNewPacket(
        CNetChan *this,
        int flow,
        int seqnr,
        int acknr,
        int nChoked,
        int nDropped,
        int nSize)
{
  int currentindex; // ebx
  CNetChan::NetFlow_t *v9; // ebp
  int v10; // eax
  int v11; // esi
  int v12; // ebx
  BOOL v13; // eax
  int v14; // eax
  float *v15; // esi
  long double v16; // st7
  int v17; // [esp+10h] [ebp-8h]

  currentindex = this->m_DataFlow[flow].currentindex;
  v9 = &this->m_DataFlow[flow];
  v10 = seqnr;
  v11 = 0;
  if ( seqnr > currentindex )
  {
    v12 = currentindex + 1;
    if ( v12 <= seqnr )
    {
      v17 = seqnr - v12;
      do
      {
        v11 = (int)&v9->frames[v12 & 0x7F];
        *(float *)v11 = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
        *(_BYTE *)(v11 + 56) = 0;
        *(_DWORD *)(v11 + 4) = 0;
        *(_DWORD *)(v11 + 16) = -1082130432;
        *(float *)(v11 + 20) = this->GetAvgLatency(this, a2: 0);
        *(_DWORD *)(v11 + 8) = 0;
        *(_DWORD *)(v11 + 12) = 0;
        *(_DWORD *)(v11 + 24) = 0;
        _V_memset(dest: v9->frames[v12 & 0x7F].msggroups, fill: 0, count: 28);
        if ( v17 < nDropped + nChoked )
        {
          if ( v17 >= nChoked )
            v9->frames[v12 & 0x7F].dropped = 1;
          else
            v9->frames[v12 & 0x7F].choked = 1;
        }
        ++v12;
        --v17;
      }
      while ( v12 <= seqnr );
    }
    *(_DWORD *)(v11 + 8) = nChoked;
    *(_DWORD *)(v11 + 4) = nSize;
    *(_DWORD *)(v11 + 12) = nDropped;
    *(_BYTE *)(v11 + 56) = 1;
    *(float *)(v11 + 20) = this->GetAvgLatency(this, a2: 0);
    v10 = seqnr;
    *(float *)(v11 + 24) = this->m_flInterpolationAmount;
  }
  ++v9->totalpackets;
  v9->currentindex = v10;
  v9->currentframe = (CNetChan::NetFrame_t *)v11;
  v13 = flow == 0;
  if ( acknr > this->m_DataFlow[v13].currentindex - 128 )
  {
    v14 = v13 * 7724 + 60 * (acknr & 0x7F);
    v15 = (float *)((char *)&this->m_DataFlow[0].frames[0].time + v14);
    if ( *((_BYTE *)&this->m_DataFlow[0].frames[0].msggroups[14] + v14) != 0
      && *(float *)((char *)&this->m_DataFlow[0].frames[0].latency + v14) == -1.0 )
    {
      v16 = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) - *v15;
      v15[4] = v16;
      if ( v16 < 0.0 )
        v15[4] = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001910
// Name: private: void CNetChan::FlowUpdate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::FlowUpdate(CNetChan *this, int flow, int addbytes)
{
  CNetChan::NetFlow_t *v3; // edi
  float v4; // xmm2_4
  int v5; // edx
  int v6; // esi
  int v7; // ebx
  int v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm0_4
  int *p_choked; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm0_4
  float avglatency; // xmm1_4
  float v24; // xmm4_4
  long double nextcompute; // [esp+0h] [ebp-8h]
  int totallatencycount; // [esp+Ch] [ebp+4h]
  int addbytesa; // [esp+10h] [ebp+8h]

  nextcompute = this->m_DataFlow[flow].nextcompute;
  v3 = &this->m_DataFlow[flow];
  this->m_DataFlow[flow].totalbytes += addbytes;
  if ( nextcompute <= g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) )
  {
    v4 = 3.4028235e38;
    v3->nextcompute = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) + 0.25;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0.0;
    totallatencycount = 0;
    v10 = 0.0;
    p_choked = &v3->frames[0].choked;
    for ( addbytesa = 32; addbytesa != 0; --addbytesa )
    {
      if ( *((_BYTE *)p_choked + 48) != 0 )
      {
        v12 = *((float *)p_choked - 2);
        if ( v4 > v12 )
          v4 = *((float *)p_choked - 2);
        if ( v12 > v10 )
          v10 = *((float *)p_choked - 2);
        v5 += *p_choked;
        v8 += *(p_choked - 1);
        v13 = *((float *)p_choked + 2);
        ++v6;
        if ( v13 > -1.0 )
        {
          ++totallatencycount;
          v9 = v13 + v9;
        }
      }
      else
      {
        ++v7;
      }
      if ( *((_BYTE *)p_choked + 108) != 0 )
      {
        v14 = *((float *)p_choked + 13);
        if ( v4 > v14 )
          v4 = *((float *)p_choked + 13);
        if ( v14 > v10 )
          v10 = *((float *)p_choked + 13);
        v5 += p_choked[15];
        v8 += p_choked[14];
        v15 = *((float *)p_choked + 17);
        ++v6;
        if ( v15 > -1.0 )
        {
          ++totallatencycount;
          v9 = v15 + v9;
        }
      }
      else
      {
        ++v7;
      }
      if ( *((_BYTE *)p_choked + 168) != 0 )
      {
        v16 = *((float *)p_choked + 28);
        if ( v4 > v16 )
          v4 = *((float *)p_choked + 28);
        if ( v16 > v10 )
          v10 = *((float *)p_choked + 28);
        v5 += p_choked[30];
        v8 += p_choked[29];
        v17 = *((float *)p_choked + 32);
        ++v6;
        if ( v17 > -1.0 )
        {
          ++totallatencycount;
          v9 = v17 + v9;
        }
      }
      else
      {
        ++v7;
      }
      if ( *((_BYTE *)p_choked + 228) != 0 )
      {
        v18 = *((float *)p_choked + 43);
        if ( v4 > v18 )
          v4 = *((float *)p_choked + 43);
        if ( v18 > v10 )
          v10 = *((float *)p_choked + 43);
        v5 += p_choked[45];
        v8 += p_choked[44];
        v19 = *((float *)p_choked + 47);
        ++v6;
        if ( v19 > -1.0 )
        {
          ++totallatencycount;
          v9 = v19 + v9;
        }
      }
      else
      {
        ++v7;
      }
      p_choked += 60;
    }
    v20 = v10 - v4;
    if ( v20 > 0.0 )
    {
      v3->avgbytespersec = (float)((float)((float)v8 * (float)(1.0 / v20)) * 0.25) + (float)(v3->avgbytespersec * 0.75);
      v3->avgpacketspersec = (float)((float)((float)v6 * (float)(1.0 / v20)) * 0.25)
                           + (float)(v3->avgpacketspersec * 0.75);
    }
    v21 = v7 + v6;
    if ( v7 + v6 > 0 )
    {
      v22 = (float)((float)((float)(v7 - v5) / (float)v21) * 0.25) + (float)(v3->avgloss * 0.75);
      v3->avgloss = v22;
      if ( v22 < 0.0 )
        v3->avgloss = 0.0;
      v3->avgchoke = (float)((float)((float)v5 / (float)v21) * 0.25) + (float)(v3->avgchoke * 0.75);
    }
    if ( totallatencycount > 0 )
    {
      avglatency = v3->avglatency;
      v24 = v9 / (float)totallatencycount;
      v3->latency = v24;
      v3->avglatency = (float)(avglatency * 0.75) + (float)(v24 * 0.25);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: virtual void CNetChan::SetChoked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetChoked(CNetChan *this)
{
  ++this->m_nOutSequenceNr;
  ++this->m_nChokedPackets;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: virtual bool CNetChan::Transmit(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::Transmit(CNetChan *this, bool onlyReliable)
{
  if ( onlyReliable )
    bf_write::Reset(this: &this->m_StreamUnreliable);
  return this->SendDatagram(this, a2: nullptr) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual bool CNetChan::SetActiveChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SetActiveChannel(CNetChan *this, INetChannel *pNewChannel)
{
  this->m_pActiveChannel = pNewChannel;
  return pNewChannel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: virtual bool CNetChan::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CNetChan::SendNetMsg@<eax>(
        CNetChan *this@<ecx>,
        int a2@<edi>,
        INetMessage *msg,
        bool bForceReliable,
        bool bVoice,
        char a6)
{
  bf_write *p_m_StreamUnreliable; // esi

  if ( netadr_s::GetType(this: &this->remote_address) == NA_NULL )
    return 1;
  p_m_StreamUnreliable = &this->m_StreamUnreliable;
  if ( ((unsigned __int8 (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2) != 0 || bVoice )
    p_m_StreamUnreliable = &this->m_StreamReliable;
  if ( a6 != 0 )
    p_m_StreamUnreliable = &this->m_StreamVoice;
  return ((int (__thiscall *)(INetMessage *, bf_write *))msg->WriteToBuffer)(a1: msg, a2: p_m_StreamUnreliable);
}

//------------------------------------------------------------------------------
// Address: 0x10001C70
// Name: public: virtual bool CNetChan::SendData(class bf_write __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendData(CNetChan *this, bf_write *msg, bool bReliable)
{
  int m_iCurBit; // edx
  bf_write *p_m_StreamUnreliable; // ecx

  if ( netadr_s::GetType(this: &this->remote_address) == NA_NULL )
    return true;
  m_iCurBit = msg->m_iCurBit;
  if ( m_iCurBit <= 0 )
    return true;
  if ( msg->m_bOverflow )
  {
    if ( !bReliable )
      return true;
  }
  else if ( !bReliable )
  {
    p_m_StreamUnreliable = &this->m_StreamUnreliable;
LABEL_10:
    if ( m_iCurBit <= p_m_StreamUnreliable->m_nDataBits - p_m_StreamUnreliable->m_iCurBit )
      return bf_write::WriteBits(this: p_m_StreamUnreliable, pInData: msg->m_pData, nBits: m_iCurBit);
    if ( bReliable )
      _Msg(a1: "ERROR! SendData reliabe data too big (%i)", (m_iCurBit + 7) >> 3);
    return false;
  }
  p_m_StreamUnreliable = &this->m_StreamReliable;
  goto LABEL_10;
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: virtual int CNetChan::GetDataRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDataRate(CNetChan *this)
{
  return this->m_Rate;
}

//------------------------------------------------------------------------------
// Address: 0x10001D00
// Name: public: virtual float CNetChan::GetTimeConnected(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeConnected(CNetChan *this)
{
  long double v1; // st7

  v1 = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) - this->connect_time;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: public: virtual struct netadr_s const __near & CNetChan::GetRemoteAddress(void)const
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CNetChan::GetRemoteAddress(CNetChan *this)
{
  return &this->remote_address;
}

//------------------------------------------------------------------------------
// Address: 0x10001D60
// Name: public: virtual class INetChannelHandler __near * CNetChan::GetMsgHandler(void)const
// Source: json
//------------------------------------------------------------------------------
INetChannelHandler *__thiscall CNetChan::GetMsgHandler(CNetChan *this)
{
  return this->m_MessageHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10001D70
// Name: public: virtual bool CNetChan::IsTimedOut(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsTimedOut(CNetChan *this)
{
  double v2; // [esp+0h] [ebp-8h]

  if ( this->m_Timeout == -1.0 )
    return false;
  v2 = this->last_received + this->m_Timeout;
  return g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) > v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: public: virtual bool CNetChan::IsTimingOut(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsTimingOut(CNetChan *this)
{
  double v2; // [esp+0h] [ebp-8h]

  if ( this->m_Timeout == -1.0 )
    return false;
  v2 = this->last_received + 4.0;
  return g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) > v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001E30
// Name: public: virtual float CNetChan::GetTimeoutSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeoutSeconds(CNetChan *this)
{
  return this->m_Timeout;
}

//------------------------------------------------------------------------------
// Address: 0x10001E40
// Name: public: virtual float CNetChan::GetTimeSinceLastReceived(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeSinceLastReceived(CNetChan *this)
{
  long double v1; // st7

  v1 = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) - this->last_received;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10001E90
// Name: public: virtual bool CNetChan::IsOverflowed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsOverflowed(CNetChan *this)
{
  return this->m_StreamReliable.m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x10001EA0
// Name: public: virtual void CNetChan::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Reset(CNetChan *this)
{
  bf_write::Reset(this: &this->m_StreamUnreliable);
  bf_write::Reset(this: &this->m_StreamReliable);
  this->m_flClearTime = 0.0;
  this->m_nChokedPackets = 0;
  this->m_nSplitPacketSequence = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: public: virtual int CNetChan::GetSocket(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetSocket(CNetChan *this)
{
  return this->m_Socket;
}

//------------------------------------------------------------------------------
// Address: 0x10001EF0
// Name: public: virtual float CNetChan::GetAvgData(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgbytespersec;
}

//------------------------------------------------------------------------------
// Address: 0x10001F10
// Name: public: virtual float CNetChan::GetAvgPackets(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgpacketspersec;
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual int CNetChan::GetTotalData(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalbytes;
}

//------------------------------------------------------------------------------
// Address: 0x10001F50
// Name: public: virtual int CNetChan::GetTotalPackets(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalpackets;
}

//------------------------------------------------------------------------------
// Address: 0x10001F70
// Name: public: virtual int CNetChan::GetSequenceNr(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetSequenceNr(CNetChan *this, int flow)
{
  if ( flow == 0 )
    return this->m_nOutSequenceNr;
  if ( flow == 1 )
    return this->m_nInSequenceNr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: virtual int CNetChan::GetBufferSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetBufferSize(CNetChan *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x10001FA0
// Name: public: virtual bool CNetChan::IsValidPacket(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsValidPacket(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frames[frame_number & 0x7F].valid;
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: public: virtual float CNetChan::GetPacketTime(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetPacketTime(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frames[frame_number & 0x7F].time;
}

//------------------------------------------------------------------------------
// Address: 0x10002000
// Name: public: virtual void CNetChan::GetPacketResponseLatency(int,int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::GetPacketResponseLatency(
        CNetChan *this,
        int flow,
        char frame_number,
        int *pnLatencyMsecs,
        int *pnChoke)
{
  if ( pnLatencyMsecs != nullptr )
  {
    if ( this->m_DataFlow[flow].frames[frame_number & 0x7F].dropped != 0 )
      *pnLatencyMsecs = 9999;
    else
      *pnLatencyMsecs = (int)(float)(this->m_DataFlow[flow].frames[frame_number & 0x7F].avg_latency * 1000.0);
  }
  if ( pnChoke != nullptr )
    *pnChoke = this->m_DataFlow[flow].frames[frame_number & 0x7F].choked;
}

//------------------------------------------------------------------------------
// Address: 0x10002060
// Name: public: virtual void CNetChan::GetRemoteFramerate(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::GetRemoteFramerate(
        CNetChan *this,
        float *pflFrameTime,
        float *pflRemoteFrameTimeStdDeviation)
{
  if ( pflFrameTime != nullptr )
    *pflFrameTime = this->m_flRemoteFrameTime;
  if ( pflRemoteFrameTimeStdDeviation != nullptr )
    *pflRemoteFrameTimeStdDeviation = this->m_flRemoteFrameTimeStdDeviation;
}

//------------------------------------------------------------------------------
// Address: 0x10002090
// Name: public: virtual float CNetChan::GetLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].latency;
}

//------------------------------------------------------------------------------
// Address: 0x100020B0
// Name: public: virtual float CNetChan::GetAvgChoke(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgChoke(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgchoke;
}

//------------------------------------------------------------------------------
// Address: 0x100020D0
// Name: public: virtual float CNetChan::GetAvgLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avglatency;
}

//------------------------------------------------------------------------------
// Address: 0x100020F0
// Name: public: virtual float CNetChan::GetAvgLoss(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLoss(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgloss;
}

//------------------------------------------------------------------------------
// Address: 0x10002110
// Name: public: virtual float CNetChan::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CNetChan::GetTime(CNetChan *this)
{
  return g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10002120
// Name: public: virtual float CNetChan::GetCommandInterpolationAmount(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetCommandInterpolationAmount(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frames[frame_number & 0x7F].m_flInterpolationAmount;
}

//------------------------------------------------------------------------------
// Address: 0x10002150
// Name: public: virtual int CNetChan::GetPacketBytes(int,int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetPacketBytes(CNetChan *this, int flow, char frame_number, int group)
{
  int v4; // eax

  v4 = frame_number & 0x7F;
  if ( group < 14 )
    return (this->m_DataFlow[flow].frames[v4].msggroups[group] + 7) >> 3;
  else
    return this->m_DataFlow[flow].frames[v4].size;
}

//------------------------------------------------------------------------------
// Address: 0x100021B0
// Name: public: virtual void CNetChan::UpdateMessageStats(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateMessageStats(CNetChan *this, int msggroup, int bits)
{
  CNetChan::NetFrame_t *currentframe; // eax

  currentframe = this->m_DataFlow[1].currentframe;
  this->m_MsgStats[msggroup] += bits;
  if ( currentframe != nullptr )
    currentframe->msggroups[msggroup] += bits;
}

//------------------------------------------------------------------------------
// Address: 0x100021E0
// Name: public: void CNetChan::IncrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::IncrementQueuedPackets(CNetChan *this)
{
  ++this->m_nQueuedPackets;
}

//------------------------------------------------------------------------------
// Address: 0x100021F0
// Name: public: void CNetChan::DecrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DecrementQueuedPackets(CNetChan *this)
{
  if ( --this->m_nQueuedPackets < 0 )
    this->m_nQueuedPackets = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002210
// Name: public: virtual void CNetChan::SetInterpolationAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetInterpolationAmount(CNetChan *this, float flInterpolationAmount)
{
  this->m_flInterpolationAmount = flInterpolationAmount;
}

//------------------------------------------------------------------------------
// Address: 0x10002230
// Name: public: virtual void CNetChan::SetRemoteFramerate(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetRemoteFramerate(CNetChan *this, float flFrameTime, float flFrameTimeStdDeviation)
{
  this->m_flRemoteFrameTime = flFrameTime;
  this->m_flRemoteFrameTimeStdDeviation = flFrameTimeStdDeviation;
}

//------------------------------------------------------------------------------
// Address: 0x10002250
// Name: public: virtual void CNetChan::SetMaxRoutablePayloadSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxRoutablePayloadSize(CNetChan *this, int nMaxRoutablePayloadSize)
{
  const char *v3; // eax

  if ( this->m_nMaxRoutablePayloadSize != nMaxRoutablePayloadSize )
  {
    v3 = (const char *)this->GetName(this);
    DevMsg(
      a1: "Setting max routable payload size from %d to %d for %s\n",
      this->m_nMaxRoutablePayloadSize,
      nMaxRoutablePayloadSize,
      v3);
  }
  this->m_nMaxRoutablePayloadSize = nMaxRoutablePayloadSize;
}

//------------------------------------------------------------------------------
// Address: 0x10002290
// Name: public: virtual int CNetChan::GetMaxRoutablePayloadSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetMaxRoutablePayloadSize(CNetChan *this)
{
  return this->m_nMaxRoutablePayloadSize;
}

//------------------------------------------------------------------------------
// Address: 0x100022A0
// Name: public: int CNetChan::IncrementSplitPacketSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::IncrementSplitPacketSequence(CNetChan *this)
{
  return ++this->m_nSplitPacketSequence;
}

//------------------------------------------------------------------------------
// Address: 0x100022B0
// Name: public: virtual int CNetChan::GetNumBitsWritten(enum ENetChannelBufType)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetNumBitsWritten(CNetChan *this, ENetChannelBufType ENetChannelBufType)
{
  switch ( ENetChannelBufType )
  {
    case BUF_RELIABLE:
      return this->m_StreamReliable.m_iCurBit;
    case BUF_UNRELIABLE:
      return this->m_StreamUnreliable.m_iCurBit;
    case BUF_VOICE:
      return this->m_StreamVoice.m_iCurBit;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: public: virtual bool CNetChan::IsRemoteDisconnected(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsRemoteDisconnected(CNetChan *this)
{
  netadr_s *p_remote_address; // esi

  p_remote_address = &this->remote_address;
  return netadr_s::IsValid(this: &this->remote_address)
      && netadr_s::GetPort(this: p_remote_address) == 1
      && (__int64)g_pSteamSocketMgrInternal->GetSteamIDForRemote(this: g_pSteamSocketMgrInternal, a2: p_remote_address) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002320
// Name: public: static void CNetChan::InitParanoidMode(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNetChan::InitParanoidMode()
{
  CNetchanParanoidMode::MessageItem_t *v0; // eax
  CNetchanParanoidMode::MessageItem_t *v1; // esi

  g_NetParanoid.m_bInitialized = true;
  g_NetParanoid.m_pRawData = (unsigned __int8 *)operator new(nSize: 0x17700u);
  v0 = (CNetchanParanoidMode::MessageItem_t *)operator new(nSize: 0x13800u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    `vector constructor iterator'(
      __t: v0,
      __s: 0x138u,
      __n: 256,
      __f: (void *(__thiscall *)(void *))CNetchanParanoidMode::MessageItem_t::MessageItem_t);
    g_NetParanoid.m_pPacketMessages = v1;
  }
  else
  {
    g_NetParanoid.m_pPacketMessages = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002380
// Name: public: void CNetchanParanoidMode::StartPacket(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::StartPacket(CNetchanParanoidMode *this, bf_read *fullbuf)
{
  unsigned int m_nDataBytes; // eax
  unsigned __int8 *m_pRawData; // edx

  if ( this->m_bInitialized && net_paranoid.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nDataBytes = fullbuf->m_nDataBytes;
    if ( m_nDataBytes >= 0x17700 )
      m_nDataBytes = 96000;
    m_pRawData = this->m_pRawData;
    this->m_nRawDataSize = m_nDataBytes;
    _V_memcpy(dest: m_pRawData, src: fullbuf->m_pData, count: m_nDataBytes);
    this->m_nPacketMessageCount = 0;
    this->m_nHeaderBits = 0;
    this->m_nFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: public: void CNetchanParanoidMode::NoteHeaderSize(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::NoteHeaderSize(CNetchanParanoidMode *this, bf_read *msg, int flags)
{
  const unsigned int *m_pData; // eax
  signed int m_nDataBits; // eax

  if ( this->m_bInitialized && net_paranoid.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pData = msg->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (msg->m_pDataIn - m_pData) - msg->m_nBitsAvail + 8 * (msg->m_nDataBytes & 3);
      if ( m_nDataBits >= msg->m_nDataBits )
        m_nDataBits = msg->m_nDataBits;
      this->m_nHeaderBits = m_nDataBits;
      this->m_nFlags = flags;
    }
    else
    {
      this->m_nHeaderBits = 0;
      this->m_nFlags = flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002450
// Name: public: void CNetchanParanoidMode::AddControlMessage(int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::AddControlMessage(
        CNetchanParanoidMode *this,
        int m_nType,
        int nStartBit,
        const char *name,
        const char *desc)
{
  int m_nPacketMessageCount; // edx
  CNetchanParanoidMode::MessageItem_t *v6; // eax

  if ( this->m_bInitialized && net_paranoid.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nPacketMessageCount = this->m_nPacketMessageCount;
    if ( m_nPacketMessageCount < 255 )
    {
      v6 = &this->m_pPacketMessages[m_nPacketMessageCount];
      this->m_nPacketMessageCount = m_nPacketMessageCount + 1;
      CNetchanParanoidMode::MessageItem_t::InitControlMessage(
        this: v6,
        nType: m_nType,
        nStartBit,
        pchName: name,
        pchDesc: desc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002490
// Name: public: void CNetchanParanoidMode::Dump(class CNetChan __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::Dump(CNetchanParanoidMode *this, CNetChan *channel, const char *pchReason)
{
  int v4; // ebx
  netadr_s *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  CNetchanParanoidMode::MessageItem_t *v8; // esi
  const char *v9; // [esp-14h] [ebp-18h]
  const char *pchReasona; // [esp+Ch] [ebp+8h]

  if ( this->m_bInitialized )
  {
    v4 = 0;
    if ( net_paranoid.m_pParent->m_Value.m_nValue != 0 )
    {
      _Msg(a1: "%s\n ", pchReason);
      v5 = (netadr_s *)channel->GetRemoteAddress(this: channel);
      v6 = netadr_s::ToString(this: v5, baseOnly: false);
      v7 = (const char *)((int (__thiscall *)(CNetChan *, const char *))channel->GetName)(a1: channel, a2: v6);
      _Msg(a1: "Dumping messages for channel %s(%s) 0x%p\n", v7, v9, channel);
      _Msg(a1: "Header bits %d, flags == %d\n", this->m_nHeaderBits, this->m_nFlags);
      _Msg(a1: "%d messages\n", this->m_nPacketMessageCount);
      if ( this->m_nPacketMessageCount > 0 )
      {
        pchReasona = nullptr;
        do
        {
          v8 = (CNetchanParanoidMode::MessageItem_t *)&pchReasona[(unsigned int)this->m_pPacketMessages];
          _Msg(a1: "%d -----------------------\n", v4);
          CNetchanParanoidMode::MessageItem_t::Dump(this: v8);
          pchReasona += 312;
          ++v4;
        }
        while ( v4 < this->m_nPacketMessageCount );
      }
      _Msg(a1: "Raw\n");
      LogMultiline(input: false, label: "PKT", data: (const char *)this->m_pRawData, len: this->m_nRawDataSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002570
// Name: public: virtual unsigned int CNetChan::RequestFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::RequestFile(CNetChan *this, const char *filename, bool bIsReplayDemoFile)
{
  bf_write *p_m_StreamReliable; // esi
  int v5; // eax
  int m_iCurBit; // ecx
  unsigned __int8 *v7; // eax
  char v8; // dl
  int v9; // ecx

  ++this->m_FileRequestCounter;
  if ( net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "RequestFile: %s (ID %i)\n", filename, this->m_FileRequestCounter);
  p_m_StreamReliable = &this->m_StreamReliable;
  v5 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
  bf_write::WriteUBitLong(this: &this->m_StreamReliable, curData: 2u, numbits: v5, bCheckRange: true);
  bf_write::WriteUBitLong(
    this: &this->m_StreamReliable,
    curData: this->m_FileRequestCounter,
    numbits: 32,
    bCheckRange: true);
  bf_write::WriteString(this: &this->m_StreamReliable, pStr: filename);
  m_iCurBit = this->m_StreamReliable.m_iCurBit;
  if ( m_iCurBit + 1 > this->m_StreamReliable.m_nDataBits )
    this->m_StreamReliable.m_bOverflow = true;
  if ( !this->m_StreamReliable.m_bOverflow )
  {
    v7 = &p_m_StreamReliable->m_pData[m_iCurBit >> 3];
    v8 = 1 << (m_iCurBit & 7);
    if ( bIsReplayDemoFile )
      *v7 |= v8;
    else
      *v7 &= ~v8;
    ++this->m_StreamReliable.m_iCurBit;
  }
  v9 = this->m_StreamReliable.m_iCurBit;
  if ( v9 + 1 > this->m_StreamReliable.m_nDataBits )
    this->m_StreamReliable.m_bOverflow = true;
  if ( !this->m_StreamReliable.m_bOverflow )
  {
    p_m_StreamReliable->m_pData[v9 >> 3] |= 1 << (v9 & 7);
    ++this->m_StreamReliable.m_iCurBit;
  }
  return this->m_FileRequestCounter;
}

//------------------------------------------------------------------------------
// Address: 0x10002650
// Name: public: virtual void CNetChan::DenyFile(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DenyFile(
        CNetChan *this,
        const char *filename,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  bf_write *p_m_StreamReliable; // esi
  int v6; // eax
  int m_iCurBit; // ecx
  unsigned __int8 *v8; // eax
  char v9; // dl
  int v10; // ecx

  if ( net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "DenyFile: %s (ID %i)\n", filename, transferID);
  p_m_StreamReliable = &this->m_StreamReliable;
  v6 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: 2u, numbits: v6, bCheckRange: true);
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: transferID, numbits: 32, bCheckRange: true);
  bf_write::WriteString(this: p_m_StreamReliable, pStr: filename);
  m_iCurBit = p_m_StreamReliable->m_iCurBit;
  if ( m_iCurBit + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    v8 = &p_m_StreamReliable->m_pData[m_iCurBit >> 3];
    v9 = 1 << (m_iCurBit & 7);
    if ( bIsReplayDemoFile )
      *v8 |= v9;
    else
      *v8 &= ~v9;
    ++p_m_StreamReliable->m_iCurBit;
  }
  v10 = p_m_StreamReliable->m_iCurBit;
  if ( v10 + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    p_m_StreamReliable->m_pData[v10 >> 3] &= ~(1 << (v10 & 7));
    ++p_m_StreamReliable->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002720
// Name: public: void CNetChan::Setup(int,struct netadr_s __near &,char const __near *,class INetChannelHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetChan::Setup(
        CNetChan *this@<ecx>,
        int a2@<edi>,
        int sock,
        netadr_s *adr,
        const char *name,
        INetChannelHandler *handler,
        INetChannelHandler *a7)
{
  CNetChan_vtbl *v8; // edx
  void (__thiscall *SetMaxBufferSize)(struct CNetChan *, ENetChannelBufType, int); // eax
  int v10; // edx
  int *p_sendSeqNr; // eax
  int i; // ecx

  this->m_Socket = sock;
  this->remote_address = *adr;
  this->last_received = ((double (__thiscall *)(INetworkSystem *, int))g_pNetworkSystem->GetNetTime)(
                          a1: g_pNetworkSystem,
                          a2);
  this->connect_time = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
  V_strncpy(pDest: this->m_Name, pSrc: (const char *)handler, maxLen: 32);
  v8 = this->__vftable;
  this->m_MessageHandler = a7;
  SetMaxBufferSize = v8->SetMaxBufferSize;
  this->m_DemoRecorder = nullptr;
  SetMaxBufferSize(this, a2: BUF_UNRELIABLE, a3: 4000);
  this->SetMaxBufferSize(this, a2: BUF_VOICE, a3: 4000);
  this->SetMaxBufferSize(this, a2: BUF_RELIABLE, a3: 96000);
  this->m_Timeout = 300.0;
  v10 = 0;
  this->m_Rate = 10000;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_nChokedPackets = 0;
  this->m_flClearTime = 0.0;
  this->m_ChallengeNr = 0;
  this->m_ReceiveList[0].buffer = nullptr;
  this->m_ReceiveList[1].buffer = nullptr;
  p_sendSeqNr = &this->m_SubChannels[0].sendSeqNr;
  do
  {
    p_sendSeqNr[2] = v10;
    p_sendSeqNr[1] = 0;
    *p_sendSeqNr = -1;
    for ( i = 0; i < 2; ++i )
    {
      p_sendSeqNr[i - 2] = 0;
      p_sendSeqNr[i - 4] = -1;
    }
    ++v10;
    p_sendSeqNr += 7;
  }
  while ( v10 < 8 );
  if ( g_pNetworkSystem->IsMultiplayer(this: g_pNetworkSystem) )
    this->m_MaxReliablePayloadSize = net_blocksize.m_pParent->m_Value.m_nValue;
  else
    this->m_MaxReliablePayloadSize = 96000;
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 56);
  this->m_MessageHandler->ConnectionStart(this: this->m_MessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100028D0
// Name: public: virtual bool CNetChan::CanPacket(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::CanPacket(CNetChan *this)
{
  if ( net_chokeloopback.m_pParent->m_Value.m_nValue == 0 && netadr_s::IsLoopback(this: &this->remote_address) )
    return true;
  if ( g_pQueuedPackedSender->HasQueuedPackets(this: g_pQueuedPackedSender, a2: this) || this->m_nQueuedPackets > 0 )
    return false;
  return g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) > this->m_flClearTime;
}

//------------------------------------------------------------------------------
// Address: 0x10002940
// Name: private: bool CNetChan::ReadSubChannelData(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ReadSubChannelData(CNetChan *this, bf_read *buf, int stream)
{
  CNetChan::DataFragments_t *v3; // edi
  unsigned int m_nInBufWord; // ecx
  int v5; // eax
  bool v6; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  bool v9; // al
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // ebp
  const unsigned int *v15; // eax
  const unsigned int *v16; // ecx
  const unsigned int *v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  const unsigned int *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ebp
  int v23; // ecx
  unsigned int v24; // edx
  int v25; // eax
  int v26; // ecx
  const unsigned int *v27; // ecx
  const unsigned int *v28; // edx
  unsigned int v29; // edx
  const unsigned int *v30; // edi
  unsigned int v31; // eax
  int v32; // edx
  const unsigned int *v33; // ecx
  unsigned int v34; // edi
  unsigned int v35; // ebx
  char *filename; // ebp
  unsigned int v37; // eax
  int v38; // edx
  const unsigned int *v39; // eax
  const unsigned int *v40; // ecx
  int m_nBitsAvail; // ecx
  unsigned int v42; // eax
  int v43; // edi
  int v44; // ecx
  CNetChan::DataFragments_t *v45; // ebp
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // edi
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // ebp
  int v54; // edi
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // edi
  int v58; // ecx
  const unsigned int *v59; // eax
  const unsigned int *v60; // ecx
  const unsigned int *v61; // edx
  unsigned int v62; // edi
  int v63; // eax
  const unsigned int *v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // ebp
  int v67; // edi
  int v68; // edx
  const unsigned int *v69; // eax
  const unsigned int *v70; // ecx
  int v71; // ecx
  unsigned int v72; // eax
  int v73; // ecx
  const unsigned int *v74; // ecx
  const unsigned int *v75; // edx
  const unsigned int *v76; // edx
  unsigned int v77; // edi
  int v78; // eax
  const unsigned int *v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // ebx
  unsigned int v82; // edx
  unsigned int v83; // eax
  int v84; // ecx
  const unsigned int *v85; // eax
  const unsigned int *v86; // edx
  unsigned int v87; // eax
  int v88; // edx
  const unsigned int *v89; // eax
  const unsigned int *v90; // ecx
  int v91; // ecx
  unsigned int v92; // eax
  int v93; // edi
  int v94; // ecx
  const unsigned int *v95; // eax
  const unsigned int *v96; // ecx
  CNetChan::DataFragments_t *v97; // edx
  const unsigned int *v98; // edx
  unsigned int v99; // edi
  int v100; // eax
  const unsigned int *v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // ebp
  int v104; // ecx
  unsigned int v105; // eax
  int v106; // edi
  int v107; // ecx
  const unsigned int *v108; // eax
  const unsigned int *v109; // ecx
  const unsigned int *v110; // edx
  unsigned int v111; // edi
  int v112; // eax
  const unsigned int *v113; // ecx
  unsigned int v114; // edx
  unsigned int v115; // ebp
  unsigned int bytes; // eax
  unsigned int v117; // eax
  CNetChan::DataFragments_t *length; // [esp+10h] [ebp-14h]
  int numFragments; // [esp+14h] [ebp-10h]
  int startFragment; // [esp+18h] [ebp-Ch]
  unsigned int offset; // [esp+1Ch] [ebp-8h]
  int v123; // [esp+20h] [ebp-4h]
  bool bSingleBlock; // [esp+2Ch] [ebp+8h]

  v3 = &this->m_ReceiveList[stream];
  m_nInBufWord = buf->m_nInBufWord;
  v5 = m_nInBufWord & 1;
  v6 = buf->m_nBitsAvail-- == 1;
  length = v3;
  offset = 0;
  startFragment = 0;
  v123 = 0;
  numFragments = 0;
  if ( v6 )
  {
    m_pDataIn = buf->m_pDataIn;
    m_pBufferEnd = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = m_nInBufWord >> 1;
  }
  v9 = v5 == 0;
  bSingleBlock = v9;
  if ( v9 )
  {
LABEL_48:
    filename = v3->filename;
    v3->filename[0] = 0;
    v3->isCompressed = false;
    v3->isReplayDemo = false;
    v3->transferID = 0;
    v6 = !v9;
    v37 = buf->m_nInBufWord;
    if ( !v6 )
    {
      v38 = v37 & 1;
      v6 = buf->m_nBitsAvail-- == 1;
      if ( v6 )
      {
        v39 = buf->m_pDataIn;
        v40 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v39 == v40 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v39 + 1;
        }
        else if ( v39 <= v40 )
        {
          buf->m_nInBufWord = *v39;
          buf->m_pDataIn = v39 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v37 >> 1;
      }
      if ( v38 == 0 )
      {
        v45 = length;
        v3->isCompressed = false;
        goto LABEL_76;
      }
      v3->isCompressed = true;
      m_nBitsAvail = buf->m_nBitsAvail;
      if ( m_nBitsAvail >= 26 )
      {
        v42 = buf->m_nInBufWord;
        v43 = v42 & 0x3FFFFFF;
        v44 = m_nBitsAvail - 26;
        buf->m_nBitsAvail = v44;
        if ( v44 != 0 )
        {
          v45 = length;
          buf->m_nInBufWord = v42 >> 26;
          length->nUncompressedSize = v43;
        }
        else
        {
          v46 = buf->m_pDataIn;
          v47 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v46 == v47 )
          {
            v45 = length;
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v46 + 1;
            length->nUncompressedSize = v43;
          }
          else
          {
            v45 = length;
            if ( v46 <= v47 )
            {
              buf->m_nInBufWord = *v46;
              buf->m_pDataIn = v46 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            length->nUncompressedSize = v43;
          }
        }
LABEL_76:
        v55 = buf->m_nBitsAvail;
        if ( v55 >= 17 )
        {
          v56 = buf->m_nInBufWord;
          v57 = v56 & 0x1FFFF;
          v58 = v55 - 17;
          buf->m_nBitsAvail = v58;
          if ( v58 != 0 )
          {
            buf->m_nInBufWord = v56 >> 17;
            v45->bytes = v57;
          }
          else
          {
            v59 = buf->m_pDataIn;
            v60 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v59 == v60 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v59 + 1;
              v45->bytes = v57;
            }
            else
            {
              if ( v59 <= v60 )
              {
                buf->m_nInBufWord = *v59;
                buf->m_pDataIn = v59 + 1;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
              v45->bytes = v57;
            }
          }
          goto LABEL_174;
        }
        v61 = buf->m_pBufferEnd;
        v62 = buf->m_nInBufWord;
        v63 = 17 - v55;
        v64 = buf->m_pDataIn;
        if ( v64 == v61 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        else
        {
          if ( v64 > v61 )
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            goto LABEL_91;
          }
          buf->m_nInBufWord = *v64;
        }
        buf->m_pDataIn = v64 + 1;
LABEL_91:
        if ( buf->m_bOverflow )
        {
          v45->bytes = 0;
        }
        else
        {
          v65 = buf->m_nInBufWord;
          v66 = (v65 & CBitBuffer::s_nMaskTable[v63]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v63;
          v67 = v66 | v62;
          v45 = length;
          buf->m_nInBufWord = v65 >> v63;
          length->bytes = v67;
        }
        goto LABEL_174;
      }
      v48 = buf->m_pBufferEnd;
      v49 = buf->m_nInBufWord;
      v50 = 26 - m_nBitsAvail;
      v51 = buf->m_pDataIn;
      if ( v51 == v48 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v51 > v48 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_72;
        }
        buf->m_nInBufWord = *v51;
      }
      buf->m_pDataIn = v51 + 1;
LABEL_72:
      if ( buf->m_bOverflow )
      {
        v45 = length;
        length->nUncompressedSize = 0;
      }
      else
      {
        v52 = buf->m_nInBufWord;
        v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v50;
        v54 = v53 | v49;
        v45 = length;
        buf->m_nInBufWord = v52 >> v50;
        length->nUncompressedSize = v54;
      }
      goto LABEL_76;
    }
    v68 = v37 & 1;
    v6 = buf->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v69 = buf->m_pDataIn;
      v70 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v69 == v70 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v69 + 1;
      }
      else if ( v69 <= v70 )
      {
        buf->m_nInBufWord = *v69;
        buf->m_pDataIn = v69 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v37 >> 1;
    }
    if ( v68 == 0 )
    {
LABEL_129:
      v87 = buf->m_nInBufWord;
      v88 = v87 & 1;
      v6 = buf->m_nBitsAvail-- == 1;
      if ( v6 )
      {
        v89 = buf->m_pDataIn;
        v90 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v89 == v90 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v89 + 1;
        }
        else if ( v89 <= v90 )
        {
          buf->m_nInBufWord = *v89;
          buf->m_pDataIn = v89 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v87 >> 1;
      }
      if ( v88 == 0 )
      {
        v3->isCompressed = false;
        goto LABEL_156;
      }
      v3->isCompressed = true;
      v91 = buf->m_nBitsAvail;
      if ( v91 >= 26 )
      {
        v92 = buf->m_nInBufWord;
        v93 = v92 & 0x3FFFFFF;
        v94 = v91 - 26;
        buf->m_nBitsAvail = v94;
        if ( v94 != 0 )
        {
          buf->m_nInBufWord = v92 >> 26;
          length->nUncompressedSize = v93;
        }
        else
        {
          v95 = buf->m_pDataIn;
          v96 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v95 == v96 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v95 + 1;
            length->nUncompressedSize = v93;
          }
          else
          {
            if ( v95 <= v96 )
            {
              buf->m_nInBufWord = *v95;
              v97 = length;
              buf->m_pDataIn = v95 + 1;
            }
            else
            {
              v97 = length;
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            v97->nUncompressedSize = v93;
          }
        }
LABEL_156:
        v104 = buf->m_nBitsAvail;
        if ( v104 >= 26 )
        {
          v105 = buf->m_nInBufWord;
          v106 = v105 & 0x3FFFFFF;
          v107 = v104 - 26;
          buf->m_nBitsAvail = v107;
          if ( v107 != 0 )
          {
            buf->m_nInBufWord = v105 >> 26;
          }
          else
          {
            v108 = buf->m_pDataIn;
            v109 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v108 == v109 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v108 + 1;
            }
            else if ( v108 <= v109 )
            {
              buf->m_nInBufWord = *v108;
              buf->m_pDataIn = v108 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
          }
LABEL_173:
          length->bytes = v106;
          v45 = length;
LABEL_174:
          if ( v45->buffer != nullptr )
          {
            free(pMem: v45->buffer);
            _ConDMsg(a1: "Fragment transmission aborted at %i/%i.\n", v45->ackedFragments, v45->numFragments);
          }
          bytes = v45->bytes;
          v45->bits = 8 * bytes;
          v45->buffer = (char *)operator new(nSize: 4 * ((bytes + 3) >> 2));
          v117 = (v45->bytes + 255) >> 8;
          v45->numFragments = v117;
          v45->ackedFragments = 0;
          v45->file = nullptr;
          if ( bSingleBlock )
          {
            startFragment = v117;
            numFragments = v117 << 8;
          }
          goto LABEL_178;
        }
        v110 = buf->m_pBufferEnd;
        v111 = buf->m_nInBufWord;
        v112 = 26 - v104;
        v113 = buf->m_pDataIn;
        if ( v113 == v110 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        else
        {
          if ( v113 > v110 )
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            goto LABEL_170;
          }
          buf->m_nInBufWord = *v113;
        }
        buf->m_pDataIn = v113 + 1;
LABEL_170:
        if ( buf->m_bOverflow )
        {
          v106 = 0;
        }
        else
        {
          v114 = buf->m_nInBufWord;
          v115 = (v114 & CBitBuffer::s_nMaskTable[v112]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v112;
          v106 = v115 | v111;
          buf->m_nInBufWord = v114 >> v112;
        }
        goto LABEL_173;
      }
      v98 = buf->m_pBufferEnd;
      v99 = buf->m_nInBufWord;
      v100 = 26 - v91;
      v101 = buf->m_pDataIn;
      if ( v101 == v98 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v101 > v98 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_152;
        }
        buf->m_nInBufWord = *v101;
      }
      buf->m_pDataIn = v101 + 1;
LABEL_152:
      if ( buf->m_bOverflow )
      {
        length->nUncompressedSize = 0;
      }
      else
      {
        v102 = buf->m_nInBufWord;
        v103 = (v102 & CBitBuffer::s_nMaskTable[v100]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v100;
        buf->m_nInBufWord = v102 >> v100;
        length->nUncompressedSize = v103 | v99;
      }
      goto LABEL_156;
    }
    v71 = buf->m_nBitsAvail;
    if ( v71 >= 32 )
    {
      v72 = buf->m_nInBufWord;
      v73 = v71 - 32;
      buf->m_nBitsAvail = v73;
      if ( v73 != 0 )
      {
        buf->m_nInBufWord = 0;
      }
      else
      {
        v74 = buf->m_pDataIn;
        v75 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v74 == v75 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v74 + 1;
        }
        else if ( v74 <= v75 )
        {
          buf->m_nInBufWord = *v74;
          buf->m_pDataIn = v74 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      goto LABEL_120;
    }
    v76 = buf->m_pBufferEnd;
    v77 = buf->m_nInBufWord;
    v78 = 32 - v71;
    v79 = buf->m_pDataIn;
    if ( v79 == v76 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v79 > v76 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_116:
        if ( buf->m_bOverflow )
        {
          v72 = 0;
        }
        else
        {
          v80 = buf->m_nInBufWord;
          v81 = (v80 & CBitBuffer::s_nMaskTable[v78]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v78;
          v82 = v80 >> v78;
          v72 = v81 | v77;
          buf->m_nInBufWord = v82;
        }
        v3 = length;
LABEL_120:
        v3->transferID = v72;
        CBitRead::ReadString(this: buf, pStr: filename, maxLen: 260, bLine: false, pOutNumChars: nullptr);
        v83 = buf->m_nInBufWord;
        v84 = v83 & 1;
        v6 = buf->m_nBitsAvail-- == 1;
        if ( v6 )
        {
          v85 = buf->m_pDataIn;
          v86 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v85 == v86 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v85 + 1;
          }
          else if ( v85 <= v86 )
          {
            buf->m_nInBufWord = *v85;
            buf->m_pDataIn = v85 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
        }
        else
        {
          buf->m_nInBufWord = v83 >> 1;
        }
        if ( v84 != 0 )
          v3->isReplayDemo = true;
        goto LABEL_129;
      }
      buf->m_nInBufWord = *v79;
    }
    buf->m_pDataIn = v79 + 1;
    goto LABEL_116;
  }
  v10 = buf->m_nBitsAvail;
  if ( v10 >= 18 )
  {
    v11 = buf->m_nInBufWord;
    v12 = v11 & 0x3FFFF;
    v13 = v10 - 18;
    buf->m_nBitsAvail = v13;
    if ( v13 != 0 )
    {
      buf->m_nInBufWord = v11 >> 18;
      v14 = v11 & 0x3FFFF;
    }
    else
    {
      v15 = buf->m_pDataIn;
      v16 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v15 == v16 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v15 + 1;
        v14 = v12;
      }
      else
      {
        if ( v15 <= v16 )
        {
          buf->m_nInBufWord = *v15;
          buf->m_pDataIn = v15 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        v14 = v12;
      }
    }
    goto LABEL_28;
  }
  v17 = buf->m_pBufferEnd;
  v18 = buf->m_nInBufWord;
  v19 = 18 - v10;
  v20 = buf->m_pDataIn;
  if ( v20 == v17 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_23:
    buf->m_pDataIn = v20 + 1;
    goto LABEL_24;
  }
  if ( v20 <= v17 )
  {
    buf->m_nInBufWord = *v20;
    goto LABEL_23;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_24:
  if ( buf->m_bOverflow )
  {
    v14 = 0;
  }
  else
  {
    v21 = buf->m_nInBufWord;
    v22 = (v21 & CBitBuffer::s_nMaskTable[v19]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v19;
    v14 = v22 | v18;
    buf->m_nInBufWord = v21 >> v19;
  }
  v3 = length;
LABEL_28:
  v23 = buf->m_nBitsAvail;
  offset = v14;
  if ( v23 >= 3 )
  {
    v24 = buf->m_nInBufWord;
    v25 = v24 & 7;
    v26 = v23 - 3;
    buf->m_nBitsAvail = v26;
    if ( v26 != 0 )
    {
      buf->m_nInBufWord = v24 >> 3;
    }
    else
    {
      v27 = buf->m_pDataIn;
      v28 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v27 == v28 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v27 + 1;
      }
      else if ( v27 <= v28 )
      {
        v29 = *v27;
        buf->m_pDataIn = v27 + 1;
        buf->m_nInBufWord = v29;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    goto LABEL_46;
  }
  v30 = buf->m_pBufferEnd;
  v31 = buf->m_nInBufWord;
  v32 = 3 - v23;
  v33 = buf->m_pDataIn;
  if ( v33 == v30 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_41:
    buf->m_pDataIn = v33 + 1;
    goto LABEL_42;
  }
  if ( v33 <= v30 )
  {
    buf->m_nInBufWord = *v33;
    goto LABEL_41;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_42:
  if ( buf->m_bOverflow )
  {
    v25 = 0;
  }
  else
  {
    v34 = buf->m_nInBufWord;
    v35 = (v34 & CBitBuffer::s_nMaskTable[v32]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v32;
    v25 = v35 | v31;
    buf->m_nInBufWord = v34 >> v32;
  }
  v3 = length;
LABEL_46:
  startFragment = v25;
  v123 = v14 << 8;
  numFragments = v25 << 8;
  if ( v14 << 8 == 0 )
  {
    v9 = false;
    goto LABEL_48;
  }
  if ( v3->buffer == nullptr )
    return 0;
LABEL_178:
  if ( offset + startFragment == length->numFragments && (unsigned __int8)length->bytes != 0 )
    numFragments -= 256 - (unsigned __int8)length->bytes;
  CBitRead::ReadBytes(this: buf, pOut: &length->buffer[v123], nBytes: numFragments);
  length->ackedFragments += startFragment;
  if ( net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Received fragments: start %i, num %i\n", offset, startFragment);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003340
// Name: private: bool CNetChan::ProcessControlMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessControlMessage(CNetChan *this, int cmd, bf_read *buf)
{
  const unsigned int *m_pData; // eax
  CNetChan *v4; // ebx
  int v5; // ebp
  int v6; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v10; // ecx
  int v11; // ebp
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v14; // edx
  unsigned int v15; // edi
  int v16; // eax
  const unsigned int *v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // ebp
  unsigned int v20; // eax
  int v21; // ecx
  bool v22; // zf
  const unsigned int *v23; // eax
  const unsigned int *v24; // edx
  unsigned int v25; // eax
  int v26; // ecx
  const unsigned int *v27; // eax
  const unsigned int *v28; // edx
  int v29; // ecx
  unsigned int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // ecx
  const unsigned int *v37; // edx
  unsigned int v38; // edi
  int v39; // eax
  const unsigned int *v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ebx
  int v43; // edi
  unsigned int v44; // edx
  bool v45; // bl
  const char *v46; // eax
  int m_nDataBits; // [esp+10h] [ebp-40Ch]
  char string[1028]; // [esp+18h] [ebp-404h] BYREF

  m_pData = buf->m_pData;
  v4 = this;
  if ( m_pData != nullptr )
  {
    v6 = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( v6 >= buf->m_nDataBits )
    {
      m_nDataBits = buf->m_nDataBits;
      v5 = m_nDataBits;
    }
    else
    {
      m_nDataBits = v6;
      v5 = v6;
    }
  }
  else
  {
    v5 = 0;
    m_nDataBits = 0;
  }
  switch ( cmd )
  {
    case 0:
      CNetchanParanoidMode::AddControlMessage(
        this: &g_NetParanoid,
        m_nType: 0,
        nStartBit: v5,
        name: "net_NOP",
        desc: str);
      return 1;
    case 1:
      CBitRead::ReadString(this: buf, pStr: &string[4], maxLen: 1024, bLine: false, pOutNumChars: nullptr);
      CNetchanParanoidMode::AddControlMessage(
        this: &g_NetParanoid,
        m_nType: 1,
        nStartBit: v5,
        name: "net_Disconnect",
        desc: &string[4]);
      v4->m_MessageHandler->ConnectionClosing(this: v4->m_MessageHandler, a2: &string[4]);
      return 0;
    case 2:
      m_nBitsAvail = buf->m_nBitsAvail;
      if ( m_nBitsAvail >= 32 )
      {
        m_nInBufWord = buf->m_nInBufWord;
        v10 = m_nBitsAvail - 32;
        buf->m_nBitsAvail = v10;
        if ( v10 != 0 )
        {
          buf->m_nInBufWord = 0;
          v11 = m_nInBufWord;
        }
        else
        {
          m_pDataIn = buf->m_pDataIn;
          m_pBufferEnd = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = m_pDataIn + 1;
            v11 = m_nInBufWord;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              buf->m_nInBufWord = *m_pDataIn;
              buf->m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            v11 = m_nInBufWord;
          }
        }
LABEL_27:
        CBitRead::ReadString(this: buf, pStr: &string[4], maxLen: 1024, bLine: false, pOutNumChars: nullptr);
        v20 = buf->m_nInBufWord;
        v21 = v20 & 1;
        v22 = buf->m_nBitsAvail-- == 1;
        if ( v22 )
        {
          v23 = buf->m_pDataIn;
          v24 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v23 == v24 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v23 + 1;
          }
          else if ( v23 <= v24 )
          {
            buf->m_nInBufWord = *v23;
            buf->m_pDataIn = v23 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
        }
        else
        {
          buf->m_nInBufWord = v20 >> 1;
        }
        string[0] = v21 != 0;
        v25 = buf->m_nInBufWord;
        v26 = v25 & 1;
        v22 = buf->m_nBitsAvail-- == 1;
        if ( v22 )
        {
          v27 = buf->m_pDataIn;
          v28 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v27 == v28 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v27 + 1;
          }
          else if ( v27 <= v28 )
          {
            buf->m_nInBufWord = *v27;
            buf->m_pDataIn = v27 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
        }
        else
        {
          buf->m_nInBufWord = v25 >> 1;
        }
        if ( v26 != 0 && g_pNetworkSystem->IsSafeFileToDownload(this: g_pNetworkSystem, a2: &string[4]) )
          ((void (__stdcall *)(char *, int, _DWORD))this->m_MessageHandler->FileRequested)(
            a1: &string[4],
            a2: v11,
            a3: *(_DWORD *)string);
        else
          ((void (__stdcall *)(char *, int, _DWORD))this->m_MessageHandler->FileDenied)(
            a1: &string[4],
            a2: v11,
            a3: *(_DWORD *)string);
        CNetchanParanoidMode::AddControlMessage(
          this: &g_NetParanoid,
          m_nType: 2,
          nStartBit: m_nDataBits,
          name: "net_File",
          desc: &string[4]);
        return 1;
      }
      v14 = buf->m_pBufferEnd;
      v15 = buf->m_nInBufWord;
      v16 = 32 - m_nBitsAvail;
      v17 = buf->m_pDataIn;
      if ( v17 == v14 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v17 > v14 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_24;
        }
        buf->m_nInBufWord = *v17;
      }
      buf->m_pDataIn = v17 + 1;
LABEL_24:
      if ( buf->m_bOverflow )
      {
        v11 = 0;
      }
      else
      {
        v18 = buf->m_nInBufWord;
        v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v16;
        v11 = v19 | v15;
        buf->m_nInBufWord = v18 >> v16;
      }
      goto LABEL_27;
    case 3:
      v29 = buf->m_nBitsAvail;
      if ( v29 < 2 )
      {
        v37 = buf->m_pBufferEnd;
        v38 = buf->m_nInBufWord;
        v39 = 2 - v29;
        v40 = buf->m_pDataIn;
        if ( v40 == v37 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_bOverflow = true;
          v4 = this;
          buf->m_nInBufWord = 0;
        }
        else
        {
          if ( v40 > v37 )
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            goto LABEL_61;
          }
          buf->m_nInBufWord = *v40;
        }
        buf->m_pDataIn = v40 + 1;
LABEL_61:
        if ( buf->m_bOverflow )
        {
          v33 = 0;
        }
        else
        {
          v41 = buf->m_nInBufWord;
          v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v39;
          v43 = v42 | v38;
          v4 = this;
          v44 = v41 >> v39;
          v33 = v43;
          buf->m_nInBufWord = v44;
        }
        goto LABEL_64;
      }
      v30 = buf->m_nInBufWord;
      v31 = v30 & 3;
      v32 = v29 - 2;
      buf->m_nBitsAvail = v32;
      if ( v32 != 0 )
      {
        buf->m_nInBufWord = v30 >> 2;
        v33 = v30 & 3;
      }
      else
      {
        v34 = buf->m_pDataIn;
        v35 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v34 == v35 )
        {
          buf->m_pDataIn = v34 + 1;
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          v33 = v31;
        }
        else
        {
          if ( v34 <= v35 )
          {
            v36 = *v34;
            buf->m_pDataIn = v34 + 1;
            buf->m_nInBufWord = v36;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          v33 = v31;
        }
      }
LABEL_64:
      v45 = v4->m_MessageHandler->ChangeSplitscreenUser(this: v4->m_MessageHandler, a2: v33);
      CNetchanParanoidMode::AddControlMessage(
        this: &g_NetParanoid,
        m_nType: 3,
        nStartBit: v5,
        name: "net_SplitScreenUser",
        desc: str);
      return v45;
    default:
      v46 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      _Msg(a1: "CNetChan: received bad control cmd %i from %s.\n", cmd, v46);
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v4, pchReason: "bad control cmd");
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037A0
// Name: public: virtual bool CNetChan::HasPendingReliableData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetChan::HasPendingReliableData(CNetChan *this)
{
  return this->m_StreamReliable.m_iCurBit > 0 || this->m_WaitingList[0].m_Size > 0 || this->m_WaitingList[1].m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100037D0
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax
  bool v3; // zf

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    v3 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = num;
    if ( v3 )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003880
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003920
// Name: private: void CNetChan::CompressFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetChan::CompressFragments(CNetChan *this@<ecx>, void *file@<edi>)
{
  CNetChan *v2; // ebp
  bool v3; // zf
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *m_WaitingList; // eax
  CNetChan::DataFragments_t **m_pMemory; // eax
  CNetChan::DataFragments_t *v6; // esi
  void *v7; // ebx
  const char *v8; // edi
  const char *v9; // eax
  int v10; // eax
  unsigned int bytes; // edx
  void *v12; // edi
  int v13; // ebx
  int v14; // ebx
  void *v15; // eax
  void *v16; // eax
  CNetChan *v17; // ebx
  void *v18; // ebx
  unsigned int v19; // eax
  unsigned int v20; // [esp+40h] [ebp-134h]
  unsigned int v21; // [esp+40h] [ebp-134h]
  int count; // [esp+54h] [ebp-120h] BYREF
  int v24; // [esp+58h] [ebp-11Ch] BYREF
  CNetChan *v25; // [esp+5Ch] [ebp-118h]
  int compressedFileSize; // [esp+60h] [ebp-114h]
  int v27; // [esp+64h] [ebp-110h]
  char *compressed; // [esp+68h] [ebp-10Ch]
  char compressedfilename[260]; // [esp+6Ch] [ebp-108h] BYREF

  v2 = this;
  v3 = !this->m_bUseCompression;
  v25 = this;
  if ( !v3 )
  {
    m_WaitingList = this->m_WaitingList;
    compressed = (char *)this->m_WaitingList;
    compressedFileSize = 2;
    do
    {
      if ( m_WaitingList->m_Size != 0 )
      {
        m_pMemory = m_WaitingList->m_Memory.m_pMemory;
        v6 = *m_pMemory;
        if ( !(*m_pMemory)->isCompressed && v6->bytes >= 0x200 && v6->ackedFragments <= 0 && v6->pendingFragments <= 0 )
        {
          if ( v6->buffer != nullptr )
          {
            count = v6->bytes;
            v7 = operator new(nSize: count);
            if ( g_pNetworkSystem->BufferToBufferCompress(
                   this: g_pNetworkSystem,
                   a2: (char *)v7,
                   a3: (unsigned int *)&count,
                   a4: v6->buffer,
                   a5: v6->bytes) )
            {
              v8 = (const char *)v2->GetName(this: v2);
              v9 = v2->GetAddress(this: v2);
              DevMsg(a1: "Compressing fragments for %s(%s) (%d -> %d bytes)\n", v8, v9, v6->bytes, count);
              _V_memcpy(dest: v6->buffer, src: v7, count);
              v10 = count;
              bytes = v6->bytes;
              v6->bytes = count;
              v6->nUncompressedSize = bytes;
              v6->numFragments = (unsigned int)(v10 + 255) >> 8;
              v6->isCompressed = true;
            }
            free(pMem: v7);
          }
          else
          {
            v27 = -1;
            v12 = nullptr;
            V_snprintf(pDest: &compressedfilename[4], maxLen: 260, pFormat: "%s.ztmp", v6->filename);
            v13 = ((int (__thiscall *)(IBaseFileSystem *, char *, _DWORD, void *))g_pFileSystem->GetFileTime)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: &compressedfilename[4],
                    a3: 0,
                    a4: file);
            if ( v13 >= g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: v6->filename, a3: nullptr)
              && (v12 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: &compressedfilename[8],
                          a3: "rb",
                          a4: 0)) != nullptr )
            {
              file = v12;
              v14 = ((int (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Size_2)(a1: &g_pFileSystem->IBaseFileSystem);
            }
            else
            {
              v15 = operator new(nSize: v6->bytes);
              v20 = v6->bytes;
              v24 = (int)v15;
              v16 = operator new(nSize: v20);
              v17 = (CNetChan *)v6->bytes;
              file = v6->file;
              *(_DWORD *)&compressedfilename[4] = v16;
              v25 = v17;
              ((void (__thiscall *)(IBaseFileSystem *, int, CNetChan *))g_pFileSystem->Read)(
                a1: &g_pFileSystem->IBaseFileSystem,
                a2: v24,
                a3: v17);
              v21 = (unsigned int)v17;
              v18 = *(void **)compressedfilename;
              if ( g_pNetworkSystem->BufferToBufferCompress(
                     this: g_pNetworkSystem,
                     a2: *(char **)compressedfilename,
                     a3: (unsigned int *)&v24,
                     a4: (char *)count,
                     a5: v21) )
              {
                v12 = g_pFileSystem->Open(
                        this: &g_pFileSystem->IBaseFileSystem,
                        a2: &compressedfilename[4],
                        a3: "wb",
                        a4: 0);
                if ( v12 != nullptr )
                {
                  DevMsg(a1: "Creating compressed version of file %s (%d -> %d)\n", v6->filename, v6->bytes, v24);
                  g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v18, a3: v24, a4: v12);
                  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v12);
                  v12 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: &compressedfilename[4],
                          a3: "rb",
                          a4: 0);
                  if ( v12 != nullptr )
                    v27 = v24;
                }
              }
              free(pMem: (void *)count);
              free(pMem: v18);
              v14 = v27;
            }
            if ( v14 > 0 )
            {
              g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6->file);
              v19 = v6->bytes;
              v6->bytes = v14;
              v6->file = v12;
              v6->nUncompressedSize = v19;
              v6->numFragments = (unsigned int)(v14 + 255) >> 8;
              v6->isCompressed = true;
            }
            v2 = v25;
          }
        }
      }
      m_WaitingList = (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)(compressed + 20);
      v3 = compressedFileSize-- == 1;
      compressed += 20;
    }
    while ( !v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003C70
// Name: public: virtual void CNetChan::SetMaxBufferSize(enum ENetChannelBufType,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxBufferSize(CNetChan *this, ENetChannelBufType eBufType, int nBytes)
{
  int v3; // ebp
  bf_write *p_m_StreamVoice; // eax
  CUtlMemory<unsigned char,int> *p_m_UnreliableDataBuffer; // esi
  int v6; // ebx
  unsigned __int8 copybuf[4000]; // [esp+8h] [ebp-FA4h] BYREF

  v3 = nBytes;
  if ( nBytes <= 96000 )
  {
    if ( nBytes < 4000 )
      v3 = 4000;
  }
  else
  {
    v3 = 96000;
  }
  if ( eBufType != BUF_RELIABLE )
  {
    if ( eBufType == BUF_UNRELIABLE )
    {
      *(_DWORD *)copybuf = &this->m_StreamUnreliable;
      p_m_UnreliableDataBuffer = &this->m_UnreliableDataBuffer;
      goto LABEL_12;
    }
    if ( eBufType != BUF_VOICE )
      return;
    p_m_StreamVoice = &this->m_StreamVoice;
    p_m_UnreliableDataBuffer = &this->m_VoiceDataBuffer;
  }
  else
  {
    p_m_StreamVoice = &this->m_StreamReliable;
    p_m_UnreliableDataBuffer = &this->m_ReliableDataBuffer;
  }
  *(_DWORD *)copybuf = p_m_StreamVoice;
LABEL_12:
  if ( p_m_UnreliableDataBuffer->m_nAllocationCount != v3 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)copybuf + 12);
    if ( (v6 + 7) >> 3 < v3 )
    {
      if ( v6 > 0 )
        _V_memcpy(dest: &copybuf[4], src: p_m_UnreliableDataBuffer->m_pMemory, count: (v6 + 7) >> 3);
      if ( p_m_UnreliableDataBuffer->m_nGrowSize >= 0 )
      {
        if ( p_m_UnreliableDataBuffer->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_UnreliableDataBuffer->m_pMemory);
          p_m_UnreliableDataBuffer->m_pMemory = nullptr;
        }
        p_m_UnreliableDataBuffer->m_nAllocationCount = 0;
      }
      CUtlMemory<unsigned char,int>::EnsureCapacity(this: p_m_UnreliableDataBuffer, num: v3);
      if ( v6 > 0 )
        _V_memcpy(dest: p_m_UnreliableDataBuffer->m_pMemory, src: &copybuf[4], count: (v6 + 7) >> 3);
      bf_write::StartWriting(
        this: *(bf_write **)copybuf,
        pData: p_m_UnreliableDataBuffer->m_pMemory,
        nBytes: v3,
        iStartBit: v6,
        nBits: -1);
    }
    else
    {
      _Msg(a1: "CNetChan::SetMaxBufferSize: cant preserve exiting data %i>%i.\n", (v6 + 7) >> 3, v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D90
// Name: private: bool CNetChan::IsFileInWaitingList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::IsFileInWaitingList(CNetChan *this, const char *filename)
{
  int v2; // ebx
  int *i; // esi
  int v4; // edi

  if ( filename == nullptr || *filename == 0 )
    return 1;
  v2 = 0;
  for ( i = &this->m_WaitingList[0].m_Size; ; i += 5 )
  {
    v4 = 0;
    if ( *i > 0 )
      break;
LABEL_7:
    if ( ++v2 >= 2 )
      return 0;
  }
  while ( _V_strcmp(s1: (const char *)(*(_DWORD *)(*(i - 3) + 4 * v4) + 4), s2: filename) != 0 )
  {
    if ( ++v4 >= *i )
      goto LABEL_7;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: private: void CNetChan::UpdateSubChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateSubChannels(CNetChan *this)
{
  CNetChan *v1; // edx
  int v2; // eax
  int *i; // ecx
  CNetChan::SubChannel_t *v4; // ebp
  int v5; // edi
  char v6; // bl
  int j; // ecx
  CNetChan::DataFragments_t *v8; // edx
  int v9; // esi
  int numFragments; // eax
  int v11; // eax
  int v12; // eax
  int m_nOutReliableState; // ecx

  v1 = this;
  v2 = 0;
  for ( i = &this->m_SubChannels[0].state; *i != 0; i += 7 )
  {
    if ( ++v2 >= 8 )
      return;
  }
  v4 = &v1->m_SubChannels[v2];
  if ( v4 != nullptr )
  {
    v5 = v1->m_MaxReliablePayloadSize >> 8;
    v6 = 0;
    for ( j = 0; j < 2; ++j )
    {
      if ( v1->m_WaitingList[j].m_Size > 0 )
      {
        v8 = *v1->m_WaitingList[j].m_Memory.m_pMemory;
        v9 = v8->pendingFragments + v8->ackedFragments;
        numFragments = v8->numFragments;
        if ( v9 != numFragments )
        {
          v11 = numFragments - v9;
          if ( v5 < v11 )
            v11 = v5;
          if ( j == 1 && this->m_bFileBackgroundTranmission && v11 > 1 )
            v11 = 1;
          v4->startFraggment[j] = v9;
          v4->numFragments[j] = v11;
          v8->pendingFragments += v11;
          v5 -= v11;
          v6 = 1;
          if ( v5 <= 0 )
          {
            v1 = this;
            goto LABEL_21;
          }
        }
        v1 = this;
      }
    }
    if ( v6 == 0 )
      return;
LABEL_21:
    v12 = 1 << v4->index;
    m_nOutReliableState = v1->m_nOutReliableState;
    if ( (m_nOutReliableState & v12) != 0 )
      v1->m_nOutReliableState = m_nOutReliableState & ~v12;
    else
      v1->m_nOutReliableState = v12 | m_nOutReliableState;
    v4->state = 1;
    v4->sendSeqNr = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003F10
// Name: private: class INetMessage __near * CNetChan::FindMessage(int)
// Source: json
//------------------------------------------------------------------------------
INetMessage *__thiscall CNetChan::FindMessage(CNetChan *this, int type)
{
  int m_Size; // ebx
  int v4; // esi
  INetMessage *v5; // ecx

  m_Size = this->m_NetMessages.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_NetMessages.m_Memory.m_pMemory[v4];
    if ( v5->GetType(this: v5) == type )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return this->m_NetMessages.m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x10003F70
// Name: public: virtual bool CNetChan::GetStreamProgress(int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::GetStreamProgress(CNetChan *this, int flow, int *received, int *total)
{
  *total = 0;
  *received = 0;
  if ( flow == 1 )
  {
    if ( this->m_ReceiveList[0].buffer != nullptr )
    {
      *total += this->m_ReceiveList[0].numFragments << 8;
      *received += this->m_ReceiveList[0].ackedFragments << 8;
    }
    if ( this->m_ReceiveList[1].buffer != nullptr )
    {
      *total += this->m_ReceiveList[1].numFragments << 8;
      *received += this->m_ReceiveList[1].ackedFragments << 8;
    }
    return *total > 0;
  }
  else if ( flow != 0 )
  {
    return false;
  }
  else
  {
    if ( this->m_WaitingList[0].m_Size > 0 )
    {
      *total += (*this->m_WaitingList[0].m_Memory.m_pMemory)->numFragments << 8;
      *received += (*this->m_WaitingList[0].m_Memory.m_pMemory)->ackedFragments << 8;
    }
    if ( this->m_WaitingList[1].m_Size > 0 )
    {
      *total += (*this->m_WaitingList[1].m_Memory.m_pMemory)->numFragments << 8;
      *received += (*this->m_WaitingList[1].m_Memory.m_pMemory)->ackedFragments << 8;
    }
    return *total > 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A50
// Name: private: void CNetChan::RemoveHeadInWaitingList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RemoveHeadInWaitingList(CNetChan *this, CNetChan::DataFragments_t *nList)
{
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *v2; // edi
  void **v3; // esi
  bool v4; // zf

  v2 = &this->m_WaitingList[(_DWORD)nList];
  v3 = (void **)*v2->m_Memory.m_pMemory;
  v4 = v3[66] == nullptr;
  nList = (CNetChan::DataFragments_t *)v3;
  if ( !v4 )
    free(pMem: v3[66]);
  if ( *v3 != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: *v3);
    *v3 = nullptr;
  }
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(this: v2, src: &nList);
  free(pMem: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10004AC0
// Name: private: bool CNetChan::SendSubChannelData(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::SendSubChannelData(CNetChan *this, bf_write *buf)
{
  signed int v3; // eax
  CNetChan::SubChannel_t *m_SubChannels; // ecx
  CNetChan::SubChannel_t *v5; // ebp
  int m_iCurBit; // ecx
  CNetChan::DataFragments_t *v9; // ebp
  int v10; // ecx
  int numFragments; // edx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  char *buffer; // eax
  unsigned int v18; // eax
  void *v19; // edi
  unsigned int offset; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *subChan; // [esp+18h] [ebp-10h]
  CNetChan::SubChannel_t *v23; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  unsigned int *bufa; // [esp+2Ch] [ebp+4h]

  CNetChan::CompressFragments(this, file: this);
  CNetChan::UpdateSubChannels(this);
  v3 = 0;
  m_SubChannels = this->m_SubChannels;
  do
  {
    v5 = m_SubChannels;
    v23 = m_SubChannels;
    if ( m_SubChannels->state == 1 )
      break;
    ++v3;
    ++m_SubChannels;
  }
  while ( v3 < 8 );
  if ( v3 == 8 )
    return 0;
  bf_write::WriteUBitLong(this: buf, curData: v3, numbits: 3, bCheckRange: true);
  bufa = (unsigned int *)v5->numFragments;
  subChan = this->m_WaitingList;
  for ( i = 2; i != 0; --i )
  {
    if ( *bufa == 0 )
    {
      m_iCurBit = buf->m_iCurBit;
      if ( m_iCurBit + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      goto LABEL_75;
    }
    v9 = *subChan->m_Memory.m_pMemory;
    v10 = buf->m_iCurBit;
    if ( v10 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        buf->m_pData[v10 >> 3] |= 1 << (v10 & 7);
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    v21 = *(bufa - 2) << 8;
    numFragments = v9->numFragments;
    offset = *bufa << 8;
    if ( *bufa + *(bufa - 2) == numFragments && (unsigned __int8)v9->bytes != 0 )
      offset = (*bufa << 8) - (256 - (unsigned __int8)v9->bytes);
    if ( *bufa != numFragments || v9->file != nullptr )
    {
      v14 = buf->m_iCurBit;
      if ( v14 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v14 >> 3] |= 1 << (v14 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: *(bufa - 2), numbits: 18, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: *bufa, numbits: 3, bCheckRange: true);
      if ( v21 != 0 )
        goto LABEL_67;
      v15 = buf->m_iCurBit;
      if ( v9->file == nullptr )
        goto LABEL_51;
      if ( v15 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v15 >> 3] |= 1 << (v15 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v9->transferID, numbits: 32, bCheckRange: true);
      bf_write::WriteString(this: buf, pStr: v9->filename);
      v15 = buf->m_iCurBit;
      if ( v9->isReplayDemo )
      {
        if ( v15 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
LABEL_56:
          v16 = buf->m_iCurBit;
          if ( v9->isCompressed )
          {
            if ( v16 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v16 >> 3] |= 1 << (v16 & 7);
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
            bf_write::WriteUBitLong(this: buf, curData: v9->nUncompressedSize, numbits: 26, bCheckRange: true);
          }
          else if ( v16 + 1 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              buf->m_pData[v16 >> 3] &= ~(1 << (v16 & 7));
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
          bf_write::WriteUBitLong(this: buf, curData: v9->bytes, numbits: 26, bCheckRange: true);
          goto LABEL_67;
        }
        if ( buf->m_bOverflow )
          goto LABEL_56;
        buf->m_pData[v15 >> 3] |= 1 << (v15 & 7);
      }
      else
      {
LABEL_51:
        if ( v15 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
          goto LABEL_56;
        }
        if ( buf->m_bOverflow )
          goto LABEL_56;
        buf->m_pData[v15 >> 3] &= ~(1 << (v15 & 7));
      }
      ++buf->m_iCurBit;
      goto LABEL_56;
    }
    v12 = buf->m_iCurBit;
    if ( v12 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        buf->m_pData[v12 >> 3] &= ~(1 << (v12 & 7));
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    v13 = buf->m_iCurBit;
    if ( v9->isCompressed )
    {
      if ( v13 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v13 >> 3] |= 1 << (v13 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v9->nUncompressedSize, numbits: 26, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: v9->bytes, numbits: 17, bCheckRange: true);
    }
    else if ( v13 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        buf->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
        ++buf->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buf, curData: v9->bytes, numbits: 17, bCheckRange: true);
    }
    else
    {
      buf->m_bOverflow = true;
      bf_write::WriteUBitLong(this: buf, curData: v9->bytes, numbits: 17, bCheckRange: true);
    }
LABEL_67:
    buffer = v9->buffer;
    if ( buffer != nullptr )
    {
      bf_write::WriteBytes(this: buf, pBuf: &buffer[v21], nBytes: offset);
    }
    else
    {
      v18 = offset;
      if ( offset <= 1 )
        v18 = 1;
      v19 = operator new(nSize: v18);
      g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v9->file, a3: v21, a4: FILESYSTEM_SEEK_HEAD);
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v19, a3: offset, a4: v9->file);
      bf_write::WriteBytes(this: buf, pBuf: v19, nBytes: offset);
      free(pMem: v19);
    }
    if ( net_showfragments.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Sending subchan %i: start %i, num %i\n", v23->index, *(bufa - 2), *bufa);
    v23->sendSeqNr = this->m_nOutSequenceNr;
    v23->state = 2;
LABEL_75:
    ++subChan;
    ++bufa;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004F20
// Name: private: bool CNetChan::_ProcessMessages(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::_ProcessMessages(CNetChan *this, bf_read *buf)
{
  CNetChan *v2; // ebp
  char *m_pszString; // ecx
  char *v4; // eax
  int m_nValue; // edx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  const unsigned int *v9; // edx
  const unsigned int *v10; // eax
  int v11; // edi
  int v12; // eax
  int m_nBitsAvail; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // ecx
  const unsigned int *v17; // eax
  const unsigned int *v18; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  const unsigned int *m_pDataIn; // ecx
  bool v22; // zf
  char v23; // al
  INetMessage *Message; // eax
  INetMessage *v26; // edi
  const char *v27; // ebx
  const unsigned int *v28; // eax
  CNetchanParanoidMode::MessageItem_t *v29; // ecx
  const unsigned int *v30; // eax
  CNetchanParanoidMode::MessageItem_t *v31; // ecx
  const unsigned int *v32; // eax
  void (__thiscall **p_UpdateMessageStats)(struct CNetChan *, int, int); // ebp
  int v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  bool v39; // al
  IDemoRecorderBase *m_DemoRecorder; // ecx
  const unsigned int *v41; // eax
  int v42; // edx
  unsigned int v43; // eax
  int v44; // edx
  int v45; // esi
  int v46; // eax
  const char *v47; // eax
  const char *v48; // eax
  const char *v49; // [esp-4h] [ebp-4Ch]
  const char *v50; // [esp-4h] [ebp-4Ch]
  const char *blockmsgname; // [esp+10h] [ebp-38h]
  char *s1; // [esp+14h] [ebp-34h]
  const char *msgname; // [esp+1Ch] [ebp-2Ch]
  bf_read democopy; // [esp+20h] [ebp-28h] BYREF
  const unsigned int *v56; // [esp+44h] [ebp-4h]
  bf_read *bufa; // [esp+4Ch] [ebp+4h]

  v2 = this;
  this->m_bStopProcessing = false;
  if ( (net_showmsg.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    if ( net_showmsg.m_pParent->m_Value.m_pszString != nullptr )
    {
      m_pszString = net_showmsg.m_pParent->m_Value.m_pszString;
      blockmsgname = m_pszString;
      goto LABEL_7;
    }
    m_pszString = (char *)str;
  }
  blockmsgname = m_pszString;
LABEL_7:
  if ( (net_blockmsg.m_nFlags & 0x1000) != 0 )
  {
    v4 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v4 = net_blockmsg.m_pParent->m_Value.m_pszString;
    if ( v4 == nullptr )
      v4 = (char *)str;
  }
  s1 = v4;
  if ( *m_pszString == 48 )
    blockmsgname = nullptr;
  if ( *v4 == 48 )
    s1 = nullptr;
  m_nValue = net_showpeaks.m_pParent->m_Value.m_nValue;
  if ( m_nValue > 0 )
  {
    m_pData = buf->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( m_nDataBits >= buf->m_nDataBits )
        m_nDataBits = buf->m_nDataBits;
    }
    else
    {
      m_nDataBits = 0;
    }
    if ( m_nValue < (buf->m_nDataBits - m_nDataBits) >> 3 )
      blockmsgname = "1";
  }
  v9 = buf->m_pData;
  *(CBitBuffer *)&democopy.m_bOverflow = buf->CBitBuffer;
  *(_QWORD *)&democopy.m_nBitsAvail = *(_QWORD *)&buf->m_nInBufWord;
  *(_QWORD *)&democopy.m_pBufferEnd = *(_QWORD *)&buf->m_pDataIn;
  v56 = v9;
  if ( v9 != nullptr )
  {
    msgname = (const char *)(32 * (buf->m_pDataIn - v9) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
    if ( (int)msgname >= buf->m_nDataBits )
      msgname = (const char *)buf->m_nDataBits;
  }
  else
  {
    msgname = nullptr;
  }
  if ( buf->m_bOverflow )
  {
LABEL_84:
    v2->m_MessageHandler->ConnectionCrashed(this: v2->m_MessageHandler, a2: "Buffer overflow in net message");
    return 0;
  }
  while ( 1 )
  {
    v10 = buf->m_pData;
    if ( v10 != nullptr )
    {
      v10 = (const unsigned int *)(32 * (buf->m_pDataIn - v10) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)v10 >= buf->m_nDataBits )
        v10 = (const unsigned int *)buf->m_nDataBits;
    }
    v11 = buf->m_nDataBits - (_DWORD)v10;
    if ( v11 < g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem) )
      break;
    v12 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
    m_nBitsAvail = buf->m_nBitsAvail;
    if ( m_nBitsAvail < v12 )
    {
      m_pBufferEnd = buf->m_pBufferEnd;
      m_nInBufWord = buf->m_nInBufWord;
      v12 -= m_nBitsAvail;
      m_pDataIn = buf->m_pDataIn;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = m_pDataIn + 1;
        buf->m_bOverflow = true;
        LOBYTE(v15) = 0;
        goto LABEL_47;
      }
      if ( m_pDataIn > m_pBufferEnd )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        LOBYTE(v15) = 0;
        goto LABEL_47;
      }
      v14 = *m_pDataIn;
      v22 = !buf->m_bOverflow;
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
      if ( !v22 )
      {
        LOBYTE(v15) = 0;
LABEL_47:
        v2->m_bProcessingMessages = true;
        v23 = CNetChan::ProcessControlMessage(this: v2, cmd: (unsigned __int8)v15, buf);
        v2->m_bProcessingMessages = false;
        if ( v23 == 0 )
        {
          if ( v2->m_bShouldDelete )
          {
            ((void (__thiscall *)(CNetChan *, int))v2->dtr_INetChannel)(a1: v2, a2: 1);
            return 0;
          }
          return 0;
        }
        goto LABEL_83;
      }
      v15 = ((v14 & CBitBuffer::s_nMaskTable[v12]) << buf->m_nBitsAvail) | m_nInBufWord;
      buf->m_nBitsAvail = 32 - v12;
LABEL_45:
      buf->m_nInBufWord = v14 >> v12;
      goto LABEL_46;
    }
    v14 = buf->m_nInBufWord;
    v15 = v14 & CBitBuffer::s_nMaskTable[v12];
    v16 = m_nBitsAvail - v12;
    buf->m_nBitsAvail = v16;
    if ( v16 != 0 )
      goto LABEL_45;
    v17 = buf->m_pDataIn;
    v18 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v17 + 1;
    }
    else if ( v17 <= v18 )
    {
      buf->m_nInBufWord = *v17;
      buf->m_pDataIn = v17 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
LABEL_46:
    if ( (unsigned __int8)v15 <= 3u )
      goto LABEL_47;
    Message = CNetChan::FindMessage(this: (CNetChan *)v2->m_pActiveChannel, type: (unsigned __int8)v15);
    v26 = Message;
    if ( Message == nullptr )
    {
      v48 = netadr_s::ToString(this: &v2->remote_address, baseOnly: false);
      _Msg(a1: "Netchannel: unknown net message (%i) from %s.\n", (unsigned __int8)v15, v48);
      v50 = "unknown message";
      goto LABEL_99;
    }
    v27 = Message->GetName(this: Message);
    v28 = buf->m_pData;
    if ( v28 != nullptr )
    {
      bufa = (bf_read *)(32 * (buf->m_pDataIn - v28) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)bufa >= buf->m_nDataBits )
        bufa = (bf_read *)buf->m_nDataBits;
    }
    else
    {
      bufa = nullptr;
    }
    if ( g_NetParanoid.m_bInitialized
      && net_paranoid.m_pParent->m_Value.m_nValue != 0
      && g_NetParanoid.m_nPacketMessageCount < 255 )
    {
      v29 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
      CNetchanParanoidMode::MessageItem_t::Init(this: v29, msg: v26, nStartBit: (int)bufa);
    }
    if ( !v26->ReadFromBuffer(this: v26, a2: buf) )
    {
      v47 = netadr_s::ToString(this: &v2->remote_address, baseOnly: false);
      _Msg(a1: "Netchannel: failed reading message %s from %s.\n", v27, v47);
      v50 = "failed reading message";
LABEL_99:
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v2, pchReason: v50);
      return 0;
    }
    v30 = buf->m_pData;
    if ( v30 != nullptr )
    {
      v30 = (const unsigned int *)(32 * (buf->m_pDataIn - v30) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)v30 >= buf->m_nDataBits )
        v30 = (const unsigned int *)buf->m_nDataBits;
    }
    if ( g_NetParanoid.m_bInitialized
      && net_paranoid.m_pParent->m_Value.m_nValue != 0
      && g_NetParanoid.m_nPacketMessageCount > 0 )
    {
      v31 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount - 1];
      if ( v31->m_pMsg == v26 )
        CNetchanParanoidMode::MessageItem_t::UpdateRaw(this: v31, msg: v26, nEndBit: (int)v30);
    }
    v32 = buf->m_pData;
    if ( v32 != nullptr )
    {
      v32 = (const unsigned int *)(32 * (buf->m_pDataIn - v32) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)v32 >= buf->m_nDataBits )
        v32 = (const unsigned int *)buf->m_nDataBits;
    }
    p_UpdateMessageStats = &this->UpdateMessageStats;
    v34 = ((int (__thiscall *)(INetMessage *, int))v26->GetGroup)(a1: v26, a2: (char *)v32 - (char *)bufa);
    ((void (__thiscall *)(CNetChan *, int))*p_UpdateMessageStats)(a1: this, a2: v34);
    if ( blockmsgname != nullptr )
    {
      if ( *blockmsgname == 49 || (v35 = v26->GetName(this: v26), _V_stricmp(s1: blockmsgname, s2: v35) == 0) )
      {
        v49 = v26->ToString(this: v26);
        v36 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        _Msg(a1: "Msg from %s: %s\n", v36, v49);
      }
    }
    if ( s1 != nullptr && (*s1 == 49 || (v37 = v26->GetName(this: v26), _V_stricmp(s1, s2: v37) == 0)) )
    {
      v38 = v26->ToString(this: v26);
      _Msg(a1: "Blocking message %s\n", v38);
    }
    else
    {
      this->m_bProcessingMessages = true;
      v39 = v26->Process(this: v26);
      v22 = !this->m_bShouldDelete;
      this->m_bProcessingMessages = false;
      if ( !v22 )
      {
        ((void (__thiscall *)(CNetChan *, int))this->dtr_INetChannel)(a1: this, a2: 1);
        return 0;
      }
      if ( this->m_bStopProcessing )
        return 0;
      if ( !v39 )
      {
        _ConDMsg(a1: "Netchannel: failed processing message %s.\n", v27);
        CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: this, pchReason: "failed processing");
        return 0;
      }
      if ( this->IsOverflowed(this) )
        return 0;
    }
LABEL_83:
    v2 = this;
    if ( buf->m_bOverflow )
      goto LABEL_84;
  }
  m_DemoRecorder = v2->m_DemoRecorder;
  if ( m_DemoRecorder != nullptr )
  {
    v41 = buf->m_pData;
    if ( v41 != nullptr )
    {
      v42 = (char *)buf->m_pDataIn - (char *)v41;
      v43 = 2 * (buf->m_nDataBytes & 3);
      v44 = 32 * (v42 >> 2) - buf->m_nBitsAvail;
      v45 = buf->m_nDataBits;
      v41 = (const unsigned int *)(v44 + 4 * v43);
      if ( (int)v41 >= v45 )
        v41 = (const unsigned int *)v45;
    }
    m_DemoRecorder->RecordMessages(
      this: m_DemoRecorder,
      a2: (bf_read *)&democopy.m_bOverflow,
      a3: (char *)v41 - msgname);
  }
  v46 = net_dumptest.m_pParent->m_Value.m_nValue;
  if ( v46 > 0 )
  {
    if ( v46 == 2 )
    {
      MEMORY[0] = 1;
      return 1;
    }
    ConVar::SetValue(this: (ConVar *)&net_dumptest.IConVar, value: 0);
    CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v2, pchReason: "requested from console");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005570
// Name: private: int CNetChan::ProcessPacketHeader(struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::ProcessPacketHeader(CNetChan *this, netpacket_t *packet)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // ebp
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebp
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  const unsigned int *v20; // edx
  unsigned int v21; // edi
  int v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebp
  int v26; // edi
  int v27; // ecx
  unsigned int v28; // eax
  int v29; // edx
  int v30; // ecx
  const unsigned int *v31; // eax
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edi
  int v35; // eax
  const unsigned int *v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebp
  int v39; // edi
  int v40; // ecx
  unsigned int v41; // eax
  __int16 v42; // dx
  int v43; // ecx
  __int16 v44; // di
  const unsigned int *v45; // eax
  const unsigned int *v46; // ecx
  const unsigned int *v47; // edx
  unsigned int v48; // edi
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // ebp
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  const char *v55; // eax
  int v57; // ecx
  unsigned int v58; // eax
  int v59; // edx
  int v60; // ecx
  const unsigned int *v61; // eax
  const unsigned int *v62; // ecx
  const unsigned int *v63; // edx
  unsigned int v64; // edi
  int v65; // eax
  const unsigned int *v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // ebp
  int v69; // edi
  int v70; // edi
  int v71; // ecx
  unsigned int v72; // eax
  int v73; // ecx
  const unsigned int *v74; // eax
  const unsigned int *v75; // ecx
  const unsigned int *v76; // edx
  unsigned int v77; // edi
  int v78; // eax
  const unsigned int *v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // ebp
  CNetChan *v82; // edx
  int v83; // eax
  const char *v84; // ecx
  const char *v85; // eax
  int v86; // eax
  const char *v87; // eax
  char v88; // cl
  int *p_state; // edi
  int m_nOutReliableState; // edx
  int j; // eax
  int *v92; // eax
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *m_WaitingList; // edx
  int k; // ebp
  CNetChan::DataFragments_t *v95; // ecx
  int m; // eax
  int v97; // eax
  int n; // eax
  int v99; // edi
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *v100; // ebp
  CNetChan::DataFragments_t *v101; // eax
  int numFragments; // ecx
  const char *v103; // eax
  const char *v104; // [esp-Ch] [ebp-34h]
  int v105; // [esp-8h] [ebp-30h]
  int m_nInSequenceNr; // [esp-4h] [ebp-2Ch]
  int v107; // [esp-4h] [ebp-2Ch]
  int v109; // [esp+14h] [ebp-14h]
  int v110; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int nChoked; // [esp+20h] [ebp-8h]
  int v113; // [esp+24h] [ebp-4h]
  netpacket_t *packeta; // [esp+2Ch] [ebp+4h]

  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v11 = 32 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_16;
      }
      packet->message.m_nInBufWord = *m_pDataIn;
    }
    packet->message.m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( packet->message.m_bOverflow )
    {
      v6 = 0;
      packeta = nullptr;
    }
    else
    {
      v13 = packet->message.m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v11;
      v6 = v14 | m_nInBufWord;
      packeta = (netpacket_t *)v6;
      packet->message.m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v4 = packet->message.m_nInBufWord;
  v5 = m_nBitsAvail - 32;
  packet->message.m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    v6 = v4;
    packet->message.m_nInBufWord = 0;
    packeta = (netpacket_t *)v4;
  }
  else
  {
    v7 = packet->message.m_pDataIn;
    v8 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      v6 = v4;
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v7 + 1;
      packeta = (netpacket_t *)v4;
    }
    else
    {
      v6 = v4;
      if ( v7 <= v8 )
      {
        packet->message.m_nInBufWord = *v7;
        packet->message.m_pDataIn = v7 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      packeta = (netpacket_t *)v4;
    }
  }
LABEL_19:
  v15 = packet->message.m_nBitsAvail;
  if ( v15 < 32 )
  {
    v20 = packet->message.m_pBufferEnd;
    v21 = packet->message.m_nInBufWord;
    v22 = 32 - v15;
    v23 = packet->message.m_pDataIn;
    if ( v23 == v20 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_34;
      }
      packet->message.m_nInBufWord = *v23;
    }
    packet->message.m_pDataIn = v23 + 1;
LABEL_34:
    if ( packet->message.m_bOverflow )
    {
      v109 = 0;
    }
    else
    {
      v24 = packet->message.m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v22;
      v26 = v25 | v21;
      v6 = (int)packeta;
      v109 = v26;
      packet->message.m_nInBufWord = v24 >> v22;
    }
    goto LABEL_37;
  }
  v16 = packet->message.m_nInBufWord;
  v17 = v15 - 32;
  packet->message.m_nBitsAvail = v17;
  if ( v17 != 0 )
  {
    packet->message.m_nInBufWord = 0;
    v109 = v16;
  }
  else
  {
    v18 = packet->message.m_pDataIn;
    v19 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v18 == v19 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v18 + 1;
      v109 = v16;
    }
    else
    {
      if ( v18 <= v19 )
      {
        packet->message.m_nInBufWord = *v18;
        packet->message.m_pDataIn = v18 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v109 = v16;
    }
  }
LABEL_37:
  v27 = packet->message.m_nBitsAvail;
  if ( v27 < 8 )
  {
    v33 = packet->message.m_pBufferEnd;
    v34 = packet->message.m_nInBufWord;
    v35 = 8 - v27;
    v36 = packet->message.m_pDataIn;
    if ( v36 == v33 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v36 > v33 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_52;
      }
      packet->message.m_nInBufWord = *v36;
    }
    packet->message.m_pDataIn = v36 + 1;
LABEL_52:
    if ( packet->message.m_bOverflow )
    {
      v110 = 0;
    }
    else
    {
      v37 = packet->message.m_nInBufWord;
      v38 = (v37 & CBitBuffer::s_nMaskTable[v35]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v35;
      v39 = v38 | v34;
      v6 = (int)packeta;
      v110 = v39;
      packet->message.m_nInBufWord = v37 >> v35;
    }
    goto LABEL_55;
  }
  v28 = packet->message.m_nInBufWord;
  v29 = (unsigned __int8)v28;
  v30 = v27 - 8;
  packet->message.m_nBitsAvail = v30;
  if ( v30 != 0 )
  {
    packet->message.m_nInBufWord = v28 >> 8;
    v110 = (unsigned __int8)v28;
  }
  else
  {
    v31 = packet->message.m_pDataIn;
    v32 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v31 + 1;
      v110 = v29;
    }
    else
    {
      if ( v31 <= v32 )
      {
        packet->message.m_nInBufWord = *v31;
        packet->message.m_pDataIn = v31 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v110 = v29;
    }
  }
LABEL_55:
  if ( !CNetworkSystem::ShouldChecksumPackets(this: g_pNetworkSystemInternal) )
    goto LABEL_80;
  v40 = packet->message.m_nBitsAvail;
  if ( v40 < 16 )
  {
    v47 = packet->message.m_pBufferEnd;
    v48 = packet->message.m_nInBufWord;
    v49 = 16 - v40;
    v50 = packet->message.m_pDataIn;
    if ( v50 == v47 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v50 > v47 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_71;
      }
      packet->message.m_nInBufWord = *v50;
    }
    packet->message.m_pDataIn = v50 + 1;
LABEL_71:
    if ( packet->message.m_bOverflow )
    {
      v44 = 0;
    }
    else
    {
      v51 = packet->message.m_nInBufWord;
      v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v49;
      v44 = v52 | v48;
      v6 = (int)packeta;
      packet->message.m_nInBufWord = v51 >> v49;
    }
    goto LABEL_74;
  }
  v41 = packet->message.m_nInBufWord;
  v42 = v41;
  v43 = v40 - 16;
  packet->message.m_nBitsAvail = v43;
  if ( v43 != 0 )
  {
    packet->message.m_nInBufWord = HIWORD(v41);
    v44 = v41;
  }
  else
  {
    v45 = packet->message.m_pDataIn;
    v46 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v45 == v46 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v45 + 1;
      v44 = v42;
    }
    else
    {
      if ( v45 <= v46 )
      {
        packet->message.m_nInBufWord = *v45;
        packet->message.m_pDataIn = v45 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v44 = v42;
    }
  }
LABEL_74:
  m_pData = packet->message.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (packet->message.m_pDataIn - m_pData)
                - packet->message.m_nBitsAvail
                + 8 * (packet->message.m_nDataBytes & 3);
    if ( m_nDataBits >= packet->message.m_nDataBits )
      m_nDataBits = packet->message.m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( CNetworkSystem::BufferToShortChecksum(
         this: g_pNetworkSystemInternal,
         pvData: (char *)packet->message.m_pData + (m_nDataBits >> 3),
         nLength: packet->message.m_nDataBytes - (m_nDataBits >> 3)) != v44 )
  {
    m_nInSequenceNr = this->m_nInSequenceNr;
    v55 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    _Msg(a1: "%s:corrupted packet %i at %i\n", v55, v6, m_nInSequenceNr);
    return -1;
  }
LABEL_80:
  v57 = packet->message.m_nBitsAvail;
  if ( v57 < 8 )
  {
    v63 = packet->message.m_pBufferEnd;
    v64 = packet->message.m_nInBufWord;
    v65 = 8 - v57;
    v66 = packet->message.m_pDataIn;
    if ( v66 == v63 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v66 > v63 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_95;
      }
      packet->message.m_nInBufWord = *v66;
    }
    packet->message.m_pDataIn = v66 + 1;
LABEL_95:
    if ( packet->message.m_bOverflow )
    {
      i = 0;
    }
    else
    {
      v67 = packet->message.m_nInBufWord;
      v68 = (v67 & CBitBuffer::s_nMaskTable[v65]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v65;
      v69 = v68 | v64;
      v6 = (int)packeta;
      i = v69;
      packet->message.m_nInBufWord = v67 >> v65;
    }
    goto LABEL_98;
  }
  v58 = packet->message.m_nInBufWord;
  v59 = (unsigned __int8)v58;
  v60 = v57 - 8;
  packet->message.m_nBitsAvail = v60;
  if ( v60 != 0 )
  {
    packet->message.m_nInBufWord = v58 >> 8;
    i = (unsigned __int8)v58;
  }
  else
  {
    v61 = packet->message.m_pDataIn;
    v62 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v61 == v62 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v61 + 1;
      i = v59;
    }
    else
    {
      if ( v61 <= v62 )
      {
        packet->message.m_nInBufWord = *v61;
        packet->message.m_pDataIn = v61 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      i = v59;
    }
  }
LABEL_98:
  v70 = 0;
  v113 = 0;
  if ( (v110 & 0x10) == 0 )
    goto LABEL_117;
  v71 = packet->message.m_nBitsAvail;
  if ( v71 < 8 )
  {
    v76 = packet->message.m_pBufferEnd;
    v77 = packet->message.m_nInBufWord;
    v78 = 8 - v71;
    v79 = packet->message.m_pDataIn;
    if ( v79 == v76 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v79 > v76 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_113;
      }
      packet->message.m_nInBufWord = *v79;
    }
    packet->message.m_pDataIn = v79 + 1;
LABEL_113:
    if ( packet->message.m_bOverflow )
    {
      v70 = 0;
    }
    else
    {
      v80 = packet->message.m_nInBufWord;
      v81 = (v80 & CBitBuffer::s_nMaskTable[v78]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v78;
      v70 = v81 | v77;
      v6 = (int)packeta;
      packet->message.m_nInBufWord = v80 >> v78;
    }
    goto LABEL_116;
  }
  v72 = packet->message.m_nInBufWord;
  v70 = (unsigned __int8)v72;
  v73 = v71 - 8;
  packet->message.m_nBitsAvail = v73;
  if ( v73 != 0 )
  {
    packet->message.m_nInBufWord = v72 >> 8;
  }
  else
  {
    v74 = packet->message.m_pDataIn;
    v75 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v74 == v75 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v74 + 1;
    }
    else if ( v74 <= v75 )
    {
      packet->message.m_nInBufWord = *v74;
      packet->message.m_pDataIn = v74 + 1;
    }
    else
    {
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
    }
  }
LABEL_116:
  v113 = v70;
LABEL_117:
  v82 = this;
  v83 = this->m_nInSequenceNr;
  if ( v6 > v83 )
  {
    v86 = v6 - v83 - v70 - 1;
    this->m_PacketDrop = v86;
    if ( v86 > 0 && net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v105 = v86;
      v87 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      _Msg(a1: "%s:Dropped %i packets at %i\n", v87, v105, v6);
      v82 = this;
    }
    v88 = 0;
    nChoked = 0;
    p_state = &v82->m_SubChannels[0].state;
    do
    {
      m_nOutReliableState = this->m_nOutReliableState;
      if ( ((1 << v88) & m_nOutReliableState) == ((1 << v88) & i) )
      {
        if ( *p_state == 3 )
        {
          *p_state = 0;
          *(p_state - 1) = -1;
          for ( j = 0; j < 2; ++j )
          {
            p_state[j - 3] = 0;
            p_state[j - 5] = -1;
          }
        }
        else
        {
          if ( *(p_state - 1) > v109 )
          {
            v103 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
            _Msg(a1: "%s:reliable state invalid (%i).\n", v103, nChoked);
            return -1;
          }
          if ( *p_state == 2 )
          {
            v92 = p_state - 3;
            m_WaitingList = this->m_WaitingList;
            for ( k = 2; k != 0; --k )
            {
              if ( *v92 != 0 )
              {
                v95 = *m_WaitingList->m_Memory.m_pMemory;
                v95->ackedFragments += *v92;
                v95->pendingFragments -= *v92;
              }
              ++v92;
              ++m_WaitingList;
            }
            *p_state = 0;
            *(p_state - 1) = -1;
            for ( m = 0; m < 2; ++m )
            {
              p_state[m - 3] = 0;
              p_state[m - 5] = -1;
            }
          }
        }
      }
      else if ( *(p_state - 1) <= v109 )
      {
        if ( *p_state == 2 )
        {
          if ( net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            _Msg(a1: "Resending subchan %i: start %i, num %i\n", p_state[1], *(p_state - 5), *(p_state - 3));
          *p_state = 1;
        }
        else if ( *p_state == 3 )
        {
          v97 = 1 << p_state[1];
          if ( (m_nOutReliableState & v97) != 0 )
            this->m_nOutReliableState = m_nOutReliableState & ~v97;
          else
            this->m_nOutReliableState = v97 | m_nOutReliableState;
          *p_state = 0;
          *(p_state - 1) = -1;
          for ( n = 0; n < 2; ++n )
          {
            p_state[n - 3] = 0;
            p_state[n - 5] = -1;
          }
        }
      }
      v88 = nChoked + 1;
      p_state += 7;
      ++nChoked;
    }
    while ( nChoked < 8 );
    this->m_nInSequenceNr = (int)packeta;
    this->m_nOutSequenceNrAck = v109;
    v99 = 0;
    v100 = this->m_WaitingList;
    do
    {
      if ( v100->m_Size != 0 && this->m_nOutSequenceNrAck > 0 )
      {
        v101 = *v100->m_Memory.m_pMemory;
        numFragments = v101->numFragments;
        if ( v101->ackedFragments == numFragments )
        {
          if ( net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            _Msg(a1: "Sending complete: %i fragments, %i bytes.\n", numFragments, v101->bytes);
          CNetChan::RemoveHeadInWaitingList(this, nList: (CNetChan::DataFragments_t *)v99);
        }
      }
      ++v99;
      ++v100;
    }
    while ( v99 < 2 );
    CNetChan::FlowNewPacket(
      this,
      flow: 1,
      seqnr: this->m_nInSequenceNr,
      acknr: this->m_nOutSequenceNrAck,
      nChoked: v113,
      nDropped: this->m_PacketDrop,
      nSize: packet->wiresize + 28);
    return v110;
  }
  else
  {
    if ( net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v84 = "duplicate";
      if ( v6 != v83 )
        v84 = "out of order";
      v107 = this->m_nInSequenceNr;
      v104 = v84;
      v85 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      _Msg(a1: "%s:%s packet %i at %i\n", v85, v104, v6, v107);
    }
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D20
// Name: public: virtual void CNetChan::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Clear(CNetChan *this)
{
  CNetChan *v1; // ebx
  void **p_buffer; // edi
  int *p_m_Size; // esi
  void **v4; // edi
  int v5; // ecx
  int v6; // eax
  void ***v7; // edx
  int v8; // ecx
  bool v9; // zf
  int v10; // ecx
  int *p_state; // edx
  int m_nOutReliableState; // esi
  int v13; // eax
  int i; // eax
  void (__thiscall *Reset)(struct CNetChan *); // edx
  char **v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]

  v1 = this;
  p_buffer = (void **)&this->m_ReceiveList[0].buffer;
  v16 = &this->m_ReceiveList[0].buffer;
  p_m_Size = &this->m_WaitingList[0].m_Size;
  v17 = 2;
  do
  {
    if ( *p_m_Size != 0 )
    {
      do
      {
        v4 = *(void ***)*(p_m_Size - 3);
        if ( v4[66] != nullptr )
          free(pMem: v4[66]);
        if ( *v4 != nullptr )
        {
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: *v4);
          *v4 = nullptr;
        }
        v5 = *p_m_Size;
        v6 = 0;
        if ( *p_m_Size > 0 )
        {
          v7 = (void ***)*(p_m_Size - 3);
          while ( *v7 != v4 )
          {
            ++v6;
            ++v7;
            if ( v6 >= v5 )
              goto LABEL_16;
          }
          if ( v6 != -1 )
          {
            v8 = v5 - v6 - 1;
            if ( v8 > 0 )
              _V_memmove(
                dest: (void *)(*(p_m_Size - 3) + 4 * v6),
                src: (const void *)(*(p_m_Size - 3) + 4 * v6 + 4),
                count: 4 * v8);
            --*p_m_Size;
          }
        }
LABEL_16:
        free(pMem: v4);
      }
      while ( *p_m_Size != 0 );
      v1 = this;
      p_buffer = (void **)v16;
    }
    if ( *p_buffer != nullptr )
    {
      free(pMem: *p_buffer);
      *p_buffer = nullptr;
    }
    p_buffer += 76;
    p_m_Size += 5;
    v9 = v17-- == 1;
    v16 = (char **)p_buffer;
  }
  while ( !v9 );
  v10 = 0;
  p_state = &v1->m_SubChannels[0].state;
  do
  {
    if ( *p_state == 1 )
    {
      m_nOutReliableState = v1->m_nOutReliableState;
      v13 = 1 << v10;
      if ( (m_nOutReliableState & (1 << v10)) != 0 )
        v1->m_nOutReliableState = m_nOutReliableState & ~v13;
      else
        v1->m_nOutReliableState = v13 | m_nOutReliableState;
      *p_state = 0;
      *(p_state - 1) = -1;
      for ( i = 0; i < 2; ++i )
      {
        p_state[i - 3] = 0;
        p_state[i - 5] = -1;
      }
    }
    else if ( *p_state == 2 )
    {
      *p_state = 3;
    }
    ++v10;
    p_state += 7;
  }
  while ( v10 < 8 );
  Reset = v1->Reset;
  v1->m_bStopProcessing = true;
  Reset(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10006E80
// Name: public: virtual void CNetChan::Shutdown(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetChan::Shutdown(CNetChan *this@<ecx>, bool a2@<bpl>, int a3@<edi>, const char *pReason, char *pStr)
{
  int v6; // eax
  unsigned __int64 v7; // rax
  INetChannelHandler *m_MessageHandler; // ecx
  int i; // edi
  INetMessage *v10; // ecx
  bool v11; // sf
  bool v12; // zf
  void (__thiscall *RemoveNetChannel)(INetworkSystem *, INetChannel *, bool); // eax

  if ( this->m_Socket >= 0 )
  {
    ((void (__thiscall *)(CNetChan *, int))this->Clear)(a1: this, a2: a3);
    if ( pStr != nullptr )
    {
      v6 = ((int (__thiscall *)(INetworkSystem *, int))g_pNetworkSystem->GetMsgTypeBits)(a1: g_pNetworkSystem, a2: 1);
      bf_write::WriteUBitLong(this: &this->m_StreamUnreliable, curData: 1u, numbits: v6, bCheckRange: a2);
      bf_write::WriteString(this: &this->m_StreamUnreliable, pStr);
      this->Transmit(this, a2: false);
    }
    v7 = g_pSteamSocketMgrInternal->GetSteamIDForRemote(this: g_pSteamSocketMgrInternal, a2: &this->remote_address);
    if ( v7 != 0 )
      ((void (__thiscall *)(ISteamSocketMgrInternal *, int, _DWORD, _DWORD))g_pSteamSocketMgrInternal->TerminateSteamConnection)(
        a1: g_pSteamSocketMgrInternal,
        a2: this->m_Socket,
        a3: v7,
        a4: HIDWORD(v7));
    this->m_Socket = -1;
    netadr_s::Clear(this: &this->remote_address);
    m_MessageHandler = this->m_MessageHandler;
    if ( m_MessageHandler != nullptr )
    {
      m_MessageHandler->ConnectionClosing(this: m_MessageHandler, a2: pStr);
      this->m_MessageHandler = nullptr;
    }
    for ( i = 0; i < this->m_NetMessages.m_Size; ++i )
    {
      v10 = this->m_NetMessages.m_Memory.m_pMemory[i];
      if ( v10 != nullptr )
        ((void (__thiscall *)(INetMessage *, int))v10->dtr_INetMessage)(a1: v10, a2: 1);
    }
    v11 = this->m_NetMessages.m_Memory.m_nGrowSize < 0;
    this->m_NetMessages.m_Size = 0;
    if ( !v11 )
    {
      if ( this->m_NetMessages.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NetMessages.m_Memory.m_pMemory);
        this->m_NetMessages.m_Memory.m_pMemory = nullptr;
      }
      this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
    }
    this->m_NetMessages.m_pElements = this->m_NetMessages.m_Memory.m_pMemory;
    v12 = !this->m_bProcessingMessages;
    this->m_DemoRecorder = nullptr;
    RemoveNetChannel = g_pNetworkSystem->RemoveNetChannel;
    if ( v12 )
    {
      ((void (__stdcall *)(CNetChan *, int))RemoveNetChannel)(a1: this, a2: 1);
    }
    else
    {
      ((void (__stdcall *)(CNetChan *, _DWORD))RemoveNetChannel)(a1: this, a2: 0);
      this->m_bShouldDelete = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006FD0
// Name: public: virtual bool CNetChan::ProcessDemoPacket(struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessDemoPacket(CNetChan *this, netpacket_t *packet)
{
  CNetChan::FlowNewPacket(
    this,
    flow: 1,
    seqnr: this->m_nInSequenceNr,
    acknr: this->m_nOutSequenceNrAck,
    nChoked: 0,
    nDropped: 0,
    nSize: packet->wiresize);
  this->last_received = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
  this->m_MessageHandler->PacketStart(
    this: this->m_MessageHandler,
    a2: this->m_nInSequenceNr,
    a3: this->m_nOutSequenceNrAck);
  this->m_pActiveChannel = this;
  if ( CNetChan::_ProcessMessages(this, buf: &packet->message) == 0 )
    return 0;
  this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007050
// Name: private: bool CNetChan::CheckReceivingList(int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNetChan::CheckReceivingList@<al>(CNetChan *this@<ecx>, int a2@<ebx>, int a3@<edi>, int nList)
{
  CNetChan::DataFragments_t *v5; // esi
  char result; // al
  int ackedFragments; // ecx
  int numFragments; // eax
  char *v9; // ecx
  void *v10; // eax
  int bytes; // [esp-14h] [ebp-40h]
  bf_read buffer; // [esp+4h] [ebp-28h] BYREF

  v5 = &this->m_ReceiveList[nList];
  if ( this->m_ReceiveList[nList].buffer == nullptr )
    return 1;
  ackedFragments = this->m_ReceiveList[nList].ackedFragments;
  numFragments = v5->numFragments;
  if ( ackedFragments < numFragments )
    return 1;
  if ( ackedFragments > numFragments )
  {
    _Msg(a1: "Receiving failed: too many fragments %i/%i\n", ackedFragments, v5->numFragments);
    return 0;
  }
  if ( net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Receiving complete: %i fragments, %i bytes\n", numFragments, v5->bytes);
  if ( v5->isCompressed )
    CNetChan::UncompressFragments(this, data: v5);
  if ( v5->filename[0] != 0 )
  {
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: nullptr)
      || g_pNetworkSystem->CanRedownloadFile(this: g_pNetworkSystem, a2: v5->filename) )
    {
      g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: v5->filename, a3: nullptr);
      v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: "wb", a4: 0);
      v5->file = v10;
      if ( v10 != nullptr )
      {
        ((void (__thiscall *)(IBaseFileSystem *, char *, unsigned int, void *, int, int))g_pFileSystem->Write)(
          a1: &g_pFileSystem->IBaseFileSystem,
          a2: v5->buffer,
          a3: v5->bytes,
          a4: v10,
          a5: a3,
          a6: a2);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5->file);
        if ( net_showfragments.m_pParent->m_Value.m_nValue == 2 )
          DevMsg(a1: "FileReceived: %s, %i bytes (ID %i)\n", v5->filename, v5->bytes, v5->transferID);
        ((void (__thiscall *)(INetChannelHandler *, char *))this->m_MessageHandler->FileReceived)(
          a1: this->m_MessageHandler,
          a2: v5->filename);
      }
      else
      {
        _Msg(a1: "Failed to write received file '%s'!\n", v5->filename);
      }
    }
    else
    {
      _Msg(a1: "Download file '%s' already exists!\n", v5->filename);
    }
  }
  else
  {
    v9 = v5->buffer;
    *(_DWORD *)&buffer.m_bOverflow = 0;
    buffer.m_nInBufWord = 0;
    bytes = v5->bytes;
    LOBYTE(buffer.m_nDataBits) = 0;
    buffer.m_nDataBytes = -1;
    CBitRead::StartReading(this: (CBitRead *)&buffer.m_bOverflow, pData: v9, nBytes: bytes, iStartBit: 0, nBits: -1);
    this->m_pActiveChannel = this;
    result = CNetChan::_ProcessMessages(this, buf: (bf_read *)&buffer.m_bOverflow);
    if ( result == 0 )
      return result;
  }
  if ( v5->buffer != nullptr )
  {
    free(pMem: v5->buffer);
    v5->buffer = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007260
// Name: public: virtual void CNetChan::ProcessPacket(struct netpacket_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ProcessPacket(CNetChan *this, netpacket_t *packet, bool bHasHeader)
{
  bf_read *p_message; // esi
  int v5; // ebx
  int m_nValue; // eax
  unsigned __int64 v7; // rax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  double v12; // st7
  int m_nBitsAvail; // ecx
  unsigned int v14; // eax
  char v15; // dl
  int v16; // ecx
  char v17; // cl
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v22; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebp
  int v26; // ebx
  int v27; // ebp
  unsigned int v28; // eax
  int v29; // edx
  const unsigned int *v31; // eax
  const unsigned int *v32; // ecx
  int m_nInReliableState; // eax
  int v34; // ebx
  const unsigned int *m_pData; // eax
  IDemoRecorderBase *m_DemoRecorder; // edi
  const char *v37; // [esp+4h] [ebp-A0h]
  unsigned __int64 v38; // [esp+8h] [ebp-9Ch]
  __int64 v39; // [esp+8h] [ebp-9Ch]
  const char *v40; // [esp+Ch] [ebp-98h]
  int v41; // [esp+Ch] [ebp-98h]
  char desc[128]; // [esp+20h] [ebp-84h] BYREF

  p_message = &packet->message;
  CBitRead::Seek(this: &packet->message, nPosition: 0);
  if ( netadr_s::IsValid(this: &this->remote_address)
    && !netadr_s::CompareAdr(this: &packet->from, a: &this->remote_address, onlyBase: false) )
  {
    return;
  }
  CNetchanParanoidMode::StartPacket(this: &g_NetParanoid, fullbuf: p_message);
  CNetChan::FlowUpdate(this, flow: 1, addbytes: packet->wiresize + 28);
  v5 = 0;
  if ( bHasHeader )
  {
    v5 = CNetChan::ProcessPacketHeader(this, packet);
    if ( v5 == -1 )
      return;
  }
  CNetchanParanoidMode::NoteHeaderSize(this: &g_NetParanoid, msg: p_message, flags: v5);
  m_nValue = net_showudp.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 0
    && m_nValue != 3
    && (net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
     || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
  {
    v7 = g_pSteamSocketMgrInternal->GetSteamIDForRemote(this: g_pSteamSocketMgrInternal, a2: &this->remote_address);
    desc[2] = -1;
    desc[3] = -1;
    desc[0] = 0;
    desc[1] = -56;
    if ( v7 != 0 )
    {
      desc[0] = -1;
      desc[1] = -1;
      desc[3] = -1;
      desc[2] = 100;
      v38 = v7;
      v8 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      v9 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                           a1: this,
                           a2: v8,
                           a3: v38,
                           a4: HIDWORD(v38));
      V_snprintf(pDest: &desc[4], maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v9, v37, v39);
    }
    else
    {
      v10 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      v11 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v10);
      V_snprintf(pDest: &desc[4], maxLen: 128, pFormat: "%12.12s %21.21s", v11, v40);
    }
    v12 = ((double (__thiscall *)(INetworkSystem *, int))g_pNetworkSystem->GetNetTime)(
            a1: g_pNetworkSystem,
            a2: packet->wiresize);
    ConColorMsg(
      a1: (const struct Color *)desc,
      a2: "UDP <- %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f wire=%i\n",
      &desc[4],
      packet->size,
      this->m_nInSequenceNr & 0x3F,
      this->m_nOutSequenceNrAck & 0x3F,
      v5 & 1,
      v12,
      v41);
  }
  this->last_received = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
  this->m_MessageHandler->PacketStart(
    this: this->m_MessageHandler,
    a2: this->m_nInSequenceNr,
    a3: this->m_nOutSequenceNrAck);
  if ( (v5 & 1) == 0 )
  {
LABEL_50:
    m_pData = packet->message.m_pData;
    if ( m_pData != nullptr )
    {
      m_pData = (const unsigned int *)(32 * (packet->message.m_pDataIn - m_pData)
                                     - packet->message.m_nBitsAvail
                                     + 8 * (packet->message.m_nDataBytes & 3));
      if ( (int)m_pData >= packet->message.m_nDataBits )
        m_pData = (const unsigned int *)packet->message.m_nDataBits;
    }
    if ( packet->message.m_nDataBits - (int)m_pData <= 0
      || (this->m_pActiveChannel = this, CNetChan::_ProcessMessages(this, buf: p_message) != 0) )
    {
      this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
      m_DemoRecorder = this->m_DemoRecorder;
      if ( m_DemoRecorder != nullptr )
        m_DemoRecorder->RecordPacket(this: m_DemoRecorder);
    }
    return;
  }
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 3 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v22 = 3 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_30;
      }
      packet->message.m_nInBufWord = *m_pDataIn;
    }
    packet->message.m_pDataIn = m_pDataIn + 1;
LABEL_30:
    if ( packet->message.m_bOverflow )
    {
      v17 = 0;
    }
    else
    {
      v24 = packet->message.m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v22;
      v17 = v25 | m_nInBufWord;
      packet->message.m_nInBufWord = v24 >> v22;
    }
    goto LABEL_33;
  }
  v14 = packet->message.m_nInBufWord;
  v15 = v14 & 7;
  v16 = m_nBitsAvail - 3;
  packet->message.m_nBitsAvail = v16;
  if ( v16 != 0 )
  {
    packet->message.m_nInBufWord = v14 >> 3;
    v17 = v14 & 7;
  }
  else
  {
    v18 = packet->message.m_pDataIn;
    v19 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v18 == v19 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v18 + 1;
      v17 = v15;
    }
    else
    {
      if ( v18 <= v19 )
      {
        packet->message.m_nInBufWord = *v18;
        packet->message.m_pDataIn = v18 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v17 = v15;
    }
  }
LABEL_33:
  v26 = 1 << v17;
  v27 = 0;
  while ( 1 )
  {
    v28 = packet->message.m_nInBufWord;
    v29 = v28 & 1;
    if ( packet->message.m_nBitsAvail-- == 1 )
    {
      v31 = packet->message.m_pDataIn;
      v32 = packet->message.m_pBufferEnd;
      packet->message.m_nBitsAvail = 32;
      if ( v31 == v32 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_pDataIn = v31 + 1;
      }
      else if ( v31 <= v32 )
      {
        packet->message.m_nInBufWord = *v31;
        packet->message.m_pDataIn = v31 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
    }
    else
    {
      packet->message.m_nInBufWord = v28 >> 1;
    }
    if ( v29 != 0 && CNetChan::ReadSubChannelData(this, buf: p_message, stream: v27) == 0 )
      break;
    if ( ++v27 >= 2 )
    {
      m_nInReliableState = this->m_nInReliableState;
      if ( (m_nInReliableState & v26) != 0 )
        this->m_nInReliableState = m_nInReliableState & ~v26;
      else
        this->m_nInReliableState = v26 | m_nInReliableState;
      v34 = 0;
      while ( CNetChan::CheckReceivingList(this, a2: v34, a3: (int)this, nList: v34) != 0 )
      {
        if ( ++v34 >= 2 )
          goto LABEL_50;
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007660
// Name: private: void CNetChan::MergeSplitUserBuffers(enum ENetChannelBufType,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::MergeSplitUserBuffers(
        CNetChan *this,
        ENetChannelBufType ENetChannelBufType,
        bf_write *outbuf)
{
  CNetChan *v3; // esi
  int Inorder; // ebp
  UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *m_pMemory; // ecx
  unsigned int *p_m_Data; // edx
  INetChannel *m_pChannel; // eax
  bf_write *v8; // edi
  unsigned int v9; // esi
  int v10; // eax
  int v11; // eax
  unsigned int v12; // [esp+8h] [ebp-8h]

  v3 = this;
  v12 = 0;
  Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SplitPlayers);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v3->m_SplitPlayers.m_Elements.m_pMemory;
      p_m_Data = (unsigned int *)&m_pMemory[(unsigned __int16)Inorder].m_Data;
      m_pChannel = m_pMemory[(unsigned __int16)Inorder].m_Data.m_pChannel;
      if ( m_pChannel != nullptr )
        break;
LABEL_13:
      Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &v3->m_SplitPlayers,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
      {
        if ( v12 != 0 )
        {
          v11 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
          bf_write::WriteUBitLong(this: outbuf, curData: 3u, numbits: v11, bCheckRange: true);
          bf_write::WriteUBitLong(this: outbuf, curData: 0, numbits: 2, bCheckRange: true);
        }
        return;
      }
    }
    if ( ENetChannelBufType != BUF_RELIABLE )
    {
      if ( ENetChannelBufType == BUF_UNRELIABLE )
      {
        v8 = (bf_write *)&m_pChannel[17];
        goto LABEL_9;
      }
      if ( ENetChannelBufType == BUF_VOICE )
      {
        v8 = (bf_write *)&m_pChannel[26];
        goto LABEL_9;
      }
    }
    v8 = (bf_write *)&m_pChannel[8];
LABEL_9:
    if ( v8->m_iCurBit > 0 )
    {
      v9 = *p_m_Data;
      if ( *p_m_Data != v12 )
      {
        v12 = *p_m_Data;
        v10 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
        bf_write::WriteUBitLong(this: outbuf, curData: 3u, numbits: v10, bCheckRange: true);
        bf_write::WriteUBitLong(this: outbuf, curData: v9, numbits: 2, bCheckRange: true);
      }
      bf_write::WriteBits(this: outbuf, pInData: v8->m_pData, nBits: v8->m_iCurBit);
      bf_write::Reset(this: v8);
      v3 = this;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007A40
// Name: private: bool CNetChan::CreateFragmentsFromBuffer(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::CreateFragmentsFromBuffer(
        CNetChan *this,
        bf_write *buffer,
        CNetChan::DataFragments_t *stream)
{
  char *v4; // ebp
  int v5; // eax
  CNetChan::DataFragments_t *v6; // esi
  unsigned int bits; // ecx
  int v8; // edi
  void *v9; // ebp
  __int64 v10; // rax
  int v11; // edi
  int v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  bf_write bfwrite; // [esp+Ch] [ebp-1Ch] BYREF

  bf_write::bf_write(this: (bf_write *)&bfwrite.m_nDataBytes);
  v4 = (char *)this + 20 * (_DWORD)stream;
  v5 = *((_DWORD *)v4 + 51);
  if ( v5 > 1
    && (v6 = *(CNetChan::DataFragments_t **)(*((_DWORD *)v4 + 48) + 4 * v5 - 4),
        bits = v6->bits,
        (unsigned int)(v8 = 4 * ((int)(((buffer->m_iCurBit + bits + 7) >> 3) + 3) >> 2)) < 0x17700)
    && v6->buffer != nullptr )
  {
    v9 = operator new(nSize: 4 * ((int)(((buffer->m_iCurBit + bits + 7) >> 3) + 3) >> 2));
    _V_memcpy(dest: v9, src: v6->buffer, count: v6->bytes);
    free(pMem: v6->buffer);
    v6->buffer = (char *)v9;
    bf_write::StartWriting(
      this: (bf_write *)&bfwrite.m_nDataBytes,
      pData: v9,
      nBytes: v8,
      iStartBit: v6->bits,
      nBits: -1);
  }
  else
  {
    v10 = ((buffer->m_iCurBit + 7) >> 3) + 3;
    v11 = 4 * (((BYTE4(v10) & 3) + (int)v10) >> 2);
    v6 = (CNetChan::DataFragments_t *)operator new(nSize: 0x130u);
    v6->bytes = 0;
    stream = v6;
    v6->bits = 0;
    v6->buffer = (char *)operator new(nSize: v11);
    v6->isCompressed = false;
    v6->isReplayDemo = false;
    v6->nUncompressedSize = 0;
    v6->file = nullptr;
    v6->filename[0] = 0;
    bf_write::StartWriting(
      this: (bf_write *)&bfwrite.m_nDataBytes,
      pData: v6->buffer,
      nBytes: v11,
      iStartBit: 0,
      nBits: -1);
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)(v4 + 192),
      elem: *((_DWORD *)v4 + 51),
      src: (void (__cdecl *const *)(IConVar *, const char *, float))&stream);
  }
  bf_write::WriteBits(this: (bf_write *)&bfwrite.m_nDataBytes, pInData: buffer->m_pData, nBits: buffer->m_iCurBit);
  if ( *(_DWORD *)&bfwrite.m_bOverflow % 8 > 0 )
  {
    v12 = *(_DWORD *)&bfwrite.m_bOverflow % 8;
    if ( v12 <= 8 - g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem) )
    {
      v13 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
      bf_write::WriteUBitLong(this: (bf_write *)&bfwrite.m_nDataBytes, curData: 0, numbits: v13, bCheckRange: true);
    }
  }
  v6->bits += buffer->m_iCurBit;
  v14 = (v6->bits + 7) >> 3;
  v6->bytes = v14;
  v6->numFragments = (v14 + 255) >> 8;
  v6->ackedFragments = 0;
  v6->pendingFragments = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007C20
// Name: private: bool CNetChan::CreateFragmentsFromFile(char const __near *,int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::CreateFragmentsFromFile(
        CNetChan *this,
        CNetChan::DataFragments_t *filename,
        int stream,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  const char *v5; // edi
  int v8; // ebx
  CNetChan::DataFragments_t *v9; // esi
  bool v10; // al
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  int v12; // eax

  v5 = (const char *)filename;
  if ( CNetChan::IsFileInWaitingList(this, (const char *)filename) != 0 )
    return 1;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: "GAME") )
  {
    v8 = g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: "GAME");
    if ( v8 < net_maxfilesize.m_pParent->m_Value.m_nValue << 20 )
    {
      if ( v8 < 0x3FFFFFF )
      {
        v9 = (CNetChan::DataFragments_t *)operator new(nSize: 0x130u);
        v10 = bIsReplayDemoFile;
        v9->bytes = v8;
        v9->bits = 8 * v8;
        v9->buffer = nullptr;
        v9->isCompressed = false;
        v9->isReplayDemo = v10;
        v9->nUncompressedSize = 0;
        Open = g_pFileSystem->Open;
        filename = v9;
        v12 = (int)Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: "rb", a4: "GAME");
        v9->file = (void *)v12;
        if ( v12 != 0 )
        {
          v9->transferID = transferID;
          V_strncpy(pDest: v9->filename, pSrc: v5, maxLen: 260);
          CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
            this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_WaitingList[stream],
            elem: this->m_WaitingList[stream].m_Size,
            src: (void (__cdecl *const *)(IConVar *, const char *, float))&filename);
          v9->numFragments = (v9->bytes + 255) >> 8;
          v9->ackedFragments = 0;
          v9->pendingFragments = 0;
          return 1;
        }
        else
        {
          _Msg(a1: "CreateFragmentsFromFile: couldn't open '%s'.\n", v5);
          free(pMem: v9);
          return 0;
        }
      }
      else
      {
        _Msg(a1: "CreateFragmentsFromFile: '%s' too big (max %i bytes).\n", v5, 0x3FFFFFF);
        return 0;
      }
    }
    else
    {
      _Msg(
        a1: "CreateFragmentsFromFile: '%s' size exceeds net_maxfilesize limit (%i MB).\n",
        v5,
        net_maxfilesize.m_pParent->m_Value.m_nValue);
      return 0;
    }
  }
  else
  {
    _Msg(a1: "CreateFragmentsFromFile: '%s' doesn't exist.\n", v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007DC0
// Name: public: virtual int CNetChan::SendDatagram(class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::SendDatagram(CNetChan *this, bf_write *datagram)
{
  int m_nValue; // edi
  const char *v5; // eax
  int m_nChokedPackets; // eax
  int m_iCurBit; // ecx
  int v8; // eax
  int v9; // edi
  int i; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  char v16; // bl
  bool v17; // cc
  bool v18; // zf
  unsigned __int16 v19; // ax
  bf_write *p_m_StreamVoice; // edx
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  unsigned __int64 v24; // rax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  int v29; // edi
  double v30; // st7
  long double v31; // st7
  const char *v32; // [esp+28h] [ebp-1784Ch]
  unsigned __int64 v33; // [esp+2Ch] [ebp-17848h]
  __int64 v34; // [esp+2Ch] [ebp-17848h]
  const char *v35; // [esp+30h] [ebp-17844h]
  const char *v36; // [esp+30h] [ebp-17844h]
  unsigned __int8 v37; // [esp+5Bh] [ebp-17819h]
  int v38; // [esp+5Ch] [ebp-17818h] BYREF
  _DWORD buf[7]; // [esp+60h] [ebp-17814h] BYREF
  long double v40; // [esp+7Ch] [ebp-177F8h]
  int v41; // [esp+88h] [ebp-177ECh]
  bf_write v42; // [esp+8Ch] [ebp-177E8h] BYREF
  char pDest[64]; // [esp+A4h] [ebp-177D0h] BYREF
  char v44[128]; // [esp+E4h] [ebp-17790h] BYREF
  char pData[96016]; // [esp+164h] [ebp-17710h] BYREF

  if ( this->m_bUsesMaxRoutablePayload )
  {
    m_nValue = net_maxroutable.m_pParent->m_Value.m_nValue;
    if ( m_nValue != this->GetMaxRoutablePayloadSize(this) )
      this->SetMaxRoutablePayloadSize(this, a2: net_maxroutable.m_pParent->m_Value.m_nValue);
  }
  if ( netadr_s::GetType(this: &this->remote_address) == NA_NULL )
  {
    this->m_flClearTime = 0.0;
    this->m_nChokedPackets = 0;
    bf_write::Reset(this: &this->m_StreamReliable);
    bf_write::Reset(this: &this->m_StreamUnreliable);
    return this->m_nOutSequenceNr++;
  }
  if ( this->m_SplitPlayers.m_NumElements != 0 )
  {
    CNetChan::MergeSplitUserBuffers(this, ENetChannelBufType: BUF_RELIABLE, outbuf: &this->m_StreamReliable);
    CNetChan::MergeSplitUserBuffers(this, ENetChannelBufType: BUF_UNRELIABLE, outbuf: &this->m_StreamUnreliable);
    CNetChan::MergeSplitUserBuffers(this, ENetChannelBufType: BUF_VOICE, outbuf: &this->m_StreamVoice);
  }
  if ( this->m_StreamReliable.m_bOverflow )
  {
    v5 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    _Msg(a1: "%s:send reliable stream overflow\n", v5);
    return 0;
  }
  if ( this->m_StreamReliable.m_iCurBit > 0 )
  {
    CNetChan::CreateFragmentsFromBuffer(this, buffer: &this->m_StreamReliable, stream: nullptr);
    bf_write::Reset(this: &this->m_StreamReliable);
  }
  bf_write::bf_write(
    this: (bf_write *)&buf[1],
    pDebugName: "CNetChan_TransmitBits->send",
    pData,
    nBytes: 96016,
    nBits: -1);
  v37 = 0;
  bf_write::WriteLong(this: (bf_write *)&buf[1], val: this->m_nOutSequenceNr);
  bf_write::WriteLong(this: (bf_write *)&buf[1], val: this->m_nInSequenceNr);
  v42 = *(bf_write *)&buf[1];
  bf_write::WriteByte(this: (bf_write *)&buf[1], val: 0);
  if ( CNetworkSystem::ShouldChecksumPackets(this: g_pNetworkSystemInternal) )
    bf_write::WriteShort(this: (bf_write *)&buf[1], val: 0);
  v41 = (buf[4] + 7) >> 3;
  bf_write::WriteByte(this: (bf_write *)&buf[1], val: this->m_nInReliableState);
  m_nChokedPackets = this->m_nChokedPackets;
  if ( m_nChokedPackets > 0 )
  {
    v37 = 16;
    bf_write::WriteByte(this: (bf_write *)&buf[1], val: (unsigned __int8)m_nChokedPackets);
  }
  if ( CNetChan::SendSubChannelData(this, buf: (bf_write *)&buf[1]) != 0 )
    v37 |= 1u;
  if ( datagram != nullptr )
  {
    m_iCurBit = datagram->m_iCurBit;
    if ( m_iCurBit >= buf[3] - buf[4] )
      _ConDMsg(a1: "CNetChan::SendDatagram:  data would overfow, ignoring\n");
    else
      bf_write::WriteBits(this: (bf_write *)&buf[1], pInData: datagram->m_pData, nBits: m_iCurBit);
  }
  if ( this->m_StreamUnreliable.m_iCurBit >= buf[3] - buf[4] )
    _ConDMsg(a1: "CNetChan::SendDatagram:  Unreliable would overfow, ignoring\n");
  else
    bf_write::WriteBits(
      this: (bf_write *)&buf[1],
      pInData: this->m_StreamUnreliable.m_pData,
      nBits: this->m_StreamUnreliable.m_iCurBit);
  bf_write::Reset(this: &this->m_StreamUnreliable);
  if ( !g_pNetworkSystem->IsDedicatedForXbox(this: g_pNetworkSystem) )
  {
    v8 = this->m_StreamVoice.m_iCurBit;
    if ( v8 > 0 && v8 < buf[3] - buf[4] )
    {
      bf_write::WriteBits(
        this: (bf_write *)&buf[1],
        pInData: this->m_StreamVoice.m_pData,
        nBits: this->m_StreamVoice.m_iCurBit);
      bf_write::Reset(this: &this->m_StreamVoice);
    }
  }
  v9 = 16;
  if ( this->m_Socket == 1 )
    v9 = net_minroutable.m_pParent->m_Value.m_nValue;
  for ( i = buf[4]; (buf[4] + 7) >> 3 < v9; i = buf[4] )
  {
    v11 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
    bf_write::WriteUBitLong(this: (bf_write *)&buf[1], curData: 0, numbits: v11, bCheckRange: true);
  }
  if ( i % 8 > 0 && i % 8 <= 8 - g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem) )
  {
    v12 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
    bf_write::WriteUBitLong(this: (bf_write *)&buf[1], curData: 0, numbits: v12, bCheckRange: true);
  }
  v13 = buf[4] % 8;
  if ( buf[4] % 8 > 0 )
  {
    v37 |= 32 * (8 - v13);
    if ( 8 - v13 > 0 )
      bf_write::WriteUBitLong(
        this: (bf_write *)&buf[1],
        curData: `GetBitForBitnum'::`2'::bitsForBitnum[(8 - v13) & 0x1F] - 1,
        numbits: 8 - v13,
        bCheckRange: true);
  }
  v14 = 8 * net_blocksize.m_pParent->m_Value.m_nValue;
  if ( ((unsigned __int8 (*)(void))g_pNetworkSystem->IsDedicatedForXbox)() != 0 )
  {
    v15 = this->m_StreamVoice.m_iCurBit;
    if ( v15 > 0 && buf[4] + v15 < v14 )
    {
      v16 = 1;
LABEL_44:
      HIBYTE(buf[0]) = 1;
      goto LABEL_45;
    }
  }
  v16 = 0;
  v17 = this->m_StreamVoice.m_iCurBit < v14;
  HIBYTE(buf[0]) = 0;
  if ( !v17 )
    goto LABEL_44;
LABEL_45:
  v18 = net_compresspackets.m_pParent->m_Value.m_nValue == 0;
  LOBYTE(v38) = 0;
  if ( !v18 )
    LOBYTE(v38) = (buf[4] + 7) >> 3 >= net_compresspackets_minsize.m_pParent->m_Value.m_nValue;
  LODWORD(v40) = v37;
  bf_write::WriteByte(this: &v42, val: v37);
  if ( CNetworkSystem::ShouldChecksumPackets(this: g_pNetworkSystemInternal) )
  {
    v19 = CNetworkSystem::BufferToShortChecksum(
            this: g_pNetworkSystemInternal,
            pvData: (const void *)(v41 + buf[1]),
            nLength: ((buf[4] + 7) >> 3) - v41);
    bf_write::WriteUBitLong(this: &v42, curData: v19, numbits: 16, bCheckRange: true);
  }
  if ( v16 != 0 )
    p_m_StreamVoice = &this->m_StreamVoice;
  else
    p_m_StreamVoice = nullptr;
  v21 = g_pNetworkSystem->SendPacket(
          this: g_pNetworkSystem,
          a2: this,
          a3: this->m_Socket,
          a4: &this->remote_address,
          a5: (const unsigned __int8 *)buf[1],
          a6: (buf[4] + 7) >> 3,
          a7: p_m_StreamVoice,
          a8: v38,
          a9: 0);
  v41 = v21;
  if ( HIBYTE(buf[0]) != 0 || !g_pNetworkSystem->IsDedicatedForXbox(this: g_pNetworkSystem) )
    bf_write::Reset(this: &this->m_StreamVoice);
  v22 = net_showudp.m_pParent->m_Value.m_nValue;
  if ( v22 != 0
    && v22 != 2
    && (net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
     || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
  {
    memset(pDest, 0, sizeof(pDest));
    if ( net_compresspackets.m_pParent->m_Value.m_nValue != 0 && v21 != 0 )
    {
      v23 = (buf[4] + 7) >> 3;
      if ( v21 < v23 )
        V_snprintf(
          pDest,
          maxLen: 64,
          pFormat: " compression=%5u [%5.2f %%]",
          v21,
          (float)((float)((float)v21 * 100.0) / (float)v23));
    }
    v24 = g_pSteamSocketMgrInternal->GetSteamIDForRemote(this: g_pSteamSocketMgrInternal, a2: &this->remote_address);
    v38 = -14336;
    if ( v24 != 0 )
    {
      v38 = -10158081;
      v33 = v24;
      v25 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      v26 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                            a1: this,
                            a2: v25,
                            a3: v33,
                            a4: HIDWORD(v33));
      V_snprintf(pDest: v44, maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v26, v32, v34);
    }
    else
    {
      v27 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      v28 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v27);
      V_snprintf(pDest: v44, maxLen: 128, pFormat: "%12.12s %21.21s", v28, v35);
    }
    v29 = (buf[4] + 7) >> 3;
    v30 = ((double (__thiscall *)(INetworkSystem *, char *))g_pNetworkSystem->GetNetTime)(
            a1: g_pNetworkSystem,
            a2: pDest);
    ConColorMsg(
      a1: (const struct Color *)&v38,
      a2: "UDP -> %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f%s\n",
      v44,
      v29,
      this->m_nOutSequenceNr & 0x3F,
      this->m_nInSequenceNr & 0x3F,
      LOBYTE(v40) & 1,
      v30,
      v36);
    v21 = v41;
  }
  CNetChan::FlowNewPacket(
    this,
    flow: 0,
    seqnr: this->m_nOutSequenceNr,
    acknr: this->m_nInSequenceNr,
    nChoked: this->m_nChokedPackets,
    nDropped: 0,
    nSize: v21 + 28);
  CNetChan::FlowUpdate(this, flow: 0, addbytes: v21 + 28);
  if ( g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem) > this->m_flClearTime )
    this->m_flClearTime = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
  this->m_flClearTime = (float)((float)(v21 + 28) / (float)this->m_Rate) + this->m_flClearTime;
  *(float *)&v40 = net_maxcleartime.m_pParent->m_Value.m_fValue;
  if ( *(float *)&v40 > 0.0 )
  {
    v31 = g_pNetworkSystem->GetNetTime(this: g_pNetworkSystem);
    v40 = v31 + *(float *)&v40;
    if ( this->m_flClearTime > v40 )
      this->m_flClearTime = v40;
  }
  ++this->m_nOutSequenceNr;
  this->m_nChokedPackets = 0;
  return this->m_nOutSequenceNr - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100084D0
// Name: public: virtual bool CNetChan::RegisterMessage(class INetMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::RegisterMessage(CNetChan *this, INetMessage *msg)
{
  INetMessage *v2; // esi
  int v4; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  int v9; // [esp-4h] [ebp-Ch]

  v2 = msg;
  v4 = msg->GetType(this: msg);
  if ( CNetChan::FindMessage(this, type: v4) != nullptr )
    return 0;
  v6 = v2->GetType(this: v2);
  v7 = Q_log2(val: v6);
  if ( v7 > (1 << g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem)) - 1 )
  {
    v9 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
    v8 = v2->GetType(this: v2);
    _Error(
      a1: "Register Message:  Insufficient SetMessageTypeBits encoding bits specified for type %d, bits %d",
      v8,
      v9);
  }
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
    this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetMessages,
    elem: this->m_NetMessages.m_Size,
    src: (void (__cdecl *const *)(IConVar *, const char *, float))&msg);
  v2->SetNetChannel(this: v2, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008650
// Name: public: virtual bool CNetChan::SendFile(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendFile(CNetChan *this, char *filename, unsigned int transferID, BOOL bIsReplayDemoFile)
{
  bool result; // al

  if ( netadr_s::GetType(this: &this->remote_address) == NA_NULL )
    return true;
  result = g_pNetworkSystem->IsValidFileTransferExtension(this: g_pNetworkSystem, a2: filename);
  if ( result )
  {
    if ( CNetChan::CreateFragmentsFromFile(
           this,
           (CNetChan::DataFragments_t *)filename,
           stream: 1,
           transferID,
           bIsReplayDemoFile) != 0 )
    {
      if ( net_showfragments.m_pParent->m_Value.m_nValue == 2 )
        DevMsg(a1: "SendFile: %s (ID %i)\n", filename, transferID);
      return true;
    }
    else
    {
      this->DenyFile(this, a2: filename, a3: transferID, a4: bIsReplayDemoFile);
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100086E0
// Name: public: CNetChan::CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetChan::CNetChan(CNetChan *this)
{
  bf_write *p_m_StreamReliable; // ebp
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *m_WaitingList; // eax
  int i; // ecx

  p_m_StreamReliable = &this->m_StreamReliable;
  this->__vftable = (CNetChan_vtbl *)&CNetChan::`vftable';
  bf_write::bf_write(this: &this->m_StreamReliable);
  this->m_ReliableDataBuffer.m_pMemory = nullptr;
  this->m_ReliableDataBuffer.m_nAllocationCount = 0;
  this->m_ReliableDataBuffer.m_nGrowSize = 0;
  bf_write::bf_write(this: &this->m_StreamUnreliable);
  this->m_UnreliableDataBuffer.m_pMemory = nullptr;
  this->m_UnreliableDataBuffer.m_nAllocationCount = 0;
  this->m_UnreliableDataBuffer.m_nGrowSize = 0;
  bf_write::bf_write(this: &this->m_StreamVoice);
  this->m_VoiceDataBuffer.m_pMemory = nullptr;
  this->m_VoiceDataBuffer.m_nAllocationCount = 0;
  this->m_VoiceDataBuffer.m_nGrowSize = 0;
  netadr_s::SetIP(this: &this->remote_address, unIP: 0);
  netadr_s::SetPort(this: &this->remote_address, newport: 0);
  netadr_s::SetType(this: &this->remote_address, newtype: NA_IP);
  m_WaitingList = this->m_WaitingList;
  for ( i = 1; i >= 0; --i )
  {
    m_WaitingList->m_Memory.m_pMemory = nullptr;
    m_WaitingList->m_Memory.m_nAllocationCount = 0;
    m_WaitingList->m_Memory.m_nGrowSize = 0;
    m_WaitingList->m_Size = 0;
    m_WaitingList->m_pElements = nullptr;
    ++m_WaitingList;
  }
  this->m_NetMessages.m_Memory.m_pMemory = nullptr;
  this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
  this->m_NetMessages.m_Memory.m_nGrowSize = 0;
  this->m_NetMessages.m_Size = 0;
  this->m_NetMessages.m_pElements = nullptr;
  this->m_SplitPlayers.m_LessFunc = CDefOps<int>::LessFunc;
  this->m_SplitPlayers.m_Elements.m_pMemory = nullptr;
  this->m_SplitPlayers.m_Elements.m_nAllocationCount = 0;
  this->m_SplitPlayers.m_Elements.m_nGrowSize = 0;
  this->m_SplitPlayers.m_NumElements = 0;
  this->m_SplitPlayers.m_Root = -1;
  this->m_SplitPlayers.m_FirstFree = -1;
  this->m_SplitPlayers.m_LastAlloc.index = -1;
  this->m_SplitPlayers.m_pElements = this->m_SplitPlayers.m_Elements.m_pMemory;
  this->m_pActiveChannel = this;
  this->m_nSplitPacketSequence = 1;
  this->m_nMaxRoutablePayloadSize = 1200;
  this->m_bProcessingMessages = false;
  this->m_bShouldDelete = false;
  this->m_bStopProcessing = false;
  this->m_Socket = -1;
  netadr_s::Clear(this: &this->remote_address);
  this->last_received = 0.0;
  this->connect_time = 0.0;
  V_strncpy(pDest: this->m_Name, pSrc: str, maxLen: 32);
  this->m_MessageHandler = nullptr;
  this->m_DemoRecorder = nullptr;
  bf_write::SetDebugName(this: &this->m_StreamUnreliable, pDebugName: "netchan_t::unreliabledata");
  bf_write::SetDebugName(this: p_m_StreamReliable, pDebugName: "netchan_t::reliabledata");
  this->m_Timeout = 300.0;
  this->m_Rate = 10000;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_ChallengeNr = 0;
  this->m_MaxReliablePayloadSize = 96000;
  this->m_FileRequestCounter = 0;
  this->m_bFileBackgroundTranmission = true;
  this->m_bUseCompression = false;
  this->m_nQueuedPackets = 0;
  this->m_flRemoteFrameTime = 0.0;
  this->m_flRemoteFrameTimeStdDeviation = 0.0;
  this->m_bUsesMaxRoutablePayload = false;
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 56);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100088F0
// Name: public: virtual CNetChan::~CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetChan::~CNetChan(CNetChan *this@<ecx>, bool a2@<bpl>)
{
  CNetChan::DataFragments_t *m_ReceiveList; // esi
  int i; // ebp
  bool v5; // sf
  void *file; // eax
  char *v7; // [esp+0h] [ebp-10h]

  this->__vftable = (CNetChan_vtbl *)&CNetChan::`vftable';
  CNetChan::Shutdown(this, a2, a3: (int)this, pReason: "NetChannel removed.", pStr: v7);
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::~CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>(this: &this->m_SplitPlayers);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetMessages);
  m_ReceiveList = this->m_ReceiveList;
  for ( i = 1; i >= 0; --i )
  {
    m_ReceiveList = (CNetChan::DataFragments_t *)((char *)m_ReceiveList - 20);
    v5 = *(int *)&m_ReceiveList->filename[4] < 0;
    *(_DWORD *)&m_ReceiveList->filename[8] = 0;
    if ( !v5 )
    {
      if ( m_ReceiveList->file != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ReceiveList->file);
        m_ReceiveList->file = nullptr;
      }
      *(_DWORD *)m_ReceiveList->filename = 0;
    }
    v5 = *(int *)&m_ReceiveList->filename[4] < 0;
    file = m_ReceiveList->file;
    *(_DWORD *)&m_ReceiveList->filename[12] = m_ReceiveList->file;
    if ( !v5 )
    {
      if ( file != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: file);
        m_ReceiveList->file = nullptr;
      }
      *(_DWORD *)m_ReceiveList->filename = 0;
    }
  }
  if ( this->m_VoiceDataBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_VoiceDataBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VoiceDataBuffer.m_pMemory);
      this->m_VoiceDataBuffer.m_pMemory = nullptr;
    }
    this->m_VoiceDataBuffer.m_nAllocationCount = 0;
  }
  if ( this->m_UnreliableDataBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_UnreliableDataBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UnreliableDataBuffer.m_pMemory);
      this->m_UnreliableDataBuffer.m_pMemory = nullptr;
    }
    this->m_UnreliableDataBuffer.m_nAllocationCount = 0;
  }
  if ( this->m_ReliableDataBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_ReliableDataBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReliableDataBuffer.m_pMemory);
      this->m_ReliableDataBuffer.m_pMemory = nullptr;
    }
    this->m_ReliableDataBuffer.m_nAllocationCount = 0;
  }
  this->__vftable = (CNetChan_vtbl *)&INetChannel::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10008A00
// Name: public: virtual void CNetChan::AttachSplitPlayer(int,class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::AttachSplitPlayer(CNetChan *this, INetChannel *nSplitPlayerSlot, INetChannel *pChannel)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  CNetChan::SplitPlayer_t search; // [esp+0h] [ebp-Ch] BYREF
  INetChannel *v5; // [esp+8h] [ebp-4h]

  search.m_pChannel = nSplitPlayerSlot;
  p_m_SplitPlayers = &this->m_SplitPlayers;
  v5 = pChannel;
  if ( CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         search: (const CNetChan::SplitPlayer_t *)&search.m_pChannel) == 0xFFFF )
    CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Insert(
      this: p_m_SplitPlayers,
      insert: (const CNetChan::SplitPlayer_t *)&search.m_pChannel);
}

//------------------------------------------------------------------------------
// Address: 0x10008A40
// Name: public: virtual void CNetChan::DetachSplitPlayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DetachSplitPlayer(CNetChan *this, INetChannel *nSplitPlayerSlot)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v5; // eax
  CNetChan::SplitPlayer_t search; // [esp+4h] [ebp-Ch] BYREF
  int v7; // [esp+Ch] [ebp-4h]

  p_m_SplitPlayers = &this->m_SplitPlayers;
  v7 = 0;
  search.m_pChannel = nSplitPlayerSlot;
  v3 = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         search: (const CNetChan::SplitPlayer_t *)&search.m_pChannel);
  v4 = v3;
  if ( v3 != 0xFFFF && v3 != 0xFFFF )
  {
    CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_SplitPlayers,
      elem: v3);
    v5 = v4;
    p_m_SplitPlayers->m_Elements.m_pMemory[v5].m_Left = v4;
    p_m_SplitPlayers->m_Elements.m_pMemory[v5].m_Right = p_m_SplitPlayers->m_FirstFree;
    --p_m_SplitPlayers->m_NumElements;
    p_m_SplitPlayers->m_FirstFree = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F7D0
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<struct CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001A860
// Name: public: virtual void CNetChan::SetUsesMaxRoutablePayload(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetUsesMaxRoutablePayload(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10003820
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CNetChan::SplitPlayer_t,unsigned short,bool (*)(struct CNetChan::SplitPlayer_t const __near &,struct CNetChan::SplitPlayer_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *__thiscall CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *)&`CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
