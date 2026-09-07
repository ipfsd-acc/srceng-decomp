// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/xlspmastertest/mastertest.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004014C0
// Name: char __near * Sys_AdrToString(struct sockaddr_in __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_AdrToString(sockaddr_in *pAddress, char *pString, int nStringSize)
{
  int v3; // ecx

  v3 = ntohs(netshort: pAddress->sin_port);
  V_snprintf(
    pDest: pString,
    maxLen: nStringSize,
    pFormat: "%i.%i.%i.%i:%i",
    pAddress->sin_addr.S_un.S_un_b.s_b1,
    pAddress->sin_addr.S_un.S_un_b.s_b2,
    pAddress->sin_addr.S_un.S_un_b.s_b3,
    pAddress->sin_addr.S_un.S_un_b.s_b4,
    v3);
  return pString;
}

//------------------------------------------------------------------------------
// Address: 0x00401510
// Name: bool NET_StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToSockaddr(const char *s, sockaddr *sadr)
{
  char v2; // al
  char *v3; // esi
  u_short v4; // ax
  unsigned int v5; // eax
  struct hostent *v7; // eax
  char copy[128]; // [esp+4h] [ebp-80h] BYREF

  *(_QWORD *)&sadr->sa_family = 0;
  *(_QWORD *)&sadr->sa_data[6] = 0;
  *(_DWORD *)&sadr->sa_family = 2;
  strcpy(copy, s);
  v2 = copy[0];
  v3 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v3 == 58 )
      {
        *v3 = 0;
        v4 = atoi(nptr: v3 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v4);
      }
      ++v3;
    }
    while ( *v3 != 0 );
    v2 = copy[0];
  }
  if ( (unsigned __int8)(v2 - 49) > 8u )
  {
    v7 = gethostbyname(name: copy);
    if ( v7 == nullptr )
      return 0;
    *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v7->h_addr_list;
  }
  else
  {
    v5 = inet_addr(cp: copy);
    *(_DWORD *)&sadr->sa_data[2] = v5;
    if ( v5 == -1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004015C0
// Name: void NET_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Init()
{
  int v0; // eax
  const char *v1; // eax
  char *v2; // eax
  int v3; // esi
  int *v4; // eax
  const char *v5; // eax
  int Error; // [esp-Ch] [ebp-1ACh]
  int v7; // [esp-4h] [ebp-1A4h]
  WSAData wsaData; // [esp+0h] [ebp-1A0h] BYREF
  sockaddr_in address; // [esp+190h] [ebp-10h] BYREF

  v0 = WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData);
  if ( v0 != 0 )
  {
    v7 = v0;
    v1 = strerror(errnum: v0);
    _Error(a1: "NET_Init: socket: %s %i", v1, v7);
  }
  else
  {
    g_net_socket = socket(af: 2, type: 2, protocol: 17);
    if ( g_net_socket == -1 )
    {
      Error = WSAGetLastError();
      v2 = strerror(errnum: Error);
      _Error(a1: "NET_Init: socket: %s %i", v2, Error);
    }
    address.sin_family = 2;
    address.sin_addr.S_un.S_addr = 0;
    address.sin_port = htons(hostshort: g_net_hostport);
    if ( bind(s: g_net_socket, name: (const struct sockaddr *)&address, namelen: 16) == -1 )
    {
      v3 = WSAGetLastError();
      v4 = _errno();
      v5 = strerror(errnum: *v4);
      _Error(a1: "NET_Init: bind to %i failed: %s %i", g_net_hostport, v5, v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016A0
// Name: void NET_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Shutdown()
{
  if ( g_net_socket != 0 )
    closesocket(s: g_net_socket);
}

//------------------------------------------------------------------------------
// Address: 0x004016C0
// Name: void Sys_SendPacket(struct sockaddr_in __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SendPacket(sockaddr_in *to, unsigned __int8 *data, unsigned int len)
{
  DWORD v3; // eax
  int *v4; // esi
  int *v5; // esi
  int *v6; // edi
  const char *v7; // eax
  _WSABUF buffers[2]; // [esp+0h] [ebp-14h] BYREF
  unsigned int nSend; // [esp+10h] [ebp-4h] BYREF

  nSend = 0;
  if ( g_bPureUDP )
  {
    buffers[0].len = len;
    buffers[0].buf = (char *)data;
    v3 = 1;
  }
  else
  {
    buffers[0].buf = (char *)&len;
    v3 = 2;
    buffers[0].len = 2;
    buffers[1].len = len;
    buffers[1].buf = (char *)data;
  }
  if ( WSASendTo(
         s: g_net_socket,
         lpBuffers: buffers,
         dwBufferCount: v3,
         lpNumberOfBytesSent: &nSend,
         dwFlags: 0,
         lpTo: (const struct sockaddr *)to,
         iTolen: 16,
         lpOverlapped: nullptr,
         lpCompletionRoutine: nullptr) == -1 )
  {
    v4 = _errno();
    *v4 = WSAGetLastError();
    v5 = _errno();
    v6 = _errno();
    v7 = strerror(errnum: *v5);
    _Msg(a1: "ERROR: Sys_SendPacket: ( %i ) %s\r\n", *v6, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: bool Sys_GetPacket(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Sys_GetPacket(unsigned int timeout)
{
  int v1; // eax
  int Error; // eax
  const char *v3; // eax
  timeval tv; // [esp+8h] [ebp-10h] BYREF
  int fromlen; // [esp+10h] [ebp-8h] BYREF
  unsigned int startTime; // [esp+14h] [ebp-4h]

  startTime = _Plat_MSTime();
  g_msg_readcount = 0;
  do
  {
    if ( _Plat_MSTime() - startTime >= timeout )
      return 0;
    g_fdset.fd_array[0] = g_net_socket;
    g_fdset.fd_count = 1;
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
  }
  while ( select(nfds: 0, readfds: &g_fdset, writefds: nullptr, exceptfds: nullptr, timeout: &tv) == -1
       || __WSAFDIsSet(fd: g_net_socket, a2: &g_fdset) == 0 );
  fromlen = 16;
  v1 = recvfrom(
         s: g_net_socket,
         buf: (char *)g_Incoming,
         len: 0x10000,
         flags: 0,
         from: (struct sockaddr *)&g_packet_from,
         &fromlen);
  g_packet_length = v1;
  if ( v1 == -1 )
  {
    Error = WSAGetLastError();
    v3 = strerror(errnum: Error);
    _Msg(a1: "ERROR: GetPacketCommand: %s\n", v3);
    return 0;
  }
  g_Incoming[v1] = 0;
  if ( !g_bPureUDP )
    g_msg_readcount = 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401860
// Name: bool MasterPing(struct sockaddr_in __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MasterPing(sockaddr_in *pMasterAdr, bool bStressTest)
{
  u_short v2; // ax
  int v3; // eax
  double v4; // st7
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v9; // esi
  int v10; // esi
  unsigned int m_nInBufWord; // ebx
  int v12; // edi
  unsigned int v13; // esi
  unsigned __int8 v14; // bl
  unsigned int v15; // esi
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned int v18; // ebx
  unsigned int v19; // esi
  int v20; // edi
  char v21; // bl
  unsigned int v22; // esi
  unsigned int v23; // eax
  char szAddress[64]; // [esp+10h] [ebp-7Ch] BYREF
  bf_read inbuf; // [esp+50h] [ebp-3Ch] BYREF
  bf_write outbuf; // [esp+74h] [ebp-18h] BYREF
  unsigned int bStressTesta; // [esp+98h] [ebp+Ch]

  v2 = ntohs(netshort: pMasterAdr->sin_port);
  V_snprintf(
    pDest: szAddress,
    maxLen: 64,
    pFormat: "%i.%i.%i.%i:%i",
    pMasterAdr->sin_addr.S_un.S_un_b.s_b1,
    pMasterAdr->sin_addr.S_un.S_un_b.s_b2,
    pMasterAdr->sin_addr.S_un.S_un_b.s_b3,
    pMasterAdr->sin_addr.S_un.S_un_b.s_b4,
    v2);
  bf_write::bf_write(this: &outbuf, pDebugName: "Ping", pData: g_Outgoing, nBytes: 1400, nBits: -1);
  bf_write::WriteByte(this: &outbuf, val: 0x69u);
  bf_write::WriteByte(this: &outbuf, val: 0xAu);
  bf_write::WriteLong(this: &outbuf, val: 0);
  Sys_SendPacket(to: pMasterAdr, data: (unsigned __int8 *)g_Outgoing, len: (outbuf.m_iCurBit + 7) >> 3);
  if ( bStressTest )
  {
    v3 = 1000 * (++s_count / 1000);
    if ( s_count == v3 )
    {
      v4 = _Plat_FloatTime(a1: s_count - v3);
      _Msg(a1: "%d pings at %f\n", s_count, v4);
      return 1;
    }
    return 1;
  }
  if ( Sys_GetPacket(timeout: 0xBB8u) == 0 )
  {
    _Msg(a1: "No response from Master: %s\n", szAddress);
    return 0;
  }
  inbuf.m_bOverflow = false;
  inbuf.m_pDebugName = nullptr;
  inbuf.m_nDataBits = -1;
  inbuf.m_nDataBytes = 0;
  CBitRead::StartReading(this: &inbuf, pData: g_Incoming, nBytes: 0x10000, iStartBit: 0, nBits: -1);
  m_nBitsAvail = inbuf.m_nBitsAvail;
  m_pDataIn = inbuf.m_pDataIn;
  if ( g_bPureUDP )
    goto LABEL_43;
  if ( inbuf.m_nBitsAvail < 8 )
  {
    v9 = 8 - inbuf.m_nBitsAvail;
    if ( inbuf.m_pDataIn == inbuf.m_pBufferEnd )
    {
      m_nBitsAvail = 1;
      m_pDataIn = inbuf.m_pDataIn + 1;
      inbuf.m_nBitsAvail = 1;
      inbuf.m_nInBufWord = 0;
      ++inbuf.m_pDataIn;
      inbuf.m_bOverflow = true;
LABEL_17:
      m_pBufferEnd = inbuf.m_pBufferEnd;
      goto LABEL_18;
    }
    if ( inbuf.m_pDataIn <= inbuf.m_pBufferEnd )
    {
      m_pDataIn = inbuf.m_pDataIn + 1;
      inbuf.m_nInBufWord = *inbuf.m_pDataIn++;
      if ( !inbuf.m_bOverflow )
      {
        m_nBitsAvail = 32 - v9;
        inbuf.m_nInBufWord >>= v9;
        inbuf.m_nBitsAvail = 32 - v9;
      }
    }
    else
    {
      inbuf.m_bOverflow = true;
      inbuf.m_nInBufWord = 0;
    }
LABEL_30:
    if ( m_nBitsAvail >= 8 )
    {
      m_pBufferEnd = inbuf.m_pBufferEnd;
LABEL_32:
      m_nBitsAvail -= 8;
      inbuf.m_nBitsAvail = m_nBitsAvail;
      if ( m_nBitsAvail == 0 )
      {
        m_nBitsAvail = 32;
        inbuf.m_nBitsAvail = 32;
        if ( m_pDataIn != m_pBufferEnd )
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            v16 = *m_pDataIn++;
            inbuf.m_nInBufWord = v16;
            inbuf.m_pDataIn = m_pDataIn;
          }
          else
          {
            inbuf.m_bOverflow = true;
            inbuf.m_nInBufWord = 0;
          }
          goto LABEL_45;
        }
        m_nBitsAvail = 1;
        ++m_pDataIn;
        inbuf.m_nBitsAvail = 1;
        inbuf.m_nInBufWord = 0;
        inbuf.m_pDataIn = m_pDataIn;
LABEL_20:
        m_nInBufWord = inbuf.m_nInBufWord;
        v12 = 32 - m_nBitsAvail;
        if ( m_pDataIn == m_pBufferEnd )
        {
          inbuf.m_nBitsAvail = 1;
          inbuf.m_nInBufWord = 0;
          inbuf.m_pDataIn = m_pDataIn + 1;
          inbuf.m_bOverflow = true;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          v19 = *m_pDataIn++;
          inbuf.m_nInBufWord = v19;
          inbuf.m_pDataIn = m_pDataIn;
          if ( !inbuf.m_bOverflow )
          {
            bStressTesta = v19 & CBitBuffer::s_nMaskTable[v12];
            v13 = v19 >> v12;
            m_pBufferEnd = inbuf.m_pBufferEnd;
            v18 = (bStressTesta << m_nBitsAvail) | m_nInBufWord;
            inbuf.m_nBitsAvail = m_nBitsAvail;
            goto LABEL_56;
          }
        }
        else
        {
          inbuf.m_bOverflow = true;
          inbuf.m_nInBufWord = 0;
        }
LABEL_22:
        _Msg(a1: "Unexpected repsonse from Master: %s\n", szAddress);
        m_pDataIn = inbuf.m_pDataIn;
        m_nBitsAvail = inbuf.m_nBitsAvail;
        v13 = inbuf.m_nInBufWord;
        m_pBufferEnd = inbuf.m_pBufferEnd;
        goto LABEL_23;
      }
      inbuf.m_nInBufWord >>= 8;
      goto LABEL_44;
    }
    goto LABEL_17;
  }
  m_nBitsAvail = inbuf.m_nBitsAvail - 8;
  inbuf.m_nBitsAvail = m_nBitsAvail;
  if ( m_nBitsAvail != 0 )
  {
    inbuf.m_nInBufWord >>= 8;
    goto LABEL_30;
  }
  m_pBufferEnd = inbuf.m_pBufferEnd;
  m_nBitsAvail = 32;
  inbuf.m_nBitsAvail = 32;
  if ( inbuf.m_pDataIn != inbuf.m_pBufferEnd )
  {
    if ( inbuf.m_pDataIn <= inbuf.m_pBufferEnd )
    {
      m_pDataIn = inbuf.m_pDataIn + 1;
      inbuf.m_nInBufWord = *inbuf.m_pDataIn++;
    }
    else
    {
      inbuf.m_bOverflow = true;
      inbuf.m_nInBufWord = 0;
    }
    goto LABEL_32;
  }
  m_nBitsAvail = 1;
  m_pDataIn = inbuf.m_pDataIn + 1;
  inbuf.m_nBitsAvail = 1;
  inbuf.m_nInBufWord = 0;
  ++inbuf.m_pDataIn;
LABEL_18:
  v10 = 8 - m_nBitsAvail;
  if ( m_pDataIn == m_pBufferEnd )
  {
    m_nBitsAvail = 1;
    ++m_pDataIn;
    inbuf.m_nBitsAvail = 1;
    inbuf.m_nInBufWord = 0;
    inbuf.m_pDataIn = m_pDataIn;
    inbuf.m_bOverflow = true;
    goto LABEL_20;
  }
  if ( m_pDataIn > m_pBufferEnd )
  {
    inbuf.m_bOverflow = true;
    inbuf.m_nInBufWord = 0;
    goto LABEL_44;
  }
  v17 = *m_pDataIn++;
  inbuf.m_nInBufWord = v17;
  inbuf.m_pDataIn = m_pDataIn;
  if ( !inbuf.m_bOverflow )
  {
    m_nBitsAvail = 32 - v10;
    inbuf.m_nInBufWord >>= v10;
    inbuf.m_nBitsAvail = 32 - v10;
LABEL_43:
    m_pBufferEnd = inbuf.m_pBufferEnd;
  }
LABEL_44:
  if ( m_nBitsAvail < 32 )
    goto LABEL_20;
LABEL_45:
  v18 = inbuf.m_nInBufWord;
  m_nBitsAvail -= 32;
  inbuf.m_nBitsAvail = m_nBitsAvail;
  if ( m_nBitsAvail != 0 )
  {
    v13 = 0;
  }
  else
  {
    m_nBitsAvail = 32;
    inbuf.m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      v13 = 0;
      m_nBitsAvail = 1;
      ++m_pDataIn;
      inbuf.m_nBitsAvail = 1;
      inbuf.m_pDataIn = m_pDataIn;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      v13 = *m_pDataIn++;
      inbuf.m_pDataIn = m_pDataIn;
    }
    else
    {
      inbuf.m_bOverflow = true;
      v13 = 0;
    }
  }
LABEL_56:
  inbuf.m_nInBufWord = v13;
  if ( v18 != -1 )
    goto LABEL_22;
LABEL_23:
  if ( m_nBitsAvail < 8 )
  {
    v20 = 8 - m_nBitsAvail;
    v21 = v13;
    if ( m_pDataIn == inbuf.m_pBufferEnd )
    {
      inbuf.m_nBitsAvail = 1;
      inbuf.m_nInBufWord = 0;
      inbuf.m_pDataIn = m_pDataIn + 1;
      inbuf.m_bOverflow = true;
      v14 = 0;
    }
    else if ( m_pDataIn <= inbuf.m_pBufferEnd )
    {
      v22 = *m_pDataIn;
      inbuf.m_nInBufWord = *m_pDataIn;
      inbuf.m_pDataIn = m_pDataIn + 1;
      if ( !inbuf.m_bOverflow )
      {
        v23 = (v22 & CBitBuffer::s_nMaskTable[v20]) << m_nBitsAvail;
        inbuf.m_nBitsAvail = 32 - v20;
        v14 = v23 | v21;
        v15 = v22 >> v20;
        goto LABEL_70;
      }
      v14 = 0;
    }
    else
    {
      inbuf.m_bOverflow = true;
      inbuf.m_nInBufWord = 0;
      v14 = 0;
    }
LABEL_72:
    _Msg(a1: "Unexpected repsonse '%c' from Master: %s\n", v14, szAddress);
    goto LABEL_73;
  }
  v14 = v13;
  inbuf.m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail != 8 )
  {
    v15 = v13 >> 8;
LABEL_70:
    inbuf.m_nInBufWord = v15;
    goto LABEL_71;
  }
  inbuf.m_nBitsAvail = 32;
  if ( m_pDataIn == m_pBufferEnd )
  {
    inbuf.m_nBitsAvail = 1;
    inbuf.m_nInBufWord = 0;
    inbuf.m_pDataIn = m_pDataIn + 1;
  }
  else if ( m_pDataIn <= m_pBufferEnd )
  {
    inbuf.m_nInBufWord = *m_pDataIn;
    inbuf.m_pDataIn = m_pDataIn + 1;
  }
  else
  {
    inbuf.m_bOverflow = true;
    inbuf.m_nInBufWord = 0;
  }
LABEL_71:
  if ( v14 != 106 )
    goto LABEL_72;
LABEL_73:
  _Msg(a1: "Ping ACK received from Master %s\n", szAddress);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401D10
// Name: bool MasterList(struct sockaddr_in __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MasterList(sockaddr_in *pMasterAdr, bool bStressTest)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  bool v13; // bl
  bool v14; // al
  unsigned int v15; // edi
  u_short v16; // ax
  const unsigned int *m_pBufferEnd; // edi
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  int v20; // esi
  unsigned int v21; // ebx
  int v22; // esi
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  unsigned int v25; // esi
  unsigned int m_nInBufWord; // ebx
  unsigned int v27; // esi
  unsigned __int8 v28; // cl
  int v29; // edx
  unsigned int v30; // esi
  int v31; // edi
  unsigned int v32; // ebx
  unsigned int v33; // esi
  int v34; // ebx
  const unsigned int *v35; // ebx
  unsigned int v36; // esi
  unsigned int v37; // ebx
  int v38; // esi
  int v39; // edi
  unsigned int v40; // ecx
  unsigned int v41; // esi
  unsigned int v42; // edi
  const unsigned int *v43; // edx
  unsigned __int16 v44; // ax
  unsigned int v45; // ecx
  __int16 v46; // si
  int v47; // eax
  unsigned int v48; // ecx
  unsigned int v49; // ebx
  char v50; // bl
  const char *v51; // ebx
  const char *v52; // esi
  int v53; // eax
  int v54; // edi
  int v55; // eax
  int v56; // eax
  double v57; // st7
  float v59; // xmm0_4
  char pStr[2048]; // [esp+4Ch] [ebp-109Ch] BYREF
  char s[2048]; // [esp+84Ch] [ebp-89Ch] BYREF
  char pDest[64]; // [esp+104Ch] [ebp-9Ch] BYREF
  bf_write v63; // [esp+108Ch] [ebp-5Ch] BYREF
  unsigned int v64; // [esp+10A4h] [ebp-44h]
  int v65; // [esp+10A8h] [ebp-40h]
  int v66; // [esp+10ACh] [ebp-3Ch]
  int v67; // [esp+10B0h] [ebp-38h]
  char v68; // [esp+10B6h] [ebp-32h]
  char v69; // [esp+10B7h] [ebp-31h]
  unsigned int v70; // [esp+10B8h] [ebp-30h]
  char v71; // [esp+10BEh] [ebp-2Ah]
  bool v72; // [esp+10BFh] [ebp-29h]
  CBitRead v73; // [esp+10C0h] [ebp-28h] BYREF
  bool v74; // [esp+10E7h] [ebp-1h]

  v70 = 0;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-details", a3: 0) != 0
    || (v3 = _CommandLine(),
        v4 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-d", a3: 0),
        v71 = 0,
        v4 != 0) )
  {
    v71 = 1;
  }
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-empty", a3: 0) != 0
    || (v6 = _CommandLine(),
        v7 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-e", a3: 0),
        v68 = 0,
        v7 != 0) )
  {
    v68 = 1;
  }
  v8 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-full", a3: 0) != 0
    || (v9 = _CommandLine(),
        v10 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-f", a3: 0),
        v69 = 0,
        v10 != 0) )
  {
    v69 = 1;
  }
  v11 = _CommandLine();
  v13 = true;
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(a1: v11, a2: "-totals", a3: 0) == 0 )
  {
    v12 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-t", a3: 0) == 0 )
      v13 = false;
  }
  v74 = v13;
  v14 = v71 != 0 || v13;
  v15 = v14 ? 0x80000000 : 0;
  v72 = v14;
  v67 = 0;
  v65 = 0;
  v66 = 0;
  v64 = v15;
  while ( 2 )
  {
    v16 = ntohs(netshort: pMasterAdr->sin_port);
    V_snprintf(
      pDest,
      maxLen: 64,
      pFormat: "%i.%i.%i.%i:%i",
      pMasterAdr->sin_addr.S_un.S_un_b.s_b1,
      pMasterAdr->sin_addr.S_un.S_un_b.s_b2,
      pMasterAdr->sin_addr.S_un.S_un_b.s_b3,
      pMasterAdr->sin_addr.S_un.S_un_b.s_b4,
      v16);
    bf_write::bf_write(this: &v63, pDebugName: "RequestBatch", pData: g_Outgoing, nBytes: 1400, nBits: -1);
    bf_write::WriteByte(this: &v63, val: 0x31u);
    bf_write::WriteByte(this: &v63, val: 0xAu);
    bf_write::WriteLong(this: &v63, val: v70 | v15);
    bf_write::WriteLong(this: &v63, val: 0);
    s[0] = 0;
    if ( !v13 )
    {
      if ( v68 != 0 )
      {
        Info_SetValueForKey(s, key: "empty", value: "1", maxsize: 2048);
        Info_SetValueForKey(s, key: "private", value: "L4D360-rc3", maxsize: 2048);
      }
      else if ( v69 != 0 )
      {
        Info_SetValueForKey(s, key: "full", value: "1", maxsize: 2048);
        Info_SetValueForKey(s, key: "private", value: "L4D360-rc3", maxsize: 2048);
      }
    }
    bf_write::WriteString(this: &v63, pStr: s);
    bf_write::WriteByte(this: &v63, val: 0xAu);
    Sys_SendPacket(to: pMasterAdr, data: (unsigned __int8 *)g_Outgoing, len: (v63.m_iCurBit + 7) >> 3);
    if ( bStressTest )
    {
      v56 = 1000 * (++s_count / 1000);
      if ( s_count != v56 )
        return 1;
      v57 = _Plat_FloatTime(a1: s_count - v56);
      _Msg(a1: "%d list req at %f\n", s_count, v57);
      return 1;
    }
    if ( v13 )
      _Msg(a1: "Servers: %4d Humans: %4d Bots: %4d\n", v66, v67, v65);
    else
      _Msg(a1: "\nServers: (startID:%d)\n", v70);
    if ( Sys_GetPacket(timeout: 0xBB8u) == 0 )
    {
      _Msg(a1: "No response from Master: %s\n", pDest);
      return 0;
    }
    v73.m_bOverflow = false;
    v73.m_pDebugName = nullptr;
    v73.m_nDataBits = -1;
    v73.m_nDataBytes = 0;
    CBitRead::StartReading(this: &v73, pData: g_Incoming, nBytes: 0x10000, iStartBit: 0, nBits: -1);
    m_pBufferEnd = v73.m_pBufferEnd;
    m_nBitsAvail = v73.m_nBitsAvail;
    m_pDataIn = v73.m_pDataIn;
    if ( g_bPureUDP )
    {
LABEL_60:
      if ( m_nBitsAvail >= 32 )
        goto LABEL_61;
      goto LABEL_37;
    }
    if ( v73.m_nBitsAvail < 8 )
    {
      v22 = 8 - v73.m_nBitsAvail;
      if ( v73.m_pDataIn == v73.m_pBufferEnd )
      {
        m_nBitsAvail = 1;
        m_pDataIn = v73.m_pDataIn + 1;
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        ++v73.m_pDataIn;
        v73.m_bOverflow = true;
        goto LABEL_35;
      }
      if ( v73.m_pDataIn <= v73.m_pBufferEnd )
      {
        m_pDataIn = v73.m_pDataIn + 1;
        v73.m_nInBufWord = *v73.m_pDataIn++;
        if ( !v73.m_bOverflow )
        {
          m_nBitsAvail = 32 - v22;
          v73.m_nInBufWord >>= v22;
          v73.m_nBitsAvail = 32 - v22;
        }
      }
      else
      {
        v73.m_bOverflow = true;
        v73.m_nInBufWord = 0;
      }
      goto LABEL_48;
    }
    m_nBitsAvail = v73.m_nBitsAvail - 8;
    v73.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      v73.m_nInBufWord >>= 8;
LABEL_48:
      if ( m_nBitsAvail >= 8 )
        goto LABEL_49;
LABEL_35:
      v20 = 8 - m_nBitsAvail;
      if ( m_pDataIn == v73.m_pBufferEnd )
      {
        m_nBitsAvail = 1;
        ++m_pDataIn;
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        v73.m_pDataIn = m_pDataIn;
        v73.m_bOverflow = true;
        goto LABEL_37;
      }
      if ( m_pDataIn <= v73.m_pBufferEnd )
      {
        v24 = *m_pDataIn++;
        v73.m_nInBufWord = v24;
        v73.m_pDataIn = m_pDataIn;
        if ( !v73.m_bOverflow )
        {
          m_nBitsAvail = 32 - v20;
          v73.m_nInBufWord >>= v20;
          v73.m_nBitsAvail = 32 - v20;
        }
      }
      else
      {
        v73.m_bOverflow = true;
        v73.m_nInBufWord = 0;
      }
      goto LABEL_60;
    }
    m_nBitsAvail = 32;
    v73.m_nBitsAvail = 32;
    if ( v73.m_pDataIn == v73.m_pBufferEnd )
    {
      m_nBitsAvail = 1;
      m_pDataIn = v73.m_pDataIn + 1;
      v73.m_nBitsAvail = 1;
      v73.m_nInBufWord = 0;
      ++v73.m_pDataIn;
      goto LABEL_35;
    }
    if ( v73.m_pDataIn <= v73.m_pBufferEnd )
    {
      m_pDataIn = v73.m_pDataIn + 1;
      v73.m_nInBufWord = *v73.m_pDataIn++;
    }
    else
    {
      v73.m_bOverflow = true;
      v73.m_nInBufWord = 0;
    }
LABEL_49:
    m_nBitsAvail -= 8;
    v73.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      v73.m_nInBufWord >>= 8;
      goto LABEL_60;
    }
    m_nBitsAvail = 32;
    v73.m_nBitsAvail = 32;
    if ( m_pDataIn != v73.m_pBufferEnd )
    {
      if ( m_pDataIn <= v73.m_pBufferEnd )
      {
        v23 = *m_pDataIn++;
        v73.m_nInBufWord = v23;
        v73.m_pDataIn = m_pDataIn;
      }
      else
      {
        v73.m_bOverflow = true;
        v73.m_nInBufWord = 0;
      }
LABEL_61:
      m_nBitsAvail -= 32;
      v73.m_nBitsAvail = m_nBitsAvail;
      if ( m_nBitsAvail != 0 )
      {
        v25 = 0;
        m_nInBufWord = v73.m_nInBufWord;
      }
      else
      {
        m_nBitsAvail = 32;
        v73.m_nBitsAvail = 32;
        if ( m_pDataIn == v73.m_pBufferEnd )
        {
          v25 = 0;
          m_nBitsAvail = 1;
          ++m_pDataIn;
          v73.m_nBitsAvail = 1;
          v73.m_pDataIn = m_pDataIn;
          m_nInBufWord = v73.m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= v73.m_pBufferEnd )
          {
            v25 = *m_pDataIn++;
            v73.m_pDataIn = m_pDataIn;
          }
          else
          {
            v73.m_bOverflow = true;
            v25 = 0;
          }
          m_nInBufWord = v73.m_nInBufWord;
        }
      }
LABEL_73:
      v73.m_nInBufWord = v25;
      if ( m_nInBufWord == -1 )
        goto LABEL_75;
      goto LABEL_74;
    }
    m_nBitsAvail = 1;
    ++m_pDataIn;
    v73.m_nBitsAvail = 1;
    v73.m_nInBufWord = 0;
    v73.m_pDataIn = m_pDataIn;
LABEL_37:
    v21 = v73.m_nInBufWord;
    if ( m_pDataIn == v73.m_pBufferEnd )
    {
      v73.m_nBitsAvail = 1;
      v73.m_nInBufWord = 0;
      v73.m_pDataIn = m_pDataIn + 1;
      v73.m_bOverflow = true;
    }
    else if ( m_pDataIn <= v73.m_pBufferEnd )
    {
      v27 = *m_pDataIn++;
      v73.m_nInBufWord = v27;
      v73.m_pDataIn = m_pDataIn;
      if ( !v73.m_bOverflow )
      {
        v70 = v27 & CBitBuffer::s_nMaskTable[32 - m_nBitsAvail];
        m_nInBufWord = (v70 << m_nBitsAvail) | v21;
        m_pBufferEnd = v73.m_pBufferEnd;
        v73.m_nBitsAvail = m_nBitsAvail;
        v25 = v27 >> (32 - m_nBitsAvail);
        goto LABEL_73;
      }
    }
    else
    {
      v73.m_bOverflow = true;
      v73.m_nInBufWord = 0;
    }
LABEL_74:
    _Msg(a1: "Unexpected repsonse from Master: %s\n", pDest);
    m_pBufferEnd = v73.m_pBufferEnd;
    m_pDataIn = v73.m_pDataIn;
    m_nBitsAvail = v73.m_nBitsAvail;
    v25 = v73.m_nInBufWord;
LABEL_75:
    if ( m_nBitsAvail >= 8 )
    {
      v28 = v25;
      v29 = m_nBitsAvail - 8;
      v73.m_nBitsAvail = v29;
      if ( v29 != 0 )
      {
        v30 = v25 >> 8;
      }
      else
      {
        v29 = 32;
        v73.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          v30 = 0;
          v29 = 1;
          ++m_pDataIn;
          v73.m_nBitsAvail = 1;
          v73.m_pDataIn = m_pDataIn;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          v30 = *m_pDataIn++;
          v73.m_pDataIn = m_pDataIn;
        }
        else
        {
          v73.m_bOverflow = true;
          v30 = 0;
        }
      }
LABEL_90:
      v73.m_nInBufWord = v30;
      if ( v28 == 102 )
        goto LABEL_92;
      goto LABEL_91;
    }
    v31 = 8 - m_nBitsAvail;
    v32 = v25;
    if ( m_pDataIn == v73.m_pBufferEnd )
    {
      v73.m_nBitsAvail = 1;
      v73.m_nInBufWord = 0;
      v73.m_pDataIn = m_pDataIn + 1;
      v73.m_bOverflow = true;
      v28 = 0;
    }
    else if ( m_pDataIn <= v73.m_pBufferEnd )
    {
      v33 = *m_pDataIn++;
      v73.m_nInBufWord = v33;
      v73.m_pDataIn = m_pDataIn;
      if ( !v73.m_bOverflow )
      {
        v70 = v33 & CBitBuffer::s_nMaskTable[v31];
        v34 = (v70 << m_nBitsAvail) | v32;
        v29 = 32 - v31;
        v30 = v33 >> v31;
        v73.m_nBitsAvail = 32 - v31;
        v28 = v34;
        goto LABEL_90;
      }
      v28 = 0;
    }
    else
    {
      v73.m_bOverflow = true;
      v73.m_nInBufWord = 0;
      v28 = 0;
    }
