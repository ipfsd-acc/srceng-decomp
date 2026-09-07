// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/lzss.cpp
// Functions: 6
// ============================================================

#include "tier1\lzss.h"

//------------------------------------------------------------------------------
// Address: 0x10278690
// Name: public: bool CLZSS::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZSS::IsCompressed(CLZSS *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1397971532;
}

//------------------------------------------------------------------------------
// Address: 0x102786B0
// Name: public: unsigned int CLZSS::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::GetActualSize(CLZSS *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1397971532 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102786D0
// Name: public: unsigned char __near * CLZSS::CompressNoAlloc(unsigned char __near *,int,unsigned char __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZSS::CompressNoAlloc(
        CLZSS *this,
        int pInput,
        int inputLength,
        unsigned __int8 *pOutputBuf,
        unsigned int *pOutputSize)
{
  void *v7; // esp
  void *v8; // esp
  unsigned __int8 *v9; // edx
  int v10; // edi
  unsigned __int8 *v11; // esi
  unsigned __int8 *v13; // ecx
  int v14; // edx
  CLZSS::lzss_node_t *pStart; // edi
  int v16; // ecx
  int v17; // esi
  unsigned __int8 *pData; // edi
  unsigned __int8 *v19; // esi
  char v20; // dl
  CLZSS::lzss_node_t *v21; // ecx
  CLZSS::lzss_list_t *v22; // esi
  CLZSS::lzss_node_t *pPrev; // edx
  CLZSS::lzss_list_t *v24; // edx
  bool v25; // zf
  int v26; // ecx
  unsigned __int8 *v27; // eax
  _BYTE *v28; // esi
  unsigned int v29; // [esp-804h] [ebp-82Ch]
  unsigned __int8 v30[2060]; // [esp-800h] [ebp-828h] BYREF
  unsigned __int8 *pEnd; // [esp+Ch] [ebp-1Ch]
  int putCmdByte; // [esp+10h] [ebp-18h]
  int lookAheadLength; // [esp+14h] [ebp-14h]
  unsigned __int8 *pEncodedPosition; // [esp+18h] [ebp-10h]
  CLZSS::lzss_node_t *pHash; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *pCmdByte; // [esp+20h] [ebp-8h]
  unsigned __int8 *pOutput; // [esp+24h] [ebp-4h]
  int encodedLength; // [esp+30h] [ebp+8h]

  if ( (unsigned int)inputLength <= 0x10 )
    return nullptr;
  v7 = alloca(2048);
  this->m_pHashTable = (CLZSS::lzss_list_t *)v30;
  memset(dst: v30, value: 0, count: 0x800u);
  v8 = alloca(16 * this->m_nWindowSize);
  v29 = 16 * this->m_nWindowSize;
  this->m_pHashTarget = (CLZSS::lzss_node_t *)v30;
  memset(dst: v30, value: 0, count: v29);
  v9 = pOutputBuf;
  *((_DWORD *)pOutputBuf + 1) = inputLength;
  v10 = 0;
  v11 = pOutputBuf + 8;
  pEnd = &pOutputBuf[inputLength - 16];
  *(_DWORD *)pOutputBuf = 1397971532;
  pOutput = pOutputBuf + 8;
  pEncodedPosition = nullptr;
  pCmdByte = nullptr;
  if ( inputLength <= 0 )
    goto LABEL_33;
  do
  {
    if ( v10 == 0 )
    {
      v13 = v11++;
      pCmdByte = v13;
      pOutput = v11;
      *v13 = 0;
    }
    v14 = inputLength;
    putCmdByte = ((_BYTE)v10 + 1) & 7;
    encodedLength = 0;
    if ( inputLength >= 16 )
      v14 = 16;
    pStart = this->m_pHashTable[*(unsigned __int8 *)pInput].pStart;
    lookAheadLength = v14;
    pHash = pStart;
    if ( pStart == nullptr )
      goto LABEL_24;
    do
    {
      v16 = 0;
      v17 = v14;
      if ( v14 != 0 )
      {
        pData = pStart->pData;
        do
        {
          --v17;
          if ( pData[v16] != *(_BYTE *)(v16 + pInput) )
            break;
          ++v16;
        }
        while ( v17 != 0 );
      }
      if ( v16 > encodedLength )
      {
        encodedLength = v16;
        pEncodedPosition = pHash->pData;
      }
      v14 = lookAheadLength;
      if ( v16 == lookAheadLength )
        break;
      pStart = pHash->pNext;
      pHash = pStart;
    }
    while ( pStart != nullptr );
    if ( encodedLength < 3 )
    {
      v11 = pOutput;
LABEL_24:
      *pCmdByte >>= 1;
      *v11 = *(_BYTE *)pInput;
      encodedLength = 1;
      pOutput = v11 + 1;
      goto LABEL_19;
    }
    *pCmdByte = (*pCmdByte >> 1) | 0x80;
    v19 = pOutput;
    v20 = pInput - (_BYTE)pEncodedPosition;
    *pOutput = (pInput - (int)pEncodedPosition - 1) >> 4;
    *++v19 = (encodedLength - 1) | (16 * (v20 - 1));
    pOutput = v19 + 1;
LABEL_19:
    lookAheadLength = encodedLength;
    do
    {
      v21 = &this->m_pHashTarget[pInput & (this->m_nWindowSize - 1)];
      if ( v21->pData != nullptr )
      {
        v22 = &this->m_pHashTable[*v21->pData];
        pPrev = v21->pPrev;
        if ( pPrev != nullptr )
        {
          v22->pEnd = pPrev;
          v21->pPrev->pNext = nullptr;
        }
        else
        {
          v22->pEnd = nullptr;
          v22->pStart = nullptr;
        }
      }
      v24 = &this->m_pHashTable[*(unsigned __int8 *)pInput];
      v21->pData = (unsigned __int8 *)pInput;
      v21->pPrev = nullptr;
      v21->pNext = v24->pStart;
      if ( v24->pStart != nullptr )
        v24->pStart->pPrev = v21;
      else
        v24->pEnd = v21;
      ++pInput;
      v25 = lookAheadLength-- == 1;
      v24->pStart = v21;
    }
    while ( !v25 );
    v26 = inputLength - encodedLength;
    inputLength -= encodedLength;
    if ( pOutput >= pEnd )
      return nullptr;
    v11 = pOutput;
    v10 = putCmdByte;
  }
  while ( v26 > 0 );
  v9 = pOutputBuf;
LABEL_33:
  if ( inputLength != 0 )
    return nullptr;
  if ( v10 != 0 )
  {
    *pCmdByte = (*pCmdByte | 0x100) >> 1 >> (7 - v10);
  }
  else
  {
    v27 = v11++;
    *v27 = 1;
  }
  *v11 = 0;
  v28 = v11 + 1;
  *v28 = 0;
  if ( pOutputSize != nullptr )
    *pOutputSize = v28 - v9 + 1;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10278910
// Name: public: unsigned char __near * CLZSS::Compress(unsigned char __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZSS::Compress(
        CLZSS *this,
        unsigned __int8 *pInput,
        int inputLength,
        unsigned int *pOutputSize)
{
  unsigned __int8 *v5; // esi

  v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: inputLength);
  if ( CLZSS::CompressNoAlloc(this, (int)pInput, inputLength, pOutputBuf: v5, pOutputSize) != nullptr )
    return v5;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10278970
