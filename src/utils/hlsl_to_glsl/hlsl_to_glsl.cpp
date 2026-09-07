// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlsl_to_glsl/hlsl_to_glsl.cpp
// Functions: 19
// ============================================================

#include "utils\hlsl_to_glsl\hlsl_to_glsl.h"

//------------------------------------------------------------------------------
// Address: 0x10006130
// Name: public: virtual long CDxInclude::Open(enum _D3DXINCLUDE_TYPE,char const __near *,void const __near *,void const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CDxInclude::Open(
        CDxInclude *this,
        _D3DXINCLUDE_TYPE IncludeType,
        const char *pFileName,
        const void *pParentData,
        void **ppData,
        unsigned int *pBytes)
{
  if ( !this->m_pHandler(a1: pFileName, a2: ppData, a3: (int *)&ppData) )
    _Error(a1: "CDxInclude::Open - include file handler failed");
  *pBytes = (unsigned int)ppData;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006180
// Name: public: virtual long CDxInclude::Close(void const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CDxInclude::Close(CDxInclude *this, void *pData)
{
  free(pMem: pData);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100061A0
// Name: void CopyUntilNewLine(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyUntilNewLine(const char *pSrc, char *pOut, int nOutLen)
{
  char *v3; // ecx

  if ( nOutLen <= 1 )
  {
    *pOut = 0;
  }
  else
  {
    v3 = pOut;
    while ( *pSrc != 10 )
      *v3++ = *pSrc++;
    *v3 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100061D0
// Name: void WriteWithComments(char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteWithComments(char *pOut, int nOutBytes, const char *pIn)
{
  const char *v3; // ebx
  char *v4; // esi
  int v5; // edi

  v3 = pIn;
  *pOut = 10;
  *(_WORD *)(pOut + 1) = 12079;
  pOut[3] = 32;
  v4 = pOut + 4;
  if ( *pIn != 0 )
  {
    v5 = 4;
    do
    {
      if ( v5 >= nOutBytes - 10 )
        _Error(a1: "WriteWithComments ran out of space!");
      if ( *v3 != 13 )
      {
        *v4++ = *v3;
        ++v5;
        if ( *v3 == 10 )
        {
          *(_WORD *)v4 = 12079;
          v4[2] = 32;
          v4 += 3;
          v5 += 3;
        }
      }
      ++v3;
    }
    while ( *v3 != 0 );
  }
  *v4 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006240
// Name: void AddSpacing(char __near * __near &,int __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSpacing(char **pCurOut, int *nCurOutLen, int nSpaces)
{
  int v3; // edi
  int v4; // eax
  int v5; // eax

  if ( *nCurOutLen < nSpaces )
    _Error(a1: "AddSpacing ran out of space");
  v3 = (int)*pCurOut;
  v4 = nSpaces % 4;
  if ( nSpaces % 4 > 0 )
  {
    do
    {
      *(*pCurOut)++ = 32;
      --v4;
    }
    while ( v4 != 0 );
  }
  v5 = nSpaces / 4;
  if ( nSpaces / 4 > 0 )
  {
    do
    {
      *(*pCurOut)++ = 9;
      --v5;
    }
    while ( v5 != 0 );
  }
  *nCurOutLen += v3 - (_DWORD)*pCurOut;
}

//------------------------------------------------------------------------------
// Address: 0x100062C0
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006350
// Name: public: void CUtlMemory<unsigned int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned int,int>::Grow(CUtlMemory<char *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (char **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100063E0
// Name: public: int CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned int,int>::Grow((CUtlMemory<char *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006450
// Name: void GetDXASMForByteCode(unsigned int,unsigned int __near *,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDXASMForByteCode(
        unsigned int nVersionHeader,
        unsigned __int8 *pByteCode,
        unsigned int nDWORDs,
        char *pOut,
        int nOutLen)
{
  const char *v5; // eax
  unsigned int *m_pMemory; // esi
  unsigned __int8 *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // [esp-10h] [ebp-28h]
  ID3DXBuffer *v10; // [esp-8h] [ebp-20h]
  CUtlMemory<unsigned int,int> mem; // [esp+8h] [ebp-10h] BYREF
  ID3DXBuffer *pDisasmBuffer; // [esp+14h] [ebp-4h] BYREF

  *pOut = 0;
  pDisasmBuffer = nullptr;
  if ( nVersionHeader == 0 )
  {
    D3DXDisassembleShader(a1: pByteCode, a2: 0, a3: 0, a4: &pDisasmBuffer);
    v10 = pDisasmBuffer;
    v5 = (const char *)((int (*)(void))pDisasmBuffer->GetBufferPointer)();
    V_strncpy(pDest: pOut, pSrc: v5, maxLen: (int)v10);
    ((void (__stdcall *)(ID3DXBuffer *, int))pDisasmBuffer->Release)(a1: pDisasmBuffer, a2: nOutLen);
    return;
  }
  memset(&mem, 0, sizeof(mem));
  CUtlMemory<unsigned int,int>::Grow(this: (CUtlMemory<char *,int> *)&mem, num: nDWORDs + 2);
  m_pMemory = mem.m_pMemory;
  v9 = (unsigned __int8 *)(mem.m_pMemory + 1);
  *mem.m_pMemory = nVersionHeader;
  memcpy(dst: v9, src: pByteCode, count: 4 * nDWORDs);
  m_pMemory[nDWORDs + 1] = 0xFFFF;
  if ( D3DXDisassembleShader(a1: m_pMemory, a2: 0, a3: 0, a4: &pDisasmBuffer) < 0 )
  {
    if ( mem.m_nGrowSize < 0 )
      return;
    goto LABEL_5;
  }
  v7 = (unsigned __int8 *)pDisasmBuffer->GetBufferPointer(this: pDisasmBuffer);
  strchr(string: v7, chr: 0xAu);
  if ( v8 != 0 )
  {
    CopyUntilNewLine(pSrc: (const char *)(v8 + 1), pOut, nOutLen);
    if ( mem.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    pDisasmBuffer->Release(this: pDisasmBuffer);
  }
  else if ( mem.m_nGrowSize >= 0 )
  {
LABEL_5:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006580
// Name: void GetGLASMForByteCode(unsigned int,unsigned int __near *,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetGLASMForByteCode(
        unsigned int nVersionHeader,
        unsigned __int8 *pByteCode,
        unsigned int nDWORDs,
        char *pOut,
        int nOutLen)
{
  unsigned int *m_pMemory; // edi
  int v6; // eax
  unsigned __int8 *v7; // [esp-Ch] [ebp-580h]
  D3DToGL converter; // [esp+Ch] [ebp-568h] BYREF
  CUtlMemory<unsigned int,int> mem; // [esp+568h] [ebp-Ch] BYREF

  memset(&mem, 0, sizeof(mem));
  *pOut = 0;
  CUtlMemory<unsigned int,int>::Grow(this: (CUtlMemory<char *,int> *)&mem, num: nDWORDs + 2);
  m_pMemory = mem.m_pMemory;
  v7 = (unsigned __int8 *)(mem.m_pMemory + 1);
  *mem.m_pMemory = nVersionHeader;
  memcpy(dst: v7, src: pByteCode, count: 4 * nDWORDs);
  m_pMemory[nDWORDs + 1] = 0xFFFF;
  D3DToGL::D3DToGL(this: &converter);
  *(_WORD *)&converter.m_bIncludeEndStatement = 0;
  converter.m_bAddHexCodeComments = false;
  converter.m_bGeneratingDebugText = true;
  if ( D3DToGL::TranslateShader(this: &converter, code: m_pMemory, pDisassembledCode: pOut, nBufLen: nOutLen) != 0 )
  {
    if ( mem.m_nGrowSize < 0 )
      return;
  }
  else
  {
    strstr(str1: (unsigned __int8 *)pOut, str2: "// --- ALU CODE --- //");
    if ( v6 != 0 )
    {
      memmove(
        dst: (unsigned __int8 *)pOut,
        src: (unsigned __int8 *)(v6 + 22),
        count: strlen((const char *)(v6 + 22)) + 1);
      if ( mem.m_nGrowSize < 0 )
        return;
    }
    else
    {
      *pOut = 0;
      if ( mem.m_nGrowSize < 0 )
        return;
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10006690
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006700
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::~CUtlVector<char,class CUtlMemory<char,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this)
{
  bool v2; // sf
  unsigned int *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006770
// Name: class CUtlString chomp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl chomp(CUtlString *result, const char *pStr)
{
  char v3; // al
  const char *v5; // edx
  unsigned int v6; // eax
  const char *v7; // esi
  char v8; // al
  CUtlString sRet; // [esp+8h] [ebp-10h] BYREF

  while ( 1 )
  {
    v3 = *pStr;
    if ( *pStr != 10 && v3 != 32 && v3 != 13 && v3 != 9 )
      break;
    ++pStr;
  }
  if ( *pStr != 0 )
  {
    v5 = pStr + 1;
    v6 = strlen(pStr + 1);
    v7 = &pStr[v6 + 1];
    if ( &v5[v6] > v5 )
    {
      do
      {
        v8 = *v7;
        if ( *v7 != 10 && v8 != 32 && v8 != 13 && v8 != 9 )
          break;
        --v7;
      }
      while ( v7 > v5 );
    }
    CUtlString::CUtlString(this: &sRet);
    CUtlString::SetDirect(this: &sRet, pValue: pStr, nChars: v7 - pStr);
    CUtlString::CUtlString(this: result, string: &sRet);
    sRet.m_Storage.m_nActualLength = 0;
    if ( sRet.m_Storage.m_Memory.m_nGrowSize >= 0 && sRet.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sRet.m_Storage.m_Memory.m_pMemory);
    return result;
  }
  else
  {
    CUtlString::CUtlString(this: result, pString: str);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: void ParseHexCodes(char const __near *,class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseHexCodes(char *pInStr, CUtlMemory<char *,int> *hexCodes)
{
  int v3; // ecx
  char v4; // al
  char v5; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  unsigned int *v8; // ecx
  int v9; // eax
  unsigned int *v10; // eax
  char szCur[256]; // [esp+Ch] [ebp-100h] BYREF

LABEL_1:
  v3 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v4 = *pInStr;
      if ( (*pInStr < 48 || v4 > 57) && (v4 < 65 || v4 > 70) && (v4 < 97 || v4 > 102) && v4 != 120 )
        break;
      while ( 1 )
      {
        v5 = *pInStr;
        if ( (*pInStr < 48 || v5 > 57) && (v5 < 65 || v5 > 70) && (v5 < 97 || v5 > 102) && v5 != 120 )
          break;
        szCur[v3++] = v5;
        ++pInStr;
      }
      if ( v3 > 0 )
      {
        m_pMemory = (int)hexCodes[1].m_pMemory;
        m_nAllocationCount = hexCodes->m_nAllocationCount;
        szCur[v3] = 0;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<unsigned int,int>::Grow(this: hexCodes, num: m_pMemory - m_nAllocationCount + 1);
        ++hexCodes[1].m_pMemory;
        v8 = (unsigned int *)hexCodes->m_pMemory;
        v9 = (int)hexCodes[1].m_pMemory - m_pMemory - 1;
        hexCodes[1].m_nAllocationCount = (int)hexCodes->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (unsigned int *)&hexCodes->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = 0;
        sscanf(string: szCur, format: "%x", &hexCodes->m_pMemory[(int)hexCodes[1].m_pMemory - 1]);
        goto LABEL_1;
      }
    }
    if ( v4 == 10 )
      break;
    ++pInStr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: void StitchAsmIntoGLSL(unsigned int,char const __near *,char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StitchAsmIntoGLSL(
        unsigned int nVersionHeader,
        int pGLSL,
        char *pOut,
        unsigned __int8 *nOutLen,
        bool bCompact)
{
  unsigned __int8 *v5; // esi
  char *v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned int m_Size; // edi
  unsigned int v10; // edi
  unsigned __int8 *v11; // eax
  const char *v12; // esi
  int v13; // eax
  const char *v14; // eax
  unsigned int v15; // kr00_4
  char *v16; // esi
  unsigned __int8 *v17; // ebx
  unsigned int v18; // edi
  unsigned __int8 *v19; // ebx
  char *v20; // esi
  char *v21; // eax
  signed int v22; // edi
  unsigned __int8 *v23; // ebx
  char *v24; // esi
  unsigned int v25; // edi
  unsigned __int8 *v26; // ebx
  unsigned int v27; // edi
  unsigned __int8 *v28; // ebx
  const char *v29; // esi
  unsigned int v30; // edi
  unsigned __int8 *v31; // ebx
  const char *v32; // esi
  char *v33; // eax
  signed int v34; // edi
  char *v35; // eax
  const char *v36; // esi
  unsigned int v37; // ebx
  unsigned __int8 *v38; // edi
  const char *v39; // esi
  const char *v40; // eax
  unsigned int v41; // ebx
  int v42; // eax
  unsigned __int8 *v43; // edx
  char *v44; // ecx
  const char *v45; // esi
  unsigned __int8 v46; // bl
  signed int v47; // edi
  unsigned __int8 *v48; // eax
  const char *v49; // esi
  unsigned int v50; // ebx
  const char *v51; // eax
  unsigned int v52; // ebx
  const char *v53; // esi
  unsigned __int8 *v54; // ebx
  unsigned int v55; // edi
  unsigned __int8 *v56; // ebx
  const char *v57; // esi
  unsigned int v58; // edi
  char **m_pMemory; // eax
  unsigned __int8 *v60; // eax
  signed int v61; // ebx
  unsigned __int8 *v62; // esi
  unsigned __int8 *v63; // esi
  unsigned __int8 *v64; // [esp-8h] [ebp-1068h]
  char pStr[2048]; // [esp+Ch] [ebp-1054h] BYREF
  char pOuta[2048]; // [esp+80Ch] [ebp-854h] BYREF
  CUtlString v67; // [esp+100Ch] [ebp-54h] BYREF
  CUtlString result; // [esp+101Ch] [ebp-44h] BYREF
  unsigned __int8 *v69; // [esp+102Ch] [ebp-34h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hexCodes; // [esp+1030h] [ebp-30h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+1044h] [ebp-1Ch] BYREF
  int v72; // [esp+1058h] [ebp-8h]
  unsigned __int8 *dst; // [esp+105Ch] [ebp-4h] BYREF

  v5 = nOutLen;
  dst = (unsigned __int8 *)pOut;
  *pOut = 0;
  v6 = (char *)pGLSL;
  nOutLen = (unsigned __int8 *)pGLSL;
  strstr(str1: (unsigned __int8 *)pGLSL, str2: "// Hex: ");
  v8 = v7;
  if ( v7 != nullptr )
  {
    do
    {
      memset(&hexCodes, 0, sizeof(hexCodes));
      v69 = v8 + 8;
      ParseHexCodes(pInStr: (char *)v8 + 8, (CUtlMemory<char *,int> *)&hexCodes);
      m_Size = hexCodes.m_Size;
      GetDXASMForByteCode(
        nVersionHeader,
        pByteCode: (unsigned __int8 *)hexCodes.m_Memory.m_pMemory,
        nDWORDs: hexCodes.m_Size,
        pOut: pOuta,
        nOutLen: 2048);
      GetGLASMForByteCode(
        nVersionHeader,
        pByteCode: (unsigned __int8 *)hexCodes.m_Memory.m_pMemory,
        nDWORDs: m_Size,
        pOut: pStr,
        nOutLen: 2048);
      chomp(&result, pStr: pOuta);
      v10 = v8 - nOutLen;
      if ( v8 - nOutLen >= (int)(v5 - 1) )
        v10 = (unsigned int)(v5 - 1);
      memcpy(dst, src: nOutLen, count: v10);
      v11 = &dst[v10];
      v12 = (const char *)&v5[-v10];
      *v11 = 0;
      dst = v11;
      pGLSL = (int)v12;
      strchr(string: v8, chr: 0xAu);
      if ( v13 == 0 )
        strchr(string: v8, chr: 0);
      v72 = v13;
      nOutLen = (unsigned __int8 *)(v13 + 1);
      if ( bCompact )
      {
        v14 = (const char *)dst;
        if ( dst > (unsigned __int8 *)pOut )
        {
          while ( *v14 != 10 )
          {
            if ( --v14 <= pOut )
              goto LABEL_12;
          }
          ++v14;
        }
LABEL_12:
        v15 = strlen(v14);
        AddSpacing(pCurOut: (char **)&dst, nCurOutLen: &pGLSL, nSpaces: (56 - v15) & (((int)(56 - v15) <= 0) - 1));
        v16 = (char *)pGLSL;
        v17 = dst;
        v18 = 18;
        if ( pGLSL - 1 <= 18 )
          v18 = pGLSL - 1;
        memcpy(dst, src: "// DirectX ASM :  ", count: v18);
        v19 = &v17[v18];
        *v19 = 0;
        v20 = &v16[-v18];
        v21 = (char *)CUtlString::operator char const *(this: &result);
        v22 = strlen(v21);
        if ( v22 >= (int)(v20 - 1) )
          v22 = (signed int)(v20 - 1);
        memcpy(dst: v19, src: (unsigned __int8 *)v21, count: v22);
        v23 = &v19[v22];
        v24 = &v20[-v22];
        v25 = 1;
        if ( (int)(v24 - 1) <= 1 )
          v25 = (unsigned int)(v24 - 1);
        *v23 = 0;
        memcpy(dst: v23, src: "\n", count: v25);
        v23[v25] = 0;
        dst = &v23[v25];
        v5 = (unsigned __int8 *)&v24[-v25];
      }
      else
      {
        v26 = dst;
        v27 = 73;
        if ( (int)(v12 - 1) <= 73 )
          v27 = (unsigned int)(v12 - 1);
        memcpy(dst, src: "// ------------------------------------------------------------------ //\n", count: v27);
        v28 = &v26[v27];
        v29 = &v12[-v27];
        v30 = 18;
        if ( (int)(v29 - 1) <= 18 )
          v30 = (unsigned int)(v29 - 1);
        *v28 = 0;
        memcpy(dst: v28, src: "// DirectX ASM :  ", count: v30);
        v31 = &v28[v30];
        *v31 = 0;
        v32 = &v29[-v30];
        v33 = (char *)CUtlString::operator char const *(this: &result);
        v34 = strlen(v33);
        if ( v34 >= (int)(v32 - 1) )
          v34 = (signed int)(v32 - 1);
        memcpy(dst: v31, src: (unsigned __int8 *)v33, count: v34);
        v35 = (char *)&v31[v34];
        v36 = &v32[-v34];
        v37 = 1;
        if ( (int)(v36 - 1) <= 1 )
          v37 = (unsigned int)(v36 - 1);
        pGLSL = (int)v35;
        *v35 = 0;
        memcpy(dst: (unsigned __int8 *)v35, src: "\n", count: v37);
        v38 = (unsigned __int8 *)(v37 + pGLSL);
        *(_BYTE *)(v37 + pGLSL) = 0;
        v39 = &v36[-v37];
        chomp(result: &v67, pStr);
        memset(&outStrings, 0, sizeof(outStrings));
        v40 = CUtlString::operator char const *(this: &v67);
        V_SplitString(pString: v40, pSeparator: "\n", &outStrings);
        pGLSL = 0;
        if ( outStrings.m_Size > 0 )
        {
          do
          {
            v41 = 18;
            if ( (int)(v39 - 1) <= 18 )
              v41 = (unsigned int)(v39 - 1);
            memcpy(dst: v38, src: "// OpenGL ASM  :  ", count: v41);
            v42 = pGLSL;
            v43 = &v38[v41];
            v38[v41] = 0;
            v44 = outStrings.m_Memory.m_pMemory[v42];
            dst = &v38[v41];
            v45 = &v39[-v41];
            v47 = strlen(v44);
            if ( v47 >= (int)(v45 - 1) )
              v47 = (signed int)(v45 - 1);
            memcpy(dst: v43, src: (unsigned __int8 *)v44, count: v47);
            v48 = &dst[v47];
            dst[v47] = v46;
            v49 = &v45[-v47];
            v50 = 1;
            if ( (int)(v49 - 1) <= 1 )
              v50 = (unsigned int)(v49 - 1);
            dst = v48;
            memcpy(dst: v48, src: "\n", count: v50);
            v38 = &dst[v50];
            v51 = (const char *)(pGLSL + 1);
            dst[v50] = 0;
            v39 = &v49[-v50];
            pGLSL = (int)v51;
          }
          while ( (int)v51 < outStrings.m_Size );
        }
        CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
        v52 = 21;
        pGLSL = 21;
        if ( (int)(v39 - 1) <= 21 )
        {
          pGLSL = (int)(v39 - 1);
          v52 = (unsigned int)(v39 - 1);
        }
        memcpy(dst: v38, src: "//\n// Hex Code    :  ", count: v52);
        v53 = &v39[-pGLSL];
        v54 = &v38[v52];
        v55 = v72 - (_DWORD)v69;
        if ( v72 - (int)v69 >= (int)(v53 - 1) )
          v55 = (unsigned int)(v53 - 1);
        v64 = v69;
        *v54 = 0;
        memcpy(dst: v54, src: v64, count: v55);
        v56 = &v54[v55];
        v57 = &v53[-v55];
        v58 = 74;
        if ( (int)(v57 - 1) <= 74 )
          v58 = (unsigned int)(v57 - 1);
        *v56 = 0;
        memcpy(
          dst: v56,
          src: "\n// ------------------------------------------------------------------ //\n",
          count: v58);
        v5 = (unsigned __int8 *)&v57[-v58];
        v56[v58] = 0;
        dst = &v56[v58];
        m_pMemory = outStrings.m_Memory.m_pMemory;
        outStrings.m_Size = 0;
        if ( outStrings.m_Memory.m_nGrowSize >= 0 )
        {
          if ( outStrings.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outStrings.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            outStrings.m_Memory.m_pMemory = nullptr;
          }
          outStrings.m_Memory.m_nAllocationCount = 0;
        }
        outStrings.m_pElements = m_pMemory;
        if ( outStrings.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            outStrings.m_Memory.m_pMemory = nullptr;
          }
          outStrings.m_Memory.m_nAllocationCount = 0;
        }
        v67.m_Storage.m_nActualLength = 0;
        if ( v67.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v67.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v67.m_Storage.m_Memory.m_pMemory);
            v67.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v67.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      result.m_Storage.m_nActualLength = 0;
      if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( result.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
          result.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        result.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( hexCodes.m_Memory.m_nGrowSize >= 0 && hexCodes.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hexCodes.m_Memory.m_pMemory);
      strstr(str1: nOutLen, str2: "// Hex: ");
      v8 = v60;
    }
    while ( v60 != nullptr );
    v6 = (char *)nOutLen;
  }
  v61 = strlen(v6);
  v62 = v5 - 1;
  if ( v61 >= (int)v62 )
    v61 = (signed int)v62;
  v63 = dst;
  memcpy(dst, src: (unsigned __int8 *)v6, count: v61);
  v63[v61] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006E10
// Name: void TranslateHLSLToDXByteCode(char const __near *,char const __near *,bool (*)(char const __near *,void __near * __near *,int __near *),class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TranslateHLSLToDXByteCode(
        const char *pProgram,
        const char *pShaderVersion,
        bool (__cdecl *pHandler)(const char *, void **, int *),
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *dxasmData)
{
  const char *v4; // eax
  int v5; // eax
  unsigned __int8 **v6; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // eax
  bool (__cdecl *v10)(const char *, void **, int *); // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  CDxInclude include; // [esp+4h] [ebp-Ch] BYREF
  ID3DXBuffer *pErrorMessages; // [esp+Ch] [ebp-4h] BYREF

  include.m_pHandler = pHandler;
  include.__vftable = (CDxInclude_vtbl *)&CDxInclude::`vftable';
  if ( D3DXCompileShader(
         a1: pProgram,
         a2: strlen(pProgram) + 1,
         a3: s_pPreDefinedMacros,
         a4: &include,
         a5: "main",
         a6: pShaderVersion,
         a7: 513,
         a8: &pHandler,
         a9: &pErrorMessages,
         a10: 0) < 0 )
  {
    v4 = (const char *)pErrorMessages->GetBufferPointer(this: pErrorMessages);
    _Error(a1: "Failed to translate shader:\n%s\n", v4);
  }
  v5 = (*(int (__stdcall **)(bool (__cdecl *)(const char *, void **, int *)))(*(_DWORD *)pHandler + 16))(a1: pHandler);
  v6 = (unsigned __int8 **)dxasmData;
  v7 = dxasmData;
  dxasmData->m_Size = 0;
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(this: v7, elem: 0, num: v5);
  v8 = *v6;
  v11 = (*(int (__stdcall **)(bool (__cdecl *)(const char *, void **, int *)))(*(_DWORD *)pHandler + 16))(a1: pHandler);
  v10 = pHandler;
  v9 = (unsigned __int8 *)(*(int (**)(void))(*(_DWORD *)pHandler + 12))();
  memcpy(dst: v8, src: v9, count: (unsigned int)v10);
  (*(void (__stdcall **)(bool (__cdecl *)(const char *, void **, int *), int))(*(_DWORD *)pHandler + 8))(
    a1: pHandler,
    a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10006EE0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x10006F50
// Name: public: virtual void CHLSLToGLSL::TranslateHLSLToGLSL(char const __near *,char const __near *,bool (*)(char const __near *,void __near * __near *,int __near *),char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLSLToGLSL::TranslateHLSLToGLSL(
        CHLSLToGLSL *this,
        const char *pProgram,
        const char *pShaderVersion,
        bool (__cdecl *pHandler)(const char *, void **, int *),
        char *pOut,
        int nOutBytes,
        char nFlags)
{
  int v7; // edi
  unsigned __int8 *v8; // esi
  const char *v9; // eax
  unsigned int *m_pMemory; // [esp-10h] [ebp-5ACh]
  bool (__cdecl *v11)(const char *, void **, int *); // [esp-8h] [ebp-5A4h]
  int m_nAllocationCount; // [esp-4h] [ebp-5A0h]
  D3DToGL v13; // [esp+Ch] [ebp-590h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > dxasmData; // [esp+568h] [ebp-34h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > backup; // [esp+57Ch] [ebp-20h] BYREF
  CUtlMemory<char,int> tempBuf; // [esp+590h] [ebp-Ch] BYREF

  memset(&dxasmData, 0, sizeof(dxasmData));
  TranslateHLSLToDXByteCode(pProgram, pShaderVersion, pHandler, &dxasmData);
  if ( dxasmData.m_Size == 0 )
    _Error(a1: "TranslateDX9HLSLToDXByteCode returned 0 bytes of bytecode!");
  D3DToGL::D3DToGL(this: &v13);
  v7 = nOutBytes;
  v8 = (unsigned __int8 *)pOut;
  v13.m_bAddHexCodeComments = (nFlags & 3) != 0;
  v13.m_bGLSL = true;
  LOBYTE(pHandler) = (nFlags & 2) != 0;
  v13.m_bPutHexCodesAfterLines = (char)pHandler;
  if ( D3DToGL::TranslateShader(
         this: &v13,
         code: dxasmData.m_Memory.m_pMemory,
         pDisassembledCode: pOut,
         nBufLen: nOutBytes) != 0 )
    _Error(a1: "TranslateDXByteCodeToGLSL error.");
  if ( (nFlags & 1) != 0 )
  {
    memset(&tempBuf, 0, sizeof(tempBuf));
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&tempBuf, num: 0x80000);
    StitchAsmIntoGLSL(
      nVersionHeader: *dxasmData.m_Memory.m_pMemory,
      pGLSL: (int)v8,
      pOut: tempBuf.m_pMemory,
      nOutLen: (unsigned __int8 *)tempBuf.m_nAllocationCount,
      bCompact: (bool)pHandler);
    if ( tempBuf.m_nAllocationCount > v7 )
      _Error(a1: "TranslateHLSLToGLSL: Not enough room to stitch asm in.");
    memcpy(dst: v8, src: (unsigned __int8 *)tempBuf.m_pMemory, count: tempBuf.m_nAllocationCount);
    if ( tempBuf.m_nGrowSize >= 0 && tempBuf.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuf.m_pMemory);
  }
  if ( (nFlags & 4) != 0 )
  {
    memset(&tempBuf, 0, sizeof(tempBuf));
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&tempBuf, num: 0x80000);
    m_pMemory = dxasmData.m_Memory.m_pMemory;
    *tempBuf.m_pMemory = 0;
    pHandler = nullptr;
    D3DXDisassembleShader(a1: m_pMemory, a2: 0, a3: 0, a4: &pHandler);
    m_nAllocationCount = tempBuf.m_nAllocationCount;
    v11 = pHandler;
    v9 = (const char *)(*(int (**)(void))(*(_DWORD *)pHandler + 12))();
    V_strncpy(pDest: tempBuf.m_pMemory, pSrc: v9, maxLen: (int)v11);
    (*(void (__stdcall **)(bool (__cdecl *)(const char *, void **, int *), int))(*(_DWORD *)pHandler + 8))(
      a1: pHandler,
      a2: m_nAllocationCount);
    memset(&backup, 0, sizeof(backup));
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: &backup,
      pArray: (const char *)v8,
      size: strlen((const char *)v8) + 1);
    WriteWithComments(pOut: (char *)v8, nOutBytes: v7, pIn: tempBuf.m_pMemory);
    V_strncat(pDest: (char *)v8, pSrc: "\n\n\n\n", destBufferSize: v7, max_chars_to_copy: -1);
    V_strncat(pDest: (char *)v8, pSrc: backup.m_Memory.m_pMemory, destBufferSize: v7, max_chars_to_copy: -1);
    CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&backup);
    if ( tempBuf.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuf.m_pMemory);
  }
  if ( (nFlags & 8) != 0 )
  {
    memset(&backup, 0, sizeof(backup));
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: &backup,
      pArray: (const char *)v8,
      size: strlen((const char *)v8) + 1);
    WriteWithComments(pOut: (char *)v8, nOutBytes: v7, pIn: pProgram);
    V_strncat(pDest: (char *)v8, pSrc: "\n\n\n\n", destBufferSize: v7, max_chars_to_copy: -1);
    V_strncat(pDest: (char *)v8, pSrc: backup.m_Memory.m_pMemory, destBufferSize: v7, max_chars_to_copy: -1);
    CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&backup);
  }
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &dxasmData);
}

//------------------------------------------------------------------------------
// Address: 0x100062B0
// Name: __CreateCHLSLToGLSLIHLSLToGLSL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHLSLToGLSL *__cdecl _CreateCHLSLToGLSLIHLSLToGLSL_interface()
{
  return &_g_CHLSLToGLSL_singleton;
}
