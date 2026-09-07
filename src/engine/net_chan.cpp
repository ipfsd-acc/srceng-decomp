// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/net_chan.cpp
// Functions: 111
// ============================================================

#include "engine\net_chan.h"

//------------------------------------------------------------------------------
// Address: 0x1006F300
// Name: public: virtual bool CNetChan::IsPlayback(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsPlayback(CEngineClient *this)
{
  return demoplayer->IsPlayingBack(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x101A69D0
// Name: void LogMultiline(bool,char const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl LogMultiline(bool input, const char *label, const char *data, unsigned int len)
{
  unsigned int i; // ebx
  int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // esi
  const char *v8; // ebx
  char v9; // al
  int v10; // eax
  char v11; // cl
  _BYTE hex_line[81]; // [esp+0h] [ebp-5Ch] OVERLAPPED BYREF
  int v13; // [esp+54h] [ebp-8h]
  const char *direction; // [esp+58h] [ebp-4h]
  unsigned int line_len; // [esp+64h] [ebp+8h]

  direction = " << ";
  if ( !input )
    direction = " >> ";
  for ( i = len; i != 0; len = i )
  {
    memset(hex_line, 32, sizeof(hex_line));
    if ( i >= 0x18 )
    {
      line_len = 24;
      v5 = 24;
    }
    else
    {
      v5 = i;
      line_len = i;
    }
    v6 = 0;
    if ( v5 != 0 )
    {
      v13 = &hex_line[56] - data;
      do
      {
        v7 = (unsigned __int8)data[v6];
        v8 = &data[v6];
        if ( isprint(c: v7) == 0 || iscntrl(c: v7) != 0 )
          v9 = 46;
        else
          v9 = *v8;
        v8[v13] = v9;
        v10 = (v6 >> 2) + 2 * v6;
        v11 = HEX[v7 & 0xF];
        ++v6;
        hex_line[v10] = HEX[v7 >> 4];
        hex_line[v10 + 1] = v11;
      }
      while ( v6 < line_len );
      v5 = line_len;
      i = len;
    }
    hex_line[80] = 0;
    hex_line[55] = 0;
    _Msg(a1: "%s %s %s %s \n", label, direction, &hex_line[56], hex_line);
    data += v5;
    i -= v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6AF0
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
// Address: 0x101A6B90
// Name: public: void CNetchanParanoidMode::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::Init(CNetchanParanoidMode *this)
{
  CNetchanParanoidMode::MessageItem_t *v2; // eax
  int v3; // edi
  int *p_m_nType; // esi
  CNetchanParanoidMode::MessageItem_t *v6; // [esp+Ch] [ebp-4h]

  this->m_bInitialized = true;
  this->m_pRawData = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17700u);
  v2 = (CNetchanParanoidMode::MessageItem_t *)MemAlloc_Alloc(nSize: 0x13800u);
  v6 = v2;
  if ( v2 != nullptr )
  {
    v3 = 255;
    p_m_nType = &v2->m_nType;
    do
    {
      *(p_m_nType - 2) = 0;
      *(p_m_nType - 1) = 0;
      *p_m_nType = 0;
      p_m_nType[1] = 0;
      p_m_nType[2] = 0;
      p_m_nType[3] = -1;
      *((_BYTE *)p_m_nType + 144) = 0;
      *((_BYTE *)p_m_nType + 176) = 0;
      _V_memset(dest: p_m_nType + 4, fill: 0, count: 128);
      p_m_nType += 78;
      --v3;
    }
    while ( v3 >= 0 );
    this->m_pPacketMessages = v6;
  }
  else
  {
    this->m_pPacketMessages = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6C30
// Name: bool ShouldChecksumPackets(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __cdecl ShouldChecksumPackets()
{
  return NET_IsMultiplayer();
}

//------------------------------------------------------------------------------
// Address: 0x101A6C40
// Name: IsSafeFileToDownload
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsSafeFileToDownload@<al>(const char *pFilename@<eax>)
{
  const char *v2; // eax
  const char *v3; // esi
  bool result; // al

  result = false;
  if ( _V_strstr(s1: pFilename, search: ":") == nullptr && _V_strstr(s1: pFilename, search: "..") == nullptr )
  {
    v2 = _V_strrchr(s: pFilename, c: 46);
    v3 = v2;
    if ( v2 != nullptr
      && (_V_stricmp(s1: v2, s2: ".layout") == 0
       || _V_strlen(str: v3) == 4
       && _V_stricmp(s1: v3, s2: ".cfg") != 0
       && _V_stricmp(s1: v3, s2: ".lst") != 0
       && _V_stricmp(s1: v3, s2: ".exe") != 0
       && _V_stricmp(s1: v3, s2: ".vbs") != 0
       && _V_stricmp(s1: v3, s2: ".com") != 0
       && _V_stricmp(s1: v3, s2: ".bat") != 0
       && _V_stricmp(s1: v3, s2: ".dll") != 0
       && _V_stricmp(s1: v3, s2: ".ini") != 0
       && _V_stricmp(s1: v3, s2: ".log") != 0) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6D60
// Name: public: virtual bool CNetChan::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsLoopback(CNetChan *this)
{
  return netadr_s::IsLoopback(this: &this->remote_address);
}

//------------------------------------------------------------------------------
// Address: 0x101A6D70
// Name: public: virtual bool CNetChan::IsNull(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsNull(CNetChan *this)
{
  return CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x101A6D90
// Name: private: void CNetChan::UncompressFragments(struct CNetChan::dataFragments_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UncompressFragments(CNetChan *this, CNetChan::dataFragments_s *data)
{
  CNetChan::dataFragments_s *v2; // esi
  char *v3; // edi
  char *buffer; // eax
  CNetChan::dataFragments_s *v5; // eax
  unsigned int bytes; // [esp-Ch] [ebp-10h]

  v2 = data;
  if ( data->isCompressed )
  {
    v3 = (char *)MemAlloc_Alloc(nSize: 4 * ((data->nUncompressedSize + 3) >> 2));
    buffer = v2->buffer;
    bytes = v2->bytes;
    data = (CNetChan::dataFragments_s *)v2->nUncompressedSize;
    NET_BufferToBufferDecompress(dest: v3, destLen: (unsigned int *)&data, source: buffer, sourceLen: bytes);
    free(pMem: v2->buffer);
    v5 = data;
    v2->buffer = v3;
    v2->bytes = (unsigned int)v5;
    v2->isCompressed = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6E10
// Name: public: virtual void CNetChan::RequestFile_OLD(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RequestFile_OLD(CNetChan *this, const char *filename, const char *transferID)
{
  _Error(a1: "Called RequestFile_OLD");
}

//------------------------------------------------------------------------------
// Address: 0x101A6E20
// Name: public: virtual void CNetChan::ResetStreaming(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ResetStreaming(CNetChan *this)
{
  this->m_SteamType = 0;
  this->m_StreamLength = 0;
  this->m_StreamReceived = 0;
  this->m_StreamSeqNr = 0;
  this->m_SteamFile[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6E50
// Name: public: virtual void CNetChan::SetChallengeNr(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetChallengeNr(CNetChan *this, unsigned int chnr)
{
  this->m_ChallengeNr = chnr;
}

//------------------------------------------------------------------------------
// Address: 0x101A6E60
// Name: public: virtual unsigned int CNetChan::GetChallengeNr(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::GetChallengeNr(CNetChan *this)
{
  return this->m_ChallengeNr;
}

//------------------------------------------------------------------------------
// Address: 0x101A6E70
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
// Address: 0x101A6E90
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
// Address: 0x101A6EB0
// Name: public: virtual void CNetChan::SetDemoRecorder(class IDemoRecorder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDemoRecorder(CNetChan *this, IDemoRecorder *recorder)
{
  this->m_DemoRecorder = recorder;
}

//------------------------------------------------------------------------------
// Address: 0x101A6EC0
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
// Address: 0x101A6F20
// Name: public: virtual void CNetChan::SetFileTransmissionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetFileTransmissionMode(CNetChan *this, bool bBackgroundMode)
{
  this->m_bFileBackgroundTranmission = bBackgroundMode;
}

//------------------------------------------------------------------------------
// Address: 0x101A6F30
// Name: public: virtual void CNetChan::SetCompressionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetCompressionMode(CNetChan *this, bool bUseCompression)
{
  this->m_bUseCompression = bUseCompression;
}

//------------------------------------------------------------------------------
// Address: 0x101A6F40
// Name: public: virtual char const __near * CNetChan::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNetChan::GetName(CNetChan *this)
{
  return this->m_Name;
}

//------------------------------------------------------------------------------
// Address: 0x101A6F50
// Name: public: virtual char const __near * CNetChan::GetAddress(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetChan::GetAddress(CNetChan *this)
{
  return netadr_s::ToString(this: &this->remote_address, baseOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x101A6F60
// Name: public: virtual int CNetChan::GetDropNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDropNumber(CNetChan *this)
{
  return this->m_PacketDrop;
}

//------------------------------------------------------------------------------
// Address: 0x101A6F70
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
  int v7; // edx
  CNetChan::netflow_t *v9; // ecx
  int currentindex; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  long double v14; // st7
  BOOL v15; // eax
  int v16; // ecx
  bool v17; // zf
  float *v18; // ecx
  long double v19; // st7
  CNetChan::netflow_t *pflow; // [esp+10h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v7 = seqnr;
  v9 = &this->m_DataFlow[flow];
  currentindex = v9->currentindex;
  v11 = 0;
  v12 = 0;
  pflow = v9;
  if ( seqnr > currentindex )
  {
    v13 = currentindex + 1;
    i = v13;
    if ( v13 <= seqnr )
    {
      v21 = seqnr - v13;
      while ( 1 )
      {
        v14 = net_time;
        v11 = (int)&v9->frame_headers[v13 & 0x7F];
        v12 = (int)&v9->frames[v13 & 0x7F];
        *(_BYTE *)(v11 + 10) = 0;
        *(float *)v11 = v14;
        *(_DWORD *)(v11 + 4) = 0;
        *(_DWORD *)(v11 + 12) = -1082130432;
        *(float *)(v12 + 4) = this->GetAvgLatency(this, a2: 0);
        *(_WORD *)(v11 + 8) = 0;
        *(_DWORD *)v12 = 0;
        *(_DWORD *)(v12 + 8) = 0;
        _V_memset(dest: (void *)(v12 + 12), fill: 0, count: 30);
        if ( v21 < nDropped + nChoked )
        {
          if ( v21 >= nChoked )
            *(_DWORD *)v12 = 1;
          else
            *(_WORD *)(v11 + 8) = 1;
        }
        ++i;
        --v21;
        if ( i > seqnr )
          break;
        v9 = pflow;
        LOBYTE(v13) = i;
      }
    }
    *(_DWORD *)v12 = nDropped;
    *(_WORD *)(v11 + 8) = nChoked;
    *(_DWORD *)(v11 + 4) = nSize;
    *(_BYTE *)(v11 + 10) = 1;
    *(float *)(v12 + 4) = this->GetAvgLatency(this, a2: 0);
    v9 = pflow;
    v7 = seqnr;
    *(float *)(v12 + 8) = this->m_flInterpolationAmount;
  }
  ++v9->totalpackets;
  v9->currentindex = v7;
  v9->currentframe = (CNetChan::netframe_s *)v12;
  v15 = flow == 0;
  if ( acknr > this->m_DataFlow[v15].currentindex - 128 )
  {
    v16 = v15 * 7724 + 16 * (acknr & 0x7F);
    v17 = !*(&this->m_DataFlow[0].frame_headers[0].valid + v16);
    v18 = (float *)((char *)&this->m_DataFlow[0].frame_headers[0].time + v16);
    if ( !v17 && v18[3] == -1.0 )
    {
      v19 = net_time - *v18;
      v18[3] = v19;
      if ( v19 < 0.0 )
        v18[3] = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7110
// Name: private: void CNetChan::FlowUpdate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::FlowUpdate(CNetChan *this, int flow, int addbytes)
{
  CNetChan::netflow_t *v3; // edi
  float v4; // xmm2_4
  int v5; // ecx
  int v6; // edx
  float v7; // xmm4_4
  int v8; // esi
  float v9; // xmm0_4
  float *p_choked; // eax
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // eax
  float v21; // xmm0_4
  float avglatency; // xmm1_4
  float v23; // xmm4_4
  int i; // [esp+4h] [ebp-4h]
  int totalinvalid; // [esp+10h] [ebp+8h]
  int totallatencycount; // [esp+14h] [ebp+Ch]

  v3 = &this->m_DataFlow[flow];
  v3->totalbytes += addbytes;
  if ( v3->nextcompute <= net_time )
  {
    v4 = 3.4028235e38;
    v5 = 0;
    v3->nextcompute = net_time + 0.25;
    v6 = 0;
    totalinvalid = 0;
    v7 = 0.0;
    totallatencycount = 0;
    v8 = 0;
    v9 = 0.0;
    p_choked = (float *)&v3->frame_headers[0].choked;
    for ( i = 32; i != 0; --i )
    {
      if ( *((_BYTE *)p_choked + 2) != 0 )
      {
        v11 = *(p_choked - 2);
        if ( v4 > v11 )
          v4 = *(p_choked - 2);
        if ( v11 > v9 )
          v9 = *(p_choked - 2);
        v5 += *((_DWORD *)p_choked - 1);
        v12 = p_choked[1];
        ++v6;
        v8 += *(__int16 *)p_choked;
        if ( v12 > -1.0 )
        {
          ++totallatencycount;
          v7 = v12 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 18) != 0 )
      {
        v13 = p_choked[2];
        if ( v4 > v13 )
          v4 = p_choked[2];
        if ( v13 > v9 )
          v9 = p_choked[2];
        v5 += *((_DWORD *)p_choked + 3);
        v14 = p_choked[5];
        ++v6;
        v8 += *((__int16 *)p_choked + 8);
        if ( v14 > -1.0 )
        {
          ++totallatencycount;
          v7 = v14 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 34) != 0 )
      {
        v15 = p_choked[6];
        if ( v4 > v15 )
          v4 = p_choked[6];
        if ( v15 > v9 )
          v9 = p_choked[6];
        v5 += *((_DWORD *)p_choked + 7);
        v16 = p_choked[9];
        ++v6;
        v8 += *((__int16 *)p_choked + 16);
        if ( v16 > -1.0 )
        {
          ++totallatencycount;
          v7 = v16 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 50) != 0 )
      {
        v17 = p_choked[10];
        if ( v4 > v17 )
          v4 = p_choked[10];
        if ( v17 > v9 )
          v9 = p_choked[10];
        v5 += *((_DWORD *)p_choked + 11);
        v18 = p_choked[13];
        ++v6;
        v8 += *((__int16 *)p_choked + 24);
        if ( v18 > -1.0 )
        {
          ++totallatencycount;
          v7 = v18 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      p_choked += 16;
    }
    v19 = v9 - v4;
    if ( v19 > 0.0 )
    {
      v3->avgbytespersec = (float)((float)((float)v5 * (float)(1.0 / v19)) * 0.25) + (float)(v3->avgbytespersec * 0.75);
      v3->avgpacketspersec = (float)((float)((float)v6 * (float)(1.0 / v19)) * 0.25)
                           + (float)(v3->avgpacketspersec * 0.75);
    }
    v20 = totalinvalid + v6;
    if ( totalinvalid + v6 > 0 )
    {
      v21 = (float)((float)((float)(totalinvalid - v8) / (float)v20) * 0.25) + (float)(v3->avgloss * 0.75);
      v3->avgloss = v21;
      if ( v21 < 0.0 )
        v3->avgloss = 0.0;
      v3->avgchoke = (float)((float)((float)v8 / (float)v20) * 0.25) + (float)(v3->avgchoke * 0.75);
    }
    if ( totallatencycount > 0 )
    {
      avglatency = v3->avglatency;
      v23 = v7 / (float)totallatencycount;
      v3->latency = v23;
      v3->avglatency = (float)(avglatency * 0.75) + (float)(v23 * 0.25);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7380
// Name: public: virtual void CNetChan::SetChoked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetChoked(CNetChan *this)
{
  ++this->m_nOutSequenceNr;
  ++this->m_nChokedPackets;
}

//------------------------------------------------------------------------------
// Address: 0x101A7390
// Name: public: virtual bool CNetChan::Transmit(bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetChan::Transmit(CNetChan *this, bool onlyReliable)
{
  if ( onlyReliable )
    bf_write::Reset(this: &this->m_StreamUnreliable);
  return this->SendDatagram(this, a2: nullptr) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A73C0
// Name: unsigned short BufferToShortChecksum(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl BufferToShortChecksum(const void *pvData, const void *nLength)
{
  unsigned int v3; // [esp+0h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &v3);
  CRC32_ProcessBuffer(pulCRC: &v3, pBuffer: pvData, nBuffer: (int)nLength);
  CRC32_Final(pulCRC: &v3);
  return v3 ^ HIWORD(v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A7400
// Name: public: virtual bool CNetChan::SetActiveChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SetActiveChannel(CNetChan *this, INetChannel *pNewChannel)
{
  this->m_pActiveChannel = pNewChannel;
  return pNewChannel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A7420
// Name: public: virtual int CNetChan::GetNumBitsWritten(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetNumBitsWritten(CNetChan *this, bool bReliable)
{
  if ( bReliable )
    return this->m_StreamReliable.m_iCurBit;
  else
    return this->m_StreamUnreliable.m_iCurBit;
}

//------------------------------------------------------------------------------
// Address: 0x101A7440
// Name: public: virtual bool CNetChan::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNetChan::SendNetMsg@<al>(
        CNetChan *this@<ecx>,
        int a2@<edi>,
        INetMessage *msg,
        bool bForceReliable,
        bool bVoice)
{
  bf_write *p_m_StreamUnreliable; // esi
  bool v8; // bl
  const char *Flags; // eax
  int v10; // [esp-Ch] [ebp-10h]

  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL )
    return 1;
  p_m_StreamUnreliable = &this->m_StreamUnreliable;
  if ( ((unsigned __int8 (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2) != 0 || bForceReliable )
    p_m_StreamUnreliable = &this->m_StreamReliable;
  if ( bVoice )
    p_m_StreamUnreliable = &this->m_StreamVoice;
  v8 = msg->WriteToBuffer(this: msg, a2: p_m_StreamUnreliable);
  if ( !v8 )
  {
    v10 = (p_m_StreamUnreliable->m_nDataBits + 7) / 8;
    Flags = (const char *)ConCommandBase::GetFlags(this: (CVTFTexture *)p_m_StreamUnreliable);
    _Warning(a1: "SendNetMsg: stream[%s] buffer overflow (maxsize = %d)!\n", Flags, v10);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101A74D0
// Name: public: virtual bool CNetChan::SendData(class bf_write __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendData(CNetChan *this, bf_write *msg, bool bReliable)
{
  int m_iCurBit; // edx
  bf_write *p_m_StreamUnreliable; // ecx

  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL )
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
      ConMsg(a1: "ERROR! SendData reliabe data too big (%i)", (m_iCurBit + 7) >> 3);
    return false;
  }
  p_m_StreamUnreliable = &this->m_StreamReliable;
  goto LABEL_10;
}

//------------------------------------------------------------------------------
// Address: 0x101A7560
// Name: private: bool CNetChan::SendReliableViaStream(struct CNetChan::dataFragments_s __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendReliableViaStream(CNetChan *this, CNetChan::dataFragments_s *data)
{
  int numFragments; // edx
  const char *v4; // eax
  unsigned int bytes; // [esp-8h] [ebp-48h]
  int m_nOutSequenceNr; // [esp-4h] [ebp-44h]
  char headerBuf[32]; // [esp+8h] [ebp-38h] BYREF
  bf_write header; // [esp+28h] [ebp-18h] BYREF

  bf_write::bf_write(this: &header, pDebugName: "outDataHeader", pData: headerBuf, nBytes: 32, nBits: -1);
  numFragments = data->numFragments;
  data->transferID = this->m_nOutSequenceNr;
  data->pendingFragments = numFragments;
  bf_write::WriteByte(this: &header, val: 2u);
  bf_write::WriteWord(this: &header, val: data->bytes);
  bf_write::WriteLong(this: &header, val: data->transferID);
  if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nOutSequenceNr = this->m_nOutSequenceNr;
    bytes = data->bytes;
    v4 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP -> %s: sz=%i seq=%i\n", v4, bytes, m_nOutSequenceNr);
  }
  NET_SendStream(
    nSock: this->m_StreamSocket,
    buf: (const char *)header.m_pData,
    len: (header.m_iCurBit + 7) >> 3,
    flags: 0);
  return NET_SendStream(nSock: this->m_StreamSocket, buf: data->buffer, len: data->bytes, flags: 0) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7640
// Name: private: bool CNetChan::SendReliableAcknowledge(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendReliableAcknowledge(CNetChan *this, int seqnr)
{
  const char *v3; // eax
  char headerBuf[32]; // [esp+8h] [ebp-38h] BYREF
  bf_write header; // [esp+28h] [ebp-18h] BYREF

  bf_write::bf_write(this: &header, pDebugName: "outAcknHeader", pData: headerBuf, nBytes: 32, nBits: -1);
  bf_write::WriteByte(this: &header, val: 4u);
  bf_write::WriteLong(this: &header, val: seqnr);
  if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP -> %s: ACKN seq=%i\n", v3, seqnr);
  }
  return NET_SendStream(
           nSock: this->m_StreamSocket,
           buf: (const char *)header.m_pData,
           len: (header.m_iCurBit + 7) >> 3,
           flags: 0) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A76D0
// Name: public: virtual int CNetChan::GetDataRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDataRate(CNetChan *this)
{
  return this->m_Rate;
}

//------------------------------------------------------------------------------
// Address: 0x101A76E0
// Name: public: virtual float CNetChan::GetTimeConnected(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeConnected(CNetChan *this)
{
  long double v1; // st7

  v1 = net_time - this->connect_time;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7720
// Name: public: virtual class INetChannelHandler __near * CNetChan::GetMsgHandler(void)const
// Source: json
//------------------------------------------------------------------------------
INetChannelHandler *__thiscall CNetChan::GetMsgHandler(CNetChan *this)
{
  return this->m_MessageHandler;
}

//------------------------------------------------------------------------------
// Address: 0x101A7730
// Name: public: virtual bool CNetChan::IsTimedOut(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsTimedOut(CNetChan *this)
{
  return this->m_Timeout != -1.0 && net_time > this->last_received + this->m_Timeout;
}

//------------------------------------------------------------------------------
// Address: 0x101A7780
// Name: public: virtual bool CNetChan::IsTimingOut(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsTimingOut(CNetChan *this)
{
  return this->m_Timeout != -1.0 && net_time > this->last_received + 4.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A77C0
// Name: public: virtual float CNetChan::GetTimeoutSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeoutSeconds(CNetChan *this)
{
  return this->m_Timeout;
}

//------------------------------------------------------------------------------
// Address: 0x101A77D0
// Name: public: virtual float CNetChan::GetTimeSinceLastReceived(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeSinceLastReceived(CNetChan *this)
{
  long double v1; // st7

  v1 = net_time - this->last_received;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7810
// Name: public: virtual bool CNetChan::IsOverflowed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsOverflowed(CNetChan *this)
{
  return this->m_StreamReliable.m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101A7820
// Name: public: virtual void CNetChan::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Reset(CNetChan *this)
{
  bf_write::Reset(this: &this->m_StreamUnreliable);
  bf_write::Reset(this: &this->m_StreamReliable);
  this->m_fClearTime = 0.0;
  this->m_nChokedPackets = 0;
  this->m_nSplitPacketSequence = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7850
// Name: public: virtual int CNetChan::GetSocket(void)const
// Source: json
//------------------------------------------------------------------------------
DEMOACTIONTIMINGTYPE __thiscall CNetChan::GetSocket(CBaseDemoAction *this)
{
  return this->m_Timing;
}

//------------------------------------------------------------------------------
// Address: 0x101A7860
// Name: public: virtual float CNetChan::GetAvgData(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgbytespersec;
}

//------------------------------------------------------------------------------
// Address: 0x101A7880
// Name: public: virtual float CNetChan::GetAvgPackets(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgpacketspersec;
}

//------------------------------------------------------------------------------
// Address: 0x101A78A0
// Name: public: virtual int CNetChan::GetTotalData(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalbytes;
}

//------------------------------------------------------------------------------
// Address: 0x101A78C0
// Name: public: virtual int CNetChan::GetTotalPackets(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalpackets;
}

//------------------------------------------------------------------------------
// Address: 0x101A78E0
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
// Address: 0x101A7910
// Name: public: virtual int CNetChan::GetBufferSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetBufferSize(CCallback<CSteam3Client,GameServerChangeRequested_t,0> *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x101A7920
// Name: public: virtual bool CNetChan::IsValidPacket(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsValidPacket(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].valid;
}

//------------------------------------------------------------------------------
// Address: 0x101A7950
// Name: public: virtual float CNetChan::GetPacketTime(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetPacketTime(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].time;
}

//------------------------------------------------------------------------------
// Address: 0x101A7980
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
  int v5; // esi
  int v6; // eax
  CNetChan::netframe_header_s *v7; // esi
  CNetChan::netframe_s *v8; // eax

  v5 = frame_number & 0x7F;
  v6 = v5;
  v7 = &this->m_DataFlow[flow].frame_headers[v5];
  v8 = &this->m_DataFlow[flow].frames[v6];
  if ( pnLatencyMsecs != nullptr )
  {
    if ( v8->dropped != 0 )
      *pnLatencyMsecs = 9999;
    else
      *pnLatencyMsecs = (int)(float)(v8->avg_latency * 1000.0);
  }
  if ( pnChoke != nullptr )
    *pnChoke = v7->choked;
}

//------------------------------------------------------------------------------
// Address: 0x101A79F0
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
// Address: 0x101A7A20
// Name: public: virtual float CNetChan::GetLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].latency;
}

//------------------------------------------------------------------------------
// Address: 0x101A7A40
// Name: public: virtual float CNetChan::GetAvgChoke(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgChoke(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgchoke;
}

//------------------------------------------------------------------------------
// Address: 0x101A7A60
// Name: public: virtual float CNetChan::GetAvgLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avglatency;
}

//------------------------------------------------------------------------------
// Address: 0x101A7A80
// Name: public: virtual float CNetChan::GetAvgLoss(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLoss(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgloss;
}

//------------------------------------------------------------------------------
// Address: 0x101A7AA0
// Name: public: virtual float CNetChan::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CNetChan::GetTime(CNetChan *this)
{
  return net_time;
}

//------------------------------------------------------------------------------
// Address: 0x101A7AB0
// Name: public: virtual float CNetChan::GetCommandInterpolationAmount(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetCommandInterpolationAmount(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frames[frame_number & 0x7F].m_flInterpolationAmount;
}

//------------------------------------------------------------------------------
// Address: 0x101A7AE0
// Name: public: virtual int CNetChan::GetPacketBytes(int,int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetPacketBytes(CNetChan *this, int flow, char frame_number, int group)
{
  if ( group < 15 )
    return (this->m_DataFlow[flow].frames[frame_number & 0x7F].msggroups[group] + 7) >> 3;
  else
    return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].size;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B40
// Name: public: virtual void CNetChan::UpdateMessageStats(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateMessageStats(CNetChan *this, int msggroup, int bits)
{
  CNetChan::netframe_s *currentframe; // eax

  currentframe = this->m_DataFlow[1].currentframe;
  this->m_MsgStats[msggroup] += bits;
  if ( currentframe != nullptr )
    currentframe->msggroups[msggroup] += bits;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B70
// Name: public: void CNetChan::IncrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::IncrementQueuedPackets(CNetChan *this)
{
  ++this->m_nQueuedPackets;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B80
// Name: public: void CNetChan::DecrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DecrementQueuedPackets(CNetChan *this)
{
  if ( --this->m_nQueuedPackets < 0 )
    this->m_nQueuedPackets = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A7BA0
// Name: public: virtual void CNetChan::SetInterpolationAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetInterpolationAmount(CNetChan *this, float flInterpolationAmount)
{
  this->m_flInterpolationAmount = flInterpolationAmount;
}

//------------------------------------------------------------------------------
// Address: 0x101A7BC0
// Name: public: virtual void CNetChan::SetRemoteFramerate(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetRemoteFramerate(CNetChan *this, float flFrameTime, float flFrameTimeStdDeviation)
{
  this->m_flRemoteFrameTime = flFrameTime;
  this->m_flRemoteFrameTimeStdDeviation = flFrameTimeStdDeviation;
}

//------------------------------------------------------------------------------
// Address: 0x101A7BF0
// Name: public: virtual void CNetChan::SetMaxRoutablePayloadSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxRoutablePayloadSize(CNetChan *this, int nSplitSize)
{
  const char *v3; // eax

  if ( this->m_nMaxRoutablePayloadSize != nSplitSize )
  {
    v3 = (const char *)this->GetName(this);
    DevMsg(
      a1: "Setting max routable payload size from %d to %d for %s\n",
      this->m_nMaxRoutablePayloadSize,
      nSplitSize,
      v3);
  }
  this->m_nMaxRoutablePayloadSize = nSplitSize;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C30
// Name: public: virtual int CNetChan::GetMaxRoutablePayloadSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetMaxRoutablePayloadSize(CNetChan *this)
{
  return this->m_nMaxRoutablePayloadSize;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C40
// Name: public: int CNetChan::IncrementSplitPacketSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::IncrementSplitPacketSequence(CNetChan *this)
{
  int result; // eax

  result = this->m_nSplitPacketSequence + 1;
  this->m_nSplitPacketSequence = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C50
// Name: public: static bool CNetChan::IsValidFileTransferExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CNetChan::IsValidFileTransferExtension(char *pFilename)
{
  const char *v1; // eax
  const char *v2; // esi

  strrchr(string: (unsigned __int8 *)pFilename, chr: 0x2Eu);
  v2 = v1;
  if ( v1 == nullptr )
    return false;
  if ( V_strcasecmp(s1: v1, s2: ".layout") == 0 )
    return true;
  return strlen(v2) - 3 <= 1
      && V_strcasecmp(s1: v2, s2: ".cfg") != 0
      && V_strcasecmp(s1: v2, s2: ".lst") != 0
      && V_strcasecmp(s1: v2, s2: ".exe") != 0
      && V_strcasecmp(s1: v2, s2: ".vbs") != 0
      && V_strcasecmp(s1: v2, s2: ".com") != 0
      && V_strcasecmp(s1: v2, s2: ".bat") != 0
      && V_strcasecmp(s1: v2, s2: ".dll") != 0
      && V_strcasecmp(s1: v2, s2: ".ini") != 0
      && V_strcasecmp(s1: v2, s2: ".log") != 0
      && V_strcasecmp(s1: v2, s2: ".lua") != 0
      && V_strcasecmp(s1: v2, s2: ".vdf") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A7D80
// Name: public: class bf_write __near & CNetChan::GetBuffer(enum CNetChan::EBufType)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CNetChan::GetBuffer(CNetChan *this, CNetChan::EBufType eBufType)
{
  if ( eBufType != BUF_RELIABLE )
  {
    if ( eBufType == BUF_UNRELIABLE )
      return &this->m_StreamUnreliable;
    if ( eBufType == BUF_VOICE )
      return &this->m_StreamVoice;
  }
  return &this->m_StreamReliable;
}

//------------------------------------------------------------------------------
// Address: 0x101A7DB0
// Name: public: virtual bool CNetChan::IsRemoteDisconnected(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsRemoteDisconnected(CNetChan *this)
{
  netadr_s *p_remote_address; // esi

  p_remote_address = &this->remote_address;
  return netadr_s::IsValid(this: &this->remote_address)
      && netadr_s::GetPort(this: p_remote_address) == 1
      && (__int64)g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: p_remote_address) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A7DF0
// Name: void NET_InitParanoidMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_InitParanoidMode()
{
  CNetchanParanoidMode::Init(this: &g_NetParanoid);
}

//------------------------------------------------------------------------------
// Address: 0x101A7E00
// Name: public: void CNetchanParanoidMode::StartPacket(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::StartPacket(CNetchanParanoidMode *this, bf_read *fullbuf)
{
  int v3; // eax
  unsigned int m_nDataBytes; // eax

  if ( this->m_bInitialized )
  {
    v3 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != 0 )
    {
      m_nDataBytes = fullbuf->m_nDataBytes;
      if ( m_nDataBytes >= 0x17700 )
        m_nDataBytes = 96000;
      this->m_nRawDataSize = m_nDataBytes;
      _V_memcpy(dest: this->m_pRawData, src: fullbuf->m_pData, count: m_nDataBytes);
      this->m_nPacketMessageCount = 0;
      this->m_nHeaderBits = 0;
      this->m_nFlags = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7E70
// Name: public: void CNetchanParanoidMode::NoteHeaderSize(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::NoteHeaderSize(CNetchanParanoidMode *this, bf_read *msg, int flags)
{
  int v3; // eax
  const unsigned int *m_pData; // eax
  signed int m_nDataBits; // eax

  if ( this->m_bInitialized )
  {
    v3 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != 0 )
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
}

//------------------------------------------------------------------------------
// Address: 0x101A7EE0
// Name: public: void CNetchanParanoidMode::Dump(class CNetChan __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::Dump(CNetchanParanoidMode *this, CNetChan *channel, const char *pchReason)
{
  int v4; // eax
  void (*v5)(const char *, ...); // esi
  netadr_s *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // ebx
  CNetchanParanoidMode::MessageItem_t *v10; // esi
  const char *v11; // [esp-10h] [ebp-14h]
  const char *pchReasona; // [esp+10h] [ebp+Ch]

  if ( this->m_bInitialized )
  {
    v4 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v4 != 0 )
    {
      v5 = (void (*)(const char *, ...))_Msg;
      _Msg(a1: "%s\n ", pchReason);
      v6 = (netadr_s *)channel->GetRemoteAddress(this: channel);
      v7 = netadr_s::ToString(this: v6, baseOnly: false);
      v8 = (const char *)((int (__thiscall *)(CNetChan *, const char *))channel->GetName)(a1: channel, a2: v7);
      _Msg(a1: "Dumping messages for channel %s(%s) 0x%p\n", v8, v11, channel);
      _Msg(a1: "Header bits %d, flags == %d\n", this->m_nHeaderBits, this->m_nFlags);
      _Msg(a1: "%d messages\n", this->m_nPacketMessageCount);
      v9 = 0;
      if ( this->m_nPacketMessageCount > 0 )
      {
        pchReasona = nullptr;
        do
        {
          v10 = (CNetchanParanoidMode::MessageItem_t *)&pchReasona[(unsigned int)this->m_pPacketMessages];
          _Msg(a1: "%d -----------------------\n", v9);
          CNetchanParanoidMode::MessageItem_t::Dump(this: v10);
          pchReasona += 312;
          ++v9;
        }
        while ( v9 < this->m_nPacketMessageCount );
        v5 = (void (*)(const char *, ...))_Msg;
      }
      v5(a1: "Raw\n");
      LogMultiline(input: false, label: "PKT", data: (const char *)this->m_pRawData, len: this->m_nRawDataSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7FE0
// Name: public: virtual unsigned int CNetChan::RequestFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::RequestFile(CNetChan *this, const char *filename, bool bIsReplayDemoFile)
{
  unsigned int v4; // ecx
  int m_iCurBit; // ecx
  unsigned __int8 *v6; // eax
  char v7; // dl
  int v8; // ecx

  v4 = ++this->m_FileRequestCounter;
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "RequestFile: %s (ID %i)\n", filename, v4);
  bf_write::WriteUBitLong(this: &this->m_StreamReliable, curData: 2u, numbits: 6, bCheckRange: true);
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
    v6 = &this->m_StreamReliable.m_pData[m_iCurBit >> 3];
    v7 = 1 << (m_iCurBit & 7);
    if ( bIsReplayDemoFile )
      *v6 |= v7;
    else
      *v6 &= ~v7;
    ++this->m_StreamReliable.m_iCurBit;
  }
  v8 = this->m_StreamReliable.m_iCurBit;
  if ( v8 + 1 > this->m_StreamReliable.m_nDataBits )
    this->m_StreamReliable.m_bOverflow = true;
  if ( !this->m_StreamReliable.m_bOverflow )
  {
    this->m_StreamReliable.m_pData[v8 >> 3] |= 1 << (v8 & 7);
    ++this->m_StreamReliable.m_iCurBit;
  }
  return this->m_FileRequestCounter;
}

//------------------------------------------------------------------------------
// Address: 0x101A80B0
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
  int m_iCurBit; // ecx
  int v7; // ecx

  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "DenyFile: %s (ID %i)\n", filename, transferID);
  p_m_StreamReliable = &this->m_StreamReliable;
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: 2u, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: transferID, numbits: 32, bCheckRange: true);
  bf_write::WriteString(this: p_m_StreamReliable, pStr: filename);
  m_iCurBit = p_m_StreamReliable->m_iCurBit;
  if ( m_iCurBit + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    if ( bIsReplayDemoFile )
      p_m_StreamReliable->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      p_m_StreamReliable->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++p_m_StreamReliable->m_iCurBit;
  }
  v7 = p_m_StreamReliable->m_iCurBit;
  if ( v7 + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    p_m_StreamReliable->m_pData[v7 >> 3] &= ~(1 << (v7 & 7));
    ++p_m_StreamReliable->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8180
// Name: public: void CNetChan::Setup(int,struct netadr_s __near *,char const __near *,class INetChannelHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Setup(CNetChan *this, int sock, netadr_s *adr, const char *name, INetChannelHandler *handler)
{
  int m_StreamSocket; // eax
  CNetChan_vtbl *v7; // edx
  void (__thiscall *SetMaxBufferSize)(struct CNetChan *, bool, int, bool); // eax
  int v9; // edx
  int *p_sendSeqNr; // eax
  int i; // ecx

  this->m_Socket = sock;
  m_StreamSocket = this->m_StreamSocket;
  if ( m_StreamSocket != 0 )
  {
    NET_CloseSocket(hSocket: m_StreamSocket, sock: -1);
    this->m_StreamSocket = 0;
  }
  if ( adr != nullptr )
  {
    this->remote_address = *adr;
  }
  else
  {
    netadr_s::Clear(this: &this->remote_address);
    netadr_s::SetType(this: &this->remote_address, newtype: NA_NULL);
  }
  this->last_received = net_time;
  this->connect_time = net_time;
  V_strncpy(pDest: this->m_Name, pSrc: name, maxLen: 32);
  v7 = this->__vftable;
  this->m_MessageHandler = handler;
  SetMaxBufferSize = v7->SetMaxBufferSize;
  this->m_DemoRecorder = nullptr;
  SetMaxBufferSize(this, a2: false, a3: 4000, a4: false);
  this->SetMaxBufferSize(this, a2: false, a3: 4000, a4: true);
  this->SetMaxBufferSize(this, a2: true, a3: 96000, a4: false);
  this->m_fClearTime = 0.0;
  this->m_Rate = 10000;
  this->m_Timeout = 300.0;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_nChokedPackets = 0;
  this->m_ChallengeNr = 0;
  this->m_StreamSocket = 0;
  this->m_StreamActive = false;
  this->m_ReceiveList[0].buffer = nullptr;
  this->m_ReceiveList[1].buffer = nullptr;
  v9 = 0;
  p_sendSeqNr = &this->m_SubChannels[0].sendSeqNr;
  do
  {
    p_sendSeqNr[2] = v9;
    p_sendSeqNr[1] = 0;
    *p_sendSeqNr = -1;
    for ( i = 0; i < 2; ++i )
    {
      p_sendSeqNr[i - 2] = 0;
      p_sendSeqNr[i - 4] = -1;
    }
    ++v9;
    p_sendSeqNr += 7;
  }
  while ( v9 < 8 );
  this->ResetStreaming(this);
  if ( NET_IsMultiplayer() )
  {
    if ( net_blocksize.m_pParent != nullptr )
      this->m_MaxReliablePayloadSize = net_blocksize.m_pParent->m_Value.m_nValue;
    else
      this->m_MaxReliablePayloadSize = 0;
  }
  else
  {
    this->m_MaxReliablePayloadSize = 96000;
  }
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 60);
  this->m_MessageHandler->ConnectionStart(this: this->m_MessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101A8360
// Name: public: virtual void CNetChan::SetDataRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDataRate(CNetChan *this, float rate)
{
  float v2; // xmm0_4

  v2 = rate;
  if ( rate < 1000.0 )
  {
    v2 = 1000.0;
LABEL_3:
    this->m_Rate = (int)v2;
    return;
  }
  if ( rate <= 30000.0 )
    goto LABEL_3;
  this->m_Rate = (int)30000.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A83B0
// Name: public: virtual bool CNetChan::CanPacket(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::CanPacket(CNetChan *this)
{
  if ( (net_chokeloopback.m_pParent == nullptr || net_chokeloopback.m_pParent->m_Value.m_nValue == 0)
    && netadr_s::IsLoopback(this: &this->remote_address) )
  {
    return true;
  }
  if ( g_pQueuedPackedSender->HasQueuedPackets(this: g_pQueuedPackedSender, a2: this) || this->m_nQueuedPackets > 0 )
    return false;
  return net_time > this->m_fClearTime;
}

//------------------------------------------------------------------------------
// Address: 0x101A8420
// Name: private: bool CNetChan::ReadSubChannelData(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ReadSubChannelData(CNetChan *this, bf_read *buf, int stream)
{
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
  int v14; // ebx
  const unsigned int *v15; // eax
  const unsigned int *v16; // ecx
  const unsigned int *v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  const unsigned int *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ebx
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
  unsigned int v36; // eax
  int v37; // edx
  const unsigned int *v38; // eax
  const unsigned int *v39; // ecx
  int m_nBitsAvail; // ecx
  unsigned int v41; // eax
  int v42; // edi
  int v43; // ecx
  CNetChan::dataFragments_s *v44; // ebx
  const unsigned int *v45; // eax
  const unsigned int *v46; // ecx
  const unsigned int *v47; // edx
  unsigned int v48; // edi
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // ebx
  int v53; // edi
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // edi
  int v57; // ecx
  const unsigned int *v58; // eax
  const unsigned int *v59; // ecx
  const unsigned int *v60; // edx
  unsigned int v61; // edi
  int v62; // eax
  const unsigned int *v63; // ecx
  unsigned int v64; // edx
  unsigned int v65; // ebx
  int v66; // edi
  int v67; // edx
  const unsigned int *v68; // eax
  const unsigned int *v69; // ecx
  int v70; // ecx
  unsigned int v71; // eax
  int v72; // ecx
  const unsigned int *v73; // ecx
  const unsigned int *v74; // edx
  const unsigned int *v75; // edx
  unsigned int v76; // edi
  int v77; // eax
  const unsigned int *v78; // ecx
  unsigned int v79; // edx
  unsigned int v80; // ebx
  unsigned int v81; // edx
  CNetChan::dataFragments_s *v82; // ebx
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
  CNetChan::dataFragments_s *v97; // edx
  const unsigned int *v98; // edx
  unsigned int v99; // edi
  int v100; // eax
  const unsigned int *v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // ebx
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
  unsigned int v115; // ebx
  unsigned int bytes; // eax
  unsigned int v117; // eax
  unsigned int offset; // [esp+Ch] [ebp-14h]
  int startFragment; // [esp+10h] [ebp-10h]
  int numFragments; // [esp+14h] [ebp-Ch]
  unsigned int length; // [esp+18h] [ebp-8h]
  CNetChan::dataFragments_s *data; // [esp+1Ch] [ebp-4h]
  bf_read *bufa; // [esp+28h] [ebp+8h]
  bool bSingleBlock_3; // [esp+2Fh] [ebp+Fh]

  data = &this->m_ReceiveList[stream];
  m_nInBufWord = buf->m_nInBufWord;
  v5 = m_nInBufWord & 1;
  v6 = buf->m_nBitsAvail-- == 1;
  startFragment = 0;
  numFragments = 0;
  offset = 0;
  length = 0;
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
  bSingleBlock_3 = v9;
  if ( v9 )
  {
LABEL_46:
    data->filename[0] = 0;
    data->isCompressed = false;
    data->isReplayDemo = false;
    data->transferID = 0;
    v6 = !v9;
    v36 = buf->m_nInBufWord;
    if ( !v6 )
    {
      v37 = v36 & 1;
      v6 = buf->m_nBitsAvail-- == 1;
      if ( v6 )
      {
        v38 = buf->m_pDataIn;
        v39 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v38 == v39 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v38 + 1;
        }
        else if ( v38 <= v39 )
        {
          buf->m_nInBufWord = *v38;
          buf->m_pDataIn = v38 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v36 >> 1;
      }
      if ( v37 == 0 )
      {
        data->isCompressed = false;
        v44 = data;
        goto LABEL_74;
      }
      data->isCompressed = true;
      m_nBitsAvail = buf->m_nBitsAvail;
      if ( m_nBitsAvail >= 26 )
      {
        v41 = buf->m_nInBufWord;
        v42 = v41 & 0x3FFFFFF;
        v43 = m_nBitsAvail - 26;
        buf->m_nBitsAvail = v43;
        if ( v43 != 0 )
        {
          v44 = data;
          buf->m_nInBufWord = v41 >> 26;
          data->nUncompressedSize = v42;
        }
        else
        {
          v45 = buf->m_pDataIn;
          v46 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v45 == v46 )
          {
            v44 = data;
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v45 + 1;
            data->nUncompressedSize = v42;
          }
          else
          {
            v44 = data;
            if ( v45 <= v46 )
            {
              buf->m_nInBufWord = *v45;
              buf->m_pDataIn = v45 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            data->nUncompressedSize = v42;
          }
        }
LABEL_74:
        v54 = buf->m_nBitsAvail;
        if ( v54 >= 17 )
        {
          v55 = buf->m_nInBufWord;
          v56 = v55 & 0x1FFFF;
          v57 = v54 - 17;
          buf->m_nBitsAvail = v57;
          if ( v57 != 0 )
          {
            buf->m_nInBufWord = v55 >> 17;
            v44->bytes = v56;
          }
          else
          {
            v58 = buf->m_pDataIn;
            v59 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v58 == v59 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v58 + 1;
              v44->bytes = v56;
            }
            else
            {
              if ( v58 <= v59 )
              {
                buf->m_nInBufWord = *v58;
                buf->m_pDataIn = v58 + 1;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
              v44->bytes = v56;
            }
          }
          goto LABEL_172;
        }
        v60 = buf->m_pBufferEnd;
        v61 = buf->m_nInBufWord;
        v62 = 17 - v54;
        v63 = buf->m_pDataIn;
        if ( v63 == v60 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        else
        {
          if ( v63 > v60 )
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            goto LABEL_89;
          }
          buf->m_nInBufWord = *v63;
        }
        buf->m_pDataIn = v63 + 1;
LABEL_89:
        if ( buf->m_bOverflow )
        {
          v44->bytes = 0;
        }
        else
        {
          v64 = buf->m_nInBufWord;
          v65 = (v64 & CBitBuffer::s_nMaskTable[v62]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v62;
          v66 = v65 | v61;
          v44 = data;
          buf->m_nInBufWord = v64 >> v62;
          data->bytes = v66;
        }
        goto LABEL_172;
      }
      v47 = buf->m_pBufferEnd;
      v48 = buf->m_nInBufWord;
      v49 = 26 - m_nBitsAvail;
      v50 = buf->m_pDataIn;
      if ( v50 == v47 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v50 > v47 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_70;
        }
        buf->m_nInBufWord = *v50;
      }
      buf->m_pDataIn = v50 + 1;
LABEL_70:
      if ( buf->m_bOverflow )
      {
        v44 = data;
        data->nUncompressedSize = 0;
      }
      else
      {
        v51 = buf->m_nInBufWord;
        v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v49;
        v53 = v52 | v48;
        v44 = data;
        buf->m_nInBufWord = v51 >> v49;
        data->nUncompressedSize = v53;
      }
      goto LABEL_74;
    }
    v67 = v36 & 1;
    v6 = buf->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v68 = buf->m_pDataIn;
      v69 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v68 == v69 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v68 + 1;
      }
      else if ( v68 <= v69 )
      {
        buf->m_nInBufWord = *v68;
        buf->m_pDataIn = v68 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v36 >> 1;
    }
    if ( v67 == 0 )
    {
      v82 = data;
      goto LABEL_127;
    }
    v70 = buf->m_nBitsAvail;
    if ( v70 >= 32 )
    {
      v71 = buf->m_nInBufWord;
      v72 = v70 - 32;
      buf->m_nBitsAvail = v72;
      if ( v72 != 0 )
      {
        buf->m_nInBufWord = 0;
      }
      else
      {
        v73 = buf->m_pDataIn;
        v74 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v73 == v74 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v73 + 1;
        }
        else if ( v73 <= v74 )
        {
          buf->m_nInBufWord = *v73;
          buf->m_pDataIn = v73 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_117:
      v82 = data;
      data->transferID = v71;
      CBitRead::ReadString(this: buf, pStr: data->filename, maxLen: 260, bLine: false, pOutNumChars: nullptr);
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
        data->isReplayDemo = true;
LABEL_127:
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
        data->isCompressed = false;
        goto LABEL_154;
      }
      v82->isCompressed = true;
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
          data->nUncompressedSize = v93;
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
            data->nUncompressedSize = v93;
          }
          else
          {
            if ( v95 <= v96 )
            {
              buf->m_nInBufWord = *v95;
              v97 = data;
              buf->m_pDataIn = v95 + 1;
            }
            else
            {
              v97 = data;
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            v97->nUncompressedSize = v93;
          }
        }
LABEL_154:
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
LABEL_171:
          data->bytes = v106;
          v44 = data;
LABEL_172:
          if ( v44->buffer != nullptr )
          {
            free(pMem: v44->buffer);
            _ConDMsg(a1: "Fragment transmission aborted at %i/%i.\n", v44->ackedFragments, v44->numFragments);
          }
          bytes = v44->bytes;
          v44->bits = 8 * bytes;
          v44->buffer = (char *)MemAlloc_Alloc(nSize: 4 * ((bytes + 3) >> 2));
          v117 = (v44->bytes + 255) >> 8;
          v44->asTCP = false;
          v44->numFragments = v117;
          v44->ackedFragments = 0;
          v44->file = nullptr;
          if ( bSingleBlock_3 )
          {
            numFragments = v117;
            length = v117 << 8;
          }
          goto LABEL_176;
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
            goto LABEL_168;
          }
          buf->m_nInBufWord = *v113;
        }
        buf->m_pDataIn = v113 + 1;
LABEL_168:
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
        goto LABEL_171;
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
          goto LABEL_150;
        }
        buf->m_nInBufWord = *v101;
      }
      buf->m_pDataIn = v101 + 1;
LABEL_150:
      if ( buf->m_bOverflow )
      {
        data->nUncompressedSize = 0;
      }
      else
      {
        v102 = buf->m_nInBufWord;
        v103 = (v102 & CBitBuffer::s_nMaskTable[v100]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v100;
        buf->m_nInBufWord = v102 >> v100;
        data->nUncompressedSize = v103 | v99;
      }
      goto LABEL_154;
    }
    v75 = buf->m_pBufferEnd;
    v76 = buf->m_nInBufWord;
    v77 = 32 - v70;
    v78 = buf->m_pDataIn;
    if ( v78 == v75 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_114;
      }
      buf->m_nInBufWord = *v78;
    }
    buf->m_pDataIn = v78 + 1;
LABEL_114:
    if ( buf->m_bOverflow )
    {
      v71 = 0;
    }
    else
    {
      v79 = buf->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v77;
      v81 = v79 >> v77;
      v71 = v80 | v76;
      buf->m_nInBufWord = v81;
    }
    goto LABEL_117;
  }
  v10 = buf->m_nBitsAvail;
  if ( v10 < 18 )
  {
    v17 = buf->m_pBufferEnd;
    v18 = buf->m_nInBufWord;
    v19 = 18 - v10;
    v20 = buf->m_pDataIn;
    if ( v20 == v17 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v20 > v17 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v20;
    }
    buf->m_pDataIn = v20 + 1;
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
      v14 = v18 | v22;
      buf->m_nInBufWord = v21 >> v19;
    }
    goto LABEL_27;
  }
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
LABEL_27:
  v23 = buf->m_nBitsAvail;
  bufa = (bf_read *)v14;
  startFragment = v14;
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
    goto LABEL_44;
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
  }
  else
  {
    if ( v33 > v30 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_41;
    }
    buf->m_nInBufWord = *v33;
  }
  buf->m_pDataIn = v33 + 1;
LABEL_41:
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
    v14 = (int)bufa;
    buf->m_nInBufWord = v34 >> v32;
  }
LABEL_44:
  numFragments = v25;
  offset = v14 << 8;
  length = v25 << 8;
  if ( v14 << 8 == 0 )
  {
    v9 = false;
    goto LABEL_46;
  }
  if ( data->buffer == nullptr )
    return 0;
LABEL_176:
  if ( numFragments + startFragment == data->numFragments && (unsigned __int8)data->bytes != 0 )
    length -= 256 - (unsigned __int8)data->bytes;
  CBitRead::ReadBytes(this: buf, pOut: &data->buffer[offset], nBytes: length);
  data->ackedFragments += numFragments;
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "Received fragments: start %i, num %i\n", startFragment, numFragments);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A8E70
// Name: private: bool CNetChan::ProcessControlMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessControlMessage(CNetChan *this, int cmd, bf_read *buf)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  const char *v7; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // ecx
  int v12; // edi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  unsigned int v21; // eax
  int v22; // ecx
  bool v23; // zf
  const unsigned int *v24; // eax
  const unsigned int *v25; // edx
  unsigned int v26; // eax
  int v27; // ecx
  const unsigned int *v28; // eax
  const unsigned int *v29; // edx
  int v30; // eax
  CNetchanParanoidMode::MessageItem_t *v31; // esi
  int v32; // eax
  CNetchanParanoidMode::MessageItem_t *v33; // esi
  int v34; // eax
  char string[1024]; // [esp+Ch] [ebp-404h] BYREF
  CNetChan *channel; // [esp+40Ch] [ebp-4h]
  int nStartBit; // [esp+41Ch] [ebp+Ch]

  m_pData = buf->m_pData;
  channel = this;
  if ( m_pData != nullptr )
  {
    m_nDataBits = buf->m_nDataBits;
    nStartBit = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( nStartBit >= m_nDataBits )
      nStartBit = m_nDataBits;
  }
  else
  {
    nStartBit = 0;
  }
  if ( cmd == 0 )
  {
    if ( !g_NetParanoid.m_bInitialized )
      return 1;
    v34 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v34 == 0 || g_NetParanoid.m_nPacketMessageCount >= 255 )
      return 1;
    v31 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
    v31->m_pMsg = nullptr;
    v31->m_nMessageSize = 0;
    v31->m_nType = 0;
    v31->m_nGroup = 0;
    V_strncpy(pDest: v31->m_szName, pSrc: "net_NOP", maxLen: 32);
    V_strncpy(pDest: v31->m_szDesc, pSrc: defaultValue, maxLen: 128);
    v31->m_nStartBit = nStartBit;
    goto LABEL_67;
  }
  if ( cmd != 1 )
  {
    if ( cmd != 2 )
    {
      v7 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      ConMsg(a1: "CNetChan: received bad control cmd %i from %s.\n", cmd, v7);
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel, pchReason: "bad control cmd");
      return 0;
    }
    m_nBitsAvail = buf->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = buf->m_nInBufWord;
      v11 = m_nBitsAvail - 32;
      buf->m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        buf->m_nInBufWord = 0;
        v12 = m_nInBufWord;
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
          v12 = m_nInBufWord;
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
          v12 = m_nInBufWord;
        }
      }
      goto LABEL_27;
    }
    v15 = buf->m_pBufferEnd;
    v16 = buf->m_nInBufWord;
    v17 = 32 - m_nBitsAvail;
    v18 = buf->m_pDataIn;
    if ( v18 == v15 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v18;
    }
    buf->m_pDataIn = v18 + 1;
LABEL_24:
    if ( buf->m_bOverflow )
    {
      v12 = 0;
    }
    else
    {
      v19 = buf->m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v17;
      v12 = v20 | v16;
      buf->m_nInBufWord = v19 >> v17;
    }
LABEL_27:
    CBitRead::ReadString(this: buf, pStr: string, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
    v21 = buf->m_nInBufWord;
    v22 = v21 & 1;
    v23 = buf->m_nBitsAvail-- == 1;
    if ( v23 )
    {
      v24 = buf->m_pDataIn;
      v25 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v24 + 1;
      }
      else if ( v24 <= v25 )
      {
        buf->m_nInBufWord = *v24;
        buf->m_pDataIn = v24 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v21 >> 1;
    }
    LOBYTE(cmd) = v22 != 0;
    v26 = buf->m_nInBufWord;
    v27 = v26 & 1;
    v23 = buf->m_nBitsAvail-- == 1;
    if ( v23 )
    {
      v28 = buf->m_pDataIn;
      v29 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v28 == v29 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v28 + 1;
      }
      else if ( v28 <= v29 )
      {
        buf->m_nInBufWord = *v28;
        buf->m_pDataIn = v28 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v26 >> 1;
    }
    if ( v27 != 0 && IsSafeFileToDownload(pFilename: string) )
      ((void (__stdcall *)(char *, int, int))channel->m_MessageHandler->FileRequested)(a1: string, a2: v12, a3: cmd);
    else
      ((void (__stdcall *)(char *, int, int))channel->m_MessageHandler->FileDenied)(a1: string, a2: v12, a3: cmd);
    if ( !g_NetParanoid.m_bInitialized )
      return 1;
    v30 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v30 == 0 || g_NetParanoid.m_nPacketMessageCount >= 255 )
      return 1;
    v31 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
    v31->m_pMsg = nullptr;
    v31->m_nMessageSize = 0;
    v31->m_nType = 2;
    v31->m_nGroup = 0;
    V_strncpy(pDest: v31->m_szName, pSrc: "net_File", maxLen: 32);
    V_strncpy(pDest: v31->m_szDesc, pSrc: string, maxLen: 128);
    v31->m_nStartBit = nStartBit;
LABEL_67:
    v31->m_nEndBit = -1;
    return 1;
  }
  CBitRead::ReadString(this: buf, pStr: string, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  if ( g_NetParanoid.m_bInitialized )
  {
    v32 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v32 != 0 && g_NetParanoid.m_nPacketMessageCount < 255 )
    {
      v33 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
      v33->m_pMsg = nullptr;
      v33->m_nMessageSize = 0;
      v33->m_nType = 1;
      v33->m_nGroup = 0;
      V_strncpy(pDest: v33->m_szName, pSrc: "net_Disconnect", maxLen: 32);
      V_strncpy(pDest: v33->m_szDesc, pSrc: string, maxLen: 128);
      v33->m_nStartBit = nStartBit;
      v33->m_nEndBit = -1;
    }
  }
  channel->m_MessageHandler->ConnectionClosing(this: channel->m_MessageHandler, a2: string);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A92C0
// Name: public: virtual bool CNetChan::HasPendingReliableData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetChan::HasPendingReliableData(CNetChan *this)
{
  return this->m_StreamReliable.m_iCurBit > 0 || this->m_WaitingList[0].m_Size > 0 || this->m_WaitingList[1].m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A9350
// Name: private: void CNetChan::CompressFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetChan::CompressFragments(CNetChan *this@<ecx>, void *a2@<edi>)
{
  CNetChan *v2; // ebx
  bool v3; // zf
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // eax
  CNetChan::dataFragments_s **m_pMemory; // eax
  CNetChan::dataFragments_s *v6; // esi
  char *v7; // edi
  const char *v8; // edi
  const char *v9; // eax
  char *v10; // eax
  void *v11; // edi
  int v12; // eax
  int v13; // ebx
  char *v14; // eax
  char *v15; // eax
  void *file; // edx
  unsigned int v17; // eax
  char *buffer; // [esp-14h] [ebp-13Ch]
  unsigned int bytes; // [esp-10h] [ebp-138h]
  unsigned int v20; // [esp-Ch] [ebp-134h]
  char compressedfilename[260]; // [esp+4h] [ebp-124h] BYREF
  CNetChan *v23; // [esp+108h] [ebp-20h]
  int v24; // [esp+10Ch] [ebp-1Ch]
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v25; // [esp+110h] [ebp-18h]
  int compressedFileSize; // [esp+114h] [ebp-14h]
  int compressedFileTime; // [esp+118h] [ebp-10h]
  unsigned int destLen; // [esp+11Ch] [ebp-Ch] BYREF
  char *compressed; // [esp+120h] [ebp-8h]
  char *uncompressed; // [esp+124h] [ebp-4h] BYREF

  v2 = this;
  v3 = !this->m_bUseCompression;
  v23 = this;
  if ( !v3 && net_compresspackets.m_pParent != nullptr && net_compresspackets.m_pParent->m_Value.m_nValue != 0 )
  {
    m_WaitingList = this->m_WaitingList;
    v25 = this->m_WaitingList;
    v24 = 2;
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
            uncompressed = (char *)v6->bytes;
            v7 = (char *)MemAlloc_Alloc(nSize: (unsigned int)uncompressed);
            bytes = v6->bytes;
            buffer = v6->buffer;
            compressed = v7;
            if ( NET_BufferToBufferCompress(
                   dest: v7,
                   destLen: (unsigned int *)&uncompressed,
                   source: buffer,
                   sourceLen: bytes) )
            {
              v8 = (const char *)v2->GetName(this: v2);
              v9 = v2->GetAddress(this: v2);
              DevMsg(a1: "Compressing fragments for %s(%s) (%d -> %d bytes)\n", v8, v9, v6->bytes, uncompressed);
              _V_memcpy(dest: v6->buffer, src: compressed, count: (int)uncompressed);
              v7 = compressed;
              v6->nUncompressedSize = v6->bytes;
              v10 = uncompressed;
              v6->bytes = (unsigned int)uncompressed;
              v6->numFragments = (unsigned int)(v10 + 255) >> 8;
              v6->isCompressed = true;
            }
            free(pMem: v7);
          }
          else
          {
            compressedFileSize = -1;
            v11 = nullptr;
            V_snprintf(pDest: compressedfilename, maxLen: 260, pFormat: "%s.ztmp", v6->filename);
            compressedFileTime = ((int (__thiscall *)(IBaseFileSystem *, char *, _DWORD, void *))g_pFileSystem->GetFileTime)(
                                   a1: &g_pFileSystem->IBaseFileSystem,
                                   a2: compressedfilename,
                                   a3: 0,
                                   a4: a2);
            v12 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: v6->filename, a3: nullptr);
            if ( compressedFileTime >= v12
              && (v11 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: compressedfilename,
                          a3: "rb",
                          a4: 0)) != nullptr )
            {
              a2 = v11;
              v13 = ((int (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Size_2)(a1: &g_pFileSystem->IBaseFileSystem);
            }
            else
            {
              v14 = (char *)MemAlloc_Alloc(nSize: v6->bytes);
              v20 = v6->bytes;
              uncompressed = v14;
              v15 = (char *)MemAlloc_Alloc(nSize: v20);
              file = v6->file;
              compressed = v15;
              compressedFileTime = v6->bytes;
              a2 = file;
              destLen = compressedFileTime;
              ((void (__thiscall *)(IBaseFileSystem *, char *, int))g_pFileSystem->Read)(
                a1: &g_pFileSystem->IBaseFileSystem,
                a2: uncompressed,
                a3: compressedFileTime);
              if ( NET_BufferToBufferCompress(
                     dest: compressed,
                     &destLen,
                     source: uncompressed,
                     sourceLen: compressedFileTime) )
              {
                v11 = g_pFileSystem->Open(
                        this: &g_pFileSystem->IBaseFileSystem,
                        a2: compressedfilename,
                        a3: "wb",
                        a4: 0);
                if ( v11 != nullptr )
                {
                  DevMsg(a1: "Creating compressed version of file %s (%d -> %d)\n", v6->filename, v6->bytes, destLen);
                  g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: compressed, a3: destLen, a4: v11);
                  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v11);
                  v11 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: compressedfilename,
                          a3: "rb",
                          a4: 0);
                  if ( v11 != nullptr )
                    compressedFileSize = destLen;
                }
              }
              free(pMem: uncompressed);
              free(pMem: compressed);
              v13 = compressedFileSize;
            }
            if ( v13 > 0 )
            {
              g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6->file);
              v17 = v6->bytes;
              v6->bytes = v13;
              v6->file = v11;
              v6->nUncompressedSize = v17;
              v6->numFragments = (unsigned int)(v13 + 255) >> 8;
              v6->isCompressed = true;
            }
            v2 = v23;
          }
        }
      }
      m_WaitingList = v25 + 1;
      v3 = v24-- == 1;
      ++v25;
    }
    while ( !v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A96A0
// Name: public: virtual bool CNetChan::StartStreaming(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::StartStreaming(CNetChan *this, unsigned int challengeNr)
{
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v5; // eax

  this->ResetStreaming(this);
  this->m_ChallengeNr = challengeNr;
  if ( NET_IsMultiplayer() )
  {
    this->m_StreamSocket = NET_ConnectSocket(sock: this->m_Socket, addr: &this->remote_address);
    if ( this->m_StreamData.m_nAllocationCount < 96000 && this->m_StreamData.m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_StreamData.m_pMemory;
      this->m_StreamData.m_nAllocationCount = 96000;
      if ( m_pMemory != nullptr )
        v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 96000);
      else
        v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
      this->m_StreamData.m_pMemory = v5;
    }
    return this->m_StreamSocket != 0;
  }
  else
  {
    this->m_StreamSocket = 0;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9750
// Name: public: virtual void CNetChan::SetMaxBufferSize(bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxBufferSize(CNetChan *this, bool bReliable, int nBytes, bool bVoice)
{
  bf_write *p_m_StreamReliable; // eax
  CUtlMemory<unsigned char,int> *p_m_ReliableDataBuffer; // esi
  int m_iCurBit; // ebx
  bf_write *stream; // [esp+8h] [ebp+8h]
  int nBytesa; // [esp+Ch] [ebp+Ch]
  unsigned __int8 *copybuf; // [esp+10h] [ebp+10h]

  if ( nBytes >= 4000 )
  {
    nBytesa = 96000;
    if ( nBytes <= 96000 )
      nBytesa = nBytes;
  }
  else
  {
    nBytesa = 4000;
  }
  if ( bReliable )
  {
    p_m_StreamReliable = &this->m_StreamReliable;
    p_m_ReliableDataBuffer = &this->m_ReliableDataBuffer;
  }
  else
  {
    if ( bVoice )
    {
      stream = &this->m_StreamVoice;
      p_m_ReliableDataBuffer = &this->m_VoiceDataBuffer;
      goto LABEL_11;
    }
    p_m_StreamReliable = &this->m_StreamUnreliable;
    p_m_ReliableDataBuffer = &this->m_UnreliableDataBuffer;
  }
  stream = p_m_StreamReliable;
LABEL_11:
  if ( p_m_ReliableDataBuffer->m_nAllocationCount != nBytesa )
  {
    m_iCurBit = stream->m_iCurBit;
    copybuf = nullptr;
    if ( (m_iCurBit + 7) >> 3 < nBytesa )
    {
      if ( m_iCurBit > 0 )
      {
        copybuf = (unsigned __int8 *)MemAlloc_Alloc(nSize: (m_iCurBit + 7) >> 3);
        _V_memcpy(dest: copybuf, src: p_m_ReliableDataBuffer->m_pMemory, count: (m_iCurBit + 7) >> 3);
      }
      if ( p_m_ReliableDataBuffer->m_nGrowSize >= 0 )
      {
        if ( p_m_ReliableDataBuffer->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ReliableDataBuffer->m_pMemory);
          p_m_ReliableDataBuffer->m_pMemory = nullptr;
        }
        p_m_ReliableDataBuffer->m_nAllocationCount = 0;
      }
      CUtlMemory<unsigned char,int>::EnsureCapacity(this: p_m_ReliableDataBuffer, num: nBytesa);
      if ( m_iCurBit > 0 )
      {
        _V_memcpy(dest: p_m_ReliableDataBuffer->m_pMemory, src: copybuf, count: (m_iCurBit + 7) >> 3);
        free(pMem: copybuf);
      }
      bf_write::StartWriting(
        this: stream,
        pData: p_m_ReliableDataBuffer->m_pMemory,
        nBytes: nBytesa,
        iStartBit: m_iCurBit,
        nBits: -1);
    }
    else
    {
      ConMsg(a1: "CNetChan::SetMaxBufferSize: cant preserve exiting data %i>%i.\n", (m_iCurBit + 7) >> 3, nBytesa);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9860
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
// Address: 0x101A98D0
// Name: private: void CNetChan::UpdateSubChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateSubChannels(CNetChan *this)
{
  CNetChan *v1; // edi
  int v2; // eax
  int *i; // ecx
  CNetChan::subChannel_s *v4; // ebx
  int v5; // esi
  int j; // ecx
  CNetChan::dataFragments_s **m_pMemory; // eax
  CNetChan::dataFragments_s *v8; // edx
  int v9; // edi
  int numFragments; // eax
  int v11; // eax
  int v12; // eax
  int m_nOutReliableState; // ecx
  CNetChan::subChannel_s *freeSubChan; // [esp+4h] [ebp-Ch]
  bool bSendData; // [esp+Fh] [ebp-1h]

  v1 = this;
  v2 = 0;
  for ( i = &this->m_SubChannels[0].state; *i != 0; i += 7 )
  {
    if ( ++v2 >= 8 )
      return;
  }
  v4 = &v1->m_SubChannels[v2];
  freeSubChan = v4;
  if ( v4 != nullptr )
  {
    v5 = v1->m_MaxReliablePayloadSize >> 8;
    bSendData = false;
    for ( j = 0; j < 2; ++j )
    {
      if ( v1->m_WaitingList[j].m_Size > 0 )
      {
        m_pMemory = v1->m_WaitingList[j].m_Memory.m_pMemory;
        v8 = *m_pMemory;
        if ( !(*m_pMemory)->asTCP )
        {
          v9 = v8->pendingFragments + v8->ackedFragments;
          numFragments = v8->numFragments;
          if ( v9 == numFragments )
          {
            v1 = this;
          }
          else
          {
            v11 = numFragments - v9;
            if ( v5 < v11 )
              v11 = v5;
            if ( j == 1 )
            {
              if ( this->m_bFileBackgroundTranmission && v11 > 1 )
                v11 = 1;
              v4 = freeSubChan;
            }
            v4->startFraggment[j] = v9;
            v1 = this;
            v4->numFragments[j] = v11;
            v8->pendingFragments += v11;
            v5 -= v11;
            bSendData = true;
            if ( v5 <= 0 )
              goto LABEL_22;
          }
        }
      }
    }
    if ( !bSendData )
      return;
LABEL_22:
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
// Address: 0x101A99E0
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
// Address: 0x101A9A30
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
// Address: 0x101AA680
// Name: private: void CNetChan::RemoveHeadInWaitingList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RemoveHeadInWaitingList(CNetChan *this, CNetChan::dataFragments_s *nList)
{
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *v2; // edi
  void **v3; // esi
  bool v4; // zf

  v2 = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_WaitingList[(_DWORD)nList];
  v3 = (void **)*v2->m_Memory.m_pMemory;
  v4 = v3[66] == nullptr;
  nList = (CNetChan::dataFragments_s *)v3;
  if ( !v4 )
    free(pMem: v3[66]);
  if ( *v3 != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: *v3);
    *v3 = nullptr;
  }
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(this: v2, src: (vgui::TreeNode *const *)&nList);
  free(pMem: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101AA6F0
// Name: private: bool CNetChan::SendSubChannelData(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::SendSubChannelData(CNetChan *this, bf_write *buf)
{
  CNetChan::dataFragments_s *v3; // eax
  signed int v4; // eax
  CNetChan::subChannel_s *m_SubChannels; // ecx
  CNetChan::subChannel_s *v6; // ebx
  unsigned int *numFragments; // ebx
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // edi
  int m_iCurBit; // ecx
  int v12; // edx
  unsigned __int8 *v13; // eax
  CNetChan::dataFragments_s *v14; // ebx
  unsigned __int8 *v15; // eax
  int v16; // edx
  int v17; // ecx
  unsigned __int8 *v18; // eax
  int v19; // ecx
  unsigned __int8 *v20; // eax
  int v21; // ecx
  unsigned __int8 *v22; // eax
  int v23; // ecx
  unsigned __int8 *v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  char *buffer; // eax
  unsigned int v29; // eax
  void *v30; // edi
  CNetChan::subChannel_s *v31; // edi
  bool v32; // zf
  int v34; // [esp+Ch] [ebp-14h]
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v35; // [esp+10h] [ebp-10h]
  CNetChan::subChannel_s *subChan; // [esp+14h] [ebp-Ch]
  unsigned int offset; // [esp+18h] [ebp-8h]
  unsigned int length; // [esp+1Ch] [ebp-4h]
  unsigned int *bufa; // [esp+28h] [ebp+8h]

  CNetChan::CompressFragments(this, a2: this);
  if ( this->m_WaitingList[0].m_Size != 0 )
  {
    v3 = *this->m_WaitingList[0].m_Memory.m_pMemory;
    if ( v3->asTCP && v3->pendingFragments <= 0 )
      CNetChan::SendReliableViaStream(this, data: *this->m_WaitingList[0].m_Memory.m_pMemory);
  }
  CNetChan::UpdateSubChannels(this);
  v4 = 0;
  m_SubChannels = this->m_SubChannels;
  do
  {
    v6 = m_SubChannels;
    subChan = m_SubChannels;
    if ( m_SubChannels->state == 1 )
      break;
    ++v4;
    ++m_SubChannels;
  }
  while ( v4 < 8 );
  if ( v4 == 8 )
    return 0;
  bf_write::WriteUBitLong(this: buf, curData: v4, numbits: 3, bCheckRange: true);
  numFragments = (unsigned int *)v6->numFragments;
  m_WaitingList = this->m_WaitingList;
  bufa = numFragments;
  v35 = m_WaitingList;
  v34 = 2;
  do
  {
    m_iCurBit = buf->m_iCurBit;
    v12 = m_iCurBit + 1;
    if ( *numFragments == 0 )
    {
      if ( v12 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v13 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v13 &= ~(1 << (m_iCurBit & 7));
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      goto LABEL_81;
    }
    v14 = *m_WaitingList->m_Memory.m_pMemory;
    if ( v12 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v15 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v15 |= 1 << (m_iCurBit & 7);
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    offset = *(bufa - 2) << 8;
    v16 = v14->numFragments;
    length = *bufa << 8;
    if ( *bufa + *(bufa - 2) == v16 && (unsigned __int8)v14->bytes != 0 )
      length = (*bufa << 8) - (256 - (unsigned __int8)v14->bytes);
    if ( *bufa != v16 || v14->file != nullptr )
    {
      v21 = buf->m_iCurBit;
      if ( v21 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v22 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v22 |= 1 << (v21 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: *(bufa - 2), numbits: 18, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: *bufa, numbits: 3, bCheckRange: true);
      if ( offset != 0 )
        goto LABEL_71;
      v23 = buf->m_iCurBit;
      if ( v14->file == nullptr )
        goto LABEL_55;
      if ( v23 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v24 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v24 |= 1 << (v23 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->transferID, numbits: 32, bCheckRange: true);
      bf_write::WriteString(this: buf, pStr: v14->filename);
      v23 = buf->m_iCurBit;
      if ( v14->isReplayDemo )
      {
        if ( v23 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
LABEL_60:
          v26 = buf->m_iCurBit;
          if ( v14->isCompressed )
          {
            if ( v26 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v26 >> 3] |= 1 << (v26 & 7);
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
            bf_write::WriteUBitLong(this: buf, curData: v14->nUncompressedSize, numbits: 26, bCheckRange: true);
          }
          else if ( v26 + 1 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              v27 = &buf->m_pData[buf->m_iCurBit >> 3];
              *v27 &= ~(1 << (v26 & 7));
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
          bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 26, bCheckRange: true);
          goto LABEL_71;
        }
        if ( buf->m_bOverflow )
          goto LABEL_60;
        v25 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v25 |= 1 << (v23 & 7);
      }
      else
      {
LABEL_55:
        if ( v23 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
          goto LABEL_60;
        }
        if ( buf->m_bOverflow )
          goto LABEL_60;
        buf->m_pData[v23 >> 3] &= ~(1 << (v23 & 7));
      }
      ++buf->m_iCurBit;
      goto LABEL_60;
    }
    v17 = buf->m_iCurBit;
    if ( v17 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v18 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v18 &= ~(1 << (v17 & 7));
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    v19 = buf->m_iCurBit;
    if ( v14->isCompressed )
    {
      if ( v19 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v19 >> 3] |= 1 << (v19 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->nUncompressedSize, numbits: 26, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
    else if ( v19 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v20 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v20 &= ~(1 << (v19 & 7));
        ++buf->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
    else
    {
      buf->m_bOverflow = true;
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
LABEL_71:
    buffer = v14->buffer;
    if ( buffer != nullptr )
    {
      bf_write::WriteBytes(this: buf, pBuf: &buffer[offset], nBytes: length);
    }
    else
    {
      v29 = length;
      if ( length <= 1 )
        v29 = 1;
      v30 = MemAlloc_Alloc(nSize: v29);
      g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v14->file, a3: offset, a4: FILESYSTEM_SEEK_HEAD);
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v30, a3: length, a4: v14->file);
      bf_write::WriteBytes(this: buf, pBuf: v30, nBytes: length);
      free(pMem: v30);
    }
    if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    {
      numFragments = bufa;
      v31 = subChan;
      ConMsg(a1: "Sending subchan %i: start %i, num %i\n", subChan->index, *(bufa - 2), *bufa);
    }
    else
    {
      v31 = subChan;
      numFragments = bufa;
    }
    v31->sendSeqNr = this->m_nOutSequenceNr;
    v31->state = 2;
LABEL_81:
    m_WaitingList = v35 + 1;
    ++numFragments;
    v32 = v34-- == 1;
    ++v35;
    bufa = numFragments;
  }
  while ( !v32 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AAB70
// Name: private: bool CNetChan::_ProcessMessages(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::_ProcessMessages(CNetChan *this, bf_read *buf)
{
  char *m_pszString; // ecx
  char *v3; // eax
  bool v4; // zf
  int m_nValue; // esi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  const unsigned int *v9; // eax
  int v10; // ecx
  const unsigned int *v11; // eax
  int v12; // eax
  int m_nBitsAvail; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  unsigned __int8 v16; // dl
  const unsigned int *v17; // eax
  const unsigned int *v18; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // edx
  unsigned int v25; // esi
  CNetChan *v26; // esi
  CNetChan *v27; // ecx
  char v28; // al
  INetChannel *m_pActiveChannel; // edi
  int v31; // esi
  int v32; // ecx
  CNetChan *v33; // esi
  const char *v34; // eax
  INetMessage *v35; // esi
  const unsigned int *v36; // eax
  int v37; // eax
  CNetchanParanoidMode::MessageItem_t *v38; // edi
  const char *v39; // eax
  const unsigned int *v40; // eax
  int v41; // ecx
  int v42; // eax
  CNetchanParanoidMode::MessageItem_t *v43; // edi
  int v44; // eax
  const char *v45; // eax
  const unsigned int *v46; // eax
  CNetChan_vtbl *v47; // edi
  int v48; // eax
  const char *v49; // eax
  CNetChan *v50; // edi
  const char *v51; // eax
  const char *v52; // eax
  const char *v53; // eax
  bool v54; // al
  const unsigned int *v55; // eax
  int v56; // ecx
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // ebx
  int v60; // eax
  const char *v61; // eax
  const char *v62; // [esp-4h] [ebp-4Ch]
  const char *v63; // [esp-4h] [ebp-4Ch]
  unsigned int v64; // [esp+0h] [ebp-48h]
  int v65; // [esp+4h] [ebp-44h]
  bf_read democopy; // [esp+Ch] [ebp-3Ch] BYREF
  const char *msgname; // [esp+30h] [ebp-18h]
  int startbit; // [esp+34h] [ebp-14h]
  signed int v69; // [esp+38h] [ebp-10h]
  const char *blockmsgname; // [esp+3Ch] [ebp-Ch]
  const char *showmsgname; // [esp+40h] [ebp-8h]
  CNetChan *channel; // [esp+44h] [ebp-4h]
  unsigned __int8 bufa; // [esp+50h] [ebp+8h]
  bf_read *bufb; // [esp+50h] [ebp+8h]

  this->m_bStopProcessing = false;
  channel = this;
  if ( (net_showmsg.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    if ( net_showmsg.m_pParent->m_Value.m_pszString != nullptr )
    {
      m_pszString = net_showmsg.m_pParent->m_Value.m_pszString;
      showmsgname = m_pszString;
      goto LABEL_7;
    }
    m_pszString = (char *)defaultValue;
  }
  showmsgname = m_pszString;
LABEL_7:
  if ( (net_blockmsg.m_nFlags & 0x1000) != 0 )
  {
    v3 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v3 = net_blockmsg.m_pParent->m_Value.m_pszString;
    if ( v3 == nullptr )
      v3 = (char *)defaultValue;
  }
  v4 = *m_pszString == 48;
  blockmsgname = v3;
  if ( v4 )
    showmsgname = nullptr;
  if ( *v3 == 48 )
    blockmsgname = nullptr;
  if ( net_showpeaks.m_pParent != nullptr )
  {
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
        showmsgname = "1";
    }
  }
  v9 = buf->m_pData;
  democopy = *buf;
  if ( v9 != nullptr )
  {
    v10 = buf->m_nDataBits;
    startbit = 32 * (buf->m_pDataIn - v9) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( startbit >= v10 )
      startbit = v10;
  }
  else
  {
    startbit = 0;
  }
  if ( buf->m_bOverflow )
  {
LABEL_105:
    channel->m_MessageHandler->ConnectionCrashed(this: channel->m_MessageHandler, a2: "Buffer overflow in net message");
    return 0;
  }
  while ( 1 )
  {
    v11 = buf->m_pData;
    if ( v11 != nullptr )
    {
      v12 = 32 * (buf->m_pDataIn - v11) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( v12 >= buf->m_nDataBits )
        v12 = buf->m_nDataBits;
    }
    else
    {
      v12 = 0;
    }
    if ( buf->m_nDataBits - v12 < 6 )
      break;
    m_nBitsAvail = buf->m_nBitsAvail;
    if ( m_nBitsAvail < 6 )
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      m_nInBufWord = buf->m_nInBufWord;
      v22 = 6 - m_nBitsAvail;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_pDataIn = m_pDataIn + 1;
        v16 = 0;
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
        goto LABEL_50;
      }
      if ( m_pDataIn > m_pBufferEnd )
      {
        v16 = 0;
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_50;
      }
      v23 = *m_pDataIn;
      v4 = !buf->m_bOverflow;
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
      if ( !v4 )
      {
        v16 = 0;
LABEL_50:
        v26 = channel;
        v27 = channel;
        channel->m_bProcessingMessages = true;
        v28 = CNetChan::ProcessControlMessage(this: v27, cmd: v16, buf);
        v26->m_bProcessingMessages = false;
        if ( v28 == 0 )
        {
          if ( v26->m_bShouldDelete )
          {
            ((void (__thiscall *)(CNetChan *, int))v26->dtr_INetChannel)(a1: v26, a2: 1);
            return 0;
          }
          return 0;
        }
        goto LABEL_104;
      }
      v24 = v23;
      v25 = (v23 & CBitBuffer::s_nMaskTable[v22]) << m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v22;
      bufa = v25 | m_nInBufWord;
      buf->m_nInBufWord = v24 >> v22;
      v16 = v25 | m_nInBufWord;
    }
    else
    {
      v14 = buf->m_nInBufWord;
      v15 = m_nBitsAvail - 6;
      v16 = v14 & 0x3F;
      buf->m_nBitsAvail = v15;
      if ( v15 != 0 )
      {
        buf->m_nInBufWord = v14 >> 6;
        bufa = v14 & 0x3F;
      }
      else
      {
        v17 = buf->m_pDataIn;
        v18 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v17 == v18 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v17 + 1;
          bufa = v16;
        }
        else
        {
          if ( v17 <= v18 )
          {
            buf->m_nInBufWord = *v17;
            buf->m_pDataIn = v17 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufa = v16;
        }
      }
    }
    if ( v16 <= 2u )
      goto LABEL_50;
    m_pActiveChannel = channel->m_pActiveChannel;
    v31 = 0;
    v69 = (signed int)m_pActiveChannel[4232].__vftable;
    if ( v69 <= 0 )
      goto LABEL_57;
    msgname = (const char *)v16;
    while ( 1 )
    {
      v32 = *((_DWORD *)&m_pActiveChannel[4229].GetName + v31);
      if ( (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v32 + 28))(a1: v32) == msgname )
        break;
      if ( ++v31 >= v69 )
        goto LABEL_57;
    }
    v35 = *((INetMessage **)&m_pActiveChannel[4229].GetName + v31);
    if ( v35 == nullptr )
    {
LABEL_57:
      v33 = channel;
      v34 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Netchannel: unknown net message (%i) from %s.\n", bufa, v34);
      v62 = "unknown message";
LABEL_58:
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v33, pchReason: v62);
      return 0;
    }
    msgname = v35->GetName(this: v35);
    v36 = buf->m_pData;
    if ( v36 != nullptr )
    {
      bufb = (bf_read *)(32 * (buf->m_pDataIn - v36) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)bufb >= buf->m_nDataBits )
        bufb = (bf_read *)buf->m_nDataBits;
    }
    else
    {
      bufb = nullptr;
    }
    if ( g_NetParanoid.m_bInitialized )
    {
      v37 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
      if ( v37 != 0 && g_NetParanoid.m_nPacketMessageCount < 255 )
      {
        v38 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
        v38->m_pMsg = v35;
        v38->m_nMessageSize = v35->GetSize(this: v35);
        v38->m_nType = v35->GetType(this: v35);
        v38->m_nGroup = v35->GetGroup(this: v35);
        v39 = v35->GetName(this: v35);
        V_strncpy(pDest: v38->m_szName, pSrc: v39, maxLen: 32);
        v38->m_szDesc[0] = 0;
        v38->m_nStartBit = (int)bufb;
        v38->m_nEndBit = -1;
      }
    }
    if ( !v35->ReadFromBuffer(this: v35, a2: buf) )
    {
      v33 = channel;
      v61 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Netchannel: failed reading message %s from %s.\n", msgname, v61);
      v62 = "failed reading message";
      goto LABEL_58;
    }
    v40 = buf->m_pData;
    if ( v40 != nullptr )
    {
      v41 = buf->m_nDataBits;
      v69 = 32 * (buf->m_pDataIn - v40) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( v69 >= v41 )
        v69 = v41;
    }
    else
    {
      v69 = 0;
    }
    if ( g_NetParanoid.m_bInitialized )
    {
      v42 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
      if ( v42 != 0 && g_NetParanoid.m_nPacketMessageCount > 0 )
      {
        v43 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount - 1];
        if ( v43->m_pMsg == v35 )
        {
          if ( v35->GetSize(this: v35) >= 0x80 )
            v44 = 128;
          else
            v44 = v35->GetSize(this: v35);
          _V_memcpy(dest: v43->m_Message, src: v35, count: v44);
          v43->m_nEndBit = v69;
          v45 = v35->ToString(this: v35);
          V_strncpy(pDest: v43->m_szDesc, pSrc: v45, maxLen: 128);
        }
      }
    }
    v46 = buf->m_pData;
    if ( v46 != nullptr )
    {
      v46 = (const unsigned int *)(32 * (buf->m_pDataIn - v46) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)v46 >= buf->m_nDataBits )
        v46 = (const unsigned int *)buf->m_nDataBits;
    }
    v47 = channel->__vftable;
    v48 = ((int (__thiscall *)(INetMessage *, int))v35->GetGroup)(a1: v35, a2: (char *)v46 - (char *)bufb);
    ((void (__thiscall *)(CNetChan *, int))v47->UpdateMessageStats)(a1: channel, a2: v48);
    if ( showmsgname != nullptr
      && (*showmsgname == 49 || (v49 = v35->GetName(this: v35), _V_stricmp(s1: showmsgname, s2: v49) == 0)) )
    {
      v50 = channel;
      v63 = v35->ToString(this: v35);
      v51 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Msg from %s: %s\n", v51, v63);
    }
    else
    {
      v50 = channel;
    }
    if ( blockmsgname != nullptr
      && (*blockmsgname == 49 || (v52 = v35->GetName(this: v35), _V_stricmp(s1: blockmsgname, s2: v52) == 0)) )
    {
      v53 = v35->ToString(this: v35);
      ConMsg(a1: "Blocking message %s\n", v53);
    }
    else
    {
      v50->m_bProcessingMessages = true;
      v54 = v35->Process(this: v35);
      v4 = !v50->m_bShouldDelete;
      v50->m_bProcessingMessages = false;
      if ( !v4 )
      {
        ((void (__thiscall *)(CNetChan *, int))v50->dtr_INetChannel)(a1: v50, a2: 1);
        return 0;
      }
      if ( v50->m_bStopProcessing )
        return 0;
      if ( !v54 )
      {
        _ConDMsg(a1: "Netchannel: failed processing message %s.\n", msgname);
        CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v50, pchReason: "failed processing");
        return 0;
      }
      if ( v50->IsOverflowed(this: v50) )
        return 0;
    }
LABEL_104:
    if ( buf->m_bOverflow )
      goto LABEL_105;
  }
  if ( channel->m_DemoRecorder != nullptr && !demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v55 = buf->m_pData;
    if ( v55 != nullptr )
    {
      v56 = (char *)buf->m_pDataIn - (char *)v55;
      v57 = 2 * (buf->m_nDataBytes & 3);
      v58 = 32 * (v56 >> 2) - buf->m_nBitsAvail;
      v59 = buf->m_nDataBits;
      v55 = (const unsigned int *)(v58 + 4 * v57);
      if ( (int)v55 >= v59 )
        v55 = (const unsigned int *)v59;
    }
    channel->m_DemoRecorder->RecordMessages(this: channel->m_DemoRecorder, a2: &democopy, a3: (int)v55 - startbit);
  }
  if ( net_dumptest.m_pParent != nullptr )
  {
    v60 = net_dumptest.m_pParent->m_Value.m_nValue;
    if ( v60 > 0 )
    {
      if ( v60 == 2 )
      {
        MEMORY[0] = 1;
        return 1;
      }
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&net_dumptest.IConVar, value: 0, a2: v64, a3: v65);
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel, pchReason: "requested from console");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AB2B0
// Name: private: int CNetChan::ProcessPacketHeader(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::ProcessPacketHeader(CNetChan *this, netpacket_s *packet)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  const unsigned int *v6; // edx
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edi
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  const unsigned int *v17; // edx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  unsigned int v20; // ebx
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // edi
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // edx
  const unsigned int *v29; // ecx
  const unsigned int *v30; // eax
  const unsigned int *v31; // edx
  unsigned int v32; // ebx
  int v33; // eax
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // edi
  int v37; // ecx
  unsigned int v38; // eax
  __int16 v39; // dx
  int v40; // ecx
  const unsigned int *v41; // ecx
  const unsigned int *v42; // eax
  const unsigned int *v43; // edx
  unsigned int v44; // ebx
  int v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  unsigned int m_nDataBytes; // edi
  int v52; // ebx
  const char *v53; // eax
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // edx
  int v58; // ecx
  const unsigned int *v59; // ecx
  const unsigned int *v60; // eax
  const unsigned int *v61; // edx
  unsigned int v62; // ebx
  int v63; // eax
  const unsigned int *v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // edi
  int v67; // ebx
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // ecx
  const unsigned int *v71; // ecx
  const unsigned int *v72; // eax
  const unsigned int *v73; // edx
  unsigned int v74; // ebx
  int v75; // eax
  const unsigned int *v76; // ecx
  unsigned int v77; // edx
  unsigned int v78; // edi
  CNetChan *v79; // edx
  int v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  int v83; // eax
  const char *v84; // eax
  int v85; // ecx
  int *numFragments; // edi
  int m_nOutReliableState; // edx
  int v88; // eax
  int j; // eax
  CNetChan::dataFragments_s *v90; // eax
  CNetChan::dataFragments_s *v91; // eax
  int k; // eax
  int v93; // eax
  int v94; // eax
  int m; // eax
  CNetChan *v96; // eax
  int v97; // ecx
  int v98; // edi
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // ebx
  const char *v100; // eax
  CNetChan::dataFragments_s *v101; // eax
  int v102; // ecx
  int v103; // [esp-8h] [ebp-2Ch]
  int m_nInSequenceNr; // [esp-4h] [ebp-28h]
  int v105; // [esp-4h] [ebp-28h]
  int v106; // [esp-4h] [ebp-28h]
  const unsigned int *nChokeda; // [esp+Ch] [ebp-18h]
  int nChoked; // [esp+Ch] [ebp-18h]
  __int16 v109; // [esp+10h] [ebp-14h]
  int v110; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h] BYREF
  int v112; // [esp+18h] [ebp-Ch]
  int v113; // [esp+1Ch] [ebp-8h]
  CNetChan *v114; // [esp+20h] [ebp-4h]
  netpacket_s *packeta; // [esp+2Ch] [ebp+8h]

  v114 = this;
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v10 = 32 - m_nBitsAvail;
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
      packeta = nullptr;
    }
    else
    {
      v12 = packet->message.m_nInBufWord;
      v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v10;
      packeta = (netpacket_s *)(v13 | m_nInBufWord);
      packet->message.m_nInBufWord = v12 >> v10;
    }
    goto LABEL_19;
  }
  v4 = packet->message.m_nInBufWord;
  v5 = m_nBitsAvail - 32;
  packet->message.m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    packet->message.m_nInBufWord = 0;
    packeta = (netpacket_s *)v4;
  }
  else
  {
    v6 = packet->message.m_pBufferEnd;
    v7 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v7 == v6 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v7 + 1;
      packeta = (netpacket_s *)v4;
    }
    else
    {
      if ( v7 <= v6 )
      {
        packet->message.m_nInBufWord = *v7;
        packet->message.m_pDataIn = v7 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      packeta = (netpacket_s *)v4;
    }
  }
LABEL_19:
  v14 = packet->message.m_nBitsAvail;
  if ( v14 < 32 )
  {
    v19 = packet->message.m_pBufferEnd;
    v20 = packet->message.m_nInBufWord;
    v21 = 32 - v14;
    v22 = packet->message.m_pDataIn;
    if ( v22 == v19 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v22 > v19 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_34;
      }
      packet->message.m_nInBufWord = *v22;
    }
    packet->message.m_pDataIn = v22 + 1;
LABEL_34:
    if ( packet->message.m_bOverflow )
    {
      v113 = 0;
    }
    else
    {
      v23 = packet->message.m_nInBufWord;
      v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v21;
      v113 = v24 | v20;
      packet->message.m_nInBufWord = v23 >> v21;
    }
    goto LABEL_37;
  }
  v15 = packet->message.m_nInBufWord;
  v16 = v14 - 32;
  packet->message.m_nBitsAvail = v16;
  if ( v16 != 0 )
  {
    packet->message.m_nInBufWord = 0;
    v113 = v15;
  }
  else
  {
    v17 = packet->message.m_pBufferEnd;
    v18 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v18 == v17 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v18 + 1;
      v113 = v15;
    }
    else
    {
      if ( v18 <= v17 )
      {
        packet->message.m_nInBufWord = *v18;
        packet->message.m_pDataIn = v18 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v113 = v15;
    }
  }
LABEL_37:
  v25 = packet->message.m_nBitsAvail;
  if ( v25 < 8 )
  {
    v31 = packet->message.m_pBufferEnd;
    v32 = packet->message.m_nInBufWord;
    v33 = 8 - v25;
    v34 = packet->message.m_pDataIn;
    if ( v34 == v31 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v34 > v31 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_52;
      }
      packet->message.m_nInBufWord = *v34;
    }
    packet->message.m_pDataIn = v34 + 1;
LABEL_52:
    if ( packet->message.m_bOverflow )
    {
      v112 = 0;
    }
    else
    {
      v35 = packet->message.m_nInBufWord;
      v36 = (v35 & CBitBuffer::s_nMaskTable[v33]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v33;
      v112 = v36 | v32;
      packet->message.m_nInBufWord = v35 >> v33;
    }
    goto LABEL_55;
  }
  v26 = packet->message.m_nInBufWord;
  v27 = v25 - 8;
  v28 = (unsigned __int8)v26;
  packet->message.m_nBitsAvail = v27;
  if ( v27 != 0 )
  {
    packet->message.m_nInBufWord = v26 >> 8;
    v112 = (unsigned __int8)v26;
  }
  else
  {
    v29 = packet->message.m_pBufferEnd;
    v30 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v30 == v29 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v30 + 1;
      v112 = v28;
    }
    else
    {
      if ( v30 <= v29 )
      {
        packet->message.m_nInBufWord = *v30;
        packet->message.m_pDataIn = v30 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v112 = v28;
    }
  }
LABEL_55:
  if ( !NET_IsMultiplayer() )
    goto LABEL_80;
  v37 = packet->message.m_nBitsAvail;
  if ( v37 < 16 )
  {
    v43 = packet->message.m_pBufferEnd;
    v44 = packet->message.m_nInBufWord;
    v45 = 16 - v37;
    v46 = packet->message.m_pDataIn;
    if ( v46 == v43 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v46 > v43 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_71;
      }
      packet->message.m_nInBufWord = *v46;
    }
    packet->message.m_pDataIn = v46 + 1;
LABEL_71:
    if ( packet->message.m_bOverflow )
    {
      v109 = 0;
    }
    else
    {
      v47 = packet->message.m_nInBufWord;
      v48 = (v47 & CBitBuffer::s_nMaskTable[v45]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v45;
      v109 = v48 | v44;
      packet->message.m_nInBufWord = v47 >> v45;
    }
    goto LABEL_74;
  }
  v38 = packet->message.m_nInBufWord;
  v39 = v38;
  v40 = v37 - 16;
  packet->message.m_nBitsAvail = v40;
  if ( v40 != 0 )
  {
    packet->message.m_nInBufWord = HIWORD(v38);
    v109 = v38;
  }
  else
  {
    v41 = packet->message.m_pBufferEnd;
    v42 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v42 == v41 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v42 + 1;
      v109 = v39;
    }
    else
    {
      if ( v42 <= v41 )
      {
        packet->message.m_nInBufWord = *v42;
        packet->message.m_pDataIn = v42 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v109 = v39;
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
  m_nDataBytes = packet->message.m_nDataBytes;
  v52 = m_nDataBits >> 3;
  nChokeda = packet->message.m_pData;
  CRC32_Init(pulCRC: (unsigned int *)&i);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&i, pBuffer: (char *)nChokeda + v52, nBuffer: m_nDataBytes - v52);
  CRC32_Final(pulCRC: (unsigned int *)&i);
  if ( ((unsigned __int16)i ^ HIWORD(i)) != v109 )
  {
    m_nInSequenceNr = v114->m_nInSequenceNr;
    v53 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
    ConMsg(a1: "%s:corrupted packet %i at %i\n", v53, packeta, m_nInSequenceNr);
    return -1;
  }
LABEL_80:
  v55 = packet->message.m_nBitsAvail;
  if ( v55 < 8 )
  {
    v61 = packet->message.m_pBufferEnd;
    v62 = packet->message.m_nInBufWord;
    v63 = 8 - v55;
    v64 = packet->message.m_pDataIn;
    if ( v64 == v61 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v64 > v61 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_95;
      }
      packet->message.m_nInBufWord = *v64;
    }
    packet->message.m_pDataIn = v64 + 1;
LABEL_95:
    if ( packet->message.m_bOverflow )
    {
      v110 = 0;
    }
    else
    {
      v65 = packet->message.m_nInBufWord;
      v66 = (v65 & CBitBuffer::s_nMaskTable[v63]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v63;
      v110 = v66 | v62;
      packet->message.m_nInBufWord = v65 >> v63;
    }
    goto LABEL_98;
  }
  v56 = packet->message.m_nInBufWord;
  v57 = (unsigned __int8)v56;
  v58 = v55 - 8;
  packet->message.m_nBitsAvail = v58;
  if ( v58 != 0 )
  {
    packet->message.m_nInBufWord = v56 >> 8;
    v110 = (unsigned __int8)v56;
  }
  else
  {
    v59 = packet->message.m_pBufferEnd;
    v60 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v60 == v59 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v60 + 1;
      v110 = v57;
    }
    else
    {
      if ( v60 <= v59 )
      {
        packet->message.m_nInBufWord = *v60;
        packet->message.m_pDataIn = v60 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v110 = v57;
    }
  }
LABEL_98:
  v67 = 0;
  nChoked = 0;
  if ( (v112 & 0x10) == 0 )
    goto LABEL_117;
  v68 = packet->message.m_nBitsAvail;
  if ( v68 < 8 )
  {
    v73 = packet->message.m_pBufferEnd;
    v74 = packet->message.m_nInBufWord;
    v75 = 8 - v68;
    v76 = packet->message.m_pDataIn;
    if ( v76 == v73 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v76 > v73 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_113;
      }
      packet->message.m_nInBufWord = *v76;
    }
    packet->message.m_pDataIn = v76 + 1;
LABEL_113:
    if ( packet->message.m_bOverflow )
    {
      v67 = 0;
    }
    else
    {
      v77 = packet->message.m_nInBufWord;
      v78 = (v77 & CBitBuffer::s_nMaskTable[v75]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v75;
      v67 = v78 | v74;
      packet->message.m_nInBufWord = v77 >> v75;
    }
    goto LABEL_116;
  }
  v69 = packet->message.m_nInBufWord;
  v67 = (unsigned __int8)v69;
  v70 = v68 - 8;
  packet->message.m_nBitsAvail = v70;
  if ( v70 != 0 )
  {
    packet->message.m_nInBufWord = v69 >> 8;
  }
  else
  {
    v71 = packet->message.m_pBufferEnd;
    v72 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v72 == v71 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v72 + 1;
    }
    else if ( v72 <= v71 )
    {
      packet->message.m_nInBufWord = *v72;
      packet->message.m_pDataIn = v72 + 1;
    }
    else
    {
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
    }
  }
LABEL_116:
  nChoked = v67;
LABEL_117:
  v79 = v114;
  v80 = v114->m_nInSequenceNr;
  if ( (int)packeta > v80 )
  {
    v83 = (int)packeta + -v67 - v80 - 1;
    v114->m_PacketDrop = v83;
    if ( v83 > 0 && net_showdrop.m_pParent != nullptr && net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v103 = v83;
      v84 = netadr_s::ToString(this: &v79->remote_address, baseOnly: false);
      ConMsg(a1: "%s:Dropped %i packets at %i\n", v84, v103, packeta);
      v79 = v114;
    }
    LOBYTE(v85) = 0;
    i = 0;
    numFragments = v79->m_SubChannels[0].numFragments;
    do
    {
      m_nOutReliableState = v114->m_nOutReliableState;
      if ( ((1 << v85) & m_nOutReliableState) == ((1 << v85) & v110) )
      {
        v88 = numFragments[3];
        if ( v88 == 3 )
        {
          numFragments[3] = 0;
          numFragments[2] = -1;
          for ( j = 0; j < 2; ++j )
          {
            numFragments[j] = 0;
            numFragments[j - 2] = -1;
          }
        }
        else
        {
          if ( numFragments[2] > v113 )
          {
            v106 = i;
            v100 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
            ConMsg(a1: "%s:reliable state invalid (%i).\n", v100, v106);
            return -1;
          }
          if ( v88 == 2 )
          {
            if ( *numFragments != 0 )
            {
              v90 = *v114->m_WaitingList[0].m_Memory.m_pMemory;
              v90->ackedFragments += *numFragments;
              v90->pendingFragments -= *numFragments;
            }
            if ( numFragments[1] != 0 )
            {
              v91 = *v114->m_WaitingList[1].m_Memory.m_pMemory;
              v91->ackedFragments += numFragments[1];
              v91->pendingFragments -= numFragments[1];
            }
            numFragments[3] = 0;
            numFragments[2] = -1;
            for ( k = 0; k < 2; ++k )
            {
              numFragments[k] = 0;
              numFragments[k - 2] = -1;
            }
          }
        }
      }
      else if ( numFragments[2] <= v113 )
      {
        v93 = numFragments[3];
        if ( v93 == 2 )
        {
          if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            ConMsg(a1: "Resending subchan %i: start %i, num %i\n", numFragments[4], *(numFragments - 2), *numFragments);
          numFragments[3] = 1;
        }
        else if ( v93 == 3 )
        {
          v94 = 1 << numFragments[4];
          if ( (m_nOutReliableState & v94) != 0 )
            v114->m_nOutReliableState = m_nOutReliableState & ~v94;
          else
            v114->m_nOutReliableState = v94 | m_nOutReliableState;
          numFragments[3] = 0;
          numFragments[2] = -1;
          for ( m = 0; m < 2; ++m )
          {
            numFragments[m] = 0;
            numFragments[m - 2] = -1;
          }
        }
      }
      v85 = i + 1;
      numFragments += 7;
      i = v85;
    }
    while ( v85 < 8 );
    v96 = v114;
    v97 = v113;
    v114->m_nInSequenceNr = (int)packeta;
    v96->m_nOutSequenceNrAck = v97;
    v98 = 0;
    m_WaitingList = v96->m_WaitingList;
    while ( 1 )
    {
      if ( m_WaitingList->m_Size != 0 && v96->m_nOutSequenceNrAck > 0 )
      {
        v101 = *m_WaitingList->m_Memory.m_pMemory;
        v102 = v101->numFragments;
        if ( v101->ackedFragments == v102 )
        {
          if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            ConMsg(a1: "Sending complete: %i fragments, %i bytes.\n", v102, v101->bytes);
          CNetChan::RemoveHeadInWaitingList(this: v114, nList: (CNetChan::dataFragments_s *)v98);
        }
      }
      ++v98;
      ++m_WaitingList;
      if ( v98 >= 2 )
        break;
      v96 = v114;
    }
    CNetChan::FlowNewPacket(
      this: v114,
      flow: 1,
      seqnr: v114->m_nInSequenceNr,
      acknr: v114->m_nOutSequenceNrAck,
      nChoked,
      nDropped: v114->m_PacketDrop,
      nSize: packet->wiresize + 28);
    return v112;
  }
  else
  {
    if ( net_showdrop.m_pParent != nullptr && net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v105 = v114->m_nInSequenceNr;
      if ( packeta == (netpacket_s *)v80 )
      {
        v81 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
        ConMsg(a1: "%s:duplicate packet %i at %i\n", v81, packeta, v105);
        return -1;
      }
      v82 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
      ConMsg(a1: "%s:out of order packet %i at %i\n", v82, packeta, v105);
    }
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACB70
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
  int v10; // edx
  int *p_state; // ecx
  int i; // edi
  int m_nOutReliableState; // eax
  int j; // eax
  void (__thiscall *Reset)(struct CNetChan *); // edx
  int v17; // [esp+10h] [ebp-8h]
  char **v18; // [esp+14h] [ebp-4h]

  v1 = this;
  p_buffer = (void **)&this->m_ReceiveList[0].buffer;
  v18 = &this->m_ReceiveList[0].buffer;
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
      p_buffer = (void **)v18;
      v1 = this;
    }
    if ( *p_buffer != nullptr )
    {
      free(pMem: *p_buffer);
      *p_buffer = nullptr;
    }
    p_buffer += 76;
    p_m_Size += 5;
    v9 = v17-- == 1;
    v18 = (char **)p_buffer;
  }
  while ( !v9 );
  v10 = 1;
  p_state = &v1->m_SubChannels[0].state;
  for ( i = 8; i != 0; --i )
  {
    if ( *p_state == 1 )
    {
      m_nOutReliableState = v1->m_nOutReliableState;
      if ( (m_nOutReliableState & v10) != 0 )
        v1->m_nOutReliableState = m_nOutReliableState & ~v10;
      else
        v1->m_nOutReliableState = v10 | m_nOutReliableState;
      *p_state = 0;
      *(p_state - 1) = -1;
      for ( j = 0; j < 2; ++j )
      {
        p_state[j - 3] = 0;
        p_state[j - 5] = -1;
      }
    }
    else if ( *p_state == 2 )
    {
      *p_state = 3;
    }
    p_state += 7;
    v10 = __ROL4__(v10, 1);
  }
  Reset = v1->Reset;
  v1->m_bStopProcessing = true;
  Reset(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101ACCD0
// Name: public: virtual void CNetChan::Shutdown(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetChan::Shutdown(CNetChan *this@<ecx>, int a2@<edi>, const char *pReason)
{
  int m_StreamSocket; // eax
  unsigned __int64 v5; // rax
  INetChannelHandler *m_MessageHandler; // ecx
  int v7; // edi
  INetMessage *v8; // ecx

  if ( this->m_Socket >= 0 )
  {
    ((void (__thiscall *)(CNetChan *, int))this->Clear)(a1: this, a2);
    if ( pReason != nullptr )
    {
      bf_write::WriteUBitLong(this: &this->m_StreamUnreliable, curData: 1u, numbits: 6, bCheckRange: true);
      bf_write::WriteString(this: &this->m_StreamUnreliable, pStr: pReason);
      this->Transmit(this, a2: false);
    }
    m_StreamSocket = this->m_StreamSocket;
    if ( m_StreamSocket != 0 )
    {
      NET_CloseSocket(hSocket: m_StreamSocket, sock: this->m_Socket);
      this->m_StreamSocket = 0;
      this->m_StreamActive = false;
    }
    v5 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
    if ( v5 != 0 )
      NET_TerminateSteamConnection(sock: this->m_Socket, uSteamID: v5);
    this->m_Socket = -1;
    netadr_s::Clear(this: &this->remote_address);
    m_MessageHandler = this->m_MessageHandler;
    v7 = 0;
    if ( m_MessageHandler != nullptr )
    {
      m_MessageHandler->ConnectionClosing(this: m_MessageHandler, a2: pReason);
      this->m_MessageHandler = nullptr;
    }
    if ( this->m_NetMessages.m_Size > 0 )
    {
      do
      {
        v8 = this->m_NetMessages.m_Memory.m_pMemory[v7];
        if ( v8 != nullptr )
          ((void (__thiscall *)(INetMessage *, int))v8->dtr_INetMessage)(a1: v8, a2: 1);
        ++v7;
      }
      while ( v7 < this->m_NetMessages.m_Size );
    }
    this->m_NetMessages.m_Size = 0;
    if ( this->m_NetMessages.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_NetMessages.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NetMessages.m_Memory.m_pMemory);
        this->m_NetMessages.m_Memory.m_pMemory = nullptr;
      }
      this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
    }
    this->m_NetMessages.m_pElements = this->m_NetMessages.m_Memory.m_pMemory;
    this->m_DemoRecorder = nullptr;
    if ( this->m_bProcessingMessages )
    {
      NET_RemoveNetChannel(netchan: this, bDeleteNetChan: false);
      this->m_bShouldDelete = true;
    }
    else
    {
      NET_RemoveNetChannel(netchan: this, bDeleteNetChan: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACE40
// Name: private: bool CNetChan::ProcessMessages(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessMessages(CNetChan *this, bf_read *buf)
{
  IMDLCache *v2; // esi
  char v4; // bl

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  this->m_pActiveChannel = this;
  v4 = CNetChan::_ProcessMessages(this, buf);
  v2->EndLock(this: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101ACE80
// Name: public: virtual void CNetChan::ProcessPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ProcessPlayback(CNetChan *this)
{
  netpacket_s *i; // ebx
  int m_nOutSequenceNrAck; // edx
  IMDLCache *v4; // edi
  bool v5; // bl

  for ( i = demoplayer->ReadPacket(this: demoplayer); i != nullptr; i = demoplayer->ReadPacket(this: demoplayer) )
  {
    CNetChan::FlowNewPacket(
      this,
      flow: 1,
      seqnr: this->m_nInSequenceNr,
      acknr: this->m_nOutSequenceNrAck,
      nChoked: 0,
      nDropped: 0,
      nSize: i->wiresize);
    m_nOutSequenceNrAck = this->m_nOutSequenceNrAck;
    this->last_received = net_time;
    this->m_MessageHandler->PacketStart(
      this: this->m_MessageHandler,
      a2: this->m_nInSequenceNr,
      a3: m_nOutSequenceNrAck);
    v4 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    this->m_pActiveChannel = this;
    v5 = CNetChan::_ProcessMessages(this, buf: &i->message);
    v4->EndLock(this: v4);
    if ( !v5 )
      break;
    this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACF40
// Name: private: bool CNetChan::CheckReceivingList(int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNetChan::CheckReceivingList@<al>(CNetChan *this@<ecx>, int a2@<ebx>, int nList)
{
  bool v4; // zf
  CNetChan::dataFragments_s *v5; // esi
  char result; // al
  int ackedFragments; // eax
  int numFragments; // ecx
  const unsigned int *v9; // ecx
  void *v10; // eax
  unsigned int bytes; // [esp-10h] [ebp-40h]
  bf_read buffer; // [esp+8h] [ebp-28h] BYREF
  CNetChan *v13; // [esp+2Ch] [ebp-4h]

  v4 = this->m_ReceiveList[nList].buffer == nullptr;
  v5 = &this->m_ReceiveList[nList];
  v13 = this;
  if ( v4 )
    return 1;
  ackedFragments = this->m_ReceiveList[nList].ackedFragments;
  numFragments = this->m_ReceiveList[nList].numFragments;
  if ( ackedFragments < numFragments )
    return 1;
  if ( ackedFragments > numFragments )
  {
    ConMsg(a1: "Receiving failed: too many fragments %i/%i\n", ackedFragments, v5->numFragments);
    return 0;
  }
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "Receiving complete: %i fragments, %i bytes\n", numFragments, v5->bytes);
  if ( v5->isCompressed )
    CNetChan::UncompressFragments(this, data: v5);
  if ( v5->filename[0] != 0 )
  {
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: nullptr)
      || CL_ShouldRedownloadFile(filename: v5->filename) )
    {
      COM_CreatePath(path: v5->filename);
      v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: "wb", a4: 0);
      v5->file = v10;
      if ( v10 != nullptr )
      {
        ((void (__thiscall *)(IBaseFileSystem *, char *, unsigned int, void *, int))g_pFileSystem->Write)(
          a1: &g_pFileSystem->IBaseFileSystem,
          a2: v5->buffer,
          a3: v5->bytes,
          a4: v10,
          a5: a2);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5->file);
        if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
          DevMsg(a1: "FileReceived: %s, %i bytes (ID %i)\n", v5->filename, v5->bytes, v5->transferID);
        ((void (__thiscall *)(INetChannelHandler *, char *, unsigned int))v13->m_MessageHandler->FileReceived)(
          a1: v13->m_MessageHandler,
          a2: v5->filename,
          a3: v5->transferID);
      }
      else
      {
        ConMsg(a1: "Failed to write received file '%s'!\n", v5->filename);
      }
    }
    else
    {
      ConMsg(a1: "Download file '%s' already exists!\n", v5->filename);
    }
  }
  else
  {
    v9 = (const unsigned int *)v5->buffer;
    buffer.m_pDebugName = nullptr;
    buffer.m_nDataBytes = 0;
    bytes = v5->bytes;
    buffer.m_bOverflow = false;
    buffer.m_nDataBits = -1;
    CBitRead::StartReading(this: &buffer, pData: v9, nBytes: bytes, iStartBit: 0, nBits: -1);
    result = CNetChan::ProcessMessages(this: v13, buf: &buffer);
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
// Address: 0x101AD140
// Name: public: virtual void CNetChan::ProcessPacket(struct netpacket_s __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CNetChan::ProcessPacket(CNetChan *this, netpacket_s *packet, int bHasHeader)
{
  bf_read *p_message; // esi
  int m_nValue; // eax
  unsigned __int64 v6; // rax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int m_nOutSequenceNrAck; // eax
  INetChannelHandler *m_MessageHandler; // ecx
  int m_nBitsAvail; // ecx
  unsigned int v14; // eax
  char v15; // dl
  int v16; // ecx
  char v17; // cl
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  int v20; // eax
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edx
  unsigned int v24; // edi
  int v25; // edi
  unsigned int v26; // eax
  int v27; // edx
  const unsigned int *v29; // eax
  const unsigned int *v30; // ecx
  int m_nInReliableState; // eax
  int v32; // edi
  int m_pData; // eax
  IMDLCache *v34; // edi
  bool v35; // al
  IMDLCache_vtbl *v36; // edx
  const char *v37; // [esp+0h] [ebp-9Ch]
  unsigned __int64 v38; // [esp+4h] [ebp-98h]
  __int64 v39; // [esp+4h] [ebp-98h]
  const char *v40; // [esp+8h] [ebp-94h]
  char pDest[16]; // [esp+18h] [ebp-84h] BYREF
  int desc_112; // [esp+98h] [ebp-4h] OVERLAPPED
  unsigned int desc_124; // [esp+A4h] [ebp+8h]

  p_message = &packet->message;
  CBitRead::Seek(this: &packet->message, nPosition: 0);
  if ( netadr_s::IsValid(this: &this->remote_address)
    && !netadr_s::CompareAdr(this: &packet->from, a: &this->remote_address, onlyBase: false) )
  {
    return;
  }
  CNetchanParanoidMode::StartPacket(this: &g_NetParanoid, fullbuf: p_message);
  CNetChan::FlowUpdate(this, flow: 1, addbytes: packet->wiresize + 28);
  desc_112 = 0;
  if ( (_BYTE)bHasHeader != 0 )
  {
    desc_112 = CNetChan::ProcessPacketHeader(this, packet);
    if ( desc_112 == -1 )
      return;
  }
  CNetchanParanoidMode::NoteHeaderSize(this: &g_NetParanoid, msg: p_message, flags: desc_112);
  if ( net_showudp.m_pParent != nullptr )
  {
    m_nValue = net_showudp.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0
      && m_nValue != 3
      && (net_showudp_remoteonly.m_pParent == nullptr
       || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
       || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
    {
      v6 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
      bHasHeader = -14336;
      if ( v6 != 0 )
      {
        v38 = v6;
        bHasHeader = -10158081;
        v7 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v8 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                             a1: this,
                             a2: v7,
                             a3: v38,
                             a4: HIDWORD(v38));
        V_snprintf(pDest, maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v8, v37, v39);
      }
      else
      {
        v9 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v10 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v9);
        V_snprintf(pDest, maxLen: 128, pFormat: "%12.12s %21.21s", v10, v40);
      }
      ConColorMsg(
        a1: (const struct Color *)&bHasHeader,
        a2: "UDP <- %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f wire=%i\n",
        pDest,
        packet->size,
        this->m_nInSequenceNr & 0x3F,
        this->m_nOutSequenceNrAck & 0x3F,
        desc_112 & 1,
        (double)net_time,
        packet->wiresize);
    }
  }
  m_nOutSequenceNrAck = this->m_nOutSequenceNrAck;
  m_MessageHandler = this->m_MessageHandler;
  this->last_received = net_time;
  m_MessageHandler->PacketStart(this: m_MessageHandler, a2: this->m_nInSequenceNr, a3: m_nOutSequenceNrAck);
  if ( (desc_112 & 1) == 0 )
  {
LABEL_52:
    m_pData = (int)p_message->m_pData;
    if ( m_pData != 0 )
    {
      m_pData = 32 * (((int)p_message->m_pDataIn - m_pData) >> 2)
              - p_message->m_nBitsAvail
              + 8 * (p_message->m_nDataBytes & 3);
      if ( m_pData >= p_message->m_nDataBits )
        m_pData = p_message->m_nDataBits;
    }
    if ( p_message->m_nDataBits - m_pData <= 0
      || (v34 = mdlcache,
          mdlcache->BeginLock(this: mdlcache),
          this->m_pActiveChannel = this,
          v35 = CNetChan::_ProcessMessages(this, buf: p_message),
          v36 = v34->__vftable,
          HIBYTE(bHasHeader) = v35,
          v36->EndLock(this: v34),
          HIBYTE(bHasHeader) != 0) )
    {
      this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
      if ( this->m_DemoRecorder != nullptr && !demoplayer->IsPlayingBack(this: demoplayer) )
        this->m_DemoRecorder->RecordPacket(this: this->m_DemoRecorder);
    }
    return;
  }
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 3 )
  {
    v20 = 3 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    desc_124 = packet->message.m_nInBufWord;
    m_pBufferEnd = p_message->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p_message->m_nBitsAvail = 1;
      p_message->m_nInBufWord = 0;
      p_message->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p_message->m_bOverflow = true;
        p_message->m_nInBufWord = 0;
        goto LABEL_32;
      }
      p_message->m_nInBufWord = *m_pDataIn;
    }
    p_message->m_pDataIn = m_pDataIn + 1;
LABEL_32:
    if ( p_message->m_bOverflow )
    {
      v17 = 0;
    }
    else
    {
      m_nInBufWord = p_message->m_nInBufWord;
      v24 = (m_nInBufWord & CBitBuffer::s_nMaskTable[v20]) << p_message->m_nBitsAvail;
      p_message->m_nBitsAvail = 32 - v20;
      bHasHeader = v24;
      v17 = v24 | desc_124;
      p_message->m_nInBufWord = m_nInBufWord >> v20;
    }
    goto LABEL_35;
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
LABEL_35:
  v25 = 1 << v17;
  bHasHeader = 0;
  while ( 1 )
  {
    v26 = p_message->m_nInBufWord;
    v27 = v26 & 1;
    if ( p_message->m_nBitsAvail-- == 1 )
    {
      v29 = p_message->m_pDataIn;
      v30 = p_message->m_pBufferEnd;
      p_message->m_nBitsAvail = 32;
      if ( v29 == v30 )
      {
        p_message->m_nBitsAvail = 1;
        p_message->m_nInBufWord = 0;
        p_message->m_pDataIn = v29 + 1;
      }
      else if ( v29 <= v30 )
      {
        p_message->m_nInBufWord = *v29;
        p_message->m_pDataIn = v29 + 1;
      }
      else
      {
        p_message->m_bOverflow = true;
        p_message->m_nInBufWord = 0;
      }
    }
    else
    {
      p_message->m_nInBufWord = v26 >> 1;
    }
    if ( v27 != 0 && !CNetChan::ReadSubChannelData(this, buf: p_message, stream: bHasHeader) )
      break;
    if ( ++bHasHeader >= 2 )
    {
      m_nInReliableState = this->m_nInReliableState;
      if ( (m_nInReliableState & v25) != 0 )
        this->m_nInReliableState = m_nInReliableState & ~v25;
      else
        this->m_nInReliableState = v25 | m_nInReliableState;
      v32 = 0;
      while ( CNetChan::CheckReceivingList(this, nList: v32) )
      {
        if ( ++v32 >= 2 )
          goto LABEL_52;
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD560
// Name: public: virtual bool CNetChan::ProcessStream(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::ProcessStream(CNetChan *this)
{
  int m_StreamSocket; // eax
  int v4; // eax
  int m_SteamType; // eax
  int v6; // eax
  int m_nBitsAvail; // esi
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *m_pDataIn; // eax
  unsigned int m_nInBufWord_high; // edx
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ebx
  int v21; // eax
  unsigned int v22; // esi
  unsigned int v23; // edx
  unsigned int v24; // esi
  CNetChan::dataFragments_s **v25; // edx
  const char *v26; // eax
  const char *v27; // eax
  int m_StreamReceived; // ecx
  int m_StreamLength; // eax
  int v30; // eax
  int v31; // ecx
  signed int v32; // eax
  int m_StreamSeqNr; // esi
  unsigned __int8 *m_pMemory; // [esp-14h] [ebp-274h]
  int v35; // [esp-Ch] [ebp-26Ch]
  int v36; // [esp-8h] [ebp-268h]
  int v37; // [esp-8h] [ebp-268h]
  char headerBuf[512]; // [esp+8h] [ebp-258h] BYREF
  bf_read buffer; // [esp+208h] [ebp-58h] BYREF
  unsigned int v40; // [esp+22Ch] [ebp-34h]
  unsigned int v41; // [esp+230h] [ebp-30h]
  char cmd; // [esp+237h] [ebp-29h] BYREF
  signed int m_nInBufWord; // [esp+238h] [ebp-28h]
  bf_read header; // [esp+23Ch] [ebp-24h] BYREF

  m_StreamSocket = this->m_StreamSocket;
  if ( m_StreamSocket == 0 )
    return true;
  if ( this->m_SteamType == 0 )
  {
    v4 = NET_ReceiveStream(nSock: m_StreamSocket, buf: &cmd, len: 1, flags: 0);
    if ( v4 == 0 )
      return true;
    if ( v4 == -1 )
      return false;
    this->ResetStreaming(this);
    this->m_SteamType = cmd;
  }
  header.m_bOverflow = false;
  header.m_nDataBits = -1;
  header.m_nDataBytes = 0;
  header.m_pDebugName = "inDataHeader";
  CBitRead::StartReading(this: &header, pData: (const unsigned int *)headerBuf, nBytes: 0x200u, iStartBit: 0, nBits: -1);
  m_SteamType = this->m_SteamType;
  if ( m_SteamType == 1 )
  {
    this->m_StreamActive = true;
    this->ResetStreaming(this);
    return CNetChan::SendReliableAcknowledge(this, seqnr: this->m_ChallengeNr);
  }
  if ( m_SteamType != 2 || this->m_StreamLength != 0 )
    goto LABEL_49;
  v6 = NET_ReceiveStream(nSock: this->m_StreamSocket, buf: headerBuf, len: 6, flags: 0);
  if ( v6 == 0 )
    return true;
  if ( v6 == -1 )
    return false;
  m_nBitsAvail = header.m_nBitsAvail;
  m_pBufferEnd = header.m_pBufferEnd;
  if ( header.m_nBitsAvail < 16 )
  {
    m_nInBufWord = header.m_nInBufWord;
    m_pDataIn = header.m_pDataIn;
    v11 = 16 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord_high = 0;
      m_nBitsAvail = 1;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    if ( header.m_pDataIn > header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord_high = 0;
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    m_nInBufWord_high = *header.m_pDataIn;
    m_pDataIn = header.m_pDataIn + 1;
    header.m_nInBufWord = *header.m_pDataIn++;
    if ( header.m_bOverflow )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    v41 = m_nInBufWord_high & CBitBuffer::s_nMaskTable[v11];
    m_nInBufWord |= v41 << SLOBYTE(header.m_nBitsAvail);
    m_nBitsAvail = 32 - v11;
    m_nInBufWord_high >>= v11;
    m_pBufferEnd = header.m_pBufferEnd;
    header.m_nBitsAvail = 32 - v11;
  }
  else
  {
    m_pDataIn = header.m_pDataIn;
    m_nBitsAvail = header.m_nBitsAvail - 16;
    header.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      m_nInBufWord_high = HIWORD(header.m_nInBufWord);
      m_nInBufWord = LOWORD(header.m_nInBufWord);
    }
    else
    {
      m_nBitsAvail = 32;
      header.m_nBitsAvail = 32;
      if ( header.m_pDataIn == header.m_pBufferEnd )
      {
        m_nInBufWord_high = 0;
        m_nBitsAvail = 1;
        m_pDataIn = header.m_pDataIn + 1;
        header.m_nBitsAvail = 1;
        ++header.m_pDataIn;
        m_nInBufWord = LOWORD(header.m_nInBufWord);
      }
      else
      {
        if ( header.m_pDataIn <= header.m_pBufferEnd )
        {
          m_nInBufWord_high = *header.m_pDataIn;
          m_pDataIn = ++header.m_pDataIn;
        }
        else
        {
          header.m_bOverflow = true;
          m_nInBufWord_high = 0;
        }
        m_nInBufWord = LOWORD(header.m_nInBufWord);
      }
    }
  }
  header.m_nInBufWord = m_nInBufWord_high;
LABEL_31:
  this->m_StreamLength = m_nInBufWord;
  if ( m_nBitsAvail < 32 )
  {
    v41 = m_nInBufWord_high;
    v14 = 32 - m_nBitsAvail;
    if ( m_pDataIn == m_pBufferEnd )
    {
      header.m_pDataIn = m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      header.m_bOverflow = true;
      v12 = 0;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      v15 = *m_pDataIn;
      header.m_nInBufWord = *m_pDataIn;
      header.m_pDataIn = m_pDataIn + 1;
      if ( header.m_bOverflow )
      {
        v12 = 0;
      }
      else
      {
        v16 = (v15 & CBitBuffer::s_nMaskTable[v14]) << m_nBitsAvail;
        header.m_nBitsAvail = m_nBitsAvail;
        v40 = v16;
        v12 = v16 | v41;
        header.m_nInBufWord = v15 >> v14;
      }
    }
    else
    {
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      v12 = 0;
    }
  }
  else
  {
    header.m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      header.m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        header.m_pDataIn = m_pDataIn + 1;
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        v12 = m_nInBufWord_high;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v13 = *m_pDataIn;
          header.m_pDataIn = m_pDataIn + 1;
          header.m_nInBufWord = v13;
        }
        else
        {
          header.m_bOverflow = true;
          header.m_nInBufWord = 0;
        }
        v12 = m_nInBufWord_high;
      }
    }
    else
    {
      header.m_nInBufWord = 0;
      v12 = m_nInBufWord_high;
    }
  }
  this->m_StreamSeqNr = v12;
  if ( m_nInBufWord > 96000 )
  {
    ConMsg(a1: "ERROR! Stream indata too big (%i)", m_nInBufWord);
    return false;
  }
LABEL_49:
  v17 = this->m_SteamType;
  if ( v17 == 3 && this->m_SteamFile[0] == 0 )
    return false;
  if ( v17 != 4 || this->m_StreamSeqNr != 0 )
  {
    m_StreamReceived = this->m_StreamReceived;
    m_StreamLength = this->m_StreamLength;
    if ( m_StreamReceived >= m_StreamLength )
      return true;
    v30 = NET_ReceiveStream(
            nSock: this->m_StreamSocket,
            buf: (char *)&this->m_StreamData.m_pMemory[m_StreamReceived],
            len: m_StreamLength - m_StreamReceived,
            flags: 0);
    if ( v30 == 0 )
      return true;
    if ( v30 != -1 )
    {
      this->m_StreamReceived += v30;
      v31 = this->m_StreamReceived;
      v32 = this->m_StreamLength;
      if ( v31 > v32 )
      {
        ConMsg(a1: "ERROR! Stream indata oversize.");
        return false;
      }
      if ( v31 == v32 )
      {
        m_StreamSeqNr = this->m_StreamSeqNr;
        m_pMemory = this->m_StreamData.m_pMemory;
        buffer.m_bOverflow = false;
        buffer.m_pDebugName = nullptr;
        buffer.m_nDataBits = -1;
        buffer.m_nDataBytes = 0;
        CBitRead::StartReading(
          this: &buffer,
          pData: (const unsigned int *)m_pMemory,
          nBytes: v32,
          iStartBit: 0,
          nBits: -1);
        CNetChan::ProcessMessages(this, buf: &buffer);
        this->ResetStreaming(this);
        return CNetChan::SendReliableAcknowledge(this, seqnr: m_StreamSeqNr);
      }
      return true;
    }
    return false;
  }
  v18 = NET_ReceiveStream(nSock: this->m_StreamSocket, buf: headerBuf, len: 4, flags: 0);
  if ( v18 == 0 )
    return true;
  if ( v18 == -1 )
    return false;
  if ( header.m_nBitsAvail < 32 )
  {
    v20 = header.m_nInBufWord;
    v21 = 32 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      v19 = 0;
    }
    else if ( header.m_pDataIn <= header.m_pBufferEnd )
    {
      v22 = *header.m_pDataIn;
      header.m_nInBufWord = *header.m_pDataIn++;
      if ( header.m_bOverflow )
      {
        v19 = 0;
      }
      else
      {
        v23 = (v22 & CBitBuffer::s_nMaskTable[v21]) << SLOBYTE(header.m_nBitsAvail);
        v24 = v22 >> v21;
        v19 = v23 | v20;
        header.m_nInBufWord = v24;
      }
    }
    else
    {
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      v19 = 0;
    }
  }
  else
  {
    v19 = header.m_nInBufWord;
    header.m_nBitsAvail -= 32;
    if ( header.m_nBitsAvail != 0 )
    {
      header.m_nInBufWord = 0;
    }
    else
    {
      header.m_nBitsAvail = 32;
      if ( header.m_pDataIn == header.m_pBufferEnd )
      {
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        ++header.m_pDataIn;
      }
      else if ( header.m_pDataIn <= header.m_pBufferEnd )
      {
        header.m_nInBufWord = *header.m_pDataIn++;
      }
      else
      {
        header.m_bOverflow = true;
        header.m_nInBufWord = 0;
      }
    }
  }
  v25 = this->m_WaitingList[0].m_Memory.m_pMemory;
  this->m_StreamSeqNr = v19;
  if ( (*v25)->transferID != v19 )
  {
    v37 = v19;
    v35 = this->m_StreamLength;
    v27 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP <- %s: invalid ACKN streamlen %d seqnr %i\n", v27, v35, v37);
    this->ResetStreaming(this);
    return true;
  }
  if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
  {
    v36 = v19;
    v26 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP <- %s: ACKN seq=%i\n", v26, v36);
  }
  CNetChan::RemoveHeadInWaitingList(this, nList: 0);
  this->ResetStreaming(this);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101ADAE0
// Name: private: void CNetChan::MergeSplitUserBuffers(enum CNetChan::EBufType,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::MergeSplitUserBuffers(CNetChan *this, CNetChan::EBufType eBufType, bf_write *outbuf)
{
  unsigned __int16 Inorder; // di
  UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *m_pMemory; // ecx
  int *p_m_nSlot; // edx
  INetChannel *m_pChannel; // eax
  bf_write *v8; // esi
  NET_SplitScreenUser v9; // [esp+8h] [ebp-18h] BYREF
  int nCurrentSlot; // [esp+1Ch] [ebp-4h]

  nCurrentSlot = 0;
  Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SplitPlayers);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = this->m_SplitPlayers.m_Elements.m_pMemory;
      p_m_nSlot = &m_pMemory[Inorder].m_Data.m_nSlot;
      m_pChannel = m_pMemory[Inorder].m_Data.m_pChannel;
      if ( m_pChannel != nullptr )
        break;
LABEL_13:
      Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_SplitPlayers,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
      {
        if ( nCurrentSlot != 0 )
        {
          NET_SplitScreenUser::NET_SplitScreenUser(this: &v9, slot: 0);
          NET_SplitScreenUser::WriteToBuffer(this: &v9, buffer: outbuf);
        }
        return;
      }
    }
    if ( eBufType != BUF_RELIABLE )
    {
      if ( eBufType == BUF_UNRELIABLE )
      {
        v8 = (bf_write *)&m_pChannel[17];
        goto LABEL_9;
      }
      if ( eBufType == BUF_VOICE )
      {
        v8 = (bf_write *)&m_pChannel[26];
        goto LABEL_9;
      }
    }
    v8 = (bf_write *)&m_pChannel[8];
LABEL_9:
    if ( v8->m_iCurBit > 0 )
    {
      if ( *p_m_nSlot != nCurrentSlot )
      {
        nCurrentSlot = *p_m_nSlot;
        NET_SplitScreenUser::NET_SplitScreenUser(this: &v9, slot: nCurrentSlot);
        NET_SplitScreenUser::WriteToBuffer(this: &v9, buffer: outbuf);
      }
      bf_write::WriteBits(this: outbuf, pInData: v8->m_pData, nBits: v8->m_iCurBit);
      bf_write::Reset(this: v8);
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADE80
// Name: private: bool CNetChan::CreateFragmentsFromBuffer(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::CreateFragmentsFromBuffer(CNetChan *this, bf_write *buffer, int stream)
{
  CUtlMemory<S3RGBA,int> *v4; // ebx
  int m_pMemory; // eax
  void *v6; // esi
  signed int v7; // eax
  int v8; // edi
  void *v9; // ebx
  int v10; // edi
  void *v11; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *v13; // edi
  S3RGBA *v14; // ebx
  S3RGBA *v15; // ecx
  int v16; // eax
  S3RGBA *v17; // ebx
  CNetChan *v18; // ecx
  unsigned int v19; // eax
  bool v20; // al
  unsigned int v21; // edx
  int v23; // [esp-8h] [ebp-30h]
  bf_write bfwrite; // [esp+Ch] [ebp-1Ch] BYREF
  CNetChan *v25; // [esp+24h] [ebp-4h]

  v25 = this;
  bf_write::bf_write(this: &bfwrite);
  v4 = (CUtlMemory<S3RGBA,int> *)((char *)this + 20 * stream);
  m_pMemory = (int)v4[17].m_pMemory;
  if ( m_pMemory > 1
    && (v6 = (void *)v4[16].m_pMemory[m_pMemory - 1],
        v7 = ((unsigned int)(buffer->m_iCurBit + *((_DWORD *)v6 + 68) + 7) >> 3) + 3,
        (v8 = 4 * (v7 / 4)) < 96000)
    && *((_DWORD *)v6 + 66) != 0 )
  {
    v9 = MemAlloc_Alloc(nSize: 4 * (v7 / 4));
    _V_memcpy(dest: v9, src: *((const void **)v6 + 66), count: *((_DWORD *)v6 + 67));
    free(pMem: *((void **)v6 + 66));
    v23 = *((_DWORD *)v6 + 68);
    *((_DWORD *)v6 + 66) = v9;
    bf_write::StartWriting(this: &bfwrite, pData: v9, nBytes: v8, iStartBit: v23, nBits: -1);
  }
  else
  {
    v10 = 4 * ((((buffer->m_iCurBit + 7) >> 3) + 3) / 4);
    v6 = MemAlloc_Alloc(nSize: 0x130u);
    *((_DWORD *)v6 + 67) = 0;
    *((_DWORD *)v6 + 68) = 0;
    v11 = MemAlloc_Alloc(nSize: v10);
    *((_DWORD *)v6 + 66) = v11;
    *((_BYTE *)v6 + 280) = 0;
    *((_BYTE *)v6 + 289) = 0;
    *((_DWORD *)v6 + 71) = 0;
    *(_DWORD *)v6 = 0;
    *((_BYTE *)v6 + 4) = 0;
    bf_write::StartWriting(this: &bfwrite, pData: v11, nBytes: v10, iStartBit: 0, nBits: -1);
    m_nAllocationCount = v4[16].m_nAllocationCount;
    v13 = v4 + 16;
    v14 = v4[17].m_pMemory;
    if ( (int)&v14->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: v13, num: (int)(&v14->g - m_nAllocationCount));
    ++v13[1].m_pMemory;
    v15 = v13->m_pMemory;
    v16 = (char *)v13[1].m_pMemory - (char *)v14 - 1;
    v13[1].m_nAllocationCount = (int)v13->m_pMemory;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[(_DWORD)v14 + 1], src: &v15[(_DWORD)v14], count: 4 * v16);
    v17 = &v13->m_pMemory[(_DWORD)v14];
    if ( v17 != nullptr )
      *v17 = (S3RGBA)v6;
  }
  bf_write::WriteBits(this: &bfwrite, pInData: buffer->m_pData, nBits: buffer->m_iCurBit);
  if ( (unsigned int)(bfwrite.m_iCurBit % 8 - 1) <= 1 )
    bf_write::WriteUBitLong(this: &bfwrite, curData: 0, numbits: 6, bCheckRange: true);
  *((_DWORD *)v6 + 68) += buffer->m_iCurBit;
  v18 = v25;
  v19 = (unsigned int)(*((_DWORD *)v6 + 68) + 7) >> 3;
  *((_DWORD *)v6 + 67) = v19;
  v20 = v18->m_StreamActive && v19 > v18->m_MaxReliablePayloadSize;
  v21 = *((_DWORD *)v6 + 67) + 255;
  *((_BYTE *)v6 + 288) = v20;
  *((_DWORD *)v6 + 74) = 0;
  *((_DWORD *)v6 + 75) = 0;
  *((_DWORD *)v6 + 73) = v21 >> 8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AE0B0
// Name: private: bool CNetChan::CreateFragmentsFromFile(char const __near *,int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::CreateFragmentsFromFile(
        CNetChan *this,
        const char *filename,
        int stream,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  int v6; // ebx
  int m_nValue; // ecx
  int v8; // eax
  CNetChan::dataFragments_s *v9; // esi
  void *v10; // eax
  int m_Size; // ebx
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v12; // edi
  int m_nAllocationCount; // eax
  CNetChan::dataFragments_s **m_pMemory; // ecx
  int v15; // eax
  CNetChan::dataFragments_s **v16; // ebx
  unsigned int v17; // ecx

  if ( CNetChan::IsFileInWaitingList(this, filename) != 0 )
    return 1;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "GAME") )
  {
    v6 = g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "GAME");
    if ( net_maxfilesize.m_pParent != nullptr )
      m_nValue = net_maxfilesize.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( v6 < m_nValue << 20 )
    {
      if ( v6 < 0x3FFFFFF )
      {
        v9 = (CNetChan::dataFragments_s *)MemAlloc_Alloc(nSize: 0x130u);
        v9->bytes = v6;
        v9->bits = 8 * v6;
        v9->isReplayDemo = bIsReplayDemoFile;
        v9->buffer = nullptr;
        v9->isCompressed = false;
        v9->nUncompressedSize = 0;
        v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "rb", a4: "GAME");
        v9->file = v10;
        if ( v10 != nullptr )
        {
          v9->transferID = transferID;
          V_strncpy(pDest: v9->filename, pSrc: filename, maxLen: 260);
          m_Size = this->m_WaitingList[stream].m_Size;
          v12 = &this->m_WaitingList[stream];
          m_nAllocationCount = this->m_WaitingList[stream].m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_WaitingList[stream],
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_WaitingList[stream].m_Size;
          m_pMemory = v12->m_Memory.m_pMemory;
          v15 = this->m_WaitingList[stream].m_Size - m_Size - 1;
          this->m_WaitingList[stream].m_pElements = this->m_WaitingList[stream].m_Memory.m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v16 = &v12->m_Memory.m_pMemory[m_Size];
          if ( v16 != nullptr )
            *v16 = v9;
          v17 = (v9->bytes + 255) >> 8;
          v9->asTCP = false;
          v9->ackedFragments = 0;
          v9->pendingFragments = 0;
          v9->numFragments = v17;
          return 1;
        }
        else
        {
          ConMsg(a1: "CreateFragmentsFromFile: couldn't open '%s'.\n", filename);
          free(pMem: v9);
          return 0;
        }
      }
      else
      {
        ConMsg(a1: "CreateFragmentsFromFile: '%s' too big (max %i bytes).\n", filename, 0x3FFFFFF);
        return 0;
      }
    }
    else
    {
      if ( net_maxfilesize.m_pParent != nullptr )
        v8 = net_maxfilesize.m_pParent->m_Value.m_nValue;
      else
        v8 = 0;
      ConMsg(a1: "CreateFragmentsFromFile: '%s' size exceeds net_maxfilesize limit (%i MB).\n", filename, v8);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "CreateFragmentsFromFile: '%s' doesn't exist.\n", filename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE2C0
// Name: public: virtual int CNetChan::SendDatagram(class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::SendDatagram(CNetChan *this, float datagram)
{
  int v3; // edi
  int m_nValue; // eax
  const char *v6; // eax
  int v7; // ebx
  int m_nChokedPackets; // eax
  int v9; // ecx
  int m_iCurBit; // eax
  int v11; // edi
  int i; // eax
  int v13; // ecx
  int v14; // eax
  unsigned __int16 v15; // ax
  bf_write *v16; // edi
  int v17; // eax
  unsigned __int64 v18; // rax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  bf_write *v23; // edi
  long double v24; // st7
  long double v25; // st6
  long double v26; // st7
  int v27; // eax
  int v28; // [esp-8h] [ebp-1782Ch]
  int m_nInSequenceNr; // [esp-4h] [ebp-17828h]
  const char *v30; // [esp+0h] [ebp-17824h]
  int v31; // [esp+0h] [ebp-17824h]
  unsigned __int64 v32; // [esp+4h] [ebp-17820h]
  __int64 v33; // [esp+4h] [ebp-17820h]
  const char *v34; // [esp+8h] [ebp-1781Ch]
  int m_nOutSequenceNr; // [esp+Ch] [ebp-17818h]
  double v36[3]; // [esp+18h] [ebp-1780Ch] BYREF
  char v37[24]; // [esp+17728h] [ebp-FCh] BYREF
  char v38[64]; // [esp+177A8h] [ebp-7Ch] BYREF
  bf_write v39; // [esp+177E8h] [ebp-3Ch] BYREF
  int v40; // [esp+17800h] [ebp-24h]
  int v41; // [esp+17804h] [ebp-20h]
  bf_write v42; // [esp+17808h] [ebp-1Ch] BYREF
  unsigned __int8 v43; // [esp+17823h] [ebp-1h]

  if ( this->m_Socket == 0 )
  {
    v3 = net_maxroutable.m_pParent != nullptr ? net_maxroutable.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != this->GetMaxRoutablePayloadSize(this) )
    {
      if ( net_maxroutable.m_pParent != nullptr )
        m_nValue = net_maxroutable.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      this->SetMaxRoutablePayloadSize(this, a2: m_nValue);
    }
  }
  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) != NA_NULL )
  {
    if ( this->m_SplitPlayers.m_NumElements != 0 )
    {
      CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_RELIABLE, outbuf: &this->m_StreamReliable);
      CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_UNRELIABLE, outbuf: &this->m_StreamUnreliable);
      CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_VOICE, outbuf: &this->m_StreamVoice);
    }
    if ( this->m_StreamReliable.m_bOverflow )
    {
      v6 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      ConMsg(a1: "%s:send reliable stream overflow\n", v6);
      return 0;
    }
    else
    {
      if ( this->m_StreamReliable.m_iCurBit > 0 )
      {
        CNetChan::CreateFragmentsFromBuffer(this, buffer: &this->m_StreamReliable, stream: 0);
        bf_write::Reset(this: &this->m_StreamReliable);
      }
      bf_write::bf_write(this: &v42, pDebugName: "CNetChan_TransmitBits->send", pData: v36, nBytes: 96016, nBits: -1);
      m_nOutSequenceNr = this->m_nOutSequenceNr;
      v43 = 0;
      bf_write::WriteLong(this: &v42, val: m_nOutSequenceNr);
      bf_write::WriteLong(this: &v42, val: this->m_nInSequenceNr);
      v39 = v42;
      bf_write::WriteByte(this: &v42, val: 0);
      if ( NET_IsMultiplayer() )
        bf_write::WriteShort(this: &v42, val: 0);
      v7 = (v42.m_iCurBit + 7) >> 3;
      bf_write::WriteByte(this: &v42, val: this->m_nInReliableState);
      m_nChokedPackets = this->m_nChokedPackets;
      if ( m_nChokedPackets > 0 )
      {
        v43 = 16;
        bf_write::WriteByte(this: &v42, val: (unsigned __int8)m_nChokedPackets);
      }
      if ( CNetChan::SendSubChannelData(this, buf: &v42) )
        v43 |= 1u;
      if ( datagram != 0.0 )
      {
        v9 = *(_DWORD *)(LODWORD(datagram) + 12);
        if ( v9 >= v42.m_nDataBits - v42.m_iCurBit )
          _ConDMsg(a1: "CNetChan::SendDatagram:  data would overfow, ignoring\n");
        else
          bf_write::WriteBits(this: &v42, pInData: *(const void **)LODWORD(datagram), nBits: v9);
      }
      if ( this->m_StreamUnreliable.m_iCurBit >= v42.m_nDataBits - v42.m_iCurBit )
        _ConDMsg(a1: "CNetChan::SendDatagram:  Unreliable would overfow, ignoring\n");
      else
        bf_write::WriteBits(
          this: &v42,
          pInData: this->m_StreamUnreliable.m_pData,
          nBits: this->m_StreamUnreliable.m_iCurBit);
      bf_write::Reset(this: &this->m_StreamUnreliable);
      m_iCurBit = this->m_StreamVoice.m_iCurBit;
      if ( m_iCurBit > 0 && m_iCurBit < v42.m_nDataBits - v42.m_iCurBit )
      {
        bf_write::WriteBits(this: &v42, pInData: this->m_StreamVoice.m_pData, nBits: this->m_StreamVoice.m_iCurBit);
        bf_write::Reset(this: &this->m_StreamVoice);
      }
      v11 = 16;
      if ( this->m_Socket == 1 )
      {
        if ( net_minroutable.m_pParent != nullptr )
          v11 = net_minroutable.m_pParent->m_Value.m_nValue;
        else
          v11 = 0;
      }
      for ( i = v42.m_iCurBit; (v42.m_iCurBit + 7) >> 3 < v11; i = v42.m_iCurBit )
        bf_write::WriteUBitLong(this: &v42, curData: 0, numbits: 6, bCheckRange: true);
      if ( (unsigned int)(i % 8 - 1) <= 1 )
        bf_write::WriteUBitLong(this: &v42, curData: 0, numbits: 6, bCheckRange: true);
      v13 = v42.m_iCurBit % 8;
      if ( v42.m_iCurBit % 8 > 0 )
      {
        v43 |= 32 * (8 - v13);
        if ( 8 - v13 > 0 )
          bf_write::WriteUBitLong(
            this: &v42,
            curData: `GetBitForBitnum'::`2'::bitsForBitnum[(8 - v13) & 0x1F] - 1,
            numbits: 8 - v13,
            bCheckRange: true);
      }
      LOBYTE(datagram) = 0;
      if ( net_compresspackets.m_pParent != nullptr && net_compresspackets.m_pParent->m_Value.m_nValue != 0 )
      {
        v14 = net_compresspackets_minsize.m_pParent != nullptr
            ? net_compresspackets_minsize.m_pParent->m_Value.m_nValue
            : 0;
        if ( (v42.m_iCurBit + 7) >> 3 >= v14 )
          LOBYTE(datagram) = 1;
      }
      v41 = v43;
      bf_write::WriteByte(this: &v39, val: v43);
      if ( NET_IsMultiplayer() )
      {
        v15 = BufferToShortChecksum(pvData: &v42.m_pData[v7], nLength: ((v42.m_iCurBit + 7) >> 3) - v7);
        bf_write::WriteUBitLong(this: &v39, curData: v15, numbits: 16, bCheckRange: true);
      }
      v16 = (bf_write *)NET_SendPacket(
                          chan: this,
                          sock: this->m_Socket,
                          to: &this->remote_address,
                          data: v42.m_pData,
                          length: (v42.m_iCurBit + 7) >> 3,
                          pVoicePayload: nullptr,
                          bUseCompression: SLOBYTE(datagram),
                          unMillisecondsDelay: 0);
      datagram = *(float *)&v16;
      bf_write::Reset(this: &this->m_StreamVoice);
      if ( net_showudp.m_pParent != nullptr )
      {
        v17 = net_showudp.m_pParent->m_Value.m_nValue;
        if ( v17 != 0
          && v17 != 2
          && (net_showudp_remoteonly.m_pParent == nullptr
           || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
           || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
        {
          memset(v38, 0, sizeof(v38));
          if ( net_compresspackets.m_pParent != nullptr
            && net_compresspackets.m_pParent->m_Value.m_nValue != 0
            && v16 != nullptr )
          {
            v40 = (v42.m_iCurBit + 7) >> 3;
            if ( (int)v16 < v40 )
              V_snprintf(
                pDest: v38,
                maxLen: 64,
                pFormat: " compression=%5u [%5.2f %%]",
                v16,
                (double)SLODWORD(datagram) * 100.0 / (double)v40);
          }
          v18 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
          datagram = NAN;
          if ( v18 != 0 )
          {
            datagram = -3.0439319e38;
            v32 = v18;
            v19 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
            v20 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                                  a1: this,
                                  a2: v19,
                                  a3: v32,
                                  a4: HIDWORD(v32));
            V_snprintf(pDest: v37, maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v20, v30, v33);
          }
          else
          {
            v21 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
            v22 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v21);
            V_snprintf(pDest: v37, maxLen: 128, pFormat: "%12.12s %21.21s", v22, v34);
          }
          ConColorMsg(
            a1: (const struct Color *)&datagram,
            a2: "UDP -> %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f%s\n",
            v37,
            (v42.m_iCurBit + 7) >> 3,
            this->m_nOutSequenceNr & 0x3F,
            this->m_nInSequenceNr & 0x3F,
            v41 & 1,
            (double)net_time,
            v38);
        }
      }
      v23 = (bf_write *)((char *)v16 + 28);
      v31 = this->m_nChokedPackets;
      m_nInSequenceNr = this->m_nInSequenceNr;
      v28 = this->m_nOutSequenceNr;
      datagram = *(float *)&v23;
      CNetChan::FlowNewPacket(
        this,
        flow: 0,
        seqnr: v28,
        acknr: m_nInSequenceNr,
        nChoked: v31,
        nDropped: 0,
        nSize: (int)v23);
      CNetChan::FlowUpdate(this, flow: 0, addbytes: (int)v23);
      if ( net_time > this->m_fClearTime )
        this->m_fClearTime = net_time;
      v24 = (double)SLODWORD(datagram) / (double)this->m_Rate + this->m_fClearTime;
      this->m_fClearTime = v24;
      datagram = net_maxcleartime.m_pParent->m_Value.m_fValue;
      if ( datagram > 0.0 )
      {
        v25 = v24;
        v26 = datagram + net_time;
        if ( v25 > v26 )
          this->m_fClearTime = v26;
      }
      v27 = ++this->m_nOutSequenceNr;
      this->m_nChokedPackets = 0;
      return v27 - 1;
    }
  }
  else
  {
    this->m_fClearTime = 0.0;
    this->m_nChokedPackets = 0;
    bf_write::Reset(this: &this->m_StreamReliable);
    bf_write::Reset(this: &this->m_StreamUnreliable);
    return this->m_nOutSequenceNr++;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE890
// Name: public: virtual bool CNetChan::RegisterMessage(class INetMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::RegisterMessage(CNetChan *this, INetMessage *msg)
{
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  INetMessage **m_pMemory; // ecx
  int v8; // eax
  INetMessage **v9; // eax

  v3 = msg->GetType(this: msg);
  if ( CNetChan::FindMessage(this, type: v3) != nullptr )
    return 0;
  m_nAllocationCount = this->m_NetMessages.m_Memory.m_nAllocationCount;
  m_Size = this->m_NetMessages.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_NetMessages,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_NetMessages.m_Size;
  m_pMemory = this->m_NetMessages.m_Memory.m_pMemory;
  v8 = this->m_NetMessages.m_Size - m_Size - 1;
  this->m_NetMessages.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_NetMessages.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = msg;
  msg->SetNetChannel(this: msg, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AEA10
// Name: public: virtual bool CNetChan::SendFile(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendFile(
        CNetChan *this,
        const char *filename,
        unsigned int transferID,
        BOOL bIsReplayDemoFile)
{
  bool result; // al

  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL )
    return true;
  result = CNetChan::IsValidFileTransferExtension(pFilename: filename);
  if ( result )
  {
    if ( CNetChan::CreateFragmentsFromFile(this, filename, stream: 1, transferID, bIsReplayDemoFile) )
    {
      if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
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
// Address: 0x101AEAA0
// Name: public: CNetChan::CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetChan::CNetChan(CNetChan *this)
{
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // eax
  int i; // ecx

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
  this->m_StreamData.m_pMemory = nullptr;
  this->m_StreamData.m_nAllocationCount = 0;
  this->m_StreamData.m_nGrowSize = 0;
  this->m_NetMessages.m_Memory.m_pMemory = nullptr;
  this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
  this->m_NetMessages.m_Memory.m_nGrowSize = 0;
  this->m_NetMessages.m_Size = 0;
  this->m_NetMessages.m_pElements = nullptr;
  this->m_SplitPlayers.m_LessFunc = (bool (__cdecl *)(const CNetChan::SplitPlayer_t *, const CNetChan::SplitPlayer_t *))CIPRateLimit::LessIP;
  this->m_SplitPlayers.m_Elements.m_pMemory = nullptr;
  this->m_SplitPlayers.m_Elements.m_nAllocationCount = 0;
  this->m_SplitPlayers.m_Elements.m_nGrowSize = 0;
  this->m_SplitPlayers.m_pElements = this->m_SplitPlayers.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_SplitPlayers.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_SplitPlayers.m_FirstFree = -1;
  this->m_pActiveChannel = this;
  this->m_nSplitPacketSequence = 1;
  this->m_nMaxRoutablePayloadSize = 1200;
  *(_WORD *)&this->m_bProcessingMessages = 0;
  this->m_bStopProcessing = false;
  this->m_Socket = -1;
  netadr_s::Clear(this: &this->remote_address);
  this->connect_time = 0.0;
  this->last_received = 0.0;
  V_strncpy(pDest: this->m_Name, pSrc: defaultValue, maxLen: 32);
  this->m_MessageHandler = nullptr;
  this->m_DemoRecorder = nullptr;
  CNetworkStringTable::SetTick(this: &this->m_StreamUnreliable, pDebugName: "netchan_t::unreliabledata");
  CNetworkStringTable::SetTick(this: &this->m_StreamReliable, pDebugName: "netchan_t::reliabledata");
  this->m_Timeout = 300.0;
  this->m_Rate = 10000;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_ChallengeNr = 0;
  this->m_StreamSocket = 0;
  this->m_StreamActive = false;
  this->m_SteamType = 0;
  this->m_StreamLength = 0;
  this->m_StreamReceived = 0;
  this->m_StreamSeqNr = 0;
  this->m_SteamFile[0] = 0;
  this->m_MaxReliablePayloadSize = 96000;
  this->m_FileRequestCounter = 0;
  *(_WORD *)&this->m_bFileBackgroundTranmission = 1;
  this->m_nQueuedPackets = 0;
  this->m_flRemoteFrameTime = 0.0;
  this->m_flRemoteFrameTimeStdDeviation = 0.0;
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 60);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101AECE0
// Name: public: virtual CNetChan::~CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::~CNetChan(CNetChan *this)
{
  CNetChan::dataFragments_s *m_ReceiveList; // esi
  void *file; // eax
  int i; // [esp+8h] [ebp-4h]

  this->__vftable = (CNetChan_vtbl *)&CNetChan::`vftable';
  CNetChan::Shutdown(this, a2: (int)this, pReason: "NetChannel removed.");
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::~CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>(this: &this->m_SplitPlayers);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_NetMessages);
  if ( this->m_StreamData.m_nGrowSize >= 0 )
  {
    if ( this->m_StreamData.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StreamData.m_pMemory);
      this->m_StreamData.m_pMemory = nullptr;
    }
    this->m_StreamData.m_nAllocationCount = 0;
  }
  m_ReceiveList = this->m_ReceiveList;
  for ( i = 1; i >= 0; --i )
  {
    m_ReceiveList = (CNetChan::dataFragments_s *)((char *)m_ReceiveList - 20);
    *(_DWORD *)&m_ReceiveList->filename[8] = 0;
    if ( *(int *)&m_ReceiveList->filename[4] >= 0 )
    {
      if ( m_ReceiveList->file != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ReceiveList->file);
        m_ReceiveList->file = nullptr;
      }
      *(_DWORD *)m_ReceiveList->filename = 0;
    }
    file = m_ReceiveList->file;
    *(_DWORD *)&m_ReceiveList->filename[12] = m_ReceiveList->file;
    if ( *(int *)&m_ReceiveList->filename[4] >= 0 )
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
// Address: 0x101AEE20
// Name: public: virtual void CNetChan::AttachSplitPlayer(int,class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::AttachSplitPlayer(CNetChan *this, int nSplitPlayerSlot, INetChannel *pChannel)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  CNetChan::SplitPlayer_t search; // [esp+4h] [ebp-8h] BYREF

  search.m_nSlot = nSplitPlayerSlot;
  p_m_SplitPlayers = &this->m_SplitPlayers;
  search.m_pChannel = pChannel;
  if ( CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         &search) == 0xFFFF )
    CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Insert(
      this: p_m_SplitPlayers,
      insert: &search);
}

//------------------------------------------------------------------------------
// Address: 0x101AEE60
// Name: public: virtual void CNetChan::DetachSplitPlayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DetachSplitPlayer(CNetChan *this, int nSplitPlayerSlot)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  int v5; // eax
  CNetChan::SplitPlayer_t search; // [esp+8h] [ebp-8h] BYREF

  p_m_SplitPlayers = &this->m_SplitPlayers;
  search.m_pChannel = nullptr;
  search.m_nSlot = nSplitPlayerSlot;
  v3 = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         &search);
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

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006F040
// Name: public: virtual bool CNetChan::IsPlayback(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsPlayback(CEngineClient *this)
{
  return demoplayer->IsPlayingBack(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x10090EF0
// Name: public: virtual int CNetChan::GetBufferSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetBufferSize(CCallback<CSteam3Client,GameServerChangeRequested_t,0> *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x101A6FD0
// Name: public: void CNetchanParanoidMode::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::Init(CNetchanParanoidMode *this)
{
  CNetchanParanoidMode::MessageItem_t *v2; // eax
  int v3; // edi
  int *p_m_nType; // esi
  CNetchanParanoidMode::MessageItem_t *v6; // [esp+Ch] [ebp-4h]

  this->m_bInitialized = true;
  this->m_pRawData = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17700u);
  v2 = (CNetchanParanoidMode::MessageItem_t *)MemAlloc_Alloc(nSize: 0x13800u);
  v6 = v2;
  if ( v2 != nullptr )
  {
    v3 = 255;
    p_m_nType = &v2->m_nType;
    do
    {
      *(p_m_nType - 2) = 0;
      *(p_m_nType - 1) = 0;
      *p_m_nType = 0;
      p_m_nType[1] = 0;
      p_m_nType[2] = 0;
      p_m_nType[3] = -1;
      *((_BYTE *)p_m_nType + 144) = 0;
      *((_BYTE *)p_m_nType + 176) = 0;
      _V_memset(dest: p_m_nType + 4, fill: 0, count: 128);
      p_m_nType += 78;
      --v3;
    }
    while ( v3 >= 0 );
    this->m_pPacketMessages = v6;
  }
  else
  {
    this->m_pPacketMessages = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7070
// Name: bool ShouldChecksumPackets(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __cdecl ShouldChecksumPackets()
{
  return NET_IsMultiplayer();
}

//------------------------------------------------------------------------------
// Address: 0x101A7080
// Name: IsSafeFileToDownload
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsSafeFileToDownload@<al>(const char *pFilename@<eax>)
{
  const char *v2; // eax
  const char *v3; // esi
  bool result; // al

  result = false;
  if ( _V_strstr(s1: pFilename, search: ":") == nullptr && _V_strstr(s1: pFilename, search: "..") == nullptr )
  {
    v2 = _V_strrchr(s: pFilename, c: 46);
    v3 = v2;
    if ( v2 != nullptr
      && (_V_stricmp(s1: v2, s2: ".layout") == 0
       || _V_strlen(str: v3) == 4
       && _V_stricmp(s1: v3, s2: ".cfg") != 0
       && _V_stricmp(s1: v3, s2: ".lst") != 0
       && _V_stricmp(s1: v3, s2: ".exe") != 0
       && _V_stricmp(s1: v3, s2: ".vbs") != 0
       && _V_stricmp(s1: v3, s2: ".com") != 0
       && _V_stricmp(s1: v3, s2: ".bat") != 0
       && _V_stricmp(s1: v3, s2: ".dll") != 0
       && _V_stricmp(s1: v3, s2: ".ini") != 0
       && _V_stricmp(s1: v3, s2: ".log") != 0) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A71A0
// Name: public: virtual bool CNetChan::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsLoopback(CNetChan *this)
{
  return netadr_s::IsLoopback(this: &this->remote_address);
}

//------------------------------------------------------------------------------
// Address: 0x101A71B0
// Name: public: virtual bool CNetChan::IsNull(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsNull(CNetChan *this)
{
  return CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x101A71D0
// Name: private: void CNetChan::UncompressFragments(struct CNetChan::dataFragments_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UncompressFragments(CNetChan *this, CNetChan::dataFragments_s *data)
{
  CNetChan::dataFragments_s *v2; // esi
  char *v3; // edi
  char *buffer; // eax
  CNetChan::dataFragments_s *v5; // eax
  unsigned int bytes; // [esp-Ch] [ebp-10h]

  v2 = data;
  if ( data->isCompressed )
  {
    v3 = (char *)MemAlloc_Alloc(nSize: 4 * ((data->nUncompressedSize + 3) >> 2));
    buffer = v2->buffer;
    bytes = v2->bytes;
    data = (CNetChan::dataFragments_s *)v2->nUncompressedSize;
    NET_BufferToBufferDecompress(dest: v3, destLen: (unsigned int *)&data, source: buffer, sourceLen: bytes);
    free(pMem: v2->buffer);
    v5 = data;
    v2->buffer = v3;
    v2->bytes = (unsigned int)v5;
    v2->isCompressed = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7250
// Name: public: virtual void CNetChan::RequestFile_OLD(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RequestFile_OLD(CNetChan *this, const char *filename, const char *transferID)
{
  _Error(a1: "Called RequestFile_OLD");
}

//------------------------------------------------------------------------------
// Address: 0x101A7260
// Name: public: virtual void CNetChan::ResetStreaming(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ResetStreaming(CNetChan *this)
{
  this->m_SteamType = 0;
  this->m_StreamLength = 0;
  this->m_StreamReceived = 0;
  this->m_StreamSeqNr = 0;
  this->m_SteamFile[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A7290
// Name: public: virtual void CNetChan::SetChallengeNr(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetChallengeNr(CNetChan *this, unsigned int chnr)
{
  this->m_ChallengeNr = chnr;
}

//------------------------------------------------------------------------------
// Address: 0x101A72A0
// Name: public: virtual unsigned int CNetChan::GetChallengeNr(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::GetChallengeNr(CNetChan *this)
{
  return this->m_ChallengeNr;
}

//------------------------------------------------------------------------------
// Address: 0x101A72B0
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
// Address: 0x101A72D0
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
// Address: 0x101A72F0
// Name: public: virtual void CNetChan::SetDemoRecorder(class IDemoRecorder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDemoRecorder(CNetChan *this, IDemoRecorder *recorder)
{
  this->m_DemoRecorder = recorder;
}

//------------------------------------------------------------------------------
// Address: 0x101A7300
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
// Address: 0x101A7360
// Name: public: virtual void CNetChan::SetFileTransmissionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetFileTransmissionMode(CNetChan *this, bool bBackgroundMode)
{
  this->m_bFileBackgroundTranmission = bBackgroundMode;
}

//------------------------------------------------------------------------------
// Address: 0x101A7370
// Name: public: virtual void CNetChan::SetCompressionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetCompressionMode(CNetChan *this, bool bUseCompression)
{
  this->m_bUseCompression = bUseCompression;
}

//------------------------------------------------------------------------------
// Address: 0x101A73A0
// Name: public: virtual int CNetChan::GetDropNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDropNumber(CNetChan *this)
{
  return this->m_PacketDrop;
}

//------------------------------------------------------------------------------
// Address: 0x101A73B0
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
  int v7; // edx
  CNetChan::netflow_t *v9; // ecx
  int currentindex; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  long double v14; // st7
  BOOL v15; // eax
  int v16; // ecx
  bool v17; // zf
  float *v18; // ecx
  long double v19; // st7
  CNetChan::netflow_t *pflow; // [esp+10h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v7 = seqnr;
  v9 = &this->m_DataFlow[flow];
  currentindex = v9->currentindex;
  v11 = 0;
  v12 = 0;
  pflow = v9;
  if ( seqnr > currentindex )
  {
    v13 = currentindex + 1;
    i = v13;
    if ( v13 <= seqnr )
    {
      v21 = seqnr - v13;
      while ( 1 )
      {
        v14 = net_time;
        v11 = (int)&v9->frame_headers[v13 & 0x7F];
        v12 = (int)&v9->frames[v13 & 0x7F];
        *(_BYTE *)(v11 + 10) = 0;
        *(float *)v11 = v14;
        *(_DWORD *)(v11 + 4) = 0;
        *(_DWORD *)(v11 + 12) = -1082130432;
        *(float *)(v12 + 4) = this->GetAvgLatency(this, a2: 0);
        *(_WORD *)(v11 + 8) = 0;
        *(_DWORD *)v12 = 0;
        *(_DWORD *)(v12 + 8) = 0;
        _V_memset(dest: (void *)(v12 + 12), fill: 0, count: 30);
        if ( v21 < nDropped + nChoked )
        {
          if ( v21 >= nChoked )
            *(_DWORD *)v12 = 1;
          else
            *(_WORD *)(v11 + 8) = 1;
        }
        ++i;
        --v21;
        if ( i > seqnr )
          break;
        v9 = pflow;
        LOBYTE(v13) = i;
      }
    }
    *(_DWORD *)v12 = nDropped;
    *(_WORD *)(v11 + 8) = nChoked;
    *(_DWORD *)(v11 + 4) = nSize;
    *(_BYTE *)(v11 + 10) = 1;
    *(float *)(v12 + 4) = this->GetAvgLatency(this, a2: 0);
    v9 = pflow;
    v7 = seqnr;
    *(float *)(v12 + 8) = this->m_flInterpolationAmount;
  }
  ++v9->totalpackets;
  v9->currentindex = v7;
  v9->currentframe = (CNetChan::netframe_s *)v12;
  v15 = flow == 0;
  if ( acknr > this->m_DataFlow[v15].currentindex - 128 )
  {
    v16 = v15 * 7724 + 16 * (acknr & 0x7F);
    v17 = !*(&this->m_DataFlow[0].frame_headers[0].valid + v16);
    v18 = (float *)((char *)&this->m_DataFlow[0].frame_headers[0].time + v16);
    if ( !v17 && v18[3] == -1.0 )
    {
      v19 = net_time - *v18;
      v18[3] = v19;
      if ( v19 < 0.0 )
        v18[3] = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7550
// Name: private: void CNetChan::FlowUpdate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::FlowUpdate(CNetChan *this, int flow, int addbytes)
{
  CNetChan::netflow_t *v3; // edi
  float v4; // xmm2_4
  int v5; // ecx
  int v6; // edx
  float v7; // xmm4_4
  int v8; // esi
  float v9; // xmm0_4
  float *p_choked; // eax
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // eax
  float v21; // xmm0_4
  float avglatency; // xmm1_4
  float v23; // xmm4_4
  int i; // [esp+4h] [ebp-4h]
  int totalinvalid; // [esp+10h] [ebp+8h]
  int totallatencycount; // [esp+14h] [ebp+Ch]

  v3 = &this->m_DataFlow[flow];
  v3->totalbytes += addbytes;
  if ( v3->nextcompute <= net_time )
  {
    v4 = 3.4028235e38;
    v5 = 0;
    v3->nextcompute = net_time + 0.25;
    v6 = 0;
    totalinvalid = 0;
    v7 = 0.0;
    totallatencycount = 0;
    v8 = 0;
    v9 = 0.0;
    p_choked = (float *)&v3->frame_headers[0].choked;
    for ( i = 32; i != 0; --i )
    {
      if ( *((_BYTE *)p_choked + 2) != 0 )
      {
        v11 = *(p_choked - 2);
        if ( v4 > v11 )
          v4 = *(p_choked - 2);
        if ( v11 > v9 )
          v9 = *(p_choked - 2);
        v5 += *((_DWORD *)p_choked - 1);
        v12 = p_choked[1];
        ++v6;
        v8 += *(__int16 *)p_choked;
        if ( v12 > -1.0 )
        {
          ++totallatencycount;
          v7 = v12 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 18) != 0 )
      {
        v13 = p_choked[2];
        if ( v4 > v13 )
          v4 = p_choked[2];
        if ( v13 > v9 )
          v9 = p_choked[2];
        v5 += *((_DWORD *)p_choked + 3);
        v14 = p_choked[5];
        ++v6;
        v8 += *((__int16 *)p_choked + 8);
        if ( v14 > -1.0 )
        {
          ++totallatencycount;
          v7 = v14 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 34) != 0 )
      {
        v15 = p_choked[6];
        if ( v4 > v15 )
          v4 = p_choked[6];
        if ( v15 > v9 )
          v9 = p_choked[6];
        v5 += *((_DWORD *)p_choked + 7);
        v16 = p_choked[9];
        ++v6;
        v8 += *((__int16 *)p_choked + 16);
        if ( v16 > -1.0 )
        {
          ++totallatencycount;
          v7 = v16 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      if ( *((_BYTE *)p_choked + 50) != 0 )
      {
        v17 = p_choked[10];
        if ( v4 > v17 )
          v4 = p_choked[10];
        if ( v17 > v9 )
          v9 = p_choked[10];
        v5 += *((_DWORD *)p_choked + 11);
        v18 = p_choked[13];
        ++v6;
        v8 += *((__int16 *)p_choked + 24);
        if ( v18 > -1.0 )
        {
          ++totallatencycount;
          v7 = v18 + v7;
        }
      }
      else
      {
        ++totalinvalid;
      }
      p_choked += 16;
    }
    v19 = v9 - v4;
    if ( v19 > 0.0 )
    {
      v3->avgbytespersec = (float)((float)((float)v5 * (float)(1.0 / v19)) * 0.25) + (float)(v3->avgbytespersec * 0.75);
      v3->avgpacketspersec = (float)((float)((float)v6 * (float)(1.0 / v19)) * 0.25)
                           + (float)(v3->avgpacketspersec * 0.75);
    }
    v20 = totalinvalid + v6;
    if ( totalinvalid + v6 > 0 )
    {
      v21 = (float)((float)((float)(totalinvalid - v8) / (float)v20) * 0.25) + (float)(v3->avgloss * 0.75);
      v3->avgloss = v21;
      if ( v21 < 0.0 )
        v3->avgloss = 0.0;
      v3->avgchoke = (float)((float)((float)v8 / (float)v20) * 0.25) + (float)(v3->avgchoke * 0.75);
    }
    if ( totallatencycount > 0 )
    {
      avglatency = v3->avglatency;
      v23 = v7 / (float)totallatencycount;
      v3->latency = v23;
      v3->avglatency = (float)(avglatency * 0.75) + (float)(v23 * 0.25);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7800
// Name: unsigned short BufferToShortChecksum(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl BufferToShortChecksum(const void *pvData, unsigned int nLength)
{
  unsigned int pulCRC; // [esp+0h] [ebp-4h] BYREF

  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: pvData, nBuffer: nLength);
  CRC32_Final(&pulCRC);
  return pulCRC ^ HIWORD(pulCRC);
}

//------------------------------------------------------------------------------
// Address: 0x101A7840
// Name: public: virtual bool CNetChan::SetActiveChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SetActiveChannel(CNetChan *this, INetChannel *pNewChannel)
{
  this->m_pActiveChannel = pNewChannel;
  return pNewChannel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A79A0
// Name: private: bool CNetChan::SendReliableViaStream(struct CNetChan::dataFragments_s __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendReliableViaStream(CNetChan *this, CNetChan::dataFragments_s *data)
{
  int numFragments; // edx
  const char *v4; // eax
  unsigned int bytes; // [esp-8h] [ebp-48h]
  int m_nOutSequenceNr; // [esp-4h] [ebp-44h]
  char headerBuf[32]; // [esp+8h] [ebp-38h] BYREF
  bf_write header; // [esp+28h] [ebp-18h] BYREF

  bf_write::bf_write(this: &header, pDebugName: "outDataHeader", pData: headerBuf, nBytes: 32, nBits: -1);
  numFragments = data->numFragments;
  data->transferID = this->m_nOutSequenceNr;
  data->pendingFragments = numFragments;
  bf_write::WriteByte(this: &header, val: 2u);
  bf_write::WriteWord(this: &header, val: data->bytes);
  bf_write::WriteLong(this: &header, val: data->transferID);
  if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nOutSequenceNr = this->m_nOutSequenceNr;
    bytes = data->bytes;
    v4 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP -> %s: sz=%i seq=%i\n", v4, bytes, m_nOutSequenceNr);
  }
  NET_SendStream(
    nSock: this->m_StreamSocket,
    buf: (const char *)header.m_pData,
    len: (header.m_iCurBit + 7) >> 3,
    flags: 0);
  return NET_SendStream(nSock: this->m_StreamSocket, buf: data->buffer, len: data->bytes, flags: 0) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B10
// Name: public: virtual int CNetChan::GetDataRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetDataRate(CNetChan *this)
{
  return this->m_Rate;
}

//------------------------------------------------------------------------------
// Address: 0x101A7B20
// Name: public: virtual float CNetChan::GetTimeConnected(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeConnected(CNetChan *this)
{
  long double v1; // st7

  v1 = net_time - this->connect_time;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7BD0
// Name: public: virtual bool CNetChan::IsTimingOut(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsTimingOut(CNetChan *this)
{
  return this->m_Timeout != -1.0 && net_time > this->last_received + 4.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C10
// Name: public: virtual float CNetChan::GetTimeoutSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeoutSeconds(CNetChan *this)
{
  return this->m_Timeout;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C20
// Name: public: virtual float CNetChan::GetTimeSinceLastReceived(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetTimeSinceLastReceived(CNetChan *this)
{
  long double v1; // st7

  v1 = net_time - this->last_received;
  if ( v1 <= 0.0 )
    return 0.0;
  return (float)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C60
// Name: public: virtual bool CNetChan::IsOverflowed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsOverflowed(CNetChan *this)
{
  return this->m_StreamReliable.m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101A7C70
// Name: public: virtual void CNetChan::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Reset(CNetChan *this)
{
  bf_write::Reset(this: &this->m_StreamUnreliable);
  bf_write::Reset(this: &this->m_StreamReliable);
  this->m_fClearTime = 0.0;
  this->m_nChokedPackets = 0;
  this->m_nSplitPacketSequence = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A7CA0
// Name: public: virtual int CNetChan::GetSocket(void)const
// Source: json
//------------------------------------------------------------------------------
DEMOACTIONTIMINGTYPE __thiscall CNetChan::GetSocket(CBaseDemoAction *this)
{
  return this->m_Timing;
}

//------------------------------------------------------------------------------
// Address: 0x101A7CB0
// Name: public: virtual float CNetChan::GetAvgData(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgbytespersec;
}

//------------------------------------------------------------------------------
// Address: 0x101A7CD0
// Name: public: virtual float CNetChan::GetAvgPackets(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgpacketspersec;
}

//------------------------------------------------------------------------------
// Address: 0x101A7CF0
// Name: public: virtual int CNetChan::GetTotalData(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalData(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalbytes;
}

//------------------------------------------------------------------------------
// Address: 0x101A7D10
// Name: public: virtual int CNetChan::GetTotalPackets(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetTotalPackets(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].totalpackets;
}

//------------------------------------------------------------------------------
// Address: 0x101A7D30
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
// Address: 0x101A7D60
// Name: public: virtual bool CNetChan::IsValidPacket(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsValidPacket(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].valid;
}

//------------------------------------------------------------------------------
// Address: 0x101A7D90
// Name: public: virtual float CNetChan::GetPacketTime(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetPacketTime(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].time;
}

//------------------------------------------------------------------------------
// Address: 0x101A7DC0
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
  int v5; // esi
  int v6; // eax
  CNetChan::netframe_header_s *v7; // esi
  CNetChan::netframe_s *v8; // eax

  v5 = frame_number & 0x7F;
  v6 = v5;
  v7 = &this->m_DataFlow[flow].frame_headers[v5];
  v8 = &this->m_DataFlow[flow].frames[v6];
  if ( pnLatencyMsecs != nullptr )
  {
    if ( v8->dropped != 0 )
      *pnLatencyMsecs = 9999;
    else
      *pnLatencyMsecs = (int)(float)(v8->avg_latency * 1000.0);
  }
  if ( pnChoke != nullptr )
    *pnChoke = v7->choked;
}

//------------------------------------------------------------------------------
// Address: 0x101A7E30
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
// Address: 0x101A7E60
// Name: public: virtual float CNetChan::GetLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].latency;
}

//------------------------------------------------------------------------------
// Address: 0x101A7E80
// Name: public: virtual float CNetChan::GetAvgChoke(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgChoke(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgchoke;
}

//------------------------------------------------------------------------------
// Address: 0x101A7EA0
// Name: public: virtual float CNetChan::GetAvgLatency(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLatency(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avglatency;
}

//------------------------------------------------------------------------------
// Address: 0x101A7EC0
// Name: public: virtual float CNetChan::GetAvgLoss(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetAvgLoss(CNetChan *this, int flow)
{
  return this->m_DataFlow[flow].avgloss;
}

//------------------------------------------------------------------------------
// Address: 0x101A7EF0
// Name: public: virtual float CNetChan::GetCommandInterpolationAmount(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetChan::GetCommandInterpolationAmount(CNetChan *this, int flow, char frame_number)
{
  return this->m_DataFlow[flow].frames[frame_number & 0x7F].m_flInterpolationAmount;
}

//------------------------------------------------------------------------------
// Address: 0x101A7F20
// Name: public: virtual int CNetChan::GetPacketBytes(int,int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetPacketBytes(CNetChan *this, int flow, char frame_number, int group)
{
  if ( group < 15 )
    return (this->m_DataFlow[flow].frames[frame_number & 0x7F].msggroups[group] + 7) >> 3;
  else
    return this->m_DataFlow[flow].frame_headers[frame_number & 0x7F].size;
}

//------------------------------------------------------------------------------
// Address: 0x101A7F80
// Name: public: virtual void CNetChan::UpdateMessageStats(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateMessageStats(CNetChan *this, int msggroup, int bits)
{
  CNetChan::netframe_s *currentframe; // eax

  currentframe = this->m_DataFlow[1].currentframe;
  this->m_MsgStats[msggroup] += bits;
  if ( currentframe != nullptr )
    currentframe->msggroups[msggroup] += bits;
}

//------------------------------------------------------------------------------
// Address: 0x101A7FB0
// Name: public: void CNetChan::IncrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::IncrementQueuedPackets(CNetChan *this)
{
  ++this->m_nQueuedPackets;
}

//------------------------------------------------------------------------------
// Address: 0x101A7FC0
// Name: public: void CNetChan::DecrementQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DecrementQueuedPackets(CNetChan *this)
{
  if ( --this->m_nQueuedPackets < 0 )
    this->m_nQueuedPackets = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A8000
// Name: public: virtual void CNetChan::SetRemoteFramerate(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetRemoteFramerate(CNetChan *this, float flFrameTime, float flFrameTimeStdDeviation)
{
  this->m_flRemoteFrameTime = flFrameTime;
  this->m_flRemoteFrameTimeStdDeviation = flFrameTimeStdDeviation;
}

//------------------------------------------------------------------------------
// Address: 0x101A8030
// Name: public: virtual void CNetChan::SetMaxRoutablePayloadSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxRoutablePayloadSize(CNetChan *this, int nSplitSize)
{
  const char *v3; // eax

  if ( this->m_nMaxRoutablePayloadSize != nSplitSize )
  {
    v3 = (const char *)this->GetName(this);
    DevMsg(
      a1: "Setting max routable payload size from %d to %d for %s\n",
      this->m_nMaxRoutablePayloadSize,
      nSplitSize,
      v3);
  }
  this->m_nMaxRoutablePayloadSize = nSplitSize;
}

//------------------------------------------------------------------------------
// Address: 0x101A8070
// Name: public: virtual int CNetChan::GetMaxRoutablePayloadSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::GetMaxRoutablePayloadSize(CNetChan *this)
{
  return this->m_nMaxRoutablePayloadSize;
}

//------------------------------------------------------------------------------
// Address: 0x101A8080
// Name: public: int CNetChan::IncrementSplitPacketSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::IncrementSplitPacketSequence(CNetChan *this)
{
  int result; // eax

  result = this->m_nSplitPacketSequence + 1;
  this->m_nSplitPacketSequence = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8090
// Name: public: static bool CNetChan::IsValidFileTransferExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CNetChan::IsValidFileTransferExtension(char *pFilename)
{
  const char *v1; // eax
  const char *v2; // esi

  strrchr(string: (unsigned __int8 *)pFilename, chr: 0x2Eu);
  v2 = v1;
  if ( v1 == nullptr )
    return false;
  if ( V_strcasecmp(s1: v1, s2: ".layout") == 0 )
    return true;
  return strlen(v2) - 3 <= 1
      && V_strcasecmp(s1: v2, s2: ".cfg") != 0
      && V_strcasecmp(s1: v2, s2: ".lst") != 0
      && V_strcasecmp(s1: v2, s2: ".exe") != 0
      && V_strcasecmp(s1: v2, s2: ".vbs") != 0
      && V_strcasecmp(s1: v2, s2: ".com") != 0
      && V_strcasecmp(s1: v2, s2: ".bat") != 0
      && V_strcasecmp(s1: v2, s2: ".dll") != 0
      && V_strcasecmp(s1: v2, s2: ".ini") != 0
      && V_strcasecmp(s1: v2, s2: ".log") != 0
      && V_strcasecmp(s1: v2, s2: ".lua") != 0
      && V_strcasecmp(s1: v2, s2: ".vdf") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A81C0
// Name: public: class bf_write __near & CNetChan::GetBuffer(enum CNetChan::EBufType)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CNetChan::GetBuffer(CNetChan *this, CNetChan::EBufType eBufType)
{
  if ( eBufType != BUF_RELIABLE )
  {
    if ( eBufType == BUF_UNRELIABLE )
      return &this->m_StreamUnreliable;
    if ( eBufType == BUF_VOICE )
      return &this->m_StreamVoice;
  }
  return &this->m_StreamReliable;
}

//------------------------------------------------------------------------------
// Address: 0x101A81F0
// Name: public: virtual bool CNetChan::IsRemoteDisconnected(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::IsRemoteDisconnected(CNetChan *this)
{
  netadr_s *p_remote_address; // esi

  p_remote_address = &this->remote_address;
  return netadr_s::IsValid(this: &this->remote_address)
      && netadr_s::GetPort(this: p_remote_address) == 1
      && (__int64)g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: p_remote_address) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A8230
// Name: void NET_InitParanoidMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_InitParanoidMode()
{
  CNetchanParanoidMode::Init(this: &g_NetParanoid);
}

//------------------------------------------------------------------------------
// Address: 0x101A8240
// Name: public: void CNetchanParanoidMode::StartPacket(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::StartPacket(CNetchanParanoidMode *this, bf_read *fullbuf)
{
  int v3; // eax
  unsigned int m_nDataBytes; // eax

  if ( this->m_bInitialized )
  {
    v3 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != 0 )
    {
      m_nDataBytes = fullbuf->m_nDataBytes;
      if ( m_nDataBytes >= 0x17700 )
        m_nDataBytes = 96000;
      this->m_nRawDataSize = m_nDataBytes;
      _V_memcpy(dest: this->m_pRawData, src: fullbuf->m_pData, count: m_nDataBytes);
      this->m_nPacketMessageCount = 0;
      this->m_nHeaderBits = 0;
      this->m_nFlags = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A82B0
// Name: public: void CNetchanParanoidMode::NoteHeaderSize(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::NoteHeaderSize(CNetchanParanoidMode *this, bf_read *msg, int flags)
{
  int v3; // eax
  const unsigned int *m_pData; // eax
  signed int m_nDataBits; // eax

  if ( this->m_bInitialized )
  {
    v3 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != 0 )
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
}

//------------------------------------------------------------------------------
// Address: 0x101A8320
// Name: public: void CNetchanParanoidMode::Dump(class CNetChan __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetchanParanoidMode::Dump(CNetchanParanoidMode *this, CNetChan *channel, const char *pchReason)
{
  int v4; // eax
  void (*v5)(const char *, ...); // esi
  netadr_s *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // ebx
  CNetchanParanoidMode::MessageItem_t *v10; // esi
  const char *v11; // [esp-10h] [ebp-14h]
  const char *pchReasona; // [esp+10h] [ebp+Ch]

  if ( this->m_bInitialized )
  {
    v4 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v4 != 0 )
    {
      v5 = (void (*)(const char *, ...))_Msg;
      _Msg(a1: "%s\n ", pchReason);
      v6 = (netadr_s *)channel->GetRemoteAddress(this: channel);
      v7 = netadr_s::ToString(this: v6, baseOnly: false);
      v8 = (const char *)((int (__thiscall *)(CNetChan *, const char *))channel->GetName)(a1: channel, a2: v7);
      _Msg(a1: "Dumping messages for channel %s(%s) 0x%p\n", v8, v11, channel);
      _Msg(a1: "Header bits %d, flags == %d\n", this->m_nHeaderBits, this->m_nFlags);
      _Msg(a1: "%d messages\n", this->m_nPacketMessageCount);
      v9 = 0;
      if ( this->m_nPacketMessageCount > 0 )
      {
        pchReasona = nullptr;
        do
        {
          v10 = (CNetchanParanoidMode::MessageItem_t *)&pchReasona[(unsigned int)this->m_pPacketMessages];
          _Msg(a1: "%d -----------------------\n", v9);
          CNetchanParanoidMode::MessageItem_t::Dump(this: v10);
          pchReasona += 312;
          ++v9;
        }
        while ( v9 < this->m_nPacketMessageCount );
        v5 = (void (*)(const char *, ...))_Msg;
      }
      v5(a1: "Raw\n");
      LogMultiline(input: false, label: "PKT", data: (const char *)this->m_pRawData, len: this->m_nRawDataSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8410
// Name: public: virtual unsigned int CNetChan::RequestFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetChan::RequestFile(CNetChan *this, const char *filename, bool bIsReplayDemoFile)
{
  unsigned int v4; // ecx
  int m_iCurBit; // ecx
  unsigned __int8 *v6; // eax
  char v7; // dl
  int v8; // ecx

  v4 = ++this->m_FileRequestCounter;
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "RequestFile: %s (ID %i)\n", filename, v4);
  bf_write::WriteUBitLong(this: &this->m_StreamReliable, curData: 2u, numbits: 6, bCheckRange: true);
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
    v6 = &this->m_StreamReliable.m_pData[m_iCurBit >> 3];
    v7 = 1 << (m_iCurBit & 7);
    if ( bIsReplayDemoFile )
      *v6 |= v7;
    else
      *v6 &= ~v7;
    ++this->m_StreamReliable.m_iCurBit;
  }
  v8 = this->m_StreamReliable.m_iCurBit;
  if ( v8 + 1 > this->m_StreamReliable.m_nDataBits )
    this->m_StreamReliable.m_bOverflow = true;
  if ( !this->m_StreamReliable.m_bOverflow )
  {
    this->m_StreamReliable.m_pData[v8 >> 3] |= 1 << (v8 & 7);
    ++this->m_StreamReliable.m_iCurBit;
  }
  return this->m_FileRequestCounter;
}

//------------------------------------------------------------------------------
// Address: 0x101A84E0
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
  int m_iCurBit; // ecx
  int v7; // ecx

  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
    DevMsg(a1: "DenyFile: %s (ID %i)\n", filename, transferID);
  p_m_StreamReliable = &this->m_StreamReliable;
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: 2u, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: p_m_StreamReliable, curData: transferID, numbits: 32, bCheckRange: true);
  bf_write::WriteString(this: p_m_StreamReliable, pStr: filename);
  m_iCurBit = p_m_StreamReliable->m_iCurBit;
  if ( m_iCurBit + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    if ( bIsReplayDemoFile )
      p_m_StreamReliable->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      p_m_StreamReliable->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++p_m_StreamReliable->m_iCurBit;
  }
  v7 = p_m_StreamReliable->m_iCurBit;
  if ( v7 + 1 > p_m_StreamReliable->m_nDataBits )
    p_m_StreamReliable->m_bOverflow = true;
  if ( !p_m_StreamReliable->m_bOverflow )
  {
    p_m_StreamReliable->m_pData[v7 >> 3] &= ~(1 << (v7 & 7));
    ++p_m_StreamReliable->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A85B0
// Name: public: void CNetChan::Setup(int,struct netadr_s __near *,char const __near *,class INetChannelHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::Setup(CNetChan *this, int sock, netadr_s *adr, const char *name, INetChannelHandler *handler)
{
  SOCKET m_StreamSocket; // eax
  CNetChan_vtbl *v7; // edx
  void (__thiscall *SetMaxBufferSize)(struct CNetChan *, bool, int, bool); // eax
  int v9; // edx
  int *p_sendSeqNr; // eax
  int i; // ecx

  this->m_Socket = sock;
  m_StreamSocket = this->m_StreamSocket;
  if ( m_StreamSocket != 0 )
  {
    NET_CloseSocket(hSocket: m_StreamSocket, sock: -1);
    this->m_StreamSocket = 0;
  }
  if ( adr != nullptr )
  {
    this->remote_address = *adr;
  }
  else
  {
    netadr_s::Clear(this: &this->remote_address);
    netadr_s::SetType(this: &this->remote_address, newtype: NA_NULL);
  }
  this->last_received = net_time;
  this->connect_time = net_time;
  V_strncpy(pDest: this->m_Name, pSrc: name, maxLen: 32);
  v7 = this->__vftable;
  this->m_MessageHandler = handler;
  SetMaxBufferSize = v7->SetMaxBufferSize;
  this->m_DemoRecorder = nullptr;
  SetMaxBufferSize(this, a2: false, a3: 4000, a4: false);
  this->SetMaxBufferSize(this, a2: false, a3: 4000, a4: true);
  this->SetMaxBufferSize(this, a2: true, a3: 96000, a4: false);
  this->m_fClearTime = 0.0;
  this->m_Rate = 10000;
  this->m_Timeout = 300.0;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_nChokedPackets = 0;
  this->m_ChallengeNr = 0;
  this->m_StreamSocket = 0;
  this->m_StreamActive = false;
  this->m_ReceiveList[0].buffer = nullptr;
  this->m_ReceiveList[1].buffer = nullptr;
  v9 = 0;
  p_sendSeqNr = &this->m_SubChannels[0].sendSeqNr;
  do
  {
    p_sendSeqNr[2] = v9;
    p_sendSeqNr[1] = 0;
    *p_sendSeqNr = -1;
    for ( i = 0; i < 2; ++i )
    {
      p_sendSeqNr[i - 2] = 0;
      p_sendSeqNr[i - 4] = -1;
    }
    ++v9;
    p_sendSeqNr += 7;
  }
  while ( v9 < 8 );
  this->ResetStreaming(this);
  if ( NET_IsMultiplayer() )
  {
    if ( net_blocksize.m_pParent != nullptr )
      this->m_MaxReliablePayloadSize = net_blocksize.m_pParent->m_Value.m_nValue;
    else
      this->m_MaxReliablePayloadSize = 0;
  }
  else
  {
    this->m_MaxReliablePayloadSize = 96000;
  }
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 60);
  this->m_MessageHandler->ConnectionStart(this: this->m_MessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101A8790
// Name: public: virtual void CNetChan::SetDataRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetDataRate(CNetChan *this, float rate)
{
  float v2; // xmm0_4

  v2 = rate;
  if ( rate < 1000.0 )
  {
    v2 = 1000.0;
LABEL_3:
    this->m_Rate = (int)v2;
    return;
  }
  if ( rate <= 30000.0 )
    goto LABEL_3;
  this->m_Rate = (int)30000.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A87E0
// Name: public: virtual bool CNetChan::CanPacket(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::CanPacket(CNetChan *this)
{
  if ( (net_chokeloopback.m_pParent == nullptr || net_chokeloopback.m_pParent->m_Value.m_nValue == 0)
    && netadr_s::IsLoopback(this: &this->remote_address) )
  {
    return true;
  }
  if ( g_pQueuedPackedSender->HasQueuedPackets(this: g_pQueuedPackedSender, a2: this) || this->m_nQueuedPackets > 0 )
    return false;
  return net_time > this->m_fClearTime;
}

//------------------------------------------------------------------------------
// Address: 0x101A8850
// Name: private: bool CNetChan::ReadSubChannelData(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ReadSubChannelData(CNetChan *this, bf_read *buf, int stream)
{
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
  int v14; // ebx
  const unsigned int *v15; // eax
  const unsigned int *v16; // ecx
  const unsigned int *v17; // edx
  unsigned int v18; // edi
  int v19; // eax
  const unsigned int *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ebx
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
  unsigned int v36; // eax
  int v37; // edx
  const unsigned int *v38; // eax
  const unsigned int *v39; // ecx
  int m_nBitsAvail; // ecx
  unsigned int v41; // eax
  int v42; // edi
  int v43; // ecx
  CNetChan::dataFragments_s *v44; // ebx
  const unsigned int *v45; // eax
  const unsigned int *v46; // ecx
  const unsigned int *v47; // edx
  unsigned int v48; // edi
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // ebx
  int v53; // edi
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // edi
  int v57; // ecx
  const unsigned int *v58; // eax
  const unsigned int *v59; // ecx
  const unsigned int *v60; // edx
  unsigned int v61; // edi
  int v62; // eax
  const unsigned int *v63; // ecx
  unsigned int v64; // edx
  unsigned int v65; // ebx
  int v66; // edi
  int v67; // edx
  const unsigned int *v68; // eax
  const unsigned int *v69; // ecx
  int v70; // ecx
  unsigned int v71; // eax
  int v72; // ecx
  const unsigned int *v73; // ecx
  const unsigned int *v74; // edx
  const unsigned int *v75; // edx
  unsigned int v76; // edi
  int v77; // eax
  const unsigned int *v78; // ecx
  unsigned int v79; // edx
  unsigned int v80; // ebx
  unsigned int v81; // edx
  CNetChan::dataFragments_s *v82; // ebx
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
  CNetChan::dataFragments_s *v97; // edx
  const unsigned int *v98; // edx
  unsigned int v99; // edi
  int v100; // eax
  const unsigned int *v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // ebx
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
  unsigned int v115; // ebx
  unsigned int bytes; // eax
  unsigned int v117; // eax
  unsigned int offset; // [esp+Ch] [ebp-14h]
  int startFragment; // [esp+10h] [ebp-10h]
  int numFragments; // [esp+14h] [ebp-Ch]
  unsigned int length; // [esp+18h] [ebp-8h]
  CNetChan::dataFragments_s *data; // [esp+1Ch] [ebp-4h]
  bf_read *bufa; // [esp+28h] [ebp+8h]
  bool bSingleBlock_3; // [esp+2Fh] [ebp+Fh]

  data = &this->m_ReceiveList[stream];
  m_nInBufWord = buf->m_nInBufWord;
  v5 = m_nInBufWord & 1;
  v6 = buf->m_nBitsAvail-- == 1;
  startFragment = 0;
  numFragments = 0;
  offset = 0;
  length = 0;
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
  bSingleBlock_3 = v9;
  if ( v9 )
  {
LABEL_46:
    data->filename[0] = 0;
    data->isCompressed = false;
    data->isReplayDemo = false;
    data->transferID = 0;
    v6 = !v9;
    v36 = buf->m_nInBufWord;
    if ( !v6 )
    {
      v37 = v36 & 1;
      v6 = buf->m_nBitsAvail-- == 1;
      if ( v6 )
      {
        v38 = buf->m_pDataIn;
        v39 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v38 == v39 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v38 + 1;
        }
        else if ( v38 <= v39 )
        {
          buf->m_nInBufWord = *v38;
          buf->m_pDataIn = v38 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v36 >> 1;
      }
      if ( v37 == 0 )
      {
        data->isCompressed = false;
        v44 = data;
        goto LABEL_74;
      }
      data->isCompressed = true;
      m_nBitsAvail = buf->m_nBitsAvail;
      if ( m_nBitsAvail >= 26 )
      {
        v41 = buf->m_nInBufWord;
        v42 = v41 & 0x3FFFFFF;
        v43 = m_nBitsAvail - 26;
        buf->m_nBitsAvail = v43;
        if ( v43 != 0 )
        {
          v44 = data;
          buf->m_nInBufWord = v41 >> 26;
          data->nUncompressedSize = v42;
        }
        else
        {
          v45 = buf->m_pDataIn;
          v46 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v45 == v46 )
          {
            v44 = data;
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v45 + 1;
            data->nUncompressedSize = v42;
          }
          else
          {
            v44 = data;
            if ( v45 <= v46 )
            {
              buf->m_nInBufWord = *v45;
              buf->m_pDataIn = v45 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            data->nUncompressedSize = v42;
          }
        }
LABEL_74:
        v54 = buf->m_nBitsAvail;
        if ( v54 >= 17 )
        {
          v55 = buf->m_nInBufWord;
          v56 = v55 & 0x1FFFF;
          v57 = v54 - 17;
          buf->m_nBitsAvail = v57;
          if ( v57 != 0 )
          {
            buf->m_nInBufWord = v55 >> 17;
            v44->bytes = v56;
          }
          else
          {
            v58 = buf->m_pDataIn;
            v59 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v58 == v59 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v58 + 1;
              v44->bytes = v56;
            }
            else
            {
              if ( v58 <= v59 )
              {
                buf->m_nInBufWord = *v58;
                buf->m_pDataIn = v58 + 1;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
              v44->bytes = v56;
            }
          }
          goto LABEL_172;
        }
        v60 = buf->m_pBufferEnd;
        v61 = buf->m_nInBufWord;
        v62 = 17 - v54;
        v63 = buf->m_pDataIn;
        if ( v63 == v60 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        else
        {
          if ( v63 > v60 )
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            goto LABEL_89;
          }
          buf->m_nInBufWord = *v63;
        }
        buf->m_pDataIn = v63 + 1;
LABEL_89:
        if ( buf->m_bOverflow )
        {
          v44->bytes = 0;
        }
        else
        {
          v64 = buf->m_nInBufWord;
          v65 = (v64 & CBitBuffer::s_nMaskTable[v62]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v62;
          v66 = v65 | v61;
          v44 = data;
          buf->m_nInBufWord = v64 >> v62;
          data->bytes = v66;
        }
        goto LABEL_172;
      }
      v47 = buf->m_pBufferEnd;
      v48 = buf->m_nInBufWord;
      v49 = 26 - m_nBitsAvail;
      v50 = buf->m_pDataIn;
      if ( v50 == v47 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v50 > v47 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_70;
        }
        buf->m_nInBufWord = *v50;
      }
      buf->m_pDataIn = v50 + 1;
LABEL_70:
      if ( buf->m_bOverflow )
      {
        v44 = data;
        data->nUncompressedSize = 0;
      }
      else
      {
        v51 = buf->m_nInBufWord;
        v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v49;
        v53 = v52 | v48;
        v44 = data;
        buf->m_nInBufWord = v51 >> v49;
        data->nUncompressedSize = v53;
      }
      goto LABEL_74;
    }
    v67 = v36 & 1;
    v6 = buf->m_nBitsAvail-- == 1;
    if ( v6 )
    {
      v68 = buf->m_pDataIn;
      v69 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v68 == v69 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v68 + 1;
      }
      else if ( v68 <= v69 )
      {
        buf->m_nInBufWord = *v68;
        buf->m_pDataIn = v68 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v36 >> 1;
    }
    if ( v67 == 0 )
    {
      v82 = data;
      goto LABEL_127;
    }
    v70 = buf->m_nBitsAvail;
    if ( v70 >= 32 )
    {
      v71 = buf->m_nInBufWord;
      v72 = v70 - 32;
      buf->m_nBitsAvail = v72;
      if ( v72 != 0 )
      {
        buf->m_nInBufWord = 0;
      }
      else
      {
        v73 = buf->m_pDataIn;
        v74 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v73 == v74 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v73 + 1;
        }
        else if ( v73 <= v74 )
        {
          buf->m_nInBufWord = *v73;
          buf->m_pDataIn = v73 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_117:
      v82 = data;
      data->transferID = v71;
      CBitRead::ReadString(this: buf, pStr: data->filename, maxLen: 260, bLine: false, pOutNumChars: nullptr);
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
        data->isReplayDemo = true;
LABEL_127:
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
        data->isCompressed = false;
        goto LABEL_154;
      }
      v82->isCompressed = true;
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
          data->nUncompressedSize = v93;
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
            data->nUncompressedSize = v93;
          }
          else
          {
            if ( v95 <= v96 )
            {
              buf->m_nInBufWord = *v95;
              v97 = data;
              buf->m_pDataIn = v95 + 1;
            }
            else
            {
              v97 = data;
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            v97->nUncompressedSize = v93;
          }
        }
LABEL_154:
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
LABEL_171:
          data->bytes = v106;
          v44 = data;
LABEL_172:
          if ( v44->buffer != nullptr )
          {
            free(pMem: v44->buffer);
            _ConDMsg(a1: "Fragment transmission aborted at %i/%i.\n", v44->ackedFragments, v44->numFragments);
          }
          bytes = v44->bytes;
          v44->bits = 8 * bytes;
          v44->buffer = (char *)MemAlloc_Alloc(nSize: 4 * ((bytes + 3) >> 2));
          v117 = (v44->bytes + 255) >> 8;
          v44->asTCP = false;
          v44->numFragments = v117;
          v44->ackedFragments = 0;
          v44->file = nullptr;
          if ( bSingleBlock_3 )
          {
            numFragments = v117;
            length = v117 << 8;
          }
          goto LABEL_176;
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
            goto LABEL_168;
          }
          buf->m_nInBufWord = *v113;
        }
        buf->m_pDataIn = v113 + 1;
LABEL_168:
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
        goto LABEL_171;
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
          goto LABEL_150;
        }
        buf->m_nInBufWord = *v101;
      }
      buf->m_pDataIn = v101 + 1;
LABEL_150:
      if ( buf->m_bOverflow )
      {
        data->nUncompressedSize = 0;
      }
      else
      {
        v102 = buf->m_nInBufWord;
        v103 = (v102 & CBitBuffer::s_nMaskTable[v100]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v100;
        buf->m_nInBufWord = v102 >> v100;
        data->nUncompressedSize = v103 | v99;
      }
      goto LABEL_154;
    }
    v75 = buf->m_pBufferEnd;
    v76 = buf->m_nInBufWord;
    v77 = 32 - v70;
    v78 = buf->m_pDataIn;
    if ( v78 == v75 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_114;
      }
      buf->m_nInBufWord = *v78;
    }
    buf->m_pDataIn = v78 + 1;
LABEL_114:
    if ( buf->m_bOverflow )
    {
      v71 = 0;
    }
    else
    {
      v79 = buf->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v77;
      v81 = v79 >> v77;
      v71 = v80 | v76;
      buf->m_nInBufWord = v81;
    }
    goto LABEL_117;
  }
  v10 = buf->m_nBitsAvail;
  if ( v10 < 18 )
  {
    v17 = buf->m_pBufferEnd;
    v18 = buf->m_nInBufWord;
    v19 = 18 - v10;
    v20 = buf->m_pDataIn;
    if ( v20 == v17 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v20 > v17 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v20;
    }
    buf->m_pDataIn = v20 + 1;
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
      v14 = v18 | v22;
      buf->m_nInBufWord = v21 >> v19;
    }
    goto LABEL_27;
  }
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
LABEL_27:
  v23 = buf->m_nBitsAvail;
  bufa = (bf_read *)v14;
  startFragment = v14;
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
    goto LABEL_44;
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
  }
  else
  {
    if ( v33 > v30 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_41;
    }
    buf->m_nInBufWord = *v33;
  }
  buf->m_pDataIn = v33 + 1;
LABEL_41:
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
    v14 = (int)bufa;
    buf->m_nInBufWord = v34 >> v32;
  }
LABEL_44:
  numFragments = v25;
  offset = v14 << 8;
  length = v25 << 8;
  if ( v14 << 8 == 0 )
  {
    v9 = false;
    goto LABEL_46;
  }
  if ( data->buffer == nullptr )
    return 0;
LABEL_176:
  if ( numFragments + startFragment == data->numFragments && (unsigned __int8)data->bytes != 0 )
    length -= 256 - (unsigned __int8)data->bytes;
  CBitRead::ReadBytes(this: buf, pOut: &data->buffer[offset], nBytes: length);
  data->ackedFragments += numFragments;
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "Received fragments: start %i, num %i\n", startFragment, numFragments);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A92A0
// Name: private: bool CNetChan::ProcessControlMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessControlMessage(CNetChan *this, int cmd, bf_read *buf)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  const char *v7; // eax
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // ecx
  int v12; // edi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  unsigned int v21; // eax
  int v22; // ecx
  bool v23; // zf
  const unsigned int *v24; // eax
  const unsigned int *v25; // edx
  unsigned int v26; // eax
  int v27; // ecx
  const unsigned int *v28; // eax
  const unsigned int *v29; // edx
  int v30; // eax
  CNetchanParanoidMode::MessageItem_t *v31; // esi
  int v32; // eax
  CNetchanParanoidMode::MessageItem_t *v33; // esi
  int v34; // eax
  char string[1024]; // [esp+Ch] [ebp-404h] BYREF
  CNetChan *channel; // [esp+40Ch] [ebp-4h]
  int nStartBit; // [esp+41Ch] [ebp+Ch]

  m_pData = buf->m_pData;
  channel = this;
  if ( m_pData != nullptr )
  {
    m_nDataBits = buf->m_nDataBits;
    nStartBit = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( nStartBit >= m_nDataBits )
      nStartBit = m_nDataBits;
  }
  else
  {
    nStartBit = 0;
  }
  if ( cmd == 0 )
  {
    if ( !g_NetParanoid.m_bInitialized )
      return 1;
    v34 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v34 == 0 || g_NetParanoid.m_nPacketMessageCount >= 255 )
      return 1;
    v31 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
    v31->m_pMsg = nullptr;
    v31->m_nMessageSize = 0;
    v31->m_nType = 0;
    v31->m_nGroup = 0;
    V_strncpy(pDest: v31->m_szName, pSrc: "net_NOP", maxLen: 32);
    V_strncpy(pDest: v31->m_szDesc, pSrc: defaultValue, maxLen: 128);
    v31->m_nStartBit = nStartBit;
    goto LABEL_67;
  }
  if ( cmd != 1 )
  {
    if ( cmd != 2 )
    {
      v7 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
      ConMsg(a1: "CNetChan: received bad control cmd %i from %s.\n", cmd, v7);
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel, pchReason: "bad control cmd");
      return 0;
    }
    m_nBitsAvail = buf->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = buf->m_nInBufWord;
      v11 = m_nBitsAvail - 32;
      buf->m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        buf->m_nInBufWord = 0;
        v12 = m_nInBufWord;
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
          v12 = m_nInBufWord;
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
          v12 = m_nInBufWord;
        }
      }
      goto LABEL_27;
    }
    v15 = buf->m_pBufferEnd;
    v16 = buf->m_nInBufWord;
    v17 = 32 - m_nBitsAvail;
    v18 = buf->m_pDataIn;
    if ( v18 == v15 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v18;
    }
    buf->m_pDataIn = v18 + 1;
LABEL_24:
    if ( buf->m_bOverflow )
    {
      v12 = 0;
    }
    else
    {
      v19 = buf->m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v17;
      v12 = v20 | v16;
      buf->m_nInBufWord = v19 >> v17;
    }
LABEL_27:
    CBitRead::ReadString(this: buf, pStr: string, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
    v21 = buf->m_nInBufWord;
    v22 = v21 & 1;
    v23 = buf->m_nBitsAvail-- == 1;
    if ( v23 )
    {
      v24 = buf->m_pDataIn;
      v25 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v24 == v25 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v24 + 1;
      }
      else if ( v24 <= v25 )
      {
        buf->m_nInBufWord = *v24;
        buf->m_pDataIn = v24 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v21 >> 1;
    }
    LOBYTE(cmd) = v22 != 0;
    v26 = buf->m_nInBufWord;
    v27 = v26 & 1;
    v23 = buf->m_nBitsAvail-- == 1;
    if ( v23 )
    {
      v28 = buf->m_pDataIn;
      v29 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v28 == v29 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v28 + 1;
      }
      else if ( v28 <= v29 )
      {
        buf->m_nInBufWord = *v28;
        buf->m_pDataIn = v28 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v26 >> 1;
    }
    if ( v27 != 0 && IsSafeFileToDownload(pFilename: string) )
      ((void (__stdcall *)(char *, int, int))channel->m_MessageHandler->FileRequested)(a1: string, a2: v12, a3: cmd);
    else
      ((void (__stdcall *)(char *, int, int))channel->m_MessageHandler->FileDenied)(a1: string, a2: v12, a3: cmd);
    if ( !g_NetParanoid.m_bInitialized )
      return 1;
    v30 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v30 == 0 || g_NetParanoid.m_nPacketMessageCount >= 255 )
      return 1;
    v31 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
    v31->m_pMsg = nullptr;
    v31->m_nMessageSize = 0;
    v31->m_nType = 2;
    v31->m_nGroup = 0;
    V_strncpy(pDest: v31->m_szName, pSrc: "net_File", maxLen: 32);
    V_strncpy(pDest: v31->m_szDesc, pSrc: string, maxLen: 128);
    v31->m_nStartBit = nStartBit;
LABEL_67:
    v31->m_nEndBit = -1;
    return 1;
  }
  CBitRead::ReadString(this: buf, pStr: string, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  if ( g_NetParanoid.m_bInitialized )
  {
    v32 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
    if ( v32 != 0 && g_NetParanoid.m_nPacketMessageCount < 255 )
    {
      v33 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
      v33->m_pMsg = nullptr;
      v33->m_nMessageSize = 0;
      v33->m_nType = 1;
      v33->m_nGroup = 0;
      V_strncpy(pDest: v33->m_szName, pSrc: "net_Disconnect", maxLen: 32);
      V_strncpy(pDest: v33->m_szDesc, pSrc: string, maxLen: 128);
      v33->m_nStartBit = nStartBit;
      v33->m_nEndBit = -1;
    }
  }
  channel->m_MessageHandler->ConnectionClosing(this: channel->m_MessageHandler, a2: string);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A96F0
// Name: public: virtual bool CNetChan::HasPendingReliableData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetChan::HasPendingReliableData(CNetChan *this)
{
  return this->m_StreamReliable.m_iCurBit > 0 || this->m_WaitingList[0].m_Size > 0 || this->m_WaitingList[1].m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A9780
// Name: private: void CNetChan::CompressFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetChan::CompressFragments(CNetChan *this@<ecx>, void *a2@<edi>)
{
  CNetChan *v2; // ebx
  bool v3; // zf
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // eax
  CNetChan::dataFragments_s **m_pMemory; // eax
  CNetChan::dataFragments_s *v6; // esi
  char *v7; // edi
  const char *v8; // edi
  const char *v9; // eax
  char *v10; // eax
  void *v11; // edi
  int v12; // eax
  int v13; // ebx
  char *v14; // eax
  char *v15; // eax
  void *file; // edx
  unsigned int v17; // eax
  char *buffer; // [esp-14h] [ebp-13Ch]
  unsigned int bytes; // [esp-10h] [ebp-138h]
  unsigned int v20; // [esp-Ch] [ebp-134h]
  char compressedfilename[260]; // [esp+4h] [ebp-124h] BYREF
  CNetChan *v23; // [esp+108h] [ebp-20h]
  int v24; // [esp+10Ch] [ebp-1Ch]
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v25; // [esp+110h] [ebp-18h]
  int compressedFileSize; // [esp+114h] [ebp-14h]
  int compressedFileTime; // [esp+118h] [ebp-10h]
  unsigned int destLen; // [esp+11Ch] [ebp-Ch] BYREF
  char *compressed; // [esp+120h] [ebp-8h]
  char *uncompressed; // [esp+124h] [ebp-4h] BYREF

  v2 = this;
  v3 = !this->m_bUseCompression;
  v23 = this;
  if ( !v3 && net_compresspackets.m_pParent != nullptr && net_compresspackets.m_pParent->m_Value.m_nValue != 0 )
  {
    m_WaitingList = this->m_WaitingList;
    v25 = this->m_WaitingList;
    v24 = 2;
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
            uncompressed = (char *)v6->bytes;
            v7 = (char *)MemAlloc_Alloc(nSize: (unsigned int)uncompressed);
            bytes = v6->bytes;
            buffer = v6->buffer;
            compressed = v7;
            if ( NET_BufferToBufferCompress(
                   dest: v7,
                   destLen: (unsigned int *)&uncompressed,
                   source: buffer,
                   sourceLen: bytes) != 0 )
            {
              v8 = (const char *)v2->GetName(this: v2);
              v9 = v2->GetAddress(this: v2);
              DevMsg(a1: "Compressing fragments for %s(%s) (%d -> %d bytes)\n", v8, v9, v6->bytes, uncompressed);
              _V_memcpy(dest: v6->buffer, src: compressed, count: (int)uncompressed);
              v7 = compressed;
              v6->nUncompressedSize = v6->bytes;
              v10 = uncompressed;
              v6->bytes = (unsigned int)uncompressed;
              v6->numFragments = (unsigned int)(v10 + 255) >> 8;
              v6->isCompressed = true;
            }
            free(pMem: v7);
          }
          else
          {
            compressedFileSize = -1;
            v11 = nullptr;
            V_snprintf(pDest: compressedfilename, maxLen: 260, pFormat: "%s.ztmp", v6->filename);
            compressedFileTime = ((int (__thiscall *)(IBaseFileSystem *, char *, _DWORD, void *))g_pFileSystem->GetFileTime)(
                                   a1: &g_pFileSystem->IBaseFileSystem,
                                   a2: compressedfilename,
                                   a3: 0,
                                   a4: a2);
            v12 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: v6->filename, a3: nullptr);
            if ( compressedFileTime >= v12
              && (v11 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: compressedfilename,
                          a3: "rb",
                          a4: 0)) != nullptr )
            {
              a2 = v11;
              v13 = ((int (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Size_2)(a1: &g_pFileSystem->IBaseFileSystem);
            }
            else
            {
              v14 = (char *)MemAlloc_Alloc(nSize: v6->bytes);
              v20 = v6->bytes;
              uncompressed = v14;
              v15 = (char *)MemAlloc_Alloc(nSize: v20);
              file = v6->file;
              compressed = v15;
              compressedFileTime = v6->bytes;
              a2 = file;
              destLen = compressedFileTime;
              ((void (__thiscall *)(IBaseFileSystem *, char *, int))g_pFileSystem->Read)(
                a1: &g_pFileSystem->IBaseFileSystem,
                a2: uncompressed,
                a3: compressedFileTime);
              if ( NET_BufferToBufferCompress(
                     dest: compressed,
                     &destLen,
                     source: uncompressed,
                     sourceLen: compressedFileTime) != 0 )
              {
                v11 = g_pFileSystem->Open(
                        this: &g_pFileSystem->IBaseFileSystem,
                        a2: compressedfilename,
                        a3: "wb",
                        a4: 0);
                if ( v11 != nullptr )
                {
                  DevMsg(a1: "Creating compressed version of file %s (%d -> %d)\n", v6->filename, v6->bytes, destLen);
                  g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: compressed, a3: destLen, a4: v11);
                  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v11);
                  v11 = g_pFileSystem->Open(
                          this: &g_pFileSystem->IBaseFileSystem,
                          a2: compressedfilename,
                          a3: "rb",
                          a4: 0);
                  if ( v11 != nullptr )
                    compressedFileSize = destLen;
                }
              }
              free(pMem: uncompressed);
              free(pMem: compressed);
              v13 = compressedFileSize;
            }
            if ( v13 > 0 )
            {
              g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6->file);
              v17 = v6->bytes;
              v6->bytes = v13;
              v6->file = v11;
              v6->nUncompressedSize = v17;
              v6->numFragments = (unsigned int)(v13 + 255) >> 8;
              v6->isCompressed = true;
            }
            v2 = v23;
          }
        }
      }
      m_WaitingList = v25 + 1;
      v3 = v24-- == 1;
      ++v25;
    }
    while ( !v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9AD0
// Name: public: virtual bool CNetChan::StartStreaming(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::StartStreaming(CNetChan *this, unsigned int challengeNr)
{
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v5; // eax

  this->ResetStreaming(this);
  this->m_ChallengeNr = challengeNr;
  if ( NET_IsMultiplayer() )
  {
    this->m_StreamSocket = NET_ConnectSocket(sock: this->m_Socket, addr: &this->remote_address);
    if ( this->m_StreamData.m_nAllocationCount < 96000 && this->m_StreamData.m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_StreamData.m_pMemory;
      this->m_StreamData.m_nAllocationCount = 96000;
      if ( m_pMemory != nullptr )
        v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 96000);
      else
        v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
      this->m_StreamData.m_pMemory = v5;
    }
    return this->m_StreamSocket != 0;
  }
  else
  {
    this->m_StreamSocket = 0;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9B80
// Name: public: virtual void CNetChan::SetMaxBufferSize(bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::SetMaxBufferSize(CNetChan *this, bool bReliable, int nBytes, bool bVoice)
{
  bf_write *p_m_StreamReliable; // eax
  CUtlMemory<unsigned char,int> *p_m_ReliableDataBuffer; // esi
  int m_iCurBit; // ebx
  bf_write *stream; // [esp+8h] [ebp+8h]
  int nBytesa; // [esp+Ch] [ebp+Ch]
  unsigned __int8 *copybuf; // [esp+10h] [ebp+10h]

  if ( nBytes >= 4000 )
  {
    nBytesa = 96000;
    if ( nBytes <= 96000 )
      nBytesa = nBytes;
  }
  else
  {
    nBytesa = 4000;
  }
  if ( bReliable )
  {
    p_m_StreamReliable = &this->m_StreamReliable;
    p_m_ReliableDataBuffer = &this->m_ReliableDataBuffer;
  }
  else
  {
    if ( bVoice )
    {
      stream = &this->m_StreamVoice;
      p_m_ReliableDataBuffer = &this->m_VoiceDataBuffer;
      goto LABEL_11;
    }
    p_m_StreamReliable = &this->m_StreamUnreliable;
    p_m_ReliableDataBuffer = &this->m_UnreliableDataBuffer;
  }
  stream = p_m_StreamReliable;
LABEL_11:
  if ( p_m_ReliableDataBuffer->m_nAllocationCount != nBytesa )
  {
    m_iCurBit = stream->m_iCurBit;
    copybuf = nullptr;
    if ( (m_iCurBit + 7) >> 3 < nBytesa )
    {
      if ( m_iCurBit > 0 )
      {
        copybuf = (unsigned __int8 *)MemAlloc_Alloc(nSize: (m_iCurBit + 7) >> 3);
        _V_memcpy(dest: copybuf, src: p_m_ReliableDataBuffer->m_pMemory, count: (m_iCurBit + 7) >> 3);
      }
      if ( p_m_ReliableDataBuffer->m_nGrowSize >= 0 )
      {
        if ( p_m_ReliableDataBuffer->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ReliableDataBuffer->m_pMemory);
          p_m_ReliableDataBuffer->m_pMemory = nullptr;
        }
        p_m_ReliableDataBuffer->m_nAllocationCount = 0;
      }
      CUtlMemory<unsigned char,int>::EnsureCapacity(this: p_m_ReliableDataBuffer, num: nBytesa);
      if ( m_iCurBit > 0 )
      {
        _V_memcpy(dest: p_m_ReliableDataBuffer->m_pMemory, src: copybuf, count: (m_iCurBit + 7) >> 3);
        free(pMem: copybuf);
      }
      bf_write::StartWriting(
        this: stream,
        pData: p_m_ReliableDataBuffer->m_pMemory,
        nBytes: nBytesa,
        iStartBit: m_iCurBit,
        nBits: -1);
    }
    else
    {
      ConMsg(a1: "CNetChan::SetMaxBufferSize: cant preserve exiting data %i>%i.\n", (m_iCurBit + 7) >> 3, nBytesa);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9C90
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
// Address: 0x101A9D00
// Name: private: void CNetChan::UpdateSubChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::UpdateSubChannels(CNetChan *this)
{
  CNetChan *v1; // edi
  int v2; // eax
  int *i; // ecx
  CNetChan::subChannel_s *v4; // ebx
  int v5; // esi
  int j; // ecx
  CNetChan::dataFragments_s **m_pMemory; // eax
  CNetChan::dataFragments_s *v8; // edx
  int v9; // edi
  int numFragments; // eax
  int v11; // eax
  int v12; // eax
  int m_nOutReliableState; // ecx
  CNetChan::subChannel_s *freeSubChan; // [esp+4h] [ebp-Ch]
  bool bSendData; // [esp+Fh] [ebp-1h]

  v1 = this;
  v2 = 0;
  for ( i = &this->m_SubChannels[0].state; *i != 0; i += 7 )
  {
    if ( ++v2 >= 8 )
      return;
  }
  v4 = &v1->m_SubChannels[v2];
  freeSubChan = v4;
  if ( v4 != nullptr )
  {
    v5 = v1->m_MaxReliablePayloadSize >> 8;
    bSendData = false;
    for ( j = 0; j < 2; ++j )
    {
      if ( v1->m_WaitingList[j].m_Size > 0 )
      {
        m_pMemory = v1->m_WaitingList[j].m_Memory.m_pMemory;
        v8 = *m_pMemory;
        if ( !(*m_pMemory)->asTCP )
        {
          v9 = v8->pendingFragments + v8->ackedFragments;
          numFragments = v8->numFragments;
          if ( v9 == numFragments )
          {
            v1 = this;
          }
          else
          {
            v11 = numFragments - v9;
            if ( v5 < v11 )
              v11 = v5;
            if ( j == 1 )
            {
              if ( this->m_bFileBackgroundTranmission && v11 > 1 )
                v11 = 1;
              v4 = freeSubChan;
            }
            v4->startFraggment[j] = v9;
            v1 = this;
            v4->numFragments[j] = v11;
            v8->pendingFragments += v11;
            v5 -= v11;
            bSendData = true;
            if ( v5 <= 0 )
              goto LABEL_22;
          }
        }
      }
    }
    if ( !bSendData )
      return;
LABEL_22:
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
// Address: 0x101A9E10
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
// Address: 0x101A9E60
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
// Address: 0x101AAA40
// Name: private: void CNetChan::RemoveHeadInWaitingList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::RemoveHeadInWaitingList(CNetChan *this, CNetChan::dataFragments_s *nList)
{
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *v2; // edi
  void **v3; // esi
  bool v4; // zf

  v2 = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_WaitingList[(_DWORD)nList];
  v3 = (void **)*v2->m_Memory.m_pMemory;
  v4 = v3[66] == nullptr;
  nList = (CNetChan::dataFragments_s *)v3;
  if ( !v4 )
    free(pMem: v3[66]);
  if ( *v3 != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: *v3);
    *v3 = nullptr;
  }
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(this: v2, src: (vgui::TreeNode **)&nList);
  free(pMem: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101AAAB0
// Name: private: bool CNetChan::SendSubChannelData(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::SendSubChannelData(CNetChan *this, bf_write *buf)
{
  CNetChan::dataFragments_s *v3; // eax
  signed int v4; // eax
  CNetChan::subChannel_s *m_SubChannels; // ecx
  CNetChan::subChannel_s *v6; // ebx
  unsigned int *numFragments; // ebx
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // edi
  int m_iCurBit; // ecx
  int v12; // edx
  unsigned __int8 *v13; // eax
  CNetChan::dataFragments_s *v14; // ebx
  unsigned __int8 *v15; // eax
  int v16; // edx
  int v17; // ecx
  unsigned __int8 *v18; // eax
  int v19; // ecx
  unsigned __int8 *v20; // eax
  int v21; // ecx
  unsigned __int8 *v22; // eax
  int v23; // ecx
  unsigned __int8 *v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  char *buffer; // eax
  unsigned int v29; // eax
  void *v30; // edi
  CNetChan::subChannel_s *v31; // edi
  bool v32; // zf
  int v34; // [esp+Ch] [ebp-14h]
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v35; // [esp+10h] [ebp-10h]
  CNetChan::subChannel_s *subChan; // [esp+14h] [ebp-Ch]
  unsigned int offset; // [esp+18h] [ebp-8h]
  unsigned int length; // [esp+1Ch] [ebp-4h]
  unsigned int *bufa; // [esp+28h] [ebp+8h]

  CNetChan::CompressFragments(this, a2: this);
  if ( this->m_WaitingList[0].m_Size != 0 )
  {
    v3 = *this->m_WaitingList[0].m_Memory.m_pMemory;
    if ( v3->asTCP && v3->pendingFragments <= 0 )
      CNetChan::SendReliableViaStream(this, data: *this->m_WaitingList[0].m_Memory.m_pMemory);
  }
  CNetChan::UpdateSubChannels(this);
  v4 = 0;
  m_SubChannels = this->m_SubChannels;
  do
  {
    v6 = m_SubChannels;
    subChan = m_SubChannels;
    if ( m_SubChannels->state == 1 )
      break;
    ++v4;
    ++m_SubChannels;
  }
  while ( v4 < 8 );
  if ( v4 == 8 )
    return 0;
  bf_write::WriteUBitLong(this: buf, curData: v4, numbits: 3, bCheckRange: true);
  numFragments = (unsigned int *)v6->numFragments;
  m_WaitingList = this->m_WaitingList;
  bufa = numFragments;
  v35 = m_WaitingList;
  v34 = 2;
  do
  {
    m_iCurBit = buf->m_iCurBit;
    v12 = m_iCurBit + 1;
    if ( *numFragments == 0 )
    {
      if ( v12 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v13 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v13 &= ~(1 << (m_iCurBit & 7));
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      goto LABEL_81;
    }
    v14 = *m_WaitingList->m_Memory.m_pMemory;
    if ( v12 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v15 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v15 |= 1 << (m_iCurBit & 7);
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    offset = *(bufa - 2) << 8;
    v16 = v14->numFragments;
    length = *bufa << 8;
    if ( *bufa + *(bufa - 2) == v16 && (unsigned __int8)v14->bytes != 0 )
      length = (*bufa << 8) - (256 - (unsigned __int8)v14->bytes);
    if ( *bufa != v16 || v14->file != nullptr )
    {
      v21 = buf->m_iCurBit;
      if ( v21 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v22 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v22 |= 1 << (v21 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: *(bufa - 2), numbits: 18, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: *bufa, numbits: 3, bCheckRange: true);
      if ( offset != 0 )
        goto LABEL_71;
      v23 = buf->m_iCurBit;
      if ( v14->file == nullptr )
        goto LABEL_55;
      if ( v23 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          v24 = &buf->m_pData[buf->m_iCurBit >> 3];
          *v24 |= 1 << (v23 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->transferID, numbits: 32, bCheckRange: true);
      bf_write::WriteString(this: buf, pStr: v14->filename);
      v23 = buf->m_iCurBit;
      if ( v14->isReplayDemo )
      {
        if ( v23 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
LABEL_60:
          v26 = buf->m_iCurBit;
          if ( v14->isCompressed )
          {
            if ( v26 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v26 >> 3] |= 1 << (v26 & 7);
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
            bf_write::WriteUBitLong(this: buf, curData: v14->nUncompressedSize, numbits: 26, bCheckRange: true);
          }
          else if ( v26 + 1 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              v27 = &buf->m_pData[buf->m_iCurBit >> 3];
              *v27 &= ~(1 << (v26 & 7));
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
          bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 26, bCheckRange: true);
          goto LABEL_71;
        }
        if ( buf->m_bOverflow )
          goto LABEL_60;
        v25 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v25 |= 1 << (v23 & 7);
      }
      else
      {
LABEL_55:
        if ( v23 + 1 > buf->m_nDataBits )
        {
          buf->m_bOverflow = true;
          goto LABEL_60;
        }
        if ( buf->m_bOverflow )
          goto LABEL_60;
        buf->m_pData[v23 >> 3] &= ~(1 << (v23 & 7));
      }
      ++buf->m_iCurBit;
      goto LABEL_60;
    }
    v17 = buf->m_iCurBit;
    if ( v17 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v18 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v18 &= ~(1 << (v17 & 7));
        ++buf->m_iCurBit;
      }
    }
    else
    {
      buf->m_bOverflow = true;
    }
    v19 = buf->m_iCurBit;
    if ( v14->isCompressed )
    {
      if ( v19 + 1 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v19 >> 3] |= 1 << (v19 & 7);
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->nUncompressedSize, numbits: 26, bCheckRange: true);
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
    else if ( v19 + 1 <= buf->m_nDataBits )
    {
      if ( !buf->m_bOverflow )
      {
        v20 = &buf->m_pData[buf->m_iCurBit >> 3];
        *v20 &= ~(1 << (v19 & 7));
        ++buf->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
    else
    {
      buf->m_bOverflow = true;
      bf_write::WriteUBitLong(this: buf, curData: v14->bytes, numbits: 17, bCheckRange: true);
    }
LABEL_71:
    buffer = v14->buffer;
    if ( buffer != nullptr )
    {
      bf_write::WriteBytes(this: buf, pBuf: &buffer[offset], nBytes: length);
    }
    else
    {
      v29 = length;
      if ( length <= 1 )
        v29 = 1;
      v30 = MemAlloc_Alloc(nSize: v29);
      g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v14->file, a3: offset, a4: FILESYSTEM_SEEK_HEAD);
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v30, a3: length, a4: v14->file);
      bf_write::WriteBytes(this: buf, pBuf: v30, nBytes: length);
      free(pMem: v30);
    }
    if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    {
      numFragments = bufa;
      v31 = subChan;
      ConMsg(a1: "Sending subchan %i: start %i, num %i\n", subChan->index, *(bufa - 2), *bufa);
    }
    else
    {
      v31 = subChan;
      numFragments = bufa;
    }
    v31->sendSeqNr = this->m_nOutSequenceNr;
    v31->state = 2;
LABEL_81:
    m_WaitingList = v35 + 1;
    ++numFragments;
    v32 = v34-- == 1;
    ++v35;
    bufa = numFragments;
  }
  while ( !v32 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AAF30
// Name: private: bool CNetChan::_ProcessMessages(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::_ProcessMessages(CNetChan *this, bf_read *buf)
{
  char *m_pszString; // ecx
  char *v3; // eax
  bool v4; // zf
  int m_nValue; // esi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  const unsigned int *v9; // eax
  int v10; // ecx
  const unsigned int *v11; // eax
  int v12; // eax
  int m_nBitsAvail; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  unsigned __int8 v16; // dl
  const unsigned int *v17; // eax
  const unsigned int *v18; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // edx
  unsigned int v25; // esi
  CNetChan *v26; // esi
  CNetChan *v27; // ecx
  char v28; // al
  INetChannel *m_pActiveChannel; // edi
  int v31; // esi
  int v32; // ecx
  CNetChan *v33; // esi
  const char *v34; // eax
  INetMessage *v35; // esi
  const unsigned int *v36; // eax
  int v37; // eax
  CNetchanParanoidMode::MessageItem_t *v38; // edi
  const char *v39; // eax
  const unsigned int *v40; // eax
  int v41; // ecx
  int v42; // eax
  CNetchanParanoidMode::MessageItem_t *v43; // edi
  int v44; // eax
  const char *v45; // eax
  const unsigned int *v46; // eax
  CNetChan_vtbl *v47; // edi
  int v48; // eax
  const char *v49; // eax
  CNetChan *v50; // edi
  const char *v51; // eax
  const char *v52; // eax
  const char *v53; // eax
  bool v54; // al
  const unsigned int *v55; // eax
  int v56; // ecx
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // ebx
  int v60; // eax
  const char *v61; // eax
  const char *v62; // [esp-4h] [ebp-4Ch]
  const char *v63; // [esp-4h] [ebp-4Ch]
  bf_read democopy; // [esp+Ch] [ebp-3Ch] BYREF
  const char *msgname; // [esp+30h] [ebp-18h]
  int startbit; // [esp+34h] [ebp-14h]
  signed int v67; // [esp+38h] [ebp-10h]
  const char *blockmsgname; // [esp+3Ch] [ebp-Ch]
  const char *showmsgname; // [esp+40h] [ebp-8h]
  CNetChan *channel; // [esp+44h] [ebp-4h]
  unsigned __int8 bufa; // [esp+50h] [ebp+8h]
  bf_read *bufb; // [esp+50h] [ebp+8h]

  this->m_bStopProcessing = false;
  channel = this;
  if ( (net_showmsg.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    if ( net_showmsg.m_pParent->m_Value.m_pszString != nullptr )
    {
      m_pszString = net_showmsg.m_pParent->m_Value.m_pszString;
      showmsgname = m_pszString;
      goto LABEL_7;
    }
    m_pszString = (char *)defaultValue;
  }
  showmsgname = m_pszString;
LABEL_7:
  if ( (net_blockmsg.m_nFlags & 0x1000) != 0 )
  {
    v3 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v3 = net_blockmsg.m_pParent->m_Value.m_pszString;
    if ( v3 == nullptr )
      v3 = (char *)defaultValue;
  }
  v4 = *m_pszString == 48;
  blockmsgname = v3;
  if ( v4 )
    showmsgname = nullptr;
  if ( *v3 == 48 )
    blockmsgname = nullptr;
  if ( net_showpeaks.m_pParent != nullptr )
  {
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
        showmsgname = "1";
    }
  }
  v9 = buf->m_pData;
  democopy = *buf;
  if ( v9 != nullptr )
  {
    v10 = buf->m_nDataBits;
    startbit = 32 * (buf->m_pDataIn - v9) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( startbit >= v10 )
      startbit = v10;
  }
  else
  {
    startbit = 0;
  }
  if ( buf->m_bOverflow )
  {
LABEL_105:
    channel->m_MessageHandler->ConnectionCrashed(this: channel->m_MessageHandler, a2: "Buffer overflow in net message");
    return 0;
  }
  while ( 1 )
  {
    v11 = buf->m_pData;
    if ( v11 != nullptr )
    {
      v12 = 32 * (buf->m_pDataIn - v11) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( v12 >= buf->m_nDataBits )
        v12 = buf->m_nDataBits;
    }
    else
    {
      v12 = 0;
    }
    if ( buf->m_nDataBits - v12 < 6 )
      break;
    m_nBitsAvail = buf->m_nBitsAvail;
    if ( m_nBitsAvail < 6 )
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      m_nInBufWord = buf->m_nInBufWord;
      v22 = 6 - m_nBitsAvail;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_pDataIn = m_pDataIn + 1;
        v16 = 0;
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
        goto LABEL_50;
      }
      if ( m_pDataIn > m_pBufferEnd )
      {
        v16 = 0;
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_50;
      }
      v23 = *m_pDataIn;
      v4 = !buf->m_bOverflow;
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
      if ( !v4 )
      {
        v16 = 0;
LABEL_50:
        v26 = channel;
        v27 = channel;
        channel->m_bProcessingMessages = true;
        v28 = CNetChan::ProcessControlMessage(this: v27, cmd: v16, buf);
        v26->m_bProcessingMessages = false;
        if ( v28 == 0 )
        {
          if ( v26->m_bShouldDelete )
          {
            ((void (__thiscall *)(CNetChan *, int))v26->dtr_INetChannel)(a1: v26, a2: 1);
            return 0;
          }
          return 0;
        }
        goto LABEL_104;
      }
      v24 = v23;
      v25 = (v23 & CBitBuffer::s_nMaskTable[v22]) << m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v22;
      bufa = v25 | m_nInBufWord;
      buf->m_nInBufWord = v24 >> v22;
      v16 = v25 | m_nInBufWord;
    }
    else
    {
      v14 = buf->m_nInBufWord;
      v15 = m_nBitsAvail - 6;
      v16 = v14 & 0x3F;
      buf->m_nBitsAvail = v15;
      if ( v15 != 0 )
      {
        buf->m_nInBufWord = v14 >> 6;
        bufa = v14 & 0x3F;
      }
      else
      {
        v17 = buf->m_pDataIn;
        v18 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v17 == v18 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v17 + 1;
          bufa = v16;
        }
        else
        {
          if ( v17 <= v18 )
          {
            buf->m_nInBufWord = *v17;
            buf->m_pDataIn = v17 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufa = v16;
        }
      }
    }
    if ( v16 <= 2u )
      goto LABEL_50;
    m_pActiveChannel = channel->m_pActiveChannel;
    v31 = 0;
    v67 = (signed int)m_pActiveChannel[4232].__vftable;
    if ( v67 <= 0 )
      goto LABEL_57;
    msgname = (const char *)v16;
    while ( 1 )
    {
      v32 = *((_DWORD *)&m_pActiveChannel[4229].GetName + v31);
      if ( (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v32 + 28))(a1: v32) == msgname )
        break;
      if ( ++v31 >= v67 )
        goto LABEL_57;
    }
    v35 = *((INetMessage **)&m_pActiveChannel[4229].GetName + v31);
    if ( v35 == nullptr )
    {
LABEL_57:
      v33 = channel;
      v34 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Netchannel: unknown net message (%i) from %s.\n", bufa, v34);
      v62 = "unknown message";
LABEL_58:
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v33, pchReason: v62);
      return 0;
    }
    msgname = v35->GetName(this: v35);
    v36 = buf->m_pData;
    if ( v36 != nullptr )
    {
      bufb = (bf_read *)(32 * (buf->m_pDataIn - v36) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)bufb >= buf->m_nDataBits )
        bufb = (bf_read *)buf->m_nDataBits;
    }
    else
    {
      bufb = nullptr;
    }
    if ( g_NetParanoid.m_bInitialized )
    {
      v37 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
      if ( v37 != 0 && g_NetParanoid.m_nPacketMessageCount < 255 )
      {
        v38 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount++];
        v38->m_pMsg = v35;
        v38->m_nMessageSize = v35->GetSize(this: v35);
        v38->m_nType = v35->GetType(this: v35);
        v38->m_nGroup = v35->GetGroup(this: v35);
        v39 = v35->GetName(this: v35);
        V_strncpy(pDest: v38->m_szName, pSrc: v39, maxLen: 32);
        v38->m_szDesc[0] = 0;
        v38->m_nStartBit = (int)bufb;
        v38->m_nEndBit = -1;
      }
    }
    if ( !v35->ReadFromBuffer(this: v35, a2: buf) )
    {
      v33 = channel;
      v61 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Netchannel: failed reading message %s from %s.\n", msgname, v61);
      v62 = "failed reading message";
      goto LABEL_58;
    }
    v40 = buf->m_pData;
    if ( v40 != nullptr )
    {
      v41 = buf->m_nDataBits;
      v67 = 32 * (buf->m_pDataIn - v40) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( v67 >= v41 )
        v67 = v41;
    }
    else
    {
      v67 = 0;
    }
    if ( g_NetParanoid.m_bInitialized )
    {
      v42 = net_paranoid.m_pParent != nullptr ? net_paranoid.m_pParent->m_Value.m_nValue : 0;
      if ( v42 != 0 && g_NetParanoid.m_nPacketMessageCount > 0 )
      {
        v43 = &g_NetParanoid.m_pPacketMessages[g_NetParanoid.m_nPacketMessageCount - 1];
        if ( v43->m_pMsg == v35 )
        {
          if ( v35->GetSize(this: v35) >= 0x80 )
            v44 = 128;
          else
            v44 = v35->GetSize(this: v35);
          _V_memcpy(dest: v43->m_Message, src: v35, count: v44);
          v43->m_nEndBit = v67;
          v45 = v35->ToString(this: v35);
          V_strncpy(pDest: v43->m_szDesc, pSrc: v45, maxLen: 128);
        }
      }
    }
    v46 = buf->m_pData;
    if ( v46 != nullptr )
    {
      v46 = (const unsigned int *)(32 * (buf->m_pDataIn - v46) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3));
      if ( (int)v46 >= buf->m_nDataBits )
        v46 = (const unsigned int *)buf->m_nDataBits;
    }
    v47 = channel->__vftable;
    v48 = ((int (__thiscall *)(INetMessage *, int))v35->GetGroup)(a1: v35, a2: (char *)v46 - (char *)bufb);
    ((void (__thiscall *)(CNetChan *, int))v47->UpdateMessageStats)(a1: channel, a2: v48);
    if ( showmsgname != nullptr
      && (*showmsgname == 49 || (v49 = v35->GetName(this: v35), _V_stricmp(s1: showmsgname, s2: v49) == 0)) )
    {
      v50 = channel;
      v63 = v35->ToString(this: v35);
      v51 = netadr_s::ToString(this: &channel->remote_address, baseOnly: false);
      ConMsg(a1: "Msg from %s: %s\n", v51, v63);
    }
    else
    {
      v50 = channel;
    }
    if ( blockmsgname != nullptr
      && (*blockmsgname == 49 || (v52 = v35->GetName(this: v35), _V_stricmp(s1: blockmsgname, s2: v52) == 0)) )
    {
      v53 = v35->ToString(this: v35);
      ConMsg(a1: "Blocking message %s\n", v53);
    }
    else
    {
      v50->m_bProcessingMessages = true;
      v54 = v35->Process(this: v35);
      v4 = !v50->m_bShouldDelete;
      v50->m_bProcessingMessages = false;
      if ( !v4 )
      {
        ((void (__thiscall *)(CNetChan *, int))v50->dtr_INetChannel)(a1: v50, a2: 1);
        return 0;
      }
      if ( v50->m_bStopProcessing )
        return 0;
      if ( !v54 )
      {
        _ConDMsg(a1: "Netchannel: failed processing message %s.\n", msgname);
        CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel: v50, pchReason: "failed processing");
        return 0;
      }
      if ( v50->IsOverflowed(this: v50) )
        return 0;
    }
LABEL_104:
    if ( buf->m_bOverflow )
      goto LABEL_105;
  }
  if ( channel->m_DemoRecorder != nullptr && !demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v55 = buf->m_pData;
    if ( v55 != nullptr )
    {
      v56 = (char *)buf->m_pDataIn - (char *)v55;
      v57 = 2 * (buf->m_nDataBytes & 3);
      v58 = 32 * (v56 >> 2) - buf->m_nBitsAvail;
      v59 = buf->m_nDataBits;
      v55 = (const unsigned int *)(v58 + 4 * v57);
      if ( (int)v55 >= v59 )
        v55 = (const unsigned int *)v59;
    }
    channel->m_DemoRecorder->RecordMessages(this: channel->m_DemoRecorder, a2: &democopy, a3: (int)v55 - startbit);
  }
  if ( net_dumptest.m_pParent != nullptr )
  {
    v60 = net_dumptest.m_pParent->m_Value.m_nValue;
    if ( v60 > 0 )
    {
      if ( v60 == 2 )
      {
        MEMORY[0] = 1;
        return 1;
      }
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&net_dumptest.IConVar, value: 0);
      CNetchanParanoidMode::Dump(this: &g_NetParanoid, channel, pchReason: "requested from console");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AB670
// Name: private: int CNetChan::ProcessPacketHeader(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::ProcessPacketHeader(CNetChan *this, netpacket_s *packet)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  const unsigned int *v6; // edx
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edi
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  const unsigned int *v17; // edx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  unsigned int v20; // ebx
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // edi
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // edx
  const unsigned int *v29; // ecx
  const unsigned int *v30; // eax
  const unsigned int *v31; // edx
  unsigned int v32; // ebx
  int v33; // eax
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // edi
  int v37; // ecx
  unsigned int v38; // eax
  __int16 v39; // dx
  int v40; // ecx
  const unsigned int *v41; // ecx
  const unsigned int *v42; // eax
  const unsigned int *v43; // edx
  unsigned int v44; // ebx
  int v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  unsigned int m_nDataBytes; // edi
  int v52; // ebx
  const char *v53; // eax
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // edx
  int v58; // ecx
  const unsigned int *v59; // ecx
  const unsigned int *v60; // eax
  const unsigned int *v61; // edx
  unsigned int v62; // ebx
  int v63; // eax
  const unsigned int *v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // edi
  int v67; // ebx
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // ecx
  const unsigned int *v71; // ecx
  const unsigned int *v72; // eax
  const unsigned int *v73; // edx
  unsigned int v74; // ebx
  int v75; // eax
  const unsigned int *v76; // ecx
  unsigned int v77; // edx
  unsigned int v78; // edi
  CNetChan *v79; // edx
  int v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  int v83; // eax
  const char *v84; // eax
  int v85; // ecx
  int *numFragments; // edi
  int m_nOutReliableState; // edx
  int v88; // eax
  int j; // eax
  CNetChan::dataFragments_s *v90; // eax
  CNetChan::dataFragments_s *v91; // eax
  int k; // eax
  int v93; // eax
  int v94; // eax
  int m; // eax
  CNetChan *v96; // eax
  int v97; // ecx
  int v98; // edi
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // ebx
  const char *v100; // eax
  CNetChan::dataFragments_s *v101; // eax
  int v102; // ecx
  int v103; // [esp-8h] [ebp-2Ch]
  int m_nInSequenceNr; // [esp-4h] [ebp-28h]
  int v105; // [esp-4h] [ebp-28h]
  int v106; // [esp-4h] [ebp-28h]
  const unsigned int *nChokeda; // [esp+Ch] [ebp-18h]
  int nChoked; // [esp+Ch] [ebp-18h]
  __int16 v109; // [esp+10h] [ebp-14h]
  int v110; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h] BYREF
  int v112; // [esp+18h] [ebp-Ch]
  int v113; // [esp+1Ch] [ebp-8h]
  CNetChan *v114; // [esp+20h] [ebp-4h]
  netpacket_s *packeta; // [esp+2Ch] [ebp+8h]

  v114 = this;
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v10 = 32 - m_nBitsAvail;
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
      packeta = nullptr;
    }
    else
    {
      v12 = packet->message.m_nInBufWord;
      v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v10;
      packeta = (netpacket_s *)(v13 | m_nInBufWord);
      packet->message.m_nInBufWord = v12 >> v10;
    }
    goto LABEL_19;
  }
  v4 = packet->message.m_nInBufWord;
  v5 = m_nBitsAvail - 32;
  packet->message.m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    packet->message.m_nInBufWord = 0;
    packeta = (netpacket_s *)v4;
  }
  else
  {
    v6 = packet->message.m_pBufferEnd;
    v7 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v7 == v6 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v7 + 1;
      packeta = (netpacket_s *)v4;
    }
    else
    {
      if ( v7 <= v6 )
      {
        packet->message.m_nInBufWord = *v7;
        packet->message.m_pDataIn = v7 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      packeta = (netpacket_s *)v4;
    }
  }
LABEL_19:
  v14 = packet->message.m_nBitsAvail;
  if ( v14 < 32 )
  {
    v19 = packet->message.m_pBufferEnd;
    v20 = packet->message.m_nInBufWord;
    v21 = 32 - v14;
    v22 = packet->message.m_pDataIn;
    if ( v22 == v19 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v22 > v19 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_34;
      }
      packet->message.m_nInBufWord = *v22;
    }
    packet->message.m_pDataIn = v22 + 1;
LABEL_34:
    if ( packet->message.m_bOverflow )
    {
      v113 = 0;
    }
    else
    {
      v23 = packet->message.m_nInBufWord;
      v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v21;
      v113 = v24 | v20;
      packet->message.m_nInBufWord = v23 >> v21;
    }
    goto LABEL_37;
  }
  v15 = packet->message.m_nInBufWord;
  v16 = v14 - 32;
  packet->message.m_nBitsAvail = v16;
  if ( v16 != 0 )
  {
    packet->message.m_nInBufWord = 0;
    v113 = v15;
  }
  else
  {
    v17 = packet->message.m_pBufferEnd;
    v18 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v18 == v17 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v18 + 1;
      v113 = v15;
    }
    else
    {
      if ( v18 <= v17 )
      {
        packet->message.m_nInBufWord = *v18;
        packet->message.m_pDataIn = v18 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v113 = v15;
    }
  }
LABEL_37:
  v25 = packet->message.m_nBitsAvail;
  if ( v25 < 8 )
  {
    v31 = packet->message.m_pBufferEnd;
    v32 = packet->message.m_nInBufWord;
    v33 = 8 - v25;
    v34 = packet->message.m_pDataIn;
    if ( v34 == v31 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v34 > v31 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_52;
      }
      packet->message.m_nInBufWord = *v34;
    }
    packet->message.m_pDataIn = v34 + 1;
LABEL_52:
    if ( packet->message.m_bOverflow )
    {
      v112 = 0;
    }
    else
    {
      v35 = packet->message.m_nInBufWord;
      v36 = (v35 & CBitBuffer::s_nMaskTable[v33]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v33;
      v112 = v36 | v32;
      packet->message.m_nInBufWord = v35 >> v33;
    }
    goto LABEL_55;
  }
  v26 = packet->message.m_nInBufWord;
  v27 = v25 - 8;
  v28 = (unsigned __int8)v26;
  packet->message.m_nBitsAvail = v27;
  if ( v27 != 0 )
  {
    packet->message.m_nInBufWord = v26 >> 8;
    v112 = (unsigned __int8)v26;
  }
  else
  {
    v29 = packet->message.m_pBufferEnd;
    v30 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v30 == v29 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v30 + 1;
      v112 = v28;
    }
    else
    {
      if ( v30 <= v29 )
      {
        packet->message.m_nInBufWord = *v30;
        packet->message.m_pDataIn = v30 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v112 = v28;
    }
  }
LABEL_55:
  if ( !NET_IsMultiplayer() )
    goto LABEL_80;
  v37 = packet->message.m_nBitsAvail;
  if ( v37 < 16 )
  {
    v43 = packet->message.m_pBufferEnd;
    v44 = packet->message.m_nInBufWord;
    v45 = 16 - v37;
    v46 = packet->message.m_pDataIn;
    if ( v46 == v43 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v46 > v43 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_71;
      }
      packet->message.m_nInBufWord = *v46;
    }
    packet->message.m_pDataIn = v46 + 1;
LABEL_71:
    if ( packet->message.m_bOverflow )
    {
      v109 = 0;
    }
    else
    {
      v47 = packet->message.m_nInBufWord;
      v48 = (v47 & CBitBuffer::s_nMaskTable[v45]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v45;
      v109 = v48 | v44;
      packet->message.m_nInBufWord = v47 >> v45;
    }
    goto LABEL_74;
  }
  v38 = packet->message.m_nInBufWord;
  v39 = v38;
  v40 = v37 - 16;
  packet->message.m_nBitsAvail = v40;
  if ( v40 != 0 )
  {
    packet->message.m_nInBufWord = HIWORD(v38);
    v109 = v38;
  }
  else
  {
    v41 = packet->message.m_pBufferEnd;
    v42 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v42 == v41 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v42 + 1;
      v109 = v39;
    }
    else
    {
      if ( v42 <= v41 )
      {
        packet->message.m_nInBufWord = *v42;
        packet->message.m_pDataIn = v42 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v109 = v39;
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
  m_nDataBytes = packet->message.m_nDataBytes;
  v52 = m_nDataBits >> 3;
  nChokeda = packet->message.m_pData;
  CRC32_Init(pulCRC: (unsigned int *)&i);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&i, pBuffer: (char *)nChokeda + v52, nBuffer: m_nDataBytes - v52);
  CRC32_Final(pulCRC: (unsigned int *)&i);
  if ( ((unsigned __int16)i ^ HIWORD(i)) != v109 )
  {
    m_nInSequenceNr = v114->m_nInSequenceNr;
    v53 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
    ConMsg(a1: "%s:corrupted packet %i at %i\n", v53, packeta, m_nInSequenceNr);
    return -1;
  }
LABEL_80:
  v55 = packet->message.m_nBitsAvail;
  if ( v55 < 8 )
  {
    v61 = packet->message.m_pBufferEnd;
    v62 = packet->message.m_nInBufWord;
    v63 = 8 - v55;
    v64 = packet->message.m_pDataIn;
    if ( v64 == v61 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v64 > v61 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_95;
      }
      packet->message.m_nInBufWord = *v64;
    }
    packet->message.m_pDataIn = v64 + 1;
LABEL_95:
    if ( packet->message.m_bOverflow )
    {
      v110 = 0;
    }
    else
    {
      v65 = packet->message.m_nInBufWord;
      v66 = (v65 & CBitBuffer::s_nMaskTable[v63]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v63;
      v110 = v66 | v62;
      packet->message.m_nInBufWord = v65 >> v63;
    }
    goto LABEL_98;
  }
  v56 = packet->message.m_nInBufWord;
  v57 = (unsigned __int8)v56;
  v58 = v55 - 8;
  packet->message.m_nBitsAvail = v58;
  if ( v58 != 0 )
  {
    packet->message.m_nInBufWord = v56 >> 8;
    v110 = (unsigned __int8)v56;
  }
  else
  {
    v59 = packet->message.m_pBufferEnd;
    v60 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v60 == v59 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v60 + 1;
      v110 = v57;
    }
    else
    {
      if ( v60 <= v59 )
      {
        packet->message.m_nInBufWord = *v60;
        packet->message.m_pDataIn = v60 + 1;
      }
      else
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
      }
      v110 = v57;
    }
  }
LABEL_98:
  v67 = 0;
  nChoked = 0;
  if ( (v112 & 0x10) == 0 )
    goto LABEL_117;
  v68 = packet->message.m_nBitsAvail;
  if ( v68 < 8 )
  {
    v73 = packet->message.m_pBufferEnd;
    v74 = packet->message.m_nInBufWord;
    v75 = 8 - v68;
    v76 = packet->message.m_pDataIn;
    if ( v76 == v73 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v76 > v73 )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
        goto LABEL_113;
      }
      packet->message.m_nInBufWord = *v76;
    }
    packet->message.m_pDataIn = v76 + 1;
LABEL_113:
    if ( packet->message.m_bOverflow )
    {
      v67 = 0;
    }
    else
    {
      v77 = packet->message.m_nInBufWord;
      v78 = (v77 & CBitBuffer::s_nMaskTable[v75]) << packet->message.m_nBitsAvail;
      packet->message.m_nBitsAvail = 32 - v75;
      v67 = v78 | v74;
      packet->message.m_nInBufWord = v77 >> v75;
    }
    goto LABEL_116;
  }
  v69 = packet->message.m_nInBufWord;
  v67 = (unsigned __int8)v69;
  v70 = v68 - 8;
  packet->message.m_nBitsAvail = v70;
  if ( v70 != 0 )
  {
    packet->message.m_nInBufWord = v69 >> 8;
  }
  else
  {
    v71 = packet->message.m_pBufferEnd;
    v72 = packet->message.m_pDataIn;
    packet->message.m_nBitsAvail = 32;
    if ( v72 == v71 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v72 + 1;
    }
    else if ( v72 <= v71 )
    {
      packet->message.m_nInBufWord = *v72;
      packet->message.m_pDataIn = v72 + 1;
    }
    else
    {
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
    }
  }
LABEL_116:
  nChoked = v67;
LABEL_117:
  v79 = v114;
  v80 = v114->m_nInSequenceNr;
  if ( (int)packeta > v80 )
  {
    v83 = (int)packeta + -v67 - v80 - 1;
    v114->m_PacketDrop = v83;
    if ( v83 > 0 && net_showdrop.m_pParent != nullptr && net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v103 = v83;
      v84 = netadr_s::ToString(this: &v79->remote_address, baseOnly: false);
      ConMsg(a1: "%s:Dropped %i packets at %i\n", v84, v103, packeta);
      v79 = v114;
    }
    LOBYTE(v85) = 0;
    i = 0;
    numFragments = v79->m_SubChannels[0].numFragments;
    do
    {
      m_nOutReliableState = v114->m_nOutReliableState;
      if ( ((1 << v85) & m_nOutReliableState) == ((1 << v85) & v110) )
      {
        v88 = numFragments[3];
        if ( v88 == 3 )
        {
          numFragments[3] = 0;
          numFragments[2] = -1;
          for ( j = 0; j < 2; ++j )
          {
            numFragments[j] = 0;
            numFragments[j - 2] = -1;
          }
        }
        else
        {
          if ( numFragments[2] > v113 )
          {
            v106 = i;
            v100 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
            ConMsg(a1: "%s:reliable state invalid (%i).\n", v100, v106);
            return -1;
          }
          if ( v88 == 2 )
          {
            if ( *numFragments != 0 )
            {
              v90 = *v114->m_WaitingList[0].m_Memory.m_pMemory;
              v90->ackedFragments += *numFragments;
              v90->pendingFragments -= *numFragments;
            }
            if ( numFragments[1] != 0 )
            {
              v91 = *v114->m_WaitingList[1].m_Memory.m_pMemory;
              v91->ackedFragments += numFragments[1];
              v91->pendingFragments -= numFragments[1];
            }
            numFragments[3] = 0;
            numFragments[2] = -1;
            for ( k = 0; k < 2; ++k )
            {
              numFragments[k] = 0;
              numFragments[k - 2] = -1;
            }
          }
        }
      }
      else if ( numFragments[2] <= v113 )
      {
        v93 = numFragments[3];
        if ( v93 == 2 )
        {
          if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            ConMsg(a1: "Resending subchan %i: start %i, num %i\n", numFragments[4], *(numFragments - 2), *numFragments);
          numFragments[3] = 1;
        }
        else if ( v93 == 3 )
        {
          v94 = 1 << numFragments[4];
          if ( (m_nOutReliableState & v94) != 0 )
            v114->m_nOutReliableState = m_nOutReliableState & ~v94;
          else
            v114->m_nOutReliableState = v94 | m_nOutReliableState;
          numFragments[3] = 0;
          numFragments[2] = -1;
          for ( m = 0; m < 2; ++m )
          {
            numFragments[m] = 0;
            numFragments[m - 2] = -1;
          }
        }
      }
      v85 = i + 1;
      numFragments += 7;
      i = v85;
    }
    while ( v85 < 8 );
    v96 = v114;
    v97 = v113;
    v114->m_nInSequenceNr = (int)packeta;
    v96->m_nOutSequenceNrAck = v97;
    v98 = 0;
    m_WaitingList = v96->m_WaitingList;
    while ( 1 )
    {
      if ( m_WaitingList->m_Size != 0 && v96->m_nOutSequenceNrAck > 0 )
      {
        v101 = *m_WaitingList->m_Memory.m_pMemory;
        v102 = v101->numFragments;
        if ( v101->ackedFragments == v102 )
        {
          if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
            ConMsg(a1: "Sending complete: %i fragments, %i bytes.\n", v102, v101->bytes);
          CNetChan::RemoveHeadInWaitingList(this: v114, nList: (CNetChan::dataFragments_s *)v98);
        }
      }
      ++v98;
      ++m_WaitingList;
      if ( v98 >= 2 )
        break;
      v96 = v114;
    }
    CNetChan::FlowNewPacket(
      this: v114,
      flow: 1,
      seqnr: v114->m_nInSequenceNr,
      acknr: v114->m_nOutSequenceNrAck,
      nChoked,
      nDropped: v114->m_PacketDrop,
      nSize: packet->wiresize + 28);
    return v112;
  }
  else
  {
    if ( net_showdrop.m_pParent != nullptr && net_showdrop.m_pParent->m_Value.m_nValue != 0 )
    {
      v105 = v114->m_nInSequenceNr;
      if ( packeta == (netpacket_s *)v80 )
      {
        v81 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
        ConMsg(a1: "%s:duplicate packet %i at %i\n", v81, packeta, v105);
        return -1;
      }
      v82 = netadr_s::ToString(this: &v114->remote_address, baseOnly: false);
      ConMsg(a1: "%s:out of order packet %i at %i\n", v82, packeta, v105);
    }
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACF30
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
  int v10; // edx
  int *p_state; // ecx
  int i; // edi
  int m_nOutReliableState; // eax
  int j; // eax
  void (__thiscall *Reset)(struct CNetChan *); // edx
  int v17; // [esp+10h] [ebp-8h]
  char **v18; // [esp+14h] [ebp-4h]

  v1 = this;
  p_buffer = (void **)&this->m_ReceiveList[0].buffer;
  v18 = &this->m_ReceiveList[0].buffer;
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
      p_buffer = (void **)v18;
      v1 = this;
    }
    if ( *p_buffer != nullptr )
    {
      free(pMem: *p_buffer);
      *p_buffer = nullptr;
    }
    p_buffer += 76;
    p_m_Size += 5;
    v9 = v17-- == 1;
    v18 = (char **)p_buffer;
  }
  while ( !v9 );
  v10 = 1;
  p_state = &v1->m_SubChannels[0].state;
  for ( i = 8; i != 0; --i )
  {
    if ( *p_state == 1 )
    {
      m_nOutReliableState = v1->m_nOutReliableState;
      if ( (m_nOutReliableState & v10) != 0 )
        v1->m_nOutReliableState = m_nOutReliableState & ~v10;
      else
        v1->m_nOutReliableState = v10 | m_nOutReliableState;
      *p_state = 0;
      *(p_state - 1) = -1;
      for ( j = 0; j < 2; ++j )
      {
        p_state[j - 3] = 0;
        p_state[j - 5] = -1;
      }
    }
    else if ( *p_state == 2 )
    {
      *p_state = 3;
    }
    p_state += 7;
    v10 = __ROL4__(v10, 1);
  }
  Reset = v1->Reset;
  v1->m_bStopProcessing = true;
  Reset(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101AD090
// Name: public: virtual void CNetChan::Shutdown(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetChan::Shutdown(CNetChan *this@<ecx>, int a2@<edi>, const char *pReason)
{
  SOCKET m_StreamSocket; // eax
  unsigned __int64 v5; // rax
  INetChannelHandler *m_MessageHandler; // ecx
  int v7; // edi
  INetMessage *v8; // ecx

  if ( this->m_Socket >= 0 )
  {
    ((void (__thiscall *)(CNetChan *, int))this->Clear)(a1: this, a2);
    if ( pReason != nullptr )
    {
      bf_write::WriteUBitLong(this: &this->m_StreamUnreliable, curData: 1u, numbits: 6, bCheckRange: true);
      bf_write::WriteString(this: &this->m_StreamUnreliable, pStr: pReason);
      this->Transmit(this, a2: false);
    }
    m_StreamSocket = this->m_StreamSocket;
    if ( m_StreamSocket != 0 )
    {
      NET_CloseSocket(hSocket: m_StreamSocket, sock: this->m_Socket);
      this->m_StreamSocket = 0;
      this->m_StreamActive = false;
    }
    v5 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
    if ( v5 != 0 )
      NET_TerminateSteamConnection(sock: this->m_Socket, uSteamID: v5);
    this->m_Socket = -1;
    netadr_s::Clear(this: &this->remote_address);
    m_MessageHandler = this->m_MessageHandler;
    v7 = 0;
    if ( m_MessageHandler != nullptr )
    {
      m_MessageHandler->ConnectionClosing(this: m_MessageHandler, a2: pReason);
      this->m_MessageHandler = nullptr;
    }
    if ( this->m_NetMessages.m_Size > 0 )
    {
      do
      {
        v8 = this->m_NetMessages.m_Memory.m_pMemory[v7];
        if ( v8 != nullptr )
          ((void (__thiscall *)(INetMessage *, int))v8->dtr_INetMessage)(a1: v8, a2: 1);
        ++v7;
      }
      while ( v7 < this->m_NetMessages.m_Size );
    }
    this->m_NetMessages.m_Size = 0;
    if ( this->m_NetMessages.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_NetMessages.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NetMessages.m_Memory.m_pMemory);
        this->m_NetMessages.m_Memory.m_pMemory = nullptr;
      }
      this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
    }
    this->m_NetMessages.m_pElements = this->m_NetMessages.m_Memory.m_pMemory;
    this->m_DemoRecorder = nullptr;
    if ( this->m_bProcessingMessages )
    {
      NET_RemoveNetChannel(netchan: this, bDeleteNetChan: false);
      this->m_bShouldDelete = true;
    }
    else
    {
      NET_RemoveNetChannel(netchan: this, bDeleteNetChan: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD200
// Name: private: bool CNetChan::ProcessMessages(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::ProcessMessages(CNetChan *this, bf_read *buf)
{
  IMDLCache *v2; // esi
  char v4; // bl

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  this->m_pActiveChannel = this;
  v4 = CNetChan::_ProcessMessages(this, buf);
  v2->EndLock(this: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101AD240
// Name: public: virtual void CNetChan::ProcessPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ProcessPlayback(CNetChan *this)
{
  netpacket_s *i; // ebx
  int m_nOutSequenceNrAck; // edx
  IMDLCache *v4; // edi
  char v5; // bl

  for ( i = demoplayer->ReadPacket(this: demoplayer); i != nullptr; i = demoplayer->ReadPacket(this: demoplayer) )
  {
    CNetChan::FlowNewPacket(
      this,
      flow: 1,
      seqnr: this->m_nInSequenceNr,
      acknr: this->m_nOutSequenceNrAck,
      nChoked: 0,
      nDropped: 0,
      nSize: i->wiresize);
    m_nOutSequenceNrAck = this->m_nOutSequenceNrAck;
    this->last_received = net_time;
    this->m_MessageHandler->PacketStart(
      this: this->m_MessageHandler,
      a2: this->m_nInSequenceNr,
      a3: m_nOutSequenceNrAck);
    v4 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    this->m_pActiveChannel = this;
    v5 = CNetChan::_ProcessMessages(this, buf: &i->message);
    v4->EndLock(this: v4);
    if ( v5 == 0 )
      break;
    this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD300
// Name: private: bool CNetChan::CheckReceivingList(int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNetChan::CheckReceivingList@<al>(CNetChan *this@<ecx>, int a2@<ebx>, int nList)
{
  bool v4; // zf
  CNetChan::dataFragments_s *v5; // esi
  char result; // al
  int ackedFragments; // eax
  int numFragments; // ecx
  char *v9; // ecx
  void *v10; // eax
  int bytes; // [esp-10h] [ebp-40h]
  bf_read buffer; // [esp+8h] [ebp-28h] BYREF
  CNetChan *v13; // [esp+2Ch] [ebp-4h]

  v4 = this->m_ReceiveList[nList].buffer == nullptr;
  v5 = &this->m_ReceiveList[nList];
  v13 = this;
  if ( v4 )
    return 1;
  ackedFragments = this->m_ReceiveList[nList].ackedFragments;
  numFragments = this->m_ReceiveList[nList].numFragments;
  if ( ackedFragments < numFragments )
    return 1;
  if ( ackedFragments > numFragments )
  {
    ConMsg(a1: "Receiving failed: too many fragments %i/%i\n", ackedFragments, v5->numFragments);
    return 0;
  }
  if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "Receiving complete: %i fragments, %i bytes\n", numFragments, v5->bytes);
  if ( v5->isCompressed )
    CNetChan::UncompressFragments(this, data: v5);
  if ( v5->filename[0] != 0 )
  {
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: nullptr)
      || CL_ShouldRedownloadFile(filename: v5->filename) )
    {
      COM_CreatePath(path: v5->filename);
      v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5->filename, a3: "wb", a4: 0);
      v5->file = v10;
      if ( v10 != nullptr )
      {
        ((void (__thiscall *)(IBaseFileSystem *, char *, unsigned int, void *, int))g_pFileSystem->Write)(
          a1: &g_pFileSystem->IBaseFileSystem,
          a2: v5->buffer,
          a3: v5->bytes,
          a4: v10,
          a5: a2);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5->file);
        if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
          DevMsg(a1: "FileReceived: %s, %i bytes (ID %i)\n", v5->filename, v5->bytes, v5->transferID);
        ((void (__thiscall *)(INetChannelHandler *, char *, unsigned int))v13->m_MessageHandler->FileReceived)(
          a1: v13->m_MessageHandler,
          a2: v5->filename,
          a3: v5->transferID);
      }
      else
      {
        ConMsg(a1: "Failed to write received file '%s'!\n", v5->filename);
      }
    }
    else
    {
      ConMsg(a1: "Download file '%s' already exists!\n", v5->filename);
    }
  }
  else
  {
    v9 = v5->buffer;
    buffer.m_pDebugName = nullptr;
    buffer.m_nDataBytes = 0;
    bytes = v5->bytes;
    buffer.m_bOverflow = false;
    buffer.m_nDataBits = -1;
    CBitRead::StartReading(this: &buffer, pData: v9, nBytes: bytes, iStartBit: 0, nBits: -1);
    result = CNetChan::ProcessMessages(this: v13, buf: &buffer);
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
// Address: 0x101AD500
// Name: public: virtual void CNetChan::ProcessPacket(struct netpacket_s __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::ProcessPacket(CNetChan *this, netpacket_s *packet, int bHasHeader)
{
  bf_read *p_message; // esi
  int m_nValue; // eax
  unsigned __int64 v6; // rax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int m_nOutSequenceNrAck; // eax
  INetChannelHandler *m_MessageHandler; // ecx
  int m_nBitsAvail; // ecx
  unsigned int v14; // eax
  char v15; // dl
  int v16; // ecx
  char v17; // cl
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  int v20; // eax
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edx
  unsigned int v24; // edi
  int v25; // edi
  unsigned int v26; // eax
  int v27; // edx
  const unsigned int *v29; // eax
  const unsigned int *v30; // ecx
  int m_nInReliableState; // eax
  int v32; // edi
  int m_pData; // eax
  IMDLCache *v34; // edi
  char v35; // al
  IMDLCache_vtbl *v36; // edx
  const char *v37; // [esp+4h] [ebp-9Ch]
  unsigned __int64 v38; // [esp+8h] [ebp-98h]
  __int64 v39; // [esp+8h] [ebp-98h]
  const char *v40; // [esp+Ch] [ebp-94h]
  char desc[128]; // [esp+1Ch] [ebp-84h] BYREF
  int flags; // [esp+9Ch] [ebp-4h]
  unsigned int packeta; // [esp+A8h] [ebp+8h]

  p_message = &packet->message;
  CBitRead::Seek(this: &packet->message, nPosition: 0);
  if ( netadr_s::IsValid(this: &this->remote_address)
    && !netadr_s::CompareAdr(this: &packet->from, a: &this->remote_address, onlyBase: false) )
  {
    return;
  }
  CNetchanParanoidMode::StartPacket(this: &g_NetParanoid, fullbuf: p_message);
  CNetChan::FlowUpdate(this, flow: 1, addbytes: packet->wiresize + 28);
  flags = 0;
  if ( (_BYTE)bHasHeader != 0 )
  {
    flags = CNetChan::ProcessPacketHeader(this, packet);
    if ( flags == -1 )
      return;
  }
  CNetchanParanoidMode::NoteHeaderSize(this: &g_NetParanoid, msg: p_message, flags);
  if ( net_showudp.m_pParent != nullptr )
  {
    m_nValue = net_showudp.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0
      && m_nValue != 3
      && (net_showudp_remoteonly.m_pParent == nullptr
       || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
       || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
    {
      v6 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
      bHasHeader = -14336;
      if ( v6 != 0 )
      {
        v38 = v6;
        bHasHeader = -10158081;
        v7 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v8 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                             a1: this,
                             a2: v7,
                             a3: v38,
                             a4: HIDWORD(v38));
        V_snprintf(pDest: desc, maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v8, v37, v39);
      }
      else
      {
        v9 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v10 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v9);
        V_snprintf(pDest: desc, maxLen: 128, pFormat: "%12.12s %21.21s", v10, v40);
      }
      ConColorMsg(
        a1: (const struct Color *)&bHasHeader,
        a2: "UDP <- %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f wire=%i\n",
        desc,
        packet->size,
        this->m_nInSequenceNr & 0x3F,
        this->m_nOutSequenceNrAck & 0x3F,
        flags & 1,
        (double)net_time,
        packet->wiresize);
    }
  }
  m_nOutSequenceNrAck = this->m_nOutSequenceNrAck;
  m_MessageHandler = this->m_MessageHandler;
  this->last_received = net_time;
  m_MessageHandler->PacketStart(this: m_MessageHandler, a2: this->m_nInSequenceNr, a3: m_nOutSequenceNrAck);
  if ( (flags & 1) == 0 )
  {
LABEL_52:
    m_pData = (int)p_message->m_pData;
    if ( m_pData != 0 )
    {
      m_pData = 32 * (((int)p_message->m_pDataIn - m_pData) >> 2)
              - p_message->m_nBitsAvail
              + 8 * (p_message->m_nDataBytes & 3);
      if ( m_pData >= p_message->m_nDataBits )
        m_pData = p_message->m_nDataBits;
    }
    if ( p_message->m_nDataBits - m_pData <= 0
      || (v34 = mdlcache,
          mdlcache->BeginLock(this: mdlcache),
          this->m_pActiveChannel = this,
          v35 = CNetChan::_ProcessMessages(this, buf: p_message),
          v36 = v34->__vftable,
          HIBYTE(bHasHeader) = v35,
          v36->EndLock(this: v34),
          HIBYTE(bHasHeader) != 0) )
    {
      this->m_MessageHandler->PacketEnd(this: this->m_MessageHandler);
      if ( this->m_DemoRecorder != nullptr && !demoplayer->IsPlayingBack(this: demoplayer) )
        this->m_DemoRecorder->RecordPacket(this: this->m_DemoRecorder);
    }
    return;
  }
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 3 )
  {
    v20 = 3 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    packeta = packet->message.m_nInBufWord;
    m_pBufferEnd = p_message->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      p_message->m_nBitsAvail = 1;
      p_message->m_nInBufWord = 0;
      p_message->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        p_message->m_bOverflow = true;
        p_message->m_nInBufWord = 0;
        goto LABEL_32;
      }
      p_message->m_nInBufWord = *m_pDataIn;
    }
    p_message->m_pDataIn = m_pDataIn + 1;
LABEL_32:
    if ( p_message->m_bOverflow )
    {
      v17 = 0;
    }
    else
    {
      m_nInBufWord = p_message->m_nInBufWord;
      v24 = (m_nInBufWord & CBitBuffer::s_nMaskTable[v20]) << p_message->m_nBitsAvail;
      p_message->m_nBitsAvail = 32 - v20;
      bHasHeader = v24;
      v17 = v24 | packeta;
      p_message->m_nInBufWord = m_nInBufWord >> v20;
    }
    goto LABEL_35;
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
LABEL_35:
  v25 = 1 << v17;
  bHasHeader = 0;
  while ( 1 )
  {
    v26 = p_message->m_nInBufWord;
    v27 = v26 & 1;
    if ( p_message->m_nBitsAvail-- == 1 )
    {
      v29 = p_message->m_pDataIn;
      v30 = p_message->m_pBufferEnd;
      p_message->m_nBitsAvail = 32;
      if ( v29 == v30 )
      {
        p_message->m_nBitsAvail = 1;
        p_message->m_nInBufWord = 0;
        p_message->m_pDataIn = v29 + 1;
      }
      else if ( v29 <= v30 )
      {
        p_message->m_nInBufWord = *v29;
        p_message->m_pDataIn = v29 + 1;
      }
      else
      {
        p_message->m_bOverflow = true;
        p_message->m_nInBufWord = 0;
      }
    }
    else
    {
      p_message->m_nInBufWord = v26 >> 1;
    }
    if ( v27 != 0 && CNetChan::ReadSubChannelData(this, buf: p_message, stream: bHasHeader) == 0 )
      break;
    if ( ++bHasHeader >= 2 )
    {
      m_nInReliableState = this->m_nInReliableState;
      if ( (m_nInReliableState & v25) != 0 )
        this->m_nInReliableState = m_nInReliableState & ~v25;
      else
        this->m_nInReliableState = v25 | m_nInReliableState;
      v32 = 0;
      while ( CNetChan::CheckReceivingList(this, a2: (int)this, nList: v32) != 0 )
      {
        if ( ++v32 >= 2 )
          goto LABEL_52;
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD920
// Name: public: virtual bool CNetChan::ProcessStream(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::ProcessStream(CNetChan *this)
{
  SOCKET m_StreamSocket; // eax
  int v4; // eax
  int m_SteamType; // eax
  int v6; // eax
  int m_nBitsAvail; // esi
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *m_pDataIn; // eax
  unsigned int m_nInBufWord_high; // edx
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ebx
  int v21; // eax
  unsigned int v22; // esi
  unsigned int v23; // edx
  unsigned int v24; // esi
  CNetChan::dataFragments_s **v25; // edx
  const char *v26; // eax
  const char *v27; // eax
  int m_StreamReceived; // ecx
  int m_StreamLength; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int m_StreamSeqNr; // esi
  unsigned __int8 *m_pMemory; // [esp-14h] [ebp-274h]
  int v35; // [esp-Ch] [ebp-26Ch]
  int v36; // [esp-8h] [ebp-268h]
  int v37; // [esp-8h] [ebp-268h]
  char headerBuf[512]; // [esp+8h] [ebp-258h] BYREF
  bf_read buffer; // [esp+208h] [ebp-58h] BYREF
  unsigned int v40; // [esp+22Ch] [ebp-34h]
  unsigned int v41; // [esp+230h] [ebp-30h]
  char cmd; // [esp+237h] [ebp-29h] BYREF
  signed int m_nInBufWord; // [esp+238h] [ebp-28h]
  bf_read header; // [esp+23Ch] [ebp-24h] BYREF

  m_StreamSocket = this->m_StreamSocket;
  if ( m_StreamSocket == 0 )
    return true;
  if ( this->m_SteamType == 0 )
  {
    v4 = NET_ReceiveStream(nSock: m_StreamSocket, buf: &cmd, len: 1, flags: 0);
    if ( v4 == 0 )
      return true;
    if ( v4 == -1 )
      return false;
    this->ResetStreaming(this);
    this->m_SteamType = cmd;
  }
  header.m_bOverflow = false;
  header.m_nDataBits = -1;
  header.m_nDataBytes = 0;
  header.m_pDebugName = "inDataHeader";
  CBitRead::StartReading(this: &header, pData: headerBuf, nBytes: 512, iStartBit: 0, nBits: -1);
  m_SteamType = this->m_SteamType;
  if ( m_SteamType == 1 )
  {
    this->m_StreamActive = true;
    this->ResetStreaming(this);
    return CNetChan::SendReliableAcknowledge(this, seqnr: this->m_ChallengeNr);
  }
  if ( m_SteamType != 2 || this->m_StreamLength != 0 )
    goto LABEL_49;
  v6 = NET_ReceiveStream(nSock: this->m_StreamSocket, buf: headerBuf, len: 6, flags: 0);
  if ( v6 == 0 )
    return true;
  if ( v6 == -1 )
    return false;
  m_nBitsAvail = header.m_nBitsAvail;
  m_pBufferEnd = header.m_pBufferEnd;
  if ( header.m_nBitsAvail < 16 )
  {
    m_nInBufWord = header.m_nInBufWord;
    m_pDataIn = header.m_pDataIn;
    v11 = 16 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord_high = 0;
      m_nBitsAvail = 1;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    if ( header.m_pDataIn > header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord_high = 0;
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    m_nInBufWord_high = *header.m_pDataIn;
    m_pDataIn = header.m_pDataIn + 1;
    header.m_nInBufWord = *header.m_pDataIn++;
    if ( header.m_bOverflow )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      m_nInBufWord = 0;
      goto LABEL_31;
    }
    v41 = m_nInBufWord_high & CBitBuffer::s_nMaskTable[v11];
    m_nInBufWord |= v41 << SLOBYTE(header.m_nBitsAvail);
    m_nBitsAvail = 32 - v11;
    m_nInBufWord_high >>= v11;
    m_pBufferEnd = header.m_pBufferEnd;
    header.m_nBitsAvail = 32 - v11;
  }
  else
  {
    m_pDataIn = header.m_pDataIn;
    m_nBitsAvail = header.m_nBitsAvail - 16;
    header.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      m_nInBufWord_high = HIWORD(header.m_nInBufWord);
      m_nInBufWord = LOWORD(header.m_nInBufWord);
    }
    else
    {
      m_nBitsAvail = 32;
      header.m_nBitsAvail = 32;
      if ( header.m_pDataIn == header.m_pBufferEnd )
      {
        m_nInBufWord_high = 0;
        m_nBitsAvail = 1;
        m_pDataIn = header.m_pDataIn + 1;
        header.m_nBitsAvail = 1;
        ++header.m_pDataIn;
        m_nInBufWord = LOWORD(header.m_nInBufWord);
      }
      else
      {
        if ( header.m_pDataIn <= header.m_pBufferEnd )
        {
          m_nInBufWord_high = *header.m_pDataIn;
          m_pDataIn = ++header.m_pDataIn;
        }
        else
        {
          header.m_bOverflow = true;
          m_nInBufWord_high = 0;
        }
        m_nInBufWord = LOWORD(header.m_nInBufWord);
      }
    }
  }
  header.m_nInBufWord = m_nInBufWord_high;
LABEL_31:
  this->m_StreamLength = m_nInBufWord;
  if ( m_nBitsAvail < 32 )
  {
    v41 = m_nInBufWord_high;
    v14 = 32 - m_nBitsAvail;
    if ( m_pDataIn == m_pBufferEnd )
    {
      header.m_pDataIn = m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      header.m_bOverflow = true;
      v12 = 0;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      v15 = *m_pDataIn;
      header.m_nInBufWord = *m_pDataIn;
      header.m_pDataIn = m_pDataIn + 1;
      if ( header.m_bOverflow )
      {
        v12 = 0;
      }
      else
      {
        v16 = (v15 & CBitBuffer::s_nMaskTable[v14]) << m_nBitsAvail;
        header.m_nBitsAvail = m_nBitsAvail;
        v40 = v16;
        v12 = v16 | v41;
        header.m_nInBufWord = v15 >> v14;
      }
    }
    else
    {
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      v12 = 0;
    }
  }
  else
  {
    header.m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      header.m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        header.m_pDataIn = m_pDataIn + 1;
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        v12 = m_nInBufWord_high;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v13 = *m_pDataIn;
          header.m_pDataIn = m_pDataIn + 1;
          header.m_nInBufWord = v13;
        }
        else
        {
          header.m_bOverflow = true;
          header.m_nInBufWord = 0;
        }
        v12 = m_nInBufWord_high;
      }
    }
    else
    {
      header.m_nInBufWord = 0;
      v12 = m_nInBufWord_high;
    }
  }
  this->m_StreamSeqNr = v12;
  if ( m_nInBufWord > 96000 )
  {
    ConMsg(a1: "ERROR! Stream indata too big (%i)", m_nInBufWord);
    return false;
  }
LABEL_49:
  v17 = this->m_SteamType;
  if ( v17 == 3 && this->m_SteamFile[0] == 0 )
    return false;
  if ( v17 != 4 || this->m_StreamSeqNr != 0 )
  {
    m_StreamReceived = this->m_StreamReceived;
    m_StreamLength = this->m_StreamLength;
    if ( m_StreamReceived >= m_StreamLength )
      return true;
    v30 = NET_ReceiveStream(
            nSock: this->m_StreamSocket,
            buf: (char *)&this->m_StreamData.m_pMemory[m_StreamReceived],
            len: m_StreamLength - m_StreamReceived,
            flags: 0);
    if ( v30 == 0 )
      return true;
    if ( v30 != -1 )
    {
      this->m_StreamReceived += v30;
      v31 = this->m_StreamReceived;
      v32 = this->m_StreamLength;
      if ( v31 > v32 )
      {
        ConMsg(a1: "ERROR! Stream indata oversize.");
        return false;
      }
      if ( v31 == v32 )
      {
        m_StreamSeqNr = this->m_StreamSeqNr;
        m_pMemory = this->m_StreamData.m_pMemory;
        buffer.m_bOverflow = false;
        buffer.m_pDebugName = nullptr;
        buffer.m_nDataBits = -1;
        buffer.m_nDataBytes = 0;
        CBitRead::StartReading(this: &buffer, pData: m_pMemory, nBytes: v32, iStartBit: 0, nBits: -1);
        CNetChan::ProcessMessages(this, buf: &buffer);
        this->ResetStreaming(this);
        return CNetChan::SendReliableAcknowledge(this, seqnr: m_StreamSeqNr);
      }
      return true;
    }
    return false;
  }
  v18 = NET_ReceiveStream(nSock: this->m_StreamSocket, buf: headerBuf, len: 4, flags: 0);
  if ( v18 == 0 )
    return true;
  if ( v18 == -1 )
    return false;
  if ( header.m_nBitsAvail < 32 )
  {
    v20 = header.m_nInBufWord;
    v21 = 32 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      v19 = 0;
    }
    else if ( header.m_pDataIn <= header.m_pBufferEnd )
    {
      v22 = *header.m_pDataIn;
      header.m_nInBufWord = *header.m_pDataIn++;
      if ( header.m_bOverflow )
      {
        v19 = 0;
      }
      else
      {
        v23 = (v22 & CBitBuffer::s_nMaskTable[v21]) << SLOBYTE(header.m_nBitsAvail);
        v24 = v22 >> v21;
        v19 = v23 | v20;
        header.m_nInBufWord = v24;
      }
    }
    else
    {
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      v19 = 0;
    }
  }
  else
  {
    v19 = header.m_nInBufWord;
    header.m_nBitsAvail -= 32;
    if ( header.m_nBitsAvail != 0 )
    {
      header.m_nInBufWord = 0;
    }
    else
    {
      header.m_nBitsAvail = 32;
      if ( header.m_pDataIn == header.m_pBufferEnd )
      {
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        ++header.m_pDataIn;
      }
      else if ( header.m_pDataIn <= header.m_pBufferEnd )
      {
        header.m_nInBufWord = *header.m_pDataIn++;
      }
      else
      {
        header.m_bOverflow = true;
        header.m_nInBufWord = 0;
      }
    }
  }
  v25 = this->m_WaitingList[0].m_Memory.m_pMemory;
  this->m_StreamSeqNr = v19;
  if ( (*v25)->transferID != v19 )
  {
    v37 = v19;
    v35 = this->m_StreamLength;
    v27 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP <- %s: invalid ACKN streamlen %d seqnr %i\n", v27, v35, v37);
    this->ResetStreaming(this);
    return true;
  }
  if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
  {
    v36 = v19;
    v26 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "TCP <- %s: ACKN seq=%i\n", v26, v36);
  }
  CNetChan::RemoveHeadInWaitingList(this, nList: nullptr);
  this->ResetStreaming(this);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101ADEA0
// Name: private: void CNetChan::MergeSplitUserBuffers(enum CNetChan::EBufType,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::MergeSplitUserBuffers(CNetChan *this, CNetChan::EBufType eBufType, bf_write *outbuf)
{
  unsigned __int16 Inorder; // di
  UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short> *m_pMemory; // ecx
  int *p_m_nSlot; // edx
  INetChannel *m_pChannel; // eax
  bf_write *v8; // esi
  NET_SplitScreenUser v9; // [esp+8h] [ebp-18h] BYREF
  int nCurrentSlot; // [esp+1Ch] [ebp-4h]

  nCurrentSlot = 0;
  Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SplitPlayers);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = this->m_SplitPlayers.m_Elements.m_pMemory;
      p_m_nSlot = &m_pMemory[Inorder].m_Data.m_nSlot;
      m_pChannel = m_pMemory[Inorder].m_Data.m_pChannel;
      if ( m_pChannel != nullptr )
        break;
LABEL_13:
      Inorder = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_SplitPlayers,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
      {
        if ( nCurrentSlot != 0 )
        {
          NET_SplitScreenUser::NET_SplitScreenUser(this: &v9, slot: 0);
          NET_SplitScreenUser::WriteToBuffer(this: &v9, buffer: outbuf);
        }
        return;
      }
    }
    if ( eBufType != BUF_RELIABLE )
    {
      if ( eBufType == BUF_UNRELIABLE )
      {
        v8 = (bf_write *)&m_pChannel[17];
        goto LABEL_9;
      }
      if ( eBufType == BUF_VOICE )
      {
        v8 = (bf_write *)&m_pChannel[26];
        goto LABEL_9;
      }
    }
    v8 = (bf_write *)&m_pChannel[8];
LABEL_9:
    if ( v8->m_iCurBit > 0 )
    {
      if ( *p_m_nSlot != nCurrentSlot )
      {
        nCurrentSlot = *p_m_nSlot;
        NET_SplitScreenUser::NET_SplitScreenUser(this: &v9, slot: nCurrentSlot);
        NET_SplitScreenUser::WriteToBuffer(this: &v9, buffer: outbuf);
      }
      bf_write::WriteBits(this: outbuf, pInData: v8->m_pData, nBits: v8->m_iCurBit);
      bf_write::Reset(this: v8);
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE240
// Name: private: bool CNetChan::CreateFragmentsFromBuffer(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::CreateFragmentsFromBuffer(CNetChan *this, bf_write *buffer, int stream)
{
  CUtlMemory<S3RGBA,int> *v4; // ebx
  int m_pMemory; // eax
  void *v6; // esi
  signed int v7; // eax
  int v8; // edi
  void *v9; // ebx
  int v10; // edi
  void *v11; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *v13; // edi
  S3RGBA *v14; // ebx
  S3RGBA *v15; // ecx
  int v16; // eax
  S3RGBA *v17; // ebx
  CNetChan *v18; // ecx
  unsigned int v19; // eax
  bool v20; // al
  unsigned int v21; // edx
  int v23; // [esp-8h] [ebp-30h]
  bf_write bfwrite; // [esp+Ch] [ebp-1Ch] BYREF
  CNetChan *v25; // [esp+24h] [ebp-4h]

  v25 = this;
  bf_write::bf_write(this: &bfwrite);
  v4 = (CUtlMemory<S3RGBA,int> *)((char *)this + 20 * stream);
  m_pMemory = (int)v4[17].m_pMemory;
  if ( m_pMemory > 1
    && (v6 = (void *)v4[16].m_pMemory[m_pMemory - 1],
        v7 = ((unsigned int)(buffer->m_iCurBit + *((_DWORD *)v6 + 68) + 7) >> 3) + 3,
        (v8 = 4 * (v7 / 4)) < 96000)
    && *((_DWORD *)v6 + 66) != 0 )
  {
    v9 = MemAlloc_Alloc(nSize: 4 * (v7 / 4));
    _V_memcpy(dest: v9, src: *((const void **)v6 + 66), count: *((_DWORD *)v6 + 67));
    free(pMem: *((void **)v6 + 66));
    v23 = *((_DWORD *)v6 + 68);
    *((_DWORD *)v6 + 66) = v9;
    bf_write::StartWriting(this: &bfwrite, pData: v9, nBytes: v8, iStartBit: v23, nBits: -1);
  }
  else
  {
    v10 = 4 * ((((buffer->m_iCurBit + 7) >> 3) + 3) / 4);
    v6 = MemAlloc_Alloc(nSize: 0x130u);
    *((_DWORD *)v6 + 67) = 0;
    *((_DWORD *)v6 + 68) = 0;
    v11 = MemAlloc_Alloc(nSize: v10);
    *((_DWORD *)v6 + 66) = v11;
    *((_BYTE *)v6 + 280) = 0;
    *((_BYTE *)v6 + 289) = 0;
    *((_DWORD *)v6 + 71) = 0;
    *(_DWORD *)v6 = 0;
    *((_BYTE *)v6 + 4) = 0;
    bf_write::StartWriting(this: &bfwrite, pData: v11, nBytes: v10, iStartBit: 0, nBits: -1);
    m_nAllocationCount = v4[16].m_nAllocationCount;
    v13 = v4 + 16;
    v14 = v4[17].m_pMemory;
    if ( (int)&v14->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: v13, num: (int)(&v14->g - m_nAllocationCount));
    ++v13[1].m_pMemory;
    v15 = v13->m_pMemory;
    v16 = (char *)v13[1].m_pMemory - (char *)v14 - 1;
    v13[1].m_nAllocationCount = (int)v13->m_pMemory;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[(_DWORD)v14 + 1], src: &v15[(_DWORD)v14], count: 4 * v16);
    v17 = &v13->m_pMemory[(_DWORD)v14];
    if ( v17 != nullptr )
      *v17 = (S3RGBA)v6;
  }
  bf_write::WriteBits(this: &bfwrite, pInData: buffer->m_pData, nBits: buffer->m_iCurBit);
  if ( (unsigned int)(bfwrite.m_iCurBit % 8 - 1) <= 1 )
    bf_write::WriteUBitLong(this: &bfwrite, curData: 0, numbits: 6, bCheckRange: true);
  *((_DWORD *)v6 + 68) += buffer->m_iCurBit;
  v18 = v25;
  v19 = (unsigned int)(*((_DWORD *)v6 + 68) + 7) >> 3;
  *((_DWORD *)v6 + 67) = v19;
  v20 = v18->m_StreamActive && v19 > v18->m_MaxReliablePayloadSize;
  v21 = *((_DWORD *)v6 + 67) + 255;
  *((_BYTE *)v6 + 288) = v20;
  *((_DWORD *)v6 + 74) = 0;
  *((_DWORD *)v6 + 75) = 0;
  *((_DWORD *)v6 + 73) = v21 >> 8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AE470
// Name: private: bool CNetChan::CreateFragmentsFromFile(char const __near *,int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::CreateFragmentsFromFile(
        CNetChan *this,
        const char *filename,
        int stream,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  int v6; // ebx
  int m_nValue; // ecx
  int v8; // eax
  CNetChan::dataFragments_s *v9; // esi
  void *v10; // eax
  int m_Size; // ebx
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *v12; // edi
  int m_nAllocationCount; // eax
  CNetChan::dataFragments_s **m_pMemory; // ecx
  int v15; // eax
  CNetChan::dataFragments_s **v16; // ebx
  unsigned int v17; // ecx

  if ( CNetChan::IsFileInWaitingList(this, filename) != 0 )
    return 1;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "GAME") )
  {
    v6 = g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "GAME");
    if ( net_maxfilesize.m_pParent != nullptr )
      m_nValue = net_maxfilesize.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( v6 < m_nValue << 20 )
    {
      if ( v6 < 0x3FFFFFF )
      {
        v9 = (CNetChan::dataFragments_s *)MemAlloc_Alloc(nSize: 0x130u);
        v9->bytes = v6;
        v9->bits = 8 * v6;
        v9->isReplayDemo = bIsReplayDemoFile;
        v9->buffer = nullptr;
        v9->isCompressed = false;
        v9->nUncompressedSize = 0;
        v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "rb", a4: "GAME");
        v9->file = v10;
        if ( v10 != nullptr )
        {
          v9->transferID = transferID;
          V_strncpy(pDest: v9->filename, pSrc: filename, maxLen: 260);
          m_Size = this->m_WaitingList[stream].m_Size;
          v12 = &this->m_WaitingList[stream];
          m_nAllocationCount = this->m_WaitingList[stream].m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_WaitingList[stream],
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_WaitingList[stream].m_Size;
          m_pMemory = v12->m_Memory.m_pMemory;
          v15 = this->m_WaitingList[stream].m_Size - m_Size - 1;
          this->m_WaitingList[stream].m_pElements = this->m_WaitingList[stream].m_Memory.m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v16 = &v12->m_Memory.m_pMemory[m_Size];
          if ( v16 != nullptr )
            *v16 = v9;
          v17 = (v9->bytes + 255) >> 8;
          v9->asTCP = false;
          v9->ackedFragments = 0;
          v9->pendingFragments = 0;
          v9->numFragments = v17;
          return 1;
        }
        else
        {
          ConMsg(a1: "CreateFragmentsFromFile: couldn't open '%s'.\n", filename);
          free(pMem: v9);
          return 0;
        }
      }
      else
      {
        ConMsg(a1: "CreateFragmentsFromFile: '%s' too big (max %i bytes).\n", filename, 0x3FFFFFF);
        return 0;
      }
    }
    else
    {
      if ( net_maxfilesize.m_pParent != nullptr )
        v8 = net_maxfilesize.m_pParent->m_Value.m_nValue;
      else
        v8 = 0;
      ConMsg(a1: "CreateFragmentsFromFile: '%s' size exceeds net_maxfilesize limit (%i MB).\n", filename, v8);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "CreateFragmentsFromFile: '%s' doesn't exist.\n", filename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE680
// Name: public: virtual int CNetChan::SendDatagram(class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetChan::SendDatagram(CNetChan *this, float datagram)
{
  int v3; // edi
  int m_nValue; // eax
  const char *v6; // eax
  int m_nChokedPackets; // eax
  int v8; // ecx
  int m_iCurBit; // eax
  int v10; // edi
  int i; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // eax
  char v16; // bl
  int v17; // eax
  unsigned __int16 v18; // ax
  bf_write *p_m_StreamVoice; // ecx
  int v20; // edi
  int v21; // eax
  unsigned __int64 v22; // rax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  bf_write *v27; // edi
  long double v28; // st7
  long double v29; // st6
  long double v30; // st7
  int v31; // eax
  int v32; // [esp+0h] [ebp-17830h]
  int m_nInSequenceNr; // [esp+4h] [ebp-1782Ch]
  const char *v34; // [esp+8h] [ebp-17828h]
  __int64 v35; // [esp+8h] [ebp-17828h]
  unsigned __int64 v36; // [esp+Ch] [ebp-17824h]
  __int64 v37; // [esp+Ch] [ebp-17824h]
  const char *v38; // [esp+10h] [ebp-17820h]
  int m_nOutSequenceNr; // [esp+14h] [ebp-1781Ch]
  unsigned int m_nInReliableState; // [esp+14h] [ebp-1781Ch]
  _BYTE pData[96016]; // [esp+20h] [ebp-17810h] BYREF
  char v42[128]; // [esp+17730h] [ebp-100h] BYREF
  char pDest[64]; // [esp+177B0h] [ebp-80h] BYREF
  bf_write v44; // [esp+177F0h] [ebp-40h] BYREF
  int v45; // [esp+17808h] [ebp-28h]
  bool bUseCompression[4]; // [esp+1780Ch] [ebp-24h]
  int v47; // [esp+17810h] [ebp-20h]
  bf_write buf; // [esp+17814h] [ebp-1Ch] BYREF
  unsigned __int8 v49; // [esp+1782Fh] [ebp-1h]

  if ( this->m_Socket == 0 )
  {
    v3 = net_maxroutable.m_pParent != nullptr ? net_maxroutable.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != this->GetMaxRoutablePayloadSize(this) )
    {
      if ( net_maxroutable.m_pParent != nullptr )
        m_nValue = net_maxroutable.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      this->SetMaxRoutablePayloadSize(this, a2: m_nValue);
    }
  }
  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL )
  {
    this->m_fClearTime = 0.0;
    this->m_nChokedPackets = 0;
    bf_write::Reset(this: &this->m_StreamReliable);
    bf_write::Reset(this: &this->m_StreamUnreliable);
    return this->m_nOutSequenceNr++;
  }
  if ( this->m_SplitPlayers.m_NumElements != 0 )
  {
    CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_RELIABLE, outbuf: &this->m_StreamReliable);
    CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_UNRELIABLE, outbuf: &this->m_StreamUnreliable);
    CNetChan::MergeSplitUserBuffers(this, eBufType: BUF_VOICE, outbuf: &this->m_StreamVoice);
  }
  if ( this->m_StreamReliable.m_bOverflow )
  {
    v6 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
    ConMsg(a1: "%s:send reliable stream overflow\n", v6);
    return 0;
  }
  if ( this->m_StreamReliable.m_iCurBit > 0 )
  {
    CNetChan::CreateFragmentsFromBuffer(this, buffer: &this->m_StreamReliable, stream: 0);
    bf_write::Reset(this: &this->m_StreamReliable);
  }
  bf_write::bf_write(this: &buf, pDebugName: "CNetChan_TransmitBits->send", pData, nBytes: 96016, nBits: -1);
  m_nOutSequenceNr = this->m_nOutSequenceNr;
  v49 = 0;
  bf_write::WriteLong(this: &buf, val: m_nOutSequenceNr);
  bf_write::WriteLong(this: &buf, val: this->m_nInSequenceNr);
  v44 = buf;
  bf_write::WriteByte(this: &buf, val: 0);
  if ( NET_IsMultiplayer() )
    bf_write::WriteShort(this: &buf, val: 0);
  m_nInReliableState = this->m_nInReliableState;
  v47 = (buf.m_iCurBit + 7) >> 3;
  bf_write::WriteByte(this: &buf, val: m_nInReliableState);
  m_nChokedPackets = this->m_nChokedPackets;
  if ( m_nChokedPackets > 0 )
  {
    v49 = 16;
    bf_write::WriteByte(this: &buf, val: (unsigned __int8)m_nChokedPackets);
  }
  if ( CNetChan::SendSubChannelData(this, &buf) != 0 )
    v49 |= 1u;
  if ( datagram != 0.0 )
  {
    v8 = *(_DWORD *)(LODWORD(datagram) + 12);
    if ( v8 >= buf.m_nDataBits - buf.m_iCurBit )
      _ConDMsg(a1: "CNetChan::SendDatagram:  data would overfow, ignoring\n");
    else
      bf_write::WriteBits(this: &buf, pInData: *(const void **)LODWORD(datagram), nBits: v8);
  }
  if ( this->m_StreamUnreliable.m_iCurBit >= buf.m_nDataBits - buf.m_iCurBit )
    _ConDMsg(a1: "CNetChan::SendDatagram:  Unreliable would overfow, ignoring\n");
  else
    bf_write::WriteBits(
      this: &buf,
      pInData: this->m_StreamUnreliable.m_pData,
      nBits: this->m_StreamUnreliable.m_iCurBit);
  bf_write::Reset(this: &this->m_StreamUnreliable);
  if ( !NET_IsDedicatedForXbox() )
  {
    m_iCurBit = this->m_StreamVoice.m_iCurBit;
    if ( m_iCurBit > 0 && m_iCurBit < buf.m_nDataBits - buf.m_iCurBit )
    {
      bf_write::WriteBits(this: &buf, pInData: this->m_StreamVoice.m_pData, nBits: this->m_StreamVoice.m_iCurBit);
      bf_write::Reset(this: &this->m_StreamVoice);
    }
  }
  v10 = 16;
  if ( this->m_Socket == 1 )
  {
    if ( net_minroutable.m_pParent != nullptr )
      v10 = net_minroutable.m_pParent->m_Value.m_nValue;
    else
      v10 = 0;
  }
  for ( i = buf.m_iCurBit; (buf.m_iCurBit + 7) >> 3 < v10; i = buf.m_iCurBit )
    bf_write::WriteUBitLong(this: &buf, curData: 0, numbits: 6, bCheckRange: true);
  if ( (unsigned int)(i % 8 - 1) <= 1 )
    bf_write::WriteUBitLong(this: &buf, curData: 0, numbits: 6, bCheckRange: true);
  v12 = buf.m_iCurBit % 8;
  if ( buf.m_iCurBit % 8 > 0 )
  {
    v49 |= 32 * (8 - v12);
    if ( 8 - v12 > 0 )
      bf_write::WriteUBitLong(
        this: &buf,
        curData: `GetBitForBitnum'::`2'::bitsForBitnum[(8 - v12) & 0x1F] - 1,
        numbits: 8 - v12,
        bCheckRange: true);
  }
  if ( net_blocksize.m_pParent != nullptr )
    v13 = net_blocksize.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  v14 = 8 * v13;
  if ( NET_IsDedicatedForXbox() )
  {
    v15 = this->m_StreamVoice.m_iCurBit;
    if ( v15 > 0 && buf.m_iCurBit + v15 < v14 )
    {
      v16 = 1;
LABEL_54:
      HIBYTE(datagram) = 1;
      goto LABEL_55;
    }
  }
  v16 = 0;
  HIBYTE(datagram) = 0;
  if ( this->m_StreamVoice.m_iCurBit >= v14 )
    goto LABEL_54;
LABEL_55:
  bUseCompression[0] = false;
  if ( net_compresspackets.m_pParent != nullptr && net_compresspackets.m_pParent->m_Value.m_nValue != 0 )
  {
    v17 = net_compresspackets_minsize.m_pParent != nullptr ? net_compresspackets_minsize.m_pParent->m_Value.m_nValue : 0;
    if ( (buf.m_iCurBit + 7) >> 3 >= v17 )
      bUseCompression[0] = true;
  }
  v45 = v49;
  bf_write::WriteByte(this: &v44, val: v49);
  if ( NET_IsMultiplayer() )
  {
    v18 = BufferToShortChecksum(pvData: &buf.m_pData[v47], nLength: ((buf.m_iCurBit + 7) >> 3) - v47);
    bf_write::WriteUBitLong(this: &v44, curData: v18, numbits: 16, bCheckRange: true);
  }
  if ( v16 != 0 )
    p_m_StreamVoice = &this->m_StreamVoice;
  else
    p_m_StreamVoice = nullptr;
  v20 = NET_SendPacket(
          chan: this,
          sock: this->m_Socket,
          to: &this->remote_address,
          data: buf.m_pData,
          length: (buf.m_iCurBit + 7) >> 3,
          pVoicePayload: p_m_StreamVoice,
          bUseCompression: bUseCompression[0],
          unMillisecondsDelay: 0);
  v47 = v20;
  if ( HIBYTE(datagram) != 0 || !NET_IsDedicatedForXbox() )
    bf_write::Reset(this: &this->m_StreamVoice);
  if ( net_showudp.m_pParent != nullptr )
  {
    v21 = net_showudp.m_pParent->m_Value.m_nValue;
    if ( v21 != 0
      && v21 != 2
      && (net_showudp_remoteonly.m_pParent == nullptr
       || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
       || !netadr_s::IsLocalhost(this: &this->remote_address) && !netadr_s::IsLoopback(this: &this->remote_address)) )
    {
      memset(pDest, 0, sizeof(pDest));
      if ( net_compresspackets.m_pParent != nullptr && net_compresspackets.m_pParent->m_Value.m_nValue != 0 && v20 != 0 )
      {
        LODWORD(datagram) = (buf.m_iCurBit + 7) >> 3;
        if ( v20 < SLODWORD(datagram) )
          V_snprintf(
            pDest,
            maxLen: 64,
            pFormat: " compression=%5u [%5.2f %%]",
            v20,
            (double)v47 * 100.0 / (double)SLODWORD(datagram));
      }
      v22 = g_pSteamSocketMgr->GetSteamIDForRemote(this: g_pSteamSocketMgr, a2: &this->remote_address);
      datagram = NAN;
      if ( v22 != 0 )
      {
        datagram = -3.0439319e38;
        v36 = v22;
        v23 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v24 = (const char *)((int (__thiscall *)(CNetChan *, const char *, _DWORD, _DWORD))this->GetName)(
                              a1: this,
                              a2: v23,
                              a3: v36,
                              a4: HIDWORD(v36));
        V_snprintf(pDest: v42, maxLen: 128, pFormat: "%12.12s %21.21s s(%llx)", v24, v34, v37);
      }
      else
      {
        v25 = netadr_s::ToString(this: &this->remote_address, baseOnly: false);
        v26 = (const char *)((int (__thiscall *)(CNetChan *, const char *))this->GetName)(a1: this, a2: v25);
        V_snprintf(pDest: v42, maxLen: 128, pFormat: "%12.12s %21.21s", v26, v38);
      }
      ConColorMsg(
        a1: (const struct Color *)&datagram,
        a2: "UDP -> %s: sz=%5i seq=%5i ack=%5i rel=%1i tm=%8.3f%s\n",
        v42,
        (buf.m_iCurBit + 7) >> 3,
        this->m_nOutSequenceNr & 0x3F,
        this->m_nInSequenceNr & 0x3F,
        v45 & 1,
        (double)net_time,
        pDest);
    }
  }
  v27 = (bf_write *)(v20 + 28);
  v35 = (unsigned int)this->m_nChokedPackets;
  m_nInSequenceNr = this->m_nInSequenceNr;
  v32 = this->m_nOutSequenceNr;
  datagram = *(float *)&v27;
  CNetChan::FlowNewPacket(
    this,
    flow: 0,
    seqnr: v32,
    acknr: m_nInSequenceNr,
    nChoked: v35,
    nDropped: SHIDWORD(v35),
    nSize: (int)v27);
  CNetChan::FlowUpdate(this, flow: 0, addbytes: (int)v27);
  if ( net_time > this->m_fClearTime )
    this->m_fClearTime = net_time;
  v28 = (double)SLODWORD(datagram) / (double)this->m_Rate + this->m_fClearTime;
  this->m_fClearTime = v28;
  datagram = net_maxcleartime.m_pParent->m_Value.m_fValue;
  if ( datagram > 0.0 )
  {
    v29 = v28;
    v30 = datagram + net_time;
    if ( v29 > v30 )
      this->m_fClearTime = v30;
  }
  v31 = ++this->m_nOutSequenceNr;
  this->m_nChokedPackets = 0;
  return v31 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AECB0
// Name: public: virtual bool CNetChan::RegisterMessage(class INetMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetChan::RegisterMessage(CNetChan *this, INetMessage *msg)
{
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  INetMessage **m_pMemory; // ecx
  int v8; // eax
  INetMessage **v9; // eax

  v3 = msg->GetType(this: msg);
  if ( CNetChan::FindMessage(this, type: v3) != nullptr )
    return 0;
  m_nAllocationCount = this->m_NetMessages.m_Memory.m_nAllocationCount;
  m_Size = this->m_NetMessages.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_NetMessages,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_NetMessages.m_Size;
  m_pMemory = this->m_NetMessages.m_Memory.m_pMemory;
  v8 = this->m_NetMessages.m_Size - m_Size - 1;
  this->m_NetMessages.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_NetMessages.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = msg;
  msg->SetNetChannel(this: msg, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AEE30
// Name: public: virtual bool CNetChan::SendFile(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetChan::SendFile(CNetChan *this, char *filename, unsigned int transferID, BOOL bIsReplayDemoFile)
{
  bool result; // al

  if ( CCircularBuffer::GetReadAvailable(this: &this->remote_address) == NA_NULL )
    return true;
  result = CNetChan::IsValidFileTransferExtension(pFilename: filename);
  if ( result )
  {
    if ( CNetChan::CreateFragmentsFromFile(this, filename, stream: 1, transferID, bIsReplayDemoFile) != 0 )
    {
      if ( net_showfragments.m_pParent != nullptr && net_showfragments.m_pParent->m_Value.m_nValue == 2 )
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
// Address: 0x101AEEC0
// Name: public: CNetChan::CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetChan::CNetChan(CNetChan *this)
{
  CUtlVector<CNetChan::dataFragments_s *,CUtlMemory<CNetChan::dataFragments_s *,int> > *m_WaitingList; // eax
  int i; // ecx

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
  this->m_StreamData.m_pMemory = nullptr;
  this->m_StreamData.m_nAllocationCount = 0;
  this->m_StreamData.m_nGrowSize = 0;
  this->m_NetMessages.m_Memory.m_pMemory = nullptr;
  this->m_NetMessages.m_Memory.m_nAllocationCount = 0;
  this->m_NetMessages.m_Memory.m_nGrowSize = 0;
  this->m_NetMessages.m_Size = 0;
  this->m_NetMessages.m_pElements = nullptr;
  this->m_SplitPlayers.m_LessFunc = (bool (__cdecl *)(const CNetChan::SplitPlayer_t *, const CNetChan::SplitPlayer_t *))CIPRateLimit::LessIP;
  this->m_SplitPlayers.m_Elements.m_pMemory = nullptr;
  this->m_SplitPlayers.m_Elements.m_nAllocationCount = 0;
  this->m_SplitPlayers.m_Elements.m_nGrowSize = 0;
  this->m_SplitPlayers.m_pElements = this->m_SplitPlayers.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_SplitPlayers.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_SplitPlayers.m_FirstFree = -1;
  this->m_pActiveChannel = this;
  this->m_nSplitPacketSequence = 1;
  this->m_nMaxRoutablePayloadSize = 1200;
  *(_WORD *)&this->m_bProcessingMessages = 0;
  this->m_bStopProcessing = false;
  this->m_Socket = -1;
  netadr_s::Clear(this: &this->remote_address);
  this->connect_time = 0.0;
  this->last_received = 0.0;
  V_strncpy(pDest: this->m_Name, pSrc: defaultValue, maxLen: 32);
  this->m_MessageHandler = nullptr;
  this->m_DemoRecorder = nullptr;
  CNetworkStringTable::SetTick(this: &this->m_StreamUnreliable, pDebugName: "netchan_t::unreliabledata");
  CNetworkStringTable::SetTick(this: &this->m_StreamReliable, pDebugName: "netchan_t::reliabledata");
  this->m_Timeout = 300.0;
  this->m_Rate = 10000;
  this->m_nOutSequenceNr = 1;
  this->m_nInSequenceNr = 0;
  this->m_nOutSequenceNrAck = 0;
  this->m_nOutReliableState = 0;
  this->m_nInReliableState = 0;
  this->m_ChallengeNr = 0;
  this->m_StreamSocket = 0;
  this->m_StreamActive = false;
  this->m_SteamType = 0;
  this->m_StreamLength = 0;
  this->m_StreamReceived = 0;
  this->m_StreamSeqNr = 0;
  this->m_SteamFile[0] = 0;
  this->m_MaxReliablePayloadSize = 96000;
  this->m_FileRequestCounter = 0;
  *(_WORD *)&this->m_bFileBackgroundTranmission = 1;
  this->m_nQueuedPackets = 0;
  this->m_flRemoteFrameTime = 0.0;
  this->m_flRemoteFrameTimeStdDeviation = 0.0;
  _V_memset(dest: this->m_DataFlow, fill: 0, count: 15448);
  _V_memset(dest: this->m_MsgStats, fill: 0, count: 60);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101AF100
// Name: public: virtual CNetChan::~CNetChan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::~CNetChan(CNetChan *this)
{
  CNetChan::dataFragments_s *m_ReceiveList; // esi
  void *file; // eax
  int i; // [esp+8h] [ebp-4h]

  this->__vftable = (CNetChan_vtbl *)&CNetChan::`vftable';
  CNetChan::Shutdown(this, a2: (int)this, pReason: "NetChannel removed.");
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::~CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>(this: &this->m_SplitPlayers);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_NetMessages);
  if ( this->m_StreamData.m_nGrowSize >= 0 )
  {
    if ( this->m_StreamData.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StreamData.m_pMemory);
      this->m_StreamData.m_pMemory = nullptr;
    }
    this->m_StreamData.m_nAllocationCount = 0;
  }
  m_ReceiveList = this->m_ReceiveList;
  for ( i = 1; i >= 0; --i )
  {
    m_ReceiveList = (CNetChan::dataFragments_s *)((char *)m_ReceiveList - 20);
    *(_DWORD *)&m_ReceiveList->filename[8] = 0;
    if ( *(int *)&m_ReceiveList->filename[4] >= 0 )
    {
      if ( m_ReceiveList->file != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ReceiveList->file);
        m_ReceiveList->file = nullptr;
      }
      *(_DWORD *)m_ReceiveList->filename = 0;
    }
    file = m_ReceiveList->file;
    *(_DWORD *)&m_ReceiveList->filename[12] = m_ReceiveList->file;
    if ( *(int *)&m_ReceiveList->filename[4] >= 0 )
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
// Address: 0x101AF240
// Name: public: virtual void CNetChan::AttachSplitPlayer(int,class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::AttachSplitPlayer(CNetChan *this, int nSplitPlayerSlot, INetChannel *pChannel)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  CNetChan::SplitPlayer_t search; // [esp+4h] [ebp-8h] BYREF

  search.m_nSlot = nSplitPlayerSlot;
  p_m_SplitPlayers = &this->m_SplitPlayers;
  search.m_pChannel = pChannel;
  if ( CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         &search) == 0xFFFF )
    CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Insert(
      this: p_m_SplitPlayers,
      insert: &search);
}

//------------------------------------------------------------------------------
// Address: 0x101AF280
// Name: public: virtual void CNetChan::DetachSplitPlayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetChan::DetachSplitPlayer(CNetChan *this, int nSplitPlayerSlot)
{
  CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl*)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> > *p_m_SplitPlayers; // esi
  unsigned __int16 v3; // ax
  int v4; // edi
  int v5; // eax
  CNetChan::SplitPlayer_t search; // [esp+8h] [ebp-8h] BYREF

  p_m_SplitPlayers = &this->m_SplitPlayers;
  search.m_pChannel = nullptr;
  search.m_nSlot = nSplitPlayerSlot;
  v3 = CUtlRBTree<CNetChan::SplitPlayer_t,unsigned short,bool (__cdecl *)(CNetChan::SplitPlayer_t const &,CNetChan::SplitPlayer_t const &),CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_SplitPlayers,
         &search);
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

} // namespace engine_xlsp