LABEL_91:
    _Msg(a1: "Unexpected repsonse '%c' from Master: %s\n", v28, pDest);
    m_pDataIn = v73.m_pDataIn;
    v29 = v73.m_nBitsAvail;
    v30 = v73.m_nInBufWord;
LABEL_92:
    v35 = v73.m_pBufferEnd;
    if ( v29 < 8 )
    {
      v39 = 8 - v29;
      if ( m_pDataIn == v73.m_pBufferEnd )
      {
        v36 = 0;
        v29 = 1;
        ++m_pDataIn;
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        v73.m_pDataIn = m_pDataIn;
        v73.m_bOverflow = true;
        goto LABEL_97;
      }
      if ( m_pDataIn <= v73.m_pBufferEnd )
      {
        v36 = *m_pDataIn++;
        v73.m_nInBufWord = v36;
        v73.m_pDataIn = m_pDataIn;
        if ( v73.m_bOverflow )
          goto LABEL_109;
        v29 = 32 - v39;
        v73.m_nBitsAvail = 32 - v39;
        v36 >>= v39;
      }
      else
      {
        v73.m_bOverflow = true;
        v36 = 0;
      }
LABEL_108:
      v73.m_nInBufWord = v36;
LABEL_109:
      if ( v29 >= 32 )
        goto LABEL_110;
LABEL_97:
      v37 = v36;
      v38 = 32 - v29;
      if ( m_pDataIn == v73.m_pBufferEnd )
      {
        v29 = 1;
        ++m_pDataIn;
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        v73.m_pDataIn = m_pDataIn;
        v73.m_bOverflow = true;
        v70 = 0;
      }
      else if ( m_pDataIn <= v73.m_pBufferEnd )
      {
        v42 = *m_pDataIn++;
        v73.m_nInBufWord = v42;
        v73.m_pDataIn = m_pDataIn;
        if ( v73.m_bOverflow )
        {
          v70 = 0;
        }
        else
        {
          v70 = v42 & CBitBuffer::s_nMaskTable[v38];
          v73.m_nBitsAvail = v29;
          v70 = (v70 << v29) | v37;
          v73.m_nInBufWord = v42 >> v38;
        }
      }
      else
      {
        v73.m_bOverflow = true;
        v73.m_nInBufWord = 0;
        v70 = 0;
      }
      v35 = v73.m_pBufferEnd;
      goto LABEL_124;
    }
    v29 -= 8;
    v73.m_nBitsAvail = v29;
    if ( v29 != 0 )
    {
      v36 = v30 >> 8;
      goto LABEL_108;
    }
    v29 = 32;
    v73.m_nBitsAvail = 32;
    if ( m_pDataIn == v73.m_pBufferEnd )
    {
      v36 = 0;
      v29 = 1;
      ++m_pDataIn;
      v73.m_nBitsAvail = 1;
      v73.m_nInBufWord = 0;
      v73.m_pDataIn = m_pDataIn;
      goto LABEL_97;
    }
    if ( m_pDataIn <= v73.m_pBufferEnd )
    {
      v36 = *m_pDataIn++;
      v73.m_nInBufWord = v36;
      v73.m_pDataIn = m_pDataIn;
    }
    else
    {
      v36 = 0;
      v73.m_bOverflow = true;
      v73.m_nInBufWord = 0;
    }
