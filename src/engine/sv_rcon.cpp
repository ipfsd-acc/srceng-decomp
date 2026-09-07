// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_rcon.cpp
// Functions: 21
// ============================================================

#include "engine\sv_rcon.h"

//------------------------------------------------------------------------------
// Address: 0x1005E360
// Name: public: void CUtlMemory<struct CRConServer::FailedRCon_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRConServer::FailedRCon_t,int>::Grow(CUtlMemory<Remote_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Remote_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Remote_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Remote_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B5C0
// Name: class CRConServer __near & RCONServer(void)
// Source: json
//------------------------------------------------------------------------------
CRConServer *__cdecl RCONServer()
{
  return &g_RCONServer;
}

//------------------------------------------------------------------------------
// Address: 0x1012B5D0
// Name: class CRConServer __near & RPTServer(void)
// Source: json
//------------------------------------------------------------------------------
CRPTServer *__cdecl RPTServer()
{
  return &g_RPTServer;
}

//------------------------------------------------------------------------------
// Address: 0x1012B5E0
// Name: public: bool CRConServer::ConnectToListeningClient(struct netadr_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::ConnectToListeningClient(CRConServer *this, netadr_s *adr, bool bSingleSocket)
{
  int Channel; // esi
  const char *v4; // eax

  if ( CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: adr, bSingleSocket) >= 0 )
    return 1;
  Channel = _LoggingSystem_FindChannel(a1: "Console");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: Channel, a2: 1) != 0 )
  {
    v4 = netadr_s::ToString(this: adr, baseOnly: false);
    _LoggingSystem_Log(a1: Channel, a2: 1, a3: "Unable to connect to remote client (%s)\n", v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B640
// Name: public: void CRConServer::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetPassword(CRConServer *this, const char *pPassword)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  CUtlString::operator=(this: &this->m_Password, src: pPassword);
}

//------------------------------------------------------------------------------
// Address: 0x1012B660
// Name: public: bool CRConServer::HasPassword(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRConServer::HasPassword(CRConServer *this)
{
  return CUtlString::Length(this: &this->m_Password) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B670
// Name: public: bool CRConServer::IsPassword(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConServer::IsPassword(CRConServer *this, const char *pPassword)
{
  CUtlString *p_m_Password; // esi
  const char *v4; // eax

  p_m_Password = &this->m_Password;
  if ( CUtlString::Length(this: &this->m_Password) == 0 )
    return false;
  v4 = CUtlString::operator char const *(this: p_m_Password);
  return _V_strcmp(s1: pPassword, s2: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B6B0
// Name: public: void CRConServer::SetAddress(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetAddress(CRConServer *this, const char *pNetAddress)
{
  netadr_s *p_m_Address; // esi

  p_m_Address = &this->m_Address;
  NET_StringToAdr(s: pNetAddress, a: &this->m_Address);
  if ( netadr_s::GetPort(this: p_m_Address) == 0 )
    netadr_s::SetPort(this: p_m_Address, newport: 0x6987u);
}

//------------------------------------------------------------------------------
// Address: 0x1012B6F0
// Name: public: bool CRConServer::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConServer::CreateSocket(CRConServer *this)
{
  return CSocketCreator::CreateListenSocket(
           this: &this->m_Socket,
           netAdr: &this->m_Address,
           bListenOnAllInterfaces: false);
}

//------------------------------------------------------------------------------
// Address: 0x1012B710
// Name: public: void CRConServer::SetRequestID(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetRequestID(CRConServer *this, unsigned int listener, int iRequestID)
{
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // ebx
  int i; // esi
  _DWORD *AcceptedSocketData; // eax

  p_m_Socket = &this->m_Socket;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket);
  for ( i = 0; i < SamplePosition; ++i )
  {
    AcceptedSocketData = CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: i);
    if ( AcceptedSocketData[2] == listener )
      AcceptedSocketData[1] = iRequestID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B750
// Name: public: bool CRConServer::BCloseAcceptedSocket(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::BCloseAcceptedSocket(CRConServer *this, unsigned int listener)
{
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // ebx
  int v4; // esi

  p_m_Socket = &this->m_Socket;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket);
  v4 = 0;
  if ( SamplePosition <= 0 )
    return 0;
  while ( *((_DWORD *)CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: v4) + 2) != listener )
  {
    if ( ++v4 >= SamplePosition )
      return 0;
  }
  CSocketCreator::CloseAcceptedSocket(this: p_m_Socket, nIndex: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012B7A0
// Name: RconPasswordChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl RconPasswordChanged_f(IConVar *pConVar)
{
  char *m_pszString; // esi
  CRConClient *v2; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_pszString = var.m_pConVarState->m_Value.m_pszString;
  v2 = RCONClient();
  CRConClient::SetPassword(this: v2, pPassword: m_pszString);
  CSocketCreator::CloseAllAcceptedSockets(this: &g_RCONServer.m_Socket);
  CUtlString::operator=(this: &g_RCONServer.m_Password, src: m_pszString);
}

//------------------------------------------------------------------------------
// Address: 0x1012BEF0
// Name: public: CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(CRConServer::ConnectedRConSocket_t *this)
{
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_OutstandingSends);
  if ( this->m_OutstandingSends.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OutstandingSends.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OutstandingSends.m_Memory.m_pMemory);
      this->m_OutstandingSends.m_Memory.m_pMemory = nullptr;
    }
    this->m_OutstandingSends.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->packetbuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->packetbuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->packetbuffer.m_Memory.m_pMemory);
      this->packetbuffer.m_Memory.m_pMemory = nullptr;
    }
    this->packetbuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BF60
// Name: private: bool CRConServer::SendRCONResponse(int,void const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::SendRCONResponse(CRConServer *this, int nIndex, char *data, int len, bool fromQueue)
{
  CSocketCreator *p_m_Socket; // esi
  signed int AcceptedSocketHandle; // ebx
  CRConServer::ConnectedRConSocket_t *AcceptedSocketData; // eax
  unsigned int m_ElementCount; // ecx
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *p_m_OutstandingSends; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  int v13; // eax
  unsigned __int16 v14; // ax
  CSocketCreator *v15; // [esp+Ch] [ebp-8h]
  CRConServer::ConnectedRConSocket_t *pSocketData; // [esp+10h] [ebp-4h]

  p_m_Socket = &this->m_Socket;
  v15 = &this->m_Socket;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex);
  if ( AcceptedSocketHandle < 0 )
    return 0;
  AcceptedSocketData = (CRConServer::ConnectedRConSocket_t *)CSocketCreator::GetAcceptedSocketData(
                                                               this: p_m_Socket,
                                                               nIndex);
  pSocketData = AcceptedSocketData;
  if ( !fromQueue )
  {
    m_ElementCount = AcceptedSocketData->m_OutstandingSends.m_ElementCount;
    if ( (_WORD)m_ElementCount != 0 )
    {
      if ( m_ElementCount > 0x64 )
      {
        CSocketCreator::CloseAcceptedSocket(this: p_m_Socket, nIndex);
        return 0;
      }
      p_m_OutstandingSends = &AcceptedSocketData->m_OutstandingSends;
      v11 = CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(this: &AcceptedSocketData->m_OutstandingSends);
      CUtlBuffer::Put(this: &p_m_OutstandingSends->m_Memory.m_pMemory[v11].m_Element, pMem: data, size: len);
      return 1;
    }
  }
  v12 = 0;
  if ( len <= 0 )
    return 1;
  while ( 1 )
  {
    v13 = send(s: AcceptedSocketHandle, buf: &data[v12], len: len - v12, flags: 0);
    if ( v13 == -1 )
      break;
    if ( v13 > 0 )
      v12 += v13;
    if ( v12 >= len )
      return 1;
  }
  if ( SocketWouldBlock() )
  {
    if ( fromQueue )
    {
      CUtlBuffer::SeekGet(
        this: &pSocketData->m_OutstandingSends.m_Memory.m_pMemory[pSocketData->m_OutstandingSends.m_Head].m_Element,
        type: SEEK_CURRENT,
        offset: v12);
    }
    else
    {
      v14 = CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(this: &pSocketData->m_OutstandingSends);
      CUtlBuffer::Put(
        this: &pSocketData->m_OutstandingSends.m_Memory.m_pMemory[v14].m_Element,
        pMem: &data[v12],
        size: len - v12);
    }
    return 0;
  }
  else
  {
    CSocketCreator::CloseAcceptedSocket(this: v15, nIndex);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C090
// Name: public: virtual void CRConServer::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::OnSocketAccepted(CRConServer *this, int hSocket, const netadr_s *netAdr, void **ppData)
{
  char *v4; // eax
  _DWORD *v5; // esi
  int v6; // eax

  v4 = (char *)MemAlloc_Alloc(nSize: 0x58u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)(v4 + 12), growSize: 0, initSize: 0, nFlags: 0);
    v5[15] = 0;
    v5[16] = 0;
    v5[17] = 0;
    *((_WORD *)v5 + 41) = -1;
    v5[19] = 0xFFFF;
    v6 = v5[15];
    v5[18] = -1;
    *((_WORD *)v5 + 40) = 0;
    v5[21] = v6;
  }
  else
  {
    v5 = nullptr;
  }
  v5[1] = 0;
  *(_BYTE *)v5 = 0;
  v5[2] = CServerRemoteAccess::GetNextListenerID(this: &g_ServerRemoteAccess, authConnection: true, adr: netAdr);
  *ppData = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1012C110
// Name: public: void CRConServer::FinishRedirect(char const __near *,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::FinishRedirect(CRConServer *this, const char *msg, netadr_s *adr)
{
  CRConServer *v3; // esi
  int v4; // edi
  const netadr_s *AcceptedSocketAddress; // eax
  _DWORD *AcceptedSocketData; // esi
  int v7; // esi
  int v8; // esi
  CUtlBuffer response; // [esp+Ch] [ebp-38h] BYREF
  int inputBuffer; // [esp+3Ch] [ebp-8h] BYREF
  CRConServer *v11; // [esp+40h] [ebp-4h]

  v3 = this;
  v11 = this;
  v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) - 1;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      AcceptedSocketAddress = CSocketCreator::GetAcceptedSocketAddress(this: &v3->m_Socket, nIndex: v4);
      if ( netadr_s::CompareAdr(this: adr, a: AcceptedSocketAddress, onlyBase: false) )
      {
        CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
        AcceptedSocketData = CSocketCreator::GetAcceptedSocketData(this: &v3->m_Socket, nIndex: v4);
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
        }
        else
        {
          inputBuffer = 0;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = 0;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        v7 = AcceptedSocketData[1];
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", v7);
        }
        else
        {
          inputBuffer = v7;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = v7;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
        }
        else
        {
          inputBuffer = 0;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = 0;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        CUtlBuffer::PutString(this: &response, pString: msg);
        CUtlBuffer::PutString(this: &response, pString: defaultValue);
        v8 = response.m_Put - 4;
        CUtlBuffer::SeekPut(this: &response, type: SEEK_HEAD, offset: 0);
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", v8);
        }
        else
        {
          inputBuffer = v8;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = v8;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        CUtlBuffer::SeekPut(this: &response, type: SEEK_CURRENT, offset: v8);
        CRConServer::SendRCONResponse(
          this: v11,
          nIndex: v4,
          data: (char *)response.m_Memory.m_pMemory,
          len: response.m_Put,
          fromQueue: false);
        if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
      }
      if ( --v4 < 0 )
        break;
      v3 = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C390
// Name: public: bool CRConServer::HandleFailedRconAuth(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::HandleFailedRconAuth(CRConServer *this, netadr_s *adr)
{
  int v3; // esi
  int v4; // ebx
  CRConServer::FailedRCon_t *v5; // ebx
  int v6; // edx
  CRConServer::FailedRCon_t *m_pMemory; // eax
  unsigned __int16 m_ElementCount; // cx
  int m_Element; // ebx
  int v10; // esi
  __int16 v11; // cx
  CRConServer::FailedRCon_t *v12; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CRConServer::FailedRCon_t *v15; // ecx
  int v16; // eax
  int v17; // eax
  CRConServer::FailedRCon_t *v18; // esi
  bool v19; // zf
  char *v20; // esi
  int v21; // eax
  unsigned __int16 v22; // ax
  int v23; // edi
  UtlLinkedListElem_t<float,unsigned short> *v24; // eax
  int v25; // ecx
  UtlLinkedListElem_t<float,unsigned short> *v26; // eax
  float *p_m_Element; // eax
  UtlLinkedListElem_t<float,unsigned short> *v28; // eax
  int m_Previous; // ecx
  int m_Next; // ecx
  ConVar *m_pParent; // eax
  int m_nValue; // edi
  ConVar *v33; // edx
  int v34; // ecx
  int v35; // edi
  int v36; // eax
  int v37; // eax
  const char *v38; // eax
  int v39; // esi
  const char *v40; // eax
  vgui::CTreeViewListControl *v41; // ecx
  ECommandTarget_t TraceType; // eax
  int v44; // edi
  double v45; // st6
  int v46; // eax
  unsigned int v47; // [esp-4h] [ebp-20h]
  int v48; // [esp+0h] [ebp-1Ch]
  unsigned int v49; // [esp+4h] [ebp-18h]
  const char *v50; // [esp+4h] [ebp-18h]
  int v51; // [esp+8h] [ebp-14h]
  int nCount; // [esp+Ch] [ebp-10h]
  int nCounta; // [esp+Ch] [ebp-10h]
  float nCountb; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int v56; // [esp+14h] [ebp-8h]
  int indexToRemove; // [esp+18h] [ebp-4h]
  unsigned __int16 recentFailures; // [esp+24h] [ebp+8h]
  int recentFailuresa; // [esp+24h] [ebp+8h]

  v3 = 0;
  nCount = this->m_failedRcons.m_Size;
  if ( nCount <= 0 )
    goto LABEL_7;
  v4 = 0;
  while ( !netadr_s::CompareAdr(this: adr, a: &this->m_failedRcons.m_Memory.m_pMemory[v4].adr, onlyBase: true) )
  {
    ++v3;
    ++v4;
    if ( v3 >= nCount )
      goto LABEL_7;
  }
  v5 = &this->m_failedRcons.m_Memory.m_pMemory[v3];
  if ( v5 == nullptr )
  {
LABEL_7:
    if ( nCount >= 32 )
    {
      v6 = 0;
      indexToRemove = -1;
      i = 0;
      v56 = -44;
      do
      {
        if ( indexToRemove < 0 )
          goto LABEL_16;
        m_pMemory = this->m_failedRcons.m_Memory.m_pMemory;
        m_ElementCount = m_pMemory[v6].badPasswordTimes.m_ElementCount;
        m_Element = 0;
        v10 = 0;
        if ( m_ElementCount != 0 )
          m_Element = (int)m_pMemory[v6].badPasswordTimes.m_Memory.m_pMemory[(unsigned __int16)(m_ElementCount - 1)].m_Element;
        v11 = *(unsigned __int16 *)((char *)&m_pMemory->badPasswordTimes.m_ElementCount + v56);
        if ( v11 != 0 )
          v10 = (int)(*(UtlLinkedListElem_t<float,unsigned short> **)((char *)&m_pMemory->badPasswordTimes.m_Memory.m_pMemory
                                                                    + v56))[(unsigned __int16)(v11 - 1)].m_Element;
        if ( m_Element < v10 )
        {
LABEL_16:
          indexToRemove = i;
          v56 = v6 * 44;
        }
        ++v6;
        ++i;
      }
      while ( i < nCount );
      if ( indexToRemove >= 0 )
      {
        v12 = &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove];
        CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v12->badPasswordTimes);
        if ( v12->badPasswordTimes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->badPasswordTimes.m_Memory.m_pMemory != nullptr )
          {
            v47 = (unsigned int)v12->badPasswordTimes.m_Memory.m_pMemory;
            ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
            v12->badPasswordTimes.m_Memory.m_pMemory = nullptr;
          }
          v12->badPasswordTimes.m_Memory.m_nAllocationCount = 0;
        }
        if ( this->m_failedRcons.m_Size - indexToRemove - 1 > 0 )
          _V_memmove(
            dest: &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove],
            src: &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove + 1],
            count: 44 * (this->m_failedRcons.m_Size - indexToRemove - 1));
        --this->m_failedRcons.m_Size;
      }
    }
    m_Size = this->m_failedRcons.m_Size;
    m_nAllocationCount = this->m_failedRcons.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CRConServer::FailedRCon_t,int>::Grow(
        this: (CUtlMemory<Remote_t,int> *)&this->m_failedRcons,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_failedRcons.m_Size;
    v15 = this->m_failedRcons.m_Memory.m_pMemory;
    v16 = this->m_failedRcons.m_Size - m_Size - 1;
    this->m_failedRcons.m_pElements = v15;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: 44 * v16);
    v17 = m_Size;
    v18 = this->m_failedRcons.m_Memory.m_pMemory;
    v17 *= 44;
    v19 = (CRConServer::FailedRCon_t *)((char *)v18 + v17) == nullptr;
    v20 = (char *)v18 + v17;
    nCounta = v17;
    if ( !v19 )
    {
      netadr_s::SetIP(this: (netadr_s *)(v20 + 4), unIP: 0);
      netadr_s::SetPort(this: (netadr_s *)(v20 + 4), newport: 0);
      netadr_s::SetType(this: (netadr_s *)(v20 + 4), newtype: NA_IP);
      *((_DWORD *)v20 + 4) = 0;
      *((_DWORD *)v20 + 5) = 0;
      *((_DWORD *)v20 + 6) = 0;
      *((_WORD *)v20 + 19) = -1;
      *((_DWORD *)v20 + 8) = 0xFFFF;
      v21 = *((_DWORD *)v20 + 4);
      *((_DWORD *)v20 + 7) = -1;
      *((_WORD *)v20 + 18) = 0;
      *((_DWORD *)v20 + 10) = v21;
    }
    v5 = (CRConServer::FailedRCon_t *)((char *)this->m_failedRcons.m_Memory.m_pMemory + nCounta);
    v5->adr = *adr;
    v5->badPasswordCount = 0;
    CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v5->badPasswordTimes);
  }
  ++v5->badPasswordCount;
  nCountb = CBaseServer::GetTime(this: &sv);
  v22 = CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(
          this: &v5->badPasswordTimes,
          multilist: false);
  v23 = v22;
  if ( v22 != 0xFFFF )
  {
    CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v5->badPasswordTimes,
      elem: v22);
    v24 = v5->badPasswordTimes.m_Memory.m_pMemory;
    v25 = v23;
    v24[v25].m_Next = -1;
    recentFailures = v5->badPasswordTimes.m_Tail;
    v24[v25].m_Previous = recentFailures;
    v5->badPasswordTimes.m_Tail = v23;
    if ( recentFailures == 0xFFFF )
      v5->badPasswordTimes.m_Head = v23;
    else
      v5->badPasswordTimes.m_Memory.m_pMemory[recentFailures].m_Next = v23;
    v26 = v5->badPasswordTimes.m_Memory.m_pMemory;
    ++v5->badPasswordTimes.m_ElementCount;
    p_m_Element = &v26[v25].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = nCountb;
  }
  for ( ; v5->badPasswordTimes.m_ElementCount > 0x14u; v5->badPasswordTimes.m_FirstFree = 0 )
  {
    if ( v5->badPasswordTimes.m_Memory.m_nAllocationCount > 0 )
    {
      v28 = v5->badPasswordTimes.m_Memory.m_pMemory;
      if ( v28->m_Previous != 0 )
      {
        m_Previous = v28->m_Previous;
        if ( (_WORD)m_Previous == 0xFFFF )
          v5->badPasswordTimes.m_Head = v28->m_Next;
        else
          v28[m_Previous].m_Next = v28->m_Next;
        m_Next = v28->m_Next;
        if ( (_WORD)m_Next == 0xFFFF )
          v5->badPasswordTimes.m_Tail = v28->m_Previous;
        else
          v5->badPasswordTimes.m_Memory.m_pMemory[m_Next].m_Previous = v28->m_Previous;
        *(_DWORD *)&v28->m_Previous = 0;
        --v5->badPasswordTimes.m_ElementCount;
      }
    }
    v5->badPasswordTimes.m_Memory.m_pMemory->m_Next = v5->badPasswordTimes.m_FirstFree;
  }
  m_pParent = sv_rcon_maxfailures.m_pParent;
  if ( sv_rcon_maxfailures.m_pParent != nullptr )
    m_nValue = sv_rcon_maxfailures.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v33 = sv_rcon_minfailures.m_pParent;
  if ( sv_rcon_minfailures.m_pParent != nullptr )
    v34 = sv_rcon_minfailures.m_pParent->m_Value.m_nValue;
  else
    v34 = 0;
  if ( m_nValue < v34 )
  {
    if ( sv_rcon_maxfailures.m_pParent != nullptr )
      v35 = sv_rcon_maxfailures.m_pParent->m_Value.m_nValue;
    else
      v35 = 0;
    if ( sv_rcon_minfailures.m_pParent != nullptr )
      v36 = sv_rcon_minfailures.m_pParent->m_Value.m_nValue;
    else
      v36 = 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_rcon_maxfailures.IConVar, value: v36, a2: v47, a3: v48);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_rcon_minfailures.IConVar, value: v35, a2: v49, a3: v51);
    m_pParent = sv_rcon_maxfailures.m_pParent;
    v33 = sv_rcon_minfailures.m_pParent;
  }
  if ( m_pParent != nullptr )
    v37 = m_pParent->m_Value.m_nValue;
  else
    v37 = 0;
  if ( v5->badPasswordCount <= v37 )
  {
    v44 = v5->badPasswordTimes.m_ElementCount - 1;
    recentFailuresa = 0;
    if ( v5->badPasswordTimes.m_ElementCount != 0 )
    {
      do
      {
        v45 = (float)(v5->badPasswordTimes.m_Memory.m_pMemory[(unsigned __int16)v44].m_Element
                    + sv_rcon_minfailuretime.m_pParent->m_Value.m_fValue);
        if ( v45 >= CBaseServer::GetTime(this: &sv) )
          ++recentFailuresa;
        --v44;
      }
      while ( v44 >= 0 );
      v33 = sv_rcon_minfailures.m_pParent;
    }
    v46 = v33 != nullptr ? v33->m_Value.m_nValue : 0;
    if ( recentFailuresa <= v46 )
      return 0;
  }
  v38 = netadr_s::ToString(this: &v5->adr, baseOnly: true);
  ConMsg(a1: "Banning %s for rcon hacking attempts\n", v38);
  if ( sv_rcon_banpenalty.m_pParent != nullptr )
    v39 = sv_rcon_banpenalty.m_pParent->m_Value.m_nValue;
  else
    v39 = 0;
  v40 = netadr_s::ToString(this: &v5->adr, baseOnly: true);
  v50 = va(format: "addip %i %s\n", v39, v40);
  TraceType = CTraceFilter::GetTraceType(this: v41);
  Cbuf_AddText(eTarget: TraceType, pText: v50, nTickDelay: 0);
  Cbuf_Execute();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012C840
