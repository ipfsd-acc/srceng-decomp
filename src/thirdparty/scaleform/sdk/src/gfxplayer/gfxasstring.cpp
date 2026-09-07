// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxasstring.cpp
// Functions: 25
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxasstring.h"

//------------------------------------------------------------------------------
// Address: 0x1007E940
// Name: public: unsigned int GASString::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASString::GetLength(const char ***this)
{
  const char *v2; // esi
  int result; // eax

  v2 = (*this)[4];
  if ( ((unsigned int)(*this)[3] & 0x8000000) != 0 )
    return (int)(*this)[4];
  result = GUTF8Util::GetLength(length: **this, buflen: (int)(*this)[4]);
  if ( (const char *)result == v2 )
    (*this)[3] = (const char *)((unsigned int)(*this)[3] | 0x8000000);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E970
// Name: public: unsigned long GASString::GetCharAt(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GASString::GetCharAt(unsigned int **this, unsigned int index)
{
  unsigned int *v2; // eax
  unsigned int result; // eax
  signed int v4; // esi

  v2 = *this;
  if ( ((*this)[3] & 0x8000000) != 0 )
    return *(char *)(*v2 + index);
  v4 = index;
  index = *v2;
  while ( 1 )
  {
    result = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&index);
    --v4;
    if ( result == 0 )
      break;
    if ( v4 < 0 )
      return result;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007E9C0
// Name: public: int GASString::LocaleCompare_CaseCheck(char const __near *,unsigned int,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASString::LocaleCompare_CaseCheck(
        CUtlMap<char const *,int,unsigned short>::CKeyLess **this,
        bool (__cdecl *a2)(const char *const *, const char *const *),
        unsigned int len,
        bool caseSensitive)
{
  unsigned int v4; // esi
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v6; // eax
  int m_LessFunc; // edi
  unsigned int v8; // ebx
  int Length; // eax
  wchar_t *v10; // edi
  wchar_t *v11; // esi
  int v12; // eax
  int v13; // ebx
  int v15; // [esp+8h] [ebp-400h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess v16; // [esp+Ch] [ebp-3FCh]
  int v17; // [esp+10h] [ebp-3F8h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess **v18; // [esp+14h] [ebp-3F4h]
  unsigned int v19; // [esp+18h] [ebp-3F0h]
  _BYTE v20[500]; // [esp+1Ch] [ebp-3ECh] BYREF
  _BYTE v21[500]; // [esp+210h] [ebp-1F8h] BYREF

  v4 = len;
  v18 = this;
  v16.m_LessFunc = a2;
  v19 = len;
  if ( len == -1 )
  {
    v19 = strlen((const char *)a2);
    v4 = v19;
  }
  v6 = *this;
  m_LessFunc = (int)(*this)[4].m_LessFunc;
  if ( ((int)(*this)[3].m_LessFunc & 0x8000000) != 0 )
  {
    v8 = (unsigned int)v6[4].m_LessFunc;
  }
  else
  {
    Length = GUTF8Util::GetLength(length: (const char *)v6->m_LessFunc, buflen: m_LessFunc);
    if ( Length == m_LessFunc )
      (*this)[3].m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((int)(*this)[3].m_LessFunc
                                                                                         | 0x8000000);
    v8 = Length;
  }
  if ( v8 < 0xFA )
  {
    v10 = (wchar_t *)v21;
  }
  else
  {
    v15 = 2;
    v10 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * v8 + 2, a3: &v15);
  }
  if ( v4 < 0xFA )
  {
    v11 = (wchar_t *)v20;
  }
  else
  {
    v17 = 2;
    v11 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * v4 + 2, a3: &v17);
  }
  GUTF8Util::DecodeString(
    pbegin: v10,
    putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)(*v18)->m_LessFunc,
    length: v8);
  GUTF8Util::DecodeString(pbegin: v11, putf8Buffer: v16, length: v19);
  if ( caseSensitive )
    v12 = wcscoll(_string1: v10, _string2: v11);
  else
    v12 = _wcsicoll(_string1: v10, _string2: v11);
  v13 = v12;
  if ( v10 != (wchar_t *)v21 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
  if ( v11 != (wchar_t *)v20 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB30
// Name: private: void GASStringManager::AllocateStringNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::AllocateStringNodes(GASStringManager *this)
{
  int v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int i; // edx
  _DWORD *v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 3);
  v7 = 323;
  v3 = (_DWORD *)(*(int (__thiscall **)(int, int, int, int *))(*(_DWORD *)v2 + 36))(a1: v2, a2: 1008, a3: 1024, a4: &v7);
  if ( v3 != nullptr )
  {
    v3[1] = *((_DWORD *)this + 5);
    *v3 = this;
    *((_DWORD *)this + 5) = v3;
    v4 = v3 + 8;
    for ( i = 10; i != 0; --i )
    {
      *(v4 - 6) = 0;
      *(v4 - 5) = *((_DWORD *)this + 4);
      *((_DWORD *)this + 4) = v4 - 6;
      *(v4 - 1) = 0;
      *v4 = *((_DWORD *)this + 4);
      *((_DWORD *)this + 4) = v4 - 1;
      v4[4] = 0;
      v4[5] = *((_DWORD *)this + 4);
      *((_DWORD *)this + 4) = v4 + 4;
      v4[9] = 0;
      v4[10] = *((_DWORD *)this + 4);
      *((_DWORD *)this + 4) = v4 + 9;
      v6 = v4 + 14;
      v4[14] = 0;
      v4[15] = *((_DWORD *)this + 4);
      v4 += 25;
      *((_DWORD *)this + 4) = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EBE0
// Name: private: void GASStringManager::AllocateTextBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::AllocateTextBuffers(GASStringManager *this)
{
  int v2; // ecx
  int v3; // eax
  unsigned int v4; // ecx
  _DWORD *v5; // eax
  int i; // edi
  _DWORD *v7; // edx
  _DWORD *v8; // ecx
  int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 3);
  v9 = 323;
  v3 = (*(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40))(a1: v2, a2: 2032, a3: &v9);
  v4 = (v3 + 7) & 0xFFFFFFF8;
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 2020) = v3;
    *(_DWORD *)(v4 + 2016) = *((_DWORD *)this + 7);
    *((_DWORD *)this + 7) = v4;
    v5 = (_DWORD *)(v4 + 24);
    for ( i = 28; i != 0; --i )
    {
      *(v5 - 6) = *((_DWORD *)this + 6);
      *(v5 - 3) = v5 - 6;
      *v5 = v5 - 3;
      v5[3] = v5;
      v7 = v5 + 6;
      v5[6] = v5 + 3;
      v8 = v5 + 9;
      v5 += 18;
      *v8 = v7;
      *((_DWORD *)this + 6) = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EC60
// Name: private: char __near * GASStringManager::AllocTextBuffer(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GASStringManager::AllocTextBuffer(
        unsigned __int8 **this,
        unsigned __int8 *src,
        unsigned int length)
{
  unsigned int v3; // ebx
  unsigned __int8 **v5; // eax
  unsigned __int8 *v6; // esi
  int v7; // ecx

  v3 = length;
  if ( length >= 0xC )
  {
    v7 = (int)*(this + 3);
    length = 323;
    v6 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, unsigned int *))(*(_DWORD *)v7 + 40))(
                              a1: v7,
                              a2: v3 + 1,
                              a3: &length);
  }
  else
  {
    if ( *(this + 6) == nullptr )
      GASStringManager::AllocateTextBuffers((GASStringManager *)this);
    v5 = (unsigned __int8 **)*(this + 6);
    v6 = nullptr;
    if ( v5 != nullptr )
    {
      v6 = *(this + 6);
      *(this + 6) = *v5;
    }
  }
  if ( v6 != nullptr )
  {
    memcpy(dst: v6, src, count: v3);
    v6[v3] = 0;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECD0
// Name: private: void GASStringManager::FreeStringNode(struct GASStringNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::FreeStringNode(GASStringManager *this, void **a2)
{
  _DWORD *v2; // eax

  v2 = *a2;
  if ( *a2 != nullptr )
  {
    if ( ((unsigned int)a2[3] & 0x40000000) == 0 )
    {
      if ( (unsigned int)a2[4] >= 0xC )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *a2);
      }
      else
      {
        *v2 = *((_DWORD *)this + 6);
        *((_DWORD *)this + 6) = v2;
      }
    }
    *a2 = nullptr;
  }
  a2[1] = *((void **)this + 4);
  *((_DWORD *)this + 4) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED20
// Name: public: void GASStringManager::SetLeakReportLog(class GFxLog __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::SetLeakReportLog(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this,
        IShaderDevice *a2,
        char *a3)
{
  IShaderAPI *v4; // ecx
  unsigned __int8 *v5; // eax

  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2);
  v4 = *((IShaderAPI **)this + 9);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = (unsigned __int8 *)a3;
  *((_DWORD *)this + 9) = a2;
  if ( a3 == nullptr )
    v5 = (unsigned __int8 *)&pMem;
  GString::operator=(this: this + 2, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1007F130
// Name: public: void GASStringNode::ReleaseNode(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__fastcall GASStringNode::ReleaseNode(int a1)
{
  int v2; // ecx
  _DWORD *v4; // edi
  _DWORD *result; // eax
  int prevIndex; // [esp+8h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 != a1 && v2 != 0 && (*(_DWORD *)(v2 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  v4 = *(_DWORD **)(a1 & 0xFFFFFC00);
  prevIndex = a1;
  GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::RemoveAlt<GASStringNode *>(
    this: v4 + 2,
    &prevIndex);
  result = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 != 0 )
  {
    if ( (*(_DWORD *)(a1 + 12) & 0x40000000) == 0 )
    {
      if ( *(_DWORD *)(a1 + 16) >= 0xCu )
      {
        result = (_DWORD *)((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                             a1: GMemory::pGlobalHeap,
                             a2: *(_DWORD *)a1);
      }
      else
      {
        *result = v4[6];
        v4[6] = result;
      }
    }
    *(_DWORD *)a1 = 0;
  }
  *(_DWORD *)(a1 + 4) = v4[4];
  v4[4] = a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F1B0
// Name: private: struct GASStringNode __near * GASStringManager::CreateConstStringNode(char const __near *,unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__thiscall GASStringManager::CreateConstStringNode(
        GASStringManager *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        unsigned int a3,
        unsigned int a4)
{
  int v5; // edi
  int v6; // eax
  CResourceStream *v7; // ebx
  int v8; // edi
  int Index; // eax
  struct GASStringNode *v10; // eax
  _DWORD *v11; // esi
  _DWORD v12[3]; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v13; // [esp+18h] [ebp-8h] BYREF
  GASStringManager *v14; // [esp+1Ch] [ebp-4h]

  v14 = this;
  v12[0] = result;
  v12[2] = a3;
  v5 = GString::BernsteinHashFunctionCIS(
         result,
         size: a3,
         seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
  v6 = *((_DWORD *)this + 2);
  v7 = (CResourceStream *)((char *)this + 8);
  v8 = v5 & 0xFFFFFF;
  v12[1] = v8;
  if ( v6 != 0
    && (Index = GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::findIndexCore<GASStringKey>(
                  this: (int *)this + 2,
                  a2: (int)v12,
                  a3: v8 & *(_DWORD *)(v6 + 4))) >= 0 )
  {
    v10 = *(struct GASStringNode **)&v7->m_pData[8 * Index + 12];
    *((_DWORD *)v10 + 3) |= a4;
  }
  else
  {
    if ( *((_DWORD *)this + 4) == 0 )
      GASStringManager::AllocateStringNodes(this);
    v11 = *((_DWORD **)this + 4);
    if ( v11 != nullptr )
      *((_DWORD *)v14 + 4) = v11[1];
    v13 = v11;
    if ( v11 != nullptr )
    {
      v11[2] = 0;
      v11[4] = a3;
      *v11 = result;
      v11[3] = a4 | v8 | 0x40000000;
      v11[1] = 0;
      GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::add<GASStringNode *>(
        this: v7,
        pmemAddr: (const GFxFontProvider *)v7,
        a3: &v13,
        hashValue: v11[3]);
      return (struct GASStringNode *)v11;
    }
    else
    {
      return *((struct GASStringNode **)v14 + 8);
    }
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1007F290
// Name: private: struct GASStringNode __near * GASStringManager::CreateStringNode(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__thiscall GASStringManager::CreateStringNode(
        GASStringManager *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        unsigned int length)
{
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int Index; // eax
  int v9; // esi
  int v10; // ecx
  _IMAGE_VXD_HEADER *key; // [esp+Ch] [ebp-10h] BYREF
  int v12; // [esp+10h] [ebp-Ch]
  unsigned int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h] BYREF

  key = (_IMAGE_VXD_HEADER *)result;
  v4 = GString::BernsteinHashFunctionCIS(
         result,
         size: length,
         seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
  v5 = *((_DWORD *)this + 2);
  v6 = v4 & 0xFFFFFF;
  v12 = v6;
  v13 = length;
  if ( v5 != 0 )
  {
    Index = GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::findIndexCore<GASStringKey>(
              this: (int *)this + 2,
              a2: (int)&key,
              a3: v6 & *(_DWORD *)(v5 + 4));
    if ( Index >= 0 )
      return *(struct GASStringNode **)(*((_DWORD *)this + 2) + 8 * Index + 12);
  }
  if ( *((_DWORD *)this + 4) == 0 )
    GASStringManager::AllocateStringNodes(this);
  v9 = *((_DWORD *)this + 4);
  if ( v9 != 0 )
    *((_DWORD *)this + 4) = *(_DWORD *)(v9 + 4);
  v14 = v9;
  if ( v9 != 0 )
  {
    *(_DWORD *)v9 = GASStringManager::AllocTextBuffer((unsigned __int8 **)this, src: (unsigned __int8 *)result, length);
    if ( *(_DWORD *)v9 != 0 )
    {
      v10 = v12;
      *(_DWORD *)(v9 + 8) = 0;
      *(_DWORD *)(v9 + 16) = length;
      *(_DWORD *)(v9 + 12) = v10;
      *(_DWORD *)(v9 + 4) = 0;
      GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::add<GASStringNode *>(
        this: (CResourceStream *)((char *)this + 8),
        pmemAddr: (const GFxFontProvider *)((char *)this + 8),
        a3: &v14,
        hashValue: *(_DWORD *)(v9 + 12));
      return (struct GASStringNode *)v9;
    }
    GASStringManager::FreeStringNode(this, a2: (void **)v9);
  }
  return *((struct GASStringNode **)this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x1007F370
// Name: private: struct GASStringNode __near * GASStringManager::CreateStringNode(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::CreateStringNode(
        GASStringManager *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result)
{
  if ( result != nullptr )
    GASStringManager::CreateStringNode(this, result, length: strlen((const char *)result));
}

//------------------------------------------------------------------------------
// Address: 0x1007F3B0
// Name: private: struct GASStringNode __near * GASStringManager::CreateStringNode(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__thiscall GASStringManager::CreateStringNode(GASStringManager *this, RGB888_t *pwstr)
{
  struct GASStringNode *StringNode; // eax
  void *v4; // esi
  struct GASStringNode *v5; // edi
  unsigned int v7; // [esp+8h] [ebp-4h] BYREF

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v7);
  GString::operator=(this: &v7, a2: pwstr);
  StringNode = GASStringManager::CreateStringNode(
                 this,
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v7 & 0xFFFFFFFC) + 8),
                 length: *(_DWORD *)(v7 & 0xFFFFFFFC) & 0x7FFFFFFF);
  v4 = (void *)(v7 & 0xFFFFFFFC);
  v5 = StringNode;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v7 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1007F420
// Name: private: struct GASStringNode __near * GASStringManager::CreateStringNode(char const __near *,unsigned int,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__thiscall GASStringManager::CreateStringNode(
        GASStringManager *this,
        char *src,
        unsigned __int8 **count,
        char *a4,
        unsigned int a5)
{
  unsigned int v5; // esi
  GASStringManager *v6; // ebx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  int v9; // ecx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // ecx
  CResourceStream *v13; // ebx
  int v14; // eax
  int Index; // eax
  int v16; // ebx
  GASStringManager *v17; // eax
  GASStringManager *v19; // esi
  unsigned __int8 **v20; // esi
  GASStringManager *v21; // eax
  unsigned int v22; // eax
  unsigned __int8 *v23; // edx
  GASStringManager *v24; // ebx
  unsigned __int8 *v25; // [esp+Ch] [ebp-18h] BYREF
  int v26; // [esp+10h] [ebp-14h]
  unsigned int v27; // [esp+14h] [ebp-10h]
  int v28; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  GASStringManager *v30; // [esp+20h] [ebp-4h]

  v5 = (unsigned int)count + a5;
  v6 = this;
  v30 = this;
  v29 = (unsigned int)count + a5;
  if ( (unsigned int)count + a5 >= 0xC )
  {
    v9 = *((_DWORD *)this + 3);
    v28 = 323;
    v7 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v9 + 40))(
                              a1: v9,
                              a2: v5 + 1,
                              a3: &v28);
    goto LABEL_7;
  }
  if ( *((_DWORD *)this + 6) == 0 )
    GASStringManager::AllocateTextBuffers(this);
  v7 = *((unsigned __int8 **)v6 + 6);
  v8 = nullptr;
  if ( v7 != nullptr )
  {
    *((_DWORD *)v6 + 6) = *(_DWORD *)v7;
LABEL_7:
    v8 = v7;
  }
  if ( v8 == nullptr )
    return *((unsigned __int8 ***)v6 + 8);
  v10 = (unsigned int)count;
  if ( count != nullptr )
  {
    memcpy(dst: v8, (unsigned __int8 *)src, (unsigned int)count);
    v10 = (unsigned int)count;
  }
  if ( a5 != 0 )
    memcpy(dst: &v8[v10], src: (unsigned __int8 *)a4, count: a5);
  v8[v5] = 0;
  v25 = v8;
  v11 = GString::BernsteinHashFunctionCIS(
          result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v8,
          size: v5,
          seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
  v12 = *((_DWORD *)v6 + 2);
  v13 = (CResourceStream *)((char *)v6 + 8);
  v14 = v11 & 0xFFFFFF;
  v26 = v14;
  v27 = v5;
  if ( v12 == 0
    || (Index = GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::findIndexCore<GASStringKey>(
                  this: (int *)v13,
                  a2: (int)&v25,
                  a3: v14 & *(_DWORD *)(v12 + 4))) < 0 )
  {
    v19 = v30;
    if ( *((_DWORD *)v30 + 4) == 0 )
      GASStringManager::AllocateStringNodes(this: v30);
    v20 = *((unsigned __int8 ***)v19 + 4);
    v21 = v30;
    if ( v20 != nullptr )
      *((_DWORD *)v30 + 4) = v20[1];
    count = v20;
    if ( v20 != nullptr )
    {
      v22 = v29;
      v23 = (unsigned __int8 *)v26;
      v20[2] = nullptr;
      v20[4] = (unsigned __int8 *)v22;
      *v20 = v8;
      v20[3] = v23;
      v20[1] = nullptr;
      GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::add<GASStringNode *>(
        this: v13,
        pmemAddr: (const GFxFontProvider *)v13,
        a3: &count,
        hashValue: (unsigned int)v20[3]);
      return v20;
    }
    if ( v29 < 0xC )
    {
      v24 = v30;
      *(_DWORD *)v8 = *((_DWORD *)v21 + 6);
      *((_DWORD *)v21 + 6) = v8;
      return *((unsigned __int8 ***)v24 + 8);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    v6 = v30;
    return *((unsigned __int8 ***)v6 + 8);
  }
  v16 = *(_DWORD *)&v13->m_pData[8 * Index + 12];
  if ( v5 >= 0xC )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  }
  else
  {
    v17 = v30;
    *(_DWORD *)v8 = *((_DWORD *)v30 + 6);
    *((_DWORD *)v17 + 6) = v8;
  }
  return (unsigned __int8 **)v16;
}

