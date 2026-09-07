// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gheapallocbitset2mh.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gheapallocbitset2mh.h"

//------------------------------------------------------------------------------
// Address: 0x10144160
// Name: public: static struct GHeapBinNodeMH __near * GHeapBinNodeMH::MakeNode(unsigned char __near *,unsigned int,struct GHeapPageMH __near *)
// Source: json
//------------------------------------------------------------------------------
static unsigned __int8 *__cdecl GHeapBinNodeMH::MakeNode(
        unsigned __int8 *start,
        unsigned int bytes,
        struct GHeapPageMH *a3)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi
  unsigned int v5; // edx

  result = start;
  v4 = &start[4 * (bytes >> 2) - 8];
  *(_DWORD *)start ^= ((unsigned __int8)(bytes >> 4) ^ (unsigned __int8)*(_DWORD *)start) & 0xF;
  *(_DWORD *)v4 = *(_DWORD *)start;
  v5 = (bytes >> 8) | *((_DWORD *)start + 1) & 0xFFFFFFF0;
  *((_DWORD *)start + 1) = v5;
  *((_DWORD *)v4 + 1) = v5;
  if ( (*(_DWORD *)start & 0xF | (16 * (*((_DWORD *)start + 1) & 0xFu))) > 1 )
    *((_DWORD *)start + 2) = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101441C0