// Name: public: virtual void CRConServer::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::OnSocketClosed(
        CRConServer *this,
        int hSocket,
        const netadr_s *netAdr,
        CRConServer::ConnectedRConSocket_t *pData)
{
  this->m_bSocketDeleted = true;
  if ( pData != nullptr )
  {
    CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(this: pData);
    free(pMem: pData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C870
// Name: public: void CRConServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::RunFrame(CRConServer *this)
{
  CRConServer *v1; // esi
  int v2; // edi
  CSocketCreator *p_m_Socket; // esi
  char *AcceptedSocketData; // ebx
  netadr_s *AcceptedSocketAddress; // eax
  bool v6; // zf
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *v7; // edi
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v8; // eax
  int v9; // ebx
  int v10; // esi
  char *v11; // edx
  int DataResponseSize; // edi
  char *p_data; // esi
  CRConServer *v14; // edi
  SOCKET v15; // esi
  int v16; // eax
  u_long v17; // edi
  u_long v18; // eax
  void *v19; // esp
  unsigned int v20; // edi
  int v21; // eax
  int v22; // edi
  u_long v23; // eax
  CRConServer *v24; // edi
  int Error; // eax
  const char *v26; // eax
  int Int; // eax
  int SamplePosition; // eax
  int v29; // [esp+0h] [ebp-1064h] BYREF
  char data; // [esp+Ch] [ebp-1058h] BYREF
  CUtlBuffer v31; // [esp+100Ch] [ebp-58h] BYREF
  SOCKET s; // [esp+103Ch] [ebp-28h]
  netadr_s *adr; // [esp+1040h] [ebp-24h]
  char buf; // [esp+1047h] [ebp-1Dh] BYREF
  int len; // [esp+1048h] [ebp-1Ch]
  u_long argp; // [esp+104Ch] [ebp-18h] BYREF
  bool v37; // [esp+1053h] [ebp-11h]
  char *v38; // [esp+1054h] [ebp-10h]
  int bufferSize; // [esp+1058h] [ebp-Ch] BYREF
  CRConServer *pNetworkListener; // [esp+105Ch] [ebp-8h]
  int nIndex; // [esp+1060h] [ebp-4h]

  v1 = this;
  pNetworkListener = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  v1->m_bSocketDeleted = false;
  v2 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v1->m_Socket) - 1;
  nIndex = v2;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      p_m_Socket = &v1->m_Socket;
      AcceptedSocketData = (char *)CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: v2);
      v38 = AcceptedSocketData;
      s = CSocketCreator::GetAcceptedSocketHandle(this: p_m_Socket, nIndex: v2);
      AcceptedSocketAddress = (netadr_s *)CSocketCreator::GetAcceptedSocketAddress(this: p_m_Socket, nIndex: v2);
      v6 = *((_WORD *)AcceptedSocketData + 39) == 0;
      adr = AcceptedSocketAddress;
      if ( !v6 )
      {
        v7 = (CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *)(AcceptedSocketData + 60);
        do
        {
          v8 = &v7->m_Memory.m_pMemory[*((unsigned __int16 *)AcceptedSocketData + 36)];
          if ( CRConServer::SendRCONResponse(
                 this: pNetworkListener,
                 nIndex,
                 data: (char *)&v8->m_Element.m_Memory.m_pMemory[v8->m_Element.m_Get - v8->m_Element.m_nOffset],
                 len: v8->m_Element.m_Put - v8->m_Element.m_Get,
                 fromQueue: true) == 0 )
            break;
          v9 = *((unsigned __int16 *)AcceptedSocketData + 36);
          CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
            this: v7,
            elem: v9);
          v10 = (int)&v7->m_Memory.m_pMemory[v9];
          if ( *(int *)(v10 + 8) >= 0 )
          {
            if ( *(_DWORD *)v10 != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v10);
              *(_DWORD *)v10 = 0;
            }
            *(_DWORD *)(v10 + 4) = 0;
          }
          v11 = v38;
          *(_WORD *)(v10 + 50) = v7->m_FirstFree;
          v7->m_FirstFree = v9;
          AcceptedSocketData = v11;
        }
        while ( *((_WORD *)v11 + 39) != 0 );
      }
      DataResponseSize = CServerRemoteAccess::GetDataResponseSize(
                           this: &g_ServerRemoteAccess,
                           listener: *((_DWORD *)AcceptedSocketData + 2));
      if ( DataResponseSize <= 0 )
      {
        v14 = pNetworkListener;
      }
      else
      {
        p_data = &data;
        len = DataResponseSize + 4;
        v37 = (unsigned int)(DataResponseSize + 4) > 0x1000;
        if ( (unsigned int)(DataResponseSize + 4) > 0x1000 )
          p_data = (char *)MemAlloc_Alloc(nSize: DataResponseSize + 4);
        *(_DWORD *)p_data = DataResponseSize;
        CServerRemoteAccess::ReadDataResponse(
          this: &g_ServerRemoteAccess,
          listener: *((_DWORD *)AcceptedSocketData + 2),
          buffer: p_data + 4,
          bufferSize: DataResponseSize);
        v14 = pNetworkListener;
        CRConServer::SendRCONResponse(this: pNetworkListener, nIndex, data: p_data, len, fromQueue: false);
        if ( v37 )
          free(pMem: p_data);
      }
      v15 = s;
      argp = 0;
      v16 = recv(s, &buf, len: 1, flags: 2);
      if ( v16 == -1 )
        break;
      if ( v16 <= 0 )
        goto LABEL_22;
      ioctlsocket(s: v15, cmd: 1074030207, &argp);
      if ( argp > 4 )
      {
        CUtlBuffer::EnsureCapacity(
          this: (CUtlBuffer *)(AcceptedSocketData + 12),
          num: argp + *((_DWORD *)AcceptedSocketData + 7));
        v17 = argp;
        v18 = 1024;
        if ( argp <= 0x400 )
          v18 = argp;
        v19 = alloca(v18);
        len = (int)&v29;
        v38 = nullptr;
        if ( argp != 0 )
        {
          while ( 1 )
          {
            v20 = v17 - (_DWORD)v38;
            if ( v20 > 0x400 )
              v20 = 1024;
            v21 = recv(s, buf: (char *)len, len: v20, flags: 0);
            v22 = v21;
            if ( v21 == 0 )
            {
              v24 = pNetworkListener;
              CSocketCreator::CloseAcceptedSocket(this: &pNetworkListener->m_Socket, nIndex);
              goto LABEL_37;
            }
            if ( v21 < 0 && !SocketWouldBlock() )
              break;
            CUtlBuffer::Put(this: (CUtlBuffer *)(AcceptedSocketData + 12), pMem: (const void *)len, size: v22);
            v23 = (u_long)&v38[v22];
            v17 = argp;
            v38 = (char *)v23;
            if ( v23 >= argp )
              goto LABEL_36;
          }
          Error = WSAGetLastError();
          v26 = NET_ErrorString(code: Error);
          _Warning(a1: "RCON Cmd: recv error (%s)\n", v26);
        }
LABEL_36:
        v24 = pNetworkListener;
LABEL_37:
        CUtlBuffer::SeekGet(this: (CUtlBuffer *)(AcceptedSocketData + 12), type: SEEK_HEAD, offset: 0);
        Int = CUtlBuffer::GetInt(this: (CUtlBuffer *)(AcceptedSocketData + 12));
        bufferSize = Int;
        if ( Int <= 1024 )
        {
          if ( Int > 0 )
          {
            while ( Int <= *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) )
            {
              SV_RedirectStart(rd: RD_SOCKET, addr: adr);
              CServerRemoteAccess::WriteDataRequest(
                this: &g_ServerRemoteAccess,
                pNetworkListener: v24,
                listener: *((_DWORD *)AcceptedSocketData + 2),
                buffer: (const void *)(*((_DWORD *)AcceptedSocketData + 3)
                             + *((_DWORD *)AcceptedSocketData + 6)
                             - *((_DWORD *)AcceptedSocketData + 11)),
                bufferSize);
              SV_RedirectEnd();
              if ( v24->m_bSocketDeleted )
                return;
              CUtlBuffer::SeekGet(this: (CUtlBuffer *)(AcceptedSocketData + 12), type: SEEK_CURRENT, offset: bufferSize);
              if ( (unsigned int)(*((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6)) < 4 )
              {
                bufferSize = 0;
                break;
              }
              Int = CUtlBuffer::GetInt(this: (CUtlBuffer *)(AcceptedSocketData + 12));
              bufferSize = Int;
              if ( Int <= 0 )
                break;
            }
          }
          SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v24->m_Socket);
          if ( SamplePosition == 0
            || nIndex > SamplePosition
            || AcceptedSocketData != CSocketCreator::GetAcceptedSocketData(this: &v24->m_Socket, nIndex) )
          {
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
            return;
          }
          if ( bufferSize > 0 || *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) > 0 )
          {
            CUtlBuffer::CUtlBuffer(this: &v31, growSize: 0, initSize: 0, nFlags: 0);
            if ( *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) > 0 )
              CUtlBuffer::Put(
                this: &v31,
                pMem: (const void *)(*((_DWORD *)AcceptedSocketData + 3)
                             + *((_DWORD *)AcceptedSocketData + 6)
                             - *((_DWORD *)AcceptedSocketData + 11)),
                size: *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6));
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
            if ( bufferSize > 0 )
              CUtlBuffer::Put(this: (CUtlBuffer *)(AcceptedSocketData + 12), pMem: &bufferSize, size: 4);
            if ( v31.m_Put > 0 )
              CUtlBuffer::Put(
                this: (CUtlBuffer *)(AcceptedSocketData + 12),
                pMem: v31.m_Memory.m_pMemory,
                size: v31.m_Put);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &v31);
          }
          else
          {
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
          }
        }
        else
        {
          CRConServer::HandleFailedRconAuth(this: v24, adr);
          CSocketCreator::CloseAcceptedSocket(this: &v24->m_Socket, nIndex);
        }
      }
