// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/netconsole.cpp
// Functions: 7
// ============================================================

#include "engine\netconsole.h"

//------------------------------------------------------------------------------
// Address: 0x101B9CD0
// Name: private: virtual void CNetConsoleMgr::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::OnSocketAccepted(
        CNetConsoleMgr *this,
        int hSocket,
        const netadr_s *netAdr,
        void **ppData)
{
  _DWORD *v5; // eax

  v5 = MemAlloc_Alloc(nSize: 0x80Cu);
  if ( v5 != nullptr )
  {
    v5[1] = 0;
    *v5 = hSocket;
    *((_WORD *)v5 + 1028) = 0;
  }
  else
  {
    v5 = nullptr;
  }
  if ( !this->m_bPasswordProtected )
    *((_BYTE *)v5 + 2056) = 1;
  *ppData = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101B9D20
// Name: private: virtual void CNetConsoleMgr::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::OnSocketClosed(CNetConsoleMgr *this, int hSocket, const netadr_s *netAdr, void *pData)
{
  if ( pData != nullptr )
    free(pMem: pData);
}

//------------------------------------------------------------------------------
// Address: 0x101B9D40
// Name: public: void CNetConsoleMgr::SendStringToNetConsoles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::SendStringToNetConsoles(CNetConsoleMgr *this, const char *pString)
{
  CNetConsoleMgr *v2; // esi
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // eax
  bool v5; // zf
  void *v6; // esp
  char *v7; // esi
  const char *i; // eax
  int v9; // edi
  int v10; // eax
  SOCKET *AcceptedSocketData; // eax
  char v12[12]; // [esp+0h] [ebp-18h] BYREF
  CSocketCreator *v13; // [esp+Ch] [ebp-Ch]
  SOCKET *v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Socket = &this->m_Socket;
  v13 = &this->m_Socket;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)p_m_Socket);
  v2 = (CNetConsoleMgr *)((char *)v2 + 316);
  v5 = v2->__vftable == (CNetConsoleMgr_vtbl *)-1;
  v15 = SamplePosition;
  v14 = (SOCKET *)v2;
  if ( !v5 )
    v15 = ++SamplePosition;
  if ( SamplePosition != 0 )
  {
    v6 = alloca(2 * strlen(pString) + 1);
    v7 = v12;
    for ( i = pString; *i != 0; ++v7 )
    {
      if ( *i == 10 )
        *v7++ = 13;
      *v7 = *i++;
    }
    v9 = 0;
    *v7 = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v10 = v9;
        if ( *v14 == -1 )
          goto LABEL_13;
        if ( v9 != 0 )
          break;
        AcceptedSocketData = v14;
LABEL_14:
        if ( *((_BYTE *)AcceptedSocketData + 2056) != 0 && *((_BYTE *)AcceptedSocketData + 2057) == 0 )
          send(s: *AcceptedSocketData, buf: v12, len: v7 - v12, flags: 0);
        if ( ++v9 >= v15 )
          return;
      }
      v10 = v9 - 1;
