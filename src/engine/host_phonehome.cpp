// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host_phonehome.cpp
// Functions: 8
// ============================================================

#include "engine\host_phonehome.h"

//------------------------------------------------------------------------------
// Address: 0x1018F0F0
// Name: public: virtual void CPhoneHome::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::Shutdown(CPhoneHome *this)
{
  CBlockingUDPSocket *m_pSocket; // ecx

  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
    ((void (__thiscall *)(CBlockingUDPSocket *, int))m_pSocket->dtr_CBlockingUDPSocket)(a1: m_pSocket, a2: 1);
  this->m_pSocket = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1018F110
// Name: public: virtual void CPhoneHome::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::Init(CPhoneHome *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  const char *v7; // esi
  int v8; // eax
  char *i; // eax
  CBlockingUDPSocket *v10; // eax
  char build_identifier[32]; // [esp+Ch] [ebp-20h] BYREF

  V_strncpy(pDest: build_identifier, pSrc: "VLV_INTERNAL                    ", maxLen: 32);
  v2 = _CommandLine();
  v3 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-bi");
  if ( v3 > 0 )
  {
    v4 = _CommandLine();
    v5 = v3 + 1;
    if ( v5 >= (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 36))(a1: v4) )
    {
      build_identifier[0] = 33;
    }
    else
    {
      v6 = _CommandLine();
      v7 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 44))(a1: v6, a2: v5);
      _V_memset(dest: build_identifier, fill: 0, count: 32);
      V_strncpy(pDest: build_identifier, pSrc: v7, maxLen: 32);
    }
  }
  if ( _V_strlen(str: build_identifier) >= 1 )
  {
    v8 = _V_strlen(str: "VLV_INTERNAL");
    if ( V_strnicmp(s1: build_identifier, s2: "VLV_INTERNAL", n: v8) != 0 )
    {
      for ( i = &build_identifier[_V_strlen(str: build_identifier) - 1]; i > build_identifier; *i-- = 0 )
      {
        if ( *i != 32 )
          break;
      }
      if ( NET_StringToAdr(s: "207.173.177.12:27013", a: &this->m_cserIP) )
      {
        this->m_bPhoneHome = true;
        V_strncpy(pDest: this->m_szBuildIdentifier, pSrc: build_identifier, maxLen: 32);
        v10 = (CBlockingUDPSocket *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v10 != nullptr )
          this->m_pSocket = CBlockingUDPSocket::CBlockingUDPSocket(this: v10);
        else
          this->m_pSocket = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F240
// Name: private: void CPhoneHome::ExitApp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::ExitApp(CPhoneHome *this)
{
  _Error(a1: g_pszExitMsg, 212);
}

//------------------------------------------------------------------------------
// Address: 0x1018F260
// Name: private: void CPhoneHome::BuildMessage(class bf_write __near &,unsigned char,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::BuildMessage(
        CPhoneHome *this,
        int buf,
        unsigned __int8 msgtype,
        const char *mapname,
        const char *uSessionID)
{
  bf_write *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int i; // ecx
  IceSubkey *keysched; // esi
  int v12; // eax
  unsigned int v13; // edi
  _BYTE pData[4]; // [esp+Ch] [ebp-8ACh] BYREF
  unsigned __int8 encrypted_data[2048]; // [esp+10h] [ebp-8A8h] BYREF
  char gamedir[64]; // [esp+810h] [ebp-A8h] BYREF
  char username[64]; // [esp+850h] [ebp-68h] BYREF
  IceKey cipher; // [esp+890h] [ebp-28h] BYREF
  bf_write encrypted; // [esp+89Ch] [ebp-1Ch] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+8B4h] [ebp-4h]

  bf_write::bf_write(this: (bf_write *)&cipher._keysched);
  v6 = (bf_write *)buf;
  bf_write::WriteByte(this: (bf_write *)buf, val: 0x6Du);
  bf_write::WriteByte(this: v6, val: 0xAu);
  bf_write::WriteByte(this: v6, val: 3u);
  bf_write::WriteLong(this: v6, val: (int)uSessionID);
  IceKey::IceKey(this: (IceKey *)&username[60], n: 1);
  encrypted.m_pDebugName = (const char *)-570424897;
  *(_DWORD *)ucEncryptionKey = 26879829;
  IceKey::set(this: (IceKey *)&username[60], key: (const unsigned __int8 *)&encrypted.m_pDebugName);
  bf_write::StartWriting(this: (bf_write *)&cipher._keysched, pData, nBytes: 2048, iStartBit: 0, nBits: -1);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 1u);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 1u);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: this->m_szBuildIdentifier);
  _V_memset(dest: &gamedir[60], fill: 0, count: 64);
  buf = 63;
  if ( !GetComputerNameA(lpBuffer: &gamedir[60], nSize: (LPDWORD)&buf) )
    V_strncpy(pDest: &gamedir[60], pSrc: "???", maxLen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: &gamedir[60]);
  _V_memset(dest: &gamedir[60], fill: 0, count: 64);
  buf = 63;
  if ( !GetUserNameA(lpBuffer: &gamedir[60], pcbBuffer: (LPDWORD)&buf) )
    V_strncpy(pDest: &gamedir[60], pSrc: "???", maxLen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: &gamedir[60]);
  V_FileBase(in: com_gamedir, out: (char *)&encrypted_data[2044], maxlen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: (const char *)&encrypted_data[2044]);
  v7 = build_number();
  bf_write::WriteLong(this: (bf_write *)&cipher._keysched, val: v7);
  bf_write::WriteFloat(this: (bf_write *)&cipher._keysched, val: realtime);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: msgtype);
  if ( mapname != nullptr )
    bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: mapname);
  if ( Sys_IsDebuggerPresent()
    || (v8 = _CommandLine(),
        (v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-allowdebug")) != 0) )
  {
    v9 = 1;
  }
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: v9);
  for ( i = encrypted.m_nDataBits; ((encrypted.m_nDataBits + 7) >> 3) % 8 != 0; i = encrypted.m_nDataBits )
    bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 0);
  keysched = cipher._keysched;
  v12 = (i + 7) >> 3;
  if ( v12 != 0 )
  {
    v13 = ((unsigned int)(v12 - 1) >> 3) + 1;
    do
    {
      IceKey::encrypt(
        this: (IceKey *)&username[60],
        ptext: (const unsigned __int8 *)keysched,
        ctext: (unsigned __int8 *)keysched);
      keysched = (IceSubkey *)((char *)keysched + 8);
      --v13;
    }
    while ( v13 != 0 );
    i = encrypted.m_nDataBits;
  }
  bf_write::WriteShort(this: v6, val: (i + 7) >> 3);
  bf_write::WriteBytes(this: v6, pBuf: cipher._keysched, nBytes: (encrypted.m_nDataBits + 7) >> 3);
  IceKey::~IceKey(this: (IceKey *)&username[60]);
}