LABEL_59:
      if ( --nIndex < 0 )
        return;
      v1 = pNetworkListener;
      v2 = nIndex;
    }
    if ( SocketWouldBlock() )
      goto LABEL_59;
LABEL_22:
    CSocketCreator::CloseAcceptedSocket(this: &v14->m_Socket, nIndex);
    goto LABEL_59;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CCA0
// Name: public: virtual void CRPTServer::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTServer::OnSocketAccepted(CRPTServer *this, int hSocket, const netadr_s *netAdr, void **ppData)
{
  CRConServer::OnSocketAccepted(this, hSocket, netAdr, ppData);
  Cmd_SetRptActive(bActive: true);
}

//------------------------------------------------------------------------------
// Address: 0x1012CCD0
// Name: public: virtual void CRPTServer::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTServer::OnSocketClosed(
        CRPTServer *this,
        int hSocket,
        const netadr_s *netAdr,
        CRConServer::ConnectedRConSocket_t *pData)
{
  Cmd_SetRptActive(bActive: false);
  this->m_bSocketDeleted = true;
  if ( pData != nullptr )
  {
    CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(this: pData);
    free(pMem: pData);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1005E0E0
// Name: public: void CUtlMemory<struct CRConServer::FailedRCon_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRConServer::FailedRCon_t,int>::Grow(CUtlMemory<Remote_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Remote_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Remote_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Remote_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B730
// Name: class CRConServer __near & RCONServer(void)
// Source: json
//------------------------------------------------------------------------------
CRConServer *__cdecl RCONServer()
{
  return &g_RCONServer;
}

//------------------------------------------------------------------------------
// Address: 0x1012B740
// Name: class CRConServer __near & RPTServer(void)
// Source: json
//------------------------------------------------------------------------------
CRPTServer *__cdecl RPTServer()
{
  return &g_RPTServer;
}

//------------------------------------------------------------------------------
// Address: 0x1012B7B0
// Name: public: void CRConServer::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetPassword(CRConServer *this, const char *pPassword)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  CUtlString::operator=(this: &this->m_Password, src: pPassword);
}

//------------------------------------------------------------------------------
// Address: 0x1012B7D0
// Name: public: bool CRConServer::HasPassword(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRConServer::HasPassword(CRConServer *this)
{
  return CUtlString::Length(this: &this->m_Password) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B7E0
// Name: public: bool CRConServer::IsPassword(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConServer::IsPassword(CRConServer *this, const char *pPassword)
{
  CUtlString *p_m_Password; // esi
  const char *v4; // eax

  p_m_Password = &this->m_Password;
  if ( CUtlString::Length(this: &this->m_Password) == 0 )
    return false;
  v4 = CUtlString::operator char const *(this: p_m_Password);
  return _V_strcmp(s1: pPassword, s2: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B820
// Name: public: void CRConServer::SetAddress(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetAddress(CRConServer *this, const char *pNetAddress)
{
  netadr_s *p_m_Address; // esi

  p_m_Address = &this->m_Address;
  NET_StringToAdr(s: pNetAddress, a: &this->m_Address);
  if ( netadr_s::GetPort(this: p_m_Address) == 0 )
    netadr_s::SetPort(this: p_m_Address, newport: 0x6987u);
}

//------------------------------------------------------------------------------
// Address: 0x1012B860
// Name: public: bool CRConServer::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConServer::CreateSocket(CRConServer *this)
{
  return CSocketCreator::CreateListenSocket(
           this: &this->m_Socket,
           netAdr: &this->m_Address,
           bListenOnAllInterfaces: false);
}

//------------------------------------------------------------------------------
// Address: 0x1012B880
// Name: public: void CRConServer::SetRequestID(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::SetRequestID(CRConServer *this, unsigned int listener, int iRequestID)
{
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // ebx
  int i; // esi
  _DWORD *AcceptedSocketData; // eax

  p_m_Socket = &this->m_Socket;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket);
  for ( i = 0; i < SamplePosition; ++i )
  {
    AcceptedSocketData = CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: i);
    if ( AcceptedSocketData[2] == listener )
      AcceptedSocketData[1] = iRequestID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B8C0
// Name: public: bool CRConServer::BCloseAcceptedSocket(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::BCloseAcceptedSocket(CRConServer *this, unsigned int listener)
{
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // ebx
  int v4; // esi

  p_m_Socket = &this->m_Socket;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket);
  v4 = 0;
  if ( SamplePosition <= 0 )
    return 0;
  while ( *((_DWORD *)CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: v4) + 2) != listener )
  {
    if ( ++v4 >= SamplePosition )
      return 0;
  }
  CSocketCreator::CloseAcceptedSocket(this: p_m_Socket, nIndex: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012B910
// Name: RconPasswordChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl RconPasswordChanged_f(IConVar *pConVar)
{
  char *m_pszString; // esi
  CRConClient *v2; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_pszString = var.m_pConVarState->m_Value.m_pszString;
  v2 = RCONClient();
  CRConClient::SetPassword(this: v2, pPassword: m_pszString);
  CSocketCreator::CloseAllAcceptedSockets(this: &g_RCONServer.m_Socket);
  CUtlString::operator=(this: &g_RCONServer.m_Password, src: m_pszString);
}

//------------------------------------------------------------------------------
// Address: 0x1012C060
// Name: public: CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(CRConServer::ConnectedRConSocket_t *this)
{
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_OutstandingSends);
  if ( this->m_OutstandingSends.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OutstandingSends.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OutstandingSends.m_Memory.m_pMemory);
      this->m_OutstandingSends.m_Memory.m_pMemory = nullptr;
    }
    this->m_OutstandingSends.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->packetbuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->packetbuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->packetbuffer.m_Memory.m_pMemory);
      this->packetbuffer.m_Memory.m_pMemory = nullptr;
    }
    this->packetbuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C0D0
// Name: private: bool CRConServer::SendRCONResponse(int,void const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::SendRCONResponse(CRConServer *this, int nIndex, char *data, int len, bool fromQueue)
{
  CSocketCreator *p_m_Socket; // esi
  signed int AcceptedSocketHandle; // ebx
  CRConServer::ConnectedRConSocket_t *AcceptedSocketData; // eax
  unsigned int m_ElementCount; // ecx
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *p_m_OutstandingSends; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  int v13; // eax
  unsigned __int16 v14; // ax
  CSocketCreator *v15; // [esp+Ch] [ebp-8h]
  CRConServer::ConnectedRConSocket_t *pSocketData; // [esp+10h] [ebp-4h]

  p_m_Socket = &this->m_Socket;
  v15 = &this->m_Socket;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex);
  if ( AcceptedSocketHandle < 0 )
    return 0;
  AcceptedSocketData = (CRConServer::ConnectedRConSocket_t *)CSocketCreator::GetAcceptedSocketData(
                                                               this: p_m_Socket,
                                                               nIndex);
  pSocketData = AcceptedSocketData;
  if ( !fromQueue )
  {
    m_ElementCount = AcceptedSocketData->m_OutstandingSends.m_ElementCount;
    if ( (_WORD)m_ElementCount != 0 )
    {
      if ( m_ElementCount > 0x64 )
      {
        CSocketCreator::CloseAcceptedSocket(this: p_m_Socket, nIndex);
        return 0;
      }
      p_m_OutstandingSends = &AcceptedSocketData->m_OutstandingSends;
      v11 = CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(this: &AcceptedSocketData->m_OutstandingSends);
      CUtlBuffer::Put(this: &p_m_OutstandingSends->m_Memory.m_pMemory[v11].m_Element, pMem: data, size: len);
      return 1;
    }
  }
  v12 = 0;
  if ( len <= 0 )
    return 1;
  while ( 1 )
  {
    v13 = send(s: AcceptedSocketHandle, buf: &data[v12], len: len - v12, flags: 0);
    if ( v13 == -1 )
      break;
    if ( v13 > 0 )
      v12 += v13;
    if ( v12 >= len )
      return 1;
  }
  if ( SocketWouldBlock() )
  {
    if ( fromQueue )
    {
      CUtlBuffer::SeekGet(
        this: &pSocketData->m_OutstandingSends.m_Memory.m_pMemory[pSocketData->m_OutstandingSends.m_Head].m_Element,
        type: SEEK_CURRENT,
        offset: v12);
    }
    else
    {
      v14 = CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(this: &pSocketData->m_OutstandingSends);
      CUtlBuffer::Put(
        this: &pSocketData->m_OutstandingSends.m_Memory.m_pMemory[v14].m_Element,
        pMem: &data[v12],
        size: len - v12);
    }
    return 0;
  }
  else
  {
    CSocketCreator::CloseAcceptedSocket(this: v15, nIndex);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C200
// Name: public: virtual void CRConServer::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::OnSocketAccepted(CRConServer *this, int hSocket, const netadr_s *netAdr, void **ppData)
{
  char *v4; // eax
  _DWORD *v5; // esi
  int v6; // eax

  v4 = (char *)MemAlloc_Alloc(nSize: 0x58u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)(v4 + 12), growSize: 0, initSize: 0, nFlags: 0);
    v5[15] = 0;
    v5[16] = 0;
    v5[17] = 0;
    *((_WORD *)v5 + 41) = -1;
    v5[19] = 0xFFFF;
    v6 = v5[15];
    v5[18] = -1;
    *((_WORD *)v5 + 40) = 0;
    v5[21] = v6;
  }
  else
  {
    v5 = nullptr;
  }
  v5[1] = 0;
  *(_BYTE *)v5 = 0;
  v5[2] = CServerRemoteAccess::GetNextListenerID(this: &g_ServerRemoteAccess, authConnection: true, adr: netAdr);
  *ppData = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1012C280
// Name: public: void CRConServer::FinishRedirect(char const __near *,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::FinishRedirect(CRConServer *this, const char *msg, netadr_s *adr)
{
  CRConServer *v3; // esi
  int v4; // edi
  const netadr_s *AcceptedSocketAddress; // eax
  _DWORD *AcceptedSocketData; // esi
  int v7; // esi
  int v8; // esi
  CUtlBuffer response; // [esp+Ch] [ebp-38h] BYREF
  int inputBuffer; // [esp+3Ch] [ebp-8h] BYREF
  CRConServer *v11; // [esp+40h] [ebp-4h]

  v3 = this;
  v11 = this;
  v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) - 1;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      AcceptedSocketAddress = CSocketCreator::GetAcceptedSocketAddress(this: &v3->m_Socket, nIndex: v4);
      if ( netadr_s::CompareAdr(this: adr, a: AcceptedSocketAddress, onlyBase: false) )
      {
        CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
        AcceptedSocketData = CSocketCreator::GetAcceptedSocketData(this: &v3->m_Socket, nIndex: v4);
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
        }
        else
        {
          inputBuffer = 0;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = 0;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        v7 = AcceptedSocketData[1];
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", v7);
        }
        else
        {
          inputBuffer = v7;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = v7;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
        }
        else
        {
          inputBuffer = 0;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = 0;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        CUtlBuffer::PutString(this: &response, pString: msg);
        CUtlBuffer::PutString(this: &response, pString: defaultValue);
        v8 = response.m_Put - 4;
        CUtlBuffer::SeekPut(this: &response, type: SEEK_HEAD, offset: 0);
        if ( (response.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &response, pFmt: "%d", v8);
        }
        else
        {
          inputBuffer = v8;
          if ( CUtlBuffer::CheckPut(this: &response, nSize: 4) )
          {
            if ( (*(_BYTE *)&response.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &response.m_Byteswap,
                outputBuffer: (int *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&response.m_Memory.m_pMemory[response.m_Put - response.m_nOffset] = v8;
            response.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &response, nPut: response.m_Put);
          }
        }
        CUtlBuffer::SeekPut(this: &response, type: SEEK_CURRENT, offset: v8);
        CRConServer::SendRCONResponse(
          this: v11,
          nIndex: v4,
          data: (char *)response.m_Memory.m_pMemory,
          len: response.m_Put,
          fromQueue: false);
        if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
      }
      if ( --v4 < 0 )
        break;
      v3 = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C500
// Name: public: bool CRConServer::HandleFailedRconAuth(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRConServer::HandleFailedRconAuth(CRConServer *this, netadr_s *adr)
{
  int v3; // esi
  int v4; // ebx
  CRConServer::FailedRCon_t *v5; // ebx
  int v6; // edx
  CRConServer::FailedRCon_t *m_pMemory; // eax
  unsigned __int16 m_ElementCount; // cx
  int m_Element; // ebx
  int v10; // esi
  __int16 v11; // cx
  CRConServer::FailedRCon_t *v12; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CRConServer::FailedRCon_t *v15; // ecx
  int v16; // eax
  int v17; // eax
  CRConServer::FailedRCon_t *v18; // esi
  bool v19; // zf
  char *v20; // esi
  int v21; // eax
  unsigned __int16 v22; // ax
  int v23; // edi
  UtlLinkedListElem_t<float,unsigned short> *v24; // eax
  int v25; // ecx
  UtlLinkedListElem_t<float,unsigned short> *v26; // eax
  float *p_m_Element; // eax
  UtlLinkedListElem_t<float,unsigned short> *v28; // eax
  int m_Previous; // ecx
  int m_Next; // ecx
  ConVar *m_pParent; // eax
  int m_nValue; // edi
  ConVar *v33; // edx
  int v34; // ecx
  int v35; // edi
  int v36; // eax
  int v37; // eax
  const char *v38; // eax
  int v39; // esi
  const char *v40; // eax
  vgui::CTreeViewListControl *v41; // ecx
  ECommandTarget_t TraceType; // eax
  int v44; // edi
  double v45; // st6
  int v46; // eax
  const char *v47; // [esp+4h] [ebp-18h]
  int nCount; // [esp+Ch] [ebp-10h]
  int nCounta; // [esp+Ch] [ebp-10h]
  float nCountb; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int v52; // [esp+14h] [ebp-8h]
  int indexToRemove; // [esp+18h] [ebp-4h]
  unsigned __int16 recentFailures; // [esp+24h] [ebp+8h]
  int recentFailuresa; // [esp+24h] [ebp+8h]

  v3 = 0;
  nCount = this->m_failedRcons.m_Size;
  if ( nCount <= 0 )
    goto LABEL_7;
  v4 = 0;
  while ( !netadr_s::CompareAdr(this: adr, a: &this->m_failedRcons.m_Memory.m_pMemory[v4].adr, onlyBase: true) )
  {
    ++v3;
    ++v4;
    if ( v3 >= nCount )
      goto LABEL_7;
  }
  v5 = &this->m_failedRcons.m_Memory.m_pMemory[v3];
  if ( v5 == nullptr )
  {
LABEL_7:
    if ( nCount >= 32 )
    {
      v6 = 0;
      indexToRemove = -1;
      i = 0;
      v52 = -44;
      do
      {
        if ( indexToRemove < 0 )
          goto LABEL_16;
        m_pMemory = this->m_failedRcons.m_Memory.m_pMemory;
        m_ElementCount = m_pMemory[v6].badPasswordTimes.m_ElementCount;
        m_Element = 0;
        v10 = 0;
        if ( m_ElementCount != 0 )
          m_Element = (int)m_pMemory[v6].badPasswordTimes.m_Memory.m_pMemory[(unsigned __int16)(m_ElementCount - 1)].m_Element;
        v11 = *(unsigned __int16 *)((char *)&m_pMemory->badPasswordTimes.m_ElementCount + v52);
        if ( v11 != 0 )
          v10 = (int)(*(UtlLinkedListElem_t<float,unsigned short> **)((char *)&m_pMemory->badPasswordTimes.m_Memory.m_pMemory
                                                                    + v52))[(unsigned __int16)(v11 - 1)].m_Element;
        if ( m_Element < v10 )
        {
LABEL_16:
          indexToRemove = i;
          v52 = v6 * 44;
        }
        ++v6;
        ++i;
      }
      while ( i < nCount );
      if ( indexToRemove >= 0 )
      {
        v12 = &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove];
        CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v12->badPasswordTimes);
        if ( v12->badPasswordTimes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->badPasswordTimes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->badPasswordTimes.m_Memory.m_pMemory);
            v12->badPasswordTimes.m_Memory.m_pMemory = nullptr;
          }
          v12->badPasswordTimes.m_Memory.m_nAllocationCount = 0;
        }
        if ( this->m_failedRcons.m_Size - indexToRemove - 1 > 0 )
          _V_memmove(
            dest: &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove],
            src: &this->m_failedRcons.m_Memory.m_pMemory[indexToRemove + 1],
            count: 44 * (this->m_failedRcons.m_Size - indexToRemove - 1));
        --this->m_failedRcons.m_Size;
      }
    }
    m_Size = this->m_failedRcons.m_Size;
    m_nAllocationCount = this->m_failedRcons.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CRConServer::FailedRCon_t,int>::Grow(
        this: (CUtlMemory<Remote_t,int> *)&this->m_failedRcons,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_failedRcons.m_Size;
    v15 = this->m_failedRcons.m_Memory.m_pMemory;
    v16 = this->m_failedRcons.m_Size - m_Size - 1;
    this->m_failedRcons.m_pElements = v15;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: 44 * v16);
    v17 = m_Size;
    v18 = this->m_failedRcons.m_Memory.m_pMemory;
    v17 *= 44;
    v19 = (CRConServer::FailedRCon_t *)((char *)v18 + v17) == nullptr;
    v20 = (char *)v18 + v17;
    nCounta = v17;
    if ( !v19 )
    {
      netadr_s::SetIP(this: (netadr_s *)(v20 + 4), unIP: 0);
      netadr_s::SetPort(this: (netadr_s *)(v20 + 4), newport: 0);
      netadr_s::SetType(this: (netadr_s *)(v20 + 4), newtype: NA_IP);
      *((_DWORD *)v20 + 4) = 0;
      *((_DWORD *)v20 + 5) = 0;
      *((_DWORD *)v20 + 6) = 0;
      *((_WORD *)v20 + 19) = -1;
      *((_DWORD *)v20 + 8) = 0xFFFF;
      v21 = *((_DWORD *)v20 + 4);
      *((_DWORD *)v20 + 7) = -1;
      *((_WORD *)v20 + 18) = 0;
      *((_DWORD *)v20 + 10) = v21;
    }
    v5 = (CRConServer::FailedRCon_t *)((char *)this->m_failedRcons.m_Memory.m_pMemory + nCounta);
    v5->adr = *adr;
    v5->badPasswordCount = 0;
    CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v5->badPasswordTimes);
  }
  ++v5->badPasswordCount;
  nCountb = CBaseServer::GetTime(this: &sv);
  v22 = CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(
          this: &v5->badPasswordTimes,
          multilist: false);
  v23 = v22;
  if ( v22 != 0xFFFF )
  {
    CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&v5->badPasswordTimes,
      elem: v22);
    v24 = v5->badPasswordTimes.m_Memory.m_pMemory;
    v25 = v23;
    v24[v25].m_Next = -1;
    recentFailures = v5->badPasswordTimes.m_Tail;
    v24[v25].m_Previous = recentFailures;
    v5->badPasswordTimes.m_Tail = v23;
    if ( recentFailures == 0xFFFF )
      v5->badPasswordTimes.m_Head = v23;
    else
      v5->badPasswordTimes.m_Memory.m_pMemory[recentFailures].m_Next = v23;
    v26 = v5->badPasswordTimes.m_Memory.m_pMemory;
    ++v5->badPasswordTimes.m_ElementCount;
    p_m_Element = &v26[v25].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = nCountb;
  }
  for ( ; v5->badPasswordTimes.m_ElementCount > 0x14u; v5->badPasswordTimes.m_FirstFree = 0 )
  {
    if ( v5->badPasswordTimes.m_Memory.m_nAllocationCount > 0 )
    {
      v28 = v5->badPasswordTimes.m_Memory.m_pMemory;
      if ( v28->m_Previous != 0 )
      {
        m_Previous = v28->m_Previous;
        if ( (_WORD)m_Previous == 0xFFFF )
          v5->badPasswordTimes.m_Head = v28->m_Next;
        else
          v28[m_Previous].m_Next = v28->m_Next;
        m_Next = v28->m_Next;
        if ( (_WORD)m_Next == 0xFFFF )
          v5->badPasswordTimes.m_Tail = v28->m_Previous;
        else
          v5->badPasswordTimes.m_Memory.m_pMemory[m_Next].m_Previous = v28->m_Previous;
        *(_DWORD *)&v28->m_Previous = 0;
        --v5->badPasswordTimes.m_ElementCount;
      }
    }
    v5->badPasswordTimes.m_Memory.m_pMemory->m_Next = v5->badPasswordTimes.m_FirstFree;
  }
  m_pParent = sv_rcon_maxfailures.m_pParent;
  if ( sv_rcon_maxfailures.m_pParent != nullptr )
    m_nValue = sv_rcon_maxfailures.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v33 = sv_rcon_minfailures.m_pParent;
  if ( sv_rcon_minfailures.m_pParent != nullptr )
    v34 = sv_rcon_minfailures.m_pParent->m_Value.m_nValue;
  else
    v34 = 0;
  if ( m_nValue < v34 )
  {
    if ( sv_rcon_maxfailures.m_pParent != nullptr )
      v35 = sv_rcon_maxfailures.m_pParent->m_Value.m_nValue;
    else
      v35 = 0;
    if ( sv_rcon_minfailures.m_pParent != nullptr )
      v36 = sv_rcon_minfailures.m_pParent->m_Value.m_nValue;
    else
      v36 = 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_rcon_maxfailures.IConVar, value: v36);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_rcon_minfailures.IConVar, value: v35);
    m_pParent = sv_rcon_maxfailures.m_pParent;
    v33 = sv_rcon_minfailures.m_pParent;
  }
  if ( m_pParent != nullptr )
    v37 = m_pParent->m_Value.m_nValue;
  else
    v37 = 0;
  if ( v5->badPasswordCount <= v37 )
  {
    v44 = v5->badPasswordTimes.m_ElementCount - 1;
    recentFailuresa = 0;
    if ( v5->badPasswordTimes.m_ElementCount != 0 )
    {
      do
      {
        v45 = (float)(v5->badPasswordTimes.m_Memory.m_pMemory[(unsigned __int16)v44].m_Element
                    + sv_rcon_minfailuretime.m_pParent->m_Value.m_fValue);
        if ( v45 >= CBaseServer::GetTime(this: &sv) )
          ++recentFailuresa;
        --v44;
      }
      while ( v44 >= 0 );
      v33 = sv_rcon_minfailures.m_pParent;
    }
    v46 = v33 != nullptr ? v33->m_Value.m_nValue : 0;
    if ( recentFailuresa <= v46 )
      return 0;
  }
  v38 = netadr_s::ToString(this: &v5->adr, baseOnly: true);
  ConMsg(a1: "Banning %s for rcon hacking attempts\n", v38);
  if ( sv_rcon_banpenalty.m_pParent != nullptr )
    v39 = sv_rcon_banpenalty.m_pParent->m_Value.m_nValue;
  else
    v39 = 0;
  v40 = netadr_s::ToString(this: &v5->adr, baseOnly: true);
  v47 = va(format: "addip %i %s\n", v39, v40);
  TraceType = CTraceFilter::GetTraceType(this: v41);
  Cbuf_AddText(eTarget: TraceType, pText: v47, nTickDelay: 0);
  Cbuf_Execute();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012C9B0