LABEL_110:
    v40 = v36;
    v29 -= 32;
    v73.m_nBitsAvail = v29;
    if ( v29 != 0 )
    {
      v73.m_nInBufWord = 0;
      v70 = v36;
    }
    else
    {
      v29 = 32;
      v73.m_nBitsAvail = 32;
      if ( m_pDataIn == v73.m_pBufferEnd )
      {
        v29 = 1;
        ++m_pDataIn;
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        v73.m_pDataIn = m_pDataIn;
        v70 = v36;
      }
      else
      {
        if ( m_pDataIn <= v73.m_pBufferEnd )
        {
          v41 = *m_pDataIn++;
          v73.m_nInBufWord = v41;
          v73.m_pDataIn = m_pDataIn;
        }
        else
        {
          v73.m_bOverflow = true;
          v73.m_nInBufWord = 0;
        }
        v70 = v40;
      }
    }
LABEL_124:
    if ( v29 < 32 )
    {
      if ( m_pDataIn == v35 )
      {
        v73.m_nBitsAvail = 1;
        v73.m_nInBufWord = 0;
        v73.m_pDataIn = m_pDataIn + 1;
        v73.m_bOverflow = true;
      }
      else if ( m_pDataIn <= v35 )
      {
        v73.m_nInBufWord = *m_pDataIn;
        v73.m_pDataIn = m_pDataIn + 1;
        if ( !v73.m_bOverflow )
        {
          v73.m_nInBufWord >>= 32 - v29;
          v73.m_nBitsAvail = v29;
        }
      }
      else
      {
        v73.m_bOverflow = true;
        v73.m_nInBufWord = 0;
      }
    }
    else
    {
      v73.m_nBitsAvail = v29 - 32;
      if ( v29 == 32 )
      {
        v73.m_nBitsAvail = 32;
        if ( m_pDataIn == v35 )
        {
          v73.m_nBitsAvail = 1;
          v73.m_nInBufWord = 0;
          v73.m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= v35 )
        {
          v73.m_nInBufWord = *m_pDataIn;
          v73.m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          v73.m_bOverflow = true;
          v73.m_nInBufWord = 0;
        }
      }
      else
      {
        v73.m_nInBufWord = 0;
      }
    }
    CBitRead::ReadString(this: &v73, pStr: s, maxLen: 2048, bLine: true, pOutNumChars: nullptr);
    if ( s[0] == 0 )
      return 1;