//------------------------------------------------------------------------------
// Address: 0x1007F5C0
// Name: public: class GASString GASString::AppendChar(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 ***__thiscall GASString::AppendChar(char ***this, unsigned __int8 ***a2, unsigned int a3)
{
  unsigned __int8 **StringNode; // eax
  unsigned int v6; // [esp+8h] [ebp-10h] BYREF
  char v7[8]; // [esp+Ch] [ebp-Ch] BYREF

  v6 = 0;
  GUTF8Util::EncodeChar(a1: v7, a2: (int *)&v6, a3);
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                 src: **this,
                 count: (unsigned __int8 **)(*this)[4],
                 a4: v7,
                 a5: v6);
  *a2 = StringNode;
  ++StringNode[2];
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007F630
// Name: public: class GASString GASString::Substring(int,int)const
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__thiscall GASString::Substring(_DWORD **this, struct GASStringNode **a2, int start, int end)
{
  int v5; // ecx
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  int v7; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // ebx
  bool (__cdecl *v9)(const char *const *, const char *const *); // edi
  unsigned int Char; // eax
  struct GASStringNode *StringNode; // eax
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+4h] [ebp-4h] BYREF

  if ( start == end )
  {
    v5 = *(_DWORD *)(*(_DWORD *)((unsigned int)*this & 0xFFFFFC00) + 32);
    ++*(_DWORD *)(v5 + 8);
    *a2 = (struct GASStringNode *)v5;
    return a2;
  }
  else
  {
    m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))**this;
    v7 = 0;
    putf8Buffer.m_LessFunc = m_LessFunc;
    v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)m_LessFunc;
    v9 = m_LessFunc;
    while ( 1 )
    {
      if ( v7 == start )
        v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)m_LessFunc;
      Char = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
      if ( ++v7 == end )
        break;
      if ( Char == 0 )
      {
        if ( v7 >= end )
          goto LABEL_11;
        break;
      }
      m_LessFunc = putf8Buffer.m_LessFunc;
    }
    v9 = putf8Buffer.m_LessFunc;