//------------------------------------------------------------------------------
// Address: 0x1018F4B0
// Name: private: void CPhoneHome::SendSessionMessage(unsigned char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::SendSessionMessage(CPhoneHome *this, unsigned __int8 msgtype, const char *mapname)
{
  unsigned int v4; // eax
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // ebx
  int v7; // esi
  unsigned int v8; // eax
  char m_nInBufWord; // cl
  int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // ebx
  int v17; // edi
  unsigned int v18; // eax
  char v19; // cl
  unsigned int v20; // ebx
  unsigned int v21; // edx
  _BYTE pData[4]; // [esp+Ch] [ebp-8E0h] BYREF
  unsigned __int8 data[2048]; // [esp+10h] [ebp-8DCh] BYREF
  unsigned __int8 readbuf[128]; // [esp+810h] [ebp-DCh] BYREF
  sockaddr_in replyaddress; // [esp+890h] [ebp-5Ch] BYREF
  sockaddr_in sa; // [esp+8A0h] [ebp-4Ch] BYREF
  bf_write buf; // [esp+8B0h] [ebp-3Ch]
  CBitRead v28; // [esp+8C8h] [ebp-24h] BYREF

  buf.m_pDebugName = (const char *)this;
  if ( this->m_uSessionID != 0 )
  {
    bf_write::bf_write(this: (bf_write *)&sa.sin_zero[4]);
    bf_write::StartWriting(this: (bf_write *)&sa.sin_zero[4], pData, nBytes: 2048, iStartBit: 0, nBits: -1);
    CPhoneHome::BuildMessage(
      this,
      buf: (int)&sa.sin_zero[4],
      msgtype,
      mapname,
      uSessionID: (const char *)this->m_uSessionID);
    netadr_s::ToSockadr(this: &this->m_cserIP, s: (sockaddr *)&replyaddress.sin_zero[4]);
    CBlockingUDPSocket::SendSocketMessage(
      this: this->m_pSocket,
      rRecipient: (const sockaddr_in *)&replyaddress.sin_zero[4],
      buf: *(const unsigned __int8 **)&sa.sin_zero[4],
      bufsize: (buf.m_nDataBits + 7) >> 3);
    if ( this->m_uSessionID == 0 && CBlockingUDPSocket::WaitForMessage(this: this->m_pSocket, timeOutInSeconds: 1.5) )
    {
      v28.m_bOverflow = false;
      v28.m_pDebugName = nullptr;
      v28.m_nDataBits = -1;
      v28.m_nDataBytes = 0;
      CBitRead::StartReading(
        this: &v28,
        pData: (const unsigned int *)&data[2044],
        nBytes: 0x80u,
        iStartBit: 0,
        nBits: -1);
      v4 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: this->m_pSocket,
             packet_from: (int)&readbuf[124],
             buf: &data[2044],
             bufsize: 0x80u);
      if ( v4 != 0 )
      {
        CBitRead::StartReading(
          this: &v28,
          pData: (const unsigned int *)&data[2044],
          nBytes: v4,
          iStartBit: 0,
          nBits: -1);
        m_pDataIn = v28.m_pDataIn;
        if ( v28.m_nBitsAvail < 8 )
        {
          v10 = 8 - v28.m_nBitsAvail;
          if ( v28.m_pDataIn == v28.m_pBufferEnd )
            return;
          if ( v28.m_pDataIn > v28.m_pBufferEnd )
            return;
          v11 = *v28.m_pDataIn;
          m_pDataIn = ++v28.m_pDataIn;
          if ( v28.m_bOverflow )
            return;
          v12 = ((v11 & CBitBuffer::s_nMaskTable[v10]) << SLOBYTE(v28.m_nBitsAvail)) | v28.m_nInBufWord;
          v7 = 32 - v10;
          v8 = v11 >> v10;
          m_nInBufWord = v12;
          m_pBufferEnd = v28.m_pBufferEnd;
          v28.m_nBitsAvail = 32 - v10;
        }
        else
        {
          m_pBufferEnd = v28.m_pBufferEnd;
          v7 = v28.m_nBitsAvail - 8;
          v28.m_nBitsAvail = v7;
          if ( v7 != 0 )
          {
            v8 = v28.m_nInBufWord >> 8;
            m_nInBufWord = v28.m_nInBufWord;
          }
          else
          {
            v7 = 32;
            v28.m_nBitsAvail = 32;
            if ( v28.m_pDataIn == v28.m_pBufferEnd )
            {
              v8 = 0;
              v7 = 1;
              m_pDataIn = v28.m_pDataIn + 1;
              v28.m_nBitsAvail = 1;
              ++v28.m_pDataIn;
              m_nInBufWord = v28.m_nInBufWord;
            }
            else
            {
              if ( v28.m_pDataIn <= v28.m_pBufferEnd )
              {
                v8 = *v28.m_pDataIn;
                m_pDataIn = ++v28.m_pDataIn;
              }
              else
              {
                v28.m_bOverflow = true;
                v8 = 0;
              }
              m_nInBufWord = v28.m_nInBufWord;
            }
          }
        }
        v28.m_nInBufWord = v8;
        if ( m_nInBufWord != 110 )
          return;
        if ( v7 < 8 )
        {
          v16 = v8;
          v17 = 8 - v7;
          if ( m_pDataIn == v28.m_pBufferEnd )
            return;
          if ( m_pDataIn > v28.m_pBufferEnd )
            return;
          v18 = *m_pDataIn++;
          v28.m_pDataIn = m_pDataIn;
          if ( v28.m_bOverflow )
            return;
          v19 = 8 - v7;
          v20 = ((v18 & CBitBuffer::s_nMaskTable[v17]) << v7) | v16;
          v14 = 32 - v17;
          v13 = v20;
          m_pBufferEnd = v28.m_pBufferEnd;
          v28.m_nBitsAvail = v14;
          v15 = v18 >> v19;
        }
        else
        {
          v13 = (unsigned __int8)v8;
          v14 = v7 - 8;
          v28.m_nBitsAvail = v14;
          if ( v14 != 0 )
          {
            v15 = v8 >> 8;
          }
          else
          {
            v14 = 32;
            v28.m_nBitsAvail = 32;
            if ( m_pDataIn == m_pBufferEnd )
            {
              v15 = 0;
              v14 = 1;
              ++m_pDataIn;
              v28.m_nBitsAvail = 1;
              v28.m_pDataIn = m_pDataIn;
            }
            else if ( m_pDataIn <= m_pBufferEnd )
            {
              v15 = *m_pDataIn++;
              v28.m_pDataIn = m_pDataIn;
            }
            else
            {
              v28.m_bOverflow = true;
              v15 = 0;
            }
          }
        }
        v28.m_nInBufWord = v15;
        if ( v13 == 1 )
        {
          if ( v14 < 32 )
          {
            if ( m_pDataIn == m_pBufferEnd || m_pDataIn > m_pBufferEnd || (v21 = *m_pDataIn, v28.m_bOverflow) )
              *((_DWORD *)buf.m_pDebugName + 14) = 0;
            else
              *((_DWORD *)buf.m_pDebugName + 14) = v15 | ((v21 & CBitBuffer::s_nMaskTable[32 - v14]) << v14);
          }
          else
          {
            *((_DWORD *)buf.m_pDebugName + 14) = v15;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F780
// Name: private: bool CPhoneHome::RequestSessionId(unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhoneHome::RequestSessionId(CPhoneHome *this, unsigned int *id)
{
  int v3; // edi
  unsigned int v4; // eax
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // ecx
  int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  int v11; // edi
  unsigned int v12; // eax
  int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned int v20; // edx
  _BYTE pData[4]; // [esp+10h] [ebp-8E0h] BYREF
  unsigned __int8 data[2048]; // [esp+14h] [ebp-8DCh] BYREF
  unsigned __int8 readbuf[128]; // [esp+814h] [ebp-DCh] BYREF
  sockaddr_in replyaddress; // [esp+894h] [ebp-5Ch] BYREF
  sockaddr_in sa; // [esp+8A4h] [ebp-4Ch] BYREF
  bf_write buf; // [esp+8B4h] [ebp-3Ch]
  CBitRead v27; // [esp+8CCh] [ebp-24h] BYREF

  *id = 0;
  bf_write::bf_write(this: (bf_write *)&sa.sin_zero[4]);
  bf_write::StartWriting(this: (bf_write *)&sa.sin_zero[4], pData, nBytes: 2048, iStartBit: 0, nBits: -1);
  CPhoneHome::BuildMessage(
    this,
    buf: (int)&sa.sin_zero[4],
    msgtype: 1u,
    mapname: nullptr,
    uSessionID: (const char *)*id);
  netadr_s::ToSockadr(this: &this->m_cserIP, s: (sockaddr *)&replyaddress.sin_zero[4]);
  v3 = 0;
  while ( 1 )
  {
    CBlockingUDPSocket::SendSocketMessage(
      this: this->m_pSocket,
      rRecipient: (const sockaddr_in *)&replyaddress.sin_zero[4],
      buf: *(const unsigned __int8 **)&sa.sin_zero[4],
      bufsize: (buf.m_nDataBits + 7) >> 3);
    if ( CBlockingUDPSocket::WaitForMessage(this: this->m_pSocket, timeOutInSeconds: 1.5) )
    {
      v27.m_bOverflow = false;
      v27.m_pDebugName = nullptr;
      v27.m_nDataBits = -1;
      v27.m_nDataBytes = 0;
      CBitRead::StartReading(
        this: &v27,
        pData: (const unsigned int *)&data[2044],
        nBytes: 0x80u,
        iStartBit: 0,
        nBits: -1);
      v4 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: this->m_pSocket,
             packet_from: (int)&readbuf[124],
             buf: &data[2044],
             bufsize: 0x80u);
      if ( v4 != 0 )
        break;
    }
    if ( ++v3 >= 3 )
      return 0;
  }
  CBitRead::StartReading(this: &v27, pData: (const unsigned int *)&data[2044], nBytes: v4, iStartBit: 0, nBits: -1);
  m_pDataIn = v27.m_pDataIn;
  if ( v27.m_nBitsAvail < 8 )
  {
    v11 = 8 - v27.m_nBitsAvail;
    if ( v27.m_pDataIn == v27.m_pBufferEnd )
      return 0;
    if ( v27.m_pDataIn > v27.m_pBufferEnd )
      return 0;
    v12 = *v27.m_pDataIn;
    m_pDataIn = ++v27.m_pDataIn;
    if ( v27.m_bOverflow )
      return 0;
    buf.m_pDebugName = (const char *)(v12 & CBitBuffer::s_nMaskTable[v11]);
    v10 = ((int)buf.m_pDebugName << SLOBYTE(v27.m_nBitsAvail)) | v27.m_nInBufWord;
    v8 = 32 - v11;
    v9 = v12 >> v11;
    m_pBufferEnd = v27.m_pBufferEnd;
    v27.m_nBitsAvail = 32 - v11;
  }
  else
  {
    m_pBufferEnd = v27.m_pBufferEnd;
    v8 = v27.m_nBitsAvail - 8;
    v27.m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      v9 = v27.m_nInBufWord >> 8;
      LOBYTE(v10) = v27.m_nInBufWord;
    }
    else
    {
      v8 = 32;
      v27.m_nBitsAvail = 32;
      if ( v27.m_pDataIn == v27.m_pBufferEnd )
      {
        v9 = 0;
        v8 = 1;
        m_pDataIn = v27.m_pDataIn + 1;
        v27.m_nBitsAvail = 1;
        ++v27.m_pDataIn;
        LOBYTE(v10) = v27.m_nInBufWord;
      }
      else
      {
        if ( v27.m_pDataIn <= v27.m_pBufferEnd )
        {
          v9 = *v27.m_pDataIn;
          m_pDataIn = ++v27.m_pDataIn;
        }
        else
        {
          v27.m_bOverflow = true;
          v9 = 0;
        }
        LOBYTE(v10) = v27.m_nInBufWord;
      }
    }
  }
  v27.m_nInBufWord = v9;
  if ( (_BYTE)v10 != 110 )
    return 0;
  if ( v8 < 8 )
  {
    v16 = 8 - v8;
    v17 = v9;
    if ( m_pDataIn == m_pBufferEnd )
      return 0;
    if ( m_pDataIn > m_pBufferEnd )
      return 0;
    v18 = *m_pDataIn++;
    v27.m_pDataIn = m_pDataIn;
    if ( v27.m_bOverflow )
      return 0;
    buf.m_pDebugName = (const char *)(v18 & CBitBuffer::s_nMaskTable[v16]);
    v19 = ((int)buf.m_pDebugName << v8) | v17;
    v14 = 32 - v16;
    v15 = v18 >> v16;
    m_pBufferEnd = v27.m_pBufferEnd;
    v27.m_nBitsAvail = 32 - v16;
    v13 = v19;
  }
  else
  {
    v13 = (unsigned __int8)v9;
    v14 = v8 - 8;
    v27.m_nBitsAvail = v14;
    if ( v14 != 0 )
    {
      v15 = v9 >> 8;
    }
    else
    {
      v14 = 32;
      v27.m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        v15 = 0;
        v14 = 1;
        ++m_pDataIn;
        v27.m_nBitsAvail = 1;
        v27.m_pDataIn = m_pDataIn;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v15 = *m_pDataIn++;
        v27.m_pDataIn = m_pDataIn;
      }
      else
      {
        v27.m_bOverflow = true;
        v15 = 0;
      }
    }
  }
  v27.m_nInBufWord = v15;
  if ( v13 != 1 )
    return 0;
  if ( v14 < 32 )
  {
    if ( m_pDataIn == m_pBufferEnd || m_pDataIn > m_pBufferEnd || (v20 = *m_pDataIn, v27.m_bOverflow) )
    {
      *id = 0;
      return 1;
    }
    else
    {
      *id = v15 | ((v20 & CBitBuffer::s_nMaskTable[32 - v14]) << v14);
      return 1;
    }
  }
  else
  {
    *id = v15;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FA40
// Name: private: virtual bool CPhoneHome::IsExternalBuild(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhoneHome::IsExternalBuild(CPhoneHome *this)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-publicbuild") != 0 )
    return true;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-internalbuild") == 0 )
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-dev", a3: 0) == 0 )
      return true;
  }
  if ( this->m_bPhoneHome )
    return _V_stricmp(s1: this->m_szBuildIdentifier, s2: "beta-playtest") != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1018FAC0
// Name: public: virtual void CPhoneHome::Message(unsigned char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::Message(CPhoneHome *this, unsigned __int8 msgtype, const char *mapname)
{
  int v4; // eax

  if ( this->m_bPhoneHome && this->m_pSocket != nullptr )
  {
    if ( msgtype != 1 )
    {
      if ( msgtype == 3 )
      {
        if ( this->m_bLevelStarted )
          return;
        this->m_bLevelStarted = true;
      }
      else
      {
        if ( msgtype != 4 )
        {
LABEL_11:
          CPhoneHome::SendSessionMessage(this, msgtype, mapname);
          return;
        }
        if ( !this->m_bLevelStarted )
          return;
        this->m_bLevelStarted = false;
      }
      v4 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-makereslists") != 0 )
        return;
      goto LABEL_11;
    }
    if ( !CPhoneHome::RequestSessionId(this, id: &this->m_uSessionID) )
      CPhoneHome::ExitApp(this);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1018F4F0
// Name: public: virtual void CPhoneHome::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::Shutdown(CPhoneHome *this)
{
  CBlockingUDPSocket *m_pSocket; // ecx

  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
    ((void (__thiscall *)(CBlockingUDPSocket *, int))m_pSocket->dtr_CBlockingUDPSocket)(a1: m_pSocket, a2: 1);
  this->m_pSocket = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1018F510
// Name: public: virtual void CPhoneHome::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::Init(CPhoneHome *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  const char *v7; // esi
  int v8; // eax
  char *i; // eax
  CBlockingUDPSocket *v10; // eax
  int v11; // [esp+0h] [ebp-2Ch]
  int v12; // [esp+0h] [ebp-2Ch]
  int v13; // [esp+0h] [ebp-2Ch]
  char build_identifier[32]; // [esp+Ch] [ebp-20h] BYREF

  V_strncpy(pDest: build_identifier, pSrc: "VLV_INTERNAL                    ", maxLen: 32);
  v2 = _CommandLine(a1: v11);
  v3 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-bi");
  if ( v3 > 0 )
  {
    v4 = _CommandLine(a1: v12);
    v5 = v3 + 1;
    if ( v5 >= (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 36))(a1: v4) )
    {
      build_identifier[0] = 33;
    }
    else
    {
      v6 = _CommandLine(a1: v13);
      v7 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 44))(a1: v6, a2: v5);
      _V_memset(dest: build_identifier, fill: 0, count: 32);
      V_strncpy(pDest: build_identifier, pSrc: v7, maxLen: 32);
    }
  }
  if ( _V_strlen(str: build_identifier) >= 1 )
  {
    v8 = _V_strlen(str: "VLV_INTERNAL");
    if ( V_strnicmp(s1: build_identifier, s2: "VLV_INTERNAL", n: v8) != 0 )
    {
      for ( i = &build_identifier[_V_strlen(str: build_identifier) - 1]; i > build_identifier; *i-- = 0 )
      {
        if ( *i != 32 )
          break;
      }
      if ( NET_StringToAdr(s: "207.173.177.12:27013", a: &this->m_cserIP) != 0 )
      {
        this->m_bPhoneHome = true;
        V_strncpy(pDest: this->m_szBuildIdentifier, pSrc: build_identifier, maxLen: 32);
        v10 = (CBlockingUDPSocket *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v10 != nullptr )
          this->m_pSocket = CBlockingUDPSocket::CBlockingUDPSocket(this: v10);
        else
          this->m_pSocket = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F640
// Name: private: void CPhoneHome::ExitApp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::ExitApp(CPhoneHome *this)
{
  _Error(a1: g_pszExitMsg, 212);
}

//------------------------------------------------------------------------------
// Address: 0x1018F660
// Name: private: void CPhoneHome::BuildMessage(class bf_write __near &,unsigned char,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::BuildMessage(
        CPhoneHome *this,
        int buf,
        unsigned __int8 msgtype,
        const char *mapname,
        const char *uSessionID)
{
  bf_write *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int i; // ecx
  IceSubkey *keysched; // esi
  int v12; // eax
  unsigned int v13; // edi
  int val; // [esp+4h] [ebp-8B4h]
  _BYTE pData[4]; // [esp+Ch] [ebp-8ACh] BYREF
  unsigned __int8 encrypted_data[2048]; // [esp+10h] [ebp-8A8h] BYREF
  char gamedir[64]; // [esp+810h] [ebp-A8h] BYREF
  char username[64]; // [esp+850h] [ebp-68h] BYREF
  IceKey cipher; // [esp+890h] [ebp-28h] BYREF
  bf_write encrypted; // [esp+89Ch] [ebp-1Ch] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+8B4h] [ebp-4h]

  bf_write::bf_write(this: (bf_write *)&cipher._keysched);
  v6 = (bf_write *)buf;
  bf_write::WriteByte(this: (bf_write *)buf, val: 0x6Du);
  bf_write::WriteByte(this: v6, val: 0xAu);
  bf_write::WriteByte(this: v6, val: 3u);
  bf_write::WriteLong(this: v6, val: (int)uSessionID);
  IceKey::IceKey(this: (IceKey *)&username[60], n: 1);
  encrypted.m_pDebugName = (const char *)-570424897;
  *(_DWORD *)ucEncryptionKey = 26879829;
  IceKey::set(this: (IceKey *)&username[60], key: (const unsigned __int8 *)&encrypted.m_pDebugName);
  bf_write::StartWriting(this: (bf_write *)&cipher._keysched, pData, nBytes: 2048, iStartBit: 0, nBits: -1);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 1u);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 1u);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: this->m_szBuildIdentifier);
  _V_memset(dest: &gamedir[60], fill: 0, count: 64);
  buf = 63;
  if ( !GetComputerNameA(lpBuffer: &gamedir[60], nSize: (LPDWORD)&buf) )
    V_strncpy(pDest: &gamedir[60], pSrc: "???", maxLen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: &gamedir[60]);
  _V_memset(dest: &gamedir[60], fill: 0, count: 64);
  buf = 63;
  if ( !GetUserNameA(lpBuffer: &gamedir[60], pcbBuffer: (LPDWORD)&buf) )
    V_strncpy(pDest: &gamedir[60], pSrc: "???", maxLen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: &gamedir[60]);
  V_FileBase(in: com_gamedir, out: (char *)&encrypted_data[2044], maxlen: 64);
  bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: (const char *)&encrypted_data[2044]);
  v7 = build_number();
  bf_write::WriteLong(this: (bf_write *)&cipher._keysched, val: v7);
  bf_write::WriteFloat(this: (bf_write *)&cipher._keysched, val: realtime);
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: msgtype);
  if ( mapname != nullptr )
    bf_write::WriteString(this: (bf_write *)&cipher._keysched, pStr: mapname);
  if ( Sys_IsDebuggerPresent()
    || (v8 = _CommandLine(a1: val),
        (v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-allowdebug")) != 0) )
  {
    v9 = 1;
  }
  bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: v9);
  for ( i = encrypted.m_nDataBits; ((encrypted.m_nDataBits + 7) >> 3) % 8 != 0; i = encrypted.m_nDataBits )
    bf_write::WriteByte(this: (bf_write *)&cipher._keysched, val: 0);
  keysched = cipher._keysched;
  v12 = (i + 7) >> 3;
  if ( v12 != 0 )
  {
    v13 = ((unsigned int)(v12 - 1) >> 3) + 1;
    do
    {
      IceKey::encrypt(
        this: (IceKey *)&username[60],
        ptext: (const unsigned __int8 *)keysched,
        ctext: (unsigned __int8 *)keysched);
      keysched = (IceSubkey *)((char *)keysched + 8);
      --v13;
    }
    while ( v13 != 0 );
    i = encrypted.m_nDataBits;
  }
  bf_write::WriteShort(this: v6, val: (i + 7) >> 3);
  bf_write::WriteBytes(this: v6, pBuf: cipher._keysched, nBytes: (encrypted.m_nDataBits + 7) >> 3);
  IceKey::~IceKey(this: (IceKey *)&username[60]);
}

//------------------------------------------------------------------------------
// Address: 0x1018F8B0
// Name: private: void CPhoneHome::SendSessionMessage(unsigned char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhoneHome::SendSessionMessage(CPhoneHome *this, unsigned __int8 msgtype, const char *mapname)
{
  int v4; // eax
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // ebx
  int v7; // esi
  unsigned int v8; // eax
  char m_nInBufWord; // cl
  int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // ebx
  int v17; // edi
  unsigned int v18; // eax
  char v19; // cl
  unsigned int v20; // ebx
  unsigned int v21; // edx
  _BYTE pData[4]; // [esp+Ch] [ebp-8E0h] BYREF
  unsigned __int8 data[2048]; // [esp+10h] [ebp-8DCh] BYREF
  unsigned __int8 readbuf[128]; // [esp+810h] [ebp-DCh] BYREF
  sockaddr_in replyaddress; // [esp+890h] [ebp-5Ch] BYREF
  sockaddr_in sa; // [esp+8A0h] [ebp-4Ch] BYREF
  bf_write buf; // [esp+8B0h] [ebp-3Ch]
  CBitRead v28; // [esp+8C8h] [ebp-24h] BYREF

  buf.m_pDebugName = (const char *)this;
  if ( this->m_uSessionID != 0 )
  {
    bf_write::bf_write(this: (bf_write *)&sa.sin_zero[4]);
    bf_write::StartWriting(this: (bf_write *)&sa.sin_zero[4], pData, nBytes: 2048, iStartBit: 0, nBits: -1);
    CPhoneHome::BuildMessage(
      this,
      buf: (int)&sa.sin_zero[4],
      msgtype,
      mapname,
      uSessionID: (const char *)this->m_uSessionID);
    netadr_s::ToSockadr(this: &this->m_cserIP, s: (sockaddr *)&replyaddress.sin_zero[4]);
    CBlockingUDPSocket::SendSocketMessage(
      this: this->m_pSocket,
      rRecipient: (const sockaddr_in *)&replyaddress.sin_zero[4],
      buf: *(const unsigned __int8 **)&sa.sin_zero[4],
      bufsize: (buf.m_nDataBits + 7) >> 3);
    if ( this->m_uSessionID == 0 && CBlockingUDPSocket::WaitForMessage(this: this->m_pSocket, timeOutInSeconds: 1.5) )
    {
      v28.m_bOverflow = false;
      v28.m_pDebugName = nullptr;
      v28.m_nDataBits = -1;
      v28.m_nDataBytes = 0;
      CBitRead::StartReading(this: &v28, pData: &data[2044], nBytes: 128, iStartBit: 0, nBits: -1);
      v4 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: this->m_pSocket,
             packet_from: (sockaddr_in *)&readbuf[124],
             buf: &data[2044],
             bufsize: 0x80u);
      if ( v4 != 0 )
      {
        CBitRead::StartReading(this: &v28, pData: &data[2044], nBytes: v4, iStartBit: 0, nBits: -1);
        m_pDataIn = v28.m_pDataIn;
        if ( v28.m_nBitsAvail < 8 )
        {
          v10 = 8 - v28.m_nBitsAvail;
          if ( v28.m_pDataIn == v28.m_pBufferEnd )
            return;
          if ( v28.m_pDataIn > v28.m_pBufferEnd )
            return;
          v11 = *v28.m_pDataIn;
          m_pDataIn = ++v28.m_pDataIn;
          if ( v28.m_bOverflow )
            return;
          v12 = ((v11 & CBitBuffer::s_nMaskTable[v10]) << SLOBYTE(v28.m_nBitsAvail)) | v28.m_nInBufWord;
          v7 = 32 - v10;
          v8 = v11 >> v10;
          m_nInBufWord = v12;
          m_pBufferEnd = v28.m_pBufferEnd;
          v28.m_nBitsAvail = 32 - v10;
        }
        else
        {
          m_pBufferEnd = v28.m_pBufferEnd;
          v7 = v28.m_nBitsAvail - 8;
          v28.m_nBitsAvail = v7;
          if ( v7 != 0 )
          {
            v8 = v28.m_nInBufWord >> 8;
            m_nInBufWord = v28.m_nInBufWord;
          }
          else
          {
            v7 = 32;
            v28.m_nBitsAvail = 32;
            if ( v28.m_pDataIn == v28.m_pBufferEnd )
            {
              v8 = 0;
              v7 = 1;
              m_pDataIn = v28.m_pDataIn + 1;
              v28.m_nBitsAvail = 1;
              ++v28.m_pDataIn;
              m_nInBufWord = v28.m_nInBufWord;
            }
            else
            {
              if ( v28.m_pDataIn <= v28.m_pBufferEnd )
              {
                v8 = *v28.m_pDataIn;
                m_pDataIn = ++v28.m_pDataIn;
              }
              else
              {
                v28.m_bOverflow = true;
                v8 = 0;
              }
              m_nInBufWord = v28.m_nInBufWord;
            }
          }
        }
        v28.m_nInBufWord = v8;
        if ( m_nInBufWord != 110 )
          return;
        if ( v7 < 8 )
        {
          v16 = v8;
          v17 = 8 - v7;
          if ( m_pDataIn == v28.m_pBufferEnd )
            return;
          if ( m_pDataIn > v28.m_pBufferEnd )
            return;
          v18 = *m_pDataIn++;
          v28.m_pDataIn = m_pDataIn;
          if ( v28.m_bOverflow )
            return;
          v19 = 8 - v7;
          v20 = ((v18 & CBitBuffer::s_nMaskTable[v17]) << v7) | v16;
          v14 = 32 - v17;
          v13 = v20;
          m_pBufferEnd = v28.m_pBufferEnd;
          v28.m_nBitsAvail = v14;
          v15 = v18 >> v19;
        }
        else
        {
          v13 = (unsigned __int8)v8;
          v14 = v7 - 8;
          v28.m_nBitsAvail = v14;
          if ( v14 != 0 )
          {
            v15 = v8 >> 8;
          }
          else
          {
            v14 = 32;
            v28.m_nBitsAvail = 32;
            if ( m_pDataIn == m_pBufferEnd )
            {
              v15 = 0;
              v14 = 1;
              ++m_pDataIn;
              v28.m_nBitsAvail = 1;
              v28.m_pDataIn = m_pDataIn;
            }
            else if ( m_pDataIn <= m_pBufferEnd )
            {
              v15 = *m_pDataIn++;
              v28.m_pDataIn = m_pDataIn;
            }
            else
            {
              v28.m_bOverflow = true;
              v15 = 0;
            }
          }
        }
        v28.m_nInBufWord = v15;
        if ( v13 == 1 )
        {
          if ( v14 < 32 )
          {
            if ( m_pDataIn == m_pBufferEnd || m_pDataIn > m_pBufferEnd || (v21 = *m_pDataIn, v28.m_bOverflow) )
              *((_DWORD *)buf.m_pDebugName + 14) = 0;
            else
              *((_DWORD *)buf.m_pDebugName + 14) = v15 | ((v21 & CBitBuffer::s_nMaskTable[32 - v14]) << v14);
          }
          else
          {
            *((_DWORD *)buf.m_pDebugName + 14) = v15;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FB80
// Name: private: bool CPhoneHome::RequestSessionId(unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhoneHome::RequestSessionId(CPhoneHome *this, unsigned int *id)
{
  int v3; // edi
  int v4; // eax
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // ecx
  int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  int v11; // edi
  unsigned int v12; // eax
  int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned int v20; // edx
  _BYTE pData[4]; // [esp+10h] [ebp-8E0h] BYREF
  unsigned __int8 data[2048]; // [esp+14h] [ebp-8DCh] BYREF
  unsigned __int8 readbuf[128]; // [esp+814h] [ebp-DCh] BYREF
  sockaddr_in replyaddress; // [esp+894h] [ebp-5Ch] BYREF
  sockaddr_in sa; // [esp+8A4h] [ebp-4Ch] BYREF
  bf_write buf; // [esp+8B4h] [ebp-3Ch]
  CBitRead v27; // [esp+8CCh] [ebp-24h] BYREF

  *id = 0;
  bf_write::bf_write(this: (bf_write *)&sa.sin_zero[4]);
  bf_write::StartWriting(this: (bf_write *)&sa.sin_zero[4], pData, nBytes: 2048, iStartBit: 0, nBits: -1);
  CPhoneHome::BuildMessage(
    this,
    buf: (int)&sa.sin_zero[4],
    msgtype: 1u,
    mapname: nullptr,
    uSessionID: (const char *)*id);
  netadr_s::ToSockadr(this: &this->m_cserIP, s: (sockaddr *)&replyaddress.sin_zero[4]);
  v3 = 0;
  while ( 1 )
  {
    CBlockingUDPSocket::SendSocketMessage(
      this: this->m_pSocket,
      rRecipient: (const sockaddr_in *)&replyaddress.sin_zero[4],
      buf: *(const unsigned __int8 **)&sa.sin_zero[4],
      bufsize: (buf.m_nDataBits + 7) >> 3);
    if ( CBlockingUDPSocket::WaitForMessage(this: this->m_pSocket, timeOutInSeconds: 1.5) )
    {
      v27.m_bOverflow = false;
      v27.m_pDebugName = nullptr;
      v27.m_nDataBits = -1;
      v27.m_nDataBytes = 0;
      CBitRead::StartReading(this: &v27, pData: &data[2044], nBytes: 128, iStartBit: 0, nBits: -1);
      v4 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: this->m_pSocket,
             packet_from: (sockaddr_in *)&readbuf[124],
             buf: &data[2044],
             bufsize: 0x80u);
      if ( v4 != 0 )
        break;
    }
    if ( ++v3 >= 3 )
      return 0;
  }
  CBitRead::StartReading(this: &v27, pData: &data[2044], nBytes: v4, iStartBit: 0, nBits: -1);
  m_pDataIn = v27.m_pDataIn;
  if ( v27.m_nBitsAvail < 8 )
  {
    v11 = 8 - v27.m_nBitsAvail;
    if ( v27.m_pDataIn == v27.m_pBufferEnd )
      return 0;
    if ( v27.m_pDataIn > v27.m_pBufferEnd )
      return 0;
    v12 = *v27.m_pDataIn;
    m_pDataIn = ++v27.m_pDataIn;
    if ( v27.m_bOverflow )
      return 0;
    buf.m_pDebugName = (const char *)(v12 & CBitBuffer::s_nMaskTable[v11]);
    v10 = ((int)buf.m_pDebugName << SLOBYTE(v27.m_nBitsAvail)) | v27.m_nInBufWord;
    v8 = 32 - v11;
    v9 = v12 >> v11;
    m_pBufferEnd = v27.m_pBufferEnd;
    v27.m_nBitsAvail = 32 - v11;
  }
  else
  {
    m_pBufferEnd = v27.m_pBufferEnd;
    v8 = v27.m_nBitsAvail - 8;
    v27.m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      v9 = v27.m_nInBufWord >> 8;
      LOBYTE(v10) = v27.m_nInBufWord;
    }
    else
    {
      v8 = 32;
      v27.m_nBitsAvail = 32;
      if ( v27.m_pDataIn == v27.m_pBufferEnd )
      {
        v9 = 0;
        v8 = 1;
        m_pDataIn = v27.m_pDataIn + 1;
        v27.m_nBitsAvail = 1;
        ++v27.m_pDataIn;
        LOBYTE(v10) = v27.m_nInBufWord;
      }
      else
      {
        if ( v27.m_pDataIn <= v27.m_pBufferEnd )
        {
          v9 = *v27.m_pDataIn;
          m_pDataIn = ++v27.m_pDataIn;
        }
        else
        {
          v27.m_bOverflow = true;
          v9 = 0;
        }
        LOBYTE(v10) = v27.m_nInBufWord;
      }
    }
  }
  v27.m_nInBufWord = v9;
  if ( (_BYTE)v10 != 110 )
    return 0;
  if ( v8 < 8 )
  {
    v16 = 8 - v8;
    v17 = v9;
    if ( m_pDataIn == m_pBufferEnd )
      return 0;
    if ( m_pDataIn > m_pBufferEnd )
      return 0;
    v18 = *m_pDataIn++;
    v27.m_pDataIn = m_pDataIn;
    if ( v27.m_bOverflow )
      return 0;
    buf.m_pDebugName = (const char *)(v18 & CBitBuffer::s_nMaskTable[v16]);
    v19 = ((int)buf.m_pDebugName << v8) | v17;
    v14 = 32 - v16;
    v15 = v18 >> v16;
    m_pBufferEnd = v27.m_pBufferEnd;
    v27.m_nBitsAvail = 32 - v16;
    v13 = v19;
  }
  else
  {
    v13 = (unsigned __int8)v9;
    v14 = v8 - 8;
    v27.m_nBitsAvail = v14;
    if ( v14 != 0 )
    {
      v15 = v9 >> 8;
    }
    else
    {
      v14 = 32;
      v27.m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        v15 = 0;
        v14 = 1;
        ++m_pDataIn;
        v27.m_nBitsAvail = 1;
        v27.m_pDataIn = m_pDataIn;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v15 = *m_pDataIn++;
        v27.m_pDataIn = m_pDataIn;
      }
      else
      {
        v27.m_bOverflow = true;
        v15 = 0;
      }
    }
  }
  v27.m_nInBufWord = v15;
  if ( v13 != 1 )
    return 0;
  if ( v14 < 32 )
  {
    if ( m_pDataIn == m_pBufferEnd || m_pDataIn > m_pBufferEnd || (v20 = *m_pDataIn, v27.m_bOverflow) )
    {
      *id = 0;
      return 1;
    }
    else
    {
      *id = v15 | ((v20 & CBitBuffer::s_nMaskTable[32 - v14]) << v14);
      return 1;
    }
  }
  else
  {
    *id = v15;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FE40
// Name: private: virtual bool CPhoneHome::IsExternalBuild(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhoneHome::IsExternalBuild(CPhoneHome *this)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+0h] [ebp-8h]

  v2 = _CommandLine(a1: v6);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-publicbuild") != 0 )
    return true;
  v4 = _CommandLine(a1: v7);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-internalbuild") == 0 )
  {
    v5 = _CommandLine(a1: v8);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-dev", a3: 0) == 0 )
      return true;
  }
  if ( this->m_bPhoneHome )
    return _V_stricmp(s1: this->m_szBuildIdentifier, s2: "beta-playtest") != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1018FEC0
// Name: public: virtual void CPhoneHome::Message(unsigned char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhoneHome::Message(
        CPhoneHome *this@<ecx>,
        int a2@<ebx>,
        unsigned __int8 msgtype,
        const char *mapname)
{
  int v5; // eax

  if ( this->m_bPhoneHome && this->m_pSocket != nullptr )
  {
    if ( msgtype != 1 )
    {
      if ( msgtype == 3 )
      {
        if ( this->m_bLevelStarted )
          return;
        this->m_bLevelStarted = true;
      }
      else
      {
        if ( msgtype != 4 )
        {
LABEL_11:
          CPhoneHome::SendSessionMessage(this, msgtype, mapname);
          return;
        }
        if ( !this->m_bLevelStarted )
          return;
        this->m_bLevelStarted = false;
      }
      v5 = _CommandLine(a1: a2);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-makereslists") != 0 )
        return;
      goto LABEL_11;
    }
    if ( CPhoneHome::RequestSessionId(this, id: &this->m_uSessionID) == 0 )
      CPhoneHome::ExitApp(this);
  }
}

} // namespace engine_xlsp
