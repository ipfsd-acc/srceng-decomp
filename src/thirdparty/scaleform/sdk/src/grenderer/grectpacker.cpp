// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/grectpacker.cpp
// Functions: 6
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\grectpacker.h"

//------------------------------------------------------------------------------
// Address: 0x1018A1A0
// Name: private: static bool GRectPacker::cmpRects(struct GRectPacker::RectType const __near &,struct GRectPacker::RectType const __near &)
// Source: json
//------------------------------------------------------------------------------
static BOOL __cdecl GRectPacker::cmpRects(
        const struct GRectPacker::RectType *a1,
        const struct GRectPacker::RectType *a2)
{
  return *(_QWORD *)a2 < *(_QWORD *)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1018A930
// Name: public: GRectPacker::GRectPacker(void)
// Source: json
//------------------------------------------------------------------------------
GRectPacker *__thiscall GRectPacker::GRectPacker(GRectPacker *this)
{
  *(_DWORD *)this = 1024;
  *((_DWORD *)this + 1) = 1024;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018A980
// Name: private: void GRectPacker::splitSpace(unsigned int,struct GRectPacker::RectType const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRectPacker::splitSpace(GRectPacker *this, unsigned int a2, const struct GRectPacker::RectType *a3)
{
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // esi
  unsigned int v9; // esi
  _DWORD v10[7]; // [esp+Ch] [ebp-38h] BYREF
  _DWORD v11[7]; // [esp+28h] [ebp-1Ch] BYREF
  unsigned int v12; // [esp+4Ch] [ebp+8h]

  v4 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 20) + 4 * (a2 >> 8)) + 28 * (unsigned __int8)a2);
  qmemcpy(v11, v4, sizeof(v11));
  qmemcpy(v10, v4, sizeof(v10));
  v5 = *(_DWORD *)a3;
  v6 = *((_DWORD *)a3 + 1);
  v7 = *((_DWORD *)this + 17);
  v11[0] += *(_DWORD *)a3;
  v11[2] -= v5;
  v10[1] += v6;
  v10[3] -= v6;
  v8 = v7 >> 8;
  v12 = (unsigned int)v4;
  v11[3] = v6;
  if ( v8 >= *((_DWORD *)this + 18) )
  {
    GArrayPagedBase<GRectPacker::NodeType,8,64,GAllocatorPagedLH_POD<GRectPacker::NodeType,2>>::allocatePage(
      this: (unsigned int *)this + 17,
      a2: v8);
    v4 = (_DWORD *)v12;
  }
  qmemcpy(
    (void *)(*(_DWORD *)(*((_DWORD *)this + 20) + 4 * v8) + 28 * (unsigned __int8)(*((_DWORD *)this + 17))++),
    v11,
    28);
  v9 = *((_DWORD *)this + 17) >> 8;
  if ( v9 >= *((_DWORD *)this + 18) )
  {
    GArrayPagedBase<GRectPacker::NodeType,8,64,GAllocatorPagedLH_POD<GRectPacker::NodeType,2>>::allocatePage(
      this: (unsigned int *)this + 17,
      a2: *((_DWORD *)this + 17) >> 8);
    v4 = (_DWORD *)v12;
  }
  qmemcpy(
    (void *)(*(_DWORD *)(*((_DWORD *)this + 20) + 4 * v9) + 28 * (unsigned __int8)(*((_DWORD *)this + 17))++),
    v10,
    28);
  v4[2] = *(_DWORD *)a3;
  v4[3] = *((_DWORD *)a3 + 1);
  v4[4] = *((_DWORD *)a3 + 2);
  v4[5] = *((_DWORD *)this + 17) - 2;
  v4[6] = *((_DWORD *)this + 17) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018AA90
