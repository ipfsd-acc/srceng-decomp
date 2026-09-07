// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makemaps.cpp
// Functions: 34
// ============================================================

#include "utils\xbox\makegamedata\makemaps.h"

//------------------------------------------------------------------------------
// Address: 0x004055F0
// Name: bool ReadBSPHeader(char const __near *,struct BSPHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadBSPHeader(const char *pFilename, BSPHeader_t *pHeader)
{
  int v2; // eax
  int v3; // esi

  _V_memset(dest: pHeader, fill: 0, count: 1036);
  v2 = _open(path: pFilename, oflag: 0x8000, pmode: 0);
  v3 = v2;
  if ( v2 == -1 )
    return 0;
  _read(fh: v2, buf: pHeader, cnt: 0x40Cu);
  _close(fh: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405640
// Name: bool GetDependants_BSP(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall GetDependants_BSP@<al>(
        int a1@<ebx>,
        const char *pBspName,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pList)
{
  char v4; // bl
  char szBspFilename[260]; // [esp+0h] [ebp-10Ch] BYREF
  void *pBSPPack; // [esp+104h] [ebp-8h] BYREF
  struct CSysModule *pBSPModule; // [esp+108h] [ebp-4h] BYREF

  if ( g_bModPathIsValid )
  {
    if ( Sys_LoadInterface(
           pModuleName: "bsppack.dll",
           pInterfaceVersionName: "IBSPPACK003",
           pOutModule: &pBSPModule,
           pOutInterface: &pBSPPack) )
    {
      V_ComposeFileName(path: g_szGamePath, filename: pBspName, dest: szBspFilename, destSize: 260);
      v4 = (*(int (__thiscall **)(void *, IFileSystem *, char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *, int))(*(_DWORD *)pBSPPack + 36))(
             a1: pBSPPack,
             a2: g_pFullFileSystem,
             a3: szBspFilename,
             a4: pList,
             a5: a1);
      Sys_UnloadModule(pModule: pBSPModule);
      return v4;
    }
    else
    {
      _Warning(a1: "Failed to load bsppack interface\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Indeterminate mod path, Cannot determine BSP dependants for %s\n", pBspName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056F0
// Name: bool ConvertStudioForSimpleWorldModel(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConvertStudioForSimpleWorldModel(const char *pDebugName, CUtlBuffer *sourceBuf, CUtlBuffer *targetBuf)
{
  int m_Put; // esi
  int v4; // eax

  StudioByteSwap::SourceIsNative(bNative: true);
  StudioByteSwap::ActivateByteSwapping(activate: true);
  m_Put = sourceBuf->m_Put;
  CUtlBuffer::EnsureCapacity(this: targetBuf, num: m_Put + 4096);
  v4 = StudioByteSwap::ByteswapStudioFile(
         pFilename: pDebugName,
         pOutBase: targetBuf->m_Memory.m_pMemory,
         outBaseSize: m_Put + 4096,
         pFileBase: sourceBuf->m_Memory.m_pMemory,
         fileSize: m_Put,
         pHdr: nullptr,
         pCompressFunc: nullptr);
  if ( v4 <= 0 )
  {
    if ( v4 == -1 )
      _Error(this: (ISceneTokenProcessor *)&stru_58D820, a2: pDebugName);
    else
      _Error(this: (ISceneTokenProcessor *)&stru_58D808, a2: pDebugName);
    return 0;
  }
  else
  {
    CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_HEAD, offset: v4);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405780
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405820
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405890
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405900
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405970
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004059E0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A70
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405AE0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B50
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405BD0
// Name: public: void CUtlBuffer::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Purge(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = 0;
  this->m_Error = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C10
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C50
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405D00
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405D40
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, unsigned __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: (unsigned __int8 *)&src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405DB0
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E20
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (int *)&i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F10
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F70
// Name: public: void CUtlBuffer::PutUnsignedInt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedInt(CUtlBuffer *this, unsigned int u)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%u", u);
  else
    CUtlBuffer::PutTypeBin<int>(this, src: u);
}

//------------------------------------------------------------------------------
// Address: 0x00405FA0
// Name: public: void CUtlBuffer::PutFloat(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutFloat(CUtlBuffer *this, float f)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%f", f);
  else
    CUtlBuffer::PutTypeBin<float>(this, src: f);
}

//------------------------------------------------------------------------------
// Address: 0x00405FE0
// Name: bool CreateTargetFile_LMP(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_LMP(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  unsigned int UnsignedInt; // eax
  int v5; // ebx
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  CUtlBuffer compressedBuffer; // [esp+4h] [ebp-98h] BYREF
  CUtlBuffer sourceBuffer; // [esp+34h] [ebp-68h] BYREF
  CUtlBuffer targetBuffer; // [esp+64h] [ebp-38h] BYREF
  unsigned int mapRevision; // [esp+94h] [ebp-8h]
  unsigned int lumpVersion; // [esp+98h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName, buffer: &sourceBuffer, bText: false, bNoOpenFailureWarning: false) )
    goto LABEL_4;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  if ( UnsignedInt != 20 )
  {
    _Warning(
      a1: "ERROR: lump file has invalid signature. ( got '%d' expected '%d' )\n--> %s\n",
      UnsignedInt,
      20,
      pSourceName);
LABEL_4:
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
  v5 = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  lumpVersion = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  v6 = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  mapRevision = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  if ( sourceBuffer.m_nMaxPut - sourceBuffer.m_Get == v6 )
  {
    CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::SetBigEndian(this: &targetBuffer, bigEndian: true);
    if ( (targetBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuffer, pFmt: "%u", 20);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuffer, src: 20);
    if ( (targetBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuffer, pFmt: "%u", v5);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuffer, src: v5);
    if ( (targetBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuffer, pFmt: "%u", lumpVersion);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuffer, src: lumpVersion);
    if ( (targetBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuffer, pFmt: "%u", v6);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuffer, src: v6);
    if ( (targetBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuffer, pFmt: "%u", mapRevision);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuffer, src: mapRevision);
    CUtlBuffer::Put(
      this: &targetBuffer,
      pMem: &sourceBuffer.m_Memory.m_pMemory[sourceBuffer.m_Get - sourceBuffer.m_nOffset],
      size: v6);
    CUtlBuffer::CUtlBuffer(this: &compressedBuffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( CompressCallback(inputBuffer: (signed int)&targetBuffer, outputBuffer: &compressedBuffer) != 0 )
      v7 = WriteBufferToFile(pTargetName, buffer: &compressedBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
    else
      v7 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
    v8 = v7;
    if ( compressedBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( compressedBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: compressedBuffer.m_Memory.m_pMemory);
        compressedBuffer.m_Memory.m_pMemory = nullptr;
      }
      compressedBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
      }
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return v8;
  }
  else
  {
    _Warning(
      a1: "ERROR: lump source buffer doesn't match ength. ( %d should be %d )\n--> %s\n",
      sourceBuffer.m_nMaxPut - sourceBuffer.m_Get,
      v6,
      pSourceName);
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406270
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406310
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004063B0
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406450
// Name: public: void CUtlBuffer::PutUnsignedShort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedShort(CUtlBuffer *this, unsigned __int16 s)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%hu", s);
  else
    CUtlBuffer::PutTypeBin<short>(this, src: s);
}

//------------------------------------------------------------------------------
// Address: 0x00406480
// Name: public: void CUtlBuffer::PutInt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutInt(CUtlBuffer *this, int i)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%d", i);
  else
    CUtlBuffer::PutTypeBin<int>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x004064B0
// Name: bool ConvertVHV(char const __near *,char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __usercall ConvertVHV@<al>(
        int a1@<edi>,
        const char *pVhvFilename,
        const char *pModelName,
        CUtlBuffer *sourceBuffer,
        CUtlBuffer *targetBuffer)
{
  void (*DeleteThis)(void); // eax
  bool v7; // zf
  char vsiFilename[260]; // [esp+0h] [ebp-140h] BYREF
  CUtlBuffer vsiBuffer; // [esp+104h] [ebp-3Ch] BYREF
  int newChecksum; // [esp+134h] [ebp-Ch] BYREF
  int originalChecksum; // [esp+138h] [ebp-8h] BYREF
  IMdlStripInfo *pMdlStripInfo; // [esp+13Ch] [ebp-4h] BYREF

  V_strncpy(pDest: vsiFilename, pSrc: pModelName, maxLen: 260);
  if ( g_bSonyPS3 )
    V_SetExtension(path: vsiFilename, extension: ".ps3.vsi", pathStringLength: 260);
  else
    V_SetExtension(path: vsiFilename, extension: ".360.vsi", pathStringLength: 260);
  CUtlBuffer::CUtlBuffer(this: &vsiBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: vsiFilename,
         a3: nullptr,
         a4: &vsiBuffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    pMdlStripInfo = nullptr;
    if ( mdllib->CreateNewStripInfo(this: mdllib, a2: &pMdlStripInfo) )
    {
      if ( pMdlStripInfo->UnSerialize(this: pMdlStripInfo, a2: &vsiBuffer) )
      {
        originalChecksum = 0;
        newChecksum = 0;
        if ( !pMdlStripInfo->GetCheckSum(this: pMdlStripInfo, a2: &originalChecksum, a3: &newChecksum) )
        {
          _Warning(a1: "Error! Failed to get checksums from '%s'\n", vsiFilename);
          pMdlStripInfo->DeleteThis(this: pMdlStripInfo);
          CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vsiBuffer);
          return 0;
        }
        if ( *((_DWORD *)sourceBuffer->m_Memory.m_pMemory + 1) == originalChecksum )
        {
          CUtlBuffer::EnsureCapacity(this: targetBuffer, num: sourceBuffer->m_nMaxPut);
          CUtlBuffer::Put(this: targetBuffer, pMem: sourceBuffer->m_Memory.m_pMemory, size: sourceBuffer->m_nMaxPut);
          v7 = ((unsigned __int8 (__thiscall *)(IMdlStripInfo *, CUtlBuffer *, int))pMdlStripInfo->StripHardwareVertsBuffer)(
                 a1: pMdlStripInfo,
                 a2: targetBuffer,
                 a3: a1) == 0;
          DeleteThis = (void (*)(void))pMdlStripInfo->DeleteThis;
          if ( !v7 )
          {
            DeleteThis();
            CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vsiBuffer);
            return 1;
          }
        }
        else
        {
          _Warning(a1: "Error! Mismatched checksums from '%s' and '%s'\n", vsiFilename, pVhvFilename);
          DeleteThis = (void (*)(void))pMdlStripInfo->DeleteThis;
        }
        DeleteThis();
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vsiBuffer);
        return 0;
      }
      _Warning(a1: "Error! Failed to unserialize strip info object '%s'\n", vsiFilename);
      pMdlStripInfo->DeleteThis(this: pMdlStripInfo);
    }
    else
    {
      _Warning(a1: "Error! Failed to allocate strip info object\n");
    }
  }
  else
  {
    _Warning(a1: "Error! Missing expected model conversion file '%s'. Cannot perform VHV fixup.\n", vsiFilename);
  }
  if ( vsiBuffer.m_Memory.m_nGrowSize >= 0 && vsiBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vsiBuffer.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004066B0
// Name: bool CreateTargetFile_BSP(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __usercall CreateTargetFile_BSP@<al>(int a1@<ebx>, int a2@<esi>, const char *pSourceName, const char *pTargetName)
{
  char inited; // bl
  const char *v6; // edx
  bool (__cdecl *v7)(const char *, CUtlBuffer *, CUtlBuffer *, bool (__cdecl *)(CUtlBuffer *, CUtlBuffer *), bool); // eax
  CZip *Zip; // esi
  CXZipTool *v9; // eax
  int (__thiscall *GetNextFilename)(struct CZip *, int, char *, int, int *); // eax
  int i; // edi
  int (__thiscall *v12)(struct CZip *, int, char *, int, int *); // edx
  char tempZipName[260]; // [esp+4h] [ebp-3E4h] BYREF
  char filename[260]; // [esp+108h] [ebp-2E0h] BYREF
  char tempSwapName[260]; // [esp+20Ch] [ebp-1DCh] BYREF
  CUtlBuffer targetBuffer; // [esp+310h] [ebp-D8h] BYREF
  CUtlBuffer tempBuffer; // [esp+340h] [ebp-A8h] BYREF
  CUtlBuffer zipBuffer; // [esp+370h] [ebp-78h] BYREF
  CUtlBuffer fileBuffer; // [esp+3A0h] [ebp-48h] BYREF
  struct CSysModule *pBSPModule; // [esp+3D0h] [ebp-18h] BYREF
  int fileSize; // [esp+3D4h] [ebp-14h] BYREF
  void *pBSPPack; // [esp+3D8h] [ebp-10h] BYREF
  int pakSize; // [esp+3DCh] [ebp-Ch] BYREF
  void *pPakData; // [esp+3E0h] [ebp-8h] BYREF
  CXZipTool *pNewXZip; // [esp+3E4h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &zipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &tempBuffer, growSize: 0, initSize: 0, nFlags: 0);
  tempZipName[0] = 0;
  tempSwapName[0] = 0;
  pPakData = nullptr;
  pakSize = 0;
  if ( !g_bModPathIsValid )
  {
    _Warning(a1: "Indeterminate mod path, Cannot perform BSP conversion for %s\n", pSourceName);
LABEL_3:
    if ( tempBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( tempBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuffer.m_Memory.m_pMemory);
        tempBuffer.m_Memory.m_pMemory = nullptr;
      }
      tempBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
        fileBuffer.m_Memory.m_pMemory = nullptr;
      }
      fileBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( zipBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( zipBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: zipBuffer.m_Memory.m_pMemory);
        zipBuffer.m_Memory.m_pMemory = nullptr;
      }
      zipBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "bsppack.dll",
          pInterfaceVersionName: "IBSPPACK003",
          pOutModule: &pBSPModule,
          pOutInterface: &pBSPPack) )
  {
    _Warning(a1: "Failed to load bsppack interface\n");
    goto LABEL_3;
  }
  MakeTemporaryFilename(pPath: tempSwapName, pathSize: 260);
  inited = InitStudioByteSwap();
  if ( inited != 0 )
  {
    if ( g_bSonyPS3 )
    {
      v6 = "ps3";
      v7 = ConvertVTFToPS3Format;
    }
    else
    {
      v6 = "360";
      v7 = ConvertVTFTo360Format;
    }
    inited = (*(int (__thiscall **)(void *, IFileSystem *, const char *, char *, _DWORD, bool (__cdecl *)(const char *, CUtlBuffer *, CUtlBuffer *, bool (__cdecl *)(CUtlBuffer *, CUtlBuffer *), bool), char (__usercall *)@<al>(int@<edi>, const char *, const char *, CUtlBuffer *, CUtlBuffer *), char (__cdecl *)(const char *, CUtlBuffer *, CUtlBuffer *), char (__cdecl *)(signed int, CUtlBuffer *), const char *))(*(_DWORD *)pBSPPack + 24))(
               a1: pBSPPack,
               a2: g_pFullFileSystem,
               a3: pSourceName,
               a4: tempSwapName,
               a5: 0,
               a6: v7,
               a7: ConvertVHV,
               a8: ConvertStudioForSimpleWorldModel,
               a9: CompressCallback,
               a10: v6);
    if ( inited != 0 )
    {
      inited = (*(int (__thiscall **)(void *, IFileSystem *, char *, void **, int *))(*(_DWORD *)pBSPPack + 28))(
                 a1: pBSPPack,
                 a2: g_pFullFileSystem,
                 a3: tempSwapName,
                 a4: &pPakData,
                 a5: &pakSize);
      if ( inited != 0 )
      {
        if ( pPakData == nullptr || pakSize == 0 )
          goto LABEL_39;
        Zip = IZip::CreateZip(pDiskCacheWritePath: nullptr, bSortByName: true);
        ((void (__thiscall *)(CZip *, void *, int, int, int))Zip->ParseFromBuffer)(
          a1: Zip,
          a2: pPakData,
          a3: pakSize,
          a4: a2,
          a5: a1);
        MakeTemporaryFilename(pPath: tempZipName, pathSize: 260);
        v9 = (CXZipTool *)MemAlloc_Alloc(nSize: 0x164u);
        if ( v9 != nullptr )
          pNewXZip = CXZipTool::CXZipTool(this: v9);
        else
          pNewXZip = nullptr;
        CXZipTool::Begin(this: pNewXZip, pZipFileName: tempZipName, alignment: 0x800u);
        GetNextFilename = Zip->GetNextFilename;
        filename[0] = 0;
        fileSize = 0;
        for ( i = ((int (__thiscall *)(CZip *, int, char *))GetNextFilename)(a1: Zip, a2: -1, a3: filename);
              i != -1;
              i = v12(this: Zip, a2: i, a3: filename, a4: 260, a5: &fileSize) )
        {
          CUtlBuffer::Purge(this: &fileBuffer);
          inited = Zip->ReadFileFromZip_2(this: Zip, a2: filename, a3: false, a4: &fileBuffer);
          if ( inited == 0 )
            goto cleanUp;
          inited = CXZipTool::AddBuffer(this: pNewXZip, pFilename: (int)filename, &fileBuffer, bDoPreload: 1u);
          if ( inited == 0 )
            goto cleanUp;
          v12 = Zip->GetNextFilename;
          filename[0] = 0;
          fileSize = 0;
        }
        IZip::ReleaseZip(pZip: Zip);
        CXZipTool::End(this: pNewXZip);
        inited = ReadFileToBuffer(
                   pSourceName: tempZipName,
                   buffer: &zipBuffer,
                   bText: false,
                   bNoOpenFailureWarning: false);
        if ( inited != 0 )
        {
          inited = (*(int (__thiscall **)(void *, IFileSystem *, char *, char *, unsigned __int8 *, int))(*(_DWORD *)pBSPPack + 32))(
                     a1: pBSPPack,
                     a2: g_pFullFileSystem,
                     a3: tempSwapName,
                     a4: tempSwapName,
                     a5: zipBuffer.m_Memory.m_pMemory,
                     a6: zipBuffer.m_nMaxPut);
          if ( inited != 0 )
          {
LABEL_39:
            inited = ReadFileToBuffer(
                       pSourceName: tempSwapName,
                       buffer: &targetBuffer,
                       bText: false,
                       bNoOpenFailureWarning: false);
            if ( inited != 0 )
              inited = WriteBufferToFile(
                         pTargetName,
                         buffer: &targetBuffer,
                         bWriteToZip: false,
                         writeMode: WRITE_TO_DISK_ALWAYS);
          }
        }
      }
    }
  }
  else
  {
    _Warning(a1: "Failed to init studio byte swap\n");
  }
cleanUp:
  if ( tempZipName[0] != 0 )
    _unlink(path: tempZipName);
  if ( tempSwapName[0] != 0 )
    _unlink(path: tempSwapName);
  Sys_UnloadModule(pModule: pBSPModule);
  if ( pPakData != nullptr )
    free(pMem: pPakData);
  if ( tempBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( tempBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuffer.m_Memory.m_pMemory);
      tempBuffer.m_Memory.m_pMemory = nullptr;
    }
    tempBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
      fileBuffer.m_Memory.m_pMemory = nullptr;
    }
    fileBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( zipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( zipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: zipBuffer.m_Memory.m_pMemory);
      zipBuffer.m_Memory.m_pMemory = nullptr;
    }
    zipBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
  return inited;
}

//------------------------------------------------------------------------------
// Address: 0x00406B40
// Name: public: unsigned char CUtlBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetUnsignedChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( (this->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this);
  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406B80
// Name: public: void CUtlBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedChar(CUtlBuffer *this, unsigned __int8 c)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this, pFmt: "%hu", c);
  }
  else if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BD0