// Name: public: unsigned int CLZSS::SafeUncompress(unsigned char __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLZSS::SafeUncompress(
        CLZSS *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        unsigned int unBufSize)
{
  int v4; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned __int8 *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // esi
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  unsigned int actualSize; // [esp+4h] [ebp-8h]
  int cmdByte; // [esp+8h] [ebp-4h]
  int getCmdByte; // [esp+14h] [ebp+8h]

  v4 = 0;
  v5 = 0;
  cmdByte = 0;
  if ( pInput == nullptr )
    return 0;
  if ( *(_DWORD *)pInput != 1397971532 )
    return 0;
  v6 = *((_DWORD *)pInput + 1);
  actualSize = v6;
  if ( v6 == 0 || v6 > unBufSize )
    return 0;
  v9 = pInput + 8;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v4 == 0 )
        cmdByte = *v9++;
      getCmdByte = ((_BYTE)v4 + 1) & 7;
      if ( (cmdByte & 1) != 0 )
        break;
      if ( ++v5 > unBufSize )
        return 0;
      *pOutput = *v9;
      v4 = ((_BYTE)v4 + 1) & 7;
      ++pOutput;
      ++v9;
      cmdByte >>= 1;
    }
    v10 = v9[1] & 0xF;
    v11 = (v9[1] >> 4) | (16 * *v9);
    v12 = v10 + 1;
    v9 += 2;
    if ( v10 == 0 )
      return v5 != actualSize ? 0 : v5;
    v13 = &pOutput[-v11];
    v14 = v12 + v5;
    v15 = v13 - 1;
    if ( v12 + v5 > unBufSize )
      break;
    if ( v12 > 0 )
    {
      do
      {
        *pOutput++ = *v15++;
        --v12;
      }
      while ( v12 != 0 );
    }
    cmdByte >>= 1;
    v5 = v14;
    v4 = getCmdByte;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278A40