// Name: private: void GRectPacker::emitPacked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRectPacker::emitPacked(GRectPacker *this)
{
  unsigned int v1; // edx
  int *v2; // eax
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v5; // edi
  _DWORD *v6; // eax
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+4h] [ebp-10h]
  GRectPacker *v9; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v1 = 0;
  v9 = this;
  for ( i = 0; v1 < *((_DWORD *)this + 17); i = v1 )
  {
    v2 = (int *)(*(_DWORD *)(*((_DWORD *)this + 20) + 4 * (v1 >> 8)) + 28 * (unsigned __int8)v1);
    v3 = v2[4];
    if ( v3 != -1 )
    {
      v4 = (_DWORD *)((char *)this + 36);
      v5 = *((_DWORD *)this + 9) >> 8;
      v7 = *v2;
      v8 = v2[1];
      if ( v5 >= *((_DWORD *)this + 10) )
      {
        GArrayPagedBase<GRectPacker::RectType,8,64,GAllocatorPagedLH_POD<GRectPacker::RectType,2>>::allocatePage(
          this: (unsigned int *)this + 9,
          a2: v5);
        this = v9;
      }
      v6 = (_DWORD *)(*(_DWORD *)(v4[3] + 4 * v5) + 12 * (unsigned __int8)*v4);
      *v6 = v7;
      v6[1] = v8;
      v1 = i;
      v6[2] = v3;
      ++*v4;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AB30
// Name: private: void GRectPacker::packRects(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRectPacker::packRects(GRectPacker *this, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  int v7; // eax
  unsigned int i; // ebx
  int v9; // edi
  unsigned int v10; // [esp+Ch] [ebp-8h]
  unsigned int v11; // [esp+10h] [ebp-4h]
  _DWORD *v12; // [esp+1Ch] [ebp+8h]

  v4 = a2;
  v5 = *(_DWORD *)(*((_DWORD *)this + 20) + 4 * (a2 >> 8));
  v6 = *(_DWORD *)(v5 + 28 * (unsigned __int8)a2 + 8);
  v7 = v5 + 28 * (unsigned __int8)a2;
  v12 = (_DWORD *)v7;
  v11 = v6;
  if ( v6 >= *((_DWORD *)this + 3) )
  {
LABEL_4:
    v10 = *(_DWORD *)(v7 + 12);
    if ( v10 >= *((_DWORD *)this + 4) )
    {
      for ( i = a3; i < *((_DWORD *)this + 5); ++i )
      {
        v9 = *(_DWORD *)(*((_DWORD *)this + 8) + 4 * (i >> 8)) + 12 * (unsigned __int8)i;
        if ( *(int *)(v9 + 8) >= 0 && *(_DWORD *)v9 <= v11 && *(_DWORD *)(v9 + 4) <= v10 )
        {
          GRectPacker::splitSpace(this, a2: v4, a3: (const struct GRectPacker::RectType *)v9);
          *(_DWORD *)(v9 + 8) |= 0x80000000;
          ++*((_DWORD *)this + 2);
          GRectPacker::packRects(this, a2: v12[5], a3: i);
          v4 = v12[6];
          a3 = i;
          v12 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 20) + 4 * (v4 >> 8)) + 28 * (unsigned __int8)v4);
          v11 = v12[2];
          if ( v11 >= *((_DWORD *)this + 3) )
          {
            v7 = *(_DWORD *)(*((_DWORD *)this + 20) + 4 * (v4 >> 8)) + 28 * (unsigned __int8)v4;
            goto LABEL_4;
          }
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AC30
// Name: public: void GRectPacker::Pack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRectPacker::Pack(GRectPacker *this)
{
  int *v2; // esi
  int v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // esi
  int v9; // ecx
  unsigned int v10; // edi
  int v11; // edi
  int v12; // eax
  _DWORD v13[7]; // [esp+Ch] [ebp-28h] BYREF
  int v14; // [esp+28h] [ebp-Ch]
  int v15; // [esp+2Ch] [ebp-8h]
  unsigned int v16; // [esp+30h] [ebp-4h]

  v2 = (int *)((char *)this + 20);
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 17) = 0;
  if ( *((_DWORD *)this + 5) != 0 )
  {
    G_QuickSortSliced<GArrayPagedLH_POD<GRectPacker::RectType,8,64,2>,bool (__cdecl *)(GRectPacker::RectType const &,GRectPacker::RectType const &)>(
      a1: (int)this + 20,
      a2: 0,
      a3: *v2,
      a4: (unsigned __int8 (__cdecl *)(int, int))GRectPacker::cmpRects);
    v3 = *((_DWORD *)this + 8);
    v4 = *v2 - 1;
    *((_DWORD *)this + 3) = *(_DWORD *)(*(_DWORD *)(v3 + 4 * (v4 >> 8)) + 12 * (unsigned __int8)v4);
    *((_DWORD *)this + 4) = *(_DWORD *)(*(_DWORD *)(v3 + 4 * (v4 >> 8)) + 12 * (unsigned __int8)v4 + 4);
    *((_DWORD *)this + 2) = 0;
    do
    {
      v5 = *((_DWORD *)this + 2);
      v6 = *(_DWORD *)this;
      v7 = *((_DWORD *)this + 1);
      *((_DWORD *)this + 17) = 0;
      *(_QWORD *)v13 = 0;
      v16 = v5;
      *(_QWORD *)&v13[2] = __PAIR64__(v7, v6);
      memset(&v13[4], 255, 12);
      if ( *((_DWORD *)this + 18) == 0 )
        GArrayPagedBase<GRectPacker::NodeType,8,64,GAllocatorPagedLH_POD<GRectPacker::NodeType,2>>::allocatePage(
          this: (unsigned int *)this + 17,
          a2: 0);
      qmemcpy((void *)(**((_DWORD **)this + 20) + 28 * (unsigned __int8)(*((_DWORD *)this + 17))++), v13, 28);
      GRectPacker::packRects(this, a2: 0, a3: 0);
      if ( *((_DWORD *)this + 2) > v16 )
      {
        v14 = *((_DWORD *)this + 9);
        v8 = v14;
        GRectPacker::emitPacked(this);
        v9 = *((_DWORD *)this + 9) - v8;
        v10 = *((_DWORD *)this + 13) >> 4;
        v15 = v9;
        if ( v10 >= *((_DWORD *)this + 14) )
        {
          GArrayPagedBase<GRectPacker::PackType,4,16,GAllocatorPagedLH_POD<GRectPacker::PackType,2>>::allocatePage(
            this: (unsigned int *)this + 13,
            a2: v10);
          v9 = v15;
        }
        v11 = *(_DWORD *)(*((_DWORD *)this + 16) + 4 * v10);
        v12 = *((_DWORD *)this + 13) & 0xF;
        *(_DWORD *)(v11 + 8 * v12) = v14;
        *(_DWORD *)(v11 + 8 * v12 + 4) = v9;
        ++*((_DWORD *)this + 13);
      }
    }
    while ( *((_DWORD *)this + 2) < *((_DWORD *)this + 5) );
  }
}
