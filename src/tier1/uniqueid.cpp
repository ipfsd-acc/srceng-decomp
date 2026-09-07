// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/uniqueid.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10278B00
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10278B10
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278B30
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278BA0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x10278BC0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x004643C0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x004643D0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004643F0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00464460
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004644B0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x004644D0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00571600
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00571610
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00571630
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005716A0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005716F0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00571710
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D4300
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x005D4310
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005D4330
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005D43A0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D43F0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x005D4410
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10278C30
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10278C40
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278C60
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278CD0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x10278CF0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, const char *pBuf, int nMaxLen)
{
  int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B4BD0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x102B4BE0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C00
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C70
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4CC0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x102B4CE0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = std::char_traits<char>::length(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4D90
// Name: bool IsUniqueIdValid(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUniqueIdValid(const UniqueId_t *id)
{
  UniqueId_t invalidId; // [esp+0h] [ebp-10h] BYREF

  memset(&invalidId, 0, sizeof(invalidId));
  return IsUniqueIdEqual(id1: &invalidId, id2: id) == 0;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00578890
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x005788A0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005788C0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00578930
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578980
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x005789A0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00531920
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00531930
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00531950
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005319C0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531A10
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00531A30
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C1DD0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x005C1DE0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005C1E00
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005C1E70
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1EC0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x005C1EE0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00496DA0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00496DB0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00496DD0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00496E40
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496E90
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00496EB0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B5EB0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x004B5EC0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5EE0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5F50
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x004B5F70
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00538680
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00538690
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005386B0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00538720
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538770
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00538790
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00423D20
// Name: bool Unserialize<class Color>(class CUtlBuffer __near &,class CUtlVector<class Color,class CUtlMemory<class Color,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<Color>(CUtlBuffer *buf, CUtlVector<Color,CUtlMemory<Color,int> > *dest)
{
  CUtlVector<Color,CUtlMemory<Color,int> > *v2; // esi
  int v3; // edi
  CUtlVector<Color,CUtlMemory<Color,int> > *v4; // ebp
  int m_Size; // edi
  int m_nAllocationCount; // eax
  Color *m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  Color *v11; // eax

  v2 = dest;
  v3 = 0;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
    {
      return true;
    }
    else
    {
      while ( 1 )
      {
        m_Size = v2->m_Size;
        m_nAllocationCount = v2->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)v2,
            num: m_Size - m_nAllocationCount + 1);
        ++v2->m_Size;
        m_pMemory = v2->m_Memory.m_pMemory;
        v9 = v2->m_Size - m_Size - 1;
        v10 = v2->m_Size - m_Size == 1;
        v2->m_pElements = v2->m_Memory.m_pMemory;
        if ( v9 >= 0 && !v10 )
          memmove(
            dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v9);
        v11 = &v2->m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = 0;
        if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[m_Size]) )
          break;
        CUtlBuffer::EatWhiteSpace(this: buf);
        if ( buf->m_Error != 0 )
          return true;
      }
      return false;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v4 = dest;
    if ( dest != nullptr
      && (CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: v2, num: (int)dest), (int)v4 > 0) )
    {
      while ( 1 )
      {
        CUtlVector<Color,CUtlMemory<Color,int>>::InsertBefore(this: v2, elem: v2->m_Size);
        if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[v3]) )
          break;
        if ( ++v3 >= (int)v4 )
          return buf->m_Error == 0;
      }
      return false;
    }
    else
    {
      return buf->m_Error == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423E30
// Name: bool Serialize<class Color>(class CUtlBuffer __near &,class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<Color>(CUtlBuffer *buf, const CUtlVector<Color,CUtlMemory<Color,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        ++buf->m_Put;
        CUtlBuffer::AddNullTermination(this: buf);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423F10
// Name: bool Unserialize<class Vector2D>(class CUtlBuffer __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Unserialize<Vector2D>(CUtlBuffer *buf, CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *dest)
{
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v2; // esi
  int v3; // ebp
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v4; // edi
  int v5; // edi
  int v6; // eax
  Vector2D *v7; // ecx
  int v8; // eax
  bool v9; // zf
  int m_Size; // edi
  int m_nAllocationCount; // eax
  Vector2D *m_pMemory; // ecx
  int v14; // eax

  v2 = dest;
  v3 = 0;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return 1;
    while ( 1 )
    {
      m_Size = v2->m_Size;
      m_nAllocationCount = v2->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>::Grow(
          this: &v2->m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++v2->m_Size;
      m_pMemory = v2->m_Memory.m_pMemory;
      v14 = v2->m_Size - m_Size - 1;
      v9 = v2->m_Size - m_Size == 1;
      v2->m_pElements = v2->m_Memory.m_pMemory;
      if ( v14 >= 0 && !v9 )
        memmove(
          dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 8 * v14);
      if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[m_Size]) )
        break;
      CUtlBuffer::EatWhiteSpace(this: buf);
      if ( buf->m_Error != 0 )
        return 1;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v4 = dest;
    if ( dest == nullptr )
      return buf->m_Error == 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(this: v2, num: (int)dest);
    if ( (int)v4 <= 0 )
      return buf->m_Error == 0;
    while ( 1 )
    {
      v5 = v2->m_Size;
      v6 = v2->m_Memory.m_nAllocationCount;
      if ( v5 + 1 > v6 )
        CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>::Grow(this: &v2->m_Memory, num: v5 - v6 + 1);
      ++v2->m_Size;
      v7 = v2->m_Memory.m_pMemory;
      v8 = v2->m_Size - v5 - 1;
      v9 = v2->m_Size - v5 == 1;
      v2->m_pElements = v2->m_Memory.m_pMemory;
      if ( v8 >= 0 && !v9 )
        memmove(dst: (unsigned __int8 *)&v7[v5 + 1], src: (unsigned __int8 *)&v7[v5], count: 8 * v8);
      if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[v3]) )
        break;
      if ( ++v3 >= (int)dest )
        return buf->m_Error == 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424050
// Name: bool Serialize<class Vector2D>(class CUtlBuffer __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<Vector2D>(CUtlBuffer *buf, const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        ++buf->m_Put;
        CUtlBuffer::AddNullTermination(this: buf);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424130
// Name: bool Unserialize<class QAngle>(class CUtlBuffer __near &,class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<QAngle>(CUtlBuffer *buf, CUtlVector<QAngle,CUtlMemory<QAngle,int> > *dest)
{
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v2; // esi
  int v3; // ebp
  CUtlBuffer *v4; // edi
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v5; // ebx
  int i; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  QAngle *m_pMemory; // ecx
  int v11; // eax
  bool v12; // zf

  v2 = dest;
  v3 = 0;
  v4 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
    {
      return true;
    }
    else
    {
      while ( 1 )
      {
        m_Size = v2->m_Size;
        m_nAllocationCount = v2->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)v2,
            num: m_Size - m_nAllocationCount + 1);
        ++v2->m_Size;
        m_pMemory = v2->m_Memory.m_pMemory;
        v11 = v2->m_Size - m_Size - 1;
        v12 = v2->m_Size - m_Size == 1;
        v2->m_pElements = v2->m_Memory.m_pMemory;
        if ( v11 >= 0 && !v12 )
          memmove(
            dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 12 * v11);
        if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[m_Size]) )
          break;
        CUtlBuffer::EatWhiteSpace(this: buf);
        if ( buf->m_Error != 0 )
          return true;
      }
      return false;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v5 = dest;
    if ( dest != nullptr
      && (CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: v2, num: (int)dest), (int)v5 > 0) )
    {
      for ( i = 0; ; ++i )
      {
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::InsertBefore(
          this: (CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *)v2,
          elem: v2->m_Size);
        if ( !Unserialize(buf, dest: &v2->m_Memory.m_pMemory[i]) )
          break;
        if ( ++v3 >= (int)v5 )
        {
          v4 = buf;
          return v4->m_Error == 0;
        }
      }
      return false;
    }
    else
    {
      return v4->m_Error == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424240
// Name: bool Serialize<class Vector>(class CUtlBuffer __near &,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<Vector>(CUtlBuffer *buf, const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424330
// Name: bool Unserialize<class Quaternion>(class CUtlBuffer __near &,class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Unserialize<Quaternion>(CUtlBuffer *buf, CUtlMemory<CUtlBinaryBlock,int> *dest)
{
  CUtlBuffer *v2; // ebp
  CUtlMemory<CUtlBinaryBlock,int> *v3; // esi
  int v4; // ebx
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *v5; // edi
  int i; // ebp
  CUtlBinaryBlock *v7; // edi
  int v8; // eax
  CUtlBinaryBlock *v9; // ecx
  int v10; // eax
  bool v11; // zf
  CUtlBinaryBlock *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlBinaryBlock *v15; // ecx
  int v16; // eax

  v2 = buf;
  v3 = dest;
  v4 = 0;
  dest[1].m_pMemory = nullptr;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return 1;
    while ( 1 )
    {
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Memory.m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<Quaternion,int>::Grow(this: v3, num: (int)&m_pMemory->m_Memory.m_pMemory - m_nAllocationCount + 1);
      ++v3[1].m_pMemory;
      v15 = v3->m_pMemory;
      v16 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory == 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v16 >= 0 && !v11 )
        memmove(
          dst: (unsigned __int8 *)&v15[(int)m_pMemory + 1],
          src: (unsigned __int8 *)&v15[(_DWORD)m_pMemory],
          count: 16 * v16);
      if ( !Unserialize(buf, dest: (Quaternion *)&v3->m_pMemory[(_DWORD)m_pMemory]) )
        break;
      CUtlBuffer::EatWhiteSpace(this: buf);
      if ( buf->m_Error != 0 )
        return 1;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v5 = (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)dest;
    if ( dest == nullptr )
      return v2->m_Error == 0;
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
      this: (CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *)v3,
      num: (int)dest);
    if ( (int)v5 <= 0 )
      return v2->m_Error == 0;
    for ( i = 0; ; ++i )
    {
      v7 = v3[1].m_pMemory;
      v8 = v3->m_nAllocationCount;
      if ( (int)&v7->m_Memory.m_pMemory + 1 > v8 )
        CUtlMemory<Quaternion,int>::Grow(this: v3, num: (int)&v7->m_Memory.m_pMemory - v8 + 1);
      ++v3[1].m_pMemory;
      v9 = v3->m_pMemory;
      v10 = (char *)v3[1].m_pMemory - (char *)v7 - 1;
      v11 = (char *)v3[1].m_pMemory - (char *)v7 == 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v10 >= 0 && !v11 )
        memmove(dst: (unsigned __int8 *)&v9[(int)v7 + 1], src: (unsigned __int8 *)&v9[(_DWORD)v7], count: 16 * v10);
      if ( !Unserialize(buf, dest: (Quaternion *)&v3->m_pMemory[i]) )
        break;
      if ( ++v4 >= (int)dest )
      {
        v2 = buf;
        return v2->m_Error == 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424480
// Name: bool Serialize<class Quaternion>(class CUtlBuffer __near &,class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<Quaternion>(CUtlBuffer *buf, const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424570
// Name: bool Unserialize<class VMatrix>(class CUtlBuffer __near &,class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Unserialize<VMatrix>(CUtlBuffer *buf, CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *dest)
{
  CUtlBuffer *v2; // ebp
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v3; // esi
  int v4; // ebx
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v5; // edi
  int i; // ebp
  int v7; // edi
  int v8; // eax
  VMatrix *v9; // ecx
  int v10; // eax
  bool v11; // zf
  int m_Size; // edi
  int m_nAllocationCount; // eax
  VMatrix *m_pMemory; // ecx
  int v16; // eax

  v2 = buf;
  v3 = dest;
  v4 = 0;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return 1;
    while ( 1 )
    {
      m_Size = v3->m_Size;
      m_nAllocationCount = v3->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<VMatrix,int>::Grow(this: &v3->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v3->m_Size;
      m_pMemory = v3->m_Memory.m_pMemory;
      v16 = v3->m_Size - m_Size - 1;
      v11 = v3->m_Size - m_Size == 1;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v16 >= 0 && !v11 )
        memmove(
          dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v16 << 6);
      if ( !Unserialize(buf, dest: &v3->m_Memory.m_pMemory[m_Size]) )
        break;
      CUtlBuffer::EatWhiteSpace(this: buf);
      if ( buf->m_Error != 0 )
        return 1;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v5 = dest;
    if ( dest == nullptr )
      return v2->m_Error == 0;
    CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(this: v3, num: (int)dest);
    if ( (int)v5 <= 0 )
      return v2->m_Error == 0;
    for ( i = 0; ; ++i )
    {
      v7 = v3->m_Size;
      v8 = v3->m_Memory.m_nAllocationCount;
      if ( v7 + 1 > v8 )
        CUtlMemory<VMatrix,int>::Grow(this: &v3->m_Memory, num: v7 - v8 + 1);
      ++v3->m_Size;
      v9 = v3->m_Memory.m_pMemory;
      v10 = v3->m_Size - v7 - 1;
      v11 = v3->m_Size - v7 == 1;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v10 >= 0 && !v11 )
        memmove(dst: (unsigned __int8 *)&v9[v7 + 1], src: (unsigned __int8 *)&v9[v7], count: v10 << 6);
      if ( !Unserialize(buf, dest: &v3->m_Memory.m_pMemory[i]) )
        break;
      if ( ++v4 >= (int)dest )
      {
        v2 = buf;
        return v2->m_Error == 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004246C0
// Name: bool Serialize<class VMatrix>(class CUtlBuffer __near &,class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<VMatrix>(CUtlBuffer *buf, const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 32;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004247A0
// Name: bool Serialize<class CUtlString>(class CUtlBuffer __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<CUtlString>(CUtlBuffer *buf, const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424890
// Name: bool Serialize<class CUtlBinaryBlock>(class CUtlBuffer __near &,class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<CUtlBinaryBlock>(
        CUtlBuffer *buf,
        const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 32;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424970
// Name: bool Unserialize<struct UniqueId_t>(class CUtlBuffer __near &,class CUtlVector<struct UniqueId_t,class CUtlMemory<struct UniqueId_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Unserialize<UniqueId_t>(CUtlBuffer *buf, CUtlMemory<CUtlBinaryBlock,int> *dest)
{
  CUtlBuffer *v2; // ebp
  CUtlMemory<CUtlBinaryBlock,int> *v3; // esi
  int v4; // ebx
  CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *v5; // edi
  int i; // ebp
  CUtlBinaryBlock *v7; // edi
  int v8; // eax
  CUtlBinaryBlock *v9; // ecx
  int v10; // eax
  bool v11; // zf
  CUtlBinaryBlock *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlBinaryBlock *v15; // ecx
  int v16; // eax

  v2 = buf;
  v3 = dest;
  v4 = 0;
  dest[1].m_pMemory = nullptr;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return 1;
    while ( 1 )
    {
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Memory.m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<Quaternion,int>::Grow(this: v3, num: (int)&m_pMemory->m_Memory.m_pMemory - m_nAllocationCount + 1);
      ++v3[1].m_pMemory;
      v15 = v3->m_pMemory;
      v16 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory == 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v16 >= 0 && !v11 )
        memmove(
          dst: (unsigned __int8 *)&v15[(int)m_pMemory + 1],
          src: (unsigned __int8 *)&v15[(_DWORD)m_pMemory],
          count: 16 * v16);
      if ( !Unserialize(buf, dest: (UniqueId_t *)&v3->m_pMemory[(_DWORD)m_pMemory]) )
        break;
      CUtlBuffer::EatWhiteSpace(this: buf);
      if ( buf->m_Error != 0 )
        return 1;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, (int *)&dest);
    v5 = (CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *)dest;
    if ( dest == nullptr )
      return v2->m_Error == 0;
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
      this: (CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *)v3,
      num: (int)dest);
    if ( (int)v5 <= 0 )
      return v2->m_Error == 0;
    for ( i = 0; ; ++i )
    {
      v7 = v3[1].m_pMemory;
      v8 = v3->m_nAllocationCount;
      if ( (int)&v7->m_Memory.m_pMemory + 1 > v8 )
        CUtlMemory<Quaternion,int>::Grow(this: v3, num: (int)&v7->m_Memory.m_pMemory - v8 + 1);
      ++v3[1].m_pMemory;
      v9 = v3->m_pMemory;
      v10 = (char *)v3[1].m_pMemory - (char *)v7 - 1;
      v11 = (char *)v3[1].m_pMemory - (char *)v7 == 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v10 >= 0 && !v11 )
        memmove(dst: (unsigned __int8 *)&v9[(int)v7 + 1], src: (unsigned __int8 *)&v9[(_DWORD)v7], count: 16 * v10);
      if ( !Unserialize(buf, dest: (UniqueId_t *)&v3->m_pMemory[i]) )
        break;
      if ( ++v4 >= (int)dest )
      {
        v2 = buf;
        return v2->m_Error == 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424AC0
// Name: bool Serialize<struct UniqueId_t>(class CUtlBuffer __near &,class CUtlVector<struct UniqueId_t,class CUtlMemory<struct UniqueId_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<UniqueId_t>(CUtlBuffer *buf, const CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *src)
{
  int m_Size; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ebx
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    v5 = 0;
    if ( m_Size > 0 )
    {
      v6 = 0;
      do
      {
        Serialize(buf, src: &src->m_Memory.m_pMemory[v6]);
        if ( s_pUtlBufferUtilArrayDelim != nullptr && v5 != m_Size - 1 )
          CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < m_Size );
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  v3 = 0;
  do
  {
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
    --m_Size;
  }
  while ( m_Size != 0 );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042CB20
// Name: bool Unserialize<class CUtlBinaryBlock>(class CUtlBuffer __near &,class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<CUtlBinaryBlock>(CUtlBuffer *buf, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dest)
{
  CUtlBuffer *v2; // edi
  int v3; // ebx
  int v4; // ebp
  int i; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlBinaryBlock *p_m_Storage; // ecx
  int v10; // eax
  bool v11; // zf
  int v12; // edi
  CUtlBinaryBlock *v13; // ecx
  int num; // [esp+8h] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: dest);
  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
    {
      return true;
    }
    else
    {
      while ( 1 )
      {
        m_Size = dest->m_Size;
        m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<Quaternion,int>::Grow(
            this: (CUtlMemory<CUtlBinaryBlock,int> *)dest,
            num: m_Size - m_nAllocationCount + 1);
        ++dest->m_Size;
        p_m_Storage = &dest->m_Memory.m_pMemory->m_Storage;
        v10 = dest->m_Size - m_Size - 1;
        v11 = dest->m_Size - m_Size == 1;
        dest->m_pElements = dest->m_Memory.m_pMemory;
        if ( v10 >= 0 && !v11 )
          memmove(
            dst: (unsigned __int8 *)&p_m_Storage[m_Size + 1],
            src: (unsigned __int8 *)&p_m_Storage[m_Size],
            count: 16 * v10);
        v12 = m_Size;
        v13 = &dest->m_Memory.m_pMemory[v12].m_Storage;
        if ( v13 != nullptr )
          CUtlBinaryBlock::CUtlBinaryBlock(this: v13, growSize: 0, initSize: 0);
        if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12].m_Storage) )
          break;
        CUtlBuffer::EatWhiteSpace(this: buf);
        if ( buf->m_Error != 0 )
          return true;
      }
      return false;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, dest: &num);
    v3 = num;
    if ( num != 0
      && (CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
            this: (CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *)dest,
            num),
          v4 = 0,
          v3 > 0) )
    {
      for ( i = 0; ; ++i )
      {
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
          this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)dest,
          elem: dest->m_Size);
        if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[i].m_Storage) )
          break;
        if ( ++v4 >= v3 )
        {
          v2 = buf;
          return v2->m_Error == 0;
        }
      }
      return false;
    }
    else
    {
      return v2->m_Error == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004318C0
// Name: bool Unserialize<class CUtlString>(class CUtlBuffer __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<CUtlString>(CUtlBuffer *buf, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dest)
{
  CUtlBuffer *v2; // edi
  int v3; // ebx
  int v4; // ebp
  int i; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  bool v11; // zf
  int v12; // edi
  CUtlString *v13; // ecx
  int num; // [esp+8h] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: dest);
  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
    {
      return true;
    }
    else
    {
      while ( 1 )
      {
        m_Size = dest->m_Size;
        m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<Quaternion,int>::Grow(
            this: (CUtlMemory<CUtlBinaryBlock,int> *)dest,
            num: m_Size - m_nAllocationCount + 1);
        ++dest->m_Size;
        m_pMemory = dest->m_Memory.m_pMemory;
        v10 = dest->m_Size - m_Size - 1;
        v11 = dest->m_Size - m_Size == 1;
        dest->m_pElements = dest->m_Memory.m_pMemory;
        if ( v10 >= 0 && !v11 )
          memmove(
            dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 16 * v10);
        v12 = m_Size;
        v13 = &dest->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
          CUtlString::CUtlString(this: v13);
        if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
          break;
        CUtlBuffer::EatWhiteSpace(this: buf);
        if ( buf->m_Error != 0 )
          return true;
      }
      return false;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, dest: &num);
    v3 = num;
    if ( num != 0
      && (CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
            this: (CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *)dest,
            num),
          v4 = 0,
          v3 > 0) )
    {
      for ( i = 0; ; ++i )
      {
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dest, elem: dest->m_Size);
        if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[i]) )
          break;
        if ( ++v4 >= v3 )
        {
          v2 = buf;
          return v2->m_Error == 0;
        }
      }
      return false;
    }
    else
    {
      return v2->m_Error == 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444960
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00444970
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_DWORD *)pDest->m_Value = 0;
  *(_DWORD *)&pDest->m_Value[4] = 0;
  *(_DWORD *)&pDest->m_Value[8] = 0;
  *(_DWORD *)&pDest->m_Value[12] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00444990
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int i; // esi
  int v5; // edx
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax

  for ( i = 16; i >= 4; i -= 4 )
  {
    if ( *(_DWORD *)id1->m_Value != *(_DWORD *)id2->m_Value )
      goto LABEL_5;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
  }
  if ( i == 0 )
  {
LABEL_14:
    v14 = 0;
    return v14 == 0;
  }