LABEL_11:
    if ( (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v9 < v8 )
      v9 = (bool (__cdecl *)(const char *const *, const char *const *))v8;
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                   result: v8,
                   length: (char *)v9 - (char *)v8);
    ++*((_DWORD *)StringNode + 2);
    *a2 = StringNode;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F6D0
// Name: public: class GASString GASString::ToUpper(void)const
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__thiscall GASString::ToUpper(int **this, struct GASStringNode **a2)
{
  CUtlMemory<CImagePacker,int> *v3; // eax
  void *v4; // esi
  struct GASStringNode *StringNode; // eax
  void *v6; // esi
  volatile LONG *v8; // [esp-8h] [ebp-1Ch]
  GString v9; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h] BYREF

  v3 = (CUtlMemory<CImagePacker,int> *)GString::GString(this: &v9, src: **this);
  GString::ToUpper(this: v3, a2: (CUtlMemory<CImagePacker,int> *)&v10);
  v4 = (void *)(v9.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v10 & 0xFFFFFFFC) + 8),
                 length: *(_DWORD *)(v10 & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++*((_DWORD *)StringNode + 2);
  v6 = (void *)(v10 & 0xFFFFFFFC);
  v8 = (volatile LONG *)((v10 & 0xFFFFFFFC) + 4);
  *a2 = StringNode;
  if ( InterlockedExchangeAdd(Addend: v8, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007F770
// Name: public: void GASString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode *__thiscall GASString::operator=(
        int *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result)
{
  struct GASStringNode *StringNode; // eax
  struct GASStringNode *v4; // esi
  int v5; // ecx

  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)(*this & 0xFFFFFC00),
                 result,
                 length: strlen((const char *)result));
  v4 = StringNode;
  ++*((_DWORD *)StringNode + 2);
  v5 = *this;
  if ( (*(_DWORD *)(*this + 8))-- == 1 )
    StringNode = (struct GASStringNode *)GASStringNode::ReleaseNode(a1: v5);
  *this = (int)v4;
  return StringNode;
}

