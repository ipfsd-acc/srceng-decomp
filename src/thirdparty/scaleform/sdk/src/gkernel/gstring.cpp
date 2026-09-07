// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gstring.cpp
// Functions: 53
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gstring.h"

//------------------------------------------------------------------------------
// Address: 0x100730C0
// Name: public: unsigned int GString::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GString::GetLength(GString *this)
{
  unsigned int v1; // esi
  int v2; // edi
  int result; // eax

  v1 = this->HeapTypeBits & 0xFFFFFFFC;
  v2 = *(_DWORD *)v1 & 0x7FFFFFFF;
  if ( *(int *)v1 < 0 )
    return *(_DWORD *)v1 & 0x7FFFFFFF;
  result = GUTF8Util::GetLength(length: (const char *)(v1 + 8), buflen: *(_DWORD *)v1 & 0x7FFFFFFF);
  if ( result == v2 )
    *(_DWORD *)v1 |= 0x80000000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073100
// Name: public: unsigned long GString::GetCharAt(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GString::GetCharAt(
        GString *this,
        CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer)
{
  int *v2; // eax
  int m_LessFunc; // esi
  unsigned int result; // eax

  v2 = (int *)(this->HeapTypeBits & 0xFFFFFFFC);
  m_LessFunc = (int)putf8Buffer.m_LessFunc;
  putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))(v2 + 2);
  if ( *v2 >= 0 )
  {
    while ( 1 )
    {
      result = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
      --m_LessFunc;
      if ( result == 0 )
        break;
      if ( m_LessFunc < 0 )
        return result;
    }
    return 0;
  }
  else
  {
    putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)putf8Buffer.m_LessFunc
                                                                                        + m_LessFunc);
    return GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073150