// Name: public: unsigned int CLZSS::Uncompress(unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::Uncompress(CLZSS *this, unsigned __int8 *pInput, unsigned __int8 *pOutput)
{
  int v3; // ebx
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // eax
  int i; // ecx
  unsigned int actualSize; // [esp+4h] [ebp-Ch]
  int cmdByte; // [esp+8h] [ebp-8h]
  unsigned int totalBytes; // [esp+Ch] [ebp-4h]

  v3 = 0;
  totalBytes = 0;
  cmdByte = 0;
  if ( pInput == nullptr )
    return 0;
  if ( *(_DWORD *)pInput != 1397971532 )
    return 0;
  actualSize = *((_DWORD *)pInput + 1);
  if ( actualSize == 0 )
    return 0;
  v6 = pInput + 8;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v3 == 0 )
        cmdByte = *v6++;
      v3 = ((_BYTE)v3 + 1) & 7;
      if ( (cmdByte & 1) != 0 )
        break;
      ++totalBytes;
      *pOutput++ = *v6++;
      cmdByte >>= 1;
    }
    v7 = v6[1] & 0xF;
    v8 = (v6[1] >> 4) | (16 * *v6);
    v9 = v7 + 1;
    v6 += 2;
    if ( v7 == 0 )
      break;
    v10 = &pOutput[-v8 - 1];
    if ( v9 > 0 )
    {
      for ( i = v9; i != 0; --i )
        *pOutput++ = *v10++;
    }
    totalBytes += v9;
    cmdByte >>= 1;
  }
  return totalBytes != actualSize ? 0 : totalBytes;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102787C0
// Name: public: bool CLZSS::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZSS::IsCompressed(CLZSS *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1397971532;
}