//------------------------------------------------------------------------------
// Address: 0x1007F7C0
// Name: public: void GASString::operator+=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char **__thiscall GASString::operator+=(char ***this, char *a2)
{
  char **result; // eax
  char **v4; // esi
  char **v5; // ecx

  result = (char **)GASStringManager::CreateStringNode(
                      this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                      src: **this,
                      count: (unsigned __int8 **)(*this)[4],
                      a4: a2,
                      a5: strlen(a2));
  v4 = result;
  ++result[2];
  v5 = *this;
  if ( (*this)[2]-- == (char *)1 )
    result = (char **)GASStringNode::ReleaseNode(a1: (int)v5);
  *this = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F810
// Name: public: class GASString GASString::operator+(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
tagEMRALPHABLEND *__thiscall GASString::operator+(char ***this, tagEMRALPHABLEND *result, char *a3)
{
  unsigned __int8 **StringNode; // eax

  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                 src: **this,
                 count: (unsigned __int8 **)(*this)[4],
                 a4: a3,
                 a5: strlen(a3));
  ++StringNode[2];
  result->emr.iType = (unsigned int)StringNode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F860
// Name: public: class GASString GASString::operator+(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 ***__thiscall GASString::operator+(char ***this, unsigned __int8 ***a2, _IMAGE_SYMBOL_EX *str)
{
  unsigned __int8 **StringNode; // eax

  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)((unsigned int)*this & 0xFFFFFC00),
                 src: **this,
                 count: (unsigned __int8 **)(*this)[4],
                 a4: *(char **)str->N.Name.Short,
                 a5: *(_DWORD *)(str->N.Name.Short + 16));
  ++StringNode[2];
  *a2 = StringNode;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007F8A0