LABEL_139:
    v43 = v73.m_pDataIn;
    while ( 1 )
    {
      if ( v73.m_nBitsAvail >= 16 )
      {
        v44 = v73.m_nInBufWord;
        v73.m_nBitsAvail -= 16;
        if ( v73.m_nBitsAvail != 0 )
        {
          v73.m_nInBufWord >>= 16;
        }
        else
        {
          v73.m_nBitsAvail = 32;
          if ( v43 == v73.m_pBufferEnd )
          {
            ++v43;
            v73.m_nBitsAvail = 1;
            v73.m_nInBufWord = 0;
            v73.m_pDataIn = v43;
          }
          else if ( v43 <= v73.m_pBufferEnd )
          {
            v45 = *v43++;
            v73.m_nInBufWord = v45;
            v73.m_pDataIn = v43;
          }
          else
          {
            v73.m_bOverflow = true;
            v73.m_nInBufWord = 0;
          }
        }
        goto LABEL_152;
      }
      v46 = v73.m_nInBufWord;
      v47 = 16 - v73.m_nBitsAvail;
      if ( v43 == v73.m_pBufferEnd )
        break;
      if ( v43 > v73.m_pBufferEnd )
        break;
      v48 = *v43++;
      v73.m_nInBufWord = v48;
      v73.m_pDataIn = v43;
      if ( v73.m_bOverflow )
        break;
      v49 = (v48 & CBitBuffer::s_nMaskTable[v47]) << SLOBYTE(v73.m_nBitsAvail);
      v73.m_nBitsAvail = 32 - v47;
      v73.m_nInBufWord >>= v47;
      v44 = v49 | v46;
LABEL_152:
      if ( v44 == 0 )
        break;
      if ( v44 == 0xFFFF )
      {
        CBitRead::ReadString(this: &v73, pStr: s, maxLen: 2048, bLine: true, pOutNumChars: nullptr);
        goto LABEL_139;
      }
      v50 = v71;
      if ( v71 != 0 || !v74 )
      {
        _Msg(a1: "%s:%d\n", s, v44);
        v43 = v73.m_pDataIn;
      }
      if ( v72 )
      {
        CBitRead::ReadString(this: &v73, pStr, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
        if ( v50 != 0 )
          _Msg(a1: "%s\n", pStr);
        if ( v74 )
        {
          v51 = Info_ValueForKey(s: pStr, key: "players");
          v52 = Info_ValueForKey(s: pStr, key: "bots");
          v53 = atoi(nptr: v52);
          v54 = v67 - v53;
          v67 = v54 + atoi(nptr: v51);
          v55 = atoi(nptr: v52);
          v65 += v55;
          ++v66;
        }
        goto LABEL_139;
      }
    }
    if ( v72 )
    {
      v70 &= ~0x80000000;
      if ( v70 != 0 )
      {
        v13 = v74;
        v15 = v64;
        continue;
      }
    }
    break;
  }
  if ( v74 )
  {
    if ( v66 != 0 )
      v59 = (float)v67 / (float)v66;
    else
      v59 = 0.0;
    _Msg(a1: "%.2f Humans/Server\n", v59);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402800
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  _Msg(a1: "usage: xlspmastertest <masterserver> [options]\n");
  _Msg(a1: "options:\n");
  _Msg(a1: "-ping          Ping Mode. Default\n");
  _Msg(a1: "-list          List Mode.\n");
  _Msg(a1: "  -totals        Summary of players.\n");
  _Msg(a1: "  -empty         Empty servers only.\n");
  _Msg(a1: "  -full          Full servers only.\n");
  _Msg(a1: "  -details       Details. Spews info string\n");
  _Msg(a1: "-udp           Send/Receive using UDP and not VDP. Debug compile only.\n");
  _Msg(a1: "-stresstest    Infinite stress testing. Outgoing packets only.\n");
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00402860
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // eax
  bool v9; // bl
  int v10; // eax
  int v11; // eax
  char addressString[128]; // [esp+Ch] [ebp-D0h] BYREF
  char szAddress[64]; // [esp+8Ch] [ebp-50h] BYREF
  sockaddr_in masterAdr; // [esp+CCh] [ebp-10h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  _Msg(a1: "\nXLSPMasterTest - Valve XLSP Master Test ( Build: %s %s )\n", "Dec 28 2010", "17:00:42");
  _Msg(a1: "( C ) Copyright 1996-2008, Valve Corporation, All rights reserved.\n\n");
  if ( argc < 2
    || (v4 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "?") != 0)
    || (v5 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-h") != 0)
    || (v6 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-help") != 0) )
  {
    Usage();
  }
  NET_Init();
  if ( V_stristr(pStr: (char *)argv[1], pSearch: ":") != nullptr )
    V_strncpy(pDest: addressString, pSrc: argv[1], maxLen: 128);
  else
    V_snprintf(pDest: addressString, maxLen: 128, pFormat: "%s:%d", argv[1], 27011);
  if ( NET_StringToSockaddr(s: addressString, sadr: (sockaddr *)&masterAdr) != 0 )
  {
    Sys_AdrToString(pAddress: &masterAdr, pString: szAddress, nStringSize: 64);
    _Msg(a1: "Master Address: %s\n", szAddress);
    v8 = _CommandLine();
    v9 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-stresstest", a3: 0) != 0;
    do
    {
      v10 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v10 + 12))(a1: v10, a2: "-list", a3: 0) != 0
        || (v11 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(a1: v11, a2: "-l", a3: 0) != 0) )
      {
        MasterList(pMasterAdr: &masterAdr, bStressTest: v9);
      }
      else
      {
        MasterPing(pMasterAdr: &masterAdr, bStressTest: v9);
      }
      Sleep(dwMilliseconds: 1u);
    }
    while ( v9 );
    NET_Shutdown();
    return 0;
  }
  else
  {
    _Msg(a1: "Failed to resolve: %s\n", addressString);
    return 0;
  }
}