//------------------------------------------------------------------------------
// Address: 0x102787E0
// Name: public: unsigned int CLZSS::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::GetActualSize(CLZSS *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1397971532 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278800
// Name: public: unsigned char __near * CLZSS::CompressNoAlloc(unsigned char __near *,int,unsigned char __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZSS::CompressNoAlloc(
        CLZSS *this,
        int pInput,
        int inputLength,
        unsigned __int8 *pOutputBuf,
        unsigned int *pOutputSize)
{
  void *v7; // esp
  void *v8; // esp
  unsigned __int8 *v9; // edx
  int v10; // edi
  unsigned __int8 *v11; // esi
  unsigned __int8 *v13; // ecx
  int v14; // edx
  CLZSS::lzss_node_t *pStart; // edi
  int v16; // ecx
  int v17; // esi
  unsigned __int8 *pData; // edi
  unsigned __int8 *v19; // esi
  char v20; // dl
  CLZSS::lzss_node_t *v21; // ecx
  CLZSS::lzss_list_t *v22; // esi
  CLZSS::lzss_node_t *pPrev; // edx
  CLZSS::lzss_list_t *v24; // edx
  bool v25; // zf
  int v26; // ecx
  unsigned __int8 *v27; // eax
  _BYTE *v28; // esi
  unsigned int v29; // [esp-804h] [ebp-82Ch]
  unsigned __int8 v30[2060]; // [esp-800h] [ebp-828h] BYREF
  unsigned __int8 *pEnd; // [esp+Ch] [ebp-1Ch]
  int putCmdByte; // [esp+10h] [ebp-18h]
  int lookAheadLength; // [esp+14h] [ebp-14h]
  unsigned __int8 *pEncodedPosition; // [esp+18h] [ebp-10h]
  CLZSS::lzss_node_t *pHash; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *pCmdByte; // [esp+20h] [ebp-8h]
  unsigned __int8 *pOutput; // [esp+24h] [ebp-4h]
  int encodedLength; // [esp+30h] [ebp+8h]

  if ( (unsigned int)inputLength <= 0x10 )
    return nullptr;
  v7 = alloca(2048);
  this->m_pHashTable = (CLZSS::lzss_list_t *)v30;
  memset(dst: v30, value: 0, count: 0x800u);
  v8 = alloca(16 * this->m_nWindowSize);
  v29 = 16 * this->m_nWindowSize;
  this->m_pHashTarget = (CLZSS::lzss_node_t *)v30;
  memset(dst: v30, value: 0, count: v29);
  v9 = pOutputBuf;
  *((_DWORD *)pOutputBuf + 1) = inputLength;
  v10 = 0;
  v11 = pOutputBuf + 8;
  pEnd = &pOutputBuf[inputLength - 16];
  *(_DWORD *)pOutputBuf = 1397971532;
  pOutput = pOutputBuf + 8;
  pEncodedPosition = nullptr;
  pCmdByte = nullptr;
  if ( inputLength <= 0 )
    goto LABEL_33;
  do
  {
    if ( v10 == 0 )
    {
      v13 = v11++;
      pCmdByte = v13;
      pOutput = v11;
      *v13 = 0;
    }
    v14 = inputLength;
    putCmdByte = ((_BYTE)v10 + 1) & 7;
    encodedLength = 0;
    if ( inputLength >= 16 )
      v14 = 16;
    pStart = this->m_pHashTable[*(unsigned __int8 *)pInput].pStart;
    lookAheadLength = v14;
    pHash = pStart;
    if ( pStart == nullptr )
      goto LABEL_24;
    do
    {
      v16 = 0;
      v17 = v14;
      if ( v14 != 0 )
      {
        pData = pStart->pData;
        do
        {
          --v17;
          if ( pData[v16] != *(_BYTE *)(v16 + pInput) )
            break;
          ++v16;
        }
        while ( v17 != 0 );
      }
      if ( v16 > encodedLength )
      {
        encodedLength = v16;
        pEncodedPosition = pHash->pData;
      }
      v14 = lookAheadLength;
      if ( v16 == lookAheadLength )
        break;
      pStart = pHash->pNext;
      pHash = pStart;
    }
    while ( pStart != nullptr );
    if ( encodedLength < 3 )
    {
      v11 = pOutput;
LABEL_24:
      *pCmdByte >>= 1;
      *v11 = *(_BYTE *)pInput;
      encodedLength = 1;
      pOutput = v11 + 1;
      goto LABEL_19;
    }
    *pCmdByte = (*pCmdByte >> 1) | 0x80;
    v19 = pOutput;
    v20 = pInput - (_BYTE)pEncodedPosition;
    *pOutput = (pInput - (int)pEncodedPosition - 1) >> 4;
    *++v19 = (encodedLength - 1) | (16 * (v20 - 1));
    pOutput = v19 + 1;
LABEL_19:
    lookAheadLength = encodedLength;
    do
    {
      v21 = &this->m_pHashTarget[pInput & (this->m_nWindowSize - 1)];
      if ( v21->pData != nullptr )
      {
        v22 = &this->m_pHashTable[*v21->pData];
        pPrev = v21->pPrev;
        if ( pPrev != nullptr )
        {
          v22->pEnd = pPrev;
          v21->pPrev->pNext = nullptr;
        }
        else
        {
          v22->pEnd = nullptr;
          v22->pStart = nullptr;
        }
      }
      v24 = &this->m_pHashTable[*(unsigned __int8 *)pInput];
      v21->pData = (unsigned __int8 *)pInput;
      v21->pPrev = nullptr;
      v21->pNext = v24->pStart;
      if ( v24->pStart != nullptr )
        v24->pStart->pPrev = v21;
      else
        v24->pEnd = v21;
      ++pInput;
      v25 = lookAheadLength-- == 1;
      v24->pStart = v21;
    }
    while ( !v25 );
    v26 = inputLength - encodedLength;
    inputLength -= encodedLength;
    if ( pOutput >= pEnd )
      return nullptr;
    v11 = pOutput;
    v10 = putCmdByte;
  }
  while ( v26 > 0 );
  v9 = pOutputBuf;
LABEL_33:
  if ( inputLength != 0 )
    return nullptr;
  if ( v10 != 0 )
  {
    *pCmdByte = (*pCmdByte | 0x100) >> 1 >> (7 - v10);
  }
  else
  {
    v27 = v11++;
    *v27 = 1;
  }
  *v11 = 0;
  v28 = v11 + 1;
  *v28 = 0;
  if ( pOutputSize != nullptr )
    *pOutputSize = v28 - v9 + 1;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10278AA0
// Name: public: unsigned int CLZSS::SafeUncompress(unsigned char __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLZSS::SafeUncompress(
        CLZSS *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        unsigned int unBufSize)
{
  int v4; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned __int8 *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // esi
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  unsigned int actualSize; // [esp+4h] [ebp-8h]
  int cmdByte; // [esp+8h] [ebp-4h]
  int getCmdByte; // [esp+14h] [ebp+8h]

  v4 = 0;
  v5 = 0;
  cmdByte = 0;
  if ( pInput == nullptr )
    return 0;
  if ( *(_DWORD *)pInput != 1397971532 )
    return 0;
  v6 = *((_DWORD *)pInput + 1);
  actualSize = v6;
  if ( v6 == 0 || v6 > unBufSize )
    return 0;
  v9 = pInput + 8;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v4 == 0 )
        cmdByte = *v9++;
      getCmdByte = ((_BYTE)v4 + 1) & 7;
      if ( (cmdByte & 1) != 0 )
        break;
      if ( ++v5 > unBufSize )
        return 0;
      *pOutput = *v9;
      v4 = ((_BYTE)v4 + 1) & 7;
      ++pOutput;
      ++v9;
      cmdByte >>= 1;
    }
    v10 = v9[1] & 0xF;
    v11 = (v9[1] >> 4) | (16 * *v9);
    v12 = v10 + 1;
    v9 += 2;
    if ( v10 == 0 )
      return v5 != actualSize ? 0 : v5;
    v13 = &pOutput[-v11];
    v14 = v12 + v5;
    v15 = v13 - 1;
    if ( v12 + v5 > unBufSize )
      break;
    if ( v12 > 0 )
    {
      do
      {
        *pOutput++ = *v15++;
        --v12;
      }
      while ( v12 != 0 );
    }
    cmdByte >>= 1;
    v5 = v14;
    v4 = getCmdByte;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278B70
