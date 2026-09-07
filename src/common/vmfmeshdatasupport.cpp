// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vmfmeshdatasupport.cpp
// Functions: 14
// ============================================================

#include "common\vmfmeshdatasupport.h"

//------------------------------------------------------------------------------
// Address: 0x100BB4D0
// Name: char KvEncoder::EncodeChar(char)
// Source: json
//------------------------------------------------------------------------------
char __cdecl KvEncoder::EncodeChar(char ch)
{
  if ( ch == 0 )
    return 45;
  if ( (unsigned __int8)(ch - 1) <= 0x1Au )
    return ch + 96;
  if ( (unsigned __int8)(ch - 28) <= 0x1Au )
    return ch + 37;
  if ( (unsigned __int8)(ch - 55) > 9u )
    return -1;
  return ch - 7;
}

//------------------------------------------------------------------------------
// Address: 0x100BB520
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::WriteDataChunk(class CChunkFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::WriteDataChunk(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile,
        const char *szHash)
{
  const char *v4; // eax
  ChunkFileResult_t result; // eax
  int (__thiscall *GetCustomSectionVer)(CVmfMeshDataSupport_SaveLoadHandler *); // edx
  int v7; // eax
  char szModelDataVer[16]; // [esp+Ch] [ebp-10h] BYREF

  v4 = (const char *)this->GetCustomSectionName(this);
  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: v4);
  if ( result == ChunkFile_Ok )
  {
    GetCustomSectionVer = this->GetCustomSectionVer;
    memset(szModelDataVer, 0, sizeof(szModelDataVer));
    v7 = GetCustomSectionVer(this);
    sprintf(string: szModelDataVer, format: "%d", v7);
    result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "version", pszValue: szModelDataVer);
    if ( result == ChunkFile_Ok )
    {
      result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "hash", pszValue: szHash);
      if ( result == ChunkFile_Ok )
      {
        result = this->OnFileDataWriting(this, a2: pFile, a3: szHash);
        if ( result == ChunkFile_Ok )
          return CChunkFile::EndChunk(this: pFile);
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB5C0
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(class CChunkFile __near *,enum ChunkFileResult_t)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile,
        ChunkFileResult_t eLoadResult)
{
  ChunkFileResult_t result; // eax
  int m_eLoadState; // edx

  result = eLoadResult;
  if ( eLoadResult == ChunkFile_Ok )
  {
    m_eLoadState = this->m_eLoadState;
    if ( m_eLoadState != 0 )
    {
      result = ChunkFile_Fail;
      if ( this->m_iLoadVer == 1 )
        return (unsigned int)(m_eLoadState - 2) > 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB5F0
// Name: protected: bool CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  return this->m_hLoadHeader.numLines >= 0 && this->m_hLoadHeader.numBytes >= 0 && this->m_hLoadHeader.numEncBytes >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BB620
// Name: int KvEncoder::Encode(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl KvEncoder::Encode(CUtlBuffer *src, CUtlBuffer *dst)
{
  int m_Put; // ecx
  CUtlBuffer *v3; // edx
  int v4; // eax
  unsigned __int8 *v6; // esi
  int v7; // ebx
  int i; // edi
  int v9; // ecx
  int v10; // ecx
  __int16 v11; // ax
  unsigned int v12; // eax
  char v13; // al
  int nReqLen; // [esp+4h] [ebp-Ch]
  int srcBytes; // [esp+8h] [ebp-8h]
  unsigned __int8 *pBase; // [esp+Ch] [ebp-4h]
  unsigned __int8 *pSrc; // [esp+18h] [ebp+8h]

  m_Put = src->m_Put;
  v3 = dst;
  v4 = 4 * ((m_Put + 2) / 3);
  nReqLen = v4;
  if ( dst->m_Memory.m_nAllocationCount < v4 )
    return 0;
  pBase = dst->m_Memory.m_pMemory;
  pSrc = src->m_Memory.m_pMemory;
  srcBytes = m_Put;
  if ( m_Put > 0 )
  {
    do
    {
      v6 = pBase + 1;
      v7 = 0;
      for ( i = 0; i < 6; i += 2 )
      {
        v9 = srcBytes--;
        if ( v9 <= 0 )
        {
          *v6++ = KvEncoder::EncodeChar(ch: 64);
        }
        else
        {
          v10 = *pSrc;
          v11 = *pSrc++ & 0x3F;
          v12 = (v10 << 10) ^ (unsigned __int16)(((_WORD)v10 << 10) ^ v11);
          if ( (_BYTE)v12 != 0 )
          {
            if ( (unsigned __int8)(v12 - 1) > 0x1Au )
            {
              if ( (unsigned __int8)(v12 - 28) > 0x1Au )
              {
                if ( (unsigned __int8)(v12 - 55) > 9u )
                  *v6 = -1;
                else
                  *v6 = v12 - 7;
                ++v6;
                v7 |= HIWORD(v12) << i;
              }
              else
              {
                *v6++ = v12 + 37;
                v7 |= HIWORD(v12) << i;
              }
            }
            else
            {
              *v6++ = v12 + 96;
              v7 |= HIWORD(v12) << i;
            }
          }
          else
          {
            *v6++ = 45;
            v7 |= HIWORD(v12) << i;
          }
        }
      }
      if ( (_BYTE)v7 != 0 )
      {
        if ( (unsigned __int8)(v7 - 1) > 0x1Au )
        {
          if ( (unsigned __int8)(v7 - 28) > 0x1Au )
          {
            if ( (unsigned __int8)(v7 - 55) > 9u )
              v13 = -1;
            else
              v13 = v7 - 7;
          }
          else
          {
            v13 = v7 + 37;
          }
        }
        else
        {
          v13 = v7 + 96;
        }
      }
      else
      {
        v13 = 45;
      }
      *pBase = v13;
      pBase = v6;
    }
    while ( srcBytes > 0 );
    v4 = nReqLen;
    v3 = dst;
  }
  CUtlBuffer::SeekPut(this: v3, type: SEEK_HEAD, offset: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BB7A0
// Name: int KvEncoder::Decode(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl KvEncoder::Decode(CUtlBuffer *src, CUtlBuffer *dst)
{
  CUtlBuffer *v2; // esi
  unsigned __int8 *m_pMemory; // edx
  char *v5; // ecx
  unsigned __int8 v6; // al
  char v7; // al
  int v8; // edi
  int v9; // esi
  unsigned __int8 v10; // al
  char v11; // al
  int v12; // ebx
  char *pBaseEnd; // [esp+Ch] [ebp-8h]
  int numBytesLimit; // [esp+10h] [ebp-4h]
  unsigned __int8 *pData; // [esp+1Ch] [ebp+8h]

  v2 = dst;
  numBytesLimit = dst->m_Memory.m_nAllocationCount;
  m_pMemory = src->m_Memory.m_pMemory;
  pData = dst->m_Memory.m_pMemory;
  v5 = (char *)&m_pMemory[src->m_Put];
  pBaseEnd = v5;
  if ( m_pMemory >= (unsigned __int8 *)v5 )
  {
LABEL_30:
    CUtlBuffer::SeekPut(this: v2, type: SEEK_HEAD, offset: v2->m_Memory.m_nAllocationCount - numBytesLimit);
    return 1;
  }
LABEL_2:
  v6 = *m_pMemory;
  if ( *m_pMemory == 45 )
  {
    v7 = 0;
  }
  else if ( (unsigned __int8)(v6 - 97) > 0x1Au )
  {
    if ( (unsigned __int8)(v6 - 65) > 0x1Au )
    {
      if ( (unsigned __int8)(v6 - 48) > 9u )
        v7 = -1;
      else
        v7 = v6 + 7;
    }
    else
    {
      v7 = v6 - 37;
    }
  }
  else
  {
    v7 = v6 - 96;
  }
  v8 = v7;
  ++m_pMemory;
  if ( v7 != -1 )
  {
    v9 = 0;
    while ( m_pMemory < (unsigned __int8 *)v5 )
    {
      v10 = *m_pMemory;
      if ( *m_pMemory == 45 )
      {
        v11 = 0;
      }
      else if ( (unsigned __int8)(v10 - 97) > 0x1Au )
      {
        if ( (unsigned __int8)(v10 - 65) > 0x1Au )
        {
          if ( (unsigned __int8)(v10 - 48) > 9u )
            v11 = -1;
          else
            v11 = v10 + 7;
        }
        else
        {
          v11 = v10 - 37;
        }
      }
      else
      {
        v11 = v10 - 96;
      }
      ++m_pMemory;
      if ( v11 == -1 )
        return 0;
      if ( v11 != 64 )
      {
        v12 = numBytesLimit--;
        if ( v12 <= 0 )
          return 0;
        v5 = pBaseEnd;
        *pData++ = v11 + ((unsigned __int8)((v8 >> v9) % 4) << 6);
      }
      v9 += 2;
      if ( v9 >= 6 )
      {
        if ( m_pMemory < (unsigned __int8 *)v5 )
          goto LABEL_2;
        break;
      }
    }
    v2 = dst;
    goto LABEL_30;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BB8C0
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile)
{
  this->m_eLoadState = 0;
  this->m_iLoadVer = 0;
  this->m_hLoadHeader.sHash[0] = 0;
  this->m_hLoadHeader.sPrefix[0] = 0;
  this->m_hLoadHeader.numLines = -1;
  this->m_hLoadHeader.numBytes = -1;
  this->m_hLoadHeader.numEncBytes = -1;
  this->m_hLoadHeader.numHaveLines = 0;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x100BB8F0
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  CUtlBuffer *p_m_bufLoadData; // esi

  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  p_m_bufLoadData = &this->m_bufLoadData;
  if ( this->m_bufLoadData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_bufLoadData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_bufLoadData->m_Memory.m_pMemory);
      p_m_bufLoadData->m_Memory.m_pMemory = nullptr;
    }
    p_m_bufLoadData->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB960
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::WriteBufferData(class CChunkFile __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::WriteBufferData(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile,
        CUtlBuffer *bufData,
        const char *szPrefix)
{
  int v4; // esi
  ChunkFileResult_t result; // eax
  int v6; // ebx
  int m_Put; // edi
  ChunkFileResult_t v8; // edi
  int v9; // esi
  int v10; // edi
  ChunkFileResult_t v11; // edi
  char chKeyValue[512]; // [esp+Ch] [ebp-294h] BYREF
  char chKeyBuf[80]; // [esp+20Ch] [ebp-94h] BYREF
  CUtlBuffer bufEncoded; // [esp+25Ch] [ebp-44h] BYREF
  int numLastLineBytes; // [esp+28Ch] [ebp-14h]
  ChunkFileResult_t eResult; // [esp+290h] [ebp-10h]
  int v17; // [esp+29Ch] [ebp-4h]
  CUtlBuffer *bufDataa; // [esp+2ACh] [ebp+Ch]

  v4 = 4 * ((bufData->m_Put + 2) / 3);
  CUtlBuffer::CUtlBuffer(this: &bufEncoded, growSize: 0, initSize: 0, nFlags: 0);
  v17 = 0;
  CUtlBuffer::EnsureCapacity(this: &bufEncoded, num: v4);
  if ( KvEncoder::Encode(src: bufData, dst: &bufEncoded) != 0 )
  {
    v6 = (bufEncoded.m_Put + 509) / 510;
    m_Put = bufEncoded.m_Put;
    numLastLineBytes = bufEncoded.m_Put % 510;
    if ( bufEncoded.m_Put % 510 == 0 )
      numLastLineBytes = 510;
    memset(chKeyBuf, 0, sizeof(chKeyBuf));
    memset(chKeyValue, 0, sizeof(chKeyValue));
    sprintf(string: chKeyBuf, format: "%s_ebytes", szPrefix);
    result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: chKeyBuf, nValue: m_Put);
    eResult = result;
    if ( result != ChunkFile_Ok )
    {
      v17 = -1;
      if ( bufEncoded.m_Memory.m_nGrowSize >= 0 )
      {
        if ( bufEncoded.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufEncoded.m_Memory.m_pMemory);
          result = eResult;
          bufEncoded.m_Memory.m_pMemory = nullptr;
        }
        bufEncoded.m_Memory.m_nAllocationCount = 0;
      }
    }
    else
    {
      sprintf(string: chKeyBuf, format: "%s_rbytes", szPrefix);
      eResult = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: chKeyBuf, nValue: bufData->m_Put);
      if ( eResult != ChunkFile_Ok )
      {
        v17 = -1;
        CUtlBuffer::~CUtlBuffer(this: &bufEncoded);
        return eResult;
      }
      else
      {
        sprintf(string: chKeyBuf, format: "%s_lines", szPrefix);
        v8 = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: chKeyBuf, nValue: v6);
        v9 = 0;
        if ( v8 != ChunkFile_Ok )
        {
          v17 = -1;
          CUtlBuffer::~CUtlBuffer(this: &bufEncoded);
          return v8;
        }
        else if ( v6 <= 0 )
        {
LABEL_24:
          v17 = -1;
          if ( bufEncoded.m_Memory.m_nGrowSize >= 0 )
          {
            if ( bufEncoded.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufEncoded.m_Memory.m_pMemory);
              bufEncoded.m_Memory.m_pMemory = nullptr;
            }
            bufEncoded.m_Memory.m_nAllocationCount = 0;
          }
          return ChunkFile_Ok;
        }
        else
        {
          bufDataa = nullptr;
          while ( 1 )
          {
            v10 = 510;
            if ( v9 >= v6 - 1 )
              v10 = numLastLineBytes;
            sprintf(string: chKeyBuf, format: "%s_ln_%d", szPrefix, v9);
            sprintf(
              string: chKeyValue,
              format: "%.*s",
              v10,
              (const char *)&bufEncoded.m_Memory.m_pMemory[(unsigned int)bufDataa]);
            v11 = CChunkFile::WriteKeyValue(this: pFile, pszKey: chKeyBuf, pszValue: chKeyValue);
            if ( v11 != ChunkFile_Ok )
              break;
            bufDataa = (CUtlBuffer *)((char *)bufDataa + 510);
            if ( ++v9 >= v6 )
              goto LABEL_24;
          }
          v17 = -1;
          if ( bufEncoded.m_Memory.m_nGrowSize >= 0 )
          {
            if ( bufEncoded.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufEncoded.m_Memory.m_pMemory);
              bufEncoded.m_Memory.m_pMemory = nullptr;
            }
            bufEncoded.m_Memory.m_nAllocationCount = 0;
          }
          return v11;
        }
      }
    }
  }
  else
  {
    v17 = -1;
    if ( bufEncoded.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufEncoded.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufEncoded.m_Memory.m_pMemory);
        bufEncoded.m_Memory.m_pMemory = nullptr;
      }
      bufEncoded.m_Memory.m_nAllocationCount = 0;
    }
    return ChunkFile_Fail;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBC90
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  ChunkFileResult_t v3; // esi
  CUtlBuffer bufBytes; // [esp+8h] [ebp-3Ch] BYREF
  int v5; // [esp+40h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &bufBytes, growSize: 0, initSize: 0, nFlags: 0);
  v5 = 0;
  CUtlBuffer::EnsureCapacity(this: &bufBytes, num: this->m_hLoadHeader.numBytes + 16);
  if ( KvEncoder::Decode(src: &this->m_bufLoadData, dst: &bufBytes) != 0 )
  {
    v3 = this->OnFileDataLoaded(this, a2: &bufBytes);
    v5 = -1;
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufBytes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
        bufBytes.m_Memory.m_pMemory = nullptr;
      }
      bufBytes.m_Memory.m_nAllocationCount = 0;
    }
    return v3;
  }
  else
  {
    v5 = -1;
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufBytes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
        bufBytes.m_Memory.m_pMemory = nullptr;
      }
      bufBytes.m_Memory.m_nAllocationCount = 0;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBD70
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVmfMeshDataSupport_SaveLoadHandler *__thiscall CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_bufLoadData, growSize: 0, initSize: 0, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BBDC0
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        int numHaveLines)
{
  int numLines; // eax
  ChunkFileResult_t result; // eax

  if ( numHaveLines == 0 )
  {
    CUtlBuffer::EnsureCapacity(this: &this->m_bufLoadData, num: this->m_hLoadHeader.numEncBytes);
    CUtlBuffer::SeekPut(this: &this->m_bufLoadData, type: SEEK_HEAD, offset: 0);
  }
  numLines = this->m_hLoadHeader.numLines;
  this->m_hLoadHeader.numHaveLines = numHaveLines;
  if ( numHaveLines < numLines )
    return ChunkFile_Ok;
  if ( numHaveLines > numLines )
    return ChunkFile_Fail;
  result = CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(this);
  if ( result == ChunkFile_Ok )
  {
    this->m_hLoadHeader.sPrefix[0] = 0;
    this->m_hLoadHeader.numLines = -1;
    this->m_hLoadHeader.numBytes = -1;
    this->m_hLoadHeader.numEncBytes = -1;
    this->m_hLoadHeader.numHaveLines = 0;
    this->m_eLoadState = 3;
    return ChunkFile_Ok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBE50
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  const char *v5; // edi
  CVmfMeshDataSupport_SaveLoadHandler *v6; // ecx
  int v7; // edi

  switch ( this->m_eLoadState )
  {
    case 2:
      if ( _V_stricmp(s1: szKey, s2: "hash") != 0 )
        return ChunkFile_Fail;
      strncpy(dest: (unsigned __int8 *)&this->m_hLoadHeader, source: (unsigned __int8 *)szValue, count: 0x104u);
      this->m_eLoadState = 3;
      return ChunkFile_Ok;
    case 3:
      sprintf(string: this->m_hLoadHeader.sPrefix, format: "%.*s", 3, szKey);
      if ( strlen(szKey) < 4 || szKey[3] != 95 )
        return ChunkFile_Fail;
      this->m_eLoadState = 4;
      goto $LN17_5;
    case 4:
$LN17_5:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 || szKey[3] != 95 )
        return ChunkFile_Fail;
      v5 = szKey + 4;
      if ( _V_stricmp(s1: szKey + 4, s2: "ebytes") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "rbytes") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "lines") != 0 )
            return ChunkFile_Fail;
          this->m_hLoadHeader.numLines = atoi(nptr: szValue);
        }
        else
        {
          this->m_hLoadHeader.numBytes = atoi(nptr: szValue);
        }
      }
      else
      {
        this->m_hLoadHeader.numEncBytes = atoi(nptr: szValue);
      }
      if ( !CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(this) )
        return ChunkFile_Ok;
      this->m_eLoadState = 5;
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this: v6, numHaveLines: 0);
    case 5:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 )
        return ChunkFile_Fail;
      if ( szKey[3] != 95 )
        return ChunkFile_Fail;
      if ( V_strncasecmp(s1: szKey + 4, s2: "ln", n: 2) != 0 )
        return ChunkFile_Fail;
      if ( szKey[6] != 95 )
        return ChunkFile_Fail;
      v7 = atoi(nptr: szKey + 7);
      if ( v7 != this->m_hLoadHeader.numHaveLines )
        return ChunkFile_Fail;
      CUtlBuffer::Put(this: &this->m_bufLoadData, pMem: (unsigned __int8 *)szValue, size: strlen(szValue));
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this, numHaveLines: v7 + 1);
    default:
      return ChunkFile_Fail;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC050
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  ChunkFileResult_t result; // eax
  int v5; // eax

  if ( this->m_eLoadState != 0 )
  {
    if ( this->m_iLoadVer != 1 )
      return ChunkFile_Fail;
    return CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(this, szKey, szValue);
  }
  else
  {
    if ( _V_stricmp(s1: szKey, s2: "version") != 0 )
      return ChunkFile_Fail;
    v5 = atoi(nptr: szValue);
    this->m_iLoadVer = v5;
    result = v5 - 1;
    if ( result != ChunkFile_Ok )
      return ChunkFile_Fail;
    this->m_eLoadState = 2;
  }
  return result;
}

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044D690
// Name: protected: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::OnFileDataWriting(class CChunkFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::OnFileDataWriting(
        IMapEntitySaveLoadHandler *this,
        CChunkFile *pFile,
        CChunkFile *pSaveInfo)
{
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0044D6A0
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(class CChunkFile __near *,enum ChunkFileResult_t)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile,
        ChunkFileResult_t eLoadResult)
{
  ChunkFileResult_t result; // eax
  int m_eLoadState; // edx

  result = eLoadResult;
  if ( eLoadResult == ChunkFile_Ok )
  {
    m_eLoadState = this->m_eLoadState;
    if ( m_eLoadState != 0 )
    {
      result = ChunkFile_Fail;
      if ( this->m_iLoadVer == 1 )
        return (unsigned int)(m_eLoadState - 2) > 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044D6D0
// Name: protected: bool CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  return this->m_hLoadHeader.numLines >= 0 && this->m_hLoadHeader.numBytes >= 0 && this->m_hLoadHeader.numEncBytes >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044D700
// Name: int KvEncoder::Decode(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl KvEncoder::Decode(CUtlBuffer *src, CUtlBuffer *dst)
{
  CUtlBuffer *v2; // esi
  unsigned __int8 *m_pMemory; // edx
  char *v5; // ecx
  unsigned __int8 v6; // al
  char v7; // al
  int v8; // edi
  int v9; // esi
  unsigned __int8 v10; // al
  char v11; // al
  int v12; // ebx
  char *pBaseEnd; // [esp+Ch] [ebp-8h]
  int numBytesLimit; // [esp+10h] [ebp-4h]
  unsigned __int8 *pData; // [esp+1Ch] [ebp+8h]

  v2 = dst;
  numBytesLimit = dst->m_Memory.m_nAllocationCount;
  m_pMemory = src->m_Memory.m_pMemory;
  pData = dst->m_Memory.m_pMemory;
  v5 = (char *)&m_pMemory[src->m_Put];
  pBaseEnd = v5;
  if ( m_pMemory >= (unsigned __int8 *)v5 )
  {
LABEL_30:
    CUtlBuffer::SeekPut(this: v2, type: SEEK_HEAD, offset: v2->m_Memory.m_nAllocationCount - numBytesLimit);
    return 1;
  }
LABEL_2:
  v6 = *m_pMemory;
  if ( *m_pMemory == 45 )
  {
    v7 = 0;
  }
  else if ( (unsigned __int8)(v6 - 97) > 0x1Au )
  {
    if ( (unsigned __int8)(v6 - 65) > 0x1Au )
    {
      if ( (unsigned __int8)(v6 - 48) > 9u )
        v7 = -1;
      else
        v7 = v6 + 7;
    }
    else
    {
      v7 = v6 - 37;
    }
  }
  else
  {
    v7 = v6 - 96;
  }
  v8 = v7;
  ++m_pMemory;
  if ( v7 != -1 )
  {
    v9 = 0;
    while ( m_pMemory < (unsigned __int8 *)v5 )
    {
      v10 = *m_pMemory;
      if ( *m_pMemory == 45 )
      {
        v11 = 0;
      }
      else if ( (unsigned __int8)(v10 - 97) > 0x1Au )
      {
        if ( (unsigned __int8)(v10 - 65) > 0x1Au )
        {
          if ( (unsigned __int8)(v10 - 48) > 9u )
            v11 = -1;
          else
            v11 = v10 + 7;
        }
        else
        {
          v11 = v10 - 37;
        }
      }
      else
      {
        v11 = v10 - 96;
      }
      ++m_pMemory;
      if ( v11 == -1 )
        return 0;
      if ( v11 != 64 )
      {
        v12 = numBytesLimit--;
        if ( v12 <= 0 )
          return 0;
        v5 = pBaseEnd;
        *pData++ = v11 + ((unsigned __int8)((v8 >> v9) % 4) << 6);
      }
      v9 += 2;
      if ( v9 >= 6 )
      {
        if ( m_pMemory < (unsigned __int8 *)v5 )
          goto LABEL_2;
        break;
      }
    }
    v2 = dst;
    goto LABEL_30;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044D820
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile)
{
  this->m_eLoadState = 0;
  this->m_iLoadVer = 0;
  this->m_hLoadHeader.sHash[0] = 0;
  this->m_hLoadHeader.sPrefix[0] = 0;
  this->m_hLoadHeader.numLines = -1;
  this->m_hLoadHeader.numBytes = -1;
  this->m_hLoadHeader.numEncBytes = -1;
  this->m_hLoadHeader.numHaveLines = 0;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0044D850
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  if ( this->m_bufLoadData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufLoadData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufLoadData.m_Memory.m_pMemory);
      this->m_bufLoadData.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufLoadData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D8A0
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  ChunkFileResult_t v3; // esi
  CUtlBuffer bufBytes; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &bufBytes, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::EnsureCapacity(this: &bufBytes, num: this->m_hLoadHeader.numBytes + 16);
  if ( KvEncoder::Decode(src: &this->m_bufLoadData, dst: &bufBytes) != 0 )
  {
    v3 = this->OnFileDataLoaded(this, a2: &bufBytes);
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 && bufBytes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
    return v3;
  }
  else
  {
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 && bufBytes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D940
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVmfMeshDataSupport_SaveLoadHandler *__thiscall CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_bufLoadData, growSize: 0, initSize: 0, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044D960
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        int numHaveLines)
{
  int numLines; // eax
  ChunkFileResult_t result; // eax

  if ( numHaveLines == 0 )
  {
    CUtlBuffer::EnsureCapacity(this: &this->m_bufLoadData, num: this->m_hLoadHeader.numEncBytes);
    CUtlBuffer::SeekPut(this: &this->m_bufLoadData, type: SEEK_HEAD, offset: 0);
  }
  numLines = this->m_hLoadHeader.numLines;
  this->m_hLoadHeader.numHaveLines = numHaveLines;
  if ( numHaveLines < numLines )
    return ChunkFile_Ok;
  if ( numHaveLines > numLines )
    return ChunkFile_Fail;
  result = CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(this);
  if ( result == ChunkFile_Ok )
  {
    this->m_hLoadHeader.sPrefix[0] = 0;
    this->m_hLoadHeader.numLines = -1;
    this->m_hLoadHeader.numBytes = -1;
    this->m_hLoadHeader.numEncBytes = -1;
    this->m_hLoadHeader.numHaveLines = 0;
    this->m_eLoadState = 3;
    return ChunkFile_Ok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044D9F0
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  const char *v5; // edi
  CVmfMeshDataSupport_SaveLoadHandler *v6; // ecx
  int v7; // edi

  switch ( this->m_eLoadState )
  {
    case 2:
      if ( _V_stricmp(s1: szKey, s2: "hash") != 0 )
        return ChunkFile_Fail;
      strncpy(dest: (unsigned __int8 *)&this->m_hLoadHeader, source: (unsigned __int8 *)szValue, count: 0x104u);
      this->m_eLoadState = 3;
      return ChunkFile_Ok;
    case 3:
      sprintf(string: this->m_hLoadHeader.sPrefix, format: "%.*s", 3, szKey);
      if ( strlen(szKey) < 4 || szKey[3] != 95 )
        return ChunkFile_Fail;
      this->m_eLoadState = 4;
      goto $LN17;
    case 4:
$LN17:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 || szKey[3] != 95 )
        return ChunkFile_Fail;
      v5 = szKey + 4;
      if ( _V_stricmp(s1: szKey + 4, s2: "ebytes") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "rbytes") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "lines") != 0 )
            return ChunkFile_Fail;
          this->m_hLoadHeader.numLines = atoi(nptr: szValue);
        }
        else
        {
          this->m_hLoadHeader.numBytes = atoi(nptr: szValue);
        }
      }
      else
      {
        this->m_hLoadHeader.numEncBytes = atoi(nptr: szValue);
      }
      if ( !CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(this) )
        return ChunkFile_Ok;
      this->m_eLoadState = 5;
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this: v6, numHaveLines: 0);
    case 5:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 )
        return ChunkFile_Fail;
      if ( szKey[3] != 95 )
        return ChunkFile_Fail;
      if ( V_strncasecmp(s1: szKey + 4, s2: "ln", n: 2) != 0 )
        return ChunkFile_Fail;
      if ( szKey[6] != 95 )
        return ChunkFile_Fail;
      v7 = atoi(nptr: szKey + 7);
      if ( v7 != this->m_hLoadHeader.numHaveLines )
        return ChunkFile_Fail;
      CUtlBuffer::Put(this: &this->m_bufLoadData, pMem: szValue, size: strlen(szValue));
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this, numHaveLines: v7 + 1);
    default:
      return ChunkFile_Fail;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DBF0
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  ChunkFileResult_t result; // eax
  int v5; // eax

  if ( this->m_eLoadState != 0 )
  {
    if ( this->m_iLoadVer != 1 )
      return ChunkFile_Fail;
    return CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(this, szKey, szValue);
  }
  else
  {
    if ( _V_stricmp(s1: szKey, s2: "version") != 0 )
      return ChunkFile_Fail;
    v5 = atoi(nptr: szValue);
    this->m_iLoadVer = v5;
    result = v5 - 1;
    if ( result != ChunkFile_Ok )
      return ChunkFile_Fail;
    this->m_eLoadState = 2;
  }
  return result;
}

} // namespace vbsp

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00458760
// Name: protected: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::OnFileDataWriting(class CChunkFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::OnFileDataWriting(
        IMapEntitySaveLoadHandler *this,
        CChunkFile *pFile,
        CChunkFile *pSaveInfo)
{
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00458A80
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(class CChunkFile __near *,enum ChunkFileResult_t)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueEnd(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile,
        ChunkFileResult_t eLoadResult)
{
  ChunkFileResult_t result; // eax
  int m_eLoadState; // edx

  result = eLoadResult;
  if ( eLoadResult == ChunkFile_Ok )
  {
    m_eLoadState = this->m_eLoadState;
    if ( m_eLoadState != 0 )
    {
      result = ChunkFile_Fail;
      if ( this->m_iLoadVer == 1 )
        return (unsigned int)(m_eLoadState - 2) > 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458AB0
// Name: protected: bool CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  return this->m_hLoadHeader.numLines >= 0 && this->m_hLoadHeader.numBytes >= 0 && this->m_hLoadHeader.numEncBytes >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00458AE0
// Name: int KvEncoder::Decode(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl KvEncoder::Decode(CUtlBuffer *src, CUtlBuffer *dst)
{
  CUtlBuffer *v2; // esi
  unsigned __int8 *m_pMemory; // edx
  char *v5; // ecx
  unsigned __int8 v6; // al
  char v7; // al
  int v8; // edi
  int v9; // esi
  unsigned __int8 v10; // al
  char v11; // al
  int v12; // ebx
  char *pBaseEnd; // [esp+Ch] [ebp-8h]
  int numBytesLimit; // [esp+10h] [ebp-4h]
  unsigned __int8 *pData; // [esp+1Ch] [ebp+8h]

  v2 = dst;
  numBytesLimit = dst->m_Memory.m_nAllocationCount;
  m_pMemory = src->m_Memory.m_pMemory;
  pData = dst->m_Memory.m_pMemory;
  v5 = (char *)&m_pMemory[src->m_Put];
  pBaseEnd = v5;
  if ( m_pMemory >= (unsigned __int8 *)v5 )
  {
LABEL_30:
    CUtlBuffer::SeekPut(this: v2, type: SEEK_HEAD, offset: v2->m_Memory.m_nAllocationCount - numBytesLimit);
    return 1;
  }
LABEL_2:
  v6 = *m_pMemory;
  if ( *m_pMemory == 45 )
  {
    v7 = 0;
  }
  else if ( (unsigned __int8)(v6 - 97) > 0x1Au )
  {
    if ( (unsigned __int8)(v6 - 65) > 0x1Au )
    {
      if ( (unsigned __int8)(v6 - 48) > 9u )
        v7 = -1;
      else
        v7 = v6 + 7;
    }
    else
    {
      v7 = v6 - 37;
    }
  }
  else
  {
    v7 = v6 - 96;
  }
  v8 = v7;
  ++m_pMemory;
  if ( v7 != -1 )
  {
    v9 = 0;
    while ( m_pMemory < (unsigned __int8 *)v5 )
    {
      v10 = *m_pMemory;
      if ( *m_pMemory == 45 )
      {
        v11 = 0;
      }
      else if ( (unsigned __int8)(v10 - 97) > 0x1Au )
      {
        if ( (unsigned __int8)(v10 - 65) > 0x1Au )
        {
          if ( (unsigned __int8)(v10 - 48) > 9u )
            v11 = -1;
          else
            v11 = v10 + 7;
        }
        else
        {
          v11 = v10 - 37;
        }
      }
      else
      {
        v11 = v10 - 96;
      }
      ++m_pMemory;
      if ( v11 == -1 )
        return 0;
      if ( v11 != 64 )
      {
        v12 = numBytesLimit--;
        if ( v12 <= 0 )
          return 0;
        v5 = pBaseEnd;
        *pData++ = v11 + ((unsigned __int8)((v8 >> v9) % 4) << 6);
      }
      v9 += 2;
      if ( v9 >= 6 )
      {
        if ( m_pMemory < (unsigned __int8 *)v5 )
          goto LABEL_2;
        break;
      }
    }
    v2 = dst;
    goto LABEL_30;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00458C00
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValueBegin(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        CChunkFile *pFile)
{
  this->m_eLoadState = 0;
  this->m_iLoadVer = 0;
  this->m_hLoadHeader.sHash[0] = 0;
  this->m_hLoadHeader.sPrefix[0] = 0;
  this->m_hLoadHeader.numLines = -1;
  this->m_hLoadHeader.numBytes = -1;
  this->m_hLoadHeader.numEncBytes = -1;
  this->m_hLoadHeader.numHaveLines = 0;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00458C30
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  if ( this->m_bufLoadData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufLoadData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufLoadData.m_Memory.m_pMemory);
      this->m_bufLoadData.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufLoadData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458C80
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(CVmfMeshDataSupport_SaveLoadHandler *this)
{
  ChunkFileResult_t v3; // esi
  CUtlBuffer bufBytes; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &bufBytes, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::EnsureCapacity(this: &bufBytes, num: this->m_hLoadHeader.numBytes + 16);
  if ( KvEncoder::Decode(src: &this->m_bufLoadData, dst: &bufBytes) != 0 )
  {
    v3 = this->OnFileDataLoaded(this, a2: &bufBytes);
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 && bufBytes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
    return v3;
  }
  else
  {
    if ( bufBytes.m_Memory.m_nGrowSize >= 0 && bufBytes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufBytes.m_Memory.m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458D20
// Name: public: CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVmfMeshDataSupport_SaveLoadHandler *__thiscall CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(
        CVmfMeshDataSupport_SaveLoadHandler *this)
{
  this->__vftable = (CVmfMeshDataSupport_SaveLoadHandler_vtbl *)&CVmfMeshDataSupport_SaveLoadHandler::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_bufLoadData, growSize: 0, initSize: 0, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00458D40
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        int numHaveLines)
{
  int numLines; // eax
  ChunkFileResult_t result; // eax

  if ( numHaveLines == 0 )
  {
    CUtlBuffer::EnsureCapacity(this: &this->m_bufLoadData, num: this->m_hLoadHeader.numEncBytes);
    CUtlBuffer::SeekPut(this: &this->m_bufLoadData, type: SEEK_HEAD, offset: 0);
  }
  numLines = this->m_hLoadHeader.numLines;
  this->m_hLoadHeader.numHaveLines = numHaveLines;
  if ( numHaveLines < numLines )
    return ChunkFile_Ok;
  if ( numHaveLines > numLines )
    return ChunkFile_Fail;
  result = CVmfMeshDataSupport_SaveLoadHandler::LoadSaveFullData(this);
  if ( result == ChunkFile_Ok )
  {
    this->m_hLoadHeader.sPrefix[0] = 0;
    this->m_hLoadHeader.numLines = -1;
    this->m_hLoadHeader.numBytes = -1;
    this->m_hLoadHeader.numEncBytes = -1;
    this->m_hLoadHeader.numHaveLines = 0;
    this->m_eLoadState = 3;
    return ChunkFile_Ok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458DD0
// Name: protected: enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  const char *v5; // edi
  CVmfMeshDataSupport_SaveLoadHandler *v6; // ecx
  int v7; // edi

  switch ( this->m_eLoadState )
  {
    case 2:
      if ( _V_stricmp(s1: szKey, s2: "hash") != 0 )
        return ChunkFile_Fail;
      strncpy(dest: (unsigned __int8 *)&this->m_hLoadHeader, source: (unsigned __int8 *)szValue, count: 0x104u);
      this->m_eLoadState = 3;
      return ChunkFile_Ok;
    case 3:
      sprintf(string: this->m_hLoadHeader.sPrefix, format: "%.*s", 3, szKey);
      if ( strlen(szKey) < 4 || szKey[3] != 95 )
        return ChunkFile_Fail;
      this->m_eLoadState = 4;
      goto $LN17;
    case 4:
$LN17:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 || szKey[3] != 95 )
        return ChunkFile_Fail;
      v5 = szKey + 4;
      if ( _V_stricmp(s1: szKey + 4, s2: "ebytes") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "rbytes") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "lines") != 0 )
            return ChunkFile_Fail;
          this->m_hLoadHeader.numLines = atoi(nptr: szValue);
        }
        else
        {
          this->m_hLoadHeader.numBytes = atoi(nptr: szValue);
        }
      }
      else
      {
        this->m_hLoadHeader.numEncBytes = atoi(nptr: szValue);
      }
      if ( !CVmfMeshDataSupport_SaveLoadHandler::LoadHaveHeader(this) )
        return ChunkFile_Ok;
      this->m_eLoadState = 5;
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this: v6, numHaveLines: 0);
    case 5:
      if ( V_strncasecmp(s1: this->m_hLoadHeader.sPrefix, s2: szKey, n: 3) != 0 )
        return ChunkFile_Fail;
      if ( szKey[3] != 95 )
        return ChunkFile_Fail;
      if ( V_strncasecmp(s1: szKey + 4, s2: "ln", n: 2) != 0 )
        return ChunkFile_Fail;
      if ( szKey[6] != 95 )
        return ChunkFile_Fail;
      v7 = atoi(nptr: szKey + 7);
      if ( v7 != this->m_hLoadHeader.numHaveLines )
        return ChunkFile_Fail;
      CUtlBuffer::Put(this: &this->m_bufLoadData, pMem: szValue, size: strlen(szValue));
      return CVmfMeshDataSupport_SaveLoadHandler::LoadHaveLines(this, numHaveLines: v7 + 1);
    default:
      return ChunkFile_Fail;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458FD0
// Name: public: virtual enum ChunkFileResult_t CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        const char *szKey,
        char *szValue)
{
  ChunkFileResult_t result; // eax
  int v5; // eax

  if ( this->m_eLoadState != 0 )
  {
    if ( this->m_iLoadVer != 1 )
      return ChunkFile_Fail;
    return CVmfMeshDataSupport_SaveLoadHandler::LoadKeyValue_Ver1(this, szKey, szValue);
  }
  else
  {
    if ( _V_stricmp(s1: szKey, s2: "version") != 0 )
      return ChunkFile_Fail;
    v5 = atoi(nptr: szValue);
    this->m_iLoadVer = v5;
    result = v5 - 1;
    if ( result != ChunkFile_Ok )
      return ChunkFile_Fail;
    this->m_eLoadState = 2;
  }
  return result;
}

} // namespace vmap