// Name: public: void GASStringNode::ResolveLowercase_Impl(void)
// Source: json
//------------------------------------------------------------------------------
void *__fastcall GASStringNode::ResolveLowercase_Impl(int *a1)
{
  CUtlMemory<CImagePacker,int> *v2; // eax
  void *v3; // esi
  int v4; // edx
  GASStringManager *v5; // esi
  struct GASStringNode *StringNode; // eax
  unsigned int v7; // esi
  void *result; // eax
  GString v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = (CUtlMemory<CImagePacker,int> *)GString::GString(this: &v9, src: *a1);
  GString::ToLower(this: v2, a2: (CUtlMemory<CImagePacker,int> *)&v10);
  v3 = (void *)(v9.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  v4 = v10;
  v5 = *(GASStringManager **)((unsigned int)a1 & 0xFFFFFC00);
  if ( (v10 & 0xFFFFFFFC) == 0xFFFFFFF8 )
  {
    StringNode = *((struct GASStringNode **)v5 + 8);
  }
  else
  {
    StringNode = GASStringManager::CreateStringNode(
                   this: v5,
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v10 & 0xFFFFFFFC) + 8),
                   length: (v10 & 0xFFFFFFFC)
                 + 8
                 + strlen((const char *)((v10 & 0xFFFFFFFC) + 8))
                 + 1
                 - ((v10 & 0xFFFFFFFC)
                  + 9));
    v4 = v10;
  }
  if ( StringNode != *((struct GASStringNode **)v5 + 8) )
  {
    a1[1] = (int)StringNode;
    if ( StringNode != (struct GASStringNode *)a1 )
    {
      ++*((_DWORD *)StringNode + 2);
      v4 = v10;
    }
  }
  v7 = v4 & 0xFFFFFFFC;
  result = (void *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((v4 & 0xFFFFFFFC) + 4), Value: -1) - 1);
  if ( result == nullptr )
    return ((_SID_AND_ATTRIBUTES (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v7).Sid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F960
// Name: public: GASStringManager::GASStringManager(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GASStringManager *__thiscall GASStringManager::GASStringManager(GASStringManager *this, struct GMemoryHeap *a2)
{
  int v3; // eax
  char *v4; // edi

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GASStringManager::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 9) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 40));
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  GASStringManager::AllocateStringNodes(this);
  v3 = *((_DWORD *)this + 4);
  if ( v3 != 0 )
    *((_DWORD *)this + 4) = *(_DWORD *)(v3 + 4);
  v4 = (char *)this + 32;
  *((_DWORD *)this + 8) = v3;
  if ( v3 != 0 )
  {
    *(_DWORD *)(v3 + 8) = 1;
    *(_DWORD *)(*(_DWORD *)v4 + 16) = 0;
    *(_DWORD *)(*(_DWORD *)v4 + 12) = GString::BernsteinHashFunctionCIS(
                                        result: &pMem,
                                        size: 0,
                                        seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505)
                                    & 0xFFFFFF
                                    | 0xC0000000;
    **(_DWORD **)v4 = &pMem;
    *(_DWORD *)(*(_DWORD *)v4 + 4) = *(_DWORD *)v4;
  }
  GHashSetBase<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>,GASStringNodeHashFunc<GASStringNode *>,GAllocatorLH<GASStringNode *,323>,GHashsetEntry<GASStringNode *,GASStringNodeHashFunc<GASStringNode *>>>::add<GASStringNode *>(
    this: (CResourceStream *)((char *)this + 8),
    pmemAddr: (const GFxFontProvider *)((char *)this + 8),
    a3: (_DWORD *)this + 8,
    hashValue: *(_DWORD *)(*(_DWORD *)v4 + 12));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007FA10
