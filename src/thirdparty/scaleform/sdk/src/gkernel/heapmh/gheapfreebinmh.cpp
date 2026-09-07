// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gheapfreebinmh.cpp
// Functions: 7
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gheapfreebinmh.h"

//------------------------------------------------------------------------------
// Address: 0x101849F0
// Name: public: static unsigned char __near * GHeapListBinMH::GetAlignedPtr(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static unsigned __int8 *__cdecl GHeapListBinMH::GetAlignedPtr(unsigned __int8 *a1, unsigned int a2)
{
  return (unsigned __int8 *)(~a2 & (unsigned int)&a1[a2]);
}

//------------------------------------------------------------------------------
// Address: 0x10184A10
// Name: public: GHeapListBinMH::GHeapListBinMH(void)
// Source: json
//------------------------------------------------------------------------------
GHeapListBinMH *__thiscall GHeapListBinMH::GHeapListBinMH(GHeapListBinMH *this)
{
  *(_DWORD *)this = 0;
  memset(dst: (unsigned __int8 *)this + 4, value: 0, count: 0x80u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10184A30
// Name: public: struct GHeapBinNodeMH __near * GHeapListBinMH::PullBest(unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GHeapBinNodeMH *__thiscall GHeapListBinMH::PullBest(GHeapListBinMH *this, unsigned int a2)
{
  int v2; // eax
  unsigned int v4; // edx
  unsigned __int8 v5; // dl
  int v6; // ecx
  struct GHeapBinNodeMH *result; // eax
  int v8; // edx

  v2 = a2 - 1;
  if ( a2 - 1 >= 0x1F )
    v2 = 31;
  v4 = *(_DWORD *)this >> v2;
  if ( v4 == 0 )
    return nullptr;
  if ( (_WORD)v4 != 0 )
  {
    if ( (_BYTE)v4 != 0 )
      v5 = *((_BYTE *)&GHeapLowerBit + (unsigned __int8)v4);
    else
      v5 = *((_BYTE *)&GHeapLowerBit + BYTE1(v4)) + 8;
  }
  else if ( (v4 & 0xFF0000) != 0 )
  {
    v5 = *((_BYTE *)&GHeapLowerBit + BYTE2(v4)) + 16;
  }
  else
  {
    v5 = *((_BYTE *)&GHeapLowerBit + HIBYTE(v4)) + 24;
  }
  v6 = v2 + v5;
  result = *((struct GHeapBinNodeMH **)this + v6 + 1);
  v8 = *((_DWORD *)result + 1);
  if ( result == (struct GHeapBinNodeMH *)(v8 & 0xFFFFFFF0) )
  {
    *((_DWORD *)this + v6 + 1) = 0;
    *(_DWORD *)this &= ~(1 << v6);
  }
  else
  {
    *((_DWORD *)this + v6 + 1) = v8 & 0xFFFFFFF0;
    *(_DWORD *)((*(_DWORD *)result & 0xFFFFFFF0) + 4) = *((_DWORD *)result + 1)
                                                      ^ (*(_DWORD *)((*(_DWORD *)result & 0xFFFFFFF0) + 4)
                                                       ^ *((_DWORD *)result + 1))
                                                      & 0xF;
    *(_DWORD *)(*((_DWORD *)result + 1) & 0xFFFFFFF0) = *(_DWORD *)result
                                                      ^ (*(_DWORD *)(*((_DWORD *)result + 1) & 0xFFFFFFF0)
                                                       ^ *(_DWORD *)result)
                                                      & 0xF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184B40
// Name: public: struct GHeapBinNodeMH __near * GHeapListBinMH::PullBest(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlMap<char const *,IShader *,unsigned short> *__thiscall GHeapListBinMH::PullBest(
        _DWORD *this,
        unsigned int result,
        unsigned int alignMask)
{
  int v4; // ecx
  unsigned int v5; // edx
  const CUtlMap<char const *,IShader *,unsigned short> *v6; // eax
  unsigned __int8 v7; // dl
  unsigned int v8; // edx
  const CUtlMap<char const *,IShader *,unsigned short> **v9; // esi
  const CUtlMap<char const *,IShader *,unsigned short> *v10; // edi
  const CUtlMap<char const *,IShader *,unsigned short> **j; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v4 = result - 1;
  if ( result - 1 >= 0x1F )
    v4 = 31;
  v5 = *this >> v4;
  v6 = nullptr;
  if ( v5 != 0 )
  {
    if ( (_WORD)v5 != 0 )
    {
      if ( (_BYTE)v5 != 0 )
        v7 = *((_BYTE *)&GHeapLowerBit + (unsigned __int8)v5);
      else
        v7 = *((_BYTE *)&GHeapLowerBit + BYTE1(v5)) + 8;
    }
    else if ( (v5 & 0xFF0000) != 0 )
    {
      v7 = *((_BYTE *)&GHeapLowerBit + BYTE2(v5)) + 16;
    }
    else
    {
      v7 = *((_BYTE *)&GHeapLowerBit + HIBYTE(v5)) + 24;
    }
    v8 = v4 + v7;
    v9 = (const CUtlMap<char const *,IShader *,unsigned short> **)(this + v8 + 1);
    i = v8;
    for ( j = v9; ; ++j )
    {
      v6 = *v9;
      if ( *v9 != nullptr )
        break;
LABEL_16:
      ++v8;
      v9 = j + 1;
      i = v8;
      if ( v8 >= 0x20 )
        return nullptr;
    }
    while ( 16 * result + (~alignMask & ((unsigned int)v6 + alignMask)) > (unsigned int)v6
                                                                        + 16
                                                                        * ((int)v6->m_Tree.m_LessFunc.m_LessFunc & 0xF
                                                                         | (16
                                                                          * ((int)v6->m_Tree.m_Elements.m_pMemory & 0xF))) )
    {
      v6 = (const CUtlMap<char const *,IShader *,unsigned short> *)((int)v6->m_Tree.m_Elements.m_pMemory & 0xFFFFFFF0);
      if ( v6 == *v9 )
      {
        v8 = i;
        goto LABEL_16;
      }
    }
    v10 = (const CUtlMap<char const *,IShader *,unsigned short> *)*(this + i + 1);
    if ( v6 != v10 )
      goto LABEL_22;
    if ( v10 != (const CUtlMap<char const *,IShader *,unsigned short> *)((int)v10->m_Tree.m_Elements.m_pMemory
                                                                       & 0xFFFFFFF0) )
    {
      *(this + i + 1) = (int)v10->m_Tree.m_Elements.m_pMemory & 0xFFFFFFF0;
LABEL_22:
      *(_DWORD *)(((int)v6->m_Tree.m_LessFunc.m_LessFunc & 0xFFFFFFF0) + 4) = (int)v6->m_Tree.m_Elements.m_pMemory
                                                                            ^ ((int)v6->m_Tree.m_Elements.m_pMemory
                                                                             ^ *(_DWORD *)(((int)v6->m_Tree.m_LessFunc.m_LessFunc
                                                                                          & 0xFFFFFFF0)
                                                                                         + 4))
                                                                            & 0xF;
      *(_DWORD *)((int)v6->m_Tree.m_Elements.m_pMemory & 0xFFFFFFF0) = (int)v6->m_Tree.m_LessFunc.m_LessFunc
                                                                     ^ (*(_DWORD *)((int)v6->m_Tree.m_Elements.m_pMemory
                                                                                  & 0xFFFFFFF0)
                                                                      ^ (int)v6->m_Tree.m_LessFunc.m_LessFunc)
                                                                     & 0xF;
      return v6;
    }
    *(this + i + 1) = 0;
    *this &= ~(1 << i);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10184CA0
// Name: public: void GHeapListBinMH::Push(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapListBinMH::Push(GHeapListBinMH *this, unsigned __int8 *node)
{
  int v3; // edi
  int v4; // edx
  unsigned int v5; // ecx
  int v6; // esi

  v3 = *((_DWORD *)node + 1) & 0xF;
  v4 = *(_DWORD *)node & 0xF;
  v5 = (v4 | (16 * v3)) - 1;
  if ( v5 >= 0x1F )
    v5 = 31;
  v6 = *((_DWORD *)this + v5 + 1);
  if ( v6 != 0 )
  {
    *(_DWORD *)node = v6 | v4;
    *((_DWORD *)node + 1) = v3 | *(_DWORD *)(v6 + 4) & 0xFFFFFFF0;
    *(_DWORD *)(*(_DWORD *)(v6 + 4) & 0xFFFFFFF0) = (unsigned int)node
                                                  | *(_DWORD *)(*(_DWORD *)(v6 + 4) & 0xFFFFFFF0) & 0xF;
    *(_DWORD *)(v6 + 4) = (unsigned int)node | *(_DWORD *)(v6 + 4) & 0xF;
  }
  else
  {
    *((_DWORD *)node + 1) = (unsigned int)node | v3;
    *(_DWORD *)node = (unsigned int)node | v4;
  }
  *((_DWORD *)this + v5 + 1) = node;
  *(_DWORD *)this |= 1 << v5;
}

//------------------------------------------------------------------------------
// Address: 0x10184D30
// Name: public: void GHeapListBinMH::Pull(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapListBinMH::Pull(GHeapListBinMH *this, unsigned __int8 *node)
{
  unsigned int v3; // ecx
  int v4; // edi
  int v5; // edx

  v3 = (*(_DWORD *)node & 0xF | (16 * (*((_DWORD *)node + 1) & 0xF))) - 1;
  if ( v3 >= 0x1F )
    v3 = 31;
  v4 = *((_DWORD *)this + v3 + 1);
  if ( node == (unsigned __int8 *)v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    if ( v4 == (v5 & 0xFFFFFFF0) )
    {
      *((_DWORD *)this + v3 + 1) = 0;
      *(_DWORD *)this &= ~(1 << v3);
    }
    else
    {
      *((_DWORD *)this + v3 + 1) = v5 & 0xFFFFFFF0;
      *(_DWORD *)((*(_DWORD *)node & 0xFFFFFFF0) + 4) = *((_DWORD *)node + 1)
                                                      ^ (*(_DWORD *)((*(_DWORD *)node & 0xFFFFFFF0) + 4)
                                                       ^ *((_DWORD *)node + 1))
                                                      & 0xF;
      *(_DWORD *)(*((_DWORD *)node + 1) & 0xFFFFFFF0) = *(_DWORD *)node
                                                      ^ (*(_DWORD *)(*((_DWORD *)node + 1) & 0xFFFFFFF0)
                                                       ^ *(_DWORD *)node)
                                                      & 0xF;
    }
  }
  else
  {
    *(_DWORD *)((*(_DWORD *)node & 0xFFFFFFF0) + 4) = *((_DWORD *)node + 1)
                                                    ^ (*(_DWORD *)((*(_DWORD *)node & 0xFFFFFFF0) + 4)
                                                     ^ *((_DWORD *)node + 1))
                                                    & 0xF;
    *(_DWORD *)(*((_DWORD *)node + 1) & 0xFFFFFFF0) = *(_DWORD *)node
                                                    ^ (*(_DWORD *)node
                                                     ^ *(_DWORD *)(*((_DWORD *)node + 1) & 0xFFFFFFF0))
                                                    & 0xF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184DF0
// Name: public: void GHeapListBinMH::Merge(unsigned char __near *,unsigned int,bool,bool,struct GHeapPageMH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHeapListBinMH::Merge(
        CUtlMap<char const *,IShader *,unsigned short> *this,
        unsigned __int8 *node,
        unsigned int bytes,
        bool (__cdecl *left)(const char *const *, const char *const *),
        bool right,
        int a6)
{
  unsigned int v7; // edi
  _DWORD *v8; // ecx
  unsigned int v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  int v13; // ebx
  int v14; // eax
  unsigned int v15; // edi
  int v16; // edx
  unsigned __int8 *nodea; // [esp+18h] [ebp+8h]
  unsigned int bytesa; // [esp+1Ch] [ebp+Ch]

  v7 = bytes >> 4;
  *(_DWORD *)node ^= ((unsigned __int8)(bytes >> 4) ^ (unsigned __int8)*(_DWORD *)node) & 0xF;
  *(_DWORD *)&node[16 * (bytes >> 4) - 8] = *(_DWORD *)node;
  bytesa = (unsigned int)&node[16 * (bytes >> 4) - 8];
  v8 = node + 4;
  v9 = (v7 >> 4) | *((_DWORD *)node + 1) & 0xFFFFFFF0;
  *((_DWORD *)node + 1) = v9;
  v10 = (int)node;
  nodea = node + 4;
  *(_DWORD *)(bytesa + 4) = v9;
  if ( (_BYTE)left != 0 )
  {
    v10 = (int)&node[-16 * (*((_DWORD *)node - 2) & 0xF | (16 * (*((_DWORD *)node - 1) & 0xF)))];
    nodea = (unsigned __int8 *)(v10 + 4);
    v7 += *(_DWORD *)v10 & 0xF | (16 * (*(_DWORD *)(v10 + 4) & 0xF));
    GHeapListBinMH::Pull((GHeapListBinMH *)this, node: (unsigned __int8 *)v10);
    v8 = (_DWORD *)(v10 + 4);
  }
  if ( right )
  {
    v11 = 16 * (*(_DWORD *)node & 0xF | (16 * (*((_DWORD *)node + 1) & 0xF)));
    v7 += *(_DWORD *)&node[v11] & 0xF | (16 * (*(_DWORD *)&node[v11 + 4] & 0xF));
    GHeapListBinMH::Pull((GHeapListBinMH *)this, node: &node[v11]);
    v8 = nodea;
  }
  *(_DWORD *)v10 ^= ((unsigned __int8)v7 ^ (unsigned __int8)*(_DWORD *)v10) & 0xF;
  *(_DWORD *)(v10 + 16 * v7 - 8) = *(_DWORD *)v10;
  v12 = *v8 & 0xFFFFFFF0 | (v7 >> 4);
  *v8 = v12;
  *(_DWORD *)(v10 + 16 * v7 - 8 + 4) = v12;
  v13 = *v8 & 0xF;
  v14 = *(_DWORD *)v10 & 0xF;
  if ( (v14 | (unsigned int)(16 * v13)) > 1 )
    *(_DWORD *)(v10 + 8) = a6;
  v15 = v7 - 1;
  if ( v15 >= 0x1F )
    v15 = 31;
  v16 = *((_DWORD *)&this->m_Tree.m_Elements.m_pMemory + v15);
  if ( v16 != 0 )
  {
    *(_DWORD *)v10 = v16 | v14;
    *v8 = v13 | *(_DWORD *)(v16 + 4) & 0xFFFFFFF0;
    *(_DWORD *)(*(_DWORD *)(v16 + 4) & 0xFFFFFFF0) = v10 | *(_DWORD *)(*(_DWORD *)(v16 + 4) & 0xFFFFFFF0) & 0xF;
    *(_DWORD *)(v16 + 4) = v10 | *(_DWORD *)(v16 + 4) & 0xF;
  }
  else
  {
    *(_DWORD *)v10 = v10 | v14;
    *v8 = v10 | v13;
  }
  *((_DWORD *)&this->m_Tree.m_Elements.m_pMemory + v15) = v10;
  this->m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((int)this->m_Tree.m_LessFunc.m_LessFunc
                                                                                                  | (1 << v15));
}