// Name: public: unsigned long GString::GetFirstCharAt(unsigned int,char const __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GString::GetFirstCharAt(
        CUtlMemory<CImagePacker,int> *this,
        const CUtlMemory<CImagePacker,int>::Iterator_t *index,
        CUtlMap<char const *,int,unsigned short>::CKeyLess offset)
{
  const CUtlMemory<CImagePacker,int>::Iterator_t *v3; // esi
  unsigned int result; // eax

  v3 = index;
  index = (const CUtlMemory<CImagePacker,int>::Iterator_t *)(((int)this->m_pMemory & 0xFFFFFFFC) + 8);
  while ( 1 )
  {
    result = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&index);
    v3 = (const CUtlMemory<CImagePacker,int>::Iterator_t *)((char *)v3 - 1);
    if ( result == 0 )
      break;
    if ( (int)v3 < 0 )
    {
      *(_DWORD *)offset.m_LessFunc = index;
      return result;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10073190
// Name: public: unsigned long GString::GetNextChar(char const __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const CImagePacker *__thiscall GString::GetNextChar(
        CUtlMemory<CImagePacker,int> *this,
        CUtlMap<char const *,int,unsigned short>::CKeyLess offset)
{
  return (const CImagePacker *)GUTF8Util::DecodeNextChar(putf8Buffer: offset);
}

//------------------------------------------------------------------------------
// Address: 0x100731A0
// Name: public: static int GString::CompareNoCase(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall GString::CompareNoCase(char *a1, char *a2)
{
  return G_stricmp(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100731C0
// Name: public: static int GString::CompareNoCase(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __stdcall GString::CompareNoCase(const char *a1, const char *a2, int a3)
{
  int v3; // ecx
  const char *v4; // esi
  int v6; // edx
  int v7; // eax
  int v8; // edx

  v3 = a3;
  if ( a3 == 0 )
    return -strlen(a2);
  v4 = a2;
  do
  {
    v6 = *a1;
    v7 = v6 + 32;
    if ( (unsigned int)(v6 - 65) > 0x19 )
      v7 = *a1;
    v8 = *v4;
    ++a1;
    if ( (unsigned int)(v8 - 65) <= 0x19 )
      v8 += 32;
    ++v4;
    if ( --v3 == 0 || v7 == 0 )
      break;
    if ( v7 != v8 )
      return v7 - v8;
  }
  while ( *v4 != 0 );
  if ( v7 == v8 && (v3 != 0 || *v4 != 0) )
    return a3 - strlen(a2);
  return v7 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x10073260
// Name: public: static unsigned int GString::BernsteinHashFunction(void const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GString::BernsteinHashFunction(
        const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        unsigned int size,
        const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *seed)
{
  unsigned int v3; // ecx
  int i; // eax
  int v5; // esi

  v3 = size;
  for ( i = (int)seed; v3 != 0; i = v5 ^ (33 * i) )
    v5 = *((unsigned __int8 *)result + --v3);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10073290
// Name: public: static unsigned int GString::BernsteinHashFunctionCIS(void const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GString::BernsteinHashFunctionCIS(
        const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        unsigned int size,
        const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *seed)
{
  unsigned int v3; // edx
  int i; // eax
  int v5; // ecx

  v3 = size;
  for ( i = (int)seed; v3 != 0; i = v5 ^ (33 * i) )
  {
    v5 = *((unsigned __int8 *)result + --v3);
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x100732D0
// Name: public: GStringBuffer::GStringBuffer(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *__thiscall GStringBuffer::GStringBuffer(
        _DWORD *this,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *result)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  *((_BYTE *)this + 16) = 0;
  *(this + 3) = 512;
  *(this + 5) = result;
  return (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10073300
// Name: public: GStringBuffer::~GStringBuffer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GStringBuffer::~GStringBuffer(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *this)
{
  int m_pfnProxied; // eax

  m_pfnProxied = this->m_pfnProxied;
  if ( LODWORD(this->m_pfnProxied) != 0 )
    LOBYTE(m_pfnProxied) = ((bool (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                             a1: GMemory::pGlobalHeap,
                             a2: m_pfnProxied);
  return m_pfnProxied;
}

//------------------------------------------------------------------------------
// Address: 0x10073320
// Name: public: unsigned int GStringBuffer::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *__thiscall GStringBuffer::GetLength(
        int this)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *Length; // eax

  Length = *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> **)(this + 4);
  if ( *(_BYTE *)(this + 16) == 0 )
  {
    Length = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GUTF8Util::GetLength(length: *(const char **)this, buflen: *(_DWORD *)(this + 4));
    if ( Length == *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> **)(this + 4) )
      *(_BYTE *)(this + 16) = 1;
  }
  return Length;
}

//------------------------------------------------------------------------------
// Address: 0x10073340
// Name: public: void GStringBuffer::Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringBuffer::Reserve(GStringBuffer *this, unsigned int a2)
{
  char *pData; // edx
  unsigned int v4; // eax
  GMemoryHeap *pHeap; // ecx

  if ( a2 >= this->BufferSize )
  {
    pData = this->pData;
    v4 = ~(this->GrowSize - 1) & (this->GrowSize + a2);
    this->BufferSize = v4;
    if ( pData != nullptr )
    {
      this->pData = (char *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: pData, a3: v4);
    }
    else
    {
      pHeap = this->pHeap;
      a2 = 5;
      this->pData = (char *)pHeap->Alloc_2(this: pHeap, a2: v4, a3: (const GAllocDebugInfo *)&a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100733A0
// Name: public: void GStringBuffer::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringBuffer::Resize(GStringBuffer *this, unsigned int a2)
{
  unsigned int v2; // edi
  char *pData; // edx
  unsigned int v5; // eax
  GMemoryHeap *pHeap; // ecx
  char *v7; // eax
  char *v8; // esi

  v2 = a2;
  if ( a2 >= this->BufferSize )
  {
    pData = this->pData;
    v5 = ~(this->GrowSize - 1) & (this->GrowSize + a2);
    this->BufferSize = v5;
    if ( pData != nullptr )
    {
      v7 = (char *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: pData, a3: v5);
    }
    else
    {
      pHeap = this->pHeap;
      a2 = 5;
      v7 = (char *)pHeap->Alloc_2(this: pHeap, a2: v5, a3: (const GAllocDebugInfo *)&a2);
    }
    this->pData = v7;
  }
  this->LengthIsSize = false;
  this->Size = v2;
  v8 = this->pData;
  if ( v8 != nullptr )
    v8[v2] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10073410
// Name: public: void GStringBuffer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringBuffer::Clear(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *this)
{
  void *m_pfnProxied; // edx
  unsigned int v3; // eax
  int v4; // ecx
  void *v5; // eax
  _BYTE *v6; // esi
  int v7; // [esp+4h] [ebp-4h] BYREF

  if ( DWORD2(this->m_pfnProxied) == 0 )
  {
    m_pfnProxied = (void *)this->m_pfnProxied;
    v3 = HIDWORD(this->m_pfnProxied) & ~(HIDWORD(this->m_pfnProxied) - 1);
    DWORD2(this->m_pfnProxied) = v3;
    if ( m_pfnProxied != nullptr )
    {
      v5 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: m_pfnProxied, a3: v3);
    }
    else
    {
      v4 = *((_DWORD *)&this->m_pObject + 1);
      v7 = 5;
      v5 = (void *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v4 + 40))(a1: v4, a2: v3, a3: &v7);
    }
    LODWORD(this->m_pfnProxied) = v5;
  }
  LOBYTE(this->m_pObject) = 0;
  DWORD1(this->m_pfnProxied) = 0;
  v6 = (_BYTE *)this->m_pfnProxied;
  if ( v6 != nullptr )
    *v6 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10073480
// Name: public: void GStringBuffer::AppendChar(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GStringBuffer::AppendChar(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *ch,
        __int128 srcSize)
{
  int v4; // edi
  int srcSizea; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 src[8]; // [esp+Ch] [ebp-Ch] BYREF

  v4 = DWORD1(this->m_pfnProxied);
  srcSizea = 0;
  GUTF8Util::EncodeChar(a1: (char *)src, a2: &srcSizea, a3: (unsigned int)ch);
  GStringBuffer::Resize((GStringBuffer *)this, a2: v4 + srcSizea);
  memcpy(dst: (unsigned __int8 *)(v4 + LODWORD(this->m_pfnProxied)), src, count: srcSizea);
}

//------------------------------------------------------------------------------
// Address: 0x100734F0
// Name: public: void GStringBuffer::AppendString(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringBuffer::AppendString(GStringBuffer *this, RGB888_t *a2, int a3)
{
  RGB888_t *EncodeStringSize; // eax
  unsigned int Size; // edi

  if ( a2 != nullptr )
  {
    EncodeStringSize = GUTF8Util::GetEncodeStringSize(retstr: a2);
    Size = this->Size;
    GStringBuffer::Resize(this, a2: (unsigned int)EncodeStringSize + Size);
    GUTF8Util::EncodeString(a1: &this->pData[Size], a2: (const wchar_t *)&a2->r, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073530
// Name: public: void GStringBuffer::AppendString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringBuffer::AppendString(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *this,
        char *putf8str,
        int utf8StrSz)
{
  unsigned int v4; // esi
  int v5; // edi

  if ( putf8str != nullptr )
  {
    v4 = utf8StrSz;
    if ( utf8StrSz != 0 )
    {
      if ( utf8StrSz == -1 )
        v4 = strlen(putf8str);
      v5 = DWORD1(this->m_pfnProxied);
      GStringBuffer::Resize((GStringBuffer *)this, a2: v5 + v4);
      memcpy(dst: (unsigned __int8 *)(v5 + LODWORD(this->m_pfnProxied)), src: (unsigned __int8 *)putf8str, count: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073590
// Name: public: void GStringBuffer::Insert(char const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncFile_t__ __thiscall GStringBuffer::Insert(
        int this,
        unsigned __int8 *src,
        unsigned int byteIndex,
        signed int insertSize)
{
  unsigned int v4; // eax
  int v6; // ebx
  int v8; // edi
  void *v9; // edx
  unsigned int v10; // eax
  int v11; // ecx
  void *v12; // eax
  FSAsyncFile_t__ result; // eax
  int v14; // [esp+Ch] [ebp-4h] BYREF
  unsigned int byteIndexa; // [esp+1Ch] [ebp+Ch]
  unsigned int insertSizea; // [esp+20h] [ebp+10h]

  v4 = insertSize;
  v6 = *(_DWORD *)(this + 4);
  if ( insertSize < 0 )
    v4 = strlen((const char *)src);
  insertSizea = v4;
  if ( *(_BYTE *)(this + 16) == 0 )
    byteIndex = GUTF8Util::GetByteIndex();
  v8 = v6 + insertSizea;
  byteIndexa = byteIndex;
  if ( v6 + insertSizea >= *(_DWORD *)(this + 8) )
  {
    v9 = *(void **)this;
    v10 = ~(*(_DWORD *)(this + 12) - 1) & (*(_DWORD *)(this + 12) + v8);
    *(_DWORD *)(this + 8) = v10;
    if ( v9 != nullptr )
    {
      v12 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v9, a3: v10);
    }
    else
    {
      v11 = *(_DWORD *)(this + 20);
      v14 = 5;
      v12 = (void *)(*(int (__thiscall **)(_DWORD, unsigned int, int *))(*(_DWORD *)v11 + 40))(
                      a1: *(_DWORD *)(this + 20),
                      a2: v10,
                      a3: &v14);
    }
    *(_DWORD *)this = v12;
  }
  memmove(
    dst: (unsigned __int8 *)(insertSizea + byteIndexa + *(_DWORD *)this),
    src: (unsigned __int8 *)(byteIndexa + *(_DWORD *)this),
    count: v6 - byteIndexa + 1);
  memcpy(dst: (unsigned __int8 *)(byteIndexa + *(_DWORD *)this), src, count: insertSizea);
  result.unused = *(_DWORD *)this;
  *(_DWORD *)(this + 4) = v8;
  *(_BYTE *)(this + 16) = 0;
  *(_BYTE *)(v8 + result.unused) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073670
// Name: public: GString::GString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::GString(CUtlMemory<CImagePacker,int> *this)
{
  this->m_pMemory = (CImagePacker *)&GString::NullData;
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10073690
// Name: protected: struct GString::DataDesc __near * GString::AllocDataCopy1(class GMemoryHeap __near *,unsigned int,unsigned int,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall GString::AllocDataCopy1(
        CCountedStringPoolBase<unsigned int> *this,
        CUtlBuffer *pheap,
        unsigned int size,
        unsigned int lengthIsSize,
        unsigned __int8 *src,
        unsigned int copySize)
{
  unsigned int v6; // esi
  VertexShaderHandle_t__ *v7; // esi
  int (__thiscall *v8)(CUtlBuffer *, unsigned int, unsigned int *); // eax
  VertexShaderHandle_t__ *v9; // eax
  unsigned int v10; // esi
  unsigned int v12; // [esp-8h] [ebp-Ch]

  v6 = size;
  if ( size != 0 )
  {
    v8 = *((int (__thiscall **)(CUtlBuffer *, unsigned int, unsigned int *))pheap->m_Memory.m_pMemory + 10);
    v12 = size + 12;
    size = 5;
    v9 = (VertexShaderHandle_t__ *)v8(a1: pheap, a2: v12, a3: &size);
    *((_BYTE *)v9 + v6 + 8) = 0;
    v10 = lengthIsSize | v6;
    *((_DWORD *)v9 + 1) = 1;
    *(_DWORD *)v9 = v10;
    v7 = v9;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v7 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v7 + 8, src, count: copySize);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10073700
// Name: protected: struct GString::DataDesc __near * GString::AllocDataCopy2(class GMemoryHeap __near *,unsigned int,unsigned int,char const __near *,unsigned int,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__stdcall GString::AllocDataCopy2(
        CCountedStringPoolBase<unsigned int> *result,
        unsigned int size,
        unsigned int lengthIsSize,
        unsigned __int8 *src,
        unsigned int copySize1,
        unsigned __int8 *a6,
        unsigned int copySize2)
{
  unsigned int v7; // esi
  VertexShaderHandle_t__ *v8; // esi
  void (__thiscall *v9)(CCountedStringPoolBase<unsigned int> *); // eax
  VertexShaderHandle_t__ *v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v14; // [esp-8h] [ebp-10h]

  v7 = size;
  if ( size != 0 )
  {
    v9 = result->__vftable[10].dtr_CCountedStringPoolBase<unsigned int>;
    v14 = size + 12;
    size = 5;
    v10 = (VertexShaderHandle_t__ *)((int (__thiscall *)(CCountedStringPoolBase<unsigned int> *, unsigned int, unsigned int *))v9)(
                                      a1: result,
                                      a2: v14,
                                      a3: &size);
    *((_BYTE *)v10 + v7 + 8) = 0;
    v11 = lengthIsSize | v7;
    *((_DWORD *)v10 + 1) = 1;
    *(_DWORD *)v10 = v11;
    v8 = v10;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v8 = &GString::NullData;
  }
  v12 = copySize1;
  memcpy(dst: (unsigned __int8 *)v8 + 8, src, count: copySize1);
  memcpy(dst: (unsigned __int8 *)v8 + v12 + 8, src: a6, count: copySize2);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10073780
// Name: public: void GString::AppendChar(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CImagePacker *__thiscall GString::AppendChar(unsigned int *this, CImagePacker *result)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  GMemoryHeap *v5; // eax
  CImagePacker *v6; // eax
  int encodeSize; // [esp+Ch] [ebp-10h] BYREF
  char v8[8]; // [esp+10h] [ebp-Ch] BYREF

  v3 = *this & 0xFFFFFFFC;
  v4 = *(_DWORD *)v3 & 0x7FFFFFFF;
  encodeSize = 0;
  GUTF8Util::EncodeChar(a1: v8, a2: &encodeSize, a3: (unsigned int)result);
  v5 = nullptr;
  if ( (*this & 3) != 0 )
  {
    if ( (*this & 3) == 1 )
    {
      v5 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
    else if ( (*this & 3) == 2 )
    {
      v5 = (GMemoryHeap *)*(this + 1);
    }
  }
  else
  {
    v5 = GMemory::pGlobalHeap;
  }
  *this = (unsigned int)GString::AllocDataCopy2(
                          result: (CCountedStringPoolBase<unsigned int> *)v5,
                          size: v4 + encodeSize,
                          lengthIsSize: 0,
                          src: (unsigned __int8 *)(v3 + 8),
                          copySize1: v4,
                          a6: (unsigned __int8 *)v8,
                          copySize2: encodeSize)
        | *this & 3;
  v6 = (CImagePacker *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) - 1);
  if ( v6 == nullptr )
    return ((CImagePacker *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v3);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10073840
// Name: public: void GString::AppendString(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
RGB888_t *__thiscall GString::AppendString(CUtlMemory<CImagePacker,int> *this, RGB888_t *pstr, int a3)
{
  RGB888_t *result; // eax
  unsigned int v5; // esi
  unsigned int v6; // edi
  GMemoryHeap *m_nAllocationCount; // eax
  int v8; // ecx
  int v9; // ecx
  RGB888_t *encodeSize; // [esp+4h] [ebp-4h]
  unsigned int encodeSizea; // [esp+4h] [ebp-4h]

  result = pstr;
  if ( pstr != nullptr )
  {
    v5 = (int)this->m_pMemory & 0xFFFFFFFC;
    v6 = *(_DWORD *)v5 & 0x7FFFFFFF;
    encodeSize = GUTF8Util::GetEncodeStringSize(retstr: pstr);
    m_nAllocationCount = nullptr;
    v8 = (int)this->m_pMemory & 3;
    if ( v8 != 0 )
    {
      v9 = v8 - 1;
      if ( v9 != 0 )
      {
        if ( v9 == 1 )
          m_nAllocationCount = (GMemoryHeap *)this->m_nAllocationCount;
      }
      else
      {
        m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
      }
    }
    else
    {
      m_nAllocationCount = GMemory::pGlobalHeap;
    }
    encodeSizea = (unsigned int)GString::AllocDataCopy1(
                                  (CCountedStringPoolBase<unsigned int> *)this,
                                  pheap: (CUtlBuffer *)m_nAllocationCount,
                                  size: (unsigned int)encodeSize + v6,
                                  lengthIsSize: 0,
                                  src: (unsigned __int8 *)(v5 + 8),
                                  copySize: v6);
    GUTF8Util::EncodeString(a1: (char *)(encodeSizea + v6 + 8), a2: (const wchar_t *)&pstr->r, a3);
    this->m_pMemory = (CImagePacker *)(encodeSizea | (int)this->m_pMemory & 3);
    result = (RGB888_t *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) - 1);
    if ( result == nullptr )
      return (RGB888_t *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                           a1: GMemory::pGlobalHeap,
                           a2: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073900
// Name: public: void GString::AppendString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CImagePacker *__thiscall GString::AppendString(
        CUtlMemory<CImagePacker,int> *this,
        CImagePacker *putf8str,
        int utf8StrSz)
{
  CImagePacker *result; // eax
  unsigned int v5; // edx
  unsigned int v6; // esi
  GMemoryHeap *m_nAllocationCount; // eax
  unsigned int v8; // edi
  int v9; // ecx
  int v10; // ecx

  result = putf8str;
  if ( putf8str != nullptr )
  {
    v5 = utf8StrSz;
    if ( utf8StrSz != 0 )
    {
      if ( utf8StrSz == -1 )
      {
        utf8StrSz = strlen((const char *)putf8str);
        v5 = utf8StrSz;
      }
      v6 = (int)this->m_pMemory & 0xFFFFFFFC;
      m_nAllocationCount = nullptr;
      v8 = *(_DWORD *)v6 & 0x7FFFFFFF;
      v9 = (int)this->m_pMemory & 3;
      if ( v9 != 0 )
      {
        v10 = v9 - 1;
        if ( v10 != 0 )
        {
          if ( v10 == 1 )
            m_nAllocationCount = (GMemoryHeap *)this->m_nAllocationCount;
        }
        else
        {
          m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
          v5 = utf8StrSz;
        }
      }
      else
      {
        m_nAllocationCount = GMemory::pGlobalHeap;
      }
      this->m_pMemory = (CImagePacker *)((unsigned int)GString::AllocDataCopy2(
                                                         result: (CCountedStringPoolBase<unsigned int> *)m_nAllocationCount,
                                                         size: v5 + v8,
                                                         lengthIsSize: 0,
                                                         src: (unsigned __int8 *)(v6 + 8),
                                                         copySize1: v8,
                                                         a6: (unsigned __int8 *)putf8str,
                                                         copySize2: v5)
                                       | (int)this->m_pMemory & 3);
      result = (CImagePacker *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v6 + 4), Value: -1) - 1);
      if ( result == nullptr )
        return (CImagePacker *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                                 a1: GMemory::pGlobalHeap,
                                 a2: v6);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100739C0
// Name: public: void GString::AssignString(struct GString::InitStruct const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CImagePacker *__thiscall GString::AssignString(CUtlMemory<CImagePacker,int> *this, int a2, unsigned int size)
{
  GMemoryHeap *m_nAllocationCount; // eax
  int v5; // edx
  int v6; // edx
  unsigned int v7; // edi
  unsigned int v8; // ebx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  unsigned int *v10; // eax
  CImagePacker *result; // eax
  unsigned int v12; // [esp-10h] [ebp-18h]
  unsigned int v13; // [esp+4h] [ebp-4h]

  v13 = (int)this->m_pMemory & 0xFFFFFFFC;
  m_nAllocationCount = nullptr;
  v5 = (int)this->m_pMemory & 3;
  if ( v5 != 0 )
  {
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
        m_nAllocationCount = (GMemoryHeap *)this->m_nAllocationCount;
    }
    else
    {
      m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
  }
  else
  {
    m_nAllocationCount = GMemory::pGlobalHeap;
  }
  v7 = size;
  if ( size != 0 )
  {
    Alloc_2 = m_nAllocationCount->Alloc_2;
    v12 = size + 12;
    size = 5;
    v10 = (unsigned int *)Alloc_2(this: m_nAllocationCount, a2: v12, a3: (const GAllocDebugInfo *)&size);
    *((_BYTE *)v10 + v7 + 8) = 0;
    v10[1] = 1;
    *v10 = v7;
    v8 = (unsigned int)v10;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v8 = (unsigned int)&GString::NullData;
  }
  (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)a2 + 4))(a1: a2, a2: v8 + 8, a3: v7);
  this->m_pMemory = (CImagePacker *)(v8 | (int)this->m_pMemory & 3);
  result = (CImagePacker *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v13 + 4), Value: -1) - 1);
  if ( result == nullptr )
    return ((CImagePacker *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v13);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073A80
// Name: public: void GString::AssignString(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CImagePacker *__thiscall GString::AssignString(
        CUtlMemory<CImagePacker,int> *this,
        unsigned __int8 *src,
        unsigned int size)
{
  GMemoryHeap *m_nAllocationCount; // eax
  int v5; // edx
  int v6; // edx
  unsigned int v7; // ebx
  VertexShaderHandle_t__ *v8; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  VertexShaderHandle_t__ *v10; // eax
  const CImagePacker *result; // eax
  unsigned int v12; // [esp-8h] [ebp-18h]
  unsigned int v13; // [esp+Ch] [ebp-4h]

  v13 = (int)this->m_pMemory & 0xFFFFFFFC;
  m_nAllocationCount = nullptr;
  v5 = (int)this->m_pMemory & 3;
  if ( v5 != 0 )
  {
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
        m_nAllocationCount = (GMemoryHeap *)this->m_nAllocationCount;
    }
    else
    {
      m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
  }
  else
  {
    m_nAllocationCount = GMemory::pGlobalHeap;
  }
  v7 = size;
  if ( size != 0 )
  {
    Alloc_2 = m_nAllocationCount->Alloc_2;
    v12 = size + 12;
    size = 5;
    v10 = (VertexShaderHandle_t__ *)Alloc_2(this: m_nAllocationCount, a2: v12, a3: (const GAllocDebugInfo *)&size);
    *((_BYTE *)v10 + v7 + 8) = 0;
    *((_DWORD *)v10 + 1) = 1;
    *(_DWORD *)v10 = v7;
    v8 = v10;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v8 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v8 + 8, src, count: v7);
  this->m_pMemory = (CImagePacker *)((int)this->m_pMemory & 3 | (unsigned int)v8);
  result = (const CImagePacker *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v13 + 4), Value: -1) - 1);
  if ( result == nullptr )
    return ((const CImagePacker *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v13);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073B50
// Name: public: void GString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::operator=(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this,
        unsigned __int8 *a2)
{
  if ( a2 != nullptr )
    GString::AssignString((CUtlMemory<CImagePacker,int> *)this, src: a2, size: strlen((const char *)a2));
  else
    GString::AssignString((CUtlMemory<CImagePacker,int> *)this, src: nullptr, size: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10073B90
// Name: public: void GString::operator=(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GString::operator=(unsigned int *this, RGB888_t *a2)
{
  unsigned int v3; // ebx
  RGB888_t *EncodeStringSize; // edi
  GMemoryHeap *v5; // eax
  VertexShaderHandle_t__ *v6; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  RGB888_t **v8; // eax
  int result; // eax
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = *this & 0xFFFFFFFC;
  if ( a2 != nullptr )
    EncodeStringSize = GUTF8Util::GetEncodeStringSize(retstr: a2);
  else
    EncodeStringSize = nullptr;
  v5 = nullptr;
  if ( (*this & 3) != 0 )
  {
    if ( (*this & 3) == 1 )
    {
      v5 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
    else if ( (*this & 3) == 2 )
    {
      v5 = (GMemoryHeap *)*(this + 1);
    }
  }
  else
  {
    v5 = GMemory::pGlobalHeap;
  }
  if ( EncodeStringSize != nullptr )
  {
    Alloc_2 = v5->Alloc_2;
    v10 = 5;
    v8 = (RGB888_t **)Alloc_2(this: v5, a2: (unsigned int)&EncodeStringSize[4], a3: (const GAllocDebugInfo *)&v10);
    *(&EncodeStringSize[2].b + (_DWORD)v8) = 0;
    *v8 = EncodeStringSize;
    v8[1] = (RGB888_t *)1;
    v6 = (VertexShaderHandle_t__ *)v8;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v6 = &GString::NullData;
  }
  GUTF8Util::EncodeString(a1: (char *)v6 + 8, a2: (const wchar_t *)&a2->r, a3: -1);
  *this = (unsigned int)v6 | *this & 3;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) - 1;
  if ( result == 0 )
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073C60
// Name: public: void GString::operator=(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GString::operator=(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this@<ecx>,
        _DWORD *src,
        int a3)
{
  int v4; // eax
  int v5; // eax
  GMemoryHeap *v6; // eax
  unsigned int v7; // edi
  volatile LONG *v8; // ebx
  GMemoryHeap *pheap; // [esp+Ch] [ebp-4h]

  v4 = (int)this->m_Memory.m_pMemory & 3;
  pheap = nullptr;
  if ( v4 != 0 )
  {
    v5 = v4 - 1;
    if ( v5 != 0 )
    {
      if ( v5 == 1 )
        pheap = (GMemoryHeap *)this->m_Memory.m_nAllocationCount;
    }
    else
    {
      pheap = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
  }
  else
  {
    pheap = GMemory::pGlobalHeap;
  }
  v6 = nullptr;
  v7 = *src & 0xFFFFFFFC;
  v8 = (volatile LONG *)((int)this->m_Memory.m_pMemory & 0xFFFFFFFC);
  if ( (*src & 3) != 0 )
  {
    if ( (*src & 3) == 1 )
    {
      v6 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: src);
    }
    else if ( (*src & 3) == 2 )
    {
      v6 = (GMemoryHeap *)src[1];
    }
  }
  else
  {
    v6 = GMemory::pGlobalHeap;
  }
  if ( pheap == v6 )
  {
    this->m_Memory.m_pMemory = (void (__cdecl **)(int))(v7 | (int)this->m_Memory.m_pMemory & 3);
    InterlockedExchangeAdd(Addend: (volatile LONG *)(v7 + 4), Value: 1);
  }
  else
  {
    this->m_Memory.m_pMemory = (void (__cdecl **)(int))((unsigned int)GString::AllocDataCopy1(
                                                                        (CCountedStringPoolBase<unsigned int> *)this,
                                                                        (CUtlBuffer *)pheap,
                                                                        size: *(_DWORD *)v7 & 0x7FFFFFFF,
                                                                        lengthIsSize: *(_DWORD *)v7 & 0x80000000,
                                                                        src: (unsigned __int8 *)(v7 + 8),
                                                                        copySize: *(_DWORD *)v7 & 0x7FFFFFFF)
                                                      | (int)this->m_Memory.m_pMemory & 3);
  }
  if ( InterlockedExchangeAdd(Addend: v8 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x10073D50
// Name: public: void GString::operator=(class GStringBuffer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GString::operator=(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this@<ecx>,
        void (__cdecl **src)(int),
        int polddata,
        int src_8)
{
  void (__cdecl *v5)(int); // edi
  GMemoryHeap *m_nAllocationCount; // eax
  int v7; // edx
  int v8; // edx
  VertexShaderHandle_t__ *v9; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  void (__cdecl **v11)(int); // eax
  volatile LONG *v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *srca; // [esp+1Ch] [ebp+8h]

  v12 = (volatile LONG *)((int)this->m_Memory.m_pMemory & 0xFFFFFFFC);
  v5 = src[1];
  srca = (unsigned __int8 *)*src;
  if ( srca == nullptr )
    srca = (unsigned __int8 *)&pMem;
  m_nAllocationCount = nullptr;
  v7 = (int)this->m_Memory.m_pMemory & 3;
  if ( v7 != 0 )
  {
    v8 = v7 - 1;
    if ( v8 != 0 )
    {
      if ( v8 == 1 )
        m_nAllocationCount = (GMemoryHeap *)this->m_Memory.m_nAllocationCount;
    }
    else
    {
      m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
  }
  else
  {
    m_nAllocationCount = GMemory::pGlobalHeap;
  }
  if ( v5 != nullptr )
  {
    Alloc_2 = m_nAllocationCount->Alloc_2;
    v13 = 5;
    v11 = (void (__cdecl **)(int))Alloc_2(
                                    this: m_nAllocationCount,
                                    a2: (unsigned int)v5 + 12,
                                    a3: (const GAllocDebugInfo *)&v13);
    *((_BYTE *)v5 + (_DWORD)v11 + 8) = 0;
    v11[1] = (void (__cdecl *)(int))1;
    *v11 = v5;
    v9 = (VertexShaderHandle_t__ *)v11;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v9 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v9 + 8, src: srca, count: (unsigned int)v5);
  this->m_Memory.m_pMemory = (void (__cdecl **)(int))((int)this->m_Memory.m_pMemory & 3 | (unsigned int)v9);
  if ( InterlockedExchangeAdd(Addend: v12 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v12);
}

//------------------------------------------------------------------------------
// Address: 0x10073E30
// Name: public: void GString::operator+=(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GString::operator+=(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this@<ecx>,
        int *src,
        int srcSize)
{
  void (__cdecl **m_pMemory)(int); // ecx
  int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // edi
  GMemoryHeap *m_nAllocationCount; // eax
  int v9; // ecx
  int v10; // ecx
  int ourSize; // [esp+Ch] [ebp-8h]
  int srcSizea; // [esp+10h] [ebp-4h]
  unsigned int lflaga; // [esp+1Ch] [ebp+8h]
  unsigned int lflag; // [esp+1Ch] [ebp+8h]

  m_pMemory = this->m_Memory.m_pMemory;
  v5 = *src;
  v6 = (unsigned int)m_pMemory & 0xFFFFFFFC;
  lflaga = *(_DWORD *)((unsigned int)m_pMemory & 0xFFFFFFFC);
  ourSize = lflaga & 0x7FFFFFFF;
  v7 = v5 & 0xFFFFFFFC;
  lflag = lflaga & *(_DWORD *)v7 & 0x80000000;
  m_nAllocationCount = nullptr;
  v9 = (unsigned __int8)m_pMemory & 3;
  srcSizea = *(_DWORD *)v7 & 0x7FFFFFFF;
  if ( v9 != 0 )
  {
    v10 = v9 - 1;
    if ( v10 != 0 )
    {
      if ( v10 == 1 )
        m_nAllocationCount = (GMemoryHeap *)this->m_Memory.m_nAllocationCount;
    }
    else
    {
      m_nAllocationCount = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    }
  }
  else
  {
    m_nAllocationCount = GMemory::pGlobalHeap;
  }
  this->m_Memory.m_pMemory = (void (__cdecl **)(int))((unsigned int)GString::AllocDataCopy2(
                                                                      result: (CCountedStringPoolBase<unsigned int> *)m_nAllocationCount,
                                                                      size: ourSize + srcSizea,
                                                                      lengthIsSize: lflag,
                                                                      src: (unsigned __int8 *)(v6 + 8),
                                                                      copySize1: ourSize,
                                                                      a6: (unsigned __int8 *)(v7 + 8),
                                                                      copySize2: srcSizea)
                                                    | (int)this->m_Memory.m_pMemory & 3);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v6 + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x10073EF0
// Name: public: void GString::Remove(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::Remove(CUtlMemory<CImagePacker,int> *this, CImagePacker *posAt, int removeLength)
{
  volatile LONG *v4; // esi
  unsigned int v5; // ebx
  int Length; // eax
  unsigned int ByteIndex; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // ecx
  GMemoryHeap *v12; // eax
  unsigned int oldSize; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]
  int removeSize; // [esp+1Ch] [ebp+8h]
  CCountedStringPoolBase<unsigned int> *removeLengtha; // [esp+20h] [ebp+Ch]

  v4 = (volatile LONG *)((int)this->m_pMemory & 0xFFFFFFFC);
  oldSize = *v4 & 0x7FFFFFFF;
  v5 = oldSize;
  if ( *(int *)v4 >= 0 )
  {
    Length = GUTF8Util::GetLength(length: (const char *)v4 + 8, buflen: *v4 & 0x7FFFFFFF);
    if ( Length == oldSize )
      *v4 |= 0x80000000;
    v5 = Length;
  }
  if ( (unsigned int)posAt < v5 )
  {
    ByteIndex = GUTF8Util::GetByteIndex();
    v8 = GUTF8Util::GetByteIndex();
    v9 = *v4 & 0x80000000;
    v10 = (int)this->m_pMemory & 3;
    removeSize = v8;
    v14 = v9;
    removeLengtha = nullptr;
    if ( v10 != 0 )
    {
      v11 = v10 - 1;
      if ( v11 != 0 )
      {
        if ( v11 == 1 )
          removeLengtha = (CCountedStringPoolBase<unsigned int> *)this->m_nAllocationCount;
      }
      else
      {
        v12 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
        v9 = v14;
        removeLengtha = (CCountedStringPoolBase<unsigned int> *)v12;
      }
    }
    else
    {
      removeLengtha = (CCountedStringPoolBase<unsigned int> *)GMemory::pGlobalHeap;
    }
    this->m_pMemory = (CImagePacker *)((unsigned int)GString::AllocDataCopy2(
                                                       result: removeLengtha,
                                                       size: oldSize - removeSize,
                                                       lengthIsSize: v9,
                                                       src: (unsigned __int8 *)v4 + 8,
                                                       copySize1: ByteIndex,
                                                       a6: (unsigned __int8 *)this->m_pMemory->m_pLightmapWavefront
                                                     + removeSize
                                                     + ByteIndex,
                                                       copySize2: oldSize - removeSize - ByteIndex)
                                     | (int)this->m_pMemory & 3);
    if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074010
// Name: public: void GString::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::Clear(GString *this)
{
  volatile LONG *v2; // esi

  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  v2 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  this->HeapTypeBits = (unsigned int)&GString::NullData | this->HeapTypeBits & 3;
}

//------------------------------------------------------------------------------
// Address: 0x10074060
// Name: public: static void GString::EscapeSpecialHTML(char const __near *,unsigned int,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall GString::EscapeSpecialHTML(
        bool (__cdecl *a1)(const char *const *, const char *const *),
        unsigned int a2,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a3)
{
  unsigned int BufferSize; // ebx
  char *pData; // esi
  unsigned int Size; // edi
  unsigned int i; // eax
  char *v7; // eax
  char *v8; // eax
  int v9; // [esp+0h] [ebp-44h]
  int v10; // [esp+4h] [ebp-40h]
  unsigned int v11; // [esp+10h] [ebp-34h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+14h] [ebp-30h] BYREF
  int v13; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int count; // [esp+1Ch] [ebp-28h] BYREF
  GStringBuffer v15; // [esp+20h] [ebp-24h] BYREF
  unsigned __int8 src[8]; // [esp+38h] [ebp-Ch] BYREF

  putf8Buffer.m_LessFunc = a1;
  BufferSize = 0;
  pData = nullptr;
  Size = 0;
  memset(&v15, 0, 12);
  v15.GrowSize = 512;
  v15.LengthIsSize = false;
  v15.pHeap = GMemory::pGlobalHeap;
  for ( i = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
        i != 0;
        i = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) )
  {
    switch ( i )
    {
      case '<':
        v13 = Size;
        Size += 4;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(v15.GrowSize - 1) & (v15.GrowSize + Size);
          v15.BufferSize = BufferSize;
          if ( pData != nullptr )
          {
            v7 = (char *)((int (__stdcall *)(char *, unsigned int))GMemory::pGlobalHeap->Realloc)(
                           a1: pData,
                           a2: BufferSize);
          }
          else
          {
            count = 5;
            v7 = (char *)((int (__stdcall *)(unsigned int, unsigned int *))v15.pHeap->Alloc_2)(
                           a1: BufferSize,
                           a2: &count);
          }
          pData = v7;
          v15.pData = v7;
        }
        v15.LengthIsSize = false;
        v15.Size = Size;
        if ( pData != nullptr )
          pData[Size] = 0;
        *(_DWORD *)&pData[v13] = *(_DWORD *)"&lt;";
        break;
      case '>':
        GStringBuffer::Resize(this: &v15, a2: Size + 4);
        pData = v15.pData;
        BufferSize = v15.BufferSize;
        *(_DWORD *)&v15.pData[Size] = *(_DWORD *)"&gt;";
        Size = v15.Size;
        break;
      case '"':
        GStringBuffer::Resize(this: &v15, a2: Size + 6);
        pData = v15.pData;
        BufferSize = v15.BufferSize;
        *(_DWORD *)&v15.pData[Size] = *(_DWORD *)"&quot;";
        *(_WORD *)&pData[Size + 4] = *(_WORD *)"t;";
        Size = v15.Size;
        break;
      case '\'':
        GStringBuffer::Resize(this: &v15, a2: Size + 6);
        pData = v15.pData;
        BufferSize = v15.BufferSize;
        *(_DWORD *)&v15.pData[Size] = *(_DWORD *)"&apos;";
        *(_WORD *)&pData[Size + 4] = *(_WORD *)"s;";
        Size = v15.Size;
        break;
      case '&':
        GStringBuffer::Resize(this: &v15, a2: Size + 5);
        pData = v15.pData;
        BufferSize = v15.BufferSize;
        *(_DWORD *)&v15.pData[Size] = *(_DWORD *)"&amp;";
        pData[Size + 4] = aAmp_2[4];
        Size = v15.Size;
        break;
      default:
        v11 = Size;
        count = 0;
        GUTF8Util::EncodeChar(a1: (char *)src, a2: (int *)&count, a3: i);
        Size += count;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(v15.GrowSize - 1) & (v15.GrowSize + Size);
          v15.BufferSize = BufferSize;
          if ( pData != nullptr )
          {
            v8 = (char *)((int (__stdcall *)(char *, unsigned int))GMemory::pGlobalHeap->Realloc)(
                           a1: pData,
                           a2: BufferSize);
          }
          else
          {
            v13 = 5;
            v8 = (char *)((int (__stdcall *)(unsigned int, int *))v15.pHeap->Alloc_2)(a1: BufferSize, a2: &v13);
          }
          pData = v8;
          v15.pData = v8;
        }
        v15.LengthIsSize = false;
        v15.Size = Size;
        if ( pData != nullptr )
          pData[Size] = 0;
        memcpy(dst: (unsigned __int8 *)&pData[v11], src, count);
        break;
    }
  }
  GString::operator=(this: a3, src: (void (__cdecl **)(int))&v15, polddata: v9, src_8: v10);
  if ( pData != nullptr )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pData);
}

//------------------------------------------------------------------------------
// Address: 0x100742A0
// Name: public: static void GString::UnescapeSpecialHTML(char const __near *,unsigned int,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall GString::UnescapeSpecialHTML(
        char *a1,
        unsigned int a2,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a3)
{
  unsigned int v3; // ebx
  void (__cdecl *v4)(int); // esi
  unsigned int v5; // edi
  unsigned int Char; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  void (__cdecl *v11)(int); // eax
  unsigned int v12; // ebx
  void (__cdecl *v13)(int); // eax
  unsigned int v14; // ebx
  void (__cdecl *v15)(int); // eax
  unsigned int v16; // [esp-4h] [ebp-50h]
  unsigned int v17; // [esp-4h] [ebp-50h]
  int v18; // [esp+0h] [ebp-4Ch]
  int v19; // [esp+4h] [ebp-48h]
  void (__cdecl *v20)(int); // [esp+10h] [ebp-3Ch] BYREF
  unsigned int v21; // [esp+14h] [ebp-38h]
  unsigned int v22; // [esp+18h] [ebp-34h]
  int v23; // [esp+1Ch] [ebp-30h]
  char v24; // [esp+20h] [ebp-2Ch]
  GMemoryHeap *v25; // [esp+24h] [ebp-28h]
  int v26; // [esp+28h] [ebp-24h] BYREF
  int v27; // [esp+2Ch] [ebp-20h] BYREF
  char *first; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int count; // [esp+34h] [ebp-18h] BYREF
  char v30[8]; // [esp+38h] [ebp-14h] BYREF
  unsigned __int8 src[8]; // [esp+40h] [ebp-Ch] BYREF

  first = a1;
  v3 = 0;
  v4 = nullptr;
  v5 = 0;
  v20 = nullptr;
  v21 = 0;
  v22 = 0;
  v23 = 512;
  v24 = 0;
  v25 = GMemory::pGlobalHeap;
  Char = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&first);
  if ( Char == 0 )
    goto LABEL_54;
  while ( 1 )
  {
    if ( Char != 38 )
    {
      v26 = v3;
      count = 0;
      GUTF8Util::EncodeChar(a1: (char *)src, a2: (int *)&count, a3: Char);
      v3 += count;
      if ( v3 >= v5 )
      {
        v5 = (v3 + 512) & 0xFFFFFE00;
        if ( v4 != nullptr )
        {
          v9 = ((int (__stdcall *)(void (__cdecl *)(int), unsigned int))GMemory::pGlobalHeap->Realloc)(
                 a1: v4,
                 a2: (v3 + 512) & 0xFFFFFE00);
        }
        else
        {
          v27 = 5;
          v9 = ((int (__stdcall *)(unsigned int, int *))v25->Alloc_2)(a1: (v3 + 512) & 0xFFFFFE00, a2: &v27);
        }
        v4 = (void (__cdecl *)(int))v9;
      }
      v24 = 0;
      if ( v4 != nullptr )
        *((_BYTE *)v4 + v3) = 0;
      memcpy(dst: (unsigned __int8 *)v4 + v26, src, count);
      goto LABEL_24;
    }
    if ( strncmp(first, last: "quot;", count: 5u) == 0 )
    {
      v16 = 34;
      goto LABEL_27;
    }
    if ( strncmp(first, last: "apos;", count: 5u) == 0 )
      break;
    if ( strncmp(first, last: "amp;", count: 4u) == 0 )
    {
      v21 = v3;
      v20 = v4;
      v22 = v5;
      v26 = v3;
      count = 0;
      GUTF8Util::EncodeChar(a1: (char *)src, a2: (int *)&count, a3: 0x26u);
      v12 = count + v3;
      if ( v12 >= v5 )
      {
        v22 = (v12 + 512) & 0xFFFFFE00;
        if ( v4 != nullptr )
        {
          v13 = (void (__cdecl *)(int))((int (__stdcall *)(void (__cdecl *)(int), unsigned int))GMemory::pGlobalHeap->Realloc)(
                                         a1: v4,
                                         a2: (v12 + 512) & 0xFFFFFE00);
        }
        else
        {
          v27 = 5;
          v13 = (void (__cdecl *)(int))((int (__stdcall *)(unsigned int, int *))v25->Alloc_2)(
                                         a1: (v12 + 512) & 0xFFFFFE00,
                                         a2: &v27);
        }
        v4 = v13;
        v20 = v13;
      }
      v24 = 0;
      v21 = v12;
      if ( v4 != nullptr )
        *((_BYTE *)v4 + v12) = 0;
      memcpy(dst: (unsigned __int8 *)v4 + v26, src, count);
      first += 4;
      goto LABEL_54;
    }
    if ( strncmp(first, last: "lt;", count: 3u) == 0 )
    {
      count = 0;
      v17 = 60;
LABEL_45:
      v26 = v3;
      v22 = v5;
      v20 = v4;
      v21 = v3;
      GUTF8Util::EncodeChar(a1: (char *)src, a2: (int *)&count, a3: v17);
      v14 = count + v3;
      if ( v14 >= v5 )
      {
        v22 = (v14 + 512) & 0xFFFFFE00;
        if ( v4 != nullptr )
        {
          v15 = (void (__cdecl *)(int))((int (__stdcall *)(void (__cdecl *)(int), unsigned int))GMemory::pGlobalHeap->Realloc)(
                                         a1: v4,
                                         a2: (v14 + 512) & 0xFFFFFE00);
        }
        else
        {
          v27 = 5;
          v15 = (void (__cdecl *)(int))((int (__stdcall *)(unsigned int, int *))v25->Alloc_2)(
                                         a1: (v14 + 512) & 0xFFFFFE00,
                                         a2: &v27);
        }
        v4 = v15;
        v20 = v15;
      }
      v21 = v14;
      v24 = 0;
      if ( v4 != nullptr )
        *((_BYTE *)v4 + v14) = 0;
      memcpy(dst: (unsigned __int8 *)v4 + v26, src, count);
      first += 3;
      goto LABEL_54;
    }
    v7 = strncmp(first, last: "gt;", count: 3u);
    count = 0;
    if ( v7 == 0 )
    {
      v17 = 62;
      goto LABEL_45;
    }
    v27 = v3;
    GUTF8Util::EncodeChar(a1: v30, a2: (int *)&count, a3: 0x26u);
    v3 += count;
    if ( v3 >= v5 )
    {
      v5 = (v3 + 512) & 0xFFFFFE00;
      if ( v4 != nullptr )
      {
        v8 = ((int (__stdcall *)(void (__cdecl *)(int), unsigned int))GMemory::pGlobalHeap->Realloc)(
               a1: v4,
               a2: (v3 + 512) & 0xFFFFFE00);
      }
      else
      {
        v26 = 5;
        v8 = ((int (__stdcall *)(unsigned int, int *))v25->Alloc_2)(a1: (v3 + 512) & 0xFFFFFE00, a2: &v26);
      }
      v4 = (void (__cdecl *)(int))v8;
    }
    v24 = 0;
    if ( v4 != nullptr )
      *((_BYTE *)v4 + v3) = 0;
    memcpy(dst: (unsigned __int8 *)v4 + v27, src: (unsigned __int8 *)v30, count);
LABEL_24:
    Char = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&first);
    if ( Char == 0 )
    {
      v21 = v3;
      v20 = v4;
      v22 = v5;
      goto LABEL_54;
    }
  }
  v16 = 39;
LABEL_27:
  count = 0;
  v26 = v3;
  v22 = v5;
  v20 = v4;
  v21 = v3;
  GUTF8Util::EncodeChar(a1: (char *)src, a2: (int *)&count, a3: v16);
  v10 = count + v3;
  if ( v10 >= v5 )
  {
    v22 = (v10 + 512) & 0xFFFFFE00;
    if ( v4 != nullptr )
    {
      v11 = (void (__cdecl *)(int))((int (__stdcall *)(void (__cdecl *)(int), unsigned int))GMemory::pGlobalHeap->Realloc)(
                                     a1: v4,
                                     a2: (v10 + 512) & 0xFFFFFE00);
    }
    else
    {
      v27 = 5;
      v11 = (void (__cdecl *)(int))((int (__stdcall *)(unsigned int, int *))v25->Alloc_2)(
                                     a1: (v10 + 512) & 0xFFFFFE00,
                                     a2: &v27);
    }
    v4 = v11;
    v20 = v11;
  }
  v21 = v10;
  v24 = 0;
  if ( v4 != nullptr )
    *((_BYTE *)v4 + v10) = 0;
  memcpy(dst: (unsigned __int8 *)v4 + v26, src, count);
  first += 5;
LABEL_54:
  GString::operator=(this: a3, src: &v20, polddata: v18, src_8: v19);
  if ( v4 != nullptr )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10074680
// Name: public: GStringLH::GStringLH(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringLH::GStringLH(CFixedBitVecBase<128> *this)
{
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  this->m_Ints[0] = (unsigned int)&GString::NullData.unused + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100746A0
// Name: public: GStringLH::GStringLH(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringLH::GStringLH(CFixedBitVecBase<128> *this, char *pdata)
{
  unsigned int v3; // esi
  GMemoryHeap *v4; // eax
  VertexShaderHandle_t__ *v5; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  VertexShaderHandle_t__ *v7; // eax
  GAllocDebugInfo v8; // [esp+Ch] [ebp-8h] BYREF
  char v9; // [esp+13h] [ebp-1h]

  v9 = 0;
  if ( pdata != nullptr )
    v3 = strlen(pdata);
  else
    v3 = 0;
  v4 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  if ( v3 != 0 )
  {
    Alloc_2 = v4->Alloc_2;
    v8.StatId = 5;
    v7 = (VertexShaderHandle_t__ *)Alloc_2(this: v4, a2: v3 + 12, a3: &v8);
    *((_BYTE *)v7 + v3 + 8) = 0;
    *((_DWORD *)v7 + 1) = 1;
    *(_DWORD *)v7 = v3;
    v5 = v7;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v5 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v5 + 8, src: (unsigned __int8 *)pdata, count: v3);
  this->m_Ints[0] = (unsigned int)v5 | 1;
}

//------------------------------------------------------------------------------
// Address: 0x10074740
// Name: private: void GStringLH::CopyConstructHelper(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int>_vtbl *__thiscall GStringLH::CopyConstructHelper(
        CCountedStringPoolBase<unsigned int> *this,
        const CFixedBitVecBase<128> *result)
{
  unsigned int v4; // esi
  CUtlBuffer *v5; // edx
  GMemoryHeap *v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  CCountedStringPoolBase<unsigned int>_vtbl *v9; // eax
  const CFixedBitVecBase<128> *v10; // [esp+14h] [ebp+8h]

  v4 = result->m_Ints[0] & 0xFFFFFFFC;
  v5 = (CUtlBuffer *)((int (__stdcall *)(CCountedStringPoolBase<unsigned int> *))GMemory::pGlobalHeap->GetAllocHeap)(a1: this);
  v6 = nullptr;
  v7 = result->m_Ints[0] & 3;
  v10 = (const CFixedBitVecBase<128> *)v5;
  if ( v7 != 0 )
  {
    v8 = v7 - 1;
    if ( v8 != 0 )
    {
      if ( v8 == 1 )
        v6 = (GMemoryHeap *)result->m_Ints[1];
    }
    else
    {
      v6 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: result);
      v5 = (CUtlBuffer *)v10;
    }
  }
  else
  {
    v6 = GMemory::pGlobalHeap;
  }
  if ( v6 == (GMemoryHeap *)v5 )
  {
    v9 = (CCountedStringPoolBase<unsigned int>_vtbl *)InterlockedExchangeAdd(
                                                        Addend: (volatile LONG *)(v4 + 4),
                                                        Value: 1);
    this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)(v4 | 1);
  }
  else
  {
    v9 = (CCountedStringPoolBase<unsigned int>_vtbl *)((unsigned int)GString::AllocDataCopy1(
                                                                       this,
                                                                       pheap: v5,
                                                                       size: *(_DWORD *)v4 & 0x7FFFFFFF,
                                                                       lengthIsSize: *(_DWORD *)v4 & 0x80000000,
                                                                       src: (unsigned __int8 *)(v4 + 8),
                                                                       copySize: *(_DWORD *)v4 & 0x7FFFFFFF)
                                                     | 1);
    this->__vftable = v9;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100747E0
// Name: public: GStringDH::GStringDH(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GStringDH::GStringDH(GStringDH *this, struct GMemoryHeap *a2)
{
  this->pHeap = a2;
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  this->HeapTypeBits = (unsigned int)&GString::NullData.unused + 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074810
// Name: private: void GStringDH::CopyConstructHelper(class GString const __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringDH::CopyConstructHelper(GStringDH *this, const struct GString *a2, CUtlBuffer *pheap)
{
  GMemoryHeap *pData; // eax
  unsigned int v5; // esi
  GMemoryHeap *v6; // edx

  pData = nullptr;
  v5 = a2->HeapTypeBits & 0xFFFFFFFC;
  if ( (a2->HeapTypeBits & 3) != 0 )
  {
    if ( (a2->HeapTypeBits & 3) == 1 )
    {
      pData = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2);
    }
    else if ( (a2->HeapTypeBits & 3) == 2 )
    {
      pData = (GMemoryHeap *)a2[1].pData;
    }
  }
  else
  {
    pData = GMemory::pGlobalHeap;
  }
  v6 = (GMemoryHeap *)pheap;
  if ( pheap == nullptr )
    v6 = pData;
  this->pHeap = v6;
  if ( pData == v6 )
  {
    InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: 1);
    this->HeapTypeBits = v5 | 2;
  }
  else
  {
    this->HeapTypeBits = (unsigned int)GString::AllocDataCopy1(
                                         (CCountedStringPoolBase<unsigned int> *)this,
                                         pheap: (CUtlBuffer *)v6,
                                         size: *(_DWORD *)v5 & 0x7FFFFFFF,
                                         lengthIsSize: *(_DWORD *)v5 & 0x80000000,
                                         src: (unsigned __int8 *)(v5 + 8),
                                         copySize: *(_DWORD *)v5 & 0x7FFFFFFF)
                       | 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100748A0
// Name: public: GStringBuffer::GStringBuffer(char const __near *,unsigned int,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GStringBuffer *__thiscall GStringBuffer::GStringBuffer(
        GStringBuffer *this,
        char *src,
        unsigned int count,
        struct GMemoryHeap *a4)
{
  unsigned int v5; // edi

  v5 = count;
  this->pData = nullptr;
  this->Size = 0;
  this->BufferSize = 0;
  this->GrowSize = 512;
  this->LengthIsSize = false;
  this->pHeap = a4;
  if ( src != nullptr && count != 0 )
  {
    if ( count == -1 )
      v5 = strlen(src);
    GStringBuffer::Resize(this, a2: v5);
    memcpy(dst: (unsigned __int8 *)this->pData, (unsigned __int8 *)src, count: v5);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074910
// Name: public: GString::GString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GString::GString(GString *this, int src)
{
  unsigned __int8 *v2; // ebx
  unsigned int v3; // esi
  VertexShaderHandle_t__ *v4; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  VertexShaderHandle_t__ *v6; // eax

  v2 = (unsigned __int8 *)src;
  if ( src != 0 )
  {
    v3 = strlen((const char *)src);
    if ( v3 != 0 )
    {
      Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
      src = 5;
      v6 = (VertexShaderHandle_t__ *)Alloc_2(this: GMemory::pGlobalHeap, a2: v3 + 12, a3: (const GAllocDebugInfo *)&src);
      *((_BYTE *)v6 + v3 + 8) = 0;
      *((_DWORD *)v6 + 1) = 1;
      *(_DWORD *)v6 = v3;
      v4 = v6;
      goto LABEL_6;
    }
  }
  else
  {
    v3 = 0;
  }
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  v4 = &GString::NullData;
LABEL_6:
  memcpy(dst: (unsigned __int8 *)v4 + 8, src: v2, count: v3);
  this->HeapTypeBits = (unsigned int)v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100749A0
// Name: public: GString::GString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::GString(CUtlMemory<CImagePacker,int> *this, char *pdata1, char *pdata2, unsigned __int8 *src)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edi
  VertexShaderHandle_t__ *v7; // esi
  unsigned int size1; // [esp+10h] [ebp-4h]

  v4 = 0;
  if ( pdata1 != nullptr )
  {
    v5 = strlen(pdata1);
    size1 = v5;
  }
  else
  {
    size1 = 0;
    v5 = 0;
  }
  if ( pdata2 != nullptr )
    v6 = strlen(pdata2);
  else
    v6 = 0;
  if ( src != nullptr )
    v4 = strlen((const char *)src);
  v7 = GString::AllocDataCopy2(
         result: (CCountedStringPoolBase<unsigned int> *)GMemory::pGlobalHeap,
         size: v5 + v4 + v6,
         lengthIsSize: 0,
         src: (unsigned __int8 *)pdata1,
         copySize1: v5,
         a6: (unsigned __int8 *)pdata2,
         copySize2: v6);
  memcpy(dst: (unsigned __int8 *)v7 + v6 + size1 + 8, src, count: v4);
  this->m_pMemory = (CImagePacker *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10074A60
// Name: public: GString::GString(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GString::GString(GString *this, char *src, unsigned int count)
{
  unsigned int v3; // esi
  VertexShaderHandle_t__ *v5; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  VertexShaderHandle_t__ *v7; // eax
  unsigned int v9; // [esp-8h] [ebp-14h]

  v3 = count;
  if ( count != 0 )
  {
    Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
    v9 = count + 12;
    count = 5;
    v7 = (VertexShaderHandle_t__ *)Alloc_2(this: GMemory::pGlobalHeap, a2: v9, a3: (const GAllocDebugInfo *)&count);
    *((_BYTE *)v7 + v3 + 8) = 0;
    *((_DWORD *)v7 + 1) = 1;
    *(_DWORD *)v7 = v3;
    v5 = v7;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v5 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v5 + 8, (unsigned __int8 *)src, count: v3);
  this->HeapTypeBits = (unsigned int)v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074AD0
// Name: public: GString::GString(struct GString::InitStruct const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GString::GString(GString *this, struct GString::InitStruct *a2, unsigned int size)
{
  unsigned int v3; // esi
  unsigned int v5; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  unsigned int v8; // [esp-8h] [ebp-10h]

  v3 = size;
  if ( size != 0 )
  {
    Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
    v8 = size + 12;
    size = 5;
    v5 = (int)Alloc_2(this: GMemory::pGlobalHeap, a2: v8, a3: (const GAllocDebugInfo *)&size);
    *(_BYTE *)(v5 + v3 + 8) = 0;
    *(_DWORD *)(v5 + 4) = 1;
    *(_DWORD *)v5 = v3;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v5 = (unsigned int)&GString::NullData;
  }
  this->HeapTypeBits = v5;
  a2->InitString(this: a2, a2: (char *)((v5 & 0xFFFFFFFC) + 8), a3: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074B40
// Name: public: GString::GString(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall GString::GString(
        CCountedStringPoolBase<unsigned int> *this,
        CImagePacker *result)
{
  GMemoryHeap *m_MaxLightmapHeight; // eax
  unsigned int v4; // esi

  m_MaxLightmapHeight = nullptr;
  v4 = result->m_MaxLightmapWidth & 0xFFFFFFFC;
  switch ( result->m_MaxLightmapWidth & 3 )
  {
    case 0:
      goto LABEL_7;
    case 1:
      m_MaxLightmapHeight = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: result);
      break;
    case 2:
      m_MaxLightmapHeight = (GMemoryHeap *)result->m_MaxLightmapHeight;
      break;
    default:
      break;
  }
  if ( m_MaxLightmapHeight != GMemory::pGlobalHeap )
  {
    this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)GString::AllocDataCopy1(
                                                                     this,
                                                                     pheap: (CUtlBuffer *)GMemory::pGlobalHeap,
                                                                     size: *(_DWORD *)v4 & 0x7FFFFFFF,
                                                                     lengthIsSize: *(_DWORD *)v4 & 0x80000000,
                                                                     src: (unsigned __int8 *)(v4 + 8),
                                                                     copySize: *(_DWORD *)v4 & 0x7FFFFFFF);
    return this;
  }
  else
  {
LABEL_7:
    this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)v4;
    InterlockedExchangeAdd(Addend: (volatile LONG *)(v4 + 4), Value: 1);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074BC0
// Name: public: GString::GString(class GStringBuffer const __near &)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ **__thiscall GString::GString(VertexShaderHandle_t__ **this, const CImagePacker *result)
{
  unsigned int m_MaxLightmapHeight; // esi
  VertexShaderHandle_t__ *v4; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  VertexShaderHandle_t__ *v6; // eax
  int v8; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *src; // [esp+18h] [ebp+8h]

  m_MaxLightmapHeight = result->m_MaxLightmapHeight;
  src = (unsigned __int8 *)result->m_MaxLightmapWidth;
  if ( src == nullptr )
    src = (unsigned __int8 *)&pMem;
  if ( m_MaxLightmapHeight != 0 )
  {
    Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
    v8 = 5;
    v6 = (VertexShaderHandle_t__ *)Alloc_2(
                                     this: GMemory::pGlobalHeap,
                                     a2: m_MaxLightmapHeight + 12,
                                     a3: (const GAllocDebugInfo *)&v8);
    *((_BYTE *)v6 + m_MaxLightmapHeight + 8) = 0;
    *((_DWORD *)v6 + 1) = 1;
    *(_DWORD *)v6 = m_MaxLightmapHeight;
    v4 = v6;
  }
  else
  {
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    v4 = &GString::NullData;
  }
  memcpy(dst: (unsigned __int8 *)v4 + 8, src, count: m_MaxLightmapHeight);
  *this = v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074C50
// Name: public: class GString GString::operator+(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__thiscall GString::operator+(
        CImagePacker *result,
        CUtlMemory<CImagePacker,int> *a2,
        CImagePacker *putf8str)
{
  CImagePacker *v3; // eax

  GString::GString(this: (CCountedStringPoolBase<unsigned int> *)a2, result);
  v3 = putf8str;
  if ( putf8str == nullptr )
    v3 = (CImagePacker *)&pMem;
  GString::AppendString(this: a2, putf8str: v3, utf8StrSz: -1);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10074C80
// Name: public: class GString GString::operator+(class GString const __near &)const
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall GString::operator+(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this,
        CCountedStringPoolBase<unsigned int> *src,
        int *a3)
{
  int v4; // [esp+0h] [ebp-4h]

  GString::GString(this: src, result: (CImagePacker *)this);
  GString::operator+=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)src,
    src: a3,
    srcSize: v4);
  return src;
}

//------------------------------------------------------------------------------
// Address: 0x10074CB0
// Name: public: class GString GString::Substring(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GString::Substring(GString *this, GString *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // esi
  int v5; // edi
  unsigned int Length; // eax
  int *v7; // esi
  char *v9; // esi
  unsigned int ByteIndex; // eax

  v4 = this->HeapTypeBits & 0xFFFFFFFC;
  v5 = *(_DWORD *)v4 & 0x7FFFFFFF;
  if ( *(int *)v4 >= 0 )
  {
    Length = GUTF8Util::GetLength(length: (const char *)(v4 + 8), buflen: v5);
    if ( Length == v5 )
      *(_DWORD *)v4 |= 0x80000000;
  }
  else
  {
    Length = *(_DWORD *)v4 & 0x7FFFFFFF;
  }
  if ( a3 >= Length || a3 >= a4 )
  {
    a2->HeapTypeBits = (unsigned int)&GString::NullData;
    InterlockedExchangeAdd(Addend: &Addend, Value: 1);
    return (struct GString)a2;
  }
  else
  {
    v7 = (int *)(this->HeapTypeBits & 0xFFFFFFFC);
    if ( *v7 >= 0 )
    {
      v9 = (char *)v7 + GUTF8Util::GetByteIndex() + 8;
      ByteIndex = GUTF8Util::GetByteIndex();
      GString::GString(this: a2, src: v9, count: ByteIndex);
    }
    else
    {
      GString::GString(this: a2, src: (char *)v7 + a3 + 8, count: a4 - a3);
    }
    return (struct GString)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074D80
// Name: public: class GString GString::ToUpper(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__thiscall GString::ToUpper(
        CUtlMemory<CImagePacker,int> *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  unsigned int Char; // eax
  const CFileSystemPassThru *v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // eax
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+8h] [ebp-20Ch] BYREF
  int bufferOffset; // [esp+Ch] [ebp-208h] BYREF
  int putf8str[128]; // [esp+10h] [ebp-204h] BYREF

  putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))(((int)this->m_pMemory
                                                                                       & 0xFFFFFFFC)
                                                                                      + 8);
  a2->m_pMemory = (CImagePacker *)&GString::NullData;
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  bufferOffset = 0;
  do
  {
    do
    {
      Char = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
      v4 = Char;
      if ( Char == 0 )
        break;
      G_towupper(charCode: v3, charCodea: Char);
      GUTF8Util::EncodeChar(a1: (char *)putf8str, a2: &bufferOffset, a3: v5);
    }
    while ( bufferOffset < 504 );
    GString::AppendString(this: a2, (CImagePacker *)putf8str, utf8StrSz: bufferOffset);
    bufferOffset = 0;
  }
  while ( v4 != 0 );
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10074E40
// Name: public: class GString GString::ToLower(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__thiscall GString::ToLower(
        CUtlMemory<CImagePacker,int> *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  unsigned int Char; // eax
  const CFileSystemPassThru *v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // eax
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+8h] [ebp-20Ch] BYREF
  int bufferOffset; // [esp+Ch] [ebp-208h] BYREF
  int putf8str[128]; // [esp+10h] [ebp-204h] BYREF

  putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))(((int)this->m_pMemory
                                                                                       & 0xFFFFFFFC)
                                                                                      + 8);
  a2->m_pMemory = (CImagePacker *)&GString::NullData;
  InterlockedExchangeAdd(Addend: &Addend, Value: 1);
  bufferOffset = 0;
  do
  {
    do
    {
      Char = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
      v4 = Char;
      if ( Char == 0 )
        break;
      G_towlower(charCode: v3, charCodea: Char);
      GUTF8Util::EncodeChar(a1: (char *)putf8str, a2: &bufferOffset, a3: v5);
    }
    while ( bufferOffset < 504 );
    GString::AppendString(this: a2, (CImagePacker *)putf8str, utf8StrSz: bufferOffset);
    bufferOffset = 0;
  }
  while ( v4 != 0 );
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1013ECD0
// Name: public: int GString::CompareNoCase(class GString const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GString::CompareNoCase(CUtlMemory<CImagePacker,int> *this, _DWORD *a2)
{
  return GString::CompareNoCase(
           a1: (char *)(((int)this->m_pMemory & 0xFFFFFFFC) + 8),
           a2: (char *)((*a2 & 0xFFFFFFFC) + 8));
}