// Name: public: virtual void CRConServer::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::OnSocketClosed(
        CRConServer *this,
        int hSocket,
        const netadr_s *netAdr,
        CRConServer::ConnectedRConSocket_t *pData)
{
  this->m_bSocketDeleted = true;
  if ( pData != nullptr )
  {
    CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(this: pData);
    free(pMem: pData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C9E0
// Name: public: void CRConServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConServer::RunFrame(CRConServer *this)
{
  CRConServer *v1; // esi
  int v2; // edi
  CSocketCreator *p_m_Socket; // esi
  char *AcceptedSocketData; // ebx
  netadr_s *AcceptedSocketAddress; // eax
  bool v6; // zf
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *v7; // edi
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v8; // eax
  int v9; // ebx
  int v10; // esi
  char *v11; // edx
  int DataResponseSize; // edi
  char *p_data; // esi
  CRConServer *v14; // edi
  SOCKET v15; // esi
  int v16; // eax
  u_long v17; // edi
  u_long v18; // eax
  void *v19; // esp
  unsigned int v20; // edi
  int v21; // eax
  int v22; // edi
  u_long v23; // eax
  CRConServer *v24; // edi
  int Error; // eax
  const char *v26; // eax
  int Int; // eax
  int SamplePosition; // eax
  int v29; // [esp+0h] [ebp-1064h] BYREF
  char data; // [esp+Ch] [ebp-1058h] BYREF
  CUtlBuffer v31; // [esp+100Ch] [ebp-58h] BYREF
  SOCKET s; // [esp+103Ch] [ebp-28h]
  netadr_s *adr; // [esp+1040h] [ebp-24h]
  char buf; // [esp+1047h] [ebp-1Dh] BYREF
  int len; // [esp+1048h] [ebp-1Ch]
  u_long argp; // [esp+104Ch] [ebp-18h] BYREF
  bool v37; // [esp+1053h] [ebp-11h]
  char *v38; // [esp+1054h] [ebp-10h]
  int bufferSize; // [esp+1058h] [ebp-Ch] BYREF
  CRConServer *pNetworkListener; // [esp+105Ch] [ebp-8h]
  int nIndex; // [esp+1060h] [ebp-4h]

  v1 = this;
  pNetworkListener = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  v1->m_bSocketDeleted = false;
  v2 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v1->m_Socket) - 1;
  nIndex = v2;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      p_m_Socket = &v1->m_Socket;
      AcceptedSocketData = (char *)CSocketCreator::GetAcceptedSocketData(this: p_m_Socket, nIndex: v2);
      v38 = AcceptedSocketData;
      s = CSocketCreator::GetAcceptedSocketHandle(this: p_m_Socket, nIndex: v2);
      AcceptedSocketAddress = (netadr_s *)CSocketCreator::GetAcceptedSocketAddress(this: p_m_Socket, nIndex: v2);
      v6 = *((_WORD *)AcceptedSocketData + 39) == 0;
      adr = AcceptedSocketAddress;
      if ( !v6 )
      {
        v7 = (CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *)(AcceptedSocketData + 60);
        do
        {
          v8 = &v7->m_Memory.m_pMemory[*((unsigned __int16 *)AcceptedSocketData + 36)];
          if ( CRConServer::SendRCONResponse(
                 this: pNetworkListener,
                 nIndex,
                 data: (char *)&v8->m_Element.m_Memory.m_pMemory[v8->m_Element.m_Get - v8->m_Element.m_nOffset],
                 len: v8->m_Element.m_Put - v8->m_Element.m_Get,
                 fromQueue: true) == 0 )
            break;
          v9 = *((unsigned __int16 *)AcceptedSocketData + 36);
          CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
            this: v7,
            elem: v9);
          v10 = (int)&v7->m_Memory.m_pMemory[v9];
          if ( *(int *)(v10 + 8) >= 0 )
          {
            if ( *(_DWORD *)v10 != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v10);
              *(_DWORD *)v10 = 0;
            }
            *(_DWORD *)(v10 + 4) = 0;
          }
          v11 = v38;
          *(_WORD *)(v10 + 50) = v7->m_FirstFree;
          v7->m_FirstFree = v9;
          AcceptedSocketData = v11;
        }
        while ( *((_WORD *)v11 + 39) != 0 );
      }
      DataResponseSize = CServerRemoteAccess::GetDataResponseSize(
                           this: &g_ServerRemoteAccess,
                           listener: *((_DWORD *)AcceptedSocketData + 2));
      if ( DataResponseSize <= 0 )
      {
        v14 = pNetworkListener;
      }
      else
      {
        p_data = &data;
        len = DataResponseSize + 4;
        v37 = (unsigned int)(DataResponseSize + 4) > 0x1000;
        if ( (unsigned int)(DataResponseSize + 4) > 0x1000 )
          p_data = (char *)MemAlloc_Alloc(nSize: DataResponseSize + 4);
        *(_DWORD *)p_data = DataResponseSize;
        CServerRemoteAccess::ReadDataResponse(
          this: &g_ServerRemoteAccess,
          listener: *((_DWORD *)AcceptedSocketData + 2),
          buffer: p_data + 4,
          bufferSize: DataResponseSize);
        v14 = pNetworkListener;
        CRConServer::SendRCONResponse(this: pNetworkListener, nIndex, data: p_data, len, fromQueue: false);
        if ( v37 )
          free(pMem: p_data);
      }
      v15 = s;
      argp = 0;
      v16 = recv(s, &buf, len: 1, flags: 2);
      if ( v16 == -1 )
        break;
      if ( v16 <= 0 )
        goto LABEL_22;
      ioctlsocket(s: v15, cmd: 1074030207, &argp);
      if ( argp > 4 )
      {
        CUtlBuffer::EnsureCapacity(
          this: (CUtlBuffer *)(AcceptedSocketData + 12),
          num: argp + *((_DWORD *)AcceptedSocketData + 7));
        v17 = argp;
        v18 = 1024;
        if ( argp <= 0x400 )
          v18 = argp;
        v19 = alloca(v18);
        len = (int)&v29;
        v38 = nullptr;
        if ( argp != 0 )
        {
          while ( 1 )
          {
            v20 = v17 - (_DWORD)v38;
            if ( v20 > 0x400 )
              v20 = 1024;
            v21 = recv(s, buf: (char *)len, len: v20, flags: 0);
            v22 = v21;
            if ( v21 == 0 )
            {
              v24 = pNetworkListener;
              CSocketCreator::CloseAcceptedSocket(this: &pNetworkListener->m_Socket, nIndex);
              goto LABEL_37;
            }
            if ( v21 < 0 && !SocketWouldBlock() )
              break;
            CUtlBuffer::Put(this: (CUtlBuffer *)(AcceptedSocketData + 12), pMem: (const void *)len, size: v22);
            v23 = (u_long)&v38[v22];
            v17 = argp;
            v38 = (char *)v23;
            if ( v23 >= argp )
              goto LABEL_36;
          }
          Error = WSAGetLastError();
          v26 = NET_ErrorString(code: Error);
          _Warning(a1: "RCON Cmd: recv error (%s)\n", v26);
        }
LABEL_36:
        v24 = pNetworkListener;
LABEL_37:
        CUtlBuffer::SeekGet(this: (CUtlBuffer *)(AcceptedSocketData + 12), type: SEEK_HEAD, offset: 0);
        Int = CUtlBuffer::GetInt(this: (CUtlBuffer *)(AcceptedSocketData + 12));
        bufferSize = Int;
        if ( Int <= 1024 )
        {
          if ( Int > 0 )
          {
            while ( Int <= *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) )
            {
              SV_RedirectStart(rd: RD_SOCKET, addr: adr);
              CServerRemoteAccess::WriteDataRequest(
                this: &g_ServerRemoteAccess,
                pNetworkListener: v24,
                listener: *((_DWORD *)AcceptedSocketData + 2),
                buffer: (const void *)(*((_DWORD *)AcceptedSocketData + 3)
                             + *((_DWORD *)AcceptedSocketData + 6)
                             - *((_DWORD *)AcceptedSocketData + 11)),
                bufferSize);
              SV_RedirectEnd();
              if ( v24->m_bSocketDeleted )
                return;
              CUtlBuffer::SeekGet(this: (CUtlBuffer *)(AcceptedSocketData + 12), type: SEEK_CURRENT, offset: bufferSize);
              if ( (unsigned int)(*((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6)) < 4 )
              {
                bufferSize = 0;
                break;
              }
              Int = CUtlBuffer::GetInt(this: (CUtlBuffer *)(AcceptedSocketData + 12));
              bufferSize = Int;
              if ( Int <= 0 )
                break;
            }
          }
          SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v24->m_Socket);
          if ( SamplePosition == 0
            || nIndex > SamplePosition
            || AcceptedSocketData != CSocketCreator::GetAcceptedSocketData(this: &v24->m_Socket, nIndex) )
          {
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
            return;
          }
          if ( bufferSize > 0 || *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) > 0 )
          {
            CUtlBuffer::CUtlBuffer(this: &v31, growSize: 0, initSize: 0, nFlags: 0);
            if ( *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6) > 0 )
              CUtlBuffer::Put(
                this: &v31,
                pMem: (const void *)(*((_DWORD *)AcceptedSocketData + 3)
                             + *((_DWORD *)AcceptedSocketData + 6)
                             - *((_DWORD *)AcceptedSocketData + 11)),
                size: *((_DWORD *)AcceptedSocketData + 7) - *((_DWORD *)AcceptedSocketData + 6));
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
            if ( bufferSize > 0 )
              CUtlBuffer::Put(this: (CUtlBuffer *)(AcceptedSocketData + 12), pMem: &bufferSize, size: 4);
            if ( v31.m_Put > 0 )
              CUtlBuffer::Put(
                this: (CUtlBuffer *)(AcceptedSocketData + 12),
                pMem: v31.m_Memory.m_pMemory,
                size: v31.m_Put);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &v31);
          }
          else
          {
            CUtlBuffer::Purge(this: (CUtlBuffer *)(AcceptedSocketData + 12));
          }
        }
        else
        {
          CRConServer::HandleFailedRconAuth(this: v24, adr);
          CSocketCreator::CloseAcceptedSocket(this: &v24->m_Socket, nIndex);
        }
      }