// Name: public: unsigned int CLZSS::Uncompress(unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::Uncompress(CLZSS *this, unsigned __int8 *pInput, unsigned __int8 *pOutput)
{
  int v3; // ebx
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // eax
  int i; // ecx
  unsigned int actualSize; // [esp+4h] [ebp-Ch]
  int cmdByte; // [esp+8h] [ebp-8h]
  unsigned int totalBytes; // [esp+Ch] [ebp-4h]

  v3 = 0;
  totalBytes = 0;
  cmdByte = 0;
  if ( pInput == nullptr )
    return 0;
  if ( *(_DWORD *)pInput != 1397971532 )
    return 0;
  actualSize = *((_DWORD *)pInput + 1);
  if ( actualSize == 0 )
    return 0;
  v6 = pInput + 8;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v3 == 0 )
        cmdByte = *v6++;
      v3 = ((_BYTE)v3 + 1) & 7;
      if ( (cmdByte & 1) != 0 )
        break;
      ++totalBytes;
      *pOutput++ = *v6++;
      cmdByte >>= 1;
    }
    v7 = v6[1] & 0xF;
    v8 = (v6[1] >> 4) | (16 * *v6);
    v9 = v7 + 1;
    v6 += 2;
    if ( v7 == 0 )
      break;
    v10 = &pOutput[-v8 - 1];
    if ( v9 > 0 )
    {
      for ( i = v9; i != 0; --i )
        *pOutput++ = *v10++;
    }
    totalBytes += v9;
    cmdByte >>= 1;
  }
  return totalBytes != actualSize ? 0 : totalBytes;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x1001AF10
