// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_uploaddata.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10130170
// Name: BuildUploadDataMessage
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildUploadDataMessage(bf_write *buf@<edi>, KeyValues *fields@<eax>, const char *tablename)
{
  int v4; // ebx
  KeyValues *FirstSubKey; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  char *String; // eax
  int j; // ecx
  unsigned __int8 *m_pData; // esi
  int v11; // eax
  unsigned int v12; // ebx
  unsigned __int8 encrypted_data[2048]; // [esp+8h] [ebp-82Ch] BYREF
  IceKey cipher; // [esp+808h] [ebp-2Ch] BYREF
  bf_write encrypted; // [esp+814h] [ebp-20h] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+82Ch] [ebp-8h] BYREF

  bf_write::bf_write(this: &encrypted);
  bf_write::WriteByte(this: buf, val: 0x71u);
  bf_write::WriteByte(this: buf, val: 0xAu);
  bf_write::WriteByte(this: buf, val: 1u);
  IceKey::IceKey(this: &cipher, n: 1);
  *(_DWORD *)ucEncryptionKey = 94744374;
  *(_DWORD *)&ucEncryptionKey[4] = 1897790284;
  IceKey::set(this: &cipher, key: ucEncryptionKey);
  bf_write::StartWriting(this: &encrypted, pData: encrypted_data, nBytes: 2048, iStartBit: 0, nBits: -1);
  bf_write::WriteByte(this: &encrypted, val: 1u);
  bf_write::WriteByte(this: &encrypted, val: 1u);
  bf_write::WriteString(this: &encrypted, pStr: tablename);
  v4 = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: fields);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      ++v4;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    if ( v4 > 255 )
      Host_Error(error: "Too many fields in uploaddata (%i max = 255)\n", v4);
  }
  bf_write::WriteByte(this: &encrypted, val: (unsigned __int8)v4);
  for ( i = KeyValues::GetFirstSubKey(this: fields); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    bf_write::WriteString(this: &encrypted, pStr: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    bf_write::WriteString(this: &encrypted, pStr: String);
  }
  for ( j = encrypted.m_iCurBit; ((encrypted.m_iCurBit + 7) >> 3) % 8 != 0; j = encrypted.m_iCurBit )
    bf_write::WriteByte(this: &encrypted, val: 0);
  m_pData = encrypted.m_pData;
  v11 = (j + 7) >> 3;
  if ( v11 != 0 )
  {
    v12 = ((unsigned int)(v11 - 1) >> 3) + 1;
    do
    {
      IceKey::encrypt(this: &cipher, ptext: m_pData, ctext: m_pData);
      m_pData += 8;
      --v12;
    }
    while ( v12 != 0 );
    j = encrypted.m_iCurBit;
  }
  bf_write::WriteShort(this: buf, val: (j + 7) >> 3);
  bf_write::WriteBytes(this: buf, pBuf: encrypted.m_pData, nBytes: (encrypted.m_iCurBit + 7) >> 3);
  IceKey::~IceKey(this: &cipher);
}

