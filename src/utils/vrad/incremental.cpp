// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/incremental.cpp
// Functions: 29
// ============================================================

#include "utils\vrad\incremental.h"

//------------------------------------------------------------------------------
// Address: 0x10002300
// Name: public: float Vector::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::operator[](Vector *this, int i)
{
  return *(&this->x + i);
}

//------------------------------------------------------------------------------
// Address: 0x100049F0
// Name: float fabs(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl fabs(float _X)
{
  return fabs(_X);
}

//------------------------------------------------------------------------------
// Address: 0x10004A00
// Name: public: float __near & Vector::operator[](int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator[](Vector *this, int i)
{
  return (Vector *)((char *)this + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x10004A40
// Name: CompareLights
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall CompareLights@<eax>(dworldlight_t *a@<ecx>, dworldlight_t *b@<eax>)
{
  bool v2; // bl
  bool v3; // dl
  bool v4; // al
  bool a8; // [esp+0h] [ebp-8h]
  bool a7; // [esp+1h] [ebp-7h]
  bool a6; // [esp+2h] [ebp-6h]
  bool a5; // [esp+3h] [ebp-5h]
  bool a4; // [esp+4h] [ebp-4h]
  bool a3; // [esp+5h] [ebp-3h]
  bool a2; // [esp+6h] [ebp-2h]
  bool a1; // [esp+7h] [ebp-1h]

  if ( fabs(a->origin.x - b->origin.x) > flEpsilon
    || fabs(a->origin.y - b->origin.y) > flEpsilon
    || (a1 = true, flEpsilon < fabs(a->origin.z - b->origin.z)) )
  {
    a1 = false;
  }
  if ( fabs(a->intensity.x - b->intensity.x) > 1.1
    || fabs(a->intensity.y - b->intensity.y) > 1.1
    || (a2 = true, fabs(a->intensity.z - b->intensity.z) > 1.1) )
  {
    a2 = false;
  }
  if ( fabs(a->normal.x - b->normal.x) > flEpsilon
    || fabs(a->normal.y - b->normal.y) > flEpsilon
    || (a3 = true, flEpsilon < fabs(a->normal.z - b->normal.z)) )
  {
    a3 = false;
  }
  a4 = flEpsilon > fabs(a->constant_attn - b->constant_attn);
  a5 = flEpsilon > fabs(a->linear_attn - b->linear_attn);
  a6 = flEpsilon > fabs(a->quadratic_attn - b->quadratic_attn);
  a7 = flEpsilon > fabs((float)(a->flags - b->flags));
  a8 = flEpsilon > fabs(a->stopdot - b->stopdot);
  v2 = flEpsilon > fabs(a->stopdot2 - b->stopdot2);
  v3 = flEpsilon > fabs(a->exponent - b->exponent);
  v4 = flEpsilon > fabs(a->radius - b->radius);
  return a1 && a2 && a3 && a4 && a5 && a6 && a7 && a8 && v2 && v3 && v4;
}

//------------------------------------------------------------------------------
// Address: 0x10004C40
// Name: public: virtual bool CIncremental::Init(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIncremental::Init(CIncremental *this, const char *pBSPFilename, const char *pIncrementalFilename)
{
  this->m_pBSPFilename = pBSPFilename;
  this->m_pIncrementalFilename = pIncrementalFilename;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004C60
// Name: public: struct dworldlight_t __near & dworldlight_t::operator=(struct dworldlight_t const __near &)
// Source: json
//------------------------------------------------------------------------------
dworldlight_t *__thiscall dworldlight_t::operator=(dworldlight_t *this, const dworldlight_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004D90
// Name: public: void CUtlMemory<class CIncrementalHeader::CLMSize,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CIncrementalHeader::CLMSize,int>::Grow(CUtlMemory<CBSPTreeData::Leaf_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBSPTreeData::Leaf_t *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBSPTreeData::Leaf_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBSPTreeData::Leaf_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005370
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
          outputBuffer: (unsigned __int16 *)&s,
          inputBuffer: (unsigned __int16 *)&v2[this->m_Get],
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
// Address: 0x10005410
// Name: public: CIncLight::CIncLight(void)
// Source: json
//------------------------------------------------------------------------------
CIncLight *__thiscall CIncLight::CIncLight(CIncLight *this)
{
  UtlLinkedListElem_t<CLightFace *,unsigned short> *m_pMemory; // ecx

  this->m_LightFaces.m_Memory.m_pMemory = nullptr;
  this->m_LightFaces.m_Memory.m_nAllocationCount = 0;
  this->m_LightFaces.m_Memory.m_nGrowSize = 0;
  this->m_LightFaces.m_LastAlloc.index = -1;
  this->m_LightFaces.m_NumAlloced = 0;
  *(_DWORD *)&this->m_LightFaces.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_LightFaces.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LightFaces.m_Head = -1;
  this->m_LightFaces.m_pElements = m_pMemory;
  memset(dst: (unsigned __int8 *)this->m_pCachedFaces, value: 0, count: sizeof(this->m_pCachedFaces));
  InitializeCriticalSection(lpCriticalSection: &this->m_CS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100055A0
// Name: unsigned short DecodeCharOrShort(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl DecodeCharOrShort(CUtlBuffer *pIn)
{
  unsigned __int16 result; // ax
  char v2; // bl
  unsigned __int8 v3; // al

  if ( (pIn->m_Flags & 1) != 0 )
  {
    LOBYTE(result) = CUtlBuffer::GetUnsignedShort(this: pIn);
  }
  else if ( CUtlBuffer::CheckGet(this: pIn, nSize: 1) )
  {
    LOBYTE(result) = pIn->m_Memory.m_pMemory[pIn->m_Get - pIn->m_nOffset];
    ++pIn->m_Get;
  }
  else
  {
    LOBYTE(result) = 0;
  }
  v2 = result;
  if ( (result & 0x80u) == 0 )
    return (unsigned __int8)result;
  if ( (pIn->m_Flags & 1) != 0 )
    return (unsigned __int8)CUtlBuffer::GetUnsignedShort(this: pIn) | ((result & 0x7F) << 8);
  if ( !CUtlBuffer::CheckGet(this: pIn, nSize: 1) )
    return (v2 & 0x7F) << 8;
  v3 = pIn->m_Memory.m_pMemory[pIn->m_Get - pIn->m_nOffset];
  ++pIn->m_Get;
  return v3 | ((v2 & 0x7F) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x10005650
// Name: void EncodeCharOrShort(class CUtlBuffer __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EncodeCharOrShort(CUtlBuffer *pBuf, unsigned __int16 val)
{
  unsigned __int16 v2; // bx
  CUtlBuffer *v3; // esi

  v2 = val;
  if ( (val & 0xFF80) != 0 )
  {
    if ( val > 0x7FFFu )
      v2 = 0x7FFF;
    v3 = pBuf;
    if ( (pBuf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: pBuf, pFmt: "%hu", HIBYTE(v2) | 0x80);
    }
    else if ( CUtlBuffer::CheckPut(this: pBuf, nSize: 1) )
    {
      pBuf->m_Memory.m_pMemory[pBuf->m_Put - pBuf->m_nOffset] = HIBYTE(v2) | 0x80;
      CUtlBuffer::AddNullTermination(this: pBuf, nPut: ++pBuf->m_Put);
    }
    if ( (pBuf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: pBuf, pFmt: "%hu", (unsigned __int8)v2);
    }
    else if ( CUtlBuffer::CheckPut(this: pBuf, nSize: 1) )
    {
LABEL_4:
      v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v2;
      CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
    }
  }
  else
  {
    v3 = pBuf;
    if ( (pBuf->m_Flags & 1) == 0 )
    {
      if ( !CUtlBuffer::CheckPut(this: pBuf, nSize: 1) )
        return;
      goto LABEL_4;
    }
    CUtlBuffer::Printf(this: pBuf, pFmt: "%hu", (unsigned __int8)val);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005750
// Name: void DecompressLightData(class CUtlBuffer __near *,class CUtlVector<class CLightValue,class CUtlMemory<class CLightValue,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecompressLightData(CUtlBuffer *pIn, CUtlVector<CLightValue,CUtlMemory<CLightValue,int> > *pOut)
{
  unsigned __int8 UnsignedShort; // bl
  unsigned __int16 v3; // ax
  int v4; // edx
  int v5; // eax
  int iOut; // [esp+4h] [ebp-4h]

  iOut = 0;
  while ( pIn->m_Get < pIn->m_Put )
  {
    if ( (pIn->m_Flags & 1) != 0 )
    {
      UnsignedShort = CUtlBuffer::GetUnsignedShort(this: pIn);
    }
    else if ( CUtlBuffer::CheckGet(this: pIn, nSize: 1) )
    {
      UnsignedShort = pIn->m_Memory.m_pMemory[pIn->m_Get++ - pIn->m_nOffset];
    }
    else
    {
      UnsignedShort = 0;
    }
    v3 = DecodeCharOrShort(pIn);
    if ( UnsignedShort != 0 )
    {
      v4 = v3;
      v5 = iOut;
      do
      {
        pOut->m_Memory.m_pMemory[v5++].m_Dot = (float)v4;
        --UnsignedShort;
      }
      while ( UnsignedShort != 0 );
      iOut = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100057E0
// Name: void CompressLightData(class CLightValue const __near *,int,class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CompressLightData(const CLightValue *pValues, int nValues, CUtlBuffer *pBuf)
{
  int v3; // eax
  unsigned __int8 v4; // bl
  int m_Dot; // edx
  unsigned __int16 v6; // di
  int i; // [esp+4h] [ebp-8h]
  unsigned __int16 flLastValue; // [esp+8h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  i = 0;
  if ( nValues <= 0 )
    return;
  do
  {
    m_Dot = (int)pValues[v3].m_Dot;
    v6 = m_Dot;
    if ( v3 != 0 )
    {
      if ( (_WORD)m_Dot == flLastValue && v4 != 0xFF )
      {
        ++v4;
        goto LABEL_13;
      }
      if ( (pBuf->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: pBuf, pFmt: "%hu", v4);
      }
      else if ( CUtlBuffer::CheckPut(this: pBuf, nSize: 1) )
      {
        pBuf->m_Memory.m_pMemory[pBuf->m_Put - pBuf->m_nOffset] = v4;
        CUtlBuffer::AddNullTermination(this: pBuf, nPut: ++pBuf->m_Put);
      }
      EncodeCharOrShort(pBuf, val: flLastValue);
      flLastValue = v6;
      v3 = i;
    }
    else
    {
      flLastValue = m_Dot;
    }
    v4 = 1;
LABEL_13:
    i = ++v3;
  }
  while ( v3 < nValues );
  if ( v4 == 0 )
    return;
  if ( (pBuf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: pBuf, pFmt: "%hu", v4);
  }
  else if ( CUtlBuffer::CheckPut(this: pBuf, nSize: 1) )
  {
    pBuf->m_Memory.m_pMemory[pBuf->m_Put - pBuf->m_nOffset] = v4;
    CUtlBuffer::AddNullTermination(this: pBuf, nPut: ++pBuf->m_Put);
    EncodeCharOrShort(pBuf, val: flLastValue);
    return;
  }
  EncodeCharOrShort(pBuf, val: flLastValue);
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: class IIncremental __near * GetIncremental(void)
// Source: json
//------------------------------------------------------------------------------
CIncremental *__cdecl GetIncremental()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    inc.__vftable = (CIncremental_vtbl *)&CIncremental::`vftable';
    inc.m_Lights.m_Memory.m_pMemory = nullptr;
    inc.m_Lights.m_Memory.m_nAllocationCount = 0;
    inc.m_Lights.m_Memory.m_nGrowSize = 0;
    inc.m_Lights.m_LastAlloc.index = -1;
    *(_DWORD *)&inc.m_Lights.m_Head = -1;
    *(_DWORD *)&inc.m_Lights.m_FirstFree = 0xFFFF;
    inc.m_Lights.m_NumAlloced = 0;
    inc.m_Lights.m_pElements = nullptr;
    inc.m_FacesTouched.m_Memory.m_pMemory = nullptr;
    inc.m_FacesTouched.m_Memory.m_nAllocationCount = 0;
    inc.m_FacesTouched.m_Memory.m_nGrowSize = 0;
    inc.m_FacesTouched.m_Size = 0;
    inc.m_FacesTouched.m_pElements = nullptr;
    inc.m_TotalMemory = 0;
    inc.m_pIncrementalFilename = nullptr;
    inc.m_pBSPFilename = nullptr;
    inc.m_bSuccessfulRun = false;
    atexit(func: GetIncremental_::_2_::_dynamic_atexit_destructor_for__inc__);
  }
  return &inc;
}

//------------------------------------------------------------------------------
// Address: 0x10005B50
// Name: private: bool CIncremental::ReadIncrementalHeader(long,class CIncrementalHeader __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::ReadIncrementalHeader(CIncremental *this, int fp, CIncrementalHeader *pHeader)
{
  void *v3; // ebx
  CIncrementalHeader *v5; // esi
  CIncrementalHeader *v6; // ecx
  unsigned __int8 *p_m_Width; // edi
  unsigned int v8; // esi
  int v9; // [esp-8h] [ebp-14h]
  int version; // [esp+8h] [ebp-4h] BYREF

  v3 = (void *)fp;
  if ( g_bFileError || g_pFileSystem->Read(this: g_pFileSystem, a2: &version, a3: 4, a4: (void *)fp) != 4 )
  {
    g_bFileError = true;
    version = 0;
  }
  if ( version != 31241 )
    return false;
  if ( g_bFileError || g_pFileSystem->Read(this: g_pFileSystem, a2: &fp, a3: 4, a4: v3) != 4 )
  {
    g_bFileError = true;
    fp = 0;
  }
  v5 = pHeader;
  v9 = fp;
  v6 = pHeader;
  pHeader->m_FaceLightmapSizes.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: &v6->m_FaceLightmapSizes,
    elem: 0,
    num: v9);
  p_m_Width = &v5->m_FaceLightmapSizes.m_Memory.m_pMemory->m_Width;
  v8 = 2 * fp;
  if ( g_bFileError || g_pFileSystem->Read(this: g_pFileSystem, a2: p_m_Width, a3: 2 * fp, a4: v3) != v8 )
  {
    g_bFileError = true;
    memset(dst: p_m_Width, value: 0, count: v8);
  }
  return !g_bFileError;
}

//------------------------------------------------------------------------------
// Address: 0x10005C30
// Name: private: bool CIncremental::WriteIncrementalHeader(long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::WriteIncrementalHeader(CIncremental *this, void *fp)
{
  int v2; // edi
  CIncrementalHeader::CLMSize *m_pMemory; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  bool v7; // bl
  CIncrementalHeader hdr; // [esp+0h] [ebp-18h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v10 = 31241;
  if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: &v10, a3: 4, a4: fp) != 4 )
    g_bFileError = true;
  v2 = numfaces;
  v10 = numfaces;
  if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: &v10, a3: 4, a4: fp) != 4 )
    g_bFileError = true;
  memset(&hdr, 0, sizeof(hdr));
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: &hdr.m_FaceLightmapSizes,
    elem: 0,
    num: v2);
  m_pMemory = hdr.m_FaceLightmapSizes.m_Memory.m_pMemory;
  v4 = 0;
  if ( v2 > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory[v4].m_Width = g_pFaces[v5].m_LightmapTextureSizeInLuxels[0];
      m_pMemory[v4++].m_Height = g_pFaces[v5++].m_LightmapTextureSizeInLuxels[1];
    }
    while ( v4 < v2 );
  }
  v6 = 2 * v2;
  if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: m_pMemory, a3: v6, a4: fp) != v6 )
    g_bFileError = true;
  v7 = !g_bFileError;
  if ( hdr.m_FaceLightmapSizes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10005D50
// Name: private: bool CIncremental::IsIncrementalFileValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::IsIncrementalFileValid(CIncremental *this)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  int v3; // eax
  void *v4; // edi
  bool v6; // al
  CIncrementalHeader::CLMSize *m_pMemory; // esi
  int v8; // eax
  int *v9; // ecx
  bool v10; // bl
  bool v11; // bl
  const char *m_pIncrementalFilename; // [esp-Ch] [ebp-30h]
  CIncrementalHeader hdr; // [esp+Ch] [ebp-18h] BYREF
  bool bValid; // [esp+23h] [ebp-1h]

  m_pIncrementalFilename = this->m_pIncrementalFilename;
  Open = g_pFileSystem->Open;
  g_bFileError = false;
  v3 = (int)Open(this: g_pFileSystem, a2: m_pIncrementalFilename, a3: "rb", a4: nullptr);
  v4 = (void *)v3;
  if ( v3 == 0 )
    return false;
  bValid = false;
  memset(&hdr, 0, sizeof(hdr));
  v6 = CIncremental::ReadIncrementalHeader(this, fp: v3, pHeader: &hdr);
  m_pMemory = hdr.m_FaceLightmapSizes.m_Memory.m_pMemory;
  if ( !v6 || hdr.m_FaceLightmapSizes.m_Size != (_DWORD)numfaces )
    goto LABEL_11;
  v8 = 0;
  if ( (int)numfaces > 0 )
  {
    v9 = &g_pFaces->m_LightmapTextureSizeInLuxels[1];
    do
    {
      if ( hdr.m_FaceLightmapSizes.m_Memory.m_pMemory[v8].m_Width != *(v9 - 1) )
        break;
      if ( hdr.m_FaceLightmapSizes.m_Memory.m_pMemory[v8].m_Height != *v9 )
        break;
      ++v8;
      v9 += 14;
    }
    while ( v8 < (int)numfaces );
  }
  v10 = true;
  if ( v8 != (_DWORD)numfaces )
LABEL_11:
    v10 = bValid;
  g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
  v11 = v10 && !g_bFileError;
  if ( hdr.m_FaceLightmapSizes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10005E40
// Name: public: virtual void CIncremental::FinishFace(unsigned short,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIncremental::FinishFace(CIncremental *this, unsigned __int16 lightID, int iFace, int iThread)
{
  CIncLight *m_Element; // ebx
  CLightFace *v5; // esi
  float m_flMaxIntensity; // xmm0_4
  int i; // eax
  CLightValue *m_pMemory; // ecx
  float m_Dot; // xmm1_4
  float *p_m_Dot; // ecx
  unsigned __int16 lightIDa; // [esp+14h] [ebp+8h]

  m_Element = this->m_Lights.m_Memory.m_pMemory[lightID].m_Element;
  v5 = m_Element->m_pCachedFaces[iThread];
  if ( v5 != nullptr && v5->m_FaceIndex == iFace )
  {
    m_flMaxIntensity = m_Element->m_flMaxIntensity;
    for ( i = 0; i < v5->m_LightValues.m_Size; *p_m_Dot = m_Dot * m_flMaxIntensity )
    {
      m_pMemory = v5->m_LightValues.m_Memory.m_pMemory;
      m_Dot = m_pMemory[i].m_Dot;
      p_m_Dot = &m_pMemory[i++].m_Dot;
    }
    CUtlBuffer::SeekPut(this: &v5->m_CompressedData, type: SEEK_HEAD, offset: 0);
    CompressLightData(
      pValues: v5->m_LightValues.m_Memory.m_pMemory,
      nValues: v5->m_LightValues.m_Size,
      pBuf: &v5->m_CompressedData);
    if ( v5->m_CompressedData.m_Put != 0 )
    {
      CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_LightValues);
      this->m_FacesTouched.m_Memory.m_pMemory[v5->m_FaceIndex] = 1;
    }
    else
    {
      EnterCriticalSection(lpCriticalSection: &m_Element->m_CS);
      lightIDa = v5->m_LightFacesIndex;
      CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)&m_Element->m_LightFaces,
        elem: lightIDa);
      m_Element->m_LightFaces.m_Memory.m_pMemory[lightIDa].m_Next = m_Element->m_LightFaces.m_FirstFree;
      m_Element->m_LightFaces.m_FirstFree = lightIDa;
      CLightFace::`scalar deleting destructor'(this: v5, a2: 1u);
      LeaveCriticalSection(lpCriticalSection: &m_Element->m_CS);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F40
// Name: public: virtual void CIncremental::GetFacesTouched(class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIncremental::GetFacesTouched(
        CIncremental *this,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *touched)
{
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: touched,
    pArray: this->m_FacesTouched.m_Memory.m_pMemory,
    size: this->m_FacesTouched.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10005F60
// Name: private: bool CIncremental::SaveIncrementalFile(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::SaveIncrementalFile(CIncremental *this)
{
  CIncremental *v1; // esi
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  void *v3; // eax
  void *v4; // edi
  int m_Head; // eax
  int v7; // ebx
  CIncLight *v8; // eax
  int m_Next; // eax
  int v10; // ebx
  CLightFace *m_Element; // esi
  int m_Put; // edi
  CUtlBuffer *p_m_CompressedData; // esi
  unsigned __int8 UnsignedShort; // al
  const char *m_pIncrementalFilename; // [esp-Ch] [ebp-90h]
  _BYTE v16[100]; // [esp+8h] [ebp-7Ch] BYREF
  int v17; // [esp+6Ch] [ebp-18h]
  int m_ElementCount; // [esp+70h] [ebp-14h] BYREF
  CIncremental *v19; // [esp+74h] [ebp-10h]
  CIncLight *pLight; // [esp+78h] [ebp-Ch] BYREF
  int fp; // [esp+7Ch] [ebp-8h]
  unsigned __int8 v22[4]; // [esp+80h] [ebp-4h] BYREF

  v1 = this;
  m_pIncrementalFilename = this->m_pIncrementalFilename;
  Open = g_pFileSystem->Open;
  v19 = this;
  g_bFileError = false;
  v3 = Open(this: g_pFileSystem, a2: m_pIncrementalFilename, a3: "wb", a4: nullptr);
  v4 = v3;
  fp = (int)v3;
  if ( v3 == nullptr )
    return false;
  if ( !CIncremental::WriteIncrementalHeader(this: v1, fp: v3) )
  {
    g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
    return false;
  }
  pLight = (CIncLight *)v1->m_Lights.m_ElementCount;
  if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: &pLight, a3: 4, a4: v4) != 4 )
    g_bFileError = true;
  m_Head = v1->m_Lights.m_Head;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      v7 = 8 * (unsigned __int16)m_Head;
      v8 = *(CIncLight **)((char *)&v1->m_Lights.m_Memory.m_pMemory->m_Element + v7);
      v17 = v7;
      pLight = v8;
      qmemcpy(v16, &v8->m_Light, sizeof(v16));
      if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: v16, a3: 100, a4: (void *)fp) != 100 )
        g_bFileError = true;
      m_ElementCount = pLight->m_LightFaces.m_ElementCount;
      if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: &m_ElementCount, a3: 4, a4: (void *)fp) != 4 )
        g_bFileError = true;
      m_Next = pLight->m_LightFaces.m_Head;
      if ( m_Next != 0xFFFF )
      {
        do
        {
          v10 = (unsigned __int16)m_Next;
          m_Element = pLight->m_LightFaces.m_Memory.m_pMemory[v10].m_Element;
          m_ElementCount = m_Element->m_FaceIndex;
          if ( g_bFileError
            || g_pFileSystem->Write(this: g_pFileSystem, a2: &m_ElementCount, a3: 2, a4: (void *)fp) != 2 )
          {
            g_bFileError = true;
          }
          m_Put = m_Element->m_CompressedData.m_Put;
          m_ElementCount = m_Put;
          if ( g_bFileError
            || g_pFileSystem->Write(this: g_pFileSystem, a2: &m_ElementCount, a3: 4, a4: (void *)fp) != 4 )
          {
            g_bFileError = true;
          }
          p_m_CompressedData = &m_Element->m_CompressedData;
          CUtlBuffer::SeekGet(this: p_m_CompressedData, type: SEEK_HEAD, offset: 0);
          while ( m_Put != 0 )
          {
            --m_Put;
            if ( (p_m_CompressedData->m_Flags & 1) != 0 )
            {
              UnsignedShort = CUtlBuffer::GetUnsignedShort(this: p_m_CompressedData);
            }
            else if ( CUtlBuffer::CheckGet(this: p_m_CompressedData, nSize: 1) )
            {
              UnsignedShort = p_m_CompressedData->m_Memory.m_pMemory[p_m_CompressedData->m_Get++
                                                                   - p_m_CompressedData->m_nOffset];
            }
            else
            {
              UnsignedShort = 0;
            }
            v22[0] = UnsignedShort;
            if ( g_bFileError || g_pFileSystem->Write(this: g_pFileSystem, a2: v22, a3: 1, a4: (void *)fp) != 1 )
              g_bFileError = true;
          }
          m_Next = pLight->m_LightFaces.m_Memory.m_pMemory[v10].m_Next;
        }
        while ( m_Next != 0xFFFF );
        v7 = v17;
      }
      m_Head = *(unsigned __int16 *)((char *)&v19->m_Lights.m_Memory.m_pMemory->m_Next + v7);
      if ( m_Head == 0xFFFF )
        break;
      v1 = v19;
    }
    v4 = (void *)fp;
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
  return !g_bFileError;
}

//------------------------------------------------------------------------------
// Address: 0x100061F0
// Name: public: virtual bool CIncremental::Serialize(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::Serialize(CIncremental *this)
{
  bool result; // al

  result = CIncremental::SaveIncrementalFile(this);
  if ( result )
  {
    WriteBSPFile(filename: this->m_pBSPFilename, pUnused: nullptr);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006210
// Name: private: void CIncremental::AddLightsForActiveLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIncremental::AddLightsForActiveLights(CIncremental *this)
{
  directlight_t *v1; // ebx
  CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short> > *p_m_Lights; // edi
  void *v3; // esi
  int v4; // ecx
  int v5; // esi
  __int16 v6; // ax
  UtlLinkedListElem_t<CIncLight *,unsigned short> *m_pMemory; // eax
  int v8; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CIncLight *,unsigned short> *v10; // eax
  CIncLight **p_m_Element; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v14; // xmm3_4
  directlight_t *v15; // [esp+4h] [ebp-8h]
  CIncLight *pLight; // [esp+8h] [ebp-4h]

  v1 = activelights;
  v15 = activelights;
  if ( activelights != nullptr )
  {
    p_m_Lights = &this->m_Lights;
    do
    {
      v3 = MemAlloc_Alloc(nSize: 0xE0u);
      if ( v3 != nullptr )
      {
        *((_DWORD *)v3 + 48) = 0;
        *((_DWORD *)v3 + 49) = 0;
        *((_DWORD *)v3 + 50) = 0;
        *((_WORD *)v3 + 107) = -1;
        *((_WORD *)v3 + 106) = 0;
        *((_DWORD *)v3 + 52) = 0xFFFF;
        v4 = *((_DWORD *)v3 + 48);
        *((_DWORD *)v3 + 51) = -1;
        *((_DWORD *)v3 + 54) = v4;
        memset(dst: (unsigned __int8 *)v3 + 124, value: 0, count: 0x44u);
        InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)v3);
        pLight = (CIncLight *)v3;
      }
      else
      {
        pLight = nullptr;
      }
      v5 = (unsigned __int16)CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short>>::AllocInternal(
                               this: p_m_Lights,
                               multilist: false);
      v6 = -1;
      if ( (_WORD)v5 != 0xFFFF )
      {
        CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::Unlink(
          this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)p_m_Lights,
          elem: v5);
        m_pMemory = p_m_Lights->m_Memory.m_pMemory;
        v8 = v5;
        m_pMemory[v8].m_Next = -1;
        m_Tail = p_m_Lights->m_Tail;
        m_pMemory[v8].m_Previous = m_Tail;
        p_m_Lights->m_Tail = v5;
        if ( (_WORD)m_Tail == 0xFFFF )
          p_m_Lights->m_Head = v5;
        else
          p_m_Lights->m_Memory.m_pMemory[m_Tail].m_Next = v5;
        v10 = p_m_Lights->m_Memory.m_pMemory;
        ++p_m_Lights->m_ElementCount;
        p_m_Element = &v10[v8].m_Element;
        if ( p_m_Element != nullptr )
          *p_m_Element = pLight;
        v1 = v15;
        v6 = v5;
      }
      v1->m_IncrementalID = v6;
      dworldlight_t::operator=(this: &pLight->m_Light, __that: &v1->light);
      y = v1->light.intensity.y;
      z = v1->light.intensity.z;
      if ( y <= z )
        v14 = v1->light.intensity.z;
      else
        v14 = v1->light.intensity.y;
      if ( v1->light.intensity.x <= v14 )
      {
        if ( y <= z )
          y = v1->light.intensity.z;
      }
      else
      {
        y = v1->light.intensity.x;
      }
      pLight->m_flMaxIntensity = y;
      v1 = v1->next;
      v15 = v1;
    }
    while ( v1 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006380
// Name: public: class CLightFace __near * CIncLight::FindOrCreateLightFace(int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CLightFace *__thiscall CIncLight::FindOrCreateLightFace(CIncLight *this, int iFace, int lmSize, bool *bNew)
{
  CLightFace *v4; // ebx
  int m_Head; // eax
  UtlLinkedListElem_t<CLightFace *,unsigned short> *v7; // edx
  UtlLinkedListElem_t<CLightFace *,unsigned short> *v8; // ecx
  CLightFace *result; // eax
  CLightFace *v10; // eax
  CLightFace *v11; // esi
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *p_m_LightFaces; // esi
  unsigned __int16 v13; // ax
  int v14; // edi
  __int16 v15; // ax
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // eax
  int v17; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *v19; // esi
  bool v20; // zf
  CLightFace **v21; // esi
  int m_nAllocationCount; // eax
  CLightValue *v23; // ecx
  int v24; // eax
  CLightFace *pFace; // [esp+10h] [ebp-4h]

  v4 = nullptr;
  if ( bNew != nullptr )
    *bNew = false;
  m_Head = this->m_LightFaces.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_7:
    v10 = (CLightFace *)MemAlloc_Alloc(nSize: 0x4Cu);
    v11 = v10;
    if ( v10 != nullptr )
    {
      v10->m_LightValues.m_Memory.m_pMemory = nullptr;
      v10->m_LightValues.m_Memory.m_nAllocationCount = 0;
      v10->m_LightValues.m_Memory.m_nGrowSize = 0;
      v10->m_LightValues.m_Size = 0;
      v10->m_LightValues.m_pElements = nullptr;
      CUtlBuffer::CUtlBuffer(this: &v10->m_CompressedData, growSize: 0, initSize: 0, nFlags: 0);
      v4 = v11;
      pFace = v11;
    }
    else
    {
      pFace = nullptr;
    }
    p_m_LightFaces = (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)&this->m_LightFaces;
    v13 = CUtlLinkedList<CLightFace *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CLightFace *,unsigned short>,unsigned short>>::AllocInternal(
            this: &this->m_LightFaces,
            multilist: false);
    v14 = v13;
    if ( v13 == 0xFFFF )
    {
      v15 = -1;
    }
    else
    {
      CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::Unlink(
        this: p_m_LightFaces,
        elem: v13);
      m_pMemory = p_m_LightFaces->m_Memory.m_pMemory;
      v17 = v14;
      m_pMemory[v17].m_Next = -1;
      m_Tail = p_m_LightFaces->m_Tail;
      m_pMemory[v17].m_Previous = m_Tail;
      p_m_LightFaces->m_Tail = v14;
      if ( (_WORD)m_Tail == 0xFFFF )
        p_m_LightFaces->m_Head = v14;
      else
        p_m_LightFaces->m_Memory.m_pMemory[m_Tail].m_Next = v14;
      ++p_m_LightFaces->m_ElementCount;
      v19 = p_m_LightFaces->m_Memory.m_pMemory;
      v20 = &v19[v17] == nullptr;
      v21 = (CLightFace **)&v19[v17];
      v4 = pFace;
      if ( !v20 )
        *v21 = pFace;
      v15 = v14;
    }
    v4->m_LightFacesIndex = v15;
    v4->m_pLight = this;
    v4->m_FaceIndex = iFace;
    v4->m_LightValues.m_Size = 0;
    if ( lmSize != 0 )
    {
      m_nAllocationCount = v4->m_LightValues.m_Memory.m_nAllocationCount;
      if ( lmSize > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v4->m_LightValues, num: lmSize - m_nAllocationCount);
      v4->m_LightValues.m_Size += lmSize;
      v23 = v4->m_LightValues.m_Memory.m_pMemory;
      v24 = v4->m_LightValues.m_Size - lmSize;
      v4->m_LightValues.m_pElements = v23;
      if ( v24 > 0 && lmSize > 0 )
        _V_memmove(dest: &v23[lmSize], src: v23, count: 4 * v24);
    }
    memset(dst: (unsigned __int8 *)v4->m_LightValues.m_Memory.m_pMemory, value: 0, count: 4 * lmSize);
    if ( bNew != nullptr )
      *bNew = true;
    return v4;
  }
  else
  {
    v7 = this->m_LightFaces.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = &v7[(unsigned __int16)m_Head];
      result = v8->m_Element;
      if ( v8->m_Element->m_FaceIndex == iFace )
        break;
      m_Head = v8->m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006600
// Name: public: virtual void CIncremental::AddLightToFace(unsigned short,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIncremental::AddLightToFace(
        CIncremental *this,
        int lightID,
        int iFace,
        int iSample,
        int lmSize,
        float dot,
        int iThread)
{
  CIncLight *m_Element; // esi
  CLightFace *v9; // eax
  int v10; // edi
  CLightFace *LightFace; // edi
  bool v12; // zf

  if ( this->m_pIncrementalFilename != nullptr )
  {
    m_Element = this->m_Lights.m_Memory.m_pMemory[(unsigned __int16)lightID].m_Element;
    v9 = m_Element->m_pCachedFaces[iThread];
    v10 = iFace;
    if ( v9 != nullptr && v9->m_FaceIndex == iFace )
    {
      LightFace = m_Element->m_pCachedFaces[iThread];
    }
    else
    {
      EnterCriticalSection(lpCriticalSection: &m_Element->m_CS);
      LightFace = CIncLight::FindOrCreateLightFace(this: m_Element, iFace: v10, lmSize, bNew: (bool *)&lightID + 3);
      LeaveCriticalSection(lpCriticalSection: &m_Element->m_CS);
      v12 = HIBYTE(lightID) == 0;
      m_Element->m_pCachedFaces[iThread] = LightFace;
      if ( !v12 )
        this->m_TotalMemory += 4 * LightFace->m_LightValues.m_Size;
    }
    LightFace->m_LightValues.m_Memory.m_pMemory[iSample].m_Dot = dot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006680
// Name: private: bool CIncremental::LoadIncrementalFile(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncremental::LoadIncrementalFile(CIncremental *this)
{
  bool result; // al
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  int v4; // eax
  void *v5; // ebx
  CIncLight *v6; // eax
  CIncLight *v7; // ebx
  unsigned __int16 v8; // ax
  int v9; // esi
  UtlLinkedListElem_t<CIncLight *,unsigned short> *v10; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v13; // xmm3_4
  bool v14; // zf
  CLightFace *v15; // eax
  CLightFace *v16; // esi
  CLightFace *v17; // ebx
  CIncLight *v18; // esi
  unsigned __int16 v19; // ax
  int v20; // edi
  UtlLinkedListElem_t<CLightFace *,unsigned short> *v21; // eax
  void *v22; // esi
  CUtlBuffer *p_m_CompressedData; // esi
  unsigned __int8 v24; // al
  unsigned __int8 v25; // bl
  bool v26; // bl
  const char *m_pIncrementalFilename; // [esp-10h] [ebp-50h]
  CIncrementalHeader hdr; // [esp+8h] [ebp-38h] BYREF
  int iLight; // [esp+1Ch] [ebp-24h]
  int iFace; // [esp+20h] [ebp-20h]
  int nLights; // [esp+24h] [ebp-1Ch] BYREF
  int nFaces; // [esp+28h] [ebp-18h] BYREF
  CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short> > *p_m_Lights; // [esp+2Ch] [ebp-14h]
  CIncLight *pLight; // [esp+30h] [ebp-10h]
  int fp; // [esp+34h] [ebp-Ch]
  int dataSize; // [esp+38h] [ebp-8h] BYREF
  unsigned __int8 ucData; // [esp+3Fh] [ebp-1h] BYREF

  p_m_Lights = &this->m_Lights;
  CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &this->m_Lights);
  this->m_TotalMemory = 0;
  result = CIncremental::IsIncrementalFileValid(this);
  if ( result )
  {
    m_pIncrementalFilename = this->m_pIncrementalFilename;
    Open = g_pFileSystem->Open;
    g_bFileError = false;
    v4 = (int)Open(this: g_pFileSystem, a2: m_pIncrementalFilename, a3: "rb", a4: nullptr);
    v5 = (void *)v4;
    fp = v4;
    if ( v4 == 0 )
      return false;
    memset(&hdr, 0, sizeof(hdr));
    if ( !CIncremental::ReadIncrementalHeader(this, fp: v4, pHeader: &hdr) )
    {
      g_pFileSystem->Close(this: g_pFileSystem, a2: v5);
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hdr);
      return false;
    }
    if ( g_bFileError || g_pFileSystem->Read(this: g_pFileSystem, a2: &nLights, a3: 4, a4: v5) != 4 )
    {
      g_bFileError = true;
      nLights = 0;
    }
    iLight = 0;
    if ( nLights > 0 )
    {
      do
      {
        v6 = (CIncLight *)MemAlloc_Alloc(nSize: 0xE0u);
        if ( v6 != nullptr )
        {
          v7 = CIncLight::CIncLight(this: v6);
          pLight = v7;
        }
        else
        {
          pLight = nullptr;
          v7 = nullptr;
        }
        v8 = CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short>>::AllocInternal(
               this: p_m_Lights,
               multilist: false);
        v9 = v8;
        if ( v8 != 0xFFFF )
        {
          CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::LinkBefore(
            this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)p_m_Lights,
            before: 0xFFFFu,
            elem: v8);
          v10 = &p_m_Lights->m_Memory.m_pMemory[v9];
          if ( v10 != nullptr )
            v10->m_Element = v7;
        }
        if ( g_bFileError || g_pFileSystem->Read(this: g_pFileSystem, a2: &v7->m_Light, a3: 100, a4: (void *)fp) != 100 )
        {
          g_bFileError = true;
          memset(dst: (unsigned __int8 *)&v7->m_Light, value: 0, count: sizeof(v7->m_Light));
        }
        y = v7->m_Light.intensity.y;
        z = v7->m_Light.intensity.z;
        if ( y <= z )
          v13 = v7->m_Light.intensity.z;
        else
          v13 = v7->m_Light.intensity.y;
        if ( v7->m_Light.intensity.x <= v13 )
        {
          if ( y <= z )
            y = v7->m_Light.intensity.z;
        }
        else
        {
          y = v7->m_Light.intensity.x;
        }
        v14 = !g_bFileError;
        v7->m_flMaxIntensity = y;
        if ( !v14 || g_pFileSystem->Read(this: g_pFileSystem, a2: &nFaces, a3: 4, a4: (void *)fp) != 4 )
        {
          g_bFileError = true;
          nFaces = 0;
        }
        for ( iFace = 0; iFace < nFaces; ++iFace )
        {
          v15 = (CLightFace *)MemAlloc_Alloc(nSize: 0x4Cu);
          v16 = v15;
          if ( v15 != nullptr )
          {
            v15->m_LightValues.m_Memory.m_pMemory = nullptr;
            v15->m_LightValues.m_Memory.m_nAllocationCount = 0;
            v15->m_LightValues.m_Memory.m_nGrowSize = 0;
            v15->m_LightValues.m_Size = 0;
            v15->m_LightValues.m_pElements = nullptr;
            CUtlBuffer::CUtlBuffer(this: &v15->m_CompressedData, growSize: 0, initSize: 0, nFlags: 0);
            v17 = v16;
          }
          else
          {
            v17 = nullptr;
          }
          v18 = pLight;
          v19 = CUtlLinkedList<CLightFace *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CLightFace *,unsigned short>,unsigned short>>::AllocInternal(
                  this: &pLight->m_LightFaces,
                  multilist: false);
          v20 = v19;
          if ( v19 != 0xFFFF )
          {
            CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::LinkBefore(
              this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)&v18->m_LightFaces,
              before: 0xFFFFu,
              elem: v19);
            v21 = &v18->m_LightFaces.m_Memory.m_pMemory[v20];
            if ( v21 != nullptr )
              v21->m_Element = v17;
          }
          v14 = !g_bFileError;
          v17->m_pLight = pLight;
          if ( v14 && (v22 = (void *)fp, g_pFileSystem->Read(this: g_pFileSystem, a2: v17, a3: 2, a4: (void *)fp) == 2) )
          {
            if ( !g_bFileError && g_pFileSystem->Read(this: g_pFileSystem, a2: &dataSize, a3: 4, a4: v22) == 4 )
              goto LABEL_42;
          }
          else
          {
            v17->m_FaceIndex = 0;
          }
          g_bFileError = true;
          dataSize = 0;
LABEL_42:
          p_m_CompressedData = &v17->m_CompressedData;
          CUtlBuffer::SeekPut(this: &v17->m_CompressedData, type: SEEK_HEAD, offset: 0);
          while ( dataSize != 0 )
          {
            --dataSize;
            if ( !g_bFileError && g_pFileSystem->Read(this: g_pFileSystem, a2: &ucData, a3: 1, a4: (void *)fp) == 1 )
            {
              v24 = ucData;
            }
            else
            {
              v24 = 0;
              g_bFileError = true;
              ucData = 0;
            }
            if ( (p_m_CompressedData->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: p_m_CompressedData, pFmt: "%hu", v24);
            }
            else
            {
              v25 = v24;
              if ( CUtlBuffer::CheckPut(this: p_m_CompressedData, nSize: 1) )
              {
                p_m_CompressedData->m_Memory.m_pMemory[p_m_CompressedData->m_Put++ - p_m_CompressedData->m_nOffset] = v25;
                CUtlBuffer::AddNullTermination(this: p_m_CompressedData, nPut: p_m_CompressedData->m_Put);
              }
            }
          }
        }
        ++iLight;
      }
      while ( iLight < nLights );
      v5 = (void *)fp;
    }
    g_pFileSystem->Close(this: g_pFileSystem, a2: v5);
    v26 = !g_bFileError;
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&hdr);
    return v26;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006A10
// Name: public: virtual bool CIncremental::PrepareForLighting(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIncremental::PrepareForLighting(CIncremental *this)
{
  CIncremental *v1; // ebx
  bool v2; // zf
  int v4; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v7; // eax
  int m_Head; // edi
  int v9; // eax
  int v10; // esi
  UtlLinkedListElem_t<int,int> *v11; // eax
  int m_Tail; // ecx
  directlight_t *v13; // eax
  int m_Next; // esi
  dworldlight_t *p_light; // ecx
  UtlLinkedListElem_t<int,int> *v16; // edi
  UtlLinkedListElem_t<int,int> *v17; // edi
  UtlLinkedListElem_t<int,int> *v18; // eax
  int m_Previous; // ecx
  int v20; // ecx
  int v21; // edx
  directlight_t *next; // edx
  int i; // eax
  CIncLight *m_Element; // esi
  unsigned __int16 v25; // ax
  UtlLinkedListElem_t<CLightFace *,unsigned short> *v26; // ecx
  int v27; // eax
  unsigned __int16 v28; // si
  int v29; // eax
  UtlLinkedListElem_t<CIncLight *,unsigned short> *v30; // ecx
  int v31; // edx
  int v32; // edx
  directlight_t **v33; // edx
  directlight_t *v34; // [esp-Ch] [ebp-48h]
  CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > unmatched; // [esp+4h] [ebp-38h] BYREF
  CIncremental *v36; // [esp+2Ch] [ebp-10h]
  directlight_t *pNext; // [esp+30h] [ebp-Ch]
  directlight_t **pPrev; // [esp+34h] [ebp-8h]
  directlight_t *v39; // [esp+38h] [ebp-4h]

  v1 = this;
  v2 = this->m_pBSPFilename == nullptr;
  v36 = this;
  if ( v2 )
    return 0;
  v4 = numfaces;
  this->m_FacesTouched.m_Size = 0;
  if ( v4 != 0 )
  {
    m_nAllocationCount = this->m_FacesTouched.m_Memory.m_nAllocationCount;
    if ( v4 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_FacesTouched.m_Memory, num: v4 - m_nAllocationCount);
    v1->m_FacesTouched.m_Size += v4;
    m_pMemory = v1->m_FacesTouched.m_Memory.m_pMemory;
    v7 = v1->m_FacesTouched.m_Size - v4;
    v1->m_FacesTouched.m_pElements = m_pMemory;
    if ( v7 > 0 && v4 > 0 )
      _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: v7);
  }
  memset(dst: v1->m_FacesTouched.m_Memory.m_pMemory, value: 0, count: numfaces);
  if ( !v1->m_bSuccessfulRun )
    CIncremental::LoadIncrementalFile(this: v1);
  m_Head = v1->m_Lights.m_Head;
  memset(&unmatched, 0, 12);
  unmatched.m_LastAlloc.index = -1;
  memset(&unmatched.m_Head, 255, 12);
  unmatched.m_ElementCount = 0;
  unmatched.m_NumAlloced = 0;
  for ( unmatched.m_pElements = nullptr;
        m_Head != 0xFFFF;
        m_Head = v1->m_Lights.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next )
  {
    v9 = CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
           this: &unmatched,
           multilist: false);
    v10 = v9;
    if ( v9 != -1 )
    {
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&unmatched,
        elem: v9);
      v11 = &unmatched.m_Memory.m_pMemory[v10];
      m_Tail = unmatched.m_Tail;
      v11->m_Next = -1;
      v11->m_Previous = m_Tail;
      unmatched.m_Tail = v10;
      if ( m_Tail == -1 )
        unmatched.m_Head = v10;
      else
        unmatched.m_Memory.m_pMemory[m_Tail].m_Next = v10;
      ++unmatched.m_ElementCount;
      if ( v11 != nullptr )
        v11->m_Element = m_Head;
    }
  }
  v13 = activelights;
  pPrev = &activelights;
  v39 = activelights;
  if ( activelights != nullptr )
  {
    while ( 1 )
    {
      m_Next = unmatched.m_Head;
      pNext = v13->next;
      if ( unmatched.m_Head == -1 )
      {
LABEL_41:
        pPrev = &v13->next;
      }
      else
      {
        p_light = &v13->light;
        while ( 1 )
        {
          v16 = &unmatched.m_Memory.m_pMemory[m_Next];
          if ( CompareLights(a: p_light, b: &v1->m_Lights.m_Memory.m_pMemory[LOWORD(v16->m_Element)].m_Element->m_Light) )
            break;
          m_Next = v16->m_Next;
          if ( m_Next == -1 )
            goto LABEL_40;
        }
        if ( m_Next < 0 || m_Next >= unmatched.m_Memory.m_nAllocationCount || m_Next > unmatched.m_LastAlloc.index )
        {
          v17 = unmatched.m_Memory.m_pMemory;
        }
        else
        {
          v17 = unmatched.m_Memory.m_pMemory;
          v18 = &unmatched.m_Memory.m_pMemory[m_Next];
          if ( v18->m_Previous != m_Next )
          {
            m_Previous = v18->m_Previous;
            if ( m_Previous == -1 )
              unmatched.m_Head = v18->m_Next;
            else
              unmatched.m_Memory.m_pMemory[m_Previous].m_Next = v18->m_Next;
            v20 = v18->m_Next;
            if ( v20 == -1 )
            {
              v21 = v18->m_Previous;
              --unmatched.m_ElementCount;
              unmatched.m_Tail = v21;
            }
            else
            {
              --unmatched.m_ElementCount;
              v17[v20].m_Previous = v18->m_Previous;
            }
            v18->m_Next = m_Next;
            v18->m_Previous = m_Next;
          }
        }
        v17[m_Next].m_Next = unmatched.m_FirstFree;
        next = v39->next;
        v34 = v39;
        unmatched.m_FirstFree = m_Next;
        *pPrev = next;
        free(pMem: v34);
        v39 = nullptr;
        if ( m_Next == -1 )
        {
LABEL_40:
          v13 = v39;
          goto LABEL_41;
        }
      }
      v39 = pNext;
      if ( pNext == nullptr )
        break;
      v13 = v39;
    }
  }
  for ( i = unmatched.m_Head; i != -1; i = (int)v33[2] )
  {
    m_Element = v1->m_Lights.m_Memory.m_pMemory[LOWORD(unmatched.m_Memory.m_pMemory[i].m_Element)].m_Element;
    pPrev = (directlight_t **)&unmatched.m_Memory.m_pMemory[i];
    v25 = m_Element->m_LightFaces.m_Head;
    if ( v25 != 0xFFFF )
    {
      v26 = m_Element->m_LightFaces.m_Memory.m_pMemory;
      do
      {
        v27 = v25;
        v1->m_FacesTouched.m_Memory.m_pMemory[v26[v27].m_Element->m_FaceIndex] = 1;
        v26 = m_Element->m_LightFaces.m_Memory.m_pMemory;
        v25 = v26[v27].m_Next;
      }
      while ( v25 != 0xFFFF );
    }
    CUtlLinkedList<CLightFace *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CLightFace *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &m_Element->m_LightFaces);
    DeleteCriticalSection(lpCriticalSection: &m_Element->m_CS);
    CUtlLinkedList<CIncLight *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)&m_Element->m_LightFaces);
    if ( m_Element->m_LightFaces.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_Element->m_LightFaces.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_LightFaces.m_Memory.m_pMemory);
        m_Element->m_LightFaces.m_Memory.m_pMemory = nullptr;
      }
      m_Element->m_LightFaces.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_Element);
    v28 = *(_WORD *)pPrev;
    v29 = *(unsigned __int16 *)pPrev;
    if ( v29 < v1->m_Lights.m_Memory.m_nAllocationCount && v28 <= v1->m_Lights.m_LastAlloc.index )
    {
      v30 = v1->m_Lights.m_Memory.m_pMemory;
      if ( v30[v29].m_Previous != v28 )
      {
        v31 = v30[v29].m_Previous;
        if ( (_WORD)v31 == 0xFFFF )
          v1->m_Lights.m_Head = v30[v29].m_Next;
        else
          v30[v31].m_Next = v30[v29].m_Next;
        v32 = v30[v29].m_Next;
        if ( (_WORD)v32 == 0xFFFF )
        {
          v1->m_Lights.m_Tail = v30[v29].m_Previous;
        }
        else
        {
          v1->m_Lights.m_Memory.m_pMemory[v32].m_Previous = v30[v29].m_Previous;
          v1 = v36;
        }
        v30[v29].m_Next = v28;
        v30[v29].m_Previous = v28;
        --v1->m_Lights.m_ElementCount;
      }
    }
    v1->m_Lights.m_Memory.m_pMemory[v29].m_Next = v1->m_Lights.m_FirstFree;
    v33 = pPrev;
    v1->m_Lights.m_FirstFree = v28;
  }
  CIncremental::AddLightsForActiveLights(this: v1);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&unmatched);
  if ( unmatched.m_Memory.m_nGrowSize >= 0 && unmatched.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: unmatched.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006DF0
// Name: private: void CIncremental::LinkLightsToFaces(class CUtlVector<class CUtlVector<class CLightFace __near *,class CUtlMemory<class CLightFace __near *,int>>,class CUtlMemory<class CUtlVector<class CLightFace __near *,class CUtlMemory<class CLightFace __near *,int>>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIncremental::LinkLightsToFaces(
        CIncremental *this,
        CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *faceLights)
{
  CIncremental *v2; // esi
  int v3; // edi
  int i; // eax
  int v5; // ecx
  CIncLight *v6; // edx
  int m_Head; // eax
  int v8; // ebx
  int m_FaceIndex; // eax
  int v10; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v12; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  S3RGBA *v16; // ecx
  CLightFace **v17; // edi
  int v18; // [esp+Ch] [ebp-10h]
  CLightFace *pFace; // [esp+10h] [ebp-Ch]
  CIncLight *pLight; // [esp+18h] [ebp-4h]

  v2 = this;
  v3 = numfaces;
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll(this: faceLights);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
    this: faceLights,
    elem: faceLights->m_Size,
    num: v3);
  for ( i = v2->m_Lights.m_Head;
        i != 0xFFFF;
        i = *(unsigned __int16 *)((char *)&v2->m_Lights.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 8 * (unsigned __int16)i;
    v6 = *(CIncLight **)((char *)&v2->m_Lights.m_Memory.m_pMemory->m_Element + v5);
    m_Head = v6->m_LightFaces.m_Head;
    v18 = v5;
    pLight = v6;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v8 = (unsigned __int16)m_Head;
        pFace = v6->m_LightFaces.m_Memory.m_pMemory[v8].m_Element;
        m_FaceIndex = pFace->m_FaceIndex;
        if ( v2->m_FacesTouched.m_Memory.m_pMemory[m_FaceIndex] != 0 )
        {
          v10 = m_FaceIndex;
          m_Size = faceLights->m_Memory.m_pMemory[v10].m_Size;
          v12 = (CUtlMemory<S3RGBA,int> *)&faceLights->m_Memory.m_pMemory[v10];
          m_nAllocationCount = v12->m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(this: v12, num: m_Size - m_nAllocationCount + 1);
            v6 = pLight;
          }
          ++v12[1].m_pMemory;
          m_pMemory = v12->m_pMemory;
          v15 = (int)v12[1].m_pMemory - m_Size - 1;
          v12[1].m_nAllocationCount = (int)v12->m_pMemory;
          if ( v15 > 0 )
          {
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
            v6 = pLight;
          }
          v16 = v12->m_pMemory;
          v2 = this;
          v17 = (CLightFace **)&v16[m_Size];
          if ( v17 != nullptr )
            *v17 = pFace;
        }
        m_Head = v6->m_LightFaces.m_Memory.m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
      v5 = v18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F20
// Name: public: virtual bool CIncremental::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIncremental::Finalize(CIncremental *this)
{
  CIncremental *v1; // esi
  int v2; // ebx
  int v3; // ecx
  int v4; // eax
  dface_t *v5; // esi
  int v6; // edi
  int v7; // edi
  int v8; // edx
  CLightValue *v9; // esi
  unsigned int v10; // edx
  float *v11; // ecx
  float m_Dot; // xmm0_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm0_4
  float *v16; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float *v21; // eax
  float v22; // xmm0_4
  float *v23; // ecx
  float v24; // xmm0_4
  float *v25; // eax
  float v26; // xmm0_4
  ColorRGBExp32 *v27; // esi
  unsigned __int8 *v28; // ebx
  unsigned __int8 dst[8]; // [esp+8h] [ebp-2F44Ch] BYREF
  _DWORD v31[48385]; // [esp+10h] [ebp-2F444h] BYREF
  CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > faceLights; // [esp+2F414h] [ebp-40h] BYREF
  CUtlVector<CLightValue,CUtlMemory<CLightValue,int> > v33; // [esp+2F428h] [ebp-2Ch] BYREF
  int v34; // [esp+2F43Ch] [ebp-18h]
  CIncremental *v35; // [esp+2F440h] [ebp-14h]
  unsigned int v36; // [esp+2F444h] [ebp-10h]
  int v37; // [esp+2F448h] [ebp-Ch]
  int v38; // [esp+2F44Ch] [ebp-8h]
  int *p_m_Size; // [esp+2F450h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v35 = this;
  if ( this->m_pIncrementalFilename == nullptr || this->m_pBSPFilename == nullptr )
    return 0;
  memset(&faceLights, 0, sizeof(faceLights));
  CIncremental::LinkLightsToFaces(this, &faceLights);
  memset(&v33, 0, sizeof(v33));
  CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v33, num: 16129);
  v33.m_Size += 16129;
  v33.m_pElements = v33.m_Memory.m_pMemory;
  if ( v33.m_Size - 16129 > 0 )
    _V_memmove(dest: &v33.m_Memory.m_pMemory[16129], src: v33.m_Memory.m_pMemory, count: 4 * (v33.m_Size - 16129));
  v3 = 0;
  v34 = 0;
  if ( (int)numfaces > 0 )
  {
    v4 = 0;
    v36 = 0;
    p_m_Size = &faceLights.m_Memory.m_pMemory->m_Size;
    do
    {
      if ( v1->m_FacesTouched.m_Memory.m_pMemory[v3] != 0 && *p_m_Size != 0 )
      {
        v5 = g_pFaces;
        v38 = (*(int *)((char *)g_pFaces->m_LightmapTextureSizeInLuxels + v4) + 1)
            * (*(int *)((char *)&g_pFaces->m_LightmapTextureSizeInLuxels[1] + v4) + 1);
        v6 = v38;
        memset(dst, value: 0, count: 12 * v38);
        v37 = 0;
        if ( *p_m_Size > 0 )
        {
          while ( 1 )
          {
            v7 = *(_DWORD *)(*(p_m_Size - 3) + 4 * v37);
            CUtlBuffer::SeekGet(this: (CUtlBuffer *)(v7 + 24), type: SEEK_HEAD, offset: 0);
            DecompressLightData(pIn: (CUtlBuffer *)(v7 + 24), pOut: &v33);
            v8 = v38;
            if ( v38 >= 4 )
            {
              v9 = v33.m_Memory.m_pMemory + 2;
              v10 = ((unsigned int)(v38 - 4) >> 2) + 1;
              v11 = (float *)v31;
              v2 = 4 * v10;
              do
              {
                m_Dot = v9[-2].m_Dot;
                if ( m_Dot != 0.0 )
                {
                  v13 = *(float **)(v7 + 72);
                  v14 = m_Dot / v13[55];
                  *(v11 - 2) = (float)(v13[9] * v14) + *(v11 - 2);
                  *(v11 - 1) = (float)(v13[10] * v14) + *(v11 - 1);
                  *v11 = (float)(v13[11] * v14) + *v11;
                }
                v15 = v9[-1].m_Dot;
                if ( v15 != 0.0 )
                {
                  v16 = *(float **)(v7 + 72);
                  v17 = v15 / v16[55];
                  v11[1] = (float)(v16[9] * v17) + v11[1];
                  v11[2] = (float)(v16[10] * v17) + v11[2];
                  v11[3] = (float)(v16[11] * v17) + v11[3];
                }
                if ( v9->m_Dot != 0.0 )
                {
                  v18 = *(float **)(v7 + 72);
                  v19 = v9->m_Dot / v18[55];
                  v11[4] = (float)(v18[9] * v19) + v11[4];
                  v11[5] = (float)(v18[10] * v19) + v11[5];
                  v11[6] = (float)(v18[11] * v19) + v11[6];
                }
                v20 = v9[1].m_Dot;
                if ( v20 != 0.0 )
                {
                  v21 = *(float **)(v7 + 72);
                  v22 = v20 / v21[55];
                  v11[7] = (float)(v21[9] * v22) + v11[7];
                  v11[8] = (float)(v21[10] * v22) + v11[8];
                  v11[9] = (float)(v21[11] * v22) + v11[9];
                }
                v9 += 4;
                v11 += 12;
                --v10;
              }
              while ( v10 != 0 );
              v8 = v38;
            }
            if ( v2 < v8 )
            {
              v23 = (float *)&v31[3 * v2];
              do
              {
                v24 = v33.m_Memory.m_pMemory[v2].m_Dot;
                if ( v24 != 0.0 )
                {
                  v25 = *(float **)(v7 + 72);
                  v26 = v24 / v25[55];
                  *(v23 - 2) = (float)(v25[9] * v26) + *(v23 - 2);
                  *(v23 - 1) = (float)(v25[10] * v26) + *(v23 - 1);
                  *v23 = (float)(v25[11] * v26) + *v23;
                }
                ++v2;
                v23 += 3;
              }
              while ( v2 < v38 );
            }
            if ( ++v37 >= *p_m_Size )
              break;
            v2 = 0;
          }
          v6 = v38;
          v5 = g_pFaces;
        }
        v27 = (ColorRGBExp32 *)&pdlightdata->m_Memory.m_pMemory[v5[v36 / 0x38].lightofs];
        v28 = dst;
        if ( v6 > 0 )
        {
          do
          {
            VectorToColorRGBExp32(vin: (const Vector *)v28, c: v27++);
            v28 += 12;
            --v6;
          }
          while ( v6 != 0 );
        }
        v1 = v35;
        v2 = 0;
      }
      p_m_Size += 5;
      v3 = v34 + 1;
      v4 = v36 + 56;
      v34 = v3;
      v36 += 56;
    }
    while ( v3 < (int)numfaces );
  }
  v1->m_bSuccessfulRun = true;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v33);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll(this: &faceLights);
  if ( faceLights.m_Memory.m_nGrowSize >= 0 && faceLights.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceLights.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100370C0
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