// Name: public: bool CLZSS::IsCompressed(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLZSS::IsCompressed(CLZSS *this, unsigned __int8 *pInput)
{
  return pInput != nullptr && *(_DWORD *)pInput == 1397971532;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF30
// Name: public: unsigned int CLZSS::GetActualSize(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::GetActualSize(CLZSS *this, unsigned __int8 *pInput)
{
  if ( pInput != nullptr && *(_DWORD *)pInput == 1397971532 )
    return *((_DWORD *)pInput + 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF50
// Name: private: void CLZSS::BuildHash(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZSS::BuildHash(CLZSS *this, unsigned __int8 *pData)
{
  CLZSS::lzss_node_t *v2; // eax
  CLZSS::lzss_list_t *v3; // esi
  CLZSS::lzss_node_t *pPrev; // edx
  CLZSS::lzss_list_t *v5; // ecx

  v2 = &this->m_pHashTarget[(unsigned int)pData & (this->m_nWindowSize - 1)];
  if ( v2->pData != nullptr )
  {
    v3 = &this->m_pHashTable[*v2->pData];
    pPrev = v2->pPrev;
    if ( pPrev != nullptr )
    {
      v3->pEnd = pPrev;
      v2->pPrev->pNext = nullptr;
    }
    else
    {
      v3->pEnd = nullptr;
      v3->pStart = nullptr;
    }
  }
  v5 = &this->m_pHashTable[*pData];
  v2->pData = pData;
  v2->pPrev = nullptr;
  v2->pNext = v5->pStart;
  if ( v5->pStart != nullptr )
    v5->pStart->pPrev = v2;
  else
    v5->pEnd = v2;
  v5->pStart = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFD0
// Name: public: unsigned char __near * CLZSS::CompressNoAlloc(unsigned char __near *,int,unsigned char __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZSS::CompressNoAlloc(
        CLZSS *this,
        unsigned __int8 *pInput,
        unsigned int inputLength,
        unsigned __int8 *pOutputBuf,
        unsigned int *pOutputSize)
{
  unsigned __int8 *result; // eax
  void *v7; // esp
  void *v8; // esp
  int v9; // esi
  int v10; // ecx
  unsigned __int8 *v11; // edx
  bool v12; // zf
  unsigned __int8 *v14; // edi
  unsigned __int8 *v15; // eax
  CLZSS::lzss_node_t *pStart; // ecx
  int v17; // eax
  unsigned __int8 *pData; // ecx
  char v19; // al
  _BYTE *v20; // edi
  int i; // esi
  unsigned __int8 *v22; // ecx
  _BYTE *v23; // edi
  unsigned int v24; // [esp-804h] [ebp-82Ch]
  unsigned __int8 v25[2060]; // [esp-800h] [ebp-828h] BYREF
  unsigned __int8 *pEnd; // [esp+Ch] [ebp-1Ch]
  CLZSS *v27; // [esp+10h] [ebp-18h]
  unsigned __int8 *pEncodedPosition; // [esp+14h] [ebp-14h]
  CLZSS::lzss_node_t *pHash; // [esp+18h] [ebp-10h]
  int lookAheadLength; // [esp+1Ch] [ebp-Ch]
  int putCmdByte; // [esp+20h] [ebp-8h]
  unsigned __int8 *pCmdByte; // [esp+24h] [ebp-4h]
  int encodedLength; // [esp+30h] [ebp+8h]

  v27 = this;
  if ( inputLength <= 0x10 )
    return nullptr;
  v7 = alloca(2048);
  this->m_pHashTable = (CLZSS::lzss_list_t *)v25;
  memset(dst: v25, value: 0, count: 0x800u);
  v8 = alloca(16 * this->m_nWindowSize);
  v24 = 16 * this->m_nWindowSize;
  this->m_pHashTarget = (CLZSS::lzss_node_t *)v25;
  memset(dst: v25, value: 0, count: v24);
  result = pOutputBuf;
  v9 = inputLength;
  pEnd = &pOutputBuf[inputLength - 16];
  v10 = 0;
  v11 = nullptr;
  v12 = inputLength == 0;
  *((_DWORD *)pOutputBuf + 1) = inputLength;
  *(_DWORD *)pOutputBuf = 1397971532;
  v14 = pOutputBuf + 8;
  pEncodedPosition = nullptr;
  pCmdByte = nullptr;
  for ( putCmdByte = 0; v9 > 0; v10 = putCmdByte )
  {
    if ( v10 == 0 )
    {
      v15 = v14;
      pCmdByte = v14++;
      *pCmdByte = 0;
      v11 = v15;
    }
    putCmdByte = ((_BYTE)v10 + 1) & 7;
    encodedLength = 0;
    if ( v9 >= 16 )
      v9 = 16;
    pStart = v27->m_pHashTable[*pInput].pStart;
    lookAheadLength = v9;
    pHash = pStart;
    if ( pStart == nullptr )
      goto LABEL_28;
    do
    {
      v17 = 0;
      pData = pStart->pData;
      do
      {
        --v9;
        if ( pData[v17] != pInput[v17] )
          break;
        ++v17;
      }
      while ( v9 != 0 );
      v9 = lookAheadLength;
      if ( v17 > encodedLength )
      {
        encodedLength = v17;
        pEncodedPosition = pHash->pData;
      }
      if ( v17 == lookAheadLength )
        break;
      pStart = pHash->pNext;
      pHash = pStart;
    }
    while ( pStart != nullptr );
    v11 = pCmdByte;
    if ( encodedLength >= 3 )
    {
      *pCmdByte = (*pCmdByte >> 1) | 0x80;
      v19 = (_BYTE)pInput - (_BYTE)pEncodedPosition;
      *v14 = (pInput - pEncodedPosition - 1) >> 4;
      v20 = v14 + 1;
      *v20 = (encodedLength - 1) | (16 * (v19 - 1));
      v14 = v20 + 1;
    }
    else
    {
LABEL_28:
      *v11 >>= 1;
      *v14 = *pInput;
      encodedLength = 1;
      ++v14;
    }
    for ( i = encodedLength; i != 0; --i )
      CLZSS::BuildHash(this: v27, pData: pInput++);
    v11 = pCmdByte;
    v9 = inputLength - encodedLength;
    result = pOutputBuf;
    inputLength -= encodedLength;
    if ( v14 >= pEnd )
      return nullptr;
    v12 = v9 == 0;
  }
  if ( !v12 )
    return nullptr;
  if ( v10 != 0 )
  {
    *v11 = (*v11 | 0x100) >> 1 >> (7 - putCmdByte);
  }
  else
  {
    v22 = v14++;
    *v22 = 1;
  }
  *v14 = 0;
  v23 = v14 + 1;
  *v23 = 0;
  if ( pOutputSize != nullptr )
    *pOutputSize = v23 - result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1C0
// Name: public: unsigned char __near * CLZSS::Compress(unsigned char __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLZSS::Compress(
        CLZSS *this,
        unsigned __int8 *pInput,
        unsigned int inputLength,
        unsigned int *pOutputSize)
{
  unsigned __int8 *v5; // esi

  v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: inputLength);
  if ( CLZSS::CompressNoAlloc(this, pInput, inputLength, pOutputBuf: v5, pOutputSize) != nullptr )
    return v5;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B210
// Name: public: unsigned int CLZSS::SafeUncompress(unsigned char __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZSS::SafeUncompress(
        CLZSS *this,
        unsigned __int8 *pInput,
        unsigned __int8 *pOutput,
        unsigned int unBufSize)
{
  int v4; // ecx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  unsigned __int8 *v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  unsigned __int8 *v15; // eax
  signed int actualSize; // [esp+4h] [ebp-8h]
  unsigned int v17; // [esp+8h] [ebp-4h]
  int getCmdByte; // [esp+10h] [ebp+4h]

  v4 = 0;
  v5 = 0;
  actualSize = 0;
  if ( pInput == nullptr )
    return 0;
  if ( *(_DWORD *)pInput != 1397971532 )
    return 0;
  v6 = *((_DWORD *)pInput + 1);
  v17 = v6;
  if ( v6 == 0 )
    return 0;
  if ( v6 > unBufSize )
    return 0;
  v9 = pInput + 8;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v4 == 0 )
        actualSize = *v9++;
      getCmdByte = ((_BYTE)v4 + 1) & 7;
      if ( (actualSize & 1) != 0 )
        break;
      if ( ++v5 > unBufSize )
        return 0;
      *pOutput++ = *v9++;
LABEL_18:
      actualSize >>= 1;
      v4 = getCmdByte;
    }
    v10 = v9[1];
    v11 = v10 >> 4;
    v12 = (v10 & 0xF) + 1;
    v13 = v11 | (16 * *v9);
    v14 = v12;
    v9 += 2;
    if ( v12 == 1 )
      return v5 != v17 ? 0 : v5;
    v5 += v12;
    v15 = &pOutput[-v13 - 1];
    if ( v5 > unBufSize )
      return 0;
    if ( v14 <= 0 )
      goto LABEL_18;
    do
    {
      *pOutput++ = *v15++;
      --v14;
    }
    while ( v14 != 0 );
    actualSize >>= 1;
    v4 = getCmdByte;
  }
}

} // namespace networksystem