LABEL_13:
      AcceptedSocketData = (SOCKET *)CSocketCreator::GetAcceptedSocketData(this: v13, nIndex: v10);
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9E20
// Name: private: void CNetConsoleMgr::HandleInputChars(char const __near *,int,class CConnectedNetConsoleData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::HandleInputChars(
        CNetConsoleMgr *this,
        char *pIn,
        int recvLen,
        CConnectedNetConsoleData *pData)
{
  char v5; // al
  int v6; // ecx
  int m_nCharsInCommandBuffer; // eax

  for ( ; recvLen != 0; --recvLen )
  {
    v5 = *pIn;
    if ( *pIn == 10 || v5 == 13 )
    {
      m_nCharsInCommandBuffer = pData->m_nCharsInCommandBuffer;
      if ( m_nCharsInCommandBuffer != 0 )
      {
        pData->m_pszInputCommandBuffer[m_nCharsInCommandBuffer] = 0;
        if ( *(_DWORD *)pData->m_pszInputCommandBuffer == 1397965136 && pData->m_pszInputCommandBuffer[4] == 32 )
        {
          if ( _V_strcmp(s1: &pData->m_pszInputCommandBuffer[5], s2: this->m_pPassword) != 0 )
          {
            _Warning(a1: "Bad password attempt from net console\n");
            pData->m_bAuthorized = false;
          }
          else
          {
            pData->m_bAuthorized = true;
          }
        }
        else if ( pData->m_bAuthorized )
        {
          engineClient->ClientCmd_Unrestricted(this: engineClient, a2: pData->m_pszInputCommandBuffer);
        }
        else
        {
          send(
            s: pData->m_hSocket,
            buf: "This server is password protected for console access. Must send PASS command\n\r",
            len: 78,
            flags: 0);
        }
      }
      pData->m_nCharsInCommandBuffer = 0;
    }
    else
    {
      v6 = pData->m_nCharsInCommandBuffer;
      if ( v6 < 2047 )
      {
        pData->m_pszInputCommandBuffer[v6] = v5;
        ++pData->m_nCharsInCommandBuffer;
      }
    }
    ++pIn;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9F00
// Name: public: CNetConsoleMgr::CNetConsoleMgr(void)
// Source: json
//------------------------------------------------------------------------------
CNetConsoleMgr *__thiscall CNetConsoleMgr::CNetConsoleMgr(CNetConsoleMgr *this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  double v8; // st7
  u_long argp; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (CNetConsoleMgr_vtbl *)&CNetConsoleMgr::`vftable';
  CSocketCreator::CSocketCreator(this: &this->m_Socket, pListener: this);
  netadr_s::SetIP(this: &this->m_Address, unIP: 0);
  netadr_s::SetPort(this: &this->m_Address, newport: 0);
  netadr_s::SetType(this: &this->m_Address, newtype: NA_IP);
  this->m_ParentConnection.m_nCharsInCommandBuffer = 0;
  this->m_ParentConnection.m_hSocket = -1;
  *(_WORD *)&this->m_ParentConnection.m_bAuthorized = 0;
  *(_WORD *)&this->m_bActive = 0;
  v2 = _CommandLine();
  argp = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-netconpassword");
  if ( argp != 0 )
  {
    v3 = _CommandLine();
    v4 = (const char *)(*(int (__thiscall **)(int, u_long))(*(_DWORD *)v3 + 44))(a1: v3, a2: argp + 1);
    V_strncpy(pDest: this->m_pPassword, pSrc: v4, maxLen: 256);
    this->m_bPasswordProtected = true;
  }
  v5 = _CommandLine();
  argp = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-netconport");
  if ( argp != 0 )
  {
    v6 = _CommandLine();
    v7 = (const char *)(*(int (__thiscall **)(int, u_long))(*(_DWORD *)v6 + 44))(a1: v6, a2: argp + 1);
    this->m_Address = net_local_adr;
    v8 = EvaluateExpression(pExpr: v7, flValueToReturnIfFailure: -1.0);
    if ( (int)v8 > 0 )
    {
      netadr_s::SetPort(this: &this->m_Address, newport: (int)v8);
      this->m_bActive = true;
      CSocketCreator::CreateListenSocket(this: &this->m_Socket, netAdr: &this->m_Address, bListenOnAllInterfaces: true);
    }
  }
  if ( g_nForkID > 0 )
  {
    argp = 1;
    ioctlsocket(s: g_nSocketToParentProcess, cmd: -2147195266, &argp);
    this->m_ParentConnection.m_hSocket = g_nSocketToParentProcess;
    *(_WORD *)&this->m_ParentConnection.m_bAuthorized = 257;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BA060
// Name: public: void CNetConsoleMgr::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::RunFrame(CNetConsoleMgr *this)
{
  CNetConsoleMgr *v1; // edi
  int SamplePosition; // eax
  int v3; // esi
  CConnectedNetConsoleData *p_m_ParentConnection; // ebx
  int v5; // eax
  SOCKET m_hSocket; // edi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  char recvBuf[259]; // [esp+8h] [ebp-110h] BYREF
  char buf; // [esp+10Bh] [ebp-Dh] BYREF
  unsigned int readLen; // [esp+10Ch] [ebp-Ch] BYREF
  CNetConsoleMgr *v16; // [esp+110h] [ebp-8h]
  int i; // [esp+114h] [ebp-4h]

  v1 = this;
  v16 = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v1->m_Socket);
  if ( v1->m_ParentConnection.m_hSocket != -1 )
    ++SamplePosition;
  v3 = SamplePosition - 1;
  i = SamplePosition - 1;
  if ( SamplePosition - 1 >= 0 )
  {
    while ( 1 )
    {
      p_m_ParentConnection = &v1->m_ParentConnection;
      v5 = v3;
      if ( v1->m_ParentConnection.m_hSocket != -1 )
      {
        if ( v3 == 0 )
          goto LABEL_10;
        v5 = v3 - 1;
      }
      p_m_ParentConnection = (CConnectedNetConsoleData *)CSocketCreator::GetAcceptedSocketData(
                                                           this: &v1->m_Socket,
                                                           nIndex: v5);
LABEL_10:
      m_hSocket = p_m_ParentConnection->m_hSocket;
      v7 = recv(s: p_m_ParentConnection->m_hSocket, &buf, len: 1, flags: 2);
      if ( v7 == -1 )
      {
        if ( SocketWouldBlock() )
          goto LABEL_31;
      }
      else if ( v7 > 0 )
      {
        ioctlsocket(s: m_hSocket, cmd: 1074030207, argp: &readLen);
        v9 = readLen;
        if ( readLen == 0 )
          goto LABEL_31;
        while ( 1 )
        {
          if ( v9 > 0x100 )
            v9 = 256;
          v10 = recv(s: m_hSocket, buf: recvBuf, len: v9, flags: 0);
          v11 = v10;
          if ( v10 == 0 )
            break;
          if ( v10 >= 0 || SocketWouldBlock() )
          {
            readLen -= v11;
            CNetConsoleMgr::HandleInputChars(this: v16, pIn: recvBuf, recvLen: v11, pData: p_m_ParentConnection);
            v9 = readLen;
            if ( readLen != 0 )
              continue;
          }
          goto LABEL_30;
        }
        v12 = i;
        if ( v16->m_ParentConnection.m_hSocket == -1 )
        {
LABEL_29:
          CSocketCreator::CloseAcceptedSocket(this: &v16->m_Socket, nIndex: v12);
        }
        else if ( i != 0 )
        {
          v12 = i - 1;
          goto LABEL_29;
        }
LABEL_30:
        v3 = i;
        goto LABEL_31;
      }
      v8 = v3;
      if ( v16->m_ParentConnection.m_hSocket != -1 )
      {
        if ( v3 == 0 )
          goto LABEL_31;
        v8 = v3 - 1;
      }
      CSocketCreator::CloseAcceptedSocket(this: &v16->m_Socket, nIndex: v8);
LABEL_31:
      i = --v3;
      if ( v3 < 0 )
        return;
      v1 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA1B0
// Name: void InitNetConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitNetConsole()
{
  CNetConsoleMgr *v0; // eax

  if ( g_pNetConsoleMgr == nullptr )
  {
    v0 = (CNetConsoleMgr *)MemAlloc_Alloc(nSize: 0x948u);
    if ( v0 != nullptr )
      g_pNetConsoleMgr = CNetConsoleMgr::CNetConsoleMgr(this: v0);
    else
      g_pNetConsoleMgr = nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101BA160
// Name: private: virtual void CNetConsoleMgr::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::OnSocketAccepted(
        CNetConsoleMgr *this,
        int hSocket,
        const netadr_s *netAdr,
        void **ppData)
{
  _DWORD *v5; // eax

  v5 = MemAlloc_Alloc(nSize: 0x80Cu);
  if ( v5 != nullptr )
  {
    v5[1] = 0;
    *v5 = hSocket;
    *((_WORD *)v5 + 1028) = 0;
  }
  else
  {
    v5 = nullptr;
  }
  if ( !this->m_bPasswordProtected )
    *((_BYTE *)v5 + 2056) = 1;
  *ppData = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101BA1D0
// Name: public: void CNetConsoleMgr::SendStringToNetConsoles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::SendStringToNetConsoles(CNetConsoleMgr *this, const char *pString)
{
  CNetConsoleMgr *v2; // esi
  CSocketCreator *p_m_Socket; // edi
  int SamplePosition; // eax
  bool v5; // zf
  void *v6; // esp
  char *v7; // esi
  const char *i; // eax
  int v9; // edi
  int v10; // eax
  SOCKET *AcceptedSocketData; // eax
  char v12[12]; // [esp+0h] [ebp-18h] BYREF
  CSocketCreator *v13; // [esp+Ch] [ebp-Ch]
  SOCKET *v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Socket = &this->m_Socket;
  v13 = &this->m_Socket;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)p_m_Socket);
  v2 = (CNetConsoleMgr *)((char *)v2 + 316);
  v5 = v2->__vftable == (CNetConsoleMgr_vtbl *)-1;
  v15 = SamplePosition;
  v14 = (SOCKET *)v2;
  if ( !v5 )
    v15 = ++SamplePosition;
  if ( SamplePosition != 0 )
  {
    v6 = alloca(2 * strlen(pString) + 1);
    v7 = v12;
    for ( i = pString; *i != 0; ++v7 )
    {
      if ( *i == 10 )
        *v7++ = 13;
      *v7 = *i++;
    }
    v9 = 0;
    *v7 = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v10 = v9;
        if ( *v14 == -1 )
          goto LABEL_13;
        if ( v9 != 0 )
          break;
        AcceptedSocketData = v14;
LABEL_14:
        if ( *((_BYTE *)AcceptedSocketData + 2056) != 0 && *((_BYTE *)AcceptedSocketData + 2057) == 0 )
          send(s: *AcceptedSocketData, buf: v12, len: v7 - v12, flags: 0);
        if ( ++v9 >= v15 )
          return;
      }
      v10 = v9 - 1;
LABEL_13:
      AcceptedSocketData = (SOCKET *)CSocketCreator::GetAcceptedSocketData(this: v13, nIndex: v10);
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA2B0
// Name: private: void CNetConsoleMgr::HandleInputChars(char const __near *,int,class CConnectedNetConsoleData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::HandleInputChars(
        CNetConsoleMgr *this,
        char *pIn,
        int recvLen,
        CConnectedNetConsoleData *pData)
{
  char v5; // al
  int v6; // ecx
  int m_nCharsInCommandBuffer; // eax

  for ( ; recvLen != 0; --recvLen )
  {
    v5 = *pIn;
    if ( *pIn == 10 || v5 == 13 )
    {
      m_nCharsInCommandBuffer = pData->m_nCharsInCommandBuffer;
      if ( m_nCharsInCommandBuffer != 0 )
      {
        pData->m_pszInputCommandBuffer[m_nCharsInCommandBuffer] = 0;
        if ( *(_DWORD *)pData->m_pszInputCommandBuffer == 1397965136 && pData->m_pszInputCommandBuffer[4] == 32 )
        {
          if ( _V_strcmp(s1: &pData->m_pszInputCommandBuffer[5], s2: this->m_pPassword) != 0 )
          {
            _Warning(a1: "Bad password attempt from net console\n");
            pData->m_bAuthorized = false;
          }
          else
          {
            pData->m_bAuthorized = true;
          }
        }
        else if ( pData->m_bAuthorized )
        {
          engineClient->ClientCmd_Unrestricted(this: engineClient, a2: pData->m_pszInputCommandBuffer);
        }
        else
        {
          send(
            s: pData->m_hSocket,
            buf: "This server is password protected for console access. Must send PASS command\n\r",
            len: 78,
            flags: 0);
        }
      }
      pData->m_nCharsInCommandBuffer = 0;
    }
    else
    {
      v6 = pData->m_nCharsInCommandBuffer;
      if ( v6 < 2047 )
      {
        pData->m_pszInputCommandBuffer[v6] = v5;
        ++pData->m_nCharsInCommandBuffer;
      }
    }
    ++pIn;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA390
// Name: public: CNetConsoleMgr::CNetConsoleMgr(void)
// Source: json
//------------------------------------------------------------------------------
CNetConsoleMgr *__thiscall CNetConsoleMgr::CNetConsoleMgr(CNetConsoleMgr *this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  double v8; // st7
  int v10; // [esp+4h] [ebp-10h]
  int v11; // [esp+4h] [ebp-10h]
  int v12; // [esp+4h] [ebp-10h]
  u_long argp; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (CNetConsoleMgr_vtbl *)&CNetConsoleMgr::`vftable';
  CSocketCreator::CSocketCreator(this: &this->m_Socket, pListener: this);
  netadr_s::SetIP(this: &this->m_Address, unIP: 0);
  netadr_s::SetPort(this: &this->m_Address, newport: 0);
  netadr_s::SetType(this: &this->m_Address, newtype: NA_IP);
  this->m_ParentConnection.m_nCharsInCommandBuffer = 0;
  this->m_ParentConnection.m_hSocket = -1;
  *(_WORD *)&this->m_ParentConnection.m_bAuthorized = 0;
  *(_WORD *)&this->m_bActive = 0;
  v2 = _CommandLine(a1: v10);
  argp = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-netconpassword");
  if ( argp != 0 )
  {
    v3 = _CommandLine(a1: v11);
    v4 = (const char *)(*(int (__thiscall **)(int, u_long))(*(_DWORD *)v3 + 44))(a1: v3, a2: argp + 1);
    V_strncpy(pDest: this->m_pPassword, pSrc: v4, maxLen: 256);
    this->m_bPasswordProtected = true;
  }
  v5 = _CommandLine(a1: v11);
  argp = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-netconport");
  if ( argp != 0 )
  {
    v6 = _CommandLine(a1: v12);
    v7 = (const char *)(*(int (__thiscall **)(int, u_long))(*(_DWORD *)v6 + 44))(a1: v6, a2: argp + 1);
    this->m_Address = net_local_adr;
    v8 = EvaluateExpression(pExpr: v7, flValueToReturnIfFailure: -1.0);
    if ( (int)v8 > 0 )
    {
      netadr_s::SetPort(this: &this->m_Address, newport: (int)v8);
      this->m_bActive = true;
      CSocketCreator::CreateListenSocket(this: &this->m_Socket, netAdr: &this->m_Address, bListenOnAllInterfaces: true);
    }
  }
  if ( g_nForkID > 0 )
  {
    argp = 1;
    ioctlsocket(s: g_nSocketToParentProcess, cmd: -2147195266, &argp);
    this->m_ParentConnection.m_hSocket = g_nSocketToParentProcess;
    *(_WORD *)&this->m_ParentConnection.m_bAuthorized = 257;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BA4F0
// Name: public: void CNetConsoleMgr::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetConsoleMgr::RunFrame(CNetConsoleMgr *this)
{
  CNetConsoleMgr *v1; // edi
  int SamplePosition; // eax
  int v3; // esi
  CConnectedNetConsoleData *p_m_ParentConnection; // ebx
  int v5; // eax
  SOCKET m_hSocket; // edi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  char recvBuf[259]; // [esp+8h] [ebp-110h] BYREF
  char buf; // [esp+10Bh] [ebp-Dh] BYREF
  unsigned int readLen; // [esp+10Ch] [ebp-Ch] BYREF
  CNetConsoleMgr *v16; // [esp+110h] [ebp-8h]
  int i; // [esp+114h] [ebp-4h]

  v1 = this;
  v16 = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v1->m_Socket);
  if ( v1->m_ParentConnection.m_hSocket != -1 )
    ++SamplePosition;
  v3 = SamplePosition - 1;
  i = SamplePosition - 1;
  if ( SamplePosition - 1 >= 0 )
  {
    while ( 1 )
    {
      p_m_ParentConnection = &v1->m_ParentConnection;
      v5 = v3;
      if ( v1->m_ParentConnection.m_hSocket != -1 )
      {
        if ( v3 == 0 )
          goto LABEL_10;
        v5 = v3 - 1;
      }
      p_m_ParentConnection = (CConnectedNetConsoleData *)CSocketCreator::GetAcceptedSocketData(
                                                           this: &v1->m_Socket,
                                                           nIndex: v5);
LABEL_10:
      m_hSocket = p_m_ParentConnection->m_hSocket;
      v7 = recv(s: p_m_ParentConnection->m_hSocket, &buf, len: 1, flags: 2);
      if ( v7 == -1 )
      {
        if ( SocketWouldBlock() )
          goto LABEL_31;
      }
      else if ( v7 > 0 )
      {
        ioctlsocket(s: m_hSocket, cmd: 1074030207, argp: &readLen);
        v9 = readLen;
        if ( readLen == 0 )
          goto LABEL_31;
        while ( 1 )
        {
          if ( v9 > 0x100 )
            v9 = 256;
          v10 = recv(s: m_hSocket, buf: recvBuf, len: v9, flags: 0);
          v11 = v10;
          if ( v10 == 0 )
            break;
          if ( v10 >= 0 || SocketWouldBlock() )
          {
            readLen -= v11;
            CNetConsoleMgr::HandleInputChars(this: v16, pIn: recvBuf, recvLen: v11, pData: p_m_ParentConnection);
            v9 = readLen;
            if ( readLen != 0 )
              continue;
          }
          goto LABEL_30;
        }
        v12 = i;
        if ( v16->m_ParentConnection.m_hSocket == -1 )
        {
LABEL_29:
          CSocketCreator::CloseAcceptedSocket(this: &v16->m_Socket, nIndex: v12);
        }
        else if ( i != 0 )
        {
          v12 = i - 1;
          goto LABEL_29;
        }
LABEL_30:
        v3 = i;
        goto LABEL_31;
      }
      v8 = v3;
      if ( v16->m_ParentConnection.m_hSocket != -1 )
      {
        if ( v3 == 0 )
          goto LABEL_31;
        v8 = v3 - 1;
      }
      CSocketCreator::CloseAcceptedSocket(this: &v16->m_Socket, nIndex: v8);
LABEL_31:
      i = --v3;
      if ( v3 < 0 )
        return;
      v1 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA640
// Name: void InitNetConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitNetConsole()
{
  CNetConsoleMgr *v0; // eax

  if ( g_pNetConsoleMgr == nullptr )
  {
    v0 = (CNetConsoleMgr *)MemAlloc_Alloc(nSize: 0x948u);
    if ( v0 != nullptr )
      g_pNetConsoleMgr = CNetConsoleMgr::CNetConsoleMgr(this: v0);
    else
      g_pNetConsoleMgr = nullptr;
  }
}

} // namespace engine_xlsp