//------------------------------------------------------------------------------
// Address: 0x10130320
// Name: bool UploadData(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UploadData(const char *cserIP, const char *tablename, KeyValues *fields)
{
  CBlockingUDPSocket *v3; // eax
  CBlockingUDPSocket *v4; // esi
  unsigned __int8 data[2048]; // [esp+8h] [ebp-834h] BYREF
  sockaddr_in sa; // [esp+808h] [ebp-34h] BYREF
  bf_write buf; // [esp+818h] [ebp-24h] BYREF
  netadr_s cseradr; // [esp+830h] [ebp-Ch] BYREF

  bf_write::bf_write(this: &buf);
  bf_write::StartWriting(this: &buf, pData: data, nBytes: 2048, iStartBit: 0, nBits: -1);
  BuildUploadDataMessage(&buf, fields, tablename);
  netadr_s::SetIP(this: &cseradr, unIP: 0);
  netadr_s::SetPort(this: &cseradr, newport: 0);
  netadr_s::SetType(this: &cseradr, newtype: NA_IP);
  if ( !NET_StringToAdr(s: cserIP, a: &cseradr) )
    return 0;
  v3 = (CBlockingUDPSocket *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 == nullptr )
    return 0;
  v4 = CBlockingUDPSocket::CBlockingUDPSocket(this: v3);
  if ( v4 == nullptr )
    return 0;
  netadr_s::ToSockadr(this: &cseradr, s: (sockaddr *)&sa);
  CBlockingUDPSocket::SendSocketMessage(this: v4, rRecipient: &sa, buf: buf.m_pData, bufsize: (buf.m_iCurBit + 7) >> 3);
  ((void (__thiscall *)(CBlockingUDPSocket *, int))v4->dtr_CBlockingUDPSocket)(a1: v4, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101303F0
// Name: __CreateCUploadGameStatsIUploadGameStats_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUploadGameStats *__cdecl _CreateCUploadGameStatsIUploadGameStats_interface()
{
  return &g_UploadGameStats;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10130250
// Name: BuildUploadDataMessage
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildUploadDataMessage(bf_write *buf@<edi>, KeyValues *fields@<eax>, const char *tablename)
{
  int v4; // ebx
  KeyValues *FirstSubKey; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  int j; // ecx
  unsigned __int8 *m_pData; // esi
  int v11; // eax
  unsigned int v12; // ebx
  unsigned __int8 encrypted_data[2048]; // [esp+8h] [ebp-82Ch] BYREF
  IceKey cipher; // [esp+808h] [ebp-2Ch] BYREF
  bf_write encrypted; // [esp+814h] [ebp-20h] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+82Ch] [ebp-8h] BYREF

  bf_write::bf_write(this: &encrypted);
  bf_write::WriteByte(this: buf, val: 0x71u);
  bf_write::WriteByte(this: buf, val: 0xAu);
  bf_write::WriteByte(this: buf, val: 1u);
  IceKey::IceKey(this: &cipher, n: 1);
  *(_DWORD *)ucEncryptionKey = 94744374;
  *(_DWORD *)&ucEncryptionKey[4] = 1897790284;
  IceKey::set(this: &cipher, key: ucEncryptionKey);
  bf_write::StartWriting(this: &encrypted, pData: encrypted_data, nBytes: 2048, iStartBit: 0, nBits: -1);
  bf_write::WriteByte(this: &encrypted, val: 1u);
  bf_write::WriteByte(this: &encrypted, val: 1u);
  bf_write::WriteString(this: &encrypted, pStr: tablename);
  v4 = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: fields);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      ++v4;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    if ( v4 > 255 )
      Host_Error(error: "Too many fields in uploaddata (%i max = 255)\n", v4);
  }
  bf_write::WriteByte(this: &encrypted, val: (unsigned __int8)v4);
  for ( i = KeyValues::GetFirstSubKey(this: fields); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    bf_write::WriteString(this: &encrypted, pStr: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    bf_write::WriteString(this: &encrypted, pStr: String);
  }
  for ( j = encrypted.m_iCurBit; ((encrypted.m_iCurBit + 7) >> 3) % 8 != 0; j = encrypted.m_iCurBit )
    bf_write::WriteByte(this: &encrypted, val: 0);
  m_pData = encrypted.m_pData;
  v11 = (j + 7) >> 3;
  if ( v11 != 0 )
  {
    v12 = ((unsigned int)(v11 - 1) >> 3) + 1;
    do
    {
      IceKey::encrypt(this: &cipher, ptext: m_pData, ctext: m_pData);
      m_pData += 8;
      --v12;
    }
    while ( v12 != 0 );
    j = encrypted.m_iCurBit;
  }
  bf_write::WriteShort(this: buf, val: (j + 7) >> 3);
  bf_write::WriteBytes(this: buf, pBuf: encrypted.m_pData, nBytes: (encrypted.m_iCurBit + 7) >> 3);
  IceKey::~IceKey(this: &cipher);
}

//------------------------------------------------------------------------------
// Address: 0x10130400
// Name: bool UploadData(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UploadData(const char *cserIP, const char *tablename, KeyValues *fields)
{
  CBlockingUDPSocket *v3; // eax
  CBlockingUDPSocket *v4; // esi
  unsigned __int8 data[2048]; // [esp+8h] [ebp-834h] BYREF
  sockaddr_in sa; // [esp+808h] [ebp-34h] BYREF
  bf_write buf; // [esp+818h] [ebp-24h] BYREF
  netadr_s cseradr; // [esp+830h] [ebp-Ch] BYREF

  bf_write::bf_write(this: &buf);
  bf_write::StartWriting(this: &buf, pData: data, nBytes: 2048, iStartBit: 0, nBits: -1);
  BuildUploadDataMessage(&buf, fields, tablename);
  netadr_s::SetIP(this: &cseradr, unIP: 0);
  netadr_s::SetPort(this: &cseradr, newport: 0);
  netadr_s::SetType(this: &cseradr, newtype: NA_IP);
  if ( NET_StringToAdr(s: cserIP, a: &cseradr) == 0 )
    return 0;
  v3 = (CBlockingUDPSocket *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 == nullptr )
    return 0;
  v4 = CBlockingUDPSocket::CBlockingUDPSocket(this: v3);
  if ( v4 == nullptr )
    return 0;
  netadr_s::ToSockadr(this: &cseradr, s: (sockaddr *)&sa);
  CBlockingUDPSocket::SendSocketMessage(this: v4, rRecipient: &sa, buf: buf.m_pData, bufsize: (buf.m_iCurBit + 7) >> 3);
  ((void (__thiscall *)(CBlockingUDPSocket *, int))v4->dtr_CBlockingUDPSocket)(a1: v4, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101304D0
// Name: __CreateCUploadGameStatsIUploadGameStats_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUploadGameStats *__cdecl _CreateCUploadGameStatsIUploadGameStats_interface()
{
  return &g_UploadGameStats;
}

} // namespace engine_xlsp