// Name: public: static void GHeapBitSet2::MarkBusy(unsigned long __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapBitSet2::MarkBusy(const char *buf, const char *start, unsigned int num, unsigned int numa)
{
  unsigned int v4; // esi
  unsigned int v5; // edx
  const char *v6; // eax
  unsigned int v7; // ecx

  v4 = numa;
  switch ( numa )
  {
    case 0u:
    case 1u:
      *(_DWORD *)&start[4 * (num >> 4)] = (1 << ((2 * num) & 0x1E))
                                        | *(_DWORD *)&start[4 * (num >> 4)] & ~(3 << ((2 * num) & 0x1E));
      return;
    case 2u:
      v5 = num;
      v6 = start;
      *(_DWORD *)&start[4 * (num >> 4)] = (2 << ((2 * num) & 0x1E))
                                        | *(_DWORD *)&start[4 * (num >> 4)] & ~(3 << ((2 * num) & 0x1E));
      goto LABEL_8;
    case 3u:
    case 4u:
    case 5u:
      v5 = num;
      v6 = start;
      *(_DWORD *)&start[4 * (num >> 4)] = (3 << ((2 * num) & 0x1E))
                                        | *(_DWORD *)&start[4 * (num >> 4)] & ~(3 << ((2 * num) & 0x1E));
      *(_DWORD *)&start[4 * ((num + 1) >> 4)] = ((numa - 3) << ((2 * (num + 1)) & 0x1E))
                                              | *(_DWORD *)&start[4 * ((num + 1) >> 4)]
                                              & ~(3 << ((2 * (num + 1)) & 0x1E));
      goto LABEL_8;
    default:
      v5 = num;
      v6 = start;
      *(_DWORD *)&start[4 * (num >> 4)] = (3 << ((2 * num) & 0x1E))
                                        | *(_DWORD *)&start[4 * (num >> 4)] & ~(3 << ((2 * num) & 0x1E));
      *(_DWORD *)&start[4 * ((num + 1) >> 4)] = (3 << ((2 * (num + 1)) & 0x1E))
                                              | *(_DWORD *)&start[4 * ((num + 1) >> 4)]
                                              & ~(3 << ((2 * (num + 1)) & 0x1E));
      v7 = num + 2;
      if ( numa >= 0x26 )
      {
        *(_DWORD *)&start[4 * (v7 >> 4)] = (3 << ((2 * v7) & 0x1E))
                                         | *(_DWORD *)&start[4 * (v7 >> 4)] & ~(3 << ((2 * v7) & 0x1E));
        *(_DWORD *)&start[4 * ((2 * num + 37) >> 5)] = numa;
      }
      else
      {
        *(_DWORD *)&start[4 * (v7 >> 4)] = ((numa - 6) >> 4 << ((2 * num + 4) & 0x1E))
                                         | *(_DWORD *)&start[4 * (v7 >> 4)] & ~(3 << ((2 * num + 4) & 0x1E));
        *(_DWORD *)&start[4 * ((num + 3) >> 4)] = *(_DWORD *)&start[4 * ((num + 3) >> 4)]
                                                & ~(3 << ((2 * num + 6) & 0x1E))
                                                | ((((numa - 6) >> 2) & 3) << ((2 * num + 6) & 0x1E));
        v4 = numa;
        *(_DWORD *)&start[4 * ((num + 4) >> 4)] = (((numa - 6) & 3) << ((2 * (num + 4)) & 0x1E))
                                                | *(_DWORD *)&start[4 * ((num + 4) >> 4)]
                                                & ~(3 << ((2 * (num + 4)) & 0x1E));
      }
LABEL_8:
      *(_DWORD *)&v6[4 * ((v5 + v4 - 1) >> 4)] = (1 << ((2 * (v5 + v4 - 1)) & 0x1E))
                                               | *(_DWORD *)&v6[4 * ((v5 + v4 - 1) >> 4)]
                                               & ~(3 << ((2 * (v5 + v4 - 1)) & 0x1E));
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101443E0
// Name: public: static unsigned int GHeapBitSet2::GetBlockSize(unsigned long const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __cdecl GHeapBitSet2::GetBlockSize(const unsigned int *a1, unsigned int a2)
{
  unsigned int result; // eax
  unsigned int v3; // eax
  unsigned int v4; // esi

  result = (a1[a2 >> 4] >> ((2 * a2) & 0x1E)) & 3;
  if ( result == 3 )
  {
    v3 = (a1[(a2 + 1) >> 4] >> ((2 * a2 + 2) & 0x1E)) & 3;
    if ( v3 == 3 )
    {
      v4 = (a1[(a2 + 2) >> 4] >> ((2 * a2 + 4) & 0x1E)) & 3;
      if ( v4 == 3 )
        return a1[(2 * a2 + 37) >> 5];
      else
        return ((a1[(a2 + 4) >> 4] >> ((2 * a2 + 8) & 0x1E)) & 3
              | (4 * ((4 * v4) | (a1[(a2 + 3) >> 4] >> ((2 * a2 + 6) & 0x1E)) & 3)))
             + 6;
    }
    else
    {
      return v3 + 3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101444A0
// Name: public: GHeapAllocBitSet2MH::GHeapAllocBitSet2MH(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocBitSet2MH::GHeapAllocBitSet2MH(CBufferedLoggingListener *this)
{
  GHeapListBinMH::GHeapListBinMH((GHeapListBinMH *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101444B0
// Name: public: void GHeapAllocBitSet2MH::InitPage(struct GHeapPageMH __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CBufferedLoggingListener *__thiscall GHeapAllocBitSet2MH::InitPage(
        CBufferedLoggingListener *this,
        CBufferedLoggingListener *page,
        unsigned __int8 *end2)
{
  CBufferedLoggingListener *result; // eax
  int v4; // esi
  int v5; // edx
  CBufferedLoggingListener *v6; // ebx
  int v7; // edi
  unsigned int v8; // ebx
  _DWORD *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // esi
  unsigned __int8 *v12; // ecx
  unsigned int v13; // ebx
  int v14; // esi
  _DWORD *v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned __int8 *v18; // edx
  unsigned int v19; // esi
  int v20; // [esp+Ch] [ebp-24h] BYREF
  int v21; // [esp+10h] [ebp-20h]
  unsigned __int8 *dst; // [esp+14h] [ebp-1Ch]
  int v23; // [esp+18h] [ebp-18h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-14h]
  unsigned int v25; // [esp+20h] [ebp-10h]
  unsigned __int8 *v26; // [esp+28h] [ebp-8h]
  GHeapListBinMH *v27; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *end2a; // [esp+3Ch] [ebp+Ch]

  v27 = (GHeapListBinMH *)this;
  GHeapGetMagicHeaders(
    pageStart: (bool (__cdecl *)(const char *const *, const char *const *))page,
    pageStarta: page->m_StoredSpew.m_Memory.m_nGrowSize,
    headers: &v20);
  memset(dst, value: 0x55u, count: 0x40u);
  result = (CBufferedLoggingListener *)v20;
  v4 = 0;
  if ( v20 != 0 )
  {
    *(_WORD *)v20 = 24512;
    *(_WORD *)(v20 + 2) = 0;
    *(_DWORD *)(v20 + 4) = end2;
    *(_DWORD *)(v20 + 8) = 0;
    result = (CBufferedLoggingListener *)v20;
  }
  v5 = v21;
  if ( v21 != 0 )
  {
    *(_WORD *)v21 = 24512;
    *(_WORD *)(v21 + 2) = 0;
    *(_DWORD *)(v21 + 4) = end2;
    *(_DWORD *)(v21 + 8) = 0;
    v5 = v21;
    result = (CBufferedLoggingListener *)v20;
  }
  v6 = nullptr;
  v7 = 0;
  end2a = nullptr;
  if ( result != nullptr )
  {
    v4 = v23;
    v6 = result;
  }
  if ( v5 != 0 )
  {
    v7 = v5 + 16;
    end2a = v24;
  }
  if ( (unsigned int)dst >= v25 )
    v7 += 64;
  else
    v6 = (CBufferedLoggingListener *)((char *)v6 - 64);
  if ( v4 != 0 )
  {
    v8 = (unsigned int)v6 - v4;
    *(_DWORD *)v4 ^= ((unsigned __int8)(v8 >> 4) ^ (unsigned __int8)*(_DWORD *)v4) & 0xF;
    v9 = (_DWORD *)(v4 + 4 * (v8 >> 2) - 8);
    *v9 = *(_DWORD *)v4;
    v10 = *(_DWORD *)(v4 + 4) & 0xFFFFFFF0 | (v8 >> 8);
    *(_DWORD *)(v4 + 4) = v10;
    v9[1] = v10;
    if ( (*(_DWORD *)v4 & 0xF | (16 * (*(_DWORD *)(v4 + 4) & 0xFu))) > 1 )
      *(_DWORD *)(v4 + 8) = page;
    GHeapListBinMH::Push(this: v27, a2: (unsigned __int8 *)v4);
    v11 = (v4 - v23) >> 4;
    v26 = dst;
    v12 = dst;
    v13 = ((int)v8 >> 4) + v11 - 1;
    *(_DWORD *)&dst[4 * (v11 >> 4)] &= ~(3 << ((2 * v11) & 0x1E));
    result = (CBufferedLoggingListener *)&v12[4 * (v13 >> 4)];
    result->__vftable = (CBufferedLoggingListener_vtbl *)((int)result->__vftable & ~(3 << ((2 * v13) & 0x1E)));
  }
  if ( v7 != 0 )
  {
    v14 = (int)&end2a[-v7];
    v15 = (_DWORD *)(v7 + 4 * ((unsigned int)&end2a[-v7] >> 2) - 8);
    *(_DWORD *)v7 ^= ((unsigned __int8)((unsigned int)&end2a[-v7] >> 4) ^ (unsigned __int8)*(_DWORD *)v7) & 0xF;
    *v15 = *(_DWORD *)v7;
    v16 = ((unsigned int)&end2a[-v7] >> 8) | *(_DWORD *)(v7 + 4) & 0xFFFFFFF0;
    *(_DWORD *)(v7 + 4) = v16;
    v15[1] = v16;
    if ( (*(_DWORD *)v7 & 0xF | (16 * (*(_DWORD *)(v7 + 4) & 0xFu))) > 1 )
      *(_DWORD *)(v7 + 8) = page;
    GHeapListBinMH::Push(this: v27, a2: (unsigned __int8 *)v7);
    v17 = (v7 - v23) >> 4;
    v18 = dst;
    v19 = (v14 >> 4) + v17 - 1;
    *(_DWORD *)&dst[4 * (v17 >> 4)] &= ~(3 << ((2 * v17) & 0x1E));
    result = (CBufferedLoggingListener *)&v18[4 * (v19 >> 4)];
    result->__vftable = (CBufferedLoggingListener_vtbl *)((int)result->__vftable & ~(3 << ((2 * v19) & 0x1E)));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101446B0
// Name: public: void GHeapAllocBitSet2MH::ReleasePage(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocBitSet2MH::ReleasePage(CBufferedLoggingListener *this, unsigned __int8 *start)
{
  unsigned __int8 *v3; // eax
  int v4; // [esp+4h] [ebp-1Ch] BYREF
  int v5; // [esp+8h] [ebp-18h]
  unsigned int v6; // [esp+Ch] [ebp-14h]
  unsigned __int8 *v7; // [esp+10h] [ebp-10h]
  unsigned int v8; // [esp+18h] [ebp-8h]

  GHeapGetMagicHeaders(
    pageStart: (bool (__cdecl *)(const char *const *, const char *const *))start,
    pageStarta: (unsigned int)start,
    headers: &v4);
  if ( v4 != 0 )
    GHeapListBinMH::Pull((GHeapListBinMH *)this, a2: v7);
  if ( v5 != 0 )
  {
    v3 = (unsigned __int8 *)(v5 + 16);
    if ( v6 > v8 )
      v3 = (unsigned __int8 *)(v5 + 80);
    GHeapListBinMH::Pull((GHeapListBinMH *)this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144700
// Name: public: void __near * GHeapAllocBitSet2MH::Alloc(unsigned int,struct GHeapMagicHeadersInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocBitSet2MH::Alloc(IShaderDLLInternal *this, unsigned int bytes, _DWORD *headers)
{
  struct GHeapBinNodeMH *v3; // esi
  int v4; // ecx
  __int32 v5; // edi
  _DWORD *v6; // ebx
  unsigned int v7; // ecx
  char *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // ecx
  int v12; // edx
  unsigned int v13; // eax
  int v15; // [esp+Ch] [ebp-8h]
  __int32 v16; // [esp+10h] [ebp-4h]

  v3 = GHeapListBinMH::PullBest((GHeapListBinMH *)this, a2: bytes >> 4);
  if ( v3 != nullptr )
  {
    v4 = *(_DWORD *)v3 & 0xF;
    if ( (v4 | (16 * (*((_DWORD *)v3 + 1) & 0xFu))) <= 1 || (v5 = *((_DWORD *)v3 + 2), v16 = v5, v5 == 0) )
    {
      v16 = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: (int)v3);
      v5 = v16;
    }
    v6 = headers;
    GHeapGetMagicHeaders(
      pageStart: (bool (__cdecl *)(const char *const *, const char *const *))v4,
      pageStarta: *(_DWORD *)(v5 + 12),
      headers);
    headers[6] = v5;
    v7 = 16 * (*(_DWORD *)v3 & 0xF | (16 * (*((_DWORD *)v3 + 1) & 0xF))) - bytes;
    if ( v7 != 0 )
    {
      v8 = (char *)v3 + bytes;
      v9 = v7 >> 2;
      v10 = (16 * (*(_DWORD *)v3 & 0xF | (16 * (*((_DWORD *)v3 + 1) & 0xF))) - bytes) >> 4;
      *(_DWORD *)v8 ^= ((unsigned __int8)v10 ^ (unsigned __int8)*(_DWORD *)((char *)v3 + bytes)) & 0xF;
      *(_DWORD *)&v8[4 * v9 - 8] = *(_DWORD *)v8;
      v15 = (int)v3 + 4 * v9 + bytes - 8;
      v11 = *(_DWORD *)((_BYTE *)v3 + bytes + 4) & 0xFFFFFFF0 | (v10 >> 4);
      *((_DWORD *)v8 + 1) = v11;
      *(_DWORD *)(v15 + 4) = v11;
      if ( (*(_DWORD *)((_BYTE *)v3 + bytes) & 0xF | (16 * (*(_DWORD *)((_BYTE *)v3 + bytes + 4) & 0xFu))) > 1 )
        *((_DWORD *)v8 + 2) = v16;
      GHeapListBinMH::Push((GHeapListBinMH *)this, a2: (unsigned __int8 *)v8);
      v12 = headers[2];
      v13 = (int)((int)v3 + bytes - headers[3]) >> 4;
      *(_DWORD *)(v12 + 4 * (v13 >> 4)) &= ~(3 << ((2 * v13) & 0x1E));
      v6 = headers;
      *(_DWORD *)(v12 + 4 * ((v10 + v13 - 1) >> 4)) &= ~(3 << ((2 * (v10 + v13 - 1)) & 0x1E));
    }
    GHeapBitSet2::MarkBusy(
      buf: (const char *)(bytes >> 4),
      start: (const char *)v6[2],
      num: ((int)v3 - v6[3]) >> 4,
      numa: bytes >> 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144860
// Name: public: void GHeapAllocBitSet2MH::Free(struct GHeapPageMH __near *,void __near *,struct GHeapMagicHeadersInfo __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocBitSet2MH::Free(
        IShaderDLLInternal *this,
        int page,
        bool (__cdecl *left)(const char *const *, const char *const *),
        _DWORD *right,
        _DWORD *a5)
{
  int v6; // ebx
  const unsigned int *v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // edx
  _DWORD *v10; // eax
  bool v11; // al
  unsigned int v12; // edx
  unsigned int v13; // ecx
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned int blocks; // [esp+10h] [ebp-8h]
  bool right_3; // [esp+2Bh] [ebp+13h]

  GHeapGetMagicHeaders(
    pageStart: (bool (__cdecl *)(const char *const *, const char *const *))this,
    pageStarta: *(_DWORD *)(page + 12),
    headers: right);
  v6 = (int)left;
  v7 = (const unsigned int *)right[2];
  right[6] = page;
  v8 = ((int)left - right[3]) >> 4;
  blocks = GHeapBitSet2::GetBlockSize(a1: v7, a2: v8);
  v9 = 16 * blocks;
  *a5 = 16 * blocks;
  v14 = right[2];
  *(_DWORD *)(v14 + 4 * (v8 >> 4)) &= ~(3 << ((2 * v8) & 0x1E));
  v10 = (_DWORD *)(v14 + 4 * ((v8 + blocks - 1) >> 4));
  *v10 &= ~(3 << ((2 * (v8 + blocks) - 2) & 0x1E));
  right_3 = (unsigned int)left + 16 * blocks < right[4];
  if ( v8 == 0
    || (LOBYTE(left) = 1, ((*(_DWORD *)(right[2] + 4 * ((v8 - 1) >> 4)) >> ((2 * (v8 - 1)) & 0x1E)) & 3) != 0) )
  {
    LOBYTE(left) = 0;
  }
  v11 = right_3 && ((*(_DWORD *)(right[2] + 4 * ((v8 + blocks) >> 4)) >> ((2 * (v8 + blocks)) & 0x1E)) & 3) == 0;
  if ( ((unsigned __int8)left | v11) != 0 )
  {
    GHeapListBinMH::Merge((CUtlMap<char const *,IShader *,unsigned short> *)this, node: v6, bytes: v9, left);
  }
  else
  {
    *(_DWORD *)v6 ^= ((unsigned __int8)blocks ^ (unsigned __int8)*(_DWORD *)v6) & 0xF;
    v12 = v9 >> 2;
    *(_DWORD *)(v6 + 4 * v12 - 8) = *(_DWORD *)v6;
    v13 = ((blocks & 0xFFFFFFF) >> 4) | *(_DWORD *)(v6 + 4) & 0xFFFFFFF0;
    *(_DWORD *)(v6 + 4) = v13;
    *(_DWORD *)(v6 + 4 * v12 - 8 + 4) = v13;
    if ( (*(_DWORD *)v6 & 0xF | (16 * (*(_DWORD *)(v6 + 4) & 0xFu))) > 1 )
      *(_DWORD *)(v6 + 8) = page;
    GHeapListBinMH::Push((GHeapListBinMH *)this, a2: (unsigned __int8 *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101449D0
// Name: public: unsigned int GHeapAllocBitSet2MH::GetUsableSize(struct GHeapPageMH const __near *,void const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocBitSet2MH::GetUsableSize(
        IShaderDLLInternal *this,
        bool (__cdecl *pageStart)(const char *const *, const char *const *),
        ButtonCode_t ptr)
{
  unsigned int *v3[7]; // [esp+0h] [ebp-1Ch] BYREF

  GHeapGetMagicHeaders(pageStart, pageStarta: *((_DWORD *)pageStart + 3), headers: v3);
  GHeapBitSet2::GetBlockSize(a1: v3[2], a2: (signed __int32)(ptr - (unsigned int)v3[3]) >> 4);
}

//------------------------------------------------------------------------------
// Address: 0x10144A10
// Name: public: void __near * GHeapAllocBitSet2MH::Alloc(unsigned int,unsigned int,struct GHeapMagicHeadersInfo __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GHeapAllocBitSet2MH::Alloc(
        GHeapListBinMH *this,
        unsigned int a2,
        unsigned int a3,
        struct GHeapMagicHeadersInfo *a4)
{
  const CUtlMap<char const *,IShader *,unsigned short> *v4; // eax
  CUtlMap<char const *,IShader *,unsigned short> *v5; // esi
  __int32 m_nAllocationCount; // edi
  bool (__cdecl *v8)(const char *const *, const char *const *); // ecx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // esi
  unsigned __int8 *v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // edi
  unsigned int v19; // ecx
  int v20; // edx
  unsigned int v21; // eax
  unsigned int v23; // [esp+Ch] [ebp-Ch]
  __int32 v25; // [esp+14h] [ebp-4h]
  unsigned __int8 *AlignedPtr; // [esp+24h] [ebp+Ch]
  struct GHeapMagicHeadersInfo *v27; // [esp+28h] [ebp+10h]

  v4 = GHeapListBinMH::PullBest(result: (const CUtlMap<char const *,IShader *,unsigned short> *)(a2 >> 4));
  v5 = (CUtlMap<char const *,IShader *,unsigned short> *)v4;
  if ( v4 == nullptr )
    return nullptr;
  if ( ((int)v4->m_Tree.m_LessFunc.m_LessFunc & 0xF | (16 * ((int)v4->m_Tree.m_Elements.m_pMemory & 0xFu))) <= 1
    || (m_nAllocationCount = v4->m_Tree.m_Elements.m_nAllocationCount, v25 = m_nAllocationCount, m_nAllocationCount == 0) )
  {
    v25 = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: (int)v4);
    m_nAllocationCount = v25;
  }
  AlignedPtr = GHeapListBinMH::GetAlignedPtr(a1: (unsigned __int8 *)v5, a2: a3 - 1);
  GHeapGetMagicHeaders(pageStart: v8, pageStarta: *(_DWORD *)(m_nAllocationCount + 12), headers: a4);
  *((_DWORD *)a4 + 6) = m_nAllocationCount;
  v9 = (unsigned int)v5
     + 16 * ((int)v5->m_Tree.m_LessFunc.m_LessFunc & 0xF | (16 * ((int)v5->m_Tree.m_Elements.m_pMemory & 0xF)))
     - (_DWORD)AlignedPtr
     - a2;
  v10 = AlignedPtr - (unsigned __int8 *)v5;
  if ( AlignedPtr != (unsigned __int8 *)v5 )
  {
    v27 = (struct GHeapMagicHeadersInfo *)((char *)v5 + 4 * (v10 >> 2) - 8);
    v11 = v10 >> 4;
    v12 = (int)v5->m_Tree.m_LessFunc.m_LessFunc
        ^ ((unsigned __int8)(v10 >> 4)
         ^ (unsigned __int8)v5->m_Tree.m_LessFunc.m_LessFunc)
        & 0xF;
    v5->m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v12;
    *(_DWORD *)v27 = v12;
    v23 = v11;
    v13 = (v11 >> 4) | (int)v5->m_Tree.m_Elements.m_pMemory & 0xFFFFFFF0;
    v5->m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *)v13;
    *((_DWORD *)v27 + 1) = v13;
    if ( ((int)v5->m_Tree.m_LessFunc.m_LessFunc & 0xF | (16 * ((int)v5->m_Tree.m_Elements.m_pMemory & 0xFu))) > 1 )
      v5->m_Tree.m_Elements.m_nAllocationCount = v25;
    GHeapListBinMH::Push(this, a2: (unsigned __int8 *)v5);
    v14 = *((_DWORD *)a4 + 2);
    v15 = ((int)v5 - *((_DWORD *)a4 + 3)) >> 4;
    *(_DWORD *)(v14 + 4 * (v15 >> 4)) &= ~(3 << ((2 * v15) & 0x1E));
    *(_DWORD *)(v14 + 4 * ((v23 + v15 - 1) >> 4)) &= ~(3 << ((2 * (v23 + v15 - 1)) & 0x1E));
  }
  if ( v9 != 0 )
  {
    v16 = &AlignedPtr[a2];
    v17 = v9 >> 4;
    *(_DWORD *)v16 ^= ((unsigned __int8)(v9 >> 4) ^ (unsigned __int8)*(_DWORD *)&AlignedPtr[a2]) & 0xF;
    v18 = v9 >> 2;
    *(_DWORD *)&v16[4 * v18 - 8] = *(_DWORD *)v16;
    v19 = (v17 >> 4) | *(_DWORD *)&AlignedPtr[a2 + 4] & 0xFFFFFFF0;
    *((_DWORD *)v16 + 1) = v19;
    *(_DWORD *)&AlignedPtr[4 * v18 - 4 + a2] = v19;
    if ( (*(_DWORD *)&AlignedPtr[a2] & 0xF | (16 * (*(_DWORD *)&AlignedPtr[a2 + 4] & 0xFu))) > 1 )
      *((_DWORD *)v16 + 2) = v25;
    GHeapListBinMH::Push(this, a2: v16);
    v20 = *((_DWORD *)a4 + 2);
    v21 = (int)&AlignedPtr[a2 - *((_DWORD *)a4 + 3)] >> 4;
    *(_DWORD *)(v20 + 4 * (v21 >> 4)) &= ~(3 << ((2 * v21) & 0x1E));
    *(_DWORD *)(v20 + 4 * ((v17 + v21 - 1) >> 4)) &= ~(3 << ((2 * (v17 + v21 - 1)) & 0x1E));
  }
  GHeapBitSet2::MarkBusy(
    buf: (const char *)(a2 >> 4),
    start: *((const char **)a4 + 2),
    num: (int)&AlignedPtr[-*((_DWORD *)a4 + 3)] >> 4,
    numa: a2 >> 4);
  return AlignedPtr;
}

//------------------------------------------------------------------------------
// Address: 0x10144C30
// Name: public: void __near * GHeapAllocBitSet2MH::ReallocInPlace(struct GHeapPageMH __near *,void __near *,unsigned int,unsigned int __near *,struct GHeapMagicHeadersInfo __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GHeapAllocBitSet2MH::ReallocInPlace(
        IShaderDLLInternal *this,
        int a2,
        unsigned __int8 *oldPtr,
        unsigned int newSize,
        _DWORD *thisTail,
        _DWORD *tailBytes)
{
  unsigned __int8 *v7; // edx
  unsigned int v8; // ecx
  const unsigned int *v9; // ebx
  unsigned int BlockSize; // eax
  int v11; // esi
  int v12; // ecx
  bool v13; // zf
  unsigned int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // esi
  unsigned __int8 *v18; // esi
  unsigned int v19; // ecx
  int v20; // edx
  const char *v21; // ecx
  unsigned int v22; // esi
  const unsigned int *v23; // ebx
  unsigned __int8 *base; // [esp+10h] [ebp-Ch]
  int start; // [esp+14h] [ebp-8h]
  unsigned int tailBytesa; // [esp+34h] [ebp+18h]
  unsigned int tailBytesb; // [esp+34h] [ebp+18h]
  unsigned int tailBytesc; // [esp+34h] [ebp+18h]
  unsigned int tailBytesd; // [esp+34h] [ebp+18h]

  GHeapGetMagicHeaders(
    pageStart: (bool (__cdecl *)(const char *const *, const char *const *))this,
    pageStarta: *(_DWORD *)(a2 + 12),
    headers: tailBytes);
  v7 = (unsigned __int8 *)tailBytes[3];
  tailBytesa = tailBytes[4];
  v8 = tailBytes[5];
  tailBytes[6] = a2;
  base = v7;
  if ( (unsigned int)oldPtr < v8 )
  {
    tailBytesa = v8 - 16;
    if ( tailBytes[2] < v8 )
      tailBytesa = v8 - 80;
  }
  v9 = (const unsigned int *)tailBytes[2];
  start = (oldPtr - v7) >> 4;
  BlockSize = GHeapBitSet2::GetBlockSize(a1: v9, a2: start);
  v11 = 16 * BlockSize;
  *thisTail = 16 * BlockSize;
  if ( newSize <= 16 * BlockSize )
  {
    if ( newSize < 16 * BlockSize )
    {
      v18 = &oldPtr[v11];
      v19 = 16 * BlockSize - newSize;
      v20 = 0;
      if ( (unsigned int)v18 < tailBytesa )
      {
        if ( ((v9[(start + BlockSize) >> 4] >> ((2 * (start + BlockSize)) & 0x1E)) & 3) == 0 )
          v20 = 16 * (*(_DWORD *)v18 & 0xF | (16 * (*((_DWORD *)v18 + 1) & 0xF)));
        v19 = 16 * BlockSize - newSize;
      }
      tailBytesd = v20 + v19;
      if ( v20 + v19 != 0 )
      {
        if ( v20 != 0 )
          GHeapListBinMH::Pull((GHeapListBinMH *)this, a2: v18);
        GHeapBinNodeMH::MakeNode(start: &oldPtr[newSize], bytes: tailBytesd, a3: (struct GHeapPageMH *)a2);
        GHeapListBinMH::Push((GHeapListBinMH *)this, a2: &oldPtr[newSize]);
        GHeapBitSet2::MarkBusy(buf: v21, start: (const char *)v9, num: start, numa: newSize >> 4);
        v22 = (&oldPtr[newSize] - base) >> 4;
        v9[v22 >> 4] &= ~(3 << ((2 * v22) & 0x1E));
        v23 = &v9[((tailBytesd >> 4) + v22 - 1) >> 4];
        *v23 &= ~(3 << ((2 * ((tailBytesd >> 4) + v22 - 1)) & 0x1E));
      }
    }
    return oldPtr;
  }
  else
  {
    if ( (unsigned int)&oldPtr[v11] >= tailBytesa )
      return nullptr;
    if ( ((v9[(start + BlockSize) >> 4] >> ((2 * (start + BlockSize)) & 0x1E)) & 3) != 0 )
      return nullptr;
    tailBytesb = 16 * (*(_DWORD *)&oldPtr[v11] & 0xF | (16 * (*(_DWORD *)&oldPtr[v11 + 4] & 0xF)));
    if ( newSize > v11 + tailBytesb )
    {
      return nullptr;
    }
    else
    {
      GHeapListBinMH::Pull((GHeapListBinMH *)this, a2: &oldPtr[v11]);
      v13 = v11 + tailBytesb - newSize == 0;
      v14 = v11 + tailBytesb - newSize;
      tailBytesc = v14;
      if ( !v13 )
      {
        GHeapBinNodeMH::MakeNode(start: &oldPtr[newSize], bytes: v14, a3: (struct GHeapPageMH *)a2);
        GHeapListBinMH::Push((GHeapListBinMH *)this, a2: &oldPtr[newSize]);
        v15 = (&oldPtr[newSize] - base) >> 4;
        v9[v15 >> 4] &= ~(3 << ((2 * v15) & 0x1E));
        v16 = (tailBytesc >> 4) + v15 - 1;
        v12 = (2 * (_BYTE)v16) & 0x1E;
        v9[v16 >> 4] &= ~(3 << v12);
      }
      GHeapBitSet2::MarkBusy(buf: (const char *)v12, start: (const char *)v9, num: start, numa: newSize >> 4);
      return oldPtr;
    }
  }
}