LABEL_5:
  v5 = id1->m_Value[0] - id2->m_Value[0];
  if ( v5 == 0 )
  {
    v6 = i - 1;
    v7 = &id2->m_Value[1];
    v8 = &id1->m_Value[1];
    if ( v6 == 0 )
      goto LABEL_14;
    v5 = *v8 - *v7;
    if ( v5 == 0 )
    {
      v9 = v6 - 1;
      v10 = v7 + 1;
      v11 = v8 + 1;
      if ( v9 == 0 )
        goto LABEL_14;
      v5 = *v11 - *v10;
      if ( v5 == 0 )
      {
        v12 = v10 + 1;
        v13 = v11 + 1;
        if ( v9 == 1 )
          goto LABEL_14;
        v5 = *v13 - *v12;
        if ( v5 == 0 )
          goto LABEL_14;
      }
    }
  }
  v14 = 1;
  if ( v5 <= 0 )
    return false;
  return v14 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00444A30
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444A80
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00444AA0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UniqueIdFromString(UniqueId_t *pDest, const char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // edi
  void *v4; // esp
  unsigned __int8 *v5; // esi
  int i; // edi
  char j; // al
  char v9[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = strlen(pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v9;
  V_strncpy(pDest: v9, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    if ( isspace(c: v9[i]) == 0 )
      break;
  }
  v9[i + 1] = 0;
  for ( j = v9[0]; j != 0; j = *++v5 )
  {
    if ( isspace(c: j) == 0 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_DWORD *)pDest->m_Value = 0;
  *(_DWORD *)&pDest->m_Value[4] = 0;
  *(_DWORD *)&pDest->m_Value[8] = 0;
  *(_DWORD *)&pDest->m_Value[12] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00444B50
// Name: bool Unserialize(class CUtlBuffer __near &,struct UniqueId_t __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, UniqueId_t *dest)
{
  int v2; // esi
  void *v3; // esp
  char v5[12]; // [esp+0h] [ebp-Ch] BYREF

  if ( (buf->m_Flags & 1) != 0 )
  {
    v2 = CUtlBuffer::PeekStringLength(this: buf);
    v3 = alloca(v2);
    CUtlBuffer::GetString(this: buf, pString: v5, nMaxChars: v2);
    UniqueIdFromString(pDest: dest, pBuf: v5, nMaxLen: v2);
  }
  else
  {
    CUtlBuffer::Get(this: buf, pMem: dest, size: 16);
  }
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00444BC0
// Name: bool Serialize(class CUtlBuffer __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const UniqueId_t *src)
{
  CUtlBuffer *v2; // esi

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    buf = nullptr;
    UuidToStringA(Uuid: (const UUID *)src, StringUuid: (RPC_CSTR *)&buf);
    if ( buf != nullptr && LOBYTE(buf->m_Memory.m_pMemory) != 0 )
    {
      CUtlBuffer::PutString(this: v2, pString: (const char *)buf);
      RpcStringFreeA(String: (RPC_CSTR *)&buf);
      return v2->m_Error == 0;
    }
    else
    {
      CUtlBuffer::PutChar(this: v2, c: 0);
      return v2->m_Error == 0;
    }
  }
  else
  {
    CUtlBuffer::Put(this: buf, pMem: src, size: 16);
    return v2->m_Error == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004471F0
// Name: bool Unserialize(class CUtlBuffer __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize(CUtlBuffer *buf, VMatrix *dest)
{
  if ( buf->m_Error != 0 )
    return false;
  if ( (buf->m_Flags & 1) != 0 )
    return CUtlBuffer::Scanf(
             this: buf,
             pFmt: "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
             dest,
             &dest->m[0][1],
             &dest->m[0][2],
             &dest->m[0][3],
             dest->m[1],
             &dest->m[1][1],
             &dest->m[1][2],
             &dest->m[1][3],
             dest->m[2],
             &dest->m[2][1],
             &dest->m[2][2],
             &dest->m[2][3],
             dest->m[3],
             &dest->m[3][1],
             &dest->m[3][2],
             &dest->m[3][3]) == 16;
  CUtlBuffer::Get(this: buf, pMem: dest, size: 64);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00447270
// Name: bool Serialize(class CUtlBuffer __near &,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, CUtlString *src)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: src);
  CUtlBuffer::PutDelimitedString(this: buf, pConv: s_pConv, pString: v2);
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004472A0
// Name: bool Unserialize(class CUtlBuffer __near &,class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, CUtlString *dest)
{
  int v2; // edi
  char *v3; // eax

  v2 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: s_pConv, bActualSize: true);
  CUtlString::SetLength(this: dest, nLen: v2 - 1);
  v3 = CUtlString::Get(this: dest);
  CUtlBuffer::GetDelimitedString(this: buf, pConv: s_pConv, pString: v3, nMaxChars: v2);
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447370
// Name: bool Serialize(class CUtlBuffer __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const bool *src)
{
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", *(unsigned __int8 *)src);
  else
    CUtlBuffer::PutChar(this: buf, c: *src);
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004473C0
// Name: bool Serialize(class CUtlBuffer __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, float *src)
{
  if ( (buf->m_Flags & 1) != 0 )
    SerializeFloat(buf, f: *src);
  else
    CUtlBuffer::PutTypeBin<float>(this: buf, src: *src);
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447410
// Name: bool Unserialize(class CUtlBuffer __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Unserialize(CUtlBuffer *buf, float *dest)
{
  CUtlBuffer *v2; // esi
  int result; // eax

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    result = CUtlBuffer::Scanf(this: buf, pFmt: "%f", dest);
    if ( result != 1 || v2->m_Error != 0 )
      return 0;
  }
  else
  {
    CUtlBuffer::GetType<float>(this: buf, dest: (float *)&buf, pszFmt: "%f");
    *dest = *(float *)&buf;
    return v2->m_Error == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447470
// Name: bool Serialize(class CUtlBuffer __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const Vector2D *src)
{
  if ( (buf->m_Flags & 1) != 0 )
  {
    SerializeFloats(buf, nCount: 2, pFloats: &src->x);
    return buf->m_Error == 0;
  }
  else
  {
    CUtlBuffer::PutTypeBin<float>(this: buf, src: src->x);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->y);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->y);
    return buf->m_Error == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004474F0
// Name: bool Unserialize(class CUtlBuffer __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, Vector2D *dest)
{
  CUtlBuffer *v2; // esi
  Vector2D *v4; // edi

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
    return CUtlBuffer::Scanf(this: buf, pFmt: "%f %f", dest, &dest->y) == 2 && v2->m_Error == 0;
  CUtlBuffer::GetType<float>(this: buf, dest: (float *)&buf, pszFmt: "%f");
  v4 = dest;
  dest->x = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->y = *(float *)&buf;
  return v2->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447570
// Name: bool Serialize(class CUtlBuffer __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const QAngle *src)
{
  if ( (buf->m_Flags & 1) != 0 )
  {
    SerializeFloats(buf, nCount: 3, pFloats: &src->x);
    return buf->m_Error == 0;
  }
  else
  {
    CUtlBuffer::PutTypeBin<float>(this: buf, src: src->x);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->y);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->y);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->z);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->z);
    return buf->m_Error == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447610
// Name: bool Unserialize(class CUtlBuffer __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, QAngle *dest)
{
  CUtlBuffer *v2; // esi
  QAngle *v4; // edi

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
    return CUtlBuffer::Scanf(this: buf, pFmt: "%f %f %f", dest, &dest->y, &dest->z) == 3 && v2->m_Error == 0;
  CUtlBuffer::GetType<float>(this: buf, dest: (float *)&buf, pszFmt: "%f");
  v4 = dest;
  dest->x = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->y = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->z = *(float *)&buf;
  return v2->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004476B0
// Name: bool Unserialize(class CUtlBuffer __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, Quaternion *dest)
{
  CUtlBuffer *v2; // esi
  Quaternion *v4; // edi

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
    return CUtlBuffer::Scanf(this: buf, pFmt: "%f %f %f %f", dest, &dest->y, &dest->z, &dest->w) == 4
        && v2->m_Error == 0;
  CUtlBuffer::GetType<float>(this: buf, dest: (float *)&buf, pszFmt: "%f");
  v4 = dest;
  dest->x = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->y = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->z = *(float *)&buf;
  CUtlBuffer::GetType<float>(this: v2, dest: (float *)&buf, pszFmt: "%f");
  v4->w = *(float *)&buf;
  return v2->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447760
// Name: bool Serialize(class CUtlBuffer __near &,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const Quaternion *src)
{
  if ( (buf->m_Flags & 1) != 0 )
  {
    SerializeFloats(buf, nCount: 4, pFloats: &src->x);
    return buf->m_Error == 0;
  }
  else
  {
    CUtlBuffer::PutTypeBin<float>(this: buf, src: src->x);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->y);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->y);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->z);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->z);
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%f", src->w);
    else
      CUtlBuffer::PutTypeBin<float>(this: buf, src: src->w);
    return buf->m_Error == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447830
// Name: bool Serialize(class CUtlBuffer __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const VMatrix *src)
{
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
    SerializeFloats(buf, nCount: 4, pFloats: (const float *)src);
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
    SerializeFloats(buf, nCount: 4, pFloats: src->m[1]);
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
    SerializeFloats(buf, nCount: 4, pFloats: src->m[2]);
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
    SerializeFloats(buf, nCount: 4, pFloats: src->m[3]);
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
  }
  else
  {
    CUtlBuffer::Put(this: buf, pMem: src, size: 64);
  }
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004478D0
// Name: bool Unserialize(class CUtlBuffer __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Unserialize(CUtlBuffer *buf, bool *dest)
{
  CUtlBuffer *v2; // esi
  int result; // eax
  unsigned __int8 Char; // al
  CUtlBuffer *v5; // [esp-Ch] [ebp-10h]

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v5 = buf;
    buf = nullptr;
    result = CUtlBuffer::Scanf(this: v5, pFmt: "%d", &buf);
    *dest = buf != nullptr;
    if ( result != 1 || v2->m_Error != 0 )
      return 0;
  }
  else
  {
    Char = CUtlBuffer::GetChar(this: buf);
    *dest = Char != 0;
    return v2->m_Error == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447940
// Name: bool Serialize(class CUtlBuffer __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, int *src)
{
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", *src);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: *src);
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447990
// Name: bool Unserialize(class CUtlBuffer __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Unserialize(CUtlBuffer *buf, int *dest)
{
  CUtlBuffer *v2; // esi
  int result; // eax

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    result = CUtlBuffer::Scanf(this: buf, pFmt: "%d", dest);
    if ( result != 1 || v2->m_Error != 0 )
      return 0;
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, dest: (int *)&buf);
    *dest = (int)buf;
    return v2->m_Error == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004479E0
// Name: bool Serialize(class CUtlBuffer __near &,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const Color *src)
{
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "%d %d %d %d", src->_color[0], src->_color[1], src->_color[2], src->_color[3]);
  }
  else
  {
    CUtlBuffer::PutUnsignedChar(this: buf, c: src->_color[0]);
    CUtlBuffer::PutUnsignedChar(this: buf, c: src->_color[1]);
    CUtlBuffer::PutUnsignedChar(this: buf, c: src->_color[2]);
    CUtlBuffer::PutUnsignedChar(this: buf, c: src->_color[3]);
  }
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447A60
// Name: bool Unserialize(class CUtlBuffer __near &,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Unserialize(CUtlBuffer *buf, Color *dest)
{
  CUtlBuffer *v2; // esi
  int v3; // eax
  Color *v4; // ecx
  unsigned __int8 UnsignedChar; // al
  Color *v7; // edi
  CUtlBuffer *v8; // [esp-18h] [ebp-28h]
  int b; // [esp+4h] [ebp-Ch] BYREF
  int a; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v8 = buf;
    buf = nullptr;
    b = 0;
    a = 0;
    v11 = 255;
    v3 = CUtlBuffer::Scanf(this: v8, pFmt: "%d %d %d %d", &buf, &b, &a, &v11);
    v4 = dest;
    dest->_color[0] = (unsigned __int8)buf;
    v4->_color[1] = b;
    v4->_color[2] = a;
    v4->_color[3] = v11;
    return v3 == 4 && v2->m_Error == 0;
  }
  else
  {
    UnsignedChar = CUtlBuffer::GetUnsignedChar(this: buf);
    v7 = dest;
    dest->_color[0] = UnsignedChar;
    v7->_color[1] = CUtlBuffer::GetUnsignedChar(this: v2);
    v7->_color[2] = CUtlBuffer::GetUnsignedChar(this: v2);
    v7->_color[3] = CUtlBuffer::GetUnsignedChar(this: v2);
    return v2->m_Error == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447B30
// Name: bool Serialize(class CUtlBuffer __near &,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize(CUtlBuffer *buf, const CUtlBinaryBlock *src)
{
  const CUtlBinaryBlock *v2; // ebx
  int m_nActualLength; // edi
  unsigned int v6; // ebp
  int m_Put; // eax
  unsigned __int8 v8; // al
  char v9; // cl
  unsigned __int8 v10; // al
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // bl
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 c1; // [esp+14h] [ebp+4h]

  v2 = src;
  m_nActualLength = src->m_nActualLength;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v6 = 0;
    if ( m_nActualLength > 0 )
    {
      while ( 1 )
      {
        if ( v6 % 0x28 == 0 )
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            m_Put = buf->m_Put;
            if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
              CUtlBuffer::PutTabs(this: buf);
          }
          if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          {
            buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
            ++buf->m_Put;
            CUtlBuffer::AddNullTermination(this: buf);
          }
        }
        v8 = v2->m_Memory.m_pMemory[v6] & 0xF;
        v9 = v2->m_Memory.m_pMemory[v6] >> 4;
        if ( v8 > 9u )
          v10 = v8 + 55;
        else
          v10 = v8 + 48;
        c1 = v10;
        if ( (unsigned __int8)(v2->m_Memory.m_pMemory[v6] >> 4) > 9u )
          v11 = v9 + 55;
        else
          v11 = v9 + 48;
        v12 = v11;
        if ( (buf->m_Flags & 1) != 0 )
        {
          v13 = buf->m_Put;
          if ( v13 != 0 && buf->m_Memory.m_pMemory[v13 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v12;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v14 = buf->m_Put;
          if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = c1;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
        if ( (int)++v6 >= m_nActualLength )
          break;
        v2 = src;
      }
    }
    if ( (buf->m_Flags & 1) != 0 )
    {
      v15 = buf->m_Put;
      if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: buf);
    }
    if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
    {
      buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
      ++buf->m_Put;
      CUtlBuffer::AddNullTermination(this: buf);
    }
  }
  else
  {
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_nActualLength);
    if ( m_nActualLength != 0 )
    {
      CUtlBuffer::Put(this: buf, pMem: src->m_Memory.m_pMemory, size: m_nActualLength);
      return buf->m_Error == 0;
    }
  }
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447E80
// Name: bool Unserialize(class CUtlBuffer __near &,class CUtlBinaryBlock __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize(CUtlBuffer *buf, CUtlBinaryBlock *dest)
{
  CUtlBuffer *v2; // esi
  CUtlBuffer *v3; // edi
  CUtlBinaryBlock *v4; // ebp
  CUtlBuffer *m_nActualLength; // ebp
  int v7; // edi
  CUtlBinaryBlock *v8; // edi
  int v9; // ebp
  CUtlBuffer *v10; // ebx
  int v11; // eax
  int m_Get; // eax
  char v13; // cl
  char v14; // al
  int v15; // [esp-8h] [ebp-18h]
  signed __int8 v16; // [esp+Fh] [ebp-1h] BYREF

  v2 = buf;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v7 = CountBinaryBytes(buf, pEndGet: (int *)&buf);
    if ( v7 < 0 )
      return false;
    CUtlBuffer::EatWhiteSpace(this: v2);
    v15 = v7;
    v8 = dest;
    v9 = 0;
    CUtlBinaryBlock::SetLength(this: dest, nLength: v15);
    v10 = buf;
    if ( v2->m_Get >= (int)buf )
    {
      return true;
    }
    else
    {
      while ( 1 )
      {
        if ( (v2->m_Flags & 1) != 0 )
        {
          LOBYTE(buf) = 0;
          CUtlBuffer::Scanf(this: v2, pFmt: "%c", &buf);
        }
        else if ( CUtlBuffer::CheckGet(this: v2, nSize: 1) )
        {
          v11 = v2->m_Get + 1;
          LOBYTE(buf) = v2->m_Memory.m_pMemory[v2->m_Get - v2->m_nOffset];
          v2->m_Get = v11;
        }
        else
        {
          LOBYTE(buf) = 0;
        }
        if ( (v2->m_Flags & 1) != 0 )
        {
          v16 = 0;
          CUtlBuffer::Scanf(this: v2, pFmt: "%c", &v16);
        }
        else if ( CUtlBuffer::CheckGet(this: v2, nSize: 1) )
        {
          m_Get = v2->m_Get;
          v16 = v2->m_Memory.m_pMemory[m_Get - v2->m_nOffset];
          v2->m_Get = m_Get + 1;
        }
        else
        {
          v16 = 0;
        }
        if ( (unsigned int)((char)buf - 48) > 9 )
        {
          if ( (unsigned int)((char)buf - 65) > 5 )
            v13 = (unsigned int)((char)buf - 97) > 5 ? -1 : (_BYTE)buf - 87;
          else
            v13 = (_BYTE)buf - 55;
        }
        else
        {
          v13 = (_BYTE)buf - 48;
        }
        if ( (unsigned int)(v16 - 48) > 9 )
        {
          if ( (unsigned int)(v16 - 65) > 5 )
            v14 = (unsigned int)(v16 - 97) > 5 ? -1 : v16 - 87;
          else
            v14 = v16 - 55;
        }
        else
        {
          v14 = v16 - 48;
        }
        if ( v13 == -1 || v14 == -1 )
          break;
        v8->m_Memory.m_pMemory[v9++] = v14 | (16 * v13);
        CUtlBuffer::EatWhiteSpace(this: v2);
        if ( v2->m_Get >= (int)v10 )
          return true;
      }
      return false;
    }
  }
  else
  {
    CUtlBuffer::GetTypeBin<int>(this: buf, dest: (int *)&buf);
    v3 = buf;
    v4 = dest;
    CUtlBinaryBlock::SetLength(this: dest, nLength: (int)buf);
    if ( v4->m_nActualLength != 0 )
      CUtlBuffer::Get(this: v2, pMem: v4->m_Memory.m_pMemory, size: v4->m_nActualLength);
    m_nActualLength = (CUtlBuffer *)v4->m_nActualLength;
    if ( v3 != m_nActualLength )
    {
      CUtlBuffer::SeekGet(this: v2, type: SEEK_CURRENT, offset: (char *)v3 - (char *)m_nActualLength);
      return false;
    }
    return v2->m_Error == 0;
  }
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00466690
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x004666A0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004666C0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00466730
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466780
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x004667A0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054CCE0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x0054CCF0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0054CD10
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0054CD80
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054CDD0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x0054CDF0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00604140
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00604150
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00604170
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006041E0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00604230
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00604250
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0054EA70
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x0054EA80
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0054EAA0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0054EB10
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054EB60
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x0054EB80
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BEB50
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x005BEB60
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005BEB80
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005BEBF0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BEC40
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x005BEC60
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00544720
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00544730
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00544750
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005447C0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544810
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00544830
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00466DF0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00466E00
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00466E20
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int i; // esi
  int v5; // edx
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax

  for ( i = 16; i >= 4; i -= 4 )
  {
    if ( *(_DWORD *)id1->m_Value != *(_DWORD *)id2->m_Value )
      goto LABEL_5;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
  }
  if ( i == 0 )
  {
LABEL_14:
    v14 = 0;
    return v14 == 0;
  }
LABEL_5:
  v5 = id1->m_Value[0] - id2->m_Value[0];
  if ( v5 == 0 )
  {
    v6 = i - 1;
    v7 = &id2->m_Value[1];
    v8 = &id1->m_Value[1];
    if ( v6 == 0 )
      goto LABEL_14;
    v5 = *v8 - *v7;
    if ( v5 == 0 )
    {
      v9 = v6 - 1;
      v10 = v7 + 1;
      v11 = v8 + 1;
      if ( v9 == 0 )
        goto LABEL_14;
      v5 = *v11 - *v10;
      if ( v5 == 0 )
      {
        v12 = v10 + 1;
        v13 = v11 + 1;
        if ( v9 == 1 )
          goto LABEL_14;
        v5 = *v13 - *v12;
        if ( v5 == 0 )
          goto LABEL_14;
      }
    }
  }
  v14 = 1;
  if ( v5 <= 0 )
    return false;
  return v14 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00466EC0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466F10
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00466F30
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0064C470
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x0064C480
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0064C4A0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0064C510
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064C560
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x0064C580
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1009EBA0
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1009EBB0
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009EBD0
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009EC40
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EC90
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x1009ECB0
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace vtex_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036EA50
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1036EA60
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036EA80
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036EAF0
// Name: void UniqueIdToString(struct UniqueId_t const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UniqueIdToString(const UniqueId_t *id, char *pBuf, int nMaxLen)
{
  char *v3; // esi

  v3 = pBuf;
  *pBuf = 0;
  pBuf = nullptr;
  UuidToStringA(Uuid: (const UUID *)id, StringUuid: (RPC_CSTR *)&pBuf);
  if ( pBuf != nullptr && *pBuf != 0 )
  {
    V_strncpy(pDest: v3, pSrc: pBuf, maxLen: nMaxLen);
    RpcStringFreeA(String: (RPC_CSTR *)&pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036EB40
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x1036EB60
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, const char *pBuf, int nMaxLen)
{
  int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036EC10
// Name: bool IsUniqueIdValid(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUniqueIdValid(const UniqueId_t *id)
{
  UniqueId_t invalidId; // [esp+0h] [ebp-10h] BYREF

  memset(&invalidId, 0, sizeof(invalidId));
  return IsUniqueIdEqual(id1: &invalidId, id2: id) == 0;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037E850
// Name: void CreateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateUniqueId(UniqueId_t *pDest)
{
  UuidCreate(Uuid: (UUID *)pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1037E860
// Name: void InvalidateUniqueId(struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateUniqueId(UniqueId_t *pDest)
{
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037E880
// Name: bool IsUniqueIdEqual(struct UniqueId_t const __near &,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsUniqueIdEqual(const UniqueId_t *id1, const UniqueId_t *id2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( *(_DWORD *)id1->m_Value == *(_DWORD *)id2->m_Value )
  {
    v4 -= 4;
    id2 = (const UniqueId_t *)((char *)id2 + 4);
    id1 = (const UniqueId_t *)((char *)id1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037E8F0
// Name: void CopyUniqueId(struct UniqueId_t const __near &,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUniqueId(const UniqueId_t *src, UniqueId_t *pDest)
{
  *pDest = *src;
}

//------------------------------------------------------------------------------
// Address: 0x1037E910
// Name: bool UniqueIdFromString(struct UniqueId_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UniqueIdFromString(UniqueId_t *pDest, char *pBuf, unsigned int nMaxLen)
{
  unsigned int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  int i; // esi
  int v7; // eax
  char j; // al
  char v10[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = nMaxLen;
  if ( nMaxLen == 0 )
    v3 = _V_strlen(str: pBuf);
  v4 = alloca(v3 + 1);
  v5 = (unsigned __int8 *)v10;
  V_strncpy(pDest: v10, pSrc: pBuf, maxLen: v3 + 1);
  for ( i = v3 - 1; i >= 0; --i )
  {
    v7 = v10[i];
    if ( v7 < 9 || v7 > 13 && v7 != 32 )
      break;
  }
  v10[i + 1] = 0;
  for ( j = v10[0]; j != 0; j = *++v5 )
  {
    if ( j < 9 || j > 13 && j != 32 )
      break;
  }
  if ( UuidFromStringA(StringUuid: v5, Uuid: (UUID *)pDest) == 0 )
    return 1;
  *(_QWORD *)pDest->m_Value = 0;
  *(_QWORD *)&pDest->m_Value[8] = 0;
  return 0;
}

} // namespace server
