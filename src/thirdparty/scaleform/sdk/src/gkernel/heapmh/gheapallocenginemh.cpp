// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gheapallocenginemh.cpp
// Functions: 20
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gheapallocenginemh.h"

//------------------------------------------------------------------------------
// Address: 0x1006C8E0
// Name: public: struct GHeapNodeMH const __near * GRadixTree<struct GHeapNodeMH,struct GHeapTreeNodeAccessor>::FindGrEq(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(unsigned int *this, unsigned int a2)
{
  unsigned int result; // eax
  unsigned int j; // edi
  unsigned int v4; // edx
  unsigned int i; // edi
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]

  result = *this;
  j = 0;
  v4 = -1;
  v10 = 0;
  if ( *this == 0 )
    return j;
  v9 = 0;
  for ( i = a2; ; i *= 2 )
  {
    v6 = result - a2;
    if ( result >= a2 && v6 < v4 )
    {
      v10 = result;
      v4 = result - a2;
      if ( v6 == 0 )
        break;
    }
    v7 = *(_DWORD *)(result + 8);
    result = *(_DWORD *)(result + 4 * (i >> 31) + 4);
    if ( v7 != 0 && v7 != result )
      v9 = v7;
    if ( result == 0 )
    {
      v8 = v9;
      for ( j = v10; v8 != 0; v8 = *(_DWORD *)(v8 + 4 * (*(_DWORD *)(v8 + 4) == 0) + 4) )
      {
        if ( v8 >= a2 && v8 - a2 < v4 )
        {
          v4 = v8 - a2;
          j = v8;
        }
      }
      return j;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3390
// Name: public: void GHeapAllocEngineMH::GetPageInfo(struct GHeapPageMH __near *,struct GHeapPageInfoMH __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::GetPageInfo(
        GHeapAllocEngineMH *this,
        bool (__cdecl **a2)(const char *const *, const char *const *),
        struct GHeapPageInfoMH *a3)
{
  int v3; // [esp+8h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-18h]

  *(_DWORD *)a3 = 0;
  *((_DWORD *)a3 + 1) = 0;
  *((_DWORD *)a3 + 2) = 0;
  *((_DWORD *)a3 + 3) = 0;
  *((_DWORD *)a3 + 4) = 0;
  *((_DWORD *)a3 + 5) = 0;
  GHeapGetMagicHeaders(pageStart: a2[3]);
  if ( v3 != 0 )
    *(_DWORD *)a3 = v3 + 8;
  *((_DWORD *)a3 + 5) = 0;
  *((_DWORD *)a3 + 3) = a2;
  if ( v4 != 0 )
    *((_DWORD *)a3 + 1) = v4 + 8;
}

//------------------------------------------------------------------------------
// Address: 0x100D33F0
// Name: public: void GHeapAllocEngineMH::GetPageInfo(struct GHeapNodeMH __near *,struct GHeapPageInfoMH __near *)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHeapAllocEngineMH::GetPageInfo(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        _DWORD *a3)
{
  *a3 = 0;
  a3[1] = 0;
  a3[3] = 0;
  a3[2] = (char *)node + 16;
  a3[5] = 0;
  a3[4] = node;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x100D3420
// Name: public: void GHeapAllocEngineMH::GetPageInfoWithSize(struct GHeapPageMH __near *,void const __near *,struct GHeapPageInfoMH __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::GetPageInfoWithSize(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int a2,
        ButtonCode_t ptr,
        _DWORD *a4)
{
  int v5; // eax
  int v6; // [esp+Ch] [ebp-1Ch]
  int v7; // [esp+10h] [ebp-18h]

  *a4 = 0;
  a4[1] = 0;
  a4[2] = 0;
  a4[3] = 0;
  a4[4] = 0;
  a4[5] = 0;
  GHeapGetMagicHeaders(pageStart: *(bool (__cdecl **)(const char *const *, const char *const *))(a2 + 12));
  if ( v6 != 0 )
    *a4 = v6 + 8;
  if ( v7 != 0 )
    a4[1] = v7 + 8;
  GHeapAllocBitSet2MH::GetUsableSize(this: (IShaderDLLInternal *)this + 3);
  a4[3] = a2;
  a4[5] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D3490
// Name: public: void GHeapAllocEngineMH::GetPageInfoWithSize(struct GHeapNodeMH __near *,void const __near *,struct GHeapPageInfoMH __near *)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHeapAllocEngineMH::GetPageInfoWithSize(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        ButtonCode_t ptr,
        _DWORD *a4)
{
  *a4 = 0;
  a4[1] = 0;
  a4[3] = 0;
  a4[2] = (char *)node + 16;
  a4[4] = node;
  a4[5] = (char *)node - ptr;
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x100D34C0
// Name: public: void __near * GHeapAllocEngineMH::ReallocInPage(struct GHeapPageMH __near *,void __near *,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHeapAllocEngineMH::ReallocInPage(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        unsigned __int16 page,
        void *oldPtr,
        unsigned int oldSize,
        _DWORD *a5)
{
  int result; // eax
  unsigned int v7; // esi
  int v8; // [esp+4h] [ebp-1Ch]
  int v9; // [esp+8h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-4h]

  result = 0;
  if ( oldSize < 0x800 )
  {
    v7 = (oldSize + 15) & 0xFFFFFFF0;
    result = GHeapAllocBitSet2MH::ReallocInPlace(this: (IShaderDLLInternal *)this + 3);
    if ( result != 0 )
    {
      a5[2] = 0;
      a5[1] = 0;
      *a5 = 0;
      if ( v8 != 0 )
        *a5 = v8 + 8;
      if ( v9 != 0 )
        a5[1] = v9 + 8;
      a5[5] = v7;
      a5[3] = v10;
      a5[4] = 0;
      *((_DWORD *)this + 39) += v7 - oldSize;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3550
// Name: public: struct GHeapNodeMH __near * GHeapRootMH::AddToGlobalTree(unsigned char __near *,unsigned int,unsigned int,class GMemoryHeapMH __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GHeapRootMH::AddToGlobalTree(
        unsigned __int8 **this,
        unsigned __int8 *ptr,
        unsigned int size,
        unsigned int align,
        int a5)
{
  unsigned __int8 *result; // eax
  int v6; // edx
  unsigned __int8 **v7; // edx
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edi
  unsigned __int8 **v10; // esi

  result = &ptr[size];
  switch ( align )
  {
    case 1u:
    case 2u:
    case 4u:
      v6 = a5;
      break;
    case 8u:
      v6 = a5 | 1;
      break;
    case 0x10u:
      v6 = a5 | 2;
      break;
    default:
      v6 = a5 | 3;
      *((_DWORD *)result + 5) = align;
      break;
  }
  *((_DWORD *)result + 3) = v6;
  v7 = this + 10;
  *((_DWORD *)result + 4) = 0;
  *((_DWORD *)result + 2) = 0;
  *((_DWORD *)result + 1) = 0;
  *(_DWORD *)result = 0;
  v8 = *(this + 10);
  if ( v8 != nullptr )
  {
    v9 = (unsigned int)&ptr[size];
    if ( v8 != result )
    {
      while ( 1 )
      {
        v10 = (unsigned __int8 **)&v8[4 * (v9 >> 31) + 4];
        v9 *= 2;
        if ( *v10 == nullptr )
          break;
        v8 = *v10;
        if ( *v10 == result )
          return result;
      }
      *v10 = result;
      *(_DWORD *)result = v8;
    }
  }
  else
  {
    *v7 = result;
    *(_DWORD *)result = v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3620
// Name: public: GHeapAllocEngineMH::GHeapAllocEngineMH(class GSysAlloc __near *,class GMemoryHeapMH __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GHeapAllocEngineMH *__thiscall GHeapAllocEngineMH::GHeapAllocEngineMH(
        GHeapAllocEngineMH *this,
        IShaderDLLVerification *minAlignSize,
        struct GMemoryHeapMH *a3,
        unsigned int a4,
        unsigned int limit)
{
  unsigned int v6; // eax
  const LoggingContext_t *v8; // [esp+0h] [ebp-4h]
  const char *savedregs; // [esp+4h] [ebp+0h]

  *this = minAlignSize;
  v6 = a4;
  *((_DWORD *)this + 1) = a3;
  if ( a4 < 4 )
    v6 = 4;
  *((_DWORD *)this + 2) = v6;
  GHeapAllocBitSet2MH::GHeapAllocBitSet2MH(this: (CBufferedLoggingListener *)(this + 3), a2: v8, a3: savedregs);
  *((_DWORD *)this + 36) = this + 36;
  *((_DWORD *)this + 37) = this + 36;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 40) = limit;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D3680
// Name: private: void __near * GHeapAllocEngineMH::allocFromPage(unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::allocFromPage(int this, unsigned int result, _DWORD *a3)
{
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  int v7; // ecx
  char v8; // bl
  const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v9; // eax
  CBufferedLoggingListener *v10; // esi
  int v11; // [esp+Ch] [ebp-20h]
  int v12; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+24h] [ebp-8h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+28h] [ebp-4h]

  while ( 1 )
  {
    GHeapAllocBitSet2MH::Alloc(this: (IShaderDLLInternal *)(this + 12), bytes: result);
    if ( v4 != 0 )
      break;
    v5 = *(_DWORD *)(this + 160);
    if ( v5 != 0 && (v6 = *(_DWORD *)(this + 152)) + 4096 > v5 && (v7 = *(_DWORD *)(this + 164)) != 0 )
    {
      v8 = (*(int (__thiscall **)(int, _DWORD, unsigned int))(*(_DWORD *)v7 + 4))(
             a1: v7,
             a2: *(_DWORD *)(this + 4),
             a3: v6 - v5 + 4096);
    }
    else
    {
      v8 = 0;
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      v9 = GHeapRootMH::AllocPage(result: *(const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > **)(this + 4));
      v10 = (CBufferedLoggingListener *)v9;
      if ( v9 != nullptr )
      {
        GHeapRootMH::GetPageIndex(this: GHeapGlobalRootMH, page: (unsigned __int16)v9);
        GHeapAllocBitSet2MH::InitPage(this: (CBufferedLoggingListener *)(this + 12), page: v10);
        *(_DWORD *)(this + 152) += 4096;
        v10->m_StoredSpew.m_Memory.m_pMemory = *(unsigned __int8 **)(this + 148);
        v10->__vftable = (CBufferedLoggingListener_vtbl *)(this + 144);
        **(_DWORD **)(this + 148) = v10;
        *(_DWORD *)(this + 148) = v10;
        v8 = 1;
      }
      LeaveCriticalSection(lpCriticalSection);
    }
    if ( v8 == 0 )
      return;
  }
  a3[2] = 0;
  a3[1] = 0;
  *a3 = 0;
  if ( v11 != 0 )
  {
    ++*(_WORD *)(v11 + 2);
    *a3 = v11 + 8;
  }
  if ( v12 != 0 )
  {
    ++*(_WORD *)(v12 + 2);
    a3[1] = v12 + 8;
  }
  a3[5] = result;
  a3[3] = v13;
  a3[4] = 0;
  ++*(_DWORD *)(this + 168);
  *(_DWORD *)(this + 156) += result;
}

//------------------------------------------------------------------------------
// Address: 0x100D37D0
// Name: private: void __near * GHeapAllocEngineMH::allocFromPage(unsigned int,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GHeapAllocEngineMH::allocFromPage(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *size,
        unsigned int alignSize,
        _DWORD *a4)
{
  void *result; // eax
  unsigned int v6; // edx
  int v7; // eax
  int v8; // ecx
  char v9; // bl
  const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v10; // eax
  CBufferedLoggingListener *v11; // esi
  int v12; // edx
  int v13; // edx
  int v14; // [esp+Ch] [ebp-20h] BYREF
  int v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+24h] [ebp-8h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+28h] [ebp-4h]

  while ( 1 )
  {
    result = GHeapAllocBitSet2MH::Alloc(
               this: (GHeapAllocBitSet2MH *)(this + 1),
               a2: (unsigned int)size,
               a3: alignSize,
               a4: (struct GHeapMagicHeadersInfo *)&v14);
    if ( result != nullptr )
      break;
    v6 = *((_DWORD *)this + 40);
    if ( v6 != 0 && (v7 = *((_DWORD *)this + 38)) + 4096 > v6 && (v8 = *((_DWORD *)this + 41)) != 0 )
    {
      v9 = (*(int (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v8 + 4))(
             a1: v8,
             a2: this->m_nAllocationCount,
             a3: v7 - v6 + 4096);
    }
    else
    {
      v9 = 0;
      lpCriticalSection = (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      v10 = GHeapRootMH::AllocPage(result: (const CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this->m_nAllocationCount);
      v11 = (CBufferedLoggingListener *)v10;
      if ( v10 != nullptr )
      {
        GHeapRootMH::GetPageIndex(this: GHeapGlobalRootMH, page: (unsigned __int16)v10);
        GHeapAllocBitSet2MH::InitPage(this: (CBufferedLoggingListener *)(this + 1), page: v11);
        *((_DWORD *)this + 38) += 4096;
        v11->m_StoredSpew.m_Memory.m_pMemory = *((unsigned __int8 **)this + 37);
        v11->__vftable = (CBufferedLoggingListener_vtbl *)(this + 12);
        **((_DWORD **)this + 37) = v11;
        *((_DWORD *)this + 37) = v11;
        v9 = 1;
      }
      LeaveCriticalSection(lpCriticalSection);
    }
    if ( v9 == 0 )
      return nullptr;
  }
  v12 = v14;
  a4[2] = 0;
  a4[1] = 0;
  *a4 = 0;
  if ( v12 != 0 )
  {
    ++*(_WORD *)(v12 + 2);
    *a4 = v14 + 8;
  }
  if ( v15 != 0 )
  {
    ++*(_WORD *)(v15 + 2);
    a4[1] = v15 + 8;
  }
  v13 = v16;
  a4[5] = size;
  a4[3] = v13;
  a4[4] = 0;
  ++*((_DWORD *)this + 42);
  *((_DWORD *)this + 39) += size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D3920
// Name: public: void GHeapAllocEngineMH::Free(struct GHeapPageMH __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::Free(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMap<char const *,IShader *,unsigned short>::Node_t *page,
        unsigned int ptr)
{
  int v4; // eax
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]

  GHeapAllocBitSet2MH::Free(this: (IShaderDLLInternal *)this + 3, (int)page);
  *((_DWORD *)this + 39) -= ptr;
  v4 = 0;
  if ( v6 != 0 )
    v4 = (unsigned __int16)--*(_WORD *)(v6 + 2);
  if ( v7 != 0 )
    v4 = (unsigned __int16)--*(_WORD *)(v7 + 2);
  if ( v4 == 0 )
  {
    p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    GHeapAllocBitSet2MH::ReleasePage(this: (CBufferedLoggingListener *)(this + 1), start: (unsigned int)page[1].elem);
    *((_DWORD *)page->key + 1) = page->elem;
    page->elem->__vftable = (IShader_vtbl *)page->key;
    GHeapRootMH::FreePage(result: page);
    *((_DWORD *)this + 38) -= 4096;
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  }
  --*((_DWORD *)this + 42);
}

//------------------------------------------------------------------------------
// Address: 0x100D39E0
// Name: private: void __near * GHeapAllocEngineMH::allocDirect(unsigned int,unsigned int,bool __near *,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall GHeapAllocEngineMH::allocDirect(
        _DWORD *this,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result,
        unsigned int alignSize,
        bool *limHandlerOK,
        _DWORD *a5)
{
  unsigned int v5; // ebx
  unsigned int v7; // eax
  int v8; // edi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v9; // eax
  unsigned __int8 *v10; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *ptr; // [esp+14h] [ebp+8h]
  _RTL_CRITICAL_SECTION *alignSizea; // [esp+18h] [ebp+Ch]

  v5 = ((unsigned int)&result[1].index + 1) & 0xFFFFFFFC;
  v7 = *(this + 40);
  v8 = alignSize > 0x10 ? 24 : 20;
  if ( v7 != 0 && *(this + 38) + v8 + v5 > v7 && *(this + 41) != 0 )
  {
    alignSizea = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    *limHandlerOK = (*(int (__thiscall **)(_DWORD, _DWORD, unsigned int))(*(_DWORD *)*(this + 41) + 4))(
                      a1: *(this + 41),
                      a2: *(this + 1),
                      a3: *(this + 38) + v5 + v8 - *(this + 40));
    EnterCriticalSection(lpCriticalSection: alignSizea);
    return nullptr;
  }
  else
  {
    *limHandlerOK = false;
    v9 = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)(*(int (__thiscall **)(_DWORD, unsigned int, unsigned int))(*(_DWORD *)*this + 12))(a1: *this, a2: v8 + v5, a3: alignSize);
    ptr = v9;
    if ( v9 != nullptr )
    {
      v10 = GHeapRootMH::AddToGlobalTree(
              this: (unsigned __int8 **)GHeapGlobalRootMH,
              ptr: (unsigned __int8 *)v9,
              size: v5,
              align: alignSize,
              a5: *(this + 1));
      a5[4] = v10;
      a5[1] = 0;
      *a5 = 0;
      a5[2] = v10 + 16;
      a5[5] = v5;
      a5[3] = 0;
      ++*(this + 42);
      *(this + 38) += v5 + v8;
      *(this + 39) += v5;
      *limHandlerOK = true;
      return ptr;
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100D3AF0
// Name: public: void __near * GHeapAllocEngineMH::Alloc(unsigned int,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall GHeapAllocEngineMH::Alloc(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        ApplicationInstantCountersInfo_t *size,
        unsigned int limHandlerOK,
        _DWORD *a4)
{
  ApplicationInstantCountersInfo_t *v4; // edi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *v5; // esi
  unsigned int v6; // eax
  unsigned int v8; // ebx
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v9; // edi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v10; // esi
  ApplicationInstantCountersInfo_t *rl; // [esp+14h] [ebp+8h]

  v4 = size;
  v5 = this;
  if ( (unsigned int)size > 0x200 )
  {
    v8 = limHandlerOK;
    if ( limHandlerOK < 4 )
      v8 = 4;
    if ( (unsigned int)size < v8 )
      v4 = (ApplicationInstantCountersInfo_t *)v8;
    v9 = (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)(((unsigned int)&v4->m_nCpuActivityMask + 3) & 0xFFFFFFFC);
    rl = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    HIBYTE(limHandlerOK) = 0;
    while ( 1 )
    {
      v10 = GHeapAllocEngineMH::allocDirect(
              this: v5,
              result: v9,
              alignSize: v8,
              limHandlerOK: (bool *)&limHandlerOK + 3,
              a5: a4);
      if ( v10 != nullptr )
      {
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)rl);
        return v10;
      }
      if ( HIBYTE(limHandlerOK) == 0 )
        break;
      v5 = this;
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)rl);
    return nullptr;
  }
  else
  {
    v6 = limHandlerOK;
    if ( limHandlerOK < 0x10 )
      v6 = 16;
    return (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)GHeapAllocEngineMH::allocFromPage(this, size: (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)(((unsigned int)&size[1].m_nDeferredWordsAllocated + 3) & 0xFFFFFFF0), alignSize: v6, a4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3BB0
// Name: public: void GRadixTree<struct GHeapNodeMH,struct GHeapTreeNodeAccessor>::Remove(struct GHeapNodeMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::Remove(
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        unsigned __int16 a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // edx
  int v6; // edx
  _DWORD *v7; // ecx
  _DWORD *v8; // ecx

  v3 = *((_DWORD *)node + 2);
  v4 = (_DWORD *)((char *)node + 8);
  if ( v3 != 0 || (v3 = *((_DWORD *)node + 1), v4 = (_DWORD *)((char *)node + 4), v3 != 0) )
  {
    while ( 1 )
    {
      v5 = (_DWORD *)(v3 + 8);
      if ( *(_DWORD *)(v3 + 8) == 0 )
      {
        v5 = (_DWORD *)(v3 + 4);
        if ( *(_DWORD *)(v3 + 4) == 0 )
          break;
      }
      v3 = *v5;
      v4 = v5;
    }
    *v4 = 0;
  }
  v6 = *(_DWORD *)node;
  if ( *(_DWORD *)node != 0 )
  {
    if ( node == (int (__cdecl *)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *))this->m_LessFunc.m_LessFunc )
      this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v3;
    else
      *(_DWORD *)(v6 + 4 * (*(_DWORD *)(v6 + 4) != (_DWORD)node) + 4) = v3;
    if ( v3 != 0 )
    {
      *(_DWORD *)v3 = v6;
      v7 = *((_DWORD **)node + 1);
      if ( v7 != nullptr )
      {
        *(_DWORD *)(v3 + 4) = v7;
        *v7 = v3;
      }
      v8 = *((_DWORD **)node + 2);
      if ( v8 != nullptr )
      {
        *(_DWORD *)(v3 + 8) = v8;
        *v8 = v3;
      }
    }
  }
  *((_DWORD *)node + 2) = 0;
  *((_DWORD *)node + 1) = 0;
  *(_DWORD *)node = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D3C50
// Name: public: void GHeapAllocEngineMH::Free(struct GHeapNodeMH __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::Free(GHeapAllocEngineMH *this, struct GHeapNodeMH *node, _BYTE *a3)
{
  int v4; // eax
  unsigned int v5; // edi
  int v6; // ecx
  unsigned __int16 v7; // [esp+0h] [ebp-Ch]

  GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::Remove(
    this: (CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)GHeapGlobalRootMH + 40),
    (int (__cdecl *)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *))node,
    a3: v7);
  v4 = *((_DWORD *)node + 3) & 3;
  if ( v4 == 3 )
    v5 = *((_DWORD *)node + 5);
  else
    v5 = 1 << (v4 + 2);
  v6 = (int)*this;
  --*((_DWORD *)this + 42);
  *((_DWORD *)this + 38) -= (char *)node + (v5 > 0x10 ? 24 : 20) - (_DWORD)a3;
  *((_DWORD *)this + 39) += a3 - (_BYTE *)node;
  (*(void (__thiscall **)(int, _BYTE *, char *, unsigned int))(*(_DWORD *)v6 + 16))(
    a1: v6,
    a2: a3,
    a3: (char *)node + (v5 > 0x10 ? 24 : 20) - (_DWORD)a3,
    a4: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100D3CD0
// Name: public: void GHeapAllocEngineMH::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::Free(GHeapAllocEngineMH *this, _BYTE *addr)
{
  CUtlMap<char const *,IShader *,unsigned short>::Node_t *v3; // eax
  _RTL_CRITICAL_SECTION *p_m_Elements; // edi
  struct GHeapNodeMH *GrEq; // eax

  LOBYTE(v3) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, (unsigned __int16)addr);
  if ( v3 != nullptr )
  {
    GHeapAllocEngineMH::Free(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      page: v3,
      ptr: (unsigned int)addr);
  }
  else
  {
    p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    GrEq = (struct GHeapNodeMH *)GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(
                                   this: (unsigned int *)&GHeapGlobalRootMH[1].m_Elements.m_nGrowSize,
                                   a2: (unsigned int)addr);
    GHeapAllocEngineMH::Free(this, node: GrEq, a3: addr);
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3D30
// Name: public: void __near * GHeapAllocEngineMH::Alloc(unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::Alloc(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        ApplicationInstantCountersInfo_t *result,
        _DWORD *a3)
{
  unsigned int m_nGrowSize; // eax
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v5; // ebx
  ApplicationInstantCountersInfo_t *rl; // [esp+4h] [ebp-4h]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize <= 0x10 )
  {
    v5 = (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)result;
    if ( (unsigned int)result > 0x200 )
    {
      rl = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      HIBYTE(result) = 0;
      while ( GHeapAllocEngineMH::allocDirect(
                this,
                result: v5,
                alignSize: this->m_nGrowSize,
                limHandlerOK: (bool *)&result + 3,
                a5: a3) == nullptr
           && HIBYTE(result) != 0 )
        ;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)rl);
    }
    else
    {
      GHeapAllocEngineMH::allocFromPage(
        (int)this,
        result: ((unsigned int)&result[1].m_nDeferredWordsAllocated + 3) & 0xFFFFFFF0,
        a3);
    }
  }
  else
  {
    GHeapAllocEngineMH::Alloc(this, size: result, limHandlerOK: m_nGrowSize, a4: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3DE0
// Name: public: void __near * GHeapAllocEngineMH::ReallocInNode(struct GHeapNodeMH __near *,void __near *,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
const UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *__thiscall GHeapAllocEngineMH::ReallocInNode(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int (__cdecl *newPtr)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        unsigned __int8 *oldPtr,
        unsigned int oldAlign,
        _DWORD *a5)
{
  int v5; // eax
  unsigned int v6; // edi
  unsigned int v8; // eax
  int v9; // eax
  char *v10; // ebx
  unsigned int v11; // edi
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // edi
  unsigned __int16 v17; // [esp+0h] [ebp-14h]
  unsigned int nodeSize; // [esp+Ch] [ebp-8h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+10h] [ebp-4h]
  unsigned __int8 *newPtra; // [esp+1Ch] [ebp+8h]
  unsigned int oldAligna; // [esp+24h] [ebp+10h]

  v5 = *((_DWORD *)newPtr + 3) & 3;
  v6 = (oldAlign + 3) & 0xFFFFFFFC;
  if ( v5 == 3 )
    v8 = *((_DWORD *)newPtr + 5);
  else
    v8 = 1 << (v5 + 2);
  oldAligna = v8;
  v9 = v8 > 0x10 ? 24 : 20;
  v10 = (char *)newPtr + v9 - (_DWORD)oldPtr;
  v11 = v9 + ((v6 + 3) & 0xFFFFFFFC);
  nodeSize = v9;
  if ( v11 > (unsigned int)v10 && *((_DWORD *)this + 40) != 0 )
  {
    while ( v11 + *((_DWORD *)this + 38) - (_DWORD)v10 > *((_DWORD *)this + 40) && *((_DWORD *)this + 41) != 0 )
    {
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int, unsigned int))(**((_DWORD **)this + 41) + 4))(
             a1: *((_DWORD *)this + 41),
             a2: this->m_nAllocationCount,
             a3: v11 + *((_DWORD *)this + 38) - *((_DWORD *)this + 40) - (_DWORD)v10) == 0 )
      {
        EnterCriticalSection(lpCriticalSection);
        return nullptr;
      }
      EnterCriticalSection(lpCriticalSection);
      if ( *((_DWORD *)this + 40) == 0 )
        break;
    }
  }
  GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::Remove(
    this: (CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)GHeapGlobalRootMH + 40),
    node: newPtr,
    a3: v17);
  v12 = (unsigned __int8 *)(*(int (__thiscall **)(UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *, unsigned __int8 *, char *, unsigned int, unsigned int))(*(_DWORD *)this->m_pMemory + 20))(
                             a1: this->m_pMemory,
                             a2: oldPtr,
                             a3: v10,
                             a4: v11,
                             a5: oldAligna);
  newPtra = v12;
  if ( v12 != nullptr )
  {
    v13 = GHeapRootMH::AddToGlobalTree(
            this: (unsigned __int8 **)GHeapGlobalRootMH,
            ptr: v12,
            size: v11 - nodeSize,
            align: oldAligna,
            a5: this->m_nAllocationCount);
    a5[4] = v13;
    a5[2] = v13 + 16;
    v14 = v11 - nodeSize;
    v15 = v11 - (_DWORD)v10;
    a5[1] = 0;
    *a5 = 0;
    a5[5] = v14;
    a5[3] = 0;
    *((_DWORD *)this + 38) += v15;
    *((_DWORD *)this + 39) += v15;
    return (const UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *)newPtra;
  }
  else
  {
    GHeapRootMH::AddToGlobalTree(
      this: (unsigned __int8 **)GHeapGlobalRootMH,
      ptr: oldPtr,
      size: (unsigned int)&v10[-nodeSize],
      align: oldAligna,
      a5: this->m_nAllocationCount);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3F80
// Name: public: void __near * GHeapAllocEngineMH::ReallocGeneral(struct GHeapPageMH __near *,void __near *,unsigned int,struct GHeapPageInfoMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::ReallocGeneral(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMap<char const *,IShader *,unsigned short>::Node_t *page,
        unsigned __int8 *oldPtr,
        ApplicationInstantCountersInfo_t *newPtr,
        _DWORD *a5)
{
  bool (__cdecl *v6)(const char *const *, const char *const *); // ecx
  unsigned __int8 *v7; // eax
  unsigned int v8; // eax
  unsigned __int8 *newPtra; // [esp+30h] [ebp+10h]

  GHeapAllocEngineMH::Alloc(this, result: newPtr, a3: a5);
  newPtra = v7;
  if ( v7 != nullptr )
  {
    GHeapGetMagicHeaders(pageStart: v6);
    GHeapAllocBitSet2MH::GetUsableSize(this: (IShaderDLLInternal *)this + 3);
    if ( v8 >= a5[5] )
      v8 = a5[5];
    memcpy(dst: newPtra, src: oldPtr, count: v8);
    GHeapAllocEngineMH::Free(this, page, ptr: (unsigned int)oldPtr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3FF0
// Name: public: unsigned int GHeapAllocEngineMH::GetUsableSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapAllocEngineMH::GetUsableSize(GHeapAllocEngineMH *this, unsigned int addr)
{
  int v3; // eax
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx

  LOBYTE(v3) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr);
  if ( v3 != 0 )
  {
    GHeapAllocBitSet2MH::GetUsableSize(this: (IShaderDLLInternal *)this + 3);
  }
  else
  {
    p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(
      this: (unsigned int *)&GHeapGlobalRootMH[1].m_Elements.m_nGrowSize,
      a2: addr);
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  }
}