LABEL_59:
      if ( --nIndex < 0 )
        return;
      v1 = pNetworkListener;
      v2 = nIndex;
    }
    if ( SocketWouldBlock() )
      goto LABEL_59;
LABEL_22:
    CSocketCreator::CloseAcceptedSocket(this: &v14->m_Socket, nIndex);
    goto LABEL_59;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CE10
// Name: public: virtual void CRPTServer::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTServer::OnSocketAccepted(CRPTServer *this, int hSocket, const netadr_s *netAdr, void **ppData)
{
  CRConServer::OnSocketAccepted(this, hSocket, netAdr, ppData);
  Cmd_SetRptActive(bActive: true);
}

//------------------------------------------------------------------------------
// Address: 0x1012CE40
// Name: public: virtual void CRPTServer::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTServer::OnSocketClosed(
        CRPTServer *this,
        int hSocket,
        const netadr_s *netAdr,
        CRConServer::ConnectedRConSocket_t *pData)
{
  Cmd_SetRptActive(bActive: false);
  this->m_bSocketDeleted = true;
  if ( pData != nullptr )
  {
    CRConServer::ConnectedRConSocket_t::~ConnectedRConSocket_t(this: pData);
    free(pMem: pData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103139B0
// Name: _dynamic_initializer_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_command__()
{
  ConCommand::ConCommand(
    this: &rcon_command,
    pName: "rcon",
    callback: rcon,
    pHelpString: "Issue an rcon command.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rcon_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C30
// Name: _dynamic_initializer_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_address__()
{
  ConVar::ConVar(
    this: &rcon_address,
    pName: "rcon_address",
    pDefaultValue: defaultValue,
    flags: 537001984,
    pHelpString: "Address of remote server if sending unconnected rcon commands (format x.x.x.x:p) ",
    callback: RconAddressChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_address__);
}

//------------------------------------------------------------------------------
// Address: 0x10318780
// Name: _dynamic_initializer_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_password__()
{
  ConVar::ConVar(
    this: &rcon_password,
    pName: "rcon_password",
    pDefaultValue: defaultValue,
    flags: 537526272,
    pHelpString: "remote console password.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))RconPasswordChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_password__);
}

//------------------------------------------------------------------------------
// Address: 0x103229F0
// Name: _dynamic_atexit_destructor_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_command__()
{
  ConCommand::~ConCommand(this: &rcon_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AC0
// Name: _dynamic_atexit_destructor_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_address__()
{
  ConVar::~ConVar(this: &rcon_address);
}

//------------------------------------------------------------------------------
// Address: 0x10324910
// Name: _dynamic_atexit_destructor_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_password__()
{
  ConVar::~ConVar(this: &rcon_password);
}

//------------------------------------------------------------------------------
// Address: 0x103139E0
// Name: _dynamic_initializer_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__box_command__()
{
  ConCommand::ConCommand(
    this: &box_command,
    pName: "box",
    callback: box,
    pHelpString: "Draw a debug box.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__box_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322A00
// Name: _dynamic_atexit_destructor_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__box_command__()
{
  ConCommand::~ConCommand(this: &box_command);
}

} // namespace engine_xlsp