// Name: public: virtual GASStringManager::~GASStringManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringManager::~GASStringManager(IShaderAPI *this)
{
  unsigned int v2; // ebx
  char **v3; // esi
  char *v4; // ecx
  char **v5; // esi
  char *v6; // eax
  char *v7; // eax
  IShaderAPI *v8; // eax
  IShaderAPI_vtbl *v9; // edx
  int v10; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // ecx
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // eax
  volatile LONG *v13; // esi
  IShaderAPI *v14; // ecx
  int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  bool v19; // zf
  _DWORD *v20; // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v21; // [esp+Ch] [ebp-20h] BYREF
  char **v22; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  this->__vftable = (IShaderAPI_vtbl *)&GASStringManager::`vftable';
  GStringBuffer::GStringBuffer(
    this: &v21,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  v2 = 0;
  while ( *((_DWORD *)this + 5) != 0 )
  {
    v3 = *((char ***)this + 5);
    v4 = v3[1];
    v22 = v3;
    *((_DWORD *)this + 5) = v4;
    v5 = v3 + 2;
    for ( i = 50; i != 0; --i )
    {
      if ( *v5 != nullptr && v5 != *((char ***)this + 8) )
      {
        if ( v2 < 0x10 )
        {
          v6 = ", '";
          if ( v2 == 0 )
            v6 = "'";
          GStringBuffer::AppendString(this: &v21, putf8str: v6, utf8StrSz: -1);
          GStringBuffer::AppendString(this: &v21, putf8str: *v5, utf8StrSz: -1);
          GStringBuffer::AppendString(this: &v21, putf8str: "'", utf8StrSz: -1);
        }
        ++v2;
        if ( ((unsigned int)v5[3] & 0x40000000) == 0 )
        {
          v7 = *v5;
          if ( (unsigned int)v5[4] >= 0xC )
          {
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v5);
          }
          else
          {
            *(IShaderAPI *)v7 = *(this + 6);
            *((_DWORD *)this + 6) = v7;
          }
        }
      }
      v5 += 5;
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
  }
  while ( *((_DWORD *)this + 7) != 0 )
  {
    v8 = *((IShaderAPI **)this + 7);
    v9 = v8[505].__vftable;
    *(this + 7) = v8[504];
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
  }
  if ( v2 != 0 )
  {
    v10 = *((_DWORD *)this + 9);
    if ( v10 != 0 )
    {
      GFxLogBase<GFxLog>::LogScriptError(
        this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((*(_DWORD *)(this + 10) & 0xFFFFFFFC) + 8),
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v10 + 12),
        this_4: (int)"ActionScript Memory leaks in movie '%s', including %d string nodes\n",
        this_8: (*(_DWORD *)(this + 10) & 0xFFFFFFFC) + 8);
      m_pfnProxied = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v21.m_pfnProxied;
      if ( LODWORD(v21.m_pfnProxied) == 0 )
        m_pfnProxied = &pMem;
      GFxLogBase<GFxLog>::LogScriptError(
        this: v11,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*((_DWORD *)this + 9) + 12),
        this_4: (int)"Leaked string content: %s\n",
        this_8: (int)m_pfnProxied);
    }
  }
  GStringBuffer::~GStringBuffer(this: &v21);
  v13 = (volatile LONG *)(*(_DWORD *)(this + 10) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v13 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v13);
  v14 = *((IShaderAPI **)this + 9);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  v15 = *((_DWORD *)this + 2);
  if ( v15 != 0 )
  {
    v16 = *(_DWORD *)(v15 + 4);
    v17 = 0;
    do
    {
      v18 = *((_DWORD *)this + 2);
      v19 = *(_DWORD *)(v18 + 8 * v17 + 8) == -2;
      v20 = (_DWORD *)(v18 + 8 * v17 + 8);
      if ( !v19 )
        *v20 = -2;
      ++v17;
    }
    while ( v17 <= v16 );
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2));
    *((_DWORD *)this + 2) = 0;
  }
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007FBE0
// Name: public: class GASString GASString::ToLower(void)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GASString::ToLower(int **this, int *a2)
{
  int *v3; // ecx
  int v4; // ecx

  v3 = *this;
  if ( v3[1] == 0 )
    GASStringNode::ResolveLowercase_Impl(a1: v3);
  v4 = (*this)[1];
  if ( v4 == 0 )
    v4 = *(_DWORD *)(*(_DWORD *)((unsigned int)*this & 0xFFFFFC00) + 32);
  ++*(_DWORD *)(v4 + 8);
  *a2 = v4;
  return a2;
}