// Name: bool CreateTargetFile_AIN(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_AIN(char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // cl
  int Int; // eax
  int v8; // ebx
  int v9; // esi
  int i; // edi
  int j; // esi
  int k; // esi
  unsigned __int8 v13; // bl
  unsigned __int16 UnsignedShort; // ax
  unsigned __int16 v15; // si
  unsigned __int16 Short; // ax
  unsigned __int16 v17; // si
  int v18; // esi
  int m; // edi
  signed __int16 v20; // ax
  signed __int16 v21; // ax
  int n; // esi
  unsigned __int8 v23; // bl
  int ii; // ebx
  int v25; // eax
  int v26; // esi
  bool v27; // bl
  BSPHeader_t bspHeader; // [esp+14h] [ebp-68Ch] BYREF
  char szBspName[260]; // [esp+420h] [ebp-280h] BYREF
  char szBspPath[260]; // [esp+524h] [ebp-17Ch] BYREF
  float inputBuffer; // [esp+628h] [ebp-78h] BYREF
  float src; // [esp+62Ch] [ebp-74h] BYREF
  float v33; // [esp+630h] [ebp-70h] BYREF
  float dest; // [esp+634h] [ebp-6Ch] BYREF
  int nodeCt; // [esp+638h] [ebp-68h]
  CUtlBuffer sourceBuf; // [esp+63Ch] [ebp-64h] BYREF
  unsigned __int16 v37[2]; // [esp+66Ch] [ebp-34h] BYREF
  CUtlBuffer targetBuf; // [esp+670h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName, buffer: &sourceBuf, bText: false, bNoOpenFailureWarning: false) )
  {
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return false;
  }
  V_FileBase(in: pSourceName, out: szBspName, maxlen: 260);
  V_ExtractFilePath(path: pSourceName, dest: szBspPath, destSize: 260);
  V_AppendSlash(pStr: szBspPath, strSize: 260);
  V_strncat(pDest: szBspPath, pSrc: "..\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: szBspPath, pSrc: szBspName, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: szBspPath, pSrc: ".bsp", destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( CompareFileTime(pFilenameA: pSourceName, pFilenameB: szBspPath) < 0 )
  {
    _Warning(a1: "%s: Need to regenerate PC nodegraph (stale)\n", pSourceName);
    if ( !g_bForce )
      goto LABEL_17;
  }
  if ( CUtlBuffer::CheckGet(this: &sourceBuf, nSize: 1) )
  {
    v4 = sourceBuf.m_Memory.m_pMemory[sourceBuf.m_Get - sourceBuf.m_nOffset];
    ++sourceBuf.m_Get;
    if ( v4 == 86 && CUtlBuffer::CheckGet(this: &sourceBuf, nSize: 1) )
    {
      v5 = sourceBuf.m_Memory.m_pMemory[sourceBuf.m_Get - sourceBuf.m_nOffset];
      ++sourceBuf.m_Get;
      if ( v5 == 101 && CUtlBuffer::CheckGet(this: &sourceBuf, nSize: 1) )
      {
        v6 = sourceBuf.m_Memory.m_pMemory[sourceBuf.m_Get - sourceBuf.m_nOffset];
        ++sourceBuf.m_Get;
        if ( v6 == 114 )
        {
          _Warning(a1: "%s: Need to regenerate PC nodegraph (bad format)\n", pSourceName);
          CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuf);
          return false;
        }
      }
    }
  }
  CUtlBuffer::SeekGet(this: &sourceBuf, type: SEEK_HEAD, offset: 0);
  Int = CUtlBuffer::GetInt(this: &sourceBuf);
  if ( Int != 37 )
  {
    _Warning(a1: "%s: Need to regenerate PC nodegraph (got version '%d', expected '%d')\n", pSourceName, Int, 37);
LABEL_17:
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return false;
  }
  v8 = CUtlBuffer::GetInt(this: &sourceBuf);
  if ( ReadBSPHeader(pFilename: szBspPath, pHeader: &bspHeader) != 0 )
  {
    if ( v8 != bspHeader.mapRevision )
    {
      _Warning(
        a1: "%s: Need to regenerate PC nodegraph (ai revision '%d' does not match bsp revision '%d')\n",
        pSourceName,
        v8,
        bspHeader.mapRevision);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuf);
      return false;
    }
  }
  else
  {
    _Warning(a1: "%s: Could not find expected bsp '%s'\n", pSourceName, szBspPath);
  }
  nodeCt = CUtlBuffer::GetInt(this: &sourceBuf);
  if ( (unsigned int)nodeCt > 0x5DC )
  {
    _Warning(a1: "%s: Need to regenerate PC nodegraph (corrupt)\n", pSourceName);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuf);
    return false;
  }
  else
  {
    CUtlBuffer::CUtlBuffer(this: &targetBuf, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::ActivateByteSwapping(this: &targetBuf, bActivate: true);
    CUtlBuffer::PutInt(this: &targetBuf, i: 37);
    CUtlBuffer::PutInt(this: &targetBuf, i: v8);
    v9 = nodeCt;
    CUtlBuffer::PutInt(this: &targetBuf, i: nodeCt);
    if ( v9 > 0 )
    {
      for ( i = v9; i != 0; --i )
      {
        for ( j = 3; j != 0; --j )
        {
          CUtlBuffer::GetType<float>(this: &sourceBuf, &dest);
          if ( (targetBuf.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &targetBuf, pFmt: "%f", dest);
          else
            CUtlBuffer::PutTypeBin<float>(this: &targetBuf, src: dest);
        }
        CUtlBuffer::GetType<float>(this: &sourceBuf, dest: &src);
        if ( (targetBuf.m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%f", src);
        else
          CUtlBuffer::PutTypeBin<float>(this: &targetBuf, src);
        for ( k = 12; k != 0; --k )
        {
          CUtlBuffer::GetType<float>(this: &sourceBuf, dest: &v33);
          if ( (targetBuf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &targetBuf, pFmt: "%f", v33);
          }
          else
          {
            inputBuffer = v33;
            if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 4) )
            {
              if ( (*(_BYTE *)&targetBuf.m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<float>(
                  this: &targetBuf.m_Byteswap,
                  outputBuffer: (float *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset],
                  &inputBuffer,
                  count: 1);
              else
                *(float *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = inputBuffer;
              targetBuf.m_Put += 4;
              CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: targetBuf.m_Put);
            }
          }
        }
        if ( CUtlBuffer::CheckGet(this: &sourceBuf, nSize: 1) )
        {
          v13 = sourceBuf.m_Memory.m_pMemory[sourceBuf.m_Get - sourceBuf.m_nOffset];
          ++sourceBuf.m_Get;
        }
        else
        {
          v13 = 0;
        }
        if ( (targetBuf.m_Flags & 1) != 0
          && targetBuf.m_Put != 0
          && targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &targetBuf);
        }
        if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 1) )
        {
          targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = v13;
          CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: ++targetBuf.m_Put);
        }
        CUtlBuffer::SeekPut(this: &targetBuf, type: SEEK_CURRENT, offset: 3);
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: &sourceBuf);
        v15 = UnsignedShort;
        if ( (targetBuf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%hu", UnsignedShort);
        }
        else
        {
          *(_DWORD *)v37 = UnsignedShort;
          if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 2) )
          {
            if ( (*(_BYTE *)&targetBuf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &targetBuf.m_Byteswap,
                outputBuffer: &targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset],
                inputBuffer: (unsigned __int8 *)v37,
                count: 1);
            else
              *(_WORD *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = v15;
            targetBuf.m_Put += 2;
            CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: targetBuf.m_Put);
          }
        }
        Short = CUtlBuffer::GetShort(this: &sourceBuf);
        v17 = Short;
        if ( (targetBuf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%hd", (__int16)Short);
        }
        else
        {
          *(_DWORD *)v37 = Short;
          if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 2) )
          {
            if ( (*(_BYTE *)&targetBuf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &targetBuf.m_Byteswap,
                outputBuffer: &targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset],
                inputBuffer: (unsigned __int8 *)v37,
                count: 1);
            else
              *(_WORD *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = v17;
            targetBuf.m_Put += 2;
            CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: targetBuf.m_Put);
          }
        }
      }
    }
    v18 = CUtlBuffer::GetInt(this: &sourceBuf);
    if ( (targetBuf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &targetBuf, pFmt: "%d", v18);
    else
      CUtlBuffer::PutTypeBin<int>(this: &targetBuf, src: v18);
    if ( v18 > 0 )
    {
      for ( m = v18; m != 0; --m )
      {
        v20 = CUtlBuffer::GetShort(this: &sourceBuf);
        if ( (targetBuf.m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%hd", v20);
        else
          CUtlBuffer::PutTypeBin<short>(this: &targetBuf, src: v20);
        v21 = CUtlBuffer::GetShort(this: &sourceBuf);
        if ( (targetBuf.m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%hd", v21);
        else
          CUtlBuffer::PutTypeBin<short>(this: &targetBuf, src: v21);
        for ( n = 12; n != 0; --n )
        {
          if ( (sourceBuf.m_Flags & 1) != 0 )
          {
            v23 = CUtlBuffer::GetUnsignedShort(this: &sourceBuf);
          }
          else if ( CUtlBuffer::CheckGet(this: &sourceBuf, nSize: 1) )
          {
            v23 = sourceBuf.m_Memory.m_pMemory[sourceBuf.m_Get - sourceBuf.m_nOffset];
            ++sourceBuf.m_Get;
          }
          else
          {
            v23 = 0;
          }
          if ( (targetBuf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &targetBuf, pFmt: "%hu", v23);
          }
          else if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 1) )
          {
            targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = v23;
            CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: ++targetBuf.m_Put);
          }
        }
      }
    }
    if ( nodeCt > 0 )
    {
      for ( ii = nodeCt; ii != 0; --ii )
      {
        v25 = CUtlBuffer::GetInt(this: &sourceBuf);
        v26 = v25;
        if ( (targetBuf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &targetBuf, pFmt: "%d", v25);
        }
        else
        {
          *(_DWORD *)v37 = v25;
          if ( CUtlBuffer::CheckPut(this: &targetBuf, nSize: 4) )
          {
            if ( (*(_BYTE *)&targetBuf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &targetBuf.m_Byteswap,
                outputBuffer: (int *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset],
                inputBuffer: (int *)v37,
                count: 1);
            else
              *(_DWORD *)&targetBuf.m_Memory.m_pMemory[targetBuf.m_Put - targetBuf.m_nOffset] = v26;
            targetBuf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &targetBuf, nPut: targetBuf.m_Put);
          }
        }
      }
    }
    v27 = WriteBufferToFile(pTargetName, buffer: &targetBuf, bWriteToZip, writeMode: WRITE_TO_DISK_ALWAYS);
    if ( targetBuf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuf.m_Memory.m_pMemory);
        targetBuf.m_Memory.m_pMemory = nullptr;
      }
      targetBuf.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return v27;
  }
}
